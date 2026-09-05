#include "bootstrap.split.h"

static int32_t vader_c_emit_array_element_tag(void* l0, int32_t l1);
static vader_string_t vader_c_emit_array_hdr_ptr(vader_box_t l0);
static int32_t vader_c_emit_array_tag(void* l0, int32_t l1);
static int32_t vader_c_emit_array_type_index_for_element(void* l0, int32_t l1);
static void vader_c_emit_assert_stack_empty(void* l0, vader_string_t l1);
static int32_t vader_c_emit_atom_for(void* l0, vader_string_t l1);
static void* vader_c_emit_atom_table_of(void* l0, void* l1);
static vader_string_t vader_c_emit_aux(void* l0, vader_string_t l1);
static void* vader_c_emit_bc_struct_fields(void* l0, int32_t l1);
static vader_string_t vader_c_emit_bc_struct_name(void* l0, int32_t l1);
static vader_string_t vader_c_emit_binop_text(void* l0, vader_string_t l1, uint8_t l2);
static vader_string_t vader_c_emit_box_expr(vader_string_t l0, uint8_t l1, int32_t l2);
static vader_string_t vader_c_emit_box_expr_unknown(void* l0, vader_string_t l1, uint8_t l2);
static vader_string_t vader_c_emit_box_slot_c(void* l0, void* l1, vader_box_t l2, vader_string_t l3, int32_t l4, void* l5);
static void* vader_c_emit_boxed_pool_objects(void* l0, void* l1);
static vader_box_t vader_c_emit_branch_target(void* l0, int32_t l1);
static vader_string_t vader_c_emit_buf_ptr(vader_box_t l0);
static void* vader_c_emit_build_string_atom_map(void* l0);
static vader_string_t vader_c_emit_c_field_name(void* l0);
static vader_string_t vader_c_emit_c_string_lit(vader_string_t l0);
static void* vader_c_emit_c_struct_layout_asserts(void* l0, void* l1);
static vader_string_t vader_c_emit_c_type_for(vader_box_t l0);
static vader_string_t vader_c_emit_c_type_for_array_kind(uint8_t l0);
static vader_string_t vader_c_emit_c_type_for_val_bare(uint8_t l0);
static int32_t vader_c_emit_callee_index_of(vader_box_t l0);
static void* vader_c_emit_classify_struct_fields(void* l0, void* l1, size_t l2);
static void* vader_c_emit_coalesce_temps(vader_string_t l0, void* l1);
static vader_string_t vader_c_emit_coerce_expr(void* l0, vader_string_t l1, uint8_t l2, uint8_t l3);
static vader_string_t vader_c_emit_coerce_operand(void* l0, vader_string_t l1, uint8_t l2, uint8_t l3);
static int32_t vader_c_emit_comptime_atom_count(void* l0);
static void* vader_c_emit_compute_atom_ids(void* l0, void* l1);
static void* vader_c_emit_compute_may_alloc(void* l0);
static vader_string_t vader_c_emit_const_lit_c(void* l0, vader_box_t l1);
static uint8_t vader_c_emit_const_val(vader_box_t l0);
static uint8_t vader_c_emit_convert_target_val(uint8_t l0);
static int32_t vader_c_emit_count_byte(void* l0, size_t l1, uint8_t l2);
static void* vader_c_emit_count_temp_occurrences(vader_string_t l0, size_t l1);
static void* vader_c_emit_crossing_mirrors(void* l0);
static bool vader_c_emit_data_entry_mutable(vader_box_t l0);
static void* vader_c_emit_data_pool_type_ids(void* l0);
static vader_string_t vader_c_emit_data_slot_c(uint8_t l0, uint64_t l1, vader_string_t l2);
static vader_string_t vader_c_emit_dispatcher_formal(void* l0);
static vader_string_t vader_c_emit_dispatcher_result(void* l0, vader_string_t l1, uint8_t l2, uint8_t l3);
static vader_box_t vader_c_emit_div_mod_helper(vader_string_t l0, uint8_t l1);
static void vader_c_emit_drop_resolved_for_local(void* l0, int32_t l1);
static void vader_c_emit_drop_top(void* l0);
static uint8_t vader_c_emit_element_storage_kind(void* l0);
static void vader_c_emit_emit_agg_data_entry(void* l0, size_t l1, void* l2, int32_t l3, int32_t l4, void* l5, void* l6);
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
static void vader_c_emit_emit_atom_count_define(void* l0, void* l1);
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
static void vader_c_emit_emit_call_result(void* l0, vader_string_t l1, uint8_t l2);
static void vader_c_emit_emit_call_to(void* l0, vader_string_t l1, void* l2);
static void vader_c_emit_emit_closure_forward_decls(void* l0, void* l1);
static void vader_c_emit_emit_closure_lift(void* l0, void* l1, int32_t l2);
static void vader_c_emit_emit_convert(void* l0, uint8_t l1, vader_string_t l2);
static void vader_c_emit_emit_data_const_op(void* l0, void* l1);
static void vader_c_emit_emit_data_global_externs(void* l0, void* l1);
static void vader_c_emit_emit_data_pool(void* l0, void* l1);
static vader_string_t vader_c_emit_emit_data_value(void* l0, void* l1, vader_box_t l2, vader_string_t l3, void* l4);
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
static void vader_c_emit_emit_function_body(void* l0, int32_t l1, void* l2, void* l3);
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
static vader_string_t vader_c_emit_emit_nested_array(void* l0, void* l1, void* l2, vader_string_t l3, void* l4);
static void vader_c_emit_emit_op(void* l0, int32_t l1, vader_box_t l2);
static void vader_c_emit_emit_open_scope(void* l0, int32_t l1, uint8_t l2);
static void vader_c_emit_emit_prim_data_entry(void* l0, size_t l1, void* l2, int32_t l3, int32_t l4, bool l5);
static void vader_c_emit_emit_ref_cast(void* l0, void* l1);
static void vader_c_emit_emit_return(void* l0);
static void vader_c_emit_emit_return_lit(void* l0, vader_box_t l1);
static void vader_c_emit_emit_return_stmt(void* l0, vader_string_t l1);
static void vader_c_emit_emit_size_of_type(void* l0);
static vader_string_t vader_c_emit_emit_slot_array_local(void* l0, vader_box_t l1, vader_box_t l2, bool l3);
static void vader_c_emit_emit_slot_decls(void* l0, void* l1, void* l2, void* l3, void* l4, void* l5, bool l6);
static void vader_c_emit_emit_slot_load_prim(void* l0, vader_string_t l1, uint8_t l2, bool l3);
static void vader_c_emit_emit_slot_store_prim(void* l0, vader_string_t l1, uint8_t l2, bool l3);
static void vader_c_emit_emit_str_data_entry(void* l0, size_t l1, void* l2, int32_t l3, int32_t l4, void* l5, bool l6);
static void vader_c_emit_emit_string_slice(void* l0);
static void vader_c_emit_emit_struct_body(void* l0, void* l1, size_t l2, void* l3);
static void vader_c_emit_emit_struct_get(void* l0, void* l1);
static void vader_c_emit_emit_struct_info_row(void* l0, void* l1, void* l2, size_t l3, void* l4);
static void vader_c_emit_emit_struct_new(void* l0, void* l1);
static void vader_c_emit_emit_struct_offset_arrays(void* l0, size_t l1, void* l2, bool l3);
static void vader_c_emit_emit_struct_set(void* l0, void* l1);
static void vader_c_emit_emit_struct_typedefs(void* l0, void* l1);
static void vader_c_emit_emit_tmp_decls(void* l0, void* l1, void* l2, void* l3, void* l4, bool l5);
static void vader_c_emit_emit_type_check(void* l0, void* l1);
static void vader_c_emit_emit_type_const(void* l0, void* l1);
static void vader_c_emit_emit_type_info_table(void* l0, void* l1);
static void vader_c_emit_emit_typed_slot_write(void* l0, vader_string_t l1, vader_box_t l2, vader_box_t l3, vader_string_t l4, uint8_t l5);
static void vader_c_emit_emit_virtual_call(void* l0, void* l1);
static void vader_c_emit_emit_vtable_dispatchers(void* l0, void* l1);
static void vader_c_emit_emit_vtable_forward_decls(void* l0, void* l1);
static void* vader_c_emit_empty_struct_offsets(void);
static bool vader_c_emit_entry_needs_materialise(vader_box_t l0, int32_t l1);
static vader_string_t vader_c_emit_erased_sibling_field_read(void* l0, int32_t l1, int32_t l2, uint8_t l3, vader_string_t l4);
static vader_string_t vader_c_emit_erased_sig_params(int32_t l0);
static vader_string_t vader_c_emit_extern_c_type(uint8_t l0);
static vader_string_t vader_c_emit_extern_decl(void* l0, void* l1);
static void* vader_c_emit_find_erased_siblings(void* l0, int32_t l1);
static int32_t vader_c_emit_find_main(void* l0, vader_string_t l1);
static vader_box_t vader_c_emit_find_vtable_row(void* l0, vader_string_t l1);
static vader_string_t vader_c_emit_float_lit(double l0);
static vader_string_t vader_c_emit_float_tag_check_expr(void* l0, vader_string_t l1);
static bool vader_c_emit_fn_builds_stack_object(void* l0);
static bool vader_c_emit_fn_calls_may_alloc(void* l0, void* l1);
static bool vader_c_emit_fn_has_direct_alloc(void* l0);
static vader_string_t vader_c_emit_fn_linkage_prefix(void* l0, int32_t l1);
static vader_string_t vader_c_emit_fn_symbol_name(void* l0, int32_t l1);
static vader_string_t vader_c_emit_fresh_tmp(void* l0, uint8_t l1);
static vader_string_t vader_c_emit_fuse_temp_local_copies(vader_string_t l0, size_t l1);
static bool vader_c_emit_has_str_data(void* l0);
static vader_string_t vader_c_emit_host_shim_name(void* l0);
static vader_string_t vader_c_emit_i32_lit_c(int32_t l0);
static vader_string_t vader_c_emit_i64_lit_c(int64_t l0);
static vader_string_t vader_c_emit_import_shim(void* l0, void* l1, int32_t l2);
static vader_string_t vader_c_emit_import_shim_signature(void* l0, int32_t l1);
static vader_string_t vader_c_emit_imports_header_name(vader_string_t l0);
static void vader_c_emit_indent_pop(void* l0);
static void vader_c_emit_indent_push(void* l0);
static void* vader_c_emit_internal_fn_flags(void* l0, void* l1, vader_string_t l2);
static void vader_c_emit_invalidate_resolve_cache(void* l0, vader_box_t l1);
static bool vader_c_emit_is_abi_array(void* l0, int32_t l1);
static bool vader_c_emit_is_abi_nullable_pointer(void* l0, int32_t l1);
static bool vader_c_emit_is_abi_nullable_string(void* l0, int32_t l1);
static bool vader_c_emit_is_c_reserved(vader_string_t l0);
static bool vader_c_emit_is_cache_safe(vader_box_t l0);
static bool vader_c_emit_is_continue_branch(void* l0, int32_t l1);
static bool vader_c_emit_is_digit_byte(uint8_t l0);
static bool vader_c_emit_is_param_by_address(void* l0, size_t l1);
static bool vader_c_emit_is_pure_control_flow(vader_box_t l0);
static bool vader_c_emit_is_ref_val(uint8_t l0);
static bool vader_c_emit_is_scope_opening(vader_box_t l0);
static vader_string_t vader_c_emit_join_commas(void* l0);
static void vader_c_emit_keep_pinned_resolves(void* l0);
static bool vader_c_emit_key_mentions_local(vader_string_t l0, int32_t l1);
static size_t vader_c_emit_leading_spaces(void* l0, size_t l1);
static vader_string_t vader_c_emit_lift_unbox_tail(void* l0);
static void vader_c_emit_line(void* l0, vader_string_t l1);
static vader_string_t vader_c_emit_linkage_prefix(bool l0);
static vader_box_t vader_c_emit_materialise_entry(void* l0, vader_box_t l1);
static void vader_c_emit_materialize_stack_for_slot(void* l0, int32_t l1);
static int32_t vader_c_emit_max_fn_arity(void* l0);
static vader_string_t vader_c_emit_mirrored_c_struct(void* l0, int32_t l1);
static vader_string_t vader_c_emit_module_stem_of(vader_string_t l0);
static void* vader_c_emit_mutable_pool_indices(void* l0);
static vader_string_t vader_c_emit_name_of(vader_box_t l0);
static void* vader_c_emit_nested_member_mirrors(void* l0);
static void* vader_c_emit_new_ctx(void* l0, bool l1, bool l2, void* l3, void* l4);
static void* vader_c_emit_new_fn_state(void* l0, void* l1, void* l2);
static void* vader_c_emit_no_slot(size_t l0);
static int32_t vader_c_emit_null_primitive_tag(void* l0);
static vader_string_t vader_c_emit_obj_ptr_expr(vader_string_t l0, uint8_t l1);
static vader_string_t vader_c_emit_obj_ptr_of(vader_box_t l0);
static vader_string_t vader_c_emit_one_variant_check(void* l0, vader_string_t l1, int32_t l2);
static bool vader_c_emit_op_allocates(vader_box_t l0);
static void* vader_c_emit_order_by_first(void* l0, size_t l1);
static bool vader_c_emit_param_is_mutable(void* l0, size_t l1);
static void* vader_c_emit_parse_copy_line(vader_string_t l0);
static void* vader_c_emit_parse_def_line(vader_string_t l0);
static void* vader_c_emit_partition_functions(void* l0);
static vader_box_t vader_c_emit_pop(void* l0);
static void* vader_c_emit_pop_args_boxed(void* l0, int32_t l1);
static void* vader_c_emit_precompute_branch_targets(void* l0, void* l1);
static void* vader_c_emit_precompute_scopes(void* l0);
static int32_t vader_c_emit_prim_tag(void* l0, uint8_t l1);
static bool vader_c_emit_primitive_matches_type(void* l0, uint8_t l1, int32_t l2);
static int32_t vader_c_emit_primitive_tag_of(void* l0, uint8_t l1);
static void vader_c_emit_push_binop(void* l0, vader_string_t l1, uint8_t l2);
static void vader_c_emit_push_binop_any(void* l0, vader_string_t l1, uint8_t l2);
static void vader_c_emit_push_cmp(void* l0, vader_string_t l1, uint8_t l2);
static void vader_c_emit_push_const(void* l0, vader_box_t l1);
static void vader_c_emit_push_eager(void* l0, vader_string_t l1, uint8_t l2);
static void vader_c_emit_push_expr(void* l0, uint8_t l1, vader_string_t l2);
static void vader_c_emit_push_i64_neg(void* l0);
static void vader_c_emit_push_into_tmp(void* l0, vader_string_t l1, uint8_t l2);
static void vader_c_emit_push_leaf_asserts(void* l0, void* l1, vader_string_t l2, vader_string_t l3, vader_string_t l4, int64_t l5, void* l6, int32_t l7);
static void vader_c_emit_push_lit(void* l0, uint8_t l1, vader_string_t l2);
static void vader_c_emit_push_local_ref(void* l0, int32_t l1, uint8_t l2);
static void vader_c_emit_push_member_copies(void* l0, void* l1, vader_string_t l2, vader_string_t l3, bool l4, void* l5, int32_t l6);
static void vader_c_emit_push_struct_field(void* l0, int32_t l1, int32_t l2, vader_string_t l3, uint8_t l4);
static void vader_c_emit_push_tmp(void* l0, vader_string_t l1, uint8_t l2);
static void vader_c_emit_push_unop(void* l0, vader_string_t l1, uint8_t l2);
static bool vader_c_emit_ref_carrying_element(vader_box_t l0, void* l1);
static vader_string_t vader_c_emit_resolve_array_local(void* l0, vader_string_t l1, bool l2);
static vader_string_t vader_c_emit_rewrite_temps(vader_string_t l0, void* l1);
static vader_string_t vader_c_emit_sanitise(vader_string_t l0);
static void* vader_c_emit_scan_fn_value_usage(void* l0);
static vader_box_t vader_c_emit_scope_ending_at(void* l0, int32_t l1);
static vader_string_t vader_c_emit_shim_linkage_prefix(bool l0);
static vader_string_t vader_c_emit_signature_for(void* l0);
static vader_box_t vader_c_emit_signedness_assert(void* l0, void* l1, vader_string_t l2, vader_string_t l3);
static vader_string_t vader_c_emit_slot_index(vader_string_t l0, vader_box_t l1);
static void* vader_c_emit_slot_token_at(void* l0, size_t l1, size_t l2, uint8_t l3);
static uint8_t vader_c_emit_slot_val_type(void* l0, int32_t l1);
static void* vader_c_emit_sorted_fn_indices(void* l0);
static void* vader_c_emit_sorted_module_stems(void* l0);
static vader_string_t vader_c_emit_storage_qualifier(bool l0);
static int32_t vader_c_emit_string_array_tag(void* l0, int32_t l1);
static int32_t vader_c_emit_string_primitive_tag(void* l0);
static bool vader_c_emit_struct_all_ref(void* l0, void* l1);
static vader_string_t vader_c_emit_struct_c_name(vader_string_t l0);
static vader_string_t vader_c_emit_struct_check_expr(void* l0, vader_string_t l1, int32_t l2, vader_string_t l3);
static vader_string_t vader_c_emit_struct_field_init(void* l0, void* l1, vader_box_t l2, vader_string_t l3, int32_t l4, void* l5);
static vader_string_t vader_c_emit_tag_of(vader_box_t l0);
static vader_string_t vader_c_emit_tag_of_expr(vader_string_t l0, uint8_t l1);
static vader_string_t vader_c_emit_tag_u(int32_t l0, vader_string_t l1);
static void* vader_c_emit_temp_token_at(void* l0, size_t l1, size_t l2);
static vader_string_t vader_c_emit_trait_check_expr(void* l0, vader_string_t l1, vader_string_t l2, int32_t l3);
static vader_string_t vader_c_emit_tramp_box_params(size_t l0);
static vader_string_t vader_c_emit_tramp_box_result(vader_string_t l0, vader_string_t l1, void* l2);
static vader_string_t vader_c_emit_tramp_head(size_t l0);
static vader_string_t vader_c_emit_tramp_unbox_args(void* l0);
static int32_t vader_c_emit_type_id_for_struct_symbol(void* l0, int32_t l1);
static int32_t vader_c_emit_type_index_for_name(void* l0, vader_string_t l1);
static vader_box_t vader_c_emit_typed_array_fill_for(uint8_t l0);
static vader_string_t vader_c_emit_unbox_expr(vader_string_t l0, uint8_t l1);
static void* vader_c_emit_unit_names_of(void* l0, void* l1);
static vader_string_t vader_c_emit_user_extern_shim(void* l0, vader_string_t l1, void* l2);
static uint8_t vader_c_emit_val_of(vader_box_t l0);
static uint8_t vader_c_emit_val_type_of_bc_type(vader_box_t l0);
static uint8_t vader_c_emit_val_type_of_field(void* l0, int32_t l1);
static vader_string_t vader_c_emit_vtable_helper_name(vader_string_t l0);
static void* vader_c_emit_vtable_sig_for_row(void* l0, void* l1);

static int32_t vader_c_emit_array_element_tag(void* l0, int32_t l1) {
    size_t l2;
    vader_box_t l3;
    int64_t t0;
    void* t1;
    int32_t t2;
    t0 = ((int64_t) (int32_t) l1);
    l2 = (size_t) (int64_t) t0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    if ((size_t) l2 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
    l3 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
    if (l3.tag == 496u) {
        t1 = l3.payload.obj;
        t2 = ((vader_struct_vader_bytecode_BcArray_t*) t1)->f_element;
        return t2;
    }
    return l1;
}

static vader_string_t vader_c_emit_array_hdr_ptr(vader_box_t l0) {
    vader_string_t l1 = 0;
    vader_string_t t0 = 0;
    vader_box_t* gc_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[2] = { &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 0u, gc_roots, NULL, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l1 = vader_c_emit_obj_ptr_of(l0);
    t0 = concat_3(295u, l1, 318u);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static int32_t vader_c_emit_array_tag(void* l0, int32_t l1) {
    size_t l2, l3, l5;
    vader_box_t l4;
    void* t0;
    int32_t t1;
    int64_t t2;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    l2 = ((vader_array_t*) l0)->length;
    l3 = (size_t) (int64_t) INT64_C(0);
    {
        loop_6: {
            if ((l3 < l2)) {
                if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                l4 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
                if (l4.tag == 496u) {
                    t0 = l4.payload.obj;
                    t1 = ((vader_struct_vader_bytecode_BcArray_t*) t0)->f_element;
                    if (t1 == l1) {
                        return ((int32_t) (size_t) l3);
                    }
                    l5 = (size_t) (int64_t) INT64_C(1);
                    t2 = (l3 + l5);
                    l3 = (size_t) (int64_t) t2;
                    goto loop_6;
                }
                l5 = (size_t) (int64_t) INT64_C(1);
                t2 = (l3 + l5);
                l3 = (size_t) (int64_t) t2;
                goto loop_6;
            } else {
            }
        }
    }
    return -(INT32_C(1));
}

static int32_t vader_c_emit_array_type_index_for_element(void* l0, int32_t l1) {
    size_t l2, l3, l4;
    vader_box_t t0;
    void* t1;
    int32_t t2;
    int64_t t3;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    l2 = ((vader_array_t*) l0)->length;
    l3 = (size_t) (int64_t) INT64_C(0);
    {
        loop_6: {
            if ((l3 < l2)) {
                if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
                if (t0.tag == 496u) {
                    vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
                    if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                    if ((size_t) l3 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                    t0 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l3);
                    t1 = t0.payload.obj;
                    t2 = ((vader_struct_vader_bytecode_BcArray_t*) t1)->f_element;
                    if (t2 == l1) {
                        return ((int32_t) (size_t) l3);
                    }
                    l4 = (size_t) (int64_t) INT64_C(1);
                    t3 = (l3 + l4);
                    l3 = (size_t) (int64_t) t3;
                    goto loop_6;
                }
                l4 = (size_t) (int64_t) INT64_C(1);
                t3 = (l3 + l4);
                l3 = (size_t) (int64_t) t3;
                goto loop_6;
            } else {
            }
        }
    }
    return INT32_C(0);
}

static void vader_c_emit_assert_stack_empty(void* l0, vader_string_t l1) {
    vader_string_t l2 = 0;
    size_t l3;
    void* l4 = NULL;
    uint64_t l5;
    size_t t0;
    int64_t t1;
    vader_string_t t2 = 0;
    void** gc_raw_roots[2] = { &l0, &l4 };
    vader_string_t* gc_atom_roots[3] = { &l1, &l2, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_stack)->length;
    if (t0 != INT64_C(0)) {
        l2 = l1;
        l3 = vader_host_std_core_byte_len(l2);
        l4 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(153) + l3));
        l3 = (size_t) (int64_t) INT64_C(0);
        l3 = std_core_write_string_at(l4, l3, 1319u);
        l3 = std_core_write_string_at(l4, l3, l2);
        l3 = std_core_write_string_at(l4, l3, 47u);
        t0 = ((vader_array_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_stack)->length;
        t1 = ((int64_t) (size_t) t0);
        l5 = (uint64_t) (int64_t) t1;
        l3 = std_core_write_unsigned(l4, l3, l5);
        l3 = std_core_write_string_at(l4, l3, 337u);
        t2 = std_core_finish_buffer(l4, l3);
        vader_host_std_abort_panic(t2);
    } else {
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static int32_t vader_c_emit_atom_for(void* l0, vader_string_t l1) {
    vader_box_t l2 = vader_box_null();
    int32_t t0;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = std_collections_get__string__i32(l0, l1);
    if (l2.tag == 170u) {
        t0 = ((int32_t) l2.payload.i);
        { int32_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return INT32_C(0); }
    vader_gc_top = gc_frame.prev;
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
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) l1)->length;
    if (t0 != INT64_C(0)) {
        { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 167u);
    l2 = (void*) _a0_arr;
    l3 = ((vader_array_t*) l0)->length;
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_16: {
            if ((l4 < l3)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l4 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                t1 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l4];
                t2 = t1.payload.s;
                if (t2 != 0u) {
                    vader_array_t* _a2_slotarr = ((vader_array_t*) l0);
                    if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                    if ((size_t) l4 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                    t1 = vader_array_box_slots(_a2_slotarr->buf)[_a2_slotarr->offset + (size_t) l4];
                    l5 = t1.payload.s;
                    vader_array_push((vader_array_t*) l2, vader_box_string(167u, l5));
                } else {
                }
                t3 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t3;
                goto loop_16;
            } else {
            }
        }
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
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
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = l1;
    l3 = vader_host_std_core_byte_len(l2);
    l4 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(23) + l3));
    l3 = (size_t) (int64_t) INT64_C(0);
    l3 = std_core_write_string_at(l4, l3, 899u);
    t0 = ((vader_struct_vader_c_emit_FnState_t*) l0)->f_aux_counter;
    l5 = ((int64_t) (int32_t) t0);
    l3 = std_core_write_int(l4, l3, l5);
    l3 = std_core_write_string_at(l4, l3, 863u);
    l3 = std_core_write_string_at(l4, l3, l2);
    l2 = std_core_finish_buffer(l4, l3);
    t0 = ((vader_struct_vader_c_emit_FnState_t*) l0)->f_aux_counter;
    l6 = (t0 + INT32_C(1));
    ((vader_struct_vader_c_emit_FnState_t*) l0)->f_aux_counter = l6;
    VADER_WRITE_BARRIER((vader_struct_vader_c_emit_FnState_t*) l0);
    { vader_string_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
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
        vader_array_t* _a0_arr = vader_array_new(37u, 0u, 13u, 498u);
        t1 = (void*) _a0_arr;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((int64_t) (int32_t) l1);
    l3 = (size_t) (int64_t) t0;
    vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
    if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
    if ((size_t) l3 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
    l5 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l3);
    if (l5.tag == 509u) {
        t1 = l5.payload.obj;
        { void* __vret = ((vader_struct_vader_bytecode_BcStruct_t*) t1)->f_fields; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a2_arr = vader_array_new(37u, 0u, 13u, 498u);
    t1 = (void*) _a2_arr;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
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
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
    l5 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
    if (l5.tag == 509u) {
        t1 = l5.payload.obj;
        t2 = ((vader_struct_vader_bytecode_BcStruct_t*) t1)->f_name;
        return t2;
    }
    return 0u;
}

static vader_string_t vader_c_emit_binop_text(void* l0, vader_string_t l1, uint8_t l2) {
    vader_box_t l3 = vader_box_null(), l4 = vader_box_null();
    void* l5 = NULL;
    vader_string_t l6 = 0;
    vader_string_t l8 = 0;
    uint8_t l7;
    bool l9;
    vader_string_t t0 = 0;
    vader_box_t* gc_roots[2] = { &l3, &l4 };
    void** gc_raw_roots[2] = { &l0, &l5 };
    vader_string_t* gc_atom_roots[4] = { &l1, &l6, &l8, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l3 = vader_c_emit_pop(l0);
    l4 = vader_c_emit_pop(l0);
    l5 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_ctx)->f_module)->f_types;
    l6 = vader_c_emit_name_of(l4);
    l7 = vader_c_emit_val_of(l4);
    l6 = vader_c_emit_coerce_operand(l5, l6, l7, l2);
    l5 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_ctx)->f_module)->f_types;
    l8 = vader_c_emit_name_of(l3);
    l7 = vader_c_emit_val_of(l3);
    l8 = vader_c_emit_coerce_operand(l5, l8, l7, l2);
    if (l1 == 515u) {
        l9 = true;
    } else {
        l9 = l1 == 220u;
    }
    if (l9) {
        t0 = concat_5(l6, 6u, l1, 6u, l8);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = concat_7(278u, l6, 6u, l1, 6u, l8, 318u);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_string_t vader_c_emit_box_expr(vader_string_t l0, uint8_t l1, int32_t l2) {
    vader_string_t l3 = 0;
    size_t l4;
    void* l5 = NULL;
    int64_t l6;
    vader_string_t t0 = 0;
    void** gc_raw_roots[1] = { &l5 };
    vader_string_t* gc_atom_roots[3] = { &l0, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    if (l1 == INT32_C(0)) {
        l3 = l0;
        l4 = vader_host_std_core_byte_len(l3);
        l5 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(38) + l4));
        l4 = (size_t) (int64_t) INT64_C(0);
        l4 = std_core_write_string_at(l5, l4, 2321u);
        l6 = ((int64_t) (int32_t) l2);
        l4 = std_core_write_int(l5, l4, l6);
        l4 = std_core_write_string_at(l5, l4, 2209u);
        l4 = std_core_write_string_at(l5, l4, l3);
        l4 = std_core_write_string_at(l5, l4, 318u);
        t0 = std_core_finish_buffer(l5, l4);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == INT32_C(1)) {
        l3 = l0;
        l4 = vader_host_std_core_byte_len(l3);
        l5 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(38) + l4));
        l4 = (size_t) (int64_t) INT64_C(0);
        l4 = std_core_write_string_at(l5, l4, 2321u);
        l6 = ((int64_t) (int32_t) l2);
        l4 = std_core_write_int(l5, l4, l6);
        l4 = std_core_write_string_at(l5, l4, 2209u);
        l4 = std_core_write_string_at(l5, l4, l3);
        l4 = std_core_write_string_at(l5, l4, 318u);
        t0 = std_core_finish_buffer(l5, l4);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == INT32_C(2)) {
        l3 = l0;
        l4 = vader_host_std_core_byte_len(l3);
        l5 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(38) + l4));
        l4 = (size_t) (int64_t) INT64_C(0);
        l4 = std_core_write_string_at(l5, l4, 2321u);
        l6 = ((int64_t) (int32_t) l2);
        l4 = std_core_write_int(l5, l4, l6);
        l4 = std_core_write_string_at(l5, l4, 2209u);
        l4 = std_core_write_string_at(l5, l4, l3);
        l4 = std_core_write_string_at(l5, l4, 318u);
        t0 = std_core_finish_buffer(l5, l4);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == INT32_C(5)) {
        l3 = l0;
        l4 = vader_host_std_core_byte_len(l3);
        l5 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(58) + l4));
        l4 = (size_t) (int64_t) INT64_C(0);
        l4 = std_core_write_string_at(l5, l4, 2321u);
        l6 = ((int64_t) (int32_t) l2);
        l4 = std_core_write_int(l5, l4, l6);
        l4 = std_core_write_string_at(l5, l4, 2212u);
        l4 = std_core_write_string_at(l5, l4, l3);
        l4 = std_core_write_string_at(l5, l4, 318u);
        t0 = std_core_finish_buffer(l5, l4);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == INT32_C(6)) {
        l3 = l0;
        l4 = vader_host_std_core_byte_len(l3);
        l5 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(58) + l4));
        l4 = (size_t) (int64_t) INT64_C(0);
        l4 = std_core_write_string_at(l5, l4, 2321u);
        l6 = ((int64_t) (int32_t) l2);
        l4 = std_core_write_int(l5, l4, l6);
        l4 = std_core_write_string_at(l5, l4, 2212u);
        l4 = std_core_write_string_at(l5, l4, l3);
        l4 = std_core_write_string_at(l5, l4, 318u);
        t0 = std_core_finish_buffer(l5, l4);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == INT32_C(7)) {
        l3 = l0;
        l4 = vader_host_std_core_byte_len(l3);
        l5 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(58) + l4));
        l4 = (size_t) (int64_t) INT64_C(0);
        l4 = std_core_write_string_at(l5, l4, 2321u);
        l6 = ((int64_t) (int32_t) l2);
        l4 = std_core_write_int(l5, l4, l6);
        l4 = std_core_write_string_at(l5, l4, 2212u);
        l4 = std_core_write_string_at(l5, l4, l3);
        l4 = std_core_write_string_at(l5, l4, 318u);
        t0 = std_core_finish_buffer(l5, l4);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == INT32_C(3)) {
        l3 = l0;
        l4 = vader_host_std_core_byte_len(l3);
        l5 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(38) + l4));
        l4 = (size_t) (int64_t) INT64_C(0);
        l4 = std_core_write_string_at(l5, l4, 2322u);
        l6 = ((int64_t) (int32_t) l2);
        l4 = std_core_write_int(l5, l4, l6);
        l4 = std_core_write_string_at(l5, l4, 2209u);
        l4 = std_core_write_string_at(l5, l4, l3);
        l4 = std_core_write_string_at(l5, l4, 318u);
        t0 = std_core_finish_buffer(l5, l4);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == INT32_C(4)) {
        l3 = l0;
        l4 = vader_host_std_core_byte_len(l3);
        l5 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(48) + l4));
        l4 = (size_t) (int64_t) INT64_C(0);
        l4 = std_core_write_string_at(l5, l4, 2322u);
        l6 = ((int64_t) (int32_t) l2);
        l4 = std_core_write_int(l5, l4, l6);
        l4 = std_core_write_string_at(l5, l4, 2213u);
        l4 = std_core_write_string_at(l5, l4, l3);
        l4 = std_core_write_string_at(l5, l4, 318u);
        t0 = std_core_finish_buffer(l5, l4);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == INT32_C(8)) {
        l3 = l0;
        l4 = vader_host_std_core_byte_len(l3);
        l5 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(58) + l4));
        l4 = (size_t) (int64_t) INT64_C(0);
        l4 = std_core_write_string_at(l5, l4, 2322u);
        l6 = ((int64_t) (int32_t) l2);
        l4 = std_core_write_int(l5, l4, l6);
        l4 = std_core_write_string_at(l5, l4, 2215u);
        l4 = std_core_write_string_at(l5, l4, l3);
        l4 = std_core_write_string_at(l5, l4, 318u);
        t0 = std_core_finish_buffer(l5, l4);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == INT32_C(9)) {
        l3 = l0;
        l4 = vader_host_std_core_byte_len(l3);
        l5 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(58) + l4));
        l4 = (size_t) (int64_t) INT64_C(0);
        l4 = std_core_write_string_at(l5, l4, 2322u);
        l6 = ((int64_t) (int32_t) l2);
        l4 = std_core_write_int(l5, l4, l6);
        l4 = std_core_write_string_at(l5, l4, 2215u);
        l4 = std_core_write_string_at(l5, l4, l3);
        l4 = std_core_write_string_at(l5, l4, 318u);
        t0 = std_core_finish_buffer(l5, l4);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == INT32_C(10)) {
        l3 = l0;
        l4 = vader_host_std_core_byte_len(l3);
        l5 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(47) + l4));
        l4 = (size_t) (int64_t) INT64_C(0);
        l4 = std_core_write_string_at(l5, l4, 2320u);
        l6 = ((int64_t) (int32_t) l2);
        l4 = std_core_write_int(l5, l4, l6);
        l4 = std_core_write_string_at(l5, l4, 2210u);
        l4 = std_core_write_string_at(l5, l4, l3);
        l4 = std_core_write_string_at(l5, l4, 318u);
        t0 = std_core_finish_buffer(l5, l4);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == INT32_C(11)) {
        l3 = l0;
        l4 = vader_host_std_core_byte_len(l3);
        l5 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(38) + l4));
        l4 = (size_t) (int64_t) INT64_C(0);
        l4 = std_core_write_string_at(l5, l4, 2320u);
        l6 = ((int64_t) (int32_t) l2);
        l4 = std_core_write_int(l5, l4, l6);
        l4 = std_core_write_string_at(l5, l4, 2209u);
        l4 = std_core_write_string_at(l5, l4, l3);
        l4 = std_core_write_string_at(l5, l4, 318u);
        t0 = std_core_finish_buffer(l5, l4);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == INT32_C(12)) {
        l3 = l0;
        l4 = vader_host_std_core_byte_len(l3);
        l5 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(39) + l4));
        l4 = (size_t) (int64_t) INT64_C(0);
        l4 = std_core_write_string_at(l5, l4, 2319u);
        l6 = ((int64_t) (int32_t) l2);
        l4 = std_core_write_int(l5, l4, l6);
        l4 = std_core_write_string_at(l5, l4, 2209u);
        l4 = std_core_write_string_at(l5, l4, l3);
        l4 = std_core_write_string_at(l5, l4, 318u);
        t0 = std_core_finish_buffer(l5, l4);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == INT32_C(13)) {
        l3 = l0;
        l4 = vader_host_std_core_byte_len(l3);
        l5 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(48) + l4));
        l4 = (size_t) (int64_t) INT64_C(0);
        l4 = std_core_write_string_at(l5, l4, 2321u);
        l6 = ((int64_t) (int32_t) l2);
        l4 = std_core_write_int(l5, l4, l6);
        l4 = std_core_write_string_at(l5, l4, 2211u);
        l4 = std_core_write_string_at(l5, l4, l3);
        l4 = std_core_write_string_at(l5, l4, 318u);
        t0 = std_core_finish_buffer(l5, l4);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == INT32_C(14)) {
        l3 = l0;
        l4 = vader_host_std_core_byte_len(l3);
        l5 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(41) + l4));
        l4 = (size_t) (int64_t) INT64_C(0);
        l4 = std_core_write_string_at(l5, l4, 2325u);
        l6 = ((int64_t) (int32_t) l2);
        l4 = std_core_write_int(l5, l4, l6);
        l4 = std_core_write_string_at(l5, l4, 2209u);
        l4 = std_core_write_string_at(l5, l4, l3);
        l4 = std_core_write_string_at(l5, l4, 318u);
        t0 = std_core_finish_buffer(l5, l4);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == INT32_C(15)) {
        { vader_string_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == INT32_C(16)) {
        { vader_gc_top = gc_frame.prev; return 2323u; }
    }
    if (l1 == INT32_C(17)) {
        l3 = l0;
        l4 = vader_host_std_core_byte_len(l3);
        l5 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(59) + l4));
        l4 = (size_t) (int64_t) INT64_C(0);
        l4 = std_core_write_string_at(l5, l4, 2322u);
        l6 = ((int64_t) (int32_t) l2);
        l4 = std_core_write_int(l5, l4, l6);
        l4 = std_core_write_string_at(l5, l4, 2214u);
        l4 = std_core_write_string_at(l5, l4, l3);
        l4 = std_core_write_string_at(l5, l4, 318u);
        t0 = std_core_finish_buffer(l5, l4);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == INT32_C(18)) {
        t0 = concat_3(2356u, l0, 318u);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == INT32_C(19)) {
        { vader_string_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_unreachable("unreachable return in vader_c_emit$box_expr");
    vader_gc_top = gc_frame.prev;
}

static vader_string_t vader_c_emit_box_expr_unknown(void* l0, vader_string_t l1, uint8_t l2) {
    int32_t l3;
    vader_string_t t0 = 0;
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[2] = { &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l3 = vader_c_emit_primitive_tag_of(l0, l2);
    t0 = vader_c_emit_box_expr(l1, l2, l3);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_string_t vader_c_emit_box_slot_c(void* l0, void* l1, vader_box_t l2, vader_string_t l3, int32_t l4, void* l5) {
    void* l6 = NULL;
    void* l7 = NULL;
    size_t l8;
    int64_t l9;
    vader_string_t l10 = 0;
    vader_box_t l11 = vader_box_null();
    int32_t t0;
    vader_string_t t1 = 0;
    vader_box_t* gc_roots[2] = { &l2, &l11 };
    void** gc_raw_roots[5] = { &l0, &l1, &l5, &l6, &l7 };
    vader_string_t* gc_atom_roots[3] = { &l3, &l10, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    if (l2.tag == 513u) {
        l6 = l2.payload.obj;
        l7 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(61));
        l8 = (size_t) (int64_t) INT64_C(0);
        l8 = std_core_write_string_at(l7, l8, 2417u);
        l9 = ((int64_t) (int32_t) l4);
        l8 = std_core_write_int(l7, l8, l9);
        l8 = std_core_write_string_at(l7, l8, 2223u);
        l10 = ((vader_struct_vader_bytecode_BcValStr_t*) l6)->f_value;
        t0 = vader_c_emit_atom_for(l5, l10);
        l9 = ((int64_t) (int32_t) t0);
        l8 = std_core_write_int(l7, l8, l9);
        l8 = std_core_write_string_at(l7, l8, 2202u);
        t1 = std_core_finish_buffer(l7, l8);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l11 = l2;
    l10 = vader_c_emit_emit_data_value(l0, l1, l11, l3, l5);
    l8 = vader_host_std_core_byte_len(l10);
    l6 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(50) + l8));
    l8 = (size_t) (int64_t) INT64_C(0);
    l8 = std_core_write_string_at(l6, l8, 2417u);
    l9 = ((int64_t) (int32_t) l4);
    l8 = std_core_write_int(l6, l8, l9);
    l8 = std_core_write_string_at(l6, l8, 2222u);
    l8 = std_core_write_string_at(l6, l8, l10);
    l8 = std_core_write_string_at(l6, l8, 204u);
    t1 = std_core_finish_buffer(l6, l8);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_c_emit_boxed_pool_objects(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l7 = NULL;
    size_t l4, l5, l6, l8;
    uint64_t l9;
    vader_string_t l10 = 0;
    int64_t t0;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &l7 };
    vader_string_t* gc_atom_roots[1] = { &l10 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 167u);
    l2 = (void*) _a0_arr;
    l3 = l1;
    l4 = ((vader_array_t*) l3)->length;
    l5 = (size_t) (int64_t) INT64_C(0);
    {
        loop_9: {
            if ((l5 < l4)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l5 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l5];
                l6 = (size_t) (int64_t) t0;
                l7 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(32));
                l8 = (size_t) (int64_t) INT64_C(0);
                l8 = std_core_write_string_at(l7, l8, 261u);
                t0 = ((int64_t) (size_t) l6);
                l9 = (uint64_t) (int64_t) t0;
                l8 = std_core_write_unsigned(l7, l8, l9);
                l10 = std_core_finish_buffer(l7, l8);
                vader_array_push((vader_array_t*) l2, vader_box_string(167u, l10));
                t0 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t0;
                goto loop_9;
            } else {
            }
        }
    }
    l3 = l1;
    l4 = ((vader_array_t*) l3)->length;
    l5 = (size_t) (int64_t) INT64_C(0);
    {
        loop_59: {
            if ((l5 < l4)) {
                vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
                if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                if ((size_t) l5 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = ((int64_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l5];
                l6 = (size_t) (int64_t) t0;
                vader_array_t* _a3_slotarr = ((vader_array_t*) l0);
                if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                if ((size_t) l6 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                t1 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l6);
                if (!(t1.tag == 504u)) {
                    l7 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(36));
                    l8 = (size_t) (int64_t) INT64_C(0);
                    l8 = std_core_write_string_at(l7, l8, 261u);
                    t0 = ((int64_t) (size_t) l6);
                    l9 = (uint64_t) (int64_t) t0;
                    l8 = std_core_write_unsigned(l7, l8, l9);
                    l8 = std_core_write_string_at(l7, l8, 901u);
                    l10 = std_core_finish_buffer(l7, l8);
                    vader_array_push((vader_array_t*) l2, vader_box_string(167u, l10));
                } else {
                }
                t0 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t0;
                goto loop_59;
            } else {
            }
        }
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_box_t vader_c_emit_branch_target(void* l0, int32_t l1) {
    size_t l2, l3;
    void* t0;
    bool t1;
    int64_t t2;
    int32_t t3;
    vader_box_t t4;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    l2 = ((vader_array_t*) l0)->length;
    l3 = (size_t) (int64_t) INT64_C(0);
    {
        loop_6: {
            if ((l3 < l2)) {
                if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
                t1 = vader_c_emit_is_continue_branch(t0, l1);
                if (t1) {
                    vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
                    if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                    if ((size_t) l3 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                    t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l3);
                    return vader_ref_box(t0);
                }
                t2 = (l3 + INT64_C(1));
                l3 = (size_t) (int64_t) t2;
                goto loop_6;
            } else {
            }
        }
    }
    vader_array_t* _a2_slotarr = ((vader_array_t*) l0);
    if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
    l2 = ((vader_array_t*) l0)->length;
    l3 = (size_t) (int64_t) INT64_C(0);
    {
        loop_37: {
            if ((l3 < l2)) {
                if ((size_t) l3 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l3);
                t3 = ((vader_struct_vader_c_emit_ScopeInfo_t*) t0)->f_end_pc;
                if ((t3 + INT32_C(1)) == l1) {
                    if ((size_t) l3 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                    t0 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l3);
                    return vader_ref_box(t0);
                }
                t2 = (l3 + INT64_C(1));
                l3 = (size_t) (int64_t) t2;
                goto loop_37;
            } else {
            }
        }
    }
    t4 = vader_box_obj(0u, NULL);
    return t4;
}

static vader_string_t vader_c_emit_buf_ptr(vader_box_t l0) {
    vader_string_t l1 = 0;
    vader_string_t t0 = 0;
    vader_box_t* gc_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[2] = { &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 0u, gc_roots, NULL, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l1 = vader_c_emit_obj_ptr_of(l0);
    t0 = concat_2(313u, l1);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
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
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 167u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(9u, 0u, 7u, 170u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 170u);
    l3 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__string__i32_t* _a3_obj = (vader_struct_std_collections_MutableMap__string__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__i32_t));
    vader_obj_header_init(_a3_obj, 358u);
    _a3_obj->f_ekeys = l1;
    _a3_obj->f_evals = l2;
    _a3_obj->f_index = l3;
    _a3_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l1 = (void*) _a3_obj;
    l2 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_strings;
    l4 = ((vader_array_t*) l2)->length;
    l5 = (size_t) (int64_t) INT64_C(0);
    {
        loop_22: {
            if ((l5 < l4)) {
                vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
                if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                if ((size_t) l5 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_box_slots(_a4_slotarr->buf)[_a4_slotarr->offset + (size_t) l5];
                l6 = t0.payload.s;
                vader_array_t* _a5_slotarr = ((vader_array_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_atom_ids);
                if (_a5_slotarr->buf != NULL && _a5_slotarr->buf->header.forward != NULL) { _a5_slotarr->buf = vader_array_buf_forward(_a5_slotarr->buf); }
                if ((size_t) l5 >= _a5_slotarr->length) { vader_trap("array index out of bounds"); }
                l7 = ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l5];
                std_collections_put__string__i32(l1, l6, l7);
                t1 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t1;
                goto loop_22;
            } else {
            }
        }
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
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
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l1 = vader_host_std_core_byte_len(l0);
    vader_array_t* _a0_arr = vader_array_new(11u, 0u, 1u, 173u);
    l2 = (void*) _a0_arr;
    vader_array_push_u8((vader_array_t*) l2, INT32_C(34));
    l3 = (size_t) (int64_t) INT64_C(0);
    {
        loop_10: {
            if ((l3 < l1)) {
                l4 = vader_host_std_core_byte_at(l0, l3);
                if (l4 == INT32_C(92)) {
                    vader_array_push_u8((vader_array_t*) l2, INT32_C(92));
                    vader_array_push_u8((vader_array_t*) l2, INT32_C(92));
                } else {
                    if (l4 == INT32_C(34)) {
                        vader_array_push_u8((vader_array_t*) l2, INT32_C(92));
                        vader_array_push_u8((vader_array_t*) l2, INT32_C(34));
                    } else {
                        if (l4 == INT32_C(10)) {
                            vader_array_push_u8((vader_array_t*) l2, INT32_C(92));
                            vader_array_push_u8((vader_array_t*) l2, INT32_C(110));
                        } else {
                            if (l4 == INT32_C(13)) {
                                vader_array_push_u8((vader_array_t*) l2, INT32_C(92));
                                vader_array_push_u8((vader_array_t*) l2, INT32_C(114));
                            } else {
                                if (l4 == INT32_C(9)) {
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
                                            } else {
                                            }
                                        } else {
                                        }
                                    } else {
                                        vader_array_push_u8((vader_array_t*) l2, (int32_t) (uint8_t) l4);
                                    }
                                }
                            }
                        }
                    }
                }
                t2 = (l3 + INT64_C(1));
                l3 = (size_t) (int64_t) t2;
                goto loop_10;
            } else {
            }
        }
    }
    vader_array_push_u8((vader_array_t*) l2, INT32_C(34));
    t5 = vader_host_std_core_bytes_to_string(l2);
    { vader_string_t __vret = t5; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_c_emit_c_struct_layout_asserts(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l7 = NULL;
    void* l10 = NULL;
    void* l13 = NULL;
    void* l19 = NULL;
    void* l28 = NULL;
    void* l31 = NULL;
    size_t l4, l5, l16, l17, l18, l20, l25, l26, l27, l29;
    vader_box_t l6 = vader_box_null();
    int32_t l8, l11;
    bool l9;
    vader_string_t l12 = 0;
    vader_string_t l14 = 0;
    vader_string_t l15 = 0;
    vader_string_t l22 = 0;
    vader_string_t l23 = 0;
    vader_string_t l24 = 0;
    vader_string_t l30 = 0;
    vader_string_t l32 = 0;
    int64_t l21;
    int64_t t0;
    void* t1 = NULL;
    vader_string_t t2 = 0;
    size_t t3;
    bool t4;
    vader_box_t* gc_roots[1] = { &l6 };
    void** gc_raw_roots[11] = { &l0, &l1, &l2, &l3, &l7, &l10, &l13, &l19, &l28, &l31, &t1 };
    vader_string_t* gc_atom_roots[9] = { &l12, &l14, &l15, &l22, &l23, &l24, &l30, &l32, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 11u, gc_roots, gc_raw_roots, 0u, NULL, 9u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 167u);
    l2 = (void*) _a0_arr;
    l3 = vader_c_emit_nested_member_mirrors(l0);
    l4 = ((vader_array_t*) l0)->length;
    l5 = (size_t) (int64_t) INT64_C(0);
    {
        loop_11: {
            if ((l5 < l4)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l5 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                l6 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5);
                if (!(l6.tag == 509u)) {
                    t0 = (l5 + INT64_C(1));
                    l5 = (size_t) (int64_t) t0;
                    goto loop_11;
                }
                t1 = l6.payload.obj;
                t2 = ((vader_struct_vader_bytecode_BcStruct_t*) t1)->f_c_name;
                if (t2 == 0u) {
                    t0 = (l5 + INT64_C(1));
                    l5 = (size_t) (int64_t) t0;
                    goto loop_11;
                }
                t1 = l6.payload.obj;
                t3 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcStruct_t*) t1)->f_fields)->length;
                if (t3 == INT64_C(0)) {
                    t0 = (l5 + INT64_C(1));
                    l5 = (size_t) (int64_t) t0;
                    goto loop_11;
                }
                l7 = ((vader_struct_std_collections_MutableSet__i32_t*) l3)->f_inner;
                l8 = ((int32_t) (size_t) l5);
                t4 = std_collections_contains_key__i32__bool(l7, l8);
                if (t4) {
                    l10 = ((vader_struct_std_collections_MutableSet__i32_t*) l1)->f_inner;
                    l11 = ((int32_t) (size_t) l5);
                    t4 = std_collections_contains_key__i32__bool(l10, l11);
                    l9 = !(t4);
                } else {
                    l9 = false;
                }
                if (l9) {
                    t0 = (l5 + INT64_C(1));
                    l5 = (size_t) (int64_t) t0;
                    goto loop_11;
                }
                t1 = l6.payload.obj;
                t2 = ((vader_struct_vader_bytecode_BcStruct_t*) t1)->f_name;
                l12 = vader_c_emit_struct_c_name(t2);
                t1 = l6.payload.obj;
                l13 = vader_bytecode_c_struct_layout(((vader_struct_vader_bytecode_BcStruct_t*) t1)->f_fields, l0);
                t1 = l6.payload.obj;
                l14 = ((vader_struct_vader_bytecode_BcStruct_t*) t1)->f_c_name;
                t1 = l6.payload.obj;
                l15 = ((vader_struct_vader_bytecode_BcStruct_t*) t1)->f_c_name;
                l16 = vader_host_std_core_byte_len(l14);
                l17 = vader_host_std_core_byte_len(l15);
                t0 = (l16 + l17);
                l18 = (size_t) (int64_t) t0;
                l19 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(60) + l18));
                l20 = (size_t) (int64_t) INT64_C(0);
                l20 = std_core_write_string_at(l19, l20, 875u);
                l21 = ((vader_struct_vader_bytecode_CLayout_t*) l13)->f_size;
                l20 = std_core_write_int(l19, l20, l21);
                l20 = std_core_write_string_at(l19, l20, 60u);
                l20 = std_core_write_string_at(l19, l20, l14);
                l20 = std_core_write_string_at(l19, l20, 345u);
                l20 = std_core_write_string_at(l19, l20, l15);
                l20 = std_core_write_string_at(l19, l20, 160u);
                l22 = std_core_finish_buffer(l19, l20);
                vader_array_push((vader_array_t*) l2, vader_box_string(167u, l22));
                t1 = l6.payload.obj;
                l23 = ((vader_struct_vader_bytecode_BcStruct_t*) t1)->f_c_name;
                t1 = l6.payload.obj;
                l24 = ((vader_struct_vader_bytecode_BcStruct_t*) t1)->f_c_name;
                l25 = vader_host_std_core_byte_len(l23);
                l26 = vader_host_std_core_byte_len(l24);
                t0 = (l25 + l26);
                l27 = (size_t) (int64_t) t0;
                l28 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(80) + l27));
                l29 = (size_t) (int64_t) INT64_C(0);
                l29 = std_core_write_string_at(l28, l29, 877u);
                l29 = std_core_write_string_at(l28, l29, l23);
                l29 = std_core_write_string_at(l28, l29, 322u);
                l29 = std_core_write_int(l28, l29, INT64_C(4096));
                l29 = std_core_write_string_at(l28, l29, 366u);
                l29 = std_core_write_string_at(l28, l29, l24);
                l29 = std_core_write_string_at(l28, l29, 115u);
                l30 = std_core_finish_buffer(l28, l29);
                vader_array_push((vader_array_t*) l2, vader_box_string(167u, l30));
                t1 = l6.payload.obj;
                l31 = ((vader_struct_vader_bytecode_BcStruct_t*) t1)->f_fields;
                t1 = l6.payload.obj;
                l32 = ((vader_struct_vader_bytecode_BcStruct_t*) t1)->f_c_name;
                vader_c_emit_push_leaf_asserts(l0, l31, l32, 0u, l12, INT64_C(0), l2, INT32_C(0));
                t0 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t0;
                goto loop_11;
            } else {
            }
        }
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_string_t vader_c_emit_c_type_for(vader_box_t l0) {
    uint8_t t0;
    vader_string_t t1;
    t0 = vader_c_emit_val_type_of_bc_type(l0);
    t1 = vader_c_emit_c_type_for_val_bare(t0);
    return t1;
}

static vader_string_t vader_c_emit_c_type_for_array_kind(uint8_t l0) {
    if (l0 == INT32_C(1)) {
        return 2257u;
    }
    if (l0 == INT32_C(2)) {
        return 2254u;
    }
    if (l0 == INT32_C(3)) {
        return 2255u;
    }
    if (l0 == INT32_C(4)) {
        return 2256u;
    }
    if (l0 == INT32_C(5)) {
        return 1729u;
    }
    if (l0 == INT32_C(6)) {
        return 1726u;
    }
    if (l0 == INT32_C(7)) {
        return 1727u;
    }
    if (l0 == INT32_C(8)) {
        return 1728u;
    }
    if (l0 == INT32_C(9)) {
        return 1591u;
    }
    if (l0 == INT32_C(10)) {
        return 1451u;
    }
    if (l0 == INT32_C(11)) {
        return 2255u;
    }
    if (l0 == INT32_C(12)) {
        return 2257u;
    }
    if (l0 == INT32_C(13)) {
        return 2383u;
    }
    if (l0 == INT32_C(0)) {
        return 2326u;
    }
    vader_unreachable("unreachable return in vader_c_emit$c_type_for_array_kind");
}

static vader_string_t vader_c_emit_c_type_for_val_bare(uint8_t l0) {
    if (l0 == INT32_C(0)) {
        return 1729u;
    }
    if (l0 == INT32_C(1)) {
        return 1726u;
    }
    if (l0 == INT32_C(2)) {
        return 1727u;
    }
    if (l0 == INT32_C(3)) {
        return 1728u;
    }
    if (l0 == INT32_C(5)) {
        return 2257u;
    }
    if (l0 == INT32_C(6)) {
        return 2254u;
    }
    if (l0 == INT32_C(7)) {
        return 2255u;
    }
    if (l0 == INT32_C(8)) {
        return 2256u;
    }
    if (l0 == INT32_C(9)) {
        return 2013u;
    }
    if (l0 == INT32_C(4)) {
        return 1946u;
    }
    if (l0 == INT32_C(10)) {
        return 1591u;
    }
    if (l0 == INT32_C(11)) {
        return 1451u;
    }
    if (l0 == INT32_C(12)) {
        return 1264u;
    }
    if (l0 == INT32_C(13)) {
        return 2255u;
    }
    if (l0 == INT32_C(14)) {
        return 2359u;
    }
    if (l0 == INT32_C(15)) {
        return 2326u;
    }
    if (l0 == INT32_C(16)) {
        return 2382u;
    }
    if (l0 == INT32_C(17)) {
        return 2383u;
    }
    if (l0 == INT32_C(18)) {
        return 2383u;
    }
    if (l0 == INT32_C(19)) {
        return 2326u;
    }
    vader_unreachable("unreachable return in vader_c_emit$c_type_for_val_bare");
}

static int32_t vader_c_emit_callee_index_of(vader_box_t l0) {
    void* t0;
    int32_t t1;
    if (l0.tag == 532u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_bytecode_Call_t*) t0)->f_function_index;
        return t1;
    }
    if (l0.tag == 561u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_bytecode_FnRef_t*) t0)->f_function_index;
        return t1;
    }
    if (l0.tag == 560u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_bytecode_FnAddr_t*) t0)->f_function_index;
        return t1;
    }
    return -(INT32_C(1));
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
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_struct_c_names);
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    if ((size_t) l2 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
    t0 = vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l2];
    l3 = t0.payload.s;
    l4 = vader_c_emit_empty_struct_offsets();
    l5 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcStruct_t*) l1)->f_fields)->length;
    l6 = (size_t) (int64_t) INT64_C(0);
    {
        loop_13: {
            if ((l6 < l5)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcStruct_t*) l1)->f_fields);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l6 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                l7 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l6);
                l8 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_types;
                t1 = ((vader_struct_vader_bytecode_BcField_t*) l7)->f_type_index;
                t2 = ((int64_t) (int32_t) t1);
                l9 = (size_t) (int64_t) t2;
                vader_array_t* _a2_slotarr = ((vader_array_t*) l8);
                if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                if ((size_t) l9 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                l10 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l9);
                t3 = ((vader_struct_vader_bytecode_BcField_t*) l7)->f_name;
                l11 = vader_c_emit_sanitise(t3);
                l12 = concat_5(1912u, l3, 375u, l11, 318u);
                if (l10.tag == 505u) {
                    t4 = l10.payload.obj;
                    t5 = vader_bytecode_is_string_val(((vader_struct_vader_bytecode_BcPrimitive_t*) t4)->f_val);
                    if (t5) {
                        vader_array_push((vader_array_t*) ((vader_struct_vader_c_emit_StructOffsets_t*) l4)->f_str_offsets, vader_box_string(167u, l12));
                    } else {
                    }
                } else {
                    t6 = vader_c_emit_val_type_of_bc_type(l10);
                    if (t6 == INT32_C(18)) {
                        vader_array_push((vader_array_t*) ((vader_struct_vader_c_emit_StructOffsets_t*) l4)->f_ref_offsets, vader_box_string(167u, l12));
                    } else {
                        vader_array_push((vader_array_t*) ((vader_struct_vader_c_emit_StructOffsets_t*) l4)->f_ptr_offsets, vader_box_string(167u, l12));
                    }
                }
                t2 = (l6 + INT64_C(1));
                l6 = (size_t) (int64_t) t2;
                goto loop_13;
            } else {
            }
        }
    }
    { void* __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_c_emit_coalesce_temps(vader_string_t l0, void* l1) {
    size_t l2, l6, l10, l12, l17, l18, l19;
    vader_string_t l3 = 0;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l9 = NULL;
    void* l15 = NULL;
    void* l20 = NULL;
    void* l21 = NULL;
    int32_t l7, l8, l22;
    bool l11, l13, l14, l16;
    uint8_t l23, l24, l25;
    void* t0 = NULL;
    int64_t t1;
    vader_box_t t2 = vader_box_null();
    uint8_t t3;
    bool t4;
    size_t t5;
    int32_t t6;
    vader_box_t* gc_roots[1] = { &t2 };
    void** gc_raw_roots[8] = { &l1, &l4, &l5, &l9, &l15, &l20, &l21, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l0, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = ((vader_array_t*) l1)->length;
    if (l2 == INT64_C(0)) {
        vader_array_t* _a0_arr = vader_array_new(11u, 0u, 1u, 173u);
        t0 = (void*) _a0_arr;
        vader_struct_vader_c_emit_CoalesceResult_t* _a1_obj = (vader_struct_vader_c_emit_CoalesceResult_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_CoalesceResult_t));
        vader_obj_header_init(_a1_obj, 660u);
        _a1_obj->f_types = t0;
        _a1_obj->f_body = l0;
        t0 = (void*) _a1_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = vader_c_emit_fuse_temp_local_copies(l0, l2);
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 170u);
    l4 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(9u, 0u, 7u, 170u);
    l5 = (void*) _a3_arr;
    l6 = (size_t) (int64_t) INT64_C(0);
    {
        loop_22: {
            if ((l6 < l2)) {
                l7 = -(INT32_C(1));
                vader_array_push_i32((vader_array_t*) l4, l7);
                l8 = -(INT32_C(1));
                vader_array_push_i32((vader_array_t*) l5, l8);
                t1 = (l6 + INT64_C(1));
                l6 = (size_t) (int64_t) t1;
                goto loop_22;
            } else {
            }
        }
    }
    l9 = vader_host_std_core_bytes(l3);
    l6 = ((vader_array_t*) l9)->length;
    l7 = INT32_C(0);
    l10 = (size_t) (int64_t) INT64_C(0);
    {
        loop_58: {
            if ((l10 < l6)) {
                if (l10 == INT64_C(0)) {
                    l11 = true;
                } else {
                    t1 = (l10 - INT64_C(1));
                    l12 = (size_t) (int64_t) t1;
                    vader_array_t* _a4_slotarr = ((vader_array_t*) l9);
                    if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                    if ((size_t) l12 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                    t2 = vader_array_read_u8(_a4_slotarr, _a4_slotarr->offset + (size_t) l12, 173u);
                    t3 = ((uint8_t) t2.payload.i);
                    l11 = t3 == INT32_C(10);
                }
                if (l11) {
                    vader_array_t* _a5_slotarr = ((vader_array_t*) l9);
                    if (_a5_slotarr->buf != NULL && _a5_slotarr->buf->header.forward != NULL) { _a5_slotarr->buf = vader_array_buf_forward(_a5_slotarr->buf); }
                    if ((size_t) l10 >= _a5_slotarr->length) { vader_trap("array index out of bounds"); }
                    t2 = vader_array_read_u8(_a5_slotarr, _a5_slotarr->offset + (size_t) l10, 173u);
                    t3 = ((uint8_t) t2.payload.i);
                    l13 = t3 == INT32_C(35);
                } else {
                    l13 = false;
                }
                if (l13) {
                    {
                        loop_98: {
                            if ((l10 < l6)) {
                                vader_array_t* _a6_slotarr = ((vader_array_t*) l9);
                                if (_a6_slotarr->buf != NULL && _a6_slotarr->buf->header.forward != NULL) { _a6_slotarr->buf = vader_array_buf_forward(_a6_slotarr->buf); }
                                if ((size_t) l10 >= _a6_slotarr->length) { vader_trap("array index out of bounds"); }
                                t2 = vader_array_read_u8(_a6_slotarr, _a6_slotarr->offset + (size_t) l10, 173u);
                                t3 = ((uint8_t) t2.payload.i);
                                l14 = t3 != INT32_C(10);
                            } else {
                                l14 = false;
                            }
                            if (l14) {
                                t1 = (l10 + INT64_C(1));
                                l10 = (size_t) (int64_t) t1;
                                goto loop_98;
                            } else {
                            }
                        }
                    }
                    goto loop_58;
                }
                vader_array_t* _a7_slotarr = ((vader_array_t*) l9);
                if (_a7_slotarr->buf != NULL && _a7_slotarr->buf->header.forward != NULL) { _a7_slotarr->buf = vader_array_buf_forward(_a7_slotarr->buf); }
                if ((size_t) l10 >= _a7_slotarr->length) { vader_trap("array index out of bounds"); }
                t2 = vader_array_read_u8(_a7_slotarr, _a7_slotarr->offset + (size_t) l10, 173u);
                t3 = ((uint8_t) t2.payload.i);
                if (t3 == INT32_C(10)) {
                    l7 = (l7 + INT32_C(1));
                    t1 = (l10 + INT64_C(1));
                    l10 = (size_t) (int64_t) t1;
                    goto loop_58;
                }
                vader_array_t* _a8_slotarr = ((vader_array_t*) l9);
                if (_a8_slotarr->buf != NULL && _a8_slotarr->buf->header.forward != NULL) { _a8_slotarr->buf = vader_array_buf_forward(_a8_slotarr->buf); }
                if ((size_t) l10 >= _a8_slotarr->length) { vader_trap("array index out of bounds"); }
                t2 = vader_array_read_u8(_a8_slotarr, _a8_slotarr->offset + (size_t) l10, 173u);
                t3 = ((uint8_t) t2.payload.i);
                if (t3 != INT32_C(116)) {
                    t1 = (l10 + INT64_C(1));
                    l10 = (size_t) (int64_t) t1;
                    goto loop_58;
                }
                l15 = vader_c_emit_temp_token_at(l9, l10, l6);
                t4 = ((vader_struct_vader_c_emit_SlotToken_t*) l15)->f_ok;
                if (t4) {
                    t5 = ((vader_struct_vader_c_emit_SlotToken_t*) l15)->f_id;
                    l16 = (t5 < l2);
                } else {
                    l16 = false;
                }
                if (l16) {
                    l17 = ((vader_struct_vader_c_emit_SlotToken_t*) l15)->f_id;
                    vader_array_t* _a9_slotarr = ((vader_array_t*) l4);
                    if (_a9_slotarr->buf != NULL && _a9_slotarr->buf->header.forward != NULL) { _a9_slotarr->buf = vader_array_buf_forward(_a9_slotarr->buf); }
                    if ((size_t) l17 >= _a9_slotarr->length) { vader_trap("array index out of bounds"); }
                    t6 = ((int32_t*) _a9_slotarr->buf->slots)[_a9_slotarr->offset + (size_t) l17];
                    if ((t6 < INT32_C(0))) {
                        l18 = ((vader_struct_vader_c_emit_SlotToken_t*) l15)->f_id;
                        vader_array_t* _a10_slotarr = ((vader_array_t*) l4);
                        if (_a10_slotarr->buf != NULL && _a10_slotarr->buf->header.forward != NULL) { _a10_slotarr->buf = vader_array_buf_forward(_a10_slotarr->buf); }
                        if ((size_t) l18 >= _a10_slotarr->length) { vader_trap("array index out of bounds"); }
                        ((int32_t*) _a10_slotarr->buf->slots)[_a10_slotarr->offset + (size_t) l18] = (int32_t) l7;
                    } else {
                    }
                    l19 = ((vader_struct_vader_c_emit_SlotToken_t*) l15)->f_id;
                    vader_array_t* _a11_slotarr = ((vader_array_t*) l5);
                    if (_a11_slotarr->buf != NULL && _a11_slotarr->buf->header.forward != NULL) { _a11_slotarr->buf = vader_array_buf_forward(_a11_slotarr->buf); }
                    if ((size_t) l19 >= _a11_slotarr->length) { vader_trap("array index out of bounds"); }
                    ((int32_t*) _a11_slotarr->buf->slots)[_a11_slotarr->offset + (size_t) l19] = (int32_t) l7;
                } else {
                }
                l10 = ((vader_struct_vader_c_emit_SlotToken_t*) l15)->f_end;
                goto loop_58;
            } else {
            }
        }
    }
    l9 = vader_c_emit_order_by_first(l4, l2);
    vader_array_t* _a12_arr = vader_array_new(9u, 1u, 7u, 170u);
    ((int32_t*) _a12_arr->buf->slots)[_a12_arr->offset + 0u] = (int32_t) -(INT32_C(1));
    t0 = (void*) _a12_arr;
    vader_array_t* _a13_arr = vader_array_repeat((vader_array_t*) t0, (size_t) l2);
    l15 = (void*) _a13_arr;
    vader_array_t* _a14_arr = vader_array_new(11u, 0u, 1u, 173u);
    l20 = (void*) _a14_arr;
    vader_array_t* _a15_arr = vader_array_new(9u, 0u, 7u, 170u);
    l21 = (void*) _a15_arr;
    l2 = ((vader_array_t*) l9)->length;
    l6 = (size_t) (int64_t) INT64_C(0);
    {
        loop_231: {
            if ((l6 < l2)) {
                vader_array_t* _a16_slotarr = ((vader_array_t*) l9);
                if (_a16_slotarr->buf != NULL && _a16_slotarr->buf->header.forward != NULL) { _a16_slotarr->buf = vader_array_buf_forward(_a16_slotarr->buf); }
                if ((size_t) l6 >= _a16_slotarr->length) { vader_trap("array index out of bounds"); }
                t1 = ((int64_t*) _a16_slotarr->buf->slots)[_a16_slotarr->offset + (size_t) l6];
                l10 = (size_t) (int64_t) t1;
                vader_array_t* _a17_slotarr = ((vader_array_t*) l4);
                if (_a17_slotarr->buf != NULL && _a17_slotarr->buf->header.forward != NULL) { _a17_slotarr->buf = vader_array_buf_forward(_a17_slotarr->buf); }
                if ((size_t) l10 >= _a17_slotarr->length) { vader_trap("array index out of bounds"); }
                l7 = ((int32_t*) _a17_slotarr->buf->slots)[_a17_slotarr->offset + (size_t) l10];
                vader_array_t* _a18_slotarr = ((vader_array_t*) l5);
                if (_a18_slotarr->buf != NULL && _a18_slotarr->buf->header.forward != NULL) { _a18_slotarr->buf = vader_array_buf_forward(_a18_slotarr->buf); }
                if ((size_t) l10 >= _a18_slotarr->length) { vader_trap("array index out of bounds"); }
                l8 = ((int32_t*) _a18_slotarr->buf->slots)[_a18_slotarr->offset + (size_t) l10];
                l22 = -(INT32_C(1));
                vader_array_t* _a19_slotarr = ((vader_array_t*) l20);
                if (_a19_slotarr->buf != NULL && _a19_slotarr->buf->header.forward != NULL) { _a19_slotarr->buf = vader_array_buf_forward(_a19_slotarr->buf); }
                l12 = ((vader_array_t*) l20)->length;
                l17 = (size_t) (int64_t) INT64_C(0);
                {
                    loop_257: {
                        if ((l17 < l12)) {
                            if ((size_t) l17 >= _a19_slotarr->length) { vader_trap("array index out of bounds"); }
                            t2 = vader_array_read_u8(_a19_slotarr, _a19_slotarr->offset + (size_t) l17, 173u);
                            l23 = ((uint8_t) t2.payload.i);
                            vader_array_t* _a20_slotarr = ((vader_array_t*) l1);
                            if (_a20_slotarr->buf != NULL && _a20_slotarr->buf->header.forward != NULL) { _a20_slotarr->buf = vader_array_buf_forward(_a20_slotarr->buf); }
                            if ((size_t) l10 >= _a20_slotarr->length) { vader_trap("array index out of bounds"); }
                            t2 = vader_array_read_u8(_a20_slotarr, _a20_slotarr->offset + (size_t) l10, 173u);
                            l24 = ((uint8_t) t2.payload.i);
                            if (l23 == l24) {
                                vader_array_t* _a21_slotarr = ((vader_array_t*) l21);
                                if (_a21_slotarr->buf != NULL && _a21_slotarr->buf->header.forward != NULL) { _a21_slotarr->buf = vader_array_buf_forward(_a21_slotarr->buf); }
                                if ((size_t) l17 >= _a21_slotarr->length) { vader_trap("array index out of bounds"); }
                                t6 = ((int32_t*) _a21_slotarr->buf->slots)[_a21_slotarr->offset + (size_t) l17];
                                l11 = (t6 < l7);
                            } else {
                                l11 = false;
                            }
                            if (l11) {
                                l22 = ((int32_t) (size_t) l17);
                            } else {
                                t1 = (l17 + INT64_C(1));
                                l17 = (size_t) (int64_t) t1;
                                goto loop_257;
                            }
                        } else {
                        }
                    }
                }
                if ((l22 < INT32_C(0))) {
                    t5 = ((vader_array_t*) l20)->length;
                    l22 = ((int32_t) (size_t) t5);
                    vader_array_t* _a22_slotarr = ((vader_array_t*) l1);
                    if (_a22_slotarr->buf != NULL && _a22_slotarr->buf->header.forward != NULL) { _a22_slotarr->buf = vader_array_buf_forward(_a22_slotarr->buf); }
                    if ((size_t) l10 >= _a22_slotarr->length) { vader_trap("array index out of bounds"); }
                    t2 = vader_array_read_u8(_a22_slotarr, _a22_slotarr->offset + (size_t) l10, 173u);
                    l25 = ((uint8_t) t2.payload.i);
                    vader_array_push_u8((vader_array_t*) l20, (int32_t) (uint8_t) l25);
                    vader_array_push_i32((vader_array_t*) l21, l8);
                } else {
                    t1 = ((int64_t) (int32_t) l22);
                    l18 = (size_t) (int64_t) t1;
                    vader_array_t* _a23_slotarr = ((vader_array_t*) l21);
                    if (_a23_slotarr->buf != NULL && _a23_slotarr->buf->header.forward != NULL) { _a23_slotarr->buf = vader_array_buf_forward(_a23_slotarr->buf); }
                    if ((size_t) l18 >= _a23_slotarr->length) { vader_trap("array index out of bounds"); }
                    ((int32_t*) _a23_slotarr->buf->slots)[_a23_slotarr->offset + (size_t) l18] = (int32_t) l8;
                }
                vader_array_t* _a24_slotarr = ((vader_array_t*) l15);
                if (_a24_slotarr->buf != NULL && _a24_slotarr->buf->header.forward != NULL) { _a24_slotarr->buf = vader_array_buf_forward(_a24_slotarr->buf); }
                if ((size_t) l10 >= _a24_slotarr->length) { vader_trap("array index out of bounds"); }
                ((int32_t*) _a24_slotarr->buf->slots)[_a24_slotarr->offset + (size_t) l10] = (int32_t) l22;
                t1 = (l6 + INT64_C(1));
                l6 = (size_t) (int64_t) t1;
                goto loop_231;
            } else {
            }
        }
    }
    l3 = vader_c_emit_rewrite_temps(l3, l15);
    vader_struct_vader_c_emit_CoalesceResult_t* _a25_obj = (vader_struct_vader_c_emit_CoalesceResult_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_CoalesceResult_t));
    vader_obj_header_init(_a25_obj, 660u);
    _a25_obj->f_types = l20;
    _a25_obj->f_body = l3;
    t0 = (void*) _a25_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_string_t vader_c_emit_coerce_expr(void* l0, vader_string_t l1, uint8_t l2, uint8_t l3) {
    bool l4;
    vader_string_t l5 = 0;
    vader_string_t l6 = 0;
    vader_string_t t0 = 0;
    bool t1;
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[4] = { &l1, &l5, &l6, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    if (l2 == l3) {
        { vader_string_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l3 == INT32_C(18)) {
        if (l2 == INT32_C(19)) {
            l4 = true;
        } else {
            l4 = l2 == INT32_C(15);
        }
        if (l4) {
            t0 = concat_2(l1, 421u);
            { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        { vader_string_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l2 == INT32_C(18)) {
        t1 = vader_c_emit_is_ref_val(l3);
        if (t1) {
            t0 = concat_3(2356u, l1, 318u);
            { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        { vader_string_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_c_emit_is_ref_val(l3);
    if (t1) {
        l4 = vader_c_emit_is_ref_val(l2);
    } else {
        l4 = false;
    }
    if (l4) {
        { vader_string_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_c_emit_is_ref_val(l3);
    if (t1) {
        t0 = vader_c_emit_box_expr_unknown(l0, l1, l2);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_c_emit_is_ref_val(l2);
    if (t1) {
        t0 = vader_c_emit_unbox_expr(l1, l3);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l5 = vader_c_emit_c_type_for_val_bare(l3);
    l6 = vader_c_emit_c_type_for_val_bare(l2);
    t0 = concat_6(278u, l5, 320u, l6, 319u, l1);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_string_t vader_c_emit_coerce_operand(void* l0, vader_string_t l1, uint8_t l2, uint8_t l3) {
    bool t0;
    vader_string_t t1 = 0;
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[2] = { &l1, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = vader_c_emit_is_ref_val(l2);
    if (t0) {
        t1 = vader_c_emit_coerce_expr(l0, l1, l2, l3);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_string_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static int32_t vader_c_emit_comptime_atom_count(void* l0) {
    size_t t0;
    t0 = ((vader_array_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_atom_table)->length;
    return ((int32_t) (size_t) t0);
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
    size_t t0;
    vader_box_t t1 = vader_box_null();
    vader_string_t t2 = 0;
    int64_t t3;
    vader_box_t* gc_roots[2] = { &l10, &t1 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l6, &l7 };
    vader_string_t* gc_atom_roots[3] = { &l8, &l9, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) l1)->length;
    if (t0 == INT64_C(0)) {
        vader_array_t* _a0_arr = vader_array_new(9u, 0u, 7u, 170u);
        l2 = (void*) _a0_arr;
        l3 = INT32_C(1);
        l4 = ((vader_array_t*) l0)->length;
        l5 = (size_t) (int64_t) INT64_C(0);
        {
            loop_15: {
                if ((l5 < l4)) {
                    vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
                    if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                    if ((size_t) l5 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                    t1 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l5];
                    t2 = t1.payload.s;
                    if (t2 == 0u) {
                        vader_array_push_i32((vader_array_t*) l2, INT32_C(0));
                    } else {
                        vader_array_push_i32((vader_array_t*) l2, l3);
                        l3 = (l3 + INT32_C(1));
                    }
                    t3 = (l5 + INT64_C(1));
                    l5 = (size_t) (int64_t) t3;
                    goto loop_15;
                } else {
                }
            }
        }
        { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a2_arr = vader_array_new(8u, 0u, 0u, 167u);
    l2 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(9u, 0u, 7u, 170u);
    l6 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_new(9u, 0u, 7u, 170u);
    l7 = (void*) _a4_arr;
    vader_struct_std_collections_MutableMap__string__i32_t* _a5_obj = (vader_struct_std_collections_MutableMap__string__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__i32_t));
    vader_obj_header_init(_a5_obj, 358u);
    _a5_obj->f_ekeys = l2;
    _a5_obj->f_evals = l6;
    _a5_obj->f_index = l7;
    _a5_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a5_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a5_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l2 = (void*) _a5_obj;
    l4 = ((vader_array_t*) l1)->length;
    l5 = (size_t) (int64_t) INT64_C(0);
    {
        loop_71: {
            if ((l5 < l4)) {
                vader_array_t* _a6_slotarr = ((vader_array_t*) l1);
                if (_a6_slotarr->buf != NULL && _a6_slotarr->buf->header.forward != NULL) { _a6_slotarr->buf = vader_array_buf_forward(_a6_slotarr->buf); }
                if ((size_t) l5 >= _a6_slotarr->length) { vader_trap("array index out of bounds"); }
                t1 = vader_array_box_slots(_a6_slotarr->buf)[_a6_slotarr->offset + (size_t) l5];
                l8 = t1.payload.s;
                t1 = std_collections_get__string__i32(l2, l8);
                if (t1.tag == 0u) {
                    vader_array_t* _a7_slotarr = ((vader_array_t*) l1);
                    if (_a7_slotarr->buf != NULL && _a7_slotarr->buf->header.forward != NULL) { _a7_slotarr->buf = vader_array_buf_forward(_a7_slotarr->buf); }
                    if ((size_t) l5 >= _a7_slotarr->length) { vader_trap("array index out of bounds"); }
                    t1 = vader_array_box_slots(_a7_slotarr->buf)[_a7_slotarr->offset + (size_t) l5];
                    l9 = t1.payload.s;
                    l3 = (((int32_t) (size_t) l5) + INT32_C(1));
                    std_collections_put__string__i32(l2, l9, l3);
                } else {
                }
                t3 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t3;
                goto loop_71;
            } else {
            }
        }
    }
    vader_array_t* _a8_arr = vader_array_new(9u, 0u, 7u, 170u);
    l6 = (void*) _a8_arr;
    l4 = ((vader_array_t*) l0)->length;
    l5 = (size_t) (int64_t) INT64_C(0);
    {
        loop_119: {
            if ((l5 < l4)) {
                vader_array_t* _a9_slotarr = ((vader_array_t*) l0);
                if (_a9_slotarr->buf != NULL && _a9_slotarr->buf->header.forward != NULL) { _a9_slotarr->buf = vader_array_buf_forward(_a9_slotarr->buf); }
                if ((size_t) l5 >= _a9_slotarr->length) { vader_trap("array index out of bounds"); }
                t1 = vader_array_box_slots(_a9_slotarr->buf)[_a9_slotarr->offset + (size_t) l5];
                t2 = t1.payload.s;
                if (t2 == 0u) {
                    vader_array_push_i32((vader_array_t*) l6, INT32_C(0));
                } else {
                    vader_array_t* _a10_slotarr = ((vader_array_t*) l0);
                    if (_a10_slotarr->buf != NULL && _a10_slotarr->buf->header.forward != NULL) { _a10_slotarr->buf = vader_array_buf_forward(_a10_slotarr->buf); }
                    if ((size_t) l5 >= _a10_slotarr->length) { vader_trap("array index out of bounds"); }
                    t1 = vader_array_box_slots(_a10_slotarr->buf)[_a10_slotarr->offset + (size_t) l5];
                    l8 = t1.payload.s;
                    l10 = std_collections_get__string__i32(l2, l8);
                    if (l10.tag == 0u) {
                        l3 = INT32_C(0);
                    } else {
                        l3 = ((int32_t) l10.payload.i);
                    }
                    vader_array_push_i32((vader_array_t*) l6, l3);
                }
                t3 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t3;
                goto loop_119;
            } else {
            }
        }
    }
    { void* __vret = l6; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
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
    vader_array_t* _a0_arr = vader_array_new(9u, 0u, 7u, 170u);
    l1 = (void*) _a0_arr;
    l2 = ((vader_array_t*) l0)->length;
    l3 = (size_t) (int64_t) INT64_C(0);
    {
        loop_8: {
            if ((l3 < l2)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l3 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l3);
                t1 = vader_c_emit_fn_has_direct_alloc(t0);
                if (t1) {
                    l4 = ((int32_t) (size_t) l3);
                    vader_array_push_i32((vader_array_t*) l1, l4);
                } else {
                }
                t2 = (l3 + INT64_C(1));
                l3 = (size_t) (int64_t) t2;
                goto loop_8;
            } else {
            }
        }
    }
    l5 = true;
    {
        loop_38: {
            if (l5) {
                l5 = false;
                l2 = ((vader_array_t*) l0)->length;
                l3 = (size_t) (int64_t) INT64_C(0);
                {
                    loop_49: {
                        if ((l3 < l2)) {
                            l4 = ((int32_t) (size_t) l3);
                            t1 = std_core____Contains_contains__i32(l1, l4);
                            if (t1) {
                                t2 = (l3 + INT64_C(1));
                                l3 = (size_t) (int64_t) t2;
                                goto loop_49;
                            }
                            vader_array_t* _a2_slotarr = ((vader_array_t*) l0);
                            if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                            if ((size_t) l3 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                            t0 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l3);
                            t1 = vader_c_emit_fn_calls_may_alloc(t0, l1);
                            if (t1) {
                                l6 = ((int32_t) (size_t) l3);
                                vader_array_push_i32((vader_array_t*) l1, l6);
                                l5 = true;
                            } else {
                            }
                            t2 = (l3 + INT64_C(1));
                            l3 = (size_t) (int64_t) t2;
                            goto loop_49;
                        } else {
                        }
                    }
                }
                goto loop_38;
            } else {
            }
        }
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_string_t vader_c_emit_const_lit_c(void* l0, vader_box_t l1) {
    vader_string_t l2 = 0;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l8 = NULL;
    size_t l5, l9;
    uint64_t l6;
    int64_t l7;
    void* t0 = NULL;
    int32_t t1;
    int64_t t2;
    double t3;
    bool t4;
    uint32_t t5;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[5] = { &l0, &l3, &l4, &l8, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    if (l1.tag == 567u) {
        t0 = l1.payload.obj;
        t1 = ((vader_struct_vader_bytecode_I32Const_t*) t0)->f_value;
        l2 = vader_c_emit_i32_lit_c(t1);
        { vader_string_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 587u) {
        t0 = l1.payload.obj;
        t2 = ((vader_struct_vader_bytecode_I64Const_t*) t0)->f_value;
        l2 = vader_c_emit_i64_lit_c(t2);
        { vader_string_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 548u) {
        t0 = l1.payload.obj;
        t3 = ((vader_struct_vader_bytecode_F64Const_t*) t0)->f_value;
        l2 = vader_c_emit_float_lit(t3);
        { vader_string_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 519u) {
        t0 = l1.payload.obj;
        t4 = ((vader_struct_vader_bytecode_BoolConst_t*) t0)->f_value;
        if (t4) {
            l2 = 2164u;
        } else {
            l2 = 1557u;
        }
        { vader_string_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 535u) {
        l3 = l1.payload.obj;
        l4 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(21));
        l5 = (size_t) (int64_t) INT64_C(0);
        t5 = ((vader_struct_vader_bytecode_CharConst_t*) l3)->f_value;
        t2 = ((int64_t) (uint32_t) ((int32_t) (uint32_t) t5));
        l6 = (uint64_t) (int64_t) t2;
        l5 = std_core_write_unsigned(l4, l5, l6);
        l5 = std_core_write_string_at(l4, l5, 2198u);
        l2 = std_core_finish_buffer(l4, l5);
        { vader_string_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 618u) {
        l3 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(42));
        l5 = (size_t) (int64_t) INT64_C(0);
        l5 = std_core_write_string_at(l3, l5, 2324u);
        t1 = ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_null_tag;
        l7 = ((int64_t) (int32_t) t1);
        l5 = std_core_write_int(l3, l5, l7);
        l5 = std_core_write_string_at(l3, l5, 2224u);
        l2 = std_core_finish_buffer(l3, l5);
        { vader_string_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 633u) {
        l3 = l1.payload.obj;
        l4 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(21));
        l5 = (size_t) (int64_t) INT64_C(0);
        l8 = ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_atom_ids;
        t1 = ((vader_struct_vader_bytecode_StringConst_t*) l3)->f_index;
        t2 = ((int64_t) (int32_t) t1);
        l9 = (size_t) (int64_t) t2;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l8);
        if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
        if ((size_t) l9 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
        t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l9];
        l7 = ((int64_t) (int32_t) t1);
        l5 = std_core_write_int(l4, l5, l7);
        l5 = std_core_write_string_at(l4, l5, 2198u);
        l2 = std_core_finish_buffer(l4, l5);
        { vader_string_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_unreachable("unreachable return in vader_c_emit$const_lit_c");
    vader_gc_top = gc_frame.prev;
}

static uint8_t vader_c_emit_const_val(vader_box_t l0) {
    if (l0.tag == 567u) {
        return (uint8_t) (int32_t) INT32_C(2);
    }
    if (l0.tag == 587u) {
        return (uint8_t) (int32_t) INT32_C(3);
    }
    if (l0.tag == 548u) {
        return (uint8_t) (int32_t) INT32_C(11);
    }
    if (l0.tag == 519u) {
        return (uint8_t) (int32_t) INT32_C(12);
    }
    if (l0.tag == 535u) {
        return (uint8_t) (int32_t) INT32_C(13);
    }
    if (l0.tag == 618u) {
        return (uint8_t) (int32_t) INT32_C(19);
    }
    if (l0.tag == 633u) {
        return (uint8_t) (int32_t) INT32_C(14);
    }
    vader_unreachable("unreachable return in vader_c_emit$const_val");
}

static uint8_t vader_c_emit_convert_target_val(uint8_t l0) {
    if (l0 == INT32_C(0)) {
        return (uint8_t) (int32_t) INT32_C(2);
    }
    if (l0 == INT32_C(1)) {
        return (uint8_t) (int32_t) INT32_C(3);
    }
    if (l0 == INT32_C(2)) {
        return (uint8_t) (int32_t) INT32_C(11);
    }
    if (l0 == INT32_C(3)) {
        return (uint8_t) (int32_t) INT32_C(13);
    }
    vader_unreachable("unreachable return in vader_c_emit$convert_target_val");
}

static int32_t vader_c_emit_count_byte(void* l0, size_t l1, uint8_t l2) {
    int32_t l3;
    size_t l4;
    vader_box_t t0;
    uint8_t t1;
    int64_t t2;
    l3 = INT32_C(0);
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_5: {
            if ((l4 < l1)) {
                vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
                if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                if ((size_t) l4 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l4, 173u);
                t1 = ((uint8_t) t0.payload.i);
                if (t1 == l2) {
                    l3 = (l3 + INT32_C(1));
                } else {
                }
                t2 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t2;
                goto loop_5;
            } else {
            }
        }
    }
    return l3;
}

static void* vader_c_emit_count_temp_occurrences(vader_string_t l0, size_t l1) {
    void* l2 = NULL;
    void* l4 = NULL;
    void* l6 = NULL;
    size_t l3, l5, l8, l9;
    bool l7;
    int32_t l10;
    int64_t t0;
    vader_box_t t1 = vader_box_null();
    uint8_t t2;
    bool t3;
    size_t t4;
    int32_t t5;
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[3] = { &l2, &l4, &l6 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(9u, 0u, 7u, 170u);
    l2 = (void*) _a0_arr;
    l3 = (size_t) (int64_t) INT64_C(0);
    {
        loop_5: {
            if ((l3 < l1)) {
                vader_array_push_i32((vader_array_t*) l2, INT32_C(0));
                t0 = (l3 + INT64_C(1));
                l3 = (size_t) (int64_t) t0;
                goto loop_5;
            } else {
            }
        }
    }
    l4 = vader_host_std_core_bytes(l0);
    l3 = ((vader_array_t*) l4)->length;
    l5 = (size_t) (int64_t) INT64_C(0);
    {
        loop_30: {
            if ((l5 < l3)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) l4);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l5 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                t1 = vader_array_read_u8(_a1_slotarr, _a1_slotarr->offset + (size_t) l5, 173u);
                t2 = ((uint8_t) t1.payload.i);
                if (t2 != INT32_C(116)) {
                    t0 = (l5 + INT64_C(1));
                    l5 = (size_t) (int64_t) t0;
                    goto loop_30;
                }
                l6 = vader_c_emit_temp_token_at(l4, l5, l3);
                t3 = ((vader_struct_vader_c_emit_SlotToken_t*) l6)->f_ok;
                if (t3) {
                    t4 = ((vader_struct_vader_c_emit_SlotToken_t*) l6)->f_id;
                    l7 = (t4 < l1);
                } else {
                    l7 = false;
                }
                if (l7) {
                    l8 = ((vader_struct_vader_c_emit_SlotToken_t*) l6)->f_id;
                    l9 = ((vader_struct_vader_c_emit_SlotToken_t*) l6)->f_id;
                    vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
                    if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                    if ((size_t) l9 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                    t5 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l9];
                    l10 = (t5 + INT32_C(1));
                    if ((size_t) l8 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                    ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l8] = (int32_t) l10;
                } else {
                }
                l5 = ((vader_struct_vader_c_emit_SlotToken_t*) l6)->f_end;
                goto loop_30;
            } else {
            }
        }
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
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
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 6u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(9u, 0u, 7u, 170u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(6u, 0u, 12u, 165u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 170u);
    l3 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__i32__bool_t* _a3_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
    vader_obj_header_init(_a3_obj, 309u);
    _a3_obj->f_ekeys = l1;
    _a3_obj->f_evals = l2;
    _a3_obj->f_index = l3;
    _a3_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    t0 = (void*) _a3_obj;
    vader_struct_std_collections_MutableSet__i32_t* _a4_obj = (vader_struct_std_collections_MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i32_t));
    vader_obj_header_init(_a4_obj, 376u);
    _a4_obj->f_inner = t0;
    l1 = (void*) _a4_obj;
    l2 = ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_imports;
    l4 = ((vader_array_t*) l2)->length;
    l5 = (size_t) (int64_t) INT64_C(0);
    {
        loop_22: {
            if ((l5 < l4)) {
                vader_array_t* _a5_slotarr = ((vader_array_t*) l2);
                if (_a5_slotarr->buf != NULL && _a5_slotarr->buf->header.forward != NULL) { _a5_slotarr->buf = vader_array_buf_forward(_a5_slotarr->buf); }
                if ((size_t) l5 >= _a5_slotarr->length) { vader_trap("array index out of bounds"); }
                l3 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l5);
                t1 = ((vader_struct_vader_bytecode_BcImport_t*) l3)->f_is_extern;
                if (!(t1)) {
                    t2 = (l5 + INT64_C(1));
                    l5 = (size_t) (int64_t) t2;
                    goto loop_22;
                }
                l6 = ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcImport_t*) l3)->f_signature)->f_param_types;
                l7 = ((vader_array_t*) l6)->length;
                l8 = (size_t) (int64_t) INT64_C(0);
                {
                    loop_49: {
                        if ((l8 < l7)) {
                            vader_array_t* _a6_slotarr = ((vader_array_t*) l6);
                            if (_a6_slotarr->buf != NULL && _a6_slotarr->buf->header.forward != NULL) { _a6_slotarr->buf = vader_array_buf_forward(_a6_slotarr->buf); }
                            if ((size_t) l8 >= _a6_slotarr->length) { vader_trap("array index out of bounds"); }
                            l9 = ((int32_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l8];
                            t3 = vader_c_emit_mirrored_c_struct(((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_types, l9);
                            if (t3 != 0u) {
                                std_collections_add__i32(l1, l9);
                            } else {
                            }
                            t2 = (l8 + INT64_C(1));
                            l8 = (size_t) (int64_t) t2;
                            goto loop_49;
                        } else {
                        }
                    }
                }
                t2 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t2;
                goto loop_22;
            } else {
            }
        }
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static bool vader_c_emit_data_entry_mutable(vader_box_t l0) {
    void* t0;
    bool t1;
    if (l0.tag == 504u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_bytecode_BcPrimData_t*) t0)->f_mutable;
        return t1;
    }
    if (l0.tag == 508u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_bytecode_BcStrData_t*) t0)->f_mutable;
        return t1;
    }
    if (l0.tag == 495u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_bytecode_BcAggregateData_t*) t0)->f_mutable;
        return t1;
    }
    vader_unreachable("unreachable return in vader_c_emit$data_entry_mutable");
}

static void* vader_c_emit_data_pool_type_ids(void* l0) {
    void* l1 = NULL;
    void* l3 = NULL;
    void* l5 = NULL;
    void* l9 = NULL;
    size_t l2, l4, l6, l7, l11, l12, l13;
    vader_box_t l8 = vader_box_null();
    bool l10;
    int32_t l14;
    void* t0 = NULL;
    int32_t t1;
    int64_t t2;
    vader_box_t* gc_roots[1] = { &l8 };
    void** gc_raw_roots[6] = { &l0, &l1, &l3, &l5, &l9, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 6u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(9u, 1u, 7u, 170u);
    ((int32_t*) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = (int32_t) INT32_C(0);
    l1 = (void*) _a0_arr;
    l2 = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_data_pool)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l1, (size_t) l2);
    l1 = (void*) _a1_arr;
    l3 = ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_functions;
    vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
    if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
    l2 = ((vader_array_t*) l3)->length;
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_17: {
            if ((l4 < l2)) {
                if ((size_t) l4 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
                l5 = ((vader_struct_vader_bytecode_BcFunction_t*) t0)->f_body;
                vader_array_t* _a3_slotarr = ((vader_array_t*) l5);
                if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                l6 = ((vader_array_t*) l5)->length;
                l7 = (size_t) (int64_t) INT64_C(0);
                {
                    loop_32: {
                        if ((l7 < l6)) {
                            if ((size_t) l7 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                            l8 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l7);
                            if (l8.tag == 537u) {
                                l9 = l8.payload.obj;
                                t1 = ((vader_struct_vader_bytecode_DataConst_t*) l9)->f_pool_index;
                                if ((t1 >= INT32_C(0))) {
                                    t1 = ((vader_struct_vader_bytecode_DataConst_t*) l9)->f_pool_index;
                                    t2 = ((int64_t) (int32_t) t1);
                                    l11 = (size_t) (int64_t) t2;
                                    l12 = ((vader_array_t*) l1)->length;
                                    l10 = (l11 < l12);
                                } else {
                                    l10 = false;
                                }
                                if (l10) {
                                    t1 = ((vader_struct_vader_bytecode_DataConst_t*) l9)->f_pool_index;
                                    t2 = ((int64_t) (int32_t) t1);
                                    l13 = (size_t) (int64_t) t2;
                                    l14 = ((vader_struct_vader_bytecode_DataConst_t*) l9)->f_type_id;
                                    vader_array_t* _a4_slotarr = ((vader_array_t*) l1);
                                    if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                                    if ((size_t) l13 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                                    ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l13] = (int32_t) l14;
                                } else {
                                }
                            } else {
                            }
                            t2 = (l7 + INT64_C(1));
                            l7 = (size_t) (int64_t) t2;
                            goto loop_32;
                        } else {
                        }
                    }
                }
                t2 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t2;
                goto loop_17;
            } else {
            }
        }
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_string_t vader_c_emit_data_slot_c(uint8_t l0, uint64_t l1, vader_string_t l2) {
    vader_string_t l3 = 0;
    size_t l4;
    void* l5 = NULL;
    double t0;
    vader_string_t t1 = 0;
    float t2;
    void** gc_raw_roots[1] = { &l5 };
    vader_string_t* gc_atom_roots[3] = { &l2, &l3, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    if (l0 == INT32_C(10)) {
        t0 = std_core_u64_BitsFloat_from_bits_vt(l1);
        l3 = vader_c_emit_float_lit(t0);
        t1 = concat_4(278u, l2, 319u, l3);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(9)) {
        t2 = std_core_u32_Bits32Float_from_bits_vt((uint32_t) (int32_t) ((int32_t) (uint64_t) l1));
        l3 = vader_c_emit_float_lit(((double) (float) t2));
        t1 = concat_4(278u, l2, 319u, l3);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = l2;
    l4 = vader_host_std_core_byte_len(l3);
    l5 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(33) + l4));
    l4 = (size_t) (int64_t) INT64_C(0);
    l4 = std_core_write_string_at(l5, l4, 278u);
    l4 = std_core_write_string_at(l5, l4, l3);
    l4 = std_core_write_string_at(l5, l4, 325u);
    l4 = std_core_write_unsigned(l5, l4, l1);
    l4 = std_core_write_string_at(l5, l4, 318u);
    t1 = std_core_finish_buffer(l5, l4);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_string_t vader_c_emit_dispatcher_formal(void* l0) {
    void* l1 = NULL;
    void* l4 = NULL;
    int32_t l2, l3;
    size_t l5;
    int64_t l6;
    vader_string_t l7 = 0;
    void* t0 = NULL;
    size_t t1;
    vader_string_t t2 = 0;
    void** gc_raw_roots[4] = { &l0, &l1, &l4, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l7, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 167u);
    t0 = (void*) _a0_arr;
    vader_struct_std_string_builder_StringBuilder_t* _a1_obj = (vader_struct_std_string_builder_StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string_builder_StringBuilder_t));
    vader_obj_header_init(_a1_obj, 389u);
    _a1_obj->f_parts = t0;
    l1 = (void*) _a1_obj;
    std_string_builder_append(l1, 2329u);
    t1 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) l0)->f_params)->length;
    l2 = (((int32_t) (size_t) t1) - INT32_C(1));
    l3 = INT32_C(0);
    {
        loop_14: {
            if ((l3 < l2)) {
                l4 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(35));
                l5 = (size_t) (int64_t) INT64_C(0);
                l5 = std_core_write_string_at(l4, l5, 380u);
                l6 = ((int64_t) (int32_t) l3);
                l5 = std_core_write_int(l4, l5, l6);
                l7 = std_core_finish_buffer(l4, l5);
                std_string_builder_append(l1, l7);
                l3 = (l3 + INT32_C(1));
                goto loop_14;
            } else {
            }
        }
    }
    t2 = std_string_builder_StringBuilder_Display_to_string(l1);
    { vader_string_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_string_t vader_c_emit_dispatcher_result(void* l0, vader_string_t l1, uint8_t l2, uint8_t l3) {
    bool l4;
    vader_string_t t0 = 0;
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[2] = { &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    if (l2 == INT32_C(19)) {
        l4 = true;
    } else {
        l4 = l2 == INT32_C(18);
    }
    if (l4) {
        l4 = true;
    } else {
        l4 = l2 == INT32_C(16);
    }
    if (l3 == INT32_C(19)) {
        l4 = !(l4);
    } else {
        l4 = false;
    }
    if (l4) {
        t0 = vader_c_emit_coerce_expr(l0, l1, l2, (uint8_t) (int32_t) INT32_C(19));
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_string_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_box_t vader_c_emit_div_mod_helper(vader_string_t l0, uint8_t l1) {
    bool l2;
    vader_box_t l3 = vader_box_null();
    vader_string_t l4 = 0;
    vader_string_t l5 = 0;
    vader_string_t t0 = 0;
    vader_box_t* gc_roots[1] = { &l3 };
    vader_string_t* gc_atom_roots[4] = { &l0, &l4, &l5, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 0u, gc_roots, NULL, 0u, NULL, 4u, gc_atom_roots };
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
        if (l0 == 430u) {
            l4 = 1446u;
        } else {
            l4 = 1873u;
        }
        l5 = vader_bytecode_val_type_name(l1);
        t0 = concat_4(2297u, l4, 863u, l5);
        l3 = vader_box_string(167u, t0);
    } else {
        l3 = vader_box_obj(0u, NULL);
    }
    { vader_box_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void vader_c_emit_drop_resolved_for_local(void* l0, int32_t l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    size_t l7, l8;
    vader_string_t l9 = 0;
    vader_string_t l10 = 0;
    vader_string_t l11 = 0;
    vader_string_t l12 = 0;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    int64_t t2;
    bool t3;
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[7] = { &l0, &l2, &l3, &l4, &l5, &l6, &t0 };
    vader_struct___Tuple_string_string_66940ed4_t _a11_storage = {0};
    void* gc_stack_objs[1] = { (void*) &_a11_storage };
    vader_string_t* gc_atom_roots[4] = { &l9, &l10, &l11, &l12 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 7u, gc_roots, gc_raw_roots, 1u, gc_stack_objs, 4u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 167u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(8u, 0u, 0u, 167u);
    l3 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 170u);
    l4 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__string__string_t* _a3_obj = (vader_struct_std_collections_MutableMap__string__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__string_t));
    vader_obj_header_init(_a3_obj, 361u);
    _a3_obj->f_ekeys = l2;
    _a3_obj->f_evals = l3;
    _a3_obj->f_index = l4;
    _a3_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l2 = (void*) _a3_obj;
    vader_array_t* _a4_arr = vader_array_new(8u, 0u, 0u, 167u);
    l3 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_new(6u, 0u, 12u, 165u);
    l4 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(9u, 0u, 7u, 170u);
    l5 = (void*) _a6_arr;
    vader_struct_std_collections_MutableMap__string__bool_t* _a7_obj = (vader_struct_std_collections_MutableMap__string__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__bool_t));
    vader_obj_header_init(_a7_obj, 357u);
    _a7_obj->f_ekeys = l3;
    _a7_obj->f_evals = l4;
    _a7_obj->f_index = l5;
    _a7_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a7_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a7_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    t0 = (void*) _a7_obj;
    vader_struct_std_collections_MutableSet__string_t* _a8_obj = (vader_struct_std_collections_MutableSet__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__string_t));
    vader_obj_header_init(_a8_obj, 378u);
    _a8_obj->f_inner = t0;
    l3 = (void*) _a8_obj;
    l4 = ((vader_struct_vader_c_emit_FnState_t*) l0)->f_resolved_arrays;
    l5 = ((vader_struct_std_collections_MutableMap__string__string_t*) l4)->f_ekeys;
    l6 = ((vader_struct_std_collections_MutableMap__string__string_t*) l4)->f_evals;
    l7 = ((vader_struct_std_collections_MutableMap__string__string_t*) l4)->f_size;
    l8 = (size_t) (int64_t) INT64_C(0);
    {
        loop_41: {
            if ((l8 >= l7)) {
            } else {
                vader_array_t* _a9_slotarr = ((vader_array_t*) l5);
                if (_a9_slotarr->buf != NULL && _a9_slotarr->buf->header.forward != NULL) { _a9_slotarr->buf = vader_array_buf_forward(_a9_slotarr->buf); }
                if ((size_t) l8 >= _a9_slotarr->length) { vader_trap("array index out of bounds"); }
                t1 = vader_array_box_slots(_a9_slotarr->buf)[_a9_slotarr->offset + (size_t) l8];
                l9 = t1.payload.s;
                vader_array_t* _a10_slotarr = ((vader_array_t*) l6);
                if (_a10_slotarr->buf != NULL && _a10_slotarr->buf->header.forward != NULL) { _a10_slotarr->buf = vader_array_buf_forward(_a10_slotarr->buf); }
                if ((size_t) l8 >= _a10_slotarr->length) { vader_trap("array index out of bounds"); }
                t1 = vader_array_box_slots(_a10_slotarr->buf)[_a10_slotarr->offset + (size_t) l8];
                l10 = t1.payload.s;
                vader_struct___Tuple_string_string_66940ed4_t* _a12_obj = &_a11_storage;
                vader_obj_header_init(_a12_obj, 236u);
                _a12_obj->f__0 = l9;
                _a12_obj->f__1 = l10;
                l4 = (void*) _a12_obj;
                l11 = ((vader_struct___Tuple_string_string_66940ed4_t*) l4)->f__0;
                l12 = ((vader_struct___Tuple_string_string_66940ed4_t*) l4)->f__1;
                t2 = (l8 + INT64_C(1));
                l8 = (size_t) (int64_t) t2;
                t3 = vader_c_emit_key_mentions_local(l11, l1);
                if (!(t3)) {
                    std_collections_put__string__string(l2, l11, l12);
                    t3 = std_collections_contains_key__string__bool(((vader_struct_std_collections_MutableSet__string_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_pinned_resolves)->f_inner, l11);
                    if (t3) {
                        std_collections_add__string(l3, l11);
                    } else {
                    }
                } else {
                }
                goto loop_41;
            }
        }
    }
    ((vader_struct_vader_c_emit_FnState_t*) l0)->f_resolved_arrays = l2;
    VADER_WRITE_BARRIER((vader_struct_vader_c_emit_FnState_t*) l0);
    ((vader_struct_vader_c_emit_FnState_t*) l0)->f_pinned_resolves = l3;
    VADER_WRITE_BARRIER((vader_struct_vader_c_emit_FnState_t*) l0);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
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
    vader_gc_top = gc_frame.prev;
}

static uint8_t vader_c_emit_element_storage_kind(void* l0) {
    size_t t0;
    vader_box_t t1;
    void* t2;
    t0 = ((vader_array_t*) l0)->length;
    if (t0 == INT64_C(0)) {
        return (uint8_t) (int32_t) INT32_C(0);
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    if ((size_t) INT32_C(0) >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
    t1 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT32_C(0));
    if (t1.tag == 512u) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
        if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
        if ((size_t) INT32_C(0) >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
        t1 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) INT32_C(0));
        t2 = t1.payload.obj;
        return ((vader_struct_vader_bytecode_BcValPrim_t*) t2)->f_kind;
    }
    return (uint8_t) (int32_t) INT32_C(0);
}

static void vader_c_emit_emit_agg_data_entry(void* l0, size_t l1, void* l2, int32_t l3, int32_t l4, void* l5, void* l6) {
    size_t l7, l10, l13;
    int32_t l8;
    void* l9 = NULL;
    void* l12 = NULL;
    vader_box_t l11 = vader_box_null();
    uint64_t l14, l15;
    vader_string_t l16 = 0;
    vader_string_t l17 = 0;
    int64_t l18;
    int64_t t0;
    bool t1;
    vader_box_t* gc_roots[1] = { &l11 };
    void** gc_raw_roots[6] = { &l0, &l2, &l5, &l6, &l9, &l12 };
    vader_string_t* gc_atom_roots[2] = { &l16, &l17 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l7 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcAggregateData_t*) l2)->f_elements)->length;
    l8 = vader_bytecode_array_kind_index((uint8_t) (int32_t) INT32_C(0));
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 167u);
    l9 = (void*) _a0_arr;
    l10 = (size_t) (int64_t) INT64_C(0);
    {
        loop_11: {
            if ((l10 < l7)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcAggregateData_t*) l2)->f_elements);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l10 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                l11 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l10);
                l12 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(53));
                l13 = (size_t) (int64_t) INT64_C(0);
                l13 = std_core_write_string_at(l12, l13, 2344u);
                t0 = ((int64_t) (size_t) l1);
                l14 = (uint64_t) (int64_t) t0;
                l13 = std_core_write_unsigned(l12, l13, l14);
                l13 = std_core_write_string_at(l12, l13, 904u);
                t0 = ((int64_t) (size_t) l10);
                l15 = (uint64_t) (int64_t) t0;
                l13 = std_core_write_unsigned(l12, l13, l15);
                l16 = std_core_finish_buffer(l12, l13);
                l17 = vader_c_emit_box_slot_c(l6, l0, l11, l16, l4, l5);
                vader_array_push((vader_array_t*) l9, vader_box_string(167u, l17));
                t0 = (l10 + INT64_C(1));
                l10 = (size_t) (int64_t) t0;
                goto loop_11;
            } else {
            }
        }
    }
    t1 = ((vader_struct_vader_c_emit_EmitCtx_t*) l6)->f_split;
    l16 = vader_c_emit_linkage_prefix(t1);
    t1 = ((vader_struct_vader_bytecode_BcAggregateData_t*) l2)->f_mutable;
    l17 = vader_c_emit_storage_qualifier(t1);
    l16 = concat_2(l16, l17);
    l17 = l16;
    l10 = vader_host_std_core_byte_len(l17);
    l12 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(212) + l10));
    l10 = (size_t) (int64_t) INT64_C(0);
    l10 = std_core_write_string_at(l12, l10, l17);
    l10 = std_core_write_string_at(l12, l10, 2114u);
    t0 = ((int64_t) (size_t) l7);
    l14 = (uint64_t) (int64_t) t0;
    l10 = std_core_write_unsigned(l12, l10, l14);
    l10 = std_core_write_string_at(l12, l10, 861u);
    t0 = ((int64_t) (size_t) l1);
    l14 = (uint64_t) (int64_t) t0;
    l10 = std_core_write_unsigned(l12, l10, l14);
    l10 = std_core_write_string_at(l12, l10, 902u);
    l17 = std_core_finish_buffer(l12, l10);
    std_string_builder_append(l0, l17);
    l12 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(162));
    l10 = (size_t) (int64_t) INT64_C(0);
    l10 = std_core_write_string_at(l12, l10, 40u);
    t0 = ((int64_t) (size_t) l7);
    l14 = (uint64_t) (int64_t) t0;
    l10 = std_core_write_unsigned(l12, l10, l14);
    l10 = std_core_write_string_at(l12, l10, 2209u);
    t0 = ((int64_t) (size_t) l7);
    l14 = (uint64_t) (int64_t) t0;
    l10 = std_core_write_unsigned(l12, l10, l14);
    l10 = std_core_write_string_at(l12, l10, 2209u);
    l18 = ((int64_t) (int32_t) l4);
    l10 = std_core_write_int(l12, l10, l18);
    l10 = std_core_write_string_at(l12, l10, 2209u);
    l18 = ((int64_t) (int32_t) l8);
    l10 = std_core_write_int(l12, l10, l18);
    l10 = std_core_write_string_at(l12, l10, 2228u);
    l17 = std_core_finish_buffer(l12, l10);
    std_string_builder_append(l0, l17);
    l17 = vader_c_emit_join_commas(l9);
    l17 = concat_3(38u, l17, 202u);
    std_string_builder_append(l0, l17);
    std_string_builder_append(l0, 2429u);
    l10 = vader_host_std_core_byte_len(l16);
    l9 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(206) + l10));
    l10 = (size_t) (int64_t) INT64_C(0);
    l10 = std_core_write_string_at(l9, l10, l16);
    l10 = std_core_write_string_at(l9, l10, 2316u);
    t0 = ((int64_t) (size_t) l1);
    l14 = (uint64_t) (int64_t) t0;
    l10 = std_core_write_unsigned(l9, l10, l14);
    l10 = std_core_write_string_at(l9, l10, 87u);
    l18 = ((int64_t) (int32_t) l3);
    l10 = std_core_write_int(l9, l10, l18);
    l10 = std_core_write_string_at(l9, l10, 2220u);
    t0 = ((int64_t) (size_t) l7);
    l14 = (uint64_t) (int64_t) t0;
    l10 = std_core_write_unsigned(l9, l10, l14);
    l10 = std_core_write_string_at(l9, l10, 2209u);
    t0 = ((int64_t) (size_t) l7);
    l14 = (uint64_t) (int64_t) t0;
    l10 = std_core_write_unsigned(l9, l10, l14);
    l10 = std_core_write_string_at(l9, l10, 2218u);
    t0 = ((int64_t) (size_t) l1);
    l14 = (uint64_t) (int64_t) t0;
    l10 = std_core_write_unsigned(l9, l10, l14);
    l10 = std_core_write_string_at(l9, l10, 903u);
    l16 = std_core_finish_buffer(l9, l10);
    std_string_builder_append(l0, l16);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_c_emit_emit_array_clear(void* l0) {
    vader_string_t l1 = 0;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = vader_c_emit_pop(l0);
    l1 = vader_c_emit_obj_ptr_of(t0);
    l1 = concat_3(2299u, l1, 349u);
    vader_c_emit_line(l0, l1);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_c_emit_emit_array_copy(void* l0) {
    vader_box_t l1 = vader_box_null(), l2 = vader_box_null(), l3 = vader_box_null(), l4 = vader_box_null();
    vader_string_t l5 = 0;
    vader_string_t l6 = 0;
    vader_string_t l7 = 0;
    vader_string_t l8 = 0;
    vader_string_t l9 = 0;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[5] = { &l1, &l2, &l3, &l4, &t0 };
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[5] = { &l5, &l6, &l7, &l8, &l9 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 5u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 5u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l1 = vader_c_emit_pop(l0);
    l2 = vader_c_emit_pop(l0);
    l3 = vader_c_emit_pop(l0);
    l4 = vader_c_emit_pop(l0);
    t0 = vader_c_emit_pop(l0);
    l5 = vader_c_emit_obj_ptr_of(t0);
    l6 = vader_c_emit_name_of(l4);
    l7 = vader_c_emit_obj_ptr_of(l3);
    l8 = vader_c_emit_name_of(l2);
    l9 = vader_c_emit_name_of(l1);
    l5 = concat_11(2300u, l5, 369u, l6, 370u, l7, 369u, l8, 369u, l9, 349u);
    vader_c_emit_line(l0, l5);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_c_emit_emit_array_get(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l3 = vader_box_null(), l7 = vader_box_null(), l9 = vader_box_null();
    void* l4 = NULL;
    int32_t l5;
    size_t l6, l17;
    uint8_t l8, l12;
    bool l10;
    vader_string_t l11 = 0;
    vader_string_t l13 = 0;
    vader_string_t l14 = 0;
    vader_string_t l15 = 0;
    vader_string_t l16 = 0;
    int64_t l18;
    int64_t t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[4] = { &l2, &l3, &l7, &l9 };
    void** gc_raw_roots[4] = { &l0, &l1, &l4, &t1 };
    vader_string_t* gc_atom_roots[5] = { &l11, &l13, &l14, &l15, &l16 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 5u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = vader_c_emit_pop(l0);
    l3 = vader_c_emit_pop(l0);
    l4 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_ctx)->f_module)->f_types;
    l5 = ((vader_struct_vader_bytecode_ArrayGet_t*) l1)->f_type_id;
    l5 = vader_c_emit_array_element_tag(l4, l5);
    t0 = ((int64_t) (int32_t) l5);
    l6 = (size_t) (int64_t) t0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    if ((size_t) l6 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
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
            l13 = 2313u;
        } else {
            l13 = 2312u;
        }
        l14 = vader_c_emit_fresh_tmp(l0, l12);
        l15 = vader_c_emit_slot_index(l11, l2);
        l13 = concat_8(l14, 61u, l13, 278u, l11, 392u, l15, 349u);
        vader_c_emit_line(l0, l13);
        vader_c_emit_push_tmp(l0, l14, l12);
        { vader_gc_top = gc_frame.prev; return; }
    }
    l13 = vader_c_emit_fresh_tmp(l0, (uint8_t) (int32_t) INT32_C(19));
    if (l9.tag == 0u) {
        l14 = vader_c_emit_slot_index(l11, l2);
        l14 = concat_6(l13, 77u, l11, 391u, l14, 859u);
        vader_c_emit_line(l0, l14);
    } else {
        if (l8 == INT32_C(1)) {
            l14 = l13;
            l15 = l11;
            l16 = vader_c_emit_slot_index(l11, l2);
            l6 = vader_host_std_core_byte_len(l14);
            l17 = vader_host_std_core_byte_len(l15);
            t0 = (l6 + l17);
            l6 = (size_t) (int64_t) t0;
            l17 = vader_host_std_core_byte_len(l16);
            t0 = (l6 + l17);
            l6 = (size_t) (int64_t) t0;
            l4 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(50) + l6));
            l6 = (size_t) (int64_t) INT64_C(0);
            l6 = std_core_write_string_at(l4, l6, l14);
            l6 = std_core_write_string_at(l4, l6, 80u);
            l6 = std_core_write_string_at(l4, l6, l15);
            l6 = std_core_write_string_at(l4, l6, 365u);
            l6 = std_core_write_string_at(l4, l6, l16);
            l6 = std_core_write_string_at(l4, l6, 365u);
            l18 = ((int64_t) (int32_t) l5);
            l6 = std_core_write_int(l4, l6, l18);
            l6 = std_core_write_string_at(l4, l6, 2205u);
            l14 = std_core_finish_buffer(l4, l6);
            vader_c_emit_line(l0, l14);
        } else {
            t1 = l9.payload.obj;
            l14 = ((vader_struct_vader_c_emit_SlotFill_t*) t1)->f_cty;
            l15 = vader_c_emit_slot_index(l11, l2);
            l11 = concat_7(279u, l14, 354u, l11, 394u, l15, 848u);
            t1 = l9.payload.obj;
            l8 = ((vader_struct_vader_c_emit_SlotFill_t*) t1)->f_val;
            l11 = vader_c_emit_box_expr(l11, l8, l5);
            l11 = concat_4(l13, 61u, l11, 494u);
            vader_c_emit_line(l0, l11);
        }
    }
    vader_c_emit_push_tmp(l0, l13, (uint8_t) (int32_t) INT32_C(19));
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_c_emit_emit_array_len(void* l0, bool l1) {
    vader_box_t l2 = vader_box_null();
    vader_string_t l3 = 0;
    vader_string_t l4 = 0;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[2] = { &l3, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = vader_c_emit_pop(l0);
    if (l1) {
        l3 = vader_c_emit_array_hdr_ptr(l2);
        vader_c_emit_resolve_array_local(l0, l3, true);
    } else {
    }
    l3 = vader_c_emit_fresh_tmp(l0, (uint8_t) (int32_t) INT32_C(9));
    l4 = vader_c_emit_array_hdr_ptr(l2);
    l4 = concat_4(l3, 61u, l4, 402u);
    vader_c_emit_line(l0, l4);
    vader_c_emit_push_tmp(l0, l3, (uint8_t) (int32_t) INT32_C(9));
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_c_emit_emit_array_new(void* l0, void* l1) {
    void* l2 = NULL;
    void* l10 = NULL;
    void* l42 = NULL;
    void* l56 = NULL;
    int32_t l3, l6, l7, l14;
    size_t l4, l22, l23, l24, l25, l26, l27, l28, l29, l30, l37, l38, l39, l40, l41, l43, l51, l52, l53, l54, l55, l57;
    uint8_t l5, l15, l16, l33, l49;
    vader_string_t l8 = 0;
    vader_string_t l9 = 0;
    vader_string_t l17 = 0;
    vader_string_t l18 = 0;
    vader_string_t l19 = 0;
    vader_string_t l20 = 0;
    vader_string_t l21 = 0;
    vader_string_t l31 = 0;
    vader_string_t l32 = 0;
    vader_string_t l34 = 0;
    vader_string_t l35 = 0;
    vader_string_t l36 = 0;
    vader_string_t l45 = 0;
    vader_string_t l46 = 0;
    vader_string_t l47 = 0;
    vader_string_t l48 = 0;
    vader_string_t l50 = 0;
    vader_string_t l59 = 0;
    int64_t l11, l44, l58;
    vader_box_t l12 = vader_box_null(), l13 = vader_box_null();
    int64_t t0;
    vader_box_t t1 = vader_box_null();
    int32_t t2;
    void* t3 = NULL;
    vader_box_t* gc_roots[3] = { &l12, &l13, &t1 };
    void** gc_raw_roots[7] = { &l0, &l1, &l2, &l10, &l42, &l56, &t3 };
    vader_string_t* gc_atom_roots[18] = { &l8, &l9, &l17, &l18, &l19, &l20, &l21, &l31, &l32, &l34, &l35, &l36, &l45, &l46, &l47, &l48, &l50, &l59 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 18u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_ctx)->f_module)->f_types;
    l3 = ((vader_struct_vader_bytecode_ArrayNew_t*) l1)->f_type_id;
    l3 = vader_c_emit_array_element_tag(l2, l3);
    t0 = ((int64_t) (int32_t) l3);
    l4 = (size_t) (int64_t) t0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    if ((size_t) l4 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
    t1 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
    l5 = vader_bytecode_array_kind_of(t1, l2);
    l6 = vader_bytecode_array_kind_index(l5);
    l7 = ((vader_struct_vader_bytecode_ArrayNew_t*) l1)->f_length;
    l8 = vader_c_emit_aux(l0, 1191u);
    l9 = l8;
    l4 = vader_host_std_core_byte_len(l9);
    l10 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(126) + l4));
    l4 = (size_t) (int64_t) INT64_C(0);
    l4 = std_core_write_string_at(l10, l4, 2317u);
    l4 = std_core_write_string_at(l10, l4, l9);
    l4 = std_core_write_string_at(l10, l4, 79u);
    t2 = ((vader_struct_vader_bytecode_ArrayNew_t*) l1)->f_type_id;
    l11 = ((int64_t) (int32_t) t2);
    l4 = std_core_write_int(l10, l4, l11);
    l4 = std_core_write_string_at(l10, l4, 2209u);
    l11 = ((int64_t) (int32_t) l7);
    l4 = std_core_write_int(l10, l4, l11);
    l4 = std_core_write_string_at(l10, l4, 2209u);
    l11 = ((int64_t) (int32_t) l6);
    l4 = std_core_write_int(l10, l4, l11);
    l4 = std_core_write_string_at(l10, l4, 2209u);
    l11 = ((int64_t) (int32_t) l3);
    l4 = std_core_write_int(l10, l4, l11);
    l4 = std_core_write_string_at(l10, l4, 2205u);
    l9 = std_core_finish_buffer(l10, l4);
    vader_c_emit_line(l0, l9);
    l12 = vader_c_emit_typed_array_fill_for(l5);
    l6 = INT32_C(0);
    {
        loop_119: {
            if ((l6 < l7)) {
                l13 = vader_c_emit_pop(l0);
                l14 = ((l7 - INT32_C(1)) - l6);
                if (!(l12.tag == 0u)) {
                    l9 = vader_c_emit_name_of(l13);
                    l15 = vader_c_emit_val_of(l13);
                    t3 = l12.payload.obj;
                    l16 = ((vader_struct_vader_c_emit_SlotFill_t*) t3)->f_val;
                    l21 = vader_c_emit_coerce_expr(l2, l9, l15, l16);
                    t3 = l12.payload.obj;
                    l17 = ((vader_struct_vader_c_emit_SlotFill_t*) t3)->f_cty;
                    l18 = l8;
                    l19 = l8;
                    t3 = l12.payload.obj;
                    l20 = ((vader_struct_vader_c_emit_SlotFill_t*) t3)->f_cty;
                    l4 = vader_host_std_core_byte_len(l17);
                    l22 = vader_host_std_core_byte_len(l18);
                    t0 = (l4 + l22);
                    l23 = (size_t) (int64_t) t0;
                    l24 = vader_host_std_core_byte_len(l19);
                    t0 = (l23 + l24);
                    l25 = (size_t) (int64_t) t0;
                    l26 = vader_host_std_core_byte_len(l20);
                    t0 = (l25 + l26);
                    l27 = (size_t) (int64_t) t0;
                    l28 = vader_host_std_core_byte_len(l21);
                    t0 = (l27 + l28);
                    l29 = (size_t) (int64_t) t0;
                    l10 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(59) + l29));
                    l30 = (size_t) (int64_t) INT64_C(0);
                    l30 = std_core_write_string_at(l10, l30, 279u);
                    l30 = std_core_write_string_at(l10, l30, l17);
                    l30 = std_core_write_string_at(l10, l30, 354u);
                    l30 = std_core_write_string_at(l10, l30, l18);
                    l30 = std_core_write_string_at(l10, l30, 394u);
                    l30 = std_core_write_string_at(l10, l30, l19);
                    l30 = std_core_write_string_at(l10, l30, 403u);
                    l11 = ((int64_t) (int32_t) l14);
                    l30 = std_core_write_int(l10, l30, l11);
                    l30 = std_core_write_string_at(l10, l30, 2253u);
                    l30 = std_core_write_string_at(l10, l30, l20);
                    l30 = std_core_write_string_at(l10, l30, 319u);
                    l30 = std_core_write_string_at(l10, l30, l21);
                    l30 = std_core_write_string_at(l10, l30, 494u);
                    l31 = std_core_finish_buffer(l10, l30);
                    vader_c_emit_line(l0, l31);
                } else {
                    if (l5 == INT32_C(13)) {
                        l32 = vader_c_emit_name_of(l13);
                        l33 = vader_c_emit_val_of(l13);
                        l36 = vader_c_emit_coerce_expr(l2, l32, l33, (uint8_t) (int32_t) INT32_C(18));
                        l34 = l8;
                        l35 = l8;
                        l37 = vader_host_std_core_byte_len(l34);
                        l38 = vader_host_std_core_byte_len(l35);
                        t0 = (l37 + l38);
                        l39 = (size_t) (int64_t) t0;
                        l40 = vader_host_std_core_byte_len(l36);
                        t0 = (l39 + l40);
                        l41 = (size_t) (int64_t) t0;
                        l42 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(61) + l41));
                        l43 = (size_t) (int64_t) INT64_C(0);
                        l43 = std_core_write_string_at(l42, l43, 300u);
                        l43 = std_core_write_string_at(l42, l43, l34);
                        l43 = std_core_write_string_at(l42, l43, 394u);
                        l43 = std_core_write_string_at(l42, l43, l35);
                        l43 = std_core_write_string_at(l42, l43, 403u);
                        l44 = ((int64_t) (int32_t) l14);
                        l43 = std_core_write_int(l42, l43, l44);
                        l43 = std_core_write_string_at(l42, l43, 2252u);
                        l43 = std_core_write_string_at(l42, l43, l36);
                        l43 = std_core_write_string_at(l42, l43, 494u);
                        l45 = std_core_finish_buffer(l42, l43);
                        vader_c_emit_line(l0, l45);
                    } else {
                        l46 = l8;
                        l47 = l8;
                        l48 = vader_c_emit_name_of(l13);
                        l49 = vader_c_emit_val_of(l13);
                        l50 = vader_c_emit_box_expr(l48, l49, l3);
                        l51 = vader_host_std_core_byte_len(l46);
                        l52 = vader_host_std_core_byte_len(l47);
                        t0 = (l51 + l52);
                        l53 = (size_t) (int64_t) t0;
                        l54 = vader_host_std_core_byte_len(l50);
                        t0 = (l53 + l54);
                        l55 = (size_t) (int64_t) t0;
                        l56 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(66) + l55));
                        l57 = (size_t) (int64_t) INT64_C(0);
                        l57 = std_core_write_string_at(l56, l57, 2298u);
                        l57 = std_core_write_string_at(l56, l57, l46);
                        l57 = std_core_write_string_at(l56, l57, 391u);
                        l57 = std_core_write_string_at(l56, l57, l47);
                        l57 = std_core_write_string_at(l56, l57, 403u);
                        l58 = ((int64_t) (int32_t) l14);
                        l57 = std_core_write_int(l56, l57, l58);
                        l57 = std_core_write_string_at(l56, l57, 2252u);
                        l57 = std_core_write_string_at(l56, l57, l50);
                        l57 = std_core_write_string_at(l56, l57, 494u);
                        l59 = std_core_finish_buffer(l56, l57);
                        vader_c_emit_line(l0, l59);
                    }
                }
                l6 = (l6 + INT32_C(1));
                goto loop_119;
            } else {
            }
        }
    }
    l9 = vader_c_emit_fresh_tmp(l0, (uint8_t) (int32_t) INT32_C(18));
    l8 = concat_4(l9, 69u, l8, 494u);
    vader_c_emit_line(l0, l8);
    vader_c_emit_push_tmp(l0, l9, (uint8_t) (int32_t) INT32_C(18));
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_c_emit_emit_array_push(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l3 = vader_box_null();
    void* l4 = NULL;
    vader_string_t l5 = 0;
    vader_string_t l9 = 0;
    size_t l6;
    uint8_t l7, l10;
    bool l8;
    int32_t l11;
    int32_t t0;
    int64_t t1;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l2, &l3, &t2 };
    void** gc_raw_roots[3] = { &l0, &l1, &l4 };
    vader_string_t* gc_atom_roots[2] = { &l5, &l9 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = vader_c_emit_pop(l0);
    l3 = vader_c_emit_pop(l0);
    l4 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_ctx)->f_module)->f_types;
    l5 = vader_c_emit_obj_ptr_of(l3);
    t0 = ((vader_struct_vader_bytecode_ArrayPush_t*) l1)->f_type_id;
    t1 = ((int64_t) (int32_t) t0);
    l6 = (size_t) (int64_t) t1;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    if ((size_t) l6 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
    t2 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l6);
    l7 = vader_bytecode_array_kind_of(t2, l4);
    if (l7 == INT32_C(7)) {
        l8 = true;
    } else {
        l8 = l7 == INT32_C(3);
    }
    if (l8) {
        l8 = true;
    } else {
        l8 = l7 == INT32_C(11);
    }
    if (l8) {
        l9 = vader_c_emit_name_of(l2);
        l10 = vader_c_emit_val_of(l2);
        l9 = vader_c_emit_coerce_expr(l4, l9, l10, (uint8_t) (int32_t) INT32_C(2));
        l9 = concat_5(2307u, l5, 365u, l9, 349u);
        vader_c_emit_line(l0, l9);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l7 == INT32_C(8)) {
        l8 = true;
    } else {
        l8 = l7 == INT32_C(4);
    }
    if (l8) {
        l9 = vader_c_emit_name_of(l2);
        l10 = vader_c_emit_val_of(l2);
        l9 = vader_c_emit_coerce_expr(l4, l9, l10, (uint8_t) (int32_t) INT32_C(3));
        l9 = concat_5(2308u, l5, 365u, l9, 349u);
        vader_c_emit_line(l0, l9);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l7 == INT32_C(10)) {
        l9 = vader_c_emit_name_of(l2);
        l10 = vader_c_emit_val_of(l2);
        l9 = vader_c_emit_coerce_expr(l4, l9, l10, (uint8_t) (int32_t) INT32_C(11));
        l9 = concat_5(2305u, l5, 365u, l9, 349u);
        vader_c_emit_line(l0, l9);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l7 == INT32_C(1)) {
        l9 = vader_c_emit_name_of(l2);
        l10 = vader_c_emit_val_of(l2);
        l9 = vader_c_emit_coerce_expr(l4, l9, l10, (uint8_t) (int32_t) INT32_C(2));
        l9 = concat_5(2311u, l5, 365u, l9, 349u);
        vader_c_emit_line(l0, l9);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l7 == INT32_C(5)) {
        l9 = vader_c_emit_name_of(l2);
        l10 = vader_c_emit_val_of(l2);
        l9 = vader_c_emit_coerce_expr(l4, l9, l10, (uint8_t) (int32_t) INT32_C(2));
        l9 = concat_5(2309u, l5, 365u, l9, 349u);
        vader_c_emit_line(l0, l9);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l7 == INT32_C(2)) {
        l9 = vader_c_emit_name_of(l2);
        l10 = vader_c_emit_val_of(l2);
        l9 = vader_c_emit_coerce_expr(l4, l9, l10, (uint8_t) (int32_t) INT32_C(2));
        l9 = concat_5(2310u, l5, 365u, l9, 349u);
        vader_c_emit_line(l0, l9);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l7 == INT32_C(6)) {
        l9 = vader_c_emit_name_of(l2);
        l10 = vader_c_emit_val_of(l2);
        l9 = vader_c_emit_coerce_expr(l4, l9, l10, (uint8_t) (int32_t) INT32_C(2));
        l9 = concat_5(2306u, l5, 365u, l9, 349u);
        vader_c_emit_line(l0, l9);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l7 == INT32_C(9)) {
        l9 = vader_c_emit_name_of(l2);
        l10 = vader_c_emit_val_of(l2);
        l9 = vader_c_emit_coerce_expr(l4, l9, l10, (uint8_t) (int32_t) INT32_C(10));
        l9 = concat_5(2304u, l5, 365u, l9, 349u);
        vader_c_emit_line(l0, l9);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l7 == INT32_C(12)) {
        l9 = vader_c_emit_name_of(l2);
        l10 = vader_c_emit_val_of(l2);
        l9 = vader_c_emit_coerce_expr(l4, l9, l10, (uint8_t) (int32_t) INT32_C(12));
        l9 = concat_5(2303u, l5, 365u, l9, 349u);
        vader_c_emit_line(l0, l9);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l7 == INT32_C(13)) {
        l8 = true;
    } else {
        l8 = l7 == INT32_C(0);
    }
    if (l8) {
        l9 = vader_c_emit_name_of(l2);
        l7 = vader_c_emit_val_of(l2);
        l11 = ((vader_struct_vader_bytecode_ArrayPush_t*) l1)->f_type_id;
        l9 = vader_c_emit_box_expr(l9, l7, l11);
        l5 = concat_5(2301u, l5, 365u, l9, 349u);
        vader_c_emit_line(l0, l5);
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_c_emit_emit_array_push_all(void* l0) {
    vader_box_t l1 = vader_box_null();
    vader_string_t l2 = 0;
    vader_string_t l3 = 0;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l1, &t0 };
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[2] = { &l2, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l1 = vader_c_emit_pop(l0);
    t0 = vader_c_emit_pop(l0);
    l2 = vader_c_emit_obj_ptr_of(t0);
    l3 = vader_c_emit_obj_ptr_of(l1);
    l2 = concat_5(2302u, l2, 370u, l3, 349u);
    vader_c_emit_line(l0, l2);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_c_emit_emit_array_remove_last(void* l0) {
    vader_box_t l1 = vader_box_null();
    vader_string_t l2 = 0;
    vader_string_t l3 = 0;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[2] = { &l2, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l1 = vader_c_emit_pop(l0);
    l2 = vader_c_emit_fresh_tmp(l0, (uint8_t) (int32_t) INT32_C(19));
    l3 = vader_c_emit_obj_ptr_of(l1);
    l3 = concat_4(l2, 81u, l3, 349u);
    vader_c_emit_line(l0, l3);
    vader_c_emit_push_tmp(l0, l2, (uint8_t) (int32_t) INT32_C(19));
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_c_emit_emit_array_repeat(void* l0) {
    vader_box_t l1 = vader_box_null(), l2 = vader_box_null();
    vader_string_t l3 = 0;
    vader_string_t l4 = 0;
    vader_string_t l5 = 0;
    vader_box_t* gc_roots[2] = { &l1, &l2 };
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[3] = { &l3, &l4, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l1 = vader_c_emit_pop(l0);
    l2 = vader_c_emit_pop(l0);
    l3 = vader_c_emit_aux(l0, 1191u);
    l4 = vader_c_emit_obj_ptr_of(l2);
    l5 = vader_c_emit_name_of(l1);
    l4 = concat_7(2317u, l3, 82u, l4, 369u, l5, 349u);
    vader_c_emit_line(l0, l4);
    l4 = vader_c_emit_fresh_tmp(l0, (uint8_t) (int32_t) INT32_C(18));
    l3 = concat_4(l4, 69u, l3, 494u);
    vader_c_emit_line(l0, l3);
    vader_c_emit_push_tmp(l0, l4, (uint8_t) (int32_t) INT32_C(18));
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_c_emit_emit_array_set(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l3 = vader_box_null(), l4 = vader_box_null(), l8 = vader_box_null(), l9 = vader_box_null();
    void* l5 = NULL;
    int32_t l6;
    size_t l7;
    bool l10;
    vader_string_t l11 = 0;
    vader_string_t l12 = 0;
    vader_string_t l14 = 0;
    uint8_t l13;
    int64_t t0;
    uint8_t t1;
    void* t2 = NULL;
    vader_box_t* gc_roots[5] = { &l2, &l3, &l4, &l8, &l9 };
    void** gc_raw_roots[4] = { &l0, &l1, &l5, &t2 };
    vader_string_t* gc_atom_roots[3] = { &l11, &l12, &l14 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 5u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots };
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
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    if ((size_t) l7 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
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
        if (l8.tag == 506u) {
            l5 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_ctx)->f_module)->f_types;
            l12 = vader_c_emit_name_of(l2);
            l13 = vader_c_emit_val_of(l2);
            l12 = vader_c_emit_coerce_expr(l5, l12, l13, (uint8_t) (int32_t) INT32_C(19));
            l14 = vader_c_emit_slot_index(l11, l3);
            l12 = concat_7(2315u, l11, 392u, l14, 365u, l12, 349u);
            vader_c_emit_line(l0, l12);
        } else {
            l12 = vader_c_emit_slot_index(l11, l3);
            l14 = vader_c_emit_obj_ptr_of(l2);
            l12 = concat_7(2314u, l11, 392u, l12, 365u, l14, 349u);
            vader_c_emit_line(l0, l12);
        }
        l12 = concat_3(824u, l11, 389u);
        vader_c_emit_line(l0, l12);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l9.tag == 0u) {
        l12 = vader_c_emit_slot_index(l11, l3);
        l14 = vader_c_emit_name_of(l2);
        l13 = vader_c_emit_val_of(l2);
        l14 = vader_c_emit_box_expr(l14, l13, l6);
        l12 = concat_7(2298u, l11, 391u, l12, 850u, l14, 494u);
        vader_c_emit_line(l0, l12);
        l12 = concat_3(824u, l11, 389u);
        vader_c_emit_line(l0, l12);
    } else {
        t2 = l9.payload.obj;
        l12 = ((vader_struct_vader_c_emit_SlotFill_t*) t2)->f_cty;
        t2 = l9.payload.obj;
        l13 = ((vader_struct_vader_c_emit_SlotFill_t*) t2)->f_val;
        vader_c_emit_emit_typed_slot_write(l0, l11, l3, l2, l12, l13);
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_c_emit_emit_array_slice(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l3 = vader_box_null(), l4 = vader_box_null();
    vader_string_t l5 = 0;
    vader_string_t l6 = 0;
    vader_string_t l7 = 0;
    vader_string_t l8 = 0;
    vader_box_t* gc_roots[3] = { &l2, &l3, &l4 };
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_string_t* gc_atom_roots[4] = { &l5, &l6, &l7, &l8 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = vader_c_emit_pop(l0);
    l3 = vader_c_emit_pop(l0);
    l4 = vader_c_emit_pop(l0);
    l5 = vader_c_emit_aux(l0, 1191u);
    l6 = vader_c_emit_obj_ptr_of(l4);
    l7 = vader_c_emit_name_of(l3);
    l8 = vader_c_emit_name_of(l2);
    l6 = concat_9(2317u, l5, 83u, l6, 369u, l7, 369u, l8, 349u);
    vader_c_emit_line(l0, l6);
    l6 = vader_c_emit_fresh_tmp(l0, (uint8_t) (int32_t) INT32_C(18));
    l5 = concat_4(l6, 69u, l5, 494u);
    vader_c_emit_line(l0, l5);
    vader_c_emit_push_tmp(l0, l6, (uint8_t) (int32_t) INT32_C(18));
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_c_emit_emit_atom_comptime_table(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    int32_t l5, l9, l12;
    size_t l6, l7, l13;
    vader_string_t l8 = 0;
    vader_string_t l10 = 0;
    vader_string_t l11 = 0;
    int64_t l14, l15;
    uint64_t l16;
    vader_box_t t0 = vader_box_null();
    size_t t1;
    int64_t t2;
    bool t3;
    vader_string_t t4 = 0;
    int32_t t5;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &l4 };
    vader_string_t* gc_atom_roots[4] = { &l8, &l10, &l11, &t4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    std_string_builder_append(l1, 431u);
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 167u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(9u, 0u, 7u, 170u);
    l3 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 170u);
    l4 = (void*) _a2_arr;
    l5 = INT32_C(0);
    l6 = ((vader_array_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_atom_table)->length;
    l7 = (size_t) (int64_t) INT64_C(0);
    {
        loop_17: {
            if ((l7 < l6)) {
                vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_atom_table);
                if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                if ((size_t) l7 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_box_slots(_a3_slotarr->buf)[_a3_slotarr->offset + (size_t) l7];
                l8 = t0.payload.s;
                t1 = vader_host_std_core_byte_len(l8);
                l9 = ((int32_t) (size_t) t1);
                l10 = vader_c_emit_c_string_lit(l8);
                l11 = concat_3(7u, l10, 42u);
                vader_array_push((vader_array_t*) l2, vader_box_string(167u, l11));
                vader_array_push_i32((vader_array_t*) l3, l5);
                vader_array_push_i32((vader_array_t*) l4, l9);
                l12 = (l9 + INT32_C(1));
                l5 = (l5 + l12);
                t2 = (l7 + INT64_C(1));
                l7 = (size_t) (int64_t) t2;
                goto loop_17;
            } else {
            }
        }
    }
    t1 = ((vader_array_t*) l3)->length;
    if (t1 == INT64_C(0)) {
        t3 = ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_split;
        t4 = vader_c_emit_linkage_prefix(t3);
        l8 = concat_2(t4, 1410u);
        std_string_builder_append(l1, l8);
        std_string_builder_append(l1, 232u);
        std_string_builder_append(l1, 1u);
        { vader_gc_top = gc_frame.prev; return; }
    }
    t3 = ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_split;
    t4 = vader_c_emit_linkage_prefix(t3);
    l8 = concat_2(t4, 1399u);
    std_string_builder_append(l1, l8);
    l6 = ((vader_array_t*) l2)->length;
    l7 = (size_t) (int64_t) INT64_C(0);
    {
        loop_101: {
            if ((l7 < l6)) {
                vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
                if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                if ((size_t) l7 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_box_slots(_a4_slotarr->buf)[_a4_slotarr->offset + (size_t) l7];
                t4 = t0.payload.s;
                l8 = concat_2(t4, 1u);
                std_string_builder_append(l1, l8);
                t2 = (l7 + INT64_C(1));
                l7 = (size_t) (int64_t) t2;
                goto loop_101;
            } else {
            }
        }
    }
    std_string_builder_append(l1, 495u);
    std_string_builder_append(l1, 1u);
    t3 = ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_split;
    t4 = vader_c_emit_linkage_prefix(t3);
    l8 = concat_2(t4, 1411u);
    std_string_builder_append(l1, l8);
    l6 = ((vader_array_t*) l3)->length;
    l7 = (size_t) (int64_t) INT64_C(0);
    {
        loop_146: {
            if ((l7 < l6)) {
                l2 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(105));
                l13 = (size_t) (int64_t) INT64_C(0);
                l13 = std_core_write_string_at(l2, l13, 39u);
                vader_array_t* _a5_slotarr = ((vader_array_t*) l4);
                if (_a5_slotarr->buf != NULL && _a5_slotarr->buf->header.forward != NULL) { _a5_slotarr->buf = vader_array_buf_forward(_a5_slotarr->buf); }
                if ((size_t) l7 >= _a5_slotarr->length) { vader_trap("array index out of bounds"); }
                t5 = ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l7];
                l14 = ((int64_t) (int32_t) t5);
                l13 = std_core_write_int(l2, l13, l14);
                l13 = std_core_write_string_at(l2, l13, 2225u);
                vader_array_t* _a6_slotarr = ((vader_array_t*) l3);
                if (_a6_slotarr->buf != NULL && _a6_slotarr->buf->header.forward != NULL) { _a6_slotarr->buf = vader_array_buf_forward(_a6_slotarr->buf); }
                if ((size_t) l7 >= _a6_slotarr->length) { vader_trap("array index out of bounds"); }
                t5 = ((int32_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l7];
                l15 = ((int64_t) (int32_t) t5);
                l13 = std_core_write_int(l2, l13, l15);
                l13 = std_core_write_string_at(l2, l13, 858u);
                l8 = std_core_finish_buffer(l2, l13);
                std_string_builder_append(l1, l8);
                t2 = (l7 + INT64_C(1));
                l7 = (size_t) (int64_t) t2;
                goto loop_146;
            } else {
            }
        }
    }
    std_string_builder_append(l1, 2429u);
    std_string_builder_append(l1, 1u);
    l2 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(56));
    l6 = (size_t) (int64_t) INT64_C(0);
    l6 = std_core_write_string_at(l2, l6, 231u);
    t1 = ((vader_array_t*) l3)->length;
    t2 = ((int64_t) (size_t) t1);
    l16 = (uint64_t) (int64_t) t2;
    l6 = std_core_write_unsigned(l2, l6, l16);
    l6 = std_core_write_string_at(l2, l6, 2199u);
    l8 = std_core_finish_buffer(l2, l6);
    std_string_builder_append(l1, l8);
    std_string_builder_append(l1, 1u);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_c_emit_emit_atom_count_define(void* l0, void* l1) {
    void* l2 = NULL;
    size_t l3;
    int64_t l4;
    vader_string_t l5 = 0;
    int32_t t0;
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_string_t* gc_atom_roots[1] = { &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(57));
    l3 = (size_t) (int64_t) INT64_C(0);
    l3 = std_core_write_string_at(l2, l3, 231u);
    t0 = vader_c_emit_comptime_atom_count(l0);
    l4 = ((int64_t) (int32_t) t0);
    l3 = std_core_write_int(l2, l3, l4);
    l3 = std_core_write_string_at(l2, l3, 2200u);
    l5 = std_core_finish_buffer(l2, l3);
    std_string_builder_append(l1, l5);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_c_emit_emit_bits_to_f32(void* l0) {
    vader_box_t l1 = vader_box_null();
    void* l2 = NULL;
    vader_string_t l3 = 0;
    uint8_t l4;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_string_t* gc_atom_roots[1] = { &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l1 = vader_c_emit_pop(l0);
    l2 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_ctx)->f_module)->f_types;
    l3 = vader_c_emit_name_of(l1);
    l4 = vader_c_emit_val_of(l1);
    l3 = vader_c_emit_coerce_operand(l2, l3, l4, (uint8_t) (int32_t) INT32_C(2));
    l3 = concat_3(281u, l3, 336u);
    vader_c_emit_push_expr(l0, (uint8_t) (int32_t) INT32_C(10), l3);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_c_emit_emit_bits_to_f64(void* l0) {
    vader_box_t l1 = vader_box_null();
    void* l2 = NULL;
    vader_string_t l3 = 0;
    uint8_t l4;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_string_t* gc_atom_roots[1] = { &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l1 = vader_c_emit_pop(l0);
    l2 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_ctx)->f_module)->f_types;
    l3 = vader_c_emit_name_of(l1);
    l4 = vader_c_emit_val_of(l1);
    l3 = vader_c_emit_coerce_operand(l2, l3, l4, (uint8_t) (int32_t) INT32_C(3));
    l3 = concat_3(282u, l3, 335u);
    vader_c_emit_push_expr(l0, (uint8_t) (int32_t) INT32_C(11), l3);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_c_emit_emit_box_op(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null();
    vader_string_t l3 = 0;
    uint8_t l4;
    int32_t l5;
    uint8_t t0;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_string_t* gc_atom_roots[1] = { &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = vader_c_emit_pop(l0);
    t0 = vader_c_emit_val_of(l2);
    if (t0 == INT32_C(19)) {
        l3 = vader_c_emit_name_of(l2);
        vader_c_emit_push_into_tmp(l0, l3, (uint8_t) (int32_t) INT32_C(19));
        { vader_gc_top = gc_frame.prev; return; }
    }
    t0 = vader_c_emit_val_of(l2);
    if (t0 == INT32_C(18)) {
        l3 = vader_c_emit_name_of(l2);
        l3 = concat_3(2356u, l3, 318u);
        vader_c_emit_push_into_tmp(l0, l3, (uint8_t) (int32_t) INT32_C(19));
        { vader_gc_top = gc_frame.prev; return; }
    }
    l3 = vader_c_emit_name_of(l2);
    l4 = vader_c_emit_val_of(l2);
    l5 = ((vader_struct_vader_bytecode_Box_t*) l1)->f_type_id;
    l3 = vader_c_emit_box_expr(l3, l4, l5);
    vader_c_emit_push_into_tmp(l0, l3, (uint8_t) (int32_t) INT32_C(19));
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_c_emit_emit_branch(void* l0, int32_t l1, bool l2) {
    int32_t l3;
    vader_box_t l4 = vader_box_null();
    void* l5 = NULL;
    void* l7 = NULL;
    vader_string_t l6 = 0;
    vader_string_t l10 = 0;
    size_t l8;
    int64_t l9;
    bool t0;
    int32_t t1;
    vader_string_t t2 = 0;
    vader_box_t* gc_roots[1] = { &l4 };
    void** gc_raw_roots[3] = { &l0, &l5, &l7 };
    vader_string_t* gc_atom_roots[3] = { &l6, &l10, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_function)->f_jump_table);
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    if ((size_t) l1 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
    l3 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l1];
    l4 = vader_c_emit_branch_target(((vader_struct_vader_c_emit_FnState_t*) l0)->f_scopes, l3);
    if (l4.tag == 667u) {
        l5 = l4.payload.obj;
        t0 = vader_c_emit_is_continue_branch(l5, l3);
        if (t0) {
            l7 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(25));
            l8 = (size_t) (int64_t) INT64_C(0);
            l8 = std_core_write_string_at(l7, l8, 1827u);
            t1 = ((vader_struct_vader_c_emit_ScopeInfo_t*) l5)->f_opener_pc;
            l9 = ((int64_t) (int32_t) t1);
            l8 = std_core_write_int(l7, l8, l9);
            l6 = std_core_finish_buffer(l7, l8);
        } else {
            l7 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(24));
            l8 = (size_t) (int64_t) INT64_C(0);
            l8 = std_core_write_string_at(l7, l8, 1473u);
            t1 = ((vader_struct_vader_c_emit_ScopeInfo_t*) l5)->f_opener_pc;
            l9 = ((int64_t) (int32_t) t1);
            l8 = std_core_write_int(l7, l8, l9);
            l6 = std_core_finish_buffer(l7, l8);
        }
        if (l2) {
            l4 = vader_c_emit_pop(l0);
            l5 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(31));
            l8 = (size_t) (int64_t) INT64_C(0);
            l8 = std_core_write_string_at(l5, l8, 1275u);
            l9 = ((int64_t) (int32_t) l1);
            l8 = std_core_write_int(l5, l8, l9);
            l8 = std_core_write_string_at(l5, l8, 318u);
            l10 = std_core_finish_buffer(l5, l8);
            vader_c_emit_assert_stack_empty(l0, l10);
            l10 = vader_c_emit_name_of(l4);
            l10 = concat_5(1693u, l10, 331u, l6, 494u);
            vader_c_emit_line(l0, l10);
        } else {
            l5 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(28));
            l8 = (size_t) (int64_t) INT64_C(0);
            l8 = std_core_write_string_at(l5, l8, 1273u);
            l9 = ((int64_t) (int32_t) l1);
            l8 = std_core_write_int(l5, l8, l9);
            l8 = std_core_write_string_at(l5, l8, 318u);
            l10 = std_core_finish_buffer(l5, l8);
            vader_c_emit_assert_stack_empty(l0, l10);
            l6 = concat_3(1633u, l6, 494u);
            vader_c_emit_line(l0, l6);
        }
    } else {
        l5 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(91));
        l8 = (size_t) (int64_t) INT64_C(0);
        l8 = std_core_write_string_at(l5, l8, 1466u);
        l9 = ((int64_t) (int32_t) l1);
        l8 = std_core_write_int(l5, l8, l9);
        l8 = std_core_write_string_at(l5, l8, 50u);
        l9 = ((int64_t) (int32_t) l3);
        l8 = std_core_write_int(l5, l8, l9);
        l8 = std_core_write_string_at(l5, l8, 318u);
        t2 = std_core_finish_buffer(l5, l8);
        std_abort_todo(t2);
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_c_emit_emit_buffer_load(void* l0, vader_string_t l1, uint8_t l2) {
    vader_box_t l3 = vader_box_null(), l4 = vader_box_null();
    vader_string_t l5 = 0;
    vader_string_t l6 = 0;
    vader_string_t l7 = 0;
    vader_box_t* gc_roots[2] = { &l3, &l4 };
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[4] = { &l1, &l5, &l6, &l7 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l3 = vader_c_emit_pop(l0);
    l4 = vader_c_emit_pop(l0);
    l5 = vader_c_emit_fresh_tmp(l0, l2);
    l6 = vader_c_emit_buf_ptr(l4);
    l7 = vader_c_emit_name_of(l3);
    l6 = concat_8(l5, 61u, l1, 278u, l6, 369u, l7, 349u);
    vader_c_emit_line(l0, l6);
    vader_c_emit_push_tmp(l0, l5, l2);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_c_emit_emit_buffer_new(void* l0) {
    vader_box_t l1 = vader_box_null();
    vader_string_t l2 = 0;
    vader_string_t l3 = 0;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[2] = { &l2, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l1 = vader_c_emit_pop(l0);
    l2 = vader_c_emit_fresh_tmp(l0, (uint8_t) (int32_t) INT32_C(18));
    l3 = vader_c_emit_name_of(l1);
    l3 = concat_4(l2, 73u, l3, 349u);
    vader_c_emit_line(l0, l3);
    vader_c_emit_push_tmp(l0, l2, (uint8_t) (int32_t) INT32_C(18));
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_c_emit_emit_buffer_store(void* l0, vader_string_t l1, vader_string_t l2) {
    vader_box_t l3 = vader_box_null(), l4 = vader_box_null();
    vader_string_t l5 = 0;
    vader_string_t l6 = 0;
    vader_string_t l7 = 0;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l3, &l4, &t0 };
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[5] = { &l1, &l2, &l5, &l6, &l7 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 5u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l3 = vader_c_emit_pop(l0);
    l4 = vader_c_emit_pop(l0);
    t0 = vader_c_emit_pop(l0);
    l5 = vader_c_emit_buf_ptr(t0);
    l6 = vader_c_emit_name_of(l4);
    l7 = vader_c_emit_name_of(l3);
    l5 = concat_10(l1, 278u, l5, 369u, l6, 365u, l2, 6u, l7, 349u);
    vader_c_emit_line(l0, l5);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_c_emit_emit_buffer_to_string(void* l0) {
    vader_box_t l1 = vader_box_null();
    vader_string_t l2 = 0;
    vader_string_t l3 = 0;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l1, &t0 };
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[2] = { &l2, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l1 = vader_c_emit_pop(l0);
    t0 = vader_c_emit_pop(l0);
    l2 = vader_c_emit_buf_ptr(t0);
    l3 = vader_c_emit_name_of(l1);
    l2 = concat_5(2332u, l2, 369u, l3, 318u);
    vader_c_emit_push_into_tmp(l0, l2, (uint8_t) (int32_t) INT32_C(14));
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_c_emit_emit_buffer_write_string(void* l0) {
    vader_box_t l1 = vader_box_null(), l2 = vader_box_null(), l3 = vader_box_null();
    void* l4 = NULL;
    vader_string_t l5 = 0;
    vader_string_t l7 = 0;
    vader_string_t l8 = 0;
    uint8_t l6;
    vader_box_t* gc_roots[3] = { &l1, &l2, &l3 };
    void** gc_raw_roots[2] = { &l0, &l4 };
    vader_string_t* gc_atom_roots[3] = { &l5, &l7, &l8 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l1 = vader_c_emit_pop(l0);
    l2 = vader_c_emit_pop(l0);
    l3 = vader_c_emit_pop(l0);
    l4 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_ctx)->f_module)->f_types;
    l5 = vader_c_emit_name_of(l1);
    l6 = vader_c_emit_val_of(l1);
    l5 = vader_c_emit_coerce_operand(l4, l5, l6, (uint8_t) (int32_t) INT32_C(14));
    l7 = vader_c_emit_buf_ptr(l3);
    l8 = vader_c_emit_name_of(l2);
    l5 = concat_7(2342u, l7, 369u, l8, 365u, l5, 349u);
    vader_c_emit_line(l0, l5);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

void* vader_c_emit_emit_c_split(void* l0, void* l1, vader_string_t l2) {
    void* l3 = NULL;
    void* l5 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    void* l14 = NULL;
    void* l16 = NULL;
    void* l18 = NULL;
    void* l22 = NULL;
    void* l24 = NULL;
    bool l4;
    vader_string_t l6 = 0;
    vader_string_t l25 = 0;
    vader_string_t l26 = 0;
    size_t l12, l13, l15, l17, l19, l20, l23;
    int32_t l21;
    void* t0 = NULL;
    int64_t t1;
    void** gc_raw_roots[15] = { &l0, &l1, &l3, &l5, &l7, &l8, &l9, &l10, &l11, &l14, &l16, &l18, &l22, &l24, &t0 };
    vader_string_t* gc_atom_roots[4] = { &l2, &l6, &l25, &l26 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 15u, NULL, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l3 = vader_c_emit_partition_functions(((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_functions);
    l4 = ((vader_struct_vader_c_emit_EmitOptions_t*) l1)->f_release;
    l5 = ((vader_struct_vader_c_emit_EmitOptions_t*) l1)->f_atom_universe;
    l6 = ((vader_struct_vader_c_emit_EmitOptions_t*) l1)->f_entry_mangled;
    l7 = vader_c_emit_internal_fn_flags(l0, l3, l6);
    l5 = vader_c_emit_new_ctx(l0, l4, true, l5, l7);
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 167u);
    t0 = (void*) _a0_arr;
    vader_struct_std_string_builder_StringBuilder_t* _a1_obj = (vader_struct_std_string_builder_StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string_builder_StringBuilder_t));
    vader_obj_header_init(_a1_obj, 389u);
    _a1_obj->f_parts = t0;
    l7 = (void*) _a1_obj;
    std_string_builder_append(l7, 434u);
    std_string_builder_append(l7, 235u);
    std_string_builder_append(l7, 237u);
    std_string_builder_append(l7, 238u);
    std_string_builder_append(l7, 239u);
    std_string_builder_append(l7, 1u);
    vader_c_emit_emit_struct_typedefs(l5, l7);
    vader_c_emit_emit_fn_sig_typedefs(l5, l7);
    vader_c_emit_emit_forward_decls(l5, l7);
    vader_c_emit_emit_closure_forward_decls(l5, l7);
    vader_c_emit_emit_vtable_forward_decls(l5, l7);
    vader_array_t* _a2_arr = vader_array_new(8u, 0u, 0u, 167u);
    t0 = (void*) _a2_arr;
    vader_struct_std_string_builder_StringBuilder_t* _a3_obj = (vader_struct_std_string_builder_StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string_builder_StringBuilder_t));
    vader_obj_header_init(_a3_obj, 389u);
    _a3_obj->f_parts = t0;
    l8 = (void*) _a3_obj;
    std_string_builder_append(l8, 433u);
    std_string_builder_append(l8, 236u);
    vader_c_emit_emit_import_shims(l5, l8);
    l6 = vader_c_emit_imports_header_name(l2);
    l6 = concat_3(234u, l6, 224u);
    std_string_builder_append(l7, l6);
    vader_c_emit_emit_atom_count_define(l5, l7);
    vader_c_emit_emit_data_global_externs(l5, l7);
    vader_array_t* _a4_arr = vader_array_new(8u, 0u, 0u, 167u);
    t0 = (void*) _a4_arr;
    vader_struct_std_string_builder_StringBuilder_t* _a5_obj = (vader_struct_std_string_builder_StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string_builder_StringBuilder_t));
    vader_obj_header_init(_a5_obj, 389u);
    _a5_obj->f_parts = t0;
    l9 = (void*) _a5_obj;
    l6 = concat_3(234u, l2, 224u);
    std_string_builder_append(l9, l6);
    vader_c_emit_emit_atom_comptime_table(l5, l9);
    vader_c_emit_emit_data_pool(l5, l9);
    vader_c_emit_emit_type_info_table(l5, l9);
    l10 = vader_c_emit_unit_names_of(((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_functions, l3);
    vader_array_t* _a6_arr = vader_array_new(8u, 0u, 0u, 167u);
    l11 = (void*) _a6_arr;
    l12 = ((vader_array_t*) l3)->length;
    l13 = (size_t) (int64_t) INT64_C(0);
    {
        loop_118: {
            if ((l13 < l12)) {
                vader_array_t* _a7_arr = vader_array_new(8u, 0u, 0u, 167u);
                t0 = (void*) _a7_arr;
                vader_struct_std_string_builder_StringBuilder_t* _a8_obj = (vader_struct_std_string_builder_StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string_builder_StringBuilder_t));
                vader_obj_header_init(_a8_obj, 389u);
                _a8_obj->f_parts = t0;
                l14 = (void*) _a8_obj;
                l6 = concat_3(234u, l2, 224u);
                std_string_builder_append(l14, l6);
                l15 = l13;
                vader_array_t* _a9_slotarr = ((vader_array_t*) l3);
                if (_a9_slotarr->buf != NULL && _a9_slotarr->buf->header.forward != NULL) { _a9_slotarr->buf = vader_array_buf_forward(_a9_slotarr->buf); }
                if ((size_t) l15 >= _a9_slotarr->length) { vader_trap("array index out of bounds"); }
                l16 = vader_array_ref_load_obj(_a9_slotarr->buf, _a9_slotarr->offset + (size_t) l15);
                vader_c_emit_emit_internal_forward_decls(l5, l16, l14);
                if (l13 == INT64_C(0)) {
                    vader_c_emit_emit_fn_trampolines(l5, l14);
                    vader_c_emit_emit_vtable_dispatchers(l5, l14);
                } else {
                }
                l17 = l13;
                vader_array_t* _a10_slotarr = ((vader_array_t*) l3);
                if (_a10_slotarr->buf != NULL && _a10_slotarr->buf->header.forward != NULL) { _a10_slotarr->buf = vader_array_buf_forward(_a10_slotarr->buf); }
                if ((size_t) l17 >= _a10_slotarr->length) { vader_trap("array index out of bounds"); }
                l18 = vader_array_ref_load_obj(_a10_slotarr->buf, _a10_slotarr->offset + (size_t) l17);
                l19 = ((vader_array_t*) l18)->length;
                l20 = (size_t) (int64_t) INT64_C(0);
                {
                    loop_167: {
                        if ((l20 < l19)) {
                            vader_array_t* _a11_slotarr = ((vader_array_t*) l18);
                            if (_a11_slotarr->buf != NULL && _a11_slotarr->buf->header.forward != NULL) { _a11_slotarr->buf = vader_array_buf_forward(_a11_slotarr->buf); }
                            if ((size_t) l20 >= _a11_slotarr->length) { vader_trap("array index out of bounds"); }
                            l21 = ((int32_t*) _a11_slotarr->buf->slots)[_a11_slotarr->offset + (size_t) l20];
                            l22 = ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_functions;
                            t1 = ((int64_t) (int32_t) l21);
                            l23 = (size_t) (int64_t) t1;
                            vader_array_t* _a12_slotarr = ((vader_array_t*) l22);
                            if (_a12_slotarr->buf != NULL && _a12_slotarr->buf->header.forward != NULL) { _a12_slotarr->buf = vader_array_buf_forward(_a12_slotarr->buf); }
                            if ((size_t) l23 >= _a12_slotarr->length) { vader_trap("array index out of bounds"); }
                            l24 = vader_array_ref_load_obj(_a12_slotarr->buf, _a12_slotarr->offset + (size_t) l23);
                            vader_c_emit_emit_function_body(l5, l21, l24, l14);
                            std_string_builder_append(l14, 1u);
                            t1 = (l20 + INT64_C(1));
                            l20 = (size_t) (int64_t) t1;
                            goto loop_167;
                        } else {
                        }
                    }
                }
                if (l13 == INT64_C(0)) {
                    l25 = ((vader_struct_vader_c_emit_EmitOptions_t*) l1)->f_entry_mangled;
                    vader_c_emit_emit_main(l5, l14, l25);
                } else {
                }
                l26 = std_string_builder_StringBuilder_Display_to_string(l14);
                vader_array_push((vader_array_t*) l11, vader_box_string(167u, l26));
                t1 = (l13 + INT64_C(1));
                l13 = (size_t) (int64_t) t1;
                goto loop_118;
            } else {
            }
        }
    }
    l6 = std_string_builder_StringBuilder_Display_to_string(l7);
    l25 = std_string_builder_StringBuilder_Display_to_string(l8);
    l26 = std_string_builder_StringBuilder_Display_to_string(l9);
    vader_struct_vader_c_emit_CProgram_t* _a13_obj = (vader_struct_vader_c_emit_CProgram_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_CProgram_t));
    vader_obj_header_init(_a13_obj, 659u);
    _a13_obj->f_header = l6;
    _a13_obj->f_imports = l25;
    _a13_obj->f_globals = l26;
    _a13_obj->f_units = l11;
    _a13_obj->f_unit_names = l10;
    t0 = (void*) _a13_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
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
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_ctx)->f_module)->f_functions;
    t0 = ((vader_struct_vader_bytecode_Call_t*) l1)->f_function_index;
    t1 = ((int64_t) (int32_t) t0);
    l3 = (size_t) (int64_t) t1;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
    l2 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
    t2 = ((vader_struct_vader_bytecode_BcFunction_t*) l2)->f_name;
    l4 = vader_c_emit_sanitise(t2);
    l2 = ((vader_struct_vader_bytecode_BcFunction_t*) l2)->f_signature;
    vader_c_emit_emit_call_to(l0, l4, l2);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_c_emit_emit_call_import(void* l0, void* l1) {
    void* l2 = NULL;
    size_t l3;
    vader_string_t l4 = 0;
    int32_t t0;
    int64_t t1;
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_string_t* gc_atom_roots[1] = { &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_ctx)->f_module)->f_imports;
    t0 = ((vader_struct_vader_bytecode_CallImport_t*) l1)->f_index;
    t1 = ((int64_t) (int32_t) t0);
    l3 = (size_t) (int64_t) t1;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
    l2 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
    l4 = vader_c_emit_host_shim_name(l2);
    l2 = ((vader_struct_vader_bytecode_BcImport_t*) l2)->f_signature;
    vader_c_emit_emit_call_to(l0, l4, l2);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_c_emit_emit_call_indirect(void* l0, void* l1) {
    void* l2 = NULL;
    void* l5 = NULL;
    void* l7 = NULL;
    size_t l3, l11;
    vader_box_t l4 = vader_box_null();
    int32_t l6;
    vader_string_t l8 = 0;
    vader_string_t l9 = 0;
    vader_string_t l10 = 0;
    int64_t l12;
    uint8_t l13;
    int32_t t0;
    int64_t t1;
    size_t t2;
    vader_box_t t3 = vader_box_null();
    vader_string_t t4 = 0;
    vader_box_t* gc_roots[2] = { &l4, &t3 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l5, &l7 };
    vader_string_t* gc_atom_roots[4] = { &l8, &l9, &l10, &t4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_ctx)->f_module)->f_types;
    t0 = ((vader_struct_vader_bytecode_CallIndirect_t*) l1)->f_type_id;
    t1 = ((int64_t) (int32_t) t0);
    l3 = (size_t) (int64_t) t1;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
    l4 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
    if (l4.tag == 499u) {
        l5 = l4.payload.obj;
        l4 = vader_c_emit_pop(l0);
        t2 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFn_t*) l5)->f_params)->length;
        l6 = ((int32_t) (size_t) t2);
        l7 = vader_c_emit_pop_args_boxed(l0, l6);
        l8 = vader_c_emit_aux(l0, 1599u);
        l9 = vader_c_emit_obj_ptr_of(l4);
        l9 = concat_5(2349u, l8, 67u, l9, 494u);
        vader_c_emit_line(l0, l9);
        if (l6 == INT32_C(0)) {
            l9 = concat_2(l8, 397u);
        } else {
            l10 = std_string_join(l7, 365u);
            l9 = concat_3(l8, 399u, l10);
        }
        l10 = l8;
        l3 = vader_host_std_core_byte_len(l10);
        l11 = vader_host_std_core_byte_len(l9);
        t1 = (l3 + l11);
        l3 = (size_t) (int64_t) t1;
        l7 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(55) + l3));
        l3 = (size_t) (int64_t) INT64_C(0);
        l3 = std_core_write_string_at(l7, l3, 296u);
        l12 = ((int64_t) (int32_t) l6);
        l3 = std_core_write_int(l7, l3, l12);
        l3 = std_core_write_string_at(l7, l3, 918u);
        l3 = std_core_write_string_at(l7, l3, l10);
        l3 = std_core_write_string_at(l7, l3, 396u);
        l3 = std_core_write_string_at(l7, l3, l9);
        l3 = std_core_write_string_at(l7, l3, 318u);
        l8 = std_core_finish_buffer(l7, l3);
        t0 = ((vader_struct_vader_bytecode_BcFn_t*) l5)->f_return_type;
        t1 = ((int64_t) (int32_t) t0);
        l3 = (size_t) (int64_t) t1;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
        if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
        if ((size_t) l3 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
        t3 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l3);
        l13 = vader_c_emit_val_type_of_bc_type(t3);
        if (l13 == INT32_C(16)) {
            l9 = concat_2(l8, 494u);
            vader_c_emit_line(l0, l9);
            { vader_gc_top = gc_frame.prev; return; }
        }
        l9 = vader_c_emit_fresh_tmp(l0, (uint8_t) (int32_t) INT32_C(19));
        l8 = concat_4(l9, 61u, l8, 494u);
        vader_c_emit_line(l0, l8);
        if (l13 == INT32_C(19)) {
            vader_c_emit_push_tmp(l0, l9, (uint8_t) (int32_t) INT32_C(19));
            { vader_gc_top = gc_frame.prev; return; }
        }
        l8 = vader_c_emit_fresh_tmp(l0, l13);
        l9 = vader_c_emit_coerce_expr(l2, l9, (uint8_t) (int32_t) INT32_C(19), l13);
        l9 = concat_4(l8, 61u, l9, 494u);
        vader_c_emit_line(l0, l9);
        vader_c_emit_push_tmp(l0, l8, l13);
        { vader_gc_top = gc_frame.prev; return; }
    }
    l2 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(49));
    l3 = (size_t) (int64_t) INT64_C(0);
    l3 = std_core_write_string_at(l2, l3, 1332u);
    t0 = ((vader_struct_vader_bytecode_CallIndirect_t*) l1)->f_type_id;
    l12 = ((int64_t) (int32_t) t0);
    l3 = std_core_write_int(l2, l3, l12);
    t4 = std_core_finish_buffer(l2, l3);
    std_abort_todo(t4);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_c_emit_emit_call_result(void* l0, vader_string_t l1, uint8_t l2) {
    bool l3;
    vader_string_t l4 = 0;
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[2] = { &l1, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    if (l2 == INT32_C(16)) {
        l3 = true;
    } else {
        l3 = ((vader_struct_vader_c_emit_FnState_t*) l0)->f_drop_call_result;
    }
    if (l3) {
        l4 = concat_2(l1, 494u);
        vader_c_emit_line(l0, l4);
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_c_emit_push_into_tmp(l0, l1, l2);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_c_emit_emit_call_to(void* l0, vader_string_t l1, void* l2) {
    int32_t l3, l5, l7;
    void* l4 = NULL;
    void* l9 = NULL;
    void* l12 = NULL;
    vader_box_t l6 = vader_box_null();
    size_t l8, l13;
    vader_string_t l10 = 0;
    vader_string_t l15 = 0;
    uint8_t l11, l14;
    size_t t0;
    int64_t t1;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l6, &t2 };
    void** gc_raw_roots[5] = { &l0, &l2, &l4, &l9, &l12 };
    vader_string_t* gc_atom_roots[3] = { &l1, &l10, &l15 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) l2)->f_params)->length;
    l3 = ((int32_t) (size_t) t0);
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 167u);
    l4 = (void*) _a0_arr;
    l5 = INT32_C(0);
    {
        loop_9: {
            if ((l5 < l3)) {
                vader_array_push((vader_array_t*) l4, vader_box_string(167u, 0u));
                l5 = (l5 + INT32_C(1));
                goto loop_9;
            } else {
            }
        }
    }
    l5 = INT32_C(0);
    {
        loop_29: {
            if ((l5 < l3)) {
                l6 = vader_c_emit_pop(l0);
                l7 = ((l3 - INT32_C(1)) - l5);
                t1 = ((int64_t) (int32_t) l7);
                l8 = (size_t) (int64_t) t1;
                l9 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_ctx)->f_module)->f_types;
                l10 = vader_c_emit_name_of(l6);
                l11 = vader_c_emit_val_of(l6);
                l12 = ((vader_struct_vader_bytecode_BcSignature_t*) l2)->f_params;
                t1 = ((int64_t) (int32_t) l7);
                l13 = (size_t) (int64_t) t1;
                vader_array_t* _a1_slotarr = ((vader_array_t*) l12);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l13 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                t2 = vader_array_read_u8(_a1_slotarr, _a1_slotarr->offset + (size_t) l13, 173u);
                l14 = ((uint8_t) t2.payload.i);
                l15 = vader_c_emit_coerce_expr(l9, l10, l11, l14);
                vader_array_t* _a2_slotarr = ((vader_array_t*) l4);
                if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                if ((size_t) l8 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                vader_array_box_slots(_a2_slotarr->buf)[_a2_slotarr->offset + (size_t) l8] = vader_box_string(167u, l15);
                VADER_WRITE_BARRIER(_a2_slotarr->buf);
                l5 = (l5 + INT32_C(1));
                goto loop_29;
            } else {
            }
        }
    }
    l10 = std_string_join(l4, 365u);
    l10 = concat_4(l1, 278u, l10, 318u);
    l11 = ((vader_struct_vader_bytecode_BcSignature_t*) l2)->f_result;
    vader_c_emit_emit_call_result(l0, l10, l11);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_c_emit_emit_closure_forward_decls(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    size_t l4, l5;
    vader_string_t l6 = 0;
    vader_string_t l8 = 0;
    vader_string_t l9 = 0;
    vader_string_t l11 = 0;
    vader_string_t l12 = 0;
    int32_t l7, l10;
    bool l13;
    bool t0;
    int32_t t1;
    void* t2 = NULL;
    size_t t3;
    int64_t t4;
    vader_box_t t5 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t5 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &t2 };
    vader_string_t* gc_atom_roots[5] = { &l6, &l8, &l9, &l11, &l12 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 5u, gc_atom_roots };
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
    l4 = ((vader_array_t*) l3)->length;
    l5 = (size_t) (int64_t) INT64_C(0);
    {
        loop_24: {
            if ((l5 < l4)) {
                vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_c_emit_FnValueUsage_t*) l2)->f_fn_ref_type);
                if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                if ((size_t) l5 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l5];
                if ((t1 >= INT32_C(0))) {
                    vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
                    if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                    if ((size_t) l5 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                    t2 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5);
                    t3 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcFunction_t*) t2)->f_signature)->f_params)->length;
                    l6 = vader_c_emit_tramp_head(t3);
                    l7 = ((int32_t) (size_t) l5);
                    l8 = vader_c_emit_fn_symbol_name(l3, l7);
                    l9 = concat_5(2331u, l8, 278u, l6, 350u);
                    std_string_builder_append(l1, l9);
                    l10 = ((int32_t) (size_t) l5);
                    l11 = vader_c_emit_fn_symbol_name(l3, l10);
                    l12 = concat_3(1535u, l11, 495u);
                    std_string_builder_append(l1, l12);
                } else {
                }
                t4 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t4;
                goto loop_24;
            } else {
            }
        }
    }
    l4 = ((vader_array_t*) l3)->length;
    l5 = (size_t) (int64_t) INT64_C(0);
    {
        loop_92: {
            if ((l5 < l4)) {
                vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_c_emit_FnValueUsage_t*) l2)->f_is_closure);
                if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                if ((size_t) l5 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                t5 = vader_box_bool(165u, ((uint8_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l5]);
                t0 = t5.payload.b;
                if (t0) {
                    vader_array_t* _a3_slotarr = ((vader_array_t*) l3);
                    if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                    if ((size_t) l5 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                    t2 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l5);
                    t3 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcFunction_t*) t2)->f_signature)->f_params)->length;
                    l13 = (t3 > INT64_C(0));
                } else {
                    l13 = false;
                }
                if (l13) {
                    vader_array_t* _a4_slotarr = ((vader_array_t*) l3);
                    if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                    if ((size_t) l5 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                    t2 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l5);
                    t3 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcFunction_t*) t2)->f_signature)->f_params)->length;
                    l6 = vader_c_emit_tramp_head((size_t) (int64_t) ((int64_t) (int32_t) (((int32_t) (size_t) t3) - INT32_C(1))));
                    l7 = ((int32_t) (size_t) l5);
                    l8 = vader_c_emit_fn_symbol_name(l3, l7);
                    l9 = concat_5(2330u, l8, 278u, l6, 350u);
                    std_string_builder_append(l1, l9);
                } else {
                }
                t4 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t4;
                goto loop_92;
            } else {
            }
        }
    }
    std_string_builder_append(l1, 1u);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_c_emit_emit_closure_lift(void* l0, void* l1, int32_t l2) {
    void* l3 = NULL;
    void* l7 = NULL;
    size_t l4;
    vader_string_t l5 = 0;
    vader_string_t l6 = 0;
    vader_string_t l9 = 0;
    vader_string_t l10 = 0;
    uint8_t l8;
    int64_t t0;
    vader_string_t t1 = 0;
    size_t t2;
    bool t3;
    vader_box_t t4 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t4 };
    void** gc_raw_roots[4] = { &l0, &l1, &l3, &l7 };
    vader_string_t* gc_atom_roots[5] = { &l5, &l6, &l9, &l10, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 5u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_functions;
    t0 = ((int64_t) (int32_t) l2);
    l4 = (size_t) (int64_t) t0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    if ((size_t) l4 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
    l3 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
    t1 = ((vader_struct_vader_bytecode_BcFunction_t*) l3)->f_name;
    l5 = vader_c_emit_sanitise(t1);
    l3 = ((vader_struct_vader_bytecode_BcFunction_t*) l3)->f_signature;
    t2 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) l3)->f_params)->length;
    if (t2 == INT64_C(0)) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    t2 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) l3)->f_params)->length;
    l6 = vader_c_emit_tramp_head((size_t) (int64_t) ((int64_t) (int32_t) (((int32_t) (size_t) t2) - INT32_C(1))));
    t3 = ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_split;
    t1 = vader_c_emit_linkage_prefix(t3);
    l6 = concat_6(t1, 2330u, l5, 278u, l6, 334u);
    std_string_builder_append(l1, l6);
    l7 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_types;
    vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) l3)->f_params);
    if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
    if ((size_t) INT32_C(0) >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
    t4 = vader_array_read_u8(_a1_slotarr, _a1_slotarr->offset + (size_t) INT32_C(0), 173u);
    l8 = ((uint8_t) t4.payload.i);
    l6 = vader_c_emit_coerce_expr(l7, 1479u, (uint8_t) (int32_t) INT32_C(18), l8);
    l9 = vader_c_emit_lift_unbox_tail(((vader_struct_vader_bytecode_BcSignature_t*) l3)->f_params);
    if (l9 == 0u) {
        l10 = l6;
    } else {
        l10 = concat_3(l6, 365u, l9);
    }
    if (((vader_struct_vader_bytecode_BcSignature_t*) l3)->f_result == INT32_C(16)) {
        l6 = concat_5(7u, l5, 278u, l10, 350u);
        std_string_builder_append(l1, l6);
        std_string_builder_append(l1, 19u);
    } else {
        l5 = vader_c_emit_tramp_box_result(l5, l10, l3);
        l5 = concat_3(16u, l5, 495u);
        std_string_builder_append(l1, l5);
    }
    std_string_builder_append(l1, 2426u);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_c_emit_emit_convert(void* l0, uint8_t l1, vader_string_t l2) {
    vader_box_t l3 = vader_box_null();
    uint8_t l4, l5;
    bool l6;
    vader_string_t l7 = 0;
    vader_string_t l8 = 0;
    vader_string_t l9 = 0;
    bool t0;
    vader_string_t t1 = 0;
    vader_box_t* gc_roots[1] = { &l3 };
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[5] = { &l2, &l7, &l8, &l9, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 5u, gc_atom_roots };
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
        l6 = std_string_starts_with(l2, 2198u);
    } else {
        l6 = false;
    }
    if (l6) {
        l5 = (uint8_t) (int32_t) INT32_C(7);
    } else {
        l5 = l4;
    }
    t0 = vader_c_emit_is_ref_val(l4);
    if (t0) {
        t1 = vader_c_emit_name_of(l3);
        l7 = vader_c_emit_unbox_expr(t1, l1);
        vader_c_emit_push_expr(l0, l1, l7);
    } else {
        if (l5 == l1) {
            l7 = vader_c_emit_name_of(l3);
            vader_c_emit_push_expr(l0, l1, l7);
        } else {
            l7 = vader_c_emit_c_type_for_val_bare(l1);
            l8 = vader_c_emit_c_type_for_val_bare(l5);
            l9 = vader_c_emit_name_of(l3);
            l7 = concat_7(279u, l7, 320u, l8, 319u, l9, 318u);
            vader_c_emit_push_expr(l0, l1, l7);
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_c_emit_emit_data_const_op(void* l0, void* l1) {
    vader_string_t l2 = 0;
    vader_string_t l3 = 0;
    size_t l4;
    void* l5 = NULL;
    int64_t l6;
    int32_t t0;
    void** gc_raw_roots[3] = { &l0, &l1, &l5 };
    vader_string_t* gc_atom_roots[2] = { &l2, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = vader_c_emit_fresh_tmp(l0, (uint8_t) (int32_t) INT32_C(18));
    l3 = l2;
    l4 = vader_host_std_core_byte_len(l3);
    l5 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(44) + l4));
    l4 = (size_t) (int64_t) INT64_C(0);
    l4 = std_core_write_string_at(l5, l4, l3);
    l4 = std_core_write_string_at(l5, l4, 71u);
    t0 = ((vader_struct_vader_bytecode_DataConst_t*) l1)->f_pool_index;
    l6 = ((int64_t) (int32_t) t0);
    l4 = std_core_write_int(l5, l4, l6);
    l4 = std_core_write_string_at(l5, l4, 494u);
    l3 = std_core_finish_buffer(l5, l4);
    vader_c_emit_line(l0, l3);
    vader_c_emit_push_tmp(l0, l2, (uint8_t) (int32_t) INT32_C(18));
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_c_emit_emit_data_global_externs(void* l0, void* l1) {
    size_t l2, l3, l5, l7;
    vader_string_t l4 = 0;
    vader_string_t l9 = 0;
    void* l6 = NULL;
    uint64_t l8;
    vader_box_t t0 = vader_box_null();
    bool t1;
    int64_t t2;
    void* t3 = NULL;
    size_t t4;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[4] = { &l0, &l1, &l6, &t3 };
    vader_string_t* gc_atom_roots[2] = { &l4, &l9 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_data_pool)->length;
    l3 = (size_t) (int64_t) INT64_C(0);
    {
        loop_7: {
            if ((l3 < l2)) {
                vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_data_pool);
                if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
                t1 = vader_c_emit_data_entry_mutable(t0);
                l4 = vader_c_emit_storage_qualifier(t1);
                l5 = vader_host_std_core_byte_len(l4);
                l6 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(54) + l5));
                l7 = (size_t) (int64_t) INT64_C(0);
                l7 = std_core_write_string_at(l6, l7, 1530u);
                l7 = std_core_write_string_at(l6, l7, l4);
                l7 = std_core_write_string_at(l6, l7, 2316u);
                t2 = ((int64_t) (size_t) l3);
                l8 = (uint64_t) (int64_t) t2;
                l7 = std_core_write_unsigned(l6, l7, l8);
                l7 = std_core_write_string_at(l6, l7, 495u);
                l9 = std_core_finish_buffer(l6, l7);
                std_string_builder_append(l1, l9);
                t2 = (l3 + INT64_C(1));
                l3 = (size_t) (int64_t) t2;
                goto loop_7;
            } else {
            }
        }
    }
    t3 = vader_c_emit_mutable_pool_indices(((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_data_pool);
    t4 = ((vader_array_t*) t3)->length;
    if ((t4 > INT64_C(0))) {
        std_string_builder_append(l1, 1534u);
        std_string_builder_append(l1, 1537u);
        std_string_builder_append(l1, 1536u);
    } else {
    }
    std_string_builder_append(l1, 1533u);
    std_string_builder_append(l1, 1532u);
    std_string_builder_append(l1, 1u);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_c_emit_emit_data_pool(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    size_t l7, l8;
    vader_box_t l9 = vader_box_null();
    int32_t l10, l11;
    bool l12, l13;
    size_t t0;
    bool t1;
    int64_t t2;
    vader_box_t* gc_roots[1] = { &l9 };
    void** gc_raw_roots[7] = { &l0, &l1, &l2, &l3, &l4, &l5, &l6 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 7u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_data_pool)->length;
    if (t0 == INT64_C(0)) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    std_string_builder_append(l1, 432u);
    std_string_builder_append(l1, 53u);
    std_string_builder_append(l1, 54u);
    l2 = vader_c_emit_data_pool_type_ids(((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module);
    t1 = vader_c_emit_has_str_data(((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_data_pool);
    if (t1) {
        l3 = vader_c_emit_build_string_atom_map(l0);
    } else {
        vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 167u);
        l4 = (void*) _a0_arr;
        vader_array_t* _a1_arr = vader_array_new(9u, 0u, 7u, 170u);
        l5 = (void*) _a1_arr;
        vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 170u);
        l6 = (void*) _a2_arr;
        vader_struct_std_collections_MutableMap__string__i32_t* _a3_obj = (vader_struct_std_collections_MutableMap__string__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__i32_t));
        vader_obj_header_init(_a3_obj, 358u);
        _a3_obj->f_ekeys = l4;
        _a3_obj->f_evals = l5;
        _a3_obj->f_index = l6;
        _a3_obj->f_mask = (size_t) (int64_t) INT64_C(0);
        _a3_obj->f_size = (size_t) (int64_t) INT64_C(0);
        _a3_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
        l3 = (void*) _a3_obj;
    }
    l7 = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_data_pool)->length;
    l8 = (size_t) (int64_t) INT64_C(0);
    {
        loop_50: {
            if ((l8 < l7)) {
                vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_data_pool);
                if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                if ((size_t) l8 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                l9 = vader_array_ref_load_box(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l8);
                vader_array_t* _a5_slotarr = ((vader_array_t*) l2);
                if (_a5_slotarr->buf != NULL && _a5_slotarr->buf->header.forward != NULL) { _a5_slotarr->buf = vader_array_buf_forward(_a5_slotarr->buf); }
                if ((size_t) l8 >= _a5_slotarr->length) { vader_trap("array index out of bounds"); }
                l10 = ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l8];
                l11 = vader_c_emit_array_element_tag(((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_types, l10);
                if (l9.tag == 508u) {
                    l4 = l9.payload.obj;
                    l12 = ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_split;
                    vader_c_emit_emit_str_data_entry(l1, l8, l4, l10, l11, l3, l12);
                } else {
                    if (l9.tag == 504u) {
                        l5 = l9.payload.obj;
                        l13 = ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_split;
                        vader_c_emit_emit_prim_data_entry(l1, l8, l5, l10, l11, l13);
                    } else {
                        if (l9.tag == 495u) {
                            l6 = l9.payload.obj;
                            vader_c_emit_emit_agg_data_entry(l1, l8, l6, l10, l11, l3, l0);
                        } else {
                        }
                    }
                }
                t2 = (l8 + INT64_C(1));
                l8 = (size_t) (int64_t) t2;
                goto loop_50;
            } else {
            }
        }
    }
    vader_c_emit_emit_global_const_roots(l0, l1);
    std_string_builder_append(l1, 1u);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static vader_string_t vader_c_emit_emit_data_value(void* l0, void* l1, vader_box_t l2, vader_string_t l3, void* l4) {
    void* l5 = NULL;
    void* l9 = NULL;
    void* l13 = NULL;
    void* l19 = NULL;
    uint8_t l6;
    uint64_t l7;
    vader_string_t l8 = 0;
    vader_string_t l17 = 0;
    vader_string_t l21 = 0;
    vader_string_t l22 = 0;
    size_t l10, l14, l15, l18, l20;
    int64_t l11;
    int32_t l12;
    vader_box_t l16 = vader_box_null();
    vader_string_t t0 = 0;
    int32_t t1;
    int64_t t2;
    vader_box_t t3 = vader_box_null();
    void* t4 = NULL;
    bool t5;
    vader_box_t* gc_roots[3] = { &l2, &l16, &t3 };
    void** gc_raw_roots[8] = { &l0, &l1, &l4, &l5, &l9, &l13, &l19, &t4 };
    vader_string_t* gc_atom_roots[6] = { &l3, &l8, &l17, &l21, &l22, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 6u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    if (l2.tag == 512u) {
        l5 = l2.payload.obj;
        l6 = ((vader_struct_vader_bytecode_BcValPrim_t*) l5)->f_kind;
        l7 = ((vader_struct_vader_bytecode_BcValPrim_t*) l5)->f_bits;
        l8 = vader_c_emit_c_type_for_array_kind(((vader_struct_vader_bytecode_BcValPrim_t*) l5)->f_kind);
        t0 = vader_c_emit_data_slot_c(l6, l7, l8);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l2.tag == 513u) {
        l5 = l2.payload.obj;
        l9 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(21));
        l10 = (size_t) (int64_t) INT64_C(0);
        l8 = ((vader_struct_vader_bytecode_BcValStr_t*) l5)->f_value;
        t1 = vader_c_emit_atom_for(l4, l8);
        l11 = ((int64_t) (int32_t) t1);
        l10 = std_core_write_int(l9, l10, l11);
        l10 = std_core_write_string_at(l9, l10, 2198u);
        t0 = std_core_finish_buffer(l9, l10);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l2.tag == 514u) {
        l5 = l2.payload.obj;
        l9 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_types;
        l12 = ((vader_struct_vader_bytecode_BcValStruct_t*) l5)->f_symbol_id;
        l12 = vader_c_emit_type_id_for_struct_symbol(l9, l12);
        l9 = ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_struct_c_names;
        t2 = ((int64_t) (int32_t) l12);
        l10 = (size_t) (int64_t) t2;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l9);
        if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
        if ((size_t) l10 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
        t3 = vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l10];
        l8 = t3.payload.s;
        l9 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(43));
        l10 = (size_t) (int64_t) INT64_C(0);
        l10 = std_core_write_string_at(l9, l10, 2417u);
        l11 = ((int64_t) (int32_t) l12);
        l10 = std_core_write_int(l9, l10, l11);
        l10 = std_core_write_string_at(l9, l10, 2219u);
        t0 = std_core_finish_buffer(l9, l10);
        vader_array_t* _a1_arr = vader_array_new(8u, 1u, 0u, 167u);
        vader_array_box_slots(_a1_arr->buf)[_a1_arr->offset + 0u] = vader_box_string(167u, t0);
        l9 = (void*) _a1_arr;
        l13 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_types;
        t2 = ((int64_t) (int32_t) l12);
        l10 = (size_t) (int64_t) t2;
        vader_array_t* _a2_slotarr = ((vader_array_t*) l13);
        if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
        if ((size_t) l10 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
        t3 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l10);
        if (t3.tag == 509u) {
            l13 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_types;
            t2 = ((int64_t) (int32_t) l12);
            l10 = (size_t) (int64_t) t2;
            vader_array_t* _a3_slotarr = ((vader_array_t*) l13);
            if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
            if ((size_t) l10 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
            t3 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l10);
            l13 = t3.payload.obj;
            l10 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcValStruct_t*) l5)->f_fields)->length;
            l14 = (size_t) (int64_t) INT64_C(0);
            {
                loop_136: {
                    if ((l14 < l10)) {
                        l15 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcStruct_t*) l13)->f_fields)->length;
                        if ((l14 < l15)) {
                            vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcStruct_t*) l13)->f_fields);
                            if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                            if ((size_t) l14 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                            t4 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l14);
                            l12 = ((vader_struct_vader_bytecode_BcField_t*) t4)->f_type_index;
                        } else {
                            l12 = INT32_C(0);
                        }
                        vader_array_t* _a5_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcValStruct_t*) l5)->f_fields);
                        if (_a5_slotarr->buf != NULL && _a5_slotarr->buf->header.forward != NULL) { _a5_slotarr->buf = vader_array_buf_forward(_a5_slotarr->buf); }
                        if ((size_t) l14 >= _a5_slotarr->length) { vader_trap("array index out of bounds"); }
                        l16 = vader_array_ref_load_box(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l14);
                        l17 = l3;
                        l18 = vader_host_std_core_byte_len(l17);
                        l19 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(22) + l18));
                        l20 = (size_t) (int64_t) INT64_C(0);
                        l20 = std_core_write_string_at(l19, l20, l17);
                        l20 = std_core_write_string_at(l19, l20, 905u);
                        t2 = ((int64_t) (size_t) l14);
                        l7 = (uint64_t) (int64_t) t2;
                        l20 = std_core_write_unsigned(l19, l20, l7);
                        l21 = std_core_finish_buffer(l19, l20);
                        l22 = vader_c_emit_struct_field_init(l0, l1, l16, l21, l12, l4);
                        vader_array_push((vader_array_t*) l9, vader_box_string(167u, l22));
                        t2 = (l14 + INT64_C(1));
                        l14 = (size_t) (int64_t) t2;
                        goto loop_136;
                    } else {
                    }
                }
            }
        } else {
        }
        t5 = ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_split;
        l17 = vader_c_emit_linkage_prefix(t5);
        l21 = vader_c_emit_join_commas(l9);
        l17 = concat_8(l17, 1405u, l8, 6u, l3, 86u, l21, 209u);
        std_string_builder_append(l1, l17);
        t0 = concat_4(310u, l8, 355u, l3);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l2.tag == 511u) {
        l5 = l2.payload.obj;
        t0 = vader_c_emit_emit_nested_array(l0, l1, l5, l3, l4);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return 445u; }
    vader_gc_top = gc_frame.prev;
}

static void vader_c_emit_emit_defer_pop_exec(void* l0, void* l1) {
    void* l2 = NULL;
    size_t l3;
    int64_t l4;
    vader_string_t l5 = 0;
    int32_t t0;
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_string_t* gc_atom_roots[1] = { &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(44));
    l3 = (size_t) (int64_t) INT64_C(0);
    l3 = std_core_write_string_at(l2, l3, 2345u);
    t0 = ((vader_struct_vader_bytecode_DeferPopExec_t*) l1)->f_count;
    l4 = ((int64_t) (int32_t) t0);
    l3 = std_core_write_int(l2, l3, l4);
    l3 = std_core_write_string_at(l2, l3, 2205u);
    l5 = std_core_finish_buffer(l2, l3);
    vader_c_emit_line(l0, l5);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_c_emit_emit_defer_push(void* l0) {
    vader_box_t l1 = vader_box_null();
    void* l2 = NULL;
    vader_string_t l3 = 0;
    uint8_t l4;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_string_t* gc_atom_roots[1] = { &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l1 = vader_c_emit_pop(l0);
    l2 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_ctx)->f_module)->f_types;
    l3 = vader_c_emit_name_of(l1);
    l4 = vader_c_emit_val_of(l1);
    l3 = vader_c_emit_coerce_expr(l2, l3, l4, (uint8_t) (int32_t) INT32_C(19));
    l3 = concat_3(2346u, l3, 349u);
    vader_c_emit_line(l0, l3);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_c_emit_emit_else(void* l0) {
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_c_emit_assert_stack_empty(l0, 1464u);
    vader_c_emit_indent_pop(l0);
    vader_c_emit_line(l0, 2427u);
    vader_c_emit_indent_push(l0);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_c_emit_emit_end(void* l0, int32_t l1) {
    void* l2 = NULL;
    void* l7 = NULL;
    size_t l3;
    int64_t l4;
    vader_string_t l5 = 0;
    vader_box_t l6 = vader_box_null();
    int32_t l8;
    bool t0;
    int32_t t1;
    vader_string_t t2 = 0;
    vader_box_t* gc_roots[1] = { &l6 };
    void** gc_raw_roots[3] = { &l0, &l2, &l7 };
    vader_string_t* gc_atom_roots[2] = { &l5, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(35));
    l3 = (size_t) (int64_t) INT64_C(0);
    l3 = std_core_write_string_at(l2, l3, 1995u);
    l4 = ((int64_t) (int32_t) l1);
    l3 = std_core_write_int(l2, l3, l4);
    l3 = std_core_write_string_at(l2, l3, 318u);
    l5 = std_core_finish_buffer(l2, l3);
    vader_c_emit_assert_stack_empty(l0, l5);
    l6 = vader_c_emit_scope_ending_at(((vader_struct_vader_c_emit_FnState_t*) l0)->f_scopes, l1);
    if (l6.tag == 667u) {
        l2 = l6.payload.obj;
        vader_c_emit_indent_pop(l0);
        l7 = ((vader_struct_vader_c_emit_FnState_t*) l0)->f_break_targets;
        l8 = ((vader_struct_vader_c_emit_ScopeInfo_t*) l2)->f_opener_pc;
        t0 = std_core____Contains_contains__i32(l7, l8);
        if (t0) {
            l7 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(29));
            l3 = (size_t) (int64_t) INT64_C(0);
            l3 = std_core_write_string_at(l7, l3, 2428u);
            t1 = ((vader_struct_vader_c_emit_ScopeInfo_t*) l2)->f_opener_pc;
            l4 = ((int64_t) (int32_t) t1);
            l3 = std_core_write_int(l7, l3, l4);
            l3 = std_core_write_string_at(l7, l3, 464u);
            l5 = std_core_finish_buffer(l7, l3);
            vader_c_emit_line(l0, l5);
        } else {
            vader_c_emit_line(l0, 2425u);
        }
    } else {
        l2 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(50));
        l3 = (size_t) (int64_t) INT64_C(0);
        l3 = std_core_write_string_at(l2, l3, 1467u);
        l4 = ((int64_t) (int32_t) l1);
        l3 = std_core_write_int(l2, l3, l4);
        t2 = std_core_finish_buffer(l2, l3);
        std_abort_todo(t2);
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_c_emit_emit_f32_to_bits(void* l0) {
    vader_box_t l1 = vader_box_null();
    void* l2 = NULL;
    vader_string_t l3 = 0;
    uint8_t l4;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_string_t* gc_atom_roots[1] = { &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l1 = vader_c_emit_pop(l0);
    l2 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_ctx)->f_module)->f_types;
    l3 = vader_c_emit_name_of(l1);
    l4 = vader_c_emit_val_of(l1);
    l3 = vader_c_emit_coerce_operand(l2, l3, l4, (uint8_t) (int32_t) INT32_C(10));
    l3 = concat_3(306u, l3, 205u);
    vader_c_emit_push_expr(l0, (uint8_t) (int32_t) INT32_C(2), l3);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_c_emit_emit_f64_to_bits(void* l0) {
    vader_box_t l1 = vader_box_null();
    void* l2 = NULL;
    vader_string_t l3 = 0;
    uint8_t l4;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_string_t* gc_atom_roots[1] = { &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l1 = vader_c_emit_pop(l0);
    l2 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_ctx)->f_module)->f_types;
    l3 = vader_c_emit_name_of(l1);
    l4 = vader_c_emit_val_of(l1);
    l3 = vader_c_emit_coerce_operand(l2, l3, l4, (uint8_t) (int32_t) INT32_C(11));
    l3 = concat_3(308u, l3, 206u);
    vader_c_emit_push_expr(l0, (uint8_t) (int32_t) INT32_C(3), l3);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_c_emit_emit_fn_addr(void* l0, void* l1) {
    vader_string_t l2 = 0;
    vader_string_t l5 = 0;
    void* l3 = NULL;
    int32_t l4;
    void** gc_raw_roots[3] = { &l0, &l1, &l3 };
    vader_string_t* gc_atom_roots[2] = { &l2, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = vader_c_emit_fresh_tmp(l0, (uint8_t) (int32_t) INT32_C(17));
    l3 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_ctx)->f_module)->f_functions;
    l4 = ((vader_struct_vader_bytecode_FnAddr_t*) l1)->f_function_index;
    l5 = vader_c_emit_fn_symbol_name(l3, l4);
    l5 = concat_4(l2, 70u, l5, 494u);
    vader_c_emit_line(l0, l5);
    vader_c_emit_line(l0, 2347u);
    vader_c_emit_push_tmp(l0, l2, (uint8_t) (int32_t) INT32_C(17));
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_c_emit_emit_fn_ref(void* l0, void* l1) {
    vader_string_t l2 = 0;
    vader_string_t l5 = 0;
    void* l3 = NULL;
    int32_t l4;
    void** gc_raw_roots[3] = { &l0, &l1, &l3 };
    vader_string_t* gc_atom_roots[2] = { &l2, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = vader_c_emit_fresh_tmp(l0, (uint8_t) (int32_t) INT32_C(18));
    l3 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_ctx)->f_module)->f_functions;
    l4 = ((vader_struct_vader_bytecode_FnRef_t*) l1)->f_function_index;
    l5 = vader_c_emit_fn_symbol_name(l3, l4);
    l5 = concat_4(l2, 72u, l5, 494u);
    vader_c_emit_line(l0, l5);
    vader_c_emit_push_tmp(l0, l2, (uint8_t) (int32_t) INT32_C(18));
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_c_emit_emit_fn_ref_tramp(void* l0, void* l1, int32_t l2, int32_t l3) {
    void* l4 = NULL;
    size_t l5, l10;
    vader_string_t l6 = 0;
    vader_string_t l7 = 0;
    vader_string_t l8 = 0;
    vader_string_t l9 = 0;
    int64_t l11;
    int64_t t0;
    vader_string_t t1 = 0;
    bool t2;
    size_t t3;
    void** gc_raw_roots[3] = { &l0, &l1, &l4 };
    vader_string_t* gc_atom_roots[5] = { &l6, &l7, &l8, &l9, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 5u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l4 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_functions;
    t0 = ((int64_t) (int32_t) l2);
    l5 = (size_t) (int64_t) t0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    if ((size_t) l5 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
    l4 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
    t1 = ((vader_struct_vader_bytecode_BcFunction_t*) l4)->f_name;
    l6 = vader_c_emit_sanitise(t1);
    l4 = ((vader_struct_vader_bytecode_BcFunction_t*) l4)->f_signature;
    t2 = ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_split;
    l7 = vader_c_emit_linkage_prefix(t2);
    t3 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) l4)->f_params)->length;
    l8 = vader_c_emit_tramp_head(t3);
    l8 = concat_6(l7, 2331u, l6, 278u, l8, 334u);
    std_string_builder_append(l1, l8);
    std_string_builder_append(l1, 10u);
    l8 = vader_c_emit_tramp_unbox_args(((vader_struct_vader_bytecode_BcSignature_t*) l4)->f_params);
    if (((vader_struct_vader_bytecode_BcSignature_t*) l4)->f_result == INT32_C(16)) {
        l9 = concat_5(7u, l6, 278u, l8, 350u);
        std_string_builder_append(l1, l9);
        std_string_builder_append(l1, 19u);
    } else {
        l8 = vader_c_emit_tramp_box_result(l6, l8, l4);
        l8 = concat_3(16u, l8, 495u);
        std_string_builder_append(l1, l8);
    }
    std_string_builder_append(l1, 2426u);
    l8 = l6;
    l5 = vader_host_std_core_byte_len(l7);
    l10 = vader_host_std_core_byte_len(l8);
    t0 = (l5 + l10);
    l5 = (size_t) (int64_t) t0;
    l10 = vader_host_std_core_byte_len(l6);
    t0 = (l5 + l10);
    l5 = (size_t) (int64_t) t0;
    l4 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(111) + l5));
    l5 = (size_t) (int64_t) INT64_C(0);
    l5 = std_core_write_string_at(l4, l5, l7);
    l5 = std_core_write_string_at(l4, l5, 2348u);
    l5 = std_core_write_string_at(l4, l5, l8);
    l5 = std_core_write_string_at(l4, l5, 87u);
    l11 = ((int64_t) (int32_t) l3);
    l5 = std_core_write_int(l4, l5, l11);
    l5 = std_core_write_string_at(l4, l5, 2221u);
    l5 = std_core_write_string_at(l4, l5, l6);
    l5 = std_core_write_string_at(l4, l5, 373u);
    l6 = std_core_finish_buffer(l4, l5);
    std_string_builder_append(l1, l6);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_c_emit_emit_fn_sig_typedefs(void* l0, void* l1) {
    int32_t l2, l3;
    vader_string_t l4 = 0;
    vader_string_t l9 = 0;
    size_t l5, l7;
    void* l6 = NULL;
    int64_t l8;
    void** gc_raw_roots[3] = { &l0, &l1, &l6 };
    vader_string_t* gc_atom_roots[2] = { &l4, &l9 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = vader_c_emit_max_fn_arity(((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_types);
    l3 = INT32_C(0);
    {
        loop_7: {
            if ((l3 <= l2)) {
                l4 = vader_c_emit_erased_sig_params(l3);
                l5 = vader_host_std_core_byte_len(l4);
                l6 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(69) + l5));
                l7 = (size_t) (int64_t) INT64_C(0);
                l7 = std_core_write_string_at(l6, l7, 2197u);
                l8 = ((int64_t) (int32_t) l3);
                l7 = std_core_write_int(l6, l7, l8);
                l7 = std_core_write_string_at(l6, l7, 919u);
                l7 = std_core_write_string_at(l6, l7, l4);
                l7 = std_core_write_string_at(l6, l7, 350u);
                l9 = std_core_finish_buffer(l6, l7);
                std_string_builder_append(l1, l9);
                l3 = (l3 + INT32_C(1));
                goto loop_7;
            } else {
            }
        }
    }
    std_string_builder_append(l1, 1u);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_c_emit_emit_fn_trampolines(void* l0, void* l1) {
    void* l2 = NULL;
    size_t l3, l4;
    int32_t l5, l6;
    bool t0;
    int32_t t1;
    int64_t t2;
    vader_box_t t3 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t3 };
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = vader_c_emit_scan_fn_value_usage(((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_functions);
    t0 = ((vader_struct_vader_c_emit_FnValueUsage_t*) l2)->f_any;
    if (!(t0)) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l3 = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_functions)->length;
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_17: {
            if ((l4 < l3)) {
                vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_c_emit_FnValueUsage_t*) l2)->f_fn_ref_type);
                if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                if ((size_t) l4 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l4];
                if ((t1 >= INT32_C(0))) {
                    l5 = ((int32_t) (size_t) l4);
                    vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_c_emit_FnValueUsage_t*) l2)->f_fn_ref_type);
                    if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                    if ((size_t) l4 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                    l6 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
                    vader_c_emit_emit_fn_ref_tramp(l0, l1, l5, l6);
                } else {
                }
                t2 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t2;
                goto loop_17;
            } else {
            }
        }
    }
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_54: {
            if ((l4 < l3)) {
                vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_c_emit_FnValueUsage_t*) l2)->f_is_closure);
                if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                if ((size_t) l4 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                t3 = vader_box_bool(165u, ((uint8_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l4]);
                t0 = t3.payload.b;
                if (t0) {
                    l5 = ((int32_t) (size_t) l4);
                    vader_c_emit_emit_closure_lift(l0, l1, l5);
                } else {
                }
                t2 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t2;
                goto loop_54;
            } else {
            }
        }
    }
    std_string_builder_append(l1, 1u);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_c_emit_emit_forward_decls(void* l0, void* l1) {
    void* l2 = NULL;
    size_t l3, l4;
    int32_t l5;
    vader_string_t l6 = 0;
    vader_string_t l8 = 0;
    vader_string_t l9 = 0;
    bool l7;
    bool t0;
    void* t1 = NULL;
    int64_t t2;
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t1 };
    vader_string_t* gc_atom_roots[3] = { &l6, &l8, &l9 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_functions;
    l3 = ((vader_array_t*) l2)->length;
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_8: {
            if ((l4 < l3)) {
                l5 = ((int32_t) (size_t) l4);
                l6 = vader_c_emit_fn_linkage_prefix(l0, l5);
                if (l6 == 0u) {
                    l7 = true;
                } else {
                    t0 = ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_split;
                    l7 = !(t0);
                }
                if (l7) {
                    vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
                    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                    if ((size_t) l4 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                    t1 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
                    l8 = vader_c_emit_signature_for(t1);
                    l9 = concat_3(l6, l8, 495u);
                    std_string_builder_append(l1, l9);
                } else {
                }
                t2 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t2;
                goto loop_8;
            } else {
            }
        }
    }
    std_string_builder_append(l1, 1u);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_c_emit_emit_function_body(void* l0, int32_t l1, void* l2, void* l3) {
    bool l4, l15, l17, l22, l25;
    vader_string_t l5 = 0;
    vader_string_t l6 = 0;
    vader_string_t l21 = 0;
    vader_string_t l36 = 0;
    vader_string_t l37 = 0;
    vader_string_t l38 = 0;
    vader_string_t l39 = 0;
    vader_string_t l40 = 0;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    void* l28 = NULL;
    void* l29 = NULL;
    void* l30 = NULL;
    void* l32 = NULL;
    void* l34 = NULL;
    int32_t l11, l27;
    size_t l12, l13, l18, l19, l23, l24, l26;
    vader_box_t l14 = vader_box_null(), l16 = vader_box_null();
    int64_t l20;
    uint64_t l31, l33, l35;
    bool t0;
    void* t1 = NULL;
    int64_t t2;
    int32_t t3;
    vader_string_t t4 = 0;
    vader_box_t t5 = vader_box_null();
    size_t t6;
    vader_box_t* gc_roots[3] = { &l14, &l16, &t5 };
    void** gc_raw_roots[13] = { &l0, &l2, &l3, &l7, &l8, &l9, &l10, &l28, &l29, &l30, &l32, &l34, &t1 };
    vader_string_t* gc_atom_roots[9] = { &l5, &l6, &l21, &l36, &l37, &l38, &l39, &l40, &t4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 13u, gc_roots, gc_raw_roots, 0u, NULL, 9u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = std_core____Contains_contains__i32(((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_may_alloc, l1);
    if (!(t0)) {
        t0 = vader_c_emit_fn_builds_stack_object(l2);
        l4 = !(t0);
    } else {
        l4 = false;
    }
    l5 = vader_c_emit_fn_linkage_prefix(l0, l1);
    l6 = vader_c_emit_signature_for(l2);
    l5 = concat_3(l5, l6, 175u);
    std_string_builder_append(l3, l5);
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 167u);
    t1 = (void*) _a0_arr;
    vader_struct_std_string_builder_StringBuilder_t* _a1_obj = (vader_struct_std_string_builder_StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string_builder_StringBuilder_t));
    vader_obj_header_init(_a1_obj, 389u);
    _a1_obj->f_parts = t1;
    l7 = (void*) _a1_obj;
    l8 = vader_c_emit_new_fn_state(l0, l2, l7);
    ((vader_struct_vader_c_emit_FnState_t*) l8)->f_no_frame = l4;
    VADER_WRITE_BARRIER((vader_struct_vader_c_emit_FnState_t*) l8);
    l9 = vader_c_emit_precompute_scopes(l2);
    ((vader_struct_vader_c_emit_FnState_t*) l8)->f_scopes = l9;
    VADER_WRITE_BARRIER((vader_struct_vader_c_emit_FnState_t*) l8);
    l9 = ((vader_struct_vader_c_emit_FnState_t*) l8)->f_scopes;
    l9 = vader_c_emit_precompute_branch_targets(l2, l9);
    l10 = ((vader_struct_vader_c_emit_BranchTargets_t*) l9)->f_continue_targets;
    ((vader_struct_vader_c_emit_FnState_t*) l8)->f_continue_targets = l10;
    VADER_WRITE_BARRIER((vader_struct_vader_c_emit_FnState_t*) l8);
    l9 = ((vader_struct_vader_c_emit_BranchTargets_t*) l9)->f_break_targets;
    ((vader_struct_vader_c_emit_FnState_t*) l8)->f_break_targets = l9;
    VADER_WRITE_BARRIER((vader_struct_vader_c_emit_FnState_t*) l8);
    l11 = -(INT32_C(1));
    l5 = 0u;
    l12 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l2)->f_body)->length;
    l13 = (size_t) (int64_t) INT64_C(0);
    {
        loop_71: {
            if ((l13 < l12)) {
                vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l2)->f_body);
                if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                if ((size_t) l13 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                l14 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l13);
                t0 = ((vader_struct_vader_c_emit_FnState_t*) l8)->f_drop_call_result;
                if (t0) {
                    l15 = l14.tag == 541u;
                } else {
                    l15 = false;
                }
                if (l15) {
                    ((vader_struct_vader_c_emit_FnState_t*) l8)->f_drop_call_result = false;
                    VADER_WRITE_BARRIER((vader_struct_vader_c_emit_FnState_t*) l8);
                    t2 = (l13 + INT64_C(1));
                    l13 = (size_t) (int64_t) t2;
                    goto loop_71;
                }
                t0 = ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_release;
                if (!(t0)) {
                    vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l2)->f_debug);
                    if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                    if ((size_t) l13 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                    l16 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l13);
                    if (!(l16.tag == 0u)) {
                        t1 = l16.payload.obj;
                        t3 = ((vader_struct_vader_bytecode_DebugPos_t*) t1)->f_line;
                        if (t3 != l11) {
                            l17 = true;
                        } else {
                            t1 = l16.payload.obj;
                            t4 = ((vader_struct_vader_bytecode_DebugPos_t*) t1)->f_file;
                            l17 = t4 != l5;
                        }
                        if (l17) {
                            t1 = l16.payload.obj;
                            t4 = ((vader_struct_vader_bytecode_DebugPos_t*) t1)->f_file;
                            l6 = vader_c_emit_c_string_lit(t4);
                            l18 = vader_host_std_core_byte_len(l6);
                            l9 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(28) + l18));
                            l19 = (size_t) (int64_t) INT64_C(0);
                            l19 = std_core_write_string_at(l9, l19, 240u);
                            t1 = l16.payload.obj;
                            t3 = ((vader_struct_vader_bytecode_DebugPos_t*) t1)->f_line;
                            l20 = ((int64_t) (int32_t) t3);
                            l19 = std_core_write_int(l9, l19, l20);
                            l19 = std_core_write_string_at(l9, l19, 6u);
                            l19 = std_core_write_string_at(l9, l19, l6);
                            l19 = std_core_write_string_at(l9, l19, 1u);
                            l21 = std_core_finish_buffer(l9, l19);
                            std_string_builder_append(l7, l21);
                            t1 = l16.payload.obj;
                            l11 = ((vader_struct_vader_bytecode_DebugPos_t*) t1)->f_line;
                            t1 = l16.payload.obj;
                            l5 = ((vader_struct_vader_bytecode_DebugPos_t*) t1)->f_file;
                        } else {
                        }
                    } else {
                    }
                } else {
                }
                if (l14.tag == 532u) {
                    l22 = true;
                } else {
                    l22 = l14.tag == 533u;
                }
                if (l22) {
                    t2 = (l13 + INT64_C(1));
                    l23 = (size_t) (int64_t) t2;
                    l24 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l2)->f_body)->length;
                    if ((l23 < l24)) {
                        l10 = ((vader_struct_vader_bytecode_BcFunction_t*) l2)->f_body;
                        t2 = (l13 + INT64_C(1));
                        l26 = (size_t) (int64_t) t2;
                        vader_array_t* _a4_slotarr = ((vader_array_t*) l10);
                        if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                        if ((size_t) l26 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                        t5 = vader_array_ref_load_box(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l26);
                        l25 = t5.tag == 541u;
                    } else {
                        l25 = false;
                    }
                    if (l25) {
                        ((vader_struct_vader_c_emit_FnState_t*) l8)->f_drop_call_result = true;
                        VADER_WRITE_BARRIER((vader_struct_vader_c_emit_FnState_t*) l8);
                    } else {
                    }
                } else {
                }
                l27 = ((int32_t) (size_t) l13);
                vader_c_emit_emit_op(l8, l27, l14);
                t2 = (l13 + INT64_C(1));
                l13 = (size_t) (int64_t) t2;
                goto loop_71;
            } else {
            }
        }
    }
    l5 = std_string_builder_StringBuilder_Display_to_string(l7);
    l7 = ((vader_struct_vader_c_emit_FnState_t*) l8)->f_tmp_types;
    l7 = vader_c_emit_coalesce_temps(l5, l7);
    l9 = ((vader_struct_vader_c_emit_CoalesceResult_t*) l7)->f_types;
    ((vader_struct_vader_c_emit_FnState_t*) l8)->f_tmp_types = l9;
    VADER_WRITE_BARRIER((vader_struct_vader_c_emit_FnState_t*) l8);
    vader_array_t* _a5_arr = vader_array_new(8u, 0u, 0u, 167u);
    l9 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(8u, 0u, 0u, 167u);
    l10 = (void*) _a6_arr;
    vader_array_t* _a7_arr = vader_array_new(8u, 0u, 0u, 167u);
    l28 = (void*) _a7_arr;
    if (!(l4)) {
        l29 = ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l2)->f_signature)->f_params;
        l12 = ((vader_array_t*) l29)->length;
        l13 = (size_t) (int64_t) INT64_C(0);
        {
            loop_295: {
                if ((l13 < l12)) {
                    vader_array_t* _a8_slotarr = ((vader_array_t*) l29);
                    if (_a8_slotarr->buf != NULL && _a8_slotarr->buf->header.forward != NULL) { _a8_slotarr->buf = vader_array_buf_forward(_a8_slotarr->buf); }
                    if ((size_t) l13 >= _a8_slotarr->length) { vader_trap("array index out of bounds"); }
                    t5 = vader_array_read_u8(_a8_slotarr, _a8_slotarr->offset + (size_t) l13, 173u);
                    if (((int32_t) t5.payload.i) == INT32_C(18)) {
                        l30 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(22));
                        l18 = (size_t) (int64_t) INT64_C(0);
                        l18 = std_core_write_string_at(l30, l18, 259u);
                        t2 = ((int64_t) (size_t) l13);
                        l31 = (uint64_t) (int64_t) t2;
                        l18 = std_core_write_unsigned(l30, l18, l31);
                        l5 = std_core_finish_buffer(l30, l18);
                        vader_array_push((vader_array_t*) l10, vader_box_string(167u, l5));
                    } else {
                        vader_array_t* _a9_slotarr = ((vader_array_t*) l29);
                        if (_a9_slotarr->buf != NULL && _a9_slotarr->buf->header.forward != NULL) { _a9_slotarr->buf = vader_array_buf_forward(_a9_slotarr->buf); }
                        if ((size_t) l13 >= _a9_slotarr->length) { vader_trap("array index out of bounds"); }
                        t5 = vader_array_read_u8(_a9_slotarr, _a9_slotarr->offset + (size_t) l13, 173u);
                        if (((int32_t) t5.payload.i) == INT32_C(14)) {
                            l32 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(22));
                            l19 = (size_t) (int64_t) INT64_C(0);
                            l19 = std_core_write_string_at(l32, l19, 259u);
                            t2 = ((int64_t) (size_t) l13);
                            l33 = (uint64_t) (int64_t) t2;
                            l19 = std_core_write_unsigned(l32, l19, l33);
                            l6 = std_core_finish_buffer(l32, l19);
                            vader_array_push((vader_array_t*) l28, vader_box_string(167u, l6));
                        } else {
                            vader_array_t* _a10_slotarr = ((vader_array_t*) l29);
                            if (_a10_slotarr->buf != NULL && _a10_slotarr->buf->header.forward != NULL) { _a10_slotarr->buf = vader_array_buf_forward(_a10_slotarr->buf); }
                            if ((size_t) l13 >= _a10_slotarr->length) { vader_trap("array index out of bounds"); }
                            t5 = vader_array_read_u8(_a10_slotarr, _a10_slotarr->offset + (size_t) l13, 173u);
                            t0 = vader_c_emit_is_ref_val(((uint8_t) t5.payload.i));
                            if (t0) {
                                l34 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(22));
                                l23 = (size_t) (int64_t) INT64_C(0);
                                l23 = std_core_write_string_at(l34, l23, 259u);
                                t2 = ((int64_t) (size_t) l13);
                                l35 = (uint64_t) (int64_t) t2;
                                l23 = std_core_write_unsigned(l34, l23, l35);
                                l21 = std_core_finish_buffer(l34, l23);
                                vader_array_push((vader_array_t*) l9, vader_box_string(167u, l21));
                            } else {
                            }
                        }
                    }
                    t2 = (l13 + INT64_C(1));
                    l13 = (size_t) (int64_t) t2;
                    goto loop_295;
                } else {
                }
            }
        }
    } else {
    }
    vader_c_emit_emit_local_decls(l2, l3, l9, l10, l28, l4);
    vader_c_emit_emit_tmp_decls(l8, l3, l9, l10, l28, l4);
    if (!(l4)) {
        t6 = ((vader_array_t*) l9)->length;
        if ((t6 > INT64_C(0))) {
            l5 = std_string_join(l9, 365u);
            l12 = vader_host_std_core_byte_len(l5);
            l29 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(56) + l12));
            l12 = (size_t) (int64_t) INT64_C(0);
            l12 = std_core_write_string_at(l29, l12, 24u);
            t6 = ((vader_array_t*) l9)->length;
            t2 = ((int64_t) (size_t) t6);
            l31 = (uint64_t) (int64_t) t2;
            l12 = std_core_write_unsigned(l29, l12, l31);
            l12 = std_core_write_string_at(l29, l12, 853u);
            l12 = std_core_write_string_at(l29, l12, l5);
            l12 = std_core_write_string_at(l29, l12, 209u);
            l5 = std_core_finish_buffer(l29, l12);
            std_string_builder_append(l3, l5);
        } else {
        }
        t6 = ((vader_array_t*) l10)->length;
        if ((t6 > INT64_C(0))) {
            l5 = std_string_join(l10, 365u);
            l12 = vader_host_std_core_byte_len(l5);
            l29 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(54) + l12));
            l12 = (size_t) (int64_t) INT64_C(0);
            l12 = std_core_write_string_at(l29, l12, 36u);
            t6 = ((vader_array_t*) l10)->length;
            t2 = ((int64_t) (size_t) t6);
            l31 = (uint64_t) (int64_t) t2;
            l12 = std_core_write_unsigned(l29, l12, l31);
            l12 = std_core_write_string_at(l29, l12, 853u);
            l12 = std_core_write_string_at(l29, l12, l5);
            l12 = std_core_write_string_at(l29, l12, 209u);
            l5 = std_core_finish_buffer(l29, l12);
            std_string_builder_append(l3, l5);
        } else {
        }
        t6 = ((vader_array_t*) l9)->length;
        if ((t6 > INT64_C(0))) {
            l5 = 1622u;
        } else {
            l5 = 651u;
        }
        t6 = ((vader_array_t*) l10)->length;
        if ((t6 > INT64_C(0))) {
            l6 = 1621u;
        } else {
            l6 = 651u;
        }
        l12 = ((vader_array_t*) ((vader_struct_vader_c_emit_FnState_t*) l8)->f_stack_storages)->length;
        if ((l12 > INT64_C(0))) {
            l21 = 1623u;
        } else {
            l21 = 651u;
        }
        vader_array_t* _a11_arr = vader_array_new(8u, 0u, 0u, 167u);
        l29 = (void*) _a11_arr;
        l8 = ((vader_struct_vader_c_emit_FnState_t*) l8)->f_stack_storages;
        l13 = ((vader_array_t*) l8)->length;
        l18 = (size_t) (int64_t) INT64_C(0);
        {
            loop_581: {
                if ((l18 < l13)) {
                    vader_array_t* _a12_slotarr = ((vader_array_t*) l8);
                    if (_a12_slotarr->buf != NULL && _a12_slotarr->buf->header.forward != NULL) { _a12_slotarr->buf = vader_array_buf_forward(_a12_slotarr->buf); }
                    if ((size_t) l18 >= _a12_slotarr->length) { vader_trap("array index out of bounds"); }
                    l30 = vader_array_ref_load_obj(_a12_slotarr->buf, _a12_slotarr->offset + (size_t) l18);
                    l36 = ((vader_struct_vader_c_emit_StackStorage_t*) l30)->f_cname;
                    l37 = ((vader_struct_vader_c_emit_StackStorage_t*) l30)->f_storage;
                    l38 = concat_5(7u, l36, 6u, l37, 89u);
                    std_string_builder_append(l3, l38);
                    l39 = ((vader_struct_vader_c_emit_StackStorage_t*) l30)->f_storage;
                    l40 = concat_2(315u, l39);
                    vader_array_push((vader_array_t*) l29, vader_box_string(167u, l40));
                    t2 = (l18 + INT64_C(1));
                    l18 = (size_t) (int64_t) t2;
                    goto loop_581;
                } else {
                }
            }
        }
        if ((l12 > INT64_C(0))) {
            l36 = std_string_join(l29, 365u);
            l13 = vader_host_std_core_byte_len(l36);
            l8 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(54) + l13));
            l13 = (size_t) (int64_t) INT64_C(0);
            l13 = std_core_write_string_at(l8, l13, 35u);
            t2 = ((int64_t) (size_t) l12);
            l31 = (uint64_t) (int64_t) t2;
            l13 = std_core_write_unsigned(l8, l13, l31);
            l13 = std_core_write_string_at(l8, l13, 853u);
            l13 = std_core_write_string_at(l8, l13, l36);
            l13 = std_core_write_string_at(l8, l13, 209u);
            l36 = std_core_finish_buffer(l8, l13);
            std_string_builder_append(l3, l36);
        } else {
        }
        l13 = ((vader_array_t*) l28)->length;
        if ((l13 > INT64_C(0))) {
            l36 = 1620u;
        } else {
            l36 = 651u;
        }
        if ((l13 > INT64_C(0))) {
            l37 = std_string_join(l28, 365u);
            l18 = vader_host_std_core_byte_len(l37);
            l8 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(64) + l18));
            l18 = (size_t) (int64_t) INT64_C(0);
            l18 = std_core_write_string_at(l8, l18, 31u);
            t2 = ((int64_t) (size_t) l13);
            l31 = (uint64_t) (int64_t) t2;
            l18 = std_core_write_unsigned(l8, l18, l31);
            l18 = std_core_write_string_at(l8, l18, 853u);
            l18 = std_core_write_string_at(l8, l18, l37);
            l18 = std_core_write_string_at(l8, l18, 209u);
            l37 = std_core_finish_buffer(l8, l18);
            std_string_builder_append(l3, l37);
        } else {
        }
        if ((l13 > INT64_C(0))) {
            l37 = l36;
            l18 = vader_host_std_core_byte_len(l37);
            l8 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(25) + l18));
            l18 = (size_t) (int64_t) INT64_C(0);
            l18 = std_core_write_string_at(l8, l18, 365u);
            t2 = ((int64_t) (size_t) l13);
            l31 = (uint64_t) (int64_t) t2;
            l18 = std_core_write_unsigned(l8, l18, l31);
            l18 = std_core_write_string_at(l8, l18, 2209u);
            l18 = std_core_write_string_at(l8, l18, l37);
            l36 = std_core_finish_buffer(l8, l18);
        } else {
            l36 = 0u;
        }
        l13 = vader_host_std_core_byte_len(l5);
        l18 = vader_host_std_core_byte_len(l6);
        t2 = (l13 + l18);
        l13 = (size_t) (int64_t) t2;
        l18 = vader_host_std_core_byte_len(l21);
        t2 = (l13 + l18);
        l13 = (size_t) (int64_t) t2;
        l18 = vader_host_std_core_byte_len(l36);
        t2 = (l13 + l18);
        l13 = (size_t) (int64_t) t2;
        l8 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(125) + l13));
        l13 = (size_t) (int64_t) INT64_C(0);
        l13 = std_core_write_string_at(l8, l13, 25u);
        t6 = ((vader_array_t*) l9)->length;
        t2 = ((int64_t) (size_t) t6);
        l31 = (uint64_t) (int64_t) t2;
        l13 = std_core_write_unsigned(l8, l13, l31);
        l13 = std_core_write_string_at(l8, l13, 2209u);
        t6 = ((vader_array_t*) l10)->length;
        t2 = ((int64_t) (size_t) t6);
        l31 = (uint64_t) (int64_t) t2;
        l13 = std_core_write_unsigned(l8, l13, l31);
        l13 = std_core_write_string_at(l8, l13, 2209u);
        l13 = std_core_write_string_at(l8, l13, l5);
        l13 = std_core_write_string_at(l8, l13, 365u);
        l13 = std_core_write_string_at(l8, l13, l6);
        l13 = std_core_write_string_at(l8, l13, 365u);
        t2 = ((int64_t) (size_t) l12);
        l31 = (uint64_t) (int64_t) t2;
        l13 = std_core_write_unsigned(l8, l13, l31);
        l13 = std_core_write_string_at(l8, l13, 2209u);
        l13 = std_core_write_string_at(l8, l13, l21);
        l13 = std_core_write_string_at(l8, l13, l36);
        l13 = std_core_write_string_at(l8, l13, 209u);
        l5 = std_core_finish_buffer(l8, l13);
        std_string_builder_append(l3, l5);
        std_string_builder_append(l3, 26u);
    } else {
    }
    l5 = ((vader_struct_vader_c_emit_CoalesceResult_t*) l7)->f_body;
    std_string_builder_append(l3, l5);
    if (!(l4)) {
        std_string_builder_append(l3, 28u);
    } else {
    }
    std_string_builder_append(l3, 2426u);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_c_emit_emit_global_const_roots(void* l0, void* l1) {
    void* l2 = NULL;
    void* l7 = NULL;
    vader_string_t l3 = 0;
    vader_string_t l4 = 0;
    vader_string_t l10 = 0;
    size_t l5, l6, l8;
    uint64_t l9;
    size_t t0;
    bool t1;
    int64_t t2, t3;
    vader_box_t t4 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t4 };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &l7 };
    vader_string_t* gc_atom_roots[3] = { &l3, &l4, &l10 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = vader_c_emit_mutable_pool_indices(((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_data_pool);
    t0 = ((vader_array_t*) l2)->length;
    if (t0 == INT64_C(0)) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    t1 = ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_split;
    l3 = vader_c_emit_linkage_prefix(t1);
    l4 = concat_2(l3, 2318u);
    std_string_builder_append(l1, l4);
    l5 = ((vader_array_t*) l2)->length;
    l6 = (size_t) (int64_t) INT64_C(0);
    {
        loop_26: {
            if ((l6 < l5)) {
                if ((l6 > INT64_C(0))) {
                    std_string_builder_append(l1, 364u);
                } else {
                }
                l7 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(33));
                l8 = (size_t) (int64_t) INT64_C(0);
                l8 = std_core_write_string_at(l7, l8, 43u);
                vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
                if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                if ((size_t) l6 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                t2 = ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l6];
                t3 = t2;
                l9 = (uint64_t) (int64_t) t3;
                l8 = std_core_write_unsigned(l7, l8, l9);
                l4 = std_core_finish_buffer(l7, l8);
                std_string_builder_append(l1, l4);
                t2 = (l6 + INT64_C(1));
                l6 = (size_t) (int64_t) t2;
                goto loop_26;
            } else {
            }
        }
    }
    std_string_builder_append(l1, 209u);
    l2 = vader_c_emit_boxed_pool_objects(((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_data_pool, l2);
    l4 = concat_2(l3, 2388u);
    std_string_builder_append(l1, l4);
    l5 = ((vader_array_t*) l2)->length;
    l6 = (size_t) (int64_t) INT64_C(0);
    {
        loop_97: {
            if ((l6 < l5)) {
                if ((l6 > INT64_C(0))) {
                    std_string_builder_append(l1, 364u);
                } else {
                }
                vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l6 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                t4 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l6];
                l4 = t4.payload.s;
                l10 = concat_2(6u, l4);
                std_string_builder_append(l1, l10);
                t2 = (l6 + INT64_C(1));
                l6 = (size_t) (int64_t) t2;
                goto loop_97;
            } else {
            }
        }
    }
    std_string_builder_append(l1, 209u);
    l3 = concat_2(l3, 2350u);
    std_string_builder_append(l1, l3);
    l7 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(78));
    l5 = (size_t) (int64_t) INT64_C(0);
    l5 = std_core_write_string_at(l7, l5, 2418u);
    t0 = ((vader_array_t*) l2)->length;
    t2 = ((int64_t) (size_t) t0);
    l9 = (uint64_t) (int64_t) t2;
    l5 = std_core_write_unsigned(l7, l5, l9);
    l5 = std_core_write_string_at(l7, l5, 2226u);
    l3 = std_core_finish_buffer(l7, l5);
    std_string_builder_append(l1, l3);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_c_emit_emit_if_open(void* l0) {
    vader_box_t l1 = vader_box_null();
    vader_string_t l2 = 0;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[1] = { &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l1 = vader_c_emit_pop(l0);
    vader_c_emit_assert_stack_empty(l0, 1698u);
    l2 = vader_c_emit_name_of(l1);
    l2 = concat_3(1693u, l2, 333u);
    vader_c_emit_line(l0, l2);
    vader_c_emit_indent_push(l0);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_c_emit_emit_import_shims(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l8 = NULL;
    void* l14 = NULL;
    size_t l6, l7;
    bool l9;
    vader_string_t l10 = 0;
    vader_string_t l11 = 0;
    vader_string_t l12 = 0;
    vader_string_t l13 = 0;
    vader_string_t l15 = 0;
    vader_string_t l17 = 0;
    int32_t l16;
    bool t0;
    vader_string_t t1 = 0;
    int64_t t2;
    size_t t3;
    vader_box_t t4 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t4 };
    void** gc_raw_roots[8] = { &l0, &l1, &l2, &l3, &l4, &l5, &l8, &l14 };
    vader_string_t* gc_atom_roots[7] = { &l10, &l11, &l12, &l13, &l15, &l17, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 7u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_split;
    if (t0) {
        vader_c_emit_emit_mirrored_struct_typedefs(l0, l1);
    } else {
    }
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 167u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(8u, 0u, 0u, 167u);
    l3 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(8u, 0u, 0u, 167u);
    l4 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(8u, 0u, 0u, 167u);
    l5 = (void*) _a3_arr;
    l6 = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_imports)->length;
    l7 = (size_t) (int64_t) INT64_C(0);
    {
        loop_23: {
            if ((l7 < l6)) {
                vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_imports);
                if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                if ((size_t) l7 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
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
                    vader_array_push((vader_array_t*) l3, vader_box_string(167u, l11));
                    t1 = ((vader_struct_vader_bytecode_BcImport_t*) l8)->f_c_header;
                    if (t1 != 0u) {
                        l12 = ((vader_struct_vader_bytecode_BcImport_t*) l8)->f_c_header;
                        t0 = std_core____Contains_contains__string(l4, l12);
                        if (!(t0)) {
                            l13 = ((vader_struct_vader_bytecode_BcImport_t*) l8)->f_c_header;
                            vader_array_push((vader_array_t*) l4, vader_box_string(167u, l13));
                        } else {
                        }
                    } else {
                        l14 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_types;
                        l15 = vader_c_emit_extern_decl(l8, l14);
                        vader_array_push((vader_array_t*) l2, vader_box_string(167u, l15));
                    }
                } else {
                }
                l16 = ((int32_t) (size_t) l7);
                l17 = vader_c_emit_import_shim(l0, l8, l16);
                vader_array_push((vader_array_t*) l5, vader_box_string(167u, l17));
                t2 = (l7 + INT64_C(1));
                l7 = (size_t) (int64_t) t2;
                goto loop_23;
            } else {
            }
        }
    }
    t3 = ((vader_array_t*) l4)->length;
    if ((t3 > INT64_C(0))) {
        std_string_builder_append(l1, 436u);
        l3 = l4;
        l6 = ((vader_array_t*) l3)->length;
        l7 = (size_t) (int64_t) INT64_C(0);
        {
            loop_126: {
                if ((l7 < l6)) {
                    vader_array_t* _a5_slotarr = ((vader_array_t*) l3);
                    if (_a5_slotarr->buf != NULL && _a5_slotarr->buf->header.forward != NULL) { _a5_slotarr->buf = vader_array_buf_forward(_a5_slotarr->buf); }
                    if ((size_t) l7 >= _a5_slotarr->length) { vader_trap("array index out of bounds"); }
                    t4 = vader_array_box_slots(_a5_slotarr->buf)[_a5_slotarr->offset + (size_t) l7];
                    l10 = t4.payload.s;
                    l11 = concat_3(233u, l10, 1u);
                    std_string_builder_append(l1, l11);
                    t2 = (l7 + INT64_C(1));
                    l7 = (size_t) (int64_t) t2;
                    goto loop_126;
                } else {
                }
            }
        }
        std_string_builder_append(l1, 1u);
    } else {
    }
    t3 = ((vader_array_t*) l2)->length;
    if ((t3 > INT64_C(0))) {
        std_string_builder_append(l1, 438u);
        l6 = ((vader_array_t*) l2)->length;
        l7 = (size_t) (int64_t) INT64_C(0);
        {
            loop_172: {
                if ((l7 < l6)) {
                    vader_array_t* _a6_slotarr = ((vader_array_t*) l2);
                    if (_a6_slotarr->buf != NULL && _a6_slotarr->buf->header.forward != NULL) { _a6_slotarr->buf = vader_array_buf_forward(_a6_slotarr->buf); }
                    if ((size_t) l7 >= _a6_slotarr->length) { vader_trap("array index out of bounds"); }
                    t4 = vader_array_box_slots(_a6_slotarr->buf)[_a6_slotarr->offset + (size_t) l7];
                    t1 = t4.payload.s;
                    l10 = concat_2(t1, 1u);
                    std_string_builder_append(l1, l10);
                    t2 = (l7 + INT64_C(1));
                    l7 = (size_t) (int64_t) t2;
                    goto loop_172;
                } else {
                }
            }
        }
        std_string_builder_append(l1, 1u);
    } else {
    }
    l2 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_types;
    l3 = vader_c_emit_crossing_mirrors(((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module);
    l2 = vader_c_emit_c_struct_layout_asserts(l2, l3);
    t3 = ((vader_array_t*) l2)->length;
    if ((t3 > INT64_C(0))) {
        std_string_builder_append(l1, 439u);
        l6 = ((vader_array_t*) l2)->length;
        l7 = (size_t) (int64_t) INT64_C(0);
        {
            loop_224: {
                if ((l7 < l6)) {
                    vader_array_t* _a7_slotarr = ((vader_array_t*) l2);
                    if (_a7_slotarr->buf != NULL && _a7_slotarr->buf->header.forward != NULL) { _a7_slotarr->buf = vader_array_buf_forward(_a7_slotarr->buf); }
                    if ((size_t) l7 >= _a7_slotarr->length) { vader_trap("array index out of bounds"); }
                    t4 = vader_array_box_slots(_a7_slotarr->buf)[_a7_slotarr->offset + (size_t) l7];
                    t1 = t4.payload.s;
                    l10 = concat_2(t1, 1u);
                    std_string_builder_append(l1, l10);
                    t2 = (l7 + INT64_C(1));
                    l7 = (size_t) (int64_t) t2;
                    goto loop_224;
                } else {
                }
            }
        }
        std_string_builder_append(l1, 1u);
    } else {
    }
    l2 = l5;
    l6 = ((vader_array_t*) l2)->length;
    l7 = (size_t) (int64_t) INT64_C(0);
    {
        loop_260: {
            if ((l7 < l6)) {
                vader_array_t* _a8_slotarr = ((vader_array_t*) l2);
                if (_a8_slotarr->buf != NULL && _a8_slotarr->buf->header.forward != NULL) { _a8_slotarr->buf = vader_array_buf_forward(_a8_slotarr->buf); }
                if ((size_t) l7 >= _a8_slotarr->length) { vader_trap("array index out of bounds"); }
                t4 = vader_array_box_slots(_a8_slotarr->buf)[_a8_slotarr->offset + (size_t) l7];
                t1 = t4.payload.s;
                l10 = concat_2(t1, 1u);
                std_string_builder_append(l1, l10);
                t2 = (l7 + INT64_C(1));
                l7 = (size_t) (int64_t) t2;
                goto loop_260;
            } else {
            }
        }
    }
    std_string_builder_append(l1, 1u);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_c_emit_emit_internal_forward_decls(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    void* l5 = NULL;
    bool l4;
    size_t l6, l7, l9;
    int32_t l8;
    vader_string_t l10 = 0;
    vader_string_t l11 = 0;
    vader_string_t t0 = 0;
    int64_t t1;
    void* t2 = NULL;
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l3, &l5, &t2 };
    vader_string_t* gc_atom_roots[3] = { &l10, &l11, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 6u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_functions;
    l4 = false;
    l5 = l1;
    l6 = ((vader_array_t*) l5)->length;
    l7 = (size_t) (int64_t) INT64_C(0);
    {
        loop_12: {
            if ((l7 < l6)) {
                vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
                if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                if ((size_t) l7 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                l8 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l7];
                t0 = vader_c_emit_fn_linkage_prefix(l0, l8);
                if (t0 != 0u) {
                    t1 = ((int64_t) (int32_t) l8);
                    l9 = (size_t) (int64_t) t1;
                    vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
                    if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                    if ((size_t) l9 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                    t2 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l9);
                    l10 = vader_c_emit_signature_for(t2);
                    l11 = concat_3(2030u, l10, 495u);
                    std_string_builder_append(l2, l11);
                    l4 = true;
                } else {
                }
                t1 = (l7 + INT64_C(1));
                l7 = (size_t) (int64_t) t1;
                goto loop_12;
            } else {
            }
        }
    }
    if (l4) {
        std_string_builder_append(l2, 1u);
    } else {
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
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
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 10u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l6 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_locals;
    l7 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_signature)->f_params)->length;
    vader_array_t* _a0_arr = vader_array_new(11u, 0u, 1u, 173u);
    l8 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(8u, 0u, 0u, 167u);
    l9 = (void*) _a1_arr;
    l10 = ((vader_array_t*) l6)->length;
    l11 = (size_t) (int64_t) INT64_C(0);
    {
        loop_16: {
            if ((l11 < l10)) {
                vader_array_t* _a2_slotarr = ((vader_array_t*) l6);
                if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                if ((size_t) l11 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l11);
                if (((vader_struct_vader_bytecode_BcLocal_t*) t0)->f_val == INT32_C(16)) {
                    t1 = (l11 + INT64_C(1));
                    l11 = (size_t) (int64_t) t1;
                    goto loop_16;
                }
                vader_array_t* _a3_slotarr = ((vader_array_t*) l6);
                if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                if ((size_t) l11 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l11);
                l12 = ((vader_struct_vader_bytecode_BcLocal_t*) t0)->f_val;
                vader_array_push_u8((vader_array_t*) l8, (int32_t) (uint8_t) l12);
                l13 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(21));
                l14 = (size_t) (int64_t) INT64_C(0);
                l14 = std_core_write_string_at(l13, l14, 1796u);
                t1 = (l7 + l11);
                l15 = (uint64_t) (int64_t) t1;
                l14 = std_core_write_unsigned(l13, l14, l15);
                l16 = std_core_finish_buffer(l13, l14);
                vader_array_push((vader_array_t*) l9, vader_box_string(167u, l16));
                t1 = (l11 + INT64_C(1));
                l11 = (size_t) (int64_t) t1;
                goto loop_16;
            } else {
            }
        }
    }
    vader_c_emit_emit_slot_decls(l1, l8, l9, l2, l3, l4, l5);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_c_emit_emit_local_field(void* l0, void* l1) {
    int32_t l2, l3, l8;
    void* l4 = NULL;
    size_t l5;
    int64_t l6;
    vader_string_t l7 = 0;
    uint8_t l9;
    int32_t t0;
    void** gc_raw_roots[3] = { &l0, &l1, &l4 };
    vader_string_t* gc_atom_roots[1] = { &l7 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_bytecode_LocalField_t*) l1)->f_type_id;
    l3 = ((vader_struct_vader_bytecode_LocalField_t*) l1)->f_field_index;
    l4 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(21));
    l5 = (size_t) (int64_t) INT64_C(0);
    l5 = std_core_write_string_at(l4, l5, 1796u);
    t0 = ((vader_struct_vader_bytecode_LocalField_t*) l1)->f_slot;
    l6 = ((int64_t) (int32_t) t0);
    l5 = std_core_write_int(l4, l5, l6);
    l7 = std_core_finish_buffer(l4, l5);
    l4 = ((vader_struct_vader_c_emit_FnState_t*) l0)->f_function;
    l8 = ((vader_struct_vader_bytecode_LocalField_t*) l1)->f_slot;
    l9 = vader_c_emit_slot_val_type(l4, l8);
    vader_c_emit_push_struct_field(l0, l2, l3, l7, l9);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
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
    vader_gc_top = gc_frame.prev;
}

static void vader_c_emit_emit_local_set(void* l0, int32_t l1, bool l2) {
    uint8_t l3, l7;
    vader_box_t l4 = vader_box_null();
    void* l5 = NULL;
    vader_string_t l6 = 0;
    size_t l8;
    int64_t l9;
    vader_box_t* gc_roots[1] = { &l4 };
    void** gc_raw_roots[2] = { &l0, &l5 };
    vader_string_t* gc_atom_roots[1] = { &l6 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l3 = vader_c_emit_slot_val_type(((vader_struct_vader_c_emit_FnState_t*) l0)->f_function, l1);
    if (l3 == INT32_C(16)) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_c_emit_materialize_stack_for_slot(l0, l1);
    l4 = vader_c_emit_pop(l0);
    l5 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_ctx)->f_module)->f_types;
    l6 = vader_c_emit_name_of(l4);
    l7 = vader_c_emit_val_of(l4);
    l6 = vader_c_emit_coerce_expr(l5, l6, l7, l3);
    l8 = vader_host_std_core_byte_len(l6);
    l5 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(25) + l8));
    l8 = (size_t) (int64_t) INT64_C(0);
    l8 = std_core_write_string_at(l5, l8, 1796u);
    l9 = ((int64_t) (int32_t) l1);
    l8 = std_core_write_int(l5, l8, l9);
    l8 = std_core_write_string_at(l5, l8, 61u);
    l8 = std_core_write_string_at(l5, l8, l6);
    l8 = std_core_write_string_at(l5, l8, 494u);
    l6 = std_core_finish_buffer(l5, l8);
    vader_c_emit_line(l0, l6);
    if (l2) {
        vader_c_emit_push_local_ref(l0, l1, l3);
    } else {
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_c_emit_emit_main(void* l0, void* l1, vader_string_t l2) {
    int32_t l3, l12;
    void* l4 = NULL;
    void* l8 = NULL;
    size_t l5, l9;
    vader_string_t l6 = 0;
    vader_string_t l11 = 0;
    vader_string_t l14 = 0;
    vader_string_t l17 = 0;
    vader_string_t l18 = 0;
    vader_string_t l19 = 0;
    vader_string_t l20 = 0;
    vader_string_t l21 = 0;
    vader_string_t l22 = 0;
    vader_string_t l23 = 0;
    vader_string_t l24 = 0;
    vader_string_t l25 = 0;
    bool l7;
    uint64_t l10;
    int64_t l13;
    uint8_t l15, l16;
    int64_t t0;
    vader_string_t t1 = 0;
    size_t t2;
    void* t3 = NULL;
    vader_box_t t4 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t4 };
    void** gc_raw_roots[5] = { &l0, &l1, &l4, &l8, &t3 };
    vader_string_t* gc_atom_roots[14] = { &l2, &l6, &l11, &l14, &l17, &l18, &l19, &l20, &l21, &l22, &l23, &l24, &l25, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 14u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l3 = vader_c_emit_find_main(((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module, l2);
    if ((l3 < INT32_C(0))) {
        std_string_builder_append(l1, 1725u);
        { vader_gc_top = gc_frame.prev; return; }
    }
    l4 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_functions;
    t0 = ((int64_t) (int32_t) l3);
    l5 = (size_t) (int64_t) t0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    if ((size_t) l5 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
    l4 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
    t1 = ((vader_struct_vader_bytecode_BcFunction_t*) l4)->f_name;
    l6 = vader_c_emit_sanitise(t1);
    t2 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l4)->f_signature)->f_params)->length;
    l7 = t2 == INT64_C(1);
    std_string_builder_append(l1, 1724u);
    std_string_builder_append(l1, 21u);
    t3 = vader_c_emit_mutable_pool_indices(((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_data_pool);
    l5 = ((vader_array_t*) t3)->length;
    if ((l5 > INT64_C(0))) {
        std_string_builder_append(l1, 27u);
        l8 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(81));
        l9 = (size_t) (int64_t) INT64_C(0);
        l9 = std_core_write_string_at(l8, l9, 22u);
        t0 = ((int64_t) (size_t) l5);
        l10 = (uint64_t) (int64_t) t0;
        l9 = std_core_write_unsigned(l8, l9, l10);
        l9 = std_core_write_string_at(l8, l9, 2206u);
        l11 = std_core_finish_buffer(l8, l9);
        std_string_builder_append(l1, l11);
    } else {
    }
    std_string_builder_append(l1, 14u);
    std_string_builder_append(l1, 15u);
    l11 = 0u;
    if (l7) {
        l3 = ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_string_tag;
        l12 = ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_string_array_tag;
        if ((l3 < INT32_C(0))) {
            l7 = true;
        } else {
            l7 = (l12 < INT32_C(0));
        }
        if (l7) {
            std_string_builder_append(l1, 12u);
            std_string_builder_append(l1, 2426u);
            { vader_gc_top = gc_frame.prev; return; }
        }
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l4)->f_signature)->f_params);
        if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
        if ((size_t) INT32_C(0) >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
        t4 = vader_array_read_u8(_a1_slotarr, _a1_slotarr->offset + (size_t) INT32_C(0), 173u);
        if (((int32_t) t4.payload.i) == INT32_C(18)) {
            l8 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(105));
            l5 = (size_t) (int64_t) INT64_C(0);
            l5 = std_core_write_string_at(l8, l5, 34u);
            l13 = ((int64_t) (int32_t) l12);
            l5 = std_core_write_int(l8, l5, l13);
            l5 = std_core_write_string_at(l8, l5, 2209u);
            l13 = ((int64_t) (int32_t) l3);
            l5 = std_core_write_int(l8, l5, l13);
            l5 = std_core_write_string_at(l8, l5, 2206u);
            l14 = std_core_finish_buffer(l8, l5);
            std_string_builder_append(l1, l14);
        } else {
            l8 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(141));
            l5 = (size_t) (int64_t) INT64_C(0);
            l5 = std_core_write_string_at(l8, l5, 23u);
            l13 = ((int64_t) (int32_t) l12);
            l5 = std_core_write_int(l8, l5, l13);
            l5 = std_core_write_string_at(l8, l5, 2227u);
            l13 = ((int64_t) (int32_t) l12);
            l5 = std_core_write_int(l8, l5, l13);
            l5 = std_core_write_string_at(l8, l5, 2209u);
            l13 = ((int64_t) (int32_t) l3);
            l5 = std_core_write_int(l8, l5, l13);
            l5 = std_core_write_string_at(l8, l5, 2204u);
            l14 = std_core_finish_buffer(l8, l5);
            std_string_builder_append(l1, l14);
        }
        l11 = 884u;
        l15 = ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l4)->f_signature)->f_result;
        l16 = (uint8_t) (int32_t) INT32_C(16);
        if (l15 == l16) {
            l14 = 7u;
            l17 = 278u;
            l18 = 350u;
            l19 = concat_5(l14, l6, l17, l11, l18);
            std_string_builder_append(l1, l19);
            l20 = 18u;
            std_string_builder_append(l1, l20);
        } else {
            l21 = 17u;
            l22 = 278u;
            l23 = 350u;
            l24 = concat_5(l21, l6, l22, l11, l23);
            std_string_builder_append(l1, l24);
        }
        l25 = 2426u;
        std_string_builder_append(l1, l25);
        { vader_gc_top = gc_frame.prev; return; }
    }
    std_string_builder_append(l1, 11u);
    l15 = ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l4)->f_signature)->f_result;
    l16 = (uint8_t) (int32_t) INT32_C(16);
    if (l15 == l16) {
        l14 = 7u;
        l17 = 278u;
        l18 = 350u;
        l19 = concat_5(l14, l6, l17, l11, l18);
        std_string_builder_append(l1, l19);
        l20 = 18u;
        std_string_builder_append(l1, l20);
    } else {
        l21 = 17u;
        l22 = 278u;
        l23 = 350u;
        l24 = concat_5(l21, l6, l22, l11, l23);
        std_string_builder_append(l1, l24);
    }
    l25 = 2426u;
    std_string_builder_append(l1, l25);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_c_emit_emit_make_closure(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null();
    vader_string_t l3 = 0;
    vader_string_t l4 = 0;
    size_t l5;
    void* l6 = NULL;
    int64_t l7;
    int32_t l8;
    int32_t t0;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[3] = { &l0, &l1, &l6 };
    vader_string_t* gc_atom_roots[2] = { &l3, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = vader_c_emit_pop(l0);
    l3 = vader_c_emit_aux(l0, 1368u);
    l4 = concat_3(2349u, l3, 68u);
    vader_c_emit_line(l0, l4);
    l4 = l3;
    l5 = vader_host_std_core_byte_len(l4);
    l6 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(47) + l5));
    l5 = (size_t) (int64_t) INT64_C(0);
    l5 = std_core_write_string_at(l6, l5, 2352u);
    l5 = std_core_write_string_at(l6, l5, l4);
    l5 = std_core_write_string_at(l6, l5, 365u);
    t0 = ((vader_struct_vader_bytecode_MakeClosure_t*) l1)->f_env_type_id;
    l7 = ((int64_t) (int32_t) t0);
    l5 = std_core_write_int(l6, l5, l7);
    l5 = std_core_write_string_at(l6, l5, 2205u);
    l4 = std_core_finish_buffer(l6, l5);
    vader_c_emit_line(l0, l4);
    l6 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_ctx)->f_module)->f_functions;
    l8 = ((vader_struct_vader_bytecode_MakeClosure_t*) l1)->f_function_index;
    l4 = vader_c_emit_fn_symbol_name(l6, l8);
    l4 = concat_4(l3, 395u, l4, 494u);
    vader_c_emit_line(l0, l4);
    l4 = vader_c_emit_obj_ptr_of(l2);
    l4 = concat_4(l3, 398u, l4, 494u);
    vader_c_emit_line(l0, l4);
    l4 = vader_c_emit_fresh_tmp(l0, (uint8_t) (int32_t) INT32_C(18));
    l3 = concat_4(l4, 69u, l3, 494u);
    vader_c_emit_line(l0, l3);
    vader_c_emit_push_tmp(l0, l4, (uint8_t) (int32_t) INT32_C(18));
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_c_emit_emit_memory_copy(void* l0) {
    vader_box_t l1 = vader_box_null(), l2 = vader_box_null(), l3 = vader_box_null(), l4 = vader_box_null();
    vader_string_t l5 = 0;
    vader_string_t l6 = 0;
    vader_string_t l7 = 0;
    vader_string_t l8 = 0;
    vader_string_t l9 = 0;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[5] = { &l1, &l2, &l3, &l4, &t0 };
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[5] = { &l5, &l6, &l7, &l8, &l9 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 5u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 5u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l1 = vader_c_emit_pop(l0);
    l2 = vader_c_emit_pop(l0);
    l3 = vader_c_emit_pop(l0);
    l4 = vader_c_emit_pop(l0);
    t0 = vader_c_emit_pop(l0);
    l5 = vader_c_emit_buf_ptr(t0);
    l6 = vader_c_emit_name_of(l4);
    l7 = vader_c_emit_buf_ptr(l3);
    l8 = vader_c_emit_name_of(l2);
    l9 = vader_c_emit_name_of(l1);
    l5 = concat_11(2337u, l5, 369u, l6, 365u, l7, 369u, l8, 369u, l9, 349u);
    vader_c_emit_line(l0, l5);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_c_emit_emit_mirrored_struct_typedefs(void* l0, void* l1) {
    size_t l2, l3;
    vader_string_t l4 = 0;
    vader_string_t l5 = 0;
    void* l6 = NULL;
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    vader_string_t t2 = 0;
    int64_t t3;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[4] = { &l0, &l1, &l6, &t1 };
    vader_string_t* gc_atom_roots[3] = { &l4, &l5, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_types)->length;
    l3 = (size_t) (int64_t) INT64_C(0);
    {
        loop_7: {
            if ((l3 < l2)) {
                vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_types);
                if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
                if (t0.tag == 509u) {
                    vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_types);
                    if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                    if ((size_t) l3 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                    t0 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l3);
                    t1 = t0.payload.obj;
                    t2 = ((vader_struct_vader_bytecode_BcStruct_t*) t1)->f_c_name;
                    if (t2 != 0u) {
                        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_struct_c_names);
                        if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                        if ((size_t) l3 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                        t0 = vader_array_box_slots(_a2_slotarr->buf)[_a2_slotarr->offset + (size_t) l3];
                        l4 = t0.payload.s;
                        l5 = concat_5(2196u, l4, 6u, l4, 495u);
                        std_string_builder_append(l1, l5);
                    } else {
                    }
                } else {
                }
                t3 = (l3 + INT64_C(1));
                l3 = (size_t) (int64_t) t3;
                goto loop_7;
            } else {
            }
        }
    }
    l2 = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_types)->length;
    l3 = (size_t) (int64_t) INT64_C(0);
    {
        loop_63: {
            if ((l3 < l2)) {
                vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_types);
                if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                if ((size_t) l3 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l3);
                if (t0.tag == 509u) {
                    vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_types);
                    if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                    if ((size_t) l3 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                    t0 = vader_array_ref_load_box(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l3);
                    l6 = t0.payload.obj;
                    t2 = ((vader_struct_vader_bytecode_BcStruct_t*) l6)->f_c_name;
                    if (t2 != 0u) {
                        vader_c_emit_emit_struct_body(l0, l6, l3, l1);
                    } else {
                    }
                } else {
                }
                t3 = (l3 + INT64_C(1));
                l3 = (size_t) (int64_t) t3;
                goto loop_63;
            } else {
            }
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static vader_string_t vader_c_emit_emit_nested_array(void* l0, void* l1, void* l2, vader_string_t l3, void* l4) {
    uint8_t l5, l22;
    size_t l6, l11, l14, l16;
    void* l7 = NULL;
    void* l15 = NULL;
    void* l21 = NULL;
    vader_string_t l8 = 0;
    vader_string_t l13 = 0;
    vader_string_t l18 = 0;
    vader_string_t l19 = 0;
    int32_t l9, l10;
    vader_box_t l12 = vader_box_null();
    uint64_t l17;
    int64_t l20;
    bool t0;
    int64_t t1;
    int32_t t2;
    vader_string_t t3 = 0;
    vader_box_t* gc_roots[1] = { &l12 };
    void** gc_raw_roots[7] = { &l0, &l1, &l2, &l4, &l7, &l15, &l21 };
    vader_string_t* gc_atom_roots[6] = { &l3, &l8, &l13, &l18, &l19, &t3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 6u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l5 = vader_c_emit_element_storage_kind(((vader_struct_vader_bytecode_BcValArray_t*) l2)->f_elements);
    l6 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcValArray_t*) l2)->f_elements)->length;
    l7 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_types;
    l8 = ((vader_struct_vader_bytecode_BcValArray_t*) l2)->f_element_type_name;
    l9 = vader_c_emit_type_index_for_name(l7, l8);
    l10 = vader_c_emit_array_type_index_for_element(((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_types, l9);
    t0 = ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_split;
    l8 = vader_c_emit_linkage_prefix(t0);
    if (l5 == INT32_C(0)) {
        vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 167u);
        l7 = (void*) _a0_arr;
        l11 = (size_t) (int64_t) INT64_C(0);
        {
            loop_34: {
                if ((l11 < l6)) {
                    vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcValArray_t*) l2)->f_elements);
                    if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                    if ((size_t) l11 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                    l12 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l11);
                    l13 = l3;
                    l14 = vader_host_std_core_byte_len(l13);
                    l15 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(22) + l14));
                    l16 = (size_t) (int64_t) INT64_C(0);
                    l16 = std_core_write_string_at(l15, l16, l13);
                    l16 = std_core_write_string_at(l15, l16, 923u);
                    t1 = ((int64_t) (size_t) l11);
                    l17 = (uint64_t) (int64_t) t1;
                    l16 = std_core_write_unsigned(l15, l16, l17);
                    l18 = std_core_finish_buffer(l15, l16);
                    l19 = vader_c_emit_box_slot_c(l0, l1, l12, l18, l9, l4);
                    vader_array_push((vader_array_t*) l7, vader_box_string(167u, l19));
                    t1 = (l11 + INT64_C(1));
                    l11 = (size_t) (int64_t) t1;
                    goto loop_34;
                } else {
                }
            }
        }
        l13 = l8;
        l18 = l3;
        l11 = vader_host_std_core_byte_len(l13);
        l14 = vader_host_std_core_byte_len(l18);
        t1 = (l11 + l14);
        l11 = (size_t) (int64_t) t1;
        l15 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(187) + l11));
        l11 = (size_t) (int64_t) INT64_C(0);
        l11 = std_core_write_string_at(l15, l11, l13);
        l11 = std_core_write_string_at(l15, l11, 1407u);
        t1 = ((int64_t) (size_t) l6);
        l17 = (uint64_t) (int64_t) t1;
        l11 = std_core_write_unsigned(l15, l11, l17);
        l11 = std_core_write_string_at(l15, l11, 860u);
        l11 = std_core_write_string_at(l15, l11, l18);
        l11 = std_core_write_string_at(l15, l11, 902u);
        l13 = std_core_finish_buffer(l15, l11);
        std_string_builder_append(l1, l13);
        l15 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(162));
        l11 = (size_t) (int64_t) INT64_C(0);
        l11 = std_core_write_string_at(l15, l11, 40u);
        t1 = ((int64_t) (size_t) l6);
        l17 = (uint64_t) (int64_t) t1;
        l11 = std_core_write_unsigned(l15, l11, l17);
        l11 = std_core_write_string_at(l15, l11, 2209u);
        t1 = ((int64_t) (size_t) l6);
        l17 = (uint64_t) (int64_t) t1;
        l11 = std_core_write_unsigned(l15, l11, l17);
        l11 = std_core_write_string_at(l15, l11, 2209u);
        l20 = ((int64_t) (int32_t) l9);
        l11 = std_core_write_int(l15, l11, l20);
        l11 = std_core_write_string_at(l15, l11, 2209u);
        t2 = vader_bytecode_array_kind_index((uint8_t) (int32_t) INT32_C(0));
        l20 = ((int64_t) (int32_t) t2);
        l11 = std_core_write_int(l15, l11, l20);
        l11 = std_core_write_string_at(l15, l11, 2228u);
        l13 = std_core_finish_buffer(l15, l11);
        std_string_builder_append(l1, l13);
        l13 = vader_c_emit_join_commas(l7);
        l13 = concat_3(38u, l13, 203u);
        std_string_builder_append(l1, l13);
    } else {
        l13 = vader_c_emit_c_type_for_array_kind(l5);
        vader_array_t* _a2_arr = vader_array_new(8u, 0u, 0u, 167u);
        l7 = (void*) _a2_arr;
        l15 = ((vader_struct_vader_bytecode_BcValArray_t*) l2)->f_elements;
        l11 = ((vader_array_t*) l15)->length;
        l14 = (size_t) (int64_t) INT64_C(0);
        {
            loop_251: {
                if ((l14 < l11)) {
                    vader_array_t* _a3_slotarr = ((vader_array_t*) l15);
                    if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                    if ((size_t) l14 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                    l12 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l14);
                    if (l12.tag == 512u) {
                        l21 = l12.payload.obj;
                        l22 = ((vader_struct_vader_bytecode_BcValPrim_t*) l21)->f_kind;
                        l17 = ((vader_struct_vader_bytecode_BcValPrim_t*) l21)->f_bits;
                        l18 = vader_c_emit_data_slot_c(l22, l17, l13);
                        vader_array_push((vader_array_t*) l7, vader_box_string(167u, l18));
                    } else {
                    }
                    t1 = (l14 + INT64_C(1));
                    l14 = (size_t) (int64_t) t1;
                    goto loop_251;
                } else {
                }
            }
        }
        l18 = l8;
        l19 = l3;
        l11 = vader_host_std_core_byte_len(l18);
        l14 = vader_host_std_core_byte_len(l13);
        t1 = (l11 + l14);
        l11 = (size_t) (int64_t) t1;
        l14 = vader_host_std_core_byte_len(l19);
        t1 = (l11 + l14);
        l11 = (size_t) (int64_t) t1;
        l15 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(176) + l11));
        l11 = (size_t) (int64_t) INT64_C(0);
        l11 = std_core_write_string_at(l15, l11, l18);
        l11 = std_core_write_string_at(l15, l11, 1406u);
        l11 = std_core_write_string_at(l15, l11, l13);
        l11 = std_core_write_string_at(l15, l11, 167u);
        t1 = ((int64_t) (size_t) l6);
        l17 = (uint64_t) (int64_t) t1;
        l11 = std_core_write_unsigned(l15, l11, l17);
        l11 = std_core_write_string_at(l15, l11, 860u);
        l11 = std_core_write_string_at(l15, l11, l19);
        l11 = std_core_write_string_at(l15, l11, 902u);
        l13 = std_core_finish_buffer(l15, l11);
        std_string_builder_append(l1, l13);
        l15 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(162));
        l11 = (size_t) (int64_t) INT64_C(0);
        l11 = std_core_write_string_at(l15, l11, 40u);
        t1 = ((int64_t) (size_t) l6);
        l17 = (uint64_t) (int64_t) t1;
        l11 = std_core_write_unsigned(l15, l11, l17);
        l11 = std_core_write_string_at(l15, l11, 2209u);
        t1 = ((int64_t) (size_t) l6);
        l17 = (uint64_t) (int64_t) t1;
        l11 = std_core_write_unsigned(l15, l11, l17);
        l11 = std_core_write_string_at(l15, l11, 2209u);
        l20 = ((int64_t) (int32_t) l9);
        l11 = std_core_write_int(l15, l11, l20);
        l11 = std_core_write_string_at(l15, l11, 2209u);
        t2 = vader_bytecode_array_kind_index(l5);
        l20 = ((int64_t) (int32_t) t2);
        l11 = std_core_write_int(l15, l11, l20);
        l11 = std_core_write_string_at(l15, l11, 2228u);
        l13 = std_core_finish_buffer(l15, l11);
        std_string_builder_append(l1, l13);
        l13 = vader_c_emit_join_commas(l7);
        l13 = concat_3(38u, l13, 203u);
        std_string_builder_append(l1, l13);
    }
    l13 = l3;
    l18 = l3;
    l11 = vader_host_std_core_byte_len(l8);
    l14 = vader_host_std_core_byte_len(l13);
    t1 = (l11 + l14);
    l11 = (size_t) (int64_t) t1;
    l14 = vader_host_std_core_byte_len(l18);
    t1 = (l11 + l14);
    l11 = (size_t) (int64_t) t1;
    l7 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(150) + l11));
    l11 = (size_t) (int64_t) INT64_C(0);
    l11 = std_core_write_string_at(l7, l11, l8);
    l11 = std_core_write_string_at(l7, l11, 1409u);
    l11 = std_core_write_string_at(l7, l11, l13);
    l11 = std_core_write_string_at(l7, l11, 87u);
    l20 = ((int64_t) (int32_t) l10);
    l11 = std_core_write_int(l7, l11, l20);
    l11 = std_core_write_string_at(l7, l11, 2220u);
    t1 = ((int64_t) (size_t) l6);
    l17 = (uint64_t) (int64_t) t1;
    l11 = std_core_write_unsigned(l7, l11, l17);
    l11 = std_core_write_string_at(l7, l11, 2209u);
    t1 = ((int64_t) (size_t) l6);
    l17 = (uint64_t) (int64_t) t1;
    l11 = std_core_write_unsigned(l7, l11, l17);
    l11 = std_core_write_string_at(l7, l11, 2217u);
    l11 = std_core_write_string_at(l7, l11, l18);
    l11 = std_core_write_string_at(l7, l11, 903u);
    l8 = std_core_finish_buffer(l7, l11);
    std_string_builder_append(l1, l8);
    t3 = concat_2(312u, l3);
    { vader_string_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void vader_c_emit_emit_op(void* l0, int32_t l1, vader_box_t l2) {
    void* l3 = NULL;
    int32_t l4;
    vader_box_t l5 = vader_box_null();
    bool l6;
    vader_string_t l7 = 0;
    uint8_t l8;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    vader_box_t* gc_roots[2] = { &l2, &l5 };
    void** gc_raw_roots[3] = { &l0, &l3, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l7, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_c_emit_invalidate_resolve_cache(l0, l2);
    if (l2.tag == 567u) {
        l3 = l2.payload.obj;
        vader_c_emit_push_const(l0, vader_ref_box(l3));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 587u) {
        l3 = l2.payload.obj;
        vader_c_emit_push_const(l0, vader_ref_box(l3));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 548u) {
        l3 = l2.payload.obj;
        vader_c_emit_push_const(l0, vader_ref_box(l3));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 519u) {
        l3 = l2.payload.obj;
        vader_c_emit_push_const(l0, vader_ref_box(l3));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 535u) {
        l3 = l2.payload.obj;
        vader_c_emit_push_const(l0, vader_ref_box(l3));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 618u) {
        l3 = l2.payload.obj;
        vader_c_emit_push_const(l0, vader_ref_box(l3));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 633u) {
        l3 = l2.payload.obj;
        vader_c_emit_push_const(l0, vader_ref_box(l3));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 612u) {
        l3 = l2.payload.obj;
        vader_c_emit_emit_local_get(l0, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 613u) {
        t0 = l2.payload.obj;
        l4 = ((vader_struct_vader_bytecode_LocalSet_t*) t0)->f_slot;
        vader_c_emit_emit_local_set(l0, l4, false);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 614u) {
        t0 = l2.payload.obj;
        l4 = ((vader_struct_vader_bytecode_LocalTee_t*) t0)->f_slot;
        vader_c_emit_emit_local_set(l0, l4, true);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 611u) {
        l3 = l2.payload.obj;
        vader_c_emit_emit_local_field(l0, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 622u) {
        vader_c_emit_emit_return(l0);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 623u) {
        t0 = l2.payload.obj;
        l5 = ((vader_struct_vader_bytecode_ReturnLit_t*) t0)->f_value;
        vader_c_emit_emit_return_lit(l0, l5);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 541u) {
        vader_c_emit_drop_top(l0);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 532u) {
        l3 = l2.payload.obj;
        vader_c_emit_emit_call(l0, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 533u) {
        l3 = l2.payload.obj;
        vader_c_emit_emit_call_import(l0, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 534u) {
        l3 = l2.payload.obj;
        vader_c_emit_emit_call_indirect(l0, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 655u) {
        l3 = l2.payload.obj;
        vader_c_emit_emit_virtual_call(l0, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 561u) {
        l3 = l2.payload.obj;
        vader_c_emit_emit_fn_ref(l0, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 560u) {
        l3 = l2.payload.obj;
        vader_c_emit_emit_fn_addr(l0, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 616u) {
        l3 = l2.payload.obj;
        vader_c_emit_emit_make_closure(l0, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 602u) {
        vader_c_emit_emit_if_open(l0);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 542u) {
        vader_c_emit_emit_else(l0);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 545u) {
        vader_c_emit_emit_end(l0, l1);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 517u) {
        vader_c_emit_emit_open_scope(l0, l1, (uint8_t) (int32_t) INT32_C(0));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 615u) {
        vader_c_emit_emit_open_scope(l0, l1, (uint8_t) (int32_t) INT32_C(1));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 525u) {
        vader_c_emit_emit_branch(l0, l1, false);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 526u) {
        vader_c_emit_emit_branch(l0, l1, true);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 522u) {
        vader_c_emit_push_unop(l0, 219u, (uint8_t) (int32_t) INT32_C(12));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 638u) {
        l3 = l2.payload.obj;
        vader_c_emit_emit_struct_new(l0, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 637u) {
        l3 = l2.payload.obj;
        vader_c_emit_emit_struct_get(l0, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 639u) {
        l3 = l2.payload.obj;
        vader_c_emit_emit_struct_set(l0, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 488u) {
        l3 = l2.payload.obj;
        vader_c_emit_emit_array_new(l0, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 487u) {
        t0 = l2.payload.obj;
        l6 = ((vader_struct_vader_bytecode_ArrayLen_t*) t0)->f_resolve_buf;
        vader_c_emit_emit_array_len(l0, l6);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 489u) {
        l3 = l2.payload.obj;
        vader_c_emit_emit_array_push(l0, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 486u) {
        l3 = l2.payload.obj;
        vader_c_emit_emit_array_get(l0, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 493u) {
        l3 = l2.payload.obj;
        vader_c_emit_emit_array_set(l0, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 494u) {
        l3 = l2.payload.obj;
        vader_c_emit_emit_array_slice(l0, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 492u) {
        vader_c_emit_emit_array_repeat(l0);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 490u) {
        vader_c_emit_emit_array_push_all(l0);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 485u) {
        vader_c_emit_emit_array_copy(l0);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 491u) {
        vader_c_emit_emit_array_remove_last(l0);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 484u) {
        vader_c_emit_emit_array_clear(l0);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 537u) {
        l3 = l2.payload.obj;
        vader_c_emit_emit_data_const_op(l0, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 641u) {
        l3 = l2.payload.obj;
        vader_c_emit_emit_type_const(l0, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 640u) {
        l3 = l2.payload.obj;
        vader_c_emit_emit_type_check(l0, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 619u) {
        l3 = l2.payload.obj;
        vader_c_emit_emit_ref_cast(l0, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 524u) {
        l3 = l2.payload.obj;
        vader_c_emit_emit_box_op(l0, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 654u) {
        t0 = l2.payload.obj;
        t1 = ((vader_struct_vader_bytecode_Unreachable_t*) t0)->f_reason;
        l7 = vader_c_emit_c_string_lit(t1);
        l7 = concat_3(2364u, l7, 349u);
        vader_c_emit_line(l0, l7);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 536u) {
        t0 = l2.payload.obj;
        l8 = vader_c_emit_convert_target_val(((vader_struct_vader_bytecode_Convert_t*) t0)->f_target);
        t0 = l2.payload.obj;
        l7 = ((vader_struct_vader_bytecode_Convert_t*) t0)->f_from_name;
        vader_c_emit_emit_convert(l0, l8, l7);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 624u) {
        vader_c_emit_emit_size_of_type(l0);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 562u) {
        vader_c_emit_push_binop(l0, 361u, (uint8_t) (int32_t) INT32_C(2));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 581u) {
        vader_c_emit_push_binop(l0, 382u, (uint8_t) (int32_t) INT32_C(2));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 575u) {
        vader_c_emit_push_binop(l0, 352u, (uint8_t) (int32_t) INT32_C(2));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 568u) {
        vader_c_emit_push_eager(l0, 430u, (uint8_t) (int32_t) INT32_C(2));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 574u) {
        vader_c_emit_push_eager(l0, 254u, (uint8_t) (int32_t) INT32_C(2));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 577u) {
        vader_c_emit_push_unop(l0, 382u, (uint8_t) (int32_t) INT32_C(2));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 564u) {
        vader_c_emit_push_unop(l0, 2430u, (uint8_t) (int32_t) INT32_C(2));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 563u) {
        vader_c_emit_push_binop(l0, 256u, (uint8_t) (int32_t) INT32_C(2));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 565u) {
        vader_c_emit_push_binop(l0, 2423u, (uint8_t) (int32_t) INT32_C(2));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 566u) {
        vader_c_emit_push_binop(l0, 862u, (uint8_t) (int32_t) INT32_C(2));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 578u) {
        vader_c_emit_push_binop(l0, 499u, (uint8_t) (int32_t) INT32_C(2));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 579u) {
        vader_c_emit_push_binop(l0, 519u, (uint8_t) (int32_t) INT32_C(2));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 580u) {
        vader_c_emit_push_binop(l0, 519u, (uint8_t) (int32_t) INT32_C(7));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 569u) {
        vader_c_emit_push_cmp(l0, 515u, (uint8_t) (int32_t) INT32_C(2));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 576u) {
        vader_c_emit_push_cmp(l0, 220u, (uint8_t) (int32_t) INT32_C(2));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 573u) {
        vader_c_emit_push_cmp(l0, 498u, (uint8_t) (int32_t) INT32_C(2));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 572u) {
        vader_c_emit_push_cmp(l0, 500u, (uint8_t) (int32_t) INT32_C(2));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 571u) {
        vader_c_emit_push_cmp(l0, 517u, (uint8_t) (int32_t) INT32_C(2));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 570u) {
        vader_c_emit_push_cmp(l0, 518u, (uint8_t) (int32_t) INT32_C(2));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 582u) {
        vader_c_emit_push_binop(l0, 361u, (uint8_t) (int32_t) INT32_C(3));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 601u) {
        vader_c_emit_push_binop(l0, 382u, (uint8_t) (int32_t) INT32_C(3));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 595u) {
        vader_c_emit_push_binop(l0, 352u, (uint8_t) (int32_t) INT32_C(3));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 588u) {
        vader_c_emit_push_eager(l0, 430u, (uint8_t) (int32_t) INT32_C(3));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 594u) {
        vader_c_emit_push_eager(l0, 254u, (uint8_t) (int32_t) INT32_C(3));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 597u) {
        vader_c_emit_push_i64_neg(l0);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 583u) {
        vader_c_emit_push_binop(l0, 256u, (uint8_t) (int32_t) INT32_C(3));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 585u) {
        vader_c_emit_push_binop(l0, 2423u, (uint8_t) (int32_t) INT32_C(3));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 586u) {
        vader_c_emit_push_binop(l0, 862u, (uint8_t) (int32_t) INT32_C(3));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 584u) {
        vader_c_emit_push_unop(l0, 2430u, (uint8_t) (int32_t) INT32_C(3));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 598u) {
        vader_c_emit_push_binop(l0, 499u, (uint8_t) (int32_t) INT32_C(3));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 599u) {
        vader_c_emit_push_binop(l0, 519u, (uint8_t) (int32_t) INT32_C(3));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 600u) {
        vader_c_emit_push_binop(l0, 519u, (uint8_t) (int32_t) INT32_C(8));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 589u) {
        vader_c_emit_push_cmp(l0, 515u, (uint8_t) (int32_t) INT32_C(3));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 596u) {
        vader_c_emit_push_cmp(l0, 220u, (uint8_t) (int32_t) INT32_C(3));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 593u) {
        vader_c_emit_push_cmp(l0, 498u, (uint8_t) (int32_t) INT32_C(3));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 592u) {
        vader_c_emit_push_cmp(l0, 500u, (uint8_t) (int32_t) INT32_C(3));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 591u) {
        vader_c_emit_push_cmp(l0, 517u, (uint8_t) (int32_t) INT32_C(3));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 590u) {
        vader_c_emit_push_cmp(l0, 518u, (uint8_t) (int32_t) INT32_C(3));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 642u) {
        vader_c_emit_push_eager(l0, 430u, (uint8_t) (int32_t) INT32_C(7));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 647u) {
        vader_c_emit_push_eager(l0, 254u, (uint8_t) (int32_t) INT32_C(7));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 646u) {
        vader_c_emit_push_cmp(l0, 498u, (uint8_t) (int32_t) INT32_C(7));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 645u) {
        vader_c_emit_push_cmp(l0, 500u, (uint8_t) (int32_t) INT32_C(7));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 644u) {
        vader_c_emit_push_cmp(l0, 517u, (uint8_t) (int32_t) INT32_C(7));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 643u) {
        vader_c_emit_push_cmp(l0, 518u, (uint8_t) (int32_t) INT32_C(7));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 648u) {
        vader_c_emit_push_eager(l0, 430u, (uint8_t) (int32_t) INT32_C(8));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 653u) {
        vader_c_emit_push_eager(l0, 254u, (uint8_t) (int32_t) INT32_C(8));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 652u) {
        vader_c_emit_push_cmp(l0, 498u, (uint8_t) (int32_t) INT32_C(8));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 651u) {
        vader_c_emit_push_cmp(l0, 500u, (uint8_t) (int32_t) INT32_C(8));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 650u) {
        vader_c_emit_push_cmp(l0, 517u, (uint8_t) (int32_t) INT32_C(8));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 649u) {
        vader_c_emit_push_cmp(l0, 518u, (uint8_t) (int32_t) INT32_C(8));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 547u) {
        vader_c_emit_push_binop(l0, 361u, (uint8_t) (int32_t) INT32_C(11));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 558u) {
        vader_c_emit_push_binop(l0, 382u, (uint8_t) (int32_t) INT32_C(11));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 555u) {
        vader_c_emit_push_binop(l0, 352u, (uint8_t) (int32_t) INT32_C(11));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 549u) {
        vader_c_emit_push_eager(l0, 430u, (uint8_t) (int32_t) INT32_C(11));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 557u) {
        vader_c_emit_push_unop(l0, 382u, (uint8_t) (int32_t) INT32_C(11));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 550u) {
        vader_c_emit_push_cmp(l0, 515u, (uint8_t) (int32_t) INT32_C(11));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 556u) {
        vader_c_emit_push_cmp(l0, 220u, (uint8_t) (int32_t) INT32_C(11));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 554u) {
        vader_c_emit_push_cmp(l0, 498u, (uint8_t) (int32_t) INT32_C(11));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 553u) {
        vader_c_emit_push_cmp(l0, 500u, (uint8_t) (int32_t) INT32_C(11));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 552u) {
        vader_c_emit_push_cmp(l0, 517u, (uint8_t) (int32_t) INT32_C(11));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 551u) {
        vader_c_emit_push_cmp(l0, 518u, (uint8_t) (int32_t) INT32_C(11));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 520u) {
        vader_c_emit_push_binop(l0, 515u, (uint8_t) (int32_t) INT32_C(12));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 521u) {
        vader_c_emit_push_binop(l0, 220u, (uint8_t) (int32_t) INT32_C(12));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 518u) {
        vader_c_emit_push_binop(l0, 257u, (uint8_t) (int32_t) INT32_C(12));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 523u) {
        vader_c_emit_push_binop(l0, 2424u, (uint8_t) (int32_t) INT32_C(12));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 634u) {
        vader_c_emit_push_cmp(l0, 515u, (uint8_t) (int32_t) INT32_C(14));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 635u) {
        vader_c_emit_push_cmp(l0, 220u, (uint8_t) (int32_t) INT32_C(14));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 636u) {
        vader_c_emit_emit_string_slice(l0);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 620u) {
        vader_c_emit_push_binop_any(l0, 515u, (uint8_t) (int32_t) INT32_C(12));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 621u) {
        vader_c_emit_push_binop_any(l0, 220u, (uint8_t) (int32_t) INT32_C(12));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 540u) {
        vader_c_emit_emit_defer_push(l0);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 539u) {
        l3 = l2.payload.obj;
        vader_c_emit_emit_defer_pop_exec(l0, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 527u) {
        vader_c_emit_emit_buffer_new(l0);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 610u) {
        vader_c_emit_emit_buffer_load(l0, 2336u, (uint8_t) (int32_t) INT32_C(2));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 605u) {
        vader_c_emit_emit_buffer_load(l0, 2334u, (uint8_t) (int32_t) INT32_C(2));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 606u) {
        vader_c_emit_emit_buffer_load(l0, 2335u, (uint8_t) (int32_t) INT32_C(3));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 604u) {
        vader_c_emit_emit_buffer_load(l0, 2333u, (uint8_t) (int32_t) INT32_C(11));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 632u) {
        vader_c_emit_emit_buffer_store(l0, 2341u, 311u);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 627u) {
        vader_c_emit_emit_buffer_store(l0, 2339u, 305u);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 628u) {
        vader_c_emit_emit_buffer_store(l0, 2340u, 307u);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 626u) {
        vader_c_emit_emit_buffer_store(l0, 2338u, 304u);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 608u) {
        t0 = l2.payload.obj;
        l6 = ((vader_struct_vader_bytecode_LoadSlotI32_t*) t0)->f_bounds_safe;
        vader_c_emit_emit_slot_load_prim(l0, 1727u, (uint8_t) (int32_t) INT32_C(2), l6);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 609u) {
        t0 = l2.payload.obj;
        l6 = ((vader_struct_vader_bytecode_LoadSlotI64_t*) t0)->f_bounds_safe;
        vader_c_emit_emit_slot_load_prim(l0, 1728u, (uint8_t) (int32_t) INT32_C(3), l6);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 607u) {
        t0 = l2.payload.obj;
        l6 = ((vader_struct_vader_bytecode_LoadSlotF64_t*) t0)->f_bounds_safe;
        vader_c_emit_emit_slot_load_prim(l0, 1451u, (uint8_t) (int32_t) INT32_C(11), l6);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 630u) {
        t0 = l2.payload.obj;
        l6 = ((vader_struct_vader_bytecode_StoreSlotI32_t*) t0)->f_bounds_safe;
        vader_c_emit_emit_slot_store_prim(l0, 1727u, (uint8_t) (int32_t) INT32_C(2), l6);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 631u) {
        t0 = l2.payload.obj;
        l6 = ((vader_struct_vader_bytecode_StoreSlotI64_t*) t0)->f_bounds_safe;
        vader_c_emit_emit_slot_store_prim(l0, 1728u, (uint8_t) (int32_t) INT32_C(3), l6);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 629u) {
        t0 = l2.payload.obj;
        l6 = ((vader_struct_vader_bytecode_StoreSlotF64_t*) t0)->f_bounds_safe;
        vader_c_emit_emit_slot_store_prim(l0, 1451u, (uint8_t) (int32_t) INT32_C(11), l6);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 617u) {
        vader_c_emit_emit_memory_copy(l0);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 528u) {
        vader_c_emit_emit_buffer_to_string(l0);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 529u) {
        vader_c_emit_emit_buffer_write_string(l0);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 559u) {
        vader_c_emit_emit_f64_to_bits(l0);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 516u) {
        vader_c_emit_emit_bits_to_f64(l0);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 546u) {
        vader_c_emit_emit_f32_to_bits(l0);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 515u) {
        vader_c_emit_emit_bits_to_f32(l0);
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_c_emit_emit_open_scope(void* l0, int32_t l1, uint8_t l2) {
    void* l3 = NULL;
    size_t l4;
    int64_t l5;
    vader_string_t l6 = 0;
    bool l7;
    void** gc_raw_roots[2] = { &l0, &l3 };
    vader_string_t* gc_atom_roots[1] = { &l6 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l3 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(36));
    l4 = (size_t) (int64_t) INT64_C(0);
    l4 = std_core_write_string_at(l3, l4, 1996u);
    l5 = ((int64_t) (int32_t) l1);
    l4 = std_core_write_int(l3, l4, l5);
    l4 = std_core_write_string_at(l3, l4, 318u);
    l6 = std_core_finish_buffer(l3, l4);
    vader_c_emit_assert_stack_empty(l0, l6);
    if (l2 == INT32_C(1)) {
        l7 = std_core____Contains_contains__i32(((vader_struct_vader_c_emit_FnState_t*) l0)->f_continue_targets, l1);
    } else {
        l7 = false;
    }
    if (l7) {
        l3 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(28));
        l4 = (size_t) (int64_t) INT64_C(0);
        l4 = std_core_write_string_at(l3, l4, 1827u);
        l5 = ((int64_t) (int32_t) l1);
        l4 = std_core_write_int(l3, l4, l5);
        l4 = std_core_write_string_at(l3, l4, 490u);
        l6 = std_core_finish_buffer(l3, l4);
        vader_c_emit_line(l0, l6);
    } else {
        vader_c_emit_line(l0, 2416u);
    }
    vader_c_emit_indent_push(l0);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_c_emit_emit_prim_data_entry(void* l0, size_t l1, void* l2, int32_t l3, int32_t l4, bool l5) {
    vader_string_t l6 = 0;
    vader_string_t l9 = 0;
    vader_string_t l10 = 0;
    vader_string_t l11 = 0;
    size_t l7, l12, l13;
    int32_t l8;
    void* l14 = NULL;
    uint64_t l15;
    int64_t l16;
    uint8_t l17;
    bool t0;
    int64_t t1;
    void** gc_raw_roots[3] = { &l0, &l2, &l14 };
    vader_string_t* gc_atom_roots[4] = { &l6, &l9, &l10, &l11 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l6 = vader_c_emit_c_type_for_array_kind(((vader_struct_vader_bytecode_BcPrimData_t*) l2)->f_kind);
    l7 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcPrimData_t*) l2)->f_items)->length;
    l8 = vader_bytecode_array_kind_index(((vader_struct_vader_bytecode_BcPrimData_t*) l2)->f_kind);
    l9 = vader_c_emit_linkage_prefix(l5);
    t0 = ((vader_struct_vader_bytecode_BcPrimData_t*) l2)->f_mutable;
    l10 = vader_c_emit_storage_qualifier(t0);
    l9 = concat_2(l9, l10);
    l10 = l9;
    l11 = l6;
    l12 = vader_host_std_core_byte_len(l10);
    l13 = vader_host_std_core_byte_len(l11);
    t1 = (l12 + l13);
    l12 = (size_t) (int64_t) t1;
    l14 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(201) + l12));
    l12 = (size_t) (int64_t) INT64_C(0);
    l12 = std_core_write_string_at(l14, l12, l10);
    l12 = std_core_write_string_at(l14, l12, 2113u);
    l12 = std_core_write_string_at(l14, l12, l11);
    l12 = std_core_write_string_at(l14, l12, 167u);
    t1 = ((int64_t) (size_t) l7);
    l15 = (uint64_t) (int64_t) t1;
    l12 = std_core_write_unsigned(l14, l12, l15);
    l12 = std_core_write_string_at(l14, l12, 861u);
    t1 = ((int64_t) (size_t) l1);
    l15 = (uint64_t) (int64_t) t1;
    l12 = std_core_write_unsigned(l14, l12, l15);
    l12 = std_core_write_string_at(l14, l12, 902u);
    l10 = std_core_finish_buffer(l14, l12);
    std_string_builder_append(l0, l10);
    l14 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(162));
    l12 = (size_t) (int64_t) INT64_C(0);
    l12 = std_core_write_string_at(l14, l12, 40u);
    t1 = ((int64_t) (size_t) l7);
    l15 = (uint64_t) (int64_t) t1;
    l12 = std_core_write_unsigned(l14, l12, l15);
    l12 = std_core_write_string_at(l14, l12, 2209u);
    t1 = ((int64_t) (size_t) l7);
    l15 = (uint64_t) (int64_t) t1;
    l12 = std_core_write_unsigned(l14, l12, l15);
    l12 = std_core_write_string_at(l14, l12, 2209u);
    l16 = ((int64_t) (int32_t) l4);
    l12 = std_core_write_int(l14, l12, l16);
    l12 = std_core_write_string_at(l14, l12, 2209u);
    l16 = ((int64_t) (int32_t) l8);
    l12 = std_core_write_int(l14, l12, l16);
    l12 = std_core_write_string_at(l14, l12, 2228u);
    l10 = std_core_finish_buffer(l14, l12);
    std_string_builder_append(l0, l10);
    std_string_builder_append(l0, 37u);
    l12 = (size_t) (int64_t) INT64_C(0);
    {
        loop_168: {
            if ((l12 < l7)) {
                if ((l12 > INT64_C(0))) {
                    std_string_builder_append(l0, 364u);
                } else {
                }
                l17 = ((vader_struct_vader_bytecode_BcPrimData_t*) l2)->f_kind;
                vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcPrimData_t*) l2)->f_items);
                if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                if ((size_t) l12 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                t1 = ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l12];
                l15 = (uint64_t) (int64_t) t1;
                l10 = vader_c_emit_data_slot_c(l17, l15, l6);
                l11 = concat_2(6u, l10);
                std_string_builder_append(l0, l11);
                t1 = (l12 + INT64_C(1));
                l12 = (size_t) (int64_t) t1;
                goto loop_168;
            } else {
            }
        }
    }
    std_string_builder_append(l0, 202u);
    std_string_builder_append(l0, 2429u);
    l6 = l9;
    l12 = vader_host_std_core_byte_len(l6);
    l14 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(206) + l12));
    l12 = (size_t) (int64_t) INT64_C(0);
    l12 = std_core_write_string_at(l14, l12, l6);
    l12 = std_core_write_string_at(l14, l12, 2316u);
    t1 = ((int64_t) (size_t) l1);
    l15 = (uint64_t) (int64_t) t1;
    l12 = std_core_write_unsigned(l14, l12, l15);
    l12 = std_core_write_string_at(l14, l12, 87u);
    l16 = ((int64_t) (int32_t) l3);
    l12 = std_core_write_int(l14, l12, l16);
    l12 = std_core_write_string_at(l14, l12, 2220u);
    t1 = ((int64_t) (size_t) l7);
    l15 = (uint64_t) (int64_t) t1;
    l12 = std_core_write_unsigned(l14, l12, l15);
    l12 = std_core_write_string_at(l14, l12, 2209u);
    t1 = ((int64_t) (size_t) l7);
    l15 = (uint64_t) (int64_t) t1;
    l12 = std_core_write_unsigned(l14, l12, l15);
    l12 = std_core_write_string_at(l14, l12, 2218u);
    t1 = ((int64_t) (size_t) l1);
    l15 = (uint64_t) (int64_t) t1;
    l12 = std_core_write_unsigned(l14, l12, l15);
    l12 = std_core_write_string_at(l14, l12, 903u);
    l6 = std_core_finish_buffer(l14, l12);
    std_string_builder_append(l0, l6);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_c_emit_emit_ref_cast(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null();
    void* l3 = NULL;
    size_t l4;
    uint8_t l5, l7;
    vader_string_t l6 = 0;
    int32_t t0;
    int64_t t1;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l2, &t2 };
    void** gc_raw_roots[3] = { &l0, &l1, &l3 };
    vader_string_t* gc_atom_roots[1] = { &l6 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = vader_c_emit_pop(l0);
    l3 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_ctx)->f_module)->f_types;
    t0 = ((vader_struct_vader_bytecode_RefCast_t*) l1)->f_type_id;
    t1 = ((int64_t) (int32_t) t0);
    l4 = (size_t) (int64_t) t1;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    if ((size_t) l4 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
    t2 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
    l5 = vader_c_emit_val_type_of_bc_type(t2);
    l3 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_ctx)->f_module)->f_types;
    l6 = vader_c_emit_name_of(l2);
    l7 = vader_c_emit_val_of(l2);
    l6 = vader_c_emit_coerce_expr(l3, l6, l7, l5);
    vader_c_emit_push_into_tmp(l0, l6, l5);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_c_emit_emit_return(void* l0) {
    uint8_t l1, l5;
    vader_string_t l2 = 0;
    vader_string_t l6 = 0;
    vader_box_t l3 = vader_box_null();
    void* l4 = NULL;
    size_t t0;
    bool t1;
    vader_box_t* gc_roots[1] = { &l3 };
    void** gc_raw_roots[2] = { &l0, &l4 };
    vader_string_t* gc_atom_roots[2] = { &l2, &l6 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcFunction_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_function)->f_signature)->f_result;
    if (l1 == INT32_C(16)) {
        vader_c_emit_emit_return_stmt(l0, 1986u);
        { vader_gc_top = gc_frame.prev; return; }
    }
    t0 = ((vader_array_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_stack)->length;
    if (t0 == INT64_C(0)) {
        l2 = ((vader_struct_vader_bytecode_BcFunction_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_function)->f_name;
        l2 = concat_3(2366u, l2, 226u);
        vader_c_emit_line(l0, l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    l3 = vader_c_emit_pop(l0);
    l4 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_ctx)->f_module)->f_types;
    l2 = vader_c_emit_name_of(l3);
    l5 = vader_c_emit_val_of(l3);
    l2 = vader_c_emit_coerce_expr(l4, l2, l5, l1);
    t1 = ((vader_struct_vader_c_emit_FnState_t*) l0)->f_no_frame;
    if (t1) {
        l6 = concat_3(1979u, l2, 494u);
        vader_c_emit_line(l0, l6);
    } else {
        l6 = vader_c_emit_c_type_for_val_bare(l1);
        l2 = concat_5(2417u, l6, 92u, l2, 497u);
        vader_c_emit_line(l0, l2);
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_c_emit_emit_return_lit(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    vader_string_t l3 = 0;
    uint8_t l4, l5;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_string_t* gc_atom_roots[1] = { &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_ctx)->f_module)->f_types;
    l3 = vader_c_emit_const_lit_c(((vader_struct_vader_c_emit_FnState_t*) l0)->f_ctx, l1);
    l4 = vader_c_emit_const_val(l1);
    l5 = ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcFunction_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_function)->f_signature)->f_result;
    l3 = vader_c_emit_coerce_expr(l2, l3, l4, l5);
    l3 = concat_3(1979u, l3, 494u);
    vader_c_emit_emit_return_stmt(l0, l3);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_c_emit_emit_return_stmt(void* l0, vader_string_t l1) {
    vader_string_t l2 = 0;
    bool t0;
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[2] = { &l1, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_c_emit_FnState_t*) l0)->f_no_frame;
    if (t0) {
        vader_c_emit_line(l0, l1);
    } else {
        l2 = concat_3(2419u, l1, 201u);
        vader_c_emit_line(l0, l2);
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_c_emit_emit_size_of_type(void* l0) {
    vader_string_t l1 = 0;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = vader_c_emit_pop(l0);
    l1 = vader_c_emit_name_of(t0);
    l1 = concat_3(2363u, l1, 422u);
    vader_c_emit_push_into_tmp(l0, l1, (uint8_t) (int32_t) INT32_C(9));
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static vader_string_t vader_c_emit_emit_slot_array_local(void* l0, vader_box_t l1, vader_box_t l2, bool l3) {
    vader_string_t l4 = 0;
    vader_string_t l5 = 0;
    vader_box_t* gc_roots[2] = { &l1, &l2 };
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[2] = { &l4, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l4 = vader_c_emit_array_hdr_ptr(l1);
    l4 = vader_c_emit_resolve_array_local(l0, l4, false);
    if (!(l3)) {
        l5 = vader_c_emit_name_of(l2);
        l5 = concat_5(1694u, l5, 91u, l4, 401u);
        vader_c_emit_line(l0, l5);
    } else {
    }
    { vader_string_t __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void vader_c_emit_emit_slot_decls(void* l0, void* l1, void* l2, void* l3, void* l4, void* l5, bool l6) {
    void* l7 = NULL;
    void* l28 = NULL;
    size_t l8, l9, l14, l15, l20, l21, l29, l30;
    uint8_t l10;
    bool l11, l12, l13;
    vader_string_t l16 = 0;
    vader_string_t l17 = 0;
    vader_string_t l18 = 0;
    vader_string_t l19 = 0;
    vader_string_t l22 = 0;
    vader_string_t l23 = 0;
    vader_string_t l24 = 0;
    vader_string_t l25 = 0;
    vader_string_t l26 = 0;
    vader_string_t l27 = 0;
    vader_string_t l31 = 0;
    vader_string_t l32 = 0;
    vader_string_t l33 = 0;
    vader_string_t l34 = 0;
    vader_string_t l35 = 0;
    vader_string_t l36 = 0;
    vader_string_t l37 = 0;
    vader_box_t t0 = vader_box_null();
    bool t1;
    int64_t t2;
    vader_string_t t3 = 0;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[8] = { &l0, &l1, &l2, &l3, &l4, &l5, &l7, &l28 };
    vader_string_t* gc_atom_roots[18] = { &l16, &l17, &l18, &l19, &l22, &l23, &l24, &l25, &l26, &l27, &l31, &l32, &l33, &l34, &l35, &l36, &l37, &t3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 18u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(11u, 0u, 1u, 173u);
    l7 = (void*) _a0_arr;
    l8 = ((vader_array_t*) l1)->length;
    l9 = (size_t) (int64_t) INT64_C(0);
    {
        loop_8: {
            if ((l9 < l8)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l9 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_read_u8(_a1_slotarr, _a1_slotarr->offset + (size_t) l9, 173u);
                l10 = ((uint8_t) t0.payload.i);
                t1 = std_core____Contains_contains__ValType(l7, l10);
                if (t1) {
                    t2 = (l9 + INT64_C(1));
                    l9 = (size_t) (int64_t) t2;
                    goto loop_8;
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
                    l15 = (size_t) (int64_t) INT64_C(0);
                    {
                        loop_71: {
                            if ((l15 < l14)) {
                                vader_array_t* _a2_slotarr = ((vader_array_t*) l1);
                                if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                                if ((size_t) l15 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                                t0 = vader_array_read_u8(_a2_slotarr, _a2_slotarr->offset + (size_t) l15, 173u);
                                if (((int32_t) t0.payload.i) == l10) {
                                    vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
                                    if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                                    if ((size_t) l15 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                                    t0 = vader_array_box_slots(_a3_slotarr->buf)[_a3_slotarr->offset + (size_t) l15];
                                    l16 = t0.payload.s;
                                    l17 = concat_3(30u, l16, 74u);
                                    std_string_builder_append(l0, l17);
                                    vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
                                    if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                                    if ((size_t) l15 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                                    t0 = vader_array_box_slots(_a4_slotarr->buf)[_a4_slotarr->offset + (size_t) l15];
                                    l18 = t0.payload.s;
                                    l19 = concat_2(256u, l18);
                                    vader_array_push((vader_array_t*) l5, vader_box_string(167u, l19));
                                } else {
                                }
                                t2 = (l15 + INT64_C(1));
                                l15 = (size_t) (int64_t) t2;
                                goto loop_71;
                            } else {
                            }
                        }
                    }
                    t2 = (l9 + INT64_C(1));
                    l9 = (size_t) (int64_t) t2;
                    goto loop_8;
                }
                if (l11) {
                    l20 = ((vader_array_t*) l1)->length;
                    l21 = (size_t) (int64_t) INT64_C(0);
                    {
                        loop_132: {
                            if ((l21 < l20)) {
                                vader_array_t* _a5_slotarr = ((vader_array_t*) l1);
                                if (_a5_slotarr->buf != NULL && _a5_slotarr->buf->header.forward != NULL) { _a5_slotarr->buf = vader_array_buf_forward(_a5_slotarr->buf); }
                                if ((size_t) l21 >= _a5_slotarr->length) { vader_trap("array index out of bounds"); }
                                t0 = vader_array_read_u8(_a5_slotarr, _a5_slotarr->offset + (size_t) l21, 173u);
                                if (((int32_t) t0.payload.i) == l10) {
                                    if (l12) {
                                        vader_array_t* _a6_slotarr = ((vader_array_t*) l2);
                                        if (_a6_slotarr->buf != NULL && _a6_slotarr->buf->header.forward != NULL) { _a6_slotarr->buf = vader_array_buf_forward(_a6_slotarr->buf); }
                                        if ((size_t) l21 >= _a6_slotarr->length) { vader_trap("array index out of bounds"); }
                                        t0 = vader_array_box_slots(_a6_slotarr->buf)[_a6_slotarr->offset + (size_t) l21];
                                        l22 = t0.payload.s;
                                        l23 = concat_3(33u, l22, 75u);
                                        std_string_builder_append(l0, l23);
                                        vader_array_t* _a7_slotarr = ((vader_array_t*) l2);
                                        if (_a7_slotarr->buf != NULL && _a7_slotarr->buf->header.forward != NULL) { _a7_slotarr->buf = vader_array_buf_forward(_a7_slotarr->buf); }
                                        if ((size_t) l21 >= _a7_slotarr->length) { vader_trap("array index out of bounds"); }
                                        t0 = vader_array_box_slots(_a7_slotarr->buf)[_a7_slotarr->offset + (size_t) l21];
                                        l24 = t0.payload.s;
                                        l25 = concat_2(256u, l24);
                                        vader_array_push((vader_array_t*) l4, vader_box_string(167u, l25));
                                    } else {
                                        vader_array_t* _a8_slotarr = ((vader_array_t*) l2);
                                        if (_a8_slotarr->buf != NULL && _a8_slotarr->buf->header.forward != NULL) { _a8_slotarr->buf = vader_array_buf_forward(_a8_slotarr->buf); }
                                        if ((size_t) l21 >= _a8_slotarr->length) { vader_trap("array index out of bounds"); }
                                        t0 = vader_array_box_slots(_a8_slotarr->buf)[_a8_slotarr->offset + (size_t) l21];
                                        l26 = t0.payload.s;
                                        l27 = concat_3(33u, l26, 495u);
                                        std_string_builder_append(l0, l27);
                                    }
                                } else {
                                }
                                t2 = (l21 + INT64_C(1));
                                l21 = (size_t) (int64_t) t2;
                                goto loop_132;
                            } else {
                            }
                        }
                    }
                } else {
                    vader_array_t* _a9_arr = vader_array_new(8u, 0u, 0u, 167u);
                    l28 = (void*) _a9_arr;
                    l29 = ((vader_array_t*) l1)->length;
                    l30 = (size_t) (int64_t) INT64_C(0);
                    {
                        loop_205: {
                            if ((l30 < l29)) {
                                vader_array_t* _a10_slotarr = ((vader_array_t*) l1);
                                if (_a10_slotarr->buf != NULL && _a10_slotarr->buf->header.forward != NULL) { _a10_slotarr->buf = vader_array_buf_forward(_a10_slotarr->buf); }
                                if ((size_t) l30 >= _a10_slotarr->length) { vader_trap("array index out of bounds"); }
                                t0 = vader_array_read_u8(_a10_slotarr, _a10_slotarr->offset + (size_t) l30, 173u);
                                if (((int32_t) t0.payload.i) == l10) {
                                    if (l12) {
                                        vader_array_t* _a11_slotarr = ((vader_array_t*) l2);
                                        if (_a11_slotarr->buf != NULL && _a11_slotarr->buf->header.forward != NULL) { _a11_slotarr->buf = vader_array_buf_forward(_a11_slotarr->buf); }
                                        if ((size_t) l30 >= _a11_slotarr->length) { vader_trap("array index out of bounds"); }
                                        t0 = vader_array_box_slots(_a11_slotarr->buf)[_a11_slotarr->offset + (size_t) l30];
                                        t3 = t0.payload.s;
                                        l31 = concat_2(t3, 84u);
                                        vader_array_push((vader_array_t*) l28, vader_box_string(167u, l31));
                                        vader_array_t* _a12_slotarr = ((vader_array_t*) l2);
                                        if (_a12_slotarr->buf != NULL && _a12_slotarr->buf->header.forward != NULL) { _a12_slotarr->buf = vader_array_buf_forward(_a12_slotarr->buf); }
                                        if ((size_t) l30 >= _a12_slotarr->length) { vader_trap("array index out of bounds"); }
                                        t0 = vader_array_box_slots(_a12_slotarr->buf)[_a12_slotarr->offset + (size_t) l30];
                                        l32 = t0.payload.s;
                                        l33 = concat_2(256u, l32);
                                        vader_array_push((vader_array_t*) l3, vader_box_string(167u, l33));
                                    } else {
                                        vader_array_t* _a13_slotarr = ((vader_array_t*) l2);
                                        if (_a13_slotarr->buf != NULL && _a13_slotarr->buf->header.forward != NULL) { _a13_slotarr->buf = vader_array_buf_forward(_a13_slotarr->buf); }
                                        if ((size_t) l30 >= _a13_slotarr->length) { vader_trap("array index out of bounds"); }
                                        t0 = vader_array_box_slots(_a13_slotarr->buf)[_a13_slotarr->offset + (size_t) l30];
                                        l34 = t0.payload.s;
                                        vader_array_push((vader_array_t*) l28, vader_box_string(167u, l34));
                                    }
                                } else {
                                }
                                t2 = (l30 + INT64_C(1));
                                l30 = (size_t) (int64_t) t2;
                                goto loop_205;
                            } else {
                            }
                        }
                    }
                    l35 = vader_c_emit_c_type_for_val_bare(l10);
                    l36 = std_string_join(l28, 365u);
                    l37 = concat_5(7u, l35, 6u, l36, 495u);
                    std_string_builder_append(l0, l37);
                }
                t2 = (l9 + INT64_C(1));
                l9 = (size_t) (int64_t) t2;
                goto loop_8;
            } else {
            }
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_c_emit_emit_slot_load_prim(void* l0, vader_string_t l1, uint8_t l2, bool l3) {
    vader_box_t l4 = vader_box_null(), l5 = vader_box_null();
    vader_string_t l6 = 0;
    vader_string_t l7 = 0;
    vader_string_t l8 = 0;
    vader_box_t* gc_roots[2] = { &l4, &l5 };
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[4] = { &l1, &l6, &l7, &l8 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l4 = vader_c_emit_pop(l0);
    l5 = vader_c_emit_pop(l0);
    l6 = vader_c_emit_emit_slot_array_local(l0, l5, l4, l3);
    l7 = vader_c_emit_fresh_tmp(l0, l2);
    l8 = vader_c_emit_slot_index(l6, l4);
    l6 = concat_8(l7, 64u, l1, 354u, l6, 394u, l8, 859u);
    vader_c_emit_line(l0, l6);
    vader_c_emit_push_tmp(l0, l7, l2);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_c_emit_emit_slot_store_prim(void* l0, vader_string_t l1, uint8_t l2, bool l3) {
    vader_box_t l4 = vader_box_null(), l5 = vader_box_null(), l6 = vader_box_null();
    vader_string_t l7 = 0;
    vader_box_t* gc_roots[3] = { &l4, &l5, &l6 };
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[2] = { &l1, &l7 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l4 = vader_c_emit_pop(l0);
    l5 = vader_c_emit_pop(l0);
    l6 = vader_c_emit_pop(l0);
    l7 = vader_c_emit_emit_slot_array_local(l0, l6, l5, l3);
    vader_c_emit_emit_typed_slot_write(l0, l7, l5, l4, l1, l2);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_c_emit_emit_str_data_entry(void* l0, size_t l1, void* l2, int32_t l3, int32_t l4, void* l5, bool l6) {
    size_t l7, l11, l15;
    int32_t l8;
    vader_string_t l9 = 0;
    vader_string_t l10 = 0;
    vader_string_t l17 = 0;
    void* l12 = NULL;
    uint64_t l13;
    int64_t l14, l16;
    bool t0;
    int64_t t1;
    vader_box_t t2 = vader_box_null();
    int32_t t3;
    vader_box_t* gc_roots[1] = { &t2 };
    void** gc_raw_roots[4] = { &l0, &l2, &l5, &l12 };
    vader_string_t* gc_atom_roots[3] = { &l9, &l10, &l17 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l7 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcStrData_t*) l2)->f_values)->length;
    l8 = vader_bytecode_array_kind_index((uint8_t) (int32_t) INT32_C(0));
    l9 = vader_c_emit_linkage_prefix(l6);
    t0 = ((vader_struct_vader_bytecode_BcStrData_t*) l2)->f_mutable;
    l10 = vader_c_emit_storage_qualifier(t0);
    l9 = concat_2(l9, l10);
    l10 = l9;
    l11 = vader_host_std_core_byte_len(l10);
    l12 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(212) + l11));
    l11 = (size_t) (int64_t) INT64_C(0);
    l11 = std_core_write_string_at(l12, l11, l10);
    l11 = std_core_write_string_at(l12, l11, 2114u);
    t1 = ((int64_t) (size_t) l7);
    l13 = (uint64_t) (int64_t) t1;
    l11 = std_core_write_unsigned(l12, l11, l13);
    l11 = std_core_write_string_at(l12, l11, 861u);
    t1 = ((int64_t) (size_t) l1);
    l13 = (uint64_t) (int64_t) t1;
    l11 = std_core_write_unsigned(l12, l11, l13);
    l11 = std_core_write_string_at(l12, l11, 902u);
    l10 = std_core_finish_buffer(l12, l11);
    std_string_builder_append(l0, l10);
    l12 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(162));
    l11 = (size_t) (int64_t) INT64_C(0);
    l11 = std_core_write_string_at(l12, l11, 40u);
    t1 = ((int64_t) (size_t) l7);
    l13 = (uint64_t) (int64_t) t1;
    l11 = std_core_write_unsigned(l12, l11, l13);
    l11 = std_core_write_string_at(l12, l11, 2209u);
    t1 = ((int64_t) (size_t) l7);
    l13 = (uint64_t) (int64_t) t1;
    l11 = std_core_write_unsigned(l12, l11, l13);
    l11 = std_core_write_string_at(l12, l11, 2209u);
    l14 = ((int64_t) (int32_t) l4);
    l11 = std_core_write_int(l12, l11, l14);
    l11 = std_core_write_string_at(l12, l11, 2209u);
    l14 = ((int64_t) (int32_t) l8);
    l11 = std_core_write_int(l12, l11, l14);
    l11 = std_core_write_string_at(l12, l11, 2228u);
    l10 = std_core_finish_buffer(l12, l11);
    std_string_builder_append(l0, l10);
    std_string_builder_append(l0, 37u);
    l11 = (size_t) (int64_t) INT64_C(0);
    {
        loop_145: {
            if ((l11 < l7)) {
                if ((l11 > INT64_C(0))) {
                    std_string_builder_append(l0, 364u);
                } else {
                }
                l12 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(62));
                l15 = (size_t) (int64_t) INT64_C(0);
                l15 = std_core_write_string_at(l12, l15, 176u);
                l14 = ((int64_t) (int32_t) l4);
                l15 = std_core_write_int(l12, l15, l14);
                l15 = std_core_write_string_at(l12, l15, 2223u);
                vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcStrData_t*) l2)->f_values);
                if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                if ((size_t) l11 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                t2 = vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l11];
                l10 = t2.payload.s;
                t3 = vader_c_emit_atom_for(l5, l10);
                l16 = ((int64_t) (int32_t) t3);
                l15 = std_core_write_int(l12, l15, l16);
                l15 = std_core_write_string_at(l12, l15, 2202u);
                l17 = std_core_finish_buffer(l12, l15);
                std_string_builder_append(l0, l17);
                t1 = (l11 + INT64_C(1));
                l11 = (size_t) (int64_t) t1;
                goto loop_145;
            } else {
            }
        }
    }
    std_string_builder_append(l0, 202u);
    std_string_builder_append(l0, 2429u);
    l11 = vader_host_std_core_byte_len(l9);
    l12 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(206) + l11));
    l11 = (size_t) (int64_t) INT64_C(0);
    l11 = std_core_write_string_at(l12, l11, l9);
    l11 = std_core_write_string_at(l12, l11, 2316u);
    t1 = ((int64_t) (size_t) l1);
    l13 = (uint64_t) (int64_t) t1;
    l11 = std_core_write_unsigned(l12, l11, l13);
    l11 = std_core_write_string_at(l12, l11, 87u);
    l14 = ((int64_t) (int32_t) l3);
    l11 = std_core_write_int(l12, l11, l14);
    l11 = std_core_write_string_at(l12, l11, 2220u);
    t1 = ((int64_t) (size_t) l7);
    l13 = (uint64_t) (int64_t) t1;
    l11 = std_core_write_unsigned(l12, l11, l13);
    l11 = std_core_write_string_at(l12, l11, 2209u);
    t1 = ((int64_t) (size_t) l7);
    l13 = (uint64_t) (int64_t) t1;
    l11 = std_core_write_unsigned(l12, l11, l13);
    l11 = std_core_write_string_at(l12, l11, 2218u);
    t1 = ((int64_t) (size_t) l1);
    l13 = (uint64_t) (int64_t) t1;
    l11 = std_core_write_unsigned(l12, l11, l13);
    l11 = std_core_write_string_at(l12, l11, 903u);
    l9 = std_core_finish_buffer(l12, l11);
    std_string_builder_append(l0, l9);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_c_emit_emit_string_slice(void* l0) {
    vader_box_t l1 = vader_box_null(), l2 = vader_box_null();
    vader_string_t l3 = 0;
    vader_string_t l4 = 0;
    vader_string_t l5 = 0;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l1, &l2, &t0 };
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[3] = { &l3, &l4, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l1 = vader_c_emit_pop(l0);
    l2 = vader_c_emit_pop(l0);
    t0 = vader_c_emit_pop(l0);
    l3 = vader_c_emit_name_of(t0);
    l4 = vader_c_emit_name_of(l2);
    l5 = vader_c_emit_name_of(l1);
    l3 = concat_7(2358u, l3, 365u, l4, 365u, l5, 318u);
    vader_c_emit_push_into_tmp(l0, l3, (uint8_t) (int32_t) INT32_C(14));
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_c_emit_emit_struct_body(void* l0, void* l1, size_t l2, void* l3) {
    vader_string_t l4 = 0;
    vader_string_t l10 = 0;
    vader_string_t l11 = 0;
    size_t l5, l6, l9;
    void* l7 = NULL;
    void* l8 = NULL;
    vader_box_t t0 = vader_box_null();
    int32_t t1;
    int64_t t2;
    vader_string_t t3 = 0;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[5] = { &l0, &l1, &l3, &l7, &l8 };
    vader_string_t* gc_atom_roots[4] = { &l4, &l10, &l11, &t3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_struct_c_names);
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    if ((size_t) l2 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
    t0 = vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l2];
    l4 = t0.payload.s;
    l4 = concat_3(2109u, l4, 175u);
    std_string_builder_append(l3, l4);
    std_string_builder_append(l3, 29u);
    l5 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcStruct_t*) l1)->f_fields)->length;
    l6 = (size_t) (int64_t) INT64_C(0);
    {
        loop_22: {
            if ((l6 < l5)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcStruct_t*) l1)->f_fields);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l6 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                l7 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l6);
                l8 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_types;
                t1 = ((vader_struct_vader_bytecode_BcField_t*) l7)->f_type_index;
                t2 = ((int64_t) (int32_t) t1);
                l9 = (size_t) (int64_t) t2;
                vader_array_t* _a2_slotarr = ((vader_array_t*) l8);
                if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                if ((size_t) l9 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l9);
                l4 = vader_c_emit_c_type_for(t0);
                t3 = ((vader_struct_vader_bytecode_BcField_t*) l7)->f_name;
                l10 = vader_c_emit_sanitise(t3);
                l11 = concat_5(7u, l4, 111u, l10, 495u);
                std_string_builder_append(l3, l11);
                t2 = (l6 + INT64_C(1));
                l6 = (size_t) (int64_t) t2;
                goto loop_22;
            } else {
            }
        }
    }
    std_string_builder_append(l3, 2429u);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_c_emit_emit_struct_get(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null();
    int32_t l3, l4;
    vader_string_t l5 = 0;
    uint8_t l6;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_string_t* gc_atom_roots[1] = { &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = vader_c_emit_pop(l0);
    l3 = ((vader_struct_vader_bytecode_StructGet_t*) l1)->f_type_id;
    l4 = ((vader_struct_vader_bytecode_StructGet_t*) l1)->f_field_index;
    l5 = vader_c_emit_name_of(l2);
    l6 = vader_c_emit_val_of(l2);
    vader_c_emit_push_struct_field(l0, l3, l4, l5, l6);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_c_emit_emit_struct_info_row(void* l0, void* l1, void* l2, size_t l3, void* l4) {
    vader_string_t l5 = 0;
    vader_string_t l9 = 0;
    vader_string_t l13 = 0;
    vader_string_t l14 = 0;
    size_t l6, l7, l8, l11, l15;
    void* l10 = NULL;
    uint64_t l12;
    vader_box_t t0 = vader_box_null();
    int64_t t1;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l4, &l10 };
    vader_string_t* gc_atom_roots[4] = { &l5, &l9, &l13, &l14 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_struct_c_names);
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
    t0 = vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l3];
    l5 = t0.payload.s;
    l6 = ((vader_array_t*) ((vader_struct_vader_c_emit_StructOffsets_t*) l2)->f_ptr_offsets)->length;
    l7 = ((vader_array_t*) ((vader_struct_vader_c_emit_StructOffsets_t*) l2)->f_str_offsets)->length;
    l8 = ((vader_array_t*) ((vader_struct_vader_c_emit_StructOffsets_t*) l2)->f_ref_offsets)->length;
    if ((l6 > INT64_C(0))) {
        l10 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(36));
        l11 = (size_t) (int64_t) INT64_C(0);
        l11 = std_core_write_string_at(l10, l11, 2362u);
        t1 = ((int64_t) (size_t) l3);
        l12 = (uint64_t) (int64_t) t1;
        l11 = std_core_write_unsigned(l10, l11, l12);
        l11 = std_core_write_string_at(l10, l11, 907u);
        l9 = std_core_finish_buffer(l10, l11);
    } else {
        l9 = 651u;
    }
    if ((l7 > INT64_C(0))) {
        l10 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(36));
        l11 = (size_t) (int64_t) INT64_C(0);
        l11 = std_core_write_string_at(l10, l11, 2362u);
        t1 = ((int64_t) (size_t) l3);
        l12 = (uint64_t) (int64_t) t1;
        l11 = std_core_write_unsigned(l10, l11, l12);
        l11 = std_core_write_string_at(l10, l11, 915u);
        l13 = std_core_finish_buffer(l10, l11);
    } else {
        l13 = 651u;
    }
    if ((l8 > INT64_C(0))) {
        l10 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(36));
        l11 = (size_t) (int64_t) INT64_C(0);
        l11 = std_core_write_string_at(l10, l11, 2362u);
        t1 = ((int64_t) (size_t) l3);
        l12 = (uint64_t) (int64_t) t1;
        l11 = std_core_write_unsigned(l10, l11, l12);
        l11 = std_core_write_string_at(l10, l11, 912u);
        l14 = std_core_finish_buffer(l10, l11);
    } else {
        l14 = 651u;
    }
    l11 = vader_host_std_core_byte_len(l5);
    l15 = vader_host_std_core_byte_len(l9);
    t1 = (l11 + l15);
    l11 = (size_t) (int64_t) t1;
    l15 = vader_host_std_core_byte_len(l13);
    t1 = (l11 + l15);
    l11 = (size_t) (int64_t) t1;
    l15 = vader_host_std_core_byte_len(l14);
    t1 = (l11 + l15);
    l11 = (size_t) (int64_t) t1;
    l10 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(139) + l11));
    l11 = (size_t) (int64_t) INT64_C(0);
    l11 = std_core_write_string_at(l10, l11, 13u);
    t1 = ((int64_t) (size_t) l3);
    l12 = (uint64_t) (int64_t) t1;
    l11 = std_core_write_unsigned(l10, l11, l12);
    l11 = std_core_write_string_at(l10, l11, 856u);
    l11 = std_core_write_string_at(l10, l11, l5);
    l11 = std_core_write_string_at(l10, l11, 344u);
    l11 = std_core_write_string_at(l10, l11, l9);
    l11 = std_core_write_string_at(l10, l11, 365u);
    t1 = ((int64_t) (size_t) l6);
    l12 = (uint64_t) (int64_t) t1;
    l11 = std_core_write_unsigned(l10, l11, l12);
    l11 = std_core_write_string_at(l10, l11, 365u);
    t1 = ((int64_t) (size_t) l7);
    l12 = (uint64_t) (int64_t) t1;
    l11 = std_core_write_unsigned(l10, l11, l12);
    l11 = std_core_write_string_at(l10, l11, 365u);
    l11 = std_core_write_string_at(l10, l11, l13);
    l11 = std_core_write_string_at(l10, l11, 365u);
    t1 = ((int64_t) (size_t) l8);
    l12 = (uint64_t) (int64_t) t1;
    l11 = std_core_write_unsigned(l10, l11, l12);
    l11 = std_core_write_string_at(l10, l11, 365u);
    l11 = std_core_write_string_at(l10, l11, l14);
    l11 = std_core_write_string_at(l10, l11, 207u);
    l5 = std_core_finish_buffer(l10, l11);
    std_string_builder_append(l4, l5);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_c_emit_emit_struct_new(void* l0, void* l1) {
    void* l2 = NULL;
    void* l5 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    void* l13 = NULL;
    void* l16 = NULL;
    size_t l3, l12;
    vader_box_t l4 = vader_box_null();
    vader_string_t l6 = 0;
    vader_string_t l14 = 0;
    vader_string_t l19 = 0;
    vader_string_t l20 = 0;
    int32_t l7, l8, l9, l17;
    uint8_t l15, l18;
    int64_t l21;
    uint64_t l22;
    int32_t t0;
    int64_t t1;
    vader_box_t t2 = vader_box_null();
    size_t t3;
    bool t4;
    vader_string_t t5 = 0;
    vader_box_t* gc_roots[2] = { &l4, &t2 };
    void** gc_raw_roots[8] = { &l0, &l1, &l2, &l5, &l10, &l11, &l13, &l16 };
    vader_string_t* gc_atom_roots[5] = { &l6, &l14, &l19, &l20, &t5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 5u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_ctx)->f_module)->f_types;
    t0 = ((vader_struct_vader_bytecode_StructNew_t*) l1)->f_type_id;
    t1 = ((int64_t) (int32_t) t0);
    l3 = (size_t) (int64_t) t1;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
    l4 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
    if (l4.tag == 509u) {
        l2 = l4.payload.obj;
        l5 = ((vader_struct_vader_c_emit_EmitCtx_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_ctx)->f_struct_c_names;
        t0 = ((vader_struct_vader_bytecode_StructNew_t*) l1)->f_type_id;
        t1 = ((int64_t) (int32_t) t0);
        l3 = (size_t) (int64_t) t1;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
        if ((size_t) l3 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
        t2 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l3];
        l6 = t2.payload.s;
        t3 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcStruct_t*) l2)->f_fields)->length;
        l7 = ((int32_t) (size_t) t3);
        vader_array_t* _a2_arr = vader_array_new(8u, 0u, 0u, 167u);
        l5 = (void*) _a2_arr;
        l8 = INT32_C(0);
        {
            loop_38: {
                if ((l8 < l7)) {
                    vader_array_push((vader_array_t*) l5, vader_box_string(167u, 0u));
                    l8 = (l8 + INT32_C(1));
                    goto loop_38;
                } else {
                }
            }
        }
        l8 = INT32_C(0);
        {
            loop_58: {
                if ((l8 < l7)) {
                    l4 = vader_c_emit_pop(l0);
                    l9 = ((l7 - INT32_C(1)) - l8);
                    l10 = ((vader_struct_vader_bytecode_BcStruct_t*) l2)->f_fields;
                    t1 = ((int64_t) (int32_t) l9);
                    l3 = (size_t) (int64_t) t1;
                    vader_array_t* _a3_slotarr = ((vader_array_t*) l10);
                    if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                    if ((size_t) l3 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                    l11 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l3);
                    t1 = ((int64_t) (int32_t) l9);
                    l12 = (size_t) (int64_t) t1;
                    l13 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_ctx)->f_module)->f_types;
                    l14 = vader_c_emit_name_of(l4);
                    l15 = vader_c_emit_val_of(l4);
                    l16 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_ctx)->f_module)->f_types;
                    l17 = ((vader_struct_vader_bytecode_BcField_t*) l11)->f_type_index;
                    l18 = vader_c_emit_val_type_of_field(l16, l17);
                    l19 = vader_c_emit_coerce_expr(l13, l14, l15, l18);
                    vader_array_t* _a4_slotarr = ((vader_array_t*) l5);
                    if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                    if ((size_t) l12 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                    vader_array_box_slots(_a4_slotarr->buf)[_a4_slotarr->offset + (size_t) l12] = vader_box_string(167u, l19);
                    VADER_WRITE_BARRIER(_a4_slotarr->buf);
                    l8 = (l8 + INT32_C(1));
                    goto loop_58;
                } else {
                }
            }
        }
        t4 = ((vader_struct_vader_bytecode_StructNew_t*) l1)->f_stack;
        if (t4) {
            l19 = vader_c_emit_aux(l0, 2073u);
            l20 = vader_c_emit_aux(l0, 1909u);
            l10 = ((vader_struct_vader_c_emit_FnState_t*) l0)->f_stack_storages;
            vader_struct_vader_c_emit_StackStorage_t* _a5_obj = (vader_struct_vader_c_emit_StackStorage_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_StackStorage_t));
            vader_obj_header_init(_a5_obj, 673u);
            _a5_obj->f_cname = l6;
            _a5_obj->f_storage = l19;
            l11 = (void*) _a5_obj;
            vader_array_push((vader_array_t*) l10, vader_ref_box(l11));
            l19 = concat_6(l6, 353u, l20, 62u, l19, 494u);
            vader_c_emit_line(l0, l19);
            l14 = l20;
        } else {
            l19 = vader_c_emit_aux(l0, 1909u);
            l6 = concat_8(l6, 353u, l19, 63u, l6, 359u, l6, 343u);
            vader_c_emit_line(l0, l6);
            l14 = l19;
        }
        l6 = l14;
        l3 = vader_host_std_core_byte_len(l6);
        l10 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(47) + l3));
        l3 = (size_t) (int64_t) INT64_C(0);
        l3 = std_core_write_string_at(l10, l3, 2352u);
        l3 = std_core_write_string_at(l10, l3, l6);
        l3 = std_core_write_string_at(l10, l3, 365u);
        t0 = ((vader_struct_vader_bytecode_StructNew_t*) l1)->f_type_id;
        l21 = ((int64_t) (int32_t) t0);
        l3 = std_core_write_int(l10, l3, l21);
        l3 = std_core_write_string_at(l10, l3, 2205u);
        l6 = std_core_finish_buffer(l10, l3);
        vader_c_emit_line(l0, l6);
        l8 = INT32_C(0);
        {
            loop_228: {
                if ((l8 < l7)) {
                    l10 = ((vader_struct_vader_bytecode_BcStruct_t*) l2)->f_fields;
                    t1 = ((int64_t) (int32_t) l8);
                    l3 = (size_t) (int64_t) t1;
                    vader_array_t* _a6_slotarr = ((vader_array_t*) l10);
                    if (_a6_slotarr->buf != NULL && _a6_slotarr->buf->header.forward != NULL) { _a6_slotarr->buf = vader_array_buf_forward(_a6_slotarr->buf); }
                    if ((size_t) l3 >= _a6_slotarr->length) { vader_trap("array index out of bounds"); }
                    l11 = vader_array_ref_load_obj(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l3);
                    t5 = ((vader_struct_vader_bytecode_BcField_t*) l11)->f_name;
                    l6 = vader_c_emit_sanitise(t5);
                    t1 = ((int64_t) (int32_t) l8);
                    l12 = (size_t) (int64_t) t1;
                    vader_array_t* _a7_slotarr = ((vader_array_t*) l5);
                    if (_a7_slotarr->buf != NULL && _a7_slotarr->buf->header.forward != NULL) { _a7_slotarr->buf = vader_array_buf_forward(_a7_slotarr->buf); }
                    if ((size_t) l12 >= _a7_slotarr->length) { vader_trap("array index out of bounds"); }
                    t2 = vader_array_box_slots(_a7_slotarr->buf)[_a7_slotarr->offset + (size_t) l12];
                    l19 = t2.payload.s;
                    l20 = concat_6(l14, 400u, l6, 61u, l19, 494u);
                    vader_c_emit_line(l0, l20);
                    l8 = (l8 + INT32_C(1));
                    goto loop_228;
                } else {
                }
            }
        }
        l6 = vader_c_emit_fresh_tmp(l0, (uint8_t) (int32_t) INT32_C(18));
        l14 = concat_4(l6, 69u, l14, 494u);
        vader_c_emit_line(l0, l14);
        vader_c_emit_push_tmp(l0, l6, (uint8_t) (int32_t) INT32_C(18));
    } else {
        l2 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_ctx)->f_module)->f_types;
        t0 = ((vader_struct_vader_bytecode_StructNew_t*) l1)->f_type_id;
        t1 = ((int64_t) (int32_t) t0);
        l3 = (size_t) (int64_t) t1;
        l12 = ((vader_array_t*) l2)->length;
        if ((l3 >= l12)) {
            l5 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(56));
            l3 = (size_t) (int64_t) INT64_C(0);
            l3 = std_core_write_string_at(l5, l3, 1717u);
            t3 = ((vader_array_t*) l2)->length;
            t1 = ((int64_t) (size_t) t3);
            l22 = (uint64_t) (int64_t) t1;
            l3 = std_core_write_unsigned(l5, l3, l22);
            l3 = std_core_write_string_at(l5, l3, 405u);
            l6 = std_core_finish_buffer(l5, l3);
        } else {
            l7 = ((vader_struct_vader_bytecode_StructNew_t*) l1)->f_type_id;
            l14 = vader_bytecode_bc_type_key(l2, l7);
            l3 = vader_host_std_core_byte_len(l14);
            l5 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(53) + l3));
            l3 = (size_t) (int64_t) INT64_C(0);
            l3 = std_core_write_string_at(l5, l3, 2141u);
            l3 = std_core_write_string_at(l5, l3, l14);
            l3 = std_core_write_string_at(l5, l3, 964u);
            t3 = ((vader_array_t*) l2)->length;
            t1 = ((int64_t) (size_t) t3);
            l22 = (uint64_t) (int64_t) t1;
            l3 = std_core_write_unsigned(l5, l3, l22);
            l3 = std_core_write_string_at(l5, l3, 405u);
            l6 = std_core_finish_buffer(l5, l3);
        }
        l3 = vader_host_std_core_byte_len(l6);
        l2 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(52) + l3));
        l3 = (size_t) (int64_t) INT64_C(0);
        l3 = std_core_write_string_at(l2, l3, 2117u);
        t0 = ((vader_struct_vader_bytecode_StructNew_t*) l1)->f_type_id;
        l21 = ((int64_t) (int32_t) t0);
        l3 = std_core_write_int(l2, l3, l21);
        l3 = std_core_write_string_at(l2, l3, 463u);
        l3 = std_core_write_string_at(l2, l3, l6);
        t5 = std_core_finish_buffer(l2, l3);
        std_abort_todo(t5);
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_c_emit_emit_struct_offset_arrays(void* l0, size_t l1, void* l2, bool l3) {
    vader_string_t l4 = 0;
    vader_string_t l5 = 0;
    vader_string_t l6 = 0;
    size_t l7, l8;
    void* l9 = NULL;
    uint64_t l10;
    size_t t0;
    int64_t t1;
    void** gc_raw_roots[3] = { &l0, &l2, &l9 };
    vader_string_t* gc_atom_roots[3] = { &l4, &l5, &l6 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l4 = vader_c_emit_linkage_prefix(l3);
    t0 = ((vader_array_t*) ((vader_struct_vader_c_emit_StructOffsets_t*) l0)->f_ptr_offsets)->length;
    if ((t0 > INT64_C(0))) {
        l5 = l4;
        l6 = std_string_join(((vader_struct_vader_c_emit_StructOffsets_t*) l0)->f_ptr_offsets, 365u);
        l7 = vader_host_std_core_byte_len(l5);
        l8 = vader_host_std_core_byte_len(l6);
        t1 = (l7 + l8);
        l7 = (size_t) (int64_t) t1;
        l9 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(62) + l7));
        l7 = (size_t) (int64_t) INT64_C(0);
        l7 = std_core_write_string_at(l9, l7, l5);
        l7 = std_core_write_string_at(l9, l7, 1408u);
        t1 = ((int64_t) (size_t) l1);
        l10 = (uint64_t) (int64_t) t1;
        l7 = std_core_write_unsigned(l9, l7, l10);
        l7 = std_core_write_string_at(l9, l7, 909u);
        l7 = std_core_write_string_at(l9, l7, l6);
        l7 = std_core_write_string_at(l9, l7, 209u);
        l5 = std_core_finish_buffer(l9, l7);
        std_string_builder_append(l2, l5);
    } else {
    }
    t0 = ((vader_array_t*) ((vader_struct_vader_c_emit_StructOffsets_t*) l0)->f_str_offsets)->length;
    if ((t0 > INT64_C(0))) {
        l5 = l4;
        l6 = std_string_join(((vader_struct_vader_c_emit_StructOffsets_t*) l0)->f_str_offsets, 365u);
        l7 = vader_host_std_core_byte_len(l5);
        l8 = vader_host_std_core_byte_len(l6);
        t1 = (l7 + l8);
        l7 = (size_t) (int64_t) t1;
        l9 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(62) + l7));
        l7 = (size_t) (int64_t) INT64_C(0);
        l7 = std_core_write_string_at(l9, l7, l5);
        l7 = std_core_write_string_at(l9, l7, 1408u);
        t1 = ((int64_t) (size_t) l1);
        l10 = (uint64_t) (int64_t) t1;
        l7 = std_core_write_unsigned(l9, l7, l10);
        l7 = std_core_write_string_at(l9, l7, 916u);
        l7 = std_core_write_string_at(l9, l7, l6);
        l7 = std_core_write_string_at(l9, l7, 209u);
        l5 = std_core_finish_buffer(l9, l7);
        std_string_builder_append(l2, l5);
    } else {
    }
    t0 = ((vader_array_t*) ((vader_struct_vader_c_emit_StructOffsets_t*) l0)->f_ref_offsets)->length;
    if ((t0 > INT64_C(0))) {
        l5 = std_string_join(((vader_struct_vader_c_emit_StructOffsets_t*) l0)->f_ref_offsets, 365u);
        l7 = vader_host_std_core_byte_len(l4);
        l8 = vader_host_std_core_byte_len(l5);
        t1 = (l7 + l8);
        l7 = (size_t) (int64_t) t1;
        l9 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(62) + l7));
        l7 = (size_t) (int64_t) INT64_C(0);
        l7 = std_core_write_string_at(l9, l7, l4);
        l7 = std_core_write_string_at(l9, l7, 1408u);
        t1 = ((int64_t) (size_t) l1);
        l10 = (uint64_t) (int64_t) t1;
        l7 = std_core_write_unsigned(l9, l7, l10);
        l7 = std_core_write_string_at(l9, l7, 913u);
        l7 = std_core_write_string_at(l9, l7, l5);
        l7 = std_core_write_string_at(l9, l7, 209u);
        l4 = std_core_finish_buffer(l9, l7);
        std_string_builder_append(l2, l4);
    } else {
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_c_emit_emit_struct_set(void* l0, void* l1) {
    void* l2 = NULL;
    void* l5 = NULL;
    void* l10 = NULL;
    size_t l3;
    vader_box_t l4 = vader_box_null(), l7 = vader_box_null();
    vader_string_t l6 = 0;
    vader_string_t l8 = 0;
    vader_string_t l13 = 0;
    vader_string_t l14 = 0;
    uint8_t l9, l12;
    int32_t l11;
    int64_t l15;
    int32_t t0;
    int64_t t1;
    vader_box_t t2 = vader_box_null();
    vader_string_t t3 = 0;
    bool t4;
    vader_box_t* gc_roots[3] = { &l4, &l7, &t2 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l5, &l10 };
    vader_string_t* gc_atom_roots[5] = { &l6, &l8, &l13, &l14, &t3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 5u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_ctx)->f_module)->f_types;
    t0 = ((vader_struct_vader_bytecode_StructSet_t*) l1)->f_type_id;
    t1 = ((int64_t) (int32_t) t0);
    l3 = (size_t) (int64_t) t1;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
    l4 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
    if (l4.tag == 509u) {
        l2 = l4.payload.obj;
        l5 = ((vader_struct_vader_c_emit_EmitCtx_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_ctx)->f_struct_c_names;
        t0 = ((vader_struct_vader_bytecode_StructSet_t*) l1)->f_type_id;
        t1 = ((int64_t) (int32_t) t0);
        l3 = (size_t) (int64_t) t1;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
        if ((size_t) l3 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
        t2 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l3];
        l6 = t2.payload.s;
        l4 = vader_c_emit_pop(l0);
        l7 = vader_c_emit_pop(l0);
        l2 = ((vader_struct_vader_bytecode_BcStruct_t*) l2)->f_fields;
        t0 = ((vader_struct_vader_bytecode_StructSet_t*) l1)->f_field_index;
        t1 = ((int64_t) (int32_t) t0);
        l3 = (size_t) (int64_t) t1;
        vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
        if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
        if ((size_t) l3 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
        l2 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l3);
        l5 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_ctx)->f_module)->f_types;
        l8 = vader_c_emit_name_of(l4);
        l9 = vader_c_emit_val_of(l4);
        l10 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_ctx)->f_module)->f_types;
        l11 = ((vader_struct_vader_bytecode_BcField_t*) l2)->f_type_index;
        l12 = vader_c_emit_val_type_of_field(l10, l11);
        l8 = vader_c_emit_coerce_expr(l5, l8, l9, l12);
        l13 = vader_c_emit_obj_ptr_of(l7);
        t3 = ((vader_struct_vader_bytecode_BcField_t*) l2)->f_name;
        l14 = vader_c_emit_sanitise(t3);
        l8 = concat_9(279u, l6, 354u, l13, 347u, l14, 61u, l8, 494u);
        vader_c_emit_line(l0, l8);
        t4 = ((vader_struct_vader_bytecode_StructSet_t*) l1)->f_stack;
        if (!(t4)) {
            l6 = concat_5(825u, l6, 354u, l13, 349u);
            vader_c_emit_line(l0, l6);
        } else {
        }
    } else {
        l2 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(50));
        l3 = (size_t) (int64_t) INT64_C(0);
        l3 = std_core_write_string_at(l2, l3, 2121u);
        t0 = ((vader_struct_vader_bytecode_StructSet_t*) l1)->f_type_id;
        l15 = ((int64_t) (int32_t) t0);
        l3 = std_core_write_int(l2, l3, l15);
        t3 = std_core_finish_buffer(l2, l3);
        std_abort_todo(t3);
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_c_emit_emit_struct_typedefs(void* l0, void* l1) {
    size_t l2, l3;
    bool l4;
    vader_string_t l5 = 0;
    vader_string_t l6 = 0;
    void* l7 = NULL;
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    vader_string_t t2 = 0;
    bool t3;
    int64_t t4;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[4] = { &l0, &l1, &l7, &t1 };
    vader_string_t* gc_atom_roots[3] = { &l5, &l6, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_types)->length;
    l3 = (size_t) (int64_t) INT64_C(0);
    {
        loop_7: {
            if ((l3 < l2)) {
                vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_types);
                if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
                if (t0.tag == 509u) {
                    vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_types);
                    if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                    if ((size_t) l3 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                    t0 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l3);
                    t1 = t0.payload.obj;
                    t2 = ((vader_struct_vader_bytecode_BcStruct_t*) t1)->f_c_name;
                    if (t2 == 0u) {
                        l4 = true;
                    } else {
                        t3 = ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_split;
                        l4 = !(t3);
                    }
                    if (l4) {
                        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_struct_c_names);
                        if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                        if ((size_t) l3 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                        t0 = vader_array_box_slots(_a2_slotarr->buf)[_a2_slotarr->offset + (size_t) l3];
                        l5 = t0.payload.s;
                        l6 = concat_5(2196u, l5, 6u, l5, 495u);
                        std_string_builder_append(l1, l6);
                    } else {
                    }
                } else {
                }
                t4 = (l3 + INT64_C(1));
                l3 = (size_t) (int64_t) t4;
                goto loop_7;
            } else {
            }
        }
    }
    std_string_builder_append(l1, 1u);
    l2 = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_types)->length;
    l3 = (size_t) (int64_t) INT64_C(0);
    {
        loop_76: {
            if ((l3 < l2)) {
                vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_types);
                if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                if ((size_t) l3 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l3);
                if (t0.tag == 509u) {
                    vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_types);
                    if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                    if ((size_t) l3 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                    t0 = vader_array_ref_load_box(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l3);
                    l7 = t0.payload.obj;
                    t2 = ((vader_struct_vader_bytecode_BcStruct_t*) l7)->f_c_name;
                    if (t2 == 0u) {
                        l4 = true;
                    } else {
                        t3 = ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_split;
                        l4 = !(t3);
                    }
                    if (l4) {
                        vader_c_emit_emit_struct_body(l0, l7, l3, l1);
                    } else {
                    }
                } else {
                }
                t4 = (l3 + INT64_C(1));
                l3 = (size_t) (int64_t) t4;
                goto loop_76;
            } else {
            }
        }
    }
    std_string_builder_append(l1, 1u);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_c_emit_emit_tmp_decls(void* l0, void* l1, void* l2, void* l3, void* l4, bool l5) {
    void* l6 = NULL;
    void* l9 = NULL;
    size_t l7, l8, l10;
    uint64_t l11;
    vader_string_t l12 = 0;
    int64_t t0;
    void** gc_raw_roots[7] = { &l0, &l1, &l2, &l3, &l4, &l6, &l9 };
    vader_string_t* gc_atom_roots[1] = { &l12 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 7u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 167u);
    l6 = (void*) _a0_arr;
    l7 = ((vader_array_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_tmp_types)->length;
    l8 = (size_t) (int64_t) INT64_C(0);
    {
        loop_8: {
            if ((l8 < l7)) {
                l9 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(21));
                l10 = (size_t) (int64_t) INT64_C(0);
                l10 = std_core_write_string_at(l9, l10, 2133u);
                t0 = ((int64_t) (size_t) l8);
                l11 = (uint64_t) (int64_t) t0;
                l10 = std_core_write_unsigned(l9, l10, l11);
                l12 = std_core_finish_buffer(l9, l10);
                vader_array_push((vader_array_t*) l6, vader_box_string(167u, l12));
                t0 = (l8 + INT64_C(1));
                l8 = (size_t) (int64_t) t0;
                goto loop_8;
            } else {
            }
        }
    }
    l9 = ((vader_struct_vader_c_emit_FnState_t*) l0)->f_tmp_types;
    vader_c_emit_emit_slot_decls(l1, l9, l6, l2, l3, l4, l5);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_c_emit_emit_type_check(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l6 = vader_box_null();
    uint8_t l3;
    void* l4 = NULL;
    void* l7 = NULL;
    size_t l5, l8;
    int32_t l9;
    vader_string_t l10 = 0;
    vader_string_t l11 = 0;
    bool t0;
    int32_t t1;
    int64_t t2;
    vader_box_t* gc_roots[2] = { &l2, &l6 };
    void** gc_raw_roots[4] = { &l0, &l1, &l4, &l7 };
    vader_string_t* gc_atom_roots[2] = { &l10, &l11 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
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
        if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
        if ((size_t) l5 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
        l6 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
        if (l6.tag == 510u) {
            l4 = l6.payload.obj;
            vader_array_t* _a1_arr = vader_array_new(8u, 0u, 0u, 167u);
            l7 = (void*) _a1_arr;
            l4 = ((vader_struct_vader_bytecode_BcUnion_t*) l4)->f_variants;
            l5 = ((vader_array_t*) l4)->length;
            l8 = (size_t) (int64_t) INT64_C(0);
            {
                loop_33: {
                    if ((l8 < l5)) {
                        vader_array_t* _a2_slotarr = ((vader_array_t*) l4);
                        if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                        if ((size_t) l8 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                        l9 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l8];
                        l10 = vader_c_emit_tag_of(l2);
                        l11 = vader_c_emit_one_variant_check(l0, l10, l9);
                        vader_array_push((vader_array_t*) l7, vader_box_string(167u, l11));
                        t2 = (l8 + INT64_C(1));
                        l8 = (size_t) (int64_t) t2;
                        goto loop_33;
                    } else {
                    }
                }
            }
            l10 = std_string_join(l7, 200u);
            l10 = concat_3(278u, l10, 318u);
            vader_c_emit_push_expr(l0, (uint8_t) (int32_t) INT32_C(12), l10);
            { vader_gc_top = gc_frame.prev; return; }
        }
        l10 = vader_c_emit_tag_of(l2);
        l9 = ((vader_struct_vader_bytecode_TypeCheck_t*) l1)->f_type_id;
        l10 = vader_c_emit_one_variant_check(l0, l10, l9);
        vader_c_emit_push_expr(l0, (uint8_t) (int32_t) INT32_C(12), l10);
        { vader_gc_top = gc_frame.prev; return; }
    }
    l4 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_ctx)->f_module)->f_types;
    l9 = ((vader_struct_vader_bytecode_TypeCheck_t*) l1)->f_type_id;
    t0 = vader_c_emit_primitive_matches_type(l4, l3, l9);
    if (t0) {
        l10 = 2164u;
    } else {
        l10 = 1557u;
    }
    vader_c_emit_push_lit(l0, (uint8_t) (int32_t) INT32_C(12), l10);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_c_emit_emit_type_const(void* l0, void* l1) {
    void* l2 = NULL;
    size_t l3;
    int64_t l4;
    vader_string_t l5 = 0;
    int32_t t0;
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_string_t* gc_atom_roots[1] = { &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(77));
    l3 = (size_t) (int64_t) INT64_C(0);
    l3 = std_core_write_string_at(l2, l3, 2324u);
    t0 = ((vader_struct_vader_c_emit_EmitCtx_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_ctx)->f_null_tag;
    l4 = ((int64_t) (int32_t) t0);
    l3 = std_core_write_int(l2, l3, l4);
    l3 = std_core_write_string_at(l2, l3, 2216u);
    t0 = ((vader_struct_vader_bytecode_TypeConst_t*) l1)->f_type_id;
    l4 = ((int64_t) (int32_t) t0);
    l3 = std_core_write_int(l2, l3, l4);
    l3 = std_core_write_string_at(l2, l3, 2203u);
    l5 = std_core_finish_buffer(l2, l3);
    vader_c_emit_push_lit(l0, (uint8_t) (int32_t) INT32_C(19), l5);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_c_emit_emit_type_info_table(void* l0, void* l1) {
    void* l2 = NULL;
    void* l4 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l12 = NULL;
    void* l16 = NULL;
    void* l19 = NULL;
    void* l23 = NULL;
    void* l24 = NULL;
    size_t l3, l5, l11, l13, l18, l20;
    vader_box_t l6 = vader_box_null();
    bool l9;
    vader_string_t l10 = 0;
    vader_string_t l15 = 0;
    vader_string_t l17 = 0;
    vader_string_t l22 = 0;
    uint64_t l14, l21, l25, l26;
    int64_t l27;
    bool t0;
    int64_t t1;
    vader_box_t t2 = vader_box_null();
    int32_t t3;
    vader_box_t* gc_roots[2] = { &l6, &t2 };
    void** gc_raw_roots[11] = { &l0, &l1, &l2, &l4, &l7, &l8, &l12, &l16, &l19, &l23, &l24 };
    vader_string_t* gc_atom_roots[4] = { &l10, &l15, &l17, &l22 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 11u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_types;
    l3 = ((vader_array_t*) l2)->length;
    vader_array_t* _a0_arr = vader_array_new(47u, 0u, 13u, 675u);
    l4 = (void*) _a0_arr;
    l5 = (size_t) (int64_t) INT64_C(0);
    {
        loop_10: {
            if ((l5 < l3)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l5 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                l6 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5);
                if (l6.tag == 509u) {
                    l7 = l6.payload.obj;
                    l8 = vader_c_emit_classify_struct_fields(l0, l7, l5);
                    l9 = ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_split;
                    vader_c_emit_emit_struct_offset_arrays(l8, l5, l1, l9);
                    vader_array_push((vader_array_t*) l4, vader_ref_box(l8));
                } else {
                    if (l6.tag == 499u) {
                        t0 = ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_split;
                        l10 = vader_c_emit_linkage_prefix(t0);
                        l11 = vader_host_std_core_byte_len(l10);
                        l12 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(87) + l11));
                        l13 = (size_t) (int64_t) INT64_C(0);
                        l13 = std_core_write_string_at(l12, l13, l10);
                        l13 = std_core_write_string_at(l12, l13, 1408u);
                        t1 = ((int64_t) (size_t) l5);
                        l14 = (uint64_t) (int64_t) t1;
                        l13 = std_core_write_unsigned(l12, l13, l14);
                        l13 = std_core_write_string_at(l12, l13, 911u);
                        l15 = std_core_finish_buffer(l12, l13);
                        std_string_builder_append(l1, l15);
                        l16 = vader_c_emit_empty_struct_offsets();
                        vader_array_push((vader_array_t*) l4, vader_ref_box(l16));
                    } else {
                        if (l6.tag == 496u) {
                            t0 = ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_split;
                            l17 = vader_c_emit_linkage_prefix(t0);
                            l18 = vader_host_std_core_byte_len(l17);
                            l19 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(90) + l18));
                            l20 = (size_t) (int64_t) INT64_C(0);
                            l20 = std_core_write_string_at(l19, l20, l17);
                            l20 = std_core_write_string_at(l19, l20, 1408u);
                            t1 = ((int64_t) (size_t) l5);
                            l21 = (uint64_t) (int64_t) t1;
                            l20 = std_core_write_unsigned(l19, l20, l21);
                            l20 = std_core_write_string_at(l19, l20, 910u);
                            l22 = std_core_finish_buffer(l19, l20);
                            std_string_builder_append(l1, l22);
                            l23 = vader_c_emit_empty_struct_offsets();
                            vader_array_push((vader_array_t*) l4, vader_ref_box(l23));
                        } else {
                            l24 = vader_c_emit_empty_struct_offsets();
                            vader_array_push((vader_array_t*) l4, vader_ref_box(l24));
                        }
                    }
                }
                t1 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t1;
                goto loop_10;
            } else {
            }
        }
    }
    std_string_builder_append(l1, 1u);
    l7 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(72));
    l5 = (size_t) (int64_t) INT64_C(0);
    l5 = std_core_write_string_at(l7, l5, 1412u);
    t1 = ((int64_t) (size_t) l3);
    l14 = (uint64_t) (int64_t) t1;
    l5 = std_core_write_unsigned(l7, l5, l14);
    l5 = std_core_write_string_at(l7, l5, 852u);
    l10 = std_core_finish_buffer(l7, l5);
    std_string_builder_append(l1, l10);
    l5 = (size_t) (int64_t) INT64_C(0);
    {
        loop_198: {
            if ((l5 < l3)) {
                vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
                if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                if ((size_t) l5 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                l6 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l5);
                if (l6.tag == 509u) {
                    l7 = l6.payload.obj;
                    vader_array_t* _a3_slotarr = ((vader_array_t*) l4);
                    if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                    if ((size_t) l5 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                    l8 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l5);
                    vader_c_emit_emit_struct_info_row(l0, l7, l8, l5, l1);
                } else {
                    if (l6.tag == 499u) {
                        l12 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(132));
                        l11 = (size_t) (int64_t) INT64_C(0);
                        l11 = std_core_write_string_at(l12, l11, 13u);
                        t1 = ((int64_t) (size_t) l5);
                        l14 = (uint64_t) (int64_t) t1;
                        l11 = std_core_write_unsigned(l12, l11, l14);
                        l11 = std_core_write_string_at(l12, l11, 855u);
                        t1 = ((int64_t) (size_t) l5);
                        l21 = (uint64_t) (int64_t) t1;
                        l11 = std_core_write_unsigned(l12, l11, l21);
                        l11 = std_core_write_string_at(l12, l11, 908u);
                        l10 = std_core_finish_buffer(l12, l11);
                        std_string_builder_append(l1, l10);
                    } else {
                        if (l6.tag == 496u) {
                            l16 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(138));
                            l13 = (size_t) (int64_t) INT64_C(0);
                            l13 = std_core_write_string_at(l16, l13, 13u);
                            t1 = ((int64_t) (size_t) l5);
                            l25 = (uint64_t) (int64_t) t1;
                            l13 = std_core_write_unsigned(l16, l13, l25);
                            l13 = std_core_write_string_at(l16, l13, 854u);
                            t1 = ((int64_t) (size_t) l5);
                            l26 = (uint64_t) (int64_t) t1;
                            l13 = std_core_write_unsigned(l16, l13, l26);
                            l13 = std_core_write_string_at(l16, l13, 908u);
                            l15 = std_core_finish_buffer(l16, l13);
                            std_string_builder_append(l1, l15);
                        } else {
                        }
                    }
                }
                t1 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t1;
                goto loop_198;
            } else {
            }
        }
    }
    std_string_builder_append(l1, 2429u);
    l4 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(59));
    l5 = (size_t) (int64_t) INT64_C(0);
    l5 = std_core_write_string_at(l4, l5, 1403u);
    t1 = ((int64_t) (size_t) l3);
    l14 = (uint64_t) (int64_t) t1;
    l5 = std_core_write_unsigned(l4, l5, l14);
    l5 = std_core_write_string_at(l4, l5, 495u);
    l10 = std_core_finish_buffer(l4, l5);
    std_string_builder_append(l1, l10);
    std_string_builder_append(l1, 1u);
    l4 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(55));
    l5 = (size_t) (int64_t) INT64_C(0);
    l5 = std_core_write_string_at(l4, l5, 1404u);
    t1 = ((int64_t) (size_t) l3);
    l14 = (uint64_t) (int64_t) t1;
    l5 = std_core_write_unsigned(l4, l5, l14);
    l5 = std_core_write_string_at(l4, l5, 852u);
    l10 = std_core_finish_buffer(l4, l5);
    std_string_builder_append(l1, l10);
    l5 = (size_t) (int64_t) INT64_C(0);
    {
        loop_398: {
            if ((l5 < l3)) {
                l4 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(52));
                l11 = (size_t) (int64_t) INT64_C(0);
                l11 = std_core_write_string_at(l4, l11, 13u);
                t1 = ((int64_t) (size_t) l5);
                l14 = (uint64_t) (int64_t) t1;
                l11 = std_core_write_unsigned(l4, l11, l14);
                l11 = std_core_write_string_at(l4, l11, 850u);
                vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
                if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                if ((size_t) l5 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                t2 = vader_array_ref_load_box(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l5);
                t3 = vader_bytecode_size_of_bc_type(t2);
                l27 = ((int64_t) (int32_t) t3);
                l11 = std_core_write_int(l4, l11, l27);
                l11 = std_core_write_string_at(l4, l11, 2208u);
                l10 = std_core_finish_buffer(l4, l11);
                std_string_builder_append(l1, l10);
                t1 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t1;
                goto loop_398;
            } else {
            }
        }
    }
    std_string_builder_append(l1, 2429u);
    std_string_builder_append(l1, 1u);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_c_emit_emit_typed_slot_write(void* l0, vader_string_t l1, vader_box_t l2, vader_box_t l3, vader_string_t l4, uint8_t l5) {
    void* l6 = NULL;
    vader_string_t l7 = 0;
    vader_string_t l9 = 0;
    uint8_t l8;
    vader_box_t* gc_roots[2] = { &l2, &l3 };
    void** gc_raw_roots[2] = { &l0, &l6 };
    vader_string_t* gc_atom_roots[4] = { &l1, &l4, &l7, &l9 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l6 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_ctx)->f_module)->f_types;
    l7 = vader_c_emit_name_of(l3);
    l8 = vader_c_emit_val_of(l3);
    l7 = vader_c_emit_coerce_expr(l6, l7, l8, l5);
    l9 = vader_c_emit_slot_index(l1, l2);
    l7 = concat_11(279u, l4, 354u, l1, 394u, l9, 851u, l4, 319u, l7, 494u);
    vader_c_emit_line(l0, l7);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_c_emit_emit_virtual_call(void* l0, void* l1) {
    void* l2 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    vader_string_t l3 = 0;
    vader_string_t l12 = 0;
    vader_box_t l4 = vader_box_null(), l5 = vader_box_null();
    uint8_t l6;
    int32_t l7;
    size_t l10, l11;
    int32_t t0;
    vader_box_t t1 = vader_box_null();
    int64_t t2;
    vader_string_t t3 = 0;
    vader_box_t* gc_roots[3] = { &l4, &l5, &t1 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l8, &l9 };
    vader_string_t* gc_atom_roots[3] = { &l3, &l12, &t3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_c_emit_FnState_t*) l0)->f_ctx;
    l3 = ((vader_struct_vader_bytecode_VirtualCall_t*) l1)->f_vtable_key;
    l4 = vader_c_emit_find_vtable_row(l2, l3);
    if (l4.tag == 0u) {
        l3 = ((vader_struct_vader_bytecode_VirtualCall_t*) l1)->f_vtable_key;
        l3 = concat_3(2365u, l3, 226u);
        vader_c_emit_line(l0, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    l2 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_ctx)->f_module)->f_types;
    l5 = vader_c_emit_pop(l0);
    l3 = vader_c_emit_name_of(l5);
    l6 = vader_c_emit_val_of(l5);
    l3 = vader_c_emit_coerce_expr(l2, l3, l6, (uint8_t) (int32_t) INT32_C(19));
    t0 = ((vader_struct_vader_bytecode_VirtualCall_t*) l1)->f_parameter_count;
    l7 = (t0 - INT32_C(1));
    l9 = vader_c_emit_pop_args_boxed(l0, l7);
    l2 = ((vader_struct_vader_c_emit_FnState_t*) l0)->f_ctx;
    l8 = l4.payload.obj;
    l2 = vader_c_emit_vtable_sig_for_row(l2, l8);
    vader_array_t* _a0_arr = vader_array_new(8u, 1u, 0u, 167u);
    vader_array_box_slots(_a0_arr->buf)[_a0_arr->offset + 0u] = vader_box_string(167u, l3);
    l8 = (void*) _a0_arr;
    l10 = ((vader_array_t*) l9)->length;
    l11 = (size_t) (int64_t) INT64_C(0);
    {
        loop_69: {
            if ((l11 < l10)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) l9);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l11 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                t1 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l11];
                l3 = t1.payload.s;
                vader_array_push((vader_array_t*) l8, vader_box_string(167u, l3));
                t2 = (l11 + INT64_C(1));
                l11 = (size_t) (int64_t) t2;
                goto loop_69;
            } else {
            }
        }
    }
    t3 = ((vader_struct_vader_bytecode_VirtualCall_t*) l1)->f_vtable_key;
    l3 = vader_c_emit_vtable_helper_name(t3);
    l12 = std_string_join(l8, 365u);
    l3 = concat_4(l3, 278u, l12, 318u);
    if (((vader_struct_vader_bytecode_BcSignature_t*) l2)->f_result == INT32_C(16)) {
        l12 = concat_2(l3, 494u);
        vader_c_emit_line(l0, l12);
        { vader_gc_top = gc_frame.prev; return; }
    }
    l6 = ((vader_struct_vader_bytecode_BcSignature_t*) l2)->f_result;
    vader_c_emit_push_into_tmp(l0, l3, l6);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_c_emit_emit_vtable_dispatchers(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    void* l17 = NULL;
    void* l19 = NULL;
    void* l25 = NULL;
    void* l27 = NULL;
    void* l28 = NULL;
    void* l30 = NULL;
    void* l33 = NULL;
    void* l37 = NULL;
    void* l46 = NULL;
    void* l54 = NULL;
    size_t l4, l5, l15, l16, l20, l21, l26, l34, l38, l45, l47, l53, l55;
    vader_string_t l8 = 0;
    vader_string_t l9 = 0;
    vader_string_t l10 = 0;
    vader_string_t l11 = 0;
    vader_string_t l12 = 0;
    vader_string_t l36 = 0;
    vader_string_t l40 = 0;
    vader_string_t l41 = 0;
    vader_string_t l42 = 0;
    vader_string_t l43 = 0;
    vader_string_t l44 = 0;
    vader_string_t l49 = 0;
    vader_string_t l52 = 0;
    vader_string_t l57 = 0;
    vader_string_t l58 = 0;
    vader_string_t l59 = 0;
    vader_string_t l60 = 0;
    vader_string_t l61 = 0;
    bool l18;
    int32_t l22, l23, l24, l31, l32;
    uint8_t l29, l39, l50, l51;
    int64_t l35, l48, l56;
    size_t t0;
    int64_t t1;
    vader_string_t t2 = 0;
    bool t3;
    int32_t t4;
    vader_box_t t5 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t5 };
    void** gc_raw_roots[18] = { &l0, &l1, &l2, &l3, &l6, &l7, &l13, &l14, &l17, &l19, &l25, &l27, &l28, &l30, &l33, &l37, &l46, &l54 };
    vader_string_t* gc_atom_roots[19] = { &l8, &l9, &l10, &l11, &l12, &l36, &l40, &l41, &l42, &l43, &l44, &l49, &l52, &l57, &l58, &l59, &l60, &l61, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 18u, gc_roots, gc_raw_roots, 0u, NULL, 19u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_vtables;
    t0 = ((vader_array_t*) l2)->length;
    if (t0 == INT64_C(0)) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l3 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_types;
    std_string_builder_append(l1, 3u);
    l4 = ((vader_array_t*) l2)->length;
    l5 = (size_t) (int64_t) INT64_C(0);
    {
        loop_21: {
            if ((l5 < l4)) {
                vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
                if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                if ((size_t) l5 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                l6 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
                t0 = ((vader_array_t*) ((vader_struct_vader_bytecode_VtableRow_t*) l6)->f_entries)->length;
                if (t0 == INT64_C(0)) {
                    t1 = (l5 + INT64_C(1));
                    l5 = (size_t) (int64_t) t1;
                    goto loop_21;
                }
                l7 = vader_c_emit_vtable_sig_for_row(l0, l6);
                t2 = ((vader_struct_vader_bytecode_VtableRow_t*) l6)->f_key;
                l8 = vader_c_emit_vtable_helper_name(t2);
                t3 = ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_split;
                l9 = vader_c_emit_linkage_prefix(t3);
                l10 = vader_c_emit_c_type_for_val_bare(((vader_struct_vader_bytecode_BcSignature_t*) l7)->f_result);
                l11 = vader_c_emit_dispatcher_formal(l7);
                l12 = concat_7(l9, l10, 6u, l8, 278u, l11, 334u);
                std_string_builder_append(l1, l12);
                std_string_builder_append(l1, 20u);
                vader_array_t* _a1_arr = vader_array_new(9u, 0u, 7u, 170u);
                l13 = (void*) _a1_arr;
                l14 = ((vader_struct_vader_bytecode_VtableRow_t*) l6)->f_entries;
                l15 = ((vader_array_t*) l14)->length;
                l16 = (size_t) (int64_t) INT64_C(0);
                {
                    loop_83: {
                        if ((l16 < l15)) {
                            vader_array_t* _a2_slotarr = ((vader_array_t*) l14);
                            if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                            if ((size_t) l16 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                            l17 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l16);
                            l18 = false;
                            l19 = l13;
                            vader_array_t* _a3_slotarr = ((vader_array_t*) l19);
                            if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                            l20 = ((vader_array_t*) l19)->length;
                            l21 = (size_t) (int64_t) INT64_C(0);
                            {
                                loop_101: {
                                    if ((l21 < l20)) {
                                        l22 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l21];
                                        l23 = ((vader_struct_vader_bytecode_VtableEntry_t*) l17)->f_receiver_type_index;
                                        if (l22 == l23) {
                                            l18 = true;
                                        } else {
                                        }
                                        t1 = (l21 + INT64_C(1));
                                        l21 = (size_t) (int64_t) t1;
                                        goto loop_101;
                                    } else {
                                    }
                                }
                            }
                            if (l18) {
                                t1 = (l16 + INT64_C(1));
                                l16 = (size_t) (int64_t) t1;
                                goto loop_83;
                            }
                            l24 = ((vader_struct_vader_bytecode_VtableEntry_t*) l17)->f_receiver_type_index;
                            vader_array_push_i32((vader_array_t*) l13, l24);
                            l25 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_functions;
                            t4 = ((vader_struct_vader_bytecode_VtableEntry_t*) l17)->f_fn_index;
                            t1 = ((int64_t) (int32_t) t4);
                            l26 = (size_t) (int64_t) t1;
                            vader_array_t* _a4_slotarr = ((vader_array_t*) l25);
                            if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                            if ((size_t) l26 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                            l27 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l26);
                            l28 = ((vader_struct_vader_bytecode_BcFunction_t*) l27)->f_signature;
                            vader_array_t* _a5_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) l28)->f_params);
                            if (_a5_slotarr->buf != NULL && _a5_slotarr->buf->header.forward != NULL) { _a5_slotarr->buf = vader_array_buf_forward(_a5_slotarr->buf); }
                            if ((size_t) INT32_C(0) >= _a5_slotarr->length) { vader_trap("array index out of bounds"); }
                            t5 = vader_array_read_u8(_a5_slotarr, _a5_slotarr->offset + (size_t) INT32_C(0), 173u);
                            l29 = ((uint8_t) t5.payload.i);
                            t2 = vader_c_emit_coerce_expr(l3, 1961u, (uint8_t) (int32_t) INT32_C(19), l29);
                            vader_array_t* _a6_arr = vader_array_new(8u, 1u, 0u, 167u);
                            vader_array_box_slots(_a6_arr->buf)[_a6_arr->offset + 0u] = vader_box_string(167u, t2);
                            l30 = (void*) _a6_arr;
                            t0 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) l28)->f_params)->length;
                            l31 = (((int32_t) (size_t) t0) - INT32_C(1));
                            l32 = INT32_C(0);
                            {
                                loop_177: {
                                    if ((l32 < l31)) {
                                        l33 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(21));
                                        l34 = (size_t) (int64_t) INT64_C(0);
                                        l34 = std_core_write_string_at(l33, l34, 1146u);
                                        l35 = ((int64_t) (int32_t) l32);
                                        l34 = std_core_write_int(l33, l34, l35);
                                        l36 = std_core_finish_buffer(l33, l34);
                                        l37 = ((vader_struct_vader_bytecode_BcSignature_t*) l28)->f_params;
                                        t1 = ((int64_t) (int32_t) (l32 + INT32_C(1)));
                                        l38 = (size_t) (int64_t) t1;
                                        vader_array_t* _a7_slotarr = ((vader_array_t*) l37);
                                        if (_a7_slotarr->buf != NULL && _a7_slotarr->buf->header.forward != NULL) { _a7_slotarr->buf = vader_array_buf_forward(_a7_slotarr->buf); }
                                        if ((size_t) l38 >= _a7_slotarr->length) { vader_trap("array index out of bounds"); }
                                        t5 = vader_array_read_u8(_a7_slotarr, _a7_slotarr->offset + (size_t) l38, 173u);
                                        l39 = ((uint8_t) t5.payload.i);
                                        l40 = vader_c_emit_coerce_expr(l3, l36, (uint8_t) (int32_t) INT32_C(19), l39);
                                        vader_array_push((vader_array_t*) l30, vader_box_string(167u, l40));
                                        l32 = (l32 + INT32_C(1));
                                        goto loop_177;
                                    } else {
                                    }
                                }
                            }
                            t2 = ((vader_struct_vader_bytecode_BcFunction_t*) l27)->f_name;
                            l41 = vader_c_emit_sanitise(t2);
                            l42 = std_string_join(l30, 365u);
                            l43 = concat_4(l41, 278u, l42, 318u);
                            if (((vader_struct_vader_bytecode_BcSignature_t*) l7)->f_result == INT32_C(16)) {
                                l44 = l43;
                                l45 = vader_host_std_core_byte_len(l44);
                                l46 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(46) + l45));
                                l47 = (size_t) (int64_t) INT64_C(0);
                                l47 = std_core_write_string_at(l46, l47, 8u);
                                t4 = ((vader_struct_vader_bytecode_VtableEntry_t*) l17)->f_receiver_type_index;
                                l48 = ((int64_t) (int32_t) t4);
                                l47 = std_core_write_int(l46, l47, l48);
                                l47 = std_core_write_string_at(l46, l47, 2249u);
                                l47 = std_core_write_string_at(l46, l47, l44);
                                l47 = std_core_write_string_at(l46, l47, 496u);
                                l49 = std_core_finish_buffer(l46, l47);
                                std_string_builder_append(l1, l49);
                            } else {
                                l50 = ((vader_struct_vader_bytecode_BcSignature_t*) l28)->f_result;
                                l51 = ((vader_struct_vader_bytecode_BcSignature_t*) l7)->f_result;
                                l52 = vader_c_emit_dispatcher_result(l3, l43, l50, l51);
                                l53 = vader_host_std_core_byte_len(l52);
                                l54 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(45) + l53));
                                l55 = (size_t) (int64_t) INT64_C(0);
                                l55 = std_core_write_string_at(l54, l55, 8u);
                                t4 = ((vader_struct_vader_bytecode_VtableEntry_t*) l17)->f_receiver_type_index;
                                l56 = ((int64_t) (int32_t) t4);
                                l55 = std_core_write_int(l54, l55, l56);
                                l55 = std_core_write_string_at(l54, l55, 2250u);
                                l55 = std_core_write_string_at(l54, l55, l52);
                                l55 = std_core_write_string_at(l54, l55, 495u);
                                l57 = std_core_finish_buffer(l54, l55);
                                std_string_builder_append(l1, l57);
                            }
                            t1 = (l16 + INT64_C(1));
                            l16 = (size_t) (int64_t) t1;
                            goto loop_83;
                        } else {
                        }
                    }
                }
                l58 = ((vader_struct_vader_bytecode_VtableRow_t*) l6)->f_key;
                l59 = concat_3(9u, l58, 227u);
                std_string_builder_append(l1, l59);
                std_string_builder_append(l1, 41u);
                if (((vader_struct_vader_bytecode_BcSignature_t*) l7)->f_result != INT32_C(16)) {
                    l60 = ((vader_struct_vader_bytecode_VtableRow_t*) l6)->f_key;
                    l61 = concat_3(32u, l60, 227u);
                    std_string_builder_append(l1, l61);
                } else {
                }
                std_string_builder_append(l1, 2426u);
                t1 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t1;
                goto loop_21;
            } else {
            }
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_c_emit_emit_vtable_forward_decls(void* l0, void* l1) {
    void* l2 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    size_t l3, l4;
    vader_string_t l7 = 0;
    vader_string_t l8 = 0;
    vader_string_t l9 = 0;
    vader_string_t l10 = 0;
    vader_string_t l11 = 0;
    size_t t0;
    int64_t t1;
    bool t2;
    vader_string_t t3 = 0;
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l5, &l6 };
    vader_string_t* gc_atom_roots[6] = { &l7, &l8, &l9, &l10, &l11, &t3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL, 6u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_vtables;
    t0 = ((vader_array_t*) l2)->length;
    if (t0 == INT64_C(0)) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    std_string_builder_append(l1, 4u);
    l3 = ((vader_array_t*) l2)->length;
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_18: {
            if ((l4 < l3)) {
                vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
                if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                if ((size_t) l4 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                l5 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
                t0 = ((vader_array_t*) ((vader_struct_vader_bytecode_VtableRow_t*) l5)->f_entries)->length;
                if (t0 == INT64_C(0)) {
                    t1 = (l4 + INT64_C(1));
                    l4 = (size_t) (int64_t) t1;
                    goto loop_18;
                }
                l6 = vader_c_emit_vtable_sig_for_row(l0, l5);
                t2 = ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_split;
                l7 = vader_c_emit_linkage_prefix(t2);
                l8 = vader_c_emit_c_type_for_val_bare(((vader_struct_vader_bytecode_BcSignature_t*) l6)->f_result);
                t3 = ((vader_struct_vader_bytecode_VtableRow_t*) l5)->f_key;
                l9 = vader_c_emit_vtable_helper_name(t3);
                l10 = vader_c_emit_dispatcher_formal(l6);
                l11 = concat_7(l7, l8, 6u, l9, 278u, l10, 350u);
                std_string_builder_append(l1, l11);
                t1 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t1;
                goto loop_18;
            } else {
            }
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_c_emit_empty_struct_offsets(void) {
    void* l0 = NULL;
    void* l1 = NULL;
    void* l2 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 167u);
    l0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(8u, 0u, 0u, 167u);
    l1 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(8u, 0u, 0u, 167u);
    l2 = (void*) _a2_arr;
    vader_struct_vader_c_emit_StructOffsets_t* _a3_obj = (vader_struct_vader_c_emit_StructOffsets_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_StructOffsets_t));
    vader_obj_header_init(_a3_obj, 675u);
    _a3_obj->f_ptr_offsets = l0;
    _a3_obj->f_str_offsets = l1;
    _a3_obj->f_ref_offsets = l2;
    t0 = (void*) _a3_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static bool vader_c_emit_entry_needs_materialise(vader_box_t l0, int32_t l1) {
    void* t0;
    int32_t t1;
    if (l0.tag == 670u) {
        return true;
    }
    if (l0.tag == 672u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_c_emit_StackLocalRef_t*) t0)->f_slot;
        return t1 == l1;
    }
    if (l0.tag == 674u) {
        return false;
    }
    if (l0.tag == 671u) {
        return false;
    }
    vader_unreachable("unreachable return in vader_c_emit$entry_needs_materialise");
}

static vader_string_t vader_c_emit_erased_sibling_field_read(void* l0, int32_t l1, int32_t l2, uint8_t l3, vader_string_t l4) {
    void* l5 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    size_t l6;
    vader_box_t l7 = vader_box_null();
    vader_string_t l10 = 0;
    vader_string_t l13 = 0;
    int32_t l11;
    uint8_t l12;
    int64_t t0;
    vader_box_t t1 = vader_box_null();
    vader_string_t t2 = 0;
    vader_box_t* gc_roots[2] = { &l7, &t1 };
    void** gc_raw_roots[4] = { &l0, &l5, &l8, &l9 };
    vader_string_t* gc_atom_roots[4] = { &l4, &l10, &l13, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l5 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_ctx)->f_module)->f_types;
    t0 = ((int64_t) (int32_t) l1);
    l6 = (size_t) (int64_t) t0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    if ((size_t) l6 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
    l7 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l6);
    if (l7.tag == 509u) {
        l8 = l7.payload.obj;
        l9 = ((vader_struct_vader_c_emit_EmitCtx_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_ctx)->f_struct_c_names;
        t0 = ((int64_t) (int32_t) l1);
        l6 = (size_t) (int64_t) t0;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l9);
        if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
        if ((size_t) l6 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
        t1 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l6];
        l10 = t1.payload.s;
        l8 = ((vader_struct_vader_bytecode_BcStruct_t*) l8)->f_fields;
        t0 = ((int64_t) (int32_t) l2);
        l6 = (size_t) (int64_t) t0;
        vader_array_t* _a2_slotarr = ((vader_array_t*) l8);
        if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
        if ((size_t) l6 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
        l8 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l6);
        l11 = ((vader_struct_vader_bytecode_BcField_t*) l8)->f_type_index;
        l12 = vader_c_emit_val_type_of_field(l5, l11);
        t2 = ((vader_struct_vader_bytecode_BcField_t*) l8)->f_name;
        l13 = vader_c_emit_sanitise(t2);
        l10 = concat_6(279u, l10, 354u, l4, 347u, l13);
        t2 = vader_c_emit_coerce_expr(l5, l10, l12, l3);
        { vader_string_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return 445u; }
    vader_gc_top = gc_frame.prev;
}

static vader_string_t vader_c_emit_erased_sig_params(int32_t l0) {
    void* l1 = NULL;
    void* l3 = NULL;
    int32_t l2;
    size_t l4;
    int64_t l5;
    vader_string_t l6 = 0;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    void** gc_raw_roots[3] = { &l1, &l3, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l6, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 167u);
    t0 = (void*) _a0_arr;
    vader_struct_std_string_builder_StringBuilder_t* _a1_obj = (vader_struct_std_string_builder_StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string_builder_StringBuilder_t));
    vader_obj_header_init(_a1_obj, 389u);
    _a1_obj->f_parts = t0;
    l1 = (void*) _a1_obj;
    std_string_builder_append(l1, 2384u);
    l2 = INT32_C(0);
    {
        loop_8: {
            if ((l2 < l0)) {
                l3 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(35));
                l4 = (size_t) (int64_t) INT64_C(0);
                l4 = std_core_write_string_at(l3, l4, 380u);
                l5 = ((int64_t) (int32_t) l2);
                l4 = std_core_write_int(l3, l4, l5);
                l6 = std_core_finish_buffer(l3, l4);
                std_string_builder_append(l1, l6);
                l2 = (l2 + INT32_C(1));
                goto loop_8;
            } else {
            }
        }
    }
    t1 = std_string_builder_StringBuilder_Display_to_string(l1);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_string_t vader_c_emit_extern_c_type(uint8_t l0) {
    vader_string_t t0;
    if (l0 == INT32_C(14)) {
        return 1400u;
    }
    t0 = vader_c_emit_c_type_for_val_bare(l0);
    return t0;
}

static vader_string_t vader_c_emit_extern_decl(void* l0, void* l1) {
    void* l2 = NULL;
    size_t l3, l4;
    int32_t l5, l7, l8, l13;
    vader_string_t l6 = 0;
    vader_string_t l9 = 0;
    vader_string_t l10 = 0;
    vader_string_t l11 = 0;
    vader_string_t l12 = 0;
    vader_string_t l14 = 0;
    bool t0;
    vader_string_t t1 = 0;
    vader_box_t t2 = vader_box_null();
    int64_t t3;
    size_t t4;
    vader_box_t* gc_roots[1] = { &t2 };
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_string_t* gc_atom_roots[7] = { &l6, &l9, &l10, &l11, &l12, &l14, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 7u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 167u);
    l2 = (void*) _a0_arr;
    l3 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcImport_t*) l0)->f_signature)->f_params)->length;
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_9: {
            if ((l4 < l3)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcImport_t*) l0)->f_signature)->f_param_types);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l4 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                l5 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
                t0 = vader_c_emit_is_abi_array(l1, l5);
                if (t0) {
                    t0 = vader_c_emit_param_is_mutable(((vader_struct_vader_bytecode_BcImport_t*) l0)->f_signature, l4);
                    if (t0) {
                        l6 = 2383u;
                    } else {
                        l6 = 1413u;
                    }
                    vader_array_push((vader_array_t*) l2, vader_box_string(167u, l6));
                } else {
                    vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcImport_t*) l0)->f_signature)->f_param_types);
                    if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                    if ((size_t) l4 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                    l7 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l4];
                    t1 = vader_c_emit_mirrored_c_struct(l1, l7);
                    if (t1 != 0u) {
                        vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcImport_t*) l0)->f_signature)->f_param_types);
                        if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                        if ((size_t) l4 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                        l8 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l4];
                        l9 = vader_c_emit_mirrored_c_struct(l1, l8);
                        t0 = vader_c_emit_param_is_mutable(((vader_struct_vader_bytecode_BcImport_t*) l0)->f_signature, l4);
                        if (t0) {
                            l10 = concat_2(l9, 352u);
                        } else {
                            l10 = concat_3(1398u, l9, 352u);
                        }
                        vader_array_push((vader_array_t*) l2, vader_box_string(167u, l10));
                    } else {
                        t0 = vader_c_emit_is_param_by_address(((vader_struct_vader_bytecode_BcImport_t*) l0)->f_signature, l4);
                        if (t0) {
                            vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcImport_t*) l0)->f_signature)->f_params);
                            if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                            if ((size_t) l4 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                            t2 = vader_array_read_u8(_a4_slotarr, _a4_slotarr->offset + (size_t) l4, 173u);
                            l11 = vader_c_emit_c_type_for_val_bare(((uint8_t) t2.payload.i));
                            t0 = vader_c_emit_param_is_mutable(((vader_struct_vader_bytecode_BcImport_t*) l0)->f_signature, l4);
                            if (t0) {
                                l12 = concat_2(l11, 352u);
                            } else {
                                l12 = concat_3(1398u, l11, 352u);
                            }
                            vader_array_push((vader_array_t*) l2, vader_box_string(167u, l12));
                        } else {
                            vader_array_t* _a5_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcImport_t*) l0)->f_signature)->f_param_types);
                            if (_a5_slotarr->buf != NULL && _a5_slotarr->buf->header.forward != NULL) { _a5_slotarr->buf = vader_array_buf_forward(_a5_slotarr->buf); }
                            if ((size_t) l4 >= _a5_slotarr->length) { vader_trap("array index out of bounds"); }
                            l13 = ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l4];
                            t0 = vader_c_emit_is_abi_nullable_pointer(l1, l13);
                            if (t0) {
                                vader_array_push((vader_array_t*) l2, vader_box_string(167u, 2383u));
                            } else {
                                vader_array_t* _a6_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcImport_t*) l0)->f_signature)->f_params);
                                if (_a6_slotarr->buf != NULL && _a6_slotarr->buf->header.forward != NULL) { _a6_slotarr->buf = vader_array_buf_forward(_a6_slotarr->buf); }
                                if ((size_t) l4 >= _a6_slotarr->length) { vader_trap("array index out of bounds"); }
                                t2 = vader_array_read_u8(_a6_slotarr, _a6_slotarr->offset + (size_t) l4, 173u);
                                l14 = vader_c_emit_extern_c_type(((uint8_t) t2.payload.i));
                                vader_array_push((vader_array_t*) l2, vader_box_string(167u, l14));
                            }
                        }
                    }
                }
                t3 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t3;
                goto loop_9;
            } else {
            }
        }
    }
    t4 = ((vader_array_t*) l2)->length;
    if (t4 == INT64_C(0)) {
        l6 = 2382u;
    } else {
        l6 = std_string_join(l2, 365u);
    }
    l5 = ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcImport_t*) l0)->f_signature)->f_result_type;
    t0 = vader_c_emit_is_abi_nullable_pointer(l1, l5);
    if (t0) {
        l9 = 2383u;
    } else {
        l9 = vader_c_emit_extern_c_type(((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcImport_t*) l0)->f_signature)->f_result);
    }
    l10 = ((vader_struct_vader_bytecode_BcImport_t*) l0)->f_extern_name;
    t1 = concat_7(1530u, l9, 6u, l10, 278u, l6, 349u);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_c_emit_find_erased_siblings(void* l0, int32_t l1) {
    void* l2 = NULL;
    void* l5 = NULL;
    void* l9 = NULL;
    void* l18 = NULL;
    void* l19 = NULL;
    size_t l3, l7, l8, l17, l20, l25;
    vader_box_t l4 = vader_box_null();
    bool l6, l10, l11, l14, l15, l16, l23;
    int32_t l12, l13, l21, l22, l24;
    int64_t t0;
    bool t1;
    vader_string_t t2 = 0;
    vader_box_t t3 = vader_box_null();
    size_t t4;
    int32_t t5;
    vader_box_t* gc_roots[2] = { &l4, &t3 };
    void** gc_raw_roots[6] = { &l0, &l2, &l5, &l9, &l18, &l19 };
    vader_string_t* gc_atom_roots[1] = { &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(9u, 0u, 7u, 170u);
    l2 = (void*) _a0_arr;
    t0 = ((int64_t) (int32_t) l1);
    l3 = (size_t) (int64_t) t0;
    vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
    if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
    if ((size_t) l3 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
    l4 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l3);
    if (l4.tag == 509u) {
        l5 = l4.payload.obj;
        t1 = vader_c_emit_struct_all_ref(l0, l5);
        if (t1) {
            { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l3 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcStruct_t*) l5)->f_fields)->length;
        t2 = ((vader_struct_vader_bytecode_BcStruct_t*) l5)->f_name;
        l6 = std_string_byte_contains(t2, 882u);
        l7 = ((vader_array_t*) l0)->length;
        l8 = (size_t) (int64_t) INT64_C(0);
        {
            loop_35: {
                if ((l8 < l7)) {
                    if (((int32_t) (size_t) l8) == l1) {
                        t0 = (l8 + INT64_C(1));
                        l8 = (size_t) (int64_t) t0;
                        goto loop_35;
                    }
                    vader_array_t* _a2_slotarr = ((vader_array_t*) l0);
                    if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                    if ((size_t) l8 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                    t3 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l8);
                    if (t3.tag == 509u) {
                        vader_array_t* _a3_slotarr = ((vader_array_t*) l0);
                        if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                        if ((size_t) l8 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                        t3 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l8);
                        l9 = t3.payload.obj;
                        t4 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcStruct_t*) l9)->f_fields)->length;
                        if (t4 != l3) {
                            t0 = (l8 + INT64_C(1));
                            l8 = (size_t) (int64_t) t0;
                            goto loop_35;
                        }
                        t5 = ((vader_struct_vader_bytecode_BcStruct_t*) l5)->f_symbol_id;
                        if ((t5 >= INT32_C(0))) {
                            l12 = ((vader_struct_vader_bytecode_BcStruct_t*) l9)->f_symbol_id;
                            l13 = ((vader_struct_vader_bytecode_BcStruct_t*) l5)->f_symbol_id;
                            l11 = l12 == l13;
                        } else {
                            l11 = false;
                        }
                        if (l11) {
                            l10 = true;
                        } else {
                            if (l6) {
                                t2 = ((vader_struct_vader_bytecode_BcStruct_t*) l9)->f_name;
                                l14 = std_string_byte_contains(t2, 882u);
                            } else {
                                l14 = false;
                            }
                            l10 = l14;
                        }
                        if (l10) {
                            l15 = true;
                            l16 = false;
                            l17 = (size_t) (int64_t) INT64_C(0);
                            {
                                loop_119: {
                                    if ((l17 < l3)) {
                                        vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcStruct_t*) l5)->f_fields);
                                        if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                                        if ((size_t) l17 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                                        l18 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l17);
                                        vader_array_t* _a5_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcStruct_t*) l9)->f_fields);
                                        if (_a5_slotarr->buf != NULL && _a5_slotarr->buf->header.forward != NULL) { _a5_slotarr->buf = vader_array_buf_forward(_a5_slotarr->buf); }
                                        if ((size_t) l17 >= _a5_slotarr->length) { vader_trap("array index out of bounds"); }
                                        l19 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l17);
                                        t5 = ((vader_struct_vader_bytecode_BcField_t*) l19)->f_type_index;
                                        t0 = ((int64_t) (int32_t) t5);
                                        l20 = (size_t) (int64_t) t0;
                                        vader_array_t* _a6_slotarr = ((vader_array_t*) l0);
                                        if (_a6_slotarr->buf != NULL && _a6_slotarr->buf->header.forward != NULL) { _a6_slotarr->buf = vader_array_buf_forward(_a6_slotarr->buf); }
                                        if ((size_t) l20 >= _a6_slotarr->length) { vader_trap("array index out of bounds"); }
                                        t3 = vader_array_ref_load_box(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l20);
                                        if (t3.tag == 506u) {
                                            l16 = true;
                                        } else {
                                            l21 = ((vader_struct_vader_bytecode_BcField_t*) l19)->f_type_index;
                                            l22 = ((vader_struct_vader_bytecode_BcField_t*) l18)->f_type_index;
                                            if (l21 != l22) {
                                                l15 = false;
                                            } else {
                                            }
                                        }
                                        t0 = (l17 + INT64_C(1));
                                        l17 = (size_t) (int64_t) t0;
                                        goto loop_119;
                                    } else {
                                    }
                                }
                            }
                            if (l15) {
                                l23 = l16;
                            } else {
                                l23 = false;
                            }
                            if (l23) {
                                l24 = ((int32_t) (size_t) l8);
                                vader_array_push_i32((vader_array_t*) l2, l24);
                            } else {
                            }
                        } else {
                        }
                        l25 = (size_t) (int64_t) INT64_C(1);
                        t0 = (l8 + l25);
                        l8 = (size_t) (int64_t) t0;
                        goto loop_35;
                    }
                    l25 = (size_t) (int64_t) INT64_C(1);
                    t0 = (l8 + l25);
                    l8 = (size_t) (int64_t) t0;
                    goto loop_35;
                } else {
                }
            }
        }
        { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static int32_t vader_c_emit_find_main(void* l0, vader_string_t l1) {
    size_t l2, l3, l6, l7, l8;
    void* l4;
    bool l5;
    vader_string_t t0;
    size_t t1;
    int64_t t2;
    bool t3;
    if (l1 != 0u) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_functions);
        if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
        l2 = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_functions)->length;
        l3 = (size_t) (int64_t) INT64_C(0);
        {
            loop_10: {
                if ((l3 < l2)) {
                    if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
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
                    goto loop_10;
                } else {
                }
            }
        }
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_functions);
        if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
        l2 = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_functions)->length;
        l3 = (size_t) (int64_t) INT64_C(0);
        {
            loop_54: {
                if ((l3 < l2)) {
                    if ((size_t) l3 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                    l4 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l3);
                    t3 = ((vader_struct_vader_bytecode_BcFunction_t*) l4)->f_is_main;
                    if (t3) {
                        l6 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l4)->f_body)->length;
                        l7 = (size_t) (int64_t) INT64_C(0);
                        l5 = (l6 > l7);
                    } else {
                        l5 = false;
                    }
                    if (l5) {
                        return ((int32_t) (size_t) l3);
                    }
                    l8 = (size_t) (int64_t) INT64_C(1);
                    t2 = (l3 + l8);
                    l3 = (size_t) (int64_t) t2;
                    goto loop_54;
                } else {
                }
            }
        }
        return -(INT32_C(1));
    }
    vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_functions);
    if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
    l2 = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_functions)->length;
    l3 = (size_t) (int64_t) INT64_C(0);
    {
        loop_106: {
            if ((l3 < l2)) {
                if ((size_t) l3 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                l4 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l3);
                t3 = ((vader_struct_vader_bytecode_BcFunction_t*) l4)->f_is_main;
                if (t3) {
                    l6 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l4)->f_body)->length;
                    l7 = (size_t) (int64_t) INT64_C(0);
                    l5 = (l6 > l7);
                } else {
                    l5 = false;
                }
                if (l5) {
                    return ((int32_t) (size_t) l3);
                }
                l8 = (size_t) (int64_t) INT64_C(1);
                t2 = (l3 + l8);
                l3 = (size_t) (int64_t) t2;
                goto loop_106;
            } else {
            }
        }
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
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    l3 = ((vader_array_t*) l2)->length;
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_8: {
            if ((l4 < l3)) {
                if ((size_t) l4 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                l5 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
                t0 = ((vader_struct_vader_bytecode_VtableRow_t*) l5)->f_key;
                if (t0 == l1) {
                    return vader_ref_box(l5);
                }
                t1 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t1;
                goto loop_8;
            } else {
            }
        }
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
    l1 = std_core_format_f64(l0);
    if (l1 == 1718u) {
        { vader_gc_top = gc_frame.prev; return 887u; }
    }
    if (l1 == 406u) {
        { vader_gc_top = gc_frame.prev; return 302u; }
    }
    if (l1 == 1887u) {
        { vader_gc_top = gc_frame.prev; return 888u; }
    }
    t0 = std_string_byte_contains(l1, 407u);
    if (t0) {
        l2 = true;
    } else {
        l2 = std_string_byte_contains(l1, 1460u);
    }
    if (l2) {
        { vader_string_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = concat_2(l1, 414u);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_string_t vader_c_emit_float_tag_check_expr(void* l0, vader_string_t l1) {
    void* l2 = NULL;
    void* l7 = NULL;
    size_t l3, l4, l6, l8;
    vader_string_t l5 = 0;
    vader_string_t l10 = 0;
    uint64_t l9;
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    bool t2;
    int64_t t3;
    size_t t4;
    vader_string_t t5 = 0;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[4] = { &l0, &l2, &l7, &t1 };
    vader_string_t* gc_atom_roots[4] = { &l1, &l5, &l10, &t5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 167u);
    l2 = (void*) _a0_arr;
    l3 = ((vader_array_t*) l0)->length;
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_8: {
            if ((l4 < l3)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l4 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
                if (t0.tag == 505u) {
                    vader_array_t* _a2_slotarr = ((vader_array_t*) l0);
                    if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                    if ((size_t) l4 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                    t0 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
                    t1 = t0.payload.obj;
                    t2 = vader_bytecode_is_float_val(((vader_struct_vader_bytecode_BcPrimitive_t*) t1)->f_val);
                    if (t2) {
                        l5 = l1;
                        l6 = vader_host_std_core_byte_len(l5);
                        l7 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(25) + l6));
                        l8 = (size_t) (int64_t) INT64_C(0);
                        l8 = std_core_write_string_at(l7, l8, l5);
                        l8 = std_core_write_string_at(l7, l8, 90u);
                        t3 = ((int64_t) (size_t) l4);
                        l9 = (uint64_t) (int64_t) t3;
                        l8 = std_core_write_unsigned(l7, l8, l9);
                        l8 = std_core_write_string_at(l7, l8, 2198u);
                        l10 = std_core_finish_buffer(l7, l8);
                        vader_array_push((vader_array_t*) l2, vader_box_string(167u, l10));
                    } else {
                    }
                } else {
                }
                t3 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t3;
                goto loop_8;
            } else {
            }
        }
    }
    t4 = ((vader_array_t*) l2)->length;
    if (t4 == INT64_C(0)) {
        { vader_gc_top = gc_frame.prev; return 445u; }
    }
    l5 = std_string_join(l2, 200u);
    t5 = concat_3(278u, l5, 318u);
    { vader_string_t __vret = t5; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static bool vader_c_emit_fn_builds_stack_object(void* l0) {
    size_t l1, l2, l4;
    vader_box_t l3;
    void* t0;
    bool t1;
    int64_t t2;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_body);
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    l1 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_body)->length;
    l2 = (size_t) (int64_t) INT64_C(0);
    {
        loop_6: {
            if ((l2 < l1)) {
                if ((size_t) l2 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                l3 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
                if (l3.tag == 638u) {
                    t0 = l3.payload.obj;
                    t1 = ((vader_struct_vader_bytecode_StructNew_t*) t0)->f_stack;
                    if (t1) {
                        return true;
                    }
                    l4 = (size_t) (int64_t) INT64_C(1);
                    t2 = (l2 + l4);
                    l2 = (size_t) (int64_t) t2;
                    goto loop_6;
                }
                l4 = (size_t) (int64_t) INT64_C(1);
                t2 = (l2 + l4);
                l2 = (size_t) (int64_t) t2;
                goto loop_6;
            } else {
            }
        }
    }
    return false;
}

static bool vader_c_emit_fn_calls_may_alloc(void* l0, void* l1) {
    size_t l2, l3, l6;
    vader_box_t l4;
    int32_t l5;
    void* t0;
    bool t1;
    int64_t t2;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_body);
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    l2 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_body)->length;
    l3 = (size_t) (int64_t) INT64_C(0);
    {
        loop_6: {
            if ((l3 < l2)) {
                if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                l4 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
                if (l4.tag == 532u) {
                    t0 = l4.payload.obj;
                    l5 = ((vader_struct_vader_bytecode_Call_t*) t0)->f_function_index;
                    t1 = std_core____Contains_contains__i32(l1, l5);
                    if (t1) {
                        return true;
                    }
                    l6 = (size_t) (int64_t) INT64_C(1);
                    t2 = (l3 + l6);
                    l3 = (size_t) (int64_t) t2;
                    goto loop_6;
                }
                l6 = (size_t) (int64_t) INT64_C(1);
                t2 = (l3 + l6);
                l3 = (size_t) (int64_t) t2;
                goto loop_6;
            } else {
            }
        }
    }
    return false;
}

static bool vader_c_emit_fn_has_direct_alloc(void* l0) {
    size_t l1, l2;
    vader_box_t t0;
    bool t1;
    int64_t t2;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_body);
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    l1 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_body)->length;
    l2 = (size_t) (int64_t) INT64_C(0);
    {
        loop_6: {
            if ((l2 < l1)) {
                if ((size_t) l2 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
                t1 = vader_c_emit_op_allocates(t0);
                if (t1) {
                    return true;
                }
                t2 = (l2 + INT64_C(1));
                l2 = (size_t) (int64_t) t2;
                goto loop_6;
            } else {
            }
        }
    }
    return false;
}

static vader_string_t vader_c_emit_fn_linkage_prefix(void* l0, int32_t l1) {
    size_t l2, l3;
    bool l4;
    void* l5;
    bool t0;
    int64_t t1;
    vader_box_t t2;
    t0 = ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_split;
    if (!(t0)) {
        return 2030u;
    }
    t1 = ((int64_t) (int32_t) l1);
    l2 = (size_t) (int64_t) t1;
    l3 = ((vader_array_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_internal_fns)->length;
    if ((l2 < l3)) {
        l5 = ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_internal_fns;
        t1 = ((int64_t) (int32_t) l1);
        l2 = (size_t) (int64_t) t1;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
        if ((size_t) l2 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
        t2 = vader_box_bool(165u, ((uint8_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l2]);
        l4 = t2.payload.b;
    } else {
        l4 = false;
    }
    if (l4) {
        return 2030u;
    }
    return 0u;
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
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
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
        l5 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(84));
        l3 = (size_t) (int64_t) INT64_C(0);
        l3 = std_core_write_string_at(l5, l3, 1318u);
        l6 = ((int64_t) (int32_t) l1);
        l3 = std_core_write_int(l5, l3, l6);
        l3 = std_core_write_string_at(l5, l3, 381u);
        t1 = std_core_finish_buffer(l5, l3);
        vader_host_std_abort_panic(t1);
    } else {
    }
    t0 = ((int64_t) (int32_t) l1);
    l3 = (size_t) (int64_t) t0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
    t2 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
    t1 = ((vader_struct_vader_bytecode_BcFunction_t*) t2)->f_name;
    t3 = vader_c_emit_sanitise(t1);
    { vader_string_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_string_t vader_c_emit_fresh_tmp(void* l0, uint8_t l1) {
    size_t l2, l4;
    void* l3 = NULL;
    uint64_t l5;
    int64_t t0;
    vader_string_t t1 = 0;
    void** gc_raw_roots[2] = { &l0, &l3 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = ((vader_array_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_tmp_types)->length;
    vader_array_push_u8((vader_array_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_tmp_types, (int32_t) (uint8_t) l1);
    l3 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(21));
    l4 = (size_t) (int64_t) INT64_C(0);
    l4 = std_core_write_string_at(l3, l4, 2133u);
    t0 = ((int64_t) (size_t) l2);
    l5 = (uint64_t) (int64_t) t0;
    l4 = std_core_write_unsigned(l3, l4, l5);
    t1 = std_core_finish_buffer(l3, l4);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_string_t vader_c_emit_fuse_temp_local_copies(vader_string_t l0, size_t l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l5 = NULL;
    void* l7 = NULL;
    void* l12 = NULL;
    size_t l4, l6, l10, l11, l14, l15, l21;
    bool l8, l9, l13;
    vader_string_t l16 = 0;
    vader_string_t l17 = 0;
    vader_string_t l18 = 0;
    vader_string_t l19 = 0;
    vader_string_t l20 = 0;
    vader_box_t t0 = vader_box_null();
    vader_string_t t1 = 0;
    bool t2;
    size_t t3;
    int32_t t4;
    int64_t t5;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[5] = { &l2, &l3, &l5, &l7, &l12 };
    vader_string_t* gc_atom_roots[7] = { &l0, &l16, &l17, &l18, &l19, &l20, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 7u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = vader_c_emit_count_temp_occurrences(l0, l1);
    l3 = std_string_split(l0, 1u);
    l4 = ((vader_array_t*) l3)->length;
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 167u);
    l5 = (void*) _a0_arr;
    l6 = (size_t) (int64_t) INT64_C(0);
    {
        loop_15: {
            if ((l6 < l4)) {
                if (((l6 + INT64_C(1)) < l4)) {
                    vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
                    if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                    if ((size_t) l6 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                    t0 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l6];
                    t1 = t0.payload.s;
                    l7 = vader_c_emit_parse_def_line(t1);
                    t2 = ((vader_struct_vader_c_emit_DefLine_t*) l7)->f_ok;
                    if (t2) {
                        t3 = ((vader_struct_vader_c_emit_DefLine_t*) l7)->f_id;
                        l8 = (t3 < l1);
                    } else {
                        l8 = false;
                    }
                    if (l8) {
                        l10 = ((vader_struct_vader_c_emit_DefLine_t*) l7)->f_id;
                        vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
                        if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                        if ((size_t) l10 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                        t4 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l10];
                        l9 = t4 == INT32_C(2);
                    } else {
                        l9 = false;
                    }
                    if (l9) {
                        t5 = (l6 + INT64_C(1));
                        l11 = (size_t) (int64_t) t5;
                        vader_array_t* _a3_slotarr = ((vader_array_t*) l3);
                        if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                        if ((size_t) l11 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                        t0 = vader_array_box_slots(_a3_slotarr->buf)[_a3_slotarr->offset + (size_t) l11];
                        t1 = t0.payload.s;
                        l12 = vader_c_emit_parse_copy_line(t1);
                        t2 = ((vader_struct_vader_c_emit_CopyLine_t*) l12)->f_ok;
                        if (t2) {
                            l14 = ((vader_struct_vader_c_emit_CopyLine_t*) l12)->f_id;
                            l15 = ((vader_struct_vader_c_emit_DefLine_t*) l7)->f_id;
                            l13 = l14 == l15;
                        } else {
                            l13 = false;
                        }
                        if (l13) {
                            l16 = ((vader_struct_vader_c_emit_DefLine_t*) l7)->f_indent;
                            l17 = ((vader_struct_vader_c_emit_CopyLine_t*) l12)->f_local;
                            l18 = ((vader_struct_vader_c_emit_DefLine_t*) l7)->f_expr;
                            l19 = concat_5(l16, l17, 61u, l18, 494u);
                            vader_array_push((vader_array_t*) l5, vader_box_string(167u, l19));
                            t5 = (l6 + INT64_C(2));
                            l6 = (size_t) (int64_t) t5;
                            goto loop_15;
                        }
                        vader_array_t* _a4_slotarr = ((vader_array_t*) l3);
                        if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                        if ((size_t) l6 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                        t0 = vader_array_box_slots(_a4_slotarr->buf)[_a4_slotarr->offset + (size_t) l6];
                        l20 = t0.payload.s;
                        vader_array_push((vader_array_t*) l5, vader_box_string(167u, l20));
                        l21 = (size_t) (int64_t) INT64_C(1);
                        t5 = (l6 + l21);
                        l6 = (size_t) (int64_t) t5;
                        goto loop_15;
                    }
                    vader_array_t* _a5_slotarr = ((vader_array_t*) l3);
                    if (_a5_slotarr->buf != NULL && _a5_slotarr->buf->header.forward != NULL) { _a5_slotarr->buf = vader_array_buf_forward(_a5_slotarr->buf); }
                    if ((size_t) l6 >= _a5_slotarr->length) { vader_trap("array index out of bounds"); }
                    t0 = vader_array_box_slots(_a5_slotarr->buf)[_a5_slotarr->offset + (size_t) l6];
                    l20 = t0.payload.s;
                    vader_array_push((vader_array_t*) l5, vader_box_string(167u, l20));
                    l21 = (size_t) (int64_t) INT64_C(1);
                    t5 = (l6 + l21);
                    l6 = (size_t) (int64_t) t5;
                    goto loop_15;
                }
                vader_array_t* _a6_slotarr = ((vader_array_t*) l3);
                if (_a6_slotarr->buf != NULL && _a6_slotarr->buf->header.forward != NULL) { _a6_slotarr->buf = vader_array_buf_forward(_a6_slotarr->buf); }
                if ((size_t) l6 >= _a6_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_box_slots(_a6_slotarr->buf)[_a6_slotarr->offset + (size_t) l6];
                l20 = t0.payload.s;
                vader_array_push((vader_array_t*) l5, vader_box_string(167u, l20));
                l21 = (size_t) (int64_t) INT64_C(1);
                t5 = (l6 + l21);
                l6 = (size_t) (int64_t) t5;
                goto loop_15;
            } else {
            }
        }
    }
    t1 = std_string_join(l5, 1u);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static bool vader_c_emit_has_str_data(void* l0) {
    void* l1;
    size_t l2, l3;
    vader_box_t l4;
    int64_t t0;
    l1 = l0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    l2 = ((vader_array_t*) l1)->length;
    l3 = (size_t) (int64_t) INT64_C(0);
    {
        loop_7: {
            if ((l3 < l2)) {
                if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                l4 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
                if (l4.tag == 508u) {
                    return true;
                }
                if (l4.tag == 495u) {
                    return true;
                }
                t0 = (l3 + INT64_C(1));
                l3 = (size_t) (int64_t) t0;
                goto loop_7;
            } else {
            }
        }
    }
    return false;
}

static vader_string_t vader_c_emit_host_shim_name(void* l0) {
    vader_string_t l1 = 0;
    vader_string_t t0 = 0;
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[2] = { &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_bytecode_BcImport_t*) l0)->f_mangled_name;
    l1 = vader_c_emit_sanitise(t0);
    t0 = concat_2(2351u, l1);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_string_t vader_c_emit_i32_lit_c(int32_t l0) {
    int32_t l1;
    void* l2 = NULL;
    size_t l3;
    int64_t l4;
    vader_string_t t0 = 0;
    void** gc_raw_roots[1] = { &l2 };
    vader_string_t* gc_atom_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l1 = (-(INT32_C(2147483647)) - INT32_C(1));
    if (l0 == l1) {
        { vader_gc_top = gc_frame.prev; return 606u; }
    }
    l2 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(29));
    l3 = (size_t) (int64_t) INT64_C(0);
    l3 = std_core_write_string_at(l2, l3, 605u);
    l4 = ((int64_t) (int32_t) l0);
    l3 = std_core_write_int(l2, l3, l4);
    l3 = std_core_write_string_at(l2, l3, 318u);
    t0 = std_core_finish_buffer(l2, l3);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_string_t vader_c_emit_i64_lit_c(int64_t l0) {
    int64_t l1;
    void* l2 = NULL;
    size_t l3;
    vader_string_t t0 = 0;
    void** gc_raw_roots[1] = { &l2 };
    vader_string_t* gc_atom_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l1 = (-(INT64_C(9223372036854775807)) - INT64_C(1));
    if (l0 == l1) {
        { vader_gc_top = gc_frame.prev; return 608u; }
    }
    l2 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(29));
    l3 = (size_t) (int64_t) INT64_C(0);
    l3 = std_core_write_string_at(l2, l3, 607u);
    l3 = std_core_write_int(l2, l3, l0);
    l3 = std_core_write_string_at(l2, l3, 318u);
    t0 = std_core_finish_buffer(l2, l3);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_string_t vader_c_emit_import_shim(void* l0, void* l1, int32_t l2) {
    vader_string_t l3 = 0;
    vader_string_t l4 = 0;
    vader_string_t l9 = 0;
    void* l5 = NULL;
    void* l11 = NULL;
    uint8_t l6;
    int32_t l7, l8;
    size_t l10;
    int64_t l12;
    bool l13;
    bool t0;
    vader_string_t t1 = 0;
    void** gc_raw_roots[4] = { &l0, &l1, &l5, &l11 };
    vader_string_t* gc_atom_roots[4] = { &l3, &l4, &l9, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_split;
    l3 = vader_c_emit_shim_linkage_prefix(t0);
    l4 = vader_c_emit_import_shim_signature(l1, l2);
    l3 = concat_2(l3, l4);
    l4 = ((vader_struct_vader_bytecode_BcImport_t*) l1)->f_mangled_name;
    l5 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_types;
    l6 = vader_bytecode_intrinsic_id_for(l4);
    if (l6 == INT32_C(19)) {
        t1 = concat_2(l3, 194u);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l6 == INT32_C(1)) {
        t1 = concat_2(l3, 190u);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l6 == INT32_C(2)) {
        t1 = concat_2(l3, 189u);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l6 == INT32_C(5)) {
        t1 = concat_2(l3, 191u);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l6 == INT32_C(3)) {
        l7 = vader_c_emit_prim_tag(l5, (uint8_t) (int32_t) INT32_C(5));
        if ((l7 < INT32_C(0))) {
            t1 = concat_2(l3, 196u);
            { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l8 = vader_c_emit_array_tag(l5, l7);
        if ((l8 < INT32_C(0))) {
            t1 = concat_2(l3, 197u);
            { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l9 = l3;
        l10 = vader_host_std_core_byte_len(l9);
        l11 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(94) + l10));
        l10 = (size_t) (int64_t) INT64_C(0);
        l10 = std_core_write_string_at(l11, l10, l9);
        l10 = std_core_write_string_at(l11, l10, 182u);
        l12 = ((int64_t) (int32_t) l8);
        l10 = std_core_write_int(l11, l10, l12);
        l10 = std_core_write_string_at(l11, l10, 2209u);
        l12 = ((int64_t) (int32_t) l7);
        l10 = std_core_write_int(l11, l10, l12);
        l10 = std_core_write_string_at(l11, l10, 2207u);
        t1 = std_core_finish_buffer(l11, l10);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l6 == INT32_C(4)) {
        t1 = concat_2(l3, 188u);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l6 == INT32_C(6)) {
        t1 = concat_2(l3, 192u);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l6 == INT32_C(12)) {
        t1 = concat_2(l3, 193u);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l6 == INT32_C(13)) {
        t1 = concat_2(l3, 180u);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l6 == INT32_C(14)) {
        t1 = concat_2(l3, 179u);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l6 == INT32_C(15)) {
        t1 = concat_2(l3, 181u);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l6 == INT32_C(16)) {
        t1 = concat_2(l3, 186u);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l6 == INT32_C(17)) {
        t1 = concat_2(l3, 195u);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l6 == INT32_C(18)) {
        t1 = concat_2(l3, 187u);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l6 == INT32_C(22)) {
        t1 = concat_2(l3, 177u);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l6 == INT32_C(23)) {
        t1 = concat_2(l3, 178u);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l6 == INT32_C(24)) {
        t1 = concat_2(l3, 185u);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l6 == INT32_C(20)) {
        t1 = concat_2(l3, 184u);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l6 == INT32_C(21)) {
        t1 = concat_2(l3, 183u);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l6 == INT32_C(7)) {
        l13 = true;
    } else {
        l13 = l6 == INT32_C(8);
    }
    if (l13) {
        l13 = true;
    } else {
        l13 = l6 == INT32_C(9);
    }
    if (l13) {
        l13 = true;
    } else {
        l13 = l6 == INT32_C(10);
    }
    if (l13) {
        l13 = true;
    } else {
        l13 = l6 == INT32_C(11);
    }
    if (l13) {
        l13 = true;
    } else {
        l13 = l6 == INT32_C(0);
    }
    if (l13) {
        t0 = ((vader_struct_vader_bytecode_BcImport_t*) l1)->f_is_extern;
        if (t0) {
            t1 = vader_c_emit_user_extern_shim(l1, l3, l5);
            { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
        }
        t1 = concat_4(l3, 198u, l4, 228u);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_unreachable("unreachable return in vader_c_emit$import_shim");
    vader_gc_top = gc_frame.prev;
}

static vader_string_t vader_c_emit_import_shim_signature(void* l0, int32_t l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l8 = NULL;
    size_t l4, l5, l7, l9;
    vader_string_t l6 = 0;
    vader_string_t l11 = 0;
    vader_string_t l12 = 0;
    uint64_t l10;
    vader_box_t t0 = vader_box_null();
    int64_t t1;
    size_t t2;
    vader_string_t t3 = 0;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[4] = { &l0, &l2, &l3, &l8 };
    vader_string_t* gc_atom_roots[4] = { &l6, &l11, &l12, &t3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_bytecode_BcImport_t*) l0)->f_signature;
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 167u);
    l3 = (void*) _a0_arr;
    l4 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) l2)->f_params)->length;
    l5 = (size_t) (int64_t) INT64_C(0);
    {
        loop_10: {
            if ((l5 < l4)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) l2)->f_params);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l5 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_read_u8(_a1_slotarr, _a1_slotarr->offset + (size_t) l5, 173u);
                l6 = vader_c_emit_c_type_for_val_bare(((uint8_t) t0.payload.i));
                l7 = vader_host_std_core_byte_len(l6);
                l8 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(22) + l7));
                l9 = (size_t) (int64_t) INT64_C(0);
                l9 = std_core_write_string_at(l8, l9, l6);
                l9 = std_core_write_string_at(l8, l9, 94u);
                t1 = ((int64_t) (size_t) l5);
                l10 = (uint64_t) (int64_t) t1;
                l9 = std_core_write_unsigned(l8, l9, l10);
                l11 = std_core_finish_buffer(l8, l9);
                vader_array_push((vader_array_t*) l3, vader_box_string(167u, l11));
                t1 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t1;
                goto loop_10;
            } else {
            }
        }
    }
    t2 = ((vader_array_t*) l3)->length;
    if (t2 == INT64_C(0)) {
        l6 = 2382u;
    } else {
        l6 = std_string_join(l3, 365u);
    }
    l11 = vader_c_emit_c_type_for_val_bare(((vader_struct_vader_bytecode_BcSignature_t*) l2)->f_result);
    l12 = vader_c_emit_host_shim_name(l0);
    t3 = concat_6(l11, 6u, l12, 278u, l6, 318u);
    { vader_string_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
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
    t0 = std_string_ends_with(l0, 426u);
    if (t0) {
        t1 = std_core_len(l0);
        t2 = (t1 - INT64_C(8));
        l1 = (size_t) (int64_t) t2;
        t3 = vader_string_slice_codepoints(l0, INT64_C(0), l1);
        t4 = concat_2(t3, 416u);
        { vader_string_t __vret = t4; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t3 = concat_2(l0, 416u);
    { vader_string_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void vader_c_emit_indent_pop(void* l0) {
    int32_t l1;
    int32_t t0;
    t0 = ((vader_struct_vader_c_emit_FnState_t*) l0)->f_indent;
    l1 = (t0 - INT32_C(1));
    ((vader_struct_vader_c_emit_FnState_t*) l0)->f_indent = l1;
    VADER_WRITE_BARRIER((vader_struct_vader_c_emit_FnState_t*) l0);
    return;
}

static void vader_c_emit_indent_push(void* l0) {
    int32_t l1;
    int32_t t0;
    t0 = ((vader_struct_vader_c_emit_FnState_t*) l0)->f_indent;
    l1 = (t0 + INT32_C(1));
    ((vader_struct_vader_c_emit_FnState_t*) l0)->f_indent = l1;
    VADER_WRITE_BARRIER((vader_struct_vader_c_emit_FnState_t*) l0);
    return;
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
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l3 = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_functions)->length;
    vader_array_t* _a0_arr = vader_array_new(9u, 0u, 7u, 170u);
    l4 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(6u, 0u, 12u, 165u);
    l5 = (void*) _a1_arr;
    l6 = (size_t) (int64_t) INT64_C(0);
    {
        loop_10: {
            if ((l6 < l3)) {
                l7 = -(INT32_C(1));
                vader_array_push_i32((vader_array_t*) l4, l7);
                vader_array_push_bool((vader_array_t*) l5, false);
                t0 = (l6 + INT64_C(1));
                l6 = (size_t) (int64_t) t0;
                goto loop_10;
            } else {
            }
        }
    }
    vader_array_t* _a2_slotarr = ((vader_array_t*) l1);
    if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
    l6 = ((vader_array_t*) l1)->length;
    l8 = (size_t) (int64_t) INT64_C(0);
    {
        loop_39: {
            if ((l8 < l6)) {
                if ((size_t) l8 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                l9 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l8);
                vader_array_t* _a3_slotarr = ((vader_array_t*) l9);
                if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                l10 = ((vader_array_t*) l9)->length;
                l11 = (size_t) (int64_t) INT64_C(0);
                {
                    loop_53: {
                        if ((l11 < l10)) {
                            t1 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l11];
                            t0 = ((int64_t) (int32_t) t1);
                            l12 = (size_t) (int64_t) t0;
                            l7 = ((int32_t) (size_t) l8);
                            vader_array_t* _a4_slotarr = ((vader_array_t*) l4);
                            if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                            if ((size_t) l12 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                            ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l12] = (int32_t) l7;
                            t0 = (l11 + INT64_C(1));
                            l11 = (size_t) (int64_t) t0;
                            goto loop_53;
                        } else {
                        }
                    }
                }
                t0 = (l8 + INT64_C(1));
                l8 = (size_t) (int64_t) t0;
                goto loop_39;
            } else {
            }
        }
    }
    l9 = ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_exports;
    vader_array_t* _a5_slotarr = ((vader_array_t*) l9);
    if (_a5_slotarr->buf != NULL && _a5_slotarr->buf->header.forward != NULL) { _a5_slotarr->buf = vader_array_buf_forward(_a5_slotarr->buf); }
    l6 = ((vader_array_t*) l9)->length;
    l8 = (size_t) (int64_t) INT64_C(0);
    {
        loop_95: {
            if ((l8 < l6)) {
                if ((size_t) l8 >= _a5_slotarr->length) { vader_trap("array index out of bounds"); }
                t2 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l8);
                t1 = ((vader_struct_vader_bytecode_BcExport_t*) t2)->f_fn_index;
                t0 = ((int64_t) (int32_t) t1);
                l10 = (size_t) (int64_t) t0;
                vader_array_t* _a6_slotarr = ((vader_array_t*) l5);
                if (_a6_slotarr->buf != NULL && _a6_slotarr->buf->header.forward != NULL) { _a6_slotarr->buf = vader_array_buf_forward(_a6_slotarr->buf); }
                if ((size_t) l10 >= _a6_slotarr->length) { vader_trap("array index out of bounds"); }
                ((uint8_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l10] = (uint8_t) true;
                t0 = (l8 + INT64_C(1));
                l8 = (size_t) (int64_t) t0;
                goto loop_95;
            } else {
            }
        }
    }
    l9 = ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_vtables;
    vader_array_t* _a7_slotarr = ((vader_array_t*) l9);
    if (_a7_slotarr->buf != NULL && _a7_slotarr->buf->header.forward != NULL) { _a7_slotarr->buf = vader_array_buf_forward(_a7_slotarr->buf); }
    l6 = ((vader_array_t*) l9)->length;
    l8 = (size_t) (int64_t) INT64_C(0);
    {
        loop_127: {
            if ((l8 < l6)) {
                if ((size_t) l8 >= _a7_slotarr->length) { vader_trap("array index out of bounds"); }
                t2 = vader_array_ref_load_obj(_a7_slotarr->buf, _a7_slotarr->offset + (size_t) l8);
                l13 = ((vader_struct_vader_bytecode_VtableRow_t*) t2)->f_entries;
                vader_array_t* _a8_slotarr = ((vader_array_t*) l13);
                if (_a8_slotarr->buf != NULL && _a8_slotarr->buf->header.forward != NULL) { _a8_slotarr->buf = vader_array_buf_forward(_a8_slotarr->buf); }
                l10 = ((vader_array_t*) l13)->length;
                l11 = (size_t) (int64_t) INT64_C(0);
                {
                    loop_142: {
                        if ((l11 < l10)) {
                            if ((size_t) l11 >= _a8_slotarr->length) { vader_trap("array index out of bounds"); }
                            t2 = vader_array_ref_load_obj(_a8_slotarr->buf, _a8_slotarr->offset + (size_t) l11);
                            t1 = ((vader_struct_vader_bytecode_VtableEntry_t*) t2)->f_fn_index;
                            t0 = ((int64_t) (int32_t) t1);
                            l12 = (size_t) (int64_t) t0;
                            vader_array_t* _a9_slotarr = ((vader_array_t*) l5);
                            if (_a9_slotarr->buf != NULL && _a9_slotarr->buf->header.forward != NULL) { _a9_slotarr->buf = vader_array_buf_forward(_a9_slotarr->buf); }
                            if ((size_t) l12 >= _a9_slotarr->length) { vader_trap("array index out of bounds"); }
                            ((uint8_t*) _a9_slotarr->buf->slots)[_a9_slotarr->offset + (size_t) l12] = (uint8_t) true;
                            t0 = (l11 + INT64_C(1));
                            l11 = (size_t) (int64_t) t0;
                            goto loop_142;
                        } else {
                        }
                    }
                }
                t0 = (l8 + INT64_C(1));
                l8 = (size_t) (int64_t) t0;
                goto loop_127;
            } else {
            }
        }
    }
    l9 = vader_c_emit_scan_fn_value_usage(((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_functions);
    l6 = (size_t) (int64_t) INT64_C(0);
    {
        loop_182: {
            if ((l6 < l3)) {
                vader_array_t* _a10_slotarr = ((vader_array_t*) ((vader_struct_vader_c_emit_FnValueUsage_t*) l9)->f_fn_ref_type);
                if (_a10_slotarr->buf != NULL && _a10_slotarr->buf->header.forward != NULL) { _a10_slotarr->buf = vader_array_buf_forward(_a10_slotarr->buf); }
                if ((size_t) l6 >= _a10_slotarr->length) { vader_trap("array index out of bounds"); }
                t1 = ((int32_t*) _a10_slotarr->buf->slots)[_a10_slotarr->offset + (size_t) l6];
                if ((t1 >= INT32_C(0))) {
                    l14 = true;
                } else {
                    vader_array_t* _a11_slotarr = ((vader_array_t*) ((vader_struct_vader_c_emit_FnValueUsage_t*) l9)->f_is_closure);
                    if (_a11_slotarr->buf != NULL && _a11_slotarr->buf->header.forward != NULL) { _a11_slotarr->buf = vader_array_buf_forward(_a11_slotarr->buf); }
                    if ((size_t) l6 >= _a11_slotarr->length) { vader_trap("array index out of bounds"); }
                    t3 = vader_box_bool(165u, ((uint8_t*) _a11_slotarr->buf->slots)[_a11_slotarr->offset + (size_t) l6]);
                    l14 = t3.payload.b;
                }
                if (l14) {
                    vader_array_t* _a12_slotarr = ((vader_array_t*) l5);
                    if (_a12_slotarr->buf != NULL && _a12_slotarr->buf->header.forward != NULL) { _a12_slotarr->buf = vader_array_buf_forward(_a12_slotarr->buf); }
                    if ((size_t) l6 >= _a12_slotarr->length) { vader_trap("array index out of bounds"); }
                    ((uint8_t*) _a12_slotarr->buf->slots)[_a12_slotarr->offset + (size_t) l6] = (uint8_t) true;
                } else {
                }
                if (l2 != 0u) {
                    vader_array_t* _a13_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_functions);
                    if (_a13_slotarr->buf != NULL && _a13_slotarr->buf->header.forward != NULL) { _a13_slotarr->buf = vader_array_buf_forward(_a13_slotarr->buf); }
                    if ((size_t) l6 >= _a13_slotarr->length) { vader_trap("array index out of bounds"); }
                    t2 = vader_array_ref_load_obj(_a13_slotarr->buf, _a13_slotarr->offset + (size_t) l6);
                    t4 = ((vader_struct_vader_bytecode_BcFunction_t*) t2)->f_name;
                    l15 = t4 == l2;
                } else {
                    l15 = false;
                }
                if (l15) {
                    vader_array_t* _a14_slotarr = ((vader_array_t*) l5);
                    if (_a14_slotarr->buf != NULL && _a14_slotarr->buf->header.forward != NULL) { _a14_slotarr->buf = vader_array_buf_forward(_a14_slotarr->buf); }
                    if ((size_t) l6 >= _a14_slotarr->length) { vader_trap("array index out of bounds"); }
                    ((uint8_t*) _a14_slotarr->buf->slots)[_a14_slotarr->offset + (size_t) l6] = (uint8_t) true;
                } else {
                }
                t0 = (l6 + INT64_C(1));
                l6 = (size_t) (int64_t) t0;
                goto loop_182;
            } else {
            }
        }
    }
    l6 = (size_t) (int64_t) INT64_C(0);
    {
        loop_246: {
            if ((l6 < l3)) {
                vader_array_t* _a15_slotarr = ((vader_array_t*) l4);
                if (_a15_slotarr->buf != NULL && _a15_slotarr->buf->header.forward != NULL) { _a15_slotarr->buf = vader_array_buf_forward(_a15_slotarr->buf); }
                if ((size_t) l6 >= _a15_slotarr->length) { vader_trap("array index out of bounds"); }
                l7 = ((int32_t*) _a15_slotarr->buf->slots)[_a15_slotarr->offset + (size_t) l6];
                vader_array_t* _a16_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_functions);
                if (_a16_slotarr->buf != NULL && _a16_slotarr->buf->header.forward != NULL) { _a16_slotarr->buf = vader_array_buf_forward(_a16_slotarr->buf); }
                if ((size_t) l6 >= _a16_slotarr->length) { vader_trap("array index out of bounds"); }
                t2 = vader_array_ref_load_obj(_a16_slotarr->buf, _a16_slotarr->offset + (size_t) l6);
                l9 = ((vader_struct_vader_bytecode_BcFunction_t*) t2)->f_body;
                vader_array_t* _a17_slotarr = ((vader_array_t*) l9);
                if (_a17_slotarr->buf != NULL && _a17_slotarr->buf->header.forward != NULL) { _a17_slotarr->buf = vader_array_buf_forward(_a17_slotarr->buf); }
                l8 = ((vader_array_t*) l9)->length;
                l10 = (size_t) (int64_t) INT64_C(0);
                {
                    loop_265: {
                        if ((l10 < l8)) {
                            if ((size_t) l10 >= _a17_slotarr->length) { vader_trap("array index out of bounds"); }
                            t3 = vader_array_ref_load_box(_a17_slotarr->buf, _a17_slotarr->offset + (size_t) l10);
                            l16 = vader_c_emit_callee_index_of(t3);
                            if ((l16 >= INT32_C(0))) {
                                t0 = ((int64_t) (int32_t) l16);
                                l11 = (size_t) (int64_t) t0;
                                vader_array_t* _a18_slotarr = ((vader_array_t*) l4);
                                if (_a18_slotarr->buf != NULL && _a18_slotarr->buf->header.forward != NULL) { _a18_slotarr->buf = vader_array_buf_forward(_a18_slotarr->buf); }
                                if ((size_t) l11 >= _a18_slotarr->length) { vader_trap("array index out of bounds"); }
                                t1 = ((int32_t*) _a18_slotarr->buf->slots)[_a18_slotarr->offset + (size_t) l11];
                                l14 = t1 != l7;
                            } else {
                                l14 = false;
                            }
                            if (l14) {
                                t0 = ((int64_t) (int32_t) l16);
                                l12 = (size_t) (int64_t) t0;
                                vader_array_t* _a19_slotarr = ((vader_array_t*) l5);
                                if (_a19_slotarr->buf != NULL && _a19_slotarr->buf->header.forward != NULL) { _a19_slotarr->buf = vader_array_buf_forward(_a19_slotarr->buf); }
                                if ((size_t) l12 >= _a19_slotarr->length) { vader_trap("array index out of bounds"); }
                                ((uint8_t*) _a19_slotarr->buf->slots)[_a19_slotarr->offset + (size_t) l12] = (uint8_t) true;
                            } else {
                            }
                            t0 = (l10 + INT64_C(1));
                            l10 = (size_t) (int64_t) t0;
                            goto loop_265;
                        } else {
                        }
                    }
                }
                t0 = (l6 + INT64_C(1));
                l6 = (size_t) (int64_t) t0;
                goto loop_246;
            } else {
            }
        }
    }
    vader_array_t* _a20_arr = vader_array_new(6u, 0u, 12u, 165u);
    l4 = (void*) _a20_arr;
    l6 = (size_t) (int64_t) INT64_C(0);
    {
        loop_325: {
            if ((l6 < l3)) {
                vader_array_t* _a21_slotarr = ((vader_array_t*) l5);
                if (_a21_slotarr->buf != NULL && _a21_slotarr->buf->header.forward != NULL) { _a21_slotarr->buf = vader_array_buf_forward(_a21_slotarr->buf); }
                if ((size_t) l6 >= _a21_slotarr->length) { vader_trap("array index out of bounds"); }
                t3 = vader_box_bool(165u, ((uint8_t*) _a21_slotarr->buf->slots)[_a21_slotarr->offset + (size_t) l6]);
                t5 = t3.payload.b;
                l14 = !(t5);
                vader_array_push_bool((vader_array_t*) l4, l14);
                t0 = (l6 + INT64_C(1));
                l6 = (size_t) (int64_t) t0;
                goto loop_325;
            } else {
            }
        }
    }
    { void* __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void vader_c_emit_invalidate_resolve_cache(void* l0, vader_box_t l1) {
    int32_t l2;
    bool l3;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* t0 = NULL;
    bool t1;
    size_t t2;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[5] = { &l0, &l4, &l5, &l6, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l1.tag == 613u) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_vader_bytecode_LocalSet_t*) t0)->f_slot;
        vader_c_emit_drop_resolved_for_local(l0, l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 614u) {
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
        t2 = ((vader_struct_std_collections_MutableMap__string__bool_t*) ((vader_struct_std_collections_MutableSet__string_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_pinned_resolves)->f_inner)->f_size;
        l3 = (t2 > INT64_C(0));
    } else {
        l3 = false;
    }
    if (l3) {
        vader_c_emit_keep_pinned_resolves(l0);
    } else {
        std_collections_clear__string__string(((vader_struct_vader_c_emit_FnState_t*) l0)->f_resolved_arrays);
        vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 167u);
        l4 = (void*) _a0_arr;
        vader_array_t* _a1_arr = vader_array_new(6u, 0u, 12u, 165u);
        l5 = (void*) _a1_arr;
        vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 170u);
        l6 = (void*) _a2_arr;
        vader_struct_std_collections_MutableMap__string__bool_t* _a3_obj = (vader_struct_std_collections_MutableMap__string__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__bool_t));
        vader_obj_header_init(_a3_obj, 357u);
        _a3_obj->f_ekeys = l4;
        _a3_obj->f_evals = l5;
        _a3_obj->f_index = l6;
        _a3_obj->f_mask = (size_t) (int64_t) INT64_C(0);
        _a3_obj->f_size = (size_t) (int64_t) INT64_C(0);
        _a3_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
        t0 = (void*) _a3_obj;
        vader_struct_std_collections_MutableSet__string_t* _a4_obj = (vader_struct_std_collections_MutableSet__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__string_t));
        vader_obj_header_init(_a4_obj, 378u);
        _a4_obj->f_inner = t0;
        l4 = (void*) _a4_obj;
        ((vader_struct_vader_c_emit_FnState_t*) l0)->f_pinned_resolves = l4;
        VADER_WRITE_BARRIER((vader_struct_vader_c_emit_FnState_t*) l0);
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
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
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    if ((size_t) l1 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
    t1 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l1);
    return t1.tag == 496u;
}

static bool vader_c_emit_is_abi_nullable_pointer(void* l0, int32_t l1) {
    int32_t l2, l10;
    vader_box_t l3;
    void* l4;
    void* l11;
    bool l5, l6, l9;
    size_t l7, l8;
    size_t t0;
    int64_t t1;
    if ((l1 < INT32_C(0))) {
        return false;
    }
    t0 = ((vader_array_t*) l0)->length;
    l2 = ((int32_t) (size_t) t0);
    if ((l1 >= l2)) {
        return false;
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    if ((size_t) l1 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
    l3 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l1);
    if (l3.tag == 510u) {
        l4 = l3.payload.obj;
        t0 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcUnion_t*) l4)->f_variants)->length;
        if (t0 != INT64_C(2)) {
            return false;
        }
        l5 = false;
        l6 = false;
        l4 = ((vader_struct_vader_bytecode_BcUnion_t*) l4)->f_variants;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l4);
        if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
        l7 = ((vader_array_t*) l4)->length;
        l8 = (size_t) (int64_t) INT64_C(0);
        {
            loop_43: {
                if ((l8 < l7)) {
                    l2 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l8];
                    if ((l2 < INT32_C(0))) {
                        l9 = true;
                    } else {
                        t0 = ((vader_array_t*) l0)->length;
                        l10 = ((int32_t) (size_t) t0);
                        l9 = (l2 >= l10);
                    }
                    if (l9) {
                        t1 = (l8 + INT64_C(1));
                        l8 = (size_t) (int64_t) t1;
                        goto loop_43;
                    }
                    vader_array_t* _a2_slotarr = ((vader_array_t*) l0);
                    if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                    if ((size_t) l2 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                    l3 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l2);
                    if (l3.tag == 505u) {
                        l11 = l3.payload.obj;
                        if (((vader_struct_vader_bytecode_BcPrimitive_t*) l11)->f_val == INT32_C(15)) {
                            l5 = true;
                        } else {
                        }
                        if (((vader_struct_vader_bytecode_BcPrimitive_t*) l11)->f_val == INT32_C(17)) {
                            l6 = true;
                        } else {
                        }
                    } else {
                    }
                    t1 = (l8 + INT64_C(1));
                    l8 = (size_t) (int64_t) t1;
                    goto loop_43;
                } else {
                }
            }
        }
        if (l5) {
            l5 = l6;
        } else {
            l5 = false;
        }
        return l5;
    }
    return false;
}

static bool vader_c_emit_is_abi_nullable_string(void* l0, int32_t l1) {
    bool l2, l5, l9;
    int32_t l3, l10;
    vader_box_t l4;
    void* l6;
    void* l11;
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
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    if ((size_t) l1 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
    l4 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l1);
    if (!(l4.tag == 510u)) {
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
    if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
    l7 = ((vader_array_t*) l6)->length;
    l8 = (size_t) (int64_t) INT64_C(0);
    {
        loop_51: {
            if ((l8 < l7)) {
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
                    goto loop_51;
                }
                vader_array_t* _a2_slotarr = ((vader_array_t*) l0);
                if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                if ((size_t) l3 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                l4 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l3);
                if (l4.tag == 505u) {
                    l11 = l4.payload.obj;
                    if (((vader_struct_vader_bytecode_BcPrimitive_t*) l11)->f_val == INT32_C(15)) {
                        l2 = true;
                    } else {
                    }
                    if (((vader_struct_vader_bytecode_BcPrimitive_t*) l11)->f_val == INT32_C(14)) {
                        l5 = true;
                    } else {
                    }
                } else {
                }
                t2 = (l8 + INT64_C(1));
                l8 = (size_t) (int64_t) t2;
                goto loop_51;
            } else {
            }
        }
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
    t0 = (void*) &vader_data_7;
    t1 = std_core____Contains_contains__string(t0, l0);
    return t1;
}

static bool vader_c_emit_is_cache_safe(vader_box_t l0) {
    if ((l0.tag == 611u || l0.tag == 612u || l0.tag == 637u)) {
        return true;
    }
    if ((l0.tag == 607u || l0.tag == 608u || l0.tag == 609u)) {
        return true;
    }
    if ((l0.tag == 629u || l0.tag == 630u || l0.tag == 631u)) {
        return true;
    }
    if ((l0.tag == 486u || l0.tag == 487u || l0.tag == 493u)) {
        return true;
    }
    if ((l0.tag == 604u || l0.tag == 605u || l0.tag == 606u || l0.tag == 610u)) {
        return true;
    }
    if ((l0.tag == 626u || l0.tag == 627u || l0.tag == 628u || l0.tag == 632u)) {
        return true;
    }
    if ((l0.tag == 519u || l0.tag == 535u || l0.tag == 548u || l0.tag == 567u || l0.tag == 587u)) {
        return true;
    }
    if ((l0.tag == 537u || l0.tag == 560u || l0.tag == 561u || l0.tag == 618u || l0.tag == 624u || l0.tag == 633u || l0.tag == 641u)) {
        return true;
    }
    if ((l0.tag == 562u || l0.tag == 568u || l0.tag == 574u || l0.tag == 575u || l0.tag == 577u || l0.tag == 581u)) {
        return true;
    }
    if ((l0.tag == 582u || l0.tag == 588u || l0.tag == 594u || l0.tag == 595u || l0.tag == 597u || l0.tag == 601u)) {
        return true;
    }
    if ((l0.tag == 547u || l0.tag == 549u || l0.tag == 555u || l0.tag == 557u || l0.tag == 558u)) {
        return true;
    }
    if ((l0.tag == 642u || l0.tag == 647u || l0.tag == 648u || l0.tag == 653u)) {
        return true;
    }
    if ((l0.tag == 563u || l0.tag == 564u || l0.tag == 565u || l0.tag == 566u || l0.tag == 578u || l0.tag == 579u || l0.tag == 580u)) {
        return true;
    }
    if ((l0.tag == 583u || l0.tag == 584u || l0.tag == 585u || l0.tag == 586u || l0.tag == 598u || l0.tag == 599u || l0.tag == 600u)) {
        return true;
    }
    if ((l0.tag == 569u || l0.tag == 570u || l0.tag == 571u || l0.tag == 572u || l0.tag == 573u || l0.tag == 576u)) {
        return true;
    }
    if ((l0.tag == 589u || l0.tag == 590u || l0.tag == 591u || l0.tag == 592u || l0.tag == 593u || l0.tag == 596u)) {
        return true;
    }
    if ((l0.tag == 550u || l0.tag == 551u || l0.tag == 552u || l0.tag == 553u || l0.tag == 554u || l0.tag == 556u)) {
        return true;
    }
    if ((l0.tag == 643u || l0.tag == 644u || l0.tag == 645u || l0.tag == 646u || l0.tag == 649u || l0.tag == 650u || l0.tag == 651u || l0.tag == 652u)) {
        return true;
    }
    if ((l0.tag == 520u || l0.tag == 521u)) {
        return true;
    }
    if ((l0.tag == 620u || l0.tag == 621u || l0.tag == 634u || l0.tag == 635u)) {
        return true;
    }
    if ((l0.tag == 518u || l0.tag == 522u || l0.tag == 523u)) {
        return true;
    }
    if ((l0.tag == 515u || l0.tag == 516u || l0.tag == 536u || l0.tag == 546u || l0.tag == 559u || l0.tag == 619u)) {
        return true;
    }
    if (l0.tag == 541u) {
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

static bool vader_c_emit_is_digit_byte(uint8_t l0) {
    bool l1;
    if ((l0 >= INT32_C(48))) {
        l1 = (l0 <= INT32_C(57));
    } else {
        l1 = false;
    }
    return l1;
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
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    if ((size_t) l1 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
    t0 = vader_box_bool(165u, ((uint8_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l1]);
    t1 = t0.payload.b;
    return t1;
}

static bool vader_c_emit_is_pure_control_flow(vader_box_t l0) {
    return (l0.tag == 517u || l0.tag == 525u || l0.tag == 526u || l0.tag == 545u || l0.tag == 602u || l0.tag == 615u || l0.tag == 622u);
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
    return (l0.tag == 517u || l0.tag == 602u || l0.tag == 615u);
}

static vader_string_t vader_c_emit_join_commas(void* l0) {
    void* l1 = NULL;
    size_t l2, l3;
    vader_string_t l4 = 0;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    int64_t t2;
    vader_string_t t3 = 0;
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[3] = { &l0, &l1, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l4, &t3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 167u);
    t0 = (void*) _a0_arr;
    vader_struct_std_string_builder_StringBuilder_t* _a1_obj = (vader_struct_std_string_builder_StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string_builder_StringBuilder_t));
    vader_obj_header_init(_a1_obj, 389u);
    _a1_obj->f_parts = t0;
    l1 = (void*) _a1_obj;
    l2 = ((vader_array_t*) l0)->length;
    l3 = (size_t) (int64_t) INT64_C(0);
    {
        loop_9: {
            if ((l3 < l2)) {
                if ((l3 > INT64_C(0))) {
                    std_string_builder_append(l1, 365u);
                } else {
                }
                vader_array_t* _a2_slotarr = ((vader_array_t*) l0);
                if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                if ((size_t) l3 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                t1 = vader_array_box_slots(_a2_slotarr->buf)[_a2_slotarr->offset + (size_t) l3];
                l4 = t1.payload.s;
                std_string_builder_append(l1, l4);
                t2 = (l3 + INT64_C(1));
                l3 = (size_t) (int64_t) t2;
                goto loop_9;
            } else {
            }
        }
    }
    t3 = std_string_builder_StringBuilder_Display_to_string(l1);
    { vader_string_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void vader_c_emit_keep_pinned_resolves(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    size_t l4, l5;
    vader_string_t l6 = 0;
    vader_string_t l8 = 0;
    vader_box_t l7 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    int64_t t1;
    vader_box_t* gc_roots[2] = { &l7, &t0 };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &l3 };
    vader_string_t* gc_atom_roots[2] = { &l6, &l8 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 167u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(8u, 0u, 0u, 167u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 170u);
    l3 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__string__string_t* _a3_obj = (vader_struct_std_collections_MutableMap__string__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__string_t));
    vader_obj_header_init(_a3_obj, 361u);
    _a3_obj->f_ekeys = l1;
    _a3_obj->f_evals = l2;
    _a3_obj->f_index = l3;
    _a3_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l1 = (void*) _a3_obj;
    l2 = ((vader_struct_vader_c_emit_FnState_t*) l0)->f_pinned_resolves;
    l3 = ((vader_struct_std_collections_MutableMap__string__bool_t*) ((vader_struct_std_collections_MutableSet__string_t*) l2)->f_inner)->f_ekeys;
    l4 = ((vader_struct_std_collections_MutableMap__string__bool_t*) ((vader_struct_std_collections_MutableSet__string_t*) l2)->f_inner)->f_size;
    l5 = (size_t) (int64_t) INT64_C(0);
    {
        loop_26: {
            if ((l5 >= l4)) {
            } else {
                vader_array_t* _a4_slotarr = ((vader_array_t*) l3);
                if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                if ((size_t) l5 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_box_slots(_a4_slotarr->buf)[_a4_slotarr->offset + (size_t) l5];
                l6 = t0.payload.s;
                t1 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t1;
                l7 = std_collections_get__string__string(((vader_struct_vader_c_emit_FnState_t*) l0)->f_resolved_arrays, l6);
                if (l7.tag == 167u) {
                    l8 = l7.payload.s;
                    std_collections_put__string__string(l1, l6, l8);
                } else {
                }
                goto loop_26;
            }
        }
    }
    ((vader_struct_vader_c_emit_FnState_t*) l0)->f_resolved_arrays = l1;
    VADER_WRITE_BARRIER((vader_struct_vader_c_emit_FnState_t*) l0);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static bool vader_c_emit_key_mentions_local(vader_string_t l0, int32_t l1) {
    size_t l2, l3, l4, l12, l13, l28, l31;
    uint8_t l5, l17, l18, l20, l21, l24, l25;
    bool l6, l7, l8, l9, l10, l11, l16, l19, l30;
    int32_t l14, l15, l22, l23, l26, l27, l29;
    uint8_t t0;
    int64_t t1;
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = vader_host_std_core_byte_len(l0);
    l3 = (size_t) (int64_t) INT64_C(0);
    {
        loop_6: {
            if ((l3 < l2)) {
                t0 = vader_host_std_core_byte_at(l0, l3);
                if (t0 != INT32_C(108)) {
                    t1 = (l3 + INT64_C(1));
                    l3 = (size_t) (int64_t) t1;
                    goto loop_6;
                }
                if ((l3 > INT64_C(0))) {
                    t1 = (l3 - INT64_C(1));
                    l4 = (size_t) (int64_t) t1;
                    l5 = vader_host_std_core_byte_at(l0, l4);
                    if ((l5 >= INT32_C(97))) {
                        l6 = (l5 <= INT32_C(122));
                    } else {
                        l6 = false;
                    }
                    if (l6) {
                        l7 = true;
                    } else {
                        if ((l5 >= INT32_C(65))) {
                            l8 = (l5 <= INT32_C(90));
                        } else {
                            l8 = false;
                        }
                        l7 = l8;
                    }
                    if (l7) {
                        l9 = true;
                    } else {
                        if ((l5 >= INT32_C(48))) {
                            l10 = (l5 <= INT32_C(57));
                        } else {
                            l10 = false;
                        }
                        l9 = l10;
                    }
                    if (l9) {
                        l11 = true;
                    } else {
                        l11 = l5 == INT32_C(95);
                    }
                    if (l11) {
                        t1 = (l3 + INT64_C(1));
                        l3 = (size_t) (int64_t) t1;
                        goto loop_6;
                    }
                    l12 = (size_t) (int64_t) INT64_C(1);
                    t1 = (l3 + l12);
                    l13 = (size_t) (int64_t) t1;
                    l14 = INT32_C(0);
                    l15 = INT32_C(0);
                    {
                        loop_115: {
                            if ((l13 < l2)) {
                                l17 = vader_host_std_core_byte_at(l0, l13);
                                l18 = (uint8_t) (int32_t) INT32_C(48);
                                l16 = (l17 >= l18);
                            } else {
                                l16 = false;
                            }
                            if (l16) {
                                l20 = vader_host_std_core_byte_at(l0, l13);
                                l21 = (uint8_t) (int32_t) INT32_C(57);
                                l19 = (l20 <= l21);
                            } else {
                                l19 = false;
                            }
                            if (l19) {
                                l22 = INT32_C(10);
                                l23 = (l14 * l22);
                                l24 = vader_host_std_core_byte_at(l0, l13);
                                l25 = (uint8_t) (int32_t) INT32_C(48);
                                l26 = (l24 - l25);
                                l14 = (l23 + l26);
                                l27 = INT32_C(1);
                                l15 = (l15 + l27);
                                l28 = (size_t) (int64_t) INT64_C(1);
                                t1 = (l13 + l28);
                                l13 = (size_t) (int64_t) t1;
                                goto loop_115;
                            } else {
                            }
                        }
                    }
                    l29 = INT32_C(0);
                    if ((l15 > l29)) {
                        l30 = l14 == l1;
                    } else {
                        l30 = false;
                    }
                    if (l30) {
                        { vader_gc_top = gc_frame.prev; return true; }
                    }
                    l31 = (size_t) (int64_t) INT64_C(1);
                    t1 = (l3 + l31);
                    l3 = (size_t) (int64_t) t1;
                    goto loop_6;
                }
                l12 = (size_t) (int64_t) INT64_C(1);
                t1 = (l3 + l12);
                l13 = (size_t) (int64_t) t1;
                l14 = INT32_C(0);
                l15 = INT32_C(0);
                {
                    loop_227: {
                        if ((l13 < l2)) {
                            l17 = vader_host_std_core_byte_at(l0, l13);
                            l18 = (uint8_t) (int32_t) INT32_C(48);
                            l16 = (l17 >= l18);
                        } else {
                            l16 = false;
                        }
                        if (l16) {
                            l20 = vader_host_std_core_byte_at(l0, l13);
                            l21 = (uint8_t) (int32_t) INT32_C(57);
                            l19 = (l20 <= l21);
                        } else {
                            l19 = false;
                        }
                        if (l19) {
                            l22 = INT32_C(10);
                            l23 = (l14 * l22);
                            l24 = vader_host_std_core_byte_at(l0, l13);
                            l25 = (uint8_t) (int32_t) INT32_C(48);
                            l26 = (l24 - l25);
                            l14 = (l23 + l26);
                            l27 = INT32_C(1);
                            l15 = (l15 + l27);
                            l28 = (size_t) (int64_t) INT64_C(1);
                            t1 = (l13 + l28);
                            l13 = (size_t) (int64_t) t1;
                            goto loop_227;
                        } else {
                        }
                    }
                }
                l29 = INT32_C(0);
                if ((l15 > l29)) {
                    l30 = l14 == l1;
                } else {
                    l30 = false;
                }
                if (l30) {
                    { vader_gc_top = gc_frame.prev; return true; }
                }
                l31 = (size_t) (int64_t) INT64_C(1);
                t1 = (l3 + l31);
                l3 = (size_t) (int64_t) t1;
                goto loop_6;
            } else {
            }
        }
    }
    { vader_gc_top = gc_frame.prev; return false; }
    vader_gc_top = gc_frame.prev;
}

static size_t vader_c_emit_leading_spaces(void* l0, size_t l1) {
    size_t l2;
    bool l3;
    vader_box_t t0;
    uint8_t t1;
    int64_t t2;
    l2 = (size_t) (int64_t) INT64_C(0);
    {
        loop_3: {
            if ((l2 < l1)) {
                vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
                if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                if ((size_t) l2 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l2, 173u);
                t1 = ((uint8_t) t0.payload.i);
                l3 = t1 == INT32_C(32);
            } else {
                l3 = false;
            }
            if (l3) {
                t2 = (l2 + INT64_C(1));
                l2 = (size_t) (int64_t) t2;
                goto loop_3;
            } else {
            }
        }
    }
    return l2;
}

static vader_string_t vader_c_emit_lift_unbox_tail(void* l0) {
    void* l1 = NULL;
    void* l4 = NULL;
    size_t l2, l3, l5;
    uint64_t l6;
    vader_string_t l7 = 0;
    vader_string_t l9 = 0;
    uint8_t l8;
    int64_t t0;
    vader_box_t t1 = vader_box_null();
    vader_string_t t2 = 0;
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[3] = { &l0, &l1, &l4 };
    vader_string_t* gc_atom_roots[3] = { &l7, &l9, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 167u);
    l1 = (void*) _a0_arr;
    l2 = ((vader_array_t*) l0)->length;
    l3 = (size_t) (int64_t) INT64_C(1);
    {
        loop_8: {
            if ((l3 < l2)) {
                l4 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(21));
                l5 = (size_t) (int64_t) INT64_C(0);
                l5 = std_core_write_string_at(l4, l5, 1146u);
                t0 = (l3 - INT64_C(1));
                l6 = (uint64_t) (int64_t) t0;
                l5 = std_core_write_unsigned(l4, l5, l6);
                l7 = std_core_finish_buffer(l4, l5);
                vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l3 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                t1 = vader_array_read_u8(_a1_slotarr, _a1_slotarr->offset + (size_t) l3, 173u);
                l8 = ((uint8_t) t1.payload.i);
                l9 = vader_c_emit_unbox_expr(l7, l8);
                vader_array_push((vader_array_t*) l1, vader_box_string(167u, l9));
                t0 = (l3 + INT64_C(1));
                l3 = (size_t) (int64_t) t0;
                goto loop_8;
            } else {
            }
        }
    }
    t2 = std_string_join(l1, 365u);
    { vader_string_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void vader_c_emit_line(void* l0, vader_string_t l1) {
    void* l2 = NULL;
    int32_t l3;
    int32_t t0;
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_c_emit_FnState_t*) l0)->f_out;
    t0 = ((vader_struct_vader_c_emit_FnState_t*) l0)->f_indent;
    l3 = (t0 * INT32_C(4));
    std_string_builder_append_repeated(l2, 32u, l3);
    std_string_builder_append(((vader_struct_vader_c_emit_FnState_t*) l0)->f_out, l1);
    std_string_builder_append(((vader_struct_vader_c_emit_FnState_t*) l0)->f_out, 1u);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static vader_string_t vader_c_emit_linkage_prefix(bool l0) {
    vader_string_t l1;
    if (l0) {
        l1 = 0u;
    } else {
        l1 = 2030u;
    }
    return l1;
}

static vader_box_t vader_c_emit_materialise_entry(void* l0, vader_box_t l1) {
    uint8_t l2;
    vader_string_t l3 = 0;
    vader_string_t l4 = 0;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l3, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = vader_c_emit_val_of(l1);
    l3 = vader_c_emit_fresh_tmp(l0, l2);
    l4 = vader_c_emit_name_of(l1);
    l4 = concat_4(l3, 61u, l4, 494u);
    vader_c_emit_line(l0, l4);
    vader_struct_vader_c_emit_StackTmp_t* _a0_obj = (vader_struct_vader_c_emit_StackTmp_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_StackTmp_t));
    vader_obj_header_init(_a0_obj, 674u);
    _a0_obj->f_name = l3;
    _a0_obj->f_val = l2;
    t0 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
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
    l3 = (size_t) (int64_t) INT64_C(0);
    {
        loop_6: {
            if ((l3 < l2)) {
                vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_stack);
                if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                l4 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
                t0 = vader_c_emit_entry_needs_materialise(l4, l1);
                if (t0) {
                    l5 = ((vader_struct_vader_c_emit_FnState_t*) l0)->f_stack;
                    l6 = vader_c_emit_materialise_entry(l0, l4);
                    vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
                    if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                    if ((size_t) l3 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                    vader_array_ref_store(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l3, l6.payload.obj);
                    VADER_WRITE_BARRIER(_a1_slotarr->buf);
                } else {
                }
                t1 = (l3 + INT64_C(1));
                l3 = (size_t) (int64_t) t1;
                goto loop_6;
            } else {
            }
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static int32_t vader_c_emit_max_fn_arity(void* l0) {
    int32_t l1, l4;
    size_t l2, l3;
    vader_box_t t0;
    void* t1;
    size_t t2;
    int64_t t3;
    l1 = INT32_C(0);
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    l2 = ((vader_array_t*) l0)->length;
    l3 = (size_t) (int64_t) INT64_C(0);
    {
        loop_8: {
            if ((l3 < l2)) {
                if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
                if (t0.tag == 499u) {
                    vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
                    if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                    if ((size_t) l3 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                    t0 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l3);
                    t1 = t0.payload.obj;
                    t2 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFn_t*) t1)->f_params)->length;
                    l4 = ((int32_t) (size_t) t2);
                    if ((l4 > l1)) {
                        l1 = l4;
                    } else {
                    }
                } else {
                }
                t3 = (l3 + INT64_C(1));
                l3 = (size_t) (int64_t) t3;
                goto loop_8;
            } else {
            }
        }
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
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
    l5 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
    if (l5.tag == 509u) {
        t1 = l5.payload.obj;
        t2 = ((vader_struct_vader_bytecode_BcStruct_t*) t1)->f_c_name;
        return t2;
    }
    return 0u;
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
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l1 = std_string_index_of(l0, 36u, (size_t) (int64_t) INT64_C(0));
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
    vader_gc_top = gc_frame.prev;
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
    vader_array_t* _a0_arr = vader_array_new(15u, 0u, 4u, 177u);
    l1 = (void*) _a0_arr;
    l2 = ((vader_array_t*) l0)->length;
    l3 = (size_t) (int64_t) INT64_C(0);
    {
        loop_8: {
            if ((l3 < l2)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l3 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l3);
                t1 = vader_c_emit_data_entry_mutable(t0);
                if (t1) {
                    vader_array_push_i64((vader_array_t*) l1, (int64_t) (size_t) l3);
                } else {
                }
                t2 = (l3 + INT64_C(1));
                l3 = (size_t) (int64_t) t2;
                goto loop_8;
            } else {
            }
        }
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_string_t vader_c_emit_name_of(vader_box_t l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    size_t l3;
    int64_t l4;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    int32_t t2;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[3] = { &l1, &l2, &t0 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    if (l0.tag == 674u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_c_emit_StackTmp_t*) t0)->f_name;
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 671u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_c_emit_StackLit_t*) t0)->f_text;
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 672u) {
        l1 = l0.payload.obj;
        l2 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(21));
        l3 = (size_t) (int64_t) INT64_C(0);
        l3 = std_core_write_string_at(l2, l3, 1796u);
        t2 = ((vader_struct_vader_c_emit_StackLocalRef_t*) l1)->f_slot;
        l4 = ((int64_t) (int32_t) t2);
        l3 = std_core_write_int(l2, l3, l4);
        t1 = std_core_finish_buffer(l2, l3);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 670u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_c_emit_StackExpr_t*) t0)->f_text;
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_unreachable("unreachable return in vader_c_emit$name_of");
    vader_gc_top = gc_frame.prev;
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
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(9u, 0u, 7u, 170u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(6u, 0u, 12u, 165u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 170u);
    l3 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__i32__bool_t* _a3_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
    vader_obj_header_init(_a3_obj, 309u);
    _a3_obj->f_ekeys = l1;
    _a3_obj->f_evals = l2;
    _a3_obj->f_index = l3;
    _a3_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    t0 = (void*) _a3_obj;
    vader_struct_std_collections_MutableSet__i32_t* _a4_obj = (vader_struct_std_collections_MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i32_t));
    vader_obj_header_init(_a4_obj, 376u);
    _a4_obj->f_inner = t0;
    l1 = (void*) _a4_obj;
    l2 = l0;
    l4 = ((vader_array_t*) l2)->length;
    l5 = (size_t) (int64_t) INT64_C(0);
    {
        loop_22: {
            if ((l5 < l4)) {
                vader_array_t* _a5_slotarr = ((vader_array_t*) l2);
                if (_a5_slotarr->buf != NULL && _a5_slotarr->buf->header.forward != NULL) { _a5_slotarr->buf = vader_array_buf_forward(_a5_slotarr->buf); }
                if ((size_t) l5 >= _a5_slotarr->length) { vader_trap("array index out of bounds"); }
                l6 = vader_array_ref_load_box(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l5);
                if (!(l6.tag == 509u)) {
                    t1 = (l5 + INT64_C(1));
                    l5 = (size_t) (int64_t) t1;
                    goto loop_22;
                }
                t0 = l6.payload.obj;
                t2 = ((vader_struct_vader_bytecode_BcStruct_t*) t0)->f_c_name;
                if (t2 == 0u) {
                    t1 = (l5 + INT64_C(1));
                    l5 = (size_t) (int64_t) t1;
                    goto loop_22;
                }
                t0 = l6.payload.obj;
                l3 = ((vader_struct_vader_bytecode_BcStruct_t*) t0)->f_fields;
                l7 = ((vader_array_t*) l3)->length;
                l8 = (size_t) (int64_t) INT64_C(0);
                {
                    loop_62: {
                        if ((l8 < l7)) {
                            vader_array_t* _a6_slotarr = ((vader_array_t*) l3);
                            if (_a6_slotarr->buf != NULL && _a6_slotarr->buf->header.forward != NULL) { _a6_slotarr->buf = vader_array_buf_forward(_a6_slotarr->buf); }
                            if ((size_t) l8 >= _a6_slotarr->length) { vader_trap("array index out of bounds"); }
                            l9 = vader_array_ref_load_obj(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l8);
                            t3 = vader_bytecode_nested_mirror(l9, l0);
                            if (!(t3.tag == 0u)) {
                                l10 = ((vader_struct_vader_bytecode_BcField_t*) l9)->f_type_index;
                                std_collections_add__i32(l1, l10);
                            } else {
                            }
                            t1 = (l8 + INT64_C(1));
                            l8 = (size_t) (int64_t) t1;
                            goto loop_62;
                        } else {
                        }
                    }
                }
                t1 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t1;
                goto loop_22;
            } else {
            }
        }
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_c_emit_new_ctx(void* l0, bool l1, bool l2, void* l3, void* l4) {
    void* l5 = NULL;
    void* l11 = NULL;
    void* l12 = NULL;
    void* l15 = NULL;
    size_t l6, l7;
    vader_box_t l8 = vader_box_null();
    vader_string_t l9 = 0;
    int32_t l10, l13, l14;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    int64_t t2;
    vader_box_t* gc_roots[1] = { &l8 };
    void** gc_raw_roots[8] = { &l0, &l3, &l4, &l5, &l11, &l12, &l15, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l9, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 167u);
    l5 = (void*) _a0_arr;
    l6 = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_types)->length;
    l7 = (size_t) (int64_t) INT64_C(0);
    {
        loop_8: {
            if ((l7 < l6)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_types);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l7 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                l8 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l7);
                if (l8.tag == 509u) {
                    t0 = l8.payload.obj;
                    t1 = ((vader_struct_vader_bytecode_BcStruct_t*) t0)->f_name;
                    l9 = vader_c_emit_struct_c_name(t1);
                    vader_array_push((vader_array_t*) l5, vader_box_string(167u, l9));
                } else {
                    vader_array_push((vader_array_t*) l5, vader_box_string(167u, 0u));
                }
                t2 = (l7 + INT64_C(1));
                l7 = (size_t) (int64_t) t2;
                goto loop_8;
            } else {
            }
        }
    }
    l10 = vader_c_emit_string_primitive_tag(((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_types);
    l11 = vader_c_emit_compute_atom_ids(((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_strings, l3);
    l12 = vader_c_emit_atom_table_of(((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_strings, l3);
    l13 = vader_c_emit_null_primitive_tag(((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_types);
    l14 = vader_c_emit_string_array_tag(((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_types, l10);
    l15 = vader_c_emit_compute_may_alloc(((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_functions);
    vader_struct_vader_c_emit_EmitCtx_t* _a2_obj = (vader_struct_vader_c_emit_EmitCtx_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_EmitCtx_t));
    vader_obj_header_init(_a2_obj, 663u);
    _a2_obj->f_module = l0;
    _a2_obj->f_struct_c_names = l5;
    _a2_obj->f_atom_ids = l11;
    _a2_obj->f_atom_table = l12;
    _a2_obj->f_null_tag = l13;
    _a2_obj->f_string_tag = l10;
    _a2_obj->f_string_array_tag = l14;
    _a2_obj->f_may_alloc = l15;
    _a2_obj->f_release = l1;
    _a2_obj->f_split = l2;
    _a2_obj->f_internal_fns = l4;
    t0 = (void*) _a2_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_c_emit_new_fn_state(void* l0, void* l1, void* l2) {
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
    vader_array_t* _a0_arr = vader_array_new(125u, 0u, 13u, 1121u);
    l3 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(11u, 0u, 1u, 173u);
    l4 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(45u, 0u, 13u, 667u);
    l5 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(9u, 0u, 7u, 170u);
    l6 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_new(9u, 0u, 7u, 170u);
    l7 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_new(8u, 0u, 0u, 167u);
    l8 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(8u, 0u, 0u, 167u);
    l9 = (void*) _a6_arr;
    vader_array_t* _a7_arr = vader_array_new(9u, 0u, 7u, 170u);
    l10 = (void*) _a7_arr;
    vader_struct_std_collections_MutableMap__string__string_t* _a8_obj = (vader_struct_std_collections_MutableMap__string__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__string_t));
    vader_obj_header_init(_a8_obj, 361u);
    _a8_obj->f_ekeys = l8;
    _a8_obj->f_evals = l9;
    _a8_obj->f_index = l10;
    _a8_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a8_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a8_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l8 = (void*) _a8_obj;
    vader_array_t* _a9_arr = vader_array_new(8u, 0u, 0u, 167u);
    l9 = (void*) _a9_arr;
    vader_array_t* _a10_arr = vader_array_new(6u, 0u, 12u, 165u);
    l10 = (void*) _a10_arr;
    vader_array_t* _a11_arr = vader_array_new(9u, 0u, 7u, 170u);
    l11 = (void*) _a11_arr;
    vader_struct_std_collections_MutableMap__string__bool_t* _a12_obj = (vader_struct_std_collections_MutableMap__string__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__bool_t));
    vader_obj_header_init(_a12_obj, 357u);
    _a12_obj->f_ekeys = l9;
    _a12_obj->f_evals = l10;
    _a12_obj->f_index = l11;
    _a12_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a12_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a12_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    t0 = (void*) _a12_obj;
    vader_struct_std_collections_MutableSet__string_t* _a13_obj = (vader_struct_std_collections_MutableSet__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__string_t));
    vader_obj_header_init(_a13_obj, 378u);
    _a13_obj->f_inner = t0;
    l9 = (void*) _a13_obj;
    vader_array_t* _a14_arr = vader_array_new(46u, 0u, 13u, 673u);
    l10 = (void*) _a14_arr;
    vader_struct_vader_c_emit_FnState_t* _a15_obj = (vader_struct_vader_c_emit_FnState_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_FnState_t));
    vader_obj_header_init(_a15_obj, 665u);
    _a15_obj->f_ctx = l0;
    _a15_obj->f_function = l1;
    _a15_obj->f_out = l2;
    _a15_obj->f_stack = l3;
    _a15_obj->f_tmp_types = l4;
    _a15_obj->f_aux_counter = INT32_C(0);
    _a15_obj->f_indent = INT32_C(1);
    _a15_obj->f_scopes = l5;
    _a15_obj->f_continue_targets = l6;
    _a15_obj->f_break_targets = l7;
    _a15_obj->f_no_frame = true;
    _a15_obj->f_resolved_arrays = l8;
    _a15_obj->f_pinned_resolves = l9;
    _a15_obj->f_drop_call_result = false;
    _a15_obj->f_stack_storages = l10;
    t0 = (void*) _a15_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_c_emit_no_slot(size_t l0) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_c_emit_SlotToken_t* _a0_obj = (vader_struct_vader_c_emit_SlotToken_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_SlotToken_t));
    vader_obj_header_init(_a0_obj, 669u);
    _a0_obj->f_ok = false;
    _a0_obj->f_id = (size_t) (int64_t) INT64_C(0);
    _a0_obj->f_end = l0;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static int32_t vader_c_emit_null_primitive_tag(void* l0) {
    size_t l1, l2, l4;
    vader_box_t l3;
    void* t0;
    int64_t t1;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    l1 = ((vader_array_t*) l0)->length;
    l2 = (size_t) (int64_t) INT64_C(0);
    {
        loop_6: {
            if ((l2 < l1)) {
                if ((size_t) l2 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                l3 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
                if (l3.tag == 505u) {
                    t0 = l3.payload.obj;
                    if (((vader_struct_vader_bytecode_BcPrimitive_t*) t0)->f_val == INT32_C(15)) {
                        return ((int32_t) (size_t) l2);
                    }
                    l4 = (size_t) (int64_t) INT64_C(1);
                    t1 = (l2 + l4);
                    l2 = (size_t) (int64_t) t1;
                    goto loop_6;
                }
                l4 = (size_t) (int64_t) INT64_C(1);
                t1 = (l2 + l4);
                l2 = (size_t) (int64_t) t1;
                goto loop_6;
            } else {
            }
        }
    }
    return INT32_C(0);
}

static vader_string_t vader_c_emit_obj_ptr_expr(vader_string_t l0, uint8_t l1) {
    vader_string_t l2 = 0;
    vader_string_t* gc_atom_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    if (l1 == INT32_C(18)) {
        l2 = l0;
    } else {
        l2 = concat_2(l0, 421u);
    }
    { vader_string_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_string_t vader_c_emit_obj_ptr_of(vader_box_t l0) {
    vader_string_t l1 = 0;
    uint8_t l2;
    vader_string_t t0 = 0;
    vader_box_t* gc_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[2] = { &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 0u, gc_roots, NULL, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l1 = vader_c_emit_name_of(l0);
    l2 = vader_c_emit_val_of(l0);
    t0 = vader_c_emit_obj_ptr_expr(l1, l2);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_string_t vader_c_emit_one_variant_check(void* l0, vader_string_t l1, int32_t l2) {
    void* l3 = NULL;
    void* l6 = NULL;
    void* l10 = NULL;
    size_t l4, l9, l11;
    vader_box_t l5 = vader_box_null();
    vader_string_t l7 = 0;
    vader_string_t l8 = 0;
    vader_string_t l12 = 0;
    vader_string_t l14 = 0;
    int64_t l13;
    int64_t t0;
    vader_string_t t1 = 0;
    void* t2 = NULL;
    bool t3;
    vader_box_t* gc_roots[1] = { &l5 };
    void** gc_raw_roots[5] = { &l0, &l3, &l6, &l10, &t2 };
    vader_string_t* gc_atom_roots[6] = { &l1, &l7, &l8, &l12, &l14, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 6u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_ctx)->f_module)->f_types;
    t0 = ((int64_t) (int32_t) l2);
    l4 = (size_t) (int64_t) t0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    if ((size_t) l4 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
    l5 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
    if (l5.tag == 506u) {
        l3 = l5.payload.obj;
        t1 = ((vader_struct_vader_bytecode_BcRef_t*) l3)->f_trait_name;
        if (t1 != 0u) {
            l6 = ((vader_struct_vader_c_emit_FnState_t*) l0)->f_ctx;
            l7 = ((vader_struct_vader_bytecode_BcRef_t*) l3)->f_trait_name;
            t1 = vader_c_emit_trait_check_expr(l6, l1, l7, l2);
            { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l5.tag == 509u) {
            l3 = l5.payload.obj;
            l6 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_ctx)->f_module)->f_types;
            l7 = ((vader_struct_vader_bytecode_BcStruct_t*) l3)->f_name;
            t1 = vader_c_emit_struct_check_expr(l6, l1, l2, l7);
            { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l5.tag == 505u) {
            t2 = l5.payload.obj;
            t3 = vader_bytecode_is_float_val(((vader_struct_vader_bytecode_BcPrimitive_t*) t2)->f_val);
            if (t3) {
                t1 = vader_c_emit_float_tag_check_expr(((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_ctx)->f_module)->f_types, l1);
                { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
            }
            l8 = l1;
            l4 = (size_t) (int64_t) INT64_C(25);
            l9 = vader_host_std_core_byte_len(l8);
            l10 = std_core_new_byte_buffer((size_t) (int64_t) (l4 + l9));
            l11 = (size_t) (int64_t) INT64_C(0);
            l11 = std_core_write_string_at(l10, l11, l8);
            l12 = 90u;
            l11 = std_core_write_string_at(l10, l11, l12);
            l13 = ((int64_t) (int32_t) l2);
            l11 = std_core_write_int(l10, l11, l13);
            l14 = 2198u;
            l11 = std_core_write_string_at(l10, l11, l14);
            t1 = std_core_finish_buffer(l10, l11);
            { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l8 = l1;
        l4 = (size_t) (int64_t) INT64_C(25);
        l9 = vader_host_std_core_byte_len(l8);
        l10 = std_core_new_byte_buffer((size_t) (int64_t) (l4 + l9));
        l11 = (size_t) (int64_t) INT64_C(0);
        l11 = std_core_write_string_at(l10, l11, l8);
        l12 = 90u;
        l11 = std_core_write_string_at(l10, l11, l12);
        l13 = ((int64_t) (int32_t) l2);
        l11 = std_core_write_int(l10, l11, l13);
        l14 = 2198u;
        l11 = std_core_write_string_at(l10, l11, l14);
        t1 = std_core_finish_buffer(l10, l11);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l5.tag == 509u) {
        l3 = l5.payload.obj;
        l6 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_ctx)->f_module)->f_types;
        l7 = ((vader_struct_vader_bytecode_BcStruct_t*) l3)->f_name;
        t1 = vader_c_emit_struct_check_expr(l6, l1, l2, l7);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l5.tag == 505u) {
        t2 = l5.payload.obj;
        t3 = vader_bytecode_is_float_val(((vader_struct_vader_bytecode_BcPrimitive_t*) t2)->f_val);
        if (t3) {
            t1 = vader_c_emit_float_tag_check_expr(((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_ctx)->f_module)->f_types, l1);
            { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l8 = l1;
        l4 = (size_t) (int64_t) INT64_C(25);
        l9 = vader_host_std_core_byte_len(l8);
        l10 = std_core_new_byte_buffer((size_t) (int64_t) (l4 + l9));
        l11 = (size_t) (int64_t) INT64_C(0);
        l11 = std_core_write_string_at(l10, l11, l8);
        l12 = 90u;
        l11 = std_core_write_string_at(l10, l11, l12);
        l13 = ((int64_t) (int32_t) l2);
        l11 = std_core_write_int(l10, l11, l13);
        l14 = 2198u;
        l11 = std_core_write_string_at(l10, l11, l14);
        t1 = std_core_finish_buffer(l10, l11);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l8 = l1;
    l4 = (size_t) (int64_t) INT64_C(25);
    l9 = vader_host_std_core_byte_len(l8);
    l10 = std_core_new_byte_buffer((size_t) (int64_t) (l4 + l9));
    l11 = (size_t) (int64_t) INT64_C(0);
    l11 = std_core_write_string_at(l10, l11, l8);
    l12 = 90u;
    l11 = std_core_write_string_at(l10, l11, l12);
    l13 = ((int64_t) (int32_t) l2);
    l11 = std_core_write_int(l10, l11, l13);
    l14 = 2198u;
    l11 = std_core_write_string_at(l10, l11, l14);
    t1 = std_core_finish_buffer(l10, l11);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static bool vader_c_emit_op_allocates(vader_box_t l0) {
    void* t0;
    bool t1;
    if (l0.tag == 638u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_bytecode_StructNew_t*) t0)->f_stack;
        return !(t1);
    }
    if ((l0.tag == 488u || l0.tag == 489u || l0.tag == 490u || l0.tag == 492u || l0.tag == 494u || l0.tag == 527u || l0.tag == 528u || l0.tag == 533u || l0.tag == 534u || l0.tag == 616u || l0.tag == 636u || l0.tag == 655u)) {
        return true;
    }
    if ((l0.tag == 484u || l0.tag == 485u || l0.tag == 486u || l0.tag == 487u || l0.tag == 491u || l0.tag == 493u || l0.tag == 515u || l0.tag == 516u || l0.tag == 517u || l0.tag == 518u || l0.tag == 519u || l0.tag == 520u || l0.tag == 521u || l0.tag == 522u || l0.tag == 523u || l0.tag == 524u || l0.tag == 525u || l0.tag == 526u || l0.tag == 529u || l0.tag == 532u || l0.tag == 535u || l0.tag == 536u || l0.tag == 537u || l0.tag == 539u || l0.tag == 540u || l0.tag == 541u || l0.tag == 542u || l0.tag == 545u || l0.tag == 546u || l0.tag == 547u || l0.tag == 548u || l0.tag == 549u || l0.tag == 550u || l0.tag == 551u || l0.tag == 552u || l0.tag == 553u || l0.tag == 554u || l0.tag == 555u || l0.tag == 556u || l0.tag == 557u || l0.tag == 558u || l0.tag == 559u || l0.tag == 560u || l0.tag == 561u || l0.tag == 562u || l0.tag == 563u || l0.tag == 564u || l0.tag == 565u || l0.tag == 566u || l0.tag == 567u || l0.tag == 568u || l0.tag == 569u || l0.tag == 570u || l0.tag == 571u || l0.tag == 572u || l0.tag == 573u || l0.tag == 574u || l0.tag == 575u || l0.tag == 576u || l0.tag == 577u || l0.tag == 578u || l0.tag == 579u || l0.tag == 580u || l0.tag == 581u || l0.tag == 582u || l0.tag == 583u || l0.tag == 584u || l0.tag == 585u || l0.tag == 586u || l0.tag == 587u || l0.tag == 588u || l0.tag == 589u || l0.tag == 590u || l0.tag == 591u || l0.tag == 592u || l0.tag == 593u || l0.tag == 594u || l0.tag == 595u || l0.tag == 596u || l0.tag == 597u || l0.tag == 598u || l0.tag == 599u || l0.tag == 600u || l0.tag == 601u || l0.tag == 602u || l0.tag == 604u || l0.tag == 605u || l0.tag == 606u || l0.tag == 607u || l0.tag == 608u || l0.tag == 609u || l0.tag == 610u || l0.tag == 611u || l0.tag == 612u || l0.tag == 613u || l0.tag == 614u || l0.tag == 615u || l0.tag == 617u || l0.tag == 618u || l0.tag == 619u || l0.tag == 620u || l0.tag == 621u || l0.tag == 622u || l0.tag == 623u || l0.tag == 624u || l0.tag == 626u || l0.tag == 627u || l0.tag == 628u || l0.tag == 629u || l0.tag == 630u || l0.tag == 631u || l0.tag == 632u || l0.tag == 633u || l0.tag == 634u || l0.tag == 635u || l0.tag == 637u || l0.tag == 639u || l0.tag == 640u || l0.tag == 641u || l0.tag == 642u || l0.tag == 643u || l0.tag == 644u || l0.tag == 645u || l0.tag == 646u || l0.tag == 647u || l0.tag == 648u || l0.tag == 649u || l0.tag == 650u || l0.tag == 651u || l0.tag == 652u || l0.tag == 653u || l0.tag == 654u)) {
        return false;
    }
    vader_unreachable("unreachable return in vader_c_emit$op_allocates");
}

static void* vader_c_emit_order_by_first(void* l0, size_t l1) {
    vader_box_t l2 = vader_box_null();
    void* l3 = NULL;
    void* l5 = NULL;
    size_t l4;
    void* t0 = NULL;
    int32_t t1;
    int64_t t2;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[4] = { &l0, &l3, &l5, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct__Cell_Array_i32__t* _a0_obj = (vader_struct__Cell_Array_i32__t*) vader_gc_alloc(sizeof(vader_struct__Cell_Array_i32__t));
    vader_obj_header_init(_a0_obj, 184u);
    _a0_obj->f_value = l0;
    t0 = (void*) _a0_obj;
    l2 = vader_ref_box(t0);
    vader_array_t* _a1_arr = vader_array_new(15u, 0u, 4u, 177u);
    l3 = (void*) _a1_arr;
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_8: {
            if ((l4 < l1)) {
                vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct__Cell_Array_i32__t*) l2.payload.obj)->f_value);
                if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                if ((size_t) l4 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                t1 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l4];
                if ((t1 >= INT32_C(0))) {
                    vader_array_push_i64((vader_array_t*) l3, (int64_t) (size_t) l4);
                } else {
                }
                t2 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t2;
                goto loop_8;
            } else {
            }
        }
    }
    vader_struct___lambda_env_vader_c_emit_5_t* _a3_obj = (vader_struct___lambda_env_vader_c_emit_5_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_c_emit_5_t));
    vader_obj_header_init(_a3_obj, 244u);
    _a3_obj->f_cap_0 = l2;
    t0 = (void*) _a3_obj;
    vader_fn_t* _a4_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
    vader_obj_header_init(_a4_closure, 146u);
    _a4_closure->code = (void*) &vader_fn_lift___lambda_vader_c_emit_4;
    _a4_closure->env = t0;
    l5 = (void*) _a4_closure;
    t0 = std_sort_sort__usize(l3, l5);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
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
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    if ((size_t) l1 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
    t0 = vader_box_bool(165u, ((uint8_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l1]);
    t1 = t0.payload.b;
    return t1;
}

static void* vader_c_emit_parse_copy_line(vader_string_t l0) {
    void* l1 = NULL;
    void* l5 = NULL;
    void* l8 = NULL;
    size_t l2, l4, l6, l7;
    bool l3;
    vader_string_t l9 = 0;
    int64_t t0;
    vader_box_t t1 = vader_box_null();
    uint8_t t2;
    void* t3 = NULL;
    bool t4;
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[4] = { &l1, &l5, &l8, &t3 };
    vader_string_t* gc_atom_roots[2] = { &l0, &l9 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l1 = vader_host_std_core_bytes(l0);
    l2 = ((vader_array_t*) l1)->length;
    if (l2 == INT64_C(0)) {
        l3 = true;
    } else {
        t0 = (l2 - INT64_C(1));
        l4 = (size_t) (int64_t) t0;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
        if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
        if ((size_t) l4 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
        t1 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l4, 173u);
        t2 = ((uint8_t) t1.payload.i);
        l3 = t2 != INT32_C(59);
    }
    if (l3) {
        vader_struct_vader_c_emit_CopyLine_t* _a1_obj = (vader_struct_vader_c_emit_CopyLine_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_CopyLine_t));
        vader_obj_header_init(_a1_obj, 661u);
        _a1_obj->f_ok = false;
        _a1_obj->f_id = (size_t) (int64_t) INT64_C(0);
        _a1_obj->f_local = 0u;
        t3 = (void*) _a1_obj;
        { void* __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = vader_c_emit_leading_spaces(l1, l2);
    l5 = vader_c_emit_slot_token_at(l1, l4, l2, (uint8_t) (int32_t) INT32_C(108));
    l6 = ((vader_struct_vader_c_emit_SlotToken_t*) l5)->f_end;
    t4 = ((vader_struct_vader_c_emit_SlotToken_t*) l5)->f_ok;
    if (!(t4)) {
        l3 = true;
    } else {
        l3 = ((l6 + INT64_C(3)) > l2);
    }
    if (l3) {
        l3 = true;
    } else {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l1);
        if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
        if ((size_t) l6 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
        t1 = vader_array_read_u8(_a2_slotarr, _a2_slotarr->offset + (size_t) l6, 173u);
        t2 = ((uint8_t) t1.payload.i);
        l3 = t2 != INT32_C(32);
    }
    if (l3) {
        l3 = true;
    } else {
        t0 = (l6 + INT64_C(1));
        l7 = (size_t) (int64_t) t0;
        vader_array_t* _a3_slotarr = ((vader_array_t*) l1);
        if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
        if ((size_t) l7 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
        t1 = vader_array_read_u8(_a3_slotarr, _a3_slotarr->offset + (size_t) l7, 173u);
        t2 = ((uint8_t) t1.payload.i);
        l3 = t2 != INT32_C(61);
    }
    if (l3) {
        l3 = true;
    } else {
        t0 = (l6 + INT64_C(2));
        l7 = (size_t) (int64_t) t0;
        vader_array_t* _a4_slotarr = ((vader_array_t*) l1);
        if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
        if ((size_t) l7 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
        t1 = vader_array_read_u8(_a4_slotarr, _a4_slotarr->offset + (size_t) l7, 173u);
        t2 = ((uint8_t) t1.payload.i);
        l3 = t2 != INT32_C(32);
    }
    if (l3) {
        vader_struct_vader_c_emit_CopyLine_t* _a5_obj = (vader_struct_vader_c_emit_CopyLine_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_CopyLine_t));
        vader_obj_header_init(_a5_obj, 661u);
        _a5_obj->f_ok = false;
        _a5_obj->f_id = (size_t) (int64_t) INT64_C(0);
        _a5_obj->f_local = 0u;
        t3 = (void*) _a5_obj;
        { void* __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = (l6 + INT64_C(3));
    l6 = (size_t) (int64_t) t0;
    l8 = vader_c_emit_slot_token_at(l1, l6, l2, (uint8_t) (int32_t) INT32_C(116));
    t4 = ((vader_struct_vader_c_emit_SlotToken_t*) l8)->f_ok;
    if (!(t4)) {
        l3 = true;
    } else {
        l6 = ((vader_struct_vader_c_emit_SlotToken_t*) l8)->f_end;
        t0 = (l2 - INT64_C(1));
        l2 = (size_t) (int64_t) t0;
        l3 = l6 != l2;
    }
    if (l3) {
        vader_struct_vader_c_emit_CopyLine_t* _a6_obj = (vader_struct_vader_c_emit_CopyLine_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_CopyLine_t));
        vader_obj_header_init(_a6_obj, 661u);
        _a6_obj->f_ok = false;
        _a6_obj->f_id = (size_t) (int64_t) INT64_C(0);
        _a6_obj->f_local = 0u;
        t3 = (void*) _a6_obj;
        { void* __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = ((vader_struct_vader_c_emit_SlotToken_t*) l8)->f_id;
    l6 = ((vader_struct_vader_c_emit_SlotToken_t*) l5)->f_end;
    vader_array_t* _a7_arr = vader_array_slice((vader_array_t*) l1, (size_t) l4, (size_t) l6);
    t3 = (void*) _a7_arr;
    l9 = vader_host_std_core_bytes_to_string(t3);
    vader_struct_vader_c_emit_CopyLine_t* _a8_obj = (vader_struct_vader_c_emit_CopyLine_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_CopyLine_t));
    vader_obj_header_init(_a8_obj, 661u);
    _a8_obj->f_ok = true;
    _a8_obj->f_id = l2;
    _a8_obj->f_local = l9;
    t3 = (void*) _a8_obj;
    { void* __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_c_emit_parse_def_line(vader_string_t l0) {
    void* l1 = NULL;
    void* l5 = NULL;
    size_t l2, l4, l6, l7;
    bool l3;
    vader_string_t l8 = 0;
    vader_string_t l9 = 0;
    int64_t t0;
    vader_box_t t1 = vader_box_null();
    uint8_t t2;
    int32_t t3;
    void* t4 = NULL;
    bool t5;
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[3] = { &l1, &l5, &t4 };
    vader_string_t* gc_atom_roots[3] = { &l0, &l8, &l9 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l1 = vader_host_std_core_bytes(l0);
    l2 = ((vader_array_t*) l1)->length;
    if (l2 == INT64_C(0)) {
        l3 = true;
    } else {
        t0 = (l2 - INT64_C(1));
        l4 = (size_t) (int64_t) t0;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
        if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
        if ((size_t) l4 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
        t1 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l4, 173u);
        t2 = ((uint8_t) t1.payload.i);
        l3 = t2 != INT32_C(59);
    }
    if (l3) {
        l3 = true;
    } else {
        t3 = vader_c_emit_count_byte(l1, l2, (uint8_t) (int32_t) INT32_C(59));
        l3 = t3 != INT32_C(1);
    }
    if (l3) {
        vader_struct_vader_c_emit_DefLine_t* _a1_obj = (vader_struct_vader_c_emit_DefLine_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_DefLine_t));
        vader_obj_header_init(_a1_obj, 662u);
        _a1_obj->f_ok = false;
        _a1_obj->f_id = (size_t) (int64_t) INT64_C(0);
        _a1_obj->f_indent = 0u;
        _a1_obj->f_expr = 0u;
        t4 = (void*) _a1_obj;
        { void* __vret = t4; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = vader_c_emit_leading_spaces(l1, l2);
    l5 = vader_c_emit_slot_token_at(l1, l4, l2, (uint8_t) (int32_t) INT32_C(116));
    l6 = ((vader_struct_vader_c_emit_SlotToken_t*) l5)->f_end;
    t5 = ((vader_struct_vader_c_emit_SlotToken_t*) l5)->f_ok;
    if (!(t5)) {
        l3 = true;
    } else {
        l3 = ((l6 + INT64_C(3)) > l2);
    }
    if (l3) {
        l3 = true;
    } else {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l1);
        if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
        if ((size_t) l6 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
        t1 = vader_array_read_u8(_a2_slotarr, _a2_slotarr->offset + (size_t) l6, 173u);
        t2 = ((uint8_t) t1.payload.i);
        l3 = t2 != INT32_C(32);
    }
    if (l3) {
        l3 = true;
    } else {
        t0 = (l6 + INT64_C(1));
        l7 = (size_t) (int64_t) t0;
        vader_array_t* _a3_slotarr = ((vader_array_t*) l1);
        if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
        if ((size_t) l7 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
        t1 = vader_array_read_u8(_a3_slotarr, _a3_slotarr->offset + (size_t) l7, 173u);
        t2 = ((uint8_t) t1.payload.i);
        l3 = t2 != INT32_C(61);
    }
    if (l3) {
        l3 = true;
    } else {
        t0 = (l6 + INT64_C(2));
        l7 = (size_t) (int64_t) t0;
        vader_array_t* _a4_slotarr = ((vader_array_t*) l1);
        if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
        if ((size_t) l7 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
        t1 = vader_array_read_u8(_a4_slotarr, _a4_slotarr->offset + (size_t) l7, 173u);
        t2 = ((uint8_t) t1.payload.i);
        l3 = t2 != INT32_C(32);
    }
    if (l3) {
        vader_struct_vader_c_emit_DefLine_t* _a5_obj = (vader_struct_vader_c_emit_DefLine_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_DefLine_t));
        vader_obj_header_init(_a5_obj, 662u);
        _a5_obj->f_ok = false;
        _a5_obj->f_id = (size_t) (int64_t) INT64_C(0);
        _a5_obj->f_indent = 0u;
        _a5_obj->f_expr = 0u;
        t4 = (void*) _a5_obj;
        { void* __vret = t4; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l7 = ((vader_struct_vader_c_emit_SlotToken_t*) l5)->f_id;
    vader_array_t* _a6_arr = vader_array_slice((vader_array_t*) l1, (size_t) INT64_C(0), (size_t) l4);
    t4 = (void*) _a6_arr;
    l8 = vader_host_std_core_bytes_to_string(t4);
    t0 = (l6 + INT64_C(3));
    l4 = (size_t) (int64_t) t0;
    t0 = (l2 - INT64_C(1));
    l2 = (size_t) (int64_t) t0;
    vader_array_t* _a7_arr = vader_array_slice((vader_array_t*) l1, (size_t) l4, (size_t) l2);
    t4 = (void*) _a7_arr;
    l9 = vader_host_std_core_bytes_to_string(t4);
    vader_struct_vader_c_emit_DefLine_t* _a8_obj = (vader_struct_vader_c_emit_DefLine_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_DefLine_t));
    vader_obj_header_init(_a8_obj, 662u);
    _a8_obj->f_ok = true;
    _a8_obj->f_id = l7;
    _a8_obj->f_indent = l8;
    _a8_obj->f_expr = l9;
    t4 = (void*) _a8_obj;
    { void* __vret = t4; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
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
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 167u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(16u, 0u, 0u, 178u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 170u);
    l3 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__string__Any___t* _a3_obj = (vader_struct_std_collections_MutableMap__string__Any___t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__Any___t));
    vader_obj_header_init(_a3_obj, 321u);
    _a3_obj->f_ekeys = l1;
    _a3_obj->f_evals = l2;
    _a3_obj->f_index = l3;
    _a3_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l1 = (void*) _a3_obj;
    l2 = vader_c_emit_sorted_fn_indices(l0);
    l4 = ((vader_array_t*) l2)->length;
    l5 = (size_t) (int64_t) INT64_C(0);
    {
        loop_22: {
            if ((l5 < l4)) {
                vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
                if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                if ((size_t) l5 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                l6 = ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l5];
                t0 = ((int64_t) (int32_t) l6);
                l7 = (size_t) (int64_t) t0;
                vader_array_t* _a5_slotarr = ((vader_array_t*) l0);
                if (_a5_slotarr->buf != NULL && _a5_slotarr->buf->header.forward != NULL) { _a5_slotarr->buf = vader_array_buf_forward(_a5_slotarr->buf); }
                if ((size_t) l7 >= _a5_slotarr->length) { vader_trap("array index out of bounds"); }
                t1 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l7);
                t2 = ((vader_struct_vader_bytecode_BcFunction_t*) t1)->f_name;
                l8 = vader_c_emit_module_stem_of(t2);
                l9 = std_collections_get__string__Any(l1, l8);
                if (l9.tag == 0u) {
                    vader_array_t* _a6_arr = vader_array_new(9u, 1u, 7u, 170u);
                    ((int32_t*) _a6_arr->buf->slots)[_a6_arr->offset + 0u] = (int32_t) l6;
                    l3 = (void*) _a6_arr;
                    std_collections_put__string__Any(l1, l8, vader_ref_box(l3));
                } else {
                    t1 = l9.payload.obj;
                    vader_array_push_i32((vader_array_t*) t1, l6);
                }
                t0 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t0;
                goto loop_22;
            } else {
            }
        }
    }
    vader_array_t* _a7_arr = vader_array_new(9u, 0u, 7u, 170u);
    t1 = (void*) _a7_arr;
    vader_array_t* _a8_arr = vader_array_new(2u, 1u, 13u, 9u);
    ((void**) _a8_arr->buf->slots)[_a8_arr->offset + 0u] = t1;
    l2 = (void*) _a8_arr;
    l3 = vader_c_emit_sorted_module_stems(l1);
    l4 = ((vader_array_t*) l3)->length;
    l5 = (size_t) (int64_t) INT64_C(0);
    {
        loop_79: {
            if ((l5 < l4)) {
                vader_array_t* _a9_slotarr = ((vader_array_t*) l3);
                if (_a9_slotarr->buf != NULL && _a9_slotarr->buf->header.forward != NULL) { _a9_slotarr->buf = vader_array_buf_forward(_a9_slotarr->buf); }
                if ((size_t) l5 >= _a9_slotarr->length) { vader_trap("array index out of bounds"); }
                t3 = vader_array_box_slots(_a9_slotarr->buf)[_a9_slotarr->offset + (size_t) l5];
                l8 = t3.payload.s;
                l9 = std_collections_get__string__Any(l1, l8);
                if (l9.tag == 0u) {
                    vader_array_t* _a10_arr = vader_array_new(9u, 0u, 7u, 170u);
                    l10 = (void*) _a10_arr;
                } else {
                    l10 = l9.payload.obj;
                }
                vader_array_push((vader_array_t*) l2, vader_ref_box(l10));
                t0 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t0;
                goto loop_79;
            } else {
            }
        }
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_box_t vader_c_emit_pop(void* l0) {
    size_t l1, l3;
    void* l2 = NULL;
    vader_box_t l4 = vader_box_null();
    void* t0 = NULL;
    int64_t t1;
    vader_box_t* gc_roots[1] = { &l4 };
    void** gc_raw_roots[3] = { &l0, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = ((vader_array_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_stack)->length;
    if (l1 == INT64_C(0)) {
        vader_struct_vader_c_emit_StackLit_t* _a0_obj = (vader_struct_vader_c_emit_StackLit_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_StackLit_t));
        vader_obj_header_init(_a0_obj, 671u);
        _a0_obj->f_text = 445u;
        _a0_obj->f_val = (uint8_t) (int32_t) INT32_C(2);
        t0 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = ((vader_struct_vader_c_emit_FnState_t*) l0)->f_stack;
    t1 = (l1 - INT64_C(1));
    l3 = (size_t) (int64_t) t1;
    vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
    if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
    if ((size_t) l3 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
    l4 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l3);
    l2 = ((vader_struct_vader_c_emit_FnState_t*) l0)->f_stack;
    t1 = (l1 - INT64_C(1));
    l1 = (size_t) (int64_t) t1;
    vader_array_t* _a2_arr = vader_array_slice((vader_array_t*) l2, (size_t) INT64_C(0), (size_t) l1);
    l2 = (void*) _a2_arr;
    ((vader_struct_vader_c_emit_FnState_t*) l0)->f_stack = l2;
    VADER_WRITE_BARRIER((vader_struct_vader_c_emit_FnState_t*) l0);
    { vader_box_t __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_c_emit_pop_args_boxed(void* l0, int32_t l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    int32_t l4;
    vader_box_t l5 = vader_box_null();
    size_t l6;
    vader_string_t l7 = 0;
    vader_string_t l9 = 0;
    uint8_t l8;
    int64_t t0;
    vader_box_t* gc_roots[1] = { &l5 };
    void** gc_raw_roots[3] = { &l0, &l2, &l3 };
    vader_string_t* gc_atom_roots[2] = { &l7, &l9 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_ctx)->f_module)->f_types;
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 167u);
    l3 = (void*) _a0_arr;
    l4 = INT32_C(0);
    {
        loop_9: {
            if ((l4 < l1)) {
                vader_array_push((vader_array_t*) l3, vader_box_string(167u, 0u));
                l4 = (l4 + INT32_C(1));
                goto loop_9;
            } else {
            }
        }
    }
    l4 = INT32_C(0);
    {
        loop_29: {
            if ((l4 < l1)) {
                l5 = vader_c_emit_pop(l0);
                t0 = ((int64_t) (int32_t) ((l1 - INT32_C(1)) - l4));
                l6 = (size_t) (int64_t) t0;
                l7 = vader_c_emit_name_of(l5);
                l8 = vader_c_emit_val_of(l5);
                l9 = vader_c_emit_coerce_expr(l2, l7, l8, (uint8_t) (int32_t) INT32_C(19));
                vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l6 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l6] = vader_box_string(167u, l9);
                VADER_WRITE_BARRIER(_a1_slotarr->buf);
                l4 = (l4 + INT32_C(1));
                goto loop_29;
            } else {
            }
        }
    }
    { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_c_emit_precompute_branch_targets(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l12 = NULL;
    size_t l6, l7;
    vader_box_t l8 = vader_box_null(), l11 = vader_box_null();
    bool l9;
    int32_t l10, l13, l14, l15, l16;
    bool t0;
    int64_t t1;
    void* t2 = NULL;
    vader_box_t* gc_roots[2] = { &l8, &l11 };
    void** gc_raw_roots[8] = { &l0, &l1, &l2, &l3, &l4, &l5, &l12, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 8u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(9u, 0u, 7u, 170u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(9u, 0u, 7u, 170u);
    l3 = (void*) _a1_arr;
    l4 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_body;
    l5 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_jump_table;
    l6 = ((vader_array_t*) l4)->length;
    l7 = (size_t) (int64_t) INT64_C(0);
    {
        loop_14: {
            if ((l7 < l6)) {
                vader_array_t* _a2_slotarr = ((vader_array_t*) l4);
                if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                if ((size_t) l7 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                l8 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l7);
                if (l8.tag == 525u) {
                    l9 = true;
                } else {
                    l9 = l8.tag == 526u;
                }
                if (l9) {
                    vader_array_t* _a3_slotarr = ((vader_array_t*) l5);
                    if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                    if ((size_t) l7 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                    l10 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l7];
                    l11 = vader_c_emit_branch_target(l1, l10);
                    if (l11.tag == 667u) {
                        l12 = l11.payload.obj;
                        t0 = vader_c_emit_is_continue_branch(l12, l10);
                        if (t0) {
                            l13 = ((vader_struct_vader_c_emit_ScopeInfo_t*) l12)->f_opener_pc;
                            t0 = std_core____Contains_contains__i32(l2, l13);
                            if (!(t0)) {
                                l14 = ((vader_struct_vader_c_emit_ScopeInfo_t*) l12)->f_opener_pc;
                                vader_array_push_i32((vader_array_t*) l2, l14);
                            } else {
                            }
                        } else {
                            l15 = ((vader_struct_vader_c_emit_ScopeInfo_t*) l12)->f_opener_pc;
                            t0 = std_core____Contains_contains__i32(l3, l15);
                            if (!(t0)) {
                                l16 = ((vader_struct_vader_c_emit_ScopeInfo_t*) l12)->f_opener_pc;
                                vader_array_push_i32((vader_array_t*) l3, l16);
                            } else {
                            }
                        }
                    } else {
                    }
                } else {
                }
                t1 = (l7 + INT64_C(1));
                l7 = (size_t) (int64_t) t1;
                goto loop_14;
            } else {
            }
        }
    }
    vader_struct_vader_c_emit_BranchTargets_t* _a4_obj = (vader_struct_vader_c_emit_BranchTargets_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_BranchTargets_t));
    vader_obj_header_init(_a4_obj, 658u);
    _a4_obj->f_continue_targets = l2;
    _a4_obj->f_break_targets = l3;
    t2 = (void*) _a4_obj;
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
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
    vader_array_t* _a0_arr = vader_array_new(45u, 0u, 13u, 667u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(9u, 0u, 7u, 170u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(11u, 0u, 1u, 173u);
    l3 = (void*) _a2_arr;
    l4 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_body;
    l5 = ((vader_array_t*) l4)->length;
    l6 = (size_t) (int64_t) INT64_C(0);
    {
        loop_13: {
            if ((l6 < l5)) {
                vader_array_t* _a3_slotarr = ((vader_array_t*) l4);
                if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                if ((size_t) l6 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                l7 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l6);
                if (l7.tag == 517u) {
                    l8 = ((int32_t) (size_t) l6);
                    vader_array_push_i32((vader_array_t*) l2, l8);
                    vader_array_push_u8((vader_array_t*) l3, INT32_C(0));
                } else {
                    if (l7.tag == 615u) {
                        l9 = ((int32_t) (size_t) l6);
                        vader_array_push_i32((vader_array_t*) l2, l9);
                        vader_array_push_u8((vader_array_t*) l3, INT32_C(1));
                    } else {
                        if (l7.tag == 602u) {
                            l10 = ((int32_t) (size_t) l6);
                            vader_array_push_i32((vader_array_t*) l2, l10);
                            vader_array_push_u8((vader_array_t*) l3, INT32_C(2));
                        } else {
                            if (l7.tag == 545u) {
                                l11 = ((vader_array_t*) l2)->length;
                                if ((l11 > INT64_C(0))) {
                                    t0 = (l11 - INT64_C(1));
                                    l12 = (size_t) (int64_t) t0;
                                    vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
                                    if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                                    if ((size_t) l12 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                                    l13 = ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l12];
                                    t0 = (l11 - INT64_C(1));
                                    l14 = (size_t) (int64_t) t0;
                                    vader_array_t* _a5_slotarr = ((vader_array_t*) l3);
                                    if (_a5_slotarr->buf != NULL && _a5_slotarr->buf->header.forward != NULL) { _a5_slotarr->buf = vader_array_buf_forward(_a5_slotarr->buf); }
                                    if ((size_t) l14 >= _a5_slotarr->length) { vader_trap("array index out of bounds"); }
                                    t1 = vader_array_read_u8(_a5_slotarr, _a5_slotarr->offset + (size_t) l14, 173u);
                                    l15 = ((uint8_t) t1.payload.i);
                                    l16 = ((int32_t) (size_t) l6);
                                    vader_struct_vader_c_emit_ScopeInfo_t* _a6_obj = (vader_struct_vader_c_emit_ScopeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_ScopeInfo_t));
                                    vader_obj_header_init(_a6_obj, 667u);
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
                                } else {
                                }
                            } else {
                            }
                        }
                    }
                }
                t0 = (l6 + INT64_C(1));
                l6 = (size_t) (int64_t) t0;
                goto loop_13;
            } else {
            }
        }
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static int32_t vader_c_emit_prim_tag(void* l0, uint8_t l1) {
    size_t l2, l3, l5;
    vader_box_t l4;
    void* t0;
    int64_t t1;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    l2 = ((vader_array_t*) l0)->length;
    l3 = (size_t) (int64_t) INT64_C(0);
    {
        loop_6: {
            if ((l3 < l2)) {
                if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                l4 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
                if (l4.tag == 505u) {
                    t0 = l4.payload.obj;
                    if (((vader_struct_vader_bytecode_BcPrimitive_t*) t0)->f_val == l1) {
                        return ((int32_t) (size_t) l3);
                    }
                    l5 = (size_t) (int64_t) INT64_C(1);
                    t1 = (l3 + l5);
                    l3 = (size_t) (int64_t) t1;
                    goto loop_6;
                }
                l5 = (size_t) (int64_t) INT64_C(1);
                t1 = (l3 + l5);
                l3 = (size_t) (int64_t) t1;
                goto loop_6;
            } else {
            }
        }
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
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
    l4 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
    if (l4.tag == 505u) {
        t1 = l4.payload.obj;
        return ((vader_struct_vader_bytecode_BcPrimitive_t*) t1)->f_val == l1;
    }
    return false;
}

static int32_t vader_c_emit_primitive_tag_of(void* l0, uint8_t l1) {
    size_t l2, l3, l5;
    vader_box_t l4;
    void* t0;
    int64_t t1;
    bool t2;
    vader_box_t t3;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    l2 = ((vader_array_t*) l0)->length;
    l3 = (size_t) (int64_t) INT64_C(0);
    {
        loop_6: {
            if ((l3 < l2)) {
                if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                l4 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
                if (l4.tag == 505u) {
                    t0 = l4.payload.obj;
                    if (((vader_struct_vader_bytecode_BcPrimitive_t*) t0)->f_val == l1) {
                        return ((int32_t) (size_t) l3);
                    }
                    l5 = (size_t) (int64_t) INT64_C(1);
                    t1 = (l3 + l5);
                    l3 = (size_t) (int64_t) t1;
                    goto loop_6;
                }
                l5 = (size_t) (int64_t) INT64_C(1);
                t1 = (l3 + l5);
                l3 = (size_t) (int64_t) t1;
                goto loop_6;
            } else {
            }
        }
    }
    t2 = vader_bytecode_is_float_val(l1);
    if (t2) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
        if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
        l2 = ((vader_array_t*) l0)->length;
        l3 = (size_t) (int64_t) INT64_C(0);
        {
            loop_55: {
                if ((l3 < l2)) {
                    if ((size_t) l3 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                    t3 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l3);
                    if (t3.tag == 505u) {
                        vader_array_t* _a2_slotarr = ((vader_array_t*) l0);
                        if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                        if ((size_t) l3 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                        t3 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l3);
                        t0 = t3.payload.obj;
                        t2 = vader_bytecode_is_float_val(((vader_struct_vader_bytecode_BcPrimitive_t*) t0)->f_val);
                        if (t2) {
                            return ((int32_t) (size_t) l3);
                        }
                        l5 = (size_t) (int64_t) INT64_C(1);
                        t1 = (l3 + l5);
                        l3 = (size_t) (int64_t) t1;
                        goto loop_55;
                    }
                    l5 = (size_t) (int64_t) INT64_C(1);
                    t1 = (l3 + l5);
                    l3 = (size_t) (int64_t) t1;
                    goto loop_55;
                } else {
                }
            }
        }
        return INT32_C(0);
    }
    return INT32_C(0);
}

static void vader_c_emit_push_binop(void* l0, vader_string_t l1, uint8_t l2) {
    vader_string_t l3 = 0;
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[2] = { &l1, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l3 = vader_c_emit_binop_text(l0, l1, l2);
    vader_c_emit_push_expr(l0, l2, l3);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_c_emit_push_binop_any(void* l0, vader_string_t l1, uint8_t l2) {
    vader_box_t l3 = vader_box_null();
    vader_string_t l4 = 0;
    vader_string_t l5 = 0;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l3, &t0 };
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[3] = { &l1, &l4, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l3 = vader_c_emit_pop(l0);
    t0 = vader_c_emit_pop(l0);
    l4 = vader_c_emit_obj_ptr_of(t0);
    l5 = vader_c_emit_obj_ptr_of(l3);
    l4 = concat_5(l4, 6u, l1, 6u, l5);
    vader_c_emit_push_expr(l0, l2, l4);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_c_emit_push_cmp(void* l0, vader_string_t l1, uint8_t l2) {
    vader_string_t l3 = 0;
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[2] = { &l1, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l3 = vader_c_emit_binop_text(l0, l1, l2);
    vader_c_emit_push_expr(l0, (uint8_t) (int32_t) INT32_C(12), l3);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_c_emit_push_const(void* l0, vader_box_t l1) {
    uint8_t l2;
    vader_string_t l3 = 0;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[1] = { &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = vader_c_emit_const_val(l1);
    l3 = vader_c_emit_const_lit_c(((vader_struct_vader_c_emit_FnState_t*) l0)->f_ctx, l1);
    vader_c_emit_push_lit(l0, l2, l3);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_c_emit_push_eager(void* l0, vader_string_t l1, uint8_t l2) {
    vader_box_t l3 = vader_box_null(), l4 = vader_box_null();
    void* l5 = NULL;
    vader_string_t l6 = 0;
    vader_string_t l8 = 0;
    vader_string_t l9 = 0;
    uint8_t l7;
    vader_string_t t0 = 0;
    vader_box_t* gc_roots[2] = { &l3, &l4 };
    void** gc_raw_roots[2] = { &l0, &l5 };
    vader_string_t* gc_atom_roots[5] = { &l1, &l6, &l8, &l9, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 5u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l3 = vader_c_emit_pop(l0);
    l4 = vader_c_emit_pop(l0);
    l5 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_ctx)->f_module)->f_types;
    l6 = vader_c_emit_name_of(l4);
    l7 = vader_c_emit_val_of(l4);
    l6 = vader_c_emit_coerce_operand(l5, l6, l7, l2);
    l5 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_ctx)->f_module)->f_types;
    l8 = vader_c_emit_name_of(l3);
    l7 = vader_c_emit_val_of(l3);
    l8 = vader_c_emit_coerce_operand(l5, l8, l7, l2);
    l3 = vader_c_emit_div_mod_helper(l1, l2);
    if (l3.tag == 0u) {
        l9 = concat_5(l6, 6u, l1, 6u, l8);
        vader_c_emit_push_into_tmp(l0, l9, l2);
    } else {
        t0 = l3.payload.s;
        l6 = concat_6(t0, 278u, l6, 365u, l8, 318u);
        vader_c_emit_push_into_tmp(l0, l6, l2);
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_c_emit_push_expr(void* l0, uint8_t l1, vader_string_t l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void** gc_raw_roots[3] = { &l0, &l3, &l4 };
    vader_string_t* gc_atom_roots[1] = { &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_c_emit_FnState_t*) l0)->f_stack;
    vader_struct_vader_c_emit_StackExpr_t* _a0_obj = (vader_struct_vader_c_emit_StackExpr_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_StackExpr_t));
    vader_obj_header_init(_a0_obj, 670u);
    _a0_obj->f_text = l2;
    _a0_obj->f_val = l1;
    l4 = (void*) _a0_obj;
    vader_array_push((vader_array_t*) l3, vader_ref_box(l4));
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_c_emit_push_i64_neg(void* l0) {
    vader_box_t l1 = vader_box_null();
    void* l2 = NULL;
    vader_string_t l3 = 0;
    uint8_t l4;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_string_t* gc_atom_roots[1] = { &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l1 = vader_c_emit_pop(l0);
    l2 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_ctx)->f_module)->f_types;
    l3 = vader_c_emit_name_of(l1);
    l4 = vader_c_emit_val_of(l1);
    l3 = vader_c_emit_coerce_operand(l2, l3, l4, (uint8_t) (int32_t) INT32_C(3));
    if (l3 == 608u) {
        vader_c_emit_push_lit(l0, (uint8_t) (int32_t) INT32_C(3), 608u);
    } else {
        l3 = concat_3(383u, l3, 318u);
        vader_c_emit_push_expr(l0, (uint8_t) (int32_t) INT32_C(3), l3);
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_c_emit_push_into_tmp(void* l0, vader_string_t l1, uint8_t l2) {
    vader_string_t l3 = 0;
    vader_string_t l4 = 0;
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[3] = { &l1, &l3, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l3 = vader_c_emit_fresh_tmp(l0, l2);
    l4 = concat_4(l3, 61u, l1, 494u);
    vader_c_emit_line(l0, l4);
    vader_c_emit_push_tmp(l0, l3, l2);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_c_emit_push_leaf_asserts(void* l0, void* l1, vader_string_t l2, vader_string_t l3, vader_string_t l4, int64_t l5, void* l6, int32_t l7) {
    void* l8 = NULL;
    void* l11 = NULL;
    void* l17 = NULL;
    void* l34 = NULL;
    size_t l9, l10, l27, l28, l29, l30, l31, l32, l33, l35;
    vader_string_t l12 = 0;
    vader_string_t l13 = 0;
    vader_string_t l18 = 0;
    vader_string_t l19 = 0;
    vader_string_t l21 = 0;
    vader_string_t l22 = 0;
    vader_string_t l23 = 0;
    vader_string_t l24 = 0;
    vader_string_t l25 = 0;
    vader_string_t l26 = 0;
    vader_string_t l36 = 0;
    vader_string_t l38 = 0;
    int64_t l14, l15;
    vader_box_t l16 = vader_box_null(), l37 = vader_box_null();
    int32_t l20;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    int64_t t2;
    vader_box_t* gc_roots[2] = { &l16, &l37 };
    void** gc_raw_roots[8] = { &l0, &l1, &l6, &l8, &l11, &l17, &l34, &t0 };
    vader_string_t* gc_atom_roots[16] = { &l2, &l3, &l4, &l12, &l13, &l18, &l19, &l21, &l22, &l23, &l24, &l25, &l26, &l36, &l38, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 16u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    if ((l7 >= INT32_C(16))) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l8 = vader_bytecode_c_struct_layout(l1, l0);
    l9 = ((vader_array_t*) l1)->length;
    l10 = (size_t) (int64_t) INT64_C(0);
    {
        loop_16: {
            if ((l10 < l9)) {
                vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
                if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                if ((size_t) l10 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                l11 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l10);
                l12 = vader_c_emit_c_field_name(l11);
                l13 = concat_2(l3, l12);
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_CLayout_t*) l8)->f_offsets);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l10 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                l14 = ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l10];
                l15 = (l5 + l14);
                l16 = vader_bytecode_nested_mirror(l11, l0);
                if (!(l16.tag == 0u)) {
                    t0 = l16.payload.obj;
                    l17 = ((vader_struct_vader_bytecode_BcStruct_t*) t0)->f_fields;
                    l18 = concat_2(l13, 407u);
                    t0 = l16.payload.obj;
                    t1 = ((vader_struct_vader_bytecode_BcStruct_t*) t0)->f_name;
                    l19 = vader_c_emit_struct_c_name(t1);
                    l20 = (l7 + INT32_C(1));
                    vader_c_emit_push_leaf_asserts(l0, l17, l2, l18, l19, l15, l6, l20);
                    t2 = (l10 + INT64_C(1));
                    l10 = (size_t) (int64_t) t2;
                    goto loop_16;
                }
                l21 = ((vader_struct_vader_bytecode_BcField_t*) l11)->f_name;
                l22 = concat_13(878u, l2, 356u, l13, 324u, l4, 357u, l21, 345u, l2, 407u, l13, 226u);
                vader_array_push((vader_array_t*) l6, vader_box_string(167u, l22));
                l23 = l2;
                l24 = l13;
                l25 = l2;
                l26 = l13;
                l27 = vader_host_std_core_byte_len(l23);
                l28 = vader_host_std_core_byte_len(l24);
                t2 = (l27 + l28);
                l29 = (size_t) (int64_t) t2;
                l30 = vader_host_std_core_byte_len(l25);
                t2 = (l29 + l30);
                l31 = (size_t) (int64_t) t2;
                l32 = vader_host_std_core_byte_len(l26);
                t2 = (l31 + l32);
                l33 = (size_t) (int64_t) t2;
                l34 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(75) + l33));
                l35 = (size_t) (int64_t) INT64_C(0);
                l35 = std_core_write_string_at(l34, l35, 876u);
                l35 = std_core_write_string_at(l34, l35, l23);
                l35 = std_core_write_string_at(l34, l35, 365u);
                l35 = std_core_write_string_at(l34, l35, l24);
                l35 = std_core_write_string_at(l34, l35, 323u);
                l35 = std_core_write_int(l34, l35, l15);
                l35 = std_core_write_string_at(l34, l35, 366u);
                l35 = std_core_write_string_at(l34, l35, l25);
                l35 = std_core_write_string_at(l34, l35, 407u);
                l35 = std_core_write_string_at(l34, l35, l26);
                l35 = std_core_write_string_at(l34, l35, 150u);
                l36 = std_core_finish_buffer(l34, l35);
                vader_array_push((vader_array_t*) l6, vader_box_string(167u, l36));
                l37 = vader_c_emit_signedness_assert(l0, l11, l2, l13);
                if (!(l37.tag == 0u)) {
                    l38 = l37.payload.s;
                    vader_array_push((vader_array_t*) l6, vader_box_string(167u, l38));
                } else {
                }
                t2 = (l10 + INT64_C(1));
                l10 = (size_t) (int64_t) t2;
                goto loop_16;
            } else {
            }
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_c_emit_push_lit(void* l0, uint8_t l1, vader_string_t l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void** gc_raw_roots[3] = { &l0, &l3, &l4 };
    vader_string_t* gc_atom_roots[1] = { &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_c_emit_FnState_t*) l0)->f_stack;
    vader_struct_vader_c_emit_StackLit_t* _a0_obj = (vader_struct_vader_c_emit_StackLit_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_StackLit_t));
    vader_obj_header_init(_a0_obj, 671u);
    _a0_obj->f_text = l2;
    _a0_obj->f_val = l1;
    l4 = (void*) _a0_obj;
    vader_array_push((vader_array_t*) l3, vader_ref_box(l4));
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_c_emit_push_local_ref(void* l0, int32_t l1, uint8_t l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void** gc_raw_roots[3] = { &l0, &l3, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_c_emit_FnState_t*) l0)->f_stack;
    vader_struct_vader_c_emit_StackLocalRef_t* _a0_obj = (vader_struct_vader_c_emit_StackLocalRef_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_StackLocalRef_t));
    vader_obj_header_init(_a0_obj, 672u);
    _a0_obj->f_slot = l1;
    _a0_obj->f_val = l2;
    l4 = (void*) _a0_obj;
    vader_array_push((vader_array_t*) l3, vader_ref_box(l4));
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_c_emit_push_member_copies(void* l0, void* l1, vader_string_t l2, vader_string_t l3, bool l4, void* l5, int32_t l6) {
    void* l7 = NULL;
    void* l10 = NULL;
    void* l17 = NULL;
    size_t l8, l9;
    vader_string_t l11 = 0;
    vader_string_t l12 = 0;
    vader_string_t l14 = 0;
    vader_string_t l15 = 0;
    vader_string_t l16 = 0;
    vader_string_t l19 = 0;
    vader_string_t l20 = 0;
    vader_string_t l21 = 0;
    vader_string_t l22 = 0;
    vader_string_t l23 = 0;
    vader_box_t l13 = vader_box_null();
    int32_t l18;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    int64_t t2;
    vader_box_t* gc_roots[1] = { &l13 };
    void** gc_raw_roots[7] = { &l0, &l1, &l5, &l7, &l10, &l17, &t0 };
    vader_string_t* gc_atom_roots[13] = { &l2, &l3, &l11, &l12, &l14, &l15, &l16, &l19, &l20, &l21, &l22, &l23, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 13u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    if ((l6 >= INT32_C(16))) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l7 = l1;
    l8 = ((vader_array_t*) l7)->length;
    l9 = (size_t) (int64_t) INT64_C(0);
    {
        loop_13: {
            if ((l9 < l8)) {
                vader_array_t* _a0_slotarr = ((vader_array_t*) l7);
                if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                if ((size_t) l9 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                l10 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l9);
                l11 = vader_c_emit_c_field_name(l10);
                l12 = concat_3(l2, 407u, l11);
                l13 = vader_bytecode_nested_mirror(l10, l0);
                if (!(l13.tag == 0u)) {
                    t0 = l13.payload.obj;
                    t1 = ((vader_struct_vader_bytecode_BcStruct_t*) t0)->f_name;
                    l14 = vader_c_emit_struct_c_name(t1);
                    l15 = ((vader_struct_vader_bytecode_BcField_t*) l10)->f_name;
                    l16 = concat_7(279u, l14, 354u, l3, 400u, l15, 318u);
                    t0 = l13.payload.obj;
                    l17 = ((vader_struct_vader_bytecode_BcStruct_t*) t0)->f_fields;
                    l18 = (l6 + INT32_C(1));
                    vader_c_emit_push_member_copies(l0, l17, l12, l16, l4, l5, l18);
                    t2 = (l9 + INT64_C(1));
                    l9 = (size_t) (int64_t) t2;
                    goto loop_13;
                }
                if (l4) {
                    l19 = ((vader_struct_vader_bytecode_BcField_t*) l10)->f_name;
                    l20 = concat_8(l12, 65u, l12, 341u, l3, 400u, l19, 494u);
                    vader_array_push((vader_array_t*) l5, vader_box_string(167u, l20));
                } else {
                    l21 = ((vader_struct_vader_bytecode_BcField_t*) l10)->f_name;
                    l22 = ((vader_struct_vader_bytecode_BcField_t*) l10)->f_name;
                    l23 = concat_10(l3, 400u, l21, 65u, l3, 400u, l22, 341u, l12, 494u);
                    vader_array_push((vader_array_t*) l5, vader_box_string(167u, l23));
                }
                t2 = (l9 + INT64_C(1));
                l9 = (size_t) (int64_t) t2;
                goto loop_13;
            } else {
            }
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_c_emit_push_struct_field(void* l0, int32_t l1, int32_t l2, vader_string_t l3, uint8_t l4) {
    void* l5 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    size_t l6, l15, l16, l20, l21, l22, l23, l24, l25;
    vader_box_t l7 = vader_box_null();
    vader_string_t l10 = 0;
    vader_string_t l13 = 0;
    vader_string_t l14 = 0;
    vader_string_t l17 = 0;
    vader_string_t l18 = 0;
    vader_string_t l19 = 0;
    int32_t l11;
    uint8_t l12;
    int64_t l26;
    int64_t t0;
    vader_box_t t1 = vader_box_null();
    vader_string_t t2 = 0;
    size_t t3;
    vader_box_t* gc_roots[2] = { &l7, &t1 };
    void** gc_raw_roots[4] = { &l0, &l5, &l8, &l9 };
    vader_string_t* gc_atom_roots[8] = { &l3, &l10, &l13, &l14, &l17, &l18, &l19, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 8u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l5 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_ctx)->f_module)->f_types;
    t0 = ((int64_t) (int32_t) l1);
    l6 = (size_t) (int64_t) t0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    if ((size_t) l6 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
    l7 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l6);
    if (l7.tag == 509u) {
        l8 = l7.payload.obj;
        l9 = ((vader_struct_vader_c_emit_EmitCtx_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_ctx)->f_struct_c_names;
        t0 = ((int64_t) (int32_t) l1);
        l6 = (size_t) (int64_t) t0;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l9);
        if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
        if ((size_t) l6 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
        t1 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l6];
        l10 = t1.payload.s;
        l8 = ((vader_struct_vader_bytecode_BcStruct_t*) l8)->f_fields;
        t0 = ((int64_t) (int32_t) l2);
        l6 = (size_t) (int64_t) t0;
        vader_array_t* _a2_slotarr = ((vader_array_t*) l8);
        if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
        if ((size_t) l6 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
        l8 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l6);
        l11 = ((vader_struct_vader_bytecode_BcField_t*) l8)->f_type_index;
        l12 = vader_c_emit_val_type_of_field(l5, l11);
        l13 = vader_c_emit_obj_ptr_expr(l3, l4);
        t2 = ((vader_struct_vader_bytecode_BcField_t*) l8)->f_name;
        l14 = vader_c_emit_sanitise(t2);
        l10 = concat_6(279u, l10, 354u, l13, 347u, l14);
        l5 = vader_c_emit_find_erased_siblings(l5, l1);
        t3 = ((vader_array_t*) l5)->length;
        if (t3 == INT64_C(0)) {
            vader_c_emit_push_expr(l0, l12, l10);
        } else {
            l14 = vader_c_emit_tag_of_expr(l3, l4);
            l6 = ((vader_array_t*) l5)->length;
            l15 = (size_t) (int64_t) INT64_C(0);
            {
                loop_82: {
                    if ((l15 < l6)) {
                        t3 = ((vader_array_t*) l5)->length;
                        t0 = ((t3 - INT64_C(1)) - l15);
                        l16 = (size_t) (int64_t) t0;
                        vader_array_t* _a3_slotarr = ((vader_array_t*) l5);
                        if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                        if ((size_t) l16 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                        l11 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l16];
                        l18 = vader_c_emit_erased_sibling_field_read(l0, l11, l2, l12, l13);
                        l17 = l14;
                        l19 = l10;
                        l20 = vader_host_std_core_byte_len(l17);
                        l21 = vader_host_std_core_byte_len(l18);
                        t0 = (l20 + l21);
                        l22 = (size_t) (int64_t) t0;
                        l23 = vader_host_std_core_byte_len(l19);
                        t0 = (l22 + l23);
                        l24 = (size_t) (int64_t) t0;
                        l8 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(33) + l24));
                        l25 = (size_t) (int64_t) INT64_C(0);
                        l25 = std_core_write_string_at(l8, l25, 278u);
                        l25 = std_core_write_string_at(l8, l25, l17);
                        l25 = std_core_write_string_at(l8, l25, 90u);
                        l26 = ((int64_t) (int32_t) l11);
                        l25 = std_core_write_int(l8, l25, l26);
                        l25 = std_core_write_string_at(l8, l25, 2201u);
                        l25 = std_core_write_string_at(l8, l25, l18);
                        l25 = std_core_write_string_at(l8, l25, 55u);
                        l25 = std_core_write_string_at(l8, l25, l19);
                        l25 = std_core_write_string_at(l8, l25, 318u);
                        l10 = std_core_finish_buffer(l8, l25);
                        t0 = (l15 + INT64_C(1));
                        l15 = (size_t) (int64_t) t0;
                        goto loop_82;
                    } else {
                    }
                }
            }
            vader_c_emit_push_expr(l0, l12, l10);
        }
    } else {
        l5 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(59));
        l6 = (size_t) (int64_t) INT64_C(0);
        l6 = std_core_write_string_at(l5, l6, 2110u);
        l26 = ((int64_t) (int32_t) l1);
        l6 = std_core_write_int(l5, l6, l26);
        t2 = std_core_finish_buffer(l5, l6);
        std_abort_todo(t2);
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_c_emit_push_tmp(void* l0, vader_string_t l1, uint8_t l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void** gc_raw_roots[3] = { &l0, &l3, &l4 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_c_emit_FnState_t*) l0)->f_stack;
    vader_struct_vader_c_emit_StackTmp_t* _a0_obj = (vader_struct_vader_c_emit_StackTmp_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_StackTmp_t));
    vader_obj_header_init(_a0_obj, 674u);
    _a0_obj->f_name = l1;
    _a0_obj->f_val = l2;
    l4 = (void*) _a0_obj;
    vader_array_push((vader_array_t*) l3, vader_ref_box(l4));
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_c_emit_push_unop(void* l0, vader_string_t l1, uint8_t l2) {
    vader_box_t l3 = vader_box_null();
    void* l4 = NULL;
    vader_string_t l5 = 0;
    uint8_t l6;
    vader_box_t* gc_roots[1] = { &l3 };
    void** gc_raw_roots[2] = { &l0, &l4 };
    vader_string_t* gc_atom_roots[2] = { &l1, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l3 = vader_c_emit_pop(l0);
    l4 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) ((vader_struct_vader_c_emit_FnState_t*) l0)->f_ctx)->f_module)->f_types;
    l5 = vader_c_emit_name_of(l3);
    l6 = vader_c_emit_val_of(l3);
    l5 = vader_c_emit_coerce_operand(l4, l5, l6, l2);
    l5 = concat_4(l1, 278u, l5, 318u);
    vader_c_emit_push_expr(l0, l2, l5);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static bool vader_c_emit_ref_carrying_element(vader_box_t l0, void* l1) {
    void* t0;
    bool t1;
    if ((l0.tag == 496u || l0.tag == 499u || l0.tag == 506u || l0.tag == 509u)) {
        return true;
    }
    if (l0.tag == 510u) {
        t0 = l0.payload.obj;
        t1 = vader_bytecode_is_ref_only_element(vader_ref_box(t0), l1);
        return t1;
    }
    return false;
}

static vader_string_t vader_c_emit_resolve_array_local(void* l0, vader_string_t l1, bool l2) {
    vader_box_t l3 = vader_box_null();
    vader_string_t l4 = 0;
    vader_string_t l5 = 0;
    vader_box_t* gc_roots[1] = { &l3 };
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[3] = { &l1, &l4, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l3 = std_collections_get__string__string(((vader_struct_vader_c_emit_FnState_t*) l0)->f_resolved_arrays, l1);
    if (l3.tag == 167u) {
        l4 = l3.payload.s;
        if (l2) {
            std_collections_add__string(((vader_struct_vader_c_emit_FnState_t*) l0)->f_pinned_resolves, l1);
        } else {
        }
        { vader_string_t __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = vader_c_emit_aux(l0, 2019u);
    l5 = concat_5(2317u, l4, 61u, l1, 494u);
    vader_c_emit_line(l0, l5);
    l5 = concat_9(1693u, l4, 387u, l4, 393u, l4, 388u, l4, 390u);
    vader_c_emit_line(l0, l5);
    std_collections_put__string__string(((vader_struct_vader_c_emit_FnState_t*) l0)->f_resolved_arrays, l1, l4);
    if (l2) {
        std_collections_add__string(((vader_struct_vader_c_emit_FnState_t*) l0)->f_pinned_resolves, l1);
    } else {
    }
    { vader_string_t __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_string_t vader_c_emit_rewrite_temps(vader_string_t l0, void* l1) {
    void* l2 = NULL;
    void* l5 = NULL;
    void* l12 = NULL;
    void* l17 = NULL;
    size_t l3, l4, l6, l7, l9, l15, l18, l19;
    bool l8, l10, l11, l13, l14;
    vader_string_t l16 = 0;
    vader_string_t l21 = 0;
    int64_t l20;
    void* t0 = NULL;
    int64_t t1;
    vader_box_t t2 = vader_box_null();
    uint8_t t3;
    bool t4;
    size_t t5;
    int32_t t6;
    vader_string_t t7 = 0;
    vader_box_t* gc_roots[1] = { &t2 };
    void** gc_raw_roots[6] = { &l1, &l2, &l5, &l12, &l17, &t0 };
    vader_string_t* gc_atom_roots[4] = { &l0, &l16, &l21, &t7 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = vader_host_std_core_bytes(l0);
    l3 = ((vader_array_t*) l2)->length;
    l4 = ((vader_array_t*) l1)->length;
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 167u);
    t0 = (void*) _a0_arr;
    vader_struct_std_string_builder_StringBuilder_t* _a1_obj = (vader_struct_std_string_builder_StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string_builder_StringBuilder_t));
    vader_obj_header_init(_a1_obj, 389u);
    _a1_obj->f_parts = t0;
    l5 = (void*) _a1_obj;
    l6 = (size_t) (int64_t) INT64_C(0);
    l7 = (size_t) (int64_t) INT64_C(0);
    {
        loop_16: {
            if ((l7 < l3)) {
                if (l7 == INT64_C(0)) {
                    l8 = true;
                } else {
                    t1 = (l7 - INT64_C(1));
                    l9 = (size_t) (int64_t) t1;
                    vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
                    if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                    if ((size_t) l9 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                    t2 = vader_array_read_u8(_a2_slotarr, _a2_slotarr->offset + (size_t) l9, 173u);
                    t3 = ((uint8_t) t2.payload.i);
                    l8 = t3 == INT32_C(10);
                }
                if (l8) {
                    vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
                    if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                    if ((size_t) l7 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                    t2 = vader_array_read_u8(_a3_slotarr, _a3_slotarr->offset + (size_t) l7, 173u);
                    t3 = ((uint8_t) t2.payload.i);
                    l10 = t3 == INT32_C(35);
                } else {
                    l10 = false;
                }
                if (l10) {
                    {
                        loop_56: {
                            if ((l7 < l3)) {
                                vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
                                if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                                if ((size_t) l7 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                                t2 = vader_array_read_u8(_a4_slotarr, _a4_slotarr->offset + (size_t) l7, 173u);
                                t3 = ((uint8_t) t2.payload.i);
                                l11 = t3 != INT32_C(10);
                            } else {
                                l11 = false;
                            }
                            if (l11) {
                                t1 = (l7 + INT64_C(1));
                                l7 = (size_t) (int64_t) t1;
                                goto loop_56;
                            } else {
                            }
                        }
                    }
                    goto loop_16;
                }
                vader_array_t* _a5_slotarr = ((vader_array_t*) l2);
                if (_a5_slotarr->buf != NULL && _a5_slotarr->buf->header.forward != NULL) { _a5_slotarr->buf = vader_array_buf_forward(_a5_slotarr->buf); }
                if ((size_t) l7 >= _a5_slotarr->length) { vader_trap("array index out of bounds"); }
                t2 = vader_array_read_u8(_a5_slotarr, _a5_slotarr->offset + (size_t) l7, 173u);
                t3 = ((uint8_t) t2.payload.i);
                if (t3 != INT32_C(116)) {
                    t1 = (l7 + INT64_C(1));
                    l7 = (size_t) (int64_t) t1;
                    goto loop_16;
                }
                l12 = vader_c_emit_temp_token_at(l2, l7, l3);
                t4 = ((vader_struct_vader_c_emit_SlotToken_t*) l12)->f_ok;
                if (t4) {
                    t5 = ((vader_struct_vader_c_emit_SlotToken_t*) l12)->f_id;
                    l13 = (t5 < l4);
                } else {
                    l13 = false;
                }
                if (l13) {
                    l15 = ((vader_struct_vader_c_emit_SlotToken_t*) l12)->f_id;
                    vader_array_t* _a6_slotarr = ((vader_array_t*) l1);
                    if (_a6_slotarr->buf != NULL && _a6_slotarr->buf->header.forward != NULL) { _a6_slotarr->buf = vader_array_buf_forward(_a6_slotarr->buf); }
                    if ((size_t) l15 >= _a6_slotarr->length) { vader_trap("array index out of bounds"); }
                    t6 = ((int32_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l15];
                    l14 = (t6 >= INT32_C(0));
                } else {
                    l14 = false;
                }
                if (l14) {
                    if ((l7 > l6)) {
                        vader_array_t* _a7_arr = vader_array_slice((vader_array_t*) l2, (size_t) l6, (size_t) l7);
                        t0 = (void*) _a7_arr;
                        l16 = vader_host_std_core_bytes_to_string(t0);
                        std_string_builder_append(l5, l16);
                    } else {
                    }
                    l17 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(21));
                    l18 = (size_t) (int64_t) INT64_C(0);
                    l18 = std_core_write_string_at(l17, l18, 2133u);
                    l19 = ((vader_struct_vader_c_emit_SlotToken_t*) l12)->f_id;
                    vader_array_t* _a8_slotarr = ((vader_array_t*) l1);
                    if (_a8_slotarr->buf != NULL && _a8_slotarr->buf->header.forward != NULL) { _a8_slotarr->buf = vader_array_buf_forward(_a8_slotarr->buf); }
                    if ((size_t) l19 >= _a8_slotarr->length) { vader_trap("array index out of bounds"); }
                    t6 = ((int32_t*) _a8_slotarr->buf->slots)[_a8_slotarr->offset + (size_t) l19];
                    l20 = ((int64_t) (int32_t) t6);
                    l18 = std_core_write_int(l17, l18, l20);
                    l21 = std_core_finish_buffer(l17, l18);
                    std_string_builder_append(l5, l21);
                    l6 = ((vader_struct_vader_c_emit_SlotToken_t*) l12)->f_end;
                } else {
                }
                l7 = ((vader_struct_vader_c_emit_SlotToken_t*) l12)->f_end;
                goto loop_16;
            } else {
            }
        }
    }
    if ((l3 > l6)) {
        vader_array_t* _a9_arr = vader_array_slice((vader_array_t*) l2, (size_t) l6, (size_t) l3);
        t0 = (void*) _a9_arr;
        l16 = vader_host_std_core_bytes_to_string(t0);
        std_string_builder_append(l5, l16);
    } else {
    }
    t7 = std_string_builder_StringBuilder_Display_to_string(l5);
    { vader_string_t __vret = t7; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
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
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l1 = vader_host_std_core_byte_len(l0);
    vader_array_t* _a0_arr = vader_array_new(11u, 0u, 1u, 173u);
    l2 = (void*) _a0_arr;
    l3 = (size_t) (int64_t) INT64_C(0);
    {
        loop_8: {
            if ((l3 < l1)) {
                l4 = vader_host_std_core_byte_at(l0, l3);
                t0 = vader_text_is_ident_byte(l4);
                if (t0) {
                    l5 = l4;
                } else {
                    l5 = (uint8_t) (int32_t) INT32_C(95);
                }
                vader_array_push_u8((vader_array_t*) l2, (int32_t) (uint8_t) l5);
                t1 = (l3 + INT64_C(1));
                l3 = (size_t) (int64_t) t1;
                goto loop_8;
            } else {
            }
        }
    }
    l6 = vader_host_std_core_bytes_to_string(l2);
    t0 = vader_c_emit_is_c_reserved(l6);
    if (t0) {
        t2 = concat_2(l6, 920u);
        { vader_string_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_string_t __vret = l6; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_c_emit_scan_fn_value_usage(void* l0) {
    size_t l1, l4, l9, l10, l13, l14;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l12 = NULL;
    int32_t l5;
    bool l6;
    vader_box_t l11 = vader_box_null();
    int64_t t0;
    void* t1 = NULL;
    int32_t t2;
    vader_box_t* gc_roots[1] = { &l11 };
    void** gc_raw_roots[7] = { &l0, &l2, &l3, &l7, &l8, &l12, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 7u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = ((vader_array_t*) l0)->length;
    vader_array_t* _a0_arr = vader_array_new(9u, 0u, 7u, 170u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(6u, 0u, 12u, 165u);
    l3 = (void*) _a1_arr;
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_10: {
            if ((l4 < l1)) {
                l5 = -(INT32_C(1));
                vader_array_push_i32((vader_array_t*) l2, l5);
                vader_array_push_bool((vader_array_t*) l3, false);
                t0 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                goto loop_10;
            } else {
            }
        }
    }
    l6 = false;
    l7 = l0;
    vader_array_t* _a2_slotarr = ((vader_array_t*) l7);
    if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
    l1 = ((vader_array_t*) l7)->length;
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_42: {
            if ((l4 < l1)) {
                if ((size_t) l4 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                t1 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
                l8 = ((vader_struct_vader_bytecode_BcFunction_t*) t1)->f_body;
                vader_array_t* _a3_slotarr = ((vader_array_t*) l8);
                if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                l9 = ((vader_array_t*) l8)->length;
                l10 = (size_t) (int64_t) INT64_C(0);
                {
                    loop_57: {
                        if ((l10 < l9)) {
                            if ((size_t) l10 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                            l11 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l10);
                            if (l11.tag == 561u) {
                                l12 = l11.payload.obj;
                                t2 = ((vader_struct_vader_bytecode_FnRef_t*) l12)->f_function_index;
                                t0 = ((int64_t) (int32_t) t2);
                                l13 = (size_t) (int64_t) t0;
                                l5 = ((vader_struct_vader_bytecode_FnRef_t*) l12)->f_type_id;
                                vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
                                if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                                if ((size_t) l13 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                                ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l13] = (int32_t) l5;
                                l6 = true;
                            } else {
                                if (l11.tag == 616u) {
                                    t1 = l11.payload.obj;
                                    t2 = ((vader_struct_vader_bytecode_MakeClosure_t*) t1)->f_function_index;
                                    t0 = ((int64_t) (int32_t) t2);
                                    l14 = (size_t) (int64_t) t0;
                                    vader_array_t* _a5_slotarr = ((vader_array_t*) l3);
                                    if (_a5_slotarr->buf != NULL && _a5_slotarr->buf->header.forward != NULL) { _a5_slotarr->buf = vader_array_buf_forward(_a5_slotarr->buf); }
                                    if ((size_t) l14 >= _a5_slotarr->length) { vader_trap("array index out of bounds"); }
                                    ((uint8_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l14] = (uint8_t) true;
                                    l6 = true;
                                } else {
                                }
                            }
                            t0 = (l10 + INT64_C(1));
                            l10 = (size_t) (int64_t) t0;
                            goto loop_57;
                        } else {
                        }
                    }
                }
                t0 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                goto loop_42;
            } else {
            }
        }
    }
    vader_struct_vader_c_emit_FnValueUsage_t* _a6_obj = (vader_struct_vader_c_emit_FnValueUsage_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_FnValueUsage_t));
    vader_obj_header_init(_a6_obj, 666u);
    _a6_obj->f_fn_ref_type = l2;
    _a6_obj->f_is_closure = l3;
    _a6_obj->f_any = l6;
    t1 = (void*) _a6_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_box_t vader_c_emit_scope_ending_at(void* l0, int32_t l1) {
    size_t l2, l3;
    void* t0;
    int32_t t1;
    int64_t t2;
    vader_box_t t3;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    l2 = ((vader_array_t*) l0)->length;
    l3 = (size_t) (int64_t) INT64_C(0);
    {
        loop_6: {
            if ((l3 < l2)) {
                if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
                t1 = ((vader_struct_vader_c_emit_ScopeInfo_t*) t0)->f_end_pc;
                if (t1 == l1) {
                    if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                    t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
                    return vader_ref_box(t0);
                }
                t2 = (l3 + INT64_C(1));
                l3 = (size_t) (int64_t) t2;
                goto loop_6;
            } else {
            }
        }
    }
    t3 = vader_box_obj(0u, NULL);
    return t3;
}

static vader_string_t vader_c_emit_shim_linkage_prefix(bool l0) {
    vader_string_t l1;
    if (l0) {
        l1 = 2031u;
    } else {
        l1 = 2030u;
    }
    return l1;
}

static vader_string_t vader_c_emit_signature_for(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l7 = NULL;
    size_t l3, l4, l6, l8;
    vader_string_t l5 = 0;
    vader_string_t l10 = 0;
    vader_string_t l11 = 0;
    uint64_t l9;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    int64_t t2;
    size_t t3;
    vader_string_t t4 = 0;
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l7, &t0 };
    vader_string_t* gc_atom_roots[4] = { &l5, &l10, &l11, &t4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 167u);
    t0 = (void*) _a0_arr;
    vader_struct_std_string_builder_StringBuilder_t* _a1_obj = (vader_struct_std_string_builder_StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string_builder_StringBuilder_t));
    vader_obj_header_init(_a1_obj, 389u);
    _a1_obj->f_parts = t0;
    l1 = (void*) _a1_obj;
    l2 = ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_signature)->f_params;
    l3 = ((vader_array_t*) l2)->length;
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_11: {
            if ((l4 < l3)) {
                if ((l4 > INT64_C(0))) {
                    std_string_builder_append(l1, 365u);
                } else {
                }
                vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
                if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                if ((size_t) l4 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                t1 = vader_array_read_u8(_a2_slotarr, _a2_slotarr->offset + (size_t) l4, 173u);
                l5 = vader_c_emit_c_type_for_val_bare(((uint8_t) t1.payload.i));
                l6 = vader_host_std_core_byte_len(l5);
                l7 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(22) + l6));
                l8 = (size_t) (int64_t) INT64_C(0);
                l8 = std_core_write_string_at(l7, l8, l5);
                l8 = std_core_write_string_at(l7, l8, 134u);
                t2 = ((int64_t) (size_t) l4);
                l9 = (uint64_t) (int64_t) t2;
                l8 = std_core_write_unsigned(l7, l8, l9);
                l10 = std_core_finish_buffer(l7, l8);
                std_string_builder_append(l1, l10);
                t2 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t2;
                goto loop_11;
            } else {
            }
        }
    }
    t3 = ((vader_array_t*) l2)->length;
    if (t3 == INT64_C(0)) {
        l5 = 2382u;
    } else {
        l5 = std_string_builder_StringBuilder_Display_to_string(l1);
    }
    l10 = vader_c_emit_c_type_for_val_bare(((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_signature)->f_result);
    t4 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_name;
    l11 = vader_c_emit_sanitise(t4);
    t4 = concat_6(l10, 6u, l11, 278u, l5, 318u);
    { vader_string_t __vret = t4; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_box_t vader_c_emit_signedness_assert(void* l0, void* l1, vader_string_t l2, vader_string_t l3) {
    vader_box_t l4 = vader_box_null();
    vader_string_t l5 = 0;
    vader_string_t l6 = 0;
    vader_box_t t0 = vader_box_null();
    uint8_t t1;
    bool t2;
    vader_string_t t3 = 0;
    vader_box_t* gc_roots[2] = { &l4, &t0 };
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_string_t* gc_atom_roots[5] = { &l2, &l3, &l5, &l6, &t3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 5u, gc_atom_roots };
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
    t1 = ((uint8_t) l4.payload.i);
    t2 = vader_bytecode_is_unsigned_val(t1);
    if (t2) {
        l5 = 445u;
    } else {
        l5 = 450u;
    }
    l6 = concat_5(280u, l2, 356u, l3, 342u);
    t3 = concat_9(875u, l6, 90u, l5, 366u, l2, 407u, l3, 165u);
    t0 = vader_box_string(167u, t3);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_string_t vader_c_emit_slot_index(vader_string_t l0, vader_box_t l1) {
    vader_string_t l2 = 0;
    vader_string_t t0 = 0;
    vader_box_t* gc_roots[1] = { &l1 };
    vader_string_t* gc_atom_roots[3] = { &l0, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 0u, gc_roots, NULL, 0u, NULL, 3u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = vader_c_emit_name_of(l1);
    t0 = concat_3(l0, 404u, l2);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_c_emit_slot_token_at(void* l0, size_t l1, size_t l2, uint8_t l3) {
    bool l4;
    size_t l5, l6, l7, l8;
    vader_box_t t0 = vader_box_null();
    uint8_t t1;
    void* t2 = NULL;
    int64_t t3;
    bool t4;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[2] = { &l0, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    if ((size_t) l1 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
    t0 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l1, 173u);
    t1 = ((uint8_t) t0.payload.i);
    if (t1 != l3) {
        t2 = vader_c_emit_no_slot((size_t) (int64_t) (l1 + INT64_C(1)));
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if ((l1 > INT64_C(0))) {
        t3 = (l1 - INT64_C(1));
        l5 = (size_t) (int64_t) t3;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
        if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
        if ((size_t) l5 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
        t0 = vader_array_read_u8(_a1_slotarr, _a1_slotarr->offset + (size_t) l5, 173u);
        t1 = ((uint8_t) t0.payload.i);
        l4 = vader_text_is_ident_byte(t1);
    } else {
        l4 = false;
    }
    if (l4) {
        t2 = vader_c_emit_no_slot((size_t) (int64_t) (l1 + INT64_C(1)));
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (((l1 + INT64_C(1)) >= l2)) {
        l4 = true;
    } else {
        t3 = (l1 + INT64_C(1));
        l5 = (size_t) (int64_t) t3;
        vader_array_t* _a2_slotarr = ((vader_array_t*) l0);
        if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
        if ((size_t) l5 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
        t0 = vader_array_read_u8(_a2_slotarr, _a2_slotarr->offset + (size_t) l5, 173u);
        t1 = ((uint8_t) t0.payload.i);
        t4 = vader_c_emit_is_digit_byte(t1);
        l4 = !(t4);
    }
    if (l4) {
        t2 = vader_c_emit_no_slot((size_t) (int64_t) (l1 + INT64_C(1)));
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l5 = (size_t) (int64_t) INT64_C(0);
    t3 = (l1 + INT64_C(1));
    l6 = (size_t) (int64_t) t3;
    {
        loop_75: {
            if ((l6 < l2)) {
                vader_array_t* _a3_slotarr = ((vader_array_t*) l0);
                if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                if ((size_t) l6 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_read_u8(_a3_slotarr, _a3_slotarr->offset + (size_t) l6, 173u);
                t1 = ((uint8_t) t0.payload.i);
                l4 = vader_c_emit_is_digit_byte(t1);
            } else {
                l4 = false;
            }
            if (l4) {
                t3 = (l5 * INT64_C(10));
                l7 = (size_t) (int64_t) t3;
                vader_array_t* _a4_slotarr = ((vader_array_t*) l0);
                if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                if ((size_t) l6 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_read_u8(_a4_slotarr, _a4_slotarr->offset + (size_t) l6, 173u);
                t1 = ((uint8_t) t0.payload.i);
                t3 = ((int64_t) (uint32_t) (t1 - INT32_C(48)));
                l8 = (size_t) (int64_t) t3;
                t3 = (l7 + l8);
                l5 = (size_t) (int64_t) t3;
                t3 = (l6 + INT64_C(1));
                l6 = (size_t) (int64_t) t3;
                goto loop_75;
            } else {
            }
        }
    }
    if ((l6 < l2)) {
        vader_array_t* _a5_slotarr = ((vader_array_t*) l0);
        if (_a5_slotarr->buf != NULL && _a5_slotarr->buf->header.forward != NULL) { _a5_slotarr->buf = vader_array_buf_forward(_a5_slotarr->buf); }
        if ((size_t) l6 >= _a5_slotarr->length) { vader_trap("array index out of bounds"); }
        t0 = vader_array_read_u8(_a5_slotarr, _a5_slotarr->offset + (size_t) l6, 173u);
        t1 = ((uint8_t) t0.payload.i);
        l4 = vader_text_is_ident_byte(t1);
    } else {
        l4 = false;
    }
    if (l4) {
        t2 = vader_c_emit_no_slot(l6);
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_c_emit_SlotToken_t* _a6_obj = (vader_struct_vader_c_emit_SlotToken_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_SlotToken_t));
    vader_obj_header_init(_a6_obj, 669u);
    _a6_obj->f_ok = true;
    _a6_obj->f_id = l5;
    _a6_obj->f_end = l6;
    t2 = (void*) _a6_obj;
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
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
        if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
        if ((size_t) l4 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
        t2 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l4, 173u);
        return ((uint8_t) t2.payload.i);
    }
    l5 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_locals;
    t1 = ((int64_t) (int32_t) l1);
    l4 = (size_t) (int64_t) t1;
    l6 = ((vader_array_t*) l2)->length;
    t1 = (l4 - l6);
    l4 = (size_t) (int64_t) t1;
    vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
    if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
    if ((size_t) l4 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
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
    vader_obj_header_init(_a0_obj, 179u);
    _a0_obj->f_value = l0;
    t0 = (void*) _a0_obj;
    l1 = vader_ref_box(t0);
    vader_array_t* _a1_arr = vader_array_new(9u, 0u, 7u, 170u);
    l2 = (void*) _a1_arr;
    l3 = ((vader_array_t*) ((vader_struct__Cell_Array_Struct_vader_bytecode_BcFunction____t*) l1.payload.obj)->f_value)->length;
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_11: {
            if ((l4 < l3)) {
                l5 = ((int32_t) (size_t) l4);
                vader_array_push_i32((vader_array_t*) l2, l5);
                t1 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t1;
                goto loop_11;
            } else {
            }
        }
    }
    vader_struct___lambda_env_vader_c_emit_1_t* _a2_obj = (vader_struct___lambda_env_vader_c_emit_1_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_c_emit_1_t));
    vader_obj_header_init(_a2_obj, 242u);
    _a2_obj->f_cap_0 = l1;
    t0 = (void*) _a2_obj;
    vader_fn_t* _a3_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
    vader_obj_header_init(_a3_closure, 143u);
    _a3_closure->code = (void*) &vader_fn_lift___lambda_vader_c_emit_0;
    _a3_closure->env = t0;
    l6 = (void*) _a3_closure;
    t0 = std_sort_sort__i32(l2, l6);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
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
    vader_struct___Tuple_string_Array_i32__4ea60c40_t _a3_storage = {0};
    void* gc_stack_objs[1] = { (void*) &_a3_storage };
    vader_string_t* gc_atom_roots[2] = { &l7, &l8 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 6u, gc_roots, gc_raw_roots, 1u, gc_stack_objs, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 167u);
    l1 = (void*) _a0_arr;
    l2 = l0;
    l3 = ((vader_struct_std_collections_MutableMap__string__i32___t*) l2)->f_ekeys;
    l4 = ((vader_struct_std_collections_MutableMap__string__i32___t*) l2)->f_evals;
    l5 = ((vader_struct_std_collections_MutableMap__string__i32___t*) l2)->f_size;
    l6 = (size_t) (int64_t) INT64_C(0);
    {
        loop_14: {
            if ((l6 >= l5)) {
            } else {
                vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l6 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l6];
                l7 = t0.payload.s;
                vader_array_t* _a2_slotarr = ((vader_array_t*) l4);
                if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                if ((size_t) l6 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                l2 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l6);
                vader_struct___Tuple_string_Array_i32__4ea60c40_t* _a4_obj = &_a3_storage;
                vader_obj_header_init(_a4_obj, 232u);
                _a4_obj->f__0 = l7;
                _a4_obj->f__1 = l2;
                t1 = (void*) _a4_obj;
                l8 = ((vader_struct___Tuple_string_Array_i32__4ea60c40_t*) t1)->f__0;
                t2 = (l6 + INT64_C(1));
                l6 = (size_t) (int64_t) t2;
                vader_array_push((vader_array_t*) l1, vader_box_string(167u, l8));
                goto loop_14;
            }
        }
    }
    vader_struct___lambda_env_vader_c_emit_3_t* _a5_obj = (vader_struct___lambda_env_vader_c_emit_3_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_c_emit_3_t));
    vader_obj_header_init(_a5_obj, 243u);
    t1 = (void*) _a5_obj;
    vader_fn_t* _a6_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
    vader_obj_header_init(_a6_closure, 139u);
    _a6_closure->code = (void*) &vader_fn_lift___lambda_vader_c_emit_2;
    _a6_closure->env = t1;
    l2 = (void*) _a6_closure;
    t1 = std_sort_sort__string(l1, l2);
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_string_t vader_c_emit_storage_qualifier(bool l0) {
    vader_string_t l1;
    if (l0) {
        l1 = 0u;
    } else {
        l1 = 1398u;
    }
    return l1;
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
    size_t l1, l2, l4;
    vader_box_t l3;
    void* t0;
    bool t1;
    int64_t t2;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    l1 = ((vader_array_t*) l0)->length;
    l2 = (size_t) (int64_t) INT64_C(0);
    {
        loop_6: {
            if ((l2 < l1)) {
                if ((size_t) l2 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                l3 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
                if (l3.tag == 505u) {
                    t0 = l3.payload.obj;
                    t1 = vader_bytecode_is_string_val(((vader_struct_vader_bytecode_BcPrimitive_t*) t0)->f_val);
                    if (t1) {
                        return ((int32_t) (size_t) l2);
                    }
                    l4 = (size_t) (int64_t) INT64_C(1);
                    t2 = (l2 + l4);
                    l2 = (size_t) (int64_t) t2;
                    goto loop_6;
                }
                l4 = (size_t) (int64_t) INT64_C(1);
                t2 = (l2 + l4);
                l2 = (size_t) (int64_t) t2;
                goto loop_6;
            } else {
            }
        }
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
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    l3 = ((vader_array_t*) l2)->length;
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_14: {
            if ((l4 < l3)) {
                if ((size_t) l4 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
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
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l8 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                t3 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l8);
                if (!(t3.tag == 506u)) {
                    return false;
                }
                t2 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t2;
                goto loop_14;
            } else {
            }
        }
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
    t0 = concat_3(2361u, l1, 917u);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_string_t vader_c_emit_struct_check_expr(void* l0, vader_string_t l1, int32_t l2, vader_string_t l3) {
    vader_string_t l4 = 0;
    vader_string_t l8 = 0;
    vader_string_t l10 = 0;
    vader_string_t l15 = 0;
    size_t l5, l9, l11, l13;
    void* l6 = NULL;
    void* l12 = NULL;
    int64_t l7;
    uint64_t l14;
    int64_t t0;
    vader_box_t t1 = vader_box_null();
    void* t2 = NULL;
    vader_string_t t3 = 0;
    vader_string_t t4 = 0;
    size_t t5;
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[4] = { &l0, &l6, &l12, &t2 };
    vader_string_t* gc_atom_roots[8] = { &l1, &l3, &l4, &l8, &l10, &l15, &t3, &t4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 8u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l4 = l1;
    l5 = vader_host_std_core_byte_len(l4);
    l6 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(25) + l5));
    l5 = (size_t) (int64_t) INT64_C(0);
    l5 = std_core_write_string_at(l6, l5, l4);
    l5 = std_core_write_string_at(l6, l5, 90u);
    l7 = ((int64_t) (int32_t) l2);
    l5 = std_core_write_int(l6, l5, l7);
    l5 = std_core_write_string_at(l6, l5, 2198u);
    l4 = std_core_finish_buffer(l6, l5);
    l8 = vader_text_prefix_before_double_underscore(l3);
    if (l8 == 0u) {
        { vader_string_t __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a0_arr = vader_array_new(8u, 1u, 0u, 167u);
    vader_array_box_slots(_a0_arr->buf)[_a0_arr->offset + 0u] = vader_box_string(167u, l4);
    l6 = (void*) _a0_arr;
    l5 = ((vader_array_t*) l0)->length;
    l9 = (size_t) (int64_t) INT64_C(0);
    {
        loop_56: {
            if ((l9 < l5)) {
                if (((int32_t) (size_t) l9) == l2) {
                    t0 = (l9 + INT64_C(1));
                    l9 = (size_t) (int64_t) t0;
                    goto loop_56;
                }
                vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l9 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                t1 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l9);
                if (t1.tag == 509u) {
                    vader_array_t* _a2_slotarr = ((vader_array_t*) l0);
                    if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                    if ((size_t) l9 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                    t1 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l9);
                    t2 = t1.payload.obj;
                    t3 = ((vader_struct_vader_bytecode_BcStruct_t*) t2)->f_name;
                    t4 = vader_text_prefix_before_double_underscore(t3);
                    if (t4 == l8) {
                        l10 = l1;
                        l11 = vader_host_std_core_byte_len(l10);
                        l12 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(25) + l11));
                        l13 = (size_t) (int64_t) INT64_C(0);
                        l13 = std_core_write_string_at(l12, l13, l10);
                        l13 = std_core_write_string_at(l12, l13, 90u);
                        t0 = ((int64_t) (size_t) l9);
                        l14 = (uint64_t) (int64_t) t0;
                        l13 = std_core_write_unsigned(l12, l13, l14);
                        l13 = std_core_write_string_at(l12, l13, 2198u);
                        l15 = std_core_finish_buffer(l12, l13);
                        vader_array_push((vader_array_t*) l6, vader_box_string(167u, l15));
                    } else {
                    }
                } else {
                }
                t0 = (l9 + INT64_C(1));
                l9 = (size_t) (int64_t) t0;
                goto loop_56;
            } else {
            }
        }
    }
    t5 = ((vader_array_t*) l6)->length;
    if (t5 == INT64_C(1)) {
        { vader_string_t __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = std_string_join(l6, 200u);
    t3 = concat_3(278u, l4, 318u);
    { vader_string_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_string_t vader_c_emit_struct_field_init(void* l0, void* l1, vader_box_t l2, vader_string_t l3, int32_t l4, void* l5) {
    void* l6 = NULL;
    void* l10 = NULL;
    uint8_t l7;
    uint64_t l8;
    vader_string_t l9 = 0;
    size_t l11;
    int64_t l12;
    vader_box_t l13 = vader_box_null();
    vader_string_t t0 = 0;
    int32_t t1;
    int64_t t2;
    vader_box_t t3 = vader_box_null();
    uint8_t t4;
    vader_box_t* gc_roots[3] = { &l2, &l13, &t3 };
    void** gc_raw_roots[5] = { &l0, &l1, &l5, &l6, &l10 };
    vader_string_t* gc_atom_roots[3] = { &l3, &l9, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    if (l2.tag == 512u) {
        l6 = l2.payload.obj;
        l7 = ((vader_struct_vader_bytecode_BcValPrim_t*) l6)->f_kind;
        l8 = ((vader_struct_vader_bytecode_BcValPrim_t*) l6)->f_bits;
        l9 = vader_c_emit_c_type_for_array_kind(((vader_struct_vader_bytecode_BcValPrim_t*) l6)->f_kind);
        t0 = vader_c_emit_data_slot_c(l7, l8, l9);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l2.tag == 513u) {
        l6 = l2.payload.obj;
        l10 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(21));
        l11 = (size_t) (int64_t) INT64_C(0);
        l9 = ((vader_struct_vader_bytecode_BcValStr_t*) l6)->f_value;
        t1 = vader_c_emit_atom_for(l5, l9);
        l12 = ((int64_t) (int32_t) t1);
        l11 = std_core_write_int(l10, l11, l12);
        l11 = std_core_write_string_at(l10, l11, 2198u);
        t0 = std_core_finish_buffer(l10, l11);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l13 = l2;
    l9 = vader_c_emit_emit_data_value(l0, l1, l13, l3, l5);
    l6 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_types;
    t2 = ((int64_t) (int32_t) l4);
    l11 = (size_t) (int64_t) t2;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l6);
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    if ((size_t) l11 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
    t3 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l11);
    t4 = vader_c_emit_val_type_of_bc_type(t3);
    if (t4 == INT32_C(18)) {
        t0 = concat_2(314u, l9);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l11 = vader_host_std_core_byte_len(l9);
    l6 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(50) + l11));
    l11 = (size_t) (int64_t) INT64_C(0);
    l11 = std_core_write_string_at(l6, l11, 2417u);
    l12 = ((int64_t) (int32_t) l4);
    l11 = std_core_write_int(l6, l11, l12);
    l11 = std_core_write_string_at(l6, l11, 2222u);
    l11 = std_core_write_string_at(l6, l11, l9);
    l11 = std_core_write_string_at(l6, l11, 204u);
    t0 = std_core_finish_buffer(l6, l11);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_string_t vader_c_emit_tag_of(vader_box_t l0) {
    vader_string_t l1 = 0;
    uint8_t l2;
    vader_string_t t0 = 0;
    vader_box_t* gc_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[2] = { &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 0u, gc_roots, NULL, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l1 = vader_c_emit_name_of(l0);
    l2 = vader_c_emit_val_of(l0);
    t0 = vader_c_emit_tag_of_expr(l1, l2);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_string_t vader_c_emit_tag_of_expr(vader_string_t l0, uint8_t l1) {
    vader_string_t l2 = 0;
    vader_string_t* gc_atom_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    if (l1 == INT32_C(18)) {
        l2 = concat_3(297u, l0, 348u);
    } else {
        l2 = concat_2(l0, 427u);
    }
    { vader_string_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_string_t vader_c_emit_tag_u(int32_t l0, vader_string_t l1) {
    void* l2 = NULL;
    size_t l3;
    int64_t l4;
    vader_string_t t0 = 0;
    void** gc_raw_roots[1] = { &l2 };
    vader_string_t* gc_atom_roots[2] = { &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    if ((l0 < INT32_C(0))) {
        t0 = concat_3(449u, l1, 169u);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(21));
    l3 = (size_t) (int64_t) INT64_C(0);
    l4 = ((int64_t) (int32_t) l0);
    l3 = std_core_write_int(l2, l3, l4);
    l3 = std_core_write_string_at(l2, l3, 2198u);
    t0 = std_core_finish_buffer(l2, l3);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_c_emit_temp_token_at(void* l0, size_t l1, size_t l2) {
    void* t0 = NULL;
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_c_emit_slot_token_at(l0, l1, l2, (uint8_t) (int32_t) INT32_C(116));
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_string_t vader_c_emit_trait_check_expr(void* l0, vader_string_t l1, vader_string_t l2, int32_t l3) {
    vader_string_t l4 = 0;
    vader_string_t l14 = 0;
    size_t l5, l9, l11, l13;
    void* l6 = NULL;
    void* l8 = NULL;
    void* l10 = NULL;
    void* l12 = NULL;
    int64_t l7;
    vader_string_t t0 = 0;
    int32_t t1;
    int64_t t2;
    void** gc_raw_roots[5] = { &l0, &l6, &l8, &l10, &l12 };
    vader_string_t* gc_atom_roots[5] = { &l1, &l2, &l4, &l14, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL, 5u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l4 = l1;
    l5 = vader_host_std_core_byte_len(l4);
    l6 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(27) + l5));
    l5 = (size_t) (int64_t) INT64_C(0);
    l5 = std_core_write_string_at(l6, l5, 278u);
    l5 = std_core_write_string_at(l6, l5, l4);
    l5 = std_core_write_string_at(l6, l5, 90u);
    l7 = ((int64_t) (int32_t) l3);
    l5 = std_core_write_int(l6, l5, l7);
    l5 = std_core_write_string_at(l6, l5, 2203u);
    t0 = std_core_finish_buffer(l6, l5);
    vader_array_t* _a0_arr = vader_array_new(8u, 1u, 0u, 167u);
    vader_array_box_slots(_a0_arr->buf)[_a0_arr->offset + 0u] = vader_box_string(167u, t0);
    l6 = (void*) _a0_arr;
    l8 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_impl_table;
    l5 = ((vader_array_t*) l8)->length;
    l9 = (size_t) (int64_t) INT64_C(0);
    {
        loop_52: {
            if ((l9 < l5)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) l8);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l9 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                l10 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l9);
                t0 = ((vader_struct_vader_bytecode_ImplEntry_t*) l10)->f_trait_name;
                if (t0 == l2) {
                    l4 = l1;
                    l11 = vader_host_std_core_byte_len(l4);
                    l12 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(27) + l11));
                    l13 = (size_t) (int64_t) INT64_C(0);
                    l13 = std_core_write_string_at(l12, l13, 278u);
                    l13 = std_core_write_string_at(l12, l13, l4);
                    l13 = std_core_write_string_at(l12, l13, 90u);
                    t1 = ((vader_struct_vader_bytecode_ImplEntry_t*) l10)->f_struct_type_index;
                    l7 = ((int64_t) (int32_t) t1);
                    l13 = std_core_write_int(l12, l13, l7);
                    l13 = std_core_write_string_at(l12, l13, 2203u);
                    l14 = std_core_finish_buffer(l12, l13);
                    vader_array_push((vader_array_t*) l6, vader_box_string(167u, l14));
                } else {
                }
                t2 = (l9 + INT64_C(1));
                l9 = (size_t) (int64_t) t2;
                goto loop_52;
            } else {
            }
        }
    }
    t0 = std_string_join(l6, 200u);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_string_t vader_c_emit_tramp_box_params(size_t l0) {
    void* l1 = NULL;
    void* l3 = NULL;
    size_t l2, l4;
    uint64_t l5;
    vader_string_t l6 = 0;
    void* t0 = NULL;
    int64_t t1;
    vader_string_t t2 = 0;
    void** gc_raw_roots[3] = { &l1, &l3, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l6, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 167u);
    t0 = (void*) _a0_arr;
    vader_struct_std_string_builder_StringBuilder_t* _a1_obj = (vader_struct_std_string_builder_StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string_builder_StringBuilder_t));
    vader_obj_header_init(_a1_obj, 389u);
    _a1_obj->f_parts = t0;
    l1 = (void*) _a1_obj;
    l2 = (size_t) (int64_t) INT64_C(0);
    {
        loop_6: {
            if ((l2 < l0)) {
                if ((l2 > INT64_C(0))) {
                    std_string_builder_append(l1, 365u);
                } else {
                }
                l3 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(33));
                l4 = (size_t) (int64_t) INT64_C(0);
                l4 = std_core_write_string_at(l3, l4, 2327u);
                t1 = ((int64_t) (size_t) l2);
                l5 = (uint64_t) (int64_t) t1;
                l4 = std_core_write_unsigned(l3, l4, l5);
                l6 = std_core_finish_buffer(l3, l4);
                std_string_builder_append(l1, l6);
                t1 = (l2 + INT64_C(1));
                l2 = (size_t) (int64_t) t1;
                goto loop_6;
            } else {
            }
        }
    }
    t2 = std_string_builder_StringBuilder_Display_to_string(l1);
    { vader_string_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_string_t vader_c_emit_tramp_box_result(vader_string_t l0, vader_string_t l1, void* l2) {
    vader_string_t l3 = 0;
    uint8_t l4;
    int32_t l5;
    vader_string_t t0 = 0;
    void** gc_raw_roots[1] = { &l2 };
    vader_string_t* gc_atom_roots[4] = { &l0, &l1, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l3 = concat_4(l0, 278u, l1, 318u);
    if (((vader_struct_vader_bytecode_BcSignature_t*) l2)->f_result == INT32_C(19)) {
        { vader_string_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (((vader_struct_vader_bytecode_BcSignature_t*) l2)->f_result == INT32_C(18)) {
        t0 = concat_3(2356u, l3, 318u);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = ((vader_struct_vader_bytecode_BcSignature_t*) l2)->f_result;
    l5 = ((vader_struct_vader_bytecode_BcSignature_t*) l2)->f_result_type;
    t0 = vader_c_emit_box_expr(l3, l4, l5);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_string_t vader_c_emit_tramp_head(size_t l0) {
    vader_string_t l1 = 0;
    vader_string_t l2 = 0;
    vader_string_t* gc_atom_roots[2] = { &l1, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    if (l0 == INT64_C(0)) {
        l1 = 2384u;
    } else {
        l2 = vader_c_emit_tramp_box_params(l0);
        l1 = concat_2(2385u, l2);
    }
    { vader_string_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_string_t vader_c_emit_tramp_unbox_args(void* l0) {
    void* l1 = NULL;
    void* l4 = NULL;
    size_t l2, l3, l5;
    uint64_t l6;
    vader_string_t l7 = 0;
    vader_string_t l9 = 0;
    uint8_t l8;
    int64_t t0;
    vader_box_t t1 = vader_box_null();
    vader_string_t t2 = 0;
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[3] = { &l0, &l1, &l4 };
    vader_string_t* gc_atom_roots[3] = { &l7, &l9, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 167u);
    l1 = (void*) _a0_arr;
    l2 = ((vader_array_t*) l0)->length;
    l3 = (size_t) (int64_t) INT64_C(0);
    {
        loop_8: {
            if ((l3 < l2)) {
                l4 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(21));
                l5 = (size_t) (int64_t) INT64_C(0);
                l5 = std_core_write_string_at(l4, l5, 1146u);
                t0 = ((int64_t) (size_t) l3);
                l6 = (uint64_t) (int64_t) t0;
                l5 = std_core_write_unsigned(l4, l5, l6);
                l7 = std_core_finish_buffer(l4, l5);
                vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l3 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                t1 = vader_array_read_u8(_a1_slotarr, _a1_slotarr->offset + (size_t) l3, 173u);
                l8 = ((uint8_t) t1.payload.i);
                l9 = vader_c_emit_unbox_expr(l7, l8);
                vader_array_push((vader_array_t*) l1, vader_box_string(167u, l9));
                t0 = (l3 + INT64_C(1));
                l3 = (size_t) (int64_t) t0;
                goto loop_8;
            } else {
            }
        }
    }
    t2 = std_string_join(l1, 365u);
    { vader_string_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static int32_t vader_c_emit_type_id_for_struct_symbol(void* l0, int32_t l1) {
    size_t l2, l3, l4;
    void* l5 = NULL;
    int64_t l6;
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    int32_t t2;
    int64_t t3;
    vader_string_t t4 = 0;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[3] = { &l0, &l5, &t1 };
    vader_string_t* gc_atom_roots[1] = { &t4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    l2 = ((vader_array_t*) l0)->length;
    l3 = (size_t) (int64_t) INT64_C(0);
    {
        loop_6: {
            if ((l3 < l2)) {
                if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
                if (t0.tag == 509u) {
                    vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
                    if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                    if ((size_t) l3 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                    t0 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l3);
                    t1 = t0.payload.obj;
                    t2 = ((vader_struct_vader_bytecode_BcStruct_t*) t1)->f_symbol_id;
                    if (t2 == l1) {
                        { int32_t __vret = ((int32_t) (size_t) l3); vader_gc_top = gc_frame.prev; return __vret; }
                    }
                    l4 = (size_t) (int64_t) INT64_C(1);
                    t3 = (l3 + l4);
                    l3 = (size_t) (int64_t) t3;
                    goto loop_6;
                }
                l4 = (size_t) (int64_t) INT64_C(1);
                t3 = (l3 + l4);
                l3 = (size_t) (int64_t) t3;
                goto loop_6;
            } else {
            }
        }
    }
    l5 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(80));
    l2 = (size_t) (int64_t) INT64_C(0);
    l2 = std_core_write_string_at(l5, l2, 1317u);
    l6 = ((int64_t) (int32_t) l1);
    l2 = std_core_write_int(l5, l2, l6);
    l2 = std_core_write_string_at(l5, l2, 144u);
    t4 = std_core_finish_buffer(l5, l2);
    vader_host_std_abort_panic(t4);
    vader_unreachable("unreachable return in vader_c_emit$type_id_for_struct_symbol");
    vader_gc_top = gc_frame.prev;
}

static int32_t vader_c_emit_type_index_for_name(void* l0, vader_string_t l1) {
    size_t l2, l3, l6;
    vader_string_t l4 = 0;
    vader_string_t l5 = 0;
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    vader_string_t t2 = 0;
    int64_t t3;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[2] = { &l0, &t1 };
    vader_string_t* gc_atom_roots[4] = { &l1, &l4, &l5, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = ((vader_array_t*) l0)->length;
    l3 = (size_t) (int64_t) INT64_C(0);
    {
        loop_6: {
            if ((l3 < l2)) {
                vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
                if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
                if (t0.tag == 509u) {
                    vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
                    if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                    if ((size_t) l3 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                    t0 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l3);
                    t1 = t0.payload.obj;
                    t2 = ((vader_struct_vader_bytecode_BcStruct_t*) t1)->f_name;
                    l4 = vader_c_emit_struct_c_name(t2);
                    l5 = vader_c_emit_struct_c_name(l1);
                    if (l4 == l5) {
                        { int32_t __vret = ((int32_t) (size_t) l3); vader_gc_top = gc_frame.prev; return __vret; }
                    }
                    l6 = (size_t) (int64_t) INT64_C(1);
                    t3 = (l3 + l6);
                    l3 = (size_t) (int64_t) t3;
                    goto loop_6;
                }
                l6 = (size_t) (int64_t) INT64_C(1);
                t3 = (l3 + l6);
                l3 = (size_t) (int64_t) t3;
                goto loop_6;
            } else {
            }
        }
    }
    { vader_gc_top = gc_frame.prev; return INT32_C(0); }
    vader_gc_top = gc_frame.prev;
}

static vader_box_t vader_c_emit_typed_array_fill_for(uint8_t l0) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0 == INT32_C(7)) {
        vader_struct_vader_c_emit_SlotFill_t* _a0_obj = (vader_struct_vader_c_emit_SlotFill_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_SlotFill_t));
        vader_obj_header_init(_a0_obj, 668u);
        _a0_obj->f_cty = 1727u;
        _a0_obj->f_val = (uint8_t) (int32_t) INT32_C(2);
        t0 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(3)) {
        vader_struct_vader_c_emit_SlotFill_t* _a1_obj = (vader_struct_vader_c_emit_SlotFill_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_SlotFill_t));
        vader_obj_header_init(_a1_obj, 668u);
        _a1_obj->f_cty = 1727u;
        _a1_obj->f_val = (uint8_t) (int32_t) INT32_C(2);
        t0 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(11)) {
        vader_struct_vader_c_emit_SlotFill_t* _a2_obj = (vader_struct_vader_c_emit_SlotFill_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_SlotFill_t));
        vader_obj_header_init(_a2_obj, 668u);
        _a2_obj->f_cty = 1727u;
        _a2_obj->f_val = (uint8_t) (int32_t) INT32_C(2);
        t0 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(8)) {
        vader_struct_vader_c_emit_SlotFill_t* _a3_obj = (vader_struct_vader_c_emit_SlotFill_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_SlotFill_t));
        vader_obj_header_init(_a3_obj, 668u);
        _a3_obj->f_cty = 1728u;
        _a3_obj->f_val = (uint8_t) (int32_t) INT32_C(3);
        t0 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(4)) {
        vader_struct_vader_c_emit_SlotFill_t* _a4_obj = (vader_struct_vader_c_emit_SlotFill_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_SlotFill_t));
        vader_obj_header_init(_a4_obj, 668u);
        _a4_obj->f_cty = 1728u;
        _a4_obj->f_val = (uint8_t) (int32_t) INT32_C(3);
        t0 = (void*) _a4_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(10)) {
        vader_struct_vader_c_emit_SlotFill_t* _a5_obj = (vader_struct_vader_c_emit_SlotFill_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_SlotFill_t));
        vader_obj_header_init(_a5_obj, 668u);
        _a5_obj->f_cty = 1451u;
        _a5_obj->f_val = (uint8_t) (int32_t) INT32_C(11);
        t0 = (void*) _a5_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(1)) {
        vader_struct_vader_c_emit_SlotFill_t* _a6_obj = (vader_struct_vader_c_emit_SlotFill_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_SlotFill_t));
        vader_obj_header_init(_a6_obj, 668u);
        _a6_obj->f_cty = 2257u;
        _a6_obj->f_val = (uint8_t) (int32_t) INT32_C(2);
        t0 = (void*) _a6_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(5)) {
        vader_struct_vader_c_emit_SlotFill_t* _a7_obj = (vader_struct_vader_c_emit_SlotFill_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_SlotFill_t));
        vader_obj_header_init(_a7_obj, 668u);
        _a7_obj->f_cty = 1729u;
        _a7_obj->f_val = (uint8_t) (int32_t) INT32_C(2);
        t0 = (void*) _a7_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(12)) {
        vader_struct_vader_c_emit_SlotFill_t* _a8_obj = (vader_struct_vader_c_emit_SlotFill_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_SlotFill_t));
        vader_obj_header_init(_a8_obj, 668u);
        _a8_obj->f_cty = 2257u;
        _a8_obj->f_val = (uint8_t) (int32_t) INT32_C(12);
        t0 = (void*) _a8_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(2)) {
        vader_struct_vader_c_emit_SlotFill_t* _a9_obj = (vader_struct_vader_c_emit_SlotFill_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_SlotFill_t));
        vader_obj_header_init(_a9_obj, 668u);
        _a9_obj->f_cty = 2254u;
        _a9_obj->f_val = (uint8_t) (int32_t) INT32_C(2);
        t0 = (void*) _a9_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(6)) {
        vader_struct_vader_c_emit_SlotFill_t* _a10_obj = (vader_struct_vader_c_emit_SlotFill_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_SlotFill_t));
        vader_obj_header_init(_a10_obj, 668u);
        _a10_obj->f_cty = 1726u;
        _a10_obj->f_val = (uint8_t) (int32_t) INT32_C(2);
        t0 = (void*) _a10_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(9)) {
        vader_struct_vader_c_emit_SlotFill_t* _a11_obj = (vader_struct_vader_c_emit_SlotFill_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_SlotFill_t));
        vader_obj_header_init(_a11_obj, 668u);
        _a11_obj->f_cty = 1591u;
        _a11_obj->f_val = (uint8_t) (int32_t) INT32_C(10);
        t0 = (void*) _a11_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(13)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    if (l0 == INT32_C(0)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    vader_unreachable("unreachable return in vader_c_emit$typed_array_fill_for");
    vader_gc_top = gc_frame.prev;
}

static vader_string_t vader_c_emit_unbox_expr(vader_string_t l0, uint8_t l1) {
    vader_string_t t0 = 0;
    vader_string_t* gc_atom_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    if (l1 == INT32_C(0)) {
        t0 = concat_3(288u, l0, 419u);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == INT32_C(1)) {
        t0 = concat_3(285u, l0, 419u);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == INT32_C(2)) {
        t0 = concat_3(286u, l0, 419u);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == INT32_C(3)) {
        t0 = concat_3(287u, l0, 419u);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == INT32_C(5)) {
        t0 = concat_3(294u, l0, 419u);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == INT32_C(6)) {
        t0 = concat_3(291u, l0, 419u);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == INT32_C(7)) {
        t0 = concat_3(292u, l0, 419u);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == INT32_C(8)) {
        t0 = concat_3(293u, l0, 419u);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == INT32_C(9)) {
        t0 = concat_3(290u, l0, 419u);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == INT32_C(4)) {
        t0 = concat_3(289u, l0, 419u);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == INT32_C(13)) {
        t0 = concat_3(292u, l0, 419u);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == INT32_C(10)) {
        t0 = concat_3(284u, l0, 418u);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == INT32_C(11)) {
        t0 = concat_3(283u, l0, 418u);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == INT32_C(12)) {
        t0 = concat_2(l0, 417u);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == INT32_C(14)) {
        t0 = concat_2(l0, 423u);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == INT32_C(15)) {
        { vader_string_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == INT32_C(16)) {
        { vader_gc_top = gc_frame.prev; return 298u; }
    }
    if (l1 == INT32_C(17)) {
        t0 = concat_3(299u, l0, 419u);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == INT32_C(18)) {
        t0 = concat_2(l0, 421u);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == INT32_C(19)) {
        { vader_string_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_unreachable("unreachable return in vader_c_emit$unbox_expr");
    vader_gc_top = gc_frame.prev;
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
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(8u, 1u, 0u, 167u);
    vader_array_box_slots(_a0_arr->buf)[_a0_arr->offset + 0u] = vader_box_string(167u, 906u);
    l2 = (void*) _a0_arr;
    l3 = ((vader_array_t*) l1)->length;
    l4 = (size_t) (int64_t) INT64_C(1);
    {
        loop_9: {
            if ((l4 < l3)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l4 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
                vader_array_t* _a2_slotarr = ((vader_array_t*) t0);
                if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                if ((size_t) INT32_C(0) >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                t1 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) INT32_C(0)];
                t2 = ((int64_t) (int32_t) t1);
                l5 = (size_t) (int64_t) t2;
                vader_array_t* _a3_slotarr = ((vader_array_t*) l0);
                if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                if ((size_t) l5 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l5);
                t3 = ((vader_struct_vader_bytecode_BcFunction_t*) t0)->f_name;
                l6 = vader_c_emit_module_stem_of(t3);
                l7 = vader_host_std_core_byte_len(l6);
                l8 = (size_t) (int64_t) INT64_C(0);
                {
                    loop_33: {
                        if ((l8 < l7)) {
                            t4 = vader_host_std_core_byte_at(l6, l8);
                            t5 = vader_text_is_ident_byte(t4);
                            if (!(t5)) {
                                vader_array_t* _a4_slotarr = ((vader_array_t*) l1);
                                if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                                if ((size_t) l4 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                                t0 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l4);
                                vader_array_t* _a5_slotarr = ((vader_array_t*) t0);
                                if (_a5_slotarr->buf != NULL && _a5_slotarr->buf->header.forward != NULL) { _a5_slotarr->buf = vader_array_buf_forward(_a5_slotarr->buf); }
                                if ((size_t) INT32_C(0) >= _a5_slotarr->length) { vader_trap("array index out of bounds"); }
                                t1 = ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) INT32_C(0)];
                                t2 = ((int64_t) (int32_t) t1);
                                l9 = (size_t) (int64_t) t2;
                                vader_array_t* _a6_slotarr = ((vader_array_t*) l0);
                                if (_a6_slotarr->buf != NULL && _a6_slotarr->buf->header.forward != NULL) { _a6_slotarr->buf = vader_array_buf_forward(_a6_slotarr->buf); }
                                if ((size_t) l9 >= _a6_slotarr->length) { vader_trap("array index out of bounds"); }
                                t0 = vader_array_ref_load_obj(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l9);
                                l10 = ((vader_struct_vader_bytecode_BcFunction_t*) t0)->f_name;
                                t3 = concat_3(2022u, l10, 989u);
                                std_abort_todo(t3);
                            } else {
                            }
                            t2 = (l8 + INT64_C(1));
                            l8 = (size_t) (int64_t) t2;
                            goto loop_33;
                        } else {
                        }
                    }
                }
                if (l6 == 0u) {
                    l11 = 914u;
                } else {
                    l11 = l6;
                }
                vader_array_push((vader_array_t*) l2, vader_box_string(167u, l11));
                t2 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t2;
                goto loop_9;
            } else {
            }
        }
    }
    vader_array_t* _a7_arr = vader_array_new(8u, 0u, 0u, 167u);
    l12 = (void*) _a7_arr;
    vader_array_t* _a8_arr = vader_array_new(6u, 0u, 12u, 165u);
    l13 = (void*) _a8_arr;
    vader_array_t* _a9_arr = vader_array_new(9u, 0u, 7u, 170u);
    l14 = (void*) _a9_arr;
    vader_struct_std_collections_MutableMap__string__bool_t* _a10_obj = (vader_struct_std_collections_MutableMap__string__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__bool_t));
    vader_obj_header_init(_a10_obj, 357u);
    _a10_obj->f_ekeys = l12;
    _a10_obj->f_evals = l13;
    _a10_obj->f_index = l14;
    _a10_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a10_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a10_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    t0 = (void*) _a10_obj;
    vader_struct_std_collections_MutableSet__string_t* _a11_obj = (vader_struct_std_collections_MutableSet__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__string_t));
    vader_obj_header_init(_a11_obj, 378u);
    _a11_obj->f_inner = t0;
    l12 = (void*) _a11_obj;
    l13 = l2;
    l3 = ((vader_array_t*) l13)->length;
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_118: {
            if ((l4 < l3)) {
                vader_array_t* _a12_slotarr = ((vader_array_t*) l13);
                if (_a12_slotarr->buf != NULL && _a12_slotarr->buf->header.forward != NULL) { _a12_slotarr->buf = vader_array_buf_forward(_a12_slotarr->buf); }
                if ((size_t) l4 >= _a12_slotarr->length) { vader_trap("array index out of bounds"); }
                t6 = vader_array_box_slots(_a12_slotarr->buf)[_a12_slotarr->offset + (size_t) l4];
                l6 = t6.payload.s;
                t5 = std_collections_contains_key__string__bool(((vader_struct_std_collections_MutableSet__string_t*) l12)->f_inner, l6);
                if (t5) {
                    t3 = concat_3(2021u, l6, 1023u);
                    std_abort_todo(t3);
                } else {
                }
                std_collections_add__string(l12, l6);
                t2 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t2;
                goto loop_118;
            } else {
            }
        }
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_string_t vader_c_emit_user_extern_shim(void* l0, vader_string_t l1, void* l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l13 = NULL;
    void* l19 = NULL;
    void* l22 = NULL;
    void* l31 = NULL;
    void* l36 = NULL;
    void* l37 = NULL;
    void* l43 = NULL;
    void* l47 = NULL;
    void* l52 = NULL;
    void* l53 = NULL;
    void* l59 = NULL;
    void* l63 = NULL;
    void* l69 = NULL;
    void* l74 = NULL;
    void* l79 = NULL;
    void* l85 = NULL;
    void* l89 = NULL;
    void* l94 = NULL;
    void* l99 = NULL;
    void* l103 = NULL;
    size_t l10, l11, l14, l20, l23, l30, l32, l38, l42, l44, l48, l54, l58, l60, l64, l68, l70, l75, l80, l86, l90, l95, l100, l104;
    int32_t l12, l25, l26, l27, l35, l51, l78;
    uint64_t l15, l16, l21, l24, l33, l39, l45, l49, l55, l61, l65, l71, l72, l76, l81, l82, l83, l87, l91, l92, l96, l97, l101, l105;
    vader_string_t l17 = 0;
    vader_string_t l18 = 0;
    vader_string_t l28 = 0;
    vader_string_t l29 = 0;
    vader_string_t l34 = 0;
    vader_string_t l40 = 0;
    vader_string_t l41 = 0;
    vader_string_t l46 = 0;
    vader_string_t l50 = 0;
    vader_string_t l56 = 0;
    vader_string_t l57 = 0;
    vader_string_t l62 = 0;
    vader_string_t l66 = 0;
    vader_string_t l67 = 0;
    vader_string_t l73 = 0;
    vader_string_t l77 = 0;
    vader_string_t l84 = 0;
    vader_string_t l88 = 0;
    vader_string_t l93 = 0;
    vader_string_t l98 = 0;
    vader_string_t l102 = 0;
    vader_string_t l106 = 0;
    bool l107;
    bool t0;
    int64_t t1;
    vader_string_t t2 = 0;
    vader_box_t t3 = vader_box_null();
    size_t t4;
    int32_t t5;
    vader_box_t* gc_roots[1] = { &t3 };
    void** gc_raw_roots[29] = { &l0, &l2, &l3, &l4, &l5, &l6, &l7, &l8, &l9, &l13, &l19, &l22, &l31, &l36, &l37, &l43, &l47, &l52, &l53, &l59, &l63, &l69, &l74, &l79, &l85, &l89, &l94, &l99, &l103 };
    vader_string_t* gc_atom_roots[24] = { &l1, &l17, &l18, &l28, &l29, &l34, &l40, &l41, &l46, &l50, &l56, &l57, &l62, &l66, &l67, &l73, &l77, &l84, &l88, &l93, &l98, &l102, &l106, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 29u, gc_roots, gc_raw_roots, 0u, NULL, 24u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_bytecode_BcImport_t*) l0)->f_signature;
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 167u);
    l4 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(8u, 0u, 0u, 167u);
    l5 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(8u, 0u, 0u, 167u);
    l6 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(8u, 0u, 0u, 167u);
    l7 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_new(8u, 0u, 0u, 167u);
    l8 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_new(8u, 0u, 0u, 167u);
    l9 = (void*) _a5_arr;
    l10 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) l3)->f_params)->length;
    l11 = (size_t) (int64_t) INT64_C(0);
    {
        loop_20: {
            if ((l11 < l10)) {
                vader_array_t* _a6_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) l3)->f_param_types);
                if (_a6_slotarr->buf != NULL && _a6_slotarr->buf->header.forward != NULL) { _a6_slotarr->buf = vader_array_buf_forward(_a6_slotarr->buf); }
                if ((size_t) l11 >= _a6_slotarr->length) { vader_trap("array index out of bounds"); }
                l12 = ((int32_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l11];
                t0 = vader_c_emit_is_abi_array(l2, l12);
                if (t0) {
                    l13 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(96));
                    l14 = (size_t) (int64_t) INT64_C(0);
                    l14 = std_core_write_string_at(l13, l14, 2357u);
                    t1 = ((int64_t) (size_t) l11);
                    l15 = (uint64_t) (int64_t) t1;
                    l14 = std_core_write_unsigned(l13, l14, l15);
                    l14 = std_core_write_string_at(l13, l14, 78u);
                    t1 = ((int64_t) (size_t) l11);
                    l16 = (uint64_t) (int64_t) t1;
                    l14 = std_core_write_unsigned(l13, l14, l16);
                    l14 = std_core_write_string_at(l13, l14, 349u);
                    l17 = std_core_finish_buffer(l13, l14);
                    vader_array_push((vader_array_t*) l5, vader_box_string(167u, l17));
                    t0 = vader_c_emit_param_is_mutable(l3, l11);
                    if (t0) {
                        l19 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(33));
                        l20 = (size_t) (int64_t) INT64_C(0);
                        l20 = std_core_write_string_at(l19, l20, 317u);
                        t1 = ((int64_t) (size_t) l11);
                        l21 = (uint64_t) (int64_t) t1;
                        l20 = std_core_write_unsigned(l19, l20, l21);
                        l20 = std_core_write_string_at(l19, l20, 424u);
                        l18 = std_core_finish_buffer(l19, l20);
                    } else {
                        l22 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(25));
                        l23 = (size_t) (int64_t) INT64_C(0);
                        l23 = std_core_write_string_at(l22, l23, 1991u);
                        t1 = ((int64_t) (size_t) l11);
                        l24 = (uint64_t) (int64_t) t1;
                        l23 = std_core_write_unsigned(l22, l23, l24);
                        l23 = std_core_write_string_at(l22, l23, 424u);
                        l18 = std_core_finish_buffer(l22, l23);
                    }
                    vader_array_push((vader_array_t*) l4, vader_box_string(167u, l18));
                } else {
                    vader_array_t* _a7_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) l3)->f_param_types);
                    if (_a7_slotarr->buf != NULL && _a7_slotarr->buf->header.forward != NULL) { _a7_slotarr->buf = vader_array_buf_forward(_a7_slotarr->buf); }
                    if ((size_t) l11 >= _a7_slotarr->length) { vader_trap("array index out of bounds"); }
                    l25 = ((int32_t*) _a7_slotarr->buf->slots)[_a7_slotarr->offset + (size_t) l11];
                    t2 = vader_c_emit_mirrored_c_struct(l2, l25);
                    if (t2 != 0u) {
                        vader_array_t* _a8_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) l3)->f_param_types);
                        if (_a8_slotarr->buf != NULL && _a8_slotarr->buf->header.forward != NULL) { _a8_slotarr->buf = vader_array_buf_forward(_a8_slotarr->buf); }
                        if ((size_t) l11 >= _a8_slotarr->length) { vader_trap("array index out of bounds"); }
                        l26 = ((int32_t*) _a8_slotarr->buf->slots)[_a8_slotarr->offset + (size_t) l11];
                        l29 = vader_c_emit_mirrored_c_struct(l2, l26);
                        vader_array_t* _a9_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) l3)->f_param_types);
                        if (_a9_slotarr->buf != NULL && _a9_slotarr->buf->header.forward != NULL) { _a9_slotarr->buf = vader_array_buf_forward(_a9_slotarr->buf); }
                        if ((size_t) l11 >= _a9_slotarr->length) { vader_trap("array index out of bounds"); }
                        l27 = ((int32_t*) _a9_slotarr->buf->slots)[_a9_slotarr->offset + (size_t) l11];
                        t2 = vader_c_emit_bc_struct_name(l2, l27);
                        l28 = vader_c_emit_struct_c_name(t2);
                        l30 = vader_host_std_core_byte_len(l29);
                        l31 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(29) + l30));
                        l32 = (size_t) (int64_t) INT64_C(0);
                        l32 = std_core_write_string_at(l31, l32, l29);
                        l32 = std_core_write_string_at(l31, l32, 155u);
                        t1 = ((int64_t) (size_t) l11);
                        l33 = (uint64_t) (int64_t) t1;
                        l32 = std_core_write_unsigned(l31, l32, l33);
                        l32 = std_core_write_string_at(l31, l32, 88u);
                        l34 = std_core_finish_buffer(l31, l32);
                        vader_array_push((vader_array_t*) l5, vader_box_string(167u, l34));
                        vader_array_t* _a10_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) l3)->f_param_types);
                        if (_a10_slotarr->buf != NULL && _a10_slotarr->buf->header.forward != NULL) { _a10_slotarr->buf = vader_array_buf_forward(_a10_slotarr->buf); }
                        if ((size_t) l11 >= _a10_slotarr->length) { vader_trap("array index out of bounds"); }
                        l35 = ((int32_t*) _a10_slotarr->buf->slots)[_a10_slotarr->offset + (size_t) l11];
                        l36 = vader_c_emit_bc_struct_fields(l2, l35);
                        l37 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(21));
                        l38 = (size_t) (int64_t) INT64_C(0);
                        l38 = std_core_write_string_at(l37, l38, 1927u);
                        t1 = ((int64_t) (size_t) l11);
                        l39 = (uint64_t) (int64_t) t1;
                        l38 = std_core_write_unsigned(l37, l38, l39);
                        l40 = std_core_finish_buffer(l37, l38);
                        l41 = l28;
                        l42 = vader_host_std_core_byte_len(l41);
                        l43 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(27) + l42));
                        l44 = (size_t) (int64_t) INT64_C(0);
                        l44 = std_core_write_string_at(l43, l44, 279u);
                        l44 = std_core_write_string_at(l43, l44, l41);
                        l44 = std_core_write_string_at(l43, l44, 358u);
                        t1 = ((int64_t) (size_t) l11);
                        l45 = (uint64_t) (int64_t) t1;
                        l44 = std_core_write_unsigned(l43, l44, l45);
                        l44 = std_core_write_string_at(l43, l44, 318u);
                        l46 = std_core_finish_buffer(l43, l44);
                        vader_c_emit_push_member_copies(l2, l36, l40, l46, true, l5, INT32_C(0));
                        t0 = vader_c_emit_param_is_mutable(l3, l11);
                        if (t0) {
                            l47 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(22));
                            l48 = (size_t) (int64_t) INT64_C(0);
                            l48 = std_core_write_string_at(l47, l48, 258u);
                            t1 = ((int64_t) (size_t) l11);
                            l49 = (uint64_t) (int64_t) t1;
                            l48 = std_core_write_unsigned(l47, l48, l49);
                            l50 = std_core_finish_buffer(l47, l48);
                            vader_array_push((vader_array_t*) l8, vader_box_string(167u, l50));
                            vader_array_t* _a11_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) l3)->f_param_types);
                            if (_a11_slotarr->buf != NULL && _a11_slotarr->buf->header.forward != NULL) { _a11_slotarr->buf = vader_array_buf_forward(_a11_slotarr->buf); }
                            if ((size_t) l11 >= _a11_slotarr->length) { vader_trap("array index out of bounds"); }
                            l51 = ((int32_t*) _a11_slotarr->buf->slots)[_a11_slotarr->offset + (size_t) l11];
                            l52 = vader_c_emit_bc_struct_fields(l2, l51);
                            l53 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(21));
                            l54 = (size_t) (int64_t) INT64_C(0);
                            l54 = std_core_write_string_at(l53, l54, 1927u);
                            t1 = ((int64_t) (size_t) l11);
                            l55 = (uint64_t) (int64_t) t1;
                            l54 = std_core_write_unsigned(l53, l54, l55);
                            l56 = std_core_finish_buffer(l53, l54);
                            l57 = l28;
                            l58 = vader_host_std_core_byte_len(l57);
                            l59 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(27) + l58));
                            l60 = (size_t) (int64_t) INT64_C(0);
                            l60 = std_core_write_string_at(l59, l60, 279u);
                            l60 = std_core_write_string_at(l59, l60, l57);
                            l60 = std_core_write_string_at(l59, l60, 358u);
                            t1 = ((int64_t) (size_t) l11);
                            l61 = (uint64_t) (int64_t) t1;
                            l60 = std_core_write_unsigned(l59, l60, l61);
                            l60 = std_core_write_string_at(l59, l60, 318u);
                            l62 = std_core_finish_buffer(l59, l60);
                            vader_c_emit_push_member_copies(l2, l52, l56, l62, false, l7, INT32_C(0));
                        } else {
                        }
                        l63 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(22));
                        l64 = (size_t) (int64_t) INT64_C(0);
                        l64 = std_core_write_string_at(l63, l64, 260u);
                        t1 = ((int64_t) (size_t) l11);
                        l65 = (uint64_t) (int64_t) t1;
                        l64 = std_core_write_unsigned(l63, l64, l65);
                        l66 = std_core_finish_buffer(l63, l64);
                        vader_array_push((vader_array_t*) l4, vader_box_string(167u, l66));
                    } else {
                        t0 = vader_c_emit_is_param_by_address(l3, l11);
                        if (t0) {
                            vader_array_t* _a12_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) l3)->f_params);
                            if (_a12_slotarr->buf != NULL && _a12_slotarr->buf->header.forward != NULL) { _a12_slotarr->buf = vader_array_buf_forward(_a12_slotarr->buf); }
                            if ((size_t) l11 >= _a12_slotarr->length) { vader_trap("array index out of bounds"); }
                            t3 = vader_array_read_u8(_a12_slotarr, _a12_slotarr->offset + (size_t) l11, 173u);
                            l67 = vader_c_emit_c_type_for_val_bare(((uint8_t) t3.payload.i));
                            l68 = vader_host_std_core_byte_len(l67);
                            l69 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(47) + l68));
                            l70 = (size_t) (int64_t) INT64_C(0);
                            l70 = std_core_write_string_at(l69, l70, l67);
                            l70 = std_core_write_string_at(l69, l70, 155u);
                            t1 = ((int64_t) (size_t) l11);
                            l71 = (uint64_t) (int64_t) t1;
                            l70 = std_core_write_unsigned(l69, l70, l71);
                            l70 = std_core_write_string_at(l69, l70, 76u);
                            t1 = ((int64_t) (size_t) l11);
                            l72 = (uint64_t) (int64_t) t1;
                            l70 = std_core_write_unsigned(l69, l70, l72);
                            l70 = std_core_write_string_at(l69, l70, 494u);
                            l73 = std_core_finish_buffer(l69, l70);
                            vader_array_push((vader_array_t*) l5, vader_box_string(167u, l73));
                            l74 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(30));
                            l75 = (size_t) (int64_t) INT64_C(0);
                            l75 = std_core_write_string_at(l74, l75, 316u);
                            t1 = ((int64_t) (size_t) l11);
                            l76 = (uint64_t) (int64_t) t1;
                            l75 = std_core_write_unsigned(l74, l75, l76);
                            l77 = std_core_finish_buffer(l74, l75);
                            vader_array_push((vader_array_t*) l4, vader_box_string(167u, l77));
                        } else {
                            vader_array_t* _a13_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) l3)->f_param_types);
                            if (_a13_slotarr->buf != NULL && _a13_slotarr->buf->header.forward != NULL) { _a13_slotarr->buf = vader_array_buf_forward(_a13_slotarr->buf); }
                            if ((size_t) l11 >= _a13_slotarr->length) { vader_trap("array index out of bounds"); }
                            l78 = ((int32_t*) _a13_slotarr->buf->slots)[_a13_slotarr->offset + (size_t) l11];
                            t0 = vader_c_emit_is_abi_nullable_pointer(l2, l78);
                            if (t0) {
                                l79 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(140));
                                l80 = (size_t) (int64_t) INT64_C(0);
                                l80 = std_core_write_string_at(l79, l80, 2386u);
                                t1 = ((int64_t) (size_t) l11);
                                l81 = (uint64_t) (int64_t) t1;
                                l80 = std_core_write_unsigned(l79, l80, l81);
                                l80 = std_core_write_string_at(l79, l80, 66u);
                                t1 = ((int64_t) (size_t) l11);
                                l82 = (uint64_t) (int64_t) t1;
                                l80 = std_core_write_unsigned(l79, l80, l82);
                                l80 = std_core_write_string_at(l79, l80, 428u);
                                t1 = ((int64_t) (size_t) l11);
                                l83 = (uint64_t) (int64_t) t1;
                                l80 = std_core_write_unsigned(l79, l80, l83);
                                l80 = std_core_write_string_at(l79, l80, 420u);
                                l84 = std_core_finish_buffer(l79, l80);
                                vader_array_push((vader_array_t*) l5, vader_box_string(167u, l84));
                                l85 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(21));
                                l86 = (size_t) (int64_t) INT64_C(0);
                                l86 = std_core_write_string_at(l85, l86, 1927u);
                                t1 = ((int64_t) (size_t) l11);
                                l87 = (uint64_t) (int64_t) t1;
                                l86 = std_core_write_unsigned(l85, l86, l87);
                                l88 = std_core_finish_buffer(l85, l86);
                                vader_array_push((vader_array_t*) l4, vader_box_string(167u, l88));
                            } else {
                                vader_array_t* _a14_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) l3)->f_params);
                                if (_a14_slotarr->buf != NULL && _a14_slotarr->buf->header.forward != NULL) { _a14_slotarr->buf = vader_array_buf_forward(_a14_slotarr->buf); }
                                if ((size_t) l11 >= _a14_slotarr->length) { vader_trap("array index out of bounds"); }
                                t3 = vader_array_read_u8(_a14_slotarr, _a14_slotarr->offset + (size_t) l11, 173u);
                                if (((int32_t) t3.payload.i) == INT32_C(14)) {
                                    l89 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(80));
                                    l90 = (size_t) (int64_t) INT64_C(0);
                                    l90 = std_core_write_string_at(l89, l90, 1401u);
                                    t1 = ((int64_t) (size_t) l11);
                                    l91 = (uint64_t) (int64_t) t1;
                                    l90 = std_core_write_unsigned(l89, l90, l91);
                                    l90 = std_core_write_string_at(l89, l90, 85u);
                                    t1 = ((int64_t) (size_t) l11);
                                    l92 = (uint64_t) (int64_t) t1;
                                    l90 = std_core_write_unsigned(l89, l90, l92);
                                    l90 = std_core_write_string_at(l89, l90, 349u);
                                    l93 = std_core_finish_buffer(l89, l90);
                                    vader_array_push((vader_array_t*) l5, vader_box_string(167u, l93));
                                    l94 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(66));
                                    l95 = (size_t) (int64_t) INT64_C(0);
                                    l95 = std_core_write_string_at(l94, l95, 2343u);
                                    t1 = ((int64_t) (size_t) l11);
                                    l96 = (uint64_t) (int64_t) t1;
                                    l95 = std_core_write_unsigned(l94, l95, l96);
                                    l95 = std_core_write_string_at(l94, l95, 374u);
                                    t1 = ((int64_t) (size_t) l11);
                                    l97 = (uint64_t) (int64_t) t1;
                                    l95 = std_core_write_unsigned(l94, l95, l97);
                                    l95 = std_core_write_string_at(l94, l95, 349u);
                                    l98 = std_core_finish_buffer(l94, l95);
                                    vader_array_push((vader_array_t*) l6, vader_box_string(167u, l98));
                                    l99 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(21));
                                    l100 = (size_t) (int64_t) INT64_C(0);
                                    l100 = std_core_write_string_at(l99, l100, 1316u);
                                    t1 = ((int64_t) (size_t) l11);
                                    l101 = (uint64_t) (int64_t) t1;
                                    l100 = std_core_write_unsigned(l99, l100, l101);
                                    l102 = std_core_finish_buffer(l99, l100);
                                    vader_array_push((vader_array_t*) l4, vader_box_string(167u, l102));
                                } else {
                                    l103 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(21));
                                    l104 = (size_t) (int64_t) INT64_C(0);
                                    l104 = std_core_write_string_at(l103, l104, 1146u);
                                    t1 = ((int64_t) (size_t) l11);
                                    l105 = (uint64_t) (int64_t) t1;
                                    l104 = std_core_write_unsigned(l103, l104, l105);
                                    l106 = std_core_finish_buffer(l103, l104);
                                    vader_array_push((vader_array_t*) l4, vader_box_string(167u, l106));
                                }
                            }
                        }
                    }
                }
                t1 = (l11 + INT64_C(1));
                l11 = (size_t) (int64_t) t1;
                goto loop_20;
            } else {
            }
        }
    }
    t4 = ((vader_array_t*) l8)->length;
    if ((t4 > INT64_C(0))) {
        l17 = std_string_join(l8, 365u);
        l10 = vader_host_std_core_byte_len(l17);
        l13 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(47) + l10));
        l10 = (size_t) (int64_t) INT64_C(0);
        l10 = std_core_write_string_at(l13, l10, 2389u);
        t4 = ((vader_array_t*) l8)->length;
        t1 = ((int64_t) (size_t) t4);
        l15 = (uint64_t) (int64_t) t1;
        l10 = std_core_write_unsigned(l13, l10, l15);
        l10 = std_core_write_string_at(l13, l10, 853u);
        l10 = std_core_write_string_at(l13, l10, l17);
        l10 = std_core_write_string_at(l13, l10, 208u);
        l17 = std_core_finish_buffer(l13, l10);
        vader_array_push((vader_array_t*) l5, vader_box_string(167u, l17));
        l13 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(64));
        l10 = (size_t) (int64_t) INT64_C(0);
        l10 = std_core_write_string_at(l13, l10, 822u);
        t4 = ((vader_array_t*) l8)->length;
        t1 = ((int64_t) (size_t) t4);
        l15 = (uint64_t) (int64_t) t1;
        l10 = std_core_write_unsigned(l13, l10, l15);
        l10 = std_core_write_string_at(l13, l10, 349u);
        l17 = std_core_finish_buffer(l13, l10);
        vader_array_push((vader_array_t*) l5, vader_box_string(167u, l17));
        vader_array_push_all((vader_array_t*) l9, (vader_array_t*) l7);
        vader_array_clear((vader_array_t*) l7);
        vader_array_push((vader_array_t*) l7, vader_box_string(167u, 821u));
        vader_array_push_all((vader_array_t*) l7, (vader_array_t*) l9);
    } else {
    }
    l17 = ((vader_struct_vader_bytecode_BcImport_t*) l0)->f_extern_name;
    l18 = std_string_join(l4, 365u);
    l17 = concat_4(l17, 278u, l18, 318u);
    if (((vader_struct_vader_bytecode_BcSignature_t*) l3)->f_result == INT32_C(16)) {
        l18 = concat_2(l17, 494u);
        vader_array_push((vader_array_t*) l5, vader_box_string(167u, l18));
        l4 = l7;
        l10 = ((vader_array_t*) l4)->length;
        l11 = (size_t) (int64_t) INT64_C(0);
        {
            loop_889: {
                if ((l11 < l10)) {
                    vader_array_t* _a15_slotarr = ((vader_array_t*) l4);
                    if (_a15_slotarr->buf != NULL && _a15_slotarr->buf->header.forward != NULL) { _a15_slotarr->buf = vader_array_buf_forward(_a15_slotarr->buf); }
                    if ((size_t) l11 >= _a15_slotarr->length) { vader_trap("array index out of bounds"); }
                    t3 = vader_array_box_slots(_a15_slotarr->buf)[_a15_slotarr->offset + (size_t) l11];
                    l18 = t3.payload.s;
                    vader_array_push((vader_array_t*) l5, vader_box_string(167u, l18));
                    t1 = (l11 + INT64_C(1));
                    l11 = (size_t) (int64_t) t1;
                    goto loop_889;
                } else {
                }
            }
        }
        l4 = l6;
        l10 = ((vader_array_t*) l4)->length;
        l11 = (size_t) (int64_t) INT64_C(0);
        {
            loop_918: {
                if ((l11 < l10)) {
                    vader_array_t* _a16_slotarr = ((vader_array_t*) l4);
                    if (_a16_slotarr->buf != NULL && _a16_slotarr->buf->header.forward != NULL) { _a16_slotarr->buf = vader_array_buf_forward(_a16_slotarr->buf); }
                    if ((size_t) l11 >= _a16_slotarr->length) { vader_trap("array index out of bounds"); }
                    t3 = vader_array_box_slots(_a16_slotarr->buf)[_a16_slotarr->offset + (size_t) l11];
                    l18 = t3.payload.s;
                    vader_array_push((vader_array_t*) l5, vader_box_string(167u, l18));
                    t1 = (l11 + INT64_C(1));
                    l11 = (size_t) (int64_t) t1;
                    goto loop_918;
                } else {
                }
            }
        }
        vader_array_push((vader_array_t*) l5, vader_box_string(167u, 1986u));
    } else {
        l12 = ((vader_struct_vader_bytecode_BcSignature_t*) l3)->f_result_type;
        t0 = vader_c_emit_is_abi_nullable_pointer(l2, l12);
        if (t0) {
            t5 = vader_c_emit_prim_tag(l2, (uint8_t) (int32_t) INT32_C(17));
            l18 = vader_c_emit_tag_u(t5, 565u);
            l28 = concat_3(2387u, l17, 494u);
            vader_array_push((vader_array_t*) l5, vader_box_string(167u, l28));
            l4 = l7;
            l10 = ((vader_array_t*) l4)->length;
            l11 = (size_t) (int64_t) INT64_C(0);
            {
                loop_972: {
                    if ((l11 < l10)) {
                        vader_array_t* _a17_slotarr = ((vader_array_t*) l4);
                        if (_a17_slotarr->buf != NULL && _a17_slotarr->buf->header.forward != NULL) { _a17_slotarr->buf = vader_array_buf_forward(_a17_slotarr->buf); }
                        if ((size_t) l11 >= _a17_slotarr->length) { vader_trap("array index out of bounds"); }
                        t3 = vader_array_box_slots(_a17_slotarr->buf)[_a17_slotarr->offset + (size_t) l11];
                        l28 = t3.payload.s;
                        vader_array_push((vader_array_t*) l5, vader_box_string(167u, l28));
                        t1 = (l11 + INT64_C(1));
                        l11 = (size_t) (int64_t) t1;
                        goto loop_972;
                    } else {
                    }
                }
            }
            l4 = l6;
            l10 = ((vader_array_t*) l4)->length;
            l11 = (size_t) (int64_t) INT64_C(0);
            {
                loop_1001: {
                    if ((l11 < l10)) {
                        vader_array_t* _a18_slotarr = ((vader_array_t*) l4);
                        if (_a18_slotarr->buf != NULL && _a18_slotarr->buf->header.forward != NULL) { _a18_slotarr->buf = vader_array_buf_forward(_a18_slotarr->buf); }
                        if ((size_t) l11 >= _a18_slotarr->length) { vader_trap("array index out of bounds"); }
                        t3 = vader_array_box_slots(_a18_slotarr->buf)[_a18_slotarr->offset + (size_t) l11];
                        l28 = t3.payload.s;
                        vader_array_push((vader_array_t*) l5, vader_box_string(167u, l28));
                        t1 = (l11 + INT64_C(1));
                        l11 = (size_t) (int64_t) t1;
                        goto loop_1001;
                    } else {
                    }
                }
            }
            l18 = concat_3(1982u, l18, 367u);
            vader_array_push((vader_array_t*) l5, vader_box_string(167u, l18));
        } else {
            l12 = ((vader_struct_vader_bytecode_BcSignature_t*) l3)->f_result_type;
            t0 = vader_c_emit_is_abi_nullable_string(l2, l12);
            if (t0) {
                t5 = vader_c_emit_prim_tag(l2, (uint8_t) (int32_t) INT32_C(14));
                l18 = vader_c_emit_tag_u(t5, 2091u);
                l28 = concat_3(1402u, l17, 494u);
                vader_array_push((vader_array_t*) l5, vader_box_string(167u, l28));
                l4 = l7;
                l10 = ((vader_array_t*) l4)->length;
                l11 = (size_t) (int64_t) INT64_C(0);
                {
                    loop_1060: {
                        if ((l11 < l10)) {
                            vader_array_t* _a19_slotarr = ((vader_array_t*) l4);
                            if (_a19_slotarr->buf != NULL && _a19_slotarr->buf->header.forward != NULL) { _a19_slotarr->buf = vader_array_buf_forward(_a19_slotarr->buf); }
                            if ((size_t) l11 >= _a19_slotarr->length) { vader_trap("array index out of bounds"); }
                            t3 = vader_array_box_slots(_a19_slotarr->buf)[_a19_slotarr->offset + (size_t) l11];
                            l28 = t3.payload.s;
                            vader_array_push((vader_array_t*) l5, vader_box_string(167u, l28));
                            t1 = (l11 + INT64_C(1));
                            l11 = (size_t) (int64_t) t1;
                            goto loop_1060;
                        } else {
                        }
                    }
                }
                l18 = concat_3(2328u, l18, 368u);
                vader_array_push((vader_array_t*) l5, vader_box_string(167u, l18));
                l4 = l6;
                l10 = ((vader_array_t*) l4)->length;
                l11 = (size_t) (int64_t) INT64_C(0);
                {
                    loop_1097: {
                        if ((l11 < l10)) {
                            vader_array_t* _a20_slotarr = ((vader_array_t*) l4);
                            if (_a20_slotarr->buf != NULL && _a20_slotarr->buf->header.forward != NULL) { _a20_slotarr->buf = vader_array_buf_forward(_a20_slotarr->buf); }
                            if ((size_t) l11 >= _a20_slotarr->length) { vader_trap("array index out of bounds"); }
                            t3 = vader_array_box_slots(_a20_slotarr->buf)[_a20_slotarr->offset + (size_t) l11];
                            l18 = t3.payload.s;
                            vader_array_push((vader_array_t*) l5, vader_box_string(167u, l18));
                            t1 = (l11 + INT64_C(1));
                            l11 = (size_t) (int64_t) t1;
                            goto loop_1097;
                        } else {
                        }
                    }
                }
                vader_array_push((vader_array_t*) l5, vader_box_string(167u, 1981u));
            } else {
                if (((vader_struct_vader_bytecode_BcSignature_t*) l3)->f_result == INT32_C(14)) {
                    l18 = concat_3(1402u, l17, 494u);
                    vader_array_push((vader_array_t*) l5, vader_box_string(167u, l18));
                    l4 = l7;
                    l10 = ((vader_array_t*) l4)->length;
                    l11 = (size_t) (int64_t) INT64_C(0);
                    {
                        loop_1142: {
                            if ((l11 < l10)) {
                                vader_array_t* _a21_slotarr = ((vader_array_t*) l4);
                                if (_a21_slotarr->buf != NULL && _a21_slotarr->buf->header.forward != NULL) { _a21_slotarr->buf = vader_array_buf_forward(_a21_slotarr->buf); }
                                if ((size_t) l11 >= _a21_slotarr->length) { vader_trap("array index out of bounds"); }
                                t3 = vader_array_box_slots(_a21_slotarr->buf)[_a21_slotarr->offset + (size_t) l11];
                                l18 = t3.payload.s;
                                vader_array_push((vader_array_t*) l5, vader_box_string(167u, l18));
                                t1 = (l11 + INT64_C(1));
                                l11 = (size_t) (int64_t) t1;
                                goto loop_1142;
                            } else {
                            }
                        }
                    }
                    vader_array_push((vader_array_t*) l5, vader_box_string(167u, 2360u));
                    l4 = l6;
                    l10 = ((vader_array_t*) l4)->length;
                    l11 = (size_t) (int64_t) INT64_C(0);
                    {
                        loop_1174: {
                            if ((l11 < l10)) {
                                vader_array_t* _a22_slotarr = ((vader_array_t*) l4);
                                if (_a22_slotarr->buf != NULL && _a22_slotarr->buf->header.forward != NULL) { _a22_slotarr->buf = vader_array_buf_forward(_a22_slotarr->buf); }
                                if ((size_t) l11 >= _a22_slotarr->length) { vader_trap("array index out of bounds"); }
                                t3 = vader_array_box_slots(_a22_slotarr->buf)[_a22_slotarr->offset + (size_t) l11];
                                l18 = t3.payload.s;
                                vader_array_push((vader_array_t*) l5, vader_box_string(167u, l18));
                                t1 = (l11 + INT64_C(1));
                                l11 = (size_t) (int64_t) t1;
                                goto loop_1174;
                            } else {
                            }
                        }
                    }
                    vader_array_push((vader_array_t*) l5, vader_box_string(167u, 1981u));
                } else {
                    t4 = ((vader_array_t*) l6)->length;
                    if (t4 == INT64_C(0)) {
                        t4 = ((vader_array_t*) l7)->length;
                        l107 = t4 == INT64_C(0);
                    } else {
                        l107 = false;
                    }
                    if (l107) {
                        l18 = concat_3(1979u, l17, 494u);
                        vader_array_push((vader_array_t*) l5, vader_box_string(167u, l18));
                    } else {
                        t2 = vader_c_emit_c_type_for_val_bare(((vader_struct_vader_bytecode_BcSignature_t*) l3)->f_result);
                        l17 = concat_4(t2, 161u, l17, 494u);
                        vader_array_push((vader_array_t*) l5, vader_box_string(167u, l17));
                        l3 = l7;
                        l10 = ((vader_array_t*) l3)->length;
                        l11 = (size_t) (int64_t) INT64_C(0);
                        {
                            loop_1242: {
                                if ((l11 < l10)) {
                                    vader_array_t* _a23_slotarr = ((vader_array_t*) l3);
                                    if (_a23_slotarr->buf != NULL && _a23_slotarr->buf->header.forward != NULL) { _a23_slotarr->buf = vader_array_buf_forward(_a23_slotarr->buf); }
                                    if ((size_t) l11 >= _a23_slotarr->length) { vader_trap("array index out of bounds"); }
                                    t3 = vader_array_box_slots(_a23_slotarr->buf)[_a23_slotarr->offset + (size_t) l11];
                                    l17 = t3.payload.s;
                                    vader_array_push((vader_array_t*) l5, vader_box_string(167u, l17));
                                    t1 = (l11 + INT64_C(1));
                                    l11 = (size_t) (int64_t) t1;
                                    goto loop_1242;
                                } else {
                                }
                            }
                        }
                        l3 = l6;
                        l10 = ((vader_array_t*) l3)->length;
                        l11 = (size_t) (int64_t) INT64_C(0);
                        {
                            loop_1271: {
                                if ((l11 < l10)) {
                                    vader_array_t* _a24_slotarr = ((vader_array_t*) l3);
                                    if (_a24_slotarr->buf != NULL && _a24_slotarr->buf->header.forward != NULL) { _a24_slotarr->buf = vader_array_buf_forward(_a24_slotarr->buf); }
                                    if ((size_t) l11 >= _a24_slotarr->length) { vader_trap("array index out of bounds"); }
                                    t3 = vader_array_box_slots(_a24_slotarr->buf)[_a24_slotarr->offset + (size_t) l11];
                                    l17 = t3.payload.s;
                                    vader_array_push((vader_array_t*) l5, vader_box_string(167u, l17));
                                    t1 = (l11 + INT64_C(1));
                                    l11 = (size_t) (int64_t) t1;
                                    goto loop_1271;
                                } else {
                                }
                            }
                        }
                        vader_array_push((vader_array_t*) l5, vader_box_string(167u, 1983u));
                    }
                }
            }
        }
    }
    l17 = std_string_join(l5, 6u);
    t2 = concat_4(l1, 176u, l17, 201u);
    { vader_string_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static uint8_t vader_c_emit_val_of(vader_box_t l0) {
    void* t0;
    if (l0.tag == 674u) {
        t0 = l0.payload.obj;
        return ((vader_struct_vader_c_emit_StackTmp_t*) t0)->f_val;
    }
    if (l0.tag == 671u) {
        t0 = l0.payload.obj;
        return ((vader_struct_vader_c_emit_StackLit_t*) t0)->f_val;
    }
    if (l0.tag == 672u) {
        t0 = l0.payload.obj;
        return ((vader_struct_vader_c_emit_StackLocalRef_t*) t0)->f_val;
    }
    if (l0.tag == 670u) {
        t0 = l0.payload.obj;
        return ((vader_struct_vader_c_emit_StackExpr_t*) t0)->f_val;
    }
    vader_unreachable("unreachable return in vader_c_emit$val_of");
}

static uint8_t vader_c_emit_val_type_of_bc_type(vader_box_t l0) {
    void* t0;
    if (l0.tag == 505u) {
        t0 = l0.payload.obj;
        return ((vader_struct_vader_bytecode_BcPrimitive_t*) t0)->f_val;
    }
    if (l0.tag == 509u) {
        return (uint8_t) (int32_t) INT32_C(18);
    }
    if (l0.tag == 496u) {
        return (uint8_t) (int32_t) INT32_C(18);
    }
    if (l0.tag == 499u) {
        return (uint8_t) (int32_t) INT32_C(18);
    }
    if (l0.tag == 510u) {
        return (uint8_t) (int32_t) INT32_C(19);
    }
    if (l0.tag == 506u) {
        return (uint8_t) (int32_t) INT32_C(19);
    }
    vader_unreachable("unreachable return in vader_c_emit$val_type_of_bc_type");
}

static uint8_t vader_c_emit_val_type_of_field(void* l0, int32_t l1) {
    size_t l2;
    int64_t t0;
    vader_box_t t1;
    uint8_t t2;
    t0 = ((int64_t) (int32_t) l1);
    l2 = (size_t) (int64_t) t0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    if ((size_t) l2 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
    t1 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
    t2 = vader_c_emit_val_type_of_bc_type(t1);
    return t2;
}

static vader_string_t vader_c_emit_vtable_helper_name(vader_string_t l0) {
    vader_string_t l1 = 0;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    void** gc_raw_roots[1] = { &t0 };
    vader_string_t* gc_atom_roots[3] = { &l0, &l1, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = std_string_split(l0, 407u);
    t1 = std_string_join(t0, 880u);
    l1 = vader_c_emit_sanitise(t1);
    t1 = concat_2(2370u, l1);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_c_emit_vtable_sig_for_row(void* l0, void* l1) {
    void* l2 = NULL;
    void* l5 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l10 = NULL;
    size_t l3, l6, l9;
    bool l4, l13;
    uint8_t l11, l12;
    int32_t l14, l15;
    void* t0 = NULL;
    int32_t t1;
    int64_t t2;
    void** gc_raw_roots[8] = { &l0, &l1, &l2, &l5, &l7, &l8, &l10, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 8u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_functions;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_VtableRow_t*) l1)->f_entries);
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    if ((size_t) INT32_C(0) >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
    t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT32_C(0));
    t1 = ((vader_struct_vader_bytecode_VtableEntry_t*) t0)->f_fn_index;
    t2 = ((int64_t) (int32_t) t1);
    l3 = (size_t) (int64_t) t2;
    vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
    if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
    if ((size_t) l3 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
    t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l3);
    l2 = ((vader_struct_vader_bytecode_BcFunction_t*) t0)->f_signature;
    l4 = true;
    l5 = ((vader_struct_vader_bytecode_VtableRow_t*) l1)->f_entries;
    vader_array_t* _a2_slotarr = ((vader_array_t*) l5);
    if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
    l3 = ((vader_array_t*) l5)->length;
    l6 = (size_t) (int64_t) INT64_C(0);
    {
        loop_24: {
            if ((l6 < l3)) {
                if ((size_t) l6 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                l7 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l6);
                l8 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct_vader_c_emit_EmitCtx_t*) l0)->f_module)->f_functions;
                t1 = ((vader_struct_vader_bytecode_VtableEntry_t*) l7)->f_fn_index;
                t2 = ((int64_t) (int32_t) t1);
                l9 = (size_t) (int64_t) t2;
                vader_array_t* _a3_slotarr = ((vader_array_t*) l8);
                if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                if ((size_t) l9 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                l10 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l9);
                l11 = ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l10)->f_signature)->f_result;
                l12 = ((vader_struct_vader_bytecode_BcSignature_t*) l2)->f_result;
                if (l11 != l12) {
                    l13 = true;
                } else {
                    l14 = ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l10)->f_signature)->f_result_type;
                    l15 = ((vader_struct_vader_bytecode_BcSignature_t*) l2)->f_result_type;
                    l13 = l14 != l15;
                }
                if (l13) {
                    l4 = false;
                } else {
                }
                t2 = (l6 + INT64_C(1));
                l6 = (size_t) (int64_t) t2;
                goto loop_24;
            } else {
            }
        }
    }
    if (l4) {
        { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l5 = ((vader_struct_vader_bytecode_BcSignature_t*) l2)->f_params;
    l7 = ((vader_struct_vader_bytecode_BcSignature_t*) l2)->f_param_types;
    l14 = ((vader_struct_vader_bytecode_BcSignature_t*) l2)->f_result_type;
    l2 = ((vader_struct_vader_bytecode_BcSignature_t*) l2)->f_param_names;
    vader_array_t* _a4_arr = vader_array_new(6u, 0u, 12u, 165u);
    l8 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_new(6u, 0u, 12u, 165u);
    l10 = (void*) _a5_arr;
    vader_struct_vader_bytecode_BcSignature_t* _a6_obj = (vader_struct_vader_bytecode_BcSignature_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcSignature_t));
    vader_obj_header_init(_a6_obj, 507u);
    _a6_obj->f_params = l5;
    _a6_obj->f_result = (uint8_t) (int32_t) INT32_C(19);
    _a6_obj->f_param_types = l7;
    _a6_obj->f_result_type = l14;
    _a6_obj->f_param_names = l2;
    _a6_obj->f_param_mutable = l8;
    _a6_obj->f_param_by_address = l10;
    t0 = (void*) _a6_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

