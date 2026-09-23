#include "bootstrap.split.h"

static bool vader_midir_BlockId_Equals_equals(int32_t l0, int32_t l1);
static void* vader_midir_annotate_function(void* l0);
static void vader_midir_append_alias(void* l0, int32_t l1, int32_t l2);
static vader_string_t vader_midir_array_element_name(vader_box_t l0);
static uint8_t vader_midir_array_element_val_type(vader_box_t l0);
static uint64_t vader_midir_bc_value_bits(vader_box_t l0, vader_string_t l1);
static vader_box_t vader_midir_build_args(void* l0, void* l1);
static vader_box_t vader_midir_build_array_len(void* l0, void* l1);
static vader_box_t vader_midir_build_array_lit(void* l0, void* l1);
static vader_box_t vader_midir_build_array_push(void* l0, void* l1);
static vader_box_t vader_midir_build_array_slice(void* l0, void* l1);
static void vader_midir_build_assign(void* l0, void* l1);
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
static void vader_midir_build_loop(void* l0, void* l1);
static vader_box_t vader_midir_build_make_closure(void* l0, void* l1);
static vader_box_t vader_midir_build_short_circuit(void* l0, void* l1, vader_box_t l2);
static void vader_midir_build_stmt(void* l0, vader_box_t l1);
static vader_box_t vader_midir_build_string_slice(void* l0, void* l1);
static vader_box_t vader_midir_build_struct_lit(void* l0, void* l1);
static vader_box_t vader_midir_build_type_check(void* l0, void* l1);
static vader_box_t vader_midir_build_type_const(void* l0, void* l1);
static vader_box_t vader_midir_build_unary(void* l0, void* l1);
static vader_box_t vader_midir_build_unreachable_type(void* l0, vader_box_t l1, void* l2, vader_string_t l3, bool l4);
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
static void vader_midir_cf_else(void* l0, void* l1);
static void vader_midir_cf_end(void* l0, void* l1);
static void vader_midir_cf_if(void* l0, void* l1, int32_t l2);
static void vader_midir_cf_loop(void* l0, void* l1, int32_t l2);
static vader_box_t vader_midir_closure_header_type(vader_box_t l0);
static void* vader_midir_compact_locals(void* l0);
static void* vader_midir_compute_carried_across_loop_headers(void* l0, void* l1);
static void* vader_midir_compute_dominators(void* l0, void* l1);
static void* vader_midir_compute_escaping(void* l0, void* l1);
static void* vader_midir_compute_liveness(void* l0);
static void* vader_midir_compute_post_dominators(void* l0);
static int32_t vader_midir_cond_branch_merge(void* l0, int32_t l1, void* l2, int32_t l3);
static void* vader_midir_convert_data_pool(void* l0);
static bool vader_midir_convert_eligible(uint8_t l0);
static vader_box_t vader_midir_convert_function(void* l0, void* l1);
static void* vader_midir_count_uses(void* l0);
static vader_box_t vader_midir_debug_pos_of_span(void* l0);
static int32_t vader_midir_declare_local(void* l0, vader_string_t l1, vader_box_t l2, vader_box_t l3);
static void vader_midir_defer_or_resolve_branch(void* l0, int32_t l1, int32_t l2);
static bool vader_midir_dominates(void* l0, int32_t l1, int32_t l2);
static void vader_midir_drain_pending(void* l0, int32_t l1, bool l2, int32_t l3, int32_t l4);
static vader_box_t vader_midir_dst_of(vader_box_t l0);
static void vader_midir_emit(void* l0, vader_box_t l1);
static int32_t vader_midir_emit_block_contents(void* l0, int32_t l1, int32_t l2);
static void vader_midir_emit_call_results(void* l0, int64_t l1, void* l2, void* l3);
static void vader_midir_emit_cfg_function_body(void* l0, int32_t l1, void* l2, void* l3, bool l4);
static int32_t vader_midir_emit_cond(void* l0, int32_t l1, void* l2, int32_t l3);
static int32_t vader_midir_emit_const(void* l0, vader_box_t l1, vader_box_t l2, void* l3);
static void vader_midir_emit_const_instr(void* l0, void* l1, int64_t l2);
static void vader_midir_emit_first_get(void* l0, int64_t l1, int32_t l2, void* l3);
static void vader_midir_emit_get(void* l0, int32_t l1, void* l2);
static void vader_midir_emit_instr(void* l0, vader_box_t l1, int64_t l2);
static void vader_midir_emit_range(void* l0, int32_t l1, int32_t l2);
static void vader_midir_emit_result(void* l0, int64_t l1, int32_t l2, void* l3);
static void vader_midir_emit_result_if_any(void* l0, int64_t l1, vader_box_t l2, void* l3);
static void vader_midir_emit_return_boxing(void* l0, int32_t l1, size_t l2, void* l3);
static void vader_midir_emit_set(void* l0, int32_t l1, void* l2);
static vader_string_t vader_midir_extern_library_name(void* l0);
static vader_string_t vader_midir_extern_symbol_name(void* l0);
static void* vader_midir_find_loop_exits(void* l0, void* l1, void* l2);
static vader_box_t vader_midir_find_struct_field_index(void* l0, int32_t l1, vader_string_t l2);
static vader_box_t vader_midir_first_stack_operand(vader_box_t l0);
static vader_box_t vader_midir_first_terminator_operand(vader_box_t l0);
static void* vader_midir_fn_metadata(void* l0);
static void* vader_midir_fold_moves(void* l0);
static void* vader_midir_fold_moves_in_block(void* l0, void* l1, void* l2);
static void vader_midir_for_each_read_in_terminator(vader_box_t l0, void* l1);
static void vader_midir_for_each_read_local(vader_box_t l0, void* l1);
static void* vader_midir_freeze_block(void* l0);
static int32_t vader_midir_fresh_tmp(void* l0, vader_string_t l1, vader_box_t l2);
static bool vader_midir_instruction_has_side_effect(vader_box_t l0);
static void vader_midir_intern_data_value_strings(vader_box_t l0, void* l1);
static int32_t vader_midir_intern_string_pool(void* l0, vader_string_t l1);
static int32_t vader_midir_intersect_dom_tree(int32_t l0, int32_t l1, void* l2);
static vader_box_t vader_midir_intrinsic_op_for_name(vader_string_t l0);
static bool vader_midir_is_dest_passing_shape(vader_box_t l0);
static bool vader_midir_is_mutable_slot(vader_box_t l0);
static bool vader_midir_is_short_circuit_op(uint8_t l0);
static bool vader_midir_last_op_exits(void* l0);
static bool vader_midir_loop_exit_present(void* l0, int32_t l1);
static bool vader_midir_loop_scope_targets(void* l0, int32_t l1);
static vader_box_t vader_midir_lowered_to_bc_value(vader_box_t l0);
static void* vader_midir_make_extern_decl(void* l0);
static void* vader_midir_make_struct_decl(void* l0);
static vader_box_t vader_midir_multi_dsts(vader_box_t l0);
static void* vader_midir_natural_loop_bodies(void* l0, void* l1, void* l2);
static bool vader_midir_needs_ref_cast(vader_box_t l0);
static int32_t vader_midir_new_block(void* l0, void* l1);
static void* vader_midir_new_project_ctx(void* l0, void* l1);
static void* vader_midir_no_hints(void);
static void* vader_midir_optimise_function(void* l0);
static int64_t vader_midir_pos_key(int32_t l0, size_t l1);
static void* vader_midir_predecessors_of(void* l0);
static void vader_midir_push_emit(void* l0, vader_box_t l1, void* l2);
static int32_t vader_midir_push_op_with_span(void* l0, vader_box_t l1, void* l2);
static bool vader_midir_read_may_carry_ref(vader_box_t l0);
static void vader_midir_record_alias(void* l0, void* l1, int32_t l2, int32_t l3);
static vader_box_t vader_midir_remap_instr(vader_box_t l0, void* l1);
static int32_t vader_midir_remap_local(void* l0, int32_t l1);
static vader_box_t vader_midir_remap_local_opt(void* l0, vader_box_t l1);
static void* vader_midir_remap_locals(void* l0, void* l1);
static vader_box_t vader_midir_remap_terminator(vader_box_t l0, void* l1);
static void vader_midir_reserve_cfg_extern(void* l0, void* l1);
static void vader_midir_reserve_cfg_function(void* l0, void* l1);
static void vader_midir_reserve_cfg_struct(void* l0, void* l1);
static vader_box_t vader_midir_resolve_loop_frame(void* l0, vader_box_t l1);
static int32_t vader_midir_resolve_vtable_fn_index(void* l0, void* l1);
static void* vader_midir_reverse_postorder(void* l0);
static void* vader_midir_schedule_stack(void* l0);
static bool vader_midir_scope_contains_target(void* l0, int32_t l1);
static bool vader_midir_sets_equal(void* l0, void* l1);
static int32_t vader_midir_struct_symbol_id(vader_box_t l0);
static void* vader_midir_successors_of(void* l0);
static void vader_midir_synthesise_cfg_intrinsic_wrappers(void* l0, void* l1);
static vader_box_t vader_midir_term_return_single(void* l0);
static void vader_midir_terminate(void* l0, vader_box_t l1);
static bool vader_midir_try_fuse_local_field(void* l0, int32_t l1, int32_t l2);
static void vader_midir_walk_rpo(void* l0, int32_t l1, void* l2, void* l3);
static void vader_midir_walk_rpo_reverse(void* l0, int32_t l1, void* l2, void* l3);
static void* vader_midir_with_by_address(void* l0, void* l1);
static vader_box_t vader_midir_with_dst(vader_box_t l0, int32_t l1);
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
    void* l12 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    void* l17 = NULL;
    void* l18 = NULL;
    void* l21 = NULL;
    void* l25 = NULL;
    void* l27 = NULL;
    void* l28 = NULL;
    void* l30 = NULL;
    void* l34 = NULL;
    void* l35 = NULL;
    void* l36 = NULL;
    size_t l9, l10, l15, l16, l19, l20, l22, l23;
    vader_string_t l11 = 0;
    vader_string_t l26 = 0;
    vader_string_t l29 = 0;
    vader_string_t l31 = 0;
    vader_string_t l32 = 0;
    vader_string_t l33 = 0;
    vader_box_t l24 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    int64_t t2;
    bool t3;
    vader_box_t* gc_roots[2] = { &l24, &t0 };
    void** gc_raw_roots[20] = { &l0, &l4, &l5, &l6, &l7, &l8, &l12, &l13, &l14, &l17, &l18, &l21, &l25, &l27, &l28, &l30, &l34, &l35, &l36, &t1 };
    vader_string_t* gc_atom_roots[6] = { &l11, &l26, &l29, &l31, &l32, &l33 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 20u, gc_roots, gc_raw_roots, 0u, NULL, 6u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l1 = INT32_C(0);
    l2 = INT32_C(0);
    l3 = vader_lower_opt_report_enabled();
    vader_array_t* _a0_arr = vader_array_new(82u, 0u, 13u, 818u);
    l4 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(8u, 0u, 0u, 176u);
    l5 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(16u, 0u, 0u, 187u);
    l6 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(9u, 0u, 7u, 179u);
    l7 = (void*) _a3_arr;
    vader_struct_std_collections_MutableMap__string__Any_t* _a4_obj = (vader_struct_std_collections_MutableMap__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__Any_t));
    vader_obj_header_init(_a4_obj, 326u);
    _a4_obj->f_ekeys = l5;
    _a4_obj->f_evals = l6;
    _a4_obj->f_index = l7;
    _a4_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a4_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a4_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l5 = (void*) _a4_obj;
    l6 = ((vader_struct_vader_midir_CFGProject_t*) l0)->f_modules;
    l7 = ((vader_struct_std_collections_MutableMap__string__CFGModule_t*) l6)->f_ekeys;
    l8 = ((vader_struct_std_collections_MutableMap__string__CFGModule_t*) l6)->f_evals;
    l9 = ((vader_struct_std_collections_MutableMap__string__CFGModule_t*) l6)->f_size;
    l10 = (size_t) (int64_t) INT64_C(0);
    {
        loop_34: {
            if ((l10 >= l9)) {
            } else {
                vader_array_t* _a5_slotarr = ((vader_array_t*) l7);
                if (_a5_slotarr->buf != NULL && _a5_slotarr->buf->header.forward != NULL) { _a5_slotarr->buf = vader_array_buf_forward(_a5_slotarr->buf); }
                if ((size_t) l10 >= _a5_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_box_slots(_a5_slotarr->buf)[_a5_slotarr->offset + (size_t) l10];
                l11 = t0.payload.s;
                vader_array_t* _a6_slotarr = ((vader_array_t*) l8);
                if (_a6_slotarr->buf != NULL && _a6_slotarr->buf->header.forward != NULL) { _a6_slotarr->buf = vader_array_buf_forward(_a6_slotarr->buf); }
                if ((size_t) l10 >= _a6_slotarr->length) { vader_trap("array index out of bounds"); }
                l6 = vader_array_ref_load_obj(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l10);
                vader_struct___Tuple_2_62f1db0066dc3143_t* _a7_obj = (vader_struct___Tuple_2_62f1db0066dc3143_t*) vader_gc_alloc(sizeof(vader_struct___Tuple_2_62f1db0066dc3143_t));
                vader_obj_header_init(_a7_obj, 216u);
                _a7_obj->f__0 = l11;
                _a7_obj->f__1 = l6;
                t1 = (void*) _a7_obj;
                l12 = ((vader_struct___Tuple_2_62f1db0066dc3143_t*) t1)->f__1;
                t2 = (l10 + INT64_C(1));
                l10 = (size_t) (int64_t) t2;
                vader_array_t* _a8_arr = vader_array_new(76u, 0u, 13u, 804u);
                l13 = (void*) _a8_arr;
                l14 = ((vader_struct_vader_midir_CFGModule_t*) l12)->f_functions;
                l15 = ((vader_array_t*) l14)->length;
                l16 = (size_t) (int64_t) INT64_C(0);
                {
                    loop_67: {
                        if ((l16 < l15)) {
                            vader_array_t* _a9_slotarr = ((vader_array_t*) l14);
                            if (_a9_slotarr->buf != NULL && _a9_slotarr->buf->header.forward != NULL) { _a9_slotarr->buf = vader_array_buf_forward(_a9_slotarr->buf); }
                            if ((size_t) l16 >= _a9_slotarr->length) { vader_trap("array index out of bounds"); }
                            t1 = vader_array_ref_load_obj(_a9_slotarr->buf, _a9_slotarr->offset + (size_t) l16);
                            l17 = vader_midir_annotate_function(t1);
                            l18 = ((vader_struct_vader_midir_CFGFunction_t*) l17)->f_blocks;
                            l19 = ((vader_array_t*) l18)->length;
                            l20 = (size_t) (int64_t) INT64_C(0);
                            {
                                loop_84: {
                                    if ((l20 < l19)) {
                                        vader_array_t* _a10_slotarr = ((vader_array_t*) l18);
                                        if (_a10_slotarr->buf != NULL && _a10_slotarr->buf->header.forward != NULL) { _a10_slotarr->buf = vader_array_buf_forward(_a10_slotarr->buf); }
                                        if ((size_t) l20 >= _a10_slotarr->length) { vader_trap("array index out of bounds"); }
                                        t1 = vader_array_ref_load_obj(_a10_slotarr->buf, _a10_slotarr->offset + (size_t) l20);
                                        l21 = ((vader_struct_vader_midir_BasicBlock_t*) t1)->f_instructions;
                                        l22 = ((vader_array_t*) l21)->length;
                                        l23 = (size_t) (int64_t) INT64_C(0);
                                        {
                                            loop_99: {
                                                if ((l23 < l22)) {
                                                    vader_array_t* _a11_slotarr = ((vader_array_t*) l21);
                                                    if (_a11_slotarr->buf != NULL && _a11_slotarr->buf->header.forward != NULL) { _a11_slotarr->buf = vader_array_buf_forward(_a11_slotarr->buf); }
                                                    if ((size_t) l23 >= _a11_slotarr->length) { vader_trap("array index out of bounds"); }
                                                    l24 = vader_array_ref_load_box(_a11_slotarr->buf, _a11_slotarr->offset + (size_t) l23);
                                                    if (l24.tag == 848u) {
                                                        l1 = (l1 + INT32_C(1));
                                                        t1 = l24.payload.obj;
                                                        t3 = ((vader_struct_vader_midir_InstrStructNew_t*) t1)->f_stack;
                                                        if (t3) {
                                                            l2 = (l2 + INT32_C(1));
                                                        } else {
                                                            if (l3) {
                                                                t1 = l24.payload.obj;
                                                                l25 = ((vader_struct_vader_midir_InstrStructNew_t*) t1)->f_span;
                                                                t1 = l24.payload.obj;
                                                                l26 = vader_types_display_type(((vader_struct_vader_midir_InstrStructNew_t*) t1)->f_type);
                                                                vader_struct_vader_midir_EscapeSite_t* _a12_obj = (vader_struct_vader_midir_EscapeSite_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_EscapeSite_t));
                                                                vader_obj_header_init(_a12_obj, 818u);
                                                                _a12_obj->f_span = l25;
                                                                _a12_obj->f_kind = 2194u;
                                                                _a12_obj->f_type_name = l26;
                                                                l27 = (void*) _a12_obj;
                                                                vader_array_push((vader_array_t*) l4, vader_ref_box(l27));
                                                            }
                                                        }
                                                    } else {
                                                        if (l24.tag == 825u) {
                                                            l1 = (l1 + INT32_C(1));
                                                            t1 = l24.payload.obj;
                                                            t3 = ((vader_struct_vader_midir_InstrArrayNew_t*) t1)->f_stack;
                                                            if (t3) {
                                                                l2 = (l2 + INT32_C(1));
                                                            } else {
                                                                if (l3) {
                                                                    t1 = l24.payload.obj;
                                                                    l28 = ((vader_struct_vader_midir_InstrArrayNew_t*) t1)->f_span;
                                                                    t1 = l24.payload.obj;
                                                                    l29 = vader_types_display_type(((vader_struct_vader_midir_InstrArrayNew_t*) t1)->f_type);
                                                                    vader_struct_vader_midir_EscapeSite_t* _a13_obj = (vader_struct_vader_midir_EscapeSite_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_EscapeSite_t));
                                                                    vader_obj_header_init(_a13_obj, 818u);
                                                                    _a13_obj->f_span = l28;
                                                                    _a13_obj->f_kind = 1257u;
                                                                    _a13_obj->f_type_name = l29;
                                                                    l30 = (void*) _a13_obj;
                                                                    vader_array_push((vader_array_t*) l4, vader_ref_box(l30));
                                                                }
                                                            }
                                                        } else {
                                                        }
                                                    }
                                                    t2 = (l23 + INT64_C(1));
                                                    l23 = (size_t) (int64_t) t2;
                                                    goto loop_99;
                                                }
                                            }
                                        }
                                        t2 = (l20 + INT64_C(1));
                                        l20 = (size_t) (int64_t) t2;
                                        goto loop_84;
                                    }
                                }
                            }
                            vader_array_push((vader_array_t*) l13, vader_ref_box(l17));
                            t2 = (l16 + INT64_C(1));
                            l16 = (size_t) (int64_t) t2;
                            goto loop_67;
                        }
                    }
                }
                l31 = ((vader_struct_vader_midir_CFGModule_t*) l12)->f_module_id;
                l32 = ((vader_struct_vader_midir_CFGModule_t*) l12)->f_module_id;
                l33 = ((vader_struct_vader_midir_CFGModule_t*) l12)->f_display_path;
                l34 = ((vader_struct_vader_midir_CFGModule_t*) l12)->f_externs;
                l35 = ((vader_struct_vader_midir_CFGModule_t*) l12)->f_struct_decls;
                vader_struct_vader_midir_CFGModule_t* _a14_obj = (vader_struct_vader_midir_CFGModule_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_CFGModule_t));
                vader_obj_header_init(_a14_obj, 806u);
                _a14_obj->f_module_id = l32;
                _a14_obj->f_display_path = l33;
                _a14_obj->f_functions = l13;
                _a14_obj->f_externs = l34;
                _a14_obj->f_struct_decls = l35;
                l36 = (void*) _a14_obj;
                std_collections_MutableMap_IndexSet_set_at__string__Any(l5, l31, vader_ref_box(l36));
                goto loop_34;
            }
        }
    }
    l6 = l0;
    l7 = ((vader_struct_vader_midir_CFGProject_t*) l6)->f_vtable_entries;
    l8 = ((vader_struct_vader_midir_CFGProject_t*) l6)->f_strings;
    l12 = ((vader_struct_vader_midir_CFGProject_t*) l6)->f_data_pool;
    l6 = ((vader_struct_vader_midir_CFGProject_t*) l6)->f_trait_membership;
    vader_struct_vader_midir_CFGProject_t* _a15_obj = (vader_struct_vader_midir_CFGProject_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_CFGProject_t));
    vader_obj_header_init(_a15_obj, 808u);
    _a15_obj->f_modules = l5;
    _a15_obj->f_vtable_entries = l7;
    _a15_obj->f_strings = l8;
    _a15_obj->f_data_pool = l12;
    _a15_obj->f_trait_membership = l6;
    l5 = (void*) _a15_obj;
    vader_struct_vader_midir_EscapeStats_t* _a16_obj = (vader_struct_vader_midir_EscapeStats_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_EscapeStats_t));
    vader_obj_header_init(_a16_obj, 819u);
    _a16_obj->f_total_allocs = l1;
    _a16_obj->f_stack_promoted = l2;
    _a16_obj->f_heap_sites = l4;
    l4 = (void*) _a16_obj;
    vader_struct_vader_midir_AnnotatedProject_t* _a17_obj = (vader_struct_vader_midir_AnnotatedProject_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_AnnotatedProject_t));
    vader_obj_header_init(_a17_obj, 801u);
    _a17_obj->f_project = l5;
    _a17_obj->f_stats = l4;
    t1 = (void*) _a17_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
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
    void* l30 = NULL;
    void* l31 = NULL;
    void* l33 = NULL;
    void* l35 = NULL;
    void* l39 = NULL;
    void* l40 = NULL;
    void* l44 = NULL;
    void* l45 = NULL;
    void* l49 = NULL;
    void* l50 = NULL;
    void* l54 = NULL;
    void* l58 = NULL;
    void* l59 = NULL;
    size_t l4, l5, l7, l8, l18, l19;
    vader_box_t l9 = vader_box_null(), l16 = vader_box_null(), l42 = vader_box_null(), l55 = vader_box_null(), l57 = vader_box_null();
    int32_t l10, l11, l12, l29, l32, l36, l37, l41, l43, l46, l51, l53, l56;
    bool l17, l20, l24, l26, l34, l38, l47, l48;
    vader_string_t l52 = 0;
    vader_string_t l60 = 0;
    void* t0 = NULL;
    int64_t t1;
    bool t2;
    size_t t3;
    vader_box_t* gc_roots[5] = { &l9, &l16, &l42, &l55, &l57 };
    void** gc_raw_roots[28] = { &l0, &l1, &l2, &l3, &l6, &l13, &l14, &l15, &l21, &l22, &l23, &l25, &l27, &l28, &l30, &l31, &l33, &l35, &l39, &l40, &l44, &l45, &l49, &l50, &l54, &l58, &l59, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l52, &l60 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 5u, 28u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(9u, 0u, 7u, 179u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(6u, 0u, 12u, 174u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 179u);
    l3 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__i32__bool_t* _a3_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
    vader_obj_header_init(_a3_obj, 316u);
    _a3_obj->f_ekeys = l1;
    _a3_obj->f_evals = l2;
    _a3_obj->f_index = l3;
    _a3_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    t0 = (void*) _a3_obj;
    vader_struct_std_collections_MutableSet__i32_t* _a4_obj = (vader_struct_std_collections_MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i32_t));
    vader_obj_header_init(_a4_obj, 384u);
    _a4_obj->f_inner = t0;
    l1 = (void*) _a4_obj;
    vader_array_t* _a5_arr = vader_array_new(9u, 0u, 7u, 179u);
    l2 = (void*) _a5_arr;
    l3 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_blocks;
    l4 = ((vader_array_t*) l3)->length;
    l5 = (size_t) (int64_t) INT64_C(0);
    {
        loop_24: {
            if ((l5 < l4)) {
                vader_array_t* _a6_slotarr = ((vader_array_t*) l3);
                if (_a6_slotarr->buf != NULL && _a6_slotarr->buf->header.forward != NULL) { _a6_slotarr->buf = vader_array_buf_forward(_a6_slotarr->buf); }
                if ((size_t) l5 >= _a6_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_ref_load_obj(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l5);
                l6 = ((vader_struct_vader_midir_BasicBlock_t*) t0)->f_instructions;
                l7 = ((vader_array_t*) l6)->length;
                l8 = (size_t) (int64_t) INT64_C(0);
                {
                    loop_39: {
                        if ((l8 < l7)) {
                            vader_array_t* _a7_slotarr = ((vader_array_t*) l6);
                            if (_a7_slotarr->buf != NULL && _a7_slotarr->buf->header.forward != NULL) { _a7_slotarr->buf = vader_array_buf_forward(_a7_slotarr->buf); }
                            if ((size_t) l8 >= _a7_slotarr->length) { vader_trap("array index out of bounds"); }
                            l9 = vader_array_ref_load_box(_a7_slotarr->buf, _a7_slotarr->offset + (size_t) l8);
                            if (l9.tag == 848u) {
                                t0 = l9.payload.obj;
                                l10 = ((vader_struct_vader_midir_InstrStructNew_t*) t0)->f_dst;
                                std_collections_add__i32(l1, l10);
                                t0 = l9.payload.obj;
                                l11 = ((vader_struct_vader_midir_InstrStructNew_t*) t0)->f_dst;
                                vader_array_push_i32((vader_array_t*) l2, l11);
                            } else {
                                if (l9.tag == 825u) {
                                    t0 = l9.payload.obj;
                                    l12 = ((vader_struct_vader_midir_InstrArrayNew_t*) t0)->f_dst;
                                    std_collections_add__i32(l1, l12);
                                } else {
                                }
                            }
                            t1 = (l8 + INT64_C(1));
                            l8 = (size_t) (int64_t) t1;
                            goto loop_39;
                        }
                    }
                }
                t1 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t1;
                goto loop_24;
            }
        }
    }
    t2 = std_collections_is_empty__i32(l1);
    if (t2) {
        { void* __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = vader_midir_compute_escaping(l0, l1);
    l6 = ((vader_struct_vader_midir_EscapeResult_t*) l3)->f_alias_of;
    l6 = vader_midir_compute_carried_across_loop_headers(l0, l6);
    vader_array_t* _a8_arr = vader_array_new(9u, 0u, 7u, 179u);
    l13 = (void*) _a8_arr;
    vader_array_t* _a9_arr = vader_array_new(6u, 0u, 12u, 174u);
    l14 = (void*) _a9_arr;
    vader_array_t* _a10_arr = vader_array_new(9u, 0u, 7u, 179u);
    l15 = (void*) _a10_arr;
    vader_struct_std_collections_MutableMap__i32__bool_t* _a11_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
    vader_obj_header_init(_a11_obj, 316u);
    _a11_obj->f_ekeys = l13;
    _a11_obj->f_evals = l14;
    _a11_obj->f_index = l15;
    _a11_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a11_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a11_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    t0 = (void*) _a11_obj;
    vader_struct_std_collections_MutableSet__i32_t* _a12_obj = (vader_struct_std_collections_MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i32_t));
    vader_obj_header_init(_a12_obj, 384u);
    _a12_obj->f_inner = t0;
    l13 = (void*) _a12_obj;
    vader_array_t* _a13_arr = vader_array_new(9u, 0u, 7u, 179u);
    l14 = (void*) _a13_arr;
    l4 = ((vader_array_t*) l2)->length;
    l5 = (size_t) (int64_t) INT64_C(0);
    {
        loop_135: {
            if ((l5 < l4)) {
                vader_array_t* _a14_slotarr = ((vader_array_t*) l2);
                if (_a14_slotarr->buf != NULL && _a14_slotarr->buf->header.forward != NULL) { _a14_slotarr->buf = vader_array_buf_forward(_a14_slotarr->buf); }
                if ((size_t) l5 >= _a14_slotarr->length) { vader_trap("array index out of bounds"); }
                l10 = ((int32_t*) _a14_slotarr->buf->slots)[_a14_slotarr->offset + (size_t) l5];
                t2 = std_collections_MutableSet_Contains_contains__i32(((vader_struct_vader_midir_EscapeResult_t*) l3)->f_escaping, l10);
                if (t2) {
                    t1 = (l5 + INT64_C(1));
                    l5 = (size_t) (int64_t) t1;
                    goto loop_135;
                }
                t2 = std_collections_MutableSet_Contains_contains__i32(l6, l10);
                if (t2) {
                    t1 = (l5 + INT64_C(1));
                    l5 = (size_t) (int64_t) t1;
                    goto loop_135;
                }
                std_collections_add__i32(l13, l10);
                vader_array_push_i32((vader_array_t*) l14, l10);
                t1 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t1;
                goto loop_135;
            }
        }
    }
    {
        loop_180: {
            t3 = ((vader_array_t*) l14)->length;
            if ((t3 > INT64_C(0))) {
                t3 = ((vader_array_t*) l14)->length;
                t1 = (t3 - INT64_C(1));
                l4 = (size_t) (int64_t) t1;
                vader_array_t* _a15_slotarr = ((vader_array_t*) l14);
                if (_a15_slotarr->buf != NULL && _a15_slotarr->buf->header.forward != NULL) { _a15_slotarr->buf = vader_array_buf_forward(_a15_slotarr->buf); }
                if ((size_t) l4 >= _a15_slotarr->length) { vader_trap("array index out of bounds"); }
                l10 = ((int32_t*) _a15_slotarr->buf->slots)[_a15_slotarr->offset + (size_t) l4];
                t3 = ((vader_array_t*) l14)->length;
                t1 = (t3 - INT64_C(1));
                l5 = (size_t) (int64_t) t1;
                vader_array_t* _a16_arr = vader_array_slice((vader_array_t*) l14, (size_t) INT64_C(0), (size_t) l5);
                l14 = (void*) _a16_arr;
                l9 = std_collections_MutableMap_Index_at__i32__Any(((vader_struct_vader_midir_EscapeResult_t*) l3)->f_alias_from, l10);
                if (!(l9.tag == 0u)) {
                    l2 = l9.payload.obj;
                    l7 = ((vader_array_t*) l2)->length;
                    l8 = (size_t) (int64_t) INT64_C(0);
                    {
                        loop_220: {
                            if ((l8 < l7)) {
                                vader_array_t* _a17_slotarr = ((vader_array_t*) l2);
                                if (_a17_slotarr->buf != NULL && _a17_slotarr->buf->header.forward != NULL) { _a17_slotarr->buf = vader_array_buf_forward(_a17_slotarr->buf); }
                                if ((size_t) l8 >= _a17_slotarr->length) { vader_trap("array index out of bounds"); }
                                l11 = ((int32_t*) _a17_slotarr->buf->slots)[_a17_slotarr->offset + (size_t) l8];
                                t2 = std_collections_MutableSet_Contains_contains__i32(l13, l11);
                                if (t2) {
                                    t1 = (l8 + INT64_C(1));
                                    l8 = (size_t) (int64_t) t1;
                                    goto loop_220;
                                }
                                l16 = std_collections_MutableMap_Index_at__i32__Any(((vader_struct_vader_midir_EscapeResult_t*) l3)->f_alias_of, l11);
                                if (!(l16.tag == 0u)) {
                                    l17 = true;
                                    l15 = l16.payload.obj;
                                    vader_array_t* _a18_slotarr = ((vader_array_t*) l15);
                                    if (_a18_slotarr->buf != NULL && _a18_slotarr->buf->header.forward != NULL) { _a18_slotarr->buf = vader_array_buf_forward(_a18_slotarr->buf); }
                                    l18 = ((vader_array_t*) l15)->length;
                                    l19 = (size_t) (int64_t) INT64_C(0);
                                    {
                                        loop_256: {
                                            if ((l19 < l18)) {
                                                l12 = ((int32_t*) _a18_slotarr->buf->slots)[_a18_slotarr->offset + (size_t) l19];
                                                t2 = std_collections_MutableSet_Contains_contains__i32(l13, l12);
                                                if (!(t2)) {
                                                    l17 = false;
                                                } else {
                                                    t1 = (l19 + INT64_C(1));
                                                    l19 = (size_t) (int64_t) t1;
                                                    goto loop_256;
                                                }
                                            }
                                        }
                                    }
                                    if (l17) {
                                        std_collections_add__i32(l13, l11);
                                        vader_array_push_i32((vader_array_t*) l14, l11);
                                    }
                                }
                                t1 = (l8 + INT64_C(1));
                                l8 = (size_t) (int64_t) t1;
                                goto loop_220;
                            }
                        }
                    }
                }
                goto loop_180;
            }
        }
    }
    l17 = false;
    vader_array_t* _a19_arr = vader_array_new(74u, 0u, 13u, 802u);
    l2 = (void*) _a19_arr;
    l14 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_blocks;
    l4 = ((vader_array_t*) l14)->length;
    l5 = (size_t) (int64_t) INT64_C(0);
    {
        loop_317: {
            if ((l5 < l4)) {
                vader_array_t* _a20_slotarr = ((vader_array_t*) l14);
                if (_a20_slotarr->buf != NULL && _a20_slotarr->buf->header.forward != NULL) { _a20_slotarr->buf = vader_array_buf_forward(_a20_slotarr->buf); }
                if ((size_t) l5 >= _a20_slotarr->length) { vader_trap("array index out of bounds"); }
                l15 = vader_array_ref_load_obj(_a20_slotarr->buf, _a20_slotarr->offset + (size_t) l5);
                l20 = false;
                vader_array_t* _a21_arr = vader_array_new(141u, 0u, 13u, 1220u);
                l21 = (void*) _a21_arr;
                l22 = ((vader_struct_vader_midir_BasicBlock_t*) l15)->f_instructions;
                l7 = ((vader_array_t*) l22)->length;
                l8 = (size_t) (int64_t) INT64_C(0);
                {
                    loop_337: {
                        if ((l8 < l7)) {
                            vader_array_t* _a22_slotarr = ((vader_array_t*) l22);
                            if (_a22_slotarr->buf != NULL && _a22_slotarr->buf->header.forward != NULL) { _a22_slotarr->buf = vader_array_buf_forward(_a22_slotarr->buf); }
                            if ((size_t) l8 >= _a22_slotarr->length) { vader_trap("array index out of bounds"); }
                            l9 = vader_array_ref_load_box(_a22_slotarr->buf, _a22_slotarr->offset + (size_t) l8);
                            if (l9.tag == 848u) {
                                t0 = l9.payload.obj;
                                l10 = ((vader_struct_vader_midir_InstrStructNew_t*) t0)->f_dst;
                                t2 = std_collections_MutableSet_Contains_contains__i32(l1, l10);
                                if (!(t2)) {
                                    l23 = l9.payload.obj;
                                    vader_array_push((vader_array_t*) l21, vader_ref_box(l23));
                                    t1 = (l8 + INT64_C(1));
                                    l8 = (size_t) (int64_t) t1;
                                    goto loop_337;
                                }
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
                                    goto loop_337;
                                }
                                l20 = true;
                                t0 = l9.payload.obj;
                                l28 = ((vader_struct_vader_midir_InstrStructNew_t*) t0)->f_span;
                                t0 = l9.payload.obj;
                                l29 = ((vader_struct_vader_midir_InstrStructNew_t*) t0)->f_dst;
                                t0 = l9.payload.obj;
                                l16 = ((vader_struct_vader_midir_InstrStructNew_t*) t0)->f_type;
                                t0 = l9.payload.obj;
                                l30 = ((vader_struct_vader_midir_InstrStructNew_t*) t0)->f_fields;
                                vader_struct_vader_midir_InstrStructNew_t* _a23_obj = (vader_struct_vader_midir_InstrStructNew_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrStructNew_t));
                                vader_obj_header_init(_a23_obj, 848u);
                                _a23_obj->f_span = l28;
                                _a23_obj->f_dst = l29;
                                _a23_obj->f_type = l16;
                                _a23_obj->f_fields = l30;
                                _a23_obj->f_stack = l24;
                                l31 = (void*) _a23_obj;
                                vader_array_push((vader_array_t*) l21, vader_ref_box(l31));
                                l18 = (size_t) (int64_t) INT64_C(1);
                                t1 = (l8 + l18);
                                l8 = (size_t) (int64_t) t1;
                                goto loop_337;
                            }
                            if (l9.tag == 825u) {
                                t0 = l9.payload.obj;
                                l32 = ((vader_struct_vader_midir_InstrArrayNew_t*) t0)->f_dst;
                                t2 = std_collections_MutableSet_Contains_contains__i32(l1, l32);
                                if (!(t2)) {
                                    l33 = l9.payload.obj;
                                    vader_array_push((vader_array_t*) l21, vader_ref_box(l33));
                                    t1 = (l8 + INT64_C(1));
                                    l8 = (size_t) (int64_t) t1;
                                    goto loop_337;
                                }
                                l35 = ((vader_struct_vader_midir_EscapeResult_t*) l3)->f_escaping;
                                t0 = l9.payload.obj;
                                l36 = ((vader_struct_vader_midir_InstrArrayNew_t*) t0)->f_dst;
                                t2 = std_collections_MutableSet_Contains_contains__i32(l35, l36);
                                if (!(t2)) {
                                    t0 = l9.payload.obj;
                                    l37 = ((vader_struct_vader_midir_InstrArrayNew_t*) t0)->f_dst;
                                    t2 = std_collections_MutableSet_Contains_contains__i32(l6, l37);
                                    l34 = !(t2);
                                } else {
                                    l34 = false;
                                }
                                t0 = l9.payload.obj;
                                l38 = ((vader_struct_vader_midir_InstrArrayNew_t*) t0)->f_stack;
                                if (l34 == l38) {
                                    l39 = l9.payload.obj;
                                    vader_array_push((vader_array_t*) l21, vader_ref_box(l39));
                                    t1 = (l8 + INT64_C(1));
                                    l8 = (size_t) (int64_t) t1;
                                    goto loop_337;
                                }
                                l20 = true;
                                t0 = l9.payload.obj;
                                l40 = ((vader_struct_vader_midir_InstrArrayNew_t*) t0)->f_span;
                                t0 = l9.payload.obj;
                                l41 = ((vader_struct_vader_midir_InstrArrayNew_t*) t0)->f_dst;
                                t0 = l9.payload.obj;
                                l42 = ((vader_struct_vader_midir_InstrArrayNew_t*) t0)->f_type;
                                t0 = l9.payload.obj;
                                l43 = ((vader_struct_vader_midir_InstrArrayNew_t*) t0)->f_length;
                                t0 = l9.payload.obj;
                                l44 = ((vader_struct_vader_midir_InstrArrayNew_t*) t0)->f_elements;
                                vader_struct_vader_midir_InstrArrayNew_t* _a24_obj = (vader_struct_vader_midir_InstrArrayNew_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrArrayNew_t));
                                vader_obj_header_init(_a24_obj, 825u);
                                _a24_obj->f_span = l40;
                                _a24_obj->f_dst = l41;
                                _a24_obj->f_type = l42;
                                _a24_obj->f_length = l43;
                                _a24_obj->f_elements = l44;
                                _a24_obj->f_stack = l34;
                                l45 = (void*) _a24_obj;
                                vader_array_push((vader_array_t*) l21, vader_ref_box(l45));
                                l18 = (size_t) (int64_t) INT64_C(1);
                                t1 = (l8 + l18);
                                l8 = (size_t) (int64_t) t1;
                                goto loop_337;
                            }
                            if (l9.tag == 841u) {
                                t0 = l9.payload.obj;
                                l46 = ((vader_struct_vader_midir_InstrFieldSet_t*) t0)->f_target;
                                l47 = std_collections_MutableSet_Contains_contains__i32(l13, l46);
                                t0 = l9.payload.obj;
                                l48 = ((vader_struct_vader_midir_InstrFieldSet_t*) t0)->f_barrierless;
                                if (l47 == l48) {
                                    l49 = l9.payload.obj;
                                    vader_array_push((vader_array_t*) l21, vader_ref_box(l49));
                                    t1 = (l8 + INT64_C(1));
                                    l8 = (size_t) (int64_t) t1;
                                    goto loop_337;
                                }
                                l20 = true;
                                t0 = l9.payload.obj;
                                l50 = ((vader_struct_vader_midir_InstrFieldSet_t*) t0)->f_span;
                                t0 = l9.payload.obj;
                                l51 = ((vader_struct_vader_midir_InstrFieldSet_t*) t0)->f_target;
                                t0 = l9.payload.obj;
                                l52 = ((vader_struct_vader_midir_InstrFieldSet_t*) t0)->f_field;
                                t0 = l9.payload.obj;
                                l53 = ((vader_struct_vader_midir_InstrFieldSet_t*) t0)->f_value;
                                vader_struct_vader_midir_InstrFieldSet_t* _a25_obj = (vader_struct_vader_midir_InstrFieldSet_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrFieldSet_t));
                                vader_obj_header_init(_a25_obj, 841u);
                                _a25_obj->f_span = l50;
                                _a25_obj->f_target = l51;
                                _a25_obj->f_field = l52;
                                _a25_obj->f_value = l53;
                                _a25_obj->f_barrierless = l47;
                                l54 = (void*) _a25_obj;
                                vader_array_push((vader_array_t*) l21, vader_ref_box(l54));
                                l18 = (size_t) (int64_t) INT64_C(1);
                                t1 = (l8 + l18);
                                l8 = (size_t) (int64_t) t1;
                                goto loop_337;
                            }
                            l55 = l9;
                            vader_array_push((vader_array_t*) l21, l55);
                            l18 = (size_t) (int64_t) INT64_C(1);
                            t1 = (l8 + l18);
                            l8 = (size_t) (int64_t) t1;
                            goto loop_337;
                        }
                    }
                }
                if (!(l20)) {
                    vader_array_push((vader_array_t*) l2, vader_ref_box(l15));
                    t1 = (l5 + INT64_C(1));
                    l5 = (size_t) (int64_t) t1;
                    goto loop_317;
                }
                l17 = true;
                l56 = ((vader_struct_vader_midir_BasicBlock_t*) l15)->f_id;
                l57 = ((vader_struct_vader_midir_BasicBlock_t*) l15)->f_terminator;
                l58 = ((vader_struct_vader_midir_BasicBlock_t*) l15)->f_span;
                vader_struct_vader_midir_BasicBlock_t* _a26_obj = (vader_struct_vader_midir_BasicBlock_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_BasicBlock_t));
                vader_obj_header_init(_a26_obj, 802u);
                _a26_obj->f_id = l56;
                _a26_obj->f_instructions = l21;
                _a26_obj->f_terminator = l57;
                _a26_obj->f_span = l58;
                l59 = (void*) _a26_obj;
                vader_array_push((vader_array_t*) l2, vader_ref_box(l59));
                t1 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t1;
                goto loop_317;
            }
        }
    }
    if (!(l17)) {
        { void* __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l1 = l0;
    l52 = ((vader_struct_vader_midir_CFGFunction_t*) l1)->f_mangled;
    l3 = ((vader_struct_vader_midir_CFGFunction_t*) l1)->f_params;
    l9 = ((vader_struct_vader_midir_CFGFunction_t*) l1)->f_return_type;
    l6 = ((vader_struct_vader_midir_CFGFunction_t*) l1)->f_locals;
    l10 = ((vader_struct_vader_midir_CFGFunction_t*) l1)->f_entry;
    l13 = ((vader_struct_vader_midir_CFGFunction_t*) l1)->f_origin;
    l60 = ((vader_struct_vader_midir_CFGFunction_t*) l1)->f_extern_name;
    l17 = ((vader_struct_vader_midir_CFGFunction_t*) l1)->f_is_extern;
    l20 = ((vader_struct_vader_midir_CFGFunction_t*) l1)->f_is_exported;
    l1 = ((vader_struct_vader_midir_CFGFunction_t*) l1)->f_scalarised_results;
    vader_struct_vader_midir_CFGFunction_t* _a27_obj = (vader_struct_vader_midir_CFGFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_CFGFunction_t));
    vader_obj_header_init(_a27_obj, 804u);
    _a27_obj->f_mangled = l52;
    _a27_obj->f_params = l3;
    _a27_obj->f_return_type = l9;
    _a27_obj->f_locals = l6;
    _a27_obj->f_blocks = l2;
    _a27_obj->f_entry = l10;
    _a27_obj->f_origin = l13;
    _a27_obj->f_extern_name = l60;
    _a27_obj->f_is_extern = l17;
    _a27_obj->f_is_exported = l20;
    _a27_obj->f_scalarised_results = l1;
    t0 = (void*) _a27_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
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
        vader_array_t* _a0_arr = vader_array_new(9u, 1u, 7u, 179u);
        ((int32_t*) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = (int32_t) l2;
        l4 = (void*) _a0_arr;
        std_collections_MutableMap_IndexSet_set_at__i32__Any(l0, l1, vader_ref_box(l4));
    } else {
        t0 = l3.payload.obj;
        vader_array_push_i32((vader_array_t*) t0, l2);
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static vader_string_t vader_midir_array_element_name(vader_box_t l0) {
    void* t0 = NULL;
    vader_string_t t1 = 0;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[1] = { &t0 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    if (l0.tag == 927u) {
        t0 = l0.payload.obj;
        t1 = vader_types_display_type_key(((vader_struct_vader_types_ArrayType_t*) t0)->f_element);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return 0u; }
    vader_gc_top = gc_frame.prev;
}

static uint8_t vader_midir_array_element_val_type(vader_box_t l0) {
    void* t0;
    uint8_t t1;
    if (l0.tag == 927u) {
        t0 = l0.payload.obj;
        t1 = vader_bytecode_val_type_of_type(((vader_struct_vader_types_ArrayType_t*) t0)->f_element);
        return t1;
    }
    return (uint8_t) (int32_t) INT32_C(19);
}

static uint64_t vader_midir_bc_value_bits(vader_box_t l0, vader_string_t l1) {
    uint64_t l2;
    void* t0 = NULL;
    int64_t t1;
    uint32_t t2;
    bool t3;
    double t4;
    uint64_t t5;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[1] = { &t0 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    if (l0.tag == 767u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_lower_LoweredIntLit_t*) t0)->f_value;
        { uint64_t __vret = (uint64_t) (int64_t) t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 754u) {
        t0 = l0.payload.obj;
        t2 = ((vader_struct_vader_lower_LoweredCharLit_t*) t0)->f_value;
        { uint64_t __vret = (uint64_t) (int64_t) ((int64_t) (uint32_t) t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 747u) {
        t0 = l0.payload.obj;
        t3 = ((vader_struct_vader_lower_LoweredBoolLit_t*) t0)->f_value;
        if (t3) {
            l2 = (uint64_t) (int64_t) INT64_C(1);
        } else {
            l2 = (uint64_t) (int64_t) INT64_C(0);
        }
        { uint64_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 762u) {
        if (l1 == 1610u) {
            t0 = l0.payload.obj;
            t4 = ((vader_struct_vader_lower_LoweredFloatLit_t*) t0)->f_value;
            t2 = std_core_f32_Float32Bits_to_bits_vt((float) (double) t4);
            { uint64_t __vret = (uint64_t) (int64_t) ((int64_t) (uint32_t) t2); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t0 = l0.payload.obj;
        t4 = ((vader_struct_vader_lower_LoweredFloatLit_t*) t0)->f_value;
        t5 = std_core_f64_FloatBits_to_bits_vt(t4);
        { uint64_t __vret = t5; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_host_std_abort_panic(1944u);
    vader_unreachable("unreachable return in vader_midir$bc_value_bits");
    vader_gc_top = gc_frame.prev;
}

static vader_box_t vader_midir_build_args(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    size_t l4, l5;
    vader_box_t l6 = vader_box_null(), l8 = vader_box_null();
    int32_t l7;
    vader_box_t t0 = vader_box_null();
    int64_t t1;
    vader_box_t* gc_roots[3] = { &l6, &l8, &t0 };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(9u, 0u, 7u, 179u);
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
                l6 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5);
                l8 = vader_midir_build_expr(l0, l6);
                if (l8.tag == 0u) {
                    t0 = vader_box_obj(0u, NULL);
                    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
                }
                l7 = ((int32_t) l8.payload.i);
                vader_array_push_i32((vader_array_t*) l2, l7);
                t1 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t1;
                goto loop_9;
            }
        }
    }
    { vader_box_t __vret = vader_ref_box(l2); vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_box_t vader_midir_build_array_len(void* l0, void* l1) {
    int32_t l2, l4;
    vader_box_t l3 = vader_box_null();
    void* l5 = NULL;
    bool l6;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l3, &t0 };
    void** gc_raw_roots[3] = { &l0, &l1, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_lower_LoweredArrayLen_t*) l1)->f_target;
    l3 = vader_midir_build_expr(l0, l3);
    if (l3.tag == 0u) {
        t0 = vader_box_obj(0u, NULL);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = ((int32_t) l3.payload.i);
    l3 = ((vader_struct_vader_lower_LoweredArrayLen_t*) l1)->f_type;
    l4 = vader_midir_fresh_tmp(l0, 1878u, l3);
    l5 = ((vader_struct_vader_lower_LoweredArrayLen_t*) l1)->f_span;
    l6 = ((vader_struct_vader_lower_LoweredArrayLen_t*) l1)->f_resolve_buf;
    vader_struct_vader_midir_InstrArrayLen_t* _a0_obj = (vader_struct_vader_midir_InstrArrayLen_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrArrayLen_t));
    vader_obj_header_init(_a0_obj, 824u);
    _a0_obj->f_span = l5;
    _a0_obj->f_dst = l4;
    _a0_obj->f_target = l2;
    _a0_obj->f_resolve_buf = l6;
    l5 = (void*) _a0_obj;
    vader_midir_emit(l0, vader_ref_box(l5));
    t0 = vader_box_i32(179u, l4);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_box_t vader_midir_build_array_lit(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    size_t l4, l5;
    vader_box_t l6 = vader_box_null(), l8 = vader_box_null();
    int32_t l7, l9;
    vader_box_t t0 = vader_box_null();
    int64_t t1;
    size_t t2;
    vader_box_t* gc_roots[3] = { &l6, &l8, &t0 };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(9u, 0u, 7u, 179u);
    l2 = (void*) _a0_arr;
    l3 = ((vader_struct_vader_lower_LoweredArrayLit_t*) l1)->f_elements;
    l4 = ((vader_array_t*) l3)->length;
    l5 = (size_t) (int64_t) INT64_C(0);
    {
        loop_9: {
            if ((l5 < l4)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l5 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                l6 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5);
                l8 = vader_midir_build_expr(l0, l6);
                if (l8.tag == 0u) {
                    t0 = vader_box_obj(0u, NULL);
                    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
                }
                l7 = ((int32_t) l8.payload.i);
                vader_array_push_i32((vader_array_t*) l2, l7);
                t1 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t1;
                goto loop_9;
            }
        }
    }
    l6 = ((vader_struct_vader_lower_LoweredArrayLit_t*) l1)->f_type;
    l7 = vader_midir_fresh_tmp(l0, 1255u, l6);
    l3 = ((vader_struct_vader_lower_LoweredArrayLit_t*) l1)->f_span;
    l6 = ((vader_struct_vader_lower_LoweredArrayLit_t*) l1)->f_type;
    t2 = ((vader_array_t*) ((vader_struct_vader_lower_LoweredArrayLit_t*) l1)->f_elements)->length;
    l9 = ((int32_t) (size_t) t2);
    vader_struct_vader_midir_InstrArrayNew_t* _a2_obj = (vader_struct_vader_midir_InstrArrayNew_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrArrayNew_t));
    vader_obj_header_init(_a2_obj, 825u);
    _a2_obj->f_span = l3;
    _a2_obj->f_dst = l7;
    _a2_obj->f_type = l6;
    _a2_obj->f_length = l9;
    _a2_obj->f_elements = l2;
    _a2_obj->f_stack = false;
    l2 = (void*) _a2_obj;
    vader_midir_emit(l0, vader_ref_box(l2));
    t0 = vader_box_i32(179u, l7);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_box_t vader_midir_build_array_push(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l3 = vader_box_null();
    void* l4 = NULL;
    int32_t l5, l6;
    bool l7;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l2, &l3, &t0 };
    void** gc_raw_roots[3] = { &l0, &l1, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_lower_LoweredArrayPush_t*) l1)->f_target;
    l2 = vader_midir_build_expr(l0, l2);
    l3 = ((vader_struct_vader_lower_LoweredArrayPush_t*) l1)->f_value;
    l3 = vader_midir_build_expr(l0, l3);
    if (l2.tag == 0u) {
        t0 = vader_box_obj(0u, NULL);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l3.tag == 0u) {
        t0 = vader_box_obj(0u, NULL);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = ((vader_struct_vader_lower_LoweredArrayPush_t*) l1)->f_span;
    l5 = ((int32_t) l2.payload.i);
    l6 = ((int32_t) l3.payload.i);
    l7 = ((vader_struct_vader_lower_LoweredArrayPush_t*) l1)->f_cached;
    vader_struct_vader_midir_InstrArrayPush_t* _a0_obj = (vader_struct_vader_midir_InstrArrayPush_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrArrayPush_t));
    vader_obj_header_init(_a0_obj, 826u);
    _a0_obj->f_span = l4;
    _a0_obj->f_target = l5;
    _a0_obj->f_value = l6;
    _a0_obj->f_cached = l7;
    l4 = (void*) _a0_obj;
    vader_midir_emit(l0, vader_ref_box(l4));
    t0 = vader_box_obj(0u, NULL);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
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
        t0 = vader_box_obj(0u, NULL);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l3.tag == 0u) {
        t0 = vader_box_obj(0u, NULL);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4.tag == 0u) {
        t0 = vader_box_obj(0u, NULL);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l5 = ((vader_struct_vader_lower_LoweredArraySlice_t*) l1)->f_type;
    l6 = vader_midir_fresh_tmp(l0, 2104u, l5);
    l7 = ((vader_struct_vader_lower_LoweredArraySlice_t*) l1)->f_span;
    l5 = ((vader_struct_vader_lower_LoweredArraySlice_t*) l1)->f_type;
    l8 = ((int32_t) l2.payload.i);
    l9 = ((int32_t) l3.payload.i);
    l10 = ((int32_t) l4.payload.i);
    vader_struct_vader_midir_InstrArraySlice_t* _a0_obj = (vader_struct_vader_midir_InstrArraySlice_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrArraySlice_t));
    vader_obj_header_init(_a0_obj, 828u);
    _a0_obj->f_span = l7;
    _a0_obj->f_dst = l6;
    _a0_obj->f_type = l5;
    _a0_obj->f_target = l8;
    _a0_obj->f_lo = l9;
    _a0_obj->f_hi = l10;
    l7 = (void*) _a0_obj;
    vader_midir_emit(l0, vader_ref_box(l7));
    t0 = vader_box_i32(179u, l6);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
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
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_lower_LoweredAssign_t*) l1)->f_target;
    if (l2.tag == 764u) {
        l3 = ((vader_struct_vader_midir_FnCtx_t*) l0)->f_local_by_sym_id;
        t0 = l2.payload.obj;
        l4 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_lower_LoweredIdent_t*) t0)->f_symbol)->f_id;
        l5 = std_collections_MutableMap_Index_at__i32__i32(l3, l4);
        l6 = ((vader_struct_vader_lower_LoweredAssign_t*) l1)->f_value;
        l6 = vader_midir_build_expr(l0, l6);
        if (l5.tag == 0u) {
            { vader_gc_top = gc_frame.prev; return; }
        }
        if (l6.tag == 0u) {
            { vader_gc_top = gc_frame.prev; return; }
        }
        l3 = ((vader_struct_vader_lower_LoweredAssign_t*) l1)->f_span;
        l4 = ((int32_t) l5.payload.i);
        l7 = ((int32_t) l6.payload.i);
        vader_struct_vader_midir_InstrMove_t* _a0_obj = (vader_struct_vader_midir_InstrMove_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrMove_t));
        vader_obj_header_init(_a0_obj, 846u);
        _a0_obj->f_span = l3;
        _a0_obj->f_dst = l4;
        _a0_obj->f_src = l7;
        l3 = (void*) _a0_obj;
        vader_midir_emit(l0, vader_ref_box(l3));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 761u) {
        t0 = l2.payload.obj;
        l5 = ((vader_struct_vader_lower_LoweredFieldAccess_t*) t0)->f_target;
        l5 = vader_midir_build_expr(l0, l5);
        l6 = ((vader_struct_vader_lower_LoweredAssign_t*) l1)->f_value;
        l6 = vader_midir_build_expr(l0, l6);
        if (l5.tag == 0u) {
            { vader_gc_top = gc_frame.prev; return; }
        }
        if (l6.tag == 0u) {
            { vader_gc_top = gc_frame.prev; return; }
        }
        l3 = ((vader_struct_vader_lower_LoweredAssign_t*) l1)->f_span;
        l4 = ((int32_t) l5.payload.i);
        t0 = l2.payload.obj;
        l8 = ((vader_struct_vader_lower_LoweredFieldAccess_t*) t0)->f_field;
        l7 = ((int32_t) l6.payload.i);
        vader_struct_vader_midir_InstrFieldSet_t* _a1_obj = (vader_struct_vader_midir_InstrFieldSet_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrFieldSet_t));
        vader_obj_header_init(_a1_obj, 841u);
        _a1_obj->f_span = l3;
        _a1_obj->f_target = l4;
        _a1_obj->f_field = l8;
        _a1_obj->f_value = l7;
        _a1_obj->f_barrierless = false;
        l3 = (void*) _a1_obj;
        vader_midir_emit(l0, vader_ref_box(l3));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 766u) {
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
        if (l9.tag == 0u) {
            { vader_gc_top = gc_frame.prev; return; }
        }
        l3 = ((vader_struct_vader_lower_LoweredAssign_t*) l1)->f_span;
        l4 = ((int32_t) l5.payload.i);
        l7 = ((int32_t) l6.payload.i);
        l10 = ((int32_t) l9.payload.i);
        t0 = l2.payload.obj;
        l11 = ((vader_struct_vader_lower_LoweredIndex_t*) t0)->f_bounds_safe;
        vader_struct_vader_midir_InstrArraySet_t* _a2_obj = (vader_struct_vader_midir_InstrArraySet_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrArraySet_t));
        vader_obj_header_init(_a2_obj, 827u);
        _a2_obj->f_span = l3;
        _a2_obj->f_target = l4;
        _a2_obj->f_index = l7;
        _a2_obj->f_value = l10;
        _a2_obj->f_bounds_safe = l11;
        l3 = (void*) _a2_obj;
        vader_midir_emit(l0, vader_ref_box(l3));
        { vader_gc_top = gc_frame.prev; return; }
    }
    l2 = ((vader_struct_vader_lower_LoweredAssign_t*) l1)->f_value;
    vader_midir_build_expr(l0, l2);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
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
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = vader_midir_is_short_circuit_op(((vader_struct_vader_lower_LoweredBinary_t*) l1)->f_op);
    if (t0) {
        t1 = vader_midir_build_short_circuit(l0, l1, vader_box_obj(0u, NULL));
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = ((vader_struct_vader_lower_LoweredBinary_t*) l1)->f_left;
    l3 = vader_midir_build_expr(l0, l3);
    if (l3.tag == 0u) {
        t1 = vader_box_obj(0u, NULL);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = ((int32_t) l3.payload.i);
    l3 = ((vader_struct_vader_lower_LoweredBinary_t*) l1)->f_right;
    l3 = vader_midir_build_expr(l0, l3);
    if (l3.tag == 0u) {
        t1 = vader_box_obj(0u, NULL);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = ((int32_t) l3.payload.i);
    l5 = vader_lower_binary_op_name(((vader_struct_vader_lower_LoweredBinary_t*) l1)->f_op);
    l3 = ((vader_struct_vader_lower_LoweredBinary_t*) l1)->f_type;
    l6 = vader_midir_fresh_tmp(l0, l5, l3);
    l7 = ((vader_struct_vader_lower_LoweredBinary_t*) l1)->f_span;
    l8 = ((vader_struct_vader_lower_LoweredBinary_t*) l1)->f_op;
    l3 = ((vader_struct_vader_lower_LoweredBinary_t*) l1)->f_type;
    vader_struct_vader_midir_InstrBinOp_t* _a0_obj = (vader_struct_vader_midir_InstrBinOp_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrBinOp_t));
    vader_obj_header_init(_a0_obj, 829u);
    _a0_obj->f_span = l7;
    _a0_obj->f_dst = l6;
    _a0_obj->f_op = l8;
    _a0_obj->f_lhs = l2;
    _a0_obj->f_rhs = l4;
    _a0_obj->f_type = l3;
    l7 = (void*) _a0_obj;
    vader_midir_emit(l0, vader_ref_box(l7));
    t1 = vader_box_i32(179u, l6);
    { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_box_t vader_midir_build_block_body(void* l0, void* l1) {
    void* l2 = NULL;
    size_t l3, l4;
    vader_box_t l5 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    int64_t t1;
    vader_box_t* gc_roots[2] = { &l5, &t0 };
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_lower_LoweredBlock_t*) l1)->f_stmts;
    l3 = ((vader_array_t*) l2)->length;
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_7: {
            if ((l4 < l3)) {
                vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
                if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                if ((size_t) l4 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                l5 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
                if (((vader_struct_vader_midir_FnCtx_t*) l0)->f_current.tag == 0u) {
                    t0 = vader_box_obj(0u, NULL);
                    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
                }
                vader_midir_build_stmt(l0, l5);
                t1 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t1;
                goto loop_7;
            }
        }
    }
    if (((vader_struct_vader_midir_FnCtx_t*) l0)->f_current.tag == 0u) {
        t0 = vader_box_obj(0u, NULL);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (((vader_struct_vader_lower_LoweredBlock_t*) l1)->f_trailing.tag == 0u) {
        t0 = vader_box_obj(0u, NULL);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l5 = ((vader_struct_vader_lower_LoweredBlock_t*) l1)->f_trailing;
    t0 = vader_midir_build_expr(l0, l5);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
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
    l5 = (size_t) (int64_t) INT64_C(0);
    {
        loop_7: {
            if ((l5 < l4)) {
                vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
                if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                if ((size_t) l5 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                l6 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
                if (((vader_struct_vader_midir_FnCtx_t*) l0)->f_current.tag == 0u) {
                    { vader_gc_top = gc_frame.prev; return; }
                }
                vader_midir_build_stmt(l0, l6);
                t0 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t0;
                goto loop_7;
            }
        }
    }
    if (((vader_struct_vader_midir_FnCtx_t*) l0)->f_current.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (!(((vader_struct_vader_lower_LoweredBlock_t*) l1)->f_trailing.tag == 0u)) {
        l6 = ((vader_struct_vader_lower_LoweredBlock_t*) l1)->f_trailing;
        vader_midir_build_expr_into(l0, l6, l2);
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static vader_box_t vader_midir_build_call(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    int32_t l4;
    vader_box_t l5 = vader_box_null(), l9 = vader_box_null(), l10 = vader_box_null();
    vader_string_t l8 = 0;
    vader_box_t t0 = vader_box_null();
    bool t1;
    int32_t t2;
    vader_box_t* gc_roots[4] = { &l5, &l9, &l10, &t0 };
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l3, &l6, &l7 };
    vader_string_t* gc_atom_roots[1] = { &l8 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    if (((vader_struct_vader_lower_LoweredCall_t*) l1)->f_callee.tag == 764u) {
        l2 = ((vader_struct_vader_lower_LoweredCall_t*) l1)->f_callee.payload.obj;
        if (((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_lower_LoweredIdent_t*) l2)->f_symbol)->f_kind == INT32_C(0)) {
            l3 = ((vader_struct_vader_midir_ProjectCtx_t*) ((vader_struct_vader_midir_FnCtx_t*) l0)->f_project)->f_extern_callbacks;
            l4 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_lower_LoweredIdent_t*) l2)->f_symbol)->f_id;
            l5 = std_collections_MutableMap_Index_at__i32__Any(l3, l4);
            if ((l5.tag == 387u || l5.tag == 384u || l5.tag == 385u || l5.tag == 386u)) {
                l6 = l5.payload.obj;
                l7 = ((vader_struct_vader_lower_LoweredCall_t*) l1)->f_args;
                l8 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_lower_LoweredIdent_t*) l2)->f_symbol)->f_name;
                l5 = vader_midir_build_extern_args(l0, l7, l6, l8);
                if (l5.tag == 0u) {
                    t0 = vader_box_obj(0u, NULL);
                    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
                }
                l3 = l5.payload.obj;
            } else {
                l6 = ((vader_struct_vader_lower_LoweredCall_t*) l1)->f_args;
                l5 = vader_midir_build_args(l0, l6);
                if (l5.tag == 0u) {
                    t0 = vader_box_obj(0u, NULL);
                    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
                }
                l3 = l5.payload.obj;
            }
            t1 = vader_typecheck_is_void(((vader_struct_vader_lower_LoweredCall_t*) l1)->f_type);
            if (t1) {
                l5 = vader_box_obj(0u, NULL);
            } else {
                l9 = ((vader_struct_vader_lower_LoweredCall_t*) l1)->f_type;
                t2 = vader_midir_fresh_tmp(l0, 1391u, l9);
                l5 = vader_box_i32(179u, t2);
            }
            l6 = ((vader_struct_vader_lower_LoweredCall_t*) l1)->f_span;
            if (l5.tag == 0u) {
                vader_array_t* _a0_arr = vader_array_new(9u, 0u, 7u, 179u);
                l7 = (void*) _a0_arr;
            } else {
                t2 = ((int32_t) l5.payload.i);
                vader_array_t* _a1_arr = vader_array_new(9u, 1u, 7u, 179u);
                ((int32_t*) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = (int32_t) t2;
                l7 = (void*) _a1_arr;
            }
            l2 = ((vader_struct_vader_lower_LoweredIdent_t*) l2)->f_symbol;
            l9 = ((vader_struct_vader_lower_LoweredCall_t*) l1)->f_type;
            vader_struct_vader_midir_InstrCall_t* _a2_obj = (vader_struct_vader_midir_InstrCall_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrCall_t));
            vader_obj_header_init(_a2_obj, 830u);
            _a2_obj->f_span = l6;
            _a2_obj->f_dsts = l7;
            _a2_obj->f_callee = l2;
            _a2_obj->f_args = l3;
            _a2_obj->f_type = l9;
            l2 = (void*) _a2_obj;
            vader_midir_emit(l0, vader_ref_box(l2));
            { vader_box_t __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    l5 = ((vader_struct_vader_lower_LoweredCall_t*) l1)->f_callee;
    l5 = vader_midir_build_expr(l0, l5);
    if (l5.tag == 0u) {
        t0 = vader_box_obj(0u, NULL);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = ((int32_t) l5.payload.i);
    l3 = ((vader_struct_vader_lower_LoweredCall_t*) l1)->f_args;
    l5 = vader_midir_build_args(l0, l3);
    if (l5.tag == 0u) {
        t0 = vader_box_obj(0u, NULL);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = l5.payload.obj;
    t1 = vader_typecheck_is_void(((vader_struct_vader_lower_LoweredCall_t*) l1)->f_type);
    if (t1) {
        l5 = vader_box_obj(0u, NULL);
    } else {
        l9 = ((vader_struct_vader_lower_LoweredCall_t*) l1)->f_type;
        t2 = vader_midir_fresh_tmp(l0, 1402u, l9);
        l5 = vader_box_i32(179u, t2);
    }
    l3 = ((vader_struct_vader_lower_LoweredCall_t*) l1)->f_span;
    l9 = vader_lower_type_of(((vader_struct_vader_lower_LoweredCall_t*) l1)->f_callee);
    l10 = ((vader_struct_vader_lower_LoweredCall_t*) l1)->f_type;
    vader_struct_vader_midir_InstrCallIndirect_t* _a3_obj = (vader_struct_vader_midir_InstrCallIndirect_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrCallIndirect_t));
    vader_obj_header_init(_a3_obj, 831u);
    _a3_obj->f_span = l3;
    _a3_obj->f_dst = l5;
    _a3_obj->f_callee = l4;
    _a3_obj->f_args = l2;
    _a3_obj->f_fn_type = l9;
    _a3_obj->f_type = l10;
    l2 = (void*) _a3_obj;
    vader_midir_emit(l0, vader_ref_box(l2));
    { vader_box_t __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
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
        t0 = vader_box_obj(0u, NULL);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = ((int32_t) l3.payload.i);
    l3 = ((vader_struct_vader_lower_LoweredCast_t*) l1)->f_type;
    l4 = vader_midir_fresh_tmp(l0, 1421u, l3);
    l5 = ((vader_struct_vader_lower_LoweredCast_t*) l1)->f_span;
    l3 = ((vader_struct_vader_lower_LoweredCast_t*) l1)->f_type;
    vader_struct_vader_midir_InstrCast_t* _a0_obj = (vader_struct_vader_midir_InstrCast_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrCast_t));
    vader_obj_header_init(_a0_obj, 832u);
    _a0_obj->f_span = l5;
    _a0_obj->f_dst = l4;
    _a0_obj->f_value = l2;
    _a0_obj->f_type = l3;
    l5 = (void*) _a0_obj;
    vader_midir_emit(l0, vader_ref_box(l5));
    t0 = vader_box_i32(179u, l4);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
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
        t0 = vader_box_obj(0u, NULL);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = ((int32_t) l3.payload.i);
    l3 = ((vader_struct_vader_lower_LoweredCellGet_t*) l1)->f_type;
    l4 = vader_midir_fresh_tmp(l0, 1423u, l3);
    l5 = ((vader_struct_vader_lower_LoweredCellGet_t*) l1)->f_span;
    l3 = ((vader_struct_vader_lower_LoweredCellGet_t*) l1)->f_value_type;
    vader_struct_vader_midir_InstrCellGet_t* _a0_obj = (vader_struct_vader_midir_InstrCellGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrCellGet_t));
    vader_obj_header_init(_a0_obj, 833u);
    _a0_obj->f_span = l5;
    _a0_obj->f_dst = l4;
    _a0_obj->f_cell = l2;
    _a0_obj->f_value_type = l3;
    l5 = (void*) _a0_obj;
    vader_midir_emit(l0, vader_ref_box(l5));
    t0 = vader_box_i32(179u, l4);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
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
        t0 = vader_box_obj(0u, NULL);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = ((int32_t) l3.payload.i);
    l3 = ((vader_struct_vader_lower_LoweredCellNew_t*) l1)->f_type;
    l4 = vader_midir_fresh_tmp(l0, 1422u, l3);
    l5 = ((vader_struct_vader_lower_LoweredCellNew_t*) l1)->f_span;
    l3 = ((vader_struct_vader_lower_LoweredCellNew_t*) l1)->f_value_type;
    vader_struct_vader_midir_InstrCellNew_t* _a0_obj = (vader_struct_vader_midir_InstrCellNew_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrCellNew_t));
    vader_obj_header_init(_a0_obj, 834u);
    _a0_obj->f_span = l5;
    _a0_obj->f_dst = l4;
    _a0_obj->f_value = l2;
    _a0_obj->f_value_type = l3;
    l5 = (void*) _a0_obj;
    vader_midir_emit(l0, vader_ref_box(l5));
    t0 = vader_box_i32(179u, l4);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

void* vader_midir_build_cfg_project(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l10 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    void* l15 = NULL;
    void* l16 = NULL;
    void* l20 = NULL;
    void* l22 = NULL;
    void* l23 = NULL;
    void* l26 = NULL;
    void* l27 = NULL;
    void* l28 = NULL;
    void* l29 = NULL;
    void* l30 = NULL;
    size_t l7, l8, l17, l18;
    vader_string_t l9 = 0;
    vader_string_t l11 = 0;
    vader_string_t l24 = 0;
    vader_string_t l25 = 0;
    vader_box_t l19 = vader_box_null(), l21 = vader_box_null();
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    int64_t t2;
    vader_box_t* gc_roots[3] = { &l19, &l21, &t1 };
    void** gc_raw_roots[22] = { &l0, &l1, &l2, &l3, &l4, &l5, &l6, &l10, &l12, &l13, &l14, &l15, &l16, &l20, &l22, &l23, &l26, &l27, &l28, &l29, &l30, &t0 };
    vader_string_t* gc_atom_roots[4] = { &l9, &l11, &l24, &l25 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 22u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = vader_midir_new_project_ctx(l0, l1);
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 176u);
    l3 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(16u, 0u, 0u, 187u);
    l4 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 179u);
    l5 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__string__Any_t* _a3_obj = (vader_struct_std_collections_MutableMap__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__Any_t));
    vader_obj_header_init(_a3_obj, 326u);
    _a3_obj->f_ekeys = l3;
    _a3_obj->f_evals = l4;
    _a3_obj->f_index = l5;
    _a3_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l3 = (void*) _a3_obj;
    l4 = ((vader_struct_vader_lower_LoweredProject_t*) l0)->f_modules;
    l5 = ((vader_struct_std_collections_MutableMap__string__LoweredModule_t*) l4)->f_ekeys;
    l6 = ((vader_struct_std_collections_MutableMap__string__LoweredModule_t*) l4)->f_evals;
    l7 = ((vader_struct_std_collections_MutableMap__string__LoweredModule_t*) l4)->f_size;
    l8 = (size_t) (int64_t) INT64_C(0);
    {
        loop_30: {
            if ((l8 >= l7)) {
                l27 = ((vader_struct_vader_lower_LoweredProject_t*) l0)->f_vtable_entries;
                l28 = ((vader_struct_vader_midir_ProjectCtx_t*) l2)->f_strings;
                l29 = vader_midir_convert_data_pool(((vader_struct_vader_lower_LoweredProject_t*) l0)->f_data_pool);
                l30 = ((vader_struct_vader_lower_LoweredProject_t*) l0)->f_trait_membership;
                vader_struct_vader_midir_CFGProject_t* _a4_obj = (vader_struct_vader_midir_CFGProject_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_CFGProject_t));
                vader_obj_header_init(_a4_obj, 808u);
                _a4_obj->f_modules = l3;
                _a4_obj->f_vtable_entries = l27;
                _a4_obj->f_strings = l28;
                _a4_obj->f_data_pool = l29;
                _a4_obj->f_trait_membership = l30;
                t0 = (void*) _a4_obj;
                { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
            }
            vader_array_t* _a5_slotarr = ((vader_array_t*) l5);
            if (_a5_slotarr->buf != NULL && _a5_slotarr->buf->header.forward != NULL) { _a5_slotarr->buf = vader_array_buf_forward(_a5_slotarr->buf); }
            if ((size_t) l8 >= _a5_slotarr->length) { vader_trap("array index out of bounds"); }
            t1 = vader_array_box_slots(_a5_slotarr->buf)[_a5_slotarr->offset + (size_t) l8];
            l9 = t1.payload.s;
            vader_array_t* _a6_slotarr = ((vader_array_t*) l6);
            if (_a6_slotarr->buf != NULL && _a6_slotarr->buf->header.forward != NULL) { _a6_slotarr->buf = vader_array_buf_forward(_a6_slotarr->buf); }
            if ((size_t) l8 >= _a6_slotarr->length) { vader_trap("array index out of bounds"); }
            l4 = vader_array_ref_load_obj(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l8);
            vader_struct___Tuple_2_edd3c91327bcb309_t* _a7_obj = (vader_struct___Tuple_2_edd3c91327bcb309_t*) vader_gc_alloc(sizeof(vader_struct___Tuple_2_edd3c91327bcb309_t));
            vader_obj_header_init(_a7_obj, 232u);
            _a7_obj->f__0 = l9;
            _a7_obj->f__1 = l4;
            l10 = (void*) _a7_obj;
            l11 = ((vader_struct___Tuple_2_edd3c91327bcb309_t*) l10)->f__0;
            l12 = ((vader_struct___Tuple_2_edd3c91327bcb309_t*) l10)->f__1;
            t2 = (l8 + INT64_C(1));
            l8 = (size_t) (int64_t) t2;
            vader_array_t* _a8_arr = vader_array_new(76u, 0u, 13u, 804u);
            l13 = (void*) _a8_arr;
            vader_array_t* _a9_arr = vader_array_new(75u, 0u, 13u, 803u);
            l14 = (void*) _a9_arr;
            vader_array_t* _a10_arr = vader_array_new(80u, 0u, 13u, 809u);
            l15 = (void*) _a10_arr;
            l16 = ((vader_struct_vader_lower_LoweredModule_t*) l12)->f_decls;
            l17 = ((vader_array_t*) l16)->length;
            l18 = (size_t) (int64_t) INT64_C(0);
            {
                loop_87: {
                    if ((l18 < l17)) {
                        vader_array_t* _a11_slotarr = ((vader_array_t*) l16);
                        if (_a11_slotarr->buf != NULL && _a11_slotarr->buf->header.forward != NULL) { _a11_slotarr->buf = vader_array_buf_forward(_a11_slotarr->buf); }
                        if ((size_t) l18 >= _a11_slotarr->length) { vader_trap("array index out of bounds"); }
                        l19 = vader_array_ref_load_box(_a11_slotarr->buf, _a11_slotarr->offset + (size_t) l18);
                        if (l19.tag == 763u) {
                            t0 = l19.payload.obj;
                            if (((vader_struct_vader_lower_LoweredFnDecl_t*) t0)->f_body.tag == 0u) {
                                t0 = l19.payload.obj;
                                l20 = vader_midir_make_extern_decl(t0);
                                vader_array_push((vader_array_t*) l14, vader_ref_box(l20));
                            } else {
                                t0 = l19.payload.obj;
                                l21 = vader_midir_convert_function(t0, l2);
                                if (!(l21.tag == 0u)) {
                                    l22 = l21.payload.obj;
                                    vader_array_push((vader_array_t*) l13, vader_ref_box(l22));
                                }
                            }
                        } else {
                            if (l19.tag == 779u) {
                                t0 = l19.payload.obj;
                                l23 = vader_midir_make_struct_decl(t0);
                                vader_array_push((vader_array_t*) l15, vader_ref_box(l23));
                            } else {
                                if (l19.tag == 755u) {
                                } else {
                                    vader_unreachable("unreachable return in vader_midir$build_cfg_project");
                                }
                            }
                        }
                        t2 = (l18 + INT64_C(1));
                        l18 = (size_t) (int64_t) t2;
                        goto loop_87;
                    }
                }
            }
            l24 = ((vader_struct_vader_lower_LoweredModule_t*) l12)->f_module_id;
            l25 = ((vader_struct_vader_lower_LoweredModule_t*) l12)->f_display_path;
            vader_struct_vader_midir_CFGModule_t* _a12_obj = (vader_struct_vader_midir_CFGModule_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_CFGModule_t));
            vader_obj_header_init(_a12_obj, 806u);
            _a12_obj->f_module_id = l24;
            _a12_obj->f_display_path = l25;
            _a12_obj->f_functions = l13;
            _a12_obj->f_externs = l14;
            _a12_obj->f_struct_decls = l15;
            l26 = (void*) _a12_obj;
            std_collections_MutableMap_IndexSet_set_at__string__Any(l3, l11, vader_ref_box(l26));
            goto loop_30;
        }
    }
    l27 = ((vader_struct_vader_lower_LoweredProject_t*) l0)->f_vtable_entries;
    l28 = ((vader_struct_vader_midir_ProjectCtx_t*) l2)->f_strings;
    l29 = vader_midir_convert_data_pool(((vader_struct_vader_lower_LoweredProject_t*) l0)->f_data_pool);
    l30 = ((vader_struct_vader_lower_LoweredProject_t*) l0)->f_trait_membership;
    vader_struct_vader_midir_CFGProject_t* _a13_obj = (vader_struct_vader_midir_CFGProject_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_CFGProject_t));
    vader_obj_header_init(_a13_obj, 808u);
    _a13_obj->f_modules = l3;
    _a13_obj->f_vtable_entries = l27;
    _a13_obj->f_strings = l28;
    _a13_obj->f_data_pool = l29;
    _a13_obj->f_trait_membership = l30;
    t0 = (void*) _a13_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_midir_build_cfg_signature(void* l0, vader_box_t l1, void* l2, void* l3) {
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l11 = NULL;
    void* l16 = NULL;
    size_t l9, l10;
    uint8_t l12;
    int32_t l13;
    vader_string_t l14 = 0;
    bool l15;
    vader_box_t l17 = vader_box_null();
    int64_t t0;
    size_t t1;
    void* t2 = NULL;
    vader_box_t* gc_roots[2] = { &l1, &l17 };
    void** gc_raw_roots[11] = { &l0, &l2, &l3, &l4, &l5, &l6, &l7, &l8, &l11, &l16, &t2 };
    vader_string_t* gc_atom_roots[1] = { &l14 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 11u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(11u, 0u, 1u, 182u);
    l4 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(9u, 0u, 7u, 179u);
    l5 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(8u, 0u, 0u, 176u);
    l6 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(6u, 0u, 12u, 174u);
    l7 = (void*) _a3_arr;
    l8 = l0;
    l9 = ((vader_array_t*) l8)->length;
    l10 = (size_t) (int64_t) INT64_C(0);
    {
        loop_15: {
            if ((l10 < l9)) {
                vader_array_t* _a4_slotarr = ((vader_array_t*) l8);
                if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                if ((size_t) l10 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                l11 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l10);
                l12 = vader_bytecode_val_type_of_type(((vader_struct_vader_midir_CFGParam_t*) l11)->f_type);
                vader_array_push_u8((vader_array_t*) l4, (int32_t) (uint8_t) l12);
                l13 = vader_bytecode_intern_type(((vader_struct_vader_midir_CFGParam_t*) l11)->f_type, l3);
                vader_array_push_i32((vader_array_t*) l5, l13);
                l14 = ((vader_struct_vader_midir_CFGParam_t*) l11)->f_name;
                vader_array_push((vader_array_t*) l6, vader_box_string(176u, l14));
                l15 = vader_midir_is_mutable_slot(((vader_struct_vader_midir_CFGParam_t*) l11)->f_type);
                vader_array_push_bool((vader_array_t*) l7, l15);
                t0 = (l10 + INT64_C(1));
                l10 = (size_t) (int64_t) t0;
                goto loop_15;
            }
        }
    }
    vader_array_t* _a5_arr = vader_array_new(11u, 0u, 1u, 182u);
    l8 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(9u, 0u, 7u, 179u);
    l11 = (void*) _a6_arr;
    t1 = ((vader_array_t*) l2)->length;
    if ((t1 > INT64_C(1))) {
        l16 = l2;
        l9 = ((vader_array_t*) l16)->length;
        l10 = (size_t) (int64_t) INT64_C(0);
        {
            loop_73: {
                if ((l10 < l9)) {
                    vader_array_t* _a7_slotarr = ((vader_array_t*) l16);
                    if (_a7_slotarr->buf != NULL && _a7_slotarr->buf->header.forward != NULL) { _a7_slotarr->buf = vader_array_buf_forward(_a7_slotarr->buf); }
                    if ((size_t) l10 >= _a7_slotarr->length) { vader_trap("array index out of bounds"); }
                    l17 = vader_array_ref_load_box(_a7_slotarr->buf, _a7_slotarr->offset + (size_t) l10);
                    l12 = vader_bytecode_val_type_of_type(l17);
                    vader_array_push_u8((vader_array_t*) l8, (int32_t) (uint8_t) l12);
                    l13 = vader_bytecode_intern_type(l17, l3);
                    vader_array_push_i32((vader_array_t*) l11, l13);
                    t0 = (l10 + INT64_C(1));
                    l10 = (size_t) (int64_t) t0;
                    goto loop_73;
                }
            }
        }
    } else {
        l12 = vader_bytecode_val_type_of_type(l1);
        vader_array_push_u8((vader_array_t*) l8, (int32_t) (uint8_t) l12);
        l13 = vader_bytecode_intern_type(l1, l3);
        vader_array_push_i32((vader_array_t*) l11, l13);
    }
    vader_array_t* _a8_arr = vader_array_new(6u, 0u, 12u, 174u);
    l16 = (void*) _a8_arr;
    vader_struct_vader_bytecode_BcSignature_t* _a9_obj = (vader_struct_vader_bytecode_BcSignature_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcSignature_t));
    vader_obj_header_init(_a9_obj, 514u);
    _a9_obj->f_params = l4;
    _a9_obj->f_results = l8;
    _a9_obj->f_param_types = l5;
    _a9_obj->f_result_types = l11;
    _a9_obj->f_param_names = l6;
    _a9_obj->f_param_mutable = l7;
    _a9_obj->f_param_by_address = l16;
    t2 = (void*) _a9_obj;
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
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
    l3 = vader_midir_fresh_tmp(l0, 1496u, l2);
    l4 = ((vader_struct_vader_lower_LoweredDataConst_t*) l1)->f_span;
    l2 = ((vader_struct_vader_lower_LoweredDataConst_t*) l1)->f_type;
    t0 = ((vader_struct_vader_lower_LoweredDataConst_t*) l1)->f_pool_index;
    l5 = ((int32_t) (size_t) t0);
    vader_struct_vader_midir_InstrDataConst_t* _a0_obj = (vader_struct_vader_midir_InstrDataConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrDataConst_t));
    vader_obj_header_init(_a0_obj, 837u);
    _a0_obj->f_span = l4;
    _a0_obj->f_dst = l3;
    _a0_obj->f_type = l2;
    _a0_obj->f_pool_index = l5;
    l4 = (void*) _a0_obj;
    vader_midir_emit(l0, vader_ref_box(l4));
    t1 = vader_box_i32(179u, l3);
    { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_box_t vader_midir_build_expr(void* l0, vader_box_t l1) {
    vader_box_t l2 = vader_box_null();
    void* l3 = NULL;
    void* l4 = NULL;
    vader_string_t l5 = 0;
    int32_t l6;
    bool l7;
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    int64_t t2;
    int32_t t3;
    double t4;
    bool t5;
    uint32_t t6;
    vader_box_t* gc_roots[3] = { &l1, &l2, &t0 };
    void** gc_raw_roots[4] = { &l0, &l3, &l4, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    if (((vader_struct_vader_midir_FnCtx_t*) l0)->f_current.tag == 0u) {
        t0 = vader_box_obj(0u, NULL);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 767u) {
        t1 = l1.payload.obj;
        l2 = ((vader_struct_vader_lower_LoweredIntLit_t*) t1)->f_type;
        t1 = l1.payload.obj;
        t2 = ((vader_struct_vader_lower_LoweredIntLit_t*) t1)->f_value;
        vader_struct_vader_midir_ConstInt_t* _a0_obj = (vader_struct_vader_midir_ConstInt_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_ConstInt_t));
        vader_obj_header_init(_a0_obj, 814u);
        _a0_obj->f_value = t2;
        l3 = (void*) _a0_obj;
        t1 = l1.payload.obj;
        l4 = ((vader_struct_vader_lower_LoweredIntLit_t*) t1)->f_span;
        t3 = vader_midir_emit_const(l0, l2, vader_ref_box(l3), l4);
        t0 = vader_box_i32(179u, t3);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 762u) {
        t1 = l1.payload.obj;
        l2 = ((vader_struct_vader_lower_LoweredFloatLit_t*) t1)->f_type;
        t1 = l1.payload.obj;
        t4 = ((vader_struct_vader_lower_LoweredFloatLit_t*) t1)->f_value;
        vader_struct_vader_midir_ConstFloat_t* _a1_obj = (vader_struct_vader_midir_ConstFloat_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_ConstFloat_t));
        vader_obj_header_init(_a1_obj, 813u);
        _a1_obj->f_value = t4;
        l3 = (void*) _a1_obj;
        t1 = l1.payload.obj;
        l4 = ((vader_struct_vader_lower_LoweredFloatLit_t*) t1)->f_span;
        t3 = vader_midir_emit_const(l0, l2, vader_ref_box(l3), l4);
        t0 = vader_box_i32(179u, t3);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 747u) {
        t1 = l1.payload.obj;
        l2 = ((vader_struct_vader_lower_LoweredBoolLit_t*) t1)->f_type;
        t1 = l1.payload.obj;
        t5 = ((vader_struct_vader_lower_LoweredBoolLit_t*) t1)->f_value;
        vader_struct_vader_midir_ConstBool_t* _a2_obj = (vader_struct_vader_midir_ConstBool_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_ConstBool_t));
        vader_obj_header_init(_a2_obj, 811u);
        _a2_obj->f_value = t5;
        l3 = (void*) _a2_obj;
        t1 = l1.payload.obj;
        l4 = ((vader_struct_vader_lower_LoweredBoolLit_t*) t1)->f_span;
        t3 = vader_midir_emit_const(l0, l2, vader_ref_box(l3), l4);
        t0 = vader_box_i32(179u, t3);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 773u) {
        t1 = l1.payload.obj;
        l2 = ((vader_struct_vader_lower_LoweredNullLit_t*) t1)->f_type;
        vader_struct_vader_midir_ConstNull_t* _a3_obj = (vader_struct_vader_midir_ConstNull_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_ConstNull_t));
        vader_obj_header_init(_a3_obj, 815u);
        l3 = (void*) _a3_obj;
        t1 = l1.payload.obj;
        l4 = ((vader_struct_vader_lower_LoweredNullLit_t*) t1)->f_span;
        t3 = vader_midir_emit_const(l0, l2, vader_ref_box(l3), l4);
        t0 = vader_box_i32(179u, t3);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 754u) {
        t1 = l1.payload.obj;
        l2 = ((vader_struct_vader_lower_LoweredCharLit_t*) t1)->f_type;
        t1 = l1.payload.obj;
        t6 = ((vader_struct_vader_lower_LoweredCharLit_t*) t1)->f_value;
        vader_struct_vader_midir_ConstChar_t* _a4_obj = (vader_struct_vader_midir_ConstChar_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_ConstChar_t));
        vader_obj_header_init(_a4_obj, 812u);
        _a4_obj->f_value = ((int32_t) (uint32_t) t6);
        l3 = (void*) _a4_obj;
        t1 = l1.payload.obj;
        l4 = ((vader_struct_vader_lower_LoweredCharLit_t*) t1)->f_span;
        t3 = vader_midir_emit_const(l0, l2, vader_ref_box(l3), l4);
        t0 = vader_box_i32(179u, t3);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 777u) {
        l3 = ((vader_struct_vader_midir_FnCtx_t*) l0)->f_project;
        t1 = l1.payload.obj;
        l5 = ((vader_struct_vader_lower_LoweredStringLit_t*) t1)->f_value;
        l6 = vader_midir_intern_string_pool(l3, l5);
        t1 = l1.payload.obj;
        l2 = ((vader_struct_vader_lower_LoweredStringLit_t*) t1)->f_type;
        vader_struct_vader_midir_ConstString_t* _a5_obj = (vader_struct_vader_midir_ConstString_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_ConstString_t));
        vader_obj_header_init(_a5_obj, 816u);
        _a5_obj->f_index = l6;
        l3 = (void*) _a5_obj;
        t1 = l1.payload.obj;
        l4 = ((vader_struct_vader_lower_LoweredStringLit_t*) t1)->f_span;
        t3 = vader_midir_emit_const(l0, l2, vader_ref_box(l3), l4);
        t0 = vader_box_i32(179u, t3);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 764u) {
        l3 = l1.payload.obj;
        t0 = vader_midir_build_ident(l0, l3);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 749u) {
        l3 = l1.payload.obj;
        t0 = vader_midir_build_call(l0, l3);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 787u) {
        l3 = l1.payload.obj;
        t0 = vader_midir_build_virtual_call(l0, l3);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 761u) {
        l3 = l1.payload.obj;
        t0 = vader_midir_build_field_access(l0, l3);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 766u) {
        l3 = l1.payload.obj;
        t0 = vader_midir_build_index(l0, l3);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 785u) {
        l3 = l1.payload.obj;
        t0 = vader_midir_build_unary(l0, l3);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 745u) {
        l3 = l1.payload.obj;
        t0 = vader_midir_build_binary(l0, l3);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 765u) {
        l3 = l1.payload.obj;
        t0 = vader_midir_build_if(l0, l3, vader_box_obj(0u, NULL));
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 746u) {
        l3 = l1.payload.obj;
        t0 = vader_midir_build_block_body(l0, l3);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 781u) {
        l3 = l1.payload.obj;
        t0 = vader_midir_build_struct_lit(l0, l3);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 740u) {
        l3 = l1.payload.obj;
        t0 = vader_midir_build_array_lit(l0, l3);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 750u) {
        l3 = l1.payload.obj;
        t0 = vader_midir_build_cast(l0, l3);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 783u) {
        l3 = l1.payload.obj;
        t0 = vader_midir_build_type_check(l0, l3);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 786u) {
        t1 = l1.payload.obj;
        l2 = ((vader_struct_vader_lower_LoweredUnreachable_t*) t1)->f_type;
        t1 = l1.payload.obj;
        l3 = ((vader_struct_vader_lower_LoweredUnreachable_t*) t1)->f_span;
        t1 = l1.payload.obj;
        l5 = ((vader_struct_vader_lower_LoweredUnreachable_t*) t1)->f_reason;
        t1 = l1.payload.obj;
        l7 = ((vader_struct_vader_lower_LoweredUnreachable_t*) t1)->f_trap;
        t0 = vader_midir_build_unreachable_type(l0, l2, l3, l5, l7);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 768u) {
        l3 = l1.payload.obj;
        t0 = vader_midir_build_intrinsic_call(l0, l3);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 739u) {
        l3 = l1.payload.obj;
        t0 = vader_midir_build_array_len(l0, l3);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 741u) {
        l3 = l1.payload.obj;
        t0 = vader_midir_build_array_push(l0, l3);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 742u) {
        l3 = l1.payload.obj;
        t0 = vader_midir_build_array_slice(l0, l3);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 778u) {
        l3 = l1.payload.obj;
        t0 = vader_midir_build_string_slice(l0, l3);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 752u) {
        l3 = l1.payload.obj;
        t0 = vader_midir_build_cell_new(l0, l3);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 751u) {
        l3 = l1.payload.obj;
        t0 = vader_midir_build_cell_get(l0, l3);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 771u) {
        l3 = l1.payload.obj;
        t0 = vader_midir_build_make_closure(l0, l3);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 757u) {
        l3 = l1.payload.obj;
        t0 = vader_midir_build_data_const(l0, l3);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 784u) {
        l3 = l1.payload.obj;
        t0 = vader_midir_build_type_const(l0, l3);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_unreachable("unreachable return in vader_midir$build_expr");
    vader_gc_top = gc_frame.prev;
}

static void vader_midir_build_expr_into(void* l0, vader_box_t l1, int32_t l2) {
    void* l3 = NULL;
    vader_box_t l4 = vader_box_null();
    bool l5;
    int32_t l6;
    void* t0 = NULL;
    bool t1;
    vader_box_t* gc_roots[2] = { &l1, &l4 };
    void** gc_raw_roots[3] = { &l0, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l1.tag == 765u) {
        l3 = l1.payload.obj;
        vader_midir_build_if(l0, l3, vader_box_i32(179u, l2));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 746u) {
        l3 = l1.payload.obj;
        vader_midir_build_block_into(l0, l3, l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 745u) {
        t0 = l1.payload.obj;
        t1 = vader_midir_is_short_circuit_op(((vader_struct_vader_lower_LoweredBinary_t*) t0)->f_op);
        if (t1) {
            l3 = l1.payload.obj;
            vader_midir_build_short_circuit(l0, l3, vader_box_i32(179u, l2));
            { vader_gc_top = gc_frame.prev; return; }
        }
    }
    l4 = l1;
    l4 = vader_midir_build_expr(l0, l4);
    if (!(((vader_struct_vader_midir_FnCtx_t*) l0)->f_current.tag == 0u)) {
        l5 = !(l4.tag == 0u);
    } else {
        l5 = false;
    }
    if (l5) {
        l3 = vader_lower_span_of(l1);
        l6 = ((int32_t) l4.payload.i);
        vader_struct_vader_midir_InstrMove_t* _a0_obj = (vader_struct_vader_midir_InstrMove_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrMove_t));
        vader_obj_header_init(_a0_obj, 846u);
        _a0_obj->f_span = l3;
        _a0_obj->f_dst = l2;
        _a0_obj->f_src = l6;
        l3 = (void*) _a0_obj;
        vader_midir_emit(l0, vader_ref_box(l3));
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
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
    vader_box_t t1 = vader_box_null();
    int64_t t2;
    vader_string_t t3 = 0;
    void* t4 = NULL;
    vader_box_t* gc_roots[4] = { &l7, &l9, &l27, &t1 };
    void** gc_raw_roots[11] = { &l0, &l1, &l2, &l4, &l12, &l20, &l23, &l25, &l26, &l28, &t4 };
    vader_string_t* gc_atom_roots[5] = { &l3, &l10, &l15, &l16, &t3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 11u, gc_roots, gc_raw_roots, 0u, NULL, 5u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(9u, 0u, 7u, 179u);
    l4 = (void*) _a0_arr;
    l5 = ((vader_array_t*) l1)->length;
    l6 = (size_t) (int64_t) INT64_C(0);
    {
        loop_8: {
            if ((l6 < l5)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l6 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                l7 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l6);
                t0 = std_collections_MutableSet_Contains_contains__usize(l2, l6);
                if (!(t0)) {
                    l9 = vader_midir_build_expr(l0, l7);
                    if (l9.tag == 0u) {
                        t1 = vader_box_obj(0u, NULL);
                        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
                    }
                    l8 = ((int32_t) l9.payload.i);
                    vader_array_push_i32((vader_array_t*) l4, l8);
                    t2 = (l6 + INT64_C(1));
                    l6 = (size_t) (int64_t) t2;
                    goto loop_8;
                }
                if (!(l7.tag == 764u)) {
                    l10 = l3;
                    l11 = vader_host_std_core_byte_len(l10);
                    l12 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(130) + l11));
                    l13 = (size_t) (int64_t) INT64_C(0);
                    l13 = std_core_write_string_at(l12, l13, 1934u);
                    t2 = (l6 + INT64_C(1));
                    l14 = (uint64_t) (int64_t) t2;
                    l13 = std_core_write_unsigned(l12, l13, l14);
                    l13 = std_core_write_string_at(l12, l13, 164u);
                    l13 = std_core_write_string_at(l12, l13, l10);
                    l13 = std_core_write_string_at(l12, l13, 1025u);
                    t3 = std_core_finish_buffer(l12, l13);
                    vader_host_std_abort_panic(t3);
                }
                t4 = l7.payload.obj;
                if (((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_lower_LoweredIdent_t*) t4)->f_symbol)->f_kind != INT32_C(0)) {
                    l15 = l3;
                    t4 = l7.payload.obj;
                    l16 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_lower_LoweredIdent_t*) t4)->f_symbol)->f_name;
                    l17 = vader_host_std_core_byte_len(l15);
                    l18 = vader_host_std_core_byte_len(l16);
                    t2 = (l17 + l18);
                    l19 = (size_t) (int64_t) t2;
                    l20 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(127) + l19));
                    l21 = (size_t) (int64_t) INT64_C(0);
                    l21 = std_core_write_string_at(l20, l21, 1934u);
                    t2 = (l6 + INT64_C(1));
                    l22 = (uint64_t) (int64_t) t2;
                    l21 = std_core_write_unsigned(l20, l21, l22);
                    l21 = std_core_write_string_at(l20, l21, 164u);
                    l21 = std_core_write_string_at(l20, l21, l15);
                    l21 = std_core_write_string_at(l20, l21, 1060u);
                    l21 = std_core_write_string_at(l20, l21, l16);
                    l21 = std_core_write_string_at(l20, l21, 1120u);
                    t3 = std_core_finish_buffer(l20, l21);
                    vader_host_std_abort_panic(t3);
                }
                vader_struct_vader_types_PrimitiveType_t* _a2_obj = (vader_struct_vader_types_PrimitiveType_t*) vader_gc_alloc(sizeof(vader_struct_vader_types_PrimitiveType_t));
                vader_obj_header_init(_a2_obj, 936u);
                _a2_obj->f_name = 585u;
                l23 = (void*) _a2_obj;
                l24 = vader_midir_fresh_tmp(l0, 1668u, vader_ref_box(l23));
                t4 = l7.payload.obj;
                l25 = ((vader_struct_vader_lower_LoweredIdent_t*) t4)->f_span;
                t4 = l7.payload.obj;
                l26 = ((vader_struct_vader_lower_LoweredIdent_t*) t4)->f_symbol;
                t4 = l7.payload.obj;
                l27 = ((vader_struct_vader_lower_LoweredIdent_t*) t4)->f_type;
                vader_struct_vader_midir_InstrFnAddr_t* _a3_obj = (vader_struct_vader_midir_InstrFnAddr_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrFnAddr_t));
                vader_obj_header_init(_a3_obj, 842u);
                _a3_obj->f_span = l25;
                _a3_obj->f_dst = l24;
                _a3_obj->f_fn_symbol = l26;
                _a3_obj->f_type = l27;
                l28 = (void*) _a3_obj;
                vader_midir_emit(l0, vader_ref_box(l28));
                vader_array_push_i32((vader_array_t*) l4, l24);
                t2 = (l6 + INT64_C(1));
                l6 = (size_t) (int64_t) t2;
                goto loop_8;
            }
        }
    }
    { vader_box_t __vret = vader_ref_box(l4); vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
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
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_lower_LoweredFieldAccess_t*) l1)->f_target;
    l3 = vader_midir_build_expr(l0, l3);
    if (l3.tag == 0u) {
        t0 = vader_box_obj(0u, NULL);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = ((int32_t) l3.payload.i);
    l3 = ((vader_struct_vader_lower_LoweredFieldAccess_t*) l1)->f_type;
    l4 = vader_midir_fresh_tmp(l0, 1639u, l3);
    l5 = ((vader_struct_vader_lower_LoweredFieldAccess_t*) l1)->f_span;
    l6 = ((vader_struct_vader_lower_LoweredFieldAccess_t*) l1)->f_field;
    l3 = ((vader_struct_vader_lower_LoweredFieldAccess_t*) l1)->f_type;
    vader_struct_vader_midir_InstrFieldGet_t* _a0_obj = (vader_struct_vader_midir_InstrFieldGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrFieldGet_t));
    vader_obj_header_init(_a0_obj, 840u);
    _a0_obj->f_span = l5;
    _a0_obj->f_dst = l4;
    _a0_obj->f_target = l2;
    _a0_obj->f_field = l6;
    _a0_obj->f_type = l3;
    l5 = (void*) _a0_obj;
    vader_midir_emit(l0, vader_ref_box(l5));
    t0 = vader_box_i32(179u, l4);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_box_t vader_midir_build_ident(void* l0, void* l1) {
    void* l2 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    int32_t l3, l7;
    vader_box_t l4 = vader_box_null(), l6 = vader_box_null();
    size_t l5;
    vader_string_t l11 = 0;
    int32_t t0;
    int64_t t1;
    void* t2 = NULL;
    bool t3;
    vader_box_t t4 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l4, &l6, &t4 };
    void** gc_raw_roots[7] = { &l0, &l1, &l2, &l8, &l9, &l10, &t2 };
    vader_string_t* gc_atom_roots[1] = { &l11 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_midir_FnCtx_t*) l0)->f_local_by_sym_id;
    l3 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_lower_LoweredIdent_t*) l1)->f_symbol)->f_id;
    l4 = std_collections_MutableMap_Index_at__i32__i32(l2, l3);
    if (!(l4.tag == 0u)) {
        l2 = ((vader_struct_vader_midir_FnCtx_t*) l0)->f_locals;
        t0 = ((int32_t) l4.payload.i);
        t1 = ((int64_t) (int32_t) t0);
        l5 = (size_t) (int64_t) t1;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
        if ((size_t) l5 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
        t2 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
        l6 = ((vader_struct_vader_midir_CFGLocal_t*) t2)->f_type;
        if (l6.tag == 943u) {
            l2 = l6.payload.obj;
            l6 = ((vader_struct_vader_lower_LoweredIdent_t*) l1)->f_type;
            t3 = vader_typecheck_equals_type(vader_ref_box(l2), l6);
            if (!(t3)) {
                l6 = ((vader_struct_vader_lower_LoweredIdent_t*) l1)->f_type;
                l3 = vader_midir_fresh_tmp(l0, 1969u, l6);
                l2 = ((vader_struct_vader_lower_LoweredIdent_t*) l1)->f_span;
                l7 = ((int32_t) l4.payload.i);
                l6 = ((vader_struct_vader_lower_LoweredIdent_t*) l1)->f_type;
                vader_struct_vader_midir_InstrCast_t* _a1_obj = (vader_struct_vader_midir_InstrCast_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrCast_t));
                vader_obj_header_init(_a1_obj, 832u);
                _a1_obj->f_span = l2;
                _a1_obj->f_dst = l3;
                _a1_obj->f_value = l7;
                _a1_obj->f_type = l6;
                l2 = (void*) _a1_obj;
                vader_midir_emit(l0, vader_ref_box(l2));
                t4 = vader_box_i32(179u, l3);
                { vader_box_t __vret = t4; vader_gc_top = gc_frame.prev; return __vret; }
            }
        }
        t0 = ((int32_t) l4.payload.i);
        t4 = vader_box_i32(179u, t0);
        { vader_box_t __vret = t4; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_lower_LoweredIdent_t*) l1)->f_symbol)->f_kind == INT32_C(0)) {
        l4 = ((vader_struct_vader_lower_LoweredIdent_t*) l1)->f_type;
        l3 = vader_midir_fresh_tmp(l0, 1669u, l4);
        l2 = ((vader_struct_vader_lower_LoweredIdent_t*) l1)->f_span;
        l8 = ((vader_struct_vader_lower_LoweredIdent_t*) l1)->f_symbol;
        l4 = ((vader_struct_vader_lower_LoweredIdent_t*) l1)->f_type;
        vader_struct_vader_midir_InstrFnRef_t* _a2_obj = (vader_struct_vader_midir_InstrFnRef_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrFnRef_t));
        vader_obj_header_init(_a2_obj, 843u);
        _a2_obj->f_span = l2;
        _a2_obj->f_dst = l3;
        _a2_obj->f_fn_symbol = l8;
        _a2_obj->f_type = l4;
        l2 = (void*) _a2_obj;
        vader_midir_emit(l0, vader_ref_box(l2));
        t4 = vader_box_i32(179u, l3);
        { vader_box_t __vret = t4; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = ((vader_struct_vader_midir_ProjectCtx_t*) ((vader_struct_vader_midir_FnCtx_t*) l0)->f_project)->f_const_fn_wrap;
    l3 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_lower_LoweredIdent_t*) l1)->f_symbol)->f_id;
    l4 = std_collections_MutableMap_Index_at__i32__Any(l2, l3);
    if (l4.tag == 722u) {
        t2 = l4.payload.obj;
        l6 = ((vader_struct_vader_lower_ConstFnWrap_t*) t2)->f_call_type;
        l3 = vader_midir_fresh_tmp(l0, 1483u, l6);
        vader_array_t* _a3_arr = vader_array_new(9u, 0u, 7u, 179u);
        l2 = (void*) _a3_arr;
        l8 = ((vader_struct_vader_lower_LoweredIdent_t*) l1)->f_span;
        vader_array_t* _a4_arr = vader_array_new(9u, 1u, 7u, 179u);
        ((int32_t*) _a4_arr->buf->slots)[_a4_arr->offset + 0u] = (int32_t) l3;
        l9 = (void*) _a4_arr;
        t2 = l4.payload.obj;
        l10 = ((vader_struct_vader_lower_ConstFnWrap_t*) t2)->f_fn_symbol;
        t2 = l4.payload.obj;
        l4 = ((vader_struct_vader_lower_ConstFnWrap_t*) t2)->f_call_type;
        vader_struct_vader_midir_InstrCall_t* _a5_obj = (vader_struct_vader_midir_InstrCall_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrCall_t));
        vader_obj_header_init(_a5_obj, 830u);
        _a5_obj->f_span = l8;
        _a5_obj->f_dsts = l9;
        _a5_obj->f_callee = l10;
        _a5_obj->f_args = l2;
        _a5_obj->f_type = l4;
        l2 = (void*) _a5_obj;
        vader_midir_emit(l0, vader_ref_box(l2));
        t4 = vader_box_i32(179u, l3);
        { vader_box_t __vret = t4; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = ((vader_struct_vader_midir_ProjectCtx_t*) ((vader_struct_vader_midir_FnCtx_t*) l0)->f_project)->f_const_inline;
    l3 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_lower_LoweredIdent_t*) l1)->f_symbol)->f_id;
    l4 = std_collections_MutableMap_Index_at__i32__Any(l2, l3);
    if (!(l4.tag == 0u)) {
        t4 = vader_midir_build_expr(l0, l4);
        { vader_box_t __vret = t4; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = ((vader_struct_vader_midir_ProjectCtx_t*) ((vader_struct_vader_midir_FnCtx_t*) l0)->f_project)->f_diags;
    l8 = ((vader_struct_vader_lower_LoweredIdent_t*) l1)->f_span;
    l11 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_lower_LoweredIdent_t*) l1)->f_symbol)->f_name;
    l11 = concat_3(975u, l11, 1074u);
    l8 = vader_diagnostics_lower_error((uint8_t) (int32_t) INT32_C(6), l8, l11);
    vader_array_push((vader_array_t*) l2, vader_ref_box(l8));
    l4 = ((vader_struct_vader_lower_LoweredIdent_t*) l1)->f_type;
    l2 = ((vader_struct_vader_lower_LoweredIdent_t*) l1)->f_span;
    l11 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_lower_LoweredIdent_t*) l1)->f_symbol)->f_name;
    l11 = concat_2(2371u, l11);
    t4 = vader_midir_build_unreachable_type(l0, l4, l2, l11, false);
    { vader_box_t __vret = t4; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_box_t vader_midir_build_if(void* l0, void* l1, vader_box_t l2) {
    int32_t l3, l7, l8, l9;
    vader_box_t l4 = vader_box_null(), l5 = vader_box_null();
    void* l6 = NULL;
    vader_box_t t0 = vader_box_null();
    int32_t t1;
    bool t2;
    vader_box_t* gc_roots[4] = { &l2, &l4, &l5, &t0 };
    void** gc_raw_roots[3] = { &l0, &l1, &l6 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l4 = ((vader_struct_vader_lower_LoweredIf_t*) l1)->f_cond;
    l4 = vader_midir_build_expr(l0, l4);
    if (l4.tag == 0u) {
        t0 = vader_box_obj(0u, NULL);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = ((int32_t) l4.payload.i);
    if (!(l2.tag == 0u)) {
        t1 = ((int32_t) l2.payload.i);
        l4 = vader_box_i32(179u, t1);
    } else {
        t2 = vader_typecheck_is_void(((vader_struct_vader_lower_LoweredIf_t*) l1)->f_type);
        if (t2) {
            l4 = vader_box_obj(0u, NULL);
        } else {
            l5 = ((vader_struct_vader_lower_LoweredIf_t*) l1)->f_type;
            t1 = vader_midir_declare_local(l0, 1773u, l5, vader_box_obj(0u, NULL));
            l4 = vader_box_i32(179u, t1);
        }
    }
    l6 = ((vader_struct_vader_lower_LoweredBlock_t*) ((vader_struct_vader_lower_LoweredIf_t*) l1)->f_then_block)->f_span;
    l7 = vader_midir_new_block(l0, l6);
    if (((vader_struct_vader_lower_LoweredIf_t*) l1)->f_else_block.tag == 0u) {
        l5 = vader_box_obj(0u, NULL);
    } else {
        l6 = ((vader_struct_vader_lower_LoweredBlock_t*) ((vader_struct_vader_lower_LoweredIf_t*) l1)->f_else_block.payload.obj)->f_span;
        t1 = vader_midir_new_block(l0, l6);
        l5 = vader_box_i32(179u, t1);
    }
    l6 = ((vader_struct_vader_lower_LoweredIf_t*) l1)->f_span;
    l8 = vader_midir_new_block(l0, l6);
    if (l5.tag == 0u) {
        l9 = l8;
    } else {
        l9 = ((int32_t) l5.payload.i);
    }
    vader_struct_vader_midir_TermCondBranch_t* _a0_obj = (vader_struct_vader_midir_TermCondBranch_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_TermCondBranch_t));
    vader_obj_header_init(_a0_obj, 861u);
    _a0_obj->f_span = ((vader_struct_vader_lower_LoweredIf_t*) l1)->f_span;
    _a0_obj->f_cond = l3;
    _a0_obj->f_then_block = l7;
    _a0_obj->f_else_block = l9;
    _a0_obj->f_join = l8;
    l6 = (void*) _a0_obj;
    vader_midir_terminate(l0, vader_ref_box(l6));
    ((vader_struct_vader_midir_FnCtx_t*) l0)->f_current = vader_box_i32(179u, l7);
    VADER_WRITE_BARRIER((vader_struct_vader_midir_FnCtx_t*) l0);
    l6 = ((vader_struct_vader_lower_LoweredIf_t*) l1)->f_then_block;
    vader_midir_build_if_arm(l0, l6, l4);
    if (!(((vader_struct_vader_midir_FnCtx_t*) l0)->f_current.tag == 0u)) {
        vader_struct_vader_midir_TermBranch_t* _a1_obj = (vader_struct_vader_midir_TermBranch_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_TermBranch_t));
        vader_obj_header_init(_a1_obj, 860u);
        _a1_obj->f_span = ((vader_struct_vader_lower_LoweredBlock_t*) ((vader_struct_vader_lower_LoweredIf_t*) l1)->f_then_block)->f_span;
        _a1_obj->f_target = l8;
        l6 = (void*) _a1_obj;
        vader_midir_terminate(l0, vader_ref_box(l6));
    }
    if (!(l5.tag == 0u)) {
        if (!(((vader_struct_vader_lower_LoweredIf_t*) l1)->f_else_block.tag == 0u)) {
            l3 = ((int32_t) l5.payload.i);
            ((vader_struct_vader_midir_FnCtx_t*) l0)->f_current = vader_box_i32(179u, l3);
            VADER_WRITE_BARRIER((vader_struct_vader_midir_FnCtx_t*) l0);
            t0 = ((vader_struct_vader_lower_LoweredIf_t*) l1)->f_else_block;
            l6 = t0.payload.obj;
            vader_midir_build_if_arm(l0, l6, l4);
            if (!(((vader_struct_vader_midir_FnCtx_t*) l0)->f_current.tag == 0u)) {
                vader_struct_vader_midir_TermBranch_t* _a2_obj = (vader_struct_vader_midir_TermBranch_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_TermBranch_t));
                vader_obj_header_init(_a2_obj, 860u);
                _a2_obj->f_span = ((vader_struct_vader_lower_LoweredBlock_t*) ((vader_struct_vader_lower_LoweredIf_t*) l1)->f_else_block.payload.obj)->f_span;
                _a2_obj->f_target = l8;
                l6 = (void*) _a2_obj;
                vader_midir_terminate(l0, vader_ref_box(l6));
            }
        }
    }
    ((vader_struct_vader_midir_FnCtx_t*) l0)->f_current = vader_box_i32(179u, l8);
    VADER_WRITE_BARRIER((vader_struct_vader_midir_FnCtx_t*) l0);
    { vader_box_t __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void vader_midir_build_if_arm(void* l0, void* l1, vader_box_t l2) {
    int32_t l3;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (!(l2.tag == 0u)) {
        l3 = ((int32_t) l2.payload.i);
        vader_midir_build_block_into(l0, l1, l3);
    } else {
        vader_midir_build_block_body(l0, l1);
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_midir_build_impl_table_from_vtable(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l14 = NULL;
    void* l20 = NULL;
    void* l27 = NULL;
    size_t l7, l8, l12, l13, l15, l18, l19, l21, l24, l28;
    vader_string_t l9 = 0;
    vader_string_t l16 = 0;
    vader_string_t l17 = 0;
    vader_string_t l23 = 0;
    vader_string_t l26 = 0;
    vader_box_t l10 = vader_box_null();
    int32_t l11;
    int64_t l22;
    bool l25;
    uint64_t l29;
    int64_t t0;
    vader_box_t t1 = vader_box_null();
    void* t2 = NULL;
    vader_box_t* gc_roots[2] = { &l10, &t1 };
    void** gc_raw_roots[11] = { &l0, &l1, &l2, &l3, &l4, &l5, &l6, &l14, &l20, &l27, &t2 };
    vader_string_t* gc_atom_roots[5] = { &l9, &l16, &l17, &l23, &l26 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 11u, gc_roots, gc_raw_roots, 0u, NULL, 5u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(41u, 0u, 13u, 610u);
    l3 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(8u, 0u, 0u, 176u);
    l4 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(6u, 0u, 12u, 174u);
    l5 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(9u, 0u, 7u, 179u);
    l6 = (void*) _a3_arr;
    vader_struct_std_collections_MutableMap__string__bool_t* _a4_obj = (vader_struct_std_collections_MutableMap__string__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__bool_t));
    vader_obj_header_init(_a4_obj, 364u);
    _a4_obj->f_ekeys = l4;
    _a4_obj->f_evals = l5;
    _a4_obj->f_index = l6;
    _a4_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a4_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a4_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l4 = (void*) _a4_obj;
    l5 = l0;
    l7 = ((vader_array_t*) l5)->length;
    l8 = (size_t) (int64_t) INT64_C(0);
    {
        loop_23: {
            if ((l8 < l7)) {
                vader_array_t* _a5_slotarr = ((vader_array_t*) l5);
                if (_a5_slotarr->buf != NULL && _a5_slotarr->buf->header.forward != NULL) { _a5_slotarr->buf = vader_array_buf_forward(_a5_slotarr->buf); }
                if ((size_t) l8 >= _a5_slotarr->length) { vader_trap("array index out of bounds"); }
                l6 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l8);
                l9 = vader_bytecode_type_intern_key(((vader_struct_vader_lower_LoweredVtableEntry_t*) l6)->f_struct_type);
                l10 = std_collections_MutableMap_Index_at__string__i32(((vader_struct_vader_bytecode_EmitterCtx_t*) l2)->f_type_key, l9);
                if (!(l10.tag == 179u)) {
                    t0 = (l8 + INT64_C(1));
                    l8 = (size_t) (int64_t) t0;
                    goto loop_23;
                }
                l11 = ((int32_t) l10.payload.i);
                t0 = ((int64_t) (int32_t) l11);
                l12 = (size_t) (int64_t) t0;
                l13 = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l2)->f_types)->length;
                if ((l12 < l13)) {
                    l14 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l2)->f_types;
                    t0 = ((int64_t) (int32_t) l11);
                    l15 = (size_t) (int64_t) t0;
                    vader_array_t* _a6_slotarr = ((vader_array_t*) l14);
                    if (_a6_slotarr->buf != NULL && _a6_slotarr->buf->header.forward != NULL) { _a6_slotarr->buf = vader_array_buf_forward(_a6_slotarr->buf); }
                    if ((size_t) l15 >= _a6_slotarr->length) { vader_trap("array index out of bounds"); }
                    t1 = vader_array_ref_load_box(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l15);
                    if (!(t1.tag == 516u)) {
                        t0 = (l8 + INT64_C(1));
                        l8 = (size_t) (int64_t) t0;
                        goto loop_23;
                    }
                    l17 = ((vader_struct_vader_lower_LoweredVtableEntry_t*) l6)->f_trait_name;
                    l18 = (size_t) (int64_t) INT64_C(21);
                    l19 = vader_host_std_core_byte_len(l17);
                    l20 = std_core_new_byte_buffer((size_t) (int64_t) (l18 + l19));
                    l21 = (size_t) (int64_t) INT64_C(0);
                    l22 = ((int64_t) (int32_t) l11);
                    l21 = std_core_write_int(l20, l21, l22);
                    l23 = 2521u;
                    l21 = std_core_write_string_at(l20, l21, l23);
                    l21 = std_core_write_string_at(l20, l21, l17);
                    l16 = std_core_finish_buffer(l20, l21);
                    t1 = std_collections_MutableMap_Index_at__string__bool(l4, l16);
                    if (t1.tag == 174u) {
                        l24 = (size_t) (int64_t) INT64_C(1);
                        t0 = (l8 + l24);
                        l8 = (size_t) (int64_t) t0;
                        goto loop_23;
                    }
                    l25 = true;
                    std_collections_MutableMap_IndexSet_set_at__string__bool(l4, l16, l25);
                    l26 = ((vader_struct_vader_lower_LoweredVtableEntry_t*) l6)->f_trait_name;
                    vader_struct_vader_bytecode_ImplEntry_t* _a7_obj = (vader_struct_vader_bytecode_ImplEntry_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_ImplEntry_t));
                    vader_obj_header_init(_a7_obj, 610u);
                    _a7_obj->f_struct_type_index = l11;
                    _a7_obj->f_trait_name = l26;
                    l27 = (void*) _a7_obj;
                    vader_array_push((vader_array_t*) l3, vader_ref_box(l27));
                    l28 = (size_t) (int64_t) INT64_C(1);
                    t0 = (l8 + l28);
                    l8 = (size_t) (int64_t) t0;
                    goto loop_23;
                }
                l17 = ((vader_struct_vader_lower_LoweredVtableEntry_t*) l6)->f_trait_name;
                l18 = (size_t) (int64_t) INT64_C(21);
                l19 = vader_host_std_core_byte_len(l17);
                l20 = std_core_new_byte_buffer((size_t) (int64_t) (l18 + l19));
                l21 = (size_t) (int64_t) INT64_C(0);
                l22 = ((int64_t) (int32_t) l11);
                l21 = std_core_write_int(l20, l21, l22);
                l23 = 2521u;
                l21 = std_core_write_string_at(l20, l21, l23);
                l21 = std_core_write_string_at(l20, l21, l17);
                l16 = std_core_finish_buffer(l20, l21);
                t1 = std_collections_MutableMap_Index_at__string__bool(l4, l16);
                if (t1.tag == 174u) {
                    l24 = (size_t) (int64_t) INT64_C(1);
                    t0 = (l8 + l24);
                    l8 = (size_t) (int64_t) t0;
                    goto loop_23;
                }
                l25 = true;
                std_collections_MutableMap_IndexSet_set_at__string__bool(l4, l16, l25);
                l26 = ((vader_struct_vader_lower_LoweredVtableEntry_t*) l6)->f_trait_name;
                vader_struct_vader_bytecode_ImplEntry_t* _a8_obj = (vader_struct_vader_bytecode_ImplEntry_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_ImplEntry_t));
                vader_obj_header_init(_a8_obj, 610u);
                _a8_obj->f_struct_type_index = l11;
                _a8_obj->f_trait_name = l26;
                l27 = (void*) _a8_obj;
                vader_array_push((vader_array_t*) l3, vader_ref_box(l27));
                l28 = (size_t) (int64_t) INT64_C(1);
                t0 = (l8 + l28);
                l8 = (size_t) (int64_t) t0;
                goto loop_23;
            }
        }
    }
    l7 = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l2)->f_types)->length;
    l8 = (size_t) (int64_t) INT64_C(0);
    {
        loop_237: {
            if ((l8 < l7)) {
                vader_array_t* _a9_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l2)->f_types);
                if (_a9_slotarr->buf != NULL && _a9_slotarr->buf->header.forward != NULL) { _a9_slotarr->buf = vader_array_buf_forward(_a9_slotarr->buf); }
                if ((size_t) l8 >= _a9_slotarr->length) { vader_trap("array index out of bounds"); }
                t1 = vader_array_ref_load_box(_a9_slotarr->buf, _a9_slotarr->offset + (size_t) l8);
                if (t1.tag == 516u) {
                    vader_array_t* _a10_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l2)->f_types);
                    if (_a10_slotarr->buf != NULL && _a10_slotarr->buf->header.forward != NULL) { _a10_slotarr->buf = vader_array_buf_forward(_a10_slotarr->buf); }
                    if ((size_t) l8 >= _a10_slotarr->length) { vader_trap("array index out of bounds"); }
                    t1 = vader_array_ref_load_box(_a10_slotarr->buf, _a10_slotarr->offset + (size_t) l8);
                    t2 = t1.payload.obj;
                    l11 = ((vader_struct_vader_bytecode_BcStruct_t*) t2)->f_symbol_id;
                    l10 = std_collections_MutableMap_Index_at__i32__Any(l1, l11);
                    if (l10.tag == 0u) {
                        t0 = (l8 + INT64_C(1));
                        l8 = (size_t) (int64_t) t0;
                        goto loop_237;
                    }
                    l5 = l10.payload.obj;
                    l12 = ((vader_array_t*) l5)->length;
                    l13 = (size_t) (int64_t) INT64_C(0);
                    {
                        loop_274: {
                            if ((l13 < l12)) {
                                vader_array_t* _a11_slotarr = ((vader_array_t*) l5);
                                if (_a11_slotarr->buf != NULL && _a11_slotarr->buf->header.forward != NULL) { _a11_slotarr->buf = vader_array_buf_forward(_a11_slotarr->buf); }
                                if ((size_t) l13 >= _a11_slotarr->length) { vader_trap("array index out of bounds"); }
                                t1 = vader_array_box_slots(_a11_slotarr->buf)[_a11_slotarr->offset + (size_t) l13];
                                l9 = t1.payload.s;
                                l17 = l9;
                                l15 = vader_host_std_core_byte_len(l17);
                                l6 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(21) + l15));
                                l18 = (size_t) (int64_t) INT64_C(0);
                                t0 = ((int64_t) (size_t) l8);
                                l29 = (uint64_t) (int64_t) t0;
                                l18 = std_core_write_unsigned(l6, l18, l29);
                                l18 = std_core_write_string_at(l6, l18, 2521u);
                                l18 = std_core_write_string_at(l6, l18, l17);
                                l16 = std_core_finish_buffer(l6, l18);
                                t1 = std_collections_MutableMap_Index_at__string__bool(l4, l16);
                                if (t1.tag == 174u) {
                                    t0 = (l13 + INT64_C(1));
                                    l13 = (size_t) (int64_t) t0;
                                    goto loop_274;
                                }
                                std_collections_MutableMap_IndexSet_set_at__string__bool(l4, l16, true);
                                vader_struct_vader_bytecode_ImplEntry_t* _a12_obj = (vader_struct_vader_bytecode_ImplEntry_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_ImplEntry_t));
                                vader_obj_header_init(_a12_obj, 610u);
                                _a12_obj->f_struct_type_index = ((int32_t) (size_t) l8);
                                _a12_obj->f_trait_name = l9;
                                l14 = (void*) _a12_obj;
                                vader_array_push((vader_array_t*) l3, vader_ref_box(l14));
                                t0 = (l13 + INT64_C(1));
                                l13 = (size_t) (int64_t) t0;
                                goto loop_274;
                            }
                        }
                    }
                    l19 = (size_t) (int64_t) INT64_C(1);
                    t0 = (l8 + l19);
                    l8 = (size_t) (int64_t) t0;
                    goto loop_237;
                }
                l19 = (size_t) (int64_t) INT64_C(1);
                t0 = (l8 + l19);
                l8 = (size_t) (int64_t) t0;
                goto loop_237;
            }
        }
    }
    { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
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
        t0 = vader_box_obj(0u, NULL);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l3.tag == 0u) {
        t0 = vader_box_obj(0u, NULL);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = ((vader_struct_vader_lower_LoweredIndex_t*) l1)->f_type;
    l5 = vader_midir_fresh_tmp(l0, 1763u, l4);
    l6 = ((vader_struct_vader_lower_LoweredIndex_t*) l1)->f_span;
    l7 = ((int32_t) l2.payload.i);
    l8 = ((int32_t) l3.payload.i);
    l2 = ((vader_struct_vader_lower_LoweredIndex_t*) l1)->f_type;
    l9 = ((vader_struct_vader_lower_LoweredIndex_t*) l1)->f_bounds_safe;
    vader_struct_vader_midir_InstrArrayGet_t* _a0_obj = (vader_struct_vader_midir_InstrArrayGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrArrayGet_t));
    vader_obj_header_init(_a0_obj, 823u);
    _a0_obj->f_span = l6;
    _a0_obj->f_dst = l5;
    _a0_obj->f_target = l7;
    _a0_obj->f_index = l8;
    _a0_obj->f_type = l2;
    _a0_obj->f_bounds_safe = l9;
    l6 = (void*) _a0_obj;
    vader_midir_emit(l0, vader_ref_box(l6));
    t0 = vader_box_i32(179u, l5);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_box_t vader_midir_build_intrinsic_call(void* l0, void* l1) {
    void* l2 = NULL;
    void* l5 = NULL;
    vader_box_t l3 = vader_box_null(), l4 = vader_box_null();
    vader_string_t l6 = 0;
    vader_box_t t0 = vader_box_null();
    bool t1;
    int32_t t2;
    vader_box_t* gc_roots[3] = { &l3, &l4, &t0 };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &l5 };
    vader_string_t* gc_atom_roots[1] = { &l6 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_lower_LoweredIntrinsicCall_t*) l1)->f_args;
    l3 = vader_midir_build_args(l0, l2);
    if (l3.tag == 0u) {
        t0 = vader_box_obj(0u, NULL);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = l3.payload.obj;
    t1 = vader_typecheck_is_void(((vader_struct_vader_lower_LoweredIntrinsicCall_t*) l1)->f_type);
    if (t1) {
        l3 = vader_box_obj(0u, NULL);
    } else {
        l4 = ((vader_struct_vader_lower_LoweredIntrinsicCall_t*) l1)->f_type;
        t2 = vader_midir_fresh_tmp(l0, 1817u, l4);
        l3 = vader_box_i32(179u, t2);
    }
    l5 = ((vader_struct_vader_lower_LoweredIntrinsicCall_t*) l1)->f_span;
    l6 = ((vader_struct_vader_lower_LoweredIntrinsicCall_t*) l1)->f_name;
    vader_struct_vader_midir_InstrIntrinsic_t* _a0_obj = (vader_struct_vader_midir_InstrIntrinsic_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrIntrinsic_t));
    vader_obj_header_init(_a0_obj, 844u);
    _a0_obj->f_span = l5;
    _a0_obj->f_dst = l3;
    _a0_obj->f_name = l6;
    _a0_obj->f_args = l2;
    l2 = (void*) _a0_obj;
    vader_midir_emit(l0, vader_ref_box(l2));
    { vader_box_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void vader_midir_build_loop(void* l0, void* l1) {
    void* l2 = NULL;
    void* l9 = NULL;
    int32_t l3, l4, l5, l7, l8;
    vader_box_t l6 = vader_box_null();
    size_t l10, l11;
    size_t t0;
    int64_t t1;
    vader_box_t* gc_roots[1] = { &l6 };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &l9 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_lower_LoweredLoop_t*) l1)->f_span;
    l3 = vader_midir_new_block(l0, l2);
    l2 = ((vader_struct_vader_lower_LoweredBlock_t*) ((vader_struct_vader_lower_LoweredLoop_t*) l1)->f_body)->f_span;
    l4 = vader_midir_new_block(l0, l2);
    l2 = ((vader_struct_vader_lower_LoweredLoop_t*) l1)->f_span;
    l5 = vader_midir_new_block(l0, l2);
    if (!(((vader_struct_vader_midir_FnCtx_t*) l0)->f_current.tag == 0u)) {
        vader_struct_vader_midir_TermBranch_t* _a0_obj = (vader_struct_vader_midir_TermBranch_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_TermBranch_t));
        vader_obj_header_init(_a0_obj, 860u);
        _a0_obj->f_span = ((vader_struct_vader_lower_LoweredLoop_t*) l1)->f_span;
        _a0_obj->f_target = l3;
        l2 = (void*) _a0_obj;
        vader_midir_terminate(l0, vader_ref_box(l2));
    }
    ((vader_struct_vader_midir_FnCtx_t*) l0)->f_current = vader_box_i32(179u, l3);
    VADER_WRITE_BARRIER((vader_struct_vader_midir_FnCtx_t*) l0);
    if (!(((vader_struct_vader_lower_LoweredLoop_t*) l1)->f_cond.tag == 0u)) {
        l6 = ((vader_struct_vader_lower_LoweredLoop_t*) l1)->f_cond;
        l6 = vader_midir_build_expr(l0, l6);
        if (!(l6.tag == 0u)) {
            l2 = vader_lower_span_of(((vader_struct_vader_lower_LoweredLoop_t*) l1)->f_cond);
            l7 = ((int32_t) l6.payload.i);
            l8 = -(INT32_C(1));
            vader_struct_vader_midir_TermCondBranch_t* _a1_obj = (vader_struct_vader_midir_TermCondBranch_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_TermCondBranch_t));
            vader_obj_header_init(_a1_obj, 861u);
            _a1_obj->f_span = l2;
            _a1_obj->f_cond = l7;
            _a1_obj->f_then_block = l4;
            _a1_obj->f_else_block = l5;
            _a1_obj->f_join = l8;
            l2 = (void*) _a1_obj;
            vader_midir_terminate(l0, vader_ref_box(l2));
        } else {
            vader_struct_vader_midir_TermBranch_t* _a2_obj = (vader_struct_vader_midir_TermBranch_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_TermBranch_t));
            vader_obj_header_init(_a2_obj, 860u);
            _a2_obj->f_span = ((vader_struct_vader_lower_LoweredLoop_t*) l1)->f_span;
            _a2_obj->f_target = l5;
            l2 = (void*) _a2_obj;
            vader_midir_terminate(l0, vader_ref_box(l2));
        }
    } else {
        vader_struct_vader_midir_TermBranch_t* _a3_obj = (vader_struct_vader_midir_TermBranch_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_TermBranch_t));
        vader_obj_header_init(_a3_obj, 860u);
        _a3_obj->f_span = ((vader_struct_vader_lower_LoweredLoop_t*) l1)->f_span;
        _a3_obj->f_target = l4;
        l2 = (void*) _a3_obj;
        vader_midir_terminate(l0, vader_ref_box(l2));
    }
    l2 = ((vader_struct_vader_midir_FnCtx_t*) l0)->f_loop_stack;
    vader_struct_vader_midir_LoopFrame_t* _a4_obj = (vader_struct_vader_midir_LoopFrame_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_LoopFrame_t));
    vader_obj_header_init(_a4_obj, 854u);
    _a4_obj->f_label = ((vader_struct_vader_lower_LoweredLoop_t*) l1)->f_label;
    _a4_obj->f_header_id = l3;
    _a4_obj->f_exit_id = l5;
    l9 = (void*) _a4_obj;
    vader_array_push((vader_array_t*) l2, vader_ref_box(l9));
    ((vader_struct_vader_midir_FnCtx_t*) l0)->f_current = vader_box_i32(179u, l4);
    VADER_WRITE_BARRIER((vader_struct_vader_midir_FnCtx_t*) l0);
    l2 = ((vader_struct_vader_lower_LoweredLoop_t*) l1)->f_body;
    vader_midir_build_block_body(l0, l2);
    if (!(((vader_struct_vader_midir_FnCtx_t*) l0)->f_current.tag == 0u)) {
        vader_struct_vader_midir_TermBranch_t* _a5_obj = (vader_struct_vader_midir_TermBranch_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_TermBranch_t));
        vader_obj_header_init(_a5_obj, 860u);
        _a5_obj->f_span = ((vader_struct_vader_lower_LoweredLoop_t*) l1)->f_span;
        _a5_obj->f_target = l3;
        l2 = (void*) _a5_obj;
        vader_midir_terminate(l0, vader_ref_box(l2));
    }
    vader_array_t* _a6_arr = vader_array_new(83u, 0u, 13u, 854u);
    l2 = (void*) _a6_arr;
    t0 = ((vader_array_t*) ((vader_struct_vader_midir_FnCtx_t*) l0)->f_loop_stack)->length;
    t1 = (t0 - INT64_C(1));
    l10 = (size_t) (int64_t) t1;
    l11 = (size_t) (int64_t) INT64_C(0);
    {
        loop_125: {
            if ((l11 < l10)) {
                vader_array_t* _a7_slotarr = ((vader_array_t*) ((vader_struct_vader_midir_FnCtx_t*) l0)->f_loop_stack);
                if (_a7_slotarr->buf != NULL && _a7_slotarr->buf->header.forward != NULL) { _a7_slotarr->buf = vader_array_buf_forward(_a7_slotarr->buf); }
                if ((size_t) l11 >= _a7_slotarr->length) { vader_trap("array index out of bounds"); }
                l9 = vader_array_ref_load_obj(_a7_slotarr->buf, _a7_slotarr->offset + (size_t) l11);
                vader_array_push((vader_array_t*) l2, vader_ref_box(l9));
                t1 = (l11 + INT64_C(1));
                l11 = (size_t) (int64_t) t1;
                goto loop_125;
            }
        }
    }
    ((vader_struct_vader_midir_FnCtx_t*) l0)->f_loop_stack = l2;
    VADER_WRITE_BARRIER((vader_struct_vader_midir_FnCtx_t*) l0);
    ((vader_struct_vader_midir_FnCtx_t*) l0)->f_current = vader_box_i32(179u, l5);
    VADER_WRITE_BARRIER((vader_struct_vader_midir_FnCtx_t*) l0);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
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
        t0 = vader_box_obj(0u, NULL);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = ((int32_t) l3.payload.i);
    l3 = ((vader_struct_vader_lower_LoweredMakeClosure_t*) l1)->f_type;
    l4 = vader_midir_fresh_tmp(l0, 1436u, l3);
    l5 = ((vader_struct_vader_lower_LoweredMakeClosure_t*) l1)->f_span;
    l6 = ((vader_struct_vader_lower_LoweredMakeClosure_t*) l1)->f_fn_symbol;
    l3 = vader_lower_type_of(((vader_struct_vader_lower_LoweredMakeClosure_t*) l1)->f_env);
    l7 = ((vader_struct_vader_lower_LoweredMakeClosure_t*) l1)->f_type;
    vader_struct_vader_midir_InstrMakeClosure_t* _a0_obj = (vader_struct_vader_midir_InstrMakeClosure_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrMakeClosure_t));
    vader_obj_header_init(_a0_obj, 845u);
    _a0_obj->f_span = l5;
    _a0_obj->f_dst = l4;
    _a0_obj->f_fn_symbol = l6;
    _a0_obj->f_env = l2;
    _a0_obj->f_env_type = l3;
    _a0_obj->f_type = l7;
    l5 = (void*) _a0_obj;
    vader_midir_emit(l0, vader_ref_box(l5));
    t0 = vader_box_i32(179u, l4);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
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
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l4 = ((vader_struct_vader_lower_LoweredBinary_t*) l1)->f_left;
    l4 = vader_midir_build_expr(l0, l4);
    if (l4.tag == 0u) {
        t0 = vader_box_obj(0u, NULL);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = ((int32_t) l4.payload.i);
    l5 = ((vader_struct_vader_lower_LoweredBinary_t*) l1)->f_op == INT32_C(10);
    if (!(l2.tag == 0u)) {
        l6 = ((int32_t) l2.payload.i);
    } else {
        if (l5) {
            l7 = 1249u;
        } else {
            l7 = 2009u;
        }
        l4 = ((vader_struct_vader_lower_LoweredBinary_t*) l1)->f_type;
        l6 = vader_midir_declare_local(l0, l7, l4, vader_box_obj(0u, NULL));
    }
    l8 = vader_lower_span_of(((vader_struct_vader_lower_LoweredBinary_t*) l1)->f_right);
    l9 = vader_midir_new_block(l0, l8);
    l8 = vader_lower_span_of(((vader_struct_vader_lower_LoweredBinary_t*) l1)->f_right);
    l10 = vader_midir_new_block(l0, l8);
    l8 = ((vader_struct_vader_lower_LoweredBinary_t*) l1)->f_span;
    l11 = vader_midir_new_block(l0, l8);
    vader_struct_vader_midir_TermCondBranch_t* _a0_obj = (vader_struct_vader_midir_TermCondBranch_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_TermCondBranch_t));
    vader_obj_header_init(_a0_obj, 861u);
    _a0_obj->f_span = ((vader_struct_vader_lower_LoweredBinary_t*) l1)->f_span;
    _a0_obj->f_cond = l3;
    _a0_obj->f_then_block = l9;
    _a0_obj->f_else_block = l10;
    _a0_obj->f_join = l11;
    l8 = (void*) _a0_obj;
    vader_midir_terminate(l0, vader_ref_box(l8));
    ((vader_struct_vader_midir_FnCtx_t*) l0)->f_current = vader_box_i32(179u, l9);
    VADER_WRITE_BARRIER((vader_struct_vader_midir_FnCtx_t*) l0);
    if (l5) {
        l4 = ((vader_struct_vader_lower_LoweredBinary_t*) l1)->f_right;
        l4 = vader_midir_build_expr(l0, l4);
        if (!(l4.tag == 0u)) {
            if (!(((vader_struct_vader_midir_FnCtx_t*) l0)->f_current.tag == 0u)) {
                l8 = vader_lower_span_of(((vader_struct_vader_lower_LoweredBinary_t*) l1)->f_right);
                l3 = ((int32_t) l4.payload.i);
                vader_struct_vader_midir_InstrMove_t* _a1_obj = (vader_struct_vader_midir_InstrMove_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrMove_t));
                vader_obj_header_init(_a1_obj, 846u);
                _a1_obj->f_span = l8;
                _a1_obj->f_dst = l6;
                _a1_obj->f_src = l3;
                l8 = (void*) _a1_obj;
                vader_midir_emit(l0, vader_ref_box(l8));
            }
        }
    } else {
        l4 = ((vader_struct_vader_lower_LoweredBinary_t*) l1)->f_type;
        l3 = vader_midir_fresh_tmp(l0, 1846u, l4);
        l8 = ((vader_struct_vader_lower_LoweredBinary_t*) l1)->f_span;
        vader_struct_vader_midir_ConstBool_t* _a2_obj = (vader_struct_vader_midir_ConstBool_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_ConstBool_t));
        vader_obj_header_init(_a2_obj, 811u);
        _a2_obj->f_value = true;
        l12 = (void*) _a2_obj;
        l4 = ((vader_struct_vader_lower_LoweredBinary_t*) l1)->f_type;
        vader_struct_vader_midir_InstrConst_t* _a3_obj = (vader_struct_vader_midir_InstrConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrConst_t));
        vader_obj_header_init(_a3_obj, 836u);
        _a3_obj->f_span = l8;
        _a3_obj->f_dst = l3;
        _a3_obj->f_value = vader_ref_box(l12);
        _a3_obj->f_type = l4;
        l8 = (void*) _a3_obj;
        vader_midir_emit(l0, vader_ref_box(l8));
        vader_struct_vader_midir_InstrMove_t* _a4_obj = (vader_struct_vader_midir_InstrMove_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrMove_t));
        vader_obj_header_init(_a4_obj, 846u);
        _a4_obj->f_span = ((vader_struct_vader_lower_LoweredBinary_t*) l1)->f_span;
        _a4_obj->f_dst = l6;
        _a4_obj->f_src = l3;
        l8 = (void*) _a4_obj;
        vader_midir_emit(l0, vader_ref_box(l8));
    }
    if (!(((vader_struct_vader_midir_FnCtx_t*) l0)->f_current.tag == 0u)) {
        vader_struct_vader_midir_TermBranch_t* _a5_obj = (vader_struct_vader_midir_TermBranch_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_TermBranch_t));
        vader_obj_header_init(_a5_obj, 860u);
        _a5_obj->f_span = ((vader_struct_vader_lower_LoweredBinary_t*) l1)->f_span;
        _a5_obj->f_target = l11;
        l8 = (void*) _a5_obj;
        vader_midir_terminate(l0, vader_ref_box(l8));
    }
    ((vader_struct_vader_midir_FnCtx_t*) l0)->f_current = vader_box_i32(179u, l10);
    VADER_WRITE_BARRIER((vader_struct_vader_midir_FnCtx_t*) l0);
    if (l5) {
        l4 = ((vader_struct_vader_lower_LoweredBinary_t*) l1)->f_type;
        l3 = vader_midir_fresh_tmp(l0, 1846u, l4);
        l8 = ((vader_struct_vader_lower_LoweredBinary_t*) l1)->f_span;
        vader_struct_vader_midir_ConstBool_t* _a6_obj = (vader_struct_vader_midir_ConstBool_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_ConstBool_t));
        vader_obj_header_init(_a6_obj, 811u);
        _a6_obj->f_value = false;
        l12 = (void*) _a6_obj;
        l4 = ((vader_struct_vader_lower_LoweredBinary_t*) l1)->f_type;
        vader_struct_vader_midir_InstrConst_t* _a7_obj = (vader_struct_vader_midir_InstrConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrConst_t));
        vader_obj_header_init(_a7_obj, 836u);
        _a7_obj->f_span = l8;
        _a7_obj->f_dst = l3;
        _a7_obj->f_value = vader_ref_box(l12);
        _a7_obj->f_type = l4;
        l8 = (void*) _a7_obj;
        vader_midir_emit(l0, vader_ref_box(l8));
        vader_struct_vader_midir_InstrMove_t* _a8_obj = (vader_struct_vader_midir_InstrMove_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrMove_t));
        vader_obj_header_init(_a8_obj, 846u);
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
                vader_obj_header_init(_a9_obj, 846u);
                _a9_obj->f_span = l8;
                _a9_obj->f_dst = l6;
                _a9_obj->f_src = l3;
                l8 = (void*) _a9_obj;
                vader_midir_emit(l0, vader_ref_box(l8));
            }
        }
    }
    if (!(((vader_struct_vader_midir_FnCtx_t*) l0)->f_current.tag == 0u)) {
        vader_struct_vader_midir_TermBranch_t* _a10_obj = (vader_struct_vader_midir_TermBranch_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_TermBranch_t));
        vader_obj_header_init(_a10_obj, 860u);
        _a10_obj->f_span = ((vader_struct_vader_lower_LoweredBinary_t*) l1)->f_span;
        _a10_obj->f_target = l11;
        l8 = (void*) _a10_obj;
        vader_midir_terminate(l0, vader_ref_box(l8));
    }
    ((vader_struct_vader_midir_FnCtx_t*) l0)->f_current = vader_box_i32(179u, l11);
    VADER_WRITE_BARRIER((vader_struct_vader_midir_FnCtx_t*) l0);
    t0 = vader_box_i32(179u, l6);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
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
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    if (l1.tag == 769u) {
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
                    vader_obj_header_init(_a0_obj, 846u);
                    _a0_obj->f_span = l5;
                    _a0_obj->f_dst = l6;
                    _a0_obj->f_src = l7;
                    l5 = (void*) _a0_obj;
                    vader_midir_emit(l0, vader_ref_box(l5));
                }
            }
        }
    } else {
        if (l1.tag == 743u) {
            l5 = l1.payload.obj;
            vader_midir_build_assign(l0, l5);
        } else {
            if (l1.tag == 753u) {
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
                        vader_obj_header_init(_a1_obj, 835u);
                        _a1_obj->f_span = l5;
                        _a1_obj->f_cell = l6;
                        _a1_obj->f_value = l7;
                        _a1_obj->f_value_type = l2;
                        l5 = (void*) _a1_obj;
                        vader_midir_emit(l0, vader_ref_box(l5));
                    }
                }
            } else {
                if (l1.tag == 759u) {
                    t0 = l1.payload.obj;
                    l2 = ((vader_struct_vader_lower_LoweredDeferPush_t*) t0)->f_thunk;
                    l2 = vader_midir_build_expr(l0, l2);
                    if (!(l2.tag == 0u)) {
                        t0 = l1.payload.obj;
                        l5 = ((vader_struct_vader_lower_LoweredDeferPush_t*) t0)->f_span;
                        l6 = ((int32_t) l2.payload.i);
                        vader_struct_vader_midir_InstrDeferPush_t* _a2_obj = (vader_struct_vader_midir_InstrDeferPush_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrDeferPush_t));
                        vader_obj_header_init(_a2_obj, 839u);
                        _a2_obj->f_span = l5;
                        _a2_obj->f_value = l6;
                        l5 = (void*) _a2_obj;
                        vader_midir_emit(l0, vader_ref_box(l5));
                    }
                } else {
                    if (l1.tag == 758u) {
                        t0 = l1.payload.obj;
                        l5 = ((vader_struct_vader_lower_LoweredDeferPopExec_t*) t0)->f_span;
                        t0 = l1.payload.obj;
                        l6 = ((vader_struct_vader_lower_LoweredDeferPopExec_t*) t0)->f_count;
                        vader_struct_vader_midir_InstrDeferPopExec_t* _a3_obj = (vader_struct_vader_midir_InstrDeferPopExec_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrDeferPopExec_t));
                        vader_obj_header_init(_a3_obj, 838u);
                        _a3_obj->f_span = l5;
                        _a3_obj->f_count = l6;
                        l5 = (void*) _a3_obj;
                        vader_midir_emit(l0, vader_ref_box(l5));
                    } else {
                        if (l1.tag == 760u) {
                            t0 = l1.payload.obj;
                            l2 = ((vader_struct_vader_lower_LoweredExprStmt_t*) t0)->f_expr;
                            vader_midir_build_expr(l0, l2);
                        } else {
                            if (l1.tag == 776u) {
                                vader_array_t* _a4_arr = vader_array_new(9u, 0u, 7u, 179u);
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
                                vader_obj_header_init(_a5_obj, 862u);
                                _a5_obj->f_span = ((vader_struct_vader_lower_LoweredReturn_t*) t0)->f_span;
                                _a5_obj->f_values = l5;
                                l5 = (void*) _a5_obj;
                                vader_midir_terminate(l0, vader_ref_box(l5));
                            } else {
                                if (l1.tag == 770u) {
                                    l5 = l1.payload.obj;
                                    vader_midir_build_loop(l0, l5);
                                } else {
                                    if (l1.tag == 748u) {
                                        t0 = l1.payload.obj;
                                        l2 = ((vader_struct_vader_lower_LoweredBreak_t*) t0)->f_label;
                                        l2 = vader_midir_resolve_loop_frame(l0, l2);
                                        if (l2.tag == 0u) {
                                            { vader_gc_top = gc_frame.prev; return; }
                                        }
                                        l5 = l2.payload.obj;
                                        t0 = l1.payload.obj;
                                        l8 = ((vader_struct_vader_lower_LoweredBreak_t*) t0)->f_span;
                                        l6 = ((vader_struct_vader_midir_LoopFrame_t*) l5)->f_exit_id;
                                        vader_struct_vader_midir_TermBranch_t* _a6_obj = (vader_struct_vader_midir_TermBranch_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_TermBranch_t));
                                        vader_obj_header_init(_a6_obj, 860u);
                                        _a6_obj->f_span = l8;
                                        _a6_obj->f_target = l6;
                                        l5 = (void*) _a6_obj;
                                        vader_midir_terminate(l0, vader_ref_box(l5));
                                    } else {
                                        if (l1.tag == 756u) {
                                            t0 = l1.payload.obj;
                                            l2 = ((vader_struct_vader_lower_LoweredContinue_t*) t0)->f_label;
                                            l2 = vader_midir_resolve_loop_frame(l0, l2);
                                            if (l2.tag == 0u) {
                                                { vader_gc_top = gc_frame.prev; return; }
                                            }
                                            l5 = l2.payload.obj;
                                            t0 = l1.payload.obj;
                                            l8 = ((vader_struct_vader_lower_LoweredContinue_t*) t0)->f_span;
                                            l6 = ((vader_struct_vader_midir_LoopFrame_t*) l5)->f_header_id;
                                            vader_struct_vader_midir_TermBranch_t* _a7_obj = (vader_struct_vader_midir_TermBranch_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_TermBranch_t));
                                            vader_obj_header_init(_a7_obj, 860u);
                                            _a7_obj->f_span = l8;
                                            _a7_obj->f_target = l6;
                                            l5 = (void*) _a7_obj;
                                            vader_midir_terminate(l0, vader_ref_box(l5));
                                        } else {
                                            if ((l1.tag == 744u || l1.tag == 789u)) {
                                                vader_host_std_abort_panic(1943u);
                                            } else {
                                                { vader_gc_top = gc_frame.prev; return; }
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
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
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
        t0 = vader_box_obj(0u, NULL);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l3.tag == 0u) {
        t0 = vader_box_obj(0u, NULL);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4.tag == 0u) {
        t0 = vader_box_obj(0u, NULL);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l5 = ((vader_struct_vader_lower_LoweredStringSlice_t*) l1)->f_type;
    l6 = vader_midir_fresh_tmp(l0, 1490u, l5);
    l7 = ((vader_struct_vader_lower_LoweredStringSlice_t*) l1)->f_span;
    l5 = ((vader_struct_vader_lower_LoweredStringSlice_t*) l1)->f_type;
    l8 = ((int32_t) l2.payload.i);
    l9 = ((int32_t) l3.payload.i);
    l10 = ((int32_t) l4.payload.i);
    vader_struct_vader_midir_InstrStringSlice_t* _a0_obj = (vader_struct_vader_midir_InstrStringSlice_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrStringSlice_t));
    vader_obj_header_init(_a0_obj, 847u);
    _a0_obj->f_span = l7;
    _a0_obj->f_dst = l6;
    _a0_obj->f_type = l5;
    _a0_obj->f_target = l8;
    _a0_obj->f_lo = l9;
    _a0_obj->f_hi = l10;
    l7 = (void*) _a0_obj;
    vader_midir_emit(l0, vader_ref_box(l7));
    t0 = vader_box_i32(179u, l6);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_box_t vader_midir_build_struct_lit(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    size_t l4, l5;
    int32_t l6;
    vader_box_t l7 = vader_box_null(), l8 = vader_box_null();
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    int64_t t2;
    vader_box_t* gc_roots[3] = { &l7, &l8, &t1 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(9u, 0u, 7u, 179u);
    l2 = (void*) _a0_arr;
    l3 = ((vader_struct_vader_lower_LoweredStructLit_t*) l1)->f_fields;
    l4 = ((vader_array_t*) l3)->length;
    l5 = (size_t) (int64_t) INT64_C(0);
    {
        loop_9: {
            if ((l5 < l4)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l5 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5);
                l7 = ((vader_struct_vader_lower_LoweredStructLitField_t*) t0)->f_value;
                l8 = vader_midir_build_expr(l0, l7);
                if (l8.tag == 0u) {
                    t1 = vader_box_obj(0u, NULL);
                    { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
                }
                l6 = ((int32_t) l8.payload.i);
                vader_array_push_i32((vader_array_t*) l2, l6);
                t2 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t2;
                goto loop_9;
            }
        }
    }
    l7 = ((vader_struct_vader_lower_LoweredStructLit_t*) l1)->f_type;
    l6 = vader_midir_fresh_tmp(l0, 2194u, l7);
    l3 = ((vader_struct_vader_lower_LoweredStructLit_t*) l1)->f_span;
    l7 = ((vader_struct_vader_lower_LoweredStructLit_t*) l1)->f_type;
    vader_struct_vader_midir_InstrStructNew_t* _a2_obj = (vader_struct_vader_midir_InstrStructNew_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrStructNew_t));
    vader_obj_header_init(_a2_obj, 848u);
    _a2_obj->f_span = l3;
    _a2_obj->f_dst = l6;
    _a2_obj->f_type = l7;
    _a2_obj->f_fields = l2;
    _a2_obj->f_stack = false;
    l2 = (void*) _a2_obj;
    vader_midir_emit(l0, vader_ref_box(l2));
    t1 = vader_box_i32(179u, l6);
    { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
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
        t0 = vader_box_obj(0u, NULL);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = ((int32_t) l3.payload.i);
    l3 = ((vader_struct_vader_lower_LoweredTypeCheck_t*) l1)->f_type;
    l4 = vader_midir_fresh_tmp(l0, 2279u, l3);
    l5 = ((vader_struct_vader_lower_LoweredTypeCheck_t*) l1)->f_span;
    l3 = ((vader_struct_vader_lower_LoweredTypeCheck_t*) l1)->f_check_type;
    vader_struct_vader_midir_InstrTypeCheck_t* _a0_obj = (vader_struct_vader_midir_InstrTypeCheck_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrTypeCheck_t));
    vader_obj_header_init(_a0_obj, 849u);
    _a0_obj->f_span = l5;
    _a0_obj->f_dst = l4;
    _a0_obj->f_value = l2;
    _a0_obj->f_check_type = l3;
    l5 = (void*) _a0_obj;
    vader_midir_emit(l0, vader_ref_box(l5));
    t0 = vader_box_i32(179u, l4);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
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
    l3 = vader_midir_fresh_tmp(l0, 2282u, l2);
    l4 = ((vader_struct_vader_lower_LoweredTypeConst_t*) l1)->f_span;
    l2 = ((vader_struct_vader_lower_LoweredTypeConst_t*) l1)->f_type;
    l5 = ((vader_struct_vader_lower_LoweredTypeConst_t*) l1)->f_value;
    vader_struct_vader_midir_InstrTypeConst_t* _a0_obj = (vader_struct_vader_midir_InstrTypeConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrTypeConst_t));
    vader_obj_header_init(_a0_obj, 850u);
    _a0_obj->f_span = l4;
    _a0_obj->f_dst = l3;
    _a0_obj->f_type = l2;
    _a0_obj->f_value_type = l5;
    l4 = (void*) _a0_obj;
    vader_midir_emit(l0, vader_ref_box(l4));
    t0 = vader_box_i32(179u, l3);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
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
        t0 = vader_box_obj(0u, NULL);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = ((int32_t) l3.payload.i);
    l3 = ((vader_struct_vader_lower_LoweredUnary_t*) l1)->f_type;
    l4 = vader_midir_fresh_tmp(l0, 2367u, l3);
    l5 = ((vader_struct_vader_lower_LoweredUnary_t*) l1)->f_span;
    l6 = ((vader_struct_vader_lower_LoweredUnary_t*) l1)->f_op;
    l3 = ((vader_struct_vader_lower_LoweredUnary_t*) l1)->f_type;
    vader_struct_vader_midir_InstrUnOp_t* _a0_obj = (vader_struct_vader_midir_InstrUnOp_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrUnOp_t));
    vader_obj_header_init(_a0_obj, 851u);
    _a0_obj->f_span = l5;
    _a0_obj->f_dst = l4;
    _a0_obj->f_op = l6;
    _a0_obj->f_operand = l2;
    _a0_obj->f_type = l3;
    l5 = (void*) _a0_obj;
    vader_midir_emit(l0, vader_ref_box(l5));
    t0 = vader_box_i32(179u, l4);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_box_t vader_midir_build_unreachable_type(void* l0, vader_box_t l1, void* l2, vader_string_t l3, bool l4) {
    vader_box_t l5 = vader_box_null();
    void* l6 = NULL;
    vader_box_t t0 = vader_box_null();
    bool t1;
    int32_t t2;
    vader_box_t* gc_roots[3] = { &l1, &l5, &t0 };
    void** gc_raw_roots[3] = { &l0, &l2, &l6 };
    vader_string_t* gc_atom_roots[1] = { &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    if (((vader_struct_vader_midir_FnCtx_t*) l0)->f_current.tag == 0u) {
        t0 = vader_box_obj(0u, NULL);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_typecheck_is_void(l1);
    if (t1) {
        l5 = vader_box_obj(0u, NULL);
    } else {
        t2 = vader_midir_declare_local(l0, 2368u, l1, vader_box_obj(0u, NULL));
        l5 = vader_box_i32(179u, t2);
    }
    vader_struct_vader_midir_TermUnreachable_t* _a0_obj = (vader_struct_vader_midir_TermUnreachable_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_TermUnreachable_t));
    vader_obj_header_init(_a0_obj, 863u);
    _a0_obj->f_span = l2;
    _a0_obj->f_reason = l3;
    _a0_obj->f_trap = l4;
    l6 = (void*) _a0_obj;
    vader_midir_terminate(l0, vader_ref_box(l6));
    { vader_box_t __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_box_t vader_midir_build_virtual_call(void* l0, void* l1) {
    int32_t l2;
    vader_box_t l3 = vader_box_null(), l5 = vader_box_null();
    void* l4 = NULL;
    void* l6 = NULL;
    vader_string_t l7 = 0;
    vader_string_t l8 = 0;
    vader_box_t t0 = vader_box_null();
    bool t1;
    int32_t t2;
    vader_box_t* gc_roots[3] = { &l3, &l5, &t0 };
    void** gc_raw_roots[4] = { &l0, &l1, &l4, &l6 };
    vader_string_t* gc_atom_roots[2] = { &l7, &l8 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_lower_LoweredVirtualCall_t*) l1)->f_receiver;
    l3 = vader_midir_build_expr(l0, l3);
    if (l3.tag == 0u) {
        t0 = vader_box_obj(0u, NULL);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = ((int32_t) l3.payload.i);
    l4 = ((vader_struct_vader_lower_LoweredVirtualCall_t*) l1)->f_args;
    l3 = vader_midir_build_args(l0, l4);
    if (l3.tag == 0u) {
        t0 = vader_box_obj(0u, NULL);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = l3.payload.obj;
    t1 = vader_typecheck_is_void(((vader_struct_vader_lower_LoweredVirtualCall_t*) l1)->f_type);
    if (t1) {
        l3 = vader_box_obj(0u, NULL);
    } else {
        l5 = ((vader_struct_vader_lower_LoweredVirtualCall_t*) l1)->f_type;
        t2 = vader_midir_fresh_tmp(l0, 2477u, l5);
        l3 = vader_box_i32(179u, t2);
    }
    l6 = ((vader_struct_vader_lower_LoweredVirtualCall_t*) l1)->f_span;
    l7 = ((vader_struct_vader_lower_LoweredVirtualCall_t*) l1)->f_trait_name;
    l8 = ((vader_struct_vader_lower_LoweredVirtualCall_t*) l1)->f_method;
    l5 = ((vader_struct_vader_lower_LoweredVirtualCall_t*) l1)->f_type;
    vader_struct_vader_midir_InstrVirtualCall_t* _a0_obj = (vader_struct_vader_midir_InstrVirtualCall_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrVirtualCall_t));
    vader_obj_header_init(_a0_obj, 852u);
    _a0_obj->f_span = l6;
    _a0_obj->f_dst = l3;
    _a0_obj->f_trait_name = l7;
    _a0_obj->f_method = l8;
    _a0_obj->f_receiver = l2;
    _a0_obj->f_args = l4;
    _a0_obj->f_type = l5;
    l4 = (void*) _a0_obj;
    vader_midir_emit(l0, vader_ref_box(l4));
    { vader_box_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_midir_build_vtables_from_entries(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l11 = NULL;
    void* l12 = NULL;
    void* l19 = NULL;
    void* l20 = NULL;
    void* l21 = NULL;
    void* l22 = NULL;
    void* l23 = NULL;
    size_t l5, l6, l7, l8;
    vader_box_t l9 = vader_box_null(), l18 = vader_box_null();
    vader_string_t l10 = 0;
    vader_string_t l13 = 0;
    vader_string_t l14 = 0;
    vader_string_t l16 = 0;
    int32_t l15, l17;
    void* t0 = NULL;
    int64_t t1;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l9, &l18, &t2 };
    void** gc_raw_roots[13] = { &l0, &l1, &l2, &l3, &l4, &l11, &l12, &l19, &l20, &l21, &l22, &l23, &t0 };
    vader_string_t* gc_atom_roots[4] = { &l10, &l13, &l14, &l16 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 13u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 176u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(6u, 0u, 12u, 174u);
    l3 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 179u);
    l4 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__string__bool_t* _a3_obj = (vader_struct_std_collections_MutableMap__string__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__bool_t));
    vader_obj_header_init(_a3_obj, 364u);
    _a3_obj->f_ekeys = l2;
    _a3_obj->f_evals = l3;
    _a3_obj->f_index = l4;
    _a3_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l2 = (void*) _a3_obj;
    l3 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_functions;
    l5 = ((vader_array_t*) l3)->length;
    l6 = (size_t) (int64_t) INT64_C(0);
    {
        loop_21: {
            if ((l6 < l5)) {
                vader_array_t* _a4_slotarr = ((vader_array_t*) l3);
                if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                if ((size_t) l6 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l6);
                l4 = ((vader_struct_vader_bytecode_BcFunction_t*) t0)->f_body;
                l7 = ((vader_array_t*) l4)->length;
                l8 = (size_t) (int64_t) INT64_C(0);
                {
                    loop_36: {
                        if ((l8 < l7)) {
                            vader_array_t* _a5_slotarr = ((vader_array_t*) l4);
                            if (_a5_slotarr->buf != NULL && _a5_slotarr->buf->header.forward != NULL) { _a5_slotarr->buf = vader_array_buf_forward(_a5_slotarr->buf); }
                            if ((size_t) l8 >= _a5_slotarr->length) { vader_trap("array index out of bounds"); }
                            l9 = vader_array_ref_load_box(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l8);
                            if (l9.tag == 662u) {
                                t0 = l9.payload.obj;
                                l10 = ((vader_struct_vader_bytecode_VirtualCall_t*) t0)->f_vtable_key;
                                std_collections_MutableMap_IndexSet_set_at__string__bool(l2, l10, true);
                            }
                            t1 = (l8 + INT64_C(1));
                            l8 = (size_t) (int64_t) t1;
                            goto loop_36;
                        }
                    }
                }
                t1 = (l6 + INT64_C(1));
                l6 = (size_t) (int64_t) t1;
                goto loop_21;
            }
        }
    }
    vader_array_t* _a6_arr = vader_array_new(8u, 0u, 0u, 176u);
    l3 = (void*) _a6_arr;
    vader_array_t* _a7_arr = vader_array_new(15u, 0u, 4u, 186u);
    l4 = (void*) _a7_arr;
    vader_array_t* _a8_arr = vader_array_new(9u, 0u, 7u, 179u);
    l11 = (void*) _a8_arr;
    vader_struct_std_collections_MutableMap__string__usize_t* _a9_obj = (vader_struct_std_collections_MutableMap__string__usize_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__usize_t));
    vader_obj_header_init(_a9_obj, 370u);
    _a9_obj->f_ekeys = l3;
    _a9_obj->f_evals = l4;
    _a9_obj->f_index = l11;
    _a9_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a9_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a9_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l3 = (void*) _a9_obj;
    vader_array_t* _a10_arr = vader_array_new(44u, 0u, 13u, 664u);
    l4 = (void*) _a10_arr;
    l11 = l0;
    l5 = ((vader_array_t*) l11)->length;
    l6 = (size_t) (int64_t) INT64_C(0);
    {
        loop_96: {
            if ((l6 < l5)) {
                vader_array_t* _a11_slotarr = ((vader_array_t*) l11);
                if (_a11_slotarr->buf != NULL && _a11_slotarr->buf->header.forward != NULL) { _a11_slotarr->buf = vader_array_buf_forward(_a11_slotarr->buf); }
                if ((size_t) l6 >= _a11_slotarr->length) { vader_trap("array index out of bounds"); }
                l12 = vader_array_ref_load_obj(_a11_slotarr->buf, _a11_slotarr->offset + (size_t) l6);
                l10 = ((vader_struct_vader_lower_LoweredVtableEntry_t*) l12)->f_trait_name;
                l13 = ((vader_struct_vader_lower_LoweredVtableEntry_t*) l12)->f_method_name;
                l14 = concat_3(l10, 436u, l13);
                t2 = std_collections_MutableMap_Index_at__string__bool(l2, l14);
                if (!(t2.tag == 174u)) {
                    t1 = (l6 + INT64_C(1));
                    l6 = (size_t) (int64_t) t1;
                    goto loop_96;
                }
                l15 = vader_midir_resolve_vtable_fn_index(((vader_struct_vader_lower_LoweredVtableEntry_t*) l12)->f_fn_symbol, l1);
                if ((l15 < INT32_C(0))) {
                    t1 = (l6 + INT64_C(1));
                    l6 = (size_t) (int64_t) t1;
                    goto loop_96;
                }
                l16 = vader_bytecode_type_intern_key(((vader_struct_vader_lower_LoweredVtableEntry_t*) l12)->f_struct_type);
                l9 = std_collections_MutableMap_Index_at__string__i32(((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_type_key, l16);
                if (!(l9.tag == 179u)) {
                    t1 = (l6 + INT64_C(1));
                    l6 = (size_t) (int64_t) t1;
                    goto loop_96;
                }
                l17 = ((int32_t) l9.payload.i);
                l18 = std_collections_MutableMap_Index_at__string__usize(l3, l14);
                if (l18.tag == 186u) {
                    l7 = ((size_t) l18.payload.i);
                    vader_array_t* _a12_slotarr = ((vader_array_t*) l4);
                    if (_a12_slotarr->buf != NULL && _a12_slotarr->buf->header.forward != NULL) { _a12_slotarr->buf = vader_array_buf_forward(_a12_slotarr->buf); }
                    if ((size_t) l7 >= _a12_slotarr->length) { vader_trap("array index out of bounds"); }
                    t0 = vader_array_ref_load_obj(_a12_slotarr->buf, _a12_slotarr->offset + (size_t) l7);
                    l19 = ((vader_struct_vader_bytecode_VtableRow_t*) t0)->f_entries;
                    vader_struct_vader_bytecode_VtableEntry_t* _a13_obj = (vader_struct_vader_bytecode_VtableEntry_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_VtableEntry_t));
                    vader_obj_header_init(_a13_obj, 663u);
                    _a13_obj->f_receiver_type_index = l17;
                    _a13_obj->f_fn_index = l15;
                    l20 = (void*) _a13_obj;
                    vader_array_push((vader_array_t*) l19, vader_ref_box(l20));
                } else {
                    l8 = ((vader_array_t*) l4)->length;
                    vader_array_t* _a14_arr = vader_array_new(43u, 0u, 13u, 663u);
                    l21 = (void*) _a14_arr;
                    vader_struct_vader_bytecode_VtableEntry_t* _a15_obj = (vader_struct_vader_bytecode_VtableEntry_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_VtableEntry_t));
                    vader_obj_header_init(_a15_obj, 663u);
                    _a15_obj->f_receiver_type_index = l17;
                    _a15_obj->f_fn_index = l15;
                    l22 = (void*) _a15_obj;
                    vader_array_push((vader_array_t*) l21, vader_ref_box(l22));
                    vader_struct_vader_bytecode_VtableRow_t* _a16_obj = (vader_struct_vader_bytecode_VtableRow_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_VtableRow_t));
                    vader_obj_header_init(_a16_obj, 664u);
                    _a16_obj->f_key = l14;
                    _a16_obj->f_entries = l21;
                    l23 = (void*) _a16_obj;
                    vader_array_push((vader_array_t*) l4, vader_ref_box(l23));
                    std_collections_MutableMap_IndexSet_set_at__string__usize(l3, l14, l8);
                }
                t1 = (l6 + INT64_C(1));
                l6 = (size_t) (int64_t) t1;
                goto loop_96;
            }
        }
    }
    { void* __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_string_t vader_midir_c_header_of(void* l0) {
    void* l1;
    void* l4;
    size_t l2, l3;
    bool l5, l7;
    vader_box_t l6, l8;
    vader_string_t t0;
    size_t t1;
    void* t2;
    int64_t t3;
    l1 = l0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    l2 = ((vader_array_t*) l1)->length;
    l3 = (size_t) (int64_t) INT64_C(0);
    {
        loop_7: {
            if ((l3 < l2)) {
                if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                l4 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
                t0 = ((vader_struct_toolchain_ast_Decorator_t*) l4)->f_name;
                if (t0 == 1387u) {
                    t1 = ((vader_array_t*) ((vader_struct_toolchain_ast_Decorator_t*) l4)->f_args)->length;
                    l5 = t1 == INT64_C(1);
                } else {
                    l5 = false;
                }
                if (l5) {
                    vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_Decorator_t*) l4)->f_args);
                    if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                    if ((size_t) INT32_C(0) >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                    l6 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) INT32_C(0));
                    if (l6.tag == 465u) {
                        t2 = l6.payload.obj;
                        t1 = ((vader_array_t*) ((vader_struct_toolchain_ast_StringLitExpr_t*) t2)->f_parts)->length;
                        l7 = t1 == INT64_C(1);
                    } else {
                        l7 = false;
                    }
                    if (l7) {
                        t2 = l6.payload.obj;
                        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_StringLitExpr_t*) t2)->f_parts);
                        if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                        if ((size_t) INT32_C(0) >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                        l8 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) INT32_C(0));
                        if (l8.tag == 467u) {
                            t2 = l8.payload.obj;
                            t0 = ((vader_struct_toolchain_ast_StringLitText_t*) t2)->f_value;
                            return t0;
                        }
                    }
                }
                t3 = (l3 + INT64_C(1));
                l3 = (size_t) (int64_t) t3;
                goto loop_7;
            }
        }
    }
    return 0u;
}

static vader_string_t vader_midir_c_struct_of(void* l0) {
    vader_box_t l1, l8;
    void* l2;
    void* l5;
    size_t l3, l4;
    bool l6, l7;
    void* t0;
    vader_string_t t1;
    size_t t2;
    int64_t t3;
    l1 = ((vader_struct_vader_comptime_MonoEntry_t*) l0)->f_decl;
    if (!(l1.tag == 468u)) {
        return 0u;
    }
    t0 = l1.payload.obj;
    l2 = ((vader_struct_toolchain_ast_StructDecl_t*) t0)->f_decorators;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    l3 = ((vader_array_t*) l2)->length;
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_16: {
            if ((l4 < l3)) {
                if ((size_t) l4 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                l5 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
                t1 = ((vader_struct_toolchain_ast_Decorator_t*) l5)->f_name;
                if (t1 == 1389u) {
                    t2 = ((vader_array_t*) ((vader_struct_toolchain_ast_Decorator_t*) l5)->f_args)->length;
                    l6 = t2 == INT64_C(1);
                } else {
                    l6 = false;
                }
                if (l6) {
                    vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_Decorator_t*) l5)->f_args);
                    if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                    if ((size_t) INT32_C(0) >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                    l1 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) INT32_C(0));
                    if (l1.tag == 465u) {
                        t0 = l1.payload.obj;
                        t2 = ((vader_array_t*) ((vader_struct_toolchain_ast_StringLitExpr_t*) t0)->f_parts)->length;
                        l7 = t2 == INT64_C(1);
                    } else {
                        l7 = false;
                    }
                    if (l7) {
                        t0 = l1.payload.obj;
                        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_StringLitExpr_t*) t0)->f_parts);
                        if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                        if ((size_t) INT32_C(0) >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                        l8 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) INT32_C(0));
                        if (l8.tag == 467u) {
                            t0 = l8.payload.obj;
                            t1 = ((vader_struct_toolchain_ast_StringLitText_t*) t0)->f_value;
                            return t1;
                        }
                    }
                }
                t3 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t3;
                goto loop_16;
            }
        }
    }
    return 0u;
}

static int32_t vader_midir_c_variadic_fixed_of(void* l0) {
    void* l1;
    void* l4;
    size_t l2, l3;
    bool l5;
    vader_box_t l6;
    vader_string_t t0;
    size_t t1;
    void* t2;
    uint64_t t3;
    int64_t t4;
    l1 = l0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    l2 = ((vader_array_t*) l1)->length;
    l3 = (size_t) (int64_t) INT64_C(0);
    {
        loop_7: {
            if ((l3 < l2)) {
                if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                l4 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
                t0 = ((vader_struct_toolchain_ast_Decorator_t*) l4)->f_name;
                if (t0 == 1390u) {
                    t1 = ((vader_array_t*) ((vader_struct_toolchain_ast_Decorator_t*) l4)->f_args)->length;
                    l5 = t1 == INT64_C(1);
                } else {
                    l5 = false;
                }
                if (l5) {
                    vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_Decorator_t*) l4)->f_args);
                    if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                    if ((size_t) INT32_C(0) >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                    l6 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) INT32_C(0));
                    if (l6.tag == 441u) {
                        t2 = l6.payload.obj;
                        t3 = ((vader_struct_toolchain_ast_IntLitExpr_t*) t2)->f_value;
                        return ((int32_t) (uint64_t) t3);
                    }
                }
                t4 = (l3 + INT64_C(1));
                l3 = (size_t) (int64_t) t4;
                goto loop_7;
            }
        }
    }
    return -(INT32_C(1));
}

static vader_box_t vader_midir_call_single_dst(void* l0) {
    size_t t0;
    vader_box_t t1;
    int32_t t2;
    t0 = ((vader_array_t*) ((vader_struct_vader_midir_InstrCall_t*) l0)->f_dsts)->length;
    if (t0 != INT64_C(1)) {
        t1 = vader_box_obj(0u, NULL);
        return t1;
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_midir_InstrCall_t*) l0)->f_dsts);
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    if ((size_t) INT32_C(0) >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
    t2 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) INT32_C(0)];
    t1 = vader_box_i32(179u, t2);
    return t1;
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
    vader_obj_header_init(_a0_obj, 524u);
    l3 = (void*) _a0_obj;
    l4 = vader_midir_push_op_with_span(l0, vader_ref_box(l3), l1);
    l3 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_scopes;
    vader_struct_vader_midir_ScopeFrame_t* _a1_obj = (vader_struct_vader_midir_ScopeFrame_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_ScopeFrame_t));
    vader_obj_header_init(_a1_obj, 859u);
    _a1_obj->f_kind = 1328u;
    _a1_obj->f_target_blk = l2;
    _a1_obj->f_opener_pc = l4;
    l5 = (void*) _a1_obj;
    vader_array_push((vader_array_t*) l3, vader_ref_box(l5));
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_midir_cf_br(void* l0, void* l1, int32_t l2) {
    void* l3 = NULL;
    int32_t l4;
    void** gc_raw_roots[3] = { &l0, &l1, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_bytecode_Branch_t* _a0_obj = (vader_struct_vader_bytecode_Branch_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_Branch_t));
    vader_obj_header_init(_a0_obj, 532u);
    l3 = (void*) _a0_obj;
    l4 = vader_midir_push_op_with_span(l0, vader_ref_box(l3), l1);
    vader_midir_defer_or_resolve_branch(l0, l2, l4);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
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
    vader_obj_header_init(_a0_obj, 549u);
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
    if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
    if ((size_t) l5 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
    l2 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5);
    l6 = ((vader_struct_vader_bytecode_BcFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_slot)->f_jump_table;
    t1 = ((vader_struct_vader_midir_ScopeFrame_t*) l2)->f_opener_pc;
    t0 = ((int64_t) (int32_t) t1);
    l5 = (size_t) (int64_t) t0;
    l7 = (l3 + INT32_C(1));
    vader_array_t* _a2_slotarr = ((vader_array_t*) l6);
    if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
    if ((size_t) l5 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
    ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l5] = (int32_t) l7;
    l6 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_scopes;
    t0 = (l4 - INT64_C(1));
    l4 = (size_t) (int64_t) t0;
    l7 = ((vader_struct_vader_midir_ScopeFrame_t*) l2)->f_target_blk;
    vader_struct_vader_midir_ScopeFrame_t* _a3_obj = (vader_struct_vader_midir_ScopeFrame_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_ScopeFrame_t));
    vader_obj_header_init(_a3_obj, 859u);
    _a3_obj->f_kind = 1764u;
    _a3_obj->f_target_blk = l7;
    _a3_obj->f_opener_pc = l3;
    l2 = (void*) _a3_obj;
    vader_array_t* _a4_slotarr = ((vader_array_t*) l6);
    if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
    if ((size_t) l4 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
    vader_array_ref_store(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l4, l2);
    VADER_WRITE_BARRIER(_a4_slotarr->buf);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
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
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_struct_vader_bytecode_End_t* _a0_obj = (vader_struct_vader_bytecode_End_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_End_t));
    vader_obj_header_init(_a0_obj, 552u);
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
    if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
    if ((size_t) l5 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
    l2 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5);
    vader_array_t* _a2_arr = vader_array_new(86u, 0u, 13u, 859u);
    l6 = (void*) _a2_arr;
    t0 = (l4 - INT64_C(1));
    l4 = (size_t) (int64_t) t0;
    l5 = (size_t) (int64_t) INT64_C(0);
    {
        loop_34: {
            if ((l5 < l4)) {
                vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_scopes);
                if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                if ((size_t) l5 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                l7 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l5);
                vader_array_push((vader_array_t*) l6, vader_ref_box(l7));
                t0 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t0;
                goto loop_34;
            }
        }
    }
    ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_scopes = l6;
    VADER_WRITE_BARRIER((vader_struct_vader_midir_FnEmitCfg_t*) l0);
    t1 = ((vader_struct_vader_midir_ScopeFrame_t*) l2)->f_kind;
    if (t1 != 1905u) {
        l6 = ((vader_struct_vader_bytecode_BcFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_slot)->f_jump_table;
        t2 = ((vader_struct_vader_midir_ScopeFrame_t*) l2)->f_opener_pc;
        t0 = ((int64_t) (int32_t) t2);
        l4 = (size_t) (int64_t) t0;
        vader_array_t* _a4_slotarr = ((vader_array_t*) l6);
        if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
        if ((size_t) l4 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
        t2 = ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l4];
        if ((t2 < INT32_C(0))) {
            l6 = ((vader_struct_vader_bytecode_BcFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_slot)->f_jump_table;
            t2 = ((vader_struct_vader_midir_ScopeFrame_t*) l2)->f_opener_pc;
            t0 = ((int64_t) (int32_t) t2);
            l4 = (size_t) (int64_t) t0;
            l8 = (l3 + INT32_C(1));
            vader_array_t* _a5_slotarr = ((vader_array_t*) l6);
            if (_a5_slotarr->buf != NULL && _a5_slotarr->buf->header.forward != NULL) { _a5_slotarr->buf = vader_array_buf_forward(_a5_slotarr->buf); }
            if ((size_t) l4 >= _a5_slotarr->length) { vader_trap("array index out of bounds"); }
            ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l4] = (int32_t) l8;
        }
    }
    l8 = ((vader_struct_vader_midir_ScopeFrame_t*) l2)->f_target_blk;
    t1 = ((vader_struct_vader_midir_ScopeFrame_t*) l2)->f_kind;
    l9 = t1 == 1905u;
    l10 = ((vader_struct_vader_midir_ScopeFrame_t*) l2)->f_opener_pc;
    vader_midir_drain_pending(l0, l8, l9, l10, l3);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_midir_cf_if(void* l0, void* l1, int32_t l2) {
    void* l3 = NULL;
    void* l5 = NULL;
    int32_t l4;
    void** gc_raw_roots[4] = { &l0, &l1, &l3, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_bytecode_If_t* _a0_obj = (vader_struct_vader_bytecode_If_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_If_t));
    vader_obj_header_init(_a0_obj, 609u);
    l3 = (void*) _a0_obj;
    l4 = vader_midir_push_op_with_span(l0, vader_ref_box(l3), l1);
    l3 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_scopes;
    vader_struct_vader_midir_ScopeFrame_t* _a1_obj = (vader_struct_vader_midir_ScopeFrame_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_ScopeFrame_t));
    vader_obj_header_init(_a1_obj, 859u);
    _a1_obj->f_kind = 1764u;
    _a1_obj->f_target_blk = l2;
    _a1_obj->f_opener_pc = l4;
    l5 = (void*) _a1_obj;
    vader_array_push((vader_array_t*) l3, vader_ref_box(l5));
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
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
    vader_obj_header_init(_a0_obj, 622u);
    l3 = (void*) _a0_obj;
    l4 = vader_midir_push_op_with_span(l0, vader_ref_box(l3), l1);
    l3 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_scopes;
    vader_struct_vader_midir_ScopeFrame_t* _a1_obj = (vader_struct_vader_midir_ScopeFrame_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_ScopeFrame_t));
    vader_obj_header_init(_a1_obj, 859u);
    _a1_obj->f_kind = 1905u;
    _a1_obj->f_target_blk = l2;
    _a1_obj->f_opener_pc = l4;
    l5 = (void*) _a1_obj;
    vader_array_push((vader_array_t*) l3, vader_ref_box(l5));
    l3 = ((vader_struct_vader_bytecode_BcFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_slot)->f_jump_table;
    t0 = ((int64_t) (int32_t) l4);
    l6 = (size_t) (int64_t) t0;
    l4 = (l4 + INT32_C(1));
    vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
    if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
    if ((size_t) l6 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
    ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l6] = (int32_t) l4;
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static vader_box_t vader_midir_closure_header_type(vader_box_t l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[4] = { &l1, &l2, &l3, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 930u) {
        l1 = l0.payload.obj;
    } else {
        vader_array_t* _a0_arr = vader_array_new(142u, 0u, 13u, 1246u);
        l2 = (void*) _a0_arr;
        vader_array_t* _a1_arr = vader_array_new(6u, 0u, 12u, 174u);
        l3 = (void*) _a1_arr;
        vader_struct_vader_types_PrimitiveType_t* _a2_obj = (vader_struct_vader_types_PrimitiveType_t*) vader_gc_alloc(sizeof(vader_struct_vader_types_PrimitiveType_t));
        vader_obj_header_init(_a2_obj, 936u);
        _a2_obj->f_name = 2479u;
        l4 = (void*) _a2_obj;
        vader_struct_vader_types_FnType_t* _a3_obj = (vader_struct_vader_types_FnType_t*) vader_gc_alloc(sizeof(vader_struct_vader_types_FnType_t));
        vader_obj_header_init(_a3_obj, 930u);
        _a3_obj->f_params = l2;
        _a3_obj->f_params_mutable = l3;
        _a3_obj->f_return_type = vader_ref_box(l4);
        l1 = (void*) _a3_obj;
    }
    { vader_box_t __vret = vader_ref_box(l1); vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_midir_compact_locals(void* l0) {
    vader_box_t l1 = vader_box_null(), l4 = vader_box_null(), l11 = vader_box_null(), l13 = vader_box_null(), l21 = vader_box_null(), l27 = vader_box_null();
    void* l2 = NULL;
    void* l6 = NULL;
    void* l9 = NULL;
    void* l12 = NULL;
    void* l14 = NULL;
    void* l19 = NULL;
    void* l25 = NULL;
    void* l28 = NULL;
    void* l31 = NULL;
    void* l32 = NULL;
    void* l33 = NULL;
    size_t l3, l5, l7, l8, l10, l15, l17, l18, l20, l23, l24, l26;
    int32_t l16, l29;
    bool l22, l35;
    vader_string_t l30 = 0;
    vader_string_t l34 = 0;
    size_t t0;
    void* t1 = NULL;
    int64_t t2;
    bool t3;
    int32_t t4;
    vader_box_t t5 = vader_box_null();
    vader_box_t* gc_roots[7] = { &l1, &l4, &l11, &l13, &l21, &l27, &t5 };
    void** gc_raw_roots[13] = { &l0, &l2, &l6, &l9, &l12, &l14, &l19, &l25, &l28, &l31, &l32, &l33, &t1 };
    vader_string_t* gc_atom_roots[2] = { &l30, &l34 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 7u, 13u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_locals)->length;
    vader_struct__Cell_usize_t* _a0_obj = (vader_struct__Cell_usize_t*) vader_gc_alloc(sizeof(vader_struct__Cell_usize_t));
    vader_obj_header_init(_a0_obj, 207u);
    _a0_obj->f_value = t0;
    t1 = (void*) _a0_obj;
    l1 = vader_ref_box(t1);
    vader_array_t* _a1_arr = vader_array_new(6u, 1u, 12u, 174u);
    ((uint8_t*) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = (uint8_t) false;
    l2 = (void*) _a1_arr;
    l3 = ((vader_struct__Cell_usize_t*) l1.payload.obj)->f_value;
    vader_array_t* _a2_arr = vader_array_repeat((vader_array_t*) l2, (size_t) l3);
    t1 = (void*) _a2_arr;
    vader_struct__Cell_Array_bool__t* _a3_obj = (vader_struct__Cell_Array_bool__t*) vader_gc_alloc(sizeof(vader_struct__Cell_Array_bool__t));
    vader_obj_header_init(_a3_obj, 192u);
    _a3_obj->f_value = t1;
    t1 = (void*) _a3_obj;
    l4 = vader_ref_box(t1);
    l2 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_params;
    vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
    if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
    l3 = ((vader_array_t*) l2)->length;
    l5 = (size_t) (int64_t) INT64_C(0);
    {
        loop_21: {
            if ((l5 < l3)) {
                if ((size_t) l5 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                l6 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l5);
                t2 = ((int64_t) (int32_t) ((vader_struct_vader_midir_CFGParam_t*) l6)->f_local);
                l7 = (size_t) (int64_t) t2;
                l8 = ((vader_struct__Cell_usize_t*) l1.payload.obj)->f_value;
                if ((l7 < l8)) {
                    l9 = ((vader_struct__Cell_Array_bool__t*) l4.payload.obj)->f_value;
                    t2 = ((int64_t) (int32_t) ((vader_struct_vader_midir_CFGParam_t*) l6)->f_local);
                    l10 = (size_t) (int64_t) t2;
                    vader_array_t* _a5_slotarr = ((vader_array_t*) l9);
                    if (_a5_slotarr->buf != NULL && _a5_slotarr->buf->header.forward != NULL) { _a5_slotarr->buf = vader_array_buf_forward(_a5_slotarr->buf); }
                    if ((size_t) l10 >= _a5_slotarr->length) { vader_trap("array index out of bounds"); }
                    ((uint8_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l10] = (uint8_t) true;
                }
                t2 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t2;
                goto loop_21;
            }
        }
    }
    l2 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_blocks;
    l3 = ((vader_array_t*) l2)->length;
    l5 = (size_t) (int64_t) INT64_C(0);
    {
        loop_64: {
            if ((l5 < l3)) {
                vader_array_t* _a6_slotarr = ((vader_array_t*) l2);
                if (_a6_slotarr->buf != NULL && _a6_slotarr->buf->header.forward != NULL) { _a6_slotarr->buf = vader_array_buf_forward(_a6_slotarr->buf); }
                if ((size_t) l5 >= _a6_slotarr->length) { vader_trap("array index out of bounds"); }
                l6 = vader_array_ref_load_obj(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l5);
                l9 = ((vader_struct_vader_midir_BasicBlock_t*) l6)->f_instructions;
                l7 = ((vader_array_t*) l9)->length;
                l8 = (size_t) (int64_t) INT64_C(0);
                {
                    loop_80: {
                        if ((l8 < l7)) {
                            vader_array_t* _a7_slotarr = ((vader_array_t*) l9);
                            if (_a7_slotarr->buf != NULL && _a7_slotarr->buf->header.forward != NULL) { _a7_slotarr->buf = vader_array_buf_forward(_a7_slotarr->buf); }
                            if ((size_t) l8 >= _a7_slotarr->length) { vader_trap("array index out of bounds"); }
                            l11 = vader_array_ref_load_box(_a7_slotarr->buf, _a7_slotarr->offset + (size_t) l8);
                            vader_struct___lambda_env_vader_midir_1_t* _a8_obj = (vader_struct___lambda_env_vader_midir_1_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_midir_1_t));
                            vader_obj_header_init(_a8_obj, 259u);
                            _a8_obj->f_cap_0 = l1;
                            _a8_obj->f_cap_1 = l4;
                            t1 = (void*) _a8_obj;
                            vader_fn_t* _a9_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
                            vader_obj_header_init(_a9_closure, 151u);
                            _a9_closure->code = (void*) &vader_fn_lift___lambda_vader_midir_0;
                            _a9_closure->env = t1;
                            l12 = (void*) _a9_closure;
                            vader_midir_for_each_read_local(l11, l12);
                            t3 = vader_midir_instruction_has_side_effect(l11);
                            if (t3) {
                                l13 = vader_midir_multi_dsts(l11);
                                if (!(l13.tag == 0u)) {
                                    l14 = l13.payload.obj;
                                    vader_array_t* _a10_slotarr = ((vader_array_t*) l14);
                                    if (_a10_slotarr->buf != NULL && _a10_slotarr->buf->header.forward != NULL) { _a10_slotarr->buf = vader_array_buf_forward(_a10_slotarr->buf); }
                                    l10 = ((vader_array_t*) l14)->length;
                                    l15 = (size_t) (int64_t) INT64_C(0);
                                    {
                                        loop_114: {
                                            if ((l15 < l10)) {
                                                l16 = ((int32_t*) _a10_slotarr->buf->slots)[_a10_slotarr->offset + (size_t) l15];
                                                t2 = ((int64_t) (int32_t) l16);
                                                l17 = (size_t) (int64_t) t2;
                                                l18 = ((vader_struct__Cell_usize_t*) l1.payload.obj)->f_value;
                                                if ((l17 < l18)) {
                                                    l19 = ((vader_struct__Cell_Array_bool__t*) l4.payload.obj)->f_value;
                                                    t2 = ((int64_t) (int32_t) l16);
                                                    l20 = (size_t) (int64_t) t2;
                                                    vader_array_t* _a11_slotarr = ((vader_array_t*) l19);
                                                    if (_a11_slotarr->buf != NULL && _a11_slotarr->buf->header.forward != NULL) { _a11_slotarr->buf = vader_array_buf_forward(_a11_slotarr->buf); }
                                                    if ((size_t) l20 >= _a11_slotarr->length) { vader_trap("array index out of bounds"); }
                                                    ((uint8_t*) _a11_slotarr->buf->slots)[_a11_slotarr->offset + (size_t) l20] = (uint8_t) true;
                                                }
                                                t2 = (l15 + INT64_C(1));
                                                l15 = (size_t) (int64_t) t2;
                                                goto loop_114;
                                            }
                                        }
                                    }
                                } else {
                                    l21 = vader_midir_dst_of(l11);
                                    if (!(l21.tag == 0u)) {
                                        t4 = ((int32_t) l21.payload.i);
                                        t2 = ((int64_t) (int32_t) t4);
                                        l23 = (size_t) (int64_t) t2;
                                        l24 = ((vader_struct__Cell_usize_t*) l1.payload.obj)->f_value;
                                        l22 = (l23 < l24);
                                    } else {
                                        l22 = false;
                                    }
                                    if (l22) {
                                        l25 = ((vader_struct__Cell_Array_bool__t*) l4.payload.obj)->f_value;
                                        t4 = ((int32_t) l21.payload.i);
                                        t2 = ((int64_t) (int32_t) t4);
                                        l26 = (size_t) (int64_t) t2;
                                        vader_array_t* _a12_slotarr = ((vader_array_t*) l25);
                                        if (_a12_slotarr->buf != NULL && _a12_slotarr->buf->header.forward != NULL) { _a12_slotarr->buf = vader_array_buf_forward(_a12_slotarr->buf); }
                                        if ((size_t) l26 >= _a12_slotarr->length) { vader_trap("array index out of bounds"); }
                                        ((uint8_t*) _a12_slotarr->buf->slots)[_a12_slotarr->offset + (size_t) l26] = (uint8_t) true;
                                    }
                                }
                            }
                            t2 = (l8 + INT64_C(1));
                            l8 = (size_t) (int64_t) t2;
                            goto loop_80;
                        }
                    }
                }
                l27 = ((vader_struct_vader_midir_BasicBlock_t*) l6)->f_terminator;
                vader_struct___lambda_env_vader_midir_3_t* _a13_obj = (vader_struct___lambda_env_vader_midir_3_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_midir_3_t));
                vader_obj_header_init(_a13_obj, 265u);
                _a13_obj->f_cap_0 = l1;
                _a13_obj->f_cap_1 = l4;
                t1 = (void*) _a13_obj;
                vader_fn_t* _a14_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
                vader_obj_header_init(_a14_closure, 151u);
                _a14_closure->code = (void*) &vader_fn_lift___lambda_vader_midir_2;
                _a14_closure->env = t1;
                l28 = (void*) _a14_closure;
                vader_midir_for_each_read_in_terminator(l27, l28);
                t2 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t2;
                goto loop_64;
            }
        }
    }
    l22 = false;
    l3 = ((vader_struct__Cell_usize_t*) l1.payload.obj)->f_value;
    vader_array_t* _a15_slotarr = ((vader_array_t*) ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_params);
    if (_a15_slotarr->buf != NULL && _a15_slotarr->buf->header.forward != NULL) { _a15_slotarr->buf = vader_array_buf_forward(_a15_slotarr->buf); }
    l5 = ((vader_array_t*) ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_params)->length;
    {
        loop_219: {
            if ((l5 < l3)) {
                vader_array_t* _a16_slotarr = ((vader_array_t*) ((vader_struct__Cell_Array_bool__t*) l4.payload.obj)->f_value);
                if (_a16_slotarr->buf != NULL && _a16_slotarr->buf->header.forward != NULL) { _a16_slotarr->buf = vader_array_buf_forward(_a16_slotarr->buf); }
                if ((size_t) l5 >= _a16_slotarr->length) { vader_trap("array index out of bounds"); }
                t5 = vader_box_bool(174u, ((uint8_t*) _a16_slotarr->buf->slots)[_a16_slotarr->offset + (size_t) l5]);
                t3 = t5.payload.b;
                if (!(t3)) {
                    l22 = true;
                } else {
                    t2 = (l5 + INT64_C(1));
                    l5 = (size_t) (int64_t) t2;
                    goto loop_219;
                }
            }
        }
    }
    if (!(l22)) {
        { void* __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a17_arr = vader_array_new(9u, 0u, 7u, 179u);
    l2 = (void*) _a17_arr;
    l3 = ((vader_struct__Cell_usize_t*) l1.payload.obj)->f_value;
    vader_array_t* _a18_arr = vader_array_repeat((vader_array_t*) l2, (size_t) l3);
    l2 = (void*) _a18_arr;
    vader_array_t* _a19_arr = vader_array_new(77u, 0u, 13u, 805u);
    l6 = (void*) _a19_arr;
    l3 = ((vader_struct__Cell_usize_t*) l1.payload.obj)->f_value;
    vader_array_t* _a20_arr = vader_array_repeat((vader_array_t*) l6, (size_t) l3);
    l6 = (void*) _a20_arr;
    l3 = ((vader_struct__Cell_usize_t*) l1.payload.obj)->f_value;
    l5 = (size_t) (int64_t) INT64_C(0);
    {
        loop_269: {
            if ((l5 < l3)) {
                vader_array_t* _a21_slotarr = ((vader_array_t*) ((vader_struct__Cell_Array_bool__t*) l4.payload.obj)->f_value);
                if (_a21_slotarr->buf != NULL && _a21_slotarr->buf->header.forward != NULL) { _a21_slotarr->buf = vader_array_buf_forward(_a21_slotarr->buf); }
                if ((size_t) l5 >= _a21_slotarr->length) { vader_trap("array index out of bounds"); }
                t5 = vader_box_bool(174u, ((uint8_t*) _a21_slotarr->buf->slots)[_a21_slotarr->offset + (size_t) l5]);
                t3 = t5.payload.b;
                if (!(t3)) {
                    l16 = -(INT32_C(1));
                    vader_array_push_i32((vader_array_t*) l2, l16);
                    t2 = (l5 + INT64_C(1));
                    l5 = (size_t) (int64_t) t2;
                    goto loop_269;
                }
                t0 = ((vader_array_t*) l6)->length;
                l29 = ((int32_t) (size_t) t0);
                vader_array_push_i32((vader_array_t*) l2, l29);
                vader_array_t* _a22_slotarr = ((vader_array_t*) ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_locals);
                if (_a22_slotarr->buf != NULL && _a22_slotarr->buf->header.forward != NULL) { _a22_slotarr->buf = vader_array_buf_forward(_a22_slotarr->buf); }
                if ((size_t) l5 >= _a22_slotarr->length) { vader_trap("array index out of bounds"); }
                l9 = vader_array_ref_load_obj(_a22_slotarr->buf, _a22_slotarr->offset + (size_t) l5);
                vader_array_push((vader_array_t*) l6, vader_ref_box(l9));
                t2 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t2;
                goto loop_269;
            }
        }
    }
    vader_array_t* _a23_arr = vader_array_new(79u, 0u, 13u, 807u);
    l9 = (void*) _a23_arr;
    l3 = ((vader_array_t*) ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_params)->length;
    vader_array_t* _a24_arr = vader_array_repeat((vader_array_t*) l9, (size_t) l3);
    l9 = (void*) _a24_arr;
    l12 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_params;
    l3 = ((vader_array_t*) l12)->length;
    l5 = (size_t) (int64_t) INT64_C(0);
    {
        loop_330: {
            if ((l5 < l3)) {
                vader_array_t* _a25_slotarr = ((vader_array_t*) l12);
                if (_a25_slotarr->buf != NULL && _a25_slotarr->buf->header.forward != NULL) { _a25_slotarr->buf = vader_array_buf_forward(_a25_slotarr->buf); }
                if ((size_t) l5 >= _a25_slotarr->length) { vader_trap("array index out of bounds"); }
                l14 = vader_array_ref_load_obj(_a25_slotarr->buf, _a25_slotarr->offset + (size_t) l5);
                l30 = ((vader_struct_vader_midir_CFGParam_t*) l14)->f_name;
                l19 = ((vader_struct_vader_midir_CFGParam_t*) l14)->f_symbol;
                l1 = ((vader_struct_vader_midir_CFGParam_t*) l14)->f_type;
                t2 = ((int64_t) (int32_t) ((vader_struct_vader_midir_CFGParam_t*) l14)->f_local);
                l7 = (size_t) (int64_t) t2;
                vader_array_t* _a26_slotarr = ((vader_array_t*) l2);
                if (_a26_slotarr->buf != NULL && _a26_slotarr->buf->header.forward != NULL) { _a26_slotarr->buf = vader_array_buf_forward(_a26_slotarr->buf); }
                if ((size_t) l7 >= _a26_slotarr->length) { vader_trap("array index out of bounds"); }
                l16 = ((int32_t*) _a26_slotarr->buf->slots)[_a26_slotarr->offset + (size_t) l7];
                vader_struct_vader_midir_CFGParam_t* _a27_obj = (vader_struct_vader_midir_CFGParam_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_CFGParam_t));
                vader_obj_header_init(_a27_obj, 807u);
                _a27_obj->f_name = l30;
                _a27_obj->f_symbol = l19;
                _a27_obj->f_type = l1;
                _a27_obj->f_local = l16;
                l25 = (void*) _a27_obj;
                vader_array_push((vader_array_t*) l9, vader_ref_box(l25));
                t2 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t2;
                goto loop_330;
            }
        }
    }
    vader_array_t* _a28_arr = vader_array_new(74u, 0u, 13u, 802u);
    l12 = (void*) _a28_arr;
    l3 = ((vader_array_t*) ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_blocks)->length;
    vader_array_t* _a29_arr = vader_array_repeat((vader_array_t*) l12, (size_t) l3);
    l12 = (void*) _a29_arr;
    l14 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_blocks;
    l3 = ((vader_array_t*) l14)->length;
    l5 = (size_t) (int64_t) INT64_C(0);
    {
        loop_386: {
            if ((l5 < l3)) {
                vader_array_t* _a30_slotarr = ((vader_array_t*) l14);
                if (_a30_slotarr->buf != NULL && _a30_slotarr->buf->header.forward != NULL) { _a30_slotarr->buf = vader_array_buf_forward(_a30_slotarr->buf); }
                if ((size_t) l5 >= _a30_slotarr->length) { vader_trap("array index out of bounds"); }
                l19 = vader_array_ref_load_obj(_a30_slotarr->buf, _a30_slotarr->offset + (size_t) l5);
                vader_array_t* _a31_arr = vader_array_new(141u, 0u, 13u, 1220u);
                l25 = (void*) _a31_arr;
                l7 = ((vader_array_t*) ((vader_struct_vader_midir_BasicBlock_t*) l19)->f_instructions)->length;
                vader_array_t* _a32_arr = vader_array_repeat((vader_array_t*) l25, (size_t) l7);
                l28 = (void*) _a32_arr;
                l31 = ((vader_struct_vader_midir_BasicBlock_t*) l19)->f_instructions;
                l8 = ((vader_array_t*) l31)->length;
                l10 = (size_t) (int64_t) INT64_C(0);
                {
                    loop_411: {
                        if ((l10 < l8)) {
                            vader_array_t* _a33_slotarr = ((vader_array_t*) l31);
                            if (_a33_slotarr->buf != NULL && _a33_slotarr->buf->header.forward != NULL) { _a33_slotarr->buf = vader_array_buf_forward(_a33_slotarr->buf); }
                            if ((size_t) l10 >= _a33_slotarr->length) { vader_trap("array index out of bounds"); }
                            l1 = vader_array_ref_load_box(_a33_slotarr->buf, _a33_slotarr->offset + (size_t) l10);
                            l4 = vader_midir_dst_of(l1);
                            if (l4.tag == 179u) {
                                t4 = ((int32_t) l4.payload.i);
                                t2 = ((int64_t) (int32_t) t4);
                                l15 = (size_t) (int64_t) t2;
                                l17 = ((vader_array_t*) l2)->length;
                                if ((l15 < l17)) {
                                    t4 = ((int32_t) l4.payload.i);
                                    t2 = ((int64_t) (int32_t) t4);
                                    l18 = (size_t) (int64_t) t2;
                                    vader_array_t* _a34_slotarr = ((vader_array_t*) l2);
                                    if (_a34_slotarr->buf != NULL && _a34_slotarr->buf->header.forward != NULL) { _a34_slotarr->buf = vader_array_buf_forward(_a34_slotarr->buf); }
                                    if ((size_t) l18 >= _a34_slotarr->length) { vader_trap("array index out of bounds"); }
                                    t4 = ((int32_t*) _a34_slotarr->buf->slots)[_a34_slotarr->offset + (size_t) l18];
                                    l22 = (t4 < INT32_C(0));
                                } else {
                                    l22 = false;
                                }
                                if (l22) {
                                    t3 = vader_midir_instruction_has_side_effect(l1);
                                    if (!(t3)) {
                                        t2 = (l10 + INT64_C(1));
                                        l10 = (size_t) (int64_t) t2;
                                        goto loop_411;
                                    }
                                    l11 = vader_midir_remap_instr(l1, l2);
                                    vader_array_push((vader_array_t*) l28, l11);
                                    l20 = (size_t) (int64_t) INT64_C(1);
                                    t2 = (l10 + l20);
                                    l10 = (size_t) (int64_t) t2;
                                    goto loop_411;
                                }
                                l11 = vader_midir_remap_instr(l1, l2);
                                vader_array_push((vader_array_t*) l28, l11);
                                l20 = (size_t) (int64_t) INT64_C(1);
                                t2 = (l10 + l20);
                                l10 = (size_t) (int64_t) t2;
                                goto loop_411;
                            }
                            l11 = vader_midir_remap_instr(l1, l2);
                            vader_array_push((vader_array_t*) l28, l11);
                            l20 = (size_t) (int64_t) INT64_C(1);
                            t2 = (l10 + l20);
                            l10 = (size_t) (int64_t) t2;
                            goto loop_411;
                        }
                    }
                }
                l16 = ((vader_struct_vader_midir_BasicBlock_t*) l19)->f_id;
                l13 = vader_midir_remap_terminator(((vader_struct_vader_midir_BasicBlock_t*) l19)->f_terminator, l2);
                l32 = ((vader_struct_vader_midir_BasicBlock_t*) l19)->f_span;
                vader_struct_vader_midir_BasicBlock_t* _a35_obj = (vader_struct_vader_midir_BasicBlock_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_BasicBlock_t));
                vader_obj_header_init(_a35_obj, 802u);
                _a35_obj->f_id = l16;
                _a35_obj->f_instructions = l28;
                _a35_obj->f_terminator = l13;
                _a35_obj->f_span = l32;
                l33 = (void*) _a35_obj;
                vader_array_push((vader_array_t*) l12, vader_ref_box(l33));
                t2 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t2;
                goto loop_386;
            }
        }
    }
    l2 = l0;
    l30 = ((vader_struct_vader_midir_CFGFunction_t*) l2)->f_mangled;
    l1 = ((vader_struct_vader_midir_CFGFunction_t*) l2)->f_return_type;
    l16 = ((vader_struct_vader_midir_CFGFunction_t*) l2)->f_entry;
    l14 = ((vader_struct_vader_midir_CFGFunction_t*) l2)->f_origin;
    l34 = ((vader_struct_vader_midir_CFGFunction_t*) l2)->f_extern_name;
    l22 = ((vader_struct_vader_midir_CFGFunction_t*) l2)->f_is_extern;
    l35 = ((vader_struct_vader_midir_CFGFunction_t*) l2)->f_is_exported;
    l2 = ((vader_struct_vader_midir_CFGFunction_t*) l2)->f_scalarised_results;
    vader_struct_vader_midir_CFGFunction_t* _a36_obj = (vader_struct_vader_midir_CFGFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_CFGFunction_t));
    vader_obj_header_init(_a36_obj, 804u);
    _a36_obj->f_mangled = l30;
    _a36_obj->f_params = l9;
    _a36_obj->f_return_type = l1;
    _a36_obj->f_locals = l6;
    _a36_obj->f_blocks = l12;
    _a36_obj->f_entry = l16;
    _a36_obj->f_origin = l14;
    _a36_obj->f_extern_name = l34;
    _a36_obj->f_is_extern = l22;
    _a36_obj->f_is_exported = l35;
    _a36_obj->f_scalarised_results = l2;
    t1 = (void*) _a36_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_midir_compute_carried_across_loop_headers(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l12 = NULL;
    void* l14 = NULL;
    void* l15 = NULL;
    void* l16 = NULL;
    void* l17 = NULL;
    void* l18 = NULL;
    void* l19 = NULL;
    void* l23 = NULL;
    void* l25 = NULL;
    void* l30 = NULL;
    void* l36 = NULL;
    void* l38 = NULL;
    void* l39 = NULL;
    size_t l8, l9, l20, l21, l26, l27, l31, l32, l40, l41;
    int32_t l10, l11, l22, l24, l33, l35, l37, l42;
    vader_box_t l13 = vader_box_null(), l28 = vader_box_null(), l29 = vader_box_null(), l34 = vader_box_null();
    void* t0 = NULL;
    bool t1;
    int64_t t2;
    size_t t3;
    vader_box_t* gc_roots[4] = { &l13, &l28, &l29, &l34 };
    void** gc_raw_roots[22] = { &l0, &l1, &l2, &l3, &l4, &l5, &l6, &l7, &l12, &l14, &l15, &l16, &l17, &l18, &l19, &l23, &l25, &l30, &l36, &l38, &l39, &t0 };
    vader_struct___Tuple_2_6ec7a632f940f1af_t _a7_storage = {0};
    void* gc_stack_objs[1] = { (void*) &_a7_storage };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 22u, gc_roots, gc_raw_roots, 1u, gc_stack_objs };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(9u, 0u, 7u, 179u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(6u, 0u, 12u, 174u);
    l3 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 179u);
    l4 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__i32__bool_t* _a3_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
    vader_obj_header_init(_a3_obj, 316u);
    _a3_obj->f_ekeys = l2;
    _a3_obj->f_evals = l3;
    _a3_obj->f_index = l4;
    _a3_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    t0 = (void*) _a3_obj;
    vader_struct_std_collections_MutableSet__i32_t* _a4_obj = (vader_struct_std_collections_MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i32_t));
    vader_obj_header_init(_a4_obj, 384u);
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
    l9 = (size_t) (int64_t) INT64_C(0);
    {
        loop_47: {
            if ((l9 >= l8)) {
            } else {
                vader_array_t* _a5_slotarr = ((vader_array_t*) l6);
                if (_a5_slotarr->buf != NULL && _a5_slotarr->buf->header.forward != NULL) { _a5_slotarr->buf = vader_array_buf_forward(_a5_slotarr->buf); }
                if ((size_t) l9 >= _a5_slotarr->length) { vader_trap("array index out of bounds"); }
                l10 = ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l9];
                vader_array_t* _a6_slotarr = ((vader_array_t*) l7);
                if (_a6_slotarr->buf != NULL && _a6_slotarr->buf->header.forward != NULL) { _a6_slotarr->buf = vader_array_buf_forward(_a6_slotarr->buf); }
                if ((size_t) l9 >= _a6_slotarr->length) { vader_trap("array index out of bounds"); }
                l5 = vader_array_ref_load_obj(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l9);
                vader_struct___Tuple_2_6ec7a632f940f1af_t* _a8_obj = &_a7_storage;
                vader_obj_header_init(_a8_obj, 219u);
                _a8_obj->f__0 = l10;
                _a8_obj->f__1 = l5;
                t0 = (void*) _a8_obj;
                l11 = ((vader_struct___Tuple_2_6ec7a632f940f1af_t*) t0)->f__0;
                t2 = (l9 + INT64_C(1));
                l9 = (size_t) (int64_t) t2;
                l13 = std_collections_MutableMap_Index_at__i32__Any(l3, l11);
                if (l13.tag == 0u) {
                    goto loop_47;
                }
                l12 = l13.payload.obj;
                vader_array_t* _a9_arr = vader_array_new(9u, 0u, 7u, 179u);
                l14 = (void*) _a9_arr;
                vader_array_t* _a10_arr = vader_array_new(6u, 0u, 12u, 174u);
                l15 = (void*) _a10_arr;
                vader_array_t* _a11_arr = vader_array_new(9u, 0u, 7u, 179u);
                l16 = (void*) _a11_arr;
                vader_struct_std_collections_MutableMap__i32__bool_t* _a12_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
                vader_obj_header_init(_a12_obj, 316u);
                _a12_obj->f_ekeys = l14;
                _a12_obj->f_evals = l15;
                _a12_obj->f_index = l16;
                _a12_obj->f_mask = (size_t) (int64_t) INT64_C(0);
                _a12_obj->f_size = (size_t) (int64_t) INT64_C(0);
                _a12_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
                t0 = (void*) _a12_obj;
                vader_struct_std_collections_MutableSet__i32_t* _a13_obj = (vader_struct_std_collections_MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i32_t));
                vader_obj_header_init(_a13_obj, 384u);
                _a13_obj->f_inner = t0;
                l17 = (void*) _a13_obj;
                l18 = l12;
                l19 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) ((vader_struct_std_collections_MutableSet__i32_t*) l18)->f_inner)->f_ekeys;
                l20 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) ((vader_struct_std_collections_MutableSet__i32_t*) l18)->f_inner)->f_size;
                l21 = (size_t) (int64_t) INT64_C(0);
                {
                    loop_108: {
                        if ((l21 >= l20)) {
                        } else {
                            vader_array_t* _a14_slotarr = ((vader_array_t*) l19);
                            if (_a14_slotarr->buf != NULL && _a14_slotarr->buf->header.forward != NULL) { _a14_slotarr->buf = vader_array_buf_forward(_a14_slotarr->buf); }
                            if ((size_t) l21 >= _a14_slotarr->length) { vader_trap("array index out of bounds"); }
                            l22 = ((int32_t*) _a14_slotarr->buf->slots)[_a14_slotarr->offset + (size_t) l21];
                            t2 = (l21 + INT64_C(1));
                            l21 = (size_t) (int64_t) t2;
                            l23 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_blocks;
                            l24 = l22;
                            vader_array_t* _a15_slotarr = ((vader_array_t*) l23);
                            if (_a15_slotarr->buf != NULL && _a15_slotarr->buf->header.forward != NULL) { _a15_slotarr->buf = vader_array_buf_forward(_a15_slotarr->buf); }
                            if ((size_t) l24 >= _a15_slotarr->length) { vader_trap("array index out of bounds"); }
                            t0 = vader_array_ref_load_obj(_a15_slotarr->buf, _a15_slotarr->offset + (size_t) l24);
                            l25 = ((vader_struct_vader_midir_BasicBlock_t*) t0)->f_instructions;
                            l26 = ((vader_array_t*) l25)->length;
                            l27 = (size_t) (int64_t) INT64_C(0);
                            {
                                loop_136: {
                                    if ((l27 < l26)) {
                                        vader_array_t* _a16_slotarr = ((vader_array_t*) l25);
                                        if (_a16_slotarr->buf != NULL && _a16_slotarr->buf->header.forward != NULL) { _a16_slotarr->buf = vader_array_buf_forward(_a16_slotarr->buf); }
                                        if ((size_t) l27 >= _a16_slotarr->length) { vader_trap("array index out of bounds"); }
                                        l28 = vader_array_ref_load_box(_a16_slotarr->buf, _a16_slotarr->offset + (size_t) l27);
                                        l29 = vader_midir_multi_dsts(l28);
                                        if (!(l29.tag == 0u)) {
                                            l30 = l29.payload.obj;
                                            l31 = ((vader_array_t*) l30)->length;
                                            l32 = (size_t) (int64_t) INT64_C(0);
                                            {
                                                loop_158: {
                                                    if ((l32 < l31)) {
                                                        vader_array_t* _a17_slotarr = ((vader_array_t*) l30);
                                                        if (_a17_slotarr->buf != NULL && _a17_slotarr->buf->header.forward != NULL) { _a17_slotarr->buf = vader_array_buf_forward(_a17_slotarr->buf); }
                                                        if ((size_t) l32 >= _a17_slotarr->length) { vader_trap("array index out of bounds"); }
                                                        l33 = ((int32_t*) _a17_slotarr->buf->slots)[_a17_slotarr->offset + (size_t) l32];
                                                        std_collections_add__i32(l17, l33);
                                                        t2 = (l32 + INT64_C(1));
                                                        l32 = (size_t) (int64_t) t2;
                                                        goto loop_158;
                                                    }
                                                }
                                            }
                                        } else {
                                            l34 = vader_midir_dst_of(l28);
                                            if (!(l34.tag == 0u)) {
                                                l35 = ((int32_t) l34.payload.i);
                                                std_collections_add__i32(l17, l35);
                                            }
                                        }
                                        t2 = (l27 + INT64_C(1));
                                        l27 = (size_t) (int64_t) t2;
                                        goto loop_136;
                                    }
                                }
                            }
                            goto loop_108;
                        }
                    }
                }
                l36 = ((vader_struct_vader_midir_Liveness_t*) l4)->f_live_in;
                l37 = l11;
                vader_array_t* _a18_slotarr = ((vader_array_t*) l36);
                if (_a18_slotarr->buf != NULL && _a18_slotarr->buf->header.forward != NULL) { _a18_slotarr->buf = vader_array_buf_forward(_a18_slotarr->buf); }
                if ((size_t) l37 >= _a18_slotarr->length) { vader_trap("array index out of bounds"); }
                l38 = vader_array_ref_load_obj(_a18_slotarr->buf, _a18_slotarr->offset + (size_t) l37);
                l39 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) ((vader_struct_std_collections_MutableSet__i32_t*) l38)->f_inner)->f_ekeys;
                l40 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) ((vader_struct_std_collections_MutableSet__i32_t*) l38)->f_inner)->f_size;
                l41 = (size_t) (int64_t) INT64_C(0);
                {
                    loop_225: {
                        if ((l41 >= l40)) {
                        } else {
                            vader_array_t* _a19_slotarr = ((vader_array_t*) l39);
                            if (_a19_slotarr->buf != NULL && _a19_slotarr->buf->header.forward != NULL) { _a19_slotarr->buf = vader_array_buf_forward(_a19_slotarr->buf); }
                            if ((size_t) l41 >= _a19_slotarr->length) { vader_trap("array index out of bounds"); }
                            l42 = ((int32_t*) _a19_slotarr->buf->slots)[_a19_slotarr->offset + (size_t) l41];
                            t2 = (l41 + INT64_C(1));
                            l41 = (size_t) (int64_t) t2;
                            t1 = std_collections_MutableSet_Contains_contains__i32(l17, l42);
                            if (t1) {
                                std_collections_add__i32(l2, l42);
                            }
                            goto loop_225;
                        }
                    }
                }
                goto loop_47;
            }
        }
    }
    vader_array_t* _a20_arr = vader_array_new(9u, 0u, 7u, 179u);
    l3 = (void*) _a20_arr;
    l4 = l2;
    l5 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) ((vader_struct_std_collections_MutableSet__i32_t*) l4)->f_inner)->f_ekeys;
    l8 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) ((vader_struct_std_collections_MutableSet__i32_t*) l4)->f_inner)->f_size;
    l9 = (size_t) (int64_t) INT64_C(0);
    {
        loop_270: {
            if ((l9 >= l8)) {
            } else {
                vader_array_t* _a21_slotarr = ((vader_array_t*) l5);
                if (_a21_slotarr->buf != NULL && _a21_slotarr->buf->header.forward != NULL) { _a21_slotarr->buf = vader_array_buf_forward(_a21_slotarr->buf); }
                if ((size_t) l9 >= _a21_slotarr->length) { vader_trap("array index out of bounds"); }
                l10 = ((int32_t*) _a21_slotarr->buf->slots)[_a21_slotarr->offset + (size_t) l9];
                t2 = (l9 + INT64_C(1));
                l9 = (size_t) (int64_t) t2;
                vader_array_push_i32((vader_array_t*) l3, l10);
                goto loop_270;
            }
        }
    }
    {
        loop_292: {
            t3 = ((vader_array_t*) l3)->length;
            if ((t3 > INT64_C(0))) {
                t3 = ((vader_array_t*) l3)->length;
                t2 = (t3 - INT64_C(1));
                l8 = (size_t) (int64_t) t2;
                vader_array_t* _a22_slotarr = ((vader_array_t*) l3);
                if (_a22_slotarr->buf != NULL && _a22_slotarr->buf->header.forward != NULL) { _a22_slotarr->buf = vader_array_buf_forward(_a22_slotarr->buf); }
                if ((size_t) l8 >= _a22_slotarr->length) { vader_trap("array index out of bounds"); }
                l10 = ((int32_t*) _a22_slotarr->buf->slots)[_a22_slotarr->offset + (size_t) l8];
                t3 = ((vader_array_t*) l3)->length;
                t2 = (t3 - INT64_C(1));
                l9 = (size_t) (int64_t) t2;
                vader_array_t* _a23_arr = vader_array_slice((vader_array_t*) l3, (size_t) INT64_C(0), (size_t) l9);
                l3 = (void*) _a23_arr;
                l13 = std_collections_MutableMap_Index_at__i32__Any(l1, l10);
                if (!(l13.tag == 0u)) {
                    l4 = l13.payload.obj;
                    l20 = ((vader_array_t*) l4)->length;
                    l21 = (size_t) (int64_t) INT64_C(0);
                    {
                        loop_332: {
                            if ((l21 < l20)) {
                                vader_array_t* _a24_slotarr = ((vader_array_t*) l4);
                                if (_a24_slotarr->buf != NULL && _a24_slotarr->buf->header.forward != NULL) { _a24_slotarr->buf = vader_array_buf_forward(_a24_slotarr->buf); }
                                if ((size_t) l21 >= _a24_slotarr->length) { vader_trap("array index out of bounds"); }
                                l11 = ((int32_t*) _a24_slotarr->buf->slots)[_a24_slotarr->offset + (size_t) l21];
                                t1 = std_collections_MutableSet_Contains_contains__i32(l2, l11);
                                if (t1) {
                                    t2 = (l21 + INT64_C(1));
                                    l21 = (size_t) (int64_t) t2;
                                    goto loop_332;
                                }
                                std_collections_add__i32(l2, l11);
                                vader_array_push_i32((vader_array_t*) l3, l11);
                                t2 = (l21 + INT64_C(1));
                                l21 = (size_t) (int64_t) t2;
                                goto loop_332;
                            }
                        }
                    }
                }
                goto loop_292;
            }
        }
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_midir_compute_dominators(void* l0, void* l1) {
    size_t l2, l9, l13, l14;
    void* l3 = NULL;
    void* l6 = NULL;
    void* l8 = NULL;
    void* l12 = NULL;
    int32_t l4, l5, l10, l11, l15, l16, l17, l18, l19, l20, l21, l23, l24;
    bool l7, l22;
    void* t0 = NULL;
    bool t1;
    int64_t t2;
    int32_t t3;
    void** gc_raw_roots[7] = { &l0, &l1, &l3, &l6, &l8, &l12, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 7u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_array_t*) ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_blocks)->length;
    vader_array_t* _a0_arr = vader_array_new(9u, 1u, 7u, 179u);
    ((int32_t*) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = (int32_t) -(INT32_C(1));
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (size_t) l2);
    l3 = (void*) _a1_arr;
    l4 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_entry;
    l5 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_entry;
    vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
    if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
    if ((size_t) l4 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
    ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l4] = (int32_t) l5;
    l6 = vader_midir_reverse_postorder(l0);
    l7 = true;
    {
        loop_23: {
            if (l7) {
                l7 = false;
                l8 = l6;
                l2 = ((vader_array_t*) l8)->length;
                l9 = (size_t) (int64_t) INT64_C(0);
                {
                    loop_35: {
                        if ((l9 < l2)) {
                            vader_array_t* _a3_slotarr = ((vader_array_t*) l8);
                            if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                            if ((size_t) l9 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                            l4 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l9];
                            l5 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_entry;
                            t1 = vader_midir_BlockId_Equals_equals(l4, l5);
                            if (t1) {
                                t2 = (l9 + INT64_C(1));
                                l9 = (size_t) (int64_t) t2;
                                goto loop_35;
                            }
                            l10 = -(INT32_C(1));
                            l11 = l4;
                            vader_array_t* _a4_slotarr = ((vader_array_t*) l1);
                            if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                            if ((size_t) l11 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                            l12 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l11);
                            l13 = ((vader_array_t*) l12)->length;
                            l14 = (size_t) (int64_t) INT64_C(0);
                            {
                                loop_70: {
                                    if ((l14 < l13)) {
                                        vader_array_t* _a5_slotarr = ((vader_array_t*) l12);
                                        if (_a5_slotarr->buf != NULL && _a5_slotarr->buf->header.forward != NULL) { _a5_slotarr->buf = vader_array_buf_forward(_a5_slotarr->buf); }
                                        if ((size_t) l14 >= _a5_slotarr->length) { vader_trap("array index out of bounds"); }
                                        l15 = ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l14];
                                        l16 = l15;
                                        vader_array_t* _a6_slotarr = ((vader_array_t*) l3);
                                        if (_a6_slotarr->buf != NULL && _a6_slotarr->buf->header.forward != NULL) { _a6_slotarr->buf = vader_array_buf_forward(_a6_slotarr->buf); }
                                        if ((size_t) l16 >= _a6_slotarr->length) { vader_trap("array index out of bounds"); }
                                        l17 = ((int32_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l16];
                                        l18 = -(INT32_C(1));
                                        if (l17 == l18) {
                                            t2 = (l14 + INT64_C(1));
                                            l14 = (size_t) (int64_t) t2;
                                            goto loop_70;
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
                                        goto loop_70;
                                    }
                                }
                            }
                            l21 = -(INT32_C(1));
                            if (l10 != l21) {
                                l23 = l4;
                                vader_array_t* _a7_slotarr = ((vader_array_t*) l3);
                                if (_a7_slotarr->buf != NULL && _a7_slotarr->buf->header.forward != NULL) { _a7_slotarr->buf = vader_array_buf_forward(_a7_slotarr->buf); }
                                if ((size_t) l23 >= _a7_slotarr->length) { vader_trap("array index out of bounds"); }
                                t3 = ((int32_t*) _a7_slotarr->buf->slots)[_a7_slotarr->offset + (size_t) l23];
                                l22 = t3 != l10;
                            } else {
                                l22 = false;
                            }
                            if (l22) {
                                l24 = l4;
                                vader_array_t* _a8_slotarr = ((vader_array_t*) l3);
                                if (_a8_slotarr->buf != NULL && _a8_slotarr->buf->header.forward != NULL) { _a8_slotarr->buf = vader_array_buf_forward(_a8_slotarr->buf); }
                                if ((size_t) l24 >= _a8_slotarr->length) { vader_trap("array index out of bounds"); }
                                ((int32_t*) _a8_slotarr->buf->slots)[_a8_slotarr->offset + (size_t) l24] = (int32_t) l10;
                                l7 = true;
                            }
                            t2 = (l9 + INT64_C(1));
                            l9 = (size_t) (int64_t) t2;
                            goto loop_35;
                        }
                    }
                }
                goto loop_23;
            }
        }
    }
    { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
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
    void** gc_raw_roots[16] = { &l0, &l1, &l2, &l3, &l4, &l5, &l6, &l9, &l28, &l33, &l38, &l42, &l47, &l52, &l59, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 16u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(9u, 0u, 7u, 179u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(6u, 0u, 12u, 174u);
    l3 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 179u);
    l4 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__i32__bool_t* _a3_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
    vader_obj_header_init(_a3_obj, 316u);
    _a3_obj->f_ekeys = l2;
    _a3_obj->f_evals = l3;
    _a3_obj->f_index = l4;
    _a3_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    t0 = (void*) _a3_obj;
    vader_struct_std_collections_MutableSet__i32_t* _a4_obj = (vader_struct_std_collections_MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i32_t));
    vader_obj_header_init(_a4_obj, 384u);
    _a4_obj->f_inner = t0;
    l2 = (void*) _a4_obj;
    vader_array_t* _a5_arr = vader_array_new(9u, 0u, 7u, 179u);
    l3 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(16u, 0u, 0u, 187u);
    l4 = (void*) _a6_arr;
    vader_array_t* _a7_arr = vader_array_new(9u, 0u, 7u, 179u);
    l5 = (void*) _a7_arr;
    vader_struct_std_collections_MutableMap__i32__Any___t* _a8_obj = (vader_struct_std_collections_MutableMap__i32__Any___t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__Any___t));
    vader_obj_header_init(_a8_obj, 289u);
    _a8_obj->f_ekeys = l3;
    _a8_obj->f_evals = l4;
    _a8_obj->f_index = l5;
    _a8_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a8_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a8_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l3 = (void*) _a8_obj;
    vader_array_t* _a9_arr = vader_array_new(9u, 0u, 7u, 179u);
    l4 = (void*) _a9_arr;
    vader_array_t* _a10_arr = vader_array_new(16u, 0u, 0u, 187u);
    l5 = (void*) _a10_arr;
    vader_array_t* _a11_arr = vader_array_new(9u, 0u, 7u, 179u);
    l6 = (void*) _a11_arr;
    vader_struct_std_collections_MutableMap__i32__Any___t* _a12_obj = (vader_struct_std_collections_MutableMap__i32__Any___t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__Any___t));
    vader_obj_header_init(_a12_obj, 289u);
    _a12_obj->f_ekeys = l4;
    _a12_obj->f_evals = l5;
    _a12_obj->f_index = l6;
    _a12_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a12_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a12_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l4 = (void*) _a12_obj;
    l5 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_blocks;
    l7 = ((vader_array_t*) l5)->length;
    l8 = (size_t) (int64_t) INT64_C(0);
    {
        loop_50: {
            if ((l8 < l7)) {
                vader_array_t* _a13_slotarr = ((vader_array_t*) l5);
                if (_a13_slotarr->buf != NULL && _a13_slotarr->buf->header.forward != NULL) { _a13_slotarr->buf = vader_array_buf_forward(_a13_slotarr->buf); }
                if ((size_t) l8 >= _a13_slotarr->length) { vader_trap("array index out of bounds"); }
                l6 = vader_array_ref_load_obj(_a13_slotarr->buf, _a13_slotarr->offset + (size_t) l8);
                l9 = ((vader_struct_vader_midir_BasicBlock_t*) l6)->f_instructions;
                l10 = ((vader_array_t*) l9)->length;
                l11 = (size_t) (int64_t) INT64_C(0);
                {
                    loop_66: {
                        if ((l11 < l10)) {
                            vader_array_t* _a14_slotarr = ((vader_array_t*) l9);
                            if (_a14_slotarr->buf != NULL && _a14_slotarr->buf->header.forward != NULL) { _a14_slotarr->buf = vader_array_buf_forward(_a14_slotarr->buf); }
                            if ((size_t) l11 >= _a14_slotarr->length) { vader_trap("array index out of bounds"); }
                            l12 = vader_array_ref_load_box(_a14_slotarr->buf, _a14_slotarr->offset + (size_t) l11);
                            if (l12.tag == 846u) {
                                t0 = l12.payload.obj;
                                l13 = ((vader_struct_vader_midir_InstrMove_t*) t0)->f_dst;
                                t0 = l12.payload.obj;
                                l14 = ((vader_struct_vader_midir_InstrMove_t*) t0)->f_src;
                                vader_midir_record_alias(l3, l4, l13, l14);
                            } else {
                                if (l12.tag == 832u) {
                                    t0 = l12.payload.obj;
                                    l15 = ((vader_struct_vader_midir_InstrCast_t*) t0)->f_dst;
                                    t0 = l12.payload.obj;
                                    l16 = ((vader_struct_vader_midir_InstrCast_t*) t0)->f_value;
                                    vader_midir_record_alias(l3, l4, l15, l16);
                                } else {
                                    if (l12.tag == 841u) {
                                        t0 = l12.payload.obj;
                                        l17 = ((vader_struct_vader_midir_InstrFieldSet_t*) t0)->f_value;
                                        std_collections_add__i32(l2, l17);
                                    } else {
                                        if (l12.tag == 827u) {
                                            t0 = l12.payload.obj;
                                            l18 = ((vader_struct_vader_midir_InstrArraySet_t*) t0)->f_value;
                                            std_collections_add__i32(l2, l18);
                                            t0 = l12.payload.obj;
                                            l19 = ((vader_struct_vader_midir_InstrArraySet_t*) t0)->f_target;
                                            std_collections_add__i32(l2, l19);
                                        } else {
                                            if (l12.tag == 826u) {
                                                t0 = l12.payload.obj;
                                                l20 = ((vader_struct_vader_midir_InstrArrayPush_t*) t0)->f_value;
                                                std_collections_add__i32(l2, l20);
                                                t0 = l12.payload.obj;
                                                l21 = ((vader_struct_vader_midir_InstrArrayPush_t*) t0)->f_target;
                                                std_collections_add__i32(l2, l21);
                                            } else {
                                                if (l12.tag == 828u) {
                                                    t0 = l12.payload.obj;
                                                    l22 = ((vader_struct_vader_midir_InstrArraySlice_t*) t0)->f_target;
                                                    std_collections_add__i32(l2, l22);
                                                    t0 = l12.payload.obj;
                                                    l23 = ((vader_struct_vader_midir_InstrArraySlice_t*) t0)->f_lo;
                                                    std_collections_add__i32(l2, l23);
                                                    t0 = l12.payload.obj;
                                                    l24 = ((vader_struct_vader_midir_InstrArraySlice_t*) t0)->f_hi;
                                                    std_collections_add__i32(l2, l24);
                                                } else {
                                                    if (l12.tag == 834u) {
                                                        t0 = l12.payload.obj;
                                                        l25 = ((vader_struct_vader_midir_InstrCellNew_t*) t0)->f_value;
                                                        std_collections_add__i32(l2, l25);
                                                    } else {
                                                        if (l12.tag == 835u) {
                                                            t0 = l12.payload.obj;
                                                            l26 = ((vader_struct_vader_midir_InstrCellSet_t*) t0)->f_value;
                                                            std_collections_add__i32(l2, l26);
                                                            t0 = l12.payload.obj;
                                                            l27 = ((vader_struct_vader_midir_InstrCellSet_t*) t0)->f_cell;
                                                            std_collections_add__i32(l2, l27);
                                                        } else {
                                                            if (l12.tag == 830u) {
                                                                t0 = l12.payload.obj;
                                                                l28 = ((vader_struct_vader_midir_InstrCall_t*) t0)->f_args;
                                                                l29 = ((vader_array_t*) l28)->length;
                                                                l30 = (size_t) (int64_t) INT64_C(0);
                                                                {
                                                                    loop_232: {
                                                                        if ((l30 < l29)) {
                                                                            vader_array_t* _a15_slotarr = ((vader_array_t*) l28);
                                                                            if (_a15_slotarr->buf != NULL && _a15_slotarr->buf->header.forward != NULL) { _a15_slotarr->buf = vader_array_buf_forward(_a15_slotarr->buf); }
                                                                            if ((size_t) l30 >= _a15_slotarr->length) { vader_trap("array index out of bounds"); }
                                                                            l31 = ((int32_t*) _a15_slotarr->buf->slots)[_a15_slotarr->offset + (size_t) l30];
                                                                            std_collections_add__i32(l2, l31);
                                                                            t1 = (l30 + INT64_C(1));
                                                                            l30 = (size_t) (int64_t) t1;
                                                                            goto loop_232;
                                                                        }
                                                                    }
                                                                }
                                                            } else {
                                                                if (l12.tag == 831u) {
                                                                    t0 = l12.payload.obj;
                                                                    l32 = ((vader_struct_vader_midir_InstrCallIndirect_t*) t0)->f_callee;
                                                                    std_collections_add__i32(l2, l32);
                                                                    t0 = l12.payload.obj;
                                                                    l33 = ((vader_struct_vader_midir_InstrCallIndirect_t*) t0)->f_args;
                                                                    l34 = ((vader_array_t*) l33)->length;
                                                                    l35 = (size_t) (int64_t) INT64_C(0);
                                                                    {
                                                                        loop_274: {
                                                                            if ((l35 < l34)) {
                                                                                vader_array_t* _a16_slotarr = ((vader_array_t*) l33);
                                                                                if (_a16_slotarr->buf != NULL && _a16_slotarr->buf->header.forward != NULL) { _a16_slotarr->buf = vader_array_buf_forward(_a16_slotarr->buf); }
                                                                                if ((size_t) l35 >= _a16_slotarr->length) { vader_trap("array index out of bounds"); }
                                                                                l36 = ((int32_t*) _a16_slotarr->buf->slots)[_a16_slotarr->offset + (size_t) l35];
                                                                                std_collections_add__i32(l2, l36);
                                                                                t1 = (l35 + INT64_C(1));
                                                                                l35 = (size_t) (int64_t) t1;
                                                                                goto loop_274;
                                                                            }
                                                                        }
                                                                    }
                                                                } else {
                                                                    if (l12.tag == 852u) {
                                                                        t0 = l12.payload.obj;
                                                                        l37 = ((vader_struct_vader_midir_InstrVirtualCall_t*) t0)->f_receiver;
                                                                        std_collections_add__i32(l2, l37);
                                                                        t0 = l12.payload.obj;
                                                                        l38 = ((vader_struct_vader_midir_InstrVirtualCall_t*) t0)->f_args;
                                                                        l39 = ((vader_array_t*) l38)->length;
                                                                        l40 = (size_t) (int64_t) INT64_C(0);
                                                                        {
                                                                            loop_316: {
                                                                                if ((l40 < l39)) {
                                                                                    vader_array_t* _a17_slotarr = ((vader_array_t*) l38);
                                                                                    if (_a17_slotarr->buf != NULL && _a17_slotarr->buf->header.forward != NULL) { _a17_slotarr->buf = vader_array_buf_forward(_a17_slotarr->buf); }
                                                                                    if ((size_t) l40 >= _a17_slotarr->length) { vader_trap("array index out of bounds"); }
                                                                                    l41 = ((int32_t*) _a17_slotarr->buf->slots)[_a17_slotarr->offset + (size_t) l40];
                                                                                    std_collections_add__i32(l2, l41);
                                                                                    t1 = (l40 + INT64_C(1));
                                                                                    l40 = (size_t) (int64_t) t1;
                                                                                    goto loop_316;
                                                                                }
                                                                            }
                                                                        }
                                                                    } else {
                                                                        if (l12.tag == 844u) {
                                                                            t0 = l12.payload.obj;
                                                                            l42 = ((vader_struct_vader_midir_InstrIntrinsic_t*) t0)->f_args;
                                                                            l43 = ((vader_array_t*) l42)->length;
                                                                            l44 = (size_t) (int64_t) INT64_C(0);
                                                                            {
                                                                                loop_350: {
                                                                                    if ((l44 < l43)) {
                                                                                        vader_array_t* _a18_slotarr = ((vader_array_t*) l42);
                                                                                        if (_a18_slotarr->buf != NULL && _a18_slotarr->buf->header.forward != NULL) { _a18_slotarr->buf = vader_array_buf_forward(_a18_slotarr->buf); }
                                                                                        if ((size_t) l44 >= _a18_slotarr->length) { vader_trap("array index out of bounds"); }
                                                                                        l45 = ((int32_t*) _a18_slotarr->buf->slots)[_a18_slotarr->offset + (size_t) l44];
                                                                                        std_collections_add__i32(l2, l45);
                                                                                        t1 = (l44 + INT64_C(1));
                                                                                        l44 = (size_t) (int64_t) t1;
                                                                                        goto loop_350;
                                                                                    }
                                                                                }
                                                                            }
                                                                        } else {
                                                                            if (l12.tag == 845u) {
                                                                                t0 = l12.payload.obj;
                                                                                l46 = ((vader_struct_vader_midir_InstrMakeClosure_t*) t0)->f_env;
                                                                                std_collections_add__i32(l2, l46);
                                                                            } else {
                                                                                if (l12.tag == 848u) {
                                                                                    t0 = l12.payload.obj;
                                                                                    l47 = ((vader_struct_vader_midir_InstrStructNew_t*) t0)->f_fields;
                                                                                    l48 = ((vader_array_t*) l47)->length;
                                                                                    l49 = (size_t) (int64_t) INT64_C(0);
                                                                                    {
                                                                                        loop_396: {
                                                                                            if ((l49 < l48)) {
                                                                                                vader_array_t* _a19_slotarr = ((vader_array_t*) l47);
                                                                                                if (_a19_slotarr->buf != NULL && _a19_slotarr->buf->header.forward != NULL) { _a19_slotarr->buf = vader_array_buf_forward(_a19_slotarr->buf); }
                                                                                                if ((size_t) l49 >= _a19_slotarr->length) { vader_trap("array index out of bounds"); }
                                                                                                l50 = ((int32_t*) _a19_slotarr->buf->slots)[_a19_slotarr->offset + (size_t) l49];
                                                                                                t0 = l12.payload.obj;
                                                                                                l51 = ((vader_struct_vader_midir_InstrStructNew_t*) t0)->f_dst;
                                                                                                vader_midir_append_alias(l3, l51, l50);
                                                                                                t1 = (l49 + INT64_C(1));
                                                                                                l49 = (size_t) (int64_t) t1;
                                                                                                goto loop_396;
                                                                                            }
                                                                                        }
                                                                                    }
                                                                                } else {
                                                                                    if (l12.tag == 825u) {
                                                                                        t0 = l12.payload.obj;
                                                                                        l52 = ((vader_struct_vader_midir_InstrArrayNew_t*) t0)->f_elements;
                                                                                        l53 = ((vader_array_t*) l52)->length;
                                                                                        l54 = (size_t) (int64_t) INT64_C(0);
                                                                                        {
                                                                                            loop_434: {
                                                                                                if ((l54 < l53)) {
                                                                                                    vader_array_t* _a20_slotarr = ((vader_array_t*) l52);
                                                                                                    if (_a20_slotarr->buf != NULL && _a20_slotarr->buf->header.forward != NULL) { _a20_slotarr->buf = vader_array_buf_forward(_a20_slotarr->buf); }
                                                                                                    if ((size_t) l54 >= _a20_slotarr->length) { vader_trap("array index out of bounds"); }
                                                                                                    l55 = ((int32_t*) _a20_slotarr->buf->slots)[_a20_slotarr->offset + (size_t) l54];
                                                                                                    t0 = l12.payload.obj;
                                                                                                    l56 = ((vader_struct_vader_midir_InstrArrayNew_t*) t0)->f_dst;
                                                                                                    vader_midir_append_alias(l3, l56, l55);
                                                                                                    t1 = (l54 + INT64_C(1));
                                                                                                    l54 = (size_t) (int64_t) t1;
                                                                                                    goto loop_434;
                                                                                                }
                                                                                            }
                                                                                        }
                                                                                    } else {
                                                                                        if ((l12.tag == 823u || l12.tag == 840u)) {
                                                                                            t0 = l12.payload.obj;
                                                                                            t2 = vader_midir_read_may_carry_ref(((vader_struct_vader_midir_InstrArrayGet_t*) t0)->f_type);
                                                                                            if (t2) {
                                                                                                t0 = l12.payload.obj;
                                                                                                l57 = ((vader_struct_vader_midir_InstrArrayGet_t*) t0)->f_dst;
                                                                                                t0 = l12.payload.obj;
                                                                                                l58 = ((vader_struct_vader_midir_InstrArrayGet_t*) t0)->f_target;
                                                                                                vader_midir_append_alias(l3, l57, l58);
                                                                                            }
                                                                                        } else {
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
                                        }
                                    }
                                }
                            }
                            t1 = (l11 + INT64_C(1));
                            l11 = (size_t) (int64_t) t1;
                            goto loop_66;
                        }
                    }
                }
                if (((vader_struct_vader_midir_BasicBlock_t*) l6)->f_terminator.tag == 862u) {
                    t0 = ((vader_struct_vader_midir_BasicBlock_t*) l6)->f_terminator.payload.obj;
                    l59 = ((vader_struct_vader_midir_TermReturn_t*) t0)->f_values;
                    l60 = ((vader_array_t*) l59)->length;
                    l61 = (size_t) (int64_t) INT64_C(0);
                    {
                        loop_518: {
                            if ((l61 < l60)) {
                                vader_array_t* _a21_slotarr = ((vader_array_t*) l59);
                                if (_a21_slotarr->buf != NULL && _a21_slotarr->buf->header.forward != NULL) { _a21_slotarr->buf = vader_array_buf_forward(_a21_slotarr->buf); }
                                if ((size_t) l61 >= _a21_slotarr->length) { vader_trap("array index out of bounds"); }
                                l62 = ((int32_t*) _a21_slotarr->buf->slots)[_a21_slotarr->offset + (size_t) l61];
                                std_collections_add__i32(l2, l62);
                                t1 = (l61 + INT64_C(1));
                                l61 = (size_t) (int64_t) t1;
                                goto loop_518;
                            }
                        }
                    }
                }
                t1 = (l8 + INT64_C(1));
                l8 = (size_t) (int64_t) t1;
                goto loop_50;
            }
        }
    }
    vader_array_t* _a22_arr = vader_array_new(9u, 0u, 7u, 179u);
    l5 = (void*) _a22_arr;
    l6 = l2;
    l9 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) ((vader_struct_std_collections_MutableSet__i32_t*) l6)->f_inner)->f_ekeys;
    l7 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) ((vader_struct_std_collections_MutableSet__i32_t*) l6)->f_inner)->f_size;
    l8 = (size_t) (int64_t) INT64_C(0);
    {
        loop_562: {
            if ((l8 >= l7)) {
            } else {
                vader_array_t* _a23_slotarr = ((vader_array_t*) l9);
                if (_a23_slotarr->buf != NULL && _a23_slotarr->buf->header.forward != NULL) { _a23_slotarr->buf = vader_array_buf_forward(_a23_slotarr->buf); }
                if ((size_t) l8 >= _a23_slotarr->length) { vader_trap("array index out of bounds"); }
                l13 = ((int32_t*) _a23_slotarr->buf->slots)[_a23_slotarr->offset + (size_t) l8];
                t1 = (l8 + INT64_C(1));
                l8 = (size_t) (int64_t) t1;
                vader_array_push_i32((vader_array_t*) l5, l13);
                goto loop_562;
            }
        }
    }
    {
        loop_584: {
            t3 = ((vader_array_t*) l5)->length;
            if ((t3 > INT64_C(0))) {
                t3 = ((vader_array_t*) l5)->length;
                t1 = (t3 - INT64_C(1));
                l7 = (size_t) (int64_t) t1;
                vader_array_t* _a24_slotarr = ((vader_array_t*) l5);
                if (_a24_slotarr->buf != NULL && _a24_slotarr->buf->header.forward != NULL) { _a24_slotarr->buf = vader_array_buf_forward(_a24_slotarr->buf); }
                if ((size_t) l7 >= _a24_slotarr->length) { vader_trap("array index out of bounds"); }
                l13 = ((int32_t*) _a24_slotarr->buf->slots)[_a24_slotarr->offset + (size_t) l7];
                t3 = ((vader_array_t*) l5)->length;
                t1 = (t3 - INT64_C(1));
                l8 = (size_t) (int64_t) t1;
                vader_array_t* _a25_arr = vader_array_slice((vader_array_t*) l5, (size_t) INT64_C(0), (size_t) l8);
                l5 = (void*) _a25_arr;
                l12 = std_collections_MutableMap_Index_at__i32__Any(l3, l13);
                if (!(l12.tag == 0u)) {
                    l6 = l12.payload.obj;
                    l10 = ((vader_array_t*) l6)->length;
                    l11 = (size_t) (int64_t) INT64_C(0);
                    {
                        loop_624: {
                            if ((l11 < l10)) {
                                vader_array_t* _a26_slotarr = ((vader_array_t*) l6);
                                if (_a26_slotarr->buf != NULL && _a26_slotarr->buf->header.forward != NULL) { _a26_slotarr->buf = vader_array_buf_forward(_a26_slotarr->buf); }
                                if ((size_t) l11 >= _a26_slotarr->length) { vader_trap("array index out of bounds"); }
                                l14 = ((int32_t*) _a26_slotarr->buf->slots)[_a26_slotarr->offset + (size_t) l11];
                                t2 = std_collections_MutableSet_Contains_contains__i32(l2, l14);
                                if (t2) {
                                    t1 = (l11 + INT64_C(1));
                                    l11 = (size_t) (int64_t) t1;
                                    goto loop_624;
                                }
                                std_collections_add__i32(l2, l14);
                                vader_array_push_i32((vader_array_t*) l5, l14);
                                t1 = (l11 + INT64_C(1));
                                l11 = (size_t) (int64_t) t1;
                                goto loop_624;
                            }
                        }
                    }
                }
                goto loop_584;
            }
        }
    }
    vader_array_t* _a27_arr = vader_array_new(9u, 0u, 7u, 179u);
    l5 = (void*) _a27_arr;
    vader_array_t* _a28_arr = vader_array_new(6u, 0u, 12u, 174u);
    l6 = (void*) _a28_arr;
    vader_array_t* _a29_arr = vader_array_new(9u, 0u, 7u, 179u);
    l9 = (void*) _a29_arr;
    vader_struct_std_collections_MutableMap__i32__bool_t* _a30_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
    vader_obj_header_init(_a30_obj, 316u);
    _a30_obj->f_ekeys = l5;
    _a30_obj->f_evals = l6;
    _a30_obj->f_index = l9;
    _a30_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a30_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a30_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    t0 = (void*) _a30_obj;
    vader_struct_std_collections_MutableSet__i32_t* _a31_obj = (vader_struct_std_collections_MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i32_t));
    vader_obj_header_init(_a31_obj, 384u);
    _a31_obj->f_inner = t0;
    l5 = (void*) _a31_obj;
    l6 = l1;
    l9 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) ((vader_struct_std_collections_MutableSet__i32_t*) l6)->f_inner)->f_ekeys;
    l7 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) ((vader_struct_std_collections_MutableSet__i32_t*) l6)->f_inner)->f_size;
    l8 = (size_t) (int64_t) INT64_C(0);
    {
        loop_690: {
            if ((l8 >= l7)) {
            } else {
                vader_array_t* _a32_slotarr = ((vader_array_t*) l9);
                if (_a32_slotarr->buf != NULL && _a32_slotarr->buf->header.forward != NULL) { _a32_slotarr->buf = vader_array_buf_forward(_a32_slotarr->buf); }
                if ((size_t) l8 >= _a32_slotarr->length) { vader_trap("array index out of bounds"); }
                l13 = ((int32_t*) _a32_slotarr->buf->slots)[_a32_slotarr->offset + (size_t) l8];
                t1 = (l8 + INT64_C(1));
                l8 = (size_t) (int64_t) t1;
                t2 = std_collections_MutableSet_Contains_contains__i32(l2, l13);
                if (t2) {
                    std_collections_add__i32(l5, l13);
                }
                goto loop_690;
            }
        }
    }
    vader_struct_vader_midir_EscapeResult_t* _a33_obj = (vader_struct_vader_midir_EscapeResult_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_EscapeResult_t));
    vader_obj_header_init(_a33_obj, 817u);
    _a33_obj->f_escaping = l5;
    _a33_obj->f_alias_of = l3;
    _a33_obj->f_alias_from = l4;
    t0 = (void*) _a33_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_midir_compute_liveness(void* l0) {
    size_t l1, l4, l15, l16, l21, l22, l32, l33, l35, l36;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    void* l12 = NULL;
    void* l14 = NULL;
    void* l18 = NULL;
    void* l20 = NULL;
    void* l25 = NULL;
    void* l28 = NULL;
    void* l29 = NULL;
    void* l30 = NULL;
    void* l38 = NULL;
    void* l39 = NULL;
    vader_box_t l9 = vader_box_null(), l13 = vader_box_null(), l17 = vader_box_null(), l19 = vader_box_null(), l24 = vader_box_null(), l27 = vader_box_null();
    int32_t l23, l26, l34, l37;
    bool l31;
    void* t0 = NULL;
    int64_t t1;
    bool t2;
    vader_box_t* gc_roots[6] = { &l9, &l13, &l17, &l19, &l24, &l27 };
    void** gc_raw_roots[20] = { &l0, &l2, &l3, &l5, &l6, &l7, &l8, &l10, &l11, &l12, &l14, &l18, &l20, &l25, &l28, &l29, &l30, &l38, &l39, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 6u, 20u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = ((vader_array_t*) ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_blocks)->length;
    vader_array_t* _a0_arr = vader_array_new(19u, 0u, 13u, 384u);
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (size_t) l1);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(19u, 0u, 13u, 384u);
    t0 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_repeat((vader_array_t*) t0, (size_t) l1);
    l3 = (void*) _a3_arr;
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_14: {
            if ((l4 < l1)) {
                vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_blocks);
                if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                if ((size_t) l4 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                l5 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l4);
                vader_array_t* _a5_arr = vader_array_new(9u, 0u, 7u, 179u);
                l6 = (void*) _a5_arr;
                vader_array_t* _a6_arr = vader_array_new(6u, 0u, 12u, 174u);
                l7 = (void*) _a6_arr;
                vader_array_t* _a7_arr = vader_array_new(9u, 0u, 7u, 179u);
                l8 = (void*) _a7_arr;
                vader_struct_std_collections_MutableMap__i32__bool_t* _a8_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
                vader_obj_header_init(_a8_obj, 316u);
                _a8_obj->f_ekeys = l6;
                _a8_obj->f_evals = l7;
                _a8_obj->f_index = l8;
                _a8_obj->f_mask = (size_t) (int64_t) INT64_C(0);
                _a8_obj->f_size = (size_t) (int64_t) INT64_C(0);
                _a8_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
                t0 = (void*) _a8_obj;
                vader_struct_std_collections_MutableSet__i32_t* _a9_obj = (vader_struct_std_collections_MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i32_t));
                vader_obj_header_init(_a9_obj, 384u);
                _a9_obj->f_inner = t0;
                t0 = (void*) _a9_obj;
                vader_struct__Cell_Struct_std_collections_MutableSet_i32__t* _a10_obj = (vader_struct__Cell_Struct_std_collections_MutableSet_i32__t*) vader_gc_alloc(sizeof(vader_struct__Cell_Struct_std_collections_MutableSet_i32__t));
                vader_obj_header_init(_a10_obj, 203u);
                _a10_obj->f_value = t0;
                t0 = (void*) _a10_obj;
                l9 = vader_ref_box(t0);
                vader_array_t* _a11_arr = vader_array_new(9u, 0u, 7u, 179u);
                l10 = (void*) _a11_arr;
                vader_array_t* _a12_arr = vader_array_new(6u, 0u, 12u, 174u);
                l11 = (void*) _a12_arr;
                vader_array_t* _a13_arr = vader_array_new(9u, 0u, 7u, 179u);
                l12 = (void*) _a13_arr;
                vader_struct_std_collections_MutableMap__i32__bool_t* _a14_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
                vader_obj_header_init(_a14_obj, 316u);
                _a14_obj->f_ekeys = l10;
                _a14_obj->f_evals = l11;
                _a14_obj->f_index = l12;
                _a14_obj->f_mask = (size_t) (int64_t) INT64_C(0);
                _a14_obj->f_size = (size_t) (int64_t) INT64_C(0);
                _a14_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
                t0 = (void*) _a14_obj;
                vader_struct_std_collections_MutableSet__i32_t* _a15_obj = (vader_struct_std_collections_MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i32_t));
                vader_obj_header_init(_a15_obj, 384u);
                _a15_obj->f_inner = t0;
                t0 = (void*) _a15_obj;
                vader_struct__Cell_Struct_std_collections_MutableSet_i32__t* _a16_obj = (vader_struct__Cell_Struct_std_collections_MutableSet_i32__t*) vader_gc_alloc(sizeof(vader_struct__Cell_Struct_std_collections_MutableSet_i32__t));
                vader_obj_header_init(_a16_obj, 203u);
                _a16_obj->f_value = t0;
                t0 = (void*) _a16_obj;
                l13 = vader_ref_box(t0);
                l14 = ((vader_struct_vader_midir_BasicBlock_t*) l5)->f_instructions;
                l15 = ((vader_array_t*) l14)->length;
                l16 = (size_t) (int64_t) INT64_C(0);
                {
                    loop_62: {
                        if ((l16 < l15)) {
                            vader_array_t* _a17_slotarr = ((vader_array_t*) l14);
                            if (_a17_slotarr->buf != NULL && _a17_slotarr->buf->header.forward != NULL) { _a17_slotarr->buf = vader_array_buf_forward(_a17_slotarr->buf); }
                            if ((size_t) l16 >= _a17_slotarr->length) { vader_trap("array index out of bounds"); }
                            l17 = vader_array_ref_load_box(_a17_slotarr->buf, _a17_slotarr->offset + (size_t) l16);
                            vader_struct___lambda_env_vader_midir_13_t* _a18_obj = (vader_struct___lambda_env_vader_midir_13_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_midir_13_t));
                            vader_obj_header_init(_a18_obj, 261u);
                            _a18_obj->f_cap_0 = l13;
                            _a18_obj->f_cap_1 = l9;
                            t0 = (void*) _a18_obj;
                            vader_fn_t* _a19_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
                            vader_obj_header_init(_a19_closure, 151u);
                            _a19_closure->code = (void*) &vader_fn_lift___lambda_vader_midir_12;
                            _a19_closure->env = t0;
                            l18 = (void*) _a19_closure;
                            vader_midir_for_each_read_local(l17, l18);
                            l19 = vader_midir_multi_dsts(l17);
                            if (!(l19.tag == 0u)) {
                                l20 = l19.payload.obj;
                                l21 = ((vader_array_t*) l20)->length;
                                l22 = (size_t) (int64_t) INT64_C(0);
                                {
                                    loop_93: {
                                        if ((l22 < l21)) {
                                            vader_array_t* _a20_slotarr = ((vader_array_t*) l20);
                                            if (_a20_slotarr->buf != NULL && _a20_slotarr->buf->header.forward != NULL) { _a20_slotarr->buf = vader_array_buf_forward(_a20_slotarr->buf); }
                                            if ((size_t) l22 >= _a20_slotarr->length) { vader_trap("array index out of bounds"); }
                                            l23 = ((int32_t*) _a20_slotarr->buf->slots)[_a20_slotarr->offset + (size_t) l22];
                                            std_collections_add__i32(((vader_struct__Cell_Struct_std_collections_MutableSet_i32__t*) l13.payload.obj)->f_value, l23);
                                            t1 = (l22 + INT64_C(1));
                                            l22 = (size_t) (int64_t) t1;
                                            goto loop_93;
                                        }
                                    }
                                }
                            } else {
                                l24 = vader_midir_dst_of(l17);
                                if (!(l24.tag == 0u)) {
                                    l25 = ((vader_struct__Cell_Struct_std_collections_MutableSet_i32__t*) l13.payload.obj)->f_value;
                                    l26 = ((int32_t) l24.payload.i);
                                    std_collections_add__i32(l25, l26);
                                }
                            }
                            t1 = (l16 + INT64_C(1));
                            l16 = (size_t) (int64_t) t1;
                            goto loop_62;
                        }
                    }
                }
                l27 = ((vader_struct_vader_midir_BasicBlock_t*) l5)->f_terminator;
                vader_struct___lambda_env_vader_midir_15_t* _a21_obj = (vader_struct___lambda_env_vader_midir_15_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_midir_15_t));
                vader_obj_header_init(_a21_obj, 262u);
                _a21_obj->f_cap_0 = l13;
                _a21_obj->f_cap_1 = l9;
                t0 = (void*) _a21_obj;
                vader_fn_t* _a22_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
                vader_obj_header_init(_a22_closure, 151u);
                _a22_closure->code = (void*) &vader_fn_lift___lambda_vader_midir_14;
                _a22_closure->env = t0;
                l28 = (void*) _a22_closure;
                vader_midir_for_each_read_in_terminator(l27, l28);
                l29 = ((vader_struct__Cell_Struct_std_collections_MutableSet_i32__t*) l9.payload.obj)->f_value;
                vader_array_push((vader_array_t*) l2, vader_ref_box(l29));
                l30 = ((vader_struct__Cell_Struct_std_collections_MutableSet_i32__t*) l13.payload.obj)->f_value;
                vader_array_push((vader_array_t*) l3, vader_ref_box(l30));
                t1 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t1;
                goto loop_14;
            }
        }
    }
    vader_array_t* _a23_arr = vader_array_new(2u, 0u, 13u, 9u);
    t0 = (void*) _a23_arr;
    vader_array_t* _a24_arr = vader_array_repeat((vader_array_t*) t0, (size_t) l1);
    l5 = (void*) _a24_arr;
    l6 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_blocks;
    l4 = ((vader_array_t*) l6)->length;
    l15 = (size_t) (int64_t) INT64_C(0);
    {
        loop_179: {
            if ((l15 < l4)) {
                vader_array_t* _a25_slotarr = ((vader_array_t*) l6);
                if (_a25_slotarr->buf != NULL && _a25_slotarr->buf->header.forward != NULL) { _a25_slotarr->buf = vader_array_buf_forward(_a25_slotarr->buf); }
                if ((size_t) l15 >= _a25_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_ref_load_obj(_a25_slotarr->buf, _a25_slotarr->offset + (size_t) l15);
                l7 = vader_midir_successors_of(t0);
                vader_array_push((vader_array_t*) l5, vader_ref_box(l7));
                t1 = (l15 + INT64_C(1));
                l15 = (size_t) (int64_t) t1;
                goto loop_179;
            }
        }
    }
    vader_struct___lambda_env_vader_midir_17_t* _a26_obj = (vader_struct___lambda_env_vader_midir_17_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_midir_17_t));
    vader_obj_header_init(_a26_obj, 263u);
    t0 = (void*) _a26_obj;
    vader_fn_t* _a27_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
    vader_obj_header_init(_a27_closure, 146u);
    _a27_closure->code = (void*) &vader_fn_lift___lambda_vader_midir_16;
    _a27_closure->env = t0;
    l6 = (void*) _a27_closure;
    l6 = std_core_filled__MutableSet_i32_(l1, l6);
    vader_struct___lambda_env_vader_midir_19_t* _a28_obj = (vader_struct___lambda_env_vader_midir_19_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_midir_19_t));
    vader_obj_header_init(_a28_obj, 264u);
    t0 = (void*) _a28_obj;
    vader_fn_t* _a29_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
    vader_obj_header_init(_a29_closure, 146u);
    _a29_closure->code = (void*) &vader_fn_lift___lambda_vader_midir_18;
    _a29_closure->env = t0;
    l7 = (void*) _a29_closure;
    l7 = std_core_filled__MutableSet_i32_(l1, l7);
    vader_array_t* _a30_arr = vader_array_new(9u, 0u, 7u, 179u);
    l8 = (void*) _a30_arr;
    vader_array_t* _a31_arr = vader_array_new(6u, 0u, 12u, 174u);
    l10 = (void*) _a31_arr;
    vader_array_t* _a32_arr = vader_array_new(9u, 0u, 7u, 179u);
    l11 = (void*) _a32_arr;
    vader_struct_std_collections_MutableMap__i32__bool_t* _a33_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
    vader_obj_header_init(_a33_obj, 316u);
    _a33_obj->f_ekeys = l8;
    _a33_obj->f_evals = l10;
    _a33_obj->f_index = l11;
    _a33_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a33_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a33_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    t0 = (void*) _a33_obj;
    vader_struct_std_collections_MutableSet__i32_t* _a34_obj = (vader_struct_std_collections_MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i32_t));
    vader_obj_header_init(_a34_obj, 384u);
    _a34_obj->f_inner = t0;
    l8 = (void*) _a34_obj;
    vader_array_t* _a35_arr = vader_array_new(9u, 0u, 7u, 179u);
    l10 = (void*) _a35_arr;
    vader_array_t* _a36_arr = vader_array_new(6u, 0u, 12u, 174u);
    l11 = (void*) _a36_arr;
    vader_array_t* _a37_arr = vader_array_new(9u, 0u, 7u, 179u);
    l12 = (void*) _a37_arr;
    vader_struct_std_collections_MutableMap__i32__bool_t* _a38_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
    vader_obj_header_init(_a38_obj, 316u);
    _a38_obj->f_ekeys = l10;
    _a38_obj->f_evals = l11;
    _a38_obj->f_index = l12;
    _a38_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a38_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a38_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    t0 = (void*) _a38_obj;
    vader_struct_std_collections_MutableSet__i32_t* _a39_obj = (vader_struct_std_collections_MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i32_t));
    vader_obj_header_init(_a39_obj, 384u);
    _a39_obj->f_inner = t0;
    l10 = (void*) _a39_obj;
    l31 = true;
    {
        loop_247: {
            if (l31) {
                l31 = false;
                l4 = l1;
                {
                    loop_255: {
                        if ((l4 > INT64_C(0))) {
                            t1 = (l4 - INT64_C(1));
                            l4 = (size_t) (int64_t) t1;
                            std_collections_clear__i32(l8);
                            vader_array_t* _a40_slotarr = ((vader_array_t*) l5);
                            if (_a40_slotarr->buf != NULL && _a40_slotarr->buf->header.forward != NULL) { _a40_slotarr->buf = vader_array_buf_forward(_a40_slotarr->buf); }
                            if ((size_t) l4 >= _a40_slotarr->length) { vader_trap("array index out of bounds"); }
                            l11 = vader_array_ref_load_obj(_a40_slotarr->buf, _a40_slotarr->offset + (size_t) l4);
                            l15 = ((vader_array_t*) l11)->length;
                            l16 = (size_t) (int64_t) INT64_C(0);
                            {
                                loop_275: {
                                    if ((l16 < l15)) {
                                        vader_array_t* _a41_slotarr = ((vader_array_t*) l11);
                                        if (_a41_slotarr->buf != NULL && _a41_slotarr->buf->header.forward != NULL) { _a41_slotarr->buf = vader_array_buf_forward(_a41_slotarr->buf); }
                                        if ((size_t) l16 >= _a41_slotarr->length) { vader_trap("array index out of bounds"); }
                                        l23 = ((int32_t*) _a41_slotarr->buf->slots)[_a41_slotarr->offset + (size_t) l16];
                                        vader_array_t* _a42_slotarr = ((vader_array_t*) l6);
                                        if (_a42_slotarr->buf != NULL && _a42_slotarr->buf->header.forward != NULL) { _a42_slotarr->buf = vader_array_buf_forward(_a42_slotarr->buf); }
                                        if ((size_t) l23 >= _a42_slotarr->length) { vader_trap("array index out of bounds"); }
                                        l12 = vader_array_ref_load_obj(_a42_slotarr->buf, _a42_slotarr->offset + (size_t) l23);
                                        l14 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) ((vader_struct_std_collections_MutableSet__i32_t*) l12)->f_inner)->f_ekeys;
                                        l21 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) ((vader_struct_std_collections_MutableSet__i32_t*) l12)->f_inner)->f_size;
                                        l22 = (size_t) (int64_t) INT64_C(0);
                                        {
                                            loop_298: {
                                                if ((l22 >= l21)) {
                                                } else {
                                                    vader_array_t* _a43_slotarr = ((vader_array_t*) l14);
                                                    if (_a43_slotarr->buf != NULL && _a43_slotarr->buf->header.forward != NULL) { _a43_slotarr->buf = vader_array_buf_forward(_a43_slotarr->buf); }
                                                    if ((size_t) l22 >= _a43_slotarr->length) { vader_trap("array index out of bounds"); }
                                                    l26 = ((int32_t*) _a43_slotarr->buf->slots)[_a43_slotarr->offset + (size_t) l22];
                                                    t1 = (l22 + INT64_C(1));
                                                    l22 = (size_t) (int64_t) t1;
                                                    std_collections_add__i32(l8, l26);
                                                    goto loop_298;
                                                }
                                            }
                                        }
                                        t1 = (l16 + INT64_C(1));
                                        l16 = (size_t) (int64_t) t1;
                                        goto loop_275;
                                    }
                                }
                            }
                            std_collections_clear__i32(l10);
                            vader_array_t* _a44_slotarr = ((vader_array_t*) l2);
                            if (_a44_slotarr->buf != NULL && _a44_slotarr->buf->header.forward != NULL) { _a44_slotarr->buf = vader_array_buf_forward(_a44_slotarr->buf); }
                            if ((size_t) l4 >= _a44_slotarr->length) { vader_trap("array index out of bounds"); }
                            l18 = vader_array_ref_load_obj(_a44_slotarr->buf, _a44_slotarr->offset + (size_t) l4);
                            l20 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) ((vader_struct_std_collections_MutableSet__i32_t*) l18)->f_inner)->f_ekeys;
                            l32 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) ((vader_struct_std_collections_MutableSet__i32_t*) l18)->f_inner)->f_size;
                            l33 = (size_t) (int64_t) INT64_C(0);
                            {
                                loop_344: {
                                    if ((l33 >= l32)) {
                                    } else {
                                        vader_array_t* _a45_slotarr = ((vader_array_t*) l20);
                                        if (_a45_slotarr->buf != NULL && _a45_slotarr->buf->header.forward != NULL) { _a45_slotarr->buf = vader_array_buf_forward(_a45_slotarr->buf); }
                                        if ((size_t) l33 >= _a45_slotarr->length) { vader_trap("array index out of bounds"); }
                                        l34 = ((int32_t*) _a45_slotarr->buf->slots)[_a45_slotarr->offset + (size_t) l33];
                                        t1 = (l33 + INT64_C(1));
                                        l33 = (size_t) (int64_t) t1;
                                        std_collections_add__i32(l10, l34);
                                        goto loop_344;
                                    }
                                }
                            }
                            l25 = l8;
                            l28 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) ((vader_struct_std_collections_MutableSet__i32_t*) l25)->f_inner)->f_ekeys;
                            l35 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) ((vader_struct_std_collections_MutableSet__i32_t*) l25)->f_inner)->f_size;
                            l36 = (size_t) (int64_t) INT64_C(0);
                            {
                                loop_378: {
                                    if ((l36 >= l35)) {
                                    } else {
                                        vader_array_t* _a46_slotarr = ((vader_array_t*) l28);
                                        if (_a46_slotarr->buf != NULL && _a46_slotarr->buf->header.forward != NULL) { _a46_slotarr->buf = vader_array_buf_forward(_a46_slotarr->buf); }
                                        if ((size_t) l36 >= _a46_slotarr->length) { vader_trap("array index out of bounds"); }
                                        l37 = ((int32_t*) _a46_slotarr->buf->slots)[_a46_slotarr->offset + (size_t) l36];
                                        t1 = (l36 + INT64_C(1));
                                        l36 = (size_t) (int64_t) t1;
                                        vader_array_t* _a47_slotarr = ((vader_array_t*) l3);
                                        if (_a47_slotarr->buf != NULL && _a47_slotarr->buf->header.forward != NULL) { _a47_slotarr->buf = vader_array_buf_forward(_a47_slotarr->buf); }
                                        if ((size_t) l4 >= _a47_slotarr->length) { vader_trap("array index out of bounds"); }
                                        t0 = vader_array_ref_load_obj(_a47_slotarr->buf, _a47_slotarr->offset + (size_t) l4);
                                        t2 = std_collections_MutableSet_Contains_contains__i32(t0, l37);
                                        if (!(t2)) {
                                            std_collections_add__i32(l10, l37);
                                        }
                                        goto loop_378;
                                    }
                                }
                            }
                            vader_array_t* _a48_slotarr = ((vader_array_t*) l7);
                            if (_a48_slotarr->buf != NULL && _a48_slotarr->buf->header.forward != NULL) { _a48_slotarr->buf = vader_array_buf_forward(_a48_slotarr->buf); }
                            if ((size_t) l4 >= _a48_slotarr->length) { vader_trap("array index out of bounds"); }
                            l29 = vader_array_ref_load_obj(_a48_slotarr->buf, _a48_slotarr->offset + (size_t) l4);
                            t2 = vader_midir_sets_equal(l8, l29);
                            if (!(t2)) {
                                vader_array_t* _a49_slotarr = ((vader_array_t*) l7);
                                if (_a49_slotarr->buf != NULL && _a49_slotarr->buf->header.forward != NULL) { _a49_slotarr->buf = vader_array_buf_forward(_a49_slotarr->buf); }
                                if ((size_t) l4 >= _a49_slotarr->length) { vader_trap("array index out of bounds"); }
                                l30 = vader_array_ref_load_obj(_a49_slotarr->buf, _a49_slotarr->offset + (size_t) l4);
                                if ((size_t) l4 >= _a49_slotarr->length) { vader_trap("array index out of bounds"); }
                                vader_array_ref_store(_a49_slotarr->buf, _a49_slotarr->offset + (size_t) l4, l8);
                                VADER_WRITE_BARRIER(_a49_slotarr->buf);
                                l8 = l30;
                                l31 = true;
                            }
                            vader_array_t* _a50_slotarr = ((vader_array_t*) l6);
                            if (_a50_slotarr->buf != NULL && _a50_slotarr->buf->header.forward != NULL) { _a50_slotarr->buf = vader_array_buf_forward(_a50_slotarr->buf); }
                            if ((size_t) l4 >= _a50_slotarr->length) { vader_trap("array index out of bounds"); }
                            l38 = vader_array_ref_load_obj(_a50_slotarr->buf, _a50_slotarr->offset + (size_t) l4);
                            t2 = vader_midir_sets_equal(l10, l38);
                            if (!(t2)) {
                                vader_array_t* _a51_slotarr = ((vader_array_t*) l6);
                                if (_a51_slotarr->buf != NULL && _a51_slotarr->buf->header.forward != NULL) { _a51_slotarr->buf = vader_array_buf_forward(_a51_slotarr->buf); }
                                if ((size_t) l4 >= _a51_slotarr->length) { vader_trap("array index out of bounds"); }
                                l39 = vader_array_ref_load_obj(_a51_slotarr->buf, _a51_slotarr->offset + (size_t) l4);
                                if ((size_t) l4 >= _a51_slotarr->length) { vader_trap("array index out of bounds"); }
                                vader_array_ref_store(_a51_slotarr->buf, _a51_slotarr->offset + (size_t) l4, l10);
                                VADER_WRITE_BARRIER(_a51_slotarr->buf);
                                l10 = l39;
                                l31 = true;
                            }
                            goto loop_255;
                        }
                    }
                }
                goto loop_247;
            }
        }
    }
    vader_struct_vader_midir_Liveness_t* _a52_obj = (vader_struct_vader_midir_Liveness_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_Liveness_t));
    vader_obj_header_init(_a52_obj, 853u);
    _a52_obj->f_live_in = l6;
    _a52_obj->f_live_out = l7;
    t0 = (void*) _a52_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_midir_compute_post_dominators(void* l0) {
    size_t l1, l4, l5, l9, l10, l17, l24, l25;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l6 = NULL;
    void* l8 = NULL;
    void* l11 = NULL;
    int32_t l7, l12, l13, l16, l18, l19, l20, l21, l22;
    bool l14, l23;
    int64_t l15;
    void* t0 = NULL;
    int64_t t1;
    size_t t2;
    int32_t t3;
    void** gc_raw_roots[7] = { &l0, &l2, &l3, &l6, &l8, &l11, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 7u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = ((vader_array_t*) ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_blocks)->length;
    vader_array_t* _a0_arr = vader_array_new(2u, 0u, 13u, 9u);
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (size_t) l1);
    l2 = (void*) _a1_arr;
    l3 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_blocks;
    l4 = ((vader_array_t*) l3)->length;
    l5 = (size_t) (int64_t) INT64_C(0);
    {
        loop_14: {
            if ((l5 < l4)) {
                vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
                if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                if ((size_t) l5 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l5);
                l6 = vader_midir_successors_of(t0);
                vader_array_push((vader_array_t*) l2, vader_ref_box(l6));
                t1 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t1;
                goto loop_14;
            }
        }
    }
    vader_array_t* _a3_arr = vader_array_new(9u, 0u, 7u, 179u);
    l3 = (void*) _a3_arr;
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        vader_array_t* _pc40_hdr = (vader_array_t*) l3;
        size_t _pc40_len = _pc40_hdr->length;
        size_t _pc40_cap = (_pc40_hdr->offset == 0 && !vader_array_is_borrowed(_pc40_hdr) && _pc40_hdr->length >= _pc40_hdr->buf->length) ? _pc40_hdr->capacity : (size_t) 0;
        void* _pc40_slots = _pc40_hdr->buf->slots;
        loop_40: {
            if ((l4 < l1)) {
                vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
                if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                if ((size_t) l4 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l4);
                t2 = ((vader_array_t*) t0)->length;
                if (t2 == INT64_C(0)) {
                    l7 = ((int32_t) (size_t) l4);
                    if (VADER_LIKELY(_pc40_len < _pc40_cap)) {
                        ((int32_t*) _pc40_slots)[_pc40_len] = (int32_t) (l7);
                        _pc40_len += 1;
                    } else {
                        _pc40_hdr->length = _pc40_len;
                        if (_pc40_hdr->buf->length < _pc40_len) { _pc40_hdr->buf->length = _pc40_len; }
                        vader_array_push_i32((vader_array_t*) l3, l7);
                        _pc40_hdr = (vader_array_t*) l3;
                        _pc40_len = _pc40_hdr->length;
                        _pc40_cap = (_pc40_hdr->offset == 0 && !vader_array_is_borrowed(_pc40_hdr) && _pc40_hdr->length >= _pc40_hdr->buf->length) ? _pc40_hdr->capacity : (size_t) 0;
                        _pc40_slots = _pc40_hdr->buf->slots;
                    }
                }
                t1 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t1;
                goto loop_40;
            }
            _pc40_hdr->length = _pc40_len;
            if (_pc40_hdr->buf->length < _pc40_len) { _pc40_hdr->buf->length = _pc40_len; }
        }
    }
    l7 = ((int32_t) (size_t) l1);
    vader_array_t* _a5_arr = vader_array_new(2u, 0u, 13u, 9u);
    l6 = (void*) _a5_arr;
    t1 = (l1 + INT64_C(1));
    l4 = (size_t) (int64_t) t1;
    vader_array_t* _a6_arr = vader_array_repeat((vader_array_t*) l6, (size_t) l4);
    l6 = (void*) _a6_arr;
    vader_array_push_all((vader_array_t*) l6, (vader_array_t*) l2);
    vader_array_t* _a7_arr = vader_array_new(9u, 0u, 7u, 179u);
    l2 = (void*) _a7_arr;
    vader_array_push((vader_array_t*) l6, vader_ref_box(l2));
    t1 = (l1 + INT64_C(1));
    l4 = (size_t) (int64_t) t1;
    vader_struct___lambda_env_vader_midir_7_t* _a8_obj = (vader_struct___lambda_env_vader_midir_7_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_midir_7_t));
    vader_obj_header_init(_a8_obj, 267u);
    t0 = (void*) _a8_obj;
    vader_fn_t* _a9_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
    vader_obj_header_init(_a9_closure, 144u);
    _a9_closure->code = (void*) &vader_fn_lift___lambda_vader_midir_6;
    _a9_closure->env = t0;
    l2 = (void*) _a9_closure;
    l2 = std_core_filled__i32__(l4, l2);
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_101: {
            if ((l4 < l1)) {
                vader_array_t* _a10_slotarr = ((vader_array_t*) l6);
                if (_a10_slotarr->buf != NULL && _a10_slotarr->buf->header.forward != NULL) { _a10_slotarr->buf = vader_array_buf_forward(_a10_slotarr->buf); }
                if ((size_t) l4 >= _a10_slotarr->length) { vader_trap("array index out of bounds"); }
                l8 = vader_array_ref_load_obj(_a10_slotarr->buf, _a10_slotarr->offset + (size_t) l4);
                l5 = ((vader_array_t*) l8)->length;
                l9 = (size_t) (int64_t) INT64_C(0);
                {
                    loop_115: {
                        if ((l9 < l5)) {
                            vader_array_t* _a11_slotarr = ((vader_array_t*) l8);
                            if (_a11_slotarr->buf != NULL && _a11_slotarr->buf->header.forward != NULL) { _a11_slotarr->buf = vader_array_buf_forward(_a11_slotarr->buf); }
                            if ((size_t) l9 >= _a11_slotarr->length) { vader_trap("array index out of bounds"); }
                            t3 = ((int32_t*) _a11_slotarr->buf->slots)[_a11_slotarr->offset + (size_t) l9];
                            t1 = ((int64_t) (int32_t) t3);
                            l10 = (size_t) (int64_t) t1;
                            vader_array_t* _a12_slotarr = ((vader_array_t*) l2);
                            if (_a12_slotarr->buf != NULL && _a12_slotarr->buf->header.forward != NULL) { _a12_slotarr->buf = vader_array_buf_forward(_a12_slotarr->buf); }
                            if ((size_t) l10 >= _a12_slotarr->length) { vader_trap("array index out of bounds"); }
                            l11 = vader_array_ref_load_obj(_a12_slotarr->buf, _a12_slotarr->offset + (size_t) l10);
                            l12 = ((int32_t) (size_t) l4);
                            vader_array_push_i32((vader_array_t*) l11, l12);
                            t1 = (l9 + INT64_C(1));
                            l9 = (size_t) (int64_t) t1;
                            goto loop_115;
                        }
                    }
                }
                t1 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t1;
                goto loop_101;
            }
        }
    }
    l4 = ((vader_array_t*) l3)->length;
    l5 = (size_t) (int64_t) INT64_C(0);
    {
        loop_157: {
            if ((l5 < l4)) {
                vader_array_t* _a13_slotarr = ((vader_array_t*) l3);
                if (_a13_slotarr->buf != NULL && _a13_slotarr->buf->header.forward != NULL) { _a13_slotarr->buf = vader_array_buf_forward(_a13_slotarr->buf); }
                if ((size_t) l5 >= _a13_slotarr->length) { vader_trap("array index out of bounds"); }
                l12 = ((int32_t*) _a13_slotarr->buf->slots)[_a13_slotarr->offset + (size_t) l5];
                t1 = ((int64_t) (int32_t) l12);
                l9 = (size_t) (int64_t) t1;
                vader_array_t* _a14_slotarr = ((vader_array_t*) l6);
                if (_a14_slotarr->buf != NULL && _a14_slotarr->buf->header.forward != NULL) { _a14_slotarr->buf = vader_array_buf_forward(_a14_slotarr->buf); }
                if ((size_t) l9 >= _a14_slotarr->length) { vader_trap("array index out of bounds"); }
                l8 = vader_array_ref_load_obj(_a14_slotarr->buf, _a14_slotarr->offset + (size_t) l9);
                l13 = l7;
                vader_array_push_i32((vader_array_t*) l8, l13);
                t1 = ((int64_t) (int32_t) l7);
                l10 = (size_t) (int64_t) t1;
                vader_array_t* _a15_slotarr = ((vader_array_t*) l2);
                if (_a15_slotarr->buf != NULL && _a15_slotarr->buf->header.forward != NULL) { _a15_slotarr->buf = vader_array_buf_forward(_a15_slotarr->buf); }
                if ((size_t) l10 >= _a15_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_ref_load_obj(_a15_slotarr->buf, _a15_slotarr->offset + (size_t) l10);
                vader_array_push_i32((vader_array_t*) t0, l12);
                t1 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t1;
                goto loop_157;
            }
        }
    }
    vader_array_t* _a16_arr = vader_array_new(9u, 0u, 7u, 179u);
    l3 = (void*) _a16_arr;
    vader_array_t* _a17_arr = vader_array_new(6u, 1u, 12u, 174u);
    ((uint8_t*) _a17_arr->buf->slots)[_a17_arr->offset + 0u] = (uint8_t) false;
    l8 = (void*) _a17_arr;
    t1 = (l1 + INT64_C(1));
    l4 = (size_t) (int64_t) t1;
    vader_array_t* _a18_arr = vader_array_repeat((vader_array_t*) l8, (size_t) l4);
    l8 = (void*) _a18_arr;
    l12 = l7;
    vader_midir_walk_rpo_reverse(l2, l12, l8, l3);
    vader_array_t* _a19_arr = vader_array_new(9u, 1u, 7u, 179u);
    ((int32_t*) _a19_arr->buf->slots)[_a19_arr->offset + 0u] = (int32_t) -(INT32_C(1));
    l2 = (void*) _a19_arr;
    t1 = (l1 + INT64_C(1));
    l4 = (size_t) (int64_t) t1;
    vader_array_t* _a20_arr = vader_array_repeat((vader_array_t*) l2, (size_t) l4);
    l2 = (void*) _a20_arr;
    t1 = ((int64_t) (int32_t) l7);
    l4 = (size_t) (int64_t) t1;
    vader_array_t* _a21_slotarr = ((vader_array_t*) l2);
    if (_a21_slotarr->buf != NULL && _a21_slotarr->buf->header.forward != NULL) { _a21_slotarr->buf = vader_array_buf_forward(_a21_slotarr->buf); }
    if ((size_t) l4 >= _a21_slotarr->length) { vader_trap("array index out of bounds"); }
    ((int32_t*) _a21_slotarr->buf->slots)[_a21_slotarr->offset + (size_t) l4] = (int32_t) l7;
    l14 = true;
    {
        loop_235: {
            if (l14) {
                l14 = false;
                t2 = ((vader_array_t*) l3)->length;
                l15 = (((int64_t) (size_t) t2) - INT64_C(1));
                {
                    loop_247: {
                        if ((l15 >= INT64_C(0))) {
                            t1 = l15;
                            l4 = (size_t) (int64_t) t1;
                            vader_array_t* _a22_slotarr = ((vader_array_t*) l3);
                            if (_a22_slotarr->buf != NULL && _a22_slotarr->buf->header.forward != NULL) { _a22_slotarr->buf = vader_array_buf_forward(_a22_slotarr->buf); }
                            if ((size_t) l4 >= _a22_slotarr->length) { vader_trap("array index out of bounds"); }
                            l12 = ((int32_t*) _a22_slotarr->buf->slots)[_a22_slotarr->offset + (size_t) l4];
                            l15 = (l15 - INT64_C(1));
                            if (l12 == l7) {
                                goto loop_247;
                            }
                            l13 = -(INT32_C(1));
                            t1 = ((int64_t) (int32_t) l12);
                            l5 = (size_t) (int64_t) t1;
                            vader_array_t* _a23_slotarr = ((vader_array_t*) l6);
                            if (_a23_slotarr->buf != NULL && _a23_slotarr->buf->header.forward != NULL) { _a23_slotarr->buf = vader_array_buf_forward(_a23_slotarr->buf); }
                            if ((size_t) l5 >= _a23_slotarr->length) { vader_trap("array index out of bounds"); }
                            l8 = vader_array_ref_load_obj(_a23_slotarr->buf, _a23_slotarr->offset + (size_t) l5);
                            l9 = ((vader_array_t*) l8)->length;
                            l10 = (size_t) (int64_t) INT64_C(0);
                            {
                                loop_284: {
                                    if ((l10 < l9)) {
                                        vader_array_t* _a24_slotarr = ((vader_array_t*) l8);
                                        if (_a24_slotarr->buf != NULL && _a24_slotarr->buf->header.forward != NULL) { _a24_slotarr->buf = vader_array_buf_forward(_a24_slotarr->buf); }
                                        if ((size_t) l10 >= _a24_slotarr->length) { vader_trap("array index out of bounds"); }
                                        l16 = ((int32_t*) _a24_slotarr->buf->slots)[_a24_slotarr->offset + (size_t) l10];
                                        t1 = ((int64_t) (int32_t) l16);
                                        l17 = (size_t) (int64_t) t1;
                                        vader_array_t* _a25_slotarr = ((vader_array_t*) l2);
                                        if (_a25_slotarr->buf != NULL && _a25_slotarr->buf->header.forward != NULL) { _a25_slotarr->buf = vader_array_buf_forward(_a25_slotarr->buf); }
                                        if ((size_t) l17 >= _a25_slotarr->length) { vader_trap("array index out of bounds"); }
                                        l18 = ((int32_t*) _a25_slotarr->buf->slots)[_a25_slotarr->offset + (size_t) l17];
                                        l19 = -(INT32_C(1));
                                        if (l18 == l19) {
                                            t1 = (l10 + INT64_C(1));
                                            l10 = (size_t) (int64_t) t1;
                                            goto loop_284;
                                        }
                                        l20 = -(INT32_C(1));
                                        if (l13 == l20) {
                                            l13 = l16;
                                        } else {
                                            l21 = l13;
                                            l13 = vader_midir_intersect_dom_tree(l16, l21, l2);
                                        }
                                        t1 = (l10 + INT64_C(1));
                                        l10 = (size_t) (int64_t) t1;
                                        goto loop_284;
                                    }
                                }
                            }
                            l22 = -(INT32_C(1));
                            if (l13 != l22) {
                                t1 = ((int64_t) (int32_t) l12);
                                l24 = (size_t) (int64_t) t1;
                                vader_array_t* _a26_slotarr = ((vader_array_t*) l2);
                                if (_a26_slotarr->buf != NULL && _a26_slotarr->buf->header.forward != NULL) { _a26_slotarr->buf = vader_array_buf_forward(_a26_slotarr->buf); }
                                if ((size_t) l24 >= _a26_slotarr->length) { vader_trap("array index out of bounds"); }
                                t3 = ((int32_t*) _a26_slotarr->buf->slots)[_a26_slotarr->offset + (size_t) l24];
                                l23 = t3 != l13;
                            } else {
                                l23 = false;
                            }
                            if (l23) {
                                t1 = ((int64_t) (int32_t) l12);
                                l25 = (size_t) (int64_t) t1;
                                vader_array_t* _a27_slotarr = ((vader_array_t*) l2);
                                if (_a27_slotarr->buf != NULL && _a27_slotarr->buf->header.forward != NULL) { _a27_slotarr->buf = vader_array_buf_forward(_a27_slotarr->buf); }
                                if ((size_t) l25 >= _a27_slotarr->length) { vader_trap("array index out of bounds"); }
                                ((int32_t*) _a27_slotarr->buf->slots)[_a27_slotarr->offset + (size_t) l25] = (int32_t) l13;
                                l14 = true;
                            }
                            goto loop_247;
                        }
                    }
                }
                goto loop_235;
            }
        }
    }
    vader_array_t* _a28_arr = vader_array_new(9u, 0u, 7u, 179u);
    t0 = (void*) _a28_arr;
    vader_array_t* _a29_arr = vader_array_repeat((vader_array_t*) t0, (size_t) l1);
    l3 = (void*) _a29_arr;
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_385: {
            if ((l4 < l1)) {
                vader_array_t* _a30_slotarr = ((vader_array_t*) l2);
                if (_a30_slotarr->buf != NULL && _a30_slotarr->buf->header.forward != NULL) { _a30_slotarr->buf = vader_array_buf_forward(_a30_slotarr->buf); }
                if ((size_t) l4 >= _a30_slotarr->length) { vader_trap("array index out of bounds"); }
                l12 = ((int32_t*) _a30_slotarr->buf->slots)[_a30_slotarr->offset + (size_t) l4];
                if (l12 == l7) {
                    l13 = -(INT32_C(1));
                    vader_array_push_i32((vader_array_t*) l3, l13);
                } else {
                    vader_array_push_i32((vader_array_t*) l3, l12);
                }
                t1 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t1;
                goto loop_385;
            }
        }
    }
    { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static int32_t vader_midir_cond_branch_merge(void* l0, int32_t l1, void* l2, int32_t l3) {
    void* l4 = NULL;
    size_t l5, l11;
    int32_t l6, l7;
    bool l8;
    vader_string_t l9 = 0;
    vader_string_t l10 = 0;
    int64_t l12;
    int64_t t0;
    bool t1;
    size_t t2;
    vader_string_t t3 = 0;
    void* t4 = NULL;
    void** gc_raw_roots[4] = { &l0, &l2, &l4, &t4 };
    vader_string_t* gc_atom_roots[3] = { &l9, &l10, &t3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l4 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_ipostdom;
    t0 = ((int64_t) (int32_t) l1);
    l5 = (size_t) (int64_t) t0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    if ((size_t) l5 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
    l6 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l5];
    if ((l6 >= INT32_C(0))) {
        t1 = std_collections_MutableSet_Contains_contains__i32(((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_wrapped_loop_headers, l6);
        if (t1) {
            { int32_t __vret = -(INT32_C(1)); vader_gc_top = gc_frame.prev; return __vret; }
        }
        { int32_t __vret = l6; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l6 = ((vader_struct_vader_midir_TermCondBranch_t*) l2)->f_join;
    if ((l6 >= INT32_C(0))) {
        t2 = ((vader_array_t*) ((vader_struct_vader_midir_CFGFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_fn_)->f_blocks)->length;
        l7 = ((int32_t) (size_t) t2);
        if ((l6 >= l7)) {
            l8 = true;
        } else {
            l7 = l1;
            l8 = l6 == l7;
        }
        if (l8) {
            l9 = ((vader_struct_vader_midir_CFGFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_fn_)->f_mangled;
            l10 = vader_vt_Display__to_string(vader_box_i32(179u, l1));
            l5 = vader_host_std_core_byte_len(l9);
            l11 = vader_host_std_core_byte_len(l10);
            t0 = (l5 + l11);
            l5 = (size_t) (int64_t) t0;
            l4 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(84) + l5));
            l5 = (size_t) (int64_t) INT64_C(0);
            l5 = std_core_write_string_at(l4, l5, 1935u);
            l5 = std_core_write_string_at(l4, l5, l9);
            l5 = std_core_write_string_at(l4, l5, 292u);
            l5 = std_core_write_string_at(l4, l5, l10);
            l5 = std_core_write_string_at(l4, l5, 237u);
            l12 = ((int64_t) (int32_t) l6);
            l5 = std_core_write_int(l4, l5, l12);
            l5 = std_core_write_string_at(l4, l5, 143u);
            t3 = std_core_finish_buffer(l4, l5);
            vader_host_std_abort_panic(t3);
        }
        l4 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_preds;
        t0 = ((int64_t) (int32_t) l6);
        l5 = (size_t) (int64_t) t0;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l4);
        if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
        if ((size_t) l5 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
        t4 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5);
        t2 = ((vader_array_t*) t4)->length;
        if (t2 == INT64_C(0)) {
            { int32_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
        }
        t1 = std_collections_MutableSet_Contains_contains__i32(((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_wrapped_loop_headers, l6);
        if (t1) {
            { int32_t __vret = -(INT32_C(1)); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l7 = l6;
        t1 = vader_midir_loop_scope_targets(l0, l7);
        if (t1) {
            { int32_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
        }
        { int32_t __vret = l6; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { int32_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
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
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 12u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(131u, 0u, 13u, 1123u);
    l1 = (void*) _a0_arr;
    l2 = l0;
    l3 = ((vader_array_t*) l2)->length;
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_9: {
            if ((l4 < l3)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l4 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                l5 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
                if (l5.tag == 795u) {
                    t0 = l5.payload.obj;
                    l6 = ((vader_struct_vader_lower_StrDataPoolEntry_t*) t0)->f_values;
                    t0 = l5.payload.obj;
                    l7 = ((vader_struct_vader_lower_StrDataPoolEntry_t*) t0)->f_mutable;
                    vader_struct_vader_bytecode_BcStrData_t* _a2_obj = (vader_struct_vader_bytecode_BcStrData_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcStrData_t));
                    vader_obj_header_init(_a2_obj, 515u);
                    _a2_obj->f_values = l6;
                    _a2_obj->f_mutable = l7;
                    l8 = (void*) _a2_obj;
                    vader_array_push((vader_array_t*) l1, vader_ref_box(l8));
                } else {
                    if (l5.tag == 793u) {
                        vader_array_t* _a3_arr = vader_array_new(14u, 0u, 4u, 185u);
                        l9 = (void*) _a3_arr;
                        t0 = l5.payload.obj;
                        l10 = ((vader_struct_vader_lower_PrimDataPoolEntry_t*) t0)->f_items;
                        l11 = ((vader_array_t*) l10)->length;
                        l12 = (size_t) (int64_t) INT64_C(0);
                        {
                            vader_array_t* _pc51_hdr = (vader_array_t*) l9;
                            size_t _pc51_len = _pc51_hdr->length;
                            size_t _pc51_cap = (_pc51_hdr->offset == 0 && !vader_array_is_borrowed(_pc51_hdr) && _pc51_hdr->length >= _pc51_hdr->buf->length) ? _pc51_hdr->capacity : (size_t) 0;
                            void* _pc51_slots = _pc51_hdr->buf->slots;
                            loop_51: {
                                if ((l12 < l11)) {
                                    vader_array_t* _a4_slotarr = ((vader_array_t*) l10);
                                    if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                                    if ((size_t) l12 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                                    t1 = ((int64_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l12];
                                    t2 = t1;
                                    l13 = (uint64_t) (int64_t) t2;
                                    if (VADER_LIKELY(_pc51_len < _pc51_cap)) {
                                        ((int64_t*) _pc51_slots)[_pc51_len] = (int64_t) ((int64_t) (uint64_t) l13);
                                        _pc51_len += 1;
                                    } else {
                                        _pc51_hdr->length = _pc51_len;
                                        if (_pc51_hdr->buf->length < _pc51_len) { _pc51_hdr->buf->length = _pc51_len; }
                                        vader_array_push_i64((vader_array_t*) l9, (int64_t) (uint64_t) l13);
                                        _pc51_hdr = (vader_array_t*) l9;
                                        _pc51_len = _pc51_hdr->length;
                                        _pc51_cap = (_pc51_hdr->offset == 0 && !vader_array_is_borrowed(_pc51_hdr) && _pc51_hdr->length >= _pc51_hdr->buf->length) ? _pc51_hdr->capacity : (size_t) 0;
                                        _pc51_slots = _pc51_hdr->buf->slots;
                                    }
                                    t1 = (l12 + INT64_C(1));
                                    l12 = (size_t) (int64_t) t1;
                                    goto loop_51;
                                }
                                _pc51_hdr->length = _pc51_len;
                                if (_pc51_hdr->buf->length < _pc51_len) { _pc51_hdr->buf->length = _pc51_len; }
                            }
                        }
                        t0 = l5.payload.obj;
                        t3 = ((vader_struct_vader_lower_PrimDataPoolEntry_t*) t0)->f_element_type_name;
                        l14 = vader_bytecode_array_kind_from_name(t3);
                        t0 = l5.payload.obj;
                        l15 = ((vader_struct_vader_lower_PrimDataPoolEntry_t*) t0)->f_mutable;
                        vader_struct_vader_bytecode_BcPrimData_t* _a5_obj = (vader_struct_vader_bytecode_BcPrimData_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcPrimData_t));
                        vader_obj_header_init(_a5_obj, 511u);
                        _a5_obj->f_kind = l14;
                        _a5_obj->f_items = l9;
                        _a5_obj->f_mutable = l15;
                        l16 = (void*) _a5_obj;
                        vader_array_push((vader_array_t*) l1, vader_ref_box(l16));
                    } else {
                        if (l5.tag == 710u) {
                            vader_array_t* _a6_arr = vader_array_new(133u, 0u, 13u, 1130u);
                            l17 = (void*) _a6_arr;
                            t0 = l5.payload.obj;
                            l18 = ((vader_struct_vader_lower_LoweredArrayLit_t*) ((vader_struct_vader_lower_AggregateDataPoolEntry_t*) t0)->f_literal)->f_elements;
                            l19 = ((vader_array_t*) l18)->length;
                            l20 = (size_t) (int64_t) INT64_C(0);
                            {
                                loop_107: {
                                    if ((l20 < l19)) {
                                        vader_array_t* _a7_slotarr = ((vader_array_t*) l18);
                                        if (_a7_slotarr->buf != NULL && _a7_slotarr->buf->header.forward != NULL) { _a7_slotarr->buf = vader_array_buf_forward(_a7_slotarr->buf); }
                                        if ((size_t) l20 >= _a7_slotarr->length) { vader_trap("array index out of bounds"); }
                                        t4 = vader_array_ref_load_box(_a7_slotarr->buf, _a7_slotarr->offset + (size_t) l20);
                                        l21 = vader_midir_lowered_to_bc_value(t4);
                                        vader_array_push((vader_array_t*) l17, l21);
                                        t1 = (l20 + INT64_C(1));
                                        l20 = (size_t) (int64_t) t1;
                                        goto loop_107;
                                    }
                                }
                            }
                            t0 = l5.payload.obj;
                            l22 = ((vader_struct_vader_lower_AggregateDataPoolEntry_t*) t0)->f_element_type_name;
                            t0 = l5.payload.obj;
                            l23 = ((vader_struct_vader_lower_AggregateDataPoolEntry_t*) t0)->f_mutable;
                            vader_struct_vader_bytecode_BcAggregateData_t* _a8_obj = (vader_struct_vader_bytecode_BcAggregateData_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcAggregateData_t));
                            vader_obj_header_init(_a8_obj, 502u);
                            _a8_obj->f_element_type_name = l22;
                            _a8_obj->f_elements = l17;
                            _a8_obj->f_mutable = l23;
                            l24 = (void*) _a8_obj;
                            vader_array_push((vader_array_t*) l1, vader_ref_box(l24));
                        } else {
                            vader_unreachable("unreachable return in vader_midir$convert_data_pool");
                        }
                    }
                }
                t1 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t1;
                goto loop_9;
            }
        }
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static bool vader_midir_convert_eligible(uint8_t l0) {
    bool l1;
    if (l0 == INT32_C(0)) {
        l1 = true;
    } else {
        if (l0 == INT32_C(1)) {
            l1 = true;
        } else {
            if (l0 == INT32_C(2)) {
                l1 = true;
            } else {
                if (l0 == INT32_C(3)) {
                    l1 = true;
                } else {
                    if (l0 == INT32_C(4)) {
                        l1 = true;
                    } else {
                        if (l0 == INT32_C(5)) {
                            l1 = true;
                        } else {
                            if (l0 == INT32_C(6)) {
                                l1 = true;
                            } else {
                                if (l0 == INT32_C(7)) {
                                    l1 = true;
                                } else {
                                    if (l0 == INT32_C(8)) {
                                        l1 = true;
                                    } else {
                                        if (l0 == INT32_C(9)) {
                                            l1 = true;
                                        } else {
                                            if (l0 == INT32_C(10)) {
                                                l1 = true;
                                            } else {
                                                if (l0 == INT32_C(11)) {
                                                    l1 = true;
                                                } else {
                                                    if (l0 == INT32_C(12)) {
                                                        l1 = false;
                                                    } else {
                                                        if (l0 == INT32_C(13)) {
                                                            l1 = true;
                                                        } else {
                                                            if (l0 == INT32_C(14)) {
                                                                l1 = false;
                                                            } else {
                                                                if (l0 == INT32_C(15)) {
                                                                    l1 = false;
                                                                } else {
                                                                    if (l0 == INT32_C(16)) {
                                                                        l1 = false;
                                                                    } else {
                                                                        if (l0 == INT32_C(17)) {
                                                                            l1 = false;
                                                                        } else {
                                                                            if (l0 == INT32_C(18)) {
                                                                                l1 = false;
                                                                            } else {
                                                                                if (l0 == INT32_C(19)) {
                                                                                    l1 = false;
                                                                                } else {
                                                                                    vader_unreachable("unreachable return in vader_midir$convert_eligible");
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

static vader_box_t vader_midir_convert_function(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    void* l18 = NULL;
    void* l21 = NULL;
    size_t l8, l9;
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
    void** gc_raw_roots[13] = { &l0, &l1, &l2, &l3, &l4, &l5, &l6, &l7, &l13, &l14, &l18, &l21, &t4 };
    vader_string_t* gc_atom_roots[2] = { &l11, &l17 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 13u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    if (((vader_struct_vader_lower_LoweredFnDecl_t*) l0)->f_body.tag == 0u) {
        t0 = vader_box_obj(0u, NULL);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_vader_lower_LoweredFnDecl_t*) l0)->f_body;
    l2 = t0.payload.obj;
    vader_array_t* _a0_arr = vader_array_new(79u, 0u, 13u, 807u);
    l3 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(77u, 0u, 13u, 805u);
    l4 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 179u);
    l5 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(9u, 0u, 7u, 179u);
    l6 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_new(9u, 0u, 7u, 179u);
    l7 = (void*) _a4_arr;
    vader_struct_std_collections_MutableMap__i32__i32_t* _a5_obj = (vader_struct_std_collections_MutableMap__i32__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__i32_t));
    vader_obj_header_init(_a5_obj, 317u);
    _a5_obj->f_ekeys = l5;
    _a5_obj->f_evals = l6;
    _a5_obj->f_index = l7;
    _a5_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a5_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a5_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l5 = (void*) _a5_obj;
    l6 = ((vader_struct_vader_lower_LoweredFnDecl_t*) l0)->f_params;
    l8 = ((vader_array_t*) l6)->length;
    l9 = (size_t) (int64_t) INT64_C(0);
    {
        loop_34: {
            if ((l9 < l8)) {
                vader_array_t* _a6_slotarr = ((vader_array_t*) l6);
                if (_a6_slotarr->buf != NULL && _a6_slotarr->buf->header.forward != NULL) { _a6_slotarr->buf = vader_array_buf_forward(_a6_slotarr->buf); }
                if ((size_t) l9 >= _a6_slotarr->length) { vader_trap("array index out of bounds"); }
                l7 = vader_array_ref_load_obj(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l9);
                t1 = ((vader_array_t*) l4)->length;
                l10 = ((int32_t) (size_t) t1);
                l11 = ((vader_struct_vader_lower_LoweredParam_t*) l7)->f_name;
                l12 = ((vader_struct_vader_lower_LoweredParam_t*) l7)->f_type;
                l13 = ((vader_struct_vader_lower_LoweredParam_t*) l7)->f_symbol;
                vader_struct_vader_midir_CFGLocal_t* _a7_obj = (vader_struct_vader_midir_CFGLocal_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_CFGLocal_t));
                vader_obj_header_init(_a7_obj, 805u);
                _a7_obj->f_name = l11;
                _a7_obj->f_type = l12;
                _a7_obj->f_symbol = vader_ref_box(l13);
                l14 = (void*) _a7_obj;
                vader_array_push((vader_array_t*) l4, vader_ref_box(l14));
                l15 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_lower_LoweredParam_t*) l7)->f_symbol)->f_id;
                l16 = l10;
                std_collections_MutableMap_IndexSet_set_at__i32__i32(l5, l15, l16);
                l17 = ((vader_struct_vader_lower_LoweredParam_t*) l7)->f_name;
                l18 = ((vader_struct_vader_lower_LoweredParam_t*) l7)->f_symbol;
                l19 = ((vader_struct_vader_lower_LoweredParam_t*) l7)->f_type;
                l20 = l10;
                vader_struct_vader_midir_CFGParam_t* _a8_obj = (vader_struct_vader_midir_CFGParam_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_CFGParam_t));
                vader_obj_header_init(_a8_obj, 807u);
                _a8_obj->f_name = l17;
                _a8_obj->f_symbol = l18;
                _a8_obj->f_type = l19;
                _a8_obj->f_local = l20;
                l21 = (void*) _a8_obj;
                vader_array_push((vader_array_t*) l3, vader_ref_box(l21));
                t2 = (l9 + INT64_C(1));
                l9 = (size_t) (int64_t) t2;
                goto loop_34;
            }
        }
    }
    l11 = ((vader_struct_vader_lower_LoweredFnDecl_t*) l0)->f_mangled;
    l6 = ((vader_struct_vader_lower_LoweredFnDecl_t*) l0)->f_origin;
    l12 = ((vader_struct_vader_lower_LoweredFnDecl_t*) l0)->f_return_type;
    vader_array_t* _a9_arr = vader_array_new(84u, 0u, 13u, 855u);
    l7 = (void*) _a9_arr;
    vader_array_t* _a10_arr = vader_array_new(83u, 0u, 13u, 854u);
    l13 = (void*) _a10_arr;
    vader_struct_vader_midir_FnCtx_t* _a11_obj = (vader_struct_vader_midir_FnCtx_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_FnCtx_t));
    vader_obj_header_init(_a11_obj, 820u);
    _a11_obj->f_project = l1;
    _a11_obj->f_mangled = l11;
    _a11_obj->f_origin = l6;
    _a11_obj->f_return_type = l12;
    _a11_obj->f_params = l3;
    _a11_obj->f_locals = l4;
    _a11_obj->f_local_by_sym_id = l5;
    _a11_obj->f_blocks = l7;
    _a11_obj->f_loop_stack = l13;
    _a11_obj->f_current = vader_box_obj(0u, NULL);
    l4 = (void*) _a11_obj;
    l5 = ((vader_struct_vader_lower_LoweredBlock_t*) l2)->f_span;
    l10 = vader_midir_new_block(l4, l5);
    ((vader_struct_vader_midir_FnCtx_t*) l4)->f_current = vader_box_i32(179u, l10);
    VADER_WRITE_BARRIER((vader_struct_vader_midir_FnCtx_t*) l4);
    l12 = vader_midir_build_block_body(l4, l2);
    if (!(((vader_struct_vader_midir_FnCtx_t*) l4)->f_current.tag == 0u)) {
        l5 = ((vader_struct_vader_midir_FnCtx_t*) l4)->f_blocks;
        t2 = ((int64_t) ((vader_struct_vader_midir_FnCtx_t*) l4)->f_current.payload.i);
        l8 = (size_t) (int64_t) t2;
        vader_array_t* _a12_slotarr = ((vader_array_t*) l5);
        if (_a12_slotarr->buf != NULL && _a12_slotarr->buf->header.forward != NULL) { _a12_slotarr->buf = vader_array_buf_forward(_a12_slotarr->buf); }
        if ((size_t) l8 >= _a12_slotarr->length) { vader_trap("array index out of bounds"); }
        l5 = vader_array_ref_load_obj(_a12_slotarr->buf, _a12_slotarr->offset + (size_t) l8);
        if (((vader_struct_vader_midir_MutableBlock_t*) l5)->f_terminator.tag == 0u) {
            l2 = ((vader_struct_vader_lower_LoweredBlock_t*) l2)->f_span;
            if (l12.tag == 0u) {
                vader_array_t* _a13_arr = vader_array_new(9u, 0u, 7u, 179u);
                l6 = (void*) _a13_arr;
            } else {
                t3 = ((int32_t) l12.payload.i);
                vader_array_t* _a14_arr = vader_array_new(9u, 1u, 7u, 179u);
                ((int32_t*) _a14_arr->buf->slots)[_a14_arr->offset + 0u] = (int32_t) t3;
                l6 = (void*) _a14_arr;
            }
            vader_struct_vader_midir_TermReturn_t* _a15_obj = (vader_struct_vader_midir_TermReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_TermReturn_t));
            vader_obj_header_init(_a15_obj, 862u);
            _a15_obj->f_span = l2;
            _a15_obj->f_values = l6;
            l2 = (void*) _a15_obj;
            ((vader_struct_vader_midir_MutableBlock_t*) l5)->f_terminator = vader_ref_box(l2);
            VADER_WRITE_BARRIER((vader_struct_vader_midir_MutableBlock_t*) l5);
        }
    }
    l2 = vader_midir_fn_metadata(l0);
    vader_array_t* _a16_arr = vader_array_new(74u, 0u, 13u, 802u);
    l5 = (void*) _a16_arr;
    l6 = ((vader_struct_vader_midir_FnCtx_t*) l4)->f_blocks;
    l8 = ((vader_array_t*) l6)->length;
    l9 = (size_t) (int64_t) INT64_C(0);
    {
        loop_184: {
            if ((l9 < l8)) {
                vader_array_t* _a17_slotarr = ((vader_array_t*) l6);
                if (_a17_slotarr->buf != NULL && _a17_slotarr->buf->header.forward != NULL) { _a17_slotarr->buf = vader_array_buf_forward(_a17_slotarr->buf); }
                if ((size_t) l9 >= _a17_slotarr->length) { vader_trap("array index out of bounds"); }
                t4 = vader_array_ref_load_obj(_a17_slotarr->buf, _a17_slotarr->offset + (size_t) l9);
                l7 = vader_midir_freeze_block(t4);
                vader_array_push((vader_array_t*) l5, vader_ref_box(l7));
                t2 = (l9 + INT64_C(1));
                l9 = (size_t) (int64_t) t2;
                goto loop_184;
            }
        }
    }
    l11 = ((vader_struct_vader_lower_LoweredFnDecl_t*) l0)->f_mangled;
    l12 = ((vader_struct_vader_lower_LoweredFnDecl_t*) l0)->f_return_type;
    l4 = ((vader_struct_vader_midir_FnCtx_t*) l4)->f_locals;
    l6 = ((vader_struct_vader_lower_LoweredFnDecl_t*) l0)->f_origin;
    l17 = ((vader_struct_vader_midir_FnMetadata_t*) l2)->f_extern_name;
    l22 = ((vader_struct_vader_midir_FnMetadata_t*) l2)->f_is_extern;
    l23 = ((vader_struct_vader_midir_FnMetadata_t*) l2)->f_is_exported;
    vader_array_t* _a18_arr = vader_array_new(142u, 0u, 13u, 1246u);
    l2 = (void*) _a18_arr;
    vader_struct_vader_midir_CFGFunction_t* _a19_obj = (vader_struct_vader_midir_CFGFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_CFGFunction_t));
    vader_obj_header_init(_a19_obj, 804u);
    _a19_obj->f_mangled = l11;
    _a19_obj->f_params = l3;
    _a19_obj->f_return_type = l12;
    _a19_obj->f_locals = l4;
    _a19_obj->f_blocks = l5;
    _a19_obj->f_entry = l10;
    _a19_obj->f_origin = l6;
    _a19_obj->f_extern_name = l17;
    _a19_obj->f_is_extern = l22;
    _a19_obj->f_is_exported = l23;
    _a19_obj->f_scalarised_results = l2;
    t4 = (void*) _a19_obj;
    { vader_box_t __vret = vader_ref_box(t4); vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_midir_count_uses(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l7 = NULL;
    vader_box_t l4 = vader_box_null();
    size_t l5, l6, l8, l9;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    int64_t t2;
    vader_box_t* gc_roots[2] = { &l4, &t1 };
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l3, &l7, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 6u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(9u, 0u, 7u, 179u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(9u, 0u, 7u, 179u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 179u);
    l3 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__i32__i32_t* _a3_obj = (vader_struct_std_collections_MutableMap__i32__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__i32_t));
    vader_obj_header_init(_a3_obj, 317u);
    _a3_obj->f_ekeys = l1;
    _a3_obj->f_evals = l2;
    _a3_obj->f_index = l3;
    _a3_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    t0 = (void*) _a3_obj;
    vader_struct__Cell_Struct_std_collections_MutableMap_i32_i32__t* _a4_obj = (vader_struct__Cell_Struct_std_collections_MutableMap_i32_i32__t*) vader_gc_alloc(sizeof(vader_struct__Cell_Struct_std_collections_MutableMap_i32_i32__t));
    vader_obj_header_init(_a4_obj, 200u);
    _a4_obj->f_value = t0;
    t0 = (void*) _a4_obj;
    l4 = vader_ref_box(t0);
    vader_struct___lambda_env_vader_midir_9_t* _a5_obj = (vader_struct___lambda_env_vader_midir_9_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_midir_9_t));
    vader_obj_header_init(_a5_obj, 268u);
    _a5_obj->f_cap_0 = l4;
    t0 = (void*) _a5_obj;
    vader_fn_t* _a6_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
    vader_obj_header_init(_a6_closure, 151u);
    _a6_closure->code = (void*) &vader_fn_lift___lambda_vader_midir_8;
    _a6_closure->env = t0;
    l1 = (void*) _a6_closure;
    l2 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_blocks;
    l5 = ((vader_array_t*) l2)->length;
    l6 = (size_t) (int64_t) INT64_C(0);
    {
        loop_25: {
            if ((l6 < l5)) {
                vader_array_t* _a7_slotarr = ((vader_array_t*) l2);
                if (_a7_slotarr->buf != NULL && _a7_slotarr->buf->header.forward != NULL) { _a7_slotarr->buf = vader_array_buf_forward(_a7_slotarr->buf); }
                if ((size_t) l6 >= _a7_slotarr->length) { vader_trap("array index out of bounds"); }
                l3 = vader_array_ref_load_obj(_a7_slotarr->buf, _a7_slotarr->offset + (size_t) l6);
                l7 = ((vader_struct_vader_midir_BasicBlock_t*) l3)->f_instructions;
                l8 = ((vader_array_t*) l7)->length;
                l9 = (size_t) (int64_t) INT64_C(0);
                {
                    loop_41: {
                        if ((l9 < l8)) {
                            vader_array_t* _a8_slotarr = ((vader_array_t*) l7);
                            if (_a8_slotarr->buf != NULL && _a8_slotarr->buf->header.forward != NULL) { _a8_slotarr->buf = vader_array_buf_forward(_a8_slotarr->buf); }
                            if ((size_t) l9 >= _a8_slotarr->length) { vader_trap("array index out of bounds"); }
                            t1 = vader_array_ref_load_box(_a8_slotarr->buf, _a8_slotarr->offset + (size_t) l9);
                            vader_midir_for_each_read_local(t1, l1);
                            t2 = (l9 + INT64_C(1));
                            l9 = (size_t) (int64_t) t2;
                            goto loop_41;
                        }
                    }
                }
                vader_midir_for_each_read_in_terminator(((vader_struct_vader_midir_BasicBlock_t*) l3)->f_terminator, l1);
                t2 = (l6 + INT64_C(1));
                l6 = (size_t) (int64_t) t2;
                goto loop_25;
            }
        }
    }
    { void* __vret = ((vader_struct__Cell_Struct_std_collections_MutableMap_i32_i32__t*) l4.payload.obj)->f_value; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_box_t vader_midir_debug_pos_of_span(void* l0) {
    vader_string_t l1 = 0;
    int32_t l2, l3;
    bool t0;
    vader_box_t t1 = vader_box_null();
    void* t2 = NULL;
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[2] = { &l0, &t2 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = toolchain_span_has_source_position(l0);
    if (!(t0)) {
        t1 = vader_box_obj(0u, NULL);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l1 = ((vader_struct_toolchain_span_Position_t*) ((vader_struct_toolchain_span_Span_t*) l0)->f_start)->f_file;
    l2 = ((vader_struct_toolchain_span_Position_t*) ((vader_struct_toolchain_span_Span_t*) l0)->f_start)->f_line;
    l3 = ((vader_struct_toolchain_span_Position_t*) ((vader_struct_toolchain_span_Span_t*) l0)->f_start)->f_column;
    vader_struct_vader_bytecode_DebugPos_t* _a0_obj = (vader_struct_vader_bytecode_DebugPos_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_DebugPos_t));
    vader_obj_header_init(_a0_obj, 545u);
    _a0_obj->f_file = l1;
    _a0_obj->f_line = l2;
    _a0_obj->f_column = l3;
    t2 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static int32_t vader_midir_declare_local(void* l0, vader_string_t l1, vader_box_t l2, vader_box_t l3) {
    int32_t l4;
    void* l5 = NULL;
    void* l6 = NULL;
    size_t t0;
    vader_box_t* gc_roots[2] = { &l2, &l3 };
    void** gc_raw_roots[3] = { &l0, &l5, &l6 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_vader_midir_FnCtx_t*) l0)->f_locals)->length;
    l4 = ((int32_t) (size_t) t0);
    l5 = ((vader_struct_vader_midir_FnCtx_t*) l0)->f_locals;
    vader_struct_vader_midir_CFGLocal_t* _a0_obj = (vader_struct_vader_midir_CFGLocal_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_CFGLocal_t));
    vader_obj_header_init(_a0_obj, 805u);
    _a0_obj->f_name = l1;
    _a0_obj->f_type = l2;
    _a0_obj->f_symbol = l3;
    l6 = (void*) _a0_obj;
    vader_array_push((vader_array_t*) l5, vader_ref_box(l6));
    { int32_t __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void vader_midir_defer_or_resolve_branch(void* l0, int32_t l1, int32_t l2) {
    size_t l3, l6, l10;
    int64_t l4;
    void* l5 = NULL;
    void* l7 = NULL;
    void* l9 = NULL;
    bool l8;
    int32_t l11;
    int64_t t0;
    vader_string_t t1 = 0;
    int32_t t2;
    void* t3 = NULL;
    bool t4;
    void** gc_raw_roots[5] = { &l0, &l5, &l7, &l9, &t3 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l3 = ((vader_array_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_scopes)->length;
    l4 = (((int64_t) (size_t) l3) - INT64_C(1));
    {
        loop_8: {
            if ((l4 >= INT64_C(0))) {
                l5 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_scopes;
                t0 = l4;
                l6 = (size_t) (int64_t) t0;
                vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
                if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                if ((size_t) l6 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                l7 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l6);
                t1 = ((vader_struct_vader_midir_ScopeFrame_t*) l7)->f_kind;
                if (t1 == 1905u) {
                    l8 = vader_midir_BlockId_Equals_equals(((vader_struct_vader_midir_ScopeFrame_t*) l7)->f_target_blk, l1);
                } else {
                    l8 = false;
                }
                if (l8) {
                    l9 = ((vader_struct_vader_bytecode_BcFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_slot)->f_jump_table;
                    t0 = ((int64_t) (int32_t) l2);
                    l10 = (size_t) (int64_t) t0;
                    t2 = ((vader_struct_vader_midir_ScopeFrame_t*) l7)->f_opener_pc;
                    l11 = (t2 + INT32_C(1));
                    vader_array_t* _a1_slotarr = ((vader_array_t*) l9);
                    if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                    if ((size_t) l10 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                    ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l10] = (int32_t) l11;
                    { vader_gc_top = gc_frame.prev; return; }
                }
                l4 = (l4 - INT64_C(1));
                goto loop_8;
            }
        }
    }
    l4 = (((int64_t) (size_t) l3) - INT64_C(1));
    {
        loop_68: {
            if ((l4 >= INT64_C(0))) {
                l5 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_scopes;
                t0 = l4;
                l3 = (size_t) (int64_t) t0;
                vader_array_t* _a2_slotarr = ((vader_array_t*) l5);
                if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                if ((size_t) l3 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                t3 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l3);
                t4 = vader_midir_BlockId_Equals_equals(((vader_struct_vader_midir_ScopeFrame_t*) t3)->f_target_blk, l1);
                if (t4) {
                    l7 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_pending;
                    vader_struct_vader_midir_PendingBranch_t* _a3_obj = (vader_struct_vader_midir_PendingBranch_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_PendingBranch_t));
                    vader_obj_header_init(_a3_obj, 856u);
                    _a3_obj->f_branch_pc = l2;
                    _a3_obj->f_target_blk = l1;
                    l9 = (void*) _a3_obj;
                    vader_array_push((vader_array_t*) l7, vader_ref_box(l9));
                    { vader_gc_top = gc_frame.prev; return; }
                }
                l4 = (l4 - INT64_C(1));
                goto loop_68;
            }
        }
    }
    l5 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_pending;
    vader_struct_vader_midir_PendingBranch_t* _a4_obj = (vader_struct_vader_midir_PendingBranch_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_PendingBranch_t));
    vader_obj_header_init(_a4_obj, 856u);
    _a4_obj->f_branch_pc = l2;
    _a4_obj->f_target_blk = l1;
    l7 = (void*) _a4_obj;
    vader_array_push((vader_array_t*) l5, vader_ref_box(l7));
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static bool vader_midir_dominates(void* l0, int32_t l1, int32_t l2) {
    int32_t l3, l4, l5, l6;
    bool t0;
    l3 = l2;
    {
        loop_3: {
            l4 = -(INT32_C(1));
            t0 = vader_midir_BlockId_Equals_equals(l3, l4);
            if (!(t0)) {
                t0 = vader_midir_BlockId_Equals_equals(l3, l1);
                if (t0) {
                    return true;
                }
                l5 = l3;
                vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
                if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                if ((size_t) l5 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                l6 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l5];
                t0 = vader_midir_BlockId_Equals_equals(l6, l3);
                if (t0) {
                    t0 = vader_midir_BlockId_Equals_equals(l3, l1);
                    return t0;
                }
                l3 = l6;
                goto loop_3;
            }
        }
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
    vader_array_t* _a0_arr = vader_array_new(85u, 0u, 13u, 856u);
    l6 = (void*) _a0_arr;
    l7 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_pending;
    l8 = ((vader_array_t*) l7)->length;
    l9 = (size_t) (int64_t) INT64_C(0);
    {
        loop_21: {
            if ((l9 < l8)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) l7);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l9 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                l10 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l9);
                t0 = vader_midir_BlockId_Equals_equals(((vader_struct_vader_midir_PendingBranch_t*) l10)->f_target_blk, l1);
                if (t0) {
                    l11 = ((vader_struct_vader_bytecode_BcFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_slot)->f_jump_table;
                    t1 = ((vader_struct_vader_midir_PendingBranch_t*) l10)->f_branch_pc;
                    t2 = ((int64_t) (int32_t) t1);
                    l12 = (size_t) (int64_t) t2;
                    vader_array_t* _a2_slotarr = ((vader_array_t*) l11);
                    if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                    if ((size_t) l12 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                    ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l12] = (int32_t) l5;
                } else {
                    vader_array_push((vader_array_t*) l6, vader_ref_box(l10));
                }
                t2 = (l9 + INT64_C(1));
                l9 = (size_t) (int64_t) t2;
                goto loop_21;
            }
        }
    }
    ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_pending = l6;
    VADER_WRITE_BARRIER((vader_struct_vader_midir_FnEmitCfg_t*) l0);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static vader_box_t vader_midir_dst_of(vader_box_t l0) {
    void* t0;
    vader_box_t t1;
    if (l0.tag == 836u) {
        t0 = l0.payload.obj;
        t1 = vader_box_i32(179u, ((vader_struct_vader_midir_InstrConst_t*) t0)->f_dst);
        return t1;
    }
    if (l0.tag == 846u) {
        t0 = l0.payload.obj;
        t1 = vader_box_i32(179u, ((vader_struct_vader_midir_InstrMove_t*) t0)->f_dst);
        return t1;
    }
    if (l0.tag == 829u) {
        t0 = l0.payload.obj;
        t1 = vader_box_i32(179u, ((vader_struct_vader_midir_InstrBinOp_t*) t0)->f_dst);
        return t1;
    }
    if (l0.tag == 851u) {
        t0 = l0.payload.obj;
        t1 = vader_box_i32(179u, ((vader_struct_vader_midir_InstrUnOp_t*) t0)->f_dst);
        return t1;
    }
    if (l0.tag == 840u) {
        t0 = l0.payload.obj;
        t1 = vader_box_i32(179u, ((vader_struct_vader_midir_InstrFieldGet_t*) t0)->f_dst);
        return t1;
    }
    if (l0.tag == 823u) {
        t0 = l0.payload.obj;
        t1 = vader_box_i32(179u, ((vader_struct_vader_midir_InstrArrayGet_t*) t0)->f_dst);
        return t1;
    }
    if (l0.tag == 824u) {
        t0 = l0.payload.obj;
        t1 = vader_box_i32(179u, ((vader_struct_vader_midir_InstrArrayLen_t*) t0)->f_dst);
        return t1;
    }
    if (l0.tag == 828u) {
        t0 = l0.payload.obj;
        t1 = vader_box_i32(179u, ((vader_struct_vader_midir_InstrArraySlice_t*) t0)->f_dst);
        return t1;
    }
    if (l0.tag == 847u) {
        t0 = l0.payload.obj;
        t1 = vader_box_i32(179u, ((vader_struct_vader_midir_InstrStringSlice_t*) t0)->f_dst);
        return t1;
    }
    if (l0.tag == 848u) {
        t0 = l0.payload.obj;
        t1 = vader_box_i32(179u, ((vader_struct_vader_midir_InstrStructNew_t*) t0)->f_dst);
        return t1;
    }
    if (l0.tag == 825u) {
        t0 = l0.payload.obj;
        t1 = vader_box_i32(179u, ((vader_struct_vader_midir_InstrArrayNew_t*) t0)->f_dst);
        return t1;
    }
    if (l0.tag == 849u) {
        t0 = l0.payload.obj;
        t1 = vader_box_i32(179u, ((vader_struct_vader_midir_InstrTypeCheck_t*) t0)->f_dst);
        return t1;
    }
    if (l0.tag == 850u) {
        t0 = l0.payload.obj;
        t1 = vader_box_i32(179u, ((vader_struct_vader_midir_InstrTypeConst_t*) t0)->f_dst);
        return t1;
    }
    if (l0.tag == 832u) {
        t0 = l0.payload.obj;
        t1 = vader_box_i32(179u, ((vader_struct_vader_midir_InstrCast_t*) t0)->f_dst);
        return t1;
    }
    if (l0.tag == 834u) {
        t0 = l0.payload.obj;
        t1 = vader_box_i32(179u, ((vader_struct_vader_midir_InstrCellNew_t*) t0)->f_dst);
        return t1;
    }
    if (l0.tag == 833u) {
        t0 = l0.payload.obj;
        t1 = vader_box_i32(179u, ((vader_struct_vader_midir_InstrCellGet_t*) t0)->f_dst);
        return t1;
    }
    if (l0.tag == 845u) {
        t0 = l0.payload.obj;
        t1 = vader_box_i32(179u, ((vader_struct_vader_midir_InstrMakeClosure_t*) t0)->f_dst);
        return t1;
    }
    if (l0.tag == 843u) {
        t0 = l0.payload.obj;
        t1 = vader_box_i32(179u, ((vader_struct_vader_midir_InstrFnRef_t*) t0)->f_dst);
        return t1;
    }
    if (l0.tag == 842u) {
        t0 = l0.payload.obj;
        t1 = vader_box_i32(179u, ((vader_struct_vader_midir_InstrFnAddr_t*) t0)->f_dst);
        return t1;
    }
    if (l0.tag == 837u) {
        t0 = l0.payload.obj;
        t1 = vader_box_i32(179u, ((vader_struct_vader_midir_InstrDataConst_t*) t0)->f_dst);
        return t1;
    }
    if (l0.tag == 830u) {
        t0 = l0.payload.obj;
        t1 = vader_midir_call_single_dst(t0);
        return t1;
    }
    if (l0.tag == 831u) {
        t0 = l0.payload.obj;
        return ((vader_struct_vader_midir_InstrCallIndirect_t*) t0)->f_dst;
    }
    if (l0.tag == 852u) {
        t0 = l0.payload.obj;
        return ((vader_struct_vader_midir_InstrVirtualCall_t*) t0)->f_dst;
    }
    if (l0.tag == 844u) {
        t0 = l0.payload.obj;
        return ((vader_struct_vader_midir_InstrIntrinsic_t*) t0)->f_dst;
    }
    if (l0.tag == 841u) {
        t1 = vader_box_obj(0u, NULL);
        return t1;
    }
    if (l0.tag == 827u) {
        t1 = vader_box_obj(0u, NULL);
        return t1;
    }
    if (l0.tag == 826u) {
        t1 = vader_box_obj(0u, NULL);
        return t1;
    }
    if (l0.tag == 835u) {
        t1 = vader_box_obj(0u, NULL);
        return t1;
    }
    if (l0.tag == 839u) {
        t1 = vader_box_obj(0u, NULL);
        return t1;
    }
    if (l0.tag == 838u) {
        t1 = vader_box_obj(0u, NULL);
        return t1;
    }
    vader_unreachable("unreachable return in vader_midir$dst_of");
}

void* vader_midir_eliminate_dead_cfg(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l8 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    void* l12 = NULL;
    void* l15 = NULL;
    void* l18 = NULL;
    void* l19 = NULL;
    void* l20 = NULL;
    size_t l5, l6, l13, l14;
    vader_string_t l7 = 0;
    vader_string_t l9 = 0;
    vader_string_t l16 = 0;
    vader_string_t l17 = 0;
    vader_box_t t0 = vader_box_null();
    int64_t t1;
    void* t2 = NULL;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[14] = { &l0, &l1, &l2, &l3, &l4, &l8, &l10, &l11, &l12, &l15, &l18, &l19, &l20, &t2 };
    vader_string_t* gc_atom_roots[4] = { &l7, &l9, &l16, &l17 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 14u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 176u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(16u, 0u, 0u, 187u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 179u);
    l3 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__string__Any_t* _a3_obj = (vader_struct_std_collections_MutableMap__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__Any_t));
    vader_obj_header_init(_a3_obj, 326u);
    _a3_obj->f_ekeys = l1;
    _a3_obj->f_evals = l2;
    _a3_obj->f_index = l3;
    _a3_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l1 = (void*) _a3_obj;
    l2 = ((vader_struct_vader_midir_CFGProject_t*) l0)->f_modules;
    l3 = ((vader_struct_std_collections_MutableMap__string__CFGModule_t*) l2)->f_ekeys;
    l4 = ((vader_struct_std_collections_MutableMap__string__CFGModule_t*) l2)->f_evals;
    l5 = ((vader_struct_std_collections_MutableMap__string__CFGModule_t*) l2)->f_size;
    l6 = (size_t) (int64_t) INT64_C(0);
    {
        loop_26: {
            if ((l6 >= l5)) {
            } else {
                vader_array_t* _a4_slotarr = ((vader_array_t*) l3);
                if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                if ((size_t) l6 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_box_slots(_a4_slotarr->buf)[_a4_slotarr->offset + (size_t) l6];
                l7 = t0.payload.s;
                vader_array_t* _a5_slotarr = ((vader_array_t*) l4);
                if (_a5_slotarr->buf != NULL && _a5_slotarr->buf->header.forward != NULL) { _a5_slotarr->buf = vader_array_buf_forward(_a5_slotarr->buf); }
                if ((size_t) l6 >= _a5_slotarr->length) { vader_trap("array index out of bounds"); }
                l2 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l6);
                vader_struct___Tuple_2_62f1db0066dc3143_t* _a6_obj = (vader_struct___Tuple_2_62f1db0066dc3143_t*) vader_gc_alloc(sizeof(vader_struct___Tuple_2_62f1db0066dc3143_t));
                vader_obj_header_init(_a6_obj, 216u);
                _a6_obj->f__0 = l7;
                _a6_obj->f__1 = l2;
                l8 = (void*) _a6_obj;
                l9 = ((vader_struct___Tuple_2_62f1db0066dc3143_t*) l8)->f__0;
                l10 = ((vader_struct___Tuple_2_62f1db0066dc3143_t*) l8)->f__1;
                t1 = (l6 + INT64_C(1));
                l6 = (size_t) (int64_t) t1;
                vader_array_t* _a7_arr = vader_array_new(76u, 0u, 13u, 804u);
                l11 = (void*) _a7_arr;
                l12 = ((vader_struct_vader_midir_CFGModule_t*) l10)->f_functions;
                l13 = ((vader_array_t*) l12)->length;
                l14 = (size_t) (int64_t) INT64_C(0);
                {
                    loop_63: {
                        if ((l14 < l13)) {
                            vader_array_t* _a8_slotarr = ((vader_array_t*) l12);
                            if (_a8_slotarr->buf != NULL && _a8_slotarr->buf->header.forward != NULL) { _a8_slotarr->buf = vader_array_buf_forward(_a8_slotarr->buf); }
                            if ((size_t) l14 >= _a8_slotarr->length) { vader_trap("array index out of bounds"); }
                            t2 = vader_array_ref_load_obj(_a8_slotarr->buf, _a8_slotarr->offset + (size_t) l14);
                            l15 = vader_midir_optimise_function(t2);
                            vader_array_push((vader_array_t*) l11, vader_ref_box(l15));
                            t1 = (l14 + INT64_C(1));
                            l14 = (size_t) (int64_t) t1;
                            goto loop_63;
                        }
                    }
                }
                l16 = ((vader_struct_vader_midir_CFGModule_t*) l10)->f_module_id;
                l17 = ((vader_struct_vader_midir_CFGModule_t*) l10)->f_display_path;
                l18 = ((vader_struct_vader_midir_CFGModule_t*) l10)->f_externs;
                l19 = ((vader_struct_vader_midir_CFGModule_t*) l10)->f_struct_decls;
                vader_struct_vader_midir_CFGModule_t* _a9_obj = (vader_struct_vader_midir_CFGModule_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_CFGModule_t));
                vader_obj_header_init(_a9_obj, 806u);
                _a9_obj->f_module_id = l16;
                _a9_obj->f_display_path = l17;
                _a9_obj->f_functions = l11;
                _a9_obj->f_externs = l18;
                _a9_obj->f_struct_decls = l19;
                l20 = (void*) _a9_obj;
                std_collections_MutableMap_IndexSet_set_at__string__Any(l1, l9, vader_ref_box(l20));
                goto loop_26;
            }
        }
    }
    l2 = l0;
    l3 = ((vader_struct_vader_midir_CFGProject_t*) l2)->f_vtable_entries;
    l4 = ((vader_struct_vader_midir_CFGProject_t*) l2)->f_strings;
    l8 = ((vader_struct_vader_midir_CFGProject_t*) l2)->f_data_pool;
    l2 = ((vader_struct_vader_midir_CFGProject_t*) l2)->f_trait_membership;
    vader_struct_vader_midir_CFGProject_t* _a10_obj = (vader_struct_vader_midir_CFGProject_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_CFGProject_t));
    vader_obj_header_init(_a10_obj, 808u);
    _a10_obj->f_modules = l1;
    _a10_obj->f_vtable_entries = l3;
    _a10_obj->f_strings = l4;
    _a10_obj->f_data_pool = l8;
    _a10_obj->f_trait_membership = l2;
    t2 = (void*) _a10_obj;
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
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
    if (((vader_struct_vader_midir_FnCtx_t*) l0)->f_current.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l2 = ((vader_struct_vader_midir_FnCtx_t*) l0)->f_blocks;
    t0 = ((int64_t) ((vader_struct_vader_midir_FnCtx_t*) l0)->f_current.payload.i);
    l3 = (size_t) (int64_t) t0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
    t1 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
    vader_array_push((vader_array_t*) ((vader_struct_vader_midir_MutableBlock_t*) t1)->f_instructions, l1);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static int32_t vader_midir_emit_block_contents(void* l0, int32_t l1, int32_t l2) {
    void* l3 = NULL;
    void* l11 = NULL;
    size_t l4, l5;
    vader_box_t l6 = vader_box_null(), l8 = vader_box_null();
    int64_t l7;
    int32_t l9;
    bool l10;
    int64_t t0;
    void* t1 = NULL;
    size_t t2;
    vader_box_t t3 = vader_box_null();
    bool t4;
    vader_string_t t5 = 0;
    int32_t t6;
    vader_box_t* gc_roots[3] = { &l6, &l8, &t3 };
    void** gc_raw_roots[4] = { &l0, &l3, &l11, &t1 };
    vader_string_t* gc_atom_roots[1] = { &t5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_midir_CFGFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_fn_)->f_blocks;
    t0 = ((int64_t) (int32_t) l1);
    l4 = (size_t) (int64_t) t0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    if ((size_t) l4 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
    l3 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
    l4 = ((vader_array_t*) ((vader_struct_vader_midir_BasicBlock_t*) l3)->f_instructions)->length;
    l5 = (size_t) (int64_t) INT64_C(0);
    {
        loop_16: {
            if ((l5 < l4)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_midir_BasicBlock_t*) l3)->f_instructions);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l5 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                l6 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5);
                l7 = vader_midir_pos_key(l1, l5);
                vader_midir_emit_instr(l0, l6, l7);
                t0 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t0;
                goto loop_16;
            }
        }
    }
    l6 = ((vader_struct_vader_midir_BasicBlock_t*) l3)->f_terminator;
    if (l6.tag == 862u) {
        t1 = l6.payload.obj;
        l8 = vader_midir_term_return_single(t1);
        t1 = l6.payload.obj;
        l4 = ((vader_array_t*) ((vader_struct_vader_midir_TermReturn_t*) t1)->f_values)->length;
        l5 = (size_t) (int64_t) INT64_C(0);
        {
            loop_57: {
                if ((l5 < l4)) {
                    t1 = l6.payload.obj;
                    vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_midir_TermReturn_t*) t1)->f_values);
                    if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                    if ((size_t) l5 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                    l9 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l5];
                    if (!(l8.tag == 0u)) {
                        l10 = std_collections_MutableSet_Contains_contains__i32(((vader_struct_vader_midir_ScheduleHints_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_hints)->f_skip_terminator_get, l1);
                    } else {
                        l10 = false;
                    }
                    if (!(l10)) {
                        t1 = l6.payload.obj;
                        l3 = ((vader_struct_vader_midir_TermReturn_t*) t1)->f_span;
                        vader_midir_emit_get(l0, l9, l3);
                    }
                    t1 = l6.payload.obj;
                    l11 = ((vader_struct_vader_midir_TermReturn_t*) t1)->f_span;
                    vader_midir_emit_return_boxing(l0, l9, l5, l11);
                    t0 = (l5 + INT64_C(1));
                    l5 = (size_t) (int64_t) t0;
                    goto loop_57;
                }
            }
        }
        l3 = ((vader_struct_vader_bytecode_BcFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_slot)->f_body;
        t2 = ((vader_array_t*) l3)->length;
        if ((t2 > INT64_C(0))) {
            t1 = l6.payload.obj;
            t3 = vader_midir_term_return_single(t1);
            l10 = !(t3.tag == 0u);
        } else {
            l10 = false;
        }
        if (l10) {
            t2 = ((vader_array_t*) l3)->length;
            t0 = (t2 - INT64_C(1));
            l4 = (size_t) (int64_t) t0;
            vader_array_t* _a3_slotarr = ((vader_array_t*) l3);
            if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
            if ((size_t) l4 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
            t3 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l4);
            l8 = vader_bytecode_const_op_of(t3);
            if (!(l8.tag == 0u)) {
                t2 = ((vader_array_t*) l3)->length;
                t0 = (t2 - INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                vader_struct_vader_bytecode_ReturnLit_t* _a4_obj = (vader_struct_vader_bytecode_ReturnLit_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_ReturnLit_t));
                vader_obj_header_init(_a4_obj, 630u);
                _a4_obj->f_value = l8;
                l11 = (void*) _a4_obj;
                vader_array_t* _a5_slotarr = ((vader_array_t*) l3);
                if (_a5_slotarr->buf != NULL && _a5_slotarr->buf->header.forward != NULL) { _a5_slotarr->buf = vader_array_buf_forward(_a5_slotarr->buf); }
                if ((size_t) l4 >= _a5_slotarr->length) { vader_trap("array index out of bounds"); }
                vader_array_ref_store(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l4, l11);
                VADER_WRITE_BARRIER(_a5_slotarr->buf);
                { int32_t __vret = -(INT32_C(1)); vader_gc_top = gc_frame.prev; return __vret; }
            }
        }
        vader_struct_vader_bytecode_Return_t* _a6_obj = (vader_struct_vader_bytecode_Return_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_Return_t));
        vader_obj_header_init(_a6_obj, 629u);
        l3 = (void*) _a6_obj;
        t1 = l6.payload.obj;
        l11 = ((vader_struct_vader_midir_TermReturn_t*) t1)->f_span;
        vader_midir_push_emit(l0, vader_ref_box(l3), l11);
        { int32_t __vret = -(INT32_C(1)); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l6.tag == 863u) {
        t1 = l6.payload.obj;
        t4 = ((vader_struct_vader_midir_TermUnreachable_t*) t1)->f_trap;
        if (t4) {
            t1 = l6.payload.obj;
            t5 = ((vader_struct_vader_midir_TermUnreachable_t*) t1)->f_reason;
            vader_struct_vader_bytecode_Unreachable_t* _a7_obj = (vader_struct_vader_bytecode_Unreachable_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_Unreachable_t));
            vader_obj_header_init(_a7_obj, 661u);
            _a7_obj->f_reason = t5;
            l3 = (void*) _a7_obj;
            t1 = l6.payload.obj;
            l11 = ((vader_struct_vader_midir_TermUnreachable_t*) t1)->f_span;
            vader_midir_push_emit(l0, vader_ref_box(l3), l11);
        } else {
            vader_struct_vader_bytecode_Return_t* _a8_obj = (vader_struct_vader_bytecode_Return_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_Return_t));
            vader_obj_header_init(_a8_obj, 629u);
            l3 = (void*) _a8_obj;
            t1 = l6.payload.obj;
            l11 = ((vader_struct_vader_midir_TermUnreachable_t*) t1)->f_span;
            vader_midir_push_emit(l0, vader_ref_box(l3), l11);
        }
        { int32_t __vret = -(INT32_C(1)); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l6.tag == 860u) {
        t1 = l6.payload.obj;
        t4 = vader_midir_BlockId_Equals_equals(((vader_struct_vader_midir_TermBranch_t*) t1)->f_target, l2);
        if (t4) {
            { int32_t __vret = -(INT32_C(1)); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t1 = l6.payload.obj;
        l9 = ((vader_struct_vader_midir_TermBranch_t*) t1)->f_target;
        t4 = vader_midir_scope_contains_target(l0, l9);
        if (t4) {
            t1 = l6.payload.obj;
            l3 = ((vader_struct_vader_midir_TermBranch_t*) t1)->f_span;
            t1 = l6.payload.obj;
            l9 = ((vader_struct_vader_midir_TermBranch_t*) t1)->f_target;
            vader_midir_cf_br(l0, l3, l9);
            { int32_t __vret = -(INT32_C(1)); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t1 = l6.payload.obj;
        { int32_t __vret = ((vader_struct_vader_midir_TermBranch_t*) t1)->f_target; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l6.tag == 861u) {
        l3 = l6.payload.obj;
        l9 = vader_midir_cond_branch_merge(l0, l1, l3, l2);
        l3 = l6.payload.obj;
        t6 = vader_midir_emit_cond(l0, l1, l3, l9);
        { int32_t __vret = t6; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { int32_t __vret = -(INT32_C(1)); vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

void* vader_midir_emit_bytecode_from_cfg(void* l0, vader_string_t l1, void* l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    void* l14 = NULL;
    void* l17 = NULL;
    void* l22 = NULL;
    void* l23 = NULL;
    void* l25 = NULL;
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
    size_t l7, l8, l12, l13, l15, l16, l18, l19;
    vader_string_t l9 = 0;
    vader_string_t l26 = 0;
    vader_string_t l41 = 0;
    vader_string_t l42 = 0;
    int32_t l20, l24;
    vader_box_t l21 = vader_box_null(), l27 = vader_box_null();
    bool l28;
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    int64_t t2;
    vader_string_t t3 = 0;
    bool t4;
    size_t t5;
    vader_box_t* gc_roots[3] = { &l21, &l27, &t0 };
    void** gc_raw_roots[26] = { &l0, &l2, &l3, &l4, &l5, &l6, &l10, &l11, &l14, &l17, &l22, &l23, &l25, &l29, &l30, &l31, &l32, &l33, &l34, &l35, &l36, &l37, &l38, &l39, &l40, &t1 };
    vader_string_t* gc_atom_roots[6] = { &l1, &l9, &l26, &l41, &l42, &t3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 26u, gc_roots, gc_raw_roots, 0u, NULL, 6u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l3 = vader_bytecode_new_emitter_ctx();
    l4 = ((vader_struct_vader_midir_CFGProject_t*) l0)->f_modules;
    l5 = ((vader_struct_std_collections_MutableMap__string__CFGModule_t*) l4)->f_ekeys;
    l6 = ((vader_struct_std_collections_MutableMap__string__CFGModule_t*) l4)->f_evals;
    l7 = ((vader_struct_std_collections_MutableMap__string__CFGModule_t*) l4)->f_size;
    l8 = (size_t) (int64_t) INT64_C(0);
    {
        loop_14: {
            if ((l8 >= l7)) {
            } else {
                vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
                if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                if ((size_t) l8 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l8];
                l9 = t0.payload.s;
                vader_array_t* _a1_slotarr = ((vader_array_t*) l6);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l8 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                l4 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l8);
                vader_struct___Tuple_2_62f1db0066dc3143_t* _a2_obj = (vader_struct___Tuple_2_62f1db0066dc3143_t*) vader_gc_alloc(sizeof(vader_struct___Tuple_2_62f1db0066dc3143_t));
                vader_obj_header_init(_a2_obj, 216u);
                _a2_obj->f__0 = l9;
                _a2_obj->f__1 = l4;
                t1 = (void*) _a2_obj;
                l10 = ((vader_struct___Tuple_2_62f1db0066dc3143_t*) t1)->f__1;
                t2 = (l8 + INT64_C(1));
                l8 = (size_t) (int64_t) t2;
                l11 = ((vader_struct_vader_midir_CFGModule_t*) l10)->f_functions;
                l12 = ((vader_array_t*) l11)->length;
                l13 = (size_t) (int64_t) INT64_C(0);
                {
                    loop_45: {
                        if ((l13 < l12)) {
                            vader_array_t* _a3_slotarr = ((vader_array_t*) l11);
                            if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                            if ((size_t) l13 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                            t1 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l13);
                            vader_midir_reserve_cfg_function(t1, l3);
                            t2 = (l13 + INT64_C(1));
                            l13 = (size_t) (int64_t) t2;
                            goto loop_45;
                        }
                    }
                }
                l14 = ((vader_struct_vader_midir_CFGModule_t*) l10)->f_externs;
                l15 = ((vader_array_t*) l14)->length;
                l16 = (size_t) (int64_t) INT64_C(0);
                {
                    loop_70: {
                        if ((l16 < l15)) {
                            vader_array_t* _a4_slotarr = ((vader_array_t*) l14);
                            if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                            if ((size_t) l16 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                            t1 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l16);
                            vader_midir_reserve_cfg_extern(t1, l3);
                            t2 = (l16 + INT64_C(1));
                            l16 = (size_t) (int64_t) t2;
                            goto loop_70;
                        }
                    }
                }
                l17 = ((vader_struct_vader_midir_CFGModule_t*) l10)->f_struct_decls;
                l18 = ((vader_array_t*) l17)->length;
                l19 = (size_t) (int64_t) INT64_C(0);
                {
                    loop_95: {
                        if ((l19 < l18)) {
                            vader_array_t* _a5_slotarr = ((vader_array_t*) l17);
                            if (_a5_slotarr->buf != NULL && _a5_slotarr->buf->header.forward != NULL) { _a5_slotarr->buf = vader_array_buf_forward(_a5_slotarr->buf); }
                            if ((size_t) l19 >= _a5_slotarr->length) { vader_trap("array index out of bounds"); }
                            t1 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l19);
                            vader_midir_reserve_cfg_struct(t1, l3);
                            t2 = (l19 + INT64_C(1));
                            l19 = (size_t) (int64_t) t2;
                            goto loop_95;
                        }
                    }
                }
                goto loop_14;
            }
        }
    }
    vader_midir_synthesise_cfg_intrinsic_wrappers(l0, l3);
    vader_array_t* _a6_arr = vader_array_new(9u, 0u, 7u, 179u);
    l4 = (void*) _a6_arr;
    l5 = ((vader_struct_vader_midir_CFGProject_t*) l0)->f_strings;
    l7 = ((vader_array_t*) l5)->length;
    l8 = (size_t) (int64_t) INT64_C(0);
    {
        loop_129: {
            if ((l8 < l7)) {
                vader_array_t* _a7_slotarr = ((vader_array_t*) l5);
                if (_a7_slotarr->buf != NULL && _a7_slotarr->buf->header.forward != NULL) { _a7_slotarr->buf = vader_array_buf_forward(_a7_slotarr->buf); }
                if ((size_t) l8 >= _a7_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_box_slots(_a7_slotarr->buf)[_a7_slotarr->offset + (size_t) l8];
                t3 = t0.payload.s;
                l20 = vader_bytecode_intern_string(t3, l3);
                vader_array_push_i32((vader_array_t*) l4, l20);
                t2 = (l8 + INT64_C(1));
                l8 = (size_t) (int64_t) t2;
                goto loop_129;
            }
        }
    }
    l5 = ((vader_struct_vader_midir_CFGProject_t*) l0)->f_data_pool;
    l7 = ((vader_array_t*) l5)->length;
    l8 = (size_t) (int64_t) INT64_C(0);
    {
        loop_159: {
            if ((l8 < l7)) {
                vader_array_t* _a8_slotarr = ((vader_array_t*) l5);
                if (_a8_slotarr->buf != NULL && _a8_slotarr->buf->header.forward != NULL) { _a8_slotarr->buf = vader_array_buf_forward(_a8_slotarr->buf); }
                if ((size_t) l8 >= _a8_slotarr->length) { vader_trap("array index out of bounds"); }
                l21 = vader_array_ref_load_box(_a8_slotarr->buf, _a8_slotarr->offset + (size_t) l8);
                if (l21.tag == 515u) {
                    t1 = l21.payload.obj;
                    l6 = ((vader_struct_vader_bytecode_BcStrData_t*) t1)->f_values;
                    l12 = ((vader_array_t*) l6)->length;
                    l13 = (size_t) (int64_t) INT64_C(0);
                    {
                        loop_179: {
                            if ((l13 < l12)) {
                                vader_array_t* _a9_slotarr = ((vader_array_t*) l6);
                                if (_a9_slotarr->buf != NULL && _a9_slotarr->buf->header.forward != NULL) { _a9_slotarr->buf = vader_array_buf_forward(_a9_slotarr->buf); }
                                if ((size_t) l13 >= _a9_slotarr->length) { vader_trap("array index out of bounds"); }
                                t0 = vader_array_box_slots(_a9_slotarr->buf)[_a9_slotarr->offset + (size_t) l13];
                                t3 = t0.payload.s;
                                vader_bytecode_intern_string(t3, l3);
                                t2 = (l13 + INT64_C(1));
                                l13 = (size_t) (int64_t) t2;
                                goto loop_179;
                            }
                        }
                    }
                } else {
                    if (l21.tag == 502u) {
                        t1 = l21.payload.obj;
                        l10 = ((vader_struct_vader_bytecode_BcAggregateData_t*) t1)->f_elements;
                        l15 = ((vader_array_t*) l10)->length;
                        l16 = (size_t) (int64_t) INT64_C(0);
                        {
                            loop_212: {
                                if ((l16 < l15)) {
                                    vader_array_t* _a10_slotarr = ((vader_array_t*) l10);
                                    if (_a10_slotarr->buf != NULL && _a10_slotarr->buf->header.forward != NULL) { _a10_slotarr->buf = vader_array_buf_forward(_a10_slotarr->buf); }
                                    if ((size_t) l16 >= _a10_slotarr->length) { vader_trap("array index out of bounds"); }
                                    t0 = vader_array_ref_load_box(_a10_slotarr->buf, _a10_slotarr->offset + (size_t) l16);
                                    vader_midir_intern_data_value_strings(t0, l3);
                                    t2 = (l16 + INT64_C(1));
                                    l16 = (size_t) (int64_t) t2;
                                    goto loop_212;
                                }
                            }
                        }
                    }
                }
                t2 = (l8 + INT64_C(1));
                l8 = (size_t) (int64_t) t2;
                goto loop_159;
            }
        }
    }
    l5 = ((vader_struct_vader_midir_CFGProject_t*) l0)->f_modules;
    l6 = ((vader_struct_std_collections_MutableMap__string__CFGModule_t*) l5)->f_ekeys;
    l10 = ((vader_struct_std_collections_MutableMap__string__CFGModule_t*) l5)->f_evals;
    l7 = ((vader_struct_std_collections_MutableMap__string__CFGModule_t*) l5)->f_size;
    l8 = (size_t) (int64_t) INT64_C(0);
    {
        loop_252: {
            if ((l8 >= l7)) {
            } else {
                vader_array_t* _a11_slotarr = ((vader_array_t*) l6);
                if (_a11_slotarr->buf != NULL && _a11_slotarr->buf->header.forward != NULL) { _a11_slotarr->buf = vader_array_buf_forward(_a11_slotarr->buf); }
                if ((size_t) l8 >= _a11_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_box_slots(_a11_slotarr->buf)[_a11_slotarr->offset + (size_t) l8];
                l9 = t0.payload.s;
                vader_array_t* _a12_slotarr = ((vader_array_t*) l10);
                if (_a12_slotarr->buf != NULL && _a12_slotarr->buf->header.forward != NULL) { _a12_slotarr->buf = vader_array_buf_forward(_a12_slotarr->buf); }
                if ((size_t) l8 >= _a12_slotarr->length) { vader_trap("array index out of bounds"); }
                l5 = vader_array_ref_load_obj(_a12_slotarr->buf, _a12_slotarr->offset + (size_t) l8);
                vader_struct___Tuple_2_62f1db0066dc3143_t* _a13_obj = (vader_struct___Tuple_2_62f1db0066dc3143_t*) vader_gc_alloc(sizeof(vader_struct___Tuple_2_62f1db0066dc3143_t));
                vader_obj_header_init(_a13_obj, 216u);
                _a13_obj->f__0 = l9;
                _a13_obj->f__1 = l5;
                t1 = (void*) _a13_obj;
                l11 = ((vader_struct___Tuple_2_62f1db0066dc3143_t*) t1)->f__1;
                t2 = (l8 + INT64_C(1));
                l8 = (size_t) (int64_t) t2;
                l14 = ((vader_struct_vader_midir_CFGModule_t*) l11)->f_functions;
                l12 = ((vader_array_t*) l14)->length;
                l13 = (size_t) (int64_t) INT64_C(0);
                {
                    loop_283: {
                        if ((l13 < l12)) {
                            vader_array_t* _a14_slotarr = ((vader_array_t*) l14);
                            if (_a14_slotarr->buf != NULL && _a14_slotarr->buf->header.forward != NULL) { _a14_slotarr->buf = vader_array_buf_forward(_a14_slotarr->buf); }
                            if ((size_t) l13 >= _a14_slotarr->length) { vader_trap("array index out of bounds"); }
                            l17 = vader_array_ref_load_obj(_a14_slotarr->buf, _a14_slotarr->offset + (size_t) l13);
                            t4 = ((vader_struct_vader_midir_CFGFunction_t*) l17)->f_is_extern;
                            if (t4) {
                                t2 = (l13 + INT64_C(1));
                                l13 = (size_t) (int64_t) t2;
                                goto loop_283;
                            }
                            l20 = -(INT32_C(1));
                            if (((vader_struct_vader_comptime_MonoEntry_t*) ((vader_struct_vader_midir_CFGFunction_t*) l17)->f_origin)->f_symbol.tag == 899u) {
                                l22 = ((vader_struct_vader_comptime_MonoEntry_t*) ((vader_struct_vader_midir_CFGFunction_t*) l17)->f_origin)->f_symbol.payload.obj;
                                l23 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l3)->f_function_index_by_symbol_id;
                                l24 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l22)->f_id;
                                l21 = std_collections_MutableMap_Index_at__i32__i32(l23, l24);
                                if (l21.tag == 179u) {
                                    l20 = ((int32_t) l21.payload.i);
                                }
                            }
                            if ((l20 < INT32_C(0))) {
                                l25 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l3)->f_function_index_by_mangle;
                                l26 = ((vader_struct_vader_midir_CFGFunction_t*) l17)->f_mangled;
                                l27 = std_collections_MutableMap_Index_at__string__i32(l25, l26);
                                if (l27.tag == 179u) {
                                    l20 = ((int32_t) l27.payload.i);
                                }
                            }
                            if ((l20 >= INT32_C(0))) {
                                l28 = ((vader_struct_vader_bytecode_EmitOptions_t*) l2)->f_want_debug;
                                vader_midir_emit_cfg_function_body(l17, l20, l3, l4, l28);
                            }
                            t2 = (l13 + INT64_C(1));
                            l13 = (size_t) (int64_t) t2;
                            goto loop_283;
                        }
                    }
                }
                goto loop_252;
            }
        }
    }
    t4 = ((vader_struct_vader_bytecode_EmitOptions_t*) l2)->f_optimize;
    if (t4) {
        l7 = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l3)->f_functions)->length;
        l8 = (size_t) (int64_t) INT64_C(0);
        {
            loop_383: {
                if ((l8 < l7)) {
                    vader_array_t* _a15_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l3)->f_functions);
                    if (_a15_slotarr->buf != NULL && _a15_slotarr->buf->header.forward != NULL) { _a15_slotarr->buf = vader_array_buf_forward(_a15_slotarr->buf); }
                    if ((size_t) l8 >= _a15_slotarr->length) { vader_trap("array index out of bounds"); }
                    t1 = vader_array_ref_load_obj(_a15_slotarr->buf, _a15_slotarr->offset + (size_t) l8);
                    t5 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) t1)->f_body)->length;
                    t2 = (t5 + INT64_C(1));
                    l12 = (size_t) (int64_t) t2;
                    {
                        loop_397: {
                            vader_array_t* _a16_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l3)->f_functions);
                            if (_a16_slotarr->buf != NULL && _a16_slotarr->buf->header.forward != NULL) { _a16_slotarr->buf = vader_array_buf_forward(_a16_slotarr->buf); }
                            if ((size_t) l8 >= _a16_slotarr->length) { vader_trap("array index out of bounds"); }
                            t1 = vader_array_ref_load_obj(_a16_slotarr->buf, _a16_slotarr->offset + (size_t) l8);
                            t5 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) t1)->f_body)->length;
                            if ((t5 < l12)) {
                                vader_array_t* _a17_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l3)->f_functions);
                                if (_a17_slotarr->buf != NULL && _a17_slotarr->buf->header.forward != NULL) { _a17_slotarr->buf = vader_array_buf_forward(_a17_slotarr->buf); }
                                if ((size_t) l8 >= _a17_slotarr->length) { vader_trap("array index out of bounds"); }
                                t1 = vader_array_ref_load_obj(_a17_slotarr->buf, _a17_slotarr->offset + (size_t) l8);
                                l12 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) t1)->f_body)->length;
                                l4 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l3)->f_functions;
                                if ((size_t) l8 >= _a17_slotarr->length) { vader_trap("array index out of bounds"); }
                                t1 = vader_array_ref_load_obj(_a17_slotarr->buf, _a17_slotarr->offset + (size_t) l8);
                                l5 = vader_bytecode_propagate_const_single_use(t1);
                                vader_array_t* _a18_slotarr = ((vader_array_t*) l4);
                                if (_a18_slotarr->buf != NULL && _a18_slotarr->buf->header.forward != NULL) { _a18_slotarr->buf = vader_array_buf_forward(_a18_slotarr->buf); }
                                if ((size_t) l8 >= _a18_slotarr->length) { vader_trap("array index out of bounds"); }
                                vader_array_ref_store(_a18_slotarr->buf, _a18_slotarr->offset + (size_t) l8, l5);
                                VADER_WRITE_BARRIER(_a18_slotarr->buf);
                                goto loop_397;
                            }
                        }
                    }
                    l6 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l3)->f_functions;
                    vader_array_t* _a19_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l3)->f_functions);
                    if (_a19_slotarr->buf != NULL && _a19_slotarr->buf->header.forward != NULL) { _a19_slotarr->buf = vader_array_buf_forward(_a19_slotarr->buf); }
                    if ((size_t) l8 >= _a19_slotarr->length) { vader_trap("array index out of bounds"); }
                    l10 = vader_array_ref_load_obj(_a19_slotarr->buf, _a19_slotarr->offset + (size_t) l8);
                    if ((size_t) l8 >= _a19_slotarr->length) { vader_trap("array index out of bounds"); }
                    t1 = vader_array_ref_load_obj(_a19_slotarr->buf, _a19_slotarr->offset + (size_t) l8);
                    l11 = vader_bytecode_run_bc_peephole(t1);
                    l14 = vader_midir_with_peephole_out(l10, l11);
                    vader_array_t* _a20_slotarr = ((vader_array_t*) l6);
                    if (_a20_slotarr->buf != NULL && _a20_slotarr->buf->header.forward != NULL) { _a20_slotarr->buf = vader_array_buf_forward(_a20_slotarr->buf); }
                    if ((size_t) l8 >= _a20_slotarr->length) { vader_trap("array index out of bounds"); }
                    vader_array_ref_store(_a20_slotarr->buf, _a20_slotarr->offset + (size_t) l8, l14);
                    VADER_WRITE_BARRIER(_a20_slotarr->buf);
                    l17 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l3)->f_functions;
                    vader_array_t* _a21_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l3)->f_functions);
                    if (_a21_slotarr->buf != NULL && _a21_slotarr->buf->header.forward != NULL) { _a21_slotarr->buf = vader_array_buf_forward(_a21_slotarr->buf); }
                    if ((size_t) l8 >= _a21_slotarr->length) { vader_trap("array index out of bounds"); }
                    l22 = vader_array_ref_load_obj(_a21_slotarr->buf, _a21_slotarr->offset + (size_t) l8);
                    if ((size_t) l8 >= _a21_slotarr->length) { vader_trap("array index out of bounds"); }
                    t1 = vader_array_ref_load_obj(_a21_slotarr->buf, _a21_slotarr->offset + (size_t) l8);
                    l23 = vader_bytecode_run_bc_const_fold_arith(t1);
                    l25 = vader_midir_with_peephole_out(l22, l23);
                    vader_array_t* _a22_slotarr = ((vader_array_t*) l17);
                    if (_a22_slotarr->buf != NULL && _a22_slotarr->buf->header.forward != NULL) { _a22_slotarr->buf = vader_array_buf_forward(_a22_slotarr->buf); }
                    if ((size_t) l8 >= _a22_slotarr->length) { vader_trap("array index out of bounds"); }
                    vader_array_ref_store(_a22_slotarr->buf, _a22_slotarr->offset + (size_t) l8, l25);
                    VADER_WRITE_BARRIER(_a22_slotarr->buf);
                    l29 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l3)->f_functions;
                    vader_array_t* _a23_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l3)->f_functions);
                    if (_a23_slotarr->buf != NULL && _a23_slotarr->buf->header.forward != NULL) { _a23_slotarr->buf = vader_array_buf_forward(_a23_slotarr->buf); }
                    if ((size_t) l8 >= _a23_slotarr->length) { vader_trap("array index out of bounds"); }
                    t1 = vader_array_ref_load_obj(_a23_slotarr->buf, _a23_slotarr->offset + (size_t) l8);
                    l30 = vader_bytecode_drop_dead_stores(t1);
                    vader_array_t* _a24_slotarr = ((vader_array_t*) l29);
                    if (_a24_slotarr->buf != NULL && _a24_slotarr->buf->header.forward != NULL) { _a24_slotarr->buf = vader_array_buf_forward(_a24_slotarr->buf); }
                    if ((size_t) l8 >= _a24_slotarr->length) { vader_trap("array index out of bounds"); }
                    vader_array_ref_store(_a24_slotarr->buf, _a24_slotarr->offset + (size_t) l8, l30);
                    VADER_WRITE_BARRIER(_a24_slotarr->buf);
                    l31 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l3)->f_functions;
                    vader_array_t* _a25_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l3)->f_functions);
                    if (_a25_slotarr->buf != NULL && _a25_slotarr->buf->header.forward != NULL) { _a25_slotarr->buf = vader_array_buf_forward(_a25_slotarr->buf); }
                    if ((size_t) l8 >= _a25_slotarr->length) { vader_trap("array index out of bounds"); }
                    l32 = vader_array_ref_load_obj(_a25_slotarr->buf, _a25_slotarr->offset + (size_t) l8);
                    if ((size_t) l8 >= _a25_slotarr->length) { vader_trap("array index out of bounds"); }
                    t1 = vader_array_ref_load_obj(_a25_slotarr->buf, _a25_slotarr->offset + (size_t) l8);
                    l33 = vader_bytecode_run_bc_return_lit_fold(t1);
                    l34 = vader_midir_with_peephole_out(l32, l33);
                    vader_array_t* _a26_slotarr = ((vader_array_t*) l31);
                    if (_a26_slotarr->buf != NULL && _a26_slotarr->buf->header.forward != NULL) { _a26_slotarr->buf = vader_array_buf_forward(_a26_slotarr->buf); }
                    if ((size_t) l8 >= _a26_slotarr->length) { vader_trap("array index out of bounds"); }
                    vader_array_ref_store(_a26_slotarr->buf, _a26_slotarr->offset + (size_t) l8, l34);
                    VADER_WRITE_BARRIER(_a26_slotarr->buf);
                    l35 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l3)->f_functions;
                    vader_array_t* _a27_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l3)->f_functions);
                    if (_a27_slotarr->buf != NULL && _a27_slotarr->buf->header.forward != NULL) { _a27_slotarr->buf = vader_array_buf_forward(_a27_slotarr->buf); }
                    if ((size_t) l8 >= _a27_slotarr->length) { vader_trap("array index out of bounds"); }
                    t1 = vader_array_ref_load_obj(_a27_slotarr->buf, _a27_slotarr->offset + (size_t) l8);
                    l36 = vader_bytecode_coalesce_slots(t1);
                    vader_array_t* _a28_slotarr = ((vader_array_t*) l35);
                    if (_a28_slotarr->buf != NULL && _a28_slotarr->buf->header.forward != NULL) { _a28_slotarr->buf = vader_array_buf_forward(_a28_slotarr->buf); }
                    if ((size_t) l8 >= _a28_slotarr->length) { vader_trap("array index out of bounds"); }
                    vader_array_ref_store(_a28_slotarr->buf, _a28_slotarr->offset + (size_t) l8, l36);
                    VADER_WRITE_BARRIER(_a28_slotarr->buf);
                    l37 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l3)->f_functions;
                    vader_array_t* _a29_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l3)->f_functions);
                    if (_a29_slotarr->buf != NULL && _a29_slotarr->buf->header.forward != NULL) { _a29_slotarr->buf = vader_array_buf_forward(_a29_slotarr->buf); }
                    if ((size_t) l8 >= _a29_slotarr->length) { vader_trap("array index out of bounds"); }
                    l38 = vader_array_ref_load_obj(_a29_slotarr->buf, _a29_slotarr->offset + (size_t) l8);
                    if ((size_t) l8 >= _a29_slotarr->length) { vader_trap("array index out of bounds"); }
                    t1 = vader_array_ref_load_obj(_a29_slotarr->buf, _a29_slotarr->offset + (size_t) l8);
                    l39 = vader_bytecode_strip_self_copies(t1);
                    l40 = vader_midir_with_peephole_out(l38, l39);
                    vader_array_t* _a30_slotarr = ((vader_array_t*) l37);
                    if (_a30_slotarr->buf != NULL && _a30_slotarr->buf->header.forward != NULL) { _a30_slotarr->buf = vader_array_buf_forward(_a30_slotarr->buf); }
                    if ((size_t) l8 >= _a30_slotarr->length) { vader_trap("array index out of bounds"); }
                    vader_array_ref_store(_a30_slotarr->buf, _a30_slotarr->offset + (size_t) l8, l40);
                    VADER_WRITE_BARRIER(_a30_slotarr->buf);
                    t2 = (l8 + INT64_C(1));
                    l8 = (size_t) (int64_t) t2;
                    goto loop_383;
                }
            }
        }
        vader_array_t* _a31_arr = vader_array_new(8u, 0u, 0u, 176u);
        l4 = (void*) _a31_arr;
        vader_array_t* _a32_arr = vader_array_new(6u, 0u, 12u, 174u);
        l5 = (void*) _a32_arr;
        vader_array_t* _a33_arr = vader_array_new(9u, 0u, 7u, 179u);
        l6 = (void*) _a33_arr;
        vader_struct_std_collections_MutableMap__string__bool_t* _a34_obj = (vader_struct_std_collections_MutableMap__string__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__bool_t));
        vader_obj_header_init(_a34_obj, 364u);
        _a34_obj->f_ekeys = l4;
        _a34_obj->f_evals = l5;
        _a34_obj->f_index = l6;
        _a34_obj->f_mask = (size_t) (int64_t) INT64_C(0);
        _a34_obj->f_size = (size_t) (int64_t) INT64_C(0);
        _a34_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
        l4 = (void*) _a34_obj;
        l5 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l3)->f_functions;
        l7 = ((vader_array_t*) l5)->length;
        l8 = (size_t) (int64_t) INT64_C(0);
        {
            loop_554: {
                if ((l8 < l7)) {
                    vader_array_t* _a35_slotarr = ((vader_array_t*) l5);
                    if (_a35_slotarr->buf != NULL && _a35_slotarr->buf->header.forward != NULL) { _a35_slotarr->buf = vader_array_buf_forward(_a35_slotarr->buf); }
                    if ((size_t) l8 >= _a35_slotarr->length) { vader_trap("array index out of bounds"); }
                    t1 = vader_array_ref_load_obj(_a35_slotarr->buf, _a35_slotarr->offset + (size_t) l8);
                    l6 = ((vader_struct_vader_bytecode_BcFunction_t*) t1)->f_body;
                    l12 = ((vader_array_t*) l6)->length;
                    l13 = (size_t) (int64_t) INT64_C(0);
                    {
                        loop_569: {
                            if ((l13 < l12)) {
                                vader_array_t* _a36_slotarr = ((vader_array_t*) l6);
                                if (_a36_slotarr->buf != NULL && _a36_slotarr->buf->header.forward != NULL) { _a36_slotarr->buf = vader_array_buf_forward(_a36_slotarr->buf); }
                                if ((size_t) l13 >= _a36_slotarr->length) { vader_trap("array index out of bounds"); }
                                l21 = vader_array_ref_load_box(_a36_slotarr->buf, _a36_slotarr->offset + (size_t) l13);
                                if (l21.tag == 662u) {
                                    t1 = l21.payload.obj;
                                    l9 = ((vader_struct_vader_bytecode_VirtualCall_t*) t1)->f_vtable_key;
                                    std_collections_MutableMap_IndexSet_set_at__string__bool(l4, l9, true);
                                }
                                t2 = (l13 + INT64_C(1));
                                l13 = (size_t) (int64_t) t2;
                                goto loop_569;
                            }
                        }
                    }
                    t2 = (l8 + INT64_C(1));
                    l8 = (size_t) (int64_t) t2;
                    goto loop_554;
                }
            }
        }
        vader_array_t* _a37_arr = vader_array_new(9u, 0u, 7u, 179u);
        l5 = (void*) _a37_arr;
        l6 = ((vader_struct_vader_midir_CFGProject_t*) l0)->f_vtable_entries;
        l7 = ((vader_array_t*) l6)->length;
        l8 = (size_t) (int64_t) INT64_C(0);
        {
            loop_615: {
                if ((l8 < l7)) {
                    vader_array_t* _a38_slotarr = ((vader_array_t*) l6);
                    if (_a38_slotarr->buf != NULL && _a38_slotarr->buf->header.forward != NULL) { _a38_slotarr->buf = vader_array_buf_forward(_a38_slotarr->buf); }
                    if ((size_t) l8 >= _a38_slotarr->length) { vader_trap("array index out of bounds"); }
                    l10 = vader_array_ref_load_obj(_a38_slotarr->buf, _a38_slotarr->offset + (size_t) l8);
                    l9 = ((vader_struct_vader_lower_LoweredVtableEntry_t*) l10)->f_trait_name;
                    l26 = ((vader_struct_vader_lower_LoweredVtableEntry_t*) l10)->f_method_name;
                    l41 = concat_3(l9, 436u, l26);
                    t0 = std_collections_MutableMap_Index_at__string__bool(l4, l41);
                    if (!(t0.tag == 174u)) {
                        t2 = (l8 + INT64_C(1));
                        l8 = (size_t) (int64_t) t2;
                        goto loop_615;
                    }
                    l42 = vader_bytecode_type_intern_key(((vader_struct_vader_lower_LoweredVtableEntry_t*) l10)->f_struct_type);
                    l21 = std_collections_MutableMap_Index_at__string__i32(((vader_struct_vader_bytecode_EmitterCtx_t*) l3)->f_type_key, l42);
                    if (l21.tag == 179u) {
                        l11 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l3)->f_pinned_types;
                        l20 = ((int32_t) l21.payload.i);
                        vader_array_push_i32((vader_array_t*) l11, l20);
                    }
                    l24 = vader_midir_resolve_vtable_fn_index(((vader_struct_vader_lower_LoweredVtableEntry_t*) l10)->f_fn_symbol, l3);
                    if ((l24 >= INT32_C(0))) {
                        vader_array_push_i32((vader_array_t*) l5, l24);
                    }
                    t2 = (l8 + INT64_C(1));
                    l8 = (size_t) (int64_t) t2;
                    goto loop_615;
                }
            }
        }
        l4 = ((vader_struct_vader_bytecode_EmitOptions_t*) l2)->f_keep_mangles;
        vader_bytecode_prune_unused_functions(l3, l5, l4);
        vader_bytecode_prune_unused_imports(l3);
        vader_bytecode_prune_unused_types(l3);
        ((vader_struct_vader_bytecode_EmitterCtx_t*) l3)->f_types_frozen = true;
        l4 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l3)->f_imports;
        l7 = ((vader_array_t*) l4)->length;
        l8 = (size_t) (int64_t) INT64_C(0);
        {
            loop_704: {
                if ((l8 < l7)) {
                    vader_array_t* _a39_slotarr = ((vader_array_t*) l4);
                    if (_a39_slotarr->buf != NULL && _a39_slotarr->buf->header.forward != NULL) { _a39_slotarr->buf = vader_array_buf_forward(_a39_slotarr->buf); }
                    if ((size_t) l8 >= _a39_slotarr->length) { vader_trap("array index out of bounds"); }
                    l5 = vader_array_ref_load_obj(_a39_slotarr->buf, _a39_slotarr->offset + (size_t) l8);
                    l9 = ((vader_struct_vader_bytecode_BcImport_t*) l5)->f_mangled_name;
                    l28 = ((vader_struct_vader_bytecode_BcImport_t*) l5)->f_is_extern;
                    vader_bytecode_assert_host_import_wired(l9, l28);
                    t2 = (l8 + INT64_C(1));
                    l8 = (size_t) (int64_t) t2;
                    goto loop_704;
                }
            }
        }
    }
    l4 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l3)->f_types;
    l5 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l3)->f_strings;
    l6 = ((vader_struct_vader_midir_CFGProject_t*) l0)->f_data_pool;
    l10 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l3)->f_functions;
    l11 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l3)->f_imports;
    l14 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l3)->f_exports;
    l17 = ((vader_struct_vader_midir_CFGProject_t*) l0)->f_vtable_entries;
    l22 = ((vader_struct_vader_midir_CFGProject_t*) l0)->f_trait_membership;
    l17 = vader_midir_build_impl_table_from_vtable(l17, l22, l3);
    l3 = vader_midir_build_vtables_from_entries(((vader_struct_vader_midir_CFGProject_t*) l0)->f_vtable_entries, l3);
    vader_struct_vader_bytecode_BytecodeModule_t* _a40_obj = (vader_struct_vader_bytecode_BytecodeModule_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BytecodeModule_t));
    vader_obj_header_init(_a40_obj, 537u);
    _a40_obj->f_name = l1;
    _a40_obj->f_types = l4;
    _a40_obj->f_strings = l5;
    _a40_obj->f_data_pool = l6;
    _a40_obj->f_functions = l10;
    _a40_obj->f_imports = l11;
    _a40_obj->f_exports = l14;
    _a40_obj->f_impl_table = l17;
    _a40_obj->f_vtables = l3;
    t1 = (void*) _a40_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
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
        } else {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
            if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
            if ((size_t) INT32_C(0) >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
            t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) INT32_C(0)];
            l4 = vader_box_i32(179u, t1);
        }
        vader_midir_emit_result_if_any(l0, l1, l4, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    l5 = ((vader_array_t*) l2)->length;
    l6 = (size_t) (int64_t) INT64_C(0);
    {
        loop_31: {
            if ((l6 < l5)) {
                t0 = ((vader_array_t*) l2)->length;
                t2 = ((t0 - INT64_C(1)) - l6);
                l7 = (size_t) (int64_t) t2;
                vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l7 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                l8 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l7];
                vader_midir_emit_set(l0, l8, l3);
                t2 = (l6 + INT64_C(1));
                l6 = (size_t) (int64_t) t2;
                goto loop_31;
            }
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_midir_emit_cfg_function_body(void* l0, int32_t l1, void* l2, void* l3, bool l4) {
    void* l5 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l15 = NULL;
    void* l18 = NULL;
    void* l19 = NULL;
    void* l20 = NULL;
    void* l21 = NULL;
    void* l22 = NULL;
    void* l23 = NULL;
    void* l24 = NULL;
    void* l25 = NULL;
    void* l26 = NULL;
    size_t l6, l9, l10;
    int32_t l11, l12, l13, l14;
    vader_string_t l16 = 0;
    uint8_t l17;
    int64_t t0;
    size_t t1;
    void* t2 = NULL;
    void** gc_raw_roots[17] = { &l0, &l2, &l3, &l5, &l7, &l8, &l15, &l18, &l19, &l20, &l21, &l22, &l23, &l24, &l25, &l26, &t2 };
    vader_string_t* gc_atom_roots[1] = { &l16 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 17u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l5 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l2)->f_functions;
    t0 = ((int64_t) (int32_t) l1);
    l6 = (size_t) (int64_t) t0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    if ((size_t) l6 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
    l5 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l6);
    vader_array_t* _a1_arr = vader_array_new(9u, 0u, 7u, 179u);
    l7 = (void*) _a1_arr;
    std_collections_MutableMap_IndexSet_set_at__i32__Any(((vader_struct_vader_bytecode_EmitterCtx_t*) l2)->f_pinned_types_by_fn, l1, vader_ref_box(l7));
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 179u);
    l8 = (void*) _a2_arr;
    l6 = ((vader_array_t*) ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_params)->length;
    l9 = ((vader_array_t*) ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_locals)->length;
    l10 = (size_t) (int64_t) INT64_C(0);
    {
        loop_26: {
            if ((l10 < l9)) {
                if ((l10 < l6)) {
                    l11 = ((int32_t) (size_t) l10);
                    vader_array_push_i32((vader_array_t*) l8, l11);
                } else {
                    l12 = ((int32_t) (size_t) l6);
                    t1 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l5)->f_locals)->length;
                    l13 = ((int32_t) (size_t) t1);
                    l14 = (l12 + l13);
                    l15 = ((vader_struct_vader_bytecode_BcFunction_t*) l5)->f_locals;
                    vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_locals);
                    if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                    if ((size_t) l10 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                    t2 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l10);
                    l16 = ((vader_struct_vader_midir_CFGLocal_t*) t2)->f_name;
                    if ((size_t) l10 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                    t2 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l10);
                    l17 = vader_bytecode_val_type_of_type(((vader_struct_vader_midir_CFGLocal_t*) t2)->f_type);
                    vader_struct_vader_bytecode_BcLocal_t* _a4_obj = (vader_struct_vader_bytecode_BcLocal_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcLocal_t));
                    vader_obj_header_init(_a4_obj, 509u);
                    _a4_obj->f_name = l16;
                    _a4_obj->f_val = l17;
                    l18 = (void*) _a4_obj;
                    vader_array_push((vader_array_t*) l15, vader_ref_box(l18));
                    vader_array_push_i32((vader_array_t*) l8, l14);
                }
                t0 = (l10 + INT64_C(1));
                l10 = (size_t) (int64_t) t0;
                goto loop_26;
            }
        }
    }
    l15 = vader_midir_predecessors_of(l0);
    l18 = vader_midir_compute_dominators(l0, l15);
    l19 = vader_midir_compute_post_dominators(l0);
    l20 = vader_midir_find_loop_exits(l0, l15, l18);
    l21 = vader_midir_schedule_stack(l0);
    vader_array_t* _a5_arr = vader_array_new(86u, 0u, 13u, 859u);
    l22 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(85u, 0u, 13u, 856u);
    l23 = (void*) _a6_arr;
    vader_array_t* _a7_arr = vader_array_new(9u, 0u, 7u, 179u);
    l24 = (void*) _a7_arr;
    vader_array_t* _a8_arr = vader_array_new(6u, 0u, 12u, 174u);
    l25 = (void*) _a8_arr;
    vader_array_t* _a9_arr = vader_array_new(9u, 0u, 7u, 179u);
    l26 = (void*) _a9_arr;
    vader_struct_std_collections_MutableMap__i32__bool_t* _a10_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
    vader_obj_header_init(_a10_obj, 316u);
    _a10_obj->f_ekeys = l24;
    _a10_obj->f_evals = l25;
    _a10_obj->f_index = l26;
    _a10_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a10_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a10_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    t2 = (void*) _a10_obj;
    vader_struct_std_collections_MutableSet__i32_t* _a11_obj = (vader_struct_std_collections_MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i32_t));
    vader_obj_header_init(_a11_obj, 384u);
    _a11_obj->f_inner = t2;
    l24 = (void*) _a11_obj;
    vader_struct_vader_midir_FnEmitCfg_t* _a12_obj = (vader_struct_vader_midir_FnEmitCfg_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_FnEmitCfg_t));
    vader_obj_header_init(_a12_obj, 821u);
    _a12_obj->f_fn_ = l0;
    _a12_obj->f_pinned_types_bucket = l7;
    _a12_obj->f_slot = l5;
    _a12_obj->f_project = l2;
    _a12_obj->f_string_index_map = l3;
    _a12_obj->f_local_to_slot = l8;
    _a12_obj->f_preds = l15;
    _a12_obj->f_idom = l18;
    _a12_obj->f_ipostdom = l19;
    _a12_obj->f_loop_exit = l20;
    _a12_obj->f_scopes = l22;
    _a12_obj->f_pending = l23;
    _a12_obj->f_wrapped_loop_headers = l24;
    _a12_obj->f_hints = l21;
    _a12_obj->f_want_debug = l4;
    l5 = (void*) _a12_obj;
    l11 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_entry;
    l12 = -(INT32_C(1));
    vader_midir_emit_range(l5, l11, l12);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static int32_t vader_midir_emit_cond(void* l0, int32_t l1, void* l2, int32_t l3) {
    int32_t l4;
    void* l5 = NULL;
    bool l6;
    bool t0;
    void** gc_raw_roots[3] = { &l0, &l2, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = std_collections_MutableSet_Contains_contains__i32(((vader_struct_vader_midir_ScheduleHints_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_hints)->f_skip_terminator_get, l1);
    if (!(t0)) {
        l4 = ((vader_struct_vader_midir_TermCondBranch_t*) l2)->f_cond;
        l5 = ((vader_struct_vader_midir_TermCondBranch_t*) l2)->f_span;
        vader_midir_emit_get(l0, l4, l5);
    }
    l5 = ((vader_struct_vader_midir_TermCondBranch_t*) l2)->f_span;
    vader_midir_cf_if(l0, l5, l3);
    if ((l3 < INT32_C(0))) {
        l6 = true;
    } else {
        t0 = vader_midir_BlockId_Equals_equals(((vader_struct_vader_midir_TermCondBranch_t*) l2)->f_then_block, l3);
        l6 = !(t0);
    }
    if (l6) {
        l4 = ((vader_struct_vader_midir_TermCondBranch_t*) l2)->f_then_block;
        vader_midir_emit_range(l0, l4, l3);
    }
    if ((l3 < INT32_C(0))) {
        l6 = true;
    } else {
        t0 = vader_midir_BlockId_Equals_equals(((vader_struct_vader_midir_TermCondBranch_t*) l2)->f_else_block, l3);
        l6 = !(t0);
    }
    if (!(l6)) {
        l5 = ((vader_struct_vader_midir_TermCondBranch_t*) l2)->f_span;
        vader_midir_cf_end(l0, l5);
        { int32_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_midir_last_op_exits(l0);
    if (t0) {
        l5 = ((vader_struct_vader_midir_TermCondBranch_t*) l2)->f_span;
        vader_midir_cf_end(l0, l5);
        { int32_t __vret = ((vader_struct_vader_midir_TermCondBranch_t*) l2)->f_else_block; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l5 = ((vader_struct_vader_midir_TermCondBranch_t*) l2)->f_span;
    vader_midir_cf_else(l0, l5);
    l4 = ((vader_struct_vader_midir_TermCondBranch_t*) l2)->f_else_block;
    vader_midir_emit_range(l0, l4, l3);
    l5 = ((vader_struct_vader_midir_TermCondBranch_t*) l2)->f_span;
    vader_midir_cf_end(l0, l5);
    { int32_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static int32_t vader_midir_emit_const(void* l0, vader_box_t l1, vader_box_t l2, void* l3) {
    int32_t l4;
    void* l5 = NULL;
    vader_box_t* gc_roots[2] = { &l1, &l2 };
    void** gc_raw_roots[3] = { &l0, &l3, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l4 = vader_midir_fresh_tmp(l0, 1846u, l1);
    vader_struct_vader_midir_InstrConst_t* _a0_obj = (vader_struct_vader_midir_InstrConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrConst_t));
    vader_obj_header_init(_a0_obj, 836u);
    _a0_obj->f_span = l3;
    _a0_obj->f_dst = l4;
    _a0_obj->f_value = l2;
    _a0_obj->f_type = l1;
    l5 = (void*) _a0_obj;
    vader_midir_emit(l0, vader_ref_box(l5));
    { int32_t __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
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
    if (l3.tag == 814u) {
        t0 = vader_bytecode_val_type_of_type(((vader_struct_vader_midir_InstrConst_t*) l1)->f_type);
        t1 = vader_bytecode_is_64_bit_int_val(t0);
        if (t1) {
            t2 = l3.payload.obj;
            t3 = ((vader_struct_vader_midir_ConstInt_t*) t2)->f_value;
            vader_struct_vader_bytecode_I64Const_t* _a0_obj = (vader_struct_vader_bytecode_I64Const_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64Const_t));
            vader_obj_header_init(_a0_obj, 594u);
            _a0_obj->f_value = t3;
            l4 = (void*) _a0_obj;
            l5 = ((vader_struct_vader_midir_InstrConst_t*) l1)->f_span;
            vader_midir_push_emit(l0, vader_ref_box(l4), l5);
        } else {
            t2 = l3.payload.obj;
            t3 = ((vader_struct_vader_midir_ConstInt_t*) t2)->f_value;
            vader_struct_vader_bytecode_I32Const_t* _a1_obj = (vader_struct_vader_bytecode_I32Const_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32Const_t));
            vader_obj_header_init(_a1_obj, 574u);
            _a1_obj->f_value = ((int32_t) (int64_t) t3);
            l4 = (void*) _a1_obj;
            l5 = ((vader_struct_vader_midir_InstrConst_t*) l1)->f_span;
            vader_midir_push_emit(l0, vader_ref_box(l4), l5);
        }
    } else {
        if (l3.tag == 813u) {
            t2 = l3.payload.obj;
            t4 = ((vader_struct_vader_midir_ConstFloat_t*) t2)->f_value;
            vader_struct_vader_bytecode_F64Const_t* _a2_obj = (vader_struct_vader_bytecode_F64Const_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_F64Const_t));
            vader_obj_header_init(_a2_obj, 555u);
            _a2_obj->f_value = t4;
            l4 = (void*) _a2_obj;
            l5 = ((vader_struct_vader_midir_InstrConst_t*) l1)->f_span;
            vader_midir_push_emit(l0, vader_ref_box(l4), l5);
        } else {
            if (l3.tag == 811u) {
                t2 = l3.payload.obj;
                t1 = ((vader_struct_vader_midir_ConstBool_t*) t2)->f_value;
                vader_struct_vader_bytecode_BoolConst_t* _a3_obj = (vader_struct_vader_bytecode_BoolConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BoolConst_t));
                vader_obj_header_init(_a3_obj, 526u);
                _a3_obj->f_value = t1;
                l4 = (void*) _a3_obj;
                l5 = ((vader_struct_vader_midir_InstrConst_t*) l1)->f_span;
                vader_midir_push_emit(l0, vader_ref_box(l4), l5);
            } else {
                if (l3.tag == 812u) {
                    t2 = l3.payload.obj;
                    t5 = ((vader_struct_vader_midir_ConstChar_t*) t2)->f_value;
                    vader_struct_vader_bytecode_CharConst_t* _a4_obj = (vader_struct_vader_bytecode_CharConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_CharConst_t));
                    vader_obj_header_init(_a4_obj, 542u);
                    _a4_obj->f_value = ((uint32_t) (int32_t) t5);
                    l4 = (void*) _a4_obj;
                    l5 = ((vader_struct_vader_midir_InstrConst_t*) l1)->f_span;
                    vader_midir_push_emit(l0, vader_ref_box(l4), l5);
                } else {
                    if (l3.tag == 815u) {
                        vader_struct_vader_bytecode_NullConst_t* _a5_obj = (vader_struct_vader_bytecode_NullConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_NullConst_t));
                        vader_obj_header_init(_a5_obj, 625u);
                        l4 = (void*) _a5_obj;
                        l5 = ((vader_struct_vader_midir_InstrConst_t*) l1)->f_span;
                        vader_midir_push_emit(l0, vader_ref_box(l4), l5);
                    } else {
                        if (l3.tag == 816u) {
                            l4 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_string_index_map;
                            t2 = l3.payload.obj;
                            t5 = ((vader_struct_vader_midir_ConstString_t*) t2)->f_index;
                            t3 = ((int64_t) (int32_t) t5);
                            l6 = (size_t) (int64_t) t3;
                            vader_array_t* _a6_slotarr = ((vader_array_t*) l4);
                            if (_a6_slotarr->buf != NULL && _a6_slotarr->buf->header.forward != NULL) { _a6_slotarr->buf = vader_array_buf_forward(_a6_slotarr->buf); }
                            if ((size_t) l6 >= _a6_slotarr->length) { vader_trap("array index out of bounds"); }
                            t5 = ((int32_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l6];
                            vader_struct_vader_bytecode_StringConst_t* _a7_obj = (vader_struct_vader_bytecode_StringConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_StringConst_t));
                            vader_obj_header_init(_a7_obj, 640u);
                            _a7_obj->f_index = t5;
                            l4 = (void*) _a7_obj;
                            l5 = ((vader_struct_vader_midir_InstrConst_t*) l1)->f_span;
                            vader_midir_push_emit(l0, vader_ref_box(l4), l5);
                        }
                    }
                }
            }
        }
    }
    l7 = ((vader_struct_vader_midir_InstrConst_t*) l1)->f_dst;
    l4 = ((vader_struct_vader_midir_InstrConst_t*) l1)->f_span;
    vader_midir_emit_result(l0, l2, l7, l4);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_midir_emit_first_get(void* l0, int64_t l1, int32_t l2, void* l3) {
    bool t0;
    void** gc_raw_roots[2] = { &l0, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = std_collections_MutableSet_Contains_contains__i64(((vader_struct_vader_midir_ScheduleHints_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_hints)->f_skip_first_get, l1);
    if (t0) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_midir_emit_get(l0, l2, l3);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
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
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    if ((size_t) l4 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
    t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l4];
    vader_struct_vader_bytecode_LocalGet_t* _a1_obj = (vader_struct_vader_bytecode_LocalGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_LocalGet_t));
    vader_obj_header_init(_a1_obj, 619u);
    _a1_obj->f_slot = t1;
    l3 = (void*) _a1_obj;
    vader_midir_push_emit(l0, vader_ref_box(l3), l2);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_midir_emit_instr(void* l0, vader_box_t l1, int64_t l2) {
    void* l3 = NULL;
    void* l9 = NULL;
    void* l11 = NULL;
    void* l13 = NULL;
    int32_t l4, l14, l24;
    size_t l5, l10, l12;
    vader_box_t l6 = vader_box_null(), l18 = vader_box_null();
    uint8_t l7, l8;
    vader_string_t l15 = 0;
    vader_string_t l16 = 0;
    vader_string_t l20 = 0;
    vader_string_t l21 = 0;
    vader_string_t l22 = 0;
    int64_t l17;
    bool l19, l23;
    void* t0 = NULL;
    int64_t t1;
    int32_t t2;
    vader_string_t t3 = 0;
    size_t t4;
    bool t5;
    vader_box_t* gc_roots[3] = { &l1, &l6, &l18 };
    void** gc_raw_roots[6] = { &l0, &l3, &l9, &l11, &l13, &t0 };
    vader_string_t* gc_atom_roots[6] = { &l15, &l16, &l20, &l21, &l22, &t3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 6u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    if (l1.tag == 836u) {
        l3 = l1.payload.obj;
        vader_midir_emit_const_instr(l0, l3, l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 846u) {
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrMove_t*) t0)->f_src;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrMove_t*) t0)->f_span;
        vader_midir_emit_first_get(l0, l2, l4, l3);
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrMove_t*) t0)->f_dst;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrMove_t*) t0)->f_span;
        vader_midir_emit_result(l0, l2, l4, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 829u) {
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrBinOp_t*) t0)->f_lhs;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrBinOp_t*) t0)->f_span;
        vader_midir_emit_first_get(l0, l2, l4, l3);
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrBinOp_t*) t0)->f_rhs;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrBinOp_t*) t0)->f_span;
        vader_midir_emit_get(l0, l4, l3);
        l3 = ((vader_struct_vader_midir_CFGFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_fn_)->f_locals;
        t0 = l1.payload.obj;
        t1 = ((int64_t) (int32_t) ((vader_struct_vader_midir_InstrBinOp_t*) t0)->f_lhs);
        l5 = (size_t) (int64_t) t1;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
        if ((size_t) l5 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
        l6 = ((vader_struct_vader_midir_CFGLocal_t*) t0)->f_type;
        t0 = l1.payload.obj;
        l7 = ((vader_struct_vader_midir_InstrBinOp_t*) t0)->f_op;
        l8 = vader_bytecode_val_type_of_type(l6);
        l6 = vader_bytecode_binary_op_for(l7, l8);
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrBinOp_t*) t0)->f_span;
        vader_midir_push_emit(l0, l6, l3);
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrBinOp_t*) t0)->f_dst;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrBinOp_t*) t0)->f_span;
        vader_midir_emit_result(l0, l2, l4, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 830u) {
        l3 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_pinned_types_bucket;
        t0 = l1.payload.obj;
        l9 = ((vader_struct_vader_midir_InstrCall_t*) t0)->f_args;
        l5 = ((vader_array_t*) l9)->length;
        l10 = (size_t) (int64_t) INT64_C(0);
        {
            loop_132: {
                if ((l10 < l5)) {
                    vader_array_t* _a1_slotarr = ((vader_array_t*) l9);
                    if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                    if ((size_t) l10 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                    l4 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l10];
                    l11 = ((vader_struct_vader_midir_CFGFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_fn_)->f_locals;
                    t1 = ((int64_t) (int32_t) l4);
                    l12 = (size_t) (int64_t) t1;
                    vader_array_t* _a2_slotarr = ((vader_array_t*) l11);
                    if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                    if ((size_t) l12 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                    t0 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l12);
                    l6 = ((vader_struct_vader_midir_CFGLocal_t*) t0)->f_type;
                    l13 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project;
                    l14 = vader_bytecode_intern_type(l6, l13);
                    vader_array_push_i32((vader_array_t*) l3, l14);
                    t1 = (l10 + INT64_C(1));
                    l10 = (size_t) (int64_t) t1;
                    goto loop_132;
                }
            }
        }
        t0 = l1.payload.obj;
        l9 = ((vader_struct_vader_midir_InstrCall_t*) t0)->f_dsts;
        l5 = ((vader_array_t*) l9)->length;
        l10 = (size_t) (int64_t) INT64_C(0);
        {
            loop_178: {
                if ((l10 < l5)) {
                    vader_array_t* _a3_slotarr = ((vader_array_t*) l9);
                    if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                    if ((size_t) l10 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                    l4 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l10];
                    l11 = ((vader_struct_vader_midir_CFGFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_fn_)->f_locals;
                    t1 = ((int64_t) (int32_t) l4);
                    l12 = (size_t) (int64_t) t1;
                    vader_array_t* _a4_slotarr = ((vader_array_t*) l11);
                    if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                    if ((size_t) l12 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                    t0 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l12);
                    l6 = ((vader_struct_vader_midir_CFGLocal_t*) t0)->f_type;
                    l13 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project;
                    l14 = vader_bytecode_intern_type(l6, l13);
                    vader_array_push_i32((vader_array_t*) l3, l14);
                    t1 = (l10 + INT64_C(1));
                    l10 = (size_t) (int64_t) t1;
                    goto loop_178;
                }
            }
        }
        t0 = l1.payload.obj;
        l5 = ((vader_array_t*) ((vader_struct_vader_midir_InstrCall_t*) t0)->f_args)->length;
        l10 = (size_t) (int64_t) INT64_C(0);
        {
            loop_223: {
                if ((l10 < l5)) {
                    if (l10 == INT64_C(0)) {
                        t0 = l1.payload.obj;
                        vader_array_t* _a5_slotarr = ((vader_array_t*) ((vader_struct_vader_midir_InstrCall_t*) t0)->f_args);
                        if (_a5_slotarr->buf != NULL && _a5_slotarr->buf->header.forward != NULL) { _a5_slotarr->buf = vader_array_buf_forward(_a5_slotarr->buf); }
                        if ((size_t) l10 >= _a5_slotarr->length) { vader_trap("array index out of bounds"); }
                        l4 = ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l10];
                        t0 = l1.payload.obj;
                        l3 = ((vader_struct_vader_midir_InstrCall_t*) t0)->f_span;
                        vader_midir_emit_first_get(l0, l2, l4, l3);
                    } else {
                        t0 = l1.payload.obj;
                        vader_array_t* _a6_slotarr = ((vader_array_t*) ((vader_struct_vader_midir_InstrCall_t*) t0)->f_args);
                        if (_a6_slotarr->buf != NULL && _a6_slotarr->buf->header.forward != NULL) { _a6_slotarr->buf = vader_array_buf_forward(_a6_slotarr->buf); }
                        if ((size_t) l10 >= _a6_slotarr->length) { vader_trap("array index out of bounds"); }
                        l14 = ((int32_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l10];
                        t0 = l1.payload.obj;
                        l9 = ((vader_struct_vader_midir_InstrCall_t*) t0)->f_span;
                        vader_midir_emit_get(l0, l14, l9);
                    }
                    t1 = (l10 + INT64_C(1));
                    l10 = (size_t) (int64_t) t1;
                    goto loop_223;
                }
            }
        }
        l3 = ((vader_struct_vader_bytecode_EmitterCtx_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project)->f_function_index_by_mangle;
        t0 = l1.payload.obj;
        l15 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_midir_InstrCall_t*) t0)->f_callee)->f_name;
        l6 = std_collections_MutableMap_Index_at__string__i32(l3, l15);
        if (l6.tag == 179u) {
            t2 = ((int32_t) l6.payload.i);
            vader_struct_vader_bytecode_Call_t* _a7_obj = (vader_struct_vader_bytecode_Call_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_Call_t));
            vader_obj_header_init(_a7_obj, 539u);
            _a7_obj->f_function_index = t2;
            l3 = (void*) _a7_obj;
            t0 = l1.payload.obj;
            l9 = ((vader_struct_vader_midir_InstrCall_t*) t0)->f_span;
            vader_midir_push_emit(l0, vader_ref_box(l3), l9);
        } else {
            l3 = ((vader_struct_vader_bytecode_EmitterCtx_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project)->f_function_index_by_symbol_id;
            t0 = l1.payload.obj;
            l4 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_midir_InstrCall_t*) t0)->f_callee)->f_id;
            l6 = std_collections_MutableMap_Index_at__i32__i32(l3, l4);
            if (l6.tag == 179u) {
                t2 = ((int32_t) l6.payload.i);
                vader_struct_vader_bytecode_Call_t* _a8_obj = (vader_struct_vader_bytecode_Call_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_Call_t));
                vader_obj_header_init(_a8_obj, 539u);
                _a8_obj->f_function_index = t2;
                l3 = (void*) _a8_obj;
                t0 = l1.payload.obj;
                l9 = ((vader_struct_vader_midir_InstrCall_t*) t0)->f_span;
                vader_midir_push_emit(l0, vader_ref_box(l3), l9);
            } else {
                l3 = ((vader_struct_vader_bytecode_EmitterCtx_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project)->f_import_index_by_symbol_id;
                t0 = l1.payload.obj;
                l4 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_midir_InstrCall_t*) t0)->f_callee)->f_id;
                l6 = std_collections_MutableMap_Index_at__i32__i32(l3, l4);
                if (l6.tag == 179u) {
                    t2 = ((int32_t) l6.payload.i);
                    vader_struct_vader_bytecode_CallImport_t* _a9_obj = (vader_struct_vader_bytecode_CallImport_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_CallImport_t));
                    vader_obj_header_init(_a9_obj, 540u);
                    _a9_obj->f_index = t2;
                    l3 = (void*) _a9_obj;
                    t0 = l1.payload.obj;
                    l9 = ((vader_struct_vader_midir_InstrCall_t*) t0)->f_span;
                    vader_midir_push_emit(l0, vader_ref_box(l3), l9);
                } else {
                    l3 = ((vader_struct_vader_bytecode_EmitterCtx_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project)->f_import_index_by_mangle;
                    t0 = l1.payload.obj;
                    l15 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_midir_InstrCall_t*) t0)->f_callee)->f_name;
                    l6 = std_collections_MutableMap_Index_at__string__i32(l3, l15);
                    if (l6.tag == 179u) {
                        t2 = ((int32_t) l6.payload.i);
                        vader_struct_vader_bytecode_CallImport_t* _a10_obj = (vader_struct_vader_bytecode_CallImport_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_CallImport_t));
                        vader_obj_header_init(_a10_obj, 540u);
                        _a10_obj->f_index = t2;
                        l3 = (void*) _a10_obj;
                        t0 = l1.payload.obj;
                        l9 = ((vader_struct_vader_midir_InstrCall_t*) t0)->f_span;
                        vader_midir_push_emit(l0, vader_ref_box(l3), l9);
                    } else {
                        t0 = l1.payload.obj;
                        l15 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_midir_InstrCall_t*) t0)->f_callee)->f_name;
                        l16 = ((vader_struct_vader_midir_CFGFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_fn_)->f_mangled;
                        l5 = vader_host_std_core_byte_len(l15);
                        l10 = vader_host_std_core_byte_len(l16);
                        t1 = (l5 + l10);
                        l5 = (size_t) (int64_t) t1;
                        l3 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(117) + l5));
                        l5 = (size_t) (int64_t) INT64_C(0);
                        l5 = std_core_write_string_at(l3, l5, 1939u);
                        l5 = std_core_write_string_at(l3, l5, l15);
                        l5 = std_core_write_string_at(l3, l5, 287u);
                        t0 = l1.payload.obj;
                        t2 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_midir_InstrCall_t*) t0)->f_callee)->f_id;
                        l17 = ((int64_t) (int32_t) t2);
                        l5 = std_core_write_int(l3, l5, l17);
                        l5 = std_core_write_string_at(l3, l5, 359u);
                        l5 = std_core_write_string_at(l3, l5, l16);
                        l5 = std_core_write_string_at(l3, l5, 300u);
                        t3 = std_core_finish_buffer(l3, l5);
                        vader_host_std_abort_panic(t3);
                    }
                }
            }
        }
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrCall_t*) t0)->f_dsts;
        t0 = l1.payload.obj;
        l9 = ((vader_struct_vader_midir_InstrCall_t*) t0)->f_span;
        vader_midir_emit_call_results(l0, l2, l3, l9);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 851u) {
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrUnOp_t*) t0)->f_operand;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrUnOp_t*) t0)->f_span;
        vader_midir_emit_first_get(l0, l2, l4, l3);
        l3 = ((vader_struct_vader_midir_CFGFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_fn_)->f_locals;
        t0 = l1.payload.obj;
        t1 = ((int64_t) (int32_t) ((vader_struct_vader_midir_InstrUnOp_t*) t0)->f_operand);
        l5 = (size_t) (int64_t) t1;
        vader_array_t* _a11_slotarr = ((vader_array_t*) l3);
        if (_a11_slotarr->buf != NULL && _a11_slotarr->buf->header.forward != NULL) { _a11_slotarr->buf = vader_array_buf_forward(_a11_slotarr->buf); }
        if ((size_t) l5 >= _a11_slotarr->length) { vader_trap("array index out of bounds"); }
        t0 = vader_array_ref_load_obj(_a11_slotarr->buf, _a11_slotarr->offset + (size_t) l5);
        l7 = vader_bytecode_val_type_of_type(((vader_struct_vader_midir_CFGLocal_t*) t0)->f_type);
        t0 = l1.payload.obj;
        l6 = vader_bytecode_unary_op_for(((vader_struct_vader_midir_InstrUnOp_t*) t0)->f_op, l7);
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrUnOp_t*) t0)->f_span;
        vader_midir_push_emit(l0, l6, l3);
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrUnOp_t*) t0)->f_dst;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrUnOp_t*) t0)->f_span;
        vader_midir_emit_result(l0, l2, l4, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 831u) {
        t0 = l1.payload.obj;
        l5 = ((vader_array_t*) ((vader_struct_vader_midir_InstrCallIndirect_t*) t0)->f_args)->length;
        l10 = (size_t) (int64_t) INT64_C(0);
        {
            loop_546: {
                if ((l10 < l5)) {
                    if (l10 == INT64_C(0)) {
                        t0 = l1.payload.obj;
                        vader_array_t* _a12_slotarr = ((vader_array_t*) ((vader_struct_vader_midir_InstrCallIndirect_t*) t0)->f_args);
                        if (_a12_slotarr->buf != NULL && _a12_slotarr->buf->header.forward != NULL) { _a12_slotarr->buf = vader_array_buf_forward(_a12_slotarr->buf); }
                        if ((size_t) l10 >= _a12_slotarr->length) { vader_trap("array index out of bounds"); }
                        l4 = ((int32_t*) _a12_slotarr->buf->slots)[_a12_slotarr->offset + (size_t) l10];
                        t0 = l1.payload.obj;
                        l3 = ((vader_struct_vader_midir_InstrCallIndirect_t*) t0)->f_span;
                        vader_midir_emit_first_get(l0, l2, l4, l3);
                    } else {
                        t0 = l1.payload.obj;
                        vader_array_t* _a13_slotarr = ((vader_array_t*) ((vader_struct_vader_midir_InstrCallIndirect_t*) t0)->f_args);
                        if (_a13_slotarr->buf != NULL && _a13_slotarr->buf->header.forward != NULL) { _a13_slotarr->buf = vader_array_buf_forward(_a13_slotarr->buf); }
                        if ((size_t) l10 >= _a13_slotarr->length) { vader_trap("array index out of bounds"); }
                        l14 = ((int32_t*) _a13_slotarr->buf->slots)[_a13_slotarr->offset + (size_t) l10];
                        t0 = l1.payload.obj;
                        l9 = ((vader_struct_vader_midir_InstrCallIndirect_t*) t0)->f_span;
                        vader_midir_emit_get(l0, l14, l9);
                    }
                    t1 = (l10 + INT64_C(1));
                    l10 = (size_t) (int64_t) t1;
                    goto loop_546;
                }
            }
        }
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
        l6 = ((vader_struct_vader_midir_InstrCallIndirect_t*) t0)->f_fn_type;
        l3 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project;
        t2 = vader_bytecode_intern_type(l6, l3);
        vader_struct_vader_bytecode_CallIndirect_t* _a14_obj = (vader_struct_vader_bytecode_CallIndirect_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_CallIndirect_t));
        vader_obj_header_init(_a14_obj, 541u);
        _a14_obj->f_type_id = t2;
        l3 = (void*) _a14_obj;
        t0 = l1.payload.obj;
        l9 = ((vader_struct_vader_midir_InstrCallIndirect_t*) t0)->f_span;
        vader_midir_push_emit(l0, vader_ref_box(l3), l9);
        t0 = l1.payload.obj;
        l6 = ((vader_struct_vader_midir_InstrCallIndirect_t*) t0)->f_dst;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrCallIndirect_t*) t0)->f_span;
        vader_midir_emit_result_if_any(l0, l2, l6, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 843u) {
        l3 = ((vader_struct_vader_bytecode_EmitterCtx_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project)->f_function_index_by_symbol_id;
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_midir_InstrFnRef_t*) t0)->f_fn_symbol)->f_id;
        l6 = std_collections_MutableMap_Index_at__i32__i32(l3, l4);
        if (l6.tag == 179u) {
            t0 = l1.payload.obj;
            l18 = ((vader_struct_vader_midir_InstrFnRef_t*) t0)->f_type;
            l3 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project;
            l4 = vader_bytecode_intern_type(l18, l3);
            t2 = ((int32_t) l6.payload.i);
            vader_struct_vader_bytecode_FnRef_t* _a15_obj = (vader_struct_vader_bytecode_FnRef_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_FnRef_t));
            vader_obj_header_init(_a15_obj, 568u);
            _a15_obj->f_function_index = t2;
            _a15_obj->f_type_id = l4;
            l3 = (void*) _a15_obj;
            t0 = l1.payload.obj;
            l9 = ((vader_struct_vader_midir_InstrFnRef_t*) t0)->f_span;
            vader_midir_push_emit(l0, vader_ref_box(l3), l9);
        } else {
            t0 = l1.payload.obj;
            l15 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_midir_InstrFnRef_t*) t0)->f_fn_symbol)->f_name;
            l5 = vader_host_std_core_byte_len(l15);
            l3 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(104) + l5));
            l5 = (size_t) (int64_t) INT64_C(0);
            l5 = std_core_write_string_at(l3, l5, 1942u);
            l5 = std_core_write_string_at(l3, l5, l15);
            l5 = std_core_write_string_at(l3, l5, 287u);
            t0 = l1.payload.obj;
            t2 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_midir_InstrFnRef_t*) t0)->f_fn_symbol)->f_id;
            l17 = ((int64_t) (int32_t) t2);
            l5 = std_core_write_int(l3, l5, l17);
            l5 = std_core_write_string_at(l3, l5, 366u);
            t3 = std_core_finish_buffer(l3, l5);
            vader_host_std_abort_panic(t3);
        }
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrFnRef_t*) t0)->f_dst;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrFnRef_t*) t0)->f_span;
        vader_midir_emit_result(l0, l2, l4, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 842u) {
        l3 = ((vader_struct_vader_bytecode_EmitterCtx_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project)->f_function_index_by_symbol_id;
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_midir_InstrFnAddr_t*) t0)->f_fn_symbol)->f_id;
        l6 = std_collections_MutableMap_Index_at__i32__i32(l3, l4);
        if (l6.tag == 179u) {
            t2 = ((int32_t) l6.payload.i);
            vader_struct_vader_bytecode_FnAddr_t* _a16_obj = (vader_struct_vader_bytecode_FnAddr_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_FnAddr_t));
            vader_obj_header_init(_a16_obj, 567u);
            _a16_obj->f_function_index = t2;
            l3 = (void*) _a16_obj;
            t0 = l1.payload.obj;
            l9 = ((vader_struct_vader_midir_InstrFnAddr_t*) t0)->f_span;
            vader_midir_push_emit(l0, vader_ref_box(l3), l9);
        } else {
            t0 = l1.payload.obj;
            l15 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_midir_InstrFnAddr_t*) t0)->f_fn_symbol)->f_name;
            l5 = vader_host_std_core_byte_len(l15);
            l3 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(102) + l5));
            l5 = (size_t) (int64_t) INT64_C(0);
            l5 = std_core_write_string_at(l3, l5, 1941u);
            l5 = std_core_write_string_at(l3, l5, l15);
            l5 = std_core_write_string_at(l3, l5, 287u);
            t0 = l1.payload.obj;
            t2 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_midir_InstrFnAddr_t*) t0)->f_fn_symbol)->f_id;
            l17 = ((int64_t) (int32_t) t2);
            l5 = std_core_write_int(l3, l5, l17);
            l5 = std_core_write_string_at(l3, l5, 365u);
            t3 = std_core_finish_buffer(l3, l5);
            vader_host_std_abort_panic(t3);
        }
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrFnAddr_t*) t0)->f_dst;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrFnAddr_t*) t0)->f_span;
        vader_midir_emit_result(l0, l2, l4, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 852u) {
        t0 = l1.payload.obj;
        l5 = ((vader_array_t*) ((vader_struct_vader_midir_InstrVirtualCall_t*) t0)->f_args)->length;
        l10 = (size_t) (int64_t) INT64_C(0);
        {
            loop_882: {
                if ((l10 < l5)) {
                    if (l10 == INT64_C(0)) {
                        t0 = l1.payload.obj;
                        vader_array_t* _a17_slotarr = ((vader_array_t*) ((vader_struct_vader_midir_InstrVirtualCall_t*) t0)->f_args);
                        if (_a17_slotarr->buf != NULL && _a17_slotarr->buf->header.forward != NULL) { _a17_slotarr->buf = vader_array_buf_forward(_a17_slotarr->buf); }
                        if ((size_t) l10 >= _a17_slotarr->length) { vader_trap("array index out of bounds"); }
                        l4 = ((int32_t*) _a17_slotarr->buf->slots)[_a17_slotarr->offset + (size_t) l10];
                        t0 = l1.payload.obj;
                        l3 = ((vader_struct_vader_midir_InstrVirtualCall_t*) t0)->f_span;
                        vader_midir_emit_first_get(l0, l2, l4, l3);
                    } else {
                        t0 = l1.payload.obj;
                        vader_array_t* _a18_slotarr = ((vader_array_t*) ((vader_struct_vader_midir_InstrVirtualCall_t*) t0)->f_args);
                        if (_a18_slotarr->buf != NULL && _a18_slotarr->buf->header.forward != NULL) { _a18_slotarr->buf = vader_array_buf_forward(_a18_slotarr->buf); }
                        if ((size_t) l10 >= _a18_slotarr->length) { vader_trap("array index out of bounds"); }
                        l14 = ((int32_t*) _a18_slotarr->buf->slots)[_a18_slotarr->offset + (size_t) l10];
                        t0 = l1.payload.obj;
                        l9 = ((vader_struct_vader_midir_InstrVirtualCall_t*) t0)->f_span;
                        vader_midir_emit_get(l0, l14, l9);
                    }
                    t1 = (l10 + INT64_C(1));
                    l10 = (size_t) (int64_t) t1;
                    goto loop_882;
                }
            }
        }
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
        l15 = ((vader_struct_vader_midir_InstrVirtualCall_t*) t0)->f_trait_name;
        t0 = l1.payload.obj;
        l16 = ((vader_struct_vader_midir_InstrVirtualCall_t*) t0)->f_method;
        l15 = concat_3(l15, 436u, l16);
        vader_struct_vader_bytecode_VirtualCall_t* _a19_obj = (vader_struct_vader_bytecode_VirtualCall_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_VirtualCall_t));
        vader_obj_header_init(_a19_obj, 662u);
        _a19_obj->f_parameter_count = l4;
        _a19_obj->f_vtable_key = l15;
        l3 = (void*) _a19_obj;
        t0 = l1.payload.obj;
        l9 = ((vader_struct_vader_midir_InstrVirtualCall_t*) t0)->f_span;
        vader_midir_push_emit(l0, vader_ref_box(l3), l9);
        t0 = l1.payload.obj;
        l6 = ((vader_struct_vader_midir_InstrVirtualCall_t*) t0)->f_dst;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrVirtualCall_t*) t0)->f_span;
        vader_midir_emit_result_if_any(l0, l2, l6, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 840u) {
        l3 = ((vader_struct_vader_midir_CFGFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_fn_)->f_locals;
        t0 = l1.payload.obj;
        t1 = ((int64_t) (int32_t) ((vader_struct_vader_midir_InstrFieldGet_t*) t0)->f_target);
        l5 = (size_t) (int64_t) t1;
        vader_array_t* _a20_slotarr = ((vader_array_t*) l3);
        if (_a20_slotarr->buf != NULL && _a20_slotarr->buf->header.forward != NULL) { _a20_slotarr->buf = vader_array_buf_forward(_a20_slotarr->buf); }
        if ((size_t) l5 >= _a20_slotarr->length) { vader_trap("array index out of bounds"); }
        l3 = vader_array_ref_load_obj(_a20_slotarr->buf, _a20_slotarr->offset + (size_t) l5);
        l6 = ((vader_struct_vader_midir_CFGLocal_t*) l3)->f_type;
        l9 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project;
        l4 = vader_bytecode_intern_type(l6, l9);
        l19 = std_collections_MutableSet_Contains_contains__i64(((vader_struct_vader_midir_ScheduleHints_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_hints)->f_skip_first_get, l2);
        t0 = l1.payload.obj;
        l14 = ((vader_struct_vader_midir_InstrFieldGet_t*) t0)->f_target;
        t0 = l1.payload.obj;
        l9 = ((vader_struct_vader_midir_InstrFieldGet_t*) t0)->f_span;
        vader_midir_emit_first_get(l0, l2, l14, l9);
        l9 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project;
        t0 = l1.payload.obj;
        l15 = ((vader_struct_vader_midir_InstrFieldGet_t*) t0)->f_field;
        l18 = vader_midir_find_struct_field_index(l9, l4, l15);
        if (l18.tag == 0u) {
            t0 = l1.payload.obj;
            l15 = ((vader_struct_vader_midir_InstrFieldGet_t*) t0)->f_field;
            l16 = vader_types_display_type(l6);
            t0 = l1.payload.obj;
            l20 = vader_vt_Display__to_string(vader_box_i32(179u, ((vader_struct_vader_midir_InstrFieldGet_t*) t0)->f_target));
            l21 = ((vader_struct_vader_midir_CFGLocal_t*) l3)->f_name;
            l22 = ((vader_struct_vader_midir_CFGFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_fn_)->f_mangled;
            t3 = concat_11(1936u, l15, 1067u, l16, 979u, l20, 106u, l21, 1107u, l22, 298u);
            vader_host_std_abort_panic(t3);
        }
        t4 = ((size_t) l18.payload.i);
        l14 = ((int32_t) (size_t) t4);
        l23 = false;
        if (!(l19)) {
            l23 = vader_midir_try_fuse_local_field(l0, l4, l14);
        }
        if (!(l23)) {
            vader_struct_vader_bytecode_StructGet_t* _a21_obj = (vader_struct_vader_bytecode_StructGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_StructGet_t));
            vader_obj_header_init(_a21_obj, 644u);
            _a21_obj->f_type_id = l4;
            _a21_obj->f_field_index = l14;
            l3 = (void*) _a21_obj;
            t0 = l1.payload.obj;
            l9 = ((vader_struct_vader_midir_InstrFieldGet_t*) t0)->f_span;
            vader_midir_push_emit(l0, vader_ref_box(l3), l9);
        }
        t0 = l1.payload.obj;
        t5 = vader_midir_needs_ref_cast(((vader_struct_vader_midir_InstrFieldGet_t*) t0)->f_type);
        if (t5) {
            t0 = l1.payload.obj;
            l6 = ((vader_struct_vader_midir_InstrFieldGet_t*) t0)->f_type;
            l3 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project;
            t2 = vader_bytecode_intern_type(l6, l3);
            vader_struct_vader_bytecode_RefCast_t* _a22_obj = (vader_struct_vader_bytecode_RefCast_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_RefCast_t));
            vader_obj_header_init(_a22_obj, 626u);
            _a22_obj->f_type_id = t2;
            l3 = (void*) _a22_obj;
            t0 = l1.payload.obj;
            l9 = ((vader_struct_vader_midir_InstrFieldGet_t*) t0)->f_span;
            vader_midir_push_emit(l0, vader_ref_box(l3), l9);
        }
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrFieldGet_t*) t0)->f_dst;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrFieldGet_t*) t0)->f_span;
        vader_midir_emit_result(l0, l2, l4, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 841u) {
        l3 = ((vader_struct_vader_midir_CFGFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_fn_)->f_locals;
        t0 = l1.payload.obj;
        t1 = ((int64_t) (int32_t) ((vader_struct_vader_midir_InstrFieldSet_t*) t0)->f_target);
        l5 = (size_t) (int64_t) t1;
        vader_array_t* _a23_slotarr = ((vader_array_t*) l3);
        if (_a23_slotarr->buf != NULL && _a23_slotarr->buf->header.forward != NULL) { _a23_slotarr->buf = vader_array_buf_forward(_a23_slotarr->buf); }
        if ((size_t) l5 >= _a23_slotarr->length) { vader_trap("array index out of bounds"); }
        t0 = vader_array_ref_load_obj(_a23_slotarr->buf, _a23_slotarr->offset + (size_t) l5);
        l6 = ((vader_struct_vader_midir_CFGLocal_t*) t0)->f_type;
        l3 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project;
        l4 = vader_bytecode_intern_type(l6, l3);
        t0 = l1.payload.obj;
        l14 = ((vader_struct_vader_midir_InstrFieldSet_t*) t0)->f_target;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrFieldSet_t*) t0)->f_span;
        vader_midir_emit_first_get(l0, l2, l14, l3);
        t0 = l1.payload.obj;
        l14 = ((vader_struct_vader_midir_InstrFieldSet_t*) t0)->f_value;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrFieldSet_t*) t0)->f_span;
        vader_midir_emit_get(l0, l14, l3);
        l3 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project;
        t0 = l1.payload.obj;
        l15 = ((vader_struct_vader_midir_InstrFieldSet_t*) t0)->f_field;
        l18 = vader_midir_find_struct_field_index(l3, l4, l15);
        if (l18.tag == 0u) {
            t0 = l1.payload.obj;
            l15 = ((vader_struct_vader_midir_InstrFieldSet_t*) t0)->f_field;
            l16 = vader_types_display_type(l6);
            l20 = ((vader_struct_vader_midir_CFGFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_fn_)->f_mangled;
            t3 = concat_7(1936u, l15, 1067u, l16, 1017u, l20, 299u);
            vader_host_std_abort_panic(t3);
        }
        t4 = ((size_t) l18.payload.i);
        l14 = ((int32_t) (size_t) t4);
        t0 = l1.payload.obj;
        l19 = ((vader_struct_vader_midir_InstrFieldSet_t*) t0)->f_barrierless;
        vader_struct_vader_bytecode_StructSet_t* _a24_obj = (vader_struct_vader_bytecode_StructSet_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_StructSet_t));
        vader_obj_header_init(_a24_obj, 646u);
        _a24_obj->f_type_id = l4;
        _a24_obj->f_field_index = l14;
        _a24_obj->f_stack = l19;
        l3 = (void*) _a24_obj;
        t0 = l1.payload.obj;
        l9 = ((vader_struct_vader_midir_InstrFieldSet_t*) t0)->f_span;
        vader_midir_push_emit(l0, vader_ref_box(l3), l9);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 823u) {
        l3 = ((vader_struct_vader_midir_CFGFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_fn_)->f_locals;
        t0 = l1.payload.obj;
        t1 = ((int64_t) (int32_t) ((vader_struct_vader_midir_InstrArrayGet_t*) t0)->f_target);
        l5 = (size_t) (int64_t) t1;
        vader_array_t* _a25_slotarr = ((vader_array_t*) l3);
        if (_a25_slotarr->buf != NULL && _a25_slotarr->buf->header.forward != NULL) { _a25_slotarr->buf = vader_array_buf_forward(_a25_slotarr->buf); }
        if ((size_t) l5 >= _a25_slotarr->length) { vader_trap("array index out of bounds"); }
        t0 = vader_array_ref_load_obj(_a25_slotarr->buf, _a25_slotarr->offset + (size_t) l5);
        l6 = ((vader_struct_vader_midir_CFGLocal_t*) t0)->f_type;
        l3 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project;
        l4 = vader_bytecode_intern_type(l6, l3);
        t0 = l1.payload.obj;
        l14 = ((vader_struct_vader_midir_InstrArrayGet_t*) t0)->f_target;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrArrayGet_t*) t0)->f_span;
        vader_midir_emit_first_get(l0, l2, l14, l3);
        t0 = l1.payload.obj;
        l14 = ((vader_struct_vader_midir_InstrArrayGet_t*) t0)->f_index;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrArrayGet_t*) t0)->f_span;
        vader_midir_emit_get(l0, l14, l3);
        l7 = vader_midir_array_element_val_type(l6);
        t0 = l1.payload.obj;
        l19 = ((vader_struct_vader_midir_InstrArrayGet_t*) t0)->f_bounds_safe;
        l6 = vader_bytecode_slot_load_op_for(l7, l19);
        if (l6.tag == 0u) {
            t0 = l1.payload.obj;
            l19 = ((vader_struct_vader_midir_InstrArrayGet_t*) t0)->f_bounds_safe;
            vader_struct_vader_bytecode_ArrayGet_t* _a26_obj = (vader_struct_vader_bytecode_ArrayGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_ArrayGet_t));
            vader_obj_header_init(_a26_obj, 493u);
            _a26_obj->f_type_id = l4;
            _a26_obj->f_bounds_safe = l19;
            l3 = (void*) _a26_obj;
            t0 = l1.payload.obj;
            l9 = ((vader_struct_vader_midir_InstrArrayGet_t*) t0)->f_span;
            vader_midir_push_emit(l0, vader_ref_box(l3), l9);
            t0 = l1.payload.obj;
            t5 = vader_midir_needs_ref_cast(((vader_struct_vader_midir_InstrArrayGet_t*) t0)->f_type);
            if (t5) {
                t0 = l1.payload.obj;
                l18 = ((vader_struct_vader_midir_InstrArrayGet_t*) t0)->f_type;
                l3 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project;
                t2 = vader_bytecode_intern_type(l18, l3);
                vader_struct_vader_bytecode_RefCast_t* _a27_obj = (vader_struct_vader_bytecode_RefCast_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_RefCast_t));
                vader_obj_header_init(_a27_obj, 626u);
                _a27_obj->f_type_id = t2;
                l3 = (void*) _a27_obj;
                t0 = l1.payload.obj;
                l9 = ((vader_struct_vader_midir_InstrArrayGet_t*) t0)->f_span;
                vader_midir_push_emit(l0, vader_ref_box(l3), l9);
            }
        } else {
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir_InstrArrayGet_t*) t0)->f_span;
            vader_midir_push_emit(l0, l6, l3);
        }
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrArrayGet_t*) t0)->f_dst;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrArrayGet_t*) t0)->f_span;
        vader_midir_emit_result(l0, l2, l4, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 827u) {
        l3 = ((vader_struct_vader_midir_CFGFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_fn_)->f_locals;
        t0 = l1.payload.obj;
        t1 = ((int64_t) (int32_t) ((vader_struct_vader_midir_InstrArraySet_t*) t0)->f_target);
        l5 = (size_t) (int64_t) t1;
        vader_array_t* _a28_slotarr = ((vader_array_t*) l3);
        if (_a28_slotarr->buf != NULL && _a28_slotarr->buf->header.forward != NULL) { _a28_slotarr->buf = vader_array_buf_forward(_a28_slotarr->buf); }
        if ((size_t) l5 >= _a28_slotarr->length) { vader_trap("array index out of bounds"); }
        t0 = vader_array_ref_load_obj(_a28_slotarr->buf, _a28_slotarr->offset + (size_t) l5);
        l6 = ((vader_struct_vader_midir_CFGLocal_t*) t0)->f_type;
        l3 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project;
        l4 = vader_bytecode_intern_type(l6, l3);
        t0 = l1.payload.obj;
        l14 = ((vader_struct_vader_midir_InstrArraySet_t*) t0)->f_target;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrArraySet_t*) t0)->f_span;
        vader_midir_emit_first_get(l0, l2, l14, l3);
        t0 = l1.payload.obj;
        l14 = ((vader_struct_vader_midir_InstrArraySet_t*) t0)->f_index;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrArraySet_t*) t0)->f_span;
        vader_midir_emit_get(l0, l14, l3);
        t0 = l1.payload.obj;
        l14 = ((vader_struct_vader_midir_InstrArraySet_t*) t0)->f_value;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrArraySet_t*) t0)->f_span;
        vader_midir_emit_get(l0, l14, l3);
        l7 = vader_midir_array_element_val_type(l6);
        t0 = l1.payload.obj;
        l19 = ((vader_struct_vader_midir_InstrArraySet_t*) t0)->f_bounds_safe;
        l6 = vader_bytecode_slot_store_op_for(l7, l19);
        if (l6.tag == 0u) {
            t0 = l1.payload.obj;
            l19 = ((vader_struct_vader_midir_InstrArraySet_t*) t0)->f_bounds_safe;
            vader_struct_vader_bytecode_ArraySet_t* _a29_obj = (vader_struct_vader_bytecode_ArraySet_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_ArraySet_t));
            vader_obj_header_init(_a29_obj, 500u);
            _a29_obj->f_type_id = l4;
            _a29_obj->f_bounds_safe = l19;
            l3 = (void*) _a29_obj;
            t0 = l1.payload.obj;
            l9 = ((vader_struct_vader_midir_InstrArraySet_t*) t0)->f_span;
            vader_midir_push_emit(l0, vader_ref_box(l3), l9);
        } else {
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir_InstrArraySet_t*) t0)->f_span;
            vader_midir_push_emit(l0, l6, l3);
        }
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 824u) {
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrArrayLen_t*) t0)->f_target;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrArrayLen_t*) t0)->f_span;
        vader_midir_emit_first_get(l0, l2, l4, l3);
        t0 = l1.payload.obj;
        t5 = ((vader_struct_vader_midir_InstrArrayLen_t*) t0)->f_resolve_buf;
        vader_struct_vader_bytecode_ArrayLen_t* _a30_obj = (vader_struct_vader_bytecode_ArrayLen_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_ArrayLen_t));
        vader_obj_header_init(_a30_obj, 494u);
        _a30_obj->f_resolve_buf = t5;
        l3 = (void*) _a30_obj;
        t0 = l1.payload.obj;
        l9 = ((vader_struct_vader_midir_InstrArrayLen_t*) t0)->f_span;
        vader_midir_push_emit(l0, vader_ref_box(l3), l9);
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrArrayLen_t*) t0)->f_dst;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrArrayLen_t*) t0)->f_span;
        vader_midir_emit_result(l0, l2, l4, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 826u) {
        l3 = ((vader_struct_vader_midir_CFGFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_fn_)->f_locals;
        t0 = l1.payload.obj;
        t1 = ((int64_t) (int32_t) ((vader_struct_vader_midir_InstrArrayPush_t*) t0)->f_value);
        l5 = (size_t) (int64_t) t1;
        vader_array_t* _a31_slotarr = ((vader_array_t*) l3);
        if (_a31_slotarr->buf != NULL && _a31_slotarr->buf->header.forward != NULL) { _a31_slotarr->buf = vader_array_buf_forward(_a31_slotarr->buf); }
        if ((size_t) l5 >= _a31_slotarr->length) { vader_trap("array index out of bounds"); }
        t0 = vader_array_ref_load_obj(_a31_slotarr->buf, _a31_slotarr->offset + (size_t) l5);
        l6 = ((vader_struct_vader_midir_CFGLocal_t*) t0)->f_type;
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
        t5 = ((vader_struct_vader_midir_InstrArrayPush_t*) t0)->f_cached;
        if (t5) {
            l3 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_local_to_slot;
            t0 = l1.payload.obj;
            t1 = ((int64_t) (int32_t) ((vader_struct_vader_midir_InstrArrayPush_t*) t0)->f_target);
            l5 = (size_t) (int64_t) t1;
            vader_array_t* _a32_slotarr = ((vader_array_t*) l3);
            if (_a32_slotarr->buf != NULL && _a32_slotarr->buf->header.forward != NULL) { _a32_slotarr->buf = vader_array_buf_forward(_a32_slotarr->buf); }
            if ((size_t) l5 >= _a32_slotarr->length) { vader_trap("array index out of bounds"); }
            l4 = ((int32_t*) _a32_slotarr->buf->slots)[_a32_slotarr->offset + (size_t) l5];
        } else {
            l4 = -(INT32_C(1));
        }
        l3 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project;
        t2 = vader_bytecode_intern_type(l6, l3);
        vader_struct_vader_bytecode_ArrayPush_t* _a33_obj = (vader_struct_vader_bytecode_ArrayPush_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_ArrayPush_t));
        vader_obj_header_init(_a33_obj, 496u);
        _a33_obj->f_type_id = t2;
        _a33_obj->f_cache_slot = l4;
        l3 = (void*) _a33_obj;
        t0 = l1.payload.obj;
        l9 = ((vader_struct_vader_midir_InstrArrayPush_t*) t0)->f_span;
        vader_midir_push_emit(l0, vader_ref_box(l3), l9);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 828u) {
        t0 = l1.payload.obj;
        l6 = ((vader_struct_vader_midir_InstrArraySlice_t*) t0)->f_type;
        l3 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project;
        l4 = vader_bytecode_intern_type(l6, l3);
        t0 = l1.payload.obj;
        l14 = ((vader_struct_vader_midir_InstrArraySlice_t*) t0)->f_target;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrArraySlice_t*) t0)->f_span;
        vader_midir_emit_first_get(l0, l2, l14, l3);
        t0 = l1.payload.obj;
        l14 = ((vader_struct_vader_midir_InstrArraySlice_t*) t0)->f_lo;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrArraySlice_t*) t0)->f_span;
        vader_midir_emit_get(l0, l14, l3);
        t0 = l1.payload.obj;
        l14 = ((vader_struct_vader_midir_InstrArraySlice_t*) t0)->f_hi;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrArraySlice_t*) t0)->f_span;
        vader_midir_emit_get(l0, l14, l3);
        vader_struct_vader_bytecode_ArraySlice_t* _a34_obj = (vader_struct_vader_bytecode_ArraySlice_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_ArraySlice_t));
        vader_obj_header_init(_a34_obj, 501u);
        _a34_obj->f_type_id = l4;
        l3 = (void*) _a34_obj;
        t0 = l1.payload.obj;
        l9 = ((vader_struct_vader_midir_InstrArraySlice_t*) t0)->f_span;
        vader_midir_push_emit(l0, vader_ref_box(l3), l9);
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrArraySlice_t*) t0)->f_dst;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrArraySlice_t*) t0)->f_span;
        vader_midir_emit_result(l0, l2, l4, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 847u) {
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
        vader_struct_vader_bytecode_StringSliceCodepoints_t* _a35_obj = (vader_struct_vader_bytecode_StringSliceCodepoints_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_StringSliceCodepoints_t));
        vader_obj_header_init(_a35_obj, 643u);
        l3 = (void*) _a35_obj;
        t0 = l1.payload.obj;
        l9 = ((vader_struct_vader_midir_InstrStringSlice_t*) t0)->f_span;
        vader_midir_push_emit(l0, vader_ref_box(l3), l9);
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrStringSlice_t*) t0)->f_dst;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrStringSlice_t*) t0)->f_span;
        vader_midir_emit_result(l0, l2, l4, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 848u) {
        t0 = l1.payload.obj;
        l6 = ((vader_struct_vader_midir_InstrStructNew_t*) t0)->f_type;
        l3 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project;
        l4 = vader_bytecode_intern_type(l6, l3);
        t0 = l1.payload.obj;
        l5 = ((vader_array_t*) ((vader_struct_vader_midir_InstrStructNew_t*) t0)->f_fields)->length;
        l10 = (size_t) (int64_t) INT64_C(0);
        {
            loop_1800: {
                if ((l10 < l5)) {
                    if (l10 == INT64_C(0)) {
                        t0 = l1.payload.obj;
                        vader_array_t* _a36_slotarr = ((vader_array_t*) ((vader_struct_vader_midir_InstrStructNew_t*) t0)->f_fields);
                        if (_a36_slotarr->buf != NULL && _a36_slotarr->buf->header.forward != NULL) { _a36_slotarr->buf = vader_array_buf_forward(_a36_slotarr->buf); }
                        if ((size_t) l10 >= _a36_slotarr->length) { vader_trap("array index out of bounds"); }
                        l14 = ((int32_t*) _a36_slotarr->buf->slots)[_a36_slotarr->offset + (size_t) l10];
                        t0 = l1.payload.obj;
                        l3 = ((vader_struct_vader_midir_InstrStructNew_t*) t0)->f_span;
                        vader_midir_emit_first_get(l0, l2, l14, l3);
                    } else {
                        t0 = l1.payload.obj;
                        vader_array_t* _a37_slotarr = ((vader_array_t*) ((vader_struct_vader_midir_InstrStructNew_t*) t0)->f_fields);
                        if (_a37_slotarr->buf != NULL && _a37_slotarr->buf->header.forward != NULL) { _a37_slotarr->buf = vader_array_buf_forward(_a37_slotarr->buf); }
                        if ((size_t) l10 >= _a37_slotarr->length) { vader_trap("array index out of bounds"); }
                        l24 = ((int32_t*) _a37_slotarr->buf->slots)[_a37_slotarr->offset + (size_t) l10];
                        t0 = l1.payload.obj;
                        l9 = ((vader_struct_vader_midir_InstrStructNew_t*) t0)->f_span;
                        vader_midir_emit_get(l0, l24, l9);
                    }
                    t1 = (l10 + INT64_C(1));
                    l10 = (size_t) (int64_t) t1;
                    goto loop_1800;
                }
            }
        }
        t0 = l1.payload.obj;
        l19 = ((vader_struct_vader_midir_InstrStructNew_t*) t0)->f_stack;
        vader_struct_vader_bytecode_StructNew_t* _a38_obj = (vader_struct_vader_bytecode_StructNew_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_StructNew_t));
        vader_obj_header_init(_a38_obj, 645u);
        _a38_obj->f_type_id = l4;
        _a38_obj->f_stack = l19;
        l3 = (void*) _a38_obj;
        t0 = l1.payload.obj;
        l9 = ((vader_struct_vader_midir_InstrStructNew_t*) t0)->f_span;
        vader_midir_push_emit(l0, vader_ref_box(l3), l9);
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrStructNew_t*) t0)->f_dst;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrStructNew_t*) t0)->f_span;
        vader_midir_emit_result(l0, l2, l4, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 825u) {
        t0 = l1.payload.obj;
        l6 = ((vader_struct_vader_midir_InstrArrayNew_t*) t0)->f_type;
        l3 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project;
        l4 = vader_bytecode_intern_type(l6, l3);
        t0 = l1.payload.obj;
        l5 = ((vader_array_t*) ((vader_struct_vader_midir_InstrArrayNew_t*) t0)->f_elements)->length;
        l10 = (size_t) (int64_t) INT64_C(0);
        {
            loop_1901: {
                if ((l10 < l5)) {
                    if (l10 == INT64_C(0)) {
                        t0 = l1.payload.obj;
                        vader_array_t* _a39_slotarr = ((vader_array_t*) ((vader_struct_vader_midir_InstrArrayNew_t*) t0)->f_elements);
                        if (_a39_slotarr->buf != NULL && _a39_slotarr->buf->header.forward != NULL) { _a39_slotarr->buf = vader_array_buf_forward(_a39_slotarr->buf); }
                        if ((size_t) l10 >= _a39_slotarr->length) { vader_trap("array index out of bounds"); }
                        l14 = ((int32_t*) _a39_slotarr->buf->slots)[_a39_slotarr->offset + (size_t) l10];
                        t0 = l1.payload.obj;
                        l3 = ((vader_struct_vader_midir_InstrArrayNew_t*) t0)->f_span;
                        vader_midir_emit_first_get(l0, l2, l14, l3);
                    } else {
                        t0 = l1.payload.obj;
                        vader_array_t* _a40_slotarr = ((vader_array_t*) ((vader_struct_vader_midir_InstrArrayNew_t*) t0)->f_elements);
                        if (_a40_slotarr->buf != NULL && _a40_slotarr->buf->header.forward != NULL) { _a40_slotarr->buf = vader_array_buf_forward(_a40_slotarr->buf); }
                        if ((size_t) l10 >= _a40_slotarr->length) { vader_trap("array index out of bounds"); }
                        l24 = ((int32_t*) _a40_slotarr->buf->slots)[_a40_slotarr->offset + (size_t) l10];
                        t0 = l1.payload.obj;
                        l9 = ((vader_struct_vader_midir_InstrArrayNew_t*) t0)->f_span;
                        vader_midir_emit_get(l0, l24, l9);
                    }
                    t1 = (l10 + INT64_C(1));
                    l10 = (size_t) (int64_t) t1;
                    goto loop_1901;
                }
            }
        }
        t0 = l1.payload.obj;
        l14 = ((vader_struct_vader_midir_InstrArrayNew_t*) t0)->f_length;
        vader_struct_vader_bytecode_ArrayNew_t* _a41_obj = (vader_struct_vader_bytecode_ArrayNew_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_ArrayNew_t));
        vader_obj_header_init(_a41_obj, 495u);
        _a41_obj->f_type_id = l4;
        _a41_obj->f_length = l14;
        l3 = (void*) _a41_obj;
        t0 = l1.payload.obj;
        l9 = ((vader_struct_vader_midir_InstrArrayNew_t*) t0)->f_span;
        vader_midir_push_emit(l0, vader_ref_box(l3), l9);
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrArrayNew_t*) t0)->f_dst;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrArrayNew_t*) t0)->f_span;
        vader_midir_emit_result(l0, l2, l4, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 837u) {
        t0 = l1.payload.obj;
        l6 = ((vader_struct_vader_midir_InstrDataConst_t*) t0)->f_type;
        l3 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project;
        l4 = vader_bytecode_intern_type(l6, l3);
        t0 = l1.payload.obj;
        t2 = ((vader_struct_vader_midir_InstrDataConst_t*) t0)->f_pool_index;
        vader_struct_vader_bytecode_DataConst_t* _a42_obj = (vader_struct_vader_bytecode_DataConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_DataConst_t));
        vader_obj_header_init(_a42_obj, 544u);
        _a42_obj->f_pool_index = t2;
        _a42_obj->f_type_id = l4;
        l3 = (void*) _a42_obj;
        t0 = l1.payload.obj;
        l9 = ((vader_struct_vader_midir_InstrDataConst_t*) t0)->f_span;
        vader_midir_push_emit(l0, vader_ref_box(l3), l9);
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrDataConst_t*) t0)->f_dst;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrDataConst_t*) t0)->f_span;
        vader_midir_emit_result(l0, l2, l4, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 849u) {
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrTypeCheck_t*) t0)->f_value;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrTypeCheck_t*) t0)->f_span;
        vader_midir_emit_first_get(l0, l2, l4, l3);
        t0 = l1.payload.obj;
        l6 = ((vader_struct_vader_midir_InstrTypeCheck_t*) t0)->f_check_type;
        l3 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project;
        t2 = vader_bytecode_intern_type(l6, l3);
        vader_struct_vader_bytecode_TypeCheck_t* _a43_obj = (vader_struct_vader_bytecode_TypeCheck_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_TypeCheck_t));
        vader_obj_header_init(_a43_obj, 647u);
        _a43_obj->f_type_id = t2;
        l3 = (void*) _a43_obj;
        t0 = l1.payload.obj;
        l9 = ((vader_struct_vader_midir_InstrTypeCheck_t*) t0)->f_span;
        vader_midir_push_emit(l0, vader_ref_box(l3), l9);
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrTypeCheck_t*) t0)->f_dst;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrTypeCheck_t*) t0)->f_span;
        vader_midir_emit_result(l0, l2, l4, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 850u) {
        t0 = l1.payload.obj;
        l6 = ((vader_struct_vader_midir_InstrTypeConst_t*) t0)->f_value_type;
        l3 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project;
        t2 = vader_bytecode_intern_type(l6, l3);
        vader_struct_vader_bytecode_TypeConst_t* _a44_obj = (vader_struct_vader_bytecode_TypeConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_TypeConst_t));
        vader_obj_header_init(_a44_obj, 648u);
        _a44_obj->f_type_id = t2;
        l3 = (void*) _a44_obj;
        t0 = l1.payload.obj;
        l9 = ((vader_struct_vader_midir_InstrTypeConst_t*) t0)->f_span;
        vader_midir_push_emit(l0, vader_ref_box(l3), l9);
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrTypeConst_t*) t0)->f_dst;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrTypeConst_t*) t0)->f_span;
        vader_midir_emit_result(l0, l2, l4, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 832u) {
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrCast_t*) t0)->f_value;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrCast_t*) t0)->f_span;
        vader_midir_emit_first_get(l0, l2, l4, l3);
        l3 = ((vader_struct_vader_midir_CFGFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_fn_)->f_locals;
        t0 = l1.payload.obj;
        t1 = ((int64_t) (int32_t) ((vader_struct_vader_midir_InstrCast_t*) t0)->f_value);
        l5 = (size_t) (int64_t) t1;
        vader_array_t* _a45_slotarr = ((vader_array_t*) l3);
        if (_a45_slotarr->buf != NULL && _a45_slotarr->buf->header.forward != NULL) { _a45_slotarr->buf = vader_array_buf_forward(_a45_slotarr->buf); }
        if ((size_t) l5 >= _a45_slotarr->length) { vader_trap("array index out of bounds"); }
        t0 = vader_array_ref_load_obj(_a45_slotarr->buf, _a45_slotarr->offset + (size_t) l5);
        l7 = vader_bytecode_val_type_of_type(((vader_struct_vader_midir_CFGLocal_t*) t0)->f_type);
        t0 = l1.payload.obj;
        l8 = vader_bytecode_val_type_of_type(((vader_struct_vader_midir_InstrCast_t*) t0)->f_type);
        l4 = ((int32_t) (uint8_t) l7);
        l14 = ((int32_t) (uint8_t) l8);
        if (l4 != l14) {
            l6 = vader_bytecode_convert_target_of(l8);
            if (l6.tag == 0u) {
                t0 = l1.payload.obj;
                l18 = ((vader_struct_vader_midir_InstrCast_t*) t0)->f_type;
                l3 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project;
                t2 = vader_bytecode_intern_type(l18, l3);
                vader_struct_vader_bytecode_RefCast_t* _a46_obj = (vader_struct_vader_bytecode_RefCast_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_RefCast_t));
                vader_obj_header_init(_a46_obj, 626u);
                _a46_obj->f_type_id = t2;
                l3 = (void*) _a46_obj;
                t0 = l1.payload.obj;
                l9 = ((vader_struct_vader_midir_InstrCast_t*) t0)->f_span;
                vader_midir_push_emit(l0, vader_ref_box(l3), l9);
            } else {
                t5 = vader_midir_convert_eligible(l7);
                if (t5) {
                    l15 = vader_bytecode_val_type_name(l7);
                    l7 = ((uint8_t) l6.payload.i);
                    vader_struct_vader_bytecode_Convert_t* _a47_obj = (vader_struct_vader_bytecode_Convert_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_Convert_t));
                    vader_obj_header_init(_a47_obj, 543u);
                    _a47_obj->f_from_name = l15;
                    _a47_obj->f_target = l7;
                    l3 = (void*) _a47_obj;
                    t0 = l1.payload.obj;
                    l9 = ((vader_struct_vader_midir_InstrCast_t*) t0)->f_span;
                    vader_midir_push_emit(l0, vader_ref_box(l3), l9);
                } else {
                    t0 = l1.payload.obj;
                    l6 = ((vader_struct_vader_midir_InstrCast_t*) t0)->f_type;
                    l3 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project;
                    t2 = vader_bytecode_intern_type(l6, l3);
                    vader_struct_vader_bytecode_RefCast_t* _a48_obj = (vader_struct_vader_bytecode_RefCast_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_RefCast_t));
                    vader_obj_header_init(_a48_obj, 626u);
                    _a48_obj->f_type_id = t2;
                    l3 = (void*) _a48_obj;
                    t0 = l1.payload.obj;
                    l9 = ((vader_struct_vader_midir_InstrCast_t*) t0)->f_span;
                    vader_midir_push_emit(l0, vader_ref_box(l3), l9);
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
    if (l1.tag == 834u) {
        t0 = l1.payload.obj;
        l6 = ((vader_struct_vader_midir_InstrCellNew_t*) t0)->f_value_type;
        l3 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project;
        l4 = vader_bytecode_intern_cell_type(l6, l3);
        t0 = l1.payload.obj;
        l14 = ((vader_struct_vader_midir_InstrCellNew_t*) t0)->f_value;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrCellNew_t*) t0)->f_span;
        vader_midir_emit_first_get(l0, l2, l14, l3);
        vader_struct_vader_bytecode_StructNew_t* _a49_obj = (vader_struct_vader_bytecode_StructNew_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_StructNew_t));
        vader_obj_header_init(_a49_obj, 645u);
        _a49_obj->f_type_id = l4;
        _a49_obj->f_stack = false;
        l3 = (void*) _a49_obj;
        t0 = l1.payload.obj;
        l9 = ((vader_struct_vader_midir_InstrCellNew_t*) t0)->f_span;
        vader_midir_push_emit(l0, vader_ref_box(l3), l9);
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrCellNew_t*) t0)->f_dst;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrCellNew_t*) t0)->f_span;
        vader_midir_emit_result(l0, l2, l4, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 833u) {
        t0 = l1.payload.obj;
        l6 = ((vader_struct_vader_midir_InstrCellGet_t*) t0)->f_value_type;
        l3 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project;
        l4 = vader_bytecode_intern_cell_type(l6, l3);
        l19 = std_collections_MutableSet_Contains_contains__i64(((vader_struct_vader_midir_ScheduleHints_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_hints)->f_skip_first_get, l2);
        t0 = l1.payload.obj;
        l14 = ((vader_struct_vader_midir_InstrCellGet_t*) t0)->f_cell;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrCellGet_t*) t0)->f_span;
        vader_midir_emit_first_get(l0, l2, l14, l3);
        l23 = false;
        if (!(l19)) {
            l23 = vader_midir_try_fuse_local_field(l0, l4, INT32_C(0));
        }
        if (!(l23)) {
            vader_struct_vader_bytecode_StructGet_t* _a50_obj = (vader_struct_vader_bytecode_StructGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_StructGet_t));
            vader_obj_header_init(_a50_obj, 644u);
            _a50_obj->f_type_id = l4;
            _a50_obj->f_field_index = INT32_C(0);
            l3 = (void*) _a50_obj;
            t0 = l1.payload.obj;
            l9 = ((vader_struct_vader_midir_InstrCellGet_t*) t0)->f_span;
            vader_midir_push_emit(l0, vader_ref_box(l3), l9);
        }
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrCellGet_t*) t0)->f_dst;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrCellGet_t*) t0)->f_span;
        vader_midir_emit_result(l0, l2, l4, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 835u) {
        t0 = l1.payload.obj;
        l6 = ((vader_struct_vader_midir_InstrCellSet_t*) t0)->f_value_type;
        l3 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project;
        l4 = vader_bytecode_intern_cell_type(l6, l3);
        t0 = l1.payload.obj;
        l14 = ((vader_struct_vader_midir_InstrCellSet_t*) t0)->f_cell;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrCellSet_t*) t0)->f_span;
        vader_midir_emit_first_get(l0, l2, l14, l3);
        t0 = l1.payload.obj;
        l14 = ((vader_struct_vader_midir_InstrCellSet_t*) t0)->f_value;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrCellSet_t*) t0)->f_span;
        vader_midir_emit_get(l0, l14, l3);
        vader_struct_vader_bytecode_StructSet_t* _a51_obj = (vader_struct_vader_bytecode_StructSet_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_StructSet_t));
        vader_obj_header_init(_a51_obj, 646u);
        _a51_obj->f_type_id = l4;
        _a51_obj->f_field_index = INT32_C(0);
        _a51_obj->f_stack = false;
        l3 = (void*) _a51_obj;
        t0 = l1.payload.obj;
        l9 = ((vader_struct_vader_midir_InstrCellSet_t*) t0)->f_span;
        vader_midir_push_emit(l0, vader_ref_box(l3), l9);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 845u) {
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrMakeClosure_t*) t0)->f_env;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrMakeClosure_t*) t0)->f_span;
        vader_midir_emit_first_get(l0, l2, l4, l3);
        t0 = l1.payload.obj;
        l6 = vader_midir_closure_header_type(((vader_struct_vader_midir_InstrMakeClosure_t*) t0)->f_type);
        l3 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project;
        l4 = vader_bytecode_intern_type(l6, l3);
        l3 = ((vader_struct_vader_bytecode_EmitterCtx_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project)->f_function_index_by_symbol_id;
        t0 = l1.payload.obj;
        l14 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_midir_InstrMakeClosure_t*) t0)->f_fn_symbol)->f_id;
        l6 = std_collections_MutableMap_Index_at__i32__i32(l3, l14);
        if (l6.tag == 179u) {
            t2 = ((int32_t) l6.payload.i);
            vader_struct_vader_bytecode_MakeClosure_t* _a52_obj = (vader_struct_vader_bytecode_MakeClosure_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_MakeClosure_t));
            vader_obj_header_init(_a52_obj, 623u);
            _a52_obj->f_function_index = t2;
            _a52_obj->f_env_type_id = l4;
            l3 = (void*) _a52_obj;
            t0 = l1.payload.obj;
            l9 = ((vader_struct_vader_midir_InstrMakeClosure_t*) t0)->f_span;
            vader_midir_push_emit(l0, vader_ref_box(l3), l9);
        } else {
            t0 = l1.payload.obj;
            l15 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_midir_InstrMakeClosure_t*) t0)->f_fn_symbol)->f_name;
            l5 = vader_host_std_core_byte_len(l15);
            l3 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(109) + l5));
            l5 = (size_t) (int64_t) INT64_C(0);
            l5 = std_core_write_string_at(l3, l5, 1940u);
            l5 = std_core_write_string_at(l3, l5, l15);
            l5 = std_core_write_string_at(l3, l5, 287u);
            t0 = l1.payload.obj;
            t2 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_midir_InstrMakeClosure_t*) t0)->f_fn_symbol)->f_id;
            l17 = ((int64_t) (int32_t) t2);
            l5 = std_core_write_int(l3, l5, l17);
            l5 = std_core_write_string_at(l3, l5, 367u);
            t3 = std_core_finish_buffer(l3, l5);
            vader_host_std_abort_panic(t3);
        }
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrMakeClosure_t*) t0)->f_dst;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrMakeClosure_t*) t0)->f_span;
        vader_midir_emit_result(l0, l2, l4, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 844u) {
        t0 = l1.payload.obj;
        l5 = ((vader_array_t*) ((vader_struct_vader_midir_InstrIntrinsic_t*) t0)->f_args)->length;
        l10 = (size_t) (int64_t) INT64_C(0);
        {
            loop_2554: {
                if ((l10 < l5)) {
                    if (l10 == INT64_C(0)) {
                        t0 = l1.payload.obj;
                        vader_array_t* _a53_slotarr = ((vader_array_t*) ((vader_struct_vader_midir_InstrIntrinsic_t*) t0)->f_args);
                        if (_a53_slotarr->buf != NULL && _a53_slotarr->buf->header.forward != NULL) { _a53_slotarr->buf = vader_array_buf_forward(_a53_slotarr->buf); }
                        if ((size_t) l10 >= _a53_slotarr->length) { vader_trap("array index out of bounds"); }
                        l4 = ((int32_t*) _a53_slotarr->buf->slots)[_a53_slotarr->offset + (size_t) l10];
                        t0 = l1.payload.obj;
                        l3 = ((vader_struct_vader_midir_InstrIntrinsic_t*) t0)->f_span;
                        vader_midir_emit_first_get(l0, l2, l4, l3);
                    } else {
                        t0 = l1.payload.obj;
                        vader_array_t* _a54_slotarr = ((vader_array_t*) ((vader_struct_vader_midir_InstrIntrinsic_t*) t0)->f_args);
                        if (_a54_slotarr->buf != NULL && _a54_slotarr->buf->header.forward != NULL) { _a54_slotarr->buf = vader_array_buf_forward(_a54_slotarr->buf); }
                        if ((size_t) l10 >= _a54_slotarr->length) { vader_trap("array index out of bounds"); }
                        l14 = ((int32_t*) _a54_slotarr->buf->slots)[_a54_slotarr->offset + (size_t) l10];
                        t0 = l1.payload.obj;
                        l9 = ((vader_struct_vader_midir_InstrIntrinsic_t*) t0)->f_span;
                        vader_midir_emit_get(l0, l14, l9);
                    }
                    t1 = (l10 + INT64_C(1));
                    l10 = (size_t) (int64_t) t1;
                    goto loop_2554;
                }
            }
        }
        t0 = l1.payload.obj;
        t3 = ((vader_struct_vader_midir_InstrIntrinsic_t*) t0)->f_name;
        l6 = vader_midir_intrinsic_op_for_name(t3);
        if (l6.tag == 0u) {
            t0 = l1.payload.obj;
            l15 = ((vader_struct_vader_midir_InstrIntrinsic_t*) t0)->f_name;
            l16 = ((vader_struct_vader_midir_CFGFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_fn_)->f_mangled;
            t3 = concat_5(1938u, l15, 1017u, l16, 301u);
            vader_host_std_abort_panic(t3);
        }
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrIntrinsic_t*) t0)->f_span;
        vader_midir_push_emit(l0, l6, l3);
        t0 = l1.payload.obj;
        l6 = ((vader_struct_vader_midir_InstrIntrinsic_t*) t0)->f_dst;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrIntrinsic_t*) t0)->f_span;
        vader_midir_emit_result_if_any(l0, l2, l6, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 839u) {
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrDeferPush_t*) t0)->f_value;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrDeferPush_t*) t0)->f_span;
        vader_midir_emit_first_get(l0, l2, l4, l3);
        vader_struct_vader_bytecode_DeferPush_t* _a55_obj = (vader_struct_vader_bytecode_DeferPush_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_DeferPush_t));
        vader_obj_header_init(_a55_obj, 547u);
        l3 = (void*) _a55_obj;
        t0 = l1.payload.obj;
        l9 = ((vader_struct_vader_midir_InstrDeferPush_t*) t0)->f_span;
        vader_midir_push_emit(l0, vader_ref_box(l3), l9);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 838u) {
        t0 = l1.payload.obj;
        t2 = ((vader_struct_vader_midir_InstrDeferPopExec_t*) t0)->f_count;
        vader_struct_vader_bytecode_DeferPopExec_t* _a56_obj = (vader_struct_vader_bytecode_DeferPopExec_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_DeferPopExec_t));
        vader_obj_header_init(_a56_obj, 546u);
        _a56_obj->f_count = t2;
        l3 = (void*) _a56_obj;
        t0 = l1.payload.obj;
        l9 = ((vader_struct_vader_midir_InstrDeferPopExec_t*) t0)->f_span;
        vader_midir_push_emit(l0, vader_ref_box(l3), l9);
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_host_std_abort_panic(1937u);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_midir_emit_range(void* l0, int32_t l1, int32_t l2) {
    int32_t l3, l4, l11, l13, l15, l19, l20, l22;
    bool l5, l9;
    void* l6 = NULL;
    void* l8 = NULL;
    void* l10 = NULL;
    void* l12 = NULL;
    void* l16 = NULL;
    void* l17 = NULL;
    void* l18 = NULL;
    void* l21 = NULL;
    void* l23 = NULL;
    void* l24 = NULL;
    size_t l7;
    vader_box_t l14 = vader_box_null();
    bool t0;
    int64_t t1;
    vader_box_t* gc_roots[1] = { &l14 };
    void** gc_raw_roots[11] = { &l0, &l6, &l8, &l10, &l12, &l16, &l17, &l18, &l21, &l23, &l24 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 11u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = l1;
    {
        loop_3: {
            l4 = -(INT32_C(1));
            t0 = vader_midir_BlockId_Equals_equals(l3, l4);
            if (!(t0)) {
                t0 = vader_midir_BlockId_Equals_equals(l3, l2);
                l5 = !(t0);
            } else {
                l5 = false;
            }
            if (l5) {
                l6 = ((vader_struct_vader_midir_CFGFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_fn_)->f_blocks;
                t1 = ((int64_t) (int32_t) l3);
                l7 = (size_t) (int64_t) t1;
                vader_array_t* _a0_slotarr = ((vader_array_t*) l6);
                if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                if ((size_t) l7 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                l8 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l7);
                l9 = false;
                l10 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_wrapped_loop_headers;
                l11 = l3;
                t0 = std_collections_MutableSet_Contains_contains__i32(l10, l11);
                if (!(t0)) {
                    t0 = vader_midir_loop_exit_present(l0, l3);
                    if (t0) {
                        l9 = true;
                    }
                }
                if (l9) {
                    l12 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_loop_exit;
                    l13 = l3;
                    l14 = std_collections_MutableMap_Index_at__i32__Any(l12, l13);
                    l15 = -(INT32_C(1));
                    if (l14.tag == 179u) {
                        l15 = ((int32_t) l14.payload.i);
                    }
                    l16 = ((vader_struct_vader_midir_BasicBlock_t*) l8)->f_span;
                    vader_midir_cf_block(l0, l16, l15);
                    l17 = ((vader_struct_vader_midir_BasicBlock_t*) l8)->f_span;
                    vader_midir_cf_loop(l0, l17, l3);
                    l18 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_wrapped_loop_headers;
                    l19 = l3;
                    std_collections_add__i32(l18, l19);
                    l20 = -(INT32_C(1));
                    if (l14.tag == 179u) {
                        l20 = ((int32_t) l14.payload.i);
                    }
                    vader_midir_emit_range(l0, l3, l20);
                    l21 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_wrapped_loop_headers;
                    l22 = l3;
                    std_collections_remove__i32(l21, l22);
                    l23 = ((vader_struct_vader_midir_BasicBlock_t*) l8)->f_span;
                    vader_midir_cf_end(l0, l23);
                    l24 = ((vader_struct_vader_midir_BasicBlock_t*) l8)->f_span;
                    vader_midir_cf_end(l0, l24);
                    if (l14.tag == 179u) {
                        l3 = ((int32_t) l14.payload.i);
                    } else {
                        l3 = -(INT32_C(1));
                    }
                    goto loop_3;
                }
                l3 = vader_midir_emit_block_contents(l0, l3, l2);
                goto loop_3;
            }
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_midir_emit_result(void* l0, int64_t l1, int32_t l2, void* l3) {
    bool t0;
    void** gc_raw_roots[2] = { &l0, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = std_collections_MutableSet_Contains_contains__i64(((vader_struct_vader_midir_ScheduleHints_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_hints)->f_skip_set, l1);
    if (t0) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_midir_emit_set(l0, l2, l3);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_midir_emit_result_if_any(void* l0, int64_t l1, vader_box_t l2, void* l3) {
    int32_t l4;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[2] = { &l0, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l2.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l4 = ((int32_t) l2.payload.i);
    vader_midir_emit_result(l0, l1, l4, l3);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_midir_emit_return_boxing(void* l0, int32_t l1, size_t l2, void* l3) {
    void* l4 = NULL;
    size_t l5;
    vader_box_t l6 = vader_box_null(), l8 = vader_box_null();
    uint8_t l7, l9;
    bool l10, l11;
    int64_t t0;
    void* t1 = NULL;
    size_t t2;
    int32_t t3;
    vader_box_t* gc_roots[2] = { &l6, &l8 };
    void** gc_raw_roots[4] = { &l0, &l3, &l4, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l4 = ((vader_struct_vader_midir_CFGFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_fn_)->f_locals;
    t0 = ((int64_t) (int32_t) l1);
    l5 = (size_t) (int64_t) t0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    if ((size_t) l5 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
    t1 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
    l6 = ((vader_struct_vader_midir_CFGLocal_t*) t1)->f_type;
    l7 = vader_bytecode_val_type_of_type(l6);
    t2 = ((vader_array_t*) ((vader_struct_vader_midir_CFGFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_fn_)->f_scalarised_results)->length;
    if ((t2 > l2)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_midir_CFGFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_fn_)->f_scalarised_results);
        if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
        if ((size_t) l2 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
        l8 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l2);
    } else {
        l8 = ((vader_struct_vader_midir_CFGFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_fn_)->f_return_type;
    }
    l9 = vader_bytecode_val_type_of_type(l8);
    if (l9 == INT32_C(18)) {
        l10 = true;
    } else {
        l10 = l9 == INT32_C(19);
    }
    if (l7 == INT32_C(18)) {
        l11 = true;
    } else {
        l11 = l7 == INT32_C(19);
    }
    if (l11) {
        l11 = true;
    } else {
        l11 = l7 == INT32_C(16);
    }
    l11 = !(l11);
    if (l10) {
        l10 = l11;
    } else {
        l10 = false;
    }
    if (l10) {
        l4 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project;
        t3 = vader_bytecode_intern_type(l6, l4);
        vader_struct_vader_bytecode_Box_t* _a2_obj = (vader_struct_vader_bytecode_Box_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_Box_t));
        vader_obj_header_init(_a2_obj, 531u);
        _a2_obj->f_type_id = t3;
        l4 = (void*) _a2_obj;
        vader_midir_push_emit(l0, vader_ref_box(l4), l3);
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
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
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    if ((size_t) l4 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
    t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l4];
    vader_struct_vader_bytecode_LocalSet_t* _a1_obj = (vader_struct_vader_bytecode_LocalSet_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_LocalSet_t));
    vader_obj_header_init(_a1_obj, 620u);
    _a1_obj->f_slot = t1;
    l3 = (void*) _a1_obj;
    vader_midir_push_emit(l0, vader_ref_box(l3), l2);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static vader_string_t vader_midir_extern_library_name(void* l0) {
    void* l1;
    void* l4;
    size_t l2, l3;
    bool l5, l7;
    vader_box_t l6, l8;
    vader_string_t t0;
    size_t t1;
    void* t2;
    int64_t t3;
    l1 = ((vader_struct_toolchain_ast_FnDecl_t*) l0)->f_decorators;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    l2 = ((vader_array_t*) l1)->length;
    l3 = (size_t) (int64_t) INT64_C(0);
    {
        loop_7: {
            if ((l3 < l2)) {
                if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                l4 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
                t0 = ((vader_struct_toolchain_ast_Decorator_t*) l4)->f_name;
                if (t0 == 1600u) {
                    t1 = ((vader_array_t*) ((vader_struct_toolchain_ast_Decorator_t*) l4)->f_args)->length;
                    l5 = t1 == INT64_C(2);
                } else {
                    l5 = false;
                }
                if (l5) {
                    vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_Decorator_t*) l4)->f_args);
                    if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                    if ((size_t) INT32_C(0) >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                    l6 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) INT32_C(0));
                    if (l6.tag == 465u) {
                        t2 = l6.payload.obj;
                        t1 = ((vader_array_t*) ((vader_struct_toolchain_ast_StringLitExpr_t*) t2)->f_parts)->length;
                        l7 = t1 == INT64_C(1);
                    } else {
                        l7 = false;
                    }
                    if (l7) {
                        t2 = l6.payload.obj;
                        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_StringLitExpr_t*) t2)->f_parts);
                        if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                        if ((size_t) INT32_C(0) >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                        l8 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) INT32_C(0));
                        if (l8.tag == 467u) {
                            t2 = l8.payload.obj;
                            t0 = ((vader_struct_toolchain_ast_StringLitText_t*) t2)->f_value;
                            return t0;
                        }
                    }
                }
                t3 = (l3 + INT64_C(1));
                l3 = (size_t) (int64_t) t3;
                goto loop_7;
            }
        }
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
    vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    l2 = ((vader_array_t*) l1)->length;
    l3 = (size_t) (int64_t) INT64_C(0);
    {
        loop_7: {
            if ((l3 < l2)) {
                if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                l4 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
                t0 = ((vader_struct_toolchain_ast_Decorator_t*) l4)->f_name;
                if (t0 != 1600u) {
                    t1 = (l3 + INT64_C(1));
                    l3 = (size_t) (int64_t) t1;
                    goto loop_7;
                }
                t2 = ((vader_array_t*) ((vader_struct_toolchain_ast_Decorator_t*) l4)->f_args)->length;
                if (t2 == INT64_C(0)) {
                    t1 = (l3 + INT64_C(1));
                    l3 = (size_t) (int64_t) t1;
                    goto loop_7;
                }
                l5 = ((vader_struct_toolchain_ast_Decorator_t*) l4)->f_args;
                t2 = ((vader_array_t*) ((vader_struct_toolchain_ast_Decorator_t*) l4)->f_args)->length;
                t1 = (t2 - INT64_C(1));
                l6 = (size_t) (int64_t) t1;
                vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l6 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                l7 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l6);
                if (l7.tag == 465u) {
                    t3 = l7.payload.obj;
                    t2 = ((vader_array_t*) ((vader_struct_toolchain_ast_StringLitExpr_t*) t3)->f_parts)->length;
                    if (t2 == INT64_C(1)) {
                        t3 = l7.payload.obj;
                        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_StringLitExpr_t*) t3)->f_parts);
                        if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                        if ((size_t) INT32_C(0) >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                        t4 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) INT32_C(0));
                        if (t4.tag == 467u) {
                            t3 = l7.payload.obj;
                            vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_StringLitExpr_t*) t3)->f_parts);
                            if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                            if ((size_t) INT32_C(0) >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                            t4 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) INT32_C(0));
                            t3 = t4.payload.obj;
                            t0 = ((vader_struct_toolchain_ast_StringLitText_t*) t3)->f_value;
                            return t0;
                        }
                    }
                }
                t1 = (l3 + INT64_C(1));
                l3 = (size_t) (int64_t) t1;
                goto loop_7;
            }
        }
    }
    t0 = ((vader_struct_toolchain_ast_FnDecl_t*) l0)->f_name;
    return t0;
}

static void* vader_midir_find_loop_exits(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l10 = NULL;
    void* l12 = NULL;
    void* l17 = NULL;
    void* l19 = NULL;
    size_t l7, l8, l18, l20, l21;
    int32_t l9, l11, l14, l15, l16, l22;
    vader_box_t l13 = vader_box_null();
    int64_t t0;
    size_t t1;
    bool t2;
    void* t3 = NULL;
    vader_box_t* gc_roots[1] = { &l13 };
    void** gc_raw_roots[12] = { &l0, &l1, &l2, &l3, &l4, &l5, &l6, &l10, &l12, &l17, &l19, &t3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 12u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(9u, 0u, 7u, 179u);
    l3 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(16u, 0u, 0u, 187u);
    l4 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 179u);
    l5 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__i32__Any_t* _a3_obj = (vader_struct_std_collections_MutableMap__i32__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__Any_t));
    vader_obj_header_init(_a3_obj, 287u);
    _a3_obj->f_ekeys = l3;
    _a3_obj->f_evals = l4;
    _a3_obj->f_index = l5;
    _a3_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l3 = (void*) _a3_obj;
    l4 = vader_midir_natural_loop_bodies(l0, l1, l2);
    l5 = ((vader_struct_std_collections_MutableMap__i32__MutableSet_i32__t*) l4)->f_ekeys;
    l6 = ((vader_struct_std_collections_MutableMap__i32__MutableSet_i32__t*) l4)->f_evals;
    l7 = ((vader_struct_std_collections_MutableMap__i32__MutableSet_i32__t*) l4)->f_size;
    l8 = (size_t) (int64_t) INT64_C(0);
    {
        loop_29: {
            if ((l8 >= l7)) {
            } else {
                vader_array_t* _a4_slotarr = ((vader_array_t*) l5);
                if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                if ((size_t) l8 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                l9 = ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l8];
                vader_array_t* _a5_slotarr = ((vader_array_t*) l6);
                if (_a5_slotarr->buf != NULL && _a5_slotarr->buf->header.forward != NULL) { _a5_slotarr->buf = vader_array_buf_forward(_a5_slotarr->buf); }
                if ((size_t) l8 >= _a5_slotarr->length) { vader_trap("array index out of bounds"); }
                l4 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l8);
                vader_struct___Tuple_2_6ec7a632f940f1af_t* _a6_obj = (vader_struct___Tuple_2_6ec7a632f940f1af_t*) vader_gc_alloc(sizeof(vader_struct___Tuple_2_6ec7a632f940f1af_t));
                vader_obj_header_init(_a6_obj, 219u);
                _a6_obj->f__0 = l9;
                _a6_obj->f__1 = l4;
                l10 = (void*) _a6_obj;
                l11 = ((vader_struct___Tuple_2_6ec7a632f940f1af_t*) l10)->f__0;
                l12 = ((vader_struct___Tuple_2_6ec7a632f940f1af_t*) l10)->f__1;
                t0 = (l8 + INT64_C(1));
                l8 = (size_t) (int64_t) t0;
                l13 = vader_box_obj(0u, NULL);
                t1 = ((vader_array_t*) ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_blocks)->length;
                l14 = ((int32_t) (size_t) t1);
                l15 = INT32_C(0);
                {
                    loop_64: {
                        if ((l15 < l14)) {
                            l16 = l15;
                            t2 = std_collections_MutableSet_Contains_contains__i32(l12, l16);
                            if (t2) {
                                l17 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_blocks;
                                t0 = ((int64_t) (int32_t) l15);
                                l18 = (size_t) (int64_t) t0;
                                vader_array_t* _a7_slotarr = ((vader_array_t*) l17);
                                if (_a7_slotarr->buf != NULL && _a7_slotarr->buf->header.forward != NULL) { _a7_slotarr->buf = vader_array_buf_forward(_a7_slotarr->buf); }
                                if ((size_t) l18 >= _a7_slotarr->length) { vader_trap("array index out of bounds"); }
                                t3 = vader_array_ref_load_obj(_a7_slotarr->buf, _a7_slotarr->offset + (size_t) l18);
                                l19 = vader_midir_successors_of(t3);
                                vader_array_t* _a8_slotarr = ((vader_array_t*) l19);
                                if (_a8_slotarr->buf != NULL && _a8_slotarr->buf->header.forward != NULL) { _a8_slotarr->buf = vader_array_buf_forward(_a8_slotarr->buf); }
                                l20 = ((vader_array_t*) l19)->length;
                                l21 = (size_t) (int64_t) INT64_C(0);
                                {
                                    loop_90: {
                                        if ((l21 < l20)) {
                                            l22 = ((int32_t*) _a8_slotarr->buf->slots)[_a8_slotarr->offset + (size_t) l21];
                                            t2 = std_collections_MutableSet_Contains_contains__i32(l12, l22);
                                            if (!(t2)) {
                                                if (l13.tag == 0u) {
                                                    l13 = vader_box_i32(179u, l22);
                                                }
                                            }
                                            t0 = (l21 + INT64_C(1));
                                            l21 = (size_t) (int64_t) t0;
                                            goto loop_90;
                                        }
                                    }
                                }
                            }
                            if (!(l13.tag == 0u)) {
                            } else {
                                l15 = (l15 + INT32_C(1));
                                goto loop_64;
                            }
                        }
                    }
                }
                std_collections_MutableMap_IndexSet_set_at__i32__Any(l3, l11, l13);
                goto loop_29;
            }
        }
    }
    { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
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
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    if ((size_t) l4 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
    l5 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
    if (l5.tag == 516u) {
        t1 = l5.payload.obj;
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcStruct_t*) t1)->f_fields);
        if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
        l4 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcStruct_t*) t1)->f_fields)->length;
        l6 = (size_t) (int64_t) INT64_C(0);
        {
            loop_19: {
                if ((l6 < l4)) {
                    t1 = l5.payload.obj;
                    vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcStruct_t*) t1)->f_fields);
                    if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                    if ((size_t) l6 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                    t1 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l6);
                    t2 = ((vader_struct_vader_bytecode_BcField_t*) t1)->f_name;
                    if (t2 == l2) {
                        t3 = vader_box_i64(186u, (int64_t)(uint64_t) l6);
                        return t3;
                    }
                    t0 = (l6 + INT64_C(1));
                    l6 = (size_t) (int64_t) t0;
                    goto loop_19;
                }
            }
        }
    }
    t3 = vader_box_obj(0u, NULL);
    return t3;
}

static vader_box_t vader_midir_first_stack_operand(vader_box_t l0) {
    vader_box_t t0;
    void* t1;
    size_t t2;
    int32_t t3;
    if (l0.tag == 836u) {
        t0 = vader_box_obj(0u, NULL);
        return t0;
    }
    if (l0.tag == 843u) {
        t0 = vader_box_obj(0u, NULL);
        return t0;
    }
    if (l0.tag == 842u) {
        t0 = vader_box_obj(0u, NULL);
        return t0;
    }
    if (l0.tag == 837u) {
        t0 = vader_box_obj(0u, NULL);
        return t0;
    }
    if (l0.tag == 850u) {
        t0 = vader_box_obj(0u, NULL);
        return t0;
    }
    if (l0.tag == 846u) {
        t1 = l0.payload.obj;
        t0 = vader_box_i32(179u, ((vader_struct_vader_midir_InstrMove_t*) t1)->f_src);
        return t0;
    }
    if (l0.tag == 829u) {
        t1 = l0.payload.obj;
        t0 = vader_box_i32(179u, ((vader_struct_vader_midir_InstrBinOp_t*) t1)->f_lhs);
        return t0;
    }
    if (l0.tag == 851u) {
        t1 = l0.payload.obj;
        t0 = vader_box_i32(179u, ((vader_struct_vader_midir_InstrUnOp_t*) t1)->f_operand);
        return t0;
    }
    if (l0.tag == 830u) {
        t1 = l0.payload.obj;
        t2 = ((vader_array_t*) ((vader_struct_vader_midir_InstrCall_t*) t1)->f_args)->length;
        if ((t2 > INT64_C(0))) {
            t1 = l0.payload.obj;
            vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_midir_InstrCall_t*) t1)->f_args);
            if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
            if ((size_t) INT32_C(0) >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
            t3 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) INT32_C(0)];
            t0 = vader_box_i32(179u, t3);
            return t0;
        }
        t0 = vader_box_obj(0u, NULL);
        return t0;
    }
    if (l0.tag == 831u) {
        t1 = l0.payload.obj;
        t2 = ((vader_array_t*) ((vader_struct_vader_midir_InstrCallIndirect_t*) t1)->f_args)->length;
        if ((t2 > INT64_C(0))) {
            t1 = l0.payload.obj;
            vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_midir_InstrCallIndirect_t*) t1)->f_args);
            if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
            if ((size_t) INT32_C(0) >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
            t3 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) INT32_C(0)];
            t0 = vader_box_i32(179u, t3);
            return t0;
        }
        t1 = l0.payload.obj;
        t0 = vader_box_i32(179u, ((vader_struct_vader_midir_InstrCallIndirect_t*) t1)->f_callee);
        return t0;
    }
    if (l0.tag == 852u) {
        t1 = l0.payload.obj;
        t2 = ((vader_array_t*) ((vader_struct_vader_midir_InstrVirtualCall_t*) t1)->f_args)->length;
        if ((t2 > INT64_C(0))) {
            t1 = l0.payload.obj;
            vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_midir_InstrVirtualCall_t*) t1)->f_args);
            if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
            if ((size_t) INT32_C(0) >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
            t3 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) INT32_C(0)];
            t0 = vader_box_i32(179u, t3);
            return t0;
        }
        t1 = l0.payload.obj;
        t0 = vader_box_i32(179u, ((vader_struct_vader_midir_InstrVirtualCall_t*) t1)->f_receiver);
        return t0;
    }
    if (l0.tag == 840u) {
        t1 = l0.payload.obj;
        t0 = vader_box_i32(179u, ((vader_struct_vader_midir_InstrFieldGet_t*) t1)->f_target);
        return t0;
    }
    if (l0.tag == 841u) {
        t1 = l0.payload.obj;
        t0 = vader_box_i32(179u, ((vader_struct_vader_midir_InstrFieldSet_t*) t1)->f_target);
        return t0;
    }
    if (l0.tag == 823u) {
        t1 = l0.payload.obj;
        t0 = vader_box_i32(179u, ((vader_struct_vader_midir_InstrArrayGet_t*) t1)->f_target);
        return t0;
    }
    if (l0.tag == 827u) {
        t1 = l0.payload.obj;
        t0 = vader_box_i32(179u, ((vader_struct_vader_midir_InstrArraySet_t*) t1)->f_target);
        return t0;
    }
    if (l0.tag == 824u) {
        t1 = l0.payload.obj;
        t0 = vader_box_i32(179u, ((vader_struct_vader_midir_InstrArrayLen_t*) t1)->f_target);
        return t0;
    }
    if (l0.tag == 826u) {
        t1 = l0.payload.obj;
        t0 = vader_box_i32(179u, ((vader_struct_vader_midir_InstrArrayPush_t*) t1)->f_target);
        return t0;
    }
    if (l0.tag == 828u) {
        t1 = l0.payload.obj;
        t0 = vader_box_i32(179u, ((vader_struct_vader_midir_InstrArraySlice_t*) t1)->f_target);
        return t0;
    }
    if (l0.tag == 847u) {
        t1 = l0.payload.obj;
        t0 = vader_box_i32(179u, ((vader_struct_vader_midir_InstrStringSlice_t*) t1)->f_target);
        return t0;
    }
    if (l0.tag == 848u) {
        t1 = l0.payload.obj;
        t2 = ((vader_array_t*) ((vader_struct_vader_midir_InstrStructNew_t*) t1)->f_fields)->length;
        if ((t2 > INT64_C(0))) {
            t1 = l0.payload.obj;
            vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_midir_InstrStructNew_t*) t1)->f_fields);
            if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
            if ((size_t) INT32_C(0) >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
            t3 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) INT32_C(0)];
            t0 = vader_box_i32(179u, t3);
            return t0;
        }
        t0 = vader_box_obj(0u, NULL);
        return t0;
    }
    if (l0.tag == 825u) {
        t1 = l0.payload.obj;
        t2 = ((vader_array_t*) ((vader_struct_vader_midir_InstrArrayNew_t*) t1)->f_elements)->length;
        if ((t2 > INT64_C(0))) {
            t1 = l0.payload.obj;
            vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_vader_midir_InstrArrayNew_t*) t1)->f_elements);
            if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
            if ((size_t) INT32_C(0) >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
            t3 = ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) INT32_C(0)];
            t0 = vader_box_i32(179u, t3);
            return t0;
        }
        t0 = vader_box_obj(0u, NULL);
        return t0;
    }
    if (l0.tag == 849u) {
        t1 = l0.payload.obj;
        t0 = vader_box_i32(179u, ((vader_struct_vader_midir_InstrTypeCheck_t*) t1)->f_value);
        return t0;
    }
    if (l0.tag == 832u) {
        t1 = l0.payload.obj;
        t0 = vader_box_i32(179u, ((vader_struct_vader_midir_InstrCast_t*) t1)->f_value);
        return t0;
    }
    if (l0.tag == 834u) {
        t1 = l0.payload.obj;
        t0 = vader_box_i32(179u, ((vader_struct_vader_midir_InstrCellNew_t*) t1)->f_value);
        return t0;
    }
    if (l0.tag == 833u) {
        t1 = l0.payload.obj;
        t0 = vader_box_i32(179u, ((vader_struct_vader_midir_InstrCellGet_t*) t1)->f_cell);
        return t0;
    }
    if (l0.tag == 835u) {
        t1 = l0.payload.obj;
        t0 = vader_box_i32(179u, ((vader_struct_vader_midir_InstrCellSet_t*) t1)->f_cell);
        return t0;
    }
    if (l0.tag == 845u) {
        t1 = l0.payload.obj;
        t0 = vader_box_i32(179u, ((vader_struct_vader_midir_InstrMakeClosure_t*) t1)->f_env);
        return t0;
    }
    if (l0.tag == 844u) {
        t1 = l0.payload.obj;
        t2 = ((vader_array_t*) ((vader_struct_vader_midir_InstrIntrinsic_t*) t1)->f_args)->length;
        if ((t2 > INT64_C(0))) {
            t1 = l0.payload.obj;
            vader_array_t* _a5_slotarr = ((vader_array_t*) ((vader_struct_vader_midir_InstrIntrinsic_t*) t1)->f_args);
            if (_a5_slotarr->buf != NULL && _a5_slotarr->buf->header.forward != NULL) { _a5_slotarr->buf = vader_array_buf_forward(_a5_slotarr->buf); }
            if ((size_t) INT32_C(0) >= _a5_slotarr->length) { vader_trap("array index out of bounds"); }
            t3 = ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) INT32_C(0)];
            t0 = vader_box_i32(179u, t3);
            return t0;
        }
        t0 = vader_box_obj(0u, NULL);
        return t0;
    }
    if (l0.tag == 839u) {
        t1 = l0.payload.obj;
        t0 = vader_box_i32(179u, ((vader_struct_vader_midir_InstrDeferPush_t*) t1)->f_value);
        return t0;
    }
    if (l0.tag == 838u) {
        t0 = vader_box_obj(0u, NULL);
        return t0;
    }
    vader_unreachable("unreachable return in vader_midir$first_stack_operand");
}

static vader_box_t vader_midir_first_terminator_operand(vader_box_t l0) {
    vader_box_t t0;
    void* t1;
    if (l0.tag == 860u) {
        t0 = vader_box_obj(0u, NULL);
        return t0;
    }
    if (l0.tag == 863u) {
        t0 = vader_box_obj(0u, NULL);
        return t0;
    }
    if (l0.tag == 861u) {
        t1 = l0.payload.obj;
        t0 = vader_box_i32(179u, ((vader_struct_vader_midir_TermCondBranch_t*) t1)->f_cond);
        return t0;
    }
    if (l0.tag == 862u) {
        t1 = l0.payload.obj;
        t0 = vader_midir_term_return_single(t1);
        return t0;
    }
    vader_unreachable("unreachable return in vader_midir$first_terminator_operand");
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
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct_vader_lower_LoweredFnDecl_t*) l0)->f_mangled;
    l2 = false;
    l3 = false;
    l4 = 0u;
    l5 = 0u;
    l6 = -(INT32_C(1));
    if (((vader_struct_vader_comptime_MonoEntry_t*) ((vader_struct_vader_lower_LoweredFnDecl_t*) l0)->f_origin)->f_decl.tag == 426u) {
        l7 = ((vader_struct_vader_comptime_MonoEntry_t*) ((vader_struct_vader_lower_LoweredFnDecl_t*) l0)->f_origin)->f_decl.payload.obj;
        l1 = vader_midir_extern_symbol_name(l7);
        l2 = toolchain_ast_decorators_have(((vader_struct_toolchain_ast_FnDecl_t*) l7)->f_decorators, 1600u);
        l3 = toolchain_ast_decorators_have(((vader_struct_toolchain_ast_FnDecl_t*) l7)->f_decorators, 1586u);
        l4 = vader_midir_c_header_of(((vader_struct_toolchain_ast_FnDecl_t*) l7)->f_decorators);
        l5 = vader_midir_extern_library_name(l7);
        l6 = vader_midir_c_variadic_fixed_of(((vader_struct_toolchain_ast_FnDecl_t*) l7)->f_decorators);
    }
    vader_struct_vader_midir_FnMetadata_t* _a0_obj = (vader_struct_vader_midir_FnMetadata_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_FnMetadata_t));
    vader_obj_header_init(_a0_obj, 822u);
    _a0_obj->f_extern_name = l1;
    _a0_obj->f_is_extern = l2;
    _a0_obj->f_c_variadic_fixed = l6;
    _a0_obj->f_is_exported = l3;
    _a0_obj->f_c_library = l5;
    _a0_obj->f_c_header = l4;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_midir_fold_moves(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l11 = NULL;
    void* l12 = NULL;
    size_t l5, l6;
    int32_t l7;
    vader_box_t l10 = vader_box_null();
    vader_string_t l13 = 0;
    vader_string_t l14 = 0;
    bool l15, l16;
    void* t0 = NULL;
    int64_t t1;
    vader_box_t* gc_roots[1] = { &l10 };
    void** gc_raw_roots[10] = { &l0, &l1, &l2, &l3, &l4, &l8, &l9, &l11, &l12, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l13, &l14 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 10u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l1 = vader_midir_count_uses(l0);
    vader_array_t* _a0_arr = vader_array_new(9u, 0u, 7u, 179u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(6u, 0u, 12u, 174u);
    l3 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 179u);
    l4 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__i32__bool_t* _a3_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
    vader_obj_header_init(_a3_obj, 316u);
    _a3_obj->f_ekeys = l2;
    _a3_obj->f_evals = l3;
    _a3_obj->f_index = l4;
    _a3_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    t0 = (void*) _a3_obj;
    vader_struct_std_collections_MutableSet__i32_t* _a4_obj = (vader_struct_std_collections_MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i32_t));
    vader_obj_header_init(_a4_obj, 384u);
    _a4_obj->f_inner = t0;
    l2 = (void*) _a4_obj;
    l3 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_params;
    l5 = ((vader_array_t*) l3)->length;
    l6 = (size_t) (int64_t) INT64_C(0);
    {
        loop_25: {
            if ((l6 < l5)) {
                vader_array_t* _a5_slotarr = ((vader_array_t*) l3);
                if (_a5_slotarr->buf != NULL && _a5_slotarr->buf->header.forward != NULL) { _a5_slotarr->buf = vader_array_buf_forward(_a5_slotarr->buf); }
                if ((size_t) l6 >= _a5_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l6);
                l7 = ((vader_struct_vader_midir_CFGParam_t*) t0)->f_local;
                std_collections_add__i32(l2, l7);
                t1 = (l6 + INT64_C(1));
                l6 = (size_t) (int64_t) t1;
                goto loop_25;
            }
        }
    }
    vader_array_t* _a6_arr = vader_array_new(74u, 0u, 13u, 802u);
    l3 = (void*) _a6_arr;
    l4 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_blocks;
    l5 = ((vader_array_t*) l4)->length;
    l6 = (size_t) (int64_t) INT64_C(0);
    {
        loop_56: {
            if ((l6 < l5)) {
                vader_array_t* _a7_slotarr = ((vader_array_t*) l4);
                if (_a7_slotarr->buf != NULL && _a7_slotarr->buf->header.forward != NULL) { _a7_slotarr->buf = vader_array_buf_forward(_a7_slotarr->buf); }
                if ((size_t) l6 >= _a7_slotarr->length) { vader_trap("array index out of bounds"); }
                l8 = vader_array_ref_load_obj(_a7_slotarr->buf, _a7_slotarr->offset + (size_t) l6);
                l7 = ((vader_struct_vader_midir_BasicBlock_t*) l8)->f_id;
                l9 = vader_midir_fold_moves_in_block(l8, l1, l2);
                l10 = ((vader_struct_vader_midir_BasicBlock_t*) l8)->f_terminator;
                l11 = ((vader_struct_vader_midir_BasicBlock_t*) l8)->f_span;
                vader_struct_vader_midir_BasicBlock_t* _a8_obj = (vader_struct_vader_midir_BasicBlock_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_BasicBlock_t));
                vader_obj_header_init(_a8_obj, 802u);
                _a8_obj->f_id = l7;
                _a8_obj->f_instructions = l9;
                _a8_obj->f_terminator = l10;
                _a8_obj->f_span = l11;
                l12 = (void*) _a8_obj;
                vader_array_push((vader_array_t*) l3, vader_ref_box(l12));
                t1 = (l6 + INT64_C(1));
                l6 = (size_t) (int64_t) t1;
                goto loop_56;
            }
        }
    }
    l1 = l0;
    l13 = ((vader_struct_vader_midir_CFGFunction_t*) l1)->f_mangled;
    l2 = ((vader_struct_vader_midir_CFGFunction_t*) l1)->f_params;
    l10 = ((vader_struct_vader_midir_CFGFunction_t*) l1)->f_return_type;
    l4 = ((vader_struct_vader_midir_CFGFunction_t*) l1)->f_locals;
    l7 = ((vader_struct_vader_midir_CFGFunction_t*) l1)->f_entry;
    l8 = ((vader_struct_vader_midir_CFGFunction_t*) l1)->f_origin;
    l14 = ((vader_struct_vader_midir_CFGFunction_t*) l1)->f_extern_name;
    l15 = ((vader_struct_vader_midir_CFGFunction_t*) l1)->f_is_extern;
    l16 = ((vader_struct_vader_midir_CFGFunction_t*) l1)->f_is_exported;
    l1 = ((vader_struct_vader_midir_CFGFunction_t*) l1)->f_scalarised_results;
    vader_struct_vader_midir_CFGFunction_t* _a9_obj = (vader_struct_vader_midir_CFGFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_CFGFunction_t));
    vader_obj_header_init(_a9_obj, 804u);
    _a9_obj->f_mangled = l13;
    _a9_obj->f_params = l2;
    _a9_obj->f_return_type = l10;
    _a9_obj->f_locals = l4;
    _a9_obj->f_blocks = l3;
    _a9_obj->f_entry = l7;
    _a9_obj->f_origin = l8;
    _a9_obj->f_extern_name = l14;
    _a9_obj->f_is_extern = l15;
    _a9_obj->f_is_exported = l16;
    _a9_obj->f_scalarised_results = l1;
    t0 = (void*) _a9_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_midir_fold_moves_in_block(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    void* l9 = NULL;
    void* l13 = NULL;
    void* l26 = NULL;
    void* l29 = NULL;
    void* l30 = NULL;
    void* l34 = NULL;
    void* l37 = NULL;
    size_t l4, l5, l19, l35, l40, l41;
    vader_box_t l6 = vader_box_null(), l7 = vader_box_null(), l11 = vader_box_null(), l14 = vader_box_null(), l17 = vader_box_null(), l20 = vader_box_null(), l21 = vader_box_null(), l36 = vader_box_null(), l39 = vader_box_null();
    int32_t l8, l10, l12, l22, l23, l24, l25, l27, l31, l38;
    int64_t l15, l18, l32;
    bool l16, l28, l33;
    int64_t t0;
    void* t1 = NULL;
    bool t2;
    size_t t3;
    vader_box_t t4 = vader_box_null();
    vader_box_t* gc_roots[10] = { &l6, &l7, &l11, &l14, &l17, &l20, &l21, &l36, &l39, &t4 };
    void** gc_raw_roots[12] = { &l0, &l1, &l2, &l3, &l9, &l13, &l26, &l29, &l30, &l34, &l37, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 10u, 12u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(141u, 0u, 13u, 1220u);
    l3 = (void*) _a0_arr;
    l4 = ((vader_array_t*) ((vader_struct_vader_midir_BasicBlock_t*) l0)->f_instructions)->length;
    l5 = (size_t) (int64_t) INT64_C(0);
    {
        loop_8: {
            if ((l5 < l4)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_midir_BasicBlock_t*) l0)->f_instructions);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l5 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                l6 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5);
                if (!(l6.tag == 846u)) {
                    l7 = l6;
                    vader_array_push((vader_array_t*) l3, l7);
                    t0 = (l5 + INT64_C(1));
                    l5 = (size_t) (int64_t) t0;
                    goto loop_8;
                }
                if (l6.tag == 846u) {
                    t1 = l6.payload.obj;
                    l8 = ((vader_struct_vader_midir_InstrMove_t*) t1)->f_src;
                    t2 = std_collections_MutableSet_Contains_contains__i32(l2, l8);
                    if (t2) {
                        l9 = l6.payload.obj;
                        vader_array_push((vader_array_t*) l3, vader_ref_box(l9));
                        t0 = (l5 + INT64_C(1));
                        l5 = (size_t) (int64_t) t0;
                        goto loop_8;
                    }
                    t1 = l6.payload.obj;
                    l10 = ((vader_struct_vader_midir_InstrMove_t*) t1)->f_src;
                    l11 = std_collections_MutableMap_Index_at__i32__i32(l1, l10);
                    if (l11.tag == 179u) {
                        l12 = ((int32_t) l11.payload.i);
                    } else {
                        l12 = INT32_C(0);
                    }
                    if (l12 != INT32_C(1)) {
                        l13 = l6.payload.obj;
                        vader_array_push((vader_array_t*) l3, vader_ref_box(l13));
                        t0 = (l5 + INT64_C(1));
                        l5 = (size_t) (int64_t) t0;
                        goto loop_8;
                    }
                    t1 = l6.payload.obj;
                    vader_struct__Cell_i32_t* _a2_obj = (vader_struct__Cell_i32_t*) vader_gc_alloc(sizeof(vader_struct__Cell_i32_t));
                    vader_obj_header_init(_a2_obj, 206u);
                    _a2_obj->f_value = ((vader_struct_vader_midir_InstrMove_t*) t1)->f_dst;
                    t1 = (void*) _a2_obj;
                    l14 = vader_ref_box(t1);
                    l15 = -(INT64_C(1));
                    l16 = false;
                    vader_array_t* _a3_arr = vader_array_new(6u, 1u, 12u, 174u);
                    ((uint8_t*) _a3_arr->buf->slots)[_a3_arr->offset + 0u] = (uint8_t) false;
                    t1 = (void*) _a3_arr;
                    vader_struct__Cell_Array_bool__t* _a4_obj = (vader_struct__Cell_Array_bool__t*) vader_gc_alloc(sizeof(vader_struct__Cell_Array_bool__t));
                    vader_obj_header_init(_a4_obj, 192u);
                    _a4_obj->f_value = t1;
                    t1 = (void*) _a4_obj;
                    l17 = vader_ref_box(t1);
                    t3 = ((vader_array_t*) l3)->length;
                    l18 = (((int64_t) (size_t) t3) - INT64_C(1));
                    {
                        loop_108: {
                            if ((l18 >= INT64_C(0))) {
                                t0 = l18;
                                l19 = (size_t) (int64_t) t0;
                                vader_array_t* _a5_slotarr = ((vader_array_t*) l3);
                                if (_a5_slotarr->buf != NULL && _a5_slotarr->buf->header.forward != NULL) { _a5_slotarr->buf = vader_array_buf_forward(_a5_slotarr->buf); }
                                if ((size_t) l19 >= _a5_slotarr->length) { vader_trap("array index out of bounds"); }
                                l20 = vader_array_ref_load_box(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l19);
                                l21 = vader_midir_dst_of(l20);
                                if (l21.tag == 179u) {
                                    l22 = ((int32_t) l21.payload.i);
                                    t1 = l6.payload.obj;
                                    l23 = ((vader_struct_vader_midir_InstrMove_t*) t1)->f_src;
                                    t2 = vader_midir_LocalId_Equals_equals(l22, l23);
                                    if (t2) {
                                        l15 = l18;
                                    } else {
                                        l24 = ((int32_t) l21.payload.i);
                                        l25 = ((vader_struct__Cell_i32_t*) l14.payload.obj)->f_value;
                                        t2 = vader_midir_LocalId_Equals_equals(l24, l25);
                                        if (t2) {
                                            l16 = true;
                                        } else {
                                            l26 = ((vader_struct__Cell_Array_bool__t*) l17.payload.obj)->f_value;
                                            l27 = INT32_C(0);
                                            l28 = false;
                                            vader_array_t* _a6_slotarr = ((vader_array_t*) l26);
                                            if (_a6_slotarr->buf != NULL && _a6_slotarr->buf->header.forward != NULL) { _a6_slotarr->buf = vader_array_buf_forward(_a6_slotarr->buf); }
                                            if ((size_t) l27 >= _a6_slotarr->length) { vader_trap("array index out of bounds"); }
                                            ((uint8_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l27] = (uint8_t) l28;
                                            vader_struct___lambda_env_vader_midir_11_t* _a7_obj = (vader_struct___lambda_env_vader_midir_11_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_midir_11_t));
                                            vader_obj_header_init(_a7_obj, 260u);
                                            _a7_obj->f_cap_0 = l14;
                                            _a7_obj->f_cap_1 = l17;
                                            t1 = (void*) _a7_obj;
                                            vader_fn_t* _a8_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
                                            vader_obj_header_init(_a8_closure, 151u);
                                            _a8_closure->code = (void*) &vader_fn_lift___lambda_vader_midir_10;
                                            _a8_closure->env = t1;
                                            l29 = (void*) _a8_closure;
                                            vader_midir_for_each_read_local(l20, l29);
                                            l30 = ((vader_struct__Cell_Array_bool__t*) l17.payload.obj)->f_value;
                                            l31 = INT32_C(0);
                                            vader_array_t* _a9_slotarr = ((vader_array_t*) l30);
                                            if (_a9_slotarr->buf != NULL && _a9_slotarr->buf->header.forward != NULL) { _a9_slotarr->buf = vader_array_buf_forward(_a9_slotarr->buf); }
                                            if ((size_t) l31 >= _a9_slotarr->length) { vader_trap("array index out of bounds"); }
                                            t4 = vader_box_bool(174u, ((uint8_t*) _a9_slotarr->buf->slots)[_a9_slotarr->offset + (size_t) l31]);
                                            t2 = t4.payload.b;
                                            if (t2) {
                                                l16 = true;
                                            } else {
                                                l32 = INT64_C(1);
                                                l18 = (l18 - l32);
                                                goto loop_108;
                                            }
                                        }
                                    }
                                } else {
                                    l26 = ((vader_struct__Cell_Array_bool__t*) l17.payload.obj)->f_value;
                                    l27 = INT32_C(0);
                                    l28 = false;
                                    vader_array_t* _a10_slotarr = ((vader_array_t*) l26);
                                    if (_a10_slotarr->buf != NULL && _a10_slotarr->buf->header.forward != NULL) { _a10_slotarr->buf = vader_array_buf_forward(_a10_slotarr->buf); }
                                    if ((size_t) l27 >= _a10_slotarr->length) { vader_trap("array index out of bounds"); }
                                    ((uint8_t*) _a10_slotarr->buf->slots)[_a10_slotarr->offset + (size_t) l27] = (uint8_t) l28;
                                    vader_struct___lambda_env_vader_midir_11_t* _a11_obj = (vader_struct___lambda_env_vader_midir_11_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_midir_11_t));
                                    vader_obj_header_init(_a11_obj, 260u);
                                    _a11_obj->f_cap_0 = l14;
                                    _a11_obj->f_cap_1 = l17;
                                    t1 = (void*) _a11_obj;
                                    vader_fn_t* _a12_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
                                    vader_obj_header_init(_a12_closure, 151u);
                                    _a12_closure->code = (void*) &vader_fn_lift___lambda_vader_midir_10;
                                    _a12_closure->env = t1;
                                    l29 = (void*) _a12_closure;
                                    vader_midir_for_each_read_local(l20, l29);
                                    l30 = ((vader_struct__Cell_Array_bool__t*) l17.payload.obj)->f_value;
                                    l31 = INT32_C(0);
                                    vader_array_t* _a13_slotarr = ((vader_array_t*) l30);
                                    if (_a13_slotarr->buf != NULL && _a13_slotarr->buf->header.forward != NULL) { _a13_slotarr->buf = vader_array_buf_forward(_a13_slotarr->buf); }
                                    if ((size_t) l31 >= _a13_slotarr->length) { vader_trap("array index out of bounds"); }
                                    t4 = vader_box_bool(174u, ((uint8_t*) _a13_slotarr->buf->slots)[_a13_slotarr->offset + (size_t) l31]);
                                    t2 = t4.payload.b;
                                    if (t2) {
                                        l16 = true;
                                    } else {
                                        l32 = INT64_C(1);
                                        l18 = (l18 - l32);
                                        goto loop_108;
                                    }
                                }
                            }
                        }
                    }
                    if ((l15 < INT64_C(0))) {
                        l33 = true;
                    } else {
                        l33 = l16;
                    }
                    if (l33) {
                        l34 = l6.payload.obj;
                        vader_array_push((vader_array_t*) l3, vader_ref_box(l34));
                        t0 = (l5 + INT64_C(1));
                        l5 = (size_t) (int64_t) t0;
                        goto loop_8;
                    }
                    t0 = l15;
                    l35 = (size_t) (int64_t) t0;
                    vader_array_t* _a14_slotarr = ((vader_array_t*) l3);
                    if (_a14_slotarr->buf != NULL && _a14_slotarr->buf->header.forward != NULL) { _a14_slotarr->buf = vader_array_buf_forward(_a14_slotarr->buf); }
                    if ((size_t) l35 >= _a14_slotarr->length) { vader_trap("array index out of bounds"); }
                    l36 = vader_array_ref_load_box(_a14_slotarr->buf, _a14_slotarr->offset + (size_t) l35);
                    t2 = vader_midir_instruction_has_side_effect(l36);
                    if (t2) {
                        l37 = l6.payload.obj;
                        vader_array_push((vader_array_t*) l3, vader_ref_box(l37));
                        t0 = (l5 + INT64_C(1));
                        l5 = (size_t) (int64_t) t0;
                        goto loop_8;
                    }
                    t1 = l6.payload.obj;
                    l38 = ((vader_struct_vader_midir_InstrMove_t*) t1)->f_dst;
                    l39 = vader_midir_with_dst(l36, l38);
                    t0 = l15;
                    l40 = (size_t) (int64_t) t0;
                    vader_array_t* _a15_slotarr = ((vader_array_t*) l3);
                    if (_a15_slotarr->buf != NULL && _a15_slotarr->buf->header.forward != NULL) { _a15_slotarr->buf = vader_array_buf_forward(_a15_slotarr->buf); }
                    if ((size_t) l40 >= _a15_slotarr->length) { vader_trap("array index out of bounds"); }
                    vader_array_ref_store(_a15_slotarr->buf, _a15_slotarr->offset + (size_t) l40, l39.payload.obj);
                    VADER_WRITE_BARRIER(_a15_slotarr->buf);
                    l41 = (size_t) (int64_t) INT64_C(1);
                    t0 = (l5 + l41);
                    l5 = (size_t) (int64_t) t0;
                    goto loop_8;
                }
                l41 = (size_t) (int64_t) INT64_C(1);
                t0 = (l5 + l41);
                l5 = (size_t) (int64_t) t0;
                goto loop_8;
            }
        }
    }
    { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
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
    if (l0.tag == 861u) {
        t0 = l0.payload.obj;
        vader_fn_t* _a0_fnobj = (vader_fn_t*) l1;
        ((vader_fn_erased_sig_1_t) _a0_fnobj->code)(_a0_fnobj->env, vader_box_i32(179u, ((vader_struct_vader_midir_TermCondBranch_t*) t0)->f_cond));
    } else {
        if (l0.tag == 862u) {
            t0 = l0.payload.obj;
            l2 = ((vader_struct_vader_midir_TermReturn_t*) t0)->f_values;
            l3 = ((vader_array_t*) l2)->length;
            l4 = (size_t) (int64_t) INT64_C(0);
            {
                loop_21: {
                    if ((l4 < l3)) {
                        vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
                        if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                        if ((size_t) l4 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                        t1 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
                        vader_fn_t* _a2_fnobj = (vader_fn_t*) l1;
                        ((vader_fn_erased_sig_1_t) _a2_fnobj->code)(_a2_fnobj->env, vader_box_i32(179u, t1));
                        t2 = (l4 + INT64_C(1));
                        l4 = (size_t) (int64_t) t2;
                        goto loop_21;
                    }
                }
            }
        } else {
            if (l0.tag == 860u) {
            } else {
                if (l0.tag == 863u) {
                } else {
                    { vader_gc_top = gc_frame.prev; return; }
                }
            }
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
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
    if (l0.tag == 836u) {
    } else {
        if (l0.tag == 843u) {
        } else {
            if (l0.tag == 842u) {
            } else {
                if (l0.tag == 846u) {
                    t0 = l0.payload.obj;
                    vader_fn_t* _a0_fnobj = (vader_fn_t*) l1;
                    ((vader_fn_erased_sig_1_t) _a0_fnobj->code)(_a0_fnobj->env, vader_box_i32(179u, ((vader_struct_vader_midir_InstrMove_t*) t0)->f_src));
                } else {
                    if (l0.tag == 829u) {
                        t0 = l0.payload.obj;
                        vader_fn_t* _a1_fnobj = (vader_fn_t*) l1;
                        ((vader_fn_erased_sig_1_t) _a1_fnobj->code)(_a1_fnobj->env, vader_box_i32(179u, ((vader_struct_vader_midir_InstrBinOp_t*) t0)->f_lhs));
                        t0 = l0.payload.obj;
                        vader_fn_t* _a2_fnobj = (vader_fn_t*) l1;
                        ((vader_fn_erased_sig_1_t) _a2_fnobj->code)(_a2_fnobj->env, vader_box_i32(179u, ((vader_struct_vader_midir_InstrBinOp_t*) t0)->f_rhs));
                    } else {
                        if (l0.tag == 851u) {
                            t0 = l0.payload.obj;
                            vader_fn_t* _a3_fnobj = (vader_fn_t*) l1;
                            ((vader_fn_erased_sig_1_t) _a3_fnobj->code)(_a3_fnobj->env, vader_box_i32(179u, ((vader_struct_vader_midir_InstrUnOp_t*) t0)->f_operand));
                        } else {
                            if (l0.tag == 830u) {
                                t0 = l0.payload.obj;
                                l2 = ((vader_struct_vader_midir_InstrCall_t*) t0)->f_args;
                                l3 = ((vader_array_t*) l2)->length;
                                l4 = (size_t) (int64_t) INT64_C(0);
                                {
                                    loop_56: {
                                        if ((l4 < l3)) {
                                            vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
                                            if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                                            if ((size_t) l4 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                                            t1 = ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l4];
                                            vader_fn_t* _a5_fnobj = (vader_fn_t*) l1;
                                            ((vader_fn_erased_sig_1_t) _a5_fnobj->code)(_a5_fnobj->env, vader_box_i32(179u, t1));
                                            t2 = (l4 + INT64_C(1));
                                            l4 = (size_t) (int64_t) t2;
                                            goto loop_56;
                                        }
                                    }
                                }
                            } else {
                                if (l0.tag == 831u) {
                                    t0 = l0.payload.obj;
                                    vader_fn_t* _a6_fnobj = (vader_fn_t*) l1;
                                    ((vader_fn_erased_sig_1_t) _a6_fnobj->code)(_a6_fnobj->env, vader_box_i32(179u, ((vader_struct_vader_midir_InstrCallIndirect_t*) t0)->f_callee));
                                    t0 = l0.payload.obj;
                                    l2 = ((vader_struct_vader_midir_InstrCallIndirect_t*) t0)->f_args;
                                    l3 = ((vader_array_t*) l2)->length;
                                    l4 = (size_t) (int64_t) INT64_C(0);
                                    {
                                        loop_92: {
                                            if ((l4 < l3)) {
                                                vader_array_t* _a7_slotarr = ((vader_array_t*) l2);
                                                if (_a7_slotarr->buf != NULL && _a7_slotarr->buf->header.forward != NULL) { _a7_slotarr->buf = vader_array_buf_forward(_a7_slotarr->buf); }
                                                if ((size_t) l4 >= _a7_slotarr->length) { vader_trap("array index out of bounds"); }
                                                t1 = ((int32_t*) _a7_slotarr->buf->slots)[_a7_slotarr->offset + (size_t) l4];
                                                vader_fn_t* _a8_fnobj = (vader_fn_t*) l1;
                                                ((vader_fn_erased_sig_1_t) _a8_fnobj->code)(_a8_fnobj->env, vader_box_i32(179u, t1));
                                                t2 = (l4 + INT64_C(1));
                                                l4 = (size_t) (int64_t) t2;
                                                goto loop_92;
                                            }
                                        }
                                    }
                                } else {
                                    if (l0.tag == 852u) {
                                        t0 = l0.payload.obj;
                                        vader_fn_t* _a9_fnobj = (vader_fn_t*) l1;
                                        ((vader_fn_erased_sig_1_t) _a9_fnobj->code)(_a9_fnobj->env, vader_box_i32(179u, ((vader_struct_vader_midir_InstrVirtualCall_t*) t0)->f_receiver));
                                        t0 = l0.payload.obj;
                                        l2 = ((vader_struct_vader_midir_InstrVirtualCall_t*) t0)->f_args;
                                        l3 = ((vader_array_t*) l2)->length;
                                        l4 = (size_t) (int64_t) INT64_C(0);
                                        {
                                            loop_128: {
                                                if ((l4 < l3)) {
                                                    vader_array_t* _a10_slotarr = ((vader_array_t*) l2);
                                                    if (_a10_slotarr->buf != NULL && _a10_slotarr->buf->header.forward != NULL) { _a10_slotarr->buf = vader_array_buf_forward(_a10_slotarr->buf); }
                                                    if ((size_t) l4 >= _a10_slotarr->length) { vader_trap("array index out of bounds"); }
                                                    t1 = ((int32_t*) _a10_slotarr->buf->slots)[_a10_slotarr->offset + (size_t) l4];
                                                    vader_fn_t* _a11_fnobj = (vader_fn_t*) l1;
                                                    ((vader_fn_erased_sig_1_t) _a11_fnobj->code)(_a11_fnobj->env, vader_box_i32(179u, t1));
                                                    t2 = (l4 + INT64_C(1));
                                                    l4 = (size_t) (int64_t) t2;
                                                    goto loop_128;
                                                }
                                            }
                                        }
                                    } else {
                                        if (l0.tag == 840u) {
                                            t0 = l0.payload.obj;
                                            vader_fn_t* _a12_fnobj = (vader_fn_t*) l1;
                                            ((vader_fn_erased_sig_1_t) _a12_fnobj->code)(_a12_fnobj->env, vader_box_i32(179u, ((vader_struct_vader_midir_InstrFieldGet_t*) t0)->f_target));
                                        } else {
                                            if (l0.tag == 841u) {
                                                t0 = l0.payload.obj;
                                                vader_fn_t* _a13_fnobj = (vader_fn_t*) l1;
                                                ((vader_fn_erased_sig_1_t) _a13_fnobj->code)(_a13_fnobj->env, vader_box_i32(179u, ((vader_struct_vader_midir_InstrFieldSet_t*) t0)->f_target));
                                                t0 = l0.payload.obj;
                                                vader_fn_t* _a14_fnobj = (vader_fn_t*) l1;
                                                ((vader_fn_erased_sig_1_t) _a14_fnobj->code)(_a14_fnobj->env, vader_box_i32(179u, ((vader_struct_vader_midir_InstrFieldSet_t*) t0)->f_value));
                                            } else {
                                                if (l0.tag == 823u) {
                                                    t0 = l0.payload.obj;
                                                    vader_fn_t* _a15_fnobj = (vader_fn_t*) l1;
                                                    ((vader_fn_erased_sig_1_t) _a15_fnobj->code)(_a15_fnobj->env, vader_box_i32(179u, ((vader_struct_vader_midir_InstrArrayGet_t*) t0)->f_target));
                                                    t0 = l0.payload.obj;
                                                    vader_fn_t* _a16_fnobj = (vader_fn_t*) l1;
                                                    ((vader_fn_erased_sig_1_t) _a16_fnobj->code)(_a16_fnobj->env, vader_box_i32(179u, ((vader_struct_vader_midir_InstrArrayGet_t*) t0)->f_index));
                                                } else {
                                                    if (l0.tag == 827u) {
                                                        t0 = l0.payload.obj;
                                                        vader_fn_t* _a17_fnobj = (vader_fn_t*) l1;
                                                        ((vader_fn_erased_sig_1_t) _a17_fnobj->code)(_a17_fnobj->env, vader_box_i32(179u, ((vader_struct_vader_midir_InstrArraySet_t*) t0)->f_target));
                                                        t0 = l0.payload.obj;
                                                        vader_fn_t* _a18_fnobj = (vader_fn_t*) l1;
                                                        ((vader_fn_erased_sig_1_t) _a18_fnobj->code)(_a18_fnobj->env, vader_box_i32(179u, ((vader_struct_vader_midir_InstrArraySet_t*) t0)->f_index));
                                                        t0 = l0.payload.obj;
                                                        vader_fn_t* _a19_fnobj = (vader_fn_t*) l1;
                                                        ((vader_fn_erased_sig_1_t) _a19_fnobj->code)(_a19_fnobj->env, vader_box_i32(179u, ((vader_struct_vader_midir_InstrArraySet_t*) t0)->f_value));
                                                    } else {
                                                        if (l0.tag == 824u) {
                                                            t0 = l0.payload.obj;
                                                            vader_fn_t* _a20_fnobj = (vader_fn_t*) l1;
                                                            ((vader_fn_erased_sig_1_t) _a20_fnobj->code)(_a20_fnobj->env, vader_box_i32(179u, ((vader_struct_vader_midir_InstrArrayLen_t*) t0)->f_target));
                                                        } else {
                                                            if (l0.tag == 826u) {
                                                                t0 = l0.payload.obj;
                                                                vader_fn_t* _a21_fnobj = (vader_fn_t*) l1;
                                                                ((vader_fn_erased_sig_1_t) _a21_fnobj->code)(_a21_fnobj->env, vader_box_i32(179u, ((vader_struct_vader_midir_InstrArrayPush_t*) t0)->f_target));
                                                                t0 = l0.payload.obj;
                                                                vader_fn_t* _a22_fnobj = (vader_fn_t*) l1;
                                                                ((vader_fn_erased_sig_1_t) _a22_fnobj->code)(_a22_fnobj->env, vader_box_i32(179u, ((vader_struct_vader_midir_InstrArrayPush_t*) t0)->f_value));
                                                            } else {
                                                                if (l0.tag == 828u) {
                                                                    t0 = l0.payload.obj;
                                                                    vader_fn_t* _a23_fnobj = (vader_fn_t*) l1;
                                                                    ((vader_fn_erased_sig_1_t) _a23_fnobj->code)(_a23_fnobj->env, vader_box_i32(179u, ((vader_struct_vader_midir_InstrArraySlice_t*) t0)->f_target));
                                                                    t0 = l0.payload.obj;
                                                                    vader_fn_t* _a24_fnobj = (vader_fn_t*) l1;
                                                                    ((vader_fn_erased_sig_1_t) _a24_fnobj->code)(_a24_fnobj->env, vader_box_i32(179u, ((vader_struct_vader_midir_InstrArraySlice_t*) t0)->f_lo));
                                                                    t0 = l0.payload.obj;
                                                                    vader_fn_t* _a25_fnobj = (vader_fn_t*) l1;
                                                                    ((vader_fn_erased_sig_1_t) _a25_fnobj->code)(_a25_fnobj->env, vader_box_i32(179u, ((vader_struct_vader_midir_InstrArraySlice_t*) t0)->f_hi));
                                                                } else {
                                                                    if (l0.tag == 847u) {
                                                                        t0 = l0.payload.obj;
                                                                        vader_fn_t* _a26_fnobj = (vader_fn_t*) l1;
                                                                        ((vader_fn_erased_sig_1_t) _a26_fnobj->code)(_a26_fnobj->env, vader_box_i32(179u, ((vader_struct_vader_midir_InstrStringSlice_t*) t0)->f_target));
                                                                        t0 = l0.payload.obj;
                                                                        vader_fn_t* _a27_fnobj = (vader_fn_t*) l1;
                                                                        ((vader_fn_erased_sig_1_t) _a27_fnobj->code)(_a27_fnobj->env, vader_box_i32(179u, ((vader_struct_vader_midir_InstrStringSlice_t*) t0)->f_lo));
                                                                        t0 = l0.payload.obj;
                                                                        vader_fn_t* _a28_fnobj = (vader_fn_t*) l1;
                                                                        ((vader_fn_erased_sig_1_t) _a28_fnobj->code)(_a28_fnobj->env, vader_box_i32(179u, ((vader_struct_vader_midir_InstrStringSlice_t*) t0)->f_hi));
                                                                    } else {
                                                                        if (l0.tag == 848u) {
                                                                            t0 = l0.payload.obj;
                                                                            l2 = ((vader_struct_vader_midir_InstrStructNew_t*) t0)->f_fields;
                                                                            l3 = ((vader_array_t*) l2)->length;
                                                                            l4 = (size_t) (int64_t) INT64_C(0);
                                                                            {
                                                                                loop_276: {
                                                                                    if ((l4 < l3)) {
                                                                                        vader_array_t* _a29_slotarr = ((vader_array_t*) l2);
                                                                                        if (_a29_slotarr->buf != NULL && _a29_slotarr->buf->header.forward != NULL) { _a29_slotarr->buf = vader_array_buf_forward(_a29_slotarr->buf); }
                                                                                        if ((size_t) l4 >= _a29_slotarr->length) { vader_trap("array index out of bounds"); }
                                                                                        t1 = ((int32_t*) _a29_slotarr->buf->slots)[_a29_slotarr->offset + (size_t) l4];
                                                                                        vader_fn_t* _a30_fnobj = (vader_fn_t*) l1;
                                                                                        ((vader_fn_erased_sig_1_t) _a30_fnobj->code)(_a30_fnobj->env, vader_box_i32(179u, t1));
                                                                                        t2 = (l4 + INT64_C(1));
                                                                                        l4 = (size_t) (int64_t) t2;
                                                                                        goto loop_276;
                                                                                    }
                                                                                }
                                                                            }
                                                                        } else {
                                                                            if (l0.tag == 825u) {
                                                                                t0 = l0.payload.obj;
                                                                                l2 = ((vader_struct_vader_midir_InstrArrayNew_t*) t0)->f_elements;
                                                                                l3 = ((vader_array_t*) l2)->length;
                                                                                l4 = (size_t) (int64_t) INT64_C(0);
                                                                                {
                                                                                    loop_307: {
                                                                                        if ((l4 < l3)) {
                                                                                            vader_array_t* _a31_slotarr = ((vader_array_t*) l2);
                                                                                            if (_a31_slotarr->buf != NULL && _a31_slotarr->buf->header.forward != NULL) { _a31_slotarr->buf = vader_array_buf_forward(_a31_slotarr->buf); }
                                                                                            if ((size_t) l4 >= _a31_slotarr->length) { vader_trap("array index out of bounds"); }
                                                                                            t1 = ((int32_t*) _a31_slotarr->buf->slots)[_a31_slotarr->offset + (size_t) l4];
                                                                                            vader_fn_t* _a32_fnobj = (vader_fn_t*) l1;
                                                                                            ((vader_fn_erased_sig_1_t) _a32_fnobj->code)(_a32_fnobj->env, vader_box_i32(179u, t1));
                                                                                            t2 = (l4 + INT64_C(1));
                                                                                            l4 = (size_t) (int64_t) t2;
                                                                                            goto loop_307;
                                                                                        }
                                                                                    }
                                                                                }
                                                                            } else {
                                                                                if (l0.tag == 849u) {
                                                                                    t0 = l0.payload.obj;
                                                                                    vader_fn_t* _a33_fnobj = (vader_fn_t*) l1;
                                                                                    ((vader_fn_erased_sig_1_t) _a33_fnobj->code)(_a33_fnobj->env, vader_box_i32(179u, ((vader_struct_vader_midir_InstrTypeCheck_t*) t0)->f_value));
                                                                                } else {
                                                                                    if (l0.tag == 850u) {
                                                                                    } else {
                                                                                        if (l0.tag == 837u) {
                                                                                        } else {
                                                                                            if (l0.tag == 832u) {
                                                                                                t0 = l0.payload.obj;
                                                                                                vader_fn_t* _a34_fnobj = (vader_fn_t*) l1;
                                                                                                ((vader_fn_erased_sig_1_t) _a34_fnobj->code)(_a34_fnobj->env, vader_box_i32(179u, ((vader_struct_vader_midir_InstrCast_t*) t0)->f_value));
                                                                                            } else {
                                                                                                if (l0.tag == 834u) {
                                                                                                    t0 = l0.payload.obj;
                                                                                                    vader_fn_t* _a35_fnobj = (vader_fn_t*) l1;
                                                                                                    ((vader_fn_erased_sig_1_t) _a35_fnobj->code)(_a35_fnobj->env, vader_box_i32(179u, ((vader_struct_vader_midir_InstrCellNew_t*) t0)->f_value));
                                                                                                } else {
                                                                                                    if (l0.tag == 833u) {
                                                                                                        t0 = l0.payload.obj;
                                                                                                        vader_fn_t* _a36_fnobj = (vader_fn_t*) l1;
                                                                                                        ((vader_fn_erased_sig_1_t) _a36_fnobj->code)(_a36_fnobj->env, vader_box_i32(179u, ((vader_struct_vader_midir_InstrCellGet_t*) t0)->f_cell));
                                                                                                    } else {
                                                                                                        if (l0.tag == 835u) {
                                                                                                            t0 = l0.payload.obj;
                                                                                                            vader_fn_t* _a37_fnobj = (vader_fn_t*) l1;
                                                                                                            ((vader_fn_erased_sig_1_t) _a37_fnobj->code)(_a37_fnobj->env, vader_box_i32(179u, ((vader_struct_vader_midir_InstrCellSet_t*) t0)->f_cell));
                                                                                                            t0 = l0.payload.obj;
                                                                                                            vader_fn_t* _a38_fnobj = (vader_fn_t*) l1;
                                                                                                            ((vader_fn_erased_sig_1_t) _a38_fnobj->code)(_a38_fnobj->env, vader_box_i32(179u, ((vader_struct_vader_midir_InstrCellSet_t*) t0)->f_value));
                                                                                                        } else {
                                                                                                            if (l0.tag == 845u) {
                                                                                                                t0 = l0.payload.obj;
                                                                                                                vader_fn_t* _a39_fnobj = (vader_fn_t*) l1;
                                                                                                                ((vader_fn_erased_sig_1_t) _a39_fnobj->code)(_a39_fnobj->env, vader_box_i32(179u, ((vader_struct_vader_midir_InstrMakeClosure_t*) t0)->f_env));
                                                                                                            } else {
                                                                                                                if (l0.tag == 844u) {
                                                                                                                    t0 = l0.payload.obj;
                                                                                                                    l2 = ((vader_struct_vader_midir_InstrIntrinsic_t*) t0)->f_args;
                                                                                                                    l3 = ((vader_array_t*) l2)->length;
                                                                                                                    l4 = (size_t) (int64_t) INT64_C(0);
                                                                                                                    {
                                                                                                                        loop_405: {
                                                                                                                            if ((l4 < l3)) {
                                                                                                                                vader_array_t* _a40_slotarr = ((vader_array_t*) l2);
                                                                                                                                if (_a40_slotarr->buf != NULL && _a40_slotarr->buf->header.forward != NULL) { _a40_slotarr->buf = vader_array_buf_forward(_a40_slotarr->buf); }
                                                                                                                                if ((size_t) l4 >= _a40_slotarr->length) { vader_trap("array index out of bounds"); }
                                                                                                                                t1 = ((int32_t*) _a40_slotarr->buf->slots)[_a40_slotarr->offset + (size_t) l4];
                                                                                                                                vader_fn_t* _a41_fnobj = (vader_fn_t*) l1;
                                                                                                                                ((vader_fn_erased_sig_1_t) _a41_fnobj->code)(_a41_fnobj->env, vader_box_i32(179u, t1));
                                                                                                                                t2 = (l4 + INT64_C(1));
                                                                                                                                l4 = (size_t) (int64_t) t2;
                                                                                                                                goto loop_405;
                                                                                                                            }
                                                                                                                        }
                                                                                                                    }
                                                                                                                } else {
                                                                                                                    if (l0.tag == 839u) {
                                                                                                                        t0 = l0.payload.obj;
                                                                                                                        vader_fn_t* _a42_fnobj = (vader_fn_t*) l1;
                                                                                                                        ((vader_fn_erased_sig_1_t) _a42_fnobj->code)(_a42_fnobj->env, vader_box_i32(179u, ((vader_struct_vader_midir_InstrDeferPush_t*) t0)->f_value));
                                                                                                                    } else {
                                                                                                                        if (l0.tag == 838u) {
                                                                                                                        } else {
                                                                                                                            { vader_gc_top = gc_frame.prev; return; }
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
                        }
                    }
                }
            }
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
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
    if (((vader_struct_vader_midir_MutableBlock_t*) l0)->f_terminator.tag == 0u) {
        l1 = ((vader_struct_vader_midir_MutableBlock_t*) l0)->f_id;
        l2 = ((vader_struct_vader_midir_MutableBlock_t*) l0)->f_instructions;
        vader_struct_vader_midir_TermUnreachable_t* _a0_obj = (vader_struct_vader_midir_TermUnreachable_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_TermUnreachable_t));
        vader_obj_header_init(_a0_obj, 863u);
        _a0_obj->f_span = ((vader_struct_vader_midir_MutableBlock_t*) l0)->f_span;
        _a0_obj->f_reason = 1953u;
        _a0_obj->f_trap = false;
        l3 = (void*) _a0_obj;
        l4 = ((vader_struct_vader_midir_MutableBlock_t*) l0)->f_span;
        vader_struct_vader_midir_BasicBlock_t* _a1_obj = (vader_struct_vader_midir_BasicBlock_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_BasicBlock_t));
        vader_obj_header_init(_a1_obj, 802u);
        _a1_obj->f_id = l1;
        _a1_obj->f_instructions = l2;
        _a1_obj->f_terminator = vader_ref_box(l3);
        _a1_obj->f_span = l4;
        t0 = (void*) _a1_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l1 = ((vader_struct_vader_midir_MutableBlock_t*) l0)->f_id;
    l2 = ((vader_struct_vader_midir_MutableBlock_t*) l0)->f_instructions;
    l5 = ((vader_struct_vader_midir_MutableBlock_t*) l0)->f_terminator;
    l3 = ((vader_struct_vader_midir_MutableBlock_t*) l0)->f_span;
    vader_struct_vader_midir_BasicBlock_t* _a2_obj = (vader_struct_vader_midir_BasicBlock_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_BasicBlock_t));
    vader_obj_header_init(_a2_obj, 802u);
    _a2_obj->f_id = l1;
    _a2_obj->f_instructions = l2;
    _a2_obj->f_terminator = l5;
    _a2_obj->f_span = l3;
    t0 = (void*) _a2_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
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
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l3 = l1;
    l4 = vader_host_std_core_byte_len(l3);
    l5 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(22) + l4));
    l4 = (size_t) (int64_t) INT64_C(0);
    l4 = std_core_write_string_at(l5, l4, 262u);
    l4 = std_core_write_string_at(l5, l4, l3);
    l4 = std_core_write_string_at(l5, l4, 890u);
    t0 = ((vader_array_t*) ((vader_struct_vader_midir_FnCtx_t*) l0)->f_locals)->length;
    t1 = ((int64_t) (size_t) t0);
    l6 = (uint64_t) (int64_t) t1;
    l4 = std_core_write_unsigned(l5, l4, l6);
    l3 = std_core_finish_buffer(l5, l4);
    t2 = vader_midir_declare_local(l0, l3, l2, vader_box_obj(0u, NULL));
    { int32_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static bool vader_midir_instruction_has_side_effect(vader_box_t l0) {
    return (l0.tag == 826u || l0.tag == 827u || l0.tag == 830u || l0.tag == 831u || l0.tag == 835u || l0.tag == 841u || l0.tag == 844u || l0.tag == 852u);
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
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    if (l0.tag == 520u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_bytecode_BcValStr_t*) t0)->f_value;
        vader_bytecode_intern_string(t1, l1);
    } else {
        if (l0.tag == 521u) {
            t0 = l0.payload.obj;
            l2 = ((vader_struct_vader_bytecode_BcValStruct_t*) t0)->f_fields;
            l3 = ((vader_array_t*) l2)->length;
            l4 = (size_t) (int64_t) INT64_C(0);
            {
                loop_23: {
                    if ((l4 < l3)) {
                        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
                        if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                        if ((size_t) l4 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                        t2 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
                        vader_midir_intern_data_value_strings(t2, l1);
                        t3 = (l4 + INT64_C(1));
                        l4 = (size_t) (int64_t) t3;
                        goto loop_23;
                    }
                }
            }
        } else {
            if (l0.tag == 518u) {
                t0 = l0.payload.obj;
                l2 = ((vader_struct_vader_bytecode_BcValArray_t*) t0)->f_elements;
                l3 = ((vader_array_t*) l2)->length;
                l4 = (size_t) (int64_t) INT64_C(0);
                {
                    loop_54: {
                        if ((l4 < l3)) {
                            vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
                            if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                            if ((size_t) l4 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                            t2 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
                            vader_midir_intern_data_value_strings(t2, l1);
                            t3 = (l4 + INT64_C(1));
                            l4 = (size_t) (int64_t) t3;
                            goto loop_54;
                        }
                    }
                }
            }
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static int32_t vader_midir_intern_string_pool(void* l0, vader_string_t l1) {
    vader_box_t l2 = vader_box_null();
    int32_t l3;
    int32_t t0;
    size_t t1;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = std_collections_MutableMap_Index_at__string__i32(((vader_struct_vader_midir_ProjectCtx_t*) l0)->f_string_index, l1);
    if (l2.tag == 179u) {
        t0 = ((int32_t) l2.payload.i);
        { int32_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = ((vader_array_t*) ((vader_struct_vader_midir_ProjectCtx_t*) l0)->f_strings)->length;
    l3 = ((int32_t) (size_t) t1);
    vader_array_push((vader_array_t*) ((vader_struct_vader_midir_ProjectCtx_t*) l0)->f_strings, vader_box_string(176u, l1));
    std_collections_MutableMap_IndexSet_set_at__string__i32(((vader_struct_vader_midir_ProjectCtx_t*) l0)->f_string_index, l1, l3);
    { int32_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static int32_t vader_midir_intersect_dom_tree(int32_t l0, int32_t l1, void* l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    int32_t l6, l7, l9, l10, l11, l12, l13, l14, l15, l16, l17;
    bool l8;
    void* t0 = NULL;
    bool t1;
    void** gc_raw_roots[5] = { &l2, &l3, &l4, &l5, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(9u, 0u, 7u, 179u);
    l3 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(6u, 0u, 12u, 174u);
    l4 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 179u);
    l5 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__i32__bool_t* _a3_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
    vader_obj_header_init(_a3_obj, 316u);
    _a3_obj->f_ekeys = l3;
    _a3_obj->f_evals = l4;
    _a3_obj->f_index = l5;
    _a3_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    t0 = (void*) _a3_obj;
    vader_struct_std_collections_MutableSet__i32_t* _a4_obj = (vader_struct_std_collections_MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i32_t));
    vader_obj_header_init(_a4_obj, 384u);
    _a4_obj->f_inner = t0;
    l3 = (void*) _a4_obj;
    l6 = l0;
    {
        loop_18: {
            l7 = -(INT32_C(1));
            t1 = vader_midir_BlockId_Equals_equals(l6, l7);
            if (!(t1)) {
                l9 = l6;
                t1 = std_collections_MutableSet_Contains_contains__i32(l3, l9);
                l8 = !(t1);
            } else {
                l8 = false;
            }
            if (l8) {
                l10 = l6;
                std_collections_add__i32(l3, l10);
                l11 = l6;
                vader_array_t* _a5_slotarr = ((vader_array_t*) l2);
                if (_a5_slotarr->buf != NULL && _a5_slotarr->buf->header.forward != NULL) { _a5_slotarr->buf = vader_array_buf_forward(_a5_slotarr->buf); }
                if ((size_t) l11 >= _a5_slotarr->length) { vader_trap("array index out of bounds"); }
                l12 = ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l11];
                t1 = vader_midir_BlockId_Equals_equals(l12, l6);
                if (t1) {
                } else {
                    l6 = l12;
                    goto loop_18;
                }
            }
            l13 = l1;
            {
                loop_64: {
                    l14 = -(INT32_C(1));
                    t1 = vader_midir_BlockId_Equals_equals(l13, l14);
                    if (!(t1)) {
                        l15 = l13;
                        t1 = std_collections_MutableSet_Contains_contains__i32(l3, l15);
                        if (t1) {
                            { int32_t __vret = l13; vader_gc_top = gc_frame.prev; return __vret; }
                        }
                        l16 = l13;
                        vader_array_t* _a6_slotarr = ((vader_array_t*) l2);
                        if (_a6_slotarr->buf != NULL && _a6_slotarr->buf->header.forward != NULL) { _a6_slotarr->buf = vader_array_buf_forward(_a6_slotarr->buf); }
                        if ((size_t) l16 >= _a6_slotarr->length) { vader_trap("array index out of bounds"); }
                        l17 = ((int32_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l16];
                        t1 = vader_midir_BlockId_Equals_equals(l17, l13);
                        if (t1) {
                            goto end_72;
                        }
                        l13 = l17;
                        goto loop_64;
                    } end_72: ;
                }
            }
            { int32_t __vret = -(INT32_C(1)); vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    l13 = l1;
    {
        loop_107: {
            l14 = -(INT32_C(1));
            t1 = vader_midir_BlockId_Equals_equals(l13, l14);
            if (!(t1)) {
                l15 = l13;
                t1 = std_collections_MutableSet_Contains_contains__i32(l3, l15);
                if (t1) {
                    { int32_t __vret = l13; vader_gc_top = gc_frame.prev; return __vret; }
                }
                l16 = l13;
                vader_array_t* _a7_slotarr = ((vader_array_t*) l2);
                if (_a7_slotarr->buf != NULL && _a7_slotarr->buf->header.forward != NULL) { _a7_slotarr->buf = vader_array_buf_forward(_a7_slotarr->buf); }
                if ((size_t) l16 >= _a7_slotarr->length) { vader_trap("array index out of bounds"); }
                l17 = ((int32_t*) _a7_slotarr->buf->slots)[_a7_slotarr->offset + (size_t) l16];
                t1 = vader_midir_BlockId_Equals_equals(l17, l13);
                if (t1) {
                    goto end_115;
                }
                l13 = l17;
                goto loop_107;
            } end_115: ;
        }
    }
    { int32_t __vret = -(INT32_C(1)); vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_box_t vader_midir_intrinsic_op_for_name(vader_string_t l0) {
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[1] = { &t0 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    if (l0 == 2097u) {
        vader_struct_vader_bytecode_SizeOfType_t* _a0_obj = (vader_struct_vader_bytecode_SizeOfType_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_SizeOfType_t));
        vader_obj_header_init(_a0_obj, 631u);
        t0 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == 1289u) {
        vader_struct_vader_bytecode_ArrayRepeat_t* _a1_obj = (vader_struct_vader_bytecode_ArrayRepeat_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_ArrayRepeat_t));
        vader_obj_header_init(_a1_obj, 499u);
        t0 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == 1282u) {
        vader_struct_vader_bytecode_ArrayPushAll_t* _a2_obj = (vader_struct_vader_bytecode_ArrayPushAll_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_ArrayPushAll_t));
        vader_obj_header_init(_a2_obj, 497u);
        t0 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == 1263u) {
        vader_struct_vader_bytecode_ArrayCopy_t* _a3_obj = (vader_struct_vader_bytecode_ArrayCopy_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_ArrayCopy_t));
        vader_obj_header_init(_a3_obj, 492u);
        t0 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == 1286u) {
        vader_struct_vader_bytecode_ArrayRemoveLast_t* _a4_obj = (vader_struct_vader_bytecode_ArrayRemoveLast_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_ArrayRemoveLast_t));
        vader_obj_header_init(_a4_obj, 498u);
        t0 = (void*) _a4_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == 1260u) {
        vader_struct_vader_bytecode_ArrayClear_t* _a5_obj = (vader_struct_vader_bytecode_ArrayClear_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_ArrayClear_t));
        vader_obj_header_init(_a5_obj, 491u);
        t0 = (void*) _a5_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_box_obj(0u, NULL);
    { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static bool vader_midir_is_dest_passing_shape(vader_box_t l0) {
    void* t0;
    bool t1;
    if ((l0.tag == 746u || l0.tag == 765u)) {
        return true;
    }
    if (l0.tag == 745u) {
        t0 = l0.payload.obj;
        t1 = vader_midir_is_short_circuit_op(((vader_struct_vader_lower_LoweredBinary_t*) t0)->f_op);
        return t1;
    }
    return false;
}

static bool vader_midir_is_mutable_slot(vader_box_t l0) {
    bool t0;
    t0 = vader_types_type_grants_mutation(l0);
    return t0;
}

static bool vader_midir_is_short_circuit_op(uint8_t l0) {
    bool l1;
    if (l0 == INT32_C(10)) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(11);
    }
    return l1;
}

static bool vader_midir_last_op_exits(void* l0) {
    void* l1;
    size_t l2;
    size_t t0;
    int64_t t1;
    vader_box_t t2;
    l1 = ((vader_struct_vader_bytecode_BcFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_slot)->f_body;
    t0 = ((vader_array_t*) l1)->length;
    if (t0 == INT64_C(0)) {
        return false;
    }
    t0 = ((vader_array_t*) l1)->length;
    t1 = (t0 - INT64_C(1));
    l2 = (size_t) (int64_t) t1;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    if ((size_t) l2 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
    t2 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
    return (t2.tag == 532u || t2.tag == 629u || t2.tag == 630u);
}

static bool vader_midir_loop_exit_present(void* l0, int32_t l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    size_t l5, l6;
    int32_t l7, l9;
    vader_box_t l8 = vader_box_null();
    void* t0 = NULL;
    int64_t t1;
    vader_box_t* gc_roots[1] = { &l8 };
    void** gc_raw_roots[5] = { &l0, &l2, &l3, &l4, &t0 };
    vader_struct___Tuple_i32_Union_i32_null__4a877297_t _a2_storage = {0};
    void* gc_stack_objs[1] = { (void*) &_a2_storage };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 1u, gc_stack_objs };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_loop_exit;
    l3 = ((vader_struct_std_collections_MutableMap__i32__i32___null_t*) l2)->f_ekeys;
    l4 = ((vader_struct_std_collections_MutableMap__i32__i32___null_t*) l2)->f_evals;
    l5 = ((vader_struct_std_collections_MutableMap__i32__i32___null_t*) l2)->f_size;
    l6 = (size_t) (int64_t) INT64_C(0);
    {
        loop_12: {
            if ((l6 >= l5)) {
                { vader_gc_top = gc_frame.prev; return false; }
            }
            vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
            if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
            if ((size_t) l6 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
            l7 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l6];
            vader_array_t* _a1_slotarr = ((vader_array_t*) l4);
            if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
            if ((size_t) l6 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
            l8 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l6];
            vader_struct___Tuple_i32_Union_i32_null__4a877297_t* _a3_obj = &_a2_storage;
            vader_obj_header_init(_a3_obj, 237u);
            _a3_obj->f__0 = l7;
            _a3_obj->f__1 = l8;
            t0 = (void*) _a3_obj;
            l9 = ((vader_struct___Tuple_i32_Union_i32_null__4a877297_t*) t0)->f__0;
            t1 = (l6 + INT64_C(1));
            l6 = (size_t) (int64_t) t1;
            if (l9 == l1) {
                { vader_gc_top = gc_frame.prev; return true; }
            }
            goto loop_12;
        }
    }
    { vader_gc_top = gc_frame.prev; return false; }
    vader_gc_top = gc_frame.prev;
}

static bool vader_midir_loop_scope_targets(void* l0, int32_t l1) {
    void* l2;
    void* l5;
    size_t l3, l4;
    bool l6;
    vader_string_t t0;
    int64_t t1;
    l2 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_scopes;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    l3 = ((vader_array_t*) l2)->length;
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_7: {
            if ((l4 < l3)) {
                if ((size_t) l4 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                l5 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
                t0 = ((vader_struct_vader_midir_ScopeFrame_t*) l5)->f_kind;
                if (t0 == 1905u) {
                    l6 = vader_midir_BlockId_Equals_equals(((vader_struct_vader_midir_ScopeFrame_t*) l5)->f_target_blk, l1);
                } else {
                    l6 = false;
                }
                if (l6) {
                    return true;
                }
                t1 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t1;
                goto loop_7;
            }
        }
    }
    return false;
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
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    if (l0.tag == 777u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_lower_LoweredStringLit_t*) t0)->f_value;
        vader_struct_vader_bytecode_BcValStr_t* _a0_obj = (vader_struct_vader_bytecode_BcValStr_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcValStr_t));
        vader_obj_header_init(_a0_obj, 520u);
        _a0_obj->f_value = t1;
        t0 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 781u) {
        vader_array_t* _a1_arr = vader_array_new(133u, 0u, 13u, 1130u);
        l1 = (void*) _a1_arr;
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_lower_LoweredStructLit_t*) t0)->f_fields;
        l3 = ((vader_array_t*) l2)->length;
        l4 = (size_t) (int64_t) INT64_C(0);
        {
            loop_24: {
                if ((l4 < l3)) {
                    vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
                    if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                    if ((size_t) l4 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                    t0 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
                    l5 = vader_midir_lowered_to_bc_value(((vader_struct_vader_lower_LoweredStructLitField_t*) t0)->f_value);
                    vader_array_push((vader_array_t*) l1, l5);
                    t2 = (l4 + INT64_C(1));
                    l4 = (size_t) (int64_t) t2;
                    goto loop_24;
                }
            }
        }
        t0 = l0.payload.obj;
        t3 = vader_midir_struct_symbol_id(((vader_struct_vader_lower_LoweredStructLit_t*) t0)->f_type);
        vader_struct_vader_bytecode_BcValStruct_t* _a3_obj = (vader_struct_vader_bytecode_BcValStruct_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcValStruct_t));
        vader_obj_header_init(_a3_obj, 521u);
        _a3_obj->f_symbol_id = t3;
        _a3_obj->f_fields = l1;
        t0 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 740u) {
        vader_array_t* _a4_arr = vader_array_new(133u, 0u, 13u, 1130u);
        l1 = (void*) _a4_arr;
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_lower_LoweredArrayLit_t*) t0)->f_elements;
        l3 = ((vader_array_t*) l2)->length;
        l4 = (size_t) (int64_t) INT64_C(0);
        {
            loop_68: {
                if ((l4 < l3)) {
                    vader_array_t* _a5_slotarr = ((vader_array_t*) l2);
                    if (_a5_slotarr->buf != NULL && _a5_slotarr->buf->header.forward != NULL) { _a5_slotarr->buf = vader_array_buf_forward(_a5_slotarr->buf); }
                    if ((size_t) l4 >= _a5_slotarr->length) { vader_trap("array index out of bounds"); }
                    t4 = vader_array_ref_load_box(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l4);
                    l5 = vader_midir_lowered_to_bc_value(t4);
                    vader_array_push((vader_array_t*) l1, l5);
                    t2 = (l4 + INT64_C(1));
                    l4 = (size_t) (int64_t) t2;
                    goto loop_68;
                }
            }
        }
        t0 = l0.payload.obj;
        t1 = vader_midir_array_element_name(((vader_struct_vader_lower_LoweredArrayLit_t*) t0)->f_type);
        vader_struct_vader_bytecode_BcValArray_t* _a6_obj = (vader_struct_vader_bytecode_BcValArray_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcValArray_t));
        vader_obj_header_init(_a6_obj, 518u);
        _a6_obj->f_element_type_name = t1;
        _a6_obj->f_elements = l1;
        t0 = (void*) _a6_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t4 = vader_lower_type_of(l0);
    l6 = vader_types_display_type_key(t4);
    l7 = vader_bytecode_array_kind_from_name(l6);
    l8 = vader_midir_bc_value_bits(l0, l6);
    vader_struct_vader_bytecode_BcValPrim_t* _a7_obj = (vader_struct_vader_bytecode_BcValPrim_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcValPrim_t));
    vader_obj_header_init(_a7_obj, 519u);
    _a7_obj->f_kind = l7;
    _a7_obj->f_bits = l8;
    t0 = (void*) _a7_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
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
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l1 = vader_midir_fn_metadata(l0);
    vader_array_t* _a0_arr = vader_array_new(79u, 0u, 13u, 807u);
    l2 = (void*) _a0_arr;
    l3 = ((vader_array_t*) ((vader_struct_vader_lower_LoweredFnDecl_t*) l0)->f_params)->length;
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_11: {
            if ((l4 < l3)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_lower_LoweredFnDecl_t*) l0)->f_params);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l4 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                l5 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
                l6 = ((vader_struct_vader_lower_LoweredParam_t*) l5)->f_name;
                l7 = ((vader_struct_vader_lower_LoweredParam_t*) l5)->f_symbol;
                l8 = ((vader_struct_vader_lower_LoweredParam_t*) l5)->f_type;
                l9 = ((int32_t) (size_t) l4);
                vader_struct_vader_midir_CFGParam_t* _a2_obj = (vader_struct_vader_midir_CFGParam_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_CFGParam_t));
                vader_obj_header_init(_a2_obj, 807u);
                _a2_obj->f_name = l6;
                _a2_obj->f_symbol = l7;
                _a2_obj->f_type = l8;
                _a2_obj->f_local = l9;
                l10 = (void*) _a2_obj;
                vader_array_push((vader_array_t*) l2, vader_ref_box(l10));
                t0 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                goto loop_11;
            }
        }
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
    vader_struct_vader_midir_CFGExternDecl_t* _a3_obj = (vader_struct_vader_midir_CFGExternDecl_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_CFGExternDecl_t));
    vader_obj_header_init(_a3_obj, 803u);
    _a3_obj->f_mangled = l6;
    _a3_obj->f_params = l2;
    _a3_obj->f_return_type = l8;
    _a3_obj->f_origin = l5;
    _a3_obj->f_extern_name = l11;
    _a3_obj->f_is_exported = l12;
    _a3_obj->f_is_extern = l13;
    _a3_obj->f_c_header = l14;
    _a3_obj->f_c_library = l15;
    _a3_obj->f_c_variadic_fixed = l9;
    t1 = (void*) _a3_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_midir_make_struct_decl(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l5 = NULL;
    void* l8 = NULL;
    size_t l3, l4;
    vader_string_t l6 = 0;
    vader_box_t l7 = vader_box_null();
    int64_t t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &l7 };
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l5, &l8, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l6 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(81u, 0u, 13u, 810u);
    l1 = (void*) _a0_arr;
    l2 = ((vader_struct_vader_lower_LoweredStructDecl_t*) l0)->f_fields;
    l3 = ((vader_array_t*) l2)->length;
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_9: {
            if ((l4 < l3)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l4 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                l5 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
                l6 = ((vader_struct_vader_lower_LoweredStructField_t*) l5)->f_name;
                l7 = ((vader_struct_vader_lower_LoweredStructField_t*) l5)->f_type;
                vader_struct_vader_midir_CFGStructField_t* _a2_obj = (vader_struct_vader_midir_CFGStructField_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_CFGStructField_t));
                vader_obj_header_init(_a2_obj, 810u);
                _a2_obj->f_name = l6;
                _a2_obj->f_type = l7;
                l8 = (void*) _a2_obj;
                vader_array_push((vader_array_t*) l1, vader_ref_box(l8));
                t0 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                goto loop_9;
            }
        }
    }
    l6 = ((vader_struct_vader_lower_LoweredStructDecl_t*) l0)->f_mangled;
    l2 = ((vader_struct_vader_lower_LoweredStructDecl_t*) l0)->f_origin;
    vader_struct_vader_midir_CFGStructDecl_t* _a3_obj = (vader_struct_vader_midir_CFGStructDecl_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_CFGStructDecl_t));
    vader_obj_header_init(_a3_obj, 809u);
    _a3_obj->f_mangled = l6;
    _a3_obj->f_fields = l1;
    _a3_obj->f_origin = l2;
    t1 = (void*) _a3_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_box_t vader_midir_multi_dsts(vader_box_t l0) {
    void* t0;
    vader_box_t t1;
    if (l0.tag == 830u) {
        t0 = l0.payload.obj;
        return vader_ref_box(((vader_struct_vader_midir_InstrCall_t*) t0)->f_dsts);
    }
    t1 = vader_box_obj(0u, NULL);
    return t1;
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
    void** gc_raw_roots[13] = { &l0, &l1, &l2, &l3, &l4, &l5, &l12, &l13, &l14, &l15, &l16, &l21, &t3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 13u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(9u, 0u, 7u, 179u);
    l3 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(16u, 0u, 0u, 187u);
    l4 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 179u);
    l5 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__i32__MutableSet_Any__t* _a3_obj = (vader_struct_std_collections_MutableMap__i32__MutableSet_Any__t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__MutableSet_Any__t));
    vader_obj_header_init(_a3_obj, 305u);
    _a3_obj->f_ekeys = l3;
    _a3_obj->f_evals = l4;
    _a3_obj->f_index = l5;
    _a3_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l3 = (void*) _a3_obj;
    l6 = ((vader_array_t*) ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_blocks)->length;
    l7 = (size_t) (int64_t) INT64_C(0);
    {
        loop_20: {
            if ((l7 < l6)) {
                l8 = ((int32_t) (size_t) l7);
                vader_array_t* _a4_arr = vader_array_new(9u, 0u, 7u, 179u);
                l4 = (void*) _a4_arr;
                vader_array_t* _a5_slotarr = ((vader_array_t*) l1);
                if (_a5_slotarr->buf != NULL && _a5_slotarr->buf->header.forward != NULL) { _a5_slotarr->buf = vader_array_buf_forward(_a5_slotarr->buf); }
                if ((size_t) l7 >= _a5_slotarr->length) { vader_trap("array index out of bounds"); }
                l5 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l7);
                l9 = ((vader_array_t*) l5)->length;
                l10 = (size_t) (int64_t) INT64_C(0);
                {
                    vader_array_t* _pc39_hdr = (vader_array_t*) l4;
                    size_t _pc39_len = _pc39_hdr->length;
                    size_t _pc39_cap = (_pc39_hdr->offset == 0 && !vader_array_is_borrowed(_pc39_hdr) && _pc39_hdr->length >= _pc39_hdr->buf->length) ? _pc39_hdr->capacity : (size_t) 0;
                    void* _pc39_slots = _pc39_hdr->buf->slots;
                    loop_39: {
                        if ((l10 < l9)) {
                            vader_array_t* _a6_slotarr = ((vader_array_t*) l5);
                            if (_a6_slotarr->buf != NULL && _a6_slotarr->buf->header.forward != NULL) { _a6_slotarr->buf = vader_array_buf_forward(_a6_slotarr->buf); }
                            if ((size_t) l10 >= _a6_slotarr->length) { vader_trap("array index out of bounds"); }
                            l11 = ((int32_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l10];
                            t0 = vader_midir_dominates(l2, l8, l11);
                            if (t0) {
                                if (VADER_LIKELY(_pc39_len < _pc39_cap)) {
                                    ((int32_t*) _pc39_slots)[_pc39_len] = (int32_t) (l11);
                                    _pc39_len += 1;
                                } else {
                                    _pc39_hdr->length = _pc39_len;
                                    if (_pc39_hdr->buf->length < _pc39_len) { _pc39_hdr->buf->length = _pc39_len; }
                                    vader_array_push_i32((vader_array_t*) l4, l11);
                                    _pc39_hdr = (vader_array_t*) l4;
                                    _pc39_len = _pc39_hdr->length;
                                    _pc39_cap = (_pc39_hdr->offset == 0 && !vader_array_is_borrowed(_pc39_hdr) && _pc39_hdr->length >= _pc39_hdr->buf->length) ? _pc39_hdr->capacity : (size_t) 0;
                                    _pc39_slots = _pc39_hdr->buf->slots;
                                }
                            }
                            t1 = (l10 + INT64_C(1));
                            l10 = (size_t) (int64_t) t1;
                            goto loop_39;
                        }
                        _pc39_hdr->length = _pc39_len;
                        if (_pc39_hdr->buf->length < _pc39_len) { _pc39_hdr->buf->length = _pc39_len; }
                    }
                }
                t2 = ((vader_array_t*) l4)->length;
                if (t2 == INT64_C(0)) {
                    t1 = (l7 + INT64_C(1));
                    l7 = (size_t) (int64_t) t1;
                    goto loop_20;
                }
                vader_array_t* _a7_arr = vader_array_new(9u, 0u, 7u, 179u);
                l12 = (void*) _a7_arr;
                vader_array_t* _a8_arr = vader_array_new(6u, 0u, 12u, 174u);
                l13 = (void*) _a8_arr;
                vader_array_t* _a9_arr = vader_array_new(9u, 0u, 7u, 179u);
                l14 = (void*) _a9_arr;
                vader_struct_std_collections_MutableMap__i32__bool_t* _a10_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
                vader_obj_header_init(_a10_obj, 316u);
                _a10_obj->f_ekeys = l12;
                _a10_obj->f_evals = l13;
                _a10_obj->f_index = l14;
                _a10_obj->f_mask = (size_t) (int64_t) INT64_C(0);
                _a10_obj->f_size = (size_t) (int64_t) INT64_C(0);
                _a10_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
                t3 = (void*) _a10_obj;
                vader_struct_std_collections_MutableSet__i32_t* _a11_obj = (vader_struct_std_collections_MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i32_t));
                vader_obj_header_init(_a11_obj, 384u);
                _a11_obj->f_inner = t3;
                l15 = (void*) _a11_obj;
                std_collections_add__i32(l15, l8);
                l16 = std_iter_clone__i32(l4);
                {
                    loop_98: {
                        t2 = ((vader_array_t*) l16)->length;
                        if ((t2 > INT64_C(0))) {
                            t2 = ((vader_array_t*) l16)->length;
                            t1 = (t2 - INT64_C(1));
                            l17 = (size_t) (int64_t) t1;
                            vader_array_t* _a12_slotarr = ((vader_array_t*) l16);
                            if (_a12_slotarr->buf != NULL && _a12_slotarr->buf->header.forward != NULL) { _a12_slotarr->buf = vader_array_buf_forward(_a12_slotarr->buf); }
                            if ((size_t) l17 >= _a12_slotarr->length) { vader_trap("array index out of bounds"); }
                            l18 = ((int32_t*) _a12_slotarr->buf->slots)[_a12_slotarr->offset + (size_t) l17];
                            t2 = ((vader_array_t*) l16)->length;
                            t1 = (t2 - INT64_C(1));
                            l19 = (size_t) (int64_t) t1;
                            vader_array_t* _a13_arr = vader_array_slice((vader_array_t*) l16, (size_t) INT64_C(0), (size_t) l19);
                            l16 = (void*) _a13_arr;
                            t0 = std_collections_MutableSet_Contains_contains__i32(l15, l18);
                            if (t0) {
                                goto loop_98;
                            }
                            std_collections_add__i32(l15, l18);
                            l20 = l18;
                            vader_array_t* _a14_slotarr = ((vader_array_t*) l1);
                            if (_a14_slotarr->buf != NULL && _a14_slotarr->buf->header.forward != NULL) { _a14_slotarr->buf = vader_array_buf_forward(_a14_slotarr->buf); }
                            if ((size_t) l20 >= _a14_slotarr->length) { vader_trap("array index out of bounds"); }
                            l21 = vader_array_ref_load_obj(_a14_slotarr->buf, _a14_slotarr->offset + (size_t) l20);
                            l22 = ((vader_array_t*) l21)->length;
                            l23 = (size_t) (int64_t) INT64_C(0);
                            {
                                loop_144: {
                                    if ((l23 < l22)) {
                                        vader_array_t* _a15_slotarr = ((vader_array_t*) l21);
                                        if (_a15_slotarr->buf != NULL && _a15_slotarr->buf->header.forward != NULL) { _a15_slotarr->buf = vader_array_buf_forward(_a15_slotarr->buf); }
                                        if ((size_t) l23 >= _a15_slotarr->length) { vader_trap("array index out of bounds"); }
                                        l24 = ((int32_t*) _a15_slotarr->buf->slots)[_a15_slotarr->offset + (size_t) l23];
                                        t0 = vader_midir_BlockId_Equals_equals(l24, l8);
                                        if (!(t0)) {
                                            vader_array_push_i32((vader_array_t*) l16, l24);
                                        }
                                        t1 = (l23 + INT64_C(1));
                                        l23 = (size_t) (int64_t) t1;
                                        goto loop_144;
                                    }
                                }
                            }
                            goto loop_98;
                        }
                    }
                }
                std_collections_MutableMap_IndexSet_set_at__i32__Any(l3, l8, vader_ref_box(l15));
                t1 = (l7 + INT64_C(1));
                l7 = (size_t) (int64_t) t1;
                goto loop_20;
            }
        }
    }
    { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static bool vader_midir_needs_ref_cast(vader_box_t l0) {
    void* t0;
    vader_string_t t1;
    if (!(l0.tag == 936u)) {
        return false;
    }
    t0 = l0.payload.obj;
    t1 = ((vader_struct_vader_types_PrimitiveType_t*) t0)->f_name;
    return t1 != 2479u;
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
    vader_array_t* _a0_arr = vader_array_new(141u, 0u, 13u, 1220u);
    l4 = (void*) _a0_arr;
    vader_struct_vader_midir_MutableBlock_t* _a1_obj = (vader_struct_vader_midir_MutableBlock_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_MutableBlock_t));
    vader_obj_header_init(_a1_obj, 855u);
    _a1_obj->f_id = l2;
    _a1_obj->f_instructions = l4;
    _a1_obj->f_terminator = vader_box_obj(0u, NULL);
    _a1_obj->f_span = l1;
    l4 = (void*) _a1_obj;
    vader_array_push((vader_array_t*) l3, vader_ref_box(l4));
    { int32_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_midir_new_project_ctx(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    void* l14 = NULL;
    void* l15 = NULL;
    void* l16 = NULL;
    void* l17 = NULL;
    void* l18 = NULL;
    size_t l6, l7, l11, l12, l19, l20;
    vader_string_t l8 = 0;
    vader_box_t l13 = vader_box_null();
    int32_t l21;
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    void* t3 = NULL;
    int64_t t2;
    bool t4;
    size_t t5;
    vader_box_t* gc_roots[2] = { &l13, &t0 };
    void** gc_raw_roots[15] = { &l0, &l1, &l2, &l3, &l4, &l5, &l9, &l10, &l14, &l15, &l16, &l17, &l18, &t1, &t3 };
    vader_string_t* gc_atom_roots[1] = { &l8 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 15u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(9u, 0u, 7u, 179u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(16u, 0u, 0u, 187u);
    l3 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 179u);
    l4 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__i32__MutableSet_Any__t* _a3_obj = (vader_struct_std_collections_MutableMap__i32__MutableSet_Any__t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__MutableSet_Any__t));
    vader_obj_header_init(_a3_obj, 305u);
    _a3_obj->f_ekeys = l2;
    _a3_obj->f_evals = l3;
    _a3_obj->f_index = l4;
    _a3_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l2 = (void*) _a3_obj;
    l3 = ((vader_struct_vader_lower_LoweredProject_t*) l0)->f_modules;
    l4 = ((vader_struct_std_collections_MutableMap__string__LoweredModule_t*) l3)->f_ekeys;
    l5 = ((vader_struct_std_collections_MutableMap__string__LoweredModule_t*) l3)->f_evals;
    l6 = ((vader_struct_std_collections_MutableMap__string__LoweredModule_t*) l3)->f_size;
    l7 = (size_t) (int64_t) INT64_C(0);
    {
        loop_26: {
            if ((l7 >= l6)) {
            } else {
                vader_array_t* _a4_slotarr = ((vader_array_t*) l4);
                if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                if ((size_t) l7 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_box_slots(_a4_slotarr->buf)[_a4_slotarr->offset + (size_t) l7];
                l8 = t0.payload.s;
                vader_array_t* _a5_slotarr = ((vader_array_t*) l5);
                if (_a5_slotarr->buf != NULL && _a5_slotarr->buf->header.forward != NULL) { _a5_slotarr->buf = vader_array_buf_forward(_a5_slotarr->buf); }
                if ((size_t) l7 >= _a5_slotarr->length) { vader_trap("array index out of bounds"); }
                l3 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l7);
                vader_struct___Tuple_2_edd3c91327bcb309_t* _a6_obj = (vader_struct___Tuple_2_edd3c91327bcb309_t*) vader_gc_alloc(sizeof(vader_struct___Tuple_2_edd3c91327bcb309_t));
                vader_obj_header_init(_a6_obj, 232u);
                _a6_obj->f__0 = l8;
                _a6_obj->f__1 = l3;
                t1 = (void*) _a6_obj;
                l9 = ((vader_struct___Tuple_2_edd3c91327bcb309_t*) t1)->f__1;
                t2 = (l7 + INT64_C(1));
                l7 = (size_t) (int64_t) t2;
                l10 = ((vader_struct_vader_lower_LoweredModule_t*) l9)->f_decls;
                l11 = ((vader_array_t*) l10)->length;
                l12 = (size_t) (int64_t) INT64_C(0);
                {
                    loop_57: {
                        if ((l12 < l11)) {
                            vader_array_t* _a7_slotarr = ((vader_array_t*) l10);
                            if (_a7_slotarr->buf != NULL && _a7_slotarr->buf->header.forward != NULL) { _a7_slotarr->buf = vader_array_buf_forward(_a7_slotarr->buf); }
                            if ((size_t) l12 >= _a7_slotarr->length) { vader_trap("array index out of bounds"); }
                            l13 = vader_array_ref_load_box(_a7_slotarr->buf, _a7_slotarr->offset + (size_t) l12);
                            if (l13.tag == 763u) {
                                t1 = l13.payload.obj;
                                t3 = vader_midir_fn_metadata(t1);
                                t4 = ((vader_struct_vader_midir_FnMetadata_t*) t3)->f_is_extern;
                                if (t4) {
                                    t1 = l13.payload.obj;
                                    if (((vader_struct_vader_comptime_MonoEntry_t*) ((vader_struct_vader_lower_LoweredFnDecl_t*) t1)->f_origin)->f_symbol.tag == 899u) {
                                        t1 = l13.payload.obj;
                                        l14 = ((vader_struct_vader_comptime_MonoEntry_t*) ((vader_struct_vader_lower_LoweredFnDecl_t*) t1)->f_origin)->f_symbol.payload.obj;
                                        vader_array_t* _a8_arr = vader_array_new(15u, 0u, 4u, 186u);
                                        l15 = (void*) _a8_arr;
                                        vader_array_t* _a9_arr = vader_array_new(6u, 0u, 12u, 174u);
                                        l16 = (void*) _a9_arr;
                                        vader_array_t* _a10_arr = vader_array_new(9u, 0u, 7u, 179u);
                                        l17 = (void*) _a10_arr;
                                        vader_struct_std_collections_MutableMap__usize__bool_t* _a11_obj = (vader_struct_std_collections_MutableMap__usize__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__usize__bool_t));
                                        vader_obj_header_init(_a11_obj, 381u);
                                        _a11_obj->f_ekeys = l15;
                                        _a11_obj->f_evals = l16;
                                        _a11_obj->f_index = l17;
                                        _a11_obj->f_mask = (size_t) (int64_t) INT64_C(0);
                                        _a11_obj->f_size = (size_t) (int64_t) INT64_C(0);
                                        _a11_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
                                        t1 = (void*) _a11_obj;
                                        vader_struct_std_collections_MutableSet__usize_t* _a12_obj = (vader_struct_std_collections_MutableSet__usize_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__usize_t));
                                        vader_obj_header_init(_a12_obj, 387u);
                                        _a12_obj->f_inner = t1;
                                        l18 = (void*) _a12_obj;
                                        t1 = l13.payload.obj;
                                        l19 = ((vader_array_t*) ((vader_struct_vader_lower_LoweredFnDecl_t*) t1)->f_params)->length;
                                        l20 = (size_t) (int64_t) INT64_C(0);
                                        {
                                            loop_109: {
                                                if ((l20 < l19)) {
                                                    t1 = l13.payload.obj;
                                                    vader_array_t* _a13_slotarr = ((vader_array_t*) ((vader_struct_vader_lower_LoweredFnDecl_t*) t1)->f_params);
                                                    if (_a13_slotarr->buf != NULL && _a13_slotarr->buf->header.forward != NULL) { _a13_slotarr->buf = vader_array_buf_forward(_a13_slotarr->buf); }
                                                    if ((size_t) l20 >= _a13_slotarr->length) { vader_trap("array index out of bounds"); }
                                                    t1 = vader_array_ref_load_obj(_a13_slotarr->buf, _a13_slotarr->offset + (size_t) l20);
                                                    if (((vader_struct_vader_lower_LoweredParam_t*) t1)->f_type.tag == 930u) {
                                                        std_collections_add__usize(l18, l20);
                                                    }
                                                    t2 = (l20 + INT64_C(1));
                                                    l20 = (size_t) (int64_t) t2;
                                                    goto loop_109;
                                                }
                                            }
                                        }
                                        t5 = std_collections_len__usize(l18);
                                        if ((t5 > INT64_C(0))) {
                                            l21 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l14)->f_id;
                                            std_collections_MutableMap_IndexSet_set_at__i32__Any(l2, l21, vader_ref_box(l18));
                                        }
                                    }
                                }
                            }
                            t2 = (l12 + INT64_C(1));
                            l12 = (size_t) (int64_t) t2;
                            goto loop_57;
                        }
                    }
                }
                goto loop_26;
            }
        }
    }
    vader_array_t* _a14_arr = vader_array_new(8u, 0u, 0u, 176u);
    l3 = (void*) _a14_arr;
    vader_array_t* _a15_arr = vader_array_new(8u, 0u, 0u, 176u);
    l4 = (void*) _a15_arr;
    vader_array_t* _a16_arr = vader_array_new(9u, 0u, 7u, 179u);
    l5 = (void*) _a16_arr;
    vader_array_t* _a17_arr = vader_array_new(9u, 0u, 7u, 179u);
    l9 = (void*) _a17_arr;
    vader_struct_std_collections_MutableMap__string__i32_t* _a18_obj = (vader_struct_std_collections_MutableMap__string__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__i32_t));
    vader_obj_header_init(_a18_obj, 365u);
    _a18_obj->f_ekeys = l4;
    _a18_obj->f_evals = l5;
    _a18_obj->f_index = l9;
    _a18_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a18_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a18_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l4 = (void*) _a18_obj;
    l5 = ((vader_struct_vader_lower_LoweredProject_t*) l0)->f_const_fn_wrap;
    l9 = ((vader_struct_vader_lower_LoweredProject_t*) l0)->f_const_inline;
    vader_struct_vader_midir_ProjectCtx_t* _a19_obj = (vader_struct_vader_midir_ProjectCtx_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_ProjectCtx_t));
    vader_obj_header_init(_a19_obj, 857u);
    _a19_obj->f_strings = l3;
    _a19_obj->f_string_index = l4;
    _a19_obj->f_const_fn_wrap = l5;
    _a19_obj->f_const_inline = l9;
    _a19_obj->f_extern_callbacks = l2;
    _a19_obj->f_diags = l1;
    t1 = (void*) _a19_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
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
    vader_array_t* _a0_arr = vader_array_new(10u, 0u, 8u, 180u);
    l0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(6u, 0u, 12u, 174u);
    l1 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 179u);
    l2 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__i64__bool_t* _a3_obj = (vader_struct_std_collections_MutableMap__i64__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i64__bool_t));
    vader_obj_header_init(_a3_obj, 325u);
    _a3_obj->f_ekeys = l0;
    _a3_obj->f_evals = l1;
    _a3_obj->f_index = l2;
    _a3_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    t0 = (void*) _a3_obj;
    vader_struct_std_collections_MutableSet__i64_t* _a4_obj = (vader_struct_std_collections_MutableSet__i64_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i64_t));
    vader_obj_header_init(_a4_obj, 385u);
    _a4_obj->f_inner = t0;
    l0 = (void*) _a4_obj;
    vader_array_t* _a5_arr = vader_array_new(10u, 0u, 8u, 180u);
    l1 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(6u, 0u, 12u, 174u);
    l2 = (void*) _a6_arr;
    vader_array_t* _a7_arr = vader_array_new(9u, 0u, 7u, 179u);
    l3 = (void*) _a7_arr;
    vader_struct_std_collections_MutableMap__i64__bool_t* _a8_obj = (vader_struct_std_collections_MutableMap__i64__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i64__bool_t));
    vader_obj_header_init(_a8_obj, 325u);
    _a8_obj->f_ekeys = l1;
    _a8_obj->f_evals = l2;
    _a8_obj->f_index = l3;
    _a8_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a8_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a8_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    t0 = (void*) _a8_obj;
    vader_struct_std_collections_MutableSet__i64_t* _a9_obj = (vader_struct_std_collections_MutableSet__i64_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i64_t));
    vader_obj_header_init(_a9_obj, 385u);
    _a9_obj->f_inner = t0;
    l1 = (void*) _a9_obj;
    vader_array_t* _a10_arr = vader_array_new(9u, 0u, 7u, 179u);
    l2 = (void*) _a10_arr;
    vader_array_t* _a11_arr = vader_array_new(6u, 0u, 12u, 174u);
    l3 = (void*) _a11_arr;
    vader_array_t* _a12_arr = vader_array_new(9u, 0u, 7u, 179u);
    l4 = (void*) _a12_arr;
    vader_struct_std_collections_MutableMap__i32__bool_t* _a13_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
    vader_obj_header_init(_a13_obj, 316u);
    _a13_obj->f_ekeys = l2;
    _a13_obj->f_evals = l3;
    _a13_obj->f_index = l4;
    _a13_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a13_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a13_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    t0 = (void*) _a13_obj;
    vader_struct_std_collections_MutableSet__i32_t* _a14_obj = (vader_struct_std_collections_MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i32_t));
    vader_obj_header_init(_a14_obj, 384u);
    _a14_obj->f_inner = t0;
    l2 = (void*) _a14_obj;
    vader_struct_vader_midir_ScheduleHints_t* _a15_obj = (vader_struct_vader_midir_ScheduleHints_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_ScheduleHints_t));
    vader_obj_header_init(_a15_obj, 858u);
    _a15_obj->f_skip_set = l0;
    _a15_obj->f_skip_first_get = l1;
    _a15_obj->f_skip_terminator_get = l2;
    t0 = (void*) _a15_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
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
    vader_gc_top = gc_frame.prev;
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
    void* t0 = NULL;
    int64_t t1;
    void** gc_raw_roots[7] = { &l0, &l2, &l3, &l5, &l6, &l10, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 7u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = ((vader_array_t*) ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_blocks)->length;
    vader_struct___lambda_env_vader_midir_5_t* _a0_obj = (vader_struct___lambda_env_vader_midir_5_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_midir_5_t));
    vader_obj_header_init(_a0_obj, 266u);
    t0 = (void*) _a0_obj;
    vader_fn_t* _a1_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
    vader_obj_header_init(_a1_closure, 144u);
    _a1_closure->code = (void*) &vader_fn_lift___lambda_vader_midir_4;
    _a1_closure->env = t0;
    l2 = (void*) _a1_closure;
    l2 = std_core_filled__i32__(l1, l2);
    l3 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_blocks;
    l1 = ((vader_array_t*) l3)->length;
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_17: {
            if ((l4 < l1)) {
                vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
                if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                if ((size_t) l4 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                l5 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
                l6 = vader_midir_successors_of(l5);
                l7 = ((vader_array_t*) l6)->length;
                l8 = (size_t) (int64_t) INT64_C(0);
                {
                    loop_33: {
                        if ((l8 < l7)) {
                            vader_array_t* _a3_slotarr = ((vader_array_t*) l6);
                            if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                            if ((size_t) l8 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                            l9 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l8];
                            vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
                            if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                            if ((size_t) l9 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                            l10 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l9);
                            l11 = ((vader_struct_vader_midir_BasicBlock_t*) l5)->f_id;
                            vader_array_push_i32((vader_array_t*) l10, l11);
                            t1 = (l8 + INT64_C(1));
                            l8 = (size_t) (int64_t) t1;
                            goto loop_33;
                        }
                    }
                }
                t1 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t1;
                goto loop_17;
            }
        }
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
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
    vader_gc_top = gc_frame.prev;
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
    vader_gc_top = gc_frame.prev;
}

static bool vader_midir_read_may_carry_ref(vader_box_t l0) {
    uint8_t l1;
    bool l2;
    l1 = vader_bytecode_val_type_of_type(l0);
    if (l1 == INT32_C(18)) {
        l2 = true;
    } else {
        l2 = l1 == INT32_C(19);
    }
    return l2;
}

static void vader_midir_record_alias(void* l0, void* l1, int32_t l2, int32_t l3) {
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_midir_append_alias(l0, l2, l3);
    vader_midir_append_alias(l1, l3, l2);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
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
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    if (l0.tag == 836u) {
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
        vader_obj_header_init(_a0_obj, 836u);
        _a0_obj->f_span = l2;
        _a0_obj->f_dst = l3;
        _a0_obj->f_value = l4;
        _a0_obj->f_type = l5;
        t0 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 846u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_midir_InstrMove_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrMove_t*) t0)->f_dst;
        l3 = vader_midir_remap_local(l1, l3);
        t0 = l0.payload.obj;
        l6 = ((vader_struct_vader_midir_InstrMove_t*) t0)->f_src;
        l6 = vader_midir_remap_local(l1, l6);
        vader_struct_vader_midir_InstrMove_t* _a1_obj = (vader_struct_vader_midir_InstrMove_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrMove_t));
        vader_obj_header_init(_a1_obj, 846u);
        _a1_obj->f_span = l2;
        _a1_obj->f_dst = l3;
        _a1_obj->f_src = l6;
        t0 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 829u) {
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
        vader_obj_header_init(_a2_obj, 829u);
        _a2_obj->f_span = l2;
        _a2_obj->f_dst = l3;
        _a2_obj->f_op = l7;
        _a2_obj->f_lhs = l6;
        _a2_obj->f_rhs = l8;
        _a2_obj->f_type = l4;
        t0 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 851u) {
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
        vader_obj_header_init(_a3_obj, 851u);
        _a3_obj->f_span = l2;
        _a3_obj->f_dst = l3;
        _a3_obj->f_op = l7;
        _a3_obj->f_operand = l6;
        _a3_obj->f_type = l4;
        t0 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 830u) {
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
        vader_obj_header_init(_a4_obj, 830u);
        _a4_obj->f_span = l2;
        _a4_obj->f_dsts = l9;
        _a4_obj->f_callee = l10;
        _a4_obj->f_args = l11;
        _a4_obj->f_type = l4;
        t0 = (void*) _a4_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 831u) {
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
        vader_obj_header_init(_a5_obj, 831u);
        _a5_obj->f_span = l2;
        _a5_obj->f_dst = l4;
        _a5_obj->f_callee = l3;
        _a5_obj->f_args = l9;
        _a5_obj->f_fn_type = l5;
        _a5_obj->f_type = l12;
        t0 = (void*) _a5_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 852u) {
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
        vader_struct_vader_midir_InstrVirtualCall_t* _a6_obj = (vader_struct_vader_midir_InstrVirtualCall_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrVirtualCall_t));
        vader_obj_header_init(_a6_obj, 852u);
        _a6_obj->f_span = l2;
        _a6_obj->f_dst = l4;
        _a6_obj->f_trait_name = l13;
        _a6_obj->f_method = l14;
        _a6_obj->f_receiver = l3;
        _a6_obj->f_args = l9;
        _a6_obj->f_type = l5;
        t0 = (void*) _a6_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 843u) {
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
        vader_obj_header_init(_a7_obj, 843u);
        _a7_obj->f_span = l2;
        _a7_obj->f_dst = l3;
        _a7_obj->f_fn_symbol = l9;
        _a7_obj->f_type = l4;
        t0 = (void*) _a7_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 842u) {
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
        vader_obj_header_init(_a8_obj, 842u);
        _a8_obj->f_span = l2;
        _a8_obj->f_dst = l3;
        _a8_obj->f_fn_symbol = l9;
        _a8_obj->f_type = l4;
        t0 = (void*) _a8_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 840u) {
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
        vader_obj_header_init(_a9_obj, 840u);
        _a9_obj->f_span = l2;
        _a9_obj->f_dst = l3;
        _a9_obj->f_target = l6;
        _a9_obj->f_field = l13;
        _a9_obj->f_type = l4;
        t0 = (void*) _a9_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 841u) {
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
        vader_obj_header_init(_a10_obj, 841u);
        _a10_obj->f_span = l2;
        _a10_obj->f_target = l3;
        _a10_obj->f_field = l13;
        _a10_obj->f_value = l6;
        _a10_obj->f_barrierless = l15;
        t0 = (void*) _a10_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 823u) {
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
        vader_obj_header_init(_a11_obj, 823u);
        _a11_obj->f_span = l2;
        _a11_obj->f_dst = l3;
        _a11_obj->f_target = l6;
        _a11_obj->f_index = l8;
        _a11_obj->f_type = l4;
        _a11_obj->f_bounds_safe = l15;
        t0 = (void*) _a11_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 827u) {
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
        vader_obj_header_init(_a12_obj, 827u);
        _a12_obj->f_span = l2;
        _a12_obj->f_target = l3;
        _a12_obj->f_index = l6;
        _a12_obj->f_value = l8;
        _a12_obj->f_bounds_safe = l15;
        t0 = (void*) _a12_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 824u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_midir_InstrArrayLen_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrArrayLen_t*) t0)->f_dst;
        l3 = vader_midir_remap_local(l1, l3);
        t0 = l0.payload.obj;
        l6 = ((vader_struct_vader_midir_InstrArrayLen_t*) t0)->f_target;
        l6 = vader_midir_remap_local(l1, l6);
        t0 = l0.payload.obj;
        l15 = ((vader_struct_vader_midir_InstrArrayLen_t*) t0)->f_resolve_buf;
        vader_struct_vader_midir_InstrArrayLen_t* _a13_obj = (vader_struct_vader_midir_InstrArrayLen_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrArrayLen_t));
        vader_obj_header_init(_a13_obj, 824u);
        _a13_obj->f_span = l2;
        _a13_obj->f_dst = l3;
        _a13_obj->f_target = l6;
        _a13_obj->f_resolve_buf = l15;
        t0 = (void*) _a13_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 826u) {
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
        vader_obj_header_init(_a14_obj, 826u);
        _a14_obj->f_span = l2;
        _a14_obj->f_target = l3;
        _a14_obj->f_value = l6;
        _a14_obj->f_cached = l15;
        t0 = (void*) _a14_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 828u) {
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
        vader_obj_header_init(_a15_obj, 828u);
        _a15_obj->f_span = l2;
        _a15_obj->f_dst = l3;
        _a15_obj->f_type = l4;
        _a15_obj->f_target = l6;
        _a15_obj->f_lo = l8;
        _a15_obj->f_hi = l16;
        t0 = (void*) _a15_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 847u) {
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
        vader_obj_header_init(_a16_obj, 847u);
        _a16_obj->f_span = l2;
        _a16_obj->f_dst = l3;
        _a16_obj->f_type = l4;
        _a16_obj->f_target = l6;
        _a16_obj->f_lo = l8;
        _a16_obj->f_hi = l16;
        t0 = (void*) _a16_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 848u) {
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
        vader_obj_header_init(_a17_obj, 848u);
        _a17_obj->f_span = l2;
        _a17_obj->f_dst = l3;
        _a17_obj->f_type = l4;
        _a17_obj->f_fields = l9;
        _a17_obj->f_stack = l15;
        t0 = (void*) _a17_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 825u) {
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
        vader_obj_header_init(_a18_obj, 825u);
        _a18_obj->f_span = l2;
        _a18_obj->f_dst = l3;
        _a18_obj->f_type = l4;
        _a18_obj->f_length = l6;
        _a18_obj->f_elements = l9;
        _a18_obj->f_stack = l15;
        t0 = (void*) _a18_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 837u) {
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
        vader_obj_header_init(_a19_obj, 837u);
        _a19_obj->f_span = l2;
        _a19_obj->f_dst = l3;
        _a19_obj->f_type = l4;
        _a19_obj->f_pool_index = l6;
        t0 = (void*) _a19_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 849u) {
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
        vader_obj_header_init(_a20_obj, 849u);
        _a20_obj->f_span = l2;
        _a20_obj->f_dst = l3;
        _a20_obj->f_value = l6;
        _a20_obj->f_check_type = l4;
        t0 = (void*) _a20_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 850u) {
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
        vader_obj_header_init(_a21_obj, 850u);
        _a21_obj->f_span = l2;
        _a21_obj->f_dst = l3;
        _a21_obj->f_type = l4;
        _a21_obj->f_value_type = l5;
        t0 = (void*) _a21_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 832u) {
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
        vader_obj_header_init(_a22_obj, 832u);
        _a22_obj->f_span = l2;
        _a22_obj->f_dst = l3;
        _a22_obj->f_value = l6;
        _a22_obj->f_type = l4;
        t0 = (void*) _a22_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 834u) {
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
        vader_obj_header_init(_a23_obj, 834u);
        _a23_obj->f_span = l2;
        _a23_obj->f_dst = l3;
        _a23_obj->f_value = l6;
        _a23_obj->f_value_type = l4;
        t0 = (void*) _a23_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 833u) {
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
        vader_obj_header_init(_a24_obj, 833u);
        _a24_obj->f_span = l2;
        _a24_obj->f_dst = l3;
        _a24_obj->f_cell = l6;
        _a24_obj->f_value_type = l4;
        t0 = (void*) _a24_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 835u) {
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
        vader_obj_header_init(_a25_obj, 835u);
        _a25_obj->f_span = l2;
        _a25_obj->f_cell = l3;
        _a25_obj->f_value = l6;
        _a25_obj->f_value_type = l4;
        t0 = (void*) _a25_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 845u) {
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
        vader_obj_header_init(_a26_obj, 845u);
        _a26_obj->f_span = l2;
        _a26_obj->f_dst = l3;
        _a26_obj->f_fn_symbol = l9;
        _a26_obj->f_env = l6;
        _a26_obj->f_env_type = l4;
        _a26_obj->f_type = l5;
        t0 = (void*) _a26_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 844u) {
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
        vader_obj_header_init(_a27_obj, 844u);
        _a27_obj->f_span = l2;
        _a27_obj->f_dst = l4;
        _a27_obj->f_name = l13;
        _a27_obj->f_args = l9;
        t0 = (void*) _a27_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 839u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_midir_InstrDeferPush_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrDeferPush_t*) t0)->f_value;
        l3 = vader_midir_remap_local(l1, l3);
        vader_struct_vader_midir_InstrDeferPush_t* _a28_obj = (vader_struct_vader_midir_InstrDeferPush_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrDeferPush_t));
        vader_obj_header_init(_a28_obj, 839u);
        _a28_obj->f_span = l2;
        _a28_obj->f_value = l3;
        t0 = (void*) _a28_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l0.payload.obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static int32_t vader_midir_remap_local(void* l0, int32_t l1) {
    size_t l2, l3;
    int64_t t0;
    int32_t t1;
    t0 = ((int64_t) (int32_t) l1);
    l2 = (size_t) (int64_t) t0;
    l3 = ((vader_array_t*) l0)->length;
    if ((l2 < l3)) {
        t0 = ((int64_t) (int32_t) l1);
        l2 = (size_t) (int64_t) t0;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
        if ((size_t) l2 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
        t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l2];
        return t1;
    }
    return l1;
}

static vader_box_t vader_midir_remap_local_opt(void* l0, vader_box_t l1) {
    int32_t l2;
    vader_box_t t0;
    int32_t t1;
    if (l1.tag == 0u) {
        t0 = vader_box_obj(0u, NULL);
        return t0;
    }
    if (l1.tag == 179u) {
        l2 = ((int32_t) l1.payload.i);
        t1 = vader_midir_remap_local(l0, l2);
        t0 = vader_box_i32(179u, t1);
        return t0;
    }
    t0 = vader_box_obj(0u, NULL);
    return t0;
}

static void* vader_midir_remap_locals(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    size_t l4, l5;
    int32_t l6, l7;
    int64_t t0;
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(9u, 0u, 7u, 179u);
    l2 = (void*) _a0_arr;
    l3 = l1;
    l4 = ((vader_array_t*) l3)->length;
    l5 = (size_t) (int64_t) INT64_C(0);
    {
        vader_array_t* _pc9_hdr = (vader_array_t*) l2;
        size_t _pc9_len = _pc9_hdr->length;
        size_t _pc9_cap = (_pc9_hdr->offset == 0 && !vader_array_is_borrowed(_pc9_hdr) && _pc9_hdr->length >= _pc9_hdr->buf->length) ? _pc9_hdr->capacity : (size_t) 0;
        void* _pc9_slots = _pc9_hdr->buf->slots;
        loop_9: {
            if ((l5 < l4)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l5 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                l6 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l5];
                l7 = vader_midir_remap_local(l0, l6);
                if (VADER_LIKELY(_pc9_len < _pc9_cap)) {
                    ((int32_t*) _pc9_slots)[_pc9_len] = (int32_t) (l7);
                    _pc9_len += 1;
                } else {
                    _pc9_hdr->length = _pc9_len;
                    if (_pc9_hdr->buf->length < _pc9_len) { _pc9_hdr->buf->length = _pc9_len; }
                    vader_array_push_i32((vader_array_t*) l2, l7);
                    _pc9_hdr = (vader_array_t*) l2;
                    _pc9_len = _pc9_hdr->length;
                    _pc9_cap = (_pc9_hdr->offset == 0 && !vader_array_is_borrowed(_pc9_hdr) && _pc9_hdr->length >= _pc9_hdr->buf->length) ? _pc9_hdr->capacity : (size_t) 0;
                    _pc9_slots = _pc9_hdr->buf->slots;
                }
                t0 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t0;
                goto loop_9;
            }
            _pc9_hdr->length = _pc9_len;
            if (_pc9_hdr->buf->length < _pc9_len) { _pc9_hdr->buf->length = _pc9_len; }
        }
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_box_t vader_midir_remap_terminator(vader_box_t l0, void* l1) {
    void* l2 = NULL;
    void* l7 = NULL;
    int32_t l3, l4, l5, l6;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l0, &t1 };
    void** gc_raw_roots[4] = { &l1, &l2, &l7, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 860u) {
        t0 = l0.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 863u) {
        t0 = l0.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 861u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_midir_TermCondBranch_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_TermCondBranch_t*) t0)->f_cond;
        l3 = vader_midir_remap_local(l1, l3);
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir_TermCondBranch_t*) t0)->f_then_block;
        t0 = l0.payload.obj;
        l5 = ((vader_struct_vader_midir_TermCondBranch_t*) t0)->f_else_block;
        t0 = l0.payload.obj;
        l6 = ((vader_struct_vader_midir_TermCondBranch_t*) t0)->f_join;
        vader_struct_vader_midir_TermCondBranch_t* _a0_obj = (vader_struct_vader_midir_TermCondBranch_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_TermCondBranch_t));
        vader_obj_header_init(_a0_obj, 861u);
        _a0_obj->f_span = l2;
        _a0_obj->f_cond = l3;
        _a0_obj->f_then_block = l4;
        _a0_obj->f_else_block = l5;
        _a0_obj->f_join = l6;
        t0 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 862u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_midir_TermReturn_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l7 = ((vader_struct_vader_midir_TermReturn_t*) t0)->f_values;
        l7 = vader_midir_remap_locals(l1, l7);
        vader_struct_vader_midir_TermReturn_t* _a1_obj = (vader_struct_vader_midir_TermReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_TermReturn_t));
        vader_obj_header_init(_a1_obj, 862u);
        _a1_obj->f_span = l2;
        _a1_obj->f_values = l7;
        t0 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = l0;
    { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
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
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_midir_CFGExternDecl_t*) l0)->f_params;
    l3 = ((vader_struct_vader_midir_CFGExternDecl_t*) l0)->f_return_type;
    vader_array_t* _a0_arr = vader_array_new(142u, 0u, 13u, 1246u);
    l4 = (void*) _a0_arr;
    l2 = vader_midir_build_cfg_signature(l2, l3, l4, l1);
    l4 = ((vader_struct_vader_midir_CFGExternDecl_t*) l0)->f_origin;
    l2 = vader_midir_with_by_address(l2, l4);
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
    vader_obj_header_init(_a1_obj, 508u);
    _a1_obj->f_extern_name = l6;
    _a1_obj->f_mangled_name = l7;
    _a1_obj->f_signature = l2;
    _a1_obj->f_is_extern = l8;
    _a1_obj->f_c_header = l9;
    _a1_obj->f_c_library = l10;
    _a1_obj->f_c_variadic_fixed = l11;
    l2 = (void*) _a1_obj;
    vader_array_push((vader_array_t*) l4, vader_ref_box(l2));
    if (((vader_struct_vader_comptime_MonoEntry_t*) ((vader_struct_vader_midir_CFGExternDecl_t*) l0)->f_origin)->f_symbol.tag == 899u) {
        l2 = ((vader_struct_vader_comptime_MonoEntry_t*) ((vader_struct_vader_midir_CFGExternDecl_t*) l0)->f_origin)->f_symbol.payload.obj;
        l4 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_import_index_by_symbol_id;
        l11 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l2)->f_id;
        std_collections_MutableMap_IndexSet_set_at__i32__i32(l4, l11, l5);
    }
    l2 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_import_index_by_mangle;
    l6 = ((vader_struct_vader_midir_CFGExternDecl_t*) l0)->f_mangled;
    std_collections_MutableMap_IndexSet_set_at__string__i32(l2, l6, l5);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_midir_reserve_cfg_function(void* l0, void* l1) {
    void* l2 = NULL;
    void* l4 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    vader_box_t l3 = vader_box_null();
    int32_t l5, l12;
    vader_string_t l10 = 0;
    bool l11;
    size_t t0;
    vader_box_t* gc_roots[1] = { &l3 };
    void** gc_raw_roots[8] = { &l0, &l1, &l2, &l4, &l6, &l7, &l8, &l9 };
    vader_string_t* gc_atom_roots[1] = { &l10 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_params;
    l3 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_return_type;
    l4 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_scalarised_results;
    l2 = vader_midir_build_cfg_signature(l2, l3, l4, l1);
    t0 = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_functions)->length;
    l5 = ((int32_t) (size_t) t0);
    vader_array_t* _a0_arr = vader_array_new(129u, 0u, 13u, 1114u);
    l4 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(134u, 0u, 13u, 1146u);
    l6 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 179u);
    l7 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(40u, 0u, 13u, 509u);
    l8 = (void*) _a3_arr;
    l9 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_functions;
    l10 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_mangled;
    l11 = ((vader_struct_vader_comptime_MonoEntry_t*) ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_origin)->f_is_main;
    vader_struct_vader_bytecode_BcFunction_t* _a4_obj = (vader_struct_vader_bytecode_BcFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcFunction_t));
    vader_obj_header_init(_a4_obj, 507u);
    _a4_obj->f_name = l10;
    _a4_obj->f_is_main = l11;
    _a4_obj->f_signature = l2;
    _a4_obj->f_locals = l8;
    _a4_obj->f_body = l4;
    _a4_obj->f_debug = l6;
    _a4_obj->f_jump_table = l7;
    l2 = (void*) _a4_obj;
    vader_array_push((vader_array_t*) l9, vader_ref_box(l2));
    if (((vader_struct_vader_comptime_MonoEntry_t*) ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_origin)->f_symbol.tag == 899u) {
        l2 = ((vader_struct_vader_comptime_MonoEntry_t*) ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_origin)->f_symbol.payload.obj;
        l4 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_function_index_by_symbol_id;
        l12 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l2)->f_id;
        std_collections_MutableMap_IndexSet_set_at__i32__i32(l4, l12, l5);
    }
    l2 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_function_index_by_mangle;
    l10 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_mangled;
    std_collections_MutableMap_IndexSet_set_at__string__i32(l2, l10, l5);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
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
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = -(INT32_C(1));
    if (((vader_struct_vader_comptime_MonoEntry_t*) ((vader_struct_vader_midir_CFGStructDecl_t*) l0)->f_origin)->f_symbol.tag == 899u) {
        t0 = ((vader_struct_vader_comptime_MonoEntry_t*) ((vader_struct_vader_midir_CFGStructDecl_t*) l0)->f_origin)->f_symbol.payload.obj;
        l2 = ((vader_struct_vader_resolver_symbol_Symbol_t*) t0)->f_id;
    }
    if (((vader_struct_vader_comptime_MonoEntry_t*) ((vader_struct_vader_midir_CFGStructDecl_t*) l0)->f_origin)->f_symbol.tag == 899u) {
        l3 = ((vader_struct_vader_comptime_MonoEntry_t*) ((vader_struct_vader_midir_CFGStructDecl_t*) l0)->f_origin)->f_symbol.payload.obj;
        l4 = ((vader_struct_vader_comptime_MonoEntry_t*) ((vader_struct_vader_midir_CFGStructDecl_t*) l0)->f_origin)->f_type_arguments;
        l5 = vader_types_mk_struct(l3, l4, false);
        l6 = vader_bytecode_type_intern_key(l5);
        l7 = std_collections_MutableMap_Index_at__string__i32(((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_type_key, l6);
        t1 = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_types)->length;
        l8 = ((int32_t) (size_t) t1);
        if (l7.tag == 179u) {
            l3 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_types;
            t2 = ((int32_t) l7.payload.i);
            t3 = ((int64_t) (int32_t) t2);
            l9 = (size_t) (int64_t) t3;
            vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
            if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
            if ((size_t) l9 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
            t4 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l9);
            if (t4.tag == 516u) {
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
            vader_obj_header_init(_a1_obj, 513u);
            _a1_obj->f_trait_name = t5;
            l4 = (void*) _a1_obj;
            vader_array_push((vader_array_t*) l3, vader_ref_box(l4));
        }
        vader_array_t* _a2_arr = vader_array_new(37u, 0u, 13u, 505u);
        l3 = (void*) _a2_arr;
        l4 = ((vader_struct_vader_midir_CFGStructDecl_t*) l0)->f_fields;
        l9 = ((vader_array_t*) l4)->length;
        l11 = (size_t) (int64_t) INT64_C(0);
        {
            loop_100: {
                if ((l11 < l9)) {
                    vader_array_t* _a3_slotarr = ((vader_array_t*) l4);
                    if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                    if ((size_t) l11 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                    l12 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l11);
                    l13 = vader_bytecode_intern_type(((vader_struct_vader_midir_CFGStructField_t*) l12)->f_type, l1);
                    t5 = ((vader_struct_vader_midir_CFGStructField_t*) l12)->f_name;
                    vader_struct_vader_bytecode_BcField_t* _a4_obj = (vader_struct_vader_bytecode_BcField_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcField_t));
                    vader_obj_header_init(_a4_obj, 505u);
                    _a4_obj->f_name = t5;
                    _a4_obj->f_type_index = l13;
                    l14 = (void*) _a4_obj;
                    vader_array_push((vader_array_t*) l3, vader_ref_box(l14));
                    t3 = (l11 + INT64_C(1));
                    l11 = (size_t) (int64_t) t3;
                    goto loop_100;
                }
            }
        }
        l4 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_types;
        t3 = ((int64_t) (int32_t) l8);
        l9 = (size_t) (int64_t) t3;
        l6 = ((vader_struct_vader_midir_CFGStructDecl_t*) l0)->f_mangled;
        l15 = vader_midir_c_struct_of(((vader_struct_vader_midir_CFGStructDecl_t*) l0)->f_origin);
        vader_struct_vader_bytecode_BcStruct_t* _a5_obj = (vader_struct_vader_bytecode_BcStruct_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcStruct_t));
        vader_obj_header_init(_a5_obj, 516u);
        _a5_obj->f_name = l6;
        _a5_obj->f_fields = l3;
        _a5_obj->f_c_name = l15;
        _a5_obj->f_symbol_id = l2;
        l3 = (void*) _a5_obj;
        vader_array_t* _a6_slotarr = ((vader_array_t*) l4);
        if (_a6_slotarr->buf != NULL && _a6_slotarr->buf->header.forward != NULL) { _a6_slotarr->buf = vader_array_buf_forward(_a6_slotarr->buf); }
        if ((size_t) l9 >= _a6_slotarr->length) { vader_trap("array index out of bounds"); }
        vader_array_ref_store(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l9, l3);
        VADER_WRITE_BARRIER(_a6_slotarr->buf);
        { vader_gc_top = gc_frame.prev; return; }
    }
    t1 = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_types)->length;
    l8 = ((int32_t) (size_t) t1);
    l3 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_types;
    t5 = ((vader_struct_vader_midir_CFGStructDecl_t*) l0)->f_mangled;
    vader_struct_vader_bytecode_BcRef_t* _a7_obj = (vader_struct_vader_bytecode_BcRef_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcRef_t));
    vader_obj_header_init(_a7_obj, 513u);
    _a7_obj->f_trait_name = t5;
    l4 = (void*) _a7_obj;
    vader_array_push((vader_array_t*) l3, vader_ref_box(l4));
    vader_array_t* _a8_arr = vader_array_new(37u, 0u, 13u, 505u);
    l3 = (void*) _a8_arr;
    l4 = ((vader_struct_vader_midir_CFGStructDecl_t*) l0)->f_fields;
    l9 = ((vader_array_t*) l4)->length;
    l11 = (size_t) (int64_t) INT64_C(0);
    {
        loop_174: {
            if ((l11 < l9)) {
                vader_array_t* _a9_slotarr = ((vader_array_t*) l4);
                if (_a9_slotarr->buf != NULL && _a9_slotarr->buf->header.forward != NULL) { _a9_slotarr->buf = vader_array_buf_forward(_a9_slotarr->buf); }
                if ((size_t) l11 >= _a9_slotarr->length) { vader_trap("array index out of bounds"); }
                l12 = vader_array_ref_load_obj(_a9_slotarr->buf, _a9_slotarr->offset + (size_t) l11);
                l13 = vader_bytecode_intern_type(((vader_struct_vader_midir_CFGStructField_t*) l12)->f_type, l1);
                t5 = ((vader_struct_vader_midir_CFGStructField_t*) l12)->f_name;
                vader_struct_vader_bytecode_BcField_t* _a10_obj = (vader_struct_vader_bytecode_BcField_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcField_t));
                vader_obj_header_init(_a10_obj, 505u);
                _a10_obj->f_name = t5;
                _a10_obj->f_type_index = l13;
                l14 = (void*) _a10_obj;
                vader_array_push((vader_array_t*) l3, vader_ref_box(l14));
                t3 = (l11 + INT64_C(1));
                l11 = (size_t) (int64_t) t3;
                goto loop_174;
            }
        }
    }
    l4 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_types;
    t3 = ((int64_t) (int32_t) l8);
    l9 = (size_t) (int64_t) t3;
    l6 = ((vader_struct_vader_midir_CFGStructDecl_t*) l0)->f_mangled;
    l15 = vader_midir_c_struct_of(((vader_struct_vader_midir_CFGStructDecl_t*) l0)->f_origin);
    vader_struct_vader_bytecode_BcStruct_t* _a11_obj = (vader_struct_vader_bytecode_BcStruct_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcStruct_t));
    vader_obj_header_init(_a11_obj, 516u);
    _a11_obj->f_name = l6;
    _a11_obj->f_fields = l3;
    _a11_obj->f_c_name = l15;
    _a11_obj->f_symbol_id = l2;
    l3 = (void*) _a11_obj;
    vader_array_t* _a12_slotarr = ((vader_array_t*) l4);
    if (_a12_slotarr->buf != NULL && _a12_slotarr->buf->header.forward != NULL) { _a12_slotarr->buf = vader_array_buf_forward(_a12_slotarr->buf); }
    if ((size_t) l9 >= _a12_slotarr->length) { vader_trap("array index out of bounds"); }
    vader_array_ref_store(_a12_slotarr->buf, _a12_slotarr->offset + (size_t) l9, l3);
    VADER_WRITE_BARRIER(_a12_slotarr->buf);
    l3 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_type_key;
    l6 = ((vader_struct_vader_midir_CFGStructDecl_t*) l0)->f_mangled;
    std_collections_MutableMap_IndexSet_set_at__string__i32(l3, l6, l8);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static vader_box_t vader_midir_resolve_loop_frame(void* l0, vader_box_t l1) {
    void* l2;
    void* l6;
    size_t l3;
    vader_string_t l4;
    int64_t l5;
    size_t t0;
    vader_box_t t1;
    int64_t t2;
    void* t3;
    vader_string_t t4;
    if (l1.tag == 0u) {
        t0 = ((vader_array_t*) ((vader_struct_vader_midir_FnCtx_t*) l0)->f_loop_stack)->length;
        if (t0 == INT64_C(0)) {
            t1 = vader_box_obj(0u, NULL);
            return t1;
        }
        l2 = ((vader_struct_vader_midir_FnCtx_t*) l0)->f_loop_stack;
        t0 = ((vader_array_t*) ((vader_struct_vader_midir_FnCtx_t*) l0)->f_loop_stack)->length;
        t2 = (t0 - INT64_C(1));
        l3 = (size_t) (int64_t) t2;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
        if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
        t3 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
        return vader_ref_box(t3);
    }
    l4 = l1.payload.s;
    t0 = ((vader_array_t*) ((vader_struct_vader_midir_FnCtx_t*) l0)->f_loop_stack)->length;
    l5 = (((int64_t) (size_t) t0) - INT64_C(1));
    {
        loop_34: {
            if ((l5 >= INT64_C(0))) {
                l2 = ((vader_struct_vader_midir_FnCtx_t*) l0)->f_loop_stack;
                t2 = l5;
                l3 = (size_t) (int64_t) t2;
                vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l3 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                l6 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l3);
                if (!(((vader_struct_vader_midir_LoopFrame_t*) l6)->f_label.tag == 0u)) {
                    t4 = ((vader_struct_vader_midir_LoopFrame_t*) l6)->f_label.payload.s;
                    if (t4 == l4) {
                        return vader_ref_box(l6);
                    }
                }
                l5 = (l5 - INT64_C(1));
                goto loop_34;
            }
        }
    }
    t1 = vader_box_obj(0u, NULL);
    return t1;
}

static int32_t vader_midir_resolve_vtable_fn_index(void* l0, void* l1) {
    void* l2 = NULL;
    vader_string_t l3 = 0;
    vader_box_t l4 = vader_box_null();
    int32_t l5;
    int32_t t0;
    vader_box_t* gc_roots[1] = { &l4 };
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_string_t* gc_atom_roots[1] = { &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_function_index_by_mangle;
    l3 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l0)->f_name;
    l4 = std_collections_MutableMap_Index_at__string__i32(l2, l3);
    if (l4.tag == 179u) {
        t0 = ((int32_t) l4.payload.i);
        { int32_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_function_index_by_symbol_id;
    l5 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l0)->f_id;
    l4 = std_collections_MutableMap_Index_at__i32__i32(l2, l5);
    if (l4.tag == 179u) {
        t0 = ((int32_t) l4.payload.i);
        { int32_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { int32_t __vret = -(INT32_C(1)); vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
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
    vader_array_t* _a0_arr = vader_array_new(9u, 0u, 7u, 179u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(6u, 1u, 12u, 174u);
    ((uint8_t*) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = (uint8_t) false;
    l2 = (void*) _a1_arr;
    l3 = ((vader_array_t*) ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_blocks)->length;
    vader_array_t* _a2_arr = vader_array_repeat((vader_array_t*) l2, (size_t) l3);
    l2 = (void*) _a2_arr;
    l4 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_entry;
    vader_midir_walk_rpo(l0, l4, l2, l1);
    vader_array_t* _a3_arr = vader_array_new(9u, 0u, 7u, 179u);
    l2 = (void*) _a3_arr;
    l3 = ((vader_array_t*) l1)->length;
    vader_array_t* _a4_arr = vader_array_repeat((vader_array_t*) l2, (size_t) l3);
    l2 = (void*) _a4_arr;
    l3 = ((vader_array_t*) l1)->length;
    {
        loop_32: {
            if ((l3 > INT64_C(0))) {
                t0 = (l3 - INT64_C(1));
                l3 = (size_t) (int64_t) t0;
                vader_array_t* _a5_slotarr = ((vader_array_t*) l1);
                if (_a5_slotarr->buf != NULL && _a5_slotarr->buf->header.forward != NULL) { _a5_slotarr->buf = vader_array_buf_forward(_a5_slotarr->buf); }
                if ((size_t) l3 >= _a5_slotarr->length) { vader_trap("array index out of bounds"); }
                l4 = ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l3];
                vader_array_push_i32((vader_array_t*) l2, l4);
                goto loop_32;
            }
        }
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
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
    l5 = (size_t) (int64_t) INT64_C(0);
    {
        loop_12: {
            if ((l5 < l4)) {
                vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
                if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                if ((size_t) l5 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                l6 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
                l7 = ((vader_array_t*) ((vader_struct_vader_midir_BasicBlock_t*) l6)->f_instructions)->length;
                l8 = (size_t) (int64_t) INT64_C(0);
                {
                    loop_27: {
                        if ((l8 < l7)) {
                            t0 = (l8 + INT64_C(1));
                            l9 = (size_t) (int64_t) t0;
                            l10 = ((vader_array_t*) ((vader_struct_vader_midir_BasicBlock_t*) l6)->f_instructions)->length;
                            if ((l9 >= l10)) {
                            } else {
                                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_midir_BasicBlock_t*) l6)->f_instructions);
                                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                                if ((size_t) l8 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                                l11 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l8);
                                l12 = ((vader_struct_vader_midir_BasicBlock_t*) l6)->f_instructions;
                                t0 = (l8 + INT64_C(1));
                                l13 = (size_t) (int64_t) t0;
                                vader_array_t* _a2_slotarr = ((vader_array_t*) l12);
                                if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                                if ((size_t) l13 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                                l14 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l13);
                                t1 = vader_midir_can_pass_through_stack(l11, l14, l1);
                                if (!(t1)) {
                                    t0 = (l8 + INT64_C(1));
                                    l8 = (size_t) (int64_t) t0;
                                    goto loop_27;
                                }
                                l15 = ((vader_struct_vader_midir_ScheduleHints_t*) l2)->f_skip_set;
                                l16 = vader_midir_pos_key(((vader_struct_vader_midir_BasicBlock_t*) l6)->f_id, l8);
                                std_collections_add__i64(l15, l16);
                                l17 = ((vader_struct_vader_midir_ScheduleHints_t*) l2)->f_skip_first_get;
                                l18 = ((vader_struct_vader_midir_BasicBlock_t*) l6)->f_id;
                                t0 = (l8 + INT64_C(1));
                                l19 = (size_t) (int64_t) t0;
                                l20 = vader_midir_pos_key(l18, l19);
                                std_collections_add__i64(l17, l20);
                                t0 = (l8 + INT64_C(1));
                                l8 = (size_t) (int64_t) t0;
                                goto loop_27;
                            }
                        }
                    }
                }
                t2 = ((vader_array_t*) ((vader_struct_vader_midir_BasicBlock_t*) l6)->f_instructions)->length;
                if (t2 == INT64_C(0)) {
                    t0 = (l5 + INT64_C(1));
                    l5 = (size_t) (int64_t) t0;
                    goto loop_12;
                }
                t2 = ((vader_array_t*) ((vader_struct_vader_midir_BasicBlock_t*) l6)->f_instructions)->length;
                t0 = (t2 - INT64_C(1));
                l21 = (size_t) (int64_t) t0;
                vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_midir_BasicBlock_t*) l6)->f_instructions);
                if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                if ((size_t) l21 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                l22 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l21);
                l23 = ((vader_struct_vader_midir_BasicBlock_t*) l6)->f_terminator;
                t1 = vader_midir_can_pass_through_terminator(l22, l23, l1);
                if (!(t1)) {
                    t0 = (l5 + INT64_C(1));
                    l5 = (size_t) (int64_t) t0;
                    goto loop_12;
                }
                l24 = ((vader_struct_vader_midir_ScheduleHints_t*) l2)->f_skip_set;
                l25 = vader_midir_pos_key(((vader_struct_vader_midir_BasicBlock_t*) l6)->f_id, l21);
                std_collections_add__i64(l24, l25);
                l26 = ((vader_struct_vader_midir_ScheduleHints_t*) l2)->f_skip_terminator_get;
                l27 = ((vader_struct_vader_midir_BasicBlock_t*) l6)->f_id;
                std_collections_add__i32(l26, l27);
                t0 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t0;
                goto loop_12;
            }
        }
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static bool vader_midir_scope_contains_target(void* l0, int32_t l1) {
    void* l2;
    size_t l3, l4;
    void* t0;
    bool t1;
    int64_t t2;
    l2 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_scopes;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    l3 = ((vader_array_t*) l2)->length;
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_7: {
            if ((l4 < l3)) {
                if ((size_t) l4 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
                t1 = vader_midir_BlockId_Equals_equals(((vader_struct_vader_midir_ScopeFrame_t*) t0)->f_target_blk, l1);
                if (t1) {
                    return true;
                }
                t2 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t2;
                goto loop_7;
            }
        }
    }
    return false;
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
    l3 = (size_t) (int64_t) INT64_C(0);
    {
        loop_24: {
            if ((l3 >= l2)) {
                return true;
            }
            vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
            if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
            if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
            l6 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            t0 = (l3 + INT64_C(1));
            l3 = (size_t) (int64_t) t0;
            t1 = std_collections_MutableSet_Contains_contains__i32(l1, l6);
            if (!(t1)) {
                return false;
            }
            goto loop_24;
        }
    }
    return true;
}

static int32_t vader_midir_struct_symbol_id(vader_box_t l0) {
    void* t0;
    int32_t t1;
    if (l0.tag == 938u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_types_StructType_t*) t0)->f_symbol)->f_id;
        return t1;
    }
    return -(INT32_C(1));
}

static void* vader_midir_successors_of(void* l0) {
    vader_box_t l1 = vader_box_null();
    void* l2 = NULL;
    int32_t l3, l4;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[3] = { &l0, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct_vader_midir_BasicBlock_t*) l0)->f_terminator;
    if (l1.tag == 860u) {
        t0 = l1.payload.obj;
        vader_array_t* _a0_arr = vader_array_new(9u, 1u, 7u, 179u);
        ((int32_t*) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = (int32_t) ((vader_struct_vader_midir_TermBranch_t*) t0)->f_target;
        t0 = (void*) _a0_arr;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 861u) {
        l2 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir_TermCondBranch_t*) l2)->f_then_block;
        l4 = ((vader_struct_vader_midir_TermCondBranch_t*) l2)->f_else_block;
        vader_array_t* _a1_arr = vader_array_new(9u, 2u, 7u, 179u);
        ((int32_t*) _a1_arr->buf->slots)[_a1_arr->offset + 1u] = (int32_t) l4;
        ((int32_t*) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = (int32_t) l3;
        t0 = (void*) _a1_arr;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 862u) {
        vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 179u);
        t0 = (void*) _a2_arr;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 863u) {
        vader_array_t* _a3_arr = vader_array_new(9u, 0u, 7u, 179u);
        t0 = (void*) _a3_arr;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_unreachable("unreachable return in vader_midir$successors_of");
    vader_gc_top = gc_frame.prev;
}

static void vader_midir_synthesise_cfg_intrinsic_wrappers(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l11 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    void* l16 = NULL;
    void* l20 = NULL;
    void* l22 = NULL;
    void* l24 = NULL;
    void* l25 = NULL;
    void* l26 = NULL;
    size_t l5, l6, l15, l17, l18;
    vader_string_t l7 = 0;
    vader_string_t l12 = 0;
    vader_string_t l23 = 0;
    vader_string_t l27 = 0;
    int32_t l8, l9, l10, l19, l21;
    void* t0 = NULL;
    int64_t t1;
    size_t t2;
    bool t3;
    vader_box_t t4 = vader_box_null();
    vader_string_t t5 = 0;
    vader_box_t* gc_roots[1] = { &t4 };
    void** gc_raw_roots[15] = { &l0, &l1, &l2, &l3, &l4, &l11, &l13, &l14, &l16, &l20, &l22, &l24, &l25, &l26, &t0 };
    vader_string_t* gc_atom_roots[5] = { &l7, &l12, &l23, &l27, &t5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 15u, gc_roots, gc_raw_roots, 0u, NULL, 5u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 176u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(6u, 0u, 12u, 174u);
    l3 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 179u);
    l4 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__string__bool_t* _a3_obj = (vader_struct_std_collections_MutableMap__string__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__bool_t));
    vader_obj_header_init(_a3_obj, 364u);
    _a3_obj->f_ekeys = l2;
    _a3_obj->f_evals = l3;
    _a3_obj->f_index = l4;
    _a3_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l2 = (void*) _a3_obj;
    l3 = ((vader_struct_vader_midir_CFGProject_t*) l0)->f_vtable_entries;
    l5 = ((vader_array_t*) l3)->length;
    l6 = (size_t) (int64_t) INT64_C(0);
    {
        loop_21: {
            if ((l6 < l5)) {
                vader_array_t* _a4_slotarr = ((vader_array_t*) l3);
                if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                if ((size_t) l6 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l6);
                l7 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_lower_LoweredVtableEntry_t*) t0)->f_fn_symbol)->f_name;
                std_collections_MutableMap_IndexSet_set_at__string__bool(l2, l7, true);
                t1 = (l6 + INT64_C(1));
                l6 = (size_t) (int64_t) t1;
                goto loop_21;
            }
        }
    }
    t2 = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_imports)->length;
    l8 = ((int32_t) (size_t) t2);
    l9 = INT32_C(0);
    {
        loop_52: {
            if ((l9 < l8)) {
                l3 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_imports;
                t1 = ((int64_t) (int32_t) l9);
                l5 = (size_t) (int64_t) t1;
                vader_array_t* _a5_slotarr = ((vader_array_t*) l3);
                if (_a5_slotarr->buf != NULL && _a5_slotarr->buf->header.forward != NULL) { _a5_slotarr->buf = vader_array_buf_forward(_a5_slotarr->buf); }
                if ((size_t) l5 >= _a5_slotarr->length) { vader_trap("array index out of bounds"); }
                l4 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l5);
                l10 = l9;
                l9 = (l9 + INT32_C(1));
                t3 = ((vader_struct_vader_bytecode_BcImport_t*) l4)->f_is_extern;
                if (t3) {
                    goto loop_52;
                }
                l7 = ((vader_struct_vader_bytecode_BcImport_t*) l4)->f_mangled_name;
                t4 = std_collections_MutableMap_Index_at__string__bool(l2, l7);
                if (t4.tag == 0u) {
                    goto loop_52;
                }
                l11 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_function_index_by_mangle;
                l12 = ((vader_struct_vader_bytecode_BcImport_t*) l4)->f_mangled_name;
                t4 = std_collections_MutableMap_Index_at__string__i32(l11, l12);
                if (t4.tag == 179u) {
                    goto loop_52;
                }
                l13 = vader_bytecode_build_intrinsic_wrapper_body(l4, l10);
                vader_array_t* _a6_arr = vader_array_new(134u, 0u, 13u, 1146u);
                l14 = (void*) _a6_arr;
                l6 = ((vader_array_t*) l13)->length;
                l15 = (size_t) (int64_t) INT64_C(0);
                {
                    loop_111: {
                        if ((l15 < l6)) {
                            vader_array_push((vader_array_t*) l14, vader_box_obj(0u, NULL));
                            t1 = (l15 + INT64_C(1));
                            l15 = (size_t) (int64_t) t1;
                            goto loop_111;
                        }
                    }
                }
                vader_array_t* _a7_arr = vader_array_new(9u, 0u, 7u, 179u);
                l16 = (void*) _a7_arr;
                l17 = ((vader_array_t*) l13)->length;
                l18 = (size_t) (int64_t) INT64_C(0);
                {
                    vader_array_t* _pc135_hdr = (vader_array_t*) l16;
                    size_t _pc135_len = _pc135_hdr->length;
                    size_t _pc135_cap = (_pc135_hdr->offset == 0 && !vader_array_is_borrowed(_pc135_hdr) && _pc135_hdr->length >= _pc135_hdr->buf->length) ? _pc135_hdr->capacity : (size_t) 0;
                    void* _pc135_slots = _pc135_hdr->buf->slots;
                    loop_135: {
                        if ((l18 < l17)) {
                            l19 = -(INT32_C(1));
                            if (VADER_LIKELY(_pc135_len < _pc135_cap)) {
                                ((int32_t*) _pc135_slots)[_pc135_len] = (int32_t) (l19);
                                _pc135_len += 1;
                            } else {
                                _pc135_hdr->length = _pc135_len;
                                if (_pc135_hdr->buf->length < _pc135_len) { _pc135_hdr->buf->length = _pc135_len; }
                                vader_array_push_i32((vader_array_t*) l16, l19);
                                _pc135_hdr = (vader_array_t*) l16;
                                _pc135_len = _pc135_hdr->length;
                                _pc135_cap = (_pc135_hdr->offset == 0 && !vader_array_is_borrowed(_pc135_hdr) && _pc135_hdr->length >= _pc135_hdr->buf->length) ? _pc135_hdr->capacity : (size_t) 0;
                                _pc135_slots = _pc135_hdr->buf->slots;
                            }
                            t1 = (l18 + INT64_C(1));
                            l18 = (size_t) (int64_t) t1;
                            goto loop_135;
                        }
                        _pc135_hdr->length = _pc135_len;
                        if (_pc135_hdr->buf->length < _pc135_len) { _pc135_hdr->buf->length = _pc135_len; }
                    }
                }
                vader_array_t* _a8_arr = vader_array_new(40u, 0u, 13u, 509u);
                l20 = (void*) _a8_arr;
                t2 = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_functions)->length;
                l21 = ((int32_t) (size_t) t2);
                l22 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_functions;
                t5 = ((vader_struct_vader_bytecode_BcImport_t*) l4)->f_mangled_name;
                l23 = concat_2(t5, 972u);
                l24 = ((vader_struct_vader_bytecode_BcImport_t*) l4)->f_signature;
                vader_struct_vader_bytecode_BcFunction_t* _a9_obj = (vader_struct_vader_bytecode_BcFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcFunction_t));
                vader_obj_header_init(_a9_obj, 507u);
                _a9_obj->f_name = l23;
                _a9_obj->f_is_main = false;
                _a9_obj->f_signature = l24;
                _a9_obj->f_locals = l20;
                _a9_obj->f_body = l13;
                _a9_obj->f_debug = l14;
                _a9_obj->f_jump_table = l16;
                l25 = (void*) _a9_obj;
                vader_array_push((vader_array_t*) l22, vader_ref_box(l25));
                l26 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_function_index_by_mangle;
                l27 = ((vader_struct_vader_bytecode_BcImport_t*) l4)->f_mangled_name;
                std_collections_MutableMap_IndexSet_set_at__string__i32(l26, l27, l21);
                goto loop_52;
            }
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static vader_box_t vader_midir_term_return_single(void* l0) {
    size_t t0;
    vader_box_t t1;
    int32_t t2;
    t0 = ((vader_array_t*) ((vader_struct_vader_midir_TermReturn_t*) l0)->f_values)->length;
    if (t0 != INT64_C(1)) {
        t1 = vader_box_obj(0u, NULL);
        return t1;
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_midir_TermReturn_t*) l0)->f_values);
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    if ((size_t) INT32_C(0) >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
    t2 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) INT32_C(0)];
    t1 = vader_box_i32(179u, t2);
    return t1;
}

static void vader_midir_terminate(void* l0, vader_box_t l1) {
    void* l2;
    size_t l3;
    int64_t t0;
    if (((vader_struct_vader_midir_FnCtx_t*) l0)->f_current.tag == 0u) {
        return;
    }
    l2 = ((vader_struct_vader_midir_FnCtx_t*) l0)->f_blocks;
    t0 = ((int64_t) ((vader_struct_vader_midir_FnCtx_t*) l0)->f_current.payload.i);
    l3 = (size_t) (int64_t) t0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
    l2 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
    if (((vader_struct_vader_midir_MutableBlock_t*) l2)->f_terminator.tag == 0u) {
        ((vader_struct_vader_midir_MutableBlock_t*) l2)->f_terminator = l1;
        VADER_WRITE_BARRIER((vader_struct_vader_midir_MutableBlock_t*) l2);
    }
    ((vader_struct_vader_midir_FnCtx_t*) l0)->f_current = vader_box_obj(0u, NULL);
    VADER_WRITE_BARRIER((vader_struct_vader_midir_FnCtx_t*) l0);
    return;
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
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    if ((size_t) l5 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
    l6 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
    if (!(l6.tag == 619u)) {
        { vader_gc_top = gc_frame.prev; return false; }
    }
    t1 = l6.payload.obj;
    l7 = ((vader_struct_vader_bytecode_LocalGet_t*) t1)->f_slot;
    l4 = ((vader_struct_vader_bytecode_BcFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_slot)->f_body;
    t0 = (l3 - INT64_C(1));
    l3 = (size_t) (int64_t) t0;
    vader_struct_vader_bytecode_LocalField_t* _a1_obj = (vader_struct_vader_bytecode_LocalField_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_LocalField_t));
    vader_obj_header_init(_a1_obj, 618u);
    _a1_obj->f_slot = l7;
    _a1_obj->f_type_id = l1;
    _a1_obj->f_field_index = l2;
    l8 = (void*) _a1_obj;
    vader_array_t* _a2_slotarr = ((vader_array_t*) l4);
    if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
    if ((size_t) l3 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
    vader_array_ref_store(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l3, l8);
    VADER_WRITE_BARRIER(_a2_slotarr->buf);
    { vader_gc_top = gc_frame.prev; return true; }
    vader_gc_top = gc_frame.prev;
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
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    if ((size_t) l4 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
    t0 = vader_box_bool(174u, ((uint8_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l4]);
    t1 = t0.payload.b;
    if (t1) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l4 = l1;
    vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
    if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
    if ((size_t) l4 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
    ((uint8_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4] = (uint8_t) true;
    l5 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_blocks;
    l4 = l1;
    vader_array_t* _a2_slotarr = ((vader_array_t*) l5);
    if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
    if ((size_t) l4 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
    t2 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
    l5 = vader_midir_successors_of(t2);
    l6 = ((vader_array_t*) l5)->length;
    l7 = (size_t) (int64_t) INT64_C(0);
    {
        loop_29: {
            if ((l7 < l6)) {
                vader_array_t* _a3_slotarr = ((vader_array_t*) l5);
                if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                if ((size_t) l7 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                l4 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l7];
                vader_midir_walk_rpo(l0, l4, l2, l3);
                t3 = (l7 + INT64_C(1));
                l7 = (size_t) (int64_t) t3;
                goto loop_29;
            }
        }
    }
    vader_array_push_i32((vader_array_t*) l3, l1);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_midir_walk_rpo_reverse(void* l0, int32_t l1, void* l2, void* l3) {
    size_t l4, l6;
    void* l5 = NULL;
    int32_t l7;
    int64_t t0;
    vader_box_t t1 = vader_box_null();
    bool t2;
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[4] = { &l0, &l2, &l3, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((int64_t) (int32_t) l1);
    l4 = (size_t) (int64_t) t0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    if ((size_t) l4 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
    t1 = vader_box_bool(174u, ((uint8_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l4]);
    t2 = t1.payload.b;
    if (t2) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    t0 = ((int64_t) (int32_t) l1);
    l4 = (size_t) (int64_t) t0;
    vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
    if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
    if ((size_t) l4 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
    ((uint8_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4] = (uint8_t) true;
    t0 = ((int64_t) (int32_t) l1);
    l4 = (size_t) (int64_t) t0;
    vader_array_t* _a2_slotarr = ((vader_array_t*) l0);
    if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
    if ((size_t) l4 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
    l5 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
    l4 = ((vader_array_t*) l5)->length;
    l6 = (size_t) (int64_t) INT64_C(0);
    {
        loop_29: {
            if ((l6 < l4)) {
                vader_array_t* _a3_slotarr = ((vader_array_t*) l5);
                if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                if ((size_t) l6 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                l7 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l6];
                vader_midir_walk_rpo_reverse(l0, l7, l2, l3);
                t0 = (l6 + INT64_C(1));
                l6 = (size_t) (int64_t) t0;
                goto loop_29;
            }
        }
    }
    vader_array_push_i32((vader_array_t*) l3, l1);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_midir_with_by_address(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null();
    void* l3 = NULL;
    void* l5 = NULL;
    void* l8 = NULL;
    void* l10 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    void* l15 = NULL;
    bool l4, l9;
    size_t l6, l7, l11, l12;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    int64_t t2;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[10] = { &l0, &l1, &l3, &l5, &l8, &l10, &l13, &l14, &l15, &t0 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 10u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_comptime_MonoEntry_t*) l1)->f_decl;
    if (!(l2.tag == 426u)) {
        { void* __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a0_arr = vader_array_new(6u, 0u, 12u, 174u);
    l3 = (void*) _a0_arr;
    l4 = false;
    t0 = l2.payload.obj;
    l5 = ((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_params;
    l6 = ((vader_array_t*) l5)->length;
    l7 = (size_t) (int64_t) INT64_C(0);
    {
        loop_21: {
            if ((l7 < l6)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l7 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                l8 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l7);
                l9 = false;
                l10 = ((vader_struct_toolchain_ast_FnParam_t*) l8)->f_decorators;
                vader_array_t* _a2_slotarr = ((vader_array_t*) l10);
                if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                l11 = ((vader_array_t*) l10)->length;
                l12 = (size_t) (int64_t) INT64_C(0);
                {
                    loop_39: {
                        if ((l12 < l11)) {
                            if ((size_t) l12 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                            t0 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l12);
                            t1 = ((vader_struct_toolchain_ast_Decorator_t*) t0)->f_name;
                            if (t1 == 1388u) {
                                l9 = true;
                            }
                            t2 = (l12 + INT64_C(1));
                            l12 = (size_t) (int64_t) t2;
                            goto loop_39;
                        }
                    }
                }
                if (l9) {
                    l4 = true;
                }
                vader_array_push_bool((vader_array_t*) l3, l9);
                t2 = (l7 + INT64_C(1));
                l7 = (size_t) (int64_t) t2;
                goto loop_21;
            }
        }
    }
    if (!(l4)) {
        { void* __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l5 = l0;
    l8 = ((vader_struct_vader_bytecode_BcSignature_t*) l5)->f_params;
    l10 = ((vader_struct_vader_bytecode_BcSignature_t*) l5)->f_results;
    l13 = ((vader_struct_vader_bytecode_BcSignature_t*) l5)->f_param_types;
    l14 = ((vader_struct_vader_bytecode_BcSignature_t*) l5)->f_result_types;
    l15 = ((vader_struct_vader_bytecode_BcSignature_t*) l5)->f_param_names;
    l5 = ((vader_struct_vader_bytecode_BcSignature_t*) l5)->f_param_mutable;
    vader_struct_vader_bytecode_BcSignature_t* _a3_obj = (vader_struct_vader_bytecode_BcSignature_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcSignature_t));
    vader_obj_header_init(_a3_obj, 514u);
    _a3_obj->f_params = l8;
    _a3_obj->f_results = l10;
    _a3_obj->f_param_types = l13;
    _a3_obj->f_result_types = l14;
    _a3_obj->f_param_names = l15;
    _a3_obj->f_param_mutable = l5;
    _a3_obj->f_param_by_address = l3;
    t0 = (void*) _a3_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_box_t vader_midir_with_dst(vader_box_t l0, int32_t l1) {
    void* l2 = NULL;
    void* l11 = NULL;
    vader_box_t l3 = vader_box_null(), l4 = vader_box_null();
    int32_t l5, l7, l10;
    uint8_t l6;
    vader_string_t l8 = 0;
    bool l9;
    void* t0 = NULL;
    vader_box_t* gc_roots[3] = { &l0, &l3, &l4 };
    void** gc_raw_roots[3] = { &l2, &l11, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l8 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    if (l0.tag == 836u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_midir_InstrConst_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrConst_t*) t0)->f_value;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrConst_t*) t0)->f_type;
        vader_struct_vader_midir_InstrConst_t* _a0_obj = (vader_struct_vader_midir_InstrConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrConst_t));
        vader_obj_header_init(_a0_obj, 836u);
        _a0_obj->f_span = l2;
        _a0_obj->f_dst = l1;
        _a0_obj->f_value = l3;
        _a0_obj->f_type = l4;
        t0 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 846u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_midir_InstrMove_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l5 = ((vader_struct_vader_midir_InstrMove_t*) t0)->f_src;
        vader_struct_vader_midir_InstrMove_t* _a1_obj = (vader_struct_vader_midir_InstrMove_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrMove_t));
        vader_obj_header_init(_a1_obj, 846u);
        _a1_obj->f_span = l2;
        _a1_obj->f_dst = l1;
        _a1_obj->f_src = l5;
        t0 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 829u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_midir_InstrBinOp_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l6 = ((vader_struct_vader_midir_InstrBinOp_t*) t0)->f_op;
        t0 = l0.payload.obj;
        l5 = ((vader_struct_vader_midir_InstrBinOp_t*) t0)->f_lhs;
        t0 = l0.payload.obj;
        l7 = ((vader_struct_vader_midir_InstrBinOp_t*) t0)->f_rhs;
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrBinOp_t*) t0)->f_type;
        vader_struct_vader_midir_InstrBinOp_t* _a2_obj = (vader_struct_vader_midir_InstrBinOp_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrBinOp_t));
        vader_obj_header_init(_a2_obj, 829u);
        _a2_obj->f_span = l2;
        _a2_obj->f_dst = l1;
        _a2_obj->f_op = l6;
        _a2_obj->f_lhs = l5;
        _a2_obj->f_rhs = l7;
        _a2_obj->f_type = l3;
        t0 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 851u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_midir_InstrUnOp_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l6 = ((vader_struct_vader_midir_InstrUnOp_t*) t0)->f_op;
        t0 = l0.payload.obj;
        l5 = ((vader_struct_vader_midir_InstrUnOp_t*) t0)->f_operand;
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrUnOp_t*) t0)->f_type;
        vader_struct_vader_midir_InstrUnOp_t* _a3_obj = (vader_struct_vader_midir_InstrUnOp_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrUnOp_t));
        vader_obj_header_init(_a3_obj, 851u);
        _a3_obj->f_span = l2;
        _a3_obj->f_dst = l1;
        _a3_obj->f_op = l6;
        _a3_obj->f_operand = l5;
        _a3_obj->f_type = l3;
        t0 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 840u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_midir_InstrFieldGet_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l5 = ((vader_struct_vader_midir_InstrFieldGet_t*) t0)->f_target;
        t0 = l0.payload.obj;
        l8 = ((vader_struct_vader_midir_InstrFieldGet_t*) t0)->f_field;
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrFieldGet_t*) t0)->f_type;
        vader_struct_vader_midir_InstrFieldGet_t* _a4_obj = (vader_struct_vader_midir_InstrFieldGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrFieldGet_t));
        vader_obj_header_init(_a4_obj, 840u);
        _a4_obj->f_span = l2;
        _a4_obj->f_dst = l1;
        _a4_obj->f_target = l5;
        _a4_obj->f_field = l8;
        _a4_obj->f_type = l3;
        t0 = (void*) _a4_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 823u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_midir_InstrArrayGet_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l5 = ((vader_struct_vader_midir_InstrArrayGet_t*) t0)->f_target;
        t0 = l0.payload.obj;
        l7 = ((vader_struct_vader_midir_InstrArrayGet_t*) t0)->f_index;
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrArrayGet_t*) t0)->f_type;
        t0 = l0.payload.obj;
        l9 = ((vader_struct_vader_midir_InstrArrayGet_t*) t0)->f_bounds_safe;
        vader_struct_vader_midir_InstrArrayGet_t* _a5_obj = (vader_struct_vader_midir_InstrArrayGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrArrayGet_t));
        vader_obj_header_init(_a5_obj, 823u);
        _a5_obj->f_span = l2;
        _a5_obj->f_dst = l1;
        _a5_obj->f_target = l5;
        _a5_obj->f_index = l7;
        _a5_obj->f_type = l3;
        _a5_obj->f_bounds_safe = l9;
        t0 = (void*) _a5_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 824u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_midir_InstrArrayLen_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l5 = ((vader_struct_vader_midir_InstrArrayLen_t*) t0)->f_target;
        t0 = l0.payload.obj;
        l9 = ((vader_struct_vader_midir_InstrArrayLen_t*) t0)->f_resolve_buf;
        vader_struct_vader_midir_InstrArrayLen_t* _a6_obj = (vader_struct_vader_midir_InstrArrayLen_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrArrayLen_t));
        vader_obj_header_init(_a6_obj, 824u);
        _a6_obj->f_span = l2;
        _a6_obj->f_dst = l1;
        _a6_obj->f_target = l5;
        _a6_obj->f_resolve_buf = l9;
        t0 = (void*) _a6_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 828u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_midir_InstrArraySlice_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrArraySlice_t*) t0)->f_type;
        t0 = l0.payload.obj;
        l5 = ((vader_struct_vader_midir_InstrArraySlice_t*) t0)->f_target;
        t0 = l0.payload.obj;
        l7 = ((vader_struct_vader_midir_InstrArraySlice_t*) t0)->f_lo;
        t0 = l0.payload.obj;
        l10 = ((vader_struct_vader_midir_InstrArraySlice_t*) t0)->f_hi;
        vader_struct_vader_midir_InstrArraySlice_t* _a7_obj = (vader_struct_vader_midir_InstrArraySlice_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrArraySlice_t));
        vader_obj_header_init(_a7_obj, 828u);
        _a7_obj->f_span = l2;
        _a7_obj->f_dst = l1;
        _a7_obj->f_type = l3;
        _a7_obj->f_target = l5;
        _a7_obj->f_lo = l7;
        _a7_obj->f_hi = l10;
        t0 = (void*) _a7_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 847u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_midir_InstrStringSlice_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrStringSlice_t*) t0)->f_type;
        t0 = l0.payload.obj;
        l5 = ((vader_struct_vader_midir_InstrStringSlice_t*) t0)->f_target;
        t0 = l0.payload.obj;
        l7 = ((vader_struct_vader_midir_InstrStringSlice_t*) t0)->f_lo;
        t0 = l0.payload.obj;
        l10 = ((vader_struct_vader_midir_InstrStringSlice_t*) t0)->f_hi;
        vader_struct_vader_midir_InstrStringSlice_t* _a8_obj = (vader_struct_vader_midir_InstrStringSlice_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrStringSlice_t));
        vader_obj_header_init(_a8_obj, 847u);
        _a8_obj->f_span = l2;
        _a8_obj->f_dst = l1;
        _a8_obj->f_type = l3;
        _a8_obj->f_target = l5;
        _a8_obj->f_lo = l7;
        _a8_obj->f_hi = l10;
        t0 = (void*) _a8_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 848u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_midir_InstrStructNew_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrStructNew_t*) t0)->f_type;
        t0 = l0.payload.obj;
        l11 = ((vader_struct_vader_midir_InstrStructNew_t*) t0)->f_fields;
        t0 = l0.payload.obj;
        l9 = ((vader_struct_vader_midir_InstrStructNew_t*) t0)->f_stack;
        vader_struct_vader_midir_InstrStructNew_t* _a9_obj = (vader_struct_vader_midir_InstrStructNew_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrStructNew_t));
        vader_obj_header_init(_a9_obj, 848u);
        _a9_obj->f_span = l2;
        _a9_obj->f_dst = l1;
        _a9_obj->f_type = l3;
        _a9_obj->f_fields = l11;
        _a9_obj->f_stack = l9;
        t0 = (void*) _a9_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 825u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_midir_InstrArrayNew_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrArrayNew_t*) t0)->f_type;
        t0 = l0.payload.obj;
        l5 = ((vader_struct_vader_midir_InstrArrayNew_t*) t0)->f_length;
        t0 = l0.payload.obj;
        l11 = ((vader_struct_vader_midir_InstrArrayNew_t*) t0)->f_elements;
        t0 = l0.payload.obj;
        l9 = ((vader_struct_vader_midir_InstrArrayNew_t*) t0)->f_stack;
        vader_struct_vader_midir_InstrArrayNew_t* _a10_obj = (vader_struct_vader_midir_InstrArrayNew_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrArrayNew_t));
        vader_obj_header_init(_a10_obj, 825u);
        _a10_obj->f_span = l2;
        _a10_obj->f_dst = l1;
        _a10_obj->f_type = l3;
        _a10_obj->f_length = l5;
        _a10_obj->f_elements = l11;
        _a10_obj->f_stack = l9;
        t0 = (void*) _a10_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 837u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_midir_InstrDataConst_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrDataConst_t*) t0)->f_type;
        t0 = l0.payload.obj;
        l5 = ((vader_struct_vader_midir_InstrDataConst_t*) t0)->f_pool_index;
        vader_struct_vader_midir_InstrDataConst_t* _a11_obj = (vader_struct_vader_midir_InstrDataConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrDataConst_t));
        vader_obj_header_init(_a11_obj, 837u);
        _a11_obj->f_span = l2;
        _a11_obj->f_dst = l1;
        _a11_obj->f_type = l3;
        _a11_obj->f_pool_index = l5;
        t0 = (void*) _a11_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 849u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_midir_InstrTypeCheck_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l5 = ((vader_struct_vader_midir_InstrTypeCheck_t*) t0)->f_value;
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrTypeCheck_t*) t0)->f_check_type;
        vader_struct_vader_midir_InstrTypeCheck_t* _a12_obj = (vader_struct_vader_midir_InstrTypeCheck_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrTypeCheck_t));
        vader_obj_header_init(_a12_obj, 849u);
        _a12_obj->f_span = l2;
        _a12_obj->f_dst = l1;
        _a12_obj->f_value = l5;
        _a12_obj->f_check_type = l3;
        t0 = (void*) _a12_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 850u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_midir_InstrTypeConst_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrTypeConst_t*) t0)->f_type;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrTypeConst_t*) t0)->f_value_type;
        vader_struct_vader_midir_InstrTypeConst_t* _a13_obj = (vader_struct_vader_midir_InstrTypeConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrTypeConst_t));
        vader_obj_header_init(_a13_obj, 850u);
        _a13_obj->f_span = l2;
        _a13_obj->f_dst = l1;
        _a13_obj->f_type = l3;
        _a13_obj->f_value_type = l4;
        t0 = (void*) _a13_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 832u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_midir_InstrCast_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l5 = ((vader_struct_vader_midir_InstrCast_t*) t0)->f_value;
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrCast_t*) t0)->f_type;
        vader_struct_vader_midir_InstrCast_t* _a14_obj = (vader_struct_vader_midir_InstrCast_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrCast_t));
        vader_obj_header_init(_a14_obj, 832u);
        _a14_obj->f_span = l2;
        _a14_obj->f_dst = l1;
        _a14_obj->f_value = l5;
        _a14_obj->f_type = l3;
        t0 = (void*) _a14_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 834u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_midir_InstrCellNew_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l5 = ((vader_struct_vader_midir_InstrCellNew_t*) t0)->f_value;
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrCellNew_t*) t0)->f_value_type;
        vader_struct_vader_midir_InstrCellNew_t* _a15_obj = (vader_struct_vader_midir_InstrCellNew_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrCellNew_t));
        vader_obj_header_init(_a15_obj, 834u);
        _a15_obj->f_span = l2;
        _a15_obj->f_dst = l1;
        _a15_obj->f_value = l5;
        _a15_obj->f_value_type = l3;
        t0 = (void*) _a15_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 833u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_midir_InstrCellGet_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l5 = ((vader_struct_vader_midir_InstrCellGet_t*) t0)->f_cell;
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrCellGet_t*) t0)->f_value_type;
        vader_struct_vader_midir_InstrCellGet_t* _a16_obj = (vader_struct_vader_midir_InstrCellGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrCellGet_t));
        vader_obj_header_init(_a16_obj, 833u);
        _a16_obj->f_span = l2;
        _a16_obj->f_dst = l1;
        _a16_obj->f_cell = l5;
        _a16_obj->f_value_type = l3;
        t0 = (void*) _a16_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 845u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_midir_InstrMakeClosure_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l11 = ((vader_struct_vader_midir_InstrMakeClosure_t*) t0)->f_fn_symbol;
        t0 = l0.payload.obj;
        l5 = ((vader_struct_vader_midir_InstrMakeClosure_t*) t0)->f_env;
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrMakeClosure_t*) t0)->f_env_type;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrMakeClosure_t*) t0)->f_type;
        vader_struct_vader_midir_InstrMakeClosure_t* _a17_obj = (vader_struct_vader_midir_InstrMakeClosure_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrMakeClosure_t));
        vader_obj_header_init(_a17_obj, 845u);
        _a17_obj->f_span = l2;
        _a17_obj->f_dst = l1;
        _a17_obj->f_fn_symbol = l11;
        _a17_obj->f_env = l5;
        _a17_obj->f_env_type = l3;
        _a17_obj->f_type = l4;
        t0 = (void*) _a17_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 843u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_midir_InstrFnRef_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l11 = ((vader_struct_vader_midir_InstrFnRef_t*) t0)->f_fn_symbol;
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrFnRef_t*) t0)->f_type;
        vader_struct_vader_midir_InstrFnRef_t* _a18_obj = (vader_struct_vader_midir_InstrFnRef_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrFnRef_t));
        vader_obj_header_init(_a18_obj, 843u);
        _a18_obj->f_span = l2;
        _a18_obj->f_dst = l1;
        _a18_obj->f_fn_symbol = l11;
        _a18_obj->f_type = l3;
        t0 = (void*) _a18_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 842u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_midir_InstrFnAddr_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l11 = ((vader_struct_vader_midir_InstrFnAddr_t*) t0)->f_fn_symbol;
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrFnAddr_t*) t0)->f_type;
        vader_struct_vader_midir_InstrFnAddr_t* _a19_obj = (vader_struct_vader_midir_InstrFnAddr_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrFnAddr_t));
        vader_obj_header_init(_a19_obj, 842u);
        _a19_obj->f_span = l2;
        _a19_obj->f_dst = l1;
        _a19_obj->f_fn_symbol = l11;
        _a19_obj->f_type = l3;
        t0 = (void*) _a19_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_box_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_midir_with_peephole_out(void* l0, void* l1) {
    vader_string_t l2 = 0;
    bool l3;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[8] = { &l0, &l1, &l4, &l5, &l6, &l7, &l8, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 8u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_name;
    l3 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_is_main;
    l4 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_signature;
    l5 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_locals;
    l6 = ((vader_struct_vader_bytecode_BcPeepholeOut_t*) l1)->f_body;
    l7 = ((vader_struct_vader_bytecode_BcPeepholeOut_t*) l1)->f_debug;
    l8 = ((vader_struct_vader_bytecode_BcPeepholeOut_t*) l1)->f_jump_table;
    vader_struct_vader_bytecode_BcFunction_t* _a0_obj = (vader_struct_vader_bytecode_BcFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcFunction_t));
    vader_obj_header_init(_a0_obj, 507u);
    _a0_obj->f_name = l2;
    _a0_obj->f_is_main = l3;
    _a0_obj->f_signature = l4;
    _a0_obj->f_locals = l5;
    _a0_obj->f_body = l6;
    _a0_obj->f_debug = l7;
    _a0_obj->f_jump_table = l8;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

