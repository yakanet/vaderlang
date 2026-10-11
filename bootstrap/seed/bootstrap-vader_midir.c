#include "bootstrap.split.h"

static bool vader_midir_BlockId_Equals_equals(int32_t l0, int32_t l1);
static void* vader_midir_annotate_function(void* l0);
static void vader_midir_append_alias(void* l0, int32_t l1, int32_t l2);
static vader_string_t vader_midir_array_element_name(vader_box_t l0);
static uint8_t vader_midir_array_element_val_type(vader_box_t l0);
static uint64_t vader_midir_bc_value_bits(vader_box_t l0, vader_string_t l1);
static bool vader_midir_binary_leaves_width(uint8_t l0, uint8_t l1);
static void* vader_midir_branch_on_cond(void* l0, vader_box_t l1, int32_t l2, int32_t l3, bool l4);
static vader_box_t vader_midir_build_args(void* l0, void* l1);
static vader_box_t vader_midir_build_array_len(void* l0, void* l1);
static vader_box_t vader_midir_build_array_lit(void* l0, void* l1);
static vader_box_t vader_midir_build_array_push(void* l0, void* l1);
static vader_box_t vader_midir_build_array_slice(void* l0, void* l1);
static void vader_midir_build_assign(void* l0, void* l1);
static void vader_midir_build_back_edge(void* l0, void* l1, void* l2);
static vader_box_t vader_midir_build_binary(void* l0, void* l1);
static vader_box_t vader_midir_build_block_body(void* l0, void* l1);
static void vader_midir_build_block_into(void* l0, void* l1, int32_t l2);
static vader_box_t vader_midir_build_call(void* l0, void* l1);
static vader_box_t vader_midir_build_cast(void* l0, void* l1);
static vader_box_t vader_midir_build_cell_get(void* l0, void* l1);
static vader_box_t vader_midir_build_cell_new(void* l0, void* l1);
static void* vader_midir_build_cfg_signature(void* l0, vader_box_t l1, void* l2, void* l3);
static vader_box_t vader_midir_build_data_const(void* l0, void* l1);
static vader_box_t vader_midir_build_expr(void* l0, vader_box_t l1);
static void vader_midir_build_expr_into(void* l0, vader_box_t l1, int32_t l2);
static vader_box_t vader_midir_build_extern_args(void* l0, void* l1, void* l2, vader_string_t l3);
static vader_box_t vader_midir_build_field_access(void* l0, void* l1);
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
static vader_box_t vader_midir_build_string_slice(void* l0, void* l1);
static vader_box_t vader_midir_build_struct_lit(void* l0, void* l1);
static vader_box_t vader_midir_build_type_check(void* l0, void* l1);
static vader_box_t vader_midir_build_type_const(void* l0, void* l1);
static vader_box_t vader_midir_build_unary(void* l0, void* l1);
static vader_box_t vader_midir_build_unreachable_type(void* l0, vader_box_t l1, void* l2, vader_string_t l3);
static vader_box_t vader_midir_build_virtual_call(void* l0, void* l1);
static void* vader_midir_build_vtables_from_entries(void* l0, void* l1);
static vader_string_t vader_midir_c_header_of(void* l0);
static vader_string_t vader_midir_c_struct_of(void* l0);
static int32_t vader_midir_c_variadic_fixed_of(void* l0);
static vader_box_t vader_midir_call_single_dst(void* l0);
static bool vader_midir_can_pass_through_stack(vader_box_t l0, vader_box_t l1, void* l2);
static bool vader_midir_can_pass_through_terminator(vader_box_t l0, vader_box_t l1, void* l2);
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
static void* vader_midir_compute_carried_across_loop_headers(void* l0, void* l1);
static void* vader_midir_compute_dominators(void* l0, void* l1);
static void* vader_midir_compute_escaping(void* l0, void* l1);
static void* vader_midir_compute_liveness(void* l0);
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
static void vader_midir_emit_instructions(void* l0, int32_t l1, size_t l2, size_t l3);
static void vader_midir_emit_loop(void* l0, void* l1, int32_t l2, int32_t l3);
static void vader_midir_emit_narrowing(void* l0, uint8_t l1, void* l2);
static void vader_midir_emit_operands_into(void* l0, int64_t l1, void* l2, void* l3, void* l4);
static void vader_midir_emit_result(void* l0, int64_t l1, int32_t l2, void* l3);
static void vader_midir_emit_result_if_any(void* l0, int64_t l1, vader_box_t l2, void* l3);
static void vader_midir_emit_retag_into(void* l0, int32_t l1, bool l2, void* l3);
static void vader_midir_emit_return(void* l0, int32_t l1, void* l2);
static void vader_midir_emit_return_retag(void* l0, int32_t l1, size_t l2, void* l3);
static void vader_midir_emit_set(void* l0, int32_t l1, void* l2);
static void vader_midir_emit_subtree(void* l0, void* l1, int32_t l2, int32_t l3);
static void vader_midir_emit_terminator(void* l0, void* l1, int32_t l2, int32_t l3, int32_t l4);
static bool vader_midir_emitted_beneath(void* l0, void* l1, void* l2, void* l3, int32_t l4);
static vader_box_t vader_midir_end_after_no_return(void* l0, void* l1, vader_box_t l2);
static bool vader_midir_ends_function(vader_box_t l0);
static bool vader_midir_entered_by_test(void* l0, void* l1, int32_t l2);
static vader_string_t vader_midir_extern_library_name(void* l0);
static vader_string_t vader_midir_extern_symbol_name(void* l0);
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
static bool vader_midir_goes_on_or_out(void* l0, void* l1, void* l2, int32_t l3);
static bool vader_midir_has_receiver(void* l0, int32_t l1);
static bool vader_midir_holds_all(void* l0, void* l1);
static void* vader_midir_import_call_target(void* l0, int32_t l1);
static bool vader_midir_instruction_has_side_effect(vader_box_t l0);
static void vader_midir_intern_data_value_strings(vader_box_t l0, void* l1);
static int32_t vader_midir_intern_string_pool(void* l0, vader_string_t l1);
static int32_t vader_midir_intersect_dom_tree(int32_t l0, int32_t l1, void* l2);
static vader_box_t vader_midir_intrinsic_op_for_name(vader_string_t l0);
static bool vader_midir_is_dest_passing_shape(vader_box_t l0);
static bool vader_midir_is_mutable_slot(vader_box_t l0);
static bool vader_midir_is_scalar_class(uint8_t l0);
static bool vader_midir_is_short_circuit_op(uint8_t l0);
static size_t vader_midir_last_empty_stack_point(void* l0, int32_t l1);
static bool vader_midir_last_op_exits(void* l0);
static bool vader_midir_leaves_at_once(void* l0, void* l1, int32_t l2, int32_t l3);
static bool vader_midir_leaves_header(void* l0, int32_t l1, int32_t l2);
static int32_t vader_midir_loop_exit(void* l0, void* l1, int32_t l2);
static vader_box_t vader_midir_lowered_to_bc_value(vader_box_t l0);
static void* vader_midir_make_extern_decl(void* l0);
static void* vader_midir_make_struct_decl(void* l0);
static bool vader_midir_move_retags(void* l0, void* l1);
static vader_box_t vader_midir_multi_dsts(vader_box_t l0);
static void* vader_midir_natural_loop_bodies(void* l0, void* l1, void* l2);
static bool vader_midir_needs_ref_cast(vader_box_t l0);
static int32_t vader_midir_new_block(void* l0, void* l1);
static void* vader_midir_new_project_ctx(void* l0, void* l1);
static void* vader_midir_no_hints(void);
static bool vader_midir_only_jumps(void* l0, int32_t l1, int32_t l2);
static bool vader_midir_only_leaves(void* l0);
static int32_t vader_midir_open_blocks(void* l0, void* l1, int32_t l2);
static void* vader_midir_operand_edges(vader_box_t l0);
static void* vader_midir_optimise_function(void* l0);
static int32_t vader_midir_outermost_loop_left(void* l0, void* l1, int32_t l2, int32_t l3);
static void vader_midir_pin_baked_struct_types(void* l0, void* l1);
static int64_t vader_midir_pos_key(int32_t l0, size_t l1);
static void* vader_midir_predecessors_of(void* l0);
static void vader_midir_push_emit(void* l0, vader_box_t l1, void* l2);
static int32_t vader_midir_push_op_with_span(void* l0, vader_box_t l1, void* l2);
static vader_box_t vader_midir_pushed_element_type(vader_box_t l0, vader_box_t l1);
static bool vader_midir_read_may_carry_ref(vader_box_t l0);
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
static int32_t vader_midir_resolve_fn_index(void* l0, void* l1);
static void* vader_midir_resolve_loop_frame(void* l0, vader_box_t l1);
static vader_box_t vader_midir_retargeted(void* l0, vader_box_t l1);
static void* vader_midir_reverse_postorder(void* l0);
static void* vader_midir_rpo_positions(void* l0, size_t l1);
static void* vader_midir_schedule_stack(void* l0);
static bool vader_midir_sets_equal(void* l0, void* l1);
static void* vader_midir_shape_of(void* l0, void* l1, void* l2);
static void* vader_midir_skip_forwarding_blocks(void* l0);
static int32_t vader_midir_struct_symbol_id(vader_box_t l0);
static void vader_midir_structure_function(void* l0);
static void* vader_midir_successors_of(void* l0);
static void vader_midir_synthesise_cfg_intrinsic_wrappers(void* l0, void* l1);
static vader_box_t vader_midir_term_return_single(void* l0);
static void vader_midir_terminate(void* l0, vader_box_t l1);
static bool vader_midir_tests_its_exit(void* l0, void* l1, int32_t l2);
static bool vader_midir_try_fuse_local_field(void* l0, int32_t l1, int32_t l2);
static bool vader_midir_unary_leaves_width(uint8_t l0, uint8_t l1);
static bool vader_midir_union_element(vader_box_t l0);
static bool vader_midir_union_field(void* l0, int32_t l1, size_t l2);
static void* vader_midir_union_fields_of(void* l0, int32_t l1);
static void* vader_midir_union_params_of(void* l0, void* l1);
static void* vader_midir_union_slots_of(void* l0);
static void vader_midir_walk_rpo(void* l0, int32_t l1, void* l2, void* l3);
static vader_box_t vader_midir_with_dst(vader_box_t l0, int32_t l1);
static void* vader_midir_with_param_decorators(void* l0, void* l1);
static void* vader_midir_with_peephole_out(void* l0, void* l1);

static bool vader_midir_BlockId_Equals_equals(int32_t l0, int32_t l1) {
    int32_t l2, l3;
    l2 = l0;
    l3 = l1;
    return l2 == l3;
}

bool vader_midir_LocalId_Equals_equals(int32_t l0, int32_t l1) {
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
    size_t l9, l10, l12, l15, l16, l19, l20, l22, l23;
    vader_box_t l24 = vader_box_null();
    vader_string_t l26 = 0;
    vader_string_t l29 = 0;
    vader_string_t l31 = 0;
    vader_string_t l33 = 0;
    vader_string_t l34 = 0;
    vader_box_t t0 = vader_box_null();
    vader_string_t t1 = 0;
    int64_t t2;
    void* t3 = NULL;
    bool t4;
    vader_box_t* gc_roots[2] = { &l24, &t0 };
    void** gc_raw_roots[21] = {
        &l0, &l4, &l5, &l6, &l7, &l8, &l11, &l13, &l14, &l17, &l18, &l21, &l25, &l27, &l28, &l30,
        &l32, &l35, &l36, &l37, &t3,
    };
    vader_string_t* gc_atom_roots[6] = { &l26, &l29, &l31, &l33, &l34, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 21u, gc_roots, gc_raw_roots, 0u, NULL, 6u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = INT32_C(0);
    l2 = INT32_C(0);
    l3 = vader_lower_opt_report_enabled();
    vader_array_t* _a0_arr = vader_array_new(110u, 0u, 13u, 934u);
    l4 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(13u, 0u, 0u, 243u);
    l5 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(21u, 0u, 0u, 254u);
    l6 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(14u, 0u, 7u, 246u);
    l7 = (void*) _a3_arr;
    vader_struct_std_collections_MutableMap__string__Any_t* _a4_obj = (vader_struct_std_collections_MutableMap__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__Any_t));
    vader_obj_header_init(_a4_obj, 335u);
    _a4_obj->f_ekeys = l5;
    _a4_obj->f_evals = l6;
    _a4_obj->f_index = l7;
    _a4_obj->f_mask = (size_t) 0;
    _a4_obj->f_size = (size_t) 0;
    _a4_obj->f_tombs = (size_t) 0;
    l5 = (void*) _a4_obj;
    l6 = ((vader_struct_vader_midir_CFGProject_t*) l0)->f_modules;
    l7 = ((vader_struct_std_collections_MutableMap__string__CFGModule_t*) l6)->f_ekeys;
    l8 = ((vader_struct_std_collections_MutableMap__string__CFGModule_t*) l6)->f_evals;
    l9 = ((vader_struct_std_collections_MutableMap__string__CFGModule_t*) l6)->f_size;
    l10 = (size_t) 0;
    while (!((l10 >= l9))) {
        vader_array_t* _a5_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l10)
        t0 = vader_array_box_slots(_a5_slotarr->buf)[_a5_slotarr->offset + (size_t) l10];
        t1 = t0.payload.s;
        vader_array_t* _a6_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l10)
        l6 = vader_array_ref_load_obj(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l10);
        t2 = (l10 + INT64_C(1));
        l10 = (size_t) (int64_t) t2;
        vader_array_t* _a7_arr = vader_array_new(104u, 0u, 13u, 918u);
        l11 = (void*) _a7_arr;
        l12 = ((vader_array_t*) ((vader_struct_vader_midir_CFGModule_t*) l6)->f_functions)->length;
        vader_array_t* _a8_arr = vader_array_repeat((vader_array_t*) l11, (size_t) l12);
        l13 = (void*) _a8_arr;
        l14 = ((vader_struct_vader_midir_CFGModule_t*) l6)->f_functions;
        l15 = ((vader_array_t*) l14)->length;
        l16 = (size_t) 0;
        while ((l16 < l15)) {
            vader_array_t* _a9_slotarr = ((vader_array_t*) l14);
            VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l16)
            t3 = vader_array_ref_load_obj(_a9_slotarr->buf, _a9_slotarr->offset + (size_t) l16);
            l17 = vader_midir_annotate_function(t3);
            l18 = ((vader_struct_vader_midir_CFGFunction_t*) l17)->f_blocks;
            l19 = ((vader_array_t*) l18)->length;
            l20 = (size_t) 0;
            while ((l20 < l19)) {
                vader_array_t* _a10_slotarr = ((vader_array_t*) l18);
                VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a10_slotarr, l20)
                t3 = vader_array_ref_load_obj(_a10_slotarr->buf, _a10_slotarr->offset + (size_t) l20);
                l21 = ((vader_struct_vader_midir_BasicBlock_t*) t3)->f_instructions;
                l22 = ((vader_array_t*) l21)->length;
                l23 = (size_t) 0;
                while ((l23 < l22)) {
                    vader_array_t* _a11_slotarr = ((vader_array_t*) l21);
                    VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l23)
                    l24 = vader_array_ref_load_box(_a11_slotarr->buf, _a11_slotarr->offset + (size_t) l23);
                    if (l24.tag == 964u) {
                        l1 = (l1 + INT32_C(1));
                        t3 = l24.payload.obj;
                        t4 = ((vader_struct_vader_midir_InstrStructNew_t*) t3)->f_stack;
                        if (t4) {
                            l2 = (l2 + INT32_C(1));
                        } else if (l3) {
                            t3 = l24.payload.obj;
                            l25 = ((vader_struct_vader_midir_InstrStructNew_t*) t3)->f_span;
                            t3 = l24.payload.obj;
                            l26 = vader_types_display_type(((vader_struct_vader_midir_InstrStructNew_t*) t3)->f_type);
                            vader_struct_vader_midir_EscapeSite_t* _a12_obj = (vader_struct_vader_midir_EscapeSite_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_EscapeSite_t));
                            vader_obj_header_init(_a12_obj, 934u);
                            _a12_obj->f_span = l25;
                            _a12_obj->f_kind = 2281u;
                            _a12_obj->f_type_name = l26;
                            l27 = (void*) _a12_obj;
                            vader_array_push((vader_array_t*) l4, vader_ref_box(l27));
                        }
                    } else if (l24.tag == 941u) {
                        l1 = (l1 + INT32_C(1));
                        t3 = l24.payload.obj;
                        t4 = ((vader_struct_vader_midir_InstrArrayNew_t*) t3)->f_stack;
                        if (t4) {
                            l2 = (l2 + INT32_C(1));
                        } else if (l3) {
                            t3 = l24.payload.obj;
                            l28 = ((vader_struct_vader_midir_InstrArrayNew_t*) t3)->f_span;
                            t3 = l24.payload.obj;
                            l29 = vader_types_display_type(((vader_struct_vader_midir_InstrArrayNew_t*) t3)->f_type);
                            vader_struct_vader_midir_EscapeSite_t* _a13_obj = (vader_struct_vader_midir_EscapeSite_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_EscapeSite_t));
                            vader_obj_header_init(_a13_obj, 934u);
                            _a13_obj->f_span = l28;
                            _a13_obj->f_kind = 1274u;
                            _a13_obj->f_type_name = l29;
                            l30 = (void*) _a13_obj;
                            vader_array_push((vader_array_t*) l4, vader_ref_box(l30));
                        }
                    }
                    t2 = (l23 + INT64_C(1));
                    l23 = (size_t) (int64_t) t2;
                }
                t2 = (l20 + INT64_C(1));
                l20 = (size_t) (int64_t) t2;
            }
            vader_array_push((vader_array_t*) l13, vader_ref_box(l17));
            t2 = (l16 + INT64_C(1));
            l16 = (size_t) (int64_t) t2;
        }
        l31 = ((vader_struct_vader_midir_CFGModule_t*) l6)->f_module_id;
        l32 = l6;
        l33 = ((vader_struct_vader_midir_CFGModule_t*) l32)->f_module_id;
        l34 = ((vader_struct_vader_midir_CFGModule_t*) l32)->f_display_path;
        l35 = ((vader_struct_vader_midir_CFGModule_t*) l32)->f_externs;
        l36 = ((vader_struct_vader_midir_CFGModule_t*) l32)->f_struct_decls;
        vader_struct_vader_midir_CFGModule_t* _a14_obj = (vader_struct_vader_midir_CFGModule_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_CFGModule_t));
        vader_obj_header_init(_a14_obj, 920u);
        _a14_obj->f_module_id = l33;
        _a14_obj->f_display_path = l34;
        _a14_obj->f_functions = l13;
        _a14_obj->f_externs = l35;
        _a14_obj->f_struct_decls = l36;
        l37 = (void*) _a14_obj;
        std_collections_MutableMap_IndexSet_set_at__string__Any(l5, l31, vader_ref_box(l37));
    }
    l6 = l0;
    l7 = ((vader_struct_vader_midir_CFGProject_t*) l6)->f_vtable_entries;
    l8 = ((vader_struct_vader_midir_CFGProject_t*) l6)->f_strings;
    l11 = ((vader_struct_vader_midir_CFGProject_t*) l6)->f_data_pool;
    l6 = ((vader_struct_vader_midir_CFGProject_t*) l6)->f_trait_membership;
    vader_struct_vader_midir_CFGProject_t* _a15_obj = (vader_struct_vader_midir_CFGProject_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_CFGProject_t));
    vader_obj_header_init(_a15_obj, 922u);
    _a15_obj->f_modules = l5;
    _a15_obj->f_vtable_entries = l7;
    _a15_obj->f_strings = l8;
    _a15_obj->f_data_pool = l11;
    _a15_obj->f_trait_membership = l6;
    l5 = (void*) _a15_obj;
    vader_struct_vader_midir_EscapeStats_t* _a16_obj = (vader_struct_vader_midir_EscapeStats_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_EscapeStats_t));
    vader_obj_header_init(_a16_obj, 935u);
    _a16_obj->f_total_allocs = l1;
    _a16_obj->f_stack_promoted = l2;
    _a16_obj->f_heap_sites = l4;
    l4 = (void*) _a16_obj;
    vader_struct_vader_midir_AnnotatedProject_t* _a17_obj = (vader_struct_vader_midir_AnnotatedProject_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_AnnotatedProject_t));
    vader_obj_header_init(_a17_obj, 915u);
    _a17_obj->f_project = l5;
    _a17_obj->f_stats = l4;
    t3 = (void*) _a17_obj;
    { void* __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
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
    size_t l4, l5, l7, l8, l18, l19;
    vader_box_t l9 = vader_box_null(), l16 = vader_box_null(), l44 = vader_box_null(), l58 = vader_box_null(), l61 = vader_box_null();
    int32_t l10, l11, l12, l30, l33, l37, l38, l43, l45, l48, l54, l56, l60;
    bool l17, l20, l24, l26, l35, l39, l49, l50;
    vader_string_t l55 = 0;
    vader_string_t l64 = 0;
    void* t0 = NULL;
    int64_t t1;
    bool t2;
    size_t t3;
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
    vader_array_t* _a0_arr = vader_array_new(14u, 0u, 7u, 246u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(11u, 0u, 12u, 241u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(14u, 0u, 7u, 246u);
    l3 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__i32__bool_t* _a3_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
    vader_obj_header_init(_a3_obj, 328u);
    _a3_obj->f_ekeys = l1;
    _a3_obj->f_evals = l2;
    _a3_obj->f_index = l3;
    _a3_obj->f_mask = (size_t) 0;
    _a3_obj->f_size = (size_t) 0;
    _a3_obj->f_tombs = (size_t) 0;
    t0 = (void*) _a3_obj;
    vader_struct_std_collections_MutableSet__i32_t* _a4_obj = (vader_struct_std_collections_MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i32_t));
    vader_obj_header_init(_a4_obj, 425u);
    _a4_obj->f_inner = t0;
    l1 = (void*) _a4_obj;
    vader_array_t* _a5_arr = vader_array_new(14u, 0u, 7u, 246u);
    l2 = (void*) _a5_arr;
    l3 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_blocks;
    l4 = ((vader_array_t*) l3)->length;
    l5 = (size_t) 0;
    while ((l5 < l4)) {
        vader_array_t* _a6_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l5)
        t0 = vader_array_ref_load_obj(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l5);
        l6 = ((vader_struct_vader_midir_BasicBlock_t*) t0)->f_instructions;
        l7 = ((vader_array_t*) l6)->length;
        l8 = (size_t) 0;
        while ((l8 < l7)) {
            vader_array_t* _a7_slotarr = ((vader_array_t*) l6);
            VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l8)
            l9 = vader_array_ref_load_box(_a7_slotarr->buf, _a7_slotarr->offset + (size_t) l8);
            if (l9.tag == 964u) {
                t0 = l9.payload.obj;
                l10 = ((vader_struct_vader_midir_InstrStructNew_t*) t0)->f_dst;
                std_collections_add__i32(l1, l10);
                t0 = l9.payload.obj;
                l11 = ((vader_struct_vader_midir_InstrStructNew_t*) t0)->f_dst;
                vader_array_push_i32((vader_array_t*) l2, l11);
            } else if (l9.tag == 941u) {
                t0 = l9.payload.obj;
                l12 = ((vader_struct_vader_midir_InstrArrayNew_t*) t0)->f_dst;
                std_collections_add__i32(l1, l12);
            }
            t1 = (l8 + INT64_C(1));
            l8 = (size_t) (int64_t) t1;
        }
        t1 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t1;
    }
    t2 = std_collections_is_empty__i32(l1);
    if (t2) {
        { void* __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = vader_midir_compute_escaping(l0, l1);
    l6 = ((vader_struct_vader_midir_EscapeResult_t*) l3)->f_alias_of;
    l6 = vader_midir_compute_carried_across_loop_headers(l0, l6);
    vader_array_t* _a8_arr = vader_array_new(14u, 0u, 7u, 246u);
    l13 = (void*) _a8_arr;
    vader_array_t* _a9_arr = vader_array_new(11u, 0u, 12u, 241u);
    l14 = (void*) _a9_arr;
    vader_array_t* _a10_arr = vader_array_new(14u, 0u, 7u, 246u);
    l15 = (void*) _a10_arr;
    vader_struct_std_collections_MutableMap__i32__bool_t* _a11_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
    vader_obj_header_init(_a11_obj, 328u);
    _a11_obj->f_ekeys = l13;
    _a11_obj->f_evals = l14;
    _a11_obj->f_index = l15;
    _a11_obj->f_mask = (size_t) 0;
    _a11_obj->f_size = (size_t) 0;
    _a11_obj->f_tombs = (size_t) 0;
    t0 = (void*) _a11_obj;
    vader_struct_std_collections_MutableSet__i32_t* _a12_obj = (vader_struct_std_collections_MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i32_t));
    vader_obj_header_init(_a12_obj, 425u);
    _a12_obj->f_inner = t0;
    l13 = (void*) _a12_obj;
    vader_array_t* _a13_arr = vader_array_new(14u, 0u, 7u, 246u);
    l14 = (void*) _a13_arr;
    l4 = ((vader_array_t*) l2)->length;
    l5 = (size_t) 0;
    while ((l5 < l4)) {
        vader_array_t* _a14_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a14_slotarr, l5)
        l10 = ((int32_t*) _a14_slotarr->buf->slots)[_a14_slotarr->offset + (size_t) l5];
        t2 = std_collections_MutableSet_Contains_contains__i32(((vader_struct_vader_midir_EscapeResult_t*) l3)->f_escaping, l10);
        if (t2) {
            t1 = (l5 + INT64_C(1));
            l5 = (size_t) (int64_t) t1;
            continue;
        }
        t2 = std_collections_MutableSet_Contains_contains__i32(l6, l10);
        if (t2) {
            t1 = (l5 + INT64_C(1));
            l5 = (size_t) (int64_t) t1;
            continue;
        }
        std_collections_add__i32(l13, l10);
        vader_array_push_i32((vader_array_t*) l14, l10);
        t1 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t1;
    }
    for (;;) {
        t3 = ((vader_array_t*) l14)->length;
        if ((t3 > INT64_C(0))) {
            t3 = ((vader_array_t*) l14)->length;
            t1 = (t3 - INT64_C(1));
            l4 = (size_t) (int64_t) t1;
            vader_array_t* _a15_slotarr = ((vader_array_t*) l14);
            VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a15_slotarr, l4)
            l10 = ((int32_t*) _a15_slotarr->buf->slots)[_a15_slotarr->offset + (size_t) l4];
            t3 = ((vader_array_t*) l14)->length;
            t1 = (t3 - INT64_C(1));
            l5 = (size_t) (int64_t) t1;
            vader_array_t* _a16_arr = vader_array_slice((vader_array_t*) l14, (size_t) INT64_C(0), (size_t) l5);
            l14 = (void*) _a16_arr;
            l9 = std_collections_MutableMap_Index_at__i32__Any(((vader_struct_vader_midir_EscapeResult_t*) l3)->f_alias_from, l10);
            if (l9.tag == 0u) {
                continue;
            }
            l2 = l9.payload.obj;
            l7 = ((vader_array_t*) l2)->length;
            l8 = (size_t) 0;
            while ((l8 < l7)) {
                vader_array_t* _a17_slotarr = ((vader_array_t*) l2);
                VADER_ARRAY_RESOLVE_BUF(_a17_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a17_slotarr, l8)
                l11 = ((int32_t*) _a17_slotarr->buf->slots)[_a17_slotarr->offset + (size_t) l8];
                t2 = std_collections_MutableSet_Contains_contains__i32(l13, l11);
                if (t2) {
                    t1 = (l8 + INT64_C(1));
                    l8 = (size_t) (int64_t) t1;
                    continue;
                }
                l16 = std_collections_MutableMap_Index_at__i32__Any(((vader_struct_vader_midir_EscapeResult_t*) l3)->f_alias_of, l11);
                if (!(l16.tag == 0u)) {
                    l17 = true;
                    l15 = l16.payload.obj;
                    l18 = ((vader_array_t*) l15)->length;
                    l19 = (size_t) 0;
                    for (;;) {
                        if ((l19 < l18)) {
                            vader_array_t* _a18_slotarr = ((vader_array_t*) l15);
                            VADER_ARRAY_RESOLVE_BUF(_a18_slotarr)
                            l12 = ((int32_t*) _a18_slotarr->buf->slots)[_a18_slotarr->offset + (size_t) l19];
                            t2 = std_collections_MutableSet_Contains_contains__i32(l13, l12);
                            if (t2) {
                                t1 = (l19 + INT64_C(1));
                                l19 = (size_t) (int64_t) t1;
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
                t1 = (l8 + INT64_C(1));
                l8 = (size_t) (int64_t) t1;
            }
            continue;
        }
        break;
    }
    l17 = false;
    vader_array_t* _a19_arr = vader_array_new(102u, 0u, 13u, 916u);
    l2 = (void*) _a19_arr;
    l14 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_blocks;
    l4 = ((vader_array_t*) l14)->length;
    l5 = (size_t) 0;
    while ((l5 < l4)) {
        vader_array_t* _a20_slotarr = ((vader_array_t*) l14);
        VADER_ARRAY_RESOLVE_BUF(_a20_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a20_slotarr, l5)
        l15 = vader_array_ref_load_obj(_a20_slotarr->buf, _a20_slotarr->offset + (size_t) l5);
        l20 = false;
        vader_array_t* _a21_arr = vader_array_new(203u, 0u, 13u, 1503u);
        l21 = (void*) _a21_arr;
        l22 = ((vader_struct_vader_midir_BasicBlock_t*) l15)->f_instructions;
        l7 = ((vader_array_t*) l22)->length;
        l8 = (size_t) 0;
        while ((l8 < l7)) {
            vader_array_t* _a22_slotarr = ((vader_array_t*) l22);
            VADER_ARRAY_RESOLVE_BUF(_a22_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a22_slotarr, l8)
            l9 = vader_array_ref_load_box(_a22_slotarr->buf, _a22_slotarr->offset + (size_t) l8);
            if (l9.tag == 964u) {
                t0 = l9.payload.obj;
                l10 = ((vader_struct_vader_midir_InstrStructNew_t*) t0)->f_dst;
                t2 = std_collections_MutableSet_Contains_contains__i32(l1, l10);
                if (t2) {
                    l25 = ((vader_struct_vader_midir_EscapeResult_t*) l3)->f_escaping;
                    t0 = l9.payload.obj;
                    l11 = ((vader_struct_vader_midir_InstrStructNew_t*) t0)->f_dst;
                    t2 = std_collections_MutableSet_Contains_contains__i32(l25, l11);
                    if (!(t2)) {
                        t0 = l9.payload.obj;
                        l12 = ((vader_struct_vader_midir_InstrStructNew_t*) t0)->f_dst;
                        t2 = std_collections_MutableSet_Contains_contains__i32(l6, l12);
                        l24 = !(t2);
                    } else {
                        l24 = false;
                    }
                    t0 = l9.payload.obj;
                    l26 = ((vader_struct_vader_midir_InstrStructNew_t*) t0)->f_stack;
                    if (l24 == l26) {
                        l27 = l9.payload.obj;
                        vader_array_push((vader_array_t*) l21, vader_ref_box(l27));
                        t1 = (l8 + INT64_C(1));
                        l8 = (size_t) (int64_t) t1;
                        continue;
                    }
                    l20 = true;
                    l28 = l9.payload.obj;
                    l29 = ((vader_struct_vader_midir_InstrStructNew_t*) l28)->f_span;
                    l30 = ((vader_struct_vader_midir_InstrStructNew_t*) l28)->f_dst;
                    l16 = ((vader_struct_vader_midir_InstrStructNew_t*) l28)->f_type;
                    l31 = ((vader_struct_vader_midir_InstrStructNew_t*) l28)->f_fields;
                    vader_struct_vader_midir_InstrStructNew_t* _a23_obj = (vader_struct_vader_midir_InstrStructNew_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrStructNew_t));
                    vader_obj_header_init(_a23_obj, 964u);
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
                    t1 = (l8 + INT64_C(1));
                    l8 = (size_t) (int64_t) t1;
                    continue;
                }
            } else if (l9.tag == 941u) {
                t0 = l9.payload.obj;
                l33 = ((vader_struct_vader_midir_InstrArrayNew_t*) t0)->f_dst;
                t2 = std_collections_MutableSet_Contains_contains__i32(l1, l33);
                if (t2) {
                    l36 = ((vader_struct_vader_midir_EscapeResult_t*) l3)->f_escaping;
                    t0 = l9.payload.obj;
                    l37 = ((vader_struct_vader_midir_InstrArrayNew_t*) t0)->f_dst;
                    t2 = std_collections_MutableSet_Contains_contains__i32(l36, l37);
                    if (!(t2)) {
                        t0 = l9.payload.obj;
                        l38 = ((vader_struct_vader_midir_InstrArrayNew_t*) t0)->f_dst;
                        t2 = std_collections_MutableSet_Contains_contains__i32(l6, l38);
                        l35 = !(t2);
                    } else {
                        l35 = false;
                    }
                    t0 = l9.payload.obj;
                    l39 = ((vader_struct_vader_midir_InstrArrayNew_t*) t0)->f_stack;
                    if (l35 == l39) {
                        l40 = l9.payload.obj;
                        vader_array_push((vader_array_t*) l21, vader_ref_box(l40));
                        t1 = (l8 + INT64_C(1));
                        l8 = (size_t) (int64_t) t1;
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
                    vader_obj_header_init(_a24_obj, 941u);
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
                    t1 = (l8 + INT64_C(1));
                    l8 = (size_t) (int64_t) t1;
                    continue;
                }
            } else if (l9.tag == 957u) {
                t0 = l9.payload.obj;
                l48 = ((vader_struct_vader_midir_InstrFieldSet_t*) t0)->f_target;
                l49 = std_collections_MutableSet_Contains_contains__i32(l13, l48);
                t0 = l9.payload.obj;
                l50 = ((vader_struct_vader_midir_InstrFieldSet_t*) t0)->f_barrierless;
                if (l49 == l50) {
                    l51 = l9.payload.obj;
                    vader_array_push((vader_array_t*) l21, vader_ref_box(l51));
                    t1 = (l8 + INT64_C(1));
                    l8 = (size_t) (int64_t) t1;
                    continue;
                }
                l20 = true;
                l52 = l9.payload.obj;
                l53 = ((vader_struct_vader_midir_InstrFieldSet_t*) l52)->f_span;
                l54 = ((vader_struct_vader_midir_InstrFieldSet_t*) l52)->f_target;
                l55 = ((vader_struct_vader_midir_InstrFieldSet_t*) l52)->f_field;
                l56 = ((vader_struct_vader_midir_InstrFieldSet_t*) l52)->f_value;
                vader_struct_vader_midir_InstrFieldSet_t* _a25_obj = (vader_struct_vader_midir_InstrFieldSet_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrFieldSet_t));
                vader_obj_header_init(_a25_obj, 957u);
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
            t1 = (l8 + INT64_C(1));
            l8 = (size_t) (int64_t) t1;
        }
        if (l20) {
            l17 = true;
            l59 = l15;
            l60 = ((vader_struct_vader_midir_BasicBlock_t*) l59)->f_id;
            l61 = ((vader_struct_vader_midir_BasicBlock_t*) l59)->f_terminator;
            l62 = ((vader_struct_vader_midir_BasicBlock_t*) l59)->f_span;
            vader_struct_vader_midir_BasicBlock_t* _a26_obj = (vader_struct_vader_midir_BasicBlock_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_BasicBlock_t));
            vader_obj_header_init(_a26_obj, 916u);
            _a26_obj->f_id = l60;
            _a26_obj->f_instructions = l21;
            _a26_obj->f_terminator = l61;
            _a26_obj->f_span = l62;
            l63 = (void*) _a26_obj;
            vader_array_push((vader_array_t*) l2, vader_ref_box(l63));
            t1 = (l5 + INT64_C(1));
            l5 = (size_t) (int64_t) t1;
            continue;
        }
        vader_array_push((vader_array_t*) l2, vader_ref_box(l15));
        t1 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t1;
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
    vader_obj_header_init(_a27_obj, 918u);
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
    l3 = std_collections_MutableMap_Index_at__i32__Any(l0, l1);
    if (l3.tag == 0u) {
        vader_array_t* _a0_arr = vader_array_new(14u, 1u, 7u, 246u);
        ((int32_t*) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = (int32_t) l2;
        l4 = (void*) _a0_arr;
        std_collections_MutableMap_IndexSet_set_at__i32__Any(l0, l1, vader_ref_box(l4));
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
    if (!(l0.tag == 1077u)) {
        { vader_gc_top = gc_frame.prev; return 0u; }
    }
    t0 = l0.payload.obj;
    t1 = vader_types_display_type_key(((vader_struct_vader_types_ArrayType_t*) t0)->f_element);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static uint8_t vader_midir_array_element_val_type(vader_box_t l0) {
    void* t0;
    uint8_t t1;
    if (!(l0.tag == 1077u)) {
        return (uint8_t) 19;
    }
    t0 = l0.payload.obj;
    t1 = vader_bytecode_val_type_of_type(((vader_struct_vader_types_ArrayType_t*) t0)->f_element);
    return t1;
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
    if (l0.tag == 880u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_lower_LoweredIntLit_t*) t0)->f_value;
        { uint64_t __vret = (uint64_t) (int64_t) t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 867u) {
        t0 = l0.payload.obj;
        t2 = ((vader_struct_vader_lower_LoweredCharLit_t*) t0)->f_value;
        { uint64_t __vret = (uint64_t) (int64_t) ((int64_t) (uint32_t) t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 860u) {
        t0 = l0.payload.obj;
        t3 = ((vader_struct_vader_lower_LoweredBoolLit_t*) t0)->f_value;
        if (t3) {
            { vader_gc_top = gc_frame.prev; return (uint64_t) 1; }
        }
        { vader_gc_top = gc_frame.prev; return (uint64_t) 0; }
    }
    if (!(l0.tag == 875u)) {
        vader_host_std_abort_panic(1990u);
        vader_unreachable("a no-return call returned");
    }
    if (!(l1 == 1628u)) {
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
            if (l0 == INT32_C(4)) {
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

static void* vader_midir_branch_on_cond(void* l0, vader_box_t l1, int32_t l2, int32_t l3, bool l4) {
    vader_box_t l5 = vader_box_null();
    void* l6 = NULL;
    void* l10 = NULL;
    bool l7, l8;
    int32_t l9;
    void* t0 = NULL;
    bool t1;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l1, &l5, &t2 };
    void** gc_raw_roots[4] = { &l0, &l6, &l10, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l1.tag == 899u) {
        t0 = l1.payload.obj;
        if (((vader_struct_vader_lower_LoweredUnary_t*) t0)->f_op == INT32_C(1)) {
            t0 = l1.payload.obj;
            l5 = ((vader_struct_vader_lower_LoweredUnary_t*) t0)->f_operand;
            l6 = vader_midir_branch_on_cond(l0, l5, l3, l2, l4);
            l7 = ((vader_struct_vader_midir_CondReach_t*) l6)->f_on_false;
            l8 = ((vader_struct_vader_midir_CondReach_t*) l6)->f_on_true;
            vader_struct_vader_midir_CondReach_t* _a0_obj = (vader_struct_vader_midir_CondReach_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_CondReach_t));
            vader_obj_header_init(_a0_obj, 925u);
            _a0_obj->f_on_true = l7;
            _a0_obj->f_on_false = l8;
            t0 = (void*) _a0_obj;
            { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    if (l4) {
        if (l1.tag == 858u) {
            t0 = l1.payload.obj;
            t1 = vader_midir_is_short_circuit_op(((vader_struct_vader_lower_LoweredBinary_t*) t0)->f_op);
            if (t1) {
                t0 = l1.payload.obj;
                l6 = vader_lower_span_of(((vader_struct_vader_lower_LoweredBinary_t*) t0)->f_right);
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
                    t2 = vader_box_i32(246u, l9);
                    ((vader_struct_vader_midir_FnCtx_t*) l0)->f_current = t2;
                    VADER_WRITE_BARRIER((vader_struct_vader_midir_FnCtx_t*) l0);
                    t0 = l1.payload.obj;
                    l5 = ((vader_struct_vader_lower_LoweredBinary_t*) t0)->f_right;
                    l10 = vader_midir_branch_on_cond(l0, l5, l2, l3, l4);
                    l7 = ((vader_struct_vader_midir_CondReach_t*) l10)->f_on_true;
                    t1 = ((vader_struct_vader_midir_CondReach_t*) l6)->f_on_false;
                    if (t1) {
                        l8 = true;
                        vader_struct_vader_midir_CondReach_t* _a1_obj = (vader_struct_vader_midir_CondReach_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_CondReach_t));
                        vader_obj_header_init(_a1_obj, 925u);
                        _a1_obj->f_on_true = l7;
                        _a1_obj->f_on_false = l8;
                        t0 = (void*) _a1_obj;
                        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
                    }
                    l8 = ((vader_struct_vader_midir_CondReach_t*) l10)->f_on_false;
                    vader_struct_vader_midir_CondReach_t* _a2_obj = (vader_struct_vader_midir_CondReach_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_CondReach_t));
                    vader_obj_header_init(_a2_obj, 925u);
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
                t2 = vader_box_i32(246u, l9);
                ((vader_struct_vader_midir_FnCtx_t*) l0)->f_current = t2;
                VADER_WRITE_BARRIER((vader_struct_vader_midir_FnCtx_t*) l0);
                t0 = l1.payload.obj;
                l5 = ((vader_struct_vader_lower_LoweredBinary_t*) t0)->f_right;
                l10 = vader_midir_branch_on_cond(l0, l5, l2, l3, l4);
                t1 = ((vader_struct_vader_midir_CondReach_t*) l6)->f_on_true;
                if (t1) {
                    l7 = true;
                    l8 = ((vader_struct_vader_midir_CondReach_t*) l10)->f_on_false;
                    vader_struct_vader_midir_CondReach_t* _a3_obj = (vader_struct_vader_midir_CondReach_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_CondReach_t));
                    vader_obj_header_init(_a3_obj, 925u);
                    _a3_obj->f_on_true = l7;
                    _a3_obj->f_on_false = l8;
                    t0 = (void*) _a3_obj;
                    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
                }
                l7 = ((vader_struct_vader_midir_CondReach_t*) l10)->f_on_true;
                l8 = ((vader_struct_vader_midir_CondReach_t*) l10)->f_on_false;
                vader_struct_vader_midir_CondReach_t* _a4_obj = (vader_struct_vader_midir_CondReach_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_CondReach_t));
                vader_obj_header_init(_a4_obj, 925u);
                _a4_obj->f_on_true = l7;
                _a4_obj->f_on_false = l8;
                t0 = (void*) _a4_obj;
                { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
            }
        }
    }
    vader_struct_vader_midir_CondReach_t* _a5_obj = (vader_struct_vader_midir_CondReach_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_CondReach_t));
    vader_obj_header_init(_a5_obj, 925u);
    _a5_obj->f_on_true = false;
    _a5_obj->f_on_false = false;
    l6 = (void*) _a5_obj;
    l5 = vader_midir_build_expr(l0, l1);
    if (l5.tag == 0u) {
        { void* __vret = l6; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l9 = ((int32_t) l5.payload.i);
    if (!(((vader_struct_vader_midir_FnCtx_t*) l0)->f_current.tag == 0u)) {
        t0 = vader_lower_span_of(l1);
        vader_struct_vader_midir_TermCondBranch_t* _a6_obj = (vader_struct_vader_midir_TermCondBranch_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_TermCondBranch_t));
        vader_obj_header_init(_a6_obj, 979u);
        _a6_obj->f_span = t0;
        _a6_obj->f_cond = l9;
        _a6_obj->f_then_block = l2;
        _a6_obj->f_else_block = l3;
        l10 = (void*) _a6_obj;
        vader_midir_terminate(l0, vader_ref_box(l10));
        vader_struct_vader_midir_CondReach_t* _a7_obj = (vader_struct_vader_midir_CondReach_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_CondReach_t));
        vader_obj_header_init(_a7_obj, 925u);
        _a7_obj->f_on_true = true;
        _a7_obj->f_on_false = true;
        t0 = (void*) _a7_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { void* __vret = l6; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir_build_args(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    size_t l4, l5;
    vader_box_t l6 = vader_box_null(), l8 = vader_box_null();
    int32_t l7;
    int64_t t0;
    vader_box_t* gc_roots[2] = { &l6, &l8 };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(14u, 0u, 7u, 246u);
    l2 = (void*) _a0_arr;
    l3 = l1;
    l4 = ((vader_array_t*) l3)->length;
    l5 = (size_t) 0;
    while ((l5 < l4)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
        l6 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5);
        l8 = vader_midir_build_expr(l0, l6);
        if (l8.tag == 0u) {
            { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
        }
        l7 = ((int32_t) l8.payload.i);
        vader_array_push_i32((vader_array_t*) l2, l7);
        t0 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t0;
    }
    { vader_box_t __vret = vader_ref_box(l2); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir_build_array_len(void* l0, void* l1) {
    int32_t l2, l4;
    vader_box_t l3 = vader_box_null();
    void* l5 = NULL;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l3, &t0 };
    void** gc_raw_roots[3] = { &l0, &l1, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_lower_LoweredArrayLen_t*) l1)->f_target;
    l3 = vader_midir_build_expr(l0, l3);
    if (l3.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l2 = ((int32_t) l3.payload.i);
    l3 = ((vader_struct_vader_lower_LoweredArrayLen_t*) l1)->f_type;
    l4 = vader_midir_fresh_tmp(l0, 1925u, l3);
    vader_struct_vader_midir_InstrArrayLen_t* _a0_obj = (vader_struct_vader_midir_InstrArrayLen_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrArrayLen_t));
    vader_obj_header_init(_a0_obj, 940u);
    _a0_obj->f_span = ((vader_struct_vader_lower_LoweredArrayLen_t*) l1)->f_span;
    _a0_obj->f_dst = l4;
    _a0_obj->f_target = l2;
    l5 = (void*) _a0_obj;
    vader_midir_emit(l0, vader_ref_box(l5));
    t0 = vader_box_i32(246u, l4);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir_build_array_lit(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    size_t l4, l5;
    vader_box_t l6 = vader_box_null(), l8 = vader_box_null();
    int32_t l7, l9;
    int64_t t0;
    size_t t1;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l6, &l8, &t2 };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(14u, 0u, 7u, 246u);
    l2 = (void*) _a0_arr;
    l3 = ((vader_struct_vader_lower_LoweredArrayLit_t*) l1)->f_elements;
    l4 = ((vader_array_t*) l3)->length;
    l5 = (size_t) 0;
    while ((l5 < l4)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
        l6 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5);
        l8 = vader_midir_build_expr(l0, l6);
        if (l8.tag == 0u) {
            { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
        }
        l7 = ((int32_t) l8.payload.i);
        vader_array_push_i32((vader_array_t*) l2, l7);
        t0 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t0;
    }
    l6 = ((vader_struct_vader_lower_LoweredArrayLit_t*) l1)->f_type;
    l7 = vader_midir_fresh_tmp(l0, 1272u, l6);
    l3 = ((vader_struct_vader_lower_LoweredArrayLit_t*) l1)->f_span;
    l6 = ((vader_struct_vader_lower_LoweredArrayLit_t*) l1)->f_type;
    t1 = ((vader_array_t*) ((vader_struct_vader_lower_LoweredArrayLit_t*) l1)->f_elements)->length;
    l9 = ((int32_t) (size_t) t1);
    vader_struct_vader_midir_InstrArrayNew_t* _a2_obj = (vader_struct_vader_midir_InstrArrayNew_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrArrayNew_t));
    vader_obj_header_init(_a2_obj, 941u);
    _a2_obj->f_span = l3;
    _a2_obj->f_dst = l7;
    _a2_obj->f_type = l6;
    _a2_obj->f_length = l9;
    _a2_obj->f_elements = l2;
    _a2_obj->f_stack = false;
    l2 = (void*) _a2_obj;
    vader_midir_emit(l0, vader_ref_box(l2));
    t2 = vader_box_i32(246u, l7);
    { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir_build_array_push(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l3 = vader_box_null();
    void* l4 = NULL;
    int32_t l5, l6;
    bool l7;
    vader_box_t* gc_roots[2] = { &l2, &l3 };
    void** gc_raw_roots[3] = { &l0, &l1, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_lower_LoweredArrayPush_t*) l1)->f_target;
    l2 = vader_midir_build_expr(l0, l2);
    l3 = ((vader_struct_vader_lower_LoweredArrayPush_t*) l1)->f_value;
    l3 = vader_midir_build_expr(l0, l3);
    if (l2.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    if (!(l3.tag == 0u)) {
        l4 = ((vader_struct_vader_lower_LoweredArrayPush_t*) l1)->f_span;
        l5 = ((int32_t) l2.payload.i);
        l6 = ((int32_t) l3.payload.i);
        l7 = ((vader_struct_vader_lower_LoweredArrayPush_t*) l1)->f_cached;
        vader_struct_vader_midir_InstrArrayPush_t* _a0_obj = (vader_struct_vader_midir_InstrArrayPush_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrArrayPush_t));
        vader_obj_header_init(_a0_obj, 942u);
        _a0_obj->f_span = l4;
        _a0_obj->f_target = l5;
        _a0_obj->f_value = l6;
        _a0_obj->f_cached = l7;
        l4 = (void*) _a0_obj;
        vader_midir_emit(l0, vader_ref_box(l4));
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static vader_box_t vader_midir_build_array_slice(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l3 = vader_box_null(), l4 = vader_box_null(), l5 = vader_box_null();
    int32_t l6, l8, l9, l10;
    void* l7 = NULL;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[5] = { &l2, &l3, &l4, &l5, &t0 };
    void** gc_raw_roots[3] = { &l0, &l1, &l7 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 5u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_lower_LoweredArraySlice_t*) l1)->f_target;
    l2 = vader_midir_build_expr(l0, l2);
    l3 = ((vader_struct_vader_lower_LoweredArraySlice_t*) l1)->f_lo;
    l3 = vader_midir_build_expr(l0, l3);
    l4 = ((vader_struct_vader_lower_LoweredArraySlice_t*) l1)->f_hi;
    l4 = vader_midir_build_expr(l0, l4);
    if (l2.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    if (l3.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    if (!(l4.tag == 0u)) {
        l5 = ((vader_struct_vader_lower_LoweredArraySlice_t*) l1)->f_type;
        l6 = vader_midir_fresh_tmp(l0, 2191u, l5);
        l7 = ((vader_struct_vader_lower_LoweredArraySlice_t*) l1)->f_span;
        l5 = ((vader_struct_vader_lower_LoweredArraySlice_t*) l1)->f_type;
        l8 = ((int32_t) l2.payload.i);
        l9 = ((int32_t) l3.payload.i);
        l10 = ((int32_t) l4.payload.i);
        vader_struct_vader_midir_InstrArraySlice_t* _a0_obj = (vader_struct_vader_midir_InstrArraySlice_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrArraySlice_t));
        vader_obj_header_init(_a0_obj, 944u);
        _a0_obj->f_span = l7;
        _a0_obj->f_dst = l6;
        _a0_obj->f_type = l5;
        _a0_obj->f_target = l8;
        _a0_obj->f_lo = l9;
        _a0_obj->f_hi = l10;
        l7 = (void*) _a0_obj;
        vader_midir_emit(l0, vader_ref_box(l7));
        t0 = vader_box_i32(246u, l6);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static void vader_midir_build_assign(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l5 = vader_box_null(), l6 = vader_box_null(), l9 = vader_box_null();
    void* l3 = NULL;
    int32_t l4, l7, l10;
    vader_string_t l8 = 0;
    bool l11;
    void* t0 = NULL;
    vader_box_t* gc_roots[4] = { &l2, &l5, &l6, &l9 };
    void** gc_raw_roots[4] = { &l0, &l1, &l3, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l8 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_lower_LoweredAssign_t*) l1)->f_target;
    if (l2.tag == 877u) {
        l3 = ((vader_struct_vader_midir_FnCtx_t*) l0)->f_local_by_sym_id;
        t0 = l2.payload.obj;
        l4 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_lower_LoweredIdent_t*) t0)->f_symbol)->f_id;
        l5 = std_collections_MutableMap_Index_at__i32__i32(l3, l4);
        l6 = ((vader_struct_vader_lower_LoweredAssign_t*) l1)->f_value;
        l6 = vader_midir_build_expr(l0, l6);
        if (l5.tag == 0u) {
            { vader_gc_top = gc_frame.prev; return; }
        }
        if (!(l6.tag == 0u)) {
            l3 = ((vader_struct_vader_lower_LoweredAssign_t*) l1)->f_span;
            l4 = ((int32_t) l5.payload.i);
            l7 = ((int32_t) l6.payload.i);
            vader_struct_vader_midir_InstrMove_t* _a0_obj = (vader_struct_vader_midir_InstrMove_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrMove_t));
            vader_obj_header_init(_a0_obj, 962u);
            _a0_obj->f_span = l3;
            _a0_obj->f_dst = l4;
            _a0_obj->f_src = l7;
            l3 = (void*) _a0_obj;
            vader_midir_emit(l0, vader_ref_box(l3));
            { vader_gc_top = gc_frame.prev; return; }
        }
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 874u) {
        t0 = l2.payload.obj;
        l5 = ((vader_struct_vader_lower_LoweredFieldAccess_t*) t0)->f_target;
        l5 = vader_midir_build_expr(l0, l5);
        l6 = ((vader_struct_vader_lower_LoweredAssign_t*) l1)->f_value;
        l6 = vader_midir_build_expr(l0, l6);
        if (l5.tag == 0u) {
            { vader_gc_top = gc_frame.prev; return; }
        }
        if (!(l6.tag == 0u)) {
            l3 = ((vader_struct_vader_lower_LoweredAssign_t*) l1)->f_span;
            l4 = ((int32_t) l5.payload.i);
            t0 = l2.payload.obj;
            l8 = ((vader_struct_vader_lower_LoweredFieldAccess_t*) t0)->f_field;
            l7 = ((int32_t) l6.payload.i);
            vader_struct_vader_midir_InstrFieldSet_t* _a1_obj = (vader_struct_vader_midir_InstrFieldSet_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrFieldSet_t));
            vader_obj_header_init(_a1_obj, 957u);
            _a1_obj->f_span = l3;
            _a1_obj->f_target = l4;
            _a1_obj->f_field = l8;
            _a1_obj->f_value = l7;
            _a1_obj->f_barrierless = false;
            l3 = (void*) _a1_obj;
            vader_midir_emit(l0, vader_ref_box(l3));
            { vader_gc_top = gc_frame.prev; return; }
        }
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (!(l2.tag == 879u)) {
        l9 = ((vader_struct_vader_lower_LoweredAssign_t*) l1)->f_value;
        vader_midir_build_expr(l0, l9);
        { vader_gc_top = gc_frame.prev; return; }
    }
    t0 = l2.payload.obj;
    l5 = ((vader_struct_vader_lower_LoweredIndex_t*) t0)->f_target;
    l5 = vader_midir_build_expr(l0, l5);
    t0 = l2.payload.obj;
    l6 = ((vader_struct_vader_lower_LoweredIndex_t*) t0)->f_index;
    l6 = vader_midir_build_expr(l0, l6);
    l9 = ((vader_struct_vader_lower_LoweredAssign_t*) l1)->f_value;
    l9 = vader_midir_build_expr(l0, l9);
    if (l5.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l6.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (!(l9.tag == 0u)) {
        l3 = ((vader_struct_vader_lower_LoweredAssign_t*) l1)->f_span;
        l4 = ((int32_t) l5.payload.i);
        l7 = ((int32_t) l6.payload.i);
        l10 = ((int32_t) l9.payload.i);
        t0 = l2.payload.obj;
        l11 = ((vader_struct_vader_lower_LoweredIndex_t*) t0)->f_bounds_safe;
        vader_struct_vader_midir_InstrArraySet_t* _a2_obj = (vader_struct_vader_midir_InstrArraySet_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrArraySet_t));
        vader_obj_header_init(_a2_obj, 943u);
        _a2_obj->f_span = l3;
        _a2_obj->f_target = l4;
        _a2_obj->f_index = l7;
        _a2_obj->f_value = l10;
        _a2_obj->f_bounds_safe = l11;
        l3 = (void*) _a2_obj;
        vader_midir_emit(l0, vader_ref_box(l3));
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_midir_build_back_edge(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    size_t l4, l5;
    vader_box_t l6 = vader_box_null();
    int32_t l7;
    int64_t t0;
    vader_box_t* gc_roots[1] = { &l6 };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_midir_LoopFrame_t*) l1)->f_step;
    l4 = ((vader_array_t*) l3)->length;
    l5 = (size_t) 0;
    while ((l5 < l4)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
        l6 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
        vader_midir_build_stmt(l0, l6);
        t0 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t0;
    }
    if (((vader_struct_vader_midir_FnCtx_t*) l0)->f_current.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l7 = ((vader_struct_vader_midir_LoopFrame_t*) l1)->f_header_id;
    vader_struct_vader_midir_TermBranch_t* _a1_obj = (vader_struct_vader_midir_TermBranch_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_TermBranch_t));
    vader_obj_header_init(_a1_obj, 978u);
    _a1_obj->f_span = l2;
    _a1_obj->f_target = l7;
    l3 = (void*) _a1_obj;
    vader_midir_terminate(l0, vader_ref_box(l3));
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_midir_build_binary(void* l0, void* l1) {
    int32_t l2, l4, l6;
    vader_box_t l3 = vader_box_null();
    vader_string_t l5 = 0;
    void* l7 = NULL;
    uint8_t l8;
    bool t0;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l3, &t1 };
    void** gc_raw_roots[3] = { &l0, &l1, &l7 };
    vader_string_t* gc_atom_roots[1] = { &l5 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_midir_is_short_circuit_op(((vader_struct_vader_lower_LoweredBinary_t*) l1)->f_op);
    if (t0) {
        t1 = vader_midir_build_short_circuit(l0, l1, vader_box_obj(0u, NULL));
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = ((vader_struct_vader_lower_LoweredBinary_t*) l1)->f_left;
    l3 = vader_midir_build_expr(l0, l3);
    if (l3.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l2 = ((int32_t) l3.payload.i);
    l3 = ((vader_struct_vader_lower_LoweredBinary_t*) l1)->f_right;
    l3 = vader_midir_build_expr(l0, l3);
    if (l3.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l4 = ((int32_t) l3.payload.i);
    l5 = vader_lower_binary_op_name(((vader_struct_vader_lower_LoweredBinary_t*) l1)->f_op);
    l3 = ((vader_struct_vader_lower_LoweredBinary_t*) l1)->f_type;
    l6 = vader_midir_fresh_tmp(l0, l5, l3);
    l7 = ((vader_struct_vader_lower_LoweredBinary_t*) l1)->f_span;
    l8 = ((vader_struct_vader_lower_LoweredBinary_t*) l1)->f_op;
    l3 = ((vader_struct_vader_lower_LoweredBinary_t*) l1)->f_type;
    vader_struct_vader_midir_InstrBinOp_t* _a0_obj = (vader_struct_vader_midir_InstrBinOp_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrBinOp_t));
    vader_obj_header_init(_a0_obj, 945u);
    _a0_obj->f_span = l7;
    _a0_obj->f_dst = l6;
    _a0_obj->f_op = l8;
    _a0_obj->f_lhs = l2;
    _a0_obj->f_rhs = l4;
    _a0_obj->f_type = l3;
    l7 = (void*) _a0_obj;
    vader_midir_emit(l0, vader_ref_box(l7));
    t1 = vader_box_i32(246u, l6);
    { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir_build_block_body(void* l0, void* l1) {
    void* l2 = NULL;
    size_t l3, l4;
    vader_box_t l5 = vader_box_null();
    int64_t t0;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l5, &t1 };
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_lower_LoweredBlock_t*) l1)->f_stmts;
    l3 = ((vader_array_t*) l2)->length;
    l4 = (size_t) 0;
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        l5 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        if (((vader_struct_vader_midir_FnCtx_t*) l0)->f_current.tag == 0u) {
            { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
        }
        vader_midir_build_stmt(l0, l5);
        t0 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t0;
    }
    if (((vader_struct_vader_midir_FnCtx_t*) l0)->f_current.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    if (!(((vader_struct_vader_lower_LoweredBlock_t*) l1)->f_trailing.tag == 0u)) {
        l5 = ((vader_struct_vader_lower_LoweredBlock_t*) l1)->f_trailing;
        t1 = vader_midir_build_expr(l0, l5);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static void vader_midir_build_block_into(void* l0, void* l1, int32_t l2) {
    void* l3 = NULL;
    size_t l4, l5;
    vader_box_t l6 = vader_box_null();
    int64_t t0;
    vader_box_t* gc_roots[1] = { &l6 };
    void** gc_raw_roots[3] = { &l0, &l1, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_lower_LoweredBlock_t*) l1)->f_stmts;
    l4 = ((vader_array_t*) l3)->length;
    l5 = (size_t) 0;
    while ((l5 < l4)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
        l6 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
        if (((vader_struct_vader_midir_FnCtx_t*) l0)->f_current.tag == 0u) {
            { vader_gc_top = gc_frame.prev; return; }
        }
        vader_midir_build_stmt(l0, l6);
        t0 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t0;
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

static vader_box_t vader_midir_build_call(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    int32_t l4;
    vader_box_t l5 = vader_box_null(), l10 = vader_box_null(), l11 = vader_box_null();
    vader_string_t l8 = 0;
    bool l9;
    bool t0;
    int32_t t1;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[4] = { &l5, &l10, &l11, &t2 };
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l3, &l6, &l7 };
    vader_string_t* gc_atom_roots[1] = { &l8 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (((vader_struct_vader_lower_LoweredCall_t*) l1)->f_callee.tag == 877u) {
        l2 = ((vader_struct_vader_lower_LoweredCall_t*) l1)->f_callee.payload.obj;
        if (((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_lower_LoweredIdent_t*) l2)->f_symbol)->f_kind == INT32_C(0)) {
            l3 = ((vader_struct_vader_midir_ProjectCtx_t*) ((vader_struct_vader_midir_FnCtx_t*) l0)->f_project)->f_extern_callbacks;
            l4 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_lower_LoweredIdent_t*) l2)->f_symbol)->f_id;
            l5 = std_collections_MutableMap_Index_at__i32__Any(l3, l4);
            if (l5.tag == 429u) {
                l6 = l5.payload.obj;
                l7 = ((vader_struct_vader_lower_LoweredCall_t*) l1)->f_args;
                l8 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_lower_LoweredIdent_t*) l2)->f_symbol)->f_name;
                l5 = vader_midir_build_extern_args(l0, l7, l6, l8);
                if (l5.tag == 0u) {
                    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
                }
                l3 = l5.payload.obj;
            } else {
                l6 = ((vader_struct_vader_lower_LoweredCall_t*) l1)->f_args;
                l5 = vader_midir_build_args(l0, l6);
                if (l5.tag == 0u) {
                    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
                }
                l3 = l5.payload.obj;
            }
            t0 = vader_typecheck_is_void(((vader_struct_vader_lower_LoweredCall_t*) l1)->f_type);
            if (t0) {
                l9 = true;
            } else {
                l9 = ((vader_struct_vader_lower_LoweredCall_t*) l1)->f_type.tag == 1084u;
            }
            if (l9) {
                l5 = vader_box_obj(0u, NULL);
            } else {
                l10 = ((vader_struct_vader_lower_LoweredCall_t*) l1)->f_type;
                t1 = vader_midir_fresh_tmp(l0, 1408u, l10);
                l5 = vader_box_i32(246u, t1);
            }
            l6 = ((vader_struct_vader_lower_LoweredCall_t*) l1)->f_span;
            if (l5.tag == 0u) {
                vader_array_t* _a0_arr = vader_array_new(14u, 0u, 7u, 246u);
                l7 = (void*) _a0_arr;
            } else {
                t1 = ((int32_t) l5.payload.i);
                vader_array_t* _a1_arr = vader_array_new(14u, 1u, 7u, 246u);
                ((int32_t*) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = (int32_t) t1;
                l7 = (void*) _a1_arr;
            }
            l2 = ((vader_struct_vader_lower_LoweredIdent_t*) l2)->f_symbol;
            l10 = ((vader_struct_vader_lower_LoweredCall_t*) l1)->f_type;
            vader_struct_vader_midir_InstrCall_t* _a2_obj = (vader_struct_vader_midir_InstrCall_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrCall_t));
            vader_obj_header_init(_a2_obj, 946u);
            _a2_obj->f_span = l6;
            _a2_obj->f_dsts = l7;
            _a2_obj->f_callee = l2;
            _a2_obj->f_args = l3;
            _a2_obj->f_type = l10;
            l2 = (void*) _a2_obj;
            vader_midir_emit(l0, vader_ref_box(l2));
            t2 = vader_midir_end_after_no_return(l0, l1, l5);
            { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    l5 = ((vader_struct_vader_lower_LoweredCall_t*) l1)->f_callee;
    l5 = vader_midir_build_expr(l0, l5);
    if (l5.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l4 = ((int32_t) l5.payload.i);
    l3 = ((vader_struct_vader_lower_LoweredCall_t*) l1)->f_args;
    l5 = vader_midir_build_args(l0, l3);
    if (l5.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l2 = l5.payload.obj;
    t0 = vader_typecheck_is_void(((vader_struct_vader_lower_LoweredCall_t*) l1)->f_type);
    if (t0) {
        l9 = true;
    } else {
        l9 = ((vader_struct_vader_lower_LoweredCall_t*) l1)->f_type.tag == 1084u;
    }
    if (l9) {
        l5 = vader_box_obj(0u, NULL);
    } else {
        l10 = ((vader_struct_vader_lower_LoweredCall_t*) l1)->f_type;
        t1 = vader_midir_fresh_tmp(l0, 1415u, l10);
        l5 = vader_box_i32(246u, t1);
    }
    l3 = ((vader_struct_vader_lower_LoweredCall_t*) l1)->f_span;
    l10 = vader_lower_type_of(((vader_struct_vader_lower_LoweredCall_t*) l1)->f_callee);
    l11 = ((vader_struct_vader_lower_LoweredCall_t*) l1)->f_type;
    vader_struct_vader_midir_InstrCallIndirect_t* _a3_obj = (vader_struct_vader_midir_InstrCallIndirect_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrCallIndirect_t));
    vader_obj_header_init(_a3_obj, 947u);
    _a3_obj->f_span = l3;
    _a3_obj->f_dst = l5;
    _a3_obj->f_callee = l4;
    _a3_obj->f_args = l2;
    _a3_obj->f_fn_type = l10;
    _a3_obj->f_type = l11;
    l2 = (void*) _a3_obj;
    vader_midir_emit(l0, vader_ref_box(l2));
    t2 = vader_midir_end_after_no_return(l0, l1, l5);
    { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir_build_cast(void* l0, void* l1) {
    int32_t l2, l4;
    vader_box_t l3 = vader_box_null();
    void* l5 = NULL;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l3, &t0 };
    void** gc_raw_roots[3] = { &l0, &l1, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_lower_LoweredCast_t*) l1)->f_value;
    l3 = vader_midir_build_expr(l0, l3);
    if (l3.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l2 = ((int32_t) l3.payload.i);
    l3 = ((vader_struct_vader_lower_LoweredCast_t*) l1)->f_type;
    l4 = vader_midir_fresh_tmp(l0, 1437u, l3);
    l5 = ((vader_struct_vader_lower_LoweredCast_t*) l1)->f_span;
    l3 = ((vader_struct_vader_lower_LoweredCast_t*) l1)->f_type;
    vader_struct_vader_midir_InstrCast_t* _a0_obj = (vader_struct_vader_midir_InstrCast_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrCast_t));
    vader_obj_header_init(_a0_obj, 948u);
    _a0_obj->f_span = l5;
    _a0_obj->f_dst = l4;
    _a0_obj->f_value = l2;
    _a0_obj->f_type = l3;
    l5 = (void*) _a0_obj;
    vader_midir_emit(l0, vader_ref_box(l5));
    t0 = vader_box_i32(246u, l4);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir_build_cell_get(void* l0, void* l1) {
    int32_t l2, l4;
    vader_box_t l3 = vader_box_null();
    void* l5 = NULL;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l3, &t0 };
    void** gc_raw_roots[3] = { &l0, &l1, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_lower_LoweredCellGet_t*) l1)->f_target;
    l3 = vader_midir_build_expr(l0, l3);
    if (l3.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l2 = ((int32_t) l3.payload.i);
    l3 = ((vader_struct_vader_lower_LoweredCellGet_t*) l1)->f_type;
    l4 = vader_midir_fresh_tmp(l0, 1439u, l3);
    l5 = ((vader_struct_vader_lower_LoweredCellGet_t*) l1)->f_span;
    l3 = ((vader_struct_vader_lower_LoweredCellGet_t*) l1)->f_value_type;
    vader_struct_vader_midir_InstrCellGet_t* _a0_obj = (vader_struct_vader_midir_InstrCellGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrCellGet_t));
    vader_obj_header_init(_a0_obj, 949u);
    _a0_obj->f_span = l5;
    _a0_obj->f_dst = l4;
    _a0_obj->f_cell = l2;
    _a0_obj->f_value_type = l3;
    l5 = (void*) _a0_obj;
    vader_midir_emit(l0, vader_ref_box(l5));
    t0 = vader_box_i32(246u, l4);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir_build_cell_new(void* l0, void* l1) {
    int32_t l2, l4;
    vader_box_t l3 = vader_box_null();
    void* l5 = NULL;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l3, &t0 };
    void** gc_raw_roots[3] = { &l0, &l1, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_lower_LoweredCellNew_t*) l1)->f_value;
    l3 = vader_midir_build_expr(l0, l3);
    if (l3.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l2 = ((int32_t) l3.payload.i);
    l3 = ((vader_struct_vader_lower_LoweredCellNew_t*) l1)->f_type;
    l4 = vader_midir_fresh_tmp(l0, 1438u, l3);
    l5 = ((vader_struct_vader_lower_LoweredCellNew_t*) l1)->f_span;
    l3 = ((vader_struct_vader_lower_LoweredCellNew_t*) l1)->f_value_type;
    vader_struct_vader_midir_InstrCellNew_t* _a0_obj = (vader_struct_vader_midir_InstrCellNew_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrCellNew_t));
    vader_obj_header_init(_a0_obj, 950u);
    _a0_obj->f_span = l5;
    _a0_obj->f_dst = l4;
    _a0_obj->f_value = l2;
    _a0_obj->f_value_type = l3;
    l5 = (void*) _a0_obj;
    vader_midir_emit(l0, vader_ref_box(l5));
    t0 = vader_box_i32(246u, l4);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
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
    size_t l7, l8, l16, l17;
    vader_string_t l9 = 0;
    vader_string_t l10 = 0;
    vader_string_t l23 = 0;
    vader_string_t l24 = 0;
    vader_box_t l18 = vader_box_null(), l20 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    int64_t t1;
    void* t2 = NULL;
    vader_box_t* gc_roots[3] = { &l18, &l20, &t0 };
    void** gc_raw_roots[17] = {
        &l0, &l1, &l2, &l3, &l4, &l5, &l6, &l11, &l12, &l13, &l14, &l15, &l19, &l21, &l22, &l25,
        &t2,
    };
    vader_string_t* gc_atom_roots[4] = { &l9, &l10, &l23, &l24 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 17u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_midir_new_project_ctx(l0, l1);
    vader_array_t* _a0_arr = vader_array_new(13u, 0u, 0u, 243u);
    l3 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(21u, 0u, 0u, 254u);
    l4 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(14u, 0u, 7u, 246u);
    l5 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__string__Any_t* _a3_obj = (vader_struct_std_collections_MutableMap__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__Any_t));
    vader_obj_header_init(_a3_obj, 335u);
    _a3_obj->f_ekeys = l3;
    _a3_obj->f_evals = l4;
    _a3_obj->f_index = l5;
    _a3_obj->f_mask = (size_t) 0;
    _a3_obj->f_size = (size_t) 0;
    _a3_obj->f_tombs = (size_t) 0;
    l3 = (void*) _a3_obj;
    l4 = ((vader_struct_vader_lower_LoweredProject_t*) l0)->f_modules;
    l5 = ((vader_struct_std_collections_MutableMap__string__LoweredModule_t*) l4)->f_ekeys;
    l6 = ((vader_struct_std_collections_MutableMap__string__LoweredModule_t*) l4)->f_evals;
    l7 = ((vader_struct_std_collections_MutableMap__string__LoweredModule_t*) l4)->f_size;
    l8 = (size_t) 0;
    while (!((l8 >= l7))) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l8)
        t0 = vader_array_box_slots(_a4_slotarr->buf)[_a4_slotarr->offset + (size_t) l8];
        l9 = t0.payload.s;
        vader_array_t* _a5_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l8)
        l4 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l8);
        l10 = l9;
        l11 = l4;
        t1 = (l8 + INT64_C(1));
        l8 = (size_t) (int64_t) t1;
        vader_array_t* _a6_arr = vader_array_new(104u, 0u, 13u, 918u);
        l12 = (void*) _a6_arr;
        vader_array_t* _a7_arr = vader_array_new(103u, 0u, 13u, 917u);
        l13 = (void*) _a7_arr;
        vader_array_t* _a8_arr = vader_array_new(108u, 0u, 13u, 923u);
        l14 = (void*) _a8_arr;
        l15 = ((vader_struct_vader_lower_LoweredModule_t*) l11)->f_decls;
        l16 = ((vader_array_t*) l15)->length;
        l17 = (size_t) 0;
        while ((l17 < l16)) {
            vader_array_t* _a9_slotarr = ((vader_array_t*) l15);
            VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l17)
            l18 = vader_array_ref_load_box(_a9_slotarr->buf, _a9_slotarr->offset + (size_t) l17);
            if (l18.tag == 876u) {
                t2 = l18.payload.obj;
                if (((vader_struct_vader_lower_LoweredFnDecl_t*) t2)->f_body.tag == 0u) {
                    t2 = l18.payload.obj;
                    l19 = vader_midir_make_extern_decl(t2);
                    vader_array_push((vader_array_t*) l13, vader_ref_box(l19));
                } else {
                    t2 = l18.payload.obj;
                    l20 = vader_midir_convert_function(t2, l2);
                    if (!(l20.tag == 0u)) {
                        l21 = l20.payload.obj;
                        vader_array_push((vader_array_t*) l12, vader_ref_box(l21));
                    }
                }
            } else if (l18.tag == 893u) {
                t2 = l18.payload.obj;
                l22 = vader_midir_make_struct_decl(t2);
                vader_array_push((vader_array_t*) l14, vader_ref_box(l22));
            } else if (!(l18.tag == 868u)) {
                vader_unreachable("non-exhaustive match (T3013 should have caught this)");
            }
            t1 = (l17 + INT64_C(1));
            l17 = (size_t) (int64_t) t1;
        }
        l23 = ((vader_struct_vader_lower_LoweredModule_t*) l11)->f_module_id;
        l24 = ((vader_struct_vader_lower_LoweredModule_t*) l11)->f_display_path;
        vader_struct_vader_midir_CFGModule_t* _a10_obj = (vader_struct_vader_midir_CFGModule_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_CFGModule_t));
        vader_obj_header_init(_a10_obj, 920u);
        _a10_obj->f_module_id = l23;
        _a10_obj->f_display_path = l24;
        _a10_obj->f_functions = l12;
        _a10_obj->f_externs = l13;
        _a10_obj->f_struct_decls = l14;
        l25 = (void*) _a10_obj;
        std_collections_MutableMap_IndexSet_set_at__string__Any(l3, l10, vader_ref_box(l25));
    }
    l4 = ((vader_struct_vader_lower_LoweredProject_t*) l0)->f_vtable_entries;
    l2 = ((vader_struct_vader_midir_ProjectCtx_t*) l2)->f_strings;
    l5 = vader_midir_convert_data_pool(((vader_struct_vader_lower_LoweredProject_t*) l0)->f_data_pool);
    l6 = ((vader_struct_vader_lower_LoweredProject_t*) l0)->f_trait_membership;
    vader_struct_vader_midir_CFGProject_t* _a11_obj = (vader_struct_vader_midir_CFGProject_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_CFGProject_t));
    vader_obj_header_init(_a11_obj, 922u);
    _a11_obj->f_modules = l3;
    _a11_obj->f_vtable_entries = l4;
    _a11_obj->f_strings = l2;
    _a11_obj->f_data_pool = l5;
    _a11_obj->f_trait_membership = l6;
    t2 = (void*) _a11_obj;
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_midir_build_cfg_signature(void* l0, vader_box_t l1, void* l2, void* l3) {
    void* l4 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l11 = NULL;
    void* l16 = NULL;
    size_t l5, l10;
    uint8_t l12;
    int32_t l13;
    vader_string_t l14 = 0;
    bool l15;
    vader_box_t l17 = vader_box_null();
    int64_t t0;
    size_t t1;
    void* t2 = NULL;
    vader_box_t* gc_roots[2] = { &l1, &l17 };
    void** gc_raw_roots[11] = { &l0, &l2, &l3, &l4, &l6, &l7, &l8, &l9, &l11, &l16, &t2 };
    vader_string_t* gc_atom_roots[1] = { &l14 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 11u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(16u, 0u, 1u, 249u);
    l4 = (void*) _a0_arr;
    l5 = ((vader_array_t*) l0)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l4, (size_t) l5);
    l4 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(14u, 0u, 7u, 246u);
    l6 = (void*) _a2_arr;
    l5 = ((vader_array_t*) l0)->length;
    vader_array_t* _a3_arr = vader_array_repeat((vader_array_t*) l6, (size_t) l5);
    l6 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_new(13u, 0u, 0u, 243u);
    l7 = (void*) _a4_arr;
    l5 = ((vader_array_t*) l0)->length;
    vader_array_t* _a5_arr = vader_array_repeat((vader_array_t*) l7, (size_t) l5);
    l7 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(11u, 0u, 12u, 241u);
    l8 = (void*) _a6_arr;
    l5 = ((vader_array_t*) l0)->length;
    vader_array_t* _a7_arr = vader_array_repeat((vader_array_t*) l8, (size_t) l5);
    l8 = (void*) _a7_arr;
    l9 = l0;
    l5 = ((vader_array_t*) l9)->length;
    l10 = (size_t) 0;
    while ((l10 < l5)) {
        vader_array_t* _a8_slotarr = ((vader_array_t*) l9);
        VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l10)
        l11 = vader_array_ref_load_obj(_a8_slotarr->buf, _a8_slotarr->offset + (size_t) l10);
        l12 = vader_bytecode_val_type_of_type(((vader_struct_vader_midir_CFGParam_t*) l11)->f_type);
        vader_array_push_u8((vader_array_t*) l4, (int32_t) (uint8_t) l12);
        l13 = vader_bytecode_intern_type(((vader_struct_vader_midir_CFGParam_t*) l11)->f_type, l3);
        vader_array_push_i32((vader_array_t*) l6, l13);
        l14 = ((vader_struct_vader_midir_CFGParam_t*) l11)->f_name;
        vader_array_push((vader_array_t*) l7, vader_box_string(243u, l14));
        l15 = vader_midir_is_mutable_slot(((vader_struct_vader_midir_CFGParam_t*) l11)->f_type);
        vader_array_push_bool((vader_array_t*) l8, l15);
        t0 = (l10 + INT64_C(1));
        l10 = (size_t) (int64_t) t0;
    }
    vader_array_t* _a9_arr = vader_array_new(16u, 0u, 1u, 249u);
    l9 = (void*) _a9_arr;
    vader_array_t* _a10_arr = vader_array_new(14u, 0u, 7u, 246u);
    l11 = (void*) _a10_arr;
    t1 = ((vader_array_t*) l2)->length;
    if ((t1 > INT64_C(1))) {
        l16 = l2;
        l5 = ((vader_array_t*) l16)->length;
        l10 = (size_t) 0;
        while ((l10 < l5)) {
            vader_array_t* _a11_slotarr = ((vader_array_t*) l16);
            VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l10)
            l17 = vader_array_ref_load_box(_a11_slotarr->buf, _a11_slotarr->offset + (size_t) l10);
            l12 = vader_bytecode_val_type_of_type(l17);
            vader_array_push_u8((vader_array_t*) l9, (int32_t) (uint8_t) l12);
            l13 = vader_bytecode_intern_type(l17, l3);
            vader_array_push_i32((vader_array_t*) l11, l13);
            t0 = (l10 + INT64_C(1));
            l10 = (size_t) (int64_t) t0;
        }
    } else {
        l12 = vader_bytecode_val_type_of_type(l1);
        vader_array_push_u8((vader_array_t*) l9, (int32_t) (uint8_t) l12);
        l13 = vader_bytecode_intern_type(l1, l3);
        vader_array_push_i32((vader_array_t*) l11, l13);
    }
    vader_array_t* _a12_arr = vader_array_new(11u, 0u, 12u, 241u);
    l16 = (void*) _a12_arr;
    vader_struct_vader_bytecode_BcSignature_t* _a13_obj = (vader_struct_vader_bytecode_BcSignature_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcSignature_t));
    vader_obj_header_init(_a13_obj, 559u);
    _a13_obj->f_params = l4;
    _a13_obj->f_results = l9;
    _a13_obj->f_param_types = l6;
    _a13_obj->f_result_types = l11;
    _a13_obj->f_param_names = l7;
    _a13_obj->f_param_mutable = l8;
    _a13_obj->f_param_by_address = l16;
    t2 = (void*) _a13_obj;
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir_build_data_const(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null();
    int32_t l3, l5;
    void* l4 = NULL;
    size_t t0;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l2, &t1 };
    void** gc_raw_roots[3] = { &l0, &l1, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_lower_LoweredDataConst_t*) l1)->f_type;
    l3 = vader_midir_fresh_tmp(l0, 1505u, l2);
    l4 = ((vader_struct_vader_lower_LoweredDataConst_t*) l1)->f_span;
    l2 = ((vader_struct_vader_lower_LoweredDataConst_t*) l1)->f_type;
    t0 = ((vader_struct_vader_lower_LoweredDataConst_t*) l1)->f_pool_index;
    l5 = ((int32_t) (size_t) t0);
    vader_struct_vader_midir_InstrDataConst_t* _a0_obj = (vader_struct_vader_midir_InstrDataConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrDataConst_t));
    vader_obj_header_init(_a0_obj, 953u);
    _a0_obj->f_span = l4;
    _a0_obj->f_dst = l3;
    _a0_obj->f_type = l2;
    _a0_obj->f_pool_index = l5;
    l4 = (void*) _a0_obj;
    vader_midir_emit(l0, vader_ref_box(l4));
    t1 = vader_box_i32(246u, l3);
    { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
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
    vader_box_t t3 = vader_box_null();
    double t4;
    bool t5;
    uint32_t t6;
    vader_box_t* gc_roots[3] = { &l1, &l2, &t3 };
    void** gc_raw_roots[4] = { &l0, &l3, &l4, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l5 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (((vader_struct_vader_midir_FnCtx_t*) l0)->f_current.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    if (l1.tag == 880u) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_vader_lower_LoweredIntLit_t*) t0)->f_type;
        t0 = l1.payload.obj;
        t1 = ((vader_struct_vader_lower_LoweredIntLit_t*) t0)->f_value;
        vader_struct_vader_midir_ConstInt_t* _a0_obj = (vader_struct_vader_midir_ConstInt_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_ConstInt_t));
        vader_obj_header_init(_a0_obj, 929u);
        _a0_obj->f_value = t1;
        l3 = (void*) _a0_obj;
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_lower_LoweredIntLit_t*) t0)->f_span;
        t2 = vader_midir_emit_const(l0, l2, vader_ref_box(l3), l4);
        t3 = vader_box_i32(246u, t2);
        { vader_box_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 875u) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_vader_lower_LoweredFloatLit_t*) t0)->f_type;
        t0 = l1.payload.obj;
        t4 = ((vader_struct_vader_lower_LoweredFloatLit_t*) t0)->f_value;
        vader_struct_vader_midir_ConstFloat_t* _a1_obj = (vader_struct_vader_midir_ConstFloat_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_ConstFloat_t));
        vader_obj_header_init(_a1_obj, 928u);
        _a1_obj->f_value = t4;
        l3 = (void*) _a1_obj;
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_lower_LoweredFloatLit_t*) t0)->f_span;
        t2 = vader_midir_emit_const(l0, l2, vader_ref_box(l3), l4);
        t3 = vader_box_i32(246u, t2);
        { vader_box_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 860u) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_vader_lower_LoweredBoolLit_t*) t0)->f_type;
        t0 = l1.payload.obj;
        t5 = ((vader_struct_vader_lower_LoweredBoolLit_t*) t0)->f_value;
        vader_struct_vader_midir_ConstBool_t* _a2_obj = (vader_struct_vader_midir_ConstBool_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_ConstBool_t));
        vader_obj_header_init(_a2_obj, 926u);
        _a2_obj->f_value = t5;
        l3 = (void*) _a2_obj;
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_lower_LoweredBoolLit_t*) t0)->f_span;
        t2 = vader_midir_emit_const(l0, l2, vader_ref_box(l3), l4);
        t3 = vader_box_i32(246u, t2);
        { vader_box_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 887u) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_vader_lower_LoweredNullLit_t*) t0)->f_type;
        vader_struct_vader_midir_ConstNull_t* _a3_obj = (vader_struct_vader_midir_ConstNull_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_ConstNull_t));
        vader_obj_header_init(_a3_obj, 930u);
        l3 = (void*) _a3_obj;
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_lower_LoweredNullLit_t*) t0)->f_span;
        t2 = vader_midir_emit_const(l0, l2, vader_ref_box(l3), l4);
        t3 = vader_box_i32(246u, t2);
        { vader_box_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 867u) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_vader_lower_LoweredCharLit_t*) t0)->f_type;
        t0 = l1.payload.obj;
        t6 = ((vader_struct_vader_lower_LoweredCharLit_t*) t0)->f_value;
        vader_struct_vader_midir_ConstChar_t* _a4_obj = (vader_struct_vader_midir_ConstChar_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_ConstChar_t));
        vader_obj_header_init(_a4_obj, 927u);
        _a4_obj->f_value = ((int32_t) (uint32_t) t6);
        l3 = (void*) _a4_obj;
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_lower_LoweredCharLit_t*) t0)->f_span;
        t2 = vader_midir_emit_const(l0, l2, vader_ref_box(l3), l4);
        t3 = vader_box_i32(246u, t2);
        { vader_box_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 891u) {
        l3 = ((vader_struct_vader_midir_FnCtx_t*) l0)->f_project;
        t0 = l1.payload.obj;
        l5 = ((vader_struct_vader_lower_LoweredStringLit_t*) t0)->f_value;
        l6 = vader_midir_intern_string_pool(l3, l5);
        t0 = l1.payload.obj;
        l2 = ((vader_struct_vader_lower_LoweredStringLit_t*) t0)->f_type;
        vader_struct_vader_midir_ConstString_t* _a5_obj = (vader_struct_vader_midir_ConstString_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_ConstString_t));
        vader_obj_header_init(_a5_obj, 931u);
        _a5_obj->f_index = l6;
        l3 = (void*) _a5_obj;
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_lower_LoweredStringLit_t*) t0)->f_span;
        t2 = vader_midir_emit_const(l0, l2, vader_ref_box(l3), l4);
        t3 = vader_box_i32(246u, t2);
        { vader_box_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 877u) {
        l3 = l1.payload.obj;
        t3 = vader_midir_build_ident(l0, l3);
        { vader_box_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 862u) {
        l3 = l1.payload.obj;
        t3 = vader_midir_build_call(l0, l3);
        { vader_box_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 901u) {
        l3 = l1.payload.obj;
        t3 = vader_midir_build_virtual_call(l0, l3);
        { vader_box_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 874u) {
        l3 = l1.payload.obj;
        t3 = vader_midir_build_field_access(l0, l3);
        { vader_box_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 879u) {
        l3 = l1.payload.obj;
        t3 = vader_midir_build_index(l0, l3);
        { vader_box_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 899u) {
        l3 = l1.payload.obj;
        t3 = vader_midir_build_unary(l0, l3);
        { vader_box_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 858u) {
        l3 = l1.payload.obj;
        t3 = vader_midir_build_binary(l0, l3);
        { vader_box_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 878u) {
        l3 = l1.payload.obj;
        t3 = vader_midir_build_if(l0, l3, vader_box_obj(0u, NULL));
        { vader_box_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 859u) {
        l3 = l1.payload.obj;
        t3 = vader_midir_build_block_body(l0, l3);
        { vader_box_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 895u) {
        l3 = l1.payload.obj;
        t3 = vader_midir_build_struct_lit(l0, l3);
        { vader_box_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 853u) {
        l3 = l1.payload.obj;
        t3 = vader_midir_build_array_lit(l0, l3);
        { vader_box_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 863u) {
        l3 = l1.payload.obj;
        t3 = vader_midir_build_cast(l0, l3);
        { vader_box_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 897u) {
        l3 = l1.payload.obj;
        t3 = vader_midir_build_type_check(l0, l3);
        { vader_box_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 900u) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_vader_lower_LoweredUnreachable_t*) t0)->f_type;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_lower_LoweredUnreachable_t*) t0)->f_span;
        t0 = l1.payload.obj;
        l5 = ((vader_struct_vader_lower_LoweredUnreachable_t*) t0)->f_reason;
        t3 = vader_midir_build_unreachable_type(l0, l2, l3, l5);
        { vader_box_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 881u) {
        l3 = l1.payload.obj;
        t3 = vader_midir_build_intrinsic_call(l0, l3);
        { vader_box_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 852u) {
        l3 = l1.payload.obj;
        t3 = vader_midir_build_array_len(l0, l3);
        { vader_box_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 854u) {
        l3 = l1.payload.obj;
        t3 = vader_midir_build_array_push(l0, l3);
        { vader_box_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 855u) {
        l3 = l1.payload.obj;
        t3 = vader_midir_build_array_slice(l0, l3);
        { vader_box_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 892u) {
        l3 = l1.payload.obj;
        t3 = vader_midir_build_string_slice(l0, l3);
        { vader_box_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 865u) {
        l3 = l1.payload.obj;
        t3 = vader_midir_build_cell_new(l0, l3);
        { vader_box_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 864u) {
        l3 = l1.payload.obj;
        t3 = vader_midir_build_cell_get(l0, l3);
        { vader_box_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 885u) {
        l3 = l1.payload.obj;
        t3 = vader_midir_build_make_closure(l0, l3);
        { vader_box_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 870u) {
        l3 = l1.payload.obj;
        t3 = vader_midir_build_data_const(l0, l3);
        { vader_box_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l1.tag == 898u)) {
        vader_unreachable("non-exhaustive match (T3013 should have caught this)");
    }
    l3 = l1.payload.obj;
    t3 = vader_midir_build_type_const(l0, l3);
    { vader_box_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_midir_build_expr_into(void* l0, vader_box_t l1, int32_t l2) {
    void* l3 = NULL;
    vader_box_t l4 = vader_box_null();
    int32_t l5;
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    bool t2;
    vader_box_t* gc_roots[3] = { &l1, &l4, &t0 };
    void** gc_raw_roots[3] = { &l0, &l3, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l1.tag == 878u) {
        l3 = l1.payload.obj;
        t0 = vader_box_i32(246u, l2);
        vader_midir_build_if(l0, l3, t0);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 859u) {
        l3 = l1.payload.obj;
        vader_midir_build_block_into(l0, l3, l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 858u) {
        t1 = l1.payload.obj;
        t2 = vader_midir_is_short_circuit_op(((vader_struct_vader_lower_LoweredBinary_t*) t1)->f_op);
        if (t2) {
            l3 = l1.payload.obj;
            t0 = vader_box_i32(246u, l2);
            vader_midir_build_short_circuit(l0, l3, t0);
            { vader_gc_top = gc_frame.prev; return; }
        }
    }
    l4 = l1;
    l4 = vader_midir_build_expr(l0, l4);
    if (((vader_struct_vader_midir_FnCtx_t*) l0)->f_current.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l4.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l3 = vader_lower_span_of(l1);
    l5 = ((int32_t) l4.payload.i);
    vader_struct_vader_midir_InstrMove_t* _a0_obj = (vader_struct_vader_midir_InstrMove_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrMove_t));
    vader_obj_header_init(_a0_obj, 962u);
    _a0_obj->f_span = l3;
    _a0_obj->f_dst = l2;
    _a0_obj->f_src = l5;
    l3 = (void*) _a0_obj;
    vader_midir_emit(l0, vader_ref_box(l3));
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_midir_build_extern_args(void* l0, void* l1, void* l2, vader_string_t l3) {
    void* l4 = NULL;
    void* l12 = NULL;
    void* l20 = NULL;
    void* l23 = NULL;
    void* l25 = NULL;
    void* l26 = NULL;
    void* l28 = NULL;
    size_t l5, l6, l11, l13, l17, l18, l19, l21;
    vader_box_t l7 = vader_box_null(), l9 = vader_box_null(), l27 = vader_box_null();
    int32_t l8, l24;
    vader_string_t l10 = 0;
    vader_string_t l15 = 0;
    vader_string_t l16 = 0;
    uint64_t l14, l22;
    bool t0;
    int64_t t1;
    vader_string_t t2 = 0;
    void* t3 = NULL;
    vader_box_t* gc_roots[3] = { &l7, &l9, &l27 };
    void** gc_raw_roots[11] = { &l0, &l1, &l2, &l4, &l12, &l20, &l23, &l25, &l26, &l28, &t3 };
    vader_string_t* gc_atom_roots[5] = { &l3, &l10, &l15, &l16, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 11u, gc_roots, gc_raw_roots, 0u, NULL, 5u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(14u, 0u, 7u, 246u);
    l4 = (void*) _a0_arr;
    l5 = (size_t) 0;
    l6 = ((vader_array_t*) l1)->length;
    for (;;) {
        if ((l5 < l6)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
            l7 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5);
            t0 = std_collections_MutableSet_Contains_contains__usize(l2, l5);
            if (t0) {
                if (!(l7.tag == 877u)) {
                    l10 = l3;
                    l11 = vader_host_std_core_byte_len(l10);
                    l12 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(130) + l11));
                    l13 = (size_t) 0;
                    l13 = std_core_write_string_at(l12, l13, 1980u);
                    t1 = (l5 + INT64_C(1));
                    l14 = (uint64_t) (int64_t) t1;
                    l13 = std_core_write_unsigned(l12, l13, l14);
                    l13 = std_core_write_string_at(l12, l13, 109u);
                    l13 = std_core_write_string_at(l12, l13, l10);
                    l13 = std_core_write_string_at(l12, l13, 934u);
                    t2 = std_core_finish_buffer(l12, l13);
                    vader_host_std_abort_panic(t2);
                    vader_unreachable("a no-return call returned");
                }
                t3 = l7.payload.obj;
                if (((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_lower_LoweredIdent_t*) t3)->f_symbol)->f_kind != INT32_C(0)) {
                    l15 = l3;
                    t3 = l7.payload.obj;
                    l16 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_lower_LoweredIdent_t*) t3)->f_symbol)->f_name;
                    l17 = vader_host_std_core_byte_len(l15);
                    l18 = vader_host_std_core_byte_len(l16);
                    t1 = (l17 + l18);
                    l19 = (size_t) (int64_t) t1;
                    l20 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(127) + l19));
                    l21 = (size_t) 0;
                    l21 = std_core_write_string_at(l20, l21, 1980u);
                    t1 = (l5 + INT64_C(1));
                    l22 = (uint64_t) (int64_t) t1;
                    l21 = std_core_write_unsigned(l20, l21, l22);
                    l21 = std_core_write_string_at(l20, l21, 109u);
                    l21 = std_core_write_string_at(l20, l21, l15);
                    l21 = std_core_write_string_at(l20, l21, 983u);
                    l21 = std_core_write_string_at(l20, l21, l16);
                    l21 = std_core_write_string_at(l20, l21, 1078u);
                    t2 = std_core_finish_buffer(l20, l21);
                    vader_host_std_abort_panic(t2);
                    vader_unreachable("a no-return call returned");
                } else {
                    t3 = (void*) &vader_data_32;
                    vader_array_t* _a2_slotarr = ((vader_array_t*) t3);
                    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                    l23 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) INT64_C(0));
                    l24 = vader_midir_fresh_tmp(l0, 1689u, vader_ref_box(l23));
                    t3 = l7.payload.obj;
                    l25 = ((vader_struct_vader_lower_LoweredIdent_t*) t3)->f_span;
                    t3 = l7.payload.obj;
                    l26 = ((vader_struct_vader_lower_LoweredIdent_t*) t3)->f_symbol;
                    t3 = l7.payload.obj;
                    l27 = ((vader_struct_vader_lower_LoweredIdent_t*) t3)->f_type;
                    vader_struct_vader_midir_InstrFnAddr_t* _a3_obj = (vader_struct_vader_midir_InstrFnAddr_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrFnAddr_t));
                    vader_obj_header_init(_a3_obj, 958u);
                    _a3_obj->f_span = l25;
                    _a3_obj->f_dst = l24;
                    _a3_obj->f_fn_symbol = l26;
                    _a3_obj->f_type = l27;
                    l28 = (void*) _a3_obj;
                    vader_midir_emit(l0, vader_ref_box(l28));
                    vader_array_push_i32((vader_array_t*) l4, l24);
                    t1 = (l5 + INT64_C(1));
                    l5 = (size_t) (int64_t) t1;
                    continue;
                }
            } else {
                l9 = vader_midir_build_expr(l0, l7);
                if (l9.tag == 0u) {
                    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
                }
                l8 = ((int32_t) l9.payload.i);
                vader_array_push_i32((vader_array_t*) l4, l8);
                t1 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t1;
                continue;
            }
        }
        break;
    }
    { vader_box_t __vret = vader_ref_box(l4); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir_build_field_access(void* l0, void* l1) {
    int32_t l2, l4;
    vader_box_t l3 = vader_box_null();
    void* l5 = NULL;
    vader_string_t l6 = 0;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l3, &t0 };
    void** gc_raw_roots[3] = { &l0, &l1, &l5 };
    vader_string_t* gc_atom_roots[1] = { &l6 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_lower_LoweredFieldAccess_t*) l1)->f_target;
    l3 = vader_midir_build_expr(l0, l3);
    if (l3.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l2 = ((int32_t) l3.payload.i);
    l3 = ((vader_struct_vader_lower_LoweredFieldAccess_t*) l1)->f_type;
    l4 = vader_midir_fresh_tmp(l0, 1657u, l3);
    l5 = ((vader_struct_vader_lower_LoweredFieldAccess_t*) l1)->f_span;
    l6 = ((vader_struct_vader_lower_LoweredFieldAccess_t*) l1)->f_field;
    l3 = ((vader_struct_vader_lower_LoweredFieldAccess_t*) l1)->f_type;
    vader_struct_vader_midir_InstrFieldGet_t* _a0_obj = (vader_struct_vader_midir_InstrFieldGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrFieldGet_t));
    vader_obj_header_init(_a0_obj, 956u);
    _a0_obj->f_span = l5;
    _a0_obj->f_dst = l4;
    _a0_obj->f_target = l2;
    _a0_obj->f_field = l6;
    _a0_obj->f_type = l3;
    l5 = (void*) _a0_obj;
    vader_midir_emit(l0, vader_ref_box(l5));
    t0 = vader_box_i32(246u, l4);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir_build_ident(void* l0, void* l1) {
    void* l2 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    int32_t l3, l7, l11;
    vader_box_t l4 = vader_box_null(), l6 = vader_box_null(), l10 = vader_box_null(), l12 = vader_box_null();
    size_t l5;
    vader_string_t l15 = 0;
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    int32_t t2;
    int64_t t3;
    bool t4;
    vader_box_t* gc_roots[5] = { &l4, &l6, &l10, &l12, &t0 };
    void** gc_raw_roots[8] = { &l0, &l1, &l2, &l8, &l9, &l13, &l14, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l15 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 5u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_midir_FnCtx_t*) l0)->f_local_by_sym_id;
    l3 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_lower_LoweredIdent_t*) l1)->f_symbol)->f_id;
    l4 = std_collections_MutableMap_Index_at__i32__i32(l2, l3);
    if (l4.tag == 0u) {
        if (((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_lower_LoweredIdent_t*) l1)->f_symbol)->f_kind == INT32_C(0)) {
            l6 = ((vader_struct_vader_lower_LoweredIdent_t*) l1)->f_type;
            l7 = vader_midir_fresh_tmp(l0, 1690u, l6);
            l8 = ((vader_struct_vader_lower_LoweredIdent_t*) l1)->f_span;
            l9 = ((vader_struct_vader_lower_LoweredIdent_t*) l1)->f_symbol;
            l10 = ((vader_struct_vader_lower_LoweredIdent_t*) l1)->f_type;
            vader_struct_vader_midir_InstrFnRef_t* _a0_obj = (vader_struct_vader_midir_InstrFnRef_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrFnRef_t));
            vader_obj_header_init(_a0_obj, 959u);
            _a0_obj->f_span = l8;
            _a0_obj->f_dst = l7;
            _a0_obj->f_fn_symbol = l9;
            _a0_obj->f_type = l10;
            l8 = (void*) _a0_obj;
            vader_midir_emit(l0, vader_ref_box(l8));
            t0 = vader_box_i32(246u, l7);
            { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l8 = ((vader_struct_vader_midir_ProjectCtx_t*) ((vader_struct_vader_midir_FnCtx_t*) l0)->f_project)->f_const_fn_wrap;
        l11 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_lower_LoweredIdent_t*) l1)->f_symbol)->f_id;
        l10 = std_collections_MutableMap_Index_at__i32__Any(l8, l11);
        if (l10.tag == 825u) {
            t1 = l10.payload.obj;
            l12 = ((vader_struct_vader_lower_ConstFnWrap_t*) t1)->f_call_type;
            l11 = vader_midir_fresh_tmp(l0, 1488u, l12);
            vader_array_t* _a1_arr = vader_array_new(14u, 0u, 7u, 246u);
            l8 = (void*) _a1_arr;
            l9 = ((vader_struct_vader_lower_LoweredIdent_t*) l1)->f_span;
            vader_array_t* _a2_arr = vader_array_new(14u, 1u, 7u, 246u);
            ((int32_t*) _a2_arr->buf->slots)[_a2_arr->offset + 0u] = (int32_t) l11;
            l13 = (void*) _a2_arr;
            t1 = l10.payload.obj;
            l14 = ((vader_struct_vader_lower_ConstFnWrap_t*) t1)->f_fn_symbol;
            t1 = l10.payload.obj;
            l10 = ((vader_struct_vader_lower_ConstFnWrap_t*) t1)->f_call_type;
            vader_struct_vader_midir_InstrCall_t* _a3_obj = (vader_struct_vader_midir_InstrCall_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrCall_t));
            vader_obj_header_init(_a3_obj, 946u);
            _a3_obj->f_span = l9;
            _a3_obj->f_dsts = l13;
            _a3_obj->f_callee = l14;
            _a3_obj->f_args = l8;
            _a3_obj->f_type = l10;
            l8 = (void*) _a3_obj;
            vader_midir_emit(l0, vader_ref_box(l8));
            t0 = vader_box_i32(246u, l11);
            { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l8 = ((vader_struct_vader_midir_ProjectCtx_t*) ((vader_struct_vader_midir_FnCtx_t*) l0)->f_project)->f_const_inline;
        l11 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_lower_LoweredIdent_t*) l1)->f_symbol)->f_id;
        l10 = std_collections_MutableMap_Index_at__i32__Any(l8, l11);
        if (!(l10.tag == 0u)) {
            t0 = vader_midir_build_expr(l0, l10);
            { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l8 = ((vader_struct_vader_midir_ProjectCtx_t*) ((vader_struct_vader_midir_FnCtx_t*) l0)->f_project)->f_diags;
        l9 = ((vader_struct_vader_lower_LoweredIdent_t*) l1)->f_span;
        l15 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_lower_LoweredIdent_t*) l1)->f_symbol)->f_name;
        l15 = concat_3(860u, l15, 1005u);
        l9 = vader_diagnostics_lower_error((uint8_t) 6, l9, l15);
        vader_array_push((vader_array_t*) l8, vader_ref_box(l9));
        l10 = ((vader_struct_vader_lower_LoweredIdent_t*) l1)->f_type;
        l8 = ((vader_struct_vader_lower_LoweredIdent_t*) l1)->f_span;
        l15 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_lower_LoweredIdent_t*) l1)->f_symbol)->f_name;
        l15 = concat_2(2448u, l15);
        t0 = vader_midir_build_unreachable_type(l0, l10, l8, l15);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = ((vader_struct_vader_midir_FnCtx_t*) l0)->f_locals;
    t2 = ((int32_t) l4.payload.i);
    t3 = ((int64_t) (int32_t) t2);
    l5 = (size_t) (int64_t) t3;
    vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l5)
    t1 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l5);
    l6 = ((vader_struct_vader_midir_CFGLocal_t*) t1)->f_type;
    if (l6.tag == 1093u) {
        l2 = l6.payload.obj;
        l6 = ((vader_struct_vader_lower_LoweredIdent_t*) l1)->f_type;
        t4 = vader_typecheck_equals_type(vader_ref_box(l2), l6);
        if (!(t4)) {
            l6 = ((vader_struct_vader_lower_LoweredIdent_t*) l1)->f_type;
            l3 = vader_midir_fresh_tmp(l0, 2018u, l6);
            l2 = ((vader_struct_vader_lower_LoweredIdent_t*) l1)->f_span;
            l7 = ((int32_t) l4.payload.i);
            l6 = ((vader_struct_vader_lower_LoweredIdent_t*) l1)->f_type;
            vader_struct_vader_midir_InstrCast_t* _a5_obj = (vader_struct_vader_midir_InstrCast_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrCast_t));
            vader_obj_header_init(_a5_obj, 948u);
            _a5_obj->f_span = l2;
            _a5_obj->f_dst = l3;
            _a5_obj->f_value = l7;
            _a5_obj->f_type = l6;
            l2 = (void*) _a5_obj;
            vader_midir_emit(l0, vader_ref_box(l2));
            t0 = vader_box_i32(246u, l3);
            { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        t2 = ((int32_t) l4.payload.i);
        t0 = vader_box_i32(246u, t2);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = ((int32_t) l4.payload.i);
    t0 = vader_box_i32(246u, t2);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
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
    vader_box_t t3 = vader_box_null();
    vader_box_t* gc_roots[5] = { &l2, &l3, &l4, &l11, &t3 };
    void** gc_raw_roots[5] = { &l0, &l1, &l5, &l12, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 5u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l2.tag == 0u) {
        t0 = vader_typecheck_is_void(((vader_struct_vader_lower_LoweredIf_t*) l1)->f_type);
        if (t0) {
            l3 = vader_box_obj(0u, NULL);
        } else {
            l4 = ((vader_struct_vader_lower_LoweredIf_t*) l1)->f_type;
            t1 = vader_midir_declare_local(l0, 1802u, l4, vader_box_obj(0u, NULL));
            l3 = vader_box_i32(246u, t1);
        }
    } else {
        t1 = ((int32_t) l2.payload.i);
        l3 = vader_box_i32(246u, t1);
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
        t3 = vader_box_i32(246u, l6);
        ((vader_struct_vader_midir_FnCtx_t*) l0)->f_current = t3;
        VADER_WRITE_BARRIER((vader_struct_vader_midir_FnCtx_t*) l0);
        l12 = ((vader_struct_vader_lower_LoweredIf_t*) l1)->f_then_block;
        vader_midir_build_if_arm(l0, l12, l3);
        vader_struct_vader_midir_TermBranch_t* _a0_obj = (vader_struct_vader_midir_TermBranch_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_TermBranch_t));
        vader_obj_header_init(_a0_obj, 978u);
        _a0_obj->f_span = ((vader_struct_vader_lower_LoweredBlock_t*) ((vader_struct_vader_lower_LoweredIf_t*) l1)->f_then_block)->f_span;
        _a0_obj->f_target = l7;
        l12 = (void*) _a0_obj;
        vader_midir_terminate(l0, vader_ref_box(l12));
    }
    if (l4.tag == 0u) {
        t3 = vader_box_i32(246u, l7);
        ((vader_struct_vader_midir_FnCtx_t*) l0)->f_current = t3;
        VADER_WRITE_BARRIER((vader_struct_vader_midir_FnCtx_t*) l0);
        { vader_box_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_vader_midir_CondReach_t*) l5)->f_on_false;
    if (t0) {
        t3 = vader_box_i32(246u, l8);
        ((vader_struct_vader_midir_FnCtx_t*) l0)->f_current = t3;
        VADER_WRITE_BARRIER((vader_struct_vader_midir_FnCtx_t*) l0);
        l5 = l4.payload.obj;
        vader_midir_build_if_arm(l0, l5, l3);
        t2 = l4.payload.obj;
        vader_struct_vader_midir_TermBranch_t* _a1_obj = (vader_struct_vader_midir_TermBranch_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_TermBranch_t));
        vader_obj_header_init(_a1_obj, 978u);
        _a1_obj->f_span = ((vader_struct_vader_lower_LoweredBlock_t*) t2)->f_span;
        _a1_obj->f_target = l7;
        l5 = (void*) _a1_obj;
        vader_midir_terminate(l0, vader_ref_box(l5));
        t3 = vader_box_i32(246u, l7);
        ((vader_struct_vader_midir_FnCtx_t*) l0)->f_current = t3;
        VADER_WRITE_BARRIER((vader_struct_vader_midir_FnCtx_t*) l0);
        { vader_box_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t3 = vader_box_i32(246u, l7);
    ((vader_struct_vader_midir_FnCtx_t*) l0)->f_current = t3;
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
    void* l14 = NULL;
    void* l19 = NULL;
    void* l23 = NULL;
    size_t l7, l8, l12, l13, l15, l18, l20;
    vader_string_t l9 = 0;
    vader_string_t l16 = 0;
    vader_string_t l17 = 0;
    vader_string_t l22 = 0;
    vader_box_t l10 = vader_box_null();
    int32_t l11;
    int64_t l21;
    uint64_t l24;
    int64_t t0;
    vader_box_t t1 = vader_box_null();
    void* t2 = NULL;
    vader_box_t* gc_roots[2] = { &l10, &t1 };
    void** gc_raw_roots[11] = { &l0, &l1, &l2, &l3, &l4, &l5, &l6, &l14, &l19, &l23, &t2 };
    vader_string_t* gc_atom_roots[4] = { &l9, &l16, &l17, &l22 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 11u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(48u, 0u, 13u, 654u);
    l3 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(13u, 0u, 0u, 243u);
    l4 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(11u, 0u, 12u, 241u);
    l5 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(14u, 0u, 7u, 246u);
    l6 = (void*) _a3_arr;
    vader_struct_std_collections_MutableMap__string__bool_t* _a4_obj = (vader_struct_std_collections_MutableMap__string__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__bool_t));
    vader_obj_header_init(_a4_obj, 383u);
    _a4_obj->f_ekeys = l4;
    _a4_obj->f_evals = l5;
    _a4_obj->f_index = l6;
    _a4_obj->f_mask = (size_t) 0;
    _a4_obj->f_size = (size_t) 0;
    _a4_obj->f_tombs = (size_t) 0;
    l4 = (void*) _a4_obj;
    l5 = l0;
    l7 = ((vader_array_t*) l5)->length;
    l8 = (size_t) 0;
    while ((l8 < l7)) {
        vader_array_t* _a5_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l8)
        l6 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l8);
        l9 = vader_bytecode_type_intern_key(((vader_struct_vader_lower_LoweredVtableEntry_t*) l6)->f_struct_type);
        l10 = std_collections_MutableMap_Index_at__string__i32(((vader_struct_vader_bytecode_EmitterCtx_t*) l2)->f_type_key, l9);
        if (l10.tag == 246u) {
            l11 = ((int32_t) l10.payload.i);
            t0 = ((int64_t) (int32_t) l11);
            l12 = (size_t) (int64_t) t0;
            l13 = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l2)->f_types)->length;
            if ((l12 < l13)) {
                l14 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l2)->f_types;
                t0 = ((int64_t) (int32_t) l11);
                l15 = (size_t) (int64_t) t0;
                vader_array_t* _a6_slotarr = ((vader_array_t*) l14);
                VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l15)
                t1 = vader_array_ref_load_box(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l15);
                if (!(t1.tag == 561u)) {
                    t0 = (l8 + INT64_C(1));
                    l8 = (size_t) (int64_t) t0;
                    continue;
                }
            }
            l17 = ((vader_struct_vader_lower_LoweredVtableEntry_t*) l6)->f_trait_name;
            l18 = vader_host_std_core_byte_len(l17);
            l19 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(21) + l18));
            l20 = (size_t) 0;
            l21 = ((int64_t) (int32_t) l11);
            l20 = std_core_write_int(l19, l20, l21);
            l20 = std_core_write_string_at(l19, l20, 2649u);
            l20 = std_core_write_string_at(l19, l20, l17);
            l16 = std_core_finish_buffer(l19, l20);
            t1 = std_collections_MutableMap_Index_at__string__bool(l4, l16);
            if (t1.tag == 241u) {
                t0 = (l8 + INT64_C(1));
                l8 = (size_t) (int64_t) t0;
                continue;
            }
            std_collections_MutableMap_IndexSet_set_at__string__bool(l4, l16, true);
            l22 = ((vader_struct_vader_lower_LoweredVtableEntry_t*) l6)->f_trait_name;
            vader_struct_vader_bytecode_ImplEntry_t* _a7_obj = (vader_struct_vader_bytecode_ImplEntry_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_ImplEntry_t));
            vader_obj_header_init(_a7_obj, 654u);
            _a7_obj->f_struct_type_index = l11;
            _a7_obj->f_trait_name = l22;
            l23 = (void*) _a7_obj;
            vader_array_push((vader_array_t*) l3, vader_ref_box(l23));
            t0 = (l8 + INT64_C(1));
            l8 = (size_t) (int64_t) t0;
            continue;
        }
        t0 = (l8 + INT64_C(1));
        l8 = (size_t) (int64_t) t0;
    }
    l7 = (size_t) 0;
    l8 = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l2)->f_types)->length;
    while ((l7 < l8)) {
        vader_array_t* _a8_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l2)->f_types);
        VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l7)
        t1 = vader_array_ref_load_box(_a8_slotarr->buf, _a8_slotarr->offset + (size_t) l7);
        if (t1.tag == 561u) {
            vader_array_t* _a9_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l2)->f_types);
            VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l7)
            t1 = vader_array_ref_load_box(_a9_slotarr->buf, _a9_slotarr->offset + (size_t) l7);
            t2 = t1.payload.obj;
            l11 = ((vader_struct_vader_bytecode_BcStruct_t*) t2)->f_symbol_id;
            l10 = std_collections_MutableMap_Index_at__i32__Any(l1, l11);
            if (l10.tag == 0u) {
                t0 = (l7 + INT64_C(1));
                l7 = (size_t) (int64_t) t0;
                continue;
            }
            l5 = l10.payload.obj;
            l12 = ((vader_array_t*) l5)->length;
            l13 = (size_t) 0;
            while ((l13 < l12)) {
                vader_array_t* _a10_slotarr = ((vader_array_t*) l5);
                VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a10_slotarr, l13)
                t1 = vader_array_box_slots(_a10_slotarr->buf)[_a10_slotarr->offset + (size_t) l13];
                l9 = t1.payload.s;
                l17 = l9;
                l15 = vader_host_std_core_byte_len(l17);
                l6 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(21) + l15));
                l18 = (size_t) 0;
                t0 = ((int64_t) (size_t) l7);
                l24 = (uint64_t) (int64_t) t0;
                l18 = std_core_write_unsigned(l6, l18, l24);
                l18 = std_core_write_string_at(l6, l18, 2649u);
                l18 = std_core_write_string_at(l6, l18, l17);
                l16 = std_core_finish_buffer(l6, l18);
                t1 = std_collections_MutableMap_Index_at__string__bool(l4, l16);
                if (t1.tag == 241u) {
                    t0 = (l13 + INT64_C(1));
                    l13 = (size_t) (int64_t) t0;
                    continue;
                }
                std_collections_MutableMap_IndexSet_set_at__string__bool(l4, l16, true);
                vader_struct_vader_bytecode_ImplEntry_t* _a11_obj = (vader_struct_vader_bytecode_ImplEntry_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_ImplEntry_t));
                vader_obj_header_init(_a11_obj, 654u);
                _a11_obj->f_struct_type_index = ((int32_t) (size_t) l7);
                _a11_obj->f_trait_name = l9;
                l14 = (void*) _a11_obj;
                vader_array_push((vader_array_t*) l3, vader_ref_box(l14));
                t0 = (l13 + INT64_C(1));
                l13 = (size_t) (int64_t) t0;
            }
        }
        t0 = (l7 + INT64_C(1));
        l7 = (size_t) (int64_t) t0;
    }
    { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir_build_index(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l3 = vader_box_null(), l4 = vader_box_null();
    int32_t l5, l7, l8;
    void* l6 = NULL;
    bool l9;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[4] = { &l2, &l3, &l4, &t0 };
    void** gc_raw_roots[3] = { &l0, &l1, &l6 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
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
        l5 = vader_midir_fresh_tmp(l0, 1797u, l4);
        l6 = ((vader_struct_vader_lower_LoweredIndex_t*) l1)->f_span;
        l7 = ((int32_t) l2.payload.i);
        l8 = ((int32_t) l3.payload.i);
        l2 = ((vader_struct_vader_lower_LoweredIndex_t*) l1)->f_type;
        l9 = ((vader_struct_vader_lower_LoweredIndex_t*) l1)->f_bounds_safe;
        vader_struct_vader_midir_InstrArrayGet_t* _a0_obj = (vader_struct_vader_midir_InstrArrayGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrArrayGet_t));
        vader_obj_header_init(_a0_obj, 939u);
        _a0_obj->f_span = l6;
        _a0_obj->f_dst = l5;
        _a0_obj->f_target = l7;
        _a0_obj->f_index = l8;
        _a0_obj->f_type = l2;
        _a0_obj->f_bounds_safe = l9;
        l6 = (void*) _a0_obj;
        vader_midir_emit(l0, vader_ref_box(l6));
        t0 = vader_box_i32(246u, l5);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static vader_box_t vader_midir_build_intrinsic_call(void* l0, void* l1) {
    void* l2 = NULL;
    void* l5 = NULL;
    vader_box_t l3 = vader_box_null(), l4 = vader_box_null();
    vader_string_t l6 = 0;
    bool t0;
    int32_t t1;
    vader_box_t* gc_roots[2] = { &l3, &l4 };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &l5 };
    vader_string_t* gc_atom_roots[1] = { &l6 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_lower_LoweredIntrinsicCall_t*) l1)->f_args;
    l3 = vader_midir_build_args(l0, l2);
    if (l3.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l2 = l3.payload.obj;
    t0 = vader_typecheck_is_void(((vader_struct_vader_lower_LoweredIntrinsicCall_t*) l1)->f_type);
    if (t0) {
        l3 = vader_box_obj(0u, NULL);
    } else {
        l4 = ((vader_struct_vader_lower_LoweredIntrinsicCall_t*) l1)->f_type;
        t1 = vader_midir_fresh_tmp(l0, 1855u, l4);
        l3 = vader_box_i32(246u, t1);
    }
    l5 = ((vader_struct_vader_lower_LoweredIntrinsicCall_t*) l1)->f_span;
    l6 = ((vader_struct_vader_lower_LoweredIntrinsicCall_t*) l1)->f_name;
    vader_struct_vader_midir_InstrIntrinsic_t* _a0_obj = (vader_struct_vader_midir_InstrIntrinsic_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrIntrinsic_t));
    vader_obj_header_init(_a0_obj, 960u);
    _a0_obj->f_span = l5;
    _a0_obj->f_dst = l3;
    _a0_obj->f_name = l6;
    _a0_obj->f_args = l2;
    l2 = (void*) _a0_obj;
    vader_midir_emit(l0, vader_ref_box(l2));
    { vader_box_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
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
        vader_obj_header_init(_a0_obj, 978u);
        _a0_obj->f_span = ((vader_struct_vader_lower_LoweredLabelledBlock_t*) l1)->f_span;
        _a0_obj->f_target = l3;
        l2 = (void*) _a0_obj;
        vader_midir_terminate(l0, vader_ref_box(l2));
    }
    l2 = ((vader_struct_vader_midir_FnCtx_t*) l0)->f_loop_stack;
    l5 = ((vader_struct_vader_lower_LoweredLabelledBlock_t*) l1)->f_label;
    vader_array_t* _a1_arr = vader_array_new(201u, 0u, 13u, 1471u);
    l6 = (void*) _a1_arr;
    t0 = vader_box_string(243u, l5);
    vader_struct_vader_midir_LoopFrame_t* _a2_obj = (vader_struct_vader_midir_LoopFrame_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_LoopFrame_t));
    vader_obj_header_init(_a2_obj, 970u);
    _a2_obj->f_label = t0;
    _a2_obj->f_header_id = l4;
    _a2_obj->f_exit_id = l4;
    _a2_obj->f_step = l6;
    _a2_obj->f_block = true;
    l6 = (void*) _a2_obj;
    vader_array_push((vader_array_t*) l2, vader_ref_box(l6));
    t0 = vader_box_i32(246u, l3);
    ((vader_struct_vader_midir_FnCtx_t*) l0)->f_current = t0;
    VADER_WRITE_BARRIER((vader_struct_vader_midir_FnCtx_t*) l0);
    l2 = ((vader_struct_vader_lower_LoweredLabelledBlock_t*) l1)->f_body;
    vader_midir_build_block_body(l0, l2);
    if (!(((vader_struct_vader_midir_FnCtx_t*) l0)->f_current.tag == 0u)) {
        vader_struct_vader_midir_TermBranch_t* _a3_obj = (vader_struct_vader_midir_TermBranch_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_TermBranch_t));
        vader_obj_header_init(_a3_obj, 978u);
        _a3_obj->f_span = ((vader_struct_vader_lower_LoweredLabelledBlock_t*) l1)->f_span;
        _a3_obj->f_target = l4;
        l2 = (void*) _a3_obj;
        vader_midir_terminate(l0, vader_ref_box(l2));
    }
    t0 = vader_array_remove_last((vader_array_t*) ((vader_struct_vader_midir_FnCtx_t*) l0)->f_loop_stack);
    t0 = vader_box_i32(246u, l4);
    ((vader_struct_vader_midir_FnCtx_t*) l0)->f_current = t0;
    VADER_WRITE_BARRIER((vader_struct_vader_midir_FnCtx_t*) l0);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_midir_build_loop(void* l0, void* l1) {
    void* l2 = NULL;
    void* l8 = NULL;
    int32_t l3, l4, l6;
    vader_box_t l5 = vader_box_null();
    bool l7;
    size_t l9, l10;
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    int32_t t2;
    bool t3;
    size_t t4;
    int64_t t5;
    vader_box_t* gc_roots[2] = { &l5, &t0 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l8, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_lower_LoweredLoop_t*) l1)->f_span;
    l3 = vader_midir_new_block(l0, l2);
    l2 = ((vader_struct_vader_lower_LoweredLoop_t*) l1)->f_span;
    l4 = vader_midir_new_block(l0, l2);
    if (!(((vader_struct_vader_midir_FnCtx_t*) l0)->f_current.tag == 0u)) {
        vader_struct_vader_midir_TermBranch_t* _a0_obj = (vader_struct_vader_midir_TermBranch_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_TermBranch_t));
        vader_obj_header_init(_a0_obj, 978u);
        _a0_obj->f_span = ((vader_struct_vader_lower_LoweredLoop_t*) l1)->f_span;
        _a0_obj->f_target = l3;
        l2 = (void*) _a0_obj;
        vader_midir_terminate(l0, vader_ref_box(l2));
    }
    t0 = vader_box_i32(246u, l3);
    ((vader_struct_vader_midir_FnCtx_t*) l0)->f_current = t0;
    VADER_WRITE_BARRIER((vader_struct_vader_midir_FnCtx_t*) l0);
    l5 = ((vader_struct_vader_lower_LoweredLoop_t*) l1)->f_cond;
    if (!(l5.tag == 0u)) {
        l2 = ((vader_struct_vader_lower_LoweredBlock_t*) ((vader_struct_vader_lower_LoweredLoop_t*) l1)->f_body)->f_span;
        l6 = vader_midir_new_block(l0, l2);
        t1 = vader_midir_operand_edges(l5);
        t2 = ((vader_struct_vader_midir_OperandEdges_t*) t1)->f_on_true;
        l7 = (t2 < INT32_C(2));
        t1 = vader_midir_branch_on_cond(l0, l5, l6, l4, l7);
        t3 = ((vader_struct_vader_midir_CondReach_t*) t1)->f_on_true;
        if (!(t3)) {
            vader_struct_vader_midir_TermBranch_t* _a1_obj = (vader_struct_vader_midir_TermBranch_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_TermBranch_t));
            vader_obj_header_init(_a1_obj, 978u);
            _a1_obj->f_span = ((vader_struct_vader_lower_LoweredLoop_t*) l1)->f_span;
            _a1_obj->f_target = l4;
            l2 = (void*) _a1_obj;
            vader_midir_terminate(l0, vader_ref_box(l2));
        }
        t0 = vader_box_i32(246u, l6);
        ((vader_struct_vader_midir_FnCtx_t*) l0)->f_current = t0;
        VADER_WRITE_BARRIER((vader_struct_vader_midir_FnCtx_t*) l0);
    }
    l5 = ((vader_struct_vader_lower_LoweredLoop_t*) l1)->f_label;
    l2 = ((vader_struct_vader_lower_LoweredLoop_t*) l1)->f_step;
    vader_struct_vader_midir_LoopFrame_t* _a2_obj = (vader_struct_vader_midir_LoopFrame_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_LoopFrame_t));
    vader_obj_header_init(_a2_obj, 970u);
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
    vader_array_t* _a3_arr = vader_array_new(111u, 0u, 13u, 970u);
    l2 = (void*) _a3_arr;
    l9 = (size_t) 0;
    t4 = ((vader_array_t*) ((vader_struct_vader_midir_FnCtx_t*) l0)->f_loop_stack)->length;
    t5 = (t4 - INT64_C(1));
    l10 = (size_t) (int64_t) t5;
    while ((l9 < l10)) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_vader_midir_FnCtx_t*) l0)->f_loop_stack);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l9)
        l8 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l9);
        vader_array_push((vader_array_t*) l2, vader_ref_box(l8));
        t5 = (l9 + INT64_C(1));
        l9 = (size_t) (int64_t) t5;
    }
    ((vader_struct_vader_midir_FnCtx_t*) l0)->f_loop_stack = l2;
    VADER_WRITE_BARRIER((vader_struct_vader_midir_FnCtx_t*) l0);
    t0 = vader_box_i32(246u, l4);
    ((vader_struct_vader_midir_FnCtx_t*) l0)->f_current = t0;
    VADER_WRITE_BARRIER((vader_struct_vader_midir_FnCtx_t*) l0);
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_midir_build_make_closure(void* l0, void* l1) {
    int32_t l2, l4;
    vader_box_t l3 = vader_box_null(), l7 = vader_box_null();
    void* l5 = NULL;
    void* l6 = NULL;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l3, &l7, &t0 };
    void** gc_raw_roots[4] = { &l0, &l1, &l5, &l6 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_lower_LoweredMakeClosure_t*) l1)->f_env;
    l3 = vader_midir_build_expr(l0, l3);
    if (l3.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l2 = ((int32_t) l3.payload.i);
    l3 = ((vader_struct_vader_lower_LoweredMakeClosure_t*) l1)->f_type;
    l4 = vader_midir_fresh_tmp(l0, 1454u, l3);
    l5 = ((vader_struct_vader_lower_LoweredMakeClosure_t*) l1)->f_span;
    l6 = ((vader_struct_vader_lower_LoweredMakeClosure_t*) l1)->f_fn_symbol;
    l3 = vader_lower_type_of(((vader_struct_vader_lower_LoweredMakeClosure_t*) l1)->f_env);
    l7 = ((vader_struct_vader_lower_LoweredMakeClosure_t*) l1)->f_type;
    vader_struct_vader_midir_InstrMakeClosure_t* _a0_obj = (vader_struct_vader_midir_InstrMakeClosure_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrMakeClosure_t));
    vader_obj_header_init(_a0_obj, 961u);
    _a0_obj->f_span = l5;
    _a0_obj->f_dst = l4;
    _a0_obj->f_fn_symbol = l6;
    _a0_obj->f_env = l2;
    _a0_obj->f_env_type = l3;
    _a0_obj->f_type = l7;
    l5 = (void*) _a0_obj;
    vader_midir_emit(l0, vader_ref_box(l5));
    t0 = vader_box_i32(246u, l4);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir_build_short_circuit(void* l0, void* l1, vader_box_t l2) {
    int32_t l3, l6, l9, l10, l11;
    vader_box_t l4 = vader_box_null();
    bool l5;
    vader_string_t l7 = 0;
    void* l8 = NULL;
    void* l12 = NULL;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l2, &l4, &t0 };
    void** gc_raw_roots[4] = { &l0, &l1, &l8, &l12 };
    vader_string_t* gc_atom_roots[1] = { &l7 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
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
            l7 = 1263u;
        } else {
            l7 = 2074u;
        }
        l4 = ((vader_struct_vader_lower_LoweredBinary_t*) l1)->f_type;
        l6 = vader_midir_declare_local(l0, l7, l4, vader_box_obj(0u, NULL));
    } else {
        l6 = ((int32_t) l2.payload.i);
    }
    l8 = vader_lower_span_of(((vader_struct_vader_lower_LoweredBinary_t*) l1)->f_right);
    l9 = vader_midir_new_block(l0, l8);
    l8 = vader_lower_span_of(((vader_struct_vader_lower_LoweredBinary_t*) l1)->f_right);
    l10 = vader_midir_new_block(l0, l8);
    l8 = ((vader_struct_vader_lower_LoweredBinary_t*) l1)->f_span;
    l11 = vader_midir_new_block(l0, l8);
    vader_struct_vader_midir_TermCondBranch_t* _a0_obj = (vader_struct_vader_midir_TermCondBranch_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_TermCondBranch_t));
    vader_obj_header_init(_a0_obj, 979u);
    _a0_obj->f_span = ((vader_struct_vader_lower_LoweredBinary_t*) l1)->f_span;
    _a0_obj->f_cond = l3;
    _a0_obj->f_then_block = l9;
    _a0_obj->f_else_block = l10;
    l8 = (void*) _a0_obj;
    vader_midir_terminate(l0, vader_ref_box(l8));
    t0 = vader_box_i32(246u, l9);
    ((vader_struct_vader_midir_FnCtx_t*) l0)->f_current = t0;
    VADER_WRITE_BARRIER((vader_struct_vader_midir_FnCtx_t*) l0);
    if (l5) {
        l4 = ((vader_struct_vader_lower_LoweredBinary_t*) l1)->f_right;
        l4 = vader_midir_build_expr(l0, l4);
        if (!(l4.tag == 0u)) {
            if (!(((vader_struct_vader_midir_FnCtx_t*) l0)->f_current.tag == 0u)) {
                l8 = vader_lower_span_of(((vader_struct_vader_lower_LoweredBinary_t*) l1)->f_right);
                l3 = ((int32_t) l4.payload.i);
                vader_struct_vader_midir_InstrMove_t* _a1_obj = (vader_struct_vader_midir_InstrMove_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrMove_t));
                vader_obj_header_init(_a1_obj, 962u);
                _a1_obj->f_span = l8;
                _a1_obj->f_dst = l6;
                _a1_obj->f_src = l3;
                l8 = (void*) _a1_obj;
                vader_midir_emit(l0, vader_ref_box(l8));
            }
        }
    } else {
        l4 = ((vader_struct_vader_lower_LoweredBinary_t*) l1)->f_type;
        l3 = vader_midir_fresh_tmp(l0, 1893u, l4);
        l8 = ((vader_struct_vader_lower_LoweredBinary_t*) l1)->f_span;
        vader_struct_vader_midir_ConstBool_t* _a2_obj = (vader_struct_vader_midir_ConstBool_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_ConstBool_t));
        vader_obj_header_init(_a2_obj, 926u);
        _a2_obj->f_value = true;
        l12 = (void*) _a2_obj;
        l4 = ((vader_struct_vader_lower_LoweredBinary_t*) l1)->f_type;
        vader_struct_vader_midir_InstrConst_t* _a3_obj = (vader_struct_vader_midir_InstrConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrConst_t));
        vader_obj_header_init(_a3_obj, 952u);
        _a3_obj->f_span = l8;
        _a3_obj->f_dst = l3;
        _a3_obj->f_value = vader_ref_box(l12);
        _a3_obj->f_type = l4;
        l8 = (void*) _a3_obj;
        vader_midir_emit(l0, vader_ref_box(l8));
        vader_struct_vader_midir_InstrMove_t* _a4_obj = (vader_struct_vader_midir_InstrMove_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrMove_t));
        vader_obj_header_init(_a4_obj, 962u);
        _a4_obj->f_span = ((vader_struct_vader_lower_LoweredBinary_t*) l1)->f_span;
        _a4_obj->f_dst = l6;
        _a4_obj->f_src = l3;
        l8 = (void*) _a4_obj;
        vader_midir_emit(l0, vader_ref_box(l8));
    }
    if (!(((vader_struct_vader_midir_FnCtx_t*) l0)->f_current.tag == 0u)) {
        vader_struct_vader_midir_TermBranch_t* _a5_obj = (vader_struct_vader_midir_TermBranch_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_TermBranch_t));
        vader_obj_header_init(_a5_obj, 978u);
        _a5_obj->f_span = ((vader_struct_vader_lower_LoweredBinary_t*) l1)->f_span;
        _a5_obj->f_target = l11;
        l8 = (void*) _a5_obj;
        vader_midir_terminate(l0, vader_ref_box(l8));
    }
    t0 = vader_box_i32(246u, l10);
    ((vader_struct_vader_midir_FnCtx_t*) l0)->f_current = t0;
    VADER_WRITE_BARRIER((vader_struct_vader_midir_FnCtx_t*) l0);
    if (l5) {
        l4 = ((vader_struct_vader_lower_LoweredBinary_t*) l1)->f_type;
        l3 = vader_midir_fresh_tmp(l0, 1893u, l4);
        l8 = ((vader_struct_vader_lower_LoweredBinary_t*) l1)->f_span;
        vader_struct_vader_midir_ConstBool_t* _a6_obj = (vader_struct_vader_midir_ConstBool_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_ConstBool_t));
        vader_obj_header_init(_a6_obj, 926u);
        _a6_obj->f_value = false;
        l12 = (void*) _a6_obj;
        l4 = ((vader_struct_vader_lower_LoweredBinary_t*) l1)->f_type;
        vader_struct_vader_midir_InstrConst_t* _a7_obj = (vader_struct_vader_midir_InstrConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrConst_t));
        vader_obj_header_init(_a7_obj, 952u);
        _a7_obj->f_span = l8;
        _a7_obj->f_dst = l3;
        _a7_obj->f_value = vader_ref_box(l12);
        _a7_obj->f_type = l4;
        l8 = (void*) _a7_obj;
        vader_midir_emit(l0, vader_ref_box(l8));
        vader_struct_vader_midir_InstrMove_t* _a8_obj = (vader_struct_vader_midir_InstrMove_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrMove_t));
        vader_obj_header_init(_a8_obj, 962u);
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
                l8 = vader_lower_span_of(((vader_struct_vader_lower_LoweredBinary_t*) l1)->f_right);
                l3 = ((int32_t) l4.payload.i);
                vader_struct_vader_midir_InstrMove_t* _a9_obj = (vader_struct_vader_midir_InstrMove_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrMove_t));
                vader_obj_header_init(_a9_obj, 962u);
                _a9_obj->f_span = l8;
                _a9_obj->f_dst = l6;
                _a9_obj->f_src = l3;
                l8 = (void*) _a9_obj;
                vader_midir_emit(l0, vader_ref_box(l8));
            }
        }
    }
    if (((vader_struct_vader_midir_FnCtx_t*) l0)->f_current.tag == 0u) {
        t0 = vader_box_i32(246u, l11);
        ((vader_struct_vader_midir_FnCtx_t*) l0)->f_current = t0;
        VADER_WRITE_BARRIER((vader_struct_vader_midir_FnCtx_t*) l0);
        t0 = vader_box_i32(246u, l6);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_midir_TermBranch_t* _a10_obj = (vader_struct_vader_midir_TermBranch_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_TermBranch_t));
    vader_obj_header_init(_a10_obj, 978u);
    _a10_obj->f_span = ((vader_struct_vader_lower_LoweredBinary_t*) l1)->f_span;
    _a10_obj->f_target = l11;
    l8 = (void*) _a10_obj;
    vader_midir_terminate(l0, vader_ref_box(l8));
    t0 = vader_box_i32(246u, l11);
    ((vader_struct_vader_midir_FnCtx_t*) l0)->f_current = t0;
    VADER_WRITE_BARRIER((vader_struct_vader_midir_FnCtx_t*) l0);
    t0 = vader_box_i32(246u, l6);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_midir_build_stmt(void* l0, vader_box_t l1) {
    vader_box_t l2 = vader_box_null(), l4 = vader_box_null();
    vader_string_t l3 = 0;
    void* l5 = NULL;
    void* l8 = NULL;
    int32_t l6, l7;
    void* t0 = NULL;
    bool t1;
    vader_box_t* gc_roots[3] = { &l1, &l2, &l4 };
    void** gc_raw_roots[4] = { &l0, &l5, &l8, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l1.tag == 883u) {
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
            std_collections_MutableMap_IndexSet_set_at__i32__i32(l5, l7, l6);
            if (!(((vader_struct_vader_midir_FnCtx_t*) l0)->f_current.tag == 0u)) {
                vader_midir_build_expr_into(l0, l2, l6);
            }
        } else {
            l2 = vader_midir_build_expr(l0, l2);
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
            std_collections_MutableMap_IndexSet_set_at__i32__i32(l5, l7, l6);
            if (!(l2.tag == 0u)) {
                if (!(((vader_struct_vader_midir_FnCtx_t*) l0)->f_current.tag == 0u)) {
                    t0 = l1.payload.obj;
                    l5 = ((vader_struct_vader_lower_LoweredLet_t*) t0)->f_span;
                    l7 = ((int32_t) l2.payload.i);
                    vader_struct_vader_midir_InstrMove_t* _a0_obj = (vader_struct_vader_midir_InstrMove_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrMove_t));
                    vader_obj_header_init(_a0_obj, 962u);
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
    if (l1.tag == 856u) {
        l5 = l1.payload.obj;
        vader_midir_build_assign(l0, l5);
    } else if (l1.tag == 866u) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_vader_lower_LoweredCellSet_t*) t0)->f_target;
        l2 = vader_midir_build_expr(l0, l2);
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_lower_LoweredCellSet_t*) t0)->f_value;
        l4 = vader_midir_build_expr(l0, l4);
        if (!(l2.tag == 0u)) {
            if (!(l4.tag == 0u)) {
                t0 = l1.payload.obj;
                l5 = ((vader_struct_vader_lower_LoweredCellSet_t*) t0)->f_span;
                l6 = ((int32_t) l2.payload.i);
                l7 = ((int32_t) l4.payload.i);
                t0 = l1.payload.obj;
                l2 = ((vader_struct_vader_lower_LoweredCellSet_t*) t0)->f_value_type;
                vader_struct_vader_midir_InstrCellSet_t* _a1_obj = (vader_struct_vader_midir_InstrCellSet_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrCellSet_t));
                vader_obj_header_init(_a1_obj, 951u);
                _a1_obj->f_span = l5;
                _a1_obj->f_cell = l6;
                _a1_obj->f_value = l7;
                _a1_obj->f_value_type = l2;
                l5 = (void*) _a1_obj;
                vader_midir_emit(l0, vader_ref_box(l5));
            }
        }
    } else if (l1.tag == 872u) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_vader_lower_LoweredDeferPush_t*) t0)->f_thunk;
        l2 = vader_midir_build_expr(l0, l2);
        if (!(l2.tag == 0u)) {
            t0 = l1.payload.obj;
            l5 = ((vader_struct_vader_lower_LoweredDeferPush_t*) t0)->f_span;
            l6 = ((int32_t) l2.payload.i);
            vader_struct_vader_midir_InstrDeferPush_t* _a2_obj = (vader_struct_vader_midir_InstrDeferPush_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrDeferPush_t));
            vader_obj_header_init(_a2_obj, 955u);
            _a2_obj->f_span = l5;
            _a2_obj->f_value = l6;
            l5 = (void*) _a2_obj;
            vader_midir_emit(l0, vader_ref_box(l5));
        }
    } else if (l1.tag == 871u) {
        t0 = l1.payload.obj;
        l5 = ((vader_struct_vader_lower_LoweredDeferPopExec_t*) t0)->f_span;
        t0 = l1.payload.obj;
        l6 = ((vader_struct_vader_lower_LoweredDeferPopExec_t*) t0)->f_count;
        vader_struct_vader_midir_InstrDeferPopExec_t* _a3_obj = (vader_struct_vader_midir_InstrDeferPopExec_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrDeferPopExec_t));
        vader_obj_header_init(_a3_obj, 954u);
        _a3_obj->f_span = l5;
        _a3_obj->f_count = l6;
        l5 = (void*) _a3_obj;
        vader_midir_emit(l0, vader_ref_box(l5));
    } else if (l1.tag == 873u) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_vader_lower_LoweredExprStmt_t*) t0)->f_expr;
        vader_midir_build_expr(l0, l2);
    } else if (l1.tag == 890u) {
        vader_array_t* _a4_arr = vader_array_new(14u, 0u, 7u, 246u);
        l5 = (void*) _a4_arr;
        t0 = l1.payload.obj;
        if (!(((vader_struct_vader_lower_LoweredReturn_t*) t0)->f_value.tag == 0u)) {
            t0 = l1.payload.obj;
            l2 = ((vader_struct_vader_lower_LoweredReturn_t*) t0)->f_value;
            l2 = vader_midir_build_expr(l0, l2);
            if (!(l2.tag == 0u)) {
                l6 = ((int32_t) l2.payload.i);
                vader_array_push_i32((vader_array_t*) l5, l6);
            }
        }
        t0 = l1.payload.obj;
        vader_struct_vader_midir_TermReturn_t* _a5_obj = (vader_struct_vader_midir_TermReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_TermReturn_t));
        vader_obj_header_init(_a5_obj, 980u);
        _a5_obj->f_span = ((vader_struct_vader_lower_LoweredReturn_t*) t0)->f_span;
        _a5_obj->f_values = l5;
        l5 = (void*) _a5_obj;
        vader_midir_terminate(l0, vader_ref_box(l5));
    } else if (l1.tag == 884u) {
        l5 = l1.payload.obj;
        vader_midir_build_loop(l0, l5);
    } else if (l1.tag == 882u) {
        l5 = l1.payload.obj;
        vader_midir_build_labelled_block(l0, l5);
    } else if (l1.tag == 861u) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_vader_lower_LoweredBreak_t*) t0)->f_label;
        l5 = vader_midir_resolve_loop_frame(l0, l2);
        t0 = l1.payload.obj;
        l8 = ((vader_struct_vader_lower_LoweredBreak_t*) t0)->f_span;
        l6 = ((vader_struct_vader_midir_LoopFrame_t*) l5)->f_exit_id;
        vader_struct_vader_midir_TermBranch_t* _a6_obj = (vader_struct_vader_midir_TermBranch_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_TermBranch_t));
        vader_obj_header_init(_a6_obj, 978u);
        _a6_obj->f_span = l8;
        _a6_obj->f_target = l6;
        l5 = (void*) _a6_obj;
        vader_midir_terminate(l0, vader_ref_box(l5));
    } else if (l1.tag == 869u) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_vader_lower_LoweredContinue_t*) t0)->f_label;
        l5 = vader_midir_resolve_loop_frame(l0, l2);
        t0 = l1.payload.obj;
        l8 = ((vader_struct_vader_lower_LoweredContinue_t*) t0)->f_span;
        vader_midir_build_back_edge(l0, l5, l8);
    } else {
        if (!((l1.tag == 857u || l1.tag == 903u))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        vader_host_std_abort_panic(1989u);
        vader_unreachable("a no-return call returned");
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_midir_build_string_slice(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l3 = vader_box_null(), l4 = vader_box_null(), l5 = vader_box_null();
    int32_t l6, l8, l9, l10;
    void* l7 = NULL;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[5] = { &l2, &l3, &l4, &l5, &t0 };
    void** gc_raw_roots[3] = { &l0, &l1, &l7 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 5u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_lower_LoweredStringSlice_t*) l1)->f_target;
    l2 = vader_midir_build_expr(l0, l2);
    l3 = ((vader_struct_vader_lower_LoweredStringSlice_t*) l1)->f_lo;
    l3 = vader_midir_build_expr(l0, l3);
    l4 = ((vader_struct_vader_lower_LoweredStringSlice_t*) l1)->f_hi;
    l4 = vader_midir_build_expr(l0, l4);
    if (l2.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    if (l3.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    if (!(l4.tag == 0u)) {
        l5 = ((vader_struct_vader_lower_LoweredStringSlice_t*) l1)->f_type;
        l6 = vader_midir_fresh_tmp(l0, 1498u, l5);
        l7 = ((vader_struct_vader_lower_LoweredStringSlice_t*) l1)->f_span;
        l5 = ((vader_struct_vader_lower_LoweredStringSlice_t*) l1)->f_type;
        l8 = ((int32_t) l2.payload.i);
        l9 = ((int32_t) l3.payload.i);
        l10 = ((int32_t) l4.payload.i);
        vader_struct_vader_midir_InstrStringSlice_t* _a0_obj = (vader_struct_vader_midir_InstrStringSlice_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrStringSlice_t));
        vader_obj_header_init(_a0_obj, 963u);
        _a0_obj->f_span = l7;
        _a0_obj->f_dst = l6;
        _a0_obj->f_type = l5;
        _a0_obj->f_target = l8;
        _a0_obj->f_lo = l9;
        _a0_obj->f_hi = l10;
        l7 = (void*) _a0_obj;
        vader_midir_emit(l0, vader_ref_box(l7));
        t0 = vader_box_i32(246u, l6);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static vader_box_t vader_midir_build_struct_lit(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    size_t l4, l5;
    int32_t l6;
    vader_box_t l7 = vader_box_null(), l8 = vader_box_null();
    void* t0 = NULL;
    int64_t t1;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l7, &l8, &t2 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(14u, 0u, 7u, 246u);
    l2 = (void*) _a0_arr;
    l3 = ((vader_struct_vader_lower_LoweredStructLit_t*) l1)->f_fields;
    l4 = ((vader_array_t*) l3)->length;
    l5 = (size_t) 0;
    while ((l5 < l4)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
        t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5);
        l7 = ((vader_struct_vader_lower_LoweredStructLitField_t*) t0)->f_value;
        l8 = vader_midir_build_expr(l0, l7);
        if (l8.tag == 0u) {
            { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
        }
        l6 = ((int32_t) l8.payload.i);
        vader_array_push_i32((vader_array_t*) l2, l6);
        t1 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t1;
    }
    l7 = ((vader_struct_vader_lower_LoweredStructLit_t*) l1)->f_type;
    l6 = vader_midir_fresh_tmp(l0, 2281u, l7);
    l3 = ((vader_struct_vader_lower_LoweredStructLit_t*) l1)->f_span;
    l7 = ((vader_struct_vader_lower_LoweredStructLit_t*) l1)->f_type;
    vader_struct_vader_midir_InstrStructNew_t* _a2_obj = (vader_struct_vader_midir_InstrStructNew_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrStructNew_t));
    vader_obj_header_init(_a2_obj, 964u);
    _a2_obj->f_span = l3;
    _a2_obj->f_dst = l6;
    _a2_obj->f_type = l7;
    _a2_obj->f_fields = l2;
    _a2_obj->f_stack = false;
    l2 = (void*) _a2_obj;
    vader_midir_emit(l0, vader_ref_box(l2));
    t2 = vader_box_i32(246u, l6);
    { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir_build_type_check(void* l0, void* l1) {
    int32_t l2, l4;
    vader_box_t l3 = vader_box_null();
    void* l5 = NULL;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l3, &t0 };
    void** gc_raw_roots[3] = { &l0, &l1, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_lower_LoweredTypeCheck_t*) l1)->f_value;
    l3 = vader_midir_build_expr(l0, l3);
    if (l3.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l2 = ((int32_t) l3.payload.i);
    l3 = ((vader_struct_vader_lower_LoweredTypeCheck_t*) l1)->f_type;
    l4 = vader_midir_fresh_tmp(l0, 2383u, l3);
    l5 = ((vader_struct_vader_lower_LoweredTypeCheck_t*) l1)->f_span;
    l3 = ((vader_struct_vader_lower_LoweredTypeCheck_t*) l1)->f_check_type;
    vader_struct_vader_midir_InstrTypeCheck_t* _a0_obj = (vader_struct_vader_midir_InstrTypeCheck_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrTypeCheck_t));
    vader_obj_header_init(_a0_obj, 965u);
    _a0_obj->f_span = l5;
    _a0_obj->f_dst = l4;
    _a0_obj->f_value = l2;
    _a0_obj->f_check_type = l3;
    l5 = (void*) _a0_obj;
    vader_midir_emit(l0, vader_ref_box(l5));
    t0 = vader_box_i32(246u, l4);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir_build_type_const(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l5 = vader_box_null();
    int32_t l3;
    void* l4 = NULL;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l2, &l5, &t0 };
    void** gc_raw_roots[3] = { &l0, &l1, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_lower_LoweredTypeConst_t*) l1)->f_type;
    l3 = vader_midir_fresh_tmp(l0, 2384u, l2);
    l4 = ((vader_struct_vader_lower_LoweredTypeConst_t*) l1)->f_span;
    l2 = ((vader_struct_vader_lower_LoweredTypeConst_t*) l1)->f_type;
    l5 = ((vader_struct_vader_lower_LoweredTypeConst_t*) l1)->f_value;
    vader_struct_vader_midir_InstrTypeConst_t* _a0_obj = (vader_struct_vader_midir_InstrTypeConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrTypeConst_t));
    vader_obj_header_init(_a0_obj, 966u);
    _a0_obj->f_span = l4;
    _a0_obj->f_dst = l3;
    _a0_obj->f_type = l2;
    _a0_obj->f_value_type = l5;
    l4 = (void*) _a0_obj;
    vader_midir_emit(l0, vader_ref_box(l4));
    t0 = vader_box_i32(246u, l3);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir_build_unary(void* l0, void* l1) {
    int32_t l2, l4;
    vader_box_t l3 = vader_box_null();
    void* l5 = NULL;
    uint8_t l6;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l3, &t0 };
    void** gc_raw_roots[3] = { &l0, &l1, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_lower_LoweredUnary_t*) l1)->f_operand;
    l3 = vader_midir_build_expr(l0, l3);
    if (l3.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l2 = ((int32_t) l3.payload.i);
    l3 = ((vader_struct_vader_lower_LoweredUnary_t*) l1)->f_type;
    l4 = vader_midir_fresh_tmp(l0, 2443u, l3);
    l5 = ((vader_struct_vader_lower_LoweredUnary_t*) l1)->f_span;
    l6 = ((vader_struct_vader_lower_LoweredUnary_t*) l1)->f_op;
    l3 = ((vader_struct_vader_lower_LoweredUnary_t*) l1)->f_type;
    vader_struct_vader_midir_InstrUnOp_t* _a0_obj = (vader_struct_vader_midir_InstrUnOp_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrUnOp_t));
    vader_obj_header_init(_a0_obj, 967u);
    _a0_obj->f_span = l5;
    _a0_obj->f_dst = l4;
    _a0_obj->f_op = l6;
    _a0_obj->f_operand = l2;
    _a0_obj->f_type = l3;
    l5 = (void*) _a0_obj;
    vader_midir_emit(l0, vader_ref_box(l5));
    t0 = vader_box_i32(246u, l4);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
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
        vader_obj_header_init(_a0_obj, 981u);
        _a0_obj->f_span = l2;
        _a0_obj->f_reason = l3;
        l5 = (void*) _a0_obj;
        vader_midir_terminate(l0, vader_ref_box(l5));
        { vader_box_t __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_midir_declare_local(l0, 2444u, l1, vader_box_obj(0u, NULL));
    l4 = vader_box_i32(246u, t1);
    vader_struct_vader_midir_TermUnreachable_t* _a1_obj = (vader_struct_vader_midir_TermUnreachable_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_TermUnreachable_t));
    vader_obj_header_init(_a1_obj, 981u);
    _a1_obj->f_span = l2;
    _a1_obj->f_reason = l3;
    l5 = (void*) _a1_obj;
    vader_midir_terminate(l0, vader_ref_box(l5));
    { vader_box_t __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir_build_virtual_call(void* l0, void* l1) {
    int32_t l2;
    vader_box_t l3 = vader_box_null(), l5 = vader_box_null();
    void* l4 = NULL;
    void* l6 = NULL;
    void* l9 = NULL;
    vader_string_t l7 = 0;
    vader_string_t l8 = 0;
    bool t0;
    int32_t t1;
    vader_box_t* gc_roots[2] = { &l3, &l5 };
    void** gc_raw_roots[5] = { &l0, &l1, &l4, &l6, &l9 };
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
    l3 = vader_midir_build_args(l0, l4);
    if (l3.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l4 = l3.payload.obj;
    t0 = vader_typecheck_is_void(((vader_struct_vader_lower_LoweredVirtualCall_t*) l1)->f_type);
    if (t0) {
        l3 = vader_box_obj(0u, NULL);
    } else {
        l5 = ((vader_struct_vader_lower_LoweredVirtualCall_t*) l1)->f_type;
        t1 = vader_midir_fresh_tmp(l0, 2601u, l5);
        l3 = vader_box_i32(246u, t1);
    }
    l6 = ((vader_struct_vader_lower_LoweredVirtualCall_t*) l1)->f_span;
    l7 = ((vader_struct_vader_lower_LoweredVirtualCall_t*) l1)->f_trait_name;
    l8 = ((vader_struct_vader_lower_LoweredVirtualCall_t*) l1)->f_method;
    l5 = ((vader_struct_vader_lower_LoweredVirtualCall_t*) l1)->f_type;
    l9 = ((vader_struct_vader_lower_LoweredVirtualCall_t*) l1)->f_param_types;
    vader_struct_vader_midir_InstrVirtualCall_t* _a0_obj = (vader_struct_vader_midir_InstrVirtualCall_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrVirtualCall_t));
    vader_obj_header_init(_a0_obj, 968u);
    _a0_obj->f_span = l6;
    _a0_obj->f_dst = l3;
    _a0_obj->f_trait_name = l7;
    _a0_obj->f_method = l8;
    _a0_obj->f_receiver = l2;
    _a0_obj->f_args = l4;
    _a0_obj->f_type = l5;
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
    void* l22 = NULL;
    void* l23 = NULL;
    void* l24 = NULL;
    size_t l5, l6, l7, l8, l21;
    vader_box_t l9 = vader_box_null(), l20 = vader_box_null();
    vader_string_t l10 = 0;
    vader_string_t l15 = 0;
    vader_string_t l16 = 0;
    vader_string_t l18 = 0;
    int32_t l17, l19;
    void* t0 = NULL;
    int64_t t1;
    bool t2;
    vader_box_t t3 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l9, &l20, &t3 };
    void** gc_raw_roots[13] = {
        &l0, &l1, &l2, &l3, &l4, &l11, &l12, &l13, &l14, &l22, &l23, &l24, &t0,
    };
    vader_string_t* gc_atom_roots[4] = { &l10, &l15, &l16, &l18 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 13u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(13u, 0u, 0u, 243u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(11u, 0u, 12u, 241u);
    l3 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(14u, 0u, 7u, 246u);
    l4 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__string__bool_t* _a3_obj = (vader_struct_std_collections_MutableMap__string__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__bool_t));
    vader_obj_header_init(_a3_obj, 383u);
    _a3_obj->f_ekeys = l2;
    _a3_obj->f_evals = l3;
    _a3_obj->f_index = l4;
    _a3_obj->f_mask = (size_t) 0;
    _a3_obj->f_size = (size_t) 0;
    _a3_obj->f_tombs = (size_t) 0;
    l2 = (void*) _a3_obj;
    l3 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_functions;
    l5 = ((vader_array_t*) l3)->length;
    l6 = (size_t) 0;
    while ((l6 < l5)) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l6)
        t0 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l6);
        l4 = ((vader_struct_vader_bytecode_BcFunction_t*) t0)->f_body;
        l7 = ((vader_array_t*) l4)->length;
        l8 = (size_t) 0;
        while ((l8 < l7)) {
            vader_array_t* _a5_slotarr = ((vader_array_t*) l4);
            VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l8)
            l9 = vader_array_ref_load_box(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l8);
            if (l9.tag == 709u) {
                t0 = l9.payload.obj;
                l10 = ((vader_struct_vader_bytecode_VirtualCall_t*) t0)->f_vtable_key;
                std_collections_MutableMap_IndexSet_set_at__string__bool(l2, l10, true);
            }
            t1 = (l8 + INT64_C(1));
            l8 = (size_t) (int64_t) t1;
        }
        t1 = (l6 + INT64_C(1));
        l6 = (size_t) (int64_t) t1;
    }
    vader_array_t* _a6_arr = vader_array_new(13u, 0u, 0u, 243u);
    l3 = (void*) _a6_arr;
    vader_array_t* _a7_arr = vader_array_new(20u, 0u, 4u, 253u);
    l4 = (void*) _a7_arr;
    vader_array_t* _a8_arr = vader_array_new(14u, 0u, 7u, 246u);
    l11 = (void*) _a8_arr;
    vader_struct_std_collections_MutableMap__string__usize_t* _a9_obj = (vader_struct_std_collections_MutableMap__string__usize_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__usize_t));
    vader_obj_header_init(_a9_obj, 389u);
    _a9_obj->f_ekeys = l3;
    _a9_obj->f_evals = l4;
    _a9_obj->f_index = l11;
    _a9_obj->f_mask = (size_t) 0;
    _a9_obj->f_size = (size_t) 0;
    _a9_obj->f_tombs = (size_t) 0;
    l3 = (void*) _a9_obj;
    vader_array_t* _a10_arr = vader_array_new(53u, 0u, 13u, 711u);
    l4 = (void*) _a10_arr;
    vader_array_t* _a11_arr = vader_array_new(97u, 0u, 13u, 902u);
    l11 = (void*) _a11_arr;
    vader_array_t* _a12_arr = vader_array_new(97u, 0u, 13u, 902u);
    l12 = (void*) _a12_arr;
    l13 = l0;
    l5 = ((vader_array_t*) l13)->length;
    l6 = (size_t) 0;
    while ((l6 < l5)) {
        vader_array_t* _a13_slotarr = ((vader_array_t*) l13);
        VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a13_slotarr, l6)
        l14 = vader_array_ref_load_obj(_a13_slotarr->buf, _a13_slotarr->offset + (size_t) l6);
        t2 = vader_types_boxes_as_representation(((vader_struct_vader_lower_LoweredVtableEntry_t*) l14)->f_struct_type);
        if (t2) {
            vader_array_push((vader_array_t*) l12, vader_ref_box(l14));
        } else {
            vader_array_push((vader_array_t*) l11, vader_ref_box(l14));
        }
        t1 = (l6 + INT64_C(1));
        l6 = (size_t) (int64_t) t1;
    }
    vader_array_push_all((vader_array_t*) l11, (vader_array_t*) l12);
    l5 = ((vader_array_t*) l11)->length;
    l6 = (size_t) 0;
    while ((l6 < l5)) {
        vader_array_t* _a14_slotarr = ((vader_array_t*) l11);
        VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a14_slotarr, l6)
        l12 = vader_array_ref_load_obj(_a14_slotarr->buf, _a14_slotarr->offset + (size_t) l6);
        l10 = ((vader_struct_vader_lower_LoweredVtableEntry_t*) l12)->f_trait_name;
        l15 = ((vader_struct_vader_lower_LoweredVtableEntry_t*) l12)->f_method_name;
        l16 = concat_3(l10, 308u, l15);
        t3 = std_collections_MutableMap_Index_at__string__bool(l2, l16);
        if (t3.tag == 241u) {
            l17 = vader_midir_resolve_fn_index(((vader_struct_vader_lower_LoweredVtableEntry_t*) l12)->f_fn_symbol, l1);
            if ((l17 < INT32_C(0))) {
                t1 = (l6 + INT64_C(1));
                l6 = (size_t) (int64_t) t1;
                continue;
            }
            l18 = vader_bytecode_type_intern_key(((vader_struct_vader_lower_LoweredVtableEntry_t*) l12)->f_struct_type);
            l9 = std_collections_MutableMap_Index_at__string__i32(((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_type_key, l18);
            if (l9.tag == 246u) {
                l19 = ((int32_t) l9.payload.i);
                l20 = std_collections_MutableMap_Index_at__string__usize(l3, l16);
                if (l20.tag == 253u) {
                    l7 = ((size_t) l20.payload.i);
                    vader_array_t* _a15_slotarr = ((vader_array_t*) l4);
                    VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a15_slotarr, l7)
                    t0 = vader_array_ref_load_obj(_a15_slotarr->buf, _a15_slotarr->offset + (size_t) l7);
                    t2 = vader_midir_has_receiver(t0, l19);
                    if (t2) {
                        t1 = (l6 + INT64_C(1));
                        l6 = (size_t) (int64_t) t1;
                        continue;
                    }
                    l8 = ((size_t) l20.payload.i);
                    vader_array_t* _a16_slotarr = ((vader_array_t*) l4);
                    VADER_ARRAY_RESOLVE_BUF(_a16_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a16_slotarr, l8)
                    t0 = vader_array_ref_load_obj(_a16_slotarr->buf, _a16_slotarr->offset + (size_t) l8);
                    l13 = ((vader_struct_vader_bytecode_VtableRow_t*) t0)->f_entries;
                    vader_struct_vader_bytecode_VtableEntry_t* _a17_obj = (vader_struct_vader_bytecode_VtableEntry_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_VtableEntry_t));
                    vader_obj_header_init(_a17_obj, 710u);
                    _a17_obj->f_receiver_type_index = l19;
                    _a17_obj->f_fn_index = l17;
                    l14 = (void*) _a17_obj;
                    vader_array_push((vader_array_t*) l13, vader_ref_box(l14));
                } else {
                    l21 = ((vader_array_t*) l4)->length;
                    vader_array_t* _a18_arr = vader_array_new(52u, 0u, 13u, 710u);
                    l22 = (void*) _a18_arr;
                    vader_struct_vader_bytecode_VtableEntry_t* _a19_obj = (vader_struct_vader_bytecode_VtableEntry_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_VtableEntry_t));
                    vader_obj_header_init(_a19_obj, 710u);
                    _a19_obj->f_receiver_type_index = l19;
                    _a19_obj->f_fn_index = l17;
                    l23 = (void*) _a19_obj;
                    vader_array_push((vader_array_t*) l22, vader_ref_box(l23));
                    vader_struct_vader_bytecode_VtableRow_t* _a20_obj = (vader_struct_vader_bytecode_VtableRow_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_VtableRow_t));
                    vader_obj_header_init(_a20_obj, 711u);
                    _a20_obj->f_key = l16;
                    _a20_obj->f_entries = l22;
                    l24 = (void*) _a20_obj;
                    vader_array_push((vader_array_t*) l4, vader_ref_box(l24));
                    std_collections_MutableMap_IndexSet_set_at__string__usize(l3, l16, l21);
                }
                t1 = (l6 + INT64_C(1));
                l6 = (size_t) (int64_t) t1;
                continue;
            }
            t1 = (l6 + INT64_C(1));
            l6 = (size_t) (int64_t) t1;
            continue;
        }
        t1 = (l6 + INT64_C(1));
        l6 = (size_t) (int64_t) t1;
    }
    { void* __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_midir_c_header_of(void* l0) {
    void* l1;
    void* l4;
    size_t l2, l3;
    vader_box_t l5, l6;
    vader_string_t t0;
    size_t t1;
    void* t2;
    int64_t t3;
    l1 = l0;
    l2 = ((vader_array_t*) l1)->length;
    l3 = (size_t) 0;
    while ((l3 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l4 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
        t0 = ((vader_struct_toolchain_ast_Decorator_t*) l4)->f_name;
        if (t0 == 1403u) {
            t1 = ((vader_array_t*) ((vader_struct_toolchain_ast_Decorator_t*) l4)->f_args)->length;
            if (t1 == INT64_C(1)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_Decorator_t*) l4)->f_args);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, INT32_C(0))
                l5 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) INT32_C(0));
                if (l5.tag == 510u) {
                    t2 = l5.payload.obj;
                    t1 = ((vader_array_t*) ((vader_struct_toolchain_ast_StringLitExpr_t*) t2)->f_parts)->length;
                    if (t1 == INT64_C(1)) {
                        t2 = l5.payload.obj;
                        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_StringLitExpr_t*) t2)->f_parts);
                        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, INT32_C(0))
                        l6 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) INT32_C(0));
                        if (l6.tag == 512u) {
                            t2 = l6.payload.obj;
                            t0 = ((vader_struct_toolchain_ast_StringLitText_t*) t2)->f_value;
                            return t0;
                        }
                    }
                }
            }
        }
        t3 = (l3 + INT64_C(1));
        l3 = (size_t) (int64_t) t3;
    }
    return 0u;
}

static vader_string_t vader_midir_c_struct_of(void* l0) {
    vader_box_t l1, l6;
    void* l2;
    void* l5;
    size_t l3, l4;
    void* t0;
    vader_string_t t1;
    size_t t2;
    int64_t t3;
    l1 = ((vader_struct_vader_comptime_MonoEntry_t*) l0)->f_decl;
    if (!(l1.tag == 513u)) {
        return 0u;
    }
    t0 = l1.payload.obj;
    l2 = ((vader_struct_toolchain_ast_StructDecl_t*) t0)->f_decorators;
    l3 = ((vader_array_t*) l2)->length;
    l4 = (size_t) 0;
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l5 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        t1 = ((vader_struct_toolchain_ast_Decorator_t*) l5)->f_name;
        if (t1 == 1406u) {
            t2 = ((vader_array_t*) ((vader_struct_toolchain_ast_Decorator_t*) l5)->f_args)->length;
            if (t2 == INT64_C(1)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_Decorator_t*) l5)->f_args);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, INT32_C(0))
                l1 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) INT32_C(0));
                if (l1.tag == 510u) {
                    t0 = l1.payload.obj;
                    t2 = ((vader_array_t*) ((vader_struct_toolchain_ast_StringLitExpr_t*) t0)->f_parts)->length;
                    if (t2 == INT64_C(1)) {
                        t0 = l1.payload.obj;
                        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_StringLitExpr_t*) t0)->f_parts);
                        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, INT32_C(0))
                        l6 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) INT32_C(0));
                        if (l6.tag == 512u) {
                            t0 = l6.payload.obj;
                            t1 = ((vader_struct_toolchain_ast_StringLitText_t*) t0)->f_value;
                            return t1;
                        }
                    }
                }
            }
        }
        t3 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t3;
    }
    return 0u;
}

static int32_t vader_midir_c_variadic_fixed_of(void* l0) {
    void* l1;
    void* l4;
    size_t l2, l3;
    vader_box_t l5;
    vader_string_t t0;
    size_t t1;
    void* t2;
    uint64_t t3;
    int64_t t4;
    l1 = l0;
    l2 = ((vader_array_t*) l1)->length;
    l3 = (size_t) 0;
    while ((l3 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l4 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
        t0 = ((vader_struct_toolchain_ast_Decorator_t*) l4)->f_name;
        if (t0 == 1407u) {
            t1 = ((vader_array_t*) ((vader_struct_toolchain_ast_Decorator_t*) l4)->f_args)->length;
            if (t1 == INT64_C(1)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_Decorator_t*) l4)->f_args);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, INT32_C(0))
                l5 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) INT32_C(0));
                if (l5.tag == 484u) {
                    t2 = l5.payload.obj;
                    t3 = ((vader_struct_toolchain_ast_IntLitExpr_t*) t2)->f_value;
                    return ((int32_t) (uint64_t) t3);
                }
            }
        }
        t4 = (l3 + INT64_C(1));
        l3 = (size_t) (int64_t) t4;
    }
    return -(INT32_C(1));
}

static vader_box_t vader_midir_call_single_dst(void* l0) {
    size_t t0;
    int32_t t1;
    vader_box_t t2;
    t0 = ((vader_array_t*) ((vader_struct_vader_midir_InstrCall_t*) l0)->f_dsts)->length;
    if (!(t0 != INT64_C(1))) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_midir_InstrCall_t*) l0)->f_dsts);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
        t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) INT32_C(0)];
        t2 = vader_box_i32(246u, t1);
        return t2;
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
    l4 = std_collections_MutableMap_Index_at__i32__i32(l2, l3);
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
    t1 = vader_midir_LocalId_Equals_equals(t0, l3);
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
    l4 = std_collections_MutableMap_Index_at__i32__i32(l2, l3);
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
    t1 = vader_midir_LocalId_Equals_equals(t0, l3);
    return t1;
}

static void vader_midir_cf_block(void* l0, void* l1, int32_t l2) {
    void* l3 = NULL;
    void* l5 = NULL;
    int32_t l4;
    void** gc_raw_roots[4] = { &l0, &l1, &l3, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_bytecode_Block_t* _a0_obj = (vader_struct_vader_bytecode_Block_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_Block_t));
    vader_obj_header_init(_a0_obj, 569u);
    l3 = (void*) _a0_obj;
    l4 = vader_midir_push_op_with_span(l0, vader_ref_box(l3), l1);
    l3 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_scopes;
    vader_struct_vader_midir_ScopeFrame_t* _a1_obj = (vader_struct_vader_midir_ScopeFrame_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_ScopeFrame_t));
    vader_obj_header_init(_a1_obj, 976u);
    _a1_obj->f_kind = 1333u;
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
    vader_obj_header_init(_a0_obj, 576u);
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
    vader_obj_header_init(_a0_obj, 577u);
    l3 = (void*) _a0_obj;
    l4 = vader_midir_push_op_with_span(l0, vader_ref_box(l3), l1);
    vader_midir_defer_or_resolve_branch(l0, l2, l4);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_midir_cf_else(void* l0, void* l1) {
    void* l2 = NULL;
    void* l6 = NULL;
    int32_t l3, l7;
    size_t l4, l5;
    int64_t t0;
    int32_t t1;
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &l6 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_bytecode_Else_t* _a0_obj = (vader_struct_vader_bytecode_Else_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_Else_t));
    vader_obj_header_init(_a0_obj, 593u);
    l2 = (void*) _a0_obj;
    l3 = vader_midir_push_op_with_span(l0, vader_ref_box(l2), l1);
    l4 = ((vader_array_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_scopes)->length;
    if (!(l4 == INT64_C(0))) {
        l2 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_scopes;
        t0 = (l4 - INT64_C(1));
        l5 = (size_t) (int64_t) t0;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
        l2 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5);
        l6 = ((vader_struct_vader_bytecode_BcFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_slot)->f_jump_table;
        t1 = ((vader_struct_vader_midir_ScopeFrame_t*) l2)->f_opener_pc;
        t0 = ((int64_t) (int32_t) t1);
        l5 = (size_t) (int64_t) t0;
        l7 = (l3 + INT32_C(1));
        vader_array_t* _a2_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l5)
        ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l5] = (int32_t) l7;
        l6 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_scopes;
        t0 = (l4 - INT64_C(1));
        l4 = (size_t) (int64_t) t0;
        l7 = ((vader_struct_vader_midir_ScopeFrame_t*) l2)->f_target_blk;
        vader_struct_vader_midir_ScopeFrame_t* _a3_obj = (vader_struct_vader_midir_ScopeFrame_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_ScopeFrame_t));
        vader_obj_header_init(_a3_obj, 976u);
        _a3_obj->f_kind = 1798u;
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
    int32_t l3, l8, l10;
    size_t l4, l5;
    bool l9;
    int64_t t0;
    vader_string_t t1 = 0;
    int32_t t2;
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l6, &l7 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_struct_vader_bytecode_End_t* _a0_obj = (vader_struct_vader_bytecode_End_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_End_t));
    vader_obj_header_init(_a0_obj, 596u);
    l2 = (void*) _a0_obj;
    l3 = vader_midir_push_op_with_span(l0, vader_ref_box(l2), l1);
    l4 = ((vader_array_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_scopes)->length;
    if (l4 == INT64_C(0)) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l2 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_scopes;
    t0 = (l4 - INT64_C(1));
    l5 = (size_t) (int64_t) t0;
    vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
    l2 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5);
    vader_array_t* _a2_arr = vader_array_new(114u, 0u, 13u, 976u);
    l6 = (void*) _a2_arr;
    l5 = (size_t) 0;
    t0 = (l4 - INT64_C(1));
    l4 = (size_t) (int64_t) t0;
    while ((l5 < l4)) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_scopes);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l5)
        l7 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l5);
        vader_array_push((vader_array_t*) l6, vader_ref_box(l7));
        t0 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t0;
    }
    ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_scopes = l6;
    VADER_WRITE_BARRIER((vader_struct_vader_midir_FnEmitCfg_t*) l0);
    t1 = ((vader_struct_vader_midir_ScopeFrame_t*) l2)->f_kind;
    if (t1 != 1949u) {
        l6 = ((vader_struct_vader_bytecode_BcFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_slot)->f_jump_table;
        t2 = ((vader_struct_vader_midir_ScopeFrame_t*) l2)->f_opener_pc;
        t0 = ((int64_t) (int32_t) t2);
        l4 = (size_t) (int64_t) t0;
        vader_array_t* _a4_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l4)
        t2 = ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l4];
        if ((t2 < INT32_C(0))) {
            l6 = ((vader_struct_vader_bytecode_BcFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_slot)->f_jump_table;
            t2 = ((vader_struct_vader_midir_ScopeFrame_t*) l2)->f_opener_pc;
            t0 = ((int64_t) (int32_t) t2);
            l4 = (size_t) (int64_t) t0;
            l8 = (l3 + INT32_C(1));
            vader_array_t* _a5_slotarr = ((vader_array_t*) l6);
            VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l4)
            ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l4] = (int32_t) l8;
        }
    }
    l8 = ((vader_struct_vader_midir_ScopeFrame_t*) l2)->f_target_blk;
    t1 = ((vader_struct_vader_midir_ScopeFrame_t*) l2)->f_kind;
    l9 = t1 == 1949u;
    l10 = ((vader_struct_vader_midir_ScopeFrame_t*) l2)->f_opener_pc;
    vader_midir_drain_pending(l0, l8, l9, l10, l3);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_midir_cf_if(void* l0, void* l1) {
    void* l2 = NULL;
    void* l5 = NULL;
    int32_t l3, l4;
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_bytecode_If_t* _a0_obj = (vader_struct_vader_bytecode_If_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_If_t));
    vader_obj_header_init(_a0_obj, 653u);
    l2 = (void*) _a0_obj;
    l3 = vader_midir_push_op_with_span(l0, vader_ref_box(l2), l1);
    l2 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_scopes;
    l4 = -(INT32_C(1));
    vader_struct_vader_midir_ScopeFrame_t* _a1_obj = (vader_struct_vader_midir_ScopeFrame_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_ScopeFrame_t));
    vader_obj_header_init(_a1_obj, 976u);
    _a1_obj->f_kind = 1798u;
    _a1_obj->f_target_blk = l4;
    _a1_obj->f_opener_pc = l3;
    l5 = (void*) _a1_obj;
    vader_array_push((vader_array_t*) l2, vader_ref_box(l5));
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_midir_cf_loop(void* l0, void* l1, int32_t l2) {
    void* l3 = NULL;
    void* l5 = NULL;
    int32_t l4;
    size_t l6;
    int64_t t0;
    void** gc_raw_roots[4] = { &l0, &l1, &l3, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_bytecode_Loop_t* _a0_obj = (vader_struct_vader_bytecode_Loop_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_Loop_t));
    vader_obj_header_init(_a0_obj, 666u);
    l3 = (void*) _a0_obj;
    l4 = vader_midir_push_op_with_span(l0, vader_ref_box(l3), l1);
    l3 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_scopes;
    vader_struct_vader_midir_ScopeFrame_t* _a1_obj = (vader_struct_vader_midir_ScopeFrame_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_ScopeFrame_t));
    vader_obj_header_init(_a1_obj, 976u);
    _a1_obj->f_kind = 1949u;
    _a1_obj->f_target_blk = l2;
    _a1_obj->f_opener_pc = l4;
    l5 = (void*) _a1_obj;
    vader_array_push((vader_array_t*) l3, vader_ref_box(l5));
    l3 = ((vader_struct_vader_bytecode_BcFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_slot)->f_jump_table;
    t0 = ((int64_t) (int32_t) l4);
    l6 = (size_t) (int64_t) t0;
    l4 = (l4 + INT32_C(1));
    vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l6)
    ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l6] = (int32_t) l4;
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_midir_close_blocks(void* l0, void* l1, void* l2, int32_t l3) {
    size_t l4, l5, l7, l8, l9;
    int32_t l6, l11, l13;
    void* l10 = NULL;
    void* l12 = NULL;
    int64_t t0;
    void* t1 = NULL;
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l10, &l12, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 6u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l4 = (size_t) 0;
    l5 = ((vader_array_t*) l2)->length;
    while ((l4 < l5)) {
        t0 = (l4 + INT64_C(1));
        l7 = (size_t) (int64_t) t0;
        l8 = ((vader_array_t*) l2)->length;
        if ((l7 < l8)) {
            t0 = (l4 + INT64_C(1));
            l9 = (size_t) (int64_t) t0;
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
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
        l11 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
        vader_array_t* _a2_slotarr = ((vader_array_t*) l10);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l11)
        t1 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l11);
        l12 = ((vader_struct_vader_midir_BasicBlock_t*) t1)->f_span;
        vader_midir_cf_end(l0, l12);
        vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l4)
        l13 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l4];
        vader_midir_emit_subtree(l0, l1, l13, l6);
        t0 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t0;
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static bool vader_midir_closes_loop(void* l0, int32_t l1, int32_t l2) {
    vader_box_t l3;
    void* t0;
    bool t1;
    l3 = std_collections_MutableMap_Index_at__i32__Any(l0, l2);
    if (l3.tag == 0u) {
        return false;
    }
    t0 = l3.payload.obj;
    t1 = std_collections_MutableSet_Contains_contains__i32(t0, l1);
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
    if (l0.tag == 1080u) {
        t0 = l0.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a0_arr = vader_array_new(204u, 0u, 13u, 1535u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(11u, 0u, 12u, 241u);
    l2 = (void*) _a1_arr;
    t0 = (void*) &vader_data_19;
    vader_array_t* _a2_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    l3 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) INT64_C(0));
    vader_struct_vader_types_FnType_t* _a3_obj = (vader_struct_vader_types_FnType_t*) vader_gc_alloc(sizeof(vader_struct_vader_types_FnType_t));
    vader_obj_header_init(_a3_obj, 1080u);
    _a3_obj->f_params = l1;
    _a3_obj->f_params_mutable = l2;
    _a3_obj->f_return_type = vader_ref_box(l3);
    t0 = (void*) _a3_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_midir_collect_baked_symbols(vader_box_t l0, void* l1) {
    int32_t l2;
    void* l3 = NULL;
    size_t l4, l5;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    int64_t t2;
    vader_box_t* gc_roots[2] = { &l0, &t1 };
    void** gc_raw_roots[3] = { &l1, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 566u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_bytecode_BcValStruct_t*) t0)->f_symbol_id;
        std_collections_add__i32(l1, l2);
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_bytecode_BcValStruct_t*) t0)->f_fields;
        l4 = ((vader_array_t*) l3)->length;
        l5 = (size_t) 0;
        while ((l5 < l4)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
            t1 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
            vader_midir_collect_baked_symbols(t1, l1);
            t2 = (l5 + INT64_C(1));
            l5 = (size_t) (int64_t) t2;
        }
    } else if (l0.tag == 563u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_bytecode_BcValArray_t*) t0)->f_elements;
        l4 = ((vader_array_t*) l3)->length;
        l5 = (size_t) 0;
        while ((l5 < l4)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
            t1 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5);
            vader_midir_collect_baked_symbols(t1, l1);
            t2 = (l5 + INT64_C(1));
            l5 = (size_t) (int64_t) t2;
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void* vader_midir_compact_locals(void* l0) {
    size_t l1, l4, l5, l7, l9, l14, l15, l17, l19;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l6 = NULL;
    void* l8 = NULL;
    void* l11 = NULL;
    void* l13 = NULL;
    void* l21 = NULL;
    void* l25 = NULL;
    void* l26 = NULL;
    void* l27 = NULL;
    void* l28 = NULL;
    vader_box_t l10 = vader_box_null(), l12 = vader_box_null(), l18 = vader_box_null(), l20 = vader_box_null();
    int32_t l16, l23;
    bool l22, l30;
    vader_string_t l24 = 0;
    vader_string_t l29 = 0;
    void* t0 = NULL;
    int64_t t1;
    bool t2;
    int32_t t3;
    vader_box_t t4 = vader_box_null();
    size_t t5;
    vader_box_t* gc_roots[5] = { &l10, &l12, &l18, &l20, &t4 };
    void** gc_raw_roots[13] = {
        &l0, &l2, &l3, &l6, &l8, &l11, &l13, &l21, &l25, &l26, &l27, &l28, &t0,
    };
    vader_string_t* gc_atom_roots[2] = { &l24, &l29 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 5u, 13u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = ((vader_array_t*) ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_locals)->length;
    vader_array_t* _a0_arr = vader_array_new(11u, 1u, 12u, 241u);
    ((uint8_t*) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = (uint8_t) false;
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (size_t) l1);
    l2 = (void*) _a1_arr;
    l3 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_params;
    l4 = ((vader_array_t*) l3)->length;
    l5 = (size_t) 0;
    while ((l5 < l4)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        l6 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l5);
        if ((((int64_t) (int32_t) ((vader_struct_vader_midir_CFGParam_t*) l6)->f_local) < l1)) {
            t1 = ((int64_t) (int32_t) ((vader_struct_vader_midir_CFGParam_t*) l6)->f_local);
            l7 = (size_t) (int64_t) t1;
            vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l7)
            ((uint8_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l7] = (uint8_t) true;
        }
        t1 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t1;
    }
    l3 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_blocks;
    l4 = ((vader_array_t*) l3)->length;
    l5 = (size_t) 0;
    while ((l5 < l4)) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l5)
        l6 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l5);
        l8 = ((vader_struct_vader_midir_BasicBlock_t*) l6)->f_instructions;
        l7 = ((vader_array_t*) l8)->length;
        l9 = (size_t) 0;
        while ((l9 < l7)) {
            vader_array_t* _a5_slotarr = ((vader_array_t*) l8);
            VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l9)
            l10 = vader_array_ref_load_box(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l9);
            vader_struct___lambda_env_vader_midir_1_t* _a6_obj = (vader_struct___lambda_env_vader_midir_1_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_midir_1_t));
            vader_obj_header_init(_a6_obj, 270u);
            _a6_obj->f_cap_0 = l1;
            _a6_obj->f_cap_1 = l2;
            t0 = (void*) _a6_obj;
            vader_fn_t* _a7_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
            vader_obj_header_init(_a7_closure, 215u);
            _a7_closure->code = (void*) &vader_fn_lift___lambda_vader_midir_0;
            _a7_closure->env = t0;
            l11 = (void*) _a7_closure;
            vader_midir_for_each_read_local(l10, l11);
            t2 = vader_midir_instruction_has_side_effect(l10);
            if (t2) {
                l12 = vader_midir_multi_dsts(l10);
                if (l12.tag == 0u) {
                    l18 = vader_midir_dst_of(l10);
                    if (!(l18.tag == 0u)) {
                        t3 = ((int32_t) l18.payload.i);
                        if ((((int64_t) (int32_t) t3) < l1)) {
                            t3 = ((int32_t) l18.payload.i);
                            t1 = ((int64_t) (int32_t) t3);
                            l19 = (size_t) (int64_t) t1;
                            vader_array_t* _a8_slotarr = ((vader_array_t*) l2);
                            VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
                            VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l19)
                            ((uint8_t*) _a8_slotarr->buf->slots)[_a8_slotarr->offset + (size_t) l19] = (uint8_t) true;
                        }
                    }
                } else {
                    l13 = l12.payload.obj;
                    l14 = ((vader_array_t*) l13)->length;
                    l15 = (size_t) 0;
                    while ((l15 < l14)) {
                        vader_array_t* _a9_slotarr = ((vader_array_t*) l13);
                        VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
                        l16 = ((int32_t*) _a9_slotarr->buf->slots)[_a9_slotarr->offset + (size_t) l15];
                        if ((((int64_t) (int32_t) l16) < l1)) {
                            t1 = ((int64_t) (int32_t) l16);
                            l17 = (size_t) (int64_t) t1;
                            vader_array_t* _a10_slotarr = ((vader_array_t*) l2);
                            VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
                            VADER_ARRAY_CHECK_INDEX(_a10_slotarr, l17)
                            ((uint8_t*) _a10_slotarr->buf->slots)[_a10_slotarr->offset + (size_t) l17] = (uint8_t) true;
                        }
                        t1 = (l15 + INT64_C(1));
                        l15 = (size_t) (int64_t) t1;
                    }
                }
            }
            t1 = (l9 + INT64_C(1));
            l9 = (size_t) (int64_t) t1;
        }
        l20 = ((vader_struct_vader_midir_BasicBlock_t*) l6)->f_terminator;
        vader_struct___lambda_env_vader_midir_3_t* _a11_obj = (vader_struct___lambda_env_vader_midir_3_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_midir_3_t));
        vader_obj_header_init(_a11_obj, 275u);
        _a11_obj->f_cap_0 = l1;
        _a11_obj->f_cap_1 = l2;
        t0 = (void*) _a11_obj;
        vader_fn_t* _a12_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
        vader_obj_header_init(_a12_closure, 215u);
        _a12_closure->code = (void*) &vader_fn_lift___lambda_vader_midir_2;
        _a12_closure->env = t0;
        l21 = (void*) _a12_closure;
        vader_midir_for_each_read_in_terminator(l20, l21);
        t1 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t1;
    }
    l22 = false;
    l4 = ((vader_array_t*) ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_params)->length;
    for (;;) {
        if ((l4 < l1)) {
            vader_array_t* _a13_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a13_slotarr, l4)
            t4 = vader_box_bool(241u, ((uint8_t*) _a13_slotarr->buf->slots)[_a13_slotarr->offset + (size_t) l4]);
            t2 = t4.payload.b;
            if (t2) {
                t1 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t1;
                continue;
            }
            l22 = true;
            break;
        }
        break;
    }
    if (!(l22)) {
        { void* __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a14_arr = vader_array_new(14u, 0u, 7u, 246u);
    t0 = (void*) _a14_arr;
    vader_array_t* _a15_arr = vader_array_repeat((vader_array_t*) t0, (size_t) l1);
    l3 = (void*) _a15_arr;
    vader_array_t* _a16_arr = vader_array_new(105u, 0u, 13u, 919u);
    t0 = (void*) _a16_arr;
    vader_array_t* _a17_arr = vader_array_repeat((vader_array_t*) t0, (size_t) l1);
    l6 = (void*) _a17_arr;
    l4 = (size_t) 0;
    while ((l4 < l1)) {
        vader_array_t* _a18_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a18_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a18_slotarr, l4)
        t4 = vader_box_bool(241u, ((uint8_t*) _a18_slotarr->buf->slots)[_a18_slotarr->offset + (size_t) l4]);
        t2 = t4.payload.b;
        if (t2) {
            t5 = ((vader_array_t*) l6)->length;
            l23 = ((int32_t) (size_t) t5);
            vader_array_push_i32((vader_array_t*) l3, l23);
            vader_array_t* _a19_slotarr = ((vader_array_t*) ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_locals);
            VADER_ARRAY_RESOLVE_BUF(_a19_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a19_slotarr, l4)
            l8 = vader_array_ref_load_obj(_a19_slotarr->buf, _a19_slotarr->offset + (size_t) l4);
            vader_array_push((vader_array_t*) l6, vader_ref_box(l8));
            t1 = (l4 + INT64_C(1));
            l4 = (size_t) (int64_t) t1;
            continue;
        }
        l16 = -(INT32_C(1));
        vader_array_push_i32((vader_array_t*) l3, l16);
        t1 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t1;
    }
    vader_array_t* _a20_arr = vader_array_new(107u, 0u, 13u, 921u);
    l2 = (void*) _a20_arr;
    l1 = ((vader_array_t*) ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_params)->length;
    vader_array_t* _a21_arr = vader_array_repeat((vader_array_t*) l2, (size_t) l1);
    l2 = (void*) _a21_arr;
    l8 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_params;
    l1 = ((vader_array_t*) l8)->length;
    l4 = (size_t) 0;
    while ((l4 < l1)) {
        vader_array_t* _a22_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a22_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a22_slotarr, l4)
        l11 = vader_array_ref_load_obj(_a22_slotarr->buf, _a22_slotarr->offset + (size_t) l4);
        l24 = ((vader_struct_vader_midir_CFGParam_t*) l11)->f_name;
        l13 = ((vader_struct_vader_midir_CFGParam_t*) l11)->f_symbol;
        l10 = ((vader_struct_vader_midir_CFGParam_t*) l11)->f_type;
        t1 = ((int64_t) (int32_t) ((vader_struct_vader_midir_CFGParam_t*) l11)->f_local);
        l5 = (size_t) (int64_t) t1;
        vader_array_t* _a23_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a23_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a23_slotarr, l5)
        l16 = ((int32_t*) _a23_slotarr->buf->slots)[_a23_slotarr->offset + (size_t) l5];
        vader_struct_vader_midir_CFGParam_t* _a24_obj = (vader_struct_vader_midir_CFGParam_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_CFGParam_t));
        vader_obj_header_init(_a24_obj, 921u);
        _a24_obj->f_name = l24;
        _a24_obj->f_symbol = l13;
        _a24_obj->f_type = l10;
        _a24_obj->f_local = l16;
        l21 = (void*) _a24_obj;
        vader_array_push((vader_array_t*) l2, vader_ref_box(l21));
        t1 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t1;
    }
    vader_array_t* _a25_arr = vader_array_new(102u, 0u, 13u, 916u);
    l8 = (void*) _a25_arr;
    l1 = ((vader_array_t*) ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_blocks)->length;
    vader_array_t* _a26_arr = vader_array_repeat((vader_array_t*) l8, (size_t) l1);
    l8 = (void*) _a26_arr;
    l11 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_blocks;
    l1 = ((vader_array_t*) l11)->length;
    l4 = (size_t) 0;
    while ((l4 < l1)) {
        vader_array_t* _a27_slotarr = ((vader_array_t*) l11);
        VADER_ARRAY_RESOLVE_BUF(_a27_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a27_slotarr, l4)
        l13 = vader_array_ref_load_obj(_a27_slotarr->buf, _a27_slotarr->offset + (size_t) l4);
        vader_array_t* _a28_arr = vader_array_new(203u, 0u, 13u, 1503u);
        l21 = (void*) _a28_arr;
        l5 = ((vader_array_t*) ((vader_struct_vader_midir_BasicBlock_t*) l13)->f_instructions)->length;
        vader_array_t* _a29_arr = vader_array_repeat((vader_array_t*) l21, (size_t) l5);
        l25 = (void*) _a29_arr;
        l26 = ((vader_struct_vader_midir_BasicBlock_t*) l13)->f_instructions;
        l7 = ((vader_array_t*) l26)->length;
        l9 = (size_t) 0;
        while ((l9 < l7)) {
            vader_array_t* _a30_slotarr = ((vader_array_t*) l26);
            VADER_ARRAY_RESOLVE_BUF(_a30_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a30_slotarr, l9)
            l10 = vader_array_ref_load_box(_a30_slotarr->buf, _a30_slotarr->offset + (size_t) l9);
            l12 = vader_midir_dst_of(l10);
            if (l12.tag == 246u) {
                t3 = ((int32_t) l12.payload.i);
                t1 = ((int64_t) (int32_t) t3);
                l14 = (size_t) (int64_t) t1;
                l15 = ((vader_array_t*) l3)->length;
                if ((l14 < l15)) {
                    t3 = ((int32_t) l12.payload.i);
                    t1 = ((int64_t) (int32_t) t3);
                    l17 = (size_t) (int64_t) t1;
                    vader_array_t* _a31_slotarr = ((vader_array_t*) l3);
                    VADER_ARRAY_RESOLVE_BUF(_a31_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a31_slotarr, l17)
                    t3 = ((int32_t*) _a31_slotarr->buf->slots)[_a31_slotarr->offset + (size_t) l17];
                    if ((t3 < INT32_C(0))) {
                        t2 = vader_midir_instruction_has_side_effect(l10);
                        if (!(t2)) {
                            t1 = (l9 + INT64_C(1));
                            l9 = (size_t) (int64_t) t1;
                            continue;
                        }
                    }
                }
            }
            l18 = vader_midir_remap_instr(l10, l3);
            vader_array_push((vader_array_t*) l25, l18);
            t1 = (l9 + INT64_C(1));
            l9 = (size_t) (int64_t) t1;
        }
        l16 = ((vader_struct_vader_midir_BasicBlock_t*) l13)->f_id;
        l20 = vader_midir_remap_terminator(((vader_struct_vader_midir_BasicBlock_t*) l13)->f_terminator, l3);
        l27 = ((vader_struct_vader_midir_BasicBlock_t*) l13)->f_span;
        vader_struct_vader_midir_BasicBlock_t* _a32_obj = (vader_struct_vader_midir_BasicBlock_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_BasicBlock_t));
        vader_obj_header_init(_a32_obj, 916u);
        _a32_obj->f_id = l16;
        _a32_obj->f_instructions = l25;
        _a32_obj->f_terminator = l20;
        _a32_obj->f_span = l27;
        l28 = (void*) _a32_obj;
        vader_array_push((vader_array_t*) l8, vader_ref_box(l28));
        t1 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t1;
    }
    l3 = l0;
    l24 = ((vader_struct_vader_midir_CFGFunction_t*) l3)->f_mangled;
    l10 = ((vader_struct_vader_midir_CFGFunction_t*) l3)->f_return_type;
    l16 = ((vader_struct_vader_midir_CFGFunction_t*) l3)->f_entry;
    l11 = ((vader_struct_vader_midir_CFGFunction_t*) l3)->f_origin;
    l29 = ((vader_struct_vader_midir_CFGFunction_t*) l3)->f_extern_name;
    l22 = ((vader_struct_vader_midir_CFGFunction_t*) l3)->f_is_extern;
    l30 = ((vader_struct_vader_midir_CFGFunction_t*) l3)->f_is_exported;
    l3 = ((vader_struct_vader_midir_CFGFunction_t*) l3)->f_scalarised_results;
    vader_struct_vader_midir_CFGFunction_t* _a33_obj = (vader_struct_vader_midir_CFGFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_CFGFunction_t));
    vader_obj_header_init(_a33_obj, 918u);
    _a33_obj->f_mangled = l24;
    _a33_obj->f_params = l2;
    _a33_obj->f_return_type = l10;
    _a33_obj->f_locals = l6;
    _a33_obj->f_blocks = l8;
    _a33_obj->f_entry = l16;
    _a33_obj->f_origin = l11;
    _a33_obj->f_extern_name = l29;
    _a33_obj->f_is_extern = l22;
    _a33_obj->f_is_exported = l30;
    _a33_obj->f_scalarised_results = l3;
    t0 = (void*) _a33_obj;
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
    size_t l8, l9, l19, l20, l25, l26, l30, l31, l39, l40;
    int32_t l10, l11, l21, l23, l32, l34, l36, l41;
    vader_box_t l12 = vader_box_null(), l27 = vader_box_null(), l28 = vader_box_null(), l33 = vader_box_null();
    void* t0 = NULL;
    bool t1;
    int64_t t2;
    size_t t3;
    vader_box_t* gc_roots[4] = { &l12, &l27, &l28, &l33 };
    void** gc_raw_roots[21] = {
        &l0, &l1, &l2, &l3, &l4, &l5, &l6, &l7, &l13, &l14, &l15, &l16, &l17, &l18, &l22, &l24,
        &l29, &l35, &l37, &l38, &t0,
    };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 21u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(14u, 0u, 7u, 246u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(11u, 0u, 12u, 241u);
    l3 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(14u, 0u, 7u, 246u);
    l4 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__i32__bool_t* _a3_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
    vader_obj_header_init(_a3_obj, 328u);
    _a3_obj->f_ekeys = l2;
    _a3_obj->f_evals = l3;
    _a3_obj->f_index = l4;
    _a3_obj->f_mask = (size_t) 0;
    _a3_obj->f_size = (size_t) 0;
    _a3_obj->f_tombs = (size_t) 0;
    t0 = (void*) _a3_obj;
    vader_struct_std_collections_MutableSet__i32_t* _a4_obj = (vader_struct_std_collections_MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i32_t));
    vader_obj_header_init(_a4_obj, 425u);
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
    l6 = ((vader_struct_std_collections_MutableMap__i32__MutableSet_i32__t*) l5)->f_ekeys;
    l7 = ((vader_struct_std_collections_MutableMap__i32__MutableSet_i32__t*) l5)->f_evals;
    l8 = ((vader_struct_std_collections_MutableMap__i32__MutableSet_i32__t*) l5)->f_size;
    l9 = (size_t) 0;
    while (!((l9 >= l8))) {
        vader_array_t* _a5_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l9)
        l10 = ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l9];
        vader_array_t* _a6_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l9)
        t0 = vader_array_ref_load_obj(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l9);
        l11 = l10;
        t2 = (l9 + INT64_C(1));
        l9 = (size_t) (int64_t) t2;
        l12 = std_collections_MutableMap_Index_at__i32__Any(l3, l11);
        if (l12.tag == 0u) {
            continue;
        }
        l5 = l12.payload.obj;
        vader_array_t* _a7_arr = vader_array_new(14u, 0u, 7u, 246u);
        l13 = (void*) _a7_arr;
        vader_array_t* _a8_arr = vader_array_new(11u, 0u, 12u, 241u);
        l14 = (void*) _a8_arr;
        vader_array_t* _a9_arr = vader_array_new(14u, 0u, 7u, 246u);
        l15 = (void*) _a9_arr;
        vader_struct_std_collections_MutableMap__i32__bool_t* _a10_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
        vader_obj_header_init(_a10_obj, 328u);
        _a10_obj->f_ekeys = l13;
        _a10_obj->f_evals = l14;
        _a10_obj->f_index = l15;
        _a10_obj->f_mask = (size_t) 0;
        _a10_obj->f_size = (size_t) 0;
        _a10_obj->f_tombs = (size_t) 0;
        t0 = (void*) _a10_obj;
        vader_struct_std_collections_MutableSet__i32_t* _a11_obj = (vader_struct_std_collections_MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i32_t));
        vader_obj_header_init(_a11_obj, 425u);
        _a11_obj->f_inner = t0;
        l16 = (void*) _a11_obj;
        l17 = l5;
        l18 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) ((vader_struct_std_collections_MutableSet__i32_t*) l17)->f_inner)->f_ekeys;
        l19 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) ((vader_struct_std_collections_MutableSet__i32_t*) l17)->f_inner)->f_size;
        l20 = (size_t) 0;
        while (!((l20 >= l19))) {
            vader_array_t* _a12_slotarr = ((vader_array_t*) l18);
            VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a12_slotarr, l20)
            l21 = ((int32_t*) _a12_slotarr->buf->slots)[_a12_slotarr->offset + (size_t) l20];
            t2 = (l20 + INT64_C(1));
            l20 = (size_t) (int64_t) t2;
            l22 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_blocks;
            l23 = l21;
            vader_array_t* _a13_slotarr = ((vader_array_t*) l22);
            VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a13_slotarr, l23)
            t0 = vader_array_ref_load_obj(_a13_slotarr->buf, _a13_slotarr->offset + (size_t) l23);
            l24 = ((vader_struct_vader_midir_BasicBlock_t*) t0)->f_instructions;
            l25 = ((vader_array_t*) l24)->length;
            l26 = (size_t) 0;
            while ((l26 < l25)) {
                vader_array_t* _a14_slotarr = ((vader_array_t*) l24);
                VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a14_slotarr, l26)
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
                    l31 = (size_t) 0;
                    while ((l31 < l30)) {
                        vader_array_t* _a15_slotarr = ((vader_array_t*) l29);
                        VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a15_slotarr, l31)
                        l32 = ((int32_t*) _a15_slotarr->buf->slots)[_a15_slotarr->offset + (size_t) l31];
                        std_collections_add__i32(l16, l32);
                        t2 = (l31 + INT64_C(1));
                        l31 = (size_t) (int64_t) t2;
                    }
                }
                t2 = (l26 + INT64_C(1));
                l26 = (size_t) (int64_t) t2;
            }
        }
        l35 = ((vader_struct_vader_midir_Liveness_t*) l4)->f_live_in;
        l36 = l11;
        vader_array_t* _a16_slotarr = ((vader_array_t*) l35);
        VADER_ARRAY_RESOLVE_BUF(_a16_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a16_slotarr, l36)
        l37 = vader_array_ref_load_obj(_a16_slotarr->buf, _a16_slotarr->offset + (size_t) l36);
        l38 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) ((vader_struct_std_collections_MutableSet__i32_t*) l37)->f_inner)->f_ekeys;
        l39 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) ((vader_struct_std_collections_MutableSet__i32_t*) l37)->f_inner)->f_size;
        l40 = (size_t) 0;
        while (!((l40 >= l39))) {
            vader_array_t* _a17_slotarr = ((vader_array_t*) l38);
            VADER_ARRAY_RESOLVE_BUF(_a17_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a17_slotarr, l40)
            l41 = ((int32_t*) _a17_slotarr->buf->slots)[_a17_slotarr->offset + (size_t) l40];
            t2 = (l40 + INT64_C(1));
            l40 = (size_t) (int64_t) t2;
            t1 = std_collections_MutableSet_Contains_contains__i32(l16, l41);
            if (!(t1)) {
                continue;
            }
            std_collections_add__i32(l2, l41);
        }
    }
    vader_array_t* _a18_arr = vader_array_new(14u, 0u, 7u, 246u);
    l3 = (void*) _a18_arr;
    l4 = l2;
    l5 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) ((vader_struct_std_collections_MutableSet__i32_t*) l4)->f_inner)->f_ekeys;
    l8 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) ((vader_struct_std_collections_MutableSet__i32_t*) l4)->f_inner)->f_size;
    l9 = (size_t) 0;
    vader_array_t* _pc257_hdr = (vader_array_t*) l3;
    size_t _pc257_len = _pc257_hdr->length;
    size_t _pc257_cap = (_pc257_hdr->offset == 0 && !vader_array_is_borrowed(_pc257_hdr) && _pc257_hdr->length >= _pc257_hdr->buf->length) ? _pc257_hdr->capacity : (size_t) 0;
    void* _pc257_slots = _pc257_hdr->buf->slots;
    for (;;) {
        if (!((l9 >= l8))) {
            vader_array_t* _a19_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a19_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a19_slotarr, l9)
            l10 = ((int32_t*) _a19_slotarr->buf->slots)[_a19_slotarr->offset + (size_t) l9];
            t2 = (l9 + INT64_C(1));
            l9 = (size_t) (int64_t) t2;
            if (VADER_LIKELY(_pc257_len < _pc257_cap)) {
                ((int32_t*) _pc257_slots)[_pc257_len] = (int32_t) (l10);
                _pc257_len += 1;
            } else {
                _pc257_hdr->length = _pc257_len;
                if (_pc257_hdr->buf->length < _pc257_len) {
                    _pc257_hdr->buf->length = _pc257_len;
                }
                vader_array_push_i32((vader_array_t*) l3, l10);
                _pc257_hdr = (vader_array_t*) l3;
                _pc257_len = _pc257_hdr->length;
                _pc257_cap = (_pc257_hdr->offset == 0 && !vader_array_is_borrowed(_pc257_hdr) && _pc257_hdr->length >= _pc257_hdr->buf->length) ? _pc257_hdr->capacity : (size_t) 0;
                _pc257_slots = _pc257_hdr->buf->slots;
            }
            continue;
        }
        _pc257_hdr->length = _pc257_len;
        if (_pc257_hdr->buf->length < _pc257_len) {
            _pc257_hdr->buf->length = _pc257_len;
        }
        break;
    }
    for (;;) {
        t3 = ((vader_array_t*) l3)->length;
        if ((t3 > INT64_C(0))) {
            t3 = ((vader_array_t*) l3)->length;
            t2 = (t3 - INT64_C(1));
            l8 = (size_t) (int64_t) t2;
            vader_array_t* _a20_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a20_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a20_slotarr, l8)
            l10 = ((int32_t*) _a20_slotarr->buf->slots)[_a20_slotarr->offset + (size_t) l8];
            t3 = ((vader_array_t*) l3)->length;
            t2 = (t3 - INT64_C(1));
            l9 = (size_t) (int64_t) t2;
            vader_array_t* _a21_arr = vader_array_slice((vader_array_t*) l3, (size_t) INT64_C(0), (size_t) l9);
            l3 = (void*) _a21_arr;
            l12 = std_collections_MutableMap_Index_at__i32__Any(l1, l10);
            if (l12.tag == 0u) {
                continue;
            }
            l4 = l12.payload.obj;
            l19 = ((vader_array_t*) l4)->length;
            l20 = (size_t) 0;
            while ((l20 < l19)) {
                vader_array_t* _a22_slotarr = ((vader_array_t*) l4);
                VADER_ARRAY_RESOLVE_BUF(_a22_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a22_slotarr, l20)
                l11 = ((int32_t*) _a22_slotarr->buf->slots)[_a22_slotarr->offset + (size_t) l20];
                t1 = std_collections_MutableSet_Contains_contains__i32(l2, l11);
                if (t1) {
                    t2 = (l20 + INT64_C(1));
                    l20 = (size_t) (int64_t) t2;
                    continue;
                }
                std_collections_add__i32(l2, l11);
                vader_array_push_i32((vader_array_t*) l3, l11);
                t2 = (l20 + INT64_C(1));
                l20 = (size_t) (int64_t) t2;
            }
            continue;
        }
        break;
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_midir_compute_dominators(void* l0, void* l1) {
    size_t l2, l9, l13, l14;
    void* l3 = NULL;
    void* l6 = NULL;
    void* l8 = NULL;
    void* l12 = NULL;
    int32_t l4, l5, l10, l11, l15, l16, l17, l18, l19, l20, l21, l22, l23;
    bool l7;
    void* t0 = NULL;
    bool t1;
    int64_t t2;
    int32_t t3;
    void** gc_raw_roots[7] = { &l0, &l1, &l3, &l6, &l8, &l12, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 7u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_array_t*) ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_blocks)->length;
    vader_array_t* _a0_arr = vader_array_new(14u, 1u, 7u, 246u);
    ((int32_t*) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = (int32_t) -(INT32_C(1));
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (size_t) l2);
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
        l9 = (size_t) 0;
        while ((l9 < l2)) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l8);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l9)
            l4 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l9];
            l5 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_entry;
            t1 = vader_midir_BlockId_Equals_equals(l4, l5);
            if (t1) {
                t2 = (l9 + INT64_C(1));
                l9 = (size_t) (int64_t) t2;
                continue;
            }
            l10 = -(INT32_C(1));
            l11 = l4;
            vader_array_t* _a4_slotarr = ((vader_array_t*) l1);
            VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l11)
            l12 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l11);
            l13 = ((vader_array_t*) l12)->length;
            l14 = (size_t) 0;
            while ((l14 < l13)) {
                vader_array_t* _a5_slotarr = ((vader_array_t*) l12);
                VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l14)
                l15 = ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l14];
                l16 = l15;
                vader_array_t* _a6_slotarr = ((vader_array_t*) l3);
                VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l16)
                l17 = ((int32_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l16];
                l18 = -(INT32_C(1));
                if (l17 == l18) {
                    t2 = (l14 + INT64_C(1));
                    l14 = (size_t) (int64_t) t2;
                    continue;
                }
                l19 = -(INT32_C(1));
                if (l10 == l19) {
                    l10 = l15;
                } else {
                    l20 = l10;
                    l10 = vader_midir_intersect_dom_tree(l15, l20, l3);
                }
                t2 = (l14 + INT64_C(1));
                l14 = (size_t) (int64_t) t2;
            }
            l21 = -(INT32_C(1));
            if (l10 != l21) {
                l22 = l4;
                vader_array_t* _a7_slotarr = ((vader_array_t*) l3);
                VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l22)
                t3 = ((int32_t*) _a7_slotarr->buf->slots)[_a7_slotarr->offset + (size_t) l22];
                if (t3 != l10) {
                    l23 = l4;
                    vader_array_t* _a8_slotarr = ((vader_array_t*) l3);
                    VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l23)
                    ((int32_t*) _a8_slotarr->buf->slots)[_a8_slotarr->offset + (size_t) l23] = (int32_t) l10;
                    l7 = true;
                }
            }
            t2 = (l9 + INT64_C(1));
            l9 = (size_t) (int64_t) t2;
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
    void* l28 = NULL;
    void* l33 = NULL;
    void* l38 = NULL;
    void* l42 = NULL;
    void* l47 = NULL;
    void* l52 = NULL;
    void* l59 = NULL;
    size_t l7, l8, l10, l11, l29, l30, l34, l35, l39, l40, l43, l44, l48, l49, l53, l54, l60, l61;
    vader_box_t l12 = vader_box_null();
    int32_t l13, l14, l15, l16, l17, l18, l19, l20, l21, l22, l23, l24, l25, l26, l27, l31, l32, l36, l37, l41, l45, l46, l50, l51, l55, l56, l57, l58, l62;
    void* t0 = NULL;
    int64_t t1;
    bool t2;
    size_t t3;
    vader_box_t* gc_roots[1] = { &l12 };
    void** gc_raw_roots[16] = {
        &l0, &l1, &l2, &l3, &l4, &l5, &l6, &l9, &l28, &l33, &l38, &l42, &l47, &l52, &l59, &t0,
    };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 16u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(14u, 0u, 7u, 246u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(11u, 0u, 12u, 241u);
    l3 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(14u, 0u, 7u, 246u);
    l4 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__i32__bool_t* _a3_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
    vader_obj_header_init(_a3_obj, 328u);
    _a3_obj->f_ekeys = l2;
    _a3_obj->f_evals = l3;
    _a3_obj->f_index = l4;
    _a3_obj->f_mask = (size_t) 0;
    _a3_obj->f_size = (size_t) 0;
    _a3_obj->f_tombs = (size_t) 0;
    t0 = (void*) _a3_obj;
    vader_struct_std_collections_MutableSet__i32_t* _a4_obj = (vader_struct_std_collections_MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i32_t));
    vader_obj_header_init(_a4_obj, 425u);
    _a4_obj->f_inner = t0;
    l2 = (void*) _a4_obj;
    vader_array_t* _a5_arr = vader_array_new(14u, 0u, 7u, 246u);
    l3 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(21u, 0u, 0u, 254u);
    l4 = (void*) _a6_arr;
    vader_array_t* _a7_arr = vader_array_new(14u, 0u, 7u, 246u);
    l5 = (void*) _a7_arr;
    vader_struct_std_collections_MutableMap__i32__Any___t* _a8_obj = (vader_struct_std_collections_MutableMap__i32__Any___t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__Any___t));
    vader_obj_header_init(_a8_obj, 297u);
    _a8_obj->f_ekeys = l3;
    _a8_obj->f_evals = l4;
    _a8_obj->f_index = l5;
    _a8_obj->f_mask = (size_t) 0;
    _a8_obj->f_size = (size_t) 0;
    _a8_obj->f_tombs = (size_t) 0;
    l3 = (void*) _a8_obj;
    vader_array_t* _a9_arr = vader_array_new(14u, 0u, 7u, 246u);
    l4 = (void*) _a9_arr;
    vader_array_t* _a10_arr = vader_array_new(21u, 0u, 0u, 254u);
    l5 = (void*) _a10_arr;
    vader_array_t* _a11_arr = vader_array_new(14u, 0u, 7u, 246u);
    l6 = (void*) _a11_arr;
    vader_struct_std_collections_MutableMap__i32__Any___t* _a12_obj = (vader_struct_std_collections_MutableMap__i32__Any___t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__Any___t));
    vader_obj_header_init(_a12_obj, 297u);
    _a12_obj->f_ekeys = l4;
    _a12_obj->f_evals = l5;
    _a12_obj->f_index = l6;
    _a12_obj->f_mask = (size_t) 0;
    _a12_obj->f_size = (size_t) 0;
    _a12_obj->f_tombs = (size_t) 0;
    l4 = (void*) _a12_obj;
    l5 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_blocks;
    l7 = ((vader_array_t*) l5)->length;
    l8 = (size_t) 0;
    while ((l8 < l7)) {
        vader_array_t* _a13_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a13_slotarr, l8)
        l6 = vader_array_ref_load_obj(_a13_slotarr->buf, _a13_slotarr->offset + (size_t) l8);
        l9 = ((vader_struct_vader_midir_BasicBlock_t*) l6)->f_instructions;
        l10 = ((vader_array_t*) l9)->length;
        l11 = (size_t) 0;
        while ((l11 < l10)) {
            vader_array_t* _a14_slotarr = ((vader_array_t*) l9);
            VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a14_slotarr, l11)
            l12 = vader_array_ref_load_box(_a14_slotarr->buf, _a14_slotarr->offset + (size_t) l11);
            if (l12.tag == 962u) {
                t0 = l12.payload.obj;
                l13 = ((vader_struct_vader_midir_InstrMove_t*) t0)->f_dst;
                t0 = l12.payload.obj;
                l14 = ((vader_struct_vader_midir_InstrMove_t*) t0)->f_src;
                vader_midir_record_alias(l3, l4, l13, l14);
            } else if (l12.tag == 948u) {
                t0 = l12.payload.obj;
                l15 = ((vader_struct_vader_midir_InstrCast_t*) t0)->f_dst;
                t0 = l12.payload.obj;
                l16 = ((vader_struct_vader_midir_InstrCast_t*) t0)->f_value;
                vader_midir_record_alias(l3, l4, l15, l16);
            } else if (l12.tag == 957u) {
                t0 = l12.payload.obj;
                l17 = ((vader_struct_vader_midir_InstrFieldSet_t*) t0)->f_value;
                std_collections_add__i32(l2, l17);
            } else if (l12.tag == 943u) {
                t0 = l12.payload.obj;
                l18 = ((vader_struct_vader_midir_InstrArraySet_t*) t0)->f_value;
                std_collections_add__i32(l2, l18);
                t0 = l12.payload.obj;
                l19 = ((vader_struct_vader_midir_InstrArraySet_t*) t0)->f_target;
                std_collections_add__i32(l2, l19);
            } else if (l12.tag == 942u) {
                t0 = l12.payload.obj;
                l20 = ((vader_struct_vader_midir_InstrArrayPush_t*) t0)->f_value;
                std_collections_add__i32(l2, l20);
                t0 = l12.payload.obj;
                l21 = ((vader_struct_vader_midir_InstrArrayPush_t*) t0)->f_target;
                std_collections_add__i32(l2, l21);
            } else if (l12.tag == 944u) {
                t0 = l12.payload.obj;
                l22 = ((vader_struct_vader_midir_InstrArraySlice_t*) t0)->f_target;
                std_collections_add__i32(l2, l22);
                t0 = l12.payload.obj;
                l23 = ((vader_struct_vader_midir_InstrArraySlice_t*) t0)->f_lo;
                std_collections_add__i32(l2, l23);
                t0 = l12.payload.obj;
                l24 = ((vader_struct_vader_midir_InstrArraySlice_t*) t0)->f_hi;
                std_collections_add__i32(l2, l24);
            } else if (l12.tag == 950u) {
                t0 = l12.payload.obj;
                l25 = ((vader_struct_vader_midir_InstrCellNew_t*) t0)->f_value;
                std_collections_add__i32(l2, l25);
            } else if (l12.tag == 951u) {
                t0 = l12.payload.obj;
                l26 = ((vader_struct_vader_midir_InstrCellSet_t*) t0)->f_value;
                std_collections_add__i32(l2, l26);
                t0 = l12.payload.obj;
                l27 = ((vader_struct_vader_midir_InstrCellSet_t*) t0)->f_cell;
                std_collections_add__i32(l2, l27);
            } else if (l12.tag == 946u) {
                t0 = l12.payload.obj;
                l28 = ((vader_struct_vader_midir_InstrCall_t*) t0)->f_args;
                l29 = ((vader_array_t*) l28)->length;
                l30 = (size_t) 0;
                while ((l30 < l29)) {
                    vader_array_t* _a15_slotarr = ((vader_array_t*) l28);
                    VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a15_slotarr, l30)
                    l31 = ((int32_t*) _a15_slotarr->buf->slots)[_a15_slotarr->offset + (size_t) l30];
                    std_collections_add__i32(l2, l31);
                    t1 = (l30 + INT64_C(1));
                    l30 = (size_t) (int64_t) t1;
                }
            } else if (l12.tag == 947u) {
                t0 = l12.payload.obj;
                l32 = ((vader_struct_vader_midir_InstrCallIndirect_t*) t0)->f_callee;
                std_collections_add__i32(l2, l32);
                t0 = l12.payload.obj;
                l33 = ((vader_struct_vader_midir_InstrCallIndirect_t*) t0)->f_args;
                l34 = ((vader_array_t*) l33)->length;
                l35 = (size_t) 0;
                while ((l35 < l34)) {
                    vader_array_t* _a16_slotarr = ((vader_array_t*) l33);
                    VADER_ARRAY_RESOLVE_BUF(_a16_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a16_slotarr, l35)
                    l36 = ((int32_t*) _a16_slotarr->buf->slots)[_a16_slotarr->offset + (size_t) l35];
                    std_collections_add__i32(l2, l36);
                    t1 = (l35 + INT64_C(1));
                    l35 = (size_t) (int64_t) t1;
                }
            } else if (l12.tag == 968u) {
                t0 = l12.payload.obj;
                l37 = ((vader_struct_vader_midir_InstrVirtualCall_t*) t0)->f_receiver;
                std_collections_add__i32(l2, l37);
                t0 = l12.payload.obj;
                l38 = ((vader_struct_vader_midir_InstrVirtualCall_t*) t0)->f_args;
                l39 = ((vader_array_t*) l38)->length;
                l40 = (size_t) 0;
                while ((l40 < l39)) {
                    vader_array_t* _a17_slotarr = ((vader_array_t*) l38);
                    VADER_ARRAY_RESOLVE_BUF(_a17_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a17_slotarr, l40)
                    l41 = ((int32_t*) _a17_slotarr->buf->slots)[_a17_slotarr->offset + (size_t) l40];
                    std_collections_add__i32(l2, l41);
                    t1 = (l40 + INT64_C(1));
                    l40 = (size_t) (int64_t) t1;
                }
            } else if (l12.tag == 960u) {
                t0 = l12.payload.obj;
                l42 = ((vader_struct_vader_midir_InstrIntrinsic_t*) t0)->f_args;
                l43 = ((vader_array_t*) l42)->length;
                l44 = (size_t) 0;
                while ((l44 < l43)) {
                    vader_array_t* _a18_slotarr = ((vader_array_t*) l42);
                    VADER_ARRAY_RESOLVE_BUF(_a18_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a18_slotarr, l44)
                    l45 = ((int32_t*) _a18_slotarr->buf->slots)[_a18_slotarr->offset + (size_t) l44];
                    std_collections_add__i32(l2, l45);
                    t1 = (l44 + INT64_C(1));
                    l44 = (size_t) (int64_t) t1;
                }
            } else if (l12.tag == 961u) {
                t0 = l12.payload.obj;
                l46 = ((vader_struct_vader_midir_InstrMakeClosure_t*) t0)->f_env;
                std_collections_add__i32(l2, l46);
            } else if (l12.tag == 964u) {
                t0 = l12.payload.obj;
                l47 = ((vader_struct_vader_midir_InstrStructNew_t*) t0)->f_fields;
                l48 = ((vader_array_t*) l47)->length;
                l49 = (size_t) 0;
                while ((l49 < l48)) {
                    vader_array_t* _a19_slotarr = ((vader_array_t*) l47);
                    VADER_ARRAY_RESOLVE_BUF(_a19_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a19_slotarr, l49)
                    l50 = ((int32_t*) _a19_slotarr->buf->slots)[_a19_slotarr->offset + (size_t) l49];
                    t0 = l12.payload.obj;
                    l51 = ((vader_struct_vader_midir_InstrStructNew_t*) t0)->f_dst;
                    vader_midir_append_alias(l3, l51, l50);
                    t1 = (l49 + INT64_C(1));
                    l49 = (size_t) (int64_t) t1;
                }
            } else if (l12.tag == 941u) {
                t0 = l12.payload.obj;
                l52 = ((vader_struct_vader_midir_InstrArrayNew_t*) t0)->f_elements;
                l53 = ((vader_array_t*) l52)->length;
                l54 = (size_t) 0;
                while ((l54 < l53)) {
                    vader_array_t* _a20_slotarr = ((vader_array_t*) l52);
                    VADER_ARRAY_RESOLVE_BUF(_a20_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a20_slotarr, l54)
                    l55 = ((int32_t*) _a20_slotarr->buf->slots)[_a20_slotarr->offset + (size_t) l54];
                    t0 = l12.payload.obj;
                    l56 = ((vader_struct_vader_midir_InstrArrayNew_t*) t0)->f_dst;
                    vader_midir_append_alias(l3, l56, l55);
                    t1 = (l54 + INT64_C(1));
                    l54 = (size_t) (int64_t) t1;
                }
            } else if ((l12.tag == 939u || l12.tag == 956u)) {
                t0 = l12.payload.obj;
                t2 = vader_midir_read_may_carry_ref(((vader_struct_vader_midir_InstrArrayGet_t*) t0)->f_type);
                if (t2) {
                    t0 = l12.payload.obj;
                    l57 = ((vader_struct_vader_midir_InstrArrayGet_t*) t0)->f_dst;
                    t0 = l12.payload.obj;
                    l58 = ((vader_struct_vader_midir_InstrArrayGet_t*) t0)->f_target;
                    vader_midir_append_alias(l3, l57, l58);
                }
            }
            t1 = (l11 + INT64_C(1));
            l11 = (size_t) (int64_t) t1;
        }
        if (((vader_struct_vader_midir_BasicBlock_t*) l6)->f_terminator.tag == 980u) {
            t0 = ((vader_struct_vader_midir_BasicBlock_t*) l6)->f_terminator.payload.obj;
            l59 = ((vader_struct_vader_midir_TermReturn_t*) t0)->f_values;
            l60 = ((vader_array_t*) l59)->length;
            l61 = (size_t) 0;
            while ((l61 < l60)) {
                vader_array_t* _a21_slotarr = ((vader_array_t*) l59);
                VADER_ARRAY_RESOLVE_BUF(_a21_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a21_slotarr, l61)
                l62 = ((int32_t*) _a21_slotarr->buf->slots)[_a21_slotarr->offset + (size_t) l61];
                std_collections_add__i32(l2, l62);
                t1 = (l61 + INT64_C(1));
                l61 = (size_t) (int64_t) t1;
            }
        }
        t1 = (l8 + INT64_C(1));
        l8 = (size_t) (int64_t) t1;
    }
    vader_array_t* _a22_arr = vader_array_new(14u, 0u, 7u, 246u);
    l5 = (void*) _a22_arr;
    l6 = l2;
    l9 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) ((vader_struct_std_collections_MutableSet__i32_t*) l6)->f_inner)->f_ekeys;
    l7 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) ((vader_struct_std_collections_MutableSet__i32_t*) l6)->f_inner)->f_size;
    l8 = (size_t) 0;
    vader_array_t* _pc542_hdr = (vader_array_t*) l5;
    size_t _pc542_len = _pc542_hdr->length;
    size_t _pc542_cap = (_pc542_hdr->offset == 0 && !vader_array_is_borrowed(_pc542_hdr) && _pc542_hdr->length >= _pc542_hdr->buf->length) ? _pc542_hdr->capacity : (size_t) 0;
    void* _pc542_slots = _pc542_hdr->buf->slots;
    for (;;) {
        if (!((l8 >= l7))) {
            vader_array_t* _a23_slotarr = ((vader_array_t*) l9);
            VADER_ARRAY_RESOLVE_BUF(_a23_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a23_slotarr, l8)
            l13 = ((int32_t*) _a23_slotarr->buf->slots)[_a23_slotarr->offset + (size_t) l8];
            t1 = (l8 + INT64_C(1));
            l8 = (size_t) (int64_t) t1;
            if (VADER_LIKELY(_pc542_len < _pc542_cap)) {
                ((int32_t*) _pc542_slots)[_pc542_len] = (int32_t) (l13);
                _pc542_len += 1;
            } else {
                _pc542_hdr->length = _pc542_len;
                if (_pc542_hdr->buf->length < _pc542_len) {
                    _pc542_hdr->buf->length = _pc542_len;
                }
                vader_array_push_i32((vader_array_t*) l5, l13);
                _pc542_hdr = (vader_array_t*) l5;
                _pc542_len = _pc542_hdr->length;
                _pc542_cap = (_pc542_hdr->offset == 0 && !vader_array_is_borrowed(_pc542_hdr) && _pc542_hdr->length >= _pc542_hdr->buf->length) ? _pc542_hdr->capacity : (size_t) 0;
                _pc542_slots = _pc542_hdr->buf->slots;
            }
            continue;
        }
        _pc542_hdr->length = _pc542_len;
        if (_pc542_hdr->buf->length < _pc542_len) {
            _pc542_hdr->buf->length = _pc542_len;
        }
        break;
    }
    for (;;) {
        t3 = ((vader_array_t*) l5)->length;
        if ((t3 > INT64_C(0))) {
            t3 = ((vader_array_t*) l5)->length;
            t1 = (t3 - INT64_C(1));
            l7 = (size_t) (int64_t) t1;
            vader_array_t* _a24_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a24_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a24_slotarr, l7)
            l13 = ((int32_t*) _a24_slotarr->buf->slots)[_a24_slotarr->offset + (size_t) l7];
            t3 = ((vader_array_t*) l5)->length;
            t1 = (t3 - INT64_C(1));
            l8 = (size_t) (int64_t) t1;
            vader_array_t* _a25_arr = vader_array_slice((vader_array_t*) l5, (size_t) INT64_C(0), (size_t) l8);
            l5 = (void*) _a25_arr;
            l12 = std_collections_MutableMap_Index_at__i32__Any(l3, l13);
            if (l12.tag == 0u) {
                continue;
            }
            l6 = l12.payload.obj;
            l10 = ((vader_array_t*) l6)->length;
            l11 = (size_t) 0;
            while ((l11 < l10)) {
                vader_array_t* _a26_slotarr = ((vader_array_t*) l6);
                VADER_ARRAY_RESOLVE_BUF(_a26_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a26_slotarr, l11)
                l14 = ((int32_t*) _a26_slotarr->buf->slots)[_a26_slotarr->offset + (size_t) l11];
                t2 = std_collections_MutableSet_Contains_contains__i32(l2, l14);
                if (t2) {
                    t1 = (l11 + INT64_C(1));
                    l11 = (size_t) (int64_t) t1;
                    continue;
                }
                std_collections_add__i32(l2, l14);
                vader_array_push_i32((vader_array_t*) l5, l14);
                t1 = (l11 + INT64_C(1));
                l11 = (size_t) (int64_t) t1;
            }
            continue;
        }
        break;
    }
    vader_array_t* _a27_arr = vader_array_new(14u, 0u, 7u, 246u);
    l5 = (void*) _a27_arr;
    vader_array_t* _a28_arr = vader_array_new(11u, 0u, 12u, 241u);
    l6 = (void*) _a28_arr;
    vader_array_t* _a29_arr = vader_array_new(14u, 0u, 7u, 246u);
    l9 = (void*) _a29_arr;
    vader_struct_std_collections_MutableMap__i32__bool_t* _a30_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
    vader_obj_header_init(_a30_obj, 328u);
    _a30_obj->f_ekeys = l5;
    _a30_obj->f_evals = l6;
    _a30_obj->f_index = l9;
    _a30_obj->f_mask = (size_t) 0;
    _a30_obj->f_size = (size_t) 0;
    _a30_obj->f_tombs = (size_t) 0;
    t0 = (void*) _a30_obj;
    vader_struct_std_collections_MutableSet__i32_t* _a31_obj = (vader_struct_std_collections_MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i32_t));
    vader_obj_header_init(_a31_obj, 425u);
    _a31_obj->f_inner = t0;
    l5 = (void*) _a31_obj;
    l6 = l1;
    l9 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) ((vader_struct_std_collections_MutableSet__i32_t*) l6)->f_inner)->f_ekeys;
    l7 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) ((vader_struct_std_collections_MutableSet__i32_t*) l6)->f_inner)->f_size;
    l8 = (size_t) 0;
    while (!((l8 >= l7))) {
        vader_array_t* _a32_slotarr = ((vader_array_t*) l9);
        VADER_ARRAY_RESOLVE_BUF(_a32_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a32_slotarr, l8)
        l13 = ((int32_t*) _a32_slotarr->buf->slots)[_a32_slotarr->offset + (size_t) l8];
        t1 = (l8 + INT64_C(1));
        l8 = (size_t) (int64_t) t1;
        t2 = std_collections_MutableSet_Contains_contains__i32(l2, l13);
        if (!(t2)) {
            continue;
        }
        std_collections_add__i32(l5, l13);
    }
    vader_struct_vader_midir_EscapeResult_t* _a33_obj = (vader_struct_vader_midir_EscapeResult_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_EscapeResult_t));
    vader_obj_header_init(_a33_obj, 933u);
    _a33_obj->f_escaping = l5;
    _a33_obj->f_alias_of = l3;
    _a33_obj->f_alias_from = l4;
    t0 = (void*) _a33_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_midir_compute_liveness(void* l0) {
    size_t l1, l4, l15, l16, l21, l22, l29, l30, l32, l33;
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
    int64_t t1;
    bool t2;
    vader_box_t* gc_roots[4] = { &l17, &l19, &l24, &l26 };
    void** gc_raw_roots[20] = {
        &l0, &l2, &l3, &l5, &l6, &l7, &l8, &l9, &l10, &l11, &l12, &l13, &l14, &l18, &l20, &l27,
        &l35, &l36, &l37, &t0,
    };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 20u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = ((vader_array_t*) ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_blocks)->length;
    vader_array_t* _a0_arr = vader_array_new(24u, 0u, 13u, 425u);
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (size_t) l1);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(24u, 0u, 13u, 425u);
    t0 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_repeat((vader_array_t*) t0, (size_t) l1);
    l3 = (void*) _a3_arr;
    l4 = (size_t) 0;
    while ((l4 < l1)) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_blocks);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l4)
        l5 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l4);
        vader_array_t* _a5_arr = vader_array_new(14u, 0u, 7u, 246u);
        l6 = (void*) _a5_arr;
        vader_array_t* _a6_arr = vader_array_new(11u, 0u, 12u, 241u);
        l7 = (void*) _a6_arr;
        vader_array_t* _a7_arr = vader_array_new(14u, 0u, 7u, 246u);
        l8 = (void*) _a7_arr;
        vader_struct_std_collections_MutableMap__i32__bool_t* _a8_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
        vader_obj_header_init(_a8_obj, 328u);
        _a8_obj->f_ekeys = l6;
        _a8_obj->f_evals = l7;
        _a8_obj->f_index = l8;
        _a8_obj->f_mask = (size_t) 0;
        _a8_obj->f_size = (size_t) 0;
        _a8_obj->f_tombs = (size_t) 0;
        t0 = (void*) _a8_obj;
        vader_struct_std_collections_MutableSet__i32_t* _a9_obj = (vader_struct_std_collections_MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i32_t));
        vader_obj_header_init(_a9_obj, 425u);
        _a9_obj->f_inner = t0;
        l9 = (void*) _a9_obj;
        vader_array_t* _a10_arr = vader_array_new(14u, 0u, 7u, 246u);
        l10 = (void*) _a10_arr;
        vader_array_t* _a11_arr = vader_array_new(11u, 0u, 12u, 241u);
        l11 = (void*) _a11_arr;
        vader_array_t* _a12_arr = vader_array_new(14u, 0u, 7u, 246u);
        l12 = (void*) _a12_arr;
        vader_struct_std_collections_MutableMap__i32__bool_t* _a13_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
        vader_obj_header_init(_a13_obj, 328u);
        _a13_obj->f_ekeys = l10;
        _a13_obj->f_evals = l11;
        _a13_obj->f_index = l12;
        _a13_obj->f_mask = (size_t) 0;
        _a13_obj->f_size = (size_t) 0;
        _a13_obj->f_tombs = (size_t) 0;
        t0 = (void*) _a13_obj;
        vader_struct_std_collections_MutableSet__i32_t* _a14_obj = (vader_struct_std_collections_MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i32_t));
        vader_obj_header_init(_a14_obj, 425u);
        _a14_obj->f_inner = t0;
        l13 = (void*) _a14_obj;
        l14 = ((vader_struct_vader_midir_BasicBlock_t*) l5)->f_instructions;
        l15 = ((vader_array_t*) l14)->length;
        l16 = (size_t) 0;
        while ((l16 < l15)) {
            vader_array_t* _a15_slotarr = ((vader_array_t*) l14);
            VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a15_slotarr, l16)
            l17 = vader_array_ref_load_box(_a15_slotarr->buf, _a15_slotarr->offset + (size_t) l16);
            vader_struct___lambda_env_vader_midir_10_t* _a16_obj = (vader_struct___lambda_env_vader_midir_10_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_midir_10_t));
            vader_obj_header_init(_a16_obj, 271u);
            _a16_obj->f_cap_0 = l13;
            _a16_obj->f_cap_1 = l9;
            t0 = (void*) _a16_obj;
            vader_fn_t* _a17_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
            vader_obj_header_init(_a17_closure, 215u);
            _a17_closure->code = (void*) &vader_fn_lift___lambda_vader_midir_9;
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
                l22 = (size_t) 0;
                while ((l22 < l21)) {
                    vader_array_t* _a18_slotarr = ((vader_array_t*) l20);
                    VADER_ARRAY_RESOLVE_BUF(_a18_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a18_slotarr, l22)
                    l23 = ((int32_t*) _a18_slotarr->buf->slots)[_a18_slotarr->offset + (size_t) l22];
                    std_collections_add__i32(l13, l23);
                    t1 = (l22 + INT64_C(1));
                    l22 = (size_t) (int64_t) t1;
                }
            }
            t1 = (l16 + INT64_C(1));
            l16 = (size_t) (int64_t) t1;
        }
        l26 = ((vader_struct_vader_midir_BasicBlock_t*) l5)->f_terminator;
        vader_struct___lambda_env_vader_midir_12_t* _a19_obj = (vader_struct___lambda_env_vader_midir_12_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_midir_12_t));
        vader_obj_header_init(_a19_obj, 272u);
        _a19_obj->f_cap_0 = l13;
        _a19_obj->f_cap_1 = l9;
        t0 = (void*) _a19_obj;
        vader_fn_t* _a20_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
        vader_obj_header_init(_a20_closure, 215u);
        _a20_closure->code = (void*) &vader_fn_lift___lambda_vader_midir_11;
        _a20_closure->env = t0;
        l27 = (void*) _a20_closure;
        vader_midir_for_each_read_in_terminator(l26, l27);
        vader_array_push((vader_array_t*) l2, vader_ref_box(l9));
        vader_array_push((vader_array_t*) l3, vader_ref_box(l13));
        t1 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t1;
    }
    vader_array_t* _a21_arr = vader_array_new(2u, 0u, 13u, 14u);
    t0 = (void*) _a21_arr;
    vader_array_t* _a22_arr = vader_array_repeat((vader_array_t*) t0, (size_t) l1);
    l5 = (void*) _a22_arr;
    l6 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_blocks;
    l4 = ((vader_array_t*) l6)->length;
    l15 = (size_t) 0;
    while ((l15 < l4)) {
        vader_array_t* _a23_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a23_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a23_slotarr, l15)
        t0 = vader_array_ref_load_obj(_a23_slotarr->buf, _a23_slotarr->offset + (size_t) l15);
        l7 = vader_midir_successors_of(t0);
        vader_array_push((vader_array_t*) l5, vader_ref_box(l7));
        t1 = (l15 + INT64_C(1));
        l15 = (size_t) (int64_t) t1;
    }
    l6 = (void*) &vader_fn_static___lambda_vader_midir_13;
    l6 = std_core_filled__MutableSet_i32_(l1, l6);
    l7 = (void*) &vader_fn_static___lambda_vader_midir_14;
    l7 = std_core_filled__MutableSet_i32_(l1, l7);
    vader_array_t* _a24_arr = vader_array_new(14u, 0u, 7u, 246u);
    l8 = (void*) _a24_arr;
    vader_array_t* _a25_arr = vader_array_new(11u, 0u, 12u, 241u);
    l9 = (void*) _a25_arr;
    vader_array_t* _a26_arr = vader_array_new(14u, 0u, 7u, 246u);
    l10 = (void*) _a26_arr;
    vader_struct_std_collections_MutableMap__i32__bool_t* _a27_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
    vader_obj_header_init(_a27_obj, 328u);
    _a27_obj->f_ekeys = l8;
    _a27_obj->f_evals = l9;
    _a27_obj->f_index = l10;
    _a27_obj->f_mask = (size_t) 0;
    _a27_obj->f_size = (size_t) 0;
    _a27_obj->f_tombs = (size_t) 0;
    t0 = (void*) _a27_obj;
    vader_struct_std_collections_MutableSet__i32_t* _a28_obj = (vader_struct_std_collections_MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i32_t));
    vader_obj_header_init(_a28_obj, 425u);
    _a28_obj->f_inner = t0;
    l8 = (void*) _a28_obj;
    vader_array_t* _a29_arr = vader_array_new(14u, 0u, 7u, 246u);
    l9 = (void*) _a29_arr;
    vader_array_t* _a30_arr = vader_array_new(11u, 0u, 12u, 241u);
    l10 = (void*) _a30_arr;
    vader_array_t* _a31_arr = vader_array_new(14u, 0u, 7u, 246u);
    l11 = (void*) _a31_arr;
    vader_struct_std_collections_MutableMap__i32__bool_t* _a32_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
    vader_obj_header_init(_a32_obj, 328u);
    _a32_obj->f_ekeys = l9;
    _a32_obj->f_evals = l10;
    _a32_obj->f_index = l11;
    _a32_obj->f_mask = (size_t) 0;
    _a32_obj->f_size = (size_t) 0;
    _a32_obj->f_tombs = (size_t) 0;
    t0 = (void*) _a32_obj;
    vader_struct_std_collections_MutableSet__i32_t* _a33_obj = (vader_struct_std_collections_MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i32_t));
    vader_obj_header_init(_a33_obj, 425u);
    _a33_obj->f_inner = t0;
    l9 = (void*) _a33_obj;
    l28 = true;
    while (l28) {
        l28 = false;
        l4 = l1;
        while ((l4 > INT64_C(0))) {
            t1 = (l4 - INT64_C(1));
            l4 = (size_t) (int64_t) t1;
            std_collections_clear__vader_midir_LocalId(l8);
            vader_array_t* _a34_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a34_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a34_slotarr, l4)
            l10 = vader_array_ref_load_obj(_a34_slotarr->buf, _a34_slotarr->offset + (size_t) l4);
            l15 = ((vader_array_t*) l10)->length;
            l16 = (size_t) 0;
            while ((l16 < l15)) {
                vader_array_t* _a35_slotarr = ((vader_array_t*) l10);
                VADER_ARRAY_RESOLVE_BUF(_a35_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a35_slotarr, l16)
                l23 = ((int32_t*) _a35_slotarr->buf->slots)[_a35_slotarr->offset + (size_t) l16];
                vader_array_t* _a36_slotarr = ((vader_array_t*) l6);
                VADER_ARRAY_RESOLVE_BUF(_a36_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a36_slotarr, l23)
                l11 = vader_array_ref_load_obj(_a36_slotarr->buf, _a36_slotarr->offset + (size_t) l23);
                l12 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) ((vader_struct_std_collections_MutableSet__i32_t*) l11)->f_inner)->f_ekeys;
                l21 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) ((vader_struct_std_collections_MutableSet__i32_t*) l11)->f_inner)->f_size;
                l22 = (size_t) 0;
                while (!((l22 >= l21))) {
                    vader_array_t* _a37_slotarr = ((vader_array_t*) l12);
                    VADER_ARRAY_RESOLVE_BUF(_a37_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a37_slotarr, l22)
                    l25 = ((int32_t*) _a37_slotarr->buf->slots)[_a37_slotarr->offset + (size_t) l22];
                    t1 = (l22 + INT64_C(1));
                    l22 = (size_t) (int64_t) t1;
                    std_collections_add__i32(l8, l25);
                }
                t1 = (l16 + INT64_C(1));
                l16 = (size_t) (int64_t) t1;
            }
            std_collections_clear__vader_midir_LocalId(l9);
            vader_array_t* _a38_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a38_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a38_slotarr, l4)
            l13 = vader_array_ref_load_obj(_a38_slotarr->buf, _a38_slotarr->offset + (size_t) l4);
            l14 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) ((vader_struct_std_collections_MutableSet__i32_t*) l13)->f_inner)->f_ekeys;
            l29 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) ((vader_struct_std_collections_MutableSet__i32_t*) l13)->f_inner)->f_size;
            l30 = (size_t) 0;
            while (!((l30 >= l29))) {
                vader_array_t* _a39_slotarr = ((vader_array_t*) l14);
                VADER_ARRAY_RESOLVE_BUF(_a39_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a39_slotarr, l30)
                l31 = ((int32_t*) _a39_slotarr->buf->slots)[_a39_slotarr->offset + (size_t) l30];
                t1 = (l30 + INT64_C(1));
                l30 = (size_t) (int64_t) t1;
                std_collections_add__i32(l9, l31);
            }
            l18 = l8;
            l20 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) ((vader_struct_std_collections_MutableSet__i32_t*) l18)->f_inner)->f_ekeys;
            l32 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) ((vader_struct_std_collections_MutableSet__i32_t*) l18)->f_inner)->f_size;
            l33 = (size_t) 0;
            while (!((l33 >= l32))) {
                vader_array_t* _a40_slotarr = ((vader_array_t*) l20);
                VADER_ARRAY_RESOLVE_BUF(_a40_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a40_slotarr, l33)
                l34 = ((int32_t*) _a40_slotarr->buf->slots)[_a40_slotarr->offset + (size_t) l33];
                t1 = (l33 + INT64_C(1));
                l33 = (size_t) (int64_t) t1;
                vader_array_t* _a41_slotarr = ((vader_array_t*) l3);
                VADER_ARRAY_RESOLVE_BUF(_a41_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a41_slotarr, l4)
                t0 = vader_array_ref_load_obj(_a41_slotarr->buf, _a41_slotarr->offset + (size_t) l4);
                t2 = std_collections_MutableSet_Contains_contains__i32(t0, l34);
                if (t2) {
                    continue;
                }
                std_collections_add__i32(l9, l34);
            }
            vader_array_t* _a42_slotarr = ((vader_array_t*) l7);
            VADER_ARRAY_RESOLVE_BUF(_a42_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a42_slotarr, l4)
            l27 = vader_array_ref_load_obj(_a42_slotarr->buf, _a42_slotarr->offset + (size_t) l4);
            t2 = vader_midir_sets_equal(l8, l27);
            if (!(t2)) {
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
            t2 = vader_midir_sets_equal(l9, l36);
            if (t2) {
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
    vader_obj_header_init(_a46_obj, 969u);
    _a46_obj->f_live_in = l6;
    _a46_obj->f_live_out = l7;
    t0 = (void*) _a46_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_midir_convert_data_pool(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l6 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    void* l16 = NULL;
    void* l17 = NULL;
    void* l18 = NULL;
    void* l24 = NULL;
    size_t l3, l4, l11, l12, l19, l20;
    vader_box_t l5 = vader_box_null(), l21 = vader_box_null();
    bool l7, l15, l23;
    uint64_t l13;
    uint8_t l14;
    vader_string_t l22 = 0;
    void* t0 = NULL;
    int64_t t1, t2;
    vader_string_t t3 = 0;
    vader_box_t t4 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l5, &l21, &t4 };
    void** gc_raw_roots[12] = { &l0, &l1, &l2, &l6, &l8, &l9, &l10, &l16, &l17, &l18, &l24, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l22, &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 12u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(188u, 0u, 13u, 1338u);
    l1 = (void*) _a0_arr;
    l2 = l0;
    l3 = ((vader_array_t*) l2)->length;
    l4 = (size_t) 0;
    while ((l4 < l3)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
        l5 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
        if (l5.tag == 910u) {
            t0 = l5.payload.obj;
            l6 = ((vader_struct_vader_lower_StrDataPoolEntry_t*) t0)->f_values;
            t0 = l5.payload.obj;
            l7 = ((vader_struct_vader_lower_StrDataPoolEntry_t*) t0)->f_mutable;
            vader_struct_vader_bytecode_BcStrData_t* _a2_obj = (vader_struct_vader_bytecode_BcStrData_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcStrData_t));
            vader_obj_header_init(_a2_obj, 560u);
            _a2_obj->f_values = l6;
            _a2_obj->f_mutable = l7;
            l8 = (void*) _a2_obj;
            vader_array_push((vader_array_t*) l1, vader_ref_box(l8));
        } else if (l5.tag == 907u) {
            vader_array_t* _a3_arr = vader_array_new(19u, 0u, 4u, 252u);
            l9 = (void*) _a3_arr;
            t0 = l5.payload.obj;
            l10 = ((vader_struct_vader_lower_PrimDataPoolEntry_t*) t0)->f_items;
            l11 = ((vader_array_t*) l10)->length;
            l12 = (size_t) 0;
            vader_array_t* _pc49_hdr = (vader_array_t*) l9;
            size_t _pc49_len = _pc49_hdr->length;
            size_t _pc49_cap = (_pc49_hdr->offset == 0 && !vader_array_is_borrowed(_pc49_hdr) && _pc49_hdr->length >= _pc49_hdr->buf->length) ? _pc49_hdr->capacity : (size_t) 0;
            void* _pc49_slots = _pc49_hdr->buf->slots;
            for (;;) {
                if ((l12 < l11)) {
                    vader_array_t* _a4_slotarr = ((vader_array_t*) l10);
                    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l12)
                    t1 = ((int64_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l12];
                    t2 = t1;
                    l13 = (uint64_t) (int64_t) t2;
                    if (VADER_LIKELY(_pc49_len < _pc49_cap)) {
                        ((int64_t*) _pc49_slots)[_pc49_len] = (int64_t) ((int64_t) (uint64_t) l13);
                        _pc49_len += 1;
                    } else {
                        _pc49_hdr->length = _pc49_len;
                        if (_pc49_hdr->buf->length < _pc49_len) {
                            _pc49_hdr->buf->length = _pc49_len;
                        }
                        vader_array_push_i64((vader_array_t*) l9, (int64_t) (uint64_t) l13);
                        _pc49_hdr = (vader_array_t*) l9;
                        _pc49_len = _pc49_hdr->length;
                        _pc49_cap = (_pc49_hdr->offset == 0 && !vader_array_is_borrowed(_pc49_hdr) && _pc49_hdr->length >= _pc49_hdr->buf->length) ? _pc49_hdr->capacity : (size_t) 0;
                        _pc49_slots = _pc49_hdr->buf->slots;
                    }
                    t1 = (l12 + INT64_C(1));
                    l12 = (size_t) (int64_t) t1;
                    continue;
                }
                _pc49_hdr->length = _pc49_len;
                if (_pc49_hdr->buf->length < _pc49_len) {
                    _pc49_hdr->buf->length = _pc49_len;
                }
                break;
            }
            t0 = l5.payload.obj;
            t3 = ((vader_struct_vader_lower_PrimDataPoolEntry_t*) t0)->f_element_type_name;
            l14 = vader_bytecode_array_kind_from_name(t3);
            t0 = l5.payload.obj;
            l15 = ((vader_struct_vader_lower_PrimDataPoolEntry_t*) t0)->f_mutable;
            vader_struct_vader_bytecode_BcPrimData_t* _a5_obj = (vader_struct_vader_bytecode_BcPrimData_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcPrimData_t));
            vader_obj_header_init(_a5_obj, 556u);
            _a5_obj->f_kind = l14;
            _a5_obj->f_items = l9;
            _a5_obj->f_mutable = l15;
            l16 = (void*) _a5_obj;
            vader_array_push((vader_array_t*) l1, vader_ref_box(l16));
        } else {
            if (!(l5.tag == 811u)) {
                vader_unreachable("non-exhaustive match (T3013 should have caught this)");
            }
            vader_array_t* _a6_arr = vader_array_new(190u, 0u, 13u, 1348u);
            l17 = (void*) _a6_arr;
            t0 = l5.payload.obj;
            l18 = ((vader_struct_vader_lower_LoweredArrayLit_t*) ((vader_struct_vader_lower_AggregateDataPoolEntry_t*) t0)->f_literal)->f_elements;
            l19 = ((vader_array_t*) l18)->length;
            l20 = (size_t) 0;
            while ((l20 < l19)) {
                vader_array_t* _a7_slotarr = ((vader_array_t*) l18);
                VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l20)
                t4 = vader_array_ref_load_box(_a7_slotarr->buf, _a7_slotarr->offset + (size_t) l20);
                l21 = vader_midir_lowered_to_bc_value(t4);
                vader_array_push((vader_array_t*) l17, l21);
                t1 = (l20 + INT64_C(1));
                l20 = (size_t) (int64_t) t1;
            }
            t0 = l5.payload.obj;
            l22 = ((vader_struct_vader_lower_AggregateDataPoolEntry_t*) t0)->f_element_type_name;
            t0 = l5.payload.obj;
            l23 = ((vader_struct_vader_lower_AggregateDataPoolEntry_t*) t0)->f_mutable;
            vader_struct_vader_bytecode_BcAggregateData_t* _a8_obj = (vader_struct_vader_bytecode_BcAggregateData_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcAggregateData_t));
            vader_obj_header_init(_a8_obj, 547u);
            _a8_obj->f_element_type_name = l22;
            _a8_obj->f_elements = l17;
            _a8_obj->f_mutable = l23;
            l24 = (void*) _a8_obj;
            vader_array_push((vader_array_t*) l1, vader_ref_box(l24));
        }
        t1 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t1;
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
        l1 = true;
    } else if (l0 == INT32_C(11)) {
        l1 = true;
    } else if (l0 == INT32_C(12)) {
        l1 = false;
    } else if (l0 == INT32_C(13)) {
        l1 = true;
    } else if (l0 == INT32_C(14)) {
        l1 = false;
    } else if (l0 == INT32_C(15)) {
        l1 = false;
    } else if (l0 == INT32_C(16)) {
        l1 = false;
    } else if (l0 == INT32_C(17)) {
        l1 = false;
    } else if (l0 == INT32_C(18)) {
        l1 = false;
    } else {
        if (!(l0 == INT32_C(19))) {
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
    size_t l4, l9;
    int32_t l10, l15, l16, l20;
    vader_string_t l11 = 0;
    vader_string_t l17 = 0;
    vader_box_t l12 = vader_box_null(), l19 = vader_box_null();
    bool l22, l23;
    vader_box_t t0 = vader_box_null();
    size_t t1;
    int64_t t2;
    int32_t t3;
    void* t4 = NULL;
    vader_box_t* gc_roots[3] = { &l12, &l19, &t0 };
    void** gc_raw_roots[13] = {
        &l0, &l1, &l2, &l3, &l5, &l6, &l7, &l8, &l13, &l14, &l18, &l21, &t4,
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
    vader_array_t* _a0_arr = vader_array_new(107u, 0u, 13u, 921u);
    l3 = (void*) _a0_arr;
    l4 = ((vader_array_t*) ((vader_struct_vader_lower_LoweredFnDecl_t*) l0)->f_params)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l3, (size_t) l4);
    l3 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(105u, 0u, 13u, 919u);
    l5 = (void*) _a2_arr;
    l4 = ((vader_array_t*) ((vader_struct_vader_lower_LoweredFnDecl_t*) l0)->f_params)->length;
    vader_array_t* _a3_arr = vader_array_repeat((vader_array_t*) l5, (size_t) l4);
    l5 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_new(14u, 0u, 7u, 246u);
    l6 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_new(14u, 0u, 7u, 246u);
    l7 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(14u, 0u, 7u, 246u);
    l8 = (void*) _a6_arr;
    vader_struct_std_collections_MutableMap__i32__i32_t* _a7_obj = (vader_struct_std_collections_MutableMap__i32__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__i32_t));
    vader_obj_header_init(_a7_obj, 329u);
    _a7_obj->f_ekeys = l6;
    _a7_obj->f_evals = l7;
    _a7_obj->f_index = l8;
    _a7_obj->f_mask = (size_t) 0;
    _a7_obj->f_size = (size_t) 0;
    _a7_obj->f_tombs = (size_t) 0;
    l6 = (void*) _a7_obj;
    l7 = ((vader_struct_vader_lower_LoweredFnDecl_t*) l0)->f_params;
    l4 = ((vader_array_t*) l7)->length;
    l9 = (size_t) 0;
    while ((l9 < l4)) {
        vader_array_t* _a8_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l9)
        l8 = vader_array_ref_load_obj(_a8_slotarr->buf, _a8_slotarr->offset + (size_t) l9);
        t1 = ((vader_array_t*) l5)->length;
        l10 = ((int32_t) (size_t) t1);
        l11 = ((vader_struct_vader_lower_LoweredParam_t*) l8)->f_name;
        l12 = ((vader_struct_vader_lower_LoweredParam_t*) l8)->f_type;
        l13 = ((vader_struct_vader_lower_LoweredParam_t*) l8)->f_symbol;
        vader_struct_vader_midir_CFGLocal_t* _a9_obj = (vader_struct_vader_midir_CFGLocal_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_CFGLocal_t));
        vader_obj_header_init(_a9_obj, 919u);
        _a9_obj->f_name = l11;
        _a9_obj->f_type = l12;
        _a9_obj->f_symbol = vader_ref_box(l13);
        l14 = (void*) _a9_obj;
        vader_array_push((vader_array_t*) l5, vader_ref_box(l14));
        l15 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_lower_LoweredParam_t*) l8)->f_symbol)->f_id;
        l16 = l10;
        std_collections_MutableMap_IndexSet_set_at__i32__i32(l6, l15, l16);
        l17 = ((vader_struct_vader_lower_LoweredParam_t*) l8)->f_name;
        l18 = ((vader_struct_vader_lower_LoweredParam_t*) l8)->f_symbol;
        l19 = ((vader_struct_vader_lower_LoweredParam_t*) l8)->f_type;
        l20 = l10;
        vader_struct_vader_midir_CFGParam_t* _a10_obj = (vader_struct_vader_midir_CFGParam_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_CFGParam_t));
        vader_obj_header_init(_a10_obj, 921u);
        _a10_obj->f_name = l17;
        _a10_obj->f_symbol = l18;
        _a10_obj->f_type = l19;
        _a10_obj->f_local = l20;
        l21 = (void*) _a10_obj;
        vader_array_push((vader_array_t*) l3, vader_ref_box(l21));
        t2 = (l9 + INT64_C(1));
        l9 = (size_t) (int64_t) t2;
    }
    l11 = ((vader_struct_vader_lower_LoweredFnDecl_t*) l0)->f_mangled;
    l7 = ((vader_struct_vader_lower_LoweredFnDecl_t*) l0)->f_origin;
    l12 = ((vader_struct_vader_lower_LoweredFnDecl_t*) l0)->f_return_type;
    vader_array_t* _a11_arr = vader_array_new(112u, 0u, 13u, 971u);
    l8 = (void*) _a11_arr;
    vader_array_t* _a12_arr = vader_array_new(111u, 0u, 13u, 970u);
    l13 = (void*) _a12_arr;
    vader_struct_vader_midir_FnCtx_t* _a13_obj = (vader_struct_vader_midir_FnCtx_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_FnCtx_t));
    vader_obj_header_init(_a13_obj, 936u);
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
    t0 = vader_box_i32(246u, l10);
    ((vader_struct_vader_midir_FnCtx_t*) l5)->f_current = t0;
    VADER_WRITE_BARRIER((vader_struct_vader_midir_FnCtx_t*) l5);
    l12 = vader_midir_build_block_body(l5, l2);
    if (!(((vader_struct_vader_midir_FnCtx_t*) l5)->f_current.tag == 0u)) {
        l6 = ((vader_struct_vader_midir_FnCtx_t*) l5)->f_blocks;
        t2 = ((int64_t) ((vader_struct_vader_midir_FnCtx_t*) l5)->f_current.payload.i);
        l4 = (size_t) (int64_t) t2;
        vader_array_t* _a14_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a14_slotarr, l4)
        l6 = vader_array_ref_load_obj(_a14_slotarr->buf, _a14_slotarr->offset + (size_t) l4);
        if (((vader_struct_vader_midir_MutableBlock_t*) l6)->f_terminator.tag == 0u) {
            l2 = ((vader_struct_vader_lower_LoweredBlock_t*) l2)->f_span;
            if (l12.tag == 0u) {
                vader_array_t* _a15_arr = vader_array_new(14u, 0u, 7u, 246u);
                l7 = (void*) _a15_arr;
            } else {
                t3 = ((int32_t) l12.payload.i);
                vader_array_t* _a16_arr = vader_array_new(14u, 1u, 7u, 246u);
                ((int32_t*) _a16_arr->buf->slots)[_a16_arr->offset + 0u] = (int32_t) t3;
                l7 = (void*) _a16_arr;
            }
            vader_struct_vader_midir_TermReturn_t* _a17_obj = (vader_struct_vader_midir_TermReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_TermReturn_t));
            vader_obj_header_init(_a17_obj, 980u);
            _a17_obj->f_span = l2;
            _a17_obj->f_values = l7;
            l2 = (void*) _a17_obj;
            ((vader_struct_vader_midir_MutableBlock_t*) l6)->f_terminator = vader_ref_box(l2);
            VADER_WRITE_BARRIER((vader_struct_vader_midir_MutableBlock_t*) l6);
        }
    }
    l2 = vader_midir_fn_metadata(l0);
    vader_array_t* _a18_arr = vader_array_new(102u, 0u, 13u, 916u);
    l6 = (void*) _a18_arr;
    l4 = ((vader_array_t*) ((vader_struct_vader_midir_FnCtx_t*) l5)->f_blocks)->length;
    vader_array_t* _a19_arr = vader_array_repeat((vader_array_t*) l6, (size_t) l4);
    l6 = (void*) _a19_arr;
    l7 = ((vader_struct_vader_midir_FnCtx_t*) l5)->f_blocks;
    l4 = ((vader_array_t*) l7)->length;
    l9 = (size_t) 0;
    while ((l9 < l4)) {
        vader_array_t* _a20_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a20_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a20_slotarr, l9)
        t4 = vader_array_ref_load_obj(_a20_slotarr->buf, _a20_slotarr->offset + (size_t) l9);
        l8 = vader_midir_freeze_block(t4);
        vader_array_push((vader_array_t*) l6, vader_ref_box(l8));
        t2 = (l9 + INT64_C(1));
        l9 = (size_t) (int64_t) t2;
    }
    l11 = ((vader_struct_vader_lower_LoweredFnDecl_t*) l0)->f_mangled;
    l12 = ((vader_struct_vader_lower_LoweredFnDecl_t*) l0)->f_return_type;
    l5 = ((vader_struct_vader_midir_FnCtx_t*) l5)->f_locals;
    l7 = ((vader_struct_vader_lower_LoweredFnDecl_t*) l0)->f_origin;
    l17 = ((vader_struct_vader_midir_FnMetadata_t*) l2)->f_extern_name;
    l22 = ((vader_struct_vader_midir_FnMetadata_t*) l2)->f_is_extern;
    l23 = ((vader_struct_vader_midir_FnMetadata_t*) l2)->f_is_exported;
    vader_array_t* _a21_arr = vader_array_new(204u, 0u, 13u, 1535u);
    l2 = (void*) _a21_arr;
    vader_struct_vader_midir_CFGFunction_t* _a22_obj = (vader_struct_vader_midir_CFGFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_CFGFunction_t));
    vader_obj_header_init(_a22_obj, 918u);
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
    t4 = (void*) _a22_obj;
    { vader_box_t __vret = vader_ref_box(t4); vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_midir_copies_cheaply(void* l0) {
    bool t0;
    size_t t1;
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
    size_t l4, l5, l8, l9;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    int64_t t2;
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[7] = { &l0, &l1, &l2, &l3, &l6, &l7, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 7u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(14u, 0u, 7u, 246u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(14u, 0u, 7u, 246u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(14u, 0u, 7u, 246u);
    l3 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__i32__i32_t* _a3_obj = (vader_struct_std_collections_MutableMap__i32__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__i32_t));
    vader_obj_header_init(_a3_obj, 329u);
    _a3_obj->f_ekeys = l1;
    _a3_obj->f_evals = l2;
    _a3_obj->f_index = l3;
    _a3_obj->f_mask = (size_t) 0;
    _a3_obj->f_size = (size_t) 0;
    _a3_obj->f_tombs = (size_t) 0;
    l1 = (void*) _a3_obj;
    vader_struct___lambda_env_vader_midir_5_t* _a4_obj = (vader_struct___lambda_env_vader_midir_5_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_midir_5_t));
    vader_obj_header_init(_a4_obj, 276u);
    _a4_obj->f_cap_0 = l1;
    t0 = (void*) _a4_obj;
    vader_fn_t* _a5_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
    vader_obj_header_init(_a5_closure, 215u);
    _a5_closure->code = (void*) &vader_fn_lift___lambda_vader_midir_4;
    _a5_closure->env = t0;
    l2 = (void*) _a5_closure;
    l3 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_blocks;
    l4 = ((vader_array_t*) l3)->length;
    l5 = (size_t) 0;
    while ((l5 < l4)) {
        vader_array_t* _a6_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l5)
        l6 = vader_array_ref_load_obj(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l5);
        l7 = ((vader_struct_vader_midir_BasicBlock_t*) l6)->f_instructions;
        l8 = ((vader_array_t*) l7)->length;
        l9 = (size_t) 0;
        while ((l9 < l8)) {
            vader_array_t* _a7_slotarr = ((vader_array_t*) l7);
            VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l9)
            t1 = vader_array_ref_load_box(_a7_slotarr->buf, _a7_slotarr->offset + (size_t) l9);
            vader_midir_for_each_read_local(t1, l2);
            t2 = (l9 + INT64_C(1));
            l9 = (size_t) (int64_t) t2;
        }
        vader_midir_for_each_read_in_terminator(((vader_struct_vader_midir_BasicBlock_t*) l6)->f_terminator, l2);
        t2 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t2;
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
    vader_obj_header_init(_a0_obj, 589u);
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
    size_t t0;
    vader_box_t* gc_roots[2] = { &l2, &l3 };
    void** gc_raw_roots[3] = { &l0, &l5, &l6 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_vader_midir_FnCtx_t*) l0)->f_locals)->length;
    l4 = ((int32_t) (size_t) t0);
    l5 = ((vader_struct_vader_midir_FnCtx_t*) l0)->f_locals;
    vader_struct_vader_midir_CFGLocal_t* _a0_obj = (vader_struct_vader_midir_CFGLocal_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_CFGLocal_t));
    vader_obj_header_init(_a0_obj, 919u);
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
    size_t l4, l5, l8;
    int32_t l9;
    vader_string_t t0 = 0;
    bool t1;
    int64_t t2;
    int32_t t3;
    void** gc_raw_roots[4] = { &l0, &l3, &l6, &l7 };
    vader_string_t* gc_atom_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_scopes;
    l4 = ((vader_array_t*) l3)->length;
    l5 = (size_t) 0;
    while ((l5 < l4)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l6 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
        t0 = ((vader_struct_vader_midir_ScopeFrame_t*) l6)->f_kind;
        if (t0 == 1949u) {
            t1 = vader_midir_BlockId_Equals_equals(((vader_struct_vader_midir_ScopeFrame_t*) l6)->f_target_blk, l1);
            if (t1) {
                l7 = ((vader_struct_vader_bytecode_BcFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_slot)->f_jump_table;
                t2 = ((int64_t) (int32_t) l2);
                l8 = (size_t) (int64_t) t2;
                t3 = ((vader_struct_vader_midir_ScopeFrame_t*) l6)->f_opener_pc;
                l9 = (t3 + INT32_C(1));
                vader_array_t* _a1_slotarr = ((vader_array_t*) l7);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l8)
                ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l8] = (int32_t) l9;
                { vader_gc_top = gc_frame.prev; return; }
            }
        }
        t2 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t2;
    }
    l3 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_pending;
    vader_struct_vader_midir_PendingBranch_t* _a2_obj = (vader_struct_vader_midir_PendingBranch_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_PendingBranch_t));
    vader_obj_header_init(_a2_obj, 973u);
    _a2_obj->f_branch_pc = l2;
    _a2_obj->f_target_blk = l1;
    l6 = (void*) _a2_obj;
    vader_array_push((vader_array_t*) l3, vader_ref_box(l6));
    { vader_gc_top = gc_frame.prev; return; }
}

static int32_t vader_midir_destination(void* l0, int32_t l1) {
    int32_t l2, l5, l6;
    size_t l3, l4;
    int32_t t0;
    int64_t t1;
    l2 = l1;
    l3 = (size_t) 0;
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
        t1 = (l3 + INT64_C(1));
        l3 = (size_t) (int64_t) t1;
    }
    return l1;
}

static bool vader_midir_dominates(void* l0, int32_t l1, int32_t l2) {
    int32_t l3, l4, l5, l6;
    bool t0;
    l3 = l2;
    for (;;) {
        l4 = -(INT32_C(1));
        t0 = vader_midir_BlockId_Equals_equals(l3, l4);
        if (!(t0)) {
            t0 = vader_midir_BlockId_Equals_equals(l3, l1);
            if (t0) {
                return true;
            }
            l5 = l3;
            vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
            l6 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l5];
            t0 = vader_midir_BlockId_Equals_equals(l6, l3);
            if (t0) {
                t0 = vader_midir_BlockId_Equals_equals(l3, l1);
                return t0;
            }
            l3 = l6;
            continue;
        }
        break;
    }
    return false;
}

static void vader_midir_drain_pending(void* l0, int32_t l1, bool l2, int32_t l3, int32_t l4) {
    int32_t l5;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    size_t l8, l9, l12;
    bool t0;
    int32_t t1;
    int64_t t2;
    void** gc_raw_roots[5] = { &l0, &l6, &l7, &l10, &l11 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l2) {
        l5 = (l3 + INT32_C(1));
    } else {
        l5 = (l4 + INT32_C(1));
    }
    vader_array_t* _a0_arr = vader_array_new(113u, 0u, 13u, 973u);
    l6 = (void*) _a0_arr;
    l7 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_pending;
    l8 = ((vader_array_t*) l7)->length;
    l9 = (size_t) 0;
    while ((l9 < l8)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l9)
        l10 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l9);
        t0 = vader_midir_BlockId_Equals_equals(((vader_struct_vader_midir_PendingBranch_t*) l10)->f_target_blk, l1);
        if (t0) {
            l11 = ((vader_struct_vader_bytecode_BcFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_slot)->f_jump_table;
            t1 = ((vader_struct_vader_midir_PendingBranch_t*) l10)->f_branch_pc;
            t2 = ((int64_t) (int32_t) t1);
            l12 = (size_t) (int64_t) t2;
            vader_array_t* _a2_slotarr = ((vader_array_t*) l11);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l12)
            ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l12] = (int32_t) l5;
        } else {
            vader_array_push((vader_array_t*) l6, vader_ref_box(l10));
        }
        t2 = (l9 + INT64_C(1));
        l9 = (size_t) (int64_t) t2;
    }
    ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_pending = l6;
    VADER_WRITE_BARRIER((vader_struct_vader_midir_FnEmitCfg_t*) l0);
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_midir_dst_of(vader_box_t l0) {
    void* t0;
    vader_box_t t1;
    if (l0.tag == 952u) {
        t0 = l0.payload.obj;
        t1 = vader_box_i32(246u, ((vader_struct_vader_midir_InstrConst_t*) t0)->f_dst);
        return t1;
    }
    if (l0.tag == 962u) {
        t0 = l0.payload.obj;
        t1 = vader_box_i32(246u, ((vader_struct_vader_midir_InstrMove_t*) t0)->f_dst);
        return t1;
    }
    if (l0.tag == 945u) {
        t0 = l0.payload.obj;
        t1 = vader_box_i32(246u, ((vader_struct_vader_midir_InstrBinOp_t*) t0)->f_dst);
        return t1;
    }
    if (l0.tag == 967u) {
        t0 = l0.payload.obj;
        t1 = vader_box_i32(246u, ((vader_struct_vader_midir_InstrUnOp_t*) t0)->f_dst);
        return t1;
    }
    if (l0.tag == 956u) {
        t0 = l0.payload.obj;
        t1 = vader_box_i32(246u, ((vader_struct_vader_midir_InstrFieldGet_t*) t0)->f_dst);
        return t1;
    }
    if (l0.tag == 939u) {
        t0 = l0.payload.obj;
        t1 = vader_box_i32(246u, ((vader_struct_vader_midir_InstrArrayGet_t*) t0)->f_dst);
        return t1;
    }
    if (l0.tag == 940u) {
        t0 = l0.payload.obj;
        t1 = vader_box_i32(246u, ((vader_struct_vader_midir_InstrArrayLen_t*) t0)->f_dst);
        return t1;
    }
    if (l0.tag == 944u) {
        t0 = l0.payload.obj;
        t1 = vader_box_i32(246u, ((vader_struct_vader_midir_InstrArraySlice_t*) t0)->f_dst);
        return t1;
    }
    if (l0.tag == 963u) {
        t0 = l0.payload.obj;
        t1 = vader_box_i32(246u, ((vader_struct_vader_midir_InstrStringSlice_t*) t0)->f_dst);
        return t1;
    }
    if (l0.tag == 964u) {
        t0 = l0.payload.obj;
        t1 = vader_box_i32(246u, ((vader_struct_vader_midir_InstrStructNew_t*) t0)->f_dst);
        return t1;
    }
    if (l0.tag == 941u) {
        t0 = l0.payload.obj;
        t1 = vader_box_i32(246u, ((vader_struct_vader_midir_InstrArrayNew_t*) t0)->f_dst);
        return t1;
    }
    if (l0.tag == 965u) {
        t0 = l0.payload.obj;
        t1 = vader_box_i32(246u, ((vader_struct_vader_midir_InstrTypeCheck_t*) t0)->f_dst);
        return t1;
    }
    if (l0.tag == 966u) {
        t0 = l0.payload.obj;
        t1 = vader_box_i32(246u, ((vader_struct_vader_midir_InstrTypeConst_t*) t0)->f_dst);
        return t1;
    }
    if (l0.tag == 948u) {
        t0 = l0.payload.obj;
        t1 = vader_box_i32(246u, ((vader_struct_vader_midir_InstrCast_t*) t0)->f_dst);
        return t1;
    }
    if (l0.tag == 950u) {
        t0 = l0.payload.obj;
        t1 = vader_box_i32(246u, ((vader_struct_vader_midir_InstrCellNew_t*) t0)->f_dst);
        return t1;
    }
    if (l0.tag == 949u) {
        t0 = l0.payload.obj;
        t1 = vader_box_i32(246u, ((vader_struct_vader_midir_InstrCellGet_t*) t0)->f_dst);
        return t1;
    }
    if (l0.tag == 961u) {
        t0 = l0.payload.obj;
        t1 = vader_box_i32(246u, ((vader_struct_vader_midir_InstrMakeClosure_t*) t0)->f_dst);
        return t1;
    }
    if (l0.tag == 959u) {
        t0 = l0.payload.obj;
        t1 = vader_box_i32(246u, ((vader_struct_vader_midir_InstrFnRef_t*) t0)->f_dst);
        return t1;
    }
    if (l0.tag == 958u) {
        t0 = l0.payload.obj;
        t1 = vader_box_i32(246u, ((vader_struct_vader_midir_InstrFnAddr_t*) t0)->f_dst);
        return t1;
    }
    if (l0.tag == 953u) {
        t0 = l0.payload.obj;
        t1 = vader_box_i32(246u, ((vader_struct_vader_midir_InstrDataConst_t*) t0)->f_dst);
        return t1;
    }
    if (l0.tag == 946u) {
        t0 = l0.payload.obj;
        t1 = vader_midir_call_single_dst(t0);
        return t1;
    }
    if (l0.tag == 947u) {
        t0 = l0.payload.obj;
        return ((vader_struct_vader_midir_InstrCallIndirect_t*) t0)->f_dst;
    }
    if (l0.tag == 968u) {
        t0 = l0.payload.obj;
        return ((vader_struct_vader_midir_InstrVirtualCall_t*) t0)->f_dst;
    }
    if (l0.tag == 960u) {
        t0 = l0.payload.obj;
        return ((vader_struct_vader_midir_InstrIntrinsic_t*) t0)->f_dst;
    }
    if (l0.tag == 957u) {
        return vader_box_obj(0u, NULL);
    }
    if (l0.tag == 943u) {
        return vader_box_obj(0u, NULL);
    }
    if (l0.tag == 942u) {
        return vader_box_obj(0u, NULL);
    }
    if (l0.tag == 951u) {
        return vader_box_obj(0u, NULL);
    }
    if (l0.tag == 955u) {
        return vader_box_obj(0u, NULL);
    }
    if (!(l0.tag == 954u)) {
        vader_unreachable("non-exhaustive match (T3013 should have caught this)");
    }
    return vader_box_obj(0u, NULL);
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
    size_t l5, l6, l11, l14, l15;
    vader_string_t l7 = 0;
    vader_string_t l8 = 0;
    vader_string_t l18 = 0;
    vader_string_t l19 = 0;
    vader_box_t t0 = vader_box_null();
    int64_t t1;
    void* t2 = NULL;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[15] = {
        &l0, &l1, &l2, &l3, &l4, &l9, &l10, &l12, &l13, &l16, &l17, &l20, &l21, &l22, &t2,
    };
    vader_string_t* gc_atom_roots[4] = { &l7, &l8, &l18, &l19 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 15u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(13u, 0u, 0u, 243u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(21u, 0u, 0u, 254u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(14u, 0u, 7u, 246u);
    l3 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__string__Any_t* _a3_obj = (vader_struct_std_collections_MutableMap__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__Any_t));
    vader_obj_header_init(_a3_obj, 335u);
    _a3_obj->f_ekeys = l1;
    _a3_obj->f_evals = l2;
    _a3_obj->f_index = l3;
    _a3_obj->f_mask = (size_t) 0;
    _a3_obj->f_size = (size_t) 0;
    _a3_obj->f_tombs = (size_t) 0;
    l1 = (void*) _a3_obj;
    l2 = ((vader_struct_vader_midir_CFGProject_t*) l0)->f_modules;
    l3 = ((vader_struct_std_collections_MutableMap__string__CFGModule_t*) l2)->f_ekeys;
    l4 = ((vader_struct_std_collections_MutableMap__string__CFGModule_t*) l2)->f_evals;
    l5 = ((vader_struct_std_collections_MutableMap__string__CFGModule_t*) l2)->f_size;
    l6 = (size_t) 0;
    while (!((l6 >= l5))) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l6)
        t0 = vader_array_box_slots(_a4_slotarr->buf)[_a4_slotarr->offset + (size_t) l6];
        l7 = t0.payload.s;
        vader_array_t* _a5_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l6)
        l2 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l6);
        l8 = l7;
        l9 = l2;
        t1 = (l6 + INT64_C(1));
        l6 = (size_t) (int64_t) t1;
        vader_array_t* _a6_arr = vader_array_new(104u, 0u, 13u, 918u);
        l10 = (void*) _a6_arr;
        l11 = ((vader_array_t*) ((vader_struct_vader_midir_CFGModule_t*) l9)->f_functions)->length;
        vader_array_t* _a7_arr = vader_array_repeat((vader_array_t*) l10, (size_t) l11);
        l12 = (void*) _a7_arr;
        l13 = ((vader_struct_vader_midir_CFGModule_t*) l9)->f_functions;
        l14 = ((vader_array_t*) l13)->length;
        l15 = (size_t) 0;
        while ((l15 < l14)) {
            vader_array_t* _a8_slotarr = ((vader_array_t*) l13);
            VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l15)
            t2 = vader_array_ref_load_obj(_a8_slotarr->buf, _a8_slotarr->offset + (size_t) l15);
            l16 = vader_midir_optimise_function(t2);
            vader_array_push((vader_array_t*) l12, vader_ref_box(l16));
            t1 = (l15 + INT64_C(1));
            l15 = (size_t) (int64_t) t1;
        }
        l17 = l9;
        l18 = ((vader_struct_vader_midir_CFGModule_t*) l17)->f_module_id;
        l19 = ((vader_struct_vader_midir_CFGModule_t*) l17)->f_display_path;
        l20 = ((vader_struct_vader_midir_CFGModule_t*) l17)->f_externs;
        l21 = ((vader_struct_vader_midir_CFGModule_t*) l17)->f_struct_decls;
        vader_struct_vader_midir_CFGModule_t* _a9_obj = (vader_struct_vader_midir_CFGModule_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_CFGModule_t));
        vader_obj_header_init(_a9_obj, 920u);
        _a9_obj->f_module_id = l18;
        _a9_obj->f_display_path = l19;
        _a9_obj->f_functions = l12;
        _a9_obj->f_externs = l20;
        _a9_obj->f_struct_decls = l21;
        l22 = (void*) _a9_obj;
        std_collections_MutableMap_IndexSet_set_at__string__Any(l1, l8, vader_ref_box(l22));
    }
    l2 = l0;
    l3 = ((vader_struct_vader_midir_CFGProject_t*) l2)->f_vtable_entries;
    l4 = ((vader_struct_vader_midir_CFGProject_t*) l2)->f_strings;
    l9 = ((vader_struct_vader_midir_CFGProject_t*) l2)->f_data_pool;
    l2 = ((vader_struct_vader_midir_CFGProject_t*) l2)->f_trait_membership;
    vader_struct_vader_midir_CFGProject_t* _a10_obj = (vader_struct_vader_midir_CFGProject_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_CFGProject_t));
    vader_obj_header_init(_a10_obj, 922u);
    _a10_obj->f_modules = l1;
    _a10_obj->f_vtable_entries = l3;
    _a10_obj->f_strings = l4;
    _a10_obj->f_data_pool = l9;
    _a10_obj->f_trait_membership = l2;
    t2 = (void*) _a10_obj;
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_midir_emit(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    size_t l3;
    int64_t t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[3] = { &l0, &l2, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (!(((vader_struct_vader_midir_FnCtx_t*) l0)->f_current.tag == 0u)) {
        l2 = ((vader_struct_vader_midir_FnCtx_t*) l0)->f_blocks;
        t0 = ((int64_t) ((vader_struct_vader_midir_FnCtx_t*) l0)->f_current.payload.i);
        l3 = (size_t) (int64_t) t0;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t1 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
        vader_array_push((vader_array_t*) ((vader_struct_vader_midir_MutableBlock_t*) t1)->f_instructions, l1);
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_midir_emit_body(void* l0, void* l1, int32_t l2, int32_t l3, int32_t l4) {
    void* l5 = NULL;
    void* l8 = NULL;
    int32_t l6, l9;
    size_t l7, l10;
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
    vader_midir_emit_instructions(l0, l2, (size_t) 0, l7);
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
    t0 = vader_midir_BlockId_Equals_equals(l3, l4);
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
    void* l20 = NULL;
    void* l21 = NULL;
    void* l23 = NULL;
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
    size_t l7, l8, l10, l11, l13, l14, l16, l17;
    int32_t l18, l22;
    vader_box_t l19 = vader_box_null(), l25 = vader_box_null();
    vader_string_t l24 = 0;
    vader_string_t l41 = 0;
    vader_string_t l42 = 0;
    vader_string_t l43 = 0;
    bool l26;
    vader_box_t t0 = vader_box_null();
    vader_string_t t1 = 0;
    int64_t t2;
    void* t3 = NULL;
    bool t4;
    size_t t5;
    vader_box_t* gc_roots[3] = { &l19, &l25, &t0 };
    void** gc_raw_roots[27] = {
        &l0, &l2, &l3, &l4, &l5, &l6, &l9, &l12, &l15, &l20, &l21, &l23, &l27, &l28, &l29, &l30,
        &l31, &l32, &l33, &l34, &l35, &l36, &l37, &l38, &l39, &l40, &t3,
    };
    vader_string_t* gc_atom_roots[6] = { &l1, &l24, &l41, &l42, &l43, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 27u, gc_roots, gc_raw_roots, 0u, NULL, 6u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = vader_bytecode_new_emitter_ctx();
    l4 = ((vader_struct_vader_midir_CFGProject_t*) l0)->f_modules;
    l5 = ((vader_struct_std_collections_MutableMap__string__CFGModule_t*) l4)->f_ekeys;
    l6 = ((vader_struct_std_collections_MutableMap__string__CFGModule_t*) l4)->f_evals;
    l7 = ((vader_struct_std_collections_MutableMap__string__CFGModule_t*) l4)->f_size;
    l8 = (size_t) 0;
    while (!((l8 >= l7))) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l8)
        t0 = vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l8];
        t1 = t0.payload.s;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l8)
        l4 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l8);
        t2 = (l8 + INT64_C(1));
        l8 = (size_t) (int64_t) t2;
        l9 = ((vader_struct_vader_midir_CFGModule_t*) l4)->f_functions;
        l10 = ((vader_array_t*) l9)->length;
        l11 = (size_t) 0;
        while ((l11 < l10)) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) l9);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l11)
            t3 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l11);
            vader_midir_reserve_cfg_function(t3, l3);
            t2 = (l11 + INT64_C(1));
            l11 = (size_t) (int64_t) t2;
        }
        l12 = ((vader_struct_vader_midir_CFGModule_t*) l4)->f_externs;
        l13 = ((vader_array_t*) l12)->length;
        l14 = (size_t) 0;
        while ((l14 < l13)) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l12);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l14)
            t3 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l14);
            vader_midir_reserve_cfg_extern(t3, l3);
            t2 = (l14 + INT64_C(1));
            l14 = (size_t) (int64_t) t2;
        }
        l15 = ((vader_struct_vader_midir_CFGModule_t*) l4)->f_struct_decls;
        l16 = ((vader_array_t*) l15)->length;
        l17 = (size_t) 0;
        while ((l17 < l16)) {
            vader_array_t* _a4_slotarr = ((vader_array_t*) l15);
            VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l17)
            t3 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l17);
            vader_midir_reserve_cfg_struct(t3, l3);
            t2 = (l17 + INT64_C(1));
            l17 = (size_t) (int64_t) t2;
        }
    }
    vader_midir_synthesise_cfg_intrinsic_wrappers(l0, l3);
    vader_array_t* _a5_arr = vader_array_new(14u, 0u, 7u, 246u);
    l4 = (void*) _a5_arr;
    l7 = ((vader_array_t*) ((vader_struct_vader_midir_CFGProject_t*) l0)->f_strings)->length;
    vader_array_t* _a6_arr = vader_array_repeat((vader_array_t*) l4, (size_t) l7);
    l4 = (void*) _a6_arr;
    l5 = ((vader_struct_vader_midir_CFGProject_t*) l0)->f_strings;
    l7 = ((vader_array_t*) l5)->length;
    l8 = (size_t) 0;
    while ((l8 < l7)) {
        vader_array_t* _a7_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l8)
        t0 = vader_array_box_slots(_a7_slotarr->buf)[_a7_slotarr->offset + (size_t) l8];
        t1 = t0.payload.s;
        l18 = vader_bytecode_intern_string(t1, l3);
        vader_array_push_i32((vader_array_t*) l4, l18);
        t2 = (l8 + INT64_C(1));
        l8 = (size_t) (int64_t) t2;
    }
    l5 = ((vader_struct_vader_midir_CFGProject_t*) l0)->f_data_pool;
    l7 = ((vader_array_t*) l5)->length;
    l8 = (size_t) 0;
    while ((l8 < l7)) {
        vader_array_t* _a8_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l8)
        l19 = vader_array_ref_load_box(_a8_slotarr->buf, _a8_slotarr->offset + (size_t) l8);
        if (l19.tag == 560u) {
            t3 = l19.payload.obj;
            l6 = ((vader_struct_vader_bytecode_BcStrData_t*) t3)->f_values;
            l10 = ((vader_array_t*) l6)->length;
            l11 = (size_t) 0;
            while ((l11 < l10)) {
                vader_array_t* _a9_slotarr = ((vader_array_t*) l6);
                VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l11)
                t0 = vader_array_box_slots(_a9_slotarr->buf)[_a9_slotarr->offset + (size_t) l11];
                t1 = t0.payload.s;
                vader_bytecode_intern_string(t1, l3);
                t2 = (l11 + INT64_C(1));
                l11 = (size_t) (int64_t) t2;
            }
        } else if (l19.tag == 547u) {
            t3 = l19.payload.obj;
            l9 = ((vader_struct_vader_bytecode_BcAggregateData_t*) t3)->f_elements;
            l13 = ((vader_array_t*) l9)->length;
            l14 = (size_t) 0;
            while ((l14 < l13)) {
                vader_array_t* _a10_slotarr = ((vader_array_t*) l9);
                VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a10_slotarr, l14)
                t0 = vader_array_ref_load_box(_a10_slotarr->buf, _a10_slotarr->offset + (size_t) l14);
                vader_midir_intern_data_value_strings(t0, l3);
                t2 = (l14 + INT64_C(1));
                l14 = (size_t) (int64_t) t2;
            }
        }
        t2 = (l8 + INT64_C(1));
        l8 = (size_t) (int64_t) t2;
    }
    l5 = ((vader_struct_vader_midir_CFGProject_t*) l0)->f_modules;
    l6 = ((vader_struct_std_collections_MutableMap__string__CFGModule_t*) l5)->f_ekeys;
    l9 = ((vader_struct_std_collections_MutableMap__string__CFGModule_t*) l5)->f_evals;
    l7 = ((vader_struct_std_collections_MutableMap__string__CFGModule_t*) l5)->f_size;
    l8 = (size_t) 0;
    while (!((l8 >= l7))) {
        vader_array_t* _a11_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l8)
        t0 = vader_array_box_slots(_a11_slotarr->buf)[_a11_slotarr->offset + (size_t) l8];
        t1 = t0.payload.s;
        vader_array_t* _a12_slotarr = ((vader_array_t*) l9);
        VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a12_slotarr, l8)
        l5 = vader_array_ref_load_obj(_a12_slotarr->buf, _a12_slotarr->offset + (size_t) l8);
        t2 = (l8 + INT64_C(1));
        l8 = (size_t) (int64_t) t2;
        l12 = ((vader_struct_vader_midir_CFGModule_t*) l5)->f_functions;
        l10 = ((vader_array_t*) l12)->length;
        l11 = (size_t) 0;
        while ((l11 < l10)) {
            vader_array_t* _a13_slotarr = ((vader_array_t*) l12);
            VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a13_slotarr, l11)
            l15 = vader_array_ref_load_obj(_a13_slotarr->buf, _a13_slotarr->offset + (size_t) l11);
            t4 = ((vader_struct_vader_midir_CFGFunction_t*) l15)->f_is_extern;
            if (t4) {
                t2 = (l11 + INT64_C(1));
                l11 = (size_t) (int64_t) t2;
                continue;
            }
            l18 = -(INT32_C(1));
            if (((vader_struct_vader_comptime_MonoEntry_t*) ((vader_struct_vader_midir_CFGFunction_t*) l15)->f_origin)->f_symbol.tag == 1019u) {
                l20 = ((vader_struct_vader_comptime_MonoEntry_t*) ((vader_struct_vader_midir_CFGFunction_t*) l15)->f_origin)->f_symbol.payload.obj;
                l21 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l3)->f_function_index_by_symbol_id;
                l22 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l20)->f_id;
                l19 = std_collections_MutableMap_Index_at__i32__i32(l21, l22);
                if (l19.tag == 246u) {
                    l18 = ((int32_t) l19.payload.i);
                }
            }
            if ((l18 < INT32_C(0))) {
                l23 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l3)->f_function_index_by_mangle;
                l24 = ((vader_struct_vader_midir_CFGFunction_t*) l15)->f_mangled;
                l25 = std_collections_MutableMap_Index_at__string__i32(l23, l24);
                if (l25.tag == 246u) {
                    l18 = ((int32_t) l25.payload.i);
                }
            }
            if ((l18 >= INT32_C(0))) {
                l26 = ((vader_struct_vader_bytecode_EmitOptions_t*) l2)->f_want_debug;
                vader_midir_emit_cfg_function_body(l15, l18, l3, l4, l26);
            }
            t2 = (l11 + INT64_C(1));
            l11 = (size_t) (int64_t) t2;
        }
    }
    l4 = ((vader_struct_vader_midir_CFGProject_t*) l0)->f_data_pool;
    t4 = ((vader_struct_vader_bytecode_EmitOptions_t*) l2)->f_optimize;
    if (t4) {
        l7 = (size_t) 0;
        l8 = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l3)->f_functions)->length;
        while ((l7 < l8)) {
            vader_array_t* _a14_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l3)->f_functions);
            VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a14_slotarr, l7)
            t3 = vader_array_ref_load_obj(_a14_slotarr->buf, _a14_slotarr->offset + (size_t) l7);
            t5 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) t3)->f_body)->length;
            t2 = (t5 + INT64_C(1));
            l10 = (size_t) (int64_t) t2;
            for (;;) {
                vader_array_t* _a15_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l3)->f_functions);
                VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a15_slotarr, l7)
                t3 = vader_array_ref_load_obj(_a15_slotarr->buf, _a15_slotarr->offset + (size_t) l7);
                t5 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) t3)->f_body)->length;
                if ((t5 < l10)) {
                    vader_array_t* _a16_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l3)->f_functions);
                    VADER_ARRAY_RESOLVE_BUF(_a16_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a16_slotarr, l7)
                    t3 = vader_array_ref_load_obj(_a16_slotarr->buf, _a16_slotarr->offset + (size_t) l7);
                    l10 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) t3)->f_body)->length;
                    l5 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l3)->f_functions;
                    VADER_ARRAY_CHECK_INDEX(_a16_slotarr, l7)
                    t3 = vader_array_ref_load_obj(_a16_slotarr->buf, _a16_slotarr->offset + (size_t) l7);
                    l6 = vader_bytecode_propagate_const_single_use(t3);
                    vader_array_t* _a17_slotarr = ((vader_array_t*) l5);
                    VADER_ARRAY_RESOLVE_BUF(_a17_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a17_slotarr, l7)
                    vader_array_ref_store(_a17_slotarr->buf, _a17_slotarr->offset + (size_t) l7, l6);
                    VADER_WRITE_BARRIER(_a17_slotarr->buf);
                    continue;
                }
                break;
            }
            l9 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l3)->f_functions;
            vader_array_t* _a18_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l3)->f_functions);
            VADER_ARRAY_RESOLVE_BUF(_a18_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a18_slotarr, l7)
            l12 = vader_array_ref_load_obj(_a18_slotarr->buf, _a18_slotarr->offset + (size_t) l7);
            VADER_ARRAY_CHECK_INDEX(_a18_slotarr, l7)
            t3 = vader_array_ref_load_obj(_a18_slotarr->buf, _a18_slotarr->offset + (size_t) l7);
            l15 = vader_bytecode_run_bc_peephole(t3);
            l20 = vader_midir_with_peephole_out(l12, l15);
            vader_array_t* _a19_slotarr = ((vader_array_t*) l9);
            VADER_ARRAY_RESOLVE_BUF(_a19_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a19_slotarr, l7)
            vader_array_ref_store(_a19_slotarr->buf, _a19_slotarr->offset + (size_t) l7, l20);
            VADER_WRITE_BARRIER(_a19_slotarr->buf);
            l21 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l3)->f_functions;
            vader_array_t* _a20_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l3)->f_functions);
            VADER_ARRAY_RESOLVE_BUF(_a20_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a20_slotarr, l7)
            l23 = vader_array_ref_load_obj(_a20_slotarr->buf, _a20_slotarr->offset + (size_t) l7);
            VADER_ARRAY_CHECK_INDEX(_a20_slotarr, l7)
            t3 = vader_array_ref_load_obj(_a20_slotarr->buf, _a20_slotarr->offset + (size_t) l7);
            l27 = vader_bytecode_run_bc_const_fold_arith(t3);
            l28 = vader_midir_with_peephole_out(l23, l27);
            vader_array_t* _a21_slotarr = ((vader_array_t*) l21);
            VADER_ARRAY_RESOLVE_BUF(_a21_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a21_slotarr, l7)
            vader_array_ref_store(_a21_slotarr->buf, _a21_slotarr->offset + (size_t) l7, l28);
            VADER_WRITE_BARRIER(_a21_slotarr->buf);
            l29 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l3)->f_functions;
            vader_array_t* _a22_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l3)->f_functions);
            VADER_ARRAY_RESOLVE_BUF(_a22_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a22_slotarr, l7)
            t3 = vader_array_ref_load_obj(_a22_slotarr->buf, _a22_slotarr->offset + (size_t) l7);
            l30 = vader_bytecode_drop_dead_stores(t3);
            vader_array_t* _a23_slotarr = ((vader_array_t*) l29);
            VADER_ARRAY_RESOLVE_BUF(_a23_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a23_slotarr, l7)
            vader_array_ref_store(_a23_slotarr->buf, _a23_slotarr->offset + (size_t) l7, l30);
            VADER_WRITE_BARRIER(_a23_slotarr->buf);
            l31 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l3)->f_functions;
            vader_array_t* _a24_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l3)->f_functions);
            VADER_ARRAY_RESOLVE_BUF(_a24_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a24_slotarr, l7)
            l32 = vader_array_ref_load_obj(_a24_slotarr->buf, _a24_slotarr->offset + (size_t) l7);
            VADER_ARRAY_CHECK_INDEX(_a24_slotarr, l7)
            t3 = vader_array_ref_load_obj(_a24_slotarr->buf, _a24_slotarr->offset + (size_t) l7);
            l33 = vader_bytecode_run_bc_return_lit_fold(t3);
            l34 = vader_midir_with_peephole_out(l32, l33);
            vader_array_t* _a25_slotarr = ((vader_array_t*) l31);
            VADER_ARRAY_RESOLVE_BUF(_a25_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a25_slotarr, l7)
            vader_array_ref_store(_a25_slotarr->buf, _a25_slotarr->offset + (size_t) l7, l34);
            VADER_WRITE_BARRIER(_a25_slotarr->buf);
            l35 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l3)->f_functions;
            vader_array_t* _a26_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l3)->f_functions);
            VADER_ARRAY_RESOLVE_BUF(_a26_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a26_slotarr, l7)
            t3 = vader_array_ref_load_obj(_a26_slotarr->buf, _a26_slotarr->offset + (size_t) l7);
            l36 = vader_bytecode_coalesce_slots(t3);
            vader_array_t* _a27_slotarr = ((vader_array_t*) l35);
            VADER_ARRAY_RESOLVE_BUF(_a27_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a27_slotarr, l7)
            vader_array_ref_store(_a27_slotarr->buf, _a27_slotarr->offset + (size_t) l7, l36);
            VADER_WRITE_BARRIER(_a27_slotarr->buf);
            l37 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l3)->f_functions;
            vader_array_t* _a28_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l3)->f_functions);
            VADER_ARRAY_RESOLVE_BUF(_a28_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a28_slotarr, l7)
            l38 = vader_array_ref_load_obj(_a28_slotarr->buf, _a28_slotarr->offset + (size_t) l7);
            VADER_ARRAY_CHECK_INDEX(_a28_slotarr, l7)
            t3 = vader_array_ref_load_obj(_a28_slotarr->buf, _a28_slotarr->offset + (size_t) l7);
            l39 = vader_bytecode_strip_self_copies(t3);
            l40 = vader_midir_with_peephole_out(l38, l39);
            vader_array_t* _a29_slotarr = ((vader_array_t*) l37);
            VADER_ARRAY_RESOLVE_BUF(_a29_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a29_slotarr, l7)
            vader_array_ref_store(_a29_slotarr->buf, _a29_slotarr->offset + (size_t) l7, l40);
            VADER_WRITE_BARRIER(_a29_slotarr->buf);
            t2 = (l7 + INT64_C(1));
            l7 = (size_t) (int64_t) t2;
        }
        vader_array_t* _a30_arr = vader_array_new(13u, 0u, 0u, 243u);
        l5 = (void*) _a30_arr;
        vader_array_t* _a31_arr = vader_array_new(11u, 0u, 12u, 241u);
        l6 = (void*) _a31_arr;
        vader_array_t* _a32_arr = vader_array_new(14u, 0u, 7u, 246u);
        l9 = (void*) _a32_arr;
        vader_struct_std_collections_MutableMap__string__bool_t* _a33_obj = (vader_struct_std_collections_MutableMap__string__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__bool_t));
        vader_obj_header_init(_a33_obj, 383u);
        _a33_obj->f_ekeys = l5;
        _a33_obj->f_evals = l6;
        _a33_obj->f_index = l9;
        _a33_obj->f_mask = (size_t) 0;
        _a33_obj->f_size = (size_t) 0;
        _a33_obj->f_tombs = (size_t) 0;
        l5 = (void*) _a33_obj;
        l6 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l3)->f_functions;
        l7 = ((vader_array_t*) l6)->length;
        l8 = (size_t) 0;
        while ((l8 < l7)) {
            vader_array_t* _a34_slotarr = ((vader_array_t*) l6);
            VADER_ARRAY_RESOLVE_BUF(_a34_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a34_slotarr, l8)
            t3 = vader_array_ref_load_obj(_a34_slotarr->buf, _a34_slotarr->offset + (size_t) l8);
            l9 = ((vader_struct_vader_bytecode_BcFunction_t*) t3)->f_body;
            l10 = ((vader_array_t*) l9)->length;
            l11 = (size_t) 0;
            while ((l11 < l10)) {
                vader_array_t* _a35_slotarr = ((vader_array_t*) l9);
                VADER_ARRAY_RESOLVE_BUF(_a35_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a35_slotarr, l11)
                l19 = vader_array_ref_load_box(_a35_slotarr->buf, _a35_slotarr->offset + (size_t) l11);
                if (l19.tag == 709u) {
                    t3 = l19.payload.obj;
                    l24 = ((vader_struct_vader_bytecode_VirtualCall_t*) t3)->f_vtable_key;
                    std_collections_MutableMap_IndexSet_set_at__string__bool(l5, l24, true);
                }
                t2 = (l11 + INT64_C(1));
                l11 = (size_t) (int64_t) t2;
            }
            t2 = (l8 + INT64_C(1));
            l8 = (size_t) (int64_t) t2;
        }
        vader_array_t* _a36_arr = vader_array_new(14u, 0u, 7u, 246u);
        l6 = (void*) _a36_arr;
        l9 = ((vader_struct_vader_midir_CFGProject_t*) l0)->f_vtable_entries;
        l7 = ((vader_array_t*) l9)->length;
        l8 = (size_t) 0;
        while ((l8 < l7)) {
            vader_array_t* _a37_slotarr = ((vader_array_t*) l9);
            VADER_ARRAY_RESOLVE_BUF(_a37_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a37_slotarr, l8)
            l12 = vader_array_ref_load_obj(_a37_slotarr->buf, _a37_slotarr->offset + (size_t) l8);
            l24 = ((vader_struct_vader_lower_LoweredVtableEntry_t*) l12)->f_trait_name;
            l41 = ((vader_struct_vader_lower_LoweredVtableEntry_t*) l12)->f_method_name;
            l42 = concat_3(l24, 308u, l41);
            t0 = std_collections_MutableMap_Index_at__string__bool(l5, l42);
            if (t0.tag == 241u) {
                l43 = vader_bytecode_type_intern_key(((vader_struct_vader_lower_LoweredVtableEntry_t*) l12)->f_struct_type);
                l19 = std_collections_MutableMap_Index_at__string__i32(((vader_struct_vader_bytecode_EmitterCtx_t*) l3)->f_type_key, l43);
                if (l19.tag == 246u) {
                    l15 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l3)->f_pinned_types;
                    l18 = ((int32_t) l19.payload.i);
                    vader_array_push_i32((vader_array_t*) l15, l18);
                }
                l22 = vader_midir_resolve_fn_index(((vader_struct_vader_lower_LoweredVtableEntry_t*) l12)->f_fn_symbol, l3);
                if ((l22 >= INT32_C(0))) {
                    vader_array_push_i32((vader_array_t*) l6, l22);
                }
                t2 = (l8 + INT64_C(1));
                l8 = (size_t) (int64_t) t2;
                continue;
            }
            t2 = (l8 + INT64_C(1));
            l8 = (size_t) (int64_t) t2;
        }
        l5 = ((vader_struct_vader_bytecode_EmitOptions_t*) l2)->f_keep_mangles;
        vader_bytecode_prune_unused_functions(l3, l6, l5);
        vader_bytecode_prune_unused_imports(l3);
        l4 = vader_bytecode_prune_unused_data(l3, l4);
        vader_midir_pin_baked_struct_types(l4, l3);
        vader_bytecode_prune_unused_types(l3);
        ((vader_struct_vader_bytecode_EmitterCtx_t*) l3)->f_types_frozen = true;
        l5 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l3)->f_imports;
        l7 = ((vader_array_t*) l5)->length;
        l8 = (size_t) 0;
        while ((l8 < l7)) {
            vader_array_t* _a38_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a38_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a38_slotarr, l8)
            l6 = vader_array_ref_load_obj(_a38_slotarr->buf, _a38_slotarr->offset + (size_t) l8);
            l24 = ((vader_struct_vader_bytecode_BcImport_t*) l6)->f_mangled_name;
            l26 = ((vader_struct_vader_bytecode_BcImport_t*) l6)->f_is_extern;
            vader_bytecode_assert_host_import_wired(l24, l26);
            t2 = (l8 + INT64_C(1));
            l8 = (size_t) (int64_t) t2;
        }
    }
    l5 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l3)->f_types;
    l6 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l3)->f_strings;
    l9 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l3)->f_functions;
    l12 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l3)->f_imports;
    l15 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l3)->f_exports;
    l20 = ((vader_struct_vader_midir_CFGProject_t*) l0)->f_vtable_entries;
    l21 = ((vader_struct_vader_midir_CFGProject_t*) l0)->f_trait_membership;
    l20 = vader_midir_build_impl_table_from_vtable(l20, l21, l3);
    l3 = vader_midir_build_vtables_from_entries(((vader_struct_vader_midir_CFGProject_t*) l0)->f_vtable_entries, l3);
    vader_struct_vader_bytecode_BytecodeModule_t* _a39_obj = (vader_struct_vader_bytecode_BytecodeModule_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BytecodeModule_t));
    vader_obj_header_init(_a39_obj, 581u);
    _a39_obj->f_name = l1;
    _a39_obj->f_types = l5;
    _a39_obj->f_strings = l6;
    _a39_obj->f_data_pool = l4;
    _a39_obj->f_functions = l9;
    _a39_obj->f_imports = l12;
    _a39_obj->f_exports = l15;
    _a39_obj->f_impl_table = l20;
    _a39_obj->f_vtables = l3;
    t3 = (void*) _a39_obj;
    { void* __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_midir_emit_call_results(void* l0, int64_t l1, void* l2, void* l3) {
    vader_box_t l4 = vader_box_null();
    size_t l5, l6, l7;
    int32_t l8;
    size_t t0;
    int32_t t1;
    int64_t t2;
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
        l4 = vader_box_i32(246u, t1);
        vader_midir_emit_result_if_any(l0, l1, l4, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    l5 = (size_t) 0;
    l6 = ((vader_array_t*) l2)->length;
    while ((l5 < l6)) {
        t0 = ((vader_array_t*) l2)->length;
        t2 = ((t0 - INT64_C(1)) - l5);
        l7 = (size_t) (int64_t) t2;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l7)
        l8 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l7];
        vader_midir_emit_set(l0, l8, l3);
        t2 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t2;
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_midir_emit_cfg_function_body(void* l0, int32_t l1, void* l2, void* l3, bool l4) {
    void* l5 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l15 = NULL;
    void* l18 = NULL;
    void* l19 = NULL;
    void* l20 = NULL;
    size_t l6, l9, l10;
    int32_t l11, l12, l13, l14;
    vader_string_t l16 = 0;
    uint8_t l17;
    int64_t t0;
    size_t t1;
    void* t2 = NULL;
    void** gc_raw_roots[11] = { &l0, &l2, &l3, &l5, &l7, &l8, &l15, &l18, &l19, &l20, &t2 };
    vader_string_t* gc_atom_roots[1] = { &l16 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 11u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l5 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l2)->f_functions;
    t0 = ((int64_t) (int32_t) l1);
    l6 = (size_t) (int64_t) t0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l6)
    l5 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l6);
    vader_array_t* _a1_arr = vader_array_new(14u, 0u, 7u, 246u);
    l7 = (void*) _a1_arr;
    std_collections_MutableMap_IndexSet_set_at__i32__Any(((vader_struct_vader_bytecode_EmitterCtx_t*) l2)->f_pinned_types_by_fn, l1, vader_ref_box(l7));
    vader_array_t* _a2_arr = vader_array_new(14u, 0u, 7u, 246u);
    l8 = (void*) _a2_arr;
    l6 = ((vader_array_t*) ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_params)->length;
    l9 = (size_t) 0;
    l10 = ((vader_array_t*) ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_locals)->length;
    while ((l9 < l10)) {
        if ((l9 < l6)) {
            l11 = ((int32_t) (size_t) l9);
            vader_array_push_i32((vader_array_t*) l8, l11);
        } else {
            l12 = ((int32_t) (size_t) l6);
            t1 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l5)->f_locals)->length;
            l13 = ((int32_t) (size_t) t1);
            l14 = (l12 + l13);
            l15 = ((vader_struct_vader_bytecode_BcFunction_t*) l5)->f_locals;
            vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_locals);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l9)
            t2 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l9);
            l16 = ((vader_struct_vader_midir_CFGLocal_t*) t2)->f_name;
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l9)
            t2 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l9);
            l17 = vader_bytecode_val_type_of_type(((vader_struct_vader_midir_CFGLocal_t*) t2)->f_type);
            vader_struct_vader_bytecode_BcLocal_t* _a4_obj = (vader_struct_vader_bytecode_BcLocal_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcLocal_t));
            vader_obj_header_init(_a4_obj, 554u);
            _a4_obj->f_name = l16;
            _a4_obj->f_val = l17;
            l18 = (void*) _a4_obj;
            vader_array_push((vader_array_t*) l15, vader_ref_box(l18));
            vader_array_push_i32((vader_array_t*) l8, l14);
        }
        t0 = (l9 + INT64_C(1));
        l9 = (size_t) (int64_t) t0;
    }
    l15 = vader_midir_skip_forwarding_blocks(l0);
    l18 = vader_midir_schedule_stack(l15);
    vader_array_t* _a5_arr = vader_array_new(114u, 0u, 13u, 976u);
    l19 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(113u, 0u, 13u, 973u);
    l20 = (void*) _a6_arr;
    vader_struct_vader_midir_FnEmitCfg_t* _a7_obj = (vader_struct_vader_midir_FnEmitCfg_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_FnEmitCfg_t));
    vader_obj_header_init(_a7_obj, 937u);
    _a7_obj->f_fn_ = l15;
    _a7_obj->f_pinned_types_bucket = l7;
    _a7_obj->f_slot = l5;
    _a7_obj->f_project = l2;
    _a7_obj->f_string_index_map = l3;
    _a7_obj->f_local_to_slot = l8;
    _a7_obj->f_scopes = l19;
    _a7_obj->f_pending = l20;
    _a7_obj->f_hints = l18;
    _a7_obj->f_want_debug = l4;
    t2 = (void*) _a7_obj;
    vader_midir_structure_function(t2);
    l5 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l2)->f_functions;
    t0 = ((int64_t) (int32_t) l1);
    l6 = (size_t) (int64_t) t0;
    l7 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l2)->f_functions;
    t0 = ((int64_t) (int32_t) l1);
    l9 = (size_t) (int64_t) t0;
    vader_array_t* _a8_slotarr = ((vader_array_t*) l7);
    VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l9)
    l7 = vader_array_ref_load_obj(_a8_slotarr->buf, _a8_slotarr->offset + (size_t) l9);
    l8 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l2)->f_functions;
    t0 = ((int64_t) (int32_t) l1);
    l9 = (size_t) (int64_t) t0;
    vader_array_t* _a9_slotarr = ((vader_array_t*) l8);
    VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l9)
    t2 = vader_array_ref_load_obj(_a9_slotarr->buf, _a9_slotarr->offset + (size_t) l9);
    l8 = vader_bytecode_drop_unbranched_blocks(t2);
    l7 = vader_midir_with_peephole_out(l7, l8);
    vader_array_t* _a10_slotarr = ((vader_array_t*) l5);
    VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a10_slotarr, l6)
    vader_array_ref_store(_a10_slotarr->buf, _a10_slotarr->offset + (size_t) l6, l7);
    VADER_WRITE_BARRIER(_a10_slotarr->buf);
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
    t0 = std_collections_MutableSet_Contains_contains__i32(((vader_struct_vader_midir_ScheduleHints_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_hints)->f_skip_terminator_get, l2);
    if (!(t0)) {
        l6 = ((vader_struct_vader_midir_TermCondBranch_t*) l3)->f_cond;
        l7 = ((vader_struct_vader_midir_TermCondBranch_t*) l3)->f_span;
        vader_midir_emit_get(l0, l6, l7);
    }
    t0 = vader_midir_BlockId_Equals_equals(((vader_struct_vader_midir_TermCondBranch_t*) l3)->f_else_block, l4);
    if (!(t0)) {
        t0 = vader_midir_BlockId_Equals_equals(((vader_struct_vader_midir_TermCondBranch_t*) l3)->f_else_block, l5);
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
    t0 = vader_midir_BlockId_Equals_equals(((vader_struct_vader_midir_TermCondBranch_t*) l3)->f_then_block, l4);
    if (!(t0)) {
        t0 = vader_midir_BlockId_Equals_equals(((vader_struct_vader_midir_TermCondBranch_t*) l3)->f_then_block, l5);
        if (!(t0)) {
            l7 = ((vader_struct_vader_midir_StructureShape_t*) l1)->f_merge;
            l6 = ((vader_struct_vader_midir_TermCondBranch_t*) l3)->f_then_block;
            vader_array_t* _a2_slotarr = ((vader_array_t*) l7);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l6)
            t1 = vader_box_bool(241u, ((uint8_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l6]);
            t0 = t1.payload.b;
            if (t0) {
                if (l10) {
                    l7 = ((vader_struct_vader_midir_TermCondBranch_t*) l3)->f_span;
                    l6 = ((vader_struct_vader_midir_TermCondBranch_t*) l3)->f_then_block;
                    vader_midir_cf_br_if(l0, l7, l6);
                    t0 = vader_midir_BlockId_Equals_equals(((vader_struct_vader_midir_TermCondBranch_t*) l3)->f_else_block, l5);
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
            t0 = vader_midir_BlockId_Equals_equals(((vader_struct_vader_midir_TermCondBranch_t*) l3)->f_then_block, l5);
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
    t0 = vader_midir_BlockId_Equals_equals(((vader_struct_vader_midir_TermCondBranch_t*) l3)->f_then_block, l5);
    if (!(t0)) {
        l6 = ((vader_struct_vader_midir_TermCondBranch_t*) l3)->f_then_block;
        l7 = ((vader_struct_vader_midir_TermCondBranch_t*) l3)->f_span;
        vader_midir_emit_branch(l0, l1, l2, l6, l4, l7);
    }
    t0 = vader_midir_BlockId_Equals_equals(((vader_struct_vader_midir_TermCondBranch_t*) l3)->f_else_block, l4);
    if (t0) {
        l8 = true;
    } else {
        l8 = vader_midir_BlockId_Equals_equals(((vader_struct_vader_midir_TermCondBranch_t*) l3)->f_else_block, l5);
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
    l4 = vader_midir_fresh_tmp(l0, 1893u, l1);
    vader_struct_vader_midir_InstrConst_t* _a0_obj = (vader_struct_vader_midir_InstrConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrConst_t));
    vader_obj_header_init(_a0_obj, 952u);
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
    size_t l6;
    int32_t l7;
    uint8_t t0;
    bool t1;
    void* t2 = NULL;
    int64_t t3;
    double t4;
    int32_t t5;
    vader_box_t* gc_roots[1] = { &l3 };
    void** gc_raw_roots[5] = { &l0, &l1, &l4, &l5, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_midir_InstrConst_t*) l1)->f_value;
    if (l3.tag == 929u) {
        t0 = vader_bytecode_val_type_of_type(((vader_struct_vader_midir_InstrConst_t*) l1)->f_type);
        t1 = vader_bytecode_is_64_bit_int_val(t0);
        if (t1) {
            t2 = l3.payload.obj;
            t3 = ((vader_struct_vader_midir_ConstInt_t*) t2)->f_value;
            vader_struct_vader_bytecode_I64Const_t* _a0_obj = (vader_struct_vader_bytecode_I64Const_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64Const_t));
            vader_obj_header_init(_a0_obj, 638u);
            _a0_obj->f_value = t3;
            l4 = (void*) _a0_obj;
            l5 = ((vader_struct_vader_midir_InstrConst_t*) l1)->f_span;
            vader_midir_push_emit(l0, vader_ref_box(l4), l5);
        } else {
            t2 = l3.payload.obj;
            t3 = ((vader_struct_vader_midir_ConstInt_t*) t2)->f_value;
            vader_struct_vader_bytecode_I32Const_t* _a1_obj = (vader_struct_vader_bytecode_I32Const_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32Const_t));
            vader_obj_header_init(_a1_obj, 618u);
            _a1_obj->f_value = ((int32_t) (int64_t) t3);
            l4 = (void*) _a1_obj;
            l5 = ((vader_struct_vader_midir_InstrConst_t*) l1)->f_span;
            vader_midir_push_emit(l0, vader_ref_box(l4), l5);
        }
    } else if (l3.tag == 928u) {
        t2 = l3.payload.obj;
        t4 = ((vader_struct_vader_midir_ConstFloat_t*) t2)->f_value;
        vader_struct_vader_bytecode_F64Const_t* _a2_obj = (vader_struct_vader_bytecode_F64Const_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_F64Const_t));
        vader_obj_header_init(_a2_obj, 599u);
        _a2_obj->f_value = t4;
        l4 = (void*) _a2_obj;
        l5 = ((vader_struct_vader_midir_InstrConst_t*) l1)->f_span;
        vader_midir_push_emit(l0, vader_ref_box(l4), l5);
    } else if (l3.tag == 926u) {
        t2 = l3.payload.obj;
        t1 = ((vader_struct_vader_midir_ConstBool_t*) t2)->f_value;
        vader_struct_vader_bytecode_BoolConst_t* _a3_obj = (vader_struct_vader_bytecode_BoolConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BoolConst_t));
        vader_obj_header_init(_a3_obj, 571u);
        _a3_obj->f_value = t1;
        l4 = (void*) _a3_obj;
        l5 = ((vader_struct_vader_midir_InstrConst_t*) l1)->f_span;
        vader_midir_push_emit(l0, vader_ref_box(l4), l5);
    } else if (l3.tag == 927u) {
        t2 = l3.payload.obj;
        t5 = ((vader_struct_vader_midir_ConstChar_t*) t2)->f_value;
        vader_struct_vader_bytecode_CharConst_t* _a4_obj = (vader_struct_vader_bytecode_CharConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_CharConst_t));
        vader_obj_header_init(_a4_obj, 586u);
        _a4_obj->f_value = ((uint32_t) (int32_t) t5);
        l4 = (void*) _a4_obj;
        l5 = ((vader_struct_vader_midir_InstrConst_t*) l1)->f_span;
        vader_midir_push_emit(l0, vader_ref_box(l4), l5);
    } else if (l3.tag == 930u) {
        vader_struct_vader_bytecode_NullConst_t* _a5_obj = (vader_struct_vader_bytecode_NullConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_NullConst_t));
        vader_obj_header_init(_a5_obj, 669u);
        l4 = (void*) _a5_obj;
        l5 = ((vader_struct_vader_midir_InstrConst_t*) l1)->f_span;
        vader_midir_push_emit(l0, vader_ref_box(l4), l5);
    } else if (l3.tag == 931u) {
        l4 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_string_index_map;
        t2 = l3.payload.obj;
        t5 = ((vader_struct_vader_midir_ConstString_t*) t2)->f_index;
        t3 = ((int64_t) (int32_t) t5);
        l6 = (size_t) (int64_t) t3;
        vader_array_t* _a6_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l6)
        t5 = ((int32_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l6];
        vader_struct_vader_bytecode_StringConst_t* _a7_obj = (vader_struct_vader_bytecode_StringConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_StringConst_t));
        vader_obj_header_init(_a7_obj, 687u);
        _a7_obj->f_index = t5;
        l4 = (void*) _a7_obj;
        l5 = ((vader_struct_vader_midir_InstrConst_t*) l1)->f_span;
        vader_midir_push_emit(l0, vader_ref_box(l4), l5);
    }
    l7 = ((vader_struct_vader_midir_InstrConst_t*) l1)->f_dst;
    l4 = ((vader_struct_vader_midir_InstrConst_t*) l1)->f_span;
    vader_midir_emit_result(l0, l2, l7, l4);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_midir_emit_first_get(void* l0, int64_t l1, int32_t l2, void* l3) {
    bool t0;
    void** gc_raw_roots[2] = { &l0, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = std_collections_MutableSet_Contains_contains__i64(((vader_struct_vader_midir_ScheduleHints_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_hints)->f_skip_first_get, l1);
    if (!(t0)) {
        vader_midir_emit_get(l0, l2, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_midir_emit_get(void* l0, int32_t l1, void* l2) {
    void* l3 = NULL;
    size_t l4;
    int64_t t0;
    int32_t t1;
    void** gc_raw_roots[3] = { &l0, &l2, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_local_to_slot;
    t0 = ((int64_t) (int32_t) l1);
    l4 = (size_t) (int64_t) t0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
    t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l4];
    vader_struct_vader_bytecode_LocalGet_t* _a1_obj = (vader_struct_vader_bytecode_LocalGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_LocalGet_t));
    vader_obj_header_init(_a1_obj, 663u);
    _a1_obj->f_slot = t1;
    l3 = (void*) _a1_obj;
    vader_midir_push_emit(l0, vader_ref_box(l3), l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_midir_emit_instr(void* l0, vader_box_t l1, int64_t l2) {
    void* l3 = NULL;
    void* l12 = NULL;
    void* l14 = NULL;
    void* l16 = NULL;
    int32_t l4, l17;
    size_t l5, l13, l15;
    bool l6, l9;
    vader_box_t l7 = vader_box_null(), l8 = vader_box_null();
    uint8_t l10, l11, l24;
    vader_string_t l18 = 0;
    vader_string_t l20 = 0;
    vader_string_t l21 = 0;
    vader_string_t l22 = 0;
    vader_string_t l23 = 0;
    int64_t l19;
    void* t0 = NULL;
    void* t3 = NULL;
    int64_t t1;
    bool t2;
    size_t t4;
    int32_t t5;
    vader_string_t t6 = 0;
    vader_box_t* gc_roots[3] = { &l1, &l7, &l8 };
    void** gc_raw_roots[7] = { &l0, &l3, &l12, &l14, &l16, &t0, &t3 };
    vader_string_t* gc_atom_roots[6] = { &l18, &l20, &l21, &l22, &l23, &t6 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 6u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l1.tag == 952u) {
        l3 = l1.payload.obj;
        vader_midir_emit_const_instr(l0, l3, l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 962u) {
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrMove_t*) t0)->f_src;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrMove_t*) t0)->f_span;
        vader_midir_emit_first_get(l0, l2, l4, l3);
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrMove_t*) t0)->f_src;
        l3 = ((vader_struct_vader_midir_CFGFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_fn_)->f_locals;
        t0 = l1.payload.obj;
        t1 = ((int64_t) (int32_t) ((vader_struct_vader_midir_InstrMove_t*) t0)->f_dst);
        l5 = (size_t) (int64_t) t1;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
        l6 = vader_midir_is_union_slot(((vader_struct_vader_midir_CFGLocal_t*) t0)->f_type);
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
    if (l1.tag == 945u) {
        l3 = ((vader_struct_vader_midir_CFGFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_fn_)->f_locals;
        t0 = l1.payload.obj;
        t1 = ((int64_t) (int32_t) ((vader_struct_vader_midir_InstrBinOp_t*) t0)->f_lhs);
        l5 = (size_t) (int64_t) t1;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
        t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5);
        l7 = ((vader_struct_vader_midir_CFGLocal_t*) t0)->f_type;
        l3 = ((vader_struct_vader_midir_CFGFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_fn_)->f_locals;
        t0 = l1.payload.obj;
        t1 = ((int64_t) (int32_t) ((vader_struct_vader_midir_InstrBinOp_t*) t0)->f_rhs);
        l5 = (size_t) (int64_t) t1;
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
        t2 = vader_midir_binary_leaves_width(((vader_struct_vader_midir_InstrBinOp_t*) t0)->f_op, l10);
        if (t2) {
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
    if (l1.tag == 946u) {
        l3 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_pinned_types_bucket;
        t0 = l1.payload.obj;
        l12 = ((vader_struct_vader_midir_InstrCall_t*) t0)->f_args;
        l5 = ((vader_array_t*) l12)->length;
        l13 = (size_t) 0;
        while ((l13 < l5)) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l12);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l13)
            l4 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l13];
            l14 = ((vader_struct_vader_midir_CFGFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_fn_)->f_locals;
            t1 = ((int64_t) (int32_t) l4);
            l15 = (size_t) (int64_t) t1;
            vader_array_t* _a4_slotarr = ((vader_array_t*) l14);
            VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l15)
            t0 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l15);
            l7 = ((vader_struct_vader_midir_CFGLocal_t*) t0)->f_type;
            l16 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project;
            l17 = vader_bytecode_intern_type(l7, l16);
            vader_array_push_i32((vader_array_t*) l3, l17);
            t1 = (l13 + INT64_C(1));
            l13 = (size_t) (int64_t) t1;
        }
        t0 = l1.payload.obj;
        l12 = ((vader_struct_vader_midir_InstrCall_t*) t0)->f_dsts;
        l5 = ((vader_array_t*) l12)->length;
        l13 = (size_t) 0;
        while ((l13 < l5)) {
            vader_array_t* _a5_slotarr = ((vader_array_t*) l12);
            VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l13)
            l4 = ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l13];
            l14 = ((vader_struct_vader_midir_CFGFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_fn_)->f_locals;
            t1 = ((int64_t) (int32_t) l4);
            l15 = (size_t) (int64_t) t1;
            vader_array_t* _a6_slotarr = ((vader_array_t*) l14);
            VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l15)
            t0 = vader_array_ref_load_obj(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l15);
            l7 = ((vader_struct_vader_midir_CFGLocal_t*) t0)->f_type;
            l16 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project;
            l17 = vader_bytecode_intern_type(l7, l16);
            vader_array_push_i32((vader_array_t*) l3, l17);
            t1 = (l13 + INT64_C(1));
            l13 = (size_t) (int64_t) t1;
        }
        l3 = l1.payload.obj;
        l3 = vader_midir_resolve_direct_call(l0, l3);
        l12 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project;
        l14 = ((vader_struct_vader_midir_DirectCallTarget_t*) l3)->f_signature;
        l12 = vader_midir_union_params_of(l12, l14);
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
    if (l1.tag == 967u) {
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrUnOp_t*) t0)->f_operand;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrUnOp_t*) t0)->f_span;
        vader_midir_emit_first_get(l0, l2, l4, l3);
        l3 = ((vader_struct_vader_midir_CFGFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_fn_)->f_locals;
        t0 = l1.payload.obj;
        t1 = ((int64_t) (int32_t) ((vader_struct_vader_midir_InstrUnOp_t*) t0)->f_operand);
        l5 = (size_t) (int64_t) t1;
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
        t2 = vader_midir_unary_leaves_width(((vader_struct_vader_midir_InstrUnOp_t*) t0)->f_op, l10);
        if (t2) {
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
    if (l1.tag == 947u) {
        t0 = l1.payload.obj;
        t3 = vader_lower_param_types_of(((vader_struct_vader_midir_InstrCallIndirect_t*) t0)->f_fn_type);
        l3 = vader_midir_union_slots_of(t3);
        t0 = l1.payload.obj;
        l12 = ((vader_struct_vader_midir_InstrCallIndirect_t*) t0)->f_args;
        t0 = l1.payload.obj;
        l14 = ((vader_struct_vader_midir_InstrCallIndirect_t*) t0)->f_span;
        vader_midir_emit_operands_into(l0, l2, l12, l3, l14);
        t0 = l1.payload.obj;
        t4 = ((vader_array_t*) ((vader_struct_vader_midir_InstrCallIndirect_t*) t0)->f_args)->length;
        if (t4 == INT64_C(0)) {
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
        t5 = vader_bytecode_intern_type(l7, l3);
        vader_struct_vader_bytecode_CallIndirect_t* _a8_obj = (vader_struct_vader_bytecode_CallIndirect_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_CallIndirect_t));
        vader_obj_header_init(_a8_obj, 585u);
        _a8_obj->f_type_id = t5;
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
    if (l1.tag == 959u) {
        l3 = ((vader_struct_vader_bytecode_EmitterCtx_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project)->f_function_index_by_symbol_id;
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_midir_InstrFnRef_t*) t0)->f_fn_symbol)->f_id;
        l7 = std_collections_MutableMap_Index_at__i32__i32(l3, l4);
        if (!(l7.tag == 246u)) {
            t0 = l1.payload.obj;
            l18 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_midir_InstrFnRef_t*) t0)->f_fn_symbol)->f_name;
            l5 = vader_host_std_core_byte_len(l18);
            l14 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(104) + l5));
            l5 = (size_t) 0;
            l5 = std_core_write_string_at(l14, l5, 1987u);
            l5 = std_core_write_string_at(l14, l5, l18);
            l5 = std_core_write_string_at(l14, l5, 214u);
            t0 = l1.payload.obj;
            t5 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_midir_InstrFnRef_t*) t0)->f_fn_symbol)->f_id;
            l19 = ((int64_t) (int32_t) t5);
            l5 = std_core_write_int(l14, l5, l19);
            l5 = std_core_write_string_at(l14, l5, 259u);
            t6 = std_core_finish_buffer(l14, l5);
            vader_host_std_abort_panic(t6);
            vader_unreachable("a no-return call returned");
        }
        t0 = l1.payload.obj;
        l8 = ((vader_struct_vader_midir_InstrFnRef_t*) t0)->f_type;
        l3 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project;
        l4 = vader_bytecode_intern_type(l8, l3);
        t5 = ((int32_t) l7.payload.i);
        vader_struct_vader_bytecode_FnRef_t* _a9_obj = (vader_struct_vader_bytecode_FnRef_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_FnRef_t));
        vader_obj_header_init(_a9_obj, 612u);
        _a9_obj->f_function_index = t5;
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
    if (l1.tag == 958u) {
        l3 = ((vader_struct_vader_bytecode_EmitterCtx_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project)->f_function_index_by_symbol_id;
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_midir_InstrFnAddr_t*) t0)->f_fn_symbol)->f_id;
        l7 = std_collections_MutableMap_Index_at__i32__i32(l3, l4);
        if (!(l7.tag == 246u)) {
            t0 = l1.payload.obj;
            l18 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_midir_InstrFnAddr_t*) t0)->f_fn_symbol)->f_name;
            l5 = vader_host_std_core_byte_len(l18);
            l14 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(102) + l5));
            l5 = (size_t) 0;
            l5 = std_core_write_string_at(l14, l5, 1986u);
            l5 = std_core_write_string_at(l14, l5, l18);
            l5 = std_core_write_string_at(l14, l5, 214u);
            t0 = l1.payload.obj;
            t5 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_midir_InstrFnAddr_t*) t0)->f_fn_symbol)->f_id;
            l19 = ((int64_t) (int32_t) t5);
            l5 = std_core_write_int(l14, l5, l19);
            l5 = std_core_write_string_at(l14, l5, 258u);
            t6 = std_core_finish_buffer(l14, l5);
            vader_host_std_abort_panic(t6);
            vader_unreachable("a no-return call returned");
        }
        t5 = ((int32_t) l7.payload.i);
        vader_struct_vader_bytecode_FnAddr_t* _a10_obj = (vader_struct_vader_bytecode_FnAddr_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_FnAddr_t));
        vader_obj_header_init(_a10_obj, 611u);
        _a10_obj->f_function_index = t5;
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
    if (l1.tag == 968u) {
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrVirtualCall_t*) t0)->f_args;
        t0 = l1.payload.obj;
        l12 = vader_midir_union_slots_of(((vader_struct_vader_midir_InstrVirtualCall_t*) t0)->f_param_types);
        t0 = l1.payload.obj;
        l14 = ((vader_struct_vader_midir_InstrVirtualCall_t*) t0)->f_span;
        vader_midir_emit_operands_into(l0, l2, l3, l12, l14);
        t0 = l1.payload.obj;
        t4 = ((vader_array_t*) ((vader_struct_vader_midir_InstrVirtualCall_t*) t0)->f_args)->length;
        if (t4 == INT64_C(0)) {
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
        t4 = ((vader_array_t*) ((vader_struct_vader_midir_InstrVirtualCall_t*) t0)->f_args)->length;
        l4 = ((int32_t) (int64_t) (t4 + INT64_C(1)));
        t0 = l1.payload.obj;
        l18 = ((vader_struct_vader_midir_InstrVirtualCall_t*) t0)->f_trait_name;
        t0 = l1.payload.obj;
        l20 = ((vader_struct_vader_midir_InstrVirtualCall_t*) t0)->f_method;
        l18 = concat_3(l18, 308u, l20);
        vader_struct_vader_bytecode_VirtualCall_t* _a11_obj = (vader_struct_vader_bytecode_VirtualCall_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_VirtualCall_t));
        vader_obj_header_init(_a11_obj, 709u);
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
    if (l1.tag == 956u) {
        l3 = ((vader_struct_vader_midir_CFGFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_fn_)->f_locals;
        t0 = l1.payload.obj;
        t1 = ((int64_t) (int32_t) ((vader_struct_vader_midir_InstrFieldGet_t*) t0)->f_target);
        l5 = (size_t) (int64_t) t1;
        vader_array_t* _a12_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a12_slotarr, l5)
        l3 = vader_array_ref_load_obj(_a12_slotarr->buf, _a12_slotarr->offset + (size_t) l5);
        l7 = ((vader_struct_vader_midir_CFGLocal_t*) l3)->f_type;
        l12 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project;
        l4 = vader_bytecode_intern_type(l7, l12);
        l6 = std_collections_MutableSet_Contains_contains__i64(((vader_struct_vader_midir_ScheduleHints_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_hints)->f_skip_first_get, l2);
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
            l20 = vader_types_display_type(l7);
            t0 = l1.payload.obj;
            l21 = vader_vt_std_core_Display__to_string(vader_box_i32(246u, ((vader_struct_vader_midir_InstrFieldGet_t*) t0)->f_target));
            l22 = ((vader_struct_vader_midir_CFGLocal_t*) l3)->f_name;
            l23 = ((vader_struct_vader_midir_CFGFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_fn_)->f_mangled;
            t6 = concat_11(1981u, l18, 993u, l20, 864u, l21, 48u, l22, 1057u, l23, 225u);
            vader_host_std_abort_panic(t6);
            vader_unreachable("a no-return call returned");
        } else {
            t4 = ((size_t) l8.payload.i);
            l17 = ((int32_t) (size_t) t4);
            l9 = false;
            if (!(l6)) {
                l9 = vader_midir_try_fuse_local_field(l0, l4, l17);
            }
            if (!(l9)) {
                vader_struct_vader_bytecode_StructGet_t* _a13_obj = (vader_struct_vader_bytecode_StructGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_StructGet_t));
                vader_obj_header_init(_a13_obj, 691u);
                _a13_obj->f_type_id = l4;
                _a13_obj->f_field_index = l17;
                l3 = (void*) _a13_obj;
                t0 = l1.payload.obj;
                l12 = ((vader_struct_vader_midir_InstrFieldGet_t*) t0)->f_span;
                vader_midir_push_emit(l0, vader_ref_box(l3), l12);
            }
            t0 = l1.payload.obj;
            t2 = vader_midir_needs_ref_cast(((vader_struct_vader_midir_InstrFieldGet_t*) t0)->f_type);
            if (t2) {
                t0 = l1.payload.obj;
                l7 = ((vader_struct_vader_midir_InstrFieldGet_t*) t0)->f_type;
                l3 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project;
                t5 = vader_bytecode_intern_type(l7, l3);
                vader_struct_vader_bytecode_RefCast_t* _a14_obj = (vader_struct_vader_bytecode_RefCast_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_RefCast_t));
                vader_obj_header_init(_a14_obj, 671u);
                _a14_obj->f_type_id = t5;
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
    } else if (l1.tag == 957u) {
        l3 = ((vader_struct_vader_midir_CFGFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_fn_)->f_locals;
        t0 = l1.payload.obj;
        t1 = ((int64_t) (int32_t) ((vader_struct_vader_midir_InstrFieldSet_t*) t0)->f_target);
        l5 = (size_t) (int64_t) t1;
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
            l5 = ((size_t) l8.payload.i);
            l6 = vader_midir_union_field(l3, l4, l5);
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir_InstrFieldSet_t*) t0)->f_span;
            vader_midir_emit_retag_into(l0, l17, l6, l3);
            t4 = ((size_t) l8.payload.i);
            l17 = ((int32_t) (size_t) t4);
            t0 = l1.payload.obj;
            l6 = ((vader_struct_vader_midir_InstrFieldSet_t*) t0)->f_barrierless;
            vader_struct_vader_bytecode_StructSet_t* _a16_obj = (vader_struct_vader_bytecode_StructSet_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_StructSet_t));
            vader_obj_header_init(_a16_obj, 693u);
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
        l20 = vader_types_display_type(l7);
        l21 = ((vader_struct_vader_midir_CFGFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_fn_)->f_mangled;
        t6 = concat_7(1981u, l18, 993u, l20, 924u, l21, 227u);
        vader_host_std_abort_panic(t6);
        vader_unreachable("a no-return call returned");
    } else {
        if (l1.tag == 939u) {
            l3 = ((vader_struct_vader_midir_CFGFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_fn_)->f_locals;
            t0 = l1.payload.obj;
            t1 = ((int64_t) (int32_t) ((vader_struct_vader_midir_InstrArrayGet_t*) t0)->f_target);
            l5 = (size_t) (int64_t) t1;
            vader_array_t* _a17_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a17_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a17_slotarr, l5)
            t0 = vader_array_ref_load_obj(_a17_slotarr->buf, _a17_slotarr->offset + (size_t) l5);
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
                vader_struct_vader_bytecode_ArrayGet_t* _a18_obj = (vader_struct_vader_bytecode_ArrayGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_ArrayGet_t));
                vader_obj_header_init(_a18_obj, 538u);
                _a18_obj->f_type_id = l4;
                _a18_obj->f_bounds_safe = l6;
                l3 = (void*) _a18_obj;
                t0 = l1.payload.obj;
                l12 = ((vader_struct_vader_midir_InstrArrayGet_t*) t0)->f_span;
                vader_midir_push_emit(l0, vader_ref_box(l3), l12);
                t0 = l1.payload.obj;
                t2 = vader_midir_needs_ref_cast(((vader_struct_vader_midir_InstrArrayGet_t*) t0)->f_type);
                if (t2) {
                    t0 = l1.payload.obj;
                    l8 = ((vader_struct_vader_midir_InstrArrayGet_t*) t0)->f_type;
                    l3 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project;
                    t5 = vader_bytecode_intern_type(l8, l3);
                    vader_struct_vader_bytecode_RefCast_t* _a19_obj = (vader_struct_vader_bytecode_RefCast_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_RefCast_t));
                    vader_obj_header_init(_a19_obj, 671u);
                    _a19_obj->f_type_id = t5;
                    l3 = (void*) _a19_obj;
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
        if (l1.tag == 943u) {
            l3 = ((vader_struct_vader_midir_CFGFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_fn_)->f_locals;
            t0 = l1.payload.obj;
            t1 = ((int64_t) (int32_t) ((vader_struct_vader_midir_InstrArraySet_t*) t0)->f_target);
            l5 = (size_t) (int64_t) t1;
            vader_array_t* _a20_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a20_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a20_slotarr, l5)
            t0 = vader_array_ref_load_obj(_a20_slotarr->buf, _a20_slotarr->offset + (size_t) l5);
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
            l6 = vader_midir_union_element(l7);
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
                vader_struct_vader_bytecode_ArraySet_t* _a21_obj = (vader_struct_vader_bytecode_ArraySet_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_ArraySet_t));
                vader_obj_header_init(_a21_obj, 545u);
                _a21_obj->f_type_id = l4;
                _a21_obj->f_bounds_safe = l6;
                l3 = (void*) _a21_obj;
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
        if (l1.tag == 940u) {
            t0 = l1.payload.obj;
            l4 = ((vader_struct_vader_midir_InstrArrayLen_t*) t0)->f_target;
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir_InstrArrayLen_t*) t0)->f_span;
            vader_midir_emit_first_get(l0, l2, l4, l3);
            vader_struct_vader_bytecode_ArrayLen_t* _a22_obj = (vader_struct_vader_bytecode_ArrayLen_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_ArrayLen_t));
            vader_obj_header_init(_a22_obj, 539u);
            l3 = (void*) _a22_obj;
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
        if (l1.tag == 942u) {
            l3 = ((vader_struct_vader_midir_CFGFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_fn_)->f_locals;
            t0 = l1.payload.obj;
            t1 = ((int64_t) (int32_t) ((vader_struct_vader_midir_InstrArrayPush_t*) t0)->f_target);
            l5 = (size_t) (int64_t) t1;
            vader_array_t* _a23_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a23_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a23_slotarr, l5)
            t0 = vader_array_ref_load_obj(_a23_slotarr->buf, _a23_slotarr->offset + (size_t) l5);
            l7 = ((vader_struct_vader_midir_CFGLocal_t*) t0)->f_type;
            l3 = ((vader_struct_vader_midir_CFGFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_fn_)->f_locals;
            t0 = l1.payload.obj;
            t1 = ((int64_t) (int32_t) ((vader_struct_vader_midir_InstrArrayPush_t*) t0)->f_value);
            l5 = (size_t) (int64_t) t1;
            vader_array_t* _a24_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a24_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a24_slotarr, l5)
            t0 = vader_array_ref_load_obj(_a24_slotarr->buf, _a24_slotarr->offset + (size_t) l5);
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
            l6 = vader_midir_is_union_slot(l7);
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir_InstrArrayPush_t*) t0)->f_span;
            vader_midir_emit_retag_into(l0, l4, l6, l3);
            t0 = l1.payload.obj;
            t2 = ((vader_struct_vader_midir_InstrArrayPush_t*) t0)->f_cached;
            if (t2) {
                l3 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_local_to_slot;
                t0 = l1.payload.obj;
                t1 = ((int64_t) (int32_t) ((vader_struct_vader_midir_InstrArrayPush_t*) t0)->f_target);
                l5 = (size_t) (int64_t) t1;
                vader_array_t* _a25_slotarr = ((vader_array_t*) l3);
                VADER_ARRAY_RESOLVE_BUF(_a25_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a25_slotarr, l5)
                l4 = ((int32_t*) _a25_slotarr->buf->slots)[_a25_slotarr->offset + (size_t) l5];
            } else {
                l4 = -(INT32_C(1));
            }
            l3 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project;
            t5 = vader_bytecode_intern_type(l7, l3);
            vader_struct_vader_bytecode_ArrayPush_t* _a26_obj = (vader_struct_vader_bytecode_ArrayPush_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_ArrayPush_t));
            vader_obj_header_init(_a26_obj, 541u);
            _a26_obj->f_type_id = t5;
            _a26_obj->f_cache_slot = l4;
            l3 = (void*) _a26_obj;
            t0 = l1.payload.obj;
            l12 = ((vader_struct_vader_midir_InstrArrayPush_t*) t0)->f_span;
            vader_midir_push_emit(l0, vader_ref_box(l3), l12);
            { vader_gc_top = gc_frame.prev; return; }
        }
        if (l1.tag == 944u) {
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
            vader_struct_vader_bytecode_ArraySlice_t* _a27_obj = (vader_struct_vader_bytecode_ArraySlice_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_ArraySlice_t));
            vader_obj_header_init(_a27_obj, 546u);
            _a27_obj->f_type_id = l4;
            l3 = (void*) _a27_obj;
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
        if (l1.tag == 963u) {
            t0 = l1.payload.obj;
            l4 = ((vader_struct_vader_midir_InstrStringSlice_t*) t0)->f_target;
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir_InstrStringSlice_t*) t0)->f_span;
            vader_midir_emit_first_get(l0, l2, l4, l3);
            t0 = l1.payload.obj;
            l4 = ((vader_struct_vader_midir_InstrStringSlice_t*) t0)->f_lo;
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir_InstrStringSlice_t*) t0)->f_span;
            vader_midir_emit_get(l0, l4, l3);
            t0 = l1.payload.obj;
            l4 = ((vader_struct_vader_midir_InstrStringSlice_t*) t0)->f_hi;
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir_InstrStringSlice_t*) t0)->f_span;
            vader_midir_emit_get(l0, l4, l3);
            vader_struct_vader_bytecode_StringSliceCodepoints_t* _a28_obj = (vader_struct_vader_bytecode_StringSliceCodepoints_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_StringSliceCodepoints_t));
            vader_obj_header_init(_a28_obj, 690u);
            l3 = (void*) _a28_obj;
            t0 = l1.payload.obj;
            l12 = ((vader_struct_vader_midir_InstrStringSlice_t*) t0)->f_span;
            vader_midir_push_emit(l0, vader_ref_box(l3), l12);
            t0 = l1.payload.obj;
            l4 = ((vader_struct_vader_midir_InstrStringSlice_t*) t0)->f_dst;
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir_InstrStringSlice_t*) t0)->f_span;
            vader_midir_emit_result(l0, l2, l4, l3);
            { vader_gc_top = gc_frame.prev; return; }
        }
        if (l1.tag == 964u) {
            t0 = l1.payload.obj;
            l7 = ((vader_struct_vader_midir_InstrStructNew_t*) t0)->f_type;
            l3 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project;
            l4 = vader_bytecode_intern_type(l7, l3);
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir_InstrStructNew_t*) t0)->f_fields;
            l12 = vader_midir_union_fields_of(((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project, l4);
            t0 = l1.payload.obj;
            l14 = ((vader_struct_vader_midir_InstrStructNew_t*) t0)->f_span;
            vader_midir_emit_operands_into(l0, l2, l3, l12, l14);
            t0 = l1.payload.obj;
            l6 = ((vader_struct_vader_midir_InstrStructNew_t*) t0)->f_stack;
            vader_struct_vader_bytecode_StructNew_t* _a29_obj = (vader_struct_vader_bytecode_StructNew_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_StructNew_t));
            vader_obj_header_init(_a29_obj, 692u);
            _a29_obj->f_type_id = l4;
            _a29_obj->f_stack = l6;
            l3 = (void*) _a29_obj;
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
        if (l1.tag == 941u) {
            t0 = l1.payload.obj;
            l7 = ((vader_struct_vader_midir_InstrArrayNew_t*) t0)->f_type;
            l3 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project;
            l4 = vader_bytecode_intern_type(l7, l3);
            t0 = l1.payload.obj;
            t2 = vader_midir_union_element(((vader_struct_vader_midir_InstrArrayNew_t*) t0)->f_type);
            vader_array_t* _a30_arr = vader_array_new(11u, 1u, 12u, 241u);
            ((uint8_t*) _a30_arr->buf->slots)[_a30_arr->offset + 0u] = (uint8_t) t2;
            l3 = (void*) _a30_arr;
            t0 = l1.payload.obj;
            l5 = ((vader_array_t*) ((vader_struct_vader_midir_InstrArrayNew_t*) t0)->f_elements)->length;
            vader_array_t* _a31_arr = vader_array_repeat((vader_array_t*) l3, (size_t) l5);
            l3 = (void*) _a31_arr;
            t0 = l1.payload.obj;
            l12 = ((vader_struct_vader_midir_InstrArrayNew_t*) t0)->f_elements;
            t0 = l1.payload.obj;
            l14 = ((vader_struct_vader_midir_InstrArrayNew_t*) t0)->f_span;
            vader_midir_emit_operands_into(l0, l2, l12, l3, l14);
            t0 = l1.payload.obj;
            l17 = ((vader_struct_vader_midir_InstrArrayNew_t*) t0)->f_length;
            vader_struct_vader_bytecode_ArrayNew_t* _a32_obj = (vader_struct_vader_bytecode_ArrayNew_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_ArrayNew_t));
            vader_obj_header_init(_a32_obj, 540u);
            _a32_obj->f_type_id = l4;
            _a32_obj->f_length = l17;
            l3 = (void*) _a32_obj;
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
        if (l1.tag == 953u) {
            t0 = l1.payload.obj;
            l7 = ((vader_struct_vader_midir_InstrDataConst_t*) t0)->f_type;
            l3 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project;
            l4 = vader_bytecode_intern_type(l7, l3);
            t0 = l1.payload.obj;
            t5 = ((vader_struct_vader_midir_InstrDataConst_t*) t0)->f_pool_index;
            vader_struct_vader_bytecode_DataConst_t* _a33_obj = (vader_struct_vader_bytecode_DataConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_DataConst_t));
            vader_obj_header_init(_a33_obj, 588u);
            _a33_obj->f_pool_index = t5;
            _a33_obj->f_type_id = l4;
            l3 = (void*) _a33_obj;
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
        if (l1.tag == 965u) {
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
            t5 = vader_bytecode_intern_type(l7, l3);
            vader_struct_vader_bytecode_TypeCheck_t* _a34_obj = (vader_struct_vader_bytecode_TypeCheck_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_TypeCheck_t));
            vader_obj_header_init(_a34_obj, 694u);
            _a34_obj->f_type_id = t5;
            l3 = (void*) _a34_obj;
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
        if (l1.tag == 966u) {
            t0 = l1.payload.obj;
            l7 = ((vader_struct_vader_midir_InstrTypeConst_t*) t0)->f_value_type;
            l3 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project;
            t5 = vader_bytecode_intern_type(l7, l3);
            vader_struct_vader_bytecode_TypeConst_t* _a35_obj = (vader_struct_vader_bytecode_TypeConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_TypeConst_t));
            vader_obj_header_init(_a35_obj, 695u);
            _a35_obj->f_type_id = t5;
            l3 = (void*) _a35_obj;
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
        if (l1.tag == 948u) {
            t0 = l1.payload.obj;
            l4 = ((vader_struct_vader_midir_InstrCast_t*) t0)->f_value;
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir_InstrCast_t*) t0)->f_span;
            vader_midir_emit_first_get(l0, l2, l4, l3);
            l3 = ((vader_struct_vader_midir_CFGFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_fn_)->f_locals;
            t0 = l1.payload.obj;
            t1 = ((int64_t) (int32_t) ((vader_struct_vader_midir_InstrCast_t*) t0)->f_value);
            l5 = (size_t) (int64_t) t1;
            vader_array_t* _a36_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a36_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a36_slotarr, l5)
            t0 = vader_array_ref_load_obj(_a36_slotarr->buf, _a36_slotarr->offset + (size_t) l5);
            l7 = ((vader_struct_vader_midir_CFGLocal_t*) t0)->f_type;
            l10 = vader_bytecode_val_type_of_type(l7);
            t0 = l1.payload.obj;
            l11 = vader_bytecode_val_type_of_type(((vader_struct_vader_midir_InstrCast_t*) t0)->f_type);
            t0 = l1.payload.obj;
            t2 = vader_midir_is_union_slot(((vader_struct_vader_midir_InstrCast_t*) t0)->f_type);
            if (t2) {
                l6 = vader_midir_is_scalar_class(l10);
            } else {
                l6 = false;
            }
            if (l6) {
                l3 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project;
                t5 = vader_bytecode_intern_type(l7, l3);
                vader_struct_vader_bytecode_Retag_t* _a37_obj = (vader_struct_vader_bytecode_Retag_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_Retag_t));
                vader_obj_header_init(_a37_obj, 674u);
                _a37_obj->f_type_id = t5;
                l3 = (void*) _a37_obj;
                t0 = l1.payload.obj;
                l12 = ((vader_struct_vader_midir_InstrCast_t*) t0)->f_span;
                vader_midir_push_emit(l0, vader_ref_box(l3), l12);
            } else if (l10 != l11) {
                l7 = vader_bytecode_convert_target_of(l11);
                if (l7.tag == 0u) {
                    t0 = l1.payload.obj;
                    l8 = ((vader_struct_vader_midir_InstrCast_t*) t0)->f_type;
                    l3 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project;
                    t5 = vader_bytecode_intern_type(l8, l3);
                    vader_struct_vader_bytecode_RefCast_t* _a38_obj = (vader_struct_vader_bytecode_RefCast_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_RefCast_t));
                    vader_obj_header_init(_a38_obj, 671u);
                    _a38_obj->f_type_id = t5;
                    l3 = (void*) _a38_obj;
                    t0 = l1.payload.obj;
                    l12 = ((vader_struct_vader_midir_InstrCast_t*) t0)->f_span;
                    vader_midir_push_emit(l0, vader_ref_box(l3), l12);
                } else {
                    t2 = vader_midir_convert_eligible(l10);
                    if (t2) {
                        l18 = vader_bytecode_val_type_name(l10);
                        l24 = ((uint8_t) l7.payload.i);
                        vader_struct_vader_bytecode_Convert_t* _a39_obj = (vader_struct_vader_bytecode_Convert_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_Convert_t));
                        vader_obj_header_init(_a39_obj, 587u);
                        _a39_obj->f_from_name = l18;
                        _a39_obj->f_target = l24;
                        l3 = (void*) _a39_obj;
                        t0 = l1.payload.obj;
                        l12 = ((vader_struct_vader_midir_InstrCast_t*) t0)->f_span;
                        vader_midir_push_emit(l0, vader_ref_box(l3), l12);
                        t2 = vader_midir_fits_in(l10, l11);
                        if (!(t2)) {
                            t0 = l1.payload.obj;
                            l3 = ((vader_struct_vader_midir_InstrCast_t*) t0)->f_span;
                            vader_midir_emit_narrowing(l0, l11, l3);
                        }
                    } else {
                        t0 = l1.payload.obj;
                        l7 = ((vader_struct_vader_midir_InstrCast_t*) t0)->f_type;
                        l3 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project;
                        t5 = vader_bytecode_intern_type(l7, l3);
                        vader_struct_vader_bytecode_RefCast_t* _a40_obj = (vader_struct_vader_bytecode_RefCast_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_RefCast_t));
                        vader_obj_header_init(_a40_obj, 671u);
                        _a40_obj->f_type_id = t5;
                        l3 = (void*) _a40_obj;
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
        if (l1.tag == 950u) {
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
            l6 = vader_midir_is_union_slot(((vader_struct_vader_midir_InstrCellNew_t*) t0)->f_value_type);
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir_InstrCellNew_t*) t0)->f_span;
            vader_midir_emit_retag_into(l0, l17, l6, l3);
            vader_struct_vader_bytecode_StructNew_t* _a41_obj = (vader_struct_vader_bytecode_StructNew_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_StructNew_t));
            vader_obj_header_init(_a41_obj, 692u);
            _a41_obj->f_type_id = l4;
            _a41_obj->f_stack = false;
            l3 = (void*) _a41_obj;
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
        if (l1.tag == 949u) {
            t0 = l1.payload.obj;
            l7 = ((vader_struct_vader_midir_InstrCellGet_t*) t0)->f_value_type;
            l3 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project;
            l4 = vader_bytecode_intern_cell_type(l7, l3);
            l6 = std_collections_MutableSet_Contains_contains__i64(((vader_struct_vader_midir_ScheduleHints_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_hints)->f_skip_first_get, l2);
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
                vader_struct_vader_bytecode_StructGet_t* _a42_obj = (vader_struct_vader_bytecode_StructGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_StructGet_t));
                vader_obj_header_init(_a42_obj, 691u);
                _a42_obj->f_type_id = l4;
                _a42_obj->f_field_index = INT32_C(0);
                l3 = (void*) _a42_obj;
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
        if (l1.tag == 951u) {
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
            l6 = vader_midir_is_union_slot(((vader_struct_vader_midir_InstrCellSet_t*) t0)->f_value_type);
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir_InstrCellSet_t*) t0)->f_span;
            vader_midir_emit_retag_into(l0, l17, l6, l3);
            vader_struct_vader_bytecode_StructSet_t* _a43_obj = (vader_struct_vader_bytecode_StructSet_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_StructSet_t));
            vader_obj_header_init(_a43_obj, 693u);
            _a43_obj->f_type_id = l4;
            _a43_obj->f_field_index = INT32_C(0);
            _a43_obj->f_stack = false;
            l3 = (void*) _a43_obj;
            t0 = l1.payload.obj;
            l12 = ((vader_struct_vader_midir_InstrCellSet_t*) t0)->f_span;
            vader_midir_push_emit(l0, vader_ref_box(l3), l12);
            { vader_gc_top = gc_frame.prev; return; }
        }
        if (l1.tag == 961u) {
            t0 = l1.payload.obj;
            l4 = ((vader_struct_vader_midir_InstrMakeClosure_t*) t0)->f_env;
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir_InstrMakeClosure_t*) t0)->f_span;
            vader_midir_emit_first_get(l0, l2, l4, l3);
            t0 = l1.payload.obj;
            l7 = vader_midir_closure_header_type(((vader_struct_vader_midir_InstrMakeClosure_t*) t0)->f_type);
            l3 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project;
            l4 = vader_bytecode_intern_type(l7, l3);
            l3 = ((vader_struct_vader_bytecode_EmitterCtx_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project)->f_function_index_by_symbol_id;
            t0 = l1.payload.obj;
            l17 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_midir_InstrMakeClosure_t*) t0)->f_fn_symbol)->f_id;
            l7 = std_collections_MutableMap_Index_at__i32__i32(l3, l17);
            if (!(l7.tag == 246u)) {
                t0 = l1.payload.obj;
                l18 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_midir_InstrMakeClosure_t*) t0)->f_fn_symbol)->f_name;
                l5 = vader_host_std_core_byte_len(l18);
                l14 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(109) + l5));
                l5 = (size_t) 0;
                l5 = std_core_write_string_at(l14, l5, 1985u);
                l5 = std_core_write_string_at(l14, l5, l18);
                l5 = std_core_write_string_at(l14, l5, 214u);
                t0 = l1.payload.obj;
                t5 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_midir_InstrMakeClosure_t*) t0)->f_fn_symbol)->f_id;
                l19 = ((int64_t) (int32_t) t5);
                l5 = std_core_write_int(l14, l5, l19);
                l5 = std_core_write_string_at(l14, l5, 260u);
                t6 = std_core_finish_buffer(l14, l5);
                vader_host_std_abort_panic(t6);
                vader_unreachable("a no-return call returned");
            }
            t5 = ((int32_t) l7.payload.i);
            vader_struct_vader_bytecode_MakeClosure_t* _a44_obj = (vader_struct_vader_bytecode_MakeClosure_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_MakeClosure_t));
            vader_obj_header_init(_a44_obj, 667u);
            _a44_obj->f_function_index = t5;
            _a44_obj->f_env_type_id = l4;
            l3 = (void*) _a44_obj;
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
        if (l1.tag == 960u) {
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir_InstrIntrinsic_t*) t0)->f_args;
            vader_array_t* _a45_arr = vader_array_new(11u, 0u, 12u, 241u);
            l12 = (void*) _a45_arr;
            t0 = l1.payload.obj;
            l14 = ((vader_struct_vader_midir_InstrIntrinsic_t*) t0)->f_span;
            vader_midir_emit_operands_into(l0, l2, l3, l12, l14);
            t0 = l1.payload.obj;
            t6 = ((vader_struct_vader_midir_InstrIntrinsic_t*) t0)->f_name;
            l7 = vader_midir_intrinsic_op_for_name(t6);
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
            l20 = ((vader_struct_vader_midir_CFGFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_fn_)->f_mangled;
            t6 = concat_5(1983u, l18, 924u, l20, 229u);
            vader_host_std_abort_panic(t6);
            vader_unreachable("a no-return call returned");
        } else {
            if (l1.tag == 955u) {
                t0 = l1.payload.obj;
                l4 = ((vader_struct_vader_midir_InstrDeferPush_t*) t0)->f_value;
                t0 = l1.payload.obj;
                l3 = ((vader_struct_vader_midir_InstrDeferPush_t*) t0)->f_span;
                vader_midir_emit_first_get(l0, l2, l4, l3);
                vader_struct_vader_bytecode_DeferPush_t* _a46_obj = (vader_struct_vader_bytecode_DeferPush_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_DeferPush_t));
                vader_obj_header_init(_a46_obj, 591u);
                l3 = (void*) _a46_obj;
                t0 = l1.payload.obj;
                l12 = ((vader_struct_vader_midir_InstrDeferPush_t*) t0)->f_span;
                vader_midir_push_emit(l0, vader_ref_box(l3), l12);
                { vader_gc_top = gc_frame.prev; return; }
            }
            if (!(l1.tag == 954u)) {
                vader_host_std_abort_panic(1982u);
                vader_unreachable("a no-return call returned");
            }
            t0 = l1.payload.obj;
            t5 = ((vader_struct_vader_midir_InstrDeferPopExec_t*) t0)->f_count;
            vader_struct_vader_bytecode_DeferPopExec_t* _a47_obj = (vader_struct_vader_bytecode_DeferPopExec_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_DeferPopExec_t));
            vader_obj_header_init(_a47_obj, 590u);
            _a47_obj->f_count = t5;
            l3 = (void*) _a47_obj;
            t0 = l1.payload.obj;
            l12 = ((vader_struct_vader_midir_InstrDeferPopExec_t*) t0)->f_span;
            vader_midir_push_emit(l0, vader_ref_box(l3), l12);
            { vader_gc_top = gc_frame.prev; return; }
        }
    }
    vader_gc_top = gc_frame.prev;
}

static void vader_midir_emit_instructions(void* l0, int32_t l1, size_t l2, size_t l3) {
    void* l4 = NULL;
    int32_t l5;
    size_t l6;
    vader_box_t l7 = vader_box_null();
    int64_t l8;
    int64_t t0;
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
        t0 = (l6 + INT64_C(1));
        l6 = (size_t) (int64_t) t0;
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_midir_emit_loop(void* l0, void* l1, int32_t l2, int32_t l3) {
    void* l4 = NULL;
    void* l6 = NULL;
    void* l8 = NULL;
    int32_t l5, l7, l9;
    void* t0 = NULL;
    size_t t1;
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
        l7 = -(INT32_C(1));
    }
    vader_midir_cf_loop(l0, l6, l2);
    l9 = -(INT32_C(1));
    vader_midir_emit_body(l0, l1, l2, l9, l7);
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
    if (l1 == INT32_C(5)) {
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
    vader_obj_header_init(_a0_obj, 618u);
    _a0_obj->f_value = l4;
    l5 = (void*) _a0_obj;
    vader_midir_push_emit(l0, vader_ref_box(l5), l2);
    vader_struct_vader_bytecode_I32BitAnd_t* _a1_obj = (vader_struct_vader_bytecode_I32BitAnd_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32BitAnd_t));
    vader_obj_header_init(_a1_obj, 614u);
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
    vader_obj_header_init(_a2_obj, 618u);
    _a2_obj->f_value = l4;
    l5 = (void*) _a2_obj;
    vader_midir_push_emit(l0, vader_ref_box(l5), l2);
    vader_struct_vader_bytecode_I32BitXor_t* _a3_obj = (vader_struct_vader_bytecode_I32BitXor_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32BitXor_t));
    vader_obj_header_init(_a3_obj, 617u);
    l5 = (void*) _a3_obj;
    vader_midir_push_emit(l0, vader_ref_box(l5), l2);
    vader_struct_vader_bytecode_I32Const_t* _a4_obj = (vader_struct_vader_bytecode_I32Const_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32Const_t));
    vader_obj_header_init(_a4_obj, 618u);
    _a4_obj->f_value = l4;
    l5 = (void*) _a4_obj;
    vader_midir_push_emit(l0, vader_ref_box(l5), l2);
    vader_struct_vader_bytecode_I32Sub_t* _a5_obj = (vader_struct_vader_bytecode_I32Sub_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32Sub_t));
    vader_obj_header_init(_a5_obj, 632u);
    l5 = (void*) _a5_obj;
    vader_midir_push_emit(l0, vader_ref_box(l5), l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_midir_emit_operands_into(void* l0, int64_t l1, void* l2, void* l3, void* l4) {
    size_t l5, l6, l10;
    int32_t l7, l8, l9;
    bool l11;
    vader_box_t t0 = vader_box_null();
    int64_t t1;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[4] = { &l0, &l2, &l3, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l5 = (size_t) 0;
    l6 = ((vader_array_t*) l2)->length;
    while ((l5 < l6)) {
        if (l5 == INT64_C(0)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
            l7 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l5];
            vader_midir_emit_first_get(l0, l1, l7, l4);
        } else {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
            l8 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l5];
            vader_midir_emit_get(l0, l8, l4);
        }
        vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l5)
        l9 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l5];
        l10 = ((vader_array_t*) l3)->length;
        if ((l5 < l10)) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l5)
            t0 = vader_box_bool(241u, ((uint8_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l5]);
            l11 = t0.payload.b;
        } else {
            l11 = false;
        }
        vader_midir_emit_retag_into(l0, l9, l11, l4);
        t1 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t1;
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_midir_emit_result(void* l0, int64_t l1, int32_t l2, void* l3) {
    bool t0;
    void** gc_raw_roots[2] = { &l0, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = std_collections_MutableSet_Contains_contains__i64(((vader_struct_vader_midir_ScheduleHints_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_hints)->f_skip_set, l1);
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
    size_t l5;
    vader_box_t l6 = vader_box_null();
    int64_t t0;
    void* t1 = NULL;
    uint8_t t2;
    bool t3;
    int32_t t4;
    vader_box_t* gc_roots[1] = { &l6 };
    void** gc_raw_roots[4] = { &l0, &l3, &l4, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (!(l2)) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l4 = ((vader_struct_vader_midir_CFGFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_fn_)->f_locals;
    t0 = ((int64_t) (int32_t) l1);
    l5 = (size_t) (int64_t) t0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
    t1 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
    l6 = ((vader_struct_vader_midir_CFGLocal_t*) t1)->f_type;
    t2 = vader_bytecode_val_type_of_type(l6);
    t3 = vader_midir_is_scalar_class(t2);
    if (t3) {
        l4 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project;
        t4 = vader_bytecode_intern_type(l6, l4);
        vader_struct_vader_bytecode_Retag_t* _a1_obj = (vader_struct_vader_bytecode_Retag_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_Retag_t));
        vader_obj_header_init(_a1_obj, 674u);
        _a1_obj->f_type_id = t4;
        l4 = (void*) _a1_obj;
        vader_midir_push_emit(l0, vader_ref_box(l4), l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_midir_emit_return(void* l0, int32_t l1, void* l2) {
    vader_box_t l3 = vader_box_null();
    size_t l4, l5;
    int32_t l6;
    bool l7;
    void* l8 = NULL;
    void* l9 = NULL;
    int64_t t0;
    size_t t1;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l3, &t2 };
    void** gc_raw_roots[4] = { &l0, &l2, &l8, &l9 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = vader_midir_term_return_single(l2);
    l4 = (size_t) 0;
    l5 = ((vader_array_t*) ((vader_struct_vader_midir_TermReturn_t*) l2)->f_values)->length;
    while ((l4 < l5)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_midir_TermReturn_t*) l2)->f_values);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        l6 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l4];
        if (!(l3.tag == 0u)) {
            l7 = std_collections_MutableSet_Contains_contains__i32(((vader_struct_vader_midir_ScheduleHints_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_hints)->f_skip_terminator_get, l1);
        } else {
            l7 = false;
        }
        if (!(l7)) {
            l8 = ((vader_struct_vader_midir_TermReturn_t*) l2)->f_span;
            vader_midir_emit_get(l0, l6, l8);
        }
        l9 = ((vader_struct_vader_midir_TermReturn_t*) l2)->f_span;
        vader_midir_emit_return_retag(l0, l6, l4, l9);
        t0 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t0;
    }
    l8 = ((vader_struct_vader_bytecode_BcFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_slot)->f_body;
    t1 = ((vader_array_t*) l8)->length;
    if ((t1 > INT64_C(0))) {
        if (!(l3.tag == 0u)) {
            t1 = ((vader_array_t*) l8)->length;
            t0 = (t1 - INT64_C(1));
            l4 = (size_t) (int64_t) t0;
            vader_array_t* _a1_slotarr = ((vader_array_t*) l8);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
            t2 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
            l3 = vader_bytecode_const_op_of(t2);
            if (!(l3.tag == 0u)) {
                t1 = ((vader_array_t*) l8)->length;
                t0 = (t1 - INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                vader_struct_vader_bytecode_ReturnLit_t* _a2_obj = (vader_struct_vader_bytecode_ReturnLit_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_ReturnLit_t));
                vader_obj_header_init(_a2_obj, 676u);
                _a2_obj->f_value = l3;
                l9 = (void*) _a2_obj;
                vader_array_t* _a3_slotarr = ((vader_array_t*) l8);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l4)
                vader_array_ref_store(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l4, l9);
                VADER_WRITE_BARRIER(_a3_slotarr->buf);
                { vader_gc_top = gc_frame.prev; return; }
            }
        }
    }
    vader_struct_vader_bytecode_Return_t* _a4_obj = (vader_struct_vader_bytecode_Return_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_Return_t));
    vader_obj_header_init(_a4_obj, 675u);
    l8 = (void*) _a4_obj;
    l9 = ((vader_struct_vader_midir_TermReturn_t*) l2)->f_span;
    vader_midir_push_emit(l0, vader_ref_box(l8), l9);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_midir_emit_return_retag(void* l0, int32_t l1, size_t l2, void* l3) {
    bool l4;
    size_t t0;
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
        l4 = vader_midir_is_union_slot(t1);
        vader_midir_emit_retag_into(l0, l1, l4, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    l4 = vader_midir_is_union_slot(((vader_struct_vader_midir_CFGFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_fn_)->f_return_type);
    vader_midir_emit_retag_into(l0, l1, l4, l3);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_midir_emit_set(void* l0, int32_t l1, void* l2) {
    void* l3 = NULL;
    size_t l4;
    int64_t t0;
    int32_t t1;
    void** gc_raw_roots[3] = { &l0, &l2, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_local_to_slot;
    t0 = ((int64_t) (int32_t) l1);
    l4 = (size_t) (int64_t) t0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
    t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l4];
    vader_struct_vader_bytecode_LocalSet_t* _a1_obj = (vader_struct_vader_bytecode_LocalSet_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_LocalSet_t));
    vader_obj_header_init(_a1_obj, 664u);
    _a1_obj->f_slot = t1;
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
    t0 = vader_box_bool(241u, ((uint8_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l5]);
    t1 = t0.payload.b;
    if (t1) {
        vader_midir_emit_loop(l0, l1, l2, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    l5 = -(INT32_C(1));
    vader_midir_emit_body(l0, l1, l2, l3, l5);
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
    if (l7.tag == 980u) {
        l5 = l7.payload.obj;
        vader_midir_emit_return(l0, l2, l5);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l7.tag == 981u) {
        t0 = l7.payload.obj;
        t1 = ((vader_struct_vader_midir_TermUnreachable_t*) t0)->f_reason;
        vader_struct_vader_bytecode_Unreachable_t* _a1_obj = (vader_struct_vader_bytecode_Unreachable_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_Unreachable_t));
        vader_obj_header_init(_a1_obj, 708u);
        _a1_obj->f_reason = t1;
        l5 = (void*) _a1_obj;
        t0 = l7.payload.obj;
        l8 = ((vader_struct_vader_midir_TermUnreachable_t*) t0)->f_span;
        vader_midir_push_emit(l0, vader_ref_box(l5), l8);
    } else if (l7.tag == 978u) {
        t0 = l7.payload.obj;
        l6 = ((vader_struct_vader_midir_TermBranch_t*) t0)->f_target;
        t0 = l7.payload.obj;
        l5 = ((vader_struct_vader_midir_TermBranch_t*) t0)->f_span;
        vader_midir_emit_branch(l0, l1, l2, l6, l3, l5);
    } else {
        if (!(l7.tag == 979u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l5 = l7.payload.obj;
        vader_midir_emit_cond_branch(l0, l1, l2, l5, l3, l4);
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static bool vader_midir_emitted_beneath(void* l0, void* l1, void* l2, void* l3, int32_t l4) {
    void* l5;
    size_t l6, l7;
    int32_t l8, l9, l10, l11, l12, l13;
    int32_t t0;
    int64_t t1;
    bool t2;
    l5 = l0;
    l6 = ((vader_array_t*) l5)->length;
    l7 = (size_t) 0;
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
            t1 = (l7 + INT64_C(1));
            l7 = (size_t) (int64_t) t1;
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
                t2 = vader_midir_dominates(l2, l12, l13);
                if (t2) {
                    return false;
                }
            }
            vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l10)
            l10 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l10];
        }
        t1 = (l7 + INT64_C(1));
        l7 = (size_t) (int64_t) t1;
    }
    return true;
}

static vader_box_t vader_midir_end_after_no_return(void* l0, void* l1, vader_box_t l2) {
    void* l3 = NULL;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[3] = { &l0, &l1, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (!(((vader_struct_vader_lower_LoweredCall_t*) l1)->f_type.tag == 1084u)) {
        { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_midir_TermUnreachable_t* _a0_obj = (vader_struct_vader_midir_TermUnreachable_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_TermUnreachable_t));
    vader_obj_header_init(_a0_obj, 981u);
    _a0_obj->f_span = ((vader_struct_vader_lower_LoweredCall_t*) l1)->f_span;
    _a0_obj->f_reason = 1208u;
    l3 = (void*) _a0_obj;
    vader_midir_terminate(l0, vader_ref_box(l3));
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static bool vader_midir_ends_function(vader_box_t l0) {
    return (l0.tag == 980u || l0.tag == 981u);
}

static bool vader_midir_entered_by_test(void* l0, void* l1, int32_t l2) {
    void* l3;
    size_t l4, l5;
    int32_t l6;
    bool t0;
    int64_t t1;
    l3 = l1;
    l4 = ((vader_array_t*) l3)->length;
    l5 = (size_t) 0;
    while ((l5 < l4)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l6 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l5];
        t0 = vader_midir_leaves_header(l0, l6, l2);
        if (t0) {
            return true;
        }
        t1 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t1;
    }
    return false;
}

static vader_string_t vader_midir_extern_library_name(void* l0) {
    void* l1;
    void* l4;
    size_t l2, l3;
    vader_box_t l5, l6;
    vader_string_t t0;
    size_t t1;
    void* t2;
    int64_t t3;
    l1 = ((vader_struct_toolchain_ast_FnDecl_t*) l0)->f_decorators;
    l2 = ((vader_array_t*) l1)->length;
    l3 = (size_t) 0;
    while ((l3 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l4 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
        t0 = ((vader_struct_toolchain_ast_Decorator_t*) l4)->f_name;
        if (t0 == 1623u) {
            t1 = ((vader_array_t*) ((vader_struct_toolchain_ast_Decorator_t*) l4)->f_args)->length;
            if (t1 == INT64_C(2)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_Decorator_t*) l4)->f_args);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, INT32_C(0))
                l5 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) INT32_C(0));
                if (l5.tag == 510u) {
                    t2 = l5.payload.obj;
                    t1 = ((vader_array_t*) ((vader_struct_toolchain_ast_StringLitExpr_t*) t2)->f_parts)->length;
                    if (t1 == INT64_C(1)) {
                        t2 = l5.payload.obj;
                        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_StringLitExpr_t*) t2)->f_parts);
                        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, INT32_C(0))
                        l6 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) INT32_C(0));
                        if (l6.tag == 512u) {
                            t2 = l6.payload.obj;
                            t0 = ((vader_struct_toolchain_ast_StringLitText_t*) t2)->f_value;
                            return t0;
                        }
                    }
                }
            }
        }
        t3 = (l3 + INT64_C(1));
        l3 = (size_t) (int64_t) t3;
    }
    return 0u;
}

static vader_string_t vader_midir_extern_symbol_name(void* l0) {
    void* l1;
    void* l4;
    void* l5;
    size_t l2, l3, l6;
    vader_box_t l7;
    vader_string_t t0;
    int64_t t1;
    size_t t2;
    void* t3;
    vader_box_t t4;
    l1 = ((vader_struct_toolchain_ast_FnDecl_t*) l0)->f_decorators;
    l2 = ((vader_array_t*) l1)->length;
    l3 = (size_t) 0;
    while ((l3 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l4 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
        t0 = ((vader_struct_toolchain_ast_Decorator_t*) l4)->f_name;
        if (t0 != 1623u) {
            t1 = (l3 + INT64_C(1));
            l3 = (size_t) (int64_t) t1;
            continue;
        }
        t2 = ((vader_array_t*) ((vader_struct_toolchain_ast_Decorator_t*) l4)->f_args)->length;
        if (t2 == INT64_C(0)) {
            t1 = (l3 + INT64_C(1));
            l3 = (size_t) (int64_t) t1;
            continue;
        }
        l5 = ((vader_struct_toolchain_ast_Decorator_t*) l4)->f_args;
        t2 = ((vader_array_t*) ((vader_struct_toolchain_ast_Decorator_t*) l4)->f_args)->length;
        t1 = (t2 - INT64_C(1));
        l6 = (size_t) (int64_t) t1;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l6)
        l7 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l6);
        if (l7.tag == 510u) {
            t3 = l7.payload.obj;
            t2 = ((vader_array_t*) ((vader_struct_toolchain_ast_StringLitExpr_t*) t3)->f_parts)->length;
            if (t2 == INT64_C(1)) {
                t3 = l7.payload.obj;
                vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_StringLitExpr_t*) t3)->f_parts);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, INT32_C(0))
                t4 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) INT32_C(0));
                if (t4.tag == 512u) {
                    t3 = l7.payload.obj;
                    vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_StringLitExpr_t*) t3)->f_parts);
                    VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a3_slotarr, INT32_C(0))
                    t4 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) INT32_C(0));
                    t3 = t4.payload.obj;
                    t0 = ((vader_struct_toolchain_ast_StringLitText_t*) t3)->f_value;
                    return t0;
                }
            }
        }
        t1 = (l3 + INT64_C(1));
        l3 = (size_t) (int64_t) t1;
    }
    t0 = ((vader_struct_toolchain_ast_FnDecl_t*) l0)->f_name;
    return t0;
}

static vader_box_t vader_midir_find_struct_field_index(void* l0, int32_t l1, vader_string_t l2) {
    void* l3;
    size_t l4, l6;
    vader_box_t l5;
    int64_t t0;
    void* t1;
    vader_string_t t2;
    vader_box_t t3;
    l3 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_types;
    t0 = ((int64_t) (int32_t) l1);
    l4 = (size_t) (int64_t) t0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
    l5 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
    if (l5.tag == 561u) {
        l4 = (size_t) 0;
        t1 = l5.payload.obj;
        l6 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcStruct_t*) t1)->f_fields)->length;
        while ((l4 < l6)) {
            t1 = l5.payload.obj;
            vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcStruct_t*) t1)->f_fields);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
            t1 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
            t2 = ((vader_struct_vader_bytecode_BcField_t*) t1)->f_name;
            if (t2 == l2) {
                t3 = vader_box_i64(253u, (int64_t)(uint64_t) l4);
                return t3;
            }
            t0 = (l4 + INT64_C(1));
            l4 = (size_t) (int64_t) t0;
        }
    }
    return vader_box_obj(0u, NULL);
}

static vader_box_t vader_midir_first_stack_operand(vader_box_t l0) {
    void* t0;
    vader_box_t t1;
    size_t t2;
    int32_t t3;
    if (l0.tag == 952u) {
        return vader_box_obj(0u, NULL);
    }
    if (l0.tag == 959u) {
        return vader_box_obj(0u, NULL);
    }
    if (l0.tag == 958u) {
        return vader_box_obj(0u, NULL);
    }
    if (l0.tag == 953u) {
        return vader_box_obj(0u, NULL);
    }
    if (l0.tag == 966u) {
        return vader_box_obj(0u, NULL);
    }
    if (l0.tag == 962u) {
        t0 = l0.payload.obj;
        t1 = vader_box_i32(246u, ((vader_struct_vader_midir_InstrMove_t*) t0)->f_src);
        return t1;
    }
    if (l0.tag == 945u) {
        t0 = l0.payload.obj;
        t1 = vader_box_i32(246u, ((vader_struct_vader_midir_InstrBinOp_t*) t0)->f_lhs);
        return t1;
    }
    if (l0.tag == 967u) {
        t0 = l0.payload.obj;
        t1 = vader_box_i32(246u, ((vader_struct_vader_midir_InstrUnOp_t*) t0)->f_operand);
        return t1;
    }
    if (l0.tag == 946u) {
        t0 = l0.payload.obj;
        t2 = ((vader_array_t*) ((vader_struct_vader_midir_InstrCall_t*) t0)->f_args)->length;
        if (!((t2 > INT64_C(0)))) {
            return vader_box_obj(0u, NULL);
        }
        t0 = l0.payload.obj;
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_midir_InstrCall_t*) t0)->f_args);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
        t3 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) INT32_C(0)];
        t1 = vader_box_i32(246u, t3);
        return t1;
    }
    if (l0.tag == 947u) {
        t0 = l0.payload.obj;
        t2 = ((vader_array_t*) ((vader_struct_vader_midir_InstrCallIndirect_t*) t0)->f_args)->length;
        if (!((t2 > INT64_C(0)))) {
            t0 = l0.payload.obj;
            t1 = vader_box_i32(246u, ((vader_struct_vader_midir_InstrCallIndirect_t*) t0)->f_callee);
            return t1;
        }
        t0 = l0.payload.obj;
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_midir_InstrCallIndirect_t*) t0)->f_args);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, INT32_C(0))
        t3 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) INT32_C(0)];
        t1 = vader_box_i32(246u, t3);
        return t1;
    }
    if (l0.tag == 968u) {
        t0 = l0.payload.obj;
        t2 = ((vader_array_t*) ((vader_struct_vader_midir_InstrVirtualCall_t*) t0)->f_args)->length;
        if (!((t2 > INT64_C(0)))) {
            t0 = l0.payload.obj;
            t1 = vader_box_i32(246u, ((vader_struct_vader_midir_InstrVirtualCall_t*) t0)->f_receiver);
            return t1;
        }
        t0 = l0.payload.obj;
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_midir_InstrVirtualCall_t*) t0)->f_args);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, INT32_C(0))
        t3 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) INT32_C(0)];
        t1 = vader_box_i32(246u, t3);
        return t1;
    }
    if (l0.tag == 956u) {
        t0 = l0.payload.obj;
        t1 = vader_box_i32(246u, ((vader_struct_vader_midir_InstrFieldGet_t*) t0)->f_target);
        return t1;
    }
    if (l0.tag == 957u) {
        t0 = l0.payload.obj;
        t1 = vader_box_i32(246u, ((vader_struct_vader_midir_InstrFieldSet_t*) t0)->f_target);
        return t1;
    }
    if (l0.tag == 939u) {
        t0 = l0.payload.obj;
        t1 = vader_box_i32(246u, ((vader_struct_vader_midir_InstrArrayGet_t*) t0)->f_target);
        return t1;
    }
    if (l0.tag == 943u) {
        t0 = l0.payload.obj;
        t1 = vader_box_i32(246u, ((vader_struct_vader_midir_InstrArraySet_t*) t0)->f_target);
        return t1;
    }
    if (l0.tag == 940u) {
        t0 = l0.payload.obj;
        t1 = vader_box_i32(246u, ((vader_struct_vader_midir_InstrArrayLen_t*) t0)->f_target);
        return t1;
    }
    if (l0.tag == 942u) {
        t0 = l0.payload.obj;
        t1 = vader_box_i32(246u, ((vader_struct_vader_midir_InstrArrayPush_t*) t0)->f_target);
        return t1;
    }
    if (l0.tag == 944u) {
        t0 = l0.payload.obj;
        t1 = vader_box_i32(246u, ((vader_struct_vader_midir_InstrArraySlice_t*) t0)->f_target);
        return t1;
    }
    if (l0.tag == 963u) {
        t0 = l0.payload.obj;
        t1 = vader_box_i32(246u, ((vader_struct_vader_midir_InstrStringSlice_t*) t0)->f_target);
        return t1;
    }
    if (l0.tag == 964u) {
        t0 = l0.payload.obj;
        t2 = ((vader_array_t*) ((vader_struct_vader_midir_InstrStructNew_t*) t0)->f_fields)->length;
        if (!((t2 > INT64_C(0)))) {
            return vader_box_obj(0u, NULL);
        }
        t0 = l0.payload.obj;
        vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_midir_InstrStructNew_t*) t0)->f_fields);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, INT32_C(0))
        t3 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) INT32_C(0)];
        t1 = vader_box_i32(246u, t3);
        return t1;
    }
    if (l0.tag == 941u) {
        t0 = l0.payload.obj;
        t2 = ((vader_array_t*) ((vader_struct_vader_midir_InstrArrayNew_t*) t0)->f_elements)->length;
        if (!((t2 > INT64_C(0)))) {
            return vader_box_obj(0u, NULL);
        }
        t0 = l0.payload.obj;
        vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_vader_midir_InstrArrayNew_t*) t0)->f_elements);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, INT32_C(0))
        t3 = ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) INT32_C(0)];
        t1 = vader_box_i32(246u, t3);
        return t1;
    }
    if (l0.tag == 965u) {
        t0 = l0.payload.obj;
        t1 = vader_box_i32(246u, ((vader_struct_vader_midir_InstrTypeCheck_t*) t0)->f_value);
        return t1;
    }
    if (l0.tag == 948u) {
        t0 = l0.payload.obj;
        t1 = vader_box_i32(246u, ((vader_struct_vader_midir_InstrCast_t*) t0)->f_value);
        return t1;
    }
    if (l0.tag == 950u) {
        t0 = l0.payload.obj;
        t1 = vader_box_i32(246u, ((vader_struct_vader_midir_InstrCellNew_t*) t0)->f_value);
        return t1;
    }
    if (l0.tag == 949u) {
        t0 = l0.payload.obj;
        t1 = vader_box_i32(246u, ((vader_struct_vader_midir_InstrCellGet_t*) t0)->f_cell);
        return t1;
    }
    if (l0.tag == 951u) {
        t0 = l0.payload.obj;
        t1 = vader_box_i32(246u, ((vader_struct_vader_midir_InstrCellSet_t*) t0)->f_cell);
        return t1;
    }
    if (l0.tag == 961u) {
        t0 = l0.payload.obj;
        t1 = vader_box_i32(246u, ((vader_struct_vader_midir_InstrMakeClosure_t*) t0)->f_env);
        return t1;
    }
    if (l0.tag == 960u) {
        t0 = l0.payload.obj;
        t2 = ((vader_array_t*) ((vader_struct_vader_midir_InstrIntrinsic_t*) t0)->f_args)->length;
        if (!((t2 > INT64_C(0)))) {
            return vader_box_obj(0u, NULL);
        }
        t0 = l0.payload.obj;
        vader_array_t* _a5_slotarr = ((vader_array_t*) ((vader_struct_vader_midir_InstrIntrinsic_t*) t0)->f_args);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, INT32_C(0))
        t3 = ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) INT32_C(0)];
        t1 = vader_box_i32(246u, t3);
        return t1;
    }
    if (l0.tag == 955u) {
        t0 = l0.payload.obj;
        t1 = vader_box_i32(246u, ((vader_struct_vader_midir_InstrDeferPush_t*) t0)->f_value);
        return t1;
    }
    if (!(l0.tag == 954u)) {
        vader_unreachable("non-exhaustive match (T3013 should have caught this)");
    }
    return vader_box_obj(0u, NULL);
}

static vader_box_t vader_midir_first_terminator_operand(vader_box_t l0) {
    void* t0;
    vader_box_t t1;
    if (l0.tag == 978u) {
        return vader_box_obj(0u, NULL);
    }
    if (l0.tag == 981u) {
        return vader_box_obj(0u, NULL);
    }
    if (l0.tag == 979u) {
        t0 = l0.payload.obj;
        t1 = vader_box_i32(246u, ((vader_struct_vader_midir_TermCondBranch_t*) t0)->f_cond);
        return t1;
    }
    if (!(l0.tag == 980u)) {
        vader_unreachable("non-exhaustive match (T3013 should have caught this)");
    }
    t0 = l0.payload.obj;
    t1 = vader_midir_term_return_single(t0);
    return t1;
}

static bool vader_midir_fits_in(uint8_t l0, uint8_t l1) {
    bool l2, l3;
    if (l1 == INT32_C(5)) {
        l2 = l0 == INT32_C(5);
        return l2;
    }
    if (l1 == INT32_C(0)) {
        l2 = l0 == INT32_C(0);
    } else if (l1 == INT32_C(6)) {
        if (l0 == INT32_C(5)) {
            l2 = true;
        } else {
            l2 = l0 == INT32_C(6);
        }
    } else if (l1 == INT32_C(1)) {
        if (l0 == INT32_C(5)) {
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
            l3 = l1 == INT32_C(4);
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
        if (l3) {
            l3 = true;
        } else {
            l3 = l1 == INT32_C(18);
        }
        if (l3) {
            l3 = true;
        } else {
            l3 = l1 == INT32_C(19);
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
    bool l2, l3;
    int32_t l6;
    void* l7 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[3] = { &l0, &l7, &t0 };
    vader_string_t* gc_atom_roots[3] = { &l1, &l4, &l5 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct_vader_lower_LoweredFnDecl_t*) l0)->f_mangled;
    l2 = false;
    l3 = false;
    l4 = 0u;
    l5 = 0u;
    l6 = -(INT32_C(1));
    if (((vader_struct_vader_comptime_MonoEntry_t*) ((vader_struct_vader_lower_LoweredFnDecl_t*) l0)->f_origin)->f_decl.tag == 469u) {
        l7 = ((vader_struct_vader_comptime_MonoEntry_t*) ((vader_struct_vader_lower_LoweredFnDecl_t*) l0)->f_origin)->f_decl.payload.obj;
        l1 = vader_midir_extern_symbol_name(l7);
        l2 = toolchain_ast_decorators_have(((vader_struct_toolchain_ast_FnDecl_t*) l7)->f_decorators, 1623u);
        l3 = toolchain_ast_decorators_have(((vader_struct_toolchain_ast_FnDecl_t*) l7)->f_decorators, 1609u);
        l4 = vader_midir_c_header_of(((vader_struct_toolchain_ast_FnDecl_t*) l7)->f_decorators);
        l5 = vader_midir_extern_library_name(l7);
        l6 = vader_midir_c_variadic_fixed_of(((vader_struct_toolchain_ast_FnDecl_t*) l7)->f_decorators);
        vader_struct_vader_midir_FnMetadata_t* _a0_obj = (vader_struct_vader_midir_FnMetadata_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_FnMetadata_t));
        vader_obj_header_init(_a0_obj, 938u);
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
    vader_obj_header_init(_a1_obj, 938u);
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
    size_t l5, l6;
    int32_t l7;
    vader_box_t l12 = vader_box_null();
    vader_string_t l15 = 0;
    vader_string_t l16 = 0;
    bool l17, l18;
    void* t0 = NULL;
    int64_t t1;
    vader_box_t* gc_roots[1] = { &l12 };
    void** gc_raw_roots[12] = { &l0, &l1, &l2, &l3, &l4, &l8, &l9, &l10, &l11, &l13, &l14, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l15, &l16 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 12u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = vader_midir_count_uses(l0);
    vader_array_t* _a0_arr = vader_array_new(14u, 0u, 7u, 246u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(11u, 0u, 12u, 241u);
    l3 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(14u, 0u, 7u, 246u);
    l4 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__i32__bool_t* _a3_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
    vader_obj_header_init(_a3_obj, 328u);
    _a3_obj->f_ekeys = l2;
    _a3_obj->f_evals = l3;
    _a3_obj->f_index = l4;
    _a3_obj->f_mask = (size_t) 0;
    _a3_obj->f_size = (size_t) 0;
    _a3_obj->f_tombs = (size_t) 0;
    t0 = (void*) _a3_obj;
    vader_struct_std_collections_MutableSet__i32_t* _a4_obj = (vader_struct_std_collections_MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i32_t));
    vader_obj_header_init(_a4_obj, 425u);
    _a4_obj->f_inner = t0;
    l2 = (void*) _a4_obj;
    l3 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_params;
    l5 = ((vader_array_t*) l3)->length;
    l6 = (size_t) 0;
    while ((l6 < l5)) {
        vader_array_t* _a5_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l6)
        t0 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l6);
        l7 = ((vader_struct_vader_midir_CFGParam_t*) t0)->f_local;
        std_collections_add__i32(l2, l7);
        t1 = (l6 + INT64_C(1));
        l6 = (size_t) (int64_t) t1;
    }
    vader_array_t* _a6_arr = vader_array_new(102u, 0u, 13u, 916u);
    l3 = (void*) _a6_arr;
    l5 = ((vader_array_t*) ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_blocks)->length;
    vader_array_t* _a7_arr = vader_array_repeat((vader_array_t*) l3, (size_t) l5);
    l3 = (void*) _a7_arr;
    l4 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_blocks;
    l5 = ((vader_array_t*) l4)->length;
    l6 = (size_t) 0;
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
        vader_obj_header_init(_a9_obj, 916u);
        _a9_obj->f_id = l7;
        _a9_obj->f_instructions = l11;
        _a9_obj->f_terminator = l12;
        _a9_obj->f_span = l13;
        l14 = (void*) _a9_obj;
        vader_array_push((vader_array_t*) l3, vader_ref_box(l14));
        t1 = (l6 + INT64_C(1));
        l6 = (size_t) (int64_t) t1;
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
    vader_obj_header_init(_a10_obj, 918u);
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
    void* l27 = NULL;
    void* l29 = NULL;
    void* l32 = NULL;
    size_t l5, l6, l22, l30, l35;
    vader_box_t l7 = vader_box_null(), l8 = vader_box_null(), l12 = vader_box_null(), l23 = vader_box_null(), l24 = vader_box_null(), l31 = vader_box_null(), l34 = vader_box_null();
    int32_t l9, l11, l13, l17, l25, l26, l33;
    bool l14, l19, l28;
    int64_t l18, l21;
    void* t0 = NULL;
    bool t1;
    int64_t t2;
    size_t t3;
    int32_t t4;
    vader_box_t t5 = vader_box_null();
    vader_box_t* gc_roots[8] = { &l7, &l8, &l12, &l23, &l24, &l31, &l34, &t5 };
    void** gc_raw_roots[13] = {
        &l0, &l1, &l2, &l3, &l4, &l10, &l15, &l16, &l20, &l27, &l29, &l32, &t0,
    };
    vader_gc_frame_t gc_frame = { vader_gc_top, 8u, 13u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(203u, 0u, 13u, 1503u);
    l4 = (void*) _a0_arr;
    l5 = (size_t) 0;
    l6 = ((vader_array_t*) ((vader_struct_vader_midir_BasicBlock_t*) l0)->f_instructions)->length;
    while ((l5 < l6)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_midir_BasicBlock_t*) l0)->f_instructions);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
        l7 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5);
        if (l7.tag == 962u) {
            if (l7.tag == 962u) {
                t0 = l7.payload.obj;
                l9 = ((vader_struct_vader_midir_InstrMove_t*) t0)->f_src;
                t1 = std_collections_MutableSet_Contains_contains__i32(l3, l9);
                if (t1) {
                    l10 = l7.payload.obj;
                    vader_array_push((vader_array_t*) l4, vader_ref_box(l10));
                    t2 = (l5 + INT64_C(1));
                    l5 = (size_t) (int64_t) t2;
                    continue;
                }
                t0 = l7.payload.obj;
                l11 = ((vader_struct_vader_midir_InstrMove_t*) t0)->f_src;
                l12 = std_collections_MutableMap_Index_at__i32__i32(l2, l11);
                if (l12.tag == 246u) {
                    l13 = ((int32_t) l12.payload.i);
                } else {
                    l13 = INT32_C(0);
                }
                if (l13 != INT32_C(1)) {
                    l14 = true;
                } else {
                    l15 = l7.payload.obj;
                    l14 = vader_midir_move_retags(l1, l15);
                }
                if (l14) {
                    l16 = l7.payload.obj;
                    vader_array_push((vader_array_t*) l4, vader_ref_box(l16));
                    t2 = (l5 + INT64_C(1));
                    l5 = (size_t) (int64_t) t2;
                    continue;
                }
                t0 = l7.payload.obj;
                l17 = ((vader_struct_vader_midir_InstrMove_t*) t0)->f_dst;
                l18 = -(INT64_C(1));
                l19 = false;
                vader_array_t* _a2_arr = vader_array_new(11u, 1u, 12u, 241u);
                ((uint8_t*) _a2_arr->buf->slots)[_a2_arr->offset + 0u] = (uint8_t) false;
                l20 = (void*) _a2_arr;
                t3 = ((vader_array_t*) l4)->length;
                l21 = (((int64_t) (size_t) t3) - INT64_C(1));
                while ((l21 >= INT64_C(0))) {
                    t2 = l21;
                    l22 = (size_t) (int64_t) t2;
                    vader_array_t* _a3_slotarr = ((vader_array_t*) l4);
                    VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l22)
                    l23 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l22);
                    l24 = vader_midir_dst_of(l23);
                    if (l24.tag == 246u) {
                        l25 = ((int32_t) l24.payload.i);
                        t0 = l7.payload.obj;
                        l26 = ((vader_struct_vader_midir_InstrMove_t*) t0)->f_src;
                        t1 = vader_midir_LocalId_Equals_equals(l25, l26);
                        if (t1) {
                            l18 = l21;
                            break;
                        }
                        t4 = ((int32_t) l24.payload.i);
                        t1 = vader_midir_LocalId_Equals_equals(t4, l17);
                        if (t1) {
                            l19 = true;
                            break;
                        }
                    }
                    vader_array_t* _a4_slotarr = ((vader_array_t*) l20);
                    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a4_slotarr, INT32_C(0))
                    ((uint8_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) INT32_C(0)] = (uint8_t) false;
                    vader_struct___lambda_env_vader_midir_7_t* _a5_obj = (vader_struct___lambda_env_vader_midir_7_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_midir_7_t));
                    vader_obj_header_init(_a5_obj, 277u);
                    _a5_obj->f_cap_0 = l17;
                    _a5_obj->f_cap_1 = l20;
                    t0 = (void*) _a5_obj;
                    vader_fn_t* _a6_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
                    vader_obj_header_init(_a6_closure, 215u);
                    _a6_closure->code = (void*) &vader_fn_lift___lambda_vader_midir_6;
                    _a6_closure->env = t0;
                    l27 = (void*) _a6_closure;
                    vader_midir_for_each_read_local(l23, l27);
                    vader_array_t* _a7_slotarr = ((vader_array_t*) l20);
                    VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a7_slotarr, INT32_C(0))
                    t5 = vader_box_bool(241u, ((uint8_t*) _a7_slotarr->buf->slots)[_a7_slotarr->offset + (size_t) INT32_C(0)]);
                    t1 = t5.payload.b;
                    if (t1) {
                        l19 = true;
                        break;
                    }
                    l21 = (l21 - INT64_C(1));
                }
                if ((l18 < INT64_C(0))) {
                    l28 = true;
                } else {
                    l28 = l19;
                }
                if (l28) {
                    l29 = l7.payload.obj;
                    vader_array_push((vader_array_t*) l4, vader_ref_box(l29));
                    t2 = (l5 + INT64_C(1));
                    l5 = (size_t) (int64_t) t2;
                    continue;
                }
                t2 = l18;
                l30 = (size_t) (int64_t) t2;
                vader_array_t* _a8_slotarr = ((vader_array_t*) l4);
                VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l30)
                l31 = vader_array_ref_load_box(_a8_slotarr->buf, _a8_slotarr->offset + (size_t) l30);
                t1 = vader_midir_instruction_has_side_effect(l31);
                if (t1) {
                    l32 = l7.payload.obj;
                    vader_array_push((vader_array_t*) l4, vader_ref_box(l32));
                    t2 = (l5 + INT64_C(1));
                    l5 = (size_t) (int64_t) t2;
                    continue;
                }
                t0 = l7.payload.obj;
                l33 = ((vader_struct_vader_midir_InstrMove_t*) t0)->f_dst;
                l34 = vader_midir_with_dst(l31, l33);
                t2 = l18;
                l35 = (size_t) (int64_t) t2;
                vader_array_t* _a9_slotarr = ((vader_array_t*) l4);
                VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l35)
                vader_array_ref_store(_a9_slotarr->buf, _a9_slotarr->offset + (size_t) l35, l34.payload.obj);
                VADER_WRITE_BARRIER(_a9_slotarr->buf);
            }
            t2 = (l5 + INT64_C(1));
            l5 = (size_t) (int64_t) t2;
            continue;
        }
        l8 = l7;
        vader_array_push((vader_array_t*) l4, l8);
        t2 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t2;
    }
    { void* __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_midir_for_each_read_in_terminator(vader_box_t l0, void* l1) {
    void* l2 = NULL;
    size_t l3, l4;
    void* t0 = NULL;
    int32_t t1;
    int64_t t2;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[3] = { &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 979u) {
        t0 = l0.payload.obj;
        vader_fn_t* _a0_fnobj = (vader_fn_t*) l1;
        ((vader_fn_erased_sig_1_t) _a0_fnobj->code)(_a0_fnobj->env, vader_box_i32(246u, ((vader_struct_vader_midir_TermCondBranch_t*) t0)->f_cond));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 980u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_midir_TermReturn_t*) t0)->f_values;
        l3 = ((vader_array_t*) l2)->length;
        l4 = (size_t) 0;
        while ((l4 < l3)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
            t1 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
            vader_fn_t* _a2_fnobj = (vader_fn_t*) l1;
            ((vader_fn_erased_sig_1_t) _a2_fnobj->code)(_a2_fnobj->env, vader_box_i32(246u, t1));
            t2 = (l4 + INT64_C(1));
            l4 = (size_t) (int64_t) t2;
        }
    } else if (!(l0.tag == 978u)) {
        if (!(l0.tag == 981u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_midir_for_each_read_local(vader_box_t l0, void* l1) {
    void* l2 = NULL;
    size_t l3, l4;
    void* t0 = NULL;
    int32_t t1;
    int64_t t2;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[3] = { &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 952u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (!(l0.tag == 959u)) {
        if (!(l0.tag == 958u)) {
            if (l0.tag == 962u) {
                t0 = l0.payload.obj;
                vader_fn_t* _a0_fnobj = (vader_fn_t*) l1;
                ((vader_fn_erased_sig_1_t) _a0_fnobj->code)(_a0_fnobj->env, vader_box_i32(246u, ((vader_struct_vader_midir_InstrMove_t*) t0)->f_src));
            } else if (l0.tag == 945u) {
                t0 = l0.payload.obj;
                vader_fn_t* _a1_fnobj = (vader_fn_t*) l1;
                ((vader_fn_erased_sig_1_t) _a1_fnobj->code)(_a1_fnobj->env, vader_box_i32(246u, ((vader_struct_vader_midir_InstrBinOp_t*) t0)->f_lhs));
                t0 = l0.payload.obj;
                vader_fn_t* _a2_fnobj = (vader_fn_t*) l1;
                ((vader_fn_erased_sig_1_t) _a2_fnobj->code)(_a2_fnobj->env, vader_box_i32(246u, ((vader_struct_vader_midir_InstrBinOp_t*) t0)->f_rhs));
            } else if (l0.tag == 967u) {
                t0 = l0.payload.obj;
                vader_fn_t* _a3_fnobj = (vader_fn_t*) l1;
                ((vader_fn_erased_sig_1_t) _a3_fnobj->code)(_a3_fnobj->env, vader_box_i32(246u, ((vader_struct_vader_midir_InstrUnOp_t*) t0)->f_operand));
            } else if (l0.tag == 946u) {
                t0 = l0.payload.obj;
                l2 = ((vader_struct_vader_midir_InstrCall_t*) t0)->f_args;
                l3 = ((vader_array_t*) l2)->length;
                l4 = (size_t) 0;
                while ((l4 < l3)) {
                    vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
                    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l4)
                    t1 = ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l4];
                    vader_fn_t* _a5_fnobj = (vader_fn_t*) l1;
                    ((vader_fn_erased_sig_1_t) _a5_fnobj->code)(_a5_fnobj->env, vader_box_i32(246u, t1));
                    t2 = (l4 + INT64_C(1));
                    l4 = (size_t) (int64_t) t2;
                }
            } else if (l0.tag == 947u) {
                t0 = l0.payload.obj;
                vader_fn_t* _a6_fnobj = (vader_fn_t*) l1;
                ((vader_fn_erased_sig_1_t) _a6_fnobj->code)(_a6_fnobj->env, vader_box_i32(246u, ((vader_struct_vader_midir_InstrCallIndirect_t*) t0)->f_callee));
                t0 = l0.payload.obj;
                l2 = ((vader_struct_vader_midir_InstrCallIndirect_t*) t0)->f_args;
                l3 = ((vader_array_t*) l2)->length;
                l4 = (size_t) 0;
                while ((l4 < l3)) {
                    vader_array_t* _a7_slotarr = ((vader_array_t*) l2);
                    VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l4)
                    t1 = ((int32_t*) _a7_slotarr->buf->slots)[_a7_slotarr->offset + (size_t) l4];
                    vader_fn_t* _a8_fnobj = (vader_fn_t*) l1;
                    ((vader_fn_erased_sig_1_t) _a8_fnobj->code)(_a8_fnobj->env, vader_box_i32(246u, t1));
                    t2 = (l4 + INT64_C(1));
                    l4 = (size_t) (int64_t) t2;
                }
            } else if (l0.tag == 968u) {
                t0 = l0.payload.obj;
                vader_fn_t* _a9_fnobj = (vader_fn_t*) l1;
                ((vader_fn_erased_sig_1_t) _a9_fnobj->code)(_a9_fnobj->env, vader_box_i32(246u, ((vader_struct_vader_midir_InstrVirtualCall_t*) t0)->f_receiver));
                t0 = l0.payload.obj;
                l2 = ((vader_struct_vader_midir_InstrVirtualCall_t*) t0)->f_args;
                l3 = ((vader_array_t*) l2)->length;
                l4 = (size_t) 0;
                while ((l4 < l3)) {
                    vader_array_t* _a10_slotarr = ((vader_array_t*) l2);
                    VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a10_slotarr, l4)
                    t1 = ((int32_t*) _a10_slotarr->buf->slots)[_a10_slotarr->offset + (size_t) l4];
                    vader_fn_t* _a11_fnobj = (vader_fn_t*) l1;
                    ((vader_fn_erased_sig_1_t) _a11_fnobj->code)(_a11_fnobj->env, vader_box_i32(246u, t1));
                    t2 = (l4 + INT64_C(1));
                    l4 = (size_t) (int64_t) t2;
                }
            } else if (l0.tag == 956u) {
                t0 = l0.payload.obj;
                vader_fn_t* _a12_fnobj = (vader_fn_t*) l1;
                ((vader_fn_erased_sig_1_t) _a12_fnobj->code)(_a12_fnobj->env, vader_box_i32(246u, ((vader_struct_vader_midir_InstrFieldGet_t*) t0)->f_target));
            } else if (l0.tag == 957u) {
                t0 = l0.payload.obj;
                vader_fn_t* _a13_fnobj = (vader_fn_t*) l1;
                ((vader_fn_erased_sig_1_t) _a13_fnobj->code)(_a13_fnobj->env, vader_box_i32(246u, ((vader_struct_vader_midir_InstrFieldSet_t*) t0)->f_target));
                t0 = l0.payload.obj;
                vader_fn_t* _a14_fnobj = (vader_fn_t*) l1;
                ((vader_fn_erased_sig_1_t) _a14_fnobj->code)(_a14_fnobj->env, vader_box_i32(246u, ((vader_struct_vader_midir_InstrFieldSet_t*) t0)->f_value));
            } else if (l0.tag == 939u) {
                t0 = l0.payload.obj;
                vader_fn_t* _a15_fnobj = (vader_fn_t*) l1;
                ((vader_fn_erased_sig_1_t) _a15_fnobj->code)(_a15_fnobj->env, vader_box_i32(246u, ((vader_struct_vader_midir_InstrArrayGet_t*) t0)->f_target));
                t0 = l0.payload.obj;
                vader_fn_t* _a16_fnobj = (vader_fn_t*) l1;
                ((vader_fn_erased_sig_1_t) _a16_fnobj->code)(_a16_fnobj->env, vader_box_i32(246u, ((vader_struct_vader_midir_InstrArrayGet_t*) t0)->f_index));
            } else if (l0.tag == 943u) {
                t0 = l0.payload.obj;
                vader_fn_t* _a17_fnobj = (vader_fn_t*) l1;
                ((vader_fn_erased_sig_1_t) _a17_fnobj->code)(_a17_fnobj->env, vader_box_i32(246u, ((vader_struct_vader_midir_InstrArraySet_t*) t0)->f_target));
                t0 = l0.payload.obj;
                vader_fn_t* _a18_fnobj = (vader_fn_t*) l1;
                ((vader_fn_erased_sig_1_t) _a18_fnobj->code)(_a18_fnobj->env, vader_box_i32(246u, ((vader_struct_vader_midir_InstrArraySet_t*) t0)->f_index));
                t0 = l0.payload.obj;
                vader_fn_t* _a19_fnobj = (vader_fn_t*) l1;
                ((vader_fn_erased_sig_1_t) _a19_fnobj->code)(_a19_fnobj->env, vader_box_i32(246u, ((vader_struct_vader_midir_InstrArraySet_t*) t0)->f_value));
            } else if (l0.tag == 940u) {
                t0 = l0.payload.obj;
                vader_fn_t* _a20_fnobj = (vader_fn_t*) l1;
                ((vader_fn_erased_sig_1_t) _a20_fnobj->code)(_a20_fnobj->env, vader_box_i32(246u, ((vader_struct_vader_midir_InstrArrayLen_t*) t0)->f_target));
            } else if (l0.tag == 942u) {
                t0 = l0.payload.obj;
                vader_fn_t* _a21_fnobj = (vader_fn_t*) l1;
                ((vader_fn_erased_sig_1_t) _a21_fnobj->code)(_a21_fnobj->env, vader_box_i32(246u, ((vader_struct_vader_midir_InstrArrayPush_t*) t0)->f_target));
                t0 = l0.payload.obj;
                vader_fn_t* _a22_fnobj = (vader_fn_t*) l1;
                ((vader_fn_erased_sig_1_t) _a22_fnobj->code)(_a22_fnobj->env, vader_box_i32(246u, ((vader_struct_vader_midir_InstrArrayPush_t*) t0)->f_value));
            } else if (l0.tag == 944u) {
                t0 = l0.payload.obj;
                vader_fn_t* _a23_fnobj = (vader_fn_t*) l1;
                ((vader_fn_erased_sig_1_t) _a23_fnobj->code)(_a23_fnobj->env, vader_box_i32(246u, ((vader_struct_vader_midir_InstrArraySlice_t*) t0)->f_target));
                t0 = l0.payload.obj;
                vader_fn_t* _a24_fnobj = (vader_fn_t*) l1;
                ((vader_fn_erased_sig_1_t) _a24_fnobj->code)(_a24_fnobj->env, vader_box_i32(246u, ((vader_struct_vader_midir_InstrArraySlice_t*) t0)->f_lo));
                t0 = l0.payload.obj;
                vader_fn_t* _a25_fnobj = (vader_fn_t*) l1;
                ((vader_fn_erased_sig_1_t) _a25_fnobj->code)(_a25_fnobj->env, vader_box_i32(246u, ((vader_struct_vader_midir_InstrArraySlice_t*) t0)->f_hi));
            } else if (l0.tag == 963u) {
                t0 = l0.payload.obj;
                vader_fn_t* _a26_fnobj = (vader_fn_t*) l1;
                ((vader_fn_erased_sig_1_t) _a26_fnobj->code)(_a26_fnobj->env, vader_box_i32(246u, ((vader_struct_vader_midir_InstrStringSlice_t*) t0)->f_target));
                t0 = l0.payload.obj;
                vader_fn_t* _a27_fnobj = (vader_fn_t*) l1;
                ((vader_fn_erased_sig_1_t) _a27_fnobj->code)(_a27_fnobj->env, vader_box_i32(246u, ((vader_struct_vader_midir_InstrStringSlice_t*) t0)->f_lo));
                t0 = l0.payload.obj;
                vader_fn_t* _a28_fnobj = (vader_fn_t*) l1;
                ((vader_fn_erased_sig_1_t) _a28_fnobj->code)(_a28_fnobj->env, vader_box_i32(246u, ((vader_struct_vader_midir_InstrStringSlice_t*) t0)->f_hi));
            } else if (l0.tag == 964u) {
                t0 = l0.payload.obj;
                l2 = ((vader_struct_vader_midir_InstrStructNew_t*) t0)->f_fields;
                l3 = ((vader_array_t*) l2)->length;
                l4 = (size_t) 0;
                while ((l4 < l3)) {
                    vader_array_t* _a29_slotarr = ((vader_array_t*) l2);
                    VADER_ARRAY_RESOLVE_BUF(_a29_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a29_slotarr, l4)
                    t1 = ((int32_t*) _a29_slotarr->buf->slots)[_a29_slotarr->offset + (size_t) l4];
                    vader_fn_t* _a30_fnobj = (vader_fn_t*) l1;
                    ((vader_fn_erased_sig_1_t) _a30_fnobj->code)(_a30_fnobj->env, vader_box_i32(246u, t1));
                    t2 = (l4 + INT64_C(1));
                    l4 = (size_t) (int64_t) t2;
                }
            } else if (l0.tag == 941u) {
                t0 = l0.payload.obj;
                l2 = ((vader_struct_vader_midir_InstrArrayNew_t*) t0)->f_elements;
                l3 = ((vader_array_t*) l2)->length;
                l4 = (size_t) 0;
                while ((l4 < l3)) {
                    vader_array_t* _a31_slotarr = ((vader_array_t*) l2);
                    VADER_ARRAY_RESOLVE_BUF(_a31_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a31_slotarr, l4)
                    t1 = ((int32_t*) _a31_slotarr->buf->slots)[_a31_slotarr->offset + (size_t) l4];
                    vader_fn_t* _a32_fnobj = (vader_fn_t*) l1;
                    ((vader_fn_erased_sig_1_t) _a32_fnobj->code)(_a32_fnobj->env, vader_box_i32(246u, t1));
                    t2 = (l4 + INT64_C(1));
                    l4 = (size_t) (int64_t) t2;
                }
            } else if (l0.tag == 965u) {
                t0 = l0.payload.obj;
                vader_fn_t* _a33_fnobj = (vader_fn_t*) l1;
                ((vader_fn_erased_sig_1_t) _a33_fnobj->code)(_a33_fnobj->env, vader_box_i32(246u, ((vader_struct_vader_midir_InstrTypeCheck_t*) t0)->f_value));
            } else if (!(l0.tag == 966u)) {
                if (!(l0.tag == 953u)) {
                    if (l0.tag == 948u) {
                        t0 = l0.payload.obj;
                        vader_fn_t* _a34_fnobj = (vader_fn_t*) l1;
                        ((vader_fn_erased_sig_1_t) _a34_fnobj->code)(_a34_fnobj->env, vader_box_i32(246u, ((vader_struct_vader_midir_InstrCast_t*) t0)->f_value));
                    } else if (l0.tag == 950u) {
                        t0 = l0.payload.obj;
                        vader_fn_t* _a35_fnobj = (vader_fn_t*) l1;
                        ((vader_fn_erased_sig_1_t) _a35_fnobj->code)(_a35_fnobj->env, vader_box_i32(246u, ((vader_struct_vader_midir_InstrCellNew_t*) t0)->f_value));
                    } else if (l0.tag == 949u) {
                        t0 = l0.payload.obj;
                        vader_fn_t* _a36_fnobj = (vader_fn_t*) l1;
                        ((vader_fn_erased_sig_1_t) _a36_fnobj->code)(_a36_fnobj->env, vader_box_i32(246u, ((vader_struct_vader_midir_InstrCellGet_t*) t0)->f_cell));
                    } else if (l0.tag == 951u) {
                        t0 = l0.payload.obj;
                        vader_fn_t* _a37_fnobj = (vader_fn_t*) l1;
                        ((vader_fn_erased_sig_1_t) _a37_fnobj->code)(_a37_fnobj->env, vader_box_i32(246u, ((vader_struct_vader_midir_InstrCellSet_t*) t0)->f_cell));
                        t0 = l0.payload.obj;
                        vader_fn_t* _a38_fnobj = (vader_fn_t*) l1;
                        ((vader_fn_erased_sig_1_t) _a38_fnobj->code)(_a38_fnobj->env, vader_box_i32(246u, ((vader_struct_vader_midir_InstrCellSet_t*) t0)->f_value));
                    } else if (l0.tag == 961u) {
                        t0 = l0.payload.obj;
                        vader_fn_t* _a39_fnobj = (vader_fn_t*) l1;
                        ((vader_fn_erased_sig_1_t) _a39_fnobj->code)(_a39_fnobj->env, vader_box_i32(246u, ((vader_struct_vader_midir_InstrMakeClosure_t*) t0)->f_env));
                    } else if (l0.tag == 960u) {
                        t0 = l0.payload.obj;
                        l2 = ((vader_struct_vader_midir_InstrIntrinsic_t*) t0)->f_args;
                        l3 = ((vader_array_t*) l2)->length;
                        l4 = (size_t) 0;
                        while ((l4 < l3)) {
                            vader_array_t* _a40_slotarr = ((vader_array_t*) l2);
                            VADER_ARRAY_RESOLVE_BUF(_a40_slotarr)
                            VADER_ARRAY_CHECK_INDEX(_a40_slotarr, l4)
                            t1 = ((int32_t*) _a40_slotarr->buf->slots)[_a40_slotarr->offset + (size_t) l4];
                            vader_fn_t* _a41_fnobj = (vader_fn_t*) l1;
                            ((vader_fn_erased_sig_1_t) _a41_fnobj->code)(_a41_fnobj->env, vader_box_i32(246u, t1));
                            t2 = (l4 + INT64_C(1));
                            l4 = (size_t) (int64_t) t2;
                        }
                    } else if (l0.tag == 955u) {
                        t0 = l0.payload.obj;
                        vader_fn_t* _a42_fnobj = (vader_fn_t*) l1;
                        ((vader_fn_erased_sig_1_t) _a42_fnobj->code)(_a42_fnobj->env, vader_box_i32(246u, ((vader_struct_vader_midir_InstrDeferPush_t*) t0)->f_value));
                    } else if (!(l0.tag == 954u)) {
                        vader_unreachable("non-exhaustive match (T3013 should have caught this)");
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
        vader_obj_header_init(_a0_obj, 916u);
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
    vader_obj_header_init(_a1_obj, 981u);
    _a1_obj->f_span = ((vader_struct_vader_midir_MutableBlock_t*) l0)->f_span;
    _a1_obj->f_reason = 2001u;
    l3 = (void*) _a1_obj;
    l4 = ((vader_struct_vader_midir_MutableBlock_t*) l0)->f_span;
    vader_struct_vader_midir_BasicBlock_t* _a2_obj = (vader_struct_vader_midir_BasicBlock_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_BasicBlock_t));
    vader_obj_header_init(_a2_obj, 916u);
    _a2_obj->f_id = l1;
    _a2_obj->f_instructions = l2;
    _a2_obj->f_terminator = vader_ref_box(l3);
    _a2_obj->f_span = l4;
    t0 = (void*) _a2_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static int32_t vader_midir_fresh_tmp(void* l0, vader_string_t l1, vader_box_t l2) {
    vader_string_t l3 = 0;
    size_t l4;
    void* l5 = NULL;
    uint64_t l6;
    size_t t0;
    int64_t t1;
    int32_t t2;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[2] = { &l0, &l5 };
    vader_string_t* gc_atom_roots[2] = { &l1, &l3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = l1;
    l4 = vader_host_std_core_byte_len(l3);
    l5 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(22) + l4));
    l4 = (size_t) 0;
    l4 = std_core_write_string_at(l5, l4, 189u);
    l4 = std_core_write_string_at(l5, l4, l3);
    l4 = std_core_write_string_at(l5, l4, 803u);
    t0 = ((vader_array_t*) ((vader_struct_vader_midir_FnCtx_t*) l0)->f_locals)->length;
    t1 = ((int64_t) (size_t) t0);
    l6 = (uint64_t) (int64_t) t1;
    l4 = std_core_write_unsigned(l5, l4, l6);
    l3 = std_core_finish_buffer(l5, l4);
    t2 = vader_midir_declare_local(l0, l3, l2, vader_box_obj(0u, NULL));
    { int32_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_midir_goes_on_or_out(void* l0, void* l1, void* l2, int32_t l3) {
    int32_t l4, l11, l12;
    size_t l5, l9, l10;
    void* l6;
    void* l7;
    void* l8;
    void* l13;
    bool l14, l15;
    vader_box_t l16;
    int64_t t0;
    bool t1;
    size_t t2;
    void* t3;
    l4 = -(INT32_C(1));
    l5 = (size_t) 0;
    l6 = l1;
    l7 = ((vader_struct_std_collections_MutableMap__i32__MutableSet_i32__t*) l6)->f_ekeys;
    l8 = ((vader_struct_std_collections_MutableMap__i32__MutableSet_i32__t*) l6)->f_evals;
    l9 = ((vader_struct_std_collections_MutableMap__i32__MutableSet_i32__t*) l6)->f_size;
    l10 = (size_t) 0;
    while (!((l10 >= l9))) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l10)
        l11 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l10];
        vader_array_t* _a1_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l10)
        l6 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l10);
        l12 = l11;
        l13 = l6;
        t0 = (l10 + INT64_C(1));
        l10 = (size_t) (int64_t) t0;
        t1 = vader_midir_holds_all(l13, l2);
        if (t1) {
            if ((l4 < INT32_C(0))) {
                l15 = true;
            } else {
                t2 = std_collections_len__i32(l13);
                l15 = (t2 < l5);
            }
            l14 = l15;
        } else {
            l14 = false;
        }
        if (!(l14)) {
            continue;
        }
        l4 = l12;
        l5 = std_collections_len__i32(l13);
    }
    l16 = std_collections_MutableMap_Index_at__i32__Any(l1, l4);
    if (l16.tag == 0u) {
        return false;
    }
    l6 = l16.payload.obj;
    t1 = vader_midir_BlockId_Equals_equals(l3, l4);
    if (t1) {
        return true;
    }
    l7 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_blocks;
    vader_array_t* _a2_slotarr = ((vader_array_t*) l7);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
    t3 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
    l16 = ((vader_struct_vader_midir_BasicBlock_t*) t3)->f_terminator;
    if (l16.tag == 979u) {
        t3 = l16.payload.obj;
        t1 = vader_midir_BlockId_Equals_equals(((vader_struct_vader_midir_TermCondBranch_t*) t3)->f_then_block, l3);
        if (t1) {
            l15 = true;
        } else {
            t3 = l16.payload.obj;
            l15 = vader_midir_BlockId_Equals_equals(((vader_struct_vader_midir_TermCondBranch_t*) t3)->f_else_block, l3);
        }
        l14 = l15;
    } else {
        l14 = false;
    }
    if (l14) {
        t1 = std_collections_MutableSet_Contains_contains__i32(l6, l3);
        return !(t1);
    }
    return false;
}

static bool vader_midir_has_receiver(void* l0, int32_t l1) {
    void* l2;
    size_t l3, l4;
    void* t0;
    int32_t t1;
    int64_t t2;
    l2 = ((vader_struct_vader_bytecode_VtableRow_t*) l0)->f_entries;
    l3 = ((vader_array_t*) l2)->length;
    l4 = (size_t) 0;
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        t1 = ((vader_struct_vader_bytecode_VtableEntry_t*) t0)->f_receiver_type_index;
        if (t1 == l1) {
            return true;
        }
        t2 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t2;
    }
    return false;
}

static bool vader_midir_holds_all(void* l0, void* l1) {
    void* l2;
    size_t l3, l4;
    int32_t l5;
    bool t0;
    int64_t t1;
    l2 = l1;
    l3 = ((vader_array_t*) l2)->length;
    l4 = (size_t) 0;
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l5 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l4];
        t0 = std_collections_MutableSet_Contains_contains__i32(l0, l5);
        if (!(t0)) {
            return false;
        }
        t1 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t1;
    }
    return true;
}

static void* vader_midir_import_call_target(void* l0, int32_t l1) {
    void* l2 = NULL;
    void* l6 = NULL;
    size_t l3;
    vader_box_t l4 = vader_box_null(), l5 = vader_box_null();
    int64_t t0;
    bool t1;
    vader_string_t t2 = 0;
    void* t3 = NULL;
    vader_box_t* gc_roots[2] = { &l4, &l5 };
    void** gc_raw_roots[4] = { &l0, &l2, &l6, &t3 };
    vader_string_t* gc_atom_roots[1] = { &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_imports;
    t0 = ((int64_t) (int32_t) l1);
    l3 = (size_t) (int64_t) t0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
    l2 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
    t1 = ((vader_struct_vader_bytecode_BcImport_t*) l2)->f_is_extern;
    if (t1) {
        l4 = vader_box_obj(0u, NULL);
    } else {
        t2 = ((vader_struct_vader_bytecode_BcImport_t*) l2)->f_mangled_name;
        l4 = vader_bytecode_intrinsic_op_for_mangled(t2);
    }
    if (l4.tag == 0u) {
        vader_struct_vader_bytecode_CallImport_t* _a1_obj = (vader_struct_vader_bytecode_CallImport_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_CallImport_t));
        vader_obj_header_init(_a1_obj, 584u);
        _a1_obj->f_index = l1;
        t3 = (void*) _a1_obj;
        l5 = vader_ref_box(t3);
        l6 = ((vader_struct_vader_bytecode_BcImport_t*) l2)->f_signature;
        vader_struct_vader_midir_DirectCallTarget_t* _a2_obj = (vader_struct_vader_midir_DirectCallTarget_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_DirectCallTarget_t));
        vader_obj_header_init(_a2_obj, 932u);
        _a2_obj->f_op = l5;
        _a2_obj->f_signature = l6;
        t3 = (void*) _a2_obj;
        { void* __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l5 = l4;
    l6 = ((vader_struct_vader_bytecode_BcImport_t*) l2)->f_signature;
    vader_struct_vader_midir_DirectCallTarget_t* _a3_obj = (vader_struct_vader_midir_DirectCallTarget_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_DirectCallTarget_t));
    vader_obj_header_init(_a3_obj, 932u);
    _a3_obj->f_op = l5;
    _a3_obj->f_signature = l6;
    t3 = (void*) _a3_obj;
    { void* __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_midir_instruction_has_side_effect(vader_box_t l0) {
    return (l0.tag == 942u || l0.tag == 943u || l0.tag == 946u || l0.tag == 947u || l0.tag == 951u || l0.tag == 957u || l0.tag == 960u || l0.tag == 968u);
}

static void vader_midir_intern_data_value_strings(vader_box_t l0, void* l1) {
    void* l2 = NULL;
    size_t l3, l4;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    vader_box_t t2 = vader_box_null();
    int64_t t3;
    vader_box_t* gc_roots[2] = { &l0, &t2 };
    void** gc_raw_roots[3] = { &l1, &l2, &t0 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l0.tag == 565u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_bytecode_BcValStr_t*) t0)->f_value;
        vader_bytecode_intern_string(t1, l1);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 566u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_bytecode_BcValStruct_t*) t0)->f_fields;
        l3 = ((vader_array_t*) l2)->length;
        l4 = (size_t) 0;
        while ((l4 < l3)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
            t2 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
            vader_midir_intern_data_value_strings(t2, l1);
            t3 = (l4 + INT64_C(1));
            l4 = (size_t) (int64_t) t3;
        }
    } else if (l0.tag == 563u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_bytecode_BcValArray_t*) t0)->f_elements;
        l3 = ((vader_array_t*) l2)->length;
        l4 = (size_t) 0;
        while ((l4 < l3)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
            t2 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
            vader_midir_intern_data_value_strings(t2, l1);
            t3 = (l4 + INT64_C(1));
            l4 = (size_t) (int64_t) t3;
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static int32_t vader_midir_intern_string_pool(void* l0, vader_string_t l1) {
    vader_box_t l2 = vader_box_null();
    int32_t l3;
    size_t t0;
    int32_t t1;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = std_collections_MutableMap_Index_at__string__i32(((vader_struct_vader_midir_ProjectCtx_t*) l0)->f_string_index, l1);
    if (!(l2.tag == 246u)) {
        t0 = ((vader_array_t*) ((vader_struct_vader_midir_ProjectCtx_t*) l0)->f_strings)->length;
        l3 = ((int32_t) (size_t) t0);
        vader_array_push((vader_array_t*) ((vader_struct_vader_midir_ProjectCtx_t*) l0)->f_strings, vader_box_string(243u, l1));
        std_collections_MutableMap_IndexSet_set_at__string__i32(((vader_struct_vader_midir_ProjectCtx_t*) l0)->f_string_index, l1, l3);
        { int32_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = ((int32_t) l2.payload.i);
    { int32_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static int32_t vader_midir_intersect_dom_tree(int32_t l0, int32_t l1, void* l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    int32_t l6, l7, l8, l9, l10, l11;
    void* t0 = NULL;
    bool t1;
    void** gc_raw_roots[5] = { &l2, &l3, &l4, &l5, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(14u, 0u, 7u, 246u);
    l3 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(11u, 0u, 12u, 241u);
    l4 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(14u, 0u, 7u, 246u);
    l5 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__i32__bool_t* _a3_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
    vader_obj_header_init(_a3_obj, 328u);
    _a3_obj->f_ekeys = l3;
    _a3_obj->f_evals = l4;
    _a3_obj->f_index = l5;
    _a3_obj->f_mask = (size_t) 0;
    _a3_obj->f_size = (size_t) 0;
    _a3_obj->f_tombs = (size_t) 0;
    t0 = (void*) _a3_obj;
    vader_struct_std_collections_MutableSet__i32_t* _a4_obj = (vader_struct_std_collections_MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i32_t));
    vader_obj_header_init(_a4_obj, 425u);
    _a4_obj->f_inner = t0;
    l3 = (void*) _a4_obj;
    l6 = l0;
    for (;;) {
        l7 = -(INT32_C(1));
        t1 = vader_midir_BlockId_Equals_equals(l6, l7);
        if (!(t1)) {
            l8 = l6;
            t1 = std_collections_MutableSet_Contains_contains__i32(l3, l8);
            if (t1) break;
            l9 = l6;
            std_collections_add__i32(l3, l9);
            l10 = l6;
            vader_array_t* _a5_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l10)
            l11 = ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l10];
            t1 = vader_midir_BlockId_Equals_equals(l11, l6);
            if (t1) break;
            l6 = l11;
            continue;
        }
        break;
    }
    l6 = l1;
    for (;;) {
        l7 = -(INT32_C(1));
        t1 = vader_midir_BlockId_Equals_equals(l6, l7);
        if (!(t1)) {
            l8 = l6;
            t1 = std_collections_MutableSet_Contains_contains__i32(l3, l8);
            if (t1) {
                { int32_t __vret = l6; vader_gc_top = gc_frame.prev; return __vret; }
            }
            l9 = l6;
            vader_array_t* _a6_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l9)
            l10 = ((int32_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l9];
            t1 = vader_midir_BlockId_Equals_equals(l10, l6);
            if (t1) break;
            l6 = l10;
            continue;
        }
        break;
    }
    { int32_t __vret = -(INT32_C(1)); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir_intrinsic_op_for_name(vader_string_t l0) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l0 == 2184u) {
        vader_struct_vader_bytecode_SizeOfType_t* _a0_obj = (vader_struct_vader_bytecode_SizeOfType_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_SizeOfType_t));
        vader_obj_header_init(_a0_obj, 677u);
        t0 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == 1297u) {
        vader_struct_vader_bytecode_ArrayRepeat_t* _a1_obj = (vader_struct_vader_bytecode_ArrayRepeat_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_ArrayRepeat_t));
        vader_obj_header_init(_a1_obj, 544u);
        t0 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == 1292u) {
        vader_struct_vader_bytecode_ArrayPushAll_t* _a2_obj = (vader_struct_vader_bytecode_ArrayPushAll_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_ArrayPushAll_t));
        vader_obj_header_init(_a2_obj, 542u);
        t0 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == 1279u) {
        vader_struct_vader_bytecode_ArrayCopy_t* _a3_obj = (vader_struct_vader_bytecode_ArrayCopy_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_ArrayCopy_t));
        vader_obj_header_init(_a3_obj, 537u);
        t0 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == 1295u) {
        vader_struct_vader_bytecode_ArrayRemoveLast_t* _a4_obj = (vader_struct_vader_bytecode_ArrayRemoveLast_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_ArrayRemoveLast_t));
        vader_obj_header_init(_a4_obj, 543u);
        t0 = (void*) _a4_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l0 == 1277u)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    vader_struct_vader_bytecode_ArrayClear_t* _a5_obj = (vader_struct_vader_bytecode_ArrayClear_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_ArrayClear_t));
    vader_obj_header_init(_a5_obj, 536u);
    t0 = (void*) _a5_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_midir_is_dest_passing_shape(vader_box_t l0) {
    void* t0;
    bool t1;
    if ((l0.tag == 859u || l0.tag == 878u)) {
        return true;
    }
    if (!(l0.tag == 858u)) {
        return false;
    }
    t0 = l0.payload.obj;
    t1 = vader_midir_is_short_circuit_op(((vader_struct_vader_lower_LoweredBinary_t*) t0)->f_op);
    return t1;
}

static bool vader_midir_is_mutable_slot(vader_box_t l0) {
    bool t0;
    vader_box_t* gc_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 0u, gc_roots, NULL, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_types_type_grants_mutation(l0);
    { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_midir_is_scalar_class(uint8_t l0) {
    bool l1;
    if (l0 == INT32_C(18)) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(19);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(16);
    }
    if (l1) {
        return !(true);
    }
    return !(l0 == INT32_C(15));
}

static bool vader_midir_is_short_circuit_op(uint8_t l0) {
    if (l0 == INT32_C(10)) {
        return true;
    }
    return l0 == INT32_C(11);
}

bool vader_midir_is_union_row(void* l0, int32_t l1) {
    void* l2;
    size_t l3;
    int64_t t0;
    vader_box_t t1;
    l2 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_types;
    t0 = ((int64_t) (int32_t) l1);
    l3 = (size_t) (int64_t) t0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
    t1 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
    return t1.tag == 562u;
}

bool vader_midir_is_union_slot(vader_box_t l0) {
    bool l1;
    void* t0;
    if (l0.tag == 1093u) {
        return true;
    }
    if (l0.tag == 1078u) {
        t0 = l0.payload.obj;
        l1 = vader_midir_is_union_slot(((vader_struct_vader_types_DistinctType_t*) t0)->f_backing);
    } else {
        l1 = false;
    }
    return l1;
}

static size_t vader_midir_last_empty_stack_point(void* l0, int32_t l1) {
    void* l2;
    int32_t l3;
    size_t l4, l5;
    int64_t l6;
    void* t0;
    int64_t t1;
    bool t2;
    l2 = ((vader_struct_vader_midir_CFGFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_fn_)->f_blocks;
    l3 = l1;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
    t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
    l4 = ((vader_array_t*) ((vader_struct_vader_midir_BasicBlock_t*) t0)->f_instructions)->length;
    while ((l4 > INT64_C(0))) {
        l2 = ((vader_struct_vader_midir_ScheduleHints_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_hints)->f_skip_set;
        t1 = (l4 - INT64_C(1));
        l5 = (size_t) (int64_t) t1;
        l6 = vader_midir_pos_key(l1, l5);
        t2 = std_collections_MutableSet_Contains_contains__i64(l2, l6);
        if (!(t2)) {
            break;
        }
        t1 = (l4 - INT64_C(1));
        l4 = (size_t) (int64_t) t1;
    }
    return l4;
}

static bool vader_midir_last_op_exits(void* l0) {
    void* l1;
    size_t l2;
    size_t t0;
    int64_t t1;
    vader_box_t t2;
    l1 = ((vader_struct_vader_bytecode_BcFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_slot)->f_body;
    t0 = ((vader_array_t*) l1)->length;
    if (!(t0 == INT64_C(0))) {
        t0 = ((vader_array_t*) l1)->length;
        t1 = (t0 - INT64_C(1));
        l2 = (size_t) (int64_t) t1;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
        t2 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
        return (t2.tag == 576u || t2.tag == 675u || t2.tag == 676u);
    }
    return false;
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
        t2 = vader_box_bool(241u, ((uint8_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l6]);
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
    l3 = std_collections_MutableMap_Index_at__i32__Any(l0, l1);
    if (l3.tag == 0u) {
        return false;
    }
    t0 = l3.payload.obj;
    t1 = std_collections_MutableSet_Contains_contains__i32(t0, l2);
    return !(t1);
}

static int32_t vader_midir_loop_exit(void* l0, void* l1, int32_t l2) {
    void* l3 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    void* l13 = NULL;
    int32_t l4, l6, l11, l12, l14, l15;
    vader_box_t l5 = vader_box_null();
    size_t l7, l8;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    bool t2;
    int64_t t3;
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
    if (!(l5.tag == 979u)) {
        { int32_t __vret = -(INT32_C(1)); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l5.payload.obj;
    l4 = ((vader_struct_vader_midir_TermCondBranch_t*) t0)->f_else_block;
    t0 = l5.payload.obj;
    l6 = ((vader_struct_vader_midir_TermCondBranch_t*) t0)->f_then_block;
    vader_array_t* _a1_arr = vader_array_new(14u, 2u, 7u, 246u);
    ((int32_t*) _a1_arr->buf->slots)[_a1_arr->offset + 1u] = (int32_t) l6;
    ((int32_t*) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = (int32_t) l4;
    l3 = (void*) _a1_arr;
    l7 = ((vader_array_t*) l3)->length;
    l8 = (size_t) 0;
    while ((l8 < l7)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        l4 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l8];
        l9 = ((vader_struct_vader_midir_StructureShape_t*) l1)->f_merge;
        l6 = l4;
        vader_array_t* _a3_slotarr = ((vader_array_t*) l9);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l6)
        t1 = vader_box_bool(241u, ((uint8_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l6]);
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
        t3 = (l8 + INT64_C(1));
        l8 = (size_t) (int64_t) t3;
    }
    { int32_t __vret = -(INT32_C(1)); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir_lowered_to_bc_value(vader_box_t l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    size_t l3, l4;
    vader_box_t l5 = vader_box_null();
    vader_string_t l6 = 0;
    uint8_t l7;
    uint64_t l8;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    int64_t t2;
    int32_t t3;
    vader_box_t t4 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l0, &l5, &t4 };
    void** gc_raw_roots[3] = { &l1, &l2, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l6, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l0.tag == 891u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_lower_LoweredStringLit_t*) t0)->f_value;
        vader_struct_vader_bytecode_BcValStr_t* _a0_obj = (vader_struct_vader_bytecode_BcValStr_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcValStr_t));
        vader_obj_header_init(_a0_obj, 565u);
        _a0_obj->f_value = t1;
        t0 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 895u) {
        vader_array_t* _a1_arr = vader_array_new(190u, 0u, 13u, 1348u);
        l1 = (void*) _a1_arr;
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_lower_LoweredStructLit_t*) t0)->f_fields;
        l3 = ((vader_array_t*) l2)->length;
        l4 = (size_t) 0;
        while ((l4 < l3)) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
            t0 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
            l5 = vader_midir_lowered_to_bc_value(((vader_struct_vader_lower_LoweredStructLitField_t*) t0)->f_value);
            vader_array_push((vader_array_t*) l1, l5);
            t2 = (l4 + INT64_C(1));
            l4 = (size_t) (int64_t) t2;
        }
        t0 = l0.payload.obj;
        t3 = vader_midir_struct_symbol_id(((vader_struct_vader_lower_LoweredStructLit_t*) t0)->f_type);
        vader_struct_vader_bytecode_BcValStruct_t* _a3_obj = (vader_struct_vader_bytecode_BcValStruct_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcValStruct_t));
        vader_obj_header_init(_a3_obj, 566u);
        _a3_obj->f_symbol_id = t3;
        _a3_obj->f_fields = l1;
        t0 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l0.tag == 853u)) {
        t4 = vader_lower_type_of(l0);
        l6 = vader_types_display_type_key(t4);
        l7 = vader_bytecode_array_kind_from_name(l6);
        l8 = vader_midir_bc_value_bits(l0, l6);
        vader_struct_vader_bytecode_BcValPrim_t* _a4_obj = (vader_struct_vader_bytecode_BcValPrim_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcValPrim_t));
        vader_obj_header_init(_a4_obj, 564u);
        _a4_obj->f_kind = l7;
        _a4_obj->f_bits = l8;
        t0 = (void*) _a4_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a5_arr = vader_array_new(190u, 0u, 13u, 1348u);
    l1 = (void*) _a5_arr;
    t0 = l0.payload.obj;
    l2 = ((vader_struct_vader_lower_LoweredArrayLit_t*) t0)->f_elements;
    l3 = ((vader_array_t*) l2)->length;
    l4 = (size_t) 0;
    while ((l4 < l3)) {
        vader_array_t* _a6_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l4)
        t4 = vader_array_ref_load_box(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l4);
        l5 = vader_midir_lowered_to_bc_value(t4);
        vader_array_push((vader_array_t*) l1, l5);
        t2 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t2;
    }
    t0 = l0.payload.obj;
    t1 = vader_midir_array_element_name(((vader_struct_vader_lower_LoweredArrayLit_t*) t0)->f_type);
    vader_struct_vader_bytecode_BcValArray_t* _a7_obj = (vader_struct_vader_bytecode_BcValArray_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcValArray_t));
    vader_obj_header_init(_a7_obj, 563u);
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
    size_t l3, l4;
    vader_string_t l6 = 0;
    vader_string_t l11 = 0;
    vader_string_t l14 = 0;
    vader_string_t l15 = 0;
    vader_box_t l8 = vader_box_null();
    int32_t l9;
    bool l12, l13;
    int64_t t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &l8 };
    void** gc_raw_roots[7] = { &l0, &l1, &l2, &l5, &l7, &l10, &t1 };
    vader_string_t* gc_atom_roots[4] = { &l6, &l11, &l14, &l15 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = vader_midir_fn_metadata(l0);
    vader_array_t* _a0_arr = vader_array_new(107u, 0u, 13u, 921u);
    l2 = (void*) _a0_arr;
    l3 = ((vader_array_t*) ((vader_struct_vader_lower_LoweredFnDecl_t*) l0)->f_params)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l2, (size_t) l3);
    l2 = (void*) _a1_arr;
    l3 = (size_t) 0;
    l4 = ((vader_array_t*) ((vader_struct_vader_lower_LoweredFnDecl_t*) l0)->f_params)->length;
    while ((l3 < l4)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_lower_LoweredFnDecl_t*) l0)->f_params);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
        l5 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l3);
        l6 = ((vader_struct_vader_lower_LoweredParam_t*) l5)->f_name;
        l7 = ((vader_struct_vader_lower_LoweredParam_t*) l5)->f_symbol;
        l8 = ((vader_struct_vader_lower_LoweredParam_t*) l5)->f_type;
        l9 = ((int32_t) (size_t) l3);
        vader_struct_vader_midir_CFGParam_t* _a3_obj = (vader_struct_vader_midir_CFGParam_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_CFGParam_t));
        vader_obj_header_init(_a3_obj, 921u);
        _a3_obj->f_name = l6;
        _a3_obj->f_symbol = l7;
        _a3_obj->f_type = l8;
        _a3_obj->f_local = l9;
        l10 = (void*) _a3_obj;
        vader_array_push((vader_array_t*) l2, vader_ref_box(l10));
        t0 = (l3 + INT64_C(1));
        l3 = (size_t) (int64_t) t0;
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
    vader_obj_header_init(_a4_obj, 917u);
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
    t1 = (void*) _a4_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_midir_make_struct_decl(void* l0) {
    void* l1 = NULL;
    void* l3 = NULL;
    void* l5 = NULL;
    void* l8 = NULL;
    size_t l2, l4;
    vader_string_t l6 = 0;
    vader_box_t l7 = vader_box_null();
    int64_t t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &l7 };
    void** gc_raw_roots[6] = { &l0, &l1, &l3, &l5, &l8, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l6 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(109u, 0u, 13u, 924u);
    l1 = (void*) _a0_arr;
    l2 = ((vader_array_t*) ((vader_struct_vader_lower_LoweredStructDecl_t*) l0)->f_fields)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l1, (size_t) l2);
    l1 = (void*) _a1_arr;
    l3 = ((vader_struct_vader_lower_LoweredStructDecl_t*) l0)->f_fields;
    l2 = ((vader_array_t*) l3)->length;
    l4 = (size_t) 0;
    while ((l4 < l2)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        l5 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
        l6 = ((vader_struct_vader_lower_LoweredStructField_t*) l5)->f_name;
        l7 = ((vader_struct_vader_lower_LoweredStructField_t*) l5)->f_type;
        vader_struct_vader_midir_CFGStructField_t* _a3_obj = (vader_struct_vader_midir_CFGStructField_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_CFGStructField_t));
        vader_obj_header_init(_a3_obj, 924u);
        _a3_obj->f_name = l6;
        _a3_obj->f_type = l7;
        l8 = (void*) _a3_obj;
        vader_array_push((vader_array_t*) l1, vader_ref_box(l8));
        t0 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t0;
    }
    l6 = ((vader_struct_vader_lower_LoweredStructDecl_t*) l0)->f_mangled;
    l3 = ((vader_struct_vader_lower_LoweredStructDecl_t*) l0)->f_origin;
    vader_struct_vader_midir_CFGStructDecl_t* _a4_obj = (vader_struct_vader_midir_CFGStructDecl_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_CFGStructDecl_t));
    vader_obj_header_init(_a4_obj, 923u);
    _a4_obj->f_mangled = l6;
    _a4_obj->f_fields = l1;
    _a4_obj->f_origin = l3;
    t1 = (void*) _a4_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_midir_move_retags(void* l0, void* l1) {
    size_t l2;
    int64_t t0;
    void* t1;
    bool t2;
    uint8_t t3;
    t0 = ((int64_t) (int32_t) ((vader_struct_vader_midir_InstrMove_t*) l1)->f_dst);
    l2 = (size_t) (int64_t) t0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
    t1 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
    t2 = vader_midir_is_union_slot(((vader_struct_vader_midir_CFGLocal_t*) t1)->f_type);
    if (t2) {
        t0 = ((int64_t) (int32_t) ((vader_struct_vader_midir_InstrMove_t*) l1)->f_src);
        l2 = (size_t) (int64_t) t0;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l2)
        t1 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l2);
        t3 = vader_bytecode_val_type_of_type(((vader_struct_vader_midir_CFGLocal_t*) t1)->f_type);
        t2 = vader_midir_is_scalar_class(t3);
        return t2;
    }
    return false;
}

static vader_box_t vader_midir_multi_dsts(vader_box_t l0) {
    void* t0;
    if (!(l0.tag == 946u)) {
        return vader_box_obj(0u, NULL);
    }
    t0 = l0.payload.obj;
    return vader_ref_box(((vader_struct_vader_midir_InstrCall_t*) t0)->f_dsts);
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
    size_t l6, l7, l9, l10, l17, l19, l22, l23;
    int32_t l8, l11, l18, l20, l24;
    bool t0;
    int64_t t1;
    size_t t2;
    void* t3 = NULL;
    void** gc_raw_roots[13] = {
        &l0, &l1, &l2, &l3, &l4, &l5, &l12, &l13, &l14, &l15, &l16, &l21, &t3,
    };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 13u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(14u, 0u, 7u, 246u);
    l3 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(21u, 0u, 0u, 254u);
    l4 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(14u, 0u, 7u, 246u);
    l5 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__i32__MutableSet_Any__t* _a3_obj = (vader_struct_std_collections_MutableMap__i32__MutableSet_Any__t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__MutableSet_Any__t));
    vader_obj_header_init(_a3_obj, 315u);
    _a3_obj->f_ekeys = l3;
    _a3_obj->f_evals = l4;
    _a3_obj->f_index = l5;
    _a3_obj->f_mask = (size_t) 0;
    _a3_obj->f_size = (size_t) 0;
    _a3_obj->f_tombs = (size_t) 0;
    l3 = (void*) _a3_obj;
    l6 = (size_t) 0;
    l7 = ((vader_array_t*) ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_blocks)->length;
    while ((l6 < l7)) {
        l8 = ((int32_t) (size_t) l6);
        vader_array_t* _a4_arr = vader_array_new(14u, 0u, 7u, 246u);
        l4 = (void*) _a4_arr;
        vader_array_t* _a5_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l6)
        l5 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l6);
        l9 = ((vader_array_t*) l5)->length;
        l10 = (size_t) 0;
        vader_array_t* _pc37_hdr = (vader_array_t*) l4;
        size_t _pc37_len = _pc37_hdr->length;
        size_t _pc37_cap = (_pc37_hdr->offset == 0 && !vader_array_is_borrowed(_pc37_hdr) && _pc37_hdr->length >= _pc37_hdr->buf->length) ? _pc37_hdr->capacity : (size_t) 0;
        void* _pc37_slots = _pc37_hdr->buf->slots;
        for (;;) {
            if ((l10 < l9)) {
                vader_array_t* _a6_slotarr = ((vader_array_t*) l5);
                VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l10)
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
                t1 = (l10 + INT64_C(1));
                l10 = (size_t) (int64_t) t1;
                continue;
            }
            _pc37_hdr->length = _pc37_len;
            if (_pc37_hdr->buf->length < _pc37_len) {
                _pc37_hdr->buf->length = _pc37_len;
            }
            break;
        }
        t2 = ((vader_array_t*) l4)->length;
        if (t2 == INT64_C(0)) {
            t1 = (l6 + INT64_C(1));
            l6 = (size_t) (int64_t) t1;
            continue;
        }
        vader_array_t* _a7_arr = vader_array_new(14u, 0u, 7u, 246u);
        l12 = (void*) _a7_arr;
        vader_array_t* _a8_arr = vader_array_new(11u, 0u, 12u, 241u);
        l13 = (void*) _a8_arr;
        vader_array_t* _a9_arr = vader_array_new(14u, 0u, 7u, 246u);
        l14 = (void*) _a9_arr;
        vader_struct_std_collections_MutableMap__i32__bool_t* _a10_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
        vader_obj_header_init(_a10_obj, 328u);
        _a10_obj->f_ekeys = l12;
        _a10_obj->f_evals = l13;
        _a10_obj->f_index = l14;
        _a10_obj->f_mask = (size_t) 0;
        _a10_obj->f_size = (size_t) 0;
        _a10_obj->f_tombs = (size_t) 0;
        t3 = (void*) _a10_obj;
        vader_struct_std_collections_MutableSet__i32_t* _a11_obj = (vader_struct_std_collections_MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i32_t));
        vader_obj_header_init(_a11_obj, 425u);
        _a11_obj->f_inner = t3;
        l15 = (void*) _a11_obj;
        std_collections_add__i32(l15, l8);
        l16 = std_iter_clone__vader_midir_BlockId(l4);
        for (;;) {
            t2 = ((vader_array_t*) l16)->length;
            if ((t2 > INT64_C(0))) {
                t2 = ((vader_array_t*) l16)->length;
                t1 = (t2 - INT64_C(1));
                l17 = (size_t) (int64_t) t1;
                vader_array_t* _a12_slotarr = ((vader_array_t*) l16);
                VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a12_slotarr, l17)
                l18 = ((int32_t*) _a12_slotarr->buf->slots)[_a12_slotarr->offset + (size_t) l17];
                t2 = ((vader_array_t*) l16)->length;
                t1 = (t2 - INT64_C(1));
                l19 = (size_t) (int64_t) t1;
                vader_array_t* _a13_arr = vader_array_slice((vader_array_t*) l16, (size_t) INT64_C(0), (size_t) l19);
                l16 = (void*) _a13_arr;
                t0 = std_collections_MutableSet_Contains_contains__i32(l15, l18);
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
                l23 = (size_t) 0;
                while ((l23 < l22)) {
                    vader_array_t* _a15_slotarr = ((vader_array_t*) l21);
                    VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a15_slotarr, l23)
                    l24 = ((int32_t*) _a15_slotarr->buf->slots)[_a15_slotarr->offset + (size_t) l23];
                    t0 = vader_midir_BlockId_Equals_equals(l24, l8);
                    if (!(t0)) {
                        vader_array_push_i32((vader_array_t*) l16, l24);
                    }
                    t1 = (l23 + INT64_C(1));
                    l23 = (size_t) (int64_t) t1;
                }
                continue;
            }
            break;
        }
        std_collections_MutableMap_IndexSet_set_at__i32__Any(l3, l8, vader_ref_box(l15));
        t1 = (l6 + INT64_C(1));
        l6 = (size_t) (int64_t) t1;
    }
    { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_midir_needs_ref_cast(vader_box_t l0) {
    void* t0;
    vader_string_t t1;
    if (!(l0.tag == 1086u)) {
        return false;
    }
    t0 = l0.payload.obj;
    t1 = ((vader_struct_vader_types_PrimitiveType_t*) t0)->f_name;
    return t1 != 2604u;
}

static int32_t vader_midir_new_block(void* l0, void* l1) {
    int32_t l2;
    void* l3 = NULL;
    void* l4 = NULL;
    size_t t0;
    void** gc_raw_roots[4] = { &l0, &l1, &l3, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_vader_midir_FnCtx_t*) l0)->f_blocks)->length;
    l2 = ((int32_t) (size_t) t0);
    l3 = ((vader_struct_vader_midir_FnCtx_t*) l0)->f_blocks;
    vader_array_t* _a0_arr = vader_array_new(203u, 0u, 13u, 1503u);
    l4 = (void*) _a0_arr;
    vader_struct_vader_midir_MutableBlock_t* _a1_obj = (vader_struct_vader_midir_MutableBlock_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_MutableBlock_t));
    vader_obj_header_init(_a1_obj, 971u);
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
    void* l8 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    void* l15 = NULL;
    void* l16 = NULL;
    size_t l6, l7, l9, l10, l17, l18;
    vader_box_t l11 = vader_box_null();
    int32_t l19;
    vader_box_t t0 = vader_box_null();
    vader_string_t t1 = 0;
    int64_t t2;
    void* t3 = NULL;
    void* t4 = NULL;
    bool t5;
    size_t t6;
    vader_box_t* gc_roots[2] = { &l11, &t0 };
    void** gc_raw_roots[14] = {
        &l0, &l1, &l2, &l3, &l4, &l5, &l8, &l12, &l13, &l14, &l15, &l16, &t3, &t4,
    };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 14u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(14u, 0u, 7u, 246u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(21u, 0u, 0u, 254u);
    l3 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(14u, 0u, 7u, 246u);
    l4 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__i32__MutableSet_Any__t* _a3_obj = (vader_struct_std_collections_MutableMap__i32__MutableSet_Any__t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__MutableSet_Any__t));
    vader_obj_header_init(_a3_obj, 315u);
    _a3_obj->f_ekeys = l2;
    _a3_obj->f_evals = l3;
    _a3_obj->f_index = l4;
    _a3_obj->f_mask = (size_t) 0;
    _a3_obj->f_size = (size_t) 0;
    _a3_obj->f_tombs = (size_t) 0;
    l2 = (void*) _a3_obj;
    l3 = ((vader_struct_vader_lower_LoweredProject_t*) l0)->f_modules;
    l4 = ((vader_struct_std_collections_MutableMap__string__LoweredModule_t*) l3)->f_ekeys;
    l5 = ((vader_struct_std_collections_MutableMap__string__LoweredModule_t*) l3)->f_evals;
    l6 = ((vader_struct_std_collections_MutableMap__string__LoweredModule_t*) l3)->f_size;
    l7 = (size_t) 0;
    while (!((l7 >= l6))) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l7)
        t0 = vader_array_box_slots(_a4_slotarr->buf)[_a4_slotarr->offset + (size_t) l7];
        t1 = t0.payload.s;
        vader_array_t* _a5_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l7)
        l3 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l7);
        t2 = (l7 + INT64_C(1));
        l7 = (size_t) (int64_t) t2;
        l8 = ((vader_struct_vader_lower_LoweredModule_t*) l3)->f_decls;
        l9 = ((vader_array_t*) l8)->length;
        l10 = (size_t) 0;
        while ((l10 < l9)) {
            vader_array_t* _a6_slotarr = ((vader_array_t*) l8);
            VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l10)
            l11 = vader_array_ref_load_box(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l10);
            if (l11.tag == 876u) {
                t3 = l11.payload.obj;
                t4 = vader_midir_fn_metadata(t3);
                t5 = ((vader_struct_vader_midir_FnMetadata_t*) t4)->f_is_extern;
                if (t5) {
                    t3 = l11.payload.obj;
                    if (((vader_struct_vader_comptime_MonoEntry_t*) ((vader_struct_vader_lower_LoweredFnDecl_t*) t3)->f_origin)->f_symbol.tag == 1019u) {
                        t3 = l11.payload.obj;
                        l12 = ((vader_struct_vader_comptime_MonoEntry_t*) ((vader_struct_vader_lower_LoweredFnDecl_t*) t3)->f_origin)->f_symbol.payload.obj;
                        vader_array_t* _a7_arr = vader_array_new(20u, 0u, 4u, 253u);
                        l13 = (void*) _a7_arr;
                        vader_array_t* _a8_arr = vader_array_new(11u, 0u, 12u, 241u);
                        l14 = (void*) _a8_arr;
                        vader_array_t* _a9_arr = vader_array_new(14u, 0u, 7u, 246u);
                        l15 = (void*) _a9_arr;
                        vader_struct_std_collections_MutableMap__usize__bool_t* _a10_obj = (vader_struct_std_collections_MutableMap__usize__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__usize__bool_t));
                        vader_obj_header_init(_a10_obj, 421u);
                        _a10_obj->f_ekeys = l13;
                        _a10_obj->f_evals = l14;
                        _a10_obj->f_index = l15;
                        _a10_obj->f_mask = (size_t) 0;
                        _a10_obj->f_size = (size_t) 0;
                        _a10_obj->f_tombs = (size_t) 0;
                        t3 = (void*) _a10_obj;
                        vader_struct_std_collections_MutableSet__usize_t* _a11_obj = (vader_struct_std_collections_MutableSet__usize_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__usize_t));
                        vader_obj_header_init(_a11_obj, 429u);
                        _a11_obj->f_inner = t3;
                        l16 = (void*) _a11_obj;
                        l17 = (size_t) 0;
                        t3 = l11.payload.obj;
                        l18 = ((vader_array_t*) ((vader_struct_vader_lower_LoweredFnDecl_t*) t3)->f_params)->length;
                        while ((l17 < l18)) {
                            t3 = l11.payload.obj;
                            vader_array_t* _a12_slotarr = ((vader_array_t*) ((vader_struct_vader_lower_LoweredFnDecl_t*) t3)->f_params);
                            VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
                            VADER_ARRAY_CHECK_INDEX(_a12_slotarr, l17)
                            t3 = vader_array_ref_load_obj(_a12_slotarr->buf, _a12_slotarr->offset + (size_t) l17);
                            if (((vader_struct_vader_lower_LoweredParam_t*) t3)->f_type.tag == 1080u) {
                                std_collections_add__usize(l16, l17);
                            }
                            t2 = (l17 + INT64_C(1));
                            l17 = (size_t) (int64_t) t2;
                        }
                        t6 = std_collections_len__usize(l16);
                        if ((t6 > INT64_C(0))) {
                            l19 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l12)->f_id;
                            std_collections_MutableMap_IndexSet_set_at__i32__Any(l2, l19, vader_ref_box(l16));
                        }
                    }
                }
            }
            t2 = (l10 + INT64_C(1));
            l10 = (size_t) (int64_t) t2;
        }
    }
    vader_array_t* _a13_arr = vader_array_new(13u, 0u, 0u, 243u);
    l3 = (void*) _a13_arr;
    vader_array_t* _a14_arr = vader_array_new(13u, 0u, 0u, 243u);
    l4 = (void*) _a14_arr;
    vader_array_t* _a15_arr = vader_array_new(14u, 0u, 7u, 246u);
    l5 = (void*) _a15_arr;
    vader_array_t* _a16_arr = vader_array_new(14u, 0u, 7u, 246u);
    l8 = (void*) _a16_arr;
    vader_struct_std_collections_MutableMap__string__i32_t* _a17_obj = (vader_struct_std_collections_MutableMap__string__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__i32_t));
    vader_obj_header_init(_a17_obj, 384u);
    _a17_obj->f_ekeys = l4;
    _a17_obj->f_evals = l5;
    _a17_obj->f_index = l8;
    _a17_obj->f_mask = (size_t) 0;
    _a17_obj->f_size = (size_t) 0;
    _a17_obj->f_tombs = (size_t) 0;
    l4 = (void*) _a17_obj;
    l5 = ((vader_struct_vader_lower_LoweredProject_t*) l0)->f_const_fn_wrap;
    l8 = ((vader_struct_vader_lower_LoweredProject_t*) l0)->f_const_inline;
    vader_struct_vader_midir_ProjectCtx_t* _a18_obj = (vader_struct_vader_midir_ProjectCtx_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_ProjectCtx_t));
    vader_obj_header_init(_a18_obj, 974u);
    _a18_obj->f_strings = l3;
    _a18_obj->f_string_index = l4;
    _a18_obj->f_const_fn_wrap = l5;
    _a18_obj->f_const_inline = l8;
    _a18_obj->f_extern_callbacks = l2;
    _a18_obj->f_diags = l1;
    t3 = (void*) _a18_obj;
    { void* __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
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
    vader_array_t* _a0_arr = vader_array_new(15u, 0u, 8u, 247u);
    l0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(11u, 0u, 12u, 241u);
    l1 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(14u, 0u, 7u, 246u);
    l2 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__i64__bool_t* _a3_obj = (vader_struct_std_collections_MutableMap__i64__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i64__bool_t));
    vader_obj_header_init(_a3_obj, 334u);
    _a3_obj->f_ekeys = l0;
    _a3_obj->f_evals = l1;
    _a3_obj->f_index = l2;
    _a3_obj->f_mask = (size_t) 0;
    _a3_obj->f_size = (size_t) 0;
    _a3_obj->f_tombs = (size_t) 0;
    t0 = (void*) _a3_obj;
    vader_struct_std_collections_MutableSet__i64_t* _a4_obj = (vader_struct_std_collections_MutableSet__i64_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i64_t));
    vader_obj_header_init(_a4_obj, 426u);
    _a4_obj->f_inner = t0;
    l0 = (void*) _a4_obj;
    vader_array_t* _a5_arr = vader_array_new(15u, 0u, 8u, 247u);
    l1 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(11u, 0u, 12u, 241u);
    l2 = (void*) _a6_arr;
    vader_array_t* _a7_arr = vader_array_new(14u, 0u, 7u, 246u);
    l3 = (void*) _a7_arr;
    vader_struct_std_collections_MutableMap__i64__bool_t* _a8_obj = (vader_struct_std_collections_MutableMap__i64__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i64__bool_t));
    vader_obj_header_init(_a8_obj, 334u);
    _a8_obj->f_ekeys = l1;
    _a8_obj->f_evals = l2;
    _a8_obj->f_index = l3;
    _a8_obj->f_mask = (size_t) 0;
    _a8_obj->f_size = (size_t) 0;
    _a8_obj->f_tombs = (size_t) 0;
    t0 = (void*) _a8_obj;
    vader_struct_std_collections_MutableSet__i64_t* _a9_obj = (vader_struct_std_collections_MutableSet__i64_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i64_t));
    vader_obj_header_init(_a9_obj, 426u);
    _a9_obj->f_inner = t0;
    l1 = (void*) _a9_obj;
    vader_array_t* _a10_arr = vader_array_new(14u, 0u, 7u, 246u);
    l2 = (void*) _a10_arr;
    vader_array_t* _a11_arr = vader_array_new(11u, 0u, 12u, 241u);
    l3 = (void*) _a11_arr;
    vader_array_t* _a12_arr = vader_array_new(14u, 0u, 7u, 246u);
    l4 = (void*) _a12_arr;
    vader_struct_std_collections_MutableMap__i32__bool_t* _a13_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
    vader_obj_header_init(_a13_obj, 328u);
    _a13_obj->f_ekeys = l2;
    _a13_obj->f_evals = l3;
    _a13_obj->f_index = l4;
    _a13_obj->f_mask = (size_t) 0;
    _a13_obj->f_size = (size_t) 0;
    _a13_obj->f_tombs = (size_t) 0;
    t0 = (void*) _a13_obj;
    vader_struct_std_collections_MutableSet__i32_t* _a14_obj = (vader_struct_std_collections_MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i32_t));
    vader_obj_header_init(_a14_obj, 425u);
    _a14_obj->f_inner = t0;
    l2 = (void*) _a14_obj;
    vader_struct_vader_midir_ScheduleHints_t* _a15_obj = (vader_struct_vader_midir_ScheduleHints_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_ScheduleHints_t));
    vader_obj_header_init(_a15_obj, 975u);
    _a15_obj->f_skip_set = l0;
    _a15_obj->f_skip_first_get = l1;
    _a15_obj->f_skip_terminator_get = l2;
    t0 = (void*) _a15_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
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
    t0 = vader_box_bool(241u, ((uint8_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l4]);
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
    size_t t0;
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
        if ((l1.tag == 861u || l1.tag == 869u)) {
            return true;
        }
        if (!(l1.tag == 890u)) {
            return false;
        }
        t1 = l1.payload.obj;
        l1 = ((vader_struct_vader_lower_LoweredReturn_t*) t1)->f_value;
        if (l1.tag == 0u) {
            return true;
        }
        return (l1.tag == 860u || l1.tag == 877u || l1.tag == 880u || l1.tag == 887u);
    }
    return false;
}

static int32_t vader_midir_open_blocks(void* l0, void* l1, int32_t l2) {
    size_t l3, l4, l5;
    int32_t l6, l8;
    void* l7 = NULL;
    void* l9 = NULL;
    size_t t0;
    int64_t t1;
    void* t2 = NULL;
    int32_t t3;
    void** gc_raw_roots[5] = { &l0, &l1, &l7, &l9, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = (size_t) 0;
    l4 = ((vader_array_t*) l1)->length;
    while ((l3 < l4)) {
        t0 = ((vader_array_t*) l1)->length;
        t1 = ((t0 - INT64_C(1)) - l3);
        l5 = (size_t) (int64_t) t1;
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
        t1 = (l3 + INT64_C(1));
        l3 = (size_t) (int64_t) t1;
    }
    t0 = ((vader_array_t*) l1)->length;
    if ((t0 > INT64_C(0))) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, INT32_C(0))
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
    if (l0.tag == 899u) {
        t0 = l0.payload.obj;
        if (((vader_struct_vader_lower_LoweredUnary_t*) t0)->f_op == INT32_C(1)) {
            t0 = l0.payload.obj;
            l1 = vader_midir_operand_edges(((vader_struct_vader_lower_LoweredUnary_t*) t0)->f_operand);
            l2 = ((vader_struct_vader_midir_OperandEdges_t*) l1)->f_on_false;
            l3 = ((vader_struct_vader_midir_OperandEdges_t*) l1)->f_on_true;
            vader_struct_vader_midir_OperandEdges_t* _a0_obj = (vader_struct_vader_midir_OperandEdges_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_OperandEdges_t));
            vader_obj_header_init(_a0_obj, 972u);
            _a0_obj->f_on_true = l2;
            _a0_obj->f_on_false = l3;
            t0 = (void*) _a0_obj;
            { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    if (l0.tag == 858u) {
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
                l6 = (l5 + l6);
                l7 = ((vader_struct_vader_midir_OperandEdges_t*) l4)->f_on_false;
                vader_struct_vader_midir_OperandEdges_t* _a1_obj = (vader_struct_vader_midir_OperandEdges_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_OperandEdges_t));
                vader_obj_header_init(_a1_obj, 972u);
                _a1_obj->f_on_true = l6;
                _a1_obj->f_on_false = l7;
                t0 = (void*) _a1_obj;
                { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
            }
            l2 = ((vader_struct_vader_midir_OperandEdges_t*) l4)->f_on_true;
            l3 = ((vader_struct_vader_midir_OperandEdges_t*) l1)->f_on_false;
            l5 = ((vader_struct_vader_midir_OperandEdges_t*) l4)->f_on_false;
            l3 = (l3 + l5);
            vader_struct_vader_midir_OperandEdges_t* _a2_obj = (vader_struct_vader_midir_OperandEdges_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_OperandEdges_t));
            vader_obj_header_init(_a2_obj, 972u);
            _a2_obj->f_on_true = l2;
            _a2_obj->f_on_false = l3;
            t0 = (void*) _a2_obj;
            { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    vader_struct_vader_midir_OperandEdges_t* _a3_obj = (vader_struct_vader_midir_OperandEdges_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_OperandEdges_t));
    vader_obj_header_init(_a3_obj, 972u);
    _a3_obj->f_on_true = INT32_C(1);
    _a3_obj->f_on_false = INT32_C(1);
    t0 = (void*) _a3_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
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
    size_t l8, l9;
    bool l13;
    int64_t t0;
    bool t1;
    l4 = -(INT32_C(1));
    l5 = l0;
    l6 = ((vader_struct_std_collections_MutableMap__i32__MutableSet_i32__t*) l5)->f_ekeys;
    l7 = ((vader_struct_std_collections_MutableMap__i32__MutableSet_i32__t*) l5)->f_evals;
    l8 = ((vader_struct_std_collections_MutableMap__i32__MutableSet_i32__t*) l5)->f_size;
    l9 = (size_t) 0;
    while (!((l9 >= l8))) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l9)
        l10 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l9];
        vader_array_t* _a1_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l9)
        l5 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l9);
        l11 = l10;
        l12 = l5;
        t0 = (l9 + INT64_C(1));
        l9 = (size_t) (int64_t) t0;
        t1 = std_collections_MutableSet_Contains_contains__i32(l12, l2);
        if (!(t1)) {
            continue;
        }
        t1 = std_collections_MutableSet_Contains_contains__i32(l12, l3);
        if (t1) {
            continue;
        }
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
    return l4;
}

static void vader_midir_pin_baked_struct_types(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    size_t l5, l6, l8, l9;
    vader_box_t l7 = vader_box_null();
    int32_t l10, l11;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    int64_t t2;
    vader_box_t* gc_roots[2] = { &l7, &t1 };
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l3, &l4, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 6u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(14u, 0u, 7u, 246u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(11u, 0u, 12u, 241u);
    l3 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(14u, 0u, 7u, 246u);
    l4 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__i32__bool_t* _a3_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
    vader_obj_header_init(_a3_obj, 328u);
    _a3_obj->f_ekeys = l2;
    _a3_obj->f_evals = l3;
    _a3_obj->f_index = l4;
    _a3_obj->f_mask = (size_t) 0;
    _a3_obj->f_size = (size_t) 0;
    _a3_obj->f_tombs = (size_t) 0;
    t0 = (void*) _a3_obj;
    vader_struct_std_collections_MutableSet__i32_t* _a4_obj = (vader_struct_std_collections_MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i32_t));
    vader_obj_header_init(_a4_obj, 425u);
    _a4_obj->f_inner = t0;
    l2 = (void*) _a4_obj;
    l3 = l0;
    l5 = ((vader_array_t*) l3)->length;
    l6 = (size_t) 0;
    while ((l6 < l5)) {
        vader_array_t* _a5_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l6)
        l7 = vader_array_ref_load_box(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l6);
        if (l7.tag == 547u) {
            t0 = l7.payload.obj;
            l4 = ((vader_struct_vader_bytecode_BcAggregateData_t*) t0)->f_elements;
            l8 = ((vader_array_t*) l4)->length;
            l9 = (size_t) 0;
            while ((l9 < l8)) {
                vader_array_t* _a6_slotarr = ((vader_array_t*) l4);
                VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l9)
                t1 = vader_array_ref_load_box(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l9);
                vader_midir_collect_baked_symbols(t1, l2);
                t2 = (l9 + INT64_C(1));
                l9 = (size_t) (int64_t) t2;
            }
        }
        t2 = (l6 + INT64_C(1));
        l6 = (size_t) (int64_t) t2;
    }
    l3 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) ((vader_struct_std_collections_MutableSet__i32_t*) l2)->f_inner)->f_ekeys;
    l5 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) ((vader_struct_std_collections_MutableSet__i32_t*) l2)->f_inner)->f_size;
    l6 = (size_t) 0;
    while (!((l6 >= l5))) {
        vader_array_t* _a7_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l6)
        l10 = ((int32_t*) _a7_slotarr->buf->slots)[_a7_slotarr->offset + (size_t) l6];
        t2 = (l6 + INT64_C(1));
        l6 = (size_t) (int64_t) t2;
        l11 = vader_bytecode_struct_symbol_type_index(((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_types, l10);
        if (!((l11 >= INT32_C(0)))) {
            continue;
        }
        vader_array_push_i32((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_pinned_types, l11);
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static int64_t vader_midir_pos_key(int32_t l0, size_t l1) {
    int64_t l2, l3;
    l2 = (((int64_t) (int32_t) l0) * INT64_C(1000000));
    l3 = ((int64_t) (size_t) l1);
    return (l2 + l3);
}

static void* vader_midir_predecessors_of(void* l0) {
    size_t l1, l4, l7, l8;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l10 = NULL;
    int32_t l9, l11;
    int64_t t0;
    void** gc_raw_roots[6] = { &l0, &l2, &l3, &l5, &l6, &l10 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 6u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = ((vader_array_t*) ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_blocks)->length;
    l2 = (void*) &vader_fn_static___lambda_vader_midir_8;
    l2 = std_core_filled__i32__(l1, l2);
    l3 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_blocks;
    l1 = ((vader_array_t*) l3)->length;
    l4 = (size_t) 0;
    while ((l4 < l1)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        l5 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        l6 = vader_midir_successors_of(l5);
        l7 = ((vader_array_t*) l6)->length;
        l8 = (size_t) 0;
        while ((l8 < l7)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l6);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l8)
            l9 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l8];
            vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l9)
            l10 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l9);
            l11 = ((vader_struct_vader_midir_BasicBlock_t*) l5)->f_id;
            vader_array_push_i32((vader_array_t*) l10, l11);
            t0 = (l8 + INT64_C(1));
            l8 = (size_t) (int64_t) t0;
        }
        t0 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t0;
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_midir_push_emit(void* l0, vader_box_t l1, void* l2) {
    void* l3 = NULL;
    vader_box_t l4 = vader_box_null();
    int32_t l5;
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
    l3 = ((vader_struct_vader_bytecode_BcFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_slot)->f_jump_table;
    l5 = -(INT32_C(1));
    vader_array_push_i32((vader_array_t*) l3, l5);
    { vader_gc_top = gc_frame.prev; return; }
}

static int32_t vader_midir_push_op_with_span(void* l0, vader_box_t l1, void* l2) {
    int32_t l3, l6;
    void* l4 = NULL;
    vader_box_t l5 = vader_box_null();
    size_t t0;
    bool t1;
    vader_box_t* gc_roots[2] = { &l1, &l5 };
    void** gc_raw_roots[3] = { &l0, &l2, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_slot)->f_body)->length;
    l3 = ((int32_t) (size_t) t0);
    vader_array_push((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_slot)->f_body, l1);
    l4 = ((vader_struct_vader_bytecode_BcFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_slot)->f_debug;
    t1 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_want_debug;
    if (t1) {
        l5 = vader_midir_debug_pos_of_span(l2);
    } else {
        l5 = vader_box_obj(0u, NULL);
    }
    vader_array_push((vader_array_t*) l4, l5);
    l4 = ((vader_struct_vader_bytecode_BcFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_slot)->f_jump_table;
    l6 = -(INT32_C(1));
    vader_array_push_i32((vader_array_t*) l4, l6);
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

static bool vader_midir_read_may_carry_ref(vader_box_t l0) {
    uint8_t l1;
    l1 = vader_bytecode_val_type_of_type(l0);
    if (l1 == INT32_C(18)) {
        return true;
    }
    return l1 == INT32_C(19);
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
    size_t l3, l4;
    vader_box_t l5 = vader_box_null();
    void* t0 = NULL;
    int64_t t1;
    vader_box_t* gc_roots[2] = { &l1, &l5 };
    void** gc_raw_roots[2] = { &l2, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l1.tag == 1093u) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_vader_types_UnionType_t*) t0)->f_variants;
        l3 = ((vader_array_t*) l2)->length;
        l4 = (size_t) 0;
        while ((l4 < l3)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
            l5 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
            vader_midir_refuse_shared_instance(l0, l5);
            t1 = (l4 + INT64_C(1));
            l4 = (size_t) (int64_t) t1;
        }
    } else {
        l5 = l1;
        vader_midir_refuse_shared_instance(l0, l5);
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_midir_refuse_shared_instance(vader_string_t l0, vader_box_t l1) {
    void* l2 = NULL;
    size_t l3, l4;
    vader_box_t l5 = vader_box_null();
    vader_string_t l6 = 0;
    vader_string_t l7 = 0;
    vader_string_t l8 = 0;
    vader_string_t l9 = 0;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_string_t t2 = 0;
    int64_t t3;
    vader_box_t* gc_roots[3] = { &l1, &l5, &t1 };
    void** gc_raw_roots[2] = { &l2, &t0 };
    vader_string_t* gc_atom_roots[6] = { &l0, &l6, &l7, &l8, &l9, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 6u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (!(l1.tag == 1088u)) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    t0 = l1.payload.obj;
    l2 = ((vader_struct_vader_types_StructType_t*) t0)->f_args;
    l3 = ((vader_array_t*) l2)->length;
    l4 = (size_t) 0;
    for (;;) {
        if ((l4 < l3)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
            l5 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
            t1 = vader_types_kept_type_argument(l5);
            if (t1.tag == 0u) {
                t0 = l1.payload.obj;
                l6 = vader_types_display_type(vader_ref_box(t0));
                l7 = concat_5(1381u, l0, 1019u, l6, 1068u);
                l8 = vader_types_display_type(l5);
                l9 = concat_3(1704u, l8, 860u);
                t2 = concat_3(l7, 1259u, l9);
                vader_host_std_abort_panic(t2);
                vader_unreachable("a no-return call returned");
            } else {
                t3 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t3;
                continue;
            }
        }
        break;
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_midir_remap_instr(vader_box_t l0, void* l1) {
    void* l2 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    int32_t l3, l6, l8, l16;
    vader_box_t l4 = vader_box_null(), l5 = vader_box_null(), l12 = vader_box_null();
    uint8_t l7;
    vader_string_t l13 = 0;
    vader_string_t l14 = 0;
    bool l15;
    void* t0 = NULL;
    vader_box_t* gc_roots[4] = { &l0, &l4, &l5, &l12 };
    void** gc_raw_roots[6] = { &l1, &l2, &l9, &l10, &l11, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l13, &l14 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l0.tag == 952u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_midir_InstrConst_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrConst_t*) t0)->f_dst;
        l3 = vader_midir_remap_local(l1, l3);
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrConst_t*) t0)->f_value;
        t0 = l0.payload.obj;
        l5 = ((vader_struct_vader_midir_InstrConst_t*) t0)->f_type;
        vader_struct_vader_midir_InstrConst_t* _a0_obj = (vader_struct_vader_midir_InstrConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrConst_t));
        vader_obj_header_init(_a0_obj, 952u);
        _a0_obj->f_span = l2;
        _a0_obj->f_dst = l3;
        _a0_obj->f_value = l4;
        _a0_obj->f_type = l5;
        t0 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 962u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_midir_InstrMove_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrMove_t*) t0)->f_dst;
        l3 = vader_midir_remap_local(l1, l3);
        t0 = l0.payload.obj;
        l6 = ((vader_struct_vader_midir_InstrMove_t*) t0)->f_src;
        l6 = vader_midir_remap_local(l1, l6);
        vader_struct_vader_midir_InstrMove_t* _a1_obj = (vader_struct_vader_midir_InstrMove_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrMove_t));
        vader_obj_header_init(_a1_obj, 962u);
        _a1_obj->f_span = l2;
        _a1_obj->f_dst = l3;
        _a1_obj->f_src = l6;
        t0 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 945u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_midir_InstrBinOp_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrBinOp_t*) t0)->f_dst;
        l3 = vader_midir_remap_local(l1, l3);
        t0 = l0.payload.obj;
        l7 = ((vader_struct_vader_midir_InstrBinOp_t*) t0)->f_op;
        t0 = l0.payload.obj;
        l6 = ((vader_struct_vader_midir_InstrBinOp_t*) t0)->f_lhs;
        l6 = vader_midir_remap_local(l1, l6);
        t0 = l0.payload.obj;
        l8 = ((vader_struct_vader_midir_InstrBinOp_t*) t0)->f_rhs;
        l8 = vader_midir_remap_local(l1, l8);
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrBinOp_t*) t0)->f_type;
        vader_struct_vader_midir_InstrBinOp_t* _a2_obj = (vader_struct_vader_midir_InstrBinOp_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrBinOp_t));
        vader_obj_header_init(_a2_obj, 945u);
        _a2_obj->f_span = l2;
        _a2_obj->f_dst = l3;
        _a2_obj->f_op = l7;
        _a2_obj->f_lhs = l6;
        _a2_obj->f_rhs = l8;
        _a2_obj->f_type = l4;
        t0 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 967u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_midir_InstrUnOp_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrUnOp_t*) t0)->f_dst;
        l3 = vader_midir_remap_local(l1, l3);
        t0 = l0.payload.obj;
        l7 = ((vader_struct_vader_midir_InstrUnOp_t*) t0)->f_op;
        t0 = l0.payload.obj;
        l6 = ((vader_struct_vader_midir_InstrUnOp_t*) t0)->f_operand;
        l6 = vader_midir_remap_local(l1, l6);
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrUnOp_t*) t0)->f_type;
        vader_struct_vader_midir_InstrUnOp_t* _a3_obj = (vader_struct_vader_midir_InstrUnOp_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrUnOp_t));
        vader_obj_header_init(_a3_obj, 967u);
        _a3_obj->f_span = l2;
        _a3_obj->f_dst = l3;
        _a3_obj->f_op = l7;
        _a3_obj->f_operand = l6;
        _a3_obj->f_type = l4;
        t0 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 946u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_midir_InstrCall_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l9 = ((vader_struct_vader_midir_InstrCall_t*) t0)->f_dsts;
        l9 = vader_midir_remap_locals(l1, l9);
        t0 = l0.payload.obj;
        l10 = ((vader_struct_vader_midir_InstrCall_t*) t0)->f_callee;
        t0 = l0.payload.obj;
        l11 = ((vader_struct_vader_midir_InstrCall_t*) t0)->f_args;
        l11 = vader_midir_remap_locals(l1, l11);
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrCall_t*) t0)->f_type;
        vader_struct_vader_midir_InstrCall_t* _a4_obj = (vader_struct_vader_midir_InstrCall_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrCall_t));
        vader_obj_header_init(_a4_obj, 946u);
        _a4_obj->f_span = l2;
        _a4_obj->f_dsts = l9;
        _a4_obj->f_callee = l10;
        _a4_obj->f_args = l11;
        _a4_obj->f_type = l4;
        t0 = (void*) _a4_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 947u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_midir_InstrCallIndirect_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrCallIndirect_t*) t0)->f_dst;
        l4 = vader_midir_remap_local_opt(l1, l4);
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrCallIndirect_t*) t0)->f_callee;
        l3 = vader_midir_remap_local(l1, l3);
        t0 = l0.payload.obj;
        l9 = ((vader_struct_vader_midir_InstrCallIndirect_t*) t0)->f_args;
        l9 = vader_midir_remap_locals(l1, l9);
        t0 = l0.payload.obj;
        l5 = ((vader_struct_vader_midir_InstrCallIndirect_t*) t0)->f_fn_type;
        t0 = l0.payload.obj;
        l12 = ((vader_struct_vader_midir_InstrCallIndirect_t*) t0)->f_type;
        vader_struct_vader_midir_InstrCallIndirect_t* _a5_obj = (vader_struct_vader_midir_InstrCallIndirect_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrCallIndirect_t));
        vader_obj_header_init(_a5_obj, 947u);
        _a5_obj->f_span = l2;
        _a5_obj->f_dst = l4;
        _a5_obj->f_callee = l3;
        _a5_obj->f_args = l9;
        _a5_obj->f_fn_type = l5;
        _a5_obj->f_type = l12;
        t0 = (void*) _a5_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 968u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_midir_InstrVirtualCall_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrVirtualCall_t*) t0)->f_dst;
        l4 = vader_midir_remap_local_opt(l1, l4);
        t0 = l0.payload.obj;
        l13 = ((vader_struct_vader_midir_InstrVirtualCall_t*) t0)->f_trait_name;
        t0 = l0.payload.obj;
        l14 = ((vader_struct_vader_midir_InstrVirtualCall_t*) t0)->f_method;
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrVirtualCall_t*) t0)->f_receiver;
        l3 = vader_midir_remap_local(l1, l3);
        t0 = l0.payload.obj;
        l9 = ((vader_struct_vader_midir_InstrVirtualCall_t*) t0)->f_args;
        l9 = vader_midir_remap_locals(l1, l9);
        t0 = l0.payload.obj;
        l5 = ((vader_struct_vader_midir_InstrVirtualCall_t*) t0)->f_type;
        t0 = l0.payload.obj;
        l10 = ((vader_struct_vader_midir_InstrVirtualCall_t*) t0)->f_param_types;
        vader_struct_vader_midir_InstrVirtualCall_t* _a6_obj = (vader_struct_vader_midir_InstrVirtualCall_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrVirtualCall_t));
        vader_obj_header_init(_a6_obj, 968u);
        _a6_obj->f_span = l2;
        _a6_obj->f_dst = l4;
        _a6_obj->f_trait_name = l13;
        _a6_obj->f_method = l14;
        _a6_obj->f_receiver = l3;
        _a6_obj->f_args = l9;
        _a6_obj->f_type = l5;
        _a6_obj->f_param_types = l10;
        t0 = (void*) _a6_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 959u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_midir_InstrFnRef_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrFnRef_t*) t0)->f_dst;
        l3 = vader_midir_remap_local(l1, l3);
        t0 = l0.payload.obj;
        l9 = ((vader_struct_vader_midir_InstrFnRef_t*) t0)->f_fn_symbol;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrFnRef_t*) t0)->f_type;
        vader_struct_vader_midir_InstrFnRef_t* _a7_obj = (vader_struct_vader_midir_InstrFnRef_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrFnRef_t));
        vader_obj_header_init(_a7_obj, 959u);
        _a7_obj->f_span = l2;
        _a7_obj->f_dst = l3;
        _a7_obj->f_fn_symbol = l9;
        _a7_obj->f_type = l4;
        t0 = (void*) _a7_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 958u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_midir_InstrFnAddr_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrFnAddr_t*) t0)->f_dst;
        l3 = vader_midir_remap_local(l1, l3);
        t0 = l0.payload.obj;
        l9 = ((vader_struct_vader_midir_InstrFnAddr_t*) t0)->f_fn_symbol;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrFnAddr_t*) t0)->f_type;
        vader_struct_vader_midir_InstrFnAddr_t* _a8_obj = (vader_struct_vader_midir_InstrFnAddr_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrFnAddr_t));
        vader_obj_header_init(_a8_obj, 958u);
        _a8_obj->f_span = l2;
        _a8_obj->f_dst = l3;
        _a8_obj->f_fn_symbol = l9;
        _a8_obj->f_type = l4;
        t0 = (void*) _a8_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 956u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_midir_InstrFieldGet_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrFieldGet_t*) t0)->f_dst;
        l3 = vader_midir_remap_local(l1, l3);
        t0 = l0.payload.obj;
        l6 = ((vader_struct_vader_midir_InstrFieldGet_t*) t0)->f_target;
        l6 = vader_midir_remap_local(l1, l6);
        t0 = l0.payload.obj;
        l13 = ((vader_struct_vader_midir_InstrFieldGet_t*) t0)->f_field;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrFieldGet_t*) t0)->f_type;
        vader_struct_vader_midir_InstrFieldGet_t* _a9_obj = (vader_struct_vader_midir_InstrFieldGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrFieldGet_t));
        vader_obj_header_init(_a9_obj, 956u);
        _a9_obj->f_span = l2;
        _a9_obj->f_dst = l3;
        _a9_obj->f_target = l6;
        _a9_obj->f_field = l13;
        _a9_obj->f_type = l4;
        t0 = (void*) _a9_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 957u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_midir_InstrFieldSet_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrFieldSet_t*) t0)->f_target;
        l3 = vader_midir_remap_local(l1, l3);
        t0 = l0.payload.obj;
        l13 = ((vader_struct_vader_midir_InstrFieldSet_t*) t0)->f_field;
        t0 = l0.payload.obj;
        l6 = ((vader_struct_vader_midir_InstrFieldSet_t*) t0)->f_value;
        l6 = vader_midir_remap_local(l1, l6);
        t0 = l0.payload.obj;
        l15 = ((vader_struct_vader_midir_InstrFieldSet_t*) t0)->f_barrierless;
        vader_struct_vader_midir_InstrFieldSet_t* _a10_obj = (vader_struct_vader_midir_InstrFieldSet_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrFieldSet_t));
        vader_obj_header_init(_a10_obj, 957u);
        _a10_obj->f_span = l2;
        _a10_obj->f_target = l3;
        _a10_obj->f_field = l13;
        _a10_obj->f_value = l6;
        _a10_obj->f_barrierless = l15;
        t0 = (void*) _a10_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 939u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_midir_InstrArrayGet_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrArrayGet_t*) t0)->f_dst;
        l3 = vader_midir_remap_local(l1, l3);
        t0 = l0.payload.obj;
        l6 = ((vader_struct_vader_midir_InstrArrayGet_t*) t0)->f_target;
        l6 = vader_midir_remap_local(l1, l6);
        t0 = l0.payload.obj;
        l8 = ((vader_struct_vader_midir_InstrArrayGet_t*) t0)->f_index;
        l8 = vader_midir_remap_local(l1, l8);
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrArrayGet_t*) t0)->f_type;
        t0 = l0.payload.obj;
        l15 = ((vader_struct_vader_midir_InstrArrayGet_t*) t0)->f_bounds_safe;
        vader_struct_vader_midir_InstrArrayGet_t* _a11_obj = (vader_struct_vader_midir_InstrArrayGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrArrayGet_t));
        vader_obj_header_init(_a11_obj, 939u);
        _a11_obj->f_span = l2;
        _a11_obj->f_dst = l3;
        _a11_obj->f_target = l6;
        _a11_obj->f_index = l8;
        _a11_obj->f_type = l4;
        _a11_obj->f_bounds_safe = l15;
        t0 = (void*) _a11_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 943u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_midir_InstrArraySet_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrArraySet_t*) t0)->f_target;
        l3 = vader_midir_remap_local(l1, l3);
        t0 = l0.payload.obj;
        l6 = ((vader_struct_vader_midir_InstrArraySet_t*) t0)->f_index;
        l6 = vader_midir_remap_local(l1, l6);
        t0 = l0.payload.obj;
        l8 = ((vader_struct_vader_midir_InstrArraySet_t*) t0)->f_value;
        l8 = vader_midir_remap_local(l1, l8);
        t0 = l0.payload.obj;
        l15 = ((vader_struct_vader_midir_InstrArraySet_t*) t0)->f_bounds_safe;
        vader_struct_vader_midir_InstrArraySet_t* _a12_obj = (vader_struct_vader_midir_InstrArraySet_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrArraySet_t));
        vader_obj_header_init(_a12_obj, 943u);
        _a12_obj->f_span = l2;
        _a12_obj->f_target = l3;
        _a12_obj->f_index = l6;
        _a12_obj->f_value = l8;
        _a12_obj->f_bounds_safe = l15;
        t0 = (void*) _a12_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 940u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_midir_InstrArrayLen_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrArrayLen_t*) t0)->f_dst;
        l3 = vader_midir_remap_local(l1, l3);
        t0 = l0.payload.obj;
        l6 = ((vader_struct_vader_midir_InstrArrayLen_t*) t0)->f_target;
        l6 = vader_midir_remap_local(l1, l6);
        vader_struct_vader_midir_InstrArrayLen_t* _a13_obj = (vader_struct_vader_midir_InstrArrayLen_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrArrayLen_t));
        vader_obj_header_init(_a13_obj, 940u);
        _a13_obj->f_span = l2;
        _a13_obj->f_dst = l3;
        _a13_obj->f_target = l6;
        t0 = (void*) _a13_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 942u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_midir_InstrArrayPush_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrArrayPush_t*) t0)->f_target;
        l3 = vader_midir_remap_local(l1, l3);
        t0 = l0.payload.obj;
        l6 = ((vader_struct_vader_midir_InstrArrayPush_t*) t0)->f_value;
        l6 = vader_midir_remap_local(l1, l6);
        t0 = l0.payload.obj;
        l15 = ((vader_struct_vader_midir_InstrArrayPush_t*) t0)->f_cached;
        vader_struct_vader_midir_InstrArrayPush_t* _a14_obj = (vader_struct_vader_midir_InstrArrayPush_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrArrayPush_t));
        vader_obj_header_init(_a14_obj, 942u);
        _a14_obj->f_span = l2;
        _a14_obj->f_target = l3;
        _a14_obj->f_value = l6;
        _a14_obj->f_cached = l15;
        t0 = (void*) _a14_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 944u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_midir_InstrArraySlice_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrArraySlice_t*) t0)->f_dst;
        l3 = vader_midir_remap_local(l1, l3);
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrArraySlice_t*) t0)->f_type;
        t0 = l0.payload.obj;
        l6 = ((vader_struct_vader_midir_InstrArraySlice_t*) t0)->f_target;
        l6 = vader_midir_remap_local(l1, l6);
        t0 = l0.payload.obj;
        l8 = ((vader_struct_vader_midir_InstrArraySlice_t*) t0)->f_lo;
        l8 = vader_midir_remap_local(l1, l8);
        t0 = l0.payload.obj;
        l16 = ((vader_struct_vader_midir_InstrArraySlice_t*) t0)->f_hi;
        l16 = vader_midir_remap_local(l1, l16);
        vader_struct_vader_midir_InstrArraySlice_t* _a15_obj = (vader_struct_vader_midir_InstrArraySlice_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrArraySlice_t));
        vader_obj_header_init(_a15_obj, 944u);
        _a15_obj->f_span = l2;
        _a15_obj->f_dst = l3;
        _a15_obj->f_type = l4;
        _a15_obj->f_target = l6;
        _a15_obj->f_lo = l8;
        _a15_obj->f_hi = l16;
        t0 = (void*) _a15_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 963u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_midir_InstrStringSlice_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrStringSlice_t*) t0)->f_dst;
        l3 = vader_midir_remap_local(l1, l3);
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrStringSlice_t*) t0)->f_type;
        t0 = l0.payload.obj;
        l6 = ((vader_struct_vader_midir_InstrStringSlice_t*) t0)->f_target;
        l6 = vader_midir_remap_local(l1, l6);
        t0 = l0.payload.obj;
        l8 = ((vader_struct_vader_midir_InstrStringSlice_t*) t0)->f_lo;
        l8 = vader_midir_remap_local(l1, l8);
        t0 = l0.payload.obj;
        l16 = ((vader_struct_vader_midir_InstrStringSlice_t*) t0)->f_hi;
        l16 = vader_midir_remap_local(l1, l16);
        vader_struct_vader_midir_InstrStringSlice_t* _a16_obj = (vader_struct_vader_midir_InstrStringSlice_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrStringSlice_t));
        vader_obj_header_init(_a16_obj, 963u);
        _a16_obj->f_span = l2;
        _a16_obj->f_dst = l3;
        _a16_obj->f_type = l4;
        _a16_obj->f_target = l6;
        _a16_obj->f_lo = l8;
        _a16_obj->f_hi = l16;
        t0 = (void*) _a16_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 964u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_midir_InstrStructNew_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrStructNew_t*) t0)->f_dst;
        l3 = vader_midir_remap_local(l1, l3);
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrStructNew_t*) t0)->f_type;
        t0 = l0.payload.obj;
        l9 = ((vader_struct_vader_midir_InstrStructNew_t*) t0)->f_fields;
        l9 = vader_midir_remap_locals(l1, l9);
        t0 = l0.payload.obj;
        l15 = ((vader_struct_vader_midir_InstrStructNew_t*) t0)->f_stack;
        vader_struct_vader_midir_InstrStructNew_t* _a17_obj = (vader_struct_vader_midir_InstrStructNew_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrStructNew_t));
        vader_obj_header_init(_a17_obj, 964u);
        _a17_obj->f_span = l2;
        _a17_obj->f_dst = l3;
        _a17_obj->f_type = l4;
        _a17_obj->f_fields = l9;
        _a17_obj->f_stack = l15;
        t0 = (void*) _a17_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 941u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_midir_InstrArrayNew_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrArrayNew_t*) t0)->f_dst;
        l3 = vader_midir_remap_local(l1, l3);
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrArrayNew_t*) t0)->f_type;
        t0 = l0.payload.obj;
        l6 = ((vader_struct_vader_midir_InstrArrayNew_t*) t0)->f_length;
        t0 = l0.payload.obj;
        l9 = ((vader_struct_vader_midir_InstrArrayNew_t*) t0)->f_elements;
        l9 = vader_midir_remap_locals(l1, l9);
        t0 = l0.payload.obj;
        l15 = ((vader_struct_vader_midir_InstrArrayNew_t*) t0)->f_stack;
        vader_struct_vader_midir_InstrArrayNew_t* _a18_obj = (vader_struct_vader_midir_InstrArrayNew_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrArrayNew_t));
        vader_obj_header_init(_a18_obj, 941u);
        _a18_obj->f_span = l2;
        _a18_obj->f_dst = l3;
        _a18_obj->f_type = l4;
        _a18_obj->f_length = l6;
        _a18_obj->f_elements = l9;
        _a18_obj->f_stack = l15;
        t0 = (void*) _a18_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 953u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_midir_InstrDataConst_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrDataConst_t*) t0)->f_dst;
        l3 = vader_midir_remap_local(l1, l3);
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrDataConst_t*) t0)->f_type;
        t0 = l0.payload.obj;
        l6 = ((vader_struct_vader_midir_InstrDataConst_t*) t0)->f_pool_index;
        vader_struct_vader_midir_InstrDataConst_t* _a19_obj = (vader_struct_vader_midir_InstrDataConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrDataConst_t));
        vader_obj_header_init(_a19_obj, 953u);
        _a19_obj->f_span = l2;
        _a19_obj->f_dst = l3;
        _a19_obj->f_type = l4;
        _a19_obj->f_pool_index = l6;
        t0 = (void*) _a19_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 965u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_midir_InstrTypeCheck_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrTypeCheck_t*) t0)->f_dst;
        l3 = vader_midir_remap_local(l1, l3);
        t0 = l0.payload.obj;
        l6 = ((vader_struct_vader_midir_InstrTypeCheck_t*) t0)->f_value;
        l6 = vader_midir_remap_local(l1, l6);
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrTypeCheck_t*) t0)->f_check_type;
        vader_struct_vader_midir_InstrTypeCheck_t* _a20_obj = (vader_struct_vader_midir_InstrTypeCheck_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrTypeCheck_t));
        vader_obj_header_init(_a20_obj, 965u);
        _a20_obj->f_span = l2;
        _a20_obj->f_dst = l3;
        _a20_obj->f_value = l6;
        _a20_obj->f_check_type = l4;
        t0 = (void*) _a20_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 966u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_midir_InstrTypeConst_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrTypeConst_t*) t0)->f_dst;
        l3 = vader_midir_remap_local(l1, l3);
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrTypeConst_t*) t0)->f_type;
        t0 = l0.payload.obj;
        l5 = ((vader_struct_vader_midir_InstrTypeConst_t*) t0)->f_value_type;
        vader_struct_vader_midir_InstrTypeConst_t* _a21_obj = (vader_struct_vader_midir_InstrTypeConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrTypeConst_t));
        vader_obj_header_init(_a21_obj, 966u);
        _a21_obj->f_span = l2;
        _a21_obj->f_dst = l3;
        _a21_obj->f_type = l4;
        _a21_obj->f_value_type = l5;
        t0 = (void*) _a21_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 948u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_midir_InstrCast_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrCast_t*) t0)->f_dst;
        l3 = vader_midir_remap_local(l1, l3);
        t0 = l0.payload.obj;
        l6 = ((vader_struct_vader_midir_InstrCast_t*) t0)->f_value;
        l6 = vader_midir_remap_local(l1, l6);
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrCast_t*) t0)->f_type;
        vader_struct_vader_midir_InstrCast_t* _a22_obj = (vader_struct_vader_midir_InstrCast_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrCast_t));
        vader_obj_header_init(_a22_obj, 948u);
        _a22_obj->f_span = l2;
        _a22_obj->f_dst = l3;
        _a22_obj->f_value = l6;
        _a22_obj->f_type = l4;
        t0 = (void*) _a22_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 950u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_midir_InstrCellNew_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrCellNew_t*) t0)->f_dst;
        l3 = vader_midir_remap_local(l1, l3);
        t0 = l0.payload.obj;
        l6 = ((vader_struct_vader_midir_InstrCellNew_t*) t0)->f_value;
        l6 = vader_midir_remap_local(l1, l6);
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrCellNew_t*) t0)->f_value_type;
        vader_struct_vader_midir_InstrCellNew_t* _a23_obj = (vader_struct_vader_midir_InstrCellNew_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrCellNew_t));
        vader_obj_header_init(_a23_obj, 950u);
        _a23_obj->f_span = l2;
        _a23_obj->f_dst = l3;
        _a23_obj->f_value = l6;
        _a23_obj->f_value_type = l4;
        t0 = (void*) _a23_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 949u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_midir_InstrCellGet_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrCellGet_t*) t0)->f_dst;
        l3 = vader_midir_remap_local(l1, l3);
        t0 = l0.payload.obj;
        l6 = ((vader_struct_vader_midir_InstrCellGet_t*) t0)->f_cell;
        l6 = vader_midir_remap_local(l1, l6);
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrCellGet_t*) t0)->f_value_type;
        vader_struct_vader_midir_InstrCellGet_t* _a24_obj = (vader_struct_vader_midir_InstrCellGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrCellGet_t));
        vader_obj_header_init(_a24_obj, 949u);
        _a24_obj->f_span = l2;
        _a24_obj->f_dst = l3;
        _a24_obj->f_cell = l6;
        _a24_obj->f_value_type = l4;
        t0 = (void*) _a24_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 951u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_midir_InstrCellSet_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrCellSet_t*) t0)->f_cell;
        l3 = vader_midir_remap_local(l1, l3);
        t0 = l0.payload.obj;
        l6 = ((vader_struct_vader_midir_InstrCellSet_t*) t0)->f_value;
        l6 = vader_midir_remap_local(l1, l6);
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrCellSet_t*) t0)->f_value_type;
        vader_struct_vader_midir_InstrCellSet_t* _a25_obj = (vader_struct_vader_midir_InstrCellSet_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrCellSet_t));
        vader_obj_header_init(_a25_obj, 951u);
        _a25_obj->f_span = l2;
        _a25_obj->f_cell = l3;
        _a25_obj->f_value = l6;
        _a25_obj->f_value_type = l4;
        t0 = (void*) _a25_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 961u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_midir_InstrMakeClosure_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrMakeClosure_t*) t0)->f_dst;
        l3 = vader_midir_remap_local(l1, l3);
        t0 = l0.payload.obj;
        l9 = ((vader_struct_vader_midir_InstrMakeClosure_t*) t0)->f_fn_symbol;
        t0 = l0.payload.obj;
        l6 = ((vader_struct_vader_midir_InstrMakeClosure_t*) t0)->f_env;
        l6 = vader_midir_remap_local(l1, l6);
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrMakeClosure_t*) t0)->f_env_type;
        t0 = l0.payload.obj;
        l5 = ((vader_struct_vader_midir_InstrMakeClosure_t*) t0)->f_type;
        vader_struct_vader_midir_InstrMakeClosure_t* _a26_obj = (vader_struct_vader_midir_InstrMakeClosure_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrMakeClosure_t));
        vader_obj_header_init(_a26_obj, 961u);
        _a26_obj->f_span = l2;
        _a26_obj->f_dst = l3;
        _a26_obj->f_fn_symbol = l9;
        _a26_obj->f_env = l6;
        _a26_obj->f_env_type = l4;
        _a26_obj->f_type = l5;
        t0 = (void*) _a26_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 960u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_midir_InstrIntrinsic_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrIntrinsic_t*) t0)->f_dst;
        l4 = vader_midir_remap_local_opt(l1, l4);
        t0 = l0.payload.obj;
        l13 = ((vader_struct_vader_midir_InstrIntrinsic_t*) t0)->f_name;
        t0 = l0.payload.obj;
        l9 = ((vader_struct_vader_midir_InstrIntrinsic_t*) t0)->f_args;
        l9 = vader_midir_remap_locals(l1, l9);
        vader_struct_vader_midir_InstrIntrinsic_t* _a27_obj = (vader_struct_vader_midir_InstrIntrinsic_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrIntrinsic_t));
        vader_obj_header_init(_a27_obj, 960u);
        _a27_obj->f_span = l2;
        _a27_obj->f_dst = l4;
        _a27_obj->f_name = l13;
        _a27_obj->f_args = l9;
        t0 = (void*) _a27_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l0.tag == 955u)) {
        t0 = l0.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l0.payload.obj;
    l2 = ((vader_struct_vader_midir_InstrDeferPush_t*) t0)->f_span;
    t0 = l0.payload.obj;
    l3 = ((vader_struct_vader_midir_InstrDeferPush_t*) t0)->f_value;
    l3 = vader_midir_remap_local(l1, l3);
    vader_struct_vader_midir_InstrDeferPush_t* _a28_obj = (vader_struct_vader_midir_InstrDeferPush_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrDeferPush_t));
    vader_obj_header_init(_a28_obj, 955u);
    _a28_obj->f_span = l2;
    _a28_obj->f_value = l3;
    t0 = (void*) _a28_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static int32_t vader_midir_remap_local(void* l0, int32_t l1) {
    size_t l2, l3;
    int64_t t0;
    int32_t t1;
    t0 = ((int64_t) (int32_t) l1);
    l2 = (size_t) (int64_t) t0;
    l3 = ((vader_array_t*) l0)->length;
    if (!((l2 < l3))) {
        return l1;
    }
    t0 = ((int64_t) (int32_t) l1);
    l2 = (size_t) (int64_t) t0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
    t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l2];
    return t1;
}

static vader_box_t vader_midir_remap_local_opt(void* l0, vader_box_t l1) {
    int32_t l2;
    int32_t t0;
    vader_box_t t1;
    if (l1.tag == 0u) {
        return vader_box_obj(0u, NULL);
    }
    if (!(l1.tag == 246u)) {
        return vader_box_obj(0u, NULL);
    }
    l2 = ((int32_t) l1.payload.i);
    t0 = vader_midir_remap_local(l0, l2);
    t1 = vader_box_i32(246u, t0);
    return t1;
}

static void* vader_midir_remap_locals(void* l0, void* l1) {
    void* l2 = NULL;
    void* l4 = NULL;
    size_t l3, l5;
    int32_t l6, l7;
    int64_t t0;
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(14u, 0u, 7u, 246u);
    l2 = (void*) _a0_arr;
    l3 = ((vader_array_t*) l1)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l2, (size_t) l3);
    l2 = (void*) _a1_arr;
    l4 = l1;
    l3 = ((vader_array_t*) l4)->length;
    l5 = (size_t) 0;
    vader_array_t* _pc15_hdr = (vader_array_t*) l2;
    size_t _pc15_len = _pc15_hdr->length;
    size_t _pc15_cap = (_pc15_hdr->offset == 0 && !vader_array_is_borrowed(_pc15_hdr) && _pc15_hdr->length >= _pc15_hdr->buf->length) ? _pc15_hdr->capacity : (size_t) 0;
    void* _pc15_slots = _pc15_hdr->buf->slots;
    for (;;) {
        if ((l5 < l3)) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) l4);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l5)
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
            t0 = (l5 + INT64_C(1));
            l5 = (size_t) (int64_t) t0;
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
    if (l0.tag == 978u) {
        t0 = l0.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 981u) {
        t0 = l0.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 979u) {
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
        vader_obj_header_init(_a0_obj, 979u);
        _a0_obj->f_span = l2;
        _a0_obj->f_cond = l3;
        _a0_obj->f_then_block = l4;
        _a0_obj->f_else_block = l5;
        t0 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l0.tag == 980u)) {
        t1 = l0;
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l0.payload.obj;
    l2 = ((vader_struct_vader_midir_TermReturn_t*) t0)->f_span;
    t0 = l0.payload.obj;
    l6 = ((vader_struct_vader_midir_TermReturn_t*) t0)->f_values;
    l6 = vader_midir_remap_locals(l1, l6);
    vader_struct_vader_midir_TermReturn_t* _a1_obj = (vader_struct_vader_midir_TermReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_TermReturn_t));
    vader_obj_header_init(_a1_obj, 980u);
    _a1_obj->f_span = l2;
    _a1_obj->f_values = l6;
    t0 = (void*) _a1_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_midir_reserve_cfg_extern(void* l0, void* l1) {
    void* l2 = NULL;
    void* l4 = NULL;
    vader_box_t l3 = vader_box_null();
    int32_t l5, l11;
    vader_string_t l6 = 0;
    vader_string_t l7 = 0;
    vader_string_t l9 = 0;
    vader_string_t l10 = 0;
    bool l8;
    size_t t0;
    vader_box_t* gc_roots[1] = { &l3 };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &l4 };
    vader_string_t* gc_atom_roots[4] = { &l6, &l7, &l9, &l10 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_midir_CFGExternDecl_t*) l0)->f_params;
    l3 = ((vader_struct_vader_midir_CFGExternDecl_t*) l0)->f_return_type;
    vader_array_t* _a0_arr = vader_array_new(204u, 0u, 13u, 1535u);
    l4 = (void*) _a0_arr;
    l2 = vader_midir_build_cfg_signature(l2, l3, l4, l1);
    l4 = ((vader_struct_vader_midir_CFGExternDecl_t*) l0)->f_origin;
    l2 = vader_midir_with_param_decorators(l2, l4);
    t0 = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_imports)->length;
    l5 = ((int32_t) (size_t) t0);
    l4 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_imports;
    l6 = ((vader_struct_vader_midir_CFGExternDecl_t*) l0)->f_extern_name;
    l7 = ((vader_struct_vader_midir_CFGExternDecl_t*) l0)->f_mangled;
    l8 = ((vader_struct_vader_midir_CFGExternDecl_t*) l0)->f_is_extern;
    l9 = ((vader_struct_vader_midir_CFGExternDecl_t*) l0)->f_c_header;
    l10 = ((vader_struct_vader_midir_CFGExternDecl_t*) l0)->f_c_library;
    l11 = ((vader_struct_vader_midir_CFGExternDecl_t*) l0)->f_c_variadic_fixed;
    vader_struct_vader_bytecode_BcImport_t* _a1_obj = (vader_struct_vader_bytecode_BcImport_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcImport_t));
    vader_obj_header_init(_a1_obj, 553u);
    _a1_obj->f_extern_name = l6;
    _a1_obj->f_mangled_name = l7;
    _a1_obj->f_signature = l2;
    _a1_obj->f_is_extern = l8;
    _a1_obj->f_c_header = l9;
    _a1_obj->f_c_library = l10;
    _a1_obj->f_c_variadic_fixed = l11;
    l2 = (void*) _a1_obj;
    vader_array_push((vader_array_t*) l4, vader_ref_box(l2));
    if (((vader_struct_vader_comptime_MonoEntry_t*) ((vader_struct_vader_midir_CFGExternDecl_t*) l0)->f_origin)->f_symbol.tag == 1019u) {
        l2 = ((vader_struct_vader_comptime_MonoEntry_t*) ((vader_struct_vader_midir_CFGExternDecl_t*) l0)->f_origin)->f_symbol.payload.obj;
        l4 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_import_index_by_symbol_id;
        l11 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l2)->f_id;
        std_collections_MutableMap_IndexSet_set_at__i32__i32(l4, l11, l5);
    }
    l2 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_import_index_by_mangle;
    l6 = ((vader_struct_vader_midir_CFGExternDecl_t*) l0)->f_mangled;
    std_collections_MutableMap_IndexSet_set_at__string__i32(l2, l6, l5);
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
    size_t t0;
    vader_box_t* gc_roots[1] = { &l3 };
    void** gc_raw_roots[9] = { &l0, &l1, &l2, &l4, &l6, &l7, &l8, &l9, &l12 };
    vader_string_t* gc_atom_roots[1] = { &l10 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 9u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_params;
    l3 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_return_type;
    l4 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_scalarised_results;
    l2 = vader_midir_build_cfg_signature(l2, l3, l4, l1);
    t0 = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_functions)->length;
    l5 = ((int32_t) (size_t) t0);
    vader_array_t* _a0_arr = vader_array_new(187u, 0u, 13u, 1316u);
    l4 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(191u, 0u, 13u, 1370u);
    l6 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(14u, 0u, 7u, 246u);
    l7 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(46u, 0u, 13u, 554u);
    l8 = (void*) _a3_arr;
    l9 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_functions;
    l10 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_mangled;
    l11 = ((vader_struct_vader_comptime_MonoEntry_t*) ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_origin)->f_is_main;
    vader_array_t* _a4_arr = vader_array_new(14u, 0u, 7u, 246u);
    l12 = (void*) _a4_arr;
    vader_struct_vader_bytecode_BcFunction_t* _a5_obj = (vader_struct_vader_bytecode_BcFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcFunction_t));
    vader_obj_header_init(_a5_obj, 552u);
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
    if (((vader_struct_vader_comptime_MonoEntry_t*) ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_origin)->f_symbol.tag == 1019u) {
        l2 = ((vader_struct_vader_comptime_MonoEntry_t*) ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_origin)->f_symbol.payload.obj;
        l4 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_function_index_by_symbol_id;
        l13 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l2)->f_id;
        std_collections_MutableMap_IndexSet_set_at__i32__i32(l4, l13, l5);
    }
    l2 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_function_index_by_mangle;
    l10 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_mangled;
    std_collections_MutableMap_IndexSet_set_at__string__i32(l2, l10, l5);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_midir_reserve_cfg_struct(void* l0, void* l1) {
    int32_t l2, l8, l13;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l12 = NULL;
    void* l14 = NULL;
    vader_box_t l5 = vader_box_null(), l7 = vader_box_null();
    vader_string_t l6 = 0;
    vader_string_t l15 = 0;
    size_t l9, l11;
    uint64_t l10;
    void* t0 = NULL;
    size_t t1;
    int32_t t2;
    int64_t t3;
    vader_box_t t4 = vader_box_null();
    vader_string_t t5 = 0;
    vader_box_t* gc_roots[3] = { &l5, &l7, &t4 };
    void** gc_raw_roots[7] = { &l0, &l1, &l3, &l4, &l12, &l14, &t0 };
    vader_string_t* gc_atom_roots[3] = { &l6, &l15, &t5 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = -(INT32_C(1));
    if (((vader_struct_vader_comptime_MonoEntry_t*) ((vader_struct_vader_midir_CFGStructDecl_t*) l0)->f_origin)->f_symbol.tag == 1019u) {
        t0 = ((vader_struct_vader_comptime_MonoEntry_t*) ((vader_struct_vader_midir_CFGStructDecl_t*) l0)->f_origin)->f_symbol.payload.obj;
        l2 = ((vader_struct_vader_resolver_symbol_Symbol_t*) t0)->f_id;
    }
    if (((vader_struct_vader_comptime_MonoEntry_t*) ((vader_struct_vader_midir_CFGStructDecl_t*) l0)->f_origin)->f_symbol.tag == 1019u) {
        l3 = ((vader_struct_vader_comptime_MonoEntry_t*) ((vader_struct_vader_midir_CFGStructDecl_t*) l0)->f_origin)->f_symbol.payload.obj;
        l4 = ((vader_struct_vader_comptime_MonoEntry_t*) ((vader_struct_vader_midir_CFGStructDecl_t*) l0)->f_origin)->f_type_arguments;
        l5 = vader_types_mk_struct(l3, l4, false);
        l6 = vader_bytecode_type_intern_key(l5);
        l7 = std_collections_MutableMap_Index_at__string__i32(((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_type_key, l6);
        t1 = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_types)->length;
        l8 = ((int32_t) (size_t) t1);
        if (l7.tag == 246u) {
            l3 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_types;
            t2 = ((int32_t) l7.payload.i);
            t3 = ((int64_t) (int32_t) t2);
            l9 = (size_t) (int64_t) t3;
            vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l9)
            t4 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l9);
            if (t4.tag == 561u) {
                { vader_gc_top = gc_frame.prev; return; }
            }
            l8 = ((int32_t) l7.payload.i);
        } else {
            std_collections_MutableMap_IndexSet_set_at__string__i32(((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_type_key, l6, l8);
            l10 = vader_bytecode_type_intern_hash(l5);
            t4 = std_collections_MutableMap_Index_at__u64__i32(((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_type_hash, l10);
            if (t4.tag == 0u) {
                std_collections_MutableMap_IndexSet_set_at__u64__i32(((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_type_hash, l10, l8);
            }
            vader_bytecode_record_slot_type(l1, l8, l5);
            l3 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_types;
            t5 = ((vader_struct_vader_midir_CFGStructDecl_t*) l0)->f_mangled;
            vader_struct_vader_bytecode_BcRef_t* _a1_obj = (vader_struct_vader_bytecode_BcRef_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcRef_t));
            vader_obj_header_init(_a1_obj, 558u);
            _a1_obj->f_trait_name = t5;
            l4 = (void*) _a1_obj;
            vader_array_push((vader_array_t*) l3, vader_ref_box(l4));
        }
        vader_array_t* _a2_arr = vader_array_new(43u, 0u, 13u, 550u);
        l3 = (void*) _a2_arr;
        l9 = ((vader_array_t*) ((vader_struct_vader_midir_CFGStructDecl_t*) l0)->f_fields)->length;
        vader_array_t* _a3_arr = vader_array_repeat((vader_array_t*) l3, (size_t) l9);
        l3 = (void*) _a3_arr;
        l4 = ((vader_struct_vader_midir_CFGStructDecl_t*) l0)->f_fields;
        l9 = ((vader_array_t*) l4)->length;
        l11 = (size_t) 0;
        while ((l11 < l9)) {
            vader_array_t* _a4_slotarr = ((vader_array_t*) l4);
            VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l11)
            l12 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l11);
            l13 = vader_bytecode_intern_type(((vader_struct_vader_midir_CFGStructField_t*) l12)->f_type, l1);
            t5 = ((vader_struct_vader_midir_CFGStructField_t*) l12)->f_name;
            vader_struct_vader_bytecode_BcField_t* _a5_obj = (vader_struct_vader_bytecode_BcField_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcField_t));
            vader_obj_header_init(_a5_obj, 550u);
            _a5_obj->f_name = t5;
            _a5_obj->f_type_index = l13;
            l14 = (void*) _a5_obj;
            vader_array_push((vader_array_t*) l3, vader_ref_box(l14));
            t3 = (l11 + INT64_C(1));
            l11 = (size_t) (int64_t) t3;
        }
        l4 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_types;
        t3 = ((int64_t) (int32_t) l8);
        l9 = (size_t) (int64_t) t3;
        l6 = ((vader_struct_vader_midir_CFGStructDecl_t*) l0)->f_mangled;
        l15 = vader_midir_c_struct_of(((vader_struct_vader_midir_CFGStructDecl_t*) l0)->f_origin);
        vader_struct_vader_bytecode_BcStruct_t* _a6_obj = (vader_struct_vader_bytecode_BcStruct_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcStruct_t));
        vader_obj_header_init(_a6_obj, 561u);
        _a6_obj->f_name = l6;
        _a6_obj->f_fields = l3;
        _a6_obj->f_c_name = l15;
        _a6_obj->f_symbol_id = l2;
        l3 = (void*) _a6_obj;
        vader_array_t* _a7_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l9)
        vader_array_ref_store(_a7_slotarr->buf, _a7_slotarr->offset + (size_t) l9, l3);
        VADER_WRITE_BARRIER(_a7_slotarr->buf);
        { vader_gc_top = gc_frame.prev; return; }
    }
    t1 = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_types)->length;
    l8 = ((int32_t) (size_t) t1);
    l3 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_types;
    t5 = ((vader_struct_vader_midir_CFGStructDecl_t*) l0)->f_mangled;
    vader_struct_vader_bytecode_BcRef_t* _a8_obj = (vader_struct_vader_bytecode_BcRef_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcRef_t));
    vader_obj_header_init(_a8_obj, 558u);
    _a8_obj->f_trait_name = t5;
    l4 = (void*) _a8_obj;
    vader_array_push((vader_array_t*) l3, vader_ref_box(l4));
    vader_array_t* _a9_arr = vader_array_new(43u, 0u, 13u, 550u);
    l3 = (void*) _a9_arr;
    l9 = ((vader_array_t*) ((vader_struct_vader_midir_CFGStructDecl_t*) l0)->f_fields)->length;
    vader_array_t* _a10_arr = vader_array_repeat((vader_array_t*) l3, (size_t) l9);
    l3 = (void*) _a10_arr;
    l4 = ((vader_struct_vader_midir_CFGStructDecl_t*) l0)->f_fields;
    l9 = ((vader_array_t*) l4)->length;
    l11 = (size_t) 0;
    while ((l11 < l9)) {
        vader_array_t* _a11_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l11)
        l12 = vader_array_ref_load_obj(_a11_slotarr->buf, _a11_slotarr->offset + (size_t) l11);
        l13 = vader_bytecode_intern_type(((vader_struct_vader_midir_CFGStructField_t*) l12)->f_type, l1);
        t5 = ((vader_struct_vader_midir_CFGStructField_t*) l12)->f_name;
        vader_struct_vader_bytecode_BcField_t* _a12_obj = (vader_struct_vader_bytecode_BcField_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcField_t));
        vader_obj_header_init(_a12_obj, 550u);
        _a12_obj->f_name = t5;
        _a12_obj->f_type_index = l13;
        l14 = (void*) _a12_obj;
        vader_array_push((vader_array_t*) l3, vader_ref_box(l14));
        t3 = (l11 + INT64_C(1));
        l11 = (size_t) (int64_t) t3;
    }
    l4 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_types;
    t3 = ((int64_t) (int32_t) l8);
    l9 = (size_t) (int64_t) t3;
    l6 = ((vader_struct_vader_midir_CFGStructDecl_t*) l0)->f_mangled;
    l15 = vader_midir_c_struct_of(((vader_struct_vader_midir_CFGStructDecl_t*) l0)->f_origin);
    vader_struct_vader_bytecode_BcStruct_t* _a13_obj = (vader_struct_vader_bytecode_BcStruct_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcStruct_t));
    vader_obj_header_init(_a13_obj, 561u);
    _a13_obj->f_name = l6;
    _a13_obj->f_fields = l3;
    _a13_obj->f_c_name = l15;
    _a13_obj->f_symbol_id = l2;
    l3 = (void*) _a13_obj;
    vader_array_t* _a14_slotarr = ((vader_array_t*) l4);
    VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a14_slotarr, l9)
    vader_array_ref_store(_a14_slotarr->buf, _a14_slotarr->offset + (size_t) l9, l3);
    VADER_WRITE_BARRIER(_a14_slotarr->buf);
    l3 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_type_key;
    l6 = ((vader_struct_vader_midir_CFGStructDecl_t*) l0)->f_mangled;
    std_collections_MutableMap_IndexSet_set_at__string__i32(l3, l6, l8);
    { vader_gc_top = gc_frame.prev; return; }
}

static void* vader_midir_resolve_direct_call(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l7 = NULL;
    int32_t l4;
    vader_box_t l5 = vader_box_null();
    vader_string_t l6 = 0;
    vader_string_t l9 = 0;
    size_t l8, l10;
    int64_t l11;
    int32_t t0;
    int64_t t1;
    void* t2 = NULL;
    vader_string_t t3 = 0;
    vader_box_t* gc_roots[1] = { &l5 };
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l3, &l7, &t2 };
    vader_string_t* gc_atom_roots[3] = { &l6, &l9, &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project;
    l3 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l2)->f_import_index_by_symbol_id;
    l4 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_midir_InstrCall_t*) l1)->f_callee)->f_id;
    l5 = std_collections_MutableMap_Index_at__i32__i32(l3, l4);
    if (l5.tag == 246u) {
        t0 = ((int32_t) l5.payload.i);
        l5 = vader_box_i32(246u, t0);
    } else {
        l3 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l2)->f_import_index_by_mangle;
        l6 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_midir_InstrCall_t*) l1)->f_callee)->f_name;
        l5 = std_collections_MutableMap_Index_at__string__i32(l3, l6);
    }
    if (l5.tag == 246u) {
        l4 = ((int32_t) l5.payload.i);
        l3 = vader_midir_import_call_target(l2, l4);
        if (!(((vader_struct_vader_midir_DirectCallTarget_t*) l3)->f_op.tag == 584u)) {
            { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    l4 = vader_midir_resolve_fn_index(((vader_struct_vader_midir_InstrCall_t*) l1)->f_callee, l2);
    if ((l4 >= INT32_C(0))) {
        vader_struct_vader_bytecode_Call_t* _a0_obj = (vader_struct_vader_bytecode_Call_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_Call_t));
        vader_obj_header_init(_a0_obj, 583u);
        _a0_obj->f_function_index = l4;
        l3 = (void*) _a0_obj;
        l7 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l2)->f_functions;
        t1 = ((int64_t) (int32_t) l4);
        l8 = (size_t) (int64_t) t1;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l8)
        t2 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l8);
        l7 = ((vader_struct_vader_bytecode_BcFunction_t*) t2)->f_signature;
        vader_struct_vader_midir_DirectCallTarget_t* _a2_obj = (vader_struct_vader_midir_DirectCallTarget_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_DirectCallTarget_t));
        vader_obj_header_init(_a2_obj, 932u);
        _a2_obj->f_op = vader_ref_box(l3);
        _a2_obj->f_signature = l7;
        t2 = (void*) _a2_obj;
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l5.tag == 246u)) {
        l6 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_midir_InstrCall_t*) l1)->f_callee)->f_name;
        l9 = ((vader_struct_vader_midir_CFGFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_fn_)->f_mangled;
        l8 = vader_host_std_core_byte_len(l6);
        l10 = vader_host_std_core_byte_len(l9);
        t1 = (l8 + l10);
        l8 = (size_t) (int64_t) t1;
        l3 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(117) + l8));
        l8 = (size_t) 0;
        l8 = std_core_write_string_at(l3, l8, 1984u);
        l8 = std_core_write_string_at(l3, l8, l6);
        l8 = std_core_write_string_at(l3, l8, 214u);
        t0 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_midir_InstrCall_t*) l1)->f_callee)->f_id;
        l11 = ((int64_t) (int32_t) t0);
        l8 = std_core_write_int(l3, l8, l11);
        l8 = std_core_write_string_at(l3, l8, 253u);
        l8 = std_core_write_string_at(l3, l8, l9);
        l8 = std_core_write_string_at(l3, l8, 228u);
        t3 = std_core_finish_buffer(l3, l8);
        vader_host_std_abort_panic(t3);
        vader_unreachable("a no-return call returned");
    }
    l4 = ((int32_t) l5.payload.i);
    t2 = vader_midir_import_call_target(l2, l4);
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static int32_t vader_midir_resolve_fn_index(void* l0, void* l1) {
    void* l2;
    vader_string_t l3;
    vader_box_t l4;
    int32_t l5;
    int32_t t0;
    l2 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_function_index_by_mangle;
    l3 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l0)->f_name;
    l4 = std_collections_MutableMap_Index_at__string__i32(l2, l3);
    if (l4.tag == 246u) {
        t0 = ((int32_t) l4.payload.i);
        return t0;
    }
    l2 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_function_index_by_symbol_id;
    l5 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l0)->f_id;
    l4 = std_collections_MutableMap_Index_at__i32__i32(l2, l5);
    if (!(l4.tag == 246u)) {
        return -(INT32_C(1));
    }
    t0 = ((int32_t) l4.payload.i);
    return t0;
}

static void* vader_midir_resolve_loop_frame(void* l0, vader_box_t l1) {
    int64_t l2;
    void* l3 = NULL;
    void* l5 = NULL;
    size_t l4;
    vader_string_t l6 = 0;
    vader_string_t l7 = 0;
    size_t t0;
    int64_t t1;
    bool t2;
    vader_string_t t3 = 0;
    vader_string_t t4 = 0;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[3] = { &l0, &l3, &l5 };
    vader_string_t* gc_atom_roots[4] = { &l6, &l7, &t3, &t4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l1.tag == 0u) {
        t0 = ((vader_array_t*) ((vader_struct_vader_midir_FnCtx_t*) l0)->f_loop_stack)->length;
        l2 = (((int64_t) (size_t) t0) - INT64_C(1));
        while ((l2 >= INT64_C(0))) {
            l3 = ((vader_struct_vader_midir_FnCtx_t*) l0)->f_loop_stack;
            t1 = l2;
            l4 = (size_t) (int64_t) t1;
            vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
            l5 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
            t2 = ((vader_struct_vader_midir_LoopFrame_t*) l5)->f_block;
            if (!(t2)) {
                { void* __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
            }
            l2 = (l2 - INT64_C(1));
        }
        l6 = ((vader_struct_vader_midir_FnCtx_t*) l0)->f_mangled;
        t3 = concat_3(1979u, l6, 906u);
        vader_host_std_abort_panic(t3);
        vader_unreachable("a no-return call returned");
    } else {
        l6 = l1.payload.s;
        t0 = ((vader_array_t*) ((vader_struct_vader_midir_FnCtx_t*) l0)->f_loop_stack)->length;
        l2 = (((int64_t) (size_t) t0) - INT64_C(1));
        while ((l2 >= INT64_C(0))) {
            l3 = ((vader_struct_vader_midir_FnCtx_t*) l0)->f_loop_stack;
            t1 = l2;
            l4 = (size_t) (int64_t) t1;
            vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
            l5 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
            if (!(((vader_struct_vader_midir_LoopFrame_t*) l5)->f_label.tag == 0u)) {
                t3 = ((vader_struct_vader_midir_LoopFrame_t*) l5)->f_label.payload.s;
                if (t3 == l6) {
                    { void* __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
                }
            }
            l2 = (l2 - INT64_C(1));
        }
        l7 = ((vader_struct_vader_midir_FnCtx_t*) l0)->f_mangled;
        t3 = concat_5(1979u, l7, 970u, l6, 861u);
        t4 = concat_2(t3, 2317u);
        vader_host_std_abort_panic(t4);
        vader_unreachable("a no-return call returned");
    }
    vader_gc_top = gc_frame.prev;
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
    if (l1.tag == 978u) {
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir_TermBranch_t*) t0)->f_span;
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_midir_TermBranch_t*) t0)->f_target;
        l4 = vader_midir_destination(l0, l4);
        vader_struct_vader_midir_TermBranch_t* _a0_obj = (vader_struct_vader_midir_TermBranch_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_TermBranch_t));
        vader_obj_header_init(_a0_obj, 978u);
        _a0_obj->f_span = l3;
        _a0_obj->f_target = l4;
        t0 = (void*) _a0_obj;
        l2 = vader_ref_box(t0);
        { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 979u) {
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
        vader_obj_header_init(_a1_obj, 979u);
        _a1_obj->f_span = l5;
        _a1_obj->f_cond = l4;
        _a1_obj->f_then_block = l6;
        _a1_obj->f_else_block = l7;
        t0 = (void*) _a1_obj;
        l2 = vader_ref_box(t0);
    } else {
        if (!((l1.tag == 980u || l1.tag == 981u))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l2 = l1;
    }
    { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_midir_reverse_postorder(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    size_t l3;
    int32_t l4;
    int64_t t0;
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(14u, 0u, 7u, 246u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(11u, 1u, 12u, 241u);
    ((uint8_t*) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = (uint8_t) false;
    l2 = (void*) _a1_arr;
    l3 = ((vader_array_t*) ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_blocks)->length;
    vader_array_t* _a2_arr = vader_array_repeat((vader_array_t*) l2, (size_t) l3);
    l2 = (void*) _a2_arr;
    l4 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_entry;
    vader_midir_walk_rpo(l0, l4, l2, l1);
    vader_array_t* _a3_arr = vader_array_new(14u, 0u, 7u, 246u);
    l2 = (void*) _a3_arr;
    l3 = ((vader_array_t*) l1)->length;
    vader_array_t* _a4_arr = vader_array_repeat((vader_array_t*) l2, (size_t) l3);
    l2 = (void*) _a4_arr;
    l3 = ((vader_array_t*) l1)->length;
    vader_array_t* _pc31_hdr = (vader_array_t*) l2;
    size_t _pc31_len = _pc31_hdr->length;
    size_t _pc31_cap = (_pc31_hdr->offset == 0 && !vader_array_is_borrowed(_pc31_hdr) && _pc31_hdr->length >= _pc31_hdr->buf->length) ? _pc31_hdr->capacity : (size_t) 0;
    void* _pc31_slots = _pc31_hdr->buf->slots;
    for (;;) {
        if ((l3 > INT64_C(0))) {
            t0 = (l3 - INT64_C(1));
            l3 = (size_t) (int64_t) t0;
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

static void* vader_midir_rpo_positions(void* l0, size_t l1) {
    void* l2 = NULL;
    size_t l3, l4;
    int32_t l5, l6;
    void* t0 = NULL;
    int64_t t1;
    void** gc_raw_roots[3] = { &l0, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(14u, 1u, 7u, 246u);
    ((int32_t*) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = (int32_t) -(INT32_C(1));
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (size_t) l1);
    l2 = (void*) _a1_arr;
    l3 = (size_t) 0;
    l4 = ((vader_array_t*) l0)->length;
    while ((l3 < l4)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
        l5 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l3];
        l6 = ((int32_t) (size_t) l3);
        vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l5)
        ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l5] = (int32_t) l6;
        t1 = (l3 + INT64_C(1));
        l3 = (size_t) (int64_t) t1;
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
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
    size_t l4, l5, l7, l8, l9, l10, l13, l19, l21;
    vader_box_t l11 = vader_box_null(), l14 = vader_box_null(), l22 = vader_box_null(), l23 = vader_box_null();
    int64_t l16, l20, l25;
    int32_t l18, l27;
    int64_t t0;
    bool t1;
    size_t t2;
    vader_box_t* gc_roots[4] = { &l11, &l14, &l22, &l23 };
    void** gc_raw_roots[10] = { &l0, &l1, &l2, &l3, &l6, &l12, &l15, &l17, &l24, &l26 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 10u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_midir_count_uses(l0);
    l2 = vader_midir_no_hints();
    l3 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_blocks;
    l4 = ((vader_array_t*) l3)->length;
    l5 = (size_t) 0;
    while ((l5 < l4)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
        l6 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
        l7 = (size_t) 0;
        l8 = ((vader_array_t*) ((vader_struct_vader_midir_BasicBlock_t*) l6)->f_instructions)->length;
        while ((l7 < l8)) {
            t0 = (l7 + INT64_C(1));
            l9 = (size_t) (int64_t) t0;
            l10 = ((vader_array_t*) ((vader_struct_vader_midir_BasicBlock_t*) l6)->f_instructions)->length;
            if ((l9 >= l10)) break;
            vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_midir_BasicBlock_t*) l6)->f_instructions);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l7)
            l11 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l7);
            l12 = ((vader_struct_vader_midir_BasicBlock_t*) l6)->f_instructions;
            t0 = (l7 + INT64_C(1));
            l13 = (size_t) (int64_t) t0;
            vader_array_t* _a2_slotarr = ((vader_array_t*) l12);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l13)
            l14 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l13);
            t1 = vader_midir_can_pass_through_stack(l11, l14, l1);
            if (t1) {
                l15 = ((vader_struct_vader_midir_ScheduleHints_t*) l2)->f_skip_set;
                l16 = vader_midir_pos_key(((vader_struct_vader_midir_BasicBlock_t*) l6)->f_id, l7);
                std_collections_add__i64(l15, l16);
                l17 = ((vader_struct_vader_midir_ScheduleHints_t*) l2)->f_skip_first_get;
                l18 = ((vader_struct_vader_midir_BasicBlock_t*) l6)->f_id;
                t0 = (l7 + INT64_C(1));
                l19 = (size_t) (int64_t) t0;
                l20 = vader_midir_pos_key(l18, l19);
                std_collections_add__i64(l17, l20);
                t0 = (l7 + INT64_C(1));
                l7 = (size_t) (int64_t) t0;
                continue;
            }
            t0 = (l7 + INT64_C(1));
            l7 = (size_t) (int64_t) t0;
        }
        t2 = ((vader_array_t*) ((vader_struct_vader_midir_BasicBlock_t*) l6)->f_instructions)->length;
        if (t2 == INT64_C(0)) {
            t0 = (l5 + INT64_C(1));
            l5 = (size_t) (int64_t) t0;
            continue;
        }
        t2 = ((vader_array_t*) ((vader_struct_vader_midir_BasicBlock_t*) l6)->f_instructions)->length;
        t0 = (t2 - INT64_C(1));
        l21 = (size_t) (int64_t) t0;
        vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_midir_BasicBlock_t*) l6)->f_instructions);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l21)
        l22 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l21);
        l23 = ((vader_struct_vader_midir_BasicBlock_t*) l6)->f_terminator;
        t1 = vader_midir_can_pass_through_terminator(l22, l23, l1);
        if (t1) {
            l24 = ((vader_struct_vader_midir_ScheduleHints_t*) l2)->f_skip_set;
            l25 = vader_midir_pos_key(((vader_struct_vader_midir_BasicBlock_t*) l6)->f_id, l21);
            std_collections_add__i64(l24, l25);
            l26 = ((vader_struct_vader_midir_ScheduleHints_t*) l2)->f_skip_terminator_get;
            l27 = ((vader_struct_vader_midir_BasicBlock_t*) l6)->f_id;
            std_collections_add__i32(l26, l27);
            t0 = (l5 + INT64_C(1));
            l5 = (size_t) (int64_t) t0;
            continue;
        }
        t0 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t0;
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_midir_sets_equal(void* l0, void* l1) {
    size_t l2, l3;
    void* l4;
    void* l5;
    int32_t l6;
    int64_t t0;
    bool t1;
    l2 = std_collections_len__i32(l0);
    l3 = std_collections_len__i32(l1);
    if (l2 != l3) {
        return false;
    }
    l4 = l0;
    l5 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) ((vader_struct_std_collections_MutableSet__i32_t*) l4)->f_inner)->f_ekeys;
    l2 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) ((vader_struct_std_collections_MutableSet__i32_t*) l4)->f_inner)->f_size;
    l3 = (size_t) 0;
    while (!((l3 >= l2))) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        l6 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        t0 = (l3 + INT64_C(1));
        l3 = (size_t) (int64_t) t0;
        t1 = std_collections_MutableSet_Contains_contains__i32(l1, l6);
        if (!(t1)) {
            return false;
        }
    }
    return true;
}

static void* vader_midir_shape_of(void* l0, void* l1, void* l2) {
    size_t l3, l11, l12, l16, l17;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    void* l29 = NULL;
    void* l30 = NULL;
    void* l31 = NULL;
    void* l32 = NULL;
    void* l33 = NULL;
    void* l34 = NULL;
    void* l37 = NULL;
    int32_t l13, l14, l15, l18, l19, l20, l21, l22, l23, l24, l35, l38, l41, l42, l46, l48, l49, l50, l51, l52;
    vader_string_t l25 = 0;
    vader_string_t l26 = 0;
    vader_string_t l27 = 0;
    bool l28, l36, l39, l40, l43, l44, l45, l47;
    void* t0 = NULL;
    int64_t t1;
    int32_t t2;
    bool t3;
    vader_string_t t4 = 0;
    size_t t5;
    vader_box_t t6 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t6 };
    void** gc_raw_roots[18] = {
        &l0, &l1, &l2, &l4, &l5, &l6, &l7, &l8, &l9, &l10, &l29, &l30, &l31, &l32, &l33, &l34, &l37,
        &t0,
    };
    vader_string_t* gc_atom_roots[4] = { &l25, &l26, &l27, &t4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 18u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = ((vader_array_t*) ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_blocks)->length;
    l4 = vader_midir_reverse_postorder(l0);
    l5 = vader_midir_rpo_positions(l4, l3);
    l6 = vader_midir_natural_loop_bodies(l0, l1, l2);
    vader_array_t* _a0_arr = vader_array_new(11u, 1u, 12u, 241u);
    ((uint8_t*) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = (uint8_t) false;
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (size_t) l3);
    l7 = (void*) _a1_arr;
    l8 = l6;
    l9 = ((vader_struct_std_collections_MutableMap__i32__MutableSet_i32__t*) l8)->f_ekeys;
    l10 = ((vader_struct_std_collections_MutableMap__i32__MutableSet_i32__t*) l8)->f_evals;
    l11 = ((vader_struct_std_collections_MutableMap__i32__MutableSet_i32__t*) l8)->f_size;
    l12 = (size_t) 0;
    while (!((l12 >= l11))) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l9);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l12)
        l13 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l12];
        vader_array_t* _a3_slotarr = ((vader_array_t*) l10);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l12)
        t0 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l12);
        l14 = l13;
        t1 = (l12 + INT64_C(1));
        l12 = (size_t) (int64_t) t1;
        l15 = l14;
        vader_array_t* _a4_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l15)
        ((uint8_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l15] = (uint8_t) true;
    }
    vader_array_t* _a5_arr = vader_array_new(14u, 1u, 7u, 246u);
    ((int32_t*) _a5_arr->buf->slots)[_a5_arr->offset + 0u] = (int32_t) INT32_C(0);
    t0 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_repeat((vader_array_t*) t0, (size_t) l3);
    l8 = (void*) _a6_arr;
    l9 = l4;
    l11 = ((vader_array_t*) l9)->length;
    l12 = (size_t) 0;
    while ((l12 < l11)) {
        vader_array_t* _a7_slotarr = ((vader_array_t*) l9);
        VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l12)
        l13 = ((int32_t*) _a7_slotarr->buf->slots)[_a7_slotarr->offset + (size_t) l12];
        l14 = l13;
        vader_array_t* _a8_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l14)
        l10 = vader_array_ref_load_obj(_a8_slotarr->buf, _a8_slotarr->offset + (size_t) l14);
        l16 = ((vader_array_t*) l10)->length;
        l17 = (size_t) 0;
        while ((l17 < l16)) {
            vader_array_t* _a9_slotarr = ((vader_array_t*) l10);
            VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l17)
            l15 = ((int32_t*) _a9_slotarr->buf->slots)[_a9_slotarr->offset + (size_t) l17];
            l18 = l15;
            vader_array_t* _a10_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a10_slotarr, l18)
            t2 = ((int32_t*) _a10_slotarr->buf->slots)[_a10_slotarr->offset + (size_t) l18];
            if ((t2 < INT32_C(0))) {
                t1 = (l17 + INT64_C(1));
                l17 = (size_t) (int64_t) t1;
                continue;
            }
            l19 = l15;
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
                t2 = ((int32_t*) _a12_slotarr->buf->slots)[_a12_slotarr->offset + (size_t) l23];
                l24 = (t2 + INT32_C(1));
                VADER_ARRAY_CHECK_INDEX(_a12_slotarr, l23)
                ((int32_t*) _a12_slotarr->buf->slots)[_a12_slotarr->offset + (size_t) l23] = (int32_t) l24;
            } else {
                t3 = vader_midir_closes_loop(l6, l15, l13);
                if (!(t3)) {
                    l25 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_mangled;
                    l26 = vader_vt_std_core_Display__to_string(vader_box_i32(246u, l15));
                    l27 = vader_vt_std_core_Display__to_string(vader_box_i32(246u, l13));
                    t4 = concat_7(1988u, l25, 226u, l26, 173u, l27, 66u);
                    vader_host_std_abort_panic(t4);
                    vader_unreachable("a no-return call returned");
                }
            }
            t1 = (l17 + INT64_C(1));
            l17 = (size_t) (int64_t) t1;
        }
        t1 = (l12 + INT64_C(1));
        l12 = (size_t) (int64_t) t1;
    }
    vader_array_t* _a13_arr = vader_array_new(11u, 1u, 12u, 241u);
    ((uint8_t*) _a13_arr->buf->slots)[_a13_arr->offset + 0u] = (uint8_t) false;
    t0 = (void*) _a13_arr;
    vader_array_t* _a14_arr = vader_array_repeat((vader_array_t*) t0, (size_t) l3);
    l9 = (void*) _a14_arr;
    l11 = (size_t) 0;
    l12 = ((vader_array_t*) l4)->length;
    while ((l11 < l12)) {
        t5 = ((vader_array_t*) l4)->length;
        t1 = ((t5 - INT64_C(1)) - l11);
        l16 = (size_t) (int64_t) t1;
        vader_array_t* _a15_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a15_slotarr, l16)
        l13 = ((int32_t*) _a15_slotarr->buf->slots)[_a15_slotarr->offset + (size_t) l16];
        l14 = l13;
        l15 = l13;
        vader_array_t* _a16_slotarr = ((vader_array_t*) l9);
        VADER_ARRAY_RESOLVE_BUF(_a16_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a16_slotarr, l15)
        t6 = vader_box_bool(241u, ((uint8_t*) _a16_slotarr->buf->slots)[_a16_slotarr->offset + (size_t) l15]);
        t3 = t6.payload.b;
        if (t3) {
            l28 = true;
        } else {
            l18 = l13;
            vader_array_t* _a17_slotarr = ((vader_array_t*) l7);
            VADER_ARRAY_RESOLVE_BUF(_a17_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a17_slotarr, l18)
            t6 = vader_box_bool(241u, ((uint8_t*) _a17_slotarr->buf->slots)[_a17_slotarr->offset + (size_t) l18]);
            l28 = t6.payload.b;
        }
        vader_array_t* _a18_slotarr = ((vader_array_t*) l9);
        VADER_ARRAY_RESOLVE_BUF(_a18_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a18_slotarr, l14)
        ((uint8_t*) _a18_slotarr->buf->slots)[_a18_slotarr->offset + (size_t) l14] = (uint8_t) l28;
        l19 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_entry;
        t3 = vader_midir_BlockId_Equals_equals(l13, l19);
        if (!(t3)) {
            l20 = l13;
            vader_array_t* _a19_slotarr = ((vader_array_t*) l9);
            VADER_ARRAY_RESOLVE_BUF(_a19_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a19_slotarr, l20)
            t6 = vader_box_bool(241u, ((uint8_t*) _a19_slotarr->buf->slots)[_a19_slotarr->offset + (size_t) l20]);
            t3 = t6.payload.b;
            if (t3) {
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
        t1 = (l11 + INT64_C(1));
        l11 = (size_t) (int64_t) t1;
    }
    vader_array_t* _a22_arr = vader_array_new(11u, 1u, 12u, 241u);
    ((uint8_t*) _a22_arr->buf->slots)[_a22_arr->offset + 0u] = (uint8_t) false;
    t0 = (void*) _a22_arr;
    vader_array_t* _a23_arr = vader_array_repeat((vader_array_t*) t0, (size_t) l3);
    l10 = (void*) _a23_arr;
    vader_array_t* _a24_arr = vader_array_new(11u, 1u, 12u, 241u);
    ((uint8_t*) _a24_arr->buf->slots)[_a24_arr->offset + 0u] = (uint8_t) false;
    t0 = (void*) _a24_arr;
    vader_array_t* _a25_arr = vader_array_repeat((vader_array_t*) t0, (size_t) l3);
    l29 = (void*) _a25_arr;
    vader_array_t* _a26_arr = vader_array_new(2u, 0u, 13u, 14u);
    t0 = (void*) _a26_arr;
    vader_array_t* _a27_arr = vader_array_repeat((vader_array_t*) t0, (size_t) l3);
    l30 = (void*) _a27_arr;
    vader_array_t* _a28_arr = vader_array_new(2u, 0u, 13u, 14u);
    t0 = (void*) _a28_arr;
    vader_array_t* _a29_arr = vader_array_repeat((vader_array_t*) t0, (size_t) l3);
    l31 = (void*) _a29_arr;
    vader_array_t* _a30_arr = vader_array_new(14u, 1u, 7u, 246u);
    ((int32_t*) _a30_arr->buf->slots)[_a30_arr->offset + 0u] = (int32_t) -(INT32_C(1));
    t0 = (void*) _a30_arr;
    vader_array_t* _a31_arr = vader_array_repeat((vader_array_t*) t0, (size_t) l3);
    l32 = (void*) _a31_arr;
    l11 = (size_t) 0;
    while ((l11 < l3)) {
        vader_array_t* _a32_arr = vader_array_new(14u, 0u, 7u, 246u);
        l33 = (void*) _a32_arr;
        vader_array_push((vader_array_t*) l30, vader_ref_box(l33));
        vader_array_t* _a33_arr = vader_array_new(14u, 0u, 7u, 246u);
        l34 = (void*) _a33_arr;
        vader_array_push((vader_array_t*) l31, vader_ref_box(l34));
        t1 = (l11 + INT64_C(1));
        l11 = (size_t) (int64_t) t1;
    }
    l3 = ((vader_array_t*) l4)->length;
    l11 = (size_t) 0;
    while ((l11 < l3)) {
        vader_array_t* _a34_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a34_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a34_slotarr, l11)
        l13 = ((int32_t*) _a34_slotarr->buf->slots)[_a34_slotarr->offset + (size_t) l11];
        l14 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_entry;
        t3 = vader_midir_BlockId_Equals_equals(l13, l14);
        if (t3) {
            t1 = (l11 + INT64_C(1));
            l11 = (size_t) (int64_t) t1;
            continue;
        }
        l15 = l13;
        vader_array_t* _a35_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a35_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a35_slotarr, l15)
        t2 = ((int32_t*) _a35_slotarr->buf->slots)[_a35_slotarr->offset + (size_t) l15];
        if ((t2 >= INT32_C(2))) {
            l18 = l13;
            vader_array_t* _a36_slotarr = ((vader_array_t*) l1);
            VADER_ARRAY_RESOLVE_BUF(_a36_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a36_slotarr, l18)
            l33 = vader_array_ref_load_obj(_a36_slotarr->buf, _a36_slotarr->offset + (size_t) l18);
            t3 = vader_midir_entered_by_test(l6, l33, l13);
            l28 = !(t3);
        } else {
            l28 = false;
        }
        if (l28) {
            l34 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_blocks;
            l19 = l13;
            vader_array_t* _a37_slotarr = ((vader_array_t*) l34);
            VADER_ARRAY_RESOLVE_BUF(_a37_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a37_slotarr, l19)
            t0 = vader_array_ref_load_obj(_a37_slotarr->buf, _a37_slotarr->offset + (size_t) l19);
            t3 = vader_midir_copies_cheaply(t0);
            if (t3) {
                l20 = l13;
                vader_array_t* _a38_slotarr = ((vader_array_t*) l29);
                VADER_ARRAY_RESOLVE_BUF(_a38_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a38_slotarr, l20)
                ((uint8_t*) _a38_slotarr->buf->slots)[_a38_slotarr->offset + (size_t) l20] = (uint8_t) true;
                t1 = (l11 + INT64_C(1));
                l11 = (size_t) (int64_t) t1;
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
            l35 = l24;
            l36 = vader_midir_tests_its_exit(l0, l6, l35);
            l37 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_blocks;
            l38 = l13;
            vader_array_t* _a40_slotarr = ((vader_array_t*) l37);
            VADER_ARRAY_RESOLVE_BUF(_a40_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a40_slotarr, l38)
            t0 = vader_array_ref_load_obj(_a40_slotarr->buf, _a40_slotarr->offset + (size_t) l38);
            l39 = vader_midir_ends_function(((vader_struct_vader_midir_BasicBlock_t*) t0)->f_terminator);
            l41 = l13;
            vader_array_t* _a41_slotarr = ((vader_array_t*) l8);
            VADER_ARRAY_RESOLVE_BUF(_a41_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a41_slotarr, l41)
            t2 = ((int32_t*) _a41_slotarr->buf->slots)[_a41_slotarr->offset + (size_t) l41];
            if ((t2 < INT32_C(2))) {
                l42 = l13;
                vader_array_t* _a42_slotarr = ((vader_array_t*) l9);
                VADER_ARRAY_RESOLVE_BUF(_a42_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a42_slotarr, l42)
                t6 = vader_box_bool(241u, ((uint8_t*) _a42_slotarr->buf->slots)[_a42_slotarr->offset + (size_t) l42]);
                t3 = t6.payload.b;
                l40 = !(t3);
            } else {
                l40 = false;
            }
            if (l36) {
                l44 = true;
            } else {
                l44 = l39;
            }
            if (l44) {
                l45 = true;
            } else {
                l45 = l40;
            }
            if (l45) {
                l46 = l22;
                t3 = vader_midir_leaves_header(l6, l46, l13);
                l43 = !(t3);
            } else {
                l43 = false;
            }
            if (!(l43)) {
                l47 = true;
            } else {
                l48 = l13;
                vader_array_t* _a43_slotarr = ((vader_array_t*) l1);
                VADER_ARRAY_RESOLVE_BUF(_a43_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a43_slotarr, l48)
                t0 = vader_array_ref_load_obj(_a43_slotarr->buf, _a43_slotarr->offset + (size_t) l48);
                t3 = vader_midir_emitted_beneath(t0, l5, l2, l32, l22);
                l47 = !(t3);
            }
            if (l47) {
                vader_array_t* _a44_slotarr = ((vader_array_t*) l31);
                VADER_ARRAY_RESOLVE_BUF(_a44_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a44_slotarr, l24)
                t0 = vader_array_ref_load_obj(_a44_slotarr->buf, _a44_slotarr->offset + (size_t) l24);
                vader_array_push_i32((vader_array_t*) t0, l13);
                l49 = l13;
                vader_array_t* _a45_slotarr = ((vader_array_t*) l32);
                VADER_ARRAY_RESOLVE_BUF(_a45_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a45_slotarr, l49)
                ((int32_t*) _a45_slotarr->buf->slots)[_a45_slotarr->offset + (size_t) l49] = (int32_t) l24;
                l50 = l13;
                vader_array_t* _a46_slotarr = ((vader_array_t*) l10);
                VADER_ARRAY_RESOLVE_BUF(_a46_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a46_slotarr, l50)
                ((uint8_t*) _a46_slotarr->buf->slots)[_a46_slotarr->offset + (size_t) l50] = (uint8_t) true;
                t1 = (l11 + INT64_C(1));
                l11 = (size_t) (int64_t) t1;
                continue;
            }
        }
        l51 = l13;
        vader_array_t* _a47_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a47_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a47_slotarr, l51)
        t2 = ((int32_t*) _a47_slotarr->buf->slots)[_a47_slotarr->offset + (size_t) l51];
        if ((t2 >= INT32_C(2))) {
            vader_array_t* _a48_slotarr = ((vader_array_t*) l30);
            VADER_ARRAY_RESOLVE_BUF(_a48_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a48_slotarr, l22)
            t0 = vader_array_ref_load_obj(_a48_slotarr->buf, _a48_slotarr->offset + (size_t) l22);
            vader_array_push_i32((vader_array_t*) t0, l13);
            l52 = l13;
            vader_array_t* _a49_slotarr = ((vader_array_t*) l10);
            VADER_ARRAY_RESOLVE_BUF(_a49_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a49_slotarr, l52)
            ((uint8_t*) _a49_slotarr->buf->slots)[_a49_slotarr->offset + (size_t) l52] = (uint8_t) true;
        }
        t1 = (l11 + INT64_C(1));
        l11 = (size_t) (int64_t) t1;
    }
    vader_struct_vader_midir_StructureShape_t* _a50_obj = (vader_struct_vader_midir_StructureShape_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_StructureShape_t));
    vader_obj_header_init(_a50_obj, 977u);
    _a50_obj->f_rpo_index = l5;
    _a50_obj->f_loop_header = l7;
    _a50_obj->f_merge = l10;
    _a50_obj->f_merges = l30;
    _a50_obj->f_exits = l31;
    _a50_obj->f_copied = l29;
    t0 = (void*) _a50_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_midir_skip_forwarding_blocks(void* l0) {
    size_t l1, l4, l5, l7, l8;
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
    size_t t3;
    bool t4;
    vader_box_t* gc_roots[2] = { &l14, &l20 };
    void** gc_raw_roots[10] = { &l0, &l2, &l3, &l6, &l12, &l13, &l17, &l21, &l22, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l23, &l24 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 10u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = ((vader_array_t*) ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_blocks)->length;
    vader_array_t* _a0_arr = vader_array_new(14u, 1u, 7u, 246u);
    ((int32_t*) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = (int32_t) INT32_C(0);
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (size_t) l1);
    l2 = (void*) _a1_arr;
    l3 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_blocks;
    l4 = ((vader_array_t*) l3)->length;
    l5 = (size_t) 0;
    while ((l5 < l4)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l5)
        t0 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l5);
        l6 = vader_midir_successors_of(t0);
        l7 = ((vader_array_t*) l6)->length;
        l8 = (size_t) 0;
        while ((l8 < l7)) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l6);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            l9 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l8];
            vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l9)
            t1 = ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l9];
            l10 = (t1 + INT32_C(1));
            VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l9)
            ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l9] = (int32_t) l10;
            t2 = (l8 + INT64_C(1));
            l8 = (size_t) (int64_t) t2;
        }
        t2 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t2;
    }
    vader_array_t* _a5_arr = vader_array_new(14u, 1u, 7u, 246u);
    ((int32_t*) _a5_arr->buf->slots)[_a5_arr->offset + 0u] = (int32_t) -(INT32_C(1));
    t0 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_repeat((vader_array_t*) t0, (size_t) l1);
    l3 = (void*) _a6_arr;
    l11 = false;
    vader_array_t* _a7_arr = vader_array_new(14u, 0u, 7u, 246u);
    l6 = (void*) _a7_arr;
    l12 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_blocks;
    l1 = ((vader_array_t*) l12)->length;
    l4 = (size_t) 0;
    vader_array_t* _pc77_hdr = (vader_array_t*) l6;
    size_t _pc77_len = _pc77_hdr->length;
    size_t _pc77_cap = (_pc77_hdr->offset == 0 && !vader_array_is_borrowed(_pc77_hdr) && _pc77_hdr->length >= _pc77_hdr->buf->length) ? _pc77_hdr->capacity : (size_t) 0;
    void* _pc77_slots = _pc77_hdr->buf->slots;
    for (;;) {
        if ((l4 < l1)) {
            vader_array_t* _a8_slotarr = ((vader_array_t*) l12);
            VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l4)
            l13 = vader_array_ref_load_obj(_a8_slotarr->buf, _a8_slotarr->offset + (size_t) l4);
            l14 = ((vader_struct_vader_midir_BasicBlock_t*) l13)->f_terminator;
            t3 = ((vader_array_t*) ((vader_struct_vader_midir_BasicBlock_t*) l13)->f_instructions)->length;
            if (t3 == INT64_C(0)) {
                if (l14.tag == 978u) {
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
                        if (VADER_LIKELY(_pc77_len < _pc77_cap)) {
                            ((int32_t*) _pc77_slots)[_pc77_len] = (int32_t) (l16);
                            _pc77_len += 1;
                        } else {
                            _pc77_hdr->length = _pc77_len;
                            if (_pc77_hdr->buf->length < _pc77_len) {
                                _pc77_hdr->buf->length = _pc77_len;
                            }
                            vader_array_push_i32((vader_array_t*) l6, l16);
                            _pc77_hdr = (vader_array_t*) l6;
                            _pc77_len = _pc77_hdr->length;
                            _pc77_cap = (_pc77_hdr->offset == 0 && !vader_array_is_borrowed(_pc77_hdr) && _pc77_hdr->length >= _pc77_hdr->buf->length) ? _pc77_hdr->capacity : (size_t) 0;
                            _pc77_slots = _pc77_hdr->buf->slots;
                        }
                    }
                }
            }
            t2 = (l4 + INT64_C(1));
            l4 = (size_t) (int64_t) t2;
            continue;
        }
        _pc77_hdr->length = _pc77_len;
        if (_pc77_hdr->buf->length < _pc77_len) {
            _pc77_hdr->buf->length = _pc77_len;
        }
        break;
    }
    t3 = ((vader_array_t*) l6)->length;
    if ((t3 > INT64_C(0))) {
        l2 = vader_midir_predecessors_of(l0);
        l12 = vader_midir_compute_dominators(l0, l2);
        l12 = vader_midir_natural_loop_bodies(l0, l2, l12);
        l1 = ((vader_array_t*) l6)->length;
        l4 = (size_t) 0;
        while ((l4 < l1)) {
            vader_array_t* _a11_slotarr = ((vader_array_t*) l6);
            VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l4)
            l9 = ((int32_t*) _a11_slotarr->buf->slots)[_a11_slotarr->offset + (size_t) l4];
            l13 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_blocks;
            l10 = l9;
            vader_array_t* _a12_slotarr = ((vader_array_t*) l13);
            VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a12_slotarr, l10)
            t0 = vader_array_ref_load_obj(_a12_slotarr->buf, _a12_slotarr->offset + (size_t) l10);
            l14 = ((vader_struct_vader_midir_BasicBlock_t*) t0)->f_terminator;
            if (l14.tag == 978u) {
                l15 = l9;
                vader_array_t* _a13_slotarr = ((vader_array_t*) l2);
                VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a13_slotarr, l15)
                l17 = vader_array_ref_load_obj(_a13_slotarr->buf, _a13_slotarr->offset + (size_t) l15);
                t0 = l14.payload.obj;
                l16 = ((vader_struct_vader_midir_TermBranch_t*) t0)->f_target;
                t4 = vader_midir_goes_on_or_out(l0, l12, l17, l16);
                if (t4) {
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
            t2 = (l4 + INT64_C(1));
            l4 = (size_t) (int64_t) t2;
        }
    }
    if (!(l11)) {
        { void* __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a15_arr = vader_array_new(102u, 0u, 13u, 916u);
    l2 = (void*) _a15_arr;
    l1 = ((vader_array_t*) ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_blocks)->length;
    vader_array_t* _a16_arr = vader_array_repeat((vader_array_t*) l2, (size_t) l1);
    l2 = (void*) _a16_arr;
    l6 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_blocks;
    l1 = ((vader_array_t*) l6)->length;
    l4 = (size_t) 0;
    while ((l4 < l1)) {
        vader_array_t* _a17_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a17_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a17_slotarr, l4)
        l12 = vader_array_ref_load_obj(_a17_slotarr->buf, _a17_slotarr->offset + (size_t) l4);
        l13 = l12;
        l9 = ((vader_struct_vader_midir_BasicBlock_t*) l13)->f_id;
        l17 = ((vader_struct_vader_midir_BasicBlock_t*) l13)->f_instructions;
        l14 = ((vader_struct_vader_midir_BasicBlock_t*) l12)->f_terminator;
        l20 = vader_midir_retargeted(l3, l14);
        l21 = ((vader_struct_vader_midir_BasicBlock_t*) l13)->f_span;
        vader_struct_vader_midir_BasicBlock_t* _a18_obj = (vader_struct_vader_midir_BasicBlock_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_BasicBlock_t));
        vader_obj_header_init(_a18_obj, 916u);
        _a18_obj->f_id = l9;
        _a18_obj->f_instructions = l17;
        _a18_obj->f_terminator = l20;
        _a18_obj->f_span = l21;
        l22 = (void*) _a18_obj;
        vader_array_push((vader_array_t*) l2, vader_ref_box(l22));
        t2 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t2;
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
    vader_obj_header_init(_a19_obj, 918u);
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

static int32_t vader_midir_struct_symbol_id(vader_box_t l0) {
    void* t0;
    int32_t t1;
    if (!(l0.tag == 1088u)) {
        return -(INT32_C(1));
    }
    t0 = l0.payload.obj;
    t1 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_types_StructType_t*) t0)->f_symbol)->f_id;
    return t1;
}

static void vader_midir_structure_function(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    int32_t l4, l5;
    vader_string_t l6 = 0;
    vader_string_t l7 = 0;
    size_t t0;
    void* t1 = NULL;
    vader_string_t t2 = 0;
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &t1 };
    vader_string_t* gc_atom_roots[3] = { &l6, &l7, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = vader_midir_predecessors_of(((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_fn_);
    l2 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_fn_;
    l3 = vader_midir_compute_dominators(((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_fn_, l1);
    l1 = vader_midir_shape_of(l2, l1, l3);
    l4 = ((vader_struct_vader_midir_CFGFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_fn_)->f_entry;
    l5 = -(INT32_C(1));
    vader_midir_emit_subtree(l0, l1, l4, l5);
    t0 = ((vader_array_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_pending)->length;
    if (!((t0 > INT64_C(0)))) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l6 = ((vader_struct_vader_midir_CFGFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_fn_)->f_mangled;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_pending);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
    t1 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT32_C(0));
    l7 = vader_vt_std_core_Display__to_string(vader_box_i32(246u, ((vader_struct_vader_midir_PendingBranch_t*) t1)->f_target_blk));
    t2 = concat_5(1988u, l6, 224u, l7, 78u);
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
    if (l1.tag == 978u) {
        t0 = l2.payload.obj;
        vader_array_t* _a0_arr = vader_array_new(14u, 1u, 7u, 246u);
        ((int32_t*) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = (int32_t) ((vader_struct_vader_midir_TermBranch_t*) t0)->f_target;
        t0 = (void*) _a0_arr;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 979u) {
        t0 = l2.payload.obj;
        l3 = ((vader_struct_vader_midir_TermCondBranch_t*) t0)->f_then_block;
        t0 = l2.payload.obj;
        l4 = ((vader_struct_vader_midir_TermCondBranch_t*) t0)->f_else_block;
        vader_array_t* _a1_arr = vader_array_new(14u, 2u, 7u, 246u);
        ((int32_t*) _a1_arr->buf->slots)[_a1_arr->offset + 1u] = (int32_t) l4;
        ((int32_t*) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = (int32_t) l3;
        t0 = (void*) _a1_arr;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 980u) {
        vader_array_t* _a2_arr = vader_array_new(14u, 0u, 7u, 246u);
        t0 = (void*) _a2_arr;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l1.tag == 981u)) {
        vader_unreachable("non-exhaustive match (T3013 should have caught this)");
    }
    vader_array_t* _a3_arr = vader_array_new(14u, 0u, 7u, 246u);
    t0 = (void*) _a3_arr;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_midir_synthesise_cfg_intrinsic_wrappers(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l11 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    void* l15 = NULL;
    void* l18 = NULL;
    void* l20 = NULL;
    void* l24 = NULL;
    void* l26 = NULL;
    void* l28 = NULL;
    void* l29 = NULL;
    void* l30 = NULL;
    void* l31 = NULL;
    size_t l5, l6, l16, l17, l19, l21, l22;
    vader_string_t l7 = 0;
    vader_string_t l12 = 0;
    vader_string_t l27 = 0;
    vader_string_t l32 = 0;
    int32_t l8, l9, l10, l23, l25;
    void* t0 = NULL;
    int64_t t1;
    size_t t2;
    bool t3;
    vader_box_t t4 = vader_box_null();
    vader_string_t t5 = 0;
    vader_box_t* gc_roots[1] = { &t4 };
    void** gc_raw_roots[18] = {
        &l0, &l1, &l2, &l3, &l4, &l11, &l13, &l14, &l15, &l18, &l20, &l24, &l26, &l28, &l29, &l30,
        &l31, &t0,
    };
    vader_string_t* gc_atom_roots[5] = { &l7, &l12, &l27, &l32, &t5 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 18u, gc_roots, gc_raw_roots, 0u, NULL, 5u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(13u, 0u, 0u, 243u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(11u, 0u, 12u, 241u);
    l3 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(14u, 0u, 7u, 246u);
    l4 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__string__bool_t* _a3_obj = (vader_struct_std_collections_MutableMap__string__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__bool_t));
    vader_obj_header_init(_a3_obj, 383u);
    _a3_obj->f_ekeys = l2;
    _a3_obj->f_evals = l3;
    _a3_obj->f_index = l4;
    _a3_obj->f_mask = (size_t) 0;
    _a3_obj->f_size = (size_t) 0;
    _a3_obj->f_tombs = (size_t) 0;
    l2 = (void*) _a3_obj;
    l3 = ((vader_struct_vader_midir_CFGProject_t*) l0)->f_vtable_entries;
    l5 = ((vader_array_t*) l3)->length;
    l6 = (size_t) 0;
    while ((l6 < l5)) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l6)
        t0 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l6);
        l7 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_lower_LoweredVtableEntry_t*) t0)->f_fn_symbol)->f_name;
        std_collections_MutableMap_IndexSet_set_at__string__bool(l2, l7, true);
        t1 = (l6 + INT64_C(1));
        l6 = (size_t) (int64_t) t1;
    }
    t2 = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_imports)->length;
    l8 = ((int32_t) (size_t) t2);
    l9 = INT32_C(0);
    while ((l9 < l8)) {
        l3 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_imports;
        t1 = ((int64_t) (int32_t) l9);
        l5 = (size_t) (int64_t) t1;
        vader_array_t* _a5_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l5)
        l4 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l5);
        l10 = l9;
        l9 = (l9 + INT32_C(1));
        t3 = ((vader_struct_vader_bytecode_BcImport_t*) l4)->f_is_extern;
        if (t3) {
            continue;
        }
        l7 = ((vader_struct_vader_bytecode_BcImport_t*) l4)->f_mangled_name;
        t4 = std_collections_MutableMap_Index_at__string__bool(l2, l7);
        if (t4.tag == 0u) {
            continue;
        }
        l11 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_function_index_by_mangle;
        l12 = ((vader_struct_vader_bytecode_BcImport_t*) l4)->f_mangled_name;
        t4 = std_collections_MutableMap_Index_at__string__i32(l11, l12);
        if (t4.tag == 246u) {
            continue;
        }
        l13 = vader_bytecode_build_intrinsic_wrapper_body(l4, l10);
        vader_array_t* _a6_arr = vader_array_new(191u, 0u, 13u, 1370u);
        l14 = (void*) _a6_arr;
        l6 = ((vader_array_t*) l13)->length;
        vader_array_t* _a7_arr = vader_array_repeat((vader_array_t*) l14, (size_t) l6);
        l15 = (void*) _a7_arr;
        l16 = (size_t) 0;
        l17 = ((vader_array_t*) l13)->length;
        while ((l16 < l17)) {
            vader_array_push((vader_array_t*) l15, vader_box_obj(0u, NULL));
            t1 = (l16 + INT64_C(1));
            l16 = (size_t) (int64_t) t1;
        }
        vader_array_t* _a8_arr = vader_array_new(14u, 0u, 7u, 246u);
        l18 = (void*) _a8_arr;
        l19 = ((vader_array_t*) l13)->length;
        vader_array_t* _a9_arr = vader_array_repeat((vader_array_t*) l18, (size_t) l19);
        l20 = (void*) _a9_arr;
        l21 = (size_t) 0;
        l22 = ((vader_array_t*) l13)->length;
        vader_array_t* _pc143_hdr = (vader_array_t*) l20;
        size_t _pc143_len = _pc143_hdr->length;
        size_t _pc143_cap = (_pc143_hdr->offset == 0 && !vader_array_is_borrowed(_pc143_hdr) && _pc143_hdr->length >= _pc143_hdr->buf->length) ? _pc143_hdr->capacity : (size_t) 0;
        void* _pc143_slots = _pc143_hdr->buf->slots;
        for (;;) {
            if ((l21 < l22)) {
                l23 = -(INT32_C(1));
                if (VADER_LIKELY(_pc143_len < _pc143_cap)) {
                    ((int32_t*) _pc143_slots)[_pc143_len] = (int32_t) (l23);
                    _pc143_len += 1;
                } else {
                    _pc143_hdr->length = _pc143_len;
                    if (_pc143_hdr->buf->length < _pc143_len) {
                        _pc143_hdr->buf->length = _pc143_len;
                    }
                    vader_array_push_i32((vader_array_t*) l20, l23);
                    _pc143_hdr = (vader_array_t*) l20;
                    _pc143_len = _pc143_hdr->length;
                    _pc143_cap = (_pc143_hdr->offset == 0 && !vader_array_is_borrowed(_pc143_hdr) && _pc143_hdr->length >= _pc143_hdr->buf->length) ? _pc143_hdr->capacity : (size_t) 0;
                    _pc143_slots = _pc143_hdr->buf->slots;
                }
                t1 = (l21 + INT64_C(1));
                l21 = (size_t) (int64_t) t1;
                continue;
            }
            _pc143_hdr->length = _pc143_len;
            if (_pc143_hdr->buf->length < _pc143_len) {
                _pc143_hdr->buf->length = _pc143_len;
            }
            break;
        }
        vader_array_t* _a10_arr = vader_array_new(46u, 0u, 13u, 554u);
        l24 = (void*) _a10_arr;
        t2 = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_functions)->length;
        l25 = ((int32_t) (size_t) t2);
        l26 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_functions;
        t5 = ((vader_struct_vader_bytecode_BcImport_t*) l4)->f_mangled_name;
        l27 = concat_2(t5, 857u);
        l28 = ((vader_struct_vader_bytecode_BcImport_t*) l4)->f_signature;
        vader_array_t* _a11_arr = vader_array_new(14u, 0u, 7u, 246u);
        l29 = (void*) _a11_arr;
        vader_struct_vader_bytecode_BcFunction_t* _a12_obj = (vader_struct_vader_bytecode_BcFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcFunction_t));
        vader_obj_header_init(_a12_obj, 552u);
        _a12_obj->f_name = l27;
        _a12_obj->f_is_main = false;
        _a12_obj->f_signature = l28;
        _a12_obj->f_locals = l24;
        _a12_obj->f_body = l13;
        _a12_obj->f_debug = l15;
        _a12_obj->f_jump_table = l20;
        _a12_obj->f_source_pc = l29;
        l30 = (void*) _a12_obj;
        vader_array_push((vader_array_t*) l26, vader_ref_box(l30));
        l31 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_function_index_by_mangle;
        l32 = ((vader_struct_vader_bytecode_BcImport_t*) l4)->f_mangled_name;
        std_collections_MutableMap_IndexSet_set_at__string__i32(l31, l32, l25);
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_midir_term_return_single(void* l0) {
    size_t t0;
    int32_t t1;
    vader_box_t t2;
    t0 = ((vader_array_t*) ((vader_struct_vader_midir_TermReturn_t*) l0)->f_values)->length;
    if (!(t0 != INT64_C(1))) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_midir_TermReturn_t*) l0)->f_values);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
        t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) INT32_C(0)];
        t2 = vader_box_i32(246u, t1);
        return t2;
    }
    return vader_box_obj(0u, NULL);
}

static void vader_midir_terminate(void* l0, vader_box_t l1) {
    void* l2;
    size_t l3;
    vader_box_t l4;
    int64_t t0;
    if (((vader_struct_vader_midir_FnCtx_t*) l0)->f_current.tag == 0u) {
        return;
    }
    l2 = ((vader_struct_vader_midir_FnCtx_t*) l0)->f_blocks;
    t0 = ((int64_t) ((vader_struct_vader_midir_FnCtx_t*) l0)->f_current.payload.i);
    l3 = (size_t) (int64_t) t0;
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
    l4 = std_collections_MutableMap_Index_at__i32__Any(l1, l2);
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
    if (l4.tag == 979u) {
        t0 = l4.payload.obj;
        l6 = ((vader_struct_vader_midir_TermCondBranch_t*) t0)->f_then_block;
        t1 = std_collections_MutableSet_Contains_contains__i32(l3, l6);
        if (!(t1)) {
            l7 = true;
        } else {
            t0 = l4.payload.obj;
            l6 = ((vader_struct_vader_midir_TermCondBranch_t*) t0)->f_else_block;
            t1 = std_collections_MutableSet_Contains_contains__i32(l3, l6);
            l7 = !(t1);
        }
        return l7;
    }
    return false;
}

static bool vader_midir_try_fuse_local_field(void* l0, int32_t l1, int32_t l2) {
    size_t l3, l5;
    void* l4 = NULL;
    void* l8 = NULL;
    vader_box_t l6 = vader_box_null();
    int32_t l7;
    int64_t t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &l6 };
    void** gc_raw_roots[4] = { &l0, &l4, &l8, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_slot)->f_body)->length;
    if (l3 == INT64_C(0)) {
        { vader_gc_top = gc_frame.prev; return false; }
    }
    l4 = ((vader_struct_vader_bytecode_BcFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_slot)->f_body;
    t0 = (l3 - INT64_C(1));
    l5 = (size_t) (int64_t) t0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
    l6 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
    if (!(l6.tag == 663u)) {
        { vader_gc_top = gc_frame.prev; return false; }
    }
    t1 = l6.payload.obj;
    l7 = ((vader_struct_vader_bytecode_LocalGet_t*) t1)->f_slot;
    l4 = ((vader_struct_vader_bytecode_BcFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_slot)->f_body;
    t0 = (l3 - INT64_C(1));
    l3 = (size_t) (int64_t) t0;
    vader_struct_vader_bytecode_LocalField_t* _a1_obj = (vader_struct_vader_bytecode_LocalField_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_LocalField_t));
    vader_obj_header_init(_a1_obj, 662u);
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

static bool vader_midir_unary_leaves_width(uint8_t l0, uint8_t l1) {
    bool l2;
    bool t0;
    t0 = vader_bytecode_is_narrow_valtype(l1);
    if (t0) {
        if (l0 == INT32_C(0)) {
            l2 = true;
        } else if (l0 == INT32_C(2)) {
            l2 = vader_bytecode_is_unsigned_val(l1);
        } else {
            if (!(l0 == INT32_C(1))) {
                vader_unreachable("non-exhaustive match (T3013 should have caught this)");
            }
            l2 = false;
        }
        return l2;
    }
    return false;
}

static bool vader_midir_union_element(vader_box_t l0) {
    void* l1;
    vader_box_t l2;
    bool t0;
    l2 = vader_types_array_backing(l0);
    if (l2.tag == 0u) {
        return false;
    }
    l1 = l2.payload.obj;
    t0 = vader_midir_is_union_slot(((vader_struct_vader_types_ArrayType_t*) l1)->f_element);
    return t0;
}

static bool vader_midir_union_field(void* l0, int32_t l1, size_t l2) {
    void* l3;
    size_t l4;
    vader_box_t l5;
    int32_t l6;
    int64_t t0;
    void* t1;
    bool t2;
    l3 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_types;
    t0 = ((int64_t) (int32_t) l1);
    l4 = (size_t) (int64_t) t0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
    l5 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
    if (l5.tag == 561u) {
        t1 = l5.payload.obj;
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcStruct_t*) t1)->f_fields);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l2)
        t1 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l2);
        l6 = ((vader_struct_vader_bytecode_BcField_t*) t1)->f_type_index;
        t2 = vader_midir_is_union_row(l0, l6);
        return t2;
    }
    return false;
}

static void* vader_midir_union_fields_of(void* l0, int32_t l1) {
    void* l2 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l8 = NULL;
    size_t l3, l7;
    vader_box_t l4 = vader_box_null();
    bool l9;
    int64_t t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &l4 };
    void** gc_raw_roots[6] = { &l0, &l2, &l5, &l6, &l8, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 6u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_types;
    t0 = ((int64_t) (int32_t) l1);
    l3 = (size_t) (int64_t) t0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
    l4 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
    if (!(l4.tag == 561u)) {
        vader_array_t* _a1_arr = vader_array_new(11u, 0u, 12u, 241u);
        t1 = (void*) _a1_arr;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = l4.payload.obj;
    l2 = ((vader_struct_vader_bytecode_BcStruct_t*) t1)->f_fields;
    vader_struct___lambda_env_vader_midir_19_t* _a2_obj = (vader_struct___lambda_env_vader_midir_19_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_midir_19_t));
    vader_obj_header_init(_a2_obj, 274u);
    _a2_obj->f_cap_0 = l0;
    l5 = (void*) _a2_obj;
    vader_array_t* _a3_arr = vader_array_new(11u, 0u, 12u, 241u);
    l6 = (void*) _a3_arr;
    l3 = ((vader_array_t*) l2)->length;
    vader_array_t* _a4_arr = vader_array_repeat((vader_array_t*) l6, (size_t) l3);
    l6 = (void*) _a4_arr;
    l3 = ((vader_array_t*) l2)->length;
    l7 = (size_t) 0;
    vader_array_t* _pc36_hdr = (vader_array_t*) l6;
    size_t _pc36_len = _pc36_hdr->length;
    size_t _pc36_cap = (_pc36_hdr->offset == 0 && !vader_array_is_borrowed(_pc36_hdr) && _pc36_hdr->length >= _pc36_hdr->buf->length) ? _pc36_hdr->capacity : (size_t) 0;
    void* _pc36_slots = _pc36_hdr->buf->slots;
    for (;;) {
        if ((l7 < l3)) {
            vader_array_t* _a5_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l7)
            l8 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l7);
            l9 = __lambda_vader_midir_18(l5, l8);
            if (VADER_LIKELY(_pc36_len < _pc36_cap)) {
                ((uint8_t*) _pc36_slots)[_pc36_len] = (uint8_t) (l9);
                _pc36_len += 1;
            } else {
                _pc36_hdr->length = _pc36_len;
                if (_pc36_hdr->buf->length < _pc36_len) {
                    _pc36_hdr->buf->length = _pc36_len;
                }
                vader_array_push_bool((vader_array_t*) l6, l9);
                _pc36_hdr = (vader_array_t*) l6;
                _pc36_len = _pc36_hdr->length;
                _pc36_cap = (_pc36_hdr->offset == 0 && !vader_array_is_borrowed(_pc36_hdr) && _pc36_hdr->length >= _pc36_hdr->buf->length) ? _pc36_hdr->capacity : (size_t) 0;
                _pc36_slots = _pc36_hdr->buf->slots;
            }
            t0 = (l7 + INT64_C(1));
            l7 = (size_t) (int64_t) t0;
            continue;
        }
        _pc36_hdr->length = _pc36_len;
        if (_pc36_hdr->buf->length < _pc36_len) {
            _pc36_hdr->buf->length = _pc36_len;
        }
        break;
    }
    { void* __vret = l6; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_midir_union_params_of(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    size_t l5, l6;
    int32_t l7;
    bool l8;
    int64_t t0;
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_bytecode_BcSignature_t*) l1)->f_param_types;
    vader_struct___lambda_env_vader_midir_16_t* _a0_obj = (vader_struct___lambda_env_vader_midir_16_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_midir_16_t));
    vader_obj_header_init(_a0_obj, 273u);
    _a0_obj->f_cap_0 = l0;
    l3 = (void*) _a0_obj;
    vader_array_t* _a1_arr = vader_array_new(11u, 0u, 12u, 241u);
    l4 = (void*) _a1_arr;
    l5 = ((vader_array_t*) l2)->length;
    vader_array_t* _a2_arr = vader_array_repeat((vader_array_t*) l4, (size_t) l5);
    l4 = (void*) _a2_arr;
    l5 = ((vader_array_t*) l2)->length;
    l6 = (size_t) 0;
    vader_array_t* _pc19_hdr = (vader_array_t*) l4;
    size_t _pc19_len = _pc19_hdr->length;
    size_t _pc19_cap = (_pc19_hdr->offset == 0 && !vader_array_is_borrowed(_pc19_hdr) && _pc19_hdr->length >= _pc19_hdr->buf->length) ? _pc19_hdr->capacity : (size_t) 0;
    void* _pc19_slots = _pc19_hdr->buf->slots;
    for (;;) {
        if ((l6 < l5)) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l6)
            l7 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l6];
            l8 = __lambda_vader_midir_15(l3, l7);
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
            t0 = (l6 + INT64_C(1));
            l6 = (size_t) (int64_t) t0;
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

static void* vader_midir_union_slots_of(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    size_t l3, l4;
    bool l5;
    vader_box_t t0 = vader_box_null();
    int64_t t1;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = l0;
    vader_array_t* _a0_arr = vader_array_new(11u, 0u, 12u, 241u);
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
        t0 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
        l5 = __lambda_vader_midir_17(t0);
        vader_array_push_bool((vader_array_t*) l2, l5);
        t1 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t1;
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_midir_walk_rpo(void* l0, int32_t l1, void* l2, void* l3) {
    int32_t l4;
    void* l5 = NULL;
    size_t l6, l7;
    vader_box_t t0 = vader_box_null();
    bool t1;
    void* t2 = NULL;
    int64_t t3;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[5] = { &l0, &l2, &l3, &l5, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l4 = l1;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
    t0 = vader_box_bool(241u, ((uint8_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l4]);
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
    l7 = (size_t) 0;
    while ((l7 < l6)) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l7)
        l4 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l7];
        vader_midir_walk_rpo(l0, l4, l2, l3);
        t3 = (l7 + INT64_C(1));
        l7 = (size_t) (int64_t) t3;
    }
    vader_array_push_i32((vader_array_t*) l3, l1);
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_midir_with_dst(vader_box_t l0, int32_t l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l12 = NULL;
    vader_box_t l4 = vader_box_null(), l5 = vader_box_null();
    int32_t l6, l8, l11;
    uint8_t l7;
    vader_string_t l9 = 0;
    bool l10;
    void* t0 = NULL;
    vader_box_t* gc_roots[3] = { &l0, &l4, &l5 };
    void** gc_raw_roots[4] = { &l2, &l3, &l12, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l9 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l0.tag == 952u) {
        l2 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrConst_t*) l2)->f_span;
        l4 = ((vader_struct_vader_midir_InstrConst_t*) l2)->f_value;
        l5 = ((vader_struct_vader_midir_InstrConst_t*) l2)->f_type;
        vader_struct_vader_midir_InstrConst_t* _a0_obj = (vader_struct_vader_midir_InstrConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrConst_t));
        vader_obj_header_init(_a0_obj, 952u);
        _a0_obj->f_span = l3;
        _a0_obj->f_dst = l1;
        _a0_obj->f_value = l4;
        _a0_obj->f_type = l5;
        t0 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 962u) {
        l2 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrMove_t*) l2)->f_span;
        l6 = ((vader_struct_vader_midir_InstrMove_t*) l2)->f_src;
        vader_struct_vader_midir_InstrMove_t* _a1_obj = (vader_struct_vader_midir_InstrMove_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrMove_t));
        vader_obj_header_init(_a1_obj, 962u);
        _a1_obj->f_span = l3;
        _a1_obj->f_dst = l1;
        _a1_obj->f_src = l6;
        t0 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 945u) {
        l2 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrBinOp_t*) l2)->f_span;
        l7 = ((vader_struct_vader_midir_InstrBinOp_t*) l2)->f_op;
        l6 = ((vader_struct_vader_midir_InstrBinOp_t*) l2)->f_lhs;
        l8 = ((vader_struct_vader_midir_InstrBinOp_t*) l2)->f_rhs;
        l4 = ((vader_struct_vader_midir_InstrBinOp_t*) l2)->f_type;
        vader_struct_vader_midir_InstrBinOp_t* _a2_obj = (vader_struct_vader_midir_InstrBinOp_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrBinOp_t));
        vader_obj_header_init(_a2_obj, 945u);
        _a2_obj->f_span = l3;
        _a2_obj->f_dst = l1;
        _a2_obj->f_op = l7;
        _a2_obj->f_lhs = l6;
        _a2_obj->f_rhs = l8;
        _a2_obj->f_type = l4;
        t0 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 967u) {
        l2 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrUnOp_t*) l2)->f_span;
        l7 = ((vader_struct_vader_midir_InstrUnOp_t*) l2)->f_op;
        l6 = ((vader_struct_vader_midir_InstrUnOp_t*) l2)->f_operand;
        l4 = ((vader_struct_vader_midir_InstrUnOp_t*) l2)->f_type;
        vader_struct_vader_midir_InstrUnOp_t* _a3_obj = (vader_struct_vader_midir_InstrUnOp_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrUnOp_t));
        vader_obj_header_init(_a3_obj, 967u);
        _a3_obj->f_span = l3;
        _a3_obj->f_dst = l1;
        _a3_obj->f_op = l7;
        _a3_obj->f_operand = l6;
        _a3_obj->f_type = l4;
        t0 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 956u) {
        l2 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrFieldGet_t*) l2)->f_span;
        l6 = ((vader_struct_vader_midir_InstrFieldGet_t*) l2)->f_target;
        l9 = ((vader_struct_vader_midir_InstrFieldGet_t*) l2)->f_field;
        l4 = ((vader_struct_vader_midir_InstrFieldGet_t*) l2)->f_type;
        vader_struct_vader_midir_InstrFieldGet_t* _a4_obj = (vader_struct_vader_midir_InstrFieldGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrFieldGet_t));
        vader_obj_header_init(_a4_obj, 956u);
        _a4_obj->f_span = l3;
        _a4_obj->f_dst = l1;
        _a4_obj->f_target = l6;
        _a4_obj->f_field = l9;
        _a4_obj->f_type = l4;
        t0 = (void*) _a4_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 939u) {
        l2 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrArrayGet_t*) l2)->f_span;
        l6 = ((vader_struct_vader_midir_InstrArrayGet_t*) l2)->f_target;
        l8 = ((vader_struct_vader_midir_InstrArrayGet_t*) l2)->f_index;
        l4 = ((vader_struct_vader_midir_InstrArrayGet_t*) l2)->f_type;
        l10 = ((vader_struct_vader_midir_InstrArrayGet_t*) l2)->f_bounds_safe;
        vader_struct_vader_midir_InstrArrayGet_t* _a5_obj = (vader_struct_vader_midir_InstrArrayGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrArrayGet_t));
        vader_obj_header_init(_a5_obj, 939u);
        _a5_obj->f_span = l3;
        _a5_obj->f_dst = l1;
        _a5_obj->f_target = l6;
        _a5_obj->f_index = l8;
        _a5_obj->f_type = l4;
        _a5_obj->f_bounds_safe = l10;
        t0 = (void*) _a5_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 940u) {
        l2 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrArrayLen_t*) l2)->f_span;
        l6 = ((vader_struct_vader_midir_InstrArrayLen_t*) l2)->f_target;
        vader_struct_vader_midir_InstrArrayLen_t* _a6_obj = (vader_struct_vader_midir_InstrArrayLen_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrArrayLen_t));
        vader_obj_header_init(_a6_obj, 940u);
        _a6_obj->f_span = l3;
        _a6_obj->f_dst = l1;
        _a6_obj->f_target = l6;
        t0 = (void*) _a6_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 944u) {
        l2 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrArraySlice_t*) l2)->f_span;
        l4 = ((vader_struct_vader_midir_InstrArraySlice_t*) l2)->f_type;
        l6 = ((vader_struct_vader_midir_InstrArraySlice_t*) l2)->f_target;
        l8 = ((vader_struct_vader_midir_InstrArraySlice_t*) l2)->f_lo;
        l11 = ((vader_struct_vader_midir_InstrArraySlice_t*) l2)->f_hi;
        vader_struct_vader_midir_InstrArraySlice_t* _a7_obj = (vader_struct_vader_midir_InstrArraySlice_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrArraySlice_t));
        vader_obj_header_init(_a7_obj, 944u);
        _a7_obj->f_span = l3;
        _a7_obj->f_dst = l1;
        _a7_obj->f_type = l4;
        _a7_obj->f_target = l6;
        _a7_obj->f_lo = l8;
        _a7_obj->f_hi = l11;
        t0 = (void*) _a7_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 963u) {
        l2 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrStringSlice_t*) l2)->f_span;
        l4 = ((vader_struct_vader_midir_InstrStringSlice_t*) l2)->f_type;
        l6 = ((vader_struct_vader_midir_InstrStringSlice_t*) l2)->f_target;
        l8 = ((vader_struct_vader_midir_InstrStringSlice_t*) l2)->f_lo;
        l11 = ((vader_struct_vader_midir_InstrStringSlice_t*) l2)->f_hi;
        vader_struct_vader_midir_InstrStringSlice_t* _a8_obj = (vader_struct_vader_midir_InstrStringSlice_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrStringSlice_t));
        vader_obj_header_init(_a8_obj, 963u);
        _a8_obj->f_span = l3;
        _a8_obj->f_dst = l1;
        _a8_obj->f_type = l4;
        _a8_obj->f_target = l6;
        _a8_obj->f_lo = l8;
        _a8_obj->f_hi = l11;
        t0 = (void*) _a8_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 964u) {
        l2 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrStructNew_t*) l2)->f_span;
        l4 = ((vader_struct_vader_midir_InstrStructNew_t*) l2)->f_type;
        l12 = ((vader_struct_vader_midir_InstrStructNew_t*) l2)->f_fields;
        l10 = ((vader_struct_vader_midir_InstrStructNew_t*) l2)->f_stack;
        vader_struct_vader_midir_InstrStructNew_t* _a9_obj = (vader_struct_vader_midir_InstrStructNew_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrStructNew_t));
        vader_obj_header_init(_a9_obj, 964u);
        _a9_obj->f_span = l3;
        _a9_obj->f_dst = l1;
        _a9_obj->f_type = l4;
        _a9_obj->f_fields = l12;
        _a9_obj->f_stack = l10;
        t0 = (void*) _a9_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 941u) {
        l2 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrArrayNew_t*) l2)->f_span;
        l4 = ((vader_struct_vader_midir_InstrArrayNew_t*) l2)->f_type;
        l6 = ((vader_struct_vader_midir_InstrArrayNew_t*) l2)->f_length;
        l12 = ((vader_struct_vader_midir_InstrArrayNew_t*) l2)->f_elements;
        l10 = ((vader_struct_vader_midir_InstrArrayNew_t*) l2)->f_stack;
        vader_struct_vader_midir_InstrArrayNew_t* _a10_obj = (vader_struct_vader_midir_InstrArrayNew_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrArrayNew_t));
        vader_obj_header_init(_a10_obj, 941u);
        _a10_obj->f_span = l3;
        _a10_obj->f_dst = l1;
        _a10_obj->f_type = l4;
        _a10_obj->f_length = l6;
        _a10_obj->f_elements = l12;
        _a10_obj->f_stack = l10;
        t0 = (void*) _a10_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 953u) {
        l2 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrDataConst_t*) l2)->f_span;
        l4 = ((vader_struct_vader_midir_InstrDataConst_t*) l2)->f_type;
        l6 = ((vader_struct_vader_midir_InstrDataConst_t*) l2)->f_pool_index;
        vader_struct_vader_midir_InstrDataConst_t* _a11_obj = (vader_struct_vader_midir_InstrDataConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrDataConst_t));
        vader_obj_header_init(_a11_obj, 953u);
        _a11_obj->f_span = l3;
        _a11_obj->f_dst = l1;
        _a11_obj->f_type = l4;
        _a11_obj->f_pool_index = l6;
        t0 = (void*) _a11_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 965u) {
        l2 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrTypeCheck_t*) l2)->f_span;
        l6 = ((vader_struct_vader_midir_InstrTypeCheck_t*) l2)->f_value;
        l4 = ((vader_struct_vader_midir_InstrTypeCheck_t*) l2)->f_check_type;
        vader_struct_vader_midir_InstrTypeCheck_t* _a12_obj = (vader_struct_vader_midir_InstrTypeCheck_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrTypeCheck_t));
        vader_obj_header_init(_a12_obj, 965u);
        _a12_obj->f_span = l3;
        _a12_obj->f_dst = l1;
        _a12_obj->f_value = l6;
        _a12_obj->f_check_type = l4;
        t0 = (void*) _a12_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 966u) {
        l2 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrTypeConst_t*) l2)->f_span;
        l4 = ((vader_struct_vader_midir_InstrTypeConst_t*) l2)->f_type;
        l5 = ((vader_struct_vader_midir_InstrTypeConst_t*) l2)->f_value_type;
        vader_struct_vader_midir_InstrTypeConst_t* _a13_obj = (vader_struct_vader_midir_InstrTypeConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrTypeConst_t));
        vader_obj_header_init(_a13_obj, 966u);
        _a13_obj->f_span = l3;
        _a13_obj->f_dst = l1;
        _a13_obj->f_type = l4;
        _a13_obj->f_value_type = l5;
        t0 = (void*) _a13_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 948u) {
        l2 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrCast_t*) l2)->f_span;
        l6 = ((vader_struct_vader_midir_InstrCast_t*) l2)->f_value;
        l4 = ((vader_struct_vader_midir_InstrCast_t*) l2)->f_type;
        vader_struct_vader_midir_InstrCast_t* _a14_obj = (vader_struct_vader_midir_InstrCast_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrCast_t));
        vader_obj_header_init(_a14_obj, 948u);
        _a14_obj->f_span = l3;
        _a14_obj->f_dst = l1;
        _a14_obj->f_value = l6;
        _a14_obj->f_type = l4;
        t0 = (void*) _a14_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 950u) {
        l2 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrCellNew_t*) l2)->f_span;
        l6 = ((vader_struct_vader_midir_InstrCellNew_t*) l2)->f_value;
        l4 = ((vader_struct_vader_midir_InstrCellNew_t*) l2)->f_value_type;
        vader_struct_vader_midir_InstrCellNew_t* _a15_obj = (vader_struct_vader_midir_InstrCellNew_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrCellNew_t));
        vader_obj_header_init(_a15_obj, 950u);
        _a15_obj->f_span = l3;
        _a15_obj->f_dst = l1;
        _a15_obj->f_value = l6;
        _a15_obj->f_value_type = l4;
        t0 = (void*) _a15_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 949u) {
        l2 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrCellGet_t*) l2)->f_span;
        l6 = ((vader_struct_vader_midir_InstrCellGet_t*) l2)->f_cell;
        l4 = ((vader_struct_vader_midir_InstrCellGet_t*) l2)->f_value_type;
        vader_struct_vader_midir_InstrCellGet_t* _a16_obj = (vader_struct_vader_midir_InstrCellGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrCellGet_t));
        vader_obj_header_init(_a16_obj, 949u);
        _a16_obj->f_span = l3;
        _a16_obj->f_dst = l1;
        _a16_obj->f_cell = l6;
        _a16_obj->f_value_type = l4;
        t0 = (void*) _a16_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 961u) {
        l2 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrMakeClosure_t*) l2)->f_span;
        l12 = ((vader_struct_vader_midir_InstrMakeClosure_t*) l2)->f_fn_symbol;
        l6 = ((vader_struct_vader_midir_InstrMakeClosure_t*) l2)->f_env;
        l4 = ((vader_struct_vader_midir_InstrMakeClosure_t*) l2)->f_env_type;
        l5 = ((vader_struct_vader_midir_InstrMakeClosure_t*) l2)->f_type;
        vader_struct_vader_midir_InstrMakeClosure_t* _a17_obj = (vader_struct_vader_midir_InstrMakeClosure_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrMakeClosure_t));
        vader_obj_header_init(_a17_obj, 961u);
        _a17_obj->f_span = l3;
        _a17_obj->f_dst = l1;
        _a17_obj->f_fn_symbol = l12;
        _a17_obj->f_env = l6;
        _a17_obj->f_env_type = l4;
        _a17_obj->f_type = l5;
        t0 = (void*) _a17_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 959u) {
        l2 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrFnRef_t*) l2)->f_span;
        l12 = ((vader_struct_vader_midir_InstrFnRef_t*) l2)->f_fn_symbol;
        l4 = ((vader_struct_vader_midir_InstrFnRef_t*) l2)->f_type;
        vader_struct_vader_midir_InstrFnRef_t* _a18_obj = (vader_struct_vader_midir_InstrFnRef_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrFnRef_t));
        vader_obj_header_init(_a18_obj, 959u);
        _a18_obj->f_span = l3;
        _a18_obj->f_dst = l1;
        _a18_obj->f_fn_symbol = l12;
        _a18_obj->f_type = l4;
        t0 = (void*) _a18_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l0.tag == 958u)) {
        { vader_box_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = l0.payload.obj;
    l3 = ((vader_struct_vader_midir_InstrFnAddr_t*) l2)->f_span;
    l12 = ((vader_struct_vader_midir_InstrFnAddr_t*) l2)->f_fn_symbol;
    l4 = ((vader_struct_vader_midir_InstrFnAddr_t*) l2)->f_type;
    vader_struct_vader_midir_InstrFnAddr_t* _a19_obj = (vader_struct_vader_midir_InstrFnAddr_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrFnAddr_t));
    vader_obj_header_init(_a19_obj, 958u);
    _a19_obj->f_span = l3;
    _a19_obj->f_dst = l1;
    _a19_obj->f_fn_symbol = l12;
    _a19_obj->f_type = l4;
    t0 = (void*) _a19_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_midir_with_param_decorators(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null();
    void* l3 = NULL;
    void* l5 = NULL;
    void* l8 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    void* l15 = NULL;
    bool l4, l9, l10;
    size_t l6, l7, l11;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    bool t2;
    int64_t t3;
    vader_box_t* gc_roots[2] = { &l2, &t1 };
    void** gc_raw_roots[10] = { &l0, &l1, &l3, &l5, &l8, &l12, &l13, &l14, &l15, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 10u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_comptime_MonoEntry_t*) l1)->f_decl;
    if (!(l2.tag == 469u)) {
        { void* __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a0_arr = vader_array_new(11u, 0u, 12u, 241u);
    l3 = (void*) _a0_arr;
    l4 = false;
    l5 = std_iter_clone__bool(((vader_struct_vader_bytecode_BcSignature_t*) l0)->f_param_mutable);
    l6 = (size_t) 0;
    t0 = l2.payload.obj;
    l7 = ((vader_array_t*) ((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_params)->length;
    while ((l6 < l7)) {
        t0 = l2.payload.obj;
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_params);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l6)
        t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l6);
        l8 = ((vader_struct_toolchain_ast_FnParam_t*) t0)->f_decorators;
        l9 = toolchain_ast_decorators_have(l8, 1405u);
        vader_array_push_bool((vader_array_t*) l3, l9);
        if (l4) {
            l10 = true;
        } else {
            vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l6)
            t1 = vader_box_bool(241u, ((uint8_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l6]);
            l10 = t1.payload.b;
        }
        l4 = l10;
        l11 = ((vader_array_t*) l5)->length;
        if ((l6 < l11)) {
            t2 = toolchain_ast_decorators_have(l8, 1404u);
            if (t2) {
                vader_array_t* _a3_slotarr = ((vader_array_t*) l5);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l6)
                ((uint8_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l6] = (uint8_t) true;
            }
        }
        t3 = (l6 + INT64_C(1));
        l6 = (size_t) (int64_t) t3;
    }
    l8 = l0;
    l12 = ((vader_struct_vader_bytecode_BcSignature_t*) l8)->f_params;
    l13 = ((vader_struct_vader_bytecode_BcSignature_t*) l8)->f_results;
    l14 = ((vader_struct_vader_bytecode_BcSignature_t*) l8)->f_param_types;
    l15 = ((vader_struct_vader_bytecode_BcSignature_t*) l8)->f_result_types;
    l8 = ((vader_struct_vader_bytecode_BcSignature_t*) l8)->f_param_names;
    if (l4) {
        l2 = vader_ref_box(l3);
        vader_struct_vader_bytecode_BcSignature_t* _a4_obj = (vader_struct_vader_bytecode_BcSignature_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcSignature_t));
        vader_obj_header_init(_a4_obj, 559u);
        _a4_obj->f_params = l12;
        _a4_obj->f_results = l13;
        _a4_obj->f_param_types = l14;
        _a4_obj->f_result_types = l15;
        _a4_obj->f_param_names = l8;
        _a4_obj->f_param_mutable = l5;
        _a4_obj->f_param_by_address = l2.payload.obj;
        t0 = (void*) _a4_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_vader_bytecode_BcSignature_t*) l0)->f_param_by_address;
    l2 = vader_ref_box(t0);
    vader_struct_vader_bytecode_BcSignature_t* _a5_obj = (vader_struct_vader_bytecode_BcSignature_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcSignature_t));
    vader_obj_header_init(_a5_obj, 559u);
    _a5_obj->f_params = l12;
    _a5_obj->f_results = l13;
    _a5_obj->f_param_types = l14;
    _a5_obj->f_result_types = l15;
    _a5_obj->f_param_names = l8;
    _a5_obj->f_param_mutable = l5;
    _a5_obj->f_param_by_address = l2.payload.obj;
    t0 = (void*) _a5_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_midir_with_peephole_out(void* l0, void* l1) {
    void* l2 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    vader_string_t l3 = 0;
    bool l4;
    vader_box_t l5 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l5 };
    void** gc_raw_roots[8] = { &l0, &l1, &l2, &l6, &l7, &l8, &l9, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = l0;
    l3 = ((vader_struct_vader_bytecode_BcFunction_t*) l2)->f_name;
    l4 = ((vader_struct_vader_bytecode_BcFunction_t*) l2)->f_is_main;
    t0 = ((vader_struct_vader_bytecode_BcFunction_t*) l2)->f_signature;
    l5 = vader_ref_box(t0);
    l6 = ((vader_struct_vader_bytecode_BcFunction_t*) l2)->f_locals;
    l7 = ((vader_struct_vader_bytecode_BcPeepholeOut_t*) l1)->f_body;
    l8 = ((vader_struct_vader_bytecode_BcPeepholeOut_t*) l1)->f_debug;
    l9 = ((vader_struct_vader_bytecode_BcPeepholeOut_t*) l1)->f_jump_table;
    l2 = ((vader_struct_vader_bytecode_BcFunction_t*) l2)->f_source_pc;
    vader_struct_vader_bytecode_BcFunction_t* _a0_obj = (vader_struct_vader_bytecode_BcFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcFunction_t));
    vader_obj_header_init(_a0_obj, 552u);
    _a0_obj->f_name = l3;
    _a0_obj->f_is_main = l4;
    _a0_obj->f_signature = l5.payload.obj;
    _a0_obj->f_locals = l6;
    _a0_obj->f_body = l7;
    _a0_obj->f_debug = l8;
    _a0_obj->f_jump_table = l9;
    _a0_obj->f_source_pc = l2;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}
