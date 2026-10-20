#include "bootstrap.split.h"

static bool vader_midir_BlockId_std_core_Equals_equals(int32_t l0, int32_t l1);
static void* vader_midir_annotate_function(void* l0);
static void vader_midir_append_alias(void* l0, int32_t l1, int32_t l2);
static vader_string_t vader_midir_array_element_name(vader_box_t l0);
static uint8_t vader_midir_array_element_val_type(vader_box_t l0);
static uint64_t vader_midir_bc_value_bits(vader_box_t l0, vader_string_t l1);
static bool vader_midir_binary_leaves_width(uint8_t l0, uint8_t l1);
static vader_box_t vader_midir_binary_width(void* l0, void* l1);
static bool vader_midir_boxed_element(vader_box_t l0);
static bool vader_midir_boxed_field(void* l0, int32_t l1, int64_t l2);
static void* vader_midir_boxed_fields_of(void* l0, int32_t l1);
static void* vader_midir_boxed_params_of(void* l0, void* l1);
static void* vader_midir_branch_on_cond(void* l0, vader_box_t l1, int32_t l2, int32_t l3, bool l4);
static vader_box_t vader_midir_build_args(void* l0, void* l1, void* l2);
static vader_box_t vader_midir_build_array_len(void* l0, void* l1);
static vader_box_t vader_midir_build_array_lit(void* l0, void* l1);
static vader_box_t vader_midir_build_array_push(void* l0, void* l1);
static vader_box_t vader_midir_build_array_slice(void* l0, void* l1);
static void vader_midir_build_assign(void* l0, void* l1);
static void vader_midir_build_back_edge(void* l0, void* l1, void* l2);
static vader_box_t vader_midir_build_binary(void* l0, void* l1);
static vader_box_t vader_midir_build_block_body(void* l0, void* l1);
static void vader_midir_build_block_into(void* l0, void* l1, int32_t l2);
static vader_box_t vader_midir_build_block_value(void* l0, void* l1, vader_box_t l2);
static vader_box_t vader_midir_build_call(void* l0, void* l1);
static vader_box_t vader_midir_build_cast(void* l0, void* l1);
static vader_box_t vader_midir_build_cast_source(void* l0, void* l1);
static vader_box_t vader_midir_build_cell_get(void* l0, void* l1);
static vader_box_t vader_midir_build_cell_new(void* l0, void* l1);
static void* vader_midir_build_cfg_signature(void* l0, vader_box_t l1, void* l2, void* l3);
static vader_box_t vader_midir_build_data_const(void* l0, void* l1);
static vader_box_t vader_midir_build_expr(void* l0, vader_box_t l1);
static void vader_midir_build_expr_into(void* l0, vader_box_t l1, int32_t l2);
static vader_box_t vader_midir_build_extern_args(void* l0, void* l1, void* l2, void* l3, vader_string_t l4);
static vader_box_t vader_midir_build_field_access(void* l0, void* l1);
static vader_box_t vader_midir_build_global_get(void* l0, void* l1);
static vader_box_t vader_midir_build_held(void* l0, vader_box_t l1, vader_box_t l2);
static vader_box_t vader_midir_build_ident(void* l0, void* l1);
static vader_box_t vader_midir_build_if(void* l0, void* l1, vader_box_t l2);
static void vader_midir_build_if_arm(void* l0, void* l1, vader_box_t l2);
static void* vader_midir_build_impl_table_from_vtable(void* l0, void* l1, void* l2);
static vader_box_t vader_midir_build_index(void* l0, void* l1);
static vader_box_t vader_midir_build_intrinsic_call(void* l0, void* l1);
static void vader_midir_build_labelled_block(void* l0, void* l1);
static void vader_midir_build_loop(void* l0, void* l1);
static vader_box_t vader_midir_build_make_closure(void* l0, void* l1);
static vader_box_t vader_midir_build_short_circuit(void* l0, void* l1, vader_box_t l2);
static void vader_midir_build_stmt(void* l0, vader_box_t l1);
static vader_box_t vader_midir_build_stored(void* l0, vader_box_t l1);
static vader_box_t vader_midir_build_struct_lit(void* l0, void* l1);
static vader_box_t vader_midir_build_type_check(void* l0, void* l1);
static vader_box_t vader_midir_build_type_const(void* l0, void* l1);
static vader_box_t vader_midir_build_unary(void* l0, void* l1);
static vader_box_t vader_midir_build_union_field(void* l0, void* l1);
static vader_box_t vader_midir_build_unreachable_type(void* l0, vader_box_t l1, void* l2, vader_string_t l3);
static vader_box_t vader_midir_build_virtual_call(void* l0, void* l1);
static void* vader_midir_build_vtables_from_entries(void* l0, void* l1);
static vader_string_t vader_midir_c_header_of(void* l0);
static vader_string_t vader_midir_c_struct_of(void* l0);
static int32_t vader_midir_c_variadic_fixed_of(void* l0);
static vader_box_t vader_midir_call_single_dst(void* l0);
static bool vader_midir_can_pass_through_stack(vader_box_t l0, vader_box_t l1, void* l2);
static bool vader_midir_can_pass_through_terminator(vader_box_t l0, vader_box_t l1, void* l2);
static int32_t vader_midir_cast_local(void* l0, int32_t l1, vader_box_t l2, vader_string_t l3, void* l4);
static void vader_midir_cf_block(void* l0, void* l1, int32_t l2);
static void vader_midir_cf_br(void* l0, void* l1, int32_t l2);
static void vader_midir_cf_br_if(void* l0, void* l1, int32_t l2);
static void vader_midir_cf_else(void* l0, void* l1);
static void vader_midir_cf_end(void* l0, void* l1);
static void vader_midir_cf_if(void* l0, void* l1);
static void vader_midir_cf_loop(void* l0, void* l1, int32_t l2);
static void vader_midir_close_blocks(void* l0, void* l1, void* l2, int32_t l3);
static bool vader_midir_closes_loop(void* l0, int32_t l1, int32_t l2);
static vader_box_t vader_midir_closure_header_type(vader_box_t l0);
static void vader_midir_collect_baked_symbols(vader_box_t l0, void* l1);
static void* vader_midir_compact_locals(void* l0);
static bool vader_midir_compares_boxes(uint8_t l0, vader_box_t l1);
static vader_box_t vader_midir_computation_integer(vader_box_t l0, vader_box_t l1, vader_box_t l2);
static vader_box_t vader_midir_computation_width(vader_box_t l0, vader_box_t l1, vader_box_t l2);
static void* vader_midir_compute_carried_across_loop_headers(void* l0, void* l1);
static void* vader_midir_compute_dominators(void* l0, void* l1);
static void* vader_midir_compute_escaping(void* l0, void* l1);
static void* vader_midir_compute_liveness(void* l0);
static vader_box_t vader_midir_computed_type(vader_box_t l0, vader_box_t l1);
static vader_box_t vader_midir_const_accessor(void* l0, void* l1);
static void* vader_midir_convert_data_pool(void* l0);
static bool vader_midir_convert_eligible(uint8_t l0);
static vader_box_t vader_midir_convert_function(void* l0, void* l1);
static bool vader_midir_copies_cheaply(void* l0);
static void* vader_midir_count_uses(void* l0);
static vader_box_t vader_midir_debug_pos_of_span(void* l0);
static int32_t vader_midir_declare_local(void* l0, vader_string_t l1, vader_box_t l2, vader_box_t l3);
static void vader_midir_defer_or_resolve_branch(void* l0, int32_t l1, int32_t l2);
static int32_t vader_midir_destination(void* l0, int32_t l1);
static bool vader_midir_dominates(void* l0, int32_t l1, int32_t l2);
static void vader_midir_drain_pending(void* l0, int32_t l1, bool l2, int32_t l3, int32_t l4);
static vader_box_t vader_midir_dst_of(vader_box_t l0);
static vader_box_t vader_midir_element_slot(vader_box_t l0);
static void vader_midir_emit(void* l0, vader_box_t l1);
static void vader_midir_emit_body(void* l0, void* l1, int32_t l2, int32_t l3, int32_t l4);
static void vader_midir_emit_branch(void* l0, void* l1, int32_t l2, int32_t l3, int32_t l4, void* l5);
static void vader_midir_emit_call_results(void* l0, int64_t l1, void* l2, void* l3);
static void vader_midir_emit_cfg_function_body(void* l0, int32_t l1, void* l2, void* l3, bool l4);
static void vader_midir_emit_cond_branch(void* l0, void* l1, int32_t l2, void* l3, int32_t l4, int32_t l5);
static int32_t vader_midir_emit_const(void* l0, vader_box_t l1, vader_box_t l2, void* l3);
static void vader_midir_emit_const_instr(void* l0, void* l1, int64_t l2);
static void vader_midir_emit_first_get(void* l0, int64_t l1, int32_t l2, void* l3);
static void vader_midir_emit_get(void* l0, int32_t l1, void* l2);
static void vader_midir_emit_instr(void* l0, vader_box_t l1, int64_t l2);
static void vader_midir_emit_instructions(void* l0, int32_t l1, int64_t l2, int64_t l3);
static void vader_midir_emit_loop(void* l0, void* l1, int32_t l2, int32_t l3);
static void vader_midir_emit_narrowing(void* l0, uint8_t l1, void* l2);
static void vader_midir_emit_operands_into(void* l0, int64_t l1, void* l2, void* l3, void* l4);
static void vader_midir_emit_result(void* l0, int64_t l1, int32_t l2, void* l3);
static void vader_midir_emit_result_if_any(void* l0, int64_t l1, vader_box_t l2, void* l3);
static void vader_midir_emit_retag_into(void* l0, int32_t l1, bool l2, void* l3);
static void vader_midir_emit_return(void* l0, int32_t l1, void* l2);
static void vader_midir_emit_return_retag(void* l0, int32_t l1, int64_t l2, void* l3);
static void vader_midir_emit_set(void* l0, int32_t l1, void* l2);
static void vader_midir_emit_subtree(void* l0, void* l1, int32_t l2, int32_t l3);
static void vader_midir_emit_terminator(void* l0, void* l1, int32_t l2, int32_t l3, int32_t l4);
static bool vader_midir_emitted_beneath(void* l0, void* l1, void* l2, void* l3, int32_t l4);
static vader_box_t vader_midir_end_after_no_return(void* l0, void* l1, vader_box_t l2);
static bool vader_midir_ends_function(vader_box_t l0);
static bool vader_midir_entered_by_test(void* l0, void* l1, int32_t l2);
static void* vader_midir_every_operand_boxed(void* l0);
static vader_string_t vader_midir_extern_library_name(void* l0);
static vader_string_t vader_midir_extern_symbol_name(void* l0);
static vader_box_t vader_midir_field_read_type(void* l0, int32_t l1, vader_box_t l2);
static vader_box_t vader_midir_field_slot(void* l0, vader_box_t l1, vader_string_t l2);
static vader_box_t vader_midir_find_struct_field_index(void* l0, int32_t l1, vader_string_t l2);
static vader_box_t vader_midir_first_stack_operand(vader_box_t l0);
static vader_box_t vader_midir_first_terminator_operand(vader_box_t l0);
static bool vader_midir_fits_in(uint8_t l0, uint8_t l1);
static void* vader_midir_fn_metadata(void* l0);
static void* vader_midir_fold_moves(void* l0);
static void* vader_midir_fold_moves_in_block(void* l0, void* l1, void* l2, void* l3);
static void vader_midir_for_each_read_in_terminator(vader_box_t l0, void* l1);
static void vader_midir_for_each_read_local(vader_box_t l0, void* l1);
static void* vader_midir_freeze_block(void* l0);
static int32_t vader_midir_fresh_tmp(void* l0, vader_string_t l1, vader_box_t l2);
static vader_box_t vader_midir_function_called(void* l0, void* l1);
static bool vader_midir_goes_on_or_out(void* l0, void* l1, void* l2, int32_t l3);
static bool vader_midir_has_receiver(void* l0, int32_t l1);
static int32_t vader_midir_held_in(void* l0, int32_t l1, vader_box_t l2, void* l3);
static int32_t vader_midir_held_use_in(void* l0, int32_t l1, vader_box_t l2, vader_box_t l3, void* l4);
static bool vader_midir_holds_all(void* l0, void* l1);
static void* vader_midir_import_call_target(void* l0, int32_t l1);
static vader_box_t vader_midir_import_called(void* l0, void* l1);
static void vader_midir_index_by_name(void* l0, void* l1, vader_string_t l2, vader_box_t l3, int32_t l4);
static void vader_midir_index_function(void* l0, vader_string_t l1, vader_box_t l2, int32_t l3);
static void vader_midir_index_import(void* l0, vader_string_t l1, vader_box_t l2, int32_t l3);
static bool vader_midir_instruction_has_side_effect(vader_box_t l0);
static bool vader_midir_instruction_runs_code(vader_box_t l0);
static vader_box_t vader_midir_integer_member(vader_box_t l0, void* l1);
static void vader_midir_intern_data_value_strings(vader_box_t l0, void* l1);
static int32_t vader_midir_intern_string_pool(void* l0, vader_string_t l1);
static int32_t vader_midir_intersect_dom_tree(int32_t l0, int32_t l1, void* l2);
static vader_box_t vader_midir_intrinsic_op_for_name(vader_string_t l0);
static bool vader_midir_is_boxed_slot(vader_box_t l0);
static bool vader_midir_is_dest_passing_shape(vader_box_t l0);
static bool vader_midir_is_scalar_class(uint8_t l0);
static bool vader_midir_is_short_circuit_op(uint8_t l0);
static bool vader_midir_is_union_slot(vader_box_t l0);
static vader_box_t vader_midir_laid_out_fields(void* l0, vader_box_t l1);
static int64_t vader_midir_last_empty_stack_point(void* l0, int32_t l1);
static bool vader_midir_last_op_exits(void* l0);
static vader_string_t vader_midir_layout_key(void* l0, vader_string_t l1);
static bool vader_midir_leaves_at_once(void* l0, void* l1, int32_t l2, int32_t l3);
static bool vader_midir_leaves_header(void* l0, int32_t l1, int32_t l2);
static void* vader_midir_literal_slots(void* l0, vader_box_t l1);
static int32_t vader_midir_loop_exit(void* l0, void* l1, int32_t l2);
static vader_box_t vader_midir_lowered_to_bc_value(vader_box_t l0);
static void* vader_midir_make_extern_decl(void* l0);
static void* vader_midir_make_struct_decl(void* l0);
static bool vader_midir_move_retags(void* l0, void* l1);
static vader_box_t vader_midir_multi_dsts(vader_box_t l0);
static vader_box_t vader_midir_narrowed_local_width(void* l0, vader_box_t l1, vader_box_t l2);
static bool vader_midir_narrowed_read(vader_box_t l0, vader_box_t l1);
static bool vader_midir_narrower(void* l0, vader_box_t l1);
static void* vader_midir_natural_loop_bodies(void* l0, void* l1, void* l2);
static bool vader_midir_needs_ref_cast(vader_box_t l0);
static int32_t vader_midir_new_block(void* l0, void* l1);
static void* vader_midir_new_project_ctx(void* l0, void* l1);
static vader_string_t vader_midir_no_common_field(void* l0, vader_string_t l1, vader_box_t l2);
static void* vader_midir_no_hints(void);
static void vader_midir_note_params(void* l0, vader_string_t l1, vader_box_t l2, void* l3, bool l4);
static void vader_midir_note_slot_types(void* l0, vader_box_t l1);
static void vader_midir_note_struct_fields(void* l0, void* l1);
static bool vader_midir_only_jumps(void* l0, int32_t l1, int32_t l2);
static bool vader_midir_only_leaves(void* l0);
static int32_t vader_midir_open_blocks(void* l0, void* l1, int32_t l2);
static void* vader_midir_operand_edges(vader_box_t l0);
static vader_box_t vader_midir_operand_width(vader_box_t l0, void* l1);
static void* vader_midir_optimise_function(void* l0);
static int32_t vader_midir_outermost_loop_left(void* l0, void* l1, int32_t l2, int32_t l3);
static void* vader_midir_param_c_types_of(void* l0);
static void* vader_midir_params_of(void* l0, void* l1);
static void vader_midir_pin_baked_struct_types(void* l0, void* l1);
static vader_box_t vader_midir_place_slot(void* l0, vader_box_t l1, vader_box_t l2);
static int64_t vader_midir_pos_key(int32_t l0, int64_t l1);
static void* vader_midir_predecessors_of(void* l0);
static void vader_midir_push_emit(void* l0, vader_box_t l1, void* l2);
static int32_t vader_midir_push_op_with_span(void* l0, vader_box_t l1, void* l2);
static vader_box_t vader_midir_pushed_element_type(vader_box_t l0, vader_box_t l1);
static int32_t vader_midir_read_as(void* l0, int32_t l1, vader_box_t l2, void* l3);
static bool vader_midir_read_may_carry_ref(vader_box_t l0);
static vader_box_t vader_midir_read_type(vader_box_t l0, vader_box_t l1);
static void vader_midir_record_alias(void* l0, void* l1, int32_t l2, int32_t l3);
static void vader_midir_refuse_shared_identity_test(vader_string_t l0, vader_box_t l1);
static void vader_midir_refuse_shared_instance(vader_string_t l0, vader_box_t l1);
static vader_box_t vader_midir_remap_instr(vader_box_t l0, void* l1);
static int32_t vader_midir_remap_local(void* l0, int32_t l1);
static vader_box_t vader_midir_remap_local_opt(void* l0, vader_box_t l1);
static void* vader_midir_remap_locals(void* l0, void* l1);
static vader_box_t vader_midir_remap_terminator(vader_box_t l0, void* l1);
static void vader_midir_reserve_cfg_extern(void* l0, void* l1);
static void vader_midir_reserve_cfg_function(void* l0, void* l1);
static void vader_midir_reserve_cfg_struct(void* l0, void* l1);
static void* vader_midir_resolve_direct_call(void* l0, void* l1);
static vader_box_t vader_midir_resolve_fn_index(void* l0, void* l1);
static void* vader_midir_resolve_loop_frame(void* l0, vader_box_t l1);
static vader_string_t vader_midir_result_c_type_of(void* l0);
static vader_box_t vader_midir_retargeted(void* l0, vader_box_t l1);
static void* vader_midir_reverse_postorder(void* l0);
static void* vader_midir_rpo_positions(void* l0, int64_t l1);
static bool vader_midir_same_bounds(void* l0, vader_box_t l1);
static void* vader_midir_schedule_stack(void* l0);
static bool vader_midir_sets_equal(void* l0, void* l1);
static void* vader_midir_shape_of(void* l0, void* l1, void* l2);
static void* vader_midir_skip_forwarding_blocks(void* l0);
static vader_box_t vader_midir_stored_cell(void* l0, void* l1);
static vader_box_t vader_midir_stored_conversion(vader_box_t l0, vader_box_t l1);
static vader_box_t vader_midir_stored_field(void* l0, void* l1);
static vader_box_t vader_midir_stored_ident(void* l0, void* l1);
static int32_t vader_midir_stored_slot(void* l0, int32_t l1, void* l2);
static vader_box_t vader_midir_stored_test(void* l0, void* l1);
static vader_box_t vader_midir_stored_union_field(void* l0, void* l1);
static int32_t vader_midir_struct_symbol_id(vader_box_t l0);
static void vader_midir_structure_function(void* l0);
static void* vader_midir_successors_of(void* l0);
static void vader_midir_synthesise_cfg_intrinsic_wrappers(void* l0, void* l1);
static vader_box_t vader_midir_term_return_single(void* l0);
static void vader_midir_terminate(void* l0, vader_box_t l1);
static bool vader_midir_tests_its_exit(void* l0, void* l1, int32_t l2);
static bool vader_midir_try_fuse_local_field(void* l0, int32_t l1, int32_t l2);
static vader_box_t vader_midir_type_at(void* l0, int64_t l1);
static bool vader_midir_unary_leaves_width(uint8_t l0, uint8_t l1);
static vader_string_t vader_midir_vtable_key(vader_string_t l0, vader_string_t l1);
static void vader_midir_walk_rpo(void* l0, int32_t l1, void* l2, void* l3);
static vader_box_t vader_midir_with_dst(vader_box_t l0, int32_t l1);
static void* vader_midir_with_param_decorators(void* l0, void* l1);
static void* vader_midir_with_peephole_out(void* l0, void* l1);

static bool vader_midir_BlockId_std_core_Equals_equals(int32_t l0, int32_t l1) {
    int32_t l2, l3;
    l2 = l0;
    l3 = l1;
    return l2 == l3;
}

bool vader_midir_LocalId_std_core_Equals_equals(int32_t l0, int32_t l1) {
    int32_t l2, l3;
    l2 = l0;
    l3 = l1;
    return l2 == l3;
}

void* vader_midir_annotate_escape(void* l0) {
    int32_t l1, l2;
    bool l3;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l11 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    void* l17 = NULL;
    void* l18 = NULL;
    void* l21 = NULL;
    void* l25 = NULL;
    void* l27 = NULL;
    void* l28 = NULL;
    void* l30 = NULL;
    void* l32 = NULL;
    void* l35 = NULL;
    void* l36 = NULL;
    void* l37 = NULL;
    int64_t l9, l10, l12, l15, l16, l19, l20, l22, l23;
    vader_box_t l24 = vader_box_null();
    vader_string_t l26 = 0;
    vader_string_t l29 = 0;
    vader_string_t l31 = 0;
    vader_string_t l33 = 0;
    vader_string_t l34 = 0;
    vader_box_t t0 = vader_box_null();
    vader_string_t t1 = 0;
    void* t2 = NULL;
    bool t3;
    vader_box_t* gc_roots[2] = { &l24, &t0 };
    void** gc_raw_roots[21] = {
        &l0, &l4, &l5, &l6, &l7, &l8, &l11, &l13, &l14, &l17, &l18, &l21, &l25, &l27, &l28, &l30,
        &l32, &l35, &l36, &l37, &t2,
    };
    vader_string_t* gc_atom_roots[6] = { &l26, &l29, &l31, &l33, &l34, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 21u, gc_roots, gc_raw_roots, 0u, NULL, 6u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = INT32_C(0);
    l2 = INT32_C(0);
    l3 = vader_lower_opt_report_enabled();
    vader_array_t* _a0_arr = vader_array_new(143u, 0u, 13u, 1088u);
    l4 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(14u, 0u, 0u, 285u);
    l5 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(21u, 0u, 0u, 296u);
    l6 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(15u, 0u, 7u, 288u);
    l7 = (void*) _a3_arr;
    vader_struct_std_collections_MutableMap__string__Any_t* _a4_obj = (vader_struct_std_collections_MutableMap__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__Any_t));
    vader_obj_header_init(_a4_obj, 448u);
    _a4_obj->f_ekeys = l5;
    _a4_obj->f_evals = l6;
    _a4_obj->f_index = l7;
    _a4_obj->f_mask = INT64_C(0);
    _a4_obj->f_size = INT64_C(0);
    _a4_obj->f_tombs = INT64_C(0);
    l5 = (void*) _a4_obj;
    l6 = ((vader_struct_vader_midir_CFGProject_t*) l0)->f_modules;
    l7 = ((vader_struct_std_collections_MutableMap__string__vader_midir_CFGModule_t*) l6)->f_ekeys;
    l8 = ((vader_struct_std_collections_MutableMap__string__vader_midir_CFGModule_t*) l6)->f_evals;
    l9 = INT64_C(0);
    l10 = ((vader_struct_std_collections_MutableMap__string__vader_midir_CFGModule_t*) l6)->f_size;
    while ((l9 < l10)) {
        vader_array_t* _a5_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l9)
        t0 = vader_array_box_slots(_a5_slotarr->buf)[_a5_slotarr->offset + (size_t) l9];
        t1 = t0.payload.s;
        vader_array_t* _a6_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l9)
        l6 = vader_array_ref_load_obj(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l9);
        vader_array_t* _a7_arr = vader_array_new(137u, 0u, 13u, 1071u);
        l11 = (void*) _a7_arr;
        l12 = ((vader_array_t*) ((vader_struct_vader_midir_CFGModule_t*) l6)->f_functions)->length;
        vader_array_t* _a8_arr = vader_array_repeat((vader_array_t*) l11, (int64_t) l12);
        l13 = (void*) _a8_arr;
        l14 = ((vader_struct_vader_midir_CFGModule_t*) l6)->f_functions;
        l15 = ((vader_array_t*) l14)->length;
        l16 = INT64_C(0);
        while ((l16 < l15)) {
            vader_array_t* _a9_slotarr = ((vader_array_t*) l14);
            VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l16)
            t2 = vader_array_ref_load_obj(_a9_slotarr->buf, _a9_slotarr->offset + (size_t) l16);
            l17 = vader_midir_annotate_function(t2);
            l18 = ((vader_struct_vader_midir_CFGFunction_t*) l17)->f_blocks;
            l19 = ((vader_array_t*) l18)->length;
            l20 = INT64_C(0);
            while ((l20 < l19)) {
                vader_array_t* _a10_slotarr = ((vader_array_t*) l18);
                VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
                t2 = vader_array_ref_load_obj(_a10_slotarr->buf, _a10_slotarr->offset + (size_t) l20);
                l21 = ((vader_struct_vader_midir_BasicBlock_t*) t2)->f_instructions;
                l22 = ((vader_array_t*) l21)->length;
                l23 = INT64_C(0);
                while ((l23 < l22)) {
                    vader_array_t* _a11_slotarr = ((vader_array_t*) l21);
                    VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
                    l24 = vader_array_ref_load_box(_a11_slotarr->buf, _a11_slotarr->offset + (size_t) l23);
                    if (l24.tag == 1119u) {
                        l1 = vader_chk_add(i32, l1, INT32_C(1));
                        t2 = l24.payload.obj;
                        t3 = ((vader_struct_vader_midir_InstrStructNew_t*) t2)->f_stack;
                        if (t3) {
                            l2 = vader_chk_add(i32, l2, INT32_C(1));
                        } else if (l3) {
                            t2 = l24.payload.obj;
                            l25 = ((vader_struct_vader_midir_InstrStructNew_t*) t2)->f_span;
                            t2 = l24.payload.obj;
                            l26 = vader_types_display_type(((vader_struct_vader_midir_InstrStructNew_t*) t2)->f_type);
                            vader_struct_vader_midir_EscapeSite_t* _a12_obj = (vader_struct_vader_midir_EscapeSite_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_EscapeSite_t));
                            vader_obj_header_init(_a12_obj, 1088u);
                            _a12_obj->f_span = l25;
                            _a12_obj->f_kind = 2437u;
                            _a12_obj->f_type_name = l26;
                            l27 = (void*) _a12_obj;
                            vader_array_push((vader_array_t*) l4, vader_ref_box(l27));
                        }
                    } else if (l24.tag == 1095u) {
                        l1 = vader_chk_add(i32, l1, INT32_C(1));
                        t2 = l24.payload.obj;
                        t3 = ((vader_struct_vader_midir_InstrArrayNew_t*) t2)->f_stack;
                        if (t3) {
                            l2 = vader_chk_add(i32, l2, INT32_C(1));
                        } else if (l3) {
                            t2 = l24.payload.obj;
                            l28 = ((vader_struct_vader_midir_InstrArrayNew_t*) t2)->f_span;
                            t2 = l24.payload.obj;
                            l29 = vader_types_display_type(((vader_struct_vader_midir_InstrArrayNew_t*) t2)->f_type);
                            vader_struct_vader_midir_EscapeSite_t* _a13_obj = (vader_struct_vader_midir_EscapeSite_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_EscapeSite_t));
                            vader_obj_header_init(_a13_obj, 1088u);
                            _a13_obj->f_span = l28;
                            _a13_obj->f_kind = 1393u;
                            _a13_obj->f_type_name = l29;
                            l30 = (void*) _a13_obj;
                            vader_array_push((vader_array_t*) l4, vader_ref_box(l30));
                        }
                    }
                    l23 = (l23 + INT64_C(1));
                }
                l20 = (l20 + INT64_C(1));
            }
            vader_array_push((vader_array_t*) l13, vader_ref_box(l17));
            l16 = (l16 + INT64_C(1));
        }
        l31 = ((vader_struct_vader_midir_CFGModule_t*) l6)->f_module_id;
        l32 = l6;
        l33 = ((vader_struct_vader_midir_CFGModule_t*) l32)->f_module_id;
        l34 = ((vader_struct_vader_midir_CFGModule_t*) l32)->f_display_path;
        l35 = ((vader_struct_vader_midir_CFGModule_t*) l32)->f_externs;
        l36 = ((vader_struct_vader_midir_CFGModule_t*) l32)->f_struct_decls;
        vader_struct_vader_midir_CFGModule_t* _a14_obj = (vader_struct_vader_midir_CFGModule_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_CFGModule_t));
        vader_obj_header_init(_a14_obj, 1073u);
        _a14_obj->f_module_id = l33;
        _a14_obj->f_display_path = l34;
        _a14_obj->f_functions = l13;
        _a14_obj->f_externs = l35;
        _a14_obj->f_struct_decls = l36;
        l37 = (void*) _a14_obj;
        std_collections_MutableMap_std_core_IndexSet_set_at__string__Any(l5, l31, vader_ref_box(l37));
        l9 = (l9 + INT64_C(1));
    }
    l6 = l0;
    l7 = ((vader_struct_vader_midir_CFGProject_t*) l6)->f_vtable_entries;
    l8 = ((vader_struct_vader_midir_CFGProject_t*) l6)->f_strings;
    l11 = ((vader_struct_vader_midir_CFGProject_t*) l6)->f_data_pool;
    l13 = ((vader_struct_vader_midir_CFGProject_t*) l6)->f_globals;
    l6 = ((vader_struct_vader_midir_CFGProject_t*) l6)->f_trait_membership;
    vader_struct_vader_midir_CFGProject_t* _a15_obj = (vader_struct_vader_midir_CFGProject_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_CFGProject_t));
    vader_obj_header_init(_a15_obj, 1075u);
    _a15_obj->f_modules = l5;
    _a15_obj->f_vtable_entries = l7;
    _a15_obj->f_strings = l8;
    _a15_obj->f_data_pool = l11;
    _a15_obj->f_globals = l13;
    _a15_obj->f_trait_membership = l6;
    l5 = (void*) _a15_obj;
    vader_struct_vader_midir_EscapeStats_t* _a16_obj = (vader_struct_vader_midir_EscapeStats_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_EscapeStats_t));
    vader_obj_header_init(_a16_obj, 1089u);
    _a16_obj->f_total_allocs = l1;
    _a16_obj->f_stack_promoted = l2;
    _a16_obj->f_heap_sites = l4;
    l4 = (void*) _a16_obj;
    vader_struct_vader_midir_AnnotatedProject_t* _a17_obj = (vader_struct_vader_midir_AnnotatedProject_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_AnnotatedProject_t));
    vader_obj_header_init(_a17_obj, 1068u);
    _a17_obj->f_project = l5;
    _a17_obj->f_stats = l4;
    t2 = (void*) _a17_obj;
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_midir_annotate_function(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l6 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    void* l15 = NULL;
    void* l21 = NULL;
    void* l22 = NULL;
    void* l23 = NULL;
    void* l25 = NULL;
    void* l27 = NULL;
    void* l28 = NULL;
    void* l29 = NULL;
    void* l31 = NULL;
    void* l32 = NULL;
    void* l34 = NULL;
    void* l36 = NULL;
    void* l40 = NULL;
    void* l41 = NULL;
    void* l42 = NULL;
    void* l46 = NULL;
    void* l47 = NULL;
    void* l51 = NULL;
    void* l52 = NULL;
    void* l53 = NULL;
    void* l57 = NULL;
    void* l59 = NULL;
    void* l62 = NULL;
    void* l63 = NULL;
    int64_t l4, l5, l7, l8, l18, l19;
    vader_box_t l9 = vader_box_null(), l16 = vader_box_null(), l44 = vader_box_null(), l58 = vader_box_null(), l61 = vader_box_null();
    int32_t l10, l11, l12, l30, l33, l37, l38, l43, l45, l48, l54, l56, l60;
    bool l17, l20, l24, l26, l35, l39, l49, l50;
    vader_string_t l55 = 0;
    vader_string_t l64 = 0;
    void* t0 = NULL;
    bool t1;
    int64_t t2;
    vader_box_t* gc_roots[5] = { &l9, &l16, &l44, &l58, &l61 };
    void** gc_raw_roots[32] = {
        &l0, &l1, &l2, &l3, &l6, &l13, &l14, &l15, &l21, &l22, &l23, &l25, &l27, &l28, &l29, &l31,
        &l32, &l34, &l36, &l40, &l41, &l42, &l46, &l47, &l51, &l52, &l53, &l57, &l59, &l62, &l63,
        &t0,
    };
    vader_string_t* gc_atom_roots[2] = { &l55, &l64 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 5u, 32u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(15u, 0u, 7u, 288u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(12u, 0u, 12u, 283u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(15u, 0u, 7u, 288u);
    l3 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__i32__bool_t* _a3_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
    vader_obj_header_init(_a3_obj, 381u);
    _a3_obj->f_ekeys = l1;
    _a3_obj->f_evals = l2;
    _a3_obj->f_index = l3;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a3_obj;
    vader_struct_std_collections_MutableSet__i32_t* _a4_obj = (vader_struct_std_collections_MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i32_t));
    vader_obj_header_init(_a4_obj, 517u);
    _a4_obj->f_inner = t0;
    l1 = (void*) _a4_obj;
    vader_array_t* _a5_arr = vader_array_new(15u, 0u, 7u, 288u);
    l2 = (void*) _a5_arr;
    l3 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_blocks;
    l4 = ((vader_array_t*) l3)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a6_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        t0 = vader_array_ref_load_obj(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l5);
        l6 = ((vader_struct_vader_midir_BasicBlock_t*) t0)->f_instructions;
        l7 = ((vader_array_t*) l6)->length;
        l8 = INT64_C(0);
        while ((l8 < l7)) {
            vader_array_t* _a7_slotarr = ((vader_array_t*) l6);
            VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
            l9 = vader_array_ref_load_box(_a7_slotarr->buf, _a7_slotarr->offset + (size_t) l8);
            if (l9.tag == 1119u) {
                t0 = l9.payload.obj;
                l10 = ((vader_struct_vader_midir_InstrStructNew_t*) t0)->f_dst;
                std_collections_add__i32(l1, l10);
                t0 = l9.payload.obj;
                l11 = ((vader_struct_vader_midir_InstrStructNew_t*) t0)->f_dst;
                vader_array_push_i32((vader_array_t*) l2, l11);
            } else if (l9.tag == 1095u) {
                t0 = l9.payload.obj;
                l12 = ((vader_struct_vader_midir_InstrArrayNew_t*) t0)->f_dst;
                std_collections_add__i32(l1, l12);
            }
            l8 = (l8 + INT64_C(1));
        }
        l5 = (l5 + INT64_C(1));
    }
    t1 = std_collections_is_empty__i32(l1);
    if (t1) {
        { void* __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = vader_midir_compute_escaping(l0, l1);
    l6 = ((vader_struct_vader_midir_EscapeResult_t*) l3)->f_alias_of;
    l6 = vader_midir_compute_carried_across_loop_headers(l0, l6);
    vader_array_t* _a8_arr = vader_array_new(15u, 0u, 7u, 288u);
    l13 = (void*) _a8_arr;
    vader_array_t* _a9_arr = vader_array_new(12u, 0u, 12u, 283u);
    l14 = (void*) _a9_arr;
    vader_array_t* _a10_arr = vader_array_new(15u, 0u, 7u, 288u);
    l15 = (void*) _a10_arr;
    vader_struct_std_collections_MutableMap__i32__bool_t* _a11_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
    vader_obj_header_init(_a11_obj, 381u);
    _a11_obj->f_ekeys = l13;
    _a11_obj->f_evals = l14;
    _a11_obj->f_index = l15;
    _a11_obj->f_mask = INT64_C(0);
    _a11_obj->f_size = INT64_C(0);
    _a11_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a11_obj;
    vader_struct_std_collections_MutableSet__i32_t* _a12_obj = (vader_struct_std_collections_MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i32_t));
    vader_obj_header_init(_a12_obj, 517u);
    _a12_obj->f_inner = t0;
    l13 = (void*) _a12_obj;
    vader_array_t* _a13_arr = vader_array_new(15u, 0u, 7u, 288u);
    l14 = (void*) _a13_arr;
    l4 = ((vader_array_t*) l2)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a14_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
        l10 = ((int32_t*) _a14_slotarr->buf->slots)[_a14_slotarr->offset + (size_t) l5];
        t1 = std_collections_MutableSet_std_core_Contains_contains__i32(((vader_struct_vader_midir_EscapeResult_t*) l3)->f_escaping, l10);
        if (t1) {
            l5 = (l5 + INT64_C(1));
            continue;
        }
        t1 = std_collections_MutableSet_std_core_Contains_contains__i32(l6, l10);
        if (t1) {
            l5 = (l5 + INT64_C(1));
            continue;
        }
        std_collections_add__i32(l13, l10);
        vader_array_push_i32((vader_array_t*) l14, l10);
        l5 = (l5 + INT64_C(1));
    }
    for (;;) {
        t2 = ((vader_array_t*) l14)->length;
        if ((t2 > INT64_C(0))) {
            t2 = ((vader_array_t*) l14)->length;
            l4 = vader_chk_sub(i64, t2, INT64_C(1));
            vader_array_t* _a15_slotarr = ((vader_array_t*) l14);
            VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
            l10 = ((int32_t*) _a15_slotarr->buf->slots)[_a15_slotarr->offset + (size_t) l4];
            t2 = ((vader_array_t*) l14)->length;
            l5 = vader_chk_sub(i64, t2, INT64_C(1));
            vader_array_t* _a16_arr = vader_array_slice((vader_array_t*) l14, (int64_t) INT64_C(0), (int64_t) l5);
            l14 = (void*) _a16_arr;
            l9 = std_collections_MutableMap_std_core_Index_at__i32__Any(((vader_struct_vader_midir_EscapeResult_t*) l3)->f_alias_from, l10);
            if (l9.tag == 0u) {
                continue;
            }
            l2 = l9.payload.obj;
            l7 = ((vader_array_t*) l2)->length;
            l8 = INT64_C(0);
            while ((l8 < l7)) {
                vader_array_t* _a17_slotarr = ((vader_array_t*) l2);
                VADER_ARRAY_RESOLVE_BUF(_a17_slotarr)
                l11 = ((int32_t*) _a17_slotarr->buf->slots)[_a17_slotarr->offset + (size_t) l8];
                t1 = std_collections_MutableSet_std_core_Contains_contains__i32(l13, l11);
                if (t1) {
                    l8 = (l8 + INT64_C(1));
                    continue;
                }
                l16 = std_collections_MutableMap_std_core_Index_at__i32__Any(((vader_struct_vader_midir_EscapeResult_t*) l3)->f_alias_of, l11);
                if (!(l16.tag == 0u)) {
                    l17 = true;
                    l15 = l16.payload.obj;
                    l18 = ((vader_array_t*) l15)->length;
                    l19 = INT64_C(0);
                    for (;;) {
                        if ((l19 < l18)) {
                            vader_array_t* _a18_slotarr = ((vader_array_t*) l15);
                            VADER_ARRAY_RESOLVE_BUF(_a18_slotarr)
                            l12 = ((int32_t*) _a18_slotarr->buf->slots)[_a18_slotarr->offset + (size_t) l19];
                            t1 = std_collections_MutableSet_std_core_Contains_contains__i32(l13, l12);
                            if (t1) {
                                l19 = (l19 + INT64_C(1));
                                continue;
                            }
                            l17 = false;
                            break;
                        }
                        break;
                    }
                    if (l17) {
                        std_collections_add__i32(l13, l11);
                        vader_array_push_i32((vader_array_t*) l14, l11);
                    }
                }
                l8 = (l8 + INT64_C(1));
            }
            continue;
        }
        break;
    }
    l17 = false;
    vader_array_t* _a19_arr = vader_array_new(135u, 0u, 13u, 1069u);
    l2 = (void*) _a19_arr;
    l14 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_blocks;
    l4 = ((vader_array_t*) l14)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a20_slotarr = ((vader_array_t*) l14);
        VADER_ARRAY_RESOLVE_BUF(_a20_slotarr)
        l15 = vader_array_ref_load_obj(_a20_slotarr->buf, _a20_slotarr->offset + (size_t) l5);
        l20 = false;
        vader_array_t* _a21_arr = vader_array_new(242u, 0u, 13u, 1745u);
        l21 = (void*) _a21_arr;
        l22 = ((vader_struct_vader_midir_BasicBlock_t*) l15)->f_instructions;
        l7 = ((vader_array_t*) l22)->length;
        l8 = INT64_C(0);
        while ((l8 < l7)) {
            vader_array_t* _a22_slotarr = ((vader_array_t*) l22);
            VADER_ARRAY_RESOLVE_BUF(_a22_slotarr)
            l9 = vader_array_ref_load_box(_a22_slotarr->buf, _a22_slotarr->offset + (size_t) l8);
            if (l9.tag == 1119u) {
                t0 = l9.payload.obj;
                l10 = ((vader_struct_vader_midir_InstrStructNew_t*) t0)->f_dst;
                t1 = std_collections_MutableSet_std_core_Contains_contains__i32(l1, l10);
                if (t1) {
                    l25 = ((vader_struct_vader_midir_EscapeResult_t*) l3)->f_escaping;
                    t0 = l9.payload.obj;
                    l11 = ((vader_struct_vader_midir_InstrStructNew_t*) t0)->f_dst;
                    t1 = std_collections_MutableSet_std_core_Contains_contains__i32(l25, l11);
                    if (!(t1)) {
                        t0 = l9.payload.obj;
                        l12 = ((vader_struct_vader_midir_InstrStructNew_t*) t0)->f_dst;
                        t1 = std_collections_MutableSet_std_core_Contains_contains__i32(l6, l12);
                        l24 = !(t1);
                    } else {
                        l24 = false;
                    }
                    t0 = l9.payload.obj;
                    l26 = ((vader_struct_vader_midir_InstrStructNew_t*) t0)->f_stack;
                    if (l24 == l26) {
                        l27 = l9.payload.obj;
                        vader_array_push((vader_array_t*) l21, vader_ref_box(l27));
                        l8 = (l8 + INT64_C(1));
                        continue;
                    }
                    l20 = true;
                    l28 = l9.payload.obj;
                    l29 = ((vader_struct_vader_midir_InstrStructNew_t*) l28)->f_span;
                    l30 = ((vader_struct_vader_midir_InstrStructNew_t*) l28)->f_dst;
                    l16 = ((vader_struct_vader_midir_InstrStructNew_t*) l28)->f_type;
                    l31 = ((vader_struct_vader_midir_InstrStructNew_t*) l28)->f_fields;
                    vader_struct_vader_midir_InstrStructNew_t* _a23_obj = (vader_struct_vader_midir_InstrStructNew_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrStructNew_t));
                    vader_obj_header_init(_a23_obj, 1119u);
                    _a23_obj->f_span = l29;
                    _a23_obj->f_dst = l30;
                    _a23_obj->f_type = l16;
                    _a23_obj->f_fields = l31;
                    _a23_obj->f_stack = l24;
                    l32 = (void*) _a23_obj;
                    vader_array_push((vader_array_t*) l21, vader_ref_box(l32));
                } else {
                    l23 = l9.payload.obj;
                    vader_array_push((vader_array_t*) l21, vader_ref_box(l23));
                    l8 = (l8 + INT64_C(1));
                    continue;
                }
            } else if (l9.tag == 1095u) {
                t0 = l9.payload.obj;
                l33 = ((vader_struct_vader_midir_InstrArrayNew_t*) t0)->f_dst;
                t1 = std_collections_MutableSet_std_core_Contains_contains__i32(l1, l33);
                if (t1) {
                    l36 = ((vader_struct_vader_midir_EscapeResult_t*) l3)->f_escaping;
                    t0 = l9.payload.obj;
                    l37 = ((vader_struct_vader_midir_InstrArrayNew_t*) t0)->f_dst;
                    t1 = std_collections_MutableSet_std_core_Contains_contains__i32(l36, l37);
                    if (!(t1)) {
                        t0 = l9.payload.obj;
                        l38 = ((vader_struct_vader_midir_InstrArrayNew_t*) t0)->f_dst;
                        t1 = std_collections_MutableSet_std_core_Contains_contains__i32(l6, l38);
                        l35 = !(t1);
                    } else {
                        l35 = false;
                    }
                    t0 = l9.payload.obj;
                    l39 = ((vader_struct_vader_midir_InstrArrayNew_t*) t0)->f_stack;
                    if (l35 == l39) {
                        l40 = l9.payload.obj;
                        vader_array_push((vader_array_t*) l21, vader_ref_box(l40));
                        l8 = (l8 + INT64_C(1));
                        continue;
                    }
                    l20 = true;
                    l41 = l9.payload.obj;
                    l42 = ((vader_struct_vader_midir_InstrArrayNew_t*) l41)->f_span;
                    l43 = ((vader_struct_vader_midir_InstrArrayNew_t*) l41)->f_dst;
                    l44 = ((vader_struct_vader_midir_InstrArrayNew_t*) l41)->f_type;
                    l45 = ((vader_struct_vader_midir_InstrArrayNew_t*) l41)->f_length;
                    l46 = ((vader_struct_vader_midir_InstrArrayNew_t*) l41)->f_elements;
                    vader_struct_vader_midir_InstrArrayNew_t* _a24_obj = (vader_struct_vader_midir_InstrArrayNew_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrArrayNew_t));
                    vader_obj_header_init(_a24_obj, 1095u);
                    _a24_obj->f_span = l42;
                    _a24_obj->f_dst = l43;
                    _a24_obj->f_type = l44;
                    _a24_obj->f_length = l45;
                    _a24_obj->f_elements = l46;
                    _a24_obj->f_stack = l35;
                    l47 = (void*) _a24_obj;
                    vader_array_push((vader_array_t*) l21, vader_ref_box(l47));
                } else {
                    l34 = l9.payload.obj;
                    vader_array_push((vader_array_t*) l21, vader_ref_box(l34));
                    l8 = (l8 + INT64_C(1));
                    continue;
                }
            } else if (l9.tag == 1111u) {
                t0 = l9.payload.obj;
                l48 = ((vader_struct_vader_midir_InstrFieldSet_t*) t0)->f_target;
                l49 = std_collections_MutableSet_std_core_Contains_contains__i32(l13, l48);
                t0 = l9.payload.obj;
                l50 = ((vader_struct_vader_midir_InstrFieldSet_t*) t0)->f_barrierless;
                if (l49 == l50) {
                    l51 = l9.payload.obj;
                    vader_array_push((vader_array_t*) l21, vader_ref_box(l51));
                    l8 = (l8 + INT64_C(1));
                    continue;
                }
                l20 = true;
                l52 = l9.payload.obj;
                l53 = ((vader_struct_vader_midir_InstrFieldSet_t*) l52)->f_span;
                l54 = ((vader_struct_vader_midir_InstrFieldSet_t*) l52)->f_target;
                l55 = ((vader_struct_vader_midir_InstrFieldSet_t*) l52)->f_field;
                l56 = ((vader_struct_vader_midir_InstrFieldSet_t*) l52)->f_value;
                vader_struct_vader_midir_InstrFieldSet_t* _a25_obj = (vader_struct_vader_midir_InstrFieldSet_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrFieldSet_t));
                vader_obj_header_init(_a25_obj, 1111u);
                _a25_obj->f_span = l53;
                _a25_obj->f_target = l54;
                _a25_obj->f_field = l55;
                _a25_obj->f_value = l56;
                _a25_obj->f_barrierless = l49;
                l57 = (void*) _a25_obj;
                vader_array_push((vader_array_t*) l21, vader_ref_box(l57));
            } else {
                l58 = l9;
                vader_array_push((vader_array_t*) l21, l58);
            }
            l8 = (l8 + INT64_C(1));
        }
        if (l20) {
            l17 = true;
            l59 = l15;
            l60 = ((vader_struct_vader_midir_BasicBlock_t*) l59)->f_id;
            l61 = ((vader_struct_vader_midir_BasicBlock_t*) l59)->f_terminator;
            l62 = ((vader_struct_vader_midir_BasicBlock_t*) l59)->f_span;
            vader_struct_vader_midir_BasicBlock_t* _a26_obj = (vader_struct_vader_midir_BasicBlock_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_BasicBlock_t));
            vader_obj_header_init(_a26_obj, 1069u);
            _a26_obj->f_id = l60;
            _a26_obj->f_instructions = l21;
            _a26_obj->f_terminator = l61;
            _a26_obj->f_span = l62;
            l63 = (void*) _a26_obj;
            vader_array_push((vader_array_t*) l2, vader_ref_box(l63));
            l5 = (l5 + INT64_C(1));
            continue;
        }
        vader_array_push((vader_array_t*) l2, vader_ref_box(l15));
        l5 = (l5 + INT64_C(1));
    }
    if (!(l17)) {
        { void* __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l1 = l0;
    l55 = ((vader_struct_vader_midir_CFGFunction_t*) l1)->f_mangled;
    l3 = ((vader_struct_vader_midir_CFGFunction_t*) l1)->f_params;
    l9 = ((vader_struct_vader_midir_CFGFunction_t*) l1)->f_return_type;
    l6 = ((vader_struct_vader_midir_CFGFunction_t*) l1)->f_locals;
    l10 = ((vader_struct_vader_midir_CFGFunction_t*) l1)->f_entry;
    l13 = ((vader_struct_vader_midir_CFGFunction_t*) l1)->f_origin;
    l64 = ((vader_struct_vader_midir_CFGFunction_t*) l1)->f_extern_name;
    l17 = ((vader_struct_vader_midir_CFGFunction_t*) l1)->f_is_extern;
    l20 = ((vader_struct_vader_midir_CFGFunction_t*) l1)->f_is_exported;
    l1 = ((vader_struct_vader_midir_CFGFunction_t*) l1)->f_scalarised_results;
    vader_struct_vader_midir_CFGFunction_t* _a27_obj = (vader_struct_vader_midir_CFGFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_CFGFunction_t));
    vader_obj_header_init(_a27_obj, 1071u);
    _a27_obj->f_mangled = l55;
    _a27_obj->f_params = l3;
    _a27_obj->f_return_type = l9;
    _a27_obj->f_locals = l6;
    _a27_obj->f_blocks = l2;
    _a27_obj->f_entry = l10;
    _a27_obj->f_origin = l13;
    _a27_obj->f_extern_name = l64;
    _a27_obj->f_is_extern = l17;
    _a27_obj->f_is_exported = l20;
    _a27_obj->f_scalarised_results = l1;
    t0 = (void*) _a27_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_midir_append_alias(void* l0, int32_t l1, int32_t l2) {
    vader_box_t l3 = vader_box_null();
    void* l4 = NULL;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l3 };
    void** gc_raw_roots[3] = { &l0, &l4, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = std_collections_MutableMap_std_core_Index_at__i32__Any(l0, l1);
    if (l3.tag == 0u) {
        vader_array_t* _a0_arr = vader_array_new(15u, 1u, 7u, 288u);
        ((int32_t*) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = (int32_t) l2;
        l4 = (void*) _a0_arr;
        std_collections_MutableMap_std_core_IndexSet_set_at__i32__Any(l0, l1, vader_ref_box(l4));
        { vader_gc_top = gc_frame.prev; return; }
    }
    t0 = l3.payload.obj;
    vader_array_push_i32((vader_array_t*) t0, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_string_t vader_midir_array_element_name(vader_box_t l0) {
    void* t0 = NULL;
    vader_string_t t1 = 0;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[1] = { &t0 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (!(l0.tag == 1252u)) {
        { vader_gc_top = gc_frame.prev; return 0u; }
    }
    t0 = l0.payload.obj;
    t1 = vader_types_representation_name(((vader_struct_vader_types_ArrayType_t*) t0)->f_element);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static uint8_t vader_midir_array_element_val_type(vader_box_t l0) {
    void* t0 = NULL;
    uint8_t t1;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (!(l0.tag == 1252u)) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 17; }
    }
    t0 = l0.payload.obj;
    t1 = vader_bytecode_val_type_of_type(((vader_struct_vader_types_ArrayType_t*) t0)->f_element);
    { uint8_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static uint64_t vader_midir_bc_value_bits(vader_box_t l0, vader_string_t l1) {
    void* t0 = NULL;
    int64_t t1;
    uint32_t t2;
    bool t3;
    double t4;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[1] = { &t0 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l0.tag == 1023u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_lower_LoweredIntLit_t*) t0)->f_value;
        { uint64_t __vret = (uint64_t) (int64_t) t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1008u) {
        t0 = l0.payload.obj;
        t2 = ((vader_struct_vader_lower_LoweredCharLit_t*) t0)->f_value;
        { uint64_t __vret = (uint64_t) (int64_t) ((int64_t) (uint32_t) t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1001u) {
        t0 = l0.payload.obj;
        t3 = ((vader_struct_vader_lower_LoweredBoolLit_t*) t0)->f_value;
        if (t3) {
            { vader_gc_top = gc_frame.prev; return (uint64_t) 1; }
        }
        { vader_gc_top = gc_frame.prev; return (uint64_t) 0; }
    }
    if (!(l0.tag == 1016u)) {
        vader_host_std_abort_panic(2138u);
        vader_unreachable("a no-return call returned");
    }
    if (!(l1 == 1759u)) {
        t0 = l0.payload.obj;
        t4 = ((vader_struct_vader_lower_LoweredFloatLit_t*) t0)->f_value;
        { uint64_t __vret = (uint64_t) (int64_t) (int64_t)(((union { double __vd; uint64_t __vu; }){ .__vd = t4 }).__vu); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l0.payload.obj;
    t4 = ((vader_struct_vader_lower_LoweredFloatLit_t*) t0)->f_value;
    { uint64_t __vret = (uint64_t) (int64_t) ((int64_t) (uint32_t) (int32_t)(((union { float __vf; uint32_t __vb; }){ .__vf = t4 }).__vb)); vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_midir_binary_leaves_width(uint8_t l0, uint8_t l1) {
    bool l2, l3;
    bool t0;
    t0 = vader_bytecode_is_narrow_valtype(l1);
    if (t0) {
        if (l0 == INT32_C(0)) {
            l2 = true;
        } else {
            l2 = l0 == INT32_C(1);
        }
        if (l2) {
            l3 = true;
        } else {
            l3 = l0 == INT32_C(2);
        }
        if (l3) {
            l3 = true;
        } else {
            l3 = l0 == INT32_C(5);
        }
        if (l3) {
            l2 = true;
        } else if (l0 == INT32_C(3)) {
            t0 = vader_bytecode_is_unsigned_val(l1);
            l2 = !(t0);
        } else {
            if (l0 == INT32_C(18)) {
                l3 = true;
            } else {
                l3 = l0 == INT32_C(19);
            }
            if (l3) {
                l3 = true;
            } else {
                l3 = l0 == INT32_C(20);
            }
            if (l3) {
                l3 = true;
            } else {
                l3 = l0 == INT32_C(4);
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
                l3 = true;
            } else {
                l3 = l0 == INT32_C(8);
            }
            if (l3) {
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
                l3 = l0 == INT32_C(13);
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
            if (l3) {
                l3 = true;
            } else {
                l3 = l0 == INT32_C(16);
            }
            if (l3) {
                l3 = true;
            } else {
                l3 = l0 == INT32_C(17);
            }
            if (!(l3)) {
                vader_unreachable("non-exhaustive match (T3013 should have caught this)");
            }
            l2 = false;
        }
        return l2;
    }
    return false;
}

static vader_box_t vader_midir_binary_width(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l3 = vader_box_null(), l4 = vader_box_null();
    bool t0;
    void* t1 = NULL;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[4] = { &l2, &l3, &l4, &t2 };
    void** gc_raw_roots[3] = { &l0, &l1, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_types_is_stored_as_integer(((vader_struct_vader_lower_LoweredBinary_t*) l1)->f_type);
    if (!(t0)) {
        l2 = vader_midir_stored_test(l0, l1);
        if (!(l2.tag == 0u)) {
            t1 = l2.payload.obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    l2 = VADER_UNION_FIELD(vader_box_t, vader_struct_vader_lower_LoweredArrayLen_t, f_type, ((vader_struct_vader_lower_LoweredBinary_t*) l1)->f_left.payload.obj);
    l3 = VADER_UNION_FIELD(vader_box_t, vader_struct_vader_lower_LoweredArrayLen_t, f_type, ((vader_struct_vader_lower_LoweredBinary_t*) l1)->f_right.payload.obj);
    l4 = ((vader_struct_vader_lower_LoweredBinary_t*) l1)->f_type;
    t2 = vader_midir_computation_width(l2, l3, l4);
    { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_midir_boxed_element(vader_box_t l0) {
    void* l1 = NULL;
    vader_box_t l2 = vader_box_null();
    bool t0;
    vader_box_t* gc_roots[2] = { &l0, &l2 };
    void** gc_raw_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = vader_types_array_backing(l0);
    if (l2.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return false; }
    }
    l1 = l2.payload.obj;
    t0 = vader_midir_is_boxed_slot(((vader_struct_vader_types_ArrayType_t*) l1)->f_element);
    { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_midir_boxed_field(void* l0, int32_t l1, int64_t l2) {
    vader_box_t l3;
    int32_t l4;
    void* t0;
    bool t1;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_types);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    l3 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l1);
    if (l3.tag == 652u) {
        t0 = l3.payload.obj;
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcStruct_t*) t0)->f_fields);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l2)
        t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l2);
        l4 = ((vader_struct_vader_bytecode_BcField_t*) t0)->f_type_index;
        t1 = vader_midir_is_boxed_row(l0, l4);
        return t1;
    }
    return false;
}

static void* vader_midir_boxed_fields_of(void* l0, int32_t l1) {
    vader_box_t l2 = vader_box_null();
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l8 = NULL;
    int64_t l6, l7;
    bool l9;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[6] = { &l0, &l3, &l4, &l5, &l8, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 6u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_types);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    l2 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l1);
    if (!(l2.tag == 652u)) {
        vader_array_t* _a1_arr = vader_array_new(12u, 0u, 12u, 283u);
        t0 = (void*) _a1_arr;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l2.payload.obj;
    l3 = ((vader_struct_vader_bytecode_BcStruct_t*) t0)->f_fields;
    vader_struct___lambda_env_vader_midir_16_t* _a2_obj = (vader_struct___lambda_env_vader_midir_16_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_midir_16_t));
    vader_obj_header_init(_a2_obj, 341u);
    _a2_obj->f_cap_0 = l0;
    l4 = (void*) _a2_obj;
    vader_array_t* _a3_arr = vader_array_new(12u, 0u, 12u, 283u);
    l5 = (void*) _a3_arr;
    l6 = ((vader_array_t*) l3)->length;
    vader_array_t* _a4_arr = vader_array_repeat((vader_array_t*) l5, (int64_t) l6);
    l5 = (void*) _a4_arr;
    l6 = ((vader_array_t*) l3)->length;
    l7 = INT64_C(0);
    vader_array_t* _pc31_hdr = (vader_array_t*) l5;
    size_t _pc31_len = _pc31_hdr->length;
    size_t _pc31_cap = (_pc31_hdr->offset == 0 && !vader_array_is_borrowed(_pc31_hdr) && _pc31_hdr->length >= _pc31_hdr->buf->length) ? _pc31_hdr->capacity : (size_t) 0;
    void* _pc31_slots = _pc31_hdr->buf->slots;
    for (;;) {
        if ((l7 < l6)) {
            vader_array_t* _a5_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
            l8 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l7);
            l9 = __lambda_vader_midir_15(l4, l8);
            if (VADER_LIKELY(_pc31_len < _pc31_cap)) {
                ((uint8_t*) _pc31_slots)[_pc31_len] = (uint8_t) (l9);
                _pc31_len += 1;
            } else {
                _pc31_hdr->length = _pc31_len;
                if (_pc31_hdr->buf->length < _pc31_len) {
                    _pc31_hdr->buf->length = _pc31_len;
                }
                vader_array_push_bool((vader_array_t*) l5, l9);
                _pc31_hdr = (vader_array_t*) l5;
                _pc31_len = _pc31_hdr->length;
                _pc31_cap = (_pc31_hdr->offset == 0 && !vader_array_is_borrowed(_pc31_hdr) && _pc31_hdr->length >= _pc31_hdr->buf->length) ? _pc31_hdr->capacity : (size_t) 0;
                _pc31_slots = _pc31_hdr->buf->slots;
            }
            l7 = (l7 + INT64_C(1));
            continue;
        }
        _pc31_hdr->length = _pc31_len;
        if (_pc31_hdr->buf->length < _pc31_len) {
            _pc31_hdr->buf->length = _pc31_len;
        }
        break;
    }
    { void* __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_midir_boxed_params_of(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    int64_t l5, l6;
    int32_t l7;
    bool l8;
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_bytecode_BcSignature_t*) l1)->f_param_types;
    vader_struct___lambda_env_vader_midir_14_t* _a0_obj = (vader_struct___lambda_env_vader_midir_14_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_midir_14_t));
    vader_obj_header_init(_a0_obj, 340u);
    _a0_obj->f_cap_0 = l0;
    l3 = (void*) _a0_obj;
    vader_array_t* _a1_arr = vader_array_new(12u, 0u, 12u, 283u);
    l4 = (void*) _a1_arr;
    l5 = ((vader_array_t*) l2)->length;
    vader_array_t* _a2_arr = vader_array_repeat((vader_array_t*) l4, (int64_t) l5);
    l4 = (void*) _a2_arr;
    l5 = ((vader_array_t*) l2)->length;
    l6 = INT64_C(0);
    vader_array_t* _pc19_hdr = (vader_array_t*) l4;
    size_t _pc19_len = _pc19_hdr->length;
    size_t _pc19_cap = (_pc19_hdr->offset == 0 && !vader_array_is_borrowed(_pc19_hdr) && _pc19_hdr->length >= _pc19_hdr->buf->length) ? _pc19_hdr->capacity : (size_t) 0;
    void* _pc19_slots = _pc19_hdr->buf->slots;
    for (;;) {
        if ((l6 < l5)) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            l7 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l6];
            l8 = __lambda_vader_midir_13(l3, l7);
            if (VADER_LIKELY(_pc19_len < _pc19_cap)) {
                ((uint8_t*) _pc19_slots)[_pc19_len] = (uint8_t) (l8);
                _pc19_len += 1;
            } else {
                _pc19_hdr->length = _pc19_len;
                if (_pc19_hdr->buf->length < _pc19_len) {
                    _pc19_hdr->buf->length = _pc19_len;
                }
                vader_array_push_bool((vader_array_t*) l4, l8);
                _pc19_hdr = (vader_array_t*) l4;
                _pc19_len = _pc19_hdr->length;
                _pc19_cap = (_pc19_hdr->offset == 0 && !vader_array_is_borrowed(_pc19_hdr) && _pc19_hdr->length >= _pc19_hdr->buf->length) ? _pc19_hdr->capacity : (size_t) 0;
                _pc19_slots = _pc19_hdr->buf->slots;
            }
            l6 = (l6 + INT64_C(1));
            continue;
        }
        _pc19_hdr->length = _pc19_len;
        if (_pc19_hdr->buf->length < _pc19_len) {
            _pc19_hdr->buf->length = _pc19_len;
        }
        break;
    }
    { void* __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_midir_branch_on_cond(void* l0, vader_box_t l1, int32_t l2, int32_t l3, bool l4) {
    vader_box_t l5 = vader_box_null();
    void* l6 = NULL;
    void* l10 = NULL;
    bool l7, l8;
    int32_t l9;
    void* t0 = NULL;
    bool t1;
    vader_box_t* gc_roots[2] = { &l1, &l5 };
    void** gc_raw_roots[4] = { &l0, &l6, &l10, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l1.tag == 1041u) {
        t0 = l1.payload.obj;
        if (((vader_struct_vader_lower_LoweredUnary_t*) t0)->f_op == INT32_C(1)) {
            t0 = l1.payload.obj;
            l5 = ((vader_struct_vader_lower_LoweredUnary_t*) t0)->f_operand;
            l6 = vader_midir_branch_on_cond(l0, l5, l3, l2, l4);
            l7 = ((vader_struct_vader_midir_CondReach_t*) l6)->f_on_false;
            l8 = ((vader_struct_vader_midir_CondReach_t*) l6)->f_on_true;
            vader_struct_vader_midir_CondReach_t* _a0_obj = (vader_struct_vader_midir_CondReach_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_CondReach_t));
            vader_obj_header_init(_a0_obj, 1079u);
            _a0_obj->f_on_true = l7;
            _a0_obj->f_on_false = l8;
            t0 = (void*) _a0_obj;
            { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    if (l4) {
        if (l1.tag == 999u) {
            t0 = l1.payload.obj;
            t1 = vader_midir_is_short_circuit_op(((vader_struct_vader_lower_LoweredBinary_t*) t0)->f_op);
            if (t1) {
                t0 = l1.payload.obj;
                l6 = VADER_UNION_FIELD(void*, vader_struct_vader_lower_LoweredArrayLen_t, f_span, ((vader_struct_vader_lower_LoweredBinary_t*) t0)->f_right.payload.obj);
                l9 = vader_midir_new_block(l0, l6);
                t0 = l1.payload.obj;
                if (((vader_struct_vader_lower_LoweredBinary_t*) t0)->f_op == INT32_C(10)) {
                    t0 = l1.payload.obj;
                    l5 = ((vader_struct_vader_lower_LoweredBinary_t*) t0)->f_left;
                    l6 = vader_midir_branch_on_cond(l0, l5, l9, l3, l4);
                    t1 = ((vader_struct_vader_midir_CondReach_t*) l6)->f_on_true;
                    if (!(t1)) {
                        { void* __vret = l6; vader_gc_top = gc_frame.prev; return __vret; }
                    }
                    ((vader_struct_vader_midir_FnCtx_t*) l0)->f_current = vader_box_i32(288u, l9);
                    VADER_WRITE_BARRIER((vader_struct_vader_midir_FnCtx_t*) l0);
                    t0 = l1.payload.obj;
                    l5 = ((vader_struct_vader_lower_LoweredBinary_t*) t0)->f_right;
                    l10 = vader_midir_branch_on_cond(l0, l5, l2, l3, l4);
                    l7 = ((vader_struct_vader_midir_CondReach_t*) l10)->f_on_true;
                    t1 = ((vader_struct_vader_midir_CondReach_t*) l6)->f_on_false;
                    if (t1) {
                        l8 = true;
                        vader_struct_vader_midir_CondReach_t* _a1_obj = (vader_struct_vader_midir_CondReach_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_CondReach_t));
                        vader_obj_header_init(_a1_obj, 1079u);
                        _a1_obj->f_on_true = l7;
                        _a1_obj->f_on_false = l8;
                        t0 = (void*) _a1_obj;
                        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
                    }
                    l8 = ((vader_struct_vader_midir_CondReach_t*) l10)->f_on_false;
                    vader_struct_vader_midir_CondReach_t* _a2_obj = (vader_struct_vader_midir_CondReach_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_CondReach_t));
                    vader_obj_header_init(_a2_obj, 1079u);
                    _a2_obj->f_on_true = l7;
                    _a2_obj->f_on_false = l8;
                    t0 = (void*) _a2_obj;
                    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
                }
                t0 = l1.payload.obj;
                l5 = ((vader_struct_vader_lower_LoweredBinary_t*) t0)->f_left;
                l6 = vader_midir_branch_on_cond(l0, l5, l2, l9, l4);
                t1 = ((vader_struct_vader_midir_CondReach_t*) l6)->f_on_false;
                if (!(t1)) {
                    { void* __vret = l6; vader_gc_top = gc_frame.prev; return __vret; }
                }
                ((vader_struct_vader_midir_FnCtx_t*) l0)->f_current = vader_box_i32(288u, l9);
                VADER_WRITE_BARRIER((vader_struct_vader_midir_FnCtx_t*) l0);
                t0 = l1.payload.obj;
                l5 = ((vader_struct_vader_lower_LoweredBinary_t*) t0)->f_right;
                l10 = vader_midir_branch_on_cond(l0, l5, l2, l3, l4);
                t1 = ((vader_struct_vader_midir_CondReach_t*) l6)->f_on_true;
                if (t1) {
                    l7 = true;
                    l8 = ((vader_struct_vader_midir_CondReach_t*) l10)->f_on_false;
                    vader_struct_vader_midir_CondReach_t* _a3_obj = (vader_struct_vader_midir_CondReach_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_CondReach_t));
                    vader_obj_header_init(_a3_obj, 1079u);
                    _a3_obj->f_on_true = l7;
                    _a3_obj->f_on_false = l8;
                    t0 = (void*) _a3_obj;
                    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
                }
                l7 = ((vader_struct_vader_midir_CondReach_t*) l10)->f_on_true;
                l8 = ((vader_struct_vader_midir_CondReach_t*) l10)->f_on_false;
                vader_struct_vader_midir_CondReach_t* _a4_obj = (vader_struct_vader_midir_CondReach_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_CondReach_t));
                vader_obj_header_init(_a4_obj, 1079u);
                _a4_obj->f_on_true = l7;
                _a4_obj->f_on_false = l8;
                t0 = (void*) _a4_obj;
                { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
            }
        }
    }
    vader_struct_vader_midir_CondReach_t* _a5_obj = (vader_struct_vader_midir_CondReach_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_CondReach_t));
    vader_obj_header_init(_a5_obj, 1079u);
    _a5_obj->f_on_true = false;
    _a5_obj->f_on_false = false;
    l6 = (void*) _a5_obj;
    l5 = vader_midir_build_expr(l0, l1);
    if (l5.tag == 0u) {
        { void* __vret = l6; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l9 = ((int32_t) l5.payload.i);
    if (!(((vader_struct_vader_midir_FnCtx_t*) l0)->f_current.tag == 0u)) {
        vader_struct_vader_midir_TermCondBranch_t* _a6_obj = (vader_struct_vader_midir_TermCondBranch_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_TermCondBranch_t));
        vader_obj_header_init(_a6_obj, 1137u);
        _a6_obj->f_span = VADER_UNION_FIELD(void*, vader_struct_vader_lower_LoweredArrayLen_t, f_span, l1.payload.obj);
        _a6_obj->f_cond = l9;
        _a6_obj->f_then_block = l2;
        _a6_obj->f_else_block = l3;
        l10 = (void*) _a6_obj;
        vader_midir_terminate(l0, vader_ref_box(l10));
        vader_struct_vader_midir_CondReach_t* _a7_obj = (vader_struct_vader_midir_CondReach_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_CondReach_t));
        vader_obj_header_init(_a7_obj, 1079u);
        _a7_obj->f_on_true = true;
        _a7_obj->f_on_false = true;
        t0 = (void*) _a7_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { void* __vret = l6; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir_build_args(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    int64_t l4, l5;
    int32_t l6;
    vader_box_t l7 = vader_box_null(), l8 = vader_box_null(), l9 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l7, &l8, &l9 };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(15u, 0u, 7u, 288u);
    l3 = (void*) _a0_arr;
    l4 = INT64_C(0);
    l5 = ((vader_array_t*) l1)->length;
    while ((l4 < l5)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
        l7 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
        l8 = vader_midir_type_at(l2, l4);
        l9 = vader_midir_build_held(l0, l7, l8);
        if (l9.tag == 0u) {
            { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
        }
        l6 = ((int32_t) l9.payload.i);
        vader_array_push_i32((vader_array_t*) l3, l6);
        l4 = (l4 + INT64_C(1));
    }
    { vader_box_t __vret = vader_ref_box(l3); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir_build_array_len(void* l0, void* l1) {
    int32_t l2, l4;
    vader_box_t l3 = vader_box_null();
    void* l5 = NULL;
    vader_box_t* gc_roots[1] = { &l3 };
    void** gc_raw_roots[3] = { &l0, &l1, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_lower_LoweredArrayLen_t*) l1)->f_target;
    l3 = vader_midir_build_expr(l0, l3);
    if (l3.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l2 = ((int32_t) l3.payload.i);
    l3 = ((vader_struct_vader_lower_LoweredArrayLen_t*) l1)->f_type;
    l4 = vader_midir_fresh_tmp(l0, 2062u, l3);
    vader_struct_vader_midir_InstrArrayLen_t* _a0_obj = (vader_struct_vader_midir_InstrArrayLen_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrArrayLen_t));
    vader_obj_header_init(_a0_obj, 1094u);
    _a0_obj->f_span = ((vader_struct_vader_lower_LoweredArrayLen_t*) l1)->f_span;
    _a0_obj->f_dst = l4;
    _a0_obj->f_target = l2;
    l5 = (void*) _a0_obj;
    vader_midir_emit(l0, vader_ref_box(l5));
    { vader_box_t __vret = vader_box_i32(288u, l4); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir_build_array_lit(void* l0, void* l1) {
    void* l2 = NULL;
    void* l4 = NULL;
    vader_box_t l3 = vader_box_null(), l7 = vader_box_null(), l9 = vader_box_null();
    int64_t l5, l6;
    int32_t l8, l10;
    int64_t t0;
    vader_box_t* gc_roots[3] = { &l3, &l7, &l9 };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(15u, 0u, 7u, 288u);
    l2 = (void*) _a0_arr;
    l3 = vader_midir_element_slot(((vader_struct_vader_lower_LoweredArrayLit_t*) l1)->f_type);
    l4 = ((vader_struct_vader_lower_LoweredArrayLit_t*) l1)->f_elements;
    l5 = ((vader_array_t*) l4)->length;
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l6)
        l7 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l6);
        l9 = vader_midir_build_held(l0, l7, l3);
        if (l9.tag == 0u) {
            { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
        }
        l8 = ((int32_t) l9.payload.i);
        vader_array_push_i32((vader_array_t*) l2, l8);
        l6 = (l6 + INT64_C(1));
    }
    l3 = ((vader_struct_vader_lower_LoweredArrayLit_t*) l1)->f_type;
    l8 = vader_midir_fresh_tmp(l0, 1391u, l3);
    l4 = ((vader_struct_vader_lower_LoweredArrayLit_t*) l1)->f_span;
    l3 = ((vader_struct_vader_lower_LoweredArrayLit_t*) l1)->f_type;
    t0 = ((vader_array_t*) ((vader_struct_vader_lower_LoweredArrayLit_t*) l1)->f_elements)->length;
    l10 = ((int32_t) (int64_t) t0);
    vader_struct_vader_midir_InstrArrayNew_t* _a2_obj = (vader_struct_vader_midir_InstrArrayNew_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrArrayNew_t));
    vader_obj_header_init(_a2_obj, 1095u);
    _a2_obj->f_span = l4;
    _a2_obj->f_dst = l8;
    _a2_obj->f_type = l3;
    _a2_obj->f_length = l10;
    _a2_obj->f_elements = l2;
    _a2_obj->f_stack = false;
    l2 = (void*) _a2_obj;
    vader_midir_emit(l0, vader_ref_box(l2));
    { vader_box_t __vret = vader_box_i32(288u, l8); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir_build_array_push(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l3 = vader_box_null(), l4 = vader_box_null();
    void* l5 = NULL;
    int32_t l6, l7;
    bool l8;
    vader_box_t* gc_roots[3] = { &l2, &l3, &l4 };
    void** gc_raw_roots[3] = { &l0, &l1, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_lower_LoweredArrayPush_t*) l1)->f_target;
    l2 = vader_midir_build_expr(l0, l2);
    l3 = ((vader_struct_vader_lower_LoweredArrayPush_t*) l1)->f_value;
    l4 = vader_midir_element_slot(VADER_UNION_FIELD(vader_box_t, vader_struct_vader_lower_LoweredArrayLen_t, f_type, ((vader_struct_vader_lower_LoweredArrayPush_t*) l1)->f_target.payload.obj));
    l3 = vader_midir_build_held(l0, l3, l4);
    if (l2.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    if (!(l3.tag == 0u)) {
        l5 = ((vader_struct_vader_lower_LoweredArrayPush_t*) l1)->f_span;
        l6 = ((int32_t) l2.payload.i);
        l7 = ((int32_t) l3.payload.i);
        l8 = ((vader_struct_vader_lower_LoweredArrayPush_t*) l1)->f_cached;
        vader_struct_vader_midir_InstrArrayPush_t* _a0_obj = (vader_struct_vader_midir_InstrArrayPush_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrArrayPush_t));
        vader_obj_header_init(_a0_obj, 1096u);
        _a0_obj->f_span = l5;
        _a0_obj->f_target = l6;
        _a0_obj->f_value = l7;
        _a0_obj->f_cached = l8;
        l5 = (void*) _a0_obj;
        vader_midir_emit(l0, vader_ref_box(l5));
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static vader_box_t vader_midir_build_array_slice(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l3 = vader_box_null(), l5 = vader_box_null(), l6 = vader_box_null();
    void* l4 = NULL;
    int32_t l7, l8, l9, l10;
    void* t0 = NULL;
    vader_box_t* gc_roots[4] = { &l2, &l3, &l5, &l6 };
    void** gc_raw_roots[4] = { &l0, &l1, &l4, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_lower_LoweredArraySlice_t*) l1)->f_target;
    l2 = vader_midir_build_expr(l0, l2);
    l3 = ((vader_struct_vader_lower_LoweredArraySlice_t*) l1)->f_lo;
    t0 = (void*) &vader_data_23;
    vader_array_t* _a0_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    l4 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT64_C(0));
    l3 = vader_midir_build_held(l0, l3, vader_ref_box(l4));
    l5 = ((vader_struct_vader_lower_LoweredArraySlice_t*) l1)->f_hi;
    t0 = (void*) &vader_data_23;
    vader_array_t* _a1_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    l4 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) INT64_C(0));
    l5 = vader_midir_build_held(l0, l5, vader_ref_box(l4));
    if (l2.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    if (l3.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    if (!(l5.tag == 0u)) {
        l6 = ((vader_struct_vader_lower_LoweredArraySlice_t*) l1)->f_type;
        l7 = vader_midir_fresh_tmp(l0, 2352u, l6);
        l4 = ((vader_struct_vader_lower_LoweredArraySlice_t*) l1)->f_span;
        l6 = ((vader_struct_vader_lower_LoweredArraySlice_t*) l1)->f_type;
        l8 = ((int32_t) l2.payload.i);
        l9 = ((int32_t) l3.payload.i);
        l10 = ((int32_t) l5.payload.i);
        vader_struct_vader_midir_InstrArraySlice_t* _a2_obj = (vader_struct_vader_midir_InstrArraySlice_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrArraySlice_t));
        vader_obj_header_init(_a2_obj, 1098u);
        _a2_obj->f_span = l4;
        _a2_obj->f_dst = l7;
        _a2_obj->f_type = l6;
        _a2_obj->f_target = l8;
        _a2_obj->f_lo = l9;
        _a2_obj->f_hi = l10;
        l4 = (void*) _a2_obj;
        vader_midir_emit(l0, vader_ref_box(l4));
        { vader_box_t __vret = vader_box_i32(288u, l7); vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static void vader_midir_build_assign(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l5 = vader_box_null(), l8 = vader_box_null(), l10 = vader_box_null(), l12 = vader_box_null();
    void* l3 = NULL;
    void* l6 = NULL;
    int32_t l4, l11, l13;
    vader_string_t l7 = 0;
    int64_t l9;
    bool l14;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    vader_string_t t3 = 0;
    int32_t t2;
    vader_box_t* gc_roots[5] = { &l2, &l5, &l8, &l10, &l12 };
    void** gc_raw_roots[5] = { &l0, &l1, &l3, &l6, &t0 };
    vader_string_t* gc_atom_roots[3] = { &l7, &t1, &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 5u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_lower_LoweredAssign_t*) l1)->f_target;
    if (l2.tag == 1020u) {
        l3 = ((vader_struct_vader_midir_FnCtx_t*) l0)->f_local_by_sym_id;
        t0 = l2.payload.obj;
        l4 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_lower_LoweredIdent_t*) t0)->f_symbol)->f_id;
        l5 = std_collections_MutableMap_std_core_Index_at__i32__i32(l3, l4);
        if (l5.tag == 0u) {
            l3 = ((vader_struct_vader_midir_ProjectCtx_t*) ((vader_struct_vader_midir_FnCtx_t*) l0)->f_project)->f_diags;
            t0 = l2.payload.obj;
            l6 = ((vader_struct_vader_lower_LoweredIdent_t*) t0)->f_span;
            t0 = l2.payload.obj;
            l7 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_lower_LoweredIdent_t*) t0)->f_symbol)->f_name;
            t1 = concat_3(910u, l7, 1008u);
            l7 = concat_2(t1, 2492u);
            l6 = vader_diagnostics_lower_error((uint8_t) 6, l6, l7);
            vader_array_push((vader_array_t*) l3, vader_ref_box(l6));
            { vader_gc_top = gc_frame.prev; return; }
        }
        l8 = ((vader_struct_vader_lower_LoweredAssign_t*) l1)->f_value;
        l3 = ((vader_struct_vader_midir_FnCtx_t*) l0)->f_locals;
        t2 = ((int32_t) l5.payload.i);
        l9 = ((int64_t) (int32_t) t2);
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l9)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l9);
        l10 = ((vader_struct_vader_midir_CFGLocal_t*) t0)->f_type;
        l8 = vader_midir_build_held(l0, l8, l10);
        if (l8.tag == 0u) {
            { vader_gc_top = gc_frame.prev; return; }
        }
        l4 = ((int32_t) l8.payload.i);
        l3 = ((vader_struct_vader_lower_LoweredAssign_t*) l1)->f_span;
        l11 = ((int32_t) l5.payload.i);
        vader_struct_vader_midir_InstrMove_t* _a1_obj = (vader_struct_vader_midir_InstrMove_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrMove_t));
        vader_obj_header_init(_a1_obj, 1118u);
        _a1_obj->f_span = l3;
        _a1_obj->f_dst = l11;
        _a1_obj->f_src = l4;
        l3 = (void*) _a1_obj;
        vader_midir_emit(l0, vader_ref_box(l3));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 1015u) {
        t0 = l2.payload.obj;
        l5 = ((vader_struct_vader_lower_LoweredFieldAccess_t*) t0)->f_target;
        l5 = vader_midir_build_expr(l0, l5);
        l8 = ((vader_struct_vader_lower_LoweredAssign_t*) l1)->f_value;
        l3 = l2.payload.obj;
        l10 = vader_midir_place_slot(l0, l5, vader_ref_box(l3));
        l8 = vader_midir_build_held(l0, l8, l10);
        if (l5.tag == 0u) {
            { vader_gc_top = gc_frame.prev; return; }
        }
        if (!(l8.tag == 0u)) {
            l3 = ((vader_struct_vader_lower_LoweredAssign_t*) l1)->f_span;
            l4 = ((int32_t) l5.payload.i);
            t0 = l2.payload.obj;
            l7 = ((vader_struct_vader_lower_LoweredFieldAccess_t*) t0)->f_field;
            l11 = ((int32_t) l8.payload.i);
            vader_struct_vader_midir_InstrFieldSet_t* _a2_obj = (vader_struct_vader_midir_InstrFieldSet_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrFieldSet_t));
            vader_obj_header_init(_a2_obj, 1111u);
            _a2_obj->f_span = l3;
            _a2_obj->f_target = l4;
            _a2_obj->f_field = l7;
            _a2_obj->f_value = l11;
            _a2_obj->f_barrierless = false;
            l3 = (void*) _a2_obj;
            vader_midir_emit(l0, vader_ref_box(l3));
            { vader_gc_top = gc_frame.prev; return; }
        }
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 1042u) {
        t0 = l2.payload.obj;
        l5 = ((vader_struct_vader_lower_LoweredUnionField_t*) t0)->f_target;
        l5 = vader_midir_build_expr(l0, l5);
        l8 = ((vader_struct_vader_lower_LoweredAssign_t*) l1)->f_value;
        l3 = l2.payload.obj;
        l10 = vader_midir_place_slot(l0, l5, vader_ref_box(l3));
        l8 = vader_midir_build_held(l0, l8, l10);
        if (l5.tag == 0u) {
            { vader_gc_top = gc_frame.prev; return; }
        }
        if (!(l8.tag == 0u)) {
            l3 = ((vader_struct_vader_lower_LoweredAssign_t*) l1)->f_span;
            l4 = ((int32_t) l5.payload.i);
            t0 = l2.payload.obj;
            l7 = ((vader_struct_vader_lower_LoweredUnionField_t*) t0)->f_field;
            l11 = ((int32_t) l8.payload.i);
            vader_struct_vader_midir_InstrUnionFieldSet_t* _a3_obj = (vader_struct_vader_midir_InstrUnionFieldSet_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrUnionFieldSet_t));
            vader_obj_header_init(_a3_obj, 1124u);
            _a3_obj->f_span = l3;
            _a3_obj->f_target = l4;
            _a3_obj->f_field = l7;
            _a3_obj->f_value = l11;
            l3 = (void*) _a3_obj;
            vader_midir_emit(l0, vader_ref_box(l3));
            { vader_gc_top = gc_frame.prev; return; }
        }
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (!(l2.tag == 1022u)) {
        l7 = ((vader_struct_vader_midir_FnCtx_t*) l0)->f_mangled;
        t1 = concat_3(2127u, l7, 1165u);
        t3 = concat_2(t1, 2544u);
        vader_host_std_abort_panic(t3);
        vader_unreachable("a no-return call returned");
    }
    t0 = l2.payload.obj;
    l5 = ((vader_struct_vader_lower_LoweredIndex_t*) t0)->f_target;
    l5 = vader_midir_build_expr(l0, l5);
    t0 = l2.payload.obj;
    l8 = ((vader_struct_vader_lower_LoweredIndex_t*) t0)->f_index;
    l8 = vader_midir_build_expr(l0, l8);
    l10 = ((vader_struct_vader_lower_LoweredAssign_t*) l1)->f_value;
    l3 = l2.payload.obj;
    l12 = vader_midir_place_slot(l0, l5, vader_ref_box(l3));
    l10 = vader_midir_build_held(l0, l10, l12);
    if (l5.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l8.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (!(l10.tag == 0u)) {
        l3 = ((vader_struct_vader_lower_LoweredAssign_t*) l1)->f_span;
        l4 = ((int32_t) l5.payload.i);
        l11 = ((int32_t) l8.payload.i);
        l13 = ((int32_t) l10.payload.i);
        t0 = l2.payload.obj;
        l14 = ((vader_struct_vader_lower_LoweredIndex_t*) t0)->f_bounds_safe;
        vader_struct_vader_midir_InstrArraySet_t* _a4_obj = (vader_struct_vader_midir_InstrArraySet_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrArraySet_t));
        vader_obj_header_init(_a4_obj, 1097u);
        _a4_obj->f_span = l3;
        _a4_obj->f_target = l4;
        _a4_obj->f_index = l11;
        _a4_obj->f_value = l13;
        _a4_obj->f_bounds_safe = l14;
        l3 = (void*) _a4_obj;
        vader_midir_emit(l0, vader_ref_box(l3));
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_midir_build_back_edge(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    int64_t l4, l5;
    vader_box_t l6 = vader_box_null();
    int32_t l7;
    vader_box_t* gc_roots[1] = { &l6 };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_midir_LoopFrame_t*) l1)->f_step;
    l4 = ((vader_array_t*) l3)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
        l6 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
        vader_midir_build_stmt(l0, l6);
        l5 = (l5 + INT64_C(1));
    }
    if (((vader_struct_vader_midir_FnCtx_t*) l0)->f_current.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l7 = ((vader_struct_vader_midir_LoopFrame_t*) l1)->f_header_id;
    vader_struct_vader_midir_TermBranch_t* _a1_obj = (vader_struct_vader_midir_TermBranch_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_TermBranch_t));
    vader_obj_header_init(_a1_obj, 1136u);
    _a1_obj->f_span = l2;
    _a1_obj->f_target = l7;
    l3 = (void*) _a1_obj;
    vader_midir_terminate(l0, vader_ref_box(l3));
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_midir_build_binary(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l4 = vader_box_null();
    int32_t l3, l5, l7;
    vader_string_t l6 = 0;
    void* l8 = NULL;
    uint8_t l9;
    bool t0;
    vader_box_t t1 = vader_box_null();
    int32_t t2;
    vader_box_t* gc_roots[3] = { &l2, &l4, &t1 };
    void** gc_raw_roots[3] = { &l0, &l1, &l8 };
    vader_string_t* gc_atom_roots[1] = { &l6 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_midir_is_short_circuit_op(((vader_struct_vader_lower_LoweredBinary_t*) l1)->f_op);
    if (t0) {
        t1 = vader_midir_build_short_circuit(l0, l1, vader_box_obj(0u, NULL));
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = vader_midir_binary_width(l0, l1);
    l4 = ((vader_struct_vader_lower_LoweredBinary_t*) l1)->f_left;
    l4 = vader_midir_build_held(l0, l4, l2);
    if (l4.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l3 = ((int32_t) l4.payload.i);
    l4 = ((vader_struct_vader_lower_LoweredBinary_t*) l1)->f_right;
    l4 = vader_midir_build_held(l0, l4, l2);
    if (l4.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l5 = ((int32_t) l4.payload.i);
    l2 = vader_midir_computed_type(((vader_struct_vader_lower_LoweredBinary_t*) l1)->f_type, l2);
    l6 = vader_lower_binary_op_name(((vader_struct_vader_lower_LoweredBinary_t*) l1)->f_op);
    l7 = vader_midir_fresh_tmp(l0, l6, l2);
    l8 = ((vader_struct_vader_lower_LoweredBinary_t*) l1)->f_span;
    l9 = ((vader_struct_vader_lower_LoweredBinary_t*) l1)->f_op;
    vader_struct_vader_midir_InstrBinOp_t* _a0_obj = (vader_struct_vader_midir_InstrBinOp_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrBinOp_t));
    vader_obj_header_init(_a0_obj, 1099u);
    _a0_obj->f_span = l8;
    _a0_obj->f_dst = l7;
    _a0_obj->f_op = l9;
    _a0_obj->f_lhs = l3;
    _a0_obj->f_rhs = l5;
    _a0_obj->f_type = l2;
    l8 = (void*) _a0_obj;
    vader_midir_emit(l0, vader_ref_box(l8));
    l2 = ((vader_struct_vader_lower_LoweredBinary_t*) l1)->f_type;
    l8 = ((vader_struct_vader_lower_LoweredBinary_t*) l1)->f_span;
    t2 = vader_midir_held_in(l0, l7, l2, l8);
    { vader_box_t __vret = vader_box_i32(288u, t2); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir_build_block_body(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l2, &t0 };
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_lower_LoweredBlock_t*) l1)->f_type;
    t0 = vader_midir_build_block_value(l0, l1, l2);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_midir_build_block_into(void* l0, void* l1, int32_t l2) {
    void* l3 = NULL;
    int64_t l4, l5;
    vader_box_t l6 = vader_box_null();
    vader_box_t* gc_roots[1] = { &l6 };
    void** gc_raw_roots[3] = { &l0, &l1, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_lower_LoweredBlock_t*) l1)->f_stmts;
    l4 = ((vader_array_t*) l3)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
        l6 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
        if (((vader_struct_vader_midir_FnCtx_t*) l0)->f_current.tag == 0u) {
            { vader_gc_top = gc_frame.prev; return; }
        }
        vader_midir_build_stmt(l0, l6);
        l5 = (l5 + INT64_C(1));
    }
    if (((vader_struct_vader_midir_FnCtx_t*) l0)->f_current.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (((vader_struct_vader_lower_LoweredBlock_t*) l1)->f_trailing.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l6 = ((vader_struct_vader_lower_LoweredBlock_t*) l1)->f_trailing;
    vader_midir_build_expr_into(l0, l6, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_midir_build_block_value(void* l0, void* l1, vader_box_t l2) {
    void* l3 = NULL;
    int64_t l4, l5;
    vader_box_t l6 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l2, &l6, &t0 };
    void** gc_raw_roots[3] = { &l0, &l1, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_lower_LoweredBlock_t*) l1)->f_stmts;
    l4 = ((vader_array_t*) l3)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
        l6 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
        if (((vader_struct_vader_midir_FnCtx_t*) l0)->f_current.tag == 0u) {
            { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
        }
        vader_midir_build_stmt(l0, l6);
        l5 = (l5 + INT64_C(1));
    }
    if (((vader_struct_vader_midir_FnCtx_t*) l0)->f_current.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    if (!(((vader_struct_vader_lower_LoweredBlock_t*) l1)->f_trailing.tag == 0u)) {
        l6 = ((vader_struct_vader_lower_LoweredBlock_t*) l1)->f_trailing;
        t0 = vader_midir_build_held(l0, l6, l2);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static vader_box_t vader_midir_build_call(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l5 = vader_box_null(), l11 = vader_box_null();
    void* l3 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    int32_t l4;
    vader_string_t l9 = 0;
    bool l10;
    void* t0 = NULL;
    bool t1;
    int32_t t2;
    vader_box_t t3 = vader_box_null();
    vader_box_t* gc_roots[4] = { &l2, &l5, &l11, &t3 };
    void** gc_raw_roots[7] = { &l0, &l1, &l3, &l6, &l7, &l8, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l9 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_lower_LoweredCall_t*) l1)->f_callee;
    if (l2.tag == 1020u) {
        t0 = l2.payload.obj;
        if (((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_lower_LoweredIdent_t*) t0)->f_symbol)->f_kind == INT32_C(0)) {
            l3 = ((vader_struct_vader_midir_ProjectCtx_t*) ((vader_struct_vader_midir_FnCtx_t*) l0)->f_project)->f_extern_callbacks;
            t0 = l2.payload.obj;
            l4 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_lower_LoweredIdent_t*) t0)->f_symbol)->f_id;
            l5 = std_collections_MutableMap_std_core_Index_at__i32__Any(l3, l4);
            l3 = ((vader_struct_vader_midir_ProjectCtx_t*) ((vader_struct_vader_midir_FnCtx_t*) l0)->f_project)->f_slots;
            t0 = l2.payload.obj;
            l6 = ((vader_struct_vader_lower_LoweredIdent_t*) t0)->f_symbol;
            l3 = vader_midir_params_of(l3, l6);
            if (l5.tag == 518u) {
                l7 = ((vader_struct_vader_lower_LoweredCall_t*) l1)->f_args;
                l8 = l5.payload.obj;
                t0 = l2.payload.obj;
                l9 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_lower_LoweredIdent_t*) t0)->f_symbol)->f_name;
                l5 = vader_midir_build_extern_args(l0, l7, l3, l8, l9);
                if (l5.tag == 0u) {
                    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
                }
                l6 = l5.payload.obj;
            } else {
                l7 = ((vader_struct_vader_lower_LoweredCall_t*) l1)->f_args;
                l5 = vader_midir_build_args(l0, l7, l3);
                if (l5.tag == 0u) {
                    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
                }
                l6 = l5.payload.obj;
            }
            t1 = vader_typecheck_is_void(((vader_struct_vader_lower_LoweredCall_t*) l1)->f_type);
            if (t1) {
                l10 = true;
            } else {
                l10 = ((vader_struct_vader_lower_LoweredCall_t*) l1)->f_type.tag == 1260u;
            }
            if (l10) {
                l5 = vader_box_obj(0u, NULL);
            } else {
                l11 = ((vader_struct_vader_lower_LoweredCall_t*) l1)->f_type;
                t2 = vader_midir_fresh_tmp(l0, 1533u, l11);
                l5 = vader_box_i32(288u, t2);
            }
            l3 = ((vader_struct_vader_lower_LoweredCall_t*) l1)->f_span;
            if (l5.tag == 0u) {
                vader_array_t* _a0_arr = vader_array_new(15u, 0u, 7u, 288u);
                l7 = (void*) _a0_arr;
            } else {
                t2 = ((int32_t) l5.payload.i);
                vader_array_t* _a1_arr = vader_array_new(15u, 1u, 7u, 288u);
                ((int32_t*) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = (int32_t) t2;
                l7 = (void*) _a1_arr;
            }
            t0 = l2.payload.obj;
            l8 = ((vader_struct_vader_lower_LoweredIdent_t*) t0)->f_symbol;
            l2 = ((vader_struct_vader_lower_LoweredCall_t*) l1)->f_type;
            vader_struct_vader_midir_InstrCall_t* _a2_obj = (vader_struct_vader_midir_InstrCall_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrCall_t));
            vader_obj_header_init(_a2_obj, 1100u);
            _a2_obj->f_span = l3;
            _a2_obj->f_dsts = l7;
            _a2_obj->f_callee = l8;
            _a2_obj->f_args = l6;
            _a2_obj->f_type = l2;
            l3 = (void*) _a2_obj;
            vader_midir_emit(l0, vader_ref_box(l3));
            t3 = vader_midir_end_after_no_return(l0, l1, l5);
            { vader_box_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    l2 = ((vader_struct_vader_lower_LoweredCall_t*) l1)->f_callee;
    l2 = vader_midir_build_expr(l0, l2);
    if (l2.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l4 = ((int32_t) l2.payload.i);
    l6 = ((vader_struct_vader_lower_LoweredCall_t*) l1)->f_args;
    l7 = vader_lower_param_types_of(VADER_UNION_FIELD(vader_box_t, vader_struct_vader_lower_LoweredArrayLen_t, f_type, ((vader_struct_vader_lower_LoweredCall_t*) l1)->f_callee.payload.obj));
    l2 = vader_midir_build_args(l0, l6, l7);
    if (l2.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l3 = l2.payload.obj;
    t1 = vader_typecheck_is_void(((vader_struct_vader_lower_LoweredCall_t*) l1)->f_type);
    if (t1) {
        l10 = true;
    } else {
        l10 = ((vader_struct_vader_lower_LoweredCall_t*) l1)->f_type.tag == 1260u;
    }
    if (l10) {
        l2 = vader_box_obj(0u, NULL);
    } else {
        l5 = ((vader_struct_vader_lower_LoweredCall_t*) l1)->f_type;
        t2 = vader_midir_fresh_tmp(l0, 1540u, l5);
        l2 = vader_box_i32(288u, t2);
    }
    l6 = ((vader_struct_vader_lower_LoweredCall_t*) l1)->f_span;
    l5 = VADER_UNION_FIELD(vader_box_t, vader_struct_vader_lower_LoweredArrayLen_t, f_type, ((vader_struct_vader_lower_LoweredCall_t*) l1)->f_callee.payload.obj);
    l11 = ((vader_struct_vader_lower_LoweredCall_t*) l1)->f_type;
    vader_struct_vader_midir_InstrCallIndirect_t* _a3_obj = (vader_struct_vader_midir_InstrCallIndirect_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrCallIndirect_t));
    vader_obj_header_init(_a3_obj, 1101u);
    _a3_obj->f_span = l6;
    _a3_obj->f_dst = l2;
    _a3_obj->f_callee = l4;
    _a3_obj->f_args = l3;
    _a3_obj->f_fn_type = l5;
    _a3_obj->f_type = l11;
    l3 = (void*) _a3_obj;
    vader_midir_emit(l0, vader_ref_box(l3));
    t3 = vader_midir_end_after_no_return(l0, l1, l2);
    { vader_box_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir_build_cast(void* l0, void* l1) {
    int32_t l2;
    vader_box_t l3 = vader_box_null();
    void* l4 = NULL;
    int32_t t0;
    vader_box_t* gc_roots[1] = { &l3 };
    void** gc_raw_roots[3] = { &l0, &l1, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = vader_midir_build_cast_source(l0, l1);
    if (l3.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l2 = ((int32_t) l3.payload.i);
    l3 = ((vader_struct_vader_lower_LoweredCast_t*) l1)->f_type;
    l4 = ((vader_struct_vader_lower_LoweredCast_t*) l1)->f_span;
    t0 = vader_midir_cast_local(l0, l2, l3, 1559u, l4);
    { vader_box_t __vret = vader_box_i32(288u, t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir_build_cast_source(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null();
    bool t0;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l2, &t1 };
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_types_is_stored_as_integer(((vader_struct_vader_lower_LoweredCast_t*) l1)->f_type);
    if (!(t0)) {
        l2 = ((vader_struct_vader_lower_LoweredCast_t*) l1)->f_value;
        t1 = vader_midir_build_expr(l0, l2);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = ((vader_struct_vader_lower_LoweredCast_t*) l1)->f_value;
    t1 = vader_midir_build_stored(l0, l2);
    { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir_build_cell_get(void* l0, void* l1) {
    int32_t l2;
    vader_box_t l3 = vader_box_null();
    void* l4 = NULL;
    int32_t t0;
    vader_box_t* gc_roots[1] = { &l3 };
    void** gc_raw_roots[3] = { &l0, &l1, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = vader_midir_stored_cell(l0, l1);
    if (l3.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l2 = ((int32_t) l3.payload.i);
    l3 = ((vader_struct_vader_lower_LoweredCellGet_t*) l1)->f_type;
    l4 = ((vader_struct_vader_lower_LoweredCellGet_t*) l1)->f_span;
    t0 = vader_midir_read_as(l0, l2, l3, l4);
    { vader_box_t __vret = vader_box_i32(288u, t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir_build_cell_new(void* l0, void* l1) {
    int32_t l2, l5;
    vader_box_t l3 = vader_box_null(), l4 = vader_box_null();
    void* l6 = NULL;
    vader_box_t* gc_roots[2] = { &l3, &l4 };
    void** gc_raw_roots[3] = { &l0, &l1, &l6 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_lower_LoweredCellNew_t*) l1)->f_value;
    l4 = ((vader_struct_vader_lower_LoweredCellNew_t*) l1)->f_value_type;
    l3 = vader_midir_build_held(l0, l3, l4);
    if (l3.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l2 = ((int32_t) l3.payload.i);
    l3 = ((vader_struct_vader_lower_LoweredCellNew_t*) l1)->f_type;
    l5 = vader_midir_fresh_tmp(l0, 1560u, l3);
    l6 = ((vader_struct_vader_lower_LoweredCellNew_t*) l1)->f_span;
    l3 = ((vader_struct_vader_lower_LoweredCellNew_t*) l1)->f_value_type;
    vader_struct_vader_midir_InstrCellNew_t* _a0_obj = (vader_struct_vader_midir_InstrCellNew_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrCellNew_t));
    vader_obj_header_init(_a0_obj, 1104u);
    _a0_obj->f_span = l6;
    _a0_obj->f_dst = l5;
    _a0_obj->f_value = l2;
    _a0_obj->f_value_type = l3;
    l6 = (void*) _a0_obj;
    vader_midir_emit(l0, vader_ref_box(l6));
    { vader_box_t __vret = vader_box_i32(288u, l5); vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_midir_build_cfg_project(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l11 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    void* l15 = NULL;
    void* l19 = NULL;
    void* l21 = NULL;
    void* l22 = NULL;
    void* l25 = NULL;
    int64_t l7, l8, l16, l17;
    vader_string_t l9 = 0;
    vader_string_t l10 = 0;
    vader_string_t l23 = 0;
    vader_string_t l24 = 0;
    vader_box_t l18 = vader_box_null(), l20 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    vader_box_t* gc_roots[3] = { &l18, &l20, &t0 };
    void** gc_raw_roots[17] = {
        &l0, &l1, &l2, &l3, &l4, &l5, &l6, &l11, &l12, &l13, &l14, &l15, &l19, &l21, &l22, &l25,
        &t1,
    };
    vader_string_t* gc_atom_roots[4] = { &l9, &l10, &l23, &l24 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 17u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_midir_new_project_ctx(l0, l1);
    vader_array_t* _a0_arr = vader_array_new(14u, 0u, 0u, 285u);
    l3 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(21u, 0u, 0u, 296u);
    l4 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(15u, 0u, 7u, 288u);
    l5 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__string__Any_t* _a3_obj = (vader_struct_std_collections_MutableMap__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__Any_t));
    vader_obj_header_init(_a3_obj, 448u);
    _a3_obj->f_ekeys = l3;
    _a3_obj->f_evals = l4;
    _a3_obj->f_index = l5;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    l3 = (void*) _a3_obj;
    l4 = ((vader_struct_vader_lower_LoweredProject_t*) l0)->f_modules;
    l5 = ((vader_struct_std_collections_MutableMap__string__vader_lower_LoweredModule_t*) l4)->f_ekeys;
    l6 = ((vader_struct_std_collections_MutableMap__string__vader_lower_LoweredModule_t*) l4)->f_evals;
    l7 = INT64_C(0);
    l8 = ((vader_struct_std_collections_MutableMap__string__vader_lower_LoweredModule_t*) l4)->f_size;
    while ((l7 < l8)) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l7)
        t0 = vader_array_box_slots(_a4_slotarr->buf)[_a4_slotarr->offset + (size_t) l7];
        l9 = t0.payload.s;
        vader_array_t* _a5_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l7)
        l4 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l7);
        l10 = l9;
        l11 = l4;
        vader_array_t* _a6_arr = vader_array_new(137u, 0u, 13u, 1071u);
        l12 = (void*) _a6_arr;
        vader_array_t* _a7_arr = vader_array_new(136u, 0u, 13u, 1070u);
        l13 = (void*) _a7_arr;
        vader_array_t* _a8_arr = vader_array_new(141u, 0u, 13u, 1076u);
        l14 = (void*) _a8_arr;
        l15 = ((vader_struct_vader_lower_LoweredModule_t*) l11)->f_decls;
        l16 = ((vader_array_t*) l15)->length;
        l17 = INT64_C(0);
        while ((l17 < l16)) {
            vader_array_t* _a9_slotarr = ((vader_array_t*) l15);
            VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l17)
            l18 = vader_array_ref_load_box(_a9_slotarr->buf, _a9_slotarr->offset + (size_t) l17);
            if (l18.tag == 1017u) {
                t1 = l18.payload.obj;
                if (((vader_struct_vader_lower_LoweredFnDecl_t*) t1)->f_body.tag == 0u) {
                    t1 = l18.payload.obj;
                    l19 = vader_midir_make_extern_decl(t1);
                    vader_array_push((vader_array_t*) l13, vader_ref_box(l19));
                } else {
                    t1 = l18.payload.obj;
                    l20 = vader_midir_convert_function(t1, l2);
                    if (!(l20.tag == 0u)) {
                        l21 = l20.payload.obj;
                        vader_array_push((vader_array_t*) l12, vader_ref_box(l21));
                    }
                }
            } else if (l18.tag == 1035u) {
                t1 = l18.payload.obj;
                l22 = vader_midir_make_struct_decl(t1);
                vader_array_push((vader_array_t*) l14, vader_ref_box(l22));
            } else if (!(l18.tag == 1009u)) {
                vader_unreachable("non-exhaustive match (T3013 should have caught this)");
            }
            l17 = (l17 + INT64_C(1));
        }
        l23 = ((vader_struct_vader_lower_LoweredModule_t*) l11)->f_module_id;
        l24 = ((vader_struct_vader_lower_LoweredModule_t*) l11)->f_display_path;
        vader_struct_vader_midir_CFGModule_t* _a10_obj = (vader_struct_vader_midir_CFGModule_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_CFGModule_t));
        vader_obj_header_init(_a10_obj, 1073u);
        _a10_obj->f_module_id = l23;
        _a10_obj->f_display_path = l24;
        _a10_obj->f_functions = l12;
        _a10_obj->f_externs = l13;
        _a10_obj->f_struct_decls = l14;
        l25 = (void*) _a10_obj;
        std_collections_MutableMap_std_core_IndexSet_set_at__string__Any(l3, l10, vader_ref_box(l25));
        l7 = (l7 + INT64_C(1));
    }
    l4 = ((vader_struct_vader_lower_LoweredProject_t*) l0)->f_vtable_entries;
    l2 = ((vader_struct_vader_midir_ProjectCtx_t*) l2)->f_strings;
    l5 = vader_midir_convert_data_pool(((vader_struct_vader_lower_LoweredProject_t*) l0)->f_data_pool);
    l6 = ((vader_struct_vader_lower_LoweredProject_t*) l0)->f_globals;
    l11 = ((vader_struct_vader_lower_LoweredProject_t*) l0)->f_trait_membership;
    vader_struct_vader_midir_CFGProject_t* _a11_obj = (vader_struct_vader_midir_CFGProject_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_CFGProject_t));
    vader_obj_header_init(_a11_obj, 1075u);
    _a11_obj->f_modules = l3;
    _a11_obj->f_vtable_entries = l4;
    _a11_obj->f_strings = l2;
    _a11_obj->f_data_pool = l5;
    _a11_obj->f_globals = l6;
    _a11_obj->f_trait_membership = l11;
    t1 = (void*) _a11_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_midir_build_cfg_signature(void* l0, vader_box_t l1, void* l2, void* l3) {
    void* l4 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l10 = NULL;
    void* l14 = NULL;
    void* l16 = NULL;
    int64_t l5, l9;
    uint8_t l11;
    int32_t l12;
    vader_string_t l13 = 0;
    vader_box_t l15 = vader_box_null();
    int64_t t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[2] = { &l1, &l15 };
    void** gc_raw_roots[11] = { &l0, &l2, &l3, &l4, &l6, &l7, &l8, &l10, &l14, &l16, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l13 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 11u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(17u, 0u, 1u, 290u);
    l4 = (void*) _a0_arr;
    l5 = ((vader_array_t*) l0)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l4, (int64_t) l5);
    l4 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(15u, 0u, 7u, 288u);
    l6 = (void*) _a2_arr;
    l5 = ((vader_array_t*) l0)->length;
    vader_array_t* _a3_arr = vader_array_repeat((vader_array_t*) l6, (int64_t) l5);
    l6 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_new(14u, 0u, 0u, 285u);
    l7 = (void*) _a4_arr;
    l5 = ((vader_array_t*) l0)->length;
    vader_array_t* _a5_arr = vader_array_repeat((vader_array_t*) l7, (int64_t) l5);
    l7 = (void*) _a5_arr;
    l8 = l0;
    l5 = ((vader_array_t*) l8)->length;
    l9 = INT64_C(0);
    while ((l9 < l5)) {
        vader_array_t* _a6_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        l10 = vader_array_ref_load_obj(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l9);
        l11 = vader_bytecode_val_type_of_type(((vader_struct_vader_midir_CFGParam_t*) l10)->f_type);
        vader_array_push_u8((vader_array_t*) l4, (int32_t) (uint8_t) l11);
        l12 = vader_bytecode_intern_type(((vader_struct_vader_midir_CFGParam_t*) l10)->f_type, l3);
        vader_array_push_i32((vader_array_t*) l6, l12);
        l13 = ((vader_struct_vader_midir_CFGParam_t*) l10)->f_name;
        vader_array_push((vader_array_t*) l7, vader_box_string(285u, l13));
        l9 = (l9 + INT64_C(1));
    }
    vader_array_t* _a7_arr = vader_array_new(17u, 0u, 1u, 290u);
    l8 = (void*) _a7_arr;
    vader_array_t* _a8_arr = vader_array_new(15u, 0u, 7u, 288u);
    l10 = (void*) _a8_arr;
    t0 = ((vader_array_t*) l2)->length;
    if ((t0 > INT64_C(1))) {
        l14 = l2;
        l5 = ((vader_array_t*) l14)->length;
        l9 = INT64_C(0);
        while ((l9 < l5)) {
            vader_array_t* _a9_slotarr = ((vader_array_t*) l14);
            VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
            l15 = vader_array_ref_load_box(_a9_slotarr->buf, _a9_slotarr->offset + (size_t) l9);
            l11 = vader_bytecode_val_type_of_type(l15);
            vader_array_push_u8((vader_array_t*) l8, (int32_t) (uint8_t) l11);
            l12 = vader_bytecode_intern_type(l15, l3);
            vader_array_push_i32((vader_array_t*) l10, l12);
            l9 = (l9 + INT64_C(1));
        }
    } else {
        l11 = vader_bytecode_val_type_of_type(l1);
        vader_array_push_u8((vader_array_t*) l8, (int32_t) (uint8_t) l11);
        l12 = vader_bytecode_intern_type(l1, l3);
        vader_array_push_i32((vader_array_t*) l10, l12);
    }
    vader_array_t* _a10_arr = vader_array_new(12u, 0u, 12u, 283u);
    l14 = (void*) _a10_arr;
    vader_array_t* _a11_arr = vader_array_new(12u, 0u, 12u, 283u);
    l16 = (void*) _a11_arr;
    vader_struct_vader_bytecode_BcSignature_t* _a12_obj = (vader_struct_vader_bytecode_BcSignature_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcSignature_t));
    vader_obj_header_init(_a12_obj, 650u);
    _a12_obj->f_params = l4;
    _a12_obj->f_results = l8;
    _a12_obj->f_param_types = l6;
    _a12_obj->f_result_types = l10;
    _a12_obj->f_param_names = l7;
    _a12_obj->f_param_c_out = l14;
    _a12_obj->f_param_by_address = l16;
    t1 = (void*) _a12_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir_build_data_const(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null();
    int32_t l3, l5;
    void* l4 = NULL;
    int64_t t0;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[3] = { &l0, &l1, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_lower_LoweredDataConst_t*) l1)->f_type;
    l3 = vader_midir_fresh_tmp(l0, 1630u, l2);
    l4 = ((vader_struct_vader_lower_LoweredDataConst_t*) l1)->f_span;
    l2 = ((vader_struct_vader_lower_LoweredDataConst_t*) l1)->f_type;
    t0 = ((vader_struct_vader_lower_LoweredDataConst_t*) l1)->f_pool_index;
    l5 = ((int32_t) (int64_t) t0);
    vader_struct_vader_midir_InstrDataConst_t* _a0_obj = (vader_struct_vader_midir_InstrDataConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrDataConst_t));
    vader_obj_header_init(_a0_obj, 1107u);
    _a0_obj->f_span = l4;
    _a0_obj->f_dst = l3;
    _a0_obj->f_type = l2;
    _a0_obj->f_pool_index = l5;
    l4 = (void*) _a0_obj;
    vader_midir_emit(l0, vader_ref_box(l4));
    { vader_box_t __vret = vader_box_i32(288u, l3); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir_build_expr(void* l0, vader_box_t l1) {
    vader_box_t l2 = vader_box_null();
    void* l3 = NULL;
    void* l4 = NULL;
    vader_string_t l5 = 0;
    int32_t l6;
    void* t0 = NULL;
    int64_t t1;
    int32_t t2;
    double t3;
    bool t4;
    uint32_t t5;
    vader_box_t t6 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l1, &l2, &t6 };
    void** gc_raw_roots[4] = { &l0, &l3, &l4, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l5 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (((vader_struct_vader_midir_FnCtx_t*) l0)->f_current.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    if (l1.tag == 1023u) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_vader_lower_LoweredIntLit_t*) t0)->f_type;
        t0 = l1.payload.obj;
        t1 = ((vader_struct_vader_lower_LoweredIntLit_t*) t0)->f_value;
        vader_struct_vader_midir_ConstInt_t* _a0_obj = (vader_struct_vader_midir_ConstInt_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_ConstInt_t));
        vader_obj_header_init(_a0_obj, 1083u);
        _a0_obj->f_value = t1;
        l3 = (void*) _a0_obj;
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_lower_LoweredIntLit_t*) t0)->f_span;
        t2 = vader_midir_emit_const(l0, l2, vader_ref_box(l3), l4);
        { vader_box_t __vret = vader_box_i32(288u, t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 1016u) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_vader_lower_LoweredFloatLit_t*) t0)->f_type;
        t0 = l1.payload.obj;
        t3 = ((vader_struct_vader_lower_LoweredFloatLit_t*) t0)->f_value;
        vader_struct_vader_midir_ConstFloat_t* _a1_obj = (vader_struct_vader_midir_ConstFloat_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_ConstFloat_t));
        vader_obj_header_init(_a1_obj, 1082u);
        _a1_obj->f_value = t3;
        l3 = (void*) _a1_obj;
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_lower_LoweredFloatLit_t*) t0)->f_span;
        t2 = vader_midir_emit_const(l0, l2, vader_ref_box(l3), l4);
        { vader_box_t __vret = vader_box_i32(288u, t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 1001u) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_vader_lower_LoweredBoolLit_t*) t0)->f_type;
        t0 = l1.payload.obj;
        t4 = ((vader_struct_vader_lower_LoweredBoolLit_t*) t0)->f_value;
        vader_struct_vader_midir_ConstBool_t* _a2_obj = (vader_struct_vader_midir_ConstBool_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_ConstBool_t));
        vader_obj_header_init(_a2_obj, 1080u);
        _a2_obj->f_value = t4;
        l3 = (void*) _a2_obj;
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_lower_LoweredBoolLit_t*) t0)->f_span;
        t2 = vader_midir_emit_const(l0, l2, vader_ref_box(l3), l4);
        { vader_box_t __vret = vader_box_i32(288u, t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 1030u) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_vader_lower_LoweredNullLit_t*) t0)->f_type;
        vader_struct_vader_midir_ConstNull_t* _a3_obj = (vader_struct_vader_midir_ConstNull_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_ConstNull_t));
        vader_obj_header_init(_a3_obj, 1084u);
        l3 = (void*) _a3_obj;
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_lower_LoweredNullLit_t*) t0)->f_span;
        t2 = vader_midir_emit_const(l0, l2, vader_ref_box(l3), l4);
        { vader_box_t __vret = vader_box_i32(288u, t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 1008u) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_vader_lower_LoweredCharLit_t*) t0)->f_type;
        t0 = l1.payload.obj;
        t5 = ((vader_struct_vader_lower_LoweredCharLit_t*) t0)->f_value;
        vader_struct_vader_midir_ConstChar_t* _a4_obj = (vader_struct_vader_midir_ConstChar_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_ConstChar_t));
        vader_obj_header_init(_a4_obj, 1081u);
        _a4_obj->f_value = ((int32_t) (uint32_t) t5);
        l3 = (void*) _a4_obj;
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_lower_LoweredCharLit_t*) t0)->f_span;
        t2 = vader_midir_emit_const(l0, l2, vader_ref_box(l3), l4);
        { vader_box_t __vret = vader_box_i32(288u, t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 1034u) {
        l3 = ((vader_struct_vader_midir_FnCtx_t*) l0)->f_project;
        t0 = l1.payload.obj;
        l5 = ((vader_struct_vader_lower_LoweredStringLit_t*) t0)->f_value;
        l6 = vader_midir_intern_string_pool(l3, l5);
        t0 = l1.payload.obj;
        l2 = ((vader_struct_vader_lower_LoweredStringLit_t*) t0)->f_type;
        vader_struct_vader_midir_ConstString_t* _a5_obj = (vader_struct_vader_midir_ConstString_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_ConstString_t));
        vader_obj_header_init(_a5_obj, 1085u);
        _a5_obj->f_index = l6;
        l3 = (void*) _a5_obj;
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_lower_LoweredStringLit_t*) t0)->f_span;
        t2 = vader_midir_emit_const(l0, l2, vader_ref_box(l3), l4);
        { vader_box_t __vret = vader_box_i32(288u, t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 1020u) {
        l3 = l1.payload.obj;
        t6 = vader_midir_build_ident(l0, l3);
        { vader_box_t __vret = t6; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 1003u) {
        l3 = l1.payload.obj;
        t6 = vader_midir_build_call(l0, l3);
        { vader_box_t __vret = t6; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 1044u) {
        l3 = l1.payload.obj;
        t6 = vader_midir_build_virtual_call(l0, l3);
        { vader_box_t __vret = t6; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 1015u) {
        l3 = l1.payload.obj;
        t6 = vader_midir_build_field_access(l0, l3);
        { vader_box_t __vret = t6; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 1042u) {
        l3 = l1.payload.obj;
        t6 = vader_midir_build_union_field(l0, l3);
        { vader_box_t __vret = t6; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 1022u) {
        l3 = l1.payload.obj;
        t6 = vader_midir_build_index(l0, l3);
        { vader_box_t __vret = t6; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 1041u) {
        l3 = l1.payload.obj;
        t6 = vader_midir_build_unary(l0, l3);
        { vader_box_t __vret = t6; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 999u) {
        l3 = l1.payload.obj;
        t6 = vader_midir_build_binary(l0, l3);
        { vader_box_t __vret = t6; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 1021u) {
        l3 = l1.payload.obj;
        t6 = vader_midir_build_if(l0, l3, vader_box_obj(0u, NULL));
        { vader_box_t __vret = t6; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 1000u) {
        l3 = l1.payload.obj;
        t6 = vader_midir_build_block_body(l0, l3);
        { vader_box_t __vret = t6; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 1037u) {
        l3 = l1.payload.obj;
        t6 = vader_midir_build_struct_lit(l0, l3);
        { vader_box_t __vret = t6; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 994u) {
        l3 = l1.payload.obj;
        t6 = vader_midir_build_array_lit(l0, l3);
        { vader_box_t __vret = t6; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 1004u) {
        l3 = l1.payload.obj;
        t6 = vader_midir_build_cast(l0, l3);
        { vader_box_t __vret = t6; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 1039u) {
        l3 = l1.payload.obj;
        t6 = vader_midir_build_type_check(l0, l3);
        { vader_box_t __vret = t6; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 1043u) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_vader_lower_LoweredUnreachable_t*) t0)->f_type;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_lower_LoweredUnreachable_t*) t0)->f_span;
        t0 = l1.payload.obj;
        l5 = ((vader_struct_vader_lower_LoweredUnreachable_t*) t0)->f_reason;
        t6 = vader_midir_build_unreachable_type(l0, l2, l3, l5);
        { vader_box_t __vret = t6; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 1024u) {
        l3 = l1.payload.obj;
        t6 = vader_midir_build_intrinsic_call(l0, l3);
        { vader_box_t __vret = t6; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 993u) {
        l3 = l1.payload.obj;
        t6 = vader_midir_build_array_len(l0, l3);
        { vader_box_t __vret = t6; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 995u) {
        l3 = l1.payload.obj;
        t6 = vader_midir_build_array_push(l0, l3);
        { vader_box_t __vret = t6; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 996u) {
        l3 = l1.payload.obj;
        t6 = vader_midir_build_array_slice(l0, l3);
        { vader_box_t __vret = t6; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 1006u) {
        l3 = l1.payload.obj;
        t6 = vader_midir_build_cell_new(l0, l3);
        { vader_box_t __vret = t6; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 1005u) {
        l3 = l1.payload.obj;
        t6 = vader_midir_build_cell_get(l0, l3);
        { vader_box_t __vret = t6; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 1028u) {
        l3 = l1.payload.obj;
        t6 = vader_midir_build_make_closure(l0, l3);
        { vader_box_t __vret = t6; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 1011u) {
        l3 = l1.payload.obj;
        t6 = vader_midir_build_data_const(l0, l3);
        { vader_box_t __vret = t6; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 1018u) {
        l3 = l1.payload.obj;
        t6 = vader_midir_build_global_get(l0, l3);
        { vader_box_t __vret = t6; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l1.tag == 1040u)) {
        vader_unreachable("non-exhaustive match (T3013 should have caught this)");
    }
    l3 = l1.payload.obj;
    t6 = vader_midir_build_type_const(l0, l3);
    { vader_box_t __vret = t6; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_midir_build_expr_into(void* l0, vader_box_t l1, int32_t l2) {
    void* l3 = NULL;
    vader_box_t l4 = vader_box_null(), l6 = vader_box_null();
    int64_t l5;
    int32_t l7;
    void* t0 = NULL;
    bool t1;
    vader_box_t* gc_roots[3] = { &l1, &l4, &l6 };
    void** gc_raw_roots[3] = { &l0, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l1.tag == 1021u) {
        l3 = l1.payload.obj;
        vader_midir_build_if(l0, l3, vader_box_i32(288u, l2));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 1000u) {
        l3 = l1.payload.obj;
        vader_midir_build_block_into(l0, l3, l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 999u) {
        t0 = l1.payload.obj;
        t1 = vader_midir_is_short_circuit_op(((vader_struct_vader_lower_LoweredBinary_t*) t0)->f_op);
        if (t1) {
            l3 = l1.payload.obj;
            vader_midir_build_short_circuit(l0, l3, vader_box_i32(288u, l2));
            { vader_gc_top = gc_frame.prev; return; }
        }
    }
    l4 = l1;
    l3 = ((vader_struct_vader_midir_FnCtx_t*) l0)->f_locals;
    l5 = ((int64_t) (int32_t) l2);
    vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
    t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
    l6 = ((vader_struct_vader_midir_CFGLocal_t*) t0)->f_type;
    l4 = vader_midir_build_held(l0, l4, l6);
    if (((vader_struct_vader_midir_FnCtx_t*) l0)->f_current.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l4.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l3 = VADER_UNION_FIELD(void*, vader_struct_vader_lower_LoweredArrayLen_t, f_span, l1.payload.obj);
    l7 = ((int32_t) l4.payload.i);
    vader_struct_vader_midir_InstrMove_t* _a1_obj = (vader_struct_vader_midir_InstrMove_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrMove_t));
    vader_obj_header_init(_a1_obj, 1118u);
    _a1_obj->f_span = l3;
    _a1_obj->f_dst = l2;
    _a1_obj->f_src = l7;
    l3 = (void*) _a1_obj;
    vader_midir_emit(l0, vader_ref_box(l3));
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_midir_build_extern_args(void* l0, void* l1, void* l2, void* l3, vader_string_t l4) {
    void* l5 = NULL;
    void* l14 = NULL;
    void* l22 = NULL;
    void* l25 = NULL;
    void* l27 = NULL;
    void* l28 = NULL;
    void* l30 = NULL;
    int64_t l6, l7, l13, l15, l16, l19, l20, l21, l23, l24;
    vader_box_t l8 = vader_box_null(), l10 = vader_box_null(), l11 = vader_box_null(), l29 = vader_box_null();
    int32_t l9, l26;
    vader_string_t l12 = 0;
    vader_string_t l17 = 0;
    vader_string_t l18 = 0;
    bool t0;
    vader_string_t t1 = 0;
    void* t2 = NULL;
    vader_box_t* gc_roots[4] = { &l8, &l10, &l11, &l29 };
    void** gc_raw_roots[12] = { &l0, &l1, &l2, &l3, &l5, &l14, &l22, &l25, &l27, &l28, &l30, &t2 };
    vader_string_t* gc_atom_roots[5] = { &l4, &l12, &l17, &l18, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 12u, gc_roots, gc_raw_roots, 0u, NULL, 5u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(15u, 0u, 7u, 288u);
    l5 = (void*) _a0_arr;
    l6 = INT64_C(0);
    l7 = ((vader_array_t*) l1)->length;
    for (;;) {
        if ((l6 < l7)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l6)
            l8 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l6);
            t0 = std_collections_MutableSet_std_core_Contains_contains__i64(l3, l6);
            if (t0) {
                if (!(l8.tag == 1020u)) {
                    l12 = l4;
                    l13 = vader_host_std_core_byte_len(l12);
                    l14 = (void*) vader_buffer_new((size_t) (INT64_C(130) + l13));
                    l15 = INT64_C(0);
                    l15 = std_core_write_string_at(l14, l15, 2126u);
                    l16 = vader_chk_add(i64, l6, INT64_C(1));
                    l15 = std_core_write_int(l14, l15, l16);
                    l15 = std_core_write_string_at(l14, l15, 134u);
                    l15 = std_core_write_string_at(l14, l15, l12);
                    l15 = std_core_write_string_at(l14, l15, 998u);
                    t1 = std_core_finish_buffer(l14, l15);
                    vader_host_std_abort_panic(t1);
                    vader_unreachable("a no-return call returned");
                }
                t2 = l8.payload.obj;
                if (((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_lower_LoweredIdent_t*) t2)->f_symbol)->f_kind != INT32_C(0)) {
                    l17 = l4;
                    t2 = l8.payload.obj;
                    l18 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_lower_LoweredIdent_t*) t2)->f_symbol)->f_name;
                    l19 = vader_host_std_core_byte_len(l17);
                    l20 = vader_host_std_core_byte_len(l18);
                    l21 = (l19 + l20);
                    l22 = (void*) vader_buffer_new((size_t) (INT64_C(127) + l21));
                    l23 = INT64_C(0);
                    l23 = std_core_write_string_at(l22, l23, 2126u);
                    l24 = vader_chk_add(i64, l6, INT64_C(1));
                    l23 = std_core_write_int(l22, l23, l24);
                    l23 = std_core_write_string_at(l22, l23, 134u);
                    l23 = std_core_write_string_at(l22, l23, l17);
                    l23 = std_core_write_string_at(l22, l23, 1051u);
                    l23 = std_core_write_string_at(l22, l23, l18);
                    l23 = std_core_write_string_at(l22, l23, 1155u);
                    t1 = std_core_finish_buffer(l22, l23);
                    vader_host_std_abort_panic(t1);
                    vader_unreachable("a no-return call returned");
                } else {
                    t2 = (void*) &vader_data_34;
                    vader_array_t* _a2_slotarr = ((vader_array_t*) t2);
                    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                    l25 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) INT64_C(0));
                    l26 = vader_midir_fresh_tmp(l0, 1822u, vader_ref_box(l25));
                    t2 = l8.payload.obj;
                    l27 = ((vader_struct_vader_lower_LoweredIdent_t*) t2)->f_span;
                    t2 = l8.payload.obj;
                    l28 = ((vader_struct_vader_lower_LoweredIdent_t*) t2)->f_symbol;
                    t2 = l8.payload.obj;
                    l29 = ((vader_struct_vader_lower_LoweredIdent_t*) t2)->f_type;
                    vader_struct_vader_midir_InstrFnAddr_t* _a3_obj = (vader_struct_vader_midir_InstrFnAddr_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrFnAddr_t));
                    vader_obj_header_init(_a3_obj, 1112u);
                    _a3_obj->f_span = l27;
                    _a3_obj->f_dst = l26;
                    _a3_obj->f_fn_symbol = l28;
                    _a3_obj->f_type = l29;
                    l30 = (void*) _a3_obj;
                    vader_midir_emit(l0, vader_ref_box(l30));
                    vader_array_push_i32((vader_array_t*) l5, l26);
                    l6 = (l6 + INT64_C(1));
                    continue;
                }
            } else {
                l10 = vader_midir_type_at(l2, l6);
                l11 = vader_midir_build_held(l0, l8, l10);
                if (l11.tag == 0u) {
                    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
                }
                l9 = ((int32_t) l11.payload.i);
                vader_array_push_i32((vader_array_t*) l5, l9);
                l6 = (l6 + INT64_C(1));
                continue;
            }
        }
        break;
    }
    { vader_box_t __vret = vader_ref_box(l5); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir_build_field_access(void* l0, void* l1) {
    int32_t l2;
    vader_box_t l3 = vader_box_null();
    void* l4 = NULL;
    int32_t t0;
    vader_box_t* gc_roots[1] = { &l3 };
    void** gc_raw_roots[3] = { &l0, &l1, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = vader_midir_stored_field(l0, l1);
    if (l3.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l2 = ((int32_t) l3.payload.i);
    l3 = ((vader_struct_vader_lower_LoweredFieldAccess_t*) l1)->f_type;
    l4 = ((vader_struct_vader_lower_LoweredFieldAccess_t*) l1)->f_span;
    t0 = vader_midir_read_as(l0, l2, l3, l4);
    { vader_box_t __vret = vader_box_i32(288u, t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir_build_global_get(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null();
    int32_t l3, l5;
    void* l4 = NULL;
    int64_t t0;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[3] = { &l0, &l1, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_lower_LoweredGlobalGet_t*) l1)->f_type;
    l3 = vader_midir_fresh_tmp(l0, 1868u, l2);
    l4 = ((vader_struct_vader_lower_LoweredGlobalGet_t*) l1)->f_span;
    l2 = ((vader_struct_vader_lower_LoweredGlobalGet_t*) l1)->f_type;
    t0 = ((vader_struct_vader_lower_LoweredGlobalGet_t*) l1)->f_slot;
    l5 = ((int32_t) (int64_t) t0);
    vader_struct_vader_midir_InstrGlobalGet_t* _a0_obj = (vader_struct_vader_midir_InstrGlobalGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrGlobalGet_t));
    vader_obj_header_init(_a0_obj, 1114u);
    _a0_obj->f_span = l4;
    _a0_obj->f_dst = l3;
    _a0_obj->f_type = l2;
    _a0_obj->f_slot = l5;
    l4 = (void*) _a0_obj;
    vader_midir_emit(l0, vader_ref_box(l4));
    { vader_box_t __vret = vader_box_i32(288u, l3); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir_build_held(void* l0, vader_box_t l1, vader_box_t l2) {
    void* l3 = NULL;
    void* l5 = NULL;
    void* l7 = NULL;
    vader_box_t l4 = vader_box_null(), l9 = vader_box_null();
    int64_t l6;
    int32_t l8;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    bool t2;
    int64_t t3;
    int32_t t4;
    vader_box_t* gc_roots[5] = { &l1, &l2, &l4, &l9, &t1 };
    void** gc_raw_roots[5] = { &l0, &l3, &l5, &l7, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 5u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (((vader_struct_vader_midir_FnCtx_t*) l0)->f_current.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    if (l1.tag == 1023u) {
        t0 = l1.payload.obj;
        l4 = vader_midir_stored_conversion(((vader_struct_vader_lower_LoweredIntLit_t*) t0)->f_type, l2);
        if (l4.tag == 0u) {
            l3 = l1.payload.obj;
            t1 = vader_midir_build_expr(l0, vader_ref_box(l3));
            { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l3 = l4.payload.obj;
        l5 = ((vader_struct_vader_integer_MachineInteger_t*) l3)->f_values;
        t0 = l1.payload.obj;
        l6 = ((vader_struct_vader_lower_LoweredIntLit_t*) t0)->f_value;
        t2 = vader_integer_holds_value(l5, l6);
        if (t2) {
            t0 = l1.payload.obj;
            t3 = ((vader_struct_vader_lower_LoweredIntLit_t*) t0)->f_value;
            vader_struct_vader_midir_ConstInt_t* _a0_obj = (vader_struct_vader_midir_ConstInt_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_ConstInt_t));
            vader_obj_header_init(_a0_obj, 1083u);
            _a0_obj->f_value = t3;
            l5 = (void*) _a0_obj;
            l3 = vader_types_machine_integer_type(l3);
            t0 = l1.payload.obj;
            l7 = ((vader_struct_vader_lower_LoweredIntLit_t*) t0)->f_span;
            t4 = vader_midir_emit_const(l0, vader_ref_box(l3), vader_ref_box(l5), l7);
            { vader_box_t __vret = vader_box_i32(288u, t4); vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    t2 = vader_types_is_stored_as_integer(VADER_UNION_FIELD(vader_box_t, vader_struct_vader_lower_LoweredArrayLen_t, f_type, l1.payload.obj));
    if (t2) {
        l9 = vader_midir_build_stored(l0, l1);
        if (l9.tag == 0u) {
            { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
        }
        l8 = ((int32_t) l9.payload.i);
        l9 = VADER_UNION_FIELD(vader_box_t, vader_struct_vader_lower_LoweredArrayLen_t, f_type, l1.payload.obj);
        l5 = VADER_UNION_FIELD(void*, vader_struct_vader_lower_LoweredArrayLen_t, f_span, l1.payload.obj);
        t4 = vader_midir_held_use_in(l0, l8, l9, l2, l5);
        { vader_box_t __vret = vader_box_i32(288u, t4); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = vader_midir_build_expr(l0, l1);
    if (l4.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l8 = ((int32_t) l4.payload.i);
    l3 = VADER_UNION_FIELD(void*, vader_struct_vader_lower_LoweredArrayLen_t, f_span, l1.payload.obj);
    t4 = vader_midir_held_in(l0, l8, l2, l3);
    { vader_box_t __vret = vader_box_i32(288u, t4); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir_build_ident(void* l0, void* l1) {
    void* l2 = NULL;
    void* l5 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    int32_t l3;
    vader_box_t l4 = vader_box_null(), l6 = vader_box_null();
    vader_string_t l9 = 0;
    int32_t t0;
    void* t1 = NULL;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l4, &l6, &t2 };
    void** gc_raw_roots[7] = { &l0, &l1, &l2, &l5, &l7, &l8, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l9 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_midir_FnCtx_t*) l0)->f_local_by_sym_id;
    l3 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_lower_LoweredIdent_t*) l1)->f_symbol)->f_id;
    l4 = std_collections_MutableMap_std_core_Index_at__i32__i32(l2, l3);
    if (!(l4.tag == 0u)) {
        l3 = ((int32_t) l4.payload.i);
        l3 = vader_midir_stored_slot(l0, l3, l1);
        l4 = ((vader_struct_vader_lower_LoweredIdent_t*) l1)->f_type;
        l2 = ((vader_struct_vader_lower_LoweredIdent_t*) l1)->f_span;
        t0 = vader_midir_read_as(l0, l3, l4, l2);
        { vader_box_t __vret = vader_box_i32(288u, t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_lower_LoweredIdent_t*) l1)->f_symbol)->f_kind == INT32_C(0)) {
        l4 = ((vader_struct_vader_lower_LoweredIdent_t*) l1)->f_type;
        l3 = vader_midir_fresh_tmp(l0, 1823u, l4);
        l2 = ((vader_struct_vader_lower_LoweredIdent_t*) l1)->f_span;
        l5 = ((vader_struct_vader_lower_LoweredIdent_t*) l1)->f_symbol;
        l4 = ((vader_struct_vader_lower_LoweredIdent_t*) l1)->f_type;
        vader_struct_vader_midir_InstrFnRef_t* _a0_obj = (vader_struct_vader_midir_InstrFnRef_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrFnRef_t));
        vader_obj_header_init(_a0_obj, 1113u);
        _a0_obj->f_span = l2;
        _a0_obj->f_dst = l3;
        _a0_obj->f_fn_symbol = l5;
        _a0_obj->f_type = l4;
        l2 = (void*) _a0_obj;
        vader_midir_emit(l0, vader_ref_box(l2));
        { vader_box_t __vret = vader_box_i32(288u, l3); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = vader_midir_const_accessor(l0, l1);
    if (l4.tag == 963u) {
        t1 = l4.payload.obj;
        l6 = ((vader_struct_vader_lower_ConstFnWrap_t*) t1)->f_call_type;
        l3 = vader_midir_fresh_tmp(l0, 1611u, l6);
        vader_array_t* _a1_arr = vader_array_new(15u, 0u, 7u, 288u);
        l2 = (void*) _a1_arr;
        l5 = ((vader_struct_vader_lower_LoweredIdent_t*) l1)->f_span;
        vader_array_t* _a2_arr = vader_array_new(15u, 1u, 7u, 288u);
        ((int32_t*) _a2_arr->buf->slots)[_a2_arr->offset + 0u] = (int32_t) l3;
        l7 = (void*) _a2_arr;
        t1 = l4.payload.obj;
        l8 = ((vader_struct_vader_lower_ConstFnWrap_t*) t1)->f_fn_symbol;
        t1 = l4.payload.obj;
        l4 = ((vader_struct_vader_lower_ConstFnWrap_t*) t1)->f_call_type;
        vader_struct_vader_midir_InstrCall_t* _a3_obj = (vader_struct_vader_midir_InstrCall_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrCall_t));
        vader_obj_header_init(_a3_obj, 1100u);
        _a3_obj->f_span = l5;
        _a3_obj->f_dsts = l7;
        _a3_obj->f_callee = l8;
        _a3_obj->f_args = l2;
        _a3_obj->f_type = l4;
        l2 = (void*) _a3_obj;
        vader_midir_emit(l0, vader_ref_box(l2));
        { vader_box_t __vret = vader_box_i32(288u, l3); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = ((vader_struct_vader_midir_ProjectCtx_t*) ((vader_struct_vader_midir_FnCtx_t*) l0)->f_project)->f_const_inline;
    l3 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_lower_LoweredIdent_t*) l1)->f_symbol)->f_id;
    l4 = std_collections_MutableMap_std_core_Index_at__i32__Any(l2, l3);
    if (!(l4.tag == 0u)) {
        t2 = vader_midir_build_expr(l0, l4);
        { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = ((vader_struct_vader_midir_ProjectCtx_t*) ((vader_struct_vader_midir_FnCtx_t*) l0)->f_project)->f_diags;
    l5 = ((vader_struct_vader_lower_LoweredIdent_t*) l1)->f_span;
    l9 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_lower_LoweredIdent_t*) l1)->f_symbol)->f_name;
    l9 = concat_3(910u, l9, 1081u);
    l5 = vader_diagnostics_lower_error((uint8_t) 6, l5, l9);
    vader_array_push((vader_array_t*) l2, vader_ref_box(l5));
    l4 = ((vader_struct_vader_lower_LoweredIdent_t*) l1)->f_type;
    l2 = ((vader_struct_vader_lower_LoweredIdent_t*) l1)->f_span;
    l9 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_lower_LoweredIdent_t*) l1)->f_symbol)->f_name;
    l9 = concat_2(2604u, l9);
    t2 = vader_midir_build_unreachable_type(l0, l4, l2, l9);
    { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir_build_if(void* l0, void* l1, vader_box_t l2) {
    vader_box_t l3 = vader_box_null(), l4 = vader_box_null(), l11 = vader_box_null();
    void* l5 = NULL;
    void* l12 = NULL;
    int32_t l6, l7, l8;
    bool l9, l10;
    bool t0;
    int32_t t1;
    void* t2 = NULL;
    vader_box_t* gc_roots[4] = { &l2, &l3, &l4, &l11 };
    void** gc_raw_roots[5] = { &l0, &l1, &l5, &l12, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l2.tag == 0u) {
        t0 = vader_typecheck_is_void(((vader_struct_vader_lower_LoweredIf_t*) l1)->f_type);
        if (t0) {
            l3 = vader_box_obj(0u, NULL);
        } else {
            l4 = ((vader_struct_vader_lower_LoweredIf_t*) l1)->f_type;
            t1 = vader_midir_declare_local(l0, 1939u, l4, vader_box_obj(0u, NULL));
            l3 = vader_box_i32(288u, t1);
        }
    } else {
        t1 = ((int32_t) l2.payload.i);
        l3 = vader_box_i32(288u, t1);
    }
    l4 = ((vader_struct_vader_lower_LoweredIf_t*) l1)->f_else_block;
    l5 = ((vader_struct_vader_lower_LoweredBlock_t*) ((vader_struct_vader_lower_LoweredIf_t*) l1)->f_then_block)->f_span;
    l6 = vader_midir_new_block(l0, l5);
    l5 = ((vader_struct_vader_lower_LoweredIf_t*) l1)->f_span;
    l7 = vader_midir_new_block(l0, l5);
    if (l4.tag == 0u) {
        l8 = l7;
    } else {
        t2 = l4.payload.obj;
        l5 = ((vader_struct_vader_lower_LoweredBlock_t*) t2)->f_span;
        l8 = vader_midir_new_block(l0, l5);
    }
    l5 = vader_midir_operand_edges(((vader_struct_vader_lower_LoweredIf_t*) l1)->f_cond);
    l9 = vader_midir_only_leaves(((vader_struct_vader_lower_LoweredIf_t*) l1)->f_then_block);
    t1 = ((vader_struct_vader_midir_OperandEdges_t*) l5)->f_on_true;
    if ((t1 < INT32_C(2))) {
        l10 = true;
    } else {
        l10 = l9;
    }
    if (l10) {
        t1 = ((vader_struct_vader_midir_OperandEdges_t*) l5)->f_on_false;
        if ((t1 < INT32_C(2))) {
            l10 = true;
        } else {
            l10 = l4.tag == 0u;
        }
        if (l10) {
            l10 = true;
        } else {
            l10 = l9;
        }
        l9 = l10;
    } else {
        l9 = false;
    }
    l11 = ((vader_struct_vader_lower_LoweredIf_t*) l1)->f_cond;
    l5 = vader_midir_branch_on_cond(l0, l11, l6, l8, l9);
    t0 = ((vader_struct_vader_midir_CondReach_t*) l5)->f_on_true;
    if (!(t0)) {
        t0 = ((vader_struct_vader_midir_CondReach_t*) l5)->f_on_false;
        if (!(t0)) {
            { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
        }
    }
    t0 = ((vader_struct_vader_midir_CondReach_t*) l5)->f_on_true;
    if (t0) {
        ((vader_struct_vader_midir_FnCtx_t*) l0)->f_current = vader_box_i32(288u, l6);
        VADER_WRITE_BARRIER((vader_struct_vader_midir_FnCtx_t*) l0);
        l12 = ((vader_struct_vader_lower_LoweredIf_t*) l1)->f_then_block;
        vader_midir_build_if_arm(l0, l12, l3);
        vader_struct_vader_midir_TermBranch_t* _a0_obj = (vader_struct_vader_midir_TermBranch_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_TermBranch_t));
        vader_obj_header_init(_a0_obj, 1136u);
        _a0_obj->f_span = ((vader_struct_vader_lower_LoweredBlock_t*) ((vader_struct_vader_lower_LoweredIf_t*) l1)->f_then_block)->f_span;
        _a0_obj->f_target = l7;
        l12 = (void*) _a0_obj;
        vader_midir_terminate(l0, vader_ref_box(l12));
    }
    if (l4.tag == 0u) {
        ((vader_struct_vader_midir_FnCtx_t*) l0)->f_current = vader_box_i32(288u, l7);
        VADER_WRITE_BARRIER((vader_struct_vader_midir_FnCtx_t*) l0);
        { vader_box_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_vader_midir_CondReach_t*) l5)->f_on_false;
    if (t0) {
        ((vader_struct_vader_midir_FnCtx_t*) l0)->f_current = vader_box_i32(288u, l8);
        VADER_WRITE_BARRIER((vader_struct_vader_midir_FnCtx_t*) l0);
        l5 = l4.payload.obj;
        vader_midir_build_if_arm(l0, l5, l3);
        t2 = l4.payload.obj;
        vader_struct_vader_midir_TermBranch_t* _a1_obj = (vader_struct_vader_midir_TermBranch_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_TermBranch_t));
        vader_obj_header_init(_a1_obj, 1136u);
        _a1_obj->f_span = ((vader_struct_vader_lower_LoweredBlock_t*) t2)->f_span;
        _a1_obj->f_target = l7;
        l5 = (void*) _a1_obj;
        vader_midir_terminate(l0, vader_ref_box(l5));
        ((vader_struct_vader_midir_FnCtx_t*) l0)->f_current = vader_box_i32(288u, l7);
        VADER_WRITE_BARRIER((vader_struct_vader_midir_FnCtx_t*) l0);
        { vader_box_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    ((vader_struct_vader_midir_FnCtx_t*) l0)->f_current = vader_box_i32(288u, l7);
    VADER_WRITE_BARRIER((vader_struct_vader_midir_FnCtx_t*) l0);
    { vader_box_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_midir_build_if_arm(void* l0, void* l1, vader_box_t l2) {
    int32_t l3;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l2.tag == 0u) {
        vader_midir_build_block_body(l0, l1);
        { vader_gc_top = gc_frame.prev; return; }
    }
    l3 = ((int32_t) l2.payload.i);
    vader_midir_build_block_into(l0, l1, l3);
    { vader_gc_top = gc_frame.prev; return; }
}

static void* vader_midir_build_impl_table_from_vtable(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l18 = NULL;
    void* l22 = NULL;
    int64_t l7, l8, l12, l14, l17, l19, l20;
    vader_string_t l9 = 0;
    vader_string_t l15 = 0;
    vader_string_t l16 = 0;
    vader_string_t l21 = 0;
    vader_box_t l10 = vader_box_null(), l23 = vader_box_null();
    int32_t l11;
    bool l13;
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    vader_box_t* gc_roots[3] = { &l10, &l23, &t0 };
    void** gc_raw_roots[10] = { &l0, &l1, &l2, &l3, &l4, &l5, &l6, &l18, &l22, &t1 };
    vader_string_t* gc_atom_roots[4] = { &l9, &l15, &l16, &l21 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 10u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(56u, 0u, 13u, 749u);
    l3 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(14u, 0u, 0u, 285u);
    l4 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(12u, 0u, 12u, 283u);
    l5 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(15u, 0u, 7u, 288u);
    l6 = (void*) _a3_arr;
    vader_struct_std_collections_MutableMap__string__bool_t* _a4_obj = (vader_struct_std_collections_MutableMap__string__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__bool_t));
    vader_obj_header_init(_a4_obj, 454u);
    _a4_obj->f_ekeys = l4;
    _a4_obj->f_evals = l5;
    _a4_obj->f_index = l6;
    _a4_obj->f_mask = INT64_C(0);
    _a4_obj->f_size = INT64_C(0);
    _a4_obj->f_tombs = INT64_C(0);
    l4 = (void*) _a4_obj;
    l5 = l0;
    l7 = ((vader_array_t*) l5)->length;
    l8 = INT64_C(0);
    while ((l8 < l7)) {
        vader_array_t* _a5_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        l6 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l8);
        l9 = vader_bytecode_type_intern_key(((vader_struct_vader_lower_LoweredVtableEntry_t*) l6)->f_struct_type);
        l10 = std_collections_MutableMap_std_core_Index_at__string__i32(((vader_struct_vader_bytecode_EmitterCtx_t*) l2)->f_type_key, l9);
        if (l10.tag == 288u) {
            l11 = ((int32_t) l10.payload.i);
            l12 = ((int64_t) (int32_t) l11);
            if ((INT64_C(0) <= l12)) {
                l14 = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l2)->f_types)->length;
                l13 = (l12 < l14);
            } else {
                l13 = false;
            }
            if (l13) {
                vader_array_t* _a6_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l2)->f_types);
                VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l11)
                t0 = vader_array_ref_load_box(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l11);
                if (!(t0.tag == 652u)) {
                    l8 = (l8 + INT64_C(1));
                    continue;
                }
            }
            l16 = ((vader_struct_vader_lower_LoweredVtableEntry_t*) l6)->f_trait_name;
            l17 = vader_host_std_core_byte_len(l16);
            l18 = (void*) vader_buffer_new((size_t) (INT64_C(21) + l17));
            l19 = INT64_C(0);
            l20 = ((int64_t) (int32_t) l11);
            l19 = std_core_write_int(l18, l19, l20);
            l19 = std_core_write_string_at(l18, l19, 2823u);
            l19 = std_core_write_string_at(l18, l19, l16);
            l15 = std_core_finish_buffer(l18, l19);
            t0 = std_collections_MutableMap_std_core_Index_at__string__bool(l4, l15);
            if (t0.tag == 283u) {
                l8 = (l8 + INT64_C(1));
                continue;
            }
            std_collections_MutableMap_std_core_IndexSet_set_at__string__bool(l4, l15, true);
            l21 = ((vader_struct_vader_lower_LoweredVtableEntry_t*) l6)->f_trait_name;
            vader_struct_vader_bytecode_ImplEntry_t* _a7_obj = (vader_struct_vader_bytecode_ImplEntry_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_ImplEntry_t));
            vader_obj_header_init(_a7_obj, 749u);
            _a7_obj->f_struct_type_index = l11;
            _a7_obj->f_trait_name = l21;
            l22 = (void*) _a7_obj;
            vader_array_push((vader_array_t*) l3, vader_ref_box(l22));
            l8 = (l8 + INT64_C(1));
            continue;
        }
        l8 = (l8 + INT64_C(1));
    }
    l7 = INT64_C(0);
    l8 = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l2)->f_types)->length;
    while ((l7 < l8)) {
        vader_array_t* _a8_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l2)->f_types);
        VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l7)
        l10 = vader_array_ref_load_box(_a8_slotarr->buf, _a8_slotarr->offset + (size_t) l7);
        if (l10.tag == 652u) {
            t1 = l10.payload.obj;
            l11 = ((vader_struct_vader_bytecode_BcStruct_t*) t1)->f_symbol_id;
            l23 = std_collections_MutableMap_std_core_Index_at__i32__string__(l1, l11);
            if (l23.tag == 0u) {
                l7 = (l7 + INT64_C(1));
                continue;
            }
            l5 = l23.payload.obj;
            l12 = ((vader_array_t*) l5)->length;
            l14 = INT64_C(0);
            while ((l14 < l12)) {
                vader_array_t* _a9_slotarr = ((vader_array_t*) l5);
                VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
                t0 = vader_array_box_slots(_a9_slotarr->buf)[_a9_slotarr->offset + (size_t) l14];
                l9 = t0.payload.s;
                l16 = l9;
                l17 = vader_host_std_core_byte_len(l16);
                l6 = (void*) vader_buffer_new((size_t) (INT64_C(21) + l17));
                l19 = INT64_C(0);
                l19 = std_core_write_int(l6, l19, l7);
                l19 = std_core_write_string_at(l6, l19, 2823u);
                l19 = std_core_write_string_at(l6, l19, l16);
                l15 = std_core_finish_buffer(l6, l19);
                t0 = std_collections_MutableMap_std_core_Index_at__string__bool(l4, l15);
                if (t0.tag == 283u) {
                    l14 = (l14 + INT64_C(1));
                    continue;
                }
                std_collections_MutableMap_std_core_IndexSet_set_at__string__bool(l4, l15, true);
                vader_struct_vader_bytecode_ImplEntry_t* _a10_obj = (vader_struct_vader_bytecode_ImplEntry_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_ImplEntry_t));
                vader_obj_header_init(_a10_obj, 749u);
                _a10_obj->f_struct_type_index = ((int32_t) (int64_t) l7);
                _a10_obj->f_trait_name = l9;
                l18 = (void*) _a10_obj;
                vader_array_push((vader_array_t*) l3, vader_ref_box(l18));
                l14 = (l14 + INT64_C(1));
            }
        }
        l7 = (l7 + INT64_C(1));
    }
    { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir_build_index(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l3 = vader_box_null(), l4 = vader_box_null();
    int32_t l5, l7, l8;
    void* l6 = NULL;
    bool l9;
    vader_box_t* gc_roots[3] = { &l2, &l3, &l4 };
    void** gc_raw_roots[3] = { &l0, &l1, &l6 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_lower_LoweredIndex_t*) l1)->f_target;
    l2 = vader_midir_build_expr(l0, l2);
    l3 = ((vader_struct_vader_lower_LoweredIndex_t*) l1)->f_index;
    l3 = vader_midir_build_expr(l0, l3);
    if (l2.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    if (!(l3.tag == 0u)) {
        l4 = ((vader_struct_vader_lower_LoweredIndex_t*) l1)->f_type;
        l5 = vader_midir_fresh_tmp(l0, 1934u, l4);
        l6 = ((vader_struct_vader_lower_LoweredIndex_t*) l1)->f_span;
        l7 = ((int32_t) l2.payload.i);
        l2 = ((vader_struct_vader_lower_LoweredIndex_t*) l1)->f_type;
        l8 = ((int32_t) l3.payload.i);
        l9 = ((vader_struct_vader_lower_LoweredIndex_t*) l1)->f_bounds_safe;
        vader_struct_vader_midir_InstrArrayGet_t* _a0_obj = (vader_struct_vader_midir_InstrArrayGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrArrayGet_t));
        vader_obj_header_init(_a0_obj, 1093u);
        _a0_obj->f_span = l6;
        _a0_obj->f_dst = l5;
        _a0_obj->f_target = l7;
        _a0_obj->f_type = l2;
        _a0_obj->f_index = l8;
        _a0_obj->f_bounds_safe = l9;
        l6 = (void*) _a0_obj;
        vader_midir_emit(l0, vader_ref_box(l6));
        { vader_box_t __vret = vader_box_i32(288u, l5); vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static vader_box_t vader_midir_build_intrinsic_call(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l7 = NULL;
    vader_box_t l4 = vader_box_null(), l5 = vader_box_null();
    vader_string_t l6 = 0;
    bool t0;
    int32_t t1;
    vader_box_t* gc_roots[2] = { &l4, &l5 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &l7 };
    vader_string_t* gc_atom_roots[1] = { &l6 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_lower_LoweredIntrinsicCall_t*) l1)->f_args;
    l3 = ((vader_struct_vader_lower_LoweredIntrinsicCall_t*) l1)->f_param_types;
    l4 = vader_midir_build_args(l0, l2, l3);
    if (l4.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l2 = l4.payload.obj;
    t0 = vader_typecheck_is_void(((vader_struct_vader_lower_LoweredIntrinsicCall_t*) l1)->f_type);
    if (t0) {
        l4 = vader_box_obj(0u, NULL);
    } else {
        l5 = ((vader_struct_vader_lower_LoweredIntrinsicCall_t*) l1)->f_type;
        t1 = vader_midir_fresh_tmp(l0, 1997u, l5);
        l4 = vader_box_i32(288u, t1);
    }
    l3 = ((vader_struct_vader_lower_LoweredIntrinsicCall_t*) l1)->f_span;
    l6 = ((vader_struct_vader_lower_LoweredIntrinsicCall_t*) l1)->f_name;
    l7 = ((vader_struct_vader_lower_LoweredIntrinsicCall_t*) l1)->f_param_types;
    vader_struct_vader_midir_InstrIntrinsic_t* _a0_obj = (vader_struct_vader_midir_InstrIntrinsic_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrIntrinsic_t));
    vader_obj_header_init(_a0_obj, 1116u);
    _a0_obj->f_span = l3;
    _a0_obj->f_dst = l4;
    _a0_obj->f_name = l6;
    _a0_obj->f_args = l2;
    _a0_obj->f_param_types = l7;
    l2 = (void*) _a0_obj;
    vader_midir_emit(l0, vader_ref_box(l2));
    { vader_box_t __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_midir_build_labelled_block(void* l0, void* l1) {
    void* l2 = NULL;
    void* l6 = NULL;
    int32_t l3, l4;
    vader_string_t l5 = 0;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &l6 };
    vader_string_t* gc_atom_roots[1] = { &l5 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_lower_LoweredLabelledBlock_t*) l1)->f_span;
    l3 = vader_midir_new_block(l0, l2);
    l2 = ((vader_struct_vader_lower_LoweredLabelledBlock_t*) l1)->f_span;
    l4 = vader_midir_new_block(l0, l2);
    if (!(((vader_struct_vader_midir_FnCtx_t*) l0)->f_current.tag == 0u)) {
        vader_struct_vader_midir_TermBranch_t* _a0_obj = (vader_struct_vader_midir_TermBranch_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_TermBranch_t));
        vader_obj_header_init(_a0_obj, 1136u);
        _a0_obj->f_span = ((vader_struct_vader_lower_LoweredLabelledBlock_t*) l1)->f_span;
        _a0_obj->f_target = l3;
        l2 = (void*) _a0_obj;
        vader_midir_terminate(l0, vader_ref_box(l2));
    }
    l2 = ((vader_struct_vader_midir_FnCtx_t*) l0)->f_loop_stack;
    l5 = ((vader_struct_vader_lower_LoweredLabelledBlock_t*) l1)->f_label;
    vader_array_t* _a1_arr = vader_array_new(239u, 0u, 13u, 1700u);
    l6 = (void*) _a1_arr;
    vader_struct_vader_midir_LoopFrame_t* _a2_obj = (vader_struct_vader_midir_LoopFrame_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_LoopFrame_t));
    vader_obj_header_init(_a2_obj, 1127u);
    _a2_obj->f_label = vader_box_string(285u, l5);
    _a2_obj->f_header_id = l4;
    _a2_obj->f_exit_id = l4;
    _a2_obj->f_step = l6;
    _a2_obj->f_block = true;
    l6 = (void*) _a2_obj;
    vader_array_push((vader_array_t*) l2, vader_ref_box(l6));
    ((vader_struct_vader_midir_FnCtx_t*) l0)->f_current = vader_box_i32(288u, l3);
    VADER_WRITE_BARRIER((vader_struct_vader_midir_FnCtx_t*) l0);
    l2 = ((vader_struct_vader_lower_LoweredLabelledBlock_t*) l1)->f_body;
    vader_midir_build_block_body(l0, l2);
    if (!(((vader_struct_vader_midir_FnCtx_t*) l0)->f_current.tag == 0u)) {
        vader_struct_vader_midir_TermBranch_t* _a3_obj = (vader_struct_vader_midir_TermBranch_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_TermBranch_t));
        vader_obj_header_init(_a3_obj, 1136u);
        _a3_obj->f_span = ((vader_struct_vader_lower_LoweredLabelledBlock_t*) l1)->f_span;
        _a3_obj->f_target = l4;
        l2 = (void*) _a3_obj;
        vader_midir_terminate(l0, vader_ref_box(l2));
    }
    t0 = vader_array_remove_last((vader_array_t*) ((vader_struct_vader_midir_FnCtx_t*) l0)->f_loop_stack);
    ((vader_struct_vader_midir_FnCtx_t*) l0)->f_current = vader_box_i32(288u, l4);
    VADER_WRITE_BARRIER((vader_struct_vader_midir_FnCtx_t*) l0);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_midir_build_loop(void* l0, void* l1) {
    void* l2 = NULL;
    void* l8 = NULL;
    int32_t l3, l4, l6;
    vader_box_t l5 = vader_box_null();
    bool l7;
    int64_t l9, l10;
    void* t0 = NULL;
    int32_t t1;
    bool t2;
    int64_t t3;
    vader_box_t* gc_roots[1] = { &l5 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l8, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_lower_LoweredLoop_t*) l1)->f_span;
    l3 = vader_midir_new_block(l0, l2);
    l2 = ((vader_struct_vader_lower_LoweredLoop_t*) l1)->f_span;
    l4 = vader_midir_new_block(l0, l2);
    if (!(((vader_struct_vader_midir_FnCtx_t*) l0)->f_current.tag == 0u)) {
        vader_struct_vader_midir_TermBranch_t* _a0_obj = (vader_struct_vader_midir_TermBranch_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_TermBranch_t));
        vader_obj_header_init(_a0_obj, 1136u);
        _a0_obj->f_span = ((vader_struct_vader_lower_LoweredLoop_t*) l1)->f_span;
        _a0_obj->f_target = l3;
        l2 = (void*) _a0_obj;
        vader_midir_terminate(l0, vader_ref_box(l2));
    }
    ((vader_struct_vader_midir_FnCtx_t*) l0)->f_current = vader_box_i32(288u, l3);
    VADER_WRITE_BARRIER((vader_struct_vader_midir_FnCtx_t*) l0);
    l5 = ((vader_struct_vader_lower_LoweredLoop_t*) l1)->f_cond;
    if (!(l5.tag == 0u)) {
        l2 = ((vader_struct_vader_lower_LoweredBlock_t*) ((vader_struct_vader_lower_LoweredLoop_t*) l1)->f_body)->f_span;
        l6 = vader_midir_new_block(l0, l2);
        t0 = vader_midir_operand_edges(l5);
        t1 = ((vader_struct_vader_midir_OperandEdges_t*) t0)->f_on_true;
        l7 = (t1 < INT32_C(2));
        t0 = vader_midir_branch_on_cond(l0, l5, l6, l4, l7);
        t2 = ((vader_struct_vader_midir_CondReach_t*) t0)->f_on_true;
        if (!(t2)) {
            vader_struct_vader_midir_TermBranch_t* _a1_obj = (vader_struct_vader_midir_TermBranch_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_TermBranch_t));
            vader_obj_header_init(_a1_obj, 1136u);
            _a1_obj->f_span = ((vader_struct_vader_lower_LoweredLoop_t*) l1)->f_span;
            _a1_obj->f_target = l4;
            l2 = (void*) _a1_obj;
            vader_midir_terminate(l0, vader_ref_box(l2));
        }
        ((vader_struct_vader_midir_FnCtx_t*) l0)->f_current = vader_box_i32(288u, l6);
        VADER_WRITE_BARRIER((vader_struct_vader_midir_FnCtx_t*) l0);
    }
    l5 = ((vader_struct_vader_lower_LoweredLoop_t*) l1)->f_label;
    l2 = ((vader_struct_vader_lower_LoweredLoop_t*) l1)->f_step;
    vader_struct_vader_midir_LoopFrame_t* _a2_obj = (vader_struct_vader_midir_LoopFrame_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_LoopFrame_t));
    vader_obj_header_init(_a2_obj, 1127u);
    _a2_obj->f_label = l5;
    _a2_obj->f_header_id = l3;
    _a2_obj->f_exit_id = l4;
    _a2_obj->f_step = l2;
    _a2_obj->f_block = false;
    l2 = (void*) _a2_obj;
    vader_array_push((vader_array_t*) ((vader_struct_vader_midir_FnCtx_t*) l0)->f_loop_stack, vader_ref_box(l2));
    l8 = ((vader_struct_vader_lower_LoweredLoop_t*) l1)->f_body;
    vader_midir_build_block_body(l0, l8);
    if (!(((vader_struct_vader_midir_FnCtx_t*) l0)->f_current.tag == 0u)) {
        l8 = ((vader_struct_vader_lower_LoweredLoop_t*) l1)->f_span;
        vader_midir_build_back_edge(l0, l2, l8);
    }
    vader_array_t* _a3_arr = vader_array_new(144u, 0u, 13u, 1127u);
    l2 = (void*) _a3_arr;
    l9 = INT64_C(0);
    t3 = ((vader_array_t*) ((vader_struct_vader_midir_FnCtx_t*) l0)->f_loop_stack)->length;
    l10 = vader_chk_sub(i64, t3, INT64_C(1));
    while ((l9 < l10)) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_vader_midir_FnCtx_t*) l0)->f_loop_stack);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l9)
        l8 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l9);
        vader_array_push((vader_array_t*) l2, vader_ref_box(l8));
        l9 = (l9 + INT64_C(1));
    }
    ((vader_struct_vader_midir_FnCtx_t*) l0)->f_loop_stack = l2;
    VADER_WRITE_BARRIER((vader_struct_vader_midir_FnCtx_t*) l0);
    ((vader_struct_vader_midir_FnCtx_t*) l0)->f_current = vader_box_i32(288u, l4);
    VADER_WRITE_BARRIER((vader_struct_vader_midir_FnCtx_t*) l0);
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_midir_build_make_closure(void* l0, void* l1) {
    int32_t l2, l4;
    vader_box_t l3 = vader_box_null(), l7 = vader_box_null();
    void* l5 = NULL;
    void* l6 = NULL;
    vader_box_t* gc_roots[2] = { &l3, &l7 };
    void** gc_raw_roots[4] = { &l0, &l1, &l5, &l6 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_lower_LoweredMakeClosure_t*) l1)->f_env;
    l3 = vader_midir_build_expr(l0, l3);
    if (l3.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l2 = ((int32_t) l3.payload.i);
    l3 = ((vader_struct_vader_lower_LoweredMakeClosure_t*) l1)->f_type;
    l4 = vader_midir_fresh_tmp(l0, 1575u, l3);
    l5 = ((vader_struct_vader_lower_LoweredMakeClosure_t*) l1)->f_span;
    l6 = ((vader_struct_vader_lower_LoweredMakeClosure_t*) l1)->f_fn_symbol;
    l3 = VADER_UNION_FIELD(vader_box_t, vader_struct_vader_lower_LoweredArrayLen_t, f_type, ((vader_struct_vader_lower_LoweredMakeClosure_t*) l1)->f_env.payload.obj);
    l7 = ((vader_struct_vader_lower_LoweredMakeClosure_t*) l1)->f_type;
    vader_struct_vader_midir_InstrMakeClosure_t* _a0_obj = (vader_struct_vader_midir_InstrMakeClosure_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrMakeClosure_t));
    vader_obj_header_init(_a0_obj, 1117u);
    _a0_obj->f_span = l5;
    _a0_obj->f_dst = l4;
    _a0_obj->f_fn_symbol = l6;
    _a0_obj->f_env = l2;
    _a0_obj->f_env_type = l3;
    _a0_obj->f_type = l7;
    l5 = (void*) _a0_obj;
    vader_midir_emit(l0, vader_ref_box(l5));
    { vader_box_t __vret = vader_box_i32(288u, l4); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir_build_short_circuit(void* l0, void* l1, vader_box_t l2) {
    int32_t l3, l6, l9, l10, l11;
    vader_box_t l4 = vader_box_null();
    bool l5;
    vader_string_t l7 = 0;
    void* l8 = NULL;
    void* l12 = NULL;
    vader_box_t* gc_roots[2] = { &l2, &l4 };
    void** gc_raw_roots[4] = { &l0, &l1, &l8, &l12 };
    vader_string_t* gc_atom_roots[1] = { &l7 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = ((vader_struct_vader_lower_LoweredBinary_t*) l1)->f_left;
    l4 = vader_midir_build_expr(l0, l4);
    if (l4.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l3 = ((int32_t) l4.payload.i);
    l5 = ((vader_struct_vader_lower_LoweredBinary_t*) l1)->f_op == INT32_C(10);
    if (l2.tag == 0u) {
        if (l5) {
            l7 = 1381u;
        } else {
            l7 = 2235u;
        }
        l4 = ((vader_struct_vader_lower_LoweredBinary_t*) l1)->f_type;
        l6 = vader_midir_declare_local(l0, l7, l4, vader_box_obj(0u, NULL));
    } else {
        l6 = ((int32_t) l2.payload.i);
    }
    l8 = VADER_UNION_FIELD(void*, vader_struct_vader_lower_LoweredArrayLen_t, f_span, ((vader_struct_vader_lower_LoweredBinary_t*) l1)->f_right.payload.obj);
    l9 = vader_midir_new_block(l0, l8);
    l8 = VADER_UNION_FIELD(void*, vader_struct_vader_lower_LoweredArrayLen_t, f_span, ((vader_struct_vader_lower_LoweredBinary_t*) l1)->f_right.payload.obj);
    l10 = vader_midir_new_block(l0, l8);
    l8 = ((vader_struct_vader_lower_LoweredBinary_t*) l1)->f_span;
    l11 = vader_midir_new_block(l0, l8);
    vader_struct_vader_midir_TermCondBranch_t* _a0_obj = (vader_struct_vader_midir_TermCondBranch_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_TermCondBranch_t));
    vader_obj_header_init(_a0_obj, 1137u);
    _a0_obj->f_span = ((vader_struct_vader_lower_LoweredBinary_t*) l1)->f_span;
    _a0_obj->f_cond = l3;
    _a0_obj->f_then_block = l9;
    _a0_obj->f_else_block = l10;
    l8 = (void*) _a0_obj;
    vader_midir_terminate(l0, vader_ref_box(l8));
    ((vader_struct_vader_midir_FnCtx_t*) l0)->f_current = vader_box_i32(288u, l9);
    VADER_WRITE_BARRIER((vader_struct_vader_midir_FnCtx_t*) l0);
    if (l5) {
        l4 = ((vader_struct_vader_lower_LoweredBinary_t*) l1)->f_right;
        l4 = vader_midir_build_expr(l0, l4);
        if (!(l4.tag == 0u)) {
            if (!(((vader_struct_vader_midir_FnCtx_t*) l0)->f_current.tag == 0u)) {
                l8 = VADER_UNION_FIELD(void*, vader_struct_vader_lower_LoweredArrayLen_t, f_span, ((vader_struct_vader_lower_LoweredBinary_t*) l1)->f_right.payload.obj);
                l3 = ((int32_t) l4.payload.i);
                vader_struct_vader_midir_InstrMove_t* _a1_obj = (vader_struct_vader_midir_InstrMove_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrMove_t));
                vader_obj_header_init(_a1_obj, 1118u);
                _a1_obj->f_span = l8;
                _a1_obj->f_dst = l6;
                _a1_obj->f_src = l3;
                l8 = (void*) _a1_obj;
                vader_midir_emit(l0, vader_ref_box(l8));
            }
        }
    } else {
        l4 = ((vader_struct_vader_lower_LoweredBinary_t*) l1)->f_type;
        l3 = vader_midir_fresh_tmp(l0, 2029u, l4);
        l8 = ((vader_struct_vader_lower_LoweredBinary_t*) l1)->f_span;
        vader_struct_vader_midir_ConstBool_t* _a2_obj = (vader_struct_vader_midir_ConstBool_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_ConstBool_t));
        vader_obj_header_init(_a2_obj, 1080u);
        _a2_obj->f_value = true;
        l12 = (void*) _a2_obj;
        l4 = ((vader_struct_vader_lower_LoweredBinary_t*) l1)->f_type;
        vader_struct_vader_midir_InstrConst_t* _a3_obj = (vader_struct_vader_midir_InstrConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrConst_t));
        vader_obj_header_init(_a3_obj, 1106u);
        _a3_obj->f_span = l8;
        _a3_obj->f_dst = l3;
        _a3_obj->f_value = vader_ref_box(l12);
        _a3_obj->f_type = l4;
        l8 = (void*) _a3_obj;
        vader_midir_emit(l0, vader_ref_box(l8));
        vader_struct_vader_midir_InstrMove_t* _a4_obj = (vader_struct_vader_midir_InstrMove_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrMove_t));
        vader_obj_header_init(_a4_obj, 1118u);
        _a4_obj->f_span = ((vader_struct_vader_lower_LoweredBinary_t*) l1)->f_span;
        _a4_obj->f_dst = l6;
        _a4_obj->f_src = l3;
        l8 = (void*) _a4_obj;
        vader_midir_emit(l0, vader_ref_box(l8));
    }
    if (!(((vader_struct_vader_midir_FnCtx_t*) l0)->f_current.tag == 0u)) {
        vader_struct_vader_midir_TermBranch_t* _a5_obj = (vader_struct_vader_midir_TermBranch_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_TermBranch_t));
        vader_obj_header_init(_a5_obj, 1136u);
        _a5_obj->f_span = ((vader_struct_vader_lower_LoweredBinary_t*) l1)->f_span;
        _a5_obj->f_target = l11;
        l8 = (void*) _a5_obj;
        vader_midir_terminate(l0, vader_ref_box(l8));
    }
    ((vader_struct_vader_midir_FnCtx_t*) l0)->f_current = vader_box_i32(288u, l10);
    VADER_WRITE_BARRIER((vader_struct_vader_midir_FnCtx_t*) l0);
    if (l5) {
        l4 = ((vader_struct_vader_lower_LoweredBinary_t*) l1)->f_type;
        l3 = vader_midir_fresh_tmp(l0, 2029u, l4);
        l8 = ((vader_struct_vader_lower_LoweredBinary_t*) l1)->f_span;
        vader_struct_vader_midir_ConstBool_t* _a6_obj = (vader_struct_vader_midir_ConstBool_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_ConstBool_t));
        vader_obj_header_init(_a6_obj, 1080u);
        _a6_obj->f_value = false;
        l12 = (void*) _a6_obj;
        l4 = ((vader_struct_vader_lower_LoweredBinary_t*) l1)->f_type;
        vader_struct_vader_midir_InstrConst_t* _a7_obj = (vader_struct_vader_midir_InstrConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrConst_t));
        vader_obj_header_init(_a7_obj, 1106u);
        _a7_obj->f_span = l8;
        _a7_obj->f_dst = l3;
        _a7_obj->f_value = vader_ref_box(l12);
        _a7_obj->f_type = l4;
        l8 = (void*) _a7_obj;
        vader_midir_emit(l0, vader_ref_box(l8));
        vader_struct_vader_midir_InstrMove_t* _a8_obj = (vader_struct_vader_midir_InstrMove_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrMove_t));
        vader_obj_header_init(_a8_obj, 1118u);
        _a8_obj->f_span = ((vader_struct_vader_lower_LoweredBinary_t*) l1)->f_span;
        _a8_obj->f_dst = l6;
        _a8_obj->f_src = l3;
        l8 = (void*) _a8_obj;
        vader_midir_emit(l0, vader_ref_box(l8));
    } else {
        l4 = ((vader_struct_vader_lower_LoweredBinary_t*) l1)->f_right;
        l4 = vader_midir_build_expr(l0, l4);
        if (!(l4.tag == 0u)) {
            if (!(((vader_struct_vader_midir_FnCtx_t*) l0)->f_current.tag == 0u)) {
                l8 = VADER_UNION_FIELD(void*, vader_struct_vader_lower_LoweredArrayLen_t, f_span, ((vader_struct_vader_lower_LoweredBinary_t*) l1)->f_right.payload.obj);
                l3 = ((int32_t) l4.payload.i);
                vader_struct_vader_midir_InstrMove_t* _a9_obj = (vader_struct_vader_midir_InstrMove_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrMove_t));
                vader_obj_header_init(_a9_obj, 1118u);
                _a9_obj->f_span = l8;
                _a9_obj->f_dst = l6;
                _a9_obj->f_src = l3;
                l8 = (void*) _a9_obj;
                vader_midir_emit(l0, vader_ref_box(l8));
            }
        }
    }
    if (((vader_struct_vader_midir_FnCtx_t*) l0)->f_current.tag == 0u) {
        ((vader_struct_vader_midir_FnCtx_t*) l0)->f_current = vader_box_i32(288u, l11);
        VADER_WRITE_BARRIER((vader_struct_vader_midir_FnCtx_t*) l0);
        { vader_box_t __vret = vader_box_i32(288u, l6); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_midir_TermBranch_t* _a10_obj = (vader_struct_vader_midir_TermBranch_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_TermBranch_t));
    vader_obj_header_init(_a10_obj, 1136u);
    _a10_obj->f_span = ((vader_struct_vader_lower_LoweredBinary_t*) l1)->f_span;
    _a10_obj->f_target = l11;
    l8 = (void*) _a10_obj;
    vader_midir_terminate(l0, vader_ref_box(l8));
    ((vader_struct_vader_midir_FnCtx_t*) l0)->f_current = vader_box_i32(288u, l11);
    VADER_WRITE_BARRIER((vader_struct_vader_midir_FnCtx_t*) l0);
    { vader_box_t __vret = vader_box_i32(288u, l6); vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_midir_build_stmt(void* l0, vader_box_t l1) {
    vader_box_t l2 = vader_box_null(), l4 = vader_box_null(), l10 = vader_box_null();
    vader_string_t l3 = 0;
    void* l5 = NULL;
    void* l9 = NULL;
    int32_t l6, l7;
    int64_t l8;
    void* t0 = NULL;
    bool t1;
    int64_t t2;
    vader_box_t* gc_roots[4] = { &l1, &l2, &l4, &l10 };
    void** gc_raw_roots[4] = { &l0, &l5, &l9, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l1.tag == 1026u) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_vader_lower_LoweredLet_t*) t0)->f_value;
        t1 = vader_midir_is_dest_passing_shape(l2);
        if (t1) {
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_lower_LoweredLet_t*) t0)->f_name;
            t0 = l1.payload.obj;
            l4 = ((vader_struct_vader_lower_LoweredLet_t*) t0)->f_type;
            t0 = l1.payload.obj;
            l5 = ((vader_struct_vader_lower_LoweredLet_t*) t0)->f_symbol;
            l6 = vader_midir_declare_local(l0, l3, l4, vader_ref_box(l5));
            l5 = ((vader_struct_vader_midir_FnCtx_t*) l0)->f_local_by_sym_id;
            t0 = l1.payload.obj;
            l7 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_lower_LoweredLet_t*) t0)->f_symbol)->f_id;
            std_collections_MutableMap_std_core_IndexSet_set_at__i32__i32(l5, l7, l6);
            if (!(((vader_struct_vader_midir_FnCtx_t*) l0)->f_current.tag == 0u)) {
                vader_midir_build_expr_into(l0, l2, l6);
            }
        } else {
            t0 = l1.payload.obj;
            l4 = ((vader_struct_vader_lower_LoweredLet_t*) t0)->f_type;
            l2 = vader_midir_build_held(l0, l2, l4);
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_lower_LoweredLet_t*) t0)->f_name;
            t0 = l1.payload.obj;
            l4 = ((vader_struct_vader_lower_LoweredLet_t*) t0)->f_type;
            t0 = l1.payload.obj;
            l5 = ((vader_struct_vader_lower_LoweredLet_t*) t0)->f_symbol;
            l6 = vader_midir_declare_local(l0, l3, l4, vader_ref_box(l5));
            l5 = ((vader_struct_vader_midir_FnCtx_t*) l0)->f_local_by_sym_id;
            t0 = l1.payload.obj;
            l7 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_lower_LoweredLet_t*) t0)->f_symbol)->f_id;
            std_collections_MutableMap_std_core_IndexSet_set_at__i32__i32(l5, l7, l6);
            if (!(l2.tag == 0u)) {
                if (!(((vader_struct_vader_midir_FnCtx_t*) l0)->f_current.tag == 0u)) {
                    t0 = l1.payload.obj;
                    l5 = ((vader_struct_vader_lower_LoweredLet_t*) t0)->f_span;
                    l7 = ((int32_t) l2.payload.i);
                    vader_struct_vader_midir_InstrMove_t* _a0_obj = (vader_struct_vader_midir_InstrMove_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrMove_t));
                    vader_obj_header_init(_a0_obj, 1118u);
                    _a0_obj->f_span = l5;
                    _a0_obj->f_dst = l6;
                    _a0_obj->f_src = l7;
                    l5 = (void*) _a0_obj;
                    vader_midir_emit(l0, vader_ref_box(l5));
                }
            }
        }
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 997u) {
        l5 = l1.payload.obj;
        vader_midir_build_assign(l0, l5);
    } else if (l1.tag == 1019u) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_vader_lower_LoweredGlobalSet_t*) t0)->f_value;
        l5 = ((vader_struct_vader_midir_ProjectCtx_t*) ((vader_struct_vader_midir_FnCtx_t*) l0)->f_project)->f_globals;
        t0 = l1.payload.obj;
        l8 = ((vader_struct_vader_lower_LoweredGlobalSet_t*) t0)->f_slot;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l8)
        t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l8);
        l4 = ((vader_struct_vader_lower_GlobalSlot_t*) t0)->f_type;
        l2 = vader_midir_build_held(l0, l2, l4);
        if (!(l2.tag == 0u)) {
            t0 = l1.payload.obj;
            l5 = ((vader_struct_vader_lower_LoweredGlobalSet_t*) t0)->f_span;
            t0 = l1.payload.obj;
            t2 = ((vader_struct_vader_lower_LoweredGlobalSet_t*) t0)->f_slot;
            l6 = ((int32_t) (int64_t) t2);
            l7 = ((int32_t) l2.payload.i);
            l9 = ((vader_struct_vader_midir_ProjectCtx_t*) ((vader_struct_vader_midir_FnCtx_t*) l0)->f_project)->f_globals;
            t0 = l1.payload.obj;
            l8 = ((vader_struct_vader_lower_LoweredGlobalSet_t*) t0)->f_slot;
            vader_array_t* _a2_slotarr = ((vader_array_t*) l9);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l8)
            t0 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l8);
            l2 = ((vader_struct_vader_lower_GlobalSlot_t*) t0)->f_type;
            vader_struct_vader_midir_InstrGlobalSet_t* _a3_obj = (vader_struct_vader_midir_InstrGlobalSet_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrGlobalSet_t));
            vader_obj_header_init(_a3_obj, 1115u);
            _a3_obj->f_span = l5;
            _a3_obj->f_slot = l6;
            _a3_obj->f_value = l7;
            _a3_obj->f_type = l2;
            l5 = (void*) _a3_obj;
            vader_midir_emit(l0, vader_ref_box(l5));
        }
    } else if (l1.tag == 1007u) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_vader_lower_LoweredCellSet_t*) t0)->f_target;
        l2 = vader_midir_build_expr(l0, l2);
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_lower_LoweredCellSet_t*) t0)->f_value;
        t0 = l1.payload.obj;
        l10 = ((vader_struct_vader_lower_LoweredCellSet_t*) t0)->f_value_type;
        l4 = vader_midir_build_held(l0, l4, l10);
        if (!(l2.tag == 0u)) {
            if (!(l4.tag == 0u)) {
                t0 = l1.payload.obj;
                l5 = ((vader_struct_vader_lower_LoweredCellSet_t*) t0)->f_span;
                l6 = ((int32_t) l2.payload.i);
                l7 = ((int32_t) l4.payload.i);
                t0 = l1.payload.obj;
                l2 = ((vader_struct_vader_lower_LoweredCellSet_t*) t0)->f_value_type;
                vader_struct_vader_midir_InstrCellSet_t* _a4_obj = (vader_struct_vader_midir_InstrCellSet_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrCellSet_t));
                vader_obj_header_init(_a4_obj, 1105u);
                _a4_obj->f_span = l5;
                _a4_obj->f_cell = l6;
                _a4_obj->f_value = l7;
                _a4_obj->f_value_type = l2;
                l5 = (void*) _a4_obj;
                vader_midir_emit(l0, vader_ref_box(l5));
            }
        }
    } else if (l1.tag == 1013u) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_vader_lower_LoweredDeferPush_t*) t0)->f_thunk;
        l2 = vader_midir_build_expr(l0, l2);
        if (!(l2.tag == 0u)) {
            t0 = l1.payload.obj;
            l5 = ((vader_struct_vader_lower_LoweredDeferPush_t*) t0)->f_span;
            l6 = ((int32_t) l2.payload.i);
            vader_struct_vader_midir_InstrDeferPush_t* _a5_obj = (vader_struct_vader_midir_InstrDeferPush_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrDeferPush_t));
            vader_obj_header_init(_a5_obj, 1109u);
            _a5_obj->f_span = l5;
            _a5_obj->f_value = l6;
            l5 = (void*) _a5_obj;
            vader_midir_emit(l0, vader_ref_box(l5));
        }
    } else if (l1.tag == 1012u) {
        t0 = l1.payload.obj;
        l5 = ((vader_struct_vader_lower_LoweredDeferPopExec_t*) t0)->f_span;
        t0 = l1.payload.obj;
        l6 = ((vader_struct_vader_lower_LoweredDeferPopExec_t*) t0)->f_count;
        vader_struct_vader_midir_InstrDeferPopExec_t* _a6_obj = (vader_struct_vader_midir_InstrDeferPopExec_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrDeferPopExec_t));
        vader_obj_header_init(_a6_obj, 1108u);
        _a6_obj->f_span = l5;
        _a6_obj->f_count = l6;
        l5 = (void*) _a6_obj;
        vader_midir_emit(l0, vader_ref_box(l5));
    } else if (l1.tag == 1014u) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_vader_lower_LoweredExprStmt_t*) t0)->f_expr;
        vader_midir_build_expr(l0, l2);
    } else if (l1.tag == 1033u) {
        vader_array_t* _a7_arr = vader_array_new(15u, 0u, 7u, 288u);
        l5 = (void*) _a7_arr;
        t0 = l1.payload.obj;
        if (!(((vader_struct_vader_lower_LoweredReturn_t*) t0)->f_value.tag == 0u)) {
            t0 = l1.payload.obj;
            l2 = ((vader_struct_vader_lower_LoweredReturn_t*) t0)->f_value;
            l4 = ((vader_struct_vader_midir_FnCtx_t*) l0)->f_return_type;
            l2 = vader_midir_build_held(l0, l2, l4);
            if (!(l2.tag == 0u)) {
                l6 = ((int32_t) l2.payload.i);
                vader_array_push_i32((vader_array_t*) l5, l6);
            }
        }
        t0 = l1.payload.obj;
        vader_struct_vader_midir_TermReturn_t* _a8_obj = (vader_struct_vader_midir_TermReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_TermReturn_t));
        vader_obj_header_init(_a8_obj, 1138u);
        _a8_obj->f_span = ((vader_struct_vader_lower_LoweredReturn_t*) t0)->f_span;
        _a8_obj->f_values = l5;
        l5 = (void*) _a8_obj;
        vader_midir_terminate(l0, vader_ref_box(l5));
    } else if (l1.tag == 1027u) {
        l5 = l1.payload.obj;
        vader_midir_build_loop(l0, l5);
    } else if (l1.tag == 1025u) {
        l5 = l1.payload.obj;
        vader_midir_build_labelled_block(l0, l5);
    } else if (l1.tag == 1002u) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_vader_lower_LoweredBreak_t*) t0)->f_label;
        l5 = vader_midir_resolve_loop_frame(l0, l2);
        t0 = l1.payload.obj;
        l9 = ((vader_struct_vader_lower_LoweredBreak_t*) t0)->f_span;
        l6 = ((vader_struct_vader_midir_LoopFrame_t*) l5)->f_exit_id;
        vader_struct_vader_midir_TermBranch_t* _a9_obj = (vader_struct_vader_midir_TermBranch_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_TermBranch_t));
        vader_obj_header_init(_a9_obj, 1136u);
        _a9_obj->f_span = l9;
        _a9_obj->f_target = l6;
        l5 = (void*) _a9_obj;
        vader_midir_terminate(l0, vader_ref_box(l5));
    } else if (l1.tag == 1010u) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_vader_lower_LoweredContinue_t*) t0)->f_label;
        l5 = vader_midir_resolve_loop_frame(l0, l2);
        t0 = l1.payload.obj;
        l9 = ((vader_struct_vader_lower_LoweredContinue_t*) t0)->f_span;
        vader_midir_build_back_edge(l0, l5, l9);
    } else {
        if (!((l1.tag == 998u || l1.tag == 1046u))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        vader_host_std_abort_panic(2137u);
        vader_unreachable("a no-return call returned");
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_midir_build_stored(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    vader_box_t l3 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l1, &l3, &t0 };
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l1.tag == 1020u) {
        l2 = l1.payload.obj;
        t0 = vader_midir_stored_ident(l0, l2);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 1015u) {
        l2 = l1.payload.obj;
        t0 = vader_midir_stored_field(l0, l2);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 1042u) {
        l2 = l1.payload.obj;
        t0 = vader_midir_stored_union_field(l0, l2);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l1.tag == 1005u)) {
        l3 = l1;
        t0 = vader_midir_build_expr(l0, l3);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = l1.payload.obj;
    t0 = vader_midir_stored_cell(l0, l2);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir_build_struct_lit(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    vader_box_t l4 = vader_box_null(), l8 = vader_box_null(), l9 = vader_box_null();
    int64_t l5, l6;
    int32_t l7;
    void* t0 = NULL;
    vader_box_t* gc_roots[3] = { &l4, &l8, &l9 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(15u, 0u, 7u, 288u);
    l2 = (void*) _a0_arr;
    l3 = ((vader_struct_vader_midir_ProjectCtx_t*) ((vader_struct_vader_midir_FnCtx_t*) l0)->f_project)->f_slots;
    l4 = ((vader_struct_vader_lower_LoweredStructLit_t*) l1)->f_type;
    l3 = vader_midir_literal_slots(l3, l4);
    l5 = INT64_C(0);
    l6 = ((vader_array_t*) ((vader_struct_vader_lower_LoweredStructLit_t*) l1)->f_fields)->length;
    while ((l5 < l6)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_lower_LoweredStructLit_t*) l1)->f_fields);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
        t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5);
        l4 = ((vader_struct_vader_lower_LoweredStructLitField_t*) t0)->f_value;
        l8 = vader_midir_type_at(l3, l5);
        l9 = vader_midir_build_held(l0, l4, l8);
        if (l9.tag == 0u) {
            { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
        }
        l7 = ((int32_t) l9.payload.i);
        vader_array_push_i32((vader_array_t*) l2, l7);
        l5 = (l5 + INT64_C(1));
    }
    l4 = ((vader_struct_vader_lower_LoweredStructLit_t*) l1)->f_type;
    l7 = vader_midir_fresh_tmp(l0, 2437u, l4);
    l3 = ((vader_struct_vader_lower_LoweredStructLit_t*) l1)->f_span;
    l4 = ((vader_struct_vader_lower_LoweredStructLit_t*) l1)->f_type;
    vader_struct_vader_midir_InstrStructNew_t* _a2_obj = (vader_struct_vader_midir_InstrStructNew_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrStructNew_t));
    vader_obj_header_init(_a2_obj, 1119u);
    _a2_obj->f_span = l3;
    _a2_obj->f_dst = l7;
    _a2_obj->f_type = l4;
    _a2_obj->f_fields = l2;
    _a2_obj->f_stack = false;
    l2 = (void*) _a2_obj;
    vader_midir_emit(l0, vader_ref_box(l2));
    { vader_box_t __vret = vader_box_i32(288u, l7); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir_build_type_check(void* l0, void* l1) {
    int32_t l2, l4;
    vader_box_t l3 = vader_box_null();
    void* l5 = NULL;
    vader_box_t* gc_roots[1] = { &l3 };
    void** gc_raw_roots[3] = { &l0, &l1, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_lower_LoweredTypeCheck_t*) l1)->f_value;
    l3 = vader_midir_build_expr(l0, l3);
    if (l3.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l2 = ((int32_t) l3.payload.i);
    l3 = ((vader_struct_vader_lower_LoweredTypeCheck_t*) l1)->f_type;
    l4 = vader_midir_fresh_tmp(l0, 2536u, l3);
    l5 = ((vader_struct_vader_lower_LoweredTypeCheck_t*) l1)->f_span;
    l3 = ((vader_struct_vader_lower_LoweredTypeCheck_t*) l1)->f_check_type;
    vader_struct_vader_midir_InstrTypeCheck_t* _a0_obj = (vader_struct_vader_midir_InstrTypeCheck_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrTypeCheck_t));
    vader_obj_header_init(_a0_obj, 1120u);
    _a0_obj->f_span = l5;
    _a0_obj->f_dst = l4;
    _a0_obj->f_value = l2;
    _a0_obj->f_check_type = l3;
    l5 = (void*) _a0_obj;
    vader_midir_emit(l0, vader_ref_box(l5));
    { vader_box_t __vret = vader_box_i32(288u, l4); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir_build_type_const(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l5 = vader_box_null();
    int32_t l3;
    void* l4 = NULL;
    vader_box_t* gc_roots[2] = { &l2, &l5 };
    void** gc_raw_roots[3] = { &l0, &l1, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_lower_LoweredTypeConst_t*) l1)->f_type;
    l3 = vader_midir_fresh_tmp(l0, 2537u, l2);
    l4 = ((vader_struct_vader_lower_LoweredTypeConst_t*) l1)->f_span;
    l2 = ((vader_struct_vader_lower_LoweredTypeConst_t*) l1)->f_type;
    l5 = ((vader_struct_vader_lower_LoweredTypeConst_t*) l1)->f_value;
    vader_struct_vader_midir_InstrTypeConst_t* _a0_obj = (vader_struct_vader_midir_InstrTypeConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrTypeConst_t));
    vader_obj_header_init(_a0_obj, 1121u);
    _a0_obj->f_span = l4;
    _a0_obj->f_dst = l3;
    _a0_obj->f_type = l2;
    _a0_obj->f_value_type = l5;
    l4 = (void*) _a0_obj;
    vader_midir_emit(l0, vader_ref_box(l4));
    { vader_box_t __vret = vader_box_i32(288u, l3); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir_build_unary(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l3 = vader_box_null();
    int32_t l4, l5;
    void* l6 = NULL;
    uint8_t l7;
    int32_t t0;
    vader_box_t* gc_roots[2] = { &l2, &l3 };
    void** gc_raw_roots[3] = { &l0, &l1, &l6 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = VADER_UNION_FIELD(vader_box_t, vader_struct_vader_lower_LoweredArrayLen_t, f_type, ((vader_struct_vader_lower_LoweredUnary_t*) l1)->f_operand.payload.obj);
    l3 = ((vader_struct_vader_lower_LoweredUnary_t*) l1)->f_type;
    l2 = vader_midir_computation_width(l2, vader_box_obj(0u, NULL), l3);
    l3 = ((vader_struct_vader_lower_LoweredUnary_t*) l1)->f_operand;
    l3 = vader_midir_build_held(l0, l3, l2);
    if (l3.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l4 = ((int32_t) l3.payload.i);
    l2 = vader_midir_computed_type(((vader_struct_vader_lower_LoweredUnary_t*) l1)->f_type, l2);
    l5 = vader_midir_fresh_tmp(l0, 2599u, l2);
    l6 = ((vader_struct_vader_lower_LoweredUnary_t*) l1)->f_span;
    l7 = ((vader_struct_vader_lower_LoweredUnary_t*) l1)->f_op;
    vader_struct_vader_midir_InstrUnOp_t* _a0_obj = (vader_struct_vader_midir_InstrUnOp_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrUnOp_t));
    vader_obj_header_init(_a0_obj, 1122u);
    _a0_obj->f_span = l6;
    _a0_obj->f_dst = l5;
    _a0_obj->f_op = l7;
    _a0_obj->f_operand = l4;
    _a0_obj->f_type = l2;
    l6 = (void*) _a0_obj;
    vader_midir_emit(l0, vader_ref_box(l6));
    l2 = ((vader_struct_vader_lower_LoweredUnary_t*) l1)->f_type;
    l6 = ((vader_struct_vader_lower_LoweredUnary_t*) l1)->f_span;
    t0 = vader_midir_held_in(l0, l5, l2, l6);
    { vader_box_t __vret = vader_box_i32(288u, t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir_build_union_field(void* l0, void* l1) {
    int32_t l2;
    vader_box_t l3 = vader_box_null();
    void* l4 = NULL;
    int32_t t0;
    vader_box_t* gc_roots[1] = { &l3 };
    void** gc_raw_roots[3] = { &l0, &l1, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = vader_midir_stored_union_field(l0, l1);
    if (l3.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l2 = ((int32_t) l3.payload.i);
    l3 = ((vader_struct_vader_lower_LoweredUnionField_t*) l1)->f_type;
    l4 = ((vader_struct_vader_lower_LoweredUnionField_t*) l1)->f_span;
    t0 = vader_midir_read_as(l0, l2, l3, l4);
    { vader_box_t __vret = vader_box_i32(288u, t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir_build_unreachable_type(void* l0, vader_box_t l1, void* l2, vader_string_t l3) {
    vader_box_t l4 = vader_box_null();
    void* l5 = NULL;
    bool t0;
    int32_t t1;
    vader_box_t* gc_roots[2] = { &l1, &l4 };
    void** gc_raw_roots[3] = { &l0, &l2, &l5 };
    vader_string_t* gc_atom_roots[1] = { &l3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (((vader_struct_vader_midir_FnCtx_t*) l0)->f_current.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    t0 = vader_typecheck_is_void(l1);
    if (t0) {
        l4 = vader_box_obj(0u, NULL);
        vader_struct_vader_midir_TermUnreachable_t* _a0_obj = (vader_struct_vader_midir_TermUnreachable_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_TermUnreachable_t));
        vader_obj_header_init(_a0_obj, 1139u);
        _a0_obj->f_span = l2;
        _a0_obj->f_reason = l3;
        l5 = (void*) _a0_obj;
        vader_midir_terminate(l0, vader_ref_box(l5));
        { vader_box_t __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_midir_declare_local(l0, 2600u, l1, vader_box_obj(0u, NULL));
    l4 = vader_box_i32(288u, t1);
    vader_struct_vader_midir_TermUnreachable_t* _a1_obj = (vader_struct_vader_midir_TermUnreachable_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_TermUnreachable_t));
    vader_obj_header_init(_a1_obj, 1139u);
    _a1_obj->f_span = l2;
    _a1_obj->f_reason = l3;
    l5 = (void*) _a1_obj;
    vader_midir_terminate(l0, vader_ref_box(l5));
    { vader_box_t __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir_build_virtual_call(void* l0, void* l1) {
    int32_t l2;
    vader_box_t l3 = vader_box_null(), l6 = vader_box_null();
    void* l4 = NULL;
    void* l5 = NULL;
    void* l9 = NULL;
    vader_string_t l7 = 0;
    vader_string_t l8 = 0;
    bool t0;
    int32_t t1;
    vader_box_t* gc_roots[2] = { &l3, &l6 };
    void** gc_raw_roots[5] = { &l0, &l1, &l4, &l5, &l9 };
    vader_string_t* gc_atom_roots[2] = { &l7, &l8 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_lower_LoweredVirtualCall_t*) l1)->f_receiver;
    l3 = vader_midir_build_expr(l0, l3);
    if (l3.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l2 = ((int32_t) l3.payload.i);
    l4 = ((vader_struct_vader_lower_LoweredVirtualCall_t*) l1)->f_args;
    l5 = ((vader_struct_vader_lower_LoweredVirtualCall_t*) l1)->f_param_types;
    l3 = vader_midir_build_args(l0, l4, l5);
    if (l3.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l4 = l3.payload.obj;
    t0 = vader_typecheck_is_void(((vader_struct_vader_lower_LoweredVirtualCall_t*) l1)->f_type);
    if (t0) {
        l3 = vader_box_obj(0u, NULL);
    } else {
        l6 = ((vader_struct_vader_lower_LoweredVirtualCall_t*) l1)->f_type;
        t1 = vader_midir_fresh_tmp(l0, 2767u, l6);
        l3 = vader_box_i32(288u, t1);
    }
    l5 = ((vader_struct_vader_lower_LoweredVirtualCall_t*) l1)->f_span;
    l7 = ((vader_struct_vader_lower_LoweredVirtualCall_t*) l1)->f_trait_name;
    l8 = ((vader_struct_vader_lower_LoweredVirtualCall_t*) l1)->f_method;
    l6 = ((vader_struct_vader_lower_LoweredVirtualCall_t*) l1)->f_type;
    l9 = ((vader_struct_vader_lower_LoweredVirtualCall_t*) l1)->f_param_types;
    vader_struct_vader_midir_InstrVirtualCall_t* _a0_obj = (vader_struct_vader_midir_InstrVirtualCall_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrVirtualCall_t));
    vader_obj_header_init(_a0_obj, 1125u);
    _a0_obj->f_span = l5;
    _a0_obj->f_dst = l3;
    _a0_obj->f_trait_name = l7;
    _a0_obj->f_method = l8;
    _a0_obj->f_receiver = l2;
    _a0_obj->f_args = l4;
    _a0_obj->f_type = l6;
    _a0_obj->f_param_types = l9;
    l4 = (void*) _a0_obj;
    vader_midir_emit(l0, vader_ref_box(l4));
    { vader_box_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_midir_build_vtables_from_entries(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l11 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    void* l23 = NULL;
    void* l24 = NULL;
    void* l25 = NULL;
    int64_t l5, l6, l7, l8, l22;
    vader_box_t l9 = vader_box_null(), l19 = vader_box_null(), l21 = vader_box_null();
    vader_string_t l10 = 0;
    vader_string_t l15 = 0;
    vader_string_t l16 = 0;
    vader_string_t l18 = 0;
    int32_t l17, l20;
    void* t0 = NULL;
    bool t1;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[4] = { &l9, &l19, &l21, &t2 };
    void** gc_raw_roots[13] = {
        &l0, &l1, &l2, &l3, &l4, &l11, &l12, &l13, &l14, &l23, &l24, &l25, &t0,
    };
    vader_string_t* gc_atom_roots[4] = { &l10, &l15, &l16, &l18 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 13u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(14u, 0u, 0u, 285u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(12u, 0u, 12u, 283u);
    l3 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(15u, 0u, 7u, 288u);
    l4 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__string__bool_t* _a3_obj = (vader_struct_std_collections_MutableMap__string__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__bool_t));
    vader_obj_header_init(_a3_obj, 454u);
    _a3_obj->f_ekeys = l2;
    _a3_obj->f_evals = l3;
    _a3_obj->f_index = l4;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    l2 = (void*) _a3_obj;
    l3 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_functions;
    l5 = ((vader_array_t*) l3)->length;
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        t0 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l6);
        l4 = ((vader_struct_vader_bytecode_BcFunction_t*) t0)->f_body;
        l7 = ((vader_array_t*) l4)->length;
        l8 = INT64_C(0);
        while ((l8 < l7)) {
            vader_array_t* _a5_slotarr = ((vader_array_t*) l4);
            VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
            l9 = vader_array_ref_load_box(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l8);
            if (l9.tag == 805u) {
                t0 = l9.payload.obj;
                l10 = ((vader_struct_vader_bytecode_VirtualCall_t*) t0)->f_vtable_key;
                std_collections_MutableMap_std_core_IndexSet_set_at__string__bool(l2, l10, true);
            }
            l8 = (l8 + INT64_C(1));
        }
        l6 = (l6 + INT64_C(1));
    }
    vader_array_t* _a6_arr = vader_array_new(14u, 0u, 0u, 285u);
    l3 = (void*) _a6_arr;
    vader_array_t* _a7_arr = vader_array_new(16u, 0u, 8u, 289u);
    l4 = (void*) _a7_arr;
    vader_array_t* _a8_arr = vader_array_new(15u, 0u, 7u, 288u);
    l11 = (void*) _a8_arr;
    vader_struct_std_collections_MutableMap__string__i64_t* _a9_obj = (vader_struct_std_collections_MutableMap__string__i64_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__i64_t));
    vader_obj_header_init(_a9_obj, 457u);
    _a9_obj->f_ekeys = l3;
    _a9_obj->f_evals = l4;
    _a9_obj->f_index = l11;
    _a9_obj->f_mask = INT64_C(0);
    _a9_obj->f_size = INT64_C(0);
    _a9_obj->f_tombs = INT64_C(0);
    l3 = (void*) _a9_obj;
    vader_array_t* _a10_arr = vader_array_new(61u, 0u, 13u, 807u);
    l4 = (void*) _a10_arr;
    vader_array_t* _a11_arr = vader_array_new(128u, 0u, 13u, 1045u);
    l11 = (void*) _a11_arr;
    vader_array_t* _a12_arr = vader_array_new(128u, 0u, 13u, 1045u);
    l12 = (void*) _a12_arr;
    l13 = l0;
    l5 = ((vader_array_t*) l13)->length;
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a13_slotarr = ((vader_array_t*) l13);
        VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
        l14 = vader_array_ref_load_obj(_a13_slotarr->buf, _a13_slotarr->offset + (size_t) l6);
        t1 = vader_types_boxes_as_representation(((vader_struct_vader_lower_LoweredVtableEntry_t*) l14)->f_struct_type);
        if (t1) {
            vader_array_push((vader_array_t*) l12, vader_ref_box(l14));
        } else {
            vader_array_push((vader_array_t*) l11, vader_ref_box(l14));
        }
        l6 = (l6 + INT64_C(1));
    }
    vader_array_push_all((vader_array_t*) l11, (vader_array_t*) l12);
    l5 = ((vader_array_t*) l11)->length;
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a14_slotarr = ((vader_array_t*) l11);
        VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
        l12 = vader_array_ref_load_obj(_a14_slotarr->buf, _a14_slotarr->offset + (size_t) l6);
        l10 = ((vader_struct_vader_lower_LoweredVtableEntry_t*) l12)->f_trait_name;
        l15 = ((vader_struct_vader_lower_LoweredVtableEntry_t*) l12)->f_method_name;
        l16 = vader_midir_vtable_key(l10, l15);
        t2 = std_collections_MutableMap_std_core_Index_at__string__bool(l2, l16);
        if (t2.tag == 283u) {
            l9 = vader_midir_resolve_fn_index(((vader_struct_vader_lower_LoweredVtableEntry_t*) l12)->f_fn_symbol, l1);
            if (l9.tag == 0u) {
                l6 = (l6 + INT64_C(1));
                continue;
            }
            l17 = ((int32_t) l9.payload.i);
            l18 = vader_bytecode_type_intern_key(((vader_struct_vader_lower_LoweredVtableEntry_t*) l12)->f_struct_type);
            l19 = std_collections_MutableMap_std_core_Index_at__string__i32(((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_type_key, l18);
            if (l19.tag == 288u) {
                l20 = ((int32_t) l19.payload.i);
                l21 = std_collections_MutableMap_std_core_Index_at__string__i64(l3, l16);
                if (l21.tag == 289u) {
                    l7 = ((int64_t) l21.payload.i);
                    vader_array_t* _a15_slotarr = ((vader_array_t*) l4);
                    VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a15_slotarr, l7)
                    t0 = vader_array_ref_load_obj(_a15_slotarr->buf, _a15_slotarr->offset + (size_t) l7);
                    t1 = vader_midir_has_receiver(t0, l20);
                    if (t1) {
                        l6 = (l6 + INT64_C(1));
                        continue;
                    }
                    l8 = ((int64_t) l21.payload.i);
                    vader_array_t* _a16_slotarr = ((vader_array_t*) l4);
                    VADER_ARRAY_RESOLVE_BUF(_a16_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a16_slotarr, l8)
                    t0 = vader_array_ref_load_obj(_a16_slotarr->buf, _a16_slotarr->offset + (size_t) l8);
                    l13 = ((vader_struct_vader_bytecode_VtableRow_t*) t0)->f_entries;
                    vader_struct_vader_bytecode_VtableEntry_t* _a17_obj = (vader_struct_vader_bytecode_VtableEntry_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_VtableEntry_t));
                    vader_obj_header_init(_a17_obj, 806u);
                    _a17_obj->f_receiver_type_index = l20;
                    _a17_obj->f_fn_index = l17;
                    l14 = (void*) _a17_obj;
                    vader_array_push((vader_array_t*) l13, vader_ref_box(l14));
                } else {
                    l22 = ((vader_array_t*) l4)->length;
                    vader_array_t* _a18_arr = vader_array_new(60u, 0u, 13u, 806u);
                    l23 = (void*) _a18_arr;
                    vader_struct_vader_bytecode_VtableEntry_t* _a19_obj = (vader_struct_vader_bytecode_VtableEntry_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_VtableEntry_t));
                    vader_obj_header_init(_a19_obj, 806u);
                    _a19_obj->f_receiver_type_index = l20;
                    _a19_obj->f_fn_index = l17;
                    l24 = (void*) _a19_obj;
                    vader_array_push((vader_array_t*) l23, vader_ref_box(l24));
                    vader_struct_vader_bytecode_VtableRow_t* _a20_obj = (vader_struct_vader_bytecode_VtableRow_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_VtableRow_t));
                    vader_obj_header_init(_a20_obj, 807u);
                    _a20_obj->f_key = l16;
                    _a20_obj->f_entries = l23;
                    l25 = (void*) _a20_obj;
                    vader_array_push((vader_array_t*) l4, vader_ref_box(l25));
                    std_collections_MutableMap_std_core_IndexSet_set_at__string__i64(l3, l16, l22);
                }
                l6 = (l6 + INT64_C(1));
                continue;
            }
            l6 = (l6 + INT64_C(1));
            continue;
        }
        l6 = (l6 + INT64_C(1));
    }
    { void* __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_midir_c_header_of(void* l0) {
    void* l1;
    void* l4;
    int64_t l2, l3;
    vader_box_t l5, l6;
    vader_string_t t0;
    int64_t t1;
    void* t2;
    l1 = l0;
    l2 = ((vader_array_t*) l1)->length;
    l3 = INT64_C(0);
    while ((l3 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l4 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
        t0 = ((vader_struct_toolchain_ast_Decorator_t*) l4)->f_name;
        if (t0 == 1527u) {
            t1 = ((vader_array_t*) ((vader_struct_toolchain_ast_Decorator_t*) l4)->f_args)->length;
            if (t1 == INT64_C(1)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_Decorator_t*) l4)->f_args);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, INT32_C(0))
                l5 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) INT32_C(0));
                if (l5.tag == 600u) {
                    t2 = l5.payload.obj;
                    t1 = ((vader_array_t*) ((vader_struct_toolchain_ast_StringLitExpr_t*) t2)->f_parts)->length;
                    if (t1 == INT64_C(1)) {
                        t2 = l5.payload.obj;
                        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_StringLitExpr_t*) t2)->f_parts);
                        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, INT32_C(0))
                        l6 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) INT32_C(0));
                        if (l6.tag == 602u) {
                            t2 = l6.payload.obj;
                            t0 = ((vader_struct_toolchain_ast_StringLitText_t*) t2)->f_value;
                            return t0;
                        }
                    }
                }
            }
        }
        l3 = (l3 + INT64_C(1));
    }
    return 0u;
}

static vader_string_t vader_midir_c_struct_of(void* l0) {
    vader_box_t l1, l6;
    void* l2;
    void* l5;
    int64_t l3, l4;
    void* t0;
    vader_string_t t1;
    int64_t t2;
    l1 = ((vader_struct_vader_comptime_MonoEntry_t*) l0)->f_decl;
    if (!(l1.tag == 603u)) {
        return 0u;
    }
    t0 = l1.payload.obj;
    l2 = ((vader_struct_toolchain_ast_StructDecl_t*) t0)->f_decorators;
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l5 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        t1 = ((vader_struct_toolchain_ast_Decorator_t*) l5)->f_name;
        if (t1 == 1530u) {
            t2 = ((vader_array_t*) ((vader_struct_toolchain_ast_Decorator_t*) l5)->f_args)->length;
            if (t2 == INT64_C(1)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_Decorator_t*) l5)->f_args);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, INT32_C(0))
                l1 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) INT32_C(0));
                if (l1.tag == 600u) {
                    t0 = l1.payload.obj;
                    t2 = ((vader_array_t*) ((vader_struct_toolchain_ast_StringLitExpr_t*) t0)->f_parts)->length;
                    if (t2 == INT64_C(1)) {
                        t0 = l1.payload.obj;
                        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_StringLitExpr_t*) t0)->f_parts);
                        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, INT32_C(0))
                        l6 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) INT32_C(0));
                        if (l6.tag == 602u) {
                            t0 = l6.payload.obj;
                            t1 = ((vader_struct_toolchain_ast_StringLitText_t*) t0)->f_value;
                            return t1;
                        }
                    }
                }
            }
        }
        l4 = (l4 + INT64_C(1));
    }
    return 0u;
}

static int32_t vader_midir_c_variadic_fixed_of(void* l0) {
    void* l1;
    void* l4;
    int64_t l2, l3;
    vader_box_t l5;
    vader_string_t t0;
    int64_t t1;
    void* t2;
    l1 = l0;
    l2 = ((vader_array_t*) l1)->length;
    l3 = INT64_C(0);
    while ((l3 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l4 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
        t0 = ((vader_struct_toolchain_ast_Decorator_t*) l4)->f_name;
        if (t0 == 1532u) {
            t1 = ((vader_array_t*) ((vader_struct_toolchain_ast_Decorator_t*) l4)->f_args)->length;
            if (t1 == INT64_C(1)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_Decorator_t*) l4)->f_args);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, INT32_C(0))
                l5 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) INT32_C(0));
                if (l5.tag == 575u) {
                    t2 = l5.payload.obj;
                    t1 = toolchain_ast_int_literal_value(t2);
                    return ((int32_t) (int64_t) t1);
                }
            }
        }
        l3 = (l3 + INT64_C(1));
    }
    return INT32_C(-1);
}

static vader_box_t vader_midir_call_single_dst(void* l0) {
    int64_t t0;
    int32_t t1;
    t0 = ((vader_array_t*) ((vader_struct_vader_midir_InstrCall_t*) l0)->f_dsts)->length;
    if (!(t0 != INT64_C(1))) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_midir_InstrCall_t*) l0)->f_dsts);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
        t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) INT32_C(0)];
        return vader_box_i32(288u, t1);
    }
    return vader_box_obj(0u, NULL);
}

static bool vader_midir_can_pass_through_stack(vader_box_t l0, vader_box_t l1, void* l2) {
    int32_t l3;
    vader_box_t l4;
    int32_t t0;
    bool t1;
    l4 = vader_midir_dst_of(l0);
    if (l4.tag == 0u) {
        return false;
    }
    l3 = ((int32_t) l4.payload.i);
    l4 = std_collections_MutableMap_std_core_Index_at__i32__i32(l2, l3);
    if (l4.tag == 0u) {
        return false;
    }
    t0 = ((int32_t) l4.payload.i);
    if (t0 != INT32_C(1)) {
        return false;
    }
    l4 = vader_midir_first_stack_operand(l1);
    if (l4.tag == 0u) {
        return false;
    }
    t0 = ((int32_t) l4.payload.i);
    t1 = vader_midir_LocalId_std_core_Equals_equals(t0, l3);
    return t1;
}

static bool vader_midir_can_pass_through_terminator(vader_box_t l0, vader_box_t l1, void* l2) {
    int32_t l3;
    vader_box_t l4;
    int32_t t0;
    bool t1;
    l4 = vader_midir_dst_of(l0);
    if (l4.tag == 0u) {
        return false;
    }
    l3 = ((int32_t) l4.payload.i);
    l4 = std_collections_MutableMap_std_core_Index_at__i32__i32(l2, l3);
    if (l4.tag == 0u) {
        return false;
    }
    t0 = ((int32_t) l4.payload.i);
    if (t0 != INT32_C(1)) {
        return false;
    }
    l4 = vader_midir_first_terminator_operand(l1);
    if (l4.tag == 0u) {
        return false;
    }
    t0 = ((int32_t) l4.payload.i);
    t1 = vader_midir_LocalId_std_core_Equals_equals(t0, l3);
    return t1;
}

static int32_t vader_midir_cast_local(void* l0, int32_t l1, vader_box_t l2, vader_string_t l3, void* l4) {
    int32_t l5;
    void* l6 = NULL;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[3] = { &l0, &l4, &l6 };
    vader_string_t* gc_atom_roots[1] = { &l3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l5 = vader_midir_fresh_tmp(l0, l3, l2);
    vader_struct_vader_midir_InstrCast_t* _a0_obj = (vader_struct_vader_midir_InstrCast_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrCast_t));
    vader_obj_header_init(_a0_obj, 1102u);
    _a0_obj->f_span = l4;
    _a0_obj->f_dst = l5;
    _a0_obj->f_value = l1;
    _a0_obj->f_type = l2;
    l6 = (void*) _a0_obj;
    vader_midir_emit(l0, vader_ref_box(l6));
    { int32_t __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_midir_cf_block(void* l0, void* l1, int32_t l2) {
    void* l3 = NULL;
    void* l5 = NULL;
    int32_t l4;
    void** gc_raw_roots[4] = { &l0, &l1, &l3, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_bytecode_Block_t* _a0_obj = (vader_struct_vader_bytecode_Block_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_Block_t));
    vader_obj_header_init(_a0_obj, 660u);
    l3 = (void*) _a0_obj;
    l4 = vader_midir_push_op_with_span(l0, vader_ref_box(l3), l1);
    l3 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_scopes;
    vader_struct_vader_midir_ScopeFrame_t* _a1_obj = (vader_struct_vader_midir_ScopeFrame_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_ScopeFrame_t));
    vader_obj_header_init(_a1_obj, 1133u);
    _a1_obj->f_kind = 1456u;
    _a1_obj->f_target_blk = l2;
    _a1_obj->f_opener_pc = l4;
    l5 = (void*) _a1_obj;
    vader_array_push((vader_array_t*) l3, vader_ref_box(l5));
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_midir_cf_br(void* l0, void* l1, int32_t l2) {
    void* l3 = NULL;
    int32_t l4;
    void** gc_raw_roots[3] = { &l0, &l1, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_bytecode_Branch_t* _a0_obj = (vader_struct_vader_bytecode_Branch_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_Branch_t));
    vader_obj_header_init(_a0_obj, 667u);
    l3 = (void*) _a0_obj;
    l4 = vader_midir_push_op_with_span(l0, vader_ref_box(l3), l1);
    vader_midir_defer_or_resolve_branch(l0, l2, l4);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_midir_cf_br_if(void* l0, void* l1, int32_t l2) {
    void* l3 = NULL;
    int32_t l4;
    void** gc_raw_roots[3] = { &l0, &l1, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_bytecode_BranchIf_t* _a0_obj = (vader_struct_vader_bytecode_BranchIf_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BranchIf_t));
    vader_obj_header_init(_a0_obj, 668u);
    l3 = (void*) _a0_obj;
    l4 = vader_midir_push_op_with_span(l0, vader_ref_box(l3), l1);
    vader_midir_defer_or_resolve_branch(l0, l2, l4);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_midir_cf_else(void* l0, void* l1) {
    void* l2 = NULL;
    void* l6 = NULL;
    int32_t l3, l7, l8;
    int64_t l4, l5;
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &l6 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_bytecode_Else_t* _a0_obj = (vader_struct_vader_bytecode_Else_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_Else_t));
    vader_obj_header_init(_a0_obj, 686u);
    l2 = (void*) _a0_obj;
    l3 = vader_midir_push_op_with_span(l0, vader_ref_box(l2), l1);
    l4 = ((vader_array_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_scopes)->length;
    if (!(l4 == INT64_C(0))) {
        l2 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_scopes;
        l5 = vader_chk_sub(i64, l4, INT64_C(1));
        vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
        l2 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5);
        l6 = ((vader_struct_vader_bytecode_BcFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_slot)->f_jump_table;
        l7 = ((vader_struct_vader_midir_ScopeFrame_t*) l2)->f_opener_pc;
        l8 = vader_chk_add(i32, l3, INT32_C(1));
        vader_array_t* _a2_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l7)
        ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l7] = (int32_t) l8;
        l6 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_scopes;
        l4 = vader_chk_sub(i64, l4, INT64_C(1));
        l7 = ((vader_struct_vader_midir_ScopeFrame_t*) l2)->f_target_blk;
        vader_struct_vader_midir_ScopeFrame_t* _a3_obj = (vader_struct_vader_midir_ScopeFrame_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_ScopeFrame_t));
        vader_obj_header_init(_a3_obj, 1133u);
        _a3_obj->f_kind = 1935u;
        _a3_obj->f_target_blk = l7;
        _a3_obj->f_opener_pc = l3;
        l2 = (void*) _a3_obj;
        vader_array_t* _a4_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l4)
        vader_array_ref_store(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l4, l2);
        VADER_WRITE_BARRIER(_a4_slotarr->buf);
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_midir_cf_end(void* l0, void* l1) {
    void* l2 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    int32_t l3, l8, l9;
    int64_t l4, l5;
    bool l10;
    vader_string_t t0 = 0;
    int32_t t1;
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l6, &l7 };
    vader_string_t* gc_atom_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_struct_vader_bytecode_End_t* _a0_obj = (vader_struct_vader_bytecode_End_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_End_t));
    vader_obj_header_init(_a0_obj, 689u);
    l2 = (void*) _a0_obj;
    l3 = vader_midir_push_op_with_span(l0, vader_ref_box(l2), l1);
    l4 = ((vader_array_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_scopes)->length;
    if (l4 == INT64_C(0)) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l2 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_scopes;
    l5 = vader_chk_sub(i64, l4, INT64_C(1));
    vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
    l2 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5);
    vader_array_t* _a2_arr = vader_array_new(147u, 0u, 13u, 1133u);
    l6 = (void*) _a2_arr;
    l5 = INT64_C(0);
    l4 = vader_chk_sub(i64, l4, INT64_C(1));
    while ((l5 < l4)) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_scopes);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l5)
        l7 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l5);
        vader_array_push((vader_array_t*) l6, vader_ref_box(l7));
        l5 = (l5 + INT64_C(1));
    }
    ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_scopes = l6;
    VADER_WRITE_BARRIER((vader_struct_vader_midir_FnEmitCfg_t*) l0);
    t0 = ((vader_struct_vader_midir_ScopeFrame_t*) l2)->f_kind;
    if (t0 != 2085u) {
        l6 = ((vader_struct_vader_bytecode_BcFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_slot)->f_jump_table;
        l8 = ((vader_struct_vader_midir_ScopeFrame_t*) l2)->f_opener_pc;
        vader_array_t* _a4_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l8)
        t1 = ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l8];
        if ((t1 < INT32_C(0))) {
            l6 = ((vader_struct_vader_bytecode_BcFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_slot)->f_jump_table;
            l8 = ((vader_struct_vader_midir_ScopeFrame_t*) l2)->f_opener_pc;
            l9 = vader_chk_add(i32, l3, INT32_C(1));
            vader_array_t* _a5_slotarr = ((vader_array_t*) l6);
            VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l8)
            ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l8] = (int32_t) l9;
        }
    }
    l8 = ((vader_struct_vader_midir_ScopeFrame_t*) l2)->f_target_blk;
    t0 = ((vader_struct_vader_midir_ScopeFrame_t*) l2)->f_kind;
    l10 = t0 == 2085u;
    l9 = ((vader_struct_vader_midir_ScopeFrame_t*) l2)->f_opener_pc;
    vader_midir_drain_pending(l0, l8, l10, l9, l3);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_midir_cf_if(void* l0, void* l1) {
    void* l2 = NULL;
    void* l4 = NULL;
    int32_t l3;
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_bytecode_If_t* _a0_obj = (vader_struct_vader_bytecode_If_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_If_t));
    vader_obj_header_init(_a0_obj, 748u);
    l2 = (void*) _a0_obj;
    l3 = vader_midir_push_op_with_span(l0, vader_ref_box(l2), l1);
    l2 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_scopes;
    vader_struct_vader_midir_ScopeFrame_t* _a1_obj = (vader_struct_vader_midir_ScopeFrame_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_ScopeFrame_t));
    vader_obj_header_init(_a1_obj, 1133u);
    _a1_obj->f_kind = 1935u;
    _a1_obj->f_target_blk = INT32_C(-1);
    _a1_obj->f_opener_pc = l3;
    l4 = (void*) _a1_obj;
    vader_array_push((vader_array_t*) l2, vader_ref_box(l4));
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_midir_cf_loop(void* l0, void* l1, int32_t l2) {
    void* l3 = NULL;
    void* l5 = NULL;
    int32_t l4, l6;
    void** gc_raw_roots[4] = { &l0, &l1, &l3, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_bytecode_Loop_t* _a0_obj = (vader_struct_vader_bytecode_Loop_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_Loop_t));
    vader_obj_header_init(_a0_obj, 761u);
    l3 = (void*) _a0_obj;
    l4 = vader_midir_push_op_with_span(l0, vader_ref_box(l3), l1);
    l3 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_scopes;
    vader_struct_vader_midir_ScopeFrame_t* _a1_obj = (vader_struct_vader_midir_ScopeFrame_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_ScopeFrame_t));
    vader_obj_header_init(_a1_obj, 1133u);
    _a1_obj->f_kind = 2085u;
    _a1_obj->f_target_blk = l2;
    _a1_obj->f_opener_pc = l4;
    l5 = (void*) _a1_obj;
    vader_array_push((vader_array_t*) l3, vader_ref_box(l5));
    l3 = ((vader_struct_vader_bytecode_BcFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_slot)->f_jump_table;
    l6 = vader_chk_add(i32, l4, INT32_C(1));
    vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
    ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l4] = (int32_t) l6;
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_midir_close_blocks(void* l0, void* l1, void* l2, int32_t l3) {
    int64_t l4, l5, l7, l8, l9;
    int32_t l6, l11, l13;
    void* l10 = NULL;
    void* l12 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l10, &l12, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 6u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l4 = INT64_C(0);
    l5 = ((vader_array_t*) l2)->length;
    while ((l4 < l5)) {
        l7 = vader_chk_add(i64, l4, INT64_C(1));
        l8 = ((vader_array_t*) l2)->length;
        if ((l7 < l8)) {
            l9 = vader_chk_add(i64, l4, INT64_C(1));
            vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l9)
            l6 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l9];
        } else {
            l6 = l3;
        }
        l10 = ((vader_struct_vader_midir_CFGFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_fn_)->f_blocks;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l11 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
        vader_array_t* _a2_slotarr = ((vader_array_t*) l10);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l11)
        t0 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l11);
        l12 = ((vader_struct_vader_midir_BasicBlock_t*) t0)->f_span;
        vader_midir_cf_end(l0, l12);
        vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        l13 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l4];
        vader_midir_emit_subtree(l0, l1, l13, l6);
        l4 = (l4 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static bool vader_midir_closes_loop(void* l0, int32_t l1, int32_t l2) {
    vader_box_t l3;
    void* t0;
    bool t1;
    l3 = std_collections_MutableMap_std_core_Index_at__i32__Any(l0, l2);
    if (l3.tag == 0u) {
        return false;
    }
    t0 = l3.payload.obj;
    t1 = std_collections_MutableSet_std_core_Contains_contains__i32(t0, l1);
    return t1;
}

static vader_box_t vader_midir_closure_header_type(vader_box_t l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[4] = { &l1, &l2, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 1255u) {
        t0 = l0.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a0_arr = vader_array_new(244u, 0u, 13u, 1804u);
    l1 = (void*) _a0_arr;
    t0 = (void*) &vader_data_18;
    vader_array_t* _a1_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    l2 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) INT64_C(0));
    vader_array_t* _a2_arr = vader_array_new(198u, 0u, 13u, 1269u);
    l3 = (void*) _a2_arr;
    t0 = vader_types_mk_fn(l1, vader_ref_box(l2), l3);
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_midir_collect_baked_symbols(vader_box_t l0, void* l1) {
    int32_t l2;
    void* l3 = NULL;
    int64_t l4, l5;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l0, &t1 };
    void** gc_raw_roots[3] = { &l1, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 657u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_bytecode_BcValStruct_t*) t0)->f_symbol_id;
        std_collections_add__i32(l1, l2);
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_bytecode_BcValStruct_t*) t0)->f_fields;
        l4 = ((vader_array_t*) l3)->length;
        l5 = INT64_C(0);
        while ((l5 < l4)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            t1 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
            vader_midir_collect_baked_symbols(t1, l1);
            l5 = (l5 + INT64_C(1));
        }
    } else if (l0.tag == 654u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_bytecode_BcValArray_t*) t0)->f_elements;
        l4 = ((vader_array_t*) l3)->length;
        l5 = INT64_C(0);
        while ((l5 < l4)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            t1 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5);
            vader_midir_collect_baked_symbols(t1, l1);
            l5 = (l5 + INT64_C(1));
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void* vader_midir_compact_locals(void* l0) {
    int64_t l1, l5, l6, l9, l10, l14, l15, l23;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l13 = NULL;
    void* l20 = NULL;
    void* l21 = NULL;
    void* l22 = NULL;
    void* l25 = NULL;
    void* l26 = NULL;
    vader_box_t l11 = vader_box_null(), l12 = vader_box_null(), l16 = vader_box_null(), l24 = vader_box_null();
    bool l17, l28;
    int32_t l18;
    vader_string_t l19 = 0;
    vader_string_t l27 = 0;
    void* t0 = NULL;
    bool t1;
    int32_t t2;
    vader_box_t t3 = vader_box_null();
    int64_t t4;
    vader_box_t* gc_roots[5] = { &l11, &l12, &l16, &l24, &t3 };
    void** gc_raw_roots[13] = {
        &l0, &l2, &l3, &l4, &l7, &l8, &l13, &l20, &l21, &l22, &l25, &l26, &t0,
    };
    vader_string_t* gc_atom_roots[2] = { &l19, &l27 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 5u, 13u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = ((vader_array_t*) ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_locals)->length;
    vader_array_t* _a0_arr = vader_array_new(12u, 1u, 12u, 283u);
    ((uint8_t*) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = (uint8_t) false;
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l1);
    l2 = (void*) _a1_arr;
    vader_struct___lambda_env_vader_midir_1_t* _a2_obj = (vader_struct___lambda_env_vader_midir_1_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_midir_1_t));
    vader_obj_header_init(_a2_obj, 338u);
    _a2_obj->f_cap_0 = l2;
    t0 = (void*) _a2_obj;
    vader_fn_t* _a3_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
    vader_obj_header_init(_a3_closure, 261u);
    _a3_closure->code = (void*) &vader_fn_lift___lambda_vader_midir_0;
    _a3_closure->env = t0;
    l3 = (void*) _a3_closure;
    l4 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_params;
    l5 = ((vader_array_t*) l4)->length;
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l6)
        t0 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l6);
        vader_fn_t* _a5_fnobj = (vader_fn_t*) l3;
        ((vader_fn_erased_sig_1_t) _a5_fnobj->code)(_a5_fnobj->env, vader_box_i32(288u, ((vader_struct_vader_midir_CFGParam_t*) t0)->f_local));
        l6 = (l6 + INT64_C(1));
    }
    l4 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_blocks;
    l5 = ((vader_array_t*) l4)->length;
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a6_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l6)
        l7 = vader_array_ref_load_obj(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l6);
        l8 = ((vader_struct_vader_midir_BasicBlock_t*) l7)->f_instructions;
        l9 = ((vader_array_t*) l8)->length;
        l10 = INT64_C(0);
        while ((l10 < l9)) {
            vader_array_t* _a7_slotarr = ((vader_array_t*) l8);
            VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l10)
            l11 = vader_array_ref_load_box(_a7_slotarr->buf, _a7_slotarr->offset + (size_t) l10);
            vader_midir_for_each_read_local(l11, l3);
            t1 = vader_midir_instruction_has_side_effect(l11);
            if (t1) {
                l12 = vader_midir_multi_dsts(l11);
                if (l12.tag == 0u) {
                    l16 = vader_midir_dst_of(l11);
                    if (!(l16.tag == 0u)) {
                        t2 = ((int32_t) l16.payload.i);
                        vader_fn_t* _a8_fnobj = (vader_fn_t*) l3;
                        ((vader_fn_erased_sig_1_t) _a8_fnobj->code)(_a8_fnobj->env, vader_box_i32(288u, t2));
                    }
                } else {
                    l13 = l12.payload.obj;
                    l14 = ((vader_array_t*) l13)->length;
                    l15 = INT64_C(0);
                    while ((l15 < l14)) {
                        vader_array_t* _a9_slotarr = ((vader_array_t*) l13);
                        VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l15)
                        t2 = ((int32_t*) _a9_slotarr->buf->slots)[_a9_slotarr->offset + (size_t) l15];
                        vader_fn_t* _a10_fnobj = (vader_fn_t*) l3;
                        ((vader_fn_erased_sig_1_t) _a10_fnobj->code)(_a10_fnobj->env, vader_box_i32(288u, t2));
                        l15 = (l15 + INT64_C(1));
                    }
                }
            }
            l10 = (l10 + INT64_C(1));
        }
        vader_midir_for_each_read_in_terminator(((vader_struct_vader_midir_BasicBlock_t*) l7)->f_terminator, l3);
        l6 = (l6 + INT64_C(1));
    }
    l17 = false;
    l5 = ((vader_array_t*) ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_params)->length;
    for (;;) {
        if ((l5 < l1)) {
            vader_array_t* _a11_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l5)
            t3 = vader_box_bool(283u, ((uint8_t*) _a11_slotarr->buf->slots)[_a11_slotarr->offset + (size_t) l5]);
            t1 = t3.payload.b;
            if (t1) {
                l5 = (l5 + INT64_C(1));
                continue;
            }
            l17 = true;
            break;
        }
        break;
    }
    if (!(l17)) {
        { void* __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a12_arr = vader_array_new(15u, 0u, 7u, 288u);
    t0 = (void*) _a12_arr;
    vader_array_t* _a13_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l1);
    l3 = (void*) _a13_arr;
    vader_array_t* _a14_arr = vader_array_new(138u, 0u, 13u, 1072u);
    t0 = (void*) _a14_arr;
    vader_array_t* _a15_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l1);
    l4 = (void*) _a15_arr;
    l5 = INT64_C(0);
    while ((l5 < l1)) {
        vader_array_t* _a16_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a16_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a16_slotarr, l5)
        t3 = vader_box_bool(283u, ((uint8_t*) _a16_slotarr->buf->slots)[_a16_slotarr->offset + (size_t) l5]);
        t1 = t3.payload.b;
        if (t1) {
            t4 = ((vader_array_t*) l4)->length;
            l18 = ((int32_t) (int64_t) t4);
            vader_array_push_i32((vader_array_t*) l3, l18);
            vader_array_t* _a17_slotarr = ((vader_array_t*) ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_locals);
            VADER_ARRAY_RESOLVE_BUF(_a17_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a17_slotarr, l5)
            l7 = vader_array_ref_load_obj(_a17_slotarr->buf, _a17_slotarr->offset + (size_t) l5);
            vader_array_push((vader_array_t*) l4, vader_ref_box(l7));
            l5 = (l5 + INT64_C(1));
            continue;
        }
        vader_array_push_i32((vader_array_t*) l3, INT32_C(-1));
        l5 = (l5 + INT64_C(1));
    }
    vader_array_t* _a18_arr = vader_array_new(140u, 0u, 13u, 1074u);
    l2 = (void*) _a18_arr;
    l1 = ((vader_array_t*) ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_params)->length;
    vader_array_t* _a19_arr = vader_array_repeat((vader_array_t*) l2, (int64_t) l1);
    l2 = (void*) _a19_arr;
    l7 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_params;
    l1 = ((vader_array_t*) l7)->length;
    l5 = INT64_C(0);
    while ((l5 < l1)) {
        vader_array_t* _a20_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a20_slotarr)
        l8 = vader_array_ref_load_obj(_a20_slotarr->buf, _a20_slotarr->offset + (size_t) l5);
        l19 = ((vader_struct_vader_midir_CFGParam_t*) l8)->f_name;
        l13 = ((vader_struct_vader_midir_CFGParam_t*) l8)->f_symbol;
        l11 = ((vader_struct_vader_midir_CFGParam_t*) l8)->f_type;
        l6 = ((int64_t) (int32_t) ((vader_struct_vader_midir_CFGParam_t*) l8)->f_local);
        vader_array_t* _a21_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a21_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a21_slotarr, l6)
        l18 = ((int32_t*) _a21_slotarr->buf->slots)[_a21_slotarr->offset + (size_t) l6];
        vader_struct_vader_midir_CFGParam_t* _a22_obj = (vader_struct_vader_midir_CFGParam_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_CFGParam_t));
        vader_obj_header_init(_a22_obj, 1074u);
        _a22_obj->f_name = l19;
        _a22_obj->f_symbol = l13;
        _a22_obj->f_type = l11;
        _a22_obj->f_local = l18;
        l20 = (void*) _a22_obj;
        vader_array_push((vader_array_t*) l2, vader_ref_box(l20));
        l5 = (l5 + INT64_C(1));
    }
    vader_array_t* _a23_arr = vader_array_new(135u, 0u, 13u, 1069u);
    l7 = (void*) _a23_arr;
    l1 = ((vader_array_t*) ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_blocks)->length;
    vader_array_t* _a24_arr = vader_array_repeat((vader_array_t*) l7, (int64_t) l1);
    l7 = (void*) _a24_arr;
    l8 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_blocks;
    l1 = ((vader_array_t*) l8)->length;
    l5 = INT64_C(0);
    while ((l5 < l1)) {
        vader_array_t* _a25_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a25_slotarr)
        l13 = vader_array_ref_load_obj(_a25_slotarr->buf, _a25_slotarr->offset + (size_t) l5);
        vader_array_t* _a26_arr = vader_array_new(242u, 0u, 13u, 1745u);
        l20 = (void*) _a26_arr;
        l6 = ((vader_array_t*) ((vader_struct_vader_midir_BasicBlock_t*) l13)->f_instructions)->length;
        vader_array_t* _a27_arr = vader_array_repeat((vader_array_t*) l20, (int64_t) l6);
        l21 = (void*) _a27_arr;
        l22 = ((vader_struct_vader_midir_BasicBlock_t*) l13)->f_instructions;
        l9 = ((vader_array_t*) l22)->length;
        l10 = INT64_C(0);
        while ((l10 < l9)) {
            vader_array_t* _a28_slotarr = ((vader_array_t*) l22);
            VADER_ARRAY_RESOLVE_BUF(_a28_slotarr)
            l11 = vader_array_ref_load_box(_a28_slotarr->buf, _a28_slotarr->offset + (size_t) l10);
            l12 = vader_midir_dst_of(l11);
            if (l12.tag == 288u) {
                t2 = ((int32_t) l12.payload.i);
                l14 = ((int64_t) (int32_t) t2);
                if ((INT64_C(0) <= l14)) {
                    l15 = ((vader_array_t*) l3)->length;
                    l17 = (l14 < l15);
                } else {
                    l17 = false;
                }
                if (l17) {
                    t2 = ((int32_t) l12.payload.i);
                    l23 = ((int64_t) (int32_t) t2);
                    vader_array_t* _a29_slotarr = ((vader_array_t*) l3);
                    VADER_ARRAY_RESOLVE_BUF(_a29_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a29_slotarr, l23)
                    t2 = ((int32_t*) _a29_slotarr->buf->slots)[_a29_slotarr->offset + (size_t) l23];
                    if ((t2 < INT32_C(0))) {
                        t1 = vader_midir_instruction_has_side_effect(l11);
                        if (!(t1)) {
                            l10 = (l10 + INT64_C(1));
                            continue;
                        }
                    }
                }
            }
            l16 = vader_midir_remap_instr(l11, l3);
            vader_array_push((vader_array_t*) l21, l16);
            l10 = (l10 + INT64_C(1));
        }
        l18 = ((vader_struct_vader_midir_BasicBlock_t*) l13)->f_id;
        l24 = vader_midir_remap_terminator(((vader_struct_vader_midir_BasicBlock_t*) l13)->f_terminator, l3);
        l25 = ((vader_struct_vader_midir_BasicBlock_t*) l13)->f_span;
        vader_struct_vader_midir_BasicBlock_t* _a30_obj = (vader_struct_vader_midir_BasicBlock_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_BasicBlock_t));
        vader_obj_header_init(_a30_obj, 1069u);
        _a30_obj->f_id = l18;
        _a30_obj->f_instructions = l21;
        _a30_obj->f_terminator = l24;
        _a30_obj->f_span = l25;
        l26 = (void*) _a30_obj;
        vader_array_push((vader_array_t*) l7, vader_ref_box(l26));
        l5 = (l5 + INT64_C(1));
    }
    l3 = l0;
    l19 = ((vader_struct_vader_midir_CFGFunction_t*) l3)->f_mangled;
    l11 = ((vader_struct_vader_midir_CFGFunction_t*) l3)->f_return_type;
    l18 = ((vader_struct_vader_midir_CFGFunction_t*) l3)->f_entry;
    l8 = ((vader_struct_vader_midir_CFGFunction_t*) l3)->f_origin;
    l27 = ((vader_struct_vader_midir_CFGFunction_t*) l3)->f_extern_name;
    l17 = ((vader_struct_vader_midir_CFGFunction_t*) l3)->f_is_extern;
    l28 = ((vader_struct_vader_midir_CFGFunction_t*) l3)->f_is_exported;
    l3 = ((vader_struct_vader_midir_CFGFunction_t*) l3)->f_scalarised_results;
    vader_struct_vader_midir_CFGFunction_t* _a31_obj = (vader_struct_vader_midir_CFGFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_CFGFunction_t));
    vader_obj_header_init(_a31_obj, 1071u);
    _a31_obj->f_mangled = l19;
    _a31_obj->f_params = l2;
    _a31_obj->f_return_type = l11;
    _a31_obj->f_locals = l4;
    _a31_obj->f_blocks = l7;
    _a31_obj->f_entry = l18;
    _a31_obj->f_origin = l8;
    _a31_obj->f_extern_name = l27;
    _a31_obj->f_is_extern = l17;
    _a31_obj->f_is_exported = l28;
    _a31_obj->f_scalarised_results = l3;
    t0 = (void*) _a31_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_midir_compares_boxes(uint8_t l0, vader_box_t l1) {
    bool l2;
    bool t0;
    if (l0 == INT32_C(12)) {
        l2 = true;
    } else {
        l2 = l0 == INT32_C(13);
    }
    if (l2) {
        t0 = vader_midir_is_union_slot(l1);
        return t0;
    }
    return false;
}

static vader_box_t vader_midir_computation_integer(vader_box_t l0, vader_box_t l1, vader_box_t l2) {
    void* l3 = NULL;
    void* l8 = NULL;
    vader_box_t l4 = vader_box_null(), l5 = vader_box_null();
    vader_string_t l6 = 0;
    vader_string_t l7 = 0;
    void* t0 = NULL;
    vader_box_t* gc_roots[5] = { &l0, &l1, &l2, &l4, &l5 };
    void** gc_raw_roots[3] = { &l3, &l8, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l6, &l7 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 5u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = vader_types_held_integer(l0);
    if (l4.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l3 = l4.payload.obj;
    l4 = vader_types_held_integer(l2);
    l5 = vader_midir_operand_width(l1, l3);
    if (l5.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    t0 = l5.payload.obj;
    l6 = ((vader_struct_vader_integer_MachineInteger_t*) t0)->f_name;
    l7 = ((vader_struct_vader_integer_MachineInteger_t*) l3)->f_name;
    if (l6 == l7) {
        if (l4.tag == 0u) {
            { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
        }
        t0 = l4.payload.obj;
        l6 = ((vader_struct_vader_integer_MachineInteger_t*) t0)->f_name;
        l7 = ((vader_struct_vader_integer_MachineInteger_t*) l3)->f_name;
        if (l6 == l7) {
            { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
        }
    }
    l3 = ((vader_struct_vader_integer_MachineInteger_t*) l3)->f_values;
    t0 = l5.payload.obj;
    l8 = ((vader_struct_vader_integer_MachineInteger_t*) t0)->f_values;
    l3 = vader_integer_interval_join(l3, l8);
    if (l4.tag == 0u) {
        t0 = vader_integer_narrowest_machine_integer(l3);
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l4.payload.obj;
    l8 = ((vader_struct_vader_integer_MachineInteger_t*) t0)->f_values;
    l3 = vader_integer_interval_join(l3, l8);
    t0 = vader_integer_narrowest_machine_integer(l3);
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir_computation_width(vader_box_t l0, vader_box_t l1, vader_box_t l2) {
    vader_box_t l3 = vader_box_null();
    void* t0 = NULL;
    void* t2 = NULL;
    bool t1;
    vader_box_t* gc_roots[4] = { &l0, &l1, &l2, &l3 };
    void** gc_raw_roots[2] = { &t0, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 1263u) {
        t0 = l0.payload.obj;
        t1 = vader_midir_same_bounds(t0, l1);
        if (t1) {
            t0 = l0.payload.obj;
            t1 = vader_midir_same_bounds(t0, l2);
            if (t1) {
                { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
            }
        }
    }
    l3 = vader_midir_computation_integer(l0, l1, l2);
    if (l3.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    t0 = l3.payload.obj;
    t2 = vader_types_machine_integer_type(t0);
    { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_midir_compute_carried_across_loop_headers(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    void* l15 = NULL;
    void* l16 = NULL;
    void* l17 = NULL;
    void* l18 = NULL;
    void* l22 = NULL;
    void* l24 = NULL;
    void* l29 = NULL;
    void* l35 = NULL;
    void* l37 = NULL;
    void* l38 = NULL;
    int64_t l8, l9, l19, l20, l25, l26, l30, l31, l39, l40;
    int32_t l10, l11, l21, l23, l32, l34, l36, l41;
    vader_box_t l12 = vader_box_null(), l27 = vader_box_null(), l28 = vader_box_null(), l33 = vader_box_null();
    void* t0 = NULL;
    bool t1;
    int64_t t2;
    vader_box_t* gc_roots[4] = { &l12, &l27, &l28, &l33 };
    void** gc_raw_roots[21] = {
        &l0, &l1, &l2, &l3, &l4, &l5, &l6, &l7, &l13, &l14, &l15, &l16, &l17, &l18, &l22, &l24,
        &l29, &l35, &l37, &l38, &t0,
    };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 21u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(15u, 0u, 7u, 288u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(12u, 0u, 12u, 283u);
    l3 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(15u, 0u, 7u, 288u);
    l4 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__i32__bool_t* _a3_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
    vader_obj_header_init(_a3_obj, 381u);
    _a3_obj->f_ekeys = l2;
    _a3_obj->f_evals = l3;
    _a3_obj->f_index = l4;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a3_obj;
    vader_struct_std_collections_MutableSet__i32_t* _a4_obj = (vader_struct_std_collections_MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i32_t));
    vader_obj_header_init(_a4_obj, 517u);
    _a4_obj->f_inner = t0;
    l2 = (void*) _a4_obj;
    l3 = vader_midir_predecessors_of(l0);
    l4 = vader_midir_compute_dominators(l0, l3);
    l3 = vader_midir_natural_loop_bodies(l0, l3, l4);
    t1 = std_collections_is_empty__i32__Any(l3);
    if (t1) {
        { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = vader_midir_compute_liveness(l0);
    l5 = l3;
    l6 = ((vader_struct_std_collections_MutableMap__i32__std_collections_MutableSet_i32__t*) l5)->f_ekeys;
    l7 = ((vader_struct_std_collections_MutableMap__i32__std_collections_MutableSet_i32__t*) l5)->f_evals;
    l8 = INT64_C(0);
    l9 = ((vader_struct_std_collections_MutableMap__i32__std_collections_MutableSet_i32__t*) l5)->f_size;
    while ((l8 < l9)) {
        vader_array_t* _a5_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l8)
        l10 = ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l8];
        vader_array_t* _a6_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l8)
        t0 = vader_array_ref_load_obj(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l8);
        l11 = l10;
        l12 = std_collections_MutableMap_std_core_Index_at__i32__Any(l3, l11);
        if (!(l12.tag == 0u)) {
            l5 = l12.payload.obj;
            vader_array_t* _a7_arr = vader_array_new(15u, 0u, 7u, 288u);
            l13 = (void*) _a7_arr;
            vader_array_t* _a8_arr = vader_array_new(12u, 0u, 12u, 283u);
            l14 = (void*) _a8_arr;
            vader_array_t* _a9_arr = vader_array_new(15u, 0u, 7u, 288u);
            l15 = (void*) _a9_arr;
            vader_struct_std_collections_MutableMap__i32__bool_t* _a10_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
            vader_obj_header_init(_a10_obj, 381u);
            _a10_obj->f_ekeys = l13;
            _a10_obj->f_evals = l14;
            _a10_obj->f_index = l15;
            _a10_obj->f_mask = INT64_C(0);
            _a10_obj->f_size = INT64_C(0);
            _a10_obj->f_tombs = INT64_C(0);
            t0 = (void*) _a10_obj;
            vader_struct_std_collections_MutableSet__i32_t* _a11_obj = (vader_struct_std_collections_MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i32_t));
            vader_obj_header_init(_a11_obj, 517u);
            _a11_obj->f_inner = t0;
            l16 = (void*) _a11_obj;
            l17 = l5;
            l18 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) ((vader_struct_std_collections_MutableSet__i32_t*) l17)->f_inner)->f_ekeys;
            l19 = INT64_C(0);
            l20 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) ((vader_struct_std_collections_MutableSet__i32_t*) l17)->f_inner)->f_size;
            while ((l19 < l20)) {
                vader_array_t* _a12_slotarr = ((vader_array_t*) l18);
                VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a12_slotarr, l19)
                l21 = ((int32_t*) _a12_slotarr->buf->slots)[_a12_slotarr->offset + (size_t) l19];
                l22 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_blocks;
                l23 = l21;
                vader_array_t* _a13_slotarr = ((vader_array_t*) l22);
                VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a13_slotarr, l23)
                t0 = vader_array_ref_load_obj(_a13_slotarr->buf, _a13_slotarr->offset + (size_t) l23);
                l24 = ((vader_struct_vader_midir_BasicBlock_t*) t0)->f_instructions;
                l25 = ((vader_array_t*) l24)->length;
                l26 = INT64_C(0);
                while ((l26 < l25)) {
                    vader_array_t* _a14_slotarr = ((vader_array_t*) l24);
                    VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
                    l27 = vader_array_ref_load_box(_a14_slotarr->buf, _a14_slotarr->offset + (size_t) l26);
                    l28 = vader_midir_multi_dsts(l27);
                    if (l28.tag == 0u) {
                        l33 = vader_midir_dst_of(l27);
                        if (!(l33.tag == 0u)) {
                            l34 = ((int32_t) l33.payload.i);
                            std_collections_add__i32(l16, l34);
                        }
                    } else {
                        l29 = l28.payload.obj;
                        l30 = ((vader_array_t*) l29)->length;
                        l31 = INT64_C(0);
                        while ((l31 < l30)) {
                            vader_array_t* _a15_slotarr = ((vader_array_t*) l29);
                            VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
                            l32 = ((int32_t*) _a15_slotarr->buf->slots)[_a15_slotarr->offset + (size_t) l31];
                            std_collections_add__i32(l16, l32);
                            l31 = (l31 + INT64_C(1));
                        }
                    }
                    l26 = (l26 + INT64_C(1));
                }
                l19 = (l19 + INT64_C(1));
            }
            l35 = ((vader_struct_vader_midir_Liveness_t*) l4)->f_live_in;
            l36 = l11;
            vader_array_t* _a16_slotarr = ((vader_array_t*) l35);
            VADER_ARRAY_RESOLVE_BUF(_a16_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a16_slotarr, l36)
            l37 = vader_array_ref_load_obj(_a16_slotarr->buf, _a16_slotarr->offset + (size_t) l36);
            l38 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) ((vader_struct_std_collections_MutableSet__i32_t*) l37)->f_inner)->f_ekeys;
            l39 = INT64_C(0);
            l40 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) ((vader_struct_std_collections_MutableSet__i32_t*) l37)->f_inner)->f_size;
            while ((l39 < l40)) {
                vader_array_t* _a17_slotarr = ((vader_array_t*) l38);
                VADER_ARRAY_RESOLVE_BUF(_a17_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a17_slotarr, l39)
                l41 = ((int32_t*) _a17_slotarr->buf->slots)[_a17_slotarr->offset + (size_t) l39];
                t1 = std_collections_MutableSet_std_core_Contains_contains__i32(l16, l41);
                if (t1) {
                    std_collections_add__i32(l2, l41);
                }
                l39 = (l39 + INT64_C(1));
            }
        }
        l8 = (l8 + INT64_C(1));
    }
    vader_array_t* _a18_arr = vader_array_new(15u, 0u, 7u, 288u);
    l3 = (void*) _a18_arr;
    l9 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) ((vader_struct_std_collections_MutableSet__i32_t*) l2)->f_inner)->f_size;
    if ((INT64_C(0) < l9)) {
        l8 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) ((vader_struct_std_collections_MutableSet__i32_t*) l2)->f_inner)->f_size;
    } else {
        l8 = INT64_C(0);
    }
    vader_array_t* _a19_arr = vader_array_repeat((vader_array_t*) l3, (int64_t) l8);
    l3 = (void*) _a19_arr;
    l4 = l2;
    l5 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) ((vader_struct_std_collections_MutableSet__i32_t*) l4)->f_inner)->f_ekeys;
    l8 = INT64_C(0);
    l9 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) ((vader_struct_std_collections_MutableSet__i32_t*) l4)->f_inner)->f_size;
    vader_array_t* _pc272_hdr = (vader_array_t*) l3;
    size_t _pc272_len = _pc272_hdr->length;
    size_t _pc272_cap = (_pc272_hdr->offset == 0 && !vader_array_is_borrowed(_pc272_hdr) && _pc272_hdr->length >= _pc272_hdr->buf->length) ? _pc272_hdr->capacity : (size_t) 0;
    void* _pc272_slots = _pc272_hdr->buf->slots;
    for (;;) {
        if ((l8 < l9)) {
            vader_array_t* _a20_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a20_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a20_slotarr, l8)
            l10 = ((int32_t*) _a20_slotarr->buf->slots)[_a20_slotarr->offset + (size_t) l8];
            if (VADER_LIKELY(_pc272_len < _pc272_cap)) {
                ((int32_t*) _pc272_slots)[_pc272_len] = (int32_t) (l10);
                _pc272_len += 1;
            } else {
                _pc272_hdr->length = _pc272_len;
                if (_pc272_hdr->buf->length < _pc272_len) {
                    _pc272_hdr->buf->length = _pc272_len;
                }
                vader_array_push_i32((vader_array_t*) l3, l10);
                _pc272_hdr = (vader_array_t*) l3;
                _pc272_len = _pc272_hdr->length;
                _pc272_cap = (_pc272_hdr->offset == 0 && !vader_array_is_borrowed(_pc272_hdr) && _pc272_hdr->length >= _pc272_hdr->buf->length) ? _pc272_hdr->capacity : (size_t) 0;
                _pc272_slots = _pc272_hdr->buf->slots;
            }
            l8 = (l8 + INT64_C(1));
            continue;
        }
        _pc272_hdr->length = _pc272_len;
        if (_pc272_hdr->buf->length < _pc272_len) {
            _pc272_hdr->buf->length = _pc272_len;
        }
        break;
    }
    for (;;) {
        t2 = ((vader_array_t*) l3)->length;
        if ((t2 > INT64_C(0))) {
            t2 = ((vader_array_t*) l3)->length;
            l8 = vader_chk_sub(i64, t2, INT64_C(1));
            vader_array_t* _a21_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a21_slotarr)
            l10 = ((int32_t*) _a21_slotarr->buf->slots)[_a21_slotarr->offset + (size_t) l8];
            t2 = ((vader_array_t*) l3)->length;
            l9 = vader_chk_sub(i64, t2, INT64_C(1));
            vader_array_t* _a22_arr = vader_array_slice((vader_array_t*) l3, (int64_t) INT64_C(0), (int64_t) l9);
            l3 = (void*) _a22_arr;
            l12 = std_collections_MutableMap_std_core_Index_at__i32__Any(l1, l10);
            if (l12.tag == 0u) {
                continue;
            }
            l4 = l12.payload.obj;
            l19 = ((vader_array_t*) l4)->length;
            l20 = INT64_C(0);
            while ((l20 < l19)) {
                vader_array_t* _a23_slotarr = ((vader_array_t*) l4);
                VADER_ARRAY_RESOLVE_BUF(_a23_slotarr)
                l11 = ((int32_t*) _a23_slotarr->buf->slots)[_a23_slotarr->offset + (size_t) l20];
                t1 = std_collections_MutableSet_std_core_Contains_contains__i32(l2, l11);
                if (t1) {
                    l20 = (l20 + INT64_C(1));
                    continue;
                }
                std_collections_add__i32(l2, l11);
                vader_array_push_i32((vader_array_t*) l3, l11);
                l20 = (l20 + INT64_C(1));
            }
            continue;
        }
        break;
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_midir_compute_dominators(void* l0, void* l1) {
    int64_t l2, l9, l13, l14;
    void* l3 = NULL;
    void* l6 = NULL;
    void* l8 = NULL;
    void* l12 = NULL;
    int32_t l4, l5, l10, l11, l15, l16, l17, l18, l19;
    bool l7;
    void* t0 = NULL;
    bool t1;
    int32_t t2;
    void** gc_raw_roots[7] = { &l0, &l1, &l3, &l6, &l8, &l12, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 7u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_array_t*) ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_blocks)->length;
    vader_array_t* _a0_arr = vader_array_new(15u, 1u, 7u, 288u);
    ((int32_t*) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = (int32_t) INT32_C(-1);
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l2);
    l3 = (void*) _a1_arr;
    l4 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_entry;
    l5 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_entry;
    vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
    ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l4] = (int32_t) l5;
    l6 = vader_midir_reverse_postorder(l0);
    l7 = true;
    while (l7) {
        l7 = false;
        l8 = l6;
        l2 = ((vader_array_t*) l8)->length;
        l9 = INT64_C(0);
        while ((l9 < l2)) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l8);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            l4 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l9];
            l5 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_entry;
            t1 = vader_midir_BlockId_std_core_Equals_equals(l4, l5);
            if (t1) {
                l9 = (l9 + INT64_C(1));
                continue;
            }
            l10 = INT32_C(-1);
            l11 = l4;
            vader_array_t* _a4_slotarr = ((vader_array_t*) l1);
            VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l11)
            l12 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l11);
            l13 = ((vader_array_t*) l12)->length;
            l14 = INT64_C(0);
            while ((l14 < l13)) {
                vader_array_t* _a5_slotarr = ((vader_array_t*) l12);
                VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
                l15 = ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l14];
                l16 = l15;
                vader_array_t* _a6_slotarr = ((vader_array_t*) l3);
                VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l16)
                t2 = ((int32_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l16];
                if (t2 == INT32_C(-1)) {
                    l14 = (l14 + INT64_C(1));
                    continue;
                }
                if (l10 == INT32_C(-1)) {
                    l10 = l15;
                } else {
                    l17 = l10;
                    l10 = vader_midir_intersect_dom_tree(l15, l17, l3);
                }
                l14 = (l14 + INT64_C(1));
            }
            if (l10 != INT32_C(-1)) {
                l18 = l4;
                vader_array_t* _a7_slotarr = ((vader_array_t*) l3);
                VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l18)
                t2 = ((int32_t*) _a7_slotarr->buf->slots)[_a7_slotarr->offset + (size_t) l18];
                if (t2 != l10) {
                    l19 = l4;
                    vader_array_t* _a8_slotarr = ((vader_array_t*) l3);
                    VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l19)
                    ((int32_t*) _a8_slotarr->buf->slots)[_a8_slotarr->offset + (size_t) l19] = (int32_t) l10;
                    l7 = true;
                }
            }
            l9 = (l9 + INT64_C(1));
        }
    }
    { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_midir_compute_escaping(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l9 = NULL;
    void* l29 = NULL;
    void* l34 = NULL;
    void* l39 = NULL;
    void* l43 = NULL;
    void* l48 = NULL;
    void* l53 = NULL;
    void* l61 = NULL;
    int64_t l7, l8, l10, l11, l30, l31, l35, l36, l40, l41, l44, l45, l49, l50, l54, l55, l62, l63;
    vader_box_t l12 = vader_box_null(), l60 = vader_box_null();
    int32_t l13, l14, l15, l16, l17, l18, l19, l20, l21, l22, l23, l24, l25, l26, l27, l28, l32, l33, l37, l38, l42, l46, l47, l51, l52, l56, l57, l58, l59, l64;
    void* t0 = NULL;
    bool t1;
    int64_t t2;
    vader_box_t* gc_roots[2] = { &l12, &l60 };
    void** gc_raw_roots[16] = {
        &l0, &l1, &l2, &l3, &l4, &l5, &l6, &l9, &l29, &l34, &l39, &l43, &l48, &l53, &l61, &t0,
    };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 16u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(15u, 0u, 7u, 288u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(12u, 0u, 12u, 283u);
    l3 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(15u, 0u, 7u, 288u);
    l4 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__i32__bool_t* _a3_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
    vader_obj_header_init(_a3_obj, 381u);
    _a3_obj->f_ekeys = l2;
    _a3_obj->f_evals = l3;
    _a3_obj->f_index = l4;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a3_obj;
    vader_struct_std_collections_MutableSet__i32_t* _a4_obj = (vader_struct_std_collections_MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i32_t));
    vader_obj_header_init(_a4_obj, 517u);
    _a4_obj->f_inner = t0;
    l2 = (void*) _a4_obj;
    vader_array_t* _a5_arr = vader_array_new(15u, 0u, 7u, 288u);
    l3 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(21u, 0u, 0u, 296u);
    l4 = (void*) _a6_arr;
    vader_array_t* _a7_arr = vader_array_new(15u, 0u, 7u, 288u);
    l5 = (void*) _a7_arr;
    vader_struct_std_collections_MutableMap__i32__Any___t* _a8_obj = (vader_struct_std_collections_MutableMap__i32__Any___t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__Any___t));
    vader_obj_header_init(_a8_obj, 380u);
    _a8_obj->f_ekeys = l3;
    _a8_obj->f_evals = l4;
    _a8_obj->f_index = l5;
    _a8_obj->f_mask = INT64_C(0);
    _a8_obj->f_size = INT64_C(0);
    _a8_obj->f_tombs = INT64_C(0);
    l3 = (void*) _a8_obj;
    vader_array_t* _a9_arr = vader_array_new(15u, 0u, 7u, 288u);
    l4 = (void*) _a9_arr;
    vader_array_t* _a10_arr = vader_array_new(21u, 0u, 0u, 296u);
    l5 = (void*) _a10_arr;
    vader_array_t* _a11_arr = vader_array_new(15u, 0u, 7u, 288u);
    l6 = (void*) _a11_arr;
    vader_struct_std_collections_MutableMap__i32__Any___t* _a12_obj = (vader_struct_std_collections_MutableMap__i32__Any___t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__Any___t));
    vader_obj_header_init(_a12_obj, 380u);
    _a12_obj->f_ekeys = l4;
    _a12_obj->f_evals = l5;
    _a12_obj->f_index = l6;
    _a12_obj->f_mask = INT64_C(0);
    _a12_obj->f_size = INT64_C(0);
    _a12_obj->f_tombs = INT64_C(0);
    l4 = (void*) _a12_obj;
    l5 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_blocks;
    l7 = ((vader_array_t*) l5)->length;
    l8 = INT64_C(0);
    while ((l8 < l7)) {
        vader_array_t* _a13_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
        l6 = vader_array_ref_load_obj(_a13_slotarr->buf, _a13_slotarr->offset + (size_t) l8);
        l9 = ((vader_struct_vader_midir_BasicBlock_t*) l6)->f_instructions;
        l10 = ((vader_array_t*) l9)->length;
        l11 = INT64_C(0);
        while ((l11 < l10)) {
            vader_array_t* _a14_slotarr = ((vader_array_t*) l9);
            VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
            l12 = vader_array_ref_load_box(_a14_slotarr->buf, _a14_slotarr->offset + (size_t) l11);
            if (l12.tag == 1118u) {
                t0 = l12.payload.obj;
                l13 = ((vader_struct_vader_midir_InstrMove_t*) t0)->f_dst;
                t0 = l12.payload.obj;
                l14 = ((vader_struct_vader_midir_InstrMove_t*) t0)->f_src;
                vader_midir_record_alias(l3, l4, l13, l14);
            } else if (l12.tag == 1102u) {
                t0 = l12.payload.obj;
                l15 = ((vader_struct_vader_midir_InstrCast_t*) t0)->f_dst;
                t0 = l12.payload.obj;
                l16 = ((vader_struct_vader_midir_InstrCast_t*) t0)->f_value;
                vader_midir_record_alias(l3, l4, l15, l16);
            } else if ((l12.tag == 1111u || l12.tag == 1124u)) {
                l17 = VADER_UNION_FIELD(int32_t, vader_struct_vader_midir_InstrFieldSet_t, f_value, l12.payload.obj);
                std_collections_add__i32(l2, l17);
            } else if (l12.tag == 1097u) {
                t0 = l12.payload.obj;
                l18 = ((vader_struct_vader_midir_InstrArraySet_t*) t0)->f_value;
                std_collections_add__i32(l2, l18);
                t0 = l12.payload.obj;
                l19 = ((vader_struct_vader_midir_InstrArraySet_t*) t0)->f_target;
                std_collections_add__i32(l2, l19);
            } else if (l12.tag == 1096u) {
                t0 = l12.payload.obj;
                l20 = ((vader_struct_vader_midir_InstrArrayPush_t*) t0)->f_value;
                std_collections_add__i32(l2, l20);
                t0 = l12.payload.obj;
                l21 = ((vader_struct_vader_midir_InstrArrayPush_t*) t0)->f_target;
                std_collections_add__i32(l2, l21);
            } else if (l12.tag == 1098u) {
                t0 = l12.payload.obj;
                l22 = ((vader_struct_vader_midir_InstrArraySlice_t*) t0)->f_target;
                std_collections_add__i32(l2, l22);
                t0 = l12.payload.obj;
                l23 = ((vader_struct_vader_midir_InstrArraySlice_t*) t0)->f_lo;
                std_collections_add__i32(l2, l23);
                t0 = l12.payload.obj;
                l24 = ((vader_struct_vader_midir_InstrArraySlice_t*) t0)->f_hi;
                std_collections_add__i32(l2, l24);
            } else if (l12.tag == 1104u) {
                t0 = l12.payload.obj;
                l25 = ((vader_struct_vader_midir_InstrCellNew_t*) t0)->f_value;
                std_collections_add__i32(l2, l25);
            } else if (l12.tag == 1105u) {
                t0 = l12.payload.obj;
                l26 = ((vader_struct_vader_midir_InstrCellSet_t*) t0)->f_value;
                std_collections_add__i32(l2, l26);
                t0 = l12.payload.obj;
                l27 = ((vader_struct_vader_midir_InstrCellSet_t*) t0)->f_cell;
                std_collections_add__i32(l2, l27);
            } else if (l12.tag == 1115u) {
                t0 = l12.payload.obj;
                l28 = ((vader_struct_vader_midir_InstrGlobalSet_t*) t0)->f_value;
                std_collections_add__i32(l2, l28);
            } else if (l12.tag == 1100u) {
                t0 = l12.payload.obj;
                l29 = ((vader_struct_vader_midir_InstrCall_t*) t0)->f_args;
                l30 = ((vader_array_t*) l29)->length;
                l31 = INT64_C(0);
                while ((l31 < l30)) {
                    vader_array_t* _a15_slotarr = ((vader_array_t*) l29);
                    VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
                    l32 = ((int32_t*) _a15_slotarr->buf->slots)[_a15_slotarr->offset + (size_t) l31];
                    std_collections_add__i32(l2, l32);
                    l31 = (l31 + INT64_C(1));
                }
            } else if (l12.tag == 1101u) {
                t0 = l12.payload.obj;
                l33 = ((vader_struct_vader_midir_InstrCallIndirect_t*) t0)->f_callee;
                std_collections_add__i32(l2, l33);
                t0 = l12.payload.obj;
                l34 = ((vader_struct_vader_midir_InstrCallIndirect_t*) t0)->f_args;
                l35 = ((vader_array_t*) l34)->length;
                l36 = INT64_C(0);
                while ((l36 < l35)) {
                    vader_array_t* _a16_slotarr = ((vader_array_t*) l34);
                    VADER_ARRAY_RESOLVE_BUF(_a16_slotarr)
                    l37 = ((int32_t*) _a16_slotarr->buf->slots)[_a16_slotarr->offset + (size_t) l36];
                    std_collections_add__i32(l2, l37);
                    l36 = (l36 + INT64_C(1));
                }
            } else if (l12.tag == 1125u) {
                t0 = l12.payload.obj;
                l38 = ((vader_struct_vader_midir_InstrVirtualCall_t*) t0)->f_receiver;
                std_collections_add__i32(l2, l38);
                t0 = l12.payload.obj;
                l39 = ((vader_struct_vader_midir_InstrVirtualCall_t*) t0)->f_args;
                l40 = ((vader_array_t*) l39)->length;
                l41 = INT64_C(0);
                while ((l41 < l40)) {
                    vader_array_t* _a17_slotarr = ((vader_array_t*) l39);
                    VADER_ARRAY_RESOLVE_BUF(_a17_slotarr)
                    l42 = ((int32_t*) _a17_slotarr->buf->slots)[_a17_slotarr->offset + (size_t) l41];
                    std_collections_add__i32(l2, l42);
                    l41 = (l41 + INT64_C(1));
                }
            } else if (l12.tag == 1116u) {
                t0 = l12.payload.obj;
                l43 = ((vader_struct_vader_midir_InstrIntrinsic_t*) t0)->f_args;
                l44 = ((vader_array_t*) l43)->length;
                l45 = INT64_C(0);
                while ((l45 < l44)) {
                    vader_array_t* _a18_slotarr = ((vader_array_t*) l43);
                    VADER_ARRAY_RESOLVE_BUF(_a18_slotarr)
                    l46 = ((int32_t*) _a18_slotarr->buf->slots)[_a18_slotarr->offset + (size_t) l45];
                    std_collections_add__i32(l2, l46);
                    l45 = (l45 + INT64_C(1));
                }
            } else if (l12.tag == 1117u) {
                t0 = l12.payload.obj;
                l47 = ((vader_struct_vader_midir_InstrMakeClosure_t*) t0)->f_env;
                std_collections_add__i32(l2, l47);
            } else if (l12.tag == 1119u) {
                t0 = l12.payload.obj;
                l48 = ((vader_struct_vader_midir_InstrStructNew_t*) t0)->f_fields;
                l49 = ((vader_array_t*) l48)->length;
                l50 = INT64_C(0);
                while ((l50 < l49)) {
                    vader_array_t* _a19_slotarr = ((vader_array_t*) l48);
                    VADER_ARRAY_RESOLVE_BUF(_a19_slotarr)
                    l51 = ((int32_t*) _a19_slotarr->buf->slots)[_a19_slotarr->offset + (size_t) l50];
                    t0 = l12.payload.obj;
                    l52 = ((vader_struct_vader_midir_InstrStructNew_t*) t0)->f_dst;
                    vader_midir_append_alias(l3, l52, l51);
                    l50 = (l50 + INT64_C(1));
                }
            } else if (l12.tag == 1095u) {
                t0 = l12.payload.obj;
                l53 = ((vader_struct_vader_midir_InstrArrayNew_t*) t0)->f_elements;
                l54 = ((vader_array_t*) l53)->length;
                l55 = INT64_C(0);
                while ((l55 < l54)) {
                    vader_array_t* _a20_slotarr = ((vader_array_t*) l53);
                    VADER_ARRAY_RESOLVE_BUF(_a20_slotarr)
                    l56 = ((int32_t*) _a20_slotarr->buf->slots)[_a20_slotarr->offset + (size_t) l55];
                    t0 = l12.payload.obj;
                    l57 = ((vader_struct_vader_midir_InstrArrayNew_t*) t0)->f_dst;
                    vader_midir_append_alias(l3, l57, l56);
                    l55 = (l55 + INT64_C(1));
                }
            } else if ((l12.tag == 1093u || l12.tag == 1110u || l12.tag == 1123u)) {
                t1 = vader_midir_read_may_carry_ref(VADER_UNION_FIELD(vader_box_t, vader_struct_vader_midir_InstrArrayGet_t, f_type, l12.payload.obj));
                if (t1) {
                    l58 = VADER_UNION_FIELD(int32_t, vader_struct_vader_midir_InstrArrayGet_t, f_dst, l12.payload.obj);
                    l59 = VADER_UNION_FIELD(int32_t, vader_struct_vader_midir_InstrArrayGet_t, f_target, l12.payload.obj);
                    vader_midir_append_alias(l3, l58, l59);
                }
            }
            l11 = (l11 + INT64_C(1));
        }
        l60 = ((vader_struct_vader_midir_BasicBlock_t*) l6)->f_terminator;
        if (l60.tag == 1138u) {
            t0 = l60.payload.obj;
            l61 = ((vader_struct_vader_midir_TermReturn_t*) t0)->f_values;
            l62 = ((vader_array_t*) l61)->length;
            l63 = INT64_C(0);
            while ((l63 < l62)) {
                vader_array_t* _a21_slotarr = ((vader_array_t*) l61);
                VADER_ARRAY_RESOLVE_BUF(_a21_slotarr)
                l64 = ((int32_t*) _a21_slotarr->buf->slots)[_a21_slotarr->offset + (size_t) l63];
                std_collections_add__i32(l2, l64);
                l63 = (l63 + INT64_C(1));
            }
        }
        l8 = (l8 + INT64_C(1));
    }
    vader_array_t* _a22_arr = vader_array_new(15u, 0u, 7u, 288u);
    l5 = (void*) _a22_arr;
    l8 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) ((vader_struct_std_collections_MutableSet__i32_t*) l2)->f_inner)->f_size;
    if ((INT64_C(0) < l8)) {
        l7 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) ((vader_struct_std_collections_MutableSet__i32_t*) l2)->f_inner)->f_size;
    } else {
        l7 = INT64_C(0);
    }
    vader_array_t* _a23_arr = vader_array_repeat((vader_array_t*) l5, (int64_t) l7);
    l5 = (void*) _a23_arr;
    l6 = l2;
    l9 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) ((vader_struct_std_collections_MutableSet__i32_t*) l6)->f_inner)->f_ekeys;
    l7 = INT64_C(0);
    l8 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) ((vader_struct_std_collections_MutableSet__i32_t*) l6)->f_inner)->f_size;
    vader_array_t* _pc572_hdr = (vader_array_t*) l5;
    size_t _pc572_len = _pc572_hdr->length;
    size_t _pc572_cap = (_pc572_hdr->offset == 0 && !vader_array_is_borrowed(_pc572_hdr) && _pc572_hdr->length >= _pc572_hdr->buf->length) ? _pc572_hdr->capacity : (size_t) 0;
    void* _pc572_slots = _pc572_hdr->buf->slots;
    for (;;) {
        if ((l7 < l8)) {
            vader_array_t* _a24_slotarr = ((vader_array_t*) l9);
            VADER_ARRAY_RESOLVE_BUF(_a24_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a24_slotarr, l7)
            l13 = ((int32_t*) _a24_slotarr->buf->slots)[_a24_slotarr->offset + (size_t) l7];
            if (VADER_LIKELY(_pc572_len < _pc572_cap)) {
                ((int32_t*) _pc572_slots)[_pc572_len] = (int32_t) (l13);
                _pc572_len += 1;
            } else {
                _pc572_hdr->length = _pc572_len;
                if (_pc572_hdr->buf->length < _pc572_len) {
                    _pc572_hdr->buf->length = _pc572_len;
                }
                vader_array_push_i32((vader_array_t*) l5, l13);
                _pc572_hdr = (vader_array_t*) l5;
                _pc572_len = _pc572_hdr->length;
                _pc572_cap = (_pc572_hdr->offset == 0 && !vader_array_is_borrowed(_pc572_hdr) && _pc572_hdr->length >= _pc572_hdr->buf->length) ? _pc572_hdr->capacity : (size_t) 0;
                _pc572_slots = _pc572_hdr->buf->slots;
            }
            l7 = (l7 + INT64_C(1));
            continue;
        }
        _pc572_hdr->length = _pc572_len;
        if (_pc572_hdr->buf->length < _pc572_len) {
            _pc572_hdr->buf->length = _pc572_len;
        }
        break;
    }
    for (;;) {
        t2 = ((vader_array_t*) l5)->length;
        if ((t2 > INT64_C(0))) {
            t2 = ((vader_array_t*) l5)->length;
            l7 = vader_chk_sub(i64, t2, INT64_C(1));
            vader_array_t* _a25_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a25_slotarr)
            l13 = ((int32_t*) _a25_slotarr->buf->slots)[_a25_slotarr->offset + (size_t) l7];
            t2 = ((vader_array_t*) l5)->length;
            l8 = vader_chk_sub(i64, t2, INT64_C(1));
            vader_array_t* _a26_arr = vader_array_slice((vader_array_t*) l5, (int64_t) INT64_C(0), (int64_t) l8);
            l5 = (void*) _a26_arr;
            l12 = std_collections_MutableMap_std_core_Index_at__i32__Any(l3, l13);
            if (l12.tag == 0u) {
                continue;
            }
            l6 = l12.payload.obj;
            l10 = ((vader_array_t*) l6)->length;
            l11 = INT64_C(0);
            while ((l11 < l10)) {
                vader_array_t* _a27_slotarr = ((vader_array_t*) l6);
                VADER_ARRAY_RESOLVE_BUF(_a27_slotarr)
                l14 = ((int32_t*) _a27_slotarr->buf->slots)[_a27_slotarr->offset + (size_t) l11];
                t1 = std_collections_MutableSet_std_core_Contains_contains__i32(l2, l14);
                if (t1) {
                    l11 = (l11 + INT64_C(1));
                    continue;
                }
                std_collections_add__i32(l2, l14);
                vader_array_push_i32((vader_array_t*) l5, l14);
                l11 = (l11 + INT64_C(1));
            }
            continue;
        }
        break;
    }
    vader_array_t* _a28_arr = vader_array_new(15u, 0u, 7u, 288u);
    l5 = (void*) _a28_arr;
    vader_array_t* _a29_arr = vader_array_new(12u, 0u, 12u, 283u);
    l6 = (void*) _a29_arr;
    vader_array_t* _a30_arr = vader_array_new(15u, 0u, 7u, 288u);
    l9 = (void*) _a30_arr;
    vader_struct_std_collections_MutableMap__i32__bool_t* _a31_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
    vader_obj_header_init(_a31_obj, 381u);
    _a31_obj->f_ekeys = l5;
    _a31_obj->f_evals = l6;
    _a31_obj->f_index = l9;
    _a31_obj->f_mask = INT64_C(0);
    _a31_obj->f_size = INT64_C(0);
    _a31_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a31_obj;
    vader_struct_std_collections_MutableSet__i32_t* _a32_obj = (vader_struct_std_collections_MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i32_t));
    vader_obj_header_init(_a32_obj, 517u);
    _a32_obj->f_inner = t0;
    l5 = (void*) _a32_obj;
    l6 = l1;
    l9 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) ((vader_struct_std_collections_MutableSet__i32_t*) l6)->f_inner)->f_ekeys;
    l7 = INT64_C(0);
    l8 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) ((vader_struct_std_collections_MutableSet__i32_t*) l6)->f_inner)->f_size;
    while ((l7 < l8)) {
        vader_array_t* _a33_slotarr = ((vader_array_t*) l9);
        VADER_ARRAY_RESOLVE_BUF(_a33_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a33_slotarr, l7)
        l13 = ((int32_t*) _a33_slotarr->buf->slots)[_a33_slotarr->offset + (size_t) l7];
        t1 = std_collections_MutableSet_std_core_Contains_contains__i32(l2, l13);
        if (t1) {
            std_collections_add__i32(l5, l13);
        }
        l7 = (l7 + INT64_C(1));
    }
    vader_struct_vader_midir_EscapeResult_t* _a34_obj = (vader_struct_vader_midir_EscapeResult_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_EscapeResult_t));
    vader_obj_header_init(_a34_obj, 1087u);
    _a34_obj->f_escaping = l5;
    _a34_obj->f_alias_of = l3;
    _a34_obj->f_alias_from = l4;
    t0 = (void*) _a34_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_midir_compute_liveness(void* l0) {
    int64_t l1, l4, l15, l16, l21, l22, l29, l30, l32, l33;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    void* l18 = NULL;
    void* l20 = NULL;
    void* l27 = NULL;
    void* l35 = NULL;
    void* l36 = NULL;
    void* l37 = NULL;
    vader_box_t l17 = vader_box_null(), l19 = vader_box_null(), l24 = vader_box_null(), l26 = vader_box_null();
    int32_t l23, l25, l31, l34;
    bool l28;
    void* t0 = NULL;
    bool t1;
    vader_box_t* gc_roots[4] = { &l17, &l19, &l24, &l26 };
    void** gc_raw_roots[20] = {
        &l0, &l2, &l3, &l5, &l6, &l7, &l8, &l9, &l10, &l11, &l12, &l13, &l14, &l18, &l20, &l27,
        &l35, &l36, &l37, &t0,
    };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 20u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = ((vader_array_t*) ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_blocks)->length;
    vader_array_t* _a0_arr = vader_array_new(30u, 0u, 13u, 517u);
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l1);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(30u, 0u, 13u, 517u);
    t0 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l1);
    l3 = (void*) _a3_arr;
    l4 = INT64_C(0);
    while ((l4 < l1)) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_blocks);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l4)
        l5 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l4);
        vader_array_t* _a5_arr = vader_array_new(15u, 0u, 7u, 288u);
        l6 = (void*) _a5_arr;
        vader_array_t* _a6_arr = vader_array_new(12u, 0u, 12u, 283u);
        l7 = (void*) _a6_arr;
        vader_array_t* _a7_arr = vader_array_new(15u, 0u, 7u, 288u);
        l8 = (void*) _a7_arr;
        vader_struct_std_collections_MutableMap__i32__bool_t* _a8_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
        vader_obj_header_init(_a8_obj, 381u);
        _a8_obj->f_ekeys = l6;
        _a8_obj->f_evals = l7;
        _a8_obj->f_index = l8;
        _a8_obj->f_mask = INT64_C(0);
        _a8_obj->f_size = INT64_C(0);
        _a8_obj->f_tombs = INT64_C(0);
        t0 = (void*) _a8_obj;
        vader_struct_std_collections_MutableSet__i32_t* _a9_obj = (vader_struct_std_collections_MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i32_t));
        vader_obj_header_init(_a9_obj, 517u);
        _a9_obj->f_inner = t0;
        l9 = (void*) _a9_obj;
        vader_array_t* _a10_arr = vader_array_new(15u, 0u, 7u, 288u);
        l10 = (void*) _a10_arr;
        vader_array_t* _a11_arr = vader_array_new(12u, 0u, 12u, 283u);
        l11 = (void*) _a11_arr;
        vader_array_t* _a12_arr = vader_array_new(15u, 0u, 7u, 288u);
        l12 = (void*) _a12_arr;
        vader_struct_std_collections_MutableMap__i32__bool_t* _a13_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
        vader_obj_header_init(_a13_obj, 381u);
        _a13_obj->f_ekeys = l10;
        _a13_obj->f_evals = l11;
        _a13_obj->f_index = l12;
        _a13_obj->f_mask = INT64_C(0);
        _a13_obj->f_size = INT64_C(0);
        _a13_obj->f_tombs = INT64_C(0);
        t0 = (void*) _a13_obj;
        vader_struct_std_collections_MutableSet__i32_t* _a14_obj = (vader_struct_std_collections_MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i32_t));
        vader_obj_header_init(_a14_obj, 517u);
        _a14_obj->f_inner = t0;
        l13 = (void*) _a14_obj;
        l14 = ((vader_struct_vader_midir_BasicBlock_t*) l5)->f_instructions;
        l15 = ((vader_array_t*) l14)->length;
        l16 = INT64_C(0);
        while ((l16 < l15)) {
            vader_array_t* _a15_slotarr = ((vader_array_t*) l14);
            VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a15_slotarr, l16)
            l17 = vader_array_ref_load_box(_a15_slotarr->buf, _a15_slotarr->offset + (size_t) l16);
            vader_struct___lambda_env_vader_midir_8_t* _a16_obj = (vader_struct___lambda_env_vader_midir_8_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_midir_8_t));
            vader_obj_header_init(_a16_obj, 344u);
            _a16_obj->f_cap_0 = l13;
            _a16_obj->f_cap_1 = l9;
            t0 = (void*) _a16_obj;
            vader_fn_t* _a17_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
            vader_obj_header_init(_a17_closure, 261u);
            _a17_closure->code = (void*) &vader_fn_lift___lambda_vader_midir_7;
            _a17_closure->env = t0;
            l18 = (void*) _a17_closure;
            vader_midir_for_each_read_local(l17, l18);
            l19 = vader_midir_multi_dsts(l17);
            if (l19.tag == 0u) {
                l24 = vader_midir_dst_of(l17);
                if (!(l24.tag == 0u)) {
                    l25 = ((int32_t) l24.payload.i);
                    std_collections_add__i32(l13, l25);
                }
            } else {
                l20 = l19.payload.obj;
                l21 = ((vader_array_t*) l20)->length;
                l22 = INT64_C(0);
                while ((l22 < l21)) {
                    vader_array_t* _a18_slotarr = ((vader_array_t*) l20);
                    VADER_ARRAY_RESOLVE_BUF(_a18_slotarr)
                    l23 = ((int32_t*) _a18_slotarr->buf->slots)[_a18_slotarr->offset + (size_t) l22];
                    std_collections_add__i32(l13, l23);
                    l22 = (l22 + INT64_C(1));
                }
            }
            l16 = (l16 + INT64_C(1));
        }
        l26 = ((vader_struct_vader_midir_BasicBlock_t*) l5)->f_terminator;
        vader_struct___lambda_env_vader_midir_10_t* _a19_obj = (vader_struct___lambda_env_vader_midir_10_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_midir_10_t));
        vader_obj_header_init(_a19_obj, 339u);
        _a19_obj->f_cap_0 = l13;
        _a19_obj->f_cap_1 = l9;
        t0 = (void*) _a19_obj;
        vader_fn_t* _a20_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
        vader_obj_header_init(_a20_closure, 261u);
        _a20_closure->code = (void*) &vader_fn_lift___lambda_vader_midir_9;
        _a20_closure->env = t0;
        l27 = (void*) _a20_closure;
        vader_midir_for_each_read_in_terminator(l26, l27);
        vader_array_push((vader_array_t*) l2, vader_ref_box(l9));
        vader_array_push((vader_array_t*) l3, vader_ref_box(l13));
        l4 = (l4 + INT64_C(1));
    }
    vader_array_t* _a21_arr = vader_array_new(2u, 0u, 13u, 15u);
    t0 = (void*) _a21_arr;
    vader_array_t* _a22_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l1);
    l5 = (void*) _a22_arr;
    l6 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_blocks;
    l4 = ((vader_array_t*) l6)->length;
    l15 = INT64_C(0);
    while ((l15 < l4)) {
        vader_array_t* _a23_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a23_slotarr)
        t0 = vader_array_ref_load_obj(_a23_slotarr->buf, _a23_slotarr->offset + (size_t) l15);
        l7 = vader_midir_successors_of(t0);
        vader_array_push((vader_array_t*) l5, vader_ref_box(l7));
        l15 = (l15 + INT64_C(1));
    }
    l6 = (void*) &vader_fn_static___lambda_vader_midir_11;
    l6 = std_core_filled__std_collections_MutableSet_i32_(l1, l6);
    l7 = (void*) &vader_fn_static___lambda_vader_midir_12;
    l7 = std_core_filled__std_collections_MutableSet_i32_(l1, l7);
    vader_array_t* _a24_arr = vader_array_new(15u, 0u, 7u, 288u);
    l8 = (void*) _a24_arr;
    vader_array_t* _a25_arr = vader_array_new(12u, 0u, 12u, 283u);
    l9 = (void*) _a25_arr;
    vader_array_t* _a26_arr = vader_array_new(15u, 0u, 7u, 288u);
    l10 = (void*) _a26_arr;
    vader_struct_std_collections_MutableMap__i32__bool_t* _a27_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
    vader_obj_header_init(_a27_obj, 381u);
    _a27_obj->f_ekeys = l8;
    _a27_obj->f_evals = l9;
    _a27_obj->f_index = l10;
    _a27_obj->f_mask = INT64_C(0);
    _a27_obj->f_size = INT64_C(0);
    _a27_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a27_obj;
    vader_struct_std_collections_MutableSet__i32_t* _a28_obj = (vader_struct_std_collections_MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i32_t));
    vader_obj_header_init(_a28_obj, 517u);
    _a28_obj->f_inner = t0;
    l8 = (void*) _a28_obj;
    vader_array_t* _a29_arr = vader_array_new(15u, 0u, 7u, 288u);
    l9 = (void*) _a29_arr;
    vader_array_t* _a30_arr = vader_array_new(12u, 0u, 12u, 283u);
    l10 = (void*) _a30_arr;
    vader_array_t* _a31_arr = vader_array_new(15u, 0u, 7u, 288u);
    l11 = (void*) _a31_arr;
    vader_struct_std_collections_MutableMap__i32__bool_t* _a32_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
    vader_obj_header_init(_a32_obj, 381u);
    _a32_obj->f_ekeys = l9;
    _a32_obj->f_evals = l10;
    _a32_obj->f_index = l11;
    _a32_obj->f_mask = INT64_C(0);
    _a32_obj->f_size = INT64_C(0);
    _a32_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a32_obj;
    vader_struct_std_collections_MutableSet__i32_t* _a33_obj = (vader_struct_std_collections_MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i32_t));
    vader_obj_header_init(_a33_obj, 517u);
    _a33_obj->f_inner = t0;
    l9 = (void*) _a33_obj;
    l28 = true;
    while (l28) {
        l28 = false;
        l4 = l1;
        while ((l4 > INT64_C(0))) {
            l4 = vader_chk_sub(i64, l4, INT64_C(1));
            std_collections_clear__vader_midir_LocalId(l8);
            vader_array_t* _a34_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a34_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a34_slotarr, l4)
            l10 = vader_array_ref_load_obj(_a34_slotarr->buf, _a34_slotarr->offset + (size_t) l4);
            l15 = ((vader_array_t*) l10)->length;
            l16 = INT64_C(0);
            while ((l16 < l15)) {
                vader_array_t* _a35_slotarr = ((vader_array_t*) l10);
                VADER_ARRAY_RESOLVE_BUF(_a35_slotarr)
                l23 = ((int32_t*) _a35_slotarr->buf->slots)[_a35_slotarr->offset + (size_t) l16];
                vader_array_t* _a36_slotarr = ((vader_array_t*) l6);
                VADER_ARRAY_RESOLVE_BUF(_a36_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a36_slotarr, l23)
                l11 = vader_array_ref_load_obj(_a36_slotarr->buf, _a36_slotarr->offset + (size_t) l23);
                l12 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) ((vader_struct_std_collections_MutableSet__i32_t*) l11)->f_inner)->f_ekeys;
                l21 = INT64_C(0);
                l22 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) ((vader_struct_std_collections_MutableSet__i32_t*) l11)->f_inner)->f_size;
                while ((l21 < l22)) {
                    vader_array_t* _a37_slotarr = ((vader_array_t*) l12);
                    VADER_ARRAY_RESOLVE_BUF(_a37_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a37_slotarr, l21)
                    l25 = ((int32_t*) _a37_slotarr->buf->slots)[_a37_slotarr->offset + (size_t) l21];
                    std_collections_add__i32(l8, l25);
                    l21 = (l21 + INT64_C(1));
                }
                l16 = (l16 + INT64_C(1));
            }
            std_collections_clear__vader_midir_LocalId(l9);
            vader_array_t* _a38_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a38_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a38_slotarr, l4)
            l13 = vader_array_ref_load_obj(_a38_slotarr->buf, _a38_slotarr->offset + (size_t) l4);
            l14 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) ((vader_struct_std_collections_MutableSet__i32_t*) l13)->f_inner)->f_ekeys;
            l29 = INT64_C(0);
            l30 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) ((vader_struct_std_collections_MutableSet__i32_t*) l13)->f_inner)->f_size;
            while ((l29 < l30)) {
                vader_array_t* _a39_slotarr = ((vader_array_t*) l14);
                VADER_ARRAY_RESOLVE_BUF(_a39_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a39_slotarr, l29)
                l31 = ((int32_t*) _a39_slotarr->buf->slots)[_a39_slotarr->offset + (size_t) l29];
                std_collections_add__i32(l9, l31);
                l29 = (l29 + INT64_C(1));
            }
            l18 = l8;
            l20 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) ((vader_struct_std_collections_MutableSet__i32_t*) l18)->f_inner)->f_ekeys;
            l32 = INT64_C(0);
            l33 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) ((vader_struct_std_collections_MutableSet__i32_t*) l18)->f_inner)->f_size;
            while ((l32 < l33)) {
                vader_array_t* _a40_slotarr = ((vader_array_t*) l20);
                VADER_ARRAY_RESOLVE_BUF(_a40_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a40_slotarr, l32)
                l34 = ((int32_t*) _a40_slotarr->buf->slots)[_a40_slotarr->offset + (size_t) l32];
                vader_array_t* _a41_slotarr = ((vader_array_t*) l3);
                VADER_ARRAY_RESOLVE_BUF(_a41_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a41_slotarr, l4)
                t0 = vader_array_ref_load_obj(_a41_slotarr->buf, _a41_slotarr->offset + (size_t) l4);
                t1 = std_collections_MutableSet_std_core_Contains_contains__i32(t0, l34);
                if (!(t1)) {
                    std_collections_add__i32(l9, l34);
                }
                l32 = (l32 + INT64_C(1));
            }
            vader_array_t* _a42_slotarr = ((vader_array_t*) l7);
            VADER_ARRAY_RESOLVE_BUF(_a42_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a42_slotarr, l4)
            l27 = vader_array_ref_load_obj(_a42_slotarr->buf, _a42_slotarr->offset + (size_t) l4);
            t1 = vader_midir_sets_equal(l8, l27);
            if (!(t1)) {
                vader_array_t* _a43_slotarr = ((vader_array_t*) l7);
                VADER_ARRAY_RESOLVE_BUF(_a43_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a43_slotarr, l4)
                l35 = vader_array_ref_load_obj(_a43_slotarr->buf, _a43_slotarr->offset + (size_t) l4);
                VADER_ARRAY_CHECK_INDEX(_a43_slotarr, l4)
                vader_array_ref_store(_a43_slotarr->buf, _a43_slotarr->offset + (size_t) l4, l8);
                VADER_WRITE_BARRIER(_a43_slotarr->buf);
                l8 = l35;
                l28 = true;
            }
            vader_array_t* _a44_slotarr = ((vader_array_t*) l6);
            VADER_ARRAY_RESOLVE_BUF(_a44_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a44_slotarr, l4)
            l36 = vader_array_ref_load_obj(_a44_slotarr->buf, _a44_slotarr->offset + (size_t) l4);
            t1 = vader_midir_sets_equal(l9, l36);
            if (t1) {
                continue;
            }
            vader_array_t* _a45_slotarr = ((vader_array_t*) l6);
            VADER_ARRAY_RESOLVE_BUF(_a45_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a45_slotarr, l4)
            l37 = vader_array_ref_load_obj(_a45_slotarr->buf, _a45_slotarr->offset + (size_t) l4);
            VADER_ARRAY_CHECK_INDEX(_a45_slotarr, l4)
            vader_array_ref_store(_a45_slotarr->buf, _a45_slotarr->offset + (size_t) l4, l9);
            VADER_WRITE_BARRIER(_a45_slotarr->buf);
            l9 = l37;
            l28 = true;
        }
    }
    vader_struct_vader_midir_Liveness_t* _a46_obj = (vader_struct_vader_midir_Liveness_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_Liveness_t));
    vader_obj_header_init(_a46_obj, 1126u);
    _a46_obj->f_live_in = l6;
    _a46_obj->f_live_out = l7;
    t0 = (void*) _a46_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir_computed_type(vader_box_t l0, vader_box_t l1) {
    void* l2;
    vader_box_t l3;
    bool t0;
    l3 = l1;
    if (l3.tag == 0u) {
        return l0;
    }
    l2 = l3.payload.obj;
    t0 = vader_types_is_stored_as_integer(l0);
    if (!(t0)) {
        return l0;
    }
    return vader_ref_box(l2);
}

static vader_box_t vader_midir_const_accessor(void* l0, void* l1) {
    void* l2;
    int32_t l3;
    vader_box_t l4;
    bool t0;
    void* t1;
    vader_box_t t2;
    t0 = ((vader_struct_vader_lower_LoweredIdent_t*) l1)->f_fresh;
    if (t0) {
        l2 = ((vader_struct_vader_midir_ProjectCtx_t*) ((vader_struct_vader_midir_FnCtx_t*) l0)->f_project)->f_const_fresh_wrap;
        l3 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_lower_LoweredIdent_t*) l1)->f_symbol)->f_id;
        l4 = std_collections_MutableMap_std_core_Index_at__i32__Any(l2, l3);
        if (!(l4.tag == 0u)) {
            t1 = l4.payload.obj;
            return vader_ref_box(t1);
        }
    }
    l2 = ((vader_struct_vader_midir_ProjectCtx_t*) ((vader_struct_vader_midir_FnCtx_t*) l0)->f_project)->f_const_fn_wrap;
    l3 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_lower_LoweredIdent_t*) l1)->f_symbol)->f_id;
    t2 = std_collections_MutableMap_std_core_Index_at__i32__Any(l2, l3);
    return t2;
}

static void* vader_midir_convert_data_pool(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    void* l18 = NULL;
    int64_t l3, l4, l9, l10, l15, l16;
    vader_box_t l5 = vader_box_null(), l17 = vader_box_null();
    uint64_t l11;
    void* t0 = NULL;
    int64_t t1, t2;
    vader_string_t t3 = 0;
    uint8_t t4;
    vader_box_t t5 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l5, &l17, &t5 };
    void** gc_raw_roots[11] = { &l0, &l1, &l2, &l6, &l7, &l8, &l12, &l13, &l14, &l18, &t0 };
    vader_string_t* gc_atom_roots[1] = { &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 11u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(225u, 0u, 13u, 1550u);
    l1 = (void*) _a0_arr;
    l2 = l0;
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l5 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
        if (l5.tag == 1064u) {
            t0 = l5.payload.obj;
            vader_struct_vader_bytecode_BcStrData_t* _a2_obj = (vader_struct_vader_bytecode_BcStrData_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcStrData_t));
            vader_obj_header_init(_a2_obj, 651u);
            _a2_obj->f_values = ((vader_struct_vader_lower_StrDataPoolEntry_t*) t0)->f_values;
            l6 = (void*) _a2_obj;
            vader_array_push((vader_array_t*) l1, vader_ref_box(l6));
        } else if (l5.tag == 1058u) {
            vader_array_t* _a3_arr = vader_array_new(20u, 0u, 4u, 293u);
            l7 = (void*) _a3_arr;
            t0 = l5.payload.obj;
            l8 = ((vader_struct_vader_lower_PrimDataPoolEntry_t*) t0)->f_items;
            l9 = ((vader_array_t*) l8)->length;
            l10 = INT64_C(0);
            vader_array_t* _pc41_hdr = (vader_array_t*) l7;
            size_t _pc41_len = _pc41_hdr->length;
            size_t _pc41_cap = (_pc41_hdr->offset == 0 && !vader_array_is_borrowed(_pc41_hdr) && _pc41_hdr->length >= _pc41_hdr->buf->length) ? _pc41_hdr->capacity : (size_t) 0;
            void* _pc41_slots = _pc41_hdr->buf->slots;
            for (;;) {
                if ((l10 < l9)) {
                    vader_array_t* _a4_slotarr = ((vader_array_t*) l8);
                    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                    t1 = ((int64_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l10];
                    t2 = t1;
                    l11 = (uint64_t) (int64_t) t2;
                    if (VADER_LIKELY(_pc41_len < _pc41_cap)) {
                        ((int64_t*) _pc41_slots)[_pc41_len] = (int64_t) ((int64_t) (uint64_t) l11);
                        _pc41_len += 1;
                    } else {
                        _pc41_hdr->length = _pc41_len;
                        if (_pc41_hdr->buf->length < _pc41_len) {
                            _pc41_hdr->buf->length = _pc41_len;
                        }
                        vader_array_push_i64((vader_array_t*) l7, (int64_t) (uint64_t) l11);
                        _pc41_hdr = (vader_array_t*) l7;
                        _pc41_len = _pc41_hdr->length;
                        _pc41_cap = (_pc41_hdr->offset == 0 && !vader_array_is_borrowed(_pc41_hdr) && _pc41_hdr->length >= _pc41_hdr->buf->length) ? _pc41_hdr->capacity : (size_t) 0;
                        _pc41_slots = _pc41_hdr->buf->slots;
                    }
                    l10 = (l10 + INT64_C(1));
                    continue;
                }
                _pc41_hdr->length = _pc41_len;
                if (_pc41_hdr->buf->length < _pc41_len) {
                    _pc41_hdr->buf->length = _pc41_len;
                }
                break;
            }
            t0 = l5.payload.obj;
            t3 = ((vader_struct_vader_lower_PrimDataPoolEntry_t*) t0)->f_element_type_name;
            t4 = vader_bytecode_array_kind_from_name(t3);
            vader_struct_vader_bytecode_BcPrimData_t* _a5_obj = (vader_struct_vader_bytecode_BcPrimData_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcPrimData_t));
            vader_obj_header_init(_a5_obj, 647u);
            _a5_obj->f_kind = t4;
            _a5_obj->f_items = l7;
            l12 = (void*) _a5_obj;
            vader_array_push((vader_array_t*) l1, vader_ref_box(l12));
        } else {
            if (!(l5.tag == 949u)) {
                vader_unreachable("non-exhaustive match (T3013 should have caught this)");
            }
            vader_array_t* _a6_arr = vader_array_new(227u, 0u, 13u, 1561u);
            l13 = (void*) _a6_arr;
            t0 = l5.payload.obj;
            l14 = ((vader_struct_vader_lower_LoweredArrayLit_t*) ((vader_struct_vader_lower_AggregateDataPoolEntry_t*) t0)->f_literal)->f_elements;
            l15 = ((vader_array_t*) l14)->length;
            l16 = INT64_C(0);
            while ((l16 < l15)) {
                vader_array_t* _a7_slotarr = ((vader_array_t*) l14);
                VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
                t5 = vader_array_ref_load_box(_a7_slotarr->buf, _a7_slotarr->offset + (size_t) l16);
                l17 = vader_midir_lowered_to_bc_value(t5);
                vader_array_push((vader_array_t*) l13, l17);
                l16 = (l16 + INT64_C(1));
            }
            t0 = l5.payload.obj;
            t3 = ((vader_struct_vader_lower_AggregateDataPoolEntry_t*) t0)->f_element_type_name;
            vader_struct_vader_bytecode_BcAggregateData_t* _a8_obj = (vader_struct_vader_bytecode_BcAggregateData_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcAggregateData_t));
            vader_obj_header_init(_a8_obj, 637u);
            _a8_obj->f_element_type_name = t3;
            _a8_obj->f_elements = l13;
            l18 = (void*) _a8_obj;
            vader_array_push((vader_array_t*) l1, vader_ref_box(l18));
        }
        l4 = (l4 + INT64_C(1));
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_midir_convert_eligible(uint8_t l0) {
    bool l1;
    if (l0 == INT32_C(0)) {
        l1 = true;
        return l1;
    }
    if (l0 == INT32_C(1)) {
        l1 = true;
    } else if (l0 == INT32_C(2)) {
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
    } else if (l0 == INT32_C(8)) {
        l1 = true;
    } else if (l0 == INT32_C(9)) {
        l1 = true;
    } else if (l0 == INT32_C(10)) {
        l1 = false;
    } else if (l0 == INT32_C(11)) {
        l1 = true;
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

static vader_box_t vader_midir_convert_function(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    void* l18 = NULL;
    void* l21 = NULL;
    int64_t l4, l9;
    int32_t l10, l15, l16, l20;
    vader_string_t l11 = 0;
    vader_string_t l17 = 0;
    vader_box_t l12 = vader_box_null(), l19 = vader_box_null();
    bool l22, l23;
    vader_box_t t0 = vader_box_null();
    int64_t t1;
    int32_t t2;
    void* t3 = NULL;
    vader_box_t* gc_roots[3] = { &l12, &l19, &t0 };
    void** gc_raw_roots[13] = {
        &l0, &l1, &l2, &l3, &l5, &l6, &l7, &l8, &l13, &l14, &l18, &l21, &t3,
    };
    vader_string_t* gc_atom_roots[2] = { &l11, &l17 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 13u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (((vader_struct_vader_lower_LoweredFnDecl_t*) l0)->f_body.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    t0 = ((vader_struct_vader_lower_LoweredFnDecl_t*) l0)->f_body;
    l2 = t0.payload.obj;
    vader_array_t* _a0_arr = vader_array_new(140u, 0u, 13u, 1074u);
    l3 = (void*) _a0_arr;
    l4 = ((vader_array_t*) ((vader_struct_vader_lower_LoweredFnDecl_t*) l0)->f_params)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l3, (int64_t) l4);
    l3 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(138u, 0u, 13u, 1072u);
    l5 = (void*) _a2_arr;
    l4 = ((vader_array_t*) ((vader_struct_vader_lower_LoweredFnDecl_t*) l0)->f_params)->length;
    vader_array_t* _a3_arr = vader_array_repeat((vader_array_t*) l5, (int64_t) l4);
    l5 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_new(15u, 0u, 7u, 288u);
    l6 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_new(15u, 0u, 7u, 288u);
    l7 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(15u, 0u, 7u, 288u);
    l8 = (void*) _a6_arr;
    vader_struct_std_collections_MutableMap__i32__i32_t* _a7_obj = (vader_struct_std_collections_MutableMap__i32__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__i32_t));
    vader_obj_header_init(_a7_obj, 382u);
    _a7_obj->f_ekeys = l6;
    _a7_obj->f_evals = l7;
    _a7_obj->f_index = l8;
    _a7_obj->f_mask = INT64_C(0);
    _a7_obj->f_size = INT64_C(0);
    _a7_obj->f_tombs = INT64_C(0);
    l6 = (void*) _a7_obj;
    l7 = ((vader_struct_vader_lower_LoweredFnDecl_t*) l0)->f_params;
    l4 = ((vader_array_t*) l7)->length;
    l9 = INT64_C(0);
    while ((l9 < l4)) {
        vader_array_t* _a8_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
        l8 = vader_array_ref_load_obj(_a8_slotarr->buf, _a8_slotarr->offset + (size_t) l9);
        t1 = ((vader_array_t*) l5)->length;
        l10 = ((int32_t) (int64_t) t1);
        l11 = ((vader_struct_vader_lower_LoweredParam_t*) l8)->f_name;
        l12 = ((vader_struct_vader_lower_LoweredParam_t*) l8)->f_type;
        l13 = ((vader_struct_vader_lower_LoweredParam_t*) l8)->f_symbol;
        vader_struct_vader_midir_CFGLocal_t* _a9_obj = (vader_struct_vader_midir_CFGLocal_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_CFGLocal_t));
        vader_obj_header_init(_a9_obj, 1072u);
        _a9_obj->f_name = l11;
        _a9_obj->f_type = l12;
        _a9_obj->f_symbol = vader_ref_box(l13);
        l14 = (void*) _a9_obj;
        vader_array_push((vader_array_t*) l5, vader_ref_box(l14));
        l15 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_lower_LoweredParam_t*) l8)->f_symbol)->f_id;
        l16 = l10;
        std_collections_MutableMap_std_core_IndexSet_set_at__i32__i32(l6, l15, l16);
        l17 = ((vader_struct_vader_lower_LoweredParam_t*) l8)->f_name;
        l18 = ((vader_struct_vader_lower_LoweredParam_t*) l8)->f_symbol;
        l19 = ((vader_struct_vader_lower_LoweredParam_t*) l8)->f_type;
        l20 = l10;
        vader_struct_vader_midir_CFGParam_t* _a10_obj = (vader_struct_vader_midir_CFGParam_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_CFGParam_t));
        vader_obj_header_init(_a10_obj, 1074u);
        _a10_obj->f_name = l17;
        _a10_obj->f_symbol = l18;
        _a10_obj->f_type = l19;
        _a10_obj->f_local = l20;
        l21 = (void*) _a10_obj;
        vader_array_push((vader_array_t*) l3, vader_ref_box(l21));
        l9 = (l9 + INT64_C(1));
    }
    l11 = ((vader_struct_vader_lower_LoweredFnDecl_t*) l0)->f_mangled;
    l7 = ((vader_struct_vader_lower_LoweredFnDecl_t*) l0)->f_origin;
    l12 = ((vader_struct_vader_lower_LoweredFnDecl_t*) l0)->f_return_type;
    vader_array_t* _a11_arr = vader_array_new(145u, 0u, 13u, 1128u);
    l8 = (void*) _a11_arr;
    vader_array_t* _a12_arr = vader_array_new(144u, 0u, 13u, 1127u);
    l13 = (void*) _a12_arr;
    vader_struct_vader_midir_FnCtx_t* _a13_obj = (vader_struct_vader_midir_FnCtx_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_FnCtx_t));
    vader_obj_header_init(_a13_obj, 1090u);
    _a13_obj->f_project = l1;
    _a13_obj->f_mangled = l11;
    _a13_obj->f_origin = l7;
    _a13_obj->f_return_type = l12;
    _a13_obj->f_params = l3;
    _a13_obj->f_locals = l5;
    _a13_obj->f_local_by_sym_id = l6;
    _a13_obj->f_blocks = l8;
    _a13_obj->f_loop_stack = l13;
    _a13_obj->f_current = vader_box_obj(0u, NULL);
    l5 = (void*) _a13_obj;
    l6 = ((vader_struct_vader_lower_LoweredBlock_t*) l2)->f_span;
    l10 = vader_midir_new_block(l5, l6);
    ((vader_struct_vader_midir_FnCtx_t*) l5)->f_current = vader_box_i32(288u, l10);
    VADER_WRITE_BARRIER((vader_struct_vader_midir_FnCtx_t*) l5);
    l12 = ((vader_struct_vader_lower_LoweredFnDecl_t*) l0)->f_return_type;
    l12 = vader_midir_build_block_value(l5, l2, l12);
    if (!(((vader_struct_vader_midir_FnCtx_t*) l5)->f_current.tag == 0u)) {
        l6 = ((vader_struct_vader_midir_FnCtx_t*) l5)->f_blocks;
        l4 = ((int64_t) ((vader_struct_vader_midir_FnCtx_t*) l5)->f_current.payload.i);
        vader_array_t* _a14_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a14_slotarr, l4)
        l6 = vader_array_ref_load_obj(_a14_slotarr->buf, _a14_slotarr->offset + (size_t) l4);
        if (((vader_struct_vader_midir_MutableBlock_t*) l6)->f_terminator.tag == 0u) {
            l2 = ((vader_struct_vader_lower_LoweredBlock_t*) l2)->f_span;
            if (l12.tag == 0u) {
                vader_array_t* _a15_arr = vader_array_new(15u, 0u, 7u, 288u);
                l7 = (void*) _a15_arr;
            } else {
                t2 = ((int32_t) l12.payload.i);
                vader_array_t* _a16_arr = vader_array_new(15u, 1u, 7u, 288u);
                ((int32_t*) _a16_arr->buf->slots)[_a16_arr->offset + 0u] = (int32_t) t2;
                l7 = (void*) _a16_arr;
            }
            vader_struct_vader_midir_TermReturn_t* _a17_obj = (vader_struct_vader_midir_TermReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_TermReturn_t));
            vader_obj_header_init(_a17_obj, 1138u);
            _a17_obj->f_span = l2;
            _a17_obj->f_values = l7;
            l2 = (void*) _a17_obj;
            ((vader_struct_vader_midir_MutableBlock_t*) l6)->f_terminator = vader_ref_box(l2);
            VADER_WRITE_BARRIER((vader_struct_vader_midir_MutableBlock_t*) l6);
        }
    }
    l2 = vader_midir_fn_metadata(l0);
    vader_array_t* _a18_arr = vader_array_new(135u, 0u, 13u, 1069u);
    l6 = (void*) _a18_arr;
    l4 = ((vader_array_t*) ((vader_struct_vader_midir_FnCtx_t*) l5)->f_blocks)->length;
    vader_array_t* _a19_arr = vader_array_repeat((vader_array_t*) l6, (int64_t) l4);
    l6 = (void*) _a19_arr;
    l7 = ((vader_struct_vader_midir_FnCtx_t*) l5)->f_blocks;
    l4 = ((vader_array_t*) l7)->length;
    l9 = INT64_C(0);
    while ((l9 < l4)) {
        vader_array_t* _a20_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a20_slotarr)
        t3 = vader_array_ref_load_obj(_a20_slotarr->buf, _a20_slotarr->offset + (size_t) l9);
        l8 = vader_midir_freeze_block(t3);
        vader_array_push((vader_array_t*) l6, vader_ref_box(l8));
        l9 = (l9 + INT64_C(1));
    }
    l11 = ((vader_struct_vader_lower_LoweredFnDecl_t*) l0)->f_mangled;
    l12 = ((vader_struct_vader_lower_LoweredFnDecl_t*) l0)->f_return_type;
    l5 = ((vader_struct_vader_midir_FnCtx_t*) l5)->f_locals;
    l7 = ((vader_struct_vader_lower_LoweredFnDecl_t*) l0)->f_origin;
    l17 = ((vader_struct_vader_midir_FnMetadata_t*) l2)->f_extern_name;
    l22 = ((vader_struct_vader_midir_FnMetadata_t*) l2)->f_is_extern;
    l23 = ((vader_struct_vader_midir_FnMetadata_t*) l2)->f_is_exported;
    vader_array_t* _a21_arr = vader_array_new(244u, 0u, 13u, 1804u);
    l2 = (void*) _a21_arr;
    vader_struct_vader_midir_CFGFunction_t* _a22_obj = (vader_struct_vader_midir_CFGFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_CFGFunction_t));
    vader_obj_header_init(_a22_obj, 1071u);
    _a22_obj->f_mangled = l11;
    _a22_obj->f_params = l3;
    _a22_obj->f_return_type = l12;
    _a22_obj->f_locals = l5;
    _a22_obj->f_blocks = l6;
    _a22_obj->f_entry = l10;
    _a22_obj->f_origin = l7;
    _a22_obj->f_extern_name = l17;
    _a22_obj->f_is_extern = l22;
    _a22_obj->f_is_exported = l23;
    _a22_obj->f_scalarised_results = l2;
    t3 = (void*) _a22_obj;
    { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_midir_copies_cheaply(void* l0) {
    bool t0;
    int64_t t1;
    t0 = vader_midir_ends_function(((vader_struct_vader_midir_BasicBlock_t*) l0)->f_terminator);
    if (t0) {
        t1 = ((vader_array_t*) ((vader_struct_vader_midir_BasicBlock_t*) l0)->f_instructions)->length;
        return (t1 <= INT64_C(2));
    }
    return false;
}

static void* vader_midir_count_uses(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    int64_t l4, l5, l8, l9;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[7] = { &l0, &l1, &l2, &l3, &l6, &l7, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 7u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(15u, 0u, 7u, 288u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(15u, 0u, 7u, 288u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(15u, 0u, 7u, 288u);
    l3 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__i32__i32_t* _a3_obj = (vader_struct_std_collections_MutableMap__i32__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__i32_t));
    vader_obj_header_init(_a3_obj, 382u);
    _a3_obj->f_ekeys = l1;
    _a3_obj->f_evals = l2;
    _a3_obj->f_index = l3;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    l1 = (void*) _a3_obj;
    vader_struct___lambda_env_vader_midir_3_t* _a4_obj = (vader_struct___lambda_env_vader_midir_3_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_midir_3_t));
    vader_obj_header_init(_a4_obj, 342u);
    _a4_obj->f_cap_0 = l1;
    t0 = (void*) _a4_obj;
    vader_fn_t* _a5_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
    vader_obj_header_init(_a5_closure, 261u);
    _a5_closure->code = (void*) &vader_fn_lift___lambda_vader_midir_2;
    _a5_closure->env = t0;
    l2 = (void*) _a5_closure;
    l3 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_blocks;
    l4 = ((vader_array_t*) l3)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a6_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l5)
        l6 = vader_array_ref_load_obj(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l5);
        l7 = ((vader_struct_vader_midir_BasicBlock_t*) l6)->f_instructions;
        l8 = ((vader_array_t*) l7)->length;
        l9 = INT64_C(0);
        while ((l9 < l8)) {
            vader_array_t* _a7_slotarr = ((vader_array_t*) l7);
            VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l9)
            t1 = vader_array_ref_load_box(_a7_slotarr->buf, _a7_slotarr->offset + (size_t) l9);
            vader_midir_for_each_read_local(t1, l2);
            l9 = (l9 + INT64_C(1));
        }
        vader_midir_for_each_read_in_terminator(((vader_struct_vader_midir_BasicBlock_t*) l6)->f_terminator, l2);
        l5 = (l5 + INT64_C(1));
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir_debug_pos_of_span(void* l0) {
    vader_string_t l1 = 0;
    int32_t l2, l3;
    bool t0;
    void* t1 = NULL;
    void** gc_raw_roots[2] = { &l0, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = toolchain_span_has_source_position(l0);
    if (!(t0)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l1 = ((vader_struct_toolchain_span_Position_t*) ((vader_struct_toolchain_span_Span_t*) l0)->f_start)->f_file;
    l2 = ((vader_struct_toolchain_span_Position_t*) ((vader_struct_toolchain_span_Span_t*) l0)->f_start)->f_line;
    l3 = ((vader_struct_toolchain_span_Position_t*) ((vader_struct_toolchain_span_Span_t*) l0)->f_start)->f_column;
    vader_struct_vader_bytecode_DebugPos_t* _a0_obj = (vader_struct_vader_bytecode_DebugPos_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_DebugPos_t));
    vader_obj_header_init(_a0_obj, 682u);
    _a0_obj->f_file = l1;
    _a0_obj->f_line = l2;
    _a0_obj->f_column = l3;
    t1 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static int32_t vader_midir_declare_local(void* l0, vader_string_t l1, vader_box_t l2, vader_box_t l3) {
    int32_t l4;
    void* l5 = NULL;
    void* l6 = NULL;
    int64_t t0;
    vader_box_t* gc_roots[2] = { &l2, &l3 };
    void** gc_raw_roots[3] = { &l0, &l5, &l6 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_vader_midir_FnCtx_t*) l0)->f_locals)->length;
    l4 = ((int32_t) (int64_t) t0);
    l5 = ((vader_struct_vader_midir_FnCtx_t*) l0)->f_locals;
    vader_struct_vader_midir_CFGLocal_t* _a0_obj = (vader_struct_vader_midir_CFGLocal_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_CFGLocal_t));
    vader_obj_header_init(_a0_obj, 1072u);
    _a0_obj->f_name = l1;
    _a0_obj->f_type = l2;
    _a0_obj->f_symbol = l3;
    l6 = (void*) _a0_obj;
    vader_array_push((vader_array_t*) l5, vader_ref_box(l6));
    { int32_t __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_midir_defer_or_resolve_branch(void* l0, int32_t l1, int32_t l2) {
    void* l3 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    int64_t l4, l5;
    int32_t l8;
    vader_string_t t0 = 0;
    bool t1;
    int32_t t2;
    void** gc_raw_roots[4] = { &l0, &l3, &l6, &l7 };
    vader_string_t* gc_atom_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_scopes;
    l4 = ((vader_array_t*) l3)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l6 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
        t0 = ((vader_struct_vader_midir_ScopeFrame_t*) l6)->f_kind;
        if (t0 == 2085u) {
            t1 = vader_midir_BlockId_std_core_Equals_equals(((vader_struct_vader_midir_ScopeFrame_t*) l6)->f_target_blk, l1);
            if (t1) {
                l7 = ((vader_struct_vader_bytecode_BcFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_slot)->f_jump_table;
                t2 = ((vader_struct_vader_midir_ScopeFrame_t*) l6)->f_opener_pc;
                l8 = vader_chk_add(i32, t2, INT32_C(1));
                vader_array_t* _a1_slotarr = ((vader_array_t*) l7);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l2)
                ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l2] = (int32_t) l8;
                { vader_gc_top = gc_frame.prev; return; }
            }
        }
        l5 = (l5 + INT64_C(1));
    }
    l3 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_pending;
    vader_struct_vader_midir_PendingBranch_t* _a2_obj = (vader_struct_vader_midir_PendingBranch_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_PendingBranch_t));
    vader_obj_header_init(_a2_obj, 1130u);
    _a2_obj->f_branch_pc = l2;
    _a2_obj->f_target_blk = l1;
    l6 = (void*) _a2_obj;
    vader_array_push((vader_array_t*) l3, vader_ref_box(l6));
    { vader_gc_top = gc_frame.prev; return; }
}

static int32_t vader_midir_destination(void* l0, int32_t l1) {
    int32_t l2, l5, l6;
    int64_t l3, l4;
    int32_t t0;
    l2 = l1;
    l3 = INT64_C(0);
    l4 = ((vader_array_t*) l0)->length;
    while ((l3 < l4)) {
        l5 = l2;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
        t0 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l5];
        if ((t0 < INT32_C(0))) {
            return l2;
        }
        l6 = l2;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l6)
        l2 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l6];
        l3 = (l3 + INT64_C(1));
    }
    return l1;
}

static bool vader_midir_dominates(void* l0, int32_t l1, int32_t l2) {
    int32_t l3, l4, l5;
    bool t0;
    l3 = l2;
    for (;;) {
        t0 = vader_midir_BlockId_std_core_Equals_equals(l3, INT32_C(-1));
        if (!(t0)) {
            t0 = vader_midir_BlockId_std_core_Equals_equals(l3, l1);
            if (t0) {
                return true;
            }
            l4 = l3;
            vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
            l5 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l4];
            t0 = vader_midir_BlockId_std_core_Equals_equals(l5, l3);
            if (t0) {
                t0 = vader_midir_BlockId_std_core_Equals_equals(l3, l1);
                return t0;
            }
            l3 = l5;
            continue;
        }
        break;
    }
    return false;
}

static void vader_midir_drain_pending(void* l0, int32_t l1, bool l2, int32_t l3, int32_t l4) {
    int32_t l5, l12;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    int64_t l8, l9;
    bool t0;
    void** gc_raw_roots[5] = { &l0, &l6, &l7, &l10, &l11 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l2) {
        l5 = vader_chk_add(i32, l3, INT32_C(1));
    } else {
        l5 = vader_chk_add(i32, l4, INT32_C(1));
    }
    vader_array_t* _a0_arr = vader_array_new(146u, 0u, 13u, 1130u);
    l6 = (void*) _a0_arr;
    l7 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_pending;
    l8 = ((vader_array_t*) l7)->length;
    l9 = INT64_C(0);
    while ((l9 < l8)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l10 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l9);
        t0 = vader_midir_BlockId_std_core_Equals_equals(((vader_struct_vader_midir_PendingBranch_t*) l10)->f_target_blk, l1);
        if (t0) {
            l11 = ((vader_struct_vader_bytecode_BcFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_slot)->f_jump_table;
            l12 = ((vader_struct_vader_midir_PendingBranch_t*) l10)->f_branch_pc;
            vader_array_t* _a2_slotarr = ((vader_array_t*) l11);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l12)
            ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l12] = (int32_t) l5;
        } else {
            vader_array_push((vader_array_t*) l6, vader_ref_box(l10));
        }
        l9 = (l9 + INT64_C(1));
    }
    ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_pending = l6;
    VADER_WRITE_BARRIER((vader_struct_vader_midir_FnEmitCfg_t*) l0);
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_midir_dst_of(vader_box_t l0) {
    void* t0;
    vader_box_t t1;
    if (l0.tag == 1106u) {
        t0 = l0.payload.obj;
        return vader_box_i32(288u, ((vader_struct_vader_midir_InstrConst_t*) t0)->f_dst);
    }
    if (l0.tag == 1118u) {
        t0 = l0.payload.obj;
        return vader_box_i32(288u, ((vader_struct_vader_midir_InstrMove_t*) t0)->f_dst);
    }
    if (l0.tag == 1099u) {
        t0 = l0.payload.obj;
        return vader_box_i32(288u, ((vader_struct_vader_midir_InstrBinOp_t*) t0)->f_dst);
    }
    if (l0.tag == 1122u) {
        t0 = l0.payload.obj;
        return vader_box_i32(288u, ((vader_struct_vader_midir_InstrUnOp_t*) t0)->f_dst);
    }
    if (l0.tag == 1110u) {
        t0 = l0.payload.obj;
        return vader_box_i32(288u, ((vader_struct_vader_midir_InstrFieldGet_t*) t0)->f_dst);
    }
    if (l0.tag == 1123u) {
        t0 = l0.payload.obj;
        return vader_box_i32(288u, ((vader_struct_vader_midir_InstrUnionFieldGet_t*) t0)->f_dst);
    }
    if (l0.tag == 1093u) {
        t0 = l0.payload.obj;
        return vader_box_i32(288u, ((vader_struct_vader_midir_InstrArrayGet_t*) t0)->f_dst);
    }
    if (l0.tag == 1094u) {
        t0 = l0.payload.obj;
        return vader_box_i32(288u, ((vader_struct_vader_midir_InstrArrayLen_t*) t0)->f_dst);
    }
    if (l0.tag == 1098u) {
        t0 = l0.payload.obj;
        return vader_box_i32(288u, ((vader_struct_vader_midir_InstrArraySlice_t*) t0)->f_dst);
    }
    if (l0.tag == 1119u) {
        t0 = l0.payload.obj;
        return vader_box_i32(288u, ((vader_struct_vader_midir_InstrStructNew_t*) t0)->f_dst);
    }
    if (l0.tag == 1095u) {
        t0 = l0.payload.obj;
        return vader_box_i32(288u, ((vader_struct_vader_midir_InstrArrayNew_t*) t0)->f_dst);
    }
    if (l0.tag == 1120u) {
        t0 = l0.payload.obj;
        return vader_box_i32(288u, ((vader_struct_vader_midir_InstrTypeCheck_t*) t0)->f_dst);
    }
    if (l0.tag == 1121u) {
        t0 = l0.payload.obj;
        return vader_box_i32(288u, ((vader_struct_vader_midir_InstrTypeConst_t*) t0)->f_dst);
    }
    if (l0.tag == 1102u) {
        t0 = l0.payload.obj;
        return vader_box_i32(288u, ((vader_struct_vader_midir_InstrCast_t*) t0)->f_dst);
    }
    if (l0.tag == 1104u) {
        t0 = l0.payload.obj;
        return vader_box_i32(288u, ((vader_struct_vader_midir_InstrCellNew_t*) t0)->f_dst);
    }
    if (l0.tag == 1103u) {
        t0 = l0.payload.obj;
        return vader_box_i32(288u, ((vader_struct_vader_midir_InstrCellGet_t*) t0)->f_dst);
    }
    if (l0.tag == 1117u) {
        t0 = l0.payload.obj;
        return vader_box_i32(288u, ((vader_struct_vader_midir_InstrMakeClosure_t*) t0)->f_dst);
    }
    if (l0.tag == 1113u) {
        t0 = l0.payload.obj;
        return vader_box_i32(288u, ((vader_struct_vader_midir_InstrFnRef_t*) t0)->f_dst);
    }
    if (l0.tag == 1112u) {
        t0 = l0.payload.obj;
        return vader_box_i32(288u, ((vader_struct_vader_midir_InstrFnAddr_t*) t0)->f_dst);
    }
    if (l0.tag == 1107u) {
        t0 = l0.payload.obj;
        return vader_box_i32(288u, ((vader_struct_vader_midir_InstrDataConst_t*) t0)->f_dst);
    }
    if (l0.tag == 1114u) {
        t0 = l0.payload.obj;
        return vader_box_i32(288u, ((vader_struct_vader_midir_InstrGlobalGet_t*) t0)->f_dst);
    }
    if (l0.tag == 1100u) {
        t0 = l0.payload.obj;
        t1 = vader_midir_call_single_dst(t0);
        return t1;
    }
    if (l0.tag == 1101u) {
        t0 = l0.payload.obj;
        return ((vader_struct_vader_midir_InstrCallIndirect_t*) t0)->f_dst;
    }
    if (l0.tag == 1125u) {
        t0 = l0.payload.obj;
        return ((vader_struct_vader_midir_InstrVirtualCall_t*) t0)->f_dst;
    }
    if (l0.tag == 1116u) {
        t0 = l0.payload.obj;
        return ((vader_struct_vader_midir_InstrIntrinsic_t*) t0)->f_dst;
    }
    if (l0.tag == 1111u) {
        return vader_box_obj(0u, NULL);
    }
    if (l0.tag == 1124u) {
        return vader_box_obj(0u, NULL);
    }
    if (l0.tag == 1097u) {
        return vader_box_obj(0u, NULL);
    }
    if (l0.tag == 1096u) {
        return vader_box_obj(0u, NULL);
    }
    if (l0.tag == 1105u) {
        return vader_box_obj(0u, NULL);
    }
    if (l0.tag == 1115u) {
        return vader_box_obj(0u, NULL);
    }
    if (l0.tag == 1109u) {
        return vader_box_obj(0u, NULL);
    }
    if (!(l0.tag == 1108u)) {
        vader_unreachable("non-exhaustive match (T3013 should have caught this)");
    }
    return vader_box_obj(0u, NULL);
}

static vader_box_t vader_midir_element_slot(vader_box_t l0) {
    void* l1;
    vader_box_t l2;
    l2 = vader_types_array_backing(l0);
    if (l2.tag == 0u) {
        return vader_box_obj(0u, NULL);
    }
    l1 = l2.payload.obj;
    return ((vader_struct_vader_types_ArrayType_t*) l1)->f_element;
}

void* vader_midir_eliminate_dead_cfg(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    void* l16 = NULL;
    void* l17 = NULL;
    void* l20 = NULL;
    void* l21 = NULL;
    void* l22 = NULL;
    int64_t l5, l6, l11, l14, l15;
    vader_string_t l7 = 0;
    vader_string_t l8 = 0;
    vader_string_t l18 = 0;
    vader_string_t l19 = 0;
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[15] = {
        &l0, &l1, &l2, &l3, &l4, &l9, &l10, &l12, &l13, &l16, &l17, &l20, &l21, &l22, &t1,
    };
    vader_string_t* gc_atom_roots[4] = { &l7, &l8, &l18, &l19 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 15u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(14u, 0u, 0u, 285u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(21u, 0u, 0u, 296u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(15u, 0u, 7u, 288u);
    l3 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__string__Any_t* _a3_obj = (vader_struct_std_collections_MutableMap__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__Any_t));
    vader_obj_header_init(_a3_obj, 448u);
    _a3_obj->f_ekeys = l1;
    _a3_obj->f_evals = l2;
    _a3_obj->f_index = l3;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    l1 = (void*) _a3_obj;
    l2 = ((vader_struct_vader_midir_CFGProject_t*) l0)->f_modules;
    l3 = ((vader_struct_std_collections_MutableMap__string__vader_midir_CFGModule_t*) l2)->f_ekeys;
    l4 = ((vader_struct_std_collections_MutableMap__string__vader_midir_CFGModule_t*) l2)->f_evals;
    l5 = INT64_C(0);
    l6 = ((vader_struct_std_collections_MutableMap__string__vader_midir_CFGModule_t*) l2)->f_size;
    while ((l5 < l6)) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l5)
        t0 = vader_array_box_slots(_a4_slotarr->buf)[_a4_slotarr->offset + (size_t) l5];
        l7 = t0.payload.s;
        vader_array_t* _a5_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l5)
        l2 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l5);
        l8 = l7;
        l9 = l2;
        vader_array_t* _a6_arr = vader_array_new(137u, 0u, 13u, 1071u);
        l10 = (void*) _a6_arr;
        l11 = ((vader_array_t*) ((vader_struct_vader_midir_CFGModule_t*) l9)->f_functions)->length;
        vader_array_t* _a7_arr = vader_array_repeat((vader_array_t*) l10, (int64_t) l11);
        l12 = (void*) _a7_arr;
        l13 = ((vader_struct_vader_midir_CFGModule_t*) l9)->f_functions;
        l14 = ((vader_array_t*) l13)->length;
        l15 = INT64_C(0);
        while ((l15 < l14)) {
            vader_array_t* _a8_slotarr = ((vader_array_t*) l13);
            VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l15)
            t1 = vader_array_ref_load_obj(_a8_slotarr->buf, _a8_slotarr->offset + (size_t) l15);
            l16 = vader_midir_optimise_function(t1);
            vader_array_push((vader_array_t*) l12, vader_ref_box(l16));
            l15 = (l15 + INT64_C(1));
        }
        l17 = l9;
        l18 = ((vader_struct_vader_midir_CFGModule_t*) l17)->f_module_id;
        l19 = ((vader_struct_vader_midir_CFGModule_t*) l17)->f_display_path;
        l20 = ((vader_struct_vader_midir_CFGModule_t*) l17)->f_externs;
        l21 = ((vader_struct_vader_midir_CFGModule_t*) l17)->f_struct_decls;
        vader_struct_vader_midir_CFGModule_t* _a9_obj = (vader_struct_vader_midir_CFGModule_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_CFGModule_t));
        vader_obj_header_init(_a9_obj, 1073u);
        _a9_obj->f_module_id = l18;
        _a9_obj->f_display_path = l19;
        _a9_obj->f_functions = l12;
        _a9_obj->f_externs = l20;
        _a9_obj->f_struct_decls = l21;
        l22 = (void*) _a9_obj;
        std_collections_MutableMap_std_core_IndexSet_set_at__string__Any(l1, l8, vader_ref_box(l22));
        l5 = (l5 + INT64_C(1));
    }
    l2 = l0;
    l3 = ((vader_struct_vader_midir_CFGProject_t*) l2)->f_vtable_entries;
    l4 = ((vader_struct_vader_midir_CFGProject_t*) l2)->f_strings;
    l9 = ((vader_struct_vader_midir_CFGProject_t*) l2)->f_data_pool;
    l10 = ((vader_struct_vader_midir_CFGProject_t*) l2)->f_globals;
    l2 = ((vader_struct_vader_midir_CFGProject_t*) l2)->f_trait_membership;
    vader_struct_vader_midir_CFGProject_t* _a10_obj = (vader_struct_vader_midir_CFGProject_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_CFGProject_t));
    vader_obj_header_init(_a10_obj, 1075u);
    _a10_obj->f_modules = l1;
    _a10_obj->f_vtable_entries = l3;
    _a10_obj->f_strings = l4;
    _a10_obj->f_data_pool = l9;
    _a10_obj->f_globals = l10;
    _a10_obj->f_trait_membership = l2;
    t1 = (void*) _a10_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_midir_emit(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    int64_t l3;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[3] = { &l0, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (!(((vader_struct_vader_midir_FnCtx_t*) l0)->f_current.tag == 0u)) {
        l2 = ((vader_struct_vader_midir_FnCtx_t*) l0)->f_blocks;
        l3 = ((int64_t) ((vader_struct_vader_midir_FnCtx_t*) l0)->f_current.payload.i);
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
        vader_array_push((vader_array_t*) ((vader_struct_vader_midir_MutableBlock_t*) t0)->f_instructions, l1);
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_midir_emit_body(void* l0, void* l1, int32_t l2, int32_t l3, int32_t l4) {
    void* l5 = NULL;
    void* l8 = NULL;
    int32_t l6, l9;
    int64_t l7, l10;
    void* t0 = NULL;
    void** gc_raw_roots[5] = { &l0, &l1, &l5, &l8, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l5 = ((vader_struct_vader_midir_StructureShape_t*) l1)->f_merges;
    l6 = l2;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l6)
    l5 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l6);
    l7 = vader_midir_last_empty_stack_point(l0, l2);
    vader_midir_emit_instructions(l0, l2, INT64_C(0), l7);
    l6 = vader_midir_open_blocks(l0, l5, l3);
    l8 = ((vader_struct_vader_midir_CFGFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_fn_)->f_blocks;
    l9 = l2;
    vader_array_t* _a1_slotarr = ((vader_array_t*) l8);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l9)
    t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l9);
    l10 = ((vader_array_t*) ((vader_struct_vader_midir_BasicBlock_t*) t0)->f_instructions)->length;
    vader_midir_emit_instructions(l0, l2, l7, l10);
    vader_midir_emit_terminator(l0, l1, l2, l6, l4);
    vader_midir_close_blocks(l0, l1, l5, l3);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_midir_emit_branch(void* l0, void* l1, int32_t l2, int32_t l3, int32_t l4, void* l5) {
    bool t0;
    void** gc_raw_roots[3] = { &l0, &l1, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_midir_BlockId_std_core_Equals_equals(l3, l4);
    if (t0) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    t0 = vader_midir_only_jumps(l1, l2, l3);
    if (!(t0)) {
        vader_midir_emit_subtree(l0, l1, l3, l4);
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_midir_cf_br(l0, l5, l3);
    { vader_gc_top = gc_frame.prev; return; }
}

void* vader_midir_emit_bytecode_from_cfg(void* l0, vader_string_t l1, void* l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l9 = NULL;
    void* l12 = NULL;
    void* l15 = NULL;
    void* l23 = NULL;
    void* l26 = NULL;
    void* l27 = NULL;
    void* l28 = NULL;
    void* l29 = NULL;
    void* l30 = NULL;
    void* l31 = NULL;
    void* l32 = NULL;
    void* l33 = NULL;
    void* l34 = NULL;
    void* l35 = NULL;
    void* l36 = NULL;
    void* l37 = NULL;
    void* l38 = NULL;
    void* l39 = NULL;
    void* l40 = NULL;
    void* l41 = NULL;
    int64_t l7, l8, l10, l11, l13, l14, l16, l17;
    int32_t l18, l21;
    vader_box_t l19 = vader_box_null(), l22 = vader_box_null(), l24 = vader_box_null();
    vader_string_t l20 = 0;
    vader_string_t l42 = 0;
    vader_string_t l43 = 0;
    vader_string_t l44 = 0;
    bool l25;
    vader_box_t t0 = vader_box_null();
    vader_string_t t1 = 0;
    void* t2 = NULL;
    bool t3;
    int64_t t4;
    vader_box_t* gc_roots[4] = { &l19, &l22, &l24, &t0 };
    void** gc_raw_roots[27] = {
        &l0, &l2, &l3, &l4, &l5, &l6, &l9, &l12, &l15, &l23, &l26, &l27, &l28, &l29, &l30, &l31,
        &l32, &l33, &l34, &l35, &l36, &l37, &l38, &l39, &l40, &l41, &t2,
    };
    vader_string_t* gc_atom_roots[6] = { &l1, &l20, &l42, &l43, &l44, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 27u, gc_roots, gc_raw_roots, 0u, NULL, 6u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = vader_bytecode_new_emitter_ctx();
    l4 = ((vader_struct_vader_midir_CFGProject_t*) l0)->f_modules;
    l5 = ((vader_struct_std_collections_MutableMap__string__vader_midir_CFGModule_t*) l4)->f_ekeys;
    l6 = ((vader_struct_std_collections_MutableMap__string__vader_midir_CFGModule_t*) l4)->f_evals;
    l7 = INT64_C(0);
    l8 = ((vader_struct_std_collections_MutableMap__string__vader_midir_CFGModule_t*) l4)->f_size;
    while ((l7 < l8)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l7)
        t0 = vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l7];
        t1 = t0.payload.s;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l7)
        l4 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l7);
        l9 = ((vader_struct_vader_midir_CFGModule_t*) l4)->f_functions;
        l10 = ((vader_array_t*) l9)->length;
        l11 = INT64_C(0);
        while ((l11 < l10)) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) l9);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            t2 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l11);
            vader_midir_reserve_cfg_function(t2, l3);
            l11 = (l11 + INT64_C(1));
        }
        l12 = ((vader_struct_vader_midir_CFGModule_t*) l4)->f_externs;
        l13 = ((vader_array_t*) l12)->length;
        l14 = INT64_C(0);
        while ((l14 < l13)) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l12);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l14)
            t2 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l14);
            vader_midir_reserve_cfg_extern(t2, l3);
            l14 = (l14 + INT64_C(1));
        }
        l15 = ((vader_struct_vader_midir_CFGModule_t*) l4)->f_struct_decls;
        l16 = ((vader_array_t*) l15)->length;
        l17 = INT64_C(0);
        while ((l17 < l16)) {
            vader_array_t* _a4_slotarr = ((vader_array_t*) l15);
            VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
            t2 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l17);
            vader_midir_reserve_cfg_struct(t2, l3);
            l17 = (l17 + INT64_C(1));
        }
        l7 = (l7 + INT64_C(1));
    }
    vader_midir_synthesise_cfg_intrinsic_wrappers(l0, l3);
    vader_array_t* _a5_arr = vader_array_new(15u, 0u, 7u, 288u);
    l4 = (void*) _a5_arr;
    l7 = ((vader_array_t*) ((vader_struct_vader_midir_CFGProject_t*) l0)->f_strings)->length;
    vader_array_t* _a6_arr = vader_array_repeat((vader_array_t*) l4, (int64_t) l7);
    l4 = (void*) _a6_arr;
    l5 = ((vader_struct_vader_midir_CFGProject_t*) l0)->f_strings;
    l7 = ((vader_array_t*) l5)->length;
    l8 = INT64_C(0);
    while ((l8 < l7)) {
        vader_array_t* _a7_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
        t0 = vader_array_box_slots(_a7_slotarr->buf)[_a7_slotarr->offset + (size_t) l8];
        t1 = t0.payload.s;
        l18 = vader_bytecode_intern_string(t1, l3);
        vader_array_push_i32((vader_array_t*) l4, l18);
        l8 = (l8 + INT64_C(1));
    }
    l5 = ((vader_struct_vader_midir_CFGProject_t*) l0)->f_data_pool;
    l7 = ((vader_array_t*) l5)->length;
    l8 = INT64_C(0);
    while ((l8 < l7)) {
        vader_array_t* _a8_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
        l19 = vader_array_ref_load_box(_a8_slotarr->buf, _a8_slotarr->offset + (size_t) l8);
        if (l19.tag == 651u) {
            t2 = l19.payload.obj;
            l6 = ((vader_struct_vader_bytecode_BcStrData_t*) t2)->f_values;
            l10 = ((vader_array_t*) l6)->length;
            l11 = INT64_C(0);
            while ((l11 < l10)) {
                vader_array_t* _a9_slotarr = ((vader_array_t*) l6);
                VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
                t0 = vader_array_box_slots(_a9_slotarr->buf)[_a9_slotarr->offset + (size_t) l11];
                t1 = t0.payload.s;
                vader_bytecode_intern_string(t1, l3);
                l11 = (l11 + INT64_C(1));
            }
        } else if (l19.tag == 637u) {
            t2 = l19.payload.obj;
            l9 = ((vader_struct_vader_bytecode_BcAggregateData_t*) t2)->f_elements;
            l13 = ((vader_array_t*) l9)->length;
            l14 = INT64_C(0);
            while ((l14 < l13)) {
                vader_array_t* _a10_slotarr = ((vader_array_t*) l9);
                VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
                t0 = vader_array_ref_load_box(_a10_slotarr->buf, _a10_slotarr->offset + (size_t) l14);
                vader_midir_intern_data_value_strings(t0, l3);
                l14 = (l14 + INT64_C(1));
            }
        }
        l8 = (l8 + INT64_C(1));
    }
    l5 = ((vader_struct_vader_midir_CFGProject_t*) l0)->f_globals;
    l7 = ((vader_array_t*) l5)->length;
    l8 = INT64_C(0);
    while ((l8 < l7)) {
        vader_array_t* _a11_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
        l6 = vader_array_ref_load_obj(_a11_slotarr->buf, _a11_slotarr->offset + (size_t) l8);
        l9 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l3)->f_globals;
        l20 = ((vader_struct_vader_lower_GlobalSlot_t*) l6)->f_name;
        l18 = vader_bytecode_intern_type(((vader_struct_vader_lower_GlobalSlot_t*) l6)->f_type, l3);
        vader_struct_vader_bytecode_BcGlobal_t* _a12_obj = (vader_struct_vader_bytecode_BcGlobal_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcGlobal_t));
        vader_obj_header_init(_a12_obj, 643u);
        _a12_obj->f_name = l20;
        _a12_obj->f_type_id = l18;
        l12 = (void*) _a12_obj;
        vader_array_push((vader_array_t*) l9, vader_ref_box(l12));
        l8 = (l8 + INT64_C(1));
    }
    l5 = ((vader_struct_vader_midir_CFGProject_t*) l0)->f_modules;
    l6 = ((vader_struct_std_collections_MutableMap__string__vader_midir_CFGModule_t*) l5)->f_ekeys;
    l9 = ((vader_struct_std_collections_MutableMap__string__vader_midir_CFGModule_t*) l5)->f_evals;
    l7 = INT64_C(0);
    l8 = ((vader_struct_std_collections_MutableMap__string__vader_midir_CFGModule_t*) l5)->f_size;
    while ((l7 < l8)) {
        vader_array_t* _a13_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a13_slotarr, l7)
        t0 = vader_array_box_slots(_a13_slotarr->buf)[_a13_slotarr->offset + (size_t) l7];
        t1 = t0.payload.s;
        vader_array_t* _a14_slotarr = ((vader_array_t*) l9);
        VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a14_slotarr, l7)
        t2 = vader_array_ref_load_obj(_a14_slotarr->buf, _a14_slotarr->offset + (size_t) l7);
        l5 = ((vader_struct_vader_midir_CFGModule_t*) t2)->f_functions;
        l10 = ((vader_array_t*) l5)->length;
        l11 = INT64_C(0);
        while ((l11 < l10)) {
            vader_array_t* _a15_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a15_slotarr, l11)
            l12 = vader_array_ref_load_obj(_a15_slotarr->buf, _a15_slotarr->offset + (size_t) l11);
            t3 = ((vader_struct_vader_midir_CFGFunction_t*) l12)->f_is_extern;
            if (t3) {
                l11 = (l11 + INT64_C(1));
                continue;
            }
            l18 = INT32_C(-1);
            l19 = ((vader_struct_vader_comptime_MonoEntry_t*) ((vader_struct_vader_midir_CFGFunction_t*) l12)->f_origin)->f_symbol;
            if (l19.tag == 1178u) {
                l15 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l3)->f_function_index_by_symbol_id;
                t2 = l19.payload.obj;
                l21 = ((vader_struct_vader_resolver_symbol_Symbol_t*) t2)->f_id;
                l22 = std_collections_MutableMap_std_core_Index_at__i32__i32(l15, l21);
                if (l22.tag == 288u) {
                    l18 = ((int32_t) l22.payload.i);
                }
            }
            if ((l18 < INT32_C(0))) {
                l23 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l3)->f_function_index_by_mangle;
                l20 = ((vader_struct_vader_midir_CFGFunction_t*) l12)->f_mangled;
                l24 = std_collections_MutableMap_std_core_Index_at__string__i32(l23, l20);
                if (l24.tag == 288u) {
                    l18 = ((int32_t) l24.payload.i);
                }
            }
            if ((l18 >= INT32_C(0))) {
                l25 = ((vader_struct_vader_bytecode_EmitOptions_t*) l2)->f_want_debug;
                vader_midir_emit_cfg_function_body(l12, l18, l3, l4, l25);
            }
            l11 = (l11 + INT64_C(1));
        }
        l7 = (l7 + INT64_C(1));
    }
    l4 = ((vader_struct_vader_midir_CFGProject_t*) l0)->f_data_pool;
    t3 = ((vader_struct_vader_bytecode_EmitOptions_t*) l2)->f_optimize;
    if (t3) {
        l7 = INT64_C(0);
        l8 = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l3)->f_functions)->length;
        while ((l7 < l8)) {
            vader_array_t* _a16_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l3)->f_functions);
            VADER_ARRAY_RESOLVE_BUF(_a16_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a16_slotarr, l7)
            t2 = vader_array_ref_load_obj(_a16_slotarr->buf, _a16_slotarr->offset + (size_t) l7);
            t4 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) t2)->f_body)->length;
            l10 = vader_chk_add(i64, t4, INT64_C(1));
            for (;;) {
                vader_array_t* _a17_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l3)->f_functions);
                VADER_ARRAY_RESOLVE_BUF(_a17_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a17_slotarr, l7)
                t2 = vader_array_ref_load_obj(_a17_slotarr->buf, _a17_slotarr->offset + (size_t) l7);
                t4 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) t2)->f_body)->length;
                if ((t4 < l10)) {
                    vader_array_t* _a18_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l3)->f_functions);
                    VADER_ARRAY_RESOLVE_BUF(_a18_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a18_slotarr, l7)
                    t2 = vader_array_ref_load_obj(_a18_slotarr->buf, _a18_slotarr->offset + (size_t) l7);
                    l10 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) t2)->f_body)->length;
                    l5 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l3)->f_functions;
                    VADER_ARRAY_CHECK_INDEX(_a18_slotarr, l7)
                    t2 = vader_array_ref_load_obj(_a18_slotarr->buf, _a18_slotarr->offset + (size_t) l7);
                    l6 = vader_bytecode_propagate_const_single_use(t2);
                    vader_array_t* _a19_slotarr = ((vader_array_t*) l5);
                    VADER_ARRAY_RESOLVE_BUF(_a19_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a19_slotarr, l7)
                    vader_array_ref_store(_a19_slotarr->buf, _a19_slotarr->offset + (size_t) l7, l6);
                    VADER_WRITE_BARRIER(_a19_slotarr->buf);
                    continue;
                }
                break;
            }
            l9 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l3)->f_functions;
            vader_array_t* _a20_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l3)->f_functions);
            VADER_ARRAY_RESOLVE_BUF(_a20_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a20_slotarr, l7)
            l12 = vader_array_ref_load_obj(_a20_slotarr->buf, _a20_slotarr->offset + (size_t) l7);
            VADER_ARRAY_CHECK_INDEX(_a20_slotarr, l7)
            t2 = vader_array_ref_load_obj(_a20_slotarr->buf, _a20_slotarr->offset + (size_t) l7);
            l15 = vader_bytecode_run_bc_peephole(t2);
            l23 = vader_midir_with_peephole_out(l12, l15);
            vader_array_t* _a21_slotarr = ((vader_array_t*) l9);
            VADER_ARRAY_RESOLVE_BUF(_a21_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a21_slotarr, l7)
            vader_array_ref_store(_a21_slotarr->buf, _a21_slotarr->offset + (size_t) l7, l23);
            VADER_WRITE_BARRIER(_a21_slotarr->buf);
            l26 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l3)->f_functions;
            vader_array_t* _a22_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l3)->f_functions);
            VADER_ARRAY_RESOLVE_BUF(_a22_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a22_slotarr, l7)
            l27 = vader_array_ref_load_obj(_a22_slotarr->buf, _a22_slotarr->offset + (size_t) l7);
            VADER_ARRAY_CHECK_INDEX(_a22_slotarr, l7)
            t2 = vader_array_ref_load_obj(_a22_slotarr->buf, _a22_slotarr->offset + (size_t) l7);
            l28 = vader_bytecode_run_bc_const_fold_arith(t2);
            l29 = vader_midir_with_peephole_out(l27, l28);
            vader_array_t* _a23_slotarr = ((vader_array_t*) l26);
            VADER_ARRAY_RESOLVE_BUF(_a23_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a23_slotarr, l7)
            vader_array_ref_store(_a23_slotarr->buf, _a23_slotarr->offset + (size_t) l7, l29);
            VADER_WRITE_BARRIER(_a23_slotarr->buf);
            l30 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l3)->f_functions;
            vader_array_t* _a24_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l3)->f_functions);
            VADER_ARRAY_RESOLVE_BUF(_a24_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a24_slotarr, l7)
            t2 = vader_array_ref_load_obj(_a24_slotarr->buf, _a24_slotarr->offset + (size_t) l7);
            l31 = vader_bytecode_drop_dead_stores(t2);
            vader_array_t* _a25_slotarr = ((vader_array_t*) l30);
            VADER_ARRAY_RESOLVE_BUF(_a25_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a25_slotarr, l7)
            vader_array_ref_store(_a25_slotarr->buf, _a25_slotarr->offset + (size_t) l7, l31);
            VADER_WRITE_BARRIER(_a25_slotarr->buf);
            l32 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l3)->f_functions;
            vader_array_t* _a26_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l3)->f_functions);
            VADER_ARRAY_RESOLVE_BUF(_a26_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a26_slotarr, l7)
            l33 = vader_array_ref_load_obj(_a26_slotarr->buf, _a26_slotarr->offset + (size_t) l7);
            VADER_ARRAY_CHECK_INDEX(_a26_slotarr, l7)
            t2 = vader_array_ref_load_obj(_a26_slotarr->buf, _a26_slotarr->offset + (size_t) l7);
            l34 = vader_bytecode_run_bc_return_lit_fold(t2);
            l35 = vader_midir_with_peephole_out(l33, l34);
            vader_array_t* _a27_slotarr = ((vader_array_t*) l32);
            VADER_ARRAY_RESOLVE_BUF(_a27_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a27_slotarr, l7)
            vader_array_ref_store(_a27_slotarr->buf, _a27_slotarr->offset + (size_t) l7, l35);
            VADER_WRITE_BARRIER(_a27_slotarr->buf);
            l36 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l3)->f_functions;
            vader_array_t* _a28_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l3)->f_functions);
            VADER_ARRAY_RESOLVE_BUF(_a28_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a28_slotarr, l7)
            t2 = vader_array_ref_load_obj(_a28_slotarr->buf, _a28_slotarr->offset + (size_t) l7);
            l37 = vader_bytecode_coalesce_slots(t2);
            vader_array_t* _a29_slotarr = ((vader_array_t*) l36);
            VADER_ARRAY_RESOLVE_BUF(_a29_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a29_slotarr, l7)
            vader_array_ref_store(_a29_slotarr->buf, _a29_slotarr->offset + (size_t) l7, l37);
            VADER_WRITE_BARRIER(_a29_slotarr->buf);
            l38 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l3)->f_functions;
            vader_array_t* _a30_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l3)->f_functions);
            VADER_ARRAY_RESOLVE_BUF(_a30_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a30_slotarr, l7)
            l39 = vader_array_ref_load_obj(_a30_slotarr->buf, _a30_slotarr->offset + (size_t) l7);
            VADER_ARRAY_CHECK_INDEX(_a30_slotarr, l7)
            t2 = vader_array_ref_load_obj(_a30_slotarr->buf, _a30_slotarr->offset + (size_t) l7);
            l40 = vader_bytecode_strip_self_copies(t2);
            l41 = vader_midir_with_peephole_out(l39, l40);
            vader_array_t* _a31_slotarr = ((vader_array_t*) l38);
            VADER_ARRAY_RESOLVE_BUF(_a31_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a31_slotarr, l7)
            vader_array_ref_store(_a31_slotarr->buf, _a31_slotarr->offset + (size_t) l7, l41);
            VADER_WRITE_BARRIER(_a31_slotarr->buf);
            l7 = (l7 + INT64_C(1));
        }
        vader_array_t* _a32_arr = vader_array_new(14u, 0u, 0u, 285u);
        l5 = (void*) _a32_arr;
        vader_array_t* _a33_arr = vader_array_new(12u, 0u, 12u, 283u);
        l6 = (void*) _a33_arr;
        vader_array_t* _a34_arr = vader_array_new(15u, 0u, 7u, 288u);
        l9 = (void*) _a34_arr;
        vader_struct_std_collections_MutableMap__string__bool_t* _a35_obj = (vader_struct_std_collections_MutableMap__string__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__bool_t));
        vader_obj_header_init(_a35_obj, 454u);
        _a35_obj->f_ekeys = l5;
        _a35_obj->f_evals = l6;
        _a35_obj->f_index = l9;
        _a35_obj->f_mask = INT64_C(0);
        _a35_obj->f_size = INT64_C(0);
        _a35_obj->f_tombs = INT64_C(0);
        l5 = (void*) _a35_obj;
        l6 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l3)->f_functions;
        l7 = ((vader_array_t*) l6)->length;
        l8 = INT64_C(0);
        while ((l8 < l7)) {
            vader_array_t* _a36_slotarr = ((vader_array_t*) l6);
            VADER_ARRAY_RESOLVE_BUF(_a36_slotarr)
            t2 = vader_array_ref_load_obj(_a36_slotarr->buf, _a36_slotarr->offset + (size_t) l8);
            l9 = ((vader_struct_vader_bytecode_BcFunction_t*) t2)->f_body;
            l10 = ((vader_array_t*) l9)->length;
            l11 = INT64_C(0);
            while ((l11 < l10)) {
                vader_array_t* _a37_slotarr = ((vader_array_t*) l9);
                VADER_ARRAY_RESOLVE_BUF(_a37_slotarr)
                l19 = vader_array_ref_load_box(_a37_slotarr->buf, _a37_slotarr->offset + (size_t) l11);
                if (l19.tag == 805u) {
                    t2 = l19.payload.obj;
                    l20 = ((vader_struct_vader_bytecode_VirtualCall_t*) t2)->f_vtable_key;
                    std_collections_MutableMap_std_core_IndexSet_set_at__string__bool(l5, l20, true);
                }
                l11 = (l11 + INT64_C(1));
            }
            l8 = (l8 + INT64_C(1));
        }
        vader_array_t* _a38_arr = vader_array_new(15u, 0u, 7u, 288u);
        l6 = (void*) _a38_arr;
        l9 = ((vader_struct_vader_midir_CFGProject_t*) l0)->f_vtable_entries;
        l7 = ((vader_array_t*) l9)->length;
        l8 = INT64_C(0);
        while ((l8 < l7)) {
            vader_array_t* _a39_slotarr = ((vader_array_t*) l9);
            VADER_ARRAY_RESOLVE_BUF(_a39_slotarr)
            l12 = vader_array_ref_load_obj(_a39_slotarr->buf, _a39_slotarr->offset + (size_t) l8);
            l20 = ((vader_struct_vader_lower_LoweredVtableEntry_t*) l12)->f_trait_name;
            l42 = ((vader_struct_vader_lower_LoweredVtableEntry_t*) l12)->f_method_name;
            l43 = vader_midir_vtable_key(l20, l42);
            t0 = std_collections_MutableMap_std_core_Index_at__string__bool(l5, l43);
            if (t0.tag == 283u) {
                l44 = vader_bytecode_type_intern_key(((vader_struct_vader_lower_LoweredVtableEntry_t*) l12)->f_struct_type);
                l19 = std_collections_MutableMap_std_core_Index_at__string__i32(((vader_struct_vader_bytecode_EmitterCtx_t*) l3)->f_type_key, l44);
                if (l19.tag == 288u) {
                    l15 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l3)->f_pinned_types;
                    l18 = ((int32_t) l19.payload.i);
                    vader_array_push_i32((vader_array_t*) l15, l18);
                }
                l22 = vader_midir_resolve_fn_index(((vader_struct_vader_lower_LoweredVtableEntry_t*) l12)->f_fn_symbol, l3);
                if (!(l22.tag == 0u)) {
                    l21 = ((int32_t) l22.payload.i);
                    vader_array_push_i32((vader_array_t*) l6, l21);
                }
                l8 = (l8 + INT64_C(1));
                continue;
            }
            l8 = (l8 + INT64_C(1));
        }
        l5 = ((vader_struct_vader_bytecode_EmitOptions_t*) l2)->f_keep_mangles;
        vader_bytecode_prune_unused_functions(l3, l6, l5);
        vader_bytecode_prune_unused_imports(l3);
        l4 = vader_bytecode_prune_unused_data(l3, l4);
        vader_bytecode_prune_unused_globals(l3);
        vader_midir_pin_baked_struct_types(l4, l3);
        vader_bytecode_prune_unused_types(l3);
        ((vader_struct_vader_bytecode_EmitterCtx_t*) l3)->f_types_frozen = true;
        l5 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l3)->f_imports;
        l7 = ((vader_array_t*) l5)->length;
        l8 = INT64_C(0);
        while ((l8 < l7)) {
            vader_array_t* _a40_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a40_slotarr)
            l6 = vader_array_ref_load_obj(_a40_slotarr->buf, _a40_slotarr->offset + (size_t) l8);
            l20 = ((vader_struct_vader_bytecode_BcImport_t*) l6)->f_mangled_name;
            l25 = ((vader_struct_vader_bytecode_BcImport_t*) l6)->f_is_extern;
            vader_bytecode_assert_host_import_wired(l20, l25);
            l8 = (l8 + INT64_C(1));
        }
    }
    l5 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l3)->f_types;
    l6 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l3)->f_strings;
    l9 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l3)->f_functions;
    l12 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l3)->f_imports;
    l15 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l3)->f_exports;
    l23 = ((vader_struct_vader_midir_CFGProject_t*) l0)->f_vtable_entries;
    l26 = ((vader_struct_vader_midir_CFGProject_t*) l0)->f_trait_membership;
    l23 = vader_midir_build_impl_table_from_vtable(l23, l26, l3);
    l26 = vader_midir_build_vtables_from_entries(((vader_struct_vader_midir_CFGProject_t*) l0)->f_vtable_entries, l3);
    l3 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l3)->f_globals;
    vader_struct_vader_bytecode_BytecodeModule_t* _a41_obj = (vader_struct_vader_bytecode_BytecodeModule_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BytecodeModule_t));
    vader_obj_header_init(_a41_obj, 672u);
    _a41_obj->f_name = l1;
    _a41_obj->f_types = l5;
    _a41_obj->f_strings = l6;
    _a41_obj->f_data_pool = l4;
    _a41_obj->f_functions = l9;
    _a41_obj->f_imports = l12;
    _a41_obj->f_exports = l15;
    _a41_obj->f_impl_table = l23;
    _a41_obj->f_vtables = l26;
    _a41_obj->f_globals = l3;
    t2 = (void*) _a41_obj;
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_midir_emit_call_results(void* l0, int64_t l1, void* l2, void* l3) {
    vader_box_t l4 = vader_box_null();
    int64_t l5, l6, l7;
    int32_t l8;
    int64_t t0, t2;
    int32_t t1;
    vader_box_t* gc_roots[1] = { &l4 };
    void** gc_raw_roots[3] = { &l0, &l2, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) l2)->length;
    if ((t0 <= INT64_C(1))) {
        t0 = ((vader_array_t*) l2)->length;
        if (t0 == INT64_C(0)) {
            l4 = vader_box_obj(0u, NULL);
            vader_midir_emit_result_if_any(l0, l1, l4, l3);
            { vader_gc_top = gc_frame.prev; return; }
        }
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
        t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) INT32_C(0)];
        l4 = vader_box_i32(288u, t1);
        vader_midir_emit_result_if_any(l0, l1, l4, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    l5 = INT64_C(0);
    l6 = ((vader_array_t*) l2)->length;
    while ((l5 < l6)) {
        t0 = ((vader_array_t*) l2)->length;
        t2 = vader_chk_sub(i64, t0, INT64_C(1));
        l7 = vader_chk_sub(i64, t2, l5);
        vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l7)
        l8 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l7];
        vader_midir_emit_set(l0, l8, l3);
        l5 = (l5 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_midir_emit_cfg_function_body(void* l0, int32_t l1, void* l2, void* l3, bool l4) {
    void* l5 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l15 = NULL;
    void* l18 = NULL;
    void* l19 = NULL;
    void* l20 = NULL;
    int64_t l8, l9, l10;
    int32_t l11, l12, l13, l14;
    vader_string_t l16 = 0;
    uint8_t l17;
    int64_t t0;
    void* t1 = NULL;
    void** gc_raw_roots[11] = { &l0, &l2, &l3, &l5, &l6, &l7, &l15, &l18, &l19, &l20, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l16 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 11u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l2)->f_functions);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    l5 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l1);
    vader_array_t* _a1_arr = vader_array_new(15u, 0u, 7u, 288u);
    l6 = (void*) _a1_arr;
    std_collections_MutableMap_std_core_IndexSet_set_at__i32__Any(((vader_struct_vader_bytecode_EmitterCtx_t*) l2)->f_pinned_types_by_fn, l1, vader_ref_box(l6));
    vader_array_t* _a2_arr = vader_array_new(15u, 0u, 7u, 288u);
    l7 = (void*) _a2_arr;
    l8 = ((vader_array_t*) ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_params)->length;
    l9 = INT64_C(0);
    l10 = ((vader_array_t*) ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_locals)->length;
    while ((l9 < l10)) {
        if ((l9 < l8)) {
            l11 = ((int32_t) (int64_t) l9);
            vader_array_push_i32((vader_array_t*) l7, l11);
        } else {
            l12 = ((int32_t) (int64_t) l8);
            t0 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l5)->f_locals)->length;
            l13 = ((int32_t) (int64_t) t0);
            l14 = vader_chk_add(i32, l12, l13);
            l15 = ((vader_struct_vader_bytecode_BcFunction_t*) l5)->f_locals;
            vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_locals);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l9)
            t1 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l9);
            l16 = ((vader_struct_vader_midir_CFGLocal_t*) t1)->f_name;
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l9)
            t1 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l9);
            l17 = vader_bytecode_val_type_of_type(((vader_struct_vader_midir_CFGLocal_t*) t1)->f_type);
            vader_struct_vader_bytecode_BcLocal_t* _a4_obj = (vader_struct_vader_bytecode_BcLocal_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcLocal_t));
            vader_obj_header_init(_a4_obj, 645u);
            _a4_obj->f_name = l16;
            _a4_obj->f_val = l17;
            l18 = (void*) _a4_obj;
            vader_array_push((vader_array_t*) l15, vader_ref_box(l18));
            vader_array_push_i32((vader_array_t*) l7, l14);
        }
        l9 = (l9 + INT64_C(1));
    }
    l15 = vader_midir_skip_forwarding_blocks(l0);
    l18 = vader_midir_schedule_stack(l15);
    vader_array_t* _a5_arr = vader_array_new(147u, 0u, 13u, 1133u);
    l19 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(146u, 0u, 13u, 1130u);
    l20 = (void*) _a6_arr;
    vader_struct_vader_midir_FnEmitCfg_t* _a7_obj = (vader_struct_vader_midir_FnEmitCfg_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_FnEmitCfg_t));
    vader_obj_header_init(_a7_obj, 1091u);
    _a7_obj->f_fn_ = l15;
    _a7_obj->f_pinned_types_bucket = l6;
    _a7_obj->f_slot = l5;
    _a7_obj->f_project = l2;
    _a7_obj->f_string_index_map = l3;
    _a7_obj->f_local_to_slot = l7;
    _a7_obj->f_scopes = l19;
    _a7_obj->f_pending = l20;
    _a7_obj->f_hints = l18;
    _a7_obj->f_want_debug = l4;
    t1 = (void*) _a7_obj;
    vader_midir_structure_function(t1);
    l5 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l2)->f_functions;
    vader_array_t* _a8_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l2)->f_functions);
    VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l1)
    l6 = vader_array_ref_load_obj(_a8_slotarr->buf, _a8_slotarr->offset + (size_t) l1);
    VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l1)
    t1 = vader_array_ref_load_obj(_a8_slotarr->buf, _a8_slotarr->offset + (size_t) l1);
    l7 = vader_bytecode_drop_unbranched_blocks(t1);
    l6 = vader_midir_with_peephole_out(l6, l7);
    vader_array_t* _a9_slotarr = ((vader_array_t*) l5);
    VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l1)
    vader_array_ref_store(_a9_slotarr->buf, _a9_slotarr->offset + (size_t) l1, l6);
    VADER_WRITE_BARRIER(_a9_slotarr->buf);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_midir_emit_cond_branch(void* l0, void* l1, int32_t l2, void* l3, int32_t l4, int32_t l5) {
    int32_t l6, l9;
    void* l7 = NULL;
    void* l11 = NULL;
    bool l8, l10;
    bool t0;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[5] = { &l0, &l1, &l3, &l7, &l11 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = std_collections_MutableSet_std_core_Contains_contains__i32(((vader_struct_vader_midir_ScheduleHints_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_hints)->f_skip_terminator_get, l2);
    if (!(t0)) {
        l6 = ((vader_struct_vader_midir_TermCondBranch_t*) l3)->f_cond;
        l7 = ((vader_struct_vader_midir_TermCondBranch_t*) l3)->f_span;
        vader_midir_emit_get(l0, l6, l7);
    }
    t0 = vader_midir_BlockId_std_core_Equals_equals(((vader_struct_vader_midir_TermCondBranch_t*) l3)->f_else_block, l4);
    if (!(t0)) {
        t0 = vader_midir_BlockId_std_core_Equals_equals(((vader_struct_vader_midir_TermCondBranch_t*) l3)->f_else_block, l5);
        l8 = !(t0);
    } else {
        l8 = false;
    }
    l7 = ((vader_struct_vader_midir_StructureShape_t*) l1)->f_rpo_index;
    l6 = ((vader_struct_vader_midir_TermCondBranch_t*) l3)->f_then_block;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l7);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l6)
    l6 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l6];
    l7 = ((vader_struct_vader_midir_StructureShape_t*) l1)->f_rpo_index;
    l9 = l2;
    vader_array_t* _a1_slotarr = ((vader_array_t*) l7);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l9)
    l9 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l9];
    l10 = (l6 > l9);
    t0 = vader_midir_BlockId_std_core_Equals_equals(((vader_struct_vader_midir_TermCondBranch_t*) l3)->f_then_block, l4);
    if (!(t0)) {
        t0 = vader_midir_BlockId_std_core_Equals_equals(((vader_struct_vader_midir_TermCondBranch_t*) l3)->f_then_block, l5);
        if (!(t0)) {
            l7 = ((vader_struct_vader_midir_StructureShape_t*) l1)->f_merge;
            l6 = ((vader_struct_vader_midir_TermCondBranch_t*) l3)->f_then_block;
            vader_array_t* _a2_slotarr = ((vader_array_t*) l7);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l6)
            t1 = vader_box_bool(283u, ((uint8_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l6]);
            t0 = t1.payload.b;
            if (t0) {
                if (l10) {
                    l7 = ((vader_struct_vader_midir_TermCondBranch_t*) l3)->f_span;
                    l6 = ((vader_struct_vader_midir_TermCondBranch_t*) l3)->f_then_block;
                    vader_midir_cf_br_if(l0, l7, l6);
                    t0 = vader_midir_BlockId_std_core_Equals_equals(((vader_struct_vader_midir_TermCondBranch_t*) l3)->f_else_block, l5);
                    if (t0) {
                        { vader_gc_top = gc_frame.prev; return; }
                    }
                    l6 = ((vader_struct_vader_midir_TermCondBranch_t*) l3)->f_else_block;
                    l7 = ((vader_struct_vader_midir_TermCondBranch_t*) l3)->f_span;
                    vader_midir_emit_branch(l0, l1, l2, l6, l4, l7);
                    { vader_gc_top = gc_frame.prev; return; }
                }
            }
        }
    }
    if (l8) {
        l6 = ((vader_struct_vader_midir_TermCondBranch_t*) l3)->f_else_block;
        t0 = vader_midir_leaves_at_once(l0, l1, l2, l6);
        if (t0) {
            l7 = ((vader_struct_vader_midir_TermCondBranch_t*) l3)->f_span;
            vader_midir_cf_if(l0, l7);
            l7 = ((vader_struct_vader_midir_TermCondBranch_t*) l3)->f_span;
            vader_midir_cf_else(l0, l7);
            l6 = ((vader_struct_vader_midir_TermCondBranch_t*) l3)->f_else_block;
            l7 = ((vader_struct_vader_midir_TermCondBranch_t*) l3)->f_span;
            vader_midir_emit_branch(l0, l1, l2, l6, l4, l7);
            l7 = ((vader_struct_vader_midir_TermCondBranch_t*) l3)->f_span;
            vader_midir_cf_end(l0, l7);
            t0 = vader_midir_BlockId_std_core_Equals_equals(((vader_struct_vader_midir_TermCondBranch_t*) l3)->f_then_block, l5);
            if (t0) {
                { vader_gc_top = gc_frame.prev; return; }
            }
            l6 = ((vader_struct_vader_midir_TermCondBranch_t*) l3)->f_then_block;
            l7 = ((vader_struct_vader_midir_TermCondBranch_t*) l3)->f_span;
            vader_midir_emit_branch(l0, l1, l2, l6, l4, l7);
            { vader_gc_top = gc_frame.prev; return; }
        }
    }
    l7 = ((vader_struct_vader_midir_TermCondBranch_t*) l3)->f_span;
    vader_midir_cf_if(l0, l7);
    t0 = vader_midir_BlockId_std_core_Equals_equals(((vader_struct_vader_midir_TermCondBranch_t*) l3)->f_then_block, l5);
    if (!(t0)) {
        l6 = ((vader_struct_vader_midir_TermCondBranch_t*) l3)->f_then_block;
        l7 = ((vader_struct_vader_midir_TermCondBranch_t*) l3)->f_span;
        vader_midir_emit_branch(l0, l1, l2, l6, l4, l7);
    }
    t0 = vader_midir_BlockId_std_core_Equals_equals(((vader_struct_vader_midir_TermCondBranch_t*) l3)->f_else_block, l4);
    if (t0) {
        l8 = true;
    } else {
        l8 = vader_midir_BlockId_std_core_Equals_equals(((vader_struct_vader_midir_TermCondBranch_t*) l3)->f_else_block, l5);
    }
    if (l8) {
        l7 = ((vader_struct_vader_midir_TermCondBranch_t*) l3)->f_span;
        vader_midir_cf_end(l0, l7);
        { vader_gc_top = gc_frame.prev; return; }
    }
    t0 = vader_midir_last_op_exits(l0);
    if (!(t0)) {
        l11 = ((vader_struct_vader_midir_TermCondBranch_t*) l3)->f_span;
        vader_midir_cf_else(l0, l11);
        l9 = ((vader_struct_vader_midir_TermCondBranch_t*) l3)->f_else_block;
        l11 = ((vader_struct_vader_midir_TermCondBranch_t*) l3)->f_span;
        vader_midir_emit_branch(l0, l1, l2, l9, l4, l11);
        l11 = ((vader_struct_vader_midir_TermCondBranch_t*) l3)->f_span;
        vader_midir_cf_end(l0, l11);
        { vader_gc_top = gc_frame.prev; return; }
    }
    l7 = ((vader_struct_vader_midir_TermCondBranch_t*) l3)->f_span;
    vader_midir_cf_end(l0, l7);
    l6 = ((vader_struct_vader_midir_TermCondBranch_t*) l3)->f_else_block;
    l7 = ((vader_struct_vader_midir_TermCondBranch_t*) l3)->f_span;
    vader_midir_emit_branch(l0, l1, l2, l6, l4, l7);
    { vader_gc_top = gc_frame.prev; return; }
}

static int32_t vader_midir_emit_const(void* l0, vader_box_t l1, vader_box_t l2, void* l3) {
    int32_t l4;
    void* l5 = NULL;
    vader_box_t* gc_roots[2] = { &l1, &l2 };
    void** gc_raw_roots[3] = { &l0, &l3, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l4 = vader_midir_fresh_tmp(l0, 2029u, l1);
    vader_struct_vader_midir_InstrConst_t* _a0_obj = (vader_struct_vader_midir_InstrConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrConst_t));
    vader_obj_header_init(_a0_obj, 1106u);
    _a0_obj->f_span = l3;
    _a0_obj->f_dst = l4;
    _a0_obj->f_value = l2;
    _a0_obj->f_type = l1;
    l5 = (void*) _a0_obj;
    vader_midir_emit(l0, vader_ref_box(l5));
    { int32_t __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_midir_emit_const_instr(void* l0, void* l1, int64_t l2) {
    vader_box_t l3 = vader_box_null();
    void* l4 = NULL;
    void* l5 = NULL;
    uint32_t l6;
    bool l7;
    int32_t l8;
    uint8_t t0;
    bool t1;
    void* t2 = NULL;
    int64_t t3;
    double t4;
    int32_t t5, t6;
    vader_box_t* gc_roots[1] = { &l3 };
    void** gc_raw_roots[5] = { &l0, &l1, &l4, &l5, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_midir_InstrConst_t*) l1)->f_value;
    if (l3.tag == 1083u) {
        t0 = vader_bytecode_val_type_of_type(((vader_struct_vader_midir_InstrConst_t*) l1)->f_type);
        t1 = vader_bytecode_is_64_bit_int_val(t0);
        if (t1) {
            t2 = l3.payload.obj;
            t3 = ((vader_struct_vader_midir_ConstInt_t*) t2)->f_value;
            vader_struct_vader_bytecode_I64Const_t* _a0_obj = (vader_struct_vader_bytecode_I64Const_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64Const_t));
            vader_obj_header_init(_a0_obj, 733u);
            _a0_obj->f_value = t3;
            l4 = (void*) _a0_obj;
            l5 = ((vader_struct_vader_midir_InstrConst_t*) l1)->f_span;
            vader_midir_push_emit(l0, vader_ref_box(l4), l5);
        } else {
            t2 = l3.payload.obj;
            t3 = ((vader_struct_vader_midir_ConstInt_t*) t2)->f_value;
            vader_struct_vader_bytecode_I32Const_t* _a1_obj = (vader_struct_vader_bytecode_I32Const_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32Const_t));
            vader_obj_header_init(_a1_obj, 713u);
            _a1_obj->f_value = ((int32_t) (int64_t) t3);
            l4 = (void*) _a1_obj;
            l5 = ((vader_struct_vader_midir_InstrConst_t*) l1)->f_span;
            vader_midir_push_emit(l0, vader_ref_box(l4), l5);
        }
    } else if (l3.tag == 1082u) {
        t2 = l3.payload.obj;
        t4 = ((vader_struct_vader_midir_ConstFloat_t*) t2)->f_value;
        vader_struct_vader_bytecode_F64Const_t* _a2_obj = (vader_struct_vader_bytecode_F64Const_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_F64Const_t));
        vader_obj_header_init(_a2_obj, 692u);
        _a2_obj->f_value = t4;
        l4 = (void*) _a2_obj;
        l5 = ((vader_struct_vader_midir_InstrConst_t*) l1)->f_span;
        vader_midir_push_emit(l0, vader_ref_box(l4), l5);
    } else if (l3.tag == 1080u) {
        t2 = l3.payload.obj;
        t1 = ((vader_struct_vader_midir_ConstBool_t*) t2)->f_value;
        vader_struct_vader_bytecode_BoolConst_t* _a3_obj = (vader_struct_vader_bytecode_BoolConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BoolConst_t));
        vader_obj_header_init(_a3_obj, 662u);
        _a3_obj->f_value = t1;
        l4 = (void*) _a3_obj;
        l5 = ((vader_struct_vader_midir_InstrConst_t*) l1)->f_span;
        vader_midir_push_emit(l0, vader_ref_box(l4), l5);
    } else if (l3.tag == 1081u) {
        t2 = l3.payload.obj;
        t5 = ((vader_struct_vader_midir_ConstChar_t*) t2)->f_value;
        t6 = t5;
        l6 = (uint32_t) (int32_t) t6;
        if ((l6 > INT32_C(55295))) {
            if ((l6 < INT32_C(57344))) {
                l7 = true;
            } else {
                l7 = (l6 > INT32_C(1114111));
            }
            if (l7) {
                vader_unreachable("value out of range: no Unicode scalar value");
            }
        }
        vader_struct_vader_bytecode_CharConst_t* _a4_obj = (vader_struct_vader_bytecode_CharConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_CharConst_t));
        vader_obj_header_init(_a4_obj, 677u);
        _a4_obj->f_value = ((uint32_t) (uint32_t) l6);
        l4 = (void*) _a4_obj;
        l5 = ((vader_struct_vader_midir_InstrConst_t*) l1)->f_span;
        vader_midir_push_emit(l0, vader_ref_box(l4), l5);
    } else if (l3.tag == 1084u) {
        vader_struct_vader_bytecode_NullConst_t* _a5_obj = (vader_struct_vader_bytecode_NullConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_NullConst_t));
        vader_obj_header_init(_a5_obj, 764u);
        l4 = (void*) _a5_obj;
        l5 = ((vader_struct_vader_midir_InstrConst_t*) l1)->f_span;
        vader_midir_push_emit(l0, vader_ref_box(l4), l5);
    } else if (l3.tag == 1085u) {
        l4 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_string_index_map;
        t2 = l3.payload.obj;
        l8 = ((vader_struct_vader_midir_ConstString_t*) t2)->f_index;
        vader_array_t* _a6_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l8)
        t5 = ((int32_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l8];
        vader_struct_vader_bytecode_StringConst_t* _a7_obj = (vader_struct_vader_bytecode_StringConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_StringConst_t));
        vader_obj_header_init(_a7_obj, 782u);
        _a7_obj->f_index = t5;
        l4 = (void*) _a7_obj;
        l5 = ((vader_struct_vader_midir_InstrConst_t*) l1)->f_span;
        vader_midir_push_emit(l0, vader_ref_box(l4), l5);
    }
    l8 = ((vader_struct_vader_midir_InstrConst_t*) l1)->f_dst;
    l4 = ((vader_struct_vader_midir_InstrConst_t*) l1)->f_span;
    vader_midir_emit_result(l0, l2, l8, l4);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_midir_emit_first_get(void* l0, int64_t l1, int32_t l2, void* l3) {
    bool t0;
    void** gc_raw_roots[2] = { &l0, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = std_collections_MutableSet_std_core_Contains_contains__i64(((vader_struct_vader_midir_ScheduleHints_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_hints)->f_skip_first_get, l1);
    if (!(t0)) {
        vader_midir_emit_get(l0, l2, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_midir_emit_get(void* l0, int32_t l1, void* l2) {
    void* l3 = NULL;
    int64_t l4;
    int32_t t0;
    void** gc_raw_roots[3] = { &l0, &l2, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_local_to_slot;
    l4 = ((int64_t) (int32_t) l1);
    vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
    t0 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l4];
    vader_struct_vader_bytecode_LocalGet_t* _a1_obj = (vader_struct_vader_bytecode_LocalGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_LocalGet_t));
    vader_obj_header_init(_a1_obj, 758u);
    _a1_obj->f_slot = t0;
    l3 = (void*) _a1_obj;
    vader_midir_push_emit(l0, vader_ref_box(l3), l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_midir_emit_instr(void* l0, vader_box_t l1, int64_t l2) {
    void* l3 = NULL;
    void* l12 = NULL;
    void* l14 = NULL;
    void* l16 = NULL;
    int32_t l4, l17, l22;
    int64_t l5, l13, l15;
    bool l6, l9;
    vader_box_t l7 = vader_box_null(), l8 = vader_box_null();
    uint8_t l10, l11, l23;
    vader_string_t l18 = 0;
    vader_string_t l19 = 0;
    vader_string_t l20 = 0;
    vader_string_t l21 = 0;
    void* t0 = NULL;
    bool t1;
    int64_t t2, t5;
    int32_t t3;
    vader_string_t t4 = 0;
    vader_box_t* gc_roots[3] = { &l1, &l7, &l8 };
    void** gc_raw_roots[6] = { &l0, &l3, &l12, &l14, &l16, &t0 };
    vader_string_t* gc_atom_roots[5] = { &l18, &l19, &l20, &l21, &t4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 5u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l1.tag == 1106u) {
        l3 = l1.payload.obj;
        vader_midir_emit_const_instr(l0, l3, l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 1118u) {
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrMove_t*) t0)->f_src;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrMove_t*) t0)->f_span;
        vader_midir_emit_first_get(l0, l2, l4, l3);
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrMove_t*) t0)->f_src;
        l3 = ((vader_struct_vader_midir_CFGFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_fn_)->f_locals;
        t0 = l1.payload.obj;
        l5 = ((int64_t) (int32_t) ((vader_struct_vader_midir_InstrMove_t*) t0)->f_dst);
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
        l6 = vader_midir_is_boxed_slot(((vader_struct_vader_midir_CFGLocal_t*) t0)->f_type);
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrMove_t*) t0)->f_span;
        vader_midir_emit_retag_into(l0, l4, l6, l3);
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrMove_t*) t0)->f_dst;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrMove_t*) t0)->f_span;
        vader_midir_emit_result(l0, l2, l4, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 1099u) {
        l3 = ((vader_struct_vader_midir_CFGFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_fn_)->f_locals;
        t0 = l1.payload.obj;
        l5 = ((int64_t) (int32_t) ((vader_struct_vader_midir_InstrBinOp_t*) t0)->f_lhs);
        vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
        t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5);
        l7 = ((vader_struct_vader_midir_CFGLocal_t*) t0)->f_type;
        l3 = ((vader_struct_vader_midir_CFGFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_fn_)->f_locals;
        t0 = l1.payload.obj;
        l5 = ((int64_t) (int32_t) ((vader_struct_vader_midir_InstrBinOp_t*) t0)->f_rhs);
        vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l5)
        t0 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l5);
        l8 = ((vader_struct_vader_midir_CFGLocal_t*) t0)->f_type;
        t0 = l1.payload.obj;
        l6 = vader_midir_compares_boxes(((vader_struct_vader_midir_InstrBinOp_t*) t0)->f_op, l8);
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrBinOp_t*) t0)->f_lhs;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrBinOp_t*) t0)->f_span;
        vader_midir_emit_first_get(l0, l2, l4, l3);
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrBinOp_t*) t0)->f_lhs;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrBinOp_t*) t0)->f_span;
        vader_midir_emit_retag_into(l0, l4, l6, l3);
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrBinOp_t*) t0)->f_rhs;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrBinOp_t*) t0)->f_span;
        vader_midir_emit_get(l0, l4, l3);
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrBinOp_t*) t0)->f_rhs;
        t0 = l1.payload.obj;
        l9 = vader_midir_compares_boxes(((vader_struct_vader_midir_InstrBinOp_t*) t0)->f_op, l7);
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrBinOp_t*) t0)->f_span;
        vader_midir_emit_retag_into(l0, l4, l9, l3);
        if (!(l6)) {
            l8 = l7;
        }
        t0 = l1.payload.obj;
        l10 = ((vader_struct_vader_midir_InstrBinOp_t*) t0)->f_op;
        l11 = vader_bytecode_val_type_of_type(l8);
        l7 = vader_bytecode_binary_op_for(l10, l11);
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrBinOp_t*) t0)->f_span;
        vader_midir_push_emit(l0, l7, l3);
        t0 = l1.payload.obj;
        l10 = vader_bytecode_val_type_of_type(((vader_struct_vader_midir_InstrBinOp_t*) t0)->f_type);
        t0 = l1.payload.obj;
        t1 = vader_midir_binary_leaves_width(((vader_struct_vader_midir_InstrBinOp_t*) t0)->f_op, l10);
        if (t1) {
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir_InstrBinOp_t*) t0)->f_span;
            vader_midir_emit_narrowing(l0, l10, l3);
        }
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrBinOp_t*) t0)->f_dst;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrBinOp_t*) t0)->f_span;
        vader_midir_emit_result(l0, l2, l4, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 1100u) {
        l3 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_pinned_types_bucket;
        t0 = l1.payload.obj;
        l12 = ((vader_struct_vader_midir_InstrCall_t*) t0)->f_args;
        l5 = ((vader_array_t*) l12)->length;
        l13 = INT64_C(0);
        while ((l13 < l5)) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l12);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            l4 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l13];
            l14 = ((vader_struct_vader_midir_CFGFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_fn_)->f_locals;
            l15 = ((int64_t) (int32_t) l4);
            vader_array_t* _a4_slotarr = ((vader_array_t*) l14);
            VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l15)
            t0 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l15);
            l7 = ((vader_struct_vader_midir_CFGLocal_t*) t0)->f_type;
            l16 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project;
            l17 = vader_bytecode_intern_type(l7, l16);
            vader_array_push_i32((vader_array_t*) l3, l17);
            l13 = (l13 + INT64_C(1));
        }
        t0 = l1.payload.obj;
        l12 = ((vader_struct_vader_midir_InstrCall_t*) t0)->f_dsts;
        l5 = ((vader_array_t*) l12)->length;
        l13 = INT64_C(0);
        while ((l13 < l5)) {
            vader_array_t* _a5_slotarr = ((vader_array_t*) l12);
            VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
            l4 = ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l13];
            l14 = ((vader_struct_vader_midir_CFGFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_fn_)->f_locals;
            l15 = ((int64_t) (int32_t) l4);
            vader_array_t* _a6_slotarr = ((vader_array_t*) l14);
            VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l15)
            t0 = vader_array_ref_load_obj(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l15);
            l7 = ((vader_struct_vader_midir_CFGLocal_t*) t0)->f_type;
            l16 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project;
            l17 = vader_bytecode_intern_type(l7, l16);
            vader_array_push_i32((vader_array_t*) l3, l17);
            l13 = (l13 + INT64_C(1));
        }
        l3 = l1.payload.obj;
        l3 = vader_midir_resolve_direct_call(l0, l3);
        l12 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project;
        l14 = ((vader_struct_vader_midir_DirectCallTarget_t*) l3)->f_signature;
        l12 = vader_midir_boxed_params_of(l12, l14);
        t0 = l1.payload.obj;
        l14 = ((vader_struct_vader_midir_InstrCall_t*) t0)->f_args;
        t0 = l1.payload.obj;
        l16 = ((vader_struct_vader_midir_InstrCall_t*) t0)->f_span;
        vader_midir_emit_operands_into(l0, l2, l14, l12, l16);
        l7 = ((vader_struct_vader_midir_DirectCallTarget_t*) l3)->f_op;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrCall_t*) t0)->f_span;
        vader_midir_push_emit(l0, l7, l3);
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrCall_t*) t0)->f_dsts;
        t0 = l1.payload.obj;
        l12 = ((vader_struct_vader_midir_InstrCall_t*) t0)->f_span;
        vader_midir_emit_call_results(l0, l2, l3, l12);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 1122u) {
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrUnOp_t*) t0)->f_operand;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrUnOp_t*) t0)->f_span;
        vader_midir_emit_first_get(l0, l2, l4, l3);
        l3 = ((vader_struct_vader_midir_CFGFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_fn_)->f_locals;
        t0 = l1.payload.obj;
        l5 = ((int64_t) (int32_t) ((vader_struct_vader_midir_InstrUnOp_t*) t0)->f_operand);
        vader_array_t* _a7_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l5)
        t0 = vader_array_ref_load_obj(_a7_slotarr->buf, _a7_slotarr->offset + (size_t) l5);
        l10 = vader_bytecode_val_type_of_type(((vader_struct_vader_midir_CFGLocal_t*) t0)->f_type);
        t0 = l1.payload.obj;
        l7 = vader_bytecode_unary_op_for(((vader_struct_vader_midir_InstrUnOp_t*) t0)->f_op, l10);
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrUnOp_t*) t0)->f_span;
        vader_midir_push_emit(l0, l7, l3);
        t0 = l1.payload.obj;
        t1 = vader_midir_unary_leaves_width(((vader_struct_vader_midir_InstrUnOp_t*) t0)->f_op, l10);
        if (t1) {
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir_InstrUnOp_t*) t0)->f_span;
            vader_midir_emit_narrowing(l0, l10, l3);
        }
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrUnOp_t*) t0)->f_dst;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrUnOp_t*) t0)->f_span;
        vader_midir_emit_result(l0, l2, l4, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 1101u) {
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrCallIndirect_t*) t0)->f_args;
        t0 = l1.payload.obj;
        l12 = vader_midir_every_operand_boxed(((vader_struct_vader_midir_InstrCallIndirect_t*) t0)->f_args);
        t0 = l1.payload.obj;
        l14 = ((vader_struct_vader_midir_InstrCallIndirect_t*) t0)->f_span;
        vader_midir_emit_operands_into(l0, l2, l3, l12, l14);
        t0 = l1.payload.obj;
        t2 = ((vader_array_t*) ((vader_struct_vader_midir_InstrCallIndirect_t*) t0)->f_args)->length;
        if (t2 == INT64_C(0)) {
            t0 = l1.payload.obj;
            l4 = ((vader_struct_vader_midir_InstrCallIndirect_t*) t0)->f_callee;
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir_InstrCallIndirect_t*) t0)->f_span;
            vader_midir_emit_first_get(l0, l2, l4, l3);
        } else {
            t0 = l1.payload.obj;
            l4 = ((vader_struct_vader_midir_InstrCallIndirect_t*) t0)->f_callee;
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir_InstrCallIndirect_t*) t0)->f_span;
            vader_midir_emit_get(l0, l4, l3);
        }
        t0 = l1.payload.obj;
        l7 = ((vader_struct_vader_midir_InstrCallIndirect_t*) t0)->f_fn_type;
        l3 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project;
        t3 = vader_bytecode_intern_type(l7, l3);
        vader_struct_vader_bytecode_CallIndirect_t* _a8_obj = (vader_struct_vader_bytecode_CallIndirect_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_CallIndirect_t));
        vader_obj_header_init(_a8_obj, 676u);
        _a8_obj->f_type_id = t3;
        l3 = (void*) _a8_obj;
        t0 = l1.payload.obj;
        l12 = ((vader_struct_vader_midir_InstrCallIndirect_t*) t0)->f_span;
        vader_midir_push_emit(l0, vader_ref_box(l3), l12);
        t0 = l1.payload.obj;
        l7 = ((vader_struct_vader_midir_InstrCallIndirect_t*) t0)->f_dst;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrCallIndirect_t*) t0)->f_span;
        vader_midir_emit_result_if_any(l0, l2, l7, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 1113u) {
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrFnRef_t*) t0)->f_fn_symbol;
        l12 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project;
        l7 = vader_midir_resolve_fn_index(l3, l12);
        if (!(l7.tag == 288u)) {
            t0 = l1.payload.obj;
            l18 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_midir_InstrFnRef_t*) t0)->f_fn_symbol)->f_name;
            l5 = vader_host_std_core_byte_len(l18);
            l14 = (void*) vader_buffer_new((size_t) (INT64_C(104) + l5));
            l5 = INT64_C(0);
            l5 = std_core_write_string_at(l14, l5, 2135u);
            l5 = std_core_write_string_at(l14, l5, l18);
            l5 = std_core_write_string_at(l14, l5, 234u);
            t0 = l1.payload.obj;
            t3 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_midir_InstrFnRef_t*) t0)->f_fn_symbol)->f_id;
            l13 = ((int64_t) (int32_t) t3);
            l5 = std_core_write_int(l14, l5, l13);
            l5 = std_core_write_string_at(l14, l5, 284u);
            t4 = std_core_finish_buffer(l14, l5);
            vader_host_std_abort_panic(t4);
            vader_unreachable("a no-return call returned");
        }
        t0 = l1.payload.obj;
        l8 = ((vader_struct_vader_midir_InstrFnRef_t*) t0)->f_type;
        l3 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project;
        l4 = vader_bytecode_intern_type(l8, l3);
        t3 = ((int32_t) l7.payload.i);
        vader_struct_vader_bytecode_FnRef_t* _a9_obj = (vader_struct_vader_bytecode_FnRef_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_FnRef_t));
        vader_obj_header_init(_a9_obj, 705u);
        _a9_obj->f_function_index = t3;
        _a9_obj->f_type_id = l4;
        l3 = (void*) _a9_obj;
        t0 = l1.payload.obj;
        l12 = ((vader_struct_vader_midir_InstrFnRef_t*) t0)->f_span;
        vader_midir_push_emit(l0, vader_ref_box(l3), l12);
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrFnRef_t*) t0)->f_dst;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrFnRef_t*) t0)->f_span;
        vader_midir_emit_result(l0, l2, l4, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 1112u) {
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrFnAddr_t*) t0)->f_fn_symbol;
        l12 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project;
        l7 = vader_midir_resolve_fn_index(l3, l12);
        if (!(l7.tag == 288u)) {
            t0 = l1.payload.obj;
            l18 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_midir_InstrFnAddr_t*) t0)->f_fn_symbol)->f_name;
            l5 = vader_host_std_core_byte_len(l18);
            l14 = (void*) vader_buffer_new((size_t) (INT64_C(102) + l5));
            l5 = INT64_C(0);
            l5 = std_core_write_string_at(l14, l5, 2134u);
            l5 = std_core_write_string_at(l14, l5, l18);
            l5 = std_core_write_string_at(l14, l5, 234u);
            t0 = l1.payload.obj;
            t3 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_midir_InstrFnAddr_t*) t0)->f_fn_symbol)->f_id;
            l13 = ((int64_t) (int32_t) t3);
            l5 = std_core_write_int(l14, l5, l13);
            l5 = std_core_write_string_at(l14, l5, 283u);
            t4 = std_core_finish_buffer(l14, l5);
            vader_host_std_abort_panic(t4);
            vader_unreachable("a no-return call returned");
        }
        t3 = ((int32_t) l7.payload.i);
        vader_struct_vader_bytecode_FnAddr_t* _a10_obj = (vader_struct_vader_bytecode_FnAddr_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_FnAddr_t));
        vader_obj_header_init(_a10_obj, 704u);
        _a10_obj->f_function_index = t3;
        l3 = (void*) _a10_obj;
        t0 = l1.payload.obj;
        l12 = ((vader_struct_vader_midir_InstrFnAddr_t*) t0)->f_span;
        vader_midir_push_emit(l0, vader_ref_box(l3), l12);
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrFnAddr_t*) t0)->f_dst;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrFnAddr_t*) t0)->f_span;
        vader_midir_emit_result(l0, l2, l4, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 1125u) {
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrVirtualCall_t*) t0)->f_args;
        t0 = l1.payload.obj;
        l12 = vader_midir_every_operand_boxed(((vader_struct_vader_midir_InstrVirtualCall_t*) t0)->f_args);
        t0 = l1.payload.obj;
        l14 = ((vader_struct_vader_midir_InstrVirtualCall_t*) t0)->f_span;
        vader_midir_emit_operands_into(l0, l2, l3, l12, l14);
        t0 = l1.payload.obj;
        t2 = ((vader_array_t*) ((vader_struct_vader_midir_InstrVirtualCall_t*) t0)->f_args)->length;
        if (t2 == INT64_C(0)) {
            t0 = l1.payload.obj;
            l4 = ((vader_struct_vader_midir_InstrVirtualCall_t*) t0)->f_receiver;
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir_InstrVirtualCall_t*) t0)->f_span;
            vader_midir_emit_first_get(l0, l2, l4, l3);
        } else {
            t0 = l1.payload.obj;
            l4 = ((vader_struct_vader_midir_InstrVirtualCall_t*) t0)->f_receiver;
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir_InstrVirtualCall_t*) t0)->f_span;
            vader_midir_emit_get(l0, l4, l3);
        }
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrVirtualCall_t*) t0)->f_receiver;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrVirtualCall_t*) t0)->f_span;
        vader_midir_emit_retag_into(l0, l4, true, l3);
        t0 = l1.payload.obj;
        t2 = ((vader_array_t*) ((vader_struct_vader_midir_InstrVirtualCall_t*) t0)->f_args)->length;
        t5 = vader_chk_add(i64, t2, INT64_C(1));
        l4 = ((int32_t) (int64_t) t5);
        t0 = l1.payload.obj;
        l18 = ((vader_struct_vader_midir_InstrVirtualCall_t*) t0)->f_trait_name;
        t0 = l1.payload.obj;
        l19 = ((vader_struct_vader_midir_InstrVirtualCall_t*) t0)->f_method;
        l18 = vader_midir_vtable_key(l18, l19);
        vader_struct_vader_bytecode_VirtualCall_t* _a11_obj = (vader_struct_vader_bytecode_VirtualCall_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_VirtualCall_t));
        vader_obj_header_init(_a11_obj, 805u);
        _a11_obj->f_parameter_count = l4;
        _a11_obj->f_vtable_key = l18;
        l3 = (void*) _a11_obj;
        t0 = l1.payload.obj;
        l12 = ((vader_struct_vader_midir_InstrVirtualCall_t*) t0)->f_span;
        vader_midir_push_emit(l0, vader_ref_box(l3), l12);
        t0 = l1.payload.obj;
        l7 = ((vader_struct_vader_midir_InstrVirtualCall_t*) t0)->f_dst;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrVirtualCall_t*) t0)->f_span;
        vader_midir_emit_result_if_any(l0, l2, l7, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 1110u) {
        l3 = ((vader_struct_vader_midir_CFGFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_fn_)->f_locals;
        t0 = l1.payload.obj;
        l5 = ((int64_t) (int32_t) ((vader_struct_vader_midir_InstrFieldGet_t*) t0)->f_target);
        vader_array_t* _a12_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a12_slotarr, l5)
        l3 = vader_array_ref_load_obj(_a12_slotarr->buf, _a12_slotarr->offset + (size_t) l5);
        l7 = ((vader_struct_vader_midir_CFGLocal_t*) l3)->f_type;
        l12 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project;
        l4 = vader_bytecode_intern_type(l7, l12);
        l6 = std_collections_MutableSet_std_core_Contains_contains__i64(((vader_struct_vader_midir_ScheduleHints_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_hints)->f_skip_first_get, l2);
        t0 = l1.payload.obj;
        l17 = ((vader_struct_vader_midir_InstrFieldGet_t*) t0)->f_target;
        t0 = l1.payload.obj;
        l12 = ((vader_struct_vader_midir_InstrFieldGet_t*) t0)->f_span;
        vader_midir_emit_first_get(l0, l2, l17, l12);
        l12 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project;
        t0 = l1.payload.obj;
        l18 = ((vader_struct_vader_midir_InstrFieldGet_t*) t0)->f_field;
        l8 = vader_midir_find_struct_field_index(l12, l4, l18);
        if (l8.tag == 0u) {
            t0 = l1.payload.obj;
            l18 = ((vader_struct_vader_midir_InstrFieldGet_t*) t0)->f_field;
            l19 = vader_types_display_type(l7);
            l20 = ((vader_struct_vader_midir_CFGLocal_t*) l3)->f_name;
            l21 = ((vader_struct_vader_midir_CFGFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_fn_)->f_mangled;
            l5 = vader_host_std_core_byte_len(l18);
            l13 = vader_host_std_core_byte_len(l19);
            l5 = (l5 + l13);
            l13 = vader_host_std_core_byte_len(l20);
            l5 = (l5 + l13);
            l13 = vader_host_std_core_byte_len(l21);
            l5 = (l5 + l13);
            l3 = (void*) vader_buffer_new((size_t) (INT64_C(173) + l5));
            l5 = INT64_C(0);
            l5 = std_core_write_string_at(l3, l5, 2129u);
            l5 = std_core_write_string_at(l3, l5, l18);
            l5 = std_core_write_string_at(l3, l5, 1066u);
            l5 = std_core_write_string_at(l3, l5, l19);
            l5 = std_core_write_string_at(l3, l5, 914u);
            t0 = l1.payload.obj;
            l13 = ((int64_t) (int32_t) ((vader_struct_vader_midir_InstrFieldGet_t*) t0)->f_target);
            l5 = std_core_write_int(l3, l5, l13);
            l5 = std_core_write_string_at(l3, l5, 56u);
            l5 = std_core_write_string_at(l3, l5, l20);
            l5 = std_core_write_string_at(l3, l5, 1132u);
            l5 = std_core_write_string_at(l3, l5, l21);
            l5 = std_core_write_string_at(l3, l5, 245u);
            t4 = std_core_finish_buffer(l3, l5);
            vader_host_std_abort_panic(t4);
            vader_unreachable("a no-return call returned");
        } else {
            t2 = ((int64_t) l8.payload.i);
            l17 = ((int32_t) (int64_t) t2);
            l9 = false;
            if (!(l6)) {
                l9 = vader_midir_try_fuse_local_field(l0, l4, l17);
            }
            if (!(l9)) {
                vader_struct_vader_bytecode_StructGet_t* _a13_obj = (vader_struct_vader_bytecode_StructGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_StructGet_t));
                vader_obj_header_init(_a13_obj, 785u);
                _a13_obj->f_type_id = l4;
                _a13_obj->f_field_index = l17;
                l3 = (void*) _a13_obj;
                t0 = l1.payload.obj;
                l12 = ((vader_struct_vader_midir_InstrFieldGet_t*) t0)->f_span;
                vader_midir_push_emit(l0, vader_ref_box(l3), l12);
            }
            t0 = l1.payload.obj;
            t1 = vader_midir_needs_ref_cast(((vader_struct_vader_midir_InstrFieldGet_t*) t0)->f_type);
            if (t1) {
                t0 = l1.payload.obj;
                l7 = ((vader_struct_vader_midir_InstrFieldGet_t*) t0)->f_type;
                l3 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project;
                t3 = vader_bytecode_intern_type(l7, l3);
                vader_struct_vader_bytecode_RefCast_t* _a14_obj = (vader_struct_vader_bytecode_RefCast_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_RefCast_t));
                vader_obj_header_init(_a14_obj, 766u);
                _a14_obj->f_type_id = t3;
                l3 = (void*) _a14_obj;
                t0 = l1.payload.obj;
                l12 = ((vader_struct_vader_midir_InstrFieldGet_t*) t0)->f_span;
                vader_midir_push_emit(l0, vader_ref_box(l3), l12);
            }
            t0 = l1.payload.obj;
            l4 = ((vader_struct_vader_midir_InstrFieldGet_t*) t0)->f_dst;
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir_InstrFieldGet_t*) t0)->f_span;
            vader_midir_emit_result(l0, l2, l4, l3);
            { vader_gc_top = gc_frame.prev; return; }
        }
    } else if (l1.tag == 1111u) {
        l3 = ((vader_struct_vader_midir_CFGFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_fn_)->f_locals;
        t0 = l1.payload.obj;
        l5 = ((int64_t) (int32_t) ((vader_struct_vader_midir_InstrFieldSet_t*) t0)->f_target);
        vader_array_t* _a15_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a15_slotarr, l5)
        t0 = vader_array_ref_load_obj(_a15_slotarr->buf, _a15_slotarr->offset + (size_t) l5);
        l7 = ((vader_struct_vader_midir_CFGLocal_t*) t0)->f_type;
        l3 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project;
        l4 = vader_bytecode_intern_type(l7, l3);
        l3 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project;
        t0 = l1.payload.obj;
        l18 = ((vader_struct_vader_midir_InstrFieldSet_t*) t0)->f_field;
        l8 = vader_midir_find_struct_field_index(l3, l4, l18);
        if (!(l8.tag == 0u)) {
            t0 = l1.payload.obj;
            l17 = ((vader_struct_vader_midir_InstrFieldSet_t*) t0)->f_target;
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir_InstrFieldSet_t*) t0)->f_span;
            vader_midir_emit_first_get(l0, l2, l17, l3);
            t0 = l1.payload.obj;
            l17 = ((vader_struct_vader_midir_InstrFieldSet_t*) t0)->f_value;
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir_InstrFieldSet_t*) t0)->f_span;
            vader_midir_emit_get(l0, l17, l3);
            t0 = l1.payload.obj;
            l17 = ((vader_struct_vader_midir_InstrFieldSet_t*) t0)->f_value;
            l3 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project;
            l5 = ((int64_t) l8.payload.i);
            l6 = vader_midir_boxed_field(l3, l4, l5);
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir_InstrFieldSet_t*) t0)->f_span;
            vader_midir_emit_retag_into(l0, l17, l6, l3);
            t2 = ((int64_t) l8.payload.i);
            l17 = ((int32_t) (int64_t) t2);
            t0 = l1.payload.obj;
            l6 = ((vader_struct_vader_midir_InstrFieldSet_t*) t0)->f_barrierless;
            vader_struct_vader_bytecode_StructSet_t* _a16_obj = (vader_struct_vader_bytecode_StructSet_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_StructSet_t));
            vader_obj_header_init(_a16_obj, 787u);
            _a16_obj->f_type_id = l4;
            _a16_obj->f_field_index = l17;
            _a16_obj->f_stack = l6;
            l3 = (void*) _a16_obj;
            t0 = l1.payload.obj;
            l12 = ((vader_struct_vader_midir_InstrFieldSet_t*) t0)->f_span;
            vader_midir_push_emit(l0, vader_ref_box(l3), l12);
            { vader_gc_top = gc_frame.prev; return; }
        }
        t0 = l1.payload.obj;
        l18 = ((vader_struct_vader_midir_InstrFieldSet_t*) t0)->f_field;
        l19 = vader_types_display_type(l7);
        l20 = ((vader_struct_vader_midir_CFGFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_fn_)->f_mangled;
        t4 = concat_7(2129u, l18, 1066u, l19, 987u, l20, 247u);
        vader_host_std_abort_panic(t4);
        vader_unreachable("a no-return call returned");
    } else if (l1.tag == 1123u) {
        l3 = ((vader_struct_vader_midir_CFGFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_fn_)->f_locals;
        t0 = l1.payload.obj;
        l5 = ((int64_t) (int32_t) ((vader_struct_vader_midir_InstrUnionFieldGet_t*) t0)->f_target);
        vader_array_t* _a17_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a17_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a17_slotarr, l5)
        t0 = vader_array_ref_load_obj(_a17_slotarr->buf, _a17_slotarr->offset + (size_t) l5);
        l7 = ((vader_struct_vader_midir_CFGLocal_t*) t0)->f_type;
        l3 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project;
        l4 = vader_bytecode_intern_type(l7, l3);
        l8 = vader_bytecode_union_layout_struct(((vader_struct_vader_bytecode_EmitterCtx_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project)->f_types, l4);
        if (l8.tag == 0u) {
            t0 = l1.payload.obj;
            l18 = ((vader_struct_vader_midir_InstrUnionFieldGet_t*) t0)->f_field;
            t4 = vader_midir_no_common_field(l0, l18, l7);
            vader_host_std_abort_panic(t4);
            vader_unreachable("a no-return call returned");
        } else {
            l17 = ((int32_t) l8.payload.i);
            l3 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project;
            t0 = l1.payload.obj;
            l18 = ((vader_struct_vader_midir_InstrUnionFieldGet_t*) t0)->f_field;
            l8 = vader_midir_find_struct_field_index(l3, l17, l18);
            if (l8.tag == 0u) {
                t0 = l1.payload.obj;
                l18 = ((vader_struct_vader_midir_InstrUnionFieldGet_t*) t0)->f_field;
                t4 = vader_midir_no_common_field(l0, l18, l7);
                vader_host_std_abort_panic(t4);
                vader_unreachable("a no-return call returned");
            } else {
                l5 = ((int64_t) l8.payload.i);
                t0 = l1.payload.obj;
                l17 = ((vader_struct_vader_midir_InstrUnionFieldGet_t*) t0)->f_target;
                t0 = l1.payload.obj;
                l3 = ((vader_struct_vader_midir_InstrUnionFieldGet_t*) t0)->f_span;
                vader_midir_emit_first_get(l0, l2, l17, l3);
                l17 = ((int32_t) (int64_t) l5);
                vader_struct_vader_bytecode_UnionFieldGet_t* _a18_obj = (vader_struct_vader_bytecode_UnionFieldGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_UnionFieldGet_t));
                vader_obj_header_init(_a18_obj, 802u);
                _a18_obj->f_type_id = l4;
                _a18_obj->f_field_index = l17;
                l3 = (void*) _a18_obj;
                t0 = l1.payload.obj;
                l12 = ((vader_struct_vader_midir_InstrUnionFieldGet_t*) t0)->f_span;
                vader_midir_push_emit(l0, vader_ref_box(l3), l12);
                t0 = l1.payload.obj;
                t1 = vader_midir_needs_ref_cast(((vader_struct_vader_midir_InstrUnionFieldGet_t*) t0)->f_type);
                if (t1) {
                    t0 = l1.payload.obj;
                    l7 = ((vader_struct_vader_midir_InstrUnionFieldGet_t*) t0)->f_type;
                    l3 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project;
                    t3 = vader_bytecode_intern_type(l7, l3);
                    vader_struct_vader_bytecode_RefCast_t* _a19_obj = (vader_struct_vader_bytecode_RefCast_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_RefCast_t));
                    vader_obj_header_init(_a19_obj, 766u);
                    _a19_obj->f_type_id = t3;
                    l3 = (void*) _a19_obj;
                    t0 = l1.payload.obj;
                    l12 = ((vader_struct_vader_midir_InstrUnionFieldGet_t*) t0)->f_span;
                    vader_midir_push_emit(l0, vader_ref_box(l3), l12);
                }
                t0 = l1.payload.obj;
                l4 = ((vader_struct_vader_midir_InstrUnionFieldGet_t*) t0)->f_dst;
                t0 = l1.payload.obj;
                l3 = ((vader_struct_vader_midir_InstrUnionFieldGet_t*) t0)->f_span;
                vader_midir_emit_result(l0, l2, l4, l3);
                { vader_gc_top = gc_frame.prev; return; }
            }
        }
    } else if (l1.tag == 1124u) {
        l3 = ((vader_struct_vader_midir_CFGFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_fn_)->f_locals;
        t0 = l1.payload.obj;
        l5 = ((int64_t) (int32_t) ((vader_struct_vader_midir_InstrUnionFieldSet_t*) t0)->f_target);
        vader_array_t* _a20_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a20_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a20_slotarr, l5)
        t0 = vader_array_ref_load_obj(_a20_slotarr->buf, _a20_slotarr->offset + (size_t) l5);
        l7 = ((vader_struct_vader_midir_CFGLocal_t*) t0)->f_type;
        l3 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project;
        l4 = vader_bytecode_intern_type(l7, l3);
        l8 = vader_bytecode_union_layout_struct(((vader_struct_vader_bytecode_EmitterCtx_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project)->f_types, l4);
        if (l8.tag == 0u) {
            t0 = l1.payload.obj;
            l18 = ((vader_struct_vader_midir_InstrUnionFieldSet_t*) t0)->f_field;
            t4 = vader_midir_no_common_field(l0, l18, l7);
            vader_host_std_abort_panic(t4);
            vader_unreachable("a no-return call returned");
        } else {
            l17 = ((int32_t) l8.payload.i);
            l3 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project;
            t0 = l1.payload.obj;
            l18 = ((vader_struct_vader_midir_InstrUnionFieldSet_t*) t0)->f_field;
            l8 = vader_midir_find_struct_field_index(l3, l17, l18);
            if (l8.tag == 0u) {
                t0 = l1.payload.obj;
                l18 = ((vader_struct_vader_midir_InstrUnionFieldSet_t*) t0)->f_field;
                t4 = vader_midir_no_common_field(l0, l18, l7);
                vader_host_std_abort_panic(t4);
                vader_unreachable("a no-return call returned");
            } else {
                l5 = ((int64_t) l8.payload.i);
                t0 = l1.payload.obj;
                l22 = ((vader_struct_vader_midir_InstrUnionFieldSet_t*) t0)->f_target;
                t0 = l1.payload.obj;
                l3 = ((vader_struct_vader_midir_InstrUnionFieldSet_t*) t0)->f_span;
                vader_midir_emit_first_get(l0, l2, l22, l3);
                t0 = l1.payload.obj;
                l22 = ((vader_struct_vader_midir_InstrUnionFieldSet_t*) t0)->f_value;
                t0 = l1.payload.obj;
                l3 = ((vader_struct_vader_midir_InstrUnionFieldSet_t*) t0)->f_span;
                vader_midir_emit_get(l0, l22, l3);
                t0 = l1.payload.obj;
                l22 = ((vader_struct_vader_midir_InstrUnionFieldSet_t*) t0)->f_value;
                l6 = vader_midir_boxed_field(((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project, l17, l5);
                t0 = l1.payload.obj;
                l3 = ((vader_struct_vader_midir_InstrUnionFieldSet_t*) t0)->f_span;
                vader_midir_emit_retag_into(l0, l22, l6, l3);
                l17 = ((int32_t) (int64_t) l5);
                vader_struct_vader_bytecode_UnionFieldSet_t* _a21_obj = (vader_struct_vader_bytecode_UnionFieldSet_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_UnionFieldSet_t));
                vader_obj_header_init(_a21_obj, 803u);
                _a21_obj->f_type_id = l4;
                _a21_obj->f_field_index = l17;
                l3 = (void*) _a21_obj;
                t0 = l1.payload.obj;
                l12 = ((vader_struct_vader_midir_InstrUnionFieldSet_t*) t0)->f_span;
                vader_midir_push_emit(l0, vader_ref_box(l3), l12);
                { vader_gc_top = gc_frame.prev; return; }
            }
        }
    } else {
        if (l1.tag == 1093u) {
            l3 = ((vader_struct_vader_midir_CFGFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_fn_)->f_locals;
            t0 = l1.payload.obj;
            l5 = ((int64_t) (int32_t) ((vader_struct_vader_midir_InstrArrayGet_t*) t0)->f_target);
            vader_array_t* _a22_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a22_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a22_slotarr, l5)
            t0 = vader_array_ref_load_obj(_a22_slotarr->buf, _a22_slotarr->offset + (size_t) l5);
            l7 = ((vader_struct_vader_midir_CFGLocal_t*) t0)->f_type;
            l3 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project;
            l4 = vader_bytecode_intern_type(l7, l3);
            t0 = l1.payload.obj;
            l17 = ((vader_struct_vader_midir_InstrArrayGet_t*) t0)->f_target;
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir_InstrArrayGet_t*) t0)->f_span;
            vader_midir_emit_first_get(l0, l2, l17, l3);
            t0 = l1.payload.obj;
            l17 = ((vader_struct_vader_midir_InstrArrayGet_t*) t0)->f_index;
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir_InstrArrayGet_t*) t0)->f_span;
            vader_midir_emit_get(l0, l17, l3);
            l10 = vader_midir_array_element_val_type(l7);
            t0 = l1.payload.obj;
            l6 = ((vader_struct_vader_midir_InstrArrayGet_t*) t0)->f_bounds_safe;
            l7 = vader_bytecode_slot_load_op_for(l10, l6);
            if (l7.tag == 0u) {
                t0 = l1.payload.obj;
                l6 = ((vader_struct_vader_midir_InstrArrayGet_t*) t0)->f_bounds_safe;
                vader_struct_vader_bytecode_ArrayGet_t* _a23_obj = (vader_struct_vader_bytecode_ArrayGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_ArrayGet_t));
                vader_obj_header_init(_a23_obj, 628u);
                _a23_obj->f_type_id = l4;
                _a23_obj->f_bounds_safe = l6;
                l3 = (void*) _a23_obj;
                t0 = l1.payload.obj;
                l12 = ((vader_struct_vader_midir_InstrArrayGet_t*) t0)->f_span;
                vader_midir_push_emit(l0, vader_ref_box(l3), l12);
                t0 = l1.payload.obj;
                t1 = vader_midir_needs_ref_cast(((vader_struct_vader_midir_InstrArrayGet_t*) t0)->f_type);
                if (t1) {
                    t0 = l1.payload.obj;
                    l8 = ((vader_struct_vader_midir_InstrArrayGet_t*) t0)->f_type;
                    l3 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project;
                    t3 = vader_bytecode_intern_type(l8, l3);
                    vader_struct_vader_bytecode_RefCast_t* _a24_obj = (vader_struct_vader_bytecode_RefCast_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_RefCast_t));
                    vader_obj_header_init(_a24_obj, 766u);
                    _a24_obj->f_type_id = t3;
                    l3 = (void*) _a24_obj;
                    t0 = l1.payload.obj;
                    l12 = ((vader_struct_vader_midir_InstrArrayGet_t*) t0)->f_span;
                    vader_midir_push_emit(l0, vader_ref_box(l3), l12);
                }
            } else {
                t0 = l1.payload.obj;
                l3 = ((vader_struct_vader_midir_InstrArrayGet_t*) t0)->f_span;
                vader_midir_push_emit(l0, l7, l3);
            }
            t0 = l1.payload.obj;
            l4 = ((vader_struct_vader_midir_InstrArrayGet_t*) t0)->f_dst;
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir_InstrArrayGet_t*) t0)->f_span;
            vader_midir_emit_result(l0, l2, l4, l3);
            { vader_gc_top = gc_frame.prev; return; }
        }
        if (l1.tag == 1097u) {
            l3 = ((vader_struct_vader_midir_CFGFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_fn_)->f_locals;
            t0 = l1.payload.obj;
            l5 = ((int64_t) (int32_t) ((vader_struct_vader_midir_InstrArraySet_t*) t0)->f_target);
            vader_array_t* _a25_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a25_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a25_slotarr, l5)
            t0 = vader_array_ref_load_obj(_a25_slotarr->buf, _a25_slotarr->offset + (size_t) l5);
            l7 = ((vader_struct_vader_midir_CFGLocal_t*) t0)->f_type;
            l3 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project;
            l4 = vader_bytecode_intern_type(l7, l3);
            t0 = l1.payload.obj;
            l17 = ((vader_struct_vader_midir_InstrArraySet_t*) t0)->f_target;
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir_InstrArraySet_t*) t0)->f_span;
            vader_midir_emit_first_get(l0, l2, l17, l3);
            t0 = l1.payload.obj;
            l17 = ((vader_struct_vader_midir_InstrArraySet_t*) t0)->f_index;
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir_InstrArraySet_t*) t0)->f_span;
            vader_midir_emit_get(l0, l17, l3);
            t0 = l1.payload.obj;
            l17 = ((vader_struct_vader_midir_InstrArraySet_t*) t0)->f_value;
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir_InstrArraySet_t*) t0)->f_span;
            vader_midir_emit_get(l0, l17, l3);
            t0 = l1.payload.obj;
            l17 = ((vader_struct_vader_midir_InstrArraySet_t*) t0)->f_value;
            l6 = vader_midir_boxed_element(l7);
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir_InstrArraySet_t*) t0)->f_span;
            vader_midir_emit_retag_into(l0, l17, l6, l3);
            l10 = vader_midir_array_element_val_type(l7);
            t0 = l1.payload.obj;
            l6 = ((vader_struct_vader_midir_InstrArraySet_t*) t0)->f_bounds_safe;
            l7 = vader_bytecode_slot_store_op_for(l10, l6);
            if (l7.tag == 0u) {
                t0 = l1.payload.obj;
                l6 = ((vader_struct_vader_midir_InstrArraySet_t*) t0)->f_bounds_safe;
                vader_struct_vader_bytecode_ArraySet_t* _a26_obj = (vader_struct_vader_bytecode_ArraySet_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_ArraySet_t));
                vader_obj_header_init(_a26_obj, 635u);
                _a26_obj->f_type_id = l4;
                _a26_obj->f_bounds_safe = l6;
                l3 = (void*) _a26_obj;
                t0 = l1.payload.obj;
                l12 = ((vader_struct_vader_midir_InstrArraySet_t*) t0)->f_span;
                vader_midir_push_emit(l0, vader_ref_box(l3), l12);
                { vader_gc_top = gc_frame.prev; return; }
            }
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir_InstrArraySet_t*) t0)->f_span;
            vader_midir_push_emit(l0, l7, l3);
            { vader_gc_top = gc_frame.prev; return; }
        }
        if (l1.tag == 1094u) {
            t0 = l1.payload.obj;
            l4 = ((vader_struct_vader_midir_InstrArrayLen_t*) t0)->f_target;
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir_InstrArrayLen_t*) t0)->f_span;
            vader_midir_emit_first_get(l0, l2, l4, l3);
            vader_struct_vader_bytecode_ArrayLen_t* _a27_obj = (vader_struct_vader_bytecode_ArrayLen_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_ArrayLen_t));
            vader_obj_header_init(_a27_obj, 629u);
            l3 = (void*) _a27_obj;
            t0 = l1.payload.obj;
            l12 = ((vader_struct_vader_midir_InstrArrayLen_t*) t0)->f_span;
            vader_midir_push_emit(l0, vader_ref_box(l3), l12);
            t0 = l1.payload.obj;
            l4 = ((vader_struct_vader_midir_InstrArrayLen_t*) t0)->f_dst;
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir_InstrArrayLen_t*) t0)->f_span;
            vader_midir_emit_result(l0, l2, l4, l3);
            { vader_gc_top = gc_frame.prev; return; }
        }
        if (l1.tag == 1096u) {
            l3 = ((vader_struct_vader_midir_CFGFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_fn_)->f_locals;
            t0 = l1.payload.obj;
            l5 = ((int64_t) (int32_t) ((vader_struct_vader_midir_InstrArrayPush_t*) t0)->f_target);
            vader_array_t* _a28_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a28_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a28_slotarr, l5)
            t0 = vader_array_ref_load_obj(_a28_slotarr->buf, _a28_slotarr->offset + (size_t) l5);
            l7 = ((vader_struct_vader_midir_CFGLocal_t*) t0)->f_type;
            l3 = ((vader_struct_vader_midir_CFGFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_fn_)->f_locals;
            t0 = l1.payload.obj;
            l5 = ((int64_t) (int32_t) ((vader_struct_vader_midir_InstrArrayPush_t*) t0)->f_value);
            vader_array_t* _a29_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a29_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a29_slotarr, l5)
            t0 = vader_array_ref_load_obj(_a29_slotarr->buf, _a29_slotarr->offset + (size_t) l5);
            l8 = ((vader_struct_vader_midir_CFGLocal_t*) t0)->f_type;
            l7 = vader_midir_pushed_element_type(l7, l8);
            t0 = l1.payload.obj;
            l4 = ((vader_struct_vader_midir_InstrArrayPush_t*) t0)->f_target;
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir_InstrArrayPush_t*) t0)->f_span;
            vader_midir_emit_first_get(l0, l2, l4, l3);
            t0 = l1.payload.obj;
            l4 = ((vader_struct_vader_midir_InstrArrayPush_t*) t0)->f_value;
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir_InstrArrayPush_t*) t0)->f_span;
            vader_midir_emit_get(l0, l4, l3);
            t0 = l1.payload.obj;
            l4 = ((vader_struct_vader_midir_InstrArrayPush_t*) t0)->f_value;
            l6 = vader_midir_is_boxed_slot(l7);
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir_InstrArrayPush_t*) t0)->f_span;
            vader_midir_emit_retag_into(l0, l4, l6, l3);
            t0 = l1.payload.obj;
            t1 = ((vader_struct_vader_midir_InstrArrayPush_t*) t0)->f_cached;
            if (t1) {
                l3 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_local_to_slot;
                t0 = l1.payload.obj;
                l5 = ((int64_t) (int32_t) ((vader_struct_vader_midir_InstrArrayPush_t*) t0)->f_target);
                vader_array_t* _a30_slotarr = ((vader_array_t*) l3);
                VADER_ARRAY_RESOLVE_BUF(_a30_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a30_slotarr, l5)
                l4 = ((int32_t*) _a30_slotarr->buf->slots)[_a30_slotarr->offset + (size_t) l5];
            } else {
                l4 = INT32_C(-1);
            }
            l3 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project;
            t3 = vader_bytecode_intern_type(l7, l3);
            vader_struct_vader_bytecode_ArrayPush_t* _a31_obj = (vader_struct_vader_bytecode_ArrayPush_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_ArrayPush_t));
            vader_obj_header_init(_a31_obj, 631u);
            _a31_obj->f_type_id = t3;
            _a31_obj->f_cache_slot = l4;
            l3 = (void*) _a31_obj;
            t0 = l1.payload.obj;
            l12 = ((vader_struct_vader_midir_InstrArrayPush_t*) t0)->f_span;
            vader_midir_push_emit(l0, vader_ref_box(l3), l12);
            { vader_gc_top = gc_frame.prev; return; }
        }
        if (l1.tag == 1098u) {
            t0 = l1.payload.obj;
            l7 = ((vader_struct_vader_midir_InstrArraySlice_t*) t0)->f_type;
            l3 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project;
            l4 = vader_bytecode_intern_type(l7, l3);
            t0 = l1.payload.obj;
            l17 = ((vader_struct_vader_midir_InstrArraySlice_t*) t0)->f_target;
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir_InstrArraySlice_t*) t0)->f_span;
            vader_midir_emit_first_get(l0, l2, l17, l3);
            t0 = l1.payload.obj;
            l17 = ((vader_struct_vader_midir_InstrArraySlice_t*) t0)->f_lo;
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir_InstrArraySlice_t*) t0)->f_span;
            vader_midir_emit_get(l0, l17, l3);
            t0 = l1.payload.obj;
            l17 = ((vader_struct_vader_midir_InstrArraySlice_t*) t0)->f_hi;
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir_InstrArraySlice_t*) t0)->f_span;
            vader_midir_emit_get(l0, l17, l3);
            vader_struct_vader_bytecode_ArraySlice_t* _a32_obj = (vader_struct_vader_bytecode_ArraySlice_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_ArraySlice_t));
            vader_obj_header_init(_a32_obj, 636u);
            _a32_obj->f_type_id = l4;
            l3 = (void*) _a32_obj;
            t0 = l1.payload.obj;
            l12 = ((vader_struct_vader_midir_InstrArraySlice_t*) t0)->f_span;
            vader_midir_push_emit(l0, vader_ref_box(l3), l12);
            t0 = l1.payload.obj;
            l4 = ((vader_struct_vader_midir_InstrArraySlice_t*) t0)->f_dst;
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir_InstrArraySlice_t*) t0)->f_span;
            vader_midir_emit_result(l0, l2, l4, l3);
            { vader_gc_top = gc_frame.prev; return; }
        }
        if (l1.tag == 1119u) {
            t0 = l1.payload.obj;
            l7 = ((vader_struct_vader_midir_InstrStructNew_t*) t0)->f_type;
            l3 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project;
            l4 = vader_bytecode_intern_type(l7, l3);
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir_InstrStructNew_t*) t0)->f_fields;
            l12 = vader_midir_boxed_fields_of(((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project, l4);
            t0 = l1.payload.obj;
            l14 = ((vader_struct_vader_midir_InstrStructNew_t*) t0)->f_span;
            vader_midir_emit_operands_into(l0, l2, l3, l12, l14);
            t0 = l1.payload.obj;
            l6 = ((vader_struct_vader_midir_InstrStructNew_t*) t0)->f_stack;
            vader_struct_vader_bytecode_StructNew_t* _a33_obj = (vader_struct_vader_bytecode_StructNew_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_StructNew_t));
            vader_obj_header_init(_a33_obj, 786u);
            _a33_obj->f_type_id = l4;
            _a33_obj->f_stack = l6;
            l3 = (void*) _a33_obj;
            t0 = l1.payload.obj;
            l12 = ((vader_struct_vader_midir_InstrStructNew_t*) t0)->f_span;
            vader_midir_push_emit(l0, vader_ref_box(l3), l12);
            t0 = l1.payload.obj;
            l4 = ((vader_struct_vader_midir_InstrStructNew_t*) t0)->f_dst;
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir_InstrStructNew_t*) t0)->f_span;
            vader_midir_emit_result(l0, l2, l4, l3);
            { vader_gc_top = gc_frame.prev; return; }
        }
        if (l1.tag == 1095u) {
            t0 = l1.payload.obj;
            l7 = ((vader_struct_vader_midir_InstrArrayNew_t*) t0)->f_type;
            l3 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project;
            l4 = vader_bytecode_intern_type(l7, l3);
            t0 = l1.payload.obj;
            t1 = vader_midir_boxed_element(((vader_struct_vader_midir_InstrArrayNew_t*) t0)->f_type);
            vader_array_t* _a34_arr = vader_array_new(12u, 1u, 12u, 283u);
            ((uint8_t*) _a34_arr->buf->slots)[_a34_arr->offset + 0u] = (uint8_t) t1;
            l3 = (void*) _a34_arr;
            t0 = l1.payload.obj;
            l5 = ((vader_array_t*) ((vader_struct_vader_midir_InstrArrayNew_t*) t0)->f_elements)->length;
            vader_array_t* _a35_arr = vader_array_repeat((vader_array_t*) l3, (int64_t) l5);
            l3 = (void*) _a35_arr;
            t0 = l1.payload.obj;
            l12 = ((vader_struct_vader_midir_InstrArrayNew_t*) t0)->f_elements;
            t0 = l1.payload.obj;
            l14 = ((vader_struct_vader_midir_InstrArrayNew_t*) t0)->f_span;
            vader_midir_emit_operands_into(l0, l2, l12, l3, l14);
            t0 = l1.payload.obj;
            l17 = ((vader_struct_vader_midir_InstrArrayNew_t*) t0)->f_length;
            vader_struct_vader_bytecode_ArrayNew_t* _a36_obj = (vader_struct_vader_bytecode_ArrayNew_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_ArrayNew_t));
            vader_obj_header_init(_a36_obj, 630u);
            _a36_obj->f_type_id = l4;
            _a36_obj->f_length = l17;
            l3 = (void*) _a36_obj;
            t0 = l1.payload.obj;
            l12 = ((vader_struct_vader_midir_InstrArrayNew_t*) t0)->f_span;
            vader_midir_push_emit(l0, vader_ref_box(l3), l12);
            t0 = l1.payload.obj;
            l4 = ((vader_struct_vader_midir_InstrArrayNew_t*) t0)->f_dst;
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir_InstrArrayNew_t*) t0)->f_span;
            vader_midir_emit_result(l0, l2, l4, l3);
            { vader_gc_top = gc_frame.prev; return; }
        }
        if (l1.tag == 1107u) {
            t0 = l1.payload.obj;
            l7 = ((vader_struct_vader_midir_InstrDataConst_t*) t0)->f_type;
            l3 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project;
            l4 = vader_bytecode_intern_type(l7, l3);
            t0 = l1.payload.obj;
            t3 = ((vader_struct_vader_midir_InstrDataConst_t*) t0)->f_pool_index;
            vader_struct_vader_bytecode_DataConst_t* _a37_obj = (vader_struct_vader_bytecode_DataConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_DataConst_t));
            vader_obj_header_init(_a37_obj, 681u);
            _a37_obj->f_pool_index = t3;
            _a37_obj->f_type_id = l4;
            l3 = (void*) _a37_obj;
            t0 = l1.payload.obj;
            l12 = ((vader_struct_vader_midir_InstrDataConst_t*) t0)->f_span;
            vader_midir_push_emit(l0, vader_ref_box(l3), l12);
            t0 = l1.payload.obj;
            l4 = ((vader_struct_vader_midir_InstrDataConst_t*) t0)->f_dst;
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir_InstrDataConst_t*) t0)->f_span;
            vader_midir_emit_result(l0, l2, l4, l3);
            { vader_gc_top = gc_frame.prev; return; }
        }
        if (l1.tag == 1114u) {
            t0 = l1.payload.obj;
            t3 = ((vader_struct_vader_midir_InstrGlobalGet_t*) t0)->f_slot;
            vader_struct_vader_bytecode_GlobalGet_t* _a38_obj = (vader_struct_vader_bytecode_GlobalGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_GlobalGet_t));
            vader_obj_header_init(_a38_obj, 706u);
            _a38_obj->f_index = t3;
            l3 = (void*) _a38_obj;
            t0 = l1.payload.obj;
            l12 = ((vader_struct_vader_midir_InstrGlobalGet_t*) t0)->f_span;
            vader_midir_push_emit(l0, vader_ref_box(l3), l12);
            t0 = l1.payload.obj;
            l4 = ((vader_struct_vader_midir_InstrGlobalGet_t*) t0)->f_dst;
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir_InstrGlobalGet_t*) t0)->f_span;
            vader_midir_emit_result(l0, l2, l4, l3);
            { vader_gc_top = gc_frame.prev; return; }
        }
        if (l1.tag == 1115u) {
            t0 = l1.payload.obj;
            l4 = ((vader_struct_vader_midir_InstrGlobalSet_t*) t0)->f_value;
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir_InstrGlobalSet_t*) t0)->f_span;
            vader_midir_emit_first_get(l0, l2, l4, l3);
            t0 = l1.payload.obj;
            l4 = ((vader_struct_vader_midir_InstrGlobalSet_t*) t0)->f_value;
            t0 = l1.payload.obj;
            l6 = vader_midir_is_boxed_slot(((vader_struct_vader_midir_InstrGlobalSet_t*) t0)->f_type);
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir_InstrGlobalSet_t*) t0)->f_span;
            vader_midir_emit_retag_into(l0, l4, l6, l3);
            t0 = l1.payload.obj;
            t3 = ((vader_struct_vader_midir_InstrGlobalSet_t*) t0)->f_slot;
            vader_struct_vader_bytecode_GlobalSet_t* _a39_obj = (vader_struct_vader_bytecode_GlobalSet_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_GlobalSet_t));
            vader_obj_header_init(_a39_obj, 707u);
            _a39_obj->f_index = t3;
            l3 = (void*) _a39_obj;
            t0 = l1.payload.obj;
            l12 = ((vader_struct_vader_midir_InstrGlobalSet_t*) t0)->f_span;
            vader_midir_push_emit(l0, vader_ref_box(l3), l12);
            { vader_gc_top = gc_frame.prev; return; }
        }
        if (l1.tag == 1120u) {
            l18 = ((vader_struct_vader_midir_CFGFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_fn_)->f_mangled;
            t0 = l1.payload.obj;
            l7 = ((vader_struct_vader_midir_InstrTypeCheck_t*) t0)->f_check_type;
            vader_midir_refuse_shared_identity_test(l18, l7);
            t0 = l1.payload.obj;
            l4 = ((vader_struct_vader_midir_InstrTypeCheck_t*) t0)->f_value;
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir_InstrTypeCheck_t*) t0)->f_span;
            vader_midir_emit_first_get(l0, l2, l4, l3);
            t0 = l1.payload.obj;
            l7 = ((vader_struct_vader_midir_InstrTypeCheck_t*) t0)->f_check_type;
            l3 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project;
            t3 = vader_bytecode_intern_type(l7, l3);
            vader_struct_vader_bytecode_TypeCheck_t* _a40_obj = (vader_struct_vader_bytecode_TypeCheck_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_TypeCheck_t));
            vader_obj_header_init(_a40_obj, 788u);
            _a40_obj->f_type_id = t3;
            l3 = (void*) _a40_obj;
            t0 = l1.payload.obj;
            l12 = ((vader_struct_vader_midir_InstrTypeCheck_t*) t0)->f_span;
            vader_midir_push_emit(l0, vader_ref_box(l3), l12);
            t0 = l1.payload.obj;
            l4 = ((vader_struct_vader_midir_InstrTypeCheck_t*) t0)->f_dst;
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir_InstrTypeCheck_t*) t0)->f_span;
            vader_midir_emit_result(l0, l2, l4, l3);
            { vader_gc_top = gc_frame.prev; return; }
        }
        if (l1.tag == 1121u) {
            t0 = l1.payload.obj;
            l7 = ((vader_struct_vader_midir_InstrTypeConst_t*) t0)->f_value_type;
            l3 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project;
            t3 = vader_bytecode_intern_type(l7, l3);
            vader_struct_vader_bytecode_TypeConst_t* _a41_obj = (vader_struct_vader_bytecode_TypeConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_TypeConst_t));
            vader_obj_header_init(_a41_obj, 789u);
            _a41_obj->f_type_id = t3;
            l3 = (void*) _a41_obj;
            t0 = l1.payload.obj;
            l12 = ((vader_struct_vader_midir_InstrTypeConst_t*) t0)->f_span;
            vader_midir_push_emit(l0, vader_ref_box(l3), l12);
            t0 = l1.payload.obj;
            l4 = ((vader_struct_vader_midir_InstrTypeConst_t*) t0)->f_dst;
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir_InstrTypeConst_t*) t0)->f_span;
            vader_midir_emit_result(l0, l2, l4, l3);
            { vader_gc_top = gc_frame.prev; return; }
        }
        if (l1.tag == 1102u) {
            t0 = l1.payload.obj;
            l4 = ((vader_struct_vader_midir_InstrCast_t*) t0)->f_value;
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir_InstrCast_t*) t0)->f_span;
            vader_midir_emit_first_get(l0, l2, l4, l3);
            l3 = ((vader_struct_vader_midir_CFGFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_fn_)->f_locals;
            t0 = l1.payload.obj;
            l5 = ((int64_t) (int32_t) ((vader_struct_vader_midir_InstrCast_t*) t0)->f_value);
            vader_array_t* _a42_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a42_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a42_slotarr, l5)
            t0 = vader_array_ref_load_obj(_a42_slotarr->buf, _a42_slotarr->offset + (size_t) l5);
            l7 = ((vader_struct_vader_midir_CFGLocal_t*) t0)->f_type;
            l10 = vader_bytecode_val_type_of_type(l7);
            t0 = l1.payload.obj;
            l11 = vader_bytecode_val_type_of_type(((vader_struct_vader_midir_InstrCast_t*) t0)->f_type);
            if (l11 == INT32_C(17)) {
                l6 = vader_midir_is_scalar_class(l10);
            } else {
                l6 = false;
            }
            if (l6) {
                l3 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project;
                t3 = vader_bytecode_intern_type(l7, l3);
                vader_struct_vader_bytecode_Retag_t* _a43_obj = (vader_struct_vader_bytecode_Retag_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_Retag_t));
                vader_obj_header_init(_a43_obj, 769u);
                _a43_obj->f_type_id = t3;
                l3 = (void*) _a43_obj;
                t0 = l1.payload.obj;
                l12 = ((vader_struct_vader_midir_InstrCast_t*) t0)->f_span;
                vader_midir_push_emit(l0, vader_ref_box(l3), l12);
            } else if (l10 != l11) {
                l7 = vader_bytecode_convert_target_of(l11);
                if (l7.tag == 0u) {
                    t0 = l1.payload.obj;
                    l8 = ((vader_struct_vader_midir_InstrCast_t*) t0)->f_type;
                    l3 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project;
                    t3 = vader_bytecode_intern_type(l8, l3);
                    vader_struct_vader_bytecode_RefCast_t* _a44_obj = (vader_struct_vader_bytecode_RefCast_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_RefCast_t));
                    vader_obj_header_init(_a44_obj, 766u);
                    _a44_obj->f_type_id = t3;
                    l3 = (void*) _a44_obj;
                    t0 = l1.payload.obj;
                    l12 = ((vader_struct_vader_midir_InstrCast_t*) t0)->f_span;
                    vader_midir_push_emit(l0, vader_ref_box(l3), l12);
                } else {
                    t1 = vader_midir_convert_eligible(l10);
                    if (t1) {
                        l18 = vader_bytecode_val_type_name(l10);
                        l23 = ((uint8_t) l7.payload.i);
                        vader_struct_vader_bytecode_Convert_t* _a45_obj = (vader_struct_vader_bytecode_Convert_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_Convert_t));
                        vader_obj_header_init(_a45_obj, 680u);
                        _a45_obj->f_from_name = l18;
                        _a45_obj->f_target = l23;
                        l3 = (void*) _a45_obj;
                        t0 = l1.payload.obj;
                        l12 = ((vader_struct_vader_midir_InstrCast_t*) t0)->f_span;
                        vader_midir_push_emit(l0, vader_ref_box(l3), l12);
                        t1 = vader_midir_fits_in(l10, l11);
                        if (!(t1)) {
                            t0 = l1.payload.obj;
                            l3 = ((vader_struct_vader_midir_InstrCast_t*) t0)->f_span;
                            vader_midir_emit_narrowing(l0, l11, l3);
                        }
                    } else {
                        t0 = l1.payload.obj;
                        l7 = ((vader_struct_vader_midir_InstrCast_t*) t0)->f_type;
                        l3 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project;
                        t3 = vader_bytecode_intern_type(l7, l3);
                        vader_struct_vader_bytecode_RefCast_t* _a46_obj = (vader_struct_vader_bytecode_RefCast_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_RefCast_t));
                        vader_obj_header_init(_a46_obj, 766u);
                        _a46_obj->f_type_id = t3;
                        l3 = (void*) _a46_obj;
                        t0 = l1.payload.obj;
                        l12 = ((vader_struct_vader_midir_InstrCast_t*) t0)->f_span;
                        vader_midir_push_emit(l0, vader_ref_box(l3), l12);
                    }
                }
            }
            t0 = l1.payload.obj;
            l4 = ((vader_struct_vader_midir_InstrCast_t*) t0)->f_dst;
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir_InstrCast_t*) t0)->f_span;
            vader_midir_emit_result(l0, l2, l4, l3);
            { vader_gc_top = gc_frame.prev; return; }
        }
        if (l1.tag == 1104u) {
            t0 = l1.payload.obj;
            l7 = ((vader_struct_vader_midir_InstrCellNew_t*) t0)->f_value_type;
            l3 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project;
            l4 = vader_bytecode_intern_cell_type(l7, l3);
            t0 = l1.payload.obj;
            l17 = ((vader_struct_vader_midir_InstrCellNew_t*) t0)->f_value;
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir_InstrCellNew_t*) t0)->f_span;
            vader_midir_emit_first_get(l0, l2, l17, l3);
            t0 = l1.payload.obj;
            l17 = ((vader_struct_vader_midir_InstrCellNew_t*) t0)->f_value;
            t0 = l1.payload.obj;
            l6 = vader_midir_is_boxed_slot(((vader_struct_vader_midir_InstrCellNew_t*) t0)->f_value_type);
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir_InstrCellNew_t*) t0)->f_span;
            vader_midir_emit_retag_into(l0, l17, l6, l3);
            vader_struct_vader_bytecode_StructNew_t* _a47_obj = (vader_struct_vader_bytecode_StructNew_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_StructNew_t));
            vader_obj_header_init(_a47_obj, 786u);
            _a47_obj->f_type_id = l4;
            _a47_obj->f_stack = false;
            l3 = (void*) _a47_obj;
            t0 = l1.payload.obj;
            l12 = ((vader_struct_vader_midir_InstrCellNew_t*) t0)->f_span;
            vader_midir_push_emit(l0, vader_ref_box(l3), l12);
            t0 = l1.payload.obj;
            l4 = ((vader_struct_vader_midir_InstrCellNew_t*) t0)->f_dst;
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir_InstrCellNew_t*) t0)->f_span;
            vader_midir_emit_result(l0, l2, l4, l3);
            { vader_gc_top = gc_frame.prev; return; }
        }
        if (l1.tag == 1103u) {
            t0 = l1.payload.obj;
            l7 = ((vader_struct_vader_midir_InstrCellGet_t*) t0)->f_value_type;
            l3 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project;
            l4 = vader_bytecode_intern_cell_type(l7, l3);
            l6 = std_collections_MutableSet_std_core_Contains_contains__i64(((vader_struct_vader_midir_ScheduleHints_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_hints)->f_skip_first_get, l2);
            t0 = l1.payload.obj;
            l17 = ((vader_struct_vader_midir_InstrCellGet_t*) t0)->f_cell;
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir_InstrCellGet_t*) t0)->f_span;
            vader_midir_emit_first_get(l0, l2, l17, l3);
            l9 = false;
            if (!(l6)) {
                l9 = vader_midir_try_fuse_local_field(l0, l4, INT32_C(0));
            }
            if (!(l9)) {
                vader_struct_vader_bytecode_StructGet_t* _a48_obj = (vader_struct_vader_bytecode_StructGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_StructGet_t));
                vader_obj_header_init(_a48_obj, 785u);
                _a48_obj->f_type_id = l4;
                _a48_obj->f_field_index = INT32_C(0);
                l3 = (void*) _a48_obj;
                t0 = l1.payload.obj;
                l12 = ((vader_struct_vader_midir_InstrCellGet_t*) t0)->f_span;
                vader_midir_push_emit(l0, vader_ref_box(l3), l12);
            }
            t0 = l1.payload.obj;
            l4 = ((vader_struct_vader_midir_InstrCellGet_t*) t0)->f_dst;
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir_InstrCellGet_t*) t0)->f_span;
            vader_midir_emit_result(l0, l2, l4, l3);
            { vader_gc_top = gc_frame.prev; return; }
        }
        if (l1.tag == 1105u) {
            t0 = l1.payload.obj;
            l7 = ((vader_struct_vader_midir_InstrCellSet_t*) t0)->f_value_type;
            l3 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project;
            l4 = vader_bytecode_intern_cell_type(l7, l3);
            t0 = l1.payload.obj;
            l17 = ((vader_struct_vader_midir_InstrCellSet_t*) t0)->f_cell;
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir_InstrCellSet_t*) t0)->f_span;
            vader_midir_emit_first_get(l0, l2, l17, l3);
            t0 = l1.payload.obj;
            l17 = ((vader_struct_vader_midir_InstrCellSet_t*) t0)->f_value;
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir_InstrCellSet_t*) t0)->f_span;
            vader_midir_emit_get(l0, l17, l3);
            t0 = l1.payload.obj;
            l17 = ((vader_struct_vader_midir_InstrCellSet_t*) t0)->f_value;
            t0 = l1.payload.obj;
            l6 = vader_midir_is_boxed_slot(((vader_struct_vader_midir_InstrCellSet_t*) t0)->f_value_type);
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir_InstrCellSet_t*) t0)->f_span;
            vader_midir_emit_retag_into(l0, l17, l6, l3);
            vader_struct_vader_bytecode_StructSet_t* _a49_obj = (vader_struct_vader_bytecode_StructSet_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_StructSet_t));
            vader_obj_header_init(_a49_obj, 787u);
            _a49_obj->f_type_id = l4;
            _a49_obj->f_field_index = INT32_C(0);
            _a49_obj->f_stack = false;
            l3 = (void*) _a49_obj;
            t0 = l1.payload.obj;
            l12 = ((vader_struct_vader_midir_InstrCellSet_t*) t0)->f_span;
            vader_midir_push_emit(l0, vader_ref_box(l3), l12);
            { vader_gc_top = gc_frame.prev; return; }
        }
        if (l1.tag == 1117u) {
            t0 = l1.payload.obj;
            l4 = ((vader_struct_vader_midir_InstrMakeClosure_t*) t0)->f_env;
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir_InstrMakeClosure_t*) t0)->f_span;
            vader_midir_emit_first_get(l0, l2, l4, l3);
            t0 = l1.payload.obj;
            l7 = vader_midir_closure_header_type(((vader_struct_vader_midir_InstrMakeClosure_t*) t0)->f_type);
            l3 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project;
            l4 = vader_bytecode_intern_type(l7, l3);
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir_InstrMakeClosure_t*) t0)->f_fn_symbol;
            l12 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project;
            l7 = vader_midir_resolve_fn_index(l3, l12);
            if (!(l7.tag == 288u)) {
                t0 = l1.payload.obj;
                l18 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_midir_InstrMakeClosure_t*) t0)->f_fn_symbol)->f_name;
                l5 = vader_host_std_core_byte_len(l18);
                l14 = (void*) vader_buffer_new((size_t) (INT64_C(109) + l5));
                l5 = INT64_C(0);
                l5 = std_core_write_string_at(l14, l5, 2133u);
                l5 = std_core_write_string_at(l14, l5, l18);
                l5 = std_core_write_string_at(l14, l5, 234u);
                t0 = l1.payload.obj;
                t3 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_midir_InstrMakeClosure_t*) t0)->f_fn_symbol)->f_id;
                l13 = ((int64_t) (int32_t) t3);
                l5 = std_core_write_int(l14, l5, l13);
                l5 = std_core_write_string_at(l14, l5, 285u);
                t4 = std_core_finish_buffer(l14, l5);
                vader_host_std_abort_panic(t4);
                vader_unreachable("a no-return call returned");
            }
            t3 = ((int32_t) l7.payload.i);
            vader_struct_vader_bytecode_MakeClosure_t* _a50_obj = (vader_struct_vader_bytecode_MakeClosure_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_MakeClosure_t));
            vader_obj_header_init(_a50_obj, 762u);
            _a50_obj->f_function_index = t3;
            _a50_obj->f_env_type_id = l4;
            l3 = (void*) _a50_obj;
            t0 = l1.payload.obj;
            l12 = ((vader_struct_vader_midir_InstrMakeClosure_t*) t0)->f_span;
            vader_midir_push_emit(l0, vader_ref_box(l3), l12);
            t0 = l1.payload.obj;
            l4 = ((vader_struct_vader_midir_InstrMakeClosure_t*) t0)->f_dst;
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir_InstrMakeClosure_t*) t0)->f_span;
            vader_midir_emit_result(l0, l2, l4, l3);
            { vader_gc_top = gc_frame.prev; return; }
        }
        if (l1.tag == 1116u) {
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir_InstrIntrinsic_t*) t0)->f_args;
            vader_array_t* _a51_arr = vader_array_new(12u, 0u, 12u, 283u);
            l12 = (void*) _a51_arr;
            t0 = l1.payload.obj;
            l14 = ((vader_struct_vader_midir_InstrIntrinsic_t*) t0)->f_span;
            vader_midir_emit_operands_into(l0, l2, l3, l12, l14);
            t0 = l1.payload.obj;
            t4 = ((vader_struct_vader_midir_InstrIntrinsic_t*) t0)->f_name;
            l7 = vader_midir_intrinsic_op_for_name(t4);
            if (!(l7.tag == 0u)) {
                t0 = l1.payload.obj;
                l3 = ((vader_struct_vader_midir_InstrIntrinsic_t*) t0)->f_span;
                vader_midir_push_emit(l0, l7, l3);
                t0 = l1.payload.obj;
                l7 = ((vader_struct_vader_midir_InstrIntrinsic_t*) t0)->f_dst;
                t0 = l1.payload.obj;
                l3 = ((vader_struct_vader_midir_InstrIntrinsic_t*) t0)->f_span;
                vader_midir_emit_result_if_any(l0, l2, l7, l3);
                { vader_gc_top = gc_frame.prev; return; }
            }
            t0 = l1.payload.obj;
            l18 = ((vader_struct_vader_midir_InstrIntrinsic_t*) t0)->f_name;
            l19 = ((vader_struct_vader_midir_CFGFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_fn_)->f_mangled;
            t4 = concat_5(2131u, l18, 987u, l19, 249u);
            vader_host_std_abort_panic(t4);
            vader_unreachable("a no-return call returned");
        } else {
            if (l1.tag == 1109u) {
                t0 = l1.payload.obj;
                l4 = ((vader_struct_vader_midir_InstrDeferPush_t*) t0)->f_value;
                t0 = l1.payload.obj;
                l3 = ((vader_struct_vader_midir_InstrDeferPush_t*) t0)->f_span;
                vader_midir_emit_first_get(l0, l2, l4, l3);
                vader_struct_vader_bytecode_DeferPush_t* _a52_obj = (vader_struct_vader_bytecode_DeferPush_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_DeferPush_t));
                vader_obj_header_init(_a52_obj, 684u);
                l3 = (void*) _a52_obj;
                t0 = l1.payload.obj;
                l12 = ((vader_struct_vader_midir_InstrDeferPush_t*) t0)->f_span;
                vader_midir_push_emit(l0, vader_ref_box(l3), l12);
                { vader_gc_top = gc_frame.prev; return; }
            }
            if (!(l1.tag == 1108u)) {
                vader_host_std_abort_panic(2130u);
                vader_unreachable("a no-return call returned");
            }
            t0 = l1.payload.obj;
            t3 = ((vader_struct_vader_midir_InstrDeferPopExec_t*) t0)->f_count;
            vader_struct_vader_bytecode_DeferPopExec_t* _a53_obj = (vader_struct_vader_bytecode_DeferPopExec_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_DeferPopExec_t));
            vader_obj_header_init(_a53_obj, 683u);
            _a53_obj->f_count = t3;
            l3 = (void*) _a53_obj;
            t0 = l1.payload.obj;
            l12 = ((vader_struct_vader_midir_InstrDeferPopExec_t*) t0)->f_span;
            vader_midir_push_emit(l0, vader_ref_box(l3), l12);
            { vader_gc_top = gc_frame.prev; return; }
        }
    }
    vader_gc_top = gc_frame.prev;
}

static void vader_midir_emit_instructions(void* l0, int32_t l1, int64_t l2, int64_t l3) {
    void* l4 = NULL;
    int32_t l5;
    int64_t l6, l8;
    vader_box_t l7 = vader_box_null();
    vader_box_t* gc_roots[1] = { &l7 };
    void** gc_raw_roots[2] = { &l0, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l4 = ((vader_struct_vader_midir_CFGFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_fn_)->f_blocks;
    l5 = l1;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
    l4 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
    l6 = l2;
    while ((l6 < l3)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_midir_BasicBlock_t*) l4)->f_instructions);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l6)
        l7 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l6);
        l8 = vader_midir_pos_key(l1, l6);
        vader_midir_emit_instr(l0, l7, l8);
        l6 = (l6 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_midir_emit_loop(void* l0, void* l1, int32_t l2, int32_t l3) {
    void* l4 = NULL;
    void* l6 = NULL;
    void* l8 = NULL;
    int32_t l5, l7, l9;
    void* t0 = NULL;
    int64_t t1;
    void** gc_raw_roots[6] = { &l0, &l1, &l4, &l6, &l8, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 6u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l4 = ((vader_struct_vader_midir_StructureShape_t*) l1)->f_exits;
    l5 = l2;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
    l4 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
    l5 = vader_midir_open_blocks(l0, l4, l3);
    l6 = ((vader_struct_vader_midir_CFGFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_fn_)->f_blocks;
    l7 = l2;
    vader_array_t* _a1_slotarr = ((vader_array_t*) l6);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l7)
    t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l7);
    l6 = ((vader_struct_vader_midir_BasicBlock_t*) t0)->f_span;
    l8 = ((vader_struct_vader_midir_StructureShape_t*) l1)->f_merges;
    l9 = l2;
    vader_array_t* _a2_slotarr = ((vader_array_t*) l8);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l9)
    t0 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l9);
    t1 = ((vader_array_t*) t0)->length;
    if (t1 == INT64_C(0)) {
        l7 = vader_midir_loop_exit(l0, l1, l2);
    } else {
        l7 = INT32_C(-1);
    }
    vader_midir_cf_loop(l0, l6, l2);
    vader_midir_emit_body(l0, l1, l2, INT32_C(-1), l7);
    vader_midir_cf_end(l0, l6);
    if ((l7 >= INT32_C(0))) {
        vader_midir_emit_branch(l0, l1, l2, l7, l5, l6);
        vader_midir_close_blocks(l0, l1, l4, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_midir_close_blocks(l0, l1, l4, l3);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_midir_emit_narrowing(void* l0, uint8_t l1, void* l2) {
    bool l3;
    int32_t l4;
    void* l5 = NULL;
    bool t0;
    void** gc_raw_roots[3] = { &l0, &l2, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l1 == INT32_C(4)) {
        l3 = true;
    } else {
        l3 = l1 == INT32_C(0);
    }
    if (l3) {
        l4 = INT32_C(255);
    } else {
        l4 = INT32_C(65535);
    }
    vader_struct_vader_bytecode_I32Const_t* _a0_obj = (vader_struct_vader_bytecode_I32Const_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32Const_t));
    vader_obj_header_init(_a0_obj, 713u);
    _a0_obj->f_value = l4;
    l5 = (void*) _a0_obj;
    vader_midir_push_emit(l0, vader_ref_box(l5), l2);
    vader_struct_vader_bytecode_I32BitAnd_t* _a1_obj = (vader_struct_vader_bytecode_I32BitAnd_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32BitAnd_t));
    vader_obj_header_init(_a1_obj, 709u);
    l5 = (void*) _a1_obj;
    vader_midir_push_emit(l0, vader_ref_box(l5), l2);
    t0 = vader_bytecode_is_unsigned_val(l1);
    if (t0) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l3) {
        l4 = INT32_C(128);
    } else {
        l4 = INT32_C(32768);
    }
    vader_struct_vader_bytecode_I32Const_t* _a2_obj = (vader_struct_vader_bytecode_I32Const_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32Const_t));
    vader_obj_header_init(_a2_obj, 713u);
    _a2_obj->f_value = l4;
    l5 = (void*) _a2_obj;
    vader_midir_push_emit(l0, vader_ref_box(l5), l2);
    vader_struct_vader_bytecode_I32BitXor_t* _a3_obj = (vader_struct_vader_bytecode_I32BitXor_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32BitXor_t));
    vader_obj_header_init(_a3_obj, 712u);
    l5 = (void*) _a3_obj;
    vader_midir_push_emit(l0, vader_ref_box(l5), l2);
    vader_struct_vader_bytecode_I32Const_t* _a4_obj = (vader_struct_vader_bytecode_I32Const_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32Const_t));
    vader_obj_header_init(_a4_obj, 713u);
    _a4_obj->f_value = l4;
    l5 = (void*) _a4_obj;
    vader_midir_push_emit(l0, vader_ref_box(l5), l2);
    vader_struct_vader_bytecode_I32Sub_t* _a5_obj = (vader_struct_vader_bytecode_I32Sub_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32Sub_t));
    vader_obj_header_init(_a5_obj, 727u);
    l5 = (void*) _a5_obj;
    vader_midir_push_emit(l0, vader_ref_box(l5), l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_midir_emit_operands_into(void* l0, int64_t l1, void* l2, void* l3, void* l4) {
    int64_t l5, l6, l10;
    int32_t l7, l8, l9;
    bool l11;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[4] = { &l0, &l2, &l3, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l5 = INT64_C(0);
    l6 = ((vader_array_t*) l2)->length;
    while ((l5 < l6)) {
        if (l5 == INT64_C(0)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            l7 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l5];
            vader_midir_emit_first_get(l0, l1, l7, l4);
        } else {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            l8 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l5];
            vader_midir_emit_get(l0, l8, l4);
        }
        vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        l9 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l5];
        l10 = ((vader_array_t*) l3)->length;
        if ((l5 < l10)) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            t0 = vader_box_bool(283u, ((uint8_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l5]);
            l11 = t0.payload.b;
        } else {
            l11 = false;
        }
        vader_midir_emit_retag_into(l0, l9, l11, l4);
        l5 = (l5 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_midir_emit_result(void* l0, int64_t l1, int32_t l2, void* l3) {
    bool t0;
    void** gc_raw_roots[2] = { &l0, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = std_collections_MutableSet_std_core_Contains_contains__i64(((vader_struct_vader_midir_ScheduleHints_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_hints)->f_skip_set, l1);
    if (!(t0)) {
        vader_midir_emit_set(l0, l2, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_midir_emit_result_if_any(void* l0, int64_t l1, vader_box_t l2, void* l3) {
    int32_t l4;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[2] = { &l0, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (!(l2.tag == 0u)) {
        l4 = ((int32_t) l2.payload.i);
        vader_midir_emit_result(l0, l1, l4, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_midir_emit_retag_into(void* l0, int32_t l1, bool l2, void* l3) {
    void* l4 = NULL;
    int64_t l5;
    vader_box_t l6 = vader_box_null();
    void* t0 = NULL;
    uint8_t t1;
    bool t2;
    int32_t t3;
    vader_box_t* gc_roots[1] = { &l6 };
    void** gc_raw_roots[4] = { &l0, &l3, &l4, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (!(l2)) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l4 = ((vader_struct_vader_midir_CFGFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_fn_)->f_locals;
    l5 = ((int64_t) (int32_t) l1);
    vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
    t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
    l6 = ((vader_struct_vader_midir_CFGLocal_t*) t0)->f_type;
    t1 = vader_bytecode_val_type_of_type(l6);
    t2 = vader_midir_is_scalar_class(t1);
    if (t2) {
        l4 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project;
        t3 = vader_bytecode_intern_type(l6, l4);
        vader_struct_vader_bytecode_Retag_t* _a1_obj = (vader_struct_vader_bytecode_Retag_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_Retag_t));
        vader_obj_header_init(_a1_obj, 769u);
        _a1_obj->f_type_id = t3;
        l4 = (void*) _a1_obj;
        vader_midir_push_emit(l0, vader_ref_box(l4), l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_midir_emit_return(void* l0, int32_t l1, void* l2) {
    vader_box_t l3 = vader_box_null();
    int64_t l4, l5;
    int32_t l6;
    bool l7;
    void* l8 = NULL;
    void* l9 = NULL;
    int64_t t0;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l3, &t1 };
    void** gc_raw_roots[4] = { &l0, &l2, &l8, &l9 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = vader_midir_term_return_single(l2);
    l4 = INT64_C(0);
    l5 = ((vader_array_t*) ((vader_struct_vader_midir_TermReturn_t*) l2)->f_values)->length;
    while ((l4 < l5)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_midir_TermReturn_t*) l2)->f_values);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        l6 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l4];
        if (!(l3.tag == 0u)) {
            l7 = std_collections_MutableSet_std_core_Contains_contains__i32(((vader_struct_vader_midir_ScheduleHints_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_hints)->f_skip_terminator_get, l1);
        } else {
            l7 = false;
        }
        if (!(l7)) {
            l8 = ((vader_struct_vader_midir_TermReturn_t*) l2)->f_span;
            vader_midir_emit_get(l0, l6, l8);
        }
        l9 = ((vader_struct_vader_midir_TermReturn_t*) l2)->f_span;
        vader_midir_emit_return_retag(l0, l6, l4, l9);
        l4 = (l4 + INT64_C(1));
    }
    l8 = ((vader_struct_vader_bytecode_BcFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_slot)->f_body;
    t0 = ((vader_array_t*) l8)->length;
    if ((t0 > INT64_C(0))) {
        if (!(l3.tag == 0u)) {
            t0 = ((vader_array_t*) l8)->length;
            l4 = vader_chk_sub(i64, t0, INT64_C(1));
            vader_array_t* _a1_slotarr = ((vader_array_t*) l8);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            t1 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
            l3 = vader_bytecode_const_op_of(t1);
            if (!(l3.tag == 0u)) {
                t0 = ((vader_array_t*) l8)->length;
                l4 = vader_chk_sub(i64, t0, INT64_C(1));
                vader_struct_vader_bytecode_ReturnLit_t* _a2_obj = (vader_struct_vader_bytecode_ReturnLit_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_ReturnLit_t));
                vader_obj_header_init(_a2_obj, 771u);
                _a2_obj->f_value = l3;
                l9 = (void*) _a2_obj;
                vader_array_t* _a3_slotarr = ((vader_array_t*) l8);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                vader_array_ref_store(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l4, l9);
                VADER_WRITE_BARRIER(_a3_slotarr->buf);
                { vader_gc_top = gc_frame.prev; return; }
            }
        }
    }
    vader_struct_vader_bytecode_Return_t* _a4_obj = (vader_struct_vader_bytecode_Return_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_Return_t));
    vader_obj_header_init(_a4_obj, 770u);
    l8 = (void*) _a4_obj;
    l9 = ((vader_struct_vader_midir_TermReturn_t*) l2)->f_span;
    vader_midir_push_emit(l0, vader_ref_box(l8), l9);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_midir_emit_return_retag(void* l0, int32_t l1, int64_t l2, void* l3) {
    bool l4;
    int64_t t0;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[2] = { &l0, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_vader_midir_CFGFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_fn_)->f_scalarised_results)->length;
    if ((t0 > l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_midir_CFGFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_fn_)->f_scalarised_results);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
        t1 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
        l4 = vader_midir_is_boxed_slot(t1);
        vader_midir_emit_retag_into(l0, l1, l4, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    l4 = vader_midir_is_boxed_slot(((vader_struct_vader_midir_CFGFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_fn_)->f_return_type);
    vader_midir_emit_retag_into(l0, l1, l4, l3);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_midir_emit_set(void* l0, int32_t l1, void* l2) {
    void* l3 = NULL;
    int64_t l4;
    int32_t t0;
    void** gc_raw_roots[3] = { &l0, &l2, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_local_to_slot;
    l4 = ((int64_t) (int32_t) l1);
    vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
    t0 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l4];
    vader_struct_vader_bytecode_LocalSet_t* _a1_obj = (vader_struct_vader_bytecode_LocalSet_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_LocalSet_t));
    vader_obj_header_init(_a1_obj, 759u);
    _a1_obj->f_slot = t0;
    l3 = (void*) _a1_obj;
    vader_midir_push_emit(l0, vader_ref_box(l3), l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_midir_emit_subtree(void* l0, void* l1, int32_t l2, int32_t l3) {
    void* l4 = NULL;
    int32_t l5;
    vader_box_t t0 = vader_box_null();
    bool t1;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[3] = { &l0, &l1, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l4 = ((vader_struct_vader_midir_StructureShape_t*) l1)->f_loop_header;
    l5 = l2;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
    t0 = vader_box_bool(283u, ((uint8_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l5]);
    t1 = t0.payload.b;
    if (t1) {
        vader_midir_emit_loop(l0, l1, l2, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_midir_emit_body(l0, l1, l2, l3, INT32_C(-1));
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_midir_emit_terminator(void* l0, void* l1, int32_t l2, int32_t l3, int32_t l4) {
    void* l5 = NULL;
    void* l8 = NULL;
    int32_t l6;
    vader_box_t l7 = vader_box_null();
    void* t0 = NULL;
    vader_string_t t1 = 0;
    vader_box_t* gc_roots[1] = { &l7 };
    void** gc_raw_roots[5] = { &l0, &l1, &l5, &l8, &t0 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l5 = ((vader_struct_vader_midir_CFGFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_fn_)->f_blocks;
    l6 = l2;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l6)
    t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l6);
    l7 = ((vader_struct_vader_midir_BasicBlock_t*) t0)->f_terminator;
    if (l7.tag == 1138u) {
        l5 = l7.payload.obj;
        vader_midir_emit_return(l0, l2, l5);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l7.tag == 1139u) {
        t0 = l7.payload.obj;
        t1 = ((vader_struct_vader_midir_TermUnreachable_t*) t0)->f_reason;
        vader_struct_vader_bytecode_Unreachable_t* _a1_obj = (vader_struct_vader_bytecode_Unreachable_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_Unreachable_t));
        vader_obj_header_init(_a1_obj, 804u);
        _a1_obj->f_reason = t1;
        l5 = (void*) _a1_obj;
        t0 = l7.payload.obj;
        l8 = ((vader_struct_vader_midir_TermUnreachable_t*) t0)->f_span;
        vader_midir_push_emit(l0, vader_ref_box(l5), l8);
    } else if (l7.tag == 1136u) {
        t0 = l7.payload.obj;
        l6 = ((vader_struct_vader_midir_TermBranch_t*) t0)->f_target;
        t0 = l7.payload.obj;
        l5 = ((vader_struct_vader_midir_TermBranch_t*) t0)->f_span;
        vader_midir_emit_branch(l0, l1, l2, l6, l3, l5);
    } else {
        if (!(l7.tag == 1137u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l5 = l7.payload.obj;
        vader_midir_emit_cond_branch(l0, l1, l2, l5, l3, l4);
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static bool vader_midir_emitted_beneath(void* l0, void* l1, void* l2, void* l3, int32_t l4) {
    void* l5;
    int64_t l6, l7;
    int32_t l8, l9, l10, l11, l12, l13;
    int32_t t0;
    bool t1;
    l5 = l0;
    l6 = ((vader_array_t*) l5)->length;
    l7 = INT64_C(0);
    while ((l7 < l6)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l8 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l7];
        l9 = l8;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l9)
        t0 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l9];
        if ((t0 < INT32_C(0))) {
            l7 = (l7 + INT64_C(1));
            continue;
        }
        l10 = l8;
        while (l10 != l4) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l10)
            l11 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l10];
            if ((l11 >= INT32_C(0))) {
                l12 = l11;
                l13 = l4;
                t1 = vader_midir_dominates(l2, l12, l13);
                if (t1) {
                    return false;
                }
            }
            vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l10)
            l10 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l10];
        }
        l7 = (l7 + INT64_C(1));
    }
    return true;
}

static vader_box_t vader_midir_end_after_no_return(void* l0, void* l1, vader_box_t l2) {
    void* l3 = NULL;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[3] = { &l0, &l1, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (!(((vader_struct_vader_lower_LoweredCall_t*) l1)->f_type.tag == 1260u)) {
        { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_midir_TermUnreachable_t* _a0_obj = (vader_struct_vader_midir_TermUnreachable_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_TermUnreachable_t));
    vader_obj_header_init(_a0_obj, 1139u);
    _a0_obj->f_span = ((vader_struct_vader_lower_LoweredCall_t*) l1)->f_span;
    _a0_obj->f_reason = 1318u;
    l3 = (void*) _a0_obj;
    vader_midir_terminate(l0, vader_ref_box(l3));
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static bool vader_midir_ends_function(vader_box_t l0) {
    return (l0.tag == 1138u || l0.tag == 1139u);
}

static bool vader_midir_entered_by_test(void* l0, void* l1, int32_t l2) {
    void* l3;
    int64_t l4, l5;
    int32_t l6;
    bool t0;
    l3 = l1;
    l4 = ((vader_array_t*) l3)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l6 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l5];
        t0 = vader_midir_leaves_header(l0, l6, l2);
        if (t0) {
            return true;
        }
        l5 = (l5 + INT64_C(1));
    }
    return false;
}

static void* vader_midir_every_operand_boxed(void* l0) {
    void* l1 = NULL;
    int64_t l2;
    void* t0 = NULL;
    void** gc_raw_roots[3] = { &l0, &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(12u, 1u, 12u, 283u);
    ((uint8_t*) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = (uint8_t) true;
    l1 = (void*) _a0_arr;
    l2 = ((vader_array_t*) l0)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l1, (int64_t) l2);
    t0 = (void*) _a1_arr;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_midir_extern_library_name(void* l0) {
    void* l1;
    void* l4;
    int64_t l2, l3;
    vader_box_t l5, l6;
    vader_string_t t0;
    int64_t t1;
    void* t2;
    l1 = ((vader_struct_toolchain_ast_FnDecl_t*) l0)->f_decorators;
    l2 = ((vader_array_t*) l1)->length;
    l3 = INT64_C(0);
    while ((l3 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l4 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
        t0 = ((vader_struct_toolchain_ast_Decorator_t*) l4)->f_name;
        if (t0 == 1754u) {
            t1 = ((vader_array_t*) ((vader_struct_toolchain_ast_Decorator_t*) l4)->f_args)->length;
            if (t1 == INT64_C(2)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_Decorator_t*) l4)->f_args);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, INT32_C(0))
                l5 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) INT32_C(0));
                if (l5.tag == 600u) {
                    t2 = l5.payload.obj;
                    t1 = ((vader_array_t*) ((vader_struct_toolchain_ast_StringLitExpr_t*) t2)->f_parts)->length;
                    if (t1 == INT64_C(1)) {
                        t2 = l5.payload.obj;
                        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_StringLitExpr_t*) t2)->f_parts);
                        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, INT32_C(0))
                        l6 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) INT32_C(0));
                        if (l6.tag == 602u) {
                            t2 = l6.payload.obj;
                            t0 = ((vader_struct_toolchain_ast_StringLitText_t*) t2)->f_value;
                            return t0;
                        }
                    }
                }
            }
        }
        l3 = (l3 + INT64_C(1));
    }
    return 0u;
}

static vader_string_t vader_midir_extern_symbol_name(void* l0) {
    void* l1;
    void* l4;
    void* l5;
    int64_t l2, l3, l6;
    vader_box_t l7, l8;
    vader_string_t t0;
    int64_t t1;
    void* t2;
    l1 = ((vader_struct_toolchain_ast_FnDecl_t*) l0)->f_decorators;
    l2 = ((vader_array_t*) l1)->length;
    l3 = INT64_C(0);
    while ((l3 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l4 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
        t0 = ((vader_struct_toolchain_ast_Decorator_t*) l4)->f_name;
        if (t0 != 1754u) {
            l3 = (l3 + INT64_C(1));
            continue;
        }
        t1 = ((vader_array_t*) ((vader_struct_toolchain_ast_Decorator_t*) l4)->f_args)->length;
        if (t1 == INT64_C(0)) {
            l3 = (l3 + INT64_C(1));
            continue;
        }
        l5 = ((vader_struct_toolchain_ast_Decorator_t*) l4)->f_args;
        t1 = ((vader_array_t*) ((vader_struct_toolchain_ast_Decorator_t*) l4)->f_args)->length;
        l6 = vader_chk_sub(i64, t1, INT64_C(1));
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l6)
        l7 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l6);
        if (l7.tag == 600u) {
            t2 = l7.payload.obj;
            t1 = ((vader_array_t*) ((vader_struct_toolchain_ast_StringLitExpr_t*) t2)->f_parts)->length;
            if (t1 == INT64_C(1)) {
                t2 = l7.payload.obj;
                vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_StringLitExpr_t*) t2)->f_parts);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, INT32_C(0))
                l8 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) INT32_C(0));
                if (l8.tag == 602u) {
                    t2 = l8.payload.obj;
                    t0 = ((vader_struct_toolchain_ast_StringLitText_t*) t2)->f_value;
                    return t0;
                }
            }
        }
        l3 = (l3 + INT64_C(1));
    }
    t0 = ((vader_struct_toolchain_ast_FnDecl_t*) l0)->f_name;
    return t0;
}

static vader_box_t vader_midir_field_read_type(void* l0, int32_t l1, vader_box_t l2) {
    vader_box_t l3 = vader_box_null(), l4 = vader_box_null();
    bool t0;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[4] = { &l2, &l3, &l4, &t1 };
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_types_is_stored_as_integer(VADER_UNION_FIELD(vader_box_t, vader_struct_vader_lower_LoweredFieldAccess_t, f_type, l2.payload.obj));
    if (!(t0)) {
        { vader_box_t __vret = VADER_UNION_FIELD(vader_box_t, vader_struct_vader_lower_LoweredFieldAccess_t, f_type, l2.payload.obj); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = vader_midir_place_slot(l0, vader_box_i32(288u, l1), l2);
    l4 = VADER_UNION_FIELD(vader_box_t, vader_struct_vader_lower_LoweredFieldAccess_t, f_type, l2.payload.obj);
    t1 = vader_midir_read_type(l3, l4);
    { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir_field_slot(void* l0, vader_box_t l1, vader_string_t l2) {
    void* l3 = NULL;
    void* l8 = NULL;
    int64_t l4, l5;
    vader_box_t l6 = vader_box_null(), l7 = vader_box_null();
    void* t0 = NULL;
    vader_string_t t1 = 0;
    vader_box_t* gc_roots[3] = { &l1, &l6, &l7 };
    void** gc_raw_roots[4] = { &l0, &l3, &l8, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l2, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l1.tag == 1270u) {
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_types_UnionType_t*) t0)->f_variants;
        l4 = ((vader_array_t*) l3)->length;
        l5 = INT64_C(0);
        for (;;) {
            if ((l5 < l4)) {
                vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
                VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
                l6 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
                l7 = vader_midir_field_slot(l0, l6, l2);
                if (l7.tag == 0u) {
                    l5 = (l5 + INT64_C(1));
                    continue;
                }
                { vader_box_t __vret = l7; vader_gc_top = gc_frame.prev; return __vret; }
            }
            break;
        }
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l6 = l1;
    l6 = vader_midir_laid_out_fields(l0, l6);
    if (l6.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l3 = l6.payload.obj;
    l4 = ((vader_array_t*) l3)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l8 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5);
        t1 = ((vader_struct_vader_midir_CFGStructField_t*) l8)->f_name;
        if (t1 == l2) {
            { vader_box_t __vret = ((vader_struct_vader_midir_CFGStructField_t*) l8)->f_type; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l5 = (l5 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static vader_box_t vader_midir_find_struct_field_index(void* l0, int32_t l1, vader_string_t l2) {
    vader_box_t l3;
    int64_t l4, l5;
    void* t0;
    vader_string_t t1;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_types);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    l3 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l1);
    if (l3.tag == 652u) {
        l4 = INT64_C(0);
        t0 = l3.payload.obj;
        l5 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcStruct_t*) t0)->f_fields)->length;
        while ((l4 < l5)) {
            t0 = l3.payload.obj;
            vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcStruct_t*) t0)->f_fields);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
            t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
            t1 = ((vader_struct_vader_bytecode_BcField_t*) t0)->f_name;
            if (t1 == l2) {
                return vader_box_i64(289u, l4);
            }
            l4 = (l4 + INT64_C(1));
        }
    }
    return vader_box_obj(0u, NULL);
}

static vader_box_t vader_midir_first_stack_operand(vader_box_t l0) {
    void* t0;
    int64_t t1;
    int32_t t2;
    if (l0.tag == 1106u) {
        return vader_box_obj(0u, NULL);
    }
    if (l0.tag == 1113u) {
        return vader_box_obj(0u, NULL);
    }
    if (l0.tag == 1112u) {
        return vader_box_obj(0u, NULL);
    }
    if (l0.tag == 1107u) {
        return vader_box_obj(0u, NULL);
    }
    if (l0.tag == 1114u) {
        return vader_box_obj(0u, NULL);
    }
    if (l0.tag == 1121u) {
        return vader_box_obj(0u, NULL);
    }
    if (l0.tag == 1118u) {
        t0 = l0.payload.obj;
        return vader_box_i32(288u, ((vader_struct_vader_midir_InstrMove_t*) t0)->f_src);
    }
    if (l0.tag == 1099u) {
        t0 = l0.payload.obj;
        return vader_box_i32(288u, ((vader_struct_vader_midir_InstrBinOp_t*) t0)->f_lhs);
    }
    if (l0.tag == 1122u) {
        t0 = l0.payload.obj;
        return vader_box_i32(288u, ((vader_struct_vader_midir_InstrUnOp_t*) t0)->f_operand);
    }
    if (l0.tag == 1100u) {
        t0 = l0.payload.obj;
        t1 = ((vader_array_t*) ((vader_struct_vader_midir_InstrCall_t*) t0)->f_args)->length;
        if (!((t1 > INT64_C(0)))) {
            return vader_box_obj(0u, NULL);
        }
        t0 = l0.payload.obj;
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_midir_InstrCall_t*) t0)->f_args);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
        t2 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) INT32_C(0)];
        return vader_box_i32(288u, t2);
    }
    if (l0.tag == 1101u) {
        t0 = l0.payload.obj;
        t1 = ((vader_array_t*) ((vader_struct_vader_midir_InstrCallIndirect_t*) t0)->f_args)->length;
        if (!((t1 > INT64_C(0)))) {
            t0 = l0.payload.obj;
            return vader_box_i32(288u, ((vader_struct_vader_midir_InstrCallIndirect_t*) t0)->f_callee);
        }
        t0 = l0.payload.obj;
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_midir_InstrCallIndirect_t*) t0)->f_args);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, INT32_C(0))
        t2 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) INT32_C(0)];
        return vader_box_i32(288u, t2);
    }
    if (l0.tag == 1125u) {
        t0 = l0.payload.obj;
        t1 = ((vader_array_t*) ((vader_struct_vader_midir_InstrVirtualCall_t*) t0)->f_args)->length;
        if (!((t1 > INT64_C(0)))) {
            t0 = l0.payload.obj;
            return vader_box_i32(288u, ((vader_struct_vader_midir_InstrVirtualCall_t*) t0)->f_receiver);
        }
        t0 = l0.payload.obj;
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_midir_InstrVirtualCall_t*) t0)->f_args);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, INT32_C(0))
        t2 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) INT32_C(0)];
        return vader_box_i32(288u, t2);
    }
    if (l0.tag == 1110u) {
        t0 = l0.payload.obj;
        return vader_box_i32(288u, ((vader_struct_vader_midir_InstrFieldGet_t*) t0)->f_target);
    }
    if (l0.tag == 1111u) {
        t0 = l0.payload.obj;
        return vader_box_i32(288u, ((vader_struct_vader_midir_InstrFieldSet_t*) t0)->f_target);
    }
    if (l0.tag == 1123u) {
        t0 = l0.payload.obj;
        return vader_box_i32(288u, ((vader_struct_vader_midir_InstrUnionFieldGet_t*) t0)->f_target);
    }
    if (l0.tag == 1124u) {
        t0 = l0.payload.obj;
        return vader_box_i32(288u, ((vader_struct_vader_midir_InstrUnionFieldSet_t*) t0)->f_target);
    }
    if (l0.tag == 1093u) {
        t0 = l0.payload.obj;
        return vader_box_i32(288u, ((vader_struct_vader_midir_InstrArrayGet_t*) t0)->f_target);
    }
    if (l0.tag == 1097u) {
        t0 = l0.payload.obj;
        return vader_box_i32(288u, ((vader_struct_vader_midir_InstrArraySet_t*) t0)->f_target);
    }
    if (l0.tag == 1094u) {
        t0 = l0.payload.obj;
        return vader_box_i32(288u, ((vader_struct_vader_midir_InstrArrayLen_t*) t0)->f_target);
    }
    if (l0.tag == 1096u) {
        t0 = l0.payload.obj;
        return vader_box_i32(288u, ((vader_struct_vader_midir_InstrArrayPush_t*) t0)->f_target);
    }
    if (l0.tag == 1098u) {
        t0 = l0.payload.obj;
        return vader_box_i32(288u, ((vader_struct_vader_midir_InstrArraySlice_t*) t0)->f_target);
    }
    if (l0.tag == 1119u) {
        t0 = l0.payload.obj;
        t1 = ((vader_array_t*) ((vader_struct_vader_midir_InstrStructNew_t*) t0)->f_fields)->length;
        if (!((t1 > INT64_C(0)))) {
            return vader_box_obj(0u, NULL);
        }
        t0 = l0.payload.obj;
        vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_midir_InstrStructNew_t*) t0)->f_fields);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, INT32_C(0))
        t2 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) INT32_C(0)];
        return vader_box_i32(288u, t2);
    }
    if (l0.tag == 1095u) {
        t0 = l0.payload.obj;
        t1 = ((vader_array_t*) ((vader_struct_vader_midir_InstrArrayNew_t*) t0)->f_elements)->length;
        if (!((t1 > INT64_C(0)))) {
            return vader_box_obj(0u, NULL);
        }
        t0 = l0.payload.obj;
        vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_vader_midir_InstrArrayNew_t*) t0)->f_elements);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, INT32_C(0))
        t2 = ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) INT32_C(0)];
        return vader_box_i32(288u, t2);
    }
    if (l0.tag == 1120u) {
        t0 = l0.payload.obj;
        return vader_box_i32(288u, ((vader_struct_vader_midir_InstrTypeCheck_t*) t0)->f_value);
    }
    if (l0.tag == 1102u) {
        t0 = l0.payload.obj;
        return vader_box_i32(288u, ((vader_struct_vader_midir_InstrCast_t*) t0)->f_value);
    }
    if (l0.tag == 1104u) {
        t0 = l0.payload.obj;
        return vader_box_i32(288u, ((vader_struct_vader_midir_InstrCellNew_t*) t0)->f_value);
    }
    if (l0.tag == 1103u) {
        t0 = l0.payload.obj;
        return vader_box_i32(288u, ((vader_struct_vader_midir_InstrCellGet_t*) t0)->f_cell);
    }
    if (l0.tag == 1105u) {
        t0 = l0.payload.obj;
        return vader_box_i32(288u, ((vader_struct_vader_midir_InstrCellSet_t*) t0)->f_cell);
    }
    if (l0.tag == 1115u) {
        t0 = l0.payload.obj;
        return vader_box_i32(288u, ((vader_struct_vader_midir_InstrGlobalSet_t*) t0)->f_value);
    }
    if (l0.tag == 1117u) {
        t0 = l0.payload.obj;
        return vader_box_i32(288u, ((vader_struct_vader_midir_InstrMakeClosure_t*) t0)->f_env);
    }
    if (l0.tag == 1116u) {
        t0 = l0.payload.obj;
        t1 = ((vader_array_t*) ((vader_struct_vader_midir_InstrIntrinsic_t*) t0)->f_args)->length;
        if (!((t1 > INT64_C(0)))) {
            return vader_box_obj(0u, NULL);
        }
        t0 = l0.payload.obj;
        vader_array_t* _a5_slotarr = ((vader_array_t*) ((vader_struct_vader_midir_InstrIntrinsic_t*) t0)->f_args);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, INT32_C(0))
        t2 = ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) INT32_C(0)];
        return vader_box_i32(288u, t2);
    }
    if (l0.tag == 1109u) {
        t0 = l0.payload.obj;
        return vader_box_i32(288u, ((vader_struct_vader_midir_InstrDeferPush_t*) t0)->f_value);
    }
    if (!(l0.tag == 1108u)) {
        vader_unreachable("non-exhaustive match (T3013 should have caught this)");
    }
    return vader_box_obj(0u, NULL);
}

static vader_box_t vader_midir_first_terminator_operand(vader_box_t l0) {
    void* t0;
    vader_box_t t1;
    if (l0.tag == 1136u) {
        return vader_box_obj(0u, NULL);
    }
    if (l0.tag == 1139u) {
        return vader_box_obj(0u, NULL);
    }
    if (l0.tag == 1137u) {
        t0 = l0.payload.obj;
        return vader_box_i32(288u, ((vader_struct_vader_midir_TermCondBranch_t*) t0)->f_cond);
    }
    if (!(l0.tag == 1138u)) {
        vader_unreachable("non-exhaustive match (T3013 should have caught this)");
    }
    t0 = l0.payload.obj;
    t1 = vader_midir_term_return_single(t0);
    return t1;
}

static bool vader_midir_fits_in(uint8_t l0, uint8_t l1) {
    bool l2, l3;
    if (l1 == INT32_C(4)) {
        l2 = l0 == INT32_C(4);
        return l2;
    }
    if (l1 == INT32_C(0)) {
        l2 = l0 == INT32_C(0);
    } else if (l1 == INT32_C(5)) {
        if (l0 == INT32_C(4)) {
            l2 = true;
        } else {
            l2 = l0 == INT32_C(5);
        }
    } else if (l1 == INT32_C(1)) {
        if (l0 == INT32_C(4)) {
            l3 = true;
        } else {
            l3 = l0 == INT32_C(0);
        }
        if (l3) {
            l2 = true;
        } else {
            l2 = l0 == INT32_C(1);
        }
    } else {
        if (l1 == INT32_C(2)) {
            l3 = true;
        } else {
            l3 = l1 == INT32_C(3);
        }
        if (l3) {
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
            l3 = true;
        } else {
            l3 = l1 == INT32_C(8);
        }
        if (l3) {
            l3 = true;
        } else {
            l3 = l1 == INT32_C(9);
        }
        if (l3) {
            l3 = true;
        } else {
            l3 = l1 == INT32_C(10);
        }
        if (l3) {
            l3 = true;
        } else {
            l3 = l1 == INT32_C(11);
        }
        if (l3) {
            l3 = true;
        } else {
            l3 = l1 == INT32_C(12);
        }
        if (l3) {
            l3 = true;
        } else {
            l3 = l1 == INT32_C(13);
        }
        if (l3) {
            l3 = true;
        } else {
            l3 = l1 == INT32_C(14);
        }
        if (l3) {
            l3 = true;
        } else {
            l3 = l1 == INT32_C(15);
        }
        if (l3) {
            l3 = true;
        } else {
            l3 = l1 == INT32_C(16);
        }
        if (l3) {
            l3 = true;
        } else {
            l3 = l1 == INT32_C(17);
        }
        if (!(l3)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l2 = true;
    }
    return l2;
}

static void* vader_midir_fn_metadata(void* l0) {
    vader_string_t l1 = 0;
    vader_string_t l4 = 0;
    vader_string_t l5 = 0;
    bool l2, l3, l8;
    int32_t l6;
    vader_box_t l7 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l7 };
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_string_t* gc_atom_roots[3] = { &l1, &l4, &l5 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct_vader_lower_LoweredFnDecl_t*) l0)->f_mangled;
    l2 = false;
    l3 = false;
    l4 = 0u;
    l5 = 0u;
    l6 = INT32_C(-1);
    l7 = ((vader_struct_vader_comptime_MonoEntry_t*) ((vader_struct_vader_lower_LoweredFnDecl_t*) l0)->f_origin)->f_decl;
    if (l7.tag == 560u) {
        t0 = l7.payload.obj;
        l1 = vader_midir_extern_symbol_name(t0);
        if (((vader_struct_vader_lower_LoweredFnDecl_t*) l0)->f_body.tag == 0u) {
            t0 = l7.payload.obj;
            l8 = toolchain_ast_decorators_have(((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_decorators, 1754u);
        } else {
            l8 = false;
        }
        l2 = l8;
        t0 = l7.payload.obj;
        l3 = toolchain_ast_decorators_have(((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_decorators, 1740u);
        t0 = l7.payload.obj;
        l4 = vader_midir_c_header_of(((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_decorators);
        t0 = l7.payload.obj;
        l5 = vader_midir_extern_library_name(t0);
        t0 = l7.payload.obj;
        l6 = vader_midir_c_variadic_fixed_of(((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_decorators);
        vader_struct_vader_midir_FnMetadata_t* _a0_obj = (vader_struct_vader_midir_FnMetadata_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_FnMetadata_t));
        vader_obj_header_init(_a0_obj, 1092u);
        _a0_obj->f_extern_name = l1;
        _a0_obj->f_is_extern = l2;
        _a0_obj->f_c_variadic_fixed = l6;
        _a0_obj->f_is_exported = l3;
        _a0_obj->f_c_library = l5;
        _a0_obj->f_c_header = l4;
        t0 = (void*) _a0_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_midir_FnMetadata_t* _a1_obj = (vader_struct_vader_midir_FnMetadata_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_FnMetadata_t));
    vader_obj_header_init(_a1_obj, 1092u);
    _a1_obj->f_extern_name = l1;
    _a1_obj->f_is_extern = l2;
    _a1_obj->f_c_variadic_fixed = l6;
    _a1_obj->f_is_exported = l3;
    _a1_obj->f_c_library = l5;
    _a1_obj->f_c_header = l4;
    t0 = (void*) _a1_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_midir_fold_moves(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    int64_t l5, l6;
    int32_t l7;
    vader_box_t l12 = vader_box_null();
    vader_string_t l15 = 0;
    vader_string_t l16 = 0;
    bool l17, l18;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l12 };
    void** gc_raw_roots[12] = { &l0, &l1, &l2, &l3, &l4, &l8, &l9, &l10, &l11, &l13, &l14, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l15, &l16 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 12u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = vader_midir_count_uses(l0);
    vader_array_t* _a0_arr = vader_array_new(15u, 0u, 7u, 288u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(12u, 0u, 12u, 283u);
    l3 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(15u, 0u, 7u, 288u);
    l4 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__i32__bool_t* _a3_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
    vader_obj_header_init(_a3_obj, 381u);
    _a3_obj->f_ekeys = l2;
    _a3_obj->f_evals = l3;
    _a3_obj->f_index = l4;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a3_obj;
    vader_struct_std_collections_MutableSet__i32_t* _a4_obj = (vader_struct_std_collections_MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i32_t));
    vader_obj_header_init(_a4_obj, 517u);
    _a4_obj->f_inner = t0;
    l2 = (void*) _a4_obj;
    l3 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_params;
    l5 = ((vader_array_t*) l3)->length;
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a5_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        t0 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l6);
        l7 = ((vader_struct_vader_midir_CFGParam_t*) t0)->f_local;
        std_collections_add__i32(l2, l7);
        l6 = (l6 + INT64_C(1));
    }
    vader_array_t* _a6_arr = vader_array_new(135u, 0u, 13u, 1069u);
    l3 = (void*) _a6_arr;
    l5 = ((vader_array_t*) ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_blocks)->length;
    vader_array_t* _a7_arr = vader_array_repeat((vader_array_t*) l3, (int64_t) l5);
    l3 = (void*) _a7_arr;
    l4 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_blocks;
    l5 = ((vader_array_t*) l4)->length;
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a8_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l6)
        l8 = vader_array_ref_load_obj(_a8_slotarr->buf, _a8_slotarr->offset + (size_t) l6);
        l9 = l8;
        l7 = ((vader_struct_vader_midir_BasicBlock_t*) l9)->f_id;
        l10 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_locals;
        l11 = vader_midir_fold_moves_in_block(l8, l10, l1, l2);
        l12 = ((vader_struct_vader_midir_BasicBlock_t*) l9)->f_terminator;
        l13 = ((vader_struct_vader_midir_BasicBlock_t*) l9)->f_span;
        vader_struct_vader_midir_BasicBlock_t* _a9_obj = (vader_struct_vader_midir_BasicBlock_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_BasicBlock_t));
        vader_obj_header_init(_a9_obj, 1069u);
        _a9_obj->f_id = l7;
        _a9_obj->f_instructions = l11;
        _a9_obj->f_terminator = l12;
        _a9_obj->f_span = l13;
        l14 = (void*) _a9_obj;
        vader_array_push((vader_array_t*) l3, vader_ref_box(l14));
        l6 = (l6 + INT64_C(1));
    }
    l1 = l0;
    l15 = ((vader_struct_vader_midir_CFGFunction_t*) l1)->f_mangled;
    l2 = ((vader_struct_vader_midir_CFGFunction_t*) l1)->f_params;
    l12 = ((vader_struct_vader_midir_CFGFunction_t*) l1)->f_return_type;
    l4 = ((vader_struct_vader_midir_CFGFunction_t*) l1)->f_locals;
    l7 = ((vader_struct_vader_midir_CFGFunction_t*) l1)->f_entry;
    l8 = ((vader_struct_vader_midir_CFGFunction_t*) l1)->f_origin;
    l16 = ((vader_struct_vader_midir_CFGFunction_t*) l1)->f_extern_name;
    l17 = ((vader_struct_vader_midir_CFGFunction_t*) l1)->f_is_extern;
    l18 = ((vader_struct_vader_midir_CFGFunction_t*) l1)->f_is_exported;
    l1 = ((vader_struct_vader_midir_CFGFunction_t*) l1)->f_scalarised_results;
    vader_struct_vader_midir_CFGFunction_t* _a10_obj = (vader_struct_vader_midir_CFGFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_CFGFunction_t));
    vader_obj_header_init(_a10_obj, 1071u);
    _a10_obj->f_mangled = l15;
    _a10_obj->f_params = l2;
    _a10_obj->f_return_type = l12;
    _a10_obj->f_locals = l4;
    _a10_obj->f_blocks = l3;
    _a10_obj->f_entry = l7;
    _a10_obj->f_origin = l8;
    _a10_obj->f_extern_name = l16;
    _a10_obj->f_is_extern = l17;
    _a10_obj->f_is_exported = l18;
    _a10_obj->f_scalarised_results = l1;
    t0 = (void*) _a10_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_midir_fold_moves_in_block(void* l0, void* l1, void* l2, void* l3) {
    void* l4 = NULL;
    void* l10 = NULL;
    void* l15 = NULL;
    void* l16 = NULL;
    void* l20 = NULL;
    void* l26 = NULL;
    void* l28 = NULL;
    void* l30 = NULL;
    int64_t l5, l6, l18, l21;
    vader_box_t l7 = vader_box_null(), l8 = vader_box_null(), l13 = vader_box_null(), l22 = vader_box_null(), l23 = vader_box_null(), l29 = vader_box_null(), l31 = vader_box_null(), l33 = vader_box_null();
    int32_t l9, l11, l12, l17, l24, l25, l32;
    bool l14, l19, l27;
    void* t0 = NULL;
    bool t1;
    int64_t t2;
    int32_t t3;
    vader_box_t t4 = vader_box_null();
    vader_box_t* gc_roots[9] = { &l7, &l8, &l13, &l22, &l23, &l29, &l31, &l33, &t4 };
    void** gc_raw_roots[13] = {
        &l0, &l1, &l2, &l3, &l4, &l10, &l15, &l16, &l20, &l26, &l28, &l30, &t0,
    };
    vader_gc_frame_t gc_frame = { vader_gc_top, 9u, 13u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(242u, 0u, 13u, 1745u);
    l4 = (void*) _a0_arr;
    l5 = INT64_C(0);
    l6 = ((vader_array_t*) ((vader_struct_vader_midir_BasicBlock_t*) l0)->f_instructions)->length;
    while ((l5 < l6)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_midir_BasicBlock_t*) l0)->f_instructions);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
        l7 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5);
        if (l7.tag == 1118u) {
            if (l7.tag == 1118u) {
                t0 = l7.payload.obj;
                l9 = ((vader_struct_vader_midir_InstrMove_t*) t0)->f_src;
                t1 = std_collections_MutableSet_std_core_Contains_contains__i32(l3, l9);
                if (t1) {
                    l10 = l7.payload.obj;
                    vader_array_push((vader_array_t*) l4, vader_ref_box(l10));
                    l5 = (l5 + INT64_C(1));
                    continue;
                }
                t0 = l7.payload.obj;
                l12 = ((vader_struct_vader_midir_InstrMove_t*) t0)->f_src;
                l13 = std_collections_MutableMap_std_core_Index_at__i32__i32(l2, l12);
                if (l13.tag == 0u) {
                    l11 = INT32_C(0);
                } else {
                    l11 = ((int32_t) l13.payload.i);
                }
                if (l11 != INT32_C(1)) {
                    l14 = true;
                } else {
                    l15 = l7.payload.obj;
                    l14 = vader_midir_move_retags(l1, l15);
                }
                if (l14) {
                    l16 = l7.payload.obj;
                    vader_array_push((vader_array_t*) l4, vader_ref_box(l16));
                    l5 = (l5 + INT64_C(1));
                    continue;
                }
                t0 = l7.payload.obj;
                l17 = ((vader_struct_vader_midir_InstrMove_t*) t0)->f_dst;
                l18 = INT64_C(-1);
                l19 = false;
                vader_array_t* _a2_arr = vader_array_new(12u, 1u, 12u, 283u);
                ((uint8_t*) _a2_arr->buf->slots)[_a2_arr->offset + 0u] = (uint8_t) false;
                l20 = (void*) _a2_arr;
                t2 = ((vader_array_t*) l4)->length;
                l21 = vader_chk_sub(i64, t2, INT64_C(1));
                while ((l21 >= INT64_C(0))) {
                    vader_array_t* _a3_slotarr = ((vader_array_t*) l4);
                    VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l21)
                    l22 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l21);
                    l23 = vader_midir_dst_of(l22);
                    if (l23.tag == 288u) {
                        l24 = ((int32_t) l23.payload.i);
                        t0 = l7.payload.obj;
                        l25 = ((vader_struct_vader_midir_InstrMove_t*) t0)->f_src;
                        t1 = vader_midir_LocalId_std_core_Equals_equals(l24, l25);
                        if (t1) {
                            l18 = l21;
                            break;
                        }
                        t3 = ((int32_t) l23.payload.i);
                        t1 = vader_midir_LocalId_std_core_Equals_equals(t3, l17);
                        if (t1) {
                            l19 = true;
                            break;
                        }
                    }
                    vader_array_t* _a4_slotarr = ((vader_array_t*) l20);
                    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a4_slotarr, INT32_C(0))
                    ((uint8_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) INT32_C(0)] = (uint8_t) false;
                    vader_struct___lambda_env_vader_midir_5_t* _a5_obj = (vader_struct___lambda_env_vader_midir_5_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_midir_5_t));
                    vader_obj_header_init(_a5_obj, 343u);
                    _a5_obj->f_cap_0 = l17;
                    _a5_obj->f_cap_1 = l20;
                    t0 = (void*) _a5_obj;
                    vader_fn_t* _a6_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
                    vader_obj_header_init(_a6_closure, 261u);
                    _a6_closure->code = (void*) &vader_fn_lift___lambda_vader_midir_4;
                    _a6_closure->env = t0;
                    l26 = (void*) _a6_closure;
                    vader_midir_for_each_read_local(l22, l26);
                    vader_array_t* _a7_slotarr = ((vader_array_t*) l20);
                    VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a7_slotarr, INT32_C(0))
                    t4 = vader_box_bool(283u, ((uint8_t*) _a7_slotarr->buf->slots)[_a7_slotarr->offset + (size_t) INT32_C(0)]);
                    t1 = t4.payload.b;
                    if (t1) {
                        l19 = true;
                        break;
                    }
                    l21 = vader_chk_sub(i64, l21, INT64_C(1));
                }
                if ((l18 < INT64_C(0))) {
                    l27 = true;
                } else {
                    l27 = l19;
                }
                if (l27) {
                    l28 = l7.payload.obj;
                    vader_array_push((vader_array_t*) l4, vader_ref_box(l28));
                    l5 = (l5 + INT64_C(1));
                    continue;
                }
                vader_array_t* _a8_slotarr = ((vader_array_t*) l4);
                VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l18)
                l29 = vader_array_ref_load_box(_a8_slotarr->buf, _a8_slotarr->offset + (size_t) l18);
                t1 = vader_midir_instruction_has_side_effect(l29);
                if (t1) {
                    l30 = l7.payload.obj;
                    vader_array_push((vader_array_t*) l4, vader_ref_box(l30));
                    l5 = (l5 + INT64_C(1));
                    continue;
                }
                l31 = l29;
                t0 = l7.payload.obj;
                l32 = ((vader_struct_vader_midir_InstrMove_t*) t0)->f_dst;
                l33 = vader_midir_with_dst(l31, l32);
                vader_array_t* _a9_slotarr = ((vader_array_t*) l4);
                VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l18)
                vader_array_ref_store(_a9_slotarr->buf, _a9_slotarr->offset + (size_t) l18, l33.payload.obj);
                VADER_WRITE_BARRIER(_a9_slotarr->buf);
            }
            l5 = (l5 + INT64_C(1));
            continue;
        }
        l8 = l7;
        vader_array_push((vader_array_t*) l4, l8);
        l5 = (l5 + INT64_C(1));
    }
    { void* __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_midir_for_each_read_in_terminator(vader_box_t l0, void* l1) {
    void* l2 = NULL;
    int64_t l3, l4;
    void* t0 = NULL;
    int32_t t1;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[3] = { &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 1137u) {
        t0 = l0.payload.obj;
        vader_fn_t* _a0_fnobj = (vader_fn_t*) l1;
        ((vader_fn_erased_sig_1_t) _a0_fnobj->code)(_a0_fnobj->env, vader_box_i32(288u, ((vader_struct_vader_midir_TermCondBranch_t*) t0)->f_cond));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 1138u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_midir_TermReturn_t*) t0)->f_values;
        l3 = ((vader_array_t*) l2)->length;
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
            t1 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
            vader_fn_t* _a2_fnobj = (vader_fn_t*) l1;
            ((vader_fn_erased_sig_1_t) _a2_fnobj->code)(_a2_fnobj->env, vader_box_i32(288u, t1));
            l4 = (l4 + INT64_C(1));
        }
    } else if (!(l0.tag == 1136u)) {
        if (!(l0.tag == 1139u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_midir_for_each_read_local(vader_box_t l0, void* l1) {
    void* l2 = NULL;
    int64_t l3, l4;
    void* t0 = NULL;
    int32_t t1;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[3] = { &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 1106u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (!(l0.tag == 1113u)) {
        if (!(l0.tag == 1112u)) {
            if (l0.tag == 1118u) {
                t0 = l0.payload.obj;
                vader_fn_t* _a0_fnobj = (vader_fn_t*) l1;
                ((vader_fn_erased_sig_1_t) _a0_fnobj->code)(_a0_fnobj->env, vader_box_i32(288u, ((vader_struct_vader_midir_InstrMove_t*) t0)->f_src));
            } else if (l0.tag == 1099u) {
                t0 = l0.payload.obj;
                vader_fn_t* _a1_fnobj = (vader_fn_t*) l1;
                ((vader_fn_erased_sig_1_t) _a1_fnobj->code)(_a1_fnobj->env, vader_box_i32(288u, ((vader_struct_vader_midir_InstrBinOp_t*) t0)->f_lhs));
                t0 = l0.payload.obj;
                vader_fn_t* _a2_fnobj = (vader_fn_t*) l1;
                ((vader_fn_erased_sig_1_t) _a2_fnobj->code)(_a2_fnobj->env, vader_box_i32(288u, ((vader_struct_vader_midir_InstrBinOp_t*) t0)->f_rhs));
            } else if (l0.tag == 1122u) {
                t0 = l0.payload.obj;
                vader_fn_t* _a3_fnobj = (vader_fn_t*) l1;
                ((vader_fn_erased_sig_1_t) _a3_fnobj->code)(_a3_fnobj->env, vader_box_i32(288u, ((vader_struct_vader_midir_InstrUnOp_t*) t0)->f_operand));
            } else if (l0.tag == 1100u) {
                t0 = l0.payload.obj;
                l2 = ((vader_struct_vader_midir_InstrCall_t*) t0)->f_args;
                l3 = ((vader_array_t*) l2)->length;
                l4 = INT64_C(0);
                while ((l4 < l3)) {
                    vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
                    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l4)
                    t1 = ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l4];
                    vader_fn_t* _a5_fnobj = (vader_fn_t*) l1;
                    ((vader_fn_erased_sig_1_t) _a5_fnobj->code)(_a5_fnobj->env, vader_box_i32(288u, t1));
                    l4 = (l4 + INT64_C(1));
                }
            } else if (l0.tag == 1101u) {
                t0 = l0.payload.obj;
                vader_fn_t* _a6_fnobj = (vader_fn_t*) l1;
                ((vader_fn_erased_sig_1_t) _a6_fnobj->code)(_a6_fnobj->env, vader_box_i32(288u, ((vader_struct_vader_midir_InstrCallIndirect_t*) t0)->f_callee));
                t0 = l0.payload.obj;
                l2 = ((vader_struct_vader_midir_InstrCallIndirect_t*) t0)->f_args;
                l3 = ((vader_array_t*) l2)->length;
                l4 = INT64_C(0);
                while ((l4 < l3)) {
                    vader_array_t* _a7_slotarr = ((vader_array_t*) l2);
                    VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l4)
                    t1 = ((int32_t*) _a7_slotarr->buf->slots)[_a7_slotarr->offset + (size_t) l4];
                    vader_fn_t* _a8_fnobj = (vader_fn_t*) l1;
                    ((vader_fn_erased_sig_1_t) _a8_fnobj->code)(_a8_fnobj->env, vader_box_i32(288u, t1));
                    l4 = (l4 + INT64_C(1));
                }
            } else if (l0.tag == 1125u) {
                t0 = l0.payload.obj;
                vader_fn_t* _a9_fnobj = (vader_fn_t*) l1;
                ((vader_fn_erased_sig_1_t) _a9_fnobj->code)(_a9_fnobj->env, vader_box_i32(288u, ((vader_struct_vader_midir_InstrVirtualCall_t*) t0)->f_receiver));
                t0 = l0.payload.obj;
                l2 = ((vader_struct_vader_midir_InstrVirtualCall_t*) t0)->f_args;
                l3 = ((vader_array_t*) l2)->length;
                l4 = INT64_C(0);
                while ((l4 < l3)) {
                    vader_array_t* _a10_slotarr = ((vader_array_t*) l2);
                    VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a10_slotarr, l4)
                    t1 = ((int32_t*) _a10_slotarr->buf->slots)[_a10_slotarr->offset + (size_t) l4];
                    vader_fn_t* _a11_fnobj = (vader_fn_t*) l1;
                    ((vader_fn_erased_sig_1_t) _a11_fnobj->code)(_a11_fnobj->env, vader_box_i32(288u, t1));
                    l4 = (l4 + INT64_C(1));
                }
            } else if ((l0.tag == 1110u || l0.tag == 1123u)) {
                vader_fn_t* _a12_fnobj = (vader_fn_t*) l1;
                ((vader_fn_erased_sig_1_t) _a12_fnobj->code)(_a12_fnobj->env, vader_box_i32(288u, VADER_UNION_FIELD(int32_t, vader_struct_vader_midir_InstrFieldGet_t, f_target, l0.payload.obj)));
            } else if ((l0.tag == 1111u || l0.tag == 1124u)) {
                vader_fn_t* _a13_fnobj = (vader_fn_t*) l1;
                ((vader_fn_erased_sig_1_t) _a13_fnobj->code)(_a13_fnobj->env, vader_box_i32(288u, VADER_UNION_FIELD(int32_t, vader_struct_vader_midir_InstrFieldSet_t, f_target, l0.payload.obj)));
                vader_fn_t* _a14_fnobj = (vader_fn_t*) l1;
                ((vader_fn_erased_sig_1_t) _a14_fnobj->code)(_a14_fnobj->env, vader_box_i32(288u, VADER_UNION_FIELD(int32_t, vader_struct_vader_midir_InstrFieldSet_t, f_value, l0.payload.obj)));
            } else if (l0.tag == 1093u) {
                t0 = l0.payload.obj;
                vader_fn_t* _a15_fnobj = (vader_fn_t*) l1;
                ((vader_fn_erased_sig_1_t) _a15_fnobj->code)(_a15_fnobj->env, vader_box_i32(288u, ((vader_struct_vader_midir_InstrArrayGet_t*) t0)->f_target));
                t0 = l0.payload.obj;
                vader_fn_t* _a16_fnobj = (vader_fn_t*) l1;
                ((vader_fn_erased_sig_1_t) _a16_fnobj->code)(_a16_fnobj->env, vader_box_i32(288u, ((vader_struct_vader_midir_InstrArrayGet_t*) t0)->f_index));
            } else if (l0.tag == 1097u) {
                t0 = l0.payload.obj;
                vader_fn_t* _a17_fnobj = (vader_fn_t*) l1;
                ((vader_fn_erased_sig_1_t) _a17_fnobj->code)(_a17_fnobj->env, vader_box_i32(288u, ((vader_struct_vader_midir_InstrArraySet_t*) t0)->f_target));
                t0 = l0.payload.obj;
                vader_fn_t* _a18_fnobj = (vader_fn_t*) l1;
                ((vader_fn_erased_sig_1_t) _a18_fnobj->code)(_a18_fnobj->env, vader_box_i32(288u, ((vader_struct_vader_midir_InstrArraySet_t*) t0)->f_index));
                t0 = l0.payload.obj;
                vader_fn_t* _a19_fnobj = (vader_fn_t*) l1;
                ((vader_fn_erased_sig_1_t) _a19_fnobj->code)(_a19_fnobj->env, vader_box_i32(288u, ((vader_struct_vader_midir_InstrArraySet_t*) t0)->f_value));
            } else if (l0.tag == 1094u) {
                t0 = l0.payload.obj;
                vader_fn_t* _a20_fnobj = (vader_fn_t*) l1;
                ((vader_fn_erased_sig_1_t) _a20_fnobj->code)(_a20_fnobj->env, vader_box_i32(288u, ((vader_struct_vader_midir_InstrArrayLen_t*) t0)->f_target));
            } else if (l0.tag == 1096u) {
                t0 = l0.payload.obj;
                vader_fn_t* _a21_fnobj = (vader_fn_t*) l1;
                ((vader_fn_erased_sig_1_t) _a21_fnobj->code)(_a21_fnobj->env, vader_box_i32(288u, ((vader_struct_vader_midir_InstrArrayPush_t*) t0)->f_target));
                t0 = l0.payload.obj;
                vader_fn_t* _a22_fnobj = (vader_fn_t*) l1;
                ((vader_fn_erased_sig_1_t) _a22_fnobj->code)(_a22_fnobj->env, vader_box_i32(288u, ((vader_struct_vader_midir_InstrArrayPush_t*) t0)->f_value));
            } else if (l0.tag == 1098u) {
                t0 = l0.payload.obj;
                vader_fn_t* _a23_fnobj = (vader_fn_t*) l1;
                ((vader_fn_erased_sig_1_t) _a23_fnobj->code)(_a23_fnobj->env, vader_box_i32(288u, ((vader_struct_vader_midir_InstrArraySlice_t*) t0)->f_target));
                t0 = l0.payload.obj;
                vader_fn_t* _a24_fnobj = (vader_fn_t*) l1;
                ((vader_fn_erased_sig_1_t) _a24_fnobj->code)(_a24_fnobj->env, vader_box_i32(288u, ((vader_struct_vader_midir_InstrArraySlice_t*) t0)->f_lo));
                t0 = l0.payload.obj;
                vader_fn_t* _a25_fnobj = (vader_fn_t*) l1;
                ((vader_fn_erased_sig_1_t) _a25_fnobj->code)(_a25_fnobj->env, vader_box_i32(288u, ((vader_struct_vader_midir_InstrArraySlice_t*) t0)->f_hi));
            } else if (l0.tag == 1119u) {
                t0 = l0.payload.obj;
                l2 = ((vader_struct_vader_midir_InstrStructNew_t*) t0)->f_fields;
                l3 = ((vader_array_t*) l2)->length;
                l4 = INT64_C(0);
                while ((l4 < l3)) {
                    vader_array_t* _a26_slotarr = ((vader_array_t*) l2);
                    VADER_ARRAY_RESOLVE_BUF(_a26_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a26_slotarr, l4)
                    t1 = ((int32_t*) _a26_slotarr->buf->slots)[_a26_slotarr->offset + (size_t) l4];
                    vader_fn_t* _a27_fnobj = (vader_fn_t*) l1;
                    ((vader_fn_erased_sig_1_t) _a27_fnobj->code)(_a27_fnobj->env, vader_box_i32(288u, t1));
                    l4 = (l4 + INT64_C(1));
                }
            } else if (l0.tag == 1095u) {
                t0 = l0.payload.obj;
                l2 = ((vader_struct_vader_midir_InstrArrayNew_t*) t0)->f_elements;
                l3 = ((vader_array_t*) l2)->length;
                l4 = INT64_C(0);
                while ((l4 < l3)) {
                    vader_array_t* _a28_slotarr = ((vader_array_t*) l2);
                    VADER_ARRAY_RESOLVE_BUF(_a28_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a28_slotarr, l4)
                    t1 = ((int32_t*) _a28_slotarr->buf->slots)[_a28_slotarr->offset + (size_t) l4];
                    vader_fn_t* _a29_fnobj = (vader_fn_t*) l1;
                    ((vader_fn_erased_sig_1_t) _a29_fnobj->code)(_a29_fnobj->env, vader_box_i32(288u, t1));
                    l4 = (l4 + INT64_C(1));
                }
            } else if (l0.tag == 1120u) {
                t0 = l0.payload.obj;
                vader_fn_t* _a30_fnobj = (vader_fn_t*) l1;
                ((vader_fn_erased_sig_1_t) _a30_fnobj->code)(_a30_fnobj->env, vader_box_i32(288u, ((vader_struct_vader_midir_InstrTypeCheck_t*) t0)->f_value));
            } else if (!(l0.tag == 1121u)) {
                if (!(l0.tag == 1107u)) {
                    if (!(l0.tag == 1114u)) {
                        if (l0.tag == 1115u) {
                            t0 = l0.payload.obj;
                            vader_fn_t* _a31_fnobj = (vader_fn_t*) l1;
                            ((vader_fn_erased_sig_1_t) _a31_fnobj->code)(_a31_fnobj->env, vader_box_i32(288u, ((vader_struct_vader_midir_InstrGlobalSet_t*) t0)->f_value));
                        } else if (l0.tag == 1102u) {
                            t0 = l0.payload.obj;
                            vader_fn_t* _a32_fnobj = (vader_fn_t*) l1;
                            ((vader_fn_erased_sig_1_t) _a32_fnobj->code)(_a32_fnobj->env, vader_box_i32(288u, ((vader_struct_vader_midir_InstrCast_t*) t0)->f_value));
                        } else if (l0.tag == 1104u) {
                            t0 = l0.payload.obj;
                            vader_fn_t* _a33_fnobj = (vader_fn_t*) l1;
                            ((vader_fn_erased_sig_1_t) _a33_fnobj->code)(_a33_fnobj->env, vader_box_i32(288u, ((vader_struct_vader_midir_InstrCellNew_t*) t0)->f_value));
                        } else if (l0.tag == 1103u) {
                            t0 = l0.payload.obj;
                            vader_fn_t* _a34_fnobj = (vader_fn_t*) l1;
                            ((vader_fn_erased_sig_1_t) _a34_fnobj->code)(_a34_fnobj->env, vader_box_i32(288u, ((vader_struct_vader_midir_InstrCellGet_t*) t0)->f_cell));
                        } else if (l0.tag == 1105u) {
                            t0 = l0.payload.obj;
                            vader_fn_t* _a35_fnobj = (vader_fn_t*) l1;
                            ((vader_fn_erased_sig_1_t) _a35_fnobj->code)(_a35_fnobj->env, vader_box_i32(288u, ((vader_struct_vader_midir_InstrCellSet_t*) t0)->f_cell));
                            t0 = l0.payload.obj;
                            vader_fn_t* _a36_fnobj = (vader_fn_t*) l1;
                            ((vader_fn_erased_sig_1_t) _a36_fnobj->code)(_a36_fnobj->env, vader_box_i32(288u, ((vader_struct_vader_midir_InstrCellSet_t*) t0)->f_value));
                        } else if (l0.tag == 1117u) {
                            t0 = l0.payload.obj;
                            vader_fn_t* _a37_fnobj = (vader_fn_t*) l1;
                            ((vader_fn_erased_sig_1_t) _a37_fnobj->code)(_a37_fnobj->env, vader_box_i32(288u, ((vader_struct_vader_midir_InstrMakeClosure_t*) t0)->f_env));
                        } else if (l0.tag == 1116u) {
                            t0 = l0.payload.obj;
                            l2 = ((vader_struct_vader_midir_InstrIntrinsic_t*) t0)->f_args;
                            l3 = ((vader_array_t*) l2)->length;
                            l4 = INT64_C(0);
                            while ((l4 < l3)) {
                                vader_array_t* _a38_slotarr = ((vader_array_t*) l2);
                                VADER_ARRAY_RESOLVE_BUF(_a38_slotarr)
                                VADER_ARRAY_CHECK_INDEX(_a38_slotarr, l4)
                                t1 = ((int32_t*) _a38_slotarr->buf->slots)[_a38_slotarr->offset + (size_t) l4];
                                vader_fn_t* _a39_fnobj = (vader_fn_t*) l1;
                                ((vader_fn_erased_sig_1_t) _a39_fnobj->code)(_a39_fnobj->env, vader_box_i32(288u, t1));
                                l4 = (l4 + INT64_C(1));
                            }
                        } else if (l0.tag == 1109u) {
                            t0 = l0.payload.obj;
                            vader_fn_t* _a40_fnobj = (vader_fn_t*) l1;
                            ((vader_fn_erased_sig_1_t) _a40_fnobj->code)(_a40_fnobj->env, vader_box_i32(288u, ((vader_struct_vader_midir_InstrDeferPush_t*) t0)->f_value));
                        } else if (!(l0.tag == 1108u)) {
                            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
                        }
                    }
                }
            }
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void* vader_midir_freeze_block(void* l0) {
    int32_t l1;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    vader_box_t l5 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l5 };
    void** gc_raw_roots[5] = { &l0, &l2, &l3, &l4, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (!(((vader_struct_vader_midir_MutableBlock_t*) l0)->f_terminator.tag == 0u)) {
        l1 = ((vader_struct_vader_midir_MutableBlock_t*) l0)->f_id;
        l2 = ((vader_struct_vader_midir_MutableBlock_t*) l0)->f_instructions;
        l5 = ((vader_struct_vader_midir_MutableBlock_t*) l0)->f_terminator;
        l3 = ((vader_struct_vader_midir_MutableBlock_t*) l0)->f_span;
        vader_struct_vader_midir_BasicBlock_t* _a0_obj = (vader_struct_vader_midir_BasicBlock_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_BasicBlock_t));
        vader_obj_header_init(_a0_obj, 1069u);
        _a0_obj->f_id = l1;
        _a0_obj->f_instructions = l2;
        _a0_obj->f_terminator = l5;
        _a0_obj->f_span = l3;
        t0 = (void*) _a0_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l1 = ((vader_struct_vader_midir_MutableBlock_t*) l0)->f_id;
    l2 = ((vader_struct_vader_midir_MutableBlock_t*) l0)->f_instructions;
    vader_struct_vader_midir_TermUnreachable_t* _a1_obj = (vader_struct_vader_midir_TermUnreachable_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_TermUnreachable_t));
    vader_obj_header_init(_a1_obj, 1139u);
    _a1_obj->f_span = ((vader_struct_vader_midir_MutableBlock_t*) l0)->f_span;
    _a1_obj->f_reason = 2149u;
    l3 = (void*) _a1_obj;
    l4 = ((vader_struct_vader_midir_MutableBlock_t*) l0)->f_span;
    vader_struct_vader_midir_BasicBlock_t* _a2_obj = (vader_struct_vader_midir_BasicBlock_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_BasicBlock_t));
    vader_obj_header_init(_a2_obj, 1069u);
    _a2_obj->f_id = l1;
    _a2_obj->f_instructions = l2;
    _a2_obj->f_terminator = vader_ref_box(l3);
    _a2_obj->f_span = l4;
    t0 = (void*) _a2_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static int32_t vader_midir_fresh_tmp(void* l0, vader_string_t l1, vader_box_t l2) {
    vader_string_t l3 = 0;
    int64_t l4, l6;
    void* l5 = NULL;
    int32_t t0;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[2] = { &l0, &l5 };
    vader_string_t* gc_atom_roots[2] = { &l1, &l3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = l1;
    l4 = vader_host_std_core_byte_len(l3);
    l5 = (void*) vader_buffer_new((size_t) (INT64_C(22) + l4));
    l4 = INT64_C(0);
    l4 = std_core_write_string_at(l5, l4, 210u);
    l4 = std_core_write_string_at(l5, l4, l3);
    l4 = std_core_write_string_at(l5, l4, 853u);
    l6 = ((vader_array_t*) ((vader_struct_vader_midir_FnCtx_t*) l0)->f_locals)->length;
    l4 = std_core_write_int(l5, l4, l6);
    l3 = std_core_finish_buffer(l5, l4);
    t0 = vader_midir_declare_local(l0, l3, l2, vader_box_obj(0u, NULL));
    { int32_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir_function_called(void* l0, void* l1) {
    void* l2;
    vader_string_t l3;
    vader_box_t l4;
    int32_t l5;
    vader_box_t t0;
    int32_t t1;
    l2 = ((vader_struct_vader_midir_CalleeLookup_t*) l0)->f_fn_by_mangle;
    l3 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l1)->f_name;
    l4 = std_collections_MutableMap_std_core_Index_at__string__i32(l2, l3);
    if (l4.tag == 0u) {
        l2 = ((vader_struct_vader_midir_CalleeLookup_t*) l0)->f_fn_by_symbol;
        l5 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l1)->f_id;
        t0 = std_collections_MutableMap_std_core_Index_at__i32__i32(l2, l5);
        return t0;
    }
    t1 = ((int32_t) l4.payload.i);
    return vader_box_i32(288u, t1);
}

static bool vader_midir_goes_on_or_out(void* l0, void* l1, void* l2, int32_t l3) {
    int32_t l4, l11, l12;
    int64_t l5, l9, l10;
    void* l6;
    void* l7;
    void* l8;
    void* l13;
    bool l14, l15;
    vader_box_t l16;
    bool t0;
    int64_t t1;
    void* t2;
    l4 = INT32_C(-1);
    l5 = INT64_C(0);
    l6 = l1;
    l7 = ((vader_struct_std_collections_MutableMap__i32__std_collections_MutableSet_i32__t*) l6)->f_ekeys;
    l8 = ((vader_struct_std_collections_MutableMap__i32__std_collections_MutableSet_i32__t*) l6)->f_evals;
    l9 = INT64_C(0);
    l10 = ((vader_struct_std_collections_MutableMap__i32__std_collections_MutableSet_i32__t*) l6)->f_size;
    while ((l9 < l10)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l9)
        l11 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l9];
        vader_array_t* _a1_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l9)
        l6 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l9);
        l12 = l11;
        l13 = l6;
        t0 = vader_midir_holds_all(l13, l2);
        if (t0) {
            if ((l4 < INT32_C(0))) {
                l15 = true;
            } else {
                t1 = std_collections_len__i32(l13);
                l15 = (t1 < l5);
            }
            l14 = l15;
        } else {
            l14 = false;
        }
        if (l14) {
            l4 = l12;
            l5 = std_collections_len__i32(l13);
        }
        l9 = (l9 + INT64_C(1));
    }
    l16 = std_collections_MutableMap_std_core_Index_at__i32__Any(l1, l4);
    if (l16.tag == 0u) {
        return false;
    }
    l6 = l16.payload.obj;
    t0 = vader_midir_BlockId_std_core_Equals_equals(l3, l4);
    if (t0) {
        return true;
    }
    l7 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_blocks;
    vader_array_t* _a2_slotarr = ((vader_array_t*) l7);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
    t2 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
    l16 = ((vader_struct_vader_midir_BasicBlock_t*) t2)->f_terminator;
    if (l16.tag == 1137u) {
        t2 = l16.payload.obj;
        t0 = vader_midir_BlockId_std_core_Equals_equals(((vader_struct_vader_midir_TermCondBranch_t*) t2)->f_then_block, l3);
        if (t0) {
            l15 = true;
        } else {
            t2 = l16.payload.obj;
            l15 = vader_midir_BlockId_std_core_Equals_equals(((vader_struct_vader_midir_TermCondBranch_t*) t2)->f_else_block, l3);
        }
        l14 = l15;
    } else {
        l14 = false;
    }
    if (l14) {
        t0 = std_collections_MutableSet_std_core_Contains_contains__i32(l6, l3);
        return !(t0);
    }
    return false;
}

static bool vader_midir_has_receiver(void* l0, int32_t l1) {
    void* l2;
    int64_t l3, l4;
    void* t0;
    int32_t t1;
    l2 = ((vader_struct_vader_bytecode_VtableRow_t*) l0)->f_entries;
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        t1 = ((vader_struct_vader_bytecode_VtableEntry_t*) t0)->f_receiver_type_index;
        if (t1 == l1) {
            return true;
        }
        l4 = (l4 + INT64_C(1));
    }
    return false;
}

static int32_t vader_midir_held_in(void* l0, int32_t l1, vader_box_t l2, void* l3) {
    void* l4 = NULL;
    int64_t l5;
    vader_box_t l6 = vader_box_null();
    void* t0 = NULL;
    int32_t t1;
    vader_box_t* gc_roots[2] = { &l2, &l6 };
    void** gc_raw_roots[4] = { &l0, &l3, &l4, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l4 = ((vader_struct_vader_midir_FnCtx_t*) l0)->f_locals;
    l5 = ((int64_t) (int32_t) l1);
    vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
    t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
    l6 = vader_midir_stored_conversion(((vader_struct_vader_midir_CFGLocal_t*) t0)->f_type, l2);
    if (l6.tag == 0u) {
        { int32_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l6.payload.obj;
    l4 = vader_types_machine_integer_type(t0);
    t1 = vader_midir_cast_local(l0, l1, vader_ref_box(l4), 1559u, l3);
    { int32_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static int32_t vader_midir_held_use_in(void* l0, int32_t l1, vader_box_t l2, vader_box_t l3, void* l4) {
    void* l5 = NULL;
    void* l7 = NULL;
    vader_box_t l6 = vader_box_null();
    int64_t l8;
    vader_string_t l9 = 0;
    vader_string_t l10 = 0;
    int32_t t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[3] = { &l2, &l3, &l6 };
    void** gc_raw_roots[5] = { &l0, &l4, &l5, &l7, &t1 };
    vader_string_t* gc_atom_roots[2] = { &l9, &l10 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l6 = vader_midir_stored_conversion(l2, l3);
    if (l6.tag == 0u) {
        t0 = vader_midir_read_as(l0, l1, l2, l4);
        { int32_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l5 = l6.payload.obj;
    l7 = ((vader_struct_vader_midir_FnCtx_t*) l0)->f_locals;
    l8 = ((int64_t) (int32_t) l1);
    vader_array_t* _a0_slotarr = ((vader_array_t*) l7);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l8)
    t1 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l8);
    l6 = vader_types_held_integer(((vader_struct_vader_midir_CFGLocal_t*) t1)->f_type);
    if (!(l6.tag == 0u)) {
        t1 = l6.payload.obj;
        l9 = ((vader_struct_vader_integer_MachineInteger_t*) t1)->f_name;
        l10 = ((vader_struct_vader_integer_MachineInteger_t*) l5)->f_name;
        if (l9 == l10) {
            { int32_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    l5 = vader_types_machine_integer_type(l5);
    t0 = vader_midir_cast_local(l0, l1, vader_ref_box(l5), 1559u, l4);
    { int32_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_midir_holds_all(void* l0, void* l1) {
    void* l2;
    int64_t l3, l4;
    int32_t l5;
    bool t0;
    l2 = l1;
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l5 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l4];
        t0 = std_collections_MutableSet_std_core_Contains_contains__i32(l0, l5);
        if (!(t0)) {
            return false;
        }
        l4 = (l4 + INT64_C(1));
    }
    return true;
}

static void* vader_midir_import_call_target(void* l0, int32_t l1) {
    void* l2 = NULL;
    void* l5 = NULL;
    vader_box_t l3 = vader_box_null(), l4 = vader_box_null();
    bool t0;
    vader_string_t t1 = 0;
    void* t2 = NULL;
    vader_box_t* gc_roots[2] = { &l3, &l4 };
    void** gc_raw_roots[4] = { &l0, &l2, &l5, &t2 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_imports);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    l2 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l1);
    t0 = ((vader_struct_vader_bytecode_BcImport_t*) l2)->f_is_extern;
    if (t0) {
        l3 = vader_box_obj(0u, NULL);
    } else {
        t1 = ((vader_struct_vader_bytecode_BcImport_t*) l2)->f_mangled_name;
        l3 = vader_bytecode_intrinsic_op_for_mangled(t1);
    }
    if (l3.tag == 0u) {
        vader_struct_vader_bytecode_CallImport_t* _a1_obj = (vader_struct_vader_bytecode_CallImport_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_CallImport_t));
        vader_obj_header_init(_a1_obj, 675u);
        _a1_obj->f_index = l1;
        t2 = (void*) _a1_obj;
        l4 = vader_ref_box(t2);
        l5 = ((vader_struct_vader_bytecode_BcImport_t*) l2)->f_signature;
        vader_struct_vader_midir_DirectCallTarget_t* _a2_obj = (vader_struct_vader_midir_DirectCallTarget_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_DirectCallTarget_t));
        vader_obj_header_init(_a2_obj, 1086u);
        _a2_obj->f_op = l4;
        _a2_obj->f_signature = l5;
        t2 = (void*) _a2_obj;
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = l3;
    l5 = ((vader_struct_vader_bytecode_BcImport_t*) l2)->f_signature;
    vader_struct_vader_midir_DirectCallTarget_t* _a3_obj = (vader_struct_vader_midir_DirectCallTarget_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_DirectCallTarget_t));
    vader_obj_header_init(_a3_obj, 1086u);
    _a3_obj->f_op = l4;
    _a3_obj->f_signature = l5;
    t2 = (void*) _a3_obj;
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir_import_called(void* l0, void* l1) {
    void* l2;
    int32_t l3;
    vader_box_t l4;
    vader_string_t l5;
    vader_box_t t0;
    int32_t t1;
    l2 = ((vader_struct_vader_midir_CalleeLookup_t*) l0)->f_import_by_symbol;
    l3 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l1)->f_id;
    l4 = std_collections_MutableMap_std_core_Index_at__i32__i32(l2, l3);
    if (l4.tag == 0u) {
        l2 = ((vader_struct_vader_midir_CalleeLookup_t*) l0)->f_import_by_mangle;
        l5 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l1)->f_name;
        t0 = std_collections_MutableMap_std_core_Index_at__string__i32(l2, l5);
        return t0;
    }
    t1 = ((int32_t) l4.payload.i);
    return vader_box_i32(288u, t1);
}

static void vader_midir_index_by_name(void* l0, void* l1, vader_string_t l2, vader_box_t l3, int32_t l4) {
    void* l5 = NULL;
    vader_box_t l6 = vader_box_null();
    int32_t l7;
    vader_box_t* gc_roots[2] = { &l3, &l6 };
    void** gc_raw_roots[3] = { &l0, &l1, &l5 };
    vader_string_t* gc_atom_roots[1] = { &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    std_collections_MutableMap_std_core_IndexSet_set_at__string__i32(l0, l2, l4);
    l6 = l3;
    if (l6.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l5 = l6.payload.obj;
    l7 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l5)->f_id;
    std_collections_MutableMap_std_core_IndexSet_set_at__i32__i32(l1, l7, l4);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_midir_index_function(void* l0, vader_string_t l1, vader_box_t l2, int32_t l3) {
    void* l4 = NULL;
    void* l5 = NULL;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[3] = { &l0, &l4, &l5 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = ((vader_struct_vader_midir_CalleeLookup_t*) l0)->f_fn_by_mangle;
    l5 = ((vader_struct_vader_midir_CalleeLookup_t*) l0)->f_fn_by_symbol;
    vader_midir_index_by_name(l4, l5, l1, l2, l3);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_midir_index_import(void* l0, vader_string_t l1, vader_box_t l2, int32_t l3) {
    void* l4 = NULL;
    void* l5 = NULL;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[3] = { &l0, &l4, &l5 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = ((vader_struct_vader_midir_CalleeLookup_t*) l0)->f_import_by_mangle;
    l5 = ((vader_struct_vader_midir_CalleeLookup_t*) l0)->f_import_by_symbol;
    vader_midir_index_by_name(l4, l5, l1, l2, l3);
    { vader_gc_top = gc_frame.prev; return; }
}

static bool vader_midir_instruction_has_side_effect(vader_box_t l0) {
    bool t0;
    t0 = vader_midir_instruction_runs_code(l0);
    if (t0) {
        return true;
    }
    return (l0.tag == 1096u || l0.tag == 1097u || l0.tag == 1105u || l0.tag == 1111u || l0.tag == 1115u || l0.tag == 1124u);
}

static bool vader_midir_instruction_runs_code(vader_box_t l0) {
    bool l1;
    if ((l0.tag == 1100u || l0.tag == 1101u || l0.tag == 1108u || l0.tag == 1116u || l0.tag == 1125u)) {
        l1 = true;
        return l1;
    }
    if ((l0.tag == 1099u || l0.tag == 1106u || l0.tag == 1110u || l0.tag == 1112u || l0.tag == 1113u || l0.tag == 1122u)) {
        l1 = false;
    } else if ((l0.tag == 1093u || l0.tag == 1094u || l0.tag == 1096u || l0.tag == 1097u || l0.tag == 1111u)) {
        l1 = false;
    } else if ((l0.tag == 1123u || l0.tag == 1124u)) {
        l1 = false;
    } else if ((l0.tag == 1095u || l0.tag == 1098u || l0.tag == 1107u || l0.tag == 1119u)) {
        l1 = false;
    } else if ((l0.tag == 1102u || l0.tag == 1103u || l0.tag == 1104u || l0.tag == 1120u || l0.tag == 1121u)) {
        l1 = false;
    } else if ((l0.tag == 1105u || l0.tag == 1109u || l0.tag == 1117u || l0.tag == 1118u)) {
        l1 = false;
    } else {
        if (!((l0.tag == 1114u || l0.tag == 1115u))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = false;
    }
    return l1;
}

static vader_box_t vader_midir_integer_member(vader_box_t l0, void* l1) {
    vader_box_t l2, l3, l8;
    void* l4;
    void* l7;
    void* l11;
    void* l12;
    int64_t l5, l6;
    vader_string_t l9, l10;
    void* t0;
    vader_box_t t1;
    bool t2;
    l2 = vader_types_held_integer(l0);
    if (l2.tag == 0u) {
        if (l0.tag == 1270u) {
            l3 = vader_box_obj(0u, NULL);
            t0 = l0.payload.obj;
            l4 = ((vader_struct_vader_types_UnionType_t*) t0)->f_variants;
            l5 = ((vader_array_t*) l4)->length;
            l6 = INT64_C(0);
            while ((l6 < l5)) {
                vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
                VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
                t1 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l6);
                l8 = vader_types_held_integer(t1);
                if (l8.tag == 0u) {
                    l6 = (l6 + INT64_C(1));
                    continue;
                }
                l7 = l8.payload.obj;
                l9 = ((vader_struct_vader_integer_MachineInteger_t*) l7)->f_name;
                l10 = ((vader_struct_vader_integer_MachineInteger_t*) l1)->f_name;
                if (l9 == l10) {
                    return vader_ref_box(l7);
                }
                l11 = ((vader_struct_vader_integer_MachineInteger_t*) l1)->f_values;
                l12 = ((vader_struct_vader_integer_MachineInteger_t*) l7)->f_values;
                t2 = vader_integer_interval_within(l11, l12);
                if (t2) {
                    t2 = vader_midir_narrower(l7, l3);
                    if (t2) {
                        l3 = vader_ref_box(l7);
                    }
                }
                l6 = (l6 + INT64_C(1));
            }
            return l3;
        }
        return l2;
    }
    return l2;
}

static void vader_midir_intern_data_value_strings(vader_box_t l0, void* l1) {
    void* l2 = NULL;
    int64_t l3, l4;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l0, &t2 };
    void** gc_raw_roots[3] = { &l1, &l2, &t0 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l0.tag == 656u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_bytecode_BcValStr_t*) t0)->f_value;
        vader_bytecode_intern_string(t1, l1);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 657u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_bytecode_BcValStruct_t*) t0)->f_fields;
        l3 = ((vader_array_t*) l2)->length;
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            t2 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
            vader_midir_intern_data_value_strings(t2, l1);
            l4 = (l4 + INT64_C(1));
        }
    } else if (l0.tag == 654u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_bytecode_BcValArray_t*) t0)->f_elements;
        l3 = ((vader_array_t*) l2)->length;
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            t2 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
            vader_midir_intern_data_value_strings(t2, l1);
            l4 = (l4 + INT64_C(1));
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static int32_t vader_midir_intern_string_pool(void* l0, vader_string_t l1) {
    vader_box_t l2 = vader_box_null();
    int32_t l3;
    int64_t t0;
    int32_t t1;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = std_collections_MutableMap_std_core_Index_at__string__i32(((vader_struct_vader_midir_ProjectCtx_t*) l0)->f_string_index, l1);
    if (!(l2.tag == 288u)) {
        t0 = ((vader_array_t*) ((vader_struct_vader_midir_ProjectCtx_t*) l0)->f_strings)->length;
        l3 = ((int32_t) (int64_t) t0);
        vader_array_push((vader_array_t*) ((vader_struct_vader_midir_ProjectCtx_t*) l0)->f_strings, vader_box_string(285u, l1));
        std_collections_MutableMap_std_core_IndexSet_set_at__string__i32(((vader_struct_vader_midir_ProjectCtx_t*) l0)->f_string_index, l1, l3);
        { int32_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = ((int32_t) l2.payload.i);
    { int32_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static int32_t vader_midir_intersect_dom_tree(int32_t l0, int32_t l1, void* l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    int32_t l6, l7, l8, l9, l10;
    void* t0 = NULL;
    bool t1;
    void** gc_raw_roots[5] = { &l2, &l3, &l4, &l5, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(15u, 0u, 7u, 288u);
    l3 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(12u, 0u, 12u, 283u);
    l4 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(15u, 0u, 7u, 288u);
    l5 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__i32__bool_t* _a3_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
    vader_obj_header_init(_a3_obj, 381u);
    _a3_obj->f_ekeys = l3;
    _a3_obj->f_evals = l4;
    _a3_obj->f_index = l5;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a3_obj;
    vader_struct_std_collections_MutableSet__i32_t* _a4_obj = (vader_struct_std_collections_MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i32_t));
    vader_obj_header_init(_a4_obj, 517u);
    _a4_obj->f_inner = t0;
    l3 = (void*) _a4_obj;
    l6 = l0;
    for (;;) {
        t1 = vader_midir_BlockId_std_core_Equals_equals(l6, INT32_C(-1));
        if (!(t1)) {
            l7 = l6;
            t1 = std_collections_MutableSet_std_core_Contains_contains__i32(l3, l7);
            if (t1) break;
            l8 = l6;
            std_collections_add__i32(l3, l8);
            l9 = l6;
            vader_array_t* _a5_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l9)
            l10 = ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l9];
            t1 = vader_midir_BlockId_std_core_Equals_equals(l10, l6);
            if (t1) break;
            l6 = l10;
            continue;
        }
        break;
    }
    l6 = l1;
    for (;;) {
        t1 = vader_midir_BlockId_std_core_Equals_equals(l6, INT32_C(-1));
        if (!(t1)) {
            l7 = l6;
            t1 = std_collections_MutableSet_std_core_Contains_contains__i32(l3, l7);
            if (t1) {
                { int32_t __vret = l6; vader_gc_top = gc_frame.prev; return __vret; }
            }
            l8 = l6;
            vader_array_t* _a6_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l8)
            l9 = ((int32_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l8];
            t1 = vader_midir_BlockId_std_core_Equals_equals(l9, l6);
            if (t1) break;
            l6 = l9;
            continue;
        }
        break;
    }
    { vader_gc_top = gc_frame.prev; return INT32_C(-1); }
}

static vader_box_t vader_midir_intrinsic_op_for_name(vader_string_t l0) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l0 == 2345u) {
        vader_struct_vader_bytecode_SizeOfType_t* _a0_obj = (vader_struct_vader_bytecode_SizeOfType_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_SizeOfType_t));
        vader_obj_header_init(_a0_obj, 772u);
        t0 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == 1416u) {
        vader_struct_vader_bytecode_ArrayRepeat_t* _a1_obj = (vader_struct_vader_bytecode_ArrayRepeat_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_ArrayRepeat_t));
        vader_obj_header_init(_a1_obj, 634u);
        t0 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == 1411u) {
        vader_struct_vader_bytecode_ArrayPushAll_t* _a2_obj = (vader_struct_vader_bytecode_ArrayPushAll_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_ArrayPushAll_t));
        vader_obj_header_init(_a2_obj, 632u);
        t0 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == 1398u) {
        vader_struct_vader_bytecode_ArrayCopy_t* _a3_obj = (vader_struct_vader_bytecode_ArrayCopy_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_ArrayCopy_t));
        vader_obj_header_init(_a3_obj, 627u);
        t0 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == 1414u) {
        vader_struct_vader_bytecode_ArrayRemoveLast_t* _a4_obj = (vader_struct_vader_bytecode_ArrayRemoveLast_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_ArrayRemoveLast_t));
        vader_obj_header_init(_a4_obj, 633u);
        t0 = (void*) _a4_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l0 == 1396u)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    vader_struct_vader_bytecode_ArrayClear_t* _a5_obj = (vader_struct_vader_bytecode_ArrayClear_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_ArrayClear_t));
    vader_obj_header_init(_a5_obj, 626u);
    t0 = (void*) _a5_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

bool vader_midir_is_boxed_row(void* l0, int32_t l1) {
    vader_box_t t0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_types);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    t0 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l1);
    return (t0.tag == 648u || t0.tag == 653u);
}

static bool vader_midir_is_boxed_slot(vader_box_t l0) {
    uint8_t t0;
    vader_box_t* gc_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 0u, gc_roots, NULL, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_bytecode_val_type_of_type(l0);
    { bool __vret = t0 == INT32_C(17); vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_midir_is_dest_passing_shape(vader_box_t l0) {
    void* t0;
    bool t1;
    if ((l0.tag == 1000u || l0.tag == 1021u)) {
        return true;
    }
    if (!(l0.tag == 999u)) {
        return false;
    }
    t0 = l0.payload.obj;
    t1 = vader_midir_is_short_circuit_op(((vader_struct_vader_lower_LoweredBinary_t*) t0)->f_op);
    return t1;
}

static bool vader_midir_is_scalar_class(uint8_t l0) {
    bool l1;
    if (l0 == INT32_C(16)) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(17);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(14);
    }
    if (l1) {
        return !(true);
    }
    return !(l0 == INT32_C(13));
}

static bool vader_midir_is_short_circuit_op(uint8_t l0) {
    if (l0 == INT32_C(10)) {
        return true;
    }
    return l0 == INT32_C(11);
}

static bool vader_midir_is_union_slot(vader_box_t l0) {
    bool l1;
    void* t0;
    if (l0.tag == 1270u) {
        return true;
    }
    if (l0.tag == 1253u) {
        t0 = l0.payload.obj;
        l1 = vader_midir_is_union_slot(((vader_struct_vader_types_DistinctType_t*) t0)->f_backing);
    } else {
        l1 = false;
    }
    return l1;
}

static vader_box_t vader_midir_laid_out_fields(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    int32_t l3;
    vader_string_t l4 = 0;
    void* t0 = NULL;
    int64_t t1;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l1, &t2 };
    void** gc_raw_roots[3] = { &l0, &l2, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l1.tag == 1265u) {
        t0 = l1.payload.obj;
        t1 = ((vader_array_t*) ((vader_struct_vader_types_StructType_t*) t0)->f_args)->length;
        if (t1 == INT64_C(0)) {
            l2 = ((vader_struct_vader_midir_SlotTypes_t*) l0)->f_plain_fields;
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_types_StructType_t*) t0)->f_symbol)->f_id;
            t2 = std_collections_MutableMap_std_core_Index_at__i32__Any(l2, l3);
            { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    l2 = ((vader_struct_vader_midir_SlotTypes_t*) l0)->f_fields;
    l4 = vader_bytecode_type_intern_key(l1);
    t2 = std_collections_MutableMap_std_core_Index_at__string__Any(l2, l4);
    { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static int64_t vader_midir_last_empty_stack_point(void* l0, int32_t l1) {
    void* l2;
    int32_t l3;
    int64_t l4, l5, l6;
    void* t0;
    bool t1;
    l2 = ((vader_struct_vader_midir_CFGFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_fn_)->f_blocks;
    l3 = l1;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
    t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
    l4 = ((vader_array_t*) ((vader_struct_vader_midir_BasicBlock_t*) t0)->f_instructions)->length;
    while ((l4 > INT64_C(0))) {
        l2 = ((vader_struct_vader_midir_ScheduleHints_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_hints)->f_skip_set;
        l5 = vader_chk_sub(i64, l4, INT64_C(1));
        l6 = vader_midir_pos_key(l1, l5);
        t1 = std_collections_MutableSet_std_core_Contains_contains__i64(l2, l6);
        if (!(t1)) {
            break;
        }
        l4 = vader_chk_sub(i64, l4, INT64_C(1));
    }
    return l4;
}

static bool vader_midir_last_op_exits(void* l0) {
    void* l1;
    int64_t l2;
    int64_t t0;
    vader_box_t t1;
    l1 = ((vader_struct_vader_bytecode_BcFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_slot)->f_body;
    t0 = ((vader_array_t*) l1)->length;
    if (!(t0 == INT64_C(0))) {
        t0 = ((vader_array_t*) l1)->length;
        l2 = vader_chk_sub(i64, t0, INT64_C(1));
        vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
        t1 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
        return (t1.tag == 667u || t1.tag == 770u || t1.tag == 771u);
    }
    return false;
}

static vader_string_t vader_midir_layout_key(void* l0, vader_string_t l1) {
    void* l2 = NULL;
    void* l4 = NULL;
    vader_box_t l3 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    vader_string_t t1 = 0;
    vader_box_t* gc_roots[2] = { &l3, &t0 };
    void** gc_raw_roots[3] = { &l0, &l2, &l4 };
    vader_string_t* gc_atom_roots[2] = { &l1, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_comptime_MonoEntry_t*) l0)->f_symbol;
    if (l3.tag == 0u) {
        { vader_string_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = l3.payload.obj;
    l4 = ((vader_struct_vader_comptime_MonoEntry_t*) l0)->f_type_arguments;
    t0 = vader_types_mk_struct(l2, l4);
    t1 = vader_bytecode_type_intern_key(t0);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_midir_leaves_at_once(void* l0, void* l1, int32_t l2, int32_t l3) {
    bool l4;
    void* l5;
    int32_t l6;
    void* t0;
    bool t1;
    vader_box_t t2;
    l5 = ((vader_struct_vader_midir_CFGFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_fn_)->f_blocks;
    l6 = l3;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l6)
    t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l6);
    t1 = vader_midir_ends_function(((vader_struct_vader_midir_BasicBlock_t*) t0)->f_terminator);
    if (t1) {
        l5 = ((vader_struct_vader_midir_StructureShape_t*) l1)->f_copied;
        l6 = l3;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l6)
        t2 = vader_box_bool(283u, ((uint8_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l6]);
        t1 = t2.payload.b;
        l4 = !(t1);
    } else {
        l4 = false;
    }
    if (l4) {
        return true;
    }
    t1 = vader_midir_only_jumps(l1, l2, l3);
    return t1;
}

static bool vader_midir_leaves_header(void* l0, int32_t l1, int32_t l2) {
    vader_box_t l3;
    void* t0;
    bool t1;
    l3 = std_collections_MutableMap_std_core_Index_at__i32__Any(l0, l1);
    if (l3.tag == 0u) {
        return false;
    }
    t0 = l3.payload.obj;
    t1 = std_collections_MutableSet_std_core_Contains_contains__i32(t0, l2);
    return !(t1);
}

static void* vader_midir_literal_slots(void* l0, vader_box_t l1) {
    vader_box_t l2 = vader_box_null();
    void* l3 = NULL;
    void* l4 = NULL;
    int64_t l5, l6;
    void* t0 = NULL;
    vader_box_t* gc_roots[2] = { &l1, &l2 };
    void** gc_raw_roots[4] = { &l0, &l3, &l4, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = vader_types_tuple_backing(l1);
    if (!(l2.tag == 0u)) {
        t0 = l2.payload.obj;
        { void* __vret = ((vader_struct_vader_types_TupleType_t*) t0)->f_elements; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = vader_midir_laid_out_fields(l0, l1);
    if (l2.tag == 0u) {
        vader_array_t* _a0_arr = vader_array_new(244u, 0u, 13u, 1804u);
        t0 = (void*) _a0_arr;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = l2.payload.obj;
    vader_array_t* _a1_arr = vader_array_new(244u, 0u, 13u, 1804u);
    l4 = (void*) _a1_arr;
    l5 = ((vader_array_t*) l3)->length;
    vader_array_t* _a2_arr = vader_array_repeat((vader_array_t*) l4, (int64_t) l5);
    l4 = (void*) _a2_arr;
    l5 = ((vader_array_t*) l3)->length;
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        t0 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l6);
        l2 = ((vader_struct_vader_midir_CFGStructField_t*) t0)->f_type;
        vader_array_push((vader_array_t*) l4, l2);
        l6 = (l6 + INT64_C(1));
    }
    { void* __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
}

static int32_t vader_midir_loop_exit(void* l0, void* l1, int32_t l2) {
    void* l3 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    void* l13 = NULL;
    int32_t l4, l6, l11, l12, l14, l15;
    vader_box_t l5 = vader_box_null();
    int64_t l7, l8;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    bool t2;
    vader_box_t* gc_roots[2] = { &l5, &t1 };
    void** gc_raw_roots[7] = { &l0, &l1, &l3, &l9, &l10, &l13, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 7u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_midir_CFGFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_fn_)->f_blocks;
    l4 = l2;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
    t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
    l5 = ((vader_struct_vader_midir_BasicBlock_t*) t0)->f_terminator;
    if (!(l5.tag == 1137u)) {
        { vader_gc_top = gc_frame.prev; return INT32_C(-1); }
    }
    t0 = l5.payload.obj;
    l4 = ((vader_struct_vader_midir_TermCondBranch_t*) t0)->f_else_block;
    t0 = l5.payload.obj;
    l6 = ((vader_struct_vader_midir_TermCondBranch_t*) t0)->f_then_block;
    vader_array_t* _a1_arr = vader_array_new(15u, 2u, 7u, 288u);
    ((int32_t*) _a1_arr->buf->slots)[_a1_arr->offset + 1u] = (int32_t) l6;
    ((int32_t*) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = (int32_t) l4;
    l3 = (void*) _a1_arr;
    l7 = ((vader_array_t*) l3)->length;
    l8 = INT64_C(0);
    while ((l8 < l7)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        l4 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l8];
        l9 = ((vader_struct_vader_midir_StructureShape_t*) l1)->f_merge;
        l6 = l4;
        vader_array_t* _a3_slotarr = ((vader_array_t*) l9);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l6)
        t1 = vader_box_bool(283u, ((uint8_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l6]);
        t2 = t1.payload.b;
        if (t2) {
            { int32_t __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l10 = ((vader_struct_vader_midir_StructureShape_t*) l1)->f_rpo_index;
        l11 = l4;
        vader_array_t* _a4_slotarr = ((vader_array_t*) l10);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l11)
        l12 = ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l11];
        l13 = ((vader_struct_vader_midir_StructureShape_t*) l1)->f_rpo_index;
        l14 = l2;
        vader_array_t* _a5_slotarr = ((vader_array_t*) l13);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l14)
        l15 = ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l14];
        if ((l12 < l15)) {
            { int32_t __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l8 = (l8 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return INT32_C(-1); }
}

static vader_box_t vader_midir_lowered_to_bc_value(vader_box_t l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    int64_t l3, l4;
    vader_box_t l5 = vader_box_null();
    vader_string_t l6 = 0;
    uint8_t l7;
    uint64_t l8;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    int32_t t2;
    vader_box_t t3 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l0, &l5, &t3 };
    void** gc_raw_roots[3] = { &l1, &l2, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l6, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l0.tag == 1034u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_lower_LoweredStringLit_t*) t0)->f_value;
        vader_struct_vader_bytecode_BcValStr_t* _a0_obj = (vader_struct_vader_bytecode_BcValStr_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcValStr_t));
        vader_obj_header_init(_a0_obj, 656u);
        _a0_obj->f_value = t1;
        t0 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1037u) {
        vader_array_t* _a1_arr = vader_array_new(227u, 0u, 13u, 1561u);
        l1 = (void*) _a1_arr;
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_lower_LoweredStructLit_t*) t0)->f_fields;
        l3 = ((vader_array_t*) l2)->length;
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            t0 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
            l5 = vader_midir_lowered_to_bc_value(((vader_struct_vader_lower_LoweredStructLitField_t*) t0)->f_value);
            vader_array_push((vader_array_t*) l1, l5);
            l4 = (l4 + INT64_C(1));
        }
        t0 = l0.payload.obj;
        t2 = vader_midir_struct_symbol_id(((vader_struct_vader_lower_LoweredStructLit_t*) t0)->f_type);
        vader_struct_vader_bytecode_BcValStruct_t* _a3_obj = (vader_struct_vader_bytecode_BcValStruct_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcValStruct_t));
        vader_obj_header_init(_a3_obj, 657u);
        _a3_obj->f_symbol_id = t2;
        _a3_obj->f_fields = l1;
        t0 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l0.tag == 994u)) {
        l6 = vader_types_representation_name(VADER_UNION_FIELD(vader_box_t, vader_struct_vader_lower_LoweredArrayLen_t, f_type, l0.payload.obj));
        l7 = vader_bytecode_array_kind_from_name(l6);
        l8 = vader_midir_bc_value_bits(l0, l6);
        vader_struct_vader_bytecode_BcValPrim_t* _a4_obj = (vader_struct_vader_bytecode_BcValPrim_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcValPrim_t));
        vader_obj_header_init(_a4_obj, 655u);
        _a4_obj->f_kind = l7;
        _a4_obj->f_bits = l8;
        t0 = (void*) _a4_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a5_arr = vader_array_new(227u, 0u, 13u, 1561u);
    l1 = (void*) _a5_arr;
    t0 = l0.payload.obj;
    l2 = ((vader_struct_vader_lower_LoweredArrayLit_t*) t0)->f_elements;
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a6_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        t3 = vader_array_ref_load_box(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l4);
        l5 = vader_midir_lowered_to_bc_value(t3);
        vader_array_push((vader_array_t*) l1, l5);
        l4 = (l4 + INT64_C(1));
    }
    t0 = l0.payload.obj;
    t1 = vader_midir_array_element_name(((vader_struct_vader_lower_LoweredArrayLit_t*) t0)->f_type);
    vader_struct_vader_bytecode_BcValArray_t* _a7_obj = (vader_struct_vader_bytecode_BcValArray_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcValArray_t));
    vader_obj_header_init(_a7_obj, 654u);
    _a7_obj->f_element_type_name = t1;
    _a7_obj->f_elements = l1;
    t0 = (void*) _a7_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_midir_make_extern_decl(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l5 = NULL;
    void* l7 = NULL;
    void* l10 = NULL;
    int64_t l3, l4;
    vader_string_t l6 = 0;
    vader_string_t l11 = 0;
    vader_string_t l14 = 0;
    vader_string_t l15 = 0;
    vader_box_t l8 = vader_box_null();
    int32_t l9;
    bool l12, l13;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l8 };
    void** gc_raw_roots[7] = { &l0, &l1, &l2, &l5, &l7, &l10, &t0 };
    vader_string_t* gc_atom_roots[4] = { &l6, &l11, &l14, &l15 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = vader_midir_fn_metadata(l0);
    vader_array_t* _a0_arr = vader_array_new(140u, 0u, 13u, 1074u);
    l2 = (void*) _a0_arr;
    l3 = ((vader_array_t*) ((vader_struct_vader_lower_LoweredFnDecl_t*) l0)->f_params)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l2, (int64_t) l3);
    l2 = (void*) _a1_arr;
    l3 = INT64_C(0);
    l4 = ((vader_array_t*) ((vader_struct_vader_lower_LoweredFnDecl_t*) l0)->f_params)->length;
    while ((l3 < l4)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_lower_LoweredFnDecl_t*) l0)->f_params);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
        l5 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l3);
        l6 = ((vader_struct_vader_lower_LoweredParam_t*) l5)->f_name;
        l7 = ((vader_struct_vader_lower_LoweredParam_t*) l5)->f_symbol;
        l8 = ((vader_struct_vader_lower_LoweredParam_t*) l5)->f_type;
        l9 = ((int32_t) (int64_t) l3);
        vader_struct_vader_midir_CFGParam_t* _a3_obj = (vader_struct_vader_midir_CFGParam_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_CFGParam_t));
        vader_obj_header_init(_a3_obj, 1074u);
        _a3_obj->f_name = l6;
        _a3_obj->f_symbol = l7;
        _a3_obj->f_type = l8;
        _a3_obj->f_local = l9;
        l10 = (void*) _a3_obj;
        vader_array_push((vader_array_t*) l2, vader_ref_box(l10));
        l3 = (l3 + INT64_C(1));
    }
    l6 = ((vader_struct_vader_lower_LoweredFnDecl_t*) l0)->f_mangled;
    l8 = ((vader_struct_vader_lower_LoweredFnDecl_t*) l0)->f_return_type;
    l5 = ((vader_struct_vader_lower_LoweredFnDecl_t*) l0)->f_origin;
    l11 = ((vader_struct_vader_midir_FnMetadata_t*) l1)->f_extern_name;
    l12 = ((vader_struct_vader_midir_FnMetadata_t*) l1)->f_is_exported;
    l13 = ((vader_struct_vader_midir_FnMetadata_t*) l1)->f_is_extern;
    l14 = ((vader_struct_vader_midir_FnMetadata_t*) l1)->f_c_header;
    l15 = ((vader_struct_vader_midir_FnMetadata_t*) l1)->f_c_library;
    l9 = ((vader_struct_vader_midir_FnMetadata_t*) l1)->f_c_variadic_fixed;
    vader_struct_vader_midir_CFGExternDecl_t* _a4_obj = (vader_struct_vader_midir_CFGExternDecl_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_CFGExternDecl_t));
    vader_obj_header_init(_a4_obj, 1070u);
    _a4_obj->f_mangled = l6;
    _a4_obj->f_params = l2;
    _a4_obj->f_return_type = l8;
    _a4_obj->f_origin = l5;
    _a4_obj->f_extern_name = l11;
    _a4_obj->f_is_exported = l12;
    _a4_obj->f_is_extern = l13;
    _a4_obj->f_c_header = l14;
    _a4_obj->f_c_library = l15;
    _a4_obj->f_c_variadic_fixed = l9;
    t0 = (void*) _a4_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_midir_make_struct_decl(void* l0) {
    void* l1 = NULL;
    void* l3 = NULL;
    void* l5 = NULL;
    void* l8 = NULL;
    int64_t l2, l4;
    vader_string_t l6 = 0;
    vader_box_t l7 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l7 };
    void** gc_raw_roots[6] = { &l0, &l1, &l3, &l5, &l8, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l6 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(142u, 0u, 13u, 1077u);
    l1 = (void*) _a0_arr;
    l2 = ((vader_array_t*) ((vader_struct_vader_lower_LoweredStructDecl_t*) l0)->f_fields)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l1, (int64_t) l2);
    l1 = (void*) _a1_arr;
    l3 = ((vader_struct_vader_lower_LoweredStructDecl_t*) l0)->f_fields;
    l2 = ((vader_array_t*) l3)->length;
    l4 = INT64_C(0);
    while ((l4 < l2)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        l5 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
        l6 = ((vader_struct_vader_lower_LoweredStructField_t*) l5)->f_name;
        l7 = ((vader_struct_vader_lower_LoweredStructField_t*) l5)->f_type;
        vader_struct_vader_midir_CFGStructField_t* _a3_obj = (vader_struct_vader_midir_CFGStructField_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_CFGStructField_t));
        vader_obj_header_init(_a3_obj, 1077u);
        _a3_obj->f_name = l6;
        _a3_obj->f_type = l7;
        l8 = (void*) _a3_obj;
        vader_array_push((vader_array_t*) l1, vader_ref_box(l8));
        l4 = (l4 + INT64_C(1));
    }
    l6 = ((vader_struct_vader_lower_LoweredStructDecl_t*) l0)->f_mangled;
    l3 = ((vader_struct_vader_lower_LoweredStructDecl_t*) l0)->f_origin;
    vader_struct_vader_midir_CFGStructDecl_t* _a4_obj = (vader_struct_vader_midir_CFGStructDecl_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_CFGStructDecl_t));
    vader_obj_header_init(_a4_obj, 1076u);
    _a4_obj->f_mangled = l6;
    _a4_obj->f_fields = l1;
    _a4_obj->f_origin = l3;
    t0 = (void*) _a4_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void vader_midir_mark_referenced(void* l0, int32_t l1) {
    int64_t l2, l4;
    bool l3;
    l2 = ((int64_t) (int32_t) l1);
    if ((INT64_C(0) <= l2)) {
        l4 = ((vader_array_t*) l0)->length;
        l3 = (l2 < l4);
    } else {
        l3 = false;
    }
    if (l3) {
        l2 = ((int64_t) (int32_t) l1);
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
        ((uint8_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l2] = (uint8_t) true;
        return;
    }
    return;
}

static bool vader_midir_move_retags(void* l0, void* l1) {
    int64_t l2;
    void* t0 = NULL;
    bool t1;
    uint8_t t2;
    void** gc_raw_roots[3] = { &l0, &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((int64_t) (int32_t) ((vader_struct_vader_midir_InstrMove_t*) l1)->f_dst);
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
    t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
    t1 = vader_midir_is_boxed_slot(((vader_struct_vader_midir_CFGLocal_t*) t0)->f_type);
    if (t1) {
        l2 = ((int64_t) (int32_t) ((vader_struct_vader_midir_InstrMove_t*) l1)->f_src);
        vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l2)
        t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l2);
        t2 = vader_bytecode_val_type_of_type(((vader_struct_vader_midir_CFGLocal_t*) t0)->f_type);
        t1 = vader_midir_is_scalar_class(t2);
        { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return false; }
}

static vader_box_t vader_midir_multi_dsts(vader_box_t l0) {
    void* t0;
    if (!(l0.tag == 1100u)) {
        return vader_box_obj(0u, NULL);
    }
    t0 = l0.payload.obj;
    return vader_ref_box(((vader_struct_vader_midir_InstrCall_t*) t0)->f_dsts);
}

static vader_box_t vader_midir_narrowed_local_width(void* l0, vader_box_t l1, vader_box_t l2) {
    int32_t l3;
    void* l4 = NULL;
    void* l8 = NULL;
    vader_box_t l5 = vader_box_null(), l7 = vader_box_null();
    int64_t l6;
    void* t0 = NULL;
    bool t1;
    vader_box_t* gc_roots[4] = { &l1, &l2, &l5, &l7 };
    void** gc_raw_roots[4] = { &l0, &l4, &l8, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (!(l1.tag == 1020u)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l4 = ((vader_struct_vader_midir_FnCtx_t*) l0)->f_local_by_sym_id;
    t0 = l1.payload.obj;
    l3 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_lower_LoweredIdent_t*) t0)->f_symbol)->f_id;
    l5 = std_collections_MutableMap_std_core_Index_at__i32__i32(l4, l3);
    if (l5.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l3 = ((int32_t) l5.payload.i);
    l4 = ((vader_struct_vader_midir_FnCtx_t*) l0)->f_locals;
    l6 = ((int64_t) (int32_t) l3);
    vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l6)
    t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l6);
    l5 = ((vader_struct_vader_midir_CFGLocal_t*) t0)->f_type;
    t0 = l1.payload.obj;
    l7 = ((vader_struct_vader_lower_LoweredIdent_t*) t0)->f_type;
    t1 = vader_midir_narrowed_read(l5, l7);
    if (!(t1)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l7 = vader_types_held_integer(l5);
    if (l7.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l4 = l7.payload.obj;
    t0 = (void*) &vader_data_21;
    vader_array_t* _a1_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    l8 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) INT64_C(0));
    l5 = vader_midir_computation_width(l5, l2, vader_ref_box(l8));
    if (l5.tag == 0u) {
        t0 = vader_types_machine_integer_type(l4);
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l5.payload.obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_midir_narrowed_read(vader_box_t l0, vader_box_t l1) {
    void* l2;
    void* l3;
    vader_box_t l4;
    vader_string_t l5, l6;
    void* t0;
    bool t1;
    if (l0.tag == 1263u) {
        if (l1.tag == 1263u) {
            t0 = l0.payload.obj;
            l2 = ((vader_struct_vader_types_RangeType_t*) t0)->f_bounds;
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_types_RangeType_t*) t0)->f_bounds;
            t1 = vader_integer_same_interval(l2, l3);
            if (t1) {
                return false;
            }
        }
    }
    l4 = vader_types_held_integer(l0);
    if (l4.tag == 0u) {
        return false;
    }
    l2 = l4.payload.obj;
    l4 = vader_types_held_integer(l1);
    if (l4.tag == 0u) {
        return false;
    }
    l3 = l4.payload.obj;
    l5 = ((vader_struct_vader_integer_MachineInteger_t*) l2)->f_name;
    l6 = ((vader_struct_vader_integer_MachineInteger_t*) l3)->f_name;
    return l5 != l6;
}

static bool vader_midir_narrower(void* l0, vader_box_t l1) {
    int64_t l2, l3;
    void* t0;
    if (!(l1.tag == 0u)) {
        l2 = ((vader_struct_vader_integer_MachineInteger_t*) l0)->f_bits;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_integer_MachineInteger_t*) t0)->f_bits;
        return (l2 < l3);
    }
    return true;
}

static void* vader_midir_natural_loop_bodies(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    void* l15 = NULL;
    void* l16 = NULL;
    void* l21 = NULL;
    int64_t l6, l7, l9, l10, l17, l19, l22, l23;
    int32_t l8, l11, l18, l20, l24;
    bool t0;
    int64_t t1;
    void* t2 = NULL;
    void** gc_raw_roots[13] = {
        &l0, &l1, &l2, &l3, &l4, &l5, &l12, &l13, &l14, &l15, &l16, &l21, &t2,
    };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 13u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(15u, 0u, 7u, 288u);
    l3 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(21u, 0u, 0u, 296u);
    l4 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(15u, 0u, 7u, 288u);
    l5 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__i32__std_collections_MutableSet_Any__t* _a3_obj = (vader_struct_std_collections_MutableMap__i32__std_collections_MutableSet_Any__t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__std_collections_MutableSet_Any__t));
    vader_obj_header_init(_a3_obj, 387u);
    _a3_obj->f_ekeys = l3;
    _a3_obj->f_evals = l4;
    _a3_obj->f_index = l5;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    l3 = (void*) _a3_obj;
    l6 = INT64_C(0);
    l7 = ((vader_array_t*) ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_blocks)->length;
    while ((l6 < l7)) {
        l8 = ((int32_t) (int64_t) l6);
        vader_array_t* _a4_arr = vader_array_new(15u, 0u, 7u, 288u);
        l4 = (void*) _a4_arr;
        vader_array_t* _a5_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l6)
        l5 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l6);
        l9 = ((vader_array_t*) l5)->length;
        l10 = INT64_C(0);
        vader_array_t* _pc37_hdr = (vader_array_t*) l4;
        size_t _pc37_len = _pc37_hdr->length;
        size_t _pc37_cap = (_pc37_hdr->offset == 0 && !vader_array_is_borrowed(_pc37_hdr) && _pc37_hdr->length >= _pc37_hdr->buf->length) ? _pc37_hdr->capacity : (size_t) 0;
        void* _pc37_slots = _pc37_hdr->buf->slots;
        for (;;) {
            if ((l10 < l9)) {
                vader_array_t* _a6_slotarr = ((vader_array_t*) l5);
                VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
                l11 = ((int32_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l10];
                t0 = vader_midir_dominates(l2, l8, l11);
                if (t0) {
                    if (VADER_LIKELY(_pc37_len < _pc37_cap)) {
                        ((int32_t*) _pc37_slots)[_pc37_len] = (int32_t) (l11);
                        _pc37_len += 1;
                    } else {
                        _pc37_hdr->length = _pc37_len;
                        if (_pc37_hdr->buf->length < _pc37_len) {
                            _pc37_hdr->buf->length = _pc37_len;
                        }
                        vader_array_push_i32((vader_array_t*) l4, l11);
                        _pc37_hdr = (vader_array_t*) l4;
                        _pc37_len = _pc37_hdr->length;
                        _pc37_cap = (_pc37_hdr->offset == 0 && !vader_array_is_borrowed(_pc37_hdr) && _pc37_hdr->length >= _pc37_hdr->buf->length) ? _pc37_hdr->capacity : (size_t) 0;
                        _pc37_slots = _pc37_hdr->buf->slots;
                    }
                }
                l10 = (l10 + INT64_C(1));
                continue;
            }
            _pc37_hdr->length = _pc37_len;
            if (_pc37_hdr->buf->length < _pc37_len) {
                _pc37_hdr->buf->length = _pc37_len;
            }
            break;
        }
        t1 = ((vader_array_t*) l4)->length;
        if (t1 == INT64_C(0)) {
            l6 = (l6 + INT64_C(1));
            continue;
        }
        vader_array_t* _a7_arr = vader_array_new(15u, 0u, 7u, 288u);
        l12 = (void*) _a7_arr;
        vader_array_t* _a8_arr = vader_array_new(12u, 0u, 12u, 283u);
        l13 = (void*) _a8_arr;
        vader_array_t* _a9_arr = vader_array_new(15u, 0u, 7u, 288u);
        l14 = (void*) _a9_arr;
        vader_struct_std_collections_MutableMap__i32__bool_t* _a10_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
        vader_obj_header_init(_a10_obj, 381u);
        _a10_obj->f_ekeys = l12;
        _a10_obj->f_evals = l13;
        _a10_obj->f_index = l14;
        _a10_obj->f_mask = INT64_C(0);
        _a10_obj->f_size = INT64_C(0);
        _a10_obj->f_tombs = INT64_C(0);
        t2 = (void*) _a10_obj;
        vader_struct_std_collections_MutableSet__i32_t* _a11_obj = (vader_struct_std_collections_MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i32_t));
        vader_obj_header_init(_a11_obj, 517u);
        _a11_obj->f_inner = t2;
        l15 = (void*) _a11_obj;
        std_collections_add__i32(l15, l8);
        l16 = std_iter_clone__vader_midir_BlockId(l4);
        for (;;) {
            t1 = ((vader_array_t*) l16)->length;
            if ((t1 > INT64_C(0))) {
                t1 = ((vader_array_t*) l16)->length;
                l17 = vader_chk_sub(i64, t1, INT64_C(1));
                vader_array_t* _a12_slotarr = ((vader_array_t*) l16);
                VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
                l18 = ((int32_t*) _a12_slotarr->buf->slots)[_a12_slotarr->offset + (size_t) l17];
                t1 = ((vader_array_t*) l16)->length;
                l19 = vader_chk_sub(i64, t1, INT64_C(1));
                vader_array_t* _a13_arr = vader_array_slice((vader_array_t*) l16, (int64_t) INT64_C(0), (int64_t) l19);
                l16 = (void*) _a13_arr;
                t0 = std_collections_MutableSet_std_core_Contains_contains__i32(l15, l18);
                if (t0) {
                    continue;
                }
                std_collections_add__i32(l15, l18);
                l20 = l18;
                vader_array_t* _a14_slotarr = ((vader_array_t*) l1);
                VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a14_slotarr, l20)
                l21 = vader_array_ref_load_obj(_a14_slotarr->buf, _a14_slotarr->offset + (size_t) l20);
                l22 = ((vader_array_t*) l21)->length;
                l23 = INT64_C(0);
                while ((l23 < l22)) {
                    vader_array_t* _a15_slotarr = ((vader_array_t*) l21);
                    VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
                    l24 = ((int32_t*) _a15_slotarr->buf->slots)[_a15_slotarr->offset + (size_t) l23];
                    t0 = vader_midir_BlockId_std_core_Equals_equals(l24, l8);
                    if (!(t0)) {
                        vader_array_push_i32((vader_array_t*) l16, l24);
                    }
                    l23 = (l23 + INT64_C(1));
                }
                continue;
            }
            break;
        }
        std_collections_MutableMap_std_core_IndexSet_set_at__i32__Any(l3, l8, vader_ref_box(l15));
        l6 = (l6 + INT64_C(1));
    }
    { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_midir_needs_ref_cast(vader_box_t l0) {
    bool l1;
    void* t0;
    vader_string_t t1;
    if (l0.tag == 1263u) {
        return true;
    }
    if (l0.tag == 1262u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_types_PrimitiveType_t*) t0)->f_name;
        l1 = t1 != 2771u;
    } else {
        l1 = false;
    }
    return l1;
}

static int32_t vader_midir_new_block(void* l0, void* l1) {
    int32_t l2;
    void* l3 = NULL;
    void* l4 = NULL;
    int64_t t0;
    void** gc_raw_roots[4] = { &l0, &l1, &l3, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_vader_midir_FnCtx_t*) l0)->f_blocks)->length;
    l2 = ((int32_t) (int64_t) t0);
    l3 = ((vader_struct_vader_midir_FnCtx_t*) l0)->f_blocks;
    vader_array_t* _a0_arr = vader_array_new(242u, 0u, 13u, 1745u);
    l4 = (void*) _a0_arr;
    vader_struct_vader_midir_MutableBlock_t* _a1_obj = (vader_struct_vader_midir_MutableBlock_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_MutableBlock_t));
    vader_obj_header_init(_a1_obj, 1128u);
    _a1_obj->f_id = l2;
    _a1_obj->f_instructions = l4;
    _a1_obj->f_terminator = vader_box_obj(0u, NULL);
    _a1_obj->f_span = l1;
    l4 = (void*) _a1_obj;
    vader_array_push((vader_array_t*) l3, vader_ref_box(l4));
    { int32_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_midir_new_project_ctx(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    int64_t l11, l12, l13, l14, l17, l18;
    vader_box_t l15 = vader_box_null(), l16 = vader_box_null();
    int32_t l19;
    vader_box_t t0 = vader_box_null();
    vader_string_t t1 = 0;
    void* t2 = NULL;
    void* t3 = NULL;
    bool t4;
    int64_t t5;
    vader_box_t* gc_roots[3] = { &l15, &l16, &t0 };
    void** gc_raw_roots[13] = { &l0, &l1, &l2, &l3, &l4, &l5, &l6, &l7, &l8, &l9, &l10, &t2, &t3 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 13u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(15u, 0u, 7u, 288u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(21u, 0u, 0u, 296u);
    l3 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(15u, 0u, 7u, 288u);
    l4 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__i32__std_collections_MutableSet_Any__t* _a3_obj = (vader_struct_std_collections_MutableMap__i32__std_collections_MutableSet_Any__t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__std_collections_MutableSet_Any__t));
    vader_obj_header_init(_a3_obj, 387u);
    _a3_obj->f_ekeys = l2;
    _a3_obj->f_evals = l3;
    _a3_obj->f_index = l4;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    l2 = (void*) _a3_obj;
    vader_array_t* _a4_arr = vader_array_new(14u, 0u, 0u, 285u);
    l3 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_new(21u, 0u, 0u, 296u);
    l4 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(15u, 0u, 7u, 288u);
    l5 = (void*) _a6_arr;
    vader_struct_std_collections_MutableMap__string__Any___t* _a7_obj = (vader_struct_std_collections_MutableMap__string__Any___t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__Any___t));
    vader_obj_header_init(_a7_obj, 449u);
    _a7_obj->f_ekeys = l3;
    _a7_obj->f_evals = l4;
    _a7_obj->f_index = l5;
    _a7_obj->f_mask = INT64_C(0);
    _a7_obj->f_size = INT64_C(0);
    _a7_obj->f_tombs = INT64_C(0);
    l3 = (void*) _a7_obj;
    vader_array_t* _a8_arr = vader_array_new(15u, 0u, 7u, 288u);
    l4 = (void*) _a8_arr;
    vader_array_t* _a9_arr = vader_array_new(21u, 0u, 0u, 296u);
    l5 = (void*) _a9_arr;
    vader_array_t* _a10_arr = vader_array_new(15u, 0u, 7u, 288u);
    l6 = (void*) _a10_arr;
    vader_struct_std_collections_MutableMap__i32__Any___t* _a11_obj = (vader_struct_std_collections_MutableMap__i32__Any___t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__Any___t));
    vader_obj_header_init(_a11_obj, 380u);
    _a11_obj->f_ekeys = l4;
    _a11_obj->f_evals = l5;
    _a11_obj->f_index = l6;
    _a11_obj->f_mask = INT64_C(0);
    _a11_obj->f_size = INT64_C(0);
    _a11_obj->f_tombs = INT64_C(0);
    l4 = (void*) _a11_obj;
    vader_array_t* _a12_arr = vader_array_new(14u, 0u, 0u, 285u);
    l5 = (void*) _a12_arr;
    vader_array_t* _a13_arr = vader_array_new(15u, 0u, 7u, 288u);
    l6 = (void*) _a13_arr;
    vader_array_t* _a14_arr = vader_array_new(15u, 0u, 7u, 288u);
    l7 = (void*) _a14_arr;
    vader_struct_std_collections_MutableMap__string__i32_t* _a15_obj = (vader_struct_std_collections_MutableMap__string__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__i32_t));
    vader_obj_header_init(_a15_obj, 455u);
    _a15_obj->f_ekeys = l5;
    _a15_obj->f_evals = l6;
    _a15_obj->f_index = l7;
    _a15_obj->f_mask = INT64_C(0);
    _a15_obj->f_size = INT64_C(0);
    _a15_obj->f_tombs = INT64_C(0);
    l5 = (void*) _a15_obj;
    vader_array_t* _a16_arr = vader_array_new(15u, 0u, 7u, 288u);
    l6 = (void*) _a16_arr;
    vader_array_t* _a17_arr = vader_array_new(15u, 0u, 7u, 288u);
    l7 = (void*) _a17_arr;
    vader_array_t* _a18_arr = vader_array_new(15u, 0u, 7u, 288u);
    l8 = (void*) _a18_arr;
    vader_struct_std_collections_MutableMap__i32__i32_t* _a19_obj = (vader_struct_std_collections_MutableMap__i32__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__i32_t));
    vader_obj_header_init(_a19_obj, 382u);
    _a19_obj->f_ekeys = l6;
    _a19_obj->f_evals = l7;
    _a19_obj->f_index = l8;
    _a19_obj->f_mask = INT64_C(0);
    _a19_obj->f_size = INT64_C(0);
    _a19_obj->f_tombs = INT64_C(0);
    l6 = (void*) _a19_obj;
    vader_array_t* _a20_arr = vader_array_new(14u, 0u, 0u, 285u);
    l7 = (void*) _a20_arr;
    vader_array_t* _a21_arr = vader_array_new(15u, 0u, 7u, 288u);
    l8 = (void*) _a21_arr;
    vader_array_t* _a22_arr = vader_array_new(15u, 0u, 7u, 288u);
    l9 = (void*) _a22_arr;
    vader_struct_std_collections_MutableMap__string__i32_t* _a23_obj = (vader_struct_std_collections_MutableMap__string__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__i32_t));
    vader_obj_header_init(_a23_obj, 455u);
    _a23_obj->f_ekeys = l7;
    _a23_obj->f_evals = l8;
    _a23_obj->f_index = l9;
    _a23_obj->f_mask = INT64_C(0);
    _a23_obj->f_size = INT64_C(0);
    _a23_obj->f_tombs = INT64_C(0);
    l7 = (void*) _a23_obj;
    vader_array_t* _a24_arr = vader_array_new(15u, 0u, 7u, 288u);
    l8 = (void*) _a24_arr;
    vader_array_t* _a25_arr = vader_array_new(15u, 0u, 7u, 288u);
    l9 = (void*) _a25_arr;
    vader_array_t* _a26_arr = vader_array_new(15u, 0u, 7u, 288u);
    l10 = (void*) _a26_arr;
    vader_struct_std_collections_MutableMap__i32__i32_t* _a27_obj = (vader_struct_std_collections_MutableMap__i32__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__i32_t));
    vader_obj_header_init(_a27_obj, 382u);
    _a27_obj->f_ekeys = l8;
    _a27_obj->f_evals = l9;
    _a27_obj->f_index = l10;
    _a27_obj->f_mask = INT64_C(0);
    _a27_obj->f_size = INT64_C(0);
    _a27_obj->f_tombs = INT64_C(0);
    l8 = (void*) _a27_obj;
    vader_struct_vader_midir_CalleeLookup_t* _a28_obj = (vader_struct_vader_midir_CalleeLookup_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_CalleeLookup_t));
    vader_obj_header_init(_a28_obj, 1078u);
    _a28_obj->f_fn_by_mangle = l5;
    _a28_obj->f_fn_by_symbol = l6;
    _a28_obj->f_import_by_mangle = l7;
    _a28_obj->f_import_by_symbol = l8;
    l5 = (void*) _a28_obj;
    vader_array_t* _a29_arr = vader_array_new(11u, 0u, 13u, 244u);
    l6 = (void*) _a29_arr;
    vader_array_t* _a30_arr = vader_array_new(11u, 0u, 13u, 244u);
    l7 = (void*) _a30_arr;
    vader_struct_vader_midir_SlotTypes_t* _a31_obj = (vader_struct_vader_midir_SlotTypes_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_SlotTypes_t));
    vader_obj_header_init(_a31_obj, 1134u);
    _a31_obj->f_fields = l3;
    _a31_obj->f_plain_fields = l4;
    _a31_obj->f_callees = l5;
    _a31_obj->f_function_params = l6;
    _a31_obj->f_import_params = l7;
    l3 = (void*) _a31_obj;
    l4 = ((vader_struct_vader_lower_LoweredProject_t*) l0)->f_modules;
    l5 = ((vader_struct_std_collections_MutableMap__string__vader_lower_LoweredModule_t*) l4)->f_ekeys;
    l6 = ((vader_struct_std_collections_MutableMap__string__vader_lower_LoweredModule_t*) l4)->f_evals;
    l11 = INT64_C(0);
    l12 = ((vader_struct_std_collections_MutableMap__string__vader_lower_LoweredModule_t*) l4)->f_size;
    while ((l11 < l12)) {
        vader_array_t* _a32_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a32_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a32_slotarr, l11)
        t0 = vader_array_box_slots(_a32_slotarr->buf)[_a32_slotarr->offset + (size_t) l11];
        t1 = t0.payload.s;
        vader_array_t* _a33_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a33_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a33_slotarr, l11)
        t2 = vader_array_ref_load_obj(_a33_slotarr->buf, _a33_slotarr->offset + (size_t) l11);
        l4 = ((vader_struct_vader_lower_LoweredModule_t*) t2)->f_decls;
        l13 = ((vader_array_t*) l4)->length;
        l14 = INT64_C(0);
        while ((l14 < l13)) {
            vader_array_t* _a34_slotarr = ((vader_array_t*) l4);
            VADER_ARRAY_RESOLVE_BUF(_a34_slotarr)
            l15 = vader_array_ref_load_box(_a34_slotarr->buf, _a34_slotarr->offset + (size_t) l14);
            vader_midir_note_slot_types(l3, l15);
            if (l15.tag == 1017u) {
                t2 = l15.payload.obj;
                t3 = vader_midir_fn_metadata(t2);
                t4 = ((vader_struct_vader_midir_FnMetadata_t*) t3)->f_is_extern;
                if (t4) {
                    t2 = l15.payload.obj;
                    l16 = ((vader_struct_vader_comptime_MonoEntry_t*) ((vader_struct_vader_lower_LoweredFnDecl_t*) t2)->f_origin)->f_symbol;
                    if (l16.tag == 1178u) {
                        vader_array_t* _a35_arr = vader_array_new(16u, 0u, 8u, 289u);
                        l7 = (void*) _a35_arr;
                        vader_array_t* _a36_arr = vader_array_new(12u, 0u, 12u, 283u);
                        l8 = (void*) _a36_arr;
                        vader_array_t* _a37_arr = vader_array_new(15u, 0u, 7u, 288u);
                        l9 = (void*) _a37_arr;
                        vader_struct_std_collections_MutableMap__i64__bool_t* _a38_obj = (vader_struct_std_collections_MutableMap__i64__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i64__bool_t));
                        vader_obj_header_init(_a38_obj, 423u);
                        _a38_obj->f_ekeys = l7;
                        _a38_obj->f_evals = l8;
                        _a38_obj->f_index = l9;
                        _a38_obj->f_mask = INT64_C(0);
                        _a38_obj->f_size = INT64_C(0);
                        _a38_obj->f_tombs = INT64_C(0);
                        t2 = (void*) _a38_obj;
                        vader_struct_std_collections_MutableSet__i64_t* _a39_obj = (vader_struct_std_collections_MutableSet__i64_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i64_t));
                        vader_obj_header_init(_a39_obj, 518u);
                        _a39_obj->f_inner = t2;
                        l10 = (void*) _a39_obj;
                        l17 = INT64_C(0);
                        t2 = l15.payload.obj;
                        l18 = ((vader_array_t*) ((vader_struct_vader_lower_LoweredFnDecl_t*) t2)->f_params)->length;
                        while ((l17 < l18)) {
                            t2 = l15.payload.obj;
                            vader_array_t* _a40_slotarr = ((vader_array_t*) ((vader_struct_vader_lower_LoweredFnDecl_t*) t2)->f_params);
                            VADER_ARRAY_RESOLVE_BUF(_a40_slotarr)
                            VADER_ARRAY_CHECK_INDEX(_a40_slotarr, l17)
                            t2 = vader_array_ref_load_obj(_a40_slotarr->buf, _a40_slotarr->offset + (size_t) l17);
                            if (((vader_struct_vader_lower_LoweredParam_t*) t2)->f_type.tag == 1255u) {
                                std_collections_add__i64(l10, l17);
                            }
                            l17 = (l17 + INT64_C(1));
                        }
                        t5 = std_collections_len__i64(l10);
                        if ((t5 > INT64_C(0))) {
                            t2 = l16.payload.obj;
                            l19 = ((vader_struct_vader_resolver_symbol_Symbol_t*) t2)->f_id;
                            std_collections_MutableMap_std_core_IndexSet_set_at__i32__Any(l2, l19, vader_ref_box(l10));
                        }
                    }
                }
            }
            l14 = (l14 + INT64_C(1));
        }
        l11 = (l11 + INT64_C(1));
    }
    vader_array_t* _a41_arr = vader_array_new(14u, 0u, 0u, 285u);
    l4 = (void*) _a41_arr;
    vader_array_t* _a42_arr = vader_array_new(14u, 0u, 0u, 285u);
    l5 = (void*) _a42_arr;
    vader_array_t* _a43_arr = vader_array_new(15u, 0u, 7u, 288u);
    l6 = (void*) _a43_arr;
    vader_array_t* _a44_arr = vader_array_new(15u, 0u, 7u, 288u);
    l7 = (void*) _a44_arr;
    vader_struct_std_collections_MutableMap__string__i32_t* _a45_obj = (vader_struct_std_collections_MutableMap__string__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__i32_t));
    vader_obj_header_init(_a45_obj, 455u);
    _a45_obj->f_ekeys = l5;
    _a45_obj->f_evals = l6;
    _a45_obj->f_index = l7;
    _a45_obj->f_mask = INT64_C(0);
    _a45_obj->f_size = INT64_C(0);
    _a45_obj->f_tombs = INT64_C(0);
    l5 = (void*) _a45_obj;
    l6 = ((vader_struct_vader_lower_LoweredProject_t*) l0)->f_const_fn_wrap;
    l7 = ((vader_struct_vader_lower_LoweredProject_t*) l0)->f_const_inline;
    l8 = ((vader_struct_vader_lower_LoweredProject_t*) l0)->f_const_fresh_wrap;
    l9 = ((vader_struct_vader_lower_LoweredProject_t*) l0)->f_globals;
    vader_struct_vader_midir_ProjectCtx_t* _a46_obj = (vader_struct_vader_midir_ProjectCtx_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_ProjectCtx_t));
    vader_obj_header_init(_a46_obj, 1131u);
    _a46_obj->f_strings = l4;
    _a46_obj->f_string_index = l5;
    _a46_obj->f_const_fn_wrap = l6;
    _a46_obj->f_const_inline = l7;
    _a46_obj->f_const_fresh_wrap = l8;
    _a46_obj->f_extern_callbacks = l2;
    _a46_obj->f_diags = l1;
    _a46_obj->f_globals = l9;
    _a46_obj->f_slots = l3;
    t2 = (void*) _a46_obj;
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_midir_no_common_field(void* l0, vader_string_t l1, vader_box_t l2) {
    vader_string_t l3 = 0;
    vader_string_t l4 = 0;
    vader_string_t t0 = 0;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[4] = { &l1, &l3, &l4, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = vader_types_display_type(l2);
    l4 = ((vader_struct_vader_midir_CFGFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_fn_)->f_mangled;
    t0 = concat_7(2128u, l1, 1066u, l3, 987u, l4, 233u);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_midir_no_hints(void) {
    void* l0 = NULL;
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l3, &l4, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 6u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(16u, 0u, 8u, 289u);
    l0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(12u, 0u, 12u, 283u);
    l1 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(15u, 0u, 7u, 288u);
    l2 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__i64__bool_t* _a3_obj = (vader_struct_std_collections_MutableMap__i64__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i64__bool_t));
    vader_obj_header_init(_a3_obj, 423u);
    _a3_obj->f_ekeys = l0;
    _a3_obj->f_evals = l1;
    _a3_obj->f_index = l2;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a3_obj;
    vader_struct_std_collections_MutableSet__i64_t* _a4_obj = (vader_struct_std_collections_MutableSet__i64_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i64_t));
    vader_obj_header_init(_a4_obj, 518u);
    _a4_obj->f_inner = t0;
    l0 = (void*) _a4_obj;
    vader_array_t* _a5_arr = vader_array_new(16u, 0u, 8u, 289u);
    l1 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(12u, 0u, 12u, 283u);
    l2 = (void*) _a6_arr;
    vader_array_t* _a7_arr = vader_array_new(15u, 0u, 7u, 288u);
    l3 = (void*) _a7_arr;
    vader_struct_std_collections_MutableMap__i64__bool_t* _a8_obj = (vader_struct_std_collections_MutableMap__i64__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i64__bool_t));
    vader_obj_header_init(_a8_obj, 423u);
    _a8_obj->f_ekeys = l1;
    _a8_obj->f_evals = l2;
    _a8_obj->f_index = l3;
    _a8_obj->f_mask = INT64_C(0);
    _a8_obj->f_size = INT64_C(0);
    _a8_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a8_obj;
    vader_struct_std_collections_MutableSet__i64_t* _a9_obj = (vader_struct_std_collections_MutableSet__i64_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i64_t));
    vader_obj_header_init(_a9_obj, 518u);
    _a9_obj->f_inner = t0;
    l1 = (void*) _a9_obj;
    vader_array_t* _a10_arr = vader_array_new(15u, 0u, 7u, 288u);
    l2 = (void*) _a10_arr;
    vader_array_t* _a11_arr = vader_array_new(12u, 0u, 12u, 283u);
    l3 = (void*) _a11_arr;
    vader_array_t* _a12_arr = vader_array_new(15u, 0u, 7u, 288u);
    l4 = (void*) _a12_arr;
    vader_struct_std_collections_MutableMap__i32__bool_t* _a13_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
    vader_obj_header_init(_a13_obj, 381u);
    _a13_obj->f_ekeys = l2;
    _a13_obj->f_evals = l3;
    _a13_obj->f_index = l4;
    _a13_obj->f_mask = INT64_C(0);
    _a13_obj->f_size = INT64_C(0);
    _a13_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a13_obj;
    vader_struct_std_collections_MutableSet__i32_t* _a14_obj = (vader_struct_std_collections_MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i32_t));
    vader_obj_header_init(_a14_obj, 517u);
    _a14_obj->f_inner = t0;
    l2 = (void*) _a14_obj;
    vader_struct_vader_midir_ScheduleHints_t* _a15_obj = (vader_struct_vader_midir_ScheduleHints_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_ScheduleHints_t));
    vader_obj_header_init(_a15_obj, 1132u);
    _a15_obj->f_skip_set = l0;
    _a15_obj->f_skip_first_get = l1;
    _a15_obj->f_skip_terminator_get = l2;
    t0 = (void*) _a15_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_midir_note_params(void* l0, vader_string_t l1, vader_box_t l2, void* l3, bool l4) {
    void* l5 = NULL;
    int32_t l6;
    int64_t t0;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[3] = { &l0, &l3, &l5 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (!(l4)) {
        l5 = ((vader_struct_vader_midir_SlotTypes_t*) l0)->f_callees;
        t0 = ((vader_array_t*) ((vader_struct_vader_midir_SlotTypes_t*) l0)->f_function_params)->length;
        l6 = ((int32_t) (int64_t) t0);
        vader_midir_index_function(l5, l1, l2, l6);
        vader_array_push((vader_array_t*) ((vader_struct_vader_midir_SlotTypes_t*) l0)->f_function_params, vader_ref_box(l3));
        { vader_gc_top = gc_frame.prev; return; }
    }
    l5 = ((vader_struct_vader_midir_SlotTypes_t*) l0)->f_callees;
    t0 = ((vader_array_t*) ((vader_struct_vader_midir_SlotTypes_t*) l0)->f_import_params)->length;
    l6 = ((int32_t) (int64_t) t0);
    vader_midir_index_import(l5, l1, l2, l6);
    vader_array_push((vader_array_t*) ((vader_struct_vader_midir_SlotTypes_t*) l0)->f_import_params, vader_ref_box(l3));
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_midir_note_slot_types(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    int64_t l4, l5;
    vader_box_t l6 = vader_box_null();
    vader_string_t l7 = 0;
    bool l8;
    void* t0 = NULL;
    vader_box_t* gc_roots[2] = { &l1, &l6 };
    void** gc_raw_roots[4] = { &l0, &l2, &l3, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l7 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l1.tag == 1035u) {
        t0 = l1.payload.obj;
        l2 = vader_midir_make_struct_decl(t0);
        vader_midir_note_struct_fields(l0, l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 1017u) {
        vader_array_t* _a0_arr = vader_array_new(244u, 0u, 13u, 1804u);
        l2 = (void*) _a0_arr;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_lower_LoweredFnDecl_t*) t0)->f_params;
        l4 = ((vader_array_t*) l3)->length;
        l5 = INT64_C(0);
        while ((l5 < l4)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5);
            l6 = ((vader_struct_vader_lower_LoweredParam_t*) t0)->f_type;
            vader_array_push((vader_array_t*) l2, l6);
            l5 = (l5 + INT64_C(1));
        }
        t0 = l1.payload.obj;
        l7 = ((vader_struct_vader_lower_LoweredFnDecl_t*) t0)->f_mangled;
        t0 = l1.payload.obj;
        l6 = ((vader_struct_vader_comptime_MonoEntry_t*) ((vader_struct_vader_lower_LoweredFnDecl_t*) t0)->f_origin)->f_symbol;
        t0 = l1.payload.obj;
        l8 = ((vader_struct_vader_lower_LoweredFnDecl_t*) t0)->f_body.tag == 0u;
        vader_midir_note_params(l0, l7, l6, l2, l8);
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_midir_note_struct_fields(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    vader_string_t l4 = 0;
    vader_box_t l5 = vader_box_null();
    int32_t l6;
    int64_t t0;
    vader_box_t* gc_roots[1] = { &l5 };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &l3 };
    vader_string_t* gc_atom_roots[1] = { &l4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_midir_SlotTypes_t*) l0)->f_fields;
    l3 = ((vader_struct_vader_midir_CFGStructDecl_t*) l1)->f_origin;
    l4 = ((vader_struct_vader_midir_CFGStructDecl_t*) l1)->f_mangled;
    l4 = vader_midir_layout_key(l3, l4);
    l3 = ((vader_struct_vader_midir_CFGStructDecl_t*) l1)->f_fields;
    std_collections_MutableMap_std_core_IndexSet_set_at__string__Any(l2, l4, vader_ref_box(l3));
    l5 = ((vader_struct_vader_comptime_MonoEntry_t*) ((vader_struct_vader_midir_CFGStructDecl_t*) l1)->f_origin)->f_symbol;
    if (l5.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l2 = l5.payload.obj;
    t0 = ((vader_array_t*) ((vader_struct_vader_comptime_MonoEntry_t*) ((vader_struct_vader_midir_CFGStructDecl_t*) l1)->f_origin)->f_type_arguments)->length;
    if (t0 == INT64_C(0)) {
        l3 = ((vader_struct_vader_midir_SlotTypes_t*) l0)->f_plain_fields;
        l6 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l2)->f_id;
        l2 = ((vader_struct_vader_midir_CFGStructDecl_t*) l1)->f_fields;
        std_collections_MutableMap_std_core_IndexSet_set_at__i32__Any(l3, l6, vader_ref_box(l2));
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static bool vader_midir_only_jumps(void* l0, int32_t l1, int32_t l2) {
    void* l3;
    int32_t l4, l5;
    vader_box_t t0;
    bool t1;
    l3 = ((vader_struct_vader_midir_StructureShape_t*) l0)->f_merge;
    l4 = l2;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
    t0 = vader_box_bool(283u, ((uint8_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l4]);
    t1 = t0.payload.b;
    if (t1) {
        return true;
    }
    l3 = ((vader_struct_vader_midir_StructureShape_t*) l0)->f_rpo_index;
    l4 = l2;
    vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
    l4 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
    l3 = ((vader_struct_vader_midir_StructureShape_t*) l0)->f_rpo_index;
    l5 = l1;
    vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l5)
    l5 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l5];
    return (l4 <= l5);
}

static bool vader_midir_only_leaves(void* l0) {
    vader_box_t l1;
    int64_t t0;
    void* t1;
    if (((vader_struct_vader_lower_LoweredBlock_t*) l0)->f_trailing.tag == 0u) {
        t0 = ((vader_array_t*) ((vader_struct_vader_lower_LoweredBlock_t*) l0)->f_stmts)->length;
        if (t0 != INT64_C(1)) {
            return false;
        }
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_lower_LoweredBlock_t*) l0)->f_stmts);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
        l1 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT32_C(0));
        if ((l1.tag == 1002u || l1.tag == 1010u)) {
            return true;
        }
        if (!(l1.tag == 1033u)) {
            return false;
        }
        t1 = l1.payload.obj;
        l1 = ((vader_struct_vader_lower_LoweredReturn_t*) t1)->f_value;
        if (l1.tag == 0u) {
            return true;
        }
        return (l1.tag == 1001u || l1.tag == 1020u || l1.tag == 1023u || l1.tag == 1030u);
    }
    return false;
}

static int32_t vader_midir_open_blocks(void* l0, void* l1, int32_t l2) {
    int64_t l3, l4, l5;
    int32_t l6, l8;
    void* l7 = NULL;
    void* l9 = NULL;
    int64_t t0, t1;
    void* t2 = NULL;
    int32_t t3;
    void** gc_raw_roots[5] = { &l0, &l1, &l7, &l9, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = INT64_C(0);
    l4 = ((vader_array_t*) l1)->length;
    while ((l3 < l4)) {
        t0 = ((vader_array_t*) l1)->length;
        t1 = vader_chk_sub(i64, t0, INT64_C(1));
        l5 = vader_chk_sub(i64, t1, l3);
        vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
        l6 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l5];
        l7 = ((vader_struct_vader_midir_CFGFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_fn_)->f_blocks;
        l8 = l6;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l8)
        t2 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l8);
        l9 = ((vader_struct_vader_midir_BasicBlock_t*) t2)->f_span;
        vader_midir_cf_block(l0, l9, l6);
        l3 = (l3 + INT64_C(1));
    }
    t0 = ((vader_array_t*) l1)->length;
    if ((t0 > INT64_C(0))) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        t3 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) INT32_C(0)];
        { int32_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { int32_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_midir_operand_edges(vader_box_t l0) {
    void* l1 = NULL;
    void* l4 = NULL;
    int32_t l2, l3, l5, l6, l7;
    void* t0 = NULL;
    bool t1;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[3] = { &l1, &l4, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 1041u) {
        t0 = l0.payload.obj;
        if (((vader_struct_vader_lower_LoweredUnary_t*) t0)->f_op == INT32_C(1)) {
            t0 = l0.payload.obj;
            l1 = vader_midir_operand_edges(((vader_struct_vader_lower_LoweredUnary_t*) t0)->f_operand);
            l2 = ((vader_struct_vader_midir_OperandEdges_t*) l1)->f_on_false;
            l3 = ((vader_struct_vader_midir_OperandEdges_t*) l1)->f_on_true;
            vader_struct_vader_midir_OperandEdges_t* _a0_obj = (vader_struct_vader_midir_OperandEdges_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_OperandEdges_t));
            vader_obj_header_init(_a0_obj, 1129u);
            _a0_obj->f_on_true = l2;
            _a0_obj->f_on_false = l3;
            t0 = (void*) _a0_obj;
            { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    if (l0.tag == 999u) {
        t0 = l0.payload.obj;
        t1 = vader_midir_is_short_circuit_op(((vader_struct_vader_lower_LoweredBinary_t*) t0)->f_op);
        if (t1) {
            t0 = l0.payload.obj;
            l1 = vader_midir_operand_edges(((vader_struct_vader_lower_LoweredBinary_t*) t0)->f_left);
            t0 = l0.payload.obj;
            l4 = vader_midir_operand_edges(((vader_struct_vader_lower_LoweredBinary_t*) t0)->f_right);
            t0 = l0.payload.obj;
            if (!(((vader_struct_vader_lower_LoweredBinary_t*) t0)->f_op == INT32_C(10))) {
                l5 = ((vader_struct_vader_midir_OperandEdges_t*) l1)->f_on_true;
                l6 = ((vader_struct_vader_midir_OperandEdges_t*) l4)->f_on_true;
                l6 = vader_chk_add(i32, l5, l6);
                l7 = ((vader_struct_vader_midir_OperandEdges_t*) l4)->f_on_false;
                vader_struct_vader_midir_OperandEdges_t* _a1_obj = (vader_struct_vader_midir_OperandEdges_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_OperandEdges_t));
                vader_obj_header_init(_a1_obj, 1129u);
                _a1_obj->f_on_true = l6;
                _a1_obj->f_on_false = l7;
                t0 = (void*) _a1_obj;
                { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
            }
            l2 = ((vader_struct_vader_midir_OperandEdges_t*) l4)->f_on_true;
            l3 = ((vader_struct_vader_midir_OperandEdges_t*) l1)->f_on_false;
            l5 = ((vader_struct_vader_midir_OperandEdges_t*) l4)->f_on_false;
            l3 = vader_chk_add(i32, l3, l5);
            vader_struct_vader_midir_OperandEdges_t* _a2_obj = (vader_struct_vader_midir_OperandEdges_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_OperandEdges_t));
            vader_obj_header_init(_a2_obj, 1129u);
            _a2_obj->f_on_true = l2;
            _a2_obj->f_on_false = l3;
            t0 = (void*) _a2_obj;
            { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    vader_struct_vader_midir_OperandEdges_t* _a3_obj = (vader_struct_vader_midir_OperandEdges_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_OperandEdges_t));
    vader_obj_header_init(_a3_obj, 1129u);
    _a3_obj->f_on_true = INT32_C(1);
    _a3_obj->f_on_false = INT32_C(1);
    t0 = (void*) _a3_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir_operand_width(vader_box_t l0, void* l1) {
    vader_box_t t0;
    if (!(l0.tag == 0u)) {
        t0 = vader_types_held_integer(l0);
        return t0;
    }
    return vader_ref_box(l1);
}

static void* vader_midir_optimise_function(void* l0) {
    void* t0 = NULL;
    void* t1 = NULL;
    void** gc_raw_roots[3] = { &l0, &t0, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_midir_fold_moves(l0);
    t1 = vader_midir_compact_locals(t0);
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static int32_t vader_midir_outermost_loop_left(void* l0, void* l1, int32_t l2, int32_t l3) {
    int32_t l4, l10, l11, l14, l15, l16;
    void* l5;
    void* l6;
    void* l7;
    void* l12;
    int64_t l8, l9;
    bool l13;
    bool t0;
    l4 = INT32_C(-1);
    l5 = l0;
    l6 = ((vader_struct_std_collections_MutableMap__i32__std_collections_MutableSet_i32__t*) l5)->f_ekeys;
    l7 = ((vader_struct_std_collections_MutableMap__i32__std_collections_MutableSet_i32__t*) l5)->f_evals;
    l8 = INT64_C(0);
    l9 = ((vader_struct_std_collections_MutableMap__i32__std_collections_MutableSet_i32__t*) l5)->f_size;
    while ((l8 < l9)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l8)
        l10 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l8];
        vader_array_t* _a1_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l8)
        l5 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l8);
        l11 = l10;
        l12 = l5;
        t0 = std_collections_MutableSet_std_core_Contains_contains__i32(l12, l2);
        if (t0) {
            t0 = std_collections_MutableSet_std_core_Contains_contains__i32(l12, l3);
            if (!(t0)) {
                if ((l4 < INT32_C(0))) {
                    l13 = true;
                } else {
                    l14 = l11;
                    vader_array_t* _a2_slotarr = ((vader_array_t*) l1);
                    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l14)
                    l15 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l14];
                    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
                    l16 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l4];
                    l13 = (l15 < l16);
                }
                if (l13) {
                    l4 = l11;
                }
            }
        }
        l8 = (l8 + INT64_C(1));
    }
    return l4;
}

static void* vader_midir_param_c_types_of(void* l0) {
    vader_box_t l1 = vader_box_null();
    void* l2 = NULL;
    void* l4 = NULL;
    bool l3, l8;
    int64_t l5, l6;
    vader_string_t l7 = 0;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[4] = { &l0, &l2, &l4, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l7 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct_vader_comptime_MonoEntry_t*) l0)->f_decl;
    vader_array_t* _a0_arr = vader_array_new(14u, 0u, 0u, 285u);
    l2 = (void*) _a0_arr;
    if (!(l1.tag == 560u)) {
        { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = false;
    t0 = l1.payload.obj;
    l4 = ((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_params;
    l5 = ((vader_array_t*) l4)->length;
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l6);
        l7 = toolchain_ast_c_type_of(((vader_struct_toolchain_ast_FnParam_t*) t0)->f_decorators);
        vader_array_push((vader_array_t*) l2, vader_box_string(285u, l7));
        if (l3) {
            l8 = true;
        } else {
            l8 = l7 != 0u;
        }
        l3 = l8;
        l6 = (l6 + INT64_C(1));
    }
    if (l3) {
        { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_clear((vader_array_t*) l2);
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_midir_params_of(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null();
    void* l3 = NULL;
    int32_t l4;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[4] = { &l0, &l1, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = vader_midir_function_called(((vader_struct_vader_midir_SlotTypes_t*) l0)->f_callees, l1);
    if (!(l2.tag == 0u)) {
        l3 = ((vader_struct_vader_midir_SlotTypes_t*) l0)->f_function_params;
        l4 = ((int32_t) l2.payload.i);
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = vader_midir_import_called(((vader_struct_vader_midir_SlotTypes_t*) l0)->f_callees, l1);
    if (l2.tag == 0u) {
        vader_array_t* _a1_arr = vader_array_new(244u, 0u, 13u, 1804u);
        t0 = (void*) _a1_arr;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = ((int32_t) l2.payload.i);
    vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_midir_SlotTypes_t*) l0)->f_import_params);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
    t0 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_midir_pin_baked_struct_types(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    int64_t l5, l6, l8, l9;
    vader_box_t l7 = vader_box_null();
    int32_t l10, l11;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l7, &t1 };
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l3, &l4, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 6u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(15u, 0u, 7u, 288u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(12u, 0u, 12u, 283u);
    l3 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(15u, 0u, 7u, 288u);
    l4 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__i32__bool_t* _a3_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
    vader_obj_header_init(_a3_obj, 381u);
    _a3_obj->f_ekeys = l2;
    _a3_obj->f_evals = l3;
    _a3_obj->f_index = l4;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a3_obj;
    vader_struct_std_collections_MutableSet__i32_t* _a4_obj = (vader_struct_std_collections_MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i32_t));
    vader_obj_header_init(_a4_obj, 517u);
    _a4_obj->f_inner = t0;
    l2 = (void*) _a4_obj;
    l3 = l0;
    l5 = ((vader_array_t*) l3)->length;
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a5_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        l7 = vader_array_ref_load_box(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l6);
        if (l7.tag == 637u) {
            t0 = l7.payload.obj;
            l4 = ((vader_struct_vader_bytecode_BcAggregateData_t*) t0)->f_elements;
            l8 = ((vader_array_t*) l4)->length;
            l9 = INT64_C(0);
            while ((l9 < l8)) {
                vader_array_t* _a6_slotarr = ((vader_array_t*) l4);
                VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
                t1 = vader_array_ref_load_box(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l9);
                vader_midir_collect_baked_symbols(t1, l2);
                l9 = (l9 + INT64_C(1));
            }
        }
        l6 = (l6 + INT64_C(1));
    }
    l3 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) ((vader_struct_std_collections_MutableSet__i32_t*) l2)->f_inner)->f_ekeys;
    l5 = INT64_C(0);
    l6 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) ((vader_struct_std_collections_MutableSet__i32_t*) l2)->f_inner)->f_size;
    while ((l5 < l6)) {
        vader_array_t* _a7_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l5)
        l10 = ((int32_t*) _a7_slotarr->buf->slots)[_a7_slotarr->offset + (size_t) l5];
        l11 = vader_bytecode_struct_symbol_type_index(((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_types, l10);
        if ((l11 >= INT32_C(0))) {
            vader_array_push_i32((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_pinned_types, l11);
        }
        l5 = (l5 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_midir_place_slot(void* l0, vader_box_t l1, vader_box_t l2) {
    int32_t l3;
    vader_box_t l4 = vader_box_null(), l7 = vader_box_null();
    void* l5 = NULL;
    int64_t l6;
    vader_string_t l8 = 0;
    void* t0 = NULL;
    vader_box_t* gc_roots[4] = { &l1, &l2, &l4, &l7 };
    void** gc_raw_roots[3] = { &l0, &l5, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l8 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = l1;
    if (l4.tag == 0u) {
        { vader_box_t __vret = VADER_UNION_FIELD(vader_box_t, vader_struct_vader_lower_LoweredFieldAccess_t, f_type, l2.payload.obj); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = ((int32_t) l4.payload.i);
    l5 = ((vader_struct_vader_midir_FnCtx_t*) l0)->f_locals;
    l6 = ((int64_t) (int32_t) l3);
    vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l6)
    t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l6);
    l4 = ((vader_struct_vader_midir_CFGLocal_t*) t0)->f_type;
    l5 = ((vader_struct_vader_midir_ProjectCtx_t*) ((vader_struct_vader_midir_FnCtx_t*) l0)->f_project)->f_slots;
    if (l2.tag == 1015u) {
        t0 = l2.payload.obj;
        l8 = ((vader_struct_vader_lower_LoweredFieldAccess_t*) t0)->f_field;
        l7 = vader_midir_field_slot(l5, l4, l8);
    } else if (l2.tag == 1042u) {
        t0 = l2.payload.obj;
        l8 = ((vader_struct_vader_lower_LoweredUnionField_t*) t0)->f_field;
        l7 = vader_midir_field_slot(l5, l4, l8);
    } else {
        if (!(l2.tag == 1022u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l7 = vader_midir_element_slot(l4);
    }
    l4 = l7;
    if (l4.tag == 0u) {
        { vader_box_t __vret = VADER_UNION_FIELD(vader_box_t, vader_struct_vader_lower_LoweredFieldAccess_t, f_type, l2.payload.obj); vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_box_t __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
}

static int64_t vader_midir_pos_key(int32_t l0, int64_t l1) {
    int64_t t0, t1;
    t0 = vader_chk_mul(i64, ((int64_t) (int32_t) l0), INT64_C(1000000));
    t1 = vader_chk_add(i64, t0, l1);
    return t1;
}

static void* vader_midir_predecessors_of(void* l0) {
    int64_t l1, l4, l7, l8;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l10 = NULL;
    int32_t l9, l11;
    void** gc_raw_roots[6] = { &l0, &l2, &l3, &l5, &l6, &l10 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 6u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = ((vader_array_t*) ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_blocks)->length;
    l2 = (void*) &vader_fn_static___lambda_vader_midir_6;
    l2 = std_core_filled__i32__(l1, l2);
    l3 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_blocks;
    l1 = ((vader_array_t*) l3)->length;
    l4 = INT64_C(0);
    while ((l4 < l1)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l5 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        l6 = vader_midir_successors_of(l5);
        l7 = ((vader_array_t*) l6)->length;
        l8 = INT64_C(0);
        while ((l8 < l7)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l6);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            l9 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l8];
            vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l9)
            l10 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l9);
            l11 = ((vader_struct_vader_midir_BasicBlock_t*) l5)->f_id;
            vader_array_push_i32((vader_array_t*) l10, l11);
            l8 = (l8 + INT64_C(1));
        }
        l4 = (l4 + INT64_C(1));
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_midir_push_emit(void* l0, vader_box_t l1, void* l2) {
    void* l3 = NULL;
    vader_box_t l4 = vader_box_null();
    bool t0;
    vader_box_t* gc_roots[2] = { &l1, &l4 };
    void** gc_raw_roots[3] = { &l0, &l2, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_push((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_slot)->f_body, l1);
    l3 = ((vader_struct_vader_bytecode_BcFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_slot)->f_debug;
    t0 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_want_debug;
    if (t0) {
        l4 = vader_midir_debug_pos_of_span(l2);
    } else {
        l4 = vader_box_obj(0u, NULL);
    }
    vader_array_push((vader_array_t*) l3, l4);
    vader_array_push_i32((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_slot)->f_jump_table, INT32_C(-1));
    { vader_gc_top = gc_frame.prev; return; }
}

static int32_t vader_midir_push_op_with_span(void* l0, vader_box_t l1, void* l2) {
    int32_t l3;
    void* l4 = NULL;
    vader_box_t l5 = vader_box_null();
    int64_t t0;
    bool t1;
    vader_box_t* gc_roots[2] = { &l1, &l5 };
    void** gc_raw_roots[3] = { &l0, &l2, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_slot)->f_body)->length;
    l3 = ((int32_t) (int64_t) t0);
    vader_array_push((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_slot)->f_body, l1);
    l4 = ((vader_struct_vader_bytecode_BcFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_slot)->f_debug;
    t1 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_want_debug;
    if (t1) {
        l5 = vader_midir_debug_pos_of_span(l2);
    } else {
        l5 = vader_box_obj(0u, NULL);
    }
    vader_array_push((vader_array_t*) l4, l5);
    vader_array_push_i32((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_slot)->f_jump_table, INT32_C(-1));
    { int32_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir_pushed_element_type(vader_box_t l0, vader_box_t l1) {
    void* l2;
    vader_box_t l3;
    l3 = vader_types_array_backing(l0);
    if (l3.tag == 0u) {
        return l1;
    }
    l2 = l3.payload.obj;
    return ((vader_struct_vader_types_ArrayType_t*) l2)->f_element;
}

static int32_t vader_midir_read_as(void* l0, int32_t l1, vader_box_t l2, void* l3) {
    void* l4 = NULL;
    int64_t l5;
    void* t0 = NULL;
    bool t1;
    int32_t t2;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[4] = { &l0, &l3, &l4, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l4 = ((vader_struct_vader_midir_FnCtx_t*) l0)->f_locals;
    l5 = ((int64_t) (int32_t) l1);
    vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
    t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
    t1 = vader_midir_narrowed_read(((vader_struct_vader_midir_CFGLocal_t*) t0)->f_type, l2);
    if (!(t1)) {
        { int32_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = vader_midir_cast_local(l0, l1, l2, 1559u, l3);
    { int32_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_midir_read_may_carry_ref(vader_box_t l0) {
    uint8_t l1;
    vader_box_t* gc_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 0u, gc_roots, NULL, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_bytecode_val_type_of_type(l0);
    if (l1 == INT32_C(16)) {
        { vader_gc_top = gc_frame.prev; return true; }
    }
    { bool __vret = l1 == INT32_C(17); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir_read_type(vader_box_t l0, vader_box_t l1) {
    bool t0;
    t0 = vader_midir_narrowed_read(l0, l1);
    if (!(t0)) {
        return l1;
    }
    return l0;
}

static void vader_midir_record_alias(void* l0, void* l1, int32_t l2, int32_t l3) {
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_midir_append_alias(l0, l2, l3);
    vader_midir_append_alias(l1, l3, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_midir_refuse_shared_identity_test(vader_string_t l0, vader_box_t l1) {
    void* l2 = NULL;
    int64_t l3, l4;
    vader_box_t l5 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[2] = { &l1, &l5 };
    void** gc_raw_roots[2] = { &l2, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l1.tag == 1270u) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_vader_types_UnionType_t*) t0)->f_variants;
        l3 = ((vader_array_t*) l2)->length;
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            l5 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
            vader_midir_refuse_shared_instance(l0, l5);
            l4 = (l4 + INT64_C(1));
        }
    } else {
        l5 = l1;
        vader_midir_refuse_shared_instance(l0, l5);
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_midir_refuse_shared_instance(vader_string_t l0, vader_box_t l1) {
    void* l2 = NULL;
    int64_t l3, l4;
    vader_box_t l5 = vader_box_null();
    vader_string_t l6 = 0;
    vader_string_t l7 = 0;
    vader_string_t l8 = 0;
    vader_string_t l9 = 0;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_string_t t2 = 0;
    vader_box_t* gc_roots[3] = { &l1, &l5, &t1 };
    void** gc_raw_roots[2] = { &l2, &t0 };
    vader_string_t* gc_atom_roots[6] = { &l0, &l6, &l7, &l8, &l9, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 6u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (!(l1.tag == 1265u)) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    t0 = l1.payload.obj;
    l2 = ((vader_struct_vader_types_StructType_t*) t0)->f_args;
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
    for (;;) {
        if ((l4 < l3)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            l5 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
            t1 = vader_types_kept_type_argument(l5);
            if (t1.tag == 0u) {
                t0 = l1.payload.obj;
                l6 = vader_types_display_type(vader_ref_box(t0));
                l7 = concat_5(1505u, l0, 1100u, l6, 1144u);
                l8 = vader_types_display_type(l5);
                l9 = concat_3(1838u, l8, 910u);
                t2 = concat_3(l7, 1375u, l9);
                vader_host_std_abort_panic(t2);
                vader_unreachable("a no-return call returned");
            } else {
                l4 = (l4 + INT64_C(1));
                continue;
            }
        }
        break;
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_midir_remap_instr(vader_box_t l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l5 = vader_box_null(), l12 = vader_box_null(), l13 = vader_box_null();
    void* l3 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    int32_t l4, l6, l8, l17;
    uint8_t l7;
    vader_string_t l14 = 0;
    vader_string_t l15 = 0;
    bool l16;
    void* t0 = NULL;
    vader_box_t* gc_roots[5] = { &l0, &l2, &l5, &l12, &l13 };
    void** gc_raw_roots[6] = { &l1, &l3, &l9, &l10, &l11, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l14, &l15 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 5u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l0.tag == 1106u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrConst_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrConst_t*) t0)->f_dst;
        l4 = vader_midir_remap_local(l1, l4);
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_midir_InstrConst_t*) t0)->f_value;
        t0 = l0.payload.obj;
        l5 = ((vader_struct_vader_midir_InstrConst_t*) t0)->f_type;
        vader_struct_vader_midir_InstrConst_t* _a0_obj = (vader_struct_vader_midir_InstrConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrConst_t));
        vader_obj_header_init(_a0_obj, 1106u);
        _a0_obj->f_span = l3;
        _a0_obj->f_dst = l4;
        _a0_obj->f_value = l2;
        _a0_obj->f_type = l5;
        t0 = (void*) _a0_obj;
        l2 = vader_ref_box(t0);
        { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1118u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrMove_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrMove_t*) t0)->f_dst;
        l4 = vader_midir_remap_local(l1, l4);
        t0 = l0.payload.obj;
        l6 = ((vader_struct_vader_midir_InstrMove_t*) t0)->f_src;
        l6 = vader_midir_remap_local(l1, l6);
        vader_struct_vader_midir_InstrMove_t* _a1_obj = (vader_struct_vader_midir_InstrMove_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrMove_t));
        vader_obj_header_init(_a1_obj, 1118u);
        _a1_obj->f_span = l3;
        _a1_obj->f_dst = l4;
        _a1_obj->f_src = l6;
        t0 = (void*) _a1_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1099u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrBinOp_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrBinOp_t*) t0)->f_dst;
        l4 = vader_midir_remap_local(l1, l4);
        t0 = l0.payload.obj;
        l7 = ((vader_struct_vader_midir_InstrBinOp_t*) t0)->f_op;
        t0 = l0.payload.obj;
        l6 = ((vader_struct_vader_midir_InstrBinOp_t*) t0)->f_lhs;
        l6 = vader_midir_remap_local(l1, l6);
        t0 = l0.payload.obj;
        l8 = ((vader_struct_vader_midir_InstrBinOp_t*) t0)->f_rhs;
        l8 = vader_midir_remap_local(l1, l8);
        t0 = l0.payload.obj;
        l5 = ((vader_struct_vader_midir_InstrBinOp_t*) t0)->f_type;
        vader_struct_vader_midir_InstrBinOp_t* _a2_obj = (vader_struct_vader_midir_InstrBinOp_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrBinOp_t));
        vader_obj_header_init(_a2_obj, 1099u);
        _a2_obj->f_span = l3;
        _a2_obj->f_dst = l4;
        _a2_obj->f_op = l7;
        _a2_obj->f_lhs = l6;
        _a2_obj->f_rhs = l8;
        _a2_obj->f_type = l5;
        t0 = (void*) _a2_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1122u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrUnOp_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrUnOp_t*) t0)->f_dst;
        l4 = vader_midir_remap_local(l1, l4);
        t0 = l0.payload.obj;
        l7 = ((vader_struct_vader_midir_InstrUnOp_t*) t0)->f_op;
        t0 = l0.payload.obj;
        l6 = ((vader_struct_vader_midir_InstrUnOp_t*) t0)->f_operand;
        l6 = vader_midir_remap_local(l1, l6);
        t0 = l0.payload.obj;
        l5 = ((vader_struct_vader_midir_InstrUnOp_t*) t0)->f_type;
        vader_struct_vader_midir_InstrUnOp_t* _a3_obj = (vader_struct_vader_midir_InstrUnOp_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrUnOp_t));
        vader_obj_header_init(_a3_obj, 1122u);
        _a3_obj->f_span = l3;
        _a3_obj->f_dst = l4;
        _a3_obj->f_op = l7;
        _a3_obj->f_operand = l6;
        _a3_obj->f_type = l5;
        t0 = (void*) _a3_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1100u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrCall_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l9 = ((vader_struct_vader_midir_InstrCall_t*) t0)->f_dsts;
        l9 = vader_midir_remap_locals(l1, l9);
        t0 = l0.payload.obj;
        l10 = ((vader_struct_vader_midir_InstrCall_t*) t0)->f_callee;
        t0 = l0.payload.obj;
        l11 = ((vader_struct_vader_midir_InstrCall_t*) t0)->f_args;
        l11 = vader_midir_remap_locals(l1, l11);
        t0 = l0.payload.obj;
        l5 = ((vader_struct_vader_midir_InstrCall_t*) t0)->f_type;
        vader_struct_vader_midir_InstrCall_t* _a4_obj = (vader_struct_vader_midir_InstrCall_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrCall_t));
        vader_obj_header_init(_a4_obj, 1100u);
        _a4_obj->f_span = l3;
        _a4_obj->f_dsts = l9;
        _a4_obj->f_callee = l10;
        _a4_obj->f_args = l11;
        _a4_obj->f_type = l5;
        t0 = (void*) _a4_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1101u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrCallIndirect_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l5 = ((vader_struct_vader_midir_InstrCallIndirect_t*) t0)->f_dst;
        l5 = vader_midir_remap_local_opt(l1, l5);
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrCallIndirect_t*) t0)->f_callee;
        l4 = vader_midir_remap_local(l1, l4);
        t0 = l0.payload.obj;
        l9 = ((vader_struct_vader_midir_InstrCallIndirect_t*) t0)->f_args;
        l9 = vader_midir_remap_locals(l1, l9);
        t0 = l0.payload.obj;
        l12 = ((vader_struct_vader_midir_InstrCallIndirect_t*) t0)->f_fn_type;
        t0 = l0.payload.obj;
        l13 = ((vader_struct_vader_midir_InstrCallIndirect_t*) t0)->f_type;
        vader_struct_vader_midir_InstrCallIndirect_t* _a5_obj = (vader_struct_vader_midir_InstrCallIndirect_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrCallIndirect_t));
        vader_obj_header_init(_a5_obj, 1101u);
        _a5_obj->f_span = l3;
        _a5_obj->f_dst = l5;
        _a5_obj->f_callee = l4;
        _a5_obj->f_args = l9;
        _a5_obj->f_fn_type = l12;
        _a5_obj->f_type = l13;
        t0 = (void*) _a5_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1125u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrVirtualCall_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l5 = ((vader_struct_vader_midir_InstrVirtualCall_t*) t0)->f_dst;
        l5 = vader_midir_remap_local_opt(l1, l5);
        t0 = l0.payload.obj;
        l14 = ((vader_struct_vader_midir_InstrVirtualCall_t*) t0)->f_trait_name;
        t0 = l0.payload.obj;
        l15 = ((vader_struct_vader_midir_InstrVirtualCall_t*) t0)->f_method;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrVirtualCall_t*) t0)->f_receiver;
        l4 = vader_midir_remap_local(l1, l4);
        t0 = l0.payload.obj;
        l9 = ((vader_struct_vader_midir_InstrVirtualCall_t*) t0)->f_args;
        l9 = vader_midir_remap_locals(l1, l9);
        t0 = l0.payload.obj;
        l12 = ((vader_struct_vader_midir_InstrVirtualCall_t*) t0)->f_type;
        t0 = l0.payload.obj;
        l10 = ((vader_struct_vader_midir_InstrVirtualCall_t*) t0)->f_param_types;
        vader_struct_vader_midir_InstrVirtualCall_t* _a6_obj = (vader_struct_vader_midir_InstrVirtualCall_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrVirtualCall_t));
        vader_obj_header_init(_a6_obj, 1125u);
        _a6_obj->f_span = l3;
        _a6_obj->f_dst = l5;
        _a6_obj->f_trait_name = l14;
        _a6_obj->f_method = l15;
        _a6_obj->f_receiver = l4;
        _a6_obj->f_args = l9;
        _a6_obj->f_type = l12;
        _a6_obj->f_param_types = l10;
        t0 = (void*) _a6_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1113u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrFnRef_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrFnRef_t*) t0)->f_dst;
        l4 = vader_midir_remap_local(l1, l4);
        t0 = l0.payload.obj;
        l9 = ((vader_struct_vader_midir_InstrFnRef_t*) t0)->f_fn_symbol;
        t0 = l0.payload.obj;
        l5 = ((vader_struct_vader_midir_InstrFnRef_t*) t0)->f_type;
        vader_struct_vader_midir_InstrFnRef_t* _a7_obj = (vader_struct_vader_midir_InstrFnRef_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrFnRef_t));
        vader_obj_header_init(_a7_obj, 1113u);
        _a7_obj->f_span = l3;
        _a7_obj->f_dst = l4;
        _a7_obj->f_fn_symbol = l9;
        _a7_obj->f_type = l5;
        t0 = (void*) _a7_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1112u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrFnAddr_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrFnAddr_t*) t0)->f_dst;
        l4 = vader_midir_remap_local(l1, l4);
        t0 = l0.payload.obj;
        l9 = ((vader_struct_vader_midir_InstrFnAddr_t*) t0)->f_fn_symbol;
        t0 = l0.payload.obj;
        l5 = ((vader_struct_vader_midir_InstrFnAddr_t*) t0)->f_type;
        vader_struct_vader_midir_InstrFnAddr_t* _a8_obj = (vader_struct_vader_midir_InstrFnAddr_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrFnAddr_t));
        vader_obj_header_init(_a8_obj, 1112u);
        _a8_obj->f_span = l3;
        _a8_obj->f_dst = l4;
        _a8_obj->f_fn_symbol = l9;
        _a8_obj->f_type = l5;
        t0 = (void*) _a8_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1110u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrFieldGet_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrFieldGet_t*) t0)->f_dst;
        l4 = vader_midir_remap_local(l1, l4);
        t0 = l0.payload.obj;
        l6 = ((vader_struct_vader_midir_InstrFieldGet_t*) t0)->f_target;
        l6 = vader_midir_remap_local(l1, l6);
        t0 = l0.payload.obj;
        l5 = ((vader_struct_vader_midir_InstrFieldGet_t*) t0)->f_type;
        t0 = l0.payload.obj;
        l14 = ((vader_struct_vader_midir_InstrFieldGet_t*) t0)->f_field;
        vader_struct_vader_midir_InstrFieldGet_t* _a9_obj = (vader_struct_vader_midir_InstrFieldGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrFieldGet_t));
        vader_obj_header_init(_a9_obj, 1110u);
        _a9_obj->f_span = l3;
        _a9_obj->f_dst = l4;
        _a9_obj->f_target = l6;
        _a9_obj->f_type = l5;
        _a9_obj->f_field = l14;
        t0 = (void*) _a9_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1111u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrFieldSet_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrFieldSet_t*) t0)->f_target;
        l4 = vader_midir_remap_local(l1, l4);
        t0 = l0.payload.obj;
        l14 = ((vader_struct_vader_midir_InstrFieldSet_t*) t0)->f_field;
        t0 = l0.payload.obj;
        l6 = ((vader_struct_vader_midir_InstrFieldSet_t*) t0)->f_value;
        l6 = vader_midir_remap_local(l1, l6);
        t0 = l0.payload.obj;
        l16 = ((vader_struct_vader_midir_InstrFieldSet_t*) t0)->f_barrierless;
        vader_struct_vader_midir_InstrFieldSet_t* _a10_obj = (vader_struct_vader_midir_InstrFieldSet_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrFieldSet_t));
        vader_obj_header_init(_a10_obj, 1111u);
        _a10_obj->f_span = l3;
        _a10_obj->f_target = l4;
        _a10_obj->f_field = l14;
        _a10_obj->f_value = l6;
        _a10_obj->f_barrierless = l16;
        t0 = (void*) _a10_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1123u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrUnionFieldGet_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrUnionFieldGet_t*) t0)->f_dst;
        l4 = vader_midir_remap_local(l1, l4);
        t0 = l0.payload.obj;
        l6 = ((vader_struct_vader_midir_InstrUnionFieldGet_t*) t0)->f_target;
        l6 = vader_midir_remap_local(l1, l6);
        t0 = l0.payload.obj;
        l5 = ((vader_struct_vader_midir_InstrUnionFieldGet_t*) t0)->f_type;
        t0 = l0.payload.obj;
        l14 = ((vader_struct_vader_midir_InstrUnionFieldGet_t*) t0)->f_field;
        vader_struct_vader_midir_InstrUnionFieldGet_t* _a11_obj = (vader_struct_vader_midir_InstrUnionFieldGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrUnionFieldGet_t));
        vader_obj_header_init(_a11_obj, 1123u);
        _a11_obj->f_span = l3;
        _a11_obj->f_dst = l4;
        _a11_obj->f_target = l6;
        _a11_obj->f_type = l5;
        _a11_obj->f_field = l14;
        t0 = (void*) _a11_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1124u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrUnionFieldSet_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrUnionFieldSet_t*) t0)->f_target;
        l4 = vader_midir_remap_local(l1, l4);
        t0 = l0.payload.obj;
        l14 = ((vader_struct_vader_midir_InstrUnionFieldSet_t*) t0)->f_field;
        t0 = l0.payload.obj;
        l6 = ((vader_struct_vader_midir_InstrUnionFieldSet_t*) t0)->f_value;
        l6 = vader_midir_remap_local(l1, l6);
        vader_struct_vader_midir_InstrUnionFieldSet_t* _a12_obj = (vader_struct_vader_midir_InstrUnionFieldSet_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrUnionFieldSet_t));
        vader_obj_header_init(_a12_obj, 1124u);
        _a12_obj->f_span = l3;
        _a12_obj->f_target = l4;
        _a12_obj->f_field = l14;
        _a12_obj->f_value = l6;
        t0 = (void*) _a12_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1093u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrArrayGet_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrArrayGet_t*) t0)->f_dst;
        l4 = vader_midir_remap_local(l1, l4);
        t0 = l0.payload.obj;
        l6 = ((vader_struct_vader_midir_InstrArrayGet_t*) t0)->f_target;
        l6 = vader_midir_remap_local(l1, l6);
        t0 = l0.payload.obj;
        l5 = ((vader_struct_vader_midir_InstrArrayGet_t*) t0)->f_type;
        t0 = l0.payload.obj;
        l8 = ((vader_struct_vader_midir_InstrArrayGet_t*) t0)->f_index;
        l8 = vader_midir_remap_local(l1, l8);
        t0 = l0.payload.obj;
        l16 = ((vader_struct_vader_midir_InstrArrayGet_t*) t0)->f_bounds_safe;
        vader_struct_vader_midir_InstrArrayGet_t* _a13_obj = (vader_struct_vader_midir_InstrArrayGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrArrayGet_t));
        vader_obj_header_init(_a13_obj, 1093u);
        _a13_obj->f_span = l3;
        _a13_obj->f_dst = l4;
        _a13_obj->f_target = l6;
        _a13_obj->f_type = l5;
        _a13_obj->f_index = l8;
        _a13_obj->f_bounds_safe = l16;
        t0 = (void*) _a13_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1097u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrArraySet_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrArraySet_t*) t0)->f_target;
        l4 = vader_midir_remap_local(l1, l4);
        t0 = l0.payload.obj;
        l6 = ((vader_struct_vader_midir_InstrArraySet_t*) t0)->f_index;
        l6 = vader_midir_remap_local(l1, l6);
        t0 = l0.payload.obj;
        l8 = ((vader_struct_vader_midir_InstrArraySet_t*) t0)->f_value;
        l8 = vader_midir_remap_local(l1, l8);
        t0 = l0.payload.obj;
        l16 = ((vader_struct_vader_midir_InstrArraySet_t*) t0)->f_bounds_safe;
        vader_struct_vader_midir_InstrArraySet_t* _a14_obj = (vader_struct_vader_midir_InstrArraySet_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrArraySet_t));
        vader_obj_header_init(_a14_obj, 1097u);
        _a14_obj->f_span = l3;
        _a14_obj->f_target = l4;
        _a14_obj->f_index = l6;
        _a14_obj->f_value = l8;
        _a14_obj->f_bounds_safe = l16;
        t0 = (void*) _a14_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1094u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrArrayLen_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrArrayLen_t*) t0)->f_dst;
        l4 = vader_midir_remap_local(l1, l4);
        t0 = l0.payload.obj;
        l6 = ((vader_struct_vader_midir_InstrArrayLen_t*) t0)->f_target;
        l6 = vader_midir_remap_local(l1, l6);
        vader_struct_vader_midir_InstrArrayLen_t* _a15_obj = (vader_struct_vader_midir_InstrArrayLen_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrArrayLen_t));
        vader_obj_header_init(_a15_obj, 1094u);
        _a15_obj->f_span = l3;
        _a15_obj->f_dst = l4;
        _a15_obj->f_target = l6;
        t0 = (void*) _a15_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1096u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrArrayPush_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrArrayPush_t*) t0)->f_target;
        l4 = vader_midir_remap_local(l1, l4);
        t0 = l0.payload.obj;
        l6 = ((vader_struct_vader_midir_InstrArrayPush_t*) t0)->f_value;
        l6 = vader_midir_remap_local(l1, l6);
        t0 = l0.payload.obj;
        l16 = ((vader_struct_vader_midir_InstrArrayPush_t*) t0)->f_cached;
        vader_struct_vader_midir_InstrArrayPush_t* _a16_obj = (vader_struct_vader_midir_InstrArrayPush_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrArrayPush_t));
        vader_obj_header_init(_a16_obj, 1096u);
        _a16_obj->f_span = l3;
        _a16_obj->f_target = l4;
        _a16_obj->f_value = l6;
        _a16_obj->f_cached = l16;
        t0 = (void*) _a16_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1098u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrArraySlice_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrArraySlice_t*) t0)->f_dst;
        l4 = vader_midir_remap_local(l1, l4);
        t0 = l0.payload.obj;
        l5 = ((vader_struct_vader_midir_InstrArraySlice_t*) t0)->f_type;
        t0 = l0.payload.obj;
        l6 = ((vader_struct_vader_midir_InstrArraySlice_t*) t0)->f_target;
        l6 = vader_midir_remap_local(l1, l6);
        t0 = l0.payload.obj;
        l8 = ((vader_struct_vader_midir_InstrArraySlice_t*) t0)->f_lo;
        l8 = vader_midir_remap_local(l1, l8);
        t0 = l0.payload.obj;
        l17 = ((vader_struct_vader_midir_InstrArraySlice_t*) t0)->f_hi;
        l17 = vader_midir_remap_local(l1, l17);
        vader_struct_vader_midir_InstrArraySlice_t* _a17_obj = (vader_struct_vader_midir_InstrArraySlice_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrArraySlice_t));
        vader_obj_header_init(_a17_obj, 1098u);
        _a17_obj->f_span = l3;
        _a17_obj->f_dst = l4;
        _a17_obj->f_type = l5;
        _a17_obj->f_target = l6;
        _a17_obj->f_lo = l8;
        _a17_obj->f_hi = l17;
        t0 = (void*) _a17_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1119u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrStructNew_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrStructNew_t*) t0)->f_dst;
        l4 = vader_midir_remap_local(l1, l4);
        t0 = l0.payload.obj;
        l5 = ((vader_struct_vader_midir_InstrStructNew_t*) t0)->f_type;
        t0 = l0.payload.obj;
        l9 = ((vader_struct_vader_midir_InstrStructNew_t*) t0)->f_fields;
        l9 = vader_midir_remap_locals(l1, l9);
        t0 = l0.payload.obj;
        l16 = ((vader_struct_vader_midir_InstrStructNew_t*) t0)->f_stack;
        vader_struct_vader_midir_InstrStructNew_t* _a18_obj = (vader_struct_vader_midir_InstrStructNew_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrStructNew_t));
        vader_obj_header_init(_a18_obj, 1119u);
        _a18_obj->f_span = l3;
        _a18_obj->f_dst = l4;
        _a18_obj->f_type = l5;
        _a18_obj->f_fields = l9;
        _a18_obj->f_stack = l16;
        t0 = (void*) _a18_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1095u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrArrayNew_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrArrayNew_t*) t0)->f_dst;
        l4 = vader_midir_remap_local(l1, l4);
        t0 = l0.payload.obj;
        l5 = ((vader_struct_vader_midir_InstrArrayNew_t*) t0)->f_type;
        t0 = l0.payload.obj;
        l6 = ((vader_struct_vader_midir_InstrArrayNew_t*) t0)->f_length;
        t0 = l0.payload.obj;
        l9 = ((vader_struct_vader_midir_InstrArrayNew_t*) t0)->f_elements;
        l9 = vader_midir_remap_locals(l1, l9);
        t0 = l0.payload.obj;
        l16 = ((vader_struct_vader_midir_InstrArrayNew_t*) t0)->f_stack;
        vader_struct_vader_midir_InstrArrayNew_t* _a19_obj = (vader_struct_vader_midir_InstrArrayNew_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrArrayNew_t));
        vader_obj_header_init(_a19_obj, 1095u);
        _a19_obj->f_span = l3;
        _a19_obj->f_dst = l4;
        _a19_obj->f_type = l5;
        _a19_obj->f_length = l6;
        _a19_obj->f_elements = l9;
        _a19_obj->f_stack = l16;
        t0 = (void*) _a19_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1107u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrDataConst_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrDataConst_t*) t0)->f_dst;
        l4 = vader_midir_remap_local(l1, l4);
        t0 = l0.payload.obj;
        l5 = ((vader_struct_vader_midir_InstrDataConst_t*) t0)->f_type;
        t0 = l0.payload.obj;
        l6 = ((vader_struct_vader_midir_InstrDataConst_t*) t0)->f_pool_index;
        vader_struct_vader_midir_InstrDataConst_t* _a20_obj = (vader_struct_vader_midir_InstrDataConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrDataConst_t));
        vader_obj_header_init(_a20_obj, 1107u);
        _a20_obj->f_span = l3;
        _a20_obj->f_dst = l4;
        _a20_obj->f_type = l5;
        _a20_obj->f_pool_index = l6;
        t0 = (void*) _a20_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1114u) {
        l3 = l0.payload.obj;
        l9 = ((vader_struct_vader_midir_InstrGlobalGet_t*) l3)->f_span;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrGlobalGet_t*) t0)->f_dst;
        l4 = vader_midir_remap_local(l1, l4);
        l5 = ((vader_struct_vader_midir_InstrGlobalGet_t*) l3)->f_type;
        l6 = ((vader_struct_vader_midir_InstrGlobalGet_t*) l3)->f_slot;
        vader_struct_vader_midir_InstrGlobalGet_t* _a21_obj = (vader_struct_vader_midir_InstrGlobalGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrGlobalGet_t));
        vader_obj_header_init(_a21_obj, 1114u);
        _a21_obj->f_span = l9;
        _a21_obj->f_dst = l4;
        _a21_obj->f_type = l5;
        _a21_obj->f_slot = l6;
        t0 = (void*) _a21_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1115u) {
        l3 = l0.payload.obj;
        l9 = ((vader_struct_vader_midir_InstrGlobalSet_t*) l3)->f_span;
        l4 = ((vader_struct_vader_midir_InstrGlobalSet_t*) l3)->f_slot;
        t0 = l0.payload.obj;
        l6 = ((vader_struct_vader_midir_InstrGlobalSet_t*) t0)->f_value;
        l6 = vader_midir_remap_local(l1, l6);
        l5 = ((vader_struct_vader_midir_InstrGlobalSet_t*) l3)->f_type;
        vader_struct_vader_midir_InstrGlobalSet_t* _a22_obj = (vader_struct_vader_midir_InstrGlobalSet_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrGlobalSet_t));
        vader_obj_header_init(_a22_obj, 1115u);
        _a22_obj->f_span = l9;
        _a22_obj->f_slot = l4;
        _a22_obj->f_value = l6;
        _a22_obj->f_type = l5;
        t0 = (void*) _a22_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1120u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrTypeCheck_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrTypeCheck_t*) t0)->f_dst;
        l4 = vader_midir_remap_local(l1, l4);
        t0 = l0.payload.obj;
        l6 = ((vader_struct_vader_midir_InstrTypeCheck_t*) t0)->f_value;
        l6 = vader_midir_remap_local(l1, l6);
        t0 = l0.payload.obj;
        l5 = ((vader_struct_vader_midir_InstrTypeCheck_t*) t0)->f_check_type;
        vader_struct_vader_midir_InstrTypeCheck_t* _a23_obj = (vader_struct_vader_midir_InstrTypeCheck_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrTypeCheck_t));
        vader_obj_header_init(_a23_obj, 1120u);
        _a23_obj->f_span = l3;
        _a23_obj->f_dst = l4;
        _a23_obj->f_value = l6;
        _a23_obj->f_check_type = l5;
        t0 = (void*) _a23_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1121u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrTypeConst_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrTypeConst_t*) t0)->f_dst;
        l4 = vader_midir_remap_local(l1, l4);
        t0 = l0.payload.obj;
        l5 = ((vader_struct_vader_midir_InstrTypeConst_t*) t0)->f_type;
        t0 = l0.payload.obj;
        l12 = ((vader_struct_vader_midir_InstrTypeConst_t*) t0)->f_value_type;
        vader_struct_vader_midir_InstrTypeConst_t* _a24_obj = (vader_struct_vader_midir_InstrTypeConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrTypeConst_t));
        vader_obj_header_init(_a24_obj, 1121u);
        _a24_obj->f_span = l3;
        _a24_obj->f_dst = l4;
        _a24_obj->f_type = l5;
        _a24_obj->f_value_type = l12;
        t0 = (void*) _a24_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1102u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrCast_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrCast_t*) t0)->f_dst;
        l4 = vader_midir_remap_local(l1, l4);
        t0 = l0.payload.obj;
        l6 = ((vader_struct_vader_midir_InstrCast_t*) t0)->f_value;
        l6 = vader_midir_remap_local(l1, l6);
        t0 = l0.payload.obj;
        l5 = ((vader_struct_vader_midir_InstrCast_t*) t0)->f_type;
        vader_struct_vader_midir_InstrCast_t* _a25_obj = (vader_struct_vader_midir_InstrCast_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrCast_t));
        vader_obj_header_init(_a25_obj, 1102u);
        _a25_obj->f_span = l3;
        _a25_obj->f_dst = l4;
        _a25_obj->f_value = l6;
        _a25_obj->f_type = l5;
        t0 = (void*) _a25_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1104u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrCellNew_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrCellNew_t*) t0)->f_dst;
        l4 = vader_midir_remap_local(l1, l4);
        t0 = l0.payload.obj;
        l6 = ((vader_struct_vader_midir_InstrCellNew_t*) t0)->f_value;
        l6 = vader_midir_remap_local(l1, l6);
        t0 = l0.payload.obj;
        l5 = ((vader_struct_vader_midir_InstrCellNew_t*) t0)->f_value_type;
        vader_struct_vader_midir_InstrCellNew_t* _a26_obj = (vader_struct_vader_midir_InstrCellNew_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrCellNew_t));
        vader_obj_header_init(_a26_obj, 1104u);
        _a26_obj->f_span = l3;
        _a26_obj->f_dst = l4;
        _a26_obj->f_value = l6;
        _a26_obj->f_value_type = l5;
        t0 = (void*) _a26_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1103u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrCellGet_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrCellGet_t*) t0)->f_dst;
        l4 = vader_midir_remap_local(l1, l4);
        t0 = l0.payload.obj;
        l6 = ((vader_struct_vader_midir_InstrCellGet_t*) t0)->f_cell;
        l6 = vader_midir_remap_local(l1, l6);
        t0 = l0.payload.obj;
        l5 = ((vader_struct_vader_midir_InstrCellGet_t*) t0)->f_value_type;
        vader_struct_vader_midir_InstrCellGet_t* _a27_obj = (vader_struct_vader_midir_InstrCellGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrCellGet_t));
        vader_obj_header_init(_a27_obj, 1103u);
        _a27_obj->f_span = l3;
        _a27_obj->f_dst = l4;
        _a27_obj->f_cell = l6;
        _a27_obj->f_value_type = l5;
        t0 = (void*) _a27_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1105u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrCellSet_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrCellSet_t*) t0)->f_cell;
        l4 = vader_midir_remap_local(l1, l4);
        t0 = l0.payload.obj;
        l6 = ((vader_struct_vader_midir_InstrCellSet_t*) t0)->f_value;
        l6 = vader_midir_remap_local(l1, l6);
        t0 = l0.payload.obj;
        l5 = ((vader_struct_vader_midir_InstrCellSet_t*) t0)->f_value_type;
        vader_struct_vader_midir_InstrCellSet_t* _a28_obj = (vader_struct_vader_midir_InstrCellSet_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrCellSet_t));
        vader_obj_header_init(_a28_obj, 1105u);
        _a28_obj->f_span = l3;
        _a28_obj->f_cell = l4;
        _a28_obj->f_value = l6;
        _a28_obj->f_value_type = l5;
        t0 = (void*) _a28_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1117u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrMakeClosure_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrMakeClosure_t*) t0)->f_dst;
        l4 = vader_midir_remap_local(l1, l4);
        t0 = l0.payload.obj;
        l9 = ((vader_struct_vader_midir_InstrMakeClosure_t*) t0)->f_fn_symbol;
        t0 = l0.payload.obj;
        l6 = ((vader_struct_vader_midir_InstrMakeClosure_t*) t0)->f_env;
        l6 = vader_midir_remap_local(l1, l6);
        t0 = l0.payload.obj;
        l5 = ((vader_struct_vader_midir_InstrMakeClosure_t*) t0)->f_env_type;
        t0 = l0.payload.obj;
        l12 = ((vader_struct_vader_midir_InstrMakeClosure_t*) t0)->f_type;
        vader_struct_vader_midir_InstrMakeClosure_t* _a29_obj = (vader_struct_vader_midir_InstrMakeClosure_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrMakeClosure_t));
        vader_obj_header_init(_a29_obj, 1117u);
        _a29_obj->f_span = l3;
        _a29_obj->f_dst = l4;
        _a29_obj->f_fn_symbol = l9;
        _a29_obj->f_env = l6;
        _a29_obj->f_env_type = l5;
        _a29_obj->f_type = l12;
        t0 = (void*) _a29_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1116u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrIntrinsic_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l5 = ((vader_struct_vader_midir_InstrIntrinsic_t*) t0)->f_dst;
        l5 = vader_midir_remap_local_opt(l1, l5);
        t0 = l0.payload.obj;
        l14 = ((vader_struct_vader_midir_InstrIntrinsic_t*) t0)->f_name;
        t0 = l0.payload.obj;
        l9 = ((vader_struct_vader_midir_InstrIntrinsic_t*) t0)->f_args;
        l9 = vader_midir_remap_locals(l1, l9);
        t0 = l0.payload.obj;
        l10 = ((vader_struct_vader_midir_InstrIntrinsic_t*) t0)->f_param_types;
        vader_struct_vader_midir_InstrIntrinsic_t* _a30_obj = (vader_struct_vader_midir_InstrIntrinsic_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrIntrinsic_t));
        vader_obj_header_init(_a30_obj, 1116u);
        _a30_obj->f_span = l3;
        _a30_obj->f_dst = l5;
        _a30_obj->f_name = l14;
        _a30_obj->f_args = l9;
        _a30_obj->f_param_types = l10;
        t0 = (void*) _a30_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1109u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrDeferPush_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrDeferPush_t*) t0)->f_value;
        l4 = vader_midir_remap_local(l1, l4);
        vader_struct_vader_midir_InstrDeferPush_t* _a31_obj = (vader_struct_vader_midir_InstrDeferPush_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrDeferPush_t));
        vader_obj_header_init(_a31_obj, 1109u);
        _a31_obj->f_span = l3;
        _a31_obj->f_value = l4;
        t0 = (void*) _a31_obj;
        l2 = vader_ref_box(t0);
    } else {
        if (!(l0.tag == 1108u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        t0 = l0.payload.obj;
        l2 = vader_ref_box(t0);
    }
    { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static int32_t vader_midir_remap_local(void* l0, int32_t l1) {
    int64_t l2, l4;
    bool l3;
    int32_t t0;
    l2 = ((int64_t) (int32_t) l1);
    if ((INT64_C(0) <= l2)) {
        l4 = ((vader_array_t*) l0)->length;
        l3 = (l2 < l4);
    } else {
        l3 = false;
    }
    if (!(l3)) {
        return l1;
    }
    l2 = ((int64_t) (int32_t) l1);
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
    t0 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l2];
    return t0;
}

static vader_box_t vader_midir_remap_local_opt(void* l0, vader_box_t l1) {
    int32_t l2;
    int32_t t0;
    if (l1.tag == 0u) {
        return vader_box_obj(0u, NULL);
    }
    if (!(l1.tag == 288u)) {
        return vader_box_obj(0u, NULL);
    }
    l2 = ((int32_t) l1.payload.i);
    t0 = vader_midir_remap_local(l0, l2);
    return vader_box_i32(288u, t0);
}

static void* vader_midir_remap_locals(void* l0, void* l1) {
    void* l2 = NULL;
    void* l4 = NULL;
    int64_t l3, l5;
    int32_t l6, l7;
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(15u, 0u, 7u, 288u);
    l2 = (void*) _a0_arr;
    l3 = ((vader_array_t*) l1)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l2, (int64_t) l3);
    l2 = (void*) _a1_arr;
    l4 = l1;
    l3 = ((vader_array_t*) l4)->length;
    l5 = INT64_C(0);
    vader_array_t* _pc15_hdr = (vader_array_t*) l2;
    size_t _pc15_len = _pc15_hdr->length;
    size_t _pc15_cap = (_pc15_hdr->offset == 0 && !vader_array_is_borrowed(_pc15_hdr) && _pc15_hdr->length >= _pc15_hdr->buf->length) ? _pc15_hdr->capacity : (size_t) 0;
    void* _pc15_slots = _pc15_hdr->buf->slots;
    for (;;) {
        if ((l5 < l3)) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) l4);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            l6 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l5];
            l7 = vader_midir_remap_local(l0, l6);
            if (VADER_LIKELY(_pc15_len < _pc15_cap)) {
                ((int32_t*) _pc15_slots)[_pc15_len] = (int32_t) (l7);
                _pc15_len += 1;
            } else {
                _pc15_hdr->length = _pc15_len;
                if (_pc15_hdr->buf->length < _pc15_len) {
                    _pc15_hdr->buf->length = _pc15_len;
                }
                vader_array_push_i32((vader_array_t*) l2, l7);
                _pc15_hdr = (vader_array_t*) l2;
                _pc15_len = _pc15_hdr->length;
                _pc15_cap = (_pc15_hdr->offset == 0 && !vader_array_is_borrowed(_pc15_hdr) && _pc15_hdr->length >= _pc15_hdr->buf->length) ? _pc15_hdr->capacity : (size_t) 0;
                _pc15_slots = _pc15_hdr->buf->slots;
            }
            l5 = (l5 + INT64_C(1));
            continue;
        }
        _pc15_hdr->length = _pc15_len;
        if (_pc15_hdr->buf->length < _pc15_len) {
            _pc15_hdr->buf->length = _pc15_len;
        }
        break;
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir_remap_terminator(vader_box_t l0, void* l1) {
    void* l2 = NULL;
    void* l6 = NULL;
    int32_t l3, l4, l5;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l0, &t1 };
    void** gc_raw_roots[4] = { &l1, &l2, &l6, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 1136u) {
        t0 = l0.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1139u) {
        t0 = l0.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1137u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_midir_TermCondBranch_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_TermCondBranch_t*) t0)->f_cond;
        l3 = vader_midir_remap_local(l1, l3);
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir_TermCondBranch_t*) t0)->f_then_block;
        t0 = l0.payload.obj;
        l5 = ((vader_struct_vader_midir_TermCondBranch_t*) t0)->f_else_block;
        vader_struct_vader_midir_TermCondBranch_t* _a0_obj = (vader_struct_vader_midir_TermCondBranch_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_TermCondBranch_t));
        vader_obj_header_init(_a0_obj, 1137u);
        _a0_obj->f_span = l2;
        _a0_obj->f_cond = l3;
        _a0_obj->f_then_block = l4;
        _a0_obj->f_else_block = l5;
        t0 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l0.tag == 1138u)) {
        t1 = l0;
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l0.payload.obj;
    l2 = ((vader_struct_vader_midir_TermReturn_t*) t0)->f_span;
    t0 = l0.payload.obj;
    l6 = ((vader_struct_vader_midir_TermReturn_t*) t0)->f_values;
    l6 = vader_midir_remap_locals(l1, l6);
    vader_struct_vader_midir_TermReturn_t* _a1_obj = (vader_struct_vader_midir_TermReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_TermReturn_t));
    vader_obj_header_init(_a1_obj, 1138u);
    _a1_obj->f_span = l2;
    _a1_obj->f_values = l6;
    t0 = (void*) _a1_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_midir_reserve_cfg_extern(void* l0, void* l1) {
    void* l2 = NULL;
    void* l4 = NULL;
    void* l12 = NULL;
    vader_box_t l3 = vader_box_null();
    int32_t l5, l11;
    vader_string_t l6 = 0;
    vader_string_t l7 = 0;
    vader_string_t l9 = 0;
    vader_string_t l10 = 0;
    vader_string_t l13 = 0;
    bool l8;
    int64_t t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &l3 };
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l4, &l12, &t1 };
    vader_string_t* gc_atom_roots[5] = { &l6, &l7, &l9, &l10, &l13 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 5u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_midir_CFGExternDecl_t*) l0)->f_params;
    l3 = ((vader_struct_vader_midir_CFGExternDecl_t*) l0)->f_return_type;
    vader_array_t* _a0_arr = vader_array_new(244u, 0u, 13u, 1804u);
    l4 = (void*) _a0_arr;
    l2 = vader_midir_build_cfg_signature(l2, l3, l4, l1);
    l4 = ((vader_struct_vader_midir_CFGExternDecl_t*) l0)->f_origin;
    l2 = vader_midir_with_param_decorators(l2, l4);
    t0 = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_imports)->length;
    l5 = ((int32_t) (int64_t) t0);
    l4 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_imports;
    l6 = ((vader_struct_vader_midir_CFGExternDecl_t*) l0)->f_extern_name;
    l7 = ((vader_struct_vader_midir_CFGExternDecl_t*) l0)->f_mangled;
    l8 = ((vader_struct_vader_midir_CFGExternDecl_t*) l0)->f_is_extern;
    l9 = ((vader_struct_vader_midir_CFGExternDecl_t*) l0)->f_c_header;
    l10 = ((vader_struct_vader_midir_CFGExternDecl_t*) l0)->f_c_library;
    l11 = ((vader_struct_vader_midir_CFGExternDecl_t*) l0)->f_c_variadic_fixed;
    l12 = vader_midir_param_c_types_of(((vader_struct_vader_midir_CFGExternDecl_t*) l0)->f_origin);
    l13 = vader_midir_result_c_type_of(((vader_struct_vader_midir_CFGExternDecl_t*) l0)->f_origin);
    vader_struct_vader_bytecode_BcImport_t* _a1_obj = (vader_struct_vader_bytecode_BcImport_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcImport_t));
    vader_obj_header_init(_a1_obj, 644u);
    _a1_obj->f_extern_name = l6;
    _a1_obj->f_mangled_name = l7;
    _a1_obj->f_signature = l2;
    _a1_obj->f_is_extern = l8;
    _a1_obj->f_c_header = l9;
    _a1_obj->f_c_library = l10;
    _a1_obj->f_c_variadic_fixed = l11;
    _a1_obj->f_param_c_types = l12;
    _a1_obj->f_result_c_type = l13;
    l2 = (void*) _a1_obj;
    vader_array_push((vader_array_t*) l4, vader_ref_box(l2));
    l3 = ((vader_struct_vader_comptime_MonoEntry_t*) ((vader_struct_vader_midir_CFGExternDecl_t*) l0)->f_origin)->f_symbol;
    if (l3.tag == 1178u) {
        l2 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_import_index_by_symbol_id;
        t1 = l3.payload.obj;
        l11 = ((vader_struct_vader_resolver_symbol_Symbol_t*) t1)->f_id;
        std_collections_MutableMap_std_core_IndexSet_set_at__i32__i32(l2, l11, l5);
    }
    l2 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_import_index_by_mangle;
    l6 = ((vader_struct_vader_midir_CFGExternDecl_t*) l0)->f_mangled;
    std_collections_MutableMap_std_core_IndexSet_set_at__string__i32(l2, l6, l5);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_midir_reserve_cfg_function(void* l0, void* l1) {
    void* l2 = NULL;
    void* l4 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l12 = NULL;
    vader_box_t l3 = vader_box_null();
    int32_t l5, l13;
    vader_string_t l10 = 0;
    bool l11;
    int64_t t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &l3 };
    void** gc_raw_roots[10] = { &l0, &l1, &l2, &l4, &l6, &l7, &l8, &l9, &l12, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l10 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 10u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_params;
    l3 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_return_type;
    l4 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_scalarised_results;
    l2 = vader_midir_build_cfg_signature(l2, l3, l4, l1);
    t0 = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_functions)->length;
    l5 = ((int32_t) (int64_t) t0);
    vader_array_t* _a0_arr = vader_array_new(224u, 0u, 13u, 1529u);
    l4 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(228u, 0u, 13u, 1585u);
    l6 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(15u, 0u, 7u, 288u);
    l7 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(54u, 0u, 13u, 645u);
    l8 = (void*) _a3_arr;
    l9 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_functions;
    l10 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_mangled;
    l11 = ((vader_struct_vader_comptime_MonoEntry_t*) ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_origin)->f_is_main;
    vader_array_t* _a4_arr = vader_array_new(15u, 0u, 7u, 288u);
    l12 = (void*) _a4_arr;
    vader_struct_vader_bytecode_BcFunction_t* _a5_obj = (vader_struct_vader_bytecode_BcFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcFunction_t));
    vader_obj_header_init(_a5_obj, 642u);
    _a5_obj->f_name = l10;
    _a5_obj->f_is_main = l11;
    _a5_obj->f_signature = l2;
    _a5_obj->f_locals = l8;
    _a5_obj->f_body = l4;
    _a5_obj->f_debug = l6;
    _a5_obj->f_jump_table = l7;
    _a5_obj->f_source_pc = l12;
    l2 = (void*) _a5_obj;
    vader_array_push((vader_array_t*) l9, vader_ref_box(l2));
    l3 = ((vader_struct_vader_comptime_MonoEntry_t*) ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_origin)->f_symbol;
    if (l3.tag == 1178u) {
        l2 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_function_index_by_symbol_id;
        t1 = l3.payload.obj;
        l13 = ((vader_struct_vader_resolver_symbol_Symbol_t*) t1)->f_id;
        std_collections_MutableMap_std_core_IndexSet_set_at__i32__i32(l2, l13, l5);
    }
    l2 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_function_index_by_mangle;
    l10 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_mangled;
    std_collections_MutableMap_std_core_IndexSet_set_at__string__i32(l2, l10, l5);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_midir_reserve_cfg_struct(void* l0, void* l1) {
    int32_t l2, l8, l9;
    vader_box_t l3 = vader_box_null(), l7 = vader_box_null();
    void* l4 = NULL;
    void* l5 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    vader_string_t l6 = 0;
    vader_string_t l15 = 0;
    uint64_t l10;
    int64_t l11, l12;
    void* t0 = NULL;
    int64_t t1;
    vader_box_t t2 = vader_box_null();
    vader_string_t t3 = 0;
    vader_box_t* gc_roots[3] = { &l3, &l7, &t2 };
    void** gc_raw_roots[7] = { &l0, &l1, &l4, &l5, &l13, &l14, &t0 };
    vader_string_t* gc_atom_roots[3] = { &l6, &l15, &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = INT32_C(-1);
    l3 = ((vader_struct_vader_comptime_MonoEntry_t*) ((vader_struct_vader_midir_CFGStructDecl_t*) l0)->f_origin)->f_symbol;
    if (l3.tag == 1178u) {
        t0 = l3.payload.obj;
        l2 = ((vader_struct_vader_resolver_symbol_Symbol_t*) t0)->f_id;
    }
    if (l3.tag == 1178u) {
        l4 = l3.payload.obj;
        l5 = ((vader_struct_vader_comptime_MonoEntry_t*) ((vader_struct_vader_midir_CFGStructDecl_t*) l0)->f_origin)->f_type_arguments;
        l3 = vader_types_mk_struct(l4, l5);
        l4 = ((vader_struct_vader_midir_CFGStructDecl_t*) l0)->f_origin;
        l6 = ((vader_struct_vader_midir_CFGStructDecl_t*) l0)->f_mangled;
        l6 = vader_midir_layout_key(l4, l6);
        l7 = std_collections_MutableMap_std_core_Index_at__string__i32(((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_type_key, l6);
        t1 = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_types)->length;
        l8 = ((int32_t) (int64_t) t1);
        if (l7.tag == 288u) {
            l4 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_types;
            l9 = ((int32_t) l7.payload.i);
            vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l9)
            t2 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l9);
            if (t2.tag == 652u) {
                { vader_gc_top = gc_frame.prev; return; }
            }
            l8 = ((int32_t) l7.payload.i);
        } else {
            std_collections_MutableMap_std_core_IndexSet_set_at__string__i32(((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_type_key, l6, l8);
            l10 = vader_bytecode_type_intern_hash(l3);
            t2 = std_collections_MutableMap_std_core_Index_at__u64__i32(((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_type_hash, l10);
            if (t2.tag == 0u) {
                std_collections_MutableMap_std_core_IndexSet_set_at__u64__i32(((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_type_hash, l10, l8);
            }
            vader_bytecode_record_slot_type(l1, l8, l3);
            l4 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_types;
            t3 = ((vader_struct_vader_midir_CFGStructDecl_t*) l0)->f_mangled;
            vader_struct_vader_bytecode_BcRef_t* _a1_obj = (vader_struct_vader_bytecode_BcRef_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcRef_t));
            vader_obj_header_init(_a1_obj, 648u);
            _a1_obj->f_trait_name = t3;
            l5 = (void*) _a1_obj;
            vader_array_push((vader_array_t*) l4, vader_ref_box(l5));
        }
        vader_array_t* _a2_arr = vader_array_new(50u, 0u, 13u, 640u);
        l4 = (void*) _a2_arr;
        l11 = ((vader_array_t*) ((vader_struct_vader_midir_CFGStructDecl_t*) l0)->f_fields)->length;
        vader_array_t* _a3_arr = vader_array_repeat((vader_array_t*) l4, (int64_t) l11);
        l4 = (void*) _a3_arr;
        l5 = ((vader_struct_vader_midir_CFGStructDecl_t*) l0)->f_fields;
        l11 = ((vader_array_t*) l5)->length;
        l12 = INT64_C(0);
        while ((l12 < l11)) {
            vader_array_t* _a4_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
            l13 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l12);
            l9 = vader_bytecode_intern_type(((vader_struct_vader_midir_CFGStructField_t*) l13)->f_type, l1);
            t3 = ((vader_struct_vader_midir_CFGStructField_t*) l13)->f_name;
            vader_struct_vader_bytecode_BcField_t* _a5_obj = (vader_struct_vader_bytecode_BcField_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcField_t));
            vader_obj_header_init(_a5_obj, 640u);
            _a5_obj->f_name = t3;
            _a5_obj->f_type_index = l9;
            l14 = (void*) _a5_obj;
            vader_array_push((vader_array_t*) l4, vader_ref_box(l14));
            l12 = (l12 + INT64_C(1));
        }
        l5 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_types;
        l6 = ((vader_struct_vader_midir_CFGStructDecl_t*) l0)->f_mangled;
        l15 = vader_midir_c_struct_of(((vader_struct_vader_midir_CFGStructDecl_t*) l0)->f_origin);
        vader_struct_vader_bytecode_BcStruct_t* _a6_obj = (vader_struct_vader_bytecode_BcStruct_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcStruct_t));
        vader_obj_header_init(_a6_obj, 652u);
        _a6_obj->f_name = l6;
        _a6_obj->f_fields = l4;
        _a6_obj->f_c_name = l15;
        _a6_obj->f_symbol_id = l2;
        l4 = (void*) _a6_obj;
        vader_array_t* _a7_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l8)
        vader_array_ref_store(_a7_slotarr->buf, _a7_slotarr->offset + (size_t) l8, l4);
        VADER_WRITE_BARRIER(_a7_slotarr->buf);
        { vader_gc_top = gc_frame.prev; return; }
    }
    t1 = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_types)->length;
    l8 = ((int32_t) (int64_t) t1);
    l4 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_types;
    t3 = ((vader_struct_vader_midir_CFGStructDecl_t*) l0)->f_mangled;
    vader_struct_vader_bytecode_BcRef_t* _a8_obj = (vader_struct_vader_bytecode_BcRef_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcRef_t));
    vader_obj_header_init(_a8_obj, 648u);
    _a8_obj->f_trait_name = t3;
    l5 = (void*) _a8_obj;
    vader_array_push((vader_array_t*) l4, vader_ref_box(l5));
    vader_array_t* _a9_arr = vader_array_new(50u, 0u, 13u, 640u);
    l4 = (void*) _a9_arr;
    l11 = ((vader_array_t*) ((vader_struct_vader_midir_CFGStructDecl_t*) l0)->f_fields)->length;
    vader_array_t* _a10_arr = vader_array_repeat((vader_array_t*) l4, (int64_t) l11);
    l4 = (void*) _a10_arr;
    l5 = ((vader_struct_vader_midir_CFGStructDecl_t*) l0)->f_fields;
    l11 = ((vader_array_t*) l5)->length;
    l12 = INT64_C(0);
    while ((l12 < l11)) {
        vader_array_t* _a11_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
        l13 = vader_array_ref_load_obj(_a11_slotarr->buf, _a11_slotarr->offset + (size_t) l12);
        l9 = vader_bytecode_intern_type(((vader_struct_vader_midir_CFGStructField_t*) l13)->f_type, l1);
        t3 = ((vader_struct_vader_midir_CFGStructField_t*) l13)->f_name;
        vader_struct_vader_bytecode_BcField_t* _a12_obj = (vader_struct_vader_bytecode_BcField_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcField_t));
        vader_obj_header_init(_a12_obj, 640u);
        _a12_obj->f_name = t3;
        _a12_obj->f_type_index = l9;
        l14 = (void*) _a12_obj;
        vader_array_push((vader_array_t*) l4, vader_ref_box(l14));
        l12 = (l12 + INT64_C(1));
    }
    l5 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_types;
    l6 = ((vader_struct_vader_midir_CFGStructDecl_t*) l0)->f_mangled;
    l15 = vader_midir_c_struct_of(((vader_struct_vader_midir_CFGStructDecl_t*) l0)->f_origin);
    vader_struct_vader_bytecode_BcStruct_t* _a13_obj = (vader_struct_vader_bytecode_BcStruct_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcStruct_t));
    vader_obj_header_init(_a13_obj, 652u);
    _a13_obj->f_name = l6;
    _a13_obj->f_fields = l4;
    _a13_obj->f_c_name = l15;
    _a13_obj->f_symbol_id = l2;
    l4 = (void*) _a13_obj;
    vader_array_t* _a14_slotarr = ((vader_array_t*) l5);
    VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a14_slotarr, l8)
    vader_array_ref_store(_a14_slotarr->buf, _a14_slotarr->offset + (size_t) l8, l4);
    VADER_WRITE_BARRIER(_a14_slotarr->buf);
    l4 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_type_key;
    l5 = ((vader_struct_vader_midir_CFGStructDecl_t*) l0)->f_origin;
    l6 = ((vader_struct_vader_midir_CFGStructDecl_t*) l0)->f_mangled;
    l6 = vader_midir_layout_key(l5, l6);
    std_collections_MutableMap_std_core_IndexSet_set_at__string__i32(l4, l6, l8);
    { vader_gc_top = gc_frame.prev; return; }
}

static void* vader_midir_resolve_direct_call(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l8 = NULL;
    int32_t l4;
    vader_box_t l5 = vader_box_null(), l7 = vader_box_null();
    vader_string_t l6 = 0;
    vader_string_t l9 = 0;
    int64_t l10, l11;
    int32_t t0;
    void* t1 = NULL;
    vader_string_t t2 = 0;
    vader_box_t* gc_roots[2] = { &l5, &l7 };
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l3, &l8, &t1 };
    vader_string_t* gc_atom_roots[3] = { &l6, &l9, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project;
    l3 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l2)->f_import_index_by_symbol_id;
    l4 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_midir_InstrCall_t*) l1)->f_callee)->f_id;
    l5 = std_collections_MutableMap_std_core_Index_at__i32__i32(l3, l4);
    if (l5.tag == 288u) {
        t0 = ((int32_t) l5.payload.i);
        l5 = vader_box_i32(288u, t0);
    } else {
        l3 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l2)->f_import_index_by_mangle;
        l6 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_midir_InstrCall_t*) l1)->f_callee)->f_name;
        l5 = std_collections_MutableMap_std_core_Index_at__string__i32(l3, l6);
    }
    if (l5.tag == 288u) {
        l4 = ((int32_t) l5.payload.i);
        l3 = vader_midir_import_call_target(l2, l4);
        if (!(((vader_struct_vader_midir_DirectCallTarget_t*) l3)->f_op.tag == 675u)) {
            { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    l7 = vader_midir_resolve_fn_index(((vader_struct_vader_midir_InstrCall_t*) l1)->f_callee, l2);
    if (!(l7.tag == 0u)) {
        t0 = ((int32_t) l7.payload.i);
        vader_struct_vader_bytecode_Call_t* _a0_obj = (vader_struct_vader_bytecode_Call_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_Call_t));
        vader_obj_header_init(_a0_obj, 674u);
        _a0_obj->f_function_index = t0;
        l3 = (void*) _a0_obj;
        l8 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l2)->f_functions;
        l4 = ((int32_t) l7.payload.i);
        vader_array_t* _a1_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
        t1 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
        l8 = ((vader_struct_vader_bytecode_BcFunction_t*) t1)->f_signature;
        vader_struct_vader_midir_DirectCallTarget_t* _a2_obj = (vader_struct_vader_midir_DirectCallTarget_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_DirectCallTarget_t));
        vader_obj_header_init(_a2_obj, 1086u);
        _a2_obj->f_op = vader_ref_box(l3);
        _a2_obj->f_signature = l8;
        t1 = (void*) _a2_obj;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l5.tag == 288u)) {
        l6 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_midir_InstrCall_t*) l1)->f_callee)->f_name;
        l9 = ((vader_struct_vader_midir_CFGFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_fn_)->f_mangled;
        l10 = vader_host_std_core_byte_len(l6);
        l11 = vader_host_std_core_byte_len(l9);
        l10 = (l10 + l11);
        l3 = (void*) vader_buffer_new((size_t) (INT64_C(117) + l10));
        l10 = INT64_C(0);
        l10 = std_core_write_string_at(l3, l10, 2132u);
        l10 = std_core_write_string_at(l3, l10, l6);
        l10 = std_core_write_string_at(l3, l10, 234u);
        t0 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_midir_InstrCall_t*) l1)->f_callee)->f_id;
        l11 = ((int64_t) (int32_t) t0);
        l10 = std_core_write_int(l3, l10, l11);
        l10 = std_core_write_string_at(l3, l10, 276u);
        l10 = std_core_write_string_at(l3, l10, l9);
        l10 = std_core_write_string_at(l3, l10, 248u);
        t2 = std_core_finish_buffer(l3, l10);
        vader_host_std_abort_panic(t2);
        vader_unreachable("a no-return call returned");
    }
    l4 = ((int32_t) l5.payload.i);
    t1 = vader_midir_import_call_target(l2, l4);
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir_resolve_fn_index(void* l0, void* l1) {
    void* l2;
    vader_string_t l3;
    vader_box_t l4;
    int32_t l5;
    int32_t t0;
    vader_box_t t1;
    l2 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_function_index_by_mangle;
    l3 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l0)->f_name;
    l4 = std_collections_MutableMap_std_core_Index_at__string__i32(l2, l3);
    if (!(l4.tag == 0u)) {
        t0 = ((int32_t) l4.payload.i);
        return vader_box_i32(288u, t0);
    }
    l2 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_function_index_by_symbol_id;
    l5 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l0)->f_id;
    t1 = std_collections_MutableMap_std_core_Index_at__i32__i32(l2, l5);
    return t1;
}

static void* vader_midir_resolve_loop_frame(void* l0, vader_box_t l1) {
    int64_t l2;
    void* l3 = NULL;
    vader_string_t l4 = 0;
    vader_string_t l5 = 0;
    int64_t t0;
    bool t1;
    vader_string_t t2 = 0;
    vader_string_t t3 = 0;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[2] = { &l0, &l3 };
    vader_string_t* gc_atom_roots[4] = { &l4, &l5, &t2, &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l1.tag == 0u) {
        t0 = ((vader_array_t*) ((vader_struct_vader_midir_FnCtx_t*) l0)->f_loop_stack)->length;
        l2 = vader_chk_sub(i64, t0, INT64_C(1));
        while ((l2 >= INT64_C(0))) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_midir_FnCtx_t*) l0)->f_loop_stack);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
            l3 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
            t1 = ((vader_struct_vader_midir_LoopFrame_t*) l3)->f_block;
            if (!(t1)) {
                { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
            }
            l2 = vader_chk_sub(i64, l2, INT64_C(1));
        }
        l4 = ((vader_struct_vader_midir_FnCtx_t*) l0)->f_mangled;
        t2 = concat_3(2125u, l4, 962u);
        vader_host_std_abort_panic(t2);
        vader_unreachable("a no-return call returned");
    } else {
        l4 = l1.payload.s;
        t0 = ((vader_array_t*) ((vader_struct_vader_midir_FnCtx_t*) l0)->f_loop_stack)->length;
        l2 = vader_chk_sub(i64, t0, INT64_C(1));
        while ((l2 >= INT64_C(0))) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_midir_FnCtx_t*) l0)->f_loop_stack);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l2)
            l3 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l2);
            if (!(((vader_struct_vader_midir_LoopFrame_t*) l3)->f_label.tag == 0u)) {
                t2 = ((vader_struct_vader_midir_LoopFrame_t*) l3)->f_label.payload.s;
                if (t2 == l4) {
                    { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
                }
            }
            l2 = vader_chk_sub(i64, l2, INT64_C(1));
        }
        l5 = ((vader_struct_vader_midir_FnCtx_t*) l0)->f_mangled;
        t2 = concat_5(2125u, l5, 1042u, l4, 911u);
        t3 = concat_2(t2, 2477u);
        vader_host_std_abort_panic(t3);
        vader_unreachable("a no-return call returned");
    }
    vader_gc_top = gc_frame.prev;
}

static vader_string_t vader_midir_result_c_type_of(void* l0) {
    vader_box_t l1;
    void* t0;
    vader_string_t t1;
    l1 = ((vader_struct_vader_comptime_MonoEntry_t*) l0)->f_decl;
    if (!(l1.tag == 560u)) {
        return 0u;
    }
    t0 = l1.payload.obj;
    t1 = toolchain_ast_c_type_of(((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_decorators);
    return t1;
}

static vader_box_t vader_midir_retargeted(void* l0, vader_box_t l1) {
    vader_box_t l2 = vader_box_null();
    void* l3 = NULL;
    void* l5 = NULL;
    int32_t l4, l6, l7;
    void* t0 = NULL;
    vader_box_t* gc_roots[2] = { &l1, &l2 };
    void** gc_raw_roots[4] = { &l0, &l3, &l5, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l1.tag == 1136u) {
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir_TermBranch_t*) t0)->f_span;
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_midir_TermBranch_t*) t0)->f_target;
        l4 = vader_midir_destination(l0, l4);
        vader_struct_vader_midir_TermBranch_t* _a0_obj = (vader_struct_vader_midir_TermBranch_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_TermBranch_t));
        vader_obj_header_init(_a0_obj, 1136u);
        _a0_obj->f_span = l3;
        _a0_obj->f_target = l4;
        t0 = (void*) _a0_obj;
        l2 = vader_ref_box(t0);
        { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 1137u) {
        l3 = l1.payload.obj;
        l5 = ((vader_struct_vader_midir_TermCondBranch_t*) l3)->f_span;
        l4 = ((vader_struct_vader_midir_TermCondBranch_t*) l3)->f_cond;
        t0 = l1.payload.obj;
        l6 = ((vader_struct_vader_midir_TermCondBranch_t*) t0)->f_then_block;
        l6 = vader_midir_destination(l0, l6);
        t0 = l1.payload.obj;
        l7 = ((vader_struct_vader_midir_TermCondBranch_t*) t0)->f_else_block;
        l7 = vader_midir_destination(l0, l7);
        vader_struct_vader_midir_TermCondBranch_t* _a1_obj = (vader_struct_vader_midir_TermCondBranch_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_TermCondBranch_t));
        vader_obj_header_init(_a1_obj, 1137u);
        _a1_obj->f_span = l5;
        _a1_obj->f_cond = l4;
        _a1_obj->f_then_block = l6;
        _a1_obj->f_else_block = l7;
        t0 = (void*) _a1_obj;
        l2 = vader_ref_box(t0);
    } else {
        if (!((l1.tag == 1138u || l1.tag == 1139u))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l2 = l1;
    }
    { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_midir_reverse_postorder(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    int64_t l3;
    int32_t l4;
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(15u, 0u, 7u, 288u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(12u, 1u, 12u, 283u);
    ((uint8_t*) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = (uint8_t) false;
    l2 = (void*) _a1_arr;
    l3 = ((vader_array_t*) ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_blocks)->length;
    vader_array_t* _a2_arr = vader_array_repeat((vader_array_t*) l2, (int64_t) l3);
    l2 = (void*) _a2_arr;
    l4 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_entry;
    vader_midir_walk_rpo(l0, l4, l2, l1);
    vader_array_t* _a3_arr = vader_array_new(15u, 0u, 7u, 288u);
    l2 = (void*) _a3_arr;
    l3 = ((vader_array_t*) l1)->length;
    vader_array_t* _a4_arr = vader_array_repeat((vader_array_t*) l2, (int64_t) l3);
    l2 = (void*) _a4_arr;
    l3 = ((vader_array_t*) l1)->length;
    vader_array_t* _pc31_hdr = (vader_array_t*) l2;
    size_t _pc31_len = _pc31_hdr->length;
    size_t _pc31_cap = (_pc31_hdr->offset == 0 && !vader_array_is_borrowed(_pc31_hdr) && _pc31_hdr->length >= _pc31_hdr->buf->length) ? _pc31_hdr->capacity : (size_t) 0;
    void* _pc31_slots = _pc31_hdr->buf->slots;
    for (;;) {
        if ((l3 > INT64_C(0))) {
            l3 = vader_chk_sub(i64, l3, INT64_C(1));
            vader_array_t* _a5_slotarr = ((vader_array_t*) l1);
            VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l3)
            l4 = ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l3];
            if (VADER_LIKELY(_pc31_len < _pc31_cap)) {
                ((int32_t*) _pc31_slots)[_pc31_len] = (int32_t) (l4);
                _pc31_len += 1;
            } else {
                _pc31_hdr->length = _pc31_len;
                if (_pc31_hdr->buf->length < _pc31_len) {
                    _pc31_hdr->buf->length = _pc31_len;
                }
                vader_array_push_i32((vader_array_t*) l2, l4);
                _pc31_hdr = (vader_array_t*) l2;
                _pc31_len = _pc31_hdr->length;
                _pc31_cap = (_pc31_hdr->offset == 0 && !vader_array_is_borrowed(_pc31_hdr) && _pc31_hdr->length >= _pc31_hdr->buf->length) ? _pc31_hdr->capacity : (size_t) 0;
                _pc31_slots = _pc31_hdr->buf->slots;
            }
            continue;
        }
        _pc31_hdr->length = _pc31_len;
        if (_pc31_hdr->buf->length < _pc31_len) {
            _pc31_hdr->buf->length = _pc31_len;
        }
        break;
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_midir_rpo_positions(void* l0, int64_t l1) {
    void* l2 = NULL;
    int64_t l3, l4;
    int32_t l5, l6;
    void* t0 = NULL;
    void** gc_raw_roots[3] = { &l0, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(15u, 1u, 7u, 288u);
    ((int32_t*) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = (int32_t) INT32_C(-1);
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l1);
    l2 = (void*) _a1_arr;
    l3 = INT64_C(0);
    l4 = ((vader_array_t*) l0)->length;
    while ((l3 < l4)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        l5 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l3];
        l6 = ((int32_t) (int64_t) l3);
        vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l5)
        ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l5] = (int32_t) l6;
        l3 = (l3 + INT64_C(1));
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_midir_same_bounds(void* l0, vader_box_t l1) {
    void* l2;
    void* l3;
    void* t0;
    bool t1;
    if (l1.tag == 1263u) {
        l2 = ((vader_struct_vader_types_RangeType_t*) l0)->f_bounds;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_types_RangeType_t*) t0)->f_bounds;
        t1 = vader_integer_same_interval(l2, l3);
        return t1;
    }
    if (l1.tag == 0u) {
        return true;
    }
    t1 = vader_types_is_stored_as_integer(l1);
    return !(t1);
}

static void* vader_midir_schedule_stack(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l6 = NULL;
    void* l12 = NULL;
    void* l15 = NULL;
    void* l17 = NULL;
    void* l24 = NULL;
    void* l26 = NULL;
    int64_t l4, l5, l7, l8, l9, l10, l13, l16, l19, l20, l21, l25;
    vader_box_t l11 = vader_box_null(), l14 = vader_box_null(), l22 = vader_box_null(), l23 = vader_box_null();
    int32_t l18, l27;
    bool t0;
    int64_t t1;
    vader_box_t* gc_roots[4] = { &l11, &l14, &l22, &l23 };
    void** gc_raw_roots[10] = { &l0, &l1, &l2, &l3, &l6, &l12, &l15, &l17, &l24, &l26 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 10u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_midir_count_uses(l0);
    l2 = vader_midir_no_hints();
    l3 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_blocks;
    l4 = ((vader_array_t*) l3)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l6 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
        l7 = INT64_C(0);
        l8 = ((vader_array_t*) ((vader_struct_vader_midir_BasicBlock_t*) l6)->f_instructions)->length;
        while ((l7 < l8)) {
            l9 = vader_chk_add(i64, l7, INT64_C(1));
            l10 = ((vader_array_t*) ((vader_struct_vader_midir_BasicBlock_t*) l6)->f_instructions)->length;
            if ((l9 >= l10)) break;
            vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_midir_BasicBlock_t*) l6)->f_instructions);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l7)
            l11 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l7);
            l12 = ((vader_struct_vader_midir_BasicBlock_t*) l6)->f_instructions;
            l13 = vader_chk_add(i64, l7, INT64_C(1));
            vader_array_t* _a2_slotarr = ((vader_array_t*) l12);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l13)
            l14 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l13);
            t0 = vader_midir_can_pass_through_stack(l11, l14, l1);
            if (t0) {
                l15 = ((vader_struct_vader_midir_ScheduleHints_t*) l2)->f_skip_set;
                l16 = vader_midir_pos_key(((vader_struct_vader_midir_BasicBlock_t*) l6)->f_id, l7);
                std_collections_add__i64(l15, l16);
                l17 = ((vader_struct_vader_midir_ScheduleHints_t*) l2)->f_skip_first_get;
                l18 = ((vader_struct_vader_midir_BasicBlock_t*) l6)->f_id;
                l19 = vader_chk_add(i64, l7, INT64_C(1));
                l20 = vader_midir_pos_key(l18, l19);
                std_collections_add__i64(l17, l20);
                l7 = (l7 + INT64_C(1));
                continue;
            }
            l7 = (l7 + INT64_C(1));
        }
        t1 = ((vader_array_t*) ((vader_struct_vader_midir_BasicBlock_t*) l6)->f_instructions)->length;
        if (t1 == INT64_C(0)) {
            l5 = (l5 + INT64_C(1));
            continue;
        }
        t1 = ((vader_array_t*) ((vader_struct_vader_midir_BasicBlock_t*) l6)->f_instructions)->length;
        l21 = vader_chk_sub(i64, t1, INT64_C(1));
        vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_midir_BasicBlock_t*) l6)->f_instructions);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l21)
        l22 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l21);
        l23 = ((vader_struct_vader_midir_BasicBlock_t*) l6)->f_terminator;
        t0 = vader_midir_can_pass_through_terminator(l22, l23, l1);
        if (t0) {
            l24 = ((vader_struct_vader_midir_ScheduleHints_t*) l2)->f_skip_set;
            l25 = vader_midir_pos_key(((vader_struct_vader_midir_BasicBlock_t*) l6)->f_id, l21);
            std_collections_add__i64(l24, l25);
            l26 = ((vader_struct_vader_midir_ScheduleHints_t*) l2)->f_skip_terminator_get;
            l27 = ((vader_struct_vader_midir_BasicBlock_t*) l6)->f_id;
            std_collections_add__i32(l26, l27);
            l5 = (l5 + INT64_C(1));
            continue;
        }
        l5 = (l5 + INT64_C(1));
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_midir_sets_equal(void* l0, void* l1) {
    int64_t l2, l3;
    void* l4;
    void* l5;
    int32_t l6;
    bool t0;
    l2 = std_collections_len__i32(l0);
    l3 = std_collections_len__i32(l1);
    if (l2 != l3) {
        return false;
    }
    l4 = l0;
    l5 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) ((vader_struct_std_collections_MutableSet__i32_t*) l4)->f_inner)->f_ekeys;
    l2 = INT64_C(0);
    l3 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) ((vader_struct_std_collections_MutableSet__i32_t*) l4)->f_inner)->f_size;
    while ((l2 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
        l6 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l2];
        t0 = std_collections_MutableSet_std_core_Contains_contains__i32(l1, l6);
        if (!(t0)) {
            return false;
        }
        l2 = (l2 + INT64_C(1));
    }
    return true;
}

static void* vader_midir_shape_of(void* l0, void* l1, void* l2) {
    int64_t l3, l11, l12, l15, l16, l26, l28, l29, l30;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    void* l27 = NULL;
    void* l32 = NULL;
    void* l33 = NULL;
    void* l34 = NULL;
    void* l35 = NULL;
    void* l36 = NULL;
    void* l39 = NULL;
    int32_t l13, l14, l17, l18, l19, l20, l21, l22, l23, l24, l37, l40, l43, l44, l48, l50, l51, l52, l53, l54;
    vader_string_t l25 = 0;
    bool l31, l38, l41, l42, l45, l46, l47, l49;
    void* t0 = NULL;
    int32_t t1;
    bool t2;
    vader_string_t t3 = 0;
    int64_t t4, t5;
    vader_box_t t6 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t6 };
    void** gc_raw_roots[18] = {
        &l0, &l1, &l2, &l4, &l5, &l6, &l7, &l8, &l9, &l10, &l27, &l32, &l33, &l34, &l35, &l36, &l39,
        &t0,
    };
    vader_string_t* gc_atom_roots[2] = { &l25, &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 18u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = ((vader_array_t*) ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_blocks)->length;
    l4 = vader_midir_reverse_postorder(l0);
    l5 = vader_midir_rpo_positions(l4, l3);
    l6 = vader_midir_natural_loop_bodies(l0, l1, l2);
    vader_array_t* _a0_arr = vader_array_new(12u, 1u, 12u, 283u);
    ((uint8_t*) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = (uint8_t) false;
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l3);
    l7 = (void*) _a1_arr;
    l8 = l6;
    l9 = ((vader_struct_std_collections_MutableMap__i32__std_collections_MutableSet_i32__t*) l8)->f_ekeys;
    l10 = ((vader_struct_std_collections_MutableMap__i32__std_collections_MutableSet_i32__t*) l8)->f_evals;
    l11 = INT64_C(0);
    l12 = ((vader_struct_std_collections_MutableMap__i32__std_collections_MutableSet_i32__t*) l8)->f_size;
    while ((l11 < l12)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l9);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l11)
        l13 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l11];
        vader_array_t* _a3_slotarr = ((vader_array_t*) l10);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l11)
        t0 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l11);
        l14 = l13;
        vader_array_t* _a4_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l14)
        ((uint8_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l14] = (uint8_t) true;
        l11 = (l11 + INT64_C(1));
    }
    vader_array_t* _a5_arr = vader_array_new(15u, 1u, 7u, 288u);
    ((int32_t*) _a5_arr->buf->slots)[_a5_arr->offset + 0u] = (int32_t) INT32_C(0);
    t0 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l3);
    l8 = (void*) _a6_arr;
    l9 = l4;
    l11 = ((vader_array_t*) l9)->length;
    l12 = INT64_C(0);
    while ((l12 < l11)) {
        vader_array_t* _a7_slotarr = ((vader_array_t*) l9);
        VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
        l13 = ((int32_t*) _a7_slotarr->buf->slots)[_a7_slotarr->offset + (size_t) l12];
        l14 = l13;
        vader_array_t* _a8_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l14)
        l10 = vader_array_ref_load_obj(_a8_slotarr->buf, _a8_slotarr->offset + (size_t) l14);
        l15 = ((vader_array_t*) l10)->length;
        l16 = INT64_C(0);
        while ((l16 < l15)) {
            vader_array_t* _a9_slotarr = ((vader_array_t*) l10);
            VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
            l17 = ((int32_t*) _a9_slotarr->buf->slots)[_a9_slotarr->offset + (size_t) l16];
            l18 = l17;
            vader_array_t* _a10_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a10_slotarr, l18)
            t1 = ((int32_t*) _a10_slotarr->buf->slots)[_a10_slotarr->offset + (size_t) l18];
            if ((t1 < INT32_C(0))) {
                l16 = (l16 + INT64_C(1));
                continue;
            }
            l19 = l17;
            vader_array_t* _a11_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l19)
            l20 = ((int32_t*) _a11_slotarr->buf->slots)[_a11_slotarr->offset + (size_t) l19];
            l21 = l13;
            VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l21)
            l22 = ((int32_t*) _a11_slotarr->buf->slots)[_a11_slotarr->offset + (size_t) l21];
            if ((l20 < l22)) {
                l23 = l13;
                vader_array_t* _a12_slotarr = ((vader_array_t*) l8);
                VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a12_slotarr, l23)
                t1 = ((int32_t*) _a12_slotarr->buf->slots)[_a12_slotarr->offset + (size_t) l23];
                l24 = vader_chk_add(i32, t1, INT32_C(1));
                VADER_ARRAY_CHECK_INDEX(_a12_slotarr, l23)
                ((int32_t*) _a12_slotarr->buf->slots)[_a12_slotarr->offset + (size_t) l23] = (int32_t) l24;
            } else {
                t2 = vader_midir_closes_loop(l6, l17, l13);
                if (!(t2)) {
                    l25 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_mangled;
                    l26 = vader_host_std_core_byte_len(l25);
                    l27 = (void*) vader_buffer_new((size_t) (INT64_C(127) + l26));
                    l28 = INT64_C(0);
                    l28 = std_core_write_string_at(l27, l28, 2136u);
                    l28 = std_core_write_string_at(l27, l28, l25);
                    l28 = std_core_write_string_at(l27, l28, 246u);
                    l29 = ((int64_t) (int32_t) l17);
                    l28 = std_core_write_int(l27, l28, l29);
                    l28 = std_core_write_string_at(l27, l28, 195u);
                    l30 = ((int64_t) (int32_t) l13);
                    l28 = std_core_write_int(l27, l28, l30);
                    l28 = std_core_write_string_at(l27, l28, 78u);
                    t3 = std_core_finish_buffer(l27, l28);
                    vader_host_std_abort_panic(t3);
                    vader_unreachable("a no-return call returned");
                }
            }
            l16 = (l16 + INT64_C(1));
        }
        l12 = (l12 + INT64_C(1));
    }
    vader_array_t* _a13_arr = vader_array_new(12u, 1u, 12u, 283u);
    ((uint8_t*) _a13_arr->buf->slots)[_a13_arr->offset + 0u] = (uint8_t) false;
    t0 = (void*) _a13_arr;
    vader_array_t* _a14_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l3);
    l9 = (void*) _a14_arr;
    l11 = INT64_C(0);
    l12 = ((vader_array_t*) l4)->length;
    while ((l11 < l12)) {
        t4 = ((vader_array_t*) l4)->length;
        t5 = vader_chk_sub(i64, t4, INT64_C(1));
        l15 = vader_chk_sub(i64, t5, l11);
        vader_array_t* _a15_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a15_slotarr, l15)
        l13 = ((int32_t*) _a15_slotarr->buf->slots)[_a15_slotarr->offset + (size_t) l15];
        l14 = l13;
        l17 = l13;
        vader_array_t* _a16_slotarr = ((vader_array_t*) l9);
        VADER_ARRAY_RESOLVE_BUF(_a16_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a16_slotarr, l17)
        t6 = vader_box_bool(283u, ((uint8_t*) _a16_slotarr->buf->slots)[_a16_slotarr->offset + (size_t) l17]);
        t2 = t6.payload.b;
        if (t2) {
            l31 = true;
        } else {
            l18 = l13;
            vader_array_t* _a17_slotarr = ((vader_array_t*) l7);
            VADER_ARRAY_RESOLVE_BUF(_a17_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a17_slotarr, l18)
            t6 = vader_box_bool(283u, ((uint8_t*) _a17_slotarr->buf->slots)[_a17_slotarr->offset + (size_t) l18]);
            l31 = t6.payload.b;
        }
        vader_array_t* _a18_slotarr = ((vader_array_t*) l9);
        VADER_ARRAY_RESOLVE_BUF(_a18_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a18_slotarr, l14)
        ((uint8_t*) _a18_slotarr->buf->slots)[_a18_slotarr->offset + (size_t) l14] = (uint8_t) l31;
        l19 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_entry;
        t2 = vader_midir_BlockId_std_core_Equals_equals(l13, l19);
        if (!(t2)) {
            l20 = l13;
            vader_array_t* _a19_slotarr = ((vader_array_t*) l9);
            VADER_ARRAY_RESOLVE_BUF(_a19_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a19_slotarr, l20)
            t6 = vader_box_bool(283u, ((uint8_t*) _a19_slotarr->buf->slots)[_a19_slotarr->offset + (size_t) l20]);
            t2 = t6.payload.b;
            if (t2) {
                l21 = l13;
                vader_array_t* _a20_slotarr = ((vader_array_t*) l2);
                VADER_ARRAY_RESOLVE_BUF(_a20_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a20_slotarr, l21)
                l22 = ((int32_t*) _a20_slotarr->buf->slots)[_a20_slotarr->offset + (size_t) l21];
                vader_array_t* _a21_slotarr = ((vader_array_t*) l9);
                VADER_ARRAY_RESOLVE_BUF(_a21_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a21_slotarr, l22)
                ((uint8_t*) _a21_slotarr->buf->slots)[_a21_slotarr->offset + (size_t) l22] = (uint8_t) true;
            }
        }
        l11 = (l11 + INT64_C(1));
    }
    vader_array_t* _a22_arr = vader_array_new(12u, 1u, 12u, 283u);
    ((uint8_t*) _a22_arr->buf->slots)[_a22_arr->offset + 0u] = (uint8_t) false;
    t0 = (void*) _a22_arr;
    vader_array_t* _a23_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l3);
    l10 = (void*) _a23_arr;
    vader_array_t* _a24_arr = vader_array_new(12u, 1u, 12u, 283u);
    ((uint8_t*) _a24_arr->buf->slots)[_a24_arr->offset + 0u] = (uint8_t) false;
    t0 = (void*) _a24_arr;
    vader_array_t* _a25_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l3);
    l27 = (void*) _a25_arr;
    vader_array_t* _a26_arr = vader_array_new(2u, 0u, 13u, 15u);
    l32 = (void*) _a26_arr;
    if ((INT64_C(0) < l3)) {
        l11 = l3;
    } else {
        l11 = INT64_C(0);
    }
    vader_array_t* _a27_arr = vader_array_repeat((vader_array_t*) l32, (int64_t) l11);
    l32 = (void*) _a27_arr;
    vader_array_t* _a28_arr = vader_array_new(2u, 0u, 13u, 15u);
    l33 = (void*) _a28_arr;
    if ((INT64_C(0) < l3)) {
        l11 = l3;
    } else {
        l11 = INT64_C(0);
    }
    vader_array_t* _a29_arr = vader_array_repeat((vader_array_t*) l33, (int64_t) l11);
    l33 = (void*) _a29_arr;
    vader_array_t* _a30_arr = vader_array_new(15u, 1u, 7u, 288u);
    ((int32_t*) _a30_arr->buf->slots)[_a30_arr->offset + 0u] = (int32_t) INT32_C(-1);
    t0 = (void*) _a30_arr;
    vader_array_t* _a31_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l3);
    l34 = (void*) _a31_arr;
    l11 = INT64_C(0);
    while ((l11 < l3)) {
        vader_array_t* _a32_arr = vader_array_new(15u, 0u, 7u, 288u);
        l35 = (void*) _a32_arr;
        vader_array_push((vader_array_t*) l32, vader_ref_box(l35));
        vader_array_t* _a33_arr = vader_array_new(15u, 0u, 7u, 288u);
        l36 = (void*) _a33_arr;
        vader_array_push((vader_array_t*) l33, vader_ref_box(l36));
        l11 = (l11 + INT64_C(1));
    }
    l3 = ((vader_array_t*) l4)->length;
    l11 = INT64_C(0);
    while ((l11 < l3)) {
        vader_array_t* _a34_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a34_slotarr)
        l13 = ((int32_t*) _a34_slotarr->buf->slots)[_a34_slotarr->offset + (size_t) l11];
        l14 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_entry;
        t2 = vader_midir_BlockId_std_core_Equals_equals(l13, l14);
        if (t2) {
            l11 = (l11 + INT64_C(1));
            continue;
        }
        l17 = l13;
        vader_array_t* _a35_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a35_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a35_slotarr, l17)
        t1 = ((int32_t*) _a35_slotarr->buf->slots)[_a35_slotarr->offset + (size_t) l17];
        if ((t1 >= INT32_C(2))) {
            l18 = l13;
            vader_array_t* _a36_slotarr = ((vader_array_t*) l1);
            VADER_ARRAY_RESOLVE_BUF(_a36_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a36_slotarr, l18)
            l35 = vader_array_ref_load_obj(_a36_slotarr->buf, _a36_slotarr->offset + (size_t) l18);
            t2 = vader_midir_entered_by_test(l6, l35, l13);
            l31 = !(t2);
        } else {
            l31 = false;
        }
        if (l31) {
            l36 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_blocks;
            l19 = l13;
            vader_array_t* _a37_slotarr = ((vader_array_t*) l36);
            VADER_ARRAY_RESOLVE_BUF(_a37_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a37_slotarr, l19)
            t0 = vader_array_ref_load_obj(_a37_slotarr->buf, _a37_slotarr->offset + (size_t) l19);
            t2 = vader_midir_copies_cheaply(t0);
            if (t2) {
                l20 = l13;
                vader_array_t* _a38_slotarr = ((vader_array_t*) l27);
                VADER_ARRAY_RESOLVE_BUF(_a38_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a38_slotarr, l20)
                ((uint8_t*) _a38_slotarr->buf->slots)[_a38_slotarr->offset + (size_t) l20] = (uint8_t) true;
                l11 = (l11 + INT64_C(1));
                continue;
            }
        }
        l21 = l13;
        vader_array_t* _a39_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a39_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a39_slotarr, l21)
        l22 = ((int32_t*) _a39_slotarr->buf->slots)[_a39_slotarr->offset + (size_t) l21];
        l23 = l22;
        l24 = vader_midir_outermost_loop_left(l6, l5, l23, l13);
        if ((l24 >= INT32_C(0))) {
            l37 = l24;
            l38 = vader_midir_tests_its_exit(l0, l6, l37);
            l39 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_blocks;
            l40 = l13;
            vader_array_t* _a40_slotarr = ((vader_array_t*) l39);
            VADER_ARRAY_RESOLVE_BUF(_a40_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a40_slotarr, l40)
            t0 = vader_array_ref_load_obj(_a40_slotarr->buf, _a40_slotarr->offset + (size_t) l40);
            l41 = vader_midir_ends_function(((vader_struct_vader_midir_BasicBlock_t*) t0)->f_terminator);
            l43 = l13;
            vader_array_t* _a41_slotarr = ((vader_array_t*) l8);
            VADER_ARRAY_RESOLVE_BUF(_a41_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a41_slotarr, l43)
            t1 = ((int32_t*) _a41_slotarr->buf->slots)[_a41_slotarr->offset + (size_t) l43];
            if ((t1 < INT32_C(2))) {
                l44 = l13;
                vader_array_t* _a42_slotarr = ((vader_array_t*) l9);
                VADER_ARRAY_RESOLVE_BUF(_a42_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a42_slotarr, l44)
                t6 = vader_box_bool(283u, ((uint8_t*) _a42_slotarr->buf->slots)[_a42_slotarr->offset + (size_t) l44]);
                t2 = t6.payload.b;
                l42 = !(t2);
            } else {
                l42 = false;
            }
            if (l38) {
                l46 = true;
            } else {
                l46 = l41;
            }
            if (l46) {
                l47 = true;
            } else {
                l47 = l42;
            }
            if (l47) {
                l48 = l22;
                t2 = vader_midir_leaves_header(l6, l48, l13);
                l45 = !(t2);
            } else {
                l45 = false;
            }
            if (!(l45)) {
                l49 = true;
            } else {
                l50 = l13;
                vader_array_t* _a43_slotarr = ((vader_array_t*) l1);
                VADER_ARRAY_RESOLVE_BUF(_a43_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a43_slotarr, l50)
                t0 = vader_array_ref_load_obj(_a43_slotarr->buf, _a43_slotarr->offset + (size_t) l50);
                t2 = vader_midir_emitted_beneath(t0, l5, l2, l34, l22);
                l49 = !(t2);
            }
            if (l49) {
                vader_array_t* _a44_slotarr = ((vader_array_t*) l33);
                VADER_ARRAY_RESOLVE_BUF(_a44_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a44_slotarr, l24)
                t0 = vader_array_ref_load_obj(_a44_slotarr->buf, _a44_slotarr->offset + (size_t) l24);
                vader_array_push_i32((vader_array_t*) t0, l13);
                l51 = l13;
                vader_array_t* _a45_slotarr = ((vader_array_t*) l34);
                VADER_ARRAY_RESOLVE_BUF(_a45_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a45_slotarr, l51)
                ((int32_t*) _a45_slotarr->buf->slots)[_a45_slotarr->offset + (size_t) l51] = (int32_t) l24;
                l52 = l13;
                vader_array_t* _a46_slotarr = ((vader_array_t*) l10);
                VADER_ARRAY_RESOLVE_BUF(_a46_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a46_slotarr, l52)
                ((uint8_t*) _a46_slotarr->buf->slots)[_a46_slotarr->offset + (size_t) l52] = (uint8_t) true;
                l11 = (l11 + INT64_C(1));
                continue;
            }
        }
        l53 = l13;
        vader_array_t* _a47_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a47_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a47_slotarr, l53)
        t1 = ((int32_t*) _a47_slotarr->buf->slots)[_a47_slotarr->offset + (size_t) l53];
        if ((t1 >= INT32_C(2))) {
            vader_array_t* _a48_slotarr = ((vader_array_t*) l32);
            VADER_ARRAY_RESOLVE_BUF(_a48_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a48_slotarr, l22)
            t0 = vader_array_ref_load_obj(_a48_slotarr->buf, _a48_slotarr->offset + (size_t) l22);
            vader_array_push_i32((vader_array_t*) t0, l13);
            l54 = l13;
            vader_array_t* _a49_slotarr = ((vader_array_t*) l10);
            VADER_ARRAY_RESOLVE_BUF(_a49_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a49_slotarr, l54)
            ((uint8_t*) _a49_slotarr->buf->slots)[_a49_slotarr->offset + (size_t) l54] = (uint8_t) true;
        }
        l11 = (l11 + INT64_C(1));
    }
    vader_struct_vader_midir_StructureShape_t* _a50_obj = (vader_struct_vader_midir_StructureShape_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_StructureShape_t));
    vader_obj_header_init(_a50_obj, 1135u);
    _a50_obj->f_rpo_index = l5;
    _a50_obj->f_loop_header = l7;
    _a50_obj->f_merge = l10;
    _a50_obj->f_merges = l32;
    _a50_obj->f_exits = l33;
    _a50_obj->f_copied = l27;
    t0 = (void*) _a50_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_midir_skip_forwarding_blocks(void* l0) {
    int64_t l1, l4, l5, l7, l8;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l6 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    void* l17 = NULL;
    void* l21 = NULL;
    void* l22 = NULL;
    int32_t l9, l10, l15, l16, l18, l19;
    bool l11, l25;
    vader_box_t l14 = vader_box_null(), l20 = vader_box_null();
    vader_string_t l23 = 0;
    vader_string_t l24 = 0;
    void* t0 = NULL;
    int32_t t1;
    int64_t t2;
    bool t3;
    vader_box_t* gc_roots[2] = { &l14, &l20 };
    void** gc_raw_roots[10] = { &l0, &l2, &l3, &l6, &l12, &l13, &l17, &l21, &l22, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l23, &l24 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 10u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = ((vader_array_t*) ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_blocks)->length;
    vader_array_t* _a0_arr = vader_array_new(15u, 1u, 7u, 288u);
    ((int32_t*) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = (int32_t) INT32_C(0);
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l1);
    l2 = (void*) _a1_arr;
    l3 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_blocks;
    l4 = ((vader_array_t*) l3)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        t0 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l5);
        l6 = vader_midir_successors_of(t0);
        l7 = ((vader_array_t*) l6)->length;
        l8 = INT64_C(0);
        while ((l8 < l7)) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l6);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            l9 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l8];
            vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l9)
            t1 = ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l9];
            l10 = vader_chk_add(i32, t1, INT32_C(1));
            VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l9)
            ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l9] = (int32_t) l10;
            l8 = (l8 + INT64_C(1));
        }
        l5 = (l5 + INT64_C(1));
    }
    vader_array_t* _a5_arr = vader_array_new(15u, 1u, 7u, 288u);
    ((int32_t*) _a5_arr->buf->slots)[_a5_arr->offset + 0u] = (int32_t) INT32_C(-1);
    t0 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l1);
    l3 = (void*) _a6_arr;
    l11 = false;
    vader_array_t* _a7_arr = vader_array_new(15u, 0u, 7u, 288u);
    l6 = (void*) _a7_arr;
    l12 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_blocks;
    l1 = ((vader_array_t*) l12)->length;
    l4 = INT64_C(0);
    vader_array_t* _pc76_hdr = (vader_array_t*) l6;
    size_t _pc76_len = _pc76_hdr->length;
    size_t _pc76_cap = (_pc76_hdr->offset == 0 && !vader_array_is_borrowed(_pc76_hdr) && _pc76_hdr->length >= _pc76_hdr->buf->length) ? _pc76_hdr->capacity : (size_t) 0;
    void* _pc76_slots = _pc76_hdr->buf->slots;
    for (;;) {
        if ((l4 < l1)) {
            vader_array_t* _a8_slotarr = ((vader_array_t*) l12);
            VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
            l13 = vader_array_ref_load_obj(_a8_slotarr->buf, _a8_slotarr->offset + (size_t) l4);
            l14 = ((vader_struct_vader_midir_BasicBlock_t*) l13)->f_terminator;
            t2 = ((vader_array_t*) ((vader_struct_vader_midir_BasicBlock_t*) l13)->f_instructions)->length;
            if (t2 == INT64_C(0)) {
                if (l14.tag == 1136u) {
                    l9 = ((vader_struct_vader_midir_BasicBlock_t*) l13)->f_id;
                    vader_array_t* _a9_slotarr = ((vader_array_t*) l2);
                    VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l9)
                    t1 = ((int32_t*) _a9_slotarr->buf->slots)[_a9_slotarr->offset + (size_t) l9];
                    if ((t1 < INT32_C(2))) {
                        l10 = ((vader_struct_vader_midir_BasicBlock_t*) l13)->f_id;
                        t0 = l14.payload.obj;
                        l15 = ((vader_struct_vader_midir_TermBranch_t*) t0)->f_target;
                        vader_array_t* _a10_slotarr = ((vader_array_t*) l3);
                        VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a10_slotarr, l10)
                        ((int32_t*) _a10_slotarr->buf->slots)[_a10_slotarr->offset + (size_t) l10] = (int32_t) l15;
                        l11 = true;
                    } else {
                        l16 = ((vader_struct_vader_midir_BasicBlock_t*) l13)->f_id;
                        if (VADER_LIKELY(_pc76_len < _pc76_cap)) {
                            ((int32_t*) _pc76_slots)[_pc76_len] = (int32_t) (l16);
                            _pc76_len += 1;
                        } else {
                            _pc76_hdr->length = _pc76_len;
                            if (_pc76_hdr->buf->length < _pc76_len) {
                                _pc76_hdr->buf->length = _pc76_len;
                            }
                            vader_array_push_i32((vader_array_t*) l6, l16);
                            _pc76_hdr = (vader_array_t*) l6;
                            _pc76_len = _pc76_hdr->length;
                            _pc76_cap = (_pc76_hdr->offset == 0 && !vader_array_is_borrowed(_pc76_hdr) && _pc76_hdr->length >= _pc76_hdr->buf->length) ? _pc76_hdr->capacity : (size_t) 0;
                            _pc76_slots = _pc76_hdr->buf->slots;
                        }
                    }
                }
            }
            l4 = (l4 + INT64_C(1));
            continue;
        }
        _pc76_hdr->length = _pc76_len;
        if (_pc76_hdr->buf->length < _pc76_len) {
            _pc76_hdr->buf->length = _pc76_len;
        }
        break;
    }
    t2 = ((vader_array_t*) l6)->length;
    if ((t2 > INT64_C(0))) {
        l2 = vader_midir_predecessors_of(l0);
        l12 = vader_midir_compute_dominators(l0, l2);
        l12 = vader_midir_natural_loop_bodies(l0, l2, l12);
        l1 = ((vader_array_t*) l6)->length;
        l4 = INT64_C(0);
        while ((l4 < l1)) {
            vader_array_t* _a11_slotarr = ((vader_array_t*) l6);
            VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
            l9 = ((int32_t*) _a11_slotarr->buf->slots)[_a11_slotarr->offset + (size_t) l4];
            l13 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_blocks;
            l10 = l9;
            vader_array_t* _a12_slotarr = ((vader_array_t*) l13);
            VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a12_slotarr, l10)
            t0 = vader_array_ref_load_obj(_a12_slotarr->buf, _a12_slotarr->offset + (size_t) l10);
            l14 = ((vader_struct_vader_midir_BasicBlock_t*) t0)->f_terminator;
            if (l14.tag == 1136u) {
                l15 = l9;
                vader_array_t* _a13_slotarr = ((vader_array_t*) l2);
                VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a13_slotarr, l15)
                l17 = vader_array_ref_load_obj(_a13_slotarr->buf, _a13_slotarr->offset + (size_t) l15);
                t0 = l14.payload.obj;
                l16 = ((vader_struct_vader_midir_TermBranch_t*) t0)->f_target;
                t3 = vader_midir_goes_on_or_out(l0, l12, l17, l16);
                if (t3) {
                    l18 = l9;
                    t0 = l14.payload.obj;
                    l19 = ((vader_struct_vader_midir_TermBranch_t*) t0)->f_target;
                    vader_array_t* _a14_slotarr = ((vader_array_t*) l3);
                    VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a14_slotarr, l18)
                    ((int32_t*) _a14_slotarr->buf->slots)[_a14_slotarr->offset + (size_t) l18] = (int32_t) l19;
                    l11 = true;
                }
            }
            l4 = (l4 + INT64_C(1));
        }
    }
    if (!(l11)) {
        { void* __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a15_arr = vader_array_new(135u, 0u, 13u, 1069u);
    l2 = (void*) _a15_arr;
    l1 = ((vader_array_t*) ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_blocks)->length;
    vader_array_t* _a16_arr = vader_array_repeat((vader_array_t*) l2, (int64_t) l1);
    l2 = (void*) _a16_arr;
    l6 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_blocks;
    l1 = ((vader_array_t*) l6)->length;
    l4 = INT64_C(0);
    while ((l4 < l1)) {
        vader_array_t* _a17_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a17_slotarr)
        l12 = vader_array_ref_load_obj(_a17_slotarr->buf, _a17_slotarr->offset + (size_t) l4);
        l13 = l12;
        l9 = ((vader_struct_vader_midir_BasicBlock_t*) l13)->f_id;
        l17 = ((vader_struct_vader_midir_BasicBlock_t*) l13)->f_instructions;
        l14 = ((vader_struct_vader_midir_BasicBlock_t*) l12)->f_terminator;
        l20 = vader_midir_retargeted(l3, l14);
        l21 = ((vader_struct_vader_midir_BasicBlock_t*) l13)->f_span;
        vader_struct_vader_midir_BasicBlock_t* _a18_obj = (vader_struct_vader_midir_BasicBlock_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_BasicBlock_t));
        vader_obj_header_init(_a18_obj, 1069u);
        _a18_obj->f_id = l9;
        _a18_obj->f_instructions = l17;
        _a18_obj->f_terminator = l20;
        _a18_obj->f_span = l21;
        l22 = (void*) _a18_obj;
        vader_array_push((vader_array_t*) l2, vader_ref_box(l22));
        l4 = (l4 + INT64_C(1));
    }
    l3 = l0;
    l23 = ((vader_struct_vader_midir_CFGFunction_t*) l3)->f_mangled;
    l6 = ((vader_struct_vader_midir_CFGFunction_t*) l3)->f_params;
    l14 = ((vader_struct_vader_midir_CFGFunction_t*) l3)->f_return_type;
    l12 = ((vader_struct_vader_midir_CFGFunction_t*) l3)->f_locals;
    l9 = ((vader_struct_vader_midir_CFGFunction_t*) l3)->f_entry;
    l13 = ((vader_struct_vader_midir_CFGFunction_t*) l3)->f_origin;
    l24 = ((vader_struct_vader_midir_CFGFunction_t*) l3)->f_extern_name;
    l11 = ((vader_struct_vader_midir_CFGFunction_t*) l3)->f_is_extern;
    l25 = ((vader_struct_vader_midir_CFGFunction_t*) l3)->f_is_exported;
    l3 = ((vader_struct_vader_midir_CFGFunction_t*) l3)->f_scalarised_results;
    vader_struct_vader_midir_CFGFunction_t* _a19_obj = (vader_struct_vader_midir_CFGFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_CFGFunction_t));
    vader_obj_header_init(_a19_obj, 1071u);
    _a19_obj->f_mangled = l23;
    _a19_obj->f_params = l6;
    _a19_obj->f_return_type = l14;
    _a19_obj->f_locals = l12;
    _a19_obj->f_blocks = l2;
    _a19_obj->f_entry = l9;
    _a19_obj->f_origin = l13;
    _a19_obj->f_extern_name = l24;
    _a19_obj->f_is_extern = l11;
    _a19_obj->f_is_exported = l25;
    _a19_obj->f_scalarised_results = l3;
    t0 = (void*) _a19_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir_stored_cell(void* l0, void* l1) {
    int32_t l2, l5;
    vader_box_t l3 = vader_box_null(), l4 = vader_box_null();
    void* l6 = NULL;
    vader_box_t* gc_roots[2] = { &l3, &l4 };
    void** gc_raw_roots[3] = { &l0, &l1, &l6 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_lower_LoweredCellGet_t*) l1)->f_target;
    l3 = vader_midir_build_expr(l0, l3);
    if (l3.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l2 = ((int32_t) l3.payload.i);
    l3 = ((vader_struct_vader_lower_LoweredCellGet_t*) l1)->f_value_type;
    l4 = ((vader_struct_vader_lower_LoweredCellGet_t*) l1)->f_type;
    l3 = vader_midir_read_type(l3, l4);
    l5 = vader_midir_fresh_tmp(l0, 1561u, l3);
    l6 = ((vader_struct_vader_lower_LoweredCellGet_t*) l1)->f_span;
    l3 = ((vader_struct_vader_lower_LoweredCellGet_t*) l1)->f_value_type;
    vader_struct_vader_midir_InstrCellGet_t* _a0_obj = (vader_struct_vader_midir_InstrCellGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrCellGet_t));
    vader_obj_header_init(_a0_obj, 1103u);
    _a0_obj->f_span = l6;
    _a0_obj->f_dst = l5;
    _a0_obj->f_cell = l2;
    _a0_obj->f_value_type = l3;
    l6 = (void*) _a0_obj;
    vader_midir_emit(l0, vader_ref_box(l6));
    { vader_box_t __vret = vader_box_i32(288u, l5); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir_stored_conversion(vader_box_t l0, vader_box_t l1) {
    vader_box_t l2, l5;
    void* l3;
    void* l4;
    vader_string_t l6, l7;
    void* t0;
    bool t1;
    l2 = l1;
    if (l2.tag == 0u) {
        return vader_box_obj(0u, NULL);
    }
    if (l0.tag == 1263u) {
        if (l2.tag == 1263u) {
            t0 = l0.payload.obj;
            l3 = ((vader_struct_vader_types_RangeType_t*) t0)->f_bounds;
            t0 = l2.payload.obj;
            l4 = ((vader_struct_vader_types_RangeType_t*) t0)->f_bounds;
            t1 = vader_integer_same_interval(l3, l4);
            if (t1) {
                return vader_box_obj(0u, NULL);
            }
        }
    }
    l5 = vader_types_held_integer(l0);
    if (l5.tag == 0u) {
        return vader_box_obj(0u, NULL);
    }
    l3 = l5.payload.obj;
    l2 = vader_midir_integer_member(l2, l3);
    if (l2.tag == 0u) {
        return vader_box_obj(0u, NULL);
    }
    l4 = l2.payload.obj;
    l6 = ((vader_struct_vader_integer_MachineInteger_t*) l4)->f_name;
    l7 = ((vader_struct_vader_integer_MachineInteger_t*) l3)->f_name;
    if (!(l6 == l7)) {
        return vader_ref_box(l4);
    }
    return vader_box_obj(0u, NULL);
}

static vader_box_t vader_midir_stored_field(void* l0, void* l1) {
    int32_t l2, l4;
    vader_box_t l3 = vader_box_null();
    void* l5 = NULL;
    vader_string_t l6 = 0;
    vader_box_t* gc_roots[1] = { &l3 };
    void** gc_raw_roots[3] = { &l0, &l1, &l5 };
    vader_string_t* gc_atom_roots[1] = { &l6 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_lower_LoweredFieldAccess_t*) l1)->f_target;
    l3 = vader_midir_build_expr(l0, l3);
    if (l3.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l2 = ((int32_t) l3.payload.i);
    l3 = vader_midir_field_read_type(l0, l2, vader_ref_box(l1));
    l4 = vader_midir_fresh_tmp(l0, 1788u, l3);
    l5 = ((vader_struct_vader_lower_LoweredFieldAccess_t*) l1)->f_span;
    l6 = ((vader_struct_vader_lower_LoweredFieldAccess_t*) l1)->f_field;
    vader_struct_vader_midir_InstrFieldGet_t* _a0_obj = (vader_struct_vader_midir_InstrFieldGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrFieldGet_t));
    vader_obj_header_init(_a0_obj, 1110u);
    _a0_obj->f_span = l5;
    _a0_obj->f_dst = l4;
    _a0_obj->f_target = l2;
    _a0_obj->f_type = l3;
    _a0_obj->f_field = l6;
    l5 = (void*) _a0_obj;
    vader_midir_emit(l0, vader_ref_box(l5));
    { vader_box_t __vret = vader_box_i32(288u, l4); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir_stored_ident(void* l0, void* l1) {
    int32_t l2;
    void* l3 = NULL;
    vader_box_t l4 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    int32_t t1;
    vader_box_t* gc_roots[2] = { &l4, &t0 };
    void** gc_raw_roots[3] = { &l0, &l1, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_midir_FnCtx_t*) l0)->f_local_by_sym_id;
    l2 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_lower_LoweredIdent_t*) l1)->f_symbol)->f_id;
    l4 = std_collections_MutableMap_std_core_Index_at__i32__i32(l3, l2);
    if (l4.tag == 0u) {
        t0 = vader_midir_build_ident(l0, l1);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = ((int32_t) l4.payload.i);
    t1 = vader_midir_stored_slot(l0, l2, l1);
    { vader_box_t __vret = vader_box_i32(288u, t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static int32_t vader_midir_stored_slot(void* l0, int32_t l1, void* l2) {
    void* l3 = NULL;
    int64_t l4;
    vader_box_t l5 = vader_box_null();
    void* t0 = NULL;
    bool t1;
    int32_t t2;
    vader_box_t* gc_roots[1] = { &l5 };
    void** gc_raw_roots[4] = { &l0, &l2, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_midir_FnCtx_t*) l0)->f_locals;
    l4 = ((int64_t) (int32_t) l1);
    vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
    t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
    l5 = ((vader_struct_vader_midir_CFGLocal_t*) t0)->f_type;
    if (l5.tag == 1270u) {
        l3 = l5.payload.obj;
        l5 = ((vader_struct_vader_lower_LoweredIdent_t*) l2)->f_type;
        t1 = vader_typecheck_equals_type(vader_ref_box(l3), l5);
        if (!(t1)) {
            l5 = ((vader_struct_vader_lower_LoweredIdent_t*) l2)->f_type;
            l3 = ((vader_struct_vader_lower_LoweredIdent_t*) l2)->f_span;
            t2 = vader_midir_cast_local(l0, l1, l5, 2168u, l3);
            { int32_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
        }
        { int32_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { int32_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir_stored_test(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l3 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l2, &l3, &t0 };
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (((vader_struct_vader_lower_LoweredBinary_t*) l1)->f_right.tag == 1023u) {
        l2 = ((vader_struct_vader_lower_LoweredBinary_t*) l1)->f_left;
        l3 = ((vader_struct_vader_lower_LoweredIntLit_t*) ((vader_struct_vader_lower_LoweredBinary_t*) l1)->f_right.payload.obj)->f_type;
        t0 = vader_midir_narrowed_local_width(l0, l2, l3);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(((vader_struct_vader_lower_LoweredBinary_t*) l1)->f_left.tag == 1023u)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l2 = ((vader_struct_vader_lower_LoweredBinary_t*) l1)->f_right;
    l3 = ((vader_struct_vader_lower_LoweredIntLit_t*) ((vader_struct_vader_lower_LoweredBinary_t*) l1)->f_left.payload.obj)->f_type;
    t0 = vader_midir_narrowed_local_width(l0, l2, l3);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir_stored_union_field(void* l0, void* l1) {
    int32_t l2, l4;
    vader_box_t l3 = vader_box_null();
    void* l5 = NULL;
    vader_string_t l6 = 0;
    vader_box_t* gc_roots[1] = { &l3 };
    void** gc_raw_roots[3] = { &l0, &l1, &l5 };
    vader_string_t* gc_atom_roots[1] = { &l6 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_lower_LoweredUnionField_t*) l1)->f_target;
    l3 = vader_midir_build_expr(l0, l3);
    if (l3.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l2 = ((int32_t) l3.payload.i);
    l3 = vader_midir_field_read_type(l0, l2, vader_ref_box(l1));
    l4 = vader_midir_fresh_tmp(l0, 1788u, l3);
    l5 = ((vader_struct_vader_lower_LoweredUnionField_t*) l1)->f_span;
    l6 = ((vader_struct_vader_lower_LoweredUnionField_t*) l1)->f_field;
    vader_struct_vader_midir_InstrUnionFieldGet_t* _a0_obj = (vader_struct_vader_midir_InstrUnionFieldGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrUnionFieldGet_t));
    vader_obj_header_init(_a0_obj, 1123u);
    _a0_obj->f_span = l5;
    _a0_obj->f_dst = l4;
    _a0_obj->f_target = l2;
    _a0_obj->f_type = l3;
    _a0_obj->f_field = l6;
    l5 = (void*) _a0_obj;
    vader_midir_emit(l0, vader_ref_box(l5));
    { vader_box_t __vret = vader_box_i32(288u, l4); vader_gc_top = gc_frame.prev; return __vret; }
}

static int32_t vader_midir_struct_symbol_id(vader_box_t l0) {
    void* t0;
    int32_t t1;
    if (!(l0.tag == 1265u)) {
        return INT32_C(-1);
    }
    t0 = l0.payload.obj;
    t1 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_types_StructType_t*) t0)->f_symbol)->f_id;
    return t1;
}

static void vader_midir_structure_function(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    int32_t l4;
    vader_string_t l5 = 0;
    int64_t l6, l7;
    int64_t t0;
    void* t1 = NULL;
    vader_string_t t2 = 0;
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &t1 };
    vader_string_t* gc_atom_roots[2] = { &l5, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = vader_midir_predecessors_of(((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_fn_);
    l2 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_fn_;
    l3 = vader_midir_compute_dominators(((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_fn_, l1);
    l1 = vader_midir_shape_of(l2, l1, l3);
    l4 = ((vader_struct_vader_midir_CFGFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_fn_)->f_entry;
    vader_midir_emit_subtree(l0, l1, l4, INT32_C(-1));
    t0 = ((vader_array_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_pending)->length;
    if (!((t0 > INT64_C(0)))) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l5 = ((vader_struct_vader_midir_CFGFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_fn_)->f_mangled;
    l6 = vader_host_std_core_byte_len(l5);
    l1 = (void*) vader_buffer_new((size_t) (INT64_C(79) + l6));
    l6 = INT64_C(0);
    l6 = std_core_write_string_at(l1, l6, 2136u);
    l6 = std_core_write_string_at(l1, l6, l5);
    l6 = std_core_write_string_at(l1, l6, 244u);
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_pending);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
    t1 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT32_C(0));
    l7 = ((int64_t) (int32_t) ((vader_struct_vader_midir_PendingBranch_t*) t1)->f_target_blk);
    l6 = std_core_write_int(l1, l6, l7);
    l6 = std_core_write_string_at(l1, l6, 91u);
    t2 = std_core_finish_buffer(l1, l6);
    vader_host_std_abort_panic(t2);
    vader_unreachable("a no-return call returned");
    vader_gc_top = gc_frame.prev;
}

static void* vader_midir_successors_of(void* l0) {
    vader_box_t l1 = vader_box_null(), l2 = vader_box_null();
    int32_t l3, l4;
    void* t0 = NULL;
    vader_box_t* gc_roots[2] = { &l1, &l2 };
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct_vader_midir_BasicBlock_t*) l0)->f_terminator;
    l2 = l1;
    if (l1.tag == 1136u) {
        t0 = l2.payload.obj;
        vader_array_t* _a0_arr = vader_array_new(15u, 1u, 7u, 288u);
        ((int32_t*) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = (int32_t) ((vader_struct_vader_midir_TermBranch_t*) t0)->f_target;
        t0 = (void*) _a0_arr;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 1137u) {
        t0 = l2.payload.obj;
        l3 = ((vader_struct_vader_midir_TermCondBranch_t*) t0)->f_then_block;
        t0 = l2.payload.obj;
        l4 = ((vader_struct_vader_midir_TermCondBranch_t*) t0)->f_else_block;
        vader_array_t* _a1_arr = vader_array_new(15u, 2u, 7u, 288u);
        ((int32_t*) _a1_arr->buf->slots)[_a1_arr->offset + 1u] = (int32_t) l4;
        ((int32_t*) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = (int32_t) l3;
        t0 = (void*) _a1_arr;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 1138u) {
        vader_array_t* _a2_arr = vader_array_new(15u, 0u, 7u, 288u);
        t0 = (void*) _a2_arr;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l1.tag == 1139u)) {
        vader_unreachable("non-exhaustive match (T3013 should have caught this)");
    }
    vader_array_t* _a3_arr = vader_array_new(15u, 0u, 7u, 288u);
    t0 = (void*) _a3_arr;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_midir_synthesise_cfg_intrinsic_wrappers(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    void* l16 = NULL;
    void* l18 = NULL;
    void* l21 = NULL;
    void* l23 = NULL;
    void* l25 = NULL;
    void* l26 = NULL;
    void* l27 = NULL;
    void* l28 = NULL;
    int64_t l5, l6, l15, l17, l19, l20;
    vader_string_t l7 = 0;
    vader_string_t l11 = 0;
    vader_string_t l24 = 0;
    vader_string_t l29 = 0;
    int32_t l8, l9, l10, l22;
    void* t0 = NULL;
    int64_t t1;
    bool t2;
    vader_box_t t3 = vader_box_null();
    vader_string_t t4 = 0;
    vader_box_t* gc_roots[1] = { &t3 };
    void** gc_raw_roots[17] = {
        &l0, &l1, &l2, &l3, &l4, &l12, &l13, &l14, &l16, &l18, &l21, &l23, &l25, &l26, &l27, &l28,
        &t0,
    };
    vader_string_t* gc_atom_roots[5] = { &l7, &l11, &l24, &l29, &t4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 17u, gc_roots, gc_raw_roots, 0u, NULL, 5u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(14u, 0u, 0u, 285u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(12u, 0u, 12u, 283u);
    l3 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(15u, 0u, 7u, 288u);
    l4 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__string__bool_t* _a3_obj = (vader_struct_std_collections_MutableMap__string__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__bool_t));
    vader_obj_header_init(_a3_obj, 454u);
    _a3_obj->f_ekeys = l2;
    _a3_obj->f_evals = l3;
    _a3_obj->f_index = l4;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    l2 = (void*) _a3_obj;
    l3 = ((vader_struct_vader_midir_CFGProject_t*) l0)->f_vtable_entries;
    l5 = ((vader_array_t*) l3)->length;
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        t0 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l6);
        l7 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_lower_LoweredVtableEntry_t*) t0)->f_fn_symbol)->f_name;
        std_collections_MutableMap_std_core_IndexSet_set_at__string__bool(l2, l7, true);
        l6 = (l6 + INT64_C(1));
    }
    t1 = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_imports)->length;
    l8 = ((int32_t) (int64_t) t1);
    l9 = INT32_C(0);
    while ((l9 < l8)) {
        vader_array_t* _a5_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_imports);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l9)
        l3 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l9);
        l10 = l9;
        l9 = vader_chk_add(i32, l9, INT32_C(1));
        t2 = ((vader_struct_vader_bytecode_BcImport_t*) l3)->f_is_extern;
        if (t2) {
            continue;
        }
        l7 = ((vader_struct_vader_bytecode_BcImport_t*) l3)->f_mangled_name;
        t3 = std_collections_MutableMap_std_core_Index_at__string__bool(l2, l7);
        if (t3.tag == 0u) {
            continue;
        }
        l4 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_function_index_by_mangle;
        l11 = ((vader_struct_vader_bytecode_BcImport_t*) l3)->f_mangled_name;
        t3 = std_collections_MutableMap_std_core_Index_at__string__i32(l4, l11);
        if (t3.tag == 288u) {
            continue;
        }
        l12 = vader_bytecode_build_intrinsic_wrapper_body(l3, l10);
        vader_array_t* _a6_arr = vader_array_new(228u, 0u, 13u, 1585u);
        l13 = (void*) _a6_arr;
        l5 = ((vader_array_t*) l12)->length;
        vader_array_t* _a7_arr = vader_array_repeat((vader_array_t*) l13, (int64_t) l5);
        l14 = (void*) _a7_arr;
        l6 = INT64_C(0);
        l15 = ((vader_array_t*) l12)->length;
        while ((l6 < l15)) {
            vader_array_push((vader_array_t*) l14, vader_box_obj(0u, NULL));
            l6 = (l6 + INT64_C(1));
        }
        vader_array_t* _a8_arr = vader_array_new(15u, 0u, 7u, 288u);
        l16 = (void*) _a8_arr;
        l17 = ((vader_array_t*) l12)->length;
        vader_array_t* _a9_arr = vader_array_repeat((vader_array_t*) l16, (int64_t) l17);
        l18 = (void*) _a9_arr;
        l19 = INT64_C(0);
        l20 = ((vader_array_t*) l12)->length;
        vader_array_t* _pc138_hdr = (vader_array_t*) l18;
        size_t _pc138_len = _pc138_hdr->length;
        size_t _pc138_cap = (_pc138_hdr->offset == 0 && !vader_array_is_borrowed(_pc138_hdr) && _pc138_hdr->length >= _pc138_hdr->buf->length) ? _pc138_hdr->capacity : (size_t) 0;
        void* _pc138_slots = _pc138_hdr->buf->slots;
        for (;;) {
            if ((l19 < l20)) {
                if (VADER_LIKELY(_pc138_len < _pc138_cap)) {
                    ((int32_t*) _pc138_slots)[_pc138_len] = (int32_t) (INT32_C(-1));
                    _pc138_len += 1;
                } else {
                    _pc138_hdr->length = _pc138_len;
                    if (_pc138_hdr->buf->length < _pc138_len) {
                        _pc138_hdr->buf->length = _pc138_len;
                    }
                    vader_array_push_i32((vader_array_t*) l18, INT32_C(-1));
                    _pc138_hdr = (vader_array_t*) l18;
                    _pc138_len = _pc138_hdr->length;
                    _pc138_cap = (_pc138_hdr->offset == 0 && !vader_array_is_borrowed(_pc138_hdr) && _pc138_hdr->length >= _pc138_hdr->buf->length) ? _pc138_hdr->capacity : (size_t) 0;
                    _pc138_slots = _pc138_hdr->buf->slots;
                }
                l19 = (l19 + INT64_C(1));
                continue;
            }
            _pc138_hdr->length = _pc138_len;
            if (_pc138_hdr->buf->length < _pc138_len) {
                _pc138_hdr->buf->length = _pc138_len;
            }
            break;
        }
        vader_array_t* _a10_arr = vader_array_new(54u, 0u, 13u, 645u);
        l21 = (void*) _a10_arr;
        t1 = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_functions)->length;
        l22 = ((int32_t) (int64_t) t1);
        l23 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_functions;
        t4 = ((vader_struct_vader_bytecode_BcImport_t*) l3)->f_mangled_name;
        l24 = concat_2(t4, 907u);
        l25 = ((vader_struct_vader_bytecode_BcImport_t*) l3)->f_signature;
        vader_array_t* _a11_arr = vader_array_new(15u, 0u, 7u, 288u);
        l26 = (void*) _a11_arr;
        vader_struct_vader_bytecode_BcFunction_t* _a12_obj = (vader_struct_vader_bytecode_BcFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcFunction_t));
        vader_obj_header_init(_a12_obj, 642u);
        _a12_obj->f_name = l24;
        _a12_obj->f_is_main = false;
        _a12_obj->f_signature = l25;
        _a12_obj->f_locals = l21;
        _a12_obj->f_body = l12;
        _a12_obj->f_debug = l14;
        _a12_obj->f_jump_table = l18;
        _a12_obj->f_source_pc = l26;
        l27 = (void*) _a12_obj;
        vader_array_push((vader_array_t*) l23, vader_ref_box(l27));
        l28 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_function_index_by_mangle;
        l29 = ((vader_struct_vader_bytecode_BcImport_t*) l3)->f_mangled_name;
        std_collections_MutableMap_std_core_IndexSet_set_at__string__i32(l28, l29, l22);
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_midir_term_return_single(void* l0) {
    int64_t t0;
    int32_t t1;
    t0 = ((vader_array_t*) ((vader_struct_vader_midir_TermReturn_t*) l0)->f_values)->length;
    if (!(t0 != INT64_C(1))) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_midir_TermReturn_t*) l0)->f_values);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
        t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) INT32_C(0)];
        return vader_box_i32(288u, t1);
    }
    return vader_box_obj(0u, NULL);
}

static void vader_midir_terminate(void* l0, vader_box_t l1) {
    void* l2;
    int64_t l3;
    vader_box_t l4;
    if (((vader_struct_vader_midir_FnCtx_t*) l0)->f_current.tag == 0u) {
        return;
    }
    l2 = ((vader_struct_vader_midir_FnCtx_t*) l0)->f_blocks;
    l3 = ((int64_t) ((vader_struct_vader_midir_FnCtx_t*) l0)->f_current.payload.i);
    vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
    l2 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
    if (((vader_struct_vader_midir_MutableBlock_t*) l2)->f_terminator.tag == 0u) {
        ((vader_struct_vader_midir_MutableBlock_t*) l2)->f_terminator = l1;
        VADER_WRITE_BARRIER((vader_struct_vader_midir_MutableBlock_t*) l2);
        l4 = vader_box_obj(0u, NULL);
        ((vader_struct_vader_midir_FnCtx_t*) l0)->f_current = l4;
        VADER_WRITE_BARRIER((vader_struct_vader_midir_FnCtx_t*) l0);
        return;
    }
    l4 = vader_box_obj(0u, NULL);
    ((vader_struct_vader_midir_FnCtx_t*) l0)->f_current = l4;
    VADER_WRITE_BARRIER((vader_struct_vader_midir_FnCtx_t*) l0);
    return;
}

static bool vader_midir_tests_its_exit(void* l0, void* l1, int32_t l2) {
    void* l3;
    void* l5;
    vader_box_t l4;
    int32_t l6;
    bool l7;
    void* t0;
    bool t1;
    l4 = std_collections_MutableMap_std_core_Index_at__i32__Any(l1, l2);
    if (l4.tag == 0u) {
        return false;
    }
    l3 = l4.payload.obj;
    l5 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_blocks;
    l6 = l2;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l6)
    t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l6);
    l4 = ((vader_struct_vader_midir_BasicBlock_t*) t0)->f_terminator;
    if (l4.tag == 1137u) {
        t0 = l4.payload.obj;
        l6 = ((vader_struct_vader_midir_TermCondBranch_t*) t0)->f_then_block;
        t1 = std_collections_MutableSet_std_core_Contains_contains__i32(l3, l6);
        if (!(t1)) {
            l7 = true;
        } else {
            t0 = l4.payload.obj;
            l6 = ((vader_struct_vader_midir_TermCondBranch_t*) t0)->f_else_block;
            t1 = std_collections_MutableSet_std_core_Contains_contains__i32(l3, l6);
            l7 = !(t1);
        }
        return l7;
    }
    return false;
}

static bool vader_midir_try_fuse_local_field(void* l0, int32_t l1, int32_t l2) {
    int64_t l3, l5;
    void* l4 = NULL;
    void* l8 = NULL;
    vader_box_t l6 = vader_box_null();
    int32_t l7;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l6 };
    void** gc_raw_roots[4] = { &l0, &l4, &l8, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_slot)->f_body)->length;
    if (l3 == INT64_C(0)) {
        { vader_gc_top = gc_frame.prev; return false; }
    }
    l4 = ((vader_struct_vader_bytecode_BcFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_slot)->f_body;
    l5 = vader_chk_sub(i64, l3, INT64_C(1));
    vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
    l6 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
    if (!(l6.tag == 758u)) {
        { vader_gc_top = gc_frame.prev; return false; }
    }
    t0 = l6.payload.obj;
    l7 = ((vader_struct_vader_bytecode_LocalGet_t*) t0)->f_slot;
    l4 = ((vader_struct_vader_bytecode_BcFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_slot)->f_body;
    l3 = vader_chk_sub(i64, l3, INT64_C(1));
    vader_struct_vader_bytecode_LocalField_t* _a1_obj = (vader_struct_vader_bytecode_LocalField_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_LocalField_t));
    vader_obj_header_init(_a1_obj, 757u);
    _a1_obj->f_slot = l7;
    _a1_obj->f_type_id = l1;
    _a1_obj->f_field_index = l2;
    l8 = (void*) _a1_obj;
    vader_array_t* _a2_slotarr = ((vader_array_t*) l4);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
    vader_array_ref_store(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l3, l8);
    VADER_WRITE_BARRIER(_a2_slotarr->buf);
    { vader_gc_top = gc_frame.prev; return true; }
}

static vader_box_t vader_midir_type_at(void* l0, int64_t l1) {
    int64_t l2;
    vader_box_t t0;
    l2 = ((vader_array_t*) l0)->length;
    if (!((l1 >= l2))) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
        t0 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l1);
        return t0;
    }
    return vader_box_obj(0u, NULL);
}

static bool vader_midir_unary_leaves_width(uint8_t l0, uint8_t l1) {
    bool l2, l3;
    bool t0;
    t0 = vader_bytecode_is_narrow_valtype(l1);
    if (t0) {
        if (l0 == INT32_C(2)) {
            l2 = vader_bytecode_is_unsigned_val(l1);
        } else {
            if (l0 == INT32_C(0)) {
                l3 = true;
            } else {
                l3 = l0 == INT32_C(1);
            }
            if (!(l3)) {
                vader_unreachable("non-exhaustive match (T3013 should have caught this)");
            }
            l2 = false;
        }
        return l2;
    }
    return false;
}

static vader_string_t vader_midir_vtable_key(vader_string_t l0, vader_string_t l1) {
    vader_string_t t0 = 0;
    vader_string_t* gc_atom_roots[3] = { &l0, &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 3u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = concat_3(l0, 334u, l1);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_midir_walk_rpo(void* l0, int32_t l1, void* l2, void* l3) {
    int32_t l4;
    void* l5 = NULL;
    int64_t l6, l7;
    vader_box_t t0 = vader_box_null();
    bool t1;
    void* t2 = NULL;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[5] = { &l0, &l2, &l3, &l5, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l4 = l1;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
    t0 = vader_box_bool(283u, ((uint8_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l4]);
    t1 = t0.payload.b;
    if (t1) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l4 = l1;
    vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
    ((uint8_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4] = (uint8_t) true;
    l5 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_blocks;
    l4 = l1;
    vader_array_t* _a2_slotarr = ((vader_array_t*) l5);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
    t2 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
    l5 = vader_midir_successors_of(t2);
    l6 = ((vader_array_t*) l5)->length;
    l7 = INT64_C(0);
    while ((l7 < l6)) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        l4 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l7];
        vader_midir_walk_rpo(l0, l4, l2, l3);
        l7 = (l7 + INT64_C(1));
    }
    vader_array_push_i32((vader_array_t*) l3, l1);
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_midir_with_dst(vader_box_t l0, int32_t l1) {
    vader_box_t l2 = vader_box_null(), l5 = vader_box_null(), l13 = vader_box_null();
    void* l3 = NULL;
    void* l4 = NULL;
    void* l12 = NULL;
    int32_t l6, l8, l11;
    uint8_t l7;
    vader_string_t l9 = 0;
    bool l10;
    void* t0 = NULL;
    vader_box_t* gc_roots[4] = { &l0, &l2, &l5, &l13 };
    void** gc_raw_roots[4] = { &l3, &l4, &l12, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l9 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l0.tag == 1106u) {
        l3 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrConst_t*) l3)->f_span;
        l2 = ((vader_struct_vader_midir_InstrConst_t*) l3)->f_value;
        l5 = ((vader_struct_vader_midir_InstrConst_t*) l3)->f_type;
        vader_struct_vader_midir_InstrConst_t* _a0_obj = (vader_struct_vader_midir_InstrConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrConst_t));
        vader_obj_header_init(_a0_obj, 1106u);
        _a0_obj->f_span = l4;
        _a0_obj->f_dst = l1;
        _a0_obj->f_value = l2;
        _a0_obj->f_type = l5;
        t0 = (void*) _a0_obj;
        l2 = vader_ref_box(t0);
        { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1118u) {
        l3 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrMove_t*) l3)->f_span;
        l6 = ((vader_struct_vader_midir_InstrMove_t*) l3)->f_src;
        vader_struct_vader_midir_InstrMove_t* _a1_obj = (vader_struct_vader_midir_InstrMove_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrMove_t));
        vader_obj_header_init(_a1_obj, 1118u);
        _a1_obj->f_span = l4;
        _a1_obj->f_dst = l1;
        _a1_obj->f_src = l6;
        t0 = (void*) _a1_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1099u) {
        l3 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrBinOp_t*) l3)->f_span;
        l7 = ((vader_struct_vader_midir_InstrBinOp_t*) l3)->f_op;
        l6 = ((vader_struct_vader_midir_InstrBinOp_t*) l3)->f_lhs;
        l8 = ((vader_struct_vader_midir_InstrBinOp_t*) l3)->f_rhs;
        l5 = ((vader_struct_vader_midir_InstrBinOp_t*) l3)->f_type;
        vader_struct_vader_midir_InstrBinOp_t* _a2_obj = (vader_struct_vader_midir_InstrBinOp_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrBinOp_t));
        vader_obj_header_init(_a2_obj, 1099u);
        _a2_obj->f_span = l4;
        _a2_obj->f_dst = l1;
        _a2_obj->f_op = l7;
        _a2_obj->f_lhs = l6;
        _a2_obj->f_rhs = l8;
        _a2_obj->f_type = l5;
        t0 = (void*) _a2_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1122u) {
        l3 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrUnOp_t*) l3)->f_span;
        l7 = ((vader_struct_vader_midir_InstrUnOp_t*) l3)->f_op;
        l6 = ((vader_struct_vader_midir_InstrUnOp_t*) l3)->f_operand;
        l5 = ((vader_struct_vader_midir_InstrUnOp_t*) l3)->f_type;
        vader_struct_vader_midir_InstrUnOp_t* _a3_obj = (vader_struct_vader_midir_InstrUnOp_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrUnOp_t));
        vader_obj_header_init(_a3_obj, 1122u);
        _a3_obj->f_span = l4;
        _a3_obj->f_dst = l1;
        _a3_obj->f_op = l7;
        _a3_obj->f_operand = l6;
        _a3_obj->f_type = l5;
        t0 = (void*) _a3_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1110u) {
        l3 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrFieldGet_t*) l3)->f_span;
        l6 = ((vader_struct_vader_midir_InstrFieldGet_t*) l3)->f_target;
        l5 = ((vader_struct_vader_midir_InstrFieldGet_t*) l3)->f_type;
        l9 = ((vader_struct_vader_midir_InstrFieldGet_t*) l3)->f_field;
        vader_struct_vader_midir_InstrFieldGet_t* _a4_obj = (vader_struct_vader_midir_InstrFieldGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrFieldGet_t));
        vader_obj_header_init(_a4_obj, 1110u);
        _a4_obj->f_span = l4;
        _a4_obj->f_dst = l1;
        _a4_obj->f_target = l6;
        _a4_obj->f_type = l5;
        _a4_obj->f_field = l9;
        t0 = (void*) _a4_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1123u) {
        l3 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrUnionFieldGet_t*) l3)->f_span;
        l6 = ((vader_struct_vader_midir_InstrUnionFieldGet_t*) l3)->f_target;
        l5 = ((vader_struct_vader_midir_InstrUnionFieldGet_t*) l3)->f_type;
        l9 = ((vader_struct_vader_midir_InstrUnionFieldGet_t*) l3)->f_field;
        vader_struct_vader_midir_InstrUnionFieldGet_t* _a5_obj = (vader_struct_vader_midir_InstrUnionFieldGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrUnionFieldGet_t));
        vader_obj_header_init(_a5_obj, 1123u);
        _a5_obj->f_span = l4;
        _a5_obj->f_dst = l1;
        _a5_obj->f_target = l6;
        _a5_obj->f_type = l5;
        _a5_obj->f_field = l9;
        t0 = (void*) _a5_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1093u) {
        l3 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrArrayGet_t*) l3)->f_span;
        l6 = ((vader_struct_vader_midir_InstrArrayGet_t*) l3)->f_target;
        l5 = ((vader_struct_vader_midir_InstrArrayGet_t*) l3)->f_type;
        l8 = ((vader_struct_vader_midir_InstrArrayGet_t*) l3)->f_index;
        l10 = ((vader_struct_vader_midir_InstrArrayGet_t*) l3)->f_bounds_safe;
        vader_struct_vader_midir_InstrArrayGet_t* _a6_obj = (vader_struct_vader_midir_InstrArrayGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrArrayGet_t));
        vader_obj_header_init(_a6_obj, 1093u);
        _a6_obj->f_span = l4;
        _a6_obj->f_dst = l1;
        _a6_obj->f_target = l6;
        _a6_obj->f_type = l5;
        _a6_obj->f_index = l8;
        _a6_obj->f_bounds_safe = l10;
        t0 = (void*) _a6_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1094u) {
        l3 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrArrayLen_t*) l3)->f_span;
        l6 = ((vader_struct_vader_midir_InstrArrayLen_t*) l3)->f_target;
        vader_struct_vader_midir_InstrArrayLen_t* _a7_obj = (vader_struct_vader_midir_InstrArrayLen_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrArrayLen_t));
        vader_obj_header_init(_a7_obj, 1094u);
        _a7_obj->f_span = l4;
        _a7_obj->f_dst = l1;
        _a7_obj->f_target = l6;
        t0 = (void*) _a7_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1098u) {
        l3 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrArraySlice_t*) l3)->f_span;
        l5 = ((vader_struct_vader_midir_InstrArraySlice_t*) l3)->f_type;
        l6 = ((vader_struct_vader_midir_InstrArraySlice_t*) l3)->f_target;
        l8 = ((vader_struct_vader_midir_InstrArraySlice_t*) l3)->f_lo;
        l11 = ((vader_struct_vader_midir_InstrArraySlice_t*) l3)->f_hi;
        vader_struct_vader_midir_InstrArraySlice_t* _a8_obj = (vader_struct_vader_midir_InstrArraySlice_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrArraySlice_t));
        vader_obj_header_init(_a8_obj, 1098u);
        _a8_obj->f_span = l4;
        _a8_obj->f_dst = l1;
        _a8_obj->f_type = l5;
        _a8_obj->f_target = l6;
        _a8_obj->f_lo = l8;
        _a8_obj->f_hi = l11;
        t0 = (void*) _a8_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1119u) {
        l3 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrStructNew_t*) l3)->f_span;
        l5 = ((vader_struct_vader_midir_InstrStructNew_t*) l3)->f_type;
        l12 = ((vader_struct_vader_midir_InstrStructNew_t*) l3)->f_fields;
        l10 = ((vader_struct_vader_midir_InstrStructNew_t*) l3)->f_stack;
        vader_struct_vader_midir_InstrStructNew_t* _a9_obj = (vader_struct_vader_midir_InstrStructNew_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrStructNew_t));
        vader_obj_header_init(_a9_obj, 1119u);
        _a9_obj->f_span = l4;
        _a9_obj->f_dst = l1;
        _a9_obj->f_type = l5;
        _a9_obj->f_fields = l12;
        _a9_obj->f_stack = l10;
        t0 = (void*) _a9_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1095u) {
        l3 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrArrayNew_t*) l3)->f_span;
        l5 = ((vader_struct_vader_midir_InstrArrayNew_t*) l3)->f_type;
        l6 = ((vader_struct_vader_midir_InstrArrayNew_t*) l3)->f_length;
        l12 = ((vader_struct_vader_midir_InstrArrayNew_t*) l3)->f_elements;
        l10 = ((vader_struct_vader_midir_InstrArrayNew_t*) l3)->f_stack;
        vader_struct_vader_midir_InstrArrayNew_t* _a10_obj = (vader_struct_vader_midir_InstrArrayNew_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrArrayNew_t));
        vader_obj_header_init(_a10_obj, 1095u);
        _a10_obj->f_span = l4;
        _a10_obj->f_dst = l1;
        _a10_obj->f_type = l5;
        _a10_obj->f_length = l6;
        _a10_obj->f_elements = l12;
        _a10_obj->f_stack = l10;
        t0 = (void*) _a10_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1107u) {
        l3 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrDataConst_t*) l3)->f_span;
        l5 = ((vader_struct_vader_midir_InstrDataConst_t*) l3)->f_type;
        l6 = ((vader_struct_vader_midir_InstrDataConst_t*) l3)->f_pool_index;
        vader_struct_vader_midir_InstrDataConst_t* _a11_obj = (vader_struct_vader_midir_InstrDataConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrDataConst_t));
        vader_obj_header_init(_a11_obj, 1107u);
        _a11_obj->f_span = l4;
        _a11_obj->f_dst = l1;
        _a11_obj->f_type = l5;
        _a11_obj->f_pool_index = l6;
        t0 = (void*) _a11_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1114u) {
        l3 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrGlobalGet_t*) l3)->f_span;
        l5 = ((vader_struct_vader_midir_InstrGlobalGet_t*) l3)->f_type;
        l6 = ((vader_struct_vader_midir_InstrGlobalGet_t*) l3)->f_slot;
        vader_struct_vader_midir_InstrGlobalGet_t* _a12_obj = (vader_struct_vader_midir_InstrGlobalGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrGlobalGet_t));
        vader_obj_header_init(_a12_obj, 1114u);
        _a12_obj->f_span = l4;
        _a12_obj->f_dst = l1;
        _a12_obj->f_type = l5;
        _a12_obj->f_slot = l6;
        t0 = (void*) _a12_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1120u) {
        l3 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrTypeCheck_t*) l3)->f_span;
        l6 = ((vader_struct_vader_midir_InstrTypeCheck_t*) l3)->f_value;
        l5 = ((vader_struct_vader_midir_InstrTypeCheck_t*) l3)->f_check_type;
        vader_struct_vader_midir_InstrTypeCheck_t* _a13_obj = (vader_struct_vader_midir_InstrTypeCheck_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrTypeCheck_t));
        vader_obj_header_init(_a13_obj, 1120u);
        _a13_obj->f_span = l4;
        _a13_obj->f_dst = l1;
        _a13_obj->f_value = l6;
        _a13_obj->f_check_type = l5;
        t0 = (void*) _a13_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1121u) {
        l3 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrTypeConst_t*) l3)->f_span;
        l5 = ((vader_struct_vader_midir_InstrTypeConst_t*) l3)->f_type;
        l13 = ((vader_struct_vader_midir_InstrTypeConst_t*) l3)->f_value_type;
        vader_struct_vader_midir_InstrTypeConst_t* _a14_obj = (vader_struct_vader_midir_InstrTypeConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrTypeConst_t));
        vader_obj_header_init(_a14_obj, 1121u);
        _a14_obj->f_span = l4;
        _a14_obj->f_dst = l1;
        _a14_obj->f_type = l5;
        _a14_obj->f_value_type = l13;
        t0 = (void*) _a14_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1102u) {
        l3 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrCast_t*) l3)->f_span;
        l6 = ((vader_struct_vader_midir_InstrCast_t*) l3)->f_value;
        l5 = ((vader_struct_vader_midir_InstrCast_t*) l3)->f_type;
        vader_struct_vader_midir_InstrCast_t* _a15_obj = (vader_struct_vader_midir_InstrCast_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrCast_t));
        vader_obj_header_init(_a15_obj, 1102u);
        _a15_obj->f_span = l4;
        _a15_obj->f_dst = l1;
        _a15_obj->f_value = l6;
        _a15_obj->f_type = l5;
        t0 = (void*) _a15_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1104u) {
        l3 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrCellNew_t*) l3)->f_span;
        l6 = ((vader_struct_vader_midir_InstrCellNew_t*) l3)->f_value;
        l5 = ((vader_struct_vader_midir_InstrCellNew_t*) l3)->f_value_type;
        vader_struct_vader_midir_InstrCellNew_t* _a16_obj = (vader_struct_vader_midir_InstrCellNew_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrCellNew_t));
        vader_obj_header_init(_a16_obj, 1104u);
        _a16_obj->f_span = l4;
        _a16_obj->f_dst = l1;
        _a16_obj->f_value = l6;
        _a16_obj->f_value_type = l5;
        t0 = (void*) _a16_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1103u) {
        l3 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrCellGet_t*) l3)->f_span;
        l6 = ((vader_struct_vader_midir_InstrCellGet_t*) l3)->f_cell;
        l5 = ((vader_struct_vader_midir_InstrCellGet_t*) l3)->f_value_type;
        vader_struct_vader_midir_InstrCellGet_t* _a17_obj = (vader_struct_vader_midir_InstrCellGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrCellGet_t));
        vader_obj_header_init(_a17_obj, 1103u);
        _a17_obj->f_span = l4;
        _a17_obj->f_dst = l1;
        _a17_obj->f_cell = l6;
        _a17_obj->f_value_type = l5;
        t0 = (void*) _a17_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1117u) {
        l3 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrMakeClosure_t*) l3)->f_span;
        l12 = ((vader_struct_vader_midir_InstrMakeClosure_t*) l3)->f_fn_symbol;
        l6 = ((vader_struct_vader_midir_InstrMakeClosure_t*) l3)->f_env;
        l5 = ((vader_struct_vader_midir_InstrMakeClosure_t*) l3)->f_env_type;
        l13 = ((vader_struct_vader_midir_InstrMakeClosure_t*) l3)->f_type;
        vader_struct_vader_midir_InstrMakeClosure_t* _a18_obj = (vader_struct_vader_midir_InstrMakeClosure_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrMakeClosure_t));
        vader_obj_header_init(_a18_obj, 1117u);
        _a18_obj->f_span = l4;
        _a18_obj->f_dst = l1;
        _a18_obj->f_fn_symbol = l12;
        _a18_obj->f_env = l6;
        _a18_obj->f_env_type = l5;
        _a18_obj->f_type = l13;
        t0 = (void*) _a18_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1113u) {
        l3 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrFnRef_t*) l3)->f_span;
        l12 = ((vader_struct_vader_midir_InstrFnRef_t*) l3)->f_fn_symbol;
        l5 = ((vader_struct_vader_midir_InstrFnRef_t*) l3)->f_type;
        vader_struct_vader_midir_InstrFnRef_t* _a19_obj = (vader_struct_vader_midir_InstrFnRef_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrFnRef_t));
        vader_obj_header_init(_a19_obj, 1113u);
        _a19_obj->f_span = l4;
        _a19_obj->f_dst = l1;
        _a19_obj->f_fn_symbol = l12;
        _a19_obj->f_type = l5;
        t0 = (void*) _a19_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1112u) {
        l3 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrFnAddr_t*) l3)->f_span;
        l12 = ((vader_struct_vader_midir_InstrFnAddr_t*) l3)->f_fn_symbol;
        l5 = ((vader_struct_vader_midir_InstrFnAddr_t*) l3)->f_type;
        vader_struct_vader_midir_InstrFnAddr_t* _a20_obj = (vader_struct_vader_midir_InstrFnAddr_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrFnAddr_t));
        vader_obj_header_init(_a20_obj, 1112u);
        _a20_obj->f_span = l4;
        _a20_obj->f_dst = l1;
        _a20_obj->f_fn_symbol = l12;
        _a20_obj->f_type = l5;
        t0 = (void*) _a20_obj;
        l2 = vader_ref_box(t0);
    } else {
        if (!((l0.tag == 1096u || l0.tag == 1097u || l0.tag == 1100u || l0.tag == 1101u || l0.tag == 1105u || l0.tag == 1108u || l0.tag == 1109u || l0.tag == 1111u || l0.tag == 1115u || l0.tag == 1116u || l0.tag == 1124u || l0.tag == 1125u))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l2 = l0;
    }
    { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_midir_with_param_decorators(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null();
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l8 = NULL;
    void* l11 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    void* l15 = NULL;
    void* l16 = NULL;
    int64_t l6, l7;
    bool l9, l10;
    void* t0 = NULL;
    bool t1;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[13] = {
        &l0, &l1, &l3, &l4, &l5, &l8, &l11, &l12, &l13, &l14, &l15, &l16, &t0,
    };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 13u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_comptime_MonoEntry_t*) l1)->f_decl;
    if (!(l2.tag == 560u)) {
        { void* __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a0_arr = vader_array_new(12u, 0u, 12u, 283u);
    l3 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(12u, 0u, 12u, 283u);
    l4 = (void*) _a1_arr;
    t0 = l2.payload.obj;
    l5 = ((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_params;
    l6 = ((vader_array_t*) l5)->length;
    l7 = INT64_C(0);
    while ((l7 < l6)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        l8 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l7);
        l9 = toolchain_ast_decorators_have(((vader_struct_toolchain_ast_FnParam_t*) l8)->f_decorators, 1529u);
        vader_array_push_bool((vader_array_t*) l3, l9);
        l10 = toolchain_ast_decorators_have(((vader_struct_toolchain_ast_FnParam_t*) l8)->f_decorators, 1528u);
        vader_array_push_bool((vader_array_t*) l4, l10);
        l7 = (l7 + INT64_C(1));
    }
    l8 = l0;
    l11 = ((vader_struct_vader_bytecode_BcSignature_t*) l8)->f_params;
    l12 = ((vader_struct_vader_bytecode_BcSignature_t*) l8)->f_results;
    l13 = ((vader_struct_vader_bytecode_BcSignature_t*) l8)->f_param_types;
    l14 = ((vader_struct_vader_bytecode_BcSignature_t*) l8)->f_result_types;
    l15 = ((vader_struct_vader_bytecode_BcSignature_t*) l8)->f_param_names;
    l16 = ((vader_struct_vader_bytecode_BcSignature_t*) l8)->f_param_c_out;
    l8 = ((vader_struct_vader_bytecode_BcSignature_t*) l8)->f_param_by_address;
    vader_struct_vader_bytecode_BcSignature_t* _a3_obj = (vader_struct_vader_bytecode_BcSignature_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcSignature_t));
    vader_obj_header_init(_a3_obj, 650u);
    _a3_obj->f_params = l11;
    _a3_obj->f_results = l12;
    _a3_obj->f_param_types = l13;
    _a3_obj->f_result_types = l14;
    _a3_obj->f_param_names = l15;
    _a3_obj->f_param_c_out = l16;
    _a3_obj->f_param_by_address = l8;
    l5 = (void*) _a3_obj;
    t1 = std_core____Contains_contains__bool(l3, true);
    if (t1) {
        ((vader_struct_vader_bytecode_BcSignature_t*) l5)->f_param_by_address = l3;
        VADER_WRITE_BARRIER((vader_struct_vader_bytecode_BcSignature_t*) l5);
    }
    t1 = std_core____Contains_contains__bool(l4, true);
    if (t1) {
        ((vader_struct_vader_bytecode_BcSignature_t*) l5)->f_param_c_out = l4;
        VADER_WRITE_BARRIER((vader_struct_vader_bytecode_BcSignature_t*) l5);
        { void* __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { void* __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_midir_with_peephole_out(void* l0, void* l1) {
    void* l2 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    vader_string_t l3 = 0;
    bool l4;
    void* t0 = NULL;
    void** gc_raw_roots[9] = { &l0, &l1, &l2, &l5, &l6, &l7, &l8, &l9, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 9u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = l0;
    l3 = ((vader_struct_vader_bytecode_BcFunction_t*) l2)->f_name;
    l4 = ((vader_struct_vader_bytecode_BcFunction_t*) l2)->f_is_main;
    l5 = ((vader_struct_vader_bytecode_BcFunction_t*) l2)->f_signature;
    l6 = ((vader_struct_vader_bytecode_BcFunction_t*) l2)->f_locals;
    l7 = ((vader_struct_vader_bytecode_BcPeepholeOut_t*) l1)->f_body;
    l8 = ((vader_struct_vader_bytecode_BcPeepholeOut_t*) l1)->f_debug;
    l9 = ((vader_struct_vader_bytecode_BcPeepholeOut_t*) l1)->f_jump_table;
    l2 = ((vader_struct_vader_bytecode_BcFunction_t*) l2)->f_source_pc;
    vader_struct_vader_bytecode_BcFunction_t* _a0_obj = (vader_struct_vader_bytecode_BcFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcFunction_t));
    vader_obj_header_init(_a0_obj, 642u);
    _a0_obj->f_name = l3;
    _a0_obj->f_is_main = l4;
    _a0_obj->f_signature = l5;
    _a0_obj->f_locals = l6;
    _a0_obj->f_body = l7;
    _a0_obj->f_debug = l8;
    _a0_obj->f_jump_table = l9;
    _a0_obj->f_source_pc = l2;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}
