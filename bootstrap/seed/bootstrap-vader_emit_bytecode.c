#include "bootstrap.split.h"

static vader_string_t vader_emit_bytecode$BytecodeProperty$std_core$Display$to_string(uint8_t l0);
static void vader_emit_bytecode$add_vtable_entry(void* l0, void* l1, vader_string_t l2, int32_t l3, int32_t l4);
static uint8_t vader_emit_bytecode$array_element_val_type(vader_box_t l0);
static vader_box_t vader_emit_bytecode$baked_value(void* l0, vader_box_t l1);
static vader_box_t vader_emit_bytecode$bc_type_of_with_ctx(vader_box_t l0, void* l1);
static bool vader_emit_bytecode$binary_leaves_width(uint8_t l0, uint8_t l1);
static bool vader_emit_bytecode$blocking_of(void* l0);
static bool vader_emit_bytecode$boxed_element(vader_box_t l0);
static bool vader_emit_bytecode$boxed_field(void* l0, int32_t l1, int64_t l2);
static void* vader_emit_bytecode$boxed_fields_of(void* l0, int32_t l1);
static void* vader_emit_bytecode$boxed_params_of(void* l0, void* l1);
static void* vader_emit_bytecode$build_cfg_signature(void* l0, vader_box_t l1, void* l2, void* l3);
static void* vader_emit_bytecode$build_impl_table_from_vtable(void* l0, void* l1, void* l2);
static void* vader_emit_bytecode$build_vtables_from_entries(void* l0, void* l1);
static void* vader_emit_bytecode$bytecode_stages(void);
static vader_string_t vader_emit_bytecode$c_struct_of(void* l0);
static bool vader_emit_bytecode$can_pass_through_stack(vader_box_t l0, vader_box_t l1, void* l2);
static bool vader_emit_bytecode$can_pass_through_terminator(vader_box_t l0, vader_box_t l1, void* l2);
static void vader_emit_bytecode$cf_block(void* l0, void* l1, int32_t l2);
static void vader_emit_bytecode$cf_br(void* l0, void* l1, int32_t l2);
static void vader_emit_bytecode$cf_br_if(void* l0, void* l1, int32_t l2);
static void vader_emit_bytecode$cf_else(void* l0, void* l1);
static void vader_emit_bytecode$cf_end(void* l0, void* l1);
static void vader_emit_bytecode$cf_if(void* l0, void* l1);
static void vader_emit_bytecode$cf_loop(void* l0, void* l1, int32_t l2);
static void vader_emit_bytecode$close_blocks(void* l0, void* l1, void* l2, int32_t l3);
static bool vader_emit_bytecode$closes_loop(void* l0, int32_t l1, int32_t l2);
static vader_box_t vader_emit_bytecode$closure_header_type(vader_box_t l0);
static void vader_emit_bytecode$collect_baked_types(vader_box_t l0, void* l1, void* l2);
static bool vader_emit_bytecode$compares_boxes(uint8_t l0, vader_box_t l1);
static bool vader_emit_bytecode$const_fills_slot(vader_box_t l0, uint8_t l1);
static uint8_t vader_emit_bytecode$const_val_type(vader_box_t l0);
static void* vader_emit_bytecode$convert_data_pool(void* l0, void* l1);
static bool vader_emit_bytecode$convert_eligible(uint8_t l0);
static bool vader_emit_bytecode$copies_cheaply(void* l0);
static void* vader_emit_bytecode$data_pool_type_roots(void* l0, void* l1);
static vader_box_t vader_emit_bytecode$debug_pos_of_span(void* l0);
static void vader_emit_bytecode$defer_or_resolve_branch(void* l0, int32_t l1, int32_t l2);
static int32_t vader_emit_bytecode$destination(void* l0, int32_t l1);
static void vader_emit_bytecode$drain_pending(void* l0, int32_t l1, bool l2, int32_t l3, int32_t l4);
static void* vader_emit_bytecode$drop_unbranched_blocks(void* l0);
static void vader_emit_bytecode$emit_body(void* l0, void* l1, int32_t l2, int32_t l3, int32_t l4);
static void vader_emit_bytecode$emit_branch(void* l0, void* l1, int32_t l2, int32_t l3, int32_t l4, void* l5);
static void vader_emit_bytecode$emit_call_results(void* l0, int64_t l1, void* l2, void* l3);
static void vader_emit_bytecode$emit_cfg_function_body(void* l0, int32_t l1, void* l2, void* l3, bool l4);
static void vader_emit_bytecode$emit_cond_branch(void* l0, void* l1, int32_t l2, void* l3, int32_t l4, int32_t l5);
static void vader_emit_bytecode$emit_const_instr(void* l0, void* l1, int64_t l2);
static void vader_emit_bytecode$emit_first_get(void* l0, int64_t l1, int32_t l2, void* l3);
static void vader_emit_bytecode$emit_get(void* l0, int32_t l1, void* l2);
static void vader_emit_bytecode$emit_instr(void* l0, vader_box_t l1, int64_t l2);
static void vader_emit_bytecode$emit_instructions(void* l0, int32_t l1, int64_t l2, int64_t l3);
static void vader_emit_bytecode$emit_loop(void* l0, void* l1, int32_t l2, int32_t l3);
static void vader_emit_bytecode$emit_narrowing(void* l0, uint8_t l1, void* l2);
static void vader_emit_bytecode$emit_operands_into(void* l0, int64_t l1, void* l2, void* l3, void* l4);
static void vader_emit_bytecode$emit_result(void* l0, int64_t l1, int32_t l2, void* l3);
static void vader_emit_bytecode$emit_result_if_any(void* l0, int64_t l1, vader_box_t l2, void* l3);
static void vader_emit_bytecode$emit_retag_into(void* l0, int32_t l1, bool l2, void* l3);
static void vader_emit_bytecode$emit_return(void* l0, int32_t l1, void* l2);
static void vader_emit_bytecode$emit_return_retag(void* l0, int32_t l1, int64_t l2, void* l3);
static void vader_emit_bytecode$emit_set(void* l0, int32_t l1, void* l2);
static void vader_emit_bytecode$emit_subtree(void* l0, void* l1, int32_t l2, int32_t l3);
static void vader_emit_bytecode$emit_terminator(void* l0, void* l1, int32_t l2, int32_t l3, int32_t l4);
static bool vader_emit_bytecode$emitted_beneath(void* l0, void* l1, void* l2, void* l3, int32_t l4);
static bool vader_emit_bytecode$ends_function(vader_box_t l0);
static bool vader_emit_bytecode$entered_by_test(void* l0, void* l1, int32_t l2);
static void* vader_emit_bytecode$every_operand_boxed(void* l0);
static bool vader_emit_bytecode$extend_into_loops(void* l0, void* l1, int64_t l2, void* l3);
static void* vader_emit_bytecode$find_loop_ranges(void* l0);
static vader_box_t vader_emit_bytecode$find_struct_field_index(void* l0, int32_t l1, vader_string_t l2);
static vader_box_t vader_emit_bytecode$first_stack_operand(vader_box_t l0);
static vader_box_t vader_emit_bytecode$first_terminator_operand(vader_box_t l0);
static bool vader_emit_bytecode$fits_in(uint8_t l0, uint8_t l1);
static bool vader_emit_bytecode$foldable_self_copy(void* l0, int64_t l1, int64_t l2, void* l3);
static bool vader_emit_bytecode$goes_on_or_out(void* l0, void* l1, void* l2, int32_t l3);
static bool vader_emit_bytecode$has_receiver(void* l0, int32_t l1);
static bool vader_emit_bytecode$holds_all(void* l0, void* l1);
static void* vader_emit_bytecode$import_call_target(void* l0, int32_t l1);
static int32_t vader_emit_bytecode$intern_cell_type(vader_box_t l0, void* l1);
static int32_t vader_emit_bytecode$intern_string(vader_string_t l0, void* l1);
static int32_t vader_emit_bytecode$intern_type(vader_box_t l0, void* l1);
static bool vader_emit_bytecode$is_union_slot(vader_box_t l0);
static int64_t vader_emit_bytecode$last_empty_stack_point(void* l0, int32_t l1);
static bool vader_emit_bytecode$last_op_exits(void* l0);
static bool vader_emit_bytecode$leaves_at_once(void* l0, void* l1, int32_t l2, int32_t l3);
static bool vader_emit_bytecode$leaves_header(void* l0, int32_t l1, int32_t l2);
static void vader_emit_bytecode$lend_written_mirrors(void* l0);
static int32_t vader_emit_bytecode$loop_exit(void* l0, void* l1, int32_t l2);
static bool vader_emit_bytecode$needs_ref_cast(vader_box_t l0);
static void* vader_emit_bytecode$new_emitter_ctx(void);
static vader_string_t vader_emit_bytecode$no_common_field(void* l0, vader_string_t l1, vader_box_t l2);
static bool vader_emit_bytecode$only_jumps(void* l0, int32_t l1, int32_t l2);
static int32_t vader_emit_bytecode$open_blocks(void* l0, void* l1, int32_t l2);
static int32_t vader_emit_bytecode$outermost_loop_left(void* l0, void* l1, int32_t l2, int32_t l3);
static void* vader_emit_bytecode$param_c_types_of(void* l0);
static vader_box_t vader_emit_bytecode$plan_bytecode_stages(void* l0);
static void* vader_emit_bytecode$planned_bytecode_stages(void);
static void* vader_emit_bytecode$propagated_once(void* l0);
static void* vader_emit_bytecode$prune_unused_data(void* l0, void* l1);
static void vader_emit_bytecode$prune_unused_functions(void* l0, void* l1, void* l2);
static void vader_emit_bytecode$prune_unused_globals(void* l0);
static void vader_emit_bytecode$prune_unused_imports(void* l0);
static void* vader_emit_bytecode$prune_unused_types(void* l0, void* l1);
static void vader_emit_bytecode$push_emit(void* l0, vader_box_t l1, void* l2);
static int32_t vader_emit_bytecode$push_op_with_span(void* l0, vader_box_t l1, void* l2);
static void vader_emit_bytecode$push_or_assign(void* l0, int64_t l1, vader_box_t l2);
static void vader_emit_bytecode$push_scope(void* l0, void* l1, int64_t l2, vader_string_t l3, int32_t l4);
static vader_box_t vader_emit_bytecode$pushed_element_type(vader_box_t l0, vader_box_t l1);
static bool vader_emit_bytecode$ranges_overlap(void* l0, void* l1);
static void vader_emit_bytecode$record_slot_type(void* l0, int32_t l1, vader_box_t l2);
static void vader_emit_bytecode$refuse_shared_identity_test(vader_string_t l0, vader_box_t l1);
static void vader_emit_bytecode$refuse_shared_instance(vader_string_t l0, vader_box_t l1);
static void* vader_emit_bytecode$remap_data_pool(void* l0, void* l1);
static void* vader_emit_bytecode$remap_data_values(void* l0, void* l1);
static void* vader_emit_bytecode$remap_debug(void* l0, void* l1, int64_t l2);
static void* vader_emit_bytecode$remap_globals(void* l0, void* l1);
static vader_box_t vader_emit_bytecode$remap_push_cache_slot(vader_box_t l0, void* l1);
static void* vader_emit_bytecode$remap_signature(void* l0, void* l1);
static vader_box_t vader_emit_bytecode$remap_type_in_op(vader_box_t l0, void* l1);
static void* vader_emit_bytecode$remap_type_indices(void* l0, void* l1);
static void vader_emit_bytecode$reserve_cfg_extern(void* l0, void* l1);
static void vader_emit_bytecode$reserve_cfg_function(void* l0, void* l1);
static void vader_emit_bytecode$reserve_cfg_struct(void* l0, void* l1);
static void* vader_emit_bytecode$resolve_direct_call(void* l0, void* l1);
static vader_box_t vader_emit_bytecode$resolve_fn_index(void* l0, void* l1);
static vader_string_t vader_emit_bytecode$result_c_type_of(void* l0);
static vader_box_t vader_emit_bytecode$retargeted(void* l0, vader_box_t l1);
static void* vader_emit_bytecode$run_bytecode_stages(void* l0, void* l1);
static void* vader_emit_bytecode$schedule_stack(void* l0);
static void* vader_emit_bytecode$shape_of(void* l0, void* l1, void* l2);
static void* vader_emit_bytecode$skip_forwarding_blocks(void* l0);
static vader_box_t vader_emit_bytecode$struct_decl_of(void* l0);
static int32_t vader_emit_bytecode$struct_symbol_id(vader_box_t l0);
static void vader_emit_bytecode$structure_function(void* l0);
static bool vader_emit_bytecode$tests_its_exit(void* l0, void* l1, int32_t l2);
static vader_string_t vader_emit_bytecode$trait_ref_name(void* l0, void* l1);
static vader_box_t vader_emit_bytecode$try_fold_arith(vader_box_t l0, void* l1, int64_t l2);
static bool vader_emit_bytecode$try_fuse_local_field(void* l0, int32_t l1, int32_t l2);
static int32_t vader_emit_bytecode$type_index_of(vader_box_t l0);
static vader_box_t vader_emit_bytecode$typed_intrinsic_op(void* l0, vader_box_t l1, void* l2);
static bool vader_emit_bytecode$unary_leaves_width(uint8_t l0, uint8_t l1);
static void vader_emit_bytecode$visit_type(int32_t l0, void* l1, void* l2);
static vader_box_t vader_emit_bytecode$walk_properties(void* l0);
static void* vader_emit_bytecode$with_param_decorators(void* l0, void* l1);

static vader_string_t vader_emit_bytecode$BytecodeProperty$std_core$Display$to_string(uint8_t l0) {
    vader_string_t l1;
    if (l0 == INT32_C(0)) {
        l1 = 971u;
        return l1;
    }
    if (l0 == INT32_C(1)) {
        l1 = 704u;
    } else if (l0 == INT32_C(2)) {
        l1 = 970u;
    } else {
        if (!(l0 == INT32_C(3))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = 869u;
    }
    return l1;
}

vader_string_t vader_emit_bytecode$BytecodeSpec$toolchain_stage$Placed$precedes(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    bool l4;
    int64_t l5, l6;
    vader_box_t l7 = vader_box_null();
    vader_string_t l8 = 0;
    vader_string_t l10 = 0;
    vader_string_t l11 = 0;
    uint8_t l9;
    bool t0;
    vader_string_t t1 = 0;
    vader_box_t t2 = vader_box_null();
    void* t3 = NULL;
    vader_box_t* gc_roots[2] = { &l7, &t2 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &t3 };
    vader_string_t* gc_atom_roots[4] = { &l8, &l10, &l11, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_emit_bytecode$BytecodeSpec_t*) l1)->f_after;
    vader_struct___lambda_env_vader_emit_bytecode_18_t* _a0_obj = (vader_struct___lambda_env_vader_emit_bytecode_18_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_emit_bytecode_18_t));
    vader_obj_header_init(_a0_obj, 625u);
    _a0_obj->f_cap_0 = l0;
    l3 = (void*) _a0_obj;
    l4 = false;
    l5 = vader_array_length(((vader_array_t*) l2));
    l6 = INT64_C(0);
    {
        while ((l6 < l5)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            l7 = vader_array_ref_load_box(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l6);
            t0 = __lambda_vader_emit_bytecode_17(l3, l7);
            if (t0) {
                l4 = true;
                goto end_12;
            }
            l6 = (l6 + INT64_C(1));
        }
        l4 = false;
    } end_12: ;
    if (l4) {
        l8 = ((vader_struct_vader_emit_bytecode$BytecodeSpec_t*) l1)->f_name;
        t1 = concat_3(1267u, l8, 1513u);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = ((vader_struct_vader_emit_bytecode$BytecodeSpec_t*) l1)->f_requires;
    l5 = vader_array_length(((vader_array_t*) l2));
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        t2 = vader_array_read_u8(_a2_slotarr, vader_array_offset(_a2_slotarr) + (size_t) l6, 582u);
        l9 = ((uint8_t) t2.payload.i);
        t3 = (void*) &vader_data_24;
        t0 = std_core$$array$Contains$contains__vader_emit_bytecode_BytecodeProperty(t3, l9);
        if (!(t0)) {
            t0 = std_core$$array$Contains$contains__vader_emit_bytecode_BytecodeProperty(((vader_struct_vader_emit_bytecode$BytecodeSpec_t*) l0)->f_establishes, l9);
            if (t0) {
                l8 = ((vader_struct_vader_emit_bytecode$BytecodeSpec_t*) l1)->f_name;
                l10 = vader_emit_bytecode$BytecodeProperty$std_core$Display$to_string(l9);
                l11 = ((vader_struct_vader_emit_bytecode$BytecodeSpec_t*) l0)->f_name;
                t1 = concat_7(1267u, l8, 1521u, l10, 1604u, l11, 1330u);
                { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
            }
        }
        l6 = (l6 + INT64_C(1));
    }
    l2 = ((vader_struct_vader_emit_bytecode$BytecodeSpec_t*) l0)->f_requires;
    l5 = vader_array_length(((vader_array_t*) l2));
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        t2 = vader_array_read_u8(_a3_slotarr, vader_array_offset(_a3_slotarr) + (size_t) l6, 582u);
        l9 = ((uint8_t) t2.payload.i);
        t0 = std_core$$array$Contains$contains__vader_emit_bytecode_BytecodeProperty(((vader_struct_vader_emit_bytecode$BytecodeSpec_t*) l1)->f_breaks, l9);
        if (t0) {
            l8 = ((vader_struct_vader_emit_bytecode$BytecodeSpec_t*) l0)->f_name;
            l10 = vader_emit_bytecode$BytecodeProperty$std_core$Display$to_string(l9);
            l11 = ((vader_struct_vader_emit_bytecode$BytecodeSpec_t*) l1)->f_name;
            t1 = concat_7(1267u, l8, 1521u, l10, 1604u, l11, 1309u);
            { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l6 = (l6 + INT64_C(1));
    }
    l2 = ((vader_struct_vader_emit_bytecode$BytecodeSpec_t*) l0)->f_breaks;
    l5 = vader_array_length(((vader_array_t*) l2));
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        t2 = vader_array_read_u8(_a4_slotarr, vader_array_offset(_a4_slotarr) + (size_t) l6, 582u);
        l9 = ((uint8_t) t2.payload.i);
        t0 = std_core$$array$Contains$contains__vader_emit_bytecode_BytecodeProperty(((vader_struct_vader_emit_bytecode$BytecodeSpec_t*) l1)->f_establishes, l9);
        if (t0) {
            l8 = ((vader_struct_vader_emit_bytecode$BytecodeSpec_t*) l1)->f_name;
            l10 = vader_emit_bytecode$BytecodeProperty$std_core$Display$to_string(l9);
            l11 = ((vader_struct_vader_emit_bytecode$BytecodeSpec_t*) l0)->f_name;
            t1 = concat_7(1267u, l8, 1525u, l10, 1604u, l11, 1309u);
            { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l6 = (l6 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return 0u; }
}

vader_string_t vader_emit_bytecode$BytecodeSpec$toolchain_stage$Placed$stage_name(void* l0) {
    vader_string_t t0;
    t0 = ((vader_struct_vader_emit_bytecode$BytecodeSpec_t*) l0)->f_name;
    return t0;
}

void* vader_emit_bytecode$CoalesceStage$toolchain_stage$Stage$describe(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l3, &l4, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 6u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(29u, 0u, 1u, 582u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(29u, 3u, 1u, 582u);
    ((uint8_t*) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 2u] = (uint8_t) INT32_C(3);
    ((uint8_t*) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 1u] = (uint8_t) INT32_C(2);
    ((uint8_t*) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 0u] = (uint8_t) INT32_C(0);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(29u, 0u, 1u, 582u);
    l3 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(34u, 0u, 0u, 591u);
    l4 = (void*) _a3_arr;
    vader_struct_vader_emit_bytecode$BytecodeSpec_t* _a4_obj = (vader_struct_vader_emit_bytecode$BytecodeSpec_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_bytecode$BytecodeSpec_t));
    vader_obj_header_init(_a4_obj, 1375u);
    _a4_obj->f_name = 2161u;
    _a4_obj->f_requires = l1;
    _a4_obj->f_breaks = l2;
    _a4_obj->f_establishes = l3;
    _a4_obj->f_after = l4;
    t0 = (void*) _a4_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_emit_bytecode$CoalesceStage$toolchain_stage$Stage$run(void* l0, void* l1) {
    int64_t l2, l3, l5, l8, l10, l22, l23, l24, l26;
    void* l4 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l13 = NULL;
    void* l16 = NULL;
    void* l18 = NULL;
    void* l19 = NULL;
    void* l20 = NULL;
    void* l25 = NULL;
    void* l27 = NULL;
    void* l28 = NULL;
    void* l31 = NULL;
    int32_t l9, l11, l12, l14, l15, l29, l30;
    bool l17;
    uint8_t l21;
    vader_box_t l32 = vader_box_null(), l33 = vader_box_null(), l34 = vader_box_null();
    vader_string_t l35 = 0;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    bool t2, t3;
    int64_t t4;
    vader_box_t* gc_roots[4] = { &l32, &l33, &l34, &t1 };
    void** gc_raw_roots[15] = {
        &l0, &l1, &l4, &l6, &l7, &l13, &l16, &l18, &l19, &l20, &l25, &l27, &l28, &l31, &t0,
    };
    vader_string_t* gc_atom_roots[1] = { &l35 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 15u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l1)->f_signature)->f_params));
    l3 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l1)->f_locals));
    l3 = vader_chk_add(i64, l2, l3);
    if ((l3 <= l2)) {
        { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l1)->f_body;
    l5 = vader_array_length(((vader_array_t*) l4));
    l6 = (void*) &vader_fn_static___lambda_vader_emit_bytecode_16;
    l6 = std_core$filled__vader_emit_bytecode_SlotRange(l3, l6);
    vader_array_t* _a0_arr = vader_array_new(24u, 1u, 12u, 575u);
    ((uint8_t*) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = (uint8_t) false;
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l3);
    l7 = (void*) _a1_arr;
    l8 = INT64_C(0);
    while ((l8 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l8)
        t1 = vader_array_ref_load_box(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l8);
        l9 = vader_core_bytecode$slot_touched(t1);
        if ((l9 >= INT32_C(0))) {
            l10 = ((int64_t) (int32_t) l9);
            vader_array_t* _a3_slotarr = ((vader_array_t*) l7);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l10)
            t2 = ((uint8_t*) _a3_slotarr->buf->slots)[vader_array_offset(_a3_slotarr) + (size_t) l10];
            t3 = t2;
            if (t3) {
                vader_array_t* _a4_slotarr = ((vader_array_t*) l6);
                VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l10)
                t0 = vader_array_ref_load_obj(_a4_slotarr->buf, vader_array_offset(_a4_slotarr) + (size_t) l10);
                l14 = ((vader_struct_vader_emit_bytecode$SlotRange_t*) t0)->f_first;
                l15 = ((int32_t) (int64_t) l8);
                vader_struct_vader_emit_bytecode$SlotRange_t* _a5_obj = (vader_struct_vader_emit_bytecode$SlotRange_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_bytecode$SlotRange_t));
                vader_obj_header_init(_a5_obj, 1389u);
                _a5_obj->f_first = l14;
                _a5_obj->f_last = l15;
                l16 = (void*) _a5_obj;
                vader_array_t* _a6_slotarr = ((vader_array_t*) l6);
                VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l10)
                vader_array_ref_store(_a6_slotarr->buf, vader_array_offset(_a6_slotarr) + (size_t) l10, l16);
                VADER_WRITE_BARRIER(_a6_slotarr->buf);
            } else {
                l11 = ((int32_t) (int64_t) l8);
                l12 = ((int32_t) (int64_t) l8);
                vader_struct_vader_emit_bytecode$SlotRange_t* _a7_obj = (vader_struct_vader_emit_bytecode$SlotRange_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_bytecode$SlotRange_t));
                vader_obj_header_init(_a7_obj, 1389u);
                _a7_obj->f_first = l11;
                _a7_obj->f_last = l12;
                l13 = (void*) _a7_obj;
                vader_array_t* _a8_slotarr = ((vader_array_t*) l6);
                VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l10)
                vader_array_ref_store(_a8_slotarr->buf, vader_array_offset(_a8_slotarr) + (size_t) l10, l13);
                VADER_WRITE_BARRIER(_a8_slotarr->buf);
                vader_array_t* _a9_slotarr = ((vader_array_t*) l7);
                VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l10)
                ((uint8_t*) _a9_slotarr->buf->slots)[vader_array_offset(_a9_slotarr) + (size_t) l10] = (uint8_t) true;
            }
        }
        l8 = (l8 + INT64_C(1));
    }
    l13 = vader_emit_bytecode$find_loop_ranges(l4);
    t4 = vader_array_length(((vader_array_t*) l13));
    if ((t4 > INT64_C(0))) {
        l17 = true;
        while (l17) {
            l17 = vader_emit_bytecode$extend_into_loops(l6, l7, l3, l13);
        }
    }
    l8 = INT64_C(0);
    while ((l8 < l2)) {
        l9 = ((int32_t) (int64_t) l5);
        vader_struct_vader_emit_bytecode$SlotRange_t* _a10_obj = (vader_struct_vader_emit_bytecode$SlotRange_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_bytecode$SlotRange_t));
        vader_obj_header_init(_a10_obj, 1389u);
        _a10_obj->f_first = INT32_C(0);
        _a10_obj->f_last = l9;
        l13 = (void*) _a10_obj;
        vader_array_t* _a11_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l8)
        vader_array_ref_store(_a11_slotarr->buf, vader_array_offset(_a11_slotarr) + (size_t) l8, l13);
        VADER_WRITE_BARRIER(_a11_slotarr->buf);
        vader_array_t* _a12_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a12_slotarr, l8)
        ((uint8_t*) _a12_slotarr->buf->slots)[vader_array_offset(_a12_slotarr) + (size_t) l8] = (uint8_t) true;
        l8 = (l8 + INT64_C(1));
    }
    vader_array_t* _a13_arr = vader_array_new(106u, 0u, 13u, 1185u);
    l13 = (void*) _a13_arr;
    vader_array_t* _a14_arr = vader_array_new(27u, 1u, 7u, 580u);
    ((int32_t*) _a14_arr->buf->slots)[vader_array_offset(_a14_arr) + 0u] = (int32_t) INT32_C(-1);
    t0 = (void*) _a14_arr;
    vader_array_t* _a15_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l3);
    l16 = (void*) _a15_arr;
    l8 = INT64_C(0);
    while ((l8 < l2)) {
        l9 = ((int32_t) (int64_t) l8);
        vader_array_t* _a16_slotarr = ((vader_array_t*) l16);
        VADER_ARRAY_RESOLVE_BUF(_a16_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a16_slotarr, l8)
        ((int32_t*) _a16_slotarr->buf->slots)[vader_array_offset(_a16_slotarr) + (size_t) l8] = (int32_t) l9;
        l8 = (l8 + INT64_C(1));
    }
    if ((INT64_C(0) < l2)) {
        l8 = l2;
    } else {
        l8 = INT64_C(0);
    }
    vader_array_t* _a17_arr = vader_array_reserve(234u, (int64_t) l8, 13u, 1389u);
    l18 = (void*) _a17_arr;
    l8 = INT64_C(0);
    while ((l8 < l2)) {
        vader_array_t* _a18_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a18_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a18_slotarr, l8)
        l19 = vader_array_ref_load_obj(_a18_slotarr->buf, vader_array_offset(_a18_slotarr) + (size_t) l8);
        vader_array_push_ref((vader_array_t*) l18, l19);
        l8 = (l8 + INT64_C(1));
    }
    l8 = l2;
    while ((l8 < l3)) {
        vader_array_t* _a19_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a19_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a19_slotarr, l8)
        t2 = ((uint8_t*) _a19_slotarr->buf->slots)[vader_array_offset(_a19_slotarr) + (size_t) l8];
        t3 = t2;
        if (t3) {
            vader_array_t* _a20_slotarr = ((vader_array_t*) l6);
            VADER_ARRAY_RESOLVE_BUF(_a20_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a20_slotarr, l8)
            l19 = vader_array_ref_load_obj(_a20_slotarr->buf, vader_array_offset(_a20_slotarr) + (size_t) l8);
            l20 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l1)->f_locals;
            l10 = vader_chk_sub(i64, l8, l2);
            vader_array_t* _a21_slotarr = ((vader_array_t*) l20);
            VADER_ARRAY_RESOLVE_BUF(_a21_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a21_slotarr, l10)
            t0 = vader_array_ref_load_obj(_a21_slotarr->buf, vader_array_offset(_a21_slotarr) + (size_t) l10);
            l21 = ((vader_struct_vader_core_bytecode$BcLocal_t*) t0)->f_val;
            l9 = INT32_C(-1);
            l22 = l2;
            l23 = vader_array_length(((vader_array_t*) l18));
            while ((l22 < l23)) {
                l24 = vader_chk_sub(i64, l22, l2);
                vader_array_t* _a22_slotarr = ((vader_array_t*) l13);
                VADER_ARRAY_RESOLVE_BUF(_a22_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a22_slotarr, l24)
                t0 = vader_array_ref_load_obj(_a22_slotarr->buf, vader_array_offset(_a22_slotarr) + (size_t) l24);
                if (((vader_struct_vader_core_bytecode$BcLocal_t*) t0)->f_val == l21) {
                    vader_array_t* _a23_slotarr = ((vader_array_t*) l18);
                    VADER_ARRAY_RESOLVE_BUF(_a23_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a23_slotarr, l22)
                    t0 = vader_array_ref_load_obj(_a23_slotarr->buf, vader_array_offset(_a23_slotarr) + (size_t) l22);
                    t2 = vader_emit_bytecode$ranges_overlap(t0, l19);
                    if (!(t2)) {
                        l9 = ((int32_t) (int64_t) l22);
                        break;
                    }
                }
                l22 = (l22 + INT64_C(1));
            }
            if ((l9 < INT32_C(0))) {
                t4 = vader_array_length(((vader_array_t*) l18));
                l9 = ((int32_t) (int64_t) t4);
                vader_array_push_ref((vader_array_t*) l18, l19);
                l25 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l1)->f_locals;
                l26 = vader_chk_sub(i64, l8, l2);
                vader_array_t* _a24_slotarr = ((vader_array_t*) l25);
                VADER_ARRAY_RESOLVE_BUF(_a24_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a24_slotarr, l26)
                l27 = vader_array_ref_load_obj(_a24_slotarr->buf, vader_array_offset(_a24_slotarr) + (size_t) l26);
                vader_array_push_ref((vader_array_t*) l13, l27);
            } else {
                vader_array_t* _a25_slotarr = ((vader_array_t*) l18);
                VADER_ARRAY_RESOLVE_BUF(_a25_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a25_slotarr, l9)
                l28 = vader_array_ref_load_obj(_a25_slotarr->buf, vader_array_offset(_a25_slotarr) + (size_t) l9);
                l12 = ((vader_struct_vader_emit_bytecode$SlotRange_t*) l19)->f_first;
                l14 = ((vader_struct_vader_emit_bytecode$SlotRange_t*) l28)->f_first;
                if ((l12 < l14)) {
                    l11 = ((vader_struct_vader_emit_bytecode$SlotRange_t*) l19)->f_first;
                } else {
                    l11 = ((vader_struct_vader_emit_bytecode$SlotRange_t*) l28)->f_first;
                }
                l29 = ((vader_struct_vader_emit_bytecode$SlotRange_t*) l19)->f_last;
                l30 = ((vader_struct_vader_emit_bytecode$SlotRange_t*) l28)->f_last;
                if ((l29 > l30)) {
                    l15 = ((vader_struct_vader_emit_bytecode$SlotRange_t*) l19)->f_last;
                } else {
                    l15 = ((vader_struct_vader_emit_bytecode$SlotRange_t*) l28)->f_last;
                }
                vader_struct_vader_emit_bytecode$SlotRange_t* _a26_obj = (vader_struct_vader_emit_bytecode$SlotRange_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_bytecode$SlotRange_t));
                vader_obj_header_init(_a26_obj, 1389u);
                _a26_obj->f_first = l11;
                _a26_obj->f_last = l15;
                l31 = (void*) _a26_obj;
                vader_array_t* _a27_slotarr = ((vader_array_t*) l18);
                VADER_ARRAY_RESOLVE_BUF(_a27_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a27_slotarr, l9)
                vader_array_ref_store(_a27_slotarr->buf, vader_array_offset(_a27_slotarr) + (size_t) l9, l31);
                VADER_WRITE_BARRIER(_a27_slotarr->buf);
            }
            vader_array_t* _a28_slotarr = ((vader_array_t*) l16);
            VADER_ARRAY_RESOLVE_BUF(_a28_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a28_slotarr, l8)
            ((int32_t*) _a28_slotarr->buf->slots)[vader_array_offset(_a28_slotarr) + (size_t) l8] = (int32_t) l9;
            l8 = vader_chk_add(i64, l8, INT64_C(1));
            continue;
        }
        vader_array_t* _a29_slotarr = ((vader_array_t*) l16);
        VADER_ARRAY_RESOLVE_BUF(_a29_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a29_slotarr, l8)
        ((int32_t*) _a29_slotarr->buf->slots)[vader_array_offset(_a29_slotarr) + (size_t) l8] = (int32_t) INT32_C(-1);
        l8 = vader_chk_add(i64, l8, INT64_C(1));
    }
    l17 = true;
    while ((l2 < l3)) {
        vader_array_t* _a30_slotarr = ((vader_array_t*) l16);
        VADER_ARRAY_RESOLVE_BUF(_a30_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a30_slotarr, l2)
        l9 = ((int32_t*) _a30_slotarr->buf->slots)[vader_array_offset(_a30_slotarr) + (size_t) l2];
        l11 = ((int32_t) (int64_t) l2);
        if (l9 != l11) {
            l17 = false;
            break;
        }
        l2 = (l2 + INT64_C(1));
    }
    if (l17) {
        { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a31_arr = vader_array_new(445u, 0u, 13u, 2295u);
    l6 = (void*) _a31_arr;
    l2 = INT64_C(0);
    while ((l2 < l5)) {
        vader_array_t* _a32_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a32_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a32_slotarr, l2)
        l32 = vader_array_ref_load_box(_a32_slotarr->buf, vader_array_offset(_a32_slotarr) + (size_t) l2);
        l9 = vader_core_bytecode$slot_touched(l32);
        if ((l9 >= INT32_C(0))) {
            vader_array_t* _a33_slotarr = ((vader_array_t*) l16);
            VADER_ARRAY_RESOLVE_BUF(_a33_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a33_slotarr, l9)
            l11 = ((int32_t*) _a33_slotarr->buf->slots)[vader_array_offset(_a33_slotarr) + (size_t) l9];
            if ((l11 >= INT32_C(0))) {
                l33 = vader_core_bytecode$with_remapped_slot(l32, l11);
                vader_array_push_ref((vader_array_t*) l6, l33.payload.obj);
            } else {
                vader_array_push_ref((vader_array_t*) l6, l32.payload.obj);
            }
        } else {
            l34 = vader_emit_bytecode$remap_push_cache_slot(l32, l16);
            vader_array_push_ref((vader_array_t*) l6, l34.payload.obj);
        }
        l2 = (l2 + INT64_C(1));
    }
    l4 = l1;
    l35 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l4)->f_name;
    l17 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l4)->f_is_main;
    l7 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l4)->f_signature;
    l16 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l4)->f_debug;
    l18 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l4)->f_jump_table;
    l4 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l4)->f_source_pc;
    vader_struct_vader_core_bytecode$BcFunction_t* _a34_obj = (vader_struct_vader_core_bytecode$BcFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcFunction_t));
    vader_obj_header_init(_a34_obj, 1182u);
    _a34_obj->f_name = l35;
    _a34_obj->f_is_main = l17;
    _a34_obj->f_signature = l7;
    _a34_obj->f_locals = l13;
    _a34_obj->f_body = l6;
    _a34_obj->f_debug = l16;
    _a34_obj->f_jump_table = l18;
    _a34_obj->f_source_pc = l4;
    t0 = (void*) _a34_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_emit_bytecode$ConstFoldStage$toolchain_stage$Stage$describe(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[7] = { &l0, &l1, &l2, &l3, &l4, &l5, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 7u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(29u, 0u, 1u, 582u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(29u, 0u, 1u, 582u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(29u, 0u, 1u, 582u);
    l3 = (void*) _a2_arr;
    t0 = (void*) &vader_data_79;
    vader_array_t* _a3_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
    l4 = vader_array_ref_load_obj(_a3_slotarr->buf, vader_array_offset(_a3_slotarr) + (size_t) INT64_C(0));
    t0 = (void*) &vader_data_80;
    vader_array_t* _a4_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
    l5 = vader_array_ref_load_obj(_a4_slotarr->buf, vader_array_offset(_a4_slotarr) + (size_t) INT64_C(0));
    vader_array_t* _a5_arr = vader_array_new(34u, 2u, 0u, 591u);
    vader_array_box_slots(_a5_arr->buf)[vader_array_offset(_a5_arr) + 1u] = vader_ref_box(l5);
    vader_array_box_slots(_a5_arr->buf)[vader_array_offset(_a5_arr) + 0u] = vader_ref_box(l4);
    l4 = (void*) _a5_arr;
    vader_struct_vader_emit_bytecode$BytecodeSpec_t* _a6_obj = (vader_struct_vader_emit_bytecode$BytecodeSpec_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_bytecode$BytecodeSpec_t));
    vader_obj_header_init(_a6_obj, 1375u);
    _a6_obj->f_name = 2204u;
    _a6_obj->f_requires = l1;
    _a6_obj->f_breaks = l2;
    _a6_obj->f_establishes = l3;
    _a6_obj->f_after = l4;
    t0 = (void*) _a6_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_emit_bytecode$ConstFoldStage$toolchain_stage$Stage$run(void* l0, void* l1) {
    void* l2 = NULL;
    void* l4 = NULL;
    void* l6 = NULL;
    void* l13 = NULL;
    void* l16 = NULL;
    void* l17 = NULL;
    int64_t l3, l5, l7;
    vader_box_t l8 = vader_box_null(), l9 = vader_box_null(), l11 = vader_box_null();
    int32_t l10, l12;
    vader_string_t l14 = 0;
    bool l15;
    void* t0 = NULL;
    vader_box_t* gc_roots[3] = { &l8, &l9, &l11 };
    void** gc_raw_roots[9] = { &l0, &l1, &l2, &l4, &l6, &l13, &l16, &l17, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l14 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 9u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l1)->f_body;
    l3 = vader_array_length(((vader_array_t*) l2));
    vader_array_t* _a0_arr = vader_array_new(445u, 0u, 13u, 2295u);
    l4 = (void*) _a0_arr;
    l5 = INT64_C(0);
    vader_array_t* _a1_arr = vader_array_new(27u, 1u, 7u, 580u);
    ((int32_t*) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 0u] = (int32_t) INT32_C(-1);
    t0 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l3);
    l6 = (void*) _a2_arr;
    l7 = INT64_C(0);
    while ((l7 < l3)) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        l8 = vader_array_ref_load_box(_a3_slotarr->buf, vader_array_offset(_a3_slotarr) + (size_t) l7);
        l9 = vader_emit_bytecode$try_fold_arith(l8, l4, l5);
        if (l9.tag == 0u) {
            vader_emit_bytecode$push_or_assign(l4, l5, l8);
            l10 = ((int32_t) (int64_t) l5);
            vader_array_t* _a4_slotarr = ((vader_array_t*) l6);
            VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l7)
            ((int32_t*) _a4_slotarr->buf->slots)[vader_array_offset(_a4_slotarr) + (size_t) l7] = (int32_t) l10;
            l5 = vader_chk_add(i64, l5, INT64_C(1));
        } else {
            l5 = vader_chk_sub(i64, l5, INT64_C(2));
            l11 = l9;
            vader_emit_bytecode$push_or_assign(l4, l5, l11);
            l12 = ((int32_t) (int64_t) l5);
            vader_array_t* _a5_slotarr = ((vader_array_t*) l6);
            VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l7)
            ((int32_t*) _a5_slotarr->buf->slots)[vader_array_offset(_a5_slotarr) + (size_t) l7] = (int32_t) l12;
            l5 = vader_chk_add(i64, l5, INT64_C(1));
        }
        l7 = (l7 + INT64_C(1));
    }
    vader_array_t* _a6_arr = vader_array_slice((vader_array_t*) l4, (int64_t) INT64_C(0), (int64_t) l5);
    l2 = (void*) _a6_arr;
    l4 = vader_core_bytecode$remap_jump_table(((vader_struct_vader_core_bytecode$BcFunction_t*) l1)->f_jump_table, l6, l5);
    l6 = vader_emit_bytecode$remap_debug(((vader_struct_vader_core_bytecode$BcFunction_t*) l1)->f_debug, l6, l5);
    l13 = l1;
    l14 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l13)->f_name;
    l15 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l13)->f_is_main;
    l16 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l13)->f_signature;
    l17 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l13)->f_locals;
    l13 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l13)->f_source_pc;
    vader_struct_vader_core_bytecode$BcFunction_t* _a7_obj = (vader_struct_vader_core_bytecode$BcFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcFunction_t));
    vader_obj_header_init(_a7_obj, 1182u);
    _a7_obj->f_name = l14;
    _a7_obj->f_is_main = l15;
    _a7_obj->f_signature = l16;
    _a7_obj->f_locals = l17;
    _a7_obj->f_body = l2;
    _a7_obj->f_debug = l6;
    _a7_obj->f_jump_table = l4;
    _a7_obj->f_source_pc = l13;
    t0 = (void*) _a7_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_emit_bytecode$DeadStoresStage$toolchain_stage$Stage$describe(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l3, &l4, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 6u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(29u, 1u, 1u, 582u);
    ((uint8_t*) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = (uint8_t) INT32_C(0);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(29u, 1u, 1u, 582u);
    ((uint8_t*) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 0u] = (uint8_t) INT32_C(2);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(29u, 0u, 1u, 582u);
    l3 = (void*) _a2_arr;
    t0 = (void*) &vader_data_81;
    vader_array_t* _a3_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
    t0 = vader_array_ref_load_obj(_a3_slotarr->buf, vader_array_offset(_a3_slotarr) + (size_t) INT64_C(0));
    vader_array_t* _a4_arr = vader_array_new(34u, 1u, 0u, 591u);
    vader_array_box_slots(_a4_arr->buf)[vader_array_offset(_a4_arr) + 0u] = vader_ref_box(t0);
    l4 = (void*) _a4_arr;
    vader_struct_vader_emit_bytecode$BytecodeSpec_t* _a5_obj = (vader_struct_vader_emit_bytecode$BytecodeSpec_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_bytecode$BytecodeSpec_t));
    vader_obj_header_init(_a5_obj, 1375u);
    _a5_obj->f_name = 2232u;
    _a5_obj->f_requires = l1;
    _a5_obj->f_breaks = l2;
    _a5_obj->f_establishes = l3;
    _a5_obj->f_after = l4;
    t0 = (void*) _a5_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_emit_bytecode$DeadStoresStage$toolchain_stage$Stage$run(void* l0, void* l1) {
    int64_t l2, l3, l6, l7;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l14 = NULL;
    void* l15 = NULL;
    void* l16 = NULL;
    void* l17 = NULL;
    void* l21 = NULL;
    void* l24 = NULL;
    void* l30 = NULL;
    vader_box_t l8 = vader_box_null(), l32 = vader_box_null();
    int32_t l9, l10, l11, l12, l18, l19, l20, l22, l23, l25, l26, l27, l28, l29, l31;
    bool l13;
    vader_string_t l33 = 0;
    void* t0 = NULL;
    int32_t t1;
    bool t2, t3;
    int64_t t4;
    vader_box_t* gc_roots[2] = { &l8, &l32 };
    void** gc_raw_roots[12] = { &l0, &l1, &l4, &l5, &l14, &l15, &l16, &l17, &l21, &l24, &l30, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l33 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 12u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l1)->f_signature)->f_params));
    l3 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l1)->f_locals));
    l3 = vader_chk_add(i64, l2, l3);
    vader_array_t* _a0_arr = vader_array_new(27u, 1u, 7u, 580u);
    ((int32_t*) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = (int32_t) INT32_C(0);
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l3);
    l4 = (void*) _a1_arr;
    l5 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l1)->f_body;
    l6 = vader_array_length(((vader_array_t*) l5));
    l7 = INT64_C(0);
    while ((l7 < l6)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        l8 = vader_array_ref_load_box(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l7);
        if (l8.tag == 1295u) {
            t0 = l8.payload.obj;
            l9 = ((vader_struct_vader_core_bytecode$LocalGet_t*) t0)->f_slot;
            vader_array_t* _a3_slotarr = ((vader_array_t*) l4);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l9)
            t1 = ((int32_t*) _a3_slotarr->buf->slots)[vader_array_offset(_a3_slotarr) + (size_t) l9];
            l10 = vader_chk_add(i32, t1, INT32_C(1));
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l9)
            ((int32_t*) _a3_slotarr->buf->slots)[vader_array_offset(_a3_slotarr) + (size_t) l9] = (int32_t) l10;
        }
        if (l8.tag == 1294u) {
            t0 = l8.payload.obj;
            l11 = ((vader_struct_vader_core_bytecode$LocalField_t*) t0)->f_slot;
            vader_array_t* _a4_slotarr = ((vader_array_t*) l4);
            VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l11)
            t1 = ((int32_t*) _a4_slotarr->buf->slots)[vader_array_offset(_a4_slotarr) + (size_t) l11];
            l12 = vader_chk_add(i32, t1, INT32_C(1));
            VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l11)
            ((int32_t*) _a4_slotarr->buf->slots)[vader_array_offset(_a4_slotarr) + (size_t) l11] = (int32_t) l12;
        }
        l7 = (l7 + INT64_C(1));
    }
    vader_array_t* _a5_arr = vader_array_new(24u, 1u, 12u, 575u);
    ((uint8_t*) _a5_arr->buf->slots)[vader_array_offset(_a5_arr) + 0u] = (uint8_t) false;
    t0 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l3);
    l5 = (void*) _a6_arr;
    l13 = false;
    l6 = l2;
    while ((l6 < l3)) {
        vader_array_t* _a7_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l6)
        t1 = ((int32_t*) _a7_slotarr->buf->slots)[vader_array_offset(_a7_slotarr) + (size_t) l6];
        if (t1 == INT32_C(0)) {
            vader_array_t* _a8_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l6)
            ((uint8_t*) _a8_slotarr->buf->slots)[vader_array_offset(_a8_slotarr) + (size_t) l6] = (uint8_t) true;
            l13 = true;
        }
        l6 = (l6 + INT64_C(1));
    }
    if (!(l13)) {
        { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a9_arr = vader_array_new(27u, 1u, 7u, 580u);
    ((int32_t*) _a9_arr->buf->slots)[vader_array_offset(_a9_arr) + 0u] = (int32_t) INT32_C(-1);
    t0 = (void*) _a9_arr;
    vader_array_t* _a10_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l3);
    l4 = (void*) _a10_arr;
    l9 = INT32_C(0);
    l6 = INT64_C(0);
    while ((l6 < l3)) {
        vader_array_t* _a11_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l6)
        t2 = ((uint8_t*) _a11_slotarr->buf->slots)[vader_array_offset(_a11_slotarr) + (size_t) l6];
        t3 = t2;
        if (!(t3)) {
            vader_array_t* _a12_slotarr = ((vader_array_t*) l4);
            VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a12_slotarr, l6)
            ((int32_t*) _a12_slotarr->buf->slots)[vader_array_offset(_a12_slotarr) + (size_t) l6] = (int32_t) l9;
            l9 = vader_chk_add(i32, l9, INT32_C(1));
        }
        l6 = (l6 + INT64_C(1));
    }
    vader_array_t* _a13_arr = vader_array_new(445u, 0u, 13u, 2295u);
    l14 = (void*) _a13_arr;
    l6 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l1)->f_body));
    vader_array_t* _a14_arr = vader_array_new(27u, 1u, 7u, 580u);
    ((int32_t*) _a14_arr->buf->slots)[vader_array_offset(_a14_arr) + 0u] = (int32_t) INT32_C(-1);
    t0 = (void*) _a14_arr;
    vader_array_t* _a15_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l6);
    l15 = (void*) _a15_arr;
    l7 = INT64_C(0);
    while ((l7 < l6)) {
        vader_array_t* _a16_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l1)->f_body);
        VADER_ARRAY_RESOLVE_BUF(_a16_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a16_slotarr, l7)
        l8 = vader_array_ref_load_box(_a16_slotarr->buf, vader_array_offset(_a16_slotarr) + (size_t) l7);
        if (l8.tag == 1296u) {
            t0 = l8.payload.obj;
            l9 = ((vader_struct_vader_core_bytecode$LocalSet_t*) t0)->f_slot;
            vader_array_t* _a17_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a17_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a17_slotarr, l9)
            t2 = ((uint8_t*) _a17_slotarr->buf->slots)[vader_array_offset(_a17_slotarr) + (size_t) l9];
            t3 = t2;
            if (t3) {
                t4 = vader_array_length(((vader_array_t*) l14));
                l10 = ((int32_t) (int64_t) t4);
                vader_array_t* _a18_slotarr = ((vader_array_t*) l15);
                VADER_ARRAY_RESOLVE_BUF(_a18_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a18_slotarr, l7)
                ((int32_t*) _a18_slotarr->buf->slots)[vader_array_offset(_a18_slotarr) + (size_t) l7] = (int32_t) l10;
                t0 = (void*) &vader_data_100;
                vader_array_t* _a19_slotarr = ((vader_array_t*) t0);
                VADER_ARRAY_RESOLVE_BUF(_a19_slotarr)
                l16 = vader_array_ref_load_obj(_a19_slotarr->buf, vader_array_offset(_a19_slotarr) + (size_t) INT64_C(0));
                vader_array_push_ref((vader_array_t*) l14, l16);
            } else {
                t4 = vader_array_length(((vader_array_t*) l14));
                l11 = ((int32_t) (int64_t) t4);
                vader_array_t* _a20_slotarr = ((vader_array_t*) l15);
                VADER_ARRAY_RESOLVE_BUF(_a20_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a20_slotarr, l7)
                ((int32_t*) _a20_slotarr->buf->slots)[vader_array_offset(_a20_slotarr) + (size_t) l7] = (int32_t) l11;
                t0 = l8.payload.obj;
                l12 = ((vader_struct_vader_core_bytecode$LocalSet_t*) t0)->f_slot;
                vader_array_t* _a21_slotarr = ((vader_array_t*) l4);
                VADER_ARRAY_RESOLVE_BUF(_a21_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a21_slotarr, l12)
                t1 = ((int32_t*) _a21_slotarr->buf->slots)[vader_array_offset(_a21_slotarr) + (size_t) l12];
                vader_struct_vader_core_bytecode$LocalSet_t* _a22_obj = (vader_struct_vader_core_bytecode$LocalSet_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$LocalSet_t));
                vader_obj_header_init(_a22_obj, 1296u);
                _a22_obj->f_slot = t1;
                l17 = (void*) _a22_obj;
                vader_array_push_ref((vader_array_t*) l14, l17);
            }
            l7 = vader_chk_add(i64, l7, INT64_C(1));
            continue;
        }
        if (l8.tag == 1297u) {
            t0 = l8.payload.obj;
            l18 = ((vader_struct_vader_core_bytecode$LocalTee_t*) t0)->f_slot;
            vader_array_t* _a23_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a23_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a23_slotarr, l18)
            t2 = ((uint8_t*) _a23_slotarr->buf->slots)[vader_array_offset(_a23_slotarr) + (size_t) l18];
            t3 = t2;
            if (t3) {
                l7 = vader_chk_add(i64, l7, INT64_C(1));
                continue;
            }
            t4 = vader_array_length(((vader_array_t*) l14));
            l19 = ((int32_t) (int64_t) t4);
            vader_array_t* _a24_slotarr = ((vader_array_t*) l15);
            VADER_ARRAY_RESOLVE_BUF(_a24_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a24_slotarr, l7)
            ((int32_t*) _a24_slotarr->buf->slots)[vader_array_offset(_a24_slotarr) + (size_t) l7] = (int32_t) l19;
            t0 = l8.payload.obj;
            l20 = ((vader_struct_vader_core_bytecode$LocalTee_t*) t0)->f_slot;
            vader_array_t* _a25_slotarr = ((vader_array_t*) l4);
            VADER_ARRAY_RESOLVE_BUF(_a25_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a25_slotarr, l20)
            t1 = ((int32_t*) _a25_slotarr->buf->slots)[vader_array_offset(_a25_slotarr) + (size_t) l20];
            vader_struct_vader_core_bytecode$LocalTee_t* _a26_obj = (vader_struct_vader_core_bytecode$LocalTee_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$LocalTee_t));
            vader_obj_header_init(_a26_obj, 1297u);
            _a26_obj->f_slot = t1;
            l21 = (void*) _a26_obj;
            vader_array_push_ref((vader_array_t*) l14, l21);
            l7 = vader_chk_add(i64, l7, INT64_C(1));
            continue;
        }
        if (l8.tag == 1295u) {
            t4 = vader_array_length(((vader_array_t*) l14));
            l22 = ((int32_t) (int64_t) t4);
            vader_array_t* _a27_slotarr = ((vader_array_t*) l15);
            VADER_ARRAY_RESOLVE_BUF(_a27_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a27_slotarr, l7)
            ((int32_t*) _a27_slotarr->buf->slots)[vader_array_offset(_a27_slotarr) + (size_t) l7] = (int32_t) l22;
            t0 = l8.payload.obj;
            l23 = ((vader_struct_vader_core_bytecode$LocalGet_t*) t0)->f_slot;
            vader_array_t* _a28_slotarr = ((vader_array_t*) l4);
            VADER_ARRAY_RESOLVE_BUF(_a28_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a28_slotarr, l23)
            t1 = ((int32_t*) _a28_slotarr->buf->slots)[vader_array_offset(_a28_slotarr) + (size_t) l23];
            vader_struct_vader_core_bytecode$LocalGet_t* _a29_obj = (vader_struct_vader_core_bytecode$LocalGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$LocalGet_t));
            vader_obj_header_init(_a29_obj, 1295u);
            _a29_obj->f_slot = t1;
            l24 = (void*) _a29_obj;
            vader_array_push_ref((vader_array_t*) l14, l24);
            l7 = vader_chk_add(i64, l7, INT64_C(1));
            continue;
        }
        if (l8.tag == 1294u) {
            t4 = vader_array_length(((vader_array_t*) l14));
            l25 = ((int32_t) (int64_t) t4);
            vader_array_t* _a30_slotarr = ((vader_array_t*) l15);
            VADER_ARRAY_RESOLVE_BUF(_a30_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a30_slotarr, l7)
            ((int32_t*) _a30_slotarr->buf->slots)[vader_array_offset(_a30_slotarr) + (size_t) l7] = (int32_t) l25;
            t0 = l8.payload.obj;
            l26 = ((vader_struct_vader_core_bytecode$LocalField_t*) t0)->f_slot;
            vader_array_t* _a31_slotarr = ((vader_array_t*) l4);
            VADER_ARRAY_RESOLVE_BUF(_a31_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a31_slotarr, l26)
            l27 = ((int32_t*) _a31_slotarr->buf->slots)[vader_array_offset(_a31_slotarr) + (size_t) l26];
            t0 = l8.payload.obj;
            l28 = ((vader_struct_vader_core_bytecode$LocalField_t*) t0)->f_type_id;
            t0 = l8.payload.obj;
            l29 = ((vader_struct_vader_core_bytecode$LocalField_t*) t0)->f_field_index;
            vader_struct_vader_core_bytecode$LocalField_t* _a32_obj = (vader_struct_vader_core_bytecode$LocalField_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$LocalField_t));
            vader_obj_header_init(_a32_obj, 1294u);
            _a32_obj->f_slot = l27;
            _a32_obj->f_type_id = l28;
            _a32_obj->f_field_index = l29;
            l30 = (void*) _a32_obj;
            vader_array_push_ref((vader_array_t*) l14, l30);
            l7 = vader_chk_add(i64, l7, INT64_C(1));
            continue;
        }
        t4 = vader_array_length(((vader_array_t*) l14));
        l31 = ((int32_t) (int64_t) t4);
        vader_array_t* _a33_slotarr = ((vader_array_t*) l15);
        VADER_ARRAY_RESOLVE_BUF(_a33_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a33_slotarr, l7)
        ((int32_t*) _a33_slotarr->buf->slots)[vader_array_offset(_a33_slotarr) + (size_t) l7] = (int32_t) l31;
        l32 = vader_emit_bytecode$remap_push_cache_slot(l8, l4);
        vader_array_push_ref((vader_array_t*) l14, l32.payload.obj);
        l7 = vader_chk_add(i64, l7, INT64_C(1));
    }
    l4 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l1)->f_jump_table;
    l6 = vader_array_length(((vader_array_t*) l14));
    l4 = vader_core_bytecode$remap_jump_table(l4, l15, l6);
    l16 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l1)->f_debug;
    l6 = vader_array_length(((vader_array_t*) l14));
    l15 = vader_emit_bytecode$remap_debug(l16, l15, l6);
    vader_array_t* _a34_arr = vader_array_new(106u, 0u, 13u, 1185u);
    l16 = (void*) _a34_arr;
    l6 = l2;
    while ((l6 < l3)) {
        vader_array_t* _a35_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a35_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a35_slotarr, l6)
        t2 = ((uint8_t*) _a35_slotarr->buf->slots)[vader_array_offset(_a35_slotarr) + (size_t) l6];
        t3 = t2;
        if (!(t3)) {
            l17 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l1)->f_locals;
            l7 = vader_chk_sub(i64, l6, l2);
            vader_array_t* _a36_slotarr = ((vader_array_t*) l17);
            VADER_ARRAY_RESOLVE_BUF(_a36_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a36_slotarr, l7)
            l21 = vader_array_ref_load_obj(_a36_slotarr->buf, vader_array_offset(_a36_slotarr) + (size_t) l7);
            vader_array_push_ref((vader_array_t*) l16, l21);
        }
        l6 = (l6 + INT64_C(1));
    }
    l5 = l1;
    l33 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l5)->f_name;
    l13 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l5)->f_is_main;
    l17 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l5)->f_signature;
    l5 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l5)->f_source_pc;
    vader_struct_vader_core_bytecode$BcFunction_t* _a37_obj = (vader_struct_vader_core_bytecode$BcFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcFunction_t));
    vader_obj_header_init(_a37_obj, 1182u);
    _a37_obj->f_name = l33;
    _a37_obj->f_is_main = l13;
    _a37_obj->f_signature = l17;
    _a37_obj->f_locals = l16;
    _a37_obj->f_body = l14;
    _a37_obj->f_debug = l15;
    _a37_obj->f_jump_table = l4;
    _a37_obj->f_source_pc = l5;
    t0 = (void*) _a37_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_emit_bytecode$PeepholeStage$toolchain_stage$Stage$describe(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l3, &l4, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 6u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(29u, 3u, 1u, 582u);
    ((uint8_t*) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 2u] = (uint8_t) INT32_C(2);
    ((uint8_t*) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 1u] = (uint8_t) INT32_C(1);
    ((uint8_t*) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = (uint8_t) INT32_C(0);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(29u, 0u, 1u, 582u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(29u, 0u, 1u, 582u);
    l3 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(34u, 0u, 0u, 591u);
    l4 = (void*) _a3_arr;
    vader_struct_vader_emit_bytecode$BytecodeSpec_t* _a4_obj = (vader_struct_vader_emit_bytecode$BytecodeSpec_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_bytecode$BytecodeSpec_t));
    vader_obj_header_init(_a4_obj, 1375u);
    _a4_obj->f_name = 2950u;
    _a4_obj->f_requires = l1;
    _a4_obj->f_breaks = l2;
    _a4_obj->f_establishes = l3;
    _a4_obj->f_after = l4;
    t0 = (void*) _a4_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_emit_bytecode$PeepholeStage$toolchain_stage$Stage$run(void* l0, void* l1) {
    bool l2, l22, l25, l26, l27, l28;
    void* l3 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    void* l18 = NULL;
    void* l19 = NULL;
    void* l30 = NULL;
    void* l36 = NULL;
    void* l39 = NULL;
    int64_t l4, l5, l6, l20, l23, l24, l29, l31, l32, l33, l35, l37;
    vader_box_t l11 = vader_box_null(), l21 = vader_box_null(), l34 = vader_box_null(), l38 = vader_box_null();
    int32_t l12, l13, l14, l15, l16, l17, l40;
    vader_string_t l41 = 0;
    int64_t t0;
    void* t1 = NULL;
    int32_t t2;
    vader_box_t t3 = vader_box_null(), t4 = vader_box_null();
    bool t5;
    vader_box_t* gc_roots[6] = { &l11, &l21, &l34, &l38, &t3, &t4 };
    void** gc_raw_roots[13] = {
        &l0, &l1, &l3, &l7, &l8, &l9, &l10, &l18, &l19, &l30, &l36, &l39, &t1,
    };
    vader_string_t* gc_atom_roots[1] = { &l41 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 6u, 13u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_core_bytecode$bc_result_arity(((vader_struct_vader_core_bytecode$BcFunction_t*) l1)->f_signature);
    l2 = (t0 > INT64_C(1));
    l3 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l1)->f_body;
    l4 = vader_array_length(((vader_array_t*) l3));
    l5 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l1)->f_signature)->f_params));
    l6 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l1)->f_locals));
    l5 = vader_chk_add(i64, l5, l6);
    vader_array_t* _a0_arr = vader_array_new(27u, 1u, 7u, 580u);
    ((int32_t*) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = (int32_t) INT32_C(0);
    t1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t1, (int64_t) l5);
    l7 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(27u, 1u, 7u, 580u);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 0u] = (int32_t) INT32_C(0);
    t1 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_repeat((vader_array_t*) t1, (int64_t) l5);
    l8 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_new(27u, 1u, 7u, 580u);
    ((int32_t*) _a4_arr->buf->slots)[vader_array_offset(_a4_arr) + 0u] = (int32_t) INT32_C(0);
    t1 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_repeat((vader_array_t*) t1, (int64_t) l5);
    l9 = (void*) _a5_arr;
    l10 = l3;
    l5 = vader_array_length(((vader_array_t*) l10));
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a6_slotarr = ((vader_array_t*) l10);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        l11 = vader_array_ref_load_box(_a6_slotarr->buf, vader_array_offset(_a6_slotarr) + (size_t) l6);
        if (l11.tag == 1296u) {
            t1 = l11.payload.obj;
            l12 = ((vader_struct_vader_core_bytecode$LocalSet_t*) t1)->f_slot;
            vader_array_t* _a7_slotarr = ((vader_array_t*) l7);
            VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l12)
            t2 = ((int32_t*) _a7_slotarr->buf->slots)[vader_array_offset(_a7_slotarr) + (size_t) l12];
            l13 = vader_chk_add(i32, t2, INT32_C(1));
            VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l12)
            ((int32_t*) _a7_slotarr->buf->slots)[vader_array_offset(_a7_slotarr) + (size_t) l12] = (int32_t) l13;
        }
        if (l11.tag == 1295u) {
            t1 = l11.payload.obj;
            l14 = ((vader_struct_vader_core_bytecode$LocalGet_t*) t1)->f_slot;
            vader_array_t* _a8_slotarr = ((vader_array_t*) l8);
            VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l14)
            t2 = ((int32_t*) _a8_slotarr->buf->slots)[vader_array_offset(_a8_slotarr) + (size_t) l14];
            l15 = vader_chk_add(i32, t2, INT32_C(1));
            VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l14)
            ((int32_t*) _a8_slotarr->buf->slots)[vader_array_offset(_a8_slotarr) + (size_t) l14] = (int32_t) l15;
        }
        if (l11.tag == 1297u) {
            t1 = l11.payload.obj;
            l16 = ((vader_struct_vader_core_bytecode$LocalTee_t*) t1)->f_slot;
            vader_array_t* _a9_slotarr = ((vader_array_t*) l9);
            VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l16)
            t2 = ((int32_t*) _a9_slotarr->buf->slots)[vader_array_offset(_a9_slotarr) + (size_t) l16];
            l17 = vader_chk_add(i32, t2, INT32_C(1));
            VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l16)
            ((int32_t*) _a9_slotarr->buf->slots)[vader_array_offset(_a9_slotarr) + (size_t) l16] = (int32_t) l17;
        }
        l6 = (l6 + INT64_C(1));
    }
    l10 = vader_core_bytecode$mark_jump_targets(((vader_struct_vader_core_bytecode$BcFunction_t*) l1)->f_jump_table, l4);
    vader_array_t* _a10_arr = vader_array_new(445u, 0u, 13u, 2295u);
    l18 = (void*) _a10_arr;
    l5 = INT64_C(0);
    vader_array_t* _a11_arr = vader_array_new(27u, 1u, 7u, 580u);
    ((int32_t*) _a11_arr->buf->slots)[vader_array_offset(_a11_arr) + 0u] = (int32_t) INT32_C(-1);
    t1 = (void*) _a11_arr;
    vader_array_t* _a12_arr = vader_array_repeat((vader_array_t*) t1, (int64_t) l4);
    l19 = (void*) _a12_arr;
    l6 = INT64_C(0);
    while ((l6 < l4)) {
        vader_array_t* _a13_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
        l11 = vader_array_ref_load_box(_a13_slotarr->buf, vader_array_offset(_a13_slotarr) + (size_t) l6);
        if (l11.tag == 1296u) {
            t0 = vader_chk_add(i64, l6, INT64_C(1));
            if ((t0 < l4)) {
                l20 = vader_chk_add(i64, l6, INT64_C(1));
                vader_array_t* _a14_slotarr = ((vader_array_t*) l3);
                VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a14_slotarr, l20)
                l21 = vader_array_ref_load_box(_a14_slotarr->buf, vader_array_offset(_a14_slotarr) + (size_t) l20);
                if (l21.tag == 1295u) {
                    t1 = l21.payload.obj;
                    l12 = ((vader_struct_vader_core_bytecode$LocalGet_t*) t1)->f_slot;
                    t1 = l11.payload.obj;
                    l13 = ((vader_struct_vader_core_bytecode$LocalSet_t*) t1)->f_slot;
                    if (l12 == l13) {
                        l22 = false;
                        if ((l5 > INT64_C(0))) {
                            l23 = vader_chk_sub(i64, l5, INT64_C(1));
                            vader_array_t* _a15_slotarr = ((vader_array_t*) l18);
                            VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
                            VADER_ARRAY_CHECK_INDEX(_a15_slotarr, l23)
                            t3 = vader_array_ref_load_box(_a15_slotarr->buf, vader_array_offset(_a15_slotarr) + (size_t) l23);
                            t4 = vader_core_bytecode$const_op_of(t3);
                            if (!(t4.tag == 0u)) {
                                l22 = true;
                            }
                        }
                        t1 = l11.payload.obj;
                        t2 = ((vader_struct_vader_core_bytecode$LocalSet_t*) t1)->f_slot;
                        l24 = ((int64_t) (int32_t) t2);
                        vader_array_t* _a16_slotarr = ((vader_array_t*) l7);
                        VADER_ARRAY_RESOLVE_BUF(_a16_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a16_slotarr, l24)
                        t2 = ((int32_t*) _a16_slotarr->buf->slots)[vader_array_offset(_a16_slotarr) + (size_t) l24];
                        if (t2 == INT32_C(1)) {
                            vader_array_t* _a17_slotarr = ((vader_array_t*) l8);
                            VADER_ARRAY_RESOLVE_BUF(_a17_slotarr)
                            VADER_ARRAY_CHECK_INDEX(_a17_slotarr, l24)
                            t2 = ((int32_t*) _a17_slotarr->buf->slots)[vader_array_offset(_a17_slotarr) + (size_t) l24];
                            l26 = t2 == INT32_C(1);
                        } else {
                            l26 = false;
                        }
                        if (l26) {
                            vader_array_t* _a18_slotarr = ((vader_array_t*) l9);
                            VADER_ARRAY_RESOLVE_BUF(_a18_slotarr)
                            VADER_ARRAY_CHECK_INDEX(_a18_slotarr, l24)
                            t2 = ((int32_t*) _a18_slotarr->buf->slots)[vader_array_offset(_a18_slotarr) + (size_t) l24];
                            l25 = t2 == INT32_C(0);
                        } else {
                            l25 = false;
                        }
                        if (l22) {
                            l28 = l25;
                        } else {
                            l28 = false;
                        }
                        if (l28) {
                            l27 = true;
                        } else {
                            l29 = vader_chk_add(i64, l6, INT64_C(1));
                            vader_array_t* _a19_slotarr = ((vader_array_t*) l10);
                            VADER_ARRAY_RESOLVE_BUF(_a19_slotarr)
                            VADER_ARRAY_CHECK_INDEX(_a19_slotarr, l29)
                            t5 = ((uint8_t*) _a19_slotarr->buf->slots)[vader_array_offset(_a19_slotarr) + (size_t) l29];
                            l27 = t5;
                        }
                        if (!(l27)) {
                            t1 = l11.payload.obj;
                            t2 = ((vader_struct_vader_core_bytecode$LocalSet_t*) t1)->f_slot;
                            vader_struct_vader_core_bytecode$LocalTee_t* _a20_obj = (vader_struct_vader_core_bytecode$LocalTee_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$LocalTee_t));
                            vader_obj_header_init(_a20_obj, 1297u);
                            _a20_obj->f_slot = t2;
                            l30 = (void*) _a20_obj;
                            vader_emit_bytecode$push_or_assign(l18, l5, vader_ref_box(l30));
                            l14 = ((int32_t) (int64_t) l5);
                            vader_array_t* _a21_slotarr = ((vader_array_t*) l19);
                            VADER_ARRAY_RESOLVE_BUF(_a21_slotarr)
                            VADER_ARRAY_CHECK_INDEX(_a21_slotarr, l6)
                            ((int32_t*) _a21_slotarr->buf->slots)[vader_array_offset(_a21_slotarr) + (size_t) l6] = (int32_t) l14;
                            l31 = vader_chk_add(i64, l6, INT64_C(1));
                            l15 = ((int32_t) (int64_t) l5);
                            VADER_ARRAY_CHECK_INDEX(_a21_slotarr, l31)
                            ((int32_t*) _a21_slotarr->buf->slots)[vader_array_offset(_a21_slotarr) + (size_t) l31] = (int32_t) l15;
                            l5 = vader_chk_add(i64, l5, INT64_C(1));
                            l6 = vader_chk_add(i64, l6, INT64_C(2));
                            continue;
                        }
                    }
                }
            }
        }
        if (l11.tag == 1307u) {
            if (!(l2)) {
                l32 = vader_array_length(((vader_array_t*) l18));
                if ((l32 > INT64_C(0))) {
                    l33 = vader_chk_sub(i64, l32, INT64_C(1));
                    vader_array_t* _a22_slotarr = ((vader_array_t*) l18);
                    VADER_ARRAY_RESOLVE_BUF(_a22_slotarr)
                    t3 = vader_array_ref_load_box(_a22_slotarr->buf, vader_array_offset(_a22_slotarr) + (size_t) l33);
                    l34 = vader_core_bytecode$const_op_of(t3);
                    if (!(l34.tag == 0u)) {
                        l35 = vader_chk_sub(i64, l32, INT64_C(1));
                        vader_struct_vader_core_bytecode$ReturnLit_t* _a23_obj = (vader_struct_vader_core_bytecode$ReturnLit_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$ReturnLit_t));
                        vader_obj_header_init(_a23_obj, 1308u);
                        _a23_obj->f_value = l34;
                        l36 = (void*) _a23_obj;
                        vader_array_t* _a24_slotarr = ((vader_array_t*) l18);
                        VADER_ARRAY_RESOLVE_BUF(_a24_slotarr)
                        vader_array_ref_store(_a24_slotarr->buf, vader_array_offset(_a24_slotarr) + (size_t) l35, l36);
                        VADER_WRITE_BARRIER(_a24_slotarr->buf);
                        t0 = vader_chk_sub(i64, l5, INT64_C(1));
                        l16 = ((int32_t) (int64_t) t0);
                        vader_array_t* _a25_slotarr = ((vader_array_t*) l19);
                        VADER_ARRAY_RESOLVE_BUF(_a25_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a25_slotarr, l6)
                        ((int32_t*) _a25_slotarr->buf->slots)[vader_array_offset(_a25_slotarr) + (size_t) l6] = (int32_t) l16;
                        l6 = vader_chk_add(i64, l6, INT64_C(1));
                        continue;
                    }
                }
            }
        }
        if (l11.tag == 1204u) {
            if ((l5 > INT64_C(0))) {
                l37 = vader_chk_sub(i64, l5, INT64_C(1));
                vader_array_t* _a26_slotarr = ((vader_array_t*) l18);
                VADER_ARRAY_RESOLVE_BUF(_a26_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a26_slotarr, l37)
                l38 = vader_array_ref_load_box(_a26_slotarr->buf, vader_array_offset(_a26_slotarr) + (size_t) l37);
                if (l38.tag == 1204u) {
                    vader_array_t* _a27_slotarr = ((vader_array_t*) l19);
                    VADER_ARRAY_RESOLVE_BUF(_a27_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a27_slotarr, l6)
                    ((int32_t*) _a27_slotarr->buf->slots)[vader_array_offset(_a27_slotarr) + (size_t) l6] = (int32_t) INT32_C(-1);
                    l5 = vader_chk_sub(i64, l5, INT64_C(1));
                    l6 = vader_chk_add(i64, l6, INT64_C(1));
                    continue;
                }
                if (l38.tag == 1201u) {
                    t1 = l38.payload.obj;
                    t5 = ((vader_struct_vader_core_bytecode$BoolConst_t*) t1)->f_value;
                    vader_struct_vader_core_bytecode$BoolConst_t* _a28_obj = (vader_struct_vader_core_bytecode$BoolConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BoolConst_t));
                    vader_obj_header_init(_a28_obj, 1201u);
                    _a28_obj->f_value = !(t5);
                    l39 = (void*) _a28_obj;
                    vader_array_t* _a29_slotarr = ((vader_array_t*) l18);
                    VADER_ARRAY_RESOLVE_BUF(_a29_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a29_slotarr, l37)
                    vader_array_ref_store(_a29_slotarr->buf, vader_array_offset(_a29_slotarr) + (size_t) l37, l39);
                    VADER_WRITE_BARRIER(_a29_slotarr->buf);
                    l17 = ((int32_t) (int64_t) l37);
                    vader_array_t* _a30_slotarr = ((vader_array_t*) l19);
                    VADER_ARRAY_RESOLVE_BUF(_a30_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a30_slotarr, l6)
                    ((int32_t*) _a30_slotarr->buf->slots)[vader_array_offset(_a30_slotarr) + (size_t) l6] = (int32_t) l17;
                    l6 = vader_chk_add(i64, l6, INT64_C(1));
                    continue;
                }
            }
        }
        vader_emit_bytecode$push_or_assign(l18, l5, l11);
        l40 = ((int32_t) (int64_t) l5);
        vader_array_t* _a31_slotarr = ((vader_array_t*) l19);
        VADER_ARRAY_RESOLVE_BUF(_a31_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a31_slotarr, l6)
        ((int32_t*) _a31_slotarr->buf->slots)[vader_array_offset(_a31_slotarr) + (size_t) l6] = (int32_t) l40;
        l5 = vader_chk_add(i64, l5, INT64_C(1));
        l6 = vader_chk_add(i64, l6, INT64_C(1));
    }
    vader_array_t* _a32_arr = vader_array_slice((vader_array_t*) l18, (int64_t) INT64_C(0), (int64_t) l5);
    l3 = (void*) _a32_arr;
    l7 = vader_core_bytecode$remap_jump_table(((vader_struct_vader_core_bytecode$BcFunction_t*) l1)->f_jump_table, l19, l5);
    l8 = vader_emit_bytecode$remap_debug(((vader_struct_vader_core_bytecode$BcFunction_t*) l1)->f_debug, l19, l5);
    l9 = l1;
    l41 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l9)->f_name;
    l2 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l9)->f_is_main;
    l10 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l9)->f_signature;
    l18 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l9)->f_locals;
    l9 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l9)->f_source_pc;
    vader_struct_vader_core_bytecode$BcFunction_t* _a33_obj = (vader_struct_vader_core_bytecode$BcFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcFunction_t));
    vader_obj_header_init(_a33_obj, 1182u);
    _a33_obj->f_name = l41;
    _a33_obj->f_is_main = l2;
    _a33_obj->f_signature = l10;
    _a33_obj->f_locals = l18;
    _a33_obj->f_body = l3;
    _a33_obj->f_debug = l8;
    _a33_obj->f_jump_table = l7;
    _a33_obj->f_source_pc = l9;
    t1 = (void*) _a33_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_emit_bytecode$PropagateStage$toolchain_stage$Stage$describe(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l3, &l4, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 6u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(29u, 1u, 1u, 582u);
    ((uint8_t*) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = (uint8_t) INT32_C(0);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(29u, 0u, 1u, 582u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(29u, 1u, 1u, 582u);
    ((uint8_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 0u] = (uint8_t) INT32_C(1);
    l3 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(34u, 0u, 0u, 591u);
    l4 = (void*) _a3_arr;
    vader_struct_vader_emit_bytecode$BytecodeSpec_t* _a4_obj = (vader_struct_vader_emit_bytecode$BytecodeSpec_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_bytecode$BytecodeSpec_t));
    vader_obj_header_init(_a4_obj, 1375u);
    _a4_obj->f_name = 2963u;
    _a4_obj->f_requires = l1;
    _a4_obj->f_breaks = l2;
    _a4_obj->f_establishes = l3;
    _a4_obj->f_after = l4;
    t0 = (void*) _a4_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_emit_bytecode$PropagateStage$toolchain_stage$Stage$run(void* l0, void* l1) {
    void* l2 = NULL;
    int64_t l3;
    int64_t t0;
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = l1;
    t0 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l2)->f_body));
    l3 = vader_chk_add(i64, t0, INT64_C(1));
    for (;;) {
        t0 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l2)->f_body));
        if ((t0 < l3)) {
            l3 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l2)->f_body));
            l2 = vader_emit_bytecode$propagated_once(l2);
            continue;
        }
        break;
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_emit_bytecode$ReturnLitStage$toolchain_stage$Stage$describe(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l3, &l4, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 6u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(29u, 0u, 1u, 582u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(29u, 0u, 1u, 582u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(29u, 0u, 1u, 582u);
    l3 = (void*) _a2_arr;
    t0 = (void*) &vader_data_82;
    vader_array_t* _a3_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
    t0 = vader_array_ref_load_obj(_a3_slotarr->buf, vader_array_offset(_a3_slotarr) + (size_t) INT64_C(0));
    vader_array_t* _a4_arr = vader_array_new(34u, 1u, 0u, 591u);
    vader_array_box_slots(_a4_arr->buf)[vader_array_offset(_a4_arr) + 0u] = vader_ref_box(t0);
    l4 = (void*) _a4_arr;
    vader_struct_vader_emit_bytecode$BytecodeSpec_t* _a5_obj = (vader_struct_vader_emit_bytecode$BytecodeSpec_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_bytecode$BytecodeSpec_t));
    vader_obj_header_init(_a5_obj, 1375u);
    _a5_obj->f_name = 3022u;
    _a5_obj->f_requires = l1;
    _a5_obj->f_breaks = l2;
    _a5_obj->f_establishes = l3;
    _a5_obj->f_after = l4;
    t0 = (void*) _a5_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_emit_bytecode$ReturnLitStage$toolchain_stage$Stage$run(void* l0, void* l1) {
    void* l2 = NULL;
    void* l4 = NULL;
    void* l6 = NULL;
    void* l13 = NULL;
    void* l18 = NULL;
    void* l19 = NULL;
    int64_t l3, l5, l7, l9, l10, l12;
    vader_box_t l8 = vader_box_null(), l11 = vader_box_null();
    int32_t l14, l15;
    vader_string_t l16 = 0;
    bool l17;
    int64_t t0;
    void* t1 = NULL;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l8, &l11, &t2 };
    void** gc_raw_roots[9] = { &l0, &l1, &l2, &l4, &l6, &l13, &l18, &l19, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l16 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 9u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_core_bytecode$bc_result_arity(((vader_struct_vader_core_bytecode$BcFunction_t*) l1)->f_signature);
    if ((t0 > INT64_C(1))) {
        { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l1)->f_body;
    l3 = vader_array_length(((vader_array_t*) l2));
    vader_array_t* _a0_arr = vader_array_new(445u, 0u, 13u, 2295u);
    l4 = (void*) _a0_arr;
    l5 = INT64_C(0);
    vader_array_t* _a1_arr = vader_array_new(27u, 1u, 7u, 580u);
    ((int32_t*) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 0u] = (int32_t) INT32_C(-1);
    t1 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_repeat((vader_array_t*) t1, (int64_t) l3);
    l6 = (void*) _a2_arr;
    l7 = INT64_C(0);
    while ((l7 < l3)) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        l8 = vader_array_ref_load_box(_a3_slotarr->buf, vader_array_offset(_a3_slotarr) + (size_t) l7);
        if (l8.tag == 1307u) {
            l9 = vader_array_length(((vader_array_t*) l4));
            if ((l9 > INT64_C(0))) {
                l10 = vader_chk_sub(i64, l9, INT64_C(1));
                vader_array_t* _a4_slotarr = ((vader_array_t*) l4);
                VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                t2 = vader_array_ref_load_box(_a4_slotarr->buf, vader_array_offset(_a4_slotarr) + (size_t) l10);
                l11 = vader_core_bytecode$const_op_of(t2);
                if (!(l11.tag == 0u)) {
                    l12 = vader_chk_sub(i64, l9, INT64_C(1));
                    vader_struct_vader_core_bytecode$ReturnLit_t* _a5_obj = (vader_struct_vader_core_bytecode$ReturnLit_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$ReturnLit_t));
                    vader_obj_header_init(_a5_obj, 1308u);
                    _a5_obj->f_value = l11;
                    l13 = (void*) _a5_obj;
                    vader_array_t* _a6_slotarr = ((vader_array_t*) l4);
                    VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
                    vader_array_ref_store(_a6_slotarr->buf, vader_array_offset(_a6_slotarr) + (size_t) l12, l13);
                    VADER_WRITE_BARRIER(_a6_slotarr->buf);
                    t0 = vader_chk_sub(i64, l9, INT64_C(1));
                    l14 = ((int32_t) (int64_t) t0);
                    vader_array_t* _a7_slotarr = ((vader_array_t*) l6);
                    VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l7)
                    ((int32_t*) _a7_slotarr->buf->slots)[vader_array_offset(_a7_slotarr) + (size_t) l7] = (int32_t) l14;
                    l7 = vader_chk_add(i64, l7, INT64_C(1));
                    continue;
                }
            }
        }
        vader_emit_bytecode$push_or_assign(l4, l5, l8);
        l15 = ((int32_t) (int64_t) l5);
        vader_array_t* _a8_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l7)
        ((int32_t*) _a8_slotarr->buf->slots)[vader_array_offset(_a8_slotarr) + (size_t) l7] = (int32_t) l15;
        l5 = vader_chk_add(i64, l5, INT64_C(1));
        l7 = vader_chk_add(i64, l7, INT64_C(1));
    }
    vader_array_t* _a9_arr = vader_array_slice((vader_array_t*) l4, (int64_t) INT64_C(0), (int64_t) l5);
    l2 = (void*) _a9_arr;
    l4 = vader_core_bytecode$remap_jump_table(((vader_struct_vader_core_bytecode$BcFunction_t*) l1)->f_jump_table, l6, l5);
    l6 = vader_emit_bytecode$remap_debug(((vader_struct_vader_core_bytecode$BcFunction_t*) l1)->f_debug, l6, l5);
    l13 = l1;
    l16 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l13)->f_name;
    l17 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l13)->f_is_main;
    l18 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l13)->f_signature;
    l19 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l13)->f_locals;
    l13 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l13)->f_source_pc;
    vader_struct_vader_core_bytecode$BcFunction_t* _a10_obj = (vader_struct_vader_core_bytecode$BcFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcFunction_t));
    vader_obj_header_init(_a10_obj, 1182u);
    _a10_obj->f_name = l16;
    _a10_obj->f_is_main = l17;
    _a10_obj->f_signature = l18;
    _a10_obj->f_locals = l19;
    _a10_obj->f_body = l2;
    _a10_obj->f_debug = l6;
    _a10_obj->f_jump_table = l4;
    _a10_obj->f_source_pc = l13;
    t1 = (void*) _a10_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_emit_bytecode$StripSelfCopiesStage$toolchain_stage$Stage$describe(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l3, &l4, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 6u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(29u, 0u, 1u, 582u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(29u, 0u, 1u, 582u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(29u, 1u, 1u, 582u);
    ((uint8_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 0u] = (uint8_t) INT32_C(3);
    l3 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(34u, 0u, 0u, 591u);
    l4 = (void*) _a3_arr;
    vader_struct_vader_emit_bytecode$BytecodeSpec_t* _a4_obj = (vader_struct_vader_emit_bytecode$BytecodeSpec_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_bytecode$BytecodeSpec_t));
    vader_obj_header_init(_a4_obj, 1375u);
    _a4_obj->f_name = 3115u;
    _a4_obj->f_requires = l1;
    _a4_obj->f_breaks = l2;
    _a4_obj->f_establishes = l3;
    _a4_obj->f_after = l4;
    t0 = (void*) _a4_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_emit_bytecode$StripSelfCopiesStage$toolchain_stage$Stage$run(void* l0, void* l1) {
    void* l2 = NULL;
    void* l4 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l15 = NULL;
    void* l16 = NULL;
    int64_t l3, l6, l10, l12;
    bool l5;
    vader_box_t l9 = vader_box_null();
    int32_t l11, l13;
    vader_string_t l14 = 0;
    bool t0;
    void* t1 = NULL;
    vader_box_t t2 = vader_box_null();
    int64_t t3;
    vader_box_t* gc_roots[2] = { &l9, &t2 };
    void** gc_raw_roots[9] = { &l0, &l1, &l2, &l4, &l7, &l8, &l15, &l16, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l14 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 9u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l1)->f_body;
    l3 = vader_array_length(((vader_array_t*) l2));
    l4 = vader_core_bytecode$mark_jump_targets(((vader_struct_vader_core_bytecode$BcFunction_t*) l1)->f_jump_table, l3);
    l5 = false;
    l6 = INT64_C(0);
    while ((l6 < l3)) {
        t0 = vader_emit_bytecode$foldable_self_copy(l2, l6, l3, l4);
        if (t0) {
            l5 = true;
            break;
        }
        l6 = vader_chk_add(i64, l6, INT64_C(1));
    }
    if (!(l5)) {
        { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a0_arr = vader_array_new(445u, 0u, 13u, 2295u);
    l7 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(27u, 1u, 7u, 580u);
    ((int32_t*) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 0u] = (int32_t) INT32_C(-1);
    t1 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_repeat((vader_array_t*) t1, (int64_t) l3);
    l8 = (void*) _a2_arr;
    l6 = INT64_C(0);
    while ((l6 < l3)) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l6)
        l9 = vader_array_ref_load_box(_a3_slotarr->buf, vader_array_offset(_a3_slotarr) + (size_t) l6);
        t0 = vader_emit_bytecode$foldable_self_copy(l2, l6, l3, l4);
        if (t0) {
            l10 = vader_chk_add(i64, l6, INT64_C(1));
            vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l10)
            t2 = vader_array_ref_load_box(_a4_slotarr->buf, vader_array_offset(_a4_slotarr) + (size_t) l10);
            if (t2.tag == 1297u) {
                t3 = vader_array_length(((vader_array_t*) l7));
                l11 = ((int32_t) (int64_t) t3);
                vader_array_t* _a5_slotarr = ((vader_array_t*) l8);
                VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l6)
                ((int32_t*) _a5_slotarr->buf->slots)[vader_array_offset(_a5_slotarr) + (size_t) l6] = (int32_t) l11;
                vader_array_push_ref((vader_array_t*) l7, l9.payload.obj);
            } else {
                vader_array_t* _a6_slotarr = ((vader_array_t*) l8);
                VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l6)
                ((int32_t*) _a6_slotarr->buf->slots)[vader_array_offset(_a6_slotarr) + (size_t) l6] = (int32_t) INT32_C(-1);
            }
            l12 = vader_chk_add(i64, l6, INT64_C(1));
            vader_array_t* _a7_slotarr = ((vader_array_t*) l8);
            VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l12)
            ((int32_t*) _a7_slotarr->buf->slots)[vader_array_offset(_a7_slotarr) + (size_t) l12] = (int32_t) INT32_C(-1);
            l6 = vader_chk_add(i64, l6, INT64_C(2));
            continue;
        }
        t3 = vader_array_length(((vader_array_t*) l7));
        l13 = ((int32_t) (int64_t) t3);
        vader_array_t* _a8_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l6)
        ((int32_t*) _a8_slotarr->buf->slots)[vader_array_offset(_a8_slotarr) + (size_t) l6] = (int32_t) l13;
        vader_array_push_ref((vader_array_t*) l7, l9.payload.obj);
        l6 = vader_chk_add(i64, l6, INT64_C(1));
    }
    l2 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l1)->f_jump_table;
    l3 = vader_array_length(((vader_array_t*) l7));
    l2 = vader_core_bytecode$remap_jump_table(l2, l8, l3);
    l4 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l1)->f_debug;
    l3 = vader_array_length(((vader_array_t*) l7));
    l4 = vader_emit_bytecode$remap_debug(l4, l8, l3);
    l8 = l1;
    l14 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l8)->f_name;
    l5 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l8)->f_is_main;
    l15 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l8)->f_signature;
    l16 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l8)->f_locals;
    l8 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l8)->f_source_pc;
    vader_struct_vader_core_bytecode$BcFunction_t* _a9_obj = (vader_struct_vader_core_bytecode$BcFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcFunction_t));
    vader_obj_header_init(_a9_obj, 1182u);
    _a9_obj->f_name = l14;
    _a9_obj->f_is_main = l5;
    _a9_obj->f_signature = l15;
    _a9_obj->f_locals = l16;
    _a9_obj->f_body = l7;
    _a9_obj->f_debug = l4;
    _a9_obj->f_jump_table = l2;
    _a9_obj->f_source_pc = l8;
    t1 = (void*) _a9_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_emit_bytecode$add_vtable_entry(void* l0, void* l1, vader_string_t l2, int32_t l3, int32_t l4) {
    void* l5 = NULL;
    void* l8 = NULL;
    int64_t l6, l7;
    void* t0 = NULL;
    bool t1;
    void** gc_raw_roots[5] = { &l0, &l1, &l5, &l8, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_struct_vader_core_bytecode$VtableEntry_t* _a0_obj = (vader_struct_vader_core_bytecode$VtableEntry_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$VtableEntry_t));
    vader_obj_header_init(_a0_obj, 1342u);
    _a0_obj->f_receiver_type_index = l3;
    _a0_obj->f_fn_index = l4;
    l5 = (void*) _a0_obj;
    l6 = vader_array_length(((vader_array_t*) l0));
    l7 = std_collections$get_or_put__string__i64(l1, l2, l6);
    if (!(l7 != l6)) {
        vader_array_t* _a1_arr = vader_array_new(204u, 1u, 13u, 1342u);
        ((void**) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 0u] = l5;
        l8 = (void*) _a1_arr;
        vader_struct_vader_core_bytecode$VtableRow_t* _a2_obj = (vader_struct_vader_core_bytecode$VtableRow_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$VtableRow_t));
        vader_obj_header_init(_a2_obj, 1343u);
        _a2_obj->f_key = l2;
        _a2_obj->f_entries = l8;
        l8 = (void*) _a2_obj;
        vader_array_push_ref((vader_array_t*) l0, l8);
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_array_t* _a3_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l7)
    t0 = vader_array_ref_load_obj(_a3_slotarr->buf, vader_array_offset(_a3_slotarr) + (size_t) l7);
    t1 = vader_emit_bytecode$has_receiver(t0, l3);
    if (t1) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_array_t* _a4_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l7)
    t0 = vader_array_ref_load_obj(_a4_slotarr->buf, vader_array_offset(_a4_slotarr) + (size_t) l7);
    vader_array_push_ref((vader_array_t*) ((vader_struct_vader_core_bytecode$VtableRow_t*) t0)->f_entries, l5);
    { vader_gc_top = gc_frame.prev; return; }
}

static uint8_t vader_emit_bytecode$array_element_val_type(vader_box_t l0) {
    void* t0 = NULL;
    uint8_t t1;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (!(l0.tag == 1350u)) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 17; }
    }
    t0 = l0.payload.obj;
    t1 = vader_midir_select$val_type_of_type(((vader_struct_vader_core_types$ArrayType_t*) t0)->f_element);
    { uint8_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_emit_bytecode$baked_value(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    int64_t l4, l5;
    vader_box_t l6 = vader_box_null(), l7 = vader_box_null();
    vader_string_t l8 = 0;
    uint8_t l9;
    uint64_t l10;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    int32_t t2;
    int64_t t3;
    vader_box_t* gc_roots[3] = { &l1, &l6, &l7 };
    void** gc_raw_roots[4] = { &l0, &l2, &l3, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l8, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l1.tag == 1789u) {
        t0 = l1.payload.obj;
        t1 = ((vader_struct_vader_lower_ir$LoweredStringLit_t*) t0)->f_value;
        vader_emit_bytecode$intern_string(t1, l0);
        t0 = l1.payload.obj;
        t1 = ((vader_struct_vader_lower_ir$LoweredStringLit_t*) t0)->f_value;
        vader_struct_vader_core_bytecode$BcValStr_t* _a0_obj = (vader_struct_vader_core_bytecode$BcValStr_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcValStr_t));
        vader_obj_header_init(_a0_obj, 1195u);
        _a0_obj->f_value = t1;
        t0 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 1792u) {
        vader_array_t* _a1_arr = vader_array_new(448u, 0u, 13u, 2329u);
        l2 = (void*) _a1_arr;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_lower_ir$LoweredStructLit_t*) t0)->f_fields;
        l4 = vader_array_length(((vader_array_t*) l3));
        l5 = INT64_C(0);
        while ((l5 < l4)) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            t0 = vader_array_ref_load_obj(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l5);
            l6 = ((vader_struct_vader_lower_ir$LoweredStructLitField_t*) t0)->f_value;
            l7 = vader_emit_bytecode$baked_value(l0, l6);
            vader_array_push_ref((vader_array_t*) l2, l7.payload.obj);
            l5 = (l5 + INT64_C(1));
        }
        t0 = l1.payload.obj;
        t2 = vader_emit_bytecode$struct_symbol_id(((vader_struct_vader_lower_ir$LoweredStructLit_t*) t0)->f_type);
        vader_struct_vader_core_bytecode$BcValStruct_t* _a3_obj = (vader_struct_vader_core_bytecode$BcValStruct_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcValStruct_t));
        vader_obj_header_init(_a3_obj, 1196u);
        _a3_obj->f_symbol_id = t2;
        _a3_obj->f_fields = l2;
        t0 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 1750u) {
        vader_array_t* _a4_arr = vader_array_new(448u, 0u, 13u, 2329u);
        l2 = (void*) _a4_arr;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_lower_ir$LoweredArrayLit_t*) t0)->f_elements;
        l4 = vader_array_length(((vader_array_t*) l3));
        l5 = INT64_C(0);
        while ((l5 < l4)) {
            vader_array_t* _a5_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
            l6 = vader_array_ref_load_box(_a5_slotarr->buf, vader_array_offset(_a5_slotarr) + (size_t) l5);
            l7 = vader_emit_bytecode$baked_value(l0, l6);
            vader_array_push_ref((vader_array_t*) l2, l7.payload.obj);
            l5 = (l5 + INT64_C(1));
        }
        t0 = l1.payload.obj;
        t2 = vader_emit_bytecode$intern_type(((vader_struct_vader_lower_ir$LoweredArrayLit_t*) t0)->f_type, l0);
        vader_struct_vader_core_bytecode$BcValArray_t* _a6_obj = (vader_struct_vader_core_bytecode$BcValArray_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcValArray_t));
        vader_obj_header_init(_a6_obj, 1193u);
        _a6_obj->f_type_id = t2;
        _a6_obj->f_elements = l2;
        t0 = (void*) _a6_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l8 = vader_core_types$representation_name(VADER_UNION_FIELD(vader_box_t, vader_struct_vader_lower_ir$LoweredArrayLen_t, f_type, l1.payload.obj));
    l6 = vader_lower_ir$data_item_bits(l1, l8);
    if (l6.tag == 0u) {
        vader_host_std_core$Intrinsic$panic(2296u);
        vader_unreachable("a no-return call returned");
    } else {
        l4 = ((int64_t) l6.payload.i);
        l9 = vader_core_bytecode$array_kind_from_name(l8);
        t3 = l4;
        l10 = (uint64_t) (int64_t) t3;
        vader_struct_vader_core_bytecode$BcValPrim_t* _a7_obj = (vader_struct_vader_core_bytecode$BcValPrim_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcValPrim_t));
        vader_obj_header_init(_a7_obj, 1194u);
        _a7_obj->f_kind = l9;
        _a7_obj->f_bits = l10;
        t0 = (void*) _a7_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_gc_top = gc_frame.prev;
}

static vader_box_t vader_emit_bytecode$bc_type_of_with_ctx(vader_box_t l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l9 = NULL;
    int64_t l4, l5, l7;
    int32_t l6;
    vader_string_t l8 = 0;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    vader_string_t t5 = 0;
    uint8_t t2;
    vader_box_t t3 = vader_box_null();
    int32_t t4;
    vader_box_t* gc_roots[2] = { &l0, &t3 };
    void** gc_raw_roots[5] = { &l1, &l2, &l3, &l9, &t0 };
    vader_string_t* gc_atom_roots[3] = { &l8, &t1, &t5 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l0.tag == 1361u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_core_types$PrimitiveType_t*) t0)->f_name;
        t2 = vader_midir_select$val_type_of_primitive_name(t1);
        vader_struct_vader_core_bytecode$BcScalar_t* _a0_obj = (vader_struct_vader_core_bytecode$BcScalar_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcScalar_t));
        vader_obj_header_init(_a0_obj, 1188u);
        _a0_obj->f_val = t2;
        t0 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if ((l0.tag == 1352u || l0.tag == 1362u)) {
        t2 = vader_midir_select$val_type_of_type(l0);
        vader_struct_vader_core_bytecode$BcScalar_t* _a1_obj = (vader_struct_vader_core_bytecode$BcScalar_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcScalar_t));
        vader_obj_header_init(_a1_obj, 1188u);
        _a1_obj->f_val = t2;
        t0 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1351u) {
        t0 = l0.payload.obj;
        t3 = vader_emit_bytecode$bc_type_of_with_ctx(((vader_struct_vader_core_types$DistinctType_t*) t0)->f_backing, l1);
        { vader_box_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1364u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_core_types$StructType_t*) t0)->f_symbol)->f_name;
        vader_struct_vader_core_bytecode$BcRef_t* _a2_obj = (vader_struct_vader_core_bytecode$BcRef_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcRef_t));
        vader_obj_header_init(_a2_obj, 1187u);
        _a2_obj->f_trait_name = t1;
        t0 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1367u) {
        t0 = l0.payload.obj;
        t1 = vader_emit_bytecode$trait_ref_name(t0, l1);
        vader_struct_vader_core_bytecode$BcRef_t* _a3_obj = (vader_struct_vader_core_bytecode$BcRef_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcRef_t));
        vader_obj_header_init(_a3_obj, 1187u);
        _a3_obj->f_trait_name = t1;
        t0 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1350u) {
        t0 = l0.payload.obj;
        t4 = vader_emit_bytecode$intern_type(((vader_struct_vader_core_types$ArrayType_t*) t0)->f_element, l1);
        vader_struct_vader_core_bytecode$BcArray_t* _a4_obj = (vader_struct_vader_core_bytecode$BcArray_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcArray_t));
        vader_obj_header_init(_a4_obj, 1178u);
        _a4_obj->f_element = t4;
        t0 = (void*) _a4_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1373u) {
        vader_array_t* _a5_arr = vader_array_new(27u, 0u, 7u, 580u);
        l2 = (void*) _a5_arr;
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_core_types$UnionType_t*) t0)->f_variants;
        l4 = vader_array_length(((vader_array_t*) l3));
        l5 = INT64_C(0);
        while ((l5 < l4)) {
            vader_array_t* _a6_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
            t3 = vader_array_ref_load_box(_a6_slotarr->buf, vader_array_offset(_a6_slotarr) + (size_t) l5);
            l6 = vader_emit_bytecode$intern_type(t3, l1);
            vader_array_push_i32((vader_array_t*) l2, l6);
            l5 = (l5 + INT64_C(1));
        }
        vader_struct_vader_core_bytecode$BcUnion_t* _a7_obj = (vader_struct_vader_core_bytecode$BcUnion_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcUnion_t));
        vader_obj_header_init(_a7_obj, 1192u);
        _a7_obj->f_variants = l2;
        t0 = (void*) _a7_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1353u) {
        vader_array_t* _a8_arr = vader_array_new(27u, 0u, 7u, 580u);
        l2 = (void*) _a8_arr;
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_core_types$FnType_t*) t0)->f_params;
        l4 = vader_array_length(((vader_array_t*) l3));
        l5 = INT64_C(0);
        while ((l5 < l4)) {
            vader_array_t* _a9_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
            t3 = vader_array_ref_load_box(_a9_slotarr->buf, vader_array_offset(_a9_slotarr) + (size_t) l5);
            l6 = vader_emit_bytecode$intern_type(t3, l1);
            vader_array_push_i32((vader_array_t*) l2, l6);
            l5 = (l5 + INT64_C(1));
        }
        t0 = l0.payload.obj;
        l6 = vader_emit_bytecode$intern_type(((vader_struct_vader_core_types$FnType_t*) t0)->f_return_type, l1);
        vader_struct_vader_core_bytecode$BcFn_t* _a10_obj = (vader_struct_vader_core_bytecode$BcFn_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcFn_t));
        vader_obj_header_init(_a10_obj, 1181u);
        _a10_obj->f_params = l2;
        _a10_obj->f_return_type = l6;
        t0 = (void*) _a10_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1368u) {
        vader_array_t* _a11_arr = vader_array_new(102u, 0u, 13u, 1180u);
        l2 = (void*) _a11_arr;
        l4 = INT64_C(0);
        t0 = l0.payload.obj;
        l5 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_types$TupleType_t*) t0)->f_elements));
        while ((l4 < l5)) {
            l3 = (void*) vader_buffer_new((size_t) INT64_C(21));
            l7 = INT64_C(0);
            l7 = std_core$write_string_at(l3, l7, 1202u);
            l7 = std_core$write_int(l3, l7, l4);
            l8 = std_core$finish_buffer(l3, l7);
            t0 = l0.payload.obj;
            vader_array_t* _a12_slotarr = ((vader_array_t*) ((vader_struct_vader_core_types$TupleType_t*) t0)->f_elements);
            VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a12_slotarr, l4)
            t3 = vader_array_ref_load_box(_a12_slotarr->buf, vader_array_offset(_a12_slotarr) + (size_t) l4);
            l6 = vader_emit_bytecode$intern_type(t3, l1);
            vader_struct_vader_core_bytecode$BcField_t* _a13_obj = (vader_struct_vader_core_bytecode$BcField_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcField_t));
            vader_obj_header_init(_a13_obj, 1180u);
            _a13_obj->f_name = l8;
            _a13_obj->f_type_index = l6;
            l9 = (void*) _a13_obj;
            vader_array_push_ref((vader_array_t*) l2, l9);
            l4 = (l4 + INT64_C(1));
        }
        t0 = l0.payload.obj;
        t1 = vader_midir_select$tuple_shape_name(((vader_struct_vader_core_types$TupleType_t*) t0)->f_elements);
        t5 = vader_core_mangle$tuple_struct_name(t1);
        vader_struct_vader_core_bytecode$BcStruct_t* _a14_obj = (vader_struct_vader_core_bytecode$BcStruct_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcStruct_t));
        vader_obj_header_init(_a14_obj, 1191u);
        _a14_obj->f_name = t5;
        _a14_obj->f_fields = l2;
        _a14_obj->f_c_name = 0u;
        _a14_obj->f_symbol_id = INT32_C(-1);
        _a14_obj->f_shared = false;
        t0 = (void*) _a14_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1370u) {
        t0 = (void*) &vader_data_23;
        vader_array_t* _a15_slotarr = ((vader_array_t*) t0);
        VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
        t0 = vader_array_ref_load_obj(_a15_slotarr->buf, vader_array_offset(_a15_slotarr) + (size_t) INT64_C(0));
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1357u) {
        t0 = l0.payload.obj;
        vader_core_types$leaked_infer_var(t0);
        vader_unreachable("a no-return call returned");
    } else {
        if (l0.tag == 1369u) {
            t0 = (void*) &vader_data_23;
            vader_array_t* _a16_slotarr = ((vader_array_t*) t0);
            VADER_ARRAY_RESOLVE_BUF(_a16_slotarr)
            t0 = vader_array_ref_load_obj(_a16_slotarr->buf, vader_array_offset(_a16_slotarr) + (size_t) INT64_C(0));
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l0.tag == 1363u) {
            t0 = (void*) &vader_data_23;
            vader_array_t* _a17_slotarr = ((vader_array_t*) t0);
            VADER_ARRAY_RESOLVE_BUF(_a17_slotarr)
            t0 = vader_array_ref_load_obj(_a17_slotarr->buf, vader_array_offset(_a17_slotarr) + (size_t) INT64_C(0));
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l0.tag == 1374u) {
            t0 = (void*) &vader_data_23;
            vader_array_t* _a18_slotarr = ((vader_array_t*) t0);
            VADER_ARRAY_RESOLVE_BUF(_a18_slotarr)
            t0 = vader_array_ref_load_obj(_a18_slotarr->buf, vader_array_offset(_a18_slotarr) + (size_t) INT64_C(0));
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l0.tag == 1356u) {
            t0 = (void*) &vader_data_23;
            vader_array_t* _a19_slotarr = ((vader_array_t*) t0);
            VADER_ARRAY_RESOLVE_BUF(_a19_slotarr)
            t0 = vader_array_ref_load_obj(_a19_slotarr->buf, vader_array_offset(_a19_slotarr) + (size_t) INT64_C(0));
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l0.tag == 1354u) {
            t0 = (void*) &vader_data_23;
            vader_array_t* _a20_slotarr = ((vader_array_t*) t0);
            VADER_ARRAY_RESOLVE_BUF(_a20_slotarr)
            t0 = vader_array_ref_load_obj(_a20_slotarr->buf, vader_array_offset(_a20_slotarr) + (size_t) INT64_C(0));
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l0.tag == 1355u) {
            t0 = (void*) &vader_data_23;
            vader_array_t* _a21_slotarr = ((vader_array_t*) t0);
            VADER_ARRAY_RESOLVE_BUF(_a21_slotarr)
            t0 = vader_array_ref_load_obj(_a21_slotarr->buf, vader_array_offset(_a21_slotarr) + (size_t) INT64_C(0));
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l0.tag == 1359u) {
            t0 = (void*) &vader_data_23;
            vader_array_t* _a22_slotarr = ((vader_array_t*) t0);
            VADER_ARRAY_RESOLVE_BUF(_a22_slotarr)
            t0 = vader_array_ref_load_obj(_a22_slotarr->buf, vader_array_offset(_a22_slotarr) + (size_t) INT64_C(0));
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (!(l0.tag == 1349u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        t0 = (void*) &vader_data_23;
        vader_array_t* _a23_slotarr = ((vader_array_t*) t0);
        VADER_ARRAY_RESOLVE_BUF(_a23_slotarr)
        t0 = vader_array_ref_load_obj(_a23_slotarr->buf, vader_array_offset(_a23_slotarr) + (size_t) INT64_C(0));
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_gc_top = gc_frame.prev;
}

static bool vader_emit_bytecode$binary_leaves_width(uint8_t l0, uint8_t l1) {
    bool l2, l3;
    bool t0;
    t0 = vader_core_bytecode$is_narrow_valtype(l1);
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
            t0 = vader_core_bytecode$is_unsigned_val(l1);
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

static bool vader_emit_bytecode$blocking_of(void* l0) {
    vader_box_t l1 = vader_box_null();
    void* t0 = NULL;
    bool t1;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct_vader_core_mono$MonoEntry_t*) l0)->f_decl;
    if (!(l1.tag == 1048u)) {
        { vader_gc_top = gc_frame.prev; return false; }
    }
    t0 = l1.payload.obj;
    t1 = toolchain_ast$has_compiler_decorator(((vader_struct_toolchain_ast$FnDecl_t*) t0)->f_decorators, (uint8_t) 4);
    { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_emit_bytecode$boxed_element(vader_box_t l0) {
    void* l1 = NULL;
    vader_box_t l2 = vader_box_null();
    bool t0;
    vader_box_t* gc_roots[2] = { &l0, &l2 };
    void** gc_raw_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = vader_core_types$array_backing(l0);
    if (l2.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return false; }
    }
    l1 = l2.payload.obj;
    t0 = vader_midir_select$is_boxed_slot(((vader_struct_vader_core_types$ArrayType_t*) l1)->f_element);
    { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_emit_bytecode$boxed_field(void* l0, int32_t l1, int64_t l2) {
    vader_box_t l3;
    int32_t l4;
    void* t0;
    bool t1;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_types);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    l3 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l1);
    if (l3.tag == 1191u) {
        t0 = l3.payload.obj;
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcStruct_t*) t0)->f_fields);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l2)
        t0 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l2);
        l4 = ((vader_struct_vader_core_bytecode$BcField_t*) t0)->f_type_index;
        t1 = vader_emit_bytecode$is_boxed_row(l0, l4);
        return t1;
    }
    return false;
}

static void* vader_emit_bytecode$boxed_fields_of(void* l0, int32_t l1) {
    vader_box_t l2 = vader_box_null();
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l8 = NULL;
    int64_t l6, l7;
    bool l9;
    void* t0 = NULL;
    int64_t t1;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[6] = { &l0, &l3, &l4, &l5, &l8, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 6u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_types);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    l2 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l1);
    if (!(l2.tag == 1191u)) {
        vader_array_t* _a1_arr = vader_array_new(24u, 0u, 12u, 575u);
        t0 = (void*) _a1_arr;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l2.payload.obj;
    l3 = ((vader_struct_vader_core_bytecode$BcStruct_t*) t0)->f_fields;
    vader_struct___lambda_env_vader_emit_bytecode_15_t* _a2_obj = (vader_struct___lambda_env_vader_emit_bytecode_15_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_emit_bytecode_15_t));
    vader_obj_header_init(_a2_obj, 624u);
    _a2_obj->f_cap_0 = l0;
    l4 = (void*) _a2_obj;
    t1 = vader_array_length(((vader_array_t*) l3));
    vader_array_t* _a3_arr = vader_array_reserve(24u, (int64_t) t1, 12u, 575u);
    l5 = (void*) _a3_arr;
    l6 = vader_array_length(((vader_array_t*) l3));
    l7 = INT64_C(0);
    vader_array_t* _pc26_hdr = (vader_array_t*) l5;
    size_t _pc26_len = vader_array_length(_pc26_hdr);
    size_t _pc26_cap = vader_array_is_borrowed(_pc26_hdr) ? (size_t) 0 : vader_array_capacity(_pc26_hdr);
    void* _pc26_slots = _pc26_hdr->buf->slots;
    for (;;) {
        if ((l7 < l6)) {
            vader_array_t* _a4_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
            l8 = vader_array_ref_load_obj(_a4_slotarr->buf, vader_array_offset(_a4_slotarr) + (size_t) l7);
            l9 = __lambda_vader_emit_bytecode_14(l4, l8);
            if (VADER_LIKELY(_pc26_len < _pc26_cap)) {
                ((uint8_t*) _pc26_slots)[_pc26_len] = (uint8_t) (l9);
                _pc26_len += 1;
            } else {
                vader_array_set_length(_pc26_hdr, _pc26_len);
                if (_pc26_hdr->buf->length < _pc26_len) {
                    _pc26_hdr->buf->length = _pc26_len;
                }
                vader_array_push_bool((vader_array_t*) l5, l9);
                _pc26_hdr = (vader_array_t*) l5;
                _pc26_len = vader_array_length(_pc26_hdr);
                _pc26_cap = vader_array_is_borrowed(_pc26_hdr) ? (size_t) 0 : vader_array_capacity(_pc26_hdr);
                _pc26_slots = _pc26_hdr->buf->slots;
            }
            l7 = (l7 + INT64_C(1));
            continue;
        }
        vader_array_set_length(_pc26_hdr, _pc26_len);
        if (_pc26_hdr->buf->length < _pc26_len) {
            _pc26_hdr->buf->length = _pc26_len;
        }
        break;
    }
    { void* __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_emit_bytecode$boxed_params_of(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    int64_t l5, l6;
    int32_t l7;
    bool l8;
    int64_t t0;
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_core_bytecode$BcSignature_t*) l1)->f_param_types;
    vader_struct___lambda_env_vader_emit_bytecode_13_t* _a0_obj = (vader_struct___lambda_env_vader_emit_bytecode_13_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_emit_bytecode_13_t));
    vader_obj_header_init(_a0_obj, 623u);
    _a0_obj->f_cap_0 = l0;
    l3 = (void*) _a0_obj;
    t0 = vader_array_length(((vader_array_t*) l2));
    vader_array_t* _a1_arr = vader_array_reserve(24u, (int64_t) t0, 12u, 575u);
    l4 = (void*) _a1_arr;
    l5 = vader_array_length(((vader_array_t*) l2));
    l6 = INT64_C(0);
    vader_array_t* _pc14_hdr = (vader_array_t*) l4;
    size_t _pc14_len = vader_array_length(_pc14_hdr);
    size_t _pc14_cap = vader_array_is_borrowed(_pc14_hdr) ? (size_t) 0 : vader_array_capacity(_pc14_hdr);
    void* _pc14_slots = _pc14_hdr->buf->slots;
    for (;;) {
        if ((l6 < l5)) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            l7 = ((int32_t*) _a2_slotarr->buf->slots)[vader_array_offset(_a2_slotarr) + (size_t) l6];
            l8 = __lambda_vader_emit_bytecode_12(l3, l7);
            if (VADER_LIKELY(_pc14_len < _pc14_cap)) {
                ((uint8_t*) _pc14_slots)[_pc14_len] = (uint8_t) (l8);
                _pc14_len += 1;
            } else {
                vader_array_set_length(_pc14_hdr, _pc14_len);
                if (_pc14_hdr->buf->length < _pc14_len) {
                    _pc14_hdr->buf->length = _pc14_len;
                }
                vader_array_push_bool((vader_array_t*) l4, l8);
                _pc14_hdr = (vader_array_t*) l4;
                _pc14_len = vader_array_length(_pc14_hdr);
                _pc14_cap = vader_array_is_borrowed(_pc14_hdr) ? (size_t) 0 : vader_array_capacity(_pc14_hdr);
                _pc14_slots = _pc14_hdr->buf->slots;
            }
            l6 = (l6 + INT64_C(1));
            continue;
        }
        vader_array_set_length(_pc14_hdr, _pc14_len);
        if (_pc14_hdr->buf->length < _pc14_len) {
            _pc14_hdr->buf->length = _pc14_len;
        }
        break;
    }
    { void* __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_emit_bytecode$build_cfg_signature(void* l0, vader_box_t l1, void* l2, void* l3) {
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l10 = NULL;
    void* l14 = NULL;
    void* l16 = NULL;
    int64_t l8, l9;
    uint8_t l11;
    int32_t l12;
    vader_string_t l13 = 0;
    vader_box_t l15 = vader_box_null();
    int64_t t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[2] = { &l1, &l15 };
    void** gc_raw_roots[11] = { &l0, &l2, &l3, &l4, &l5, &l6, &l7, &l10, &l14, &l16, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l13 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 11u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_array_length(((vader_array_t*) l0));
    vader_array_t* _a0_arr = vader_array_reserve(29u, (int64_t) t0, 1u, 582u);
    l4 = (void*) _a0_arr;
    t0 = vader_array_length(((vader_array_t*) l0));
    vader_array_t* _a1_arr = vader_array_reserve(27u, (int64_t) t0, 7u, 580u);
    l5 = (void*) _a1_arr;
    t0 = vader_array_length(((vader_array_t*) l0));
    vader_array_t* _a2_arr = vader_array_reserve(26u, (int64_t) t0, 0u, 577u);
    l6 = (void*) _a2_arr;
    l7 = l0;
    l8 = vader_array_length(((vader_array_t*) l7));
    l9 = INT64_C(0);
    while ((l9 < l8)) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        l10 = vader_array_ref_load_obj(_a3_slotarr->buf, vader_array_offset(_a3_slotarr) + (size_t) l9);
        l11 = vader_midir_select$val_type_of_type(((vader_struct_vader_midir$CFGParam_t*) l10)->f_type);
        vader_array_push_u8((vader_array_t*) l4, (int32_t) (uint8_t) l11);
        l12 = vader_emit_bytecode$intern_type(((vader_struct_vader_midir$CFGParam_t*) l10)->f_type, l3);
        vader_array_push_i32((vader_array_t*) l5, l12);
        l13 = ((vader_struct_vader_midir$CFGParam_t*) l10)->f_name;
        vader_array_push_scalar((vader_array_t*) l6, vader_box_string(577u, l13));
        l9 = (l9 + INT64_C(1));
    }
    vader_array_t* _a4_arr = vader_array_new(29u, 0u, 1u, 582u);
    l7 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_new(27u, 0u, 7u, 580u);
    l10 = (void*) _a5_arr;
    t0 = vader_array_length(((vader_array_t*) l2));
    if ((t0 > INT64_C(1))) {
        l14 = l2;
        l8 = vader_array_length(((vader_array_t*) l14));
        l9 = INT64_C(0);
        while ((l9 < l8)) {
            vader_array_t* _a6_slotarr = ((vader_array_t*) l14);
            VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
            l15 = vader_array_ref_load_box(_a6_slotarr->buf, vader_array_offset(_a6_slotarr) + (size_t) l9);
            l11 = vader_midir_select$val_type_of_type(l15);
            vader_array_push_u8((vader_array_t*) l7, (int32_t) (uint8_t) l11);
            l12 = vader_emit_bytecode$intern_type(l15, l3);
            vader_array_push_i32((vader_array_t*) l10, l12);
            l9 = (l9 + INT64_C(1));
        }
    } else {
        l11 = vader_midir_select$val_type_of_type(l1);
        vader_array_push_u8((vader_array_t*) l7, (int32_t) (uint8_t) l11);
        l12 = vader_emit_bytecode$intern_type(l1, l3);
        vader_array_push_i32((vader_array_t*) l10, l12);
    }
    vader_array_t* _a7_arr = vader_array_new(24u, 0u, 12u, 575u);
    l14 = (void*) _a7_arr;
    vader_array_t* _a8_arr = vader_array_new(24u, 0u, 12u, 575u);
    l16 = (void*) _a8_arr;
    vader_struct_vader_core_bytecode$BcSignature_t* _a9_obj = (vader_struct_vader_core_bytecode$BcSignature_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcSignature_t));
    vader_obj_header_init(_a9_obj, 1189u);
    _a9_obj->f_params = l4;
    _a9_obj->f_results = l7;
    _a9_obj->f_param_types = l5;
    _a9_obj->f_result_types = l10;
    _a9_obj->f_param_names = l6;
    _a9_obj->f_param_c_out = l14;
    _a9_obj->f_param_by_address = l16;
    t1 = (void*) _a9_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_emit_bytecode$build_impl_table_from_vtable(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l15 = NULL;
    void* l22 = NULL;
    void* l25 = NULL;
    int64_t l7, l8, l12, l14, l16, l17, l21, l23, l24;
    vader_string_t l9 = 0;
    vader_string_t l18 = 0;
    vader_string_t l19 = 0;
    vader_string_t l20 = 0;
    vader_box_t l10 = vader_box_null(), l26 = vader_box_null();
    int32_t l11;
    bool l13;
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    vader_box_t* gc_roots[3] = { &l10, &l26, &t0 };
    void** gc_raw_roots[11] = { &l0, &l1, &l2, &l3, &l4, &l5, &l6, &l15, &l22, &l25, &t1 };
    vader_string_t* gc_atom_roots[4] = { &l9, &l18, &l19, &l20 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 11u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(177u, 0u, 13u, 1286u);
    l3 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(26u, 0u, 0u, 577u);
    l4 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(24u, 0u, 12u, 575u);
    l5 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(27u, 0u, 7u, 580u);
    l6 = (void*) _a3_arr;
    vader_struct_std_collections$Map__string__bool_t* _a4_obj = (vader_struct_std_collections$Map__string__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__bool_t));
    vader_obj_header_init(_a4_obj, 901u);
    _a4_obj->f_ekeys = l4;
    _a4_obj->f_evals = l5;
    _a4_obj->f_index = l6;
    _a4_obj->f_mask = INT64_C(0);
    _a4_obj->f_grow_at = INT64_C(0);
    _a4_obj->f_size = INT64_C(0);
    _a4_obj->f_tombs = INT64_C(0);
    l4 = (void*) _a4_obj;
    l5 = l0;
    l7 = vader_array_length(((vader_array_t*) l5));
    l8 = INT64_C(0);
    while ((l8 < l7)) {
        vader_array_t* _a5_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        l6 = vader_array_ref_load_obj(_a5_slotarr->buf, vader_array_offset(_a5_slotarr) + (size_t) l8);
        l9 = vader_midir_select$type_intern_key(((vader_struct_vader_lower_ir$LoweredVtableEntry_t*) l6)->f_struct_type);
        l10 = std_collections$Map$std_core$Index$at__string__i32(((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l2)->f_type_key, l9);
        if (l10.tag == 580u) {
            l11 = ((int32_t) l10.payload.i);
            l12 = ((int64_t) (int32_t) l11);
            if ((INT64_C(0) <= l12)) {
                l14 = vader_array_length(((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l2)->f_types));
                l13 = (l12 < l14);
            } else {
                l13 = false;
            }
            if (l13) {
                vader_array_t* _a6_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l2)->f_types);
                VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l11)
                t0 = vader_array_ref_load_box(_a6_slotarr->buf, vader_array_offset(_a6_slotarr) + (size_t) l11);
                if (!((t0.tag == 1178u || t0.tag == 1191u))) {
                    l8 = (l8 + INT64_C(1));
                    continue;
                }
            }
            l15 = ((vader_struct_vader_lower_ir$LoweredVtableEntry_t*) l6)->f_row_traits;
            l16 = vader_array_length(((vader_array_t*) l15));
            l17 = INT64_C(0);
            while ((l17 < l16)) {
                vader_array_t* _a7_slotarr = ((vader_array_t*) l15);
                VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
                t0 = vader_array_box_slots(_a7_slotarr->buf)[vader_array_offset(_a7_slotarr) + (size_t) l17];
                l18 = t0.payload.s;
                l20 = l18;
                l21 = vader_host_std_core$Intrinsic$byte_len(l20);
                l22 = (void*) vader_buffer_new((size_t) (INT64_C(21) + l21));
                l23 = INT64_C(0);
                l24 = ((int64_t) (int32_t) l11);
                l23 = std_core$write_int(l22, l23, l24);
                l23 = std_core$write_string_at(l22, l23, 3631u);
                l23 = std_core$write_string_at(l22, l23, l20);
                l19 = std_core$finish_buffer(l22, l23);
                t0 = std_collections$Map$std_core$Index$at__string__bool(l4, l19);
                if (t0.tag == 575u) {
                    l17 = (l17 + INT64_C(1));
                    continue;
                }
                std_collections$Map$std_core$IndexSet$set_at__string__bool(l4, l19, true);
                vader_struct_vader_core_bytecode$ImplEntry_t* _a8_obj = (vader_struct_vader_core_bytecode$ImplEntry_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$ImplEntry_t));
                vader_obj_header_init(_a8_obj, 1286u);
                _a8_obj->f_type_index = l11;
                _a8_obj->f_trait_name = l18;
                l25 = (void*) _a8_obj;
                vader_array_push_ref((vader_array_t*) l3, l25);
                l17 = (l17 + INT64_C(1));
            }
            l8 = (l8 + INT64_C(1));
            continue;
        }
        l8 = (l8 + INT64_C(1));
    }
    l7 = INT64_C(0);
    l8 = vader_array_length(((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l2)->f_types));
    while ((l7 < l8)) {
        vader_array_t* _a9_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l2)->f_types);
        VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l7)
        l10 = vader_array_ref_load_box(_a9_slotarr->buf, vader_array_offset(_a9_slotarr) + (size_t) l7);
        if (l10.tag == 1191u) {
            t1 = l10.payload.obj;
            l11 = ((vader_struct_vader_core_bytecode$BcStruct_t*) t1)->f_symbol_id;
            l26 = std_collections$Map$std_core$Index$at__i32__string__(l1, l11);
            if (l26.tag == 0u) {
                l7 = (l7 + INT64_C(1));
                continue;
            }
            l5 = l26.payload.obj;
            l12 = vader_array_length(((vader_array_t*) l5));
            l14 = INT64_C(0);
            while ((l14 < l12)) {
                vader_array_t* _a10_slotarr = ((vader_array_t*) l5);
                VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
                t0 = vader_array_box_slots(_a10_slotarr->buf)[vader_array_offset(_a10_slotarr) + (size_t) l14];
                l9 = t0.payload.s;
                l19 = l9;
                l16 = vader_host_std_core$Intrinsic$byte_len(l19);
                l6 = (void*) vader_buffer_new((size_t) (INT64_C(21) + l16));
                l17 = INT64_C(0);
                l17 = std_core$write_int(l6, l17, l7);
                l17 = std_core$write_string_at(l6, l17, 3631u);
                l17 = std_core$write_string_at(l6, l17, l19);
                l18 = std_core$finish_buffer(l6, l17);
                t0 = std_collections$Map$std_core$Index$at__string__bool(l4, l18);
                if (t0.tag == 575u) {
                    l14 = (l14 + INT64_C(1));
                    continue;
                }
                std_collections$Map$std_core$IndexSet$set_at__string__bool(l4, l18, true);
                vader_struct_vader_core_bytecode$ImplEntry_t* _a11_obj = (vader_struct_vader_core_bytecode$ImplEntry_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$ImplEntry_t));
                vader_obj_header_init(_a11_obj, 1286u);
                _a11_obj->f_type_index = ((int32_t) (int64_t) l7);
                _a11_obj->f_trait_name = l9;
                l15 = (void*) _a11_obj;
                vader_array_push_ref((vader_array_t*) l3, l15);
                l14 = (l14 + INT64_C(1));
            }
        }
        l7 = (l7 + INT64_C(1));
    }
    { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_emit_bytecode$build_vtables_from_entries(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l11 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    int64_t l5, l6, l7, l8;
    vader_box_t l9 = vader_box_null(), l16 = vader_box_null();
    vader_string_t l10 = 0;
    vader_string_t l17 = 0;
    vader_string_t l18 = 0;
    vader_string_t l19 = 0;
    int32_t l15, l20;
    void* t0 = NULL;
    bool t1;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l9, &l16, &t2 };
    void** gc_raw_roots[10] = { &l0, &l1, &l2, &l3, &l4, &l11, &l12, &l13, &l14, &t0 };
    vader_string_t* gc_atom_roots[4] = { &l10, &l17, &l18, &l19 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 10u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(26u, 0u, 0u, 577u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(24u, 0u, 12u, 575u);
    l3 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(27u, 0u, 7u, 580u);
    l4 = (void*) _a2_arr;
    vader_struct_std_collections$Map__string__bool_t* _a3_obj = (vader_struct_std_collections$Map__string__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__bool_t));
    vader_obj_header_init(_a3_obj, 901u);
    _a3_obj->f_ekeys = l2;
    _a3_obj->f_evals = l3;
    _a3_obj->f_index = l4;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    l2 = (void*) _a3_obj;
    l3 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l1)->f_functions;
    l5 = vader_array_length(((vader_array_t*) l3));
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        t0 = vader_array_ref_load_obj(_a4_slotarr->buf, vader_array_offset(_a4_slotarr) + (size_t) l6);
        l4 = ((vader_struct_vader_core_bytecode$BcFunction_t*) t0)->f_body;
        l7 = vader_array_length(((vader_array_t*) l4));
        l8 = INT64_C(0);
        while ((l8 < l7)) {
            vader_array_t* _a5_slotarr = ((vader_array_t*) l4);
            VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
            l9 = vader_array_ref_load_box(_a5_slotarr->buf, vader_array_offset(_a5_slotarr) + (size_t) l8);
            if (l9.tag == 1341u) {
                t0 = l9.payload.obj;
                l10 = ((vader_struct_vader_core_bytecode$VirtualCall_t*) t0)->f_vtable_key;
                std_collections$Map$std_core$IndexSet$set_at__string__bool(l2, l10, true);
            }
            l8 = (l8 + INT64_C(1));
        }
        l6 = (l6 + INT64_C(1));
    }
    vader_array_t* _a6_arr = vader_array_new(26u, 0u, 0u, 577u);
    l3 = (void*) _a6_arr;
    vader_array_t* _a7_arr = vader_array_new(28u, 0u, 8u, 581u);
    l4 = (void*) _a7_arr;
    vader_array_t* _a8_arr = vader_array_new(27u, 0u, 7u, 580u);
    l11 = (void*) _a8_arr;
    vader_struct_std_collections$Map__string__i64_t* _a9_obj = (vader_struct_std_collections$Map__string__i64_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__i64_t));
    vader_obj_header_init(_a9_obj, 904u);
    _a9_obj->f_ekeys = l3;
    _a9_obj->f_evals = l4;
    _a9_obj->f_index = l11;
    _a9_obj->f_mask = INT64_C(0);
    _a9_obj->f_grow_at = INT64_C(0);
    _a9_obj->f_size = INT64_C(0);
    _a9_obj->f_tombs = INT64_C(0);
    l3 = (void*) _a9_obj;
    vader_array_t* _a10_arr = vader_array_new(205u, 0u, 13u, 1343u);
    l4 = (void*) _a10_arr;
    vader_array_t* _a11_arr = vader_array_new(377u, 0u, 13u, 1800u);
    l11 = (void*) _a11_arr;
    vader_array_t* _a12_arr = vader_array_new(377u, 0u, 13u, 1800u);
    l12 = (void*) _a12_arr;
    l13 = l0;
    l5 = vader_array_length(((vader_array_t*) l13));
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a13_slotarr = ((vader_array_t*) l13);
        VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
        l14 = vader_array_ref_load_obj(_a13_slotarr->buf, vader_array_offset(_a13_slotarr) + (size_t) l6);
        t1 = vader_core_types$boxes_as_representation(((vader_struct_vader_lower_ir$LoweredVtableEntry_t*) l14)->f_struct_type);
        if (t1) {
            vader_array_push_ref((vader_array_t*) l12, l14);
        } else {
            vader_array_push_ref((vader_array_t*) l11, l14);
        }
        l6 = (l6 + INT64_C(1));
    }
    vader_array_push_all((vader_array_t*) l11, (vader_array_t*) l12);
    l5 = vader_array_length(((vader_array_t*) l11));
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a14_slotarr = ((vader_array_t*) l11);
        VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
        l12 = vader_array_ref_load_obj(_a14_slotarr->buf, vader_array_offset(_a14_slotarr) + (size_t) l6);
        l9 = vader_emit_bytecode$resolve_fn_index(((vader_struct_vader_lower_ir$LoweredVtableEntry_t*) l12)->f_fn_symbol, l1);
        if (l9.tag == 0u) {
            l6 = (l6 + INT64_C(1));
            continue;
        }
        l15 = ((int32_t) l9.payload.i);
        l10 = vader_midir_select$type_intern_key(((vader_struct_vader_lower_ir$LoweredVtableEntry_t*) l12)->f_struct_type);
        l16 = std_collections$Map$std_core$Index$at__string__i32(((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l1)->f_type_key, l10);
        if (l16.tag == 580u) {
            l13 = ((vader_struct_vader_lower_ir$LoweredVtableEntry_t*) l12)->f_row_traits;
            l7 = vader_array_length(((vader_array_t*) l13));
            l8 = INT64_C(0);
            while ((l8 < l7)) {
                vader_array_t* _a15_slotarr = ((vader_array_t*) l13);
                VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
                t2 = vader_array_box_slots(_a15_slotarr->buf)[vader_array_offset(_a15_slotarr) + (size_t) l8];
                l17 = t2.payload.s;
                l18 = ((vader_struct_vader_lower_ir$LoweredVtableEntry_t*) l12)->f_method_name;
                l19 = vader_core_mangle$vtable_key(l17, l18);
                t2 = std_collections$Map$std_core$Index$at__string__bool(l2, l19);
                if (t2.tag == 575u) {
                    l20 = ((int32_t) l16.payload.i);
                    vader_emit_bytecode$add_vtable_entry(l4, l3, l19, l20, l15);
                }
                l8 = (l8 + INT64_C(1));
            }
            l6 = (l6 + INT64_C(1));
            continue;
        }
        l6 = (l6 + INT64_C(1));
    }
    { void* __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_emit_bytecode$bytecode_stages(void) {
    void* l0 = NULL;
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[8] = { &l0, &l1, &l2, &l3, &l4, &l5, &l6, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 8u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = (void*) &vader_data_79;
    vader_array_t* _a0_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    l0 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) INT64_C(0));
    t0 = (void*) &vader_data_80;
    vader_array_t* _a1_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    l1 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) INT64_C(0));
    t0 = (void*) &vader_data_81;
    vader_array_t* _a2_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    l2 = vader_array_ref_load_obj(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) INT64_C(0));
    t0 = (void*) &vader_data_82;
    vader_array_t* _a3_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
    l3 = vader_array_ref_load_obj(_a3_slotarr->buf, vader_array_offset(_a3_slotarr) + (size_t) INT64_C(0));
    t0 = (void*) &vader_data_83;
    vader_array_t* _a4_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
    l4 = vader_array_ref_load_obj(_a4_slotarr->buf, vader_array_offset(_a4_slotarr) + (size_t) INT64_C(0));
    t0 = (void*) &vader_data_84;
    vader_array_t* _a5_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
    l5 = vader_array_ref_load_obj(_a5_slotarr->buf, vader_array_offset(_a5_slotarr) + (size_t) INT64_C(0));
    t0 = (void*) &vader_data_85;
    vader_array_t* _a6_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
    l6 = vader_array_ref_load_obj(_a6_slotarr->buf, vader_array_offset(_a6_slotarr) + (size_t) INT64_C(0));
    vader_array_t* _a7_arr = vader_array_new(34u, 7u, 0u, 591u);
    vader_array_box_slots(_a7_arr->buf)[vader_array_offset(_a7_arr) + 6u] = vader_ref_box(l6);
    vader_array_box_slots(_a7_arr->buf)[vader_array_offset(_a7_arr) + 5u] = vader_ref_box(l5);
    vader_array_box_slots(_a7_arr->buf)[vader_array_offset(_a7_arr) + 4u] = vader_ref_box(l4);
    vader_array_box_slots(_a7_arr->buf)[vader_array_offset(_a7_arr) + 3u] = vader_ref_box(l3);
    vader_array_box_slots(_a7_arr->buf)[vader_array_offset(_a7_arr) + 2u] = vader_ref_box(l2);
    vader_array_box_slots(_a7_arr->buf)[vader_array_offset(_a7_arr) + 1u] = vader_ref_box(l1);
    vader_array_box_slots(_a7_arr->buf)[vader_array_offset(_a7_arr) + 0u] = vader_ref_box(l0);
    t0 = (void*) _a7_arr;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_emit_bytecode$c_struct_of(void* l0) {
    void* l1 = NULL;
    void* l3 = NULL;
    vader_box_t l2 = vader_box_null();
    vader_string_t l4 = 0;
    vader_string_t t0 = 0;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[3] = { &l0, &l1, &l3 };
    vader_string_t* gc_atom_roots[2] = { &l4, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_emit_bytecode$struct_decl_of(l0);
    if (l2.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return 0u; }
    }
    l1 = l2.payload.obj;
    l3 = ((vader_struct_toolchain_ast$StructDecl_t*) l1)->f_decorators;
    l4 = ((vader_struct_toolchain_ast$StructDecl_t*) l1)->f_name;
    t0 = toolchain_ast$c_struct_spelling(l3, l4);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_emit_bytecode$can_pass_through_stack(vader_box_t l0, vader_box_t l1, void* l2) {
    int32_t l3;
    vader_box_t l4;
    int64_t l5;
    int32_t t0;
    bool t1;
    l4 = vader_midir$dst_of(l0);
    if (l4.tag == 0u) {
        return false;
    }
    l3 = ((int32_t) l4.payload.i);
    l5 = ((int64_t) (int32_t) l3);
    vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
    t0 = ((int32_t*) _a0_slotarr->buf->slots)[vader_array_offset(_a0_slotarr) + (size_t) l5];
    if (t0 != INT32_C(1)) {
        return false;
    }
    l4 = vader_emit_bytecode$first_stack_operand(l1);
    if (l4.tag == 0u) {
        return false;
    }
    t0 = ((int32_t) l4.payload.i);
    t1 = vader_midir$LocalId$std_core$Equals$equals(t0, l3);
    return t1;
}

static bool vader_emit_bytecode$can_pass_through_terminator(vader_box_t l0, vader_box_t l1, void* l2) {
    int32_t l3;
    vader_box_t l4;
    int64_t l5;
    int32_t t0;
    bool t1;
    l4 = vader_midir$dst_of(l0);
    if (l4.tag == 0u) {
        return false;
    }
    l3 = ((int32_t) l4.payload.i);
    l5 = ((int64_t) (int32_t) l3);
    vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
    t0 = ((int32_t*) _a0_slotarr->buf->slots)[vader_array_offset(_a0_slotarr) + (size_t) l5];
    if (t0 != INT32_C(1)) {
        return false;
    }
    l4 = vader_emit_bytecode$first_terminator_operand(l1);
    if (l4.tag == 0u) {
        return false;
    }
    t0 = ((int32_t) l4.payload.i);
    t1 = vader_midir$LocalId$std_core$Equals$equals(t0, l3);
    return t1;
}

static void vader_emit_bytecode$cf_block(void* l0, void* l1, int32_t l2) {
    void* l3 = NULL;
    void* l5 = NULL;
    int32_t l4;
    void* t0 = NULL;
    void** gc_raw_roots[5] = { &l0, &l1, &l3, &l5, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = (void*) &vader_data_88;
    vader_array_t* _a0_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    l3 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) INT64_C(0));
    l4 = vader_emit_bytecode$push_op_with_span(l0, vader_ref_box(l3), l1);
    l3 = ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_scopes;
    vader_struct_vader_emit_bytecode$ScopeFrame_t* _a1_obj = (vader_struct_vader_emit_bytecode$ScopeFrame_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_bytecode$ScopeFrame_t));
    vader_obj_header_init(_a1_obj, 1388u);
    _a1_obj->f_kind = 2007u;
    _a1_obj->f_target_blk = l2;
    _a1_obj->f_opener_pc = l4;
    l5 = (void*) _a1_obj;
    vader_array_push_ref((vader_array_t*) l3, l5);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_bytecode$cf_br(void* l0, void* l1, int32_t l2) {
    void* l3 = NULL;
    int32_t l4;
    void* t0 = NULL;
    void** gc_raw_roots[4] = { &l0, &l1, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = (void*) &vader_data_89;
    vader_array_t* _a0_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    l3 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) INT64_C(0));
    l4 = vader_emit_bytecode$push_op_with_span(l0, vader_ref_box(l3), l1);
    vader_emit_bytecode$defer_or_resolve_branch(l0, l2, l4);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_bytecode$cf_br_if(void* l0, void* l1, int32_t l2) {
    void* l3 = NULL;
    int32_t l4;
    void* t0 = NULL;
    void** gc_raw_roots[4] = { &l0, &l1, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = (void*) &vader_data_97;
    vader_array_t* _a0_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    l3 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) INT64_C(0));
    l4 = vader_emit_bytecode$push_op_with_span(l0, vader_ref_box(l3), l1);
    vader_emit_bytecode$defer_or_resolve_branch(l0, l2, l4);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_bytecode$cf_else(void* l0, void* l1) {
    void* l2 = NULL;
    void* l6 = NULL;
    int32_t l3, l7, l8;
    int64_t l4, l5;
    void* t0 = NULL;
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l6, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = (void*) &vader_data_99;
    vader_array_t* _a0_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    l2 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) INT64_C(0));
    l3 = vader_emit_bytecode$push_op_with_span(l0, vader_ref_box(l2), l1);
    l4 = vader_array_length(((vader_array_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_scopes));
    if (!(l4 == INT64_C(0))) {
        l2 = ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_scopes;
        l5 = vader_chk_sub(i64, l4, INT64_C(1));
        vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
        l2 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l5);
        l6 = ((vader_struct_vader_core_bytecode$BcFunction_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_slot)->f_jump_table;
        l7 = ((vader_struct_vader_emit_bytecode$ScopeFrame_t*) l2)->f_opener_pc;
        l8 = vader_chk_add(i32, l3, INT32_C(1));
        vader_array_t* _a2_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l7)
        ((int32_t*) _a2_slotarr->buf->slots)[vader_array_offset(_a2_slotarr) + (size_t) l7] = (int32_t) l8;
        l6 = ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_scopes;
        l4 = vader_chk_sub(i64, l4, INT64_C(1));
        l7 = ((vader_struct_vader_emit_bytecode$ScopeFrame_t*) l2)->f_target_blk;
        vader_struct_vader_emit_bytecode$ScopeFrame_t* _a3_obj = (vader_struct_vader_emit_bytecode$ScopeFrame_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_bytecode$ScopeFrame_t));
        vader_obj_header_init(_a3_obj, 1388u);
        _a3_obj->f_kind = 2584u;
        _a3_obj->f_target_blk = l7;
        _a3_obj->f_opener_pc = l3;
        l2 = (void*) _a3_obj;
        vader_array_t* _a4_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l4)
        vader_array_ref_store(_a4_slotarr->buf, vader_array_offset(_a4_slotarr) + (size_t) l4, l2);
        VADER_WRITE_BARRIER(_a4_slotarr->buf);
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_bytecode$cf_end(void* l0, void* l1) {
    void* l2 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    int32_t l3, l8, l9;
    int64_t l4, l5;
    bool l10;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    int32_t t2;
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l6, &l7, &t0 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 6u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = (void*) &vader_data_87;
    vader_array_t* _a0_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    l2 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) INT64_C(0));
    l3 = vader_emit_bytecode$push_op_with_span(l0, vader_ref_box(l2), l1);
    l4 = vader_array_length(((vader_array_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_scopes));
    if (l4 == INT64_C(0)) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l2 = ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_scopes;
    l5 = vader_chk_sub(i64, l4, INT64_C(1));
    vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
    l2 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l5);
    vader_array_t* _a2_arr = vader_array_new(233u, 0u, 13u, 1388u);
    l6 = (void*) _a2_arr;
    l5 = INT64_C(0);
    l4 = vader_chk_sub(i64, l4, INT64_C(1));
    while ((l5 < l4)) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_scopes);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l5)
        l7 = vader_array_ref_load_obj(_a3_slotarr->buf, vader_array_offset(_a3_slotarr) + (size_t) l5);
        vader_array_push_ref((vader_array_t*) l6, l7);
        l5 = (l5 + INT64_C(1));
    }
    ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_scopes = l6;
    VADER_WRITE_BARRIER((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0);
    t1 = ((vader_struct_vader_emit_bytecode$ScopeFrame_t*) l2)->f_kind;
    if (t1 != 2748u) {
        l6 = ((vader_struct_vader_core_bytecode$BcFunction_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_slot)->f_jump_table;
        l8 = ((vader_struct_vader_emit_bytecode$ScopeFrame_t*) l2)->f_opener_pc;
        vader_array_t* _a4_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l8)
        t2 = ((int32_t*) _a4_slotarr->buf->slots)[vader_array_offset(_a4_slotarr) + (size_t) l8];
        if ((t2 < INT32_C(0))) {
            l6 = ((vader_struct_vader_core_bytecode$BcFunction_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_slot)->f_jump_table;
            l8 = ((vader_struct_vader_emit_bytecode$ScopeFrame_t*) l2)->f_opener_pc;
            l9 = vader_chk_add(i32, l3, INT32_C(1));
            vader_array_t* _a5_slotarr = ((vader_array_t*) l6);
            VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l8)
            ((int32_t*) _a5_slotarr->buf->slots)[vader_array_offset(_a5_slotarr) + (size_t) l8] = (int32_t) l9;
        }
    }
    l8 = ((vader_struct_vader_emit_bytecode$ScopeFrame_t*) l2)->f_target_blk;
    t1 = ((vader_struct_vader_emit_bytecode$ScopeFrame_t*) l2)->f_kind;
    l10 = t1 == 2748u;
    l9 = ((vader_struct_vader_emit_bytecode$ScopeFrame_t*) l2)->f_opener_pc;
    vader_emit_bytecode$drain_pending(l0, l8, l10, l9, l3);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_bytecode$cf_if(void* l0, void* l1) {
    void* l2 = NULL;
    void* l4 = NULL;
    int32_t l3;
    void* t0 = NULL;
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l4, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = (void*) &vader_data_98;
    vader_array_t* _a0_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    l2 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) INT64_C(0));
    l3 = vader_emit_bytecode$push_op_with_span(l0, vader_ref_box(l2), l1);
    l2 = ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_scopes;
    vader_struct_vader_emit_bytecode$ScopeFrame_t* _a1_obj = (vader_struct_vader_emit_bytecode$ScopeFrame_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_bytecode$ScopeFrame_t));
    vader_obj_header_init(_a1_obj, 1388u);
    _a1_obj->f_kind = 2584u;
    _a1_obj->f_target_blk = INT32_C(-1);
    _a1_obj->f_opener_pc = l3;
    l4 = (void*) _a1_obj;
    vader_array_push_ref((vader_array_t*) l2, l4);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_bytecode$cf_loop(void* l0, void* l1, int32_t l2) {
    void* l3 = NULL;
    void* l5 = NULL;
    int32_t l4, l6;
    void* t0 = NULL;
    void** gc_raw_roots[5] = { &l0, &l1, &l3, &l5, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = (void*) &vader_data_86;
    vader_array_t* _a0_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    l3 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) INT64_C(0));
    l4 = vader_emit_bytecode$push_op_with_span(l0, vader_ref_box(l3), l1);
    l3 = ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_scopes;
    vader_struct_vader_emit_bytecode$ScopeFrame_t* _a1_obj = (vader_struct_vader_emit_bytecode$ScopeFrame_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_bytecode$ScopeFrame_t));
    vader_obj_header_init(_a1_obj, 1388u);
    _a1_obj->f_kind = 2748u;
    _a1_obj->f_target_blk = l2;
    _a1_obj->f_opener_pc = l4;
    l5 = (void*) _a1_obj;
    vader_array_push_ref((vader_array_t*) l3, l5);
    l3 = ((vader_struct_vader_core_bytecode$BcFunction_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_slot)->f_jump_table;
    l6 = vader_chk_add(i32, l4, INT32_C(1));
    vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
    ((int32_t*) _a2_slotarr->buf->slots)[vader_array_offset(_a2_slotarr) + (size_t) l4] = (int32_t) l6;
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_bytecode$close_blocks(void* l0, void* l1, void* l2, int32_t l3) {
    int64_t l4, l5, l7, l8, l9;
    int32_t l6, l11, l13;
    void* l10 = NULL;
    void* l12 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l10, &l12, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 6u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l4 = INT64_C(0);
    l5 = vader_array_length(((vader_array_t*) l2));
    while ((l4 < l5)) {
        l7 = vader_chk_add(i64, l4, INT64_C(1));
        l8 = vader_array_length(((vader_array_t*) l2));
        if ((l7 < l8)) {
            l9 = vader_chk_add(i64, l4, INT64_C(1));
            vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l9)
            l6 = ((int32_t*) _a0_slotarr->buf->slots)[vader_array_offset(_a0_slotarr) + (size_t) l9];
        } else {
            l6 = l3;
        }
        l10 = ((vader_struct_vader_midir$CFGFunction_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_fn_)->f_blocks;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l11 = ((int32_t*) _a1_slotarr->buf->slots)[vader_array_offset(_a1_slotarr) + (size_t) l4];
        vader_array_t* _a2_slotarr = ((vader_array_t*) l10);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l11)
        t0 = vader_array_ref_load_obj(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l11);
        l12 = ((vader_struct_vader_midir$BasicBlock_t*) t0)->f_span;
        vader_emit_bytecode$cf_end(l0, l12);
        vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        l13 = ((int32_t*) _a3_slotarr->buf->slots)[vader_array_offset(_a3_slotarr) + (size_t) l4];
        vader_emit_bytecode$emit_subtree(l0, l1, l13, l6);
        l4 = (l4 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static bool vader_emit_bytecode$closes_loop(void* l0, int32_t l1, int32_t l2) {
    vader_box_t l3;
    void* t0;
    bool t1;
    l3 = std_collections$Map$std_core$Index$at__i32__Any(l0, l2);
    if (l3.tag == 0u) {
        return false;
    }
    t0 = l3.payload.obj;
    t1 = std_collections$Set$std_core$Contains$contains__i32(t0, l1);
    return t1;
}

static vader_box_t vader_emit_bytecode$closure_header_type(vader_box_t l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[4] = { &l1, &l2, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 1353u) {
        t0 = l0.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a0_arr = vader_array_new(450u, 0u, 13u, 2396u);
    l1 = (void*) _a0_arr;
    t0 = (void*) &vader_data_43;
    vader_array_t* _a1_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    l2 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) INT64_C(0));
    vader_array_t* _a2_arr = vader_array_new(222u, 0u, 13u, 1370u);
    l3 = (void*) _a2_arr;
    t0 = vader_core_types$mk_fn(l1, vader_ref_box(l2), l3);
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_emit_bytecode$collect_baked_types(vader_box_t l0, void* l1, void* l2) {
    int32_t l3;
    void* l4 = NULL;
    int64_t l5, l6;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l0, &t1 };
    void** gc_raw_roots[4] = { &l1, &l2, &l4, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 1196u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_core_bytecode$BcValStruct_t*) t0)->f_symbol_id;
        std_collections$add__i32(l2, l3);
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_core_bytecode$BcValStruct_t*) t0)->f_fields;
        l5 = vader_array_length(((vader_array_t*) l4));
        l6 = INT64_C(0);
        while ((l6 < l5)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            t1 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l6);
            vader_emit_bytecode$collect_baked_types(t1, l1, l2);
            l6 = (l6 + INT64_C(1));
        }
    } else if (l0.tag == 1193u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_core_bytecode$BcValArray_t*) t0)->f_type_id;
        vader_array_push_i32((vader_array_t*) l1, l3);
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_core_bytecode$BcValArray_t*) t0)->f_elements;
        l5 = vader_array_length(((vader_array_t*) l4));
        l6 = INT64_C(0);
        while ((l6 < l5)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l4);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            t1 = vader_array_ref_load_box(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l6);
            vader_emit_bytecode$collect_baked_types(t1, l1, l2);
            l6 = (l6 + INT64_C(1));
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static bool vader_emit_bytecode$compares_boxes(uint8_t l0, vader_box_t l1) {
    bool l2;
    bool t0;
    if (l0 == INT32_C(12)) {
        l2 = true;
    } else {
        l2 = l0 == INT32_C(13);
    }
    if (l2) {
        t0 = vader_emit_bytecode$is_union_slot(l1);
        return t0;
    }
    return false;
}

static bool vader_emit_bytecode$const_fills_slot(vader_box_t l0, uint8_t l1) {
    bool t0;
    uint8_t t1;
    if (l0.tag == 1270u) {
        t0 = vader_core_bytecode$is_64_bit_int_val(l1);
        return t0;
    }
    if (!(l0.tag == 1250u)) {
        t1 = vader_emit_bytecode$const_val_type(l0);
        return t1 == l1;
    }
    t0 = vader_core_bytecode$is_integer_val(l1);
    if (t0) {
        t0 = vader_core_bytecode$is_64_bit_int_val(l1);
        return !(t0);
    }
    return false;
}

static uint8_t vader_emit_bytecode$const_val_type(vader_box_t l0) {
    uint8_t l1;
    if (l0.tag == 1250u) {
        l1 = (uint8_t) 2;
        return l1;
    }
    if (l0.tag == 1270u) {
        l1 = (uint8_t) 3;
    } else if (l0.tag == 1229u) {
        l1 = (uint8_t) 9;
    } else if (l0.tag == 1201u) {
        l1 = (uint8_t) 10;
    } else if (l0.tag == 1216u) {
        l1 = (uint8_t) 11;
    } else if (l0.tag == 1318u) {
        l1 = (uint8_t) 12;
    } else {
        if (!(l0.tag == 1302u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = (uint8_t) 13;
    }
    return l1;
}

static void* vader_emit_bytecode$convert_data_pool(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l7 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    void* l12 = NULL;
    void* l16 = NULL;
    void* l17 = NULL;
    void* l18 = NULL;
    void* l23 = NULL;
    int64_t l4, l5, l8, l9, l13, l14, l19, l20;
    vader_box_t l6 = vader_box_null(), l21 = vader_box_null(), l22 = vader_box_null();
    uint64_t l15;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_string_t t2 = 0;
    int64_t t3, t4;
    uint8_t t5;
    vader_box_t* gc_roots[4] = { &l6, &l21, &l22, &t1 };
    void** gc_raw_roots[13] = {
        &l0, &l1, &l2, &l3, &l7, &l10, &l11, &l12, &l16, &l17, &l18, &l23, &t0,
    };
    vader_string_t* gc_atom_roots[1] = { &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 13u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(446u, 0u, 13u, 2318u);
    l2 = (void*) _a0_arr;
    l3 = l1;
    l4 = vader_array_length(((vader_array_t*) l3));
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l6 = vader_array_ref_load_box(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l5);
        if (l6.tag == 1805u) {
            t0 = l6.payload.obj;
            l7 = ((vader_struct_vader_lower_ir$StrDataPoolEntry_t*) t0)->f_values;
            l8 = vader_array_length(((vader_array_t*) l7));
            l9 = INT64_C(0);
            while ((l9 < l8)) {
                vader_array_t* _a2_slotarr = ((vader_array_t*) l7);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                t1 = vader_array_box_slots(_a2_slotarr->buf)[vader_array_offset(_a2_slotarr) + (size_t) l9];
                t2 = t1.payload.s;
                vader_emit_bytecode$intern_string(t2, l0);
                l9 = (l9 + INT64_C(1));
            }
            t0 = l6.payload.obj;
            vader_struct_vader_core_bytecode$BcStrData_t* _a3_obj = (vader_struct_vader_core_bytecode$BcStrData_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcStrData_t));
            vader_obj_header_init(_a3_obj, 1190u);
            _a3_obj->f_values = ((vader_struct_vader_lower_ir$StrDataPoolEntry_t*) t0)->f_values;
            l10 = (void*) _a3_obj;
            vader_array_push_ref((vader_array_t*) l2, l10);
        } else if (l6.tag == 1804u) {
            vader_array_t* _a4_arr = vader_array_new(32u, 0u, 4u, 585u);
            l11 = (void*) _a4_arr;
            t0 = l6.payload.obj;
            l12 = ((vader_struct_vader_lower_ir$PrimDataPoolEntry_t*) t0)->f_items;
            l13 = vader_array_length(((vader_array_t*) l12));
            l14 = INT64_C(0);
            vader_array_t* _pc68_hdr = (vader_array_t*) l11;
            size_t _pc68_len = vader_array_length(_pc68_hdr);
            size_t _pc68_cap = vader_array_is_borrowed(_pc68_hdr) ? (size_t) 0 : vader_array_capacity(_pc68_hdr);
            void* _pc68_slots = _pc68_hdr->buf->slots;
            for (;;) {
                if ((l14 < l13)) {
                    vader_array_t* _a5_slotarr = ((vader_array_t*) l12);
                    VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
                    t3 = ((int64_t*) _a5_slotarr->buf->slots)[vader_array_offset(_a5_slotarr) + (size_t) l14];
                    t4 = t3;
                    l15 = (uint64_t) (int64_t) t4;
                    if (VADER_LIKELY(_pc68_len < _pc68_cap)) {
                        ((int64_t*) _pc68_slots)[_pc68_len] = (int64_t) ((int64_t) (uint64_t) l15);
                        _pc68_len += 1;
                    } else {
                        vader_array_set_length(_pc68_hdr, _pc68_len);
                        if (_pc68_hdr->buf->length < _pc68_len) {
                            _pc68_hdr->buf->length = _pc68_len;
                        }
                        vader_array_push_i64((vader_array_t*) l11, (int64_t) (uint64_t) l15);
                        _pc68_hdr = (vader_array_t*) l11;
                        _pc68_len = vader_array_length(_pc68_hdr);
                        _pc68_cap = vader_array_is_borrowed(_pc68_hdr) ? (size_t) 0 : vader_array_capacity(_pc68_hdr);
                        _pc68_slots = _pc68_hdr->buf->slots;
                    }
                    l14 = (l14 + INT64_C(1));
                    continue;
                }
                vader_array_set_length(_pc68_hdr, _pc68_len);
                if (_pc68_hdr->buf->length < _pc68_len) {
                    _pc68_hdr->buf->length = _pc68_len;
                }
                break;
            }
            t0 = l6.payload.obj;
            t2 = ((vader_struct_vader_lower_ir$PrimDataPoolEntry_t*) t0)->f_element_type_name;
            t5 = vader_core_bytecode$array_kind_from_name(t2);
            vader_struct_vader_core_bytecode$BcPrimData_t* _a6_obj = (vader_struct_vader_core_bytecode$BcPrimData_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcPrimData_t));
            vader_obj_header_init(_a6_obj, 1186u);
            _a6_obj->f_kind = t5;
            _a6_obj->f_items = l11;
            l16 = (void*) _a6_obj;
            vader_array_push_ref((vader_array_t*) l2, l16);
        } else {
            if (!(l6.tag == 1743u)) {
                vader_unreachable("non-exhaustive match (T3013 should have caught this)");
            }
            vader_array_t* _a7_arr = vader_array_new(448u, 0u, 13u, 2329u);
            l17 = (void*) _a7_arr;
            t0 = l6.payload.obj;
            l18 = ((vader_struct_vader_lower_ir$LoweredArrayLit_t*) ((vader_struct_vader_lower_ir$AggregateDataPoolEntry_t*) t0)->f_literal)->f_elements;
            l19 = vader_array_length(((vader_array_t*) l18));
            l20 = INT64_C(0);
            while ((l20 < l19)) {
                vader_array_t* _a8_slotarr = ((vader_array_t*) l18);
                VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
                l21 = vader_array_ref_load_box(_a8_slotarr->buf, vader_array_offset(_a8_slotarr) + (size_t) l20);
                l22 = vader_emit_bytecode$baked_value(l0, l21);
                vader_array_push_ref((vader_array_t*) l17, l22.payload.obj);
                l20 = (l20 + INT64_C(1));
            }
            vader_struct_vader_core_bytecode$BcAggregateData_t* _a9_obj = (vader_struct_vader_core_bytecode$BcAggregateData_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcAggregateData_t));
            vader_obj_header_init(_a9_obj, 1177u);
            _a9_obj->f_elements = l17;
            l23 = (void*) _a9_obj;
            vader_array_push_ref((vader_array_t*) l2, l23);
        }
        l5 = (l5 + INT64_C(1));
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_emit_bytecode$convert_eligible(uint8_t l0) {
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

static bool vader_emit_bytecode$copies_cheaply(void* l0) {
    bool t0;
    int64_t t1;
    t0 = vader_emit_bytecode$ends_function(((vader_struct_vader_midir$BasicBlock_t*) l0)->f_terminator);
    if (t0) {
        t1 = vader_array_length(((vader_array_t*) ((vader_struct_vader_midir$BasicBlock_t*) l0)->f_instructions));
        return (t1 <= INT64_C(2));
    }
    return false;
}

static void* vader_emit_bytecode$data_pool_type_roots(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    int64_t l6, l7, l9, l10;
    vader_box_t l8 = vader_box_null();
    int32_t l11, l12;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l8, &t1 };
    void** gc_raw_roots[7] = { &l0, &l1, &l2, &l3, &l4, &l5, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 7u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(27u, 0u, 7u, 580u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(27u, 0u, 7u, 580u);
    l3 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(24u, 0u, 12u, 575u);
    l4 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(27u, 0u, 7u, 580u);
    l5 = (void*) _a3_arr;
    vader_struct_std_collections$Map__i32__bool_t* _a4_obj = (vader_struct_std_collections$Map__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__i32__bool_t));
    vader_obj_header_init(_a4_obj, 815u);
    _a4_obj->f_ekeys = l3;
    _a4_obj->f_evals = l4;
    _a4_obj->f_index = l5;
    _a4_obj->f_mask = INT64_C(0);
    _a4_obj->f_grow_at = INT64_C(0);
    _a4_obj->f_size = INT64_C(0);
    _a4_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a4_obj;
    vader_struct_std_collections$Set__i32_t* _a5_obj = (vader_struct_std_collections$Set__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Set__i32_t));
    vader_obj_header_init(_a5_obj, 989u);
    _a5_obj->f_inner = t0;
    l3 = (void*) _a5_obj;
    l4 = l1;
    l6 = vader_array_length(((vader_array_t*) l4));
    l7 = INT64_C(0);
    while ((l7 < l6)) {
        vader_array_t* _a6_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        l8 = vader_array_ref_load_box(_a6_slotarr->buf, vader_array_offset(_a6_slotarr) + (size_t) l7);
        if (l8.tag == 1177u) {
            t0 = l8.payload.obj;
            l5 = ((vader_struct_vader_core_bytecode$BcAggregateData_t*) t0)->f_elements;
            l9 = vader_array_length(((vader_array_t*) l5));
            l10 = INT64_C(0);
            while ((l10 < l9)) {
                vader_array_t* _a7_slotarr = ((vader_array_t*) l5);
                VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
                t1 = vader_array_ref_load_box(_a7_slotarr->buf, vader_array_offset(_a7_slotarr) + (size_t) l10);
                vader_emit_bytecode$collect_baked_types(t1, l2, l3);
                l10 = (l10 + INT64_C(1));
            }
        }
        l7 = (l7 + INT64_C(1));
    }
    l4 = ((vader_struct_std_collections$Map__i32__bool_t*) ((vader_struct_std_collections$Set__i32_t*) l3)->f_inner)->f_ekeys;
    l6 = INT64_C(0);
    l7 = ((vader_struct_std_collections$Map__i32__bool_t*) ((vader_struct_std_collections$Set__i32_t*) l3)->f_inner)->f_size;
    while ((l6 < l7)) {
        vader_array_t* _a8_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l6)
        l11 = ((int32_t*) _a8_slotarr->buf->slots)[vader_array_offset(_a8_slotarr) + (size_t) l6];
        l12 = vader_core_bytecode$struct_symbol_type_index(((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_types, l11);
        if ((l12 >= INT32_C(0))) {
            vader_array_push_i32((vader_array_t*) l2, l12);
        }
        l6 = (l6 + INT64_C(1));
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_emit_bytecode$debug_pos_of_span(void* l0) {
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
    t0 = toolchain_span$has_source_position(l0);
    if (!(t0)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l1 = ((vader_struct_toolchain_span$Position_t*) ((vader_struct_toolchain_span$Span_t*) l0)->f_start)->f_file;
    l2 = ((vader_struct_toolchain_span$Position_t*) ((vader_struct_toolchain_span$Span_t*) l0)->f_start)->f_line;
    l3 = ((vader_struct_toolchain_span$Position_t*) ((vader_struct_toolchain_span$Span_t*) l0)->f_start)->f_column;
    vader_struct_vader_core_bytecode$DebugPos_t* _a0_obj = (vader_struct_vader_core_bytecode$DebugPos_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$DebugPos_t));
    vader_obj_header_init(_a0_obj, 1221u);
    _a0_obj->f_file = l1;
    _a0_obj->f_line = l2;
    _a0_obj->f_column = l3;
    t1 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_emit_bytecode$default_emit_options(void) {
    void* l0 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(26u, 0u, 0u, 577u);
    l0 = (void*) _a0_arr;
    vader_struct_vader_emit_bytecode$EmitOptions_t* _a1_obj = (vader_struct_vader_emit_bytecode$EmitOptions_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_bytecode$EmitOptions_t));
    vader_obj_header_init(_a1_obj, 1380u);
    _a1_obj->f_optimize = true;
    _a1_obj->f_keep_mangles = l0;
    _a1_obj->f_want_debug = false;
    t0 = (void*) _a1_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_emit_bytecode$defer_or_resolve_branch(void* l0, int32_t l1, int32_t l2) {
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
    l3 = ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_scopes;
    l4 = vader_array_length(((vader_array_t*) l3));
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l6 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l5);
        t0 = ((vader_struct_vader_emit_bytecode$ScopeFrame_t*) l6)->f_kind;
        if (t0 == 2748u) {
            t1 = vader_midir$BlockId$std_core$Equals$equals(((vader_struct_vader_emit_bytecode$ScopeFrame_t*) l6)->f_target_blk, l1);
            if (t1) {
                l7 = ((vader_struct_vader_core_bytecode$BcFunction_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_slot)->f_jump_table;
                t2 = ((vader_struct_vader_emit_bytecode$ScopeFrame_t*) l6)->f_opener_pc;
                l8 = vader_chk_add(i32, t2, INT32_C(1));
                vader_array_t* _a1_slotarr = ((vader_array_t*) l7);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l2)
                ((int32_t*) _a1_slotarr->buf->slots)[vader_array_offset(_a1_slotarr) + (size_t) l2] = (int32_t) l8;
                { vader_gc_top = gc_frame.prev; return; }
            }
        }
        l5 = (l5 + INT64_C(1));
    }
    l3 = ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_pending;
    vader_struct_vader_emit_bytecode$PendingBranch_t* _a2_obj = (vader_struct_vader_emit_bytecode$PendingBranch_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_bytecode$PendingBranch_t));
    vader_obj_header_init(_a2_obj, 1384u);
    _a2_obj->f_branch_pc = l2;
    _a2_obj->f_target_blk = l1;
    l6 = (void*) _a2_obj;
    vader_array_push_ref((vader_array_t*) l3, l6);
    { vader_gc_top = gc_frame.prev; return; }
}

static int32_t vader_emit_bytecode$destination(void* l0, int32_t l1) {
    int32_t l2, l5, l6;
    int64_t l3, l4;
    int32_t t0;
    l2 = l1;
    l3 = INT64_C(0);
    l4 = vader_array_length(((vader_array_t*) l0));
    while ((l3 < l4)) {
        l5 = l2;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
        t0 = ((int32_t*) _a0_slotarr->buf->slots)[vader_array_offset(_a0_slotarr) + (size_t) l5];
        if ((t0 < INT32_C(0))) {
            return l2;
        }
        l6 = l2;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l6)
        l2 = ((int32_t*) _a1_slotarr->buf->slots)[vader_array_offset(_a1_slotarr) + (size_t) l6];
        l3 = (l3 + INT64_C(1));
    }
    return l1;
}

static void vader_emit_bytecode$drain_pending(void* l0, int32_t l1, bool l2, int32_t l3, int32_t l4) {
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
    vader_array_t* _a0_arr = vader_array_new(230u, 0u, 13u, 1384u);
    l6 = (void*) _a0_arr;
    l7 = ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_pending;
    l8 = vader_array_length(((vader_array_t*) l7));
    l9 = INT64_C(0);
    while ((l9 < l8)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l10 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l9);
        t0 = vader_midir$BlockId$std_core$Equals$equals(((vader_struct_vader_emit_bytecode$PendingBranch_t*) l10)->f_target_blk, l1);
        if (t0) {
            l11 = ((vader_struct_vader_core_bytecode$BcFunction_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_slot)->f_jump_table;
            l12 = ((vader_struct_vader_emit_bytecode$PendingBranch_t*) l10)->f_branch_pc;
            vader_array_t* _a2_slotarr = ((vader_array_t*) l11);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l12)
            ((int32_t*) _a2_slotarr->buf->slots)[vader_array_offset(_a2_slotarr) + (size_t) l12] = (int32_t) l5;
        } else {
            vader_array_push_ref((vader_array_t*) l6, l10);
        }
        l9 = (l9 + INT64_C(1));
    }
    ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_pending = l6;
    VADER_WRITE_BARRIER((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0);
    { vader_gc_top = gc_frame.prev; return; }
}

static void* vader_emit_bytecode$drop_unbranched_blocks(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l4 = NULL;
    void* l7 = NULL;
    void* l10 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    int64_t l3, l5, l9;
    int32_t l6;
    bool l8;
    vader_box_t l11 = vader_box_null();
    vader_string_t l12 = 0;
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    bool t2, t3;
    int64_t t4;
    vader_box_t* gc_roots[2] = { &l11, &t0 };
    void** gc_raw_roots[9] = { &l0, &l1, &l2, &l4, &l7, &l10, &l13, &l14, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l12 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 9u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_body;
    l2 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_jump_table;
    l3 = vader_array_length(((vader_array_t*) l1));
    vader_array_t* _a0_arr = vader_array_new(24u, 1u, 12u, 575u);
    ((uint8_t*) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = (uint8_t) false;
    l4 = (void*) _a0_arr;
    l5 = vader_chk_add(i64, l3, INT64_C(1));
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l4, (int64_t) l5);
    l4 = (void*) _a1_arr;
    l5 = INT64_C(0);
    while ((l5 < l3)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l5)
        l6 = ((int32_t*) _a2_slotarr->buf->slots)[vader_array_offset(_a2_slotarr) + (size_t) l5];
        vader_array_t* _a3_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        t0 = vader_array_ref_load_box(_a3_slotarr->buf, vader_array_offset(_a3_slotarr) + (size_t) l5);
        if ((t0.tag == 1206u || t0.tag == 1207u)) {
            if ((l6 >= INT32_C(0))) {
                if ((((int64_t) (int32_t) l6) <= l3)) {
                    vader_array_t* _a4_slotarr = ((vader_array_t*) l4);
                    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l6)
                    ((uint8_t*) _a4_slotarr->buf->slots)[vader_array_offset(_a4_slotarr) + (size_t) l6] = (uint8_t) true;
                }
            }
        }
        l5 = (l5 + INT64_C(1));
    }
    vader_array_t* _a5_arr = vader_array_new(24u, 1u, 12u, 575u);
    ((uint8_t*) _a5_arr->buf->slots)[vader_array_offset(_a5_arr) + 0u] = (uint8_t) false;
    t1 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_repeat((vader_array_t*) t1, (int64_t) l3);
    l7 = (void*) _a6_arr;
    l8 = false;
    l5 = INT64_C(0);
    while ((l5 < l3)) {
        vader_array_t* _a7_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l5)
        l6 = ((int32_t*) _a7_slotarr->buf->slots)[vader_array_offset(_a7_slotarr) + (size_t) l5];
        vader_array_t* _a8_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
        t0 = vader_array_ref_load_box(_a8_slotarr->buf, vader_array_offset(_a8_slotarr) + (size_t) l5);
        if (t0.tag == 1199u) {
            if ((l6 > INT32_C(0))) {
                vader_array_t* _a9_slotarr = ((vader_array_t*) l4);
                VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l6)
                t2 = ((uint8_t*) _a9_slotarr->buf->slots)[vader_array_offset(_a9_slotarr) + (size_t) l6];
                t3 = t2;
                if (!(t3)) {
                    vader_array_t* _a10_slotarr = ((vader_array_t*) l7);
                    VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a10_slotarr, l5)
                    ((uint8_t*) _a10_slotarr->buf->slots)[vader_array_offset(_a10_slotarr) + (size_t) l5] = (uint8_t) true;
                    l9 = vader_chk_sub(i64, ((int64_t) (int32_t) l6), INT64_C(1));
                    VADER_ARRAY_CHECK_INDEX(_a10_slotarr, l9)
                    ((uint8_t*) _a10_slotarr->buf->slots)[vader_array_offset(_a10_slotarr) + (size_t) l9] = (uint8_t) true;
                    l8 = true;
                }
            }
        }
        l5 = (l5 + INT64_C(1));
    }
    if (!(l8)) {
        { void* __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a11_arr = vader_array_new(445u, 0u, 13u, 2295u);
    l4 = (void*) _a11_arr;
    vader_array_t* _a12_arr = vader_array_new(27u, 0u, 7u, 580u);
    l10 = (void*) _a12_arr;
    l5 = INT64_C(0);
    while ((l5 < l3)) {
        vader_array_t* _a13_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a13_slotarr, l5)
        t2 = ((uint8_t*) _a13_slotarr->buf->slots)[vader_array_offset(_a13_slotarr) + (size_t) l5];
        t3 = t2;
        if (t3) {
            vader_array_push_i32((vader_array_t*) l10, INT32_C(-1));
        } else {
            t4 = vader_array_length(((vader_array_t*) l4));
            l6 = ((int32_t) (int64_t) t4);
            vader_array_push_i32((vader_array_t*) l10, l6);
            vader_array_t* _a14_slotarr = ((vader_array_t*) l1);
            VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
            l11 = vader_array_ref_load_box(_a14_slotarr->buf, vader_array_offset(_a14_slotarr) + (size_t) l5);
            vader_array_push_ref((vader_array_t*) l4, l11.payload.obj);
        }
        l5 = (l5 + INT64_C(1));
    }
    l1 = l0;
    l12 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l1)->f_name;
    l8 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l1)->f_is_main;
    l7 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l1)->f_signature;
    l13 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l1)->f_locals;
    l14 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_debug;
    l3 = vader_array_length(((vader_array_t*) l4));
    l14 = vader_emit_bytecode$remap_debug(l14, l10, l3);
    l3 = vader_array_length(((vader_array_t*) l4));
    l2 = vader_core_bytecode$remap_jump_table(l2, l10, l3);
    l1 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l1)->f_source_pc;
    vader_struct_vader_core_bytecode$BcFunction_t* _a15_obj = (vader_struct_vader_core_bytecode$BcFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcFunction_t));
    vader_obj_header_init(_a15_obj, 1182u);
    _a15_obj->f_name = l12;
    _a15_obj->f_is_main = l8;
    _a15_obj->f_signature = l7;
    _a15_obj->f_locals = l13;
    _a15_obj->f_body = l4;
    _a15_obj->f_debug = l14;
    _a15_obj->f_jump_table = l2;
    _a15_obj->f_source_pc = l1;
    t1 = (void*) _a15_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_emit_bytecode$emit_body(void* l0, void* l1, int32_t l2, int32_t l3, int32_t l4) {
    void* l5 = NULL;
    void* l8 = NULL;
    int32_t l6, l9;
    int64_t l7, l10;
    void* t0 = NULL;
    void** gc_raw_roots[5] = { &l0, &l1, &l5, &l8, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l5 = ((vader_struct_vader_emit_bytecode$StructureShape_t*) l1)->f_merges;
    l6 = l2;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l6)
    l5 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l6);
    l7 = vader_emit_bytecode$last_empty_stack_point(l0, l2);
    vader_emit_bytecode$emit_instructions(l0, l2, INT64_C(0), l7);
    l6 = vader_emit_bytecode$open_blocks(l0, l5, l3);
    l8 = ((vader_struct_vader_midir$CFGFunction_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_fn_)->f_blocks;
    l9 = l2;
    vader_array_t* _a1_slotarr = ((vader_array_t*) l8);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l9)
    t0 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l9);
    l10 = vader_array_length(((vader_array_t*) ((vader_struct_vader_midir$BasicBlock_t*) t0)->f_instructions));
    vader_emit_bytecode$emit_instructions(l0, l2, l7, l10);
    vader_emit_bytecode$emit_terminator(l0, l1, l2, l6, l4);
    vader_emit_bytecode$close_blocks(l0, l1, l5, l3);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_bytecode$emit_branch(void* l0, void* l1, int32_t l2, int32_t l3, int32_t l4, void* l5) {
    bool t0;
    void** gc_raw_roots[3] = { &l0, &l1, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_midir$BlockId$std_core$Equals$equals(l3, l4);
    if (t0) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    t0 = vader_emit_bytecode$only_jumps(l1, l2, l3);
    if (!(t0)) {
        vader_emit_bytecode$emit_subtree(l0, l1, l3, l4);
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_emit_bytecode$cf_br(l0, l5, l3);
    { vader_gc_top = gc_frame.prev; return; }
}

void* vader_emit_bytecode$emit_bytecode_from_cfg(void* l0, vader_string_t l1, void* l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l9 = NULL;
    void* l12 = NULL;
    void* l15 = NULL;
    void* l21 = NULL;
    void* l24 = NULL;
    int64_t l7, l8, l10, l11, l13, l14, l16, l17;
    int32_t l18, l22;
    vader_string_t l19 = 0;
    vader_string_t l27 = 0;
    vader_box_t l20 = vader_box_null(), l23 = vader_box_null(), l25 = vader_box_null();
    bool l26;
    vader_box_t t0 = vader_box_null();
    vader_string_t t1 = 0;
    void* t2 = NULL;
    int64_t t3;
    bool t4;
    vader_box_t* gc_roots[4] = { &l20, &l23, &l25, &t0 };
    void** gc_raw_roots[12] = { &l0, &l2, &l3, &l4, &l5, &l6, &l9, &l12, &l15, &l21, &l24, &t2 };
    vader_string_t* gc_atom_roots[4] = { &l1, &l19, &l27, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 12u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = vader_emit_bytecode$new_emitter_ctx();
    l4 = ((vader_struct_vader_midir$CFGProject_t*) l0)->f_dispatched_instances;
    ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l3)->f_dispatched_instances = l4;
    VADER_WRITE_BARRIER((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l3);
    l4 = ((vader_struct_vader_midir$CFGProject_t*) l0)->f_modules;
    l5 = ((vader_struct_std_collections$Map__string__vader_midir_CFGModule_t*) l4)->f_ekeys;
    l6 = ((vader_struct_std_collections$Map__string__vader_midir_CFGModule_t*) l4)->f_evals;
    l7 = INT64_C(0);
    l8 = ((vader_struct_std_collections$Map__string__vader_midir_CFGModule_t*) l4)->f_size;
    while ((l7 < l8)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l7)
        t0 = vader_array_box_slots(_a0_slotarr->buf)[vader_array_offset(_a0_slotarr) + (size_t) l7];
        t1 = t0.payload.s;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l7)
        l4 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l7);
        l9 = ((vader_struct_vader_midir$CFGModule_t*) l4)->f_functions;
        l10 = vader_array_length(((vader_array_t*) l9));
        l11 = INT64_C(0);
        while ((l11 < l10)) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) l9);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            t2 = vader_array_ref_load_obj(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l11);
            vader_emit_bytecode$reserve_cfg_function(t2, l3);
            l11 = (l11 + INT64_C(1));
        }
        l12 = ((vader_struct_vader_midir$CFGModule_t*) l4)->f_externs;
        l13 = vader_array_length(((vader_array_t*) l12));
        l14 = INT64_C(0);
        while ((l14 < l13)) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l12);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l14)
            t2 = vader_array_ref_load_obj(_a3_slotarr->buf, vader_array_offset(_a3_slotarr) + (size_t) l14);
            vader_emit_bytecode$reserve_cfg_extern(t2, l3);
            l14 = (l14 + INT64_C(1));
        }
        l15 = ((vader_struct_vader_midir$CFGModule_t*) l4)->f_struct_decls;
        l16 = vader_array_length(((vader_array_t*) l15));
        l17 = INT64_C(0);
        while ((l17 < l16)) {
            vader_array_t* _a4_slotarr = ((vader_array_t*) l15);
            VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
            t2 = vader_array_ref_load_obj(_a4_slotarr->buf, vader_array_offset(_a4_slotarr) + (size_t) l17);
            vader_emit_bytecode$reserve_cfg_struct(t2, l3);
            l17 = (l17 + INT64_C(1));
        }
        l7 = (l7 + INT64_C(1));
    }
    vader_emit_bytecode$lend_written_mirrors(l3);
    t3 = vader_array_length(((vader_array_t*) ((vader_struct_vader_midir$CFGProject_t*) l0)->f_strings));
    vader_array_t* _a5_arr = vader_array_reserve(27u, (int64_t) t3, 7u, 580u);
    l4 = (void*) _a5_arr;
    l5 = ((vader_struct_vader_midir$CFGProject_t*) l0)->f_strings;
    l7 = vader_array_length(((vader_array_t*) l5));
    l8 = INT64_C(0);
    while ((l8 < l7)) {
        vader_array_t* _a6_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        t0 = vader_array_box_slots(_a6_slotarr->buf)[vader_array_offset(_a6_slotarr) + (size_t) l8];
        t1 = t0.payload.s;
        l18 = vader_emit_bytecode$intern_string(t1, l3);
        vader_array_push_i32((vader_array_t*) l4, l18);
        l8 = (l8 + INT64_C(1));
    }
    l5 = ((vader_struct_vader_midir$CFGProject_t*) l0)->f_data_pool;
    l5 = vader_emit_bytecode$convert_data_pool(l3, l5);
    l6 = ((vader_struct_vader_midir$CFGProject_t*) l0)->f_globals;
    l7 = vader_array_length(((vader_array_t*) l6));
    l8 = INT64_C(0);
    while ((l8 < l7)) {
        vader_array_t* _a7_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
        l9 = vader_array_ref_load_obj(_a7_slotarr->buf, vader_array_offset(_a7_slotarr) + (size_t) l8);
        l12 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l3)->f_globals;
        l19 = ((vader_struct_vader_lower_ir$GlobalSlot_t*) l9)->f_name;
        l18 = vader_emit_bytecode$intern_type(((vader_struct_vader_lower_ir$GlobalSlot_t*) l9)->f_type, l3);
        vader_struct_vader_core_bytecode$BcGlobal_t* _a8_obj = (vader_struct_vader_core_bytecode$BcGlobal_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcGlobal_t));
        vader_obj_header_init(_a8_obj, 1183u);
        _a8_obj->f_name = l19;
        _a8_obj->f_type_id = l18;
        l15 = (void*) _a8_obj;
        vader_array_push_ref((vader_array_t*) l12, l15);
        l8 = (l8 + INT64_C(1));
    }
    l6 = ((vader_struct_vader_midir$CFGProject_t*) l0)->f_modules;
    l9 = ((vader_struct_std_collections$Map__string__vader_midir_CFGModule_t*) l6)->f_ekeys;
    l12 = ((vader_struct_std_collections$Map__string__vader_midir_CFGModule_t*) l6)->f_evals;
    l7 = INT64_C(0);
    l8 = ((vader_struct_std_collections$Map__string__vader_midir_CFGModule_t*) l6)->f_size;
    while ((l7 < l8)) {
        vader_array_t* _a9_slotarr = ((vader_array_t*) l9);
        VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l7)
        t0 = vader_array_box_slots(_a9_slotarr->buf)[vader_array_offset(_a9_slotarr) + (size_t) l7];
        t1 = t0.payload.s;
        vader_array_t* _a10_slotarr = ((vader_array_t*) l12);
        VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a10_slotarr, l7)
        t2 = vader_array_ref_load_obj(_a10_slotarr->buf, vader_array_offset(_a10_slotarr) + (size_t) l7);
        l6 = ((vader_struct_vader_midir$CFGModule_t*) t2)->f_functions;
        l10 = vader_array_length(((vader_array_t*) l6));
        l11 = INT64_C(0);
        while ((l11 < l10)) {
            vader_array_t* _a11_slotarr = ((vader_array_t*) l6);
            VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l11)
            l15 = vader_array_ref_load_obj(_a11_slotarr->buf, vader_array_offset(_a11_slotarr) + (size_t) l11);
            l18 = INT32_C(-1);
            l20 = ((vader_struct_vader_core_mono$MonoEntry_t*) ((vader_struct_vader_midir$CFGFunction_t*) l15)->f_origin)->f_symbol;
            if (l20.tag == 1346u) {
                l21 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l3)->f_function_index_by_symbol_id;
                t2 = l20.payload.obj;
                l22 = ((vader_struct_vader_core_symbol$Symbol_t*) t2)->f_id;
                l23 = std_collections$Map$std_core$Index$at__i32__i32(l21, l22);
                if (l23.tag == 580u) {
                    l18 = ((int32_t) l23.payload.i);
                }
            }
            if ((l18 < INT32_C(0))) {
                l24 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l3)->f_function_index_by_mangle;
                l19 = ((vader_struct_vader_midir$CFGFunction_t*) l15)->f_mangled;
                l25 = std_collections$Map$std_core$Index$at__string__i32(l24, l19);
                if (l25.tag == 580u) {
                    l18 = ((int32_t) l25.payload.i);
                }
            }
            if ((l18 >= INT32_C(0))) {
                l26 = ((vader_struct_vader_emit_bytecode$EmitOptions_t*) l2)->f_want_debug;
                vader_emit_bytecode$emit_cfg_function_body(l15, l18, l3, l4, l26);
            }
            l11 = (l11 + INT64_C(1));
        }
        l7 = (l7 + INT64_C(1));
    }
    t4 = ((vader_struct_vader_emit_bytecode$EmitOptions_t*) l2)->f_optimize;
    if (t4) {
        l4 = vader_emit_bytecode$planned_bytecode_stages();
        l7 = INT64_C(0);
        l8 = vader_array_length(((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l3)->f_functions));
        while ((l7 < l8)) {
            l6 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l3)->f_functions;
            vader_array_t* _a12_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l3)->f_functions);
            VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a12_slotarr, l7)
            l9 = vader_array_ref_load_obj(_a12_slotarr->buf, vader_array_offset(_a12_slotarr) + (size_t) l7);
            l12 = vader_emit_bytecode$run_bytecode_stages(l4, l9);
            vader_array_t* _a13_slotarr = ((vader_array_t*) l6);
            VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a13_slotarr, l7)
            vader_array_ref_store(_a13_slotarr->buf, vader_array_offset(_a13_slotarr) + (size_t) l7, l12);
            VADER_WRITE_BARRIER(_a13_slotarr->buf);
            l7 = (l7 + INT64_C(1));
        }
        vader_array_t* _a14_arr = vader_array_new(26u, 0u, 0u, 577u);
        l4 = (void*) _a14_arr;
        vader_array_t* _a15_arr = vader_array_new(24u, 0u, 12u, 575u);
        l6 = (void*) _a15_arr;
        vader_array_t* _a16_arr = vader_array_new(27u, 0u, 7u, 580u);
        l9 = (void*) _a16_arr;
        vader_struct_std_collections$Map__string__bool_t* _a17_obj = (vader_struct_std_collections$Map__string__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__bool_t));
        vader_obj_header_init(_a17_obj, 901u);
        _a17_obj->f_ekeys = l4;
        _a17_obj->f_evals = l6;
        _a17_obj->f_index = l9;
        _a17_obj->f_mask = INT64_C(0);
        _a17_obj->f_grow_at = INT64_C(0);
        _a17_obj->f_size = INT64_C(0);
        _a17_obj->f_tombs = INT64_C(0);
        l4 = (void*) _a17_obj;
        l6 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l3)->f_functions;
        l7 = vader_array_length(((vader_array_t*) l6));
        l8 = INT64_C(0);
        while ((l8 < l7)) {
            vader_array_t* _a18_slotarr = ((vader_array_t*) l6);
            VADER_ARRAY_RESOLVE_BUF(_a18_slotarr)
            t2 = vader_array_ref_load_obj(_a18_slotarr->buf, vader_array_offset(_a18_slotarr) + (size_t) l8);
            l9 = ((vader_struct_vader_core_bytecode$BcFunction_t*) t2)->f_body;
            l10 = vader_array_length(((vader_array_t*) l9));
            l11 = INT64_C(0);
            while ((l11 < l10)) {
                vader_array_t* _a19_slotarr = ((vader_array_t*) l9);
                VADER_ARRAY_RESOLVE_BUF(_a19_slotarr)
                l20 = vader_array_ref_load_box(_a19_slotarr->buf, vader_array_offset(_a19_slotarr) + (size_t) l11);
                if (l20.tag == 1341u) {
                    t2 = l20.payload.obj;
                    l19 = ((vader_struct_vader_core_bytecode$VirtualCall_t*) t2)->f_vtable_key;
                    std_collections$Map$std_core$IndexSet$set_at__string__bool(l4, l19, true);
                }
                l11 = (l11 + INT64_C(1));
            }
            l8 = (l8 + INT64_C(1));
        }
        vader_array_t* _a20_arr = vader_array_new(27u, 0u, 7u, 580u);
        l6 = (void*) _a20_arr;
        l9 = ((vader_struct_vader_midir$CFGProject_t*) l0)->f_vtable_entries;
        l7 = vader_array_length(((vader_array_t*) l9));
        l8 = INT64_C(0);
        while ((l8 < l7)) {
            vader_array_t* _a21_slotarr = ((vader_array_t*) l9);
            VADER_ARRAY_RESOLVE_BUF(_a21_slotarr)
            l12 = vader_array_ref_load_obj(_a21_slotarr->buf, vader_array_offset(_a21_slotarr) + (size_t) l8);
            l15 = ((vader_struct_vader_lower_ir$LoweredVtableEntry_t*) l12)->f_row_traits;
            vader_struct___lambda_env_vader_emit_bytecode_1_t* _a22_obj = (vader_struct___lambda_env_vader_emit_bytecode_1_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_emit_bytecode_1_t));
            vader_obj_header_init(_a22_obj, 621u);
            _a22_obj->f_cap_0 = l4;
            _a22_obj->f_cap_1 = l12;
            l21 = (void*) _a22_obj;
            l26 = false;
            l10 = vader_array_length(((vader_array_t*) l15));
            l11 = INT64_C(0);
            {
                while ((l11 < l10)) {
                    vader_array_t* _a23_slotarr = ((vader_array_t*) l15);
                    VADER_ARRAY_RESOLVE_BUF(_a23_slotarr)
                    t0 = vader_array_box_slots(_a23_slotarr->buf)[vader_array_offset(_a23_slotarr) + (size_t) l11];
                    l19 = t0.payload.s;
                    t4 = __lambda_vader_emit_bytecode_0(l21, l19);
                    if (t4) {
                        l26 = true;
                        goto end_434;
                    }
                    l11 = (l11 + INT64_C(1));
                }
                l26 = false;
            } end_434: ;
            if (l26) {
                l27 = vader_midir_select$type_intern_key(((vader_struct_vader_lower_ir$LoweredVtableEntry_t*) l12)->f_struct_type);
                l20 = std_collections$Map$std_core$Index$at__string__i32(((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l3)->f_type_key, l27);
                if (l20.tag == 580u) {
                    l24 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l3)->f_pinned_types;
                    l18 = ((int32_t) l20.payload.i);
                    vader_array_push_i32((vader_array_t*) l24, l18);
                }
                l23 = vader_emit_bytecode$resolve_fn_index(((vader_struct_vader_lower_ir$LoweredVtableEntry_t*) l12)->f_fn_symbol, l3);
                if (!(l23.tag == 0u)) {
                    l22 = ((int32_t) l23.payload.i);
                    vader_array_push_i32((vader_array_t*) l6, l22);
                }
                l8 = (l8 + INT64_C(1));
                continue;
            }
            l8 = (l8 + INT64_C(1));
        }
        l4 = ((vader_struct_vader_emit_bytecode$EmitOptions_t*) l2)->f_keep_mangles;
        vader_emit_bytecode$prune_unused_functions(l3, l6, l4);
        vader_emit_bytecode$prune_unused_imports(l3);
        l5 = vader_emit_bytecode$prune_unused_data(l3, l5);
        vader_emit_bytecode$prune_unused_globals(l3);
        l5 = vader_emit_bytecode$prune_unused_types(l3, l5);
        ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l3)->f_types_frozen = true;
    }
    l4 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l3)->f_imports;
    l7 = vader_array_length(((vader_array_t*) l4));
    l8 = INT64_C(0);
    while ((l8 < l7)) {
        vader_array_t* _a24_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a24_slotarr)
        t2 = vader_array_ref_load_obj(_a24_slotarr->buf, vader_array_offset(_a24_slotarr) + (size_t) l8);
        vader_midir_select$assert_import_wired(t2);
        l8 = (l8 + INT64_C(1));
    }
    l4 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l3)->f_types;
    l6 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l3)->f_strings;
    l9 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l3)->f_functions;
    l12 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l3)->f_imports;
    l15 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l3)->f_exports;
    l21 = ((vader_struct_vader_midir$CFGProject_t*) l0)->f_vtable_entries;
    l24 = ((vader_struct_vader_midir$CFGProject_t*) l0)->f_trait_membership;
    l21 = vader_emit_bytecode$build_impl_table_from_vtable(l21, l24, l3);
    l24 = vader_emit_bytecode$build_vtables_from_entries(((vader_struct_vader_midir$CFGProject_t*) l0)->f_vtable_entries, l3);
    l3 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l3)->f_globals;
    vader_struct_vader_core_bytecode$BytecodeModule_t* _a25_obj = (vader_struct_vader_core_bytecode$BytecodeModule_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BytecodeModule_t));
    vader_obj_header_init(_a25_obj, 1211u);
    _a25_obj->f_name = l1;
    _a25_obj->f_types = l4;
    _a25_obj->f_strings = l6;
    _a25_obj->f_data_pool = l5;
    _a25_obj->f_functions = l9;
    _a25_obj->f_imports = l12;
    _a25_obj->f_exports = l15;
    _a25_obj->f_impl_table = l21;
    _a25_obj->f_vtables = l24;
    _a25_obj->f_globals = l3;
    t2 = (void*) _a25_obj;
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_emit_bytecode$emit_call_results(void* l0, int64_t l1, void* l2, void* l3) {
    vader_box_t l4 = vader_box_null();
    int64_t l5, l6, l7;
    int32_t l8;
    int64_t t0, t2;
    int32_t t1;
    vader_box_t* gc_roots[1] = { &l4 };
    void** gc_raw_roots[3] = { &l0, &l2, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_array_length(((vader_array_t*) l2));
    if ((t0 <= INT64_C(1))) {
        t0 = vader_array_length(((vader_array_t*) l2));
        if (t0 == INT64_C(0)) {
            l4 = vader_box_obj(0u, NULL);
            vader_emit_bytecode$emit_result_if_any(l0, l1, l4, l3);
            { vader_gc_top = gc_frame.prev; return; }
        }
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
        t1 = ((int32_t*) _a0_slotarr->buf->slots)[vader_array_offset(_a0_slotarr) + (size_t) INT32_C(0)];
        l4 = vader_box_i32(580u, t1);
        vader_emit_bytecode$emit_result_if_any(l0, l1, l4, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    l5 = INT64_C(0);
    l6 = vader_array_length(((vader_array_t*) l2));
    while ((l5 < l6)) {
        t0 = vader_array_length(((vader_array_t*) l2));
        t2 = vader_chk_sub(i64, t0, INT64_C(1));
        l7 = vader_chk_sub(i64, t2, l5);
        vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l7)
        l8 = ((int32_t*) _a1_slotarr->buf->slots)[vader_array_offset(_a1_slotarr) + (size_t) l7];
        vader_emit_bytecode$emit_set(l0, l8, l3);
        l5 = (l5 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_bytecode$emit_cfg_function_body(void* l0, int32_t l1, void* l2, void* l3, bool l4) {
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
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l2)->f_functions);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    l5 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l1);
    vader_array_t* _a1_arr = vader_array_new(27u, 0u, 7u, 580u);
    l6 = (void*) _a1_arr;
    std_collections$Map$std_core$IndexSet$set_at__i32__Any(((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l2)->f_pinned_types_by_fn, l1, vader_ref_box(l6));
    vader_array_t* _a2_arr = vader_array_new(27u, 0u, 7u, 580u);
    l7 = (void*) _a2_arr;
    l8 = vader_array_length(((vader_array_t*) ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_params));
    l9 = INT64_C(0);
    l10 = vader_array_length(((vader_array_t*) ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_locals));
    while ((l9 < l10)) {
        if ((l9 < l8)) {
            l11 = ((int32_t) (int64_t) l9);
            vader_array_push_i32((vader_array_t*) l7, l11);
        } else {
            l12 = ((int32_t) (int64_t) l8);
            t0 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l5)->f_locals));
            l13 = ((int32_t) (int64_t) t0);
            l14 = vader_chk_add(i32, l12, l13);
            l15 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l5)->f_locals;
            vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_locals);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l9)
            t1 = vader_array_ref_load_obj(_a3_slotarr->buf, vader_array_offset(_a3_slotarr) + (size_t) l9);
            l16 = ((vader_struct_vader_midir$CFGLocal_t*) t1)->f_name;
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l9)
            t1 = vader_array_ref_load_obj(_a3_slotarr->buf, vader_array_offset(_a3_slotarr) + (size_t) l9);
            l17 = vader_midir_select$val_type_of_type(((vader_struct_vader_midir$CFGLocal_t*) t1)->f_type);
            vader_struct_vader_core_bytecode$BcLocal_t* _a4_obj = (vader_struct_vader_core_bytecode$BcLocal_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcLocal_t));
            vader_obj_header_init(_a4_obj, 1185u);
            _a4_obj->f_name = l16;
            _a4_obj->f_val = l17;
            l18 = (void*) _a4_obj;
            vader_array_push_ref((vader_array_t*) l15, l18);
            vader_array_push_i32((vader_array_t*) l7, l14);
        }
        l9 = (l9 + INT64_C(1));
    }
    l15 = vader_emit_bytecode$skip_forwarding_blocks(l0);
    l18 = vader_emit_bytecode$schedule_stack(l15);
    vader_array_t* _a5_arr = vader_array_new(233u, 0u, 13u, 1388u);
    l19 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(230u, 0u, 13u, 1384u);
    l20 = (void*) _a6_arr;
    vader_struct_vader_emit_bytecode$FnEmitCfg_t* _a7_obj = (vader_struct_vader_emit_bytecode$FnEmitCfg_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_bytecode$FnEmitCfg_t));
    vader_obj_header_init(_a7_obj, 1382u);
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
    vader_emit_bytecode$structure_function(t1);
    l5 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l2)->f_functions;
    vader_array_t* _a8_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l2)->f_functions);
    VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l1)
    t1 = vader_array_ref_load_obj(_a8_slotarr->buf, vader_array_offset(_a8_slotarr) + (size_t) l1);
    l6 = vader_emit_bytecode$drop_unbranched_blocks(t1);
    vader_array_t* _a9_slotarr = ((vader_array_t*) l5);
    VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l1)
    vader_array_ref_store(_a9_slotarr->buf, vader_array_offset(_a9_slotarr) + (size_t) l1, l6);
    VADER_WRITE_BARRIER(_a9_slotarr->buf);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_bytecode$emit_cond_branch(void* l0, void* l1, int32_t l2, void* l3, int32_t l4, int32_t l5) {
    int32_t l6, l9;
    void* l7 = NULL;
    void* l11 = NULL;
    bool l8, l10;
    bool t0, t1;
    void** gc_raw_roots[5] = { &l0, &l1, &l3, &l7, &l11 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = std_collections$Set$std_core$Contains$contains__i32(((vader_struct_vader_emit_bytecode$ScheduleHints_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_hints)->f_skip_terminator_get, l2);
    if (!(t0)) {
        l6 = ((vader_struct_vader_midir$TermCondBranch_t*) l3)->f_cond;
        l7 = ((vader_struct_vader_midir$TermCondBranch_t*) l3)->f_span;
        vader_emit_bytecode$emit_get(l0, l6, l7);
    }
    t0 = vader_midir$BlockId$std_core$Equals$equals(((vader_struct_vader_midir$TermCondBranch_t*) l3)->f_else_block, l4);
    if (!(t0)) {
        t0 = vader_midir$BlockId$std_core$Equals$equals(((vader_struct_vader_midir$TermCondBranch_t*) l3)->f_else_block, l5);
        l8 = !(t0);
    } else {
        l8 = false;
    }
    l7 = ((vader_struct_vader_emit_bytecode$StructureShape_t*) l1)->f_rpo_index;
    l6 = ((vader_struct_vader_midir$TermCondBranch_t*) l3)->f_then_block;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l7);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l6)
    l6 = ((int32_t*) _a0_slotarr->buf->slots)[vader_array_offset(_a0_slotarr) + (size_t) l6];
    l7 = ((vader_struct_vader_emit_bytecode$StructureShape_t*) l1)->f_rpo_index;
    l9 = l2;
    vader_array_t* _a1_slotarr = ((vader_array_t*) l7);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l9)
    l9 = ((int32_t*) _a1_slotarr->buf->slots)[vader_array_offset(_a1_slotarr) + (size_t) l9];
    l10 = (l6 > l9);
    t0 = vader_midir$BlockId$std_core$Equals$equals(((vader_struct_vader_midir$TermCondBranch_t*) l3)->f_then_block, l4);
    if (!(t0)) {
        t0 = vader_midir$BlockId$std_core$Equals$equals(((vader_struct_vader_midir$TermCondBranch_t*) l3)->f_then_block, l5);
        if (!(t0)) {
            l7 = ((vader_struct_vader_emit_bytecode$StructureShape_t*) l1)->f_merge;
            l6 = ((vader_struct_vader_midir$TermCondBranch_t*) l3)->f_then_block;
            vader_array_t* _a2_slotarr = ((vader_array_t*) l7);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l6)
            t0 = ((uint8_t*) _a2_slotarr->buf->slots)[vader_array_offset(_a2_slotarr) + (size_t) l6];
            t1 = t0;
            if (t1) {
                if (l10) {
                    l7 = ((vader_struct_vader_midir$TermCondBranch_t*) l3)->f_span;
                    l6 = ((vader_struct_vader_midir$TermCondBranch_t*) l3)->f_then_block;
                    vader_emit_bytecode$cf_br_if(l0, l7, l6);
                    t0 = vader_midir$BlockId$std_core$Equals$equals(((vader_struct_vader_midir$TermCondBranch_t*) l3)->f_else_block, l5);
                    if (t0) {
                        { vader_gc_top = gc_frame.prev; return; }
                    }
                    l6 = ((vader_struct_vader_midir$TermCondBranch_t*) l3)->f_else_block;
                    l7 = ((vader_struct_vader_midir$TermCondBranch_t*) l3)->f_span;
                    vader_emit_bytecode$emit_branch(l0, l1, l2, l6, l4, l7);
                    { vader_gc_top = gc_frame.prev; return; }
                }
            }
        }
    }
    if (l8) {
        l6 = ((vader_struct_vader_midir$TermCondBranch_t*) l3)->f_else_block;
        t0 = vader_emit_bytecode$leaves_at_once(l0, l1, l2, l6);
        if (t0) {
            l7 = ((vader_struct_vader_midir$TermCondBranch_t*) l3)->f_span;
            vader_emit_bytecode$cf_if(l0, l7);
            l7 = ((vader_struct_vader_midir$TermCondBranch_t*) l3)->f_span;
            vader_emit_bytecode$cf_else(l0, l7);
            l6 = ((vader_struct_vader_midir$TermCondBranch_t*) l3)->f_else_block;
            l7 = ((vader_struct_vader_midir$TermCondBranch_t*) l3)->f_span;
            vader_emit_bytecode$emit_branch(l0, l1, l2, l6, l4, l7);
            l7 = ((vader_struct_vader_midir$TermCondBranch_t*) l3)->f_span;
            vader_emit_bytecode$cf_end(l0, l7);
            t0 = vader_midir$BlockId$std_core$Equals$equals(((vader_struct_vader_midir$TermCondBranch_t*) l3)->f_then_block, l5);
            if (t0) {
                { vader_gc_top = gc_frame.prev; return; }
            }
            l6 = ((vader_struct_vader_midir$TermCondBranch_t*) l3)->f_then_block;
            l7 = ((vader_struct_vader_midir$TermCondBranch_t*) l3)->f_span;
            vader_emit_bytecode$emit_branch(l0, l1, l2, l6, l4, l7);
            { vader_gc_top = gc_frame.prev; return; }
        }
    }
    l7 = ((vader_struct_vader_midir$TermCondBranch_t*) l3)->f_span;
    vader_emit_bytecode$cf_if(l0, l7);
    t0 = vader_midir$BlockId$std_core$Equals$equals(((vader_struct_vader_midir$TermCondBranch_t*) l3)->f_then_block, l5);
    if (!(t0)) {
        l6 = ((vader_struct_vader_midir$TermCondBranch_t*) l3)->f_then_block;
        l7 = ((vader_struct_vader_midir$TermCondBranch_t*) l3)->f_span;
        vader_emit_bytecode$emit_branch(l0, l1, l2, l6, l4, l7);
    }
    t0 = vader_midir$BlockId$std_core$Equals$equals(((vader_struct_vader_midir$TermCondBranch_t*) l3)->f_else_block, l4);
    if (t0) {
        l8 = true;
    } else {
        l8 = vader_midir$BlockId$std_core$Equals$equals(((vader_struct_vader_midir$TermCondBranch_t*) l3)->f_else_block, l5);
    }
    if (l8) {
        l7 = ((vader_struct_vader_midir$TermCondBranch_t*) l3)->f_span;
        vader_emit_bytecode$cf_end(l0, l7);
        { vader_gc_top = gc_frame.prev; return; }
    }
    t0 = vader_emit_bytecode$last_op_exits(l0);
    if (!(t0)) {
        l11 = ((vader_struct_vader_midir$TermCondBranch_t*) l3)->f_span;
        vader_emit_bytecode$cf_else(l0, l11);
        l9 = ((vader_struct_vader_midir$TermCondBranch_t*) l3)->f_else_block;
        l11 = ((vader_struct_vader_midir$TermCondBranch_t*) l3)->f_span;
        vader_emit_bytecode$emit_branch(l0, l1, l2, l9, l4, l11);
        l11 = ((vader_struct_vader_midir$TermCondBranch_t*) l3)->f_span;
        vader_emit_bytecode$cf_end(l0, l11);
        { vader_gc_top = gc_frame.prev; return; }
    }
    l7 = ((vader_struct_vader_midir$TermCondBranch_t*) l3)->f_span;
    vader_emit_bytecode$cf_end(l0, l7);
    l6 = ((vader_struct_vader_midir$TermCondBranch_t*) l3)->f_else_block;
    l7 = ((vader_struct_vader_midir$TermCondBranch_t*) l3)->f_span;
    vader_emit_bytecode$emit_branch(l0, l1, l2, l6, l4, l7);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_bytecode$emit_const_instr(void* l0, void* l1, int64_t l2) {
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
    l3 = ((vader_struct_vader_midir$InstrConst_t*) l1)->f_value;
    if (l3.tag == 1827u) {
        t0 = vader_midir_select$val_type_of_type(((vader_struct_vader_midir$InstrConst_t*) l1)->f_type);
        t1 = vader_core_bytecode$is_64_bit_int_val(t0);
        if (t1) {
            t2 = l3.payload.obj;
            t3 = ((vader_struct_vader_midir$ConstInt_t*) t2)->f_value;
            vader_struct_vader_core_bytecode$I64Const_t* _a0_obj = (vader_struct_vader_core_bytecode$I64Const_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$I64Const_t));
            vader_obj_header_init(_a0_obj, 1270u);
            _a0_obj->f_value = t3;
            l4 = (void*) _a0_obj;
            l5 = ((vader_struct_vader_midir$InstrConst_t*) l1)->f_span;
            vader_emit_bytecode$push_emit(l0, vader_ref_box(l4), l5);
        } else {
            t2 = l3.payload.obj;
            t3 = ((vader_struct_vader_midir$ConstInt_t*) t2)->f_value;
            vader_struct_vader_core_bytecode$I32Const_t* _a1_obj = (vader_struct_vader_core_bytecode$I32Const_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$I32Const_t));
            vader_obj_header_init(_a1_obj, 1250u);
            _a1_obj->f_value = ((int32_t) (int64_t) t3);
            l4 = (void*) _a1_obj;
            l5 = ((vader_struct_vader_midir$InstrConst_t*) l1)->f_span;
            vader_emit_bytecode$push_emit(l0, vader_ref_box(l4), l5);
        }
    } else if (l3.tag == 1826u) {
        t2 = l3.payload.obj;
        t4 = ((vader_struct_vader_midir$ConstFloat_t*) t2)->f_value;
        vader_struct_vader_core_bytecode$F64Const_t* _a2_obj = (vader_struct_vader_core_bytecode$F64Const_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$F64Const_t));
        vader_obj_header_init(_a2_obj, 1229u);
        _a2_obj->f_value = t4;
        l4 = (void*) _a2_obj;
        l5 = ((vader_struct_vader_midir$InstrConst_t*) l1)->f_span;
        vader_emit_bytecode$push_emit(l0, vader_ref_box(l4), l5);
    } else if (l3.tag == 1824u) {
        t2 = l3.payload.obj;
        t1 = ((vader_struct_vader_midir$ConstBool_t*) t2)->f_value;
        vader_struct_vader_core_bytecode$BoolConst_t* _a3_obj = (vader_struct_vader_core_bytecode$BoolConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BoolConst_t));
        vader_obj_header_init(_a3_obj, 1201u);
        _a3_obj->f_value = t1;
        l4 = (void*) _a3_obj;
        l5 = ((vader_struct_vader_midir$InstrConst_t*) l1)->f_span;
        vader_emit_bytecode$push_emit(l0, vader_ref_box(l4), l5);
    } else if (l3.tag == 1825u) {
        t2 = l3.payload.obj;
        t5 = ((vader_struct_vader_midir$ConstChar_t*) t2)->f_value;
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
        vader_struct_vader_core_bytecode$CharConst_t* _a4_obj = (vader_struct_vader_core_bytecode$CharConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$CharConst_t));
        vader_obj_header_init(_a4_obj, 1216u);
        _a4_obj->f_value = ((uint32_t) (uint32_t) l6);
        l4 = (void*) _a4_obj;
        l5 = ((vader_struct_vader_midir$InstrConst_t*) l1)->f_span;
        vader_emit_bytecode$push_emit(l0, vader_ref_box(l4), l5);
    } else if (l3.tag == 1828u) {
        t2 = (void*) &vader_data_93;
        vader_array_t* _a5_slotarr = ((vader_array_t*) t2);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        l4 = vader_array_ref_load_obj(_a5_slotarr->buf, vader_array_offset(_a5_slotarr) + (size_t) INT64_C(0));
        l5 = ((vader_struct_vader_midir$InstrConst_t*) l1)->f_span;
        vader_emit_bytecode$push_emit(l0, vader_ref_box(l4), l5);
    } else if (l3.tag == 1829u) {
        l4 = ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_string_index_map;
        t2 = l3.payload.obj;
        l8 = ((vader_struct_vader_midir$ConstString_t*) t2)->f_index;
        vader_array_t* _a6_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l8)
        t5 = ((int32_t*) _a6_slotarr->buf->slots)[vader_array_offset(_a6_slotarr) + (size_t) l8];
        vader_struct_vader_core_bytecode$StringConst_t* _a7_obj = (vader_struct_vader_core_bytecode$StringConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$StringConst_t));
        vader_obj_header_init(_a7_obj, 1318u);
        _a7_obj->f_index = t5;
        l4 = (void*) _a7_obj;
        l5 = ((vader_struct_vader_midir$InstrConst_t*) l1)->f_span;
        vader_emit_bytecode$push_emit(l0, vader_ref_box(l4), l5);
    }
    l8 = ((vader_struct_vader_midir$InstrConst_t*) l1)->f_dst;
    l4 = ((vader_struct_vader_midir$InstrConst_t*) l1)->f_span;
    vader_emit_bytecode$emit_result(l0, l2, l8, l4);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_bytecode$emit_first_get(void* l0, int64_t l1, int32_t l2, void* l3) {
    bool t0;
    void** gc_raw_roots[2] = { &l0, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = std_collections$Set$std_core$Contains$contains__i64(((vader_struct_vader_emit_bytecode$ScheduleHints_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_hints)->f_skip_first_get, l1);
    if (!(t0)) {
        vader_emit_bytecode$emit_get(l0, l2, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_bytecode$emit_get(void* l0, int32_t l1, void* l2) {
    void* l3 = NULL;
    int64_t l4;
    int32_t t0;
    void** gc_raw_roots[3] = { &l0, &l2, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_local_to_slot;
    l4 = ((int64_t) (int32_t) l1);
    vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
    t0 = ((int32_t*) _a0_slotarr->buf->slots)[vader_array_offset(_a0_slotarr) + (size_t) l4];
    vader_struct_vader_core_bytecode$LocalGet_t* _a1_obj = (vader_struct_vader_core_bytecode$LocalGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$LocalGet_t));
    vader_obj_header_init(_a1_obj, 1295u);
    _a1_obj->f_slot = t0;
    l3 = (void*) _a1_obj;
    vader_emit_bytecode$push_emit(l0, vader_ref_box(l3), l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_bytecode$emit_instr(void* l0, vader_box_t l1, int64_t l2) {
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
    uint8_t t6;
    vader_box_t* gc_roots[3] = { &l1, &l7, &l8 };
    void** gc_raw_roots[6] = { &l0, &l3, &l12, &l14, &l16, &t0 };
    vader_string_t* gc_atom_roots[5] = { &l18, &l19, &l20, &l21, &t4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 5u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l1.tag == 1847u) {
        l3 = l1.payload.obj;
        vader_emit_bytecode$emit_const_instr(l0, l3, l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 1859u) {
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_midir$InstrMove_t*) t0)->f_src;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir$InstrMove_t*) t0)->f_span;
        vader_emit_bytecode$emit_first_get(l0, l2, l4, l3);
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_midir$InstrMove_t*) t0)->f_src;
        l3 = ((vader_struct_vader_midir$CFGFunction_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_fn_)->f_locals;
        t0 = l1.payload.obj;
        l5 = ((int64_t) (int32_t) ((vader_struct_vader_midir$InstrMove_t*) t0)->f_dst);
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l5);
        l6 = vader_midir_select$is_boxed_slot(((vader_struct_vader_midir$CFGLocal_t*) t0)->f_type);
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir$InstrMove_t*) t0)->f_span;
        vader_emit_bytecode$emit_retag_into(l0, l4, l6, l3);
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_midir$InstrMove_t*) t0)->f_dst;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir$InstrMove_t*) t0)->f_span;
        vader_emit_bytecode$emit_result(l0, l2, l4, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 1840u) {
        l3 = ((vader_struct_vader_midir$CFGFunction_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_fn_)->f_locals;
        t0 = l1.payload.obj;
        l5 = ((int64_t) (int32_t) ((vader_struct_vader_midir$InstrBinOp_t*) t0)->f_lhs);
        vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
        t0 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l5);
        l7 = ((vader_struct_vader_midir$CFGLocal_t*) t0)->f_type;
        l3 = ((vader_struct_vader_midir$CFGFunction_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_fn_)->f_locals;
        t0 = l1.payload.obj;
        l5 = ((int64_t) (int32_t) ((vader_struct_vader_midir$InstrBinOp_t*) t0)->f_rhs);
        vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l5)
        t0 = vader_array_ref_load_obj(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l5);
        l8 = ((vader_struct_vader_midir$CFGLocal_t*) t0)->f_type;
        t0 = l1.payload.obj;
        l6 = vader_emit_bytecode$compares_boxes(((vader_struct_vader_midir$InstrBinOp_t*) t0)->f_op, l8);
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_midir$InstrBinOp_t*) t0)->f_lhs;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir$InstrBinOp_t*) t0)->f_span;
        vader_emit_bytecode$emit_first_get(l0, l2, l4, l3);
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_midir$InstrBinOp_t*) t0)->f_lhs;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir$InstrBinOp_t*) t0)->f_span;
        vader_emit_bytecode$emit_retag_into(l0, l4, l6, l3);
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_midir$InstrBinOp_t*) t0)->f_rhs;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir$InstrBinOp_t*) t0)->f_span;
        vader_emit_bytecode$emit_get(l0, l4, l3);
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_midir$InstrBinOp_t*) t0)->f_rhs;
        t0 = l1.payload.obj;
        l9 = vader_emit_bytecode$compares_boxes(((vader_struct_vader_midir$InstrBinOp_t*) t0)->f_op, l7);
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir$InstrBinOp_t*) t0)->f_span;
        vader_emit_bytecode$emit_retag_into(l0, l4, l9, l3);
        if (!(l6)) {
            l8 = l7;
        }
        t0 = l1.payload.obj;
        l10 = ((vader_struct_vader_midir$InstrBinOp_t*) t0)->f_op;
        l11 = vader_midir_select$val_type_of_type(l8);
        l7 = vader_midir_select$binary_op_for(l10, l11);
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir$InstrBinOp_t*) t0)->f_span;
        vader_emit_bytecode$push_emit(l0, l7, l3);
        t0 = l1.payload.obj;
        l10 = vader_midir_select$val_type_of_type(((vader_struct_vader_midir$InstrBinOp_t*) t0)->f_type);
        t0 = l1.payload.obj;
        t1 = vader_emit_bytecode$binary_leaves_width(((vader_struct_vader_midir$InstrBinOp_t*) t0)->f_op, l10);
        if (t1) {
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir$InstrBinOp_t*) t0)->f_span;
            vader_emit_bytecode$emit_narrowing(l0, l10, l3);
        }
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_midir$InstrBinOp_t*) t0)->f_dst;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir$InstrBinOp_t*) t0)->f_span;
        vader_emit_bytecode$emit_result(l0, l2, l4, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 1841u) {
        l3 = ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_pinned_types_bucket;
        t0 = l1.payload.obj;
        l12 = ((vader_struct_vader_midir$InstrCall_t*) t0)->f_args;
        l5 = vader_array_length(((vader_array_t*) l12));
        l13 = INT64_C(0);
        while ((l13 < l5)) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l12);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            l4 = ((int32_t*) _a3_slotarr->buf->slots)[vader_array_offset(_a3_slotarr) + (size_t) l13];
            l14 = ((vader_struct_vader_midir$CFGFunction_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_fn_)->f_locals;
            l15 = ((int64_t) (int32_t) l4);
            vader_array_t* _a4_slotarr = ((vader_array_t*) l14);
            VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l15)
            t0 = vader_array_ref_load_obj(_a4_slotarr->buf, vader_array_offset(_a4_slotarr) + (size_t) l15);
            l7 = ((vader_struct_vader_midir$CFGLocal_t*) t0)->f_type;
            l16 = ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_project;
            l17 = vader_emit_bytecode$intern_type(l7, l16);
            vader_array_push_i32((vader_array_t*) l3, l17);
            l13 = (l13 + INT64_C(1));
        }
        t0 = l1.payload.obj;
        l12 = ((vader_struct_vader_midir$InstrCall_t*) t0)->f_dsts;
        l5 = vader_array_length(((vader_array_t*) l12));
        l13 = INT64_C(0);
        while ((l13 < l5)) {
            vader_array_t* _a5_slotarr = ((vader_array_t*) l12);
            VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
            l4 = ((int32_t*) _a5_slotarr->buf->slots)[vader_array_offset(_a5_slotarr) + (size_t) l13];
            l14 = ((vader_struct_vader_midir$CFGFunction_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_fn_)->f_locals;
            l15 = ((int64_t) (int32_t) l4);
            vader_array_t* _a6_slotarr = ((vader_array_t*) l14);
            VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l15)
            t0 = vader_array_ref_load_obj(_a6_slotarr->buf, vader_array_offset(_a6_slotarr) + (size_t) l15);
            l7 = ((vader_struct_vader_midir$CFGLocal_t*) t0)->f_type;
            l16 = ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_project;
            l17 = vader_emit_bytecode$intern_type(l7, l16);
            vader_array_push_i32((vader_array_t*) l3, l17);
            l13 = (l13 + INT64_C(1));
        }
        l3 = l1.payload.obj;
        l3 = vader_emit_bytecode$resolve_direct_call(l0, l3);
        l12 = ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_project;
        l14 = ((vader_struct_vader_emit_bytecode$DirectCallTarget_t*) l3)->f_signature;
        l12 = vader_emit_bytecode$boxed_params_of(l12, l14);
        t0 = l1.payload.obj;
        l14 = ((vader_struct_vader_midir$InstrCall_t*) t0)->f_args;
        t0 = l1.payload.obj;
        l16 = ((vader_struct_vader_midir$InstrCall_t*) t0)->f_span;
        vader_emit_bytecode$emit_operands_into(l0, l2, l14, l12, l16);
        l7 = ((vader_struct_vader_emit_bytecode$DirectCallTarget_t*) l3)->f_op;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir$InstrCall_t*) t0)->f_span;
        vader_emit_bytecode$push_emit(l0, l7, l3);
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir$InstrCall_t*) t0)->f_dsts;
        t0 = l1.payload.obj;
        l12 = ((vader_struct_vader_midir$InstrCall_t*) t0)->f_span;
        vader_emit_bytecode$emit_call_results(l0, l2, l3, l12);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 1863u) {
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_midir$InstrUnOp_t*) t0)->f_operand;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir$InstrUnOp_t*) t0)->f_span;
        vader_emit_bytecode$emit_first_get(l0, l2, l4, l3);
        l3 = ((vader_struct_vader_midir$CFGFunction_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_fn_)->f_locals;
        t0 = l1.payload.obj;
        l5 = ((int64_t) (int32_t) ((vader_struct_vader_midir$InstrUnOp_t*) t0)->f_operand);
        vader_array_t* _a7_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l5)
        t0 = vader_array_ref_load_obj(_a7_slotarr->buf, vader_array_offset(_a7_slotarr) + (size_t) l5);
        l10 = vader_midir_select$val_type_of_type(((vader_struct_vader_midir$CFGLocal_t*) t0)->f_type);
        t0 = l1.payload.obj;
        l7 = vader_midir_select$unary_op_for(((vader_struct_vader_midir$InstrUnOp_t*) t0)->f_op, l10);
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir$InstrUnOp_t*) t0)->f_span;
        vader_emit_bytecode$push_emit(l0, l7, l3);
        t0 = l1.payload.obj;
        t1 = vader_emit_bytecode$unary_leaves_width(((vader_struct_vader_midir$InstrUnOp_t*) t0)->f_op, l10);
        if (t1) {
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir$InstrUnOp_t*) t0)->f_span;
            vader_emit_bytecode$emit_narrowing(l0, l10, l3);
        }
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_midir$InstrUnOp_t*) t0)->f_dst;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir$InstrUnOp_t*) t0)->f_span;
        vader_emit_bytecode$emit_result(l0, l2, l4, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 1842u) {
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir$InstrCallIndirect_t*) t0)->f_args;
        t0 = l1.payload.obj;
        l12 = vader_emit_bytecode$every_operand_boxed(((vader_struct_vader_midir$InstrCallIndirect_t*) t0)->f_args);
        t0 = l1.payload.obj;
        l14 = ((vader_struct_vader_midir$InstrCallIndirect_t*) t0)->f_span;
        vader_emit_bytecode$emit_operands_into(l0, l2, l3, l12, l14);
        t0 = l1.payload.obj;
        t2 = vader_array_length(((vader_array_t*) ((vader_struct_vader_midir$InstrCallIndirect_t*) t0)->f_args));
        if (t2 == INT64_C(0)) {
            t0 = l1.payload.obj;
            l4 = ((vader_struct_vader_midir$InstrCallIndirect_t*) t0)->f_callee;
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir$InstrCallIndirect_t*) t0)->f_span;
            vader_emit_bytecode$emit_first_get(l0, l2, l4, l3);
        } else {
            t0 = l1.payload.obj;
            l4 = ((vader_struct_vader_midir$InstrCallIndirect_t*) t0)->f_callee;
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir$InstrCallIndirect_t*) t0)->f_span;
            vader_emit_bytecode$emit_get(l0, l4, l3);
        }
        t0 = l1.payload.obj;
        l7 = ((vader_struct_vader_midir$InstrCallIndirect_t*) t0)->f_fn_type;
        l3 = ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_project;
        t3 = vader_emit_bytecode$intern_type(l7, l3);
        vader_struct_vader_core_bytecode$CallIndirect_t* _a8_obj = (vader_struct_vader_core_bytecode$CallIndirect_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$CallIndirect_t));
        vader_obj_header_init(_a8_obj, 1215u);
        _a8_obj->f_type_id = t3;
        l3 = (void*) _a8_obj;
        t0 = l1.payload.obj;
        l12 = ((vader_struct_vader_midir$InstrCallIndirect_t*) t0)->f_span;
        vader_emit_bytecode$push_emit(l0, vader_ref_box(l3), l12);
        t0 = l1.payload.obj;
        l7 = ((vader_struct_vader_midir$InstrCallIndirect_t*) t0)->f_dst;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir$InstrCallIndirect_t*) t0)->f_span;
        vader_emit_bytecode$emit_result_if_any(l0, l2, l7, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 1854u) {
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir$InstrFnRef_t*) t0)->f_fn_symbol;
        l12 = ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_project;
        l7 = vader_emit_bytecode$resolve_fn_index(l3, l12);
        if (!(l7.tag == 580u)) {
            t0 = l1.payload.obj;
            l18 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_midir$InstrFnRef_t*) t0)->f_fn_symbol)->f_name;
            l5 = vader_host_std_core$Intrinsic$byte_len(l18);
            l14 = (void*) vader_buffer_new((size_t) (INT64_C(98) + l5));
            l5 = INT64_C(0);
            l5 = std_core$write_string_at(l14, l5, 2293u);
            l5 = std_core$write_string_at(l14, l5, l18);
            l5 = std_core$write_string_at(l14, l5, 343u);
            t0 = l1.payload.obj;
            t3 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_midir$InstrFnRef_t*) t0)->f_fn_symbol)->f_id;
            l13 = ((int64_t) (int32_t) t3);
            l5 = std_core$write_int(l14, l5, l13);
            l5 = std_core$write_string_at(l14, l5, 383u);
            t4 = std_core$finish_buffer(l14, l5);
            vader_host_std_core$Intrinsic$panic(t4);
            vader_unreachable("a no-return call returned");
        }
        t0 = l1.payload.obj;
        l8 = ((vader_struct_vader_midir$InstrFnRef_t*) t0)->f_type;
        l3 = ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_project;
        l4 = vader_emit_bytecode$intern_type(l8, l3);
        t3 = ((int32_t) l7.payload.i);
        vader_struct_vader_core_bytecode$FnRef_t* _a9_obj = (vader_struct_vader_core_bytecode$FnRef_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$FnRef_t));
        vader_obj_header_init(_a9_obj, 1242u);
        _a9_obj->f_function_index = t3;
        _a9_obj->f_type_id = l4;
        l3 = (void*) _a9_obj;
        t0 = l1.payload.obj;
        l12 = ((vader_struct_vader_midir$InstrFnRef_t*) t0)->f_span;
        vader_emit_bytecode$push_emit(l0, vader_ref_box(l3), l12);
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_midir$InstrFnRef_t*) t0)->f_dst;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir$InstrFnRef_t*) t0)->f_span;
        vader_emit_bytecode$emit_result(l0, l2, l4, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 1853u) {
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir$InstrFnAddr_t*) t0)->f_fn_symbol;
        l12 = ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_project;
        l7 = vader_emit_bytecode$resolve_fn_index(l3, l12);
        if (!(l7.tag == 580u)) {
            t0 = l1.payload.obj;
            l18 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_midir$InstrFnAddr_t*) t0)->f_fn_symbol)->f_name;
            l5 = vader_host_std_core$Intrinsic$byte_len(l18);
            l14 = (void*) vader_buffer_new((size_t) (INT64_C(111) + l5));
            l5 = INT64_C(0);
            l5 = std_core$write_string_at(l14, l5, 2292u);
            l5 = std_core$write_string_at(l14, l5, l18);
            l5 = std_core$write_string_at(l14, l5, 343u);
            t0 = l1.payload.obj;
            t3 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_midir$InstrFnAddr_t*) t0)->f_fn_symbol)->f_id;
            l13 = ((int64_t) (int32_t) t3);
            l5 = std_core$write_int(l14, l5, l13);
            l5 = std_core$write_string_at(l14, l5, 406u);
            t4 = std_core$finish_buffer(l14, l5);
            vader_host_std_core$Intrinsic$panic(t4);
            vader_unreachable("a no-return call returned");
        }
        t3 = ((int32_t) l7.payload.i);
        vader_struct_vader_core_bytecode$FnAddr_t* _a10_obj = (vader_struct_vader_core_bytecode$FnAddr_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$FnAddr_t));
        vader_obj_header_init(_a10_obj, 1241u);
        _a10_obj->f_function_index = t3;
        l3 = (void*) _a10_obj;
        t0 = l1.payload.obj;
        l12 = ((vader_struct_vader_midir$InstrFnAddr_t*) t0)->f_span;
        vader_emit_bytecode$push_emit(l0, vader_ref_box(l3), l12);
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_midir$InstrFnAddr_t*) t0)->f_dst;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir$InstrFnAddr_t*) t0)->f_span;
        vader_emit_bytecode$emit_result(l0, l2, l4, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 1866u) {
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir$InstrVirtualCall_t*) t0)->f_args;
        t0 = l1.payload.obj;
        l12 = vader_emit_bytecode$every_operand_boxed(((vader_struct_vader_midir$InstrVirtualCall_t*) t0)->f_args);
        t0 = l1.payload.obj;
        l14 = ((vader_struct_vader_midir$InstrVirtualCall_t*) t0)->f_span;
        vader_emit_bytecode$emit_operands_into(l0, l2, l3, l12, l14);
        t0 = l1.payload.obj;
        t2 = vader_array_length(((vader_array_t*) ((vader_struct_vader_midir$InstrVirtualCall_t*) t0)->f_args));
        if (t2 == INT64_C(0)) {
            t0 = l1.payload.obj;
            l4 = ((vader_struct_vader_midir$InstrVirtualCall_t*) t0)->f_receiver;
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir$InstrVirtualCall_t*) t0)->f_span;
            vader_emit_bytecode$emit_first_get(l0, l2, l4, l3);
        } else {
            t0 = l1.payload.obj;
            l4 = ((vader_struct_vader_midir$InstrVirtualCall_t*) t0)->f_receiver;
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir$InstrVirtualCall_t*) t0)->f_span;
            vader_emit_bytecode$emit_get(l0, l4, l3);
        }
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_midir$InstrVirtualCall_t*) t0)->f_receiver;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir$InstrVirtualCall_t*) t0)->f_span;
        vader_emit_bytecode$emit_retag_into(l0, l4, true, l3);
        t0 = l1.payload.obj;
        t2 = vader_array_length(((vader_array_t*) ((vader_struct_vader_midir$InstrVirtualCall_t*) t0)->f_args));
        t5 = vader_chk_add(i64, t2, INT64_C(1));
        l4 = ((int32_t) (int64_t) t5);
        t0 = l1.payload.obj;
        l18 = ((vader_struct_vader_midir$InstrVirtualCall_t*) t0)->f_trait_name;
        t0 = l1.payload.obj;
        l19 = ((vader_struct_vader_midir$InstrVirtualCall_t*) t0)->f_method;
        l18 = vader_core_mangle$vtable_key(l18, l19);
        t0 = l1.payload.obj;
        t6 = vader_midir_select$val_type_of_type(((vader_struct_vader_midir$InstrVirtualCall_t*) t0)->f_type);
        vader_array_t* _a11_arr = vader_array_new(29u, 1u, 1u, 582u);
        ((uint8_t*) _a11_arr->buf->slots)[vader_array_offset(_a11_arr) + 0u] = (uint8_t) (int32_t) (uint8_t) t6;
        l3 = (void*) _a11_arr;
        vader_struct_vader_core_bytecode$VirtualCall_t* _a12_obj = (vader_struct_vader_core_bytecode$VirtualCall_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$VirtualCall_t));
        vader_obj_header_init(_a12_obj, 1341u);
        _a12_obj->f_parameter_count = l4;
        _a12_obj->f_vtable_key = l18;
        _a12_obj->f_results = l3;
        l3 = (void*) _a12_obj;
        t0 = l1.payload.obj;
        l12 = ((vader_struct_vader_midir$InstrVirtualCall_t*) t0)->f_span;
        vader_emit_bytecode$push_emit(l0, vader_ref_box(l3), l12);
        t0 = l1.payload.obj;
        l7 = ((vader_struct_vader_midir$InstrVirtualCall_t*) t0)->f_dst;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir$InstrVirtualCall_t*) t0)->f_span;
        vader_emit_bytecode$emit_result_if_any(l0, l2, l7, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 1851u) {
        l3 = ((vader_struct_vader_midir$CFGFunction_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_fn_)->f_locals;
        t0 = l1.payload.obj;
        l5 = ((int64_t) (int32_t) ((vader_struct_vader_midir$InstrFieldGet_t*) t0)->f_target);
        vader_array_t* _a13_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a13_slotarr, l5)
        l3 = vader_array_ref_load_obj(_a13_slotarr->buf, vader_array_offset(_a13_slotarr) + (size_t) l5);
        l7 = ((vader_struct_vader_midir$CFGLocal_t*) l3)->f_type;
        l12 = ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_project;
        l4 = vader_emit_bytecode$intern_type(l7, l12);
        l6 = std_collections$Set$std_core$Contains$contains__i64(((vader_struct_vader_emit_bytecode$ScheduleHints_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_hints)->f_skip_first_get, l2);
        t0 = l1.payload.obj;
        l17 = ((vader_struct_vader_midir$InstrFieldGet_t*) t0)->f_target;
        t0 = l1.payload.obj;
        l12 = ((vader_struct_vader_midir$InstrFieldGet_t*) t0)->f_span;
        vader_emit_bytecode$emit_first_get(l0, l2, l17, l12);
        l12 = ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_project;
        t0 = l1.payload.obj;
        l18 = ((vader_struct_vader_midir$InstrFieldGet_t*) t0)->f_field;
        l8 = vader_emit_bytecode$find_struct_field_index(l12, l4, l18);
        if (l8.tag == 0u) {
            t0 = l1.payload.obj;
            l18 = ((vader_struct_vader_midir$InstrFieldGet_t*) t0)->f_field;
            l19 = vader_core_types$display_type(l7);
            t0 = l1.payload.obj;
            l17 = ((vader_struct_vader_midir$InstrFieldGet_t*) t0)->f_target;
            l20 = ((vader_struct_vader_midir$CFGLocal_t*) l3)->f_name;
            l21 = ((vader_struct_vader_midir$CFGFunction_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_fn_)->f_mangled;
            l5 = vader_host_std_core$Intrinsic$byte_len(l18);
            l13 = vader_host_std_core$Intrinsic$byte_len(l19);
            l5 = (l5 + l13);
            l13 = vader_host_std_core$Intrinsic$byte_len(l20);
            l5 = (l5 + l13);
            l13 = vader_host_std_core$Intrinsic$byte_len(l21);
            l5 = (l5 + l13);
            l3 = (void*) vader_buffer_new((size_t) (INT64_C(75) + l5));
            l5 = INT64_C(0);
            l5 = std_core$write_string_at(l3, l5, 2286u);
            l5 = std_core$write_string_at(l3, l5, l18);
            l5 = std_core$write_string_at(l3, l5, 1501u);
            l5 = std_core$write_string_at(l3, l5, l19);
            l5 = std_core$write_string_at(l3, l5, 1274u);
            l13 = ((int64_t) (int32_t) l17);
            l5 = std_core$write_int(l3, l5, l13);
            l5 = std_core$write_string_at(l3, l5, 106u);
            l5 = std_core$write_string_at(l3, l5, l20);
            l5 = std_core$write_string_at(l3, l5, 1577u);
            l5 = std_core$write_string_at(l3, l5, l21);
            l5 = std_core$write_string_at(l3, l5, 341u);
            t4 = std_core$finish_buffer(l3, l5);
            vader_host_std_core$Intrinsic$panic(t4);
            vader_unreachable("a no-return call returned");
        } else {
            t2 = ((int64_t) l8.payload.i);
            l17 = ((int32_t) (int64_t) t2);
            l9 = false;
            if (!(l6)) {
                l9 = vader_emit_bytecode$try_fuse_local_field(l0, l4, l17);
            }
            if (!(l9)) {
                vader_struct_vader_core_bytecode$StructGet_t* _a14_obj = (vader_struct_vader_core_bytecode$StructGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$StructGet_t));
                vader_obj_header_init(_a14_obj, 1321u);
                _a14_obj->f_type_id = l4;
                _a14_obj->f_field_index = l17;
                l3 = (void*) _a14_obj;
                t0 = l1.payload.obj;
                l12 = ((vader_struct_vader_midir$InstrFieldGet_t*) t0)->f_span;
                vader_emit_bytecode$push_emit(l0, vader_ref_box(l3), l12);
            }
            t0 = l1.payload.obj;
            t1 = vader_emit_bytecode$needs_ref_cast(((vader_struct_vader_midir$InstrFieldGet_t*) t0)->f_type);
            if (t1) {
                t0 = l1.payload.obj;
                l7 = ((vader_struct_vader_midir$InstrFieldGet_t*) t0)->f_type;
                l3 = ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_project;
                t3 = vader_emit_bytecode$intern_type(l7, l3);
                vader_struct_vader_core_bytecode$RefCast_t* _a15_obj = (vader_struct_vader_core_bytecode$RefCast_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$RefCast_t));
                vader_obj_header_init(_a15_obj, 1303u);
                _a15_obj->f_type_id = t3;
                l3 = (void*) _a15_obj;
                t0 = l1.payload.obj;
                l12 = ((vader_struct_vader_midir$InstrFieldGet_t*) t0)->f_span;
                vader_emit_bytecode$push_emit(l0, vader_ref_box(l3), l12);
            }
            t0 = l1.payload.obj;
            l4 = ((vader_struct_vader_midir$InstrFieldGet_t*) t0)->f_dst;
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir$InstrFieldGet_t*) t0)->f_span;
            vader_emit_bytecode$emit_result(l0, l2, l4, l3);
            { vader_gc_top = gc_frame.prev; return; }
        }
    } else if (l1.tag == 1852u) {
        l3 = ((vader_struct_vader_midir$CFGFunction_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_fn_)->f_locals;
        t0 = l1.payload.obj;
        l5 = ((int64_t) (int32_t) ((vader_struct_vader_midir$InstrFieldSet_t*) t0)->f_target);
        vader_array_t* _a16_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a16_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a16_slotarr, l5)
        t0 = vader_array_ref_load_obj(_a16_slotarr->buf, vader_array_offset(_a16_slotarr) + (size_t) l5);
        l7 = ((vader_struct_vader_midir$CFGLocal_t*) t0)->f_type;
        l3 = ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_project;
        l4 = vader_emit_bytecode$intern_type(l7, l3);
        l3 = ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_project;
        t0 = l1.payload.obj;
        l18 = ((vader_struct_vader_midir$InstrFieldSet_t*) t0)->f_field;
        l8 = vader_emit_bytecode$find_struct_field_index(l3, l4, l18);
        if (l8.tag == 0u) {
            t0 = l1.payload.obj;
            l18 = ((vader_struct_vader_midir$InstrFieldSet_t*) t0)->f_field;
            l19 = vader_core_types$display_type(l7);
            l20 = ((vader_struct_vader_midir$CFGFunction_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_fn_)->f_mangled;
            t4 = concat_7(2286u, l18, 1501u, l19, 1384u, l20, 357u);
            vader_host_std_core$Intrinsic$panic(t4);
            vader_unreachable("a no-return call returned");
        } else {
            l5 = ((int64_t) l8.payload.i);
            t0 = l1.payload.obj;
            l17 = ((vader_struct_vader_midir$InstrFieldSet_t*) t0)->f_target;
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir$InstrFieldSet_t*) t0)->f_span;
            vader_emit_bytecode$emit_first_get(l0, l2, l17, l3);
            t0 = l1.payload.obj;
            l17 = ((vader_struct_vader_midir$InstrFieldSet_t*) t0)->f_value;
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir$InstrFieldSet_t*) t0)->f_span;
            vader_emit_bytecode$emit_get(l0, l17, l3);
            t0 = l1.payload.obj;
            l17 = ((vader_struct_vader_midir$InstrFieldSet_t*) t0)->f_value;
            l6 = vader_emit_bytecode$boxed_field(((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_project, l4, l5);
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir$InstrFieldSet_t*) t0)->f_span;
            vader_emit_bytecode$emit_retag_into(l0, l17, l6, l3);
            l17 = ((int32_t) (int64_t) l5);
            t0 = l1.payload.obj;
            l6 = ((vader_struct_vader_midir$InstrFieldSet_t*) t0)->f_barrierless;
            vader_struct_vader_core_bytecode$StructSet_t* _a17_obj = (vader_struct_vader_core_bytecode$StructSet_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$StructSet_t));
            vader_obj_header_init(_a17_obj, 1323u);
            _a17_obj->f_type_id = l4;
            _a17_obj->f_field_index = l17;
            _a17_obj->f_stack = l6;
            l3 = (void*) _a17_obj;
            t0 = l1.payload.obj;
            l12 = ((vader_struct_vader_midir$InstrFieldSet_t*) t0)->f_span;
            vader_emit_bytecode$push_emit(l0, vader_ref_box(l3), l12);
            { vader_gc_top = gc_frame.prev; return; }
        }
    } else if (l1.tag == 1864u) {
        l3 = ((vader_struct_vader_midir$CFGFunction_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_fn_)->f_locals;
        t0 = l1.payload.obj;
        l5 = ((int64_t) (int32_t) ((vader_struct_vader_midir$InstrUnionFieldGet_t*) t0)->f_target);
        vader_array_t* _a18_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a18_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a18_slotarr, l5)
        t0 = vader_array_ref_load_obj(_a18_slotarr->buf, vader_array_offset(_a18_slotarr) + (size_t) l5);
        l7 = ((vader_struct_vader_midir$CFGLocal_t*) t0)->f_type;
        l3 = ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_project;
        l4 = vader_emit_bytecode$intern_type(l7, l3);
        l8 = vader_core_bytecode$union_layout_struct(((vader_struct_vader_emit_bytecode$EmitterCtx_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_project)->f_types, l4);
        if (l8.tag == 0u) {
            t0 = l1.payload.obj;
            l18 = ((vader_struct_vader_midir$InstrUnionFieldGet_t*) t0)->f_field;
            t4 = vader_emit_bytecode$no_common_field(l0, l18, l7);
            vader_host_std_core$Intrinsic$panic(t4);
            vader_unreachable("a no-return call returned");
        } else {
            l17 = ((int32_t) l8.payload.i);
            l3 = ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_project;
            t0 = l1.payload.obj;
            l18 = ((vader_struct_vader_midir$InstrUnionFieldGet_t*) t0)->f_field;
            l8 = vader_emit_bytecode$find_struct_field_index(l3, l17, l18);
            if (l8.tag == 0u) {
                t0 = l1.payload.obj;
                l18 = ((vader_struct_vader_midir$InstrUnionFieldGet_t*) t0)->f_field;
                t4 = vader_emit_bytecode$no_common_field(l0, l18, l7);
                vader_host_std_core$Intrinsic$panic(t4);
                vader_unreachable("a no-return call returned");
            } else {
                l5 = ((int64_t) l8.payload.i);
                t0 = l1.payload.obj;
                l17 = ((vader_struct_vader_midir$InstrUnionFieldGet_t*) t0)->f_target;
                t0 = l1.payload.obj;
                l3 = ((vader_struct_vader_midir$InstrUnionFieldGet_t*) t0)->f_span;
                vader_emit_bytecode$emit_first_get(l0, l2, l17, l3);
                l17 = ((int32_t) (int64_t) l5);
                vader_struct_vader_core_bytecode$UnionFieldGet_t* _a19_obj = (vader_struct_vader_core_bytecode$UnionFieldGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$UnionFieldGet_t));
                vader_obj_header_init(_a19_obj, 1338u);
                _a19_obj->f_type_id = l4;
                _a19_obj->f_field_index = l17;
                l3 = (void*) _a19_obj;
                t0 = l1.payload.obj;
                l12 = ((vader_struct_vader_midir$InstrUnionFieldGet_t*) t0)->f_span;
                vader_emit_bytecode$push_emit(l0, vader_ref_box(l3), l12);
                t0 = l1.payload.obj;
                t1 = vader_emit_bytecode$needs_ref_cast(((vader_struct_vader_midir$InstrUnionFieldGet_t*) t0)->f_type);
                if (t1) {
                    t0 = l1.payload.obj;
                    l7 = ((vader_struct_vader_midir$InstrUnionFieldGet_t*) t0)->f_type;
                    l3 = ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_project;
                    t3 = vader_emit_bytecode$intern_type(l7, l3);
                    vader_struct_vader_core_bytecode$RefCast_t* _a20_obj = (vader_struct_vader_core_bytecode$RefCast_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$RefCast_t));
                    vader_obj_header_init(_a20_obj, 1303u);
                    _a20_obj->f_type_id = t3;
                    l3 = (void*) _a20_obj;
                    t0 = l1.payload.obj;
                    l12 = ((vader_struct_vader_midir$InstrUnionFieldGet_t*) t0)->f_span;
                    vader_emit_bytecode$push_emit(l0, vader_ref_box(l3), l12);
                }
                t0 = l1.payload.obj;
                l4 = ((vader_struct_vader_midir$InstrUnionFieldGet_t*) t0)->f_dst;
                t0 = l1.payload.obj;
                l3 = ((vader_struct_vader_midir$InstrUnionFieldGet_t*) t0)->f_span;
                vader_emit_bytecode$emit_result(l0, l2, l4, l3);
                { vader_gc_top = gc_frame.prev; return; }
            }
        }
    } else if (l1.tag == 1865u) {
        l3 = ((vader_struct_vader_midir$CFGFunction_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_fn_)->f_locals;
        t0 = l1.payload.obj;
        l5 = ((int64_t) (int32_t) ((vader_struct_vader_midir$InstrUnionFieldSet_t*) t0)->f_target);
        vader_array_t* _a21_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a21_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a21_slotarr, l5)
        t0 = vader_array_ref_load_obj(_a21_slotarr->buf, vader_array_offset(_a21_slotarr) + (size_t) l5);
        l7 = ((vader_struct_vader_midir$CFGLocal_t*) t0)->f_type;
        l3 = ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_project;
        l4 = vader_emit_bytecode$intern_type(l7, l3);
        l8 = vader_core_bytecode$union_layout_struct(((vader_struct_vader_emit_bytecode$EmitterCtx_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_project)->f_types, l4);
        if (l8.tag == 0u) {
            t0 = l1.payload.obj;
            l18 = ((vader_struct_vader_midir$InstrUnionFieldSet_t*) t0)->f_field;
            t4 = vader_emit_bytecode$no_common_field(l0, l18, l7);
            vader_host_std_core$Intrinsic$panic(t4);
            vader_unreachable("a no-return call returned");
        } else {
            l17 = ((int32_t) l8.payload.i);
            l3 = ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_project;
            t0 = l1.payload.obj;
            l18 = ((vader_struct_vader_midir$InstrUnionFieldSet_t*) t0)->f_field;
            l8 = vader_emit_bytecode$find_struct_field_index(l3, l17, l18);
            if (l8.tag == 0u) {
                t0 = l1.payload.obj;
                l18 = ((vader_struct_vader_midir$InstrUnionFieldSet_t*) t0)->f_field;
                t4 = vader_emit_bytecode$no_common_field(l0, l18, l7);
                vader_host_std_core$Intrinsic$panic(t4);
                vader_unreachable("a no-return call returned");
            } else {
                l5 = ((int64_t) l8.payload.i);
                t0 = l1.payload.obj;
                l22 = ((vader_struct_vader_midir$InstrUnionFieldSet_t*) t0)->f_target;
                t0 = l1.payload.obj;
                l3 = ((vader_struct_vader_midir$InstrUnionFieldSet_t*) t0)->f_span;
                vader_emit_bytecode$emit_first_get(l0, l2, l22, l3);
                t0 = l1.payload.obj;
                l22 = ((vader_struct_vader_midir$InstrUnionFieldSet_t*) t0)->f_value;
                t0 = l1.payload.obj;
                l3 = ((vader_struct_vader_midir$InstrUnionFieldSet_t*) t0)->f_span;
                vader_emit_bytecode$emit_get(l0, l22, l3);
                t0 = l1.payload.obj;
                l22 = ((vader_struct_vader_midir$InstrUnionFieldSet_t*) t0)->f_value;
                l6 = vader_emit_bytecode$boxed_field(((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_project, l17, l5);
                t0 = l1.payload.obj;
                l3 = ((vader_struct_vader_midir$InstrUnionFieldSet_t*) t0)->f_span;
                vader_emit_bytecode$emit_retag_into(l0, l22, l6, l3);
                l17 = ((int32_t) (int64_t) l5);
                vader_struct_vader_core_bytecode$UnionFieldSet_t* _a22_obj = (vader_struct_vader_core_bytecode$UnionFieldSet_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$UnionFieldSet_t));
                vader_obj_header_init(_a22_obj, 1339u);
                _a22_obj->f_type_id = l4;
                _a22_obj->f_field_index = l17;
                l3 = (void*) _a22_obj;
                t0 = l1.payload.obj;
                l12 = ((vader_struct_vader_midir$InstrUnionFieldSet_t*) t0)->f_span;
                vader_emit_bytecode$push_emit(l0, vader_ref_box(l3), l12);
                { vader_gc_top = gc_frame.prev; return; }
            }
        }
    } else {
        if (l1.tag == 1834u) {
            l3 = ((vader_struct_vader_midir$CFGFunction_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_fn_)->f_locals;
            t0 = l1.payload.obj;
            l5 = ((int64_t) (int32_t) ((vader_struct_vader_midir$InstrArrayGet_t*) t0)->f_target);
            vader_array_t* _a23_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a23_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a23_slotarr, l5)
            t0 = vader_array_ref_load_obj(_a23_slotarr->buf, vader_array_offset(_a23_slotarr) + (size_t) l5);
            l7 = ((vader_struct_vader_midir$CFGLocal_t*) t0)->f_type;
            l3 = ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_project;
            l4 = vader_emit_bytecode$intern_type(l7, l3);
            t0 = l1.payload.obj;
            l17 = ((vader_struct_vader_midir$InstrArrayGet_t*) t0)->f_target;
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir$InstrArrayGet_t*) t0)->f_span;
            vader_emit_bytecode$emit_first_get(l0, l2, l17, l3);
            t0 = l1.payload.obj;
            l17 = ((vader_struct_vader_midir$InstrArrayGet_t*) t0)->f_index;
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir$InstrArrayGet_t*) t0)->f_span;
            vader_emit_bytecode$emit_get(l0, l17, l3);
            l10 = vader_emit_bytecode$array_element_val_type(l7);
            t0 = l1.payload.obj;
            l6 = ((vader_struct_vader_midir$InstrArrayGet_t*) t0)->f_bounds_safe;
            l7 = vader_midir_select$slot_load_op_for(l10, l6);
            if (l7.tag == 0u) {
                t0 = l1.payload.obj;
                l6 = ((vader_struct_vader_midir$InstrArrayGet_t*) t0)->f_bounds_safe;
                vader_struct_vader_core_bytecode$ArrayGet_t* _a24_obj = (vader_struct_vader_core_bytecode$ArrayGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$ArrayGet_t));
                vader_obj_header_init(_a24_obj, 1167u);
                _a24_obj->f_type_id = l4;
                _a24_obj->f_bounds_safe = l6;
                l3 = (void*) _a24_obj;
                t0 = l1.payload.obj;
                l12 = ((vader_struct_vader_midir$InstrArrayGet_t*) t0)->f_span;
                vader_emit_bytecode$push_emit(l0, vader_ref_box(l3), l12);
                t0 = l1.payload.obj;
                t1 = vader_emit_bytecode$needs_ref_cast(((vader_struct_vader_midir$InstrArrayGet_t*) t0)->f_type);
                if (t1) {
                    t0 = l1.payload.obj;
                    l8 = ((vader_struct_vader_midir$InstrArrayGet_t*) t0)->f_type;
                    l3 = ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_project;
                    t3 = vader_emit_bytecode$intern_type(l8, l3);
                    vader_struct_vader_core_bytecode$RefCast_t* _a25_obj = (vader_struct_vader_core_bytecode$RefCast_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$RefCast_t));
                    vader_obj_header_init(_a25_obj, 1303u);
                    _a25_obj->f_type_id = t3;
                    l3 = (void*) _a25_obj;
                    t0 = l1.payload.obj;
                    l12 = ((vader_struct_vader_midir$InstrArrayGet_t*) t0)->f_span;
                    vader_emit_bytecode$push_emit(l0, vader_ref_box(l3), l12);
                }
            } else {
                t0 = l1.payload.obj;
                l3 = ((vader_struct_vader_midir$InstrArrayGet_t*) t0)->f_span;
                vader_emit_bytecode$push_emit(l0, l7, l3);
            }
            t0 = l1.payload.obj;
            l4 = ((vader_struct_vader_midir$InstrArrayGet_t*) t0)->f_dst;
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir$InstrArrayGet_t*) t0)->f_span;
            vader_emit_bytecode$emit_result(l0, l2, l4, l3);
            { vader_gc_top = gc_frame.prev; return; }
        }
        if (l1.tag == 1838u) {
            l3 = ((vader_struct_vader_midir$CFGFunction_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_fn_)->f_locals;
            t0 = l1.payload.obj;
            l5 = ((int64_t) (int32_t) ((vader_struct_vader_midir$InstrArraySet_t*) t0)->f_target);
            vader_array_t* _a26_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a26_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a26_slotarr, l5)
            t0 = vader_array_ref_load_obj(_a26_slotarr->buf, vader_array_offset(_a26_slotarr) + (size_t) l5);
            l7 = ((vader_struct_vader_midir$CFGLocal_t*) t0)->f_type;
            l3 = ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_project;
            l4 = vader_emit_bytecode$intern_type(l7, l3);
            t0 = l1.payload.obj;
            l17 = ((vader_struct_vader_midir$InstrArraySet_t*) t0)->f_target;
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir$InstrArraySet_t*) t0)->f_span;
            vader_emit_bytecode$emit_first_get(l0, l2, l17, l3);
            t0 = l1.payload.obj;
            l17 = ((vader_struct_vader_midir$InstrArraySet_t*) t0)->f_index;
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir$InstrArraySet_t*) t0)->f_span;
            vader_emit_bytecode$emit_get(l0, l17, l3);
            t0 = l1.payload.obj;
            l17 = ((vader_struct_vader_midir$InstrArraySet_t*) t0)->f_value;
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir$InstrArraySet_t*) t0)->f_span;
            vader_emit_bytecode$emit_get(l0, l17, l3);
            t0 = l1.payload.obj;
            l17 = ((vader_struct_vader_midir$InstrArraySet_t*) t0)->f_value;
            l6 = vader_emit_bytecode$boxed_element(l7);
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir$InstrArraySet_t*) t0)->f_span;
            vader_emit_bytecode$emit_retag_into(l0, l17, l6, l3);
            l10 = vader_emit_bytecode$array_element_val_type(l7);
            t0 = l1.payload.obj;
            l6 = ((vader_struct_vader_midir$InstrArraySet_t*) t0)->f_bounds_safe;
            l7 = vader_midir_select$slot_store_op_for(l10, l6);
            if (l7.tag == 0u) {
                t0 = l1.payload.obj;
                l6 = ((vader_struct_vader_midir$InstrArraySet_t*) t0)->f_bounds_safe;
                vader_struct_vader_core_bytecode$ArraySet_t* _a27_obj = (vader_struct_vader_core_bytecode$ArraySet_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$ArraySet_t));
                vader_obj_header_init(_a27_obj, 1175u);
                _a27_obj->f_type_id = l4;
                _a27_obj->f_bounds_safe = l6;
                l3 = (void*) _a27_obj;
                t0 = l1.payload.obj;
                l12 = ((vader_struct_vader_midir$InstrArraySet_t*) t0)->f_span;
                vader_emit_bytecode$push_emit(l0, vader_ref_box(l3), l12);
                { vader_gc_top = gc_frame.prev; return; }
            }
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir$InstrArraySet_t*) t0)->f_span;
            vader_emit_bytecode$push_emit(l0, l7, l3);
            { vader_gc_top = gc_frame.prev; return; }
        }
        if (l1.tag == 1835u) {
            t0 = l1.payload.obj;
            l4 = ((vader_struct_vader_midir$InstrArrayLen_t*) t0)->f_target;
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir$InstrArrayLen_t*) t0)->f_span;
            vader_emit_bytecode$emit_first_get(l0, l2, l4, l3);
            t0 = (void*) &vader_data_90;
            vader_array_t* _a28_slotarr = ((vader_array_t*) t0);
            VADER_ARRAY_RESOLVE_BUF(_a28_slotarr)
            l3 = vader_array_ref_load_obj(_a28_slotarr->buf, vader_array_offset(_a28_slotarr) + (size_t) INT64_C(0));
            t0 = l1.payload.obj;
            l12 = ((vader_struct_vader_midir$InstrArrayLen_t*) t0)->f_span;
            vader_emit_bytecode$push_emit(l0, vader_ref_box(l3), l12);
            t0 = l1.payload.obj;
            l4 = ((vader_struct_vader_midir$InstrArrayLen_t*) t0)->f_dst;
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir$InstrArrayLen_t*) t0)->f_span;
            vader_emit_bytecode$emit_result(l0, l2, l4, l3);
            { vader_gc_top = gc_frame.prev; return; }
        }
        if (l1.tag == 1837u) {
            l3 = ((vader_struct_vader_midir$CFGFunction_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_fn_)->f_locals;
            t0 = l1.payload.obj;
            l5 = ((int64_t) (int32_t) ((vader_struct_vader_midir$InstrArrayPush_t*) t0)->f_target);
            vader_array_t* _a29_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a29_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a29_slotarr, l5)
            t0 = vader_array_ref_load_obj(_a29_slotarr->buf, vader_array_offset(_a29_slotarr) + (size_t) l5);
            l7 = ((vader_struct_vader_midir$CFGLocal_t*) t0)->f_type;
            l3 = ((vader_struct_vader_midir$CFGFunction_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_fn_)->f_locals;
            t0 = l1.payload.obj;
            l5 = ((int64_t) (int32_t) ((vader_struct_vader_midir$InstrArrayPush_t*) t0)->f_value);
            vader_array_t* _a30_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a30_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a30_slotarr, l5)
            t0 = vader_array_ref_load_obj(_a30_slotarr->buf, vader_array_offset(_a30_slotarr) + (size_t) l5);
            l8 = ((vader_struct_vader_midir$CFGLocal_t*) t0)->f_type;
            l7 = vader_emit_bytecode$pushed_element_type(l7, l8);
            t0 = l1.payload.obj;
            l4 = ((vader_struct_vader_midir$InstrArrayPush_t*) t0)->f_target;
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir$InstrArrayPush_t*) t0)->f_span;
            vader_emit_bytecode$emit_first_get(l0, l2, l4, l3);
            t0 = l1.payload.obj;
            l4 = ((vader_struct_vader_midir$InstrArrayPush_t*) t0)->f_value;
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir$InstrArrayPush_t*) t0)->f_span;
            vader_emit_bytecode$emit_get(l0, l4, l3);
            t0 = l1.payload.obj;
            l4 = ((vader_struct_vader_midir$InstrArrayPush_t*) t0)->f_value;
            l6 = vader_midir_select$is_boxed_slot(l7);
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir$InstrArrayPush_t*) t0)->f_span;
            vader_emit_bytecode$emit_retag_into(l0, l4, l6, l3);
            t0 = l1.payload.obj;
            t1 = ((vader_struct_vader_midir$InstrArrayPush_t*) t0)->f_cached;
            if (t1) {
                l3 = ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_local_to_slot;
                t0 = l1.payload.obj;
                l5 = ((int64_t) (int32_t) ((vader_struct_vader_midir$InstrArrayPush_t*) t0)->f_target);
                vader_array_t* _a31_slotarr = ((vader_array_t*) l3);
                VADER_ARRAY_RESOLVE_BUF(_a31_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a31_slotarr, l5)
                l4 = ((int32_t*) _a31_slotarr->buf->slots)[vader_array_offset(_a31_slotarr) + (size_t) l5];
            } else {
                l4 = INT32_C(-1);
            }
            l3 = ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_project;
            t3 = vader_emit_bytecode$intern_type(l7, l3);
            vader_struct_vader_core_bytecode$ArrayPush_t* _a32_obj = (vader_struct_vader_core_bytecode$ArrayPush_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$ArrayPush_t));
            vader_obj_header_init(_a32_obj, 1170u);
            _a32_obj->f_type_id = t3;
            _a32_obj->f_cache_slot = l4;
            l3 = (void*) _a32_obj;
            t0 = l1.payload.obj;
            l12 = ((vader_struct_vader_midir$InstrArrayPush_t*) t0)->f_span;
            vader_emit_bytecode$push_emit(l0, vader_ref_box(l3), l12);
            { vader_gc_top = gc_frame.prev; return; }
        }
        if (l1.tag == 1839u) {
            t0 = l1.payload.obj;
            l7 = ((vader_struct_vader_midir$InstrArraySlice_t*) t0)->f_type;
            l3 = ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_project;
            l4 = vader_emit_bytecode$intern_type(l7, l3);
            t0 = l1.payload.obj;
            l17 = ((vader_struct_vader_midir$InstrArraySlice_t*) t0)->f_target;
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir$InstrArraySlice_t*) t0)->f_span;
            vader_emit_bytecode$emit_first_get(l0, l2, l17, l3);
            t0 = l1.payload.obj;
            l17 = ((vader_struct_vader_midir$InstrArraySlice_t*) t0)->f_lo;
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir$InstrArraySlice_t*) t0)->f_span;
            vader_emit_bytecode$emit_get(l0, l17, l3);
            t0 = l1.payload.obj;
            l17 = ((vader_struct_vader_midir$InstrArraySlice_t*) t0)->f_hi;
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir$InstrArraySlice_t*) t0)->f_span;
            vader_emit_bytecode$emit_get(l0, l17, l3);
            vader_struct_vader_core_bytecode$ArraySlice_t* _a33_obj = (vader_struct_vader_core_bytecode$ArraySlice_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$ArraySlice_t));
            vader_obj_header_init(_a33_obj, 1176u);
            _a33_obj->f_type_id = l4;
            l3 = (void*) _a33_obj;
            t0 = l1.payload.obj;
            l12 = ((vader_struct_vader_midir$InstrArraySlice_t*) t0)->f_span;
            vader_emit_bytecode$push_emit(l0, vader_ref_box(l3), l12);
            t0 = l1.payload.obj;
            l4 = ((vader_struct_vader_midir$InstrArraySlice_t*) t0)->f_dst;
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir$InstrArraySlice_t*) t0)->f_span;
            vader_emit_bytecode$emit_result(l0, l2, l4, l3);
            { vader_gc_top = gc_frame.prev; return; }
        }
        if (l1.tag == 1860u) {
            t0 = l1.payload.obj;
            l7 = ((vader_struct_vader_midir$InstrStructNew_t*) t0)->f_type;
            l3 = ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_project;
            l4 = vader_emit_bytecode$intern_type(l7, l3);
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir$InstrStructNew_t*) t0)->f_fields;
            l12 = vader_emit_bytecode$boxed_fields_of(((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_project, l4);
            t0 = l1.payload.obj;
            l14 = ((vader_struct_vader_midir$InstrStructNew_t*) t0)->f_span;
            vader_emit_bytecode$emit_operands_into(l0, l2, l3, l12, l14);
            t0 = l1.payload.obj;
            l6 = ((vader_struct_vader_midir$InstrStructNew_t*) t0)->f_stack;
            vader_struct_vader_core_bytecode$StructNew_t* _a34_obj = (vader_struct_vader_core_bytecode$StructNew_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$StructNew_t));
            vader_obj_header_init(_a34_obj, 1322u);
            _a34_obj->f_type_id = l4;
            _a34_obj->f_stack = l6;
            l3 = (void*) _a34_obj;
            t0 = l1.payload.obj;
            l12 = ((vader_struct_vader_midir$InstrStructNew_t*) t0)->f_span;
            vader_emit_bytecode$push_emit(l0, vader_ref_box(l3), l12);
            t0 = l1.payload.obj;
            l4 = ((vader_struct_vader_midir$InstrStructNew_t*) t0)->f_dst;
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir$InstrStructNew_t*) t0)->f_span;
            vader_emit_bytecode$emit_result(l0, l2, l4, l3);
            { vader_gc_top = gc_frame.prev; return; }
        }
        if (l1.tag == 1836u) {
            t0 = l1.payload.obj;
            l7 = ((vader_struct_vader_midir$InstrArrayNew_t*) t0)->f_type;
            l3 = ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_project;
            l4 = vader_emit_bytecode$intern_type(l7, l3);
            t0 = l1.payload.obj;
            t1 = vader_emit_bytecode$boxed_element(((vader_struct_vader_midir$InstrArrayNew_t*) t0)->f_type);
            vader_array_t* _a35_arr = vader_array_new(24u, 1u, 12u, 575u);
            ((uint8_t*) _a35_arr->buf->slots)[vader_array_offset(_a35_arr) + 0u] = (uint8_t) t1;
            l3 = (void*) _a35_arr;
            t0 = l1.payload.obj;
            l5 = vader_array_length(((vader_array_t*) ((vader_struct_vader_midir$InstrArrayNew_t*) t0)->f_elements));
            vader_array_t* _a36_arr = vader_array_repeat((vader_array_t*) l3, (int64_t) l5);
            l3 = (void*) _a36_arr;
            t0 = l1.payload.obj;
            l12 = ((vader_struct_vader_midir$InstrArrayNew_t*) t0)->f_elements;
            t0 = l1.payload.obj;
            l14 = ((vader_struct_vader_midir$InstrArrayNew_t*) t0)->f_span;
            vader_emit_bytecode$emit_operands_into(l0, l2, l12, l3, l14);
            t0 = l1.payload.obj;
            l17 = ((vader_struct_vader_midir$InstrArrayNew_t*) t0)->f_length;
            vader_struct_vader_core_bytecode$ArrayNew_t* _a37_obj = (vader_struct_vader_core_bytecode$ArrayNew_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$ArrayNew_t));
            vader_obj_header_init(_a37_obj, 1169u);
            _a37_obj->f_type_id = l4;
            _a37_obj->f_length = l17;
            l3 = (void*) _a37_obj;
            t0 = l1.payload.obj;
            l12 = ((vader_struct_vader_midir$InstrArrayNew_t*) t0)->f_span;
            vader_emit_bytecode$push_emit(l0, vader_ref_box(l3), l12);
            t0 = l1.payload.obj;
            l4 = ((vader_struct_vader_midir$InstrArrayNew_t*) t0)->f_dst;
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir$InstrArrayNew_t*) t0)->f_span;
            vader_emit_bytecode$emit_result(l0, l2, l4, l3);
            { vader_gc_top = gc_frame.prev; return; }
        }
        if (l1.tag == 1848u) {
            t0 = l1.payload.obj;
            l7 = ((vader_struct_vader_midir$InstrDataConst_t*) t0)->f_type;
            l3 = ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_project;
            l4 = vader_emit_bytecode$intern_type(l7, l3);
            t0 = l1.payload.obj;
            t3 = ((vader_struct_vader_midir$InstrDataConst_t*) t0)->f_pool_index;
            vader_struct_vader_core_bytecode$DataConst_t* _a38_obj = (vader_struct_vader_core_bytecode$DataConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$DataConst_t));
            vader_obj_header_init(_a38_obj, 1220u);
            _a38_obj->f_pool_index = t3;
            _a38_obj->f_type_id = l4;
            l3 = (void*) _a38_obj;
            t0 = l1.payload.obj;
            l12 = ((vader_struct_vader_midir$InstrDataConst_t*) t0)->f_span;
            vader_emit_bytecode$push_emit(l0, vader_ref_box(l3), l12);
            t0 = l1.payload.obj;
            l4 = ((vader_struct_vader_midir$InstrDataConst_t*) t0)->f_dst;
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir$InstrDataConst_t*) t0)->f_span;
            vader_emit_bytecode$emit_result(l0, l2, l4, l3);
            { vader_gc_top = gc_frame.prev; return; }
        }
        if (l1.tag == 1855u) {
            t0 = l1.payload.obj;
            t3 = ((vader_struct_vader_midir$InstrGlobalGet_t*) t0)->f_slot;
            vader_struct_vader_core_bytecode$GlobalGet_t* _a39_obj = (vader_struct_vader_core_bytecode$GlobalGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$GlobalGet_t));
            vader_obj_header_init(_a39_obj, 1243u);
            _a39_obj->f_index = t3;
            l3 = (void*) _a39_obj;
            t0 = l1.payload.obj;
            l12 = ((vader_struct_vader_midir$InstrGlobalGet_t*) t0)->f_span;
            vader_emit_bytecode$push_emit(l0, vader_ref_box(l3), l12);
            t0 = l1.payload.obj;
            l4 = ((vader_struct_vader_midir$InstrGlobalGet_t*) t0)->f_dst;
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir$InstrGlobalGet_t*) t0)->f_span;
            vader_emit_bytecode$emit_result(l0, l2, l4, l3);
            { vader_gc_top = gc_frame.prev; return; }
        }
        if (l1.tag == 1856u) {
            t0 = l1.payload.obj;
            l4 = ((vader_struct_vader_midir$InstrGlobalSet_t*) t0)->f_value;
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir$InstrGlobalSet_t*) t0)->f_span;
            vader_emit_bytecode$emit_first_get(l0, l2, l4, l3);
            t0 = l1.payload.obj;
            l4 = ((vader_struct_vader_midir$InstrGlobalSet_t*) t0)->f_value;
            t0 = l1.payload.obj;
            l6 = vader_midir_select$is_boxed_slot(((vader_struct_vader_midir$InstrGlobalSet_t*) t0)->f_type);
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir$InstrGlobalSet_t*) t0)->f_span;
            vader_emit_bytecode$emit_retag_into(l0, l4, l6, l3);
            t0 = l1.payload.obj;
            t3 = ((vader_struct_vader_midir$InstrGlobalSet_t*) t0)->f_slot;
            vader_struct_vader_core_bytecode$GlobalSet_t* _a40_obj = (vader_struct_vader_core_bytecode$GlobalSet_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$GlobalSet_t));
            vader_obj_header_init(_a40_obj, 1244u);
            _a40_obj->f_index = t3;
            l3 = (void*) _a40_obj;
            t0 = l1.payload.obj;
            l12 = ((vader_struct_vader_midir$InstrGlobalSet_t*) t0)->f_span;
            vader_emit_bytecode$push_emit(l0, vader_ref_box(l3), l12);
            { vader_gc_top = gc_frame.prev; return; }
        }
        if (l1.tag == 1861u) {
            l18 = ((vader_struct_vader_midir$CFGFunction_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_fn_)->f_mangled;
            t0 = l1.payload.obj;
            l7 = ((vader_struct_vader_midir$InstrTypeCheck_t*) t0)->f_check_type;
            vader_emit_bytecode$refuse_shared_identity_test(l18, l7);
            t0 = l1.payload.obj;
            l4 = ((vader_struct_vader_midir$InstrTypeCheck_t*) t0)->f_value;
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir$InstrTypeCheck_t*) t0)->f_span;
            vader_emit_bytecode$emit_first_get(l0, l2, l4, l3);
            t0 = l1.payload.obj;
            l7 = ((vader_struct_vader_midir$InstrTypeCheck_t*) t0)->f_check_type;
            l3 = ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_project;
            t3 = vader_emit_bytecode$intern_type(l7, l3);
            vader_struct_vader_core_bytecode$TypeCheck_t* _a41_obj = (vader_struct_vader_core_bytecode$TypeCheck_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$TypeCheck_t));
            vader_obj_header_init(_a41_obj, 1324u);
            _a41_obj->f_type_id = t3;
            l3 = (void*) _a41_obj;
            t0 = l1.payload.obj;
            l12 = ((vader_struct_vader_midir$InstrTypeCheck_t*) t0)->f_span;
            vader_emit_bytecode$push_emit(l0, vader_ref_box(l3), l12);
            t0 = l1.payload.obj;
            l4 = ((vader_struct_vader_midir$InstrTypeCheck_t*) t0)->f_dst;
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir$InstrTypeCheck_t*) t0)->f_span;
            vader_emit_bytecode$emit_result(l0, l2, l4, l3);
            { vader_gc_top = gc_frame.prev; return; }
        }
        if (l1.tag == 1862u) {
            t0 = l1.payload.obj;
            l7 = ((vader_struct_vader_midir$InstrTypeConst_t*) t0)->f_value_type;
            l3 = ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_project;
            t3 = vader_emit_bytecode$intern_type(l7, l3);
            vader_struct_vader_core_bytecode$TypeConst_t* _a42_obj = (vader_struct_vader_core_bytecode$TypeConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$TypeConst_t));
            vader_obj_header_init(_a42_obj, 1325u);
            _a42_obj->f_type_id = t3;
            l3 = (void*) _a42_obj;
            t0 = l1.payload.obj;
            l12 = ((vader_struct_vader_midir$InstrTypeConst_t*) t0)->f_span;
            vader_emit_bytecode$push_emit(l0, vader_ref_box(l3), l12);
            t0 = l1.payload.obj;
            l4 = ((vader_struct_vader_midir$InstrTypeConst_t*) t0)->f_dst;
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir$InstrTypeConst_t*) t0)->f_span;
            vader_emit_bytecode$emit_result(l0, l2, l4, l3);
            { vader_gc_top = gc_frame.prev; return; }
        }
        if (l1.tag == 1843u) {
            t0 = l1.payload.obj;
            l4 = ((vader_struct_vader_midir$InstrCast_t*) t0)->f_value;
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir$InstrCast_t*) t0)->f_span;
            vader_emit_bytecode$emit_first_get(l0, l2, l4, l3);
            l3 = ((vader_struct_vader_midir$CFGFunction_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_fn_)->f_locals;
            t0 = l1.payload.obj;
            l5 = ((int64_t) (int32_t) ((vader_struct_vader_midir$InstrCast_t*) t0)->f_value);
            vader_array_t* _a43_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a43_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a43_slotarr, l5)
            t0 = vader_array_ref_load_obj(_a43_slotarr->buf, vader_array_offset(_a43_slotarr) + (size_t) l5);
            l7 = ((vader_struct_vader_midir$CFGLocal_t*) t0)->f_type;
            l10 = vader_midir_select$val_type_of_type(l7);
            t0 = l1.payload.obj;
            l11 = vader_midir_select$val_type_of_type(((vader_struct_vader_midir$InstrCast_t*) t0)->f_type);
            if (l11 == INT32_C(17)) {
                l6 = vader_midir_select$is_scalar_class(l10);
            } else {
                l6 = false;
            }
            if (l6) {
                l3 = ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_project;
                t3 = vader_emit_bytecode$intern_type(l7, l3);
                vader_struct_vader_core_bytecode$Retag_t* _a44_obj = (vader_struct_vader_core_bytecode$Retag_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$Retag_t));
                vader_obj_header_init(_a44_obj, 1306u);
                _a44_obj->f_type_id = t3;
                l3 = (void*) _a44_obj;
                t0 = l1.payload.obj;
                l12 = ((vader_struct_vader_midir$InstrCast_t*) t0)->f_span;
                vader_emit_bytecode$push_emit(l0, vader_ref_box(l3), l12);
            } else if (l10 != l11) {
                l7 = vader_core_bytecode$convert_target_of(l11);
                if (l7.tag == 0u) {
                    t0 = l1.payload.obj;
                    l8 = ((vader_struct_vader_midir$InstrCast_t*) t0)->f_type;
                    l3 = ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_project;
                    t3 = vader_emit_bytecode$intern_type(l8, l3);
                    vader_struct_vader_core_bytecode$RefCast_t* _a45_obj = (vader_struct_vader_core_bytecode$RefCast_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$RefCast_t));
                    vader_obj_header_init(_a45_obj, 1303u);
                    _a45_obj->f_type_id = t3;
                    l3 = (void*) _a45_obj;
                    t0 = l1.payload.obj;
                    l12 = ((vader_struct_vader_midir$InstrCast_t*) t0)->f_span;
                    vader_emit_bytecode$push_emit(l0, vader_ref_box(l3), l12);
                } else {
                    t1 = vader_emit_bytecode$convert_eligible(l10);
                    if (t1) {
                        l18 = vader_core_bytecode$val_type_name(l10);
                        l23 = ((uint8_t) l7.payload.i);
                        vader_struct_vader_core_bytecode$Convert_t* _a46_obj = (vader_struct_vader_core_bytecode$Convert_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$Convert_t));
                        vader_obj_header_init(_a46_obj, 1219u);
                        _a46_obj->f_from_name = l18;
                        _a46_obj->f_target = l23;
                        l3 = (void*) _a46_obj;
                        t0 = l1.payload.obj;
                        l12 = ((vader_struct_vader_midir$InstrCast_t*) t0)->f_span;
                        vader_emit_bytecode$push_emit(l0, vader_ref_box(l3), l12);
                        t1 = vader_emit_bytecode$fits_in(l10, l11);
                        if (!(t1)) {
                            t0 = l1.payload.obj;
                            l3 = ((vader_struct_vader_midir$InstrCast_t*) t0)->f_span;
                            vader_emit_bytecode$emit_narrowing(l0, l11, l3);
                        }
                    } else {
                        t0 = l1.payload.obj;
                        l7 = ((vader_struct_vader_midir$InstrCast_t*) t0)->f_type;
                        l3 = ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_project;
                        t3 = vader_emit_bytecode$intern_type(l7, l3);
                        vader_struct_vader_core_bytecode$RefCast_t* _a47_obj = (vader_struct_vader_core_bytecode$RefCast_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$RefCast_t));
                        vader_obj_header_init(_a47_obj, 1303u);
                        _a47_obj->f_type_id = t3;
                        l3 = (void*) _a47_obj;
                        t0 = l1.payload.obj;
                        l12 = ((vader_struct_vader_midir$InstrCast_t*) t0)->f_span;
                        vader_emit_bytecode$push_emit(l0, vader_ref_box(l3), l12);
                    }
                }
            }
            t0 = l1.payload.obj;
            l4 = ((vader_struct_vader_midir$InstrCast_t*) t0)->f_dst;
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir$InstrCast_t*) t0)->f_span;
            vader_emit_bytecode$emit_result(l0, l2, l4, l3);
            { vader_gc_top = gc_frame.prev; return; }
        }
        if (l1.tag == 1845u) {
            t0 = l1.payload.obj;
            l7 = ((vader_struct_vader_midir$InstrCellNew_t*) t0)->f_value_type;
            l3 = ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_project;
            l4 = vader_emit_bytecode$intern_cell_type(l7, l3);
            t0 = l1.payload.obj;
            l17 = ((vader_struct_vader_midir$InstrCellNew_t*) t0)->f_value;
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir$InstrCellNew_t*) t0)->f_span;
            vader_emit_bytecode$emit_first_get(l0, l2, l17, l3);
            t0 = l1.payload.obj;
            l17 = ((vader_struct_vader_midir$InstrCellNew_t*) t0)->f_value;
            t0 = l1.payload.obj;
            l6 = vader_midir_select$is_boxed_slot(((vader_struct_vader_midir$InstrCellNew_t*) t0)->f_value_type);
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir$InstrCellNew_t*) t0)->f_span;
            vader_emit_bytecode$emit_retag_into(l0, l17, l6, l3);
            vader_struct_vader_core_bytecode$StructNew_t* _a48_obj = (vader_struct_vader_core_bytecode$StructNew_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$StructNew_t));
            vader_obj_header_init(_a48_obj, 1322u);
            _a48_obj->f_type_id = l4;
            _a48_obj->f_stack = false;
            l3 = (void*) _a48_obj;
            t0 = l1.payload.obj;
            l12 = ((vader_struct_vader_midir$InstrCellNew_t*) t0)->f_span;
            vader_emit_bytecode$push_emit(l0, vader_ref_box(l3), l12);
            t0 = l1.payload.obj;
            l4 = ((vader_struct_vader_midir$InstrCellNew_t*) t0)->f_dst;
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir$InstrCellNew_t*) t0)->f_span;
            vader_emit_bytecode$emit_result(l0, l2, l4, l3);
            { vader_gc_top = gc_frame.prev; return; }
        }
        if (l1.tag == 1844u) {
            t0 = l1.payload.obj;
            l7 = ((vader_struct_vader_midir$InstrCellGet_t*) t0)->f_value_type;
            l3 = ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_project;
            l4 = vader_emit_bytecode$intern_cell_type(l7, l3);
            l6 = std_collections$Set$std_core$Contains$contains__i64(((vader_struct_vader_emit_bytecode$ScheduleHints_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_hints)->f_skip_first_get, l2);
            t0 = l1.payload.obj;
            l17 = ((vader_struct_vader_midir$InstrCellGet_t*) t0)->f_cell;
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir$InstrCellGet_t*) t0)->f_span;
            vader_emit_bytecode$emit_first_get(l0, l2, l17, l3);
            l9 = false;
            if (!(l6)) {
                l9 = vader_emit_bytecode$try_fuse_local_field(l0, l4, INT32_C(0));
            }
            if (!(l9)) {
                vader_struct_vader_core_bytecode$StructGet_t* _a49_obj = (vader_struct_vader_core_bytecode$StructGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$StructGet_t));
                vader_obj_header_init(_a49_obj, 1321u);
                _a49_obj->f_type_id = l4;
                _a49_obj->f_field_index = INT32_C(0);
                l3 = (void*) _a49_obj;
                t0 = l1.payload.obj;
                l12 = ((vader_struct_vader_midir$InstrCellGet_t*) t0)->f_span;
                vader_emit_bytecode$push_emit(l0, vader_ref_box(l3), l12);
            }
            t0 = l1.payload.obj;
            l4 = ((vader_struct_vader_midir$InstrCellGet_t*) t0)->f_dst;
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir$InstrCellGet_t*) t0)->f_span;
            vader_emit_bytecode$emit_result(l0, l2, l4, l3);
            { vader_gc_top = gc_frame.prev; return; }
        }
        if (l1.tag == 1846u) {
            t0 = l1.payload.obj;
            l7 = ((vader_struct_vader_midir$InstrCellSet_t*) t0)->f_value_type;
            l3 = ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_project;
            l4 = vader_emit_bytecode$intern_cell_type(l7, l3);
            t0 = l1.payload.obj;
            l17 = ((vader_struct_vader_midir$InstrCellSet_t*) t0)->f_cell;
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir$InstrCellSet_t*) t0)->f_span;
            vader_emit_bytecode$emit_first_get(l0, l2, l17, l3);
            t0 = l1.payload.obj;
            l17 = ((vader_struct_vader_midir$InstrCellSet_t*) t0)->f_value;
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir$InstrCellSet_t*) t0)->f_span;
            vader_emit_bytecode$emit_get(l0, l17, l3);
            t0 = l1.payload.obj;
            l17 = ((vader_struct_vader_midir$InstrCellSet_t*) t0)->f_value;
            t0 = l1.payload.obj;
            l6 = vader_midir_select$is_boxed_slot(((vader_struct_vader_midir$InstrCellSet_t*) t0)->f_value_type);
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir$InstrCellSet_t*) t0)->f_span;
            vader_emit_bytecode$emit_retag_into(l0, l17, l6, l3);
            vader_struct_vader_core_bytecode$StructSet_t* _a50_obj = (vader_struct_vader_core_bytecode$StructSet_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$StructSet_t));
            vader_obj_header_init(_a50_obj, 1323u);
            _a50_obj->f_type_id = l4;
            _a50_obj->f_field_index = INT32_C(0);
            _a50_obj->f_stack = false;
            l3 = (void*) _a50_obj;
            t0 = l1.payload.obj;
            l12 = ((vader_struct_vader_midir$InstrCellSet_t*) t0)->f_span;
            vader_emit_bytecode$push_emit(l0, vader_ref_box(l3), l12);
            { vader_gc_top = gc_frame.prev; return; }
        }
        if (l1.tag == 1858u) {
            t0 = l1.payload.obj;
            l4 = ((vader_struct_vader_midir$InstrMakeClosure_t*) t0)->f_env;
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir$InstrMakeClosure_t*) t0)->f_span;
            vader_emit_bytecode$emit_first_get(l0, l2, l4, l3);
            t0 = l1.payload.obj;
            l7 = vader_emit_bytecode$closure_header_type(((vader_struct_vader_midir$InstrMakeClosure_t*) t0)->f_type);
            l3 = ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_project;
            l4 = vader_emit_bytecode$intern_type(l7, l3);
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir$InstrMakeClosure_t*) t0)->f_fn_symbol;
            l12 = ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_project;
            l7 = vader_emit_bytecode$resolve_fn_index(l3, l12);
            if (!(l7.tag == 580u)) {
                t0 = l1.payload.obj;
                l18 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_midir$InstrMakeClosure_t*) t0)->f_fn_symbol)->f_name;
                l5 = vader_host_std_core$Intrinsic$byte_len(l18);
                l14 = (void*) vader_buffer_new((size_t) (INT64_C(106) + l5));
                l5 = INT64_C(0);
                l5 = std_core$write_string_at(l14, l5, 2291u);
                l5 = std_core$write_string_at(l14, l5, l18);
                l5 = std_core$write_string_at(l14, l5, 343u);
                t0 = l1.payload.obj;
                t3 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_midir$InstrMakeClosure_t*) t0)->f_fn_symbol)->f_id;
                l13 = ((int64_t) (int32_t) t3);
                l5 = std_core$write_int(l14, l5, l13);
                l5 = std_core$write_string_at(l14, l5, 382u);
                t4 = std_core$finish_buffer(l14, l5);
                vader_host_std_core$Intrinsic$panic(t4);
                vader_unreachable("a no-return call returned");
            }
            t3 = ((int32_t) l7.payload.i);
            vader_struct_vader_core_bytecode$MakeClosure_t* _a51_obj = (vader_struct_vader_core_bytecode$MakeClosure_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$MakeClosure_t));
            vader_obj_header_init(_a51_obj, 1299u);
            _a51_obj->f_function_index = t3;
            _a51_obj->f_env_type_id = l4;
            l3 = (void*) _a51_obj;
            t0 = l1.payload.obj;
            l12 = ((vader_struct_vader_midir$InstrMakeClosure_t*) t0)->f_span;
            vader_emit_bytecode$push_emit(l0, vader_ref_box(l3), l12);
            t0 = l1.payload.obj;
            l4 = ((vader_struct_vader_midir$InstrMakeClosure_t*) t0)->f_dst;
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir$InstrMakeClosure_t*) t0)->f_span;
            vader_emit_bytecode$emit_result(l0, l2, l4, l3);
            { vader_gc_top = gc_frame.prev; return; }
        }
        if (l1.tag == 1857u) {
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir$InstrIntrinsic_t*) t0)->f_args;
            vader_array_t* _a52_arr = vader_array_new(24u, 0u, 12u, 575u);
            l12 = (void*) _a52_arr;
            t0 = l1.payload.obj;
            l14 = ((vader_struct_vader_midir$InstrIntrinsic_t*) t0)->f_span;
            vader_emit_bytecode$emit_operands_into(l0, l2, l3, l12, l14);
            t0 = l1.payload.obj;
            t4 = ((vader_struct_vader_midir$InstrIntrinsic_t*) t0)->f_name;
            l8 = vader_midir_select$intrinsic_op_for_name(t4);
            if (l8.tag == 0u) {
                t0 = l1.payload.obj;
                l18 = ((vader_struct_vader_midir$InstrIntrinsic_t*) t0)->f_name;
                l19 = ((vader_struct_vader_midir$CFGFunction_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_fn_)->f_mangled;
                t4 = concat_5(2289u, l18, 1384u, l19, 356u);
                vader_host_std_core$Intrinsic$panic(t4);
                vader_unreachable("a no-return call returned");
            } else {
                l7 = l8;
                l3 = l1.payload.obj;
                l7 = vader_emit_bytecode$typed_intrinsic_op(l0, l7, l3);
                t0 = l1.payload.obj;
                l3 = ((vader_struct_vader_midir$InstrIntrinsic_t*) t0)->f_span;
                vader_emit_bytecode$push_emit(l0, l7, l3);
                t0 = l1.payload.obj;
                l7 = ((vader_struct_vader_midir$InstrIntrinsic_t*) t0)->f_dst;
                t0 = l1.payload.obj;
                l3 = ((vader_struct_vader_midir$InstrIntrinsic_t*) t0)->f_span;
                vader_emit_bytecode$emit_result_if_any(l0, l2, l7, l3);
                { vader_gc_top = gc_frame.prev; return; }
            }
        } else {
            if (l1.tag == 1850u) {
                t0 = l1.payload.obj;
                l4 = ((vader_struct_vader_midir$InstrDeferPush_t*) t0)->f_value;
                t0 = l1.payload.obj;
                l3 = ((vader_struct_vader_midir$InstrDeferPush_t*) t0)->f_span;
                vader_emit_bytecode$emit_first_get(l0, l2, l4, l3);
                t0 = (void*) &vader_data_91;
                vader_array_t* _a53_slotarr = ((vader_array_t*) t0);
                VADER_ARRAY_RESOLVE_BUF(_a53_slotarr)
                l3 = vader_array_ref_load_obj(_a53_slotarr->buf, vader_array_offset(_a53_slotarr) + (size_t) INT64_C(0));
                t0 = l1.payload.obj;
                l12 = ((vader_struct_vader_midir$InstrDeferPush_t*) t0)->f_span;
                vader_emit_bytecode$push_emit(l0, vader_ref_box(l3), l12);
                { vader_gc_top = gc_frame.prev; return; }
            }
            if (!(l1.tag == 1849u)) {
                vader_host_std_core$Intrinsic$panic(2288u);
                vader_unreachable("a no-return call returned");
            }
            t0 = l1.payload.obj;
            t3 = ((vader_struct_vader_midir$InstrDeferPopExec_t*) t0)->f_count;
            vader_struct_vader_core_bytecode$DeferPopExec_t* _a54_obj = (vader_struct_vader_core_bytecode$DeferPopExec_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$DeferPopExec_t));
            vader_obj_header_init(_a54_obj, 1222u);
            _a54_obj->f_count = t3;
            l3 = (void*) _a54_obj;
            t0 = l1.payload.obj;
            l12 = ((vader_struct_vader_midir$InstrDeferPopExec_t*) t0)->f_span;
            vader_emit_bytecode$push_emit(l0, vader_ref_box(l3), l12);
            { vader_gc_top = gc_frame.prev; return; }
        }
    }
    vader_gc_top = gc_frame.prev;
}

static void vader_emit_bytecode$emit_instructions(void* l0, int32_t l1, int64_t l2, int64_t l3) {
    void* l4 = NULL;
    int32_t l5;
    int64_t l6, l8;
    vader_box_t l7 = vader_box_null();
    vader_box_t* gc_roots[1] = { &l7 };
    void** gc_raw_roots[2] = { &l0, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l4 = ((vader_struct_vader_midir$CFGFunction_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_fn_)->f_blocks;
    l5 = l1;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
    l4 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l5);
    l6 = l2;
    while ((l6 < l3)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_midir$BasicBlock_t*) l4)->f_instructions);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l6)
        l7 = vader_array_ref_load_box(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l6);
        l8 = vader_midir$pos_key(l1, l6);
        vader_emit_bytecode$emit_instr(l0, l7, l8);
        l6 = (l6 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_bytecode$emit_loop(void* l0, void* l1, int32_t l2, int32_t l3) {
    void* l4 = NULL;
    void* l6 = NULL;
    void* l8 = NULL;
    int32_t l5, l7, l9;
    void* t0 = NULL;
    int64_t t1;
    void** gc_raw_roots[6] = { &l0, &l1, &l4, &l6, &l8, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 6u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l4 = ((vader_struct_vader_emit_bytecode$StructureShape_t*) l1)->f_exits;
    l5 = l2;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
    l4 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l5);
    l5 = vader_emit_bytecode$open_blocks(l0, l4, l3);
    l6 = ((vader_struct_vader_midir$CFGFunction_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_fn_)->f_blocks;
    l7 = l2;
    vader_array_t* _a1_slotarr = ((vader_array_t*) l6);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l7)
    t0 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l7);
    l6 = ((vader_struct_vader_midir$BasicBlock_t*) t0)->f_span;
    l8 = ((vader_struct_vader_emit_bytecode$StructureShape_t*) l1)->f_merges;
    l9 = l2;
    vader_array_t* _a2_slotarr = ((vader_array_t*) l8);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l9)
    t0 = vader_array_ref_load_obj(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l9);
    t1 = vader_array_length(((vader_array_t*) t0));
    if (t1 == INT64_C(0)) {
        l7 = vader_emit_bytecode$loop_exit(l0, l1, l2);
    } else {
        l7 = INT32_C(-1);
    }
    vader_emit_bytecode$cf_loop(l0, l6, l2);
    vader_emit_bytecode$emit_body(l0, l1, l2, INT32_C(-1), l7);
    vader_emit_bytecode$cf_end(l0, l6);
    if ((l7 >= INT32_C(0))) {
        vader_emit_bytecode$emit_branch(l0, l1, l2, l7, l5, l6);
        vader_emit_bytecode$close_blocks(l0, l1, l4, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_emit_bytecode$close_blocks(l0, l1, l4, l3);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_bytecode$emit_narrowing(void* l0, uint8_t l1, void* l2) {
    bool l3;
    int32_t l4;
    void* l5 = NULL;
    void* t0 = NULL;
    bool t1;
    void** gc_raw_roots[4] = { &l0, &l2, &l5, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
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
    vader_struct_vader_core_bytecode$I32Const_t* _a0_obj = (vader_struct_vader_core_bytecode$I32Const_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$I32Const_t));
    vader_obj_header_init(_a0_obj, 1250u);
    _a0_obj->f_value = l4;
    l5 = (void*) _a0_obj;
    vader_emit_bytecode$push_emit(l0, vader_ref_box(l5), l2);
    t0 = (void*) &vader_data_94;
    vader_array_t* _a1_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    l5 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) INT64_C(0));
    vader_emit_bytecode$push_emit(l0, vader_ref_box(l5), l2);
    t1 = vader_core_bytecode$is_unsigned_val(l1);
    if (t1) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l3) {
        l4 = INT32_C(128);
    } else {
        l4 = INT32_C(32768);
    }
    vader_struct_vader_core_bytecode$I32Const_t* _a2_obj = (vader_struct_vader_core_bytecode$I32Const_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$I32Const_t));
    vader_obj_header_init(_a2_obj, 1250u);
    _a2_obj->f_value = l4;
    l5 = (void*) _a2_obj;
    vader_emit_bytecode$push_emit(l0, vader_ref_box(l5), l2);
    t0 = (void*) &vader_data_95;
    vader_array_t* _a3_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
    l5 = vader_array_ref_load_obj(_a3_slotarr->buf, vader_array_offset(_a3_slotarr) + (size_t) INT64_C(0));
    vader_emit_bytecode$push_emit(l0, vader_ref_box(l5), l2);
    vader_struct_vader_core_bytecode$I32Const_t* _a4_obj = (vader_struct_vader_core_bytecode$I32Const_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$I32Const_t));
    vader_obj_header_init(_a4_obj, 1250u);
    _a4_obj->f_value = l4;
    l5 = (void*) _a4_obj;
    vader_emit_bytecode$push_emit(l0, vader_ref_box(l5), l2);
    t0 = (void*) &vader_data_96;
    vader_array_t* _a5_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
    l5 = vader_array_ref_load_obj(_a5_slotarr->buf, vader_array_offset(_a5_slotarr) + (size_t) INT64_C(0));
    vader_emit_bytecode$push_emit(l0, vader_ref_box(l5), l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_bytecode$emit_operands_into(void* l0, int64_t l1, void* l2, void* l3, void* l4) {
    int64_t l5, l6, l10;
    int32_t l7, l8, l9;
    bool l11;
    bool t0;
    void** gc_raw_roots[4] = { &l0, &l2, &l3, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l5 = INT64_C(0);
    l6 = vader_array_length(((vader_array_t*) l2));
    while ((l5 < l6)) {
        if (l5 == INT64_C(0)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            l7 = ((int32_t*) _a0_slotarr->buf->slots)[vader_array_offset(_a0_slotarr) + (size_t) l5];
            vader_emit_bytecode$emit_first_get(l0, l1, l7, l4);
        } else {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            l8 = ((int32_t*) _a1_slotarr->buf->slots)[vader_array_offset(_a1_slotarr) + (size_t) l5];
            vader_emit_bytecode$emit_get(l0, l8, l4);
        }
        vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        l9 = ((int32_t*) _a2_slotarr->buf->slots)[vader_array_offset(_a2_slotarr) + (size_t) l5];
        l10 = vader_array_length(((vader_array_t*) l3));
        if ((l5 < l10)) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            t0 = ((uint8_t*) _a3_slotarr->buf->slots)[vader_array_offset(_a3_slotarr) + (size_t) l5];
            l11 = t0;
        } else {
            l11 = false;
        }
        vader_emit_bytecode$emit_retag_into(l0, l9, l11, l4);
        l5 = (l5 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_bytecode$emit_result(void* l0, int64_t l1, int32_t l2, void* l3) {
    bool t0;
    void** gc_raw_roots[2] = { &l0, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = std_collections$Set$std_core$Contains$contains__i64(((vader_struct_vader_emit_bytecode$ScheduleHints_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_hints)->f_skip_set, l1);
    if (!(t0)) {
        vader_emit_bytecode$emit_set(l0, l2, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_bytecode$emit_result_if_any(void* l0, int64_t l1, vader_box_t l2, void* l3) {
    int32_t l4;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[2] = { &l0, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (!(l2.tag == 0u)) {
        l4 = ((int32_t) l2.payload.i);
        vader_emit_bytecode$emit_result(l0, l1, l4, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_bytecode$emit_retag_into(void* l0, int32_t l1, bool l2, void* l3) {
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
    l4 = ((vader_struct_vader_midir$CFGFunction_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_fn_)->f_locals;
    l5 = ((int64_t) (int32_t) l1);
    vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
    t0 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l5);
    l6 = ((vader_struct_vader_midir$CFGLocal_t*) t0)->f_type;
    t1 = vader_midir_select$val_type_of_type(l6);
    t2 = vader_midir_select$is_scalar_class(t1);
    if (t2) {
        l4 = ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_project;
        t3 = vader_emit_bytecode$intern_type(l6, l4);
        vader_struct_vader_core_bytecode$Retag_t* _a1_obj = (vader_struct_vader_core_bytecode$Retag_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$Retag_t));
        vader_obj_header_init(_a1_obj, 1306u);
        _a1_obj->f_type_id = t3;
        l4 = (void*) _a1_obj;
        vader_emit_bytecode$push_emit(l0, vader_ref_box(l4), l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_bytecode$emit_return(void* l0, int32_t l1, void* l2) {
    vader_box_t l3 = vader_box_null();
    int64_t l4, l5;
    int32_t l6;
    bool l7;
    void* l8 = NULL;
    void* l9 = NULL;
    int64_t t0;
    vader_box_t t1 = vader_box_null();
    void* t2 = NULL;
    vader_box_t* gc_roots[2] = { &l3, &t1 };
    void** gc_raw_roots[5] = { &l0, &l2, &l8, &l9, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = vader_midir$term_return_single(l2);
    l4 = INT64_C(0);
    l5 = vader_array_length(((vader_array_t*) ((vader_struct_vader_midir$TermReturn_t*) l2)->f_values));
    while ((l4 < l5)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_midir$TermReturn_t*) l2)->f_values);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        l6 = ((int32_t*) _a0_slotarr->buf->slots)[vader_array_offset(_a0_slotarr) + (size_t) l4];
        if (!(l3.tag == 0u)) {
            l7 = std_collections$Set$std_core$Contains$contains__i32(((vader_struct_vader_emit_bytecode$ScheduleHints_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_hints)->f_skip_terminator_get, l1);
        } else {
            l7 = false;
        }
        if (!(l7)) {
            l8 = ((vader_struct_vader_midir$TermReturn_t*) l2)->f_span;
            vader_emit_bytecode$emit_get(l0, l6, l8);
        }
        l9 = ((vader_struct_vader_midir$TermReturn_t*) l2)->f_span;
        vader_emit_bytecode$emit_return_retag(l0, l6, l4, l9);
        l4 = (l4 + INT64_C(1));
    }
    l8 = ((vader_struct_vader_core_bytecode$BcFunction_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_slot)->f_body;
    t0 = vader_array_length(((vader_array_t*) l8));
    if ((t0 > INT64_C(0))) {
        if (!(l3.tag == 0u)) {
            t0 = vader_array_length(((vader_array_t*) l8));
            l4 = vader_chk_sub(i64, t0, INT64_C(1));
            vader_array_t* _a1_slotarr = ((vader_array_t*) l8);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            t1 = vader_array_ref_load_box(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l4);
            l3 = vader_core_bytecode$const_op_of(t1);
            if (!(l3.tag == 0u)) {
                t0 = vader_array_length(((vader_array_t*) l8));
                l4 = vader_chk_sub(i64, t0, INT64_C(1));
                vader_struct_vader_core_bytecode$ReturnLit_t* _a2_obj = (vader_struct_vader_core_bytecode$ReturnLit_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$ReturnLit_t));
                vader_obj_header_init(_a2_obj, 1308u);
                _a2_obj->f_value = l3;
                l9 = (void*) _a2_obj;
                vader_array_t* _a3_slotarr = ((vader_array_t*) l8);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                vader_array_ref_store(_a3_slotarr->buf, vader_array_offset(_a3_slotarr) + (size_t) l4, l9);
                VADER_WRITE_BARRIER(_a3_slotarr->buf);
                { vader_gc_top = gc_frame.prev; return; }
            }
        }
    }
    t2 = (void*) &vader_data_92;
    vader_array_t* _a4_slotarr = ((vader_array_t*) t2);
    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
    l8 = vader_array_ref_load_obj(_a4_slotarr->buf, vader_array_offset(_a4_slotarr) + (size_t) INT64_C(0));
    l9 = ((vader_struct_vader_midir$TermReturn_t*) l2)->f_span;
    vader_emit_bytecode$push_emit(l0, vader_ref_box(l8), l9);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_bytecode$emit_return_retag(void* l0, int32_t l1, int64_t l2, void* l3) {
    bool l4;
    int64_t t0;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[2] = { &l0, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_array_length(((vader_array_t*) ((vader_struct_vader_midir$CFGFunction_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_fn_)->f_scalarised_results));
    if ((t0 > l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_midir$CFGFunction_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_fn_)->f_scalarised_results);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
        t1 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l2);
        l4 = vader_midir_select$is_boxed_slot(t1);
        vader_emit_bytecode$emit_retag_into(l0, l1, l4, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    l4 = vader_midir_select$is_boxed_slot(((vader_struct_vader_midir$CFGFunction_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_fn_)->f_return_type);
    vader_emit_bytecode$emit_retag_into(l0, l1, l4, l3);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_bytecode$emit_set(void* l0, int32_t l1, void* l2) {
    void* l3 = NULL;
    int64_t l4;
    int32_t t0;
    void** gc_raw_roots[3] = { &l0, &l2, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_local_to_slot;
    l4 = ((int64_t) (int32_t) l1);
    vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
    t0 = ((int32_t*) _a0_slotarr->buf->slots)[vader_array_offset(_a0_slotarr) + (size_t) l4];
    vader_struct_vader_core_bytecode$LocalSet_t* _a1_obj = (vader_struct_vader_core_bytecode$LocalSet_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$LocalSet_t));
    vader_obj_header_init(_a1_obj, 1296u);
    _a1_obj->f_slot = t0;
    l3 = (void*) _a1_obj;
    vader_emit_bytecode$push_emit(l0, vader_ref_box(l3), l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_bytecode$emit_subtree(void* l0, void* l1, int32_t l2, int32_t l3) {
    void* l4 = NULL;
    int32_t l5;
    bool t0, t1;
    void** gc_raw_roots[3] = { &l0, &l1, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l4 = ((vader_struct_vader_emit_bytecode$StructureShape_t*) l1)->f_loop_header;
    l5 = l2;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
    t0 = ((uint8_t*) _a0_slotarr->buf->slots)[vader_array_offset(_a0_slotarr) + (size_t) l5];
    t1 = t0;
    if (t1) {
        vader_emit_bytecode$emit_loop(l0, l1, l2, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_emit_bytecode$emit_body(l0, l1, l2, l3, INT32_C(-1));
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_bytecode$emit_terminator(void* l0, void* l1, int32_t l2, int32_t l3, int32_t l4) {
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
    l5 = ((vader_struct_vader_midir$CFGFunction_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_fn_)->f_blocks;
    l6 = l2;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l6)
    t0 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l6);
    l7 = ((vader_struct_vader_midir$BasicBlock_t*) t0)->f_terminator;
    if (l7.tag == 1878u) {
        l5 = l7.payload.obj;
        vader_emit_bytecode$emit_return(l0, l2, l5);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l7.tag == 1879u) {
        t0 = l7.payload.obj;
        t1 = ((vader_struct_vader_midir$TermUnreachable_t*) t0)->f_reason;
        vader_struct_vader_core_bytecode$Unreachable_t* _a1_obj = (vader_struct_vader_core_bytecode$Unreachable_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$Unreachable_t));
        vader_obj_header_init(_a1_obj, 1340u);
        _a1_obj->f_reason = t1;
        l5 = (void*) _a1_obj;
        t0 = l7.payload.obj;
        l8 = ((vader_struct_vader_midir$TermUnreachable_t*) t0)->f_span;
        vader_emit_bytecode$push_emit(l0, vader_ref_box(l5), l8);
    } else if (l7.tag == 1876u) {
        t0 = l7.payload.obj;
        l6 = ((vader_struct_vader_midir$TermBranch_t*) t0)->f_target;
        t0 = l7.payload.obj;
        l5 = ((vader_struct_vader_midir$TermBranch_t*) t0)->f_span;
        vader_emit_bytecode$emit_branch(l0, l1, l2, l6, l3, l5);
    } else {
        if (!(l7.tag == 1877u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l5 = l7.payload.obj;
        vader_emit_bytecode$emit_cond_branch(l0, l1, l2, l5, l3, l4);
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static bool vader_emit_bytecode$emitted_beneath(void* l0, void* l1, void* l2, void* l3, int32_t l4) {
    void* l5;
    int64_t l6, l7;
    int32_t l8, l9, l10, l11, l12, l13;
    int32_t t0;
    bool t1;
    l5 = l0;
    l6 = vader_array_length(((vader_array_t*) l5));
    l7 = INT64_C(0);
    while ((l7 < l6)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l8 = ((int32_t*) _a0_slotarr->buf->slots)[vader_array_offset(_a0_slotarr) + (size_t) l7];
        l9 = l8;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l9)
        t0 = ((int32_t*) _a1_slotarr->buf->slots)[vader_array_offset(_a1_slotarr) + (size_t) l9];
        if ((t0 < INT32_C(0))) {
            l7 = (l7 + INT64_C(1));
            continue;
        }
        l10 = l8;
        while (l10 != l4) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l10)
            l11 = ((int32_t*) _a2_slotarr->buf->slots)[vader_array_offset(_a2_slotarr) + (size_t) l10];
            if ((l11 >= INT32_C(0))) {
                l12 = l11;
                l13 = l4;
                t1 = vader_midir$dominates(l2, l12, l13);
                if (t1) {
                    return false;
                }
            }
            vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l10)
            l10 = ((int32_t*) _a3_slotarr->buf->slots)[vader_array_offset(_a3_slotarr) + (size_t) l10];
        }
        l7 = (l7 + INT64_C(1));
    }
    return true;
}

static bool vader_emit_bytecode$ends_function(vader_box_t l0) {
    return (l0.tag == 1878u || l0.tag == 1879u);
}

static bool vader_emit_bytecode$entered_by_test(void* l0, void* l1, int32_t l2) {
    void* l3;
    int64_t l4, l5;
    int32_t l6;
    bool t0;
    l3 = l1;
    l4 = vader_array_length(((vader_array_t*) l3));
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l6 = ((int32_t*) _a0_slotarr->buf->slots)[vader_array_offset(_a0_slotarr) + (size_t) l5];
        t0 = vader_emit_bytecode$leaves_header(l0, l6, l2);
        if (t0) {
            return true;
        }
        l5 = (l5 + INT64_C(1));
    }
    return false;
}

static void* vader_emit_bytecode$every_operand_boxed(void* l0) {
    void* l1 = NULL;
    int64_t l2;
    void* t0 = NULL;
    void** gc_raw_roots[3] = { &l0, &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(24u, 1u, 12u, 575u);
    ((uint8_t*) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = (uint8_t) true;
    l1 = (void*) _a0_arr;
    l2 = vader_array_length(((vader_array_t*) l0));
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l1, (int64_t) l2);
    t0 = (void*) _a1_arr;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_emit_bytecode$extend_into_loops(void* l0, void* l1, int64_t l2, void* l3) {
    bool l4;
    int64_t l5, l8, l9;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l10 = NULL;
    int32_t l11, l12, l13, l14, l15, l16, l17, l18, l19, l20, l21, l22;
    bool t0, t1;
    void** gc_raw_roots[6] = { &l0, &l1, &l3, &l6, &l7, &l10 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 6u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l4 = false;
    l5 = INT64_C(0);
    while ((l5 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
        t0 = ((uint8_t*) _a0_slotarr->buf->slots)[vader_array_offset(_a0_slotarr) + (size_t) l5];
        t1 = t0;
        if (t1) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
            l6 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l5);
            l7 = l3;
            l8 = vader_array_length(((vader_array_t*) l7));
            l9 = INT64_C(0);
            while ((l9 < l8)) {
                vader_array_t* _a2_slotarr = ((vader_array_t*) l7);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                l10 = vader_array_ref_load_obj(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l9);
                l11 = ((vader_struct_vader_emit_bytecode$SlotRange_t*) l6)->f_first;
                l12 = ((vader_struct_vader_emit_bytecode$SlotRange_t*) l10)->f_last;
                if ((l11 <= l12)) {
                    l13 = ((vader_struct_vader_emit_bytecode$SlotRange_t*) l6)->f_last;
                    l14 = ((vader_struct_vader_emit_bytecode$SlotRange_t*) l10)->f_first;
                    if ((l13 >= l14)) {
                        l15 = ((vader_struct_vader_emit_bytecode$SlotRange_t*) l6)->f_first;
                        l16 = ((vader_struct_vader_emit_bytecode$SlotRange_t*) l10)->f_first;
                        if ((l15 > l16)) {
                            l17 = ((vader_struct_vader_emit_bytecode$SlotRange_t*) l10)->f_first;
                            l18 = ((vader_struct_vader_emit_bytecode$SlotRange_t*) l6)->f_last;
                            vader_struct_vader_emit_bytecode$SlotRange_t* _a3_obj = (vader_struct_vader_emit_bytecode$SlotRange_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_bytecode$SlotRange_t));
                            vader_obj_header_init(_a3_obj, 1389u);
                            _a3_obj->f_first = l17;
                            _a3_obj->f_last = l18;
                            l6 = (void*) _a3_obj;
                            l4 = true;
                        }
                        l19 = ((vader_struct_vader_emit_bytecode$SlotRange_t*) l6)->f_last;
                        l20 = ((vader_struct_vader_emit_bytecode$SlotRange_t*) l10)->f_last;
                        if ((l19 < l20)) {
                            l21 = ((vader_struct_vader_emit_bytecode$SlotRange_t*) l6)->f_first;
                            l22 = ((vader_struct_vader_emit_bytecode$SlotRange_t*) l10)->f_last;
                            vader_struct_vader_emit_bytecode$SlotRange_t* _a4_obj = (vader_struct_vader_emit_bytecode$SlotRange_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_bytecode$SlotRange_t));
                            vader_obj_header_init(_a4_obj, 1389u);
                            _a4_obj->f_first = l21;
                            _a4_obj->f_last = l22;
                            l6 = (void*) _a4_obj;
                            l4 = true;
                        }
                    }
                }
                l9 = (l9 + INT64_C(1));
            }
            vader_array_t* _a5_slotarr = ((vader_array_t*) l0);
            VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l5)
            vader_array_ref_store(_a5_slotarr->buf, vader_array_offset(_a5_slotarr) + (size_t) l5, l6);
            VADER_WRITE_BARRIER(_a5_slotarr->buf);
        }
        l5 = (l5 + INT64_C(1));
    }
    { bool __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_emit_bytecode$find_loop_ranges(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l13 = NULL;
    int64_t l4, l5, l6;
    vader_box_t l7 = vader_box_null();
    int32_t l8, l9, l10, l11, l12;
    vader_box_t t0 = vader_box_null();
    vader_string_t t1 = 0;
    vader_box_t* gc_roots[2] = { &l7, &t0 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &l13 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(234u, 0u, 13u, 1389u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(26u, 0u, 0u, 577u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(27u, 0u, 7u, 580u);
    l3 = (void*) _a2_arr;
    l4 = INT64_C(0);
    l5 = vader_array_length(((vader_array_t*) l0));
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        l7 = vader_array_ref_load_box(_a3_slotarr->buf, vader_array_offset(_a3_slotarr) + (size_t) l6);
        if (l7.tag == 1199u) {
            l8 = ((int32_t) (int64_t) l6);
            vader_emit_bytecode$push_scope(l2, l3, l4, 2007u, l8);
            l4 = vader_chk_add(i64, l4, INT64_C(1));
        } else if (l7.tag == 1298u) {
            l9 = ((int32_t) (int64_t) l6);
            vader_emit_bytecode$push_scope(l2, l3, l4, 2748u, l9);
            l4 = vader_chk_add(i64, l4, INT64_C(1));
        } else if (l7.tag == 1285u) {
            l10 = ((int32_t) (int64_t) l6);
            vader_emit_bytecode$push_scope(l2, l3, l4, 2584u, l10);
            l4 = vader_chk_add(i64, l4, INT64_C(1));
        } else if (l7.tag == 1226u) {
            if ((l4 > INT64_C(0))) {
                l4 = vader_chk_sub(i64, l4, INT64_C(1));
                vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
                VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l4)
                t0 = vader_array_box_slots(_a4_slotarr->buf)[vader_array_offset(_a4_slotarr) + (size_t) l4];
                t1 = t0.payload.s;
                if (t1 == 2748u) {
                    vader_array_t* _a5_slotarr = ((vader_array_t*) l3);
                    VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l4)
                    l11 = ((int32_t*) _a5_slotarr->buf->slots)[vader_array_offset(_a5_slotarr) + (size_t) l4];
                    l12 = ((int32_t) (int64_t) l6);
                    vader_struct_vader_emit_bytecode$SlotRange_t* _a6_obj = (vader_struct_vader_emit_bytecode$SlotRange_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_bytecode$SlotRange_t));
                    vader_obj_header_init(_a6_obj, 1389u);
                    _a6_obj->f_first = l11;
                    _a6_obj->f_last = l12;
                    l13 = (void*) _a6_obj;
                    vader_array_push_ref((vader_array_t*) l1, l13);
                }
            }
        }
        l6 = (l6 + INT64_C(1));
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_emit_bytecode$find_struct_field_index(void* l0, int32_t l1, vader_string_t l2) {
    vader_box_t l3;
    int64_t l4, l5;
    void* t0;
    vader_string_t t1;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_types);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    l3 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l1);
    if (l3.tag == 1191u) {
        l4 = INT64_C(0);
        t0 = l3.payload.obj;
        l5 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcStruct_t*) t0)->f_fields));
        while ((l4 < l5)) {
            t0 = l3.payload.obj;
            vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcStruct_t*) t0)->f_fields);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
            t0 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l4);
            t1 = ((vader_struct_vader_core_bytecode$BcField_t*) t0)->f_name;
            if (t1 == l2) {
                return vader_box_i64(581u, l4);
            }
            l4 = (l4 + INT64_C(1));
        }
    }
    return vader_box_obj(0u, NULL);
}

static vader_box_t vader_emit_bytecode$first_stack_operand(vader_box_t l0) {
    vader_box_t l1;
    void* t0;
    vader_box_t t1;
    int32_t t2;
    if (l0.tag == 1847u) {
        return vader_box_obj(0u, NULL);
    }
    if (l0.tag == 1854u) {
        return vader_box_obj(0u, NULL);
    }
    if (l0.tag == 1853u) {
        return vader_box_obj(0u, NULL);
    }
    if (l0.tag == 1848u) {
        return vader_box_obj(0u, NULL);
    }
    if (l0.tag == 1855u) {
        return vader_box_obj(0u, NULL);
    }
    if (l0.tag == 1862u) {
        return vader_box_obj(0u, NULL);
    }
    if (l0.tag == 1859u) {
        t0 = l0.payload.obj;
        return vader_box_i32(580u, ((vader_struct_vader_midir$InstrMove_t*) t0)->f_src);
    }
    if (l0.tag == 1840u) {
        t0 = l0.payload.obj;
        return vader_box_i32(580u, ((vader_struct_vader_midir$InstrBinOp_t*) t0)->f_lhs);
    }
    if (l0.tag == 1863u) {
        t0 = l0.payload.obj;
        return vader_box_i32(580u, ((vader_struct_vader_midir$InstrUnOp_t*) t0)->f_operand);
    }
    if (l0.tag == 1841u) {
        t0 = l0.payload.obj;
        t1 = std_core$first__vader_midir$LocalId(((vader_struct_vader_midir$InstrCall_t*) t0)->f_args);
        return t1;
    }
    if (l0.tag == 1842u) {
        t0 = l0.payload.obj;
        l1 = std_core$first__vader_midir$LocalId(((vader_struct_vader_midir$InstrCallIndirect_t*) t0)->f_args);
        if (l1.tag == 0u) {
            t0 = l0.payload.obj;
            return vader_box_i32(580u, ((vader_struct_vader_midir$InstrCallIndirect_t*) t0)->f_callee);
        }
        t2 = ((int32_t) l1.payload.i);
        return vader_box_i32(580u, t2);
    }
    if (l0.tag == 1866u) {
        t0 = l0.payload.obj;
        l1 = std_core$first__vader_midir$LocalId(((vader_struct_vader_midir$InstrVirtualCall_t*) t0)->f_args);
        if (l1.tag == 0u) {
            t0 = l0.payload.obj;
            return vader_box_i32(580u, ((vader_struct_vader_midir$InstrVirtualCall_t*) t0)->f_receiver);
        }
        t2 = ((int32_t) l1.payload.i);
        return vader_box_i32(580u, t2);
    }
    if (l0.tag == 1851u) {
        t0 = l0.payload.obj;
        return vader_box_i32(580u, ((vader_struct_vader_midir$InstrFieldGet_t*) t0)->f_target);
    }
    if (l0.tag == 1852u) {
        t0 = l0.payload.obj;
        return vader_box_i32(580u, ((vader_struct_vader_midir$InstrFieldSet_t*) t0)->f_target);
    }
    if (l0.tag == 1864u) {
        t0 = l0.payload.obj;
        return vader_box_i32(580u, ((vader_struct_vader_midir$InstrUnionFieldGet_t*) t0)->f_target);
    }
    if (l0.tag == 1865u) {
        t0 = l0.payload.obj;
        return vader_box_i32(580u, ((vader_struct_vader_midir$InstrUnionFieldSet_t*) t0)->f_target);
    }
    if (l0.tag == 1834u) {
        t0 = l0.payload.obj;
        return vader_box_i32(580u, ((vader_struct_vader_midir$InstrArrayGet_t*) t0)->f_target);
    }
    if (l0.tag == 1838u) {
        t0 = l0.payload.obj;
        return vader_box_i32(580u, ((vader_struct_vader_midir$InstrArraySet_t*) t0)->f_target);
    }
    if (l0.tag == 1835u) {
        t0 = l0.payload.obj;
        return vader_box_i32(580u, ((vader_struct_vader_midir$InstrArrayLen_t*) t0)->f_target);
    }
    if (l0.tag == 1837u) {
        t0 = l0.payload.obj;
        return vader_box_i32(580u, ((vader_struct_vader_midir$InstrArrayPush_t*) t0)->f_target);
    }
    if (l0.tag == 1839u) {
        t0 = l0.payload.obj;
        return vader_box_i32(580u, ((vader_struct_vader_midir$InstrArraySlice_t*) t0)->f_target);
    }
    if (l0.tag == 1860u) {
        t0 = l0.payload.obj;
        t1 = std_core$first__vader_midir$LocalId(((vader_struct_vader_midir$InstrStructNew_t*) t0)->f_fields);
        return t1;
    }
    if (l0.tag == 1836u) {
        t0 = l0.payload.obj;
        t1 = std_core$first__vader_midir$LocalId(((vader_struct_vader_midir$InstrArrayNew_t*) t0)->f_elements);
        return t1;
    }
    if (l0.tag == 1861u) {
        t0 = l0.payload.obj;
        return vader_box_i32(580u, ((vader_struct_vader_midir$InstrTypeCheck_t*) t0)->f_value);
    }
    if (l0.tag == 1843u) {
        t0 = l0.payload.obj;
        return vader_box_i32(580u, ((vader_struct_vader_midir$InstrCast_t*) t0)->f_value);
    }
    if (l0.tag == 1845u) {
        t0 = l0.payload.obj;
        return vader_box_i32(580u, ((vader_struct_vader_midir$InstrCellNew_t*) t0)->f_value);
    }
    if (l0.tag == 1844u) {
        t0 = l0.payload.obj;
        return vader_box_i32(580u, ((vader_struct_vader_midir$InstrCellGet_t*) t0)->f_cell);
    }
    if (l0.tag == 1846u) {
        t0 = l0.payload.obj;
        return vader_box_i32(580u, ((vader_struct_vader_midir$InstrCellSet_t*) t0)->f_cell);
    }
    if (l0.tag == 1856u) {
        t0 = l0.payload.obj;
        return vader_box_i32(580u, ((vader_struct_vader_midir$InstrGlobalSet_t*) t0)->f_value);
    }
    if (l0.tag == 1858u) {
        t0 = l0.payload.obj;
        return vader_box_i32(580u, ((vader_struct_vader_midir$InstrMakeClosure_t*) t0)->f_env);
    }
    if (l0.tag == 1857u) {
        t0 = l0.payload.obj;
        t1 = std_core$first__vader_midir$LocalId(((vader_struct_vader_midir$InstrIntrinsic_t*) t0)->f_args);
        return t1;
    }
    if (l0.tag == 1850u) {
        t0 = l0.payload.obj;
        return vader_box_i32(580u, ((vader_struct_vader_midir$InstrDeferPush_t*) t0)->f_value);
    }
    if (!(l0.tag == 1849u)) {
        vader_unreachable("non-exhaustive match (T3013 should have caught this)");
    }
    return vader_box_obj(0u, NULL);
}

static vader_box_t vader_emit_bytecode$first_terminator_operand(vader_box_t l0) {
    void* t0;
    vader_box_t t1;
    if (l0.tag == 1876u) {
        return vader_box_obj(0u, NULL);
    }
    if (l0.tag == 1879u) {
        return vader_box_obj(0u, NULL);
    }
    if (l0.tag == 1877u) {
        t0 = l0.payload.obj;
        return vader_box_i32(580u, ((vader_struct_vader_midir$TermCondBranch_t*) t0)->f_cond);
    }
    if (!(l0.tag == 1878u)) {
        vader_unreachable("non-exhaustive match (T3013 should have caught this)");
    }
    t0 = l0.payload.obj;
    t1 = vader_midir$term_return_single(t0);
    return t1;
}

static bool vader_emit_bytecode$fits_in(uint8_t l0, uint8_t l1) {
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

static bool vader_emit_bytecode$foldable_self_copy(void* l0, int64_t l1, int64_t l2, void* l3) {
    int64_t l4;
    vader_box_t l5, l6;
    int32_t l7, l8;
    int64_t t0;
    bool t1, t2;
    void* t3;
    t0 = vader_chk_add(i64, l1, INT64_C(1));
    if ((t0 >= l2)) {
        return false;
    }
    l4 = vader_chk_add(i64, l1, INT64_C(1));
    vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
    t1 = ((uint8_t*) _a0_slotarr->buf->slots)[vader_array_offset(_a0_slotarr) + (size_t) l4];
    t2 = t1;
    if (t2) {
        return false;
    }
    vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l1)
    l5 = vader_array_ref_load_box(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l1);
    if (l5.tag == 1295u) {
        l4 = vader_chk_add(i64, l1, INT64_C(1));
        vader_array_t* _a2_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        l6 = vader_array_ref_load_box(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l4);
        if (l6.tag == 1297u) {
            t3 = l6.payload.obj;
            l7 = ((vader_struct_vader_core_bytecode$LocalTee_t*) t3)->f_slot;
            t3 = l5.payload.obj;
            l8 = ((vader_struct_vader_core_bytecode$LocalGet_t*) t3)->f_slot;
            return l7 == l8;
        }
        if (l6.tag == 1296u) {
            t3 = l6.payload.obj;
            l7 = ((vader_struct_vader_core_bytecode$LocalSet_t*) t3)->f_slot;
            t3 = l5.payload.obj;
            l8 = ((vader_struct_vader_core_bytecode$LocalGet_t*) t3)->f_slot;
            return l7 == l8;
        }
        return false;
    }
    return false;
}

static bool vader_emit_bytecode$goes_on_or_out(void* l0, void* l1, void* l2, int32_t l3) {
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
    l7 = ((vader_struct_std_collections$Map__i32__std_collections_Set_i32__t*) l6)->f_ekeys;
    l8 = ((vader_struct_std_collections$Map__i32__std_collections_Set_i32__t*) l6)->f_evals;
    l9 = INT64_C(0);
    l10 = ((vader_struct_std_collections$Map__i32__std_collections_Set_i32__t*) l6)->f_size;
    while ((l9 < l10)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l9)
        l11 = ((int32_t*) _a0_slotarr->buf->slots)[vader_array_offset(_a0_slotarr) + (size_t) l9];
        vader_array_t* _a1_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l9)
        l6 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l9);
        l12 = l11;
        l13 = l6;
        t0 = vader_emit_bytecode$holds_all(l13, l2);
        if (t0) {
            if ((l4 < INT32_C(0))) {
                l15 = true;
            } else {
                t1 = std_collections$len__i32(l13);
                l15 = (t1 < l5);
            }
            l14 = l15;
        } else {
            l14 = false;
        }
        if (l14) {
            l4 = l12;
            l5 = std_collections$len__i32(l13);
        }
        l9 = (l9 + INT64_C(1));
    }
    l16 = std_collections$Map$std_core$Index$at__i32__Any(l1, l4);
    if (l16.tag == 0u) {
        return false;
    }
    l6 = l16.payload.obj;
    t0 = vader_midir$BlockId$std_core$Equals$equals(l3, l4);
    if (t0) {
        return true;
    }
    l7 = ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_blocks;
    vader_array_t* _a2_slotarr = ((vader_array_t*) l7);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
    t2 = vader_array_ref_load_obj(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l4);
    l16 = ((vader_struct_vader_midir$BasicBlock_t*) t2)->f_terminator;
    if (l16.tag == 1877u) {
        t2 = l16.payload.obj;
        t0 = vader_midir$BlockId$std_core$Equals$equals(((vader_struct_vader_midir$TermCondBranch_t*) t2)->f_then_block, l3);
        if (t0) {
            l15 = true;
        } else {
            t2 = l16.payload.obj;
            l15 = vader_midir$BlockId$std_core$Equals$equals(((vader_struct_vader_midir$TermCondBranch_t*) t2)->f_else_block, l3);
        }
        l14 = l15;
    } else {
        l14 = false;
    }
    if (l14) {
        t0 = std_collections$Set$std_core$Contains$contains__i32(l6, l3);
        return !(t0);
    }
    return false;
}

static bool vader_emit_bytecode$has_receiver(void* l0, int32_t l1) {
    void* l2;
    int64_t l3, l4;
    void* t0;
    int32_t t1;
    l2 = ((vader_struct_vader_core_bytecode$VtableRow_t*) l0)->f_entries;
    l3 = vader_array_length(((vader_array_t*) l2));
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l4);
        t1 = ((vader_struct_vader_core_bytecode$VtableEntry_t*) t0)->f_receiver_type_index;
        if (t1 == l1) {
            return true;
        }
        l4 = (l4 + INT64_C(1));
    }
    return false;
}

static bool vader_emit_bytecode$holds_all(void* l0, void* l1) {
    void* l2;
    int64_t l3, l4;
    int32_t l5;
    bool t0;
    l2 = l1;
    l3 = vader_array_length(((vader_array_t*) l2));
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l5 = ((int32_t*) _a0_slotarr->buf->slots)[vader_array_offset(_a0_slotarr) + (size_t) l4];
        t0 = std_collections$Set$std_core$Contains$contains__i32(l0, l5);
        if (!(t0)) {
            return false;
        }
        l4 = (l4 + INT64_C(1));
    }
    return true;
}

static void* vader_emit_bytecode$import_call_target(void* l0, int32_t l1) {
    void* l2 = NULL;
    void* l5 = NULL;
    vader_box_t l3 = vader_box_null(), l4 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[2] = { &l3, &l4 };
    void** gc_raw_roots[4] = { &l0, &l2, &l5, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_imports);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    l2 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l1);
    l3 = vader_midir_select$member_op(((vader_struct_vader_core_bytecode$BcImport_t*) l2)->f_intrinsic);
    if (l3.tag == 0u) {
        vader_struct_vader_core_bytecode$CallImport_t* _a1_obj = (vader_struct_vader_core_bytecode$CallImport_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$CallImport_t));
        vader_obj_header_init(_a1_obj, 1214u);
        _a1_obj->f_index = l1;
        t0 = (void*) _a1_obj;
        l4 = vader_ref_box(t0);
        l5 = ((vader_struct_vader_core_bytecode$BcImport_t*) l2)->f_signature;
        vader_struct_vader_emit_bytecode$DirectCallTarget_t* _a2_obj = (vader_struct_vader_emit_bytecode$DirectCallTarget_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_bytecode$DirectCallTarget_t));
        vader_obj_header_init(_a2_obj, 1379u);
        _a2_obj->f_op = l4;
        _a2_obj->f_signature = l5;
        t0 = (void*) _a2_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = l3;
    l5 = ((vader_struct_vader_core_bytecode$BcImport_t*) l2)->f_signature;
    vader_struct_vader_emit_bytecode$DirectCallTarget_t* _a3_obj = (vader_struct_vader_emit_bytecode$DirectCallTarget_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_bytecode$DirectCallTarget_t));
    vader_obj_header_init(_a3_obj, 1379u);
    _a3_obj->f_op = l4;
    _a3_obj->f_signature = l5;
    t0 = (void*) _a3_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static int32_t vader_emit_bytecode$intern_cell_type(vader_box_t l0, void* l1) {
    int32_t l2, l5, l6;
    vader_string_t l3 = 0;
    vader_string_t l4 = 0;
    void* l7 = NULL;
    void* l8 = NULL;
    int64_t t0;
    vader_string_t t1 = 0;
    vader_string_t t2 = 0;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[3] = { &l1, &l7, &l8 };
    vader_string_t* gc_atom_roots[4] = { &l3, &l4, &t1, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_emit_bytecode$intern_type(l0, l1);
    l3 = vader_midir_select$type_intern_key(l0);
    l4 = concat_3(317u, l3, 606u);
    t0 = vader_array_length(((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l1)->f_types));
    l5 = ((int32_t) (int64_t) t0);
    l6 = std_collections$get_or_put__string__i32(((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l1)->f_type_key, l4, l5);
    if (!(l6 != l5)) {
        vader_struct_vader_core_bytecode$BcField_t* _a0_obj = (vader_struct_vader_core_bytecode$BcField_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcField_t));
        vader_obj_header_init(_a0_obj, 1180u);
        _a0_obj->f_name = 3521u;
        _a0_obj->f_type_index = l2;
        l7 = (void*) _a0_obj;
        vader_array_t* _a1_arr = vader_array_new(102u, 0u, 13u, 1180u);
        l8 = (void*) _a1_arr;
        vader_array_push_ref((vader_array_t*) l8, l7);
        l7 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l1)->f_types;
        t1 = vader_midir_select$cell_shape_name(l3);
        t2 = vader_core_mangle$cell_struct_name(t1);
        vader_struct_vader_core_bytecode$BcStruct_t* _a2_obj = (vader_struct_vader_core_bytecode$BcStruct_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcStruct_t));
        vader_obj_header_init(_a2_obj, 1191u);
        _a2_obj->f_name = t2;
        _a2_obj->f_fields = l8;
        _a2_obj->f_c_name = 0u;
        _a2_obj->f_symbol_id = INT32_C(-1);
        _a2_obj->f_shared = false;
        l8 = (void*) _a2_obj;
        vader_array_push_ref((vader_array_t*) l7, l8);
        { int32_t __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { int32_t __vret = l6; vader_gc_top = gc_frame.prev; return __vret; }
}

static int32_t vader_emit_bytecode$intern_string(vader_string_t l0, void* l1) {
    int32_t l2, l3;
    int64_t t0;
    void** gc_raw_roots[1] = { &l1 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_array_length(((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l1)->f_strings));
    l2 = ((int32_t) (int64_t) t0);
    l3 = std_collections$get_or_put__string__i32(((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l1)->f_string_key, l0, l2);
    if (l3 == l2) {
        vader_array_push_scalar((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l1)->f_strings, vader_box_string(577u, l0));
        { int32_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { int32_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static int32_t vader_emit_bytecode$intern_type(vader_box_t l0, void* l1) {
    uint64_t l2;
    vader_box_t l3 = vader_box_null(), l9 = vader_box_null();
    int64_t l4, l6;
    bool l5;
    void* l7 = NULL;
    int32_t l8, l11;
    vader_string_t l10 = 0;
    int32_t t0;
    bool t1;
    int64_t t2;
    vader_string_t t3 = 0;
    void* t4 = NULL;
    vader_box_t* gc_roots[3] = { &l0, &l3, &l9 };
    void** gc_raw_roots[3] = { &l1, &l7, &t4 };
    vader_string_t* gc_atom_roots[2] = { &l10, &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_midir_select$type_intern_hash(l0);
    l3 = std_collections$Map$std_core$Index$at__u64__i32(((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l1)->f_type_hash, l2);
    if (l3.tag == 580u) {
        t0 = ((int32_t) l3.payload.i);
        l4 = ((int64_t) (int32_t) t0);
        if ((INT64_C(0) <= l4)) {
            l6 = vader_array_length(((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l1)->f_type_by_slot));
            l5 = (l4 < l6);
        } else {
            l5 = false;
        }
        if (l5) {
            l7 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l1)->f_type_by_slot;
            l8 = ((int32_t) l3.payload.i);
            vader_array_t* _a0_slotarr = ((vader_array_t*) l7);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l8)
            l9 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l8);
            t1 = vader_midir_select$same_intern_class(l0, l9);
            if (t1) {
                t0 = ((int32_t) l3.payload.i);
                { int32_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
            }
        }
    }
    l10 = vader_midir_select$type_intern_key(l0);
    t2 = vader_array_length(((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l1)->f_types));
    l8 = ((int32_t) (int64_t) t2);
    l11 = std_collections$get_or_put__string__i32(((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l1)->f_type_key, l10, l8);
    if (l11 != l8) {
        if (l3.tag == 0u) {
            std_collections$Map$std_core$IndexSet$set_at__u64__i32(((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l1)->f_type_hash, l2, l11);
            vader_emit_bytecode$record_slot_type(l1, l11, l0);
            { int32_t __vret = l11; vader_gc_top = gc_frame.prev; return __vret; }
        }
        { int32_t __vret = l11; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l1)->f_types_frozen;
    if (t1) {
        t3 = concat_3(2294u, l10, 1283u);
        vader_host_std_core$Intrinsic$panic(t3);
        vader_unreachable("a no-return call returned");
    } else {
        vader_struct_vader_core_bytecode$BcRef_t* _a1_obj = (vader_struct_vader_core_bytecode$BcRef_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcRef_t));
        vader_obj_header_init(_a1_obj, 1187u);
        _a1_obj->f_trait_name = 0u;
        t4 = (void*) _a1_obj;
        l9 = vader_ref_box(t4);
        vader_array_push_ref((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l1)->f_types, l9.payload.obj);
        if (l3.tag == 0u) {
            std_collections$Map$std_core$IndexSet$set_at__u64__i32(((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l1)->f_type_hash, l2, l8);
        }
        vader_emit_bytecode$record_slot_type(l1, l8, l0);
        l7 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l1)->f_types;
        l3 = vader_emit_bytecode$bc_type_of_with_ctx(l0, l1);
        vader_array_t* _a2_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l8)
        vader_array_ref_store(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l8, l3.payload.obj);
        VADER_WRITE_BARRIER(_a2_slotarr->buf);
        { int32_t __vret = l8; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_gc_top = gc_frame.prev;
}

bool vader_emit_bytecode$is_boxed_row(void* l0, int32_t l1) {
    vader_box_t t0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_types);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    t0 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l1);
    return (t0.tag == 1187u || t0.tag == 1192u);
}

static bool vader_emit_bytecode$is_union_slot(vader_box_t l0) {
    bool l1;
    void* t0;
    if (l0.tag == 1373u) {
        return true;
    }
    if (l0.tag == 1351u) {
        t0 = l0.payload.obj;
        l1 = vader_emit_bytecode$is_union_slot(((vader_struct_vader_core_types$DistinctType_t*) t0)->f_backing);
    } else {
        l1 = false;
    }
    return l1;
}

static int64_t vader_emit_bytecode$last_empty_stack_point(void* l0, int32_t l1) {
    void* l2;
    int32_t l3;
    int64_t l4, l5, l6;
    void* t0;
    bool t1;
    l2 = ((vader_struct_vader_midir$CFGFunction_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_fn_)->f_blocks;
    l3 = l1;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
    t0 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l3);
    l4 = vader_array_length(((vader_array_t*) ((vader_struct_vader_midir$BasicBlock_t*) t0)->f_instructions));
    while ((l4 > INT64_C(0))) {
        l2 = ((vader_struct_vader_emit_bytecode$ScheduleHints_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_hints)->f_skip_set;
        l5 = vader_chk_sub(i64, l4, INT64_C(1));
        l6 = vader_midir$pos_key(l1, l5);
        t1 = std_collections$Set$std_core$Contains$contains__i64(l2, l6);
        if (!(t1)) {
            break;
        }
        l4 = vader_chk_sub(i64, l4, INT64_C(1));
    }
    return l4;
}

static bool vader_emit_bytecode$last_op_exits(void* l0) {
    void* l1;
    int64_t l2;
    int64_t t0;
    vader_box_t t1;
    l1 = ((vader_struct_vader_core_bytecode$BcFunction_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_slot)->f_body;
    t0 = vader_array_length(((vader_array_t*) l1));
    if (!(t0 == INT64_C(0))) {
        t0 = vader_array_length(((vader_array_t*) l1));
        l2 = vader_chk_sub(i64, t0, INT64_C(1));
        vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
        t1 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l2);
        return (t1.tag == 1206u || t1.tag == 1307u || t1.tag == 1308u);
    }
    return false;
}

static bool vader_emit_bytecode$leaves_at_once(void* l0, void* l1, int32_t l2, int32_t l3) {
    bool l4;
    void* l5;
    int32_t l6;
    void* t0;
    bool t1, t2;
    l5 = ((vader_struct_vader_midir$CFGFunction_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_fn_)->f_blocks;
    l6 = l3;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l6)
    t0 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l6);
    t1 = vader_emit_bytecode$ends_function(((vader_struct_vader_midir$BasicBlock_t*) t0)->f_terminator);
    if (t1) {
        l5 = ((vader_struct_vader_emit_bytecode$StructureShape_t*) l1)->f_copied;
        l6 = l3;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l6)
        t1 = ((uint8_t*) _a1_slotarr->buf->slots)[vader_array_offset(_a1_slotarr) + (size_t) l6];
        t2 = t1;
        l4 = !(t2);
    } else {
        l4 = false;
    }
    if (l4) {
        return true;
    }
    t1 = vader_emit_bytecode$only_jumps(l1, l2, l3);
    return t1;
}

static bool vader_emit_bytecode$leaves_header(void* l0, int32_t l1, int32_t l2) {
    vader_box_t l3;
    void* t0;
    bool t1;
    l3 = std_collections$Map$std_core$Index$at__i32__Any(l0, l1);
    if (l3.tag == 0u) {
        return false;
    }
    t0 = l3.payload.obj;
    t1 = std_collections$Set$std_core$Contains$contains__i32(t0, l2);
    return !(t1);
}

static void vader_emit_bytecode$lend_written_mirrors(void* l0) {
    int64_t l1, l2, l5, l6;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l8 = NULL;
    bool l7, l10;
    int32_t l9;
    void* t0 = NULL;
    int64_t t1;
    bool t2;
    vader_box_t t3 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t3 };
    void** gc_raw_roots[5] = { &l0, &l3, &l4, &l8, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = INT64_C(0);
    l2 = vader_array_length(((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_imports));
    while ((l1 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_imports);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l1);
        l3 = ((vader_struct_vader_core_bytecode$BcImport_t*) t0)->f_signature;
        t1 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l3)->f_params));
        vader_array_t* _a1_arr = vader_array_reserve(24u, (int64_t) t1, 12u, 575u);
        l4 = (void*) _a1_arr;
        l5 = INT64_C(0);
        l6 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l3)->f_params));
        vader_array_t* _pc24_hdr = (vader_array_t*) l4;
        size_t _pc24_len = vader_array_length(_pc24_hdr);
        size_t _pc24_cap = vader_array_is_borrowed(_pc24_hdr) ? (size_t) 0 : vader_array_capacity(_pc24_hdr);
        void* _pc24_slots = _pc24_hdr->buf->slots;
        for (;;) {
            if ((l5 < l6)) {
                t2 = vader_core_bytecode$param_is_c_out(l3, l5);
                if (t2) {
                    l8 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_types;
                    vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l3)->f_param_types);
                    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l5)
                    l9 = ((int32_t*) _a2_slotarr->buf->slots)[vader_array_offset(_a2_slotarr) + (size_t) l5];
                    t3 = vader_core_bytecode$mirror_at(l8, l9);
                    l7 = !(t3.tag == 0u);
                } else {
                    l7 = false;
                }
                t2 = vader_core_bytecode$param_is_by_address(l3, l5);
                if (t2) {
                    l10 = true;
                } else {
                    l10 = l7;
                }
                if (VADER_LIKELY(_pc24_len < _pc24_cap)) {
                    ((uint8_t*) _pc24_slots)[_pc24_len] = (uint8_t) (l10);
                    _pc24_len += 1;
                } else {
                    vader_array_set_length(_pc24_hdr, _pc24_len);
                    if (_pc24_hdr->buf->length < _pc24_len) {
                        _pc24_hdr->buf->length = _pc24_len;
                    }
                    vader_array_push_bool((vader_array_t*) l4, l10);
                    _pc24_hdr = (vader_array_t*) l4;
                    _pc24_len = vader_array_length(_pc24_hdr);
                    _pc24_cap = vader_array_is_borrowed(_pc24_hdr) ? (size_t) 0 : vader_array_capacity(_pc24_hdr);
                    _pc24_slots = _pc24_hdr->buf->slots;
                }
                l5 = (l5 + INT64_C(1));
                continue;
            }
            vader_array_set_length(_pc24_hdr, _pc24_len);
            if (_pc24_hdr->buf->length < _pc24_len) {
                _pc24_hdr->buf->length = _pc24_len;
            }
            break;
        }
        t2 = std_core$$array$Contains$contains__bool(l4, true);
        if (t2) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_imports);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l1)
            t0 = vader_array_ref_load_obj(_a3_slotarr->buf, vader_array_offset(_a3_slotarr) + (size_t) l1);
            ((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcImport_t*) t0)->f_signature)->f_param_by_address = l4;
            VADER_WRITE_BARRIER((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcImport_t*) t0)->f_signature);
        }
        l1 = (l1 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static int32_t vader_emit_bytecode$loop_exit(void* l0, void* l1, int32_t l2) {
    void* l3 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    void* l13 = NULL;
    int32_t l4, l6, l11, l12, l14, l15;
    vader_box_t l5 = vader_box_null();
    int64_t l7, l8;
    void* t0 = NULL;
    bool t1, t2;
    vader_box_t* gc_roots[1] = { &l5 };
    void** gc_raw_roots[7] = { &l0, &l1, &l3, &l9, &l10, &l13, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 7u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_midir$CFGFunction_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_fn_)->f_blocks;
    l4 = l2;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
    t0 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l4);
    l5 = ((vader_struct_vader_midir$BasicBlock_t*) t0)->f_terminator;
    if (!(l5.tag == 1877u)) {
        { vader_gc_top = gc_frame.prev; return INT32_C(-1); }
    }
    t0 = l5.payload.obj;
    l4 = ((vader_struct_vader_midir$TermCondBranch_t*) t0)->f_else_block;
    t0 = l5.payload.obj;
    l6 = ((vader_struct_vader_midir$TermCondBranch_t*) t0)->f_then_block;
    vader_array_t* _a1_arr = vader_array_new(27u, 2u, 7u, 580u);
    ((int32_t*) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 1u] = (int32_t) l6;
    ((int32_t*) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 0u] = (int32_t) l4;
    l3 = (void*) _a1_arr;
    l7 = vader_array_length(((vader_array_t*) l3));
    l8 = INT64_C(0);
    while ((l8 < l7)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        l4 = ((int32_t*) _a2_slotarr->buf->slots)[vader_array_offset(_a2_slotarr) + (size_t) l8];
        l9 = ((vader_struct_vader_emit_bytecode$StructureShape_t*) l1)->f_merge;
        l6 = l4;
        vader_array_t* _a3_slotarr = ((vader_array_t*) l9);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l6)
        t1 = ((uint8_t*) _a3_slotarr->buf->slots)[vader_array_offset(_a3_slotarr) + (size_t) l6];
        t2 = t1;
        if (t2) {
            { int32_t __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l10 = ((vader_struct_vader_emit_bytecode$StructureShape_t*) l1)->f_rpo_index;
        l11 = l4;
        vader_array_t* _a4_slotarr = ((vader_array_t*) l10);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l11)
        l12 = ((int32_t*) _a4_slotarr->buf->slots)[vader_array_offset(_a4_slotarr) + (size_t) l11];
        l13 = ((vader_struct_vader_emit_bytecode$StructureShape_t*) l1)->f_rpo_index;
        l14 = l2;
        vader_array_t* _a5_slotarr = ((vader_array_t*) l13);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l14)
        l15 = ((int32_t*) _a5_slotarr->buf->slots)[vader_array_offset(_a5_slotarr) + (size_t) l14];
        if ((l12 < l15)) {
            { int32_t __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l8 = (l8 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return INT32_C(-1); }
}

static bool vader_emit_bytecode$needs_ref_cast(vader_box_t l0) {
    bool l1;
    void* t0;
    bool t1;
    if (l0.tag == 1362u) {
        return true;
    }
    if (l0.tag == 1361u) {
        t0 = l0.payload.obj;
        t1 = vader_core_types$is_void(vader_ref_box(t0));
        l1 = !(t1);
    } else {
        l1 = false;
    }
    return l1;
}

static void* vader_emit_bytecode$new_emitter_ctx(void) {
    void* l0 = NULL;
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    void* l15 = NULL;
    void* l16 = NULL;
    void* l17 = NULL;
    void* l18 = NULL;
    void* l19 = NULL;
    uint64_t l5;
    void* t0 = NULL;
    void** gc_raw_roots[20] = {
        &l0, &l1, &l2, &l3, &l4, &l6, &l7, &l8, &l9, &l10, &l11, &l12, &l13, &l14, &l15, &l16, &l17,
        &l18, &l19, &t0,
    };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 20u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(447u, 0u, 13u, 2319u);
    l0 = (void*) _a0_arr;
    vader_struct_vader_core_bytecode$BcScalar_t* _a1_obj = (vader_struct_vader_core_bytecode$BcScalar_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcScalar_t));
    vader_obj_header_init(_a1_obj, 1188u);
    _a1_obj->f_val = (uint8_t) 13;
    l1 = (void*) _a1_obj;
    vader_array_push_ref((vader_array_t*) l0, l1);
    vader_array_t* _a2_arr = vader_array_new(26u, 0u, 0u, 577u);
    l1 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(27u, 0u, 7u, 580u);
    l2 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_new(27u, 0u, 7u, 580u);
    l3 = (void*) _a4_arr;
    vader_struct_std_collections$Map__string__i32_t* _a5_obj = (vader_struct_std_collections$Map__string__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__i32_t));
    vader_obj_header_init(_a5_obj, 902u);
    _a5_obj->f_ekeys = l1;
    _a5_obj->f_evals = l2;
    _a5_obj->f_index = l3;
    _a5_obj->f_mask = INT64_C(0);
    _a5_obj->f_grow_at = INT64_C(0);
    _a5_obj->f_size = INT64_C(0);
    _a5_obj->f_tombs = INT64_C(0);
    l1 = (void*) _a5_obj;
    std_collections$Map$std_core$IndexSet$set_at__string__i32(l1, 2893u, INT32_C(0));
    vader_array_t* _a6_arr = vader_array_new(32u, 0u, 4u, 585u);
    l2 = (void*) _a6_arr;
    vader_array_t* _a7_arr = vader_array_new(27u, 0u, 7u, 580u);
    l3 = (void*) _a7_arr;
    vader_array_t* _a8_arr = vader_array_new(27u, 0u, 7u, 580u);
    l4 = (void*) _a8_arr;
    vader_struct_std_collections$Map__u64__i32_t* _a9_obj = (vader_struct_std_collections$Map__u64__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__u64__i32_t));
    vader_obj_header_init(_a9_obj, 966u);
    _a9_obj->f_ekeys = l2;
    _a9_obj->f_evals = l3;
    _a9_obj->f_index = l4;
    _a9_obj->f_mask = INT64_C(0);
    _a9_obj->f_grow_at = INT64_C(0);
    _a9_obj->f_size = INT64_C(0);
    _a9_obj->f_tombs = INT64_C(0);
    l2 = (void*) _a9_obj;
    t0 = (void*) &vader_data_40;
    vader_array_t* _a10_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
    t0 = vader_array_ref_load_obj(_a10_slotarr->buf, vader_array_offset(_a10_slotarr) + (size_t) INT64_C(0));
    l5 = vader_midir_select$type_intern_hash(vader_ref_box(t0));
    std_collections$Map$std_core$IndexSet$set_at__u64__i32(l2, l5, INT32_C(0));
    t0 = (void*) &vader_data_40;
    vader_array_t* _a11_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
    t0 = vader_array_ref_load_obj(_a11_slotarr->buf, vader_array_offset(_a11_slotarr) + (size_t) INT64_C(0));
    vader_array_t* _a12_arr = vader_array_new(450u, 1u, 13u, 2396u);
    ((void**) _a12_arr->buf->slots)[vader_array_offset(_a12_arr) + 0u] = t0;
    l3 = (void*) _a12_arr;
    vader_array_t* _a13_arr = vader_array_new(104u, 0u, 13u, 1183u);
    l4 = (void*) _a13_arr;
    vader_array_t* _a14_arr = vader_array_new(26u, 0u, 0u, 577u);
    l6 = (void*) _a14_arr;
    vader_array_t* _a15_arr = vader_array_new(26u, 0u, 0u, 577u);
    l7 = (void*) _a15_arr;
    vader_array_t* _a16_arr = vader_array_new(27u, 0u, 7u, 580u);
    l8 = (void*) _a16_arr;
    vader_struct_std_collections$Map__string__string_t* _a17_obj = (vader_struct_std_collections$Map__string__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__string_t));
    vader_obj_header_init(_a17_obj, 917u);
    _a17_obj->f_ekeys = l6;
    _a17_obj->f_evals = l7;
    _a17_obj->f_index = l8;
    _a17_obj->f_mask = INT64_C(0);
    _a17_obj->f_grow_at = INT64_C(0);
    _a17_obj->f_size = INT64_C(0);
    _a17_obj->f_tombs = INT64_C(0);
    l6 = (void*) _a17_obj;
    vader_array_t* _a18_arr = vader_array_new(26u, 0u, 0u, 577u);
    l7 = (void*) _a18_arr;
    vader_array_t* _a19_arr = vader_array_new(26u, 0u, 0u, 577u);
    l8 = (void*) _a19_arr;
    vader_array_t* _a20_arr = vader_array_new(27u, 0u, 7u, 580u);
    l9 = (void*) _a20_arr;
    vader_array_t* _a21_arr = vader_array_new(27u, 0u, 7u, 580u);
    l10 = (void*) _a21_arr;
    vader_struct_std_collections$Map__string__i32_t* _a22_obj = (vader_struct_std_collections$Map__string__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__i32_t));
    vader_obj_header_init(_a22_obj, 902u);
    _a22_obj->f_ekeys = l8;
    _a22_obj->f_evals = l9;
    _a22_obj->f_index = l10;
    _a22_obj->f_mask = INT64_C(0);
    _a22_obj->f_grow_at = INT64_C(0);
    _a22_obj->f_size = INT64_C(0);
    _a22_obj->f_tombs = INT64_C(0);
    l8 = (void*) _a22_obj;
    vader_array_t* _a23_arr = vader_array_new(103u, 0u, 13u, 1182u);
    l9 = (void*) _a23_arr;
    vader_array_t* _a24_arr = vader_array_new(27u, 0u, 7u, 580u);
    l10 = (void*) _a24_arr;
    vader_array_t* _a25_arr = vader_array_new(27u, 0u, 7u, 580u);
    l11 = (void*) _a25_arr;
    vader_array_t* _a26_arr = vader_array_new(27u, 0u, 7u, 580u);
    l12 = (void*) _a26_arr;
    vader_struct_std_collections$Map__i32__i32_t* _a27_obj = (vader_struct_std_collections$Map__i32__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__i32__i32_t));
    vader_obj_header_init(_a27_obj, 816u);
    _a27_obj->f_ekeys = l10;
    _a27_obj->f_evals = l11;
    _a27_obj->f_index = l12;
    _a27_obj->f_mask = INT64_C(0);
    _a27_obj->f_grow_at = INT64_C(0);
    _a27_obj->f_size = INT64_C(0);
    _a27_obj->f_tombs = INT64_C(0);
    l10 = (void*) _a27_obj;
    vader_array_t* _a28_arr = vader_array_new(26u, 0u, 0u, 577u);
    l11 = (void*) _a28_arr;
    vader_array_t* _a29_arr = vader_array_new(27u, 0u, 7u, 580u);
    l12 = (void*) _a29_arr;
    vader_array_t* _a30_arr = vader_array_new(27u, 0u, 7u, 580u);
    l13 = (void*) _a30_arr;
    vader_struct_std_collections$Map__string__i32_t* _a31_obj = (vader_struct_std_collections$Map__string__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__i32_t));
    vader_obj_header_init(_a31_obj, 902u);
    _a31_obj->f_ekeys = l11;
    _a31_obj->f_evals = l12;
    _a31_obj->f_index = l13;
    _a31_obj->f_mask = INT64_C(0);
    _a31_obj->f_grow_at = INT64_C(0);
    _a31_obj->f_size = INT64_C(0);
    _a31_obj->f_tombs = INT64_C(0);
    l11 = (void*) _a31_obj;
    vader_array_t* _a32_arr = vader_array_new(105u, 0u, 13u, 1184u);
    l12 = (void*) _a32_arr;
    vader_array_t* _a33_arr = vader_array_new(27u, 0u, 7u, 580u);
    l13 = (void*) _a33_arr;
    vader_array_t* _a34_arr = vader_array_new(27u, 0u, 7u, 580u);
    l14 = (void*) _a34_arr;
    vader_array_t* _a35_arr = vader_array_new(27u, 0u, 7u, 580u);
    l15 = (void*) _a35_arr;
    vader_struct_std_collections$Map__i32__i32_t* _a36_obj = (vader_struct_std_collections$Map__i32__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__i32__i32_t));
    vader_obj_header_init(_a36_obj, 816u);
    _a36_obj->f_ekeys = l13;
    _a36_obj->f_evals = l14;
    _a36_obj->f_index = l15;
    _a36_obj->f_mask = INT64_C(0);
    _a36_obj->f_grow_at = INT64_C(0);
    _a36_obj->f_size = INT64_C(0);
    _a36_obj->f_tombs = INT64_C(0);
    l13 = (void*) _a36_obj;
    vader_array_t* _a37_arr = vader_array_new(26u, 0u, 0u, 577u);
    l14 = (void*) _a37_arr;
    vader_array_t* _a38_arr = vader_array_new(27u, 0u, 7u, 580u);
    l15 = (void*) _a38_arr;
    vader_array_t* _a39_arr = vader_array_new(27u, 0u, 7u, 580u);
    l16 = (void*) _a39_arr;
    vader_struct_std_collections$Map__string__i32_t* _a40_obj = (vader_struct_std_collections$Map__string__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__i32_t));
    vader_obj_header_init(_a40_obj, 902u);
    _a40_obj->f_ekeys = l14;
    _a40_obj->f_evals = l15;
    _a40_obj->f_index = l16;
    _a40_obj->f_mask = INT64_C(0);
    _a40_obj->f_grow_at = INT64_C(0);
    _a40_obj->f_size = INT64_C(0);
    _a40_obj->f_tombs = INT64_C(0);
    l14 = (void*) _a40_obj;
    vader_array_t* _a41_arr = vader_array_new(101u, 0u, 13u, 1179u);
    l15 = (void*) _a41_arr;
    vader_array_t* _a42_arr = vader_array_new(27u, 0u, 7u, 580u);
    l16 = (void*) _a42_arr;
    vader_array_t* _a43_arr = vader_array_new(27u, 0u, 7u, 580u);
    l17 = (void*) _a43_arr;
    vader_array_t* _a44_arr = vader_array_new(33u, 0u, 0u, 588u);
    l18 = (void*) _a44_arr;
    vader_array_t* _a45_arr = vader_array_new(27u, 0u, 7u, 580u);
    l19 = (void*) _a45_arr;
    vader_struct_std_collections$Map__i32__Any___t* _a46_obj = (vader_struct_std_collections$Map__i32__Any___t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__i32__Any___t));
    vader_obj_header_init(_a46_obj, 813u);
    _a46_obj->f_ekeys = l17;
    _a46_obj->f_evals = l18;
    _a46_obj->f_index = l19;
    _a46_obj->f_mask = INT64_C(0);
    _a46_obj->f_grow_at = INT64_C(0);
    _a46_obj->f_size = INT64_C(0);
    _a46_obj->f_tombs = INT64_C(0);
    l17 = (void*) _a46_obj;
    vader_struct_vader_emit_bytecode$EmitterCtx_t* _a47_obj = (vader_struct_vader_emit_bytecode$EmitterCtx_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_bytecode$EmitterCtx_t));
    vader_obj_header_init(_a47_obj, 1381u);
    _a47_obj->f_globals = l4;
    _a47_obj->f_dispatched_instances = l6;
    _a47_obj->f_types = l0;
    _a47_obj->f_type_key = l1;
    _a47_obj->f_type_hash = l2;
    _a47_obj->f_type_by_slot = l3;
    _a47_obj->f_strings = l7;
    _a47_obj->f_string_key = l8;
    _a47_obj->f_functions = l9;
    _a47_obj->f_function_index_by_symbol_id = l10;
    _a47_obj->f_function_index_by_mangle = l11;
    _a47_obj->f_imports = l12;
    _a47_obj->f_import_index_by_symbol_id = l13;
    _a47_obj->f_import_index_by_mangle = l14;
    _a47_obj->f_exports = l15;
    _a47_obj->f_pinned_types = l16;
    _a47_obj->f_types_frozen = false;
    _a47_obj->f_pinned_types_by_fn = l17;
    t0 = (void*) _a47_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_emit_bytecode$no_common_field(void* l0, vader_string_t l1, vader_box_t l2) {
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
    l3 = vader_core_types$display_type(l2);
    l4 = ((vader_struct_vader_midir$CFGFunction_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_fn_)->f_mangled;
    t0 = concat_7(2285u, l1, 1501u, l3, 1384u, l4, 341u);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_emit_bytecode$only_jumps(void* l0, int32_t l1, int32_t l2) {
    void* l3;
    int32_t l4, l5;
    bool t0, t1;
    l3 = ((vader_struct_vader_emit_bytecode$StructureShape_t*) l0)->f_merge;
    l4 = l2;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
    t0 = ((uint8_t*) _a0_slotarr->buf->slots)[vader_array_offset(_a0_slotarr) + (size_t) l4];
    t1 = t0;
    if (t1) {
        return true;
    }
    l3 = ((vader_struct_vader_emit_bytecode$StructureShape_t*) l0)->f_rpo_index;
    l4 = l2;
    vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
    l4 = ((int32_t*) _a1_slotarr->buf->slots)[vader_array_offset(_a1_slotarr) + (size_t) l4];
    l3 = ((vader_struct_vader_emit_bytecode$StructureShape_t*) l0)->f_rpo_index;
    l5 = l1;
    vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l5)
    l5 = ((int32_t*) _a2_slotarr->buf->slots)[vader_array_offset(_a2_slotarr) + (size_t) l5];
    return (l4 <= l5);
}

static int32_t vader_emit_bytecode$open_blocks(void* l0, void* l1, int32_t l2) {
    int64_t l3, l4, l5;
    int32_t l6, l8;
    void* l7 = NULL;
    void* l9 = NULL;
    vader_box_t l10 = vader_box_null();
    int64_t t0, t1;
    void* t2 = NULL;
    int32_t t3;
    vader_box_t* gc_roots[1] = { &l10 };
    void** gc_raw_roots[5] = { &l0, &l1, &l7, &l9, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = INT64_C(0);
    l4 = vader_array_length(((vader_array_t*) l1));
    while ((l3 < l4)) {
        t0 = vader_array_length(((vader_array_t*) l1));
        t1 = vader_chk_sub(i64, t0, INT64_C(1));
        l5 = vader_chk_sub(i64, t1, l3);
        vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
        l6 = ((int32_t*) _a0_slotarr->buf->slots)[vader_array_offset(_a0_slotarr) + (size_t) l5];
        l7 = ((vader_struct_vader_midir$CFGFunction_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_fn_)->f_blocks;
        l8 = l6;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l8)
        t2 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l8);
        l9 = ((vader_struct_vader_midir$BasicBlock_t*) t2)->f_span;
        vader_emit_bytecode$cf_block(l0, l9, l6);
        l3 = (l3 + INT64_C(1));
    }
    l10 = std_core$first__vader_midir$BlockId(l1);
    if (l10.tag == 0u) {
        { int32_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t3 = ((int32_t) l10.payload.i);
    { int32_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
}

static int32_t vader_emit_bytecode$outermost_loop_left(void* l0, void* l1, int32_t l2, int32_t l3) {
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
    l6 = ((vader_struct_std_collections$Map__i32__std_collections_Set_i32__t*) l5)->f_ekeys;
    l7 = ((vader_struct_std_collections$Map__i32__std_collections_Set_i32__t*) l5)->f_evals;
    l8 = INT64_C(0);
    l9 = ((vader_struct_std_collections$Map__i32__std_collections_Set_i32__t*) l5)->f_size;
    while ((l8 < l9)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l8)
        l10 = ((int32_t*) _a0_slotarr->buf->slots)[vader_array_offset(_a0_slotarr) + (size_t) l8];
        vader_array_t* _a1_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l8)
        l5 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l8);
        l11 = l10;
        l12 = l5;
        t0 = std_collections$Set$std_core$Contains$contains__i32(l12, l2);
        if (t0) {
            t0 = std_collections$Set$std_core$Contains$contains__i32(l12, l3);
            if (!(t0)) {
                if ((l4 < INT32_C(0))) {
                    l13 = true;
                } else {
                    l14 = l11;
                    vader_array_t* _a2_slotarr = ((vader_array_t*) l1);
                    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l14)
                    l15 = ((int32_t*) _a2_slotarr->buf->slots)[vader_array_offset(_a2_slotarr) + (size_t) l14];
                    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
                    l16 = ((int32_t*) _a2_slotarr->buf->slots)[vader_array_offset(_a2_slotarr) + (size_t) l4];
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

static void* vader_emit_bytecode$param_c_types_of(void* l0) {
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
    l1 = ((vader_struct_vader_core_mono$MonoEntry_t*) l0)->f_decl;
    vader_array_t* _a0_arr = vader_array_new(26u, 0u, 0u, 577u);
    l2 = (void*) _a0_arr;
    if (!(l1.tag == 1048u)) {
        { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = false;
    t0 = l1.payload.obj;
    l4 = ((vader_struct_toolchain_ast$FnDecl_t*) t0)->f_params;
    l5 = vader_array_length(((vader_array_t*) l4));
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        t0 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l6);
        l7 = toolchain_ast$c_type_of(((vader_struct_toolchain_ast$FnParam_t*) t0)->f_decorators);
        vader_array_push_scalar((vader_array_t*) l2, vader_box_string(577u, l7));
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

static vader_box_t vader_emit_bytecode$plan_bytecode_stages(void* l0) {
    vader_box_t l1 = vader_box_null(), l2 = vader_box_null();
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l1, &l2, &t1 };
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = toolchain_stage$plan_stages__vader_core_bytecode_BcFunction__vader_core_bytecode_BcFunction__vader_emit_bytecode_BytecodeSpec(l0);
    l2 = l1;
    if (l1.tag == 1162u) {
        t0 = l2.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l1.payload.obj;
    t1 = vader_emit_bytecode$walk_properties(t0);
    { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_emit_bytecode$planned_bytecode_stages(void) {
    vader_box_t l0 = vader_box_null(), l1 = vader_box_null();
    vader_string_t l2 = 0;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    vader_box_t* gc_roots[2] = { &l0, &l1 };
    void** gc_raw_roots[1] = { &t0 };
    vader_string_t* gc_atom_roots[2] = { &l2, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_emit_bytecode$bytecode_stages();
    l0 = vader_emit_bytecode$plan_bytecode_stages(t0);
    l1 = l0;
    if (l0.tag == 1162u) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_toolchain_stage$PlanError_t*) t0)->f_message;
        t1 = concat_2(2068u, l2);
        vader_host_std_core$Intrinsic$panic(t1);
        vader_unreachable("a no-return call returned");
    } else {
        t0 = l0.payload.obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_gc_top = gc_frame.prev;
}

static void* vader_emit_bytecode$propagated_once(void* l0) {
    int64_t l1, l2, l9, l10, l12, l17;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l20 = NULL;
    void* l21 = NULL;
    void* l22 = NULL;
    void* l23 = NULL;
    vader_box_t l11 = vader_box_null(), l25 = vader_box_null(), l27 = vader_box_null(), l28 = vader_box_null(), l29 = vader_box_null();
    int32_t l13, l14, l15, l16, l18, l19;
    bool l24;
    uint8_t l26;
    vader_string_t l30 = 0;
    void* t0 = NULL;
    int32_t t1;
    bool t2;
    vader_box_t t3 = vader_box_null();
    int64_t t4;
    vader_box_t* gc_roots[6] = { &l11, &l25, &l27, &l28, &l29, &t3 };
    void** gc_raw_roots[12] = { &l0, &l3, &l4, &l5, &l6, &l7, &l8, &l20, &l21, &l22, &l23, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l30 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 6u, 12u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_signature)->f_params));
    l2 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_locals));
    l2 = vader_chk_add(i64, l1, l2);
    if ((l2 <= l1)) {
        { void* __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a0_arr = vader_array_new(27u, 1u, 7u, 580u);
    ((int32_t*) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = (int32_t) INT32_C(0);
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l2);
    l3 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(27u, 1u, 7u, 580u);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 0u] = (int32_t) INT32_C(0);
    t0 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l2);
    l4 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_new(27u, 1u, 7u, 580u);
    ((int32_t*) _a4_arr->buf->slots)[vader_array_offset(_a4_arr) + 0u] = (int32_t) INT32_C(0);
    t0 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l2);
    l5 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(27u, 1u, 7u, 580u);
    ((int32_t*) _a6_arr->buf->slots)[vader_array_offset(_a6_arr) + 0u] = (int32_t) INT32_C(-1);
    t0 = (void*) _a6_arr;
    vader_array_t* _a7_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l2);
    l6 = (void*) _a7_arr;
    vader_array_t* _a8_arr = vader_array_new(27u, 1u, 7u, 580u);
    ((int32_t*) _a8_arr->buf->slots)[vader_array_offset(_a8_arr) + 0u] = (int32_t) INT32_C(-1);
    t0 = (void*) _a8_arr;
    vader_array_t* _a9_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l2);
    l7 = (void*) _a9_arr;
    l8 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_body;
    l9 = vader_array_length(((vader_array_t*) l8));
    l10 = INT64_C(0);
    while ((l10 < l9)) {
        vader_array_t* _a10_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
        l11 = vader_array_ref_load_box(_a10_slotarr->buf, vader_array_offset(_a10_slotarr) + (size_t) l10);
        if (l11.tag == 1296u) {
            t0 = l11.payload.obj;
            t1 = ((vader_struct_vader_core_bytecode$LocalSet_t*) t0)->f_slot;
            l12 = ((int64_t) (int32_t) t1);
            vader_array_t* _a11_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l12)
            t1 = ((int32_t*) _a11_slotarr->buf->slots)[vader_array_offset(_a11_slotarr) + (size_t) l12];
            l13 = vader_chk_add(i32, t1, INT32_C(1));
            VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l12)
            ((int32_t*) _a11_slotarr->buf->slots)[vader_array_offset(_a11_slotarr) + (size_t) l12] = (int32_t) l13;
            l14 = ((int32_t) (int64_t) l10);
            vader_array_t* _a12_slotarr = ((vader_array_t*) l6);
            VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a12_slotarr, l12)
            ((int32_t*) _a12_slotarr->buf->slots)[vader_array_offset(_a12_slotarr) + (size_t) l12] = (int32_t) l14;
        }
        if (l11.tag == 1297u) {
            t0 = l11.payload.obj;
            l15 = ((vader_struct_vader_core_bytecode$LocalTee_t*) t0)->f_slot;
            vader_array_t* _a13_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a13_slotarr, l15)
            t1 = ((int32_t*) _a13_slotarr->buf->slots)[vader_array_offset(_a13_slotarr) + (size_t) l15];
            l16 = vader_chk_add(i32, t1, INT32_C(1));
            VADER_ARRAY_CHECK_INDEX(_a13_slotarr, l15)
            ((int32_t*) _a13_slotarr->buf->slots)[vader_array_offset(_a13_slotarr) + (size_t) l15] = (int32_t) l16;
        }
        if (l11.tag == 1295u) {
            t0 = l11.payload.obj;
            t1 = ((vader_struct_vader_core_bytecode$LocalGet_t*) t0)->f_slot;
            l17 = ((int64_t) (int32_t) t1);
            vader_array_t* _a14_slotarr = ((vader_array_t*) l4);
            VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a14_slotarr, l17)
            t1 = ((int32_t*) _a14_slotarr->buf->slots)[vader_array_offset(_a14_slotarr) + (size_t) l17];
            l18 = vader_chk_add(i32, t1, INT32_C(1));
            VADER_ARRAY_CHECK_INDEX(_a14_slotarr, l17)
            ((int32_t*) _a14_slotarr->buf->slots)[vader_array_offset(_a14_slotarr) + (size_t) l17] = (int32_t) l18;
            l19 = ((int32_t) (int64_t) l10);
            vader_array_t* _a15_slotarr = ((vader_array_t*) l7);
            VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a15_slotarr, l17)
            ((int32_t*) _a15_slotarr->buf->slots)[vader_array_offset(_a15_slotarr) + (size_t) l17] = (int32_t) l19;
        }
        l10 = (l10 + INT64_C(1));
    }
    vader_array_t* _a16_arr = vader_array_new(27u, 0u, 7u, 580u);
    l20 = (void*) _a16_arr;
    vader_array_t* _a17_arr = vader_array_new(24u, 0u, 12u, 575u);
    l21 = (void*) _a17_arr;
    vader_array_t* _a18_arr = vader_array_new(27u, 0u, 7u, 580u);
    l22 = (void*) _a18_arr;
    vader_struct_std_collections$Map__i32__bool_t* _a19_obj = (vader_struct_std_collections$Map__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__i32__bool_t));
    vader_obj_header_init(_a19_obj, 815u);
    _a19_obj->f_ekeys = l20;
    _a19_obj->f_evals = l21;
    _a19_obj->f_index = l22;
    _a19_obj->f_mask = INT64_C(0);
    _a19_obj->f_grow_at = INT64_C(0);
    _a19_obj->f_size = INT64_C(0);
    _a19_obj->f_tombs = INT64_C(0);
    l20 = (void*) _a19_obj;
    vader_array_t* _a20_arr = vader_array_new(27u, 0u, 7u, 580u);
    l21 = (void*) _a20_arr;
    vader_array_t* _a21_arr = vader_array_new(33u, 0u, 0u, 588u);
    l22 = (void*) _a21_arr;
    vader_array_t* _a22_arr = vader_array_new(27u, 0u, 7u, 580u);
    l23 = (void*) _a22_arr;
    vader_struct_std_collections$Map__i32__Any_t* _a23_obj = (vader_struct_std_collections$Map__i32__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__i32__Any_t));
    vader_obj_header_init(_a23_obj, 812u);
    _a23_obj->f_ekeys = l21;
    _a23_obj->f_evals = l22;
    _a23_obj->f_index = l23;
    _a23_obj->f_mask = INT64_C(0);
    _a23_obj->f_grow_at = INT64_C(0);
    _a23_obj->f_size = INT64_C(0);
    _a23_obj->f_tombs = INT64_C(0);
    l21 = (void*) _a23_obj;
    l10 = l1;
    while ((l10 < l2)) {
        l24 = true;
        vader_array_t* _a24_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a24_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a24_slotarr, l10)
        t1 = ((int32_t*) _a24_slotarr->buf->slots)[vader_array_offset(_a24_slotarr) + (size_t) l10];
        if (t1 != INT32_C(0)) {
            l24 = false;
        }
        vader_array_t* _a25_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a25_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a25_slotarr, l10)
        t1 = ((int32_t*) _a25_slotarr->buf->slots)[vader_array_offset(_a25_slotarr) + (size_t) l10];
        if (t1 != INT32_C(1)) {
            l24 = false;
        }
        vader_array_t* _a26_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a26_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a26_slotarr, l10)
        t1 = ((int32_t*) _a26_slotarr->buf->slots)[vader_array_offset(_a26_slotarr) + (size_t) l10];
        if (t1 != INT32_C(1)) {
            l24 = false;
        }
        l13 = INT32_C(-1);
        l14 = INT32_C(-1);
        if (l24) {
            vader_array_t* _a27_slotarr = ((vader_array_t*) l6);
            VADER_ARRAY_RESOLVE_BUF(_a27_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a27_slotarr, l10)
            l13 = ((int32_t*) _a27_slotarr->buf->slots)[vader_array_offset(_a27_slotarr) + (size_t) l10];
            vader_array_t* _a28_slotarr = ((vader_array_t*) l7);
            VADER_ARRAY_RESOLVE_BUF(_a28_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a28_slotarr, l10)
            l14 = ((int32_t*) _a28_slotarr->buf->slots)[vader_array_offset(_a28_slotarr) + (size_t) l10];
            if ((l13 <= INT32_C(0))) {
                l24 = false;
            }
            if ((l14 <= l13)) {
                l24 = false;
            }
        }
        if (l24) {
            l15 = vader_chk_sub(i32, l13, INT32_C(1));
            vader_array_t* _a29_slotarr = ((vader_array_t*) l8);
            VADER_ARRAY_RESOLVE_BUF(_a29_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a29_slotarr, l15)
            l11 = vader_array_ref_load_box(_a29_slotarr->buf, vader_array_offset(_a29_slotarr) + (size_t) l15);
            l25 = vader_core_bytecode$const_op_of(l11);
            if (l25.tag == 0u) {
                l24 = false;
            } else {
                l22 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_locals;
                l12 = vader_chk_sub(i64, l10, l1);
                vader_array_t* _a30_slotarr = ((vader_array_t*) l22);
                VADER_ARRAY_RESOLVE_BUF(_a30_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a30_slotarr, l12)
                t0 = vader_array_ref_load_obj(_a30_slotarr->buf, vader_array_offset(_a30_slotarr) + (size_t) l12);
                l26 = ((vader_struct_vader_core_bytecode$BcLocal_t*) t0)->f_val;
                t2 = vader_emit_bytecode$const_fills_slot(l25, l26);
                if (t2) {
                    l16 = vader_chk_sub(i32, l13, INT32_C(1));
                    std_collections$Map$std_core$IndexSet$set_at__i32__bool(l20, l16, true);
                    std_collections$Map$std_core$IndexSet$set_at__i32__bool(l20, l13, true);
                    std_collections$Map$std_core$IndexSet$set_at__i32__Any(l21, l14, l11);
                } else {
                    l24 = false;
                }
            }
        }
        l10 = (l10 + INT64_C(1));
    }
    t2 = std_collections$is_empty__i32__bool(l20);
    if (t2) {
        { void* __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a31_arr = vader_array_new(445u, 0u, 13u, 2295u);
    l3 = (void*) _a31_arr;
    vader_array_t* _a32_arr = vader_array_new(449u, 0u, 13u, 2355u);
    l4 = (void*) _a32_arr;
    vader_array_t* _a33_arr = vader_array_new(27u, 1u, 7u, 580u);
    ((int32_t*) _a33_arr->buf->slots)[vader_array_offset(_a33_arr) + 0u] = (int32_t) INT32_C(-1);
    t0 = (void*) _a33_arr;
    vader_array_t* _a34_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l9);
    l5 = (void*) _a34_arr;
    l1 = INT64_C(0);
    while ((l1 < l9)) {
        l13 = ((int32_t) (int64_t) l1);
        t3 = std_collections$Map$std_core$Index$at__i32__bool(l20, l13);
        if (t3.tag == 575u) {
            l1 = vader_chk_add(i64, l1, INT64_C(1));
            continue;
        }
        l14 = ((int32_t) (int64_t) l1);
        l11 = std_collections$Map$std_core$Index$at__i32__Any(l21, l14);
        if (l11.tag == 0u) {
            t4 = vader_array_length(((vader_array_t*) l3));
            l15 = ((int32_t) (int64_t) t4);
            vader_array_t* _a35_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a35_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a35_slotarr, l1)
            ((int32_t*) _a35_slotarr->buf->slots)[vader_array_offset(_a35_slotarr) + (size_t) l1] = (int32_t) l15;
            vader_array_t* _a36_slotarr = ((vader_array_t*) l8);
            VADER_ARRAY_RESOLVE_BUF(_a36_slotarr)
            l25 = vader_array_ref_load_box(_a36_slotarr->buf, vader_array_offset(_a36_slotarr) + (size_t) l1);
            vader_array_push_ref((vader_array_t*) l3, l25.payload.obj);
            vader_array_t* _a37_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_debug);
            VADER_ARRAY_RESOLVE_BUF(_a37_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a37_slotarr, l1)
            l27 = vader_array_ref_load_box(_a37_slotarr->buf, vader_array_offset(_a37_slotarr) + (size_t) l1);
            vader_array_push_ref((vader_array_t*) l4, l27.payload.obj);
        } else {
            t4 = vader_array_length(((vader_array_t*) l3));
            l16 = ((int32_t) (int64_t) t4);
            vader_array_t* _a38_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a38_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a38_slotarr, l1)
            ((int32_t*) _a38_slotarr->buf->slots)[vader_array_offset(_a38_slotarr) + (size_t) l1] = (int32_t) l16;
            l28 = l11;
            vader_array_push_ref((vader_array_t*) l3, l28.payload.obj);
            vader_array_t* _a39_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_debug);
            VADER_ARRAY_RESOLVE_BUF(_a39_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a39_slotarr, l1)
            l29 = vader_array_ref_load_box(_a39_slotarr->buf, vader_array_offset(_a39_slotarr) + (size_t) l1);
            vader_array_push_ref((vader_array_t*) l4, l29.payload.obj);
        }
        l1 = vader_chk_add(i64, l1, INT64_C(1));
    }
    l6 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_jump_table;
    l1 = vader_array_length(((vader_array_t*) l3));
    l5 = vader_core_bytecode$remap_jump_table(l6, l5, l1);
    l6 = l0;
    l30 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l6)->f_name;
    l24 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l6)->f_is_main;
    l7 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l6)->f_signature;
    l8 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l6)->f_locals;
    l6 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l6)->f_source_pc;
    vader_struct_vader_core_bytecode$BcFunction_t* _a40_obj = (vader_struct_vader_core_bytecode$BcFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcFunction_t));
    vader_obj_header_init(_a40_obj, 1182u);
    _a40_obj->f_name = l30;
    _a40_obj->f_is_main = l24;
    _a40_obj->f_signature = l7;
    _a40_obj->f_locals = l8;
    _a40_obj->f_body = l3;
    _a40_obj->f_debug = l4;
    _a40_obj->f_jump_table = l5;
    _a40_obj->f_source_pc = l6;
    t0 = (void*) _a40_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_emit_bytecode$prune_unused_data(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    void* l16 = NULL;
    int64_t l5, l6, l7, l8;
    vader_box_t l9 = vader_box_null();
    int32_t l10, l11, l15;
    void* t0 = NULL;
    bool t1;
    int64_t t2;
    vader_box_t* gc_roots[1] = { &l9 };
    void** gc_raw_roots[10] = { &l0, &l1, &l2, &l3, &l4, &l12, &l13, &l14, &l16, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 10u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(27u, 0u, 7u, 580u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(24u, 0u, 12u, 575u);
    l3 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(27u, 0u, 7u, 580u);
    l4 = (void*) _a2_arr;
    vader_struct_std_collections$Map__i32__bool_t* _a3_obj = (vader_struct_std_collections$Map__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__i32__bool_t));
    vader_obj_header_init(_a3_obj, 815u);
    _a3_obj->f_ekeys = l2;
    _a3_obj->f_evals = l3;
    _a3_obj->f_index = l4;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a3_obj;
    vader_struct_std_collections$Set__i32_t* _a4_obj = (vader_struct_std_collections$Set__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Set__i32_t));
    vader_obj_header_init(_a4_obj, 989u);
    _a4_obj->f_inner = t0;
    l2 = (void*) _a4_obj;
    l3 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_functions;
    l5 = vader_array_length(((vader_array_t*) l3));
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a5_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        t0 = vader_array_ref_load_obj(_a5_slotarr->buf, vader_array_offset(_a5_slotarr) + (size_t) l6);
        l4 = ((vader_struct_vader_core_bytecode$BcFunction_t*) t0)->f_body;
        l7 = vader_array_length(((vader_array_t*) l4));
        l8 = INT64_C(0);
        while ((l8 < l7)) {
            vader_array_t* _a6_slotarr = ((vader_array_t*) l4);
            VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
            l9 = vader_array_ref_load_box(_a6_slotarr->buf, vader_array_offset(_a6_slotarr) + (size_t) l8);
            if (l9.tag == 1220u) {
                t0 = l9.payload.obj;
                l10 = ((vader_struct_vader_core_bytecode$DataConst_t*) t0)->f_pool_index;
                std_collections$add__i32(l2, l10);
            }
            l8 = (l8 + INT64_C(1));
        }
        l6 = (l6 + INT64_C(1));
    }
    l5 = std_collections$len__i32(l2);
    l6 = vader_array_length(((vader_array_t*) l1));
    if (l5 == l6) {
        { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a7_arr = vader_array_new(27u, 0u, 7u, 580u);
    l3 = (void*) _a7_arr;
    vader_array_t* _a8_arr = vader_array_new(446u, 0u, 13u, 2318u);
    l4 = (void*) _a8_arr;
    l5 = INT64_C(0);
    l6 = vader_array_length(((vader_array_t*) l1));
    while ((l5 < l6)) {
        l10 = ((int32_t) (int64_t) l5);
        t1 = std_collections$Set$std_core$Contains$contains__i32(l2, l10);
        if (t1) {
            t2 = vader_array_length(((vader_array_t*) l4));
            l11 = ((int32_t) (int64_t) t2);
            vader_array_push_i32((vader_array_t*) l3, l11);
            vader_array_t* _a9_slotarr = ((vader_array_t*) l1);
            VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
            l9 = vader_array_ref_load_box(_a9_slotarr->buf, vader_array_offset(_a9_slotarr) + (size_t) l5);
            vader_array_push_ref((vader_array_t*) l4, l9.payload.obj);
        } else {
            vader_array_push_i32((vader_array_t*) l3, INT32_C(-1));
        }
        l5 = (l5 + INT64_C(1));
    }
    l2 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_functions;
    l5 = vader_array_length(((vader_array_t*) l2));
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a10_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
        l12 = vader_array_ref_load_obj(_a10_slotarr->buf, vader_array_offset(_a10_slotarr) + (size_t) l6);
        l7 = INT64_C(0);
        l8 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l12)->f_body));
        while ((l7 < l8)) {
            vader_array_t* _a11_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l12)->f_body);
            VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l7)
            l9 = vader_array_ref_load_box(_a11_slotarr->buf, vader_array_offset(_a11_slotarr) + (size_t) l7);
            if (l9.tag == 1220u) {
                l13 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l12)->f_body;
                l14 = l9.payload.obj;
                t0 = l9.payload.obj;
                l10 = ((vader_struct_vader_core_bytecode$DataConst_t*) t0)->f_pool_index;
                vader_array_t* _a12_slotarr = ((vader_array_t*) l3);
                VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a12_slotarr, l10)
                l11 = ((int32_t*) _a12_slotarr->buf->slots)[vader_array_offset(_a12_slotarr) + (size_t) l10];
                l15 = ((vader_struct_vader_core_bytecode$DataConst_t*) l14)->f_type_id;
                vader_struct_vader_core_bytecode$DataConst_t* _a13_obj = (vader_struct_vader_core_bytecode$DataConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$DataConst_t));
                vader_obj_header_init(_a13_obj, 1220u);
                _a13_obj->f_pool_index = l11;
                _a13_obj->f_type_id = l15;
                l16 = (void*) _a13_obj;
                vader_array_t* _a14_slotarr = ((vader_array_t*) l13);
                VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a14_slotarr, l7)
                vader_array_ref_store(_a14_slotarr->buf, vader_array_offset(_a14_slotarr) + (size_t) l7, l16);
                VADER_WRITE_BARRIER(_a14_slotarr->buf);
            }
            l7 = (l7 + INT64_C(1));
        }
        l6 = (l6 + INT64_C(1));
    }
    { void* __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_emit_bytecode$prune_unused_functions(void* l0, void* l1, void* l2) {
    int64_t l3, l7, l11, l12, l16, l18;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l14 = NULL;
    void* l15 = NULL;
    void* l19 = NULL;
    void* l21 = NULL;
    void* l25 = NULL;
    int32_t l8, l10, l22, l23, l24, l26, l27, l28;
    vader_string_t l9 = 0;
    vader_string_t l29 = 0;
    bool l13;
    vader_box_t l17 = vader_box_null(), l20 = vader_box_null();
    bool t0;
    int32_t t1;
    void* t2 = NULL;
    vader_box_t t3 = vader_box_null();
    int64_t t4;
    vader_string_t t5 = 0;
    vader_box_t* gc_roots[3] = { &l17, &l20, &t3 };
    void** gc_raw_roots[12] = { &l0, &l1, &l2, &l4, &l5, &l6, &l14, &l15, &l19, &l21, &l25, &t2 };
    vader_string_t* gc_atom_roots[3] = { &l9, &l29, &t5 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 12u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = vader_array_length(((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_functions));
    vader_array_t* _a0_arr = vader_array_new(27u, 0u, 7u, 580u);
    l4 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(24u, 0u, 12u, 575u);
    l5 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(27u, 0u, 7u, 580u);
    l6 = (void*) _a2_arr;
    vader_struct_std_collections$Map__i32__bool_t* _a3_obj = (vader_struct_std_collections$Map__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__i32__bool_t));
    vader_obj_header_init(_a3_obj, 815u);
    _a3_obj->f_ekeys = l4;
    _a3_obj->f_evals = l5;
    _a3_obj->f_index = l6;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    l4 = (void*) _a3_obj;
    l7 = INT64_C(0);
    while ((l7 < l3)) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_functions);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l7)
        l5 = vader_array_ref_load_obj(_a4_slotarr->buf, vader_array_offset(_a4_slotarr) + (size_t) l7);
        t0 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l5)->f_is_main;
        if (t0) {
            l8 = ((int32_t) (int64_t) l7);
            std_collections$Map$std_core$IndexSet$set_at__i32__bool(l4, l8, true);
        }
        l9 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l5)->f_name;
        t0 = std_core$$array$Contains$contains__string(l2, l9);
        if (t0) {
            l10 = ((int32_t) (int64_t) l7);
            std_collections$Map$std_core$IndexSet$set_at__i32__bool(l4, l10, true);
        }
        l7 = (l7 + INT64_C(1));
    }
    l5 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_exports;
    l7 = vader_array_length(((vader_array_t*) l5));
    l11 = INT64_C(0);
    while ((l11 < l7)) {
        vader_array_t* _a5_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        l6 = vader_array_ref_load_obj(_a5_slotarr->buf, vader_array_offset(_a5_slotarr) + (size_t) l11);
        t1 = ((vader_struct_vader_core_bytecode$BcExport_t*) l6)->f_fn_index;
        l12 = ((int64_t) (int32_t) t1);
        if ((INT64_C(0) <= l12)) {
            l13 = (l12 < l3);
        } else {
            l13 = false;
        }
        if (l13) {
            l8 = ((vader_struct_vader_core_bytecode$BcExport_t*) l6)->f_fn_index;
            std_collections$Map$std_core$IndexSet$set_at__i32__bool(l4, l8, true);
        }
        l11 = (l11 + INT64_C(1));
    }
    l5 = l1;
    l7 = vader_array_length(((vader_array_t*) l5));
    l11 = INT64_C(0);
    while ((l11 < l7)) {
        vader_array_t* _a6_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        l8 = ((int32_t*) _a6_slotarr->buf->slots)[vader_array_offset(_a6_slotarr) + (size_t) l11];
        l12 = ((int64_t) (int32_t) l8);
        if ((INT64_C(0) <= l12)) {
            l13 = (l12 < l3);
        } else {
            l13 = false;
        }
        if (l13) {
            std_collections$Map$std_core$IndexSet$set_at__i32__bool(l4, l8, true);
        }
        l11 = (l11 + INT64_C(1));
    }
    l6 = l4;
    l11 = ((vader_struct_std_collections$Map__i32__bool_t*) l6)->f_size;
    if ((INT64_C(0) < l11)) {
        l7 = ((vader_struct_std_collections$Map__i32__bool_t*) l6)->f_size;
    } else {
        l7 = INT64_C(0);
    }
    vader_array_t* _a7_arr = vader_array_reserve(27u, (int64_t) l7, 7u, 580u);
    l14 = (void*) _a7_arr;
    l15 = ((vader_struct_std_collections$Map__i32__bool_t*) l6)->f_ekeys;
    l7 = INT64_C(0);
    l11 = ((vader_struct_std_collections$Map__i32__bool_t*) l6)->f_size;
    vader_array_t* _pc179_hdr = (vader_array_t*) l14;
    size_t _pc179_len = vader_array_length(_pc179_hdr);
    size_t _pc179_cap = vader_array_is_borrowed(_pc179_hdr) ? (size_t) 0 : vader_array_capacity(_pc179_hdr);
    void* _pc179_slots = _pc179_hdr->buf->slots;
    for (;;) {
        if ((l7 < l11)) {
            vader_array_t* _a8_slotarr = ((vader_array_t*) l15);
            VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l7)
            l8 = ((int32_t*) _a8_slotarr->buf->slots)[vader_array_offset(_a8_slotarr) + (size_t) l7];
            if (VADER_LIKELY(_pc179_len < _pc179_cap)) {
                ((int32_t*) _pc179_slots)[_pc179_len] = (int32_t) (l8);
                _pc179_len += 1;
            } else {
                vader_array_set_length(_pc179_hdr, _pc179_len);
                if (_pc179_hdr->buf->length < _pc179_len) {
                    _pc179_hdr->buf->length = _pc179_len;
                }
                vader_array_push_i32((vader_array_t*) l14, l8);
                _pc179_hdr = (vader_array_t*) l14;
                _pc179_len = vader_array_length(_pc179_hdr);
                _pc179_cap = vader_array_is_borrowed(_pc179_hdr) ? (size_t) 0 : vader_array_capacity(_pc179_hdr);
                _pc179_slots = _pc179_hdr->buf->slots;
            }
            l7 = (l7 + INT64_C(1));
            continue;
        }
        vader_array_set_length(_pc179_hdr, _pc179_len);
        if (_pc179_hdr->buf->length < _pc179_len) {
            _pc179_hdr->buf->length = _pc179_len;
        }
        break;
    }
    l5 = l14;
    l7 = INT64_C(0);
    for (;;) {
        l11 = vader_array_length(((vader_array_t*) l5));
        if ((l7 < l11)) {
            vader_array_t* _a9_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
            l8 = ((int32_t*) _a9_slotarr->buf->slots)[vader_array_offset(_a9_slotarr) + (size_t) l7];
            l7 = vader_chk_add(i64, l7, INT64_C(1));
            vader_array_t* _a10_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_functions);
            VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a10_slotarr, l8)
            t2 = vader_array_ref_load_obj(_a10_slotarr->buf, vader_array_offset(_a10_slotarr) + (size_t) l8);
            l6 = ((vader_struct_vader_core_bytecode$BcFunction_t*) t2)->f_body;
            l12 = vader_array_length(((vader_array_t*) l6));
            l16 = INT64_C(0);
            while ((l16 < l12)) {
                vader_array_t* _a11_slotarr = ((vader_array_t*) l6);
                VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
                l17 = vader_array_ref_load_box(_a11_slotarr->buf, vader_array_offset(_a11_slotarr) + (size_t) l16);
                if ((l17.tag == 1213u || l17.tag == 1241u || l17.tag == 1242u || l17.tag == 1299u)) {
                    l10 = VADER_UNION_FIELD(int32_t, vader_struct_vader_core_bytecode$Call_t, f_function_index, l17.payload.obj);
                    t3 = std_collections$Map$std_core$Index$at__i32__bool(l4, l10);
                    if (t3.tag == 575u) {
                        l16 = (l16 + INT64_C(1));
                        continue;
                    }
                    std_collections$Map$std_core$IndexSet$set_at__i32__bool(l4, l10, true);
                    vader_array_push_i32((vader_array_t*) l5, l10);
                    l16 = (l16 + INT64_C(1));
                    continue;
                }
                l16 = (l16 + INT64_C(1));
            }
            continue;
        }
        break;
    }
    t0 = std_collections$is_empty__i32__bool(l4);
    if (t0) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    t4 = std_collections$len__i32__bool(l4);
    if (t4 == l3) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_array_t* _a12_arr = vader_array_new(103u, 0u, 13u, 1182u);
    l5 = (void*) _a12_arr;
    vader_array_t* _a13_arr = vader_array_new(27u, 0u, 7u, 580u);
    l6 = (void*) _a13_arr;
    l7 = INT64_C(0);
    while ((l7 < l3)) {
        l8 = ((int32_t) (int64_t) l7);
        t3 = std_collections$Map$std_core$Index$at__i32__bool(l4, l8);
        if (t3.tag == 575u) {
            t4 = vader_array_length(((vader_array_t*) l5));
            l10 = ((int32_t) (int64_t) t4);
            vader_array_push_i32((vader_array_t*) l6, l10);
            vader_array_t* _a14_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_functions);
            VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a14_slotarr, l7)
            l14 = vader_array_ref_load_obj(_a14_slotarr->buf, vader_array_offset(_a14_slotarr) + (size_t) l7);
            vader_array_push_ref((vader_array_t*) l5, l14);
        } else {
            vader_array_push_i32((vader_array_t*) l6, INT32_C(-1));
        }
        l7 = (l7 + INT64_C(1));
    }
    l4 = l5;
    l3 = vader_array_length(((vader_array_t*) l4));
    l7 = INT64_C(0);
    while ((l7 < l3)) {
        vader_array_t* _a15_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
        l14 = vader_array_ref_load_obj(_a15_slotarr->buf, vader_array_offset(_a15_slotarr) + (size_t) l7);
        l15 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l14)->f_body;
        l11 = INT64_C(0);
        l12 = vader_array_length(((vader_array_t*) l15));
        l16 = INT64_C(0);
        while ((l16 < l12)) {
            vader_array_t* _a16_slotarr = ((vader_array_t*) l15);
            VADER_ARRAY_RESOLVE_BUF(_a16_slotarr)
            l17 = vader_array_ref_load_box(_a16_slotarr->buf, vader_array_offset(_a16_slotarr) + (size_t) l16);
            l18 = l11;
            l19 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l14)->f_body;
            if (l17.tag == 1213u) {
                t2 = l17.payload.obj;
                l8 = ((vader_struct_vader_core_bytecode$Call_t*) t2)->f_function_index;
                vader_array_t* _a17_slotarr = ((vader_array_t*) l6);
                VADER_ARRAY_RESOLVE_BUF(_a17_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a17_slotarr, l8)
                t1 = ((int32_t*) _a17_slotarr->buf->slots)[vader_array_offset(_a17_slotarr) + (size_t) l8];
                vader_struct_vader_core_bytecode$Call_t* _a18_obj = (vader_struct_vader_core_bytecode$Call_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$Call_t));
                vader_obj_header_init(_a18_obj, 1213u);
                _a18_obj->f_function_index = t1;
                t2 = (void*) _a18_obj;
                l20 = vader_ref_box(t2);
            } else if (l17.tag == 1242u) {
                l21 = l17.payload.obj;
                t2 = l17.payload.obj;
                l10 = ((vader_struct_vader_core_bytecode$FnRef_t*) t2)->f_function_index;
                vader_array_t* _a19_slotarr = ((vader_array_t*) l6);
                VADER_ARRAY_RESOLVE_BUF(_a19_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a19_slotarr, l10)
                l22 = ((int32_t*) _a19_slotarr->buf->slots)[vader_array_offset(_a19_slotarr) + (size_t) l10];
                l23 = ((vader_struct_vader_core_bytecode$FnRef_t*) l21)->f_type_id;
                vader_struct_vader_core_bytecode$FnRef_t* _a20_obj = (vader_struct_vader_core_bytecode$FnRef_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$FnRef_t));
                vader_obj_header_init(_a20_obj, 1242u);
                _a20_obj->f_function_index = l22;
                _a20_obj->f_type_id = l23;
                t2 = (void*) _a20_obj;
                l20 = vader_ref_box(t2);
            } else if (l17.tag == 1241u) {
                t2 = l17.payload.obj;
                l24 = ((vader_struct_vader_core_bytecode$FnAddr_t*) t2)->f_function_index;
                vader_array_t* _a21_slotarr = ((vader_array_t*) l6);
                VADER_ARRAY_RESOLVE_BUF(_a21_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a21_slotarr, l24)
                t1 = ((int32_t*) _a21_slotarr->buf->slots)[vader_array_offset(_a21_slotarr) + (size_t) l24];
                vader_struct_vader_core_bytecode$FnAddr_t* _a22_obj = (vader_struct_vader_core_bytecode$FnAddr_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$FnAddr_t));
                vader_obj_header_init(_a22_obj, 1241u);
                _a22_obj->f_function_index = t1;
                t2 = (void*) _a22_obj;
                l20 = vader_ref_box(t2);
            } else if (l17.tag == 1299u) {
                l25 = l17.payload.obj;
                t2 = l17.payload.obj;
                l26 = ((vader_struct_vader_core_bytecode$MakeClosure_t*) t2)->f_function_index;
                vader_array_t* _a23_slotarr = ((vader_array_t*) l6);
                VADER_ARRAY_RESOLVE_BUF(_a23_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a23_slotarr, l26)
                l27 = ((int32_t*) _a23_slotarr->buf->slots)[vader_array_offset(_a23_slotarr) + (size_t) l26];
                l28 = ((vader_struct_vader_core_bytecode$MakeClosure_t*) l25)->f_env_type_id;
                vader_struct_vader_core_bytecode$MakeClosure_t* _a24_obj = (vader_struct_vader_core_bytecode$MakeClosure_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$MakeClosure_t));
                vader_obj_header_init(_a24_obj, 1299u);
                _a24_obj->f_function_index = l27;
                _a24_obj->f_env_type_id = l28;
                t2 = (void*) _a24_obj;
                l20 = vader_ref_box(t2);
            } else {
                l20 = l17;
            }
            vader_array_t* _a25_slotarr = ((vader_array_t*) l19);
            VADER_ARRAY_RESOLVE_BUF(_a25_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a25_slotarr, l18)
            vader_array_ref_store(_a25_slotarr->buf, vader_array_offset(_a25_slotarr) + (size_t) l18, l20.payload.obj);
            VADER_WRITE_BARRIER(_a25_slotarr->buf);
            l11 = vader_chk_add(i64, l11, INT64_C(1));
            l16 = (l16 + INT64_C(1));
        }
        l7 = (l7 + INT64_C(1));
    }
    vader_array_t* _a26_arr = vader_array_new(101u, 0u, 13u, 1179u);
    l4 = (void*) _a26_arr;
    l14 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_exports;
    l3 = vader_array_length(((vader_array_t*) l14));
    l7 = INT64_C(0);
    while ((l7 < l3)) {
        vader_array_t* _a27_slotarr = ((vader_array_t*) l14);
        VADER_ARRAY_RESOLVE_BUF(_a27_slotarr)
        l15 = vader_array_ref_load_obj(_a27_slotarr->buf, vader_array_offset(_a27_slotarr) + (size_t) l7);
        l8 = ((vader_struct_vader_core_bytecode$BcExport_t*) l15)->f_fn_index;
        vader_array_t* _a28_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a28_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a28_slotarr, l8)
        l10 = ((int32_t*) _a28_slotarr->buf->slots)[vader_array_offset(_a28_slotarr) + (size_t) l8];
        if ((l10 >= INT32_C(0))) {
            t5 = ((vader_struct_vader_core_bytecode$BcExport_t*) l15)->f_extern_name;
            vader_struct_vader_core_bytecode$BcExport_t* _a29_obj = (vader_struct_vader_core_bytecode$BcExport_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcExport_t));
            vader_obj_header_init(_a29_obj, 1179u);
            _a29_obj->f_extern_name = t5;
            _a29_obj->f_fn_index = l10;
            l19 = (void*) _a29_obj;
            vader_array_push_ref((vader_array_t*) l4, l19);
        }
        l7 = (l7 + INT64_C(1));
    }
    ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_exports = l4;
    VADER_WRITE_BARRIER((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0);
    vader_array_t* _a30_arr = vader_array_new(27u, 0u, 7u, 580u);
    l4 = (void*) _a30_arr;
    vader_array_t* _a31_arr = vader_array_new(27u, 0u, 7u, 580u);
    l14 = (void*) _a31_arr;
    vader_array_t* _a32_arr = vader_array_new(27u, 0u, 7u, 580u);
    l15 = (void*) _a32_arr;
    vader_struct_std_collections$Map__i32__i32_t* _a33_obj = (vader_struct_std_collections$Map__i32__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__i32__i32_t));
    vader_obj_header_init(_a33_obj, 816u);
    _a33_obj->f_ekeys = l4;
    _a33_obj->f_evals = l14;
    _a33_obj->f_index = l15;
    _a33_obj->f_mask = INT64_C(0);
    _a33_obj->f_grow_at = INT64_C(0);
    _a33_obj->f_size = INT64_C(0);
    _a33_obj->f_tombs = INT64_C(0);
    l4 = (void*) _a33_obj;
    l14 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_function_index_by_symbol_id;
    l15 = ((vader_struct_std_collections$Map__i32__i32_t*) l14)->f_ekeys;
    l19 = ((vader_struct_std_collections$Map__i32__i32_t*) l14)->f_evals;
    l3 = INT64_C(0);
    l7 = ((vader_struct_std_collections$Map__i32__i32_t*) l14)->f_size;
    while ((l3 < l7)) {
        vader_array_t* _a34_slotarr = ((vader_array_t*) l15);
        VADER_ARRAY_RESOLVE_BUF(_a34_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a34_slotarr, l3)
        l8 = ((int32_t*) _a34_slotarr->buf->slots)[vader_array_offset(_a34_slotarr) + (size_t) l3];
        vader_array_t* _a35_slotarr = ((vader_array_t*) l19);
        VADER_ARRAY_RESOLVE_BUF(_a35_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a35_slotarr, l3)
        l10 = ((int32_t*) _a35_slotarr->buf->slots)[vader_array_offset(_a35_slotarr) + (size_t) l3];
        l22 = l8;
        l23 = l10;
        vader_array_t* _a36_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a36_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a36_slotarr, l23)
        l24 = ((int32_t*) _a36_slotarr->buf->slots)[vader_array_offset(_a36_slotarr) + (size_t) l23];
        if ((l24 >= INT32_C(0))) {
            std_collections$Map$std_core$IndexSet$set_at__i32__i32(l4, l22, l24);
        }
        l3 = (l3 + INT64_C(1));
    }
    ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_function_index_by_symbol_id = l4;
    VADER_WRITE_BARRIER((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0);
    vader_array_t* _a37_arr = vader_array_new(26u, 0u, 0u, 577u);
    l4 = (void*) _a37_arr;
    vader_array_t* _a38_arr = vader_array_new(27u, 0u, 7u, 580u);
    l14 = (void*) _a38_arr;
    vader_array_t* _a39_arr = vader_array_new(27u, 0u, 7u, 580u);
    l15 = (void*) _a39_arr;
    vader_struct_std_collections$Map__string__i32_t* _a40_obj = (vader_struct_std_collections$Map__string__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__i32_t));
    vader_obj_header_init(_a40_obj, 902u);
    _a40_obj->f_ekeys = l4;
    _a40_obj->f_evals = l14;
    _a40_obj->f_index = l15;
    _a40_obj->f_mask = INT64_C(0);
    _a40_obj->f_grow_at = INT64_C(0);
    _a40_obj->f_size = INT64_C(0);
    _a40_obj->f_tombs = INT64_C(0);
    l4 = (void*) _a40_obj;
    l14 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_function_index_by_mangle;
    l15 = ((vader_struct_std_collections$Map__string__i32_t*) l14)->f_ekeys;
    l19 = ((vader_struct_std_collections$Map__string__i32_t*) l14)->f_evals;
    l3 = INT64_C(0);
    l7 = ((vader_struct_std_collections$Map__string__i32_t*) l14)->f_size;
    while ((l3 < l7)) {
        vader_array_t* _a41_slotarr = ((vader_array_t*) l15);
        VADER_ARRAY_RESOLVE_BUF(_a41_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a41_slotarr, l3)
        t3 = vader_array_box_slots(_a41_slotarr->buf)[vader_array_offset(_a41_slotarr) + (size_t) l3];
        l9 = t3.payload.s;
        vader_array_t* _a42_slotarr = ((vader_array_t*) l19);
        VADER_ARRAY_RESOLVE_BUF(_a42_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a42_slotarr, l3)
        l8 = ((int32_t*) _a42_slotarr->buf->slots)[vader_array_offset(_a42_slotarr) + (size_t) l3];
        l29 = l9;
        l10 = l8;
        vader_array_t* _a43_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a43_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a43_slotarr, l10)
        l22 = ((int32_t*) _a43_slotarr->buf->slots)[vader_array_offset(_a43_slotarr) + (size_t) l10];
        if ((l22 >= INT32_C(0))) {
            std_collections$Map$std_core$IndexSet$set_at__string__i32(l4, l29, l22);
        }
        l3 = (l3 + INT64_C(1));
    }
    ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_function_index_by_mangle = l4;
    VADER_WRITE_BARRIER((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0);
    vader_array_t* _a44_arr = vader_array_new(27u, 0u, 7u, 580u);
    l4 = (void*) _a44_arr;
    vader_array_t* _a45_arr = vader_array_new(33u, 0u, 0u, 588u);
    l14 = (void*) _a45_arr;
    vader_array_t* _a46_arr = vader_array_new(27u, 0u, 7u, 580u);
    l15 = (void*) _a46_arr;
    vader_struct_std_collections$Map__i32__Any___t* _a47_obj = (vader_struct_std_collections$Map__i32__Any___t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__i32__Any___t));
    vader_obj_header_init(_a47_obj, 813u);
    _a47_obj->f_ekeys = l4;
    _a47_obj->f_evals = l14;
    _a47_obj->f_index = l15;
    _a47_obj->f_mask = INT64_C(0);
    _a47_obj->f_grow_at = INT64_C(0);
    _a47_obj->f_size = INT64_C(0);
    _a47_obj->f_tombs = INT64_C(0);
    l4 = (void*) _a47_obj;
    l14 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_pinned_types_by_fn;
    l15 = ((vader_struct_std_collections$Map__i32__i32___t*) l14)->f_ekeys;
    l19 = ((vader_struct_std_collections$Map__i32__i32___t*) l14)->f_evals;
    l3 = INT64_C(0);
    l7 = ((vader_struct_std_collections$Map__i32__i32___t*) l14)->f_size;
    while ((l3 < l7)) {
        vader_array_t* _a48_slotarr = ((vader_array_t*) l15);
        VADER_ARRAY_RESOLVE_BUF(_a48_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a48_slotarr, l3)
        l8 = ((int32_t*) _a48_slotarr->buf->slots)[vader_array_offset(_a48_slotarr) + (size_t) l3];
        vader_array_t* _a49_slotarr = ((vader_array_t*) l19);
        VADER_ARRAY_RESOLVE_BUF(_a49_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a49_slotarr, l3)
        l14 = vader_array_ref_load_obj(_a49_slotarr->buf, vader_array_offset(_a49_slotarr) + (size_t) l3);
        l10 = l8;
        l21 = l14;
        vader_array_t* _a50_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a50_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a50_slotarr, l10)
        l22 = ((int32_t*) _a50_slotarr->buf->slots)[vader_array_offset(_a50_slotarr) + (size_t) l10];
        if ((l22 >= INT32_C(0))) {
            std_collections$Map$std_core$IndexSet$set_at__i32__Any(l4, l22, vader_ref_box(l21));
        }
        l3 = (l3 + INT64_C(1));
    }
    ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_pinned_types_by_fn = l4;
    VADER_WRITE_BARRIER((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0);
    ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_functions = l5;
    VADER_WRITE_BARRIER((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_bytecode$prune_unused_globals(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l11 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    void* l15 = NULL;
    int64_t l4, l5, l6, l7;
    vader_box_t l8 = vader_box_null();
    int32_t l9, l10;
    void* t0 = NULL;
    bool t1;
    int64_t t2;
    int32_t t3;
    vader_box_t* gc_roots[1] = { &l8 };
    void** gc_raw_roots[10] = { &l0, &l1, &l2, &l3, &l11, &l12, &l13, &l14, &l15, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 10u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(27u, 0u, 7u, 580u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(24u, 0u, 12u, 575u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(27u, 0u, 7u, 580u);
    l3 = (void*) _a2_arr;
    vader_struct_std_collections$Map__i32__bool_t* _a3_obj = (vader_struct_std_collections$Map__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__i32__bool_t));
    vader_obj_header_init(_a3_obj, 815u);
    _a3_obj->f_ekeys = l1;
    _a3_obj->f_evals = l2;
    _a3_obj->f_index = l3;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a3_obj;
    vader_struct_std_collections$Set__i32_t* _a4_obj = (vader_struct_std_collections$Set__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Set__i32_t));
    vader_obj_header_init(_a4_obj, 989u);
    _a4_obj->f_inner = t0;
    l1 = (void*) _a4_obj;
    l2 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_functions;
    l4 = vader_array_length(((vader_array_t*) l2));
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a5_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        t0 = vader_array_ref_load_obj(_a5_slotarr->buf, vader_array_offset(_a5_slotarr) + (size_t) l5);
        l3 = ((vader_struct_vader_core_bytecode$BcFunction_t*) t0)->f_body;
        l6 = vader_array_length(((vader_array_t*) l3));
        l7 = INT64_C(0);
        while ((l7 < l6)) {
            vader_array_t* _a6_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
            l8 = vader_array_ref_load_box(_a6_slotarr->buf, vader_array_offset(_a6_slotarr) + (size_t) l7);
            if (l8.tag == 1243u) {
                t0 = l8.payload.obj;
                l9 = ((vader_struct_vader_core_bytecode$GlobalGet_t*) t0)->f_index;
                std_collections$add__i32(l1, l9);
            } else if (l8.tag == 1244u) {
                t0 = l8.payload.obj;
                l10 = ((vader_struct_vader_core_bytecode$GlobalSet_t*) t0)->f_index;
                std_collections$add__i32(l1, l10);
            }
            l7 = (l7 + INT64_C(1));
        }
        l5 = (l5 + INT64_C(1));
    }
    l4 = std_collections$len__i32(l1);
    l5 = vader_array_length(((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_globals));
    if (l4 == l5) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_array_t* _a7_arr = vader_array_new(27u, 0u, 7u, 580u);
    l2 = (void*) _a7_arr;
    vader_array_t* _a8_arr = vader_array_new(104u, 0u, 13u, 1183u);
    l3 = (void*) _a8_arr;
    l4 = INT64_C(0);
    l5 = vader_array_length(((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_globals));
    while ((l4 < l5)) {
        l9 = ((int32_t) (int64_t) l4);
        t1 = std_collections$Set$std_core$Contains$contains__i32(l1, l9);
        if (t1) {
            t2 = vader_array_length(((vader_array_t*) l3));
            l10 = ((int32_t) (int64_t) t2);
            vader_array_push_i32((vader_array_t*) l2, l10);
            vader_array_t* _a9_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_globals);
            VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l4)
            l11 = vader_array_ref_load_obj(_a9_slotarr->buf, vader_array_offset(_a9_slotarr) + (size_t) l4);
            vader_array_push_ref((vader_array_t*) l3, l11);
        } else {
            vader_array_push_i32((vader_array_t*) l2, INT32_C(-1));
        }
        l4 = (l4 + INT64_C(1));
    }
    l1 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_functions;
    l4 = vader_array_length(((vader_array_t*) l1));
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a10_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
        l11 = vader_array_ref_load_obj(_a10_slotarr->buf, vader_array_offset(_a10_slotarr) + (size_t) l5);
        l6 = INT64_C(0);
        l7 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l11)->f_body));
        while ((l6 < l7)) {
            vader_array_t* _a11_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l11)->f_body);
            VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l6)
            l8 = vader_array_ref_load_box(_a11_slotarr->buf, vader_array_offset(_a11_slotarr) + (size_t) l6);
            if (l8.tag == 1243u) {
                l12 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l11)->f_body;
                t0 = l8.payload.obj;
                l9 = ((vader_struct_vader_core_bytecode$GlobalGet_t*) t0)->f_index;
                vader_array_t* _a12_slotarr = ((vader_array_t*) l2);
                VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a12_slotarr, l9)
                t3 = ((int32_t*) _a12_slotarr->buf->slots)[vader_array_offset(_a12_slotarr) + (size_t) l9];
                vader_struct_vader_core_bytecode$GlobalGet_t* _a13_obj = (vader_struct_vader_core_bytecode$GlobalGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$GlobalGet_t));
                vader_obj_header_init(_a13_obj, 1243u);
                _a13_obj->f_index = t3;
                l13 = (void*) _a13_obj;
                vader_array_t* _a14_slotarr = ((vader_array_t*) l12);
                VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a14_slotarr, l6)
                vader_array_ref_store(_a14_slotarr->buf, vader_array_offset(_a14_slotarr) + (size_t) l6, l13);
                VADER_WRITE_BARRIER(_a14_slotarr->buf);
            } else if (l8.tag == 1244u) {
                l14 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l11)->f_body;
                t0 = l8.payload.obj;
                l10 = ((vader_struct_vader_core_bytecode$GlobalSet_t*) t0)->f_index;
                vader_array_t* _a15_slotarr = ((vader_array_t*) l2);
                VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a15_slotarr, l10)
                t3 = ((int32_t*) _a15_slotarr->buf->slots)[vader_array_offset(_a15_slotarr) + (size_t) l10];
                vader_struct_vader_core_bytecode$GlobalSet_t* _a16_obj = (vader_struct_vader_core_bytecode$GlobalSet_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$GlobalSet_t));
                vader_obj_header_init(_a16_obj, 1244u);
                _a16_obj->f_index = t3;
                l15 = (void*) _a16_obj;
                vader_array_t* _a17_slotarr = ((vader_array_t*) l14);
                VADER_ARRAY_RESOLVE_BUF(_a17_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a17_slotarr, l6)
                vader_array_ref_store(_a17_slotarr->buf, vader_array_offset(_a17_slotarr) + (size_t) l6, l15);
                VADER_WRITE_BARRIER(_a17_slotarr->buf);
            }
            l6 = (l6 + INT64_C(1));
        }
        l5 = (l5 + INT64_C(1));
    }
    ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_globals = l3;
    VADER_WRITE_BARRIER((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_bytecode$prune_unused_imports(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l11 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    int64_t l4, l5, l6, l7;
    vader_box_t l8 = vader_box_null();
    int32_t l9, l10;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    int64_t t2;
    int32_t t3;
    vader_box_t* gc_roots[2] = { &l8, &t1 };
    void** gc_raw_roots[8] = { &l0, &l1, &l2, &l3, &l11, &l12, &l13, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 8u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(27u, 0u, 7u, 580u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(24u, 0u, 12u, 575u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(27u, 0u, 7u, 580u);
    l3 = (void*) _a2_arr;
    vader_struct_std_collections$Map__i32__bool_t* _a3_obj = (vader_struct_std_collections$Map__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__i32__bool_t));
    vader_obj_header_init(_a3_obj, 815u);
    _a3_obj->f_ekeys = l1;
    _a3_obj->f_evals = l2;
    _a3_obj->f_index = l3;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    l1 = (void*) _a3_obj;
    l2 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_functions;
    l4 = vader_array_length(((vader_array_t*) l2));
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        t0 = vader_array_ref_load_obj(_a4_slotarr->buf, vader_array_offset(_a4_slotarr) + (size_t) l5);
        l3 = ((vader_struct_vader_core_bytecode$BcFunction_t*) t0)->f_body;
        l6 = vader_array_length(((vader_array_t*) l3));
        l7 = INT64_C(0);
        while ((l7 < l6)) {
            vader_array_t* _a5_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
            l8 = vader_array_ref_load_box(_a5_slotarr->buf, vader_array_offset(_a5_slotarr) + (size_t) l7);
            if (l8.tag == 1214u) {
                t0 = l8.payload.obj;
                l9 = ((vader_struct_vader_core_bytecode$CallImport_t*) t0)->f_index;
                std_collections$Map$std_core$IndexSet$set_at__i32__bool(l1, l9, true);
            }
            l7 = (l7 + INT64_C(1));
        }
        l5 = (l5 + INT64_C(1));
    }
    l4 = std_collections$len__i32__bool(l1);
    l5 = vader_array_length(((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_imports));
    if (l4 == l5) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_array_t* _a6_arr = vader_array_new(27u, 0u, 7u, 580u);
    l2 = (void*) _a6_arr;
    vader_array_t* _a7_arr = vader_array_new(105u, 0u, 13u, 1184u);
    l3 = (void*) _a7_arr;
    l4 = INT64_C(0);
    l5 = vader_array_length(((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_imports));
    while ((l4 < l5)) {
        l9 = ((int32_t) (int64_t) l4);
        t1 = std_collections$Map$std_core$Index$at__i32__bool(l1, l9);
        if (t1.tag == 575u) {
            t2 = vader_array_length(((vader_array_t*) l3));
            l10 = ((int32_t) (int64_t) t2);
            vader_array_push_i32((vader_array_t*) l2, l10);
            vader_array_t* _a8_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_imports);
            VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l4)
            l11 = vader_array_ref_load_obj(_a8_slotarr->buf, vader_array_offset(_a8_slotarr) + (size_t) l4);
            vader_array_push_ref((vader_array_t*) l3, l11);
        } else {
            vader_array_push_i32((vader_array_t*) l2, INT32_C(-1));
        }
        l4 = (l4 + INT64_C(1));
    }
    l1 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_functions;
    l4 = vader_array_length(((vader_array_t*) l1));
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a9_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
        l11 = vader_array_ref_load_obj(_a9_slotarr->buf, vader_array_offset(_a9_slotarr) + (size_t) l5);
        l6 = INT64_C(0);
        l7 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l11)->f_body));
        while ((l6 < l7)) {
            vader_array_t* _a10_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l11)->f_body);
            VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a10_slotarr, l6)
            l8 = vader_array_ref_load_box(_a10_slotarr->buf, vader_array_offset(_a10_slotarr) + (size_t) l6);
            if (l8.tag == 1214u) {
                l12 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l11)->f_body;
                t0 = l8.payload.obj;
                l9 = ((vader_struct_vader_core_bytecode$CallImport_t*) t0)->f_index;
                vader_array_t* _a11_slotarr = ((vader_array_t*) l2);
                VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l9)
                t3 = ((int32_t*) _a11_slotarr->buf->slots)[vader_array_offset(_a11_slotarr) + (size_t) l9];
                vader_struct_vader_core_bytecode$CallImport_t* _a12_obj = (vader_struct_vader_core_bytecode$CallImport_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$CallImport_t));
                vader_obj_header_init(_a12_obj, 1214u);
                _a12_obj->f_index = t3;
                l13 = (void*) _a12_obj;
                vader_array_t* _a13_slotarr = ((vader_array_t*) l12);
                VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a13_slotarr, l6)
                vader_array_ref_store(_a13_slotarr->buf, vader_array_offset(_a13_slotarr) + (size_t) l6, l13);
                VADER_WRITE_BARRIER(_a13_slotarr->buf);
            }
            l6 = (l6 + INT64_C(1));
        }
        l5 = (l5 + INT64_C(1));
    }
    ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_imports = l3;
    VADER_WRITE_BARRIER((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0);
    { vader_gc_top = gc_frame.prev; return; }
}

static void* vader_emit_bytecode$prune_unused_types(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l13 = NULL;
    void* l24 = NULL;
    void* l27 = NULL;
    int64_t l5, l6, l10, l11, l14, l15;
    int32_t l12, l16, l21;
    vader_box_t l17 = vader_box_null(), l18 = vader_box_null();
    vader_string_t l19 = 0;
    vader_string_t l20 = 0;
    vader_string_t l25 = 0;
    bool l22, l26;
    uint8_t l23;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    int32_t t2;
    bool t3;
    int64_t t4;
    vader_box_t* gc_roots[3] = { &l17, &l18, &t1 };
    void** gc_raw_roots[12] = { &l0, &l1, &l2, &l3, &l4, &l7, &l8, &l9, &l13, &l24, &l27, &t0 };
    vader_string_t* gc_atom_roots[3] = { &l19, &l20, &l25 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 12u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(27u, 0u, 7u, 580u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(24u, 0u, 12u, 575u);
    l3 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(27u, 0u, 7u, 580u);
    l4 = (void*) _a2_arr;
    vader_struct_std_collections$Map__i32__bool_t* _a3_obj = (vader_struct_std_collections$Map__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__i32__bool_t));
    vader_obj_header_init(_a3_obj, 815u);
    _a3_obj->f_ekeys = l2;
    _a3_obj->f_evals = l3;
    _a3_obj->f_index = l4;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a3_obj;
    vader_struct_std_collections$Set__i32_t* _a4_obj = (vader_struct_std_collections$Set__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Set__i32_t));
    vader_obj_header_init(_a4_obj, 989u);
    _a4_obj->f_inner = t0;
    l2 = (void*) _a4_obj;
    std_collections$add__i32(l2, INT32_C(0));
    vader_array_t* _a5_arr = vader_array_new(27u, 0u, 7u, 580u);
    l3 = (void*) _a5_arr;
    l4 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_functions;
    l5 = vader_array_length(((vader_array_t*) l4));
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a6_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        l7 = vader_array_ref_load_obj(_a6_slotarr->buf, vader_array_offset(_a6_slotarr) + (size_t) l6);
        l8 = ((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l7)->f_signature)->f_result_types;
        vader_array_push_all((vader_array_t*) l3, (vader_array_t*) l8);
        l9 = ((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l7)->f_signature)->f_param_types;
        l10 = vader_array_length(((vader_array_t*) l9));
        l11 = INT64_C(0);
        while ((l11 < l10)) {
            vader_array_t* _a7_slotarr = ((vader_array_t*) l9);
            VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
            l12 = ((int32_t*) _a7_slotarr->buf->slots)[vader_array_offset(_a7_slotarr) + (size_t) l11];
            vader_array_push_i32((vader_array_t*) l3, l12);
            l11 = (l11 + INT64_C(1));
        }
        l13 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l7)->f_body;
        l14 = vader_array_length(((vader_array_t*) l13));
        l15 = INT64_C(0);
        while ((l15 < l14)) {
            vader_array_t* _a8_slotarr = ((vader_array_t*) l13);
            VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
            t1 = vader_array_ref_load_box(_a8_slotarr->buf, vader_array_offset(_a8_slotarr) + (size_t) l15);
            l16 = vader_emit_bytecode$type_index_of(t1);
            if ((l16 >= INT32_C(0))) {
                vader_array_push_i32((vader_array_t*) l3, l16);
            }
            l15 = (l15 + INT64_C(1));
        }
        l6 = (l6 + INT64_C(1));
    }
    l4 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_imports;
    l5 = vader_array_length(((vader_array_t*) l4));
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a9_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
        l7 = vader_array_ref_load_obj(_a9_slotarr->buf, vader_array_offset(_a9_slotarr) + (size_t) l6);
        l8 = ((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcImport_t*) l7)->f_signature)->f_result_types;
        vader_array_push_all((vader_array_t*) l3, (vader_array_t*) l8);
        l9 = ((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcImport_t*) l7)->f_signature)->f_param_types;
        l10 = vader_array_length(((vader_array_t*) l9));
        l11 = INT64_C(0);
        while ((l11 < l10)) {
            vader_array_t* _a10_slotarr = ((vader_array_t*) l9);
            VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
            l12 = ((int32_t*) _a10_slotarr->buf->slots)[vader_array_offset(_a10_slotarr) + (size_t) l11];
            vader_array_push_i32((vader_array_t*) l3, l12);
            l11 = (l11 + INT64_C(1));
        }
        l6 = (l6 + INT64_C(1));
    }
    l4 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_globals;
    l5 = vader_array_length(((vader_array_t*) l4));
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a11_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
        t0 = vader_array_ref_load_obj(_a11_slotarr->buf, vader_array_offset(_a11_slotarr) + (size_t) l6);
        l12 = ((vader_struct_vader_core_bytecode$BcGlobal_t*) t0)->f_type_id;
        vader_array_push_i32((vader_array_t*) l3, l12);
        l6 = (l6 + INT64_C(1));
    }
    l4 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_pinned_types;
    l5 = vader_array_length(((vader_array_t*) l4));
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a12_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
        l12 = ((int32_t*) _a12_slotarr->buf->slots)[vader_array_offset(_a12_slotarr) + (size_t) l6];
        vader_array_push_i32((vader_array_t*) l3, l12);
        l6 = (l6 + INT64_C(1));
    }
    l4 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_pinned_types_by_fn;
    l7 = ((vader_struct_std_collections$Map__i32__i32___t*) l4)->f_ekeys;
    l8 = ((vader_struct_std_collections$Map__i32__i32___t*) l4)->f_evals;
    l5 = INT64_C(0);
    l6 = ((vader_struct_std_collections$Map__i32__i32___t*) l4)->f_size;
    while ((l5 < l6)) {
        vader_array_t* _a13_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a13_slotarr, l5)
        t2 = ((int32_t*) _a13_slotarr->buf->slots)[vader_array_offset(_a13_slotarr) + (size_t) l5];
        vader_array_t* _a14_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a14_slotarr, l5)
        l4 = vader_array_ref_load_obj(_a14_slotarr->buf, vader_array_offset(_a14_slotarr) + (size_t) l5);
        l10 = vader_array_length(((vader_array_t*) l4));
        l11 = INT64_C(0);
        while ((l11 < l10)) {
            vader_array_t* _a15_slotarr = ((vader_array_t*) l4);
            VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
            l12 = ((int32_t*) _a15_slotarr->buf->slots)[vader_array_offset(_a15_slotarr) + (size_t) l11];
            vader_array_push_i32((vader_array_t*) l3, l12);
            l11 = (l11 + INT64_C(1));
        }
        l5 = (l5 + INT64_C(1));
    }
    l4 = vader_emit_bytecode$data_pool_type_roots(l0, l1);
    vader_array_push_all((vader_array_t*) l3, (vader_array_t*) l4);
    l5 = vader_array_length(((vader_array_t*) l3));
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a16_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a16_slotarr)
        t2 = ((int32_t*) _a16_slotarr->buf->slots)[vader_array_offset(_a16_slotarr) + (size_t) l6];
        vader_emit_bytecode$visit_type(t2, l0, l2);
        l6 = (l6 + INT64_C(1));
    }
    l5 = std_collections$len__i32(l2);
    l6 = vader_array_length(((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_types));
    if (l5 == l6) {
        { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l5 = vader_array_length(((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_types));
    vader_array_t* _a17_arr = vader_array_new(27u, 0u, 7u, 580u);
    l3 = (void*) _a17_arr;
    vader_array_t* _a18_arr = vader_array_new(447u, 0u, 13u, 2319u);
    l4 = (void*) _a18_arr;
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        l12 = ((int32_t) (int64_t) l6);
        t3 = std_collections$Set$std_core$Contains$contains__i32(l2, l12);
        if (t3) {
            t4 = vader_array_length(((vader_array_t*) l4));
            l16 = ((int32_t) (int64_t) t4);
            vader_array_push_i32((vader_array_t*) l3, l16);
            vader_array_t* _a19_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_types);
            VADER_ARRAY_RESOLVE_BUF(_a19_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a19_slotarr, l6)
            l17 = vader_array_ref_load_box(_a19_slotarr->buf, vader_array_offset(_a19_slotarr) + (size_t) l6);
            vader_array_push_ref((vader_array_t*) l4, l17.payload.obj);
        } else {
            vader_array_push_i32((vader_array_t*) l3, INT32_C(-1));
        }
        l6 = (l6 + INT64_C(1));
    }
    l2 = l4;
    vader_struct___lambda_env_vader_emit_bytecode_3_t* _a20_obj = (vader_struct___lambda_env_vader_emit_bytecode_3_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_emit_bytecode_3_t));
    vader_obj_header_init(_a20_obj, 626u);
    _a20_obj->f_cap_0 = l3;
    l4 = (void*) _a20_obj;
    t4 = vader_array_length(((vader_array_t*) l2));
    vader_array_t* _a21_arr = vader_array_reserve(447u, (int64_t) t4, 13u, 2319u);
    l7 = (void*) _a21_arr;
    l5 = vader_array_length(((vader_array_t*) l2));
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a22_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a22_slotarr)
        l17 = vader_array_ref_load_box(_a22_slotarr->buf, vader_array_offset(_a22_slotarr) + (size_t) l6);
        l18 = __lambda_vader_emit_bytecode_2(l4, l17);
        vader_array_push_ref((vader_array_t*) l7, l18.payload.obj);
        l6 = (l6 + INT64_C(1));
    }
    ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_types = l7;
    VADER_WRITE_BARRIER((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0);
    vader_array_t* _a23_arr = vader_array_new(26u, 0u, 0u, 577u);
    l2 = (void*) _a23_arr;
    vader_array_t* _a24_arr = vader_array_new(27u, 0u, 7u, 580u);
    l4 = (void*) _a24_arr;
    vader_array_t* _a25_arr = vader_array_new(27u, 0u, 7u, 580u);
    l7 = (void*) _a25_arr;
    vader_struct_std_collections$Map__string__i32_t* _a26_obj = (vader_struct_std_collections$Map__string__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__i32_t));
    vader_obj_header_init(_a26_obj, 902u);
    _a26_obj->f_ekeys = l2;
    _a26_obj->f_evals = l4;
    _a26_obj->f_index = l7;
    _a26_obj->f_mask = INT64_C(0);
    _a26_obj->f_grow_at = INT64_C(0);
    _a26_obj->f_size = INT64_C(0);
    _a26_obj->f_tombs = INT64_C(0);
    l2 = (void*) _a26_obj;
    l4 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_type_key;
    l7 = ((vader_struct_std_collections$Map__string__i32_t*) l4)->f_ekeys;
    l8 = ((vader_struct_std_collections$Map__string__i32_t*) l4)->f_evals;
    l5 = INT64_C(0);
    l6 = ((vader_struct_std_collections$Map__string__i32_t*) l4)->f_size;
    while ((l5 < l6)) {
        vader_array_t* _a27_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a27_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a27_slotarr, l5)
        t1 = vader_array_box_slots(_a27_slotarr->buf)[vader_array_offset(_a27_slotarr) + (size_t) l5];
        l19 = t1.payload.s;
        vader_array_t* _a28_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a28_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a28_slotarr, l5)
        l12 = ((int32_t*) _a28_slotarr->buf->slots)[vader_array_offset(_a28_slotarr) + (size_t) l5];
        l20 = l19;
        l16 = l12;
        l21 = vader_emit_bytecode$remap_idx(l3, l16);
        if ((l21 >= INT32_C(0))) {
            std_collections$Map$std_core$IndexSet$set_at__string__i32(l2, l20, l21);
        }
        l5 = (l5 + INT64_C(1));
    }
    ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_type_key = l2;
    VADER_WRITE_BARRIER((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0);
    l2 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_functions;
    l5 = vader_array_length(((vader_array_t*) l2));
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a29_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a29_slotarr)
        l4 = vader_array_ref_load_obj(_a29_slotarr->buf, vader_array_offset(_a29_slotarr) + (size_t) l6);
        l7 = vader_emit_bytecode$remap_signature(((vader_struct_vader_core_bytecode$BcFunction_t*) l4)->f_signature, l3);
        ((vader_struct_vader_core_bytecode$BcFunction_t*) l4)->f_signature = l7;
        VADER_WRITE_BARRIER((vader_struct_vader_core_bytecode$BcFunction_t*) l4);
        l10 = INT64_C(0);
        l11 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l4)->f_body));
        while ((l10 < l11)) {
            l8 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l4)->f_body;
            vader_array_t* _a30_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l4)->f_body);
            VADER_ARRAY_RESOLVE_BUF(_a30_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a30_slotarr, l10)
            t1 = vader_array_ref_load_box(_a30_slotarr->buf, vader_array_offset(_a30_slotarr) + (size_t) l10);
            l17 = vader_emit_bytecode$remap_type_in_op(t1, l3);
            vader_array_t* _a31_slotarr = ((vader_array_t*) l8);
            VADER_ARRAY_RESOLVE_BUF(_a31_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a31_slotarr, l10)
            vader_array_ref_store(_a31_slotarr->buf, vader_array_offset(_a31_slotarr) + (size_t) l10, l17.payload.obj);
            VADER_WRITE_BARRIER(_a31_slotarr->buf);
            l10 = (l10 + INT64_C(1));
        }
        l6 = (l6 + INT64_C(1));
    }
    t4 = vader_array_length(((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_imports));
    vader_array_t* _a32_arr = vader_array_reserve(105u, (int64_t) t4, 13u, 1184u);
    l2 = (void*) _a32_arr;
    l4 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_imports;
    l5 = vader_array_length(((vader_array_t*) l4));
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a33_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a33_slotarr)
        l7 = vader_array_ref_load_obj(_a33_slotarr->buf, vader_array_offset(_a33_slotarr) + (size_t) l6);
        l8 = l7;
        l19 = ((vader_struct_vader_core_bytecode$BcImport_t*) l8)->f_extern_name;
        l20 = ((vader_struct_vader_core_bytecode$BcImport_t*) l8)->f_mangled_name;
        l9 = vader_emit_bytecode$remap_signature(((vader_struct_vader_core_bytecode$BcImport_t*) l7)->f_signature, l3);
        l22 = ((vader_struct_vader_core_bytecode$BcImport_t*) l8)->f_is_extern;
        l23 = ((vader_struct_vader_core_bytecode$BcImport_t*) l8)->f_intrinsic;
        l13 = ((vader_struct_vader_core_bytecode$BcImport_t*) l8)->f_c_headers;
        l17 = ((vader_struct_vader_core_bytecode$BcImport_t*) l8)->f_library;
        l12 = ((vader_struct_vader_core_bytecode$BcImport_t*) l8)->f_c_variadic_fixed;
        l24 = ((vader_struct_vader_core_bytecode$BcImport_t*) l8)->f_param_c_types;
        l25 = ((vader_struct_vader_core_bytecode$BcImport_t*) l8)->f_result_c_type;
        l26 = ((vader_struct_vader_core_bytecode$BcImport_t*) l8)->f_blocking;
        vader_struct_vader_core_bytecode$BcImport_t* _a34_obj = (vader_struct_vader_core_bytecode$BcImport_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcImport_t));
        vader_obj_header_init(_a34_obj, 1184u);
        _a34_obj->f_extern_name = l19;
        _a34_obj->f_mangled_name = l20;
        _a34_obj->f_signature = l9;
        _a34_obj->f_is_extern = l22;
        _a34_obj->f_intrinsic = l23;
        _a34_obj->f_c_headers = l13;
        _a34_obj->f_library = l17;
        _a34_obj->f_c_variadic_fixed = l12;
        _a34_obj->f_param_c_types = l24;
        _a34_obj->f_result_c_type = l25;
        _a34_obj->f_blocking = l26;
        l27 = (void*) _a34_obj;
        vader_array_push_ref((vader_array_t*) l2, l27);
        l6 = (l6 + INT64_C(1));
    }
    ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_imports = l2;
    VADER_WRITE_BARRIER((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0);
    l2 = vader_emit_bytecode$remap_globals(((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_globals, l3);
    ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_globals = l2;
    VADER_WRITE_BARRIER((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0);
    t0 = vader_emit_bytecode$remap_data_pool(l1, l3);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_emit_bytecode$push_emit(void* l0, vader_box_t l1, void* l2) {
    void* l3 = NULL;
    vader_box_t l4 = vader_box_null();
    bool t0;
    vader_box_t* gc_roots[2] = { &l1, &l4 };
    void** gc_raw_roots[3] = { &l0, &l2, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_push_ref((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_slot)->f_body, l1.payload.obj);
    l3 = ((vader_struct_vader_core_bytecode$BcFunction_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_slot)->f_debug;
    t0 = ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_want_debug;
    if (t0) {
        l4 = vader_emit_bytecode$debug_pos_of_span(l2);
    } else {
        l4 = vader_box_obj(0u, NULL);
    }
    vader_array_push_ref((vader_array_t*) l3, l4.payload.obj);
    vader_array_push_i32((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_slot)->f_jump_table, INT32_C(-1));
    { vader_gc_top = gc_frame.prev; return; }
}

static int32_t vader_emit_bytecode$push_op_with_span(void* l0, vader_box_t l1, void* l2) {
    int32_t l3;
    void* l4 = NULL;
    vader_box_t l5 = vader_box_null();
    int64_t t0;
    bool t1;
    vader_box_t* gc_roots[2] = { &l1, &l5 };
    void** gc_raw_roots[3] = { &l0, &l2, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_slot)->f_body));
    l3 = ((int32_t) (int64_t) t0);
    vader_array_push_ref((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_slot)->f_body, l1.payload.obj);
    l4 = ((vader_struct_vader_core_bytecode$BcFunction_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_slot)->f_debug;
    t1 = ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_want_debug;
    if (t1) {
        l5 = vader_emit_bytecode$debug_pos_of_span(l2);
    } else {
        l5 = vader_box_obj(0u, NULL);
    }
    vader_array_push_ref((vader_array_t*) l4, l5.payload.obj);
    vader_array_push_i32((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_slot)->f_jump_table, INT32_C(-1));
    { int32_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_emit_bytecode$push_or_assign(void* l0, int64_t l1, vader_box_t l2) {
    int64_t l3;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = vader_array_length(((vader_array_t*) l0));
    if (l1 == l3) {
        vader_array_push_ref((vader_array_t*) l0, l2.payload.obj);
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    vader_array_ref_store(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l1, l2.payload.obj);
    VADER_WRITE_BARRIER(_a0_slotarr->buf);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_bytecode$push_scope(void* l0, void* l1, int64_t l2, vader_string_t l3, int32_t l4) {
    int64_t l5;
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_string_t* gc_atom_roots[1] = { &l3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l5 = vader_array_length(((vader_array_t*) l0));
    if (l2 == l5) {
        vader_array_push_scalar((vader_array_t*) l0, vader_box_string(577u, l3));
        vader_array_push_i32((vader_array_t*) l1, l4);
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
    vader_array_box_slots(_a0_slotarr->buf)[vader_array_offset(_a0_slotarr) + (size_t) l2] = vader_box_string(577u, l3);
    vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l2)
    ((int32_t*) _a1_slotarr->buf->slots)[vader_array_offset(_a1_slotarr) + (size_t) l2] = (int32_t) l4;
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_emit_bytecode$pushed_element_type(vader_box_t l0, vader_box_t l1) {
    void* l2;
    vader_box_t l3;
    l3 = vader_core_types$array_backing(l0);
    if (l3.tag == 0u) {
        return l1;
    }
    l2 = l3.payload.obj;
    return ((vader_struct_vader_core_types$ArrayType_t*) l2)->f_element;
}

static bool vader_emit_bytecode$ranges_overlap(void* l0, void* l1) {
    int32_t l2, l3;
    l2 = ((vader_struct_vader_emit_bytecode$SlotRange_t*) l0)->f_first;
    l3 = ((vader_struct_vader_emit_bytecode$SlotRange_t*) l1)->f_last;
    if ((l2 <= l3)) {
        l2 = ((vader_struct_vader_emit_bytecode$SlotRange_t*) l1)->f_first;
        l3 = ((vader_struct_vader_emit_bytecode$SlotRange_t*) l0)->f_last;
        return (l2 <= l3);
    }
    return false;
}

static void vader_emit_bytecode$record_slot_type(void* l0, int32_t l1, vader_box_t l2) {
    int64_t l3, l4;
    bool l5;
    void* l6 = NULL;
    void* l7 = NULL;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[4] = { &l0, &l6, &l7, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = vader_array_length(((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_type_by_slot));
    l4 = ((int64_t) (int32_t) l1);
    l5 = (l3 <= l4);
    while (l5) {
        l6 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_type_by_slot;
        t0 = (void*) &vader_data_40;
        vader_array_t* _a0_slotarr = ((vader_array_t*) t0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l7 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) INT64_C(0));
        vader_array_push_ref((vader_array_t*) l6, l7);
        l5 = (l3 < l4);
        l3 = (l3 + INT64_C(1));
    }
    vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_type_by_slot);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l1)
    vader_array_ref_store(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l1, l2.payload.obj);
    VADER_WRITE_BARRIER(_a1_slotarr->buf);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_bytecode$refuse_shared_identity_test(vader_string_t l0, vader_box_t l1) {
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
    if (l1.tag == 1373u) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_vader_core_types$UnionType_t*) t0)->f_variants;
        l3 = vader_array_length(((vader_array_t*) l2));
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            l5 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l4);
            vader_emit_bytecode$refuse_shared_instance(l0, l5);
            l4 = (l4 + INT64_C(1));
        }
    } else {
        l5 = l1;
        vader_emit_bytecode$refuse_shared_instance(l0, l5);
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_bytecode$refuse_shared_instance(vader_string_t l0, vader_box_t l1) {
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
    if (!(l1.tag == 1364u)) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    t0 = l1.payload.obj;
    l2 = ((vader_struct_vader_core_types$StructType_t*) t0)->f_args;
    l3 = vader_array_length(((vader_array_t*) l2));
    l4 = INT64_C(0);
    for (;;) {
        if ((l4 < l3)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            l5 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l4);
            t1 = vader_core_types$kept_type_argument(l5);
            if (t1.tag == 0u) {
                t0 = l1.payload.obj;
                l6 = vader_core_types$display_type(vader_ref_box(t0));
                l7 = concat_5(2066u, l0, 1549u, l6, 1589u);
                l8 = vader_core_types$display_type(l5);
                l9 = concat_3(2470u, l8, 1267u);
                t2 = concat_3(l7, 1913u, l9);
                vader_host_std_core$Intrinsic$panic(t2);
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

vader_box_t vader_emit_bytecode$remap_data_entry(vader_box_t l0, void* l1) {
    void* t0 = NULL;
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[3] = { &l1, &t0, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (!(l0.tag == 1177u)) {
        { vader_box_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l0.payload.obj;
    t1 = vader_emit_bytecode$remap_data_values(((vader_struct_vader_core_bytecode$BcAggregateData_t*) t0)->f_elements, l1);
    vader_struct_vader_core_bytecode$BcAggregateData_t* _a0_obj = (vader_struct_vader_core_bytecode$BcAggregateData_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcAggregateData_t));
    vader_obj_header_init(_a0_obj, 1177u);
    _a0_obj->f_elements = t1;
    t0 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_emit_bytecode$remap_data_pool(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    int64_t l5, l6;
    vader_box_t l7 = vader_box_null(), l8 = vader_box_null();
    int64_t t0;
    vader_box_t* gc_roots[2] = { &l7, &l8 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = l0;
    vader_struct___lambda_env_vader_emit_bytecode_7_t* _a0_obj = (vader_struct___lambda_env_vader_emit_bytecode_7_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_emit_bytecode_7_t));
    vader_obj_header_init(_a0_obj, 628u);
    _a0_obj->f_cap_0 = l1;
    l3 = (void*) _a0_obj;
    t0 = vader_array_length(((vader_array_t*) l2));
    vader_array_t* _a1_arr = vader_array_reserve(446u, (int64_t) t0, 13u, 2318u);
    l4 = (void*) _a1_arr;
    l5 = vader_array_length(((vader_array_t*) l2));
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        l7 = vader_array_ref_load_box(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l6);
        l8 = __lambda_vader_emit_bytecode_6(l3, l7);
        vader_array_push_ref((vader_array_t*) l4, l8.payload.obj);
        l6 = (l6 + INT64_C(1));
    }
    { void* __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_emit_bytecode$remap_data_value(vader_box_t l0, void* l1) {
    vader_box_t l2 = vader_box_null();
    int32_t l3;
    void* l4 = NULL;
    void* t0 = NULL;
    vader_box_t* gc_roots[2] = { &l0, &l2 };
    void** gc_raw_roots[3] = { &l1, &l4, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 1196u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_core_bytecode$BcValStruct_t*) t0)->f_symbol_id;
        t0 = l0.payload.obj;
        l4 = vader_emit_bytecode$remap_data_values(((vader_struct_vader_core_bytecode$BcValStruct_t*) t0)->f_fields, l1);
        vader_struct_vader_core_bytecode$BcValStruct_t* _a0_obj = (vader_struct_vader_core_bytecode$BcValStruct_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcValStruct_t));
        vader_obj_header_init(_a0_obj, 1196u);
        _a0_obj->f_symbol_id = l3;
        _a0_obj->f_fields = l4;
        t0 = (void*) _a0_obj;
        l2 = vader_ref_box(t0);
        { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1193u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_core_bytecode$BcValArray_t*) t0)->f_type_id;
        l3 = vader_emit_bytecode$remap_idx(l1, l3);
        t0 = l0.payload.obj;
        l4 = vader_emit_bytecode$remap_data_values(((vader_struct_vader_core_bytecode$BcValArray_t*) t0)->f_elements, l1);
        vader_struct_vader_core_bytecode$BcValArray_t* _a1_obj = (vader_struct_vader_core_bytecode$BcValArray_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcValArray_t));
        vader_obj_header_init(_a1_obj, 1193u);
        _a1_obj->f_type_id = l3;
        _a1_obj->f_elements = l4;
        t0 = (void*) _a1_obj;
        l2 = vader_ref_box(t0);
    } else {
        if (!((l0.tag == 1194u || l0.tag == 1195u))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l2 = l0;
    }
    { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_emit_bytecode$remap_data_values(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    int64_t l5, l6;
    vader_box_t l7 = vader_box_null(), l8 = vader_box_null();
    int64_t t0;
    vader_box_t* gc_roots[2] = { &l7, &l8 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = l0;
    vader_struct___lambda_env_vader_emit_bytecode_11_t* _a0_obj = (vader_struct___lambda_env_vader_emit_bytecode_11_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_emit_bytecode_11_t));
    vader_obj_header_init(_a0_obj, 622u);
    _a0_obj->f_cap_0 = l1;
    l3 = (void*) _a0_obj;
    t0 = vader_array_length(((vader_array_t*) l2));
    vader_array_t* _a1_arr = vader_array_reserve(448u, (int64_t) t0, 13u, 2329u);
    l4 = (void*) _a1_arr;
    l5 = vader_array_length(((vader_array_t*) l2));
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        l7 = vader_array_ref_load_box(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l6);
        l8 = __lambda_vader_emit_bytecode_10(l3, l7);
        vader_array_push_ref((vader_array_t*) l4, l8.payload.obj);
        l6 = (l6 + INT64_C(1));
    }
    { void* __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_emit_bytecode$remap_debug(void* l0, void* l1, int64_t l2) {
    void* l3 = NULL;
    int64_t l4, l5, l7;
    int32_t l6;
    vader_box_t l8 = vader_box_null();
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l8, &t1 };
    void** gc_raw_roots[4] = { &l0, &l1, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(449u, 1u, 13u, 2355u);
    ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = vader_box_obj(0u, NULL).payload.obj;
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l2);
    l3 = (void*) _a1_arr;
    l4 = INT64_C(0);
    l5 = vader_array_length(((vader_array_t*) l0));
    while ((l4 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        l6 = ((int32_t*) _a2_slotarr->buf->slots)[vader_array_offset(_a2_slotarr) + (size_t) l4];
        if ((l6 < INT32_C(0))) {
            l4 = (l4 + INT64_C(1));
            continue;
        }
        l7 = ((int64_t) (int32_t) l6);
        if ((l7 < l2)) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l7)
            t1 = vader_array_ref_load_box(_a3_slotarr->buf, vader_array_offset(_a3_slotarr) + (size_t) l7);
            if (t1.tag == 0u) {
                vader_array_t* _a4_slotarr = ((vader_array_t*) l0);
                VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                l8 = vader_array_ref_load_box(_a4_slotarr->buf, vader_array_offset(_a4_slotarr) + (size_t) l4);
                vader_array_t* _a5_slotarr = ((vader_array_t*) l3);
                VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l7)
                vader_array_ref_store(_a5_slotarr->buf, vader_array_offset(_a5_slotarr) + (size_t) l7, l8.payload.obj);
                VADER_WRITE_BARRIER(_a5_slotarr->buf);
            }
        }
        l4 = (l4 + INT64_C(1));
    }
    { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_emit_bytecode$remap_globals(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    int64_t l5, l6;
    int64_t t0;
    void** gc_raw_roots[7] = { &l0, &l1, &l2, &l3, &l4, &l7, &l8 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 7u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = l0;
    vader_struct___lambda_env_vader_emit_bytecode_5_t* _a0_obj = (vader_struct___lambda_env_vader_emit_bytecode_5_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_emit_bytecode_5_t));
    vader_obj_header_init(_a0_obj, 627u);
    _a0_obj->f_cap_0 = l1;
    l3 = (void*) _a0_obj;
    t0 = vader_array_length(((vader_array_t*) l2));
    vader_array_t* _a1_arr = vader_array_reserve(104u, (int64_t) t0, 13u, 1183u);
    l4 = (void*) _a1_arr;
    l5 = vader_array_length(((vader_array_t*) l2));
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        l7 = vader_array_ref_load_obj(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l6);
        l8 = __lambda_vader_emit_bytecode_4(l3, l7);
        vader_array_push_ref((vader_array_t*) l4, l8);
        l6 = (l6 + INT64_C(1));
    }
    { void* __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
}

int32_t vader_emit_bytecode$remap_idx(void* l0, int32_t l1) {
    int64_t l2, l3;
    int32_t t0;
    if ((l1 < INT32_C(0))) {
        return l1;
    }
    l2 = ((int64_t) (int32_t) l1);
    l3 = vader_array_length(((vader_array_t*) l0));
    if (!((l2 >= l3))) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
        t0 = ((int32_t*) _a0_slotarr->buf->slots)[vader_array_offset(_a0_slotarr) + (size_t) l1];
        return t0;
    }
    return INT32_C(-1);
}

static vader_box_t vader_emit_bytecode$remap_push_cache_slot(vader_box_t l0, void* l1) {
    bool l2;
    int64_t l3, l4;
    int32_t l5, l6;
    void* t0 = NULL;
    int32_t t1;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[2] = { &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (!(l0.tag == 1170u)) {
        { vader_box_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l0.payload.obj;
    t1 = ((vader_struct_vader_core_bytecode$ArrayPush_t*) t0)->f_cache_slot;
    if ((t1 < INT32_C(0))) {
        l2 = true;
    } else {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_core_bytecode$ArrayPush_t*) t0)->f_cache_slot;
        l3 = ((int64_t) (int32_t) t1);
        l4 = vader_array_length(((vader_array_t*) l1));
        l2 = (l3 >= l4);
    }
    if (!(l2)) {
        t0 = l0.payload.obj;
        l5 = ((vader_struct_vader_core_bytecode$ArrayPush_t*) t0)->f_type_id;
        t0 = l0.payload.obj;
        l6 = ((vader_struct_vader_core_bytecode$ArrayPush_t*) t0)->f_cache_slot;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l6)
        l6 = ((int32_t*) _a0_slotarr->buf->slots)[vader_array_offset(_a0_slotarr) + (size_t) l6];
        vader_struct_vader_core_bytecode$ArrayPush_t* _a1_obj = (vader_struct_vader_core_bytecode$ArrayPush_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$ArrayPush_t));
        vader_obj_header_init(_a1_obj, 1170u);
        _a1_obj->f_type_id = l5;
        _a1_obj->f_cache_slot = l6;
        t0 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l0.payload.obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_emit_bytecode$remap_signature(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[10] = { &l0, &l1, &l2, &l3, &l4, &l5, &l6, &l7, &l8, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 10u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = l0;
    l3 = ((vader_struct_vader_core_bytecode$BcSignature_t*) l2)->f_params;
    l4 = ((vader_struct_vader_core_bytecode$BcSignature_t*) l2)->f_results;
    l5 = ((vader_struct_vader_core_bytecode$BcSignature_t*) l0)->f_param_types;
    l5 = vader_emit_bytecode$remap_type_indices(l1, l5);
    l6 = ((vader_struct_vader_core_bytecode$BcSignature_t*) l0)->f_result_types;
    l6 = vader_emit_bytecode$remap_type_indices(l1, l6);
    l7 = ((vader_struct_vader_core_bytecode$BcSignature_t*) l2)->f_param_names;
    l8 = ((vader_struct_vader_core_bytecode$BcSignature_t*) l2)->f_param_c_out;
    l2 = ((vader_struct_vader_core_bytecode$BcSignature_t*) l2)->f_param_by_address;
    vader_struct_vader_core_bytecode$BcSignature_t* _a0_obj = (vader_struct_vader_core_bytecode$BcSignature_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcSignature_t));
    vader_obj_header_init(_a0_obj, 1189u);
    _a0_obj->f_params = l3;
    _a0_obj->f_results = l4;
    _a0_obj->f_param_types = l5;
    _a0_obj->f_result_types = l6;
    _a0_obj->f_param_names = l7;
    _a0_obj->f_param_c_out = l8;
    _a0_obj->f_param_by_address = l2;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_emit_bytecode$remap_type(vader_box_t l0, void* l1) {
    vader_box_t l2 = vader_box_null();
    void* l3 = NULL;
    void* l4 = NULL;
    void* l7 = NULL;
    void* l11 = NULL;
    int64_t l5, l6;
    vader_string_t l8 = 0;
    vader_string_t l12 = 0;
    int32_t l9, l10;
    bool l13;
    void* t0 = NULL;
    int32_t t1;
    vader_box_t* gc_roots[2] = { &l0, &l2 };
    void** gc_raw_roots[6] = { &l1, &l3, &l4, &l7, &l11, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l8, &l12 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if ((l0.tag == 1187u || l0.tag == 1188u)) {
        l2 = l0;
        { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1191u) {
        vader_array_t* _a0_arr = vader_array_new(102u, 0u, 13u, 1180u);
        l3 = (void*) _a0_arr;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_core_bytecode$BcStruct_t*) t0)->f_fields;
        l5 = vader_array_length(((vader_array_t*) l4));
        l6 = INT64_C(0);
        while ((l6 < l5)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l4);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            l7 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l6);
            l8 = ((vader_struct_vader_core_bytecode$BcField_t*) l7)->f_name;
            l9 = ((vader_struct_vader_core_bytecode$BcField_t*) l7)->f_type_index;
            l10 = vader_emit_bytecode$remap_idx(l1, l9);
            vader_struct_vader_core_bytecode$BcField_t* _a2_obj = (vader_struct_vader_core_bytecode$BcField_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcField_t));
            vader_obj_header_init(_a2_obj, 1180u);
            _a2_obj->f_name = l8;
            _a2_obj->f_type_index = l10;
            l11 = (void*) _a2_obj;
            vader_array_push_ref((vader_array_t*) l3, l11);
            l6 = (l6 + INT64_C(1));
        }
        l4 = l0.payload.obj;
        l8 = ((vader_struct_vader_core_bytecode$BcStruct_t*) l4)->f_name;
        l12 = ((vader_struct_vader_core_bytecode$BcStruct_t*) l4)->f_c_name;
        l9 = ((vader_struct_vader_core_bytecode$BcStruct_t*) l4)->f_symbol_id;
        l13 = ((vader_struct_vader_core_bytecode$BcStruct_t*) l4)->f_shared;
        vader_struct_vader_core_bytecode$BcStruct_t* _a3_obj = (vader_struct_vader_core_bytecode$BcStruct_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcStruct_t));
        vader_obj_header_init(_a3_obj, 1191u);
        _a3_obj->f_name = l8;
        _a3_obj->f_fields = l3;
        _a3_obj->f_c_name = l12;
        _a3_obj->f_symbol_id = l9;
        _a3_obj->f_shared = l13;
        t0 = (void*) _a3_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1178u) {
        t0 = l0.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$BcArray_t*) t0)->f_element;
        t1 = vader_emit_bytecode$remap_idx(l1, l9);
        vader_struct_vader_core_bytecode$BcArray_t* _a4_obj = (vader_struct_vader_core_bytecode$BcArray_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcArray_t));
        vader_obj_header_init(_a4_obj, 1178u);
        _a4_obj->f_element = t1;
        t0 = (void*) _a4_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1192u) {
        vader_array_t* _a5_arr = vader_array_new(27u, 0u, 7u, 580u);
        l3 = (void*) _a5_arr;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_core_bytecode$BcUnion_t*) t0)->f_variants;
        l5 = vader_array_length(((vader_array_t*) l4));
        l6 = INT64_C(0);
        vader_array_t* _pc103_hdr = (vader_array_t*) l3;
        size_t _pc103_len = vader_array_length(_pc103_hdr);
        size_t _pc103_cap = vader_array_is_borrowed(_pc103_hdr) ? (size_t) 0 : vader_array_capacity(_pc103_hdr);
        void* _pc103_slots = _pc103_hdr->buf->slots;
        for (;;) {
            if ((l6 < l5)) {
                vader_array_t* _a6_slotarr = ((vader_array_t*) l4);
                VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
                l9 = ((int32_t*) _a6_slotarr->buf->slots)[vader_array_offset(_a6_slotarr) + (size_t) l6];
                l10 = vader_emit_bytecode$remap_idx(l1, l9);
                if (VADER_LIKELY(_pc103_len < _pc103_cap)) {
                    ((int32_t*) _pc103_slots)[_pc103_len] = (int32_t) (l10);
                    _pc103_len += 1;
                } else {
                    vader_array_set_length(_pc103_hdr, _pc103_len);
                    if (_pc103_hdr->buf->length < _pc103_len) {
                        _pc103_hdr->buf->length = _pc103_len;
                    }
                    vader_array_push_i32((vader_array_t*) l3, l10);
                    _pc103_hdr = (vader_array_t*) l3;
                    _pc103_len = vader_array_length(_pc103_hdr);
                    _pc103_cap = vader_array_is_borrowed(_pc103_hdr) ? (size_t) 0 : vader_array_capacity(_pc103_hdr);
                    _pc103_slots = _pc103_hdr->buf->slots;
                }
                l6 = (l6 + INT64_C(1));
                continue;
            }
            vader_array_set_length(_pc103_hdr, _pc103_len);
            if (_pc103_hdr->buf->length < _pc103_len) {
                _pc103_hdr->buf->length = _pc103_len;
            }
            break;
        }
        vader_struct_vader_core_bytecode$BcUnion_t* _a7_obj = (vader_struct_vader_core_bytecode$BcUnion_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcUnion_t));
        vader_obj_header_init(_a7_obj, 1192u);
        _a7_obj->f_variants = l3;
        t0 = (void*) _a7_obj;
        l2 = vader_ref_box(t0);
    } else {
        if (!(l0.tag == 1181u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        vader_array_t* _a8_arr = vader_array_new(27u, 0u, 7u, 580u);
        l3 = (void*) _a8_arr;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_core_bytecode$BcFn_t*) t0)->f_params;
        l5 = vader_array_length(((vader_array_t*) l4));
        l6 = INT64_C(0);
        vader_array_t* _pc146_hdr = (vader_array_t*) l3;
        size_t _pc146_len = vader_array_length(_pc146_hdr);
        size_t _pc146_cap = vader_array_is_borrowed(_pc146_hdr) ? (size_t) 0 : vader_array_capacity(_pc146_hdr);
        void* _pc146_slots = _pc146_hdr->buf->slots;
        for (;;) {
            if ((l6 < l5)) {
                vader_array_t* _a9_slotarr = ((vader_array_t*) l4);
                VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
                l9 = ((int32_t*) _a9_slotarr->buf->slots)[vader_array_offset(_a9_slotarr) + (size_t) l6];
                l10 = vader_emit_bytecode$remap_idx(l1, l9);
                if (VADER_LIKELY(_pc146_len < _pc146_cap)) {
                    ((int32_t*) _pc146_slots)[_pc146_len] = (int32_t) (l10);
                    _pc146_len += 1;
                } else {
                    vader_array_set_length(_pc146_hdr, _pc146_len);
                    if (_pc146_hdr->buf->length < _pc146_len) {
                        _pc146_hdr->buf->length = _pc146_len;
                    }
                    vader_array_push_i32((vader_array_t*) l3, l10);
                    _pc146_hdr = (vader_array_t*) l3;
                    _pc146_len = vader_array_length(_pc146_hdr);
                    _pc146_cap = vader_array_is_borrowed(_pc146_hdr) ? (size_t) 0 : vader_array_capacity(_pc146_hdr);
                    _pc146_slots = _pc146_hdr->buf->slots;
                }
                l6 = (l6 + INT64_C(1));
                continue;
            }
            vader_array_set_length(_pc146_hdr, _pc146_len);
            if (_pc146_hdr->buf->length < _pc146_len) {
                _pc146_hdr->buf->length = _pc146_len;
            }
            break;
        }
        t0 = l0.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$BcFn_t*) t0)->f_return_type;
        l9 = vader_emit_bytecode$remap_idx(l1, l9);
        vader_struct_vader_core_bytecode$BcFn_t* _a10_obj = (vader_struct_vader_core_bytecode$BcFn_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcFn_t));
        vader_obj_header_init(_a10_obj, 1181u);
        _a10_obj->f_params = l3;
        _a10_obj->f_return_type = l9;
        t0 = (void*) _a10_obj;
        l2 = vader_ref_box(t0);
    }
    { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_emit_bytecode$remap_type_in_op(vader_box_t l0, void* l1) {
    vader_box_t l2 = vader_box_null();
    void* l3 = NULL;
    int32_t l4, l6, l7;
    bool l5;
    void* t0 = NULL;
    int32_t t1;
    vader_box_t* gc_roots[2] = { &l0, &l2 };
    void** gc_raw_roots[3] = { &l1, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 1322u) {
        l3 = l0.payload.obj;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_core_bytecode$StructNew_t*) t0)->f_type_id;
        l4 = vader_emit_bytecode$remap_idx(l1, l4);
        l5 = ((vader_struct_vader_core_bytecode$StructNew_t*) l3)->f_stack;
        vader_struct_vader_core_bytecode$StructNew_t* _a0_obj = (vader_struct_vader_core_bytecode$StructNew_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$StructNew_t));
        vader_obj_header_init(_a0_obj, 1322u);
        _a0_obj->f_type_id = l4;
        _a0_obj->f_stack = l5;
        t0 = (void*) _a0_obj;
        l2 = vader_ref_box(t0);
        { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1321u) {
        l3 = l0.payload.obj;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_core_bytecode$StructGet_t*) t0)->f_type_id;
        l4 = vader_emit_bytecode$remap_idx(l1, l4);
        l6 = ((vader_struct_vader_core_bytecode$StructGet_t*) l3)->f_field_index;
        vader_struct_vader_core_bytecode$StructGet_t* _a1_obj = (vader_struct_vader_core_bytecode$StructGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$StructGet_t));
        vader_obj_header_init(_a1_obj, 1321u);
        _a1_obj->f_type_id = l4;
        _a1_obj->f_field_index = l6;
        t0 = (void*) _a1_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1323u) {
        l3 = l0.payload.obj;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_core_bytecode$StructSet_t*) t0)->f_type_id;
        l4 = vader_emit_bytecode$remap_idx(l1, l4);
        l6 = ((vader_struct_vader_core_bytecode$StructSet_t*) l3)->f_field_index;
        l5 = ((vader_struct_vader_core_bytecode$StructSet_t*) l3)->f_stack;
        vader_struct_vader_core_bytecode$StructSet_t* _a2_obj = (vader_struct_vader_core_bytecode$StructSet_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$StructSet_t));
        vader_obj_header_init(_a2_obj, 1323u);
        _a2_obj->f_type_id = l4;
        _a2_obj->f_field_index = l6;
        _a2_obj->f_stack = l5;
        t0 = (void*) _a2_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1338u) {
        l3 = l0.payload.obj;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_core_bytecode$UnionFieldGet_t*) t0)->f_type_id;
        l4 = vader_emit_bytecode$remap_idx(l1, l4);
        l6 = ((vader_struct_vader_core_bytecode$UnionFieldGet_t*) l3)->f_field_index;
        vader_struct_vader_core_bytecode$UnionFieldGet_t* _a3_obj = (vader_struct_vader_core_bytecode$UnionFieldGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$UnionFieldGet_t));
        vader_obj_header_init(_a3_obj, 1338u);
        _a3_obj->f_type_id = l4;
        _a3_obj->f_field_index = l6;
        t0 = (void*) _a3_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1339u) {
        l3 = l0.payload.obj;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_core_bytecode$UnionFieldSet_t*) t0)->f_type_id;
        l4 = vader_emit_bytecode$remap_idx(l1, l4);
        l6 = ((vader_struct_vader_core_bytecode$UnionFieldSet_t*) l3)->f_field_index;
        vader_struct_vader_core_bytecode$UnionFieldSet_t* _a4_obj = (vader_struct_vader_core_bytecode$UnionFieldSet_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$UnionFieldSet_t));
        vader_obj_header_init(_a4_obj, 1339u);
        _a4_obj->f_type_id = l4;
        _a4_obj->f_field_index = l6;
        t0 = (void*) _a4_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1169u) {
        l3 = l0.payload.obj;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_core_bytecode$ArrayNew_t*) t0)->f_type_id;
        l4 = vader_emit_bytecode$remap_idx(l1, l4);
        l6 = ((vader_struct_vader_core_bytecode$ArrayNew_t*) l3)->f_length;
        vader_struct_vader_core_bytecode$ArrayNew_t* _a5_obj = (vader_struct_vader_core_bytecode$ArrayNew_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$ArrayNew_t));
        vader_obj_header_init(_a5_obj, 1169u);
        _a5_obj->f_type_id = l4;
        _a5_obj->f_length = l6;
        t0 = (void*) _a5_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1167u) {
        l3 = l0.payload.obj;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_core_bytecode$ArrayGet_t*) t0)->f_type_id;
        l4 = vader_emit_bytecode$remap_idx(l1, l4);
        l5 = ((vader_struct_vader_core_bytecode$ArrayGet_t*) l3)->f_bounds_safe;
        vader_struct_vader_core_bytecode$ArrayGet_t* _a6_obj = (vader_struct_vader_core_bytecode$ArrayGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$ArrayGet_t));
        vader_obj_header_init(_a6_obj, 1167u);
        _a6_obj->f_type_id = l4;
        _a6_obj->f_bounds_safe = l5;
        t0 = (void*) _a6_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1175u) {
        l3 = l0.payload.obj;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_core_bytecode$ArraySet_t*) t0)->f_type_id;
        l4 = vader_emit_bytecode$remap_idx(l1, l4);
        l5 = ((vader_struct_vader_core_bytecode$ArraySet_t*) l3)->f_bounds_safe;
        vader_struct_vader_core_bytecode$ArraySet_t* _a7_obj = (vader_struct_vader_core_bytecode$ArraySet_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$ArraySet_t));
        vader_obj_header_init(_a7_obj, 1175u);
        _a7_obj->f_type_id = l4;
        _a7_obj->f_bounds_safe = l5;
        t0 = (void*) _a7_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1170u) {
        l3 = l0.payload.obj;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_core_bytecode$ArrayPush_t*) t0)->f_type_id;
        l4 = vader_emit_bytecode$remap_idx(l1, l4);
        l6 = ((vader_struct_vader_core_bytecode$ArrayPush_t*) l3)->f_cache_slot;
        vader_struct_vader_core_bytecode$ArrayPush_t* _a8_obj = (vader_struct_vader_core_bytecode$ArrayPush_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$ArrayPush_t));
        vader_obj_header_init(_a8_obj, 1170u);
        _a8_obj->f_type_id = l4;
        _a8_obj->f_cache_slot = l6;
        t0 = (void*) _a8_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1324u) {
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_core_bytecode$TypeCheck_t*) t0)->f_type_id;
        t1 = vader_emit_bytecode$remap_idx(l1, l4);
        vader_struct_vader_core_bytecode$TypeCheck_t* _a9_obj = (vader_struct_vader_core_bytecode$TypeCheck_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$TypeCheck_t));
        vader_obj_header_init(_a9_obj, 1324u);
        _a9_obj->f_type_id = t1;
        t0 = (void*) _a9_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1325u) {
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_core_bytecode$TypeConst_t*) t0)->f_type_id;
        t1 = vader_emit_bytecode$remap_idx(l1, l4);
        vader_struct_vader_core_bytecode$TypeConst_t* _a10_obj = (vader_struct_vader_core_bytecode$TypeConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$TypeConst_t));
        vader_obj_header_init(_a10_obj, 1325u);
        _a10_obj->f_type_id = t1;
        t0 = (void*) _a10_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1215u) {
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_core_bytecode$CallIndirect_t*) t0)->f_type_id;
        t1 = vader_emit_bytecode$remap_idx(l1, l4);
        vader_struct_vader_core_bytecode$CallIndirect_t* _a11_obj = (vader_struct_vader_core_bytecode$CallIndirect_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$CallIndirect_t));
        vader_obj_header_init(_a11_obj, 1215u);
        _a11_obj->f_type_id = t1;
        t0 = (void*) _a11_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1299u) {
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_core_bytecode$MakeClosure_t*) t0)->f_function_index;
        t0 = l0.payload.obj;
        l6 = ((vader_struct_vader_core_bytecode$MakeClosure_t*) t0)->f_env_type_id;
        l6 = vader_emit_bytecode$remap_idx(l1, l6);
        vader_struct_vader_core_bytecode$MakeClosure_t* _a12_obj = (vader_struct_vader_core_bytecode$MakeClosure_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$MakeClosure_t));
        vader_obj_header_init(_a12_obj, 1299u);
        _a12_obj->f_function_index = l4;
        _a12_obj->f_env_type_id = l6;
        t0 = (void*) _a12_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1242u) {
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_core_bytecode$FnRef_t*) t0)->f_function_index;
        t0 = l0.payload.obj;
        l6 = ((vader_struct_vader_core_bytecode$FnRef_t*) t0)->f_type_id;
        l6 = vader_emit_bytecode$remap_idx(l1, l6);
        vader_struct_vader_core_bytecode$FnRef_t* _a13_obj = (vader_struct_vader_core_bytecode$FnRef_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$FnRef_t));
        vader_obj_header_init(_a13_obj, 1242u);
        _a13_obj->f_function_index = l4;
        _a13_obj->f_type_id = l6;
        t0 = (void*) _a13_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1294u) {
        l3 = l0.payload.obj;
        l4 = ((vader_struct_vader_core_bytecode$LocalField_t*) l3)->f_slot;
        t0 = l0.payload.obj;
        l6 = ((vader_struct_vader_core_bytecode$LocalField_t*) t0)->f_type_id;
        l6 = vader_emit_bytecode$remap_idx(l1, l6);
        l7 = ((vader_struct_vader_core_bytecode$LocalField_t*) l3)->f_field_index;
        vader_struct_vader_core_bytecode$LocalField_t* _a14_obj = (vader_struct_vader_core_bytecode$LocalField_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$LocalField_t));
        vader_obj_header_init(_a14_obj, 1294u);
        _a14_obj->f_slot = l4;
        _a14_obj->f_type_id = l6;
        _a14_obj->f_field_index = l7;
        t0 = (void*) _a14_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1176u) {
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_core_bytecode$ArraySlice_t*) t0)->f_type_id;
        t1 = vader_emit_bytecode$remap_idx(l1, l4);
        vader_struct_vader_core_bytecode$ArraySlice_t* _a15_obj = (vader_struct_vader_core_bytecode$ArraySlice_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$ArraySlice_t));
        vader_obj_header_init(_a15_obj, 1176u);
        _a15_obj->f_type_id = t1;
        t0 = (void*) _a15_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1174u) {
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_core_bytecode$ArrayReserve_t*) t0)->f_type_id;
        t1 = vader_emit_bytecode$remap_idx(l1, l4);
        vader_struct_vader_core_bytecode$ArrayReserve_t* _a16_obj = (vader_struct_vader_core_bytecode$ArrayReserve_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$ArrayReserve_t));
        vader_obj_header_init(_a16_obj, 1174u);
        _a16_obj->f_type_id = t1;
        t0 = (void*) _a16_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1303u) {
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_core_bytecode$RefCast_t*) t0)->f_type_id;
        t1 = vader_emit_bytecode$remap_idx(l1, l4);
        vader_struct_vader_core_bytecode$RefCast_t* _a17_obj = (vader_struct_vader_core_bytecode$RefCast_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$RefCast_t));
        vader_obj_header_init(_a17_obj, 1303u);
        _a17_obj->f_type_id = t1;
        t0 = (void*) _a17_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1306u) {
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_core_bytecode$Retag_t*) t0)->f_type_id;
        t1 = vader_emit_bytecode$remap_idx(l1, l4);
        vader_struct_vader_core_bytecode$Retag_t* _a18_obj = (vader_struct_vader_core_bytecode$Retag_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$Retag_t));
        vader_obj_header_init(_a18_obj, 1306u);
        _a18_obj->f_type_id = t1;
        t0 = (void*) _a18_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1220u) {
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_core_bytecode$DataConst_t*) t0)->f_pool_index;
        t0 = l0.payload.obj;
        l6 = ((vader_struct_vader_core_bytecode$DataConst_t*) t0)->f_type_id;
        l6 = vader_emit_bytecode$remap_idx(l1, l6);
        vader_struct_vader_core_bytecode$DataConst_t* _a19_obj = (vader_struct_vader_core_bytecode$DataConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$DataConst_t));
        vader_obj_header_init(_a19_obj, 1220u);
        _a19_obj->f_pool_index = l4;
        _a19_obj->f_type_id = l6;
        t0 = (void*) _a19_obj;
        l2 = vader_ref_box(t0);
    } else {
        if (!((l0.tag == 1165u || l0.tag == 1166u || l0.tag == 1168u || l0.tag == 1171u || l0.tag == 1172u || l0.tag == 1173u || l0.tag == 1197u || l0.tag == 1198u || l0.tag == 1199u || l0.tag == 1200u || l0.tag == 1201u || l0.tag == 1202u || l0.tag == 1203u || l0.tag == 1204u || l0.tag == 1205u || l0.tag == 1206u || l0.tag == 1207u || l0.tag == 1208u || l0.tag == 1209u || l0.tag == 1210u || l0.tag == 1213u || l0.tag == 1214u || l0.tag == 1216u || l0.tag == 1217u || l0.tag == 1218u || l0.tag == 1219u || l0.tag == 1222u || l0.tag == 1223u || l0.tag == 1224u || l0.tag == 1225u || l0.tag == 1226u || l0.tag == 1227u || l0.tag == 1228u || l0.tag == 1229u || l0.tag == 1230u || l0.tag == 1231u || l0.tag == 1232u || l0.tag == 1233u || l0.tag == 1234u || l0.tag == 1235u || l0.tag == 1236u || l0.tag == 1237u || l0.tag == 1238u || l0.tag == 1239u || l0.tag == 1240u || l0.tag == 1241u || l0.tag == 1243u || l0.tag == 1244u || l0.tag == 1245u || l0.tag == 1246u || l0.tag == 1247u || l0.tag == 1248u || l0.tag == 1249u || l0.tag == 1250u || l0.tag == 1251u || l0.tag == 1252u || l0.tag == 1253u || l0.tag == 1254u || l0.tag == 1255u || l0.tag == 1256u || l0.tag == 1257u || l0.tag == 1258u || l0.tag == 1259u || l0.tag == 1260u || l0.tag == 1261u || l0.tag == 1262u || l0.tag == 1263u || l0.tag == 1264u || l0.tag == 1265u || l0.tag == 1266u || l0.tag == 1267u || l0.tag == 1268u || l0.tag == 1269u || l0.tag == 1270u || l0.tag == 1271u || l0.tag == 1272u || l0.tag == 1273u || l0.tag == 1274u || l0.tag == 1275u || l0.tag == 1276u || l0.tag == 1277u || l0.tag == 1278u || l0.tag == 1279u || l0.tag == 1280u || l0.tag == 1281u || l0.tag == 1282u || l0.tag == 1283u || l0.tag == 1284u || l0.tag == 1285u || l0.tag == 1287u || l0.tag == 1288u || l0.tag == 1289u || l0.tag == 1290u || l0.tag == 1291u || l0.tag == 1292u || l0.tag == 1293u || l0.tag == 1295u || l0.tag == 1296u || l0.tag == 1297u || l0.tag == 1298u || l0.tag == 1301u || l0.tag == 1302u || l0.tag == 1304u || l0.tag == 1305u || l0.tag == 1307u || l0.tag == 1308u || l0.tag == 1309u || l0.tag == 1310u || l0.tag == 1311u || l0.tag == 1312u || l0.tag == 1313u || l0.tag == 1314u || l0.tag == 1315u || l0.tag == 1316u || l0.tag == 1317u || l0.tag == 1318u || l0.tag == 1319u || l0.tag == 1320u || l0.tag == 1326u || l0.tag == 1327u || l0.tag == 1328u || l0.tag == 1329u || l0.tag == 1330u || l0.tag == 1331u || l0.tag == 1332u || l0.tag == 1333u || l0.tag == 1334u || l0.tag == 1335u || l0.tag == 1336u || l0.tag == 1337u || l0.tag == 1340u || l0.tag == 1341u))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l2 = l0;
    }
    { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_emit_bytecode$remap_type_indices(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    int64_t l5, l6;
    int32_t l7, l8;
    int64_t t0;
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = l1;
    vader_struct___lambda_env_vader_emit_bytecode_9_t* _a0_obj = (vader_struct___lambda_env_vader_emit_bytecode_9_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_emit_bytecode_9_t));
    vader_obj_header_init(_a0_obj, 629u);
    _a0_obj->f_cap_0 = l0;
    l3 = (void*) _a0_obj;
    t0 = vader_array_length(((vader_array_t*) l2));
    vader_array_t* _a1_arr = vader_array_reserve(27u, (int64_t) t0, 7u, 580u);
    l4 = (void*) _a1_arr;
    l5 = vader_array_length(((vader_array_t*) l2));
    l6 = INT64_C(0);
    vader_array_t* _pc14_hdr = (vader_array_t*) l4;
    size_t _pc14_len = vader_array_length(_pc14_hdr);
    size_t _pc14_cap = vader_array_is_borrowed(_pc14_hdr) ? (size_t) 0 : vader_array_capacity(_pc14_hdr);
    void* _pc14_slots = _pc14_hdr->buf->slots;
    for (;;) {
        if ((l6 < l5)) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            l7 = ((int32_t*) _a2_slotarr->buf->slots)[vader_array_offset(_a2_slotarr) + (size_t) l6];
            l8 = __lambda_vader_emit_bytecode_8(l3, l7);
            if (VADER_LIKELY(_pc14_len < _pc14_cap)) {
                ((int32_t*) _pc14_slots)[_pc14_len] = (int32_t) (l8);
                _pc14_len += 1;
            } else {
                vader_array_set_length(_pc14_hdr, _pc14_len);
                if (_pc14_hdr->buf->length < _pc14_len) {
                    _pc14_hdr->buf->length = _pc14_len;
                }
                vader_array_push_i32((vader_array_t*) l4, l8);
                _pc14_hdr = (vader_array_t*) l4;
                _pc14_len = vader_array_length(_pc14_hdr);
                _pc14_cap = vader_array_is_borrowed(_pc14_hdr) ? (size_t) 0 : vader_array_capacity(_pc14_hdr);
                _pc14_slots = _pc14_hdr->buf->slots;
            }
            l6 = (l6 + INT64_C(1));
            continue;
        }
        vader_array_set_length(_pc14_hdr, _pc14_len);
        if (_pc14_hdr->buf->length < _pc14_len) {
            _pc14_hdr->buf->length = _pc14_len;
        }
        break;
    }
    { void* __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_emit_bytecode$reserve_cfg_extern(void* l0, void* l1) {
    void* l2 = NULL;
    void* l4 = NULL;
    void* l12 = NULL;
    void* l14 = NULL;
    vader_box_t l3 = vader_box_null();
    int32_t l5, l13;
    vader_string_t l6 = 0;
    vader_string_t l7 = 0;
    vader_string_t l10 = 0;
    bool l8, l9;
    uint8_t l11;
    int64_t t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &l3 };
    void** gc_raw_roots[7] = { &l0, &l1, &l2, &l4, &l12, &l14, &t1 };
    vader_string_t* gc_atom_roots[3] = { &l6, &l7, &l10 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_midir$CFGExternDecl_t*) l0)->f_params;
    l3 = ((vader_struct_vader_midir$CFGExternDecl_t*) l0)->f_return_type;
    vader_array_t* _a0_arr = vader_array_new(450u, 0u, 13u, 2396u);
    l4 = (void*) _a0_arr;
    l2 = vader_emit_bytecode$build_cfg_signature(l2, l3, l4, l1);
    l4 = ((vader_struct_vader_midir$CFGExternDecl_t*) l0)->f_origin;
    l2 = vader_emit_bytecode$with_param_decorators(l2, l4);
    t0 = vader_array_length(((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l1)->f_imports));
    l5 = ((int32_t) (int64_t) t0);
    l4 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l1)->f_imports;
    l6 = ((vader_struct_vader_midir$CFGExternDecl_t*) l0)->f_extern_name;
    l7 = ((vader_struct_vader_midir$CFGExternDecl_t*) l0)->f_mangled;
    l8 = ((vader_struct_vader_midir$CFGExternDecl_t*) l0)->f_is_extern;
    l9 = ((vader_struct_vader_midir$CFGExternDecl_t*) l0)->f_is_extern;
    l10 = ((vader_struct_vader_midir$CFGExternDecl_t*) l0)->f_intrinsic;
    l11 = vader_core_bytecode$import_intrinsic(l9, l10);
    l12 = ((vader_struct_vader_midir$CFGExternDecl_t*) l0)->f_c_headers;
    l3 = ((vader_struct_vader_midir$CFGExternDecl_t*) l0)->f_library;
    l13 = ((vader_struct_vader_midir$CFGExternDecl_t*) l0)->f_c_variadic_fixed;
    l14 = vader_emit_bytecode$param_c_types_of(((vader_struct_vader_midir$CFGExternDecl_t*) l0)->f_origin);
    l10 = vader_emit_bytecode$result_c_type_of(((vader_struct_vader_midir$CFGExternDecl_t*) l0)->f_origin);
    l9 = vader_emit_bytecode$blocking_of(((vader_struct_vader_midir$CFGExternDecl_t*) l0)->f_origin);
    vader_struct_vader_core_bytecode$BcImport_t* _a1_obj = (vader_struct_vader_core_bytecode$BcImport_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcImport_t));
    vader_obj_header_init(_a1_obj, 1184u);
    _a1_obj->f_extern_name = l6;
    _a1_obj->f_mangled_name = l7;
    _a1_obj->f_signature = l2;
    _a1_obj->f_is_extern = l8;
    _a1_obj->f_intrinsic = l11;
    _a1_obj->f_c_headers = l12;
    _a1_obj->f_library = l3;
    _a1_obj->f_c_variadic_fixed = l13;
    _a1_obj->f_param_c_types = l14;
    _a1_obj->f_result_c_type = l10;
    _a1_obj->f_blocking = l9;
    l2 = (void*) _a1_obj;
    vader_array_push_ref((vader_array_t*) l4, l2);
    l3 = ((vader_struct_vader_core_mono$MonoEntry_t*) ((vader_struct_vader_midir$CFGExternDecl_t*) l0)->f_origin)->f_symbol;
    if (l3.tag == 1346u) {
        l2 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l1)->f_import_index_by_symbol_id;
        t1 = l3.payload.obj;
        l13 = ((vader_struct_vader_core_symbol$Symbol_t*) t1)->f_id;
        std_collections$Map$std_core$IndexSet$set_at__i32__i32(l2, l13, l5);
    }
    l2 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l1)->f_import_index_by_mangle;
    l6 = ((vader_struct_vader_midir$CFGExternDecl_t*) l0)->f_mangled;
    std_collections$Map$std_core$IndexSet$set_at__string__i32(l2, l6, l5);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_bytecode$reserve_cfg_function(void* l0, void* l1) {
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
    vader_string_t t2 = 0;
    vader_box_t t3 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l3, &t3 };
    void** gc_raw_roots[10] = { &l0, &l1, &l2, &l4, &l6, &l7, &l8, &l9, &l12, &t1 };
    vader_string_t* gc_atom_roots[2] = { &l10, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 10u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_params;
    l3 = ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_return_type;
    l4 = ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_scalarised_results;
    l2 = vader_emit_bytecode$build_cfg_signature(l2, l3, l4, l1);
    t0 = vader_array_length(((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l1)->f_functions));
    l5 = ((int32_t) (int64_t) t0);
    vader_array_t* _a0_arr = vader_array_new(445u, 0u, 13u, 2295u);
    l4 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(449u, 0u, 13u, 2355u);
    l6 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(27u, 0u, 7u, 580u);
    l7 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(106u, 0u, 13u, 1185u);
    l8 = (void*) _a3_arr;
    l9 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l1)->f_functions;
    l10 = ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_mangled;
    l11 = ((vader_struct_vader_core_mono$MonoEntry_t*) ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_origin)->f_is_main;
    vader_array_t* _a4_arr = vader_array_new(27u, 0u, 7u, 580u);
    l12 = (void*) _a4_arr;
    vader_struct_vader_core_bytecode$BcFunction_t* _a5_obj = (vader_struct_vader_core_bytecode$BcFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcFunction_t));
    vader_obj_header_init(_a5_obj, 1182u);
    _a5_obj->f_name = l10;
    _a5_obj->f_is_main = l11;
    _a5_obj->f_signature = l2;
    _a5_obj->f_locals = l8;
    _a5_obj->f_body = l4;
    _a5_obj->f_debug = l6;
    _a5_obj->f_jump_table = l7;
    _a5_obj->f_source_pc = l12;
    l2 = (void*) _a5_obj;
    vader_array_push_ref((vader_array_t*) l9, l2);
    l3 = ((vader_struct_vader_core_mono$MonoEntry_t*) ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_origin)->f_symbol;
    if (l3.tag == 1346u) {
        l2 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l1)->f_function_index_by_symbol_id;
        t1 = l3.payload.obj;
        l13 = ((vader_struct_vader_core_symbol$Symbol_t*) t1)->f_id;
        std_collections$Map$std_core$IndexSet$set_at__i32__i32(l2, l13, l5);
    }
    t2 = ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_mangled;
    if (t2 != 0u) {
        l2 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l1)->f_function_index_by_mangle;
        l10 = ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_mangled;
        t3 = std_collections$Map$std_core$Index$at__string__i32(l2, l10);
        if (!(t3.tag == 0u)) {
            l10 = ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_mangled;
            t2 = concat_3(2287u, l10, 1267u);
            vader_host_std_core$Intrinsic$panic(t2);
            vader_unreachable("a no-return call returned");
        }
    }
    l2 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l1)->f_function_index_by_mangle;
    l10 = ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_mangled;
    std_collections$Map$std_core$IndexSet$set_at__string__i32(l2, l10, l5);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_bytecode$reserve_cfg_struct(void* l0, void* l1) {
    int32_t l2, l8, l9;
    vader_box_t l3 = vader_box_null(), l6 = vader_box_null();
    void* l4 = NULL;
    void* l5 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    vader_string_t l7 = 0;
    vader_string_t l15 = 0;
    uint64_t l10;
    int64_t l11, l12;
    bool l16;
    void* t0 = NULL;
    int64_t t1;
    vader_box_t t2 = vader_box_null();
    vader_string_t t3 = 0;
    vader_box_t* gc_roots[3] = { &l3, &l6, &t2 };
    void** gc_raw_roots[7] = { &l0, &l1, &l4, &l5, &l13, &l14, &t0 };
    vader_string_t* gc_atom_roots[3] = { &l7, &l15, &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = INT32_C(-1);
    l3 = ((vader_struct_vader_core_mono$MonoEntry_t*) ((vader_struct_vader_midir$CFGStructDecl_t*) l0)->f_origin)->f_symbol;
    if (l3.tag == 1346u) {
        t0 = l3.payload.obj;
        l2 = ((vader_struct_vader_core_symbol$Symbol_t*) t0)->f_id;
    }
    if (l3.tag == 1346u) {
        l4 = l3.payload.obj;
        l5 = ((vader_struct_vader_core_mono$MonoEntry_t*) ((vader_struct_vader_midir$CFGStructDecl_t*) l0)->f_origin)->f_type_arguments;
        l6 = vader_core_types$mk_struct(l4, l5);
        l4 = ((vader_struct_vader_midir$CFGStructDecl_t*) l0)->f_origin;
        l7 = ((vader_struct_vader_midir$CFGStructDecl_t*) l0)->f_mangled;
        l7 = vader_midir$layout_key(l4, l7);
        t1 = vader_array_length(((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l1)->f_types));
        l8 = ((int32_t) (int64_t) t1);
        l9 = std_collections$get_or_put__string__i32(((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l1)->f_type_key, l7, l8);
        if (l9 != l8) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l1)->f_types);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l9)
            t2 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l9);
            if (t2.tag == 1191u) {
                { vader_gc_top = gc_frame.prev; return; }
            }
        } else {
            l4 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l1)->f_type_hash;
            l10 = vader_midir_select$type_intern_hash(l6);
            std_collections$get_or_put__u64__i32(l4, l10, l9);
            vader_emit_bytecode$record_slot_type(l1, l9, l6);
            l4 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l1)->f_types;
            t3 = ((vader_struct_vader_midir$CFGStructDecl_t*) l0)->f_mangled;
            vader_struct_vader_core_bytecode$BcRef_t* _a1_obj = (vader_struct_vader_core_bytecode$BcRef_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcRef_t));
            vader_obj_header_init(_a1_obj, 1187u);
            _a1_obj->f_trait_name = t3;
            l5 = (void*) _a1_obj;
            vader_array_push_ref((vader_array_t*) l4, l5);
        }
        t1 = vader_array_length(((vader_array_t*) ((vader_struct_vader_midir$CFGStructDecl_t*) l0)->f_fields));
        vader_array_t* _a2_arr = vader_array_reserve(102u, (int64_t) t1, 13u, 1180u);
        l4 = (void*) _a2_arr;
        l5 = ((vader_struct_vader_midir$CFGStructDecl_t*) l0)->f_fields;
        l11 = vader_array_length(((vader_array_t*) l5));
        l12 = INT64_C(0);
        while ((l12 < l11)) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            l13 = vader_array_ref_load_obj(_a3_slotarr->buf, vader_array_offset(_a3_slotarr) + (size_t) l12);
            l8 = vader_emit_bytecode$intern_type(((vader_struct_vader_midir$CFGStructField_t*) l13)->f_type, l1);
            t3 = ((vader_struct_vader_midir$CFGStructField_t*) l13)->f_name;
            vader_struct_vader_core_bytecode$BcField_t* _a4_obj = (vader_struct_vader_core_bytecode$BcField_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcField_t));
            vader_obj_header_init(_a4_obj, 1180u);
            _a4_obj->f_name = t3;
            _a4_obj->f_type_index = l8;
            l14 = (void*) _a4_obj;
            vader_array_push_ref((vader_array_t*) l4, l14);
            l12 = (l12 + INT64_C(1));
        }
        l5 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l1)->f_types;
        l7 = ((vader_struct_vader_midir$CFGStructDecl_t*) l0)->f_mangled;
        l15 = vader_emit_bytecode$c_struct_of(((vader_struct_vader_midir$CFGStructDecl_t*) l0)->f_origin);
        l13 = l3.payload.obj;
        l3 = vader_emit_bytecode$struct_decl_of(((vader_struct_vader_midir$CFGStructDecl_t*) l0)->f_origin);
        l16 = vader_core_types$is_task_shared(l13, l3);
        vader_struct_vader_core_bytecode$BcStruct_t* _a5_obj = (vader_struct_vader_core_bytecode$BcStruct_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcStruct_t));
        vader_obj_header_init(_a5_obj, 1191u);
        _a5_obj->f_name = l7;
        _a5_obj->f_fields = l4;
        _a5_obj->f_c_name = l15;
        _a5_obj->f_symbol_id = l2;
        _a5_obj->f_shared = l16;
        l4 = (void*) _a5_obj;
        vader_array_t* _a6_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l9)
        vader_array_ref_store(_a6_slotarr->buf, vader_array_offset(_a6_slotarr) + (size_t) l9, l4);
        VADER_WRITE_BARRIER(_a6_slotarr->buf);
        { vader_gc_top = gc_frame.prev; return; }
    }
    t1 = vader_array_length(((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l1)->f_types));
    l8 = ((int32_t) (int64_t) t1);
    l4 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l1)->f_types;
    t3 = ((vader_struct_vader_midir$CFGStructDecl_t*) l0)->f_mangled;
    vader_struct_vader_core_bytecode$BcRef_t* _a7_obj = (vader_struct_vader_core_bytecode$BcRef_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcRef_t));
    vader_obj_header_init(_a7_obj, 1187u);
    _a7_obj->f_trait_name = t3;
    l5 = (void*) _a7_obj;
    vader_array_push_ref((vader_array_t*) l4, l5);
    t1 = vader_array_length(((vader_array_t*) ((vader_struct_vader_midir$CFGStructDecl_t*) l0)->f_fields));
    vader_array_t* _a8_arr = vader_array_reserve(102u, (int64_t) t1, 13u, 1180u);
    l4 = (void*) _a8_arr;
    l5 = ((vader_struct_vader_midir$CFGStructDecl_t*) l0)->f_fields;
    l11 = vader_array_length(((vader_array_t*) l5));
    l12 = INT64_C(0);
    while ((l12 < l11)) {
        vader_array_t* _a9_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
        l13 = vader_array_ref_load_obj(_a9_slotarr->buf, vader_array_offset(_a9_slotarr) + (size_t) l12);
        l9 = vader_emit_bytecode$intern_type(((vader_struct_vader_midir$CFGStructField_t*) l13)->f_type, l1);
        t3 = ((vader_struct_vader_midir$CFGStructField_t*) l13)->f_name;
        vader_struct_vader_core_bytecode$BcField_t* _a10_obj = (vader_struct_vader_core_bytecode$BcField_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcField_t));
        vader_obj_header_init(_a10_obj, 1180u);
        _a10_obj->f_name = t3;
        _a10_obj->f_type_index = l9;
        l14 = (void*) _a10_obj;
        vader_array_push_ref((vader_array_t*) l4, l14);
        l12 = (l12 + INT64_C(1));
    }
    l5 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l1)->f_types;
    l7 = ((vader_struct_vader_midir$CFGStructDecl_t*) l0)->f_mangled;
    l15 = vader_emit_bytecode$c_struct_of(((vader_struct_vader_midir$CFGStructDecl_t*) l0)->f_origin);
    vader_struct_vader_core_bytecode$BcStruct_t* _a11_obj = (vader_struct_vader_core_bytecode$BcStruct_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcStruct_t));
    vader_obj_header_init(_a11_obj, 1191u);
    _a11_obj->f_name = l7;
    _a11_obj->f_fields = l4;
    _a11_obj->f_c_name = l15;
    _a11_obj->f_symbol_id = l2;
    _a11_obj->f_shared = false;
    l4 = (void*) _a11_obj;
    vader_array_t* _a12_slotarr = ((vader_array_t*) l5);
    VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a12_slotarr, l8)
    vader_array_ref_store(_a12_slotarr->buf, vader_array_offset(_a12_slotarr) + (size_t) l8, l4);
    VADER_WRITE_BARRIER(_a12_slotarr->buf);
    l4 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l1)->f_type_key;
    l5 = ((vader_struct_vader_midir$CFGStructDecl_t*) l0)->f_origin;
    l7 = ((vader_struct_vader_midir$CFGStructDecl_t*) l0)->f_mangled;
    l7 = vader_midir$layout_key(l5, l7);
    std_collections$Map$std_core$IndexSet$set_at__string__i32(l4, l7, l8);
    { vader_gc_top = gc_frame.prev; return; }
}

static void* vader_emit_bytecode$resolve_direct_call(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    int32_t l4;
    vader_box_t l5 = vader_box_null();
    vader_string_t l6 = 0;
    vader_string_t l7 = 0;
    int64_t l8, l9;
    int32_t t0;
    void* t1 = NULL;
    vader_string_t t2 = 0;
    vader_box_t* gc_roots[1] = { &l5 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &t1 };
    vader_string_t* gc_atom_roots[3] = { &l6, &l7, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_project;
    l3 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l2)->f_import_index_by_symbol_id;
    l4 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_midir$InstrCall_t*) l1)->f_callee)->f_id;
    l5 = std_collections$Map$std_core$Index$at__i32__i32(l3, l4);
    if (l5.tag == 580u) {
        t0 = ((int32_t) l5.payload.i);
        l5 = vader_box_i32(580u, t0);
    } else {
        l3 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l2)->f_import_index_by_mangle;
        l6 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_midir$InstrCall_t*) l1)->f_callee)->f_name;
        l5 = std_collections$Map$std_core$Index$at__string__i32(l3, l6);
    }
    if (l5.tag == 580u) {
        l4 = ((int32_t) l5.payload.i);
        t1 = vader_emit_bytecode$import_call_target(l2, l4);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l5 = vader_emit_bytecode$resolve_fn_index(((vader_struct_vader_midir$InstrCall_t*) l1)->f_callee, l2);
    if (!(l5.tag == 0u)) {
        t0 = ((int32_t) l5.payload.i);
        vader_struct_vader_core_bytecode$Call_t* _a0_obj = (vader_struct_vader_core_bytecode$Call_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$Call_t));
        vader_obj_header_init(_a0_obj, 1213u);
        _a0_obj->f_function_index = t0;
        l3 = (void*) _a0_obj;
        l2 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l2)->f_functions;
        l4 = ((int32_t) l5.payload.i);
        vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
        t1 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l4);
        l2 = ((vader_struct_vader_core_bytecode$BcFunction_t*) t1)->f_signature;
        vader_struct_vader_emit_bytecode$DirectCallTarget_t* _a2_obj = (vader_struct_vader_emit_bytecode$DirectCallTarget_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_bytecode$DirectCallTarget_t));
        vader_obj_header_init(_a2_obj, 1379u);
        _a2_obj->f_op = vader_ref_box(l3);
        _a2_obj->f_signature = l2;
        t1 = (void*) _a2_obj;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l6 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_midir$InstrCall_t*) l1)->f_callee)->f_name;
    l4 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_midir$InstrCall_t*) l1)->f_callee)->f_id;
    l7 = ((vader_struct_vader_midir$CFGFunction_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_fn_)->f_mangled;
    l8 = vader_host_std_core$Intrinsic$byte_len(l6);
    l9 = vader_host_std_core$Intrinsic$byte_len(l7);
    l8 = (l8 + l9);
    l2 = (void*) vader_buffer_new((size_t) (INT64_C(102) + l8));
    l8 = INT64_C(0);
    l8 = std_core$write_string_at(l2, l8, 2290u);
    l8 = std_core$write_string_at(l2, l8, l6);
    l8 = std_core$write_string_at(l2, l8, 343u);
    l9 = ((int64_t) (int32_t) l4);
    l8 = std_core$write_int(l2, l8, l9);
    l8 = std_core$write_string_at(l2, l8, 389u);
    l8 = std_core$write_string_at(l2, l8, l7);
    l8 = std_core$write_string_at(l2, l8, 344u);
    t2 = std_core$finish_buffer(l2, l8);
    vader_host_std_core$Intrinsic$panic(t2);
    vader_unreachable("a no-return call returned");
    vader_gc_top = gc_frame.prev;
}

static vader_box_t vader_emit_bytecode$resolve_fn_index(void* l0, void* l1) {
    void* l2;
    vader_string_t l3;
    vader_box_t l4;
    int32_t l5;
    int32_t t0;
    vader_box_t t1;
    l2 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l1)->f_function_index_by_mangle;
    l3 = ((vader_struct_vader_core_symbol$Symbol_t*) l0)->f_name;
    l4 = std_collections$Map$std_core$Index$at__string__i32(l2, l3);
    if (!(l4.tag == 0u)) {
        t0 = ((int32_t) l4.payload.i);
        return vader_box_i32(580u, t0);
    }
    l2 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l1)->f_function_index_by_symbol_id;
    l5 = ((vader_struct_vader_core_symbol$Symbol_t*) l0)->f_id;
    t1 = std_collections$Map$std_core$Index$at__i32__i32(l2, l5);
    return t1;
}

static vader_string_t vader_emit_bytecode$result_c_type_of(void* l0) {
    vader_box_t l1 = vader_box_null();
    void* t0 = NULL;
    vader_string_t t1 = 0;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct_vader_core_mono$MonoEntry_t*) l0)->f_decl;
    if (!(l1.tag == 1048u)) {
        { vader_gc_top = gc_frame.prev; return 0u; }
    }
    t0 = l1.payload.obj;
    t1 = toolchain_ast$c_type_of(((vader_struct_toolchain_ast$FnDecl_t*) t0)->f_decorators);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_emit_bytecode$retargeted(void* l0, vader_box_t l1) {
    vader_box_t l2 = vader_box_null();
    void* l3 = NULL;
    void* l5 = NULL;
    int32_t l4, l6, l7;
    void* t0 = NULL;
    vader_box_t* gc_roots[2] = { &l1, &l2 };
    void** gc_raw_roots[4] = { &l0, &l3, &l5, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l1.tag == 1876u) {
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir$TermBranch_t*) t0)->f_span;
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_midir$TermBranch_t*) t0)->f_target;
        l4 = vader_emit_bytecode$destination(l0, l4);
        vader_struct_vader_midir$TermBranch_t* _a0_obj = (vader_struct_vader_midir$TermBranch_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$TermBranch_t));
        vader_obj_header_init(_a0_obj, 1876u);
        _a0_obj->f_span = l3;
        _a0_obj->f_target = l4;
        t0 = (void*) _a0_obj;
        l2 = vader_ref_box(t0);
        { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 1877u) {
        l3 = l1.payload.obj;
        l5 = ((vader_struct_vader_midir$TermCondBranch_t*) l3)->f_span;
        l4 = ((vader_struct_vader_midir$TermCondBranch_t*) l3)->f_cond;
        t0 = l1.payload.obj;
        l6 = ((vader_struct_vader_midir$TermCondBranch_t*) t0)->f_then_block;
        l6 = vader_emit_bytecode$destination(l0, l6);
        t0 = l1.payload.obj;
        l7 = ((vader_struct_vader_midir$TermCondBranch_t*) t0)->f_else_block;
        l7 = vader_emit_bytecode$destination(l0, l7);
        vader_struct_vader_midir$TermCondBranch_t* _a1_obj = (vader_struct_vader_midir$TermCondBranch_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$TermCondBranch_t));
        vader_obj_header_init(_a1_obj, 1877u);
        _a1_obj->f_span = l5;
        _a1_obj->f_cond = l4;
        _a1_obj->f_then_block = l6;
        _a1_obj->f_else_block = l7;
        t0 = (void*) _a1_obj;
        l2 = vader_ref_box(t0);
    } else {
        if (!((l1.tag == 1878u || l1.tag == 1879u))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l2 = l1;
    }
    { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_emit_bytecode$run_bytecode_stages(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    int64_t l4, l5;
    vader_box_t l6 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l6, &t0 };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = l1;
    l3 = l0;
    l4 = vader_array_length(((vader_array_t*) l3));
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
        l6 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l5);
        t0 = toolchain_stage$Stage$run$$dispatch(l6, vader_ref_box(l2));
        l2 = t0.payload.obj;
        l5 = (l5 + INT64_C(1));
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_emit_bytecode$schedule_stack(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l17 = NULL;
    void* l24 = NULL;
    void* l26 = NULL;
    int64_t l7, l8, l9, l10, l11, l12, l14, l16, l19, l20, l21, l25;
    vader_box_t l13 = vader_box_null(), l15 = vader_box_null(), l22 = vader_box_null(), l23 = vader_box_null();
    int32_t l18, l27;
    void* t0 = NULL;
    bool t1;
    int64_t t2;
    vader_box_t* gc_roots[4] = { &l13, &l15, &l22, &l23 };
    void** gc_raw_roots[11] = { &l0, &l1, &l2, &l3, &l4, &l5, &l6, &l17, &l24, &l26, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 11u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_midir$count_uses(l0);
    vader_array_t* _a0_arr = vader_array_new(28u, 0u, 8u, 581u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(24u, 0u, 12u, 575u);
    l3 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(27u, 0u, 7u, 580u);
    l4 = (void*) _a2_arr;
    vader_struct_std_collections$Map__i64__bool_t* _a3_obj = (vader_struct_std_collections$Map__i64__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__i64__bool_t));
    vader_obj_header_init(_a3_obj, 864u);
    _a3_obj->f_ekeys = l2;
    _a3_obj->f_evals = l3;
    _a3_obj->f_index = l4;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a3_obj;
    vader_struct_std_collections$Set__i64_t* _a4_obj = (vader_struct_std_collections$Set__i64_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Set__i64_t));
    vader_obj_header_init(_a4_obj, 990u);
    _a4_obj->f_inner = t0;
    l2 = (void*) _a4_obj;
    vader_array_t* _a5_arr = vader_array_new(28u, 0u, 8u, 581u);
    l3 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(24u, 0u, 12u, 575u);
    l4 = (void*) _a6_arr;
    vader_array_t* _a7_arr = vader_array_new(27u, 0u, 7u, 580u);
    l5 = (void*) _a7_arr;
    vader_struct_std_collections$Map__i64__bool_t* _a8_obj = (vader_struct_std_collections$Map__i64__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__i64__bool_t));
    vader_obj_header_init(_a8_obj, 864u);
    _a8_obj->f_ekeys = l3;
    _a8_obj->f_evals = l4;
    _a8_obj->f_index = l5;
    _a8_obj->f_mask = INT64_C(0);
    _a8_obj->f_grow_at = INT64_C(0);
    _a8_obj->f_size = INT64_C(0);
    _a8_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a8_obj;
    vader_struct_std_collections$Set__i64_t* _a9_obj = (vader_struct_std_collections$Set__i64_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Set__i64_t));
    vader_obj_header_init(_a9_obj, 990u);
    _a9_obj->f_inner = t0;
    l3 = (void*) _a9_obj;
    vader_array_t* _a10_arr = vader_array_new(27u, 0u, 7u, 580u);
    l4 = (void*) _a10_arr;
    vader_array_t* _a11_arr = vader_array_new(24u, 0u, 12u, 575u);
    l5 = (void*) _a11_arr;
    vader_array_t* _a12_arr = vader_array_new(27u, 0u, 7u, 580u);
    l6 = (void*) _a12_arr;
    vader_struct_std_collections$Map__i32__bool_t* _a13_obj = (vader_struct_std_collections$Map__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__i32__bool_t));
    vader_obj_header_init(_a13_obj, 815u);
    _a13_obj->f_ekeys = l4;
    _a13_obj->f_evals = l5;
    _a13_obj->f_index = l6;
    _a13_obj->f_mask = INT64_C(0);
    _a13_obj->f_grow_at = INT64_C(0);
    _a13_obj->f_size = INT64_C(0);
    _a13_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a13_obj;
    vader_struct_std_collections$Set__i32_t* _a14_obj = (vader_struct_std_collections$Set__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Set__i32_t));
    vader_obj_header_init(_a14_obj, 989u);
    _a14_obj->f_inner = t0;
    l4 = (void*) _a14_obj;
    vader_struct_vader_emit_bytecode$ScheduleHints_t* _a15_obj = (vader_struct_vader_emit_bytecode$ScheduleHints_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_bytecode$ScheduleHints_t));
    vader_obj_header_init(_a15_obj, 1387u);
    _a15_obj->f_skip_set = l2;
    _a15_obj->f_skip_first_get = l3;
    _a15_obj->f_skip_terminator_get = l4;
    l2 = (void*) _a15_obj;
    l3 = ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_blocks;
    l7 = vader_array_length(((vader_array_t*) l3));
    l8 = INT64_C(0);
    while ((l8 < l7)) {
        vader_array_t* _a16_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a16_slotarr)
        l4 = vader_array_ref_load_obj(_a16_slotarr->buf, vader_array_offset(_a16_slotarr) + (size_t) l8);
        l9 = INT64_C(0);
        l10 = vader_array_length(((vader_array_t*) ((vader_struct_vader_midir$BasicBlock_t*) l4)->f_instructions));
        while ((l9 < l10)) {
            l11 = vader_chk_add(i64, l9, INT64_C(1));
            l12 = vader_array_length(((vader_array_t*) ((vader_struct_vader_midir$BasicBlock_t*) l4)->f_instructions));
            if ((l11 >= l12)) break;
            vader_array_t* _a17_slotarr = ((vader_array_t*) ((vader_struct_vader_midir$BasicBlock_t*) l4)->f_instructions);
            VADER_ARRAY_RESOLVE_BUF(_a17_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a17_slotarr, l9)
            l13 = vader_array_ref_load_box(_a17_slotarr->buf, vader_array_offset(_a17_slotarr) + (size_t) l9);
            l5 = ((vader_struct_vader_midir$BasicBlock_t*) l4)->f_instructions;
            l14 = vader_chk_add(i64, l9, INT64_C(1));
            vader_array_t* _a18_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a18_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a18_slotarr, l14)
            l15 = vader_array_ref_load_box(_a18_slotarr->buf, vader_array_offset(_a18_slotarr) + (size_t) l14);
            t1 = vader_emit_bytecode$can_pass_through_stack(l13, l15, l1);
            if (t1) {
                l6 = ((vader_struct_vader_emit_bytecode$ScheduleHints_t*) l2)->f_skip_set;
                l16 = vader_midir$pos_key(((vader_struct_vader_midir$BasicBlock_t*) l4)->f_id, l9);
                std_collections$add__i64(l6, l16);
                l17 = ((vader_struct_vader_emit_bytecode$ScheduleHints_t*) l2)->f_skip_first_get;
                l18 = ((vader_struct_vader_midir$BasicBlock_t*) l4)->f_id;
                l19 = vader_chk_add(i64, l9, INT64_C(1));
                l20 = vader_midir$pos_key(l18, l19);
                std_collections$add__i64(l17, l20);
                l9 = (l9 + INT64_C(1));
                continue;
            }
            l9 = (l9 + INT64_C(1));
        }
        t2 = vader_array_length(((vader_array_t*) ((vader_struct_vader_midir$BasicBlock_t*) l4)->f_instructions));
        if (t2 == INT64_C(0)) {
            l8 = (l8 + INT64_C(1));
            continue;
        }
        t2 = vader_array_length(((vader_array_t*) ((vader_struct_vader_midir$BasicBlock_t*) l4)->f_instructions));
        l21 = vader_chk_sub(i64, t2, INT64_C(1));
        vader_array_t* _a19_slotarr = ((vader_array_t*) ((vader_struct_vader_midir$BasicBlock_t*) l4)->f_instructions);
        VADER_ARRAY_RESOLVE_BUF(_a19_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a19_slotarr, l21)
        l22 = vader_array_ref_load_box(_a19_slotarr->buf, vader_array_offset(_a19_slotarr) + (size_t) l21);
        l23 = ((vader_struct_vader_midir$BasicBlock_t*) l4)->f_terminator;
        t1 = vader_emit_bytecode$can_pass_through_terminator(l22, l23, l1);
        if (t1) {
            l24 = ((vader_struct_vader_emit_bytecode$ScheduleHints_t*) l2)->f_skip_set;
            l25 = vader_midir$pos_key(((vader_struct_vader_midir$BasicBlock_t*) l4)->f_id, l21);
            std_collections$add__i64(l24, l25);
            l26 = ((vader_struct_vader_emit_bytecode$ScheduleHints_t*) l2)->f_skip_terminator_get;
            l27 = ((vader_struct_vader_midir$BasicBlock_t*) l4)->f_id;
            std_collections$add__vader_midir$BlockId(l26, l27);
            l8 = (l8 + INT64_C(1));
            continue;
        }
        l8 = (l8 + INT64_C(1));
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_emit_bytecode$shape_of(void* l0, void* l1, void* l2) {
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
    bool t2, t6;
    vader_string_t t3 = 0;
    int64_t t4, t5;
    void** gc_raw_roots[18] = {
        &l0, &l1, &l2, &l4, &l5, &l6, &l7, &l8, &l9, &l10, &l27, &l32, &l33, &l34, &l35, &l36, &l39,
        &t0,
    };
    vader_string_t* gc_atom_roots[2] = { &l25, &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 18u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = vader_array_length(((vader_array_t*) ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_blocks));
    l4 = vader_midir$reverse_postorder(l0);
    l5 = vader_midir$rpo_positions(l4, l3);
    l6 = vader_midir$natural_loop_bodies(l0, l1, l2);
    vader_array_t* _a0_arr = vader_array_new(24u, 1u, 12u, 575u);
    ((uint8_t*) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = (uint8_t) false;
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l3);
    l7 = (void*) _a1_arr;
    l8 = l6;
    l9 = ((vader_struct_std_collections$Map__i32__std_collections_Set_i32__t*) l8)->f_ekeys;
    l10 = ((vader_struct_std_collections$Map__i32__std_collections_Set_i32__t*) l8)->f_evals;
    l11 = INT64_C(0);
    l12 = ((vader_struct_std_collections$Map__i32__std_collections_Set_i32__t*) l8)->f_size;
    while ((l11 < l12)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l9);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l11)
        l13 = ((int32_t*) _a2_slotarr->buf->slots)[vader_array_offset(_a2_slotarr) + (size_t) l11];
        vader_array_t* _a3_slotarr = ((vader_array_t*) l10);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l11)
        t0 = vader_array_ref_load_obj(_a3_slotarr->buf, vader_array_offset(_a3_slotarr) + (size_t) l11);
        l14 = l13;
        vader_array_t* _a4_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l14)
        ((uint8_t*) _a4_slotarr->buf->slots)[vader_array_offset(_a4_slotarr) + (size_t) l14] = (uint8_t) true;
        l11 = (l11 + INT64_C(1));
    }
    vader_array_t* _a5_arr = vader_array_new(27u, 1u, 7u, 580u);
    ((int32_t*) _a5_arr->buf->slots)[vader_array_offset(_a5_arr) + 0u] = (int32_t) INT32_C(0);
    t0 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l3);
    l8 = (void*) _a6_arr;
    l9 = l4;
    l11 = vader_array_length(((vader_array_t*) l9));
    l12 = INT64_C(0);
    while ((l12 < l11)) {
        vader_array_t* _a7_slotarr = ((vader_array_t*) l9);
        VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
        l13 = ((int32_t*) _a7_slotarr->buf->slots)[vader_array_offset(_a7_slotarr) + (size_t) l12];
        l14 = l13;
        vader_array_t* _a8_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l14)
        l10 = vader_array_ref_load_obj(_a8_slotarr->buf, vader_array_offset(_a8_slotarr) + (size_t) l14);
        l15 = vader_array_length(((vader_array_t*) l10));
        l16 = INT64_C(0);
        while ((l16 < l15)) {
            vader_array_t* _a9_slotarr = ((vader_array_t*) l10);
            VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
            l17 = ((int32_t*) _a9_slotarr->buf->slots)[vader_array_offset(_a9_slotarr) + (size_t) l16];
            l18 = l17;
            vader_array_t* _a10_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a10_slotarr, l18)
            t1 = ((int32_t*) _a10_slotarr->buf->slots)[vader_array_offset(_a10_slotarr) + (size_t) l18];
            if ((t1 < INT32_C(0))) {
                l16 = (l16 + INT64_C(1));
                continue;
            }
            l19 = l17;
            vader_array_t* _a11_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l19)
            l20 = ((int32_t*) _a11_slotarr->buf->slots)[vader_array_offset(_a11_slotarr) + (size_t) l19];
            l21 = l13;
            VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l21)
            l22 = ((int32_t*) _a11_slotarr->buf->slots)[vader_array_offset(_a11_slotarr) + (size_t) l21];
            if ((l20 < l22)) {
                l23 = l13;
                vader_array_t* _a12_slotarr = ((vader_array_t*) l8);
                VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a12_slotarr, l23)
                t1 = ((int32_t*) _a12_slotarr->buf->slots)[vader_array_offset(_a12_slotarr) + (size_t) l23];
                l24 = vader_chk_add(i32, t1, INT32_C(1));
                VADER_ARRAY_CHECK_INDEX(_a12_slotarr, l23)
                ((int32_t*) _a12_slotarr->buf->slots)[vader_array_offset(_a12_slotarr) + (size_t) l23] = (int32_t) l24;
            } else {
                t2 = vader_emit_bytecode$closes_loop(l6, l17, l13);
                if (!(t2)) {
                    l25 = ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_mangled;
                    l26 = vader_host_std_core$Intrinsic$byte_len(l25);
                    l27 = (void*) vader_buffer_new((size_t) (INT64_C(134) + l26));
                    l28 = INT64_C(0);
                    l28 = std_core$write_string_at(l27, l28, 2295u);
                    l28 = std_core$write_string_at(l27, l28, l25);
                    l28 = std_core$write_string_at(l27, l28, 355u);
                    l29 = ((int64_t) (int32_t) l17);
                    l28 = std_core$write_int(l27, l28, l29);
                    l28 = std_core$write_string_at(l27, l28, 81u);
                    l30 = ((int64_t) (int32_t) l13);
                    l28 = std_core$write_int(l27, l28, l30);
                    l28 = std_core$write_string_at(l27, l28, 143u);
                    t3 = std_core$finish_buffer(l27, l28);
                    vader_host_std_core$Intrinsic$panic(t3);
                    vader_unreachable("a no-return call returned");
                }
            }
            l16 = (l16 + INT64_C(1));
        }
        l12 = (l12 + INT64_C(1));
    }
    vader_array_t* _a13_arr = vader_array_new(24u, 1u, 12u, 575u);
    ((uint8_t*) _a13_arr->buf->slots)[vader_array_offset(_a13_arr) + 0u] = (uint8_t) false;
    t0 = (void*) _a13_arr;
    vader_array_t* _a14_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l3);
    l9 = (void*) _a14_arr;
    l11 = INT64_C(0);
    l12 = vader_array_length(((vader_array_t*) l4));
    while ((l11 < l12)) {
        t4 = vader_array_length(((vader_array_t*) l4));
        t5 = vader_chk_sub(i64, t4, INT64_C(1));
        l15 = vader_chk_sub(i64, t5, l11);
        vader_array_t* _a15_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a15_slotarr, l15)
        l13 = ((int32_t*) _a15_slotarr->buf->slots)[vader_array_offset(_a15_slotarr) + (size_t) l15];
        l14 = l13;
        l17 = l13;
        vader_array_t* _a16_slotarr = ((vader_array_t*) l9);
        VADER_ARRAY_RESOLVE_BUF(_a16_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a16_slotarr, l17)
        t2 = ((uint8_t*) _a16_slotarr->buf->slots)[vader_array_offset(_a16_slotarr) + (size_t) l17];
        t6 = t2;
        if (t6) {
            l31 = true;
        } else {
            l18 = l13;
            vader_array_t* _a17_slotarr = ((vader_array_t*) l7);
            VADER_ARRAY_RESOLVE_BUF(_a17_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a17_slotarr, l18)
            t2 = ((uint8_t*) _a17_slotarr->buf->slots)[vader_array_offset(_a17_slotarr) + (size_t) l18];
            l31 = t2;
        }
        vader_array_t* _a18_slotarr = ((vader_array_t*) l9);
        VADER_ARRAY_RESOLVE_BUF(_a18_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a18_slotarr, l14)
        ((uint8_t*) _a18_slotarr->buf->slots)[vader_array_offset(_a18_slotarr) + (size_t) l14] = (uint8_t) l31;
        l19 = ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_entry;
        t2 = vader_midir$BlockId$std_core$Equals$equals(l13, l19);
        if (!(t2)) {
            l20 = l13;
            vader_array_t* _a19_slotarr = ((vader_array_t*) l9);
            VADER_ARRAY_RESOLVE_BUF(_a19_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a19_slotarr, l20)
            t2 = ((uint8_t*) _a19_slotarr->buf->slots)[vader_array_offset(_a19_slotarr) + (size_t) l20];
            t6 = t2;
            if (t6) {
                l21 = l13;
                vader_array_t* _a20_slotarr = ((vader_array_t*) l2);
                VADER_ARRAY_RESOLVE_BUF(_a20_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a20_slotarr, l21)
                l22 = ((int32_t*) _a20_slotarr->buf->slots)[vader_array_offset(_a20_slotarr) + (size_t) l21];
                vader_array_t* _a21_slotarr = ((vader_array_t*) l9);
                VADER_ARRAY_RESOLVE_BUF(_a21_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a21_slotarr, l22)
                ((uint8_t*) _a21_slotarr->buf->slots)[vader_array_offset(_a21_slotarr) + (size_t) l22] = (uint8_t) true;
            }
        }
        l11 = (l11 + INT64_C(1));
    }
    vader_array_t* _a22_arr = vader_array_new(24u, 1u, 12u, 575u);
    ((uint8_t*) _a22_arr->buf->slots)[vader_array_offset(_a22_arr) + 0u] = (uint8_t) false;
    t0 = (void*) _a22_arr;
    vader_array_t* _a23_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l3);
    l10 = (void*) _a23_arr;
    vader_array_t* _a24_arr = vader_array_new(24u, 1u, 12u, 575u);
    ((uint8_t*) _a24_arr->buf->slots)[vader_array_offset(_a24_arr) + 0u] = (uint8_t) false;
    t0 = (void*) _a24_arr;
    vader_array_t* _a25_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l3);
    l27 = (void*) _a25_arr;
    if ((INT64_C(0) < l3)) {
        l11 = l3;
    } else {
        l11 = INT64_C(0);
    }
    vader_array_t* _a26_arr = vader_array_reserve(3u, (int64_t) l11, 13u, 27u);
    l32 = (void*) _a26_arr;
    if ((INT64_C(0) < l3)) {
        l11 = l3;
    } else {
        l11 = INT64_C(0);
    }
    vader_array_t* _a27_arr = vader_array_reserve(3u, (int64_t) l11, 13u, 27u);
    l33 = (void*) _a27_arr;
    vader_array_t* _a28_arr = vader_array_new(27u, 1u, 7u, 580u);
    ((int32_t*) _a28_arr->buf->slots)[vader_array_offset(_a28_arr) + 0u] = (int32_t) INT32_C(-1);
    t0 = (void*) _a28_arr;
    vader_array_t* _a29_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l3);
    l34 = (void*) _a29_arr;
    l11 = INT64_C(0);
    while ((l11 < l3)) {
        vader_array_t* _a30_arr = vader_array_new(27u, 0u, 7u, 580u);
        l35 = (void*) _a30_arr;
        vader_array_push_ref((vader_array_t*) l32, l35);
        vader_array_t* _a31_arr = vader_array_new(27u, 0u, 7u, 580u);
        l36 = (void*) _a31_arr;
        vader_array_push_ref((vader_array_t*) l33, l36);
        l11 = (l11 + INT64_C(1));
    }
    l3 = vader_array_length(((vader_array_t*) l4));
    l11 = INT64_C(0);
    while ((l11 < l3)) {
        vader_array_t* _a32_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a32_slotarr)
        l13 = ((int32_t*) _a32_slotarr->buf->slots)[vader_array_offset(_a32_slotarr) + (size_t) l11];
        l14 = ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_entry;
        t2 = vader_midir$BlockId$std_core$Equals$equals(l13, l14);
        if (t2) {
            l11 = (l11 + INT64_C(1));
            continue;
        }
        l17 = l13;
        vader_array_t* _a33_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a33_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a33_slotarr, l17)
        t1 = ((int32_t*) _a33_slotarr->buf->slots)[vader_array_offset(_a33_slotarr) + (size_t) l17];
        if ((t1 >= INT32_C(2))) {
            l18 = l13;
            vader_array_t* _a34_slotarr = ((vader_array_t*) l1);
            VADER_ARRAY_RESOLVE_BUF(_a34_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a34_slotarr, l18)
            l35 = vader_array_ref_load_obj(_a34_slotarr->buf, vader_array_offset(_a34_slotarr) + (size_t) l18);
            t2 = vader_emit_bytecode$entered_by_test(l6, l35, l13);
            l31 = !(t2);
        } else {
            l31 = false;
        }
        if (l31) {
            l36 = ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_blocks;
            l19 = l13;
            vader_array_t* _a35_slotarr = ((vader_array_t*) l36);
            VADER_ARRAY_RESOLVE_BUF(_a35_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a35_slotarr, l19)
            t0 = vader_array_ref_load_obj(_a35_slotarr->buf, vader_array_offset(_a35_slotarr) + (size_t) l19);
            t2 = vader_emit_bytecode$copies_cheaply(t0);
            if (t2) {
                l20 = l13;
                vader_array_t* _a36_slotarr = ((vader_array_t*) l27);
                VADER_ARRAY_RESOLVE_BUF(_a36_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a36_slotarr, l20)
                ((uint8_t*) _a36_slotarr->buf->slots)[vader_array_offset(_a36_slotarr) + (size_t) l20] = (uint8_t) true;
                l11 = (l11 + INT64_C(1));
                continue;
            }
        }
        l21 = l13;
        vader_array_t* _a37_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a37_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a37_slotarr, l21)
        l22 = ((int32_t*) _a37_slotarr->buf->slots)[vader_array_offset(_a37_slotarr) + (size_t) l21];
        l23 = l22;
        l24 = vader_emit_bytecode$outermost_loop_left(l6, l5, l23, l13);
        if ((l24 >= INT32_C(0))) {
            l37 = l24;
            l38 = vader_emit_bytecode$tests_its_exit(l0, l6, l37);
            l39 = ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_blocks;
            l40 = l13;
            vader_array_t* _a38_slotarr = ((vader_array_t*) l39);
            VADER_ARRAY_RESOLVE_BUF(_a38_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a38_slotarr, l40)
            t0 = vader_array_ref_load_obj(_a38_slotarr->buf, vader_array_offset(_a38_slotarr) + (size_t) l40);
            l41 = vader_emit_bytecode$ends_function(((vader_struct_vader_midir$BasicBlock_t*) t0)->f_terminator);
            l43 = l13;
            vader_array_t* _a39_slotarr = ((vader_array_t*) l8);
            VADER_ARRAY_RESOLVE_BUF(_a39_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a39_slotarr, l43)
            t1 = ((int32_t*) _a39_slotarr->buf->slots)[vader_array_offset(_a39_slotarr) + (size_t) l43];
            if ((t1 < INT32_C(2))) {
                l44 = l13;
                vader_array_t* _a40_slotarr = ((vader_array_t*) l9);
                VADER_ARRAY_RESOLVE_BUF(_a40_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a40_slotarr, l44)
                t2 = ((uint8_t*) _a40_slotarr->buf->slots)[vader_array_offset(_a40_slotarr) + (size_t) l44];
                t6 = t2;
                l42 = !(t6);
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
                t2 = vader_emit_bytecode$leaves_header(l6, l48, l13);
                l45 = !(t2);
            } else {
                l45 = false;
            }
            if (!(l45)) {
                l49 = true;
            } else {
                l50 = l13;
                vader_array_t* _a41_slotarr = ((vader_array_t*) l1);
                VADER_ARRAY_RESOLVE_BUF(_a41_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a41_slotarr, l50)
                t0 = vader_array_ref_load_obj(_a41_slotarr->buf, vader_array_offset(_a41_slotarr) + (size_t) l50);
                t2 = vader_emit_bytecode$emitted_beneath(t0, l5, l2, l34, l22);
                l49 = !(t2);
            }
            if (l49) {
                vader_array_t* _a42_slotarr = ((vader_array_t*) l33);
                VADER_ARRAY_RESOLVE_BUF(_a42_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a42_slotarr, l24)
                t0 = vader_array_ref_load_obj(_a42_slotarr->buf, vader_array_offset(_a42_slotarr) + (size_t) l24);
                vader_array_push_i32((vader_array_t*) t0, l13);
                l51 = l13;
                vader_array_t* _a43_slotarr = ((vader_array_t*) l34);
                VADER_ARRAY_RESOLVE_BUF(_a43_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a43_slotarr, l51)
                ((int32_t*) _a43_slotarr->buf->slots)[vader_array_offset(_a43_slotarr) + (size_t) l51] = (int32_t) l24;
                l52 = l13;
                vader_array_t* _a44_slotarr = ((vader_array_t*) l10);
                VADER_ARRAY_RESOLVE_BUF(_a44_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a44_slotarr, l52)
                ((uint8_t*) _a44_slotarr->buf->slots)[vader_array_offset(_a44_slotarr) + (size_t) l52] = (uint8_t) true;
                l11 = (l11 + INT64_C(1));
                continue;
            }
        }
        l53 = l13;
        vader_array_t* _a45_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a45_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a45_slotarr, l53)
        t1 = ((int32_t*) _a45_slotarr->buf->slots)[vader_array_offset(_a45_slotarr) + (size_t) l53];
        if ((t1 >= INT32_C(2))) {
            vader_array_t* _a46_slotarr = ((vader_array_t*) l32);
            VADER_ARRAY_RESOLVE_BUF(_a46_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a46_slotarr, l22)
            t0 = vader_array_ref_load_obj(_a46_slotarr->buf, vader_array_offset(_a46_slotarr) + (size_t) l22);
            vader_array_push_i32((vader_array_t*) t0, l13);
            l54 = l13;
            vader_array_t* _a47_slotarr = ((vader_array_t*) l10);
            VADER_ARRAY_RESOLVE_BUF(_a47_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a47_slotarr, l54)
            ((uint8_t*) _a47_slotarr->buf->slots)[vader_array_offset(_a47_slotarr) + (size_t) l54] = (uint8_t) true;
        }
        l11 = (l11 + INT64_C(1));
    }
    vader_struct_vader_emit_bytecode$StructureShape_t* _a48_obj = (vader_struct_vader_emit_bytecode$StructureShape_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_bytecode$StructureShape_t));
    vader_obj_header_init(_a48_obj, 1391u);
    _a48_obj->f_rpo_index = l5;
    _a48_obj->f_loop_header = l7;
    _a48_obj->f_merge = l10;
    _a48_obj->f_merges = l32;
    _a48_obj->f_exits = l33;
    _a48_obj->f_copied = l27;
    t0 = (void*) _a48_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_emit_bytecode$skip_forwarding_blocks(void* l0) {
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
    bool l11;
    vader_box_t l14 = vader_box_null(), l20 = vader_box_null();
    vader_string_t l23 = 0;
    void* t0 = NULL;
    int32_t t1;
    int64_t t2;
    bool t3;
    vader_box_t* gc_roots[2] = { &l14, &l20 };
    void** gc_raw_roots[10] = { &l0, &l2, &l3, &l6, &l12, &l13, &l17, &l21, &l22, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l23 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 10u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = vader_array_length(((vader_array_t*) ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_blocks));
    vader_array_t* _a0_arr = vader_array_new(27u, 1u, 7u, 580u);
    ((int32_t*) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = (int32_t) INT32_C(0);
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l1);
    l2 = (void*) _a1_arr;
    l3 = ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_blocks;
    l4 = vader_array_length(((vader_array_t*) l3));
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        t0 = vader_array_ref_load_obj(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l5);
        l6 = vader_midir$successors_of(t0);
        l7 = vader_array_length(((vader_array_t*) l6));
        l8 = INT64_C(0);
        while ((l8 < l7)) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l6);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            l9 = ((int32_t*) _a3_slotarr->buf->slots)[vader_array_offset(_a3_slotarr) + (size_t) l8];
            vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l9)
            t1 = ((int32_t*) _a4_slotarr->buf->slots)[vader_array_offset(_a4_slotarr) + (size_t) l9];
            l10 = vader_chk_add(i32, t1, INT32_C(1));
            VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l9)
            ((int32_t*) _a4_slotarr->buf->slots)[vader_array_offset(_a4_slotarr) + (size_t) l9] = (int32_t) l10;
            l8 = (l8 + INT64_C(1));
        }
        l5 = (l5 + INT64_C(1));
    }
    vader_array_t* _a5_arr = vader_array_new(27u, 1u, 7u, 580u);
    ((int32_t*) _a5_arr->buf->slots)[vader_array_offset(_a5_arr) + 0u] = (int32_t) INT32_C(-1);
    t0 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l1);
    l3 = (void*) _a6_arr;
    l11 = false;
    vader_array_t* _a7_arr = vader_array_new(27u, 0u, 7u, 580u);
    l6 = (void*) _a7_arr;
    l12 = ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_blocks;
    l1 = vader_array_length(((vader_array_t*) l12));
    l4 = INT64_C(0);
    vader_array_t* _pc76_hdr = (vader_array_t*) l6;
    size_t _pc76_len = vader_array_length(_pc76_hdr);
    size_t _pc76_cap = vader_array_is_borrowed(_pc76_hdr) ? (size_t) 0 : vader_array_capacity(_pc76_hdr);
    void* _pc76_slots = _pc76_hdr->buf->slots;
    for (;;) {
        if ((l4 < l1)) {
            vader_array_t* _a8_slotarr = ((vader_array_t*) l12);
            VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
            l13 = vader_array_ref_load_obj(_a8_slotarr->buf, vader_array_offset(_a8_slotarr) + (size_t) l4);
            l14 = ((vader_struct_vader_midir$BasicBlock_t*) l13)->f_terminator;
            t2 = vader_array_length(((vader_array_t*) ((vader_struct_vader_midir$BasicBlock_t*) l13)->f_instructions));
            if (t2 == INT64_C(0)) {
                if (l14.tag == 1876u) {
                    l9 = ((vader_struct_vader_midir$BasicBlock_t*) l13)->f_id;
                    vader_array_t* _a9_slotarr = ((vader_array_t*) l2);
                    VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l9)
                    t1 = ((int32_t*) _a9_slotarr->buf->slots)[vader_array_offset(_a9_slotarr) + (size_t) l9];
                    if ((t1 < INT32_C(2))) {
                        l10 = ((vader_struct_vader_midir$BasicBlock_t*) l13)->f_id;
                        t0 = l14.payload.obj;
                        l15 = ((vader_struct_vader_midir$TermBranch_t*) t0)->f_target;
                        vader_array_t* _a10_slotarr = ((vader_array_t*) l3);
                        VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a10_slotarr, l10)
                        ((int32_t*) _a10_slotarr->buf->slots)[vader_array_offset(_a10_slotarr) + (size_t) l10] = (int32_t) l15;
                        l11 = true;
                    } else {
                        l16 = ((vader_struct_vader_midir$BasicBlock_t*) l13)->f_id;
                        if (VADER_LIKELY(_pc76_len < _pc76_cap)) {
                            ((int32_t*) _pc76_slots)[_pc76_len] = (int32_t) (l16);
                            _pc76_len += 1;
                        } else {
                            vader_array_set_length(_pc76_hdr, _pc76_len);
                            if (_pc76_hdr->buf->length < _pc76_len) {
                                _pc76_hdr->buf->length = _pc76_len;
                            }
                            vader_array_push_i32((vader_array_t*) l6, l16);
                            _pc76_hdr = (vader_array_t*) l6;
                            _pc76_len = vader_array_length(_pc76_hdr);
                            _pc76_cap = vader_array_is_borrowed(_pc76_hdr) ? (size_t) 0 : vader_array_capacity(_pc76_hdr);
                            _pc76_slots = _pc76_hdr->buf->slots;
                        }
                    }
                }
            }
            l4 = (l4 + INT64_C(1));
            continue;
        }
        vader_array_set_length(_pc76_hdr, _pc76_len);
        if (_pc76_hdr->buf->length < _pc76_len) {
            _pc76_hdr->buf->length = _pc76_len;
        }
        break;
    }
    t2 = vader_array_length(((vader_array_t*) l6));
    if ((t2 > INT64_C(0))) {
        l2 = vader_midir$predecessors_of(l0);
        l12 = vader_midir$compute_dominators(l0, l2);
        l12 = vader_midir$natural_loop_bodies(l0, l2, l12);
        l1 = vader_array_length(((vader_array_t*) l6));
        l4 = INT64_C(0);
        while ((l4 < l1)) {
            vader_array_t* _a11_slotarr = ((vader_array_t*) l6);
            VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
            l9 = ((int32_t*) _a11_slotarr->buf->slots)[vader_array_offset(_a11_slotarr) + (size_t) l4];
            l13 = ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_blocks;
            l10 = l9;
            vader_array_t* _a12_slotarr = ((vader_array_t*) l13);
            VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a12_slotarr, l10)
            t0 = vader_array_ref_load_obj(_a12_slotarr->buf, vader_array_offset(_a12_slotarr) + (size_t) l10);
            l14 = ((vader_struct_vader_midir$BasicBlock_t*) t0)->f_terminator;
            if (l14.tag == 1876u) {
                l15 = l9;
                vader_array_t* _a13_slotarr = ((vader_array_t*) l2);
                VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a13_slotarr, l15)
                l17 = vader_array_ref_load_obj(_a13_slotarr->buf, vader_array_offset(_a13_slotarr) + (size_t) l15);
                t0 = l14.payload.obj;
                l16 = ((vader_struct_vader_midir$TermBranch_t*) t0)->f_target;
                t3 = vader_emit_bytecode$goes_on_or_out(l0, l12, l17, l16);
                if (t3) {
                    l18 = l9;
                    t0 = l14.payload.obj;
                    l19 = ((vader_struct_vader_midir$TermBranch_t*) t0)->f_target;
                    vader_array_t* _a14_slotarr = ((vader_array_t*) l3);
                    VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a14_slotarr, l18)
                    ((int32_t*) _a14_slotarr->buf->slots)[vader_array_offset(_a14_slotarr) + (size_t) l18] = (int32_t) l19;
                    l11 = true;
                }
            }
            l4 = (l4 + INT64_C(1));
        }
    }
    if (!(l11)) {
        { void* __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = vader_array_length(((vader_array_t*) ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_blocks));
    vader_array_t* _a15_arr = vader_array_reserve(379u, (int64_t) t2, 13u, 1810u);
    l2 = (void*) _a15_arr;
    l6 = ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_blocks;
    l1 = vader_array_length(((vader_array_t*) l6));
    l4 = INT64_C(0);
    while ((l4 < l1)) {
        vader_array_t* _a16_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a16_slotarr)
        l12 = vader_array_ref_load_obj(_a16_slotarr->buf, vader_array_offset(_a16_slotarr) + (size_t) l4);
        l13 = l12;
        l9 = ((vader_struct_vader_midir$BasicBlock_t*) l13)->f_id;
        l17 = ((vader_struct_vader_midir$BasicBlock_t*) l13)->f_instructions;
        l14 = ((vader_struct_vader_midir$BasicBlock_t*) l12)->f_terminator;
        l20 = vader_emit_bytecode$retargeted(l3, l14);
        l21 = ((vader_struct_vader_midir$BasicBlock_t*) l13)->f_span;
        vader_struct_vader_midir$BasicBlock_t* _a17_obj = (vader_struct_vader_midir$BasicBlock_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$BasicBlock_t));
        vader_obj_header_init(_a17_obj, 1810u);
        _a17_obj->f_id = l9;
        _a17_obj->f_instructions = l17;
        _a17_obj->f_terminator = l20;
        _a17_obj->f_span = l21;
        l22 = (void*) _a17_obj;
        vader_array_push_ref((vader_array_t*) l2, l22);
        l4 = (l4 + INT64_C(1));
    }
    l3 = l0;
    l23 = ((vader_struct_vader_midir$CFGFunction_t*) l3)->f_mangled;
    l6 = ((vader_struct_vader_midir$CFGFunction_t*) l3)->f_params;
    l14 = ((vader_struct_vader_midir$CFGFunction_t*) l3)->f_return_type;
    l12 = ((vader_struct_vader_midir$CFGFunction_t*) l3)->f_locals;
    l9 = ((vader_struct_vader_midir$CFGFunction_t*) l3)->f_entry;
    l13 = ((vader_struct_vader_midir$CFGFunction_t*) l3)->f_origin;
    l3 = ((vader_struct_vader_midir$CFGFunction_t*) l3)->f_scalarised_results;
    vader_struct_vader_midir$CFGFunction_t* _a18_obj = (vader_struct_vader_midir$CFGFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$CFGFunction_t));
    vader_obj_header_init(_a18_obj, 1812u);
    _a18_obj->f_mangled = l23;
    _a18_obj->f_params = l6;
    _a18_obj->f_return_type = l14;
    _a18_obj->f_locals = l12;
    _a18_obj->f_blocks = l2;
    _a18_obj->f_entry = l9;
    _a18_obj->f_origin = l13;
    _a18_obj->f_scalarised_results = l3;
    t0 = (void*) _a18_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_emit_bytecode$struct_decl_of(void* l0) {
    vader_box_t l1;
    void* t0;
    l1 = ((vader_struct_vader_core_mono$MonoEntry_t*) l0)->f_decl;
    if (!(l1.tag == 1091u)) {
        return vader_box_obj(0u, NULL);
    }
    t0 = l1.payload.obj;
    return vader_ref_box(t0);
}

static int32_t vader_emit_bytecode$struct_symbol_id(vader_box_t l0) {
    void* t0;
    int32_t t1;
    if (!(l0.tag == 1364u)) {
        return INT32_C(-1);
    }
    t0 = l0.payload.obj;
    t1 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_core_types$StructType_t*) t0)->f_symbol)->f_id;
    return t1;
}

static void vader_emit_bytecode$structure_function(void* l0) {
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
    l1 = vader_midir$predecessors_of(((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_fn_);
    l2 = ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_fn_;
    l3 = vader_midir$compute_dominators(((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_fn_, l1);
    l1 = vader_emit_bytecode$shape_of(l2, l1, l3);
    l4 = ((vader_struct_vader_midir$CFGFunction_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_fn_)->f_entry;
    vader_emit_bytecode$emit_subtree(l0, l1, l4, INT32_C(-1));
    t0 = vader_array_length(((vader_array_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_pending));
    if (!((t0 > INT64_C(0)))) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l5 = ((vader_struct_vader_midir$CFGFunction_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_fn_)->f_mangled;
    l6 = vader_host_std_core$Intrinsic$byte_len(l5);
    l1 = (void*) vader_buffer_new((size_t) (INT64_C(87) + l6));
    l6 = INT64_C(0);
    l6 = std_core$write_string_at(l1, l6, 2295u);
    l6 = std_core$write_string_at(l1, l6, l5);
    l6 = std_core$write_string_at(l1, l6, 354u);
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_pending);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
    t1 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) INT32_C(0));
    l7 = ((int64_t) (int32_t) ((vader_struct_vader_emit_bytecode$PendingBranch_t*) t1)->f_target_blk);
    l6 = std_core$write_int(l1, l6, l7);
    l6 = std_core$write_string_at(l1, l6, 163u);
    t2 = std_core$finish_buffer(l1, l6);
    vader_host_std_core$Intrinsic$panic(t2);
    vader_unreachable("a no-return call returned");
    vader_gc_top = gc_frame.prev;
}

static bool vader_emit_bytecode$tests_its_exit(void* l0, void* l1, int32_t l2) {
    void* l3;
    void* l5;
    vader_box_t l4;
    int32_t l6;
    bool l7;
    void* t0;
    bool t1;
    l4 = std_collections$Map$std_core$Index$at__i32__Any(l1, l2);
    if (l4.tag == 0u) {
        return false;
    }
    l3 = l4.payload.obj;
    l5 = ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_blocks;
    l6 = l2;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l6)
    t0 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l6);
    l4 = ((vader_struct_vader_midir$BasicBlock_t*) t0)->f_terminator;
    if (l4.tag == 1877u) {
        t0 = l4.payload.obj;
        l6 = ((vader_struct_vader_midir$TermCondBranch_t*) t0)->f_then_block;
        t1 = std_collections$Set$std_core$Contains$contains__i32(l3, l6);
        if (!(t1)) {
            l7 = true;
        } else {
            t0 = l4.payload.obj;
            l6 = ((vader_struct_vader_midir$TermCondBranch_t*) t0)->f_else_block;
            t1 = std_collections$Set$std_core$Contains$contains__i32(l3, l6);
            l7 = !(t1);
        }
        return l7;
    }
    return false;
}

static vader_string_t vader_emit_bytecode$trait_ref_name(void* l0, void* l1) {
    vader_string_t l2 = 0;
    void* l3 = NULL;
    void* l4 = NULL;
    vader_box_t l5 = vader_box_null();
    vader_string_t t0 = 0;
    vader_box_t* gc_roots[1] = { &l5 };
    void** gc_raw_roots[4] = { &l0, &l1, &l3, &l4 };
    vader_string_t* gc_atom_roots[2] = { &l2, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_core_types$trait_key_of(((vader_struct_vader_core_types$TraitType_t*) l0)->f_symbol);
    l3 = ((vader_struct_vader_core_types$TraitType_t*) l0)->f_args;
    l4 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l1)->f_dispatched_instances;
    l5 = vader_core_types$dispatched_instance_key(l2, l3, l4);
    if (l5.tag == 0u) {
        { vader_string_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l5.payload.s;
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_emit_bytecode$try_fold_arith(vader_box_t l0, void* l1, int64_t l2) {
    int64_t l3, l8;
    vader_box_t l4 = vader_box_null(), l5 = vader_box_null(), l11 = vader_box_null();
    int32_t l6, l7;
    uint8_t l9, l10;
    void* t0 = NULL;
    int32_t t1;
    int64_t t2;
    vader_box_t* gc_roots[4] = { &l0, &l4, &l5, &l11 };
    void** gc_raw_roots[2] = { &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if ((l2 < INT64_C(2))) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l3 = vader_chk_sub(i64, l2, INT64_C(1));
    vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
    l4 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l3);
    l3 = vader_chk_sub(i64, l2, INT64_C(2));
    l5 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l3);
    if (l5.tag == 1250u) {
        if (l4.tag == 1250u) {
            if (l0.tag == 1245u) {
                t0 = l5.payload.obj;
                l6 = ((vader_struct_vader_core_bytecode$I32Const_t*) t0)->f_value;
                t0 = l4.payload.obj;
                l7 = ((vader_struct_vader_core_bytecode$I32Const_t*) t0)->f_value;
                vader_struct_vader_core_bytecode$I32Const_t* _a1_obj = (vader_struct_vader_core_bytecode$I32Const_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$I32Const_t));
                vader_obj_header_init(_a1_obj, 1250u);
                _a1_obj->f_value = (l6 + l7);
                t0 = (void*) _a1_obj;
                { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
            }
            if (l0.tag == 1264u) {
                t0 = l5.payload.obj;
                l6 = ((vader_struct_vader_core_bytecode$I32Const_t*) t0)->f_value;
                t0 = l4.payload.obj;
                l7 = ((vader_struct_vader_core_bytecode$I32Const_t*) t0)->f_value;
                vader_struct_vader_core_bytecode$I32Const_t* _a2_obj = (vader_struct_vader_core_bytecode$I32Const_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$I32Const_t));
                vader_obj_header_init(_a2_obj, 1250u);
                _a2_obj->f_value = (l6 - l7);
                t0 = (void*) _a2_obj;
                { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
            }
            if (l0.tag == 1258u) {
                t0 = l5.payload.obj;
                l6 = ((vader_struct_vader_core_bytecode$I32Const_t*) t0)->f_value;
                t0 = l4.payload.obj;
                l7 = ((vader_struct_vader_core_bytecode$I32Const_t*) t0)->f_value;
                vader_struct_vader_core_bytecode$I32Const_t* _a3_obj = (vader_struct_vader_core_bytecode$I32Const_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$I32Const_t));
                vader_obj_header_init(_a3_obj, 1250u);
                _a3_obj->f_value = (l6 * l7);
                t0 = (void*) _a3_obj;
                { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
            }
            if (l0.tag == 1217u) {
                t0 = l5.payload.obj;
                t1 = ((vader_struct_vader_core_bytecode$I32Const_t*) t0)->f_value;
                l3 = ((int64_t) (int32_t) t1);
                t0 = l4.payload.obj;
                t1 = ((vader_struct_vader_core_bytecode$I32Const_t*) t0)->f_value;
                l8 = ((int64_t) (int32_t) t1);
                t0 = l0.payload.obj;
                l9 = ((vader_struct_vader_core_bytecode$CheckedArith_t*) t0)->f_op;
                t0 = l0.payload.obj;
                l10 = ((vader_struct_vader_core_bytecode$CheckedArith_t*) t0)->f_kind;
                l11 = vader_core_bytecode$checked_arith(l9, l10, l3, l8);
                if (l11.tag == 0u) {
                    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
                }
                t2 = ((int64_t) l11.payload.i);
                vader_struct_vader_core_bytecode$I32Const_t* _a4_obj = (vader_struct_vader_core_bytecode$I32Const_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$I32Const_t));
                vader_obj_header_init(_a4_obj, 1250u);
                _a4_obj->f_value = ((int32_t) (int64_t) t2);
                t0 = (void*) _a4_obj;
                { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
            }
        }
    }
    if (l5.tag == 1270u) {
        if (l4.tag == 1270u) {
            if (l0.tag == 1265u) {
                t0 = l5.payload.obj;
                l3 = ((vader_struct_vader_core_bytecode$I64Const_t*) t0)->f_value;
                t0 = l4.payload.obj;
                l8 = ((vader_struct_vader_core_bytecode$I64Const_t*) t0)->f_value;
                vader_struct_vader_core_bytecode$I64Const_t* _a5_obj = (vader_struct_vader_core_bytecode$I64Const_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$I64Const_t));
                vader_obj_header_init(_a5_obj, 1270u);
                _a5_obj->f_value = (l3 + l8);
                t0 = (void*) _a5_obj;
                { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
            }
            if (l0.tag == 1284u) {
                t0 = l5.payload.obj;
                l3 = ((vader_struct_vader_core_bytecode$I64Const_t*) t0)->f_value;
                t0 = l4.payload.obj;
                l8 = ((vader_struct_vader_core_bytecode$I64Const_t*) t0)->f_value;
                vader_struct_vader_core_bytecode$I64Const_t* _a6_obj = (vader_struct_vader_core_bytecode$I64Const_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$I64Const_t));
                vader_obj_header_init(_a6_obj, 1270u);
                _a6_obj->f_value = (l3 - l8);
                t0 = (void*) _a6_obj;
                { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
            }
            if (l0.tag == 1278u) {
                t0 = l5.payload.obj;
                l3 = ((vader_struct_vader_core_bytecode$I64Const_t*) t0)->f_value;
                t0 = l4.payload.obj;
                l8 = ((vader_struct_vader_core_bytecode$I64Const_t*) t0)->f_value;
                vader_struct_vader_core_bytecode$I64Const_t* _a7_obj = (vader_struct_vader_core_bytecode$I64Const_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$I64Const_t));
                vader_obj_header_init(_a7_obj, 1270u);
                _a7_obj->f_value = (l3 * l8);
                t0 = (void*) _a7_obj;
                { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
            }
            if (l0.tag == 1217u) {
                t0 = l0.payload.obj;
                l9 = ((vader_struct_vader_core_bytecode$CheckedArith_t*) t0)->f_op;
                t0 = l0.payload.obj;
                l10 = ((vader_struct_vader_core_bytecode$CheckedArith_t*) t0)->f_kind;
                t0 = l5.payload.obj;
                l3 = ((vader_struct_vader_core_bytecode$I64Const_t*) t0)->f_value;
                t0 = l4.payload.obj;
                l8 = ((vader_struct_vader_core_bytecode$I64Const_t*) t0)->f_value;
                l4 = vader_core_bytecode$checked_arith(l9, l10, l3, l8);
                if (l4.tag == 0u) {
                    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
                }
                t2 = ((int64_t) l4.payload.i);
                vader_struct_vader_core_bytecode$I64Const_t* _a8_obj = (vader_struct_vader_core_bytecode$I64Const_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$I64Const_t));
                vader_obj_header_init(_a8_obj, 1270u);
                _a8_obj->f_value = t2;
                t0 = (void*) _a8_obj;
                { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
            }
        }
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static bool vader_emit_bytecode$try_fuse_local_field(void* l0, int32_t l1, int32_t l2) {
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
    l3 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_slot)->f_body));
    if (l3 == INT64_C(0)) {
        { vader_gc_top = gc_frame.prev; return false; }
    }
    l4 = ((vader_struct_vader_core_bytecode$BcFunction_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_slot)->f_body;
    l5 = vader_chk_sub(i64, l3, INT64_C(1));
    vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
    l6 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l5);
    if (!(l6.tag == 1295u)) {
        { vader_gc_top = gc_frame.prev; return false; }
    }
    t0 = l6.payload.obj;
    l7 = ((vader_struct_vader_core_bytecode$LocalGet_t*) t0)->f_slot;
    l4 = ((vader_struct_vader_core_bytecode$BcFunction_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_slot)->f_body;
    l3 = vader_chk_sub(i64, l3, INT64_C(1));
    vader_struct_vader_core_bytecode$LocalField_t* _a1_obj = (vader_struct_vader_core_bytecode$LocalField_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$LocalField_t));
    vader_obj_header_init(_a1_obj, 1294u);
    _a1_obj->f_slot = l7;
    _a1_obj->f_type_id = l1;
    _a1_obj->f_field_index = l2;
    l8 = (void*) _a1_obj;
    vader_array_t* _a2_slotarr = ((vader_array_t*) l4);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
    vader_array_ref_store(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l3, l8);
    VADER_WRITE_BARRIER(_a2_slotarr->buf);
    { vader_gc_top = gc_frame.prev; return true; }
}

static int32_t vader_emit_bytecode$type_index_of(vader_box_t l0) {
    int32_t l1;
    void* t0;
    if (l0.tag == 1322u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_core_bytecode$StructNew_t*) t0)->f_type_id;
        return l1;
    }
    if (l0.tag == 1321u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_core_bytecode$StructGet_t*) t0)->f_type_id;
    } else if (l0.tag == 1323u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_core_bytecode$StructSet_t*) t0)->f_type_id;
    } else if (l0.tag == 1338u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_core_bytecode$UnionFieldGet_t*) t0)->f_type_id;
    } else if (l0.tag == 1339u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_core_bytecode$UnionFieldSet_t*) t0)->f_type_id;
    } else if (l0.tag == 1169u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_core_bytecode$ArrayNew_t*) t0)->f_type_id;
    } else if (l0.tag == 1167u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_core_bytecode$ArrayGet_t*) t0)->f_type_id;
    } else if (l0.tag == 1175u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_core_bytecode$ArraySet_t*) t0)->f_type_id;
    } else if (l0.tag == 1170u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_core_bytecode$ArrayPush_t*) t0)->f_type_id;
    } else if (l0.tag == 1324u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_core_bytecode$TypeCheck_t*) t0)->f_type_id;
    } else if (l0.tag == 1325u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_core_bytecode$TypeConst_t*) t0)->f_type_id;
    } else if (l0.tag == 1215u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_core_bytecode$CallIndirect_t*) t0)->f_type_id;
    } else if (l0.tag == 1299u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_core_bytecode$MakeClosure_t*) t0)->f_env_type_id;
    } else if (l0.tag == 1242u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_core_bytecode$FnRef_t*) t0)->f_type_id;
    } else if (l0.tag == 1294u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_core_bytecode$LocalField_t*) t0)->f_type_id;
    } else if (l0.tag == 1176u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_core_bytecode$ArraySlice_t*) t0)->f_type_id;
    } else if (l0.tag == 1174u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_core_bytecode$ArrayReserve_t*) t0)->f_type_id;
    } else if (l0.tag == 1303u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_core_bytecode$RefCast_t*) t0)->f_type_id;
    } else if (l0.tag == 1306u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_core_bytecode$Retag_t*) t0)->f_type_id;
    } else if (l0.tag == 1220u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_core_bytecode$DataConst_t*) t0)->f_type_id;
    } else {
        if (!((l0.tag == 1165u || l0.tag == 1166u || l0.tag == 1168u || l0.tag == 1171u || l0.tag == 1172u || l0.tag == 1173u || l0.tag == 1197u || l0.tag == 1198u || l0.tag == 1199u || l0.tag == 1200u || l0.tag == 1201u || l0.tag == 1202u || l0.tag == 1203u || l0.tag == 1204u || l0.tag == 1205u || l0.tag == 1206u || l0.tag == 1207u || l0.tag == 1208u || l0.tag == 1209u || l0.tag == 1210u || l0.tag == 1213u || l0.tag == 1214u || l0.tag == 1216u || l0.tag == 1217u || l0.tag == 1218u || l0.tag == 1219u || l0.tag == 1222u || l0.tag == 1223u || l0.tag == 1224u || l0.tag == 1225u || l0.tag == 1226u || l0.tag == 1227u || l0.tag == 1228u || l0.tag == 1229u || l0.tag == 1230u || l0.tag == 1231u || l0.tag == 1232u || l0.tag == 1233u || l0.tag == 1234u || l0.tag == 1235u || l0.tag == 1236u || l0.tag == 1237u || l0.tag == 1238u || l0.tag == 1239u || l0.tag == 1240u || l0.tag == 1241u || l0.tag == 1243u || l0.tag == 1244u || l0.tag == 1245u || l0.tag == 1246u || l0.tag == 1247u || l0.tag == 1248u || l0.tag == 1249u || l0.tag == 1250u || l0.tag == 1251u || l0.tag == 1252u || l0.tag == 1253u || l0.tag == 1254u || l0.tag == 1255u || l0.tag == 1256u || l0.tag == 1257u || l0.tag == 1258u || l0.tag == 1259u || l0.tag == 1260u || l0.tag == 1261u || l0.tag == 1262u || l0.tag == 1263u || l0.tag == 1264u || l0.tag == 1265u || l0.tag == 1266u || l0.tag == 1267u || l0.tag == 1268u || l0.tag == 1269u || l0.tag == 1270u || l0.tag == 1271u || l0.tag == 1272u || l0.tag == 1273u || l0.tag == 1274u || l0.tag == 1275u || l0.tag == 1276u || l0.tag == 1277u || l0.tag == 1278u || l0.tag == 1279u || l0.tag == 1280u || l0.tag == 1281u || l0.tag == 1282u || l0.tag == 1283u || l0.tag == 1284u || l0.tag == 1285u || l0.tag == 1287u || l0.tag == 1288u || l0.tag == 1289u || l0.tag == 1290u || l0.tag == 1291u || l0.tag == 1292u || l0.tag == 1293u || l0.tag == 1295u || l0.tag == 1296u || l0.tag == 1297u || l0.tag == 1298u || l0.tag == 1301u || l0.tag == 1302u || l0.tag == 1304u || l0.tag == 1305u || l0.tag == 1307u || l0.tag == 1308u || l0.tag == 1309u || l0.tag == 1310u || l0.tag == 1311u || l0.tag == 1312u || l0.tag == 1313u || l0.tag == 1314u || l0.tag == 1315u || l0.tag == 1316u || l0.tag == 1317u || l0.tag == 1318u || l0.tag == 1319u || l0.tag == 1320u || l0.tag == 1326u || l0.tag == 1327u || l0.tag == 1328u || l0.tag == 1329u || l0.tag == 1330u || l0.tag == 1331u || l0.tag == 1332u || l0.tag == 1333u || l0.tag == 1334u || l0.tag == 1335u || l0.tag == 1336u || l0.tag == 1337u || l0.tag == 1340u || l0.tag == 1341u))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = INT32_C(-1);
    }
    return l1;
}

static vader_box_t vader_emit_bytecode$typed_intrinsic_op(void* l0, vader_box_t l1, void* l2) {
    vader_box_t l3 = vader_box_null();
    void* l4 = NULL;
    int64_t l5;
    int32_t t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[2] = { &l1, &l3 };
    void** gc_raw_roots[4] = { &l0, &l2, &l4, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_midir$InstrIntrinsic_t*) l2)->f_dst;
    if (l1.tag == 1174u) {
        if (!(l3.tag == 0u)) {
            l4 = ((vader_struct_vader_midir$CFGFunction_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_fn_)->f_locals;
            t0 = ((int32_t) l3.payload.i);
            l5 = ((int64_t) (int32_t) t0);
            vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
            t1 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l5);
            l3 = ((vader_struct_vader_midir$CFGLocal_t*) t1)->f_type;
            l4 = ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_project;
            t0 = vader_emit_bytecode$intern_type(l3, l4);
            vader_struct_vader_core_bytecode$ArrayReserve_t* _a1_obj = (vader_struct_vader_core_bytecode$ArrayReserve_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$ArrayReserve_t));
            vader_obj_header_init(_a1_obj, 1174u);
            _a1_obj->f_type_id = t0;
            t1 = (void*) _a1_obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        { vader_box_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_box_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_emit_bytecode$unary_leaves_width(uint8_t l0, uint8_t l1) {
    bool l2, l3;
    bool t0;
    t0 = vader_core_bytecode$is_narrow_valtype(l1);
    if (t0) {
        if (l0 == INT32_C(2)) {
            l2 = vader_core_bytecode$is_unsigned_val(l1);
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

static void vader_emit_bytecode$visit_type(int32_t l0, void* l1, void* l2) {
    int64_t l3, l4;
    vader_box_t l5 = vader_box_null();
    void* l6 = NULL;
    bool t0;
    void* t1 = NULL;
    int32_t t2;
    vader_box_t* gc_roots[1] = { &l5 };
    void** gc_raw_roots[4] = { &l1, &l2, &l6, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if ((l0 < INT32_C(0))) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l3 = ((int64_t) (int32_t) l0);
    l4 = vader_array_length(((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l1)->f_types));
    if ((l3 >= l4)) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    t0 = std_collections$add__i32(l2, l0);
    if (!(t0)) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l1)->f_types);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l0)
    l5 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l0);
    if (l5.tag == 1191u) {
        t1 = l5.payload.obj;
        l6 = ((vader_struct_vader_core_bytecode$BcStruct_t*) t1)->f_fields;
        l3 = vader_array_length(((vader_array_t*) l6));
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l6);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            t1 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l4);
            t2 = ((vader_struct_vader_core_bytecode$BcField_t*) t1)->f_type_index;
            vader_emit_bytecode$visit_type(t2, l1, l2);
            l4 = (l4 + INT64_C(1));
        }
    }
    if (l5.tag == 1192u) {
        t1 = l5.payload.obj;
        l6 = ((vader_struct_vader_core_bytecode$BcUnion_t*) t1)->f_variants;
        l3 = vader_array_length(((vader_array_t*) l6));
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) l6);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            t2 = ((int32_t*) _a2_slotarr->buf->slots)[vader_array_offset(_a2_slotarr) + (size_t) l4];
            vader_emit_bytecode$visit_type(t2, l1, l2);
            l4 = (l4 + INT64_C(1));
        }
    }
    if (l5.tag == 1178u) {
        t1 = l5.payload.obj;
        t2 = ((vader_struct_vader_core_bytecode$BcArray_t*) t1)->f_element;
        vader_emit_bytecode$visit_type(t2, l1, l2);
    }
    if (l5.tag == 1181u) {
        t1 = l5.payload.obj;
        l6 = ((vader_struct_vader_core_bytecode$BcFn_t*) t1)->f_params;
        l3 = vader_array_length(((vader_array_t*) l6));
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l6);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            t2 = ((int32_t*) _a3_slotarr->buf->slots)[vader_array_offset(_a3_slotarr) + (size_t) l4];
            vader_emit_bytecode$visit_type(t2, l1, l2);
            l4 = (l4 + INT64_C(1));
        }
        t1 = l5.payload.obj;
        t2 = ((vader_struct_vader_core_bytecode$BcFn_t*) t1)->f_return_type;
        vader_emit_bytecode$visit_type(t2, l1, l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_emit_bytecode$walk_properties(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l7 = NULL;
    void* l12 = NULL;
    void* l16 = NULL;
    int64_t l4, l5, l8, l9, l13, l14, l17, l18;
    uint8_t l6, l15, l19;
    vader_string_t l10 = 0;
    vader_string_t l11 = 0;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null(), t2 = vader_box_null();
    bool t3;
    vader_string_t t4 = 0;
    vader_box_t* gc_roots[2] = { &t1, &t2 };
    void** gc_raw_roots[8] = { &l0, &l1, &l2, &l3, &l7, &l12, &l16, &t0 };
    vader_string_t* gc_atom_roots[3] = { &l10, &l11, &t4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(29u, 0u, 1u, 582u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(24u, 0u, 12u, 575u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(27u, 0u, 7u, 580u);
    l3 = (void*) _a2_arr;
    vader_struct_std_collections$Map__vader_emit_bytecode_BytecodeProperty__bool_t* _a3_obj = (vader_struct_std_collections$Map__vader_emit_bytecode_BytecodeProperty__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__vader_emit_bytecode_BytecodeProperty__bool_t));
    vader_obj_header_init(_a3_obj, 978u);
    _a3_obj->f_ekeys = l1;
    _a3_obj->f_evals = l2;
    _a3_obj->f_index = l3;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a3_obj;
    vader_struct_std_collections$Set__vader_emit_bytecode_BytecodeProperty_t* _a4_obj = (vader_struct_std_collections$Set__vader_emit_bytecode_BytecodeProperty_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Set__vader_emit_bytecode_BytecodeProperty_t));
    vader_obj_header_init(_a4_obj, 994u);
    _a4_obj->f_inner = t0;
    l1 = (void*) _a4_obj;
    l2 = (void*) &vader_data_24;
    l4 = vader_array_length(((vader_array_t*) l2));
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a5_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        t1 = vader_array_read_u8(_a5_slotarr, vader_array_offset(_a5_slotarr) + (size_t) l5, 582u);
        l6 = ((uint8_t) t1.payload.i);
        std_collections$add__vader_emit_bytecode_BytecodeProperty(l1, l6);
        l5 = (l5 + INT64_C(1));
    }
    l2 = l0;
    l4 = vader_array_length(((vader_array_t*) l2));
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a6_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        t1 = vader_array_ref_load_box(_a6_slotarr->buf, vader_array_offset(_a6_slotarr) + (size_t) l5);
        t2 = toolchain_stage$Stage$describe$$dispatch(t1);
        l3 = t2.payload.obj;
        l7 = ((vader_struct_vader_emit_bytecode$BytecodeSpec_t*) l3)->f_requires;
        l8 = vader_array_length(((vader_array_t*) l7));
        l9 = INT64_C(0);
        while ((l9 < l8)) {
            vader_array_t* _a7_slotarr = ((vader_array_t*) l7);
            VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
            t1 = vader_array_read_u8(_a7_slotarr, vader_array_offset(_a7_slotarr) + (size_t) l9, 582u);
            l6 = ((uint8_t) t1.payload.i);
            t3 = std_collections$Set$std_core$Contains$contains__vader_emit_bytecode_BytecodeProperty(l1, l6);
            if (!(t3)) {
                l10 = ((vader_struct_vader_emit_bytecode$BytecodeSpec_t*) l3)->f_name;
                l11 = vader_emit_bytecode$BytecodeProperty$std_core$Display$to_string(l6);
                t4 = concat_5(1267u, l10, 1521u, l11, 1614u);
                vader_struct_toolchain_stage$PlanError_t* _a8_obj = (vader_struct_toolchain_stage$PlanError_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_stage$PlanError_t));
                vader_obj_header_init(_a8_obj, 1162u);
                _a8_obj->f_message = t4;
                t0 = (void*) _a8_obj;
                { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l9 = (l9 + INT64_C(1));
        }
        l12 = ((vader_struct_vader_emit_bytecode$BytecodeSpec_t*) l3)->f_breaks;
        l13 = vader_array_length(((vader_array_t*) l12));
        l14 = INT64_C(0);
        while ((l14 < l13)) {
            vader_array_t* _a9_slotarr = ((vader_array_t*) l12);
            VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
            t1 = vader_array_read_u8(_a9_slotarr, vader_array_offset(_a9_slotarr) + (size_t) l14, 582u);
            l15 = ((uint8_t) t1.payload.i);
            std_collections$remove__vader_emit_bytecode_BytecodeProperty(l1, l15);
            l14 = (l14 + INT64_C(1));
        }
        l16 = ((vader_struct_vader_emit_bytecode$BytecodeSpec_t*) l3)->f_establishes;
        l17 = vader_array_length(((vader_array_t*) l16));
        l18 = INT64_C(0);
        while ((l18 < l17)) {
            vader_array_t* _a10_slotarr = ((vader_array_t*) l16);
            VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
            t1 = vader_array_read_u8(_a10_slotarr, vader_array_offset(_a10_slotarr) + (size_t) l18, 582u);
            l19 = ((uint8_t) t1.payload.i);
            std_collections$add__vader_emit_bytecode_BytecodeProperty(l1, l19);
            l18 = (l18 + INT64_C(1));
        }
        l5 = (l5 + INT64_C(1));
    }
    l2 = (void*) &vader_data_25;
    l4 = vader_array_length(((vader_array_t*) l2));
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a11_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
        t1 = vader_array_read_u8(_a11_slotarr, vader_array_offset(_a11_slotarr) + (size_t) l5, 582u);
        l6 = ((uint8_t) t1.payload.i);
        t3 = std_collections$Set$std_core$Contains$contains__vader_emit_bytecode_BytecodeProperty(l1, l6);
        if (!(t3)) {
            l10 = vader_emit_bytecode$BytecodeProperty$std_core$Display$to_string(l6);
            t4 = concat_3(3205u, l10, 1615u);
            vader_struct_toolchain_stage$PlanError_t* _a12_obj = (vader_struct_toolchain_stage$PlanError_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_stage$PlanError_t));
            vader_obj_header_init(_a12_obj, 1162u);
            _a12_obj->f_message = t4;
            t0 = (void*) _a12_obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l5 = (l5 + INT64_C(1));
    }
    { vader_box_t __vret = vader_ref_box(l0); vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_emit_bytecode$with_param_decorators(void* l0, void* l1) {
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
    l2 = ((vader_struct_vader_core_mono$MonoEntry_t*) l1)->f_decl;
    if (!(l2.tag == 1048u)) {
        { void* __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a0_arr = vader_array_new(24u, 0u, 12u, 575u);
    l3 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(24u, 0u, 12u, 575u);
    l4 = (void*) _a1_arr;
    t0 = l2.payload.obj;
    l5 = ((vader_struct_toolchain_ast$FnDecl_t*) t0)->f_params;
    l6 = vader_array_length(((vader_array_t*) l5));
    l7 = INT64_C(0);
    while ((l7 < l6)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        l8 = vader_array_ref_load_obj(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l7);
        l9 = toolchain_ast$has_compiler_decorator(((vader_struct_toolchain_ast$FnParam_t*) l8)->f_decorators, (uint8_t) 3);
        vader_array_push_bool((vader_array_t*) l3, l9);
        l10 = toolchain_ast$has_compiler_decorator(((vader_struct_toolchain_ast$FnParam_t*) l8)->f_decorators, (uint8_t) 6);
        vader_array_push_bool((vader_array_t*) l4, l10);
        l7 = (l7 + INT64_C(1));
    }
    l8 = l0;
    l11 = ((vader_struct_vader_core_bytecode$BcSignature_t*) l8)->f_params;
    l12 = ((vader_struct_vader_core_bytecode$BcSignature_t*) l8)->f_results;
    l13 = ((vader_struct_vader_core_bytecode$BcSignature_t*) l8)->f_param_types;
    l14 = ((vader_struct_vader_core_bytecode$BcSignature_t*) l8)->f_result_types;
    l15 = ((vader_struct_vader_core_bytecode$BcSignature_t*) l8)->f_param_names;
    l16 = ((vader_struct_vader_core_bytecode$BcSignature_t*) l8)->f_param_c_out;
    l8 = ((vader_struct_vader_core_bytecode$BcSignature_t*) l8)->f_param_by_address;
    vader_struct_vader_core_bytecode$BcSignature_t* _a3_obj = (vader_struct_vader_core_bytecode$BcSignature_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcSignature_t));
    vader_obj_header_init(_a3_obj, 1189u);
    _a3_obj->f_params = l11;
    _a3_obj->f_results = l12;
    _a3_obj->f_param_types = l13;
    _a3_obj->f_result_types = l14;
    _a3_obj->f_param_names = l15;
    _a3_obj->f_param_c_out = l16;
    _a3_obj->f_param_by_address = l8;
    l5 = (void*) _a3_obj;
    t1 = std_core$$array$Contains$contains__bool(l3, true);
    if (t1) {
        ((vader_struct_vader_core_bytecode$BcSignature_t*) l5)->f_param_by_address = l3;
        VADER_WRITE_BARRIER((vader_struct_vader_core_bytecode$BcSignature_t*) l5);
    }
    t1 = std_core$$array$Contains$contains__bool(l4, true);
    if (t1) {
        ((vader_struct_vader_core_bytecode$BcSignature_t*) l5)->f_param_c_out = l4;
        VADER_WRITE_BARRIER((vader_struct_vader_core_bytecode$BcSignature_t*) l5);
        { void* __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { void* __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
}
