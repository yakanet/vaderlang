#include "bootstrap.split.h"

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
static void* vader_midir_build_cfg_signature(void* l0, vader_box_t l1, void* l2);
static vader_box_t vader_midir_build_data_const(void* l0, void* l1);
static vader_box_t vader_midir_build_expr(void* l0, vader_box_t l1);
static void vader_midir_build_expr_into(void* l0, vader_box_t l1, int32_t l2);
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
static bool vader_midir_can_pass_through_stack(vader_box_t l0, vader_box_t l1, void* l2);
static bool vader_midir_can_pass_through_terminator(vader_box_t l0, vader_box_t l1, void* l2);
static void vader_midir_cf_block(void* l0, void* l1, int32_t l2);
static void vader_midir_cf_br(void* l0, void* l1, int32_t l2);
static void vader_midir_cf_else(void* l0, void* l1);
static void vader_midir_cf_end(void* l0, void* l1);
static void vader_midir_cf_if(void* l0, void* l1, int32_t l2);
static void vader_midir_cf_loop(void* l0, void* l1, int32_t l2);
static bool vader_midir_changed_blocks(void* l0, void* l1);
static vader_box_t vader_midir_closure_header_type(vader_box_t l0);
static void* vader_midir_compact_locals(void* l0);
static void* vader_midir_compute_carried_across_loop_headers(void* l0, void* l1);
static void* vader_midir_compute_dominators(void* l0, void* l1);
static void* vader_midir_compute_escaping(void* l0, void* l1);
static void* vader_midir_compute_liveness(void* l0);
static void* vader_midir_compute_post_dominators(void* l0);
static int32_t vader_midir_cond_branch_merge(void* l0, int32_t l1, int32_t l2);
static void* vader_midir_convert_data_pool(void* l0);
static bool vader_midir_convert_eligible(uint8_t l0);
static vader_box_t vader_midir_convert_function(void* l0, void* l1);
static void* vader_midir_count_uses(void* l0);
static vader_box_t vader_midir_debug_pos_of_span(void* l0);
static int32_t vader_midir_declare_local(void* l0, vader_string_t l1, vader_box_t l2, vader_box_t l3);
static bool vader_midir_decorators_have(void* l0, vader_string_t l1);
static void vader_midir_defer_or_resolve_branch(void* l0, int32_t l1, int32_t l2);
static void* vader_midir_die_once(void* l0);
static bool vader_midir_dominates(void* l0, int32_t l1, int32_t l2);
static void vader_midir_drain_pending(void* l0, int32_t l1, bool l2, int32_t l3, int32_t l4);
static vader_box_t vader_midir_dst_of(vader_box_t l0);
static void vader_midir_emit(void* l0, vader_box_t l1);
static int32_t vader_midir_emit_block_contents(void* l0, int32_t l1, int32_t l2);
static void vader_midir_emit_cfg_function_body(void* l0, int32_t l1, void* l2, void* l3, bool l4);
static int32_t vader_midir_emit_const(void* l0, vader_box_t l1, vader_box_t l2, void* l3);
static void vader_midir_emit_const_instr(void* l0, void* l1, int64_t l2);
static void vader_midir_emit_first_get(void* l0, int64_t l1, int32_t l2, void* l3);
static void vader_midir_emit_get(void* l0, int32_t l1, void* l2);
static void vader_midir_emit_instr(void* l0, vader_box_t l1, int64_t l2);
static void vader_midir_emit_range(void* l0, int32_t l1, int32_t l2);
static void vader_midir_emit_result(void* l0, int64_t l1, int32_t l2, void* l3);
static void vader_midir_emit_result_if_any(void* l0, int64_t l1, vader_box_t l2, void* l3);
static void vader_midir_emit_set(void* l0, int32_t l1, void* l2);
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
static bool vader_midir_is_short_circuit_op(uint8_t l0);
static bool vader_midir_loop_exit_present(void* l0, int32_t l1);
static vader_box_t vader_midir_lowered_to_bc_value(vader_box_t l0);
static void* vader_midir_make_extern_decl(void* l0);
static void* vader_midir_make_struct_decl(void* l0);
static void* vader_midir_natural_loop_bodies(void* l0, void* l1, void* l2);
static bool vader_midir_needs_ref_cast(vader_box_t l0);
static int32_t vader_midir_new_block(void* l0, void* l1);
static void* vader_midir_new_project_ctx(void* l0);
static void* vader_midir_no_hints(void);
static void* vader_midir_optimise_function(void* l0);
static int64_t vader_midir_pos_key(int32_t l0, size_t l1);
static void* vader_midir_predecessors_of(void* l0);
static void* vader_midir_prune_block(void* l0, void* l1, size_t l2);
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
static void vader_midir_terminate(void* l0, vader_box_t l1);
static bool vader_midir_try_fuse_local_field(void* l0, int32_t l1, int32_t l2);
static void vader_midir_walk_rpo(void* l0, int32_t l1, void* l2, void* l3);
static void vader_midir_walk_rpo_reverse(void* l0, int32_t l1, void* l2, void* l3);
static vader_box_t vader_midir_with_dst(vader_box_t l0, int32_t l1);
static void* vader_midir_with_peephole_out(void* l0, void* l1);

void* vader_midir_annotate_escape(void* l0) {
    int32_t l1, l2;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    void* l12 = NULL;
    void* l15 = NULL;
    void* l16 = NULL;
    void* l19 = NULL;
    void* l23 = NULL;
    void* l24 = NULL;
    void* l28 = NULL;
    void* l29 = NULL;
    void* l30 = NULL;
    size_t l7, l8, l13, l14, l17, l18, l20, l21;
    vader_string_t l9, l25, l26, l27;
    vader_box_t l22 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    int64_t t2;
    bool t3;
    vader_box_t* gc_roots[2] = { &l22, &t0 };
    void** gc_raw_roots[17] = { &l0, &l3, &l4, &l5, &l6, &l10, &l11, &l12, &l15, &l16, &l19, &l23, &l24, &l28, &l29, &l30, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 17u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = INT32_C(0);
    l2 = INT32_C(0);
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 161u);
    l3 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(15u, 0u, 0u, 170u);
    l4 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 163u);
    l5 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__string__Any_t* _a3_obj = (vader_struct_std_collections_MutableMap__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__Any_t));
    vader_obj_header_init(_a3_obj, 321u);
    _a3_obj->f_ekeys = l3;
    _a3_obj->f_evals = l4;
    _a3_obj->f_index = l5;
    _a3_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l3 = (void*) _a3_obj;
    l4 = ((vader_struct_vader_midir_CFGProject_t*) l0)->f_modules;
    l5 = ((vader_struct_std_collections_MutableMap__string__CFGModule_t*) l4)->f_ekeys;
    l6 = ((vader_struct_std_collections_MutableMap__string__CFGModule_t*) l4)->f_evals;
    l7 = ((vader_struct_std_collections_MutableMap__string__CFGModule_t*) l4)->f_size;
    l8 = (size_t) (int64_t) INT64_C(0);
    {
        loop_30: {
            if ((l8 >= l7)) {
            } else {
                vader_array_t* _a4_slotarr = ((vader_array_t*) l5);
                if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                if ((size_t) l8 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_box_slots(_a4_slotarr->buf)[_a4_slotarr->offset + (size_t) l8];
                l9 = t0.payload.s;
                vader_array_t* _a5_slotarr = ((vader_array_t*) l6);
                if (_a5_slotarr->buf != NULL && _a5_slotarr->buf->header.forward != NULL) { _a5_slotarr->buf = vader_array_buf_forward(_a5_slotarr->buf); }
                if ((size_t) l8 >= _a5_slotarr->length) { vader_trap("array index out of bounds"); }
                l4 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l8);
                vader_struct___Tuple_1276_t* _a6_obj = (vader_struct___Tuple_1276_t*) vader_gc_alloc(sizeof(vader_struct___Tuple_1276_t));
                vader_obj_header_init(_a6_obj, 217u);
                _a6_obj->f__0 = l9;
                _a6_obj->f__1 = l4;
                t1 = (void*) _a6_obj;
                l10 = ((vader_struct___Tuple_1276_t*) t1)->f__1;
                t2 = (l8 + INT64_C(1));
                l8 = (size_t) (int64_t) t2;
                vader_array_t* _a7_arr = vader_array_new(69u, 0u, 13u, 800u);
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
                            t1 = vader_array_ref_load_obj(_a8_slotarr->buf, _a8_slotarr->offset + (size_t) l14);
                            l15 = vader_midir_annotate_function(t1);
                            l16 = ((vader_struct_vader_midir_CFGFunction_t*) l15)->f_blocks;
                            vader_array_t* _a9_slotarr = ((vader_array_t*) l16);
                            if (_a9_slotarr->buf != NULL && _a9_slotarr->buf->header.forward != NULL) { _a9_slotarr->buf = vader_array_buf_forward(_a9_slotarr->buf); }
                            l17 = ((vader_array_t*) l16)->length;
                            l18 = (size_t) (int64_t) INT64_C(0);
                            {
                                loop_80: {
                                    if ((l18 < l17)) {
                                        if ((size_t) l18 >= _a9_slotarr->length) { vader_trap("array index out of bounds"); }
                                        t1 = vader_array_ref_load_obj(_a9_slotarr->buf, _a9_slotarr->offset + (size_t) l18);
                                        l19 = ((vader_struct_vader_midir_BasicBlock_t*) t1)->f_instructions;
                                        vader_array_t* _a10_slotarr = ((vader_array_t*) l19);
                                        if (_a10_slotarr->buf != NULL && _a10_slotarr->buf->header.forward != NULL) { _a10_slotarr->buf = vader_array_buf_forward(_a10_slotarr->buf); }
                                        l20 = ((vader_array_t*) l19)->length;
                                        l21 = (size_t) (int64_t) INT64_C(0);
                                        {
                                            loop_95: {
                                                if ((l21 < l20)) {
                                                    if ((size_t) l21 >= _a10_slotarr->length) { vader_trap("array index out of bounds"); }
                                                    l22 = vader_array_ref_load_box(_a10_slotarr->buf, _a10_slotarr->offset + (size_t) l21);
                                                    if (l22.tag == 842u) {
                                                        l23 = l22.payload.obj;
                                                        l1 = (l1 + INT32_C(1));
                                                        t3 = ((vader_struct_vader_midir_InstrStructNew_t*) l23)->f_stack;
                                                        if (t3) {
                                                            l2 = (l2 + INT32_C(1));
                                                        } else {
                                                        }
                                                    } else {
                                                        if (l22.tag == 820u) {
                                                            l24 = l22.payload.obj;
                                                            l1 = (l1 + INT32_C(1));
                                                            t3 = ((vader_struct_vader_midir_InstrArrayNew_t*) l24)->f_stack;
                                                            if (t3) {
                                                                l2 = (l2 + INT32_C(1));
                                                            } else {
                                                            }
                                                        } else {
                                                        }
                                                    }
                                                    t2 = (l21 + INT64_C(1));
                                                    l21 = (size_t) (int64_t) t2;
                                                    goto loop_95;
                                                } else {
                                                }
                                            }
                                        }
                                        t2 = (l18 + INT64_C(1));
                                        l18 = (size_t) (int64_t) t2;
                                        goto loop_80;
                                    } else {
                                    }
                                }
                            }
                            vader_array_push((vader_array_t*) l11, vader_ref_box(l15));
                            t2 = (l14 + INT64_C(1));
                            l14 = (size_t) (int64_t) t2;
                            goto loop_63;
                        } else {
                        }
                    }
                }
                l25 = ((vader_struct_vader_midir_CFGModule_t*) l10)->f_module_id;
                l26 = ((vader_struct_vader_midir_CFGModule_t*) l10)->f_module_id;
                l27 = ((vader_struct_vader_midir_CFGModule_t*) l10)->f_display_path;
                l28 = ((vader_struct_vader_midir_CFGModule_t*) l10)->f_externs;
                l29 = ((vader_struct_vader_midir_CFGModule_t*) l10)->f_struct_decls;
                vader_struct_vader_midir_CFGModule_t* _a11_obj = (vader_struct_vader_midir_CFGModule_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_CFGModule_t));
                vader_obj_header_init(_a11_obj, 802u);
                _a11_obj->f_module_id = l26;
                _a11_obj->f_display_path = l27;
                _a11_obj->f_functions = l11;
                _a11_obj->f_externs = l28;
                _a11_obj->f_struct_decls = l29;
                l30 = (void*) _a11_obj;
                std_collections_put__string__Any(l3, l25, vader_ref_box(l30));
                goto loop_30;
            }
        }
    }
    l4 = l0;
    l5 = ((vader_struct_vader_midir_CFGProject_t*) l4)->f_vtable_entries;
    l6 = ((vader_struct_vader_midir_CFGProject_t*) l4)->f_strings;
    l10 = ((vader_struct_vader_midir_CFGProject_t*) l4)->f_data_pool;
    l4 = ((vader_struct_vader_midir_CFGProject_t*) l4)->f_trait_membership;
    vader_struct_vader_midir_CFGProject_t* _a12_obj = (vader_struct_vader_midir_CFGProject_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_CFGProject_t));
    vader_obj_header_init(_a12_obj, 804u);
    _a12_obj->f_modules = l3;
    _a12_obj->f_vtable_entries = l5;
    _a12_obj->f_strings = l6;
    _a12_obj->f_data_pool = l10;
    _a12_obj->f_trait_membership = l4;
    l3 = (void*) _a12_obj;
    vader_struct_vader_midir_EscapeStats_t* _a13_obj = (vader_struct_vader_midir_EscapeStats_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_EscapeStats_t));
    vader_obj_header_init(_a13_obj, 814u);
    _a13_obj->f_total_allocs = l1;
    _a13_obj->f_stack_promoted = l2;
    l4 = (void*) _a13_obj;
    vader_struct_vader_midir_AnnotatedProject_t* _a14_obj = (vader_struct_vader_midir_AnnotatedProject_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_AnnotatedProject_t));
    vader_obj_header_init(_a14_obj, 797u);
    _a14_obj->f_project = l3;
    _a14_obj->f_stats = l4;
    t1 = (void*) _a14_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_midir_annotate_function(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l6 = NULL;
    void* l10 = NULL;
    void* l14 = NULL;
    void* l15 = NULL;
    void* l21 = NULL;
    void* l22 = NULL;
    void* l23 = NULL;
    void* l24 = NULL;
    void* l26 = NULL;
    void* l27 = NULL;
    void* l29 = NULL;
    void* l31 = NULL;
    void* l32 = NULL;
    void* l33 = NULL;
    void* l34 = NULL;
    void* l37 = NULL;
    void* l39 = NULL;
    void* l42 = NULL;
    void* l46 = NULL;
    void* l47 = NULL;
    void* l48 = NULL;
    void* l49 = NULL;
    void* l53 = NULL;
    void* l57 = NULL;
    void* l61 = NULL;
    void* l62 = NULL;
    size_t l4, l5, l7, l8, l18, l19;
    vader_box_t l9 = vader_box_null(), l16 = vader_box_null(), l44 = vader_box_null(), l58 = vader_box_null(), l60 = vader_box_null();
    int32_t l11, l12, l13, l30, l35, l38, l40, l43, l45, l50, l54, l56, l59;
    bool l17, l20, l25, l28, l36, l41, l51, l52;
    vader_string_t l55, l63;
    void* t0 = NULL;
    int64_t t1;
    size_t t2;
    bool t3;
    vader_box_t* gc_roots[5] = { &l9, &l16, &l44, &l58, &l60 };
    void** gc_raw_roots[31] = { &l0, &l1, &l2, &l3, &l6, &l10, &l14, &l15, &l21, &l22, &l23, &l24, &l26, &l27, &l29, &l31, &l32, &l33, &l34, &l37, &l39, &l42, &l46, &l47, &l48, &l49, &l53, &l57, &l61, &l62, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 5u, 31u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(9u, 0u, 7u, 163u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(6u, 0u, 12u, 159u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 163u);
    l3 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__i32__bool_t* _a3_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
    vader_obj_header_init(_a3_obj, 310u);
    _a3_obj->f_ekeys = l1;
    _a3_obj->f_evals = l2;
    _a3_obj->f_index = l3;
    _a3_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    t0 = (void*) _a3_obj;
    vader_struct_std_collections_MutableSet__i32_t* _a4_obj = (vader_struct_std_collections_MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i32_t));
    vader_obj_header_init(_a4_obj, 387u);
    _a4_obj->f_inner = t0;
    l1 = (void*) _a4_obj;
    vader_array_t* _a5_arr = vader_array_new(9u, 0u, 7u, 163u);
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
                            if (l9.tag == 842u) {
                                l10 = l9.payload.obj;
                                l11 = ((vader_struct_vader_midir_InstrStructNew_t*) l10)->f_dst;
                                std_collections_add__i32(l1, l11);
                                l12 = ((vader_struct_vader_midir_InstrStructNew_t*) l10)->f_dst;
                                vader_array_push_i32((vader_array_t*) l2, l12);
                            } else {
                                if (l9.tag == 820u) {
                                    t0 = l9.payload.obj;
                                    l13 = ((vader_struct_vader_midir_InstrArrayNew_t*) t0)->f_dst;
                                    std_collections_add__i32(l1, l13);
                                } else {
                                }
                            }
                            t1 = (l8 + INT64_C(1));
                            l8 = (size_t) (int64_t) t1;
                            goto loop_39;
                        } else {
                        }
                    }
                }
                t1 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t1;
                goto loop_24;
            } else {
            }
        }
    }
    t2 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) ((vader_struct_std_collections_MutableSet__i32_t*) l1)->f_inner)->f_size;
    if (t2 == INT64_C(0)) {
        { void* __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = vader_midir_compute_escaping(l0, l1);
    l6 = ((vader_struct_vader_midir_EscapeResult_t*) l3)->f_alias_of;
    l6 = vader_midir_compute_carried_across_loop_headers(l0, l6);
    vader_array_t* _a8_arr = vader_array_new(9u, 0u, 7u, 163u);
    l10 = (void*) _a8_arr;
    vader_array_t* _a9_arr = vader_array_new(6u, 0u, 12u, 159u);
    l14 = (void*) _a9_arr;
    vader_array_t* _a10_arr = vader_array_new(9u, 0u, 7u, 163u);
    l15 = (void*) _a10_arr;
    vader_struct_std_collections_MutableMap__i32__bool_t* _a11_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
    vader_obj_header_init(_a11_obj, 310u);
    _a11_obj->f_ekeys = l10;
    _a11_obj->f_evals = l14;
    _a11_obj->f_index = l15;
    _a11_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a11_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a11_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    t0 = (void*) _a11_obj;
    vader_struct_std_collections_MutableSet__i32_t* _a12_obj = (vader_struct_std_collections_MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i32_t));
    vader_obj_header_init(_a12_obj, 387u);
    _a12_obj->f_inner = t0;
    l10 = (void*) _a12_obj;
    vader_array_t* _a13_arr = vader_array_new(9u, 0u, 7u, 163u);
    l14 = (void*) _a13_arr;
    l4 = ((vader_array_t*) l2)->length;
    l5 = (size_t) (int64_t) INT64_C(0);
    {
        loop_139: {
            if ((l5 < l4)) {
                vader_array_t* _a14_slotarr = ((vader_array_t*) l2);
                if (_a14_slotarr->buf != NULL && _a14_slotarr->buf->header.forward != NULL) { _a14_slotarr->buf = vader_array_buf_forward(_a14_slotarr->buf); }
                if ((size_t) l5 >= _a14_slotarr->length) { vader_trap("array index out of bounds"); }
                l11 = ((int32_t*) _a14_slotarr->buf->slots)[_a14_slotarr->offset + (size_t) l5];
                t3 = std_collections_contains_key__i32__bool(((vader_struct_std_collections_MutableSet__i32_t*) ((vader_struct_vader_midir_EscapeResult_t*) l3)->f_escaping)->f_inner, l11);
                if (t3) {
                    t1 = (l5 + INT64_C(1));
                    l5 = (size_t) (int64_t) t1;
                    goto loop_139;
                }
                t3 = std_collections_contains_key__i32__bool(((vader_struct_std_collections_MutableSet__i32_t*) l6)->f_inner, l11);
                if (t3) {
                    t1 = (l5 + INT64_C(1));
                    l5 = (size_t) (int64_t) t1;
                    goto loop_139;
                }
                std_collections_add__i32(l10, l11);
                vader_array_push_i32((vader_array_t*) l14, l11);
                t1 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t1;
                goto loop_139;
            } else {
            }
        }
    }
    {
        loop_186: {
            t2 = ((vader_array_t*) l14)->length;
            if ((t2 > INT64_C(0))) {
                t2 = ((vader_array_t*) l14)->length;
                t1 = (t2 - INT64_C(1));
                l4 = (size_t) (int64_t) t1;
                vader_array_t* _a15_slotarr = ((vader_array_t*) l14);
                if (_a15_slotarr->buf != NULL && _a15_slotarr->buf->header.forward != NULL) { _a15_slotarr->buf = vader_array_buf_forward(_a15_slotarr->buf); }
                if ((size_t) l4 >= _a15_slotarr->length) { vader_trap("array index out of bounds"); }
                l11 = ((int32_t*) _a15_slotarr->buf->slots)[_a15_slotarr->offset + (size_t) l4];
                t2 = ((vader_array_t*) l14)->length;
                t1 = (t2 - INT64_C(1));
                l5 = (size_t) (int64_t) t1;
                vader_array_t* _a16_arr = vader_array_slice((vader_array_t*) l14, (size_t) INT64_C(0), (size_t) l5);
                l14 = (void*) _a16_arr;
                l9 = std_collections_get__i32__Any(((vader_struct_vader_midir_EscapeResult_t*) l3)->f_alias_from, l11);
                if (!(l9.tag == 0u)) {
                    l2 = l9.payload.obj;
                    l7 = ((vader_array_t*) l2)->length;
                    l8 = (size_t) (int64_t) INT64_C(0);
                    {
                        loop_226: {
                            if ((l8 < l7)) {
                                vader_array_t* _a17_slotarr = ((vader_array_t*) l2);
                                if (_a17_slotarr->buf != NULL && _a17_slotarr->buf->header.forward != NULL) { _a17_slotarr->buf = vader_array_buf_forward(_a17_slotarr->buf); }
                                if ((size_t) l8 >= _a17_slotarr->length) { vader_trap("array index out of bounds"); }
                                l12 = ((int32_t*) _a17_slotarr->buf->slots)[_a17_slotarr->offset + (size_t) l8];
                                t3 = std_collections_contains_key__i32__bool(((vader_struct_std_collections_MutableSet__i32_t*) l10)->f_inner, l12);
                                if (t3) {
                                    t1 = (l8 + INT64_C(1));
                                    l8 = (size_t) (int64_t) t1;
                                    goto loop_226;
                                }
                                l16 = std_collections_get__i32__Any(((vader_struct_vader_midir_EscapeResult_t*) l3)->f_alias_of, l12);
                                if (!(l16.tag == 0u)) {
                                    l17 = true;
                                    l15 = l16.payload.obj;
                                    vader_array_t* _a18_slotarr = ((vader_array_t*) l15);
                                    if (_a18_slotarr->buf != NULL && _a18_slotarr->buf->header.forward != NULL) { _a18_slotarr->buf = vader_array_buf_forward(_a18_slotarr->buf); }
                                    l18 = ((vader_array_t*) l15)->length;
                                    l19 = (size_t) (int64_t) INT64_C(0);
                                    {
                                        loop_262: {
                                            if ((l19 < l18)) {
                                                l13 = ((int32_t*) _a18_slotarr->buf->slots)[_a18_slotarr->offset + (size_t) l19];
                                                t3 = std_collections_contains_key__i32__bool(((vader_struct_std_collections_MutableSet__i32_t*) l10)->f_inner, l13);
                                                if (!(t3)) {
                                                    l17 = false;
                                                } else {
                                                    t1 = (l19 + INT64_C(1));
                                                    l19 = (size_t) (int64_t) t1;
                                                    goto loop_262;
                                                }
                                            } else {
                                            }
                                        }
                                    }
                                    if (l17) {
                                        std_collections_add__i32(l10, l12);
                                        vader_array_push_i32((vader_array_t*) l14, l12);
                                    } else {
                                    }
                                } else {
                                }
                                t1 = (l8 + INT64_C(1));
                                l8 = (size_t) (int64_t) t1;
                                goto loop_226;
                            } else {
                            }
                        }
                    }
                } else {
                }
                goto loop_186;
            } else {
            }
        }
    }
    l17 = false;
    vader_array_t* _a19_arr = vader_array_new(67u, 0u, 13u, 798u);
    l2 = (void*) _a19_arr;
    l14 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_blocks;
    l4 = ((vader_array_t*) l14)->length;
    l5 = (size_t) (int64_t) INT64_C(0);
    {
        loop_329: {
            if ((l5 < l4)) {
                vader_array_t* _a20_slotarr = ((vader_array_t*) l14);
                if (_a20_slotarr->buf != NULL && _a20_slotarr->buf->header.forward != NULL) { _a20_slotarr->buf = vader_array_buf_forward(_a20_slotarr->buf); }
                if ((size_t) l5 >= _a20_slotarr->length) { vader_trap("array index out of bounds"); }
                l15 = vader_array_ref_load_obj(_a20_slotarr->buf, _a20_slotarr->offset + (size_t) l5);
                l20 = false;
                vader_array_t* _a21_arr = vader_array_new(127u, 0u, 13u, 1157u);
                l21 = (void*) _a21_arr;
                l22 = ((vader_struct_vader_midir_BasicBlock_t*) l15)->f_instructions;
                l7 = ((vader_array_t*) l22)->length;
                l8 = (size_t) (int64_t) INT64_C(0);
                {
                    loop_349: {
                        if ((l8 < l7)) {
                            vader_array_t* _a22_slotarr = ((vader_array_t*) l22);
                            if (_a22_slotarr->buf != NULL && _a22_slotarr->buf->header.forward != NULL) { _a22_slotarr->buf = vader_array_buf_forward(_a22_slotarr->buf); }
                            if ((size_t) l8 >= _a22_slotarr->length) { vader_trap("array index out of bounds"); }
                            l9 = vader_array_ref_load_box(_a22_slotarr->buf, _a22_slotarr->offset + (size_t) l8);
                            if (l9.tag == 842u) {
                                l23 = l9.payload.obj;
                                l24 = ((vader_struct_std_collections_MutableSet__i32_t*) l1)->f_inner;
                                l11 = ((vader_struct_vader_midir_InstrStructNew_t*) l23)->f_dst;
                                t3 = std_collections_contains_key__i32__bool(l24, l11);
                                if (!(t3)) {
                                    vader_array_push((vader_array_t*) l21, vader_ref_box(l23));
                                    t1 = (l8 + INT64_C(1));
                                    l8 = (size_t) (int64_t) t1;
                                    goto loop_349;
                                }
                                l26 = ((vader_struct_std_collections_MutableSet__i32_t*) ((vader_struct_vader_midir_EscapeResult_t*) l3)->f_escaping)->f_inner;
                                l12 = ((vader_struct_vader_midir_InstrStructNew_t*) l23)->f_dst;
                                t3 = std_collections_contains_key__i32__bool(l26, l12);
                                if (!(t3)) {
                                    l27 = ((vader_struct_std_collections_MutableSet__i32_t*) l6)->f_inner;
                                    l13 = ((vader_struct_vader_midir_InstrStructNew_t*) l23)->f_dst;
                                    t3 = std_collections_contains_key__i32__bool(l27, l13);
                                    l25 = !(t3);
                                } else {
                                    l25 = false;
                                }
                                l28 = ((vader_struct_vader_midir_InstrStructNew_t*) l23)->f_stack;
                                if (l25 == l28) {
                                    vader_array_push((vader_array_t*) l21, vader_ref_box(l23));
                                    t1 = (l8 + INT64_C(1));
                                    l8 = (size_t) (int64_t) t1;
                                    goto loop_349;
                                }
                                l20 = true;
                                l29 = ((vader_struct_vader_midir_InstrStructNew_t*) l23)->f_span;
                                l30 = ((vader_struct_vader_midir_InstrStructNew_t*) l23)->f_dst;
                                l16 = ((vader_struct_vader_midir_InstrStructNew_t*) l23)->f_type;
                                l31 = ((vader_struct_vader_midir_InstrStructNew_t*) l23)->f_fields;
                                vader_struct_vader_midir_InstrStructNew_t* _a23_obj = (vader_struct_vader_midir_InstrStructNew_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrStructNew_t));
                                vader_obj_header_init(_a23_obj, 842u);
                                _a23_obj->f_span = l29;
                                _a23_obj->f_dst = l30;
                                _a23_obj->f_type = l16;
                                _a23_obj->f_fields = l31;
                                _a23_obj->f_stack = l25;
                                l32 = (void*) _a23_obj;
                                vader_array_push((vader_array_t*) l21, vader_ref_box(l32));
                                l18 = (size_t) (int64_t) INT64_C(1);
                                t1 = (l8 + l18);
                                l8 = (size_t) (int64_t) t1;
                                goto loop_349;
                            }
                            if (l9.tag == 820u) {
                                l33 = l9.payload.obj;
                                l34 = ((vader_struct_std_collections_MutableSet__i32_t*) l1)->f_inner;
                                l35 = ((vader_struct_vader_midir_InstrArrayNew_t*) l33)->f_dst;
                                t3 = std_collections_contains_key__i32__bool(l34, l35);
                                if (!(t3)) {
                                    vader_array_push((vader_array_t*) l21, vader_ref_box(l33));
                                    t1 = (l8 + INT64_C(1));
                                    l8 = (size_t) (int64_t) t1;
                                    goto loop_349;
                                }
                                l37 = ((vader_struct_std_collections_MutableSet__i32_t*) ((vader_struct_vader_midir_EscapeResult_t*) l3)->f_escaping)->f_inner;
                                l38 = ((vader_struct_vader_midir_InstrArrayNew_t*) l33)->f_dst;
                                t3 = std_collections_contains_key__i32__bool(l37, l38);
                                if (!(t3)) {
                                    l39 = ((vader_struct_std_collections_MutableSet__i32_t*) l6)->f_inner;
                                    l40 = ((vader_struct_vader_midir_InstrArrayNew_t*) l33)->f_dst;
                                    t3 = std_collections_contains_key__i32__bool(l39, l40);
                                    l36 = !(t3);
                                } else {
                                    l36 = false;
                                }
                                l41 = ((vader_struct_vader_midir_InstrArrayNew_t*) l33)->f_stack;
                                if (l36 == l41) {
                                    vader_array_push((vader_array_t*) l21, vader_ref_box(l33));
                                    t1 = (l8 + INT64_C(1));
                                    l8 = (size_t) (int64_t) t1;
                                    goto loop_349;
                                }
                                l20 = true;
                                l42 = ((vader_struct_vader_midir_InstrArrayNew_t*) l33)->f_span;
                                l43 = ((vader_struct_vader_midir_InstrArrayNew_t*) l33)->f_dst;
                                l44 = ((vader_struct_vader_midir_InstrArrayNew_t*) l33)->f_type;
                                l45 = ((vader_struct_vader_midir_InstrArrayNew_t*) l33)->f_length;
                                l46 = ((vader_struct_vader_midir_InstrArrayNew_t*) l33)->f_elements;
                                vader_struct_vader_midir_InstrArrayNew_t* _a24_obj = (vader_struct_vader_midir_InstrArrayNew_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrArrayNew_t));
                                vader_obj_header_init(_a24_obj, 820u);
                                _a24_obj->f_span = l42;
                                _a24_obj->f_dst = l43;
                                _a24_obj->f_type = l44;
                                _a24_obj->f_length = l45;
                                _a24_obj->f_elements = l46;
                                _a24_obj->f_stack = l36;
                                l47 = (void*) _a24_obj;
                                vader_array_push((vader_array_t*) l21, vader_ref_box(l47));
                                l18 = (size_t) (int64_t) INT64_C(1);
                                t1 = (l8 + l18);
                                l8 = (size_t) (int64_t) t1;
                                goto loop_349;
                            }
                            if (l9.tag == 836u) {
                                l48 = l9.payload.obj;
                                l49 = ((vader_struct_std_collections_MutableSet__i32_t*) l10)->f_inner;
                                l50 = ((vader_struct_vader_midir_InstrFieldSet_t*) l48)->f_target;
                                l51 = std_collections_contains_key__i32__bool(l49, l50);
                                l52 = ((vader_struct_vader_midir_InstrFieldSet_t*) l48)->f_barrierless;
                                if (l51 == l52) {
                                    vader_array_push((vader_array_t*) l21, vader_ref_box(l48));
                                    t1 = (l8 + INT64_C(1));
                                    l8 = (size_t) (int64_t) t1;
                                    goto loop_349;
                                }
                                l20 = true;
                                l53 = ((vader_struct_vader_midir_InstrFieldSet_t*) l48)->f_span;
                                l54 = ((vader_struct_vader_midir_InstrFieldSet_t*) l48)->f_target;
                                l55 = ((vader_struct_vader_midir_InstrFieldSet_t*) l48)->f_field;
                                l56 = ((vader_struct_vader_midir_InstrFieldSet_t*) l48)->f_value;
                                vader_struct_vader_midir_InstrFieldSet_t* _a25_obj = (vader_struct_vader_midir_InstrFieldSet_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrFieldSet_t));
                                vader_obj_header_init(_a25_obj, 836u);
                                _a25_obj->f_span = l53;
                                _a25_obj->f_target = l54;
                                _a25_obj->f_field = l55;
                                _a25_obj->f_value = l56;
                                _a25_obj->f_barrierless = l51;
                                l57 = (void*) _a25_obj;
                                vader_array_push((vader_array_t*) l21, vader_ref_box(l57));
                                l18 = (size_t) (int64_t) INT64_C(1);
                                t1 = (l8 + l18);
                                l8 = (size_t) (int64_t) t1;
                                goto loop_349;
                            }
                            l58 = l9;
                            vader_array_push((vader_array_t*) l21, l58);
                            l18 = (size_t) (int64_t) INT64_C(1);
                            t1 = (l8 + l18);
                            l8 = (size_t) (int64_t) t1;
                            goto loop_349;
                        } else {
                        }
                    }
                }
                if (!(l20)) {
                    vader_array_push((vader_array_t*) l2, vader_ref_box(l15));
                    t1 = (l5 + INT64_C(1));
                    l5 = (size_t) (int64_t) t1;
                    goto loop_329;
                }
                l17 = true;
                l59 = ((vader_struct_vader_midir_BasicBlock_t*) l15)->f_id;
                l60 = ((vader_struct_vader_midir_BasicBlock_t*) l15)->f_terminator;
                l61 = ((vader_struct_vader_midir_BasicBlock_t*) l15)->f_span;
                vader_struct_vader_midir_BasicBlock_t* _a26_obj = (vader_struct_vader_midir_BasicBlock_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_BasicBlock_t));
                vader_obj_header_init(_a26_obj, 798u);
                _a26_obj->f_id = l59;
                _a26_obj->f_instructions = l21;
                _a26_obj->f_terminator = l60;
                _a26_obj->f_span = l61;
                l62 = (void*) _a26_obj;
                vader_array_push((vader_array_t*) l2, vader_ref_box(l62));
                t1 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t1;
                goto loop_329;
            } else {
            }
        }
    }
    if (!(l17)) {
        { void* __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l55 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_mangled;
    l1 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_params;
    l9 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_return_type;
    l3 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_locals;
    l11 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_entry;
    l6 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_origin;
    l63 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_extern_name;
    l17 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_is_extern;
    l20 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_is_exported;
    vader_struct_vader_midir_CFGFunction_t* _a27_obj = (vader_struct_vader_midir_CFGFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_CFGFunction_t));
    vader_obj_header_init(_a27_obj, 800u);
    _a27_obj->f_mangled = l55;
    _a27_obj->f_params = l1;
    _a27_obj->f_return_type = l9;
    _a27_obj->f_locals = l3;
    _a27_obj->f_blocks = l2;
    _a27_obj->f_entry = l11;
    _a27_obj->f_origin = l6;
    _a27_obj->f_extern_name = l63;
    _a27_obj->f_is_extern = l17;
    _a27_obj->f_is_exported = l20;
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
    l3 = std_collections_get__i32__Any(l0, l1);
    if (l3.tag == 0u) {
        vader_array_t* _a0_arr = vader_array_new(9u, 1u, 7u, 163u);
        ((int32_t*) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = (int32_t) l2;
        l4 = (void*) _a0_arr;
        std_collections_put__i32__Any(l0, l1, vader_ref_box(l4));
    } else {
        t0 = l3.payload.obj;
        vader_array_push_i32((vader_array_t*) t0, l2);
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static vader_string_t vader_midir_array_element_name(vader_box_t l0) {
    void* t0 = NULL;
    vader_string_t t1;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 919u) {
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
    if (l0.tag == 919u) {
        t0 = l0.payload.obj;
        t1 = vader_bytecode_val_type_of_type(((vader_struct_vader_types_ArrayType_t*) t0)->f_element);
        return t1;
    }
    return (uint8_t) (int32_t) INT32_C(18);
}

static uint64_t vader_midir_bc_value_bits(vader_box_t l0, vader_string_t l1) {
    uint64_t l2;
    void* l3 = NULL;
    void* t0 = NULL;
    int64_t t1;
    uint32_t t2;
    bool t3;
    double t4;
    uint64_t t5;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[2] = { &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 765u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_lower_LoweredIntLit_t*) t0)->f_value;
        { uint64_t __vret = (uint64_t) (int64_t) t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 752u) {
        t0 = l0.payload.obj;
        t2 = ((vader_struct_vader_lower_LoweredCharLit_t*) t0)->f_value;
        { uint64_t __vret = (uint64_t) (int64_t) ((int64_t) (uint32_t) t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 745u) {
        t0 = l0.payload.obj;
        t3 = ((vader_struct_vader_lower_LoweredBoolLit_t*) t0)->f_value;
        if (t3) {
            l2 = (uint64_t) (int64_t) INT64_C(1);
        } else {
            l2 = (uint64_t) (int64_t) INT64_C(0);
        }
        { uint64_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 760u) {
        l3 = l0.payload.obj;
        if (l1 == 1439u) {
            t4 = ((vader_struct_vader_lower_LoweredFloatLit_t*) l3)->f_value;
            t2 = std_core_f32_Float32Bits_to_bits_vt((float) (double) t4);
            { uint64_t __vret = (uint64_t) (int64_t) ((int64_t) (uint32_t) t2); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t4 = ((vader_struct_vader_lower_LoweredFloatLit_t*) l3)->f_value;
        t5 = std_core_f64_FloatBits_to_bits_vt(t4);
        { uint64_t __vret = t5; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_import_32(1749u);
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
    vader_array_t* _a0_arr = vader_array_new(9u, 0u, 7u, 163u);
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
            } else {
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
    l4 = vader_midir_fresh_tmp(l0, 1690u, l3);
    l5 = ((vader_struct_vader_lower_LoweredArrayLen_t*) l1)->f_span;
    l6 = ((vader_struct_vader_lower_LoweredArrayLen_t*) l1)->f_resolve_buf;
    vader_struct_vader_midir_InstrArrayLen_t* _a0_obj = (vader_struct_vader_midir_InstrArrayLen_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrArrayLen_t));
    vader_obj_header_init(_a0_obj, 819u);
    _a0_obj->f_span = l5;
    _a0_obj->f_dst = l4;
    _a0_obj->f_target = l2;
    _a0_obj->f_resolve_buf = l6;
    l5 = (void*) _a0_obj;
    vader_midir_emit(l0, vader_ref_box(l5));
    t0 = vader_box_i32(163u, l4);
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
    vader_array_t* _a0_arr = vader_array_new(9u, 0u, 7u, 163u);
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
            } else {
            }
        }
    }
    l6 = ((vader_struct_vader_lower_LoweredArrayLit_t*) l1)->f_type;
    l7 = vader_midir_fresh_tmp(l0, 1109u, l6);
    l3 = ((vader_struct_vader_lower_LoweredArrayLit_t*) l1)->f_span;
    l6 = ((vader_struct_vader_lower_LoweredArrayLit_t*) l1)->f_type;
    t2 = ((vader_array_t*) ((vader_struct_vader_lower_LoweredArrayLit_t*) l1)->f_elements)->length;
    l9 = ((int32_t) (size_t) t2);
    vader_struct_vader_midir_InstrArrayNew_t* _a2_obj = (vader_struct_vader_midir_InstrArrayNew_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrArrayNew_t));
    vader_obj_header_init(_a2_obj, 820u);
    _a2_obj->f_span = l3;
    _a2_obj->f_dst = l7;
    _a2_obj->f_type = l6;
    _a2_obj->f_length = l9;
    _a2_obj->f_elements = l2;
    _a2_obj->f_stack = false;
    l2 = (void*) _a2_obj;
    vader_midir_emit(l0, vader_ref_box(l2));
    t0 = vader_box_i32(163u, l7);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_box_t vader_midir_build_array_push(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l3 = vader_box_null();
    void* l4 = NULL;
    int32_t l5, l6;
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
    vader_struct_vader_midir_InstrArrayPush_t* _a0_obj = (vader_struct_vader_midir_InstrArrayPush_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrArrayPush_t));
    vader_obj_header_init(_a0_obj, 821u);
    _a0_obj->f_span = l4;
    _a0_obj->f_target = l5;
    _a0_obj->f_value = l6;
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
    l6 = vader_midir_fresh_tmp(l0, 1899u, l5);
    l7 = ((vader_struct_vader_lower_LoweredArraySlice_t*) l1)->f_span;
    l5 = ((vader_struct_vader_lower_LoweredArraySlice_t*) l1)->f_type;
    l8 = ((int32_t) l2.payload.i);
    l9 = ((int32_t) l3.payload.i);
    l10 = ((int32_t) l4.payload.i);
    vader_struct_vader_midir_InstrArraySlice_t* _a0_obj = (vader_struct_vader_midir_InstrArraySlice_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrArraySlice_t));
    vader_obj_header_init(_a0_obj, 823u);
    _a0_obj->f_span = l7;
    _a0_obj->f_dst = l6;
    _a0_obj->f_type = l5;
    _a0_obj->f_target = l8;
    _a0_obj->f_lo = l9;
    _a0_obj->f_hi = l10;
    l7 = (void*) _a0_obj;
    vader_midir_emit(l0, vader_ref_box(l7));
    t0 = vader_box_i32(163u, l6);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void vader_midir_build_assign(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l6 = vader_box_null(), l7 = vader_box_null();
    void* l3 = NULL;
    void* l4 = NULL;
    int32_t l5, l8, l10;
    vader_string_t l9;
    bool l11;
    vader_box_t* gc_roots[3] = { &l2, &l6, &l7 };
    void** gc_raw_roots[4] = { &l0, &l1, &l3, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_lower_LoweredAssign_t*) l1)->f_target;
    if (l2.tag == 762u) {
        l3 = l2.payload.obj;
        l4 = ((vader_struct_vader_midir_FnCtx_t*) l0)->f_local_by_sym_id;
        l5 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_lower_LoweredIdent_t*) l3)->f_symbol)->f_id;
        l6 = std_collections_get__i32__i32(l4, l5);
        l7 = ((vader_struct_vader_lower_LoweredAssign_t*) l1)->f_value;
        l7 = vader_midir_build_expr(l0, l7);
        if (l6.tag == 0u) {
            { vader_gc_top = gc_frame.prev; return; }
        }
        if (l7.tag == 0u) {
            { vader_gc_top = gc_frame.prev; return; }
        }
        l3 = ((vader_struct_vader_lower_LoweredAssign_t*) l1)->f_span;
        l5 = ((int32_t) l6.payload.i);
        l8 = ((int32_t) l7.payload.i);
        vader_struct_vader_midir_InstrMove_t* _a0_obj = (vader_struct_vader_midir_InstrMove_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrMove_t));
        vader_obj_header_init(_a0_obj, 840u);
        _a0_obj->f_span = l3;
        _a0_obj->f_dst = l5;
        _a0_obj->f_src = l8;
        l3 = (void*) _a0_obj;
        vader_midir_emit(l0, vader_ref_box(l3));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 759u) {
        l3 = l2.payload.obj;
        l6 = ((vader_struct_vader_lower_LoweredFieldAccess_t*) l3)->f_target;
        l6 = vader_midir_build_expr(l0, l6);
        l7 = ((vader_struct_vader_lower_LoweredAssign_t*) l1)->f_value;
        l7 = vader_midir_build_expr(l0, l7);
        if (l6.tag == 0u) {
            { vader_gc_top = gc_frame.prev; return; }
        }
        if (l7.tag == 0u) {
            { vader_gc_top = gc_frame.prev; return; }
        }
        l4 = ((vader_struct_vader_lower_LoweredAssign_t*) l1)->f_span;
        l5 = ((int32_t) l6.payload.i);
        l9 = ((vader_struct_vader_lower_LoweredFieldAccess_t*) l3)->f_field;
        l8 = ((int32_t) l7.payload.i);
        vader_struct_vader_midir_InstrFieldSet_t* _a1_obj = (vader_struct_vader_midir_InstrFieldSet_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrFieldSet_t));
        vader_obj_header_init(_a1_obj, 836u);
        _a1_obj->f_span = l4;
        _a1_obj->f_target = l5;
        _a1_obj->f_field = l9;
        _a1_obj->f_value = l8;
        _a1_obj->f_barrierless = false;
        l3 = (void*) _a1_obj;
        vader_midir_emit(l0, vader_ref_box(l3));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 764u) {
        l3 = l2.payload.obj;
        l2 = ((vader_struct_vader_lower_LoweredIndex_t*) l3)->f_target;
        l2 = vader_midir_build_expr(l0, l2);
        l6 = ((vader_struct_vader_lower_LoweredIndex_t*) l3)->f_index;
        l6 = vader_midir_build_expr(l0, l6);
        l7 = ((vader_struct_vader_lower_LoweredAssign_t*) l1)->f_value;
        l7 = vader_midir_build_expr(l0, l7);
        if (l2.tag == 0u) {
            { vader_gc_top = gc_frame.prev; return; }
        }
        if (l6.tag == 0u) {
            { vader_gc_top = gc_frame.prev; return; }
        }
        if (l7.tag == 0u) {
            { vader_gc_top = gc_frame.prev; return; }
        }
        l4 = ((vader_struct_vader_lower_LoweredAssign_t*) l1)->f_span;
        l5 = ((int32_t) l2.payload.i);
        l8 = ((int32_t) l6.payload.i);
        l10 = ((int32_t) l7.payload.i);
        l11 = ((vader_struct_vader_lower_LoweredIndex_t*) l3)->f_bounds_safe;
        vader_struct_vader_midir_InstrArraySet_t* _a2_obj = (vader_struct_vader_midir_InstrArraySet_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrArraySet_t));
        vader_obj_header_init(_a2_obj, 822u);
        _a2_obj->f_span = l4;
        _a2_obj->f_target = l5;
        _a2_obj->f_index = l8;
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
    vader_string_t l5;
    void* l7 = NULL;
    uint8_t l8;
    bool t0;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l3, &t1 };
    void** gc_raw_roots[3] = { &l0, &l1, &l7 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
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
    vader_obj_header_init(_a0_obj, 824u);
    _a0_obj->f_span = l7;
    _a0_obj->f_dst = l6;
    _a0_obj->f_op = l8;
    _a0_obj->f_lhs = l2;
    _a0_obj->f_rhs = l4;
    _a0_obj->f_type = l3;
    l7 = (void*) _a0_obj;
    vader_midir_emit(l0, vader_ref_box(l7));
    t1 = vader_box_i32(163u, l6);
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
            } else {
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
            } else {
            }
        }
    }
    if (((vader_struct_vader_midir_FnCtx_t*) l0)->f_current.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (!(((vader_struct_vader_lower_LoweredBlock_t*) l1)->f_trailing.tag == 0u)) {
        l6 = ((vader_struct_vader_lower_LoweredBlock_t*) l1)->f_trailing;
        vader_midir_build_expr_into(l0, l6, l2);
    } else {
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static vader_box_t vader_midir_build_call(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l6 = NULL;
    void* l14 = NULL;
    vader_box_t l4 = vader_box_null(), l5 = vader_box_null(), l8 = vader_box_null(), l9 = vader_box_null(), l11 = vader_box_null(), l12 = vader_box_null(), l13 = vader_box_null();
    int32_t l7;
    vader_string_t l10;
    vader_box_t t0 = vader_box_null();
    bool t1;
    int32_t t2;
    vader_box_t* gc_roots[8] = { &l4, &l5, &l8, &l9, &l11, &l12, &l13, &t0 };
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l3, &l6, &l14 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 8u, 6u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (((vader_struct_vader_lower_LoweredCall_t*) l1)->f_callee.tag == 762u) {
        l2 = ((vader_struct_vader_lower_LoweredCall_t*) l1)->f_callee.payload.obj;
        if (((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_lower_LoweredIdent_t*) l2)->f_symbol)->f_kind == INT32_C(0)) {
            l3 = ((vader_struct_vader_lower_LoweredCall_t*) l1)->f_args;
            l4 = vader_midir_build_args(l0, l3);
            if (l4.tag == 0u) {
                t0 = vader_box_obj(0u, NULL);
                { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
            }
            l3 = l4.payload.obj;
            t1 = vader_typecheck_is_void(((vader_struct_vader_lower_LoweredCall_t*) l1)->f_type);
            if (t1) {
                l4 = vader_box_obj(0u, NULL);
            } else {
                l5 = ((vader_struct_vader_lower_LoweredCall_t*) l1)->f_type;
                t2 = vader_midir_fresh_tmp(l0, 1234u, l5);
                l4 = vader_box_i32(163u, t2);
            }
            l6 = ((vader_struct_vader_lower_LoweredCall_t*) l1)->f_span;
            l2 = ((vader_struct_vader_lower_LoweredIdent_t*) l2)->f_symbol;
            l5 = ((vader_struct_vader_lower_LoweredCall_t*) l1)->f_type;
            vader_struct_vader_midir_InstrCall_t* _a0_obj = (vader_struct_vader_midir_InstrCall_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrCall_t));
            vader_obj_header_init(_a0_obj, 825u);
            _a0_obj->f_span = l6;
            _a0_obj->f_dst = l4;
            _a0_obj->f_callee = l2;
            _a0_obj->f_args = l3;
            _a0_obj->f_type = l5;
            l2 = (void*) _a0_obj;
            vader_midir_emit(l0, vader_ref_box(l2));
            { vader_box_t __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l4 = ((vader_struct_vader_lower_LoweredCall_t*) l1)->f_callee;
        l5 = vader_midir_build_expr(l0, l4);
        if (l5.tag == 0u) {
            t0 = vader_box_obj(0u, NULL);
            { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l7 = ((int32_t) l5.payload.i);
        l3 = ((vader_struct_vader_lower_LoweredCall_t*) l1)->f_args;
        l8 = vader_midir_build_args(l0, l3);
        if (l8.tag == 0u) {
            t0 = vader_box_obj(0u, NULL);
            { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l2 = l8.payload.obj;
        t1 = vader_typecheck_is_void(((vader_struct_vader_lower_LoweredCall_t*) l1)->f_type);
        if (t1) {
            l9 = vader_box_obj(0u, NULL);
        } else {
            l10 = 1245u;
            l11 = ((vader_struct_vader_lower_LoweredCall_t*) l1)->f_type;
            t2 = vader_midir_fresh_tmp(l0, l10, l11);
            l9 = vader_box_i32(163u, t2);
        }
        l6 = ((vader_struct_vader_lower_LoweredCall_t*) l1)->f_span;
        l12 = vader_lower_type_of(((vader_struct_vader_lower_LoweredCall_t*) l1)->f_callee);
        l13 = ((vader_struct_vader_lower_LoweredCall_t*) l1)->f_type;
        vader_struct_vader_midir_InstrCallIndirect_t* _a1_obj = (vader_struct_vader_midir_InstrCallIndirect_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrCallIndirect_t));
        vader_obj_header_init(_a1_obj, 826u);
        _a1_obj->f_span = l6;
        _a1_obj->f_dst = l9;
        _a1_obj->f_callee = l7;
        _a1_obj->f_args = l2;
        _a1_obj->f_fn_type = l12;
        _a1_obj->f_type = l13;
        l14 = (void*) _a1_obj;
        vader_midir_emit(l0, vader_ref_box(l14));
        { vader_box_t __vret = l9; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = ((vader_struct_vader_lower_LoweredCall_t*) l1)->f_callee;
    l5 = vader_midir_build_expr(l0, l4);
    if (l5.tag == 0u) {
        t0 = vader_box_obj(0u, NULL);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l7 = ((int32_t) l5.payload.i);
    l3 = ((vader_struct_vader_lower_LoweredCall_t*) l1)->f_args;
    l8 = vader_midir_build_args(l0, l3);
    if (l8.tag == 0u) {
        t0 = vader_box_obj(0u, NULL);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = l8.payload.obj;
    t1 = vader_typecheck_is_void(((vader_struct_vader_lower_LoweredCall_t*) l1)->f_type);
    if (t1) {
        l9 = vader_box_obj(0u, NULL);
    } else {
        l10 = 1245u;
        l11 = ((vader_struct_vader_lower_LoweredCall_t*) l1)->f_type;
        t2 = vader_midir_fresh_tmp(l0, l10, l11);
        l9 = vader_box_i32(163u, t2);
    }
    l6 = ((vader_struct_vader_lower_LoweredCall_t*) l1)->f_span;
    l12 = vader_lower_type_of(((vader_struct_vader_lower_LoweredCall_t*) l1)->f_callee);
    l13 = ((vader_struct_vader_lower_LoweredCall_t*) l1)->f_type;
    vader_struct_vader_midir_InstrCallIndirect_t* _a2_obj = (vader_struct_vader_midir_InstrCallIndirect_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrCallIndirect_t));
    vader_obj_header_init(_a2_obj, 826u);
    _a2_obj->f_span = l6;
    _a2_obj->f_dst = l9;
    _a2_obj->f_callee = l7;
    _a2_obj->f_args = l2;
    _a2_obj->f_fn_type = l12;
    _a2_obj->f_type = l13;
    l14 = (void*) _a2_obj;
    vader_midir_emit(l0, vader_ref_box(l14));
    { vader_box_t __vret = l9; vader_gc_top = gc_frame.prev; return __vret; }
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
    l4 = vader_midir_fresh_tmp(l0, 1261u, l3);
    l5 = ((vader_struct_vader_lower_LoweredCast_t*) l1)->f_span;
    l3 = ((vader_struct_vader_lower_LoweredCast_t*) l1)->f_type;
    vader_struct_vader_midir_InstrCast_t* _a0_obj = (vader_struct_vader_midir_InstrCast_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrCast_t));
    vader_obj_header_init(_a0_obj, 827u);
    _a0_obj->f_span = l5;
    _a0_obj->f_dst = l4;
    _a0_obj->f_value = l2;
    _a0_obj->f_type = l3;
    l5 = (void*) _a0_obj;
    vader_midir_emit(l0, vader_ref_box(l5));
    t0 = vader_box_i32(163u, l4);
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
    l4 = vader_midir_fresh_tmp(l0, 1264u, l3);
    l5 = ((vader_struct_vader_lower_LoweredCellGet_t*) l1)->f_span;
    l3 = ((vader_struct_vader_lower_LoweredCellGet_t*) l1)->f_value_type;
    vader_struct_vader_midir_InstrCellGet_t* _a0_obj = (vader_struct_vader_midir_InstrCellGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrCellGet_t));
    vader_obj_header_init(_a0_obj, 828u);
    _a0_obj->f_span = l5;
    _a0_obj->f_dst = l4;
    _a0_obj->f_cell = l2;
    _a0_obj->f_value_type = l3;
    l5 = (void*) _a0_obj;
    vader_midir_emit(l0, vader_ref_box(l5));
    t0 = vader_box_i32(163u, l4);
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
    l4 = vader_midir_fresh_tmp(l0, 1263u, l3);
    l5 = ((vader_struct_vader_lower_LoweredCellNew_t*) l1)->f_span;
    l3 = ((vader_struct_vader_lower_LoweredCellNew_t*) l1)->f_value_type;
    vader_struct_vader_midir_InstrCellNew_t* _a0_obj = (vader_struct_vader_midir_InstrCellNew_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrCellNew_t));
    vader_obj_header_init(_a0_obj, 829u);
    _a0_obj->f_span = l5;
    _a0_obj->f_dst = l4;
    _a0_obj->f_value = l2;
    _a0_obj->f_value_type = l3;
    l5 = (void*) _a0_obj;
    vader_midir_emit(l0, vader_ref_box(l5));
    t0 = vader_box_i32(163u, l4);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

void* vader_midir_build_cfg_project(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l9 = NULL;
    void* l11 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    void* l15 = NULL;
    void* l19 = NULL;
    void* l20 = NULL;
    void* l22 = NULL;
    void* l23 = NULL;
    void* l27 = NULL;
    size_t l6, l7, l16, l17, l24;
    vader_string_t l8, l10, l25, l26;
    vader_box_t l18 = vader_box_null(), l21 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    int64_t t1;
    void* t2 = NULL;
    vader_box_t* gc_roots[3] = { &l18, &l21, &t0 };
    void** gc_raw_roots[18] = { &l0, &l1, &l2, &l3, &l4, &l5, &l9, &l11, &l12, &l13, &l14, &l15, &l19, &l20, &l22, &l23, &l27, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 18u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_midir_new_project_ctx(l0);
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 161u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(15u, 0u, 0u, 170u);
    l3 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 163u);
    l4 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__string__Any_t* _a3_obj = (vader_struct_std_collections_MutableMap__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__Any_t));
    vader_obj_header_init(_a3_obj, 321u);
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
        loop_29: {
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
                vader_struct___Tuple_1251_t* _a6_obj = (vader_struct___Tuple_1251_t*) vader_gc_alloc(sizeof(vader_struct___Tuple_1251_t));
                vader_obj_header_init(_a6_obj, 214u);
                _a6_obj->f__0 = l8;
                _a6_obj->f__1 = l3;
                l9 = (void*) _a6_obj;
                l10 = ((vader_struct___Tuple_1251_t*) l9)->f__0;
                l11 = ((vader_struct___Tuple_1251_t*) l9)->f__1;
                t1 = (l7 + INT64_C(1));
                l7 = (size_t) (int64_t) t1;
                vader_array_t* _a7_arr = vader_array_new(69u, 0u, 13u, 800u);
                l12 = (void*) _a7_arr;
                vader_array_t* _a8_arr = vader_array_new(68u, 0u, 13u, 799u);
                l13 = (void*) _a8_arr;
                vader_array_t* _a9_arr = vader_array_new(73u, 0u, 13u, 805u);
                l14 = (void*) _a9_arr;
                l15 = ((vader_struct_vader_lower_LoweredModule_t*) l11)->f_decls;
                l16 = ((vader_array_t*) l15)->length;
                l17 = (size_t) (int64_t) INT64_C(0);
                {
                    loop_70: {
                        if ((l17 < l16)) {
                            vader_array_t* _a10_slotarr = ((vader_array_t*) l15);
                            if (_a10_slotarr->buf != NULL && _a10_slotarr->buf->header.forward != NULL) { _a10_slotarr->buf = vader_array_buf_forward(_a10_slotarr->buf); }
                            if ((size_t) l17 >= _a10_slotarr->length) { vader_trap("array index out of bounds"); }
                            l18 = vader_array_ref_load_box(_a10_slotarr->buf, _a10_slotarr->offset + (size_t) l17);
                            if (l18.tag == 761u) {
                                l19 = l18.payload.obj;
                                if (((vader_struct_vader_lower_LoweredFnDecl_t*) l19)->f_body.tag == 0u) {
                                    l20 = vader_midir_make_extern_decl(l19);
                                    vader_array_push((vader_array_t*) l13, vader_ref_box(l20));
                                } else {
                                    l21 = vader_midir_convert_function(l19, l1);
                                    if (!(l21.tag == 0u)) {
                                        l22 = l21.payload.obj;
                                        vader_array_push((vader_array_t*) l12, vader_ref_box(l22));
                                    } else {
                                    }
                                }
                                l24 = (size_t) (int64_t) INT64_C(1);
                                t1 = (l17 + l24);
                                l17 = (size_t) (int64_t) t1;
                                goto loop_70;
                            }
                            if (l18.tag == 777u) {
                                t2 = l18.payload.obj;
                                l23 = vader_midir_make_struct_decl(t2);
                                vader_array_push((vader_array_t*) l14, vader_ref_box(l23));
                                l24 = (size_t) (int64_t) INT64_C(1);
                                t1 = (l17 + l24);
                                l17 = (size_t) (int64_t) t1;
                                goto loop_70;
                            }
                            if (l18.tag == 753u) {
                                l24 = (size_t) (int64_t) INT64_C(1);
                                t1 = (l17 + l24);
                                l17 = (size_t) (int64_t) t1;
                                goto loop_70;
                            }
                            vader_unreachable("unreachable return in vader_midir$build_cfg_project");
                        } else {
                        }
                    }
                }
                l25 = ((vader_struct_vader_lower_LoweredModule_t*) l11)->f_module_id;
                l26 = ((vader_struct_vader_lower_LoweredModule_t*) l11)->f_display_path;
                vader_struct_vader_midir_CFGModule_t* _a11_obj = (vader_struct_vader_midir_CFGModule_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_CFGModule_t));
                vader_obj_header_init(_a11_obj, 802u);
                _a11_obj->f_module_id = l25;
                _a11_obj->f_display_path = l26;
                _a11_obj->f_functions = l12;
                _a11_obj->f_externs = l13;
                _a11_obj->f_struct_decls = l14;
                l27 = (void*) _a11_obj;
                std_collections_put__string__Any(l2, l10, vader_ref_box(l27));
                goto loop_29;
            }
        }
    }
    l3 = ((vader_struct_vader_lower_LoweredProject_t*) l0)->f_vtable_entries;
    l1 = ((vader_struct_vader_midir_ProjectCtx_t*) l1)->f_strings;
    l4 = vader_midir_convert_data_pool(((vader_struct_vader_lower_LoweredProject_t*) l0)->f_data_pool);
    l5 = ((vader_struct_vader_lower_LoweredProject_t*) l0)->f_trait_membership;
    vader_struct_vader_midir_CFGProject_t* _a12_obj = (vader_struct_vader_midir_CFGProject_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_CFGProject_t));
    vader_obj_header_init(_a12_obj, 804u);
    _a12_obj->f_modules = l2;
    _a12_obj->f_vtable_entries = l3;
    _a12_obj->f_strings = l1;
    _a12_obj->f_data_pool = l4;
    _a12_obj->f_trait_membership = l5;
    t2 = (void*) _a12_obj;
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_midir_build_cfg_signature(void* l0, vader_box_t l1, void* l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l9 = NULL;
    size_t l7, l8;
    uint8_t l10;
    int32_t l11;
    vader_string_t l12;
    int64_t t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[8] = { &l0, &l2, &l3, &l4, &l5, &l6, &l9, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 8u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(11u, 0u, 1u, 166u);
    l3 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(9u, 0u, 7u, 163u);
    l4 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(8u, 0u, 0u, 161u);
    l5 = (void*) _a2_arr;
    l6 = l0;
    l7 = ((vader_array_t*) l6)->length;
    l8 = (size_t) (int64_t) INT64_C(0);
    {
        loop_13: {
            if ((l8 < l7)) {
                vader_array_t* _a3_slotarr = ((vader_array_t*) l6);
                if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                if ((size_t) l8 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                l9 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l8);
                l10 = vader_bytecode_val_type_of_type(((vader_struct_vader_midir_CFGParam_t*) l9)->f_type);
                vader_array_push_u8((vader_array_t*) l3, (int32_t) (uint8_t) l10);
                l11 = vader_bytecode_intern_type(((vader_struct_vader_midir_CFGParam_t*) l9)->f_type, l2);
                vader_array_push_i32((vader_array_t*) l4, l11);
                l12 = ((vader_struct_vader_midir_CFGParam_t*) l9)->f_name;
                vader_array_push((vader_array_t*) l5, vader_box_string(161u, l12));
                t0 = (l8 + INT64_C(1));
                l8 = (size_t) (int64_t) t0;
                goto loop_13;
            } else {
            }
        }
    }
    l10 = vader_bytecode_val_type_of_type(l1);
    l11 = vader_bytecode_intern_type(l1, l2);
    vader_struct_vader_bytecode_BcSignature_t* _a4_obj = (vader_struct_vader_bytecode_BcSignature_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcSignature_t));
    vader_obj_header_init(_a4_obj, 516u);
    _a4_obj->f_params = l3;
    _a4_obj->f_result = l10;
    _a4_obj->f_param_types = l4;
    _a4_obj->f_result_type = l11;
    _a4_obj->f_param_names = l5;
    t1 = (void*) _a4_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
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
    l3 = vader_midir_fresh_tmp(l0, 1335u, l2);
    l4 = ((vader_struct_vader_lower_LoweredDataConst_t*) l1)->f_span;
    l2 = ((vader_struct_vader_lower_LoweredDataConst_t*) l1)->f_type;
    t0 = ((vader_struct_vader_lower_LoweredDataConst_t*) l1)->f_pool_index;
    l5 = ((int32_t) (size_t) t0);
    vader_struct_vader_midir_InstrDataConst_t* _a0_obj = (vader_struct_vader_midir_InstrDataConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrDataConst_t));
    vader_obj_header_init(_a0_obj, 832u);
    _a0_obj->f_span = l4;
    _a0_obj->f_dst = l3;
    _a0_obj->f_type = l2;
    _a0_obj->f_pool_index = l5;
    l4 = (void*) _a0_obj;
    vader_midir_emit(l0, vader_ref_box(l4));
    t1 = vader_box_i32(163u, l3);
    { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_box_t vader_midir_build_expr(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    void* l4 = NULL;
    vader_box_t l3 = vader_box_null();
    vader_string_t l5;
    int32_t l6;
    bool l7;
    vader_box_t t0 = vader_box_null();
    int64_t t1;
    int32_t t2;
    double t3;
    bool t4;
    uint32_t t5;
    vader_box_t* gc_roots[3] = { &l1, &l3, &t0 };
    void** gc_raw_roots[3] = { &l0, &l2, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (((vader_struct_vader_midir_FnCtx_t*) l0)->f_current.tag == 0u) {
        t0 = vader_box_obj(0u, NULL);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 765u) {
        l2 = l1.payload.obj;
        l3 = ((vader_struct_vader_lower_LoweredIntLit_t*) l2)->f_type;
        t1 = ((vader_struct_vader_lower_LoweredIntLit_t*) l2)->f_value;
        vader_struct_vader_midir_ConstInt_t* _a0_obj = (vader_struct_vader_midir_ConstInt_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_ConstInt_t));
        vader_obj_header_init(_a0_obj, 810u);
        _a0_obj->f_value = t1;
        l4 = (void*) _a0_obj;
        l2 = ((vader_struct_vader_lower_LoweredIntLit_t*) l2)->f_span;
        t2 = vader_midir_emit_const(l0, l3, vader_ref_box(l4), l2);
        t0 = vader_box_i32(163u, t2);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 760u) {
        l2 = l1.payload.obj;
        l3 = ((vader_struct_vader_lower_LoweredFloatLit_t*) l2)->f_type;
        t3 = ((vader_struct_vader_lower_LoweredFloatLit_t*) l2)->f_value;
        vader_struct_vader_midir_ConstFloat_t* _a1_obj = (vader_struct_vader_midir_ConstFloat_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_ConstFloat_t));
        vader_obj_header_init(_a1_obj, 809u);
        _a1_obj->f_value = t3;
        l4 = (void*) _a1_obj;
        l2 = ((vader_struct_vader_lower_LoweredFloatLit_t*) l2)->f_span;
        t2 = vader_midir_emit_const(l0, l3, vader_ref_box(l4), l2);
        t0 = vader_box_i32(163u, t2);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 745u) {
        l2 = l1.payload.obj;
        l3 = ((vader_struct_vader_lower_LoweredBoolLit_t*) l2)->f_type;
        t4 = ((vader_struct_vader_lower_LoweredBoolLit_t*) l2)->f_value;
        vader_struct_vader_midir_ConstBool_t* _a2_obj = (vader_struct_vader_midir_ConstBool_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_ConstBool_t));
        vader_obj_header_init(_a2_obj, 807u);
        _a2_obj->f_value = t4;
        l4 = (void*) _a2_obj;
        l2 = ((vader_struct_vader_lower_LoweredBoolLit_t*) l2)->f_span;
        t2 = vader_midir_emit_const(l0, l3, vader_ref_box(l4), l2);
        t0 = vader_box_i32(163u, t2);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 771u) {
        l2 = l1.payload.obj;
        l3 = ((vader_struct_vader_lower_LoweredNullLit_t*) l2)->f_type;
        vader_struct_vader_midir_ConstNull_t* _a3_obj = (vader_struct_vader_midir_ConstNull_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_ConstNull_t));
        vader_obj_header_init(_a3_obj, 811u);
        l4 = (void*) _a3_obj;
        l2 = ((vader_struct_vader_lower_LoweredNullLit_t*) l2)->f_span;
        t2 = vader_midir_emit_const(l0, l3, vader_ref_box(l4), l2);
        t0 = vader_box_i32(163u, t2);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 752u) {
        l2 = l1.payload.obj;
        l3 = ((vader_struct_vader_lower_LoweredCharLit_t*) l2)->f_type;
        t5 = ((vader_struct_vader_lower_LoweredCharLit_t*) l2)->f_value;
        vader_struct_vader_midir_ConstChar_t* _a4_obj = (vader_struct_vader_midir_ConstChar_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_ConstChar_t));
        vader_obj_header_init(_a4_obj, 808u);
        _a4_obj->f_value = ((int32_t) (uint32_t) t5);
        l4 = (void*) _a4_obj;
        l2 = ((vader_struct_vader_lower_LoweredCharLit_t*) l2)->f_span;
        t2 = vader_midir_emit_const(l0, l3, vader_ref_box(l4), l2);
        t0 = vader_box_i32(163u, t2);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 775u) {
        l2 = l1.payload.obj;
        l4 = ((vader_struct_vader_midir_FnCtx_t*) l0)->f_project;
        l5 = ((vader_struct_vader_lower_LoweredStringLit_t*) l2)->f_value;
        l6 = vader_midir_intern_string_pool(l4, l5);
        l3 = ((vader_struct_vader_lower_LoweredStringLit_t*) l2)->f_type;
        vader_struct_vader_midir_ConstString_t* _a5_obj = (vader_struct_vader_midir_ConstString_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_ConstString_t));
        vader_obj_header_init(_a5_obj, 812u);
        _a5_obj->f_index = l6;
        l4 = (void*) _a5_obj;
        l2 = ((vader_struct_vader_lower_LoweredStringLit_t*) l2)->f_span;
        t2 = vader_midir_emit_const(l0, l3, vader_ref_box(l4), l2);
        t0 = vader_box_i32(163u, t2);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 762u) {
        l2 = l1.payload.obj;
        t0 = vader_midir_build_ident(l0, l2);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 747u) {
        l2 = l1.payload.obj;
        t0 = vader_midir_build_call(l0, l2);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 785u) {
        l2 = l1.payload.obj;
        t0 = vader_midir_build_virtual_call(l0, l2);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 759u) {
        l2 = l1.payload.obj;
        t0 = vader_midir_build_field_access(l0, l2);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 764u) {
        l2 = l1.payload.obj;
        t0 = vader_midir_build_index(l0, l2);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 783u) {
        l2 = l1.payload.obj;
        t0 = vader_midir_build_unary(l0, l2);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 743u) {
        l2 = l1.payload.obj;
        t0 = vader_midir_build_binary(l0, l2);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 763u) {
        l2 = l1.payload.obj;
        t0 = vader_midir_build_if(l0, l2, vader_box_obj(0u, NULL));
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 744u) {
        l2 = l1.payload.obj;
        t0 = vader_midir_build_block_body(l0, l2);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 779u) {
        l2 = l1.payload.obj;
        t0 = vader_midir_build_struct_lit(l0, l2);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 738u) {
        l2 = l1.payload.obj;
        t0 = vader_midir_build_array_lit(l0, l2);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 748u) {
        l2 = l1.payload.obj;
        t0 = vader_midir_build_cast(l0, l2);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 781u) {
        l2 = l1.payload.obj;
        t0 = vader_midir_build_type_check(l0, l2);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 784u) {
        l2 = l1.payload.obj;
        l3 = ((vader_struct_vader_lower_LoweredUnreachable_t*) l2)->f_type;
        l4 = ((vader_struct_vader_lower_LoweredUnreachable_t*) l2)->f_span;
        l5 = ((vader_struct_vader_lower_LoweredUnreachable_t*) l2)->f_reason;
        l7 = ((vader_struct_vader_lower_LoweredUnreachable_t*) l2)->f_trap;
        t0 = vader_midir_build_unreachable_type(l0, l3, l4, l5, l7);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 766u) {
        l2 = l1.payload.obj;
        t0 = vader_midir_build_intrinsic_call(l0, l2);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 737u) {
        l2 = l1.payload.obj;
        t0 = vader_midir_build_array_len(l0, l2);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 739u) {
        l2 = l1.payload.obj;
        t0 = vader_midir_build_array_push(l0, l2);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 740u) {
        l2 = l1.payload.obj;
        t0 = vader_midir_build_array_slice(l0, l2);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 776u) {
        l2 = l1.payload.obj;
        t0 = vader_midir_build_string_slice(l0, l2);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 750u) {
        l2 = l1.payload.obj;
        t0 = vader_midir_build_cell_new(l0, l2);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 749u) {
        l2 = l1.payload.obj;
        t0 = vader_midir_build_cell_get(l0, l2);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 769u) {
        l2 = l1.payload.obj;
        t0 = vader_midir_build_make_closure(l0, l2);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 755u) {
        l2 = l1.payload.obj;
        t0 = vader_midir_build_data_const(l0, l2);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 782u) {
        l2 = l1.payload.obj;
        t0 = vader_midir_build_type_const(l0, l2);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_unreachable("unreachable return in vader_midir$build_expr");
    vader_gc_top = gc_frame.prev;
}

static void vader_midir_build_expr_into(void* l0, vader_box_t l1, int32_t l2) {
    void* l3 = NULL;
    void* l8 = NULL;
    vader_box_t l4 = vader_box_null(), l5 = vader_box_null();
    bool l6;
    int32_t l7;
    bool t0;
    vader_box_t* gc_roots[3] = { &l1, &l4, &l5 };
    void** gc_raw_roots[3] = { &l0, &l3, &l8 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l1.tag == 763u) {
        l3 = l1.payload.obj;
        vader_midir_build_if(l0, l3, vader_box_i32(163u, l2));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 744u) {
        l3 = l1.payload.obj;
        vader_midir_build_block_into(l0, l3, l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 743u) {
        l3 = l1.payload.obj;
        t0 = vader_midir_is_short_circuit_op(((vader_struct_vader_lower_LoweredBinary_t*) l3)->f_op);
        if (t0) {
            vader_midir_build_short_circuit(l0, l3, vader_box_i32(163u, l2));
            { vader_gc_top = gc_frame.prev; return; }
        }
        l4 = l1;
        l5 = vader_midir_build_expr(l0, l4);
        if (!(((vader_struct_vader_midir_FnCtx_t*) l0)->f_current.tag == 0u)) {
            l6 = !(l5.tag == 0u);
        } else {
            l6 = false;
        }
        if (l6) {
            l3 = vader_lower_span_of(l1);
            l7 = ((int32_t) l5.payload.i);
            vader_struct_vader_midir_InstrMove_t* _a0_obj = (vader_struct_vader_midir_InstrMove_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrMove_t));
            vader_obj_header_init(_a0_obj, 840u);
            _a0_obj->f_span = l3;
            _a0_obj->f_dst = l2;
            _a0_obj->f_src = l7;
            l8 = (void*) _a0_obj;
            vader_midir_emit(l0, vader_ref_box(l8));
        } else {
        }
        { vader_gc_top = gc_frame.prev; return; }
    }
    l4 = l1;
    l5 = vader_midir_build_expr(l0, l4);
    if (!(((vader_struct_vader_midir_FnCtx_t*) l0)->f_current.tag == 0u)) {
        l6 = !(l5.tag == 0u);
    } else {
        l6 = false;
    }
    if (l6) {
        l3 = vader_lower_span_of(l1);
        l7 = ((int32_t) l5.payload.i);
        vader_struct_vader_midir_InstrMove_t* _a1_obj = (vader_struct_vader_midir_InstrMove_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrMove_t));
        vader_obj_header_init(_a1_obj, 840u);
        _a1_obj->f_span = l3;
        _a1_obj->f_dst = l2;
        _a1_obj->f_src = l7;
        l8 = (void*) _a1_obj;
        vader_midir_emit(l0, vader_ref_box(l8));
    } else {
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static vader_box_t vader_midir_build_field_access(void* l0, void* l1) {
    int32_t l2, l4;
    vader_box_t l3 = vader_box_null();
    void* l5 = NULL;
    vader_string_t l6;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l3, &t0 };
    void** gc_raw_roots[3] = { &l0, &l1, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_lower_LoweredFieldAccess_t*) l1)->f_target;
    l3 = vader_midir_build_expr(l0, l3);
    if (l3.tag == 0u) {
        t0 = vader_box_obj(0u, NULL);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = ((int32_t) l3.payload.i);
    l3 = ((vader_struct_vader_lower_LoweredFieldAccess_t*) l1)->f_type;
    l4 = vader_midir_fresh_tmp(l0, 1460u, l3);
    l5 = ((vader_struct_vader_lower_LoweredFieldAccess_t*) l1)->f_span;
    l6 = ((vader_struct_vader_lower_LoweredFieldAccess_t*) l1)->f_field;
    l3 = ((vader_struct_vader_lower_LoweredFieldAccess_t*) l1)->f_type;
    vader_struct_vader_midir_InstrFieldGet_t* _a0_obj = (vader_struct_vader_midir_InstrFieldGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrFieldGet_t));
    vader_obj_header_init(_a0_obj, 835u);
    _a0_obj->f_span = l5;
    _a0_obj->f_dst = l4;
    _a0_obj->f_target = l2;
    _a0_obj->f_field = l6;
    _a0_obj->f_type = l3;
    l5 = (void*) _a0_obj;
    vader_midir_emit(l0, vader_ref_box(l5));
    t0 = vader_box_i32(163u, l4);
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
    vader_string_t l11;
    int32_t t0;
    int64_t t1;
    void* t2 = NULL;
    bool t3;
    vader_box_t t4 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l4, &l6, &t4 };
    void** gc_raw_roots[7] = { &l0, &l1, &l2, &l8, &l9, &l10, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 7u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_midir_FnCtx_t*) l0)->f_local_by_sym_id;
    l3 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_lower_LoweredIdent_t*) l1)->f_symbol)->f_id;
    l4 = std_collections_get__i32__i32(l2, l3);
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
        if (l6.tag == 935u) {
            l2 = l6.payload.obj;
            l6 = ((vader_struct_vader_lower_LoweredIdent_t*) l1)->f_type;
            t3 = vader_typecheck_equals_type(vader_ref_box(l2), l6);
            if (!(t3)) {
                l6 = ((vader_struct_vader_lower_LoweredIdent_t*) l1)->f_type;
                l3 = vader_midir_fresh_tmp(l0, 1774u, l6);
                l2 = ((vader_struct_vader_lower_LoweredIdent_t*) l1)->f_span;
                l7 = ((int32_t) l4.payload.i);
                l6 = ((vader_struct_vader_lower_LoweredIdent_t*) l1)->f_type;
                vader_struct_vader_midir_InstrCast_t* _a1_obj = (vader_struct_vader_midir_InstrCast_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrCast_t));
                vader_obj_header_init(_a1_obj, 827u);
                _a1_obj->f_span = l2;
                _a1_obj->f_dst = l3;
                _a1_obj->f_value = l7;
                _a1_obj->f_type = l6;
                l2 = (void*) _a1_obj;
                vader_midir_emit(l0, vader_ref_box(l2));
                t4 = vader_box_i32(163u, l3);
                { vader_box_t __vret = t4; vader_gc_top = gc_frame.prev; return __vret; }
            }
            t0 = ((int32_t) l4.payload.i);
            t4 = vader_box_i32(163u, t0);
            { vader_box_t __vret = t4; vader_gc_top = gc_frame.prev; return __vret; }
        }
        t0 = ((int32_t) l4.payload.i);
        t4 = vader_box_i32(163u, t0);
        { vader_box_t __vret = t4; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_lower_LoweredIdent_t*) l1)->f_symbol)->f_kind == INT32_C(0)) {
        l4 = ((vader_struct_vader_lower_LoweredIdent_t*) l1)->f_type;
        l3 = vader_midir_fresh_tmp(l0, 1487u, l4);
        l2 = ((vader_struct_vader_lower_LoweredIdent_t*) l1)->f_span;
        l8 = ((vader_struct_vader_lower_LoweredIdent_t*) l1)->f_symbol;
        l4 = ((vader_struct_vader_lower_LoweredIdent_t*) l1)->f_type;
        vader_struct_vader_midir_InstrFnRef_t* _a2_obj = (vader_struct_vader_midir_InstrFnRef_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrFnRef_t));
        vader_obj_header_init(_a2_obj, 837u);
        _a2_obj->f_span = l2;
        _a2_obj->f_dst = l3;
        _a2_obj->f_fn_symbol = l8;
        _a2_obj->f_type = l4;
        l2 = (void*) _a2_obj;
        vader_midir_emit(l0, vader_ref_box(l2));
        t4 = vader_box_i32(163u, l3);
        { vader_box_t __vret = t4; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = ((vader_struct_vader_midir_ProjectCtx_t*) ((vader_struct_vader_midir_FnCtx_t*) l0)->f_project)->f_const_fn_wrap;
    l3 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_lower_LoweredIdent_t*) l1)->f_symbol)->f_id;
    l4 = std_collections_get__i32__Any(l2, l3);
    if (l4.tag == 719u) {
        l2 = l4.payload.obj;
        l4 = ((vader_struct_vader_lower_ConstFnWrap_t*) l2)->f_call_type;
        l3 = vader_midir_fresh_tmp(l0, 1320u, l4);
        vader_array_t* _a3_arr = vader_array_new(9u, 0u, 7u, 163u);
        l8 = (void*) _a3_arr;
        l9 = ((vader_struct_vader_lower_LoweredIdent_t*) l1)->f_span;
        l10 = ((vader_struct_vader_lower_ConstFnWrap_t*) l2)->f_fn_symbol;
        l4 = ((vader_struct_vader_lower_ConstFnWrap_t*) l2)->f_call_type;
        vader_struct_vader_midir_InstrCall_t* _a4_obj = (vader_struct_vader_midir_InstrCall_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrCall_t));
        vader_obj_header_init(_a4_obj, 825u);
        _a4_obj->f_span = l9;
        _a4_obj->f_dst = vader_box_i32(163u, l3);
        _a4_obj->f_callee = l10;
        _a4_obj->f_args = l8;
        _a4_obj->f_type = l4;
        l2 = (void*) _a4_obj;
        vader_midir_emit(l0, vader_ref_box(l2));
        t4 = vader_box_i32(163u, l3);
        { vader_box_t __vret = t4; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = ((vader_struct_vader_midir_ProjectCtx_t*) ((vader_struct_vader_midir_FnCtx_t*) l0)->f_project)->f_const_inline;
    l3 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_lower_LoweredIdent_t*) l1)->f_symbol)->f_id;
    l4 = std_collections_get__i32__Any(l2, l3);
    if (!(l4.tag == 0u)) {
        t4 = vader_midir_build_expr(l0, l4);
        { vader_box_t __vret = t4; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = ((vader_struct_vader_lower_LoweredIdent_t*) l1)->f_type;
    l2 = ((vader_struct_vader_lower_LoweredIdent_t*) l1)->f_span;
    l11 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_lower_LoweredIdent_t*) l1)->f_symbol)->f_name;
    l11 = concat_2(2198u, l11);
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
        l4 = vader_box_i32(163u, t1);
    } else {
        t2 = vader_typecheck_is_void(((vader_struct_vader_lower_LoweredIf_t*) l1)->f_type);
        if (t2) {
            l4 = vader_box_obj(0u, NULL);
        } else {
            l5 = ((vader_struct_vader_lower_LoweredIf_t*) l1)->f_type;
            t1 = vader_midir_declare_local(l0, 1588u, l5, vader_box_obj(0u, NULL));
            l4 = vader_box_i32(163u, t1);
        }
    }
    l6 = ((vader_struct_vader_lower_LoweredBlock_t*) ((vader_struct_vader_lower_LoweredIf_t*) l1)->f_then_block)->f_span;
    l7 = vader_midir_new_block(l0, l6);
    if (((vader_struct_vader_lower_LoweredIf_t*) l1)->f_else_block.tag == 0u) {
        l5 = vader_box_obj(0u, NULL);
    } else {
        l6 = ((vader_struct_vader_lower_LoweredBlock_t*) ((vader_struct_vader_lower_LoweredIf_t*) l1)->f_else_block.payload.obj)->f_span;
        t1 = vader_midir_new_block(l0, l6);
        l5 = vader_box_i32(163u, t1);
    }
    l6 = ((vader_struct_vader_lower_LoweredIf_t*) l1)->f_span;
    l8 = vader_midir_new_block(l0, l6);
    if (l5.tag == 0u) {
        l9 = l8;
    } else {
        l9 = ((int32_t) l5.payload.i);
    }
    vader_struct_vader_midir_TermCondBranch_t* _a0_obj = (vader_struct_vader_midir_TermCondBranch_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_TermCondBranch_t));
    vader_obj_header_init(_a0_obj, 855u);
    _a0_obj->f_span = ((vader_struct_vader_lower_LoweredIf_t*) l1)->f_span;
    _a0_obj->f_cond = l3;
    _a0_obj->f_then_block = l7;
    _a0_obj->f_else_block = l9;
    l6 = (void*) _a0_obj;
    vader_midir_terminate(l0, vader_ref_box(l6));
    ((vader_struct_vader_midir_FnCtx_t*) l0)->f_current = vader_box_i32(163u, l7);
    VADER_WRITE_BARRIER((vader_struct_vader_midir_FnCtx_t*) l0);
    l6 = ((vader_struct_vader_lower_LoweredIf_t*) l1)->f_then_block;
    vader_midir_build_if_arm(l0, l6, l4);
    if (!(((vader_struct_vader_midir_FnCtx_t*) l0)->f_current.tag == 0u)) {
        vader_struct_vader_midir_TermBranch_t* _a1_obj = (vader_struct_vader_midir_TermBranch_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_TermBranch_t));
        vader_obj_header_init(_a1_obj, 854u);
        _a1_obj->f_span = ((vader_struct_vader_lower_LoweredBlock_t*) ((vader_struct_vader_lower_LoweredIf_t*) l1)->f_then_block)->f_span;
        _a1_obj->f_target = l8;
        l6 = (void*) _a1_obj;
        vader_midir_terminate(l0, vader_ref_box(l6));
    } else {
    }
    if (!(l5.tag == 0u)) {
        if (!(((vader_struct_vader_lower_LoweredIf_t*) l1)->f_else_block.tag == 0u)) {
            l3 = ((int32_t) l5.payload.i);
            ((vader_struct_vader_midir_FnCtx_t*) l0)->f_current = vader_box_i32(163u, l3);
            VADER_WRITE_BARRIER((vader_struct_vader_midir_FnCtx_t*) l0);
            t0 = ((vader_struct_vader_lower_LoweredIf_t*) l1)->f_else_block;
            l6 = t0.payload.obj;
            vader_midir_build_if_arm(l0, l6, l4);
            if (!(((vader_struct_vader_midir_FnCtx_t*) l0)->f_current.tag == 0u)) {
                vader_struct_vader_midir_TermBranch_t* _a2_obj = (vader_struct_vader_midir_TermBranch_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_TermBranch_t));
                vader_obj_header_init(_a2_obj, 854u);
                _a2_obj->f_span = ((vader_struct_vader_lower_LoweredBlock_t*) ((vader_struct_vader_lower_LoweredIf_t*) l1)->f_else_block.payload.obj)->f_span;
                _a2_obj->f_target = l8;
                l6 = (void*) _a2_obj;
                vader_midir_terminate(l0, vader_ref_box(l6));
            } else {
            }
        } else {
        }
    } else {
    }
    ((vader_struct_vader_midir_FnCtx_t*) l0)->f_current = vader_box_i32(163u, l8);
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
    vader_string_t l9, l16, l17, l23, l26;
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
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 11u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(40u, 0u, 13u, 610u);
    l3 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(8u, 0u, 0u, 161u);
    l4 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(6u, 0u, 12u, 159u);
    l5 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(9u, 0u, 7u, 163u);
    l6 = (void*) _a3_arr;
    vader_struct_std_collections_MutableMap__string__bool_t* _a4_obj = (vader_struct_std_collections_MutableMap__string__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__bool_t));
    vader_obj_header_init(_a4_obj, 368u);
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
                l10 = std_collections_get__string__i32(((vader_struct_vader_bytecode_EmitterCtx_t*) l2)->f_type_key, l9);
                if (!(l10.tag == 163u)) {
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
                    if (!(t1.tag == 518u)) {
                        t0 = (l8 + INT64_C(1));
                        l8 = (size_t) (int64_t) t0;
                        goto loop_23;
                    }
                    l17 = ((vader_struct_vader_lower_LoweredVtableEntry_t*) l6)->f_trait_name;
                    l18 = (size_t) (int64_t) INT64_C(21);
                    l19 = vader_import_0(l17);
                    l20 = std_core_new_byte_buffer((size_t) (int64_t) (l18 + l19));
                    l21 = (size_t) (int64_t) INT64_C(0);
                    l22 = ((int64_t) (int32_t) l11);
                    l21 = std_core_write_int(l20, l21, l22);
                    l23 = 2342u;
                    l21 = std_core_write_string_at(l20, l21, l23);
                    l21 = std_core_write_string_at(l20, l21, l17);
                    l16 = std_core_finish_buffer(l20, l21);
                    t1 = std_collections_get__string__bool(l4, l16);
                    if (t1.tag == 159u) {
                        l24 = (size_t) (int64_t) INT64_C(1);
                        t0 = (l8 + l24);
                        l8 = (size_t) (int64_t) t0;
                        goto loop_23;
                    }
                    l25 = true;
                    std_collections_put__string__bool(l4, l16, l25);
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
                l19 = vader_import_0(l17);
                l20 = std_core_new_byte_buffer((size_t) (int64_t) (l18 + l19));
                l21 = (size_t) (int64_t) INT64_C(0);
                l22 = ((int64_t) (int32_t) l11);
                l21 = std_core_write_int(l20, l21, l22);
                l23 = 2342u;
                l21 = std_core_write_string_at(l20, l21, l23);
                l21 = std_core_write_string_at(l20, l21, l17);
                l16 = std_core_finish_buffer(l20, l21);
                t1 = std_collections_get__string__bool(l4, l16);
                if (t1.tag == 159u) {
                    l24 = (size_t) (int64_t) INT64_C(1);
                    t0 = (l8 + l24);
                    l8 = (size_t) (int64_t) t0;
                    goto loop_23;
                }
                l25 = true;
                std_collections_put__string__bool(l4, l16, l25);
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
            } else {
            }
        }
    }
    l7 = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l2)->f_types)->length;
    l8 = (size_t) (int64_t) INT64_C(0);
    {
        loop_238: {
            if ((l8 < l7)) {
                vader_array_t* _a9_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l2)->f_types);
                if (_a9_slotarr->buf != NULL && _a9_slotarr->buf->header.forward != NULL) { _a9_slotarr->buf = vader_array_buf_forward(_a9_slotarr->buf); }
                if ((size_t) l8 >= _a9_slotarr->length) { vader_trap("array index out of bounds"); }
                t1 = vader_array_ref_load_box(_a9_slotarr->buf, _a9_slotarr->offset + (size_t) l8);
                if (t1.tag == 518u) {
                    vader_array_t* _a10_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l2)->f_types);
                    if (_a10_slotarr->buf != NULL && _a10_slotarr->buf->header.forward != NULL) { _a10_slotarr->buf = vader_array_buf_forward(_a10_slotarr->buf); }
                    if ((size_t) l8 >= _a10_slotarr->length) { vader_trap("array index out of bounds"); }
                    t1 = vader_array_ref_load_box(_a10_slotarr->buf, _a10_slotarr->offset + (size_t) l8);
                    t2 = t1.payload.obj;
                    l11 = ((vader_struct_vader_bytecode_BcStruct_t*) t2)->f_symbol_id;
                    l10 = std_collections_get__i32__Any(l1, l11);
                    if (l10.tag == 0u) {
                        t0 = (l8 + INT64_C(1));
                        l8 = (size_t) (int64_t) t0;
                        goto loop_238;
                    }
                    l5 = l10.payload.obj;
                    l12 = ((vader_array_t*) l5)->length;
                    l13 = (size_t) (int64_t) INT64_C(0);
                    {
                        loop_275: {
                            if ((l13 < l12)) {
                                vader_array_t* _a11_slotarr = ((vader_array_t*) l5);
                                if (_a11_slotarr->buf != NULL && _a11_slotarr->buf->header.forward != NULL) { _a11_slotarr->buf = vader_array_buf_forward(_a11_slotarr->buf); }
                                if ((size_t) l13 >= _a11_slotarr->length) { vader_trap("array index out of bounds"); }
                                t1 = vader_array_box_slots(_a11_slotarr->buf)[_a11_slotarr->offset + (size_t) l13];
                                l9 = t1.payload.s;
                                l17 = l9;
                                l15 = vader_import_0(l17);
                                l6 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(21) + l15));
                                l18 = (size_t) (int64_t) INT64_C(0);
                                t0 = ((int64_t) (size_t) l8);
                                l29 = (uint64_t) (int64_t) t0;
                                l18 = std_core_write_unsigned(l6, l18, l29);
                                l18 = std_core_write_string_at(l6, l18, 2342u);
                                l18 = std_core_write_string_at(l6, l18, l17);
                                l16 = std_core_finish_buffer(l6, l18);
                                t1 = std_collections_get__string__bool(l4, l16);
                                if (t1.tag == 159u) {
                                    t0 = (l13 + INT64_C(1));
                                    l13 = (size_t) (int64_t) t0;
                                    goto loop_275;
                                }
                                std_collections_put__string__bool(l4, l16, true);
                                vader_struct_vader_bytecode_ImplEntry_t* _a12_obj = (vader_struct_vader_bytecode_ImplEntry_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_ImplEntry_t));
                                vader_obj_header_init(_a12_obj, 610u);
                                _a12_obj->f_struct_type_index = ((int32_t) (size_t) l8);
                                _a12_obj->f_trait_name = l9;
                                l14 = (void*) _a12_obj;
                                vader_array_push((vader_array_t*) l3, vader_ref_box(l14));
                                t0 = (l13 + INT64_C(1));
                                l13 = (size_t) (int64_t) t0;
                                goto loop_275;
                            } else {
                            }
                        }
                    }
                    l19 = (size_t) (int64_t) INT64_C(1);
                    t0 = (l8 + l19);
                    l8 = (size_t) (int64_t) t0;
                    goto loop_238;
                }
                l19 = (size_t) (int64_t) INT64_C(1);
                t0 = (l8 + l19);
                l8 = (size_t) (int64_t) t0;
                goto loop_238;
            } else {
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
    l5 = vader_midir_fresh_tmp(l0, 1579u, l4);
    l6 = ((vader_struct_vader_lower_LoweredIndex_t*) l1)->f_span;
    l7 = ((int32_t) l2.payload.i);
    l8 = ((int32_t) l3.payload.i);
    l2 = ((vader_struct_vader_lower_LoweredIndex_t*) l1)->f_type;
    l9 = ((vader_struct_vader_lower_LoweredIndex_t*) l1)->f_bounds_safe;
    vader_struct_vader_midir_InstrArrayGet_t* _a0_obj = (vader_struct_vader_midir_InstrArrayGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrArrayGet_t));
    vader_obj_header_init(_a0_obj, 818u);
    _a0_obj->f_span = l6;
    _a0_obj->f_dst = l5;
    _a0_obj->f_target = l7;
    _a0_obj->f_index = l8;
    _a0_obj->f_type = l2;
    _a0_obj->f_bounds_safe = l9;
    l6 = (void*) _a0_obj;
    vader_midir_emit(l0, vader_ref_box(l6));
    t0 = vader_box_i32(163u, l5);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_box_t vader_midir_build_intrinsic_call(void* l0, void* l1) {
    void* l2 = NULL;
    void* l5 = NULL;
    vader_box_t l3 = vader_box_null(), l4 = vader_box_null();
    vader_string_t l6;
    vader_box_t t0 = vader_box_null();
    bool t1;
    int32_t t2;
    vader_box_t* gc_roots[3] = { &l3, &l4, &t0 };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
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
        t2 = vader_midir_fresh_tmp(l0, 1630u, l4);
        l3 = vader_box_i32(163u, t2);
    }
    l5 = ((vader_struct_vader_lower_LoweredIntrinsicCall_t*) l1)->f_span;
    l6 = ((vader_struct_vader_lower_LoweredIntrinsicCall_t*) l1)->f_name;
    vader_struct_vader_midir_InstrIntrinsic_t* _a0_obj = (vader_struct_vader_midir_InstrIntrinsic_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrIntrinsic_t));
    vader_obj_header_init(_a0_obj, 838u);
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
    void* l8 = NULL;
    int32_t l3, l4, l5, l7;
    vader_box_t l6 = vader_box_null();
    size_t l9, l10;
    size_t t0;
    int64_t t1;
    vader_box_t* gc_roots[1] = { &l6 };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &l8 };
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
        vader_obj_header_init(_a0_obj, 854u);
        _a0_obj->f_span = ((vader_struct_vader_lower_LoweredLoop_t*) l1)->f_span;
        _a0_obj->f_target = l3;
        l2 = (void*) _a0_obj;
        vader_midir_terminate(l0, vader_ref_box(l2));
    } else {
    }
    ((vader_struct_vader_midir_FnCtx_t*) l0)->f_current = vader_box_i32(163u, l3);
    VADER_WRITE_BARRIER((vader_struct_vader_midir_FnCtx_t*) l0);
    if (!(((vader_struct_vader_lower_LoweredLoop_t*) l1)->f_cond.tag == 0u)) {
        l6 = ((vader_struct_vader_lower_LoweredLoop_t*) l1)->f_cond;
        l6 = vader_midir_build_expr(l0, l6);
        if (!(l6.tag == 0u)) {
            l2 = vader_lower_span_of(((vader_struct_vader_lower_LoweredLoop_t*) l1)->f_cond);
            l7 = ((int32_t) l6.payload.i);
            vader_struct_vader_midir_TermCondBranch_t* _a1_obj = (vader_struct_vader_midir_TermCondBranch_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_TermCondBranch_t));
            vader_obj_header_init(_a1_obj, 855u);
            _a1_obj->f_span = l2;
            _a1_obj->f_cond = l7;
            _a1_obj->f_then_block = l4;
            _a1_obj->f_else_block = l5;
            l2 = (void*) _a1_obj;
            vader_midir_terminate(l0, vader_ref_box(l2));
        } else {
            vader_struct_vader_midir_TermBranch_t* _a2_obj = (vader_struct_vader_midir_TermBranch_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_TermBranch_t));
            vader_obj_header_init(_a2_obj, 854u);
            _a2_obj->f_span = ((vader_struct_vader_lower_LoweredLoop_t*) l1)->f_span;
            _a2_obj->f_target = l5;
            l2 = (void*) _a2_obj;
            vader_midir_terminate(l0, vader_ref_box(l2));
        }
    } else {
        vader_struct_vader_midir_TermBranch_t* _a3_obj = (vader_struct_vader_midir_TermBranch_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_TermBranch_t));
        vader_obj_header_init(_a3_obj, 854u);
        _a3_obj->f_span = ((vader_struct_vader_lower_LoweredLoop_t*) l1)->f_span;
        _a3_obj->f_target = l4;
        l2 = (void*) _a3_obj;
        vader_midir_terminate(l0, vader_ref_box(l2));
    }
    l2 = ((vader_struct_vader_midir_FnCtx_t*) l0)->f_loop_stack;
    vader_struct_vader_midir_LoopFrame_t* _a4_obj = (vader_struct_vader_midir_LoopFrame_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_LoopFrame_t));
    vader_obj_header_init(_a4_obj, 848u);
    _a4_obj->f_label = ((vader_struct_vader_lower_LoweredLoop_t*) l1)->f_label;
    _a4_obj->f_header_id = l3;
    _a4_obj->f_exit_id = l5;
    l8 = (void*) _a4_obj;
    vader_array_push((vader_array_t*) l2, vader_ref_box(l8));
    ((vader_struct_vader_midir_FnCtx_t*) l0)->f_current = vader_box_i32(163u, l4);
    VADER_WRITE_BARRIER((vader_struct_vader_midir_FnCtx_t*) l0);
    l2 = ((vader_struct_vader_lower_LoweredLoop_t*) l1)->f_body;
    vader_midir_build_block_body(l0, l2);
    if (!(((vader_struct_vader_midir_FnCtx_t*) l0)->f_current.tag == 0u)) {
        vader_struct_vader_midir_TermBranch_t* _a5_obj = (vader_struct_vader_midir_TermBranch_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_TermBranch_t));
        vader_obj_header_init(_a5_obj, 854u);
        _a5_obj->f_span = ((vader_struct_vader_lower_LoweredLoop_t*) l1)->f_span;
        _a5_obj->f_target = l3;
        l2 = (void*) _a5_obj;
        vader_midir_terminate(l0, vader_ref_box(l2));
    } else {
    }
    vader_array_t* _a6_arr = vader_array_new(75u, 0u, 13u, 848u);
    l2 = (void*) _a6_arr;
    t0 = ((vader_array_t*) ((vader_struct_vader_midir_FnCtx_t*) l0)->f_loop_stack)->length;
    t1 = (t0 - INT64_C(1));
    l9 = (size_t) (int64_t) t1;
    l10 = (size_t) (int64_t) INT64_C(0);
    {
        loop_123: {
            if ((l10 < l9)) {
                vader_array_t* _a7_slotarr = ((vader_array_t*) ((vader_struct_vader_midir_FnCtx_t*) l0)->f_loop_stack);
                if (_a7_slotarr->buf != NULL && _a7_slotarr->buf->header.forward != NULL) { _a7_slotarr->buf = vader_array_buf_forward(_a7_slotarr->buf); }
                if ((size_t) l10 >= _a7_slotarr->length) { vader_trap("array index out of bounds"); }
                l8 = vader_array_ref_load_obj(_a7_slotarr->buf, _a7_slotarr->offset + (size_t) l10);
                vader_array_push((vader_array_t*) l2, vader_ref_box(l8));
                t1 = (l10 + INT64_C(1));
                l10 = (size_t) (int64_t) t1;
                goto loop_123;
            } else {
            }
        }
    }
    ((vader_struct_vader_midir_FnCtx_t*) l0)->f_loop_stack = l2;
    VADER_WRITE_BARRIER((vader_struct_vader_midir_FnCtx_t*) l0);
    ((vader_struct_vader_midir_FnCtx_t*) l0)->f_current = vader_box_i32(163u, l5);
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
    l4 = vader_midir_fresh_tmp(l0, 1276u, l3);
    l5 = ((vader_struct_vader_lower_LoweredMakeClosure_t*) l1)->f_span;
    l6 = ((vader_struct_vader_lower_LoweredMakeClosure_t*) l1)->f_fn_symbol;
    l3 = vader_lower_type_of(((vader_struct_vader_lower_LoweredMakeClosure_t*) l1)->f_env);
    l7 = ((vader_struct_vader_lower_LoweredMakeClosure_t*) l1)->f_type;
    vader_struct_vader_midir_InstrMakeClosure_t* _a0_obj = (vader_struct_vader_midir_InstrMakeClosure_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrMakeClosure_t));
    vader_obj_header_init(_a0_obj, 839u);
    _a0_obj->f_span = l5;
    _a0_obj->f_dst = l4;
    _a0_obj->f_fn_symbol = l6;
    _a0_obj->f_env = l2;
    _a0_obj->f_env_type = l3;
    _a0_obj->f_type = l7;
    l5 = (void*) _a0_obj;
    vader_midir_emit(l0, vader_ref_box(l5));
    t0 = vader_box_i32(163u, l4);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_box_t vader_midir_build_short_circuit(void* l0, void* l1, vader_box_t l2) {
    int32_t l3, l6, l9, l10, l11;
    vader_box_t l4 = vader_box_null();
    bool l5;
    vader_string_t l7;
    void* l8 = NULL;
    void* l12 = NULL;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l2, &l4, &t0 };
    void** gc_raw_roots[4] = { &l0, &l1, &l8, &l12 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
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
            l7 = 1104u;
        } else {
            l7 = 1807u;
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
    vader_obj_header_init(_a0_obj, 855u);
    _a0_obj->f_span = ((vader_struct_vader_lower_LoweredBinary_t*) l1)->f_span;
    _a0_obj->f_cond = l3;
    _a0_obj->f_then_block = l9;
    _a0_obj->f_else_block = l10;
    l8 = (void*) _a0_obj;
    vader_midir_terminate(l0, vader_ref_box(l8));
    ((vader_struct_vader_midir_FnCtx_t*) l0)->f_current = vader_box_i32(163u, l9);
    VADER_WRITE_BARRIER((vader_struct_vader_midir_FnCtx_t*) l0);
    if (l5) {
        l4 = ((vader_struct_vader_lower_LoweredBinary_t*) l1)->f_right;
        l4 = vader_midir_build_expr(l0, l4);
        if (!(l4.tag == 0u)) {
            if (!(((vader_struct_vader_midir_FnCtx_t*) l0)->f_current.tag == 0u)) {
                l8 = vader_lower_span_of(((vader_struct_vader_lower_LoweredBinary_t*) l1)->f_right);
                l3 = ((int32_t) l4.payload.i);
                vader_struct_vader_midir_InstrMove_t* _a1_obj = (vader_struct_vader_midir_InstrMove_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrMove_t));
                vader_obj_header_init(_a1_obj, 840u);
                _a1_obj->f_span = l8;
                _a1_obj->f_dst = l6;
                _a1_obj->f_src = l3;
                l8 = (void*) _a1_obj;
                vader_midir_emit(l0, vader_ref_box(l8));
            } else {
            }
        } else {
        }
    } else {
        l4 = ((vader_struct_vader_lower_LoweredBinary_t*) l1)->f_type;
        l3 = vader_midir_fresh_tmp(l0, 1658u, l4);
        l8 = ((vader_struct_vader_lower_LoweredBinary_t*) l1)->f_span;
        vader_struct_vader_midir_ConstBool_t* _a2_obj = (vader_struct_vader_midir_ConstBool_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_ConstBool_t));
        vader_obj_header_init(_a2_obj, 807u);
        _a2_obj->f_value = true;
        l12 = (void*) _a2_obj;
        l4 = ((vader_struct_vader_lower_LoweredBinary_t*) l1)->f_type;
        vader_struct_vader_midir_InstrConst_t* _a3_obj = (vader_struct_vader_midir_InstrConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrConst_t));
        vader_obj_header_init(_a3_obj, 831u);
        _a3_obj->f_span = l8;
        _a3_obj->f_dst = l3;
        _a3_obj->f_value = vader_ref_box(l12);
        _a3_obj->f_type = l4;
        l8 = (void*) _a3_obj;
        vader_midir_emit(l0, vader_ref_box(l8));
        vader_struct_vader_midir_InstrMove_t* _a4_obj = (vader_struct_vader_midir_InstrMove_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrMove_t));
        vader_obj_header_init(_a4_obj, 840u);
        _a4_obj->f_span = ((vader_struct_vader_lower_LoweredBinary_t*) l1)->f_span;
        _a4_obj->f_dst = l6;
        _a4_obj->f_src = l3;
        l8 = (void*) _a4_obj;
        vader_midir_emit(l0, vader_ref_box(l8));
    }
    if (!(((vader_struct_vader_midir_FnCtx_t*) l0)->f_current.tag == 0u)) {
        vader_struct_vader_midir_TermBranch_t* _a5_obj = (vader_struct_vader_midir_TermBranch_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_TermBranch_t));
        vader_obj_header_init(_a5_obj, 854u);
        _a5_obj->f_span = ((vader_struct_vader_lower_LoweredBinary_t*) l1)->f_span;
        _a5_obj->f_target = l11;
        l8 = (void*) _a5_obj;
        vader_midir_terminate(l0, vader_ref_box(l8));
    } else {
    }
    ((vader_struct_vader_midir_FnCtx_t*) l0)->f_current = vader_box_i32(163u, l10);
    VADER_WRITE_BARRIER((vader_struct_vader_midir_FnCtx_t*) l0);
    if (l5) {
        l4 = ((vader_struct_vader_lower_LoweredBinary_t*) l1)->f_type;
        l3 = vader_midir_fresh_tmp(l0, 1658u, l4);
        l8 = ((vader_struct_vader_lower_LoweredBinary_t*) l1)->f_span;
        vader_struct_vader_midir_ConstBool_t* _a6_obj = (vader_struct_vader_midir_ConstBool_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_ConstBool_t));
        vader_obj_header_init(_a6_obj, 807u);
        _a6_obj->f_value = false;
        l12 = (void*) _a6_obj;
        l4 = ((vader_struct_vader_lower_LoweredBinary_t*) l1)->f_type;
        vader_struct_vader_midir_InstrConst_t* _a7_obj = (vader_struct_vader_midir_InstrConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrConst_t));
        vader_obj_header_init(_a7_obj, 831u);
        _a7_obj->f_span = l8;
        _a7_obj->f_dst = l3;
        _a7_obj->f_value = vader_ref_box(l12);
        _a7_obj->f_type = l4;
        l8 = (void*) _a7_obj;
        vader_midir_emit(l0, vader_ref_box(l8));
        vader_struct_vader_midir_InstrMove_t* _a8_obj = (vader_struct_vader_midir_InstrMove_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrMove_t));
        vader_obj_header_init(_a8_obj, 840u);
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
                vader_obj_header_init(_a9_obj, 840u);
                _a9_obj->f_span = l8;
                _a9_obj->f_dst = l6;
                _a9_obj->f_src = l3;
                l8 = (void*) _a9_obj;
                vader_midir_emit(l0, vader_ref_box(l8));
            } else {
            }
        } else {
        }
    }
    if (!(((vader_struct_vader_midir_FnCtx_t*) l0)->f_current.tag == 0u)) {
        vader_struct_vader_midir_TermBranch_t* _a10_obj = (vader_struct_vader_midir_TermBranch_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_TermBranch_t));
        vader_obj_header_init(_a10_obj, 854u);
        _a10_obj->f_span = ((vader_struct_vader_lower_LoweredBinary_t*) l1)->f_span;
        _a10_obj->f_target = l11;
        l8 = (void*) _a10_obj;
        vader_midir_terminate(l0, vader_ref_box(l8));
    } else {
    }
    ((vader_struct_vader_midir_FnCtx_t*) l0)->f_current = vader_box_i32(163u, l11);
    VADER_WRITE_BARRIER((vader_struct_vader_midir_FnCtx_t*) l0);
    t0 = vader_box_i32(163u, l6);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void vader_midir_build_stmt(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    void* l6 = NULL;
    vader_box_t l3 = vader_box_null(), l5 = vader_box_null();
    vader_string_t l4;
    int32_t l7, l8;
    bool t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[3] = { &l1, &l3, &l5 };
    void** gc_raw_roots[4] = { &l0, &l2, &l6, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l1.tag == 767u) {
        l2 = l1.payload.obj;
        l3 = ((vader_struct_vader_lower_LoweredLet_t*) l2)->f_value;
        t0 = vader_midir_is_dest_passing_shape(l3);
        if (t0) {
            l4 = ((vader_struct_vader_lower_LoweredLet_t*) l2)->f_name;
            l5 = ((vader_struct_vader_lower_LoweredLet_t*) l2)->f_type;
            l6 = ((vader_struct_vader_lower_LoweredLet_t*) l2)->f_symbol;
            l7 = vader_midir_declare_local(l0, l4, l5, vader_ref_box(l6));
            l6 = ((vader_struct_vader_midir_FnCtx_t*) l0)->f_local_by_sym_id;
            l8 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_lower_LoweredLet_t*) l2)->f_symbol)->f_id;
            std_collections_put__i32__i32(l6, l8, l7);
            if (!(((vader_struct_vader_midir_FnCtx_t*) l0)->f_current.tag == 0u)) {
                vader_midir_build_expr_into(l0, l3, l7);
            } else {
            }
        } else {
            l3 = vader_midir_build_expr(l0, l3);
            l4 = ((vader_struct_vader_lower_LoweredLet_t*) l2)->f_name;
            l5 = ((vader_struct_vader_lower_LoweredLet_t*) l2)->f_type;
            l6 = ((vader_struct_vader_lower_LoweredLet_t*) l2)->f_symbol;
            l7 = vader_midir_declare_local(l0, l4, l5, vader_ref_box(l6));
            l6 = ((vader_struct_vader_midir_FnCtx_t*) l0)->f_local_by_sym_id;
            l8 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_lower_LoweredLet_t*) l2)->f_symbol)->f_id;
            std_collections_put__i32__i32(l6, l8, l7);
            if (!(l3.tag == 0u)) {
                if (!(((vader_struct_vader_midir_FnCtx_t*) l0)->f_current.tag == 0u)) {
                    l2 = ((vader_struct_vader_lower_LoweredLet_t*) l2)->f_span;
                    l8 = ((int32_t) l3.payload.i);
                    vader_struct_vader_midir_InstrMove_t* _a0_obj = (vader_struct_vader_midir_InstrMove_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrMove_t));
                    vader_obj_header_init(_a0_obj, 840u);
                    _a0_obj->f_span = l2;
                    _a0_obj->f_dst = l7;
                    _a0_obj->f_src = l8;
                    l2 = (void*) _a0_obj;
                    vader_midir_emit(l0, vader_ref_box(l2));
                } else {
                }
            } else {
            }
        }
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 741u) {
        l2 = l1.payload.obj;
        vader_midir_build_assign(l0, l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 751u) {
        l2 = l1.payload.obj;
        l3 = ((vader_struct_vader_lower_LoweredCellSet_t*) l2)->f_target;
        l3 = vader_midir_build_expr(l0, l3);
        l5 = ((vader_struct_vader_lower_LoweredCellSet_t*) l2)->f_value;
        l5 = vader_midir_build_expr(l0, l5);
        if (!(l3.tag == 0u)) {
            if (!(l5.tag == 0u)) {
                l6 = ((vader_struct_vader_lower_LoweredCellSet_t*) l2)->f_span;
                l7 = ((int32_t) l3.payload.i);
                l8 = ((int32_t) l5.payload.i);
                l3 = ((vader_struct_vader_lower_LoweredCellSet_t*) l2)->f_value_type;
                vader_struct_vader_midir_InstrCellSet_t* _a1_obj = (vader_struct_vader_midir_InstrCellSet_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrCellSet_t));
                vader_obj_header_init(_a1_obj, 830u);
                _a1_obj->f_span = l6;
                _a1_obj->f_cell = l7;
                _a1_obj->f_value = l8;
                _a1_obj->f_value_type = l3;
                l2 = (void*) _a1_obj;
                vader_midir_emit(l0, vader_ref_box(l2));
            } else {
            }
        } else {
        }
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 757u) {
        l2 = l1.payload.obj;
        l3 = ((vader_struct_vader_lower_LoweredDeferPush_t*) l2)->f_thunk;
        l3 = vader_midir_build_expr(l0, l3);
        if (!(l3.tag == 0u)) {
            l2 = ((vader_struct_vader_lower_LoweredDeferPush_t*) l2)->f_span;
            l7 = ((int32_t) l3.payload.i);
            vader_struct_vader_midir_InstrDeferPush_t* _a2_obj = (vader_struct_vader_midir_InstrDeferPush_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrDeferPush_t));
            vader_obj_header_init(_a2_obj, 834u);
            _a2_obj->f_span = l2;
            _a2_obj->f_value = l7;
            l2 = (void*) _a2_obj;
            vader_midir_emit(l0, vader_ref_box(l2));
        } else {
        }
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 756u) {
        l2 = l1.payload.obj;
        l6 = ((vader_struct_vader_lower_LoweredDeferPopExec_t*) l2)->f_span;
        l7 = ((vader_struct_vader_lower_LoweredDeferPopExec_t*) l2)->f_count;
        vader_struct_vader_midir_InstrDeferPopExec_t* _a3_obj = (vader_struct_vader_midir_InstrDeferPopExec_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrDeferPopExec_t));
        vader_obj_header_init(_a3_obj, 833u);
        _a3_obj->f_span = l6;
        _a3_obj->f_count = l7;
        l2 = (void*) _a3_obj;
        vader_midir_emit(l0, vader_ref_box(l2));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 758u) {
        t1 = l1.payload.obj;
        l3 = ((vader_struct_vader_lower_LoweredExprStmt_t*) t1)->f_expr;
        vader_midir_build_expr(l0, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 774u) {
        l2 = l1.payload.obj;
        l3 = vader_box_obj(0u, NULL);
        if (!(((vader_struct_vader_lower_LoweredReturn_t*) l2)->f_value.tag == 0u)) {
            l5 = ((vader_struct_vader_lower_LoweredReturn_t*) l2)->f_value;
            l3 = vader_midir_build_expr(l0, l5);
        } else {
        }
        vader_struct_vader_midir_TermReturn_t* _a4_obj = (vader_struct_vader_midir_TermReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_TermReturn_t));
        vader_obj_header_init(_a4_obj, 856u);
        _a4_obj->f_span = ((vader_struct_vader_lower_LoweredReturn_t*) l2)->f_span;
        _a4_obj->f_value = l3;
        l2 = (void*) _a4_obj;
        vader_midir_terminate(l0, vader_ref_box(l2));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 768u) {
        l2 = l1.payload.obj;
        vader_midir_build_loop(l0, l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 746u) {
        l2 = l1.payload.obj;
        l3 = ((vader_struct_vader_lower_LoweredBreak_t*) l2)->f_label;
        l3 = vader_midir_resolve_loop_frame(l0, l3);
        if (l3.tag == 0u) {
            { vader_gc_top = gc_frame.prev; return; }
        }
        l6 = l3.payload.obj;
        l2 = ((vader_struct_vader_lower_LoweredBreak_t*) l2)->f_span;
        l7 = ((vader_struct_vader_midir_LoopFrame_t*) l6)->f_exit_id;
        vader_struct_vader_midir_TermBranch_t* _a5_obj = (vader_struct_vader_midir_TermBranch_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_TermBranch_t));
        vader_obj_header_init(_a5_obj, 854u);
        _a5_obj->f_span = l2;
        _a5_obj->f_target = l7;
        l2 = (void*) _a5_obj;
        vader_midir_terminate(l0, vader_ref_box(l2));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 754u) {
        l2 = l1.payload.obj;
        l3 = ((vader_struct_vader_lower_LoweredContinue_t*) l2)->f_label;
        l3 = vader_midir_resolve_loop_frame(l0, l3);
        if (l3.tag == 0u) {
            { vader_gc_top = gc_frame.prev; return; }
        }
        l6 = l3.payload.obj;
        l2 = ((vader_struct_vader_lower_LoweredContinue_t*) l2)->f_span;
        l7 = ((vader_struct_vader_midir_LoopFrame_t*) l6)->f_header_id;
        vader_struct_vader_midir_TermBranch_t* _a6_obj = (vader_struct_vader_midir_TermBranch_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_TermBranch_t));
        vader_obj_header_init(_a6_obj, 854u);
        _a6_obj->f_span = l2;
        _a6_obj->f_target = l7;
        l2 = (void*) _a6_obj;
        vader_midir_terminate(l0, vader_ref_box(l2));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if ((l1.tag == 742u || l1.tag == 787u)) {
        vader_import_32(1748u);
        { vader_gc_top = gc_frame.prev; return; }
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
    l6 = vader_midir_fresh_tmp(l0, 1328u, l5);
    l7 = ((vader_struct_vader_lower_LoweredStringSlice_t*) l1)->f_span;
    l5 = ((vader_struct_vader_lower_LoweredStringSlice_t*) l1)->f_type;
    l8 = ((int32_t) l2.payload.i);
    l9 = ((int32_t) l3.payload.i);
    l10 = ((int32_t) l4.payload.i);
    vader_struct_vader_midir_InstrStringSlice_t* _a0_obj = (vader_struct_vader_midir_InstrStringSlice_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrStringSlice_t));
    vader_obj_header_init(_a0_obj, 841u);
    _a0_obj->f_span = l7;
    _a0_obj->f_dst = l6;
    _a0_obj->f_type = l5;
    _a0_obj->f_target = l8;
    _a0_obj->f_lo = l9;
    _a0_obj->f_hi = l10;
    l7 = (void*) _a0_obj;
    vader_midir_emit(l0, vader_ref_box(l7));
    t0 = vader_box_i32(163u, l6);
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
    vader_array_t* _a0_arr = vader_array_new(9u, 0u, 7u, 163u);
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
            } else {
            }
        }
    }
    l7 = ((vader_struct_vader_lower_LoweredStructLit_t*) l1)->f_type;
    l6 = vader_midir_fresh_tmp(l0, 2034u, l7);
    l3 = ((vader_struct_vader_lower_LoweredStructLit_t*) l1)->f_span;
    l7 = ((vader_struct_vader_lower_LoweredStructLit_t*) l1)->f_type;
    vader_struct_vader_midir_InstrStructNew_t* _a2_obj = (vader_struct_vader_midir_InstrStructNew_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrStructNew_t));
    vader_obj_header_init(_a2_obj, 842u);
    _a2_obj->f_span = l3;
    _a2_obj->f_dst = l6;
    _a2_obj->f_type = l7;
    _a2_obj->f_fields = l2;
    _a2_obj->f_stack = false;
    l2 = (void*) _a2_obj;
    vader_midir_emit(l0, vader_ref_box(l2));
    t1 = vader_box_i32(163u, l6);
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
    l4 = vader_midir_fresh_tmp(l0, 2106u, l3);
    l5 = ((vader_struct_vader_lower_LoweredTypeCheck_t*) l1)->f_span;
    l3 = ((vader_struct_vader_lower_LoweredTypeCheck_t*) l1)->f_check_type;
    vader_struct_vader_midir_InstrTypeCheck_t* _a0_obj = (vader_struct_vader_midir_InstrTypeCheck_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrTypeCheck_t));
    vader_obj_header_init(_a0_obj, 843u);
    _a0_obj->f_span = l5;
    _a0_obj->f_dst = l4;
    _a0_obj->f_value = l2;
    _a0_obj->f_check_type = l3;
    l5 = (void*) _a0_obj;
    vader_midir_emit(l0, vader_ref_box(l5));
    t0 = vader_box_i32(163u, l4);
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
    l3 = vader_midir_fresh_tmp(l0, 2109u, l2);
    l4 = ((vader_struct_vader_lower_LoweredTypeConst_t*) l1)->f_span;
    l2 = ((vader_struct_vader_lower_LoweredTypeConst_t*) l1)->f_type;
    l5 = ((vader_struct_vader_lower_LoweredTypeConst_t*) l1)->f_value;
    vader_struct_vader_midir_InstrTypeConst_t* _a0_obj = (vader_struct_vader_midir_InstrTypeConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrTypeConst_t));
    vader_obj_header_init(_a0_obj, 844u);
    _a0_obj->f_span = l4;
    _a0_obj->f_dst = l3;
    _a0_obj->f_type = l2;
    _a0_obj->f_value_type = l5;
    l4 = (void*) _a0_obj;
    vader_midir_emit(l0, vader_ref_box(l4));
    t0 = vader_box_i32(163u, l3);
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
    l4 = vader_midir_fresh_tmp(l0, 2194u, l3);
    l5 = ((vader_struct_vader_lower_LoweredUnary_t*) l1)->f_span;
    l6 = ((vader_struct_vader_lower_LoweredUnary_t*) l1)->f_op;
    l3 = ((vader_struct_vader_lower_LoweredUnary_t*) l1)->f_type;
    vader_struct_vader_midir_InstrUnOp_t* _a0_obj = (vader_struct_vader_midir_InstrUnOp_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrUnOp_t));
    vader_obj_header_init(_a0_obj, 845u);
    _a0_obj->f_span = l5;
    _a0_obj->f_dst = l4;
    _a0_obj->f_op = l6;
    _a0_obj->f_operand = l2;
    _a0_obj->f_type = l3;
    l5 = (void*) _a0_obj;
    vader_midir_emit(l0, vader_ref_box(l5));
    t0 = vader_box_i32(163u, l4);
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
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (((vader_struct_vader_midir_FnCtx_t*) l0)->f_current.tag == 0u) {
        t0 = vader_box_obj(0u, NULL);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_typecheck_is_void(l1);
    if (t1) {
        l5 = vader_box_obj(0u, NULL);
    } else {
        t2 = vader_midir_declare_local(l0, 2195u, l1, vader_box_obj(0u, NULL));
        l5 = vader_box_i32(163u, t2);
    }
    vader_struct_vader_midir_TermUnreachable_t* _a0_obj = (vader_struct_vader_midir_TermUnreachable_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_TermUnreachable_t));
    vader_obj_header_init(_a0_obj, 857u);
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
    vader_string_t l7, l8;
    vader_box_t t0 = vader_box_null();
    bool t1;
    int32_t t2;
    vader_box_t* gc_roots[3] = { &l3, &l5, &t0 };
    void** gc_raw_roots[4] = { &l0, &l1, &l4, &l6 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
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
        t2 = vader_midir_fresh_tmp(l0, 2301u, l5);
        l3 = vader_box_i32(163u, t2);
    }
    l6 = ((vader_struct_vader_lower_LoweredVirtualCall_t*) l1)->f_span;
    l7 = ((vader_struct_vader_lower_LoweredVirtualCall_t*) l1)->f_trait_name;
    l8 = ((vader_struct_vader_lower_LoweredVirtualCall_t*) l1)->f_method;
    l5 = ((vader_struct_vader_lower_LoweredVirtualCall_t*) l1)->f_type;
    vader_struct_vader_midir_InstrVirtualCall_t* _a0_obj = (vader_struct_vader_midir_InstrVirtualCall_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrVirtualCall_t));
    vader_obj_header_init(_a0_obj, 846u);
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
    void* l17 = NULL;
    void* l18 = NULL;
    void* l19 = NULL;
    void* l20 = NULL;
    void* l21 = NULL;
    size_t l5, l6, l7, l8;
    vader_box_t l9 = vader_box_null();
    vader_string_t l10, l13, l14;
    int32_t l15, l16;
    void* t0 = NULL;
    int64_t t1;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l9, &t2 };
    void** gc_raw_roots[13] = { &l0, &l1, &l2, &l3, &l4, &l11, &l12, &l17, &l18, &l19, &l20, &l21, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 13u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 161u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(6u, 0u, 12u, 159u);
    l3 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 163u);
    l4 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__string__bool_t* _a3_obj = (vader_struct_std_collections_MutableMap__string__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__bool_t));
    vader_obj_header_init(_a3_obj, 368u);
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
                                std_collections_put__string__bool(l2, l10, true);
                            } else {
                            }
                            t1 = (l8 + INT64_C(1));
                            l8 = (size_t) (int64_t) t1;
                            goto loop_36;
                        } else {
                        }
                    }
                }
                t1 = (l6 + INT64_C(1));
                l6 = (size_t) (int64_t) t1;
                goto loop_21;
            } else {
            }
        }
    }
    vader_array_t* _a6_arr = vader_array_new(8u, 0u, 0u, 161u);
    l3 = (void*) _a6_arr;
    vader_array_t* _a7_arr = vader_array_new(14u, 0u, 4u, 169u);
    l4 = (void*) _a7_arr;
    vader_array_t* _a8_arr = vader_array_new(9u, 0u, 7u, 163u);
    l11 = (void*) _a8_arr;
    vader_struct_std_collections_MutableMap__string__usize_t* _a9_obj = (vader_struct_std_collections_MutableMap__string__usize_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__usize_t));
    vader_obj_header_init(_a9_obj, 373u);
    _a9_obj->f_ekeys = l3;
    _a9_obj->f_evals = l4;
    _a9_obj->f_index = l11;
    _a9_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a9_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a9_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l3 = (void*) _a9_obj;
    vader_array_t* _a10_arr = vader_array_new(43u, 0u, 13u, 664u);
    l4 = (void*) _a10_arr;
    l11 = l0;
    l5 = ((vader_array_t*) l11)->length;
    l6 = (size_t) (int64_t) INT64_C(0);
    {
        loop_99: {
            if ((l6 < l5)) {
                vader_array_t* _a11_slotarr = ((vader_array_t*) l11);
                if (_a11_slotarr->buf != NULL && _a11_slotarr->buf->header.forward != NULL) { _a11_slotarr->buf = vader_array_buf_forward(_a11_slotarr->buf); }
                if ((size_t) l6 >= _a11_slotarr->length) { vader_trap("array index out of bounds"); }
                l12 = vader_array_ref_load_obj(_a11_slotarr->buf, _a11_slotarr->offset + (size_t) l6);
                l10 = ((vader_struct_vader_lower_LoweredVtableEntry_t*) l12)->f_trait_name;
                l13 = ((vader_struct_vader_lower_LoweredVtableEntry_t*) l12)->f_method_name;
                l14 = concat_3(l10, 397u, l13);
                t2 = std_collections_get__string__bool(l2, l14);
                if (!(t2.tag == 159u)) {
                    t1 = (l6 + INT64_C(1));
                    l6 = (size_t) (int64_t) t1;
                    goto loop_99;
                }
                l15 = vader_midir_resolve_vtable_fn_index(((vader_struct_vader_lower_LoweredVtableEntry_t*) l12)->f_fn_symbol, l1);
                if ((l15 < INT32_C(0))) {
                    t1 = (l6 + INT64_C(1));
                    l6 = (size_t) (int64_t) t1;
                    goto loop_99;
                }
                l16 = vader_bytecode_intern_type(((vader_struct_vader_lower_LoweredVtableEntry_t*) l12)->f_struct_type, l1);
                l9 = std_collections_get__string__usize(l3, l14);
                if (l9.tag == 169u) {
                    l7 = ((size_t) l9.payload.i);
                    vader_array_t* _a12_slotarr = ((vader_array_t*) l4);
                    if (_a12_slotarr->buf != NULL && _a12_slotarr->buf->header.forward != NULL) { _a12_slotarr->buf = vader_array_buf_forward(_a12_slotarr->buf); }
                    if ((size_t) l7 >= _a12_slotarr->length) { vader_trap("array index out of bounds"); }
                    t0 = vader_array_ref_load_obj(_a12_slotarr->buf, _a12_slotarr->offset + (size_t) l7);
                    l17 = ((vader_struct_vader_bytecode_VtableRow_t*) t0)->f_entries;
                    vader_struct_vader_bytecode_VtableEntry_t* _a13_obj = (vader_struct_vader_bytecode_VtableEntry_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_VtableEntry_t));
                    vader_obj_header_init(_a13_obj, 663u);
                    _a13_obj->f_receiver_type_index = l16;
                    _a13_obj->f_fn_index = l15;
                    l18 = (void*) _a13_obj;
                    vader_array_push((vader_array_t*) l17, vader_ref_box(l18));
                } else {
                    l8 = ((vader_array_t*) l4)->length;
                    vader_array_t* _a14_arr = vader_array_new(42u, 0u, 13u, 663u);
                    l19 = (void*) _a14_arr;
                    vader_struct_vader_bytecode_VtableEntry_t* _a15_obj = (vader_struct_vader_bytecode_VtableEntry_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_VtableEntry_t));
                    vader_obj_header_init(_a15_obj, 663u);
                    _a15_obj->f_receiver_type_index = l16;
                    _a15_obj->f_fn_index = l15;
                    l20 = (void*) _a15_obj;
                    vader_array_push((vader_array_t*) l19, vader_ref_box(l20));
                    vader_struct_vader_bytecode_VtableRow_t* _a16_obj = (vader_struct_vader_bytecode_VtableRow_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_VtableRow_t));
                    vader_obj_header_init(_a16_obj, 664u);
                    _a16_obj->f_key = l14;
                    _a16_obj->f_entries = l19;
                    l21 = (void*) _a16_obj;
                    vader_array_push((vader_array_t*) l4, vader_ref_box(l21));
                    std_collections_put__string__usize(l3, l14, l8);
                }
                t1 = (l6 + INT64_C(1));
                l6 = (size_t) (int64_t) t1;
                goto loop_99;
            } else {
            }
        }
    }
    { void* __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static bool vader_midir_can_pass_through_stack(vader_box_t l0, vader_box_t l1, void* l2) {
    int32_t l3, l5;
    vader_box_t l4;
    int32_t t0;
    l4 = vader_midir_dst_of(l0);
    if (l4.tag == 0u) {
        return false;
    }
    l3 = ((int32_t) l4.payload.i);
    l4 = std_collections_get__i32__i32(l2, l3);
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
    l5 = ((int32_t) l4.payload.i);
    return l5 == l3;
}

static bool vader_midir_can_pass_through_terminator(vader_box_t l0, vader_box_t l1, void* l2) {
    int32_t l3, l5;
    vader_box_t l4;
    int32_t t0;
    l4 = vader_midir_dst_of(l0);
    if (l4.tag == 0u) {
        return false;
    }
    l3 = ((int32_t) l4.payload.i);
    l4 = std_collections_get__i32__i32(l2, l3);
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
    l5 = ((int32_t) l4.payload.i);
    return l5 == l3;
}

static void vader_midir_cf_block(void* l0, void* l1, int32_t l2) {
    void* l3 = NULL;
    void* l5 = NULL;
    int32_t l4;
    void** gc_raw_roots[4] = { &l0, &l1, &l3, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_bytecode_Block_t* _a0_obj = (vader_struct_vader_bytecode_Block_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_Block_t));
    vader_obj_header_init(_a0_obj, 526u);
    l3 = (void*) _a0_obj;
    l4 = vader_midir_push_op_with_span(l0, vader_ref_box(l3), l1);
    l3 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_scopes;
    vader_struct_vader_midir_ScopeFrame_t* _a1_obj = (vader_struct_vader_midir_ScopeFrame_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_ScopeFrame_t));
    vader_obj_header_init(_a1_obj, 853u);
    _a1_obj->f_kind = 1180u;
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
    vader_obj_header_init(_a0_obj, 534u);
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
    vader_obj_header_init(_a0_obj, 550u);
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
    vader_obj_header_init(_a3_obj, 853u);
    _a3_obj->f_kind = 1580u;
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
    vader_string_t t1;
    int32_t t2;
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l6, &l7 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_bytecode_End_t* _a0_obj = (vader_struct_vader_bytecode_End_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_End_t));
    vader_obj_header_init(_a0_obj, 553u);
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
    vader_array_t* _a2_arr = vader_array_new(78u, 0u, 13u, 853u);
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
            } else {
            }
        }
    }
    ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_scopes = l6;
    VADER_WRITE_BARRIER((vader_struct_vader_midir_FnEmitCfg_t*) l0);
    t1 = ((vader_struct_vader_midir_ScopeFrame_t*) l2)->f_kind;
    if (t1 != 1714u) {
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
        } else {
        }
    } else {
    }
    l8 = ((vader_struct_vader_midir_ScopeFrame_t*) l2)->f_target_blk;
    t1 = ((vader_struct_vader_midir_ScopeFrame_t*) l2)->f_kind;
    l9 = t1 == 1714u;
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
    vader_obj_header_init(_a1_obj, 853u);
    _a1_obj->f_kind = 1580u;
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
    vader_obj_header_init(_a1_obj, 853u);
    _a1_obj->f_kind = 1714u;
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

static bool vader_midir_changed_blocks(void* l0, void* l1) {
    size_t l2, l3, l4, l5;
    void* t0;
    int64_t t1;
    l2 = ((vader_array_t*) ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_blocks)->length;
    l3 = ((vader_array_t*) ((vader_struct_vader_midir_CFGFunction_t*) l1)->f_blocks)->length;
    if (l2 != l3) {
        return true;
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_blocks);
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    l2 = ((vader_array_t*) ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_blocks)->length;
    l3 = (size_t) (int64_t) INT64_C(0);
    {
        loop_18: {
            if ((l3 < l2)) {
                if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
                l4 = ((vader_array_t*) ((vader_struct_vader_midir_BasicBlock_t*) t0)->f_instructions)->length;
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_midir_CFGFunction_t*) l1)->f_blocks);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l3 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l3);
                l5 = ((vader_array_t*) ((vader_struct_vader_midir_BasicBlock_t*) t0)->f_instructions)->length;
                if (l4 != l5) {
                    return true;
                }
                t1 = (l3 + INT64_C(1));
                l3 = (size_t) (int64_t) t1;
                goto loop_18;
            } else {
            }
        }
    }
    return false;
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
    if (l0.tag == 922u) {
        t0 = l0.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a0_arr = vader_array_new(128u, 0u, 13u, 1180u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(6u, 0u, 12u, 159u);
    l2 = (void*) _a1_arr;
    vader_struct_vader_types_PrimitiveType_t* _a2_obj = (vader_struct_vader_types_PrimitiveType_t*) vader_gc_alloc(sizeof(vader_struct_vader_types_PrimitiveType_t));
    vader_obj_header_init(_a2_obj, 928u);
    _a2_obj->f_name = 2303u;
    l3 = (void*) _a2_obj;
    vader_struct_vader_types_FnType_t* _a3_obj = (vader_struct_vader_types_FnType_t*) vader_gc_alloc(sizeof(vader_struct_vader_types_FnType_t));
    vader_obj_header_init(_a3_obj, 922u);
    _a3_obj->f_params = l1;
    _a3_obj->f_params_mutable = l2;
    _a3_obj->f_return_type = vader_ref_box(l3);
    t0 = (void*) _a3_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_midir_compact_locals(void* l0) {
    vader_box_t l1 = vader_box_null(), l4 = vader_box_null(), l11 = vader_box_null(), l13 = vader_box_null(), l18 = vader_box_null();
    void* l2 = NULL;
    void* l6 = NULL;
    void* l9 = NULL;
    void* l12 = NULL;
    void* l16 = NULL;
    void* l19 = NULL;
    void* l23 = NULL;
    void* l24 = NULL;
    void* l25 = NULL;
    void* l28 = NULL;
    void* l29 = NULL;
    size_t l3, l5, l7, l8, l10, l15, l17, l26, l27;
    int32_t l14, l21;
    bool l20, l31;
    vader_string_t l22, l30;
    size_t t0;
    void* t1 = NULL;
    int64_t t2;
    bool t3;
    vader_box_t t4 = vader_box_null();
    int32_t t5;
    vader_box_t* gc_roots[6] = { &l1, &l4, &l11, &l13, &l18, &t4 };
    void** gc_raw_roots[13] = { &l0, &l2, &l6, &l9, &l12, &l16, &l19, &l23, &l24, &l25, &l28, &l29, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 6u, 13u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_locals)->length;
    vader_struct__Cell_usize_t* _a0_obj = (vader_struct__Cell_usize_t*) vader_gc_alloc(sizeof(vader_struct__Cell_usize_t));
    vader_obj_header_init(_a0_obj, 189u);
    _a0_obj->f_value = t0;
    t1 = (void*) _a0_obj;
    l1 = vader_ref_box(t1);
    vader_array_t* _a1_arr = vader_array_new(6u, 1u, 12u, 159u);
    ((uint8_t*) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = (uint8_t) false;
    l2 = (void*) _a1_arr;
    l3 = ((vader_struct__Cell_usize_t*) l1.payload.obj)->f_value;
    vader_array_t* _a2_arr = vader_array_repeat((vader_array_t*) l2, (size_t) l3);
    t1 = (void*) _a2_arr;
    vader_struct__Cell_Array_bool__t* _a3_obj = (vader_struct__Cell_Array_bool__t*) vader_gc_alloc(sizeof(vader_struct__Cell_Array_bool__t));
    vader_obj_header_init(_a3_obj, 174u);
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
                } else {
                }
                t2 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t2;
                goto loop_21;
            } else {
            }
        }
    }
    l2 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_blocks;
    l3 = ((vader_array_t*) l2)->length;
    l5 = (size_t) (int64_t) INT64_C(0);
    {
        loop_66: {
            if ((l5 < l3)) {
                vader_array_t* _a6_slotarr = ((vader_array_t*) l2);
                if (_a6_slotarr->buf != NULL && _a6_slotarr->buf->header.forward != NULL) { _a6_slotarr->buf = vader_array_buf_forward(_a6_slotarr->buf); }
                if ((size_t) l5 >= _a6_slotarr->length) { vader_trap("array index out of bounds"); }
                l6 = vader_array_ref_load_obj(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l5);
                l9 = ((vader_struct_vader_midir_BasicBlock_t*) l6)->f_instructions;
                l7 = ((vader_array_t*) l9)->length;
                l8 = (size_t) (int64_t) INT64_C(0);
                {
                    loop_82: {
                        if ((l8 < l7)) {
                            vader_array_t* _a7_slotarr = ((vader_array_t*) l9);
                            if (_a7_slotarr->buf != NULL && _a7_slotarr->buf->header.forward != NULL) { _a7_slotarr->buf = vader_array_buf_forward(_a7_slotarr->buf); }
                            if ((size_t) l8 >= _a7_slotarr->length) { vader_trap("array index out of bounds"); }
                            l11 = vader_array_ref_load_box(_a7_slotarr->buf, _a7_slotarr->offset + (size_t) l8);
                            vader_struct___lambda_env_1655_t* _a8_obj = (vader_struct___lambda_env_1655_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_1655_t));
                            vader_obj_header_init(_a8_obj, 229u);
                            _a8_obj->f_cap_0 = l1;
                            _a8_obj->f_cap_1 = l4;
                            t1 = (void*) _a8_obj;
                            vader_fn_t* _a9_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
                            vader_obj_header_init(_a9_closure, 138u);
                            _a9_closure->code = (void*) &vader_fn_lift_1750;
                            _a9_closure->env = t1;
                            l12 = (void*) _a9_closure;
                            vader_midir_for_each_read_local(l11, l12);
                            t3 = vader_midir_instruction_has_side_effect(l11);
                            if (t3) {
                                l13 = vader_midir_dst_of(l11);
                                if (l13.tag == 163u) {
                                    l14 = ((int32_t) l13.payload.i);
                                    t2 = ((int64_t) (int32_t) l14);
                                    l10 = (size_t) (int64_t) t2;
                                    l15 = ((vader_struct__Cell_usize_t*) l1.payload.obj)->f_value;
                                    if ((l10 < l15)) {
                                        l16 = ((vader_struct__Cell_Array_bool__t*) l4.payload.obj)->f_value;
                                        t2 = ((int64_t) (int32_t) l14);
                                        l17 = (size_t) (int64_t) t2;
                                        vader_array_t* _a10_slotarr = ((vader_array_t*) l16);
                                        if (_a10_slotarr->buf != NULL && _a10_slotarr->buf->header.forward != NULL) { _a10_slotarr->buf = vader_array_buf_forward(_a10_slotarr->buf); }
                                        if ((size_t) l17 >= _a10_slotarr->length) { vader_trap("array index out of bounds"); }
                                        ((uint8_t*) _a10_slotarr->buf->slots)[_a10_slotarr->offset + (size_t) l17] = (uint8_t) true;
                                    } else {
                                    }
                                } else {
                                }
                            } else {
                            }
                            t2 = (l8 + INT64_C(1));
                            l8 = (size_t) (int64_t) t2;
                            goto loop_82;
                        } else {
                        }
                    }
                }
                l18 = ((vader_struct_vader_midir_BasicBlock_t*) l6)->f_terminator;
                vader_struct___lambda_env_1658_t* _a11_obj = (vader_struct___lambda_env_1658_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_1658_t));
                vader_obj_header_init(_a11_obj, 230u);
                _a11_obj->f_cap_0 = l1;
                _a11_obj->f_cap_1 = l4;
                t1 = (void*) _a11_obj;
                vader_fn_t* _a12_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
                vader_obj_header_init(_a12_closure, 138u);
                _a12_closure->code = (void*) &vader_fn_lift_1751;
                _a12_closure->env = t1;
                l19 = (void*) _a12_closure;
                vader_midir_for_each_read_in_terminator(l18, l19);
                t2 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t2;
                goto loop_66;
            } else {
            }
        }
    }
    l20 = false;
    l3 = ((vader_struct__Cell_usize_t*) l1.payload.obj)->f_value;
    l5 = ((vader_array_t*) ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_params)->length;
    {
        loop_169: {
            if ((l5 < l3)) {
                vader_array_t* _a13_slotarr = ((vader_array_t*) ((vader_struct__Cell_Array_bool__t*) l4.payload.obj)->f_value);
                if (_a13_slotarr->buf != NULL && _a13_slotarr->buf->header.forward != NULL) { _a13_slotarr->buf = vader_array_buf_forward(_a13_slotarr->buf); }
                if ((size_t) l5 >= _a13_slotarr->length) { vader_trap("array index out of bounds"); }
                t4 = vader_box_bool(159u, ((uint8_t*) _a13_slotarr->buf->slots)[_a13_slotarr->offset + (size_t) l5]);
                t3 = t4.payload.b;
                if (!(t3)) {
                    l20 = true;
                } else {
                    t2 = (l5 + INT64_C(1));
                    l5 = (size_t) (int64_t) t2;
                    goto loop_169;
                }
            } else {
            }
        }
    }
    if (!(l20)) {
        { void* __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a14_arr = vader_array_new(9u, 0u, 7u, 163u);
    l2 = (void*) _a14_arr;
    l3 = ((vader_struct__Cell_usize_t*) l1.payload.obj)->f_value;
    vader_array_t* _a15_arr = vader_array_repeat((vader_array_t*) l2, (size_t) l3);
    l2 = (void*) _a15_arr;
    vader_array_t* _a16_arr = vader_array_new(70u, 0u, 13u, 801u);
    l6 = (void*) _a16_arr;
    l3 = ((vader_struct__Cell_usize_t*) l1.payload.obj)->f_value;
    vader_array_t* _a17_arr = vader_array_repeat((vader_array_t*) l6, (size_t) l3);
    l6 = (void*) _a17_arr;
    l3 = ((vader_struct__Cell_usize_t*) l1.payload.obj)->f_value;
    l5 = (size_t) (int64_t) INT64_C(0);
    {
        loop_220: {
            if ((l5 < l3)) {
                vader_array_t* _a18_slotarr = ((vader_array_t*) ((vader_struct__Cell_Array_bool__t*) l4.payload.obj)->f_value);
                if (_a18_slotarr->buf != NULL && _a18_slotarr->buf->header.forward != NULL) { _a18_slotarr->buf = vader_array_buf_forward(_a18_slotarr->buf); }
                if ((size_t) l5 >= _a18_slotarr->length) { vader_trap("array index out of bounds"); }
                t4 = vader_box_bool(159u, ((uint8_t*) _a18_slotarr->buf->slots)[_a18_slotarr->offset + (size_t) l5]);
                t3 = t4.payload.b;
                if (!(t3)) {
                    l14 = -(INT32_C(1));
                    vader_array_push_i32((vader_array_t*) l2, l14);
                    t2 = (l5 + INT64_C(1));
                    l5 = (size_t) (int64_t) t2;
                    goto loop_220;
                }
                t0 = ((vader_array_t*) l6)->length;
                l21 = ((int32_t) (size_t) t0);
                vader_array_push_i32((vader_array_t*) l2, l21);
                vader_array_t* _a19_slotarr = ((vader_array_t*) ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_locals);
                if (_a19_slotarr->buf != NULL && _a19_slotarr->buf->header.forward != NULL) { _a19_slotarr->buf = vader_array_buf_forward(_a19_slotarr->buf); }
                if ((size_t) l5 >= _a19_slotarr->length) { vader_trap("array index out of bounds"); }
                l9 = vader_array_ref_load_obj(_a19_slotarr->buf, _a19_slotarr->offset + (size_t) l5);
                vader_array_push((vader_array_t*) l6, vader_ref_box(l9));
                t2 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t2;
                goto loop_220;
            } else {
            }
        }
    }
    vader_array_t* _a20_arr = vader_array_new(72u, 0u, 13u, 803u);
    l9 = (void*) _a20_arr;
    l3 = ((vader_array_t*) ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_params)->length;
    vader_array_t* _a21_arr = vader_array_repeat((vader_array_t*) l9, (size_t) l3);
    l9 = (void*) _a21_arr;
    l12 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_params;
    l3 = ((vader_array_t*) l12)->length;
    l5 = (size_t) (int64_t) INT64_C(0);
    {
        loop_282: {
            if ((l5 < l3)) {
                vader_array_t* _a22_slotarr = ((vader_array_t*) l12);
                if (_a22_slotarr->buf != NULL && _a22_slotarr->buf->header.forward != NULL) { _a22_slotarr->buf = vader_array_buf_forward(_a22_slotarr->buf); }
                if ((size_t) l5 >= _a22_slotarr->length) { vader_trap("array index out of bounds"); }
                l16 = vader_array_ref_load_obj(_a22_slotarr->buf, _a22_slotarr->offset + (size_t) l5);
                l22 = ((vader_struct_vader_midir_CFGParam_t*) l16)->f_name;
                l19 = ((vader_struct_vader_midir_CFGParam_t*) l16)->f_symbol;
                l1 = ((vader_struct_vader_midir_CFGParam_t*) l16)->f_type;
                t2 = ((int64_t) (int32_t) ((vader_struct_vader_midir_CFGParam_t*) l16)->f_local);
                l7 = (size_t) (int64_t) t2;
                vader_array_t* _a23_slotarr = ((vader_array_t*) l2);
                if (_a23_slotarr->buf != NULL && _a23_slotarr->buf->header.forward != NULL) { _a23_slotarr->buf = vader_array_buf_forward(_a23_slotarr->buf); }
                if ((size_t) l7 >= _a23_slotarr->length) { vader_trap("array index out of bounds"); }
                l14 = ((int32_t*) _a23_slotarr->buf->slots)[_a23_slotarr->offset + (size_t) l7];
                vader_struct_vader_midir_CFGParam_t* _a24_obj = (vader_struct_vader_midir_CFGParam_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_CFGParam_t));
                vader_obj_header_init(_a24_obj, 803u);
                _a24_obj->f_name = l22;
                _a24_obj->f_symbol = l19;
                _a24_obj->f_type = l1;
                _a24_obj->f_local = l14;
                l23 = (void*) _a24_obj;
                vader_array_push((vader_array_t*) l9, vader_ref_box(l23));
                t2 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t2;
                goto loop_282;
            } else {
            }
        }
    }
    vader_array_t* _a25_arr = vader_array_new(67u, 0u, 13u, 798u);
    l12 = (void*) _a25_arr;
    l3 = ((vader_array_t*) ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_blocks)->length;
    vader_array_t* _a26_arr = vader_array_repeat((vader_array_t*) l12, (size_t) l3);
    l12 = (void*) _a26_arr;
    l16 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_blocks;
    l3 = ((vader_array_t*) l16)->length;
    l5 = (size_t) (int64_t) INT64_C(0);
    {
        loop_339: {
            if ((l5 < l3)) {
                vader_array_t* _a27_slotarr = ((vader_array_t*) l16);
                if (_a27_slotarr->buf != NULL && _a27_slotarr->buf->header.forward != NULL) { _a27_slotarr->buf = vader_array_buf_forward(_a27_slotarr->buf); }
                if ((size_t) l5 >= _a27_slotarr->length) { vader_trap("array index out of bounds"); }
                l19 = vader_array_ref_load_obj(_a27_slotarr->buf, _a27_slotarr->offset + (size_t) l5);
                vader_array_t* _a28_arr = vader_array_new(127u, 0u, 13u, 1157u);
                l23 = (void*) _a28_arr;
                l7 = ((vader_array_t*) ((vader_struct_vader_midir_BasicBlock_t*) l19)->f_instructions)->length;
                vader_array_t* _a29_arr = vader_array_repeat((vader_array_t*) l23, (size_t) l7);
                l24 = (void*) _a29_arr;
                l25 = ((vader_struct_vader_midir_BasicBlock_t*) l19)->f_instructions;
                l8 = ((vader_array_t*) l25)->length;
                l10 = (size_t) (int64_t) INT64_C(0);
                {
                    loop_364: {
                        if ((l10 < l8)) {
                            vader_array_t* _a30_slotarr = ((vader_array_t*) l25);
                            if (_a30_slotarr->buf != NULL && _a30_slotarr->buf->header.forward != NULL) { _a30_slotarr->buf = vader_array_buf_forward(_a30_slotarr->buf); }
                            if ((size_t) l10 >= _a30_slotarr->length) { vader_trap("array index out of bounds"); }
                            l1 = vader_array_ref_load_box(_a30_slotarr->buf, _a30_slotarr->offset + (size_t) l10);
                            l4 = vader_midir_dst_of(l1);
                            if (l4.tag == 163u) {
                                l14 = ((int32_t) l4.payload.i);
                                t2 = ((int64_t) (int32_t) l14);
                                l15 = (size_t) (int64_t) t2;
                                l17 = ((vader_array_t*) l2)->length;
                                if ((l15 < l17)) {
                                    t2 = ((int64_t) (int32_t) l14);
                                    l26 = (size_t) (int64_t) t2;
                                    vader_array_t* _a31_slotarr = ((vader_array_t*) l2);
                                    if (_a31_slotarr->buf != NULL && _a31_slotarr->buf->header.forward != NULL) { _a31_slotarr->buf = vader_array_buf_forward(_a31_slotarr->buf); }
                                    if ((size_t) l26 >= _a31_slotarr->length) { vader_trap("array index out of bounds"); }
                                    t5 = ((int32_t*) _a31_slotarr->buf->slots)[_a31_slotarr->offset + (size_t) l26];
                                    l20 = (t5 < INT32_C(0));
                                } else {
                                    l20 = false;
                                }
                                if (l20) {
                                    t3 = vader_midir_instruction_has_side_effect(l1);
                                    if (!(t3)) {
                                        t2 = (l10 + INT64_C(1));
                                        l10 = (size_t) (int64_t) t2;
                                        goto loop_364;
                                    }
                                    l11 = vader_midir_remap_instr(l1, l2);
                                    vader_array_push((vader_array_t*) l24, l11);
                                    l27 = (size_t) (int64_t) INT64_C(1);
                                    t2 = (l10 + l27);
                                    l10 = (size_t) (int64_t) t2;
                                    goto loop_364;
                                }
                                l11 = vader_midir_remap_instr(l1, l2);
                                vader_array_push((vader_array_t*) l24, l11);
                                l27 = (size_t) (int64_t) INT64_C(1);
                                t2 = (l10 + l27);
                                l10 = (size_t) (int64_t) t2;
                                goto loop_364;
                            }
                            l11 = vader_midir_remap_instr(l1, l2);
                            vader_array_push((vader_array_t*) l24, l11);
                            l27 = (size_t) (int64_t) INT64_C(1);
                            t2 = (l10 + l27);
                            l10 = (size_t) (int64_t) t2;
                            goto loop_364;
                        } else {
                        }
                    }
                }
                l21 = ((vader_struct_vader_midir_BasicBlock_t*) l19)->f_id;
                l13 = vader_midir_remap_terminator(((vader_struct_vader_midir_BasicBlock_t*) l19)->f_terminator, l2);
                l28 = ((vader_struct_vader_midir_BasicBlock_t*) l19)->f_span;
                vader_struct_vader_midir_BasicBlock_t* _a32_obj = (vader_struct_vader_midir_BasicBlock_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_BasicBlock_t));
                vader_obj_header_init(_a32_obj, 798u);
                _a32_obj->f_id = l21;
                _a32_obj->f_instructions = l24;
                _a32_obj->f_terminator = l13;
                _a32_obj->f_span = l28;
                l29 = (void*) _a32_obj;
                vader_array_push((vader_array_t*) l12, vader_ref_box(l29));
                t2 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t2;
                goto loop_339;
            } else {
            }
        }
    }
    l22 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_mangled;
    l1 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_return_type;
    l14 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_entry;
    l2 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_origin;
    l30 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_extern_name;
    l20 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_is_extern;
    l31 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_is_exported;
    vader_struct_vader_midir_CFGFunction_t* _a33_obj = (vader_struct_vader_midir_CFGFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_CFGFunction_t));
    vader_obj_header_init(_a33_obj, 800u);
    _a33_obj->f_mangled = l22;
    _a33_obj->f_params = l9;
    _a33_obj->f_return_type = l1;
    _a33_obj->f_locals = l6;
    _a33_obj->f_blocks = l12;
    _a33_obj->f_entry = l14;
    _a33_obj->f_origin = l2;
    _a33_obj->f_extern_name = l30;
    _a33_obj->f_is_extern = l20;
    _a33_obj->f_is_exported = l31;
    t1 = (void*) _a33_obj;
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
    void* l32 = NULL;
    void* l33 = NULL;
    size_t l8, l9, l20, l21, l26, l27, l34, l35;
    int32_t l10, l11, l22, l24, l29, l31, l36;
    vader_box_t l13 = vader_box_null(), l28 = vader_box_null();
    void* t0 = NULL;
    size_t t1;
    int64_t t2;
    vader_box_t t3 = vader_box_null();
    bool t4;
    vader_box_t* gc_roots[3] = { &l13, &l28, &t3 };
    void** gc_raw_roots[21] = { &l0, &l1, &l2, &l3, &l4, &l5, &l6, &l7, &l12, &l14, &l15, &l16, &l17, &l18, &l19, &l23, &l25, &l30, &l32, &l33, &t0 };
    vader_struct___Tuple_1282_t _a7_storage = {0};
    void* gc_stack_objs[1] = { (void*) &_a7_storage };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 21u, gc_roots, gc_raw_roots, 1u, gc_stack_objs };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(9u, 0u, 7u, 163u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(6u, 0u, 12u, 159u);
    l3 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 163u);
    l4 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__i32__bool_t* _a3_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
    vader_obj_header_init(_a3_obj, 310u);
    _a3_obj->f_ekeys = l2;
    _a3_obj->f_evals = l3;
    _a3_obj->f_index = l4;
    _a3_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    t0 = (void*) _a3_obj;
    vader_struct_std_collections_MutableSet__i32_t* _a4_obj = (vader_struct_std_collections_MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i32_t));
    vader_obj_header_init(_a4_obj, 387u);
    _a4_obj->f_inner = t0;
    l2 = (void*) _a4_obj;
    l3 = vader_midir_predecessors_of(l0);
    l4 = vader_midir_compute_dominators(l0, l3);
    l3 = vader_midir_natural_loop_bodies(l0, l3, l4);
    t1 = ((vader_struct_std_collections_MutableMap__i32__MutableSet_i32__t*) l3)->f_size;
    if (t1 == INT64_C(0)) {
        { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = vader_midir_compute_liveness(l0);
    l5 = l3;
    l6 = ((vader_struct_std_collections_MutableMap__i32__MutableSet_i32__t*) l5)->f_ekeys;
    l7 = ((vader_struct_std_collections_MutableMap__i32__MutableSet_i32__t*) l5)->f_evals;
    l8 = ((vader_struct_std_collections_MutableMap__i32__MutableSet_i32__t*) l5)->f_size;
    l9 = (size_t) (int64_t) INT64_C(0);
    {
        loop_50: {
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
                vader_struct___Tuple_1282_t* _a8_obj = &_a7_storage;
                vader_obj_header_init(_a8_obj, 218u);
                _a8_obj->f__0 = l10;
                _a8_obj->f__1 = l5;
                t0 = (void*) _a8_obj;
                l11 = ((vader_struct___Tuple_1282_t*) t0)->f__0;
                t2 = (l9 + INT64_C(1));
                l9 = (size_t) (int64_t) t2;
                l13 = std_collections_get__i32__Any(l3, l11);
                if (l13.tag == 0u) {
                    goto loop_50;
                }
                l12 = l13.payload.obj;
                vader_array_t* _a9_arr = vader_array_new(9u, 0u, 7u, 163u);
                l14 = (void*) _a9_arr;
                vader_array_t* _a10_arr = vader_array_new(6u, 0u, 12u, 159u);
                l15 = (void*) _a10_arr;
                vader_array_t* _a11_arr = vader_array_new(9u, 0u, 7u, 163u);
                l16 = (void*) _a11_arr;
                vader_struct_std_collections_MutableMap__i32__bool_t* _a12_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
                vader_obj_header_init(_a12_obj, 310u);
                _a12_obj->f_ekeys = l14;
                _a12_obj->f_evals = l15;
                _a12_obj->f_index = l16;
                _a12_obj->f_mask = (size_t) (int64_t) INT64_C(0);
                _a12_obj->f_size = (size_t) (int64_t) INT64_C(0);
                _a12_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
                t0 = (void*) _a12_obj;
                vader_struct_std_collections_MutableSet__i32_t* _a13_obj = (vader_struct_std_collections_MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i32_t));
                vader_obj_header_init(_a13_obj, 387u);
                _a13_obj->f_inner = t0;
                l17 = (void*) _a13_obj;
                l18 = l12;
                l19 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) ((vader_struct_std_collections_MutableSet__i32_t*) l18)->f_inner)->f_ekeys;
                l20 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) ((vader_struct_std_collections_MutableSet__i32_t*) l18)->f_inner)->f_size;
                l21 = (size_t) (int64_t) INT64_C(0);
                {
                    loop_111: {
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
                                loop_139: {
                                    if ((l27 < l26)) {
                                        vader_array_t* _a16_slotarr = ((vader_array_t*) l25);
                                        if (_a16_slotarr->buf != NULL && _a16_slotarr->buf->header.forward != NULL) { _a16_slotarr->buf = vader_array_buf_forward(_a16_slotarr->buf); }
                                        if ((size_t) l27 >= _a16_slotarr->length) { vader_trap("array index out of bounds"); }
                                        t3 = vader_array_ref_load_box(_a16_slotarr->buf, _a16_slotarr->offset + (size_t) l27);
                                        l28 = vader_midir_dst_of(t3);
                                        if (!(l28.tag == 0u)) {
                                            l29 = ((int32_t) l28.payload.i);
                                            std_collections_add__i32(l17, l29);
                                        } else {
                                        }
                                        t2 = (l27 + INT64_C(1));
                                        l27 = (size_t) (int64_t) t2;
                                        goto loop_139;
                                    } else {
                                    }
                                }
                            }
                            goto loop_111;
                        }
                    }
                }
                l30 = ((vader_struct_vader_midir_Liveness_t*) l4)->f_live_in;
                l31 = l11;
                vader_array_t* _a17_slotarr = ((vader_array_t*) l30);
                if (_a17_slotarr->buf != NULL && _a17_slotarr->buf->header.forward != NULL) { _a17_slotarr->buf = vader_array_buf_forward(_a17_slotarr->buf); }
                if ((size_t) l31 >= _a17_slotarr->length) { vader_trap("array index out of bounds"); }
                l32 = vader_array_ref_load_obj(_a17_slotarr->buf, _a17_slotarr->offset + (size_t) l31);
                l33 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) ((vader_struct_std_collections_MutableSet__i32_t*) l32)->f_inner)->f_ekeys;
                l34 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) ((vader_struct_std_collections_MutableSet__i32_t*) l32)->f_inner)->f_size;
                l35 = (size_t) (int64_t) INT64_C(0);
                {
                    loop_192: {
                        if ((l35 >= l34)) {
                        } else {
                            vader_array_t* _a18_slotarr = ((vader_array_t*) l33);
                            if (_a18_slotarr->buf != NULL && _a18_slotarr->buf->header.forward != NULL) { _a18_slotarr->buf = vader_array_buf_forward(_a18_slotarr->buf); }
                            if ((size_t) l35 >= _a18_slotarr->length) { vader_trap("array index out of bounds"); }
                            l36 = ((int32_t*) _a18_slotarr->buf->slots)[_a18_slotarr->offset + (size_t) l35];
                            t2 = (l35 + INT64_C(1));
                            l35 = (size_t) (int64_t) t2;
                            t4 = std_collections_contains_key__i32__bool(((vader_struct_std_collections_MutableSet__i32_t*) l17)->f_inner, l36);
                            if (t4) {
                                std_collections_add__i32(l2, l36);
                            } else {
                            }
                            goto loop_192;
                        }
                    }
                }
                goto loop_50;
            }
        }
    }
    vader_array_t* _a19_arr = vader_array_new(9u, 0u, 7u, 163u);
    l3 = (void*) _a19_arr;
    l4 = l2;
    l5 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) ((vader_struct_std_collections_MutableSet__i32_t*) l4)->f_inner)->f_ekeys;
    l8 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) ((vader_struct_std_collections_MutableSet__i32_t*) l4)->f_inner)->f_size;
    l9 = (size_t) (int64_t) INT64_C(0);
    {
        loop_238: {
            if ((l9 >= l8)) {
            } else {
                vader_array_t* _a20_slotarr = ((vader_array_t*) l5);
                if (_a20_slotarr->buf != NULL && _a20_slotarr->buf->header.forward != NULL) { _a20_slotarr->buf = vader_array_buf_forward(_a20_slotarr->buf); }
                if ((size_t) l9 >= _a20_slotarr->length) { vader_trap("array index out of bounds"); }
                l10 = ((int32_t*) _a20_slotarr->buf->slots)[_a20_slotarr->offset + (size_t) l9];
                t2 = (l9 + INT64_C(1));
                l9 = (size_t) (int64_t) t2;
                vader_array_push_i32((vader_array_t*) l3, l10);
                goto loop_238;
            }
        }
    }
    {
        loop_260: {
            t1 = ((vader_array_t*) l3)->length;
            if ((t1 > INT64_C(0))) {
                t1 = ((vader_array_t*) l3)->length;
                t2 = (t1 - INT64_C(1));
                l8 = (size_t) (int64_t) t2;
                vader_array_t* _a21_slotarr = ((vader_array_t*) l3);
                if (_a21_slotarr->buf != NULL && _a21_slotarr->buf->header.forward != NULL) { _a21_slotarr->buf = vader_array_buf_forward(_a21_slotarr->buf); }
                if ((size_t) l8 >= _a21_slotarr->length) { vader_trap("array index out of bounds"); }
                l10 = ((int32_t*) _a21_slotarr->buf->slots)[_a21_slotarr->offset + (size_t) l8];
                t1 = ((vader_array_t*) l3)->length;
                t2 = (t1 - INT64_C(1));
                l9 = (size_t) (int64_t) t2;
                vader_array_t* _a22_arr = vader_array_slice((vader_array_t*) l3, (size_t) INT64_C(0), (size_t) l9);
                l3 = (void*) _a22_arr;
                l13 = std_collections_get__i32__Any(l1, l10);
                if (!(l13.tag == 0u)) {
                    l4 = l13.payload.obj;
                    l20 = ((vader_array_t*) l4)->length;
                    l21 = (size_t) (int64_t) INT64_C(0);
                    {
                        loop_300: {
                            if ((l21 < l20)) {
                                vader_array_t* _a23_slotarr = ((vader_array_t*) l4);
                                if (_a23_slotarr->buf != NULL && _a23_slotarr->buf->header.forward != NULL) { _a23_slotarr->buf = vader_array_buf_forward(_a23_slotarr->buf); }
                                if ((size_t) l21 >= _a23_slotarr->length) { vader_trap("array index out of bounds"); }
                                l11 = ((int32_t*) _a23_slotarr->buf->slots)[_a23_slotarr->offset + (size_t) l21];
                                t4 = std_collections_contains_key__i32__bool(((vader_struct_std_collections_MutableSet__i32_t*) l2)->f_inner, l11);
                                if (t4) {
                                    t2 = (l21 + INT64_C(1));
                                    l21 = (size_t) (int64_t) t2;
                                    goto loop_300;
                                }
                                std_collections_add__i32(l2, l11);
                                vader_array_push_i32((vader_array_t*) l3, l11);
                                t2 = (l21 + INT64_C(1));
                                l21 = (size_t) (int64_t) t2;
                                goto loop_300;
                            } else {
                            }
                        }
                    }
                } else {
                }
                goto loop_260;
            } else {
            }
        }
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_midir_compute_dominators(void* l0, void* l1) {
    size_t l2, l9, l14, l15;
    void* l3 = NULL;
    void* l6 = NULL;
    void* l8 = NULL;
    void* l13 = NULL;
    int32_t l4, l5, l10, l11, l12, l16, l17, l18, l19, l20, l21, l22, l24, l25;
    bool l7, l23;
    void* t0 = NULL;
    int64_t t1;
    int32_t t2;
    void** gc_raw_roots[7] = { &l0, &l1, &l3, &l6, &l8, &l13, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 7u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_array_t*) ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_blocks)->length;
    vader_array_t* _a0_arr = vader_array_new(9u, 1u, 7u, 163u);
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
                            l5 = l4;
                            l10 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_entry;
                            if (l5 == l10) {
                                t1 = (l9 + INT64_C(1));
                                l9 = (size_t) (int64_t) t1;
                                goto loop_35;
                            }
                            l11 = -(INT32_C(1));
                            l12 = l4;
                            vader_array_t* _a4_slotarr = ((vader_array_t*) l1);
                            if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                            if ((size_t) l12 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                            l13 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l12);
                            l14 = ((vader_array_t*) l13)->length;
                            l15 = (size_t) (int64_t) INT64_C(0);
                            {
                                loop_71: {
                                    if ((l15 < l14)) {
                                        vader_array_t* _a5_slotarr = ((vader_array_t*) l13);
                                        if (_a5_slotarr->buf != NULL && _a5_slotarr->buf->header.forward != NULL) { _a5_slotarr->buf = vader_array_buf_forward(_a5_slotarr->buf); }
                                        if ((size_t) l15 >= _a5_slotarr->length) { vader_trap("array index out of bounds"); }
                                        l16 = ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l15];
                                        l17 = l16;
                                        vader_array_t* _a6_slotarr = ((vader_array_t*) l3);
                                        if (_a6_slotarr->buf != NULL && _a6_slotarr->buf->header.forward != NULL) { _a6_slotarr->buf = vader_array_buf_forward(_a6_slotarr->buf); }
                                        if ((size_t) l17 >= _a6_slotarr->length) { vader_trap("array index out of bounds"); }
                                        l18 = ((int32_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l17];
                                        l19 = -(INT32_C(1));
                                        if (l18 == l19) {
                                            t1 = (l15 + INT64_C(1));
                                            l15 = (size_t) (int64_t) t1;
                                            goto loop_71;
                                        }
                                        l20 = -(INT32_C(1));
                                        if (l11 == l20) {
                                            l11 = l16;
                                        } else {
                                            l21 = l11;
                                            l11 = vader_midir_intersect_dom_tree(l16, l21, l3);
                                        }
                                        t1 = (l15 + INT64_C(1));
                                        l15 = (size_t) (int64_t) t1;
                                        goto loop_71;
                                    } else {
                                    }
                                }
                            }
                            l22 = -(INT32_C(1));
                            if (l11 != l22) {
                                l24 = l4;
                                vader_array_t* _a7_slotarr = ((vader_array_t*) l3);
                                if (_a7_slotarr->buf != NULL && _a7_slotarr->buf->header.forward != NULL) { _a7_slotarr->buf = vader_array_buf_forward(_a7_slotarr->buf); }
                                if ((size_t) l24 >= _a7_slotarr->length) { vader_trap("array index out of bounds"); }
                                t2 = ((int32_t*) _a7_slotarr->buf->slots)[_a7_slotarr->offset + (size_t) l24];
                                l23 = t2 != l11;
                            } else {
                                l23 = false;
                            }
                            if (l23) {
                                l25 = l4;
                                vader_array_t* _a8_slotarr = ((vader_array_t*) l3);
                                if (_a8_slotarr->buf != NULL && _a8_slotarr->buf->header.forward != NULL) { _a8_slotarr->buf = vader_array_buf_forward(_a8_slotarr->buf); }
                                if ((size_t) l25 >= _a8_slotarr->length) { vader_trap("array index out of bounds"); }
                                ((int32_t*) _a8_slotarr->buf->slots)[_a8_slotarr->offset + (size_t) l25] = (int32_t) l11;
                                l7 = true;
                            } else {
                            }
                            t1 = (l9 + INT64_C(1));
                            l9 = (size_t) (int64_t) t1;
                            goto loop_35;
                        } else {
                        }
                    }
                }
                goto loop_23;
            } else {
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
    void* l13 = NULL;
    void* l16 = NULL;
    void* l20 = NULL;
    void* l23 = NULL;
    void* l26 = NULL;
    void* l31 = NULL;
    void* l34 = NULL;
    void* l38 = NULL;
    void* l40 = NULL;
    void* l44 = NULL;
    void* l46 = NULL;
    void* l50 = NULL;
    void* l55 = NULL;
    void* l56 = NULL;
    void* l61 = NULL;
    void* l62 = NULL;
    void* l70 = NULL;
    size_t l7, l8, l10, l11, l35, l36, l41, l42, l47, l48, l51, l52, l57, l58, l63, l64;
    vader_box_t l12 = vader_box_null(), l67 = vader_box_null();
    int32_t l14, l15, l17, l18, l19, l21, l22, l24, l25, l27, l28, l29, l30, l32, l33, l37, l39, l43, l45, l49, l53, l54, l59, l60, l65, l66, l68, l69, l71;
    void* t0 = NULL;
    int64_t t1;
    bool t2;
    vader_box_t t3 = vader_box_null();
    size_t t4;
    vader_box_t* gc_roots[3] = { &l12, &l67, &t3 };
    void** gc_raw_roots[26] = { &l0, &l1, &l2, &l3, &l4, &l5, &l6, &l9, &l13, &l16, &l20, &l23, &l26, &l31, &l34, &l38, &l40, &l44, &l46, &l50, &l55, &l56, &l61, &l62, &l70, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 26u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(9u, 0u, 7u, 163u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(6u, 0u, 12u, 159u);
    l3 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 163u);
    l4 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__i32__bool_t* _a3_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
    vader_obj_header_init(_a3_obj, 310u);
    _a3_obj->f_ekeys = l2;
    _a3_obj->f_evals = l3;
    _a3_obj->f_index = l4;
    _a3_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    t0 = (void*) _a3_obj;
    vader_struct_std_collections_MutableSet__i32_t* _a4_obj = (vader_struct_std_collections_MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i32_t));
    vader_obj_header_init(_a4_obj, 387u);
    _a4_obj->f_inner = t0;
    l2 = (void*) _a4_obj;
    vader_array_t* _a5_arr = vader_array_new(9u, 0u, 7u, 163u);
    l3 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(15u, 0u, 0u, 170u);
    l4 = (void*) _a6_arr;
    vader_array_t* _a7_arr = vader_array_new(9u, 0u, 7u, 163u);
    l5 = (void*) _a7_arr;
    vader_struct_std_collections_MutableMap__i32__Any___t* _a8_obj = (vader_struct_std_collections_MutableMap__i32__Any___t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__Any___t));
    vader_obj_header_init(_a8_obj, 277u);
    _a8_obj->f_ekeys = l3;
    _a8_obj->f_evals = l4;
    _a8_obj->f_index = l5;
    _a8_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a8_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a8_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l3 = (void*) _a8_obj;
    vader_array_t* _a9_arr = vader_array_new(9u, 0u, 7u, 163u);
    l4 = (void*) _a9_arr;
    vader_array_t* _a10_arr = vader_array_new(15u, 0u, 0u, 170u);
    l5 = (void*) _a10_arr;
    vader_array_t* _a11_arr = vader_array_new(9u, 0u, 7u, 163u);
    l6 = (void*) _a11_arr;
    vader_struct_std_collections_MutableMap__i32__Any___t* _a12_obj = (vader_struct_std_collections_MutableMap__i32__Any___t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__Any___t));
    vader_obj_header_init(_a12_obj, 277u);
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
                            if (l12.tag == 840u) {
                                l13 = l12.payload.obj;
                                l14 = ((vader_struct_vader_midir_InstrMove_t*) l13)->f_dst;
                                l15 = ((vader_struct_vader_midir_InstrMove_t*) l13)->f_src;
                                vader_midir_record_alias(l3, l4, l14, l15);
                            } else {
                                if (l12.tag == 827u) {
                                    l16 = l12.payload.obj;
                                    l17 = ((vader_struct_vader_midir_InstrCast_t*) l16)->f_dst;
                                    l18 = ((vader_struct_vader_midir_InstrCast_t*) l16)->f_value;
                                    vader_midir_record_alias(l3, l4, l17, l18);
                                } else {
                                    if (l12.tag == 836u) {
                                        t0 = l12.payload.obj;
                                        l19 = ((vader_struct_vader_midir_InstrFieldSet_t*) t0)->f_value;
                                        std_collections_add__i32(l2, l19);
                                    } else {
                                        if (l12.tag == 822u) {
                                            l20 = l12.payload.obj;
                                            l21 = ((vader_struct_vader_midir_InstrArraySet_t*) l20)->f_value;
                                            std_collections_add__i32(l2, l21);
                                            l22 = ((vader_struct_vader_midir_InstrArraySet_t*) l20)->f_target;
                                            std_collections_add__i32(l2, l22);
                                        } else {
                                            if (l12.tag == 821u) {
                                                l23 = l12.payload.obj;
                                                l24 = ((vader_struct_vader_midir_InstrArrayPush_t*) l23)->f_value;
                                                std_collections_add__i32(l2, l24);
                                                l25 = ((vader_struct_vader_midir_InstrArrayPush_t*) l23)->f_target;
                                                std_collections_add__i32(l2, l25);
                                            } else {
                                                if (l12.tag == 823u) {
                                                    l26 = l12.payload.obj;
                                                    l27 = ((vader_struct_vader_midir_InstrArraySlice_t*) l26)->f_target;
                                                    std_collections_add__i32(l2, l27);
                                                    l28 = ((vader_struct_vader_midir_InstrArraySlice_t*) l26)->f_lo;
                                                    std_collections_add__i32(l2, l28);
                                                    l29 = ((vader_struct_vader_midir_InstrArraySlice_t*) l26)->f_hi;
                                                    std_collections_add__i32(l2, l29);
                                                } else {
                                                    if (l12.tag == 829u) {
                                                        t0 = l12.payload.obj;
                                                        l30 = ((vader_struct_vader_midir_InstrCellNew_t*) t0)->f_value;
                                                        std_collections_add__i32(l2, l30);
                                                    } else {
                                                        if (l12.tag == 830u) {
                                                            l31 = l12.payload.obj;
                                                            l32 = ((vader_struct_vader_midir_InstrCellSet_t*) l31)->f_value;
                                                            std_collections_add__i32(l2, l32);
                                                            l33 = ((vader_struct_vader_midir_InstrCellSet_t*) l31)->f_cell;
                                                            std_collections_add__i32(l2, l33);
                                                        } else {
                                                            if (l12.tag == 825u) {
                                                                t0 = l12.payload.obj;
                                                                l34 = ((vader_struct_vader_midir_InstrCall_t*) t0)->f_args;
                                                                l35 = ((vader_array_t*) l34)->length;
                                                                l36 = (size_t) (int64_t) INT64_C(0);
                                                                {
                                                                    loop_224: {
                                                                        if ((l36 < l35)) {
                                                                            vader_array_t* _a15_slotarr = ((vader_array_t*) l34);
                                                                            if (_a15_slotarr->buf != NULL && _a15_slotarr->buf->header.forward != NULL) { _a15_slotarr->buf = vader_array_buf_forward(_a15_slotarr->buf); }
                                                                            if ((size_t) l36 >= _a15_slotarr->length) { vader_trap("array index out of bounds"); }
                                                                            l37 = ((int32_t*) _a15_slotarr->buf->slots)[_a15_slotarr->offset + (size_t) l36];
                                                                            std_collections_add__i32(l2, l37);
                                                                            t1 = (l36 + INT64_C(1));
                                                                            l36 = (size_t) (int64_t) t1;
                                                                            goto loop_224;
                                                                        } else {
                                                                        }
                                                                    }
                                                                }
                                                            } else {
                                                                if (l12.tag == 826u) {
                                                                    l38 = l12.payload.obj;
                                                                    l39 = ((vader_struct_vader_midir_InstrCallIndirect_t*) l38)->f_callee;
                                                                    std_collections_add__i32(l2, l39);
                                                                    l40 = ((vader_struct_vader_midir_InstrCallIndirect_t*) l38)->f_args;
                                                                    l41 = ((vader_array_t*) l40)->length;
                                                                    l42 = (size_t) (int64_t) INT64_C(0);
                                                                    {
                                                                        loop_266: {
                                                                            if ((l42 < l41)) {
                                                                                vader_array_t* _a16_slotarr = ((vader_array_t*) l40);
                                                                                if (_a16_slotarr->buf != NULL && _a16_slotarr->buf->header.forward != NULL) { _a16_slotarr->buf = vader_array_buf_forward(_a16_slotarr->buf); }
                                                                                if ((size_t) l42 >= _a16_slotarr->length) { vader_trap("array index out of bounds"); }
                                                                                l43 = ((int32_t*) _a16_slotarr->buf->slots)[_a16_slotarr->offset + (size_t) l42];
                                                                                std_collections_add__i32(l2, l43);
                                                                                t1 = (l42 + INT64_C(1));
                                                                                l42 = (size_t) (int64_t) t1;
                                                                                goto loop_266;
                                                                            } else {
                                                                            }
                                                                        }
                                                                    }
                                                                } else {
                                                                    if (l12.tag == 846u) {
                                                                        l44 = l12.payload.obj;
                                                                        l45 = ((vader_struct_vader_midir_InstrVirtualCall_t*) l44)->f_receiver;
                                                                        std_collections_add__i32(l2, l45);
                                                                        l46 = ((vader_struct_vader_midir_InstrVirtualCall_t*) l44)->f_args;
                                                                        l47 = ((vader_array_t*) l46)->length;
                                                                        l48 = (size_t) (int64_t) INT64_C(0);
                                                                        {
                                                                            loop_308: {
                                                                                if ((l48 < l47)) {
                                                                                    vader_array_t* _a17_slotarr = ((vader_array_t*) l46);
                                                                                    if (_a17_slotarr->buf != NULL && _a17_slotarr->buf->header.forward != NULL) { _a17_slotarr->buf = vader_array_buf_forward(_a17_slotarr->buf); }
                                                                                    if ((size_t) l48 >= _a17_slotarr->length) { vader_trap("array index out of bounds"); }
                                                                                    l49 = ((int32_t*) _a17_slotarr->buf->slots)[_a17_slotarr->offset + (size_t) l48];
                                                                                    std_collections_add__i32(l2, l49);
                                                                                    t1 = (l48 + INT64_C(1));
                                                                                    l48 = (size_t) (int64_t) t1;
                                                                                    goto loop_308;
                                                                                } else {
                                                                                }
                                                                            }
                                                                        }
                                                                    } else {
                                                                        if (l12.tag == 838u) {
                                                                            t0 = l12.payload.obj;
                                                                            l50 = ((vader_struct_vader_midir_InstrIntrinsic_t*) t0)->f_args;
                                                                            l51 = ((vader_array_t*) l50)->length;
                                                                            l52 = (size_t) (int64_t) INT64_C(0);
                                                                            {
                                                                                loop_343: {
                                                                                    if ((l52 < l51)) {
                                                                                        vader_array_t* _a18_slotarr = ((vader_array_t*) l50);
                                                                                        if (_a18_slotarr->buf != NULL && _a18_slotarr->buf->header.forward != NULL) { _a18_slotarr->buf = vader_array_buf_forward(_a18_slotarr->buf); }
                                                                                        if ((size_t) l52 >= _a18_slotarr->length) { vader_trap("array index out of bounds"); }
                                                                                        l53 = ((int32_t*) _a18_slotarr->buf->slots)[_a18_slotarr->offset + (size_t) l52];
                                                                                        std_collections_add__i32(l2, l53);
                                                                                        t1 = (l52 + INT64_C(1));
                                                                                        l52 = (size_t) (int64_t) t1;
                                                                                        goto loop_343;
                                                                                    } else {
                                                                                    }
                                                                                }
                                                                            }
                                                                        } else {
                                                                            if (l12.tag == 839u) {
                                                                                t0 = l12.payload.obj;
                                                                                l54 = ((vader_struct_vader_midir_InstrMakeClosure_t*) t0)->f_env;
                                                                                std_collections_add__i32(l2, l54);
                                                                            } else {
                                                                                if (l12.tag == 842u) {
                                                                                    l55 = l12.payload.obj;
                                                                                    l56 = ((vader_struct_vader_midir_InstrStructNew_t*) l55)->f_fields;
                                                                                    l57 = ((vader_array_t*) l56)->length;
                                                                                    l58 = (size_t) (int64_t) INT64_C(0);
                                                                                    {
                                                                                        loop_391: {
                                                                                            if ((l58 < l57)) {
                                                                                                vader_array_t* _a19_slotarr = ((vader_array_t*) l56);
                                                                                                if (_a19_slotarr->buf != NULL && _a19_slotarr->buf->header.forward != NULL) { _a19_slotarr->buf = vader_array_buf_forward(_a19_slotarr->buf); }
                                                                                                if ((size_t) l58 >= _a19_slotarr->length) { vader_trap("array index out of bounds"); }
                                                                                                l59 = ((int32_t*) _a19_slotarr->buf->slots)[_a19_slotarr->offset + (size_t) l58];
                                                                                                l60 = ((vader_struct_vader_midir_InstrStructNew_t*) l55)->f_dst;
                                                                                                vader_midir_append_alias(l3, l60, l59);
                                                                                                t1 = (l58 + INT64_C(1));
                                                                                                l58 = (size_t) (int64_t) t1;
                                                                                                goto loop_391;
                                                                                            } else {
                                                                                            }
                                                                                        }
                                                                                    }
                                                                                } else {
                                                                                    if (l12.tag == 820u) {
                                                                                        l61 = l12.payload.obj;
                                                                                        l62 = ((vader_struct_vader_midir_InstrArrayNew_t*) l61)->f_elements;
                                                                                        l63 = ((vader_array_t*) l62)->length;
                                                                                        l64 = (size_t) (int64_t) INT64_C(0);
                                                                                        {
                                                                                            loop_429: {
                                                                                                if ((l64 < l63)) {
                                                                                                    vader_array_t* _a20_slotarr = ((vader_array_t*) l62);
                                                                                                    if (_a20_slotarr->buf != NULL && _a20_slotarr->buf->header.forward != NULL) { _a20_slotarr->buf = vader_array_buf_forward(_a20_slotarr->buf); }
                                                                                                    if ((size_t) l64 >= _a20_slotarr->length) { vader_trap("array index out of bounds"); }
                                                                                                    l65 = ((int32_t*) _a20_slotarr->buf->slots)[_a20_slotarr->offset + (size_t) l64];
                                                                                                    l66 = ((vader_struct_vader_midir_InstrArrayNew_t*) l61)->f_dst;
                                                                                                    vader_midir_append_alias(l3, l66, l65);
                                                                                                    t1 = (l64 + INT64_C(1));
                                                                                                    l64 = (size_t) (int64_t) t1;
                                                                                                    goto loop_429;
                                                                                                } else {
                                                                                                }
                                                                                            }
                                                                                        }
                                                                                    } else {
                                                                                        if ((l12.tag == 818u || l12.tag == 835u)) {
                                                                                            l67 = l12;
                                                                                            t0 = l67.payload.obj;
                                                                                            t2 = vader_midir_read_may_carry_ref(((vader_struct_vader_midir_InstrArrayGet_t*) t0)->f_type);
                                                                                            if (t2) {
                                                                                                t0 = l67.payload.obj;
                                                                                                l68 = ((vader_struct_vader_midir_InstrArrayGet_t*) t0)->f_dst;
                                                                                                t0 = l67.payload.obj;
                                                                                                l69 = ((vader_struct_vader_midir_InstrArrayGet_t*) t0)->f_target;
                                                                                                vader_midir_append_alias(l3, l68, l69);
                                                                                            } else {
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
                        } else {
                        }
                    }
                }
                if (((vader_struct_vader_midir_BasicBlock_t*) l6)->f_terminator.tag == 856u) {
                    l70 = ((vader_struct_vader_midir_BasicBlock_t*) l6)->f_terminator.payload.obj;
                    if (!(((vader_struct_vader_midir_TermReturn_t*) l70)->f_value.tag == 0u)) {
                        t3 = ((vader_struct_vader_midir_TermReturn_t*) l70)->f_value;
                        l71 = ((int32_t) t3.payload.i);
                        std_collections_add__i32(l2, l71);
                    } else {
                    }
                } else {
                }
                t1 = (l8 + INT64_C(1));
                l8 = (size_t) (int64_t) t1;
                goto loop_50;
            } else {
            }
        }
    }
    vader_array_t* _a21_arr = vader_array_new(9u, 0u, 7u, 163u);
    l5 = (void*) _a21_arr;
    l6 = l2;
    l9 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) ((vader_struct_std_collections_MutableSet__i32_t*) l6)->f_inner)->f_ekeys;
    l7 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) ((vader_struct_std_collections_MutableSet__i32_t*) l6)->f_inner)->f_size;
    l8 = (size_t) (int64_t) INT64_C(0);
    {
        loop_546: {
            if ((l8 >= l7)) {
            } else {
                vader_array_t* _a22_slotarr = ((vader_array_t*) l9);
                if (_a22_slotarr->buf != NULL && _a22_slotarr->buf->header.forward != NULL) { _a22_slotarr->buf = vader_array_buf_forward(_a22_slotarr->buf); }
                if ((size_t) l8 >= _a22_slotarr->length) { vader_trap("array index out of bounds"); }
                l14 = ((int32_t*) _a22_slotarr->buf->slots)[_a22_slotarr->offset + (size_t) l8];
                t1 = (l8 + INT64_C(1));
                l8 = (size_t) (int64_t) t1;
                vader_array_push_i32((vader_array_t*) l5, l14);
                goto loop_546;
            }
        }
    }
    {
        loop_568: {
            t4 = ((vader_array_t*) l5)->length;
            if ((t4 > INT64_C(0))) {
                t4 = ((vader_array_t*) l5)->length;
                t1 = (t4 - INT64_C(1));
                l7 = (size_t) (int64_t) t1;
                vader_array_t* _a23_slotarr = ((vader_array_t*) l5);
                if (_a23_slotarr->buf != NULL && _a23_slotarr->buf->header.forward != NULL) { _a23_slotarr->buf = vader_array_buf_forward(_a23_slotarr->buf); }
                if ((size_t) l7 >= _a23_slotarr->length) { vader_trap("array index out of bounds"); }
                l14 = ((int32_t*) _a23_slotarr->buf->slots)[_a23_slotarr->offset + (size_t) l7];
                t4 = ((vader_array_t*) l5)->length;
                t1 = (t4 - INT64_C(1));
                l8 = (size_t) (int64_t) t1;
                vader_array_t* _a24_arr = vader_array_slice((vader_array_t*) l5, (size_t) INT64_C(0), (size_t) l8);
                l5 = (void*) _a24_arr;
                l12 = std_collections_get__i32__Any(l3, l14);
                if (!(l12.tag == 0u)) {
                    l6 = l12.payload.obj;
                    l10 = ((vader_array_t*) l6)->length;
                    l11 = (size_t) (int64_t) INT64_C(0);
                    {
                        loop_608: {
                            if ((l11 < l10)) {
                                vader_array_t* _a25_slotarr = ((vader_array_t*) l6);
                                if (_a25_slotarr->buf != NULL && _a25_slotarr->buf->header.forward != NULL) { _a25_slotarr->buf = vader_array_buf_forward(_a25_slotarr->buf); }
                                if ((size_t) l11 >= _a25_slotarr->length) { vader_trap("array index out of bounds"); }
                                l15 = ((int32_t*) _a25_slotarr->buf->slots)[_a25_slotarr->offset + (size_t) l11];
                                t2 = std_collections_contains_key__i32__bool(((vader_struct_std_collections_MutableSet__i32_t*) l2)->f_inner, l15);
                                if (t2) {
                                    t1 = (l11 + INT64_C(1));
                                    l11 = (size_t) (int64_t) t1;
                                    goto loop_608;
                                }
                                std_collections_add__i32(l2, l15);
                                vader_array_push_i32((vader_array_t*) l5, l15);
                                t1 = (l11 + INT64_C(1));
                                l11 = (size_t) (int64_t) t1;
                                goto loop_608;
                            } else {
                            }
                        }
                    }
                } else {
                }
                goto loop_568;
            } else {
            }
        }
    }
    vader_array_t* _a26_arr = vader_array_new(9u, 0u, 7u, 163u);
    l5 = (void*) _a26_arr;
    vader_array_t* _a27_arr = vader_array_new(6u, 0u, 12u, 159u);
    l6 = (void*) _a27_arr;
    vader_array_t* _a28_arr = vader_array_new(9u, 0u, 7u, 163u);
    l9 = (void*) _a28_arr;
    vader_struct_std_collections_MutableMap__i32__bool_t* _a29_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
    vader_obj_header_init(_a29_obj, 310u);
    _a29_obj->f_ekeys = l5;
    _a29_obj->f_evals = l6;
    _a29_obj->f_index = l9;
    _a29_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a29_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a29_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    t0 = (void*) _a29_obj;
    vader_struct_std_collections_MutableSet__i32_t* _a30_obj = (vader_struct_std_collections_MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i32_t));
    vader_obj_header_init(_a30_obj, 387u);
    _a30_obj->f_inner = t0;
    l5 = (void*) _a30_obj;
    l6 = l1;
    l9 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) ((vader_struct_std_collections_MutableSet__i32_t*) l6)->f_inner)->f_ekeys;
    l7 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) ((vader_struct_std_collections_MutableSet__i32_t*) l6)->f_inner)->f_size;
    l8 = (size_t) (int64_t) INT64_C(0);
    {
        loop_677: {
            if ((l8 >= l7)) {
            } else {
                vader_array_t* _a31_slotarr = ((vader_array_t*) l9);
                if (_a31_slotarr->buf != NULL && _a31_slotarr->buf->header.forward != NULL) { _a31_slotarr->buf = vader_array_buf_forward(_a31_slotarr->buf); }
                if ((size_t) l8 >= _a31_slotarr->length) { vader_trap("array index out of bounds"); }
                l14 = ((int32_t*) _a31_slotarr->buf->slots)[_a31_slotarr->offset + (size_t) l8];
                t1 = (l8 + INT64_C(1));
                l8 = (size_t) (int64_t) t1;
                t2 = std_collections_contains_key__i32__bool(((vader_struct_std_collections_MutableSet__i32_t*) l2)->f_inner, l14);
                if (t2) {
                    std_collections_add__i32(l5, l14);
                } else {
                }
                goto loop_677;
            }
        }
    }
    vader_struct_vader_midir_EscapeResult_t* _a32_obj = (vader_struct_vader_midir_EscapeResult_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_EscapeResult_t));
    vader_obj_header_init(_a32_obj, 813u);
    _a32_obj->f_escaping = l5;
    _a32_obj->f_alias_of = l3;
    _a32_obj->f_alias_from = l4;
    t0 = (void*) _a32_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_midir_compute_liveness(void* l0) {
    size_t l1, l4, l15, l16, l27, l28, l30, l31, l33, l34;
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
    void* l23 = NULL;
    void* l24 = NULL;
    void* l25 = NULL;
    void* l36 = NULL;
    void* l37 = NULL;
    void* l38 = NULL;
    vader_box_t l9 = vader_box_null(), l13 = vader_box_null(), l17 = vader_box_null(), l19 = vader_box_null(), l22 = vader_box_null();
    int32_t l21, l29, l32, l35;
    bool l26;
    void* t0 = NULL;
    int64_t t1;
    bool t2;
    vader_box_t* gc_roots[5] = { &l9, &l13, &l17, &l19, &l22 };
    void** gc_raw_roots[20] = { &l0, &l2, &l3, &l5, &l6, &l7, &l8, &l10, &l11, &l12, &l14, &l18, &l20, &l23, &l24, &l25, &l36, &l37, &l38, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 5u, 20u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = ((vader_array_t*) ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_blocks)->length;
    vader_array_t* _a0_arr = vader_array_new(18u, 0u, 13u, 387u);
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (size_t) l1);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(18u, 0u, 13u, 387u);
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
                vader_array_t* _a5_arr = vader_array_new(9u, 0u, 7u, 163u);
                l6 = (void*) _a5_arr;
                vader_array_t* _a6_arr = vader_array_new(6u, 0u, 12u, 159u);
                l7 = (void*) _a6_arr;
                vader_array_t* _a7_arr = vader_array_new(9u, 0u, 7u, 163u);
                l8 = (void*) _a7_arr;
                vader_struct_std_collections_MutableMap__i32__bool_t* _a8_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
                vader_obj_header_init(_a8_obj, 310u);
                _a8_obj->f_ekeys = l6;
                _a8_obj->f_evals = l7;
                _a8_obj->f_index = l8;
                _a8_obj->f_mask = (size_t) (int64_t) INT64_C(0);
                _a8_obj->f_size = (size_t) (int64_t) INT64_C(0);
                _a8_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
                t0 = (void*) _a8_obj;
                vader_struct_std_collections_MutableSet__i32_t* _a9_obj = (vader_struct_std_collections_MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i32_t));
                vader_obj_header_init(_a9_obj, 387u);
                _a9_obj->f_inner = t0;
                t0 = (void*) _a9_obj;
                vader_struct__Cell_Struct_lib_std_collections_collections_vader_13537_i32__t* _a10_obj = (vader_struct__Cell_Struct_lib_std_collections_collections_vader_13537_i32__t*) vader_gc_alloc(sizeof(vader_struct__Cell_Struct_lib_std_collections_collections_vader_13537_i32__t));
                vader_obj_header_init(_a10_obj, 179u);
                _a10_obj->f_value = t0;
                t0 = (void*) _a10_obj;
                l9 = vader_ref_box(t0);
                vader_array_t* _a11_arr = vader_array_new(9u, 0u, 7u, 163u);
                l10 = (void*) _a11_arr;
                vader_array_t* _a12_arr = vader_array_new(6u, 0u, 12u, 159u);
                l11 = (void*) _a12_arr;
                vader_array_t* _a13_arr = vader_array_new(9u, 0u, 7u, 163u);
                l12 = (void*) _a13_arr;
                vader_struct_std_collections_MutableMap__i32__bool_t* _a14_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
                vader_obj_header_init(_a14_obj, 310u);
                _a14_obj->f_ekeys = l10;
                _a14_obj->f_evals = l11;
                _a14_obj->f_index = l12;
                _a14_obj->f_mask = (size_t) (int64_t) INT64_C(0);
                _a14_obj->f_size = (size_t) (int64_t) INT64_C(0);
                _a14_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
                t0 = (void*) _a14_obj;
                vader_struct_std_collections_MutableSet__i32_t* _a15_obj = (vader_struct_std_collections_MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i32_t));
                vader_obj_header_init(_a15_obj, 387u);
                _a15_obj->f_inner = t0;
                t0 = (void*) _a15_obj;
                vader_struct__Cell_Struct_lib_std_collections_collections_vader_13537_i32__t* _a16_obj = (vader_struct__Cell_Struct_lib_std_collections_collections_vader_13537_i32__t*) vader_gc_alloc(sizeof(vader_struct__Cell_Struct_lib_std_collections_collections_vader_13537_i32__t));
                vader_obj_header_init(_a16_obj, 179u);
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
                            vader_struct___lambda_env_2590_t* _a18_obj = (vader_struct___lambda_env_2590_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_2590_t));
                            vader_obj_header_init(_a18_obj, 240u);
                            _a18_obj->f_cap_0 = l13;
                            _a18_obj->f_cap_1 = l9;
                            t0 = (void*) _a18_obj;
                            vader_fn_t* _a19_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
                            vader_obj_header_init(_a19_closure, 138u);
                            _a19_closure->code = (void*) &vader_fn_lift_1775;
                            _a19_closure->env = t0;
                            l18 = (void*) _a19_closure;
                            vader_midir_for_each_read_local(l17, l18);
                            l19 = vader_midir_dst_of(l17);
                            if (!(l19.tag == 0u)) {
                                l20 = ((vader_struct__Cell_Struct_lib_std_collections_collections_vader_13537_i32__t*) l13.payload.obj)->f_value;
                                l21 = ((int32_t) l19.payload.i);
                                std_collections_add__i32(l20, l21);
                            } else {
                            }
                            t1 = (l16 + INT64_C(1));
                            l16 = (size_t) (int64_t) t1;
                            goto loop_62;
                        } else {
                        }
                    }
                }
                l22 = ((vader_struct_vader_midir_BasicBlock_t*) l5)->f_terminator;
                vader_struct___lambda_env_2593_t* _a20_obj = (vader_struct___lambda_env_2593_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_2593_t));
                vader_obj_header_init(_a20_obj, 241u);
                _a20_obj->f_cap_0 = l13;
                _a20_obj->f_cap_1 = l9;
                t0 = (void*) _a20_obj;
                vader_fn_t* _a21_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
                vader_obj_header_init(_a21_closure, 138u);
                _a21_closure->code = (void*) &vader_fn_lift_1776;
                _a21_closure->env = t0;
                l23 = (void*) _a21_closure;
                vader_midir_for_each_read_in_terminator(l22, l23);
                l24 = ((vader_struct__Cell_Struct_lib_std_collections_collections_vader_13537_i32__t*) l9.payload.obj)->f_value;
                vader_array_push((vader_array_t*) l2, vader_ref_box(l24));
                l25 = ((vader_struct__Cell_Struct_lib_std_collections_collections_vader_13537_i32__t*) l13.payload.obj)->f_value;
                vader_array_push((vader_array_t*) l3, vader_ref_box(l25));
                t1 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t1;
                goto loop_14;
            } else {
            }
        }
    }
    vader_array_t* _a22_arr = vader_array_new(2u, 0u, 13u, 9u);
    t0 = (void*) _a22_arr;
    vader_array_t* _a23_arr = vader_array_repeat((vader_array_t*) t0, (size_t) l1);
    l5 = (void*) _a23_arr;
    l6 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_blocks;
    l4 = ((vader_array_t*) l6)->length;
    l15 = (size_t) (int64_t) INT64_C(0);
    {
        loop_145: {
            if ((l15 < l4)) {
                vader_array_t* _a24_slotarr = ((vader_array_t*) l6);
                if (_a24_slotarr->buf != NULL && _a24_slotarr->buf->header.forward != NULL) { _a24_slotarr->buf = vader_array_buf_forward(_a24_slotarr->buf); }
                if ((size_t) l15 >= _a24_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_ref_load_obj(_a24_slotarr->buf, _a24_slotarr->offset + (size_t) l15);
                l7 = vader_midir_successors_of(t0);
                vader_array_push((vader_array_t*) l5, vader_ref_box(l7));
                t1 = (l15 + INT64_C(1));
                l15 = (size_t) (int64_t) t1;
                goto loop_145;
            } else {
            }
        }
    }
    vader_struct___lambda_env_2599_t* _a25_obj = (vader_struct___lambda_env_2599_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_2599_t));
    vader_obj_header_init(_a25_obj, 242u);
    t0 = (void*) _a25_obj;
    vader_fn_t* _a26_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
    vader_obj_header_init(_a26_closure, 131u);
    _a26_closure->code = (void*) &vader_fn_lift_1777;
    _a26_closure->env = t0;
    l6 = (void*) _a26_closure;
    l6 = std_core_filled__MutableSet_i32_(l1, l6);
    vader_struct___lambda_env_2602_t* _a27_obj = (vader_struct___lambda_env_2602_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_2602_t));
    vader_obj_header_init(_a27_obj, 243u);
    t0 = (void*) _a27_obj;
    vader_fn_t* _a28_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
    vader_obj_header_init(_a28_closure, 131u);
    _a28_closure->code = (void*) &vader_fn_lift_1778;
    _a28_closure->env = t0;
    l7 = (void*) _a28_closure;
    l7 = std_core_filled__MutableSet_i32_(l1, l7);
    vader_array_t* _a29_arr = vader_array_new(9u, 0u, 7u, 163u);
    l8 = (void*) _a29_arr;
    vader_array_t* _a30_arr = vader_array_new(6u, 0u, 12u, 159u);
    l10 = (void*) _a30_arr;
    vader_array_t* _a31_arr = vader_array_new(9u, 0u, 7u, 163u);
    l11 = (void*) _a31_arr;
    vader_struct_std_collections_MutableMap__i32__bool_t* _a32_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
    vader_obj_header_init(_a32_obj, 310u);
    _a32_obj->f_ekeys = l8;
    _a32_obj->f_evals = l10;
    _a32_obj->f_index = l11;
    _a32_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a32_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a32_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    t0 = (void*) _a32_obj;
    vader_struct_std_collections_MutableSet__i32_t* _a33_obj = (vader_struct_std_collections_MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i32_t));
    vader_obj_header_init(_a33_obj, 387u);
    _a33_obj->f_inner = t0;
    l8 = (void*) _a33_obj;
    vader_array_t* _a34_arr = vader_array_new(9u, 0u, 7u, 163u);
    l10 = (void*) _a34_arr;
    vader_array_t* _a35_arr = vader_array_new(6u, 0u, 12u, 159u);
    l11 = (void*) _a35_arr;
    vader_array_t* _a36_arr = vader_array_new(9u, 0u, 7u, 163u);
    l12 = (void*) _a36_arr;
    vader_struct_std_collections_MutableMap__i32__bool_t* _a37_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
    vader_obj_header_init(_a37_obj, 310u);
    _a37_obj->f_ekeys = l10;
    _a37_obj->f_evals = l11;
    _a37_obj->f_index = l12;
    _a37_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a37_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a37_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    t0 = (void*) _a37_obj;
    vader_struct_std_collections_MutableSet__i32_t* _a38_obj = (vader_struct_std_collections_MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i32_t));
    vader_obj_header_init(_a38_obj, 387u);
    _a38_obj->f_inner = t0;
    l10 = (void*) _a38_obj;
    l26 = true;
    {
        loop_214: {
            if (l26) {
                l26 = false;
                l4 = l1;
                {
                    loop_222: {
                        if ((l4 > INT64_C(0))) {
                            t1 = (l4 - INT64_C(1));
                            l4 = (size_t) (int64_t) t1;
                            std_collections_clear__i32__bool(((vader_struct_std_collections_MutableSet__i32_t*) l8)->f_inner);
                            vader_array_t* _a39_slotarr = ((vader_array_t*) l5);
                            if (_a39_slotarr->buf != NULL && _a39_slotarr->buf->header.forward != NULL) { _a39_slotarr->buf = vader_array_buf_forward(_a39_slotarr->buf); }
                            if ((size_t) l4 >= _a39_slotarr->length) { vader_trap("array index out of bounds"); }
                            l11 = vader_array_ref_load_obj(_a39_slotarr->buf, _a39_slotarr->offset + (size_t) l4);
                            l15 = ((vader_array_t*) l11)->length;
                            l16 = (size_t) (int64_t) INT64_C(0);
                            {
                                loop_242: {
                                    if ((l16 < l15)) {
                                        vader_array_t* _a40_slotarr = ((vader_array_t*) l11);
                                        if (_a40_slotarr->buf != NULL && _a40_slotarr->buf->header.forward != NULL) { _a40_slotarr->buf = vader_array_buf_forward(_a40_slotarr->buf); }
                                        if ((size_t) l16 >= _a40_slotarr->length) { vader_trap("array index out of bounds"); }
                                        l21 = ((int32_t*) _a40_slotarr->buf->slots)[_a40_slotarr->offset + (size_t) l16];
                                        vader_array_t* _a41_slotarr = ((vader_array_t*) l6);
                                        if (_a41_slotarr->buf != NULL && _a41_slotarr->buf->header.forward != NULL) { _a41_slotarr->buf = vader_array_buf_forward(_a41_slotarr->buf); }
                                        if ((size_t) l21 >= _a41_slotarr->length) { vader_trap("array index out of bounds"); }
                                        l12 = vader_array_ref_load_obj(_a41_slotarr->buf, _a41_slotarr->offset + (size_t) l21);
                                        l14 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) ((vader_struct_std_collections_MutableSet__i32_t*) l12)->f_inner)->f_ekeys;
                                        l27 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) ((vader_struct_std_collections_MutableSet__i32_t*) l12)->f_inner)->f_size;
                                        l28 = (size_t) (int64_t) INT64_C(0);
                                        {
                                            loop_265: {
                                                if ((l28 >= l27)) {
                                                } else {
                                                    vader_array_t* _a42_slotarr = ((vader_array_t*) l14);
                                                    if (_a42_slotarr->buf != NULL && _a42_slotarr->buf->header.forward != NULL) { _a42_slotarr->buf = vader_array_buf_forward(_a42_slotarr->buf); }
                                                    if ((size_t) l28 >= _a42_slotarr->length) { vader_trap("array index out of bounds"); }
                                                    l29 = ((int32_t*) _a42_slotarr->buf->slots)[_a42_slotarr->offset + (size_t) l28];
                                                    t1 = (l28 + INT64_C(1));
                                                    l28 = (size_t) (int64_t) t1;
                                                    std_collections_add__i32(l8, l29);
                                                    goto loop_265;
                                                }
                                            }
                                        }
                                        t1 = (l16 + INT64_C(1));
                                        l16 = (size_t) (int64_t) t1;
                                        goto loop_242;
                                    } else {
                                    }
                                }
                            }
                            std_collections_clear__i32__bool(((vader_struct_std_collections_MutableSet__i32_t*) l10)->f_inner);
                            vader_array_t* _a43_slotarr = ((vader_array_t*) l2);
                            if (_a43_slotarr->buf != NULL && _a43_slotarr->buf->header.forward != NULL) { _a43_slotarr->buf = vader_array_buf_forward(_a43_slotarr->buf); }
                            if ((size_t) l4 >= _a43_slotarr->length) { vader_trap("array index out of bounds"); }
                            l18 = vader_array_ref_load_obj(_a43_slotarr->buf, _a43_slotarr->offset + (size_t) l4);
                            l20 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) ((vader_struct_std_collections_MutableSet__i32_t*) l18)->f_inner)->f_ekeys;
                            l30 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) ((vader_struct_std_collections_MutableSet__i32_t*) l18)->f_inner)->f_size;
                            l31 = (size_t) (int64_t) INT64_C(0);
                            {
                                loop_312: {
                                    if ((l31 >= l30)) {
                                    } else {
                                        vader_array_t* _a44_slotarr = ((vader_array_t*) l20);
                                        if (_a44_slotarr->buf != NULL && _a44_slotarr->buf->header.forward != NULL) { _a44_slotarr->buf = vader_array_buf_forward(_a44_slotarr->buf); }
                                        if ((size_t) l31 >= _a44_slotarr->length) { vader_trap("array index out of bounds"); }
                                        l32 = ((int32_t*) _a44_slotarr->buf->slots)[_a44_slotarr->offset + (size_t) l31];
                                        t1 = (l31 + INT64_C(1));
                                        l31 = (size_t) (int64_t) t1;
                                        std_collections_add__i32(l10, l32);
                                        goto loop_312;
                                    }
                                }
                            }
                            l23 = l8;
                            l24 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) ((vader_struct_std_collections_MutableSet__i32_t*) l23)->f_inner)->f_ekeys;
                            l33 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) ((vader_struct_std_collections_MutableSet__i32_t*) l23)->f_inner)->f_size;
                            l34 = (size_t) (int64_t) INT64_C(0);
                            {
                                loop_346: {
                                    if ((l34 >= l33)) {
                                    } else {
                                        vader_array_t* _a45_slotarr = ((vader_array_t*) l24);
                                        if (_a45_slotarr->buf != NULL && _a45_slotarr->buf->header.forward != NULL) { _a45_slotarr->buf = vader_array_buf_forward(_a45_slotarr->buf); }
                                        if ((size_t) l34 >= _a45_slotarr->length) { vader_trap("array index out of bounds"); }
                                        l35 = ((int32_t*) _a45_slotarr->buf->slots)[_a45_slotarr->offset + (size_t) l34];
                                        t1 = (l34 + INT64_C(1));
                                        l34 = (size_t) (int64_t) t1;
                                        vader_array_t* _a46_slotarr = ((vader_array_t*) l3);
                                        if (_a46_slotarr->buf != NULL && _a46_slotarr->buf->header.forward != NULL) { _a46_slotarr->buf = vader_array_buf_forward(_a46_slotarr->buf); }
                                        if ((size_t) l4 >= _a46_slotarr->length) { vader_trap("array index out of bounds"); }
                                        t0 = vader_array_ref_load_obj(_a46_slotarr->buf, _a46_slotarr->offset + (size_t) l4);
                                        t2 = std_collections_contains_key__i32__bool(((vader_struct_std_collections_MutableSet__i32_t*) t0)->f_inner, l35);
                                        if (!(t2)) {
                                            std_collections_add__i32(l10, l35);
                                        } else {
                                        }
                                        goto loop_346;
                                    }
                                }
                            }
                            vader_array_t* _a47_slotarr = ((vader_array_t*) l7);
                            if (_a47_slotarr->buf != NULL && _a47_slotarr->buf->header.forward != NULL) { _a47_slotarr->buf = vader_array_buf_forward(_a47_slotarr->buf); }
                            if ((size_t) l4 >= _a47_slotarr->length) { vader_trap("array index out of bounds"); }
                            l25 = vader_array_ref_load_obj(_a47_slotarr->buf, _a47_slotarr->offset + (size_t) l4);
                            t2 = vader_midir_sets_equal(l8, l25);
                            if (!(t2)) {
                                vader_array_t* _a48_slotarr = ((vader_array_t*) l7);
                                if (_a48_slotarr->buf != NULL && _a48_slotarr->buf->header.forward != NULL) { _a48_slotarr->buf = vader_array_buf_forward(_a48_slotarr->buf); }
                                if ((size_t) l4 >= _a48_slotarr->length) { vader_trap("array index out of bounds"); }
                                l36 = vader_array_ref_load_obj(_a48_slotarr->buf, _a48_slotarr->offset + (size_t) l4);
                                if ((size_t) l4 >= _a48_slotarr->length) { vader_trap("array index out of bounds"); }
                                vader_array_ref_store(_a48_slotarr->buf, _a48_slotarr->offset + (size_t) l4, l8);
                                VADER_WRITE_BARRIER(_a48_slotarr->buf);
                                l8 = l36;
                                l26 = true;
                            } else {
                            }
                            vader_array_t* _a49_slotarr = ((vader_array_t*) l6);
                            if (_a49_slotarr->buf != NULL && _a49_slotarr->buf->header.forward != NULL) { _a49_slotarr->buf = vader_array_buf_forward(_a49_slotarr->buf); }
                            if ((size_t) l4 >= _a49_slotarr->length) { vader_trap("array index out of bounds"); }
                            l37 = vader_array_ref_load_obj(_a49_slotarr->buf, _a49_slotarr->offset + (size_t) l4);
                            t2 = vader_midir_sets_equal(l10, l37);
                            if (!(t2)) {
                                vader_array_t* _a50_slotarr = ((vader_array_t*) l6);
                                if (_a50_slotarr->buf != NULL && _a50_slotarr->buf->header.forward != NULL) { _a50_slotarr->buf = vader_array_buf_forward(_a50_slotarr->buf); }
                                if ((size_t) l4 >= _a50_slotarr->length) { vader_trap("array index out of bounds"); }
                                l38 = vader_array_ref_load_obj(_a50_slotarr->buf, _a50_slotarr->offset + (size_t) l4);
                                if ((size_t) l4 >= _a50_slotarr->length) { vader_trap("array index out of bounds"); }
                                vader_array_ref_store(_a50_slotarr->buf, _a50_slotarr->offset + (size_t) l4, l10);
                                VADER_WRITE_BARRIER(_a50_slotarr->buf);
                                l10 = l38;
                                l26 = true;
                            } else {
                            }
                            goto loop_222;
                        } else {
                        }
                    }
                }
                goto loop_214;
            } else {
            }
        }
    }
    vader_struct_vader_midir_Liveness_t* _a51_obj = (vader_struct_vader_midir_Liveness_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_Liveness_t));
    vader_obj_header_init(_a51_obj, 847u);
    _a51_obj->f_live_in = l6;
    _a51_obj->f_live_out = l7;
    t0 = (void*) _a51_obj;
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
            } else {
            }
        }
    }
    vader_array_t* _a3_arr = vader_array_new(9u, 0u, 7u, 163u);
    l3 = (void*) _a3_arr;
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_41: {
            if ((l4 < l1)) {
                vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
                if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                if ((size_t) l4 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l4);
                t2 = ((vader_array_t*) t0)->length;
                if (t2 == INT64_C(0)) {
                    l7 = ((int32_t) (size_t) l4);
                    vader_array_push_i32((vader_array_t*) l3, l7);
                } else {
                }
                t1 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t1;
                goto loop_41;
            } else {
            }
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
    vader_array_t* _a7_arr = vader_array_new(9u, 0u, 7u, 163u);
    l2 = (void*) _a7_arr;
    vader_array_push((vader_array_t*) l6, vader_ref_box(l2));
    t1 = (l1 + INT64_C(1));
    l4 = (size_t) (int64_t) t1;
    vader_struct___lambda_env_1760_t* _a8_obj = (vader_struct___lambda_env_1760_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_1760_t));
    vader_obj_header_init(_a8_obj, 232u);
    t0 = (void*) _a8_obj;
    vader_fn_t* _a9_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
    vader_obj_header_init(_a9_closure, 130u);
    _a9_closure->code = (void*) &vader_fn_lift_1759;
    _a9_closure->env = t0;
    l2 = (void*) _a9_closure;
    l2 = std_core_filled__i32__(l4, l2);
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_104: {
            if ((l4 < l1)) {
                vader_array_t* _a10_slotarr = ((vader_array_t*) l6);
                if (_a10_slotarr->buf != NULL && _a10_slotarr->buf->header.forward != NULL) { _a10_slotarr->buf = vader_array_buf_forward(_a10_slotarr->buf); }
                if ((size_t) l4 >= _a10_slotarr->length) { vader_trap("array index out of bounds"); }
                l8 = vader_array_ref_load_obj(_a10_slotarr->buf, _a10_slotarr->offset + (size_t) l4);
                l5 = ((vader_array_t*) l8)->length;
                l9 = (size_t) (int64_t) INT64_C(0);
                {
                    loop_118: {
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
                            goto loop_118;
                        } else {
                        }
                    }
                }
                t1 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t1;
                goto loop_104;
            } else {
            }
        }
    }
    l4 = ((vader_array_t*) l3)->length;
    l5 = (size_t) (int64_t) INT64_C(0);
    {
        loop_162: {
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
                goto loop_162;
            } else {
            }
        }
    }
    vader_array_t* _a16_arr = vader_array_new(9u, 0u, 7u, 163u);
    l3 = (void*) _a16_arr;
    vader_array_t* _a17_arr = vader_array_new(6u, 1u, 12u, 159u);
    ((uint8_t*) _a17_arr->buf->slots)[_a17_arr->offset + 0u] = (uint8_t) false;
    l8 = (void*) _a17_arr;
    t1 = (l1 + INT64_C(1));
    l4 = (size_t) (int64_t) t1;
    vader_array_t* _a18_arr = vader_array_repeat((vader_array_t*) l8, (size_t) l4);
    l8 = (void*) _a18_arr;
    l12 = l7;
    vader_midir_walk_rpo_reverse(l2, l12, l8, l3);
    vader_array_t* _a19_arr = vader_array_new(9u, 1u, 7u, 163u);
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
        loop_241: {
            if (l14) {
                l14 = false;
                t2 = ((vader_array_t*) l3)->length;
                l15 = (((int64_t) (size_t) t2) - INT64_C(1));
                {
                    loop_253: {
                        if ((l15 >= INT64_C(0))) {
                            t1 = l15;
                            l4 = (size_t) (int64_t) t1;
                            vader_array_t* _a22_slotarr = ((vader_array_t*) l3);
                            if (_a22_slotarr->buf != NULL && _a22_slotarr->buf->header.forward != NULL) { _a22_slotarr->buf = vader_array_buf_forward(_a22_slotarr->buf); }
                            if ((size_t) l4 >= _a22_slotarr->length) { vader_trap("array index out of bounds"); }
                            l12 = ((int32_t*) _a22_slotarr->buf->slots)[_a22_slotarr->offset + (size_t) l4];
                            l15 = (l15 - INT64_C(1));
                            if (l12 == l7) {
                                goto loop_253;
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
                                loop_290: {
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
                                            goto loop_290;
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
                                        goto loop_290;
                                    } else {
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
                            } else {
                            }
                            goto loop_253;
                        } else {
                        }
                    }
                }
                goto loop_241;
            } else {
            }
        }
    }
    vader_array_t* _a28_arr = vader_array_new(9u, 0u, 7u, 163u);
    t0 = (void*) _a28_arr;
    vader_array_t* _a29_arr = vader_array_repeat((vader_array_t*) t0, (size_t) l1);
    l3 = (void*) _a29_arr;
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_395: {
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
                goto loop_395;
            } else {
            }
        }
    }
    { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static int32_t vader_midir_cond_branch_merge(void* l0, int32_t l1, int32_t l2) {
    void* l3;
    size_t l4;
    int32_t l5;
    int64_t t0;
    bool t1;
    l3 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_ipostdom;
    t0 = ((int64_t) (int32_t) l1);
    l4 = (size_t) (int64_t) t0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    if ((size_t) l4 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
    l5 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l4];
    if ((l5 < INT32_C(0))) {
        return l2;
    }
    t1 = std_collections_contains_key__i32__bool(((vader_struct_std_collections_MutableSet__i32_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_wrapped_loop_headers)->f_inner, l5);
    if (t1) {
        return -(INT32_C(1));
    }
    return l5;
}

static void* vader_midir_convert_data_pool(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    void* l12 = NULL;
    void* l18 = NULL;
    void* l19 = NULL;
    void* l20 = NULL;
    void* l21 = NULL;
    void* l27 = NULL;
    size_t l3, l4, l13, l14, l22, l23, l28;
    vader_box_t l5 = vader_box_null(), l24 = vader_box_null();
    bool l8, l17, l26;
    uint64_t l15;
    uint8_t l16;
    vader_string_t l25;
    int64_t t0, t1;
    vader_string_t t2;
    vader_box_t t3 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l5, &l24, &t3 };
    void** gc_raw_roots[14] = { &l0, &l1, &l2, &l6, &l7, &l9, &l10, &l11, &l12, &l18, &l19, &l20, &l21, &l27 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 14u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(117u, 0u, 13u, 1084u);
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
                if (l5.tag == 791u) {
                    l6 = l5.payload.obj;
                    l7 = ((vader_struct_vader_lower_StrDataPoolEntry_t*) l6)->f_values;
                    l8 = ((vader_struct_vader_lower_StrDataPoolEntry_t*) l6)->f_mutable;
                    vader_struct_vader_bytecode_BcStrData_t* _a2_obj = (vader_struct_vader_bytecode_BcStrData_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcStrData_t));
                    vader_obj_header_init(_a2_obj, 517u);
                    _a2_obj->f_values = l7;
                    _a2_obj->f_mutable = l8;
                    l9 = (void*) _a2_obj;
                    vader_array_push((vader_array_t*) l1, vader_ref_box(l9));
                    l28 = (size_t) (int64_t) INT64_C(1);
                    t0 = (l4 + l28);
                    l4 = (size_t) (int64_t) t0;
                    goto loop_9;
                }
                if (l5.tag == 790u) {
                    l10 = l5.payload.obj;
                    vader_array_t* _a3_arr = vader_array_new(13u, 0u, 4u, 168u);
                    l11 = (void*) _a3_arr;
                    l12 = ((vader_struct_vader_lower_PrimDataPoolEntry_t*) l10)->f_items;
                    l13 = ((vader_array_t*) l12)->length;
                    l14 = (size_t) (int64_t) INT64_C(0);
                    {
                        loop_58: {
                            if ((l14 < l13)) {
                                vader_array_t* _a4_slotarr = ((vader_array_t*) l12);
                                if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                                if ((size_t) l14 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                                t0 = ((int64_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l14];
                                t1 = t0;
                                l15 = (uint64_t) (int64_t) t1;
                                vader_array_push_i64((vader_array_t*) l11, (int64_t) (uint64_t) l15);
                                t0 = (l14 + INT64_C(1));
                                l14 = (size_t) (int64_t) t0;
                                goto loop_58;
                            } else {
                            }
                        }
                    }
                    t2 = ((vader_struct_vader_lower_PrimDataPoolEntry_t*) l10)->f_element_type_name;
                    l16 = vader_bytecode_array_kind_from_name(t2);
                    l17 = ((vader_struct_vader_lower_PrimDataPoolEntry_t*) l10)->f_mutable;
                    vader_struct_vader_bytecode_BcPrimData_t* _a5_obj = (vader_struct_vader_bytecode_BcPrimData_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcPrimData_t));
                    vader_obj_header_init(_a5_obj, 513u);
                    _a5_obj->f_kind = l16;
                    _a5_obj->f_items = l11;
                    _a5_obj->f_mutable = l17;
                    l18 = (void*) _a5_obj;
                    vader_array_push((vader_array_t*) l1, vader_ref_box(l18));
                    l28 = (size_t) (int64_t) INT64_C(1);
                    t0 = (l4 + l28);
                    l4 = (size_t) (int64_t) t0;
                    goto loop_9;
                }
                if (l5.tag == 708u) {
                    l19 = l5.payload.obj;
                    vader_array_t* _a6_arr = vader_array_new(119u, 0u, 13u, 1090u);
                    l20 = (void*) _a6_arr;
                    l21 = ((vader_struct_vader_lower_LoweredArrayLit_t*) ((vader_struct_vader_lower_AggregateDataPoolEntry_t*) l19)->f_literal)->f_elements;
                    l22 = ((vader_array_t*) l21)->length;
                    l23 = (size_t) (int64_t) INT64_C(0);
                    {
                        loop_119: {
                            if ((l23 < l22)) {
                                vader_array_t* _a7_slotarr = ((vader_array_t*) l21);
                                if (_a7_slotarr->buf != NULL && _a7_slotarr->buf->header.forward != NULL) { _a7_slotarr->buf = vader_array_buf_forward(_a7_slotarr->buf); }
                                if ((size_t) l23 >= _a7_slotarr->length) { vader_trap("array index out of bounds"); }
                                t3 = vader_array_ref_load_box(_a7_slotarr->buf, _a7_slotarr->offset + (size_t) l23);
                                l24 = vader_midir_lowered_to_bc_value(t3);
                                vader_array_push((vader_array_t*) l20, l24);
                                t0 = (l23 + INT64_C(1));
                                l23 = (size_t) (int64_t) t0;
                                goto loop_119;
                            } else {
                            }
                        }
                    }
                    l25 = ((vader_struct_vader_lower_AggregateDataPoolEntry_t*) l19)->f_element_type_name;
                    l26 = ((vader_struct_vader_lower_AggregateDataPoolEntry_t*) l19)->f_mutable;
                    vader_struct_vader_bytecode_BcAggregateData_t* _a8_obj = (vader_struct_vader_bytecode_BcAggregateData_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcAggregateData_t));
                    vader_obj_header_init(_a8_obj, 504u);
                    _a8_obj->f_element_type_name = l25;
                    _a8_obj->f_elements = l20;
                    _a8_obj->f_mutable = l26;
                    l27 = (void*) _a8_obj;
                    vader_array_push((vader_array_t*) l1, vader_ref_box(l27));
                    l28 = (size_t) (int64_t) INT64_C(1);
                    t0 = (l4 + l28);
                    l4 = (size_t) (int64_t) t0;
                    goto loop_9;
                }
                vader_unreachable("unreachable return in vader_midir$convert_data_pool");
            } else {
            }
        }
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static bool vader_midir_convert_eligible(uint8_t l0) {
    if (l0 == INT32_C(0)) {
        return true;
    }
    if (l0 == INT32_C(1)) {
        return true;
    }
    if (l0 == INT32_C(2)) {
        return true;
    }
    if (l0 == INT32_C(3)) {
        return true;
    }
    if (l0 == INT32_C(4)) {
        return true;
    }
    if (l0 == INT32_C(5)) {
        return true;
    }
    if (l0 == INT32_C(6)) {
        return true;
    }
    if (l0 == INT32_C(7)) {
        return true;
    }
    if (l0 == INT32_C(8)) {
        return true;
    }
    if (l0 == INT32_C(9)) {
        return true;
    }
    if (l0 == INT32_C(10)) {
        return true;
    }
    if (l0 == INT32_C(11)) {
        return true;
    }
    if (l0 == INT32_C(12)) {
        return false;
    }
    if (l0 == INT32_C(13)) {
        return true;
    }
    if (l0 == INT32_C(14)) {
        return false;
    }
    if (l0 == INT32_C(15)) {
        return false;
    }
    if (l0 == INT32_C(16)) {
        return false;
    }
    if (l0 == INT32_C(17)) {
        return false;
    }
    if (l0 == INT32_C(18)) {
        return false;
    }
    vader_unreachable("unreachable return in vader_midir$convert_eligible");
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
    vader_string_t l11, l17;
    vader_box_t l12 = vader_box_null(), l19 = vader_box_null();
    bool l22, l23;
    vader_box_t t0 = vader_box_null();
    size_t t1;
    int64_t t2;
    void* t3 = NULL;
    vader_box_t* gc_roots[3] = { &l12, &l19, &t0 };
    void** gc_raw_roots[13] = { &l0, &l1, &l2, &l3, &l4, &l5, &l6, &l7, &l13, &l14, &l18, &l21, &t3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 13u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (((vader_struct_vader_lower_LoweredFnDecl_t*) l0)->f_body.tag == 0u) {
        t0 = vader_box_obj(0u, NULL);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_vader_lower_LoweredFnDecl_t*) l0)->f_body;
    l2 = t0.payload.obj;
    vader_array_t* _a0_arr = vader_array_new(72u, 0u, 13u, 803u);
    l3 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(70u, 0u, 13u, 801u);
    l4 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 163u);
    l5 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(9u, 0u, 7u, 163u);
    l6 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_new(9u, 0u, 7u, 163u);
    l7 = (void*) _a4_arr;
    vader_struct_std_collections_MutableMap__i32__i32_t* _a5_obj = (vader_struct_std_collections_MutableMap__i32__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__i32_t));
    vader_obj_header_init(_a5_obj, 311u);
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
                vader_obj_header_init(_a7_obj, 801u);
                _a7_obj->f_name = l11;
                _a7_obj->f_type = l12;
                _a7_obj->f_symbol = vader_ref_box(l13);
                l14 = (void*) _a7_obj;
                vader_array_push((vader_array_t*) l4, vader_ref_box(l14));
                l15 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_lower_LoweredParam_t*) l7)->f_symbol)->f_id;
                l16 = l10;
                std_collections_put__i32__i32(l5, l15, l16);
                l17 = ((vader_struct_vader_lower_LoweredParam_t*) l7)->f_name;
                l18 = ((vader_struct_vader_lower_LoweredParam_t*) l7)->f_symbol;
                l19 = ((vader_struct_vader_lower_LoweredParam_t*) l7)->f_type;
                l20 = l10;
                vader_struct_vader_midir_CFGParam_t* _a8_obj = (vader_struct_vader_midir_CFGParam_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_CFGParam_t));
                vader_obj_header_init(_a8_obj, 803u);
                _a8_obj->f_name = l17;
                _a8_obj->f_symbol = l18;
                _a8_obj->f_type = l19;
                _a8_obj->f_local = l20;
                l21 = (void*) _a8_obj;
                vader_array_push((vader_array_t*) l3, vader_ref_box(l21));
                t2 = (l9 + INT64_C(1));
                l9 = (size_t) (int64_t) t2;
                goto loop_34;
            } else {
            }
        }
    }
    l11 = ((vader_struct_vader_lower_LoweredFnDecl_t*) l0)->f_mangled;
    l6 = ((vader_struct_vader_lower_LoweredFnDecl_t*) l0)->f_origin;
    l12 = ((vader_struct_vader_lower_LoweredFnDecl_t*) l0)->f_return_type;
    vader_array_t* _a9_arr = vader_array_new(76u, 0u, 13u, 849u);
    l7 = (void*) _a9_arr;
    vader_array_t* _a10_arr = vader_array_new(75u, 0u, 13u, 848u);
    l13 = (void*) _a10_arr;
    vader_struct_vader_midir_FnCtx_t* _a11_obj = (vader_struct_vader_midir_FnCtx_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_FnCtx_t));
    vader_obj_header_init(_a11_obj, 815u);
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
    ((vader_struct_vader_midir_FnCtx_t*) l4)->f_current = vader_box_i32(163u, l10);
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
            vader_struct_vader_midir_TermReturn_t* _a13_obj = (vader_struct_vader_midir_TermReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_TermReturn_t));
            vader_obj_header_init(_a13_obj, 856u);
            _a13_obj->f_span = ((vader_struct_vader_lower_LoweredBlock_t*) l2)->f_span;
            _a13_obj->f_value = l12;
            l2 = (void*) _a13_obj;
            ((vader_struct_vader_midir_MutableBlock_t*) l5)->f_terminator = vader_ref_box(l2);
            VADER_WRITE_BARRIER((vader_struct_vader_midir_MutableBlock_t*) l5);
        } else {
        }
    } else {
    }
    l2 = vader_midir_fn_metadata(l0);
    vader_array_t* _a14_arr = vader_array_new(67u, 0u, 13u, 798u);
    l5 = (void*) _a14_arr;
    l6 = ((vader_struct_vader_midir_FnCtx_t*) l4)->f_blocks;
    l8 = ((vader_array_t*) l6)->length;
    l9 = (size_t) (int64_t) INT64_C(0);
    {
        loop_174: {
            if ((l9 < l8)) {
                vader_array_t* _a15_slotarr = ((vader_array_t*) l6);
                if (_a15_slotarr->buf != NULL && _a15_slotarr->buf->header.forward != NULL) { _a15_slotarr->buf = vader_array_buf_forward(_a15_slotarr->buf); }
                if ((size_t) l9 >= _a15_slotarr->length) { vader_trap("array index out of bounds"); }
                t3 = vader_array_ref_load_obj(_a15_slotarr->buf, _a15_slotarr->offset + (size_t) l9);
                l7 = vader_midir_freeze_block(t3);
                vader_array_push((vader_array_t*) l5, vader_ref_box(l7));
                t2 = (l9 + INT64_C(1));
                l9 = (size_t) (int64_t) t2;
                goto loop_174;
            } else {
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
    vader_struct_vader_midir_CFGFunction_t* _a16_obj = (vader_struct_vader_midir_CFGFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_CFGFunction_t));
    vader_obj_header_init(_a16_obj, 800u);
    _a16_obj->f_mangled = l11;
    _a16_obj->f_params = l3;
    _a16_obj->f_return_type = l12;
    _a16_obj->f_locals = l4;
    _a16_obj->f_blocks = l5;
    _a16_obj->f_entry = l10;
    _a16_obj->f_origin = l6;
    _a16_obj->f_extern_name = l17;
    _a16_obj->f_is_extern = l22;
    _a16_obj->f_is_exported = l23;
    t3 = (void*) _a16_obj;
    { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
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
    vader_array_t* _a0_arr = vader_array_new(9u, 0u, 7u, 163u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(9u, 0u, 7u, 163u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 163u);
    l3 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__i32__i32_t* _a3_obj = (vader_struct_std_collections_MutableMap__i32__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__i32_t));
    vader_obj_header_init(_a3_obj, 311u);
    _a3_obj->f_ekeys = l1;
    _a3_obj->f_evals = l2;
    _a3_obj->f_index = l3;
    _a3_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    t0 = (void*) _a3_obj;
    vader_struct__Cell_Struct_lib_std_collections_collections_vader_2450_i32_i32__t* _a4_obj = (vader_struct__Cell_Struct_lib_std_collections_collections_vader_2450_i32_i32__t*) vader_gc_alloc(sizeof(vader_struct__Cell_Struct_lib_std_collections_collections_vader_2450_i32_i32__t));
    vader_obj_header_init(_a4_obj, 183u);
    _a4_obj->f_value = t0;
    t0 = (void*) _a4_obj;
    l4 = vader_ref_box(t0);
    vader_struct___lambda_env_2574_t* _a5_obj = (vader_struct___lambda_env_2574_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_2574_t));
    vader_obj_header_init(_a5_obj, 238u);
    _a5_obj->f_cap_0 = l4;
    t0 = (void*) _a5_obj;
    vader_fn_t* _a6_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
    vader_obj_header_init(_a6_closure, 138u);
    _a6_closure->code = (void*) &vader_fn_lift_1771;
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
                        } else {
                        }
                    }
                }
                vader_midir_for_each_read_in_terminator(((vader_struct_vader_midir_BasicBlock_t*) l3)->f_terminator, l1);
                t2 = (l6 + INT64_C(1));
                l6 = (size_t) (int64_t) t2;
                goto loop_25;
            } else {
            }
        }
    }
    { void* __vret = ((vader_struct__Cell_Struct_lib_std_collections_collections_vader_2450_i32_i32__t*) l4.payload.obj)->f_value; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_box_t vader_midir_debug_pos_of_span(void* l0) {
    vader_string_t l1;
    int32_t l2, l3;
    bool t0;
    vader_box_t t1 = vader_box_null();
    void* t2 = NULL;
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[2] = { &l0, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
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
    vader_obj_header_init(_a0_obj, 546u);
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
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_vader_midir_FnCtx_t*) l0)->f_locals)->length;
    l4 = ((int32_t) (size_t) t0);
    l5 = ((vader_struct_vader_midir_FnCtx_t*) l0)->f_locals;
    vader_struct_vader_midir_CFGLocal_t* _a0_obj = (vader_struct_vader_midir_CFGLocal_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_CFGLocal_t));
    vader_obj_header_init(_a0_obj, 801u);
    _a0_obj->f_name = l1;
    _a0_obj->f_type = l2;
    _a0_obj->f_symbol = l3;
    l6 = (void*) _a0_obj;
    vader_array_push((vader_array_t*) l5, vader_ref_box(l6));
    { int32_t __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static bool vader_midir_decorators_have(void* l0, vader_string_t l1) {
    void* l2;
    size_t l3, l4;
    void* t0;
    vader_string_t t1;
    int64_t t2;
    l2 = l0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    l3 = ((vader_array_t*) l2)->length;
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_7: {
            if ((l4 < l3)) {
                if ((size_t) l4 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
                t1 = ((vader_struct_toolchain_ast_Decorator_t*) t0)->f_name;
                if (t1 == l1) {
                    return true;
                }
                t2 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t2;
                goto loop_7;
            } else {
            }
        }
    }
    return false;
}

static void vader_midir_defer_or_resolve_branch(void* l0, int32_t l1, int32_t l2) {
    size_t l3, l6, l12;
    int64_t l4;
    void* l5 = NULL;
    void* l7 = NULL;
    void* l11 = NULL;
    bool l8;
    int32_t l9, l10, l13;
    int64_t t0;
    vader_string_t t1;
    int32_t t2;
    void* t3 = NULL;
    void** gc_raw_roots[5] = { &l0, &l5, &l7, &l11, &t3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL };
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
                if (t1 == 1714u) {
                    l9 = ((vader_struct_vader_midir_ScopeFrame_t*) l7)->f_target_blk;
                    l10 = l1;
                    l8 = l9 == l10;
                } else {
                    l8 = false;
                }
                if (l8) {
                    l11 = ((vader_struct_vader_bytecode_BcFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_slot)->f_jump_table;
                    t0 = ((int64_t) (int32_t) l2);
                    l12 = (size_t) (int64_t) t0;
                    t2 = ((vader_struct_vader_midir_ScopeFrame_t*) l7)->f_opener_pc;
                    l13 = (t2 + INT32_C(1));
                    vader_array_t* _a1_slotarr = ((vader_array_t*) l11);
                    if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                    if ((size_t) l12 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                    ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l12] = (int32_t) l13;
                    { vader_gc_top = gc_frame.prev; return; }
                }
                l4 = (l4 - INT64_C(1));
                goto loop_8;
            } else {
            }
        }
    }
    l4 = (((int64_t) (size_t) l3) - INT64_C(1));
    {
        loop_73: {
            if ((l4 >= INT64_C(0))) {
                l5 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_scopes;
                t0 = l4;
                l3 = (size_t) (int64_t) t0;
                vader_array_t* _a2_slotarr = ((vader_array_t*) l5);
                if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                if ((size_t) l3 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                t3 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l3);
                l9 = ((vader_struct_vader_midir_ScopeFrame_t*) t3)->f_target_blk;
                l10 = l1;
                if (l9 == l10) {
                    l7 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_pending;
                    vader_struct_vader_midir_PendingBranch_t* _a3_obj = (vader_struct_vader_midir_PendingBranch_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_PendingBranch_t));
                    vader_obj_header_init(_a3_obj, 850u);
                    _a3_obj->f_branch_pc = l2;
                    _a3_obj->f_target_blk = l1;
                    l11 = (void*) _a3_obj;
                    vader_array_push((vader_array_t*) l7, vader_ref_box(l11));
                    { vader_gc_top = gc_frame.prev; return; }
                }
                l4 = (l4 - INT64_C(1));
                goto loop_73;
            } else {
            }
        }
    }
    l5 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_pending;
    vader_struct_vader_midir_PendingBranch_t* _a4_obj = (vader_struct_vader_midir_PendingBranch_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_PendingBranch_t));
    vader_obj_header_init(_a4_obj, 850u);
    _a4_obj->f_branch_pc = l2;
    _a4_obj->f_target_blk = l1;
    l7 = (void*) _a4_obj;
    vader_array_push((vader_array_t*) l5, vader_ref_box(l7));
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_midir_die_once(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l9 = NULL;
    void* l13 = NULL;
    void* l16 = NULL;
    void* l17 = NULL;
    size_t l4, l5, l8, l10, l11, l12;
    int32_t l14;
    vader_box_t l15 = vader_box_null();
    vader_string_t l18, l19;
    bool l20, l21;
    int64_t t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &l15 };
    void** gc_raw_roots[11] = { &l0, &l1, &l2, &l3, &l6, &l7, &l9, &l13, &l16, &l17, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 11u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_midir_compute_liveness(l0);
    vader_array_t* _a0_arr = vader_array_new(67u, 0u, 13u, 798u);
    l2 = (void*) _a0_arr;
    l3 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_blocks;
    l4 = ((vader_array_t*) l3)->length;
    l5 = (size_t) (int64_t) INT64_C(0);
    {
        loop_12: {
            if ((l5 < l4)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l5 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                l6 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5);
                l7 = ((vader_struct_vader_midir_Liveness_t*) l1)->f_live_out;
                t0 = ((int64_t) (int32_t) ((vader_struct_vader_midir_BasicBlock_t*) l6)->f_id);
                l8 = (size_t) (int64_t) t0;
                vader_array_t* _a2_slotarr = ((vader_array_t*) l7);
                if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                if ((size_t) l8 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                l9 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l8);
                l10 = ((vader_array_t*) ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_params)->length;
                l11 = ((vader_array_t*) ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_locals)->length;
                t0 = (l10 + l11);
                l12 = (size_t) (int64_t) t0;
                l13 = vader_midir_prune_block(l6, l9, l12);
                l14 = ((vader_struct_vader_midir_BasicBlock_t*) l6)->f_id;
                l15 = ((vader_struct_vader_midir_BasicBlock_t*) l6)->f_terminator;
                l16 = ((vader_struct_vader_midir_BasicBlock_t*) l6)->f_span;
                vader_struct_vader_midir_BasicBlock_t* _a3_obj = (vader_struct_vader_midir_BasicBlock_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_BasicBlock_t));
                vader_obj_header_init(_a3_obj, 798u);
                _a3_obj->f_id = l14;
                _a3_obj->f_instructions = l13;
                _a3_obj->f_terminator = l15;
                _a3_obj->f_span = l16;
                l17 = (void*) _a3_obj;
                vader_array_push((vader_array_t*) l2, vader_ref_box(l17));
                t0 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t0;
                goto loop_12;
            } else {
            }
        }
    }
    l18 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_mangled;
    l1 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_params;
    l15 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_return_type;
    l3 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_locals;
    l14 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_entry;
    l6 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_origin;
    l19 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_extern_name;
    l20 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_is_extern;
    l21 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_is_exported;
    vader_struct_vader_midir_CFGFunction_t* _a4_obj = (vader_struct_vader_midir_CFGFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_CFGFunction_t));
    vader_obj_header_init(_a4_obj, 800u);
    _a4_obj->f_mangled = l18;
    _a4_obj->f_params = l1;
    _a4_obj->f_return_type = l15;
    _a4_obj->f_locals = l3;
    _a4_obj->f_blocks = l2;
    _a4_obj->f_entry = l14;
    _a4_obj->f_origin = l6;
    _a4_obj->f_extern_name = l19;
    _a4_obj->f_is_extern = l20;
    _a4_obj->f_is_exported = l21;
    t1 = (void*) _a4_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static bool vader_midir_dominates(void* l0, int32_t l1, int32_t l2) {
    int32_t l3, l4, l5, l6, l7, l8, l9, l10, l11, l12, l13;
    l3 = l2;
    {
        loop_3: {
            l4 = l3;
            l5 = -(INT32_C(1));
            if (!(l4 == l5)) {
                l6 = l3;
                l7 = l1;
                if (l6 == l7) {
                    return true;
                }
                l8 = l3;
                vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
                if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                if ((size_t) l8 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                l9 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l8];
                l10 = l9;
                l11 = l3;
                if (l10 == l11) {
                    l12 = l3;
                    l13 = l1;
                    return l12 == l13;
                }
                l3 = l9;
                goto loop_3;
            } else {
            }
        }
    }
    return false;
}

static void vader_midir_drain_pending(void* l0, int32_t l1, bool l2, int32_t l3, int32_t l4) {
    int32_t l5, l11, l12;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l10 = NULL;
    void* l13 = NULL;
    size_t l8, l9, l14;
    int32_t t0;
    int64_t t1;
    void** gc_raw_roots[5] = { &l0, &l6, &l7, &l10, &l13 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l2) {
        l5 = (l3 + INT32_C(1));
    } else {
        l5 = (l4 + INT32_C(1));
    }
    vader_array_t* _a0_arr = vader_array_new(77u, 0u, 13u, 850u);
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
                l11 = ((vader_struct_vader_midir_PendingBranch_t*) l10)->f_target_blk;
                l12 = l1;
                if (l11 == l12) {
                    l13 = ((vader_struct_vader_bytecode_BcFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_slot)->f_jump_table;
                    t0 = ((vader_struct_vader_midir_PendingBranch_t*) l10)->f_branch_pc;
                    t1 = ((int64_t) (int32_t) t0);
                    l14 = (size_t) (int64_t) t1;
                    vader_array_t* _a2_slotarr = ((vader_array_t*) l13);
                    if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                    if ((size_t) l14 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                    ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l14] = (int32_t) l5;
                } else {
                    vader_array_push((vader_array_t*) l6, vader_ref_box(l10));
                }
                t1 = (l9 + INT64_C(1));
                l9 = (size_t) (int64_t) t1;
                goto loop_21;
            } else {
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
    if (l0.tag == 831u) {
        t0 = l0.payload.obj;
        t1 = vader_box_i32(163u, ((vader_struct_vader_midir_InstrConst_t*) t0)->f_dst);
        return t1;
    }
    if (l0.tag == 840u) {
        t0 = l0.payload.obj;
        t1 = vader_box_i32(163u, ((vader_struct_vader_midir_InstrMove_t*) t0)->f_dst);
        return t1;
    }
    if (l0.tag == 824u) {
        t0 = l0.payload.obj;
        t1 = vader_box_i32(163u, ((vader_struct_vader_midir_InstrBinOp_t*) t0)->f_dst);
        return t1;
    }
    if (l0.tag == 845u) {
        t0 = l0.payload.obj;
        t1 = vader_box_i32(163u, ((vader_struct_vader_midir_InstrUnOp_t*) t0)->f_dst);
        return t1;
    }
    if (l0.tag == 835u) {
        t0 = l0.payload.obj;
        t1 = vader_box_i32(163u, ((vader_struct_vader_midir_InstrFieldGet_t*) t0)->f_dst);
        return t1;
    }
    if (l0.tag == 818u) {
        t0 = l0.payload.obj;
        t1 = vader_box_i32(163u, ((vader_struct_vader_midir_InstrArrayGet_t*) t0)->f_dst);
        return t1;
    }
    if (l0.tag == 819u) {
        t0 = l0.payload.obj;
        t1 = vader_box_i32(163u, ((vader_struct_vader_midir_InstrArrayLen_t*) t0)->f_dst);
        return t1;
    }
    if (l0.tag == 823u) {
        t0 = l0.payload.obj;
        t1 = vader_box_i32(163u, ((vader_struct_vader_midir_InstrArraySlice_t*) t0)->f_dst);
        return t1;
    }
    if (l0.tag == 841u) {
        t0 = l0.payload.obj;
        t1 = vader_box_i32(163u, ((vader_struct_vader_midir_InstrStringSlice_t*) t0)->f_dst);
        return t1;
    }
    if (l0.tag == 842u) {
        t0 = l0.payload.obj;
        t1 = vader_box_i32(163u, ((vader_struct_vader_midir_InstrStructNew_t*) t0)->f_dst);
        return t1;
    }
    if (l0.tag == 820u) {
        t0 = l0.payload.obj;
        t1 = vader_box_i32(163u, ((vader_struct_vader_midir_InstrArrayNew_t*) t0)->f_dst);
        return t1;
    }
    if (l0.tag == 843u) {
        t0 = l0.payload.obj;
        t1 = vader_box_i32(163u, ((vader_struct_vader_midir_InstrTypeCheck_t*) t0)->f_dst);
        return t1;
    }
    if (l0.tag == 844u) {
        t0 = l0.payload.obj;
        t1 = vader_box_i32(163u, ((vader_struct_vader_midir_InstrTypeConst_t*) t0)->f_dst);
        return t1;
    }
    if (l0.tag == 827u) {
        t0 = l0.payload.obj;
        t1 = vader_box_i32(163u, ((vader_struct_vader_midir_InstrCast_t*) t0)->f_dst);
        return t1;
    }
    if (l0.tag == 829u) {
        t0 = l0.payload.obj;
        t1 = vader_box_i32(163u, ((vader_struct_vader_midir_InstrCellNew_t*) t0)->f_dst);
        return t1;
    }
    if (l0.tag == 828u) {
        t0 = l0.payload.obj;
        t1 = vader_box_i32(163u, ((vader_struct_vader_midir_InstrCellGet_t*) t0)->f_dst);
        return t1;
    }
    if (l0.tag == 839u) {
        t0 = l0.payload.obj;
        t1 = vader_box_i32(163u, ((vader_struct_vader_midir_InstrMakeClosure_t*) t0)->f_dst);
        return t1;
    }
    if (l0.tag == 837u) {
        t0 = l0.payload.obj;
        t1 = vader_box_i32(163u, ((vader_struct_vader_midir_InstrFnRef_t*) t0)->f_dst);
        return t1;
    }
    if (l0.tag == 832u) {
        t0 = l0.payload.obj;
        t1 = vader_box_i32(163u, ((vader_struct_vader_midir_InstrDataConst_t*) t0)->f_dst);
        return t1;
    }
    if (l0.tag == 825u) {
        t0 = l0.payload.obj;
        return ((vader_struct_vader_midir_InstrCall_t*) t0)->f_dst;
    }
    if (l0.tag == 826u) {
        t0 = l0.payload.obj;
        return ((vader_struct_vader_midir_InstrCallIndirect_t*) t0)->f_dst;
    }
    if (l0.tag == 846u) {
        t0 = l0.payload.obj;
        return ((vader_struct_vader_midir_InstrVirtualCall_t*) t0)->f_dst;
    }
    if (l0.tag == 838u) {
        t0 = l0.payload.obj;
        return ((vader_struct_vader_midir_InstrIntrinsic_t*) t0)->f_dst;
    }
    if (l0.tag == 836u) {
        t1 = vader_box_obj(0u, NULL);
        return t1;
    }
    if (l0.tag == 822u) {
        t1 = vader_box_obj(0u, NULL);
        return t1;
    }
    if (l0.tag == 821u) {
        t1 = vader_box_obj(0u, NULL);
        return t1;
    }
    if (l0.tag == 830u) {
        t1 = vader_box_obj(0u, NULL);
        return t1;
    }
    if (l0.tag == 834u) {
        t1 = vader_box_obj(0u, NULL);
        return t1;
    }
    if (l0.tag == 833u) {
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
    vader_string_t l7, l9, l16, l17;
    vader_box_t t0 = vader_box_null();
    int64_t t1;
    void* t2 = NULL;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[14] = { &l0, &l1, &l2, &l3, &l4, &l8, &l10, &l11, &l12, &l15, &l18, &l19, &l20, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 14u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 161u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(15u, 0u, 0u, 170u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 163u);
    l3 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__string__Any_t* _a3_obj = (vader_struct_std_collections_MutableMap__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__Any_t));
    vader_obj_header_init(_a3_obj, 321u);
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
                vader_struct___Tuple_1276_t* _a6_obj = (vader_struct___Tuple_1276_t*) vader_gc_alloc(sizeof(vader_struct___Tuple_1276_t));
                vader_obj_header_init(_a6_obj, 217u);
                _a6_obj->f__0 = l7;
                _a6_obj->f__1 = l2;
                l8 = (void*) _a6_obj;
                l9 = ((vader_struct___Tuple_1276_t*) l8)->f__0;
                l10 = ((vader_struct___Tuple_1276_t*) l8)->f__1;
                t1 = (l6 + INT64_C(1));
                l6 = (size_t) (int64_t) t1;
                vader_array_t* _a7_arr = vader_array_new(69u, 0u, 13u, 800u);
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
                        } else {
                        }
                    }
                }
                l16 = ((vader_struct_vader_midir_CFGModule_t*) l10)->f_module_id;
                l17 = ((vader_struct_vader_midir_CFGModule_t*) l10)->f_display_path;
                l18 = ((vader_struct_vader_midir_CFGModule_t*) l10)->f_externs;
                l19 = ((vader_struct_vader_midir_CFGModule_t*) l10)->f_struct_decls;
                vader_struct_vader_midir_CFGModule_t* _a9_obj = (vader_struct_vader_midir_CFGModule_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_CFGModule_t));
                vader_obj_header_init(_a9_obj, 802u);
                _a9_obj->f_module_id = l16;
                _a9_obj->f_display_path = l17;
                _a9_obj->f_functions = l11;
                _a9_obj->f_externs = l18;
                _a9_obj->f_struct_decls = l19;
                l20 = (void*) _a9_obj;
                std_collections_put__string__Any(l1, l9, vader_ref_box(l20));
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
    vader_obj_header_init(_a10_obj, 804u);
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
    void* l9 = NULL;
    void* l15 = NULL;
    size_t l4, l5;
    vader_box_t l6 = vader_box_null(), l10 = vader_box_null();
    int64_t l7;
    int32_t l8, l16, l17;
    uint8_t l11, l12;
    bool l13, l14;
    int64_t t0;
    bool t1;
    vader_box_t t2 = vader_box_null();
    void* t3 = NULL;
    int32_t t4;
    size_t t5;
    vader_string_t t6;
    vader_box_t* gc_roots[3] = { &l6, &l10, &t2 };
    void** gc_raw_roots[5] = { &l0, &l3, &l9, &l15, &t3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
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
            } else {
            }
        }
    }
    l6 = ((vader_struct_vader_midir_BasicBlock_t*) l3)->f_terminator;
    if (l6.tag == 856u) {
        l3 = l6.payload.obj;
        if (!(((vader_struct_vader_midir_TermReturn_t*) l3)->f_value.tag == 0u)) {
            t1 = std_collections_contains_key__i32__bool(((vader_struct_std_collections_MutableSet__i32_t*) ((vader_struct_vader_midir_ScheduleHints_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_hints)->f_skip_terminator_get)->f_inner, l1);
            if (!(t1)) {
                t2 = ((vader_struct_vader_midir_TermReturn_t*) l3)->f_value;
                l8 = ((int32_t) t2.payload.i);
                l9 = ((vader_struct_vader_midir_TermReturn_t*) l3)->f_span;
                vader_midir_emit_get(l0, l8, l9);
            } else {
            }
            l9 = ((vader_struct_vader_midir_CFGFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_fn_)->f_locals;
            t0 = ((int64_t) ((vader_struct_vader_midir_TermReturn_t*) l3)->f_value.payload.i);
            l4 = (size_t) (int64_t) t0;
            vader_array_t* _a2_slotarr = ((vader_array_t*) l9);
            if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
            if ((size_t) l4 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
            t3 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
            l10 = ((vader_struct_vader_midir_CFGLocal_t*) t3)->f_type;
            l11 = vader_bytecode_val_type_of_type(l10);
            l12 = vader_bytecode_val_type_of_type(((vader_struct_vader_midir_CFGFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_fn_)->f_return_type);
            if (l12 == INT32_C(17)) {
                l13 = true;
            } else {
                l13 = l12 == INT32_C(18);
            }
            if (l11 == INT32_C(17)) {
                l14 = true;
            } else {
                l14 = l11 == INT32_C(18);
            }
            if (l14) {
                l14 = true;
            } else {
                l14 = l11 == INT32_C(16);
            }
            l14 = !(l14);
            if (l13) {
                l13 = l14;
            } else {
                l13 = false;
            }
            if (l13) {
                l9 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project;
                t4 = vader_bytecode_intern_type(l10, l9);
                vader_struct_vader_bytecode_Box_t* _a3_obj = (vader_struct_vader_bytecode_Box_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_Box_t));
                vader_obj_header_init(_a3_obj, 533u);
                _a3_obj->f_type_id = t4;
                l9 = (void*) _a3_obj;
                l15 = ((vader_struct_vader_midir_TermReturn_t*) l3)->f_span;
                vader_midir_push_emit(l0, vader_ref_box(l9), l15);
            } else {
            }
        } else {
        }
        l9 = ((vader_struct_vader_bytecode_BcFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_slot)->f_body;
        t5 = ((vader_array_t*) l9)->length;
        if ((t5 > INT64_C(0))) {
            t5 = ((vader_array_t*) l9)->length;
            t0 = (t5 - INT64_C(1));
            l4 = (size_t) (int64_t) t0;
            vader_array_t* _a4_slotarr = ((vader_array_t*) l9);
            if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
            if ((size_t) l4 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
            t2 = vader_array_ref_load_box(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l4);
            l10 = vader_bytecode_const_op_of(t2);
            if (!(l10.tag == 0u)) {
                t5 = ((vader_array_t*) l9)->length;
                t0 = (t5 - INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                vader_struct_vader_bytecode_ReturnLit_t* _a5_obj = (vader_struct_vader_bytecode_ReturnLit_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_ReturnLit_t));
                vader_obj_header_init(_a5_obj, 630u);
                _a5_obj->f_value = l10;
                l15 = (void*) _a5_obj;
                vader_array_t* _a6_slotarr = ((vader_array_t*) l9);
                if (_a6_slotarr->buf != NULL && _a6_slotarr->buf->header.forward != NULL) { _a6_slotarr->buf = vader_array_buf_forward(_a6_slotarr->buf); }
                if ((size_t) l4 >= _a6_slotarr->length) { vader_trap("array index out of bounds"); }
                vader_array_ref_store(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l4, l15);
                VADER_WRITE_BARRIER(_a6_slotarr->buf);
                { int32_t __vret = -(INT32_C(1)); vader_gc_top = gc_frame.prev; return __vret; }
            }
            vader_struct_vader_bytecode_Return_t* _a7_obj = (vader_struct_vader_bytecode_Return_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_Return_t));
            vader_obj_header_init(_a7_obj, 629u);
            l9 = (void*) _a7_obj;
            l15 = ((vader_struct_vader_midir_TermReturn_t*) l3)->f_span;
            vader_midir_push_emit(l0, vader_ref_box(l9), l15);
            { int32_t __vret = -(INT32_C(1)); vader_gc_top = gc_frame.prev; return __vret; }
        }
        vader_struct_vader_bytecode_Return_t* _a8_obj = (vader_struct_vader_bytecode_Return_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_Return_t));
        vader_obj_header_init(_a8_obj, 629u);
        l9 = (void*) _a8_obj;
        l15 = ((vader_struct_vader_midir_TermReturn_t*) l3)->f_span;
        vader_midir_push_emit(l0, vader_ref_box(l9), l15);
        { int32_t __vret = -(INT32_C(1)); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l6.tag == 857u) {
        l3 = l6.payload.obj;
        t1 = ((vader_struct_vader_midir_TermUnreachable_t*) l3)->f_trap;
        if (t1) {
            t6 = ((vader_struct_vader_midir_TermUnreachable_t*) l3)->f_reason;
            vader_struct_vader_bytecode_Unreachable_t* _a9_obj = (vader_struct_vader_bytecode_Unreachable_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_Unreachable_t));
            vader_obj_header_init(_a9_obj, 661u);
            _a9_obj->f_reason = t6;
            l9 = (void*) _a9_obj;
            l15 = ((vader_struct_vader_midir_TermUnreachable_t*) l3)->f_span;
            vader_midir_push_emit(l0, vader_ref_box(l9), l15);
        } else {
            vader_struct_vader_bytecode_Return_t* _a10_obj = (vader_struct_vader_bytecode_Return_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_Return_t));
            vader_obj_header_init(_a10_obj, 629u);
            l9 = (void*) _a10_obj;
            l3 = ((vader_struct_vader_midir_TermUnreachable_t*) l3)->f_span;
            vader_midir_push_emit(l0, vader_ref_box(l9), l3);
        }
        { int32_t __vret = -(INT32_C(1)); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l6.tag == 854u) {
        l3 = l6.payload.obj;
        l8 = ((vader_struct_vader_midir_TermBranch_t*) l3)->f_target;
        l16 = l2;
        if (l8 == l16) {
            { int32_t __vret = -(INT32_C(1)); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l8 = ((vader_struct_vader_midir_TermBranch_t*) l3)->f_target;
        t1 = vader_midir_scope_contains_target(l0, l8);
        if (t1) {
            l9 = ((vader_struct_vader_midir_TermBranch_t*) l3)->f_span;
            l8 = ((vader_struct_vader_midir_TermBranch_t*) l3)->f_target;
            vader_midir_cf_br(l0, l9, l8);
            { int32_t __vret = -(INT32_C(1)); vader_gc_top = gc_frame.prev; return __vret; }
        }
        { int32_t __vret = ((vader_struct_vader_midir_TermBranch_t*) l3)->f_target; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l6.tag == 855u) {
        l3 = l6.payload.obj;
        l8 = vader_midir_cond_branch_merge(l0, l1, l2);
        t1 = std_collections_contains_key__i32__bool(((vader_struct_std_collections_MutableSet__i32_t*) ((vader_struct_vader_midir_ScheduleHints_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_hints)->f_skip_terminator_get)->f_inner, l1);
        if (!(t1)) {
            l16 = ((vader_struct_vader_midir_TermCondBranch_t*) l3)->f_cond;
            l9 = ((vader_struct_vader_midir_TermCondBranch_t*) l3)->f_span;
            vader_midir_emit_get(l0, l16, l9);
        } else {
        }
        l9 = ((vader_struct_vader_midir_TermCondBranch_t*) l3)->f_span;
        vader_midir_cf_if(l0, l9, l8);
        if ((l8 < INT32_C(0))) {
            l13 = true;
        } else {
            l16 = ((vader_struct_vader_midir_TermCondBranch_t*) l3)->f_then_block;
            l17 = l8;
            l13 = !(l16 == l17);
        }
        if (l13) {
            l16 = ((vader_struct_vader_midir_TermCondBranch_t*) l3)->f_then_block;
            vader_midir_emit_range(l0, l16, l8);
        } else {
        }
        l9 = ((vader_struct_vader_bytecode_BcFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_slot)->f_body;
        l4 = ((vader_array_t*) l9)->length;
        l13 = false;
        if ((l4 > INT64_C(0))) {
            t0 = (l4 - INT64_C(1));
            l4 = (size_t) (int64_t) t0;
            vader_array_t* _a11_slotarr = ((vader_array_t*) l9);
            if (_a11_slotarr->buf != NULL && _a11_slotarr->buf->header.forward != NULL) { _a11_slotarr->buf = vader_array_buf_forward(_a11_slotarr->buf); }
            if ((size_t) l4 >= _a11_slotarr->length) { vader_trap("array index out of bounds"); }
            l6 = vader_array_ref_load_box(_a11_slotarr->buf, _a11_slotarr->offset + (size_t) l4);
            if (l6.tag == 629u) {
                l13 = true;
            } else {
            }
            if (l6.tag == 630u) {
                l13 = true;
            } else {
            }
            if (l6.tag == 534u) {
                l13 = true;
            } else {
            }
        } else {
        }
        if (l13) {
            l16 = ((vader_struct_vader_midir_TermCondBranch_t*) l3)->f_else_block;
            l17 = l8;
            l13 = !(l16 == l17);
        } else {
            l13 = false;
        }
        if (l13) {
            l9 = ((vader_struct_vader_midir_TermCondBranch_t*) l3)->f_span;
            vader_midir_cf_end(l0, l9);
            { int32_t __vret = ((vader_struct_vader_midir_TermCondBranch_t*) l3)->f_else_block; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l9 = ((vader_struct_vader_midir_TermCondBranch_t*) l3)->f_span;
        vader_midir_cf_else(l0, l9);
        if ((l8 < INT32_C(0))) {
            l13 = true;
        } else {
            l16 = ((vader_struct_vader_midir_TermCondBranch_t*) l3)->f_else_block;
            l17 = l8;
            l13 = !(l16 == l17);
        }
        if (l13) {
            l16 = ((vader_struct_vader_midir_TermCondBranch_t*) l3)->f_else_block;
            vader_midir_emit_range(l0, l16, l8);
        } else {
        }
        l3 = ((vader_struct_vader_midir_TermCondBranch_t*) l3)->f_span;
        vader_midir_cf_end(l0, l3);
        { int32_t __vret = l8; vader_gc_top = gc_frame.prev; return __vret; }
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
    vader_string_t l9, l26, l41, l42;
    int32_t l20, l24;
    vader_box_t l21 = vader_box_null(), l27 = vader_box_null();
    bool l28;
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    int64_t t2;
    vader_string_t t3;
    bool t4;
    size_t t5;
    vader_box_t* gc_roots[3] = { &l21, &l27, &t0 };
    void** gc_raw_roots[26] = { &l0, &l2, &l3, &l4, &l5, &l6, &l10, &l11, &l14, &l17, &l22, &l23, &l25, &l29, &l30, &l31, &l32, &l33, &l34, &l35, &l36, &l37, &l38, &l39, &l40, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 26u, gc_roots, gc_raw_roots, 0u, NULL };
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
                vader_struct___Tuple_1276_t* _a2_obj = (vader_struct___Tuple_1276_t*) vader_gc_alloc(sizeof(vader_struct___Tuple_1276_t));
                vader_obj_header_init(_a2_obj, 217u);
                _a2_obj->f__0 = l9;
                _a2_obj->f__1 = l4;
                t1 = (void*) _a2_obj;
                l10 = ((vader_struct___Tuple_1276_t*) t1)->f__1;
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
                        } else {
                        }
                    }
                }
                l14 = ((vader_struct_vader_midir_CFGModule_t*) l10)->f_externs;
                l15 = ((vader_array_t*) l14)->length;
                l16 = (size_t) (int64_t) INT64_C(0);
                {
                    loop_71: {
                        if ((l16 < l15)) {
                            vader_array_t* _a4_slotarr = ((vader_array_t*) l14);
                            if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                            if ((size_t) l16 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                            t1 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l16);
                            vader_midir_reserve_cfg_extern(t1, l3);
                            t2 = (l16 + INT64_C(1));
                            l16 = (size_t) (int64_t) t2;
                            goto loop_71;
                        } else {
                        }
                    }
                }
                l17 = ((vader_struct_vader_midir_CFGModule_t*) l10)->f_struct_decls;
                l18 = ((vader_array_t*) l17)->length;
                l19 = (size_t) (int64_t) INT64_C(0);
                {
                    loop_97: {
                        if ((l19 < l18)) {
                            vader_array_t* _a5_slotarr = ((vader_array_t*) l17);
                            if (_a5_slotarr->buf != NULL && _a5_slotarr->buf->header.forward != NULL) { _a5_slotarr->buf = vader_array_buf_forward(_a5_slotarr->buf); }
                            if ((size_t) l19 >= _a5_slotarr->length) { vader_trap("array index out of bounds"); }
                            t1 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l19);
                            vader_midir_reserve_cfg_struct(t1, l3);
                            t2 = (l19 + INT64_C(1));
                            l19 = (size_t) (int64_t) t2;
                            goto loop_97;
                        } else {
                        }
                    }
                }
                goto loop_14;
            }
        }
    }
    vader_midir_synthesise_cfg_intrinsic_wrappers(l0, l3);
    vader_array_t* _a6_arr = vader_array_new(9u, 0u, 7u, 163u);
    l4 = (void*) _a6_arr;
    l5 = ((vader_struct_vader_midir_CFGProject_t*) l0)->f_strings;
    l7 = ((vader_array_t*) l5)->length;
    l8 = (size_t) (int64_t) INT64_C(0);
    {
        loop_132: {
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
                goto loop_132;
            } else {
            }
        }
    }
    l5 = ((vader_struct_vader_midir_CFGProject_t*) l0)->f_data_pool;
    l7 = ((vader_array_t*) l5)->length;
    l8 = (size_t) (int64_t) INT64_C(0);
    {
        loop_163: {
            if ((l8 < l7)) {
                vader_array_t* _a8_slotarr = ((vader_array_t*) l5);
                if (_a8_slotarr->buf != NULL && _a8_slotarr->buf->header.forward != NULL) { _a8_slotarr->buf = vader_array_buf_forward(_a8_slotarr->buf); }
                if ((size_t) l8 >= _a8_slotarr->length) { vader_trap("array index out of bounds"); }
                l21 = vader_array_ref_load_box(_a8_slotarr->buf, _a8_slotarr->offset + (size_t) l8);
                if (l21.tag == 517u) {
                    t1 = l21.payload.obj;
                    l6 = ((vader_struct_vader_bytecode_BcStrData_t*) t1)->f_values;
                    l12 = ((vader_array_t*) l6)->length;
                    l13 = (size_t) (int64_t) INT64_C(0);
                    {
                        loop_183: {
                            if ((l13 < l12)) {
                                vader_array_t* _a9_slotarr = ((vader_array_t*) l6);
                                if (_a9_slotarr->buf != NULL && _a9_slotarr->buf->header.forward != NULL) { _a9_slotarr->buf = vader_array_buf_forward(_a9_slotarr->buf); }
                                if ((size_t) l13 >= _a9_slotarr->length) { vader_trap("array index out of bounds"); }
                                t0 = vader_array_box_slots(_a9_slotarr->buf)[_a9_slotarr->offset + (size_t) l13];
                                t3 = t0.payload.s;
                                vader_bytecode_intern_string(t3, l3);
                                t2 = (l13 + INT64_C(1));
                                l13 = (size_t) (int64_t) t2;
                                goto loop_183;
                            } else {
                            }
                        }
                    }
                } else {
                    if (l21.tag == 504u) {
                        t1 = l21.payload.obj;
                        l10 = ((vader_struct_vader_bytecode_BcAggregateData_t*) t1)->f_elements;
                        l15 = ((vader_array_t*) l10)->length;
                        l16 = (size_t) (int64_t) INT64_C(0);
                        {
                            loop_217: {
                                if ((l16 < l15)) {
                                    vader_array_t* _a10_slotarr = ((vader_array_t*) l10);
                                    if (_a10_slotarr->buf != NULL && _a10_slotarr->buf->header.forward != NULL) { _a10_slotarr->buf = vader_array_buf_forward(_a10_slotarr->buf); }
                                    if ((size_t) l16 >= _a10_slotarr->length) { vader_trap("array index out of bounds"); }
                                    t0 = vader_array_ref_load_box(_a10_slotarr->buf, _a10_slotarr->offset + (size_t) l16);
                                    vader_midir_intern_data_value_strings(t0, l3);
                                    t2 = (l16 + INT64_C(1));
                                    l16 = (size_t) (int64_t) t2;
                                    goto loop_217;
                                } else {
                                }
                            }
                        }
                    } else {
                    }
                }
                t2 = (l8 + INT64_C(1));
                l8 = (size_t) (int64_t) t2;
                goto loop_163;
            } else {
            }
        }
    }
    l5 = ((vader_struct_vader_midir_CFGProject_t*) l0)->f_modules;
    l6 = ((vader_struct_std_collections_MutableMap__string__CFGModule_t*) l5)->f_ekeys;
    l10 = ((vader_struct_std_collections_MutableMap__string__CFGModule_t*) l5)->f_evals;
    l7 = ((vader_struct_std_collections_MutableMap__string__CFGModule_t*) l5)->f_size;
    l8 = (size_t) (int64_t) INT64_C(0);
    {
        loop_260: {
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
                vader_struct___Tuple_1276_t* _a13_obj = (vader_struct___Tuple_1276_t*) vader_gc_alloc(sizeof(vader_struct___Tuple_1276_t));
                vader_obj_header_init(_a13_obj, 217u);
                _a13_obj->f__0 = l9;
                _a13_obj->f__1 = l5;
                t1 = (void*) _a13_obj;
                l11 = ((vader_struct___Tuple_1276_t*) t1)->f__1;
                t2 = (l8 + INT64_C(1));
                l8 = (size_t) (int64_t) t2;
                l14 = ((vader_struct_vader_midir_CFGModule_t*) l11)->f_functions;
                l12 = ((vader_array_t*) l14)->length;
                l13 = (size_t) (int64_t) INT64_C(0);
                {
                    loop_291: {
                        if ((l13 < l12)) {
                            vader_array_t* _a14_slotarr = ((vader_array_t*) l14);
                            if (_a14_slotarr->buf != NULL && _a14_slotarr->buf->header.forward != NULL) { _a14_slotarr->buf = vader_array_buf_forward(_a14_slotarr->buf); }
                            if ((size_t) l13 >= _a14_slotarr->length) { vader_trap("array index out of bounds"); }
                            l17 = vader_array_ref_load_obj(_a14_slotarr->buf, _a14_slotarr->offset + (size_t) l13);
                            t4 = ((vader_struct_vader_midir_CFGFunction_t*) l17)->f_is_extern;
                            if (t4) {
                                t2 = (l13 + INT64_C(1));
                                l13 = (size_t) (int64_t) t2;
                                goto loop_291;
                            }
                            l20 = -(INT32_C(1));
                            if (((vader_struct_vader_comptime_MonoEntry_t*) ((vader_struct_vader_midir_CFGFunction_t*) l17)->f_origin)->f_symbol.tag == 893u) {
                                l22 = ((vader_struct_vader_comptime_MonoEntry_t*) ((vader_struct_vader_midir_CFGFunction_t*) l17)->f_origin)->f_symbol.payload.obj;
                                l23 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l3)->f_function_index_by_symbol_id;
                                l24 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l22)->f_id;
                                l21 = std_collections_get__i32__i32(l23, l24);
                                if (l21.tag == 163u) {
                                    l20 = ((int32_t) l21.payload.i);
                                } else {
                                }
                            } else {
                            }
                            if ((l20 < INT32_C(0))) {
                                l25 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l3)->f_function_index_by_mangle;
                                l26 = ((vader_struct_vader_midir_CFGFunction_t*) l17)->f_mangled;
                                l27 = std_collections_get__string__i32(l25, l26);
                                if (l27.tag == 163u) {
                                    l20 = ((int32_t) l27.payload.i);
                                } else {
                                }
                            } else {
                            }
                            if ((l20 >= INT32_C(0))) {
                                l28 = ((vader_struct_vader_bytecode_EmitOptions_t*) l2)->f_want_debug;
                                vader_midir_emit_cfg_function_body(l17, l20, l3, l4, l28);
                            } else {
                            }
                            t2 = (l13 + INT64_C(1));
                            l13 = (size_t) (int64_t) t2;
                            goto loop_291;
                        } else {
                        }
                    }
                }
                goto loop_260;
            }
        }
    }
    t4 = ((vader_struct_vader_bytecode_EmitOptions_t*) l2)->f_optimize;
    if (t4) {
        l7 = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l3)->f_functions)->length;
        l8 = (size_t) (int64_t) INT64_C(0);
        {
            loop_397: {
                if ((l8 < l7)) {
                    vader_array_t* _a15_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l3)->f_functions);
                    if (_a15_slotarr->buf != NULL && _a15_slotarr->buf->header.forward != NULL) { _a15_slotarr->buf = vader_array_buf_forward(_a15_slotarr->buf); }
                    if ((size_t) l8 >= _a15_slotarr->length) { vader_trap("array index out of bounds"); }
                    t1 = vader_array_ref_load_obj(_a15_slotarr->buf, _a15_slotarr->offset + (size_t) l8);
                    t5 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) t1)->f_body)->length;
                    t2 = (t5 + INT64_C(1));
                    l12 = (size_t) (int64_t) t2;
                    {
                        loop_411: {
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
                                goto loop_411;
                            } else {
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
                    goto loop_397;
                } else {
                }
            }
        }
        vader_array_t* _a31_arr = vader_array_new(8u, 0u, 0u, 161u);
        l4 = (void*) _a31_arr;
        vader_array_t* _a32_arr = vader_array_new(6u, 0u, 12u, 159u);
        l5 = (void*) _a32_arr;
        vader_array_t* _a33_arr = vader_array_new(9u, 0u, 7u, 163u);
        l6 = (void*) _a33_arr;
        vader_struct_std_collections_MutableMap__string__bool_t* _a34_obj = (vader_struct_std_collections_MutableMap__string__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__bool_t));
        vader_obj_header_init(_a34_obj, 368u);
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
            loop_570: {
                if ((l8 < l7)) {
                    vader_array_t* _a35_slotarr = ((vader_array_t*) l5);
                    if (_a35_slotarr->buf != NULL && _a35_slotarr->buf->header.forward != NULL) { _a35_slotarr->buf = vader_array_buf_forward(_a35_slotarr->buf); }
                    if ((size_t) l8 >= _a35_slotarr->length) { vader_trap("array index out of bounds"); }
                    t1 = vader_array_ref_load_obj(_a35_slotarr->buf, _a35_slotarr->offset + (size_t) l8);
                    l6 = ((vader_struct_vader_bytecode_BcFunction_t*) t1)->f_body;
                    l12 = ((vader_array_t*) l6)->length;
                    l13 = (size_t) (int64_t) INT64_C(0);
                    {
                        loop_585: {
                            if ((l13 < l12)) {
                                vader_array_t* _a36_slotarr = ((vader_array_t*) l6);
                                if (_a36_slotarr->buf != NULL && _a36_slotarr->buf->header.forward != NULL) { _a36_slotarr->buf = vader_array_buf_forward(_a36_slotarr->buf); }
                                if ((size_t) l13 >= _a36_slotarr->length) { vader_trap("array index out of bounds"); }
                                l21 = vader_array_ref_load_box(_a36_slotarr->buf, _a36_slotarr->offset + (size_t) l13);
                                if (l21.tag == 662u) {
                                    t1 = l21.payload.obj;
                                    l9 = ((vader_struct_vader_bytecode_VirtualCall_t*) t1)->f_vtable_key;
                                    std_collections_put__string__bool(l4, l9, true);
                                } else {
                                }
                                t2 = (l13 + INT64_C(1));
                                l13 = (size_t) (int64_t) t2;
                                goto loop_585;
                            } else {
                            }
                        }
                    }
                    t2 = (l8 + INT64_C(1));
                    l8 = (size_t) (int64_t) t2;
                    goto loop_570;
                } else {
                }
            }
        }
        vader_array_t* _a37_arr = vader_array_new(9u, 0u, 7u, 163u);
        l5 = (void*) _a37_arr;
        l6 = ((vader_struct_vader_midir_CFGProject_t*) l0)->f_vtable_entries;
        l7 = ((vader_array_t*) l6)->length;
        l8 = (size_t) (int64_t) INT64_C(0);
        {
            loop_634: {
                if ((l8 < l7)) {
                    vader_array_t* _a38_slotarr = ((vader_array_t*) l6);
                    if (_a38_slotarr->buf != NULL && _a38_slotarr->buf->header.forward != NULL) { _a38_slotarr->buf = vader_array_buf_forward(_a38_slotarr->buf); }
                    if ((size_t) l8 >= _a38_slotarr->length) { vader_trap("array index out of bounds"); }
                    l10 = vader_array_ref_load_obj(_a38_slotarr->buf, _a38_slotarr->offset + (size_t) l8);
                    l9 = ((vader_struct_vader_lower_LoweredVtableEntry_t*) l10)->f_trait_name;
                    l26 = ((vader_struct_vader_lower_LoweredVtableEntry_t*) l10)->f_method_name;
                    l41 = concat_3(l9, 397u, l26);
                    t0 = std_collections_get__string__bool(l4, l41);
                    if (!(t0.tag == 159u)) {
                        t2 = (l8 + INT64_C(1));
                        l8 = (size_t) (int64_t) t2;
                        goto loop_634;
                    }
                    l42 = vader_bytecode_type_intern_key(((vader_struct_vader_lower_LoweredVtableEntry_t*) l10)->f_struct_type);
                    l21 = std_collections_get__string__i32(((vader_struct_vader_bytecode_EmitterCtx_t*) l3)->f_type_key, l42);
                    if (l21.tag == 163u) {
                        l20 = ((int32_t) l21.payload.i);
                        vader_array_push_i32((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l3)->f_pinned_types, l20);
                    } else {
                    }
                    l24 = vader_midir_resolve_vtable_fn_index(((vader_struct_vader_lower_LoweredVtableEntry_t*) l10)->f_fn_symbol, l3);
                    if ((l24 >= INT32_C(0))) {
                        vader_array_push_i32((vader_array_t*) l5, l24);
                    } else {
                    }
                    t2 = (l8 + INT64_C(1));
                    l8 = (size_t) (int64_t) t2;
                    goto loop_634;
                } else {
                }
            }
        }
        l4 = ((vader_struct_vader_bytecode_EmitOptions_t*) l2)->f_keep_mangles;
        vader_bytecode_prune_unused_functions(l3, l5, l4);
        vader_bytecode_prune_unused_imports(l3);
        vader_bytecode_prune_unused_types(l3);
        l4 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l3)->f_imports;
        l7 = ((vader_array_t*) l4)->length;
        l8 = (size_t) (int64_t) INT64_C(0);
        {
            loop_721: {
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
                    goto loop_721;
                } else {
                }
            }
        }
    } else {
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
    vader_obj_header_init(_a40_obj, 539u);
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
    vader_string_t l16;
    uint8_t l17;
    int64_t t0;
    size_t t1;
    void* t2 = NULL;
    void** gc_raw_roots[17] = { &l0, &l2, &l3, &l5, &l7, &l8, &l15, &l18, &l19, &l20, &l21, &l22, &l23, &l24, &l25, &l26, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 17u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l5 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l2)->f_functions;
    t0 = ((int64_t) (int32_t) l1);
    l6 = (size_t) (int64_t) t0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    if ((size_t) l6 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
    l5 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l6);
    vader_array_t* _a1_arr = vader_array_new(9u, 0u, 7u, 163u);
    l7 = (void*) _a1_arr;
    std_collections_put__i32__Any(((vader_struct_vader_bytecode_EmitterCtx_t*) l2)->f_pinned_types_by_fn, l1, vader_ref_box(l7));
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 163u);
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
                    vader_obj_header_init(_a4_obj, 511u);
                    _a4_obj->f_name = l16;
                    _a4_obj->f_val = l17;
                    l18 = (void*) _a4_obj;
                    vader_array_push((vader_array_t*) l15, vader_ref_box(l18));
                    vader_array_push_i32((vader_array_t*) l8, l14);
                }
                t0 = (l10 + INT64_C(1));
                l10 = (size_t) (int64_t) t0;
                goto loop_26;
            } else {
            }
        }
    }
    l15 = vader_midir_predecessors_of(l0);
    l18 = vader_midir_compute_dominators(l0, l15);
    l19 = vader_midir_compute_post_dominators(l0);
    l20 = vader_midir_find_loop_exits(l0, l15, l18);
    l21 = vader_midir_schedule_stack(l0);
    vader_array_t* _a5_arr = vader_array_new(78u, 0u, 13u, 853u);
    l22 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(77u, 0u, 13u, 850u);
    l23 = (void*) _a6_arr;
    vader_array_t* _a7_arr = vader_array_new(9u, 0u, 7u, 163u);
    l24 = (void*) _a7_arr;
    vader_array_t* _a8_arr = vader_array_new(6u, 0u, 12u, 159u);
    l25 = (void*) _a8_arr;
    vader_array_t* _a9_arr = vader_array_new(9u, 0u, 7u, 163u);
    l26 = (void*) _a9_arr;
    vader_struct_std_collections_MutableMap__i32__bool_t* _a10_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
    vader_obj_header_init(_a10_obj, 310u);
    _a10_obj->f_ekeys = l24;
    _a10_obj->f_evals = l25;
    _a10_obj->f_index = l26;
    _a10_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a10_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a10_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    t2 = (void*) _a10_obj;
    vader_struct_std_collections_MutableSet__i32_t* _a11_obj = (vader_struct_std_collections_MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i32_t));
    vader_obj_header_init(_a11_obj, 387u);
    _a11_obj->f_inner = t2;
    l24 = (void*) _a11_obj;
    vader_struct_vader_midir_FnEmitCfg_t* _a12_obj = (vader_struct_vader_midir_FnEmitCfg_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_FnEmitCfg_t));
    vader_obj_header_init(_a12_obj, 816u);
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

static int32_t vader_midir_emit_const(void* l0, vader_box_t l1, vader_box_t l2, void* l3) {
    int32_t l4;
    void* l5 = NULL;
    vader_box_t* gc_roots[2] = { &l1, &l2 };
    void** gc_raw_roots[3] = { &l0, &l3, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l4 = vader_midir_fresh_tmp(l0, 1658u, l1);
    vader_struct_vader_midir_InstrConst_t* _a0_obj = (vader_struct_vader_midir_InstrConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrConst_t));
    vader_obj_header_init(_a0_obj, 831u);
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
    void* l6 = NULL;
    size_t l7;
    int32_t l8;
    uint8_t t0;
    bool t1;
    int64_t t2;
    void* t3 = NULL;
    double t4;
    int32_t t5;
    vader_box_t* gc_roots[1] = { &l3 };
    void** gc_raw_roots[6] = { &l0, &l1, &l4, &l5, &l6, &t3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 6u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_midir_InstrConst_t*) l1)->f_value;
    if (l3.tag == 810u) {
        l4 = l3.payload.obj;
        t0 = vader_bytecode_val_type_of_type(((vader_struct_vader_midir_InstrConst_t*) l1)->f_type);
        t1 = vader_bytecode_is_64_bit_int_val(t0);
        if (t1) {
            t2 = ((vader_struct_vader_midir_ConstInt_t*) l4)->f_value;
            vader_struct_vader_bytecode_I64Const_t* _a0_obj = (vader_struct_vader_bytecode_I64Const_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64Const_t));
            vader_obj_header_init(_a0_obj, 594u);
            _a0_obj->f_value = t2;
            l5 = (void*) _a0_obj;
            l6 = ((vader_struct_vader_midir_InstrConst_t*) l1)->f_span;
            vader_midir_push_emit(l0, vader_ref_box(l5), l6);
        } else {
            t2 = ((vader_struct_vader_midir_ConstInt_t*) l4)->f_value;
            vader_struct_vader_bytecode_I32Const_t* _a1_obj = (vader_struct_vader_bytecode_I32Const_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32Const_t));
            vader_obj_header_init(_a1_obj, 574u);
            _a1_obj->f_value = ((int32_t) (int64_t) t2);
            l4 = (void*) _a1_obj;
            l5 = ((vader_struct_vader_midir_InstrConst_t*) l1)->f_span;
            vader_midir_push_emit(l0, vader_ref_box(l4), l5);
        }
    } else {
        if (l3.tag == 809u) {
            t3 = l3.payload.obj;
            t4 = ((vader_struct_vader_midir_ConstFloat_t*) t3)->f_value;
            vader_struct_vader_bytecode_F64Const_t* _a2_obj = (vader_struct_vader_bytecode_F64Const_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_F64Const_t));
            vader_obj_header_init(_a2_obj, 556u);
            _a2_obj->f_value = t4;
            l4 = (void*) _a2_obj;
            l5 = ((vader_struct_vader_midir_InstrConst_t*) l1)->f_span;
            vader_midir_push_emit(l0, vader_ref_box(l4), l5);
        } else {
            if (l3.tag == 807u) {
                t3 = l3.payload.obj;
                t1 = ((vader_struct_vader_midir_ConstBool_t*) t3)->f_value;
                vader_struct_vader_bytecode_BoolConst_t* _a3_obj = (vader_struct_vader_bytecode_BoolConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BoolConst_t));
                vader_obj_header_init(_a3_obj, 528u);
                _a3_obj->f_value = t1;
                l4 = (void*) _a3_obj;
                l5 = ((vader_struct_vader_midir_InstrConst_t*) l1)->f_span;
                vader_midir_push_emit(l0, vader_ref_box(l4), l5);
            } else {
                if (l3.tag == 808u) {
                    t3 = l3.payload.obj;
                    t5 = ((vader_struct_vader_midir_ConstChar_t*) t3)->f_value;
                    vader_struct_vader_bytecode_CharConst_t* _a4_obj = (vader_struct_vader_bytecode_CharConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_CharConst_t));
                    vader_obj_header_init(_a4_obj, 543u);
                    _a4_obj->f_value = ((uint32_t) (int32_t) t5);
                    l4 = (void*) _a4_obj;
                    l5 = ((vader_struct_vader_midir_InstrConst_t*) l1)->f_span;
                    vader_midir_push_emit(l0, vader_ref_box(l4), l5);
                } else {
                    if (l3.tag == 811u) {
                        vader_struct_vader_bytecode_NullConst_t* _a5_obj = (vader_struct_vader_bytecode_NullConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_NullConst_t));
                        vader_obj_header_init(_a5_obj, 625u);
                        l4 = (void*) _a5_obj;
                        l5 = ((vader_struct_vader_midir_InstrConst_t*) l1)->f_span;
                        vader_midir_push_emit(l0, vader_ref_box(l4), l5);
                    } else {
                        if (l3.tag == 812u) {
                            l4 = l3.payload.obj;
                            l5 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_string_index_map;
                            t5 = ((vader_struct_vader_midir_ConstString_t*) l4)->f_index;
                            t2 = ((int64_t) (int32_t) t5);
                            l7 = (size_t) (int64_t) t2;
                            vader_array_t* _a6_slotarr = ((vader_array_t*) l5);
                            if (_a6_slotarr->buf != NULL && _a6_slotarr->buf->header.forward != NULL) { _a6_slotarr->buf = vader_array_buf_forward(_a6_slotarr->buf); }
                            if ((size_t) l7 >= _a6_slotarr->length) { vader_trap("array index out of bounds"); }
                            t5 = ((int32_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l7];
                            vader_struct_vader_bytecode_StringConst_t* _a7_obj = (vader_struct_vader_bytecode_StringConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_StringConst_t));
                            vader_obj_header_init(_a7_obj, 640u);
                            _a7_obj->f_index = t5;
                            l4 = (void*) _a7_obj;
                            l5 = ((vader_struct_vader_midir_InstrConst_t*) l1)->f_span;
                            vader_midir_push_emit(l0, vader_ref_box(l4), l5);
                        } else {
                        }
                    }
                }
            }
        }
    }
    l8 = ((vader_struct_vader_midir_InstrConst_t*) l1)->f_dst;
    l4 = ((vader_struct_vader_midir_InstrConst_t*) l1)->f_span;
    vader_midir_emit_result(l0, l2, l8, l4);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_midir_emit_first_get(void* l0, int64_t l1, int32_t l2, void* l3) {
    bool t0;
    void** gc_raw_roots[2] = { &l0, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = std_collections_contains_key__i64__bool(((vader_struct_std_collections_MutableSet__i64_t*) ((vader_struct_vader_midir_ScheduleHints_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_hints)->f_skip_first_get)->f_inner, l1);
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
    void* l5 = NULL;
    void* l10 = NULL;
    void* l12 = NULL;
    void* l14 = NULL;
    int32_t l4, l15, l23;
    size_t l6, l11, l13;
    vader_box_t l7 = vader_box_null(), l20 = vader_box_null();
    uint8_t l8, l9;
    vader_string_t l16, l17, l21;
    int64_t l18;
    bool l19, l22;
    int64_t t0;
    void* t1 = NULL;
    int32_t t2;
    vader_string_t t3;
    size_t t4;
    bool t5;
    vader_box_t* gc_roots[3] = { &l1, &l7, &l20 };
    void** gc_raw_roots[7] = { &l0, &l3, &l5, &l10, &l12, &l14, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 7u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l1.tag == 831u) {
        l3 = l1.payload.obj;
        vader_midir_emit_const_instr(l0, l3, l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 840u) {
        l3 = l1.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrMove_t*) l3)->f_src;
        l5 = ((vader_struct_vader_midir_InstrMove_t*) l3)->f_span;
        vader_midir_emit_first_get(l0, l2, l4, l5);
        l4 = ((vader_struct_vader_midir_InstrMove_t*) l3)->f_dst;
        l3 = ((vader_struct_vader_midir_InstrMove_t*) l3)->f_span;
        vader_midir_emit_result(l0, l2, l4, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 824u) {
        l3 = l1.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrBinOp_t*) l3)->f_lhs;
        l5 = ((vader_struct_vader_midir_InstrBinOp_t*) l3)->f_span;
        vader_midir_emit_first_get(l0, l2, l4, l5);
        l4 = ((vader_struct_vader_midir_InstrBinOp_t*) l3)->f_rhs;
        l5 = ((vader_struct_vader_midir_InstrBinOp_t*) l3)->f_span;
        vader_midir_emit_get(l0, l4, l5);
        l5 = ((vader_struct_vader_midir_CFGFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_fn_)->f_locals;
        t0 = ((int64_t) (int32_t) ((vader_struct_vader_midir_InstrBinOp_t*) l3)->f_lhs);
        l6 = (size_t) (int64_t) t0;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
        if ((size_t) l6 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
        t1 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l6);
        l7 = ((vader_struct_vader_midir_CFGLocal_t*) t1)->f_type;
        l8 = ((vader_struct_vader_midir_InstrBinOp_t*) l3)->f_op;
        l9 = vader_bytecode_val_type_of_type(l7);
        l7 = vader_bytecode_binary_op_for(l8, l9);
        l5 = ((vader_struct_vader_midir_InstrBinOp_t*) l3)->f_span;
        vader_midir_push_emit(l0, l7, l5);
        l4 = ((vader_struct_vader_midir_InstrBinOp_t*) l3)->f_dst;
        l3 = ((vader_struct_vader_midir_InstrBinOp_t*) l3)->f_span;
        vader_midir_emit_result(l0, l2, l4, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 825u) {
        l3 = l1.payload.obj;
        l5 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_pinned_types_bucket;
        l10 = ((vader_struct_vader_midir_InstrCall_t*) l3)->f_args;
        l6 = ((vader_array_t*) l10)->length;
        l11 = (size_t) (int64_t) INT64_C(0);
        {
            loop_113: {
                if ((l11 < l6)) {
                    vader_array_t* _a1_slotarr = ((vader_array_t*) l10);
                    if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                    if ((size_t) l11 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                    l4 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l11];
                    l12 = ((vader_struct_vader_midir_CFGFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_fn_)->f_locals;
                    t0 = ((int64_t) (int32_t) l4);
                    l13 = (size_t) (int64_t) t0;
                    vader_array_t* _a2_slotarr = ((vader_array_t*) l12);
                    if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                    if ((size_t) l13 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                    t1 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l13);
                    l7 = ((vader_struct_vader_midir_CFGLocal_t*) t1)->f_type;
                    l14 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project;
                    l15 = vader_bytecode_intern_type(l7, l14);
                    vader_array_push_i32((vader_array_t*) l5, l15);
                    t0 = (l11 + INT64_C(1));
                    l11 = (size_t) (int64_t) t0;
                    goto loop_113;
                } else {
                }
            }
        }
        if (((vader_struct_vader_midir_InstrCall_t*) l3)->f_dst.tag == 163u) {
            l4 = ((int32_t) ((vader_struct_vader_midir_InstrCall_t*) l3)->f_dst.payload.i);
            l10 = ((vader_struct_vader_midir_CFGFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_fn_)->f_locals;
            t0 = ((int64_t) (int32_t) l4);
            l6 = (size_t) (int64_t) t0;
            vader_array_t* _a3_slotarr = ((vader_array_t*) l10);
            if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
            if ((size_t) l6 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
            t1 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l6);
            l7 = ((vader_struct_vader_midir_CFGLocal_t*) t1)->f_type;
            l10 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project;
            l4 = vader_bytecode_intern_type(l7, l10);
            vader_array_push_i32((vader_array_t*) l5, l4);
        } else {
        }
        l6 = ((vader_array_t*) ((vader_struct_vader_midir_InstrCall_t*) l3)->f_args)->length;
        l11 = (size_t) (int64_t) INT64_C(0);
        {
            loop_185: {
                if ((l11 < l6)) {
                    if (l11 == INT64_C(0)) {
                        vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_vader_midir_InstrCall_t*) l3)->f_args);
                        if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                        if ((size_t) l11 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                        l4 = ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l11];
                        l5 = ((vader_struct_vader_midir_InstrCall_t*) l3)->f_span;
                        vader_midir_emit_first_get(l0, l2, l4, l5);
                    } else {
                        vader_array_t* _a5_slotarr = ((vader_array_t*) ((vader_struct_vader_midir_InstrCall_t*) l3)->f_args);
                        if (_a5_slotarr->buf != NULL && _a5_slotarr->buf->header.forward != NULL) { _a5_slotarr->buf = vader_array_buf_forward(_a5_slotarr->buf); }
                        if ((size_t) l11 >= _a5_slotarr->length) { vader_trap("array index out of bounds"); }
                        l15 = ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l11];
                        l10 = ((vader_struct_vader_midir_InstrCall_t*) l3)->f_span;
                        vader_midir_emit_get(l0, l15, l10);
                    }
                    t0 = (l11 + INT64_C(1));
                    l11 = (size_t) (int64_t) t0;
                    goto loop_185;
                } else {
                }
            }
        }
        l5 = ((vader_struct_vader_bytecode_EmitterCtx_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project)->f_function_index_by_mangle;
        l16 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_midir_InstrCall_t*) l3)->f_callee)->f_name;
        l7 = std_collections_get__string__i32(l5, l16);
        if (l7.tag == 163u) {
            t2 = ((int32_t) l7.payload.i);
            vader_struct_vader_bytecode_Call_t* _a6_obj = (vader_struct_vader_bytecode_Call_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_Call_t));
            vader_obj_header_init(_a6_obj, 540u);
            _a6_obj->f_function_index = t2;
            l5 = (void*) _a6_obj;
            l10 = ((vader_struct_vader_midir_InstrCall_t*) l3)->f_span;
            vader_midir_push_emit(l0, vader_ref_box(l5), l10);
        } else {
            l5 = ((vader_struct_vader_bytecode_EmitterCtx_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project)->f_function_index_by_symbol_id;
            l4 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_midir_InstrCall_t*) l3)->f_callee)->f_id;
            l7 = std_collections_get__i32__i32(l5, l4);
            if (l7.tag == 163u) {
                t2 = ((int32_t) l7.payload.i);
                vader_struct_vader_bytecode_Call_t* _a7_obj = (vader_struct_vader_bytecode_Call_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_Call_t));
                vader_obj_header_init(_a7_obj, 540u);
                _a7_obj->f_function_index = t2;
                l5 = (void*) _a7_obj;
                l10 = ((vader_struct_vader_midir_InstrCall_t*) l3)->f_span;
                vader_midir_push_emit(l0, vader_ref_box(l5), l10);
            } else {
                l5 = ((vader_struct_vader_bytecode_EmitterCtx_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project)->f_import_index_by_symbol_id;
                l4 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_midir_InstrCall_t*) l3)->f_callee)->f_id;
                l7 = std_collections_get__i32__i32(l5, l4);
                if (l7.tag == 163u) {
                    t2 = ((int32_t) l7.payload.i);
                    vader_struct_vader_bytecode_CallImport_t* _a8_obj = (vader_struct_vader_bytecode_CallImport_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_CallImport_t));
                    vader_obj_header_init(_a8_obj, 541u);
                    _a8_obj->f_index = t2;
                    l5 = (void*) _a8_obj;
                    l10 = ((vader_struct_vader_midir_InstrCall_t*) l3)->f_span;
                    vader_midir_push_emit(l0, vader_ref_box(l5), l10);
                } else {
                    l5 = ((vader_struct_vader_bytecode_EmitterCtx_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project)->f_import_index_by_mangle;
                    l16 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_midir_InstrCall_t*) l3)->f_callee)->f_name;
                    l7 = std_collections_get__string__i32(l5, l16);
                    if (l7.tag == 163u) {
                        t2 = ((int32_t) l7.payload.i);
                        vader_struct_vader_bytecode_CallImport_t* _a9_obj = (vader_struct_vader_bytecode_CallImport_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_CallImport_t));
                        vader_obj_header_init(_a9_obj, 541u);
                        _a9_obj->f_index = t2;
                        l5 = (void*) _a9_obj;
                        l10 = ((vader_struct_vader_midir_InstrCall_t*) l3)->f_span;
                        vader_midir_push_emit(l0, vader_ref_box(l5), l10);
                    } else {
                        l16 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_midir_InstrCall_t*) l3)->f_callee)->f_name;
                        l17 = ((vader_struct_vader_midir_CFGFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_fn_)->f_mangled;
                        l6 = vader_import_0(l16);
                        l11 = vader_import_0(l17);
                        t0 = (l6 + l11);
                        l6 = (size_t) (int64_t) t0;
                        l5 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(117) + l6));
                        l6 = (size_t) (int64_t) INT64_C(0);
                        l6 = std_core_write_string_at(l5, l6, 1745u);
                        l6 = std_core_write_string_at(l5, l6, l16);
                        l6 = std_core_write_string_at(l5, l6, 269u);
                        t2 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_midir_InstrCall_t*) l3)->f_callee)->f_id;
                        l18 = ((int64_t) (int32_t) t2);
                        l6 = std_core_write_int(l5, l6, l18);
                        l6 = std_core_write_string_at(l5, l6, 331u);
                        l6 = std_core_write_string_at(l5, l6, l17);
                        l6 = std_core_write_string_at(l5, l6, 281u);
                        t3 = std_core_finish_buffer(l5, l6);
                        vader_import_32(t3);
                    }
                }
            }
        }
        l7 = ((vader_struct_vader_midir_InstrCall_t*) l3)->f_dst;
        l3 = ((vader_struct_vader_midir_InstrCall_t*) l3)->f_span;
        vader_midir_emit_result_if_any(l0, l2, l7, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 845u) {
        l3 = l1.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrUnOp_t*) l3)->f_operand;
        l5 = ((vader_struct_vader_midir_InstrUnOp_t*) l3)->f_span;
        vader_midir_emit_first_get(l0, l2, l4, l5);
        l5 = ((vader_struct_vader_midir_CFGFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_fn_)->f_locals;
        t0 = ((int64_t) (int32_t) ((vader_struct_vader_midir_InstrUnOp_t*) l3)->f_operand);
        l6 = (size_t) (int64_t) t0;
        vader_array_t* _a10_slotarr = ((vader_array_t*) l5);
        if (_a10_slotarr->buf != NULL && _a10_slotarr->buf->header.forward != NULL) { _a10_slotarr->buf = vader_array_buf_forward(_a10_slotarr->buf); }
        if ((size_t) l6 >= _a10_slotarr->length) { vader_trap("array index out of bounds"); }
        t1 = vader_array_ref_load_obj(_a10_slotarr->buf, _a10_slotarr->offset + (size_t) l6);
        l8 = vader_bytecode_val_type_of_type(((vader_struct_vader_midir_CFGLocal_t*) t1)->f_type);
        l7 = vader_bytecode_unary_op_for(((vader_struct_vader_midir_InstrUnOp_t*) l3)->f_op, l8);
        l5 = ((vader_struct_vader_midir_InstrUnOp_t*) l3)->f_span;
        vader_midir_push_emit(l0, l7, l5);
        l4 = ((vader_struct_vader_midir_InstrUnOp_t*) l3)->f_dst;
        l3 = ((vader_struct_vader_midir_InstrUnOp_t*) l3)->f_span;
        vader_midir_emit_result(l0, l2, l4, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 826u) {
        l3 = l1.payload.obj;
        l6 = ((vader_array_t*) ((vader_struct_vader_midir_InstrCallIndirect_t*) l3)->f_args)->length;
        l11 = (size_t) (int64_t) INT64_C(0);
        {
            loop_467: {
                if ((l11 < l6)) {
                    if (l11 == INT64_C(0)) {
                        vader_array_t* _a11_slotarr = ((vader_array_t*) ((vader_struct_vader_midir_InstrCallIndirect_t*) l3)->f_args);
                        if (_a11_slotarr->buf != NULL && _a11_slotarr->buf->header.forward != NULL) { _a11_slotarr->buf = vader_array_buf_forward(_a11_slotarr->buf); }
                        if ((size_t) l11 >= _a11_slotarr->length) { vader_trap("array index out of bounds"); }
                        l4 = ((int32_t*) _a11_slotarr->buf->slots)[_a11_slotarr->offset + (size_t) l11];
                        l5 = ((vader_struct_vader_midir_InstrCallIndirect_t*) l3)->f_span;
                        vader_midir_emit_first_get(l0, l2, l4, l5);
                    } else {
                        vader_array_t* _a12_slotarr = ((vader_array_t*) ((vader_struct_vader_midir_InstrCallIndirect_t*) l3)->f_args);
                        if (_a12_slotarr->buf != NULL && _a12_slotarr->buf->header.forward != NULL) { _a12_slotarr->buf = vader_array_buf_forward(_a12_slotarr->buf); }
                        if ((size_t) l11 >= _a12_slotarr->length) { vader_trap("array index out of bounds"); }
                        l15 = ((int32_t*) _a12_slotarr->buf->slots)[_a12_slotarr->offset + (size_t) l11];
                        l10 = ((vader_struct_vader_midir_InstrCallIndirect_t*) l3)->f_span;
                        vader_midir_emit_get(l0, l15, l10);
                    }
                    t0 = (l11 + INT64_C(1));
                    l11 = (size_t) (int64_t) t0;
                    goto loop_467;
                } else {
                }
            }
        }
        t4 = ((vader_array_t*) ((vader_struct_vader_midir_InstrCallIndirect_t*) l3)->f_args)->length;
        if (t4 == INT64_C(0)) {
            l4 = ((vader_struct_vader_midir_InstrCallIndirect_t*) l3)->f_callee;
            l5 = ((vader_struct_vader_midir_InstrCallIndirect_t*) l3)->f_span;
            vader_midir_emit_first_get(l0, l2, l4, l5);
        } else {
            l4 = ((vader_struct_vader_midir_InstrCallIndirect_t*) l3)->f_callee;
            l5 = ((vader_struct_vader_midir_InstrCallIndirect_t*) l3)->f_span;
            vader_midir_emit_get(l0, l4, l5);
        }
        l7 = ((vader_struct_vader_midir_InstrCallIndirect_t*) l3)->f_fn_type;
        l5 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project;
        t2 = vader_bytecode_intern_type(l7, l5);
        vader_struct_vader_bytecode_CallIndirect_t* _a13_obj = (vader_struct_vader_bytecode_CallIndirect_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_CallIndirect_t));
        vader_obj_header_init(_a13_obj, 542u);
        _a13_obj->f_type_id = t2;
        l5 = (void*) _a13_obj;
        l10 = ((vader_struct_vader_midir_InstrCallIndirect_t*) l3)->f_span;
        vader_midir_push_emit(l0, vader_ref_box(l5), l10);
        l7 = ((vader_struct_vader_midir_InstrCallIndirect_t*) l3)->f_dst;
        l3 = ((vader_struct_vader_midir_InstrCallIndirect_t*) l3)->f_span;
        vader_midir_emit_result_if_any(l0, l2, l7, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 837u) {
        l3 = l1.payload.obj;
        l5 = ((vader_struct_vader_bytecode_EmitterCtx_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project)->f_function_index_by_symbol_id;
        l4 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_midir_InstrFnRef_t*) l3)->f_fn_symbol)->f_id;
        l7 = std_collections_get__i32__i32(l5, l4);
        if (l7.tag == 163u) {
            l4 = ((int32_t) l7.payload.i);
            l7 = ((vader_struct_vader_midir_InstrFnRef_t*) l3)->f_type;
            l5 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project;
            l15 = vader_bytecode_intern_type(l7, l5);
            vader_struct_vader_bytecode_FnRef_t* _a14_obj = (vader_struct_vader_bytecode_FnRef_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_FnRef_t));
            vader_obj_header_init(_a14_obj, 568u);
            _a14_obj->f_function_index = l4;
            _a14_obj->f_type_id = l15;
            l5 = (void*) _a14_obj;
            l10 = ((vader_struct_vader_midir_InstrFnRef_t*) l3)->f_span;
            vader_midir_push_emit(l0, vader_ref_box(l5), l10);
        } else {
            l16 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_midir_InstrFnRef_t*) l3)->f_fn_symbol)->f_name;
            l6 = vader_import_0(l16);
            l5 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(104) + l6));
            l6 = (size_t) (int64_t) INT64_C(0);
            l6 = std_core_write_string_at(l5, l6, 1747u);
            l6 = std_core_write_string_at(l5, l6, l16);
            l6 = std_core_write_string_at(l5, l6, 269u);
            t2 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_midir_InstrFnRef_t*) l3)->f_fn_symbol)->f_id;
            l18 = ((int64_t) (int32_t) t2);
            l6 = std_core_write_int(l5, l6, l18);
            l6 = std_core_write_string_at(l5, l6, 337u);
            t3 = std_core_finish_buffer(l5, l6);
            vader_import_32(t3);
        }
        l4 = ((vader_struct_vader_midir_InstrFnRef_t*) l3)->f_dst;
        l3 = ((vader_struct_vader_midir_InstrFnRef_t*) l3)->f_span;
        vader_midir_emit_result(l0, l2, l4, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 846u) {
        l3 = l1.payload.obj;
        l6 = ((vader_array_t*) ((vader_struct_vader_midir_InstrVirtualCall_t*) l3)->f_args)->length;
        l11 = (size_t) (int64_t) INT64_C(0);
        {
            loop_671: {
                if ((l11 < l6)) {
                    if (l11 == INT64_C(0)) {
                        vader_array_t* _a15_slotarr = ((vader_array_t*) ((vader_struct_vader_midir_InstrVirtualCall_t*) l3)->f_args);
                        if (_a15_slotarr->buf != NULL && _a15_slotarr->buf->header.forward != NULL) { _a15_slotarr->buf = vader_array_buf_forward(_a15_slotarr->buf); }
                        if ((size_t) l11 >= _a15_slotarr->length) { vader_trap("array index out of bounds"); }
                        l4 = ((int32_t*) _a15_slotarr->buf->slots)[_a15_slotarr->offset + (size_t) l11];
                        l5 = ((vader_struct_vader_midir_InstrVirtualCall_t*) l3)->f_span;
                        vader_midir_emit_first_get(l0, l2, l4, l5);
                    } else {
                        vader_array_t* _a16_slotarr = ((vader_array_t*) ((vader_struct_vader_midir_InstrVirtualCall_t*) l3)->f_args);
                        if (_a16_slotarr->buf != NULL && _a16_slotarr->buf->header.forward != NULL) { _a16_slotarr->buf = vader_array_buf_forward(_a16_slotarr->buf); }
                        if ((size_t) l11 >= _a16_slotarr->length) { vader_trap("array index out of bounds"); }
                        l15 = ((int32_t*) _a16_slotarr->buf->slots)[_a16_slotarr->offset + (size_t) l11];
                        l10 = ((vader_struct_vader_midir_InstrVirtualCall_t*) l3)->f_span;
                        vader_midir_emit_get(l0, l15, l10);
                    }
                    t0 = (l11 + INT64_C(1));
                    l11 = (size_t) (int64_t) t0;
                    goto loop_671;
                } else {
                }
            }
        }
        t4 = ((vader_array_t*) ((vader_struct_vader_midir_InstrVirtualCall_t*) l3)->f_args)->length;
        if (t4 == INT64_C(0)) {
            l4 = ((vader_struct_vader_midir_InstrVirtualCall_t*) l3)->f_receiver;
            l5 = ((vader_struct_vader_midir_InstrVirtualCall_t*) l3)->f_span;
            vader_midir_emit_first_get(l0, l2, l4, l5);
        } else {
            l4 = ((vader_struct_vader_midir_InstrVirtualCall_t*) l3)->f_receiver;
            l5 = ((vader_struct_vader_midir_InstrVirtualCall_t*) l3)->f_span;
            vader_midir_emit_get(l0, l4, l5);
        }
        t4 = ((vader_array_t*) ((vader_struct_vader_midir_InstrVirtualCall_t*) l3)->f_args)->length;
        l4 = ((int32_t) (int64_t) (t4 + INT64_C(1)));
        l16 = ((vader_struct_vader_midir_InstrVirtualCall_t*) l3)->f_trait_name;
        l17 = ((vader_struct_vader_midir_InstrVirtualCall_t*) l3)->f_method;
        l16 = concat_3(l16, 397u, l17);
        vader_struct_vader_bytecode_VirtualCall_t* _a17_obj = (vader_struct_vader_bytecode_VirtualCall_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_VirtualCall_t));
        vader_obj_header_init(_a17_obj, 662u);
        _a17_obj->f_parameter_count = l4;
        _a17_obj->f_vtable_key = l16;
        l5 = (void*) _a17_obj;
        l10 = ((vader_struct_vader_midir_InstrVirtualCall_t*) l3)->f_span;
        vader_midir_push_emit(l0, vader_ref_box(l5), l10);
        l7 = ((vader_struct_vader_midir_InstrVirtualCall_t*) l3)->f_dst;
        l3 = ((vader_struct_vader_midir_InstrVirtualCall_t*) l3)->f_span;
        vader_midir_emit_result_if_any(l0, l2, l7, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 835u) {
        l3 = l1.payload.obj;
        l5 = ((vader_struct_vader_midir_CFGFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_fn_)->f_locals;
        t0 = ((int64_t) (int32_t) ((vader_struct_vader_midir_InstrFieldGet_t*) l3)->f_target);
        l6 = (size_t) (int64_t) t0;
        vader_array_t* _a18_slotarr = ((vader_array_t*) l5);
        if (_a18_slotarr->buf != NULL && _a18_slotarr->buf->header.forward != NULL) { _a18_slotarr->buf = vader_array_buf_forward(_a18_slotarr->buf); }
        if ((size_t) l6 >= _a18_slotarr->length) { vader_trap("array index out of bounds"); }
        t1 = vader_array_ref_load_obj(_a18_slotarr->buf, _a18_slotarr->offset + (size_t) l6);
        l7 = ((vader_struct_vader_midir_CFGLocal_t*) t1)->f_type;
        l5 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project;
        l4 = vader_bytecode_intern_type(l7, l5);
        l19 = std_collections_contains_key__i64__bool(((vader_struct_std_collections_MutableSet__i64_t*) ((vader_struct_vader_midir_ScheduleHints_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_hints)->f_skip_first_get)->f_inner, l2);
        l15 = ((vader_struct_vader_midir_InstrFieldGet_t*) l3)->f_target;
        l5 = ((vader_struct_vader_midir_InstrFieldGet_t*) l3)->f_span;
        vader_midir_emit_first_get(l0, l2, l15, l5);
        l5 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project;
        l16 = ((vader_struct_vader_midir_InstrFieldGet_t*) l3)->f_field;
        l20 = vader_midir_find_struct_field_index(l5, l4, l16);
        if (l20.tag == 0u) {
            l16 = ((vader_struct_vader_midir_InstrFieldGet_t*) l3)->f_field;
            l17 = vader_types_display_type(l7);
            l21 = ((vader_struct_vader_midir_CFGFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_fn_)->f_mangled;
            t3 = concat_7(1742u, l16, 943u, l17, 903u, l21, 279u);
            vader_import_32(t3);
        } else {
        }
        t4 = ((size_t) l20.payload.i);
        l15 = ((int32_t) (size_t) t4);
        l22 = false;
        if (!(l19)) {
            l22 = vader_midir_try_fuse_local_field(l0, l4, l15);
        } else {
        }
        if (!(l22)) {
            vader_struct_vader_bytecode_StructGet_t* _a19_obj = (vader_struct_vader_bytecode_StructGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_StructGet_t));
            vader_obj_header_init(_a19_obj, 644u);
            _a19_obj->f_type_id = l4;
            _a19_obj->f_field_index = l15;
            l5 = (void*) _a19_obj;
            l10 = ((vader_struct_vader_midir_InstrFieldGet_t*) l3)->f_span;
            vader_midir_push_emit(l0, vader_ref_box(l5), l10);
        } else {
        }
        t5 = vader_midir_needs_ref_cast(((vader_struct_vader_midir_InstrFieldGet_t*) l3)->f_type);
        if (t5) {
            l7 = ((vader_struct_vader_midir_InstrFieldGet_t*) l3)->f_type;
            l5 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project;
            t2 = vader_bytecode_intern_type(l7, l5);
            vader_struct_vader_bytecode_RefCast_t* _a20_obj = (vader_struct_vader_bytecode_RefCast_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_RefCast_t));
            vader_obj_header_init(_a20_obj, 626u);
            _a20_obj->f_type_id = t2;
            l5 = (void*) _a20_obj;
            l10 = ((vader_struct_vader_midir_InstrFieldGet_t*) l3)->f_span;
            vader_midir_push_emit(l0, vader_ref_box(l5), l10);
        } else {
        }
        l4 = ((vader_struct_vader_midir_InstrFieldGet_t*) l3)->f_dst;
        l3 = ((vader_struct_vader_midir_InstrFieldGet_t*) l3)->f_span;
        vader_midir_emit_result(l0, l2, l4, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 836u) {
        l3 = l1.payload.obj;
        l5 = ((vader_struct_vader_midir_CFGFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_fn_)->f_locals;
        t0 = ((int64_t) (int32_t) ((vader_struct_vader_midir_InstrFieldSet_t*) l3)->f_target);
        l6 = (size_t) (int64_t) t0;
        vader_array_t* _a21_slotarr = ((vader_array_t*) l5);
        if (_a21_slotarr->buf != NULL && _a21_slotarr->buf->header.forward != NULL) { _a21_slotarr->buf = vader_array_buf_forward(_a21_slotarr->buf); }
        if ((size_t) l6 >= _a21_slotarr->length) { vader_trap("array index out of bounds"); }
        t1 = vader_array_ref_load_obj(_a21_slotarr->buf, _a21_slotarr->offset + (size_t) l6);
        l7 = ((vader_struct_vader_midir_CFGLocal_t*) t1)->f_type;
        l5 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project;
        l4 = vader_bytecode_intern_type(l7, l5);
        l15 = ((vader_struct_vader_midir_InstrFieldSet_t*) l3)->f_target;
        l5 = ((vader_struct_vader_midir_InstrFieldSet_t*) l3)->f_span;
        vader_midir_emit_first_get(l0, l2, l15, l5);
        l15 = ((vader_struct_vader_midir_InstrFieldSet_t*) l3)->f_value;
        l5 = ((vader_struct_vader_midir_InstrFieldSet_t*) l3)->f_span;
        vader_midir_emit_get(l0, l15, l5);
        l5 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project;
        l16 = ((vader_struct_vader_midir_InstrFieldSet_t*) l3)->f_field;
        l20 = vader_midir_find_struct_field_index(l5, l4, l16);
        if (l20.tag == 0u) {
            l16 = ((vader_struct_vader_midir_InstrFieldSet_t*) l3)->f_field;
            l17 = vader_types_display_type(l7);
            l21 = ((vader_struct_vader_midir_CFGFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_fn_)->f_mangled;
            t3 = concat_7(1742u, l16, 943u, l17, 903u, l21, 280u);
            vader_import_32(t3);
        } else {
        }
        t4 = ((size_t) l20.payload.i);
        l15 = ((int32_t) (size_t) t4);
        l19 = ((vader_struct_vader_midir_InstrFieldSet_t*) l3)->f_barrierless;
        vader_struct_vader_bytecode_StructSet_t* _a22_obj = (vader_struct_vader_bytecode_StructSet_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_StructSet_t));
        vader_obj_header_init(_a22_obj, 646u);
        _a22_obj->f_type_id = l4;
        _a22_obj->f_field_index = l15;
        _a22_obj->f_stack = l19;
        l5 = (void*) _a22_obj;
        l3 = ((vader_struct_vader_midir_InstrFieldSet_t*) l3)->f_span;
        vader_midir_push_emit(l0, vader_ref_box(l5), l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 818u) {
        l3 = l1.payload.obj;
        l5 = ((vader_struct_vader_midir_CFGFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_fn_)->f_locals;
        t0 = ((int64_t) (int32_t) ((vader_struct_vader_midir_InstrArrayGet_t*) l3)->f_target);
        l6 = (size_t) (int64_t) t0;
        vader_array_t* _a23_slotarr = ((vader_array_t*) l5);
        if (_a23_slotarr->buf != NULL && _a23_slotarr->buf->header.forward != NULL) { _a23_slotarr->buf = vader_array_buf_forward(_a23_slotarr->buf); }
        if ((size_t) l6 >= _a23_slotarr->length) { vader_trap("array index out of bounds"); }
        t1 = vader_array_ref_load_obj(_a23_slotarr->buf, _a23_slotarr->offset + (size_t) l6);
        l7 = ((vader_struct_vader_midir_CFGLocal_t*) t1)->f_type;
        l5 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project;
        l4 = vader_bytecode_intern_type(l7, l5);
        l15 = ((vader_struct_vader_midir_InstrArrayGet_t*) l3)->f_target;
        l5 = ((vader_struct_vader_midir_InstrArrayGet_t*) l3)->f_span;
        vader_midir_emit_first_get(l0, l2, l15, l5);
        l15 = ((vader_struct_vader_midir_InstrArrayGet_t*) l3)->f_index;
        l5 = ((vader_struct_vader_midir_InstrArrayGet_t*) l3)->f_span;
        vader_midir_emit_get(l0, l15, l5);
        l8 = vader_midir_array_element_val_type(l7);
        l19 = ((vader_struct_vader_midir_InstrArrayGet_t*) l3)->f_bounds_safe;
        l7 = vader_bytecode_slot_load_op_for(l8, l19);
        if (l7.tag == 0u) {
            l19 = ((vader_struct_vader_midir_InstrArrayGet_t*) l3)->f_bounds_safe;
            vader_struct_vader_bytecode_ArrayGet_t* _a24_obj = (vader_struct_vader_bytecode_ArrayGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_ArrayGet_t));
            vader_obj_header_init(_a24_obj, 495u);
            _a24_obj->f_type_id = l4;
            _a24_obj->f_bounds_safe = l19;
            l5 = (void*) _a24_obj;
            l10 = ((vader_struct_vader_midir_InstrArrayGet_t*) l3)->f_span;
            vader_midir_push_emit(l0, vader_ref_box(l5), l10);
            t5 = vader_midir_needs_ref_cast(((vader_struct_vader_midir_InstrArrayGet_t*) l3)->f_type);
            if (t5) {
                l20 = ((vader_struct_vader_midir_InstrArrayGet_t*) l3)->f_type;
                l5 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project;
                t2 = vader_bytecode_intern_type(l20, l5);
                vader_struct_vader_bytecode_RefCast_t* _a25_obj = (vader_struct_vader_bytecode_RefCast_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_RefCast_t));
                vader_obj_header_init(_a25_obj, 626u);
                _a25_obj->f_type_id = t2;
                l5 = (void*) _a25_obj;
                l10 = ((vader_struct_vader_midir_InstrArrayGet_t*) l3)->f_span;
                vader_midir_push_emit(l0, vader_ref_box(l5), l10);
            } else {
            }
        } else {
            l5 = ((vader_struct_vader_midir_InstrArrayGet_t*) l3)->f_span;
            vader_midir_push_emit(l0, l7, l5);
        }
        l4 = ((vader_struct_vader_midir_InstrArrayGet_t*) l3)->f_dst;
        l3 = ((vader_struct_vader_midir_InstrArrayGet_t*) l3)->f_span;
        vader_midir_emit_result(l0, l2, l4, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 822u) {
        l3 = l1.payload.obj;
        l5 = ((vader_struct_vader_midir_CFGFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_fn_)->f_locals;
        t0 = ((int64_t) (int32_t) ((vader_struct_vader_midir_InstrArraySet_t*) l3)->f_target);
        l6 = (size_t) (int64_t) t0;
        vader_array_t* _a26_slotarr = ((vader_array_t*) l5);
        if (_a26_slotarr->buf != NULL && _a26_slotarr->buf->header.forward != NULL) { _a26_slotarr->buf = vader_array_buf_forward(_a26_slotarr->buf); }
        if ((size_t) l6 >= _a26_slotarr->length) { vader_trap("array index out of bounds"); }
        t1 = vader_array_ref_load_obj(_a26_slotarr->buf, _a26_slotarr->offset + (size_t) l6);
        l7 = ((vader_struct_vader_midir_CFGLocal_t*) t1)->f_type;
        l5 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project;
        l4 = vader_bytecode_intern_type(l7, l5);
        l15 = ((vader_struct_vader_midir_InstrArraySet_t*) l3)->f_target;
        l5 = ((vader_struct_vader_midir_InstrArraySet_t*) l3)->f_span;
        vader_midir_emit_first_get(l0, l2, l15, l5);
        l15 = ((vader_struct_vader_midir_InstrArraySet_t*) l3)->f_index;
        l5 = ((vader_struct_vader_midir_InstrArraySet_t*) l3)->f_span;
        vader_midir_emit_get(l0, l15, l5);
        l15 = ((vader_struct_vader_midir_InstrArraySet_t*) l3)->f_value;
        l5 = ((vader_struct_vader_midir_InstrArraySet_t*) l3)->f_span;
        vader_midir_emit_get(l0, l15, l5);
        l8 = vader_midir_array_element_val_type(l7);
        l19 = ((vader_struct_vader_midir_InstrArraySet_t*) l3)->f_bounds_safe;
        l7 = vader_bytecode_slot_store_op_for(l8, l19);
        if (l7.tag == 0u) {
            l19 = ((vader_struct_vader_midir_InstrArraySet_t*) l3)->f_bounds_safe;
            vader_struct_vader_bytecode_ArraySet_t* _a27_obj = (vader_struct_vader_bytecode_ArraySet_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_ArraySet_t));
            vader_obj_header_init(_a27_obj, 502u);
            _a27_obj->f_type_id = l4;
            _a27_obj->f_bounds_safe = l19;
            l5 = (void*) _a27_obj;
            l10 = ((vader_struct_vader_midir_InstrArraySet_t*) l3)->f_span;
            vader_midir_push_emit(l0, vader_ref_box(l5), l10);
        } else {
            l3 = ((vader_struct_vader_midir_InstrArraySet_t*) l3)->f_span;
            vader_midir_push_emit(l0, l7, l3);
        }
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 819u) {
        l3 = l1.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrArrayLen_t*) l3)->f_target;
        l5 = ((vader_struct_vader_midir_InstrArrayLen_t*) l3)->f_span;
        vader_midir_emit_first_get(l0, l2, l4, l5);
        t5 = ((vader_struct_vader_midir_InstrArrayLen_t*) l3)->f_resolve_buf;
        vader_struct_vader_bytecode_ArrayLen_t* _a28_obj = (vader_struct_vader_bytecode_ArrayLen_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_ArrayLen_t));
        vader_obj_header_init(_a28_obj, 496u);
        _a28_obj->f_resolve_buf = t5;
        l5 = (void*) _a28_obj;
        l10 = ((vader_struct_vader_midir_InstrArrayLen_t*) l3)->f_span;
        vader_midir_push_emit(l0, vader_ref_box(l5), l10);
        l4 = ((vader_struct_vader_midir_InstrArrayLen_t*) l3)->f_dst;
        l3 = ((vader_struct_vader_midir_InstrArrayLen_t*) l3)->f_span;
        vader_midir_emit_result(l0, l2, l4, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 821u) {
        l3 = l1.payload.obj;
        l5 = ((vader_struct_vader_midir_CFGFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_fn_)->f_locals;
        t0 = ((int64_t) (int32_t) ((vader_struct_vader_midir_InstrArrayPush_t*) l3)->f_value);
        l6 = (size_t) (int64_t) t0;
        vader_array_t* _a29_slotarr = ((vader_array_t*) l5);
        if (_a29_slotarr->buf != NULL && _a29_slotarr->buf->header.forward != NULL) { _a29_slotarr->buf = vader_array_buf_forward(_a29_slotarr->buf); }
        if ((size_t) l6 >= _a29_slotarr->length) { vader_trap("array index out of bounds"); }
        t1 = vader_array_ref_load_obj(_a29_slotarr->buf, _a29_slotarr->offset + (size_t) l6);
        l7 = ((vader_struct_vader_midir_CFGLocal_t*) t1)->f_type;
        l4 = ((vader_struct_vader_midir_InstrArrayPush_t*) l3)->f_target;
        l5 = ((vader_struct_vader_midir_InstrArrayPush_t*) l3)->f_span;
        vader_midir_emit_first_get(l0, l2, l4, l5);
        l4 = ((vader_struct_vader_midir_InstrArrayPush_t*) l3)->f_value;
        l5 = ((vader_struct_vader_midir_InstrArrayPush_t*) l3)->f_span;
        vader_midir_emit_get(l0, l4, l5);
        l5 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project;
        t2 = vader_bytecode_intern_type(l7, l5);
        vader_struct_vader_bytecode_ArrayPush_t* _a30_obj = (vader_struct_vader_bytecode_ArrayPush_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_ArrayPush_t));
        vader_obj_header_init(_a30_obj, 498u);
        _a30_obj->f_type_id = t2;
        l5 = (void*) _a30_obj;
        l3 = ((vader_struct_vader_midir_InstrArrayPush_t*) l3)->f_span;
        vader_midir_push_emit(l0, vader_ref_box(l5), l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 823u) {
        l3 = l1.payload.obj;
        l7 = ((vader_struct_vader_midir_InstrArraySlice_t*) l3)->f_type;
        l5 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project;
        l4 = vader_bytecode_intern_type(l7, l5);
        l15 = ((vader_struct_vader_midir_InstrArraySlice_t*) l3)->f_target;
        l5 = ((vader_struct_vader_midir_InstrArraySlice_t*) l3)->f_span;
        vader_midir_emit_first_get(l0, l2, l15, l5);
        l15 = ((vader_struct_vader_midir_InstrArraySlice_t*) l3)->f_lo;
        l5 = ((vader_struct_vader_midir_InstrArraySlice_t*) l3)->f_span;
        vader_midir_emit_get(l0, l15, l5);
        l15 = ((vader_struct_vader_midir_InstrArraySlice_t*) l3)->f_hi;
        l5 = ((vader_struct_vader_midir_InstrArraySlice_t*) l3)->f_span;
        vader_midir_emit_get(l0, l15, l5);
        vader_struct_vader_bytecode_ArraySlice_t* _a31_obj = (vader_struct_vader_bytecode_ArraySlice_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_ArraySlice_t));
        vader_obj_header_init(_a31_obj, 503u);
        _a31_obj->f_type_id = l4;
        l5 = (void*) _a31_obj;
        l10 = ((vader_struct_vader_midir_InstrArraySlice_t*) l3)->f_span;
        vader_midir_push_emit(l0, vader_ref_box(l5), l10);
        l4 = ((vader_struct_vader_midir_InstrArraySlice_t*) l3)->f_dst;
        l3 = ((vader_struct_vader_midir_InstrArraySlice_t*) l3)->f_span;
        vader_midir_emit_result(l0, l2, l4, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 841u) {
        l3 = l1.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrStringSlice_t*) l3)->f_target;
        l5 = ((vader_struct_vader_midir_InstrStringSlice_t*) l3)->f_span;
        vader_midir_emit_first_get(l0, l2, l4, l5);
        l4 = ((vader_struct_vader_midir_InstrStringSlice_t*) l3)->f_lo;
        l5 = ((vader_struct_vader_midir_InstrStringSlice_t*) l3)->f_span;
        vader_midir_emit_get(l0, l4, l5);
        l4 = ((vader_struct_vader_midir_InstrStringSlice_t*) l3)->f_hi;
        l5 = ((vader_struct_vader_midir_InstrStringSlice_t*) l3)->f_span;
        vader_midir_emit_get(l0, l4, l5);
        vader_struct_vader_bytecode_StringSliceCodepoints_t* _a32_obj = (vader_struct_vader_bytecode_StringSliceCodepoints_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_StringSliceCodepoints_t));
        vader_obj_header_init(_a32_obj, 643u);
        l5 = (void*) _a32_obj;
        l10 = ((vader_struct_vader_midir_InstrStringSlice_t*) l3)->f_span;
        vader_midir_push_emit(l0, vader_ref_box(l5), l10);
        l4 = ((vader_struct_vader_midir_InstrStringSlice_t*) l3)->f_dst;
        l3 = ((vader_struct_vader_midir_InstrStringSlice_t*) l3)->f_span;
        vader_midir_emit_result(l0, l2, l4, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 842u) {
        l3 = l1.payload.obj;
        l7 = ((vader_struct_vader_midir_InstrStructNew_t*) l3)->f_type;
        l5 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project;
        l4 = vader_bytecode_intern_type(l7, l5);
        l6 = ((vader_array_t*) ((vader_struct_vader_midir_InstrStructNew_t*) l3)->f_fields)->length;
        l11 = (size_t) (int64_t) INT64_C(0);
        {
            loop_1403: {
                if ((l11 < l6)) {
                    if (l11 == INT64_C(0)) {
                        vader_array_t* _a33_slotarr = ((vader_array_t*) ((vader_struct_vader_midir_InstrStructNew_t*) l3)->f_fields);
                        if (_a33_slotarr->buf != NULL && _a33_slotarr->buf->header.forward != NULL) { _a33_slotarr->buf = vader_array_buf_forward(_a33_slotarr->buf); }
                        if ((size_t) l11 >= _a33_slotarr->length) { vader_trap("array index out of bounds"); }
                        l15 = ((int32_t*) _a33_slotarr->buf->slots)[_a33_slotarr->offset + (size_t) l11];
                        l5 = ((vader_struct_vader_midir_InstrStructNew_t*) l3)->f_span;
                        vader_midir_emit_first_get(l0, l2, l15, l5);
                    } else {
                        vader_array_t* _a34_slotarr = ((vader_array_t*) ((vader_struct_vader_midir_InstrStructNew_t*) l3)->f_fields);
                        if (_a34_slotarr->buf != NULL && _a34_slotarr->buf->header.forward != NULL) { _a34_slotarr->buf = vader_array_buf_forward(_a34_slotarr->buf); }
                        if ((size_t) l11 >= _a34_slotarr->length) { vader_trap("array index out of bounds"); }
                        l23 = ((int32_t*) _a34_slotarr->buf->slots)[_a34_slotarr->offset + (size_t) l11];
                        l10 = ((vader_struct_vader_midir_InstrStructNew_t*) l3)->f_span;
                        vader_midir_emit_get(l0, l23, l10);
                    }
                    t0 = (l11 + INT64_C(1));
                    l11 = (size_t) (int64_t) t0;
                    goto loop_1403;
                } else {
                }
            }
        }
        l19 = ((vader_struct_vader_midir_InstrStructNew_t*) l3)->f_stack;
        vader_struct_vader_bytecode_StructNew_t* _a35_obj = (vader_struct_vader_bytecode_StructNew_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_StructNew_t));
        vader_obj_header_init(_a35_obj, 645u);
        _a35_obj->f_type_id = l4;
        _a35_obj->f_stack = l19;
        l5 = (void*) _a35_obj;
        l10 = ((vader_struct_vader_midir_InstrStructNew_t*) l3)->f_span;
        vader_midir_push_emit(l0, vader_ref_box(l5), l10);
        l4 = ((vader_struct_vader_midir_InstrStructNew_t*) l3)->f_dst;
        l3 = ((vader_struct_vader_midir_InstrStructNew_t*) l3)->f_span;
        vader_midir_emit_result(l0, l2, l4, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 820u) {
        l3 = l1.payload.obj;
        l7 = ((vader_struct_vader_midir_InstrArrayNew_t*) l3)->f_type;
        l5 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project;
        l4 = vader_bytecode_intern_type(l7, l5);
        l6 = ((vader_array_t*) ((vader_struct_vader_midir_InstrArrayNew_t*) l3)->f_elements)->length;
        l11 = (size_t) (int64_t) INT64_C(0);
        {
            loop_1488: {
                if ((l11 < l6)) {
                    if (l11 == INT64_C(0)) {
                        vader_array_t* _a36_slotarr = ((vader_array_t*) ((vader_struct_vader_midir_InstrArrayNew_t*) l3)->f_elements);
                        if (_a36_slotarr->buf != NULL && _a36_slotarr->buf->header.forward != NULL) { _a36_slotarr->buf = vader_array_buf_forward(_a36_slotarr->buf); }
                        if ((size_t) l11 >= _a36_slotarr->length) { vader_trap("array index out of bounds"); }
                        l15 = ((int32_t*) _a36_slotarr->buf->slots)[_a36_slotarr->offset + (size_t) l11];
                        l5 = ((vader_struct_vader_midir_InstrArrayNew_t*) l3)->f_span;
                        vader_midir_emit_first_get(l0, l2, l15, l5);
                    } else {
                        vader_array_t* _a37_slotarr = ((vader_array_t*) ((vader_struct_vader_midir_InstrArrayNew_t*) l3)->f_elements);
                        if (_a37_slotarr->buf != NULL && _a37_slotarr->buf->header.forward != NULL) { _a37_slotarr->buf = vader_array_buf_forward(_a37_slotarr->buf); }
                        if ((size_t) l11 >= _a37_slotarr->length) { vader_trap("array index out of bounds"); }
                        l23 = ((int32_t*) _a37_slotarr->buf->slots)[_a37_slotarr->offset + (size_t) l11];
                        l10 = ((vader_struct_vader_midir_InstrArrayNew_t*) l3)->f_span;
                        vader_midir_emit_get(l0, l23, l10);
                    }
                    t0 = (l11 + INT64_C(1));
                    l11 = (size_t) (int64_t) t0;
                    goto loop_1488;
                } else {
                }
            }
        }
        l15 = ((vader_struct_vader_midir_InstrArrayNew_t*) l3)->f_length;
        vader_struct_vader_bytecode_ArrayNew_t* _a38_obj = (vader_struct_vader_bytecode_ArrayNew_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_ArrayNew_t));
        vader_obj_header_init(_a38_obj, 497u);
        _a38_obj->f_type_id = l4;
        _a38_obj->f_length = l15;
        l5 = (void*) _a38_obj;
        l10 = ((vader_struct_vader_midir_InstrArrayNew_t*) l3)->f_span;
        vader_midir_push_emit(l0, vader_ref_box(l5), l10);
        l4 = ((vader_struct_vader_midir_InstrArrayNew_t*) l3)->f_dst;
        l3 = ((vader_struct_vader_midir_InstrArrayNew_t*) l3)->f_span;
        vader_midir_emit_result(l0, l2, l4, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 832u) {
        l3 = l1.payload.obj;
        l7 = ((vader_struct_vader_midir_InstrDataConst_t*) l3)->f_type;
        l5 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project;
        l4 = vader_bytecode_intern_type(l7, l5);
        t2 = ((vader_struct_vader_midir_InstrDataConst_t*) l3)->f_pool_index;
        vader_struct_vader_bytecode_DataConst_t* _a39_obj = (vader_struct_vader_bytecode_DataConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_DataConst_t));
        vader_obj_header_init(_a39_obj, 545u);
        _a39_obj->f_pool_index = t2;
        _a39_obj->f_type_id = l4;
        l5 = (void*) _a39_obj;
        l10 = ((vader_struct_vader_midir_InstrDataConst_t*) l3)->f_span;
        vader_midir_push_emit(l0, vader_ref_box(l5), l10);
        l4 = ((vader_struct_vader_midir_InstrDataConst_t*) l3)->f_dst;
        l3 = ((vader_struct_vader_midir_InstrDataConst_t*) l3)->f_span;
        vader_midir_emit_result(l0, l2, l4, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 843u) {
        l3 = l1.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrTypeCheck_t*) l3)->f_value;
        l5 = ((vader_struct_vader_midir_InstrTypeCheck_t*) l3)->f_span;
        vader_midir_emit_first_get(l0, l2, l4, l5);
        l7 = ((vader_struct_vader_midir_InstrTypeCheck_t*) l3)->f_check_type;
        l5 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project;
        t2 = vader_bytecode_intern_type(l7, l5);
        vader_struct_vader_bytecode_TypeCheck_t* _a40_obj = (vader_struct_vader_bytecode_TypeCheck_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_TypeCheck_t));
        vader_obj_header_init(_a40_obj, 647u);
        _a40_obj->f_type_id = t2;
        l5 = (void*) _a40_obj;
        l10 = ((vader_struct_vader_midir_InstrTypeCheck_t*) l3)->f_span;
        vader_midir_push_emit(l0, vader_ref_box(l5), l10);
        l4 = ((vader_struct_vader_midir_InstrTypeCheck_t*) l3)->f_dst;
        l3 = ((vader_struct_vader_midir_InstrTypeCheck_t*) l3)->f_span;
        vader_midir_emit_result(l0, l2, l4, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 844u) {
        l3 = l1.payload.obj;
        l7 = ((vader_struct_vader_midir_InstrTypeConst_t*) l3)->f_value_type;
        l5 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project;
        t2 = vader_bytecode_intern_type(l7, l5);
        vader_struct_vader_bytecode_TypeConst_t* _a41_obj = (vader_struct_vader_bytecode_TypeConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_TypeConst_t));
        vader_obj_header_init(_a41_obj, 648u);
        _a41_obj->f_type_id = t2;
        l5 = (void*) _a41_obj;
        l10 = ((vader_struct_vader_midir_InstrTypeConst_t*) l3)->f_span;
        vader_midir_push_emit(l0, vader_ref_box(l5), l10);
        l4 = ((vader_struct_vader_midir_InstrTypeConst_t*) l3)->f_dst;
        l3 = ((vader_struct_vader_midir_InstrTypeConst_t*) l3)->f_span;
        vader_midir_emit_result(l0, l2, l4, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 827u) {
        l3 = l1.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrCast_t*) l3)->f_value;
        l5 = ((vader_struct_vader_midir_InstrCast_t*) l3)->f_span;
        vader_midir_emit_first_get(l0, l2, l4, l5);
        l5 = ((vader_struct_vader_midir_CFGFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_fn_)->f_locals;
        t0 = ((int64_t) (int32_t) ((vader_struct_vader_midir_InstrCast_t*) l3)->f_value);
        l6 = (size_t) (int64_t) t0;
        vader_array_t* _a42_slotarr = ((vader_array_t*) l5);
        if (_a42_slotarr->buf != NULL && _a42_slotarr->buf->header.forward != NULL) { _a42_slotarr->buf = vader_array_buf_forward(_a42_slotarr->buf); }
        if ((size_t) l6 >= _a42_slotarr->length) { vader_trap("array index out of bounds"); }
        t1 = vader_array_ref_load_obj(_a42_slotarr->buf, _a42_slotarr->offset + (size_t) l6);
        l8 = vader_bytecode_val_type_of_type(((vader_struct_vader_midir_CFGLocal_t*) t1)->f_type);
        l9 = vader_bytecode_val_type_of_type(((vader_struct_vader_midir_InstrCast_t*) l3)->f_type);
        l4 = ((int32_t) (uint8_t) l8);
        l15 = ((int32_t) (uint8_t) l9);
        if (l4 != l15) {
            l7 = vader_bytecode_convert_target_of(l9);
            if (l7.tag == 0u) {
                l20 = ((vader_struct_vader_midir_InstrCast_t*) l3)->f_type;
                l5 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project;
                t2 = vader_bytecode_intern_type(l20, l5);
                vader_struct_vader_bytecode_RefCast_t* _a43_obj = (vader_struct_vader_bytecode_RefCast_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_RefCast_t));
                vader_obj_header_init(_a43_obj, 626u);
                _a43_obj->f_type_id = t2;
                l5 = (void*) _a43_obj;
                l10 = ((vader_struct_vader_midir_InstrCast_t*) l3)->f_span;
                vader_midir_push_emit(l0, vader_ref_box(l5), l10);
            } else {
                t5 = vader_midir_convert_eligible(l8);
                if (t5) {
                    l16 = vader_bytecode_val_type_name(l8);
                    l8 = ((uint8_t) l7.payload.i);
                    vader_struct_vader_bytecode_Convert_t* _a44_obj = (vader_struct_vader_bytecode_Convert_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_Convert_t));
                    vader_obj_header_init(_a44_obj, 544u);
                    _a44_obj->f_from_name = l16;
                    _a44_obj->f_target = l8;
                    l5 = (void*) _a44_obj;
                    l10 = ((vader_struct_vader_midir_InstrCast_t*) l3)->f_span;
                    vader_midir_push_emit(l0, vader_ref_box(l5), l10);
                } else {
                    l7 = ((vader_struct_vader_midir_InstrCast_t*) l3)->f_type;
                    l5 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project;
                    t2 = vader_bytecode_intern_type(l7, l5);
                    vader_struct_vader_bytecode_RefCast_t* _a45_obj = (vader_struct_vader_bytecode_RefCast_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_RefCast_t));
                    vader_obj_header_init(_a45_obj, 626u);
                    _a45_obj->f_type_id = t2;
                    l5 = (void*) _a45_obj;
                    l10 = ((vader_struct_vader_midir_InstrCast_t*) l3)->f_span;
                    vader_midir_push_emit(l0, vader_ref_box(l5), l10);
                }
            }
        } else {
        }
        l4 = ((vader_struct_vader_midir_InstrCast_t*) l3)->f_dst;
        l3 = ((vader_struct_vader_midir_InstrCast_t*) l3)->f_span;
        vader_midir_emit_result(l0, l2, l4, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 829u) {
        l3 = l1.payload.obj;
        l7 = ((vader_struct_vader_midir_InstrCellNew_t*) l3)->f_value_type;
        l5 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project;
        l4 = vader_bytecode_intern_cell_type(l7, l5);
        l15 = ((vader_struct_vader_midir_InstrCellNew_t*) l3)->f_value;
        l5 = ((vader_struct_vader_midir_InstrCellNew_t*) l3)->f_span;
        vader_midir_emit_first_get(l0, l2, l15, l5);
        vader_struct_vader_bytecode_StructNew_t* _a46_obj = (vader_struct_vader_bytecode_StructNew_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_StructNew_t));
        vader_obj_header_init(_a46_obj, 645u);
        _a46_obj->f_type_id = l4;
        _a46_obj->f_stack = false;
        l5 = (void*) _a46_obj;
        l10 = ((vader_struct_vader_midir_InstrCellNew_t*) l3)->f_span;
        vader_midir_push_emit(l0, vader_ref_box(l5), l10);
        l4 = ((vader_struct_vader_midir_InstrCellNew_t*) l3)->f_dst;
        l3 = ((vader_struct_vader_midir_InstrCellNew_t*) l3)->f_span;
        vader_midir_emit_result(l0, l2, l4, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 828u) {
        l3 = l1.payload.obj;
        l7 = ((vader_struct_vader_midir_InstrCellGet_t*) l3)->f_value_type;
        l5 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project;
        l4 = vader_bytecode_intern_cell_type(l7, l5);
        l19 = std_collections_contains_key__i64__bool(((vader_struct_std_collections_MutableSet__i64_t*) ((vader_struct_vader_midir_ScheduleHints_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_hints)->f_skip_first_get)->f_inner, l2);
        l15 = ((vader_struct_vader_midir_InstrCellGet_t*) l3)->f_cell;
        l5 = ((vader_struct_vader_midir_InstrCellGet_t*) l3)->f_span;
        vader_midir_emit_first_get(l0, l2, l15, l5);
        l22 = false;
        if (!(l19)) {
            l22 = vader_midir_try_fuse_local_field(l0, l4, INT32_C(0));
        } else {
        }
        if (!(l22)) {
            vader_struct_vader_bytecode_StructGet_t* _a47_obj = (vader_struct_vader_bytecode_StructGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_StructGet_t));
            vader_obj_header_init(_a47_obj, 644u);
            _a47_obj->f_type_id = l4;
            _a47_obj->f_field_index = INT32_C(0);
            l5 = (void*) _a47_obj;
            l10 = ((vader_struct_vader_midir_InstrCellGet_t*) l3)->f_span;
            vader_midir_push_emit(l0, vader_ref_box(l5), l10);
        } else {
        }
        l4 = ((vader_struct_vader_midir_InstrCellGet_t*) l3)->f_dst;
        l3 = ((vader_struct_vader_midir_InstrCellGet_t*) l3)->f_span;
        vader_midir_emit_result(l0, l2, l4, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 830u) {
        l3 = l1.payload.obj;
        l7 = ((vader_struct_vader_midir_InstrCellSet_t*) l3)->f_value_type;
        l5 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project;
        l4 = vader_bytecode_intern_cell_type(l7, l5);
        l15 = ((vader_struct_vader_midir_InstrCellSet_t*) l3)->f_cell;
        l5 = ((vader_struct_vader_midir_InstrCellSet_t*) l3)->f_span;
        vader_midir_emit_first_get(l0, l2, l15, l5);
        l15 = ((vader_struct_vader_midir_InstrCellSet_t*) l3)->f_value;
        l5 = ((vader_struct_vader_midir_InstrCellSet_t*) l3)->f_span;
        vader_midir_emit_get(l0, l15, l5);
        vader_struct_vader_bytecode_StructSet_t* _a48_obj = (vader_struct_vader_bytecode_StructSet_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_StructSet_t));
        vader_obj_header_init(_a48_obj, 646u);
        _a48_obj->f_type_id = l4;
        _a48_obj->f_field_index = INT32_C(0);
        _a48_obj->f_stack = false;
        l5 = (void*) _a48_obj;
        l3 = ((vader_struct_vader_midir_InstrCellSet_t*) l3)->f_span;
        vader_midir_push_emit(l0, vader_ref_box(l5), l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 839u) {
        l3 = l1.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrMakeClosure_t*) l3)->f_env;
        l5 = ((vader_struct_vader_midir_InstrMakeClosure_t*) l3)->f_span;
        vader_midir_emit_first_get(l0, l2, l4, l5);
        l7 = vader_midir_closure_header_type(((vader_struct_vader_midir_InstrMakeClosure_t*) l3)->f_type);
        l5 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project;
        l4 = vader_bytecode_intern_type(l7, l5);
        l5 = ((vader_struct_vader_bytecode_EmitterCtx_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_project)->f_function_index_by_symbol_id;
        l15 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_midir_InstrMakeClosure_t*) l3)->f_fn_symbol)->f_id;
        l7 = std_collections_get__i32__i32(l5, l15);
        if (l7.tag == 163u) {
            t2 = ((int32_t) l7.payload.i);
            vader_struct_vader_bytecode_MakeClosure_t* _a49_obj = (vader_struct_vader_bytecode_MakeClosure_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_MakeClosure_t));
            vader_obj_header_init(_a49_obj, 623u);
            _a49_obj->f_function_index = t2;
            _a49_obj->f_env_type_id = l4;
            l5 = (void*) _a49_obj;
            l10 = ((vader_struct_vader_midir_InstrMakeClosure_t*) l3)->f_span;
            vader_midir_push_emit(l0, vader_ref_box(l5), l10);
        } else {
            l16 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_midir_InstrMakeClosure_t*) l3)->f_fn_symbol)->f_name;
            l6 = vader_import_0(l16);
            l5 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(109) + l6));
            l6 = (size_t) (int64_t) INT64_C(0);
            l6 = std_core_write_string_at(l5, l6, 1746u);
            l6 = std_core_write_string_at(l5, l6, l16);
            l6 = std_core_write_string_at(l5, l6, 269u);
            t2 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_midir_InstrMakeClosure_t*) l3)->f_fn_symbol)->f_id;
            l18 = ((int64_t) (int32_t) t2);
            l6 = std_core_write_int(l5, l6, l18);
            l6 = std_core_write_string_at(l5, l6, 338u);
            t3 = std_core_finish_buffer(l5, l6);
            vader_import_32(t3);
        }
        l4 = ((vader_struct_vader_midir_InstrMakeClosure_t*) l3)->f_dst;
        l3 = ((vader_struct_vader_midir_InstrMakeClosure_t*) l3)->f_span;
        vader_midir_emit_result(l0, l2, l4, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 838u) {
        l3 = l1.payload.obj;
        l6 = ((vader_array_t*) ((vader_struct_vader_midir_InstrIntrinsic_t*) l3)->f_args)->length;
        l11 = (size_t) (int64_t) INT64_C(0);
        {
            loop_2049: {
                if ((l11 < l6)) {
                    if (l11 == INT64_C(0)) {
                        vader_array_t* _a50_slotarr = ((vader_array_t*) ((vader_struct_vader_midir_InstrIntrinsic_t*) l3)->f_args);
                        if (_a50_slotarr->buf != NULL && _a50_slotarr->buf->header.forward != NULL) { _a50_slotarr->buf = vader_array_buf_forward(_a50_slotarr->buf); }
                        if ((size_t) l11 >= _a50_slotarr->length) { vader_trap("array index out of bounds"); }
                        l4 = ((int32_t*) _a50_slotarr->buf->slots)[_a50_slotarr->offset + (size_t) l11];
                        l5 = ((vader_struct_vader_midir_InstrIntrinsic_t*) l3)->f_span;
                        vader_midir_emit_first_get(l0, l2, l4, l5);
                    } else {
                        vader_array_t* _a51_slotarr = ((vader_array_t*) ((vader_struct_vader_midir_InstrIntrinsic_t*) l3)->f_args);
                        if (_a51_slotarr->buf != NULL && _a51_slotarr->buf->header.forward != NULL) { _a51_slotarr->buf = vader_array_buf_forward(_a51_slotarr->buf); }
                        if ((size_t) l11 >= _a51_slotarr->length) { vader_trap("array index out of bounds"); }
                        l15 = ((int32_t*) _a51_slotarr->buf->slots)[_a51_slotarr->offset + (size_t) l11];
                        l10 = ((vader_struct_vader_midir_InstrIntrinsic_t*) l3)->f_span;
                        vader_midir_emit_get(l0, l15, l10);
                    }
                    t0 = (l11 + INT64_C(1));
                    l11 = (size_t) (int64_t) t0;
                    goto loop_2049;
                } else {
                }
            }
        }
        t3 = ((vader_struct_vader_midir_InstrIntrinsic_t*) l3)->f_name;
        l7 = vader_midir_intrinsic_op_for_name(t3);
        if (l7.tag == 0u) {
            l16 = ((vader_struct_vader_midir_InstrIntrinsic_t*) l3)->f_name;
            l17 = ((vader_struct_vader_midir_CFGFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_fn_)->f_mangled;
            t3 = concat_5(1744u, l16, 903u, l17, 282u);
            vader_import_32(t3);
        } else {
        }
        l5 = ((vader_struct_vader_midir_InstrIntrinsic_t*) l3)->f_span;
        vader_midir_push_emit(l0, l7, l5);
        l7 = ((vader_struct_vader_midir_InstrIntrinsic_t*) l3)->f_dst;
        l3 = ((vader_struct_vader_midir_InstrIntrinsic_t*) l3)->f_span;
        vader_midir_emit_result_if_any(l0, l2, l7, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 834u) {
        l3 = l1.payload.obj;
        l4 = ((vader_struct_vader_midir_InstrDeferPush_t*) l3)->f_value;
        l5 = ((vader_struct_vader_midir_InstrDeferPush_t*) l3)->f_span;
        vader_midir_emit_first_get(l0, l2, l4, l5);
        vader_struct_vader_bytecode_DeferPush_t* _a52_obj = (vader_struct_vader_bytecode_DeferPush_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_DeferPush_t));
        vader_obj_header_init(_a52_obj, 548u);
        l5 = (void*) _a52_obj;
        l3 = ((vader_struct_vader_midir_InstrDeferPush_t*) l3)->f_span;
        vader_midir_push_emit(l0, vader_ref_box(l5), l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 833u) {
        l3 = l1.payload.obj;
        t2 = ((vader_struct_vader_midir_InstrDeferPopExec_t*) l3)->f_count;
        vader_struct_vader_bytecode_DeferPopExec_t* _a53_obj = (vader_struct_vader_bytecode_DeferPopExec_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_DeferPopExec_t));
        vader_obj_header_init(_a53_obj, 547u);
        _a53_obj->f_count = t2;
        l5 = (void*) _a53_obj;
        l3 = ((vader_struct_vader_midir_InstrDeferPopExec_t*) l3)->f_span;
        vader_midir_push_emit(l0, vader_ref_box(l5), l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_import_32(1743u);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_midir_emit_range(void* l0, int32_t l1, int32_t l2) {
    int32_t l3, l4, l5, l7, l8, l14, l16, l18, l22, l23, l25;
    bool l6, l12;
    void* l9 = NULL;
    void* l11 = NULL;
    void* l13 = NULL;
    void* l15 = NULL;
    void* l19 = NULL;
    void* l20 = NULL;
    void* l21 = NULL;
    void* l24 = NULL;
    void* l26 = NULL;
    void* l27 = NULL;
    size_t l10;
    vader_box_t l17 = vader_box_null();
    int64_t t0;
    bool t1;
    vader_box_t* gc_roots[1] = { &l17 };
    void** gc_raw_roots[11] = { &l0, &l9, &l11, &l13, &l15, &l19, &l20, &l21, &l24, &l26, &l27 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 11u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = l1;
    {
        loop_3: {
            l4 = l3;
            l5 = -(INT32_C(1));
            if (!(l4 == l5)) {
                l7 = l3;
                l8 = l2;
                l6 = !(l7 == l8);
            } else {
                l6 = false;
            }
            if (l6) {
                l9 = ((vader_struct_vader_midir_CFGFunction_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_fn_)->f_blocks;
                t0 = ((int64_t) (int32_t) l3);
                l10 = (size_t) (int64_t) t0;
                vader_array_t* _a0_slotarr = ((vader_array_t*) l9);
                if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                if ((size_t) l10 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                l11 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l10);
                l12 = false;
                l13 = ((vader_struct_std_collections_MutableSet__i32_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_wrapped_loop_headers)->f_inner;
                l14 = l3;
                t1 = std_collections_contains_key__i32__bool(l13, l14);
                if (!(t1)) {
                    t1 = vader_midir_loop_exit_present(l0, l3);
                    if (t1) {
                        l12 = true;
                    } else {
                    }
                } else {
                }
                if (l12) {
                    l15 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_loop_exit;
                    l16 = l3;
                    l17 = std_collections_get__i32__Any(l15, l16);
                    l18 = -(INT32_C(1));
                    if (l17.tag == 163u) {
                        l18 = ((int32_t) l17.payload.i);
                    } else {
                    }
                    l19 = ((vader_struct_vader_midir_BasicBlock_t*) l11)->f_span;
                    vader_midir_cf_block(l0, l19, l18);
                    l20 = ((vader_struct_vader_midir_BasicBlock_t*) l11)->f_span;
                    vader_midir_cf_loop(l0, l20, l3);
                    l21 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_wrapped_loop_headers;
                    l22 = l3;
                    std_collections_add__i32(l21, l22);
                    l23 = -(INT32_C(1));
                    if (l17.tag == 163u) {
                        l23 = ((int32_t) l17.payload.i);
                    } else {
                    }
                    vader_midir_emit_range(l0, l3, l23);
                    l24 = ((vader_struct_std_collections_MutableSet__i32_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_wrapped_loop_headers)->f_inner;
                    l25 = l3;
                    std_collections_remove__i32__bool(l24, l25);
                    l26 = ((vader_struct_vader_midir_BasicBlock_t*) l11)->f_span;
                    vader_midir_cf_end(l0, l26);
                    l27 = ((vader_struct_vader_midir_BasicBlock_t*) l11)->f_span;
                    vader_midir_cf_end(l0, l27);
                    if (l17.tag == 163u) {
                        l3 = ((int32_t) l17.payload.i);
                    } else {
                        l3 = -(INT32_C(1));
                    }
                    goto loop_3;
                }
                l3 = vader_midir_emit_block_contents(l0, l3, l2);
                goto loop_3;
            } else {
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
    t0 = std_collections_contains_key__i64__bool(((vader_struct_std_collections_MutableSet__i64_t*) ((vader_struct_vader_midir_ScheduleHints_t*) ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_hints)->f_skip_set)->f_inner, l1);
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

static vader_string_t vader_midir_extern_symbol_name(void* l0) {
    void* l1;
    void* l4;
    void* l5;
    void* l8;
    size_t l2, l3, l6, l9;
    vader_box_t l7;
    vader_string_t t0;
    int64_t t1;
    size_t t2;
    vader_box_t t3;
    void* t4;
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
                if (t0 != 1436u) {
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
                if (l7.tag == 467u) {
                    l8 = l7.payload.obj;
                    t2 = ((vader_array_t*) ((vader_struct_toolchain_ast_StringLitExpr_t*) l8)->f_parts)->length;
                    if (t2 == INT64_C(1)) {
                        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_StringLitExpr_t*) l8)->f_parts);
                        if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                        if ((size_t) INT32_C(0) >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                        t3 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) INT32_C(0));
                        if (t3.tag == 469u) {
                            vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_StringLitExpr_t*) l8)->f_parts);
                            if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                            if ((size_t) INT32_C(0) >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                            t3 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) INT32_C(0));
                            t4 = t3.payload.obj;
                            t0 = ((vader_struct_toolchain_ast_StringLitText_t*) t4)->f_value;
                            return t0;
                        }
                        l9 = (size_t) (int64_t) INT64_C(1);
                        t1 = (l3 + l9);
                        l3 = (size_t) (int64_t) t1;
                        goto loop_7;
                    }
                    l9 = (size_t) (int64_t) INT64_C(1);
                    t1 = (l3 + l9);
                    l3 = (size_t) (int64_t) t1;
                    goto loop_7;
                }
                l9 = (size_t) (int64_t) INT64_C(1);
                t1 = (l3 + l9);
                l3 = (size_t) (int64_t) t1;
                goto loop_7;
            } else {
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
    void* l16 = NULL;
    void* l18 = NULL;
    void* l20 = NULL;
    size_t l7, l8, l19, l21, l22;
    int32_t l9, l11, l14, l15, l17, l23;
    vader_box_t l13 = vader_box_null();
    int64_t t0;
    size_t t1;
    bool t2;
    void* t3 = NULL;
    vader_box_t* gc_roots[1] = { &l13 };
    void** gc_raw_roots[13] = { &l0, &l1, &l2, &l3, &l4, &l5, &l6, &l10, &l12, &l16, &l18, &l20, &t3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 13u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(9u, 0u, 7u, 163u);
    l3 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(15u, 0u, 0u, 170u);
    l4 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 163u);
    l5 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__i32__Any___Any_t* _a3_obj = (vader_struct_std_collections_MutableMap__i32__Any___Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__Any___Any_t));
    vader_obj_header_init(_a3_obj, 278u);
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
                vader_struct___Tuple_1282_t* _a6_obj = (vader_struct___Tuple_1282_t*) vader_gc_alloc(sizeof(vader_struct___Tuple_1282_t));
                vader_obj_header_init(_a6_obj, 218u);
                _a6_obj->f__0 = l9;
                _a6_obj->f__1 = l4;
                l10 = (void*) _a6_obj;
                l11 = ((vader_struct___Tuple_1282_t*) l10)->f__0;
                l12 = ((vader_struct___Tuple_1282_t*) l10)->f__1;
                t0 = (l8 + INT64_C(1));
                l8 = (size_t) (int64_t) t0;
                l13 = vader_box_obj(0u, NULL);
                t1 = ((vader_array_t*) ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_blocks)->length;
                l14 = ((int32_t) (size_t) t1);
                l15 = INT32_C(0);
                {
                    loop_64: {
                        if ((l15 < l14)) {
                            l16 = ((vader_struct_std_collections_MutableSet__i32_t*) l12)->f_inner;
                            l17 = l15;
                            t2 = std_collections_contains_key__i32__bool(l16, l17);
                            if (t2) {
                                l18 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_blocks;
                                t0 = ((int64_t) (int32_t) l15);
                                l19 = (size_t) (int64_t) t0;
                                vader_array_t* _a7_slotarr = ((vader_array_t*) l18);
                                if (_a7_slotarr->buf != NULL && _a7_slotarr->buf->header.forward != NULL) { _a7_slotarr->buf = vader_array_buf_forward(_a7_slotarr->buf); }
                                if ((size_t) l19 >= _a7_slotarr->length) { vader_trap("array index out of bounds"); }
                                t3 = vader_array_ref_load_obj(_a7_slotarr->buf, _a7_slotarr->offset + (size_t) l19);
                                l20 = vader_midir_successors_of(t3);
                                vader_array_t* _a8_slotarr = ((vader_array_t*) l20);
                                if (_a8_slotarr->buf != NULL && _a8_slotarr->buf->header.forward != NULL) { _a8_slotarr->buf = vader_array_buf_forward(_a8_slotarr->buf); }
                                l21 = ((vader_array_t*) l20)->length;
                                l22 = (size_t) (int64_t) INT64_C(0);
                                {
                                    loop_92: {
                                        if ((l22 < l21)) {
                                            l23 = ((int32_t*) _a8_slotarr->buf->slots)[_a8_slotarr->offset + (size_t) l22];
                                            t2 = std_collections_contains_key__i32__bool(((vader_struct_std_collections_MutableSet__i32_t*) l12)->f_inner, l23);
                                            if (!(t2)) {
                                                if (l13.tag == 0u) {
                                                    l13 = vader_box_i32(163u, l23);
                                                } else {
                                                }
                                            } else {
                                            }
                                            t0 = (l22 + INT64_C(1));
                                            l22 = (size_t) (int64_t) t0;
                                            goto loop_92;
                                        } else {
                                        }
                                    }
                                }
                            } else {
                            }
                            if (!(l13.tag == 0u)) {
                            } else {
                                l15 = (l15 + INT32_C(1));
                                goto loop_64;
                            }
                        } else {
                        }
                    }
                }
                std_collections_put__i32__Any(l3, l11, l13);
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
    if (l5.tag == 518u) {
        l3 = l5.payload.obj;
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcStruct_t*) l3)->f_fields);
        if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
        l4 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcStruct_t*) l3)->f_fields)->length;
        l6 = (size_t) (int64_t) INT64_C(0);
        {
            loop_20: {
                if ((l6 < l4)) {
                    if ((size_t) l6 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                    t1 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l6);
                    t2 = ((vader_struct_vader_bytecode_BcField_t*) t1)->f_name;
                    if (t2 == l2) {
                        t3 = vader_box_i64(169u, (int64_t)(uint64_t) l6);
                        return t3;
                    }
                    t0 = (l6 + INT64_C(1));
                    l6 = (size_t) (int64_t) t0;
                    goto loop_20;
                } else {
                }
            }
        }
        t3 = vader_box_obj(0u, NULL);
        return t3;
    }
    t3 = vader_box_obj(0u, NULL);
    return t3;
}

static vader_box_t vader_midir_first_stack_operand(vader_box_t l0) {
    void* l1;
    vader_box_t t0;
    void* t1;
    size_t t2;
    int32_t t3;
    if (l0.tag == 831u) {
        t0 = vader_box_obj(0u, NULL);
        return t0;
    }
    if (l0.tag == 837u) {
        t0 = vader_box_obj(0u, NULL);
        return t0;
    }
    if (l0.tag == 832u) {
        t0 = vader_box_obj(0u, NULL);
        return t0;
    }
    if (l0.tag == 844u) {
        t0 = vader_box_obj(0u, NULL);
        return t0;
    }
    if (l0.tag == 840u) {
        t1 = l0.payload.obj;
        t0 = vader_box_i32(163u, ((vader_struct_vader_midir_InstrMove_t*) t1)->f_src);
        return t0;
    }
    if (l0.tag == 824u) {
        t1 = l0.payload.obj;
        t0 = vader_box_i32(163u, ((vader_struct_vader_midir_InstrBinOp_t*) t1)->f_lhs);
        return t0;
    }
    if (l0.tag == 845u) {
        t1 = l0.payload.obj;
        t0 = vader_box_i32(163u, ((vader_struct_vader_midir_InstrUnOp_t*) t1)->f_operand);
        return t0;
    }
    if (l0.tag == 825u) {
        l1 = l0.payload.obj;
        t2 = ((vader_array_t*) ((vader_struct_vader_midir_InstrCall_t*) l1)->f_args)->length;
        if ((t2 > INT64_C(0))) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_midir_InstrCall_t*) l1)->f_args);
            if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
            if ((size_t) INT32_C(0) >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
            t3 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) INT32_C(0)];
            t0 = vader_box_i32(163u, t3);
            return t0;
        }
        t0 = vader_box_obj(0u, NULL);
        return t0;
    }
    if (l0.tag == 826u) {
        l1 = l0.payload.obj;
        t2 = ((vader_array_t*) ((vader_struct_vader_midir_InstrCallIndirect_t*) l1)->f_args)->length;
        if ((t2 > INT64_C(0))) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_midir_InstrCallIndirect_t*) l1)->f_args);
            if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
            if ((size_t) INT32_C(0) >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
            t3 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) INT32_C(0)];
            t0 = vader_box_i32(163u, t3);
            return t0;
        }
        t0 = vader_box_i32(163u, ((vader_struct_vader_midir_InstrCallIndirect_t*) l1)->f_callee);
        return t0;
    }
    if (l0.tag == 846u) {
        l1 = l0.payload.obj;
        t2 = ((vader_array_t*) ((vader_struct_vader_midir_InstrVirtualCall_t*) l1)->f_args)->length;
        if ((t2 > INT64_C(0))) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_midir_InstrVirtualCall_t*) l1)->f_args);
            if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
            if ((size_t) INT32_C(0) >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
            t3 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) INT32_C(0)];
            t0 = vader_box_i32(163u, t3);
            return t0;
        }
        t0 = vader_box_i32(163u, ((vader_struct_vader_midir_InstrVirtualCall_t*) l1)->f_receiver);
        return t0;
    }
    if (l0.tag == 835u) {
        t1 = l0.payload.obj;
        t0 = vader_box_i32(163u, ((vader_struct_vader_midir_InstrFieldGet_t*) t1)->f_target);
        return t0;
    }
    if (l0.tag == 836u) {
        t1 = l0.payload.obj;
        t0 = vader_box_i32(163u, ((vader_struct_vader_midir_InstrFieldSet_t*) t1)->f_target);
        return t0;
    }
    if (l0.tag == 818u) {
        t1 = l0.payload.obj;
        t0 = vader_box_i32(163u, ((vader_struct_vader_midir_InstrArrayGet_t*) t1)->f_target);
        return t0;
    }
    if (l0.tag == 822u) {
        t1 = l0.payload.obj;
        t0 = vader_box_i32(163u, ((vader_struct_vader_midir_InstrArraySet_t*) t1)->f_target);
        return t0;
    }
    if (l0.tag == 819u) {
        t1 = l0.payload.obj;
        t0 = vader_box_i32(163u, ((vader_struct_vader_midir_InstrArrayLen_t*) t1)->f_target);
        return t0;
    }
    if (l0.tag == 821u) {
        t1 = l0.payload.obj;
        t0 = vader_box_i32(163u, ((vader_struct_vader_midir_InstrArrayPush_t*) t1)->f_target);
        return t0;
    }
    if (l0.tag == 823u) {
        t1 = l0.payload.obj;
        t0 = vader_box_i32(163u, ((vader_struct_vader_midir_InstrArraySlice_t*) t1)->f_target);
        return t0;
    }
    if (l0.tag == 841u) {
        t1 = l0.payload.obj;
        t0 = vader_box_i32(163u, ((vader_struct_vader_midir_InstrStringSlice_t*) t1)->f_target);
        return t0;
    }
    if (l0.tag == 842u) {
        l1 = l0.payload.obj;
        t2 = ((vader_array_t*) ((vader_struct_vader_midir_InstrStructNew_t*) l1)->f_fields)->length;
        if ((t2 > INT64_C(0))) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_midir_InstrStructNew_t*) l1)->f_fields);
            if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
            if ((size_t) INT32_C(0) >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
            t3 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) INT32_C(0)];
            t0 = vader_box_i32(163u, t3);
            return t0;
        }
        t0 = vader_box_obj(0u, NULL);
        return t0;
    }
    if (l0.tag == 820u) {
        l1 = l0.payload.obj;
        t2 = ((vader_array_t*) ((vader_struct_vader_midir_InstrArrayNew_t*) l1)->f_elements)->length;
        if ((t2 > INT64_C(0))) {
            vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_vader_midir_InstrArrayNew_t*) l1)->f_elements);
            if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
            if ((size_t) INT32_C(0) >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
            t3 = ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) INT32_C(0)];
            t0 = vader_box_i32(163u, t3);
            return t0;
        }
        t0 = vader_box_obj(0u, NULL);
        return t0;
    }
    if (l0.tag == 843u) {
        t1 = l0.payload.obj;
        t0 = vader_box_i32(163u, ((vader_struct_vader_midir_InstrTypeCheck_t*) t1)->f_value);
        return t0;
    }
    if (l0.tag == 827u) {
        t1 = l0.payload.obj;
        t0 = vader_box_i32(163u, ((vader_struct_vader_midir_InstrCast_t*) t1)->f_value);
        return t0;
    }
    if (l0.tag == 829u) {
        t1 = l0.payload.obj;
        t0 = vader_box_i32(163u, ((vader_struct_vader_midir_InstrCellNew_t*) t1)->f_value);
        return t0;
    }
    if (l0.tag == 828u) {
        t1 = l0.payload.obj;
        t0 = vader_box_i32(163u, ((vader_struct_vader_midir_InstrCellGet_t*) t1)->f_cell);
        return t0;
    }
    if (l0.tag == 830u) {
        t1 = l0.payload.obj;
        t0 = vader_box_i32(163u, ((vader_struct_vader_midir_InstrCellSet_t*) t1)->f_cell);
        return t0;
    }
    if (l0.tag == 839u) {
        t1 = l0.payload.obj;
        t0 = vader_box_i32(163u, ((vader_struct_vader_midir_InstrMakeClosure_t*) t1)->f_env);
        return t0;
    }
    if (l0.tag == 838u) {
        l1 = l0.payload.obj;
        t2 = ((vader_array_t*) ((vader_struct_vader_midir_InstrIntrinsic_t*) l1)->f_args)->length;
        if ((t2 > INT64_C(0))) {
            vader_array_t* _a5_slotarr = ((vader_array_t*) ((vader_struct_vader_midir_InstrIntrinsic_t*) l1)->f_args);
            if (_a5_slotarr->buf != NULL && _a5_slotarr->buf->header.forward != NULL) { _a5_slotarr->buf = vader_array_buf_forward(_a5_slotarr->buf); }
            if ((size_t) INT32_C(0) >= _a5_slotarr->length) { vader_trap("array index out of bounds"); }
            t3 = ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) INT32_C(0)];
            t0 = vader_box_i32(163u, t3);
            return t0;
        }
        t0 = vader_box_obj(0u, NULL);
        return t0;
    }
    if (l0.tag == 834u) {
        t1 = l0.payload.obj;
        t0 = vader_box_i32(163u, ((vader_struct_vader_midir_InstrDeferPush_t*) t1)->f_value);
        return t0;
    }
    if (l0.tag == 833u) {
        t0 = vader_box_obj(0u, NULL);
        return t0;
    }
    vader_unreachable("unreachable return in vader_midir$first_stack_operand");
}

static vader_box_t vader_midir_first_terminator_operand(vader_box_t l0) {
    vader_box_t t0;
    void* t1;
    if (l0.tag == 854u) {
        t0 = vader_box_obj(0u, NULL);
        return t0;
    }
    if (l0.tag == 857u) {
        t0 = vader_box_obj(0u, NULL);
        return t0;
    }
    if (l0.tag == 855u) {
        t1 = l0.payload.obj;
        t0 = vader_box_i32(163u, ((vader_struct_vader_midir_TermCondBranch_t*) t1)->f_cond);
        return t0;
    }
    if (l0.tag == 856u) {
        t1 = l0.payload.obj;
        return ((vader_struct_vader_midir_TermReturn_t*) t1)->f_value;
    }
    vader_unreachable("unreachable return in vader_midir$first_terminator_operand");
}

static void* vader_midir_fn_metadata(void* l0) {
    vader_string_t l1;
    bool l2, l3;
    void* l4 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[3] = { &l0, &l4, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct_vader_lower_LoweredFnDecl_t*) l0)->f_mangled;
    l2 = false;
    l3 = false;
    if (((vader_struct_vader_comptime_MonoEntry_t*) ((vader_struct_vader_lower_LoweredFnDecl_t*) l0)->f_origin)->f_decl.tag == 428u) {
        l4 = ((vader_struct_vader_comptime_MonoEntry_t*) ((vader_struct_vader_lower_LoweredFnDecl_t*) l0)->f_origin)->f_decl.payload.obj;
        l1 = vader_midir_extern_symbol_name(l4);
        l2 = vader_midir_decorators_have(((vader_struct_toolchain_ast_FnDecl_t*) l4)->f_decorators, 1436u);
        l3 = vader_midir_decorators_have(((vader_struct_toolchain_ast_FnDecl_t*) l4)->f_decorators, 1422u);
    } else {
    }
    vader_struct_vader_midir_FnMetadata_t* _a0_obj = (vader_struct_vader_midir_FnMetadata_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_FnMetadata_t));
    vader_obj_header_init(_a0_obj, 817u);
    _a0_obj->f_extern_name = l1;
    _a0_obj->f_is_extern = l2;
    _a0_obj->f_is_exported = l3;
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
    vader_string_t l13, l14;
    bool l15, l16;
    void* t0 = NULL;
    int64_t t1;
    vader_box_t* gc_roots[1] = { &l10 };
    void** gc_raw_roots[10] = { &l0, &l1, &l2, &l3, &l4, &l8, &l9, &l11, &l12, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 10u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_midir_count_uses(l0);
    vader_array_t* _a0_arr = vader_array_new(9u, 0u, 7u, 163u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(6u, 0u, 12u, 159u);
    l3 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 163u);
    l4 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__i32__bool_t* _a3_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
    vader_obj_header_init(_a3_obj, 310u);
    _a3_obj->f_ekeys = l2;
    _a3_obj->f_evals = l3;
    _a3_obj->f_index = l4;
    _a3_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    t0 = (void*) _a3_obj;
    vader_struct_std_collections_MutableSet__i32_t* _a4_obj = (vader_struct_std_collections_MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i32_t));
    vader_obj_header_init(_a4_obj, 387u);
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
            } else {
            }
        }
    }
    vader_array_t* _a6_arr = vader_array_new(67u, 0u, 13u, 798u);
    l3 = (void*) _a6_arr;
    l4 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_blocks;
    l5 = ((vader_array_t*) l4)->length;
    l6 = (size_t) (int64_t) INT64_C(0);
    {
        loop_57: {
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
                vader_obj_header_init(_a8_obj, 798u);
                _a8_obj->f_id = l7;
                _a8_obj->f_instructions = l9;
                _a8_obj->f_terminator = l10;
                _a8_obj->f_span = l11;
                l12 = (void*) _a8_obj;
                vader_array_push((vader_array_t*) l3, vader_ref_box(l12));
                t1 = (l6 + INT64_C(1));
                l6 = (size_t) (int64_t) t1;
                goto loop_57;
            } else {
            }
        }
    }
    l13 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_mangled;
    l1 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_params;
    l10 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_return_type;
    l2 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_locals;
    l7 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_entry;
    l4 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_origin;
    l14 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_extern_name;
    l15 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_is_extern;
    l16 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_is_exported;
    vader_struct_vader_midir_CFGFunction_t* _a9_obj = (vader_struct_vader_midir_CFGFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_CFGFunction_t));
    vader_obj_header_init(_a9_obj, 800u);
    _a9_obj->f_mangled = l13;
    _a9_obj->f_params = l1;
    _a9_obj->f_return_type = l10;
    _a9_obj->f_locals = l2;
    _a9_obj->f_blocks = l3;
    _a9_obj->f_entry = l7;
    _a9_obj->f_origin = l4;
    _a9_obj->f_extern_name = l14;
    _a9_obj->f_is_extern = l15;
    _a9_obj->f_is_exported = l16;
    t0 = (void*) _a9_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_midir_fold_moves_in_block(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l11 = NULL;
    void* l15 = NULL;
    void* l29 = NULL;
    void* l32 = NULL;
    void* l33 = NULL;
    void* l37 = NULL;
    void* l40 = NULL;
    size_t l4, l5, l21, l38, l43, l44;
    vader_box_t l6 = vader_box_null(), l7 = vader_box_null(), l13 = vader_box_null(), l16 = vader_box_null(), l19 = vader_box_null(), l22 = vader_box_null(), l23 = vader_box_null(), l39 = vader_box_null(), l42 = vader_box_null();
    int32_t l10, l12, l14, l24, l25, l26, l27, l28, l30, l34, l41;
    int64_t l17, l20, l35;
    bool l18, l31, l36;
    int64_t t0;
    bool t1;
    void* t2 = NULL;
    size_t t3;
    vader_box_t t4 = vader_box_null();
    vader_box_t* gc_roots[10] = { &l6, &l7, &l13, &l16, &l19, &l22, &l23, &l39, &l42, &t4 };
    void** gc_raw_roots[14] = { &l0, &l1, &l2, &l3, &l8, &l9, &l11, &l15, &l29, &l32, &l33, &l37, &l40, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 10u, 14u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(127u, 0u, 13u, 1157u);
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
                if (!(l6.tag == 840u)) {
                    l7 = l6;
                    vader_array_push((vader_array_t*) l3, l7);
                    t0 = (l5 + INT64_C(1));
                    l5 = (size_t) (int64_t) t0;
                    goto loop_8;
                }
                if (l6.tag == 840u) {
                    l8 = l6.payload.obj;
                    l9 = ((vader_struct_std_collections_MutableSet__i32_t*) l2)->f_inner;
                    l10 = ((vader_struct_vader_midir_InstrMove_t*) l8)->f_src;
                    t1 = std_collections_contains_key__i32__bool(l9, l10);
                    if (t1) {
                        l11 = l6.payload.obj;
                        vader_array_push((vader_array_t*) l3, vader_ref_box(l11));
                        t0 = (l5 + INT64_C(1));
                        l5 = (size_t) (int64_t) t0;
                        goto loop_8;
                    }
                    l12 = ((vader_struct_vader_midir_InstrMove_t*) l8)->f_src;
                    l13 = std_collections_get__i32__i32(l1, l12);
                    if (l13.tag == 163u) {
                        l14 = ((int32_t) l13.payload.i);
                    } else {
                        l14 = INT32_C(0);
                    }
                    if (l14 != INT32_C(1)) {
                        l15 = l6.payload.obj;
                        vader_array_push((vader_array_t*) l3, vader_ref_box(l15));
                        t0 = (l5 + INT64_C(1));
                        l5 = (size_t) (int64_t) t0;
                        goto loop_8;
                    }
                    vader_struct__Cell_i32_t* _a2_obj = (vader_struct__Cell_i32_t*) vader_gc_alloc(sizeof(vader_struct__Cell_i32_t));
                    vader_obj_header_init(_a2_obj, 188u);
                    _a2_obj->f_value = ((vader_struct_vader_midir_InstrMove_t*) l8)->f_dst;
                    t2 = (void*) _a2_obj;
                    l16 = vader_ref_box(t2);
                    l17 = -(INT64_C(1));
                    l18 = false;
                    vader_array_t* _a3_arr = vader_array_new(6u, 1u, 12u, 159u);
                    ((uint8_t*) _a3_arr->buf->slots)[_a3_arr->offset + 0u] = (uint8_t) false;
                    t2 = (void*) _a3_arr;
                    vader_struct__Cell_Array_bool__t* _a4_obj = (vader_struct__Cell_Array_bool__t*) vader_gc_alloc(sizeof(vader_struct__Cell_Array_bool__t));
                    vader_obj_header_init(_a4_obj, 174u);
                    _a4_obj->f_value = t2;
                    t2 = (void*) _a4_obj;
                    l19 = vader_ref_box(t2);
                    t3 = ((vader_array_t*) l3)->length;
                    l20 = (((int64_t) (size_t) t3) - INT64_C(1));
                    {
                        loop_107: {
                            if ((l20 >= INT64_C(0))) {
                                t0 = l20;
                                l21 = (size_t) (int64_t) t0;
                                vader_array_t* _a5_slotarr = ((vader_array_t*) l3);
                                if (_a5_slotarr->buf != NULL && _a5_slotarr->buf->header.forward != NULL) { _a5_slotarr->buf = vader_array_buf_forward(_a5_slotarr->buf); }
                                if ((size_t) l21 >= _a5_slotarr->length) { vader_trap("array index out of bounds"); }
                                l22 = vader_array_ref_load_box(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l21);
                                l23 = vader_midir_dst_of(l22);
                                if (l23.tag == 163u) {
                                    l24 = ((int32_t) l23.payload.i);
                                    l25 = l24;
                                    l26 = ((vader_struct_vader_midir_InstrMove_t*) l8)->f_src;
                                    if (l25 == l26) {
                                        l17 = l20;
                                    } else {
                                        l27 = l24;
                                        l28 = ((vader_struct__Cell_i32_t*) l16.payload.obj)->f_value;
                                        if (l27 == l28) {
                                            l18 = true;
                                        } else {
                                            l29 = ((vader_struct__Cell_Array_bool__t*) l19.payload.obj)->f_value;
                                            l30 = INT32_C(0);
                                            l31 = false;
                                            vader_array_t* _a6_slotarr = ((vader_array_t*) l29);
                                            if (_a6_slotarr->buf != NULL && _a6_slotarr->buf->header.forward != NULL) { _a6_slotarr->buf = vader_array_buf_forward(_a6_slotarr->buf); }
                                            if ((size_t) l30 >= _a6_slotarr->length) { vader_trap("array index out of bounds"); }
                                            ((uint8_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l30] = (uint8_t) l31;
                                            vader_struct___lambda_env_2583_t* _a7_obj = (vader_struct___lambda_env_2583_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_2583_t));
                                            vader_obj_header_init(_a7_obj, 239u);
                                            _a7_obj->f_cap_0 = l16;
                                            _a7_obj->f_cap_1 = l19;
                                            t2 = (void*) _a7_obj;
                                            vader_fn_t* _a8_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
                                            vader_obj_header_init(_a8_closure, 138u);
                                            _a8_closure->code = (void*) &vader_fn_lift_1773;
                                            _a8_closure->env = t2;
                                            l32 = (void*) _a8_closure;
                                            vader_midir_for_each_read_local(l22, l32);
                                            l33 = ((vader_struct__Cell_Array_bool__t*) l19.payload.obj)->f_value;
                                            l34 = INT32_C(0);
                                            vader_array_t* _a9_slotarr = ((vader_array_t*) l33);
                                            if (_a9_slotarr->buf != NULL && _a9_slotarr->buf->header.forward != NULL) { _a9_slotarr->buf = vader_array_buf_forward(_a9_slotarr->buf); }
                                            if ((size_t) l34 >= _a9_slotarr->length) { vader_trap("array index out of bounds"); }
                                            t4 = vader_box_bool(159u, ((uint8_t*) _a9_slotarr->buf->slots)[_a9_slotarr->offset + (size_t) l34]);
                                            t1 = t4.payload.b;
                                            if (t1) {
                                                l18 = true;
                                            } else {
                                                l35 = INT64_C(1);
                                                l20 = (l20 - l35);
                                                goto loop_107;
                                            }
                                        }
                                    }
                                } else {
                                    l29 = ((vader_struct__Cell_Array_bool__t*) l19.payload.obj)->f_value;
                                    l30 = INT32_C(0);
                                    l31 = false;
                                    vader_array_t* _a10_slotarr = ((vader_array_t*) l29);
                                    if (_a10_slotarr->buf != NULL && _a10_slotarr->buf->header.forward != NULL) { _a10_slotarr->buf = vader_array_buf_forward(_a10_slotarr->buf); }
                                    if ((size_t) l30 >= _a10_slotarr->length) { vader_trap("array index out of bounds"); }
                                    ((uint8_t*) _a10_slotarr->buf->slots)[_a10_slotarr->offset + (size_t) l30] = (uint8_t) l31;
                                    vader_struct___lambda_env_2583_t* _a11_obj = (vader_struct___lambda_env_2583_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_2583_t));
                                    vader_obj_header_init(_a11_obj, 239u);
                                    _a11_obj->f_cap_0 = l16;
                                    _a11_obj->f_cap_1 = l19;
                                    t2 = (void*) _a11_obj;
                                    vader_fn_t* _a12_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
                                    vader_obj_header_init(_a12_closure, 138u);
                                    _a12_closure->code = (void*) &vader_fn_lift_1773;
                                    _a12_closure->env = t2;
                                    l32 = (void*) _a12_closure;
                                    vader_midir_for_each_read_local(l22, l32);
                                    l33 = ((vader_struct__Cell_Array_bool__t*) l19.payload.obj)->f_value;
                                    l34 = INT32_C(0);
                                    vader_array_t* _a13_slotarr = ((vader_array_t*) l33);
                                    if (_a13_slotarr->buf != NULL && _a13_slotarr->buf->header.forward != NULL) { _a13_slotarr->buf = vader_array_buf_forward(_a13_slotarr->buf); }
                                    if ((size_t) l34 >= _a13_slotarr->length) { vader_trap("array index out of bounds"); }
                                    t4 = vader_box_bool(159u, ((uint8_t*) _a13_slotarr->buf->slots)[_a13_slotarr->offset + (size_t) l34]);
                                    t1 = t4.payload.b;
                                    if (t1) {
                                        l18 = true;
                                    } else {
                                        l35 = INT64_C(1);
                                        l20 = (l20 - l35);
                                        goto loop_107;
                                    }
                                }
                            } else {
                            }
                        }
                    }
                    if ((l17 < INT64_C(0))) {
                        l36 = true;
                    } else {
                        l36 = l18;
                    }
                    if (l36) {
                        l37 = l6.payload.obj;
                        vader_array_push((vader_array_t*) l3, vader_ref_box(l37));
                        t0 = (l5 + INT64_C(1));
                        l5 = (size_t) (int64_t) t0;
                        goto loop_8;
                    }
                    t0 = l17;
                    l38 = (size_t) (int64_t) t0;
                    vader_array_t* _a14_slotarr = ((vader_array_t*) l3);
                    if (_a14_slotarr->buf != NULL && _a14_slotarr->buf->header.forward != NULL) { _a14_slotarr->buf = vader_array_buf_forward(_a14_slotarr->buf); }
                    if ((size_t) l38 >= _a14_slotarr->length) { vader_trap("array index out of bounds"); }
                    l39 = vader_array_ref_load_box(_a14_slotarr->buf, _a14_slotarr->offset + (size_t) l38);
                    t1 = vader_midir_instruction_has_side_effect(l39);
                    if (t1) {
                        l40 = l6.payload.obj;
                        vader_array_push((vader_array_t*) l3, vader_ref_box(l40));
                        t0 = (l5 + INT64_C(1));
                        l5 = (size_t) (int64_t) t0;
                        goto loop_8;
                    }
                    l41 = ((vader_struct_vader_midir_InstrMove_t*) l8)->f_dst;
                    l42 = vader_midir_with_dst(l39, l41);
                    t0 = l17;
                    l43 = (size_t) (int64_t) t0;
                    vader_array_t* _a15_slotarr = ((vader_array_t*) l3);
                    if (_a15_slotarr->buf != NULL && _a15_slotarr->buf->header.forward != NULL) { _a15_slotarr->buf = vader_array_buf_forward(_a15_slotarr->buf); }
                    if ((size_t) l43 >= _a15_slotarr->length) { vader_trap("array index out of bounds"); }
                    vader_array_ref_store(_a15_slotarr->buf, _a15_slotarr->offset + (size_t) l43, l42.payload.obj);
                    VADER_WRITE_BARRIER(_a15_slotarr->buf);
                    l44 = (size_t) (int64_t) INT64_C(1);
                    t0 = (l5 + l44);
                    l5 = (size_t) (int64_t) t0;
                    goto loop_8;
                }
                l44 = (size_t) (int64_t) INT64_C(1);
                t0 = (l5 + l44);
                l5 = (size_t) (int64_t) t0;
                goto loop_8;
            } else {
            }
        }
    }
    { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void vader_midir_for_each_read_in_terminator(vader_box_t l0, void* l1) {
    void* l2 = NULL;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[3] = { &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 855u) {
        t0 = l0.payload.obj;
        vader_fn_t* _a0_fnobj = (vader_fn_t*) l1;
        ((vader_fn_erased_sig_1_t) _a0_fnobj->code)(_a0_fnobj->env, vader_box_i32(163u, ((vader_struct_vader_midir_TermCondBranch_t*) t0)->f_cond));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 856u) {
        l2 = l0.payload.obj;
        if (!(((vader_struct_vader_midir_TermReturn_t*) l2)->f_value.tag == 0u)) {
            vader_fn_t* _a1_fnobj = (vader_fn_t*) l1;
            ((vader_fn_erased_sig_1_t) _a1_fnobj->code)(_a1_fnobj->env, ((vader_struct_vader_midir_TermReturn_t*) l2)->f_value);
        } else {
        }
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 854u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 857u) {
        { vader_gc_top = gc_frame.prev; return; }
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
    if (l0.tag == 831u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 837u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 840u) {
        t0 = l0.payload.obj;
        vader_fn_t* _a0_fnobj = (vader_fn_t*) l1;
        ((vader_fn_erased_sig_1_t) _a0_fnobj->code)(_a0_fnobj->env, vader_box_i32(163u, ((vader_struct_vader_midir_InstrMove_t*) t0)->f_src));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 824u) {
        l2 = l0.payload.obj;
        vader_fn_t* _a1_fnobj = (vader_fn_t*) l1;
        ((vader_fn_erased_sig_1_t) _a1_fnobj->code)(_a1_fnobj->env, vader_box_i32(163u, ((vader_struct_vader_midir_InstrBinOp_t*) l2)->f_lhs));
        vader_fn_t* _a2_fnobj = (vader_fn_t*) l1;
        ((vader_fn_erased_sig_1_t) _a2_fnobj->code)(_a2_fnobj->env, vader_box_i32(163u, ((vader_struct_vader_midir_InstrBinOp_t*) l2)->f_rhs));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 845u) {
        t0 = l0.payload.obj;
        vader_fn_t* _a3_fnobj = (vader_fn_t*) l1;
        ((vader_fn_erased_sig_1_t) _a3_fnobj->code)(_a3_fnobj->env, vader_box_i32(163u, ((vader_struct_vader_midir_InstrUnOp_t*) t0)->f_operand));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 825u) {
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
                    ((vader_fn_erased_sig_1_t) _a5_fnobj->code)(_a5_fnobj->env, vader_box_i32(163u, t1));
                    t2 = (l4 + INT64_C(1));
                    l4 = (size_t) (int64_t) t2;
                    goto loop_56;
                } else {
                }
            }
        }
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 826u) {
        l2 = l0.payload.obj;
        vader_fn_t* _a6_fnobj = (vader_fn_t*) l1;
        ((vader_fn_erased_sig_1_t) _a6_fnobj->code)(_a6_fnobj->env, vader_box_i32(163u, ((vader_struct_vader_midir_InstrCallIndirect_t*) l2)->f_callee));
        l2 = ((vader_struct_vader_midir_InstrCallIndirect_t*) l2)->f_args;
        l3 = ((vader_array_t*) l2)->length;
        l4 = (size_t) (int64_t) INT64_C(0);
        {
            loop_93: {
                if ((l4 < l3)) {
                    vader_array_t* _a7_slotarr = ((vader_array_t*) l2);
                    if (_a7_slotarr->buf != NULL && _a7_slotarr->buf->header.forward != NULL) { _a7_slotarr->buf = vader_array_buf_forward(_a7_slotarr->buf); }
                    if ((size_t) l4 >= _a7_slotarr->length) { vader_trap("array index out of bounds"); }
                    t1 = ((int32_t*) _a7_slotarr->buf->slots)[_a7_slotarr->offset + (size_t) l4];
                    vader_fn_t* _a8_fnobj = (vader_fn_t*) l1;
                    ((vader_fn_erased_sig_1_t) _a8_fnobj->code)(_a8_fnobj->env, vader_box_i32(163u, t1));
                    t2 = (l4 + INT64_C(1));
                    l4 = (size_t) (int64_t) t2;
                    goto loop_93;
                } else {
                }
            }
        }
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 846u) {
        l2 = l0.payload.obj;
        vader_fn_t* _a9_fnobj = (vader_fn_t*) l1;
        ((vader_fn_erased_sig_1_t) _a9_fnobj->code)(_a9_fnobj->env, vader_box_i32(163u, ((vader_struct_vader_midir_InstrVirtualCall_t*) l2)->f_receiver));
        l2 = ((vader_struct_vader_midir_InstrVirtualCall_t*) l2)->f_args;
        l3 = ((vader_array_t*) l2)->length;
        l4 = (size_t) (int64_t) INT64_C(0);
        {
            loop_130: {
                if ((l4 < l3)) {
                    vader_array_t* _a10_slotarr = ((vader_array_t*) l2);
                    if (_a10_slotarr->buf != NULL && _a10_slotarr->buf->header.forward != NULL) { _a10_slotarr->buf = vader_array_buf_forward(_a10_slotarr->buf); }
                    if ((size_t) l4 >= _a10_slotarr->length) { vader_trap("array index out of bounds"); }
                    t1 = ((int32_t*) _a10_slotarr->buf->slots)[_a10_slotarr->offset + (size_t) l4];
                    vader_fn_t* _a11_fnobj = (vader_fn_t*) l1;
                    ((vader_fn_erased_sig_1_t) _a11_fnobj->code)(_a11_fnobj->env, vader_box_i32(163u, t1));
                    t2 = (l4 + INT64_C(1));
                    l4 = (size_t) (int64_t) t2;
                    goto loop_130;
                } else {
                }
            }
        }
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 835u) {
        t0 = l0.payload.obj;
        vader_fn_t* _a12_fnobj = (vader_fn_t*) l1;
        ((vader_fn_erased_sig_1_t) _a12_fnobj->code)(_a12_fnobj->env, vader_box_i32(163u, ((vader_struct_vader_midir_InstrFieldGet_t*) t0)->f_target));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 836u) {
        l2 = l0.payload.obj;
        vader_fn_t* _a13_fnobj = (vader_fn_t*) l1;
        ((vader_fn_erased_sig_1_t) _a13_fnobj->code)(_a13_fnobj->env, vader_box_i32(163u, ((vader_struct_vader_midir_InstrFieldSet_t*) l2)->f_target));
        vader_fn_t* _a14_fnobj = (vader_fn_t*) l1;
        ((vader_fn_erased_sig_1_t) _a14_fnobj->code)(_a14_fnobj->env, vader_box_i32(163u, ((vader_struct_vader_midir_InstrFieldSet_t*) l2)->f_value));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 818u) {
        l2 = l0.payload.obj;
        vader_fn_t* _a15_fnobj = (vader_fn_t*) l1;
        ((vader_fn_erased_sig_1_t) _a15_fnobj->code)(_a15_fnobj->env, vader_box_i32(163u, ((vader_struct_vader_midir_InstrArrayGet_t*) l2)->f_target));
        vader_fn_t* _a16_fnobj = (vader_fn_t*) l1;
        ((vader_fn_erased_sig_1_t) _a16_fnobj->code)(_a16_fnobj->env, vader_box_i32(163u, ((vader_struct_vader_midir_InstrArrayGet_t*) l2)->f_index));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 822u) {
        l2 = l0.payload.obj;
        vader_fn_t* _a17_fnobj = (vader_fn_t*) l1;
        ((vader_fn_erased_sig_1_t) _a17_fnobj->code)(_a17_fnobj->env, vader_box_i32(163u, ((vader_struct_vader_midir_InstrArraySet_t*) l2)->f_target));
        vader_fn_t* _a18_fnobj = (vader_fn_t*) l1;
        ((vader_fn_erased_sig_1_t) _a18_fnobj->code)(_a18_fnobj->env, vader_box_i32(163u, ((vader_struct_vader_midir_InstrArraySet_t*) l2)->f_index));
        vader_fn_t* _a19_fnobj = (vader_fn_t*) l1;
        ((vader_fn_erased_sig_1_t) _a19_fnobj->code)(_a19_fnobj->env, vader_box_i32(163u, ((vader_struct_vader_midir_InstrArraySet_t*) l2)->f_value));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 819u) {
        t0 = l0.payload.obj;
        vader_fn_t* _a20_fnobj = (vader_fn_t*) l1;
        ((vader_fn_erased_sig_1_t) _a20_fnobj->code)(_a20_fnobj->env, vader_box_i32(163u, ((vader_struct_vader_midir_InstrArrayLen_t*) t0)->f_target));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 821u) {
        l2 = l0.payload.obj;
        vader_fn_t* _a21_fnobj = (vader_fn_t*) l1;
        ((vader_fn_erased_sig_1_t) _a21_fnobj->code)(_a21_fnobj->env, vader_box_i32(163u, ((vader_struct_vader_midir_InstrArrayPush_t*) l2)->f_target));
        vader_fn_t* _a22_fnobj = (vader_fn_t*) l1;
        ((vader_fn_erased_sig_1_t) _a22_fnobj->code)(_a22_fnobj->env, vader_box_i32(163u, ((vader_struct_vader_midir_InstrArrayPush_t*) l2)->f_value));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 823u) {
        l2 = l0.payload.obj;
        vader_fn_t* _a23_fnobj = (vader_fn_t*) l1;
        ((vader_fn_erased_sig_1_t) _a23_fnobj->code)(_a23_fnobj->env, vader_box_i32(163u, ((vader_struct_vader_midir_InstrArraySlice_t*) l2)->f_target));
        vader_fn_t* _a24_fnobj = (vader_fn_t*) l1;
        ((vader_fn_erased_sig_1_t) _a24_fnobj->code)(_a24_fnobj->env, vader_box_i32(163u, ((vader_struct_vader_midir_InstrArraySlice_t*) l2)->f_lo));
        vader_fn_t* _a25_fnobj = (vader_fn_t*) l1;
        ((vader_fn_erased_sig_1_t) _a25_fnobj->code)(_a25_fnobj->env, vader_box_i32(163u, ((vader_struct_vader_midir_InstrArraySlice_t*) l2)->f_hi));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 841u) {
        l2 = l0.payload.obj;
        vader_fn_t* _a26_fnobj = (vader_fn_t*) l1;
        ((vader_fn_erased_sig_1_t) _a26_fnobj->code)(_a26_fnobj->env, vader_box_i32(163u, ((vader_struct_vader_midir_InstrStringSlice_t*) l2)->f_target));
        vader_fn_t* _a27_fnobj = (vader_fn_t*) l1;
        ((vader_fn_erased_sig_1_t) _a27_fnobj->code)(_a27_fnobj->env, vader_box_i32(163u, ((vader_struct_vader_midir_InstrStringSlice_t*) l2)->f_lo));
        vader_fn_t* _a28_fnobj = (vader_fn_t*) l1;
        ((vader_fn_erased_sig_1_t) _a28_fnobj->code)(_a28_fnobj->env, vader_box_i32(163u, ((vader_struct_vader_midir_InstrStringSlice_t*) l2)->f_hi));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 842u) {
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
                    ((vader_fn_erased_sig_1_t) _a30_fnobj->code)(_a30_fnobj->env, vader_box_i32(163u, t1));
                    t2 = (l4 + INT64_C(1));
                    l4 = (size_t) (int64_t) t2;
                    goto loop_276;
                } else {
                }
            }
        }
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 820u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_midir_InstrArrayNew_t*) t0)->f_elements;
        l3 = ((vader_array_t*) l2)->length;
        l4 = (size_t) (int64_t) INT64_C(0);
        {
            loop_309: {
                if ((l4 < l3)) {
                    vader_array_t* _a31_slotarr = ((vader_array_t*) l2);
                    if (_a31_slotarr->buf != NULL && _a31_slotarr->buf->header.forward != NULL) { _a31_slotarr->buf = vader_array_buf_forward(_a31_slotarr->buf); }
                    if ((size_t) l4 >= _a31_slotarr->length) { vader_trap("array index out of bounds"); }
                    t1 = ((int32_t*) _a31_slotarr->buf->slots)[_a31_slotarr->offset + (size_t) l4];
                    vader_fn_t* _a32_fnobj = (vader_fn_t*) l1;
                    ((vader_fn_erased_sig_1_t) _a32_fnobj->code)(_a32_fnobj->env, vader_box_i32(163u, t1));
                    t2 = (l4 + INT64_C(1));
                    l4 = (size_t) (int64_t) t2;
                    goto loop_309;
                } else {
                }
            }
        }
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 843u) {
        t0 = l0.payload.obj;
        vader_fn_t* _a33_fnobj = (vader_fn_t*) l1;
        ((vader_fn_erased_sig_1_t) _a33_fnobj->code)(_a33_fnobj->env, vader_box_i32(163u, ((vader_struct_vader_midir_InstrTypeCheck_t*) t0)->f_value));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 844u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 832u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 827u) {
        t0 = l0.payload.obj;
        vader_fn_t* _a34_fnobj = (vader_fn_t*) l1;
        ((vader_fn_erased_sig_1_t) _a34_fnobj->code)(_a34_fnobj->env, vader_box_i32(163u, ((vader_struct_vader_midir_InstrCast_t*) t0)->f_value));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 829u) {
        t0 = l0.payload.obj;
        vader_fn_t* _a35_fnobj = (vader_fn_t*) l1;
        ((vader_fn_erased_sig_1_t) _a35_fnobj->code)(_a35_fnobj->env, vader_box_i32(163u, ((vader_struct_vader_midir_InstrCellNew_t*) t0)->f_value));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 828u) {
        t0 = l0.payload.obj;
        vader_fn_t* _a36_fnobj = (vader_fn_t*) l1;
        ((vader_fn_erased_sig_1_t) _a36_fnobj->code)(_a36_fnobj->env, vader_box_i32(163u, ((vader_struct_vader_midir_InstrCellGet_t*) t0)->f_cell));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 830u) {
        l2 = l0.payload.obj;
        vader_fn_t* _a37_fnobj = (vader_fn_t*) l1;
        ((vader_fn_erased_sig_1_t) _a37_fnobj->code)(_a37_fnobj->env, vader_box_i32(163u, ((vader_struct_vader_midir_InstrCellSet_t*) l2)->f_cell));
        vader_fn_t* _a38_fnobj = (vader_fn_t*) l1;
        ((vader_fn_erased_sig_1_t) _a38_fnobj->code)(_a38_fnobj->env, vader_box_i32(163u, ((vader_struct_vader_midir_InstrCellSet_t*) l2)->f_value));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 839u) {
        t0 = l0.payload.obj;
        vader_fn_t* _a39_fnobj = (vader_fn_t*) l1;
        ((vader_fn_erased_sig_1_t) _a39_fnobj->code)(_a39_fnobj->env, vader_box_i32(163u, ((vader_struct_vader_midir_InstrMakeClosure_t*) t0)->f_env));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 838u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_midir_InstrIntrinsic_t*) t0)->f_args;
        l3 = ((vader_array_t*) l2)->length;
        l4 = (size_t) (int64_t) INT64_C(0);
        {
            loop_416: {
                if ((l4 < l3)) {
                    vader_array_t* _a40_slotarr = ((vader_array_t*) l2);
                    if (_a40_slotarr->buf != NULL && _a40_slotarr->buf->header.forward != NULL) { _a40_slotarr->buf = vader_array_buf_forward(_a40_slotarr->buf); }
                    if ((size_t) l4 >= _a40_slotarr->length) { vader_trap("array index out of bounds"); }
                    t1 = ((int32_t*) _a40_slotarr->buf->slots)[_a40_slotarr->offset + (size_t) l4];
                    vader_fn_t* _a41_fnobj = (vader_fn_t*) l1;
                    ((vader_fn_erased_sig_1_t) _a41_fnobj->code)(_a41_fnobj->env, vader_box_i32(163u, t1));
                    t2 = (l4 + INT64_C(1));
                    l4 = (size_t) (int64_t) t2;
                    goto loop_416;
                } else {
                }
            }
        }
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 834u) {
        t0 = l0.payload.obj;
        vader_fn_t* _a42_fnobj = (vader_fn_t*) l1;
        ((vader_fn_erased_sig_1_t) _a42_fnobj->code)(_a42_fnobj->env, vader_box_i32(163u, ((vader_struct_vader_midir_InstrDeferPush_t*) t0)->f_value));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 833u) {
        { vader_gc_top = gc_frame.prev; return; }
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
        vader_obj_header_init(_a0_obj, 857u);
        _a0_obj->f_span = ((vader_struct_vader_midir_MutableBlock_t*) l0)->f_span;
        _a0_obj->f_reason = 1758u;
        _a0_obj->f_trap = false;
        l3 = (void*) _a0_obj;
        l4 = ((vader_struct_vader_midir_MutableBlock_t*) l0)->f_span;
        vader_struct_vader_midir_BasicBlock_t* _a1_obj = (vader_struct_vader_midir_BasicBlock_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_BasicBlock_t));
        vader_obj_header_init(_a1_obj, 798u);
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
    vader_obj_header_init(_a2_obj, 798u);
    _a2_obj->f_id = l1;
    _a2_obj->f_instructions = l2;
    _a2_obj->f_terminator = l5;
    _a2_obj->f_span = l3;
    t0 = (void*) _a2_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static int32_t vader_midir_fresh_tmp(void* l0, vader_string_t l1, vader_box_t l2) {
    vader_string_t l3;
    size_t l4;
    void* l5 = NULL;
    uint64_t l6;
    size_t t0;
    int64_t t1;
    int32_t t2;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[2] = { &l0, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = l1;
    l4 = vader_import_0(l3);
    l5 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(22) + l4));
    l4 = (size_t) (int64_t) INT64_C(0);
    l4 = std_core_write_string_at(l5, l4, 249u);
    l4 = std_core_write_string_at(l5, l4, l3);
    l4 = std_core_write_string_at(l5, l4, 819u);
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
    return (l0.tag == 821u || l0.tag == 822u || l0.tag == 825u || l0.tag == 826u || l0.tag == 830u || l0.tag == 836u || l0.tag == 838u || l0.tag == 846u);
}

static void vader_midir_intern_data_value_strings(vader_box_t l0, void* l1) {
    void* l2 = NULL;
    size_t l3, l4;
    void* t0 = NULL;
    vader_string_t t1;
    vader_box_t t2 = vader_box_null();
    int64_t t3;
    vader_box_t* gc_roots[2] = { &l0, &t2 };
    void** gc_raw_roots[3] = { &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 522u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_bytecode_BcValStr_t*) t0)->f_value;
        vader_bytecode_intern_string(t1, l1);
    } else {
        if (l0.tag == 523u) {
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
                    } else {
                    }
                }
            }
        } else {
            if (l0.tag == 520u) {
                t0 = l0.payload.obj;
                l2 = ((vader_struct_vader_bytecode_BcValArray_t*) t0)->f_elements;
                l3 = ((vader_array_t*) l2)->length;
                l4 = (size_t) (int64_t) INT64_C(0);
                {
                    loop_55: {
                        if ((l4 < l3)) {
                            vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
                            if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                            if ((size_t) l4 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                            t2 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
                            vader_midir_intern_data_value_strings(t2, l1);
                            t3 = (l4 + INT64_C(1));
                            l4 = (size_t) (int64_t) t3;
                            goto loop_55;
                        } else {
                        }
                    }
                }
            } else {
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
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = std_collections_get__string__i32(((vader_struct_vader_midir_ProjectCtx_t*) l0)->f_string_index, l1);
    if (l2.tag == 163u) {
        t0 = ((int32_t) l2.payload.i);
        { int32_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = ((vader_array_t*) ((vader_struct_vader_midir_ProjectCtx_t*) l0)->f_strings)->length;
    l3 = ((int32_t) (size_t) t1);
    vader_array_push((vader_array_t*) ((vader_struct_vader_midir_ProjectCtx_t*) l0)->f_strings, vader_box_string(161u, l1));
    std_collections_put__string__i32(((vader_struct_vader_midir_ProjectCtx_t*) l0)->f_string_index, l1, l3);
    { int32_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static int32_t vader_midir_intersect_dom_tree(int32_t l0, int32_t l1, void* l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    int32_t l6, l7, l8, l10, l11, l12, l13, l14, l15, l16, l17, l18, l19, l20, l21, l22, l23;
    bool l9;
    void* t0 = NULL;
    bool t1;
    void** gc_raw_roots[5] = { &l2, &l3, &l4, &l5, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(9u, 0u, 7u, 163u);
    l3 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(6u, 0u, 12u, 159u);
    l4 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 163u);
    l5 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__i32__bool_t* _a3_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
    vader_obj_header_init(_a3_obj, 310u);
    _a3_obj->f_ekeys = l3;
    _a3_obj->f_evals = l4;
    _a3_obj->f_index = l5;
    _a3_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    t0 = (void*) _a3_obj;
    vader_struct_std_collections_MutableSet__i32_t* _a4_obj = (vader_struct_std_collections_MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i32_t));
    vader_obj_header_init(_a4_obj, 387u);
    _a4_obj->f_inner = t0;
    l3 = (void*) _a4_obj;
    l6 = l0;
    {
        loop_18: {
            l7 = l6;
            l8 = -(INT32_C(1));
            if (!(l7 == l8)) {
                l4 = ((vader_struct_std_collections_MutableSet__i32_t*) l3)->f_inner;
                l10 = l6;
                t1 = std_collections_contains_key__i32__bool(l4, l10);
                l9 = !(t1);
            } else {
                l9 = false;
            }
            if (l9) {
                l11 = l6;
                std_collections_add__i32(l3, l11);
                l12 = l6;
                vader_array_t* _a5_slotarr = ((vader_array_t*) l2);
                if (_a5_slotarr->buf != NULL && _a5_slotarr->buf->header.forward != NULL) { _a5_slotarr->buf = vader_array_buf_forward(_a5_slotarr->buf); }
                if ((size_t) l12 >= _a5_slotarr->length) { vader_trap("array index out of bounds"); }
                l13 = ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l12];
                l14 = l13;
                l15 = l6;
                if (l14 == l15) {
                } else {
                    l6 = l13;
                    goto loop_18;
                }
            } else {
            }
            l16 = l1;
            {
                loop_73: {
                    l17 = l16;
                    l18 = -(INT32_C(1));
                    if (!(l17 == l18)) {
                        l5 = ((vader_struct_std_collections_MutableSet__i32_t*) l3)->f_inner;
                        l19 = l16;
                        t1 = std_collections_contains_key__i32__bool(l5, l19);
                        if (t1) {
                            { int32_t __vret = l16; vader_gc_top = gc_frame.prev; return __vret; }
                        }
                        l20 = l16;
                        vader_array_t* _a6_slotarr = ((vader_array_t*) l2);
                        if (_a6_slotarr->buf != NULL && _a6_slotarr->buf->header.forward != NULL) { _a6_slotarr->buf = vader_array_buf_forward(_a6_slotarr->buf); }
                        if ((size_t) l20 >= _a6_slotarr->length) { vader_trap("array index out of bounds"); }
                        l21 = ((int32_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l20];
                        l22 = l21;
                        l23 = l16;
                        if (l22 == l23) {
                        } else {
                            l16 = l21;
                            goto loop_73;
                        }
                    } else {
                    }
                }
            }
            { int32_t __vret = -(INT32_C(1)); vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    l16 = l1;
    {
        loop_125: {
            l17 = l16;
            l18 = -(INT32_C(1));
            if (!(l17 == l18)) {
                l5 = ((vader_struct_std_collections_MutableSet__i32_t*) l3)->f_inner;
                l19 = l16;
                t1 = std_collections_contains_key__i32__bool(l5, l19);
                if (t1) {
                    { int32_t __vret = l16; vader_gc_top = gc_frame.prev; return __vret; }
                }
                l20 = l16;
                vader_array_t* _a7_slotarr = ((vader_array_t*) l2);
                if (_a7_slotarr->buf != NULL && _a7_slotarr->buf->header.forward != NULL) { _a7_slotarr->buf = vader_array_buf_forward(_a7_slotarr->buf); }
                if ((size_t) l20 >= _a7_slotarr->length) { vader_trap("array index out of bounds"); }
                l21 = ((int32_t*) _a7_slotarr->buf->slots)[_a7_slotarr->offset + (size_t) l20];
                l22 = l21;
                l23 = l16;
                if (l22 == l23) {
                } else {
                    l16 = l21;
                    goto loop_125;
                }
            } else {
            }
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
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0 == 1893u) {
        vader_struct_vader_bytecode_SizeOfType_t* _a0_obj = (vader_struct_vader_bytecode_SizeOfType_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_SizeOfType_t));
        vader_obj_header_init(_a0_obj, 631u);
        t0 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == 1142u) {
        vader_struct_vader_bytecode_ArrayRepeat_t* _a1_obj = (vader_struct_vader_bytecode_ArrayRepeat_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_ArrayRepeat_t));
        vader_obj_header_init(_a1_obj, 501u);
        t0 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == 1135u) {
        vader_struct_vader_bytecode_ArrayPushAll_t* _a2_obj = (vader_struct_vader_bytecode_ArrayPushAll_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_ArrayPushAll_t));
        vader_obj_header_init(_a2_obj, 499u);
        t0 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == 1116u) {
        vader_struct_vader_bytecode_ArrayCopy_t* _a3_obj = (vader_struct_vader_bytecode_ArrayCopy_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_ArrayCopy_t));
        vader_obj_header_init(_a3_obj, 494u);
        t0 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == 1139u) {
        vader_struct_vader_bytecode_ArrayRemoveLast_t* _a4_obj = (vader_struct_vader_bytecode_ArrayRemoveLast_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_ArrayRemoveLast_t));
        vader_obj_header_init(_a4_obj, 500u);
        t0 = (void*) _a4_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == 1113u) {
        vader_struct_vader_bytecode_ArrayClear_t* _a5_obj = (vader_struct_vader_bytecode_ArrayClear_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_ArrayClear_t));
        vader_obj_header_init(_a5_obj, 493u);
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
    if ((l0.tag == 744u || l0.tag == 763u)) {
        return true;
    }
    if (l0.tag == 743u) {
        t0 = l0.payload.obj;
        t1 = vader_midir_is_short_circuit_op(((vader_struct_vader_lower_LoweredBinary_t*) t0)->f_op);
        return t1;
    }
    return false;
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

static bool vader_midir_loop_exit_present(void* l0, int32_t l1) {
    void* l2;
    void* l3;
    void* l4;
    size_t l5, l6;
    int32_t l7, l9;
    vader_box_t l8;
    void* t0;
    int64_t t1;
    l2 = ((vader_struct_vader_midir_FnEmitCfg_t*) l0)->f_loop_exit;
    l3 = ((vader_struct_std_collections_MutableMap__i32__i32___null_t*) l2)->f_ekeys;
    l4 = ((vader_struct_std_collections_MutableMap__i32__i32___null_t*) l2)->f_evals;
    l5 = ((vader_struct_std_collections_MutableMap__i32__i32___null_t*) l2)->f_size;
    l6 = (size_t) (int64_t) INT64_C(0);
    {
        loop_12: {
            if ((l6 >= l5)) {
            } else {
                vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
                if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                if ((size_t) l6 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                l7 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l6];
                vader_array_t* _a1_slotarr = ((vader_array_t*) l4);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l6 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                l8 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l6];
                vader_struct___Tuple_1291_t _a2_storage;
                vader_struct___Tuple_1291_t* _a3_obj = &_a2_storage;
                vader_obj_header_init(_a3_obj, 219u);
                _a3_obj->f__0 = l7;
                _a3_obj->f__1 = l8;
                t0 = (void*) _a3_obj;
                l9 = ((vader_struct___Tuple_1291_t*) t0)->f__0;
                t1 = (l6 + INT64_C(1));
                l6 = (size_t) (int64_t) t1;
                if (l9 == l1) {
                    return true;
                }
                goto loop_12;
            }
        }
    }
    return false;
}

static vader_box_t vader_midir_lowered_to_bc_value(vader_box_t l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    size_t l4, l5;
    vader_box_t l6 = vader_box_null();
    vader_string_t l7;
    uint8_t l8;
    uint64_t l9;
    void* t0 = NULL;
    vader_string_t t1;
    int64_t t2;
    int32_t t3;
    vader_box_t t4 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l0, &l6, &t4 };
    void** gc_raw_roots[4] = { &l1, &l2, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 775u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_lower_LoweredStringLit_t*) t0)->f_value;
        vader_struct_vader_bytecode_BcValStr_t* _a0_obj = (vader_struct_vader_bytecode_BcValStr_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcValStr_t));
        vader_obj_header_init(_a0_obj, 522u);
        _a0_obj->f_value = t1;
        t0 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 779u) {
        l1 = l0.payload.obj;
        vader_array_t* _a1_arr = vader_array_new(119u, 0u, 13u, 1090u);
        l2 = (void*) _a1_arr;
        l3 = ((vader_struct_vader_lower_LoweredStructLit_t*) l1)->f_fields;
        l4 = ((vader_array_t*) l3)->length;
        l5 = (size_t) (int64_t) INT64_C(0);
        {
            loop_25: {
                if ((l5 < l4)) {
                    vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
                    if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                    if ((size_t) l5 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                    t0 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l5);
                    l6 = vader_midir_lowered_to_bc_value(((vader_struct_vader_lower_LoweredStructLitField_t*) t0)->f_value);
                    vader_array_push((vader_array_t*) l2, l6);
                    t2 = (l5 + INT64_C(1));
                    l5 = (size_t) (int64_t) t2;
                    goto loop_25;
                } else {
                }
            }
        }
        t3 = vader_midir_struct_symbol_id(((vader_struct_vader_lower_LoweredStructLit_t*) l1)->f_type);
        vader_struct_vader_bytecode_BcValStruct_t* _a3_obj = (vader_struct_vader_bytecode_BcValStruct_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcValStruct_t));
        vader_obj_header_init(_a3_obj, 523u);
        _a3_obj->f_symbol_id = t3;
        _a3_obj->f_fields = l2;
        t0 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 738u) {
        l1 = l0.payload.obj;
        vader_array_t* _a4_arr = vader_array_new(119u, 0u, 13u, 1090u);
        l2 = (void*) _a4_arr;
        l3 = ((vader_struct_vader_lower_LoweredArrayLit_t*) l1)->f_elements;
        l4 = ((vader_array_t*) l3)->length;
        l5 = (size_t) (int64_t) INT64_C(0);
        {
            loop_69: {
                if ((l5 < l4)) {
                    vader_array_t* _a5_slotarr = ((vader_array_t*) l3);
                    if (_a5_slotarr->buf != NULL && _a5_slotarr->buf->header.forward != NULL) { _a5_slotarr->buf = vader_array_buf_forward(_a5_slotarr->buf); }
                    if ((size_t) l5 >= _a5_slotarr->length) { vader_trap("array index out of bounds"); }
                    t4 = vader_array_ref_load_box(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l5);
                    l6 = vader_midir_lowered_to_bc_value(t4);
                    vader_array_push((vader_array_t*) l2, l6);
                    t2 = (l5 + INT64_C(1));
                    l5 = (size_t) (int64_t) t2;
                    goto loop_69;
                } else {
                }
            }
        }
        t1 = vader_midir_array_element_name(((vader_struct_vader_lower_LoweredArrayLit_t*) l1)->f_type);
        vader_struct_vader_bytecode_BcValArray_t* _a6_obj = (vader_struct_vader_bytecode_BcValArray_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcValArray_t));
        vader_obj_header_init(_a6_obj, 520u);
        _a6_obj->f_element_type_name = t1;
        _a6_obj->f_elements = l2;
        t0 = (void*) _a6_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t4 = vader_lower_type_of(l0);
    l7 = vader_types_display_type_key(t4);
    l8 = vader_bytecode_array_kind_from_name(l7);
    l9 = vader_midir_bc_value_bits(l0, l7);
    vader_struct_vader_bytecode_BcValPrim_t* _a7_obj = (vader_struct_vader_bytecode_BcValPrim_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcValPrim_t));
    vader_obj_header_init(_a7_obj, 521u);
    _a7_obj->f_kind = l8;
    _a7_obj->f_bits = l9;
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
    vader_string_t l6, l11;
    vader_box_t l8 = vader_box_null();
    int32_t l9;
    bool l12, l13;
    int64_t t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &l8 };
    void** gc_raw_roots[7] = { &l0, &l1, &l2, &l5, &l7, &l10, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 7u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_midir_fn_metadata(l0);
    vader_array_t* _a0_arr = vader_array_new(72u, 0u, 13u, 803u);
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
                vader_obj_header_init(_a2_obj, 803u);
                _a2_obj->f_name = l6;
                _a2_obj->f_symbol = l7;
                _a2_obj->f_type = l8;
                _a2_obj->f_local = l9;
                l10 = (void*) _a2_obj;
                vader_array_push((vader_array_t*) l2, vader_ref_box(l10));
                t0 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                goto loop_11;
            } else {
            }
        }
    }
    l6 = ((vader_struct_vader_lower_LoweredFnDecl_t*) l0)->f_mangled;
    l8 = ((vader_struct_vader_lower_LoweredFnDecl_t*) l0)->f_return_type;
    l5 = ((vader_struct_vader_lower_LoweredFnDecl_t*) l0)->f_origin;
    l11 = ((vader_struct_vader_midir_FnMetadata_t*) l1)->f_extern_name;
    l12 = ((vader_struct_vader_midir_FnMetadata_t*) l1)->f_is_exported;
    l13 = ((vader_struct_vader_midir_FnMetadata_t*) l1)->f_is_extern;
    vader_struct_vader_midir_CFGExternDecl_t* _a3_obj = (vader_struct_vader_midir_CFGExternDecl_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_CFGExternDecl_t));
    vader_obj_header_init(_a3_obj, 799u);
    _a3_obj->f_mangled = l6;
    _a3_obj->f_params = l2;
    _a3_obj->f_return_type = l8;
    _a3_obj->f_origin = l5;
    _a3_obj->f_extern_name = l11;
    _a3_obj->f_is_exported = l12;
    _a3_obj->f_is_extern = l13;
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
    vader_string_t l6;
    vader_box_t l7 = vader_box_null();
    int64_t t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &l7 };
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l5, &l8, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 6u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(74u, 0u, 13u, 806u);
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
                vader_obj_header_init(_a2_obj, 806u);
                _a2_obj->f_name = l6;
                _a2_obj->f_type = l7;
                l8 = (void*) _a2_obj;
                vader_array_push((vader_array_t*) l1, vader_ref_box(l8));
                t0 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                goto loop_9;
            } else {
            }
        }
    }
    l6 = ((vader_struct_vader_lower_LoweredStructDecl_t*) l0)->f_mangled;
    l2 = ((vader_struct_vader_lower_LoweredStructDecl_t*) l0)->f_origin;
    vader_struct_vader_midir_CFGStructDecl_t* _a3_obj = (vader_struct_vader_midir_CFGStructDecl_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_CFGStructDecl_t));
    vader_obj_header_init(_a3_obj, 805u);
    _a3_obj->f_mangled = l6;
    _a3_obj->f_fields = l1;
    _a3_obj->f_origin = l2;
    t1 = (void*) _a3_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
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
    int32_t l8, l11, l18, l20, l24, l25, l26;
    bool t0;
    int64_t t1;
    size_t t2;
    void* t3 = NULL;
    void** gc_raw_roots[13] = { &l0, &l1, &l2, &l3, &l4, &l5, &l12, &l13, &l14, &l15, &l16, &l21, &t3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 13u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(9u, 0u, 7u, 163u);
    l3 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(15u, 0u, 0u, 170u);
    l4 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 163u);
    l5 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__i32__MutableSet_Any__t* _a3_obj = (vader_struct_std_collections_MutableMap__i32__MutableSet_Any__t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__MutableSet_Any__t));
    vader_obj_header_init(_a3_obj, 301u);
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
                vader_array_t* _a4_arr = vader_array_new(9u, 0u, 7u, 163u);
                l4 = (void*) _a4_arr;
                vader_array_t* _a5_slotarr = ((vader_array_t*) l1);
                if (_a5_slotarr->buf != NULL && _a5_slotarr->buf->header.forward != NULL) { _a5_slotarr->buf = vader_array_buf_forward(_a5_slotarr->buf); }
                if ((size_t) l7 >= _a5_slotarr->length) { vader_trap("array index out of bounds"); }
                l5 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l7);
                l9 = ((vader_array_t*) l5)->length;
                l10 = (size_t) (int64_t) INT64_C(0);
                {
                    loop_39: {
                        if ((l10 < l9)) {
                            vader_array_t* _a6_slotarr = ((vader_array_t*) l5);
                            if (_a6_slotarr->buf != NULL && _a6_slotarr->buf->header.forward != NULL) { _a6_slotarr->buf = vader_array_buf_forward(_a6_slotarr->buf); }
                            if ((size_t) l10 >= _a6_slotarr->length) { vader_trap("array index out of bounds"); }
                            l11 = ((int32_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l10];
                            t0 = vader_midir_dominates(l2, l8, l11);
                            if (t0) {
                                vader_array_push_i32((vader_array_t*) l4, l11);
                            } else {
                            }
                            t1 = (l10 + INT64_C(1));
                            l10 = (size_t) (int64_t) t1;
                            goto loop_39;
                        } else {
                        }
                    }
                }
                t2 = ((vader_array_t*) l4)->length;
                if (t2 == INT64_C(0)) {
                    t1 = (l7 + INT64_C(1));
                    l7 = (size_t) (int64_t) t1;
                    goto loop_20;
                }
                vader_array_t* _a7_arr = vader_array_new(9u, 0u, 7u, 163u);
                l12 = (void*) _a7_arr;
                vader_array_t* _a8_arr = vader_array_new(6u, 0u, 12u, 159u);
                l13 = (void*) _a8_arr;
                vader_array_t* _a9_arr = vader_array_new(9u, 0u, 7u, 163u);
                l14 = (void*) _a9_arr;
                vader_struct_std_collections_MutableMap__i32__bool_t* _a10_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
                vader_obj_header_init(_a10_obj, 310u);
                _a10_obj->f_ekeys = l12;
                _a10_obj->f_evals = l13;
                _a10_obj->f_index = l14;
                _a10_obj->f_mask = (size_t) (int64_t) INT64_C(0);
                _a10_obj->f_size = (size_t) (int64_t) INT64_C(0);
                _a10_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
                t3 = (void*) _a10_obj;
                vader_struct_std_collections_MutableSet__i32_t* _a11_obj = (vader_struct_std_collections_MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i32_t));
                vader_obj_header_init(_a11_obj, 387u);
                _a11_obj->f_inner = t3;
                l15 = (void*) _a11_obj;
                std_collections_add__i32(l15, l8);
                l16 = std_iter_clone__i32(l4);
                {
                    loop_100: {
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
                            t0 = std_collections_contains_key__i32__bool(((vader_struct_std_collections_MutableSet__i32_t*) l15)->f_inner, l18);
                            if (t0) {
                                goto loop_100;
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
                                loop_146: {
                                    if ((l23 < l22)) {
                                        vader_array_t* _a15_slotarr = ((vader_array_t*) l21);
                                        if (_a15_slotarr->buf != NULL && _a15_slotarr->buf->header.forward != NULL) { _a15_slotarr->buf = vader_array_buf_forward(_a15_slotarr->buf); }
                                        if ((size_t) l23 >= _a15_slotarr->length) { vader_trap("array index out of bounds"); }
                                        l24 = ((int32_t*) _a15_slotarr->buf->slots)[_a15_slotarr->offset + (size_t) l23];
                                        l25 = l24;
                                        l26 = l8;
                                        if (!(l25 == l26)) {
                                            vader_array_push_i32((vader_array_t*) l16, l24);
                                        } else {
                                        }
                                        t1 = (l23 + INT64_C(1));
                                        l23 = (size_t) (int64_t) t1;
                                        goto loop_146;
                                    } else {
                                    }
                                }
                            }
                            goto loop_100;
                        } else {
                        }
                    }
                }
                std_collections_put__i32__Any(l3, l8, vader_ref_box(l15));
                t1 = (l7 + INT64_C(1));
                l7 = (size_t) (int64_t) t1;
                goto loop_20;
            } else {
            }
        }
    }
    { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static bool vader_midir_needs_ref_cast(vader_box_t l0) {
    void* t0;
    vader_string_t t1;
    if (!(l0.tag == 928u)) {
        return false;
    }
    t0 = l0.payload.obj;
    t1 = ((vader_struct_vader_types_PrimitiveType_t*) t0)->f_name;
    return t1 != 2303u;
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
    vader_array_t* _a0_arr = vader_array_new(127u, 0u, 13u, 1157u);
    l4 = (void*) _a0_arr;
    vader_struct_vader_midir_MutableBlock_t* _a1_obj = (vader_struct_vader_midir_MutableBlock_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_MutableBlock_t));
    vader_obj_header_init(_a1_obj, 849u);
    _a1_obj->f_id = l2;
    _a1_obj->f_instructions = l4;
    _a1_obj->f_terminator = vader_box_obj(0u, NULL);
    _a1_obj->f_span = l1;
    l4 = (void*) _a1_obj;
    vader_array_push((vader_array_t*) l3, vader_ref_box(l4));
    { int32_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_midir_new_project_ctx(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l3, &l4, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 6u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 161u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(8u, 0u, 0u, 161u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 163u);
    l3 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(9u, 0u, 7u, 163u);
    l4 = (void*) _a3_arr;
    vader_struct_std_collections_MutableMap__string__i32_t* _a4_obj = (vader_struct_std_collections_MutableMap__string__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__i32_t));
    vader_obj_header_init(_a4_obj, 369u);
    _a4_obj->f_ekeys = l2;
    _a4_obj->f_evals = l3;
    _a4_obj->f_index = l4;
    _a4_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a4_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a4_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l2 = (void*) _a4_obj;
    l3 = ((vader_struct_vader_lower_LoweredProject_t*) l0)->f_const_fn_wrap;
    l4 = ((vader_struct_vader_lower_LoweredProject_t*) l0)->f_const_inline;
    vader_struct_vader_midir_ProjectCtx_t* _a5_obj = (vader_struct_vader_midir_ProjectCtx_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_ProjectCtx_t));
    vader_obj_header_init(_a5_obj, 851u);
    _a5_obj->f_strings = l1;
    _a5_obj->f_string_index = l2;
    _a5_obj->f_const_fn_wrap = l3;
    _a5_obj->f_const_inline = l4;
    t0 = (void*) _a5_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
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
    vader_array_t* _a0_arr = vader_array_new(10u, 0u, 8u, 164u);
    l0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(6u, 0u, 12u, 159u);
    l1 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 163u);
    l2 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__i64__bool_t* _a3_obj = (vader_struct_std_collections_MutableMap__i64__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i64__bool_t));
    vader_obj_header_init(_a3_obj, 320u);
    _a3_obj->f_ekeys = l0;
    _a3_obj->f_evals = l1;
    _a3_obj->f_index = l2;
    _a3_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    t0 = (void*) _a3_obj;
    vader_struct_std_collections_MutableSet__i64_t* _a4_obj = (vader_struct_std_collections_MutableSet__i64_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i64_t));
    vader_obj_header_init(_a4_obj, 388u);
    _a4_obj->f_inner = t0;
    l0 = (void*) _a4_obj;
    vader_array_t* _a5_arr = vader_array_new(10u, 0u, 8u, 164u);
    l1 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(6u, 0u, 12u, 159u);
    l2 = (void*) _a6_arr;
    vader_array_t* _a7_arr = vader_array_new(9u, 0u, 7u, 163u);
    l3 = (void*) _a7_arr;
    vader_struct_std_collections_MutableMap__i64__bool_t* _a8_obj = (vader_struct_std_collections_MutableMap__i64__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i64__bool_t));
    vader_obj_header_init(_a8_obj, 320u);
    _a8_obj->f_ekeys = l1;
    _a8_obj->f_evals = l2;
    _a8_obj->f_index = l3;
    _a8_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a8_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a8_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    t0 = (void*) _a8_obj;
    vader_struct_std_collections_MutableSet__i64_t* _a9_obj = (vader_struct_std_collections_MutableSet__i64_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i64_t));
    vader_obj_header_init(_a9_obj, 388u);
    _a9_obj->f_inner = t0;
    l1 = (void*) _a9_obj;
    vader_array_t* _a10_arr = vader_array_new(9u, 0u, 7u, 163u);
    l2 = (void*) _a10_arr;
    vader_array_t* _a11_arr = vader_array_new(6u, 0u, 12u, 159u);
    l3 = (void*) _a11_arr;
    vader_array_t* _a12_arr = vader_array_new(9u, 0u, 7u, 163u);
    l4 = (void*) _a12_arr;
    vader_struct_std_collections_MutableMap__i32__bool_t* _a13_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
    vader_obj_header_init(_a13_obj, 310u);
    _a13_obj->f_ekeys = l2;
    _a13_obj->f_evals = l3;
    _a13_obj->f_index = l4;
    _a13_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a13_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a13_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    t0 = (void*) _a13_obj;
    vader_struct_std_collections_MutableSet__i32_t* _a14_obj = (vader_struct_std_collections_MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i32_t));
    vader_obj_header_init(_a14_obj, 387u);
    _a14_obj->f_inner = t0;
    l2 = (void*) _a14_obj;
    vader_struct_vader_midir_ScheduleHints_t* _a15_obj = (vader_struct_vader_midir_ScheduleHints_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_ScheduleHints_t));
    vader_obj_header_init(_a15_obj, 852u);
    _a15_obj->f_skip_set = l0;
    _a15_obj->f_skip_first_get = l1;
    _a15_obj->f_skip_terminator_get = l2;
    t0 = (void*) _a15_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_midir_optimise_function(void* l0) {
    void* l1 = NULL;
    void* l3 = NULL;
    int32_t l2;
    bool t0;
    void* t1 = NULL;
    void** gc_raw_roots[4] = { &l0, &l1, &l3, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_midir_fold_moves(l0);
    l2 = INT32_C(0);
    {
        loop_6: {
            if ((l2 < INT32_C(8))) {
                l3 = vader_midir_die_once(l1);
                t0 = vader_midir_changed_blocks(l1, l3);
                if (!(t0)) {
                } else {
                    l1 = l3;
                    l2 = (l2 + INT32_C(1));
                    goto loop_6;
                }
            } else {
            }
        }
    }
    t1 = vader_midir_compact_locals(l1);
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
    vader_struct___lambda_env_1742_t* _a0_obj = (vader_struct___lambda_env_1742_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_1742_t));
    vader_obj_header_init(_a0_obj, 231u);
    t0 = (void*) _a0_obj;
    vader_fn_t* _a1_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
    vader_obj_header_init(_a1_closure, 130u);
    _a1_closure->code = (void*) &vader_fn_lift_1756;
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
                        } else {
                        }
                    }
                }
                t1 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t1;
                goto loop_17;
            } else {
            }
        }
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_midir_prune_block(void* l0, void* l1, size_t l2) {
    vader_box_t l3 = vader_box_null(), l4 = vader_box_null(), l12 = vader_box_null(), l14 = vader_box_null();
    void* l5 = NULL;
    void* l6 = NULL;
    void* l10 = NULL;
    void* l16 = NULL;
    void* l21 = NULL;
    void* l22 = NULL;
    void* l24 = NULL;
    size_t l7, l8, l11, l18, l19, l23;
    int32_t l9, l20;
    int64_t l13;
    bool l15, l17;
    void* t0 = NULL;
    int64_t t1;
    vader_box_t t2 = vader_box_null();
    bool t3;
    vader_box_t* gc_roots[5] = { &l3, &l4, &l12, &l14, &t2 };
    void** gc_raw_roots[10] = { &l0, &l1, &l5, &l6, &l10, &l16, &l21, &l22, &l24, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 5u, 10u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(6u, 1u, 12u, 159u);
    ((uint8_t*) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = (uint8_t) false;
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (size_t) l2);
    t0 = (void*) _a1_arr;
    vader_struct__Cell_Array_bool__t* _a2_obj = (vader_struct__Cell_Array_bool__t*) vader_gc_alloc(sizeof(vader_struct__Cell_Array_bool__t));
    vader_obj_header_init(_a2_obj, 174u);
    _a2_obj->f_value = t0;
    t0 = (void*) _a2_obj;
    l3 = vader_ref_box(t0);
    vader_struct___lambda_env_2623_t* _a3_obj = (vader_struct___lambda_env_2623_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_2623_t));
    vader_obj_header_init(_a3_obj, 244u);
    _a3_obj->f_cap_0 = l3;
    t0 = (void*) _a3_obj;
    vader_fn_t* _a4_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
    vader_obj_header_init(_a4_closure, 138u);
    _a4_closure->code = (void*) &vader_fn_lift_1780;
    _a4_closure->env = t0;
    t0 = (void*) _a4_closure;
    vader_struct__Cell_Fn_i32___void_t* _a5_obj = (vader_struct__Cell_Fn_i32___void_t*) vader_gc_alloc(sizeof(vader_struct__Cell_Fn_i32___void_t));
    vader_obj_header_init(_a5_obj, 178u);
    _a5_obj->f_value = t0;
    t0 = (void*) _a5_obj;
    l4 = vader_ref_box(t0);
    l5 = l1;
    l6 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) ((vader_struct_std_collections_MutableSet__i32_t*) l5)->f_inner)->f_ekeys;
    l7 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) ((vader_struct_std_collections_MutableSet__i32_t*) l5)->f_inner)->f_size;
    l8 = (size_t) (int64_t) INT64_C(0);
    {
        loop_22: {
            if ((l8 >= l7)) {
            } else {
                vader_array_t* _a6_slotarr = ((vader_array_t*) l6);
                if (_a6_slotarr->buf != NULL && _a6_slotarr->buf->header.forward != NULL) { _a6_slotarr->buf = vader_array_buf_forward(_a6_slotarr->buf); }
                if ((size_t) l8 >= _a6_slotarr->length) { vader_trap("array index out of bounds"); }
                l9 = ((int32_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l8];
                t1 = (l8 + INT64_C(1));
                l8 = (size_t) (int64_t) t1;
                l5 = ((vader_struct__Cell_Fn_i32___void_t*) l4.payload.obj)->f_value;
                vader_fn_t* _a7_fnobj = (vader_fn_t*) l5;
                ((vader_fn_erased_sig_1_t) _a7_fnobj->code)(_a7_fnobj->env, vader_box_i32(163u, l9));
                l10 = ((vader_struct__Cell_Array_bool__t*) l3.payload.obj)->f_value;
                t1 = ((int64_t) (int32_t) l9);
                l11 = (size_t) (int64_t) t1;
                vader_array_t* _a8_slotarr = ((vader_array_t*) l10);
                if (_a8_slotarr->buf != NULL && _a8_slotarr->buf->header.forward != NULL) { _a8_slotarr->buf = vader_array_buf_forward(_a8_slotarr->buf); }
                if ((size_t) l11 >= _a8_slotarr->length) { vader_trap("array index out of bounds"); }
                ((uint8_t*) _a8_slotarr->buf->slots)[_a8_slotarr->offset + (size_t) l11] = (uint8_t) true;
                goto loop_22;
            }
        }
    }
    l12 = ((vader_struct_vader_midir_BasicBlock_t*) l0)->f_terminator;
    vader_struct___lambda_env_2631_t* _a9_obj = (vader_struct___lambda_env_2631_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_2631_t));
    vader_obj_header_init(_a9_obj, 245u);
    _a9_obj->f_cap_0 = l4;
    _a9_obj->f_cap_1 = l3;
    t0 = (void*) _a9_obj;
    vader_fn_t* _a10_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
    vader_obj_header_init(_a10_closure, 138u);
    _a10_closure->code = (void*) &vader_fn_lift_1781;
    _a10_closure->env = t0;
    l5 = (void*) _a10_closure;
    vader_midir_for_each_read_in_terminator(l12, l5);
    l7 = ((vader_array_t*) ((vader_struct_vader_midir_BasicBlock_t*) l0)->f_instructions)->length;
    vader_array_t* _a11_arr = vader_array_new(6u, 1u, 12u, 159u);
    ((uint8_t*) _a11_arr->buf->slots)[_a11_arr->offset + 0u] = (uint8_t) false;
    t0 = (void*) _a11_arr;
    vader_array_t* _a12_arr = vader_array_repeat((vader_array_t*) t0, (size_t) l7);
    l5 = (void*) _a12_arr;
    l13 = (((int64_t) (size_t) l7) - INT64_C(1));
    {
        loop_78: {
            if ((l13 >= INT64_C(0))) {
                l6 = ((vader_struct_vader_midir_BasicBlock_t*) l0)->f_instructions;
                t1 = l13;
                l8 = (size_t) (int64_t) t1;
                vader_array_t* _a13_slotarr = ((vader_array_t*) l6);
                if (_a13_slotarr->buf != NULL && _a13_slotarr->buf->header.forward != NULL) { _a13_slotarr->buf = vader_array_buf_forward(_a13_slotarr->buf); }
                if ((size_t) l8 >= _a13_slotarr->length) { vader_trap("array index out of bounds"); }
                l12 = vader_array_ref_load_box(_a13_slotarr->buf, _a13_slotarr->offset + (size_t) l8);
                l14 = vader_midir_dst_of(l12);
                l15 = true;
                if (l14.tag == 163u) {
                    l9 = ((int32_t) l14.payload.i);
                    l10 = ((vader_struct__Cell_Fn_i32___void_t*) l4.payload.obj)->f_value;
                    vader_fn_t* _a14_fnobj = (vader_fn_t*) l10;
                    ((vader_fn_erased_sig_1_t) _a14_fnobj->code)(_a14_fnobj->env, vader_box_i32(163u, l9));
                    l16 = ((vader_struct__Cell_Array_bool__t*) l3.payload.obj)->f_value;
                    t1 = ((int64_t) (int32_t) l9);
                    l11 = (size_t) (int64_t) t1;
                    vader_array_t* _a15_slotarr = ((vader_array_t*) l16);
                    if (_a15_slotarr->buf != NULL && _a15_slotarr->buf->header.forward != NULL) { _a15_slotarr->buf = vader_array_buf_forward(_a15_slotarr->buf); }
                    if ((size_t) l11 >= _a15_slotarr->length) { vader_trap("array index out of bounds"); }
                    t2 = vader_box_bool(159u, ((uint8_t*) _a15_slotarr->buf->slots)[_a15_slotarr->offset + (size_t) l11]);
                    l15 = t2.payload.b;
                } else {
                }
                t3 = vader_midir_instruction_has_side_effect(l12);
                if (!(t3)) {
                    l17 = !(l15);
                } else {
                    l17 = false;
                }
                if (l17) {
                    t1 = l13;
                    l18 = (size_t) (int64_t) t1;
                    vader_array_t* _a16_slotarr = ((vader_array_t*) l5);
                    if (_a16_slotarr->buf != NULL && _a16_slotarr->buf->header.forward != NULL) { _a16_slotarr->buf = vader_array_buf_forward(_a16_slotarr->buf); }
                    if ((size_t) l18 >= _a16_slotarr->length) { vader_trap("array index out of bounds"); }
                    ((uint8_t*) _a16_slotarr->buf->slots)[_a16_slotarr->offset + (size_t) l18] = (uint8_t) false;
                } else {
                    t1 = l13;
                    l19 = (size_t) (int64_t) t1;
                    vader_array_t* _a17_slotarr = ((vader_array_t*) l5);
                    if (_a17_slotarr->buf != NULL && _a17_slotarr->buf->header.forward != NULL) { _a17_slotarr->buf = vader_array_buf_forward(_a17_slotarr->buf); }
                    if ((size_t) l19 >= _a17_slotarr->length) { vader_trap("array index out of bounds"); }
                    ((uint8_t*) _a17_slotarr->buf->slots)[_a17_slotarr->offset + (size_t) l19] = (uint8_t) true;
                    if (l14.tag == 163u) {
                        l20 = ((int32_t) l14.payload.i);
                        l21 = ((vader_struct__Cell_Fn_i32___void_t*) l4.payload.obj)->f_value;
                        vader_fn_t* _a18_fnobj = (vader_fn_t*) l21;
                        ((vader_fn_erased_sig_1_t) _a18_fnobj->code)(_a18_fnobj->env, vader_box_i32(163u, l20));
                        l22 = ((vader_struct__Cell_Array_bool__t*) l3.payload.obj)->f_value;
                        t1 = ((int64_t) (int32_t) l20);
                        l23 = (size_t) (int64_t) t1;
                        vader_array_t* _a19_slotarr = ((vader_array_t*) l22);
                        if (_a19_slotarr->buf != NULL && _a19_slotarr->buf->header.forward != NULL) { _a19_slotarr->buf = vader_array_buf_forward(_a19_slotarr->buf); }
                        if ((size_t) l23 >= _a19_slotarr->length) { vader_trap("array index out of bounds"); }
                        ((uint8_t*) _a19_slotarr->buf->slots)[_a19_slotarr->offset + (size_t) l23] = (uint8_t) false;
                    } else {
                    }
                    vader_struct___lambda_env_2634_t* _a20_obj = (vader_struct___lambda_env_2634_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_2634_t));
                    vader_obj_header_init(_a20_obj, 246u);
                    _a20_obj->f_cap_0 = l4;
                    _a20_obj->f_cap_1 = l3;
                    t0 = (void*) _a20_obj;
                    vader_fn_t* _a21_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
                    vader_obj_header_init(_a21_closure, 138u);
                    _a21_closure->code = (void*) &vader_fn_lift_1782;
                    _a21_closure->env = t0;
                    l24 = (void*) _a21_closure;
                    vader_midir_for_each_read_local(l12, l24);
                }
                l13 = (l13 - INT64_C(1));
                goto loop_78;
            } else {
            }
        }
    }
    vader_array_t* _a22_arr = vader_array_new(127u, 0u, 13u, 1157u);
    l6 = (void*) _a22_arr;
    l8 = (size_t) (int64_t) INT64_C(0);
    {
        loop_192: {
            if ((l8 < l7)) {
                vader_array_t* _a23_slotarr = ((vader_array_t*) l5);
                if (_a23_slotarr->buf != NULL && _a23_slotarr->buf->header.forward != NULL) { _a23_slotarr->buf = vader_array_buf_forward(_a23_slotarr->buf); }
                if ((size_t) l8 >= _a23_slotarr->length) { vader_trap("array index out of bounds"); }
                t2 = vader_box_bool(159u, ((uint8_t*) _a23_slotarr->buf->slots)[_a23_slotarr->offset + (size_t) l8]);
                t3 = t2.payload.b;
                if (t3) {
                    vader_array_t* _a24_slotarr = ((vader_array_t*) ((vader_struct_vader_midir_BasicBlock_t*) l0)->f_instructions);
                    if (_a24_slotarr->buf != NULL && _a24_slotarr->buf->header.forward != NULL) { _a24_slotarr->buf = vader_array_buf_forward(_a24_slotarr->buf); }
                    if ((size_t) l8 >= _a24_slotarr->length) { vader_trap("array index out of bounds"); }
                    l3 = vader_array_ref_load_box(_a24_slotarr->buf, _a24_slotarr->offset + (size_t) l8);
                    vader_array_push((vader_array_t*) l6, l3);
                } else {
                }
                t1 = (l8 + INT64_C(1));
                l8 = (size_t) (int64_t) t1;
                goto loop_192;
            } else {
            }
        }
    }
    { void* __vret = l6; vader_gc_top = gc_frame.prev; return __vret; }
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
    if (l1 == INT32_C(17)) {
        l2 = true;
    } else {
        l2 = l1 == INT32_C(18);
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
    void* l3 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    int32_t l4, l7, l9, l16;
    vader_box_t l5 = vader_box_null(), l6 = vader_box_null(), l12 = vader_box_null();
    uint8_t l8;
    vader_string_t l13, l14;
    bool l15;
    void* t0 = NULL;
    vader_box_t* gc_roots[4] = { &l0, &l5, &l6, &l12 };
    void** gc_raw_roots[6] = { &l1, &l2, &l3, &l10, &l11, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 6u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 831u) {
        l2 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrConst_t*) l2)->f_span;
        l4 = ((vader_struct_vader_midir_InstrConst_t*) l2)->f_dst;
        l4 = vader_midir_remap_local(l1, l4);
        l5 = ((vader_struct_vader_midir_InstrConst_t*) l2)->f_value;
        l6 = ((vader_struct_vader_midir_InstrConst_t*) l2)->f_type;
        vader_struct_vader_midir_InstrConst_t* _a0_obj = (vader_struct_vader_midir_InstrConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrConst_t));
        vader_obj_header_init(_a0_obj, 831u);
        _a0_obj->f_span = l3;
        _a0_obj->f_dst = l4;
        _a0_obj->f_value = l5;
        _a0_obj->f_type = l6;
        t0 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 840u) {
        l2 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrMove_t*) l2)->f_span;
        l4 = ((vader_struct_vader_midir_InstrMove_t*) l2)->f_dst;
        l4 = vader_midir_remap_local(l1, l4);
        l7 = ((vader_struct_vader_midir_InstrMove_t*) l2)->f_src;
        l7 = vader_midir_remap_local(l1, l7);
        vader_struct_vader_midir_InstrMove_t* _a1_obj = (vader_struct_vader_midir_InstrMove_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrMove_t));
        vader_obj_header_init(_a1_obj, 840u);
        _a1_obj->f_span = l3;
        _a1_obj->f_dst = l4;
        _a1_obj->f_src = l7;
        t0 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 824u) {
        l2 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrBinOp_t*) l2)->f_span;
        l4 = ((vader_struct_vader_midir_InstrBinOp_t*) l2)->f_dst;
        l4 = vader_midir_remap_local(l1, l4);
        l8 = ((vader_struct_vader_midir_InstrBinOp_t*) l2)->f_op;
        l7 = ((vader_struct_vader_midir_InstrBinOp_t*) l2)->f_lhs;
        l7 = vader_midir_remap_local(l1, l7);
        l9 = ((vader_struct_vader_midir_InstrBinOp_t*) l2)->f_rhs;
        l9 = vader_midir_remap_local(l1, l9);
        l5 = ((vader_struct_vader_midir_InstrBinOp_t*) l2)->f_type;
        vader_struct_vader_midir_InstrBinOp_t* _a2_obj = (vader_struct_vader_midir_InstrBinOp_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrBinOp_t));
        vader_obj_header_init(_a2_obj, 824u);
        _a2_obj->f_span = l3;
        _a2_obj->f_dst = l4;
        _a2_obj->f_op = l8;
        _a2_obj->f_lhs = l7;
        _a2_obj->f_rhs = l9;
        _a2_obj->f_type = l5;
        t0 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 845u) {
        l2 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrUnOp_t*) l2)->f_span;
        l4 = ((vader_struct_vader_midir_InstrUnOp_t*) l2)->f_dst;
        l4 = vader_midir_remap_local(l1, l4);
        l8 = ((vader_struct_vader_midir_InstrUnOp_t*) l2)->f_op;
        l7 = ((vader_struct_vader_midir_InstrUnOp_t*) l2)->f_operand;
        l7 = vader_midir_remap_local(l1, l7);
        l5 = ((vader_struct_vader_midir_InstrUnOp_t*) l2)->f_type;
        vader_struct_vader_midir_InstrUnOp_t* _a3_obj = (vader_struct_vader_midir_InstrUnOp_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrUnOp_t));
        vader_obj_header_init(_a3_obj, 845u);
        _a3_obj->f_span = l3;
        _a3_obj->f_dst = l4;
        _a3_obj->f_op = l8;
        _a3_obj->f_operand = l7;
        _a3_obj->f_type = l5;
        t0 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 825u) {
        l2 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrCall_t*) l2)->f_span;
        l5 = ((vader_struct_vader_midir_InstrCall_t*) l2)->f_dst;
        l5 = vader_midir_remap_local_opt(l1, l5);
        l10 = ((vader_struct_vader_midir_InstrCall_t*) l2)->f_callee;
        l11 = ((vader_struct_vader_midir_InstrCall_t*) l2)->f_args;
        l11 = vader_midir_remap_locals(l1, l11);
        l6 = ((vader_struct_vader_midir_InstrCall_t*) l2)->f_type;
        vader_struct_vader_midir_InstrCall_t* _a4_obj = (vader_struct_vader_midir_InstrCall_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrCall_t));
        vader_obj_header_init(_a4_obj, 825u);
        _a4_obj->f_span = l3;
        _a4_obj->f_dst = l5;
        _a4_obj->f_callee = l10;
        _a4_obj->f_args = l11;
        _a4_obj->f_type = l6;
        t0 = (void*) _a4_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 826u) {
        l2 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrCallIndirect_t*) l2)->f_span;
        l5 = ((vader_struct_vader_midir_InstrCallIndirect_t*) l2)->f_dst;
        l5 = vader_midir_remap_local_opt(l1, l5);
        l4 = ((vader_struct_vader_midir_InstrCallIndirect_t*) l2)->f_callee;
        l4 = vader_midir_remap_local(l1, l4);
        l10 = ((vader_struct_vader_midir_InstrCallIndirect_t*) l2)->f_args;
        l10 = vader_midir_remap_locals(l1, l10);
        l6 = ((vader_struct_vader_midir_InstrCallIndirect_t*) l2)->f_fn_type;
        l12 = ((vader_struct_vader_midir_InstrCallIndirect_t*) l2)->f_type;
        vader_struct_vader_midir_InstrCallIndirect_t* _a5_obj = (vader_struct_vader_midir_InstrCallIndirect_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrCallIndirect_t));
        vader_obj_header_init(_a5_obj, 826u);
        _a5_obj->f_span = l3;
        _a5_obj->f_dst = l5;
        _a5_obj->f_callee = l4;
        _a5_obj->f_args = l10;
        _a5_obj->f_fn_type = l6;
        _a5_obj->f_type = l12;
        t0 = (void*) _a5_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 846u) {
        l2 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrVirtualCall_t*) l2)->f_span;
        l5 = ((vader_struct_vader_midir_InstrVirtualCall_t*) l2)->f_dst;
        l5 = vader_midir_remap_local_opt(l1, l5);
        l13 = ((vader_struct_vader_midir_InstrVirtualCall_t*) l2)->f_trait_name;
        l14 = ((vader_struct_vader_midir_InstrVirtualCall_t*) l2)->f_method;
        l4 = ((vader_struct_vader_midir_InstrVirtualCall_t*) l2)->f_receiver;
        l4 = vader_midir_remap_local(l1, l4);
        l10 = ((vader_struct_vader_midir_InstrVirtualCall_t*) l2)->f_args;
        l10 = vader_midir_remap_locals(l1, l10);
        l6 = ((vader_struct_vader_midir_InstrVirtualCall_t*) l2)->f_type;
        vader_struct_vader_midir_InstrVirtualCall_t* _a6_obj = (vader_struct_vader_midir_InstrVirtualCall_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrVirtualCall_t));
        vader_obj_header_init(_a6_obj, 846u);
        _a6_obj->f_span = l3;
        _a6_obj->f_dst = l5;
        _a6_obj->f_trait_name = l13;
        _a6_obj->f_method = l14;
        _a6_obj->f_receiver = l4;
        _a6_obj->f_args = l10;
        _a6_obj->f_type = l6;
        t0 = (void*) _a6_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 837u) {
        l2 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrFnRef_t*) l2)->f_span;
        l4 = ((vader_struct_vader_midir_InstrFnRef_t*) l2)->f_dst;
        l4 = vader_midir_remap_local(l1, l4);
        l10 = ((vader_struct_vader_midir_InstrFnRef_t*) l2)->f_fn_symbol;
        l5 = ((vader_struct_vader_midir_InstrFnRef_t*) l2)->f_type;
        vader_struct_vader_midir_InstrFnRef_t* _a7_obj = (vader_struct_vader_midir_InstrFnRef_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrFnRef_t));
        vader_obj_header_init(_a7_obj, 837u);
        _a7_obj->f_span = l3;
        _a7_obj->f_dst = l4;
        _a7_obj->f_fn_symbol = l10;
        _a7_obj->f_type = l5;
        t0 = (void*) _a7_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 835u) {
        l2 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrFieldGet_t*) l2)->f_span;
        l4 = ((vader_struct_vader_midir_InstrFieldGet_t*) l2)->f_dst;
        l4 = vader_midir_remap_local(l1, l4);
        l7 = ((vader_struct_vader_midir_InstrFieldGet_t*) l2)->f_target;
        l7 = vader_midir_remap_local(l1, l7);
        l13 = ((vader_struct_vader_midir_InstrFieldGet_t*) l2)->f_field;
        l5 = ((vader_struct_vader_midir_InstrFieldGet_t*) l2)->f_type;
        vader_struct_vader_midir_InstrFieldGet_t* _a8_obj = (vader_struct_vader_midir_InstrFieldGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrFieldGet_t));
        vader_obj_header_init(_a8_obj, 835u);
        _a8_obj->f_span = l3;
        _a8_obj->f_dst = l4;
        _a8_obj->f_target = l7;
        _a8_obj->f_field = l13;
        _a8_obj->f_type = l5;
        t0 = (void*) _a8_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 836u) {
        l2 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrFieldSet_t*) l2)->f_span;
        l4 = ((vader_struct_vader_midir_InstrFieldSet_t*) l2)->f_target;
        l4 = vader_midir_remap_local(l1, l4);
        l13 = ((vader_struct_vader_midir_InstrFieldSet_t*) l2)->f_field;
        l7 = ((vader_struct_vader_midir_InstrFieldSet_t*) l2)->f_value;
        l7 = vader_midir_remap_local(l1, l7);
        l15 = ((vader_struct_vader_midir_InstrFieldSet_t*) l2)->f_barrierless;
        vader_struct_vader_midir_InstrFieldSet_t* _a9_obj = (vader_struct_vader_midir_InstrFieldSet_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrFieldSet_t));
        vader_obj_header_init(_a9_obj, 836u);
        _a9_obj->f_span = l3;
        _a9_obj->f_target = l4;
        _a9_obj->f_field = l13;
        _a9_obj->f_value = l7;
        _a9_obj->f_barrierless = l15;
        t0 = (void*) _a9_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 818u) {
        l2 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrArrayGet_t*) l2)->f_span;
        l4 = ((vader_struct_vader_midir_InstrArrayGet_t*) l2)->f_dst;
        l4 = vader_midir_remap_local(l1, l4);
        l7 = ((vader_struct_vader_midir_InstrArrayGet_t*) l2)->f_target;
        l7 = vader_midir_remap_local(l1, l7);
        l9 = ((vader_struct_vader_midir_InstrArrayGet_t*) l2)->f_index;
        l9 = vader_midir_remap_local(l1, l9);
        l5 = ((vader_struct_vader_midir_InstrArrayGet_t*) l2)->f_type;
        l15 = ((vader_struct_vader_midir_InstrArrayGet_t*) l2)->f_bounds_safe;
        vader_struct_vader_midir_InstrArrayGet_t* _a10_obj = (vader_struct_vader_midir_InstrArrayGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrArrayGet_t));
        vader_obj_header_init(_a10_obj, 818u);
        _a10_obj->f_span = l3;
        _a10_obj->f_dst = l4;
        _a10_obj->f_target = l7;
        _a10_obj->f_index = l9;
        _a10_obj->f_type = l5;
        _a10_obj->f_bounds_safe = l15;
        t0 = (void*) _a10_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 822u) {
        l2 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrArraySet_t*) l2)->f_span;
        l4 = ((vader_struct_vader_midir_InstrArraySet_t*) l2)->f_target;
        l4 = vader_midir_remap_local(l1, l4);
        l7 = ((vader_struct_vader_midir_InstrArraySet_t*) l2)->f_index;
        l7 = vader_midir_remap_local(l1, l7);
        l9 = ((vader_struct_vader_midir_InstrArraySet_t*) l2)->f_value;
        l9 = vader_midir_remap_local(l1, l9);
        l15 = ((vader_struct_vader_midir_InstrArraySet_t*) l2)->f_bounds_safe;
        vader_struct_vader_midir_InstrArraySet_t* _a11_obj = (vader_struct_vader_midir_InstrArraySet_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrArraySet_t));
        vader_obj_header_init(_a11_obj, 822u);
        _a11_obj->f_span = l3;
        _a11_obj->f_target = l4;
        _a11_obj->f_index = l7;
        _a11_obj->f_value = l9;
        _a11_obj->f_bounds_safe = l15;
        t0 = (void*) _a11_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 819u) {
        l2 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrArrayLen_t*) l2)->f_span;
        l4 = ((vader_struct_vader_midir_InstrArrayLen_t*) l2)->f_dst;
        l4 = vader_midir_remap_local(l1, l4);
        l7 = ((vader_struct_vader_midir_InstrArrayLen_t*) l2)->f_target;
        l7 = vader_midir_remap_local(l1, l7);
        l15 = ((vader_struct_vader_midir_InstrArrayLen_t*) l2)->f_resolve_buf;
        vader_struct_vader_midir_InstrArrayLen_t* _a12_obj = (vader_struct_vader_midir_InstrArrayLen_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrArrayLen_t));
        vader_obj_header_init(_a12_obj, 819u);
        _a12_obj->f_span = l3;
        _a12_obj->f_dst = l4;
        _a12_obj->f_target = l7;
        _a12_obj->f_resolve_buf = l15;
        t0 = (void*) _a12_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 821u) {
        l2 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrArrayPush_t*) l2)->f_span;
        l4 = ((vader_struct_vader_midir_InstrArrayPush_t*) l2)->f_target;
        l4 = vader_midir_remap_local(l1, l4);
        l7 = ((vader_struct_vader_midir_InstrArrayPush_t*) l2)->f_value;
        l7 = vader_midir_remap_local(l1, l7);
        vader_struct_vader_midir_InstrArrayPush_t* _a13_obj = (vader_struct_vader_midir_InstrArrayPush_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrArrayPush_t));
        vader_obj_header_init(_a13_obj, 821u);
        _a13_obj->f_span = l3;
        _a13_obj->f_target = l4;
        _a13_obj->f_value = l7;
        t0 = (void*) _a13_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 823u) {
        l2 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrArraySlice_t*) l2)->f_span;
        l4 = ((vader_struct_vader_midir_InstrArraySlice_t*) l2)->f_dst;
        l4 = vader_midir_remap_local(l1, l4);
        l5 = ((vader_struct_vader_midir_InstrArraySlice_t*) l2)->f_type;
        l7 = ((vader_struct_vader_midir_InstrArraySlice_t*) l2)->f_target;
        l7 = vader_midir_remap_local(l1, l7);
        l9 = ((vader_struct_vader_midir_InstrArraySlice_t*) l2)->f_lo;
        l9 = vader_midir_remap_local(l1, l9);
        l16 = ((vader_struct_vader_midir_InstrArraySlice_t*) l2)->f_hi;
        l16 = vader_midir_remap_local(l1, l16);
        vader_struct_vader_midir_InstrArraySlice_t* _a14_obj = (vader_struct_vader_midir_InstrArraySlice_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrArraySlice_t));
        vader_obj_header_init(_a14_obj, 823u);
        _a14_obj->f_span = l3;
        _a14_obj->f_dst = l4;
        _a14_obj->f_type = l5;
        _a14_obj->f_target = l7;
        _a14_obj->f_lo = l9;
        _a14_obj->f_hi = l16;
        t0 = (void*) _a14_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 841u) {
        l2 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrStringSlice_t*) l2)->f_span;
        l4 = ((vader_struct_vader_midir_InstrStringSlice_t*) l2)->f_dst;
        l4 = vader_midir_remap_local(l1, l4);
        l5 = ((vader_struct_vader_midir_InstrStringSlice_t*) l2)->f_type;
        l7 = ((vader_struct_vader_midir_InstrStringSlice_t*) l2)->f_target;
        l7 = vader_midir_remap_local(l1, l7);
        l9 = ((vader_struct_vader_midir_InstrStringSlice_t*) l2)->f_lo;
        l9 = vader_midir_remap_local(l1, l9);
        l16 = ((vader_struct_vader_midir_InstrStringSlice_t*) l2)->f_hi;
        l16 = vader_midir_remap_local(l1, l16);
        vader_struct_vader_midir_InstrStringSlice_t* _a15_obj = (vader_struct_vader_midir_InstrStringSlice_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrStringSlice_t));
        vader_obj_header_init(_a15_obj, 841u);
        _a15_obj->f_span = l3;
        _a15_obj->f_dst = l4;
        _a15_obj->f_type = l5;
        _a15_obj->f_target = l7;
        _a15_obj->f_lo = l9;
        _a15_obj->f_hi = l16;
        t0 = (void*) _a15_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 842u) {
        l2 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrStructNew_t*) l2)->f_span;
        l4 = ((vader_struct_vader_midir_InstrStructNew_t*) l2)->f_dst;
        l4 = vader_midir_remap_local(l1, l4);
        l5 = ((vader_struct_vader_midir_InstrStructNew_t*) l2)->f_type;
        l10 = ((vader_struct_vader_midir_InstrStructNew_t*) l2)->f_fields;
        l10 = vader_midir_remap_locals(l1, l10);
        l15 = ((vader_struct_vader_midir_InstrStructNew_t*) l2)->f_stack;
        vader_struct_vader_midir_InstrStructNew_t* _a16_obj = (vader_struct_vader_midir_InstrStructNew_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrStructNew_t));
        vader_obj_header_init(_a16_obj, 842u);
        _a16_obj->f_span = l3;
        _a16_obj->f_dst = l4;
        _a16_obj->f_type = l5;
        _a16_obj->f_fields = l10;
        _a16_obj->f_stack = l15;
        t0 = (void*) _a16_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 820u) {
        l2 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrArrayNew_t*) l2)->f_span;
        l4 = ((vader_struct_vader_midir_InstrArrayNew_t*) l2)->f_dst;
        l4 = vader_midir_remap_local(l1, l4);
        l5 = ((vader_struct_vader_midir_InstrArrayNew_t*) l2)->f_type;
        l7 = ((vader_struct_vader_midir_InstrArrayNew_t*) l2)->f_length;
        l10 = ((vader_struct_vader_midir_InstrArrayNew_t*) l2)->f_elements;
        l10 = vader_midir_remap_locals(l1, l10);
        l15 = ((vader_struct_vader_midir_InstrArrayNew_t*) l2)->f_stack;
        vader_struct_vader_midir_InstrArrayNew_t* _a17_obj = (vader_struct_vader_midir_InstrArrayNew_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrArrayNew_t));
        vader_obj_header_init(_a17_obj, 820u);
        _a17_obj->f_span = l3;
        _a17_obj->f_dst = l4;
        _a17_obj->f_type = l5;
        _a17_obj->f_length = l7;
        _a17_obj->f_elements = l10;
        _a17_obj->f_stack = l15;
        t0 = (void*) _a17_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 832u) {
        l2 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrDataConst_t*) l2)->f_span;
        l4 = ((vader_struct_vader_midir_InstrDataConst_t*) l2)->f_dst;
        l4 = vader_midir_remap_local(l1, l4);
        l5 = ((vader_struct_vader_midir_InstrDataConst_t*) l2)->f_type;
        l7 = ((vader_struct_vader_midir_InstrDataConst_t*) l2)->f_pool_index;
        vader_struct_vader_midir_InstrDataConst_t* _a18_obj = (vader_struct_vader_midir_InstrDataConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrDataConst_t));
        vader_obj_header_init(_a18_obj, 832u);
        _a18_obj->f_span = l3;
        _a18_obj->f_dst = l4;
        _a18_obj->f_type = l5;
        _a18_obj->f_pool_index = l7;
        t0 = (void*) _a18_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 843u) {
        l2 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrTypeCheck_t*) l2)->f_span;
        l4 = ((vader_struct_vader_midir_InstrTypeCheck_t*) l2)->f_dst;
        l4 = vader_midir_remap_local(l1, l4);
        l7 = ((vader_struct_vader_midir_InstrTypeCheck_t*) l2)->f_value;
        l7 = vader_midir_remap_local(l1, l7);
        l5 = ((vader_struct_vader_midir_InstrTypeCheck_t*) l2)->f_check_type;
        vader_struct_vader_midir_InstrTypeCheck_t* _a19_obj = (vader_struct_vader_midir_InstrTypeCheck_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrTypeCheck_t));
        vader_obj_header_init(_a19_obj, 843u);
        _a19_obj->f_span = l3;
        _a19_obj->f_dst = l4;
        _a19_obj->f_value = l7;
        _a19_obj->f_check_type = l5;
        t0 = (void*) _a19_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 844u) {
        l2 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrTypeConst_t*) l2)->f_span;
        l4 = ((vader_struct_vader_midir_InstrTypeConst_t*) l2)->f_dst;
        l4 = vader_midir_remap_local(l1, l4);
        l5 = ((vader_struct_vader_midir_InstrTypeConst_t*) l2)->f_type;
        l6 = ((vader_struct_vader_midir_InstrTypeConst_t*) l2)->f_value_type;
        vader_struct_vader_midir_InstrTypeConst_t* _a20_obj = (vader_struct_vader_midir_InstrTypeConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrTypeConst_t));
        vader_obj_header_init(_a20_obj, 844u);
        _a20_obj->f_span = l3;
        _a20_obj->f_dst = l4;
        _a20_obj->f_type = l5;
        _a20_obj->f_value_type = l6;
        t0 = (void*) _a20_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 827u) {
        l2 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrCast_t*) l2)->f_span;
        l4 = ((vader_struct_vader_midir_InstrCast_t*) l2)->f_dst;
        l4 = vader_midir_remap_local(l1, l4);
        l7 = ((vader_struct_vader_midir_InstrCast_t*) l2)->f_value;
        l7 = vader_midir_remap_local(l1, l7);
        l5 = ((vader_struct_vader_midir_InstrCast_t*) l2)->f_type;
        vader_struct_vader_midir_InstrCast_t* _a21_obj = (vader_struct_vader_midir_InstrCast_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrCast_t));
        vader_obj_header_init(_a21_obj, 827u);
        _a21_obj->f_span = l3;
        _a21_obj->f_dst = l4;
        _a21_obj->f_value = l7;
        _a21_obj->f_type = l5;
        t0 = (void*) _a21_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 829u) {
        l2 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrCellNew_t*) l2)->f_span;
        l4 = ((vader_struct_vader_midir_InstrCellNew_t*) l2)->f_dst;
        l4 = vader_midir_remap_local(l1, l4);
        l7 = ((vader_struct_vader_midir_InstrCellNew_t*) l2)->f_value;
        l7 = vader_midir_remap_local(l1, l7);
        l5 = ((vader_struct_vader_midir_InstrCellNew_t*) l2)->f_value_type;
        vader_struct_vader_midir_InstrCellNew_t* _a22_obj = (vader_struct_vader_midir_InstrCellNew_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrCellNew_t));
        vader_obj_header_init(_a22_obj, 829u);
        _a22_obj->f_span = l3;
        _a22_obj->f_dst = l4;
        _a22_obj->f_value = l7;
        _a22_obj->f_value_type = l5;
        t0 = (void*) _a22_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 828u) {
        l2 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrCellGet_t*) l2)->f_span;
        l4 = ((vader_struct_vader_midir_InstrCellGet_t*) l2)->f_dst;
        l4 = vader_midir_remap_local(l1, l4);
        l7 = ((vader_struct_vader_midir_InstrCellGet_t*) l2)->f_cell;
        l7 = vader_midir_remap_local(l1, l7);
        l5 = ((vader_struct_vader_midir_InstrCellGet_t*) l2)->f_value_type;
        vader_struct_vader_midir_InstrCellGet_t* _a23_obj = (vader_struct_vader_midir_InstrCellGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrCellGet_t));
        vader_obj_header_init(_a23_obj, 828u);
        _a23_obj->f_span = l3;
        _a23_obj->f_dst = l4;
        _a23_obj->f_cell = l7;
        _a23_obj->f_value_type = l5;
        t0 = (void*) _a23_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 830u) {
        l2 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrCellSet_t*) l2)->f_span;
        l4 = ((vader_struct_vader_midir_InstrCellSet_t*) l2)->f_cell;
        l4 = vader_midir_remap_local(l1, l4);
        l7 = ((vader_struct_vader_midir_InstrCellSet_t*) l2)->f_value;
        l7 = vader_midir_remap_local(l1, l7);
        l5 = ((vader_struct_vader_midir_InstrCellSet_t*) l2)->f_value_type;
        vader_struct_vader_midir_InstrCellSet_t* _a24_obj = (vader_struct_vader_midir_InstrCellSet_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrCellSet_t));
        vader_obj_header_init(_a24_obj, 830u);
        _a24_obj->f_span = l3;
        _a24_obj->f_cell = l4;
        _a24_obj->f_value = l7;
        _a24_obj->f_value_type = l5;
        t0 = (void*) _a24_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 839u) {
        l2 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrMakeClosure_t*) l2)->f_span;
        l4 = ((vader_struct_vader_midir_InstrMakeClosure_t*) l2)->f_dst;
        l4 = vader_midir_remap_local(l1, l4);
        l10 = ((vader_struct_vader_midir_InstrMakeClosure_t*) l2)->f_fn_symbol;
        l7 = ((vader_struct_vader_midir_InstrMakeClosure_t*) l2)->f_env;
        l7 = vader_midir_remap_local(l1, l7);
        l5 = ((vader_struct_vader_midir_InstrMakeClosure_t*) l2)->f_env_type;
        l6 = ((vader_struct_vader_midir_InstrMakeClosure_t*) l2)->f_type;
        vader_struct_vader_midir_InstrMakeClosure_t* _a25_obj = (vader_struct_vader_midir_InstrMakeClosure_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrMakeClosure_t));
        vader_obj_header_init(_a25_obj, 839u);
        _a25_obj->f_span = l3;
        _a25_obj->f_dst = l4;
        _a25_obj->f_fn_symbol = l10;
        _a25_obj->f_env = l7;
        _a25_obj->f_env_type = l5;
        _a25_obj->f_type = l6;
        t0 = (void*) _a25_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 838u) {
        l2 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrIntrinsic_t*) l2)->f_span;
        l5 = ((vader_struct_vader_midir_InstrIntrinsic_t*) l2)->f_dst;
        l5 = vader_midir_remap_local_opt(l1, l5);
        l13 = ((vader_struct_vader_midir_InstrIntrinsic_t*) l2)->f_name;
        l2 = ((vader_struct_vader_midir_InstrIntrinsic_t*) l2)->f_args;
        l2 = vader_midir_remap_locals(l1, l2);
        vader_struct_vader_midir_InstrIntrinsic_t* _a26_obj = (vader_struct_vader_midir_InstrIntrinsic_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrIntrinsic_t));
        vader_obj_header_init(_a26_obj, 838u);
        _a26_obj->f_span = l3;
        _a26_obj->f_dst = l5;
        _a26_obj->f_name = l13;
        _a26_obj->f_args = l2;
        t0 = (void*) _a26_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 834u) {
        l2 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrDeferPush_t*) l2)->f_span;
        l4 = ((vader_struct_vader_midir_InstrDeferPush_t*) l2)->f_value;
        l4 = vader_midir_remap_local(l1, l4);
        vader_struct_vader_midir_InstrDeferPush_t* _a27_obj = (vader_struct_vader_midir_InstrDeferPush_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrDeferPush_t));
        vader_obj_header_init(_a27_obj, 834u);
        _a27_obj->f_span = l3;
        _a27_obj->f_value = l4;
        t0 = (void*) _a27_obj;
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
    if (l1.tag == 163u) {
        l2 = ((int32_t) l1.payload.i);
        t1 = vader_midir_remap_local(l0, l2);
        t0 = vader_box_i32(163u, t1);
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
    vader_array_t* _a0_arr = vader_array_new(9u, 0u, 7u, 163u);
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
                l6 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l5];
                l7 = vader_midir_remap_local(l0, l6);
                vader_array_push_i32((vader_array_t*) l2, l7);
                t0 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t0;
                goto loop_9;
            } else {
            }
        }
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_box_t vader_midir_remap_terminator(vader_box_t l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    int32_t l4, l5, l6;
    vader_box_t l7 = vader_box_null();
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l0, &l7, &t1 };
    void** gc_raw_roots[4] = { &l1, &l2, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 854u) {
        t0 = l0.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 857u) {
        t0 = l0.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 855u) {
        l2 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_TermCondBranch_t*) l2)->f_span;
        l4 = ((vader_struct_vader_midir_TermCondBranch_t*) l2)->f_cond;
        l4 = vader_midir_remap_local(l1, l4);
        l5 = ((vader_struct_vader_midir_TermCondBranch_t*) l2)->f_then_block;
        l6 = ((vader_struct_vader_midir_TermCondBranch_t*) l2)->f_else_block;
        vader_struct_vader_midir_TermCondBranch_t* _a0_obj = (vader_struct_vader_midir_TermCondBranch_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_TermCondBranch_t));
        vader_obj_header_init(_a0_obj, 855u);
        _a0_obj->f_span = l3;
        _a0_obj->f_cond = l4;
        _a0_obj->f_then_block = l5;
        _a0_obj->f_else_block = l6;
        t0 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 856u) {
        l2 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_TermReturn_t*) l2)->f_span;
        l7 = ((vader_struct_vader_midir_TermReturn_t*) l2)->f_value;
        l7 = vader_midir_remap_local_opt(l1, l7);
        vader_struct_vader_midir_TermReturn_t* _a1_obj = (vader_struct_vader_midir_TermReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_TermReturn_t));
        vader_obj_header_init(_a1_obj, 856u);
        _a1_obj->f_span = l3;
        _a1_obj->f_value = l7;
        t0 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = l0;
    { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void vader_midir_reserve_cfg_extern(void* l0, void* l1) {
    void* l2 = NULL;
    void* l5 = NULL;
    vader_box_t l3 = vader_box_null();
    int32_t l4, l9;
    vader_string_t l6, l7;
    bool l8;
    size_t t0;
    vader_box_t* gc_roots[1] = { &l3 };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_midir_CFGExternDecl_t*) l0)->f_params;
    l3 = ((vader_struct_vader_midir_CFGExternDecl_t*) l0)->f_return_type;
    l2 = vader_midir_build_cfg_signature(l2, l3, l1);
    t0 = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_imports)->length;
    l4 = ((int32_t) (size_t) t0);
    l5 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_imports;
    l6 = ((vader_struct_vader_midir_CFGExternDecl_t*) l0)->f_extern_name;
    l7 = ((vader_struct_vader_midir_CFGExternDecl_t*) l0)->f_mangled;
    l8 = ((vader_struct_vader_midir_CFGExternDecl_t*) l0)->f_is_extern;
    vader_struct_vader_bytecode_BcImport_t* _a0_obj = (vader_struct_vader_bytecode_BcImport_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcImport_t));
    vader_obj_header_init(_a0_obj, 510u);
    _a0_obj->f_extern_name = l6;
    _a0_obj->f_mangled_name = l7;
    _a0_obj->f_signature = l2;
    _a0_obj->f_is_extern = l8;
    l2 = (void*) _a0_obj;
    vader_array_push((vader_array_t*) l5, vader_ref_box(l2));
    if (((vader_struct_vader_comptime_MonoEntry_t*) ((vader_struct_vader_midir_CFGExternDecl_t*) l0)->f_origin)->f_symbol.tag == 893u) {
        l2 = ((vader_struct_vader_comptime_MonoEntry_t*) ((vader_struct_vader_midir_CFGExternDecl_t*) l0)->f_origin)->f_symbol.payload.obj;
        l5 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_import_index_by_symbol_id;
        l9 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l2)->f_id;
        std_collections_put__i32__i32(l5, l9, l4);
    } else {
    }
    l2 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_import_index_by_mangle;
    l6 = ((vader_struct_vader_midir_CFGExternDecl_t*) l0)->f_mangled;
    std_collections_put__string__i32(l2, l6, l4);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_midir_reserve_cfg_function(void* l0, void* l1) {
    void* l2 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    vader_box_t l3 = vader_box_null();
    int32_t l4, l12;
    vader_string_t l10;
    bool l11;
    size_t t0;
    vader_box_t* gc_roots[1] = { &l3 };
    void** gc_raw_roots[8] = { &l0, &l1, &l2, &l5, &l6, &l7, &l8, &l9 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 8u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_params;
    l3 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_return_type;
    l2 = vader_midir_build_cfg_signature(l2, l3, l1);
    t0 = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_functions)->length;
    l4 = ((int32_t) (size_t) t0);
    vader_array_t* _a0_arr = vader_array_new(116u, 0u, 13u, 1078u);
    l5 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(120u, 0u, 13u, 1102u);
    l6 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 163u);
    l7 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(39u, 0u, 13u, 511u);
    l8 = (void*) _a3_arr;
    l9 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_functions;
    l10 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_mangled;
    l11 = ((vader_struct_vader_comptime_MonoEntry_t*) ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_origin)->f_is_main;
    vader_struct_vader_bytecode_BcFunction_t* _a4_obj = (vader_struct_vader_bytecode_BcFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcFunction_t));
    vader_obj_header_init(_a4_obj, 509u);
    _a4_obj->f_name = l10;
    _a4_obj->f_is_main = l11;
    _a4_obj->f_signature = l2;
    _a4_obj->f_locals = l8;
    _a4_obj->f_body = l5;
    _a4_obj->f_debug = l6;
    _a4_obj->f_jump_table = l7;
    l2 = (void*) _a4_obj;
    vader_array_push((vader_array_t*) l9, vader_ref_box(l2));
    if (((vader_struct_vader_comptime_MonoEntry_t*) ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_origin)->f_symbol.tag == 893u) {
        l2 = ((vader_struct_vader_comptime_MonoEntry_t*) ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_origin)->f_symbol.payload.obj;
        l5 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_function_index_by_symbol_id;
        l12 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l2)->f_id;
        std_collections_put__i32__i32(l5, l12, l4);
    } else {
    }
    l2 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_function_index_by_mangle;
    l10 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_mangled;
    std_collections_put__string__i32(l2, l10, l4);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_midir_reserve_cfg_struct(void* l0, void* l1) {
    int32_t l2, l7, l8;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    void* l16 = NULL;
    void* l18 = NULL;
    vader_string_t l5;
    vader_box_t l6 = vader_box_null();
    size_t l9, l12, l15, l17;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    size_t t2;
    int64_t t3;
    vader_string_t t4;
    vader_box_t* gc_roots[2] = { &l6, &t1 };
    void** gc_raw_roots[11] = { &l0, &l1, &l3, &l4, &l10, &l11, &l13, &l14, &l16, &l18, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 11u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = -(INT32_C(1));
    if (((vader_struct_vader_comptime_MonoEntry_t*) ((vader_struct_vader_midir_CFGStructDecl_t*) l0)->f_origin)->f_symbol.tag == 893u) {
        t0 = ((vader_struct_vader_comptime_MonoEntry_t*) ((vader_struct_vader_midir_CFGStructDecl_t*) l0)->f_origin)->f_symbol.payload.obj;
        l2 = ((vader_struct_vader_resolver_symbol_Symbol_t*) t0)->f_id;
    } else {
    }
    if (((vader_struct_vader_comptime_MonoEntry_t*) ((vader_struct_vader_midir_CFGStructDecl_t*) l0)->f_origin)->f_symbol.tag == 893u) {
        l3 = ((vader_struct_vader_comptime_MonoEntry_t*) ((vader_struct_vader_midir_CFGStructDecl_t*) l0)->f_origin)->f_symbol.payload.obj;
        l4 = ((vader_struct_vader_comptime_MonoEntry_t*) ((vader_struct_vader_midir_CFGStructDecl_t*) l0)->f_origin)->f_type_arguments;
        t1 = vader_types_mk_struct(l3, l4, false);
        l5 = vader_bytecode_type_intern_key(t1);
        l6 = std_collections_get__string__i32(((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_type_key, l5);
        t2 = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_types)->length;
        l7 = ((int32_t) (size_t) t2);
        if (l6.tag == 163u) {
            l8 = ((int32_t) l6.payload.i);
            l3 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_types;
            t3 = ((int64_t) (int32_t) l8);
            l9 = (size_t) (int64_t) t3;
            vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
            if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
            if ((size_t) l9 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
            t1 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l9);
            if (t1.tag == 518u) {
                { vader_gc_top = gc_frame.prev; return; }
            }
            l7 = l8;
            vader_array_t* _a1_arr = vader_array_new(36u, 0u, 13u, 507u);
            l10 = (void*) _a1_arr;
            l11 = ((vader_struct_vader_midir_CFGStructDecl_t*) l0)->f_fields;
            l9 = ((vader_array_t*) l11)->length;
            l12 = (size_t) (int64_t) INT64_C(0);
            {
                loop_69: {
                    if ((l12 < l9)) {
                        vader_array_t* _a2_slotarr = ((vader_array_t*) l11);
                        if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                        if ((size_t) l12 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                        l13 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l12);
                        l8 = vader_bytecode_intern_type(((vader_struct_vader_midir_CFGStructField_t*) l13)->f_type, l1);
                        t4 = ((vader_struct_vader_midir_CFGStructField_t*) l13)->f_name;
                        vader_struct_vader_bytecode_BcField_t* _a3_obj = (vader_struct_vader_bytecode_BcField_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcField_t));
                        vader_obj_header_init(_a3_obj, 507u);
                        _a3_obj->f_name = t4;
                        _a3_obj->f_type_index = l8;
                        l14 = (void*) _a3_obj;
                        vader_array_push((vader_array_t*) l10, vader_ref_box(l14));
                        l15 = (size_t) (int64_t) INT64_C(1);
                        t3 = (l12 + l15);
                        l12 = (size_t) (int64_t) t3;
                        goto loop_69;
                    } else {
                    }
                }
            }
            l16 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_types;
            t3 = ((int64_t) (int32_t) l7);
            l17 = (size_t) (int64_t) t3;
            t4 = ((vader_struct_vader_midir_CFGStructDecl_t*) l0)->f_mangled;
            vader_struct_vader_bytecode_BcStruct_t* _a4_obj = (vader_struct_vader_bytecode_BcStruct_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcStruct_t));
            vader_obj_header_init(_a4_obj, 518u);
            _a4_obj->f_name = t4;
            _a4_obj->f_fields = l10;
            _a4_obj->f_symbol_id = l2;
            l18 = (void*) _a4_obj;
            vader_array_t* _a5_slotarr = ((vader_array_t*) l16);
            if (_a5_slotarr->buf != NULL && _a5_slotarr->buf->header.forward != NULL) { _a5_slotarr->buf = vader_array_buf_forward(_a5_slotarr->buf); }
            if ((size_t) l17 >= _a5_slotarr->length) { vader_trap("array index out of bounds"); }
            vader_array_ref_store(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l17, l18);
            VADER_WRITE_BARRIER(_a5_slotarr->buf);
            { vader_gc_top = gc_frame.prev; return; }
        }
        std_collections_put__string__i32(((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_type_key, l5, l7);
        l3 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_types;
        t4 = ((vader_struct_vader_midir_CFGStructDecl_t*) l0)->f_mangled;
        vader_struct_vader_bytecode_BcRef_t* _a6_obj = (vader_struct_vader_bytecode_BcRef_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcRef_t));
        vader_obj_header_init(_a6_obj, 515u);
        _a6_obj->f_trait_name = t4;
        l4 = (void*) _a6_obj;
        vader_array_push((vader_array_t*) l3, vader_ref_box(l4));
        vader_array_t* _a7_arr = vader_array_new(36u, 0u, 13u, 507u);
        l10 = (void*) _a7_arr;
        l11 = ((vader_struct_vader_midir_CFGStructDecl_t*) l0)->f_fields;
        l9 = ((vader_array_t*) l11)->length;
        l12 = (size_t) (int64_t) INT64_C(0);
        {
            loop_140: {
                if ((l12 < l9)) {
                    vader_array_t* _a8_slotarr = ((vader_array_t*) l11);
                    if (_a8_slotarr->buf != NULL && _a8_slotarr->buf->header.forward != NULL) { _a8_slotarr->buf = vader_array_buf_forward(_a8_slotarr->buf); }
                    if ((size_t) l12 >= _a8_slotarr->length) { vader_trap("array index out of bounds"); }
                    l13 = vader_array_ref_load_obj(_a8_slotarr->buf, _a8_slotarr->offset + (size_t) l12);
                    l8 = vader_bytecode_intern_type(((vader_struct_vader_midir_CFGStructField_t*) l13)->f_type, l1);
                    t4 = ((vader_struct_vader_midir_CFGStructField_t*) l13)->f_name;
                    vader_struct_vader_bytecode_BcField_t* _a9_obj = (vader_struct_vader_bytecode_BcField_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcField_t));
                    vader_obj_header_init(_a9_obj, 507u);
                    _a9_obj->f_name = t4;
                    _a9_obj->f_type_index = l8;
                    l14 = (void*) _a9_obj;
                    vader_array_push((vader_array_t*) l10, vader_ref_box(l14));
                    l15 = (size_t) (int64_t) INT64_C(1);
                    t3 = (l12 + l15);
                    l12 = (size_t) (int64_t) t3;
                    goto loop_140;
                } else {
                }
            }
        }
        l16 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_types;
        t3 = ((int64_t) (int32_t) l7);
        l17 = (size_t) (int64_t) t3;
        t4 = ((vader_struct_vader_midir_CFGStructDecl_t*) l0)->f_mangled;
        vader_struct_vader_bytecode_BcStruct_t* _a10_obj = (vader_struct_vader_bytecode_BcStruct_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcStruct_t));
        vader_obj_header_init(_a10_obj, 518u);
        _a10_obj->f_name = t4;
        _a10_obj->f_fields = l10;
        _a10_obj->f_symbol_id = l2;
        l18 = (void*) _a10_obj;
        vader_array_t* _a11_slotarr = ((vader_array_t*) l16);
        if (_a11_slotarr->buf != NULL && _a11_slotarr->buf->header.forward != NULL) { _a11_slotarr->buf = vader_array_buf_forward(_a11_slotarr->buf); }
        if ((size_t) l17 >= _a11_slotarr->length) { vader_trap("array index out of bounds"); }
        vader_array_ref_store(_a11_slotarr->buf, _a11_slotarr->offset + (size_t) l17, l18);
        VADER_WRITE_BARRIER(_a11_slotarr->buf);
        { vader_gc_top = gc_frame.prev; return; }
    }
    t2 = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_types)->length;
    l7 = ((int32_t) (size_t) t2);
    l3 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_types;
    t4 = ((vader_struct_vader_midir_CFGStructDecl_t*) l0)->f_mangled;
    vader_struct_vader_bytecode_BcRef_t* _a12_obj = (vader_struct_vader_bytecode_BcRef_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcRef_t));
    vader_obj_header_init(_a12_obj, 515u);
    _a12_obj->f_trait_name = t4;
    l4 = (void*) _a12_obj;
    vader_array_push((vader_array_t*) l3, vader_ref_box(l4));
    vader_array_t* _a13_arr = vader_array_new(36u, 0u, 13u, 507u);
    l3 = (void*) _a13_arr;
    l4 = ((vader_struct_vader_midir_CFGStructDecl_t*) l0)->f_fields;
    l9 = ((vader_array_t*) l4)->length;
    l12 = (size_t) (int64_t) INT64_C(0);
    {
        loop_211: {
            if ((l12 < l9)) {
                vader_array_t* _a14_slotarr = ((vader_array_t*) l4);
                if (_a14_slotarr->buf != NULL && _a14_slotarr->buf->header.forward != NULL) { _a14_slotarr->buf = vader_array_buf_forward(_a14_slotarr->buf); }
                if ((size_t) l12 >= _a14_slotarr->length) { vader_trap("array index out of bounds"); }
                l10 = vader_array_ref_load_obj(_a14_slotarr->buf, _a14_slotarr->offset + (size_t) l12);
                l8 = vader_bytecode_intern_type(((vader_struct_vader_midir_CFGStructField_t*) l10)->f_type, l1);
                t4 = ((vader_struct_vader_midir_CFGStructField_t*) l10)->f_name;
                vader_struct_vader_bytecode_BcField_t* _a15_obj = (vader_struct_vader_bytecode_BcField_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcField_t));
                vader_obj_header_init(_a15_obj, 507u);
                _a15_obj->f_name = t4;
                _a15_obj->f_type_index = l8;
                l11 = (void*) _a15_obj;
                vader_array_push((vader_array_t*) l3, vader_ref_box(l11));
                t3 = (l12 + INT64_C(1));
                l12 = (size_t) (int64_t) t3;
                goto loop_211;
            } else {
            }
        }
    }
    l4 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_types;
    t3 = ((int64_t) (int32_t) l7);
    l9 = (size_t) (int64_t) t3;
    t4 = ((vader_struct_vader_midir_CFGStructDecl_t*) l0)->f_mangled;
    vader_struct_vader_bytecode_BcStruct_t* _a16_obj = (vader_struct_vader_bytecode_BcStruct_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcStruct_t));
    vader_obj_header_init(_a16_obj, 518u);
    _a16_obj->f_name = t4;
    _a16_obj->f_fields = l3;
    _a16_obj->f_symbol_id = l2;
    l3 = (void*) _a16_obj;
    vader_array_t* _a17_slotarr = ((vader_array_t*) l4);
    if (_a17_slotarr->buf != NULL && _a17_slotarr->buf->header.forward != NULL) { _a17_slotarr->buf = vader_array_buf_forward(_a17_slotarr->buf); }
    if ((size_t) l9 >= _a17_slotarr->length) { vader_trap("array index out of bounds"); }
    vader_array_ref_store(_a17_slotarr->buf, _a17_slotarr->offset + (size_t) l9, l3);
    VADER_WRITE_BARRIER(_a17_slotarr->buf);
    l3 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_type_key;
    l5 = ((vader_struct_vader_midir_CFGStructDecl_t*) l0)->f_mangled;
    std_collections_put__string__i32(l3, l5, l7);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static vader_box_t vader_midir_resolve_loop_frame(void* l0, vader_box_t l1) {
    void* l2;
    void* l6;
    size_t l3;
    vader_string_t l4;
    int64_t l5, l7;
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
                    l7 = INT64_C(1);
                    l5 = (l5 - l7);
                    goto loop_34;
                }
                l7 = INT64_C(1);
                l5 = (l5 - l7);
                goto loop_34;
            } else {
            }
        }
    }
    t1 = vader_box_obj(0u, NULL);
    return t1;
}

static int32_t vader_midir_resolve_vtable_fn_index(void* l0, void* l1) {
    void* l2 = NULL;
    vader_string_t l3;
    vader_box_t l4 = vader_box_null();
    int32_t l5;
    int32_t t0;
    vader_box_t* gc_roots[1] = { &l4 };
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_function_index_by_mangle;
    l3 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l0)->f_name;
    l4 = std_collections_get__string__i32(l2, l3);
    if (l4.tag == 163u) {
        t0 = ((int32_t) l4.payload.i);
        { int32_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_function_index_by_symbol_id;
    l5 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l0)->f_id;
    l4 = std_collections_get__i32__i32(l2, l5);
    if (l4.tag == 163u) {
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
    vader_array_t* _a0_arr = vader_array_new(9u, 0u, 7u, 163u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(6u, 1u, 12u, 159u);
    ((uint8_t*) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = (uint8_t) false;
    l2 = (void*) _a1_arr;
    l3 = ((vader_array_t*) ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_blocks)->length;
    vader_array_t* _a2_arr = vader_array_repeat((vader_array_t*) l2, (size_t) l3);
    l2 = (void*) _a2_arr;
    l4 = ((vader_struct_vader_midir_CFGFunction_t*) l0)->f_entry;
    vader_midir_walk_rpo(l0, l4, l2, l1);
    vader_array_t* _a3_arr = vader_array_new(9u, 0u, 7u, 163u);
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
            } else {
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
                        } else {
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
            } else {
            }
        }
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static bool vader_midir_scope_contains_target(void* l0, int32_t l1) {
    void* l2;
    size_t l3, l4;
    int32_t l5, l6;
    void* t0;
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
                t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
                l5 = ((vader_struct_vader_midir_ScopeFrame_t*) t0)->f_target_blk;
                l6 = l1;
                if (l5 == l6) {
                    return true;
                }
                t1 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t1;
                goto loop_7;
            } else {
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
    l2 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) ((vader_struct_std_collections_MutableSet__i32_t*) l0)->f_inner)->f_size;
    l3 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) ((vader_struct_std_collections_MutableSet__i32_t*) l1)->f_inner)->f_size;
    if (l2 != l3) {
        return false;
    }
    l4 = l0;
    l5 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) ((vader_struct_std_collections_MutableSet__i32_t*) l4)->f_inner)->f_ekeys;
    l2 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) ((vader_struct_std_collections_MutableSet__i32_t*) l4)->f_inner)->f_size;
    l3 = (size_t) (int64_t) INT64_C(0);
    {
        loop_26: {
            if ((l3 >= l2)) {
            } else {
                vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
                if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                l6 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
                t0 = (l3 + INT64_C(1));
                l3 = (size_t) (int64_t) t0;
                t1 = std_collections_contains_key__i32__bool(((vader_struct_std_collections_MutableSet__i32_t*) l1)->f_inner, l6);
                if (!(t1)) {
                    return false;
                }
                goto loop_26;
            }
        }
    }
    return true;
}

static int32_t vader_midir_struct_symbol_id(vader_box_t l0) {
    void* t0;
    int32_t t1;
    if (l0.tag == 930u) {
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
    if (l1.tag == 854u) {
        t0 = l1.payload.obj;
        vader_array_t* _a0_arr = vader_array_new(9u, 1u, 7u, 163u);
        ((int32_t*) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = (int32_t) ((vader_struct_vader_midir_TermBranch_t*) t0)->f_target;
        t0 = (void*) _a0_arr;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 855u) {
        l2 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir_TermCondBranch_t*) l2)->f_then_block;
        l4 = ((vader_struct_vader_midir_TermCondBranch_t*) l2)->f_else_block;
        vader_array_t* _a1_arr = vader_array_new(9u, 2u, 7u, 163u);
        ((int32_t*) _a1_arr->buf->slots)[_a1_arr->offset + 1u] = (int32_t) l4;
        ((int32_t*) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = (int32_t) l3;
        t0 = (void*) _a1_arr;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 856u) {
        vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 163u);
        t0 = (void*) _a2_arr;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 857u) {
        vader_array_t* _a3_arr = vader_array_new(9u, 0u, 7u, 163u);
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
    vader_string_t l7, l12, l23, l27;
    int32_t l8, l9, l10, l19, l21;
    void* t0 = NULL;
    int64_t t1;
    size_t t2;
    bool t3;
    vader_box_t t4 = vader_box_null();
    vader_string_t t5;
    vader_box_t* gc_roots[1] = { &t4 };
    void** gc_raw_roots[15] = { &l0, &l1, &l2, &l3, &l4, &l11, &l13, &l14, &l16, &l20, &l22, &l24, &l25, &l26, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 15u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 161u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(6u, 0u, 12u, 159u);
    l3 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 163u);
    l4 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__string__bool_t* _a3_obj = (vader_struct_std_collections_MutableMap__string__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__bool_t));
    vader_obj_header_init(_a3_obj, 368u);
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
                std_collections_put__string__bool(l2, l7, true);
                t1 = (l6 + INT64_C(1));
                l6 = (size_t) (int64_t) t1;
                goto loop_21;
            } else {
            }
        }
    }
    t2 = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_imports)->length;
    l8 = ((int32_t) (size_t) t2);
    l9 = INT32_C(0);
    {
        loop_53: {
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
                    goto loop_53;
                }
                l7 = ((vader_struct_vader_bytecode_BcImport_t*) l4)->f_mangled_name;
                t4 = std_collections_get__string__bool(l2, l7);
                if (t4.tag == 0u) {
                    goto loop_53;
                }
                l11 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_function_index_by_mangle;
                l12 = ((vader_struct_vader_bytecode_BcImport_t*) l4)->f_mangled_name;
                t4 = std_collections_get__string__i32(l11, l12);
                if (t4.tag == 163u) {
                    goto loop_53;
                }
                l13 = vader_bytecode_build_intrinsic_wrapper_body(l4, l10);
                vader_array_t* _a6_arr = vader_array_new(120u, 0u, 13u, 1102u);
                l14 = (void*) _a6_arr;
                l6 = ((vader_array_t*) l13)->length;
                l15 = (size_t) (int64_t) INT64_C(0);
                {
                    loop_112: {
                        if ((l15 < l6)) {
                            vader_array_push((vader_array_t*) l14, vader_box_obj(0u, NULL));
                            t1 = (l15 + INT64_C(1));
                            l15 = (size_t) (int64_t) t1;
                            goto loop_112;
                        } else {
                        }
                    }
                }
                vader_array_t* _a7_arr = vader_array_new(9u, 0u, 7u, 163u);
                l16 = (void*) _a7_arr;
                l17 = ((vader_array_t*) l13)->length;
                l18 = (size_t) (int64_t) INT64_C(0);
                {
                    loop_137: {
                        if ((l18 < l17)) {
                            l19 = -(INT32_C(1));
                            vader_array_push_i32((vader_array_t*) l16, l19);
                            t1 = (l18 + INT64_C(1));
                            l18 = (size_t) (int64_t) t1;
                            goto loop_137;
                        } else {
                        }
                    }
                }
                vader_array_t* _a8_arr = vader_array_new(39u, 0u, 13u, 511u);
                l20 = (void*) _a8_arr;
                t2 = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_functions)->length;
                l21 = ((int32_t) (size_t) t2);
                l22 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_functions;
                t5 = ((vader_struct_vader_bytecode_BcImport_t*) l4)->f_mangled_name;
                l23 = concat_2(t5, 871u);
                l24 = ((vader_struct_vader_bytecode_BcImport_t*) l4)->f_signature;
                vader_struct_vader_bytecode_BcFunction_t* _a9_obj = (vader_struct_vader_bytecode_BcFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcFunction_t));
                vader_obj_header_init(_a9_obj, 509u);
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
                std_collections_put__string__i32(l26, l27, l21);
                goto loop_53;
            } else {
            }
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
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
    } else {
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
    t0 = vader_box_bool(159u, ((uint8_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l4]);
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
            } else {
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
    t1 = vader_box_bool(159u, ((uint8_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l4]);
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
            } else {
            }
        }
    }
    vader_array_push_i32((vader_array_t*) l3, l1);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static vader_box_t vader_midir_with_dst(vader_box_t l0, int32_t l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l12 = NULL;
    vader_box_t l4 = vader_box_null(), l5 = vader_box_null();
    int32_t l6, l8, l11;
    uint8_t l7;
    vader_string_t l9;
    bool l10;
    void* t0 = NULL;
    vader_box_t* gc_roots[3] = { &l0, &l4, &l5 };
    void** gc_raw_roots[4] = { &l2, &l3, &l12, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 831u) {
        l2 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrConst_t*) l2)->f_span;
        l4 = ((vader_struct_vader_midir_InstrConst_t*) l2)->f_value;
        l5 = ((vader_struct_vader_midir_InstrConst_t*) l2)->f_type;
        vader_struct_vader_midir_InstrConst_t* _a0_obj = (vader_struct_vader_midir_InstrConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrConst_t));
        vader_obj_header_init(_a0_obj, 831u);
        _a0_obj->f_span = l3;
        _a0_obj->f_dst = l1;
        _a0_obj->f_value = l4;
        _a0_obj->f_type = l5;
        t0 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 840u) {
        l2 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrMove_t*) l2)->f_span;
        l6 = ((vader_struct_vader_midir_InstrMove_t*) l2)->f_src;
        vader_struct_vader_midir_InstrMove_t* _a1_obj = (vader_struct_vader_midir_InstrMove_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrMove_t));
        vader_obj_header_init(_a1_obj, 840u);
        _a1_obj->f_span = l3;
        _a1_obj->f_dst = l1;
        _a1_obj->f_src = l6;
        t0 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 824u) {
        l2 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrBinOp_t*) l2)->f_span;
        l7 = ((vader_struct_vader_midir_InstrBinOp_t*) l2)->f_op;
        l6 = ((vader_struct_vader_midir_InstrBinOp_t*) l2)->f_lhs;
        l8 = ((vader_struct_vader_midir_InstrBinOp_t*) l2)->f_rhs;
        l4 = ((vader_struct_vader_midir_InstrBinOp_t*) l2)->f_type;
        vader_struct_vader_midir_InstrBinOp_t* _a2_obj = (vader_struct_vader_midir_InstrBinOp_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrBinOp_t));
        vader_obj_header_init(_a2_obj, 824u);
        _a2_obj->f_span = l3;
        _a2_obj->f_dst = l1;
        _a2_obj->f_op = l7;
        _a2_obj->f_lhs = l6;
        _a2_obj->f_rhs = l8;
        _a2_obj->f_type = l4;
        t0 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 845u) {
        l2 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrUnOp_t*) l2)->f_span;
        l7 = ((vader_struct_vader_midir_InstrUnOp_t*) l2)->f_op;
        l6 = ((vader_struct_vader_midir_InstrUnOp_t*) l2)->f_operand;
        l4 = ((vader_struct_vader_midir_InstrUnOp_t*) l2)->f_type;
        vader_struct_vader_midir_InstrUnOp_t* _a3_obj = (vader_struct_vader_midir_InstrUnOp_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrUnOp_t));
        vader_obj_header_init(_a3_obj, 845u);
        _a3_obj->f_span = l3;
        _a3_obj->f_dst = l1;
        _a3_obj->f_op = l7;
        _a3_obj->f_operand = l6;
        _a3_obj->f_type = l4;
        t0 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 835u) {
        l2 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrFieldGet_t*) l2)->f_span;
        l6 = ((vader_struct_vader_midir_InstrFieldGet_t*) l2)->f_target;
        l9 = ((vader_struct_vader_midir_InstrFieldGet_t*) l2)->f_field;
        l4 = ((vader_struct_vader_midir_InstrFieldGet_t*) l2)->f_type;
        vader_struct_vader_midir_InstrFieldGet_t* _a4_obj = (vader_struct_vader_midir_InstrFieldGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrFieldGet_t));
        vader_obj_header_init(_a4_obj, 835u);
        _a4_obj->f_span = l3;
        _a4_obj->f_dst = l1;
        _a4_obj->f_target = l6;
        _a4_obj->f_field = l9;
        _a4_obj->f_type = l4;
        t0 = (void*) _a4_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 818u) {
        l2 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrArrayGet_t*) l2)->f_span;
        l6 = ((vader_struct_vader_midir_InstrArrayGet_t*) l2)->f_target;
        l8 = ((vader_struct_vader_midir_InstrArrayGet_t*) l2)->f_index;
        l4 = ((vader_struct_vader_midir_InstrArrayGet_t*) l2)->f_type;
        l10 = ((vader_struct_vader_midir_InstrArrayGet_t*) l2)->f_bounds_safe;
        vader_struct_vader_midir_InstrArrayGet_t* _a5_obj = (vader_struct_vader_midir_InstrArrayGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrArrayGet_t));
        vader_obj_header_init(_a5_obj, 818u);
        _a5_obj->f_span = l3;
        _a5_obj->f_dst = l1;
        _a5_obj->f_target = l6;
        _a5_obj->f_index = l8;
        _a5_obj->f_type = l4;
        _a5_obj->f_bounds_safe = l10;
        t0 = (void*) _a5_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 819u) {
        l2 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrArrayLen_t*) l2)->f_span;
        l6 = ((vader_struct_vader_midir_InstrArrayLen_t*) l2)->f_target;
        l10 = ((vader_struct_vader_midir_InstrArrayLen_t*) l2)->f_resolve_buf;
        vader_struct_vader_midir_InstrArrayLen_t* _a6_obj = (vader_struct_vader_midir_InstrArrayLen_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrArrayLen_t));
        vader_obj_header_init(_a6_obj, 819u);
        _a6_obj->f_span = l3;
        _a6_obj->f_dst = l1;
        _a6_obj->f_target = l6;
        _a6_obj->f_resolve_buf = l10;
        t0 = (void*) _a6_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 823u) {
        l2 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrArraySlice_t*) l2)->f_span;
        l4 = ((vader_struct_vader_midir_InstrArraySlice_t*) l2)->f_type;
        l6 = ((vader_struct_vader_midir_InstrArraySlice_t*) l2)->f_target;
        l8 = ((vader_struct_vader_midir_InstrArraySlice_t*) l2)->f_lo;
        l11 = ((vader_struct_vader_midir_InstrArraySlice_t*) l2)->f_hi;
        vader_struct_vader_midir_InstrArraySlice_t* _a7_obj = (vader_struct_vader_midir_InstrArraySlice_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrArraySlice_t));
        vader_obj_header_init(_a7_obj, 823u);
        _a7_obj->f_span = l3;
        _a7_obj->f_dst = l1;
        _a7_obj->f_type = l4;
        _a7_obj->f_target = l6;
        _a7_obj->f_lo = l8;
        _a7_obj->f_hi = l11;
        t0 = (void*) _a7_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 841u) {
        l2 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrStringSlice_t*) l2)->f_span;
        l4 = ((vader_struct_vader_midir_InstrStringSlice_t*) l2)->f_type;
        l6 = ((vader_struct_vader_midir_InstrStringSlice_t*) l2)->f_target;
        l8 = ((vader_struct_vader_midir_InstrStringSlice_t*) l2)->f_lo;
        l11 = ((vader_struct_vader_midir_InstrStringSlice_t*) l2)->f_hi;
        vader_struct_vader_midir_InstrStringSlice_t* _a8_obj = (vader_struct_vader_midir_InstrStringSlice_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrStringSlice_t));
        vader_obj_header_init(_a8_obj, 841u);
        _a8_obj->f_span = l3;
        _a8_obj->f_dst = l1;
        _a8_obj->f_type = l4;
        _a8_obj->f_target = l6;
        _a8_obj->f_lo = l8;
        _a8_obj->f_hi = l11;
        t0 = (void*) _a8_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 842u) {
        l2 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrStructNew_t*) l2)->f_span;
        l4 = ((vader_struct_vader_midir_InstrStructNew_t*) l2)->f_type;
        l12 = ((vader_struct_vader_midir_InstrStructNew_t*) l2)->f_fields;
        l10 = ((vader_struct_vader_midir_InstrStructNew_t*) l2)->f_stack;
        vader_struct_vader_midir_InstrStructNew_t* _a9_obj = (vader_struct_vader_midir_InstrStructNew_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrStructNew_t));
        vader_obj_header_init(_a9_obj, 842u);
        _a9_obj->f_span = l3;
        _a9_obj->f_dst = l1;
        _a9_obj->f_type = l4;
        _a9_obj->f_fields = l12;
        _a9_obj->f_stack = l10;
        t0 = (void*) _a9_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 820u) {
        l2 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrArrayNew_t*) l2)->f_span;
        l4 = ((vader_struct_vader_midir_InstrArrayNew_t*) l2)->f_type;
        l6 = ((vader_struct_vader_midir_InstrArrayNew_t*) l2)->f_length;
        l12 = ((vader_struct_vader_midir_InstrArrayNew_t*) l2)->f_elements;
        l10 = ((vader_struct_vader_midir_InstrArrayNew_t*) l2)->f_stack;
        vader_struct_vader_midir_InstrArrayNew_t* _a10_obj = (vader_struct_vader_midir_InstrArrayNew_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrArrayNew_t));
        vader_obj_header_init(_a10_obj, 820u);
        _a10_obj->f_span = l3;
        _a10_obj->f_dst = l1;
        _a10_obj->f_type = l4;
        _a10_obj->f_length = l6;
        _a10_obj->f_elements = l12;
        _a10_obj->f_stack = l10;
        t0 = (void*) _a10_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 832u) {
        l2 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrDataConst_t*) l2)->f_span;
        l4 = ((vader_struct_vader_midir_InstrDataConst_t*) l2)->f_type;
        l6 = ((vader_struct_vader_midir_InstrDataConst_t*) l2)->f_pool_index;
        vader_struct_vader_midir_InstrDataConst_t* _a11_obj = (vader_struct_vader_midir_InstrDataConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrDataConst_t));
        vader_obj_header_init(_a11_obj, 832u);
        _a11_obj->f_span = l3;
        _a11_obj->f_dst = l1;
        _a11_obj->f_type = l4;
        _a11_obj->f_pool_index = l6;
        t0 = (void*) _a11_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 843u) {
        l2 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrTypeCheck_t*) l2)->f_span;
        l6 = ((vader_struct_vader_midir_InstrTypeCheck_t*) l2)->f_value;
        l4 = ((vader_struct_vader_midir_InstrTypeCheck_t*) l2)->f_check_type;
        vader_struct_vader_midir_InstrTypeCheck_t* _a12_obj = (vader_struct_vader_midir_InstrTypeCheck_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrTypeCheck_t));
        vader_obj_header_init(_a12_obj, 843u);
        _a12_obj->f_span = l3;
        _a12_obj->f_dst = l1;
        _a12_obj->f_value = l6;
        _a12_obj->f_check_type = l4;
        t0 = (void*) _a12_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 844u) {
        l2 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrTypeConst_t*) l2)->f_span;
        l4 = ((vader_struct_vader_midir_InstrTypeConst_t*) l2)->f_type;
        l5 = ((vader_struct_vader_midir_InstrTypeConst_t*) l2)->f_value_type;
        vader_struct_vader_midir_InstrTypeConst_t* _a13_obj = (vader_struct_vader_midir_InstrTypeConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrTypeConst_t));
        vader_obj_header_init(_a13_obj, 844u);
        _a13_obj->f_span = l3;
        _a13_obj->f_dst = l1;
        _a13_obj->f_type = l4;
        _a13_obj->f_value_type = l5;
        t0 = (void*) _a13_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 827u) {
        l2 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrCast_t*) l2)->f_span;
        l6 = ((vader_struct_vader_midir_InstrCast_t*) l2)->f_value;
        l4 = ((vader_struct_vader_midir_InstrCast_t*) l2)->f_type;
        vader_struct_vader_midir_InstrCast_t* _a14_obj = (vader_struct_vader_midir_InstrCast_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrCast_t));
        vader_obj_header_init(_a14_obj, 827u);
        _a14_obj->f_span = l3;
        _a14_obj->f_dst = l1;
        _a14_obj->f_value = l6;
        _a14_obj->f_type = l4;
        t0 = (void*) _a14_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 829u) {
        l2 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrCellNew_t*) l2)->f_span;
        l6 = ((vader_struct_vader_midir_InstrCellNew_t*) l2)->f_value;
        l4 = ((vader_struct_vader_midir_InstrCellNew_t*) l2)->f_value_type;
        vader_struct_vader_midir_InstrCellNew_t* _a15_obj = (vader_struct_vader_midir_InstrCellNew_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrCellNew_t));
        vader_obj_header_init(_a15_obj, 829u);
        _a15_obj->f_span = l3;
        _a15_obj->f_dst = l1;
        _a15_obj->f_value = l6;
        _a15_obj->f_value_type = l4;
        t0 = (void*) _a15_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 828u) {
        l2 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrCellGet_t*) l2)->f_span;
        l6 = ((vader_struct_vader_midir_InstrCellGet_t*) l2)->f_cell;
        l4 = ((vader_struct_vader_midir_InstrCellGet_t*) l2)->f_value_type;
        vader_struct_vader_midir_InstrCellGet_t* _a16_obj = (vader_struct_vader_midir_InstrCellGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrCellGet_t));
        vader_obj_header_init(_a16_obj, 828u);
        _a16_obj->f_span = l3;
        _a16_obj->f_dst = l1;
        _a16_obj->f_cell = l6;
        _a16_obj->f_value_type = l4;
        t0 = (void*) _a16_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 839u) {
        l2 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrMakeClosure_t*) l2)->f_span;
        l12 = ((vader_struct_vader_midir_InstrMakeClosure_t*) l2)->f_fn_symbol;
        l6 = ((vader_struct_vader_midir_InstrMakeClosure_t*) l2)->f_env;
        l4 = ((vader_struct_vader_midir_InstrMakeClosure_t*) l2)->f_env_type;
        l5 = ((vader_struct_vader_midir_InstrMakeClosure_t*) l2)->f_type;
        vader_struct_vader_midir_InstrMakeClosure_t* _a17_obj = (vader_struct_vader_midir_InstrMakeClosure_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrMakeClosure_t));
        vader_obj_header_init(_a17_obj, 839u);
        _a17_obj->f_span = l3;
        _a17_obj->f_dst = l1;
        _a17_obj->f_fn_symbol = l12;
        _a17_obj->f_env = l6;
        _a17_obj->f_env_type = l4;
        _a17_obj->f_type = l5;
        t0 = (void*) _a17_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 837u) {
        l2 = l0.payload.obj;
        l3 = ((vader_struct_vader_midir_InstrFnRef_t*) l2)->f_span;
        l12 = ((vader_struct_vader_midir_InstrFnRef_t*) l2)->f_fn_symbol;
        l4 = ((vader_struct_vader_midir_InstrFnRef_t*) l2)->f_type;
        vader_struct_vader_midir_InstrFnRef_t* _a18_obj = (vader_struct_vader_midir_InstrFnRef_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_InstrFnRef_t));
        vader_obj_header_init(_a18_obj, 837u);
        _a18_obj->f_span = l3;
        _a18_obj->f_dst = l1;
        _a18_obj->f_fn_symbol = l12;
        _a18_obj->f_type = l4;
        t0 = (void*) _a18_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_box_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_midir_with_peephole_out(void* l0, void* l1) {
    vader_string_t l2;
    bool l3;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[8] = { &l0, &l1, &l4, &l5, &l6, &l7, &l8, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 8u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_name;
    l3 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_is_main;
    l4 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_signature;
    l5 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_locals;
    l6 = ((vader_struct_vader_bytecode_BcPeepholeOut_t*) l1)->f_body;
    l7 = ((vader_struct_vader_bytecode_BcPeepholeOut_t*) l1)->f_debug;
    l8 = ((vader_struct_vader_bytecode_BcPeepholeOut_t*) l1)->f_jump_table;
    vader_struct_vader_bytecode_BcFunction_t* _a0_obj = (vader_struct_vader_bytecode_BcFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcFunction_t));
    vader_obj_header_init(_a0_obj, 509u);
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

