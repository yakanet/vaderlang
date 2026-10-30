#include "bootstrap.split.h"

static uint8_t vader_emit_bytecode$array_element_val_type(vader_box_t l0);
static vader_box_t vader_emit_bytecode$baked_value(void* l0, vader_box_t l1);
static void* vader_emit_bytecode$bc_peephole_unchanged(void* l0);
static vader_box_t vader_emit_bytecode$bc_type_of_with_ctx(vader_box_t l0, void* l1);
static bool vader_emit_bytecode$binary_leaves_width(uint8_t l0, uint8_t l1);
static bool vader_emit_bytecode$boxed_element(vader_box_t l0);
static bool vader_emit_bytecode$boxed_field(void* l0, int32_t l1, int64_t l2);
static void* vader_emit_bytecode$boxed_fields_of(void* l0, int32_t l1);
static void* vader_emit_bytecode$boxed_params_of(void* l0, void* l1);
static void* vader_emit_bytecode$build_cfg_signature(void* l0, vader_box_t l1, void* l2, void* l3);
static void* vader_emit_bytecode$build_impl_table_from_vtable(void* l0, void* l1, void* l2);
static void* vader_emit_bytecode$build_intrinsic_wrapper_body(void* l0, int32_t l1);
static void* vader_emit_bytecode$build_vtables_from_entries(void* l0, void* l1);
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
static void* vader_emit_bytecode$coalesce_slots(void* l0);
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
static void* vader_emit_bytecode$drop_dead_stores(void* l0);
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
static int32_t vader_emit_bytecode$loop_exit(void* l0, void* l1, int32_t l2);
static bool vader_emit_bytecode$needs_ref_cast(vader_box_t l0);
static void* vader_emit_bytecode$new_emitter_ctx(void);
static vader_string_t vader_emit_bytecode$no_common_field(void* l0, vader_string_t l1, vader_box_t l2);
static bool vader_emit_bytecode$only_jumps(void* l0, int32_t l1, int32_t l2);
static int32_t vader_emit_bytecode$open_blocks(void* l0, void* l1, int32_t l2);
static int32_t vader_emit_bytecode$outermost_loop_left(void* l0, void* l1, int32_t l2, int32_t l3);
static void* vader_emit_bytecode$param_c_types_of(void* l0);
static void* vader_emit_bytecode$propagate_const_single_use(void* l0);
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
static void* vader_emit_bytecode$run_bc_const_fold_arith(void* l0);
static void* vader_emit_bytecode$run_bc_peephole(void* l0);
static void* vader_emit_bytecode$run_bc_return_lit_fold(void* l0);
static void* vader_emit_bytecode$schedule_stack(void* l0);
static void* vader_emit_bytecode$shape_of(void* l0, void* l1, void* l2);
static void* vader_emit_bytecode$skip_forwarding_blocks(void* l0);
static void* vader_emit_bytecode$strip_self_copies(void* l0);
static int32_t vader_emit_bytecode$struct_symbol_id(vader_box_t l0);
static void vader_emit_bytecode$structure_function(void* l0);
static void vader_emit_bytecode$synthesise_cfg_intrinsic_wrappers(void* l0, void* l1);
static bool vader_emit_bytecode$tests_its_exit(void* l0, void* l1, int32_t l2);
static vader_box_t vader_emit_bytecode$try_fold_arith(vader_box_t l0, void* l1, int64_t l2);
static bool vader_emit_bytecode$try_fuse_local_field(void* l0, int32_t l1, int32_t l2);
static int32_t vader_emit_bytecode$type_index_of(vader_box_t l0);
static bool vader_emit_bytecode$unary_leaves_width(uint8_t l0, uint8_t l1);
static void vader_emit_bytecode$visit_type(int32_t l0, void* l1, void* l2);
static void* vader_emit_bytecode$with_param_decorators(void* l0, void* l1);
static void* vader_emit_bytecode$with_peephole_out(void* l0, void* l1);

static uint8_t vader_emit_bytecode$array_element_val_type(vader_box_t l0) {
    void* t0 = NULL;
    uint8_t t1;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (!(l0.tag == 1019u)) {
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
    if (l1.tag == 1407u) {
        t0 = l1.payload.obj;
        t1 = ((vader_struct_vader_lower_ir$LoweredStringLit_t*) t0)->f_value;
        vader_emit_bytecode$intern_string(t1, l0);
        t0 = l1.payload.obj;
        t1 = ((vader_struct_vader_lower_ir$LoweredStringLit_t*) t0)->f_value;
        vader_struct_vader_core_bytecode$BcValStr_t* _a0_obj = (vader_struct_vader_core_bytecode$BcValStr_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcValStr_t));
        vader_obj_header_init(_a0_obj, 865u);
        _a0_obj->f_value = t1;
        t0 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 1410u) {
        vader_array_t* _a1_arr = vader_array_new(361u, 0u, 13u, 1837u);
        l2 = (void*) _a1_arr;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_lower_ir$LoweredStructLit_t*) t0)->f_fields;
        l4 = ((vader_array_t*) l3)->length;
        l5 = INT64_C(0);
        while ((l5 < l4)) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            t0 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l5);
            l6 = ((vader_struct_vader_lower_ir$LoweredStructLitField_t*) t0)->f_value;
            l7 = vader_emit_bytecode$baked_value(l0, l6);
            vader_array_push_ref((vader_array_t*) l2, l7.payload.obj);
            l5 = (l5 + INT64_C(1));
        }
        t0 = l1.payload.obj;
        t2 = vader_emit_bytecode$struct_symbol_id(((vader_struct_vader_lower_ir$LoweredStructLit_t*) t0)->f_type);
        vader_struct_vader_core_bytecode$BcValStruct_t* _a3_obj = (vader_struct_vader_core_bytecode$BcValStruct_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcValStruct_t));
        vader_obj_header_init(_a3_obj, 866u);
        _a3_obj->f_symbol_id = t2;
        _a3_obj->f_fields = l2;
        t0 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 1367u) {
        vader_array_t* _a4_arr = vader_array_new(361u, 0u, 13u, 1837u);
        l2 = (void*) _a4_arr;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_lower_ir$LoweredArrayLit_t*) t0)->f_elements;
        l4 = ((vader_array_t*) l3)->length;
        l5 = INT64_C(0);
        while ((l5 < l4)) {
            vader_array_t* _a5_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
            l6 = vader_array_ref_load_box(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l5);
            l7 = vader_emit_bytecode$baked_value(l0, l6);
            vader_array_push_ref((vader_array_t*) l2, l7.payload.obj);
            l5 = (l5 + INT64_C(1));
        }
        t0 = l1.payload.obj;
        t2 = vader_emit_bytecode$intern_type(((vader_struct_vader_lower_ir$LoweredArrayLit_t*) t0)->f_type, l0);
        vader_struct_vader_core_bytecode$BcValArray_t* _a6_obj = (vader_struct_vader_core_bytecode$BcValArray_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcValArray_t));
        vader_obj_header_init(_a6_obj, 863u);
        _a6_obj->f_type_id = t2;
        _a6_obj->f_elements = l2;
        t0 = (void*) _a6_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l8 = vader_core_types$representation_name(VADER_UNION_FIELD(vader_box_t, vader_struct_vader_lower_ir$LoweredArrayLen_t, f_type, l1.payload.obj));
    l6 = vader_lower_ir$data_item_bits(l1, l8);
    if (l6.tag == 0u) {
        vader_host_std_abort$panic(1871u);
        vader_unreachable("a no-return call returned");
    } else {
        l4 = ((int64_t) l6.payload.i);
        l9 = vader_core_bytecode$array_kind_from_name(l8);
        t3 = l4;
        l10 = (uint64_t) (int64_t) t3;
        vader_struct_vader_core_bytecode$BcValPrim_t* _a7_obj = (vader_struct_vader_core_bytecode$BcValPrim_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcValPrim_t));
        vader_obj_header_init(_a7_obj, 864u);
        _a7_obj->f_kind = l9;
        _a7_obj->f_bits = l10;
        t0 = (void*) _a7_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_gc_top = gc_frame.prev;
}

static void* vader_emit_bytecode$bc_peephole_unchanged(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_body;
    l2 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_jump_table;
    l3 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_debug;
    vader_struct_vader_emit_bytecode$BcPeepholeOut_t* _a0_obj = (vader_struct_vader_emit_bytecode$BcPeepholeOut_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_bytecode$BcPeepholeOut_t));
    vader_obj_header_init(_a0_obj, 1043u);
    _a0_obj->f_body = l1;
    _a0_obj->f_jump_table = l2;
    _a0_obj->f_debug = l3;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
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
    uint8_t t2;
    vader_box_t t3 = vader_box_null();
    int32_t t4;
    vader_box_t* gc_roots[2] = { &l0, &t3 };
    void** gc_raw_roots[5] = { &l1, &l2, &l3, &l9, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l8, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l0.tag == 1030u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_core_types$PrimitiveType_t*) t0)->f_name;
        t2 = vader_midir_select$val_type_of_primitive_name(t1);
        vader_struct_vader_core_bytecode$BcScalar_t* _a0_obj = (vader_struct_vader_core_bytecode$BcScalar_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcScalar_t));
        vader_obj_header_init(_a0_obj, 858u);
        _a0_obj->f_val = t2;
        t0 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if ((l0.tag == 1021u || l0.tag == 1031u)) {
        t2 = vader_midir_select$val_type_of_type(l0);
        vader_struct_vader_core_bytecode$BcScalar_t* _a1_obj = (vader_struct_vader_core_bytecode$BcScalar_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcScalar_t));
        vader_obj_header_init(_a1_obj, 858u);
        _a1_obj->f_val = t2;
        t0 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1020u) {
        t0 = l0.payload.obj;
        t3 = vader_emit_bytecode$bc_type_of_with_ctx(((vader_struct_vader_core_types$DistinctType_t*) t0)->f_backing, l1);
        { vader_box_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1033u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_core_types$StructType_t*) t0)->f_symbol)->f_name;
        vader_struct_vader_core_bytecode$BcRef_t* _a2_obj = (vader_struct_vader_core_bytecode$BcRef_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcRef_t));
        vader_obj_header_init(_a2_obj, 857u);
        _a2_obj->f_trait_name = t1;
        t0 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1035u) {
        t0 = l0.payload.obj;
        t1 = vader_core_types$trait_key_of(((vader_struct_vader_core_types$TraitType_t*) t0)->f_symbol);
        vader_struct_vader_core_bytecode$BcRef_t* _a3_obj = (vader_struct_vader_core_bytecode$BcRef_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcRef_t));
        vader_obj_header_init(_a3_obj, 857u);
        _a3_obj->f_trait_name = t1;
        t0 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1019u) {
        t0 = l0.payload.obj;
        t4 = vader_emit_bytecode$intern_type(((vader_struct_vader_core_types$ArrayType_t*) t0)->f_element, l1);
        vader_struct_vader_core_bytecode$BcArray_t* _a4_obj = (vader_struct_vader_core_bytecode$BcArray_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcArray_t));
        vader_obj_header_init(_a4_obj, 848u);
        _a4_obj->f_element = t4;
        t0 = (void*) _a4_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1041u) {
        vader_array_t* _a5_arr = vader_array_new(23u, 0u, 7u, 450u);
        l2 = (void*) _a5_arr;
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_core_types$UnionType_t*) t0)->f_variants;
        l4 = ((vader_array_t*) l3)->length;
        l5 = INT64_C(0);
        while ((l5 < l4)) {
            vader_array_t* _a6_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
            t3 = vader_array_ref_load_box(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l5);
            l6 = vader_emit_bytecode$intern_type(t3, l1);
            vader_array_push_i32((vader_array_t*) l2, l6);
            l5 = (l5 + INT64_C(1));
        }
        vader_struct_vader_core_bytecode$BcUnion_t* _a7_obj = (vader_struct_vader_core_bytecode$BcUnion_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcUnion_t));
        vader_obj_header_init(_a7_obj, 862u);
        _a7_obj->f_variants = l2;
        t0 = (void*) _a7_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1022u) {
        vader_array_t* _a8_arr = vader_array_new(23u, 0u, 7u, 450u);
        l2 = (void*) _a8_arr;
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_core_types$FnType_t*) t0)->f_params;
        l4 = ((vader_array_t*) l3)->length;
        l5 = INT64_C(0);
        while ((l5 < l4)) {
            vader_array_t* _a9_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
            t3 = vader_array_ref_load_box(_a9_slotarr->buf, _a9_slotarr->offset + (size_t) l5);
            l6 = vader_emit_bytecode$intern_type(t3, l1);
            vader_array_push_i32((vader_array_t*) l2, l6);
            l5 = (l5 + INT64_C(1));
        }
        t0 = l0.payload.obj;
        l6 = vader_emit_bytecode$intern_type(((vader_struct_vader_core_types$FnType_t*) t0)->f_return_type, l1);
        vader_struct_vader_core_bytecode$BcFn_t* _a10_obj = (vader_struct_vader_core_bytecode$BcFn_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcFn_t));
        vader_obj_header_init(_a10_obj, 851u);
        _a10_obj->f_params = l2;
        _a10_obj->f_return_type = l6;
        t0 = (void*) _a10_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1036u) {
        vader_array_t* _a11_arr = vader_array_new(69u, 0u, 13u, 850u);
        l2 = (void*) _a11_arr;
        l4 = INT64_C(0);
        t0 = l0.payload.obj;
        l5 = ((vader_array_t*) ((vader_struct_vader_core_types$TupleType_t*) t0)->f_elements)->length;
        while ((l4 < l5)) {
            l3 = (void*) vader_buffer_new((size_t) INT64_C(21));
            l7 = INT64_C(0);
            l7 = std_core$write_string_at(l3, l7, 976u);
            l7 = std_core$write_int(l3, l7, l4);
            l8 = std_core$finish_buffer(l3, l7);
            t0 = l0.payload.obj;
            vader_array_t* _a12_slotarr = ((vader_array_t*) ((vader_struct_vader_core_types$TupleType_t*) t0)->f_elements);
            VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a12_slotarr, l4)
            t3 = vader_array_ref_load_box(_a12_slotarr->buf, _a12_slotarr->offset + (size_t) l4);
            l6 = vader_emit_bytecode$intern_type(t3, l1);
            vader_struct_vader_core_bytecode$BcField_t* _a13_obj = (vader_struct_vader_core_bytecode$BcField_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcField_t));
            vader_obj_header_init(_a13_obj, 850u);
            _a13_obj->f_name = l8;
            _a13_obj->f_type_index = l6;
            l9 = (void*) _a13_obj;
            vader_array_push_ref((vader_array_t*) l2, l9);
            l4 = (l4 + INT64_C(1));
        }
        t0 = l0.payload.obj;
        l8 = vader_midir_select$tuple_shape_name(((vader_struct_vader_core_types$TupleType_t*) t0)->f_elements);
        t1 = concat_2(990u, l8);
        vader_struct_vader_core_bytecode$BcStruct_t* _a14_obj = (vader_struct_vader_core_bytecode$BcStruct_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcStruct_t));
        vader_obj_header_init(_a14_obj, 861u);
        _a14_obj->f_name = t1;
        _a14_obj->f_fields = l2;
        _a14_obj->f_c_name = 0u;
        _a14_obj->f_symbol_id = INT32_C(-1);
        t0 = (void*) _a14_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1038u) {
        t0 = (void*) &vader_data_40;
        vader_array_t* _a15_slotarr = ((vader_array_t*) t0);
        VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
        t0 = vader_array_ref_load_obj(_a15_slotarr->buf, _a15_slotarr->offset + (size_t) INT64_C(0));
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1026u) {
        t0 = l0.payload.obj;
        vader_core_types$leaked_infer_var(t0);
        vader_unreachable("a no-return call returned");
    } else {
        if (l0.tag == 1037u) {
            t0 = (void*) &vader_data_40;
            vader_array_t* _a16_slotarr = ((vader_array_t*) t0);
            VADER_ARRAY_RESOLVE_BUF(_a16_slotarr)
            t0 = vader_array_ref_load_obj(_a16_slotarr->buf, _a16_slotarr->offset + (size_t) INT64_C(0));
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l0.tag == 1032u) {
            t0 = (void*) &vader_data_40;
            vader_array_t* _a17_slotarr = ((vader_array_t*) t0);
            VADER_ARRAY_RESOLVE_BUF(_a17_slotarr)
            t0 = vader_array_ref_load_obj(_a17_slotarr->buf, _a17_slotarr->offset + (size_t) INT64_C(0));
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l0.tag == 1042u) {
            t0 = (void*) &vader_data_40;
            vader_array_t* _a18_slotarr = ((vader_array_t*) t0);
            VADER_ARRAY_RESOLVE_BUF(_a18_slotarr)
            t0 = vader_array_ref_load_obj(_a18_slotarr->buf, _a18_slotarr->offset + (size_t) INT64_C(0));
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l0.tag == 1025u) {
            t0 = (void*) &vader_data_40;
            vader_array_t* _a19_slotarr = ((vader_array_t*) t0);
            VADER_ARRAY_RESOLVE_BUF(_a19_slotarr)
            t0 = vader_array_ref_load_obj(_a19_slotarr->buf, _a19_slotarr->offset + (size_t) INT64_C(0));
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l0.tag == 1023u) {
            t0 = (void*) &vader_data_40;
            vader_array_t* _a20_slotarr = ((vader_array_t*) t0);
            VADER_ARRAY_RESOLVE_BUF(_a20_slotarr)
            t0 = vader_array_ref_load_obj(_a20_slotarr->buf, _a20_slotarr->offset + (size_t) INT64_C(0));
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l0.tag == 1024u) {
            t0 = (void*) &vader_data_40;
            vader_array_t* _a21_slotarr = ((vader_array_t*) t0);
            VADER_ARRAY_RESOLVE_BUF(_a21_slotarr)
            t0 = vader_array_ref_load_obj(_a21_slotarr->buf, _a21_slotarr->offset + (size_t) INT64_C(0));
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l0.tag == 1028u) {
            t0 = (void*) &vader_data_40;
            vader_array_t* _a22_slotarr = ((vader_array_t*) t0);
            VADER_ARRAY_RESOLVE_BUF(_a22_slotarr)
            t0 = vader_array_ref_load_obj(_a22_slotarr->buf, _a22_slotarr->offset + (size_t) INT64_C(0));
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (!(l0.tag == 1018u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        t0 = (void*) &vader_data_40;
        vader_array_t* _a23_slotarr = ((vader_array_t*) t0);
        VADER_ARRAY_RESOLVE_BUF(_a23_slotarr)
        t0 = vader_array_ref_load_obj(_a23_slotarr->buf, _a23_slotarr->offset + (size_t) INT64_C(0));
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
    l3 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l1);
    if (l3.tag == 861u) {
        t0 = l3.payload.obj;
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcStruct_t*) t0)->f_fields);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l2)
        t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l2);
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
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[6] = { &l0, &l3, &l4, &l5, &l8, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 6u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_types);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    l2 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l1);
    if (!(l2.tag == 861u)) {
        vader_array_t* _a1_arr = vader_array_new(20u, 0u, 12u, 445u);
        t0 = (void*) _a1_arr;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l2.payload.obj;
    l3 = ((vader_struct_vader_core_bytecode$BcStruct_t*) t0)->f_fields;
    vader_struct___lambda_env_vader_emit_bytecode_14_t* _a2_obj = (vader_struct___lambda_env_vader_emit_bytecode_14_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_emit_bytecode_14_t));
    vader_obj_header_init(_a2_obj, 476u);
    _a2_obj->f_cap_0 = l0;
    l4 = (void*) _a2_obj;
    vader_array_t* _a3_arr = vader_array_new(20u, 0u, 12u, 445u);
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
            l9 = __lambda_vader_emit_bytecode_13(l4, l8);
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

static void* vader_emit_bytecode$boxed_params_of(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    int64_t l5, l6;
    int32_t l7;
    bool l8;
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_core_bytecode$BcSignature_t*) l1)->f_param_types;
    vader_struct___lambda_env_vader_emit_bytecode_12_t* _a0_obj = (vader_struct___lambda_env_vader_emit_bytecode_12_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_emit_bytecode_12_t));
    vader_obj_header_init(_a0_obj, 475u);
    _a0_obj->f_cap_0 = l0;
    l3 = (void*) _a0_obj;
    vader_array_t* _a1_arr = vader_array_new(20u, 0u, 12u, 445u);
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
            l8 = __lambda_vader_emit_bytecode_11(l3, l7);
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

static void* vader_emit_bytecode$build_cfg_signature(void* l0, vader_box_t l1, void* l2, void* l3) {
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
    vader_array_t* _a0_arr = vader_array_new(25u, 0u, 1u, 452u);
    l4 = (void*) _a0_arr;
    l5 = ((vader_array_t*) l0)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l4, (int64_t) l5);
    l4 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(23u, 0u, 7u, 450u);
    l6 = (void*) _a2_arr;
    l5 = ((vader_array_t*) l0)->length;
    vader_array_t* _a3_arr = vader_array_repeat((vader_array_t*) l6, (int64_t) l5);
    l6 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_new(22u, 0u, 0u, 447u);
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
        l11 = vader_midir_select$val_type_of_type(((vader_struct_vader_midir$CFGParam_t*) l10)->f_type);
        vader_array_push_u8((vader_array_t*) l4, (int32_t) (uint8_t) l11);
        l12 = vader_emit_bytecode$intern_type(((vader_struct_vader_midir$CFGParam_t*) l10)->f_type, l3);
        vader_array_push_i32((vader_array_t*) l6, l12);
        l13 = ((vader_struct_vader_midir$CFGParam_t*) l10)->f_name;
        vader_array_push_scalar((vader_array_t*) l7, vader_box_string(447u, l13));
        l9 = (l9 + INT64_C(1));
    }
    vader_array_t* _a7_arr = vader_array_new(25u, 0u, 1u, 452u);
    l8 = (void*) _a7_arr;
    vader_array_t* _a8_arr = vader_array_new(23u, 0u, 7u, 450u);
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
            l11 = vader_midir_select$val_type_of_type(l15);
            vader_array_push_u8((vader_array_t*) l8, (int32_t) (uint8_t) l11);
            l12 = vader_emit_bytecode$intern_type(l15, l3);
            vader_array_push_i32((vader_array_t*) l10, l12);
            l9 = (l9 + INT64_C(1));
        }
    } else {
        l11 = vader_midir_select$val_type_of_type(l1);
        vader_array_push_u8((vader_array_t*) l8, (int32_t) (uint8_t) l11);
        l12 = vader_emit_bytecode$intern_type(l1, l3);
        vader_array_push_i32((vader_array_t*) l10, l12);
    }
    vader_array_t* _a10_arr = vader_array_new(20u, 0u, 12u, 445u);
    l14 = (void*) _a10_arr;
    vader_array_t* _a11_arr = vader_array_new(20u, 0u, 12u, 445u);
    l16 = (void*) _a11_arr;
    vader_struct_vader_core_bytecode$BcSignature_t* _a12_obj = (vader_struct_vader_core_bytecode$BcSignature_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcSignature_t));
    vader_obj_header_init(_a12_obj, 859u);
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

static void* vader_emit_bytecode$build_impl_table_from_vtable(void* l0, void* l1, void* l2) {
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
    vader_array_t* _a0_arr = vader_array_new(144u, 0u, 13u, 956u);
    l3 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(22u, 0u, 0u, 447u);
    l4 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(20u, 0u, 12u, 445u);
    l5 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(23u, 0u, 7u, 450u);
    l6 = (void*) _a3_arr;
    vader_struct_std_collections$MutableMap__string__bool_t* _a4_obj = (vader_struct_std_collections$MutableMap__string__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__string__bool_t));
    vader_obj_header_init(_a4_obj, 662u);
    _a4_obj->f_ekeys = l4;
    _a4_obj->f_evals = l5;
    _a4_obj->f_index = l6;
    _a4_obj->f_mask = INT64_C(0);
    _a4_obj->f_grow_at = INT64_C(0);
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
        l9 = vader_midir_select$type_intern_key(((vader_struct_vader_lower_ir$LoweredVtableEntry_t*) l6)->f_struct_type);
        l10 = std_collections$MutableMap$std_core$Index$at__string__i32(((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l2)->f_type_key, l9);
        if (l10.tag == 450u) {
            l11 = ((int32_t) l10.payload.i);
            l12 = ((int64_t) (int32_t) l11);
            if ((INT64_C(0) <= l12)) {
                l14 = ((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l2)->f_types)->length;
                l13 = (l12 < l14);
            } else {
                l13 = false;
            }
            if (l13) {
                vader_array_t* _a6_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l2)->f_types);
                VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l11)
                t0 = vader_array_ref_load_box(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l11);
                if (!((t0.tag == 848u || t0.tag == 861u))) {
                    l8 = (l8 + INT64_C(1));
                    continue;
                }
            }
            l16 = ((vader_struct_vader_lower_ir$LoweredVtableEntry_t*) l6)->f_trait_name;
            l17 = vader_host_std_core$byte_len(l16);
            l18 = (void*) vader_buffer_new((size_t) (INT64_C(21) + l17));
            l19 = INT64_C(0);
            l20 = ((int64_t) (int32_t) l11);
            l19 = std_core$write_int(l18, l19, l20);
            l19 = std_core$write_string_at(l18, l19, 3063u);
            l19 = std_core$write_string_at(l18, l19, l16);
            l15 = std_core$finish_buffer(l18, l19);
            t0 = std_collections$MutableMap$std_core$Index$at__string__bool(l4, l15);
            if (t0.tag == 445u) {
                l8 = (l8 + INT64_C(1));
                continue;
            }
            std_collections$MutableMap$std_core$IndexSet$set_at__string__bool(l4, l15, true);
            l21 = ((vader_struct_vader_lower_ir$LoweredVtableEntry_t*) l6)->f_trait_name;
            vader_struct_vader_core_bytecode$ImplEntry_t* _a7_obj = (vader_struct_vader_core_bytecode$ImplEntry_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$ImplEntry_t));
            vader_obj_header_init(_a7_obj, 956u);
            _a7_obj->f_type_index = l11;
            _a7_obj->f_trait_name = l21;
            l22 = (void*) _a7_obj;
            vader_array_push_ref((vader_array_t*) l3, l22);
            l8 = (l8 + INT64_C(1));
            continue;
        }
        l8 = (l8 + INT64_C(1));
    }
    l7 = INT64_C(0);
    l8 = ((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l2)->f_types)->length;
    while ((l7 < l8)) {
        vader_array_t* _a8_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l2)->f_types);
        VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l7)
        l10 = vader_array_ref_load_box(_a8_slotarr->buf, _a8_slotarr->offset + (size_t) l7);
        if (l10.tag == 861u) {
            t1 = l10.payload.obj;
            l11 = ((vader_struct_vader_core_bytecode$BcStruct_t*) t1)->f_symbol_id;
            l23 = std_collections$MutableMap$std_core$Index$at__i32__string__(l1, l11);
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
                l17 = vader_host_std_core$byte_len(l16);
                l6 = (void*) vader_buffer_new((size_t) (INT64_C(21) + l17));
                l19 = INT64_C(0);
                l19 = std_core$write_int(l6, l19, l7);
                l19 = std_core$write_string_at(l6, l19, 3063u);
                l19 = std_core$write_string_at(l6, l19, l16);
                l15 = std_core$finish_buffer(l6, l19);
                t0 = std_collections$MutableMap$std_core$Index$at__string__bool(l4, l15);
                if (t0.tag == 445u) {
                    l14 = (l14 + INT64_C(1));
                    continue;
                }
                std_collections$MutableMap$std_core$IndexSet$set_at__string__bool(l4, l15, true);
                vader_struct_vader_core_bytecode$ImplEntry_t* _a10_obj = (vader_struct_vader_core_bytecode$ImplEntry_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$ImplEntry_t));
                vader_obj_header_init(_a10_obj, 956u);
                _a10_obj->f_type_index = ((int32_t) (int64_t) l7);
                _a10_obj->f_trait_name = l9;
                l18 = (void*) _a10_obj;
                vader_array_push_ref((vader_array_t*) l3, l18);
                l14 = (l14 + INT64_C(1));
            }
        }
        l7 = (l7 + INT64_C(1));
    }
    { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_emit_bytecode$build_intrinsic_wrapper_body(void* l0, int32_t l1) {
    void* l2 = NULL;
    void* l5 = NULL;
    int64_t l3, l4;
    vader_box_t l6 = vader_box_null();
    vader_string_t t0 = 0;
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &l6 };
    void** gc_raw_roots[4] = { &l0, &l2, &l5, &t1 };
    vader_string_t* gc_atom_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(358u, 0u, 13u, 1803u);
    l2 = (void*) _a0_arr;
    l3 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcImport_t*) l0)->f_signature)->f_params)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l2, (int64_t) l3);
    l2 = (void*) _a1_arr;
    l3 = INT64_C(0);
    l4 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcImport_t*) l0)->f_signature)->f_params)->length;
    while ((l3 < l4)) {
        vader_struct_vader_core_bytecode$LocalGet_t* _a2_obj = (vader_struct_vader_core_bytecode$LocalGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$LocalGet_t));
        vader_obj_header_init(_a2_obj, 965u);
        _a2_obj->f_slot = ((int32_t) (int64_t) l3);
        l5 = (void*) _a2_obj;
        vader_array_push_ref((vader_array_t*) l2, l5);
        l3 = (l3 + INT64_C(1));
    }
    t0 = ((vader_struct_vader_core_bytecode$BcImport_t*) l0)->f_mangled_name;
    l6 = vader_midir_select$intrinsic_op_for_mangled(t0);
    if (l6.tag == 0u) {
        vader_struct_vader_core_bytecode$CallImport_t* _a3_obj = (vader_struct_vader_core_bytecode$CallImport_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$CallImport_t));
        vader_obj_header_init(_a3_obj, 884u);
        _a3_obj->f_index = l1;
        l5 = (void*) _a3_obj;
        vader_array_push_ref((vader_array_t*) l2, l5);
    } else {
        vader_array_push_ref((vader_array_t*) l2, l6.payload.obj);
    }
    t1 = (void*) &vader_data_62;
    vader_array_t* _a4_slotarr = ((vader_array_t*) t1);
    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
    l5 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) INT64_C(0));
    vader_array_push_ref((vader_array_t*) l2, l5);
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_emit_bytecode$build_vtables_from_entries(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l11 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    void* l21 = NULL;
    void* l22 = NULL;
    void* l23 = NULL;
    int64_t l5, l6, l7, l8;
    vader_box_t l9 = vader_box_null(), l19 = vader_box_null();
    vader_string_t l10 = 0;
    vader_string_t l15 = 0;
    vader_string_t l16 = 0;
    vader_string_t l18 = 0;
    int32_t l17, l20;
    void* t0 = NULL;
    bool t1;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l9, &l19, &t2 };
    void** gc_raw_roots[13] = {
        &l0, &l1, &l2, &l3, &l4, &l11, &l12, &l13, &l14, &l21, &l22, &l23, &t0,
    };
    vader_string_t* gc_atom_roots[4] = { &l10, &l15, &l16, &l18 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 13u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(22u, 0u, 0u, 447u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(20u, 0u, 12u, 445u);
    l3 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(23u, 0u, 7u, 450u);
    l4 = (void*) _a2_arr;
    vader_struct_std_collections$MutableMap__string__bool_t* _a3_obj = (vader_struct_std_collections$MutableMap__string__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__string__bool_t));
    vader_obj_header_init(_a3_obj, 662u);
    _a3_obj->f_ekeys = l2;
    _a3_obj->f_evals = l3;
    _a3_obj->f_index = l4;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    l2 = (void*) _a3_obj;
    l3 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l1)->f_functions;
    l5 = ((vader_array_t*) l3)->length;
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        t0 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l6);
        l4 = ((vader_struct_vader_core_bytecode$BcFunction_t*) t0)->f_body;
        l7 = ((vader_array_t*) l4)->length;
        l8 = INT64_C(0);
        while ((l8 < l7)) {
            vader_array_t* _a5_slotarr = ((vader_array_t*) l4);
            VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
            l9 = vader_array_ref_load_box(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l8);
            if (l9.tag == 1010u) {
                t0 = l9.payload.obj;
                l10 = ((vader_struct_vader_core_bytecode$VirtualCall_t*) t0)->f_vtable_key;
                std_collections$MutableMap$std_core$IndexSet$set_at__string__bool(l2, l10, true);
            }
            l8 = (l8 + INT64_C(1));
        }
        l6 = (l6 + INT64_C(1));
    }
    vader_array_t* _a6_arr = vader_array_new(22u, 0u, 0u, 447u);
    l3 = (void*) _a6_arr;
    vader_array_t* _a7_arr = vader_array_new(24u, 0u, 8u, 451u);
    l4 = (void*) _a7_arr;
    vader_array_t* _a8_arr = vader_array_new(23u, 0u, 7u, 450u);
    l11 = (void*) _a8_arr;
    vader_struct_std_collections$MutableMap__string__i64_t* _a9_obj = (vader_struct_std_collections$MutableMap__string__i64_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__string__i64_t));
    vader_obj_header_init(_a9_obj, 665u);
    _a9_obj->f_ekeys = l3;
    _a9_obj->f_evals = l4;
    _a9_obj->f_index = l11;
    _a9_obj->f_mask = INT64_C(0);
    _a9_obj->f_grow_at = INT64_C(0);
    _a9_obj->f_size = INT64_C(0);
    _a9_obj->f_tombs = INT64_C(0);
    l3 = (void*) _a9_obj;
    vader_array_t* _a10_arr = vader_array_new(171u, 0u, 13u, 1012u);
    l4 = (void*) _a10_arr;
    vader_array_t* _a11_arr = vader_array_new(305u, 0u, 13u, 1418u);
    l11 = (void*) _a11_arr;
    vader_array_t* _a12_arr = vader_array_new(305u, 0u, 13u, 1418u);
    l12 = (void*) _a12_arr;
    l13 = l0;
    l5 = ((vader_array_t*) l13)->length;
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a13_slotarr = ((vader_array_t*) l13);
        VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
        l14 = vader_array_ref_load_obj(_a13_slotarr->buf, _a13_slotarr->offset + (size_t) l6);
        t1 = vader_core_types$boxes_as_representation(((vader_struct_vader_lower_ir$LoweredVtableEntry_t*) l14)->f_struct_type);
        if (t1) {
            vader_array_push_ref((vader_array_t*) l12, l14);
        } else {
            vader_array_push_ref((vader_array_t*) l11, l14);
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
        l10 = ((vader_struct_vader_lower_ir$LoweredVtableEntry_t*) l12)->f_trait_name;
        l15 = ((vader_struct_vader_lower_ir$LoweredVtableEntry_t*) l12)->f_method_name;
        l16 = vader_midir$vtable_key(l10, l15);
        t2 = std_collections$MutableMap$std_core$Index$at__string__bool(l2, l16);
        if (t2.tag == 445u) {
            l9 = vader_emit_bytecode$resolve_fn_index(((vader_struct_vader_lower_ir$LoweredVtableEntry_t*) l12)->f_fn_symbol, l1);
            if (l9.tag == 0u) {
                l6 = (l6 + INT64_C(1));
                continue;
            }
            l17 = ((int32_t) l9.payload.i);
            l18 = vader_midir_select$type_intern_key(((vader_struct_vader_lower_ir$LoweredVtableEntry_t*) l12)->f_struct_type);
            l19 = std_collections$MutableMap$std_core$Index$at__string__i32(((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l1)->f_type_key, l18);
            if (l19.tag == 450u) {
                l20 = ((int32_t) l19.payload.i);
                l7 = ((vader_array_t*) l4)->length;
                l8 = std_collections$get_or_put__string__i64(l3, l16, l7);
                if (l8 != l7) {
                    vader_array_t* _a15_slotarr = ((vader_array_t*) l4);
                    VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a15_slotarr, l8)
                    t0 = vader_array_ref_load_obj(_a15_slotarr->buf, _a15_slotarr->offset + (size_t) l8);
                    t1 = vader_emit_bytecode$has_receiver(t0, l20);
                    if (t1) {
                        l6 = (l6 + INT64_C(1));
                        continue;
                    }
                    vader_array_t* _a16_slotarr = ((vader_array_t*) l4);
                    VADER_ARRAY_RESOLVE_BUF(_a16_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a16_slotarr, l8)
                    t0 = vader_array_ref_load_obj(_a16_slotarr->buf, _a16_slotarr->offset + (size_t) l8);
                    l13 = ((vader_struct_vader_core_bytecode$VtableRow_t*) t0)->f_entries;
                    vader_struct_vader_core_bytecode$VtableEntry_t* _a17_obj = (vader_struct_vader_core_bytecode$VtableEntry_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$VtableEntry_t));
                    vader_obj_header_init(_a17_obj, 1011u);
                    _a17_obj->f_receiver_type_index = l20;
                    _a17_obj->f_fn_index = l17;
                    l14 = (void*) _a17_obj;
                    vader_array_push_ref((vader_array_t*) l13, l14);
                } else {
                    vader_array_t* _a18_arr = vader_array_new(170u, 0u, 13u, 1011u);
                    l21 = (void*) _a18_arr;
                    vader_struct_vader_core_bytecode$VtableEntry_t* _a19_obj = (vader_struct_vader_core_bytecode$VtableEntry_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$VtableEntry_t));
                    vader_obj_header_init(_a19_obj, 1011u);
                    _a19_obj->f_receiver_type_index = l20;
                    _a19_obj->f_fn_index = l17;
                    l22 = (void*) _a19_obj;
                    vader_array_push_ref((vader_array_t*) l21, l22);
                    vader_struct_vader_core_bytecode$VtableRow_t* _a20_obj = (vader_struct_vader_core_bytecode$VtableRow_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$VtableRow_t));
                    vader_obj_header_init(_a20_obj, 1012u);
                    _a20_obj->f_key = l16;
                    _a20_obj->f_entries = l21;
                    l23 = (void*) _a20_obj;
                    vader_array_push_ref((vader_array_t*) l4, l23);
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

static vader_string_t vader_emit_bytecode$c_struct_of(void* l0) {
    vader_box_t l1;
    void* l2;
    vader_string_t l3;
    void* t0;
    vader_string_t t1;
    l1 = ((vader_struct_vader_core_mono$MonoEntry_t*) l0)->f_decl;
    if (!(l1.tag == 816u)) {
        return 0u;
    }
    t0 = l1.payload.obj;
    l2 = ((vader_struct_toolchain_ast$StructDecl_t*) t0)->f_decorators;
    t0 = l1.payload.obj;
    l3 = ((vader_struct_toolchain_ast$StructDecl_t*) t0)->f_name;
    t1 = toolchain_ast$c_struct_spelling(l2, l3);
    return t1;
}

static bool vader_emit_bytecode$can_pass_through_stack(vader_box_t l0, vader_box_t l1, void* l2) {
    int32_t l3;
    vader_box_t l4;
    int32_t t0;
    bool t1;
    l4 = vader_midir$dst_of(l0);
    if (l4.tag == 0u) {
        return false;
    }
    l3 = ((int32_t) l4.payload.i);
    l4 = std_collections$MutableMap$std_core$Index$at__i32__i32(l2, l3);
    if (l4.tag == 0u) {
        return false;
    }
    t0 = ((int32_t) l4.payload.i);
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
    int32_t t0;
    bool t1;
    l4 = vader_midir$dst_of(l0);
    if (l4.tag == 0u) {
        return false;
    }
    l3 = ((int32_t) l4.payload.i);
    l4 = std_collections$MutableMap$std_core$Index$at__i32__i32(l2, l3);
    if (l4.tag == 0u) {
        return false;
    }
    t0 = ((int32_t) l4.payload.i);
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
    t0 = (void*) &vader_data_65;
    vader_array_t* _a0_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    l3 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT64_C(0));
    l4 = vader_emit_bytecode$push_op_with_span(l0, vader_ref_box(l3), l1);
    l3 = ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_scopes;
    vader_struct_vader_emit_bytecode$ScopeFrame_t* _a1_obj = (vader_struct_vader_emit_bytecode$ScopeFrame_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_bytecode$ScopeFrame_t));
    vader_obj_header_init(_a1_obj, 1050u);
    _a1_obj->f_kind = 1631u;
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
    t0 = (void*) &vader_data_66;
    vader_array_t* _a0_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    l3 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT64_C(0));
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
    t0 = (void*) &vader_data_73;
    vader_array_t* _a0_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    l3 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT64_C(0));
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
    t0 = (void*) &vader_data_75;
    vader_array_t* _a0_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    l2 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT64_C(0));
    l3 = vader_emit_bytecode$push_op_with_span(l0, vader_ref_box(l2), l1);
    l4 = ((vader_array_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_scopes)->length;
    if (!(l4 == INT64_C(0))) {
        l2 = ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_scopes;
        l5 = vader_chk_sub(i64, l4, INT64_C(1));
        vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
        l2 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5);
        l6 = ((vader_struct_vader_core_bytecode$BcFunction_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_slot)->f_jump_table;
        l7 = ((vader_struct_vader_emit_bytecode$ScopeFrame_t*) l2)->f_opener_pc;
        l8 = vader_chk_add(i32, l3, INT32_C(1));
        vader_array_t* _a2_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l7)
        ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l7] = (int32_t) l8;
        l6 = ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_scopes;
        l4 = vader_chk_sub(i64, l4, INT64_C(1));
        l7 = ((vader_struct_vader_emit_bytecode$ScopeFrame_t*) l2)->f_target_blk;
        vader_struct_vader_emit_bytecode$ScopeFrame_t* _a3_obj = (vader_struct_vader_emit_bytecode$ScopeFrame_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_bytecode$ScopeFrame_t));
        vader_obj_header_init(_a3_obj, 1050u);
        _a3_obj->f_kind = 2129u;
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
    t0 = (void*) &vader_data_64;
    vader_array_t* _a0_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    l2 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT64_C(0));
    l3 = vader_emit_bytecode$push_op_with_span(l0, vader_ref_box(l2), l1);
    l4 = ((vader_array_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_scopes)->length;
    if (l4 == INT64_C(0)) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l2 = ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_scopes;
    l5 = vader_chk_sub(i64, l4, INT64_C(1));
    vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
    l2 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5);
    vader_array_t* _a2_arr = vader_array_new(192u, 0u, 13u, 1050u);
    l6 = (void*) _a2_arr;
    l5 = INT64_C(0);
    l4 = vader_chk_sub(i64, l4, INT64_C(1));
    while ((l5 < l4)) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_scopes);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l5)
        l7 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l5);
        vader_array_push_ref((vader_array_t*) l6, l7);
        l5 = (l5 + INT64_C(1));
    }
    ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_scopes = l6;
    VADER_WRITE_BARRIER((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0);
    t1 = ((vader_struct_vader_emit_bytecode$ScopeFrame_t*) l2)->f_kind;
    if (t1 != 2291u) {
        l6 = ((vader_struct_vader_core_bytecode$BcFunction_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_slot)->f_jump_table;
        l8 = ((vader_struct_vader_emit_bytecode$ScopeFrame_t*) l2)->f_opener_pc;
        vader_array_t* _a4_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l8)
        t2 = ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l8];
        if ((t2 < INT32_C(0))) {
            l6 = ((vader_struct_vader_core_bytecode$BcFunction_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_slot)->f_jump_table;
            l8 = ((vader_struct_vader_emit_bytecode$ScopeFrame_t*) l2)->f_opener_pc;
            l9 = vader_chk_add(i32, l3, INT32_C(1));
            vader_array_t* _a5_slotarr = ((vader_array_t*) l6);
            VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l8)
            ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l8] = (int32_t) l9;
        }
    }
    l8 = ((vader_struct_vader_emit_bytecode$ScopeFrame_t*) l2)->f_target_blk;
    t1 = ((vader_struct_vader_emit_bytecode$ScopeFrame_t*) l2)->f_kind;
    l10 = t1 == 2291u;
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
    t0 = (void*) &vader_data_74;
    vader_array_t* _a0_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    l2 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT64_C(0));
    l3 = vader_emit_bytecode$push_op_with_span(l0, vader_ref_box(l2), l1);
    l2 = ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_scopes;
    vader_struct_vader_emit_bytecode$ScopeFrame_t* _a1_obj = (vader_struct_vader_emit_bytecode$ScopeFrame_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_bytecode$ScopeFrame_t));
    vader_obj_header_init(_a1_obj, 1050u);
    _a1_obj->f_kind = 2129u;
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
    t0 = (void*) &vader_data_63;
    vader_array_t* _a0_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    l3 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT64_C(0));
    l4 = vader_emit_bytecode$push_op_with_span(l0, vader_ref_box(l3), l1);
    l3 = ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_scopes;
    vader_struct_vader_emit_bytecode$ScopeFrame_t* _a1_obj = (vader_struct_vader_emit_bytecode$ScopeFrame_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_bytecode$ScopeFrame_t));
    vader_obj_header_init(_a1_obj, 1050u);
    _a1_obj->f_kind = 2291u;
    _a1_obj->f_target_blk = l2;
    _a1_obj->f_opener_pc = l4;
    l5 = (void*) _a1_obj;
    vader_array_push_ref((vader_array_t*) l3, l5);
    l3 = ((vader_struct_vader_core_bytecode$BcFunction_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_slot)->f_jump_table;
    l6 = vader_chk_add(i32, l4, INT32_C(1));
    vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
    ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l4] = (int32_t) l6;
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
        l10 = ((vader_struct_vader_midir$CFGFunction_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_fn_)->f_blocks;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l11 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
        vader_array_t* _a2_slotarr = ((vader_array_t*) l10);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l11)
        t0 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l11);
        l12 = ((vader_struct_vader_midir$BasicBlock_t*) t0)->f_span;
        vader_emit_bytecode$cf_end(l0, l12);
        vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        l13 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l4];
        vader_emit_bytecode$emit_subtree(l0, l1, l13, l6);
        l4 = (l4 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static bool vader_emit_bytecode$closes_loop(void* l0, int32_t l1, int32_t l2) {
    vader_box_t l3;
    void* t0;
    bool t1;
    l3 = std_collections$MutableMap$std_core$Index$at__i32__Any(l0, l2);
    if (l3.tag == 0u) {
        return false;
    }
    t0 = l3.payload.obj;
    t1 = std_collections$MutableSet$std_core$Contains$contains__i32(t0, l1);
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
    if (l0.tag == 1022u) {
        t0 = l0.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a0_arr = vader_array_new(363u, 0u, 13u, 1904u);
    l1 = (void*) _a0_arr;
    t0 = (void*) &vader_data_18;
    vader_array_t* _a1_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    l2 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) INT64_C(0));
    vader_array_t* _a2_arr = vader_array_new(188u, 0u, 13u, 1038u);
    l3 = (void*) _a2_arr;
    t0 = vader_core_types$mk_fn(l1, vader_ref_box(l2), l3);
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_emit_bytecode$coalesce_slots(void* l0) {
    int64_t l1, l2, l4, l7, l9, l21, l22, l23, l25;
    void* l3 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l12 = NULL;
    void* l15 = NULL;
    void* l17 = NULL;
    void* l18 = NULL;
    void* l19 = NULL;
    void* l24 = NULL;
    void* l26 = NULL;
    void* l27 = NULL;
    void* l30 = NULL;
    int32_t l8, l10, l11, l13, l14, l28, l29;
    bool l16;
    uint8_t l20;
    vader_box_t l31 = vader_box_null(), l32 = vader_box_null(), l33 = vader_box_null();
    vader_string_t l34 = 0;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    bool t2, t3;
    int64_t t4;
    vader_box_t* gc_roots[4] = { &l31, &l32, &l33, &t1 };
    void** gc_raw_roots[14] = {
        &l0, &l3, &l5, &l6, &l12, &l15, &l17, &l18, &l19, &l24, &l26, &l27, &l30, &t0,
    };
    vader_string_t* gc_atom_roots[1] = { &l34 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 14u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_signature)->f_params)->length;
    l2 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_locals)->length;
    l2 = vader_chk_add(i64, l1, l2);
    if ((l2 <= l1)) {
        { void* __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_body;
    l4 = ((vader_array_t*) l3)->length;
    l5 = (void*) &vader_fn_static___lambda_vader_emit_bytecode_0;
    l5 = std_core$filled__vader_emit_bytecode_SlotRange(l2, l5);
    vader_array_t* _a0_arr = vader_array_new(20u, 1u, 12u, 445u);
    ((uint8_t*) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = (uint8_t) false;
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l2);
    l6 = (void*) _a1_arr;
    l7 = INT64_C(0);
    while ((l7 < l4)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l7)
        t1 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l7);
        l8 = vader_core_bytecode$slot_touched(t1);
        if ((l8 >= INT32_C(0))) {
            l9 = ((int64_t) (int32_t) l8);
            vader_array_t* _a3_slotarr = ((vader_array_t*) l6);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l9)
            t2 = ((uint8_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l9];
            t3 = t2;
            if (t3) {
                vader_array_t* _a4_slotarr = ((vader_array_t*) l5);
                VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l9)
                t0 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l9);
                l13 = ((vader_struct_vader_emit_bytecode$SlotRange_t*) t0)->f_first;
                l14 = ((int32_t) (int64_t) l7);
                vader_struct_vader_emit_bytecode$SlotRange_t* _a5_obj = (vader_struct_vader_emit_bytecode$SlotRange_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_bytecode$SlotRange_t));
                vader_obj_header_init(_a5_obj, 1051u);
                _a5_obj->f_first = l13;
                _a5_obj->f_last = l14;
                l15 = (void*) _a5_obj;
                vader_array_t* _a6_slotarr = ((vader_array_t*) l5);
                VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l9)
                vader_array_ref_store(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l9, l15);
                VADER_WRITE_BARRIER(_a6_slotarr->buf);
            } else {
                l10 = ((int32_t) (int64_t) l7);
                l11 = ((int32_t) (int64_t) l7);
                vader_struct_vader_emit_bytecode$SlotRange_t* _a7_obj = (vader_struct_vader_emit_bytecode$SlotRange_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_bytecode$SlotRange_t));
                vader_obj_header_init(_a7_obj, 1051u);
                _a7_obj->f_first = l10;
                _a7_obj->f_last = l11;
                l12 = (void*) _a7_obj;
                vader_array_t* _a8_slotarr = ((vader_array_t*) l5);
                VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l9)
                vader_array_ref_store(_a8_slotarr->buf, _a8_slotarr->offset + (size_t) l9, l12);
                VADER_WRITE_BARRIER(_a8_slotarr->buf);
                vader_array_t* _a9_slotarr = ((vader_array_t*) l6);
                VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l9)
                ((uint8_t*) _a9_slotarr->buf->slots)[_a9_slotarr->offset + (size_t) l9] = (uint8_t) true;
            }
        }
        l7 = (l7 + INT64_C(1));
    }
    l12 = vader_emit_bytecode$find_loop_ranges(l3);
    t4 = ((vader_array_t*) l12)->length;
    if ((t4 > INT64_C(0))) {
        l16 = true;
        while (l16) {
            l16 = vader_emit_bytecode$extend_into_loops(l5, l6, l2, l12);
        }
    }
    l7 = INT64_C(0);
    while ((l7 < l1)) {
        l8 = ((int32_t) (int64_t) l4);
        vader_struct_vader_emit_bytecode$SlotRange_t* _a10_obj = (vader_struct_vader_emit_bytecode$SlotRange_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_bytecode$SlotRange_t));
        vader_obj_header_init(_a10_obj, 1051u);
        _a10_obj->f_first = INT32_C(0);
        _a10_obj->f_last = l8;
        l12 = (void*) _a10_obj;
        vader_array_t* _a11_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l7)
        vader_array_ref_store(_a11_slotarr->buf, _a11_slotarr->offset + (size_t) l7, l12);
        VADER_WRITE_BARRIER(_a11_slotarr->buf);
        vader_array_t* _a12_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a12_slotarr, l7)
        ((uint8_t*) _a12_slotarr->buf->slots)[_a12_slotarr->offset + (size_t) l7] = (uint8_t) true;
        l7 = (l7 + INT64_C(1));
    }
    vader_array_t* _a13_arr = vader_array_new(73u, 0u, 13u, 855u);
    l12 = (void*) _a13_arr;
    vader_array_t* _a14_arr = vader_array_new(23u, 1u, 7u, 450u);
    ((int32_t*) _a14_arr->buf->slots)[_a14_arr->offset + 0u] = (int32_t) INT32_C(-1);
    t0 = (void*) _a14_arr;
    vader_array_t* _a15_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l2);
    l15 = (void*) _a15_arr;
    l7 = INT64_C(0);
    while ((l7 < l1)) {
        l8 = ((int32_t) (int64_t) l7);
        vader_array_t* _a16_slotarr = ((vader_array_t*) l15);
        VADER_ARRAY_RESOLVE_BUF(_a16_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a16_slotarr, l7)
        ((int32_t*) _a16_slotarr->buf->slots)[_a16_slotarr->offset + (size_t) l7] = (int32_t) l8;
        l7 = (l7 + INT64_C(1));
    }
    vader_array_t* _a17_arr = vader_array_new(193u, 0u, 13u, 1051u);
    l17 = (void*) _a17_arr;
    if ((INT64_C(0) < l1)) {
        l7 = l1;
    } else {
        l7 = INT64_C(0);
    }
    vader_array_t* _a18_arr = vader_array_repeat((vader_array_t*) l17, (int64_t) l7);
    l17 = (void*) _a18_arr;
    l7 = INT64_C(0);
    while ((l7 < l1)) {
        vader_array_t* _a19_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a19_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a19_slotarr, l7)
        l18 = vader_array_ref_load_obj(_a19_slotarr->buf, _a19_slotarr->offset + (size_t) l7);
        vader_array_push_ref((vader_array_t*) l17, l18);
        l7 = (l7 + INT64_C(1));
    }
    l7 = l1;
    while ((l7 < l2)) {
        vader_array_t* _a20_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a20_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a20_slotarr, l7)
        t2 = ((uint8_t*) _a20_slotarr->buf->slots)[_a20_slotarr->offset + (size_t) l7];
        t3 = t2;
        if (t3) {
            vader_array_t* _a21_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a21_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a21_slotarr, l7)
            l18 = vader_array_ref_load_obj(_a21_slotarr->buf, _a21_slotarr->offset + (size_t) l7);
            l19 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_locals;
            l9 = vader_chk_sub(i64, l7, l1);
            vader_array_t* _a22_slotarr = ((vader_array_t*) l19);
            VADER_ARRAY_RESOLVE_BUF(_a22_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a22_slotarr, l9)
            t0 = vader_array_ref_load_obj(_a22_slotarr->buf, _a22_slotarr->offset + (size_t) l9);
            l20 = ((vader_struct_vader_core_bytecode$BcLocal_t*) t0)->f_val;
            l8 = INT32_C(-1);
            l21 = l1;
            l22 = ((vader_array_t*) l17)->length;
            while ((l21 < l22)) {
                l23 = vader_chk_sub(i64, l21, l1);
                vader_array_t* _a23_slotarr = ((vader_array_t*) l12);
                VADER_ARRAY_RESOLVE_BUF(_a23_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a23_slotarr, l23)
                t0 = vader_array_ref_load_obj(_a23_slotarr->buf, _a23_slotarr->offset + (size_t) l23);
                if (((vader_struct_vader_core_bytecode$BcLocal_t*) t0)->f_val == l20) {
                    vader_array_t* _a24_slotarr = ((vader_array_t*) l17);
                    VADER_ARRAY_RESOLVE_BUF(_a24_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a24_slotarr, l21)
                    t0 = vader_array_ref_load_obj(_a24_slotarr->buf, _a24_slotarr->offset + (size_t) l21);
                    t2 = vader_emit_bytecode$ranges_overlap(t0, l18);
                    if (!(t2)) {
                        l8 = ((int32_t) (int64_t) l21);
                        break;
                    }
                }
                l21 = (l21 + INT64_C(1));
            }
            if ((l8 < INT32_C(0))) {
                t4 = ((vader_array_t*) l17)->length;
                l8 = ((int32_t) (int64_t) t4);
                vader_array_push_ref((vader_array_t*) l17, l18);
                l24 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_locals;
                l25 = vader_chk_sub(i64, l7, l1);
                vader_array_t* _a25_slotarr = ((vader_array_t*) l24);
                VADER_ARRAY_RESOLVE_BUF(_a25_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a25_slotarr, l25)
                l26 = vader_array_ref_load_obj(_a25_slotarr->buf, _a25_slotarr->offset + (size_t) l25);
                vader_array_push_ref((vader_array_t*) l12, l26);
            } else {
                vader_array_t* _a26_slotarr = ((vader_array_t*) l17);
                VADER_ARRAY_RESOLVE_BUF(_a26_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a26_slotarr, l8)
                l27 = vader_array_ref_load_obj(_a26_slotarr->buf, _a26_slotarr->offset + (size_t) l8);
                l11 = ((vader_struct_vader_emit_bytecode$SlotRange_t*) l18)->f_first;
                l13 = ((vader_struct_vader_emit_bytecode$SlotRange_t*) l27)->f_first;
                if ((l11 < l13)) {
                    l10 = ((vader_struct_vader_emit_bytecode$SlotRange_t*) l18)->f_first;
                } else {
                    l10 = ((vader_struct_vader_emit_bytecode$SlotRange_t*) l27)->f_first;
                }
                l28 = ((vader_struct_vader_emit_bytecode$SlotRange_t*) l18)->f_last;
                l29 = ((vader_struct_vader_emit_bytecode$SlotRange_t*) l27)->f_last;
                if ((l28 > l29)) {
                    l14 = ((vader_struct_vader_emit_bytecode$SlotRange_t*) l18)->f_last;
                } else {
                    l14 = ((vader_struct_vader_emit_bytecode$SlotRange_t*) l27)->f_last;
                }
                vader_struct_vader_emit_bytecode$SlotRange_t* _a27_obj = (vader_struct_vader_emit_bytecode$SlotRange_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_bytecode$SlotRange_t));
                vader_obj_header_init(_a27_obj, 1051u);
                _a27_obj->f_first = l10;
                _a27_obj->f_last = l14;
                l30 = (void*) _a27_obj;
                vader_array_t* _a28_slotarr = ((vader_array_t*) l17);
                VADER_ARRAY_RESOLVE_BUF(_a28_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a28_slotarr, l8)
                vader_array_ref_store(_a28_slotarr->buf, _a28_slotarr->offset + (size_t) l8, l30);
                VADER_WRITE_BARRIER(_a28_slotarr->buf);
            }
            vader_array_t* _a29_slotarr = ((vader_array_t*) l15);
            VADER_ARRAY_RESOLVE_BUF(_a29_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a29_slotarr, l7)
            ((int32_t*) _a29_slotarr->buf->slots)[_a29_slotarr->offset + (size_t) l7] = (int32_t) l8;
            l7 = vader_chk_add(i64, l7, INT64_C(1));
            continue;
        }
        vader_array_t* _a30_slotarr = ((vader_array_t*) l15);
        VADER_ARRAY_RESOLVE_BUF(_a30_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a30_slotarr, l7)
        ((int32_t*) _a30_slotarr->buf->slots)[_a30_slotarr->offset + (size_t) l7] = (int32_t) INT32_C(-1);
        l7 = vader_chk_add(i64, l7, INT64_C(1));
    }
    l16 = true;
    while ((l1 < l2)) {
        vader_array_t* _a31_slotarr = ((vader_array_t*) l15);
        VADER_ARRAY_RESOLVE_BUF(_a31_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a31_slotarr, l1)
        l8 = ((int32_t*) _a31_slotarr->buf->slots)[_a31_slotarr->offset + (size_t) l1];
        l10 = ((int32_t) (int64_t) l1);
        if (l8 != l10) {
            l16 = false;
            break;
        }
        l1 = (l1 + INT64_C(1));
    }
    if (l16) {
        { void* __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a32_arr = vader_array_new(358u, 0u, 13u, 1803u);
    l5 = (void*) _a32_arr;
    l1 = INT64_C(0);
    while ((l1 < l4)) {
        vader_array_t* _a33_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a33_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a33_slotarr, l1)
        l31 = vader_array_ref_load_box(_a33_slotarr->buf, _a33_slotarr->offset + (size_t) l1);
        l8 = vader_core_bytecode$slot_touched(l31);
        if ((l8 >= INT32_C(0))) {
            vader_array_t* _a34_slotarr = ((vader_array_t*) l15);
            VADER_ARRAY_RESOLVE_BUF(_a34_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a34_slotarr, l8)
            l10 = ((int32_t*) _a34_slotarr->buf->slots)[_a34_slotarr->offset + (size_t) l8];
            if ((l10 >= INT32_C(0))) {
                l32 = vader_core_bytecode$with_remapped_slot(l31, l10);
                vader_array_push_ref((vader_array_t*) l5, l32.payload.obj);
            } else {
                vader_array_push_ref((vader_array_t*) l5, l31.payload.obj);
            }
        } else {
            l33 = vader_emit_bytecode$remap_push_cache_slot(l31, l15);
            vader_array_push_ref((vader_array_t*) l5, l33.payload.obj);
        }
        l1 = (l1 + INT64_C(1));
    }
    l3 = l0;
    l34 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l3)->f_name;
    l16 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l3)->f_is_main;
    l6 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l3)->f_signature;
    l15 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l3)->f_debug;
    l17 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l3)->f_jump_table;
    l3 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l3)->f_source_pc;
    vader_struct_vader_core_bytecode$BcFunction_t* _a35_obj = (vader_struct_vader_core_bytecode$BcFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcFunction_t));
    vader_obj_header_init(_a35_obj, 852u);
    _a35_obj->f_name = l34;
    _a35_obj->f_is_main = l16;
    _a35_obj->f_signature = l6;
    _a35_obj->f_locals = l12;
    _a35_obj->f_body = l5;
    _a35_obj->f_debug = l15;
    _a35_obj->f_jump_table = l17;
    _a35_obj->f_source_pc = l3;
    t0 = (void*) _a35_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
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
    if (l0.tag == 866u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_core_bytecode$BcValStruct_t*) t0)->f_symbol_id;
        std_collections$add__i32(l2, l3);
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_core_bytecode$BcValStruct_t*) t0)->f_fields;
        l5 = ((vader_array_t*) l4)->length;
        l6 = INT64_C(0);
        while ((l6 < l5)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            t1 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l6);
            vader_emit_bytecode$collect_baked_types(t1, l1, l2);
            l6 = (l6 + INT64_C(1));
        }
    } else if (l0.tag == 863u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_core_bytecode$BcValArray_t*) t0)->f_type_id;
        vader_array_push_i32((vader_array_t*) l1, l3);
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_core_bytecode$BcValArray_t*) t0)->f_elements;
        l5 = ((vader_array_t*) l4)->length;
        l6 = INT64_C(0);
        while ((l6 < l5)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l4);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            t1 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l6);
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
    if (l0.tag == 940u) {
        t0 = vader_core_bytecode$is_64_bit_int_val(l1);
        return t0;
    }
    if (!(l0.tag == 920u)) {
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
    if (l0.tag == 920u) {
        l1 = (uint8_t) 2;
        return l1;
    }
    if (l0.tag == 940u) {
        l1 = (uint8_t) 3;
    } else if (l0.tag == 899u) {
        l1 = (uint8_t) 9;
    } else if (l0.tag == 871u) {
        l1 = (uint8_t) 10;
    } else if (l0.tag == 886u) {
        l1 = (uint8_t) 11;
    } else if (l0.tag == 987u) {
        l1 = (uint8_t) 12;
    } else {
        if (!(l0.tag == 971u)) {
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
    vader_array_t* _a0_arr = vader_array_new(359u, 0u, 13u, 1826u);
    l2 = (void*) _a0_arr;
    l3 = l1;
    l4 = ((vader_array_t*) l3)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l6 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5);
        if (l6.tag == 1423u) {
            t0 = l6.payload.obj;
            l7 = ((vader_struct_vader_lower_ir$StrDataPoolEntry_t*) t0)->f_values;
            l8 = ((vader_array_t*) l7)->length;
            l9 = INT64_C(0);
            while ((l9 < l8)) {
                vader_array_t* _a2_slotarr = ((vader_array_t*) l7);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                t1 = vader_array_box_slots(_a2_slotarr->buf)[_a2_slotarr->offset + (size_t) l9];
                t2 = t1.payload.s;
                vader_emit_bytecode$intern_string(t2, l0);
                l9 = (l9 + INT64_C(1));
            }
            t0 = l6.payload.obj;
            vader_struct_vader_core_bytecode$BcStrData_t* _a3_obj = (vader_struct_vader_core_bytecode$BcStrData_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcStrData_t));
            vader_obj_header_init(_a3_obj, 860u);
            _a3_obj->f_values = ((vader_struct_vader_lower_ir$StrDataPoolEntry_t*) t0)->f_values;
            l10 = (void*) _a3_obj;
            vader_array_push_ref((vader_array_t*) l2, l10);
        } else if (l6.tag == 1422u) {
            vader_array_t* _a4_arr = vader_array_new(28u, 0u, 4u, 455u);
            l11 = (void*) _a4_arr;
            t0 = l6.payload.obj;
            l12 = ((vader_struct_vader_lower_ir$PrimDataPoolEntry_t*) t0)->f_items;
            l13 = ((vader_array_t*) l12)->length;
            l14 = INT64_C(0);
            vader_array_t* _pc68_hdr = (vader_array_t*) l11;
            size_t _pc68_len = _pc68_hdr->length;
            size_t _pc68_cap = (_pc68_hdr->offset == 0 && !vader_array_is_borrowed(_pc68_hdr) && _pc68_hdr->length >= _pc68_hdr->buf->length) ? _pc68_hdr->capacity : (size_t) 0;
            void* _pc68_slots = _pc68_hdr->buf->slots;
            for (;;) {
                if ((l14 < l13)) {
                    vader_array_t* _a5_slotarr = ((vader_array_t*) l12);
                    VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
                    t3 = ((int64_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l14];
                    t4 = t3;
                    l15 = (uint64_t) (int64_t) t4;
                    if (VADER_LIKELY(_pc68_len < _pc68_cap)) {
                        ((int64_t*) _pc68_slots)[_pc68_len] = (int64_t) ((int64_t) (uint64_t) l15);
                        _pc68_len += 1;
                    } else {
                        _pc68_hdr->length = _pc68_len;
                        if (_pc68_hdr->buf->length < _pc68_len) {
                            _pc68_hdr->buf->length = _pc68_len;
                        }
                        vader_array_push_i64((vader_array_t*) l11, (int64_t) (uint64_t) l15);
                        _pc68_hdr = (vader_array_t*) l11;
                        _pc68_len = _pc68_hdr->length;
                        _pc68_cap = (_pc68_hdr->offset == 0 && !vader_array_is_borrowed(_pc68_hdr) && _pc68_hdr->length >= _pc68_hdr->buf->length) ? _pc68_hdr->capacity : (size_t) 0;
                        _pc68_slots = _pc68_hdr->buf->slots;
                    }
                    l14 = (l14 + INT64_C(1));
                    continue;
                }
                _pc68_hdr->length = _pc68_len;
                if (_pc68_hdr->buf->length < _pc68_len) {
                    _pc68_hdr->buf->length = _pc68_len;
                }
                break;
            }
            t0 = l6.payload.obj;
            t2 = ((vader_struct_vader_lower_ir$PrimDataPoolEntry_t*) t0)->f_element_type_name;
            t5 = vader_core_bytecode$array_kind_from_name(t2);
            vader_struct_vader_core_bytecode$BcPrimData_t* _a6_obj = (vader_struct_vader_core_bytecode$BcPrimData_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcPrimData_t));
            vader_obj_header_init(_a6_obj, 856u);
            _a6_obj->f_kind = t5;
            _a6_obj->f_items = l11;
            l16 = (void*) _a6_obj;
            vader_array_push_ref((vader_array_t*) l2, l16);
        } else {
            if (!(l6.tag == 1360u)) {
                vader_unreachable("non-exhaustive match (T3013 should have caught this)");
            }
            vader_array_t* _a7_arr = vader_array_new(361u, 0u, 13u, 1837u);
            l17 = (void*) _a7_arr;
            t0 = l6.payload.obj;
            l18 = ((vader_struct_vader_lower_ir$LoweredArrayLit_t*) ((vader_struct_vader_lower_ir$AggregateDataPoolEntry_t*) t0)->f_literal)->f_elements;
            l19 = ((vader_array_t*) l18)->length;
            l20 = INT64_C(0);
            while ((l20 < l19)) {
                vader_array_t* _a8_slotarr = ((vader_array_t*) l18);
                VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
                l21 = vader_array_ref_load_box(_a8_slotarr->buf, _a8_slotarr->offset + (size_t) l20);
                l22 = vader_emit_bytecode$baked_value(l0, l21);
                vader_array_push_ref((vader_array_t*) l17, l22.payload.obj);
                l20 = (l20 + INT64_C(1));
            }
            vader_struct_vader_core_bytecode$BcAggregateData_t* _a9_obj = (vader_struct_vader_core_bytecode$BcAggregateData_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcAggregateData_t));
            vader_obj_header_init(_a9_obj, 847u);
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
        t1 = ((vader_array_t*) ((vader_struct_vader_midir$BasicBlock_t*) l0)->f_instructions)->length;
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
    vader_array_t* _a0_arr = vader_array_new(23u, 0u, 7u, 450u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(23u, 0u, 7u, 450u);
    l3 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(20u, 0u, 12u, 445u);
    l4 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(23u, 0u, 7u, 450u);
    l5 = (void*) _a3_arr;
    vader_struct_std_collections$MutableMap__i32__bool_t* _a4_obj = (vader_struct_std_collections$MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i32__bool_t));
    vader_obj_header_init(_a4_obj, 585u);
    _a4_obj->f_ekeys = l3;
    _a4_obj->f_evals = l4;
    _a4_obj->f_index = l5;
    _a4_obj->f_mask = INT64_C(0);
    _a4_obj->f_grow_at = INT64_C(0);
    _a4_obj->f_size = INT64_C(0);
    _a4_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a4_obj;
    vader_struct_std_collections$MutableSet__i32_t* _a5_obj = (vader_struct_std_collections$MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableSet__i32_t));
    vader_obj_header_init(_a5_obj, 728u);
    _a5_obj->f_inner = t0;
    l3 = (void*) _a5_obj;
    l4 = l1;
    l6 = ((vader_array_t*) l4)->length;
    l7 = INT64_C(0);
    while ((l7 < l6)) {
        vader_array_t* _a6_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        l8 = vader_array_ref_load_box(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l7);
        if (l8.tag == 847u) {
            t0 = l8.payload.obj;
            l5 = ((vader_struct_vader_core_bytecode$BcAggregateData_t*) t0)->f_elements;
            l9 = ((vader_array_t*) l5)->length;
            l10 = INT64_C(0);
            while ((l10 < l9)) {
                vader_array_t* _a7_slotarr = ((vader_array_t*) l5);
                VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
                t1 = vader_array_ref_load_box(_a7_slotarr->buf, _a7_slotarr->offset + (size_t) l10);
                vader_emit_bytecode$collect_baked_types(t1, l2, l3);
                l10 = (l10 + INT64_C(1));
            }
        }
        l7 = (l7 + INT64_C(1));
    }
    l4 = ((vader_struct_std_collections$MutableMap__i32__bool_t*) ((vader_struct_std_collections$MutableSet__i32_t*) l3)->f_inner)->f_ekeys;
    l6 = INT64_C(0);
    l7 = ((vader_struct_std_collections$MutableMap__i32__bool_t*) ((vader_struct_std_collections$MutableSet__i32_t*) l3)->f_inner)->f_size;
    while ((l6 < l7)) {
        vader_array_t* _a8_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l6)
        l11 = ((int32_t*) _a8_slotarr->buf->slots)[_a8_slotarr->offset + (size_t) l6];
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
    vader_obj_header_init(_a0_obj, 891u);
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
    vader_array_t* _a0_arr = vader_array_new(22u, 0u, 0u, 447u);
    l0 = (void*) _a0_arr;
    vader_struct_vader_emit_bytecode$EmitOptions_t* _a1_obj = (vader_struct_vader_emit_bytecode$EmitOptions_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_bytecode$EmitOptions_t));
    vader_obj_header_init(_a1_obj, 1045u);
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
    l4 = ((vader_array_t*) l3)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l6 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
        t0 = ((vader_struct_vader_emit_bytecode$ScopeFrame_t*) l6)->f_kind;
        if (t0 == 2291u) {
            t1 = vader_midir$BlockId$std_core$Equals$equals(((vader_struct_vader_emit_bytecode$ScopeFrame_t*) l6)->f_target_blk, l1);
            if (t1) {
                l7 = ((vader_struct_vader_core_bytecode$BcFunction_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_slot)->f_jump_table;
                t2 = ((vader_struct_vader_emit_bytecode$ScopeFrame_t*) l6)->f_opener_pc;
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
    l3 = ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_pending;
    vader_struct_vader_emit_bytecode$PendingBranch_t* _a2_obj = (vader_struct_vader_emit_bytecode$PendingBranch_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_bytecode$PendingBranch_t));
    vader_obj_header_init(_a2_obj, 1048u);
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
    vader_array_t* _a0_arr = vader_array_new(191u, 0u, 13u, 1048u);
    l6 = (void*) _a0_arr;
    l7 = ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_pending;
    l8 = ((vader_array_t*) l7)->length;
    l9 = INT64_C(0);
    while ((l9 < l8)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l10 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l9);
        t0 = vader_midir$BlockId$std_core$Equals$equals(((vader_struct_vader_emit_bytecode$PendingBranch_t*) l10)->f_target_blk, l1);
        if (t0) {
            l11 = ((vader_struct_vader_core_bytecode$BcFunction_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_slot)->f_jump_table;
            l12 = ((vader_struct_vader_emit_bytecode$PendingBranch_t*) l10)->f_branch_pc;
            vader_array_t* _a2_slotarr = ((vader_array_t*) l11);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l12)
            ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l12] = (int32_t) l5;
        } else {
            vader_array_push_ref((vader_array_t*) l6, l10);
        }
        l9 = (l9 + INT64_C(1));
    }
    ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_pending = l6;
    VADER_WRITE_BARRIER((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0);
    { vader_gc_top = gc_frame.prev; return; }
}

static void* vader_emit_bytecode$drop_dead_stores(void* l0) {
    int64_t l1, l2, l5, l6;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    void* l15 = NULL;
    void* l16 = NULL;
    void* l20 = NULL;
    void* l23 = NULL;
    void* l29 = NULL;
    vader_box_t l7 = vader_box_null(), l31 = vader_box_null();
    int32_t l8, l9, l10, l11, l17, l18, l19, l21, l22, l24, l25, l26, l27, l28, l30;
    bool l12;
    vader_string_t l32 = 0;
    void* t0 = NULL;
    int32_t t1;
    bool t2, t3;
    int64_t t4;
    vader_box_t* gc_roots[2] = { &l7, &l31 };
    void** gc_raw_roots[11] = { &l0, &l3, &l4, &l13, &l14, &l15, &l16, &l20, &l23, &l29, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l32 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 11u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_signature)->f_params)->length;
    l2 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_locals)->length;
    l2 = vader_chk_add(i64, l1, l2);
    vader_array_t* _a0_arr = vader_array_new(23u, 1u, 7u, 450u);
    ((int32_t*) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = (int32_t) INT32_C(0);
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l2);
    l3 = (void*) _a1_arr;
    l4 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_body;
    l5 = ((vader_array_t*) l4)->length;
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        l7 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l6);
        if (l7.tag == 965u) {
            t0 = l7.payload.obj;
            l8 = ((vader_struct_vader_core_bytecode$LocalGet_t*) t0)->f_slot;
            vader_array_t* _a3_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l8)
            t1 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l8];
            l9 = vader_chk_add(i32, t1, INT32_C(1));
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l8)
            ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l8] = (int32_t) l9;
        }
        if (l7.tag == 964u) {
            t0 = l7.payload.obj;
            l10 = ((vader_struct_vader_core_bytecode$LocalField_t*) t0)->f_slot;
            vader_array_t* _a4_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l10)
            t1 = ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l10];
            l11 = vader_chk_add(i32, t1, INT32_C(1));
            VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l10)
            ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l10] = (int32_t) l11;
        }
        l6 = (l6 + INT64_C(1));
    }
    vader_array_t* _a5_arr = vader_array_new(20u, 1u, 12u, 445u);
    ((uint8_t*) _a5_arr->buf->slots)[_a5_arr->offset + 0u] = (uint8_t) false;
    t0 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l2);
    l4 = (void*) _a6_arr;
    l12 = false;
    l5 = l1;
    while ((l5 < l2)) {
        vader_array_t* _a7_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l5)
        t1 = ((int32_t*) _a7_slotarr->buf->slots)[_a7_slotarr->offset + (size_t) l5];
        if (t1 == INT32_C(0)) {
            vader_array_t* _a8_slotarr = ((vader_array_t*) l4);
            VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l5)
            ((uint8_t*) _a8_slotarr->buf->slots)[_a8_slotarr->offset + (size_t) l5] = (uint8_t) true;
            l12 = true;
        }
        l5 = (l5 + INT64_C(1));
    }
    if (!(l12)) {
        { void* __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a9_arr = vader_array_new(23u, 1u, 7u, 450u);
    ((int32_t*) _a9_arr->buf->slots)[_a9_arr->offset + 0u] = (int32_t) INT32_C(-1);
    t0 = (void*) _a9_arr;
    vader_array_t* _a10_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l2);
    l3 = (void*) _a10_arr;
    l8 = INT32_C(0);
    l5 = INT64_C(0);
    while ((l5 < l2)) {
        vader_array_t* _a11_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l5)
        t2 = ((uint8_t*) _a11_slotarr->buf->slots)[_a11_slotarr->offset + (size_t) l5];
        t3 = t2;
        if (!(t3)) {
            vader_array_t* _a12_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a12_slotarr, l5)
            ((int32_t*) _a12_slotarr->buf->slots)[_a12_slotarr->offset + (size_t) l5] = (int32_t) l8;
            l8 = vader_chk_add(i32, l8, INT32_C(1));
        }
        l5 = (l5 + INT64_C(1));
    }
    vader_array_t* _a13_arr = vader_array_new(358u, 0u, 13u, 1803u);
    l13 = (void*) _a13_arr;
    l5 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_body)->length;
    vader_array_t* _a14_arr = vader_array_new(23u, 1u, 7u, 450u);
    ((int32_t*) _a14_arr->buf->slots)[_a14_arr->offset + 0u] = (int32_t) INT32_C(-1);
    t0 = (void*) _a14_arr;
    vader_array_t* _a15_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l5);
    l14 = (void*) _a15_arr;
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a16_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_body);
        VADER_ARRAY_RESOLVE_BUF(_a16_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a16_slotarr, l6)
        l7 = vader_array_ref_load_box(_a16_slotarr->buf, _a16_slotarr->offset + (size_t) l6);
        if (l7.tag == 966u) {
            t0 = l7.payload.obj;
            l8 = ((vader_struct_vader_core_bytecode$LocalSet_t*) t0)->f_slot;
            vader_array_t* _a17_slotarr = ((vader_array_t*) l4);
            VADER_ARRAY_RESOLVE_BUF(_a17_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a17_slotarr, l8)
            t2 = ((uint8_t*) _a17_slotarr->buf->slots)[_a17_slotarr->offset + (size_t) l8];
            t3 = t2;
            if (t3) {
                t4 = ((vader_array_t*) l13)->length;
                l9 = ((int32_t) (int64_t) t4);
                vader_array_t* _a18_slotarr = ((vader_array_t*) l14);
                VADER_ARRAY_RESOLVE_BUF(_a18_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a18_slotarr, l6)
                ((int32_t*) _a18_slotarr->buf->slots)[_a18_slotarr->offset + (size_t) l6] = (int32_t) l9;
                t0 = (void*) &vader_data_61;
                vader_array_t* _a19_slotarr = ((vader_array_t*) t0);
                VADER_ARRAY_RESOLVE_BUF(_a19_slotarr)
                l15 = vader_array_ref_load_obj(_a19_slotarr->buf, _a19_slotarr->offset + (size_t) INT64_C(0));
                vader_array_push_ref((vader_array_t*) l13, l15);
            } else {
                t4 = ((vader_array_t*) l13)->length;
                l10 = ((int32_t) (int64_t) t4);
                vader_array_t* _a20_slotarr = ((vader_array_t*) l14);
                VADER_ARRAY_RESOLVE_BUF(_a20_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a20_slotarr, l6)
                ((int32_t*) _a20_slotarr->buf->slots)[_a20_slotarr->offset + (size_t) l6] = (int32_t) l10;
                t0 = l7.payload.obj;
                l11 = ((vader_struct_vader_core_bytecode$LocalSet_t*) t0)->f_slot;
                vader_array_t* _a21_slotarr = ((vader_array_t*) l3);
                VADER_ARRAY_RESOLVE_BUF(_a21_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a21_slotarr, l11)
                t1 = ((int32_t*) _a21_slotarr->buf->slots)[_a21_slotarr->offset + (size_t) l11];
                vader_struct_vader_core_bytecode$LocalSet_t* _a22_obj = (vader_struct_vader_core_bytecode$LocalSet_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$LocalSet_t));
                vader_obj_header_init(_a22_obj, 966u);
                _a22_obj->f_slot = t1;
                l16 = (void*) _a22_obj;
                vader_array_push_ref((vader_array_t*) l13, l16);
            }
            l6 = vader_chk_add(i64, l6, INT64_C(1));
            continue;
        }
        if (l7.tag == 967u) {
            t0 = l7.payload.obj;
            l17 = ((vader_struct_vader_core_bytecode$LocalTee_t*) t0)->f_slot;
            vader_array_t* _a23_slotarr = ((vader_array_t*) l4);
            VADER_ARRAY_RESOLVE_BUF(_a23_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a23_slotarr, l17)
            t2 = ((uint8_t*) _a23_slotarr->buf->slots)[_a23_slotarr->offset + (size_t) l17];
            t3 = t2;
            if (t3) {
                l6 = vader_chk_add(i64, l6, INT64_C(1));
                continue;
            }
            t4 = ((vader_array_t*) l13)->length;
            l18 = ((int32_t) (int64_t) t4);
            vader_array_t* _a24_slotarr = ((vader_array_t*) l14);
            VADER_ARRAY_RESOLVE_BUF(_a24_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a24_slotarr, l6)
            ((int32_t*) _a24_slotarr->buf->slots)[_a24_slotarr->offset + (size_t) l6] = (int32_t) l18;
            t0 = l7.payload.obj;
            l19 = ((vader_struct_vader_core_bytecode$LocalTee_t*) t0)->f_slot;
            vader_array_t* _a25_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a25_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a25_slotarr, l19)
            t1 = ((int32_t*) _a25_slotarr->buf->slots)[_a25_slotarr->offset + (size_t) l19];
            vader_struct_vader_core_bytecode$LocalTee_t* _a26_obj = (vader_struct_vader_core_bytecode$LocalTee_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$LocalTee_t));
            vader_obj_header_init(_a26_obj, 967u);
            _a26_obj->f_slot = t1;
            l20 = (void*) _a26_obj;
            vader_array_push_ref((vader_array_t*) l13, l20);
            l6 = vader_chk_add(i64, l6, INT64_C(1));
            continue;
        }
        if (l7.tag == 965u) {
            t4 = ((vader_array_t*) l13)->length;
            l21 = ((int32_t) (int64_t) t4);
            vader_array_t* _a27_slotarr = ((vader_array_t*) l14);
            VADER_ARRAY_RESOLVE_BUF(_a27_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a27_slotarr, l6)
            ((int32_t*) _a27_slotarr->buf->slots)[_a27_slotarr->offset + (size_t) l6] = (int32_t) l21;
            t0 = l7.payload.obj;
            l22 = ((vader_struct_vader_core_bytecode$LocalGet_t*) t0)->f_slot;
            vader_array_t* _a28_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a28_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a28_slotarr, l22)
            t1 = ((int32_t*) _a28_slotarr->buf->slots)[_a28_slotarr->offset + (size_t) l22];
            vader_struct_vader_core_bytecode$LocalGet_t* _a29_obj = (vader_struct_vader_core_bytecode$LocalGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$LocalGet_t));
            vader_obj_header_init(_a29_obj, 965u);
            _a29_obj->f_slot = t1;
            l23 = (void*) _a29_obj;
            vader_array_push_ref((vader_array_t*) l13, l23);
            l6 = vader_chk_add(i64, l6, INT64_C(1));
            continue;
        }
        if (l7.tag == 964u) {
            t4 = ((vader_array_t*) l13)->length;
            l24 = ((int32_t) (int64_t) t4);
            vader_array_t* _a30_slotarr = ((vader_array_t*) l14);
            VADER_ARRAY_RESOLVE_BUF(_a30_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a30_slotarr, l6)
            ((int32_t*) _a30_slotarr->buf->slots)[_a30_slotarr->offset + (size_t) l6] = (int32_t) l24;
            t0 = l7.payload.obj;
            l25 = ((vader_struct_vader_core_bytecode$LocalField_t*) t0)->f_slot;
            vader_array_t* _a31_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a31_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a31_slotarr, l25)
            l26 = ((int32_t*) _a31_slotarr->buf->slots)[_a31_slotarr->offset + (size_t) l25];
            t0 = l7.payload.obj;
            l27 = ((vader_struct_vader_core_bytecode$LocalField_t*) t0)->f_type_id;
            t0 = l7.payload.obj;
            l28 = ((vader_struct_vader_core_bytecode$LocalField_t*) t0)->f_field_index;
            vader_struct_vader_core_bytecode$LocalField_t* _a32_obj = (vader_struct_vader_core_bytecode$LocalField_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$LocalField_t));
            vader_obj_header_init(_a32_obj, 964u);
            _a32_obj->f_slot = l26;
            _a32_obj->f_type_id = l27;
            _a32_obj->f_field_index = l28;
            l29 = (void*) _a32_obj;
            vader_array_push_ref((vader_array_t*) l13, l29);
            l6 = vader_chk_add(i64, l6, INT64_C(1));
            continue;
        }
        t4 = ((vader_array_t*) l13)->length;
        l30 = ((int32_t) (int64_t) t4);
        vader_array_t* _a33_slotarr = ((vader_array_t*) l14);
        VADER_ARRAY_RESOLVE_BUF(_a33_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a33_slotarr, l6)
        ((int32_t*) _a33_slotarr->buf->slots)[_a33_slotarr->offset + (size_t) l6] = (int32_t) l30;
        l31 = vader_emit_bytecode$remap_push_cache_slot(l7, l3);
        vader_array_push_ref((vader_array_t*) l13, l31.payload.obj);
        l6 = vader_chk_add(i64, l6, INT64_C(1));
    }
    l3 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_jump_table;
    l5 = ((vader_array_t*) l13)->length;
    l3 = vader_core_bytecode$remap_jump_table(l3, l14, l5);
    l15 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_debug;
    l5 = ((vader_array_t*) l13)->length;
    l14 = vader_emit_bytecode$remap_debug(l15, l14, l5);
    vader_array_t* _a34_arr = vader_array_new(73u, 0u, 13u, 855u);
    l15 = (void*) _a34_arr;
    l5 = l1;
    while ((l5 < l2)) {
        vader_array_t* _a35_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a35_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a35_slotarr, l5)
        t2 = ((uint8_t*) _a35_slotarr->buf->slots)[_a35_slotarr->offset + (size_t) l5];
        t3 = t2;
        if (!(t3)) {
            l16 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_locals;
            l6 = vader_chk_sub(i64, l5, l1);
            vader_array_t* _a36_slotarr = ((vader_array_t*) l16);
            VADER_ARRAY_RESOLVE_BUF(_a36_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a36_slotarr, l6)
            l20 = vader_array_ref_load_obj(_a36_slotarr->buf, _a36_slotarr->offset + (size_t) l6);
            vader_array_push_ref((vader_array_t*) l15, l20);
        }
        l5 = (l5 + INT64_C(1));
    }
    l4 = l0;
    l32 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l4)->f_name;
    l12 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l4)->f_is_main;
    l16 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l4)->f_signature;
    l4 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l4)->f_source_pc;
    vader_struct_vader_core_bytecode$BcFunction_t* _a37_obj = (vader_struct_vader_core_bytecode$BcFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcFunction_t));
    vader_obj_header_init(_a37_obj, 852u);
    _a37_obj->f_name = l32;
    _a37_obj->f_is_main = l12;
    _a37_obj->f_signature = l16;
    _a37_obj->f_locals = l15;
    _a37_obj->f_body = l13;
    _a37_obj->f_debug = l14;
    _a37_obj->f_jump_table = l3;
    _a37_obj->f_source_pc = l4;
    t0 = (void*) _a37_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_emit_bytecode$drop_unbranched_blocks(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l4 = NULL;
    void* l7 = NULL;
    void* l10 = NULL;
    int64_t l3, l5, l9;
    int32_t l6;
    bool l8;
    vader_box_t l11 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    bool t2, t3;
    int64_t t4;
    vader_box_t* gc_roots[2] = { &l11, &t0 };
    void** gc_raw_roots[7] = { &l0, &l1, &l2, &l4, &l7, &l10, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 7u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_body;
    l2 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_jump_table;
    l3 = ((vader_array_t*) l1)->length;
    vader_array_t* _a0_arr = vader_array_new(20u, 1u, 12u, 445u);
    ((uint8_t*) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = (uint8_t) false;
    l4 = (void*) _a0_arr;
    l5 = vader_chk_add(i64, l3, INT64_C(1));
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l4, (int64_t) l5);
    l4 = (void*) _a1_arr;
    l5 = INT64_C(0);
    while ((l5 < l3)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l5)
        l6 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l5];
        vader_array_t* _a3_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        t0 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l5);
        if ((t0.tag == 876u || t0.tag == 877u)) {
            if ((l6 >= INT32_C(0))) {
                if ((((int64_t) (int32_t) l6) <= l3)) {
                    vader_array_t* _a4_slotarr = ((vader_array_t*) l4);
                    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l6)
                    ((uint8_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l6] = (uint8_t) true;
                }
            }
        }
        l5 = (l5 + INT64_C(1));
    }
    vader_array_t* _a5_arr = vader_array_new(20u, 1u, 12u, 445u);
    ((uint8_t*) _a5_arr->buf->slots)[_a5_arr->offset + 0u] = (uint8_t) false;
    t1 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_repeat((vader_array_t*) t1, (int64_t) l3);
    l7 = (void*) _a6_arr;
    l8 = false;
    l5 = INT64_C(0);
    while ((l5 < l3)) {
        vader_array_t* _a7_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l5)
        l6 = ((int32_t*) _a7_slotarr->buf->slots)[_a7_slotarr->offset + (size_t) l5];
        vader_array_t* _a8_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
        t0 = vader_array_ref_load_box(_a8_slotarr->buf, _a8_slotarr->offset + (size_t) l5);
        if (t0.tag == 869u) {
            if ((l6 > INT32_C(0))) {
                vader_array_t* _a9_slotarr = ((vader_array_t*) l4);
                VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l6)
                t2 = ((uint8_t*) _a9_slotarr->buf->slots)[_a9_slotarr->offset + (size_t) l6];
                t3 = t2;
                if (!(t3)) {
                    vader_array_t* _a10_slotarr = ((vader_array_t*) l7);
                    VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a10_slotarr, l5)
                    ((uint8_t*) _a10_slotarr->buf->slots)[_a10_slotarr->offset + (size_t) l5] = (uint8_t) true;
                    l9 = vader_chk_sub(i64, ((int64_t) (int32_t) l6), INT64_C(1));
                    VADER_ARRAY_CHECK_INDEX(_a10_slotarr, l9)
                    ((uint8_t*) _a10_slotarr->buf->slots)[_a10_slotarr->offset + (size_t) l9] = (uint8_t) true;
                    l8 = true;
                }
            }
        }
        l5 = (l5 + INT64_C(1));
    }
    if (!(l8)) {
        t1 = vader_emit_bytecode$bc_peephole_unchanged(l0);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a11_arr = vader_array_new(358u, 0u, 13u, 1803u);
    l4 = (void*) _a11_arr;
    vader_array_t* _a12_arr = vader_array_new(23u, 0u, 7u, 450u);
    l10 = (void*) _a12_arr;
    l5 = INT64_C(0);
    while ((l5 < l3)) {
        vader_array_t* _a13_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a13_slotarr, l5)
        t2 = ((uint8_t*) _a13_slotarr->buf->slots)[_a13_slotarr->offset + (size_t) l5];
        t3 = t2;
        if (t3) {
            vader_array_push_i32((vader_array_t*) l10, INT32_C(-1));
        } else {
            t4 = ((vader_array_t*) l4)->length;
            l6 = ((int32_t) (int64_t) t4);
            vader_array_push_i32((vader_array_t*) l10, l6);
            vader_array_t* _a14_slotarr = ((vader_array_t*) l1);
            VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
            l11 = vader_array_ref_load_box(_a14_slotarr->buf, _a14_slotarr->offset + (size_t) l5);
            vader_array_push_ref((vader_array_t*) l4, l11.payload.obj);
        }
        l5 = (l5 + INT64_C(1));
    }
    l3 = ((vader_array_t*) l4)->length;
    l1 = vader_core_bytecode$remap_jump_table(l2, l10, l3);
    l2 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_debug;
    l3 = ((vader_array_t*) l4)->length;
    l2 = vader_emit_bytecode$remap_debug(l2, l10, l3);
    vader_struct_vader_emit_bytecode$BcPeepholeOut_t* _a15_obj = (vader_struct_vader_emit_bytecode$BcPeepholeOut_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_bytecode$BcPeepholeOut_t));
    vader_obj_header_init(_a15_obj, 1043u);
    _a15_obj->f_body = l4;
    _a15_obj->f_jump_table = l1;
    _a15_obj->f_debug = l2;
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
    l5 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l6);
    l7 = vader_emit_bytecode$last_empty_stack_point(l0, l2);
    vader_emit_bytecode$emit_instructions(l0, l2, INT64_C(0), l7);
    l6 = vader_emit_bytecode$open_blocks(l0, l5, l3);
    l8 = ((vader_struct_vader_midir$CFGFunction_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_fn_)->f_blocks;
    l9 = l2;
    vader_array_t* _a1_slotarr = ((vader_array_t*) l8);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l9)
    t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l9);
    l10 = ((vader_array_t*) ((vader_struct_vader_midir$BasicBlock_t*) t0)->f_instructions)->length;
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
    int32_t l18, l22;
    vader_string_t l19 = 0;
    vader_string_t l42 = 0;
    vader_string_t l43 = 0;
    vader_string_t l44 = 0;
    vader_box_t l20 = vader_box_null(), l23 = vader_box_null(), l25 = vader_box_null();
    bool l26;
    vader_box_t t0 = vader_box_null();
    vader_string_t t1 = 0;
    void* t2 = NULL;
    bool t3;
    int64_t t4;
    vader_box_t* gc_roots[4] = { &l20, &l23, &l25, &t0 };
    void** gc_raw_roots[27] = {
        &l0, &l2, &l3, &l4, &l5, &l6, &l9, &l12, &l15, &l21, &l24, &l27, &l28, &l29, &l30, &l31,
        &l32, &l33, &l34, &l35, &l36, &l37, &l38, &l39, &l40, &l41, &t2,
    };
    vader_string_t* gc_atom_roots[6] = { &l1, &l19, &l42, &l43, &l44, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 27u, gc_roots, gc_raw_roots, 0u, NULL, 6u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = vader_emit_bytecode$new_emitter_ctx();
    l4 = ((vader_struct_vader_midir$CFGProject_t*) l0)->f_modules;
    l5 = ((vader_struct_std_collections$MutableMap__string__vader_midir_CFGModule_t*) l4)->f_ekeys;
    l6 = ((vader_struct_std_collections$MutableMap__string__vader_midir_CFGModule_t*) l4)->f_evals;
    l7 = INT64_C(0);
    l8 = ((vader_struct_std_collections$MutableMap__string__vader_midir_CFGModule_t*) l4)->f_size;
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
        l9 = ((vader_struct_vader_midir$CFGModule_t*) l4)->f_functions;
        l10 = ((vader_array_t*) l9)->length;
        l11 = INT64_C(0);
        while ((l11 < l10)) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) l9);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            t2 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l11);
            vader_emit_bytecode$reserve_cfg_function(t2, l3);
            l11 = (l11 + INT64_C(1));
        }
        l12 = ((vader_struct_vader_midir$CFGModule_t*) l4)->f_externs;
        l13 = ((vader_array_t*) l12)->length;
        l14 = INT64_C(0);
        while ((l14 < l13)) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l12);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l14)
            t2 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l14);
            vader_emit_bytecode$reserve_cfg_extern(t2, l3);
            l14 = (l14 + INT64_C(1));
        }
        l15 = ((vader_struct_vader_midir$CFGModule_t*) l4)->f_struct_decls;
        l16 = ((vader_array_t*) l15)->length;
        l17 = INT64_C(0);
        while ((l17 < l16)) {
            vader_array_t* _a4_slotarr = ((vader_array_t*) l15);
            VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
            t2 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l17);
            vader_emit_bytecode$reserve_cfg_struct(t2, l3);
            l17 = (l17 + INT64_C(1));
        }
        l7 = (l7 + INT64_C(1));
    }
    vader_emit_bytecode$synthesise_cfg_intrinsic_wrappers(l0, l3);
    vader_array_t* _a5_arr = vader_array_new(23u, 0u, 7u, 450u);
    l4 = (void*) _a5_arr;
    l7 = ((vader_array_t*) ((vader_struct_vader_midir$CFGProject_t*) l0)->f_strings)->length;
    vader_array_t* _a6_arr = vader_array_repeat((vader_array_t*) l4, (int64_t) l7);
    l4 = (void*) _a6_arr;
    l5 = ((vader_struct_vader_midir$CFGProject_t*) l0)->f_strings;
    l7 = ((vader_array_t*) l5)->length;
    l8 = INT64_C(0);
    while ((l8 < l7)) {
        vader_array_t* _a7_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
        t0 = vader_array_box_slots(_a7_slotarr->buf)[_a7_slotarr->offset + (size_t) l8];
        t1 = t0.payload.s;
        l18 = vader_emit_bytecode$intern_string(t1, l3);
        vader_array_push_i32((vader_array_t*) l4, l18);
        l8 = (l8 + INT64_C(1));
    }
    l5 = ((vader_struct_vader_midir$CFGProject_t*) l0)->f_data_pool;
    l5 = vader_emit_bytecode$convert_data_pool(l3, l5);
    l6 = ((vader_struct_vader_midir$CFGProject_t*) l0)->f_globals;
    l7 = ((vader_array_t*) l6)->length;
    l8 = INT64_C(0);
    while ((l8 < l7)) {
        vader_array_t* _a8_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
        l9 = vader_array_ref_load_obj(_a8_slotarr->buf, _a8_slotarr->offset + (size_t) l8);
        l12 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l3)->f_globals;
        l19 = ((vader_struct_vader_lower_ir$GlobalSlot_t*) l9)->f_name;
        l18 = vader_emit_bytecode$intern_type(((vader_struct_vader_lower_ir$GlobalSlot_t*) l9)->f_type, l3);
        vader_struct_vader_core_bytecode$BcGlobal_t* _a9_obj = (vader_struct_vader_core_bytecode$BcGlobal_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcGlobal_t));
        vader_obj_header_init(_a9_obj, 853u);
        _a9_obj->f_name = l19;
        _a9_obj->f_type_id = l18;
        l15 = (void*) _a9_obj;
        vader_array_push_ref((vader_array_t*) l12, l15);
        l8 = (l8 + INT64_C(1));
    }
    l6 = ((vader_struct_vader_midir$CFGProject_t*) l0)->f_modules;
    l9 = ((vader_struct_std_collections$MutableMap__string__vader_midir_CFGModule_t*) l6)->f_ekeys;
    l12 = ((vader_struct_std_collections$MutableMap__string__vader_midir_CFGModule_t*) l6)->f_evals;
    l7 = INT64_C(0);
    l8 = ((vader_struct_std_collections$MutableMap__string__vader_midir_CFGModule_t*) l6)->f_size;
    while ((l7 < l8)) {
        vader_array_t* _a10_slotarr = ((vader_array_t*) l9);
        VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a10_slotarr, l7)
        t0 = vader_array_box_slots(_a10_slotarr->buf)[_a10_slotarr->offset + (size_t) l7];
        t1 = t0.payload.s;
        vader_array_t* _a11_slotarr = ((vader_array_t*) l12);
        VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l7)
        t2 = vader_array_ref_load_obj(_a11_slotarr->buf, _a11_slotarr->offset + (size_t) l7);
        l6 = ((vader_struct_vader_midir$CFGModule_t*) t2)->f_functions;
        l10 = ((vader_array_t*) l6)->length;
        l11 = INT64_C(0);
        while ((l11 < l10)) {
            vader_array_t* _a12_slotarr = ((vader_array_t*) l6);
            VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a12_slotarr, l11)
            l15 = vader_array_ref_load_obj(_a12_slotarr->buf, _a12_slotarr->offset + (size_t) l11);
            l18 = INT32_C(-1);
            l20 = ((vader_struct_vader_core_mono$MonoEntry_t*) ((vader_struct_vader_midir$CFGFunction_t*) l15)->f_origin)->f_symbol;
            if (l20.tag == 1015u) {
                l21 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l3)->f_function_index_by_symbol_id;
                t2 = l20.payload.obj;
                l22 = ((vader_struct_vader_core_symbol$Symbol_t*) t2)->f_id;
                l23 = std_collections$MutableMap$std_core$Index$at__i32__i32(l21, l22);
                if (l23.tag == 450u) {
                    l18 = ((int32_t) l23.payload.i);
                }
            }
            if ((l18 < INT32_C(0))) {
                l24 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l3)->f_function_index_by_mangle;
                l19 = ((vader_struct_vader_midir$CFGFunction_t*) l15)->f_mangled;
                l25 = std_collections$MutableMap$std_core$Index$at__string__i32(l24, l19);
                if (l25.tag == 450u) {
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
    t3 = ((vader_struct_vader_emit_bytecode$EmitOptions_t*) l2)->f_optimize;
    if (t3) {
        l7 = INT64_C(0);
        l8 = ((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l3)->f_functions)->length;
        while ((l7 < l8)) {
            vader_array_t* _a13_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l3)->f_functions);
            VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a13_slotarr, l7)
            t2 = vader_array_ref_load_obj(_a13_slotarr->buf, _a13_slotarr->offset + (size_t) l7);
            t4 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) t2)->f_body)->length;
            l10 = vader_chk_add(i64, t4, INT64_C(1));
            for (;;) {
                vader_array_t* _a14_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l3)->f_functions);
                VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a14_slotarr, l7)
                t2 = vader_array_ref_load_obj(_a14_slotarr->buf, _a14_slotarr->offset + (size_t) l7);
                t4 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) t2)->f_body)->length;
                if ((t4 < l10)) {
                    vader_array_t* _a15_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l3)->f_functions);
                    VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a15_slotarr, l7)
                    t2 = vader_array_ref_load_obj(_a15_slotarr->buf, _a15_slotarr->offset + (size_t) l7);
                    l10 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) t2)->f_body)->length;
                    l4 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l3)->f_functions;
                    VADER_ARRAY_CHECK_INDEX(_a15_slotarr, l7)
                    t2 = vader_array_ref_load_obj(_a15_slotarr->buf, _a15_slotarr->offset + (size_t) l7);
                    l6 = vader_emit_bytecode$propagate_const_single_use(t2);
                    vader_array_t* _a16_slotarr = ((vader_array_t*) l4);
                    VADER_ARRAY_RESOLVE_BUF(_a16_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a16_slotarr, l7)
                    vader_array_ref_store(_a16_slotarr->buf, _a16_slotarr->offset + (size_t) l7, l6);
                    VADER_WRITE_BARRIER(_a16_slotarr->buf);
                    continue;
                }
                break;
            }
            l9 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l3)->f_functions;
            vader_array_t* _a17_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l3)->f_functions);
            VADER_ARRAY_RESOLVE_BUF(_a17_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a17_slotarr, l7)
            l12 = vader_array_ref_load_obj(_a17_slotarr->buf, _a17_slotarr->offset + (size_t) l7);
            VADER_ARRAY_CHECK_INDEX(_a17_slotarr, l7)
            t2 = vader_array_ref_load_obj(_a17_slotarr->buf, _a17_slotarr->offset + (size_t) l7);
            l15 = vader_emit_bytecode$run_bc_peephole(t2);
            l21 = vader_emit_bytecode$with_peephole_out(l12, l15);
            vader_array_t* _a18_slotarr = ((vader_array_t*) l9);
            VADER_ARRAY_RESOLVE_BUF(_a18_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a18_slotarr, l7)
            vader_array_ref_store(_a18_slotarr->buf, _a18_slotarr->offset + (size_t) l7, l21);
            VADER_WRITE_BARRIER(_a18_slotarr->buf);
            l24 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l3)->f_functions;
            vader_array_t* _a19_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l3)->f_functions);
            VADER_ARRAY_RESOLVE_BUF(_a19_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a19_slotarr, l7)
            l27 = vader_array_ref_load_obj(_a19_slotarr->buf, _a19_slotarr->offset + (size_t) l7);
            VADER_ARRAY_CHECK_INDEX(_a19_slotarr, l7)
            t2 = vader_array_ref_load_obj(_a19_slotarr->buf, _a19_slotarr->offset + (size_t) l7);
            l28 = vader_emit_bytecode$run_bc_const_fold_arith(t2);
            l29 = vader_emit_bytecode$with_peephole_out(l27, l28);
            vader_array_t* _a20_slotarr = ((vader_array_t*) l24);
            VADER_ARRAY_RESOLVE_BUF(_a20_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a20_slotarr, l7)
            vader_array_ref_store(_a20_slotarr->buf, _a20_slotarr->offset + (size_t) l7, l29);
            VADER_WRITE_BARRIER(_a20_slotarr->buf);
            l30 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l3)->f_functions;
            vader_array_t* _a21_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l3)->f_functions);
            VADER_ARRAY_RESOLVE_BUF(_a21_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a21_slotarr, l7)
            t2 = vader_array_ref_load_obj(_a21_slotarr->buf, _a21_slotarr->offset + (size_t) l7);
            l31 = vader_emit_bytecode$drop_dead_stores(t2);
            vader_array_t* _a22_slotarr = ((vader_array_t*) l30);
            VADER_ARRAY_RESOLVE_BUF(_a22_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a22_slotarr, l7)
            vader_array_ref_store(_a22_slotarr->buf, _a22_slotarr->offset + (size_t) l7, l31);
            VADER_WRITE_BARRIER(_a22_slotarr->buf);
            l32 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l3)->f_functions;
            vader_array_t* _a23_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l3)->f_functions);
            VADER_ARRAY_RESOLVE_BUF(_a23_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a23_slotarr, l7)
            l33 = vader_array_ref_load_obj(_a23_slotarr->buf, _a23_slotarr->offset + (size_t) l7);
            VADER_ARRAY_CHECK_INDEX(_a23_slotarr, l7)
            t2 = vader_array_ref_load_obj(_a23_slotarr->buf, _a23_slotarr->offset + (size_t) l7);
            l34 = vader_emit_bytecode$run_bc_return_lit_fold(t2);
            l35 = vader_emit_bytecode$with_peephole_out(l33, l34);
            vader_array_t* _a24_slotarr = ((vader_array_t*) l32);
            VADER_ARRAY_RESOLVE_BUF(_a24_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a24_slotarr, l7)
            vader_array_ref_store(_a24_slotarr->buf, _a24_slotarr->offset + (size_t) l7, l35);
            VADER_WRITE_BARRIER(_a24_slotarr->buf);
            l36 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l3)->f_functions;
            vader_array_t* _a25_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l3)->f_functions);
            VADER_ARRAY_RESOLVE_BUF(_a25_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a25_slotarr, l7)
            t2 = vader_array_ref_load_obj(_a25_slotarr->buf, _a25_slotarr->offset + (size_t) l7);
            l37 = vader_emit_bytecode$coalesce_slots(t2);
            vader_array_t* _a26_slotarr = ((vader_array_t*) l36);
            VADER_ARRAY_RESOLVE_BUF(_a26_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a26_slotarr, l7)
            vader_array_ref_store(_a26_slotarr->buf, _a26_slotarr->offset + (size_t) l7, l37);
            VADER_WRITE_BARRIER(_a26_slotarr->buf);
            l38 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l3)->f_functions;
            vader_array_t* _a27_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l3)->f_functions);
            VADER_ARRAY_RESOLVE_BUF(_a27_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a27_slotarr, l7)
            l39 = vader_array_ref_load_obj(_a27_slotarr->buf, _a27_slotarr->offset + (size_t) l7);
            VADER_ARRAY_CHECK_INDEX(_a27_slotarr, l7)
            t2 = vader_array_ref_load_obj(_a27_slotarr->buf, _a27_slotarr->offset + (size_t) l7);
            l40 = vader_emit_bytecode$strip_self_copies(t2);
            l41 = vader_emit_bytecode$with_peephole_out(l39, l40);
            vader_array_t* _a28_slotarr = ((vader_array_t*) l38);
            VADER_ARRAY_RESOLVE_BUF(_a28_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a28_slotarr, l7)
            vader_array_ref_store(_a28_slotarr->buf, _a28_slotarr->offset + (size_t) l7, l41);
            VADER_WRITE_BARRIER(_a28_slotarr->buf);
            l7 = (l7 + INT64_C(1));
        }
        vader_array_t* _a29_arr = vader_array_new(22u, 0u, 0u, 447u);
        l4 = (void*) _a29_arr;
        vader_array_t* _a30_arr = vader_array_new(20u, 0u, 12u, 445u);
        l6 = (void*) _a30_arr;
        vader_array_t* _a31_arr = vader_array_new(23u, 0u, 7u, 450u);
        l9 = (void*) _a31_arr;
        vader_struct_std_collections$MutableMap__string__bool_t* _a32_obj = (vader_struct_std_collections$MutableMap__string__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__string__bool_t));
        vader_obj_header_init(_a32_obj, 662u);
        _a32_obj->f_ekeys = l4;
        _a32_obj->f_evals = l6;
        _a32_obj->f_index = l9;
        _a32_obj->f_mask = INT64_C(0);
        _a32_obj->f_grow_at = INT64_C(0);
        _a32_obj->f_size = INT64_C(0);
        _a32_obj->f_tombs = INT64_C(0);
        l4 = (void*) _a32_obj;
        l6 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l3)->f_functions;
        l7 = ((vader_array_t*) l6)->length;
        l8 = INT64_C(0);
        while ((l8 < l7)) {
            vader_array_t* _a33_slotarr = ((vader_array_t*) l6);
            VADER_ARRAY_RESOLVE_BUF(_a33_slotarr)
            t2 = vader_array_ref_load_obj(_a33_slotarr->buf, _a33_slotarr->offset + (size_t) l8);
            l9 = ((vader_struct_vader_core_bytecode$BcFunction_t*) t2)->f_body;
            l10 = ((vader_array_t*) l9)->length;
            l11 = INT64_C(0);
            while ((l11 < l10)) {
                vader_array_t* _a34_slotarr = ((vader_array_t*) l9);
                VADER_ARRAY_RESOLVE_BUF(_a34_slotarr)
                l20 = vader_array_ref_load_box(_a34_slotarr->buf, _a34_slotarr->offset + (size_t) l11);
                if (l20.tag == 1010u) {
                    t2 = l20.payload.obj;
                    l19 = ((vader_struct_vader_core_bytecode$VirtualCall_t*) t2)->f_vtable_key;
                    std_collections$MutableMap$std_core$IndexSet$set_at__string__bool(l4, l19, true);
                }
                l11 = (l11 + INT64_C(1));
            }
            l8 = (l8 + INT64_C(1));
        }
        vader_array_t* _a35_arr = vader_array_new(23u, 0u, 7u, 450u);
        l6 = (void*) _a35_arr;
        l9 = ((vader_struct_vader_midir$CFGProject_t*) l0)->f_vtable_entries;
        l7 = ((vader_array_t*) l9)->length;
        l8 = INT64_C(0);
        while ((l8 < l7)) {
            vader_array_t* _a36_slotarr = ((vader_array_t*) l9);
            VADER_ARRAY_RESOLVE_BUF(_a36_slotarr)
            l12 = vader_array_ref_load_obj(_a36_slotarr->buf, _a36_slotarr->offset + (size_t) l8);
            l19 = ((vader_struct_vader_lower_ir$LoweredVtableEntry_t*) l12)->f_trait_name;
            l42 = ((vader_struct_vader_lower_ir$LoweredVtableEntry_t*) l12)->f_method_name;
            l43 = vader_midir$vtable_key(l19, l42);
            t0 = std_collections$MutableMap$std_core$Index$at__string__bool(l4, l43);
            if (t0.tag == 445u) {
                l44 = vader_midir_select$type_intern_key(((vader_struct_vader_lower_ir$LoweredVtableEntry_t*) l12)->f_struct_type);
                l20 = std_collections$MutableMap$std_core$Index$at__string__i32(((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l3)->f_type_key, l44);
                if (l20.tag == 450u) {
                    l15 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l3)->f_pinned_types;
                    l18 = ((int32_t) l20.payload.i);
                    vader_array_push_i32((vader_array_t*) l15, l18);
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
        l4 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l3)->f_imports;
        l7 = ((vader_array_t*) l4)->length;
        l8 = INT64_C(0);
        while ((l8 < l7)) {
            vader_array_t* _a37_slotarr = ((vader_array_t*) l4);
            VADER_ARRAY_RESOLVE_BUF(_a37_slotarr)
            l6 = vader_array_ref_load_obj(_a37_slotarr->buf, _a37_slotarr->offset + (size_t) l8);
            l19 = ((vader_struct_vader_core_bytecode$BcImport_t*) l6)->f_mangled_name;
            l26 = ((vader_struct_vader_core_bytecode$BcImport_t*) l6)->f_is_extern;
            vader_midir_select$assert_host_import_wired(l19, l26);
            l8 = (l8 + INT64_C(1));
        }
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
    vader_struct_vader_core_bytecode$BytecodeModule_t* _a38_obj = (vader_struct_vader_core_bytecode$BytecodeModule_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BytecodeModule_t));
    vader_obj_header_init(_a38_obj, 881u);
    _a38_obj->f_name = l1;
    _a38_obj->f_types = l4;
    _a38_obj->f_strings = l6;
    _a38_obj->f_data_pool = l5;
    _a38_obj->f_functions = l9;
    _a38_obj->f_imports = l12;
    _a38_obj->f_exports = l15;
    _a38_obj->f_impl_table = l21;
    _a38_obj->f_vtables = l24;
    _a38_obj->f_globals = l3;
    t2 = (void*) _a38_obj;
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
    t0 = ((vader_array_t*) l2)->length;
    if ((t0 <= INT64_C(1))) {
        t0 = ((vader_array_t*) l2)->length;
        if (t0 == INT64_C(0)) {
            l4 = vader_box_obj(0u, NULL);
            vader_emit_bytecode$emit_result_if_any(l0, l1, l4, l3);
            { vader_gc_top = gc_frame.prev; return; }
        }
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
        t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) INT32_C(0)];
        l4 = vader_box_i32(450u, t1);
        vader_emit_bytecode$emit_result_if_any(l0, l1, l4, l3);
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
    l5 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l1);
    vader_array_t* _a1_arr = vader_array_new(23u, 0u, 7u, 450u);
    l6 = (void*) _a1_arr;
    std_collections$MutableMap$std_core$IndexSet$set_at__i32__Any(((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l2)->f_pinned_types_by_fn, l1, vader_ref_box(l6));
    vader_array_t* _a2_arr = vader_array_new(23u, 0u, 7u, 450u);
    l7 = (void*) _a2_arr;
    l8 = ((vader_array_t*) ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_params)->length;
    l9 = INT64_C(0);
    l10 = ((vader_array_t*) ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_locals)->length;
    while ((l9 < l10)) {
        if ((l9 < l8)) {
            l11 = ((int32_t) (int64_t) l9);
            vader_array_push_i32((vader_array_t*) l7, l11);
        } else {
            l12 = ((int32_t) (int64_t) l8);
            t0 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l5)->f_locals)->length;
            l13 = ((int32_t) (int64_t) t0);
            l14 = vader_chk_add(i32, l12, l13);
            l15 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l5)->f_locals;
            vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_locals);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l9)
            t1 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l9);
            l16 = ((vader_struct_vader_midir$CFGLocal_t*) t1)->f_name;
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l9)
            t1 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l9);
            l17 = vader_midir_select$val_type_of_type(((vader_struct_vader_midir$CFGLocal_t*) t1)->f_type);
            vader_struct_vader_core_bytecode$BcLocal_t* _a4_obj = (vader_struct_vader_core_bytecode$BcLocal_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcLocal_t));
            vader_obj_header_init(_a4_obj, 855u);
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
    vader_array_t* _a5_arr = vader_array_new(192u, 0u, 13u, 1050u);
    l19 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(191u, 0u, 13u, 1048u);
    l20 = (void*) _a6_arr;
    vader_struct_vader_emit_bytecode$FnEmitCfg_t* _a7_obj = (vader_struct_vader_emit_bytecode$FnEmitCfg_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_bytecode$FnEmitCfg_t));
    vader_obj_header_init(_a7_obj, 1047u);
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
    l6 = vader_array_ref_load_obj(_a8_slotarr->buf, _a8_slotarr->offset + (size_t) l1);
    VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l1)
    t1 = vader_array_ref_load_obj(_a8_slotarr->buf, _a8_slotarr->offset + (size_t) l1);
    l7 = vader_emit_bytecode$drop_unbranched_blocks(t1);
    l6 = vader_emit_bytecode$with_peephole_out(l6, l7);
    vader_array_t* _a9_slotarr = ((vader_array_t*) l5);
    VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l1)
    vader_array_ref_store(_a9_slotarr->buf, _a9_slotarr->offset + (size_t) l1, l6);
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
    t0 = std_collections$MutableSet$std_core$Contains$contains__i32(((vader_struct_vader_emit_bytecode$ScheduleHints_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_hints)->f_skip_terminator_get, l2);
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
    l6 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l6];
    l7 = ((vader_struct_vader_emit_bytecode$StructureShape_t*) l1)->f_rpo_index;
    l9 = l2;
    vader_array_t* _a1_slotarr = ((vader_array_t*) l7);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l9)
    l9 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l9];
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
            t0 = ((uint8_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l6];
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
    if (l3.tag == 1445u) {
        t0 = vader_midir_select$val_type_of_type(((vader_struct_vader_midir$InstrConst_t*) l1)->f_type);
        t1 = vader_core_bytecode$is_64_bit_int_val(t0);
        if (t1) {
            t2 = l3.payload.obj;
            t3 = ((vader_struct_vader_midir$ConstInt_t*) t2)->f_value;
            vader_struct_vader_core_bytecode$I64Const_t* _a0_obj = (vader_struct_vader_core_bytecode$I64Const_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$I64Const_t));
            vader_obj_header_init(_a0_obj, 940u);
            _a0_obj->f_value = t3;
            l4 = (void*) _a0_obj;
            l5 = ((vader_struct_vader_midir$InstrConst_t*) l1)->f_span;
            vader_emit_bytecode$push_emit(l0, vader_ref_box(l4), l5);
        } else {
            t2 = l3.payload.obj;
            t3 = ((vader_struct_vader_midir$ConstInt_t*) t2)->f_value;
            vader_struct_vader_core_bytecode$I32Const_t* _a1_obj = (vader_struct_vader_core_bytecode$I32Const_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$I32Const_t));
            vader_obj_header_init(_a1_obj, 920u);
            _a1_obj->f_value = ((int32_t) (int64_t) t3);
            l4 = (void*) _a1_obj;
            l5 = ((vader_struct_vader_midir$InstrConst_t*) l1)->f_span;
            vader_emit_bytecode$push_emit(l0, vader_ref_box(l4), l5);
        }
    } else if (l3.tag == 1444u) {
        t2 = l3.payload.obj;
        t4 = ((vader_struct_vader_midir$ConstFloat_t*) t2)->f_value;
        vader_struct_vader_core_bytecode$F64Const_t* _a2_obj = (vader_struct_vader_core_bytecode$F64Const_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$F64Const_t));
        vader_obj_header_init(_a2_obj, 899u);
        _a2_obj->f_value = t4;
        l4 = (void*) _a2_obj;
        l5 = ((vader_struct_vader_midir$InstrConst_t*) l1)->f_span;
        vader_emit_bytecode$push_emit(l0, vader_ref_box(l4), l5);
    } else if (l3.tag == 1442u) {
        t2 = l3.payload.obj;
        t1 = ((vader_struct_vader_midir$ConstBool_t*) t2)->f_value;
        vader_struct_vader_core_bytecode$BoolConst_t* _a3_obj = (vader_struct_vader_core_bytecode$BoolConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BoolConst_t));
        vader_obj_header_init(_a3_obj, 871u);
        _a3_obj->f_value = t1;
        l4 = (void*) _a3_obj;
        l5 = ((vader_struct_vader_midir$InstrConst_t*) l1)->f_span;
        vader_emit_bytecode$push_emit(l0, vader_ref_box(l4), l5);
    } else if (l3.tag == 1443u) {
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
        vader_obj_header_init(_a4_obj, 886u);
        _a4_obj->f_value = ((uint32_t) (uint32_t) l6);
        l4 = (void*) _a4_obj;
        l5 = ((vader_struct_vader_midir$InstrConst_t*) l1)->f_span;
        vader_emit_bytecode$push_emit(l0, vader_ref_box(l4), l5);
    } else if (l3.tag == 1446u) {
        t2 = (void*) &vader_data_69;
        vader_array_t* _a5_slotarr = ((vader_array_t*) t2);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        l4 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) INT64_C(0));
        l5 = ((vader_struct_vader_midir$InstrConst_t*) l1)->f_span;
        vader_emit_bytecode$push_emit(l0, vader_ref_box(l4), l5);
    } else if (l3.tag == 1447u) {
        l4 = ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_string_index_map;
        t2 = l3.payload.obj;
        l8 = ((vader_struct_vader_midir$ConstString_t*) t2)->f_index;
        vader_array_t* _a6_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l8)
        t5 = ((int32_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l8];
        vader_struct_vader_core_bytecode$StringConst_t* _a7_obj = (vader_struct_vader_core_bytecode$StringConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$StringConst_t));
        vader_obj_header_init(_a7_obj, 987u);
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
    t0 = std_collections$MutableSet$std_core$Contains$contains__i64(((vader_struct_vader_emit_bytecode$ScheduleHints_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_hints)->f_skip_first_get, l1);
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
    t0 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l4];
    vader_struct_vader_core_bytecode$LocalGet_t* _a1_obj = (vader_struct_vader_core_bytecode$LocalGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$LocalGet_t));
    vader_obj_header_init(_a1_obj, 965u);
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
    if (l1.tag == 1465u) {
        l3 = l1.payload.obj;
        vader_emit_bytecode$emit_const_instr(l0, l3, l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 1477u) {
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
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
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
    if (l1.tag == 1458u) {
        l3 = ((vader_struct_vader_midir$CFGFunction_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_fn_)->f_locals;
        t0 = l1.payload.obj;
        l5 = ((int64_t) (int32_t) ((vader_struct_vader_midir$InstrBinOp_t*) t0)->f_lhs);
        vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
        t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5);
        l7 = ((vader_struct_vader_midir$CFGLocal_t*) t0)->f_type;
        l3 = ((vader_struct_vader_midir$CFGFunction_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_fn_)->f_locals;
        t0 = l1.payload.obj;
        l5 = ((int64_t) (int32_t) ((vader_struct_vader_midir$InstrBinOp_t*) t0)->f_rhs);
        vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l5)
        t0 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l5);
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
    if (l1.tag == 1459u) {
        l3 = ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_pinned_types_bucket;
        t0 = l1.payload.obj;
        l12 = ((vader_struct_vader_midir$InstrCall_t*) t0)->f_args;
        l5 = ((vader_array_t*) l12)->length;
        l13 = INT64_C(0);
        while ((l13 < l5)) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l12);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            l4 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l13];
            l14 = ((vader_struct_vader_midir$CFGFunction_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_fn_)->f_locals;
            l15 = ((int64_t) (int32_t) l4);
            vader_array_t* _a4_slotarr = ((vader_array_t*) l14);
            VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l15)
            t0 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l15);
            l7 = ((vader_struct_vader_midir$CFGLocal_t*) t0)->f_type;
            l16 = ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_project;
            l17 = vader_emit_bytecode$intern_type(l7, l16);
            vader_array_push_i32((vader_array_t*) l3, l17);
            l13 = (l13 + INT64_C(1));
        }
        t0 = l1.payload.obj;
        l12 = ((vader_struct_vader_midir$InstrCall_t*) t0)->f_dsts;
        l5 = ((vader_array_t*) l12)->length;
        l13 = INT64_C(0);
        while ((l13 < l5)) {
            vader_array_t* _a5_slotarr = ((vader_array_t*) l12);
            VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
            l4 = ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l13];
            l14 = ((vader_struct_vader_midir$CFGFunction_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_fn_)->f_locals;
            l15 = ((int64_t) (int32_t) l4);
            vader_array_t* _a6_slotarr = ((vader_array_t*) l14);
            VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l15)
            t0 = vader_array_ref_load_obj(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l15);
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
    if (l1.tag == 1481u) {
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
        t0 = vader_array_ref_load_obj(_a7_slotarr->buf, _a7_slotarr->offset + (size_t) l5);
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
    if (l1.tag == 1460u) {
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir$InstrCallIndirect_t*) t0)->f_args;
        t0 = l1.payload.obj;
        l12 = vader_emit_bytecode$every_operand_boxed(((vader_struct_vader_midir$InstrCallIndirect_t*) t0)->f_args);
        t0 = l1.payload.obj;
        l14 = ((vader_struct_vader_midir$InstrCallIndirect_t*) t0)->f_span;
        vader_emit_bytecode$emit_operands_into(l0, l2, l3, l12, l14);
        t0 = l1.payload.obj;
        t2 = ((vader_array_t*) ((vader_struct_vader_midir$InstrCallIndirect_t*) t0)->f_args)->length;
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
        vader_obj_header_init(_a8_obj, 885u);
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
    if (l1.tag == 1472u) {
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir$InstrFnRef_t*) t0)->f_fn_symbol;
        l12 = ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_project;
        l7 = vader_emit_bytecode$resolve_fn_index(l3, l12);
        if (!(l7.tag == 450u)) {
            t0 = l1.payload.obj;
            l18 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_midir$InstrFnRef_t*) t0)->f_fn_symbol)->f_name;
            l5 = vader_host_std_core$byte_len(l18);
            l14 = (void*) vader_buffer_new((size_t) (INT64_C(98) + l5));
            l5 = INT64_C(0);
            l5 = std_core$write_string_at(l14, l5, 1868u);
            l5 = std_core$write_string_at(l14, l5, l18);
            l5 = std_core$write_string_at(l14, l5, 290u);
            t0 = l1.payload.obj;
            t3 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_midir$InstrFnRef_t*) t0)->f_fn_symbol)->f_id;
            l13 = ((int64_t) (int32_t) t3);
            l5 = std_core$write_int(l14, l5, l13);
            l5 = std_core$write_string_at(l14, l5, 330u);
            t4 = std_core$finish_buffer(l14, l5);
            vader_host_std_abort$panic(t4);
            vader_unreachable("a no-return call returned");
        }
        t0 = l1.payload.obj;
        l8 = ((vader_struct_vader_midir$InstrFnRef_t*) t0)->f_type;
        l3 = ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_project;
        l4 = vader_emit_bytecode$intern_type(l8, l3);
        t3 = ((int32_t) l7.payload.i);
        vader_struct_vader_core_bytecode$FnRef_t* _a9_obj = (vader_struct_vader_core_bytecode$FnRef_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$FnRef_t));
        vader_obj_header_init(_a9_obj, 912u);
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
    if (l1.tag == 1471u) {
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir$InstrFnAddr_t*) t0)->f_fn_symbol;
        l12 = ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_project;
        l7 = vader_emit_bytecode$resolve_fn_index(l3, l12);
        if (!(l7.tag == 450u)) {
            t0 = l1.payload.obj;
            l18 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_midir$InstrFnAddr_t*) t0)->f_fn_symbol)->f_name;
            l5 = vader_host_std_core$byte_len(l18);
            l14 = (void*) vader_buffer_new((size_t) (INT64_C(111) + l5));
            l5 = INT64_C(0);
            l5 = std_core$write_string_at(l14, l5, 1867u);
            l5 = std_core$write_string_at(l14, l5, l18);
            l5 = std_core$write_string_at(l14, l5, 290u);
            t0 = l1.payload.obj;
            t3 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_midir$InstrFnAddr_t*) t0)->f_fn_symbol)->f_id;
            l13 = ((int64_t) (int32_t) t3);
            l5 = std_core$write_int(l14, l5, l13);
            l5 = std_core$write_string_at(l14, l5, 347u);
            t4 = std_core$finish_buffer(l14, l5);
            vader_host_std_abort$panic(t4);
            vader_unreachable("a no-return call returned");
        }
        t3 = ((int32_t) l7.payload.i);
        vader_struct_vader_core_bytecode$FnAddr_t* _a10_obj = (vader_struct_vader_core_bytecode$FnAddr_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$FnAddr_t));
        vader_obj_header_init(_a10_obj, 911u);
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
    if (l1.tag == 1484u) {
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir$InstrVirtualCall_t*) t0)->f_args;
        t0 = l1.payload.obj;
        l12 = vader_emit_bytecode$every_operand_boxed(((vader_struct_vader_midir$InstrVirtualCall_t*) t0)->f_args);
        t0 = l1.payload.obj;
        l14 = ((vader_struct_vader_midir$InstrVirtualCall_t*) t0)->f_span;
        vader_emit_bytecode$emit_operands_into(l0, l2, l3, l12, l14);
        t0 = l1.payload.obj;
        t2 = ((vader_array_t*) ((vader_struct_vader_midir$InstrVirtualCall_t*) t0)->f_args)->length;
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
        t2 = ((vader_array_t*) ((vader_struct_vader_midir$InstrVirtualCall_t*) t0)->f_args)->length;
        t5 = vader_chk_add(i64, t2, INT64_C(1));
        l4 = ((int32_t) (int64_t) t5);
        t0 = l1.payload.obj;
        l18 = ((vader_struct_vader_midir$InstrVirtualCall_t*) t0)->f_trait_name;
        t0 = l1.payload.obj;
        l19 = ((vader_struct_vader_midir$InstrVirtualCall_t*) t0)->f_method;
        l18 = vader_midir$vtable_key(l18, l19);
        t0 = l1.payload.obj;
        t6 = vader_midir_select$val_type_of_type(((vader_struct_vader_midir$InstrVirtualCall_t*) t0)->f_type);
        vader_array_t* _a11_arr = vader_array_new(25u, 1u, 1u, 452u);
        ((uint8_t*) _a11_arr->buf->slots)[_a11_arr->offset + 0u] = (uint8_t) (int32_t) (uint8_t) t6;
        l3 = (void*) _a11_arr;
        vader_struct_vader_core_bytecode$VirtualCall_t* _a12_obj = (vader_struct_vader_core_bytecode$VirtualCall_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$VirtualCall_t));
        vader_obj_header_init(_a12_obj, 1010u);
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
    if (l1.tag == 1469u) {
        l3 = ((vader_struct_vader_midir$CFGFunction_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_fn_)->f_locals;
        t0 = l1.payload.obj;
        l5 = ((int64_t) (int32_t) ((vader_struct_vader_midir$InstrFieldGet_t*) t0)->f_target);
        vader_array_t* _a13_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a13_slotarr, l5)
        l3 = vader_array_ref_load_obj(_a13_slotarr->buf, _a13_slotarr->offset + (size_t) l5);
        l7 = ((vader_struct_vader_midir$CFGLocal_t*) l3)->f_type;
        l12 = ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_project;
        l4 = vader_emit_bytecode$intern_type(l7, l12);
        l6 = std_collections$MutableSet$std_core$Contains$contains__i64(((vader_struct_vader_emit_bytecode$ScheduleHints_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_hints)->f_skip_first_get, l2);
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
            l5 = vader_host_std_core$byte_len(l18);
            l13 = vader_host_std_core$byte_len(l19);
            l5 = (l5 + l13);
            l13 = vader_host_std_core$byte_len(l20);
            l5 = (l5 + l13);
            l13 = vader_host_std_core$byte_len(l21);
            l5 = (l5 + l13);
            l3 = (void*) vader_buffer_new((size_t) (INT64_C(75) + l5));
            l5 = INT64_C(0);
            l5 = std_core$write_string_at(l3, l5, 1861u);
            l5 = std_core$write_string_at(l3, l5, l18);
            l5 = std_core$write_string_at(l3, l5, 1210u);
            l5 = std_core$write_string_at(l3, l5, l19);
            l5 = std_core$write_string_at(l3, l5, 1040u);
            l13 = ((int64_t) (int32_t) l17);
            l5 = std_core$write_int(l3, l5, l13);
            l5 = std_core$write_string_at(l3, l5, 85u);
            l5 = std_core$write_string_at(l3, l5, l20);
            l5 = std_core$write_string_at(l3, l5, 1268u);
            l5 = std_core$write_string_at(l3, l5, l21);
            l5 = std_core$write_string_at(l3, l5, 289u);
            t4 = std_core$finish_buffer(l3, l5);
            vader_host_std_abort$panic(t4);
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
                vader_obj_header_init(_a14_obj, 990u);
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
                vader_obj_header_init(_a15_obj, 972u);
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
    } else if (l1.tag == 1470u) {
        l3 = ((vader_struct_vader_midir$CFGFunction_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_fn_)->f_locals;
        t0 = l1.payload.obj;
        l5 = ((int64_t) (int32_t) ((vader_struct_vader_midir$InstrFieldSet_t*) t0)->f_target);
        vader_array_t* _a16_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a16_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a16_slotarr, l5)
        t0 = vader_array_ref_load_obj(_a16_slotarr->buf, _a16_slotarr->offset + (size_t) l5);
        l7 = ((vader_struct_vader_midir$CFGLocal_t*) t0)->f_type;
        l3 = ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_project;
        l4 = vader_emit_bytecode$intern_type(l7, l3);
        l3 = ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_project;
        t0 = l1.payload.obj;
        l18 = ((vader_struct_vader_midir$InstrFieldSet_t*) t0)->f_field;
        l8 = vader_emit_bytecode$find_struct_field_index(l3, l4, l18);
        if (!(l8.tag == 0u)) {
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
            l3 = ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_project;
            l5 = ((int64_t) l8.payload.i);
            l6 = vader_emit_bytecode$boxed_field(l3, l4, l5);
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir$InstrFieldSet_t*) t0)->f_span;
            vader_emit_bytecode$emit_retag_into(l0, l17, l6, l3);
            t2 = ((int64_t) l8.payload.i);
            l17 = ((int32_t) (int64_t) t2);
            t0 = l1.payload.obj;
            l6 = ((vader_struct_vader_midir$InstrFieldSet_t*) t0)->f_barrierless;
            vader_struct_vader_core_bytecode$StructSet_t* _a17_obj = (vader_struct_vader_core_bytecode$StructSet_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$StructSet_t));
            vader_obj_header_init(_a17_obj, 992u);
            _a17_obj->f_type_id = l4;
            _a17_obj->f_field_index = l17;
            _a17_obj->f_stack = l6;
            l3 = (void*) _a17_obj;
            t0 = l1.payload.obj;
            l12 = ((vader_struct_vader_midir$InstrFieldSet_t*) t0)->f_span;
            vader_emit_bytecode$push_emit(l0, vader_ref_box(l3), l12);
            { vader_gc_top = gc_frame.prev; return; }
        }
        t0 = l1.payload.obj;
        l18 = ((vader_struct_vader_midir$InstrFieldSet_t*) t0)->f_field;
        l19 = vader_core_types$display_type(l7);
        l20 = ((vader_struct_vader_midir$CFGFunction_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_fn_)->f_mangled;
        t4 = concat_7(1861u, l18, 1210u, l19, 1123u, l20, 304u);
        vader_host_std_abort$panic(t4);
        vader_unreachable("a no-return call returned");
    } else if (l1.tag == 1482u) {
        l3 = ((vader_struct_vader_midir$CFGFunction_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_fn_)->f_locals;
        t0 = l1.payload.obj;
        l5 = ((int64_t) (int32_t) ((vader_struct_vader_midir$InstrUnionFieldGet_t*) t0)->f_target);
        vader_array_t* _a18_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a18_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a18_slotarr, l5)
        t0 = vader_array_ref_load_obj(_a18_slotarr->buf, _a18_slotarr->offset + (size_t) l5);
        l7 = ((vader_struct_vader_midir$CFGLocal_t*) t0)->f_type;
        l3 = ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_project;
        l4 = vader_emit_bytecode$intern_type(l7, l3);
        l8 = vader_core_bytecode$union_layout_struct(((vader_struct_vader_emit_bytecode$EmitterCtx_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_project)->f_types, l4);
        if (l8.tag == 0u) {
            t0 = l1.payload.obj;
            l18 = ((vader_struct_vader_midir$InstrUnionFieldGet_t*) t0)->f_field;
            t4 = vader_emit_bytecode$no_common_field(l0, l18, l7);
            vader_host_std_abort$panic(t4);
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
                vader_host_std_abort$panic(t4);
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
                vader_obj_header_init(_a19_obj, 1007u);
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
                    vader_obj_header_init(_a20_obj, 972u);
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
    } else if (l1.tag == 1483u) {
        l3 = ((vader_struct_vader_midir$CFGFunction_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_fn_)->f_locals;
        t0 = l1.payload.obj;
        l5 = ((int64_t) (int32_t) ((vader_struct_vader_midir$InstrUnionFieldSet_t*) t0)->f_target);
        vader_array_t* _a21_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a21_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a21_slotarr, l5)
        t0 = vader_array_ref_load_obj(_a21_slotarr->buf, _a21_slotarr->offset + (size_t) l5);
        l7 = ((vader_struct_vader_midir$CFGLocal_t*) t0)->f_type;
        l3 = ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_project;
        l4 = vader_emit_bytecode$intern_type(l7, l3);
        l8 = vader_core_bytecode$union_layout_struct(((vader_struct_vader_emit_bytecode$EmitterCtx_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_project)->f_types, l4);
        if (l8.tag == 0u) {
            t0 = l1.payload.obj;
            l18 = ((vader_struct_vader_midir$InstrUnionFieldSet_t*) t0)->f_field;
            t4 = vader_emit_bytecode$no_common_field(l0, l18, l7);
            vader_host_std_abort$panic(t4);
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
                vader_host_std_abort$panic(t4);
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
                vader_obj_header_init(_a22_obj, 1008u);
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
        if (l1.tag == 1452u) {
            l3 = ((vader_struct_vader_midir$CFGFunction_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_fn_)->f_locals;
            t0 = l1.payload.obj;
            l5 = ((int64_t) (int32_t) ((vader_struct_vader_midir$InstrArrayGet_t*) t0)->f_target);
            vader_array_t* _a23_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a23_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a23_slotarr, l5)
            t0 = vader_array_ref_load_obj(_a23_slotarr->buf, _a23_slotarr->offset + (size_t) l5);
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
                vader_obj_header_init(_a24_obj, 838u);
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
                    vader_obj_header_init(_a25_obj, 972u);
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
        if (l1.tag == 1456u) {
            l3 = ((vader_struct_vader_midir$CFGFunction_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_fn_)->f_locals;
            t0 = l1.payload.obj;
            l5 = ((int64_t) (int32_t) ((vader_struct_vader_midir$InstrArraySet_t*) t0)->f_target);
            vader_array_t* _a26_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a26_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a26_slotarr, l5)
            t0 = vader_array_ref_load_obj(_a26_slotarr->buf, _a26_slotarr->offset + (size_t) l5);
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
                vader_obj_header_init(_a27_obj, 845u);
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
        if (l1.tag == 1453u) {
            t0 = l1.payload.obj;
            l4 = ((vader_struct_vader_midir$InstrArrayLen_t*) t0)->f_target;
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir$InstrArrayLen_t*) t0)->f_span;
            vader_emit_bytecode$emit_first_get(l0, l2, l4, l3);
            t0 = (void*) &vader_data_67;
            vader_array_t* _a28_slotarr = ((vader_array_t*) t0);
            VADER_ARRAY_RESOLVE_BUF(_a28_slotarr)
            l3 = vader_array_ref_load_obj(_a28_slotarr->buf, _a28_slotarr->offset + (size_t) INT64_C(0));
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
        if (l1.tag == 1455u) {
            l3 = ((vader_struct_vader_midir$CFGFunction_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_fn_)->f_locals;
            t0 = l1.payload.obj;
            l5 = ((int64_t) (int32_t) ((vader_struct_vader_midir$InstrArrayPush_t*) t0)->f_target);
            vader_array_t* _a29_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a29_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a29_slotarr, l5)
            t0 = vader_array_ref_load_obj(_a29_slotarr->buf, _a29_slotarr->offset + (size_t) l5);
            l7 = ((vader_struct_vader_midir$CFGLocal_t*) t0)->f_type;
            l3 = ((vader_struct_vader_midir$CFGFunction_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_fn_)->f_locals;
            t0 = l1.payload.obj;
            l5 = ((int64_t) (int32_t) ((vader_struct_vader_midir$InstrArrayPush_t*) t0)->f_value);
            vader_array_t* _a30_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a30_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a30_slotarr, l5)
            t0 = vader_array_ref_load_obj(_a30_slotarr->buf, _a30_slotarr->offset + (size_t) l5);
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
                l4 = ((int32_t*) _a31_slotarr->buf->slots)[_a31_slotarr->offset + (size_t) l5];
            } else {
                l4 = INT32_C(-1);
            }
            l3 = ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_project;
            t3 = vader_emit_bytecode$intern_type(l7, l3);
            vader_struct_vader_core_bytecode$ArrayPush_t* _a32_obj = (vader_struct_vader_core_bytecode$ArrayPush_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$ArrayPush_t));
            vader_obj_header_init(_a32_obj, 841u);
            _a32_obj->f_type_id = t3;
            _a32_obj->f_cache_slot = l4;
            l3 = (void*) _a32_obj;
            t0 = l1.payload.obj;
            l12 = ((vader_struct_vader_midir$InstrArrayPush_t*) t0)->f_span;
            vader_emit_bytecode$push_emit(l0, vader_ref_box(l3), l12);
            { vader_gc_top = gc_frame.prev; return; }
        }
        if (l1.tag == 1457u) {
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
            vader_obj_header_init(_a33_obj, 846u);
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
        if (l1.tag == 1478u) {
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
            vader_obj_header_init(_a34_obj, 991u);
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
        if (l1.tag == 1454u) {
            t0 = l1.payload.obj;
            l7 = ((vader_struct_vader_midir$InstrArrayNew_t*) t0)->f_type;
            l3 = ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_project;
            l4 = vader_emit_bytecode$intern_type(l7, l3);
            t0 = l1.payload.obj;
            t1 = vader_emit_bytecode$boxed_element(((vader_struct_vader_midir$InstrArrayNew_t*) t0)->f_type);
            vader_array_t* _a35_arr = vader_array_new(20u, 1u, 12u, 445u);
            ((uint8_t*) _a35_arr->buf->slots)[_a35_arr->offset + 0u] = (uint8_t) t1;
            l3 = (void*) _a35_arr;
            t0 = l1.payload.obj;
            l5 = ((vader_array_t*) ((vader_struct_vader_midir$InstrArrayNew_t*) t0)->f_elements)->length;
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
            vader_obj_header_init(_a37_obj, 840u);
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
        if (l1.tag == 1466u) {
            t0 = l1.payload.obj;
            l7 = ((vader_struct_vader_midir$InstrDataConst_t*) t0)->f_type;
            l3 = ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_project;
            l4 = vader_emit_bytecode$intern_type(l7, l3);
            t0 = l1.payload.obj;
            t3 = ((vader_struct_vader_midir$InstrDataConst_t*) t0)->f_pool_index;
            vader_struct_vader_core_bytecode$DataConst_t* _a38_obj = (vader_struct_vader_core_bytecode$DataConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$DataConst_t));
            vader_obj_header_init(_a38_obj, 890u);
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
        if (l1.tag == 1473u) {
            t0 = l1.payload.obj;
            t3 = ((vader_struct_vader_midir$InstrGlobalGet_t*) t0)->f_slot;
            vader_struct_vader_core_bytecode$GlobalGet_t* _a39_obj = (vader_struct_vader_core_bytecode$GlobalGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$GlobalGet_t));
            vader_obj_header_init(_a39_obj, 913u);
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
        if (l1.tag == 1474u) {
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
            vader_obj_header_init(_a40_obj, 914u);
            _a40_obj->f_index = t3;
            l3 = (void*) _a40_obj;
            t0 = l1.payload.obj;
            l12 = ((vader_struct_vader_midir$InstrGlobalSet_t*) t0)->f_span;
            vader_emit_bytecode$push_emit(l0, vader_ref_box(l3), l12);
            { vader_gc_top = gc_frame.prev; return; }
        }
        if (l1.tag == 1479u) {
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
            vader_obj_header_init(_a41_obj, 993u);
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
        if (l1.tag == 1480u) {
            t0 = l1.payload.obj;
            l7 = ((vader_struct_vader_midir$InstrTypeConst_t*) t0)->f_value_type;
            l3 = ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_project;
            t3 = vader_emit_bytecode$intern_type(l7, l3);
            vader_struct_vader_core_bytecode$TypeConst_t* _a42_obj = (vader_struct_vader_core_bytecode$TypeConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$TypeConst_t));
            vader_obj_header_init(_a42_obj, 994u);
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
        if (l1.tag == 1461u) {
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
            t0 = vader_array_ref_load_obj(_a43_slotarr->buf, _a43_slotarr->offset + (size_t) l5);
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
                vader_obj_header_init(_a44_obj, 975u);
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
                    vader_obj_header_init(_a45_obj, 972u);
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
                        vader_obj_header_init(_a46_obj, 889u);
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
                        vader_obj_header_init(_a47_obj, 972u);
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
        if (l1.tag == 1463u) {
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
            vader_obj_header_init(_a48_obj, 991u);
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
        if (l1.tag == 1462u) {
            t0 = l1.payload.obj;
            l7 = ((vader_struct_vader_midir$InstrCellGet_t*) t0)->f_value_type;
            l3 = ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_project;
            l4 = vader_emit_bytecode$intern_cell_type(l7, l3);
            l6 = std_collections$MutableSet$std_core$Contains$contains__i64(((vader_struct_vader_emit_bytecode$ScheduleHints_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_hints)->f_skip_first_get, l2);
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
                vader_obj_header_init(_a49_obj, 990u);
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
        if (l1.tag == 1464u) {
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
            vader_obj_header_init(_a50_obj, 992u);
            _a50_obj->f_type_id = l4;
            _a50_obj->f_field_index = INT32_C(0);
            _a50_obj->f_stack = false;
            l3 = (void*) _a50_obj;
            t0 = l1.payload.obj;
            l12 = ((vader_struct_vader_midir$InstrCellSet_t*) t0)->f_span;
            vader_emit_bytecode$push_emit(l0, vader_ref_box(l3), l12);
            { vader_gc_top = gc_frame.prev; return; }
        }
        if (l1.tag == 1476u) {
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
            if (!(l7.tag == 450u)) {
                t0 = l1.payload.obj;
                l18 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_midir$InstrMakeClosure_t*) t0)->f_fn_symbol)->f_name;
                l5 = vader_host_std_core$byte_len(l18);
                l14 = (void*) vader_buffer_new((size_t) (INT64_C(106) + l5));
                l5 = INT64_C(0);
                l5 = std_core$write_string_at(l14, l5, 1866u);
                l5 = std_core$write_string_at(l14, l5, l18);
                l5 = std_core$write_string_at(l14, l5, 290u);
                t0 = l1.payload.obj;
                t3 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_midir$InstrMakeClosure_t*) t0)->f_fn_symbol)->f_id;
                l13 = ((int64_t) (int32_t) t3);
                l5 = std_core$write_int(l14, l5, l13);
                l5 = std_core$write_string_at(l14, l5, 329u);
                t4 = std_core$finish_buffer(l14, l5);
                vader_host_std_abort$panic(t4);
                vader_unreachable("a no-return call returned");
            }
            t3 = ((int32_t) l7.payload.i);
            vader_struct_vader_core_bytecode$MakeClosure_t* _a51_obj = (vader_struct_vader_core_bytecode$MakeClosure_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$MakeClosure_t));
            vader_obj_header_init(_a51_obj, 969u);
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
        if (l1.tag == 1475u) {
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir$InstrIntrinsic_t*) t0)->f_args;
            vader_array_t* _a52_arr = vader_array_new(20u, 0u, 12u, 445u);
            l12 = (void*) _a52_arr;
            t0 = l1.payload.obj;
            l14 = ((vader_struct_vader_midir$InstrIntrinsic_t*) t0)->f_span;
            vader_emit_bytecode$emit_operands_into(l0, l2, l3, l12, l14);
            t0 = l1.payload.obj;
            t4 = ((vader_struct_vader_midir$InstrIntrinsic_t*) t0)->f_name;
            l7 = vader_midir_select$intrinsic_op_for_name(t4);
            if (!(l7.tag == 0u)) {
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
            t0 = l1.payload.obj;
            l18 = ((vader_struct_vader_midir$InstrIntrinsic_t*) t0)->f_name;
            l19 = ((vader_struct_vader_midir$CFGFunction_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_fn_)->f_mangled;
            t4 = concat_5(1864u, l18, 1123u, l19, 303u);
            vader_host_std_abort$panic(t4);
            vader_unreachable("a no-return call returned");
        } else {
            if (l1.tag == 1468u) {
                t0 = l1.payload.obj;
                l4 = ((vader_struct_vader_midir$InstrDeferPush_t*) t0)->f_value;
                t0 = l1.payload.obj;
                l3 = ((vader_struct_vader_midir$InstrDeferPush_t*) t0)->f_span;
                vader_emit_bytecode$emit_first_get(l0, l2, l4, l3);
                t0 = (void*) &vader_data_68;
                vader_array_t* _a53_slotarr = ((vader_array_t*) t0);
                VADER_ARRAY_RESOLVE_BUF(_a53_slotarr)
                l3 = vader_array_ref_load_obj(_a53_slotarr->buf, _a53_slotarr->offset + (size_t) INT64_C(0));
                t0 = l1.payload.obj;
                l12 = ((vader_struct_vader_midir$InstrDeferPush_t*) t0)->f_span;
                vader_emit_bytecode$push_emit(l0, vader_ref_box(l3), l12);
                { vader_gc_top = gc_frame.prev; return; }
            }
            if (!(l1.tag == 1467u)) {
                vader_host_std_abort$panic(1863u);
                vader_unreachable("a no-return call returned");
            }
            t0 = l1.payload.obj;
            t3 = ((vader_struct_vader_midir$InstrDeferPopExec_t*) t0)->f_count;
            vader_struct_vader_core_bytecode$DeferPopExec_t* _a54_obj = (vader_struct_vader_core_bytecode$DeferPopExec_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$DeferPopExec_t));
            vader_obj_header_init(_a54_obj, 892u);
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
    l4 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
    l6 = l2;
    while ((l6 < l3)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_midir$BasicBlock_t*) l4)->f_instructions);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l6)
        l7 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l6);
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
    l4 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
    l5 = vader_emit_bytecode$open_blocks(l0, l4, l3);
    l6 = ((vader_struct_vader_midir$CFGFunction_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_fn_)->f_blocks;
    l7 = l2;
    vader_array_t* _a1_slotarr = ((vader_array_t*) l6);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l7)
    t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l7);
    l6 = ((vader_struct_vader_midir$BasicBlock_t*) t0)->f_span;
    l8 = ((vader_struct_vader_emit_bytecode$StructureShape_t*) l1)->f_merges;
    l9 = l2;
    vader_array_t* _a2_slotarr = ((vader_array_t*) l8);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l9)
    t0 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l9);
    t1 = ((vader_array_t*) t0)->length;
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
    vader_obj_header_init(_a0_obj, 920u);
    _a0_obj->f_value = l4;
    l5 = (void*) _a0_obj;
    vader_emit_bytecode$push_emit(l0, vader_ref_box(l5), l2);
    t0 = (void*) &vader_data_70;
    vader_array_t* _a1_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    l5 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) INT64_C(0));
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
    vader_obj_header_init(_a2_obj, 920u);
    _a2_obj->f_value = l4;
    l5 = (void*) _a2_obj;
    vader_emit_bytecode$push_emit(l0, vader_ref_box(l5), l2);
    t0 = (void*) &vader_data_71;
    vader_array_t* _a3_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
    l5 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) INT64_C(0));
    vader_emit_bytecode$push_emit(l0, vader_ref_box(l5), l2);
    vader_struct_vader_core_bytecode$I32Const_t* _a4_obj = (vader_struct_vader_core_bytecode$I32Const_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$I32Const_t));
    vader_obj_header_init(_a4_obj, 920u);
    _a4_obj->f_value = l4;
    l5 = (void*) _a4_obj;
    vader_emit_bytecode$push_emit(l0, vader_ref_box(l5), l2);
    t0 = (void*) &vader_data_72;
    vader_array_t* _a5_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
    l5 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) INT64_C(0));
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
    l6 = ((vader_array_t*) l2)->length;
    while ((l5 < l6)) {
        if (l5 == INT64_C(0)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            l7 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l5];
            vader_emit_bytecode$emit_first_get(l0, l1, l7, l4);
        } else {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            l8 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l5];
            vader_emit_bytecode$emit_get(l0, l8, l4);
        }
        vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        l9 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l5];
        l10 = ((vader_array_t*) l3)->length;
        if ((l5 < l10)) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            t0 = ((uint8_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l5];
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
    t0 = std_collections$MutableSet$std_core$Contains$contains__i64(((vader_struct_vader_emit_bytecode$ScheduleHints_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_hints)->f_skip_set, l1);
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
    t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
    l6 = ((vader_struct_vader_midir$CFGLocal_t*) t0)->f_type;
    t1 = vader_midir_select$val_type_of_type(l6);
    t2 = vader_midir_select$is_scalar_class(t1);
    if (t2) {
        l4 = ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_project;
        t3 = vader_emit_bytecode$intern_type(l6, l4);
        vader_struct_vader_core_bytecode$Retag_t* _a1_obj = (vader_struct_vader_core_bytecode$Retag_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$Retag_t));
        vader_obj_header_init(_a1_obj, 975u);
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
    l5 = ((vader_array_t*) ((vader_struct_vader_midir$TermReturn_t*) l2)->f_values)->length;
    while ((l4 < l5)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_midir$TermReturn_t*) l2)->f_values);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        l6 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l4];
        if (!(l3.tag == 0u)) {
            l7 = std_collections$MutableSet$std_core$Contains$contains__i32(((vader_struct_vader_emit_bytecode$ScheduleHints_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_hints)->f_skip_terminator_get, l1);
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
    t0 = ((vader_array_t*) l8)->length;
    if ((t0 > INT64_C(0))) {
        if (!(l3.tag == 0u)) {
            t0 = ((vader_array_t*) l8)->length;
            l4 = vader_chk_sub(i64, t0, INT64_C(1));
            vader_array_t* _a1_slotarr = ((vader_array_t*) l8);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            t1 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
            l3 = vader_core_bytecode$const_op_of(t1);
            if (!(l3.tag == 0u)) {
                t0 = ((vader_array_t*) l8)->length;
                l4 = vader_chk_sub(i64, t0, INT64_C(1));
                vader_struct_vader_core_bytecode$ReturnLit_t* _a2_obj = (vader_struct_vader_core_bytecode$ReturnLit_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$ReturnLit_t));
                vader_obj_header_init(_a2_obj, 977u);
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
    t2 = (void*) &vader_data_62;
    vader_array_t* _a4_slotarr = ((vader_array_t*) t2);
    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
    l8 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) INT64_C(0));
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
    t0 = ((vader_array_t*) ((vader_struct_vader_midir$CFGFunction_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_fn_)->f_scalarised_results)->length;
    if ((t0 > l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_midir$CFGFunction_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_fn_)->f_scalarised_results);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
        t1 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
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
    t0 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l4];
    vader_struct_vader_core_bytecode$LocalSet_t* _a1_obj = (vader_struct_vader_core_bytecode$LocalSet_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$LocalSet_t));
    vader_obj_header_init(_a1_obj, 966u);
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
    t0 = ((uint8_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l5];
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
    t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l6);
    l7 = ((vader_struct_vader_midir$BasicBlock_t*) t0)->f_terminator;
    if (l7.tag == 1496u) {
        l5 = l7.payload.obj;
        vader_emit_bytecode$emit_return(l0, l2, l5);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l7.tag == 1497u) {
        t0 = l7.payload.obj;
        t1 = ((vader_struct_vader_midir$TermUnreachable_t*) t0)->f_reason;
        vader_struct_vader_core_bytecode$Unreachable_t* _a1_obj = (vader_struct_vader_core_bytecode$Unreachable_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$Unreachable_t));
        vader_obj_header_init(_a1_obj, 1009u);
        _a1_obj->f_reason = t1;
        l5 = (void*) _a1_obj;
        t0 = l7.payload.obj;
        l8 = ((vader_struct_vader_midir$TermUnreachable_t*) t0)->f_span;
        vader_emit_bytecode$push_emit(l0, vader_ref_box(l5), l8);
    } else if (l7.tag == 1494u) {
        t0 = l7.payload.obj;
        l6 = ((vader_struct_vader_midir$TermBranch_t*) t0)->f_target;
        t0 = l7.payload.obj;
        l5 = ((vader_struct_vader_midir$TermBranch_t*) t0)->f_span;
        vader_emit_bytecode$emit_branch(l0, l1, l2, l6, l3, l5);
    } else {
        if (!(l7.tag == 1495u)) {
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
                t1 = vader_midir$dominates(l2, l12, l13);
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

static bool vader_emit_bytecode$ends_function(vader_box_t l0) {
    return (l0.tag == 1496u || l0.tag == 1497u);
}

static bool vader_emit_bytecode$entered_by_test(void* l0, void* l1, int32_t l2) {
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
    vader_array_t* _a0_arr = vader_array_new(20u, 1u, 12u, 445u);
    ((uint8_t*) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = (uint8_t) true;
    l1 = (void*) _a0_arr;
    l2 = ((vader_array_t*) l0)->length;
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
        t0 = ((uint8_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l5];
        t1 = t0;
        if (t1) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
            l6 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5);
            l7 = l3;
            l8 = ((vader_array_t*) l7)->length;
            l9 = INT64_C(0);
            while ((l9 < l8)) {
                vader_array_t* _a2_slotarr = ((vader_array_t*) l7);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                l10 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l9);
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
                            vader_obj_header_init(_a3_obj, 1051u);
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
                            vader_obj_header_init(_a4_obj, 1051u);
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
            vader_array_ref_store(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l5, l6);
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
    vader_array_t* _a0_arr = vader_array_new(193u, 0u, 13u, 1051u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(22u, 0u, 0u, 447u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(23u, 0u, 7u, 450u);
    l3 = (void*) _a2_arr;
    l4 = INT64_C(0);
    l5 = ((vader_array_t*) l0)->length;
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        l7 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l6);
        if (l7.tag == 869u) {
            l8 = ((int32_t) (int64_t) l6);
            vader_emit_bytecode$push_scope(l2, l3, l4, 1631u, l8);
            l4 = vader_chk_add(i64, l4, INT64_C(1));
        } else if (l7.tag == 968u) {
            l9 = ((int32_t) (int64_t) l6);
            vader_emit_bytecode$push_scope(l2, l3, l4, 2291u, l9);
            l4 = vader_chk_add(i64, l4, INT64_C(1));
        } else if (l7.tag == 955u) {
            l10 = ((int32_t) (int64_t) l6);
            vader_emit_bytecode$push_scope(l2, l3, l4, 2129u, l10);
            l4 = vader_chk_add(i64, l4, INT64_C(1));
        } else if (l7.tag == 896u) {
            if ((l4 > INT64_C(0))) {
                l4 = vader_chk_sub(i64, l4, INT64_C(1));
                vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
                VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l4)
                t0 = vader_array_box_slots(_a4_slotarr->buf)[_a4_slotarr->offset + (size_t) l4];
                t1 = t0.payload.s;
                if (t1 == 2291u) {
                    vader_array_t* _a5_slotarr = ((vader_array_t*) l3);
                    VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l4)
                    l11 = ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l4];
                    l12 = ((int32_t) (int64_t) l6);
                    vader_struct_vader_emit_bytecode$SlotRange_t* _a6_obj = (vader_struct_vader_emit_bytecode$SlotRange_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_bytecode$SlotRange_t));
                    vader_obj_header_init(_a6_obj, 1051u);
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
    l3 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l1);
    if (l3.tag == 861u) {
        l4 = INT64_C(0);
        t0 = l3.payload.obj;
        l5 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcStruct_t*) t0)->f_fields)->length;
        while ((l4 < l5)) {
            t0 = l3.payload.obj;
            vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcStruct_t*) t0)->f_fields);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
            t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
            t1 = ((vader_struct_vader_core_bytecode$BcField_t*) t0)->f_name;
            if (t1 == l2) {
                return vader_box_i64(451u, l4);
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
    if (l0.tag == 1465u) {
        return vader_box_obj(0u, NULL);
    }
    if (l0.tag == 1472u) {
        return vader_box_obj(0u, NULL);
    }
    if (l0.tag == 1471u) {
        return vader_box_obj(0u, NULL);
    }
    if (l0.tag == 1466u) {
        return vader_box_obj(0u, NULL);
    }
    if (l0.tag == 1473u) {
        return vader_box_obj(0u, NULL);
    }
    if (l0.tag == 1480u) {
        return vader_box_obj(0u, NULL);
    }
    if (l0.tag == 1477u) {
        t0 = l0.payload.obj;
        return vader_box_i32(450u, ((vader_struct_vader_midir$InstrMove_t*) t0)->f_src);
    }
    if (l0.tag == 1458u) {
        t0 = l0.payload.obj;
        return vader_box_i32(450u, ((vader_struct_vader_midir$InstrBinOp_t*) t0)->f_lhs);
    }
    if (l0.tag == 1481u) {
        t0 = l0.payload.obj;
        return vader_box_i32(450u, ((vader_struct_vader_midir$InstrUnOp_t*) t0)->f_operand);
    }
    if (l0.tag == 1459u) {
        t0 = l0.payload.obj;
        t1 = std_iter$first_or_null__i32(((vader_struct_vader_midir$InstrCall_t*) t0)->f_args);
        return t1;
    }
    if (l0.tag == 1460u) {
        t0 = l0.payload.obj;
        l1 = std_iter$first_or_null__i32(((vader_struct_vader_midir$InstrCallIndirect_t*) t0)->f_args);
        if (l1.tag == 0u) {
            t0 = l0.payload.obj;
            return vader_box_i32(450u, ((vader_struct_vader_midir$InstrCallIndirect_t*) t0)->f_callee);
        }
        t2 = ((int32_t) l1.payload.i);
        return vader_box_i32(450u, t2);
    }
    if (l0.tag == 1484u) {
        t0 = l0.payload.obj;
        l1 = std_iter$first_or_null__i32(((vader_struct_vader_midir$InstrVirtualCall_t*) t0)->f_args);
        if (l1.tag == 0u) {
            t0 = l0.payload.obj;
            return vader_box_i32(450u, ((vader_struct_vader_midir$InstrVirtualCall_t*) t0)->f_receiver);
        }
        t2 = ((int32_t) l1.payload.i);
        return vader_box_i32(450u, t2);
    }
    if (l0.tag == 1469u) {
        t0 = l0.payload.obj;
        return vader_box_i32(450u, ((vader_struct_vader_midir$InstrFieldGet_t*) t0)->f_target);
    }
    if (l0.tag == 1470u) {
        t0 = l0.payload.obj;
        return vader_box_i32(450u, ((vader_struct_vader_midir$InstrFieldSet_t*) t0)->f_target);
    }
    if (l0.tag == 1482u) {
        t0 = l0.payload.obj;
        return vader_box_i32(450u, ((vader_struct_vader_midir$InstrUnionFieldGet_t*) t0)->f_target);
    }
    if (l0.tag == 1483u) {
        t0 = l0.payload.obj;
        return vader_box_i32(450u, ((vader_struct_vader_midir$InstrUnionFieldSet_t*) t0)->f_target);
    }
    if (l0.tag == 1452u) {
        t0 = l0.payload.obj;
        return vader_box_i32(450u, ((vader_struct_vader_midir$InstrArrayGet_t*) t0)->f_target);
    }
    if (l0.tag == 1456u) {
        t0 = l0.payload.obj;
        return vader_box_i32(450u, ((vader_struct_vader_midir$InstrArraySet_t*) t0)->f_target);
    }
    if (l0.tag == 1453u) {
        t0 = l0.payload.obj;
        return vader_box_i32(450u, ((vader_struct_vader_midir$InstrArrayLen_t*) t0)->f_target);
    }
    if (l0.tag == 1455u) {
        t0 = l0.payload.obj;
        return vader_box_i32(450u, ((vader_struct_vader_midir$InstrArrayPush_t*) t0)->f_target);
    }
    if (l0.tag == 1457u) {
        t0 = l0.payload.obj;
        return vader_box_i32(450u, ((vader_struct_vader_midir$InstrArraySlice_t*) t0)->f_target);
    }
    if (l0.tag == 1478u) {
        t0 = l0.payload.obj;
        t1 = std_iter$first_or_null__i32(((vader_struct_vader_midir$InstrStructNew_t*) t0)->f_fields);
        return t1;
    }
    if (l0.tag == 1454u) {
        t0 = l0.payload.obj;
        t1 = std_iter$first_or_null__i32(((vader_struct_vader_midir$InstrArrayNew_t*) t0)->f_elements);
        return t1;
    }
    if (l0.tag == 1479u) {
        t0 = l0.payload.obj;
        return vader_box_i32(450u, ((vader_struct_vader_midir$InstrTypeCheck_t*) t0)->f_value);
    }
    if (l0.tag == 1461u) {
        t0 = l0.payload.obj;
        return vader_box_i32(450u, ((vader_struct_vader_midir$InstrCast_t*) t0)->f_value);
    }
    if (l0.tag == 1463u) {
        t0 = l0.payload.obj;
        return vader_box_i32(450u, ((vader_struct_vader_midir$InstrCellNew_t*) t0)->f_value);
    }
    if (l0.tag == 1462u) {
        t0 = l0.payload.obj;
        return vader_box_i32(450u, ((vader_struct_vader_midir$InstrCellGet_t*) t0)->f_cell);
    }
    if (l0.tag == 1464u) {
        t0 = l0.payload.obj;
        return vader_box_i32(450u, ((vader_struct_vader_midir$InstrCellSet_t*) t0)->f_cell);
    }
    if (l0.tag == 1474u) {
        t0 = l0.payload.obj;
        return vader_box_i32(450u, ((vader_struct_vader_midir$InstrGlobalSet_t*) t0)->f_value);
    }
    if (l0.tag == 1476u) {
        t0 = l0.payload.obj;
        return vader_box_i32(450u, ((vader_struct_vader_midir$InstrMakeClosure_t*) t0)->f_env);
    }
    if (l0.tag == 1475u) {
        t0 = l0.payload.obj;
        t1 = std_iter$first_or_null__i32(((vader_struct_vader_midir$InstrIntrinsic_t*) t0)->f_args);
        return t1;
    }
    if (l0.tag == 1468u) {
        t0 = l0.payload.obj;
        return vader_box_i32(450u, ((vader_struct_vader_midir$InstrDeferPush_t*) t0)->f_value);
    }
    if (!(l0.tag == 1467u)) {
        vader_unreachable("non-exhaustive match (T3013 should have caught this)");
    }
    return vader_box_obj(0u, NULL);
}

static vader_box_t vader_emit_bytecode$first_terminator_operand(vader_box_t l0) {
    void* t0;
    vader_box_t t1;
    if (l0.tag == 1494u) {
        return vader_box_obj(0u, NULL);
    }
    if (l0.tag == 1497u) {
        return vader_box_obj(0u, NULL);
    }
    if (l0.tag == 1495u) {
        t0 = l0.payload.obj;
        return vader_box_i32(450u, ((vader_struct_vader_midir$TermCondBranch_t*) t0)->f_cond);
    }
    if (!(l0.tag == 1496u)) {
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
    t1 = ((uint8_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l4];
    t2 = t1;
    if (t2) {
        return false;
    }
    vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l1)
    l5 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l1);
    if (l5.tag == 965u) {
        l4 = vader_chk_add(i64, l1, INT64_C(1));
        vader_array_t* _a2_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        l6 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
        if (l6.tag == 967u) {
            t3 = l6.payload.obj;
            l7 = ((vader_struct_vader_core_bytecode$LocalTee_t*) t3)->f_slot;
            t3 = l5.payload.obj;
            l8 = ((vader_struct_vader_core_bytecode$LocalGet_t*) t3)->f_slot;
            return l7 == l8;
        }
        if (l6.tag == 966u) {
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
    l7 = ((vader_struct_std_collections$MutableMap__i32__std_collections_MutableSet_i32__t*) l6)->f_ekeys;
    l8 = ((vader_struct_std_collections$MutableMap__i32__std_collections_MutableSet_i32__t*) l6)->f_evals;
    l9 = INT64_C(0);
    l10 = ((vader_struct_std_collections$MutableMap__i32__std_collections_MutableSet_i32__t*) l6)->f_size;
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
    l16 = std_collections$MutableMap$std_core$Index$at__i32__Any(l1, l4);
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
    t2 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
    l16 = ((vader_struct_vader_midir$BasicBlock_t*) t2)->f_terminator;
    if (l16.tag == 1495u) {
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
        t0 = std_collections$MutableSet$std_core$Contains$contains__i32(l6, l3);
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
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
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
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l5 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l4];
        t0 = std_collections$MutableSet$std_core$Contains$contains__i32(l0, l5);
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
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_imports);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    l2 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l1);
    t0 = ((vader_struct_vader_core_bytecode$BcImport_t*) l2)->f_is_extern;
    if (t0) {
        l3 = vader_box_obj(0u, NULL);
    } else {
        t1 = ((vader_struct_vader_core_bytecode$BcImport_t*) l2)->f_mangled_name;
        l3 = vader_midir_select$intrinsic_op_for_mangled(t1);
    }
    if (l3.tag == 0u) {
        vader_struct_vader_core_bytecode$CallImport_t* _a1_obj = (vader_struct_vader_core_bytecode$CallImport_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$CallImport_t));
        vader_obj_header_init(_a1_obj, 884u);
        _a1_obj->f_index = l1;
        t2 = (void*) _a1_obj;
        l4 = vader_ref_box(t2);
        l5 = ((vader_struct_vader_core_bytecode$BcImport_t*) l2)->f_signature;
        vader_struct_vader_emit_bytecode$DirectCallTarget_t* _a2_obj = (vader_struct_vader_emit_bytecode$DirectCallTarget_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_bytecode$DirectCallTarget_t));
        vader_obj_header_init(_a2_obj, 1044u);
        _a2_obj->f_op = l4;
        _a2_obj->f_signature = l5;
        t2 = (void*) _a2_obj;
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = l3;
    l5 = ((vader_struct_vader_core_bytecode$BcImport_t*) l2)->f_signature;
    vader_struct_vader_emit_bytecode$DirectCallTarget_t* _a3_obj = (vader_struct_vader_emit_bytecode$DirectCallTarget_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_bytecode$DirectCallTarget_t));
    vader_obj_header_init(_a3_obj, 1044u);
    _a3_obj->f_op = l4;
    _a3_obj->f_signature = l5;
    t2 = (void*) _a3_obj;
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static int32_t vader_emit_bytecode$intern_cell_type(vader_box_t l0, void* l1) {
    int32_t l2, l5, l6;
    vader_string_t l3 = 0;
    vader_string_t l4 = 0;
    void* l7 = NULL;
    void* l8 = NULL;
    int64_t t0;
    vader_string_t t1 = 0;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[3] = { &l1, &l7, &l8 };
    vader_string_t* gc_atom_roots[3] = { &l3, &l4, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_emit_bytecode$intern_type(l0, l1);
    l3 = vader_midir_select$type_intern_key(l0);
    l4 = concat_3(262u, l3, 526u);
    t0 = ((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l1)->f_types)->length;
    l5 = ((int32_t) (int64_t) t0);
    l6 = std_collections$get_or_put__string__i32(((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l1)->f_type_key, l4, l5);
    if (!(l6 != l5)) {
        vader_struct_vader_core_bytecode$BcField_t* _a0_obj = (vader_struct_vader_core_bytecode$BcField_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcField_t));
        vader_obj_header_init(_a0_obj, 850u);
        _a0_obj->f_name = 2984u;
        _a0_obj->f_type_index = l2;
        l7 = (void*) _a0_obj;
        vader_array_t* _a1_arr = vader_array_new(69u, 0u, 13u, 850u);
        l8 = (void*) _a1_arr;
        vader_array_push_ref((vader_array_t*) l8, l7);
        l7 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l1)->f_types;
        l3 = vader_midir_select$cell_shape_name(l3);
        t1 = concat_2(263u, l3);
        vader_struct_vader_core_bytecode$BcStruct_t* _a2_obj = (vader_struct_vader_core_bytecode$BcStruct_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcStruct_t));
        vader_obj_header_init(_a2_obj, 861u);
        _a2_obj->f_name = t1;
        _a2_obj->f_fields = l8;
        _a2_obj->f_c_name = 0u;
        _a2_obj->f_symbol_id = INT32_C(-1);
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
    t0 = ((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l1)->f_strings)->length;
    l2 = ((int32_t) (int64_t) t0);
    l3 = std_collections$get_or_put__string__i32(((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l1)->f_string_key, l0, l2);
    if (l3 == l2) {
        vader_array_push_scalar((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l1)->f_strings, vader_box_string(447u, l0));
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
    l3 = std_collections$MutableMap$std_core$Index$at__u64__i32(((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l1)->f_type_hash, l2);
    if (l3.tag == 450u) {
        t0 = ((int32_t) l3.payload.i);
        l4 = ((int64_t) (int32_t) t0);
        if ((INT64_C(0) <= l4)) {
            l6 = ((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l1)->f_type_by_slot)->length;
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
            l9 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l8);
            t1 = vader_midir_select$same_intern_class(l0, l9);
            if (t1) {
                t0 = ((int32_t) l3.payload.i);
                { int32_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
            }
        }
    }
    l10 = vader_midir_select$type_intern_key(l0);
    t2 = ((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l1)->f_types)->length;
    l8 = ((int32_t) (int64_t) t2);
    l11 = std_collections$get_or_put__string__i32(((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l1)->f_type_key, l10, l8);
    if (l11 != l8) {
        if (l3.tag == 0u) {
            std_collections$MutableMap$std_core$IndexSet$set_at__u64__i32(((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l1)->f_type_hash, l2, l11);
            vader_emit_bytecode$record_slot_type(l1, l11, l0);
            { int32_t __vret = l11; vader_gc_top = gc_frame.prev; return __vret; }
        }
        { int32_t __vret = l11; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l1)->f_types_frozen;
    if (t1) {
        t3 = concat_3(1869u, l10, 1047u);
        vader_host_std_abort$panic(t3);
        vader_unreachable("a no-return call returned");
    } else {
        vader_struct_vader_core_bytecode$BcRef_t* _a1_obj = (vader_struct_vader_core_bytecode$BcRef_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcRef_t));
        vader_obj_header_init(_a1_obj, 857u);
        _a1_obj->f_trait_name = 0u;
        t4 = (void*) _a1_obj;
        l9 = vader_ref_box(t4);
        vader_array_push_ref((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l1)->f_types, l9.payload.obj);
        if (l3.tag == 0u) {
            std_collections$MutableMap$std_core$IndexSet$set_at__u64__i32(((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l1)->f_type_hash, l2, l8);
        }
        vader_emit_bytecode$record_slot_type(l1, l8, l0);
        l7 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l1)->f_types;
        l3 = vader_emit_bytecode$bc_type_of_with_ctx(l0, l1);
        vader_array_t* _a2_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l8)
        vader_array_ref_store(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l8, l3.payload.obj);
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
    t0 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l1);
    return (t0.tag == 857u || t0.tag == 862u);
}

static bool vader_emit_bytecode$is_union_slot(vader_box_t l0) {
    bool l1;
    void* t0;
    if (l0.tag == 1041u) {
        return true;
    }
    if (l0.tag == 1020u) {
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
    t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
    l4 = ((vader_array_t*) ((vader_struct_vader_midir$BasicBlock_t*) t0)->f_instructions)->length;
    while ((l4 > INT64_C(0))) {
        l2 = ((vader_struct_vader_emit_bytecode$ScheduleHints_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_hints)->f_skip_set;
        l5 = vader_chk_sub(i64, l4, INT64_C(1));
        l6 = vader_midir$pos_key(l1, l5);
        t1 = std_collections$MutableSet$std_core$Contains$contains__i64(l2, l6);
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
    t0 = ((vader_array_t*) l1)->length;
    if (!(t0 == INT64_C(0))) {
        t0 = ((vader_array_t*) l1)->length;
        l2 = vader_chk_sub(i64, t0, INT64_C(1));
        vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
        t1 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
        return (t1.tag == 876u || t1.tag == 976u || t1.tag == 977u);
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
    t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l6);
    t1 = vader_emit_bytecode$ends_function(((vader_struct_vader_midir$BasicBlock_t*) t0)->f_terminator);
    if (t1) {
        l5 = ((vader_struct_vader_emit_bytecode$StructureShape_t*) l1)->f_copied;
        l6 = l3;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l6)
        t1 = ((uint8_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l6];
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
    l3 = std_collections$MutableMap$std_core$Index$at__i32__Any(l0, l1);
    if (l3.tag == 0u) {
        return false;
    }
    t0 = l3.payload.obj;
    t1 = std_collections$MutableSet$std_core$Contains$contains__i32(t0, l2);
    return !(t1);
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
    t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
    l5 = ((vader_struct_vader_midir$BasicBlock_t*) t0)->f_terminator;
    if (!(l5.tag == 1495u)) {
        { vader_gc_top = gc_frame.prev; return INT32_C(-1); }
    }
    t0 = l5.payload.obj;
    l4 = ((vader_struct_vader_midir$TermCondBranch_t*) t0)->f_else_block;
    t0 = l5.payload.obj;
    l6 = ((vader_struct_vader_midir$TermCondBranch_t*) t0)->f_then_block;
    vader_array_t* _a1_arr = vader_array_new(23u, 2u, 7u, 450u);
    ((int32_t*) _a1_arr->buf->slots)[_a1_arr->offset + 1u] = (int32_t) l6;
    ((int32_t*) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = (int32_t) l4;
    l3 = (void*) _a1_arr;
    l7 = ((vader_array_t*) l3)->length;
    l8 = INT64_C(0);
    while ((l8 < l7)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        l4 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l8];
        l9 = ((vader_struct_vader_emit_bytecode$StructureShape_t*) l1)->f_merge;
        l6 = l4;
        vader_array_t* _a3_slotarr = ((vader_array_t*) l9);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l6)
        t1 = ((uint8_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l6];
        t2 = t1;
        if (t2) {
            { int32_t __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l10 = ((vader_struct_vader_emit_bytecode$StructureShape_t*) l1)->f_rpo_index;
        l11 = l4;
        vader_array_t* _a4_slotarr = ((vader_array_t*) l10);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l11)
        l12 = ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l11];
        l13 = ((vader_struct_vader_emit_bytecode$StructureShape_t*) l1)->f_rpo_index;
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

static bool vader_emit_bytecode$needs_ref_cast(vader_box_t l0) {
    bool l1;
    void* t0;
    bool t1;
    if (l0.tag == 1031u) {
        return true;
    }
    if (l0.tag == 1030u) {
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
    uint64_t l5;
    void* t0 = NULL;
    void** gc_raw_roots[19] = {
        &l0, &l1, &l2, &l3, &l4, &l6, &l7, &l8, &l9, &l10, &l11, &l12, &l13, &l14, &l15, &l16, &l17,
        &l18, &t0,
    };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 19u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(360u, 0u, 13u, 1827u);
    l0 = (void*) _a0_arr;
    vader_struct_vader_core_bytecode$BcScalar_t* _a1_obj = (vader_struct_vader_core_bytecode$BcScalar_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcScalar_t));
    vader_obj_header_init(_a1_obj, 858u);
    _a1_obj->f_val = (uint8_t) 13;
    l1 = (void*) _a1_obj;
    vader_array_push_ref((vader_array_t*) l0, l1);
    vader_array_t* _a2_arr = vader_array_new(22u, 0u, 0u, 447u);
    l1 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(23u, 0u, 7u, 450u);
    l2 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_new(23u, 0u, 7u, 450u);
    l3 = (void*) _a4_arr;
    vader_struct_std_collections$MutableMap__string__i32_t* _a5_obj = (vader_struct_std_collections$MutableMap__string__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__string__i32_t));
    vader_obj_header_init(_a5_obj, 663u);
    _a5_obj->f_ekeys = l1;
    _a5_obj->f_evals = l2;
    _a5_obj->f_index = l3;
    _a5_obj->f_mask = INT64_C(0);
    _a5_obj->f_grow_at = INT64_C(0);
    _a5_obj->f_size = INT64_C(0);
    _a5_obj->f_tombs = INT64_C(0);
    l1 = (void*) _a5_obj;
    std_collections$MutableMap$std_core$IndexSet$set_at__string__i32(l1, 2413u, INT32_C(0));
    vader_array_t* _a6_arr = vader_array_new(28u, 0u, 4u, 455u);
    l2 = (void*) _a6_arr;
    vader_array_t* _a7_arr = vader_array_new(23u, 0u, 7u, 450u);
    l3 = (void*) _a7_arr;
    vader_array_t* _a8_arr = vader_array_new(23u, 0u, 7u, 450u);
    l4 = (void*) _a8_arr;
    vader_struct_std_collections$MutableMap__u64__i32_t* _a9_obj = (vader_struct_std_collections$MutableMap__u64__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__u64__i32_t));
    vader_obj_header_init(_a9_obj, 714u);
    _a9_obj->f_ekeys = l2;
    _a9_obj->f_evals = l3;
    _a9_obj->f_index = l4;
    _a9_obj->f_mask = INT64_C(0);
    _a9_obj->f_grow_at = INT64_C(0);
    _a9_obj->f_size = INT64_C(0);
    _a9_obj->f_tombs = INT64_C(0);
    l2 = (void*) _a9_obj;
    t0 = (void*) &vader_data_17;
    vader_array_t* _a10_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
    t0 = vader_array_ref_load_obj(_a10_slotarr->buf, _a10_slotarr->offset + (size_t) INT64_C(0));
    l5 = vader_midir_select$type_intern_hash(vader_ref_box(t0));
    std_collections$MutableMap$std_core$IndexSet$set_at__u64__i32(l2, l5, INT32_C(0));
    t0 = (void*) &vader_data_17;
    vader_array_t* _a11_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
    t0 = vader_array_ref_load_obj(_a11_slotarr->buf, _a11_slotarr->offset + (size_t) INT64_C(0));
    vader_array_t* _a12_arr = vader_array_new(363u, 1u, 13u, 1904u);
    ((void**) _a12_arr->buf->slots)[_a12_arr->offset + 0u] = t0;
    l3 = (void*) _a12_arr;
    vader_array_t* _a13_arr = vader_array_new(71u, 0u, 13u, 853u);
    l4 = (void*) _a13_arr;
    vader_array_t* _a14_arr = vader_array_new(22u, 0u, 0u, 447u);
    l6 = (void*) _a14_arr;
    vader_array_t* _a15_arr = vader_array_new(22u, 0u, 0u, 447u);
    l7 = (void*) _a15_arr;
    vader_array_t* _a16_arr = vader_array_new(23u, 0u, 7u, 450u);
    l8 = (void*) _a16_arr;
    vader_array_t* _a17_arr = vader_array_new(23u, 0u, 7u, 450u);
    l9 = (void*) _a17_arr;
    vader_struct_std_collections$MutableMap__string__i32_t* _a18_obj = (vader_struct_std_collections$MutableMap__string__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__string__i32_t));
    vader_obj_header_init(_a18_obj, 663u);
    _a18_obj->f_ekeys = l7;
    _a18_obj->f_evals = l8;
    _a18_obj->f_index = l9;
    _a18_obj->f_mask = INT64_C(0);
    _a18_obj->f_grow_at = INT64_C(0);
    _a18_obj->f_size = INT64_C(0);
    _a18_obj->f_tombs = INT64_C(0);
    l7 = (void*) _a18_obj;
    vader_array_t* _a19_arr = vader_array_new(70u, 0u, 13u, 852u);
    l8 = (void*) _a19_arr;
    vader_array_t* _a20_arr = vader_array_new(23u, 0u, 7u, 450u);
    l9 = (void*) _a20_arr;
    vader_array_t* _a21_arr = vader_array_new(23u, 0u, 7u, 450u);
    l10 = (void*) _a21_arr;
    vader_array_t* _a22_arr = vader_array_new(23u, 0u, 7u, 450u);
    l11 = (void*) _a22_arr;
    vader_struct_std_collections$MutableMap__i32__i32_t* _a23_obj = (vader_struct_std_collections$MutableMap__i32__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i32__i32_t));
    vader_obj_header_init(_a23_obj, 586u);
    _a23_obj->f_ekeys = l9;
    _a23_obj->f_evals = l10;
    _a23_obj->f_index = l11;
    _a23_obj->f_mask = INT64_C(0);
    _a23_obj->f_grow_at = INT64_C(0);
    _a23_obj->f_size = INT64_C(0);
    _a23_obj->f_tombs = INT64_C(0);
    l9 = (void*) _a23_obj;
    vader_array_t* _a24_arr = vader_array_new(22u, 0u, 0u, 447u);
    l10 = (void*) _a24_arr;
    vader_array_t* _a25_arr = vader_array_new(23u, 0u, 7u, 450u);
    l11 = (void*) _a25_arr;
    vader_array_t* _a26_arr = vader_array_new(23u, 0u, 7u, 450u);
    l12 = (void*) _a26_arr;
    vader_struct_std_collections$MutableMap__string__i32_t* _a27_obj = (vader_struct_std_collections$MutableMap__string__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__string__i32_t));
    vader_obj_header_init(_a27_obj, 663u);
    _a27_obj->f_ekeys = l10;
    _a27_obj->f_evals = l11;
    _a27_obj->f_index = l12;
    _a27_obj->f_mask = INT64_C(0);
    _a27_obj->f_grow_at = INT64_C(0);
    _a27_obj->f_size = INT64_C(0);
    _a27_obj->f_tombs = INT64_C(0);
    l10 = (void*) _a27_obj;
    vader_array_t* _a28_arr = vader_array_new(72u, 0u, 13u, 854u);
    l11 = (void*) _a28_arr;
    vader_array_t* _a29_arr = vader_array_new(23u, 0u, 7u, 450u);
    l12 = (void*) _a29_arr;
    vader_array_t* _a30_arr = vader_array_new(23u, 0u, 7u, 450u);
    l13 = (void*) _a30_arr;
    vader_array_t* _a31_arr = vader_array_new(23u, 0u, 7u, 450u);
    l14 = (void*) _a31_arr;
    vader_struct_std_collections$MutableMap__i32__i32_t* _a32_obj = (vader_struct_std_collections$MutableMap__i32__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i32__i32_t));
    vader_obj_header_init(_a32_obj, 586u);
    _a32_obj->f_ekeys = l12;
    _a32_obj->f_evals = l13;
    _a32_obj->f_index = l14;
    _a32_obj->f_mask = INT64_C(0);
    _a32_obj->f_grow_at = INT64_C(0);
    _a32_obj->f_size = INT64_C(0);
    _a32_obj->f_tombs = INT64_C(0);
    l12 = (void*) _a32_obj;
    vader_array_t* _a33_arr = vader_array_new(22u, 0u, 0u, 447u);
    l13 = (void*) _a33_arr;
    vader_array_t* _a34_arr = vader_array_new(23u, 0u, 7u, 450u);
    l14 = (void*) _a34_arr;
    vader_array_t* _a35_arr = vader_array_new(23u, 0u, 7u, 450u);
    l15 = (void*) _a35_arr;
    vader_struct_std_collections$MutableMap__string__i32_t* _a36_obj = (vader_struct_std_collections$MutableMap__string__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__string__i32_t));
    vader_obj_header_init(_a36_obj, 663u);
    _a36_obj->f_ekeys = l13;
    _a36_obj->f_evals = l14;
    _a36_obj->f_index = l15;
    _a36_obj->f_mask = INT64_C(0);
    _a36_obj->f_grow_at = INT64_C(0);
    _a36_obj->f_size = INT64_C(0);
    _a36_obj->f_tombs = INT64_C(0);
    l13 = (void*) _a36_obj;
    vader_array_t* _a37_arr = vader_array_new(68u, 0u, 13u, 849u);
    l14 = (void*) _a37_arr;
    vader_array_t* _a38_arr = vader_array_new(23u, 0u, 7u, 450u);
    l15 = (void*) _a38_arr;
    vader_array_t* _a39_arr = vader_array_new(23u, 0u, 7u, 450u);
    l16 = (void*) _a39_arr;
    vader_array_t* _a40_arr = vader_array_new(29u, 0u, 0u, 458u);
    l17 = (void*) _a40_arr;
    vader_array_t* _a41_arr = vader_array_new(23u, 0u, 7u, 450u);
    l18 = (void*) _a41_arr;
    vader_struct_std_collections$MutableMap__i32__Any___t* _a42_obj = (vader_struct_std_collections$MutableMap__i32__Any___t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i32__Any___t));
    vader_obj_header_init(_a42_obj, 583u);
    _a42_obj->f_ekeys = l16;
    _a42_obj->f_evals = l17;
    _a42_obj->f_index = l18;
    _a42_obj->f_mask = INT64_C(0);
    _a42_obj->f_grow_at = INT64_C(0);
    _a42_obj->f_size = INT64_C(0);
    _a42_obj->f_tombs = INT64_C(0);
    l16 = (void*) _a42_obj;
    vader_struct_vader_emit_bytecode$EmitterCtx_t* _a43_obj = (vader_struct_vader_emit_bytecode$EmitterCtx_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_bytecode$EmitterCtx_t));
    vader_obj_header_init(_a43_obj, 1046u);
    _a43_obj->f_globals = l4;
    _a43_obj->f_types = l0;
    _a43_obj->f_type_key = l1;
    _a43_obj->f_type_hash = l2;
    _a43_obj->f_type_by_slot = l3;
    _a43_obj->f_strings = l6;
    _a43_obj->f_string_key = l7;
    _a43_obj->f_functions = l8;
    _a43_obj->f_function_index_by_symbol_id = l9;
    _a43_obj->f_function_index_by_mangle = l10;
    _a43_obj->f_imports = l11;
    _a43_obj->f_import_index_by_symbol_id = l12;
    _a43_obj->f_import_index_by_mangle = l13;
    _a43_obj->f_exports = l14;
    _a43_obj->f_pinned_types = l15;
    _a43_obj->f_types_frozen = false;
    _a43_obj->f_pinned_types_by_fn = l16;
    t0 = (void*) _a43_obj;
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
    t0 = concat_7(1860u, l1, 1210u, l3, 1123u, l4, 289u);
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
    t0 = ((uint8_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l4];
    t1 = t0;
    if (t1) {
        return true;
    }
    l3 = ((vader_struct_vader_emit_bytecode$StructureShape_t*) l0)->f_rpo_index;
    l4 = l2;
    vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
    l4 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
    l3 = ((vader_struct_vader_emit_bytecode$StructureShape_t*) l0)->f_rpo_index;
    l5 = l1;
    vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l5)
    l5 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l5];
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
    l4 = ((vader_array_t*) l1)->length;
    while ((l3 < l4)) {
        t0 = ((vader_array_t*) l1)->length;
        t1 = vader_chk_sub(i64, t0, INT64_C(1));
        l5 = vader_chk_sub(i64, t1, l3);
        vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
        l6 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l5];
        l7 = ((vader_struct_vader_midir$CFGFunction_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_fn_)->f_blocks;
        l8 = l6;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l8)
        t2 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l8);
        l9 = ((vader_struct_vader_midir$BasicBlock_t*) t2)->f_span;
        vader_emit_bytecode$cf_block(l0, l9, l6);
        l3 = (l3 + INT64_C(1));
    }
    l10 = std_iter$first_or_null__i32(l1);
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
    l6 = ((vader_struct_std_collections$MutableMap__i32__std_collections_MutableSet_i32__t*) l5)->f_ekeys;
    l7 = ((vader_struct_std_collections$MutableMap__i32__std_collections_MutableSet_i32__t*) l5)->f_evals;
    l8 = INT64_C(0);
    l9 = ((vader_struct_std_collections$MutableMap__i32__std_collections_MutableSet_i32__t*) l5)->f_size;
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
        t0 = std_collections$MutableSet$std_core$Contains$contains__i32(l12, l2);
        if (t0) {
            t0 = std_collections$MutableSet$std_core$Contains$contains__i32(l12, l3);
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
    vader_array_t* _a0_arr = vader_array_new(22u, 0u, 0u, 447u);
    l2 = (void*) _a0_arr;
    if (!(l1.tag == 773u)) {
        { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = false;
    t0 = l1.payload.obj;
    l4 = ((vader_struct_toolchain_ast$FnDecl_t*) t0)->f_params;
    l5 = ((vader_array_t*) l4)->length;
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l6);
        l7 = toolchain_ast$c_type_of(((vader_struct_toolchain_ast$FnParam_t*) t0)->f_decorators);
        vader_array_push_scalar((vader_array_t*) l2, vader_box_string(447u, l7));
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

static void* vader_emit_bytecode$propagate_const_single_use(void* l0) {
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
    l1 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_signature)->f_params)->length;
    l2 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_locals)->length;
    l2 = vader_chk_add(i64, l1, l2);
    if ((l2 <= l1)) {
        { void* __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a0_arr = vader_array_new(23u, 1u, 7u, 450u);
    ((int32_t*) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = (int32_t) INT32_C(0);
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l2);
    l3 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(23u, 1u, 7u, 450u);
    ((int32_t*) _a2_arr->buf->slots)[_a2_arr->offset + 0u] = (int32_t) INT32_C(0);
    t0 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l2);
    l4 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_new(23u, 1u, 7u, 450u);
    ((int32_t*) _a4_arr->buf->slots)[_a4_arr->offset + 0u] = (int32_t) INT32_C(0);
    t0 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l2);
    l5 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(23u, 1u, 7u, 450u);
    ((int32_t*) _a6_arr->buf->slots)[_a6_arr->offset + 0u] = (int32_t) INT32_C(-1);
    t0 = (void*) _a6_arr;
    vader_array_t* _a7_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l2);
    l6 = (void*) _a7_arr;
    vader_array_t* _a8_arr = vader_array_new(23u, 1u, 7u, 450u);
    ((int32_t*) _a8_arr->buf->slots)[_a8_arr->offset + 0u] = (int32_t) INT32_C(-1);
    t0 = (void*) _a8_arr;
    vader_array_t* _a9_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l2);
    l7 = (void*) _a9_arr;
    l8 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_body;
    l9 = ((vader_array_t*) l8)->length;
    l10 = INT64_C(0);
    while ((l10 < l9)) {
        vader_array_t* _a10_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
        l11 = vader_array_ref_load_box(_a10_slotarr->buf, _a10_slotarr->offset + (size_t) l10);
        if (l11.tag == 966u) {
            t0 = l11.payload.obj;
            t1 = ((vader_struct_vader_core_bytecode$LocalSet_t*) t0)->f_slot;
            l12 = ((int64_t) (int32_t) t1);
            vader_array_t* _a11_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l12)
            t1 = ((int32_t*) _a11_slotarr->buf->slots)[_a11_slotarr->offset + (size_t) l12];
            l13 = vader_chk_add(i32, t1, INT32_C(1));
            VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l12)
            ((int32_t*) _a11_slotarr->buf->slots)[_a11_slotarr->offset + (size_t) l12] = (int32_t) l13;
            l14 = ((int32_t) (int64_t) l10);
            vader_array_t* _a12_slotarr = ((vader_array_t*) l6);
            VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a12_slotarr, l12)
            ((int32_t*) _a12_slotarr->buf->slots)[_a12_slotarr->offset + (size_t) l12] = (int32_t) l14;
        }
        if (l11.tag == 967u) {
            t0 = l11.payload.obj;
            l15 = ((vader_struct_vader_core_bytecode$LocalTee_t*) t0)->f_slot;
            vader_array_t* _a13_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a13_slotarr, l15)
            t1 = ((int32_t*) _a13_slotarr->buf->slots)[_a13_slotarr->offset + (size_t) l15];
            l16 = vader_chk_add(i32, t1, INT32_C(1));
            VADER_ARRAY_CHECK_INDEX(_a13_slotarr, l15)
            ((int32_t*) _a13_slotarr->buf->slots)[_a13_slotarr->offset + (size_t) l15] = (int32_t) l16;
        }
        if (l11.tag == 965u) {
            t0 = l11.payload.obj;
            t1 = ((vader_struct_vader_core_bytecode$LocalGet_t*) t0)->f_slot;
            l17 = ((int64_t) (int32_t) t1);
            vader_array_t* _a14_slotarr = ((vader_array_t*) l4);
            VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a14_slotarr, l17)
            t1 = ((int32_t*) _a14_slotarr->buf->slots)[_a14_slotarr->offset + (size_t) l17];
            l18 = vader_chk_add(i32, t1, INT32_C(1));
            VADER_ARRAY_CHECK_INDEX(_a14_slotarr, l17)
            ((int32_t*) _a14_slotarr->buf->slots)[_a14_slotarr->offset + (size_t) l17] = (int32_t) l18;
            l19 = ((int32_t) (int64_t) l10);
            vader_array_t* _a15_slotarr = ((vader_array_t*) l7);
            VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a15_slotarr, l17)
            ((int32_t*) _a15_slotarr->buf->slots)[_a15_slotarr->offset + (size_t) l17] = (int32_t) l19;
        }
        l10 = (l10 + INT64_C(1));
    }
    vader_array_t* _a16_arr = vader_array_new(23u, 0u, 7u, 450u);
    l20 = (void*) _a16_arr;
    vader_array_t* _a17_arr = vader_array_new(20u, 0u, 12u, 445u);
    l21 = (void*) _a17_arr;
    vader_array_t* _a18_arr = vader_array_new(23u, 0u, 7u, 450u);
    l22 = (void*) _a18_arr;
    vader_struct_std_collections$MutableMap__i32__bool_t* _a19_obj = (vader_struct_std_collections$MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i32__bool_t));
    vader_obj_header_init(_a19_obj, 585u);
    _a19_obj->f_ekeys = l20;
    _a19_obj->f_evals = l21;
    _a19_obj->f_index = l22;
    _a19_obj->f_mask = INT64_C(0);
    _a19_obj->f_grow_at = INT64_C(0);
    _a19_obj->f_size = INT64_C(0);
    _a19_obj->f_tombs = INT64_C(0);
    l20 = (void*) _a19_obj;
    vader_array_t* _a20_arr = vader_array_new(23u, 0u, 7u, 450u);
    l21 = (void*) _a20_arr;
    vader_array_t* _a21_arr = vader_array_new(29u, 0u, 0u, 458u);
    l22 = (void*) _a21_arr;
    vader_array_t* _a22_arr = vader_array_new(23u, 0u, 7u, 450u);
    l23 = (void*) _a22_arr;
    vader_struct_std_collections$MutableMap__i32__Any_t* _a23_obj = (vader_struct_std_collections$MutableMap__i32__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i32__Any_t));
    vader_obj_header_init(_a23_obj, 582u);
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
        t1 = ((int32_t*) _a24_slotarr->buf->slots)[_a24_slotarr->offset + (size_t) l10];
        if (t1 != INT32_C(0)) {
            l24 = false;
        }
        vader_array_t* _a25_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a25_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a25_slotarr, l10)
        t1 = ((int32_t*) _a25_slotarr->buf->slots)[_a25_slotarr->offset + (size_t) l10];
        if (t1 != INT32_C(1)) {
            l24 = false;
        }
        vader_array_t* _a26_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a26_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a26_slotarr, l10)
        t1 = ((int32_t*) _a26_slotarr->buf->slots)[_a26_slotarr->offset + (size_t) l10];
        if (t1 != INT32_C(1)) {
            l24 = false;
        }
        l13 = INT32_C(-1);
        l14 = INT32_C(-1);
        if (l24) {
            vader_array_t* _a27_slotarr = ((vader_array_t*) l6);
            VADER_ARRAY_RESOLVE_BUF(_a27_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a27_slotarr, l10)
            l13 = ((int32_t*) _a27_slotarr->buf->slots)[_a27_slotarr->offset + (size_t) l10];
            vader_array_t* _a28_slotarr = ((vader_array_t*) l7);
            VADER_ARRAY_RESOLVE_BUF(_a28_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a28_slotarr, l10)
            l14 = ((int32_t*) _a28_slotarr->buf->slots)[_a28_slotarr->offset + (size_t) l10];
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
            l11 = vader_array_ref_load_box(_a29_slotarr->buf, _a29_slotarr->offset + (size_t) l15);
            l25 = vader_core_bytecode$const_op_of(l11);
            if (l25.tag == 0u) {
                l24 = false;
            } else {
                l22 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_locals;
                l12 = vader_chk_sub(i64, l10, l1);
                vader_array_t* _a30_slotarr = ((vader_array_t*) l22);
                VADER_ARRAY_RESOLVE_BUF(_a30_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a30_slotarr, l12)
                t0 = vader_array_ref_load_obj(_a30_slotarr->buf, _a30_slotarr->offset + (size_t) l12);
                l26 = ((vader_struct_vader_core_bytecode$BcLocal_t*) t0)->f_val;
                t2 = vader_emit_bytecode$const_fills_slot(l25, l26);
                if (t2) {
                    l16 = vader_chk_sub(i32, l13, INT32_C(1));
                    std_collections$MutableMap$std_core$IndexSet$set_at__i32__bool(l20, l16, true);
                    std_collections$MutableMap$std_core$IndexSet$set_at__i32__bool(l20, l13, true);
                    std_collections$MutableMap$std_core$IndexSet$set_at__i32__Any(l21, l14, l11);
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
    vader_array_t* _a31_arr = vader_array_new(358u, 0u, 13u, 1803u);
    l3 = (void*) _a31_arr;
    vader_array_t* _a32_arr = vader_array_new(362u, 0u, 13u, 1863u);
    l4 = (void*) _a32_arr;
    vader_array_t* _a33_arr = vader_array_new(23u, 1u, 7u, 450u);
    ((int32_t*) _a33_arr->buf->slots)[_a33_arr->offset + 0u] = (int32_t) INT32_C(-1);
    t0 = (void*) _a33_arr;
    vader_array_t* _a34_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l9);
    l5 = (void*) _a34_arr;
    l1 = INT64_C(0);
    while ((l1 < l9)) {
        l13 = ((int32_t) (int64_t) l1);
        t3 = std_collections$MutableMap$std_core$Index$at__i32__bool(l20, l13);
        if (t3.tag == 445u) {
            l1 = vader_chk_add(i64, l1, INT64_C(1));
            continue;
        }
        l14 = ((int32_t) (int64_t) l1);
        l11 = std_collections$MutableMap$std_core$Index$at__i32__Any(l21, l14);
        if (l11.tag == 0u) {
            t4 = ((vader_array_t*) l3)->length;
            l15 = ((int32_t) (int64_t) t4);
            vader_array_t* _a35_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a35_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a35_slotarr, l1)
            ((int32_t*) _a35_slotarr->buf->slots)[_a35_slotarr->offset + (size_t) l1] = (int32_t) l15;
            vader_array_t* _a36_slotarr = ((vader_array_t*) l8);
            VADER_ARRAY_RESOLVE_BUF(_a36_slotarr)
            l25 = vader_array_ref_load_box(_a36_slotarr->buf, _a36_slotarr->offset + (size_t) l1);
            vader_array_push_ref((vader_array_t*) l3, l25.payload.obj);
            vader_array_t* _a37_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_debug);
            VADER_ARRAY_RESOLVE_BUF(_a37_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a37_slotarr, l1)
            l27 = vader_array_ref_load_box(_a37_slotarr->buf, _a37_slotarr->offset + (size_t) l1);
            vader_array_push_ref((vader_array_t*) l4, l27.payload.obj);
        } else {
            t4 = ((vader_array_t*) l3)->length;
            l16 = ((int32_t) (int64_t) t4);
            vader_array_t* _a38_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a38_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a38_slotarr, l1)
            ((int32_t*) _a38_slotarr->buf->slots)[_a38_slotarr->offset + (size_t) l1] = (int32_t) l16;
            l28 = l11;
            vader_array_push_ref((vader_array_t*) l3, l28.payload.obj);
            vader_array_t* _a39_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_debug);
            VADER_ARRAY_RESOLVE_BUF(_a39_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a39_slotarr, l1)
            l29 = vader_array_ref_load_box(_a39_slotarr->buf, _a39_slotarr->offset + (size_t) l1);
            vader_array_push_ref((vader_array_t*) l4, l29.payload.obj);
        }
        l1 = vader_chk_add(i64, l1, INT64_C(1));
    }
    l6 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_jump_table;
    l1 = ((vader_array_t*) l3)->length;
    l5 = vader_core_bytecode$remap_jump_table(l6, l5, l1);
    l6 = l0;
    l30 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l6)->f_name;
    l24 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l6)->f_is_main;
    l7 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l6)->f_signature;
    l8 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l6)->f_locals;
    l6 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l6)->f_source_pc;
    vader_struct_vader_core_bytecode$BcFunction_t* _a40_obj = (vader_struct_vader_core_bytecode$BcFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcFunction_t));
    vader_obj_header_init(_a40_obj, 852u);
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
    vader_array_t* _a0_arr = vader_array_new(23u, 0u, 7u, 450u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(20u, 0u, 12u, 445u);
    l3 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(23u, 0u, 7u, 450u);
    l4 = (void*) _a2_arr;
    vader_struct_std_collections$MutableMap__i32__bool_t* _a3_obj = (vader_struct_std_collections$MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i32__bool_t));
    vader_obj_header_init(_a3_obj, 585u);
    _a3_obj->f_ekeys = l2;
    _a3_obj->f_evals = l3;
    _a3_obj->f_index = l4;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a3_obj;
    vader_struct_std_collections$MutableSet__i32_t* _a4_obj = (vader_struct_std_collections$MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableSet__i32_t));
    vader_obj_header_init(_a4_obj, 728u);
    _a4_obj->f_inner = t0;
    l2 = (void*) _a4_obj;
    l3 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_functions;
    l5 = ((vader_array_t*) l3)->length;
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a5_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        t0 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l6);
        l4 = ((vader_struct_vader_core_bytecode$BcFunction_t*) t0)->f_body;
        l7 = ((vader_array_t*) l4)->length;
        l8 = INT64_C(0);
        while ((l8 < l7)) {
            vader_array_t* _a6_slotarr = ((vader_array_t*) l4);
            VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
            l9 = vader_array_ref_load_box(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l8);
            if (l9.tag == 890u) {
                t0 = l9.payload.obj;
                l10 = ((vader_struct_vader_core_bytecode$DataConst_t*) t0)->f_pool_index;
                std_collections$add__i32(l2, l10);
            }
            l8 = (l8 + INT64_C(1));
        }
        l6 = (l6 + INT64_C(1));
    }
    l5 = std_collections$len__i32(l2);
    l6 = ((vader_array_t*) l1)->length;
    if (l5 == l6) {
        { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a7_arr = vader_array_new(23u, 0u, 7u, 450u);
    l3 = (void*) _a7_arr;
    vader_array_t* _a8_arr = vader_array_new(359u, 0u, 13u, 1826u);
    l4 = (void*) _a8_arr;
    l5 = INT64_C(0);
    l6 = ((vader_array_t*) l1)->length;
    while ((l5 < l6)) {
        l10 = ((int32_t) (int64_t) l5);
        t1 = std_collections$MutableSet$std_core$Contains$contains__i32(l2, l10);
        if (t1) {
            t2 = ((vader_array_t*) l4)->length;
            l11 = ((int32_t) (int64_t) t2);
            vader_array_push_i32((vader_array_t*) l3, l11);
            vader_array_t* _a9_slotarr = ((vader_array_t*) l1);
            VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
            l9 = vader_array_ref_load_box(_a9_slotarr->buf, _a9_slotarr->offset + (size_t) l5);
            vader_array_push_ref((vader_array_t*) l4, l9.payload.obj);
        } else {
            vader_array_push_i32((vader_array_t*) l3, INT32_C(-1));
        }
        l5 = (l5 + INT64_C(1));
    }
    l2 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_functions;
    l5 = ((vader_array_t*) l2)->length;
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a10_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
        l12 = vader_array_ref_load_obj(_a10_slotarr->buf, _a10_slotarr->offset + (size_t) l6);
        l7 = INT64_C(0);
        l8 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l12)->f_body)->length;
        while ((l7 < l8)) {
            vader_array_t* _a11_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l12)->f_body);
            VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l7)
            l9 = vader_array_ref_load_box(_a11_slotarr->buf, _a11_slotarr->offset + (size_t) l7);
            if (l9.tag == 890u) {
                l13 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l12)->f_body;
                l14 = l9.payload.obj;
                t0 = l9.payload.obj;
                l10 = ((vader_struct_vader_core_bytecode$DataConst_t*) t0)->f_pool_index;
                vader_array_t* _a12_slotarr = ((vader_array_t*) l3);
                VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a12_slotarr, l10)
                l11 = ((int32_t*) _a12_slotarr->buf->slots)[_a12_slotarr->offset + (size_t) l10];
                l15 = ((vader_struct_vader_core_bytecode$DataConst_t*) l14)->f_type_id;
                vader_struct_vader_core_bytecode$DataConst_t* _a13_obj = (vader_struct_vader_core_bytecode$DataConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$DataConst_t));
                vader_obj_header_init(_a13_obj, 890u);
                _a13_obj->f_pool_index = l11;
                _a13_obj->f_type_id = l15;
                l16 = (void*) _a13_obj;
                vader_array_t* _a14_slotarr = ((vader_array_t*) l13);
                VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a14_slotarr, l7)
                vader_array_ref_store(_a14_slotarr->buf, _a14_slotarr->offset + (size_t) l7, l16);
                VADER_WRITE_BARRIER(_a14_slotarr->buf);
            }
            l7 = (l7 + INT64_C(1));
        }
        l6 = (l6 + INT64_C(1));
    }
    { void* __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_emit_bytecode$prune_unused_functions(void* l0, void* l1, void* l2) {
    int64_t l3, l7, l11, l12, l14, l18;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l16 = NULL;
    void* l17 = NULL;
    void* l19 = NULL;
    void* l21 = NULL;
    void* l25 = NULL;
    int32_t l8, l10, l22, l23, l24, l26, l27, l28;
    vader_string_t l9 = 0;
    vader_string_t l29 = 0;
    bool l13;
    vader_box_t l15 = vader_box_null(), l20 = vader_box_null();
    bool t0;
    int32_t t1;
    void* t2 = NULL;
    vader_box_t t3 = vader_box_null();
    int64_t t4;
    vader_string_t t5 = 0;
    vader_box_t* gc_roots[3] = { &l15, &l20, &t3 };
    void** gc_raw_roots[12] = { &l0, &l1, &l2, &l4, &l5, &l6, &l16, &l17, &l19, &l21, &l25, &t2 };
    vader_string_t* gc_atom_roots[3] = { &l9, &l29, &t5 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 12u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = ((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_functions)->length;
    vader_array_t* _a0_arr = vader_array_new(23u, 0u, 7u, 450u);
    l4 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(20u, 0u, 12u, 445u);
    l5 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(23u, 0u, 7u, 450u);
    l6 = (void*) _a2_arr;
    vader_struct_std_collections$MutableMap__i32__bool_t* _a3_obj = (vader_struct_std_collections$MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i32__bool_t));
    vader_obj_header_init(_a3_obj, 585u);
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
        l5 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l7);
        t0 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l5)->f_is_main;
        if (t0) {
            l8 = ((int32_t) (int64_t) l7);
            std_collections$MutableMap$std_core$IndexSet$set_at__i32__bool(l4, l8, true);
        }
        l9 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l5)->f_name;
        t0 = std_core$$array$Contains$contains__string(l2, l9);
        if (t0) {
            l10 = ((int32_t) (int64_t) l7);
            std_collections$MutableMap$std_core$IndexSet$set_at__i32__bool(l4, l10, true);
        }
        l7 = (l7 + INT64_C(1));
    }
    l5 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_exports;
    l7 = ((vader_array_t*) l5)->length;
    l11 = INT64_C(0);
    while ((l11 < l7)) {
        vader_array_t* _a5_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        l6 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l11);
        t1 = ((vader_struct_vader_core_bytecode$BcExport_t*) l6)->f_fn_index;
        l12 = ((int64_t) (int32_t) t1);
        if ((INT64_C(0) <= l12)) {
            l13 = (l12 < l3);
        } else {
            l13 = false;
        }
        if (l13) {
            l8 = ((vader_struct_vader_core_bytecode$BcExport_t*) l6)->f_fn_index;
            std_collections$MutableMap$std_core$IndexSet$set_at__i32__bool(l4, l8, true);
        }
        l11 = (l11 + INT64_C(1));
    }
    l5 = l1;
    l7 = ((vader_array_t*) l5)->length;
    l11 = INT64_C(0);
    while ((l11 < l7)) {
        vader_array_t* _a6_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        l8 = ((int32_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l11];
        l12 = ((int64_t) (int32_t) l8);
        if ((INT64_C(0) <= l12)) {
            l13 = (l12 < l3);
        } else {
            l13 = false;
        }
        if (l13) {
            std_collections$MutableMap$std_core$IndexSet$set_at__i32__bool(l4, l8, true);
        }
        l11 = (l11 + INT64_C(1));
    }
    l5 = std_collections$keys__i32__bool(l4);
    l7 = INT64_C(0);
    for (;;) {
        l11 = ((vader_array_t*) l5)->length;
        if ((l7 < l11)) {
            vader_array_t* _a7_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
            l8 = ((int32_t*) _a7_slotarr->buf->slots)[_a7_slotarr->offset + (size_t) l7];
            l7 = vader_chk_add(i64, l7, INT64_C(1));
            vader_array_t* _a8_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_functions);
            VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l8)
            t2 = vader_array_ref_load_obj(_a8_slotarr->buf, _a8_slotarr->offset + (size_t) l8);
            l6 = ((vader_struct_vader_core_bytecode$BcFunction_t*) t2)->f_body;
            l12 = ((vader_array_t*) l6)->length;
            l14 = INT64_C(0);
            while ((l14 < l12)) {
                vader_array_t* _a9_slotarr = ((vader_array_t*) l6);
                VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
                l15 = vader_array_ref_load_box(_a9_slotarr->buf, _a9_slotarr->offset + (size_t) l14);
                if ((l15.tag == 883u || l15.tag == 911u || l15.tag == 912u || l15.tag == 969u)) {
                    l10 = VADER_UNION_FIELD(int32_t, vader_struct_vader_core_bytecode$Call_t, f_function_index, l15.payload.obj);
                    t3 = std_collections$MutableMap$std_core$Index$at__i32__bool(l4, l10);
                    if (t3.tag == 445u) {
                        l14 = (l14 + INT64_C(1));
                        continue;
                    }
                    std_collections$MutableMap$std_core$IndexSet$set_at__i32__bool(l4, l10, true);
                    vader_array_push_i32((vader_array_t*) l5, l10);
                    l14 = (l14 + INT64_C(1));
                    continue;
                }
                l14 = (l14 + INT64_C(1));
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
    vader_array_t* _a10_arr = vader_array_new(70u, 0u, 13u, 852u);
    l5 = (void*) _a10_arr;
    vader_array_t* _a11_arr = vader_array_new(23u, 0u, 7u, 450u);
    l6 = (void*) _a11_arr;
    l7 = INT64_C(0);
    while ((l7 < l3)) {
        l8 = ((int32_t) (int64_t) l7);
        t3 = std_collections$MutableMap$std_core$Index$at__i32__bool(l4, l8);
        if (t3.tag == 445u) {
            t4 = ((vader_array_t*) l5)->length;
            l10 = ((int32_t) (int64_t) t4);
            vader_array_push_i32((vader_array_t*) l6, l10);
            vader_array_t* _a12_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_functions);
            VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a12_slotarr, l7)
            l16 = vader_array_ref_load_obj(_a12_slotarr->buf, _a12_slotarr->offset + (size_t) l7);
            vader_array_push_ref((vader_array_t*) l5, l16);
        } else {
            vader_array_push_i32((vader_array_t*) l6, INT32_C(-1));
        }
        l7 = (l7 + INT64_C(1));
    }
    l4 = l5;
    l3 = ((vader_array_t*) l4)->length;
    l7 = INT64_C(0);
    while ((l7 < l3)) {
        vader_array_t* _a13_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
        l16 = vader_array_ref_load_obj(_a13_slotarr->buf, _a13_slotarr->offset + (size_t) l7);
        l17 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l16)->f_body;
        l11 = INT64_C(0);
        l12 = ((vader_array_t*) l17)->length;
        l14 = INT64_C(0);
        while ((l14 < l12)) {
            vader_array_t* _a14_slotarr = ((vader_array_t*) l17);
            VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
            l15 = vader_array_ref_load_box(_a14_slotarr->buf, _a14_slotarr->offset + (size_t) l14);
            l18 = l11;
            l19 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l16)->f_body;
            if (l15.tag == 883u) {
                t2 = l15.payload.obj;
                l8 = ((vader_struct_vader_core_bytecode$Call_t*) t2)->f_function_index;
                vader_array_t* _a15_slotarr = ((vader_array_t*) l6);
                VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a15_slotarr, l8)
                t1 = ((int32_t*) _a15_slotarr->buf->slots)[_a15_slotarr->offset + (size_t) l8];
                vader_struct_vader_core_bytecode$Call_t* _a16_obj = (vader_struct_vader_core_bytecode$Call_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$Call_t));
                vader_obj_header_init(_a16_obj, 883u);
                _a16_obj->f_function_index = t1;
                t2 = (void*) _a16_obj;
                l20 = vader_ref_box(t2);
            } else if (l15.tag == 912u) {
                l21 = l15.payload.obj;
                t2 = l15.payload.obj;
                l10 = ((vader_struct_vader_core_bytecode$FnRef_t*) t2)->f_function_index;
                vader_array_t* _a17_slotarr = ((vader_array_t*) l6);
                VADER_ARRAY_RESOLVE_BUF(_a17_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a17_slotarr, l10)
                l22 = ((int32_t*) _a17_slotarr->buf->slots)[_a17_slotarr->offset + (size_t) l10];
                l23 = ((vader_struct_vader_core_bytecode$FnRef_t*) l21)->f_type_id;
                vader_struct_vader_core_bytecode$FnRef_t* _a18_obj = (vader_struct_vader_core_bytecode$FnRef_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$FnRef_t));
                vader_obj_header_init(_a18_obj, 912u);
                _a18_obj->f_function_index = l22;
                _a18_obj->f_type_id = l23;
                t2 = (void*) _a18_obj;
                l20 = vader_ref_box(t2);
            } else if (l15.tag == 911u) {
                t2 = l15.payload.obj;
                l24 = ((vader_struct_vader_core_bytecode$FnAddr_t*) t2)->f_function_index;
                vader_array_t* _a19_slotarr = ((vader_array_t*) l6);
                VADER_ARRAY_RESOLVE_BUF(_a19_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a19_slotarr, l24)
                t1 = ((int32_t*) _a19_slotarr->buf->slots)[_a19_slotarr->offset + (size_t) l24];
                vader_struct_vader_core_bytecode$FnAddr_t* _a20_obj = (vader_struct_vader_core_bytecode$FnAddr_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$FnAddr_t));
                vader_obj_header_init(_a20_obj, 911u);
                _a20_obj->f_function_index = t1;
                t2 = (void*) _a20_obj;
                l20 = vader_ref_box(t2);
            } else if (l15.tag == 969u) {
                l25 = l15.payload.obj;
                t2 = l15.payload.obj;
                l26 = ((vader_struct_vader_core_bytecode$MakeClosure_t*) t2)->f_function_index;
                vader_array_t* _a21_slotarr = ((vader_array_t*) l6);
                VADER_ARRAY_RESOLVE_BUF(_a21_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a21_slotarr, l26)
                l27 = ((int32_t*) _a21_slotarr->buf->slots)[_a21_slotarr->offset + (size_t) l26];
                l28 = ((vader_struct_vader_core_bytecode$MakeClosure_t*) l25)->f_env_type_id;
                vader_struct_vader_core_bytecode$MakeClosure_t* _a22_obj = (vader_struct_vader_core_bytecode$MakeClosure_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$MakeClosure_t));
                vader_obj_header_init(_a22_obj, 969u);
                _a22_obj->f_function_index = l27;
                _a22_obj->f_env_type_id = l28;
                t2 = (void*) _a22_obj;
                l20 = vader_ref_box(t2);
            } else {
                l20 = l15;
            }
            vader_array_t* _a23_slotarr = ((vader_array_t*) l19);
            VADER_ARRAY_RESOLVE_BUF(_a23_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a23_slotarr, l18)
            vader_array_ref_store(_a23_slotarr->buf, _a23_slotarr->offset + (size_t) l18, l20.payload.obj);
            VADER_WRITE_BARRIER(_a23_slotarr->buf);
            l11 = vader_chk_add(i64, l11, INT64_C(1));
            l14 = (l14 + INT64_C(1));
        }
        l7 = (l7 + INT64_C(1));
    }
    vader_array_t* _a24_arr = vader_array_new(68u, 0u, 13u, 849u);
    l4 = (void*) _a24_arr;
    l16 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_exports;
    l3 = ((vader_array_t*) l16)->length;
    l7 = INT64_C(0);
    while ((l7 < l3)) {
        vader_array_t* _a25_slotarr = ((vader_array_t*) l16);
        VADER_ARRAY_RESOLVE_BUF(_a25_slotarr)
        l17 = vader_array_ref_load_obj(_a25_slotarr->buf, _a25_slotarr->offset + (size_t) l7);
        l8 = ((vader_struct_vader_core_bytecode$BcExport_t*) l17)->f_fn_index;
        vader_array_t* _a26_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a26_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a26_slotarr, l8)
        l10 = ((int32_t*) _a26_slotarr->buf->slots)[_a26_slotarr->offset + (size_t) l8];
        if ((l10 >= INT32_C(0))) {
            t5 = ((vader_struct_vader_core_bytecode$BcExport_t*) l17)->f_extern_name;
            vader_struct_vader_core_bytecode$BcExport_t* _a27_obj = (vader_struct_vader_core_bytecode$BcExport_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcExport_t));
            vader_obj_header_init(_a27_obj, 849u);
            _a27_obj->f_extern_name = t5;
            _a27_obj->f_fn_index = l10;
            l19 = (void*) _a27_obj;
            vader_array_push_ref((vader_array_t*) l4, l19);
        }
        l7 = (l7 + INT64_C(1));
    }
    ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_exports = l4;
    VADER_WRITE_BARRIER((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0);
    vader_array_t* _a28_arr = vader_array_new(23u, 0u, 7u, 450u);
    l4 = (void*) _a28_arr;
    vader_array_t* _a29_arr = vader_array_new(23u, 0u, 7u, 450u);
    l16 = (void*) _a29_arr;
    vader_array_t* _a30_arr = vader_array_new(23u, 0u, 7u, 450u);
    l17 = (void*) _a30_arr;
    vader_struct_std_collections$MutableMap__i32__i32_t* _a31_obj = (vader_struct_std_collections$MutableMap__i32__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i32__i32_t));
    vader_obj_header_init(_a31_obj, 586u);
    _a31_obj->f_ekeys = l4;
    _a31_obj->f_evals = l16;
    _a31_obj->f_index = l17;
    _a31_obj->f_mask = INT64_C(0);
    _a31_obj->f_grow_at = INT64_C(0);
    _a31_obj->f_size = INT64_C(0);
    _a31_obj->f_tombs = INT64_C(0);
    l4 = (void*) _a31_obj;
    l16 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_function_index_by_symbol_id;
    l17 = ((vader_struct_std_collections$MutableMap__i32__i32_t*) l16)->f_ekeys;
    l19 = ((vader_struct_std_collections$MutableMap__i32__i32_t*) l16)->f_evals;
    l3 = INT64_C(0);
    l7 = ((vader_struct_std_collections$MutableMap__i32__i32_t*) l16)->f_size;
    while ((l3 < l7)) {
        vader_array_t* _a32_slotarr = ((vader_array_t*) l17);
        VADER_ARRAY_RESOLVE_BUF(_a32_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a32_slotarr, l3)
        l8 = ((int32_t*) _a32_slotarr->buf->slots)[_a32_slotarr->offset + (size_t) l3];
        vader_array_t* _a33_slotarr = ((vader_array_t*) l19);
        VADER_ARRAY_RESOLVE_BUF(_a33_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a33_slotarr, l3)
        l10 = ((int32_t*) _a33_slotarr->buf->slots)[_a33_slotarr->offset + (size_t) l3];
        l22 = l8;
        l23 = l10;
        vader_array_t* _a34_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a34_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a34_slotarr, l23)
        l24 = ((int32_t*) _a34_slotarr->buf->slots)[_a34_slotarr->offset + (size_t) l23];
        if ((l24 >= INT32_C(0))) {
            std_collections$MutableMap$std_core$IndexSet$set_at__i32__i32(l4, l22, l24);
        }
        l3 = (l3 + INT64_C(1));
    }
    ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_function_index_by_symbol_id = l4;
    VADER_WRITE_BARRIER((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0);
    vader_array_t* _a35_arr = vader_array_new(22u, 0u, 0u, 447u);
    l4 = (void*) _a35_arr;
    vader_array_t* _a36_arr = vader_array_new(23u, 0u, 7u, 450u);
    l16 = (void*) _a36_arr;
    vader_array_t* _a37_arr = vader_array_new(23u, 0u, 7u, 450u);
    l17 = (void*) _a37_arr;
    vader_struct_std_collections$MutableMap__string__i32_t* _a38_obj = (vader_struct_std_collections$MutableMap__string__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__string__i32_t));
    vader_obj_header_init(_a38_obj, 663u);
    _a38_obj->f_ekeys = l4;
    _a38_obj->f_evals = l16;
    _a38_obj->f_index = l17;
    _a38_obj->f_mask = INT64_C(0);
    _a38_obj->f_grow_at = INT64_C(0);
    _a38_obj->f_size = INT64_C(0);
    _a38_obj->f_tombs = INT64_C(0);
    l4 = (void*) _a38_obj;
    l16 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_function_index_by_mangle;
    l17 = ((vader_struct_std_collections$MutableMap__string__i32_t*) l16)->f_ekeys;
    l19 = ((vader_struct_std_collections$MutableMap__string__i32_t*) l16)->f_evals;
    l3 = INT64_C(0);
    l7 = ((vader_struct_std_collections$MutableMap__string__i32_t*) l16)->f_size;
    while ((l3 < l7)) {
        vader_array_t* _a39_slotarr = ((vader_array_t*) l17);
        VADER_ARRAY_RESOLVE_BUF(_a39_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a39_slotarr, l3)
        t3 = vader_array_box_slots(_a39_slotarr->buf)[_a39_slotarr->offset + (size_t) l3];
        l9 = t3.payload.s;
        vader_array_t* _a40_slotarr = ((vader_array_t*) l19);
        VADER_ARRAY_RESOLVE_BUF(_a40_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a40_slotarr, l3)
        l8 = ((int32_t*) _a40_slotarr->buf->slots)[_a40_slotarr->offset + (size_t) l3];
        l29 = l9;
        l10 = l8;
        vader_array_t* _a41_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a41_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a41_slotarr, l10)
        l22 = ((int32_t*) _a41_slotarr->buf->slots)[_a41_slotarr->offset + (size_t) l10];
        if ((l22 >= INT32_C(0))) {
            std_collections$MutableMap$std_core$IndexSet$set_at__string__i32(l4, l29, l22);
        }
        l3 = (l3 + INT64_C(1));
    }
    ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_function_index_by_mangle = l4;
    VADER_WRITE_BARRIER((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0);
    vader_array_t* _a42_arr = vader_array_new(23u, 0u, 7u, 450u);
    l4 = (void*) _a42_arr;
    vader_array_t* _a43_arr = vader_array_new(29u, 0u, 0u, 458u);
    l16 = (void*) _a43_arr;
    vader_array_t* _a44_arr = vader_array_new(23u, 0u, 7u, 450u);
    l17 = (void*) _a44_arr;
    vader_struct_std_collections$MutableMap__i32__Any___t* _a45_obj = (vader_struct_std_collections$MutableMap__i32__Any___t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i32__Any___t));
    vader_obj_header_init(_a45_obj, 583u);
    _a45_obj->f_ekeys = l4;
    _a45_obj->f_evals = l16;
    _a45_obj->f_index = l17;
    _a45_obj->f_mask = INT64_C(0);
    _a45_obj->f_grow_at = INT64_C(0);
    _a45_obj->f_size = INT64_C(0);
    _a45_obj->f_tombs = INT64_C(0);
    l4 = (void*) _a45_obj;
    l16 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_pinned_types_by_fn;
    l17 = ((vader_struct_std_collections$MutableMap__i32__i32___t*) l16)->f_ekeys;
    l19 = ((vader_struct_std_collections$MutableMap__i32__i32___t*) l16)->f_evals;
    l3 = INT64_C(0);
    l7 = ((vader_struct_std_collections$MutableMap__i32__i32___t*) l16)->f_size;
    while ((l3 < l7)) {
        vader_array_t* _a46_slotarr = ((vader_array_t*) l17);
        VADER_ARRAY_RESOLVE_BUF(_a46_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a46_slotarr, l3)
        l8 = ((int32_t*) _a46_slotarr->buf->slots)[_a46_slotarr->offset + (size_t) l3];
        vader_array_t* _a47_slotarr = ((vader_array_t*) l19);
        VADER_ARRAY_RESOLVE_BUF(_a47_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a47_slotarr, l3)
        l16 = vader_array_ref_load_obj(_a47_slotarr->buf, _a47_slotarr->offset + (size_t) l3);
        l10 = l8;
        l21 = l16;
        vader_array_t* _a48_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a48_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a48_slotarr, l10)
        l22 = ((int32_t*) _a48_slotarr->buf->slots)[_a48_slotarr->offset + (size_t) l10];
        if ((l22 >= INT32_C(0))) {
            std_collections$MutableMap$std_core$IndexSet$set_at__i32__Any(l4, l22, vader_ref_box(l21));
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
    vader_array_t* _a0_arr = vader_array_new(23u, 0u, 7u, 450u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(20u, 0u, 12u, 445u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(23u, 0u, 7u, 450u);
    l3 = (void*) _a2_arr;
    vader_struct_std_collections$MutableMap__i32__bool_t* _a3_obj = (vader_struct_std_collections$MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i32__bool_t));
    vader_obj_header_init(_a3_obj, 585u);
    _a3_obj->f_ekeys = l1;
    _a3_obj->f_evals = l2;
    _a3_obj->f_index = l3;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a3_obj;
    vader_struct_std_collections$MutableSet__i32_t* _a4_obj = (vader_struct_std_collections$MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableSet__i32_t));
    vader_obj_header_init(_a4_obj, 728u);
    _a4_obj->f_inner = t0;
    l1 = (void*) _a4_obj;
    l2 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_functions;
    l4 = ((vader_array_t*) l2)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a5_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        t0 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l5);
        l3 = ((vader_struct_vader_core_bytecode$BcFunction_t*) t0)->f_body;
        l6 = ((vader_array_t*) l3)->length;
        l7 = INT64_C(0);
        while ((l7 < l6)) {
            vader_array_t* _a6_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
            l8 = vader_array_ref_load_box(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l7);
            if (l8.tag == 913u) {
                t0 = l8.payload.obj;
                l9 = ((vader_struct_vader_core_bytecode$GlobalGet_t*) t0)->f_index;
                std_collections$add__i32(l1, l9);
            } else if (l8.tag == 914u) {
                t0 = l8.payload.obj;
                l10 = ((vader_struct_vader_core_bytecode$GlobalSet_t*) t0)->f_index;
                std_collections$add__i32(l1, l10);
            }
            l7 = (l7 + INT64_C(1));
        }
        l5 = (l5 + INT64_C(1));
    }
    l4 = std_collections$len__i32(l1);
    l5 = ((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_globals)->length;
    if (l4 == l5) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_array_t* _a7_arr = vader_array_new(23u, 0u, 7u, 450u);
    l2 = (void*) _a7_arr;
    vader_array_t* _a8_arr = vader_array_new(71u, 0u, 13u, 853u);
    l3 = (void*) _a8_arr;
    l4 = INT64_C(0);
    l5 = ((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_globals)->length;
    while ((l4 < l5)) {
        l9 = ((int32_t) (int64_t) l4);
        t1 = std_collections$MutableSet$std_core$Contains$contains__i32(l1, l9);
        if (t1) {
            t2 = ((vader_array_t*) l3)->length;
            l10 = ((int32_t) (int64_t) t2);
            vader_array_push_i32((vader_array_t*) l2, l10);
            vader_array_t* _a9_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_globals);
            VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l4)
            l11 = vader_array_ref_load_obj(_a9_slotarr->buf, _a9_slotarr->offset + (size_t) l4);
            vader_array_push_ref((vader_array_t*) l3, l11);
        } else {
            vader_array_push_i32((vader_array_t*) l2, INT32_C(-1));
        }
        l4 = (l4 + INT64_C(1));
    }
    l1 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_functions;
    l4 = ((vader_array_t*) l1)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a10_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
        l11 = vader_array_ref_load_obj(_a10_slotarr->buf, _a10_slotarr->offset + (size_t) l5);
        l6 = INT64_C(0);
        l7 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l11)->f_body)->length;
        while ((l6 < l7)) {
            vader_array_t* _a11_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l11)->f_body);
            VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l6)
            l8 = vader_array_ref_load_box(_a11_slotarr->buf, _a11_slotarr->offset + (size_t) l6);
            if (l8.tag == 913u) {
                l12 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l11)->f_body;
                t0 = l8.payload.obj;
                l9 = ((vader_struct_vader_core_bytecode$GlobalGet_t*) t0)->f_index;
                vader_array_t* _a12_slotarr = ((vader_array_t*) l2);
                VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a12_slotarr, l9)
                t3 = ((int32_t*) _a12_slotarr->buf->slots)[_a12_slotarr->offset + (size_t) l9];
                vader_struct_vader_core_bytecode$GlobalGet_t* _a13_obj = (vader_struct_vader_core_bytecode$GlobalGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$GlobalGet_t));
                vader_obj_header_init(_a13_obj, 913u);
                _a13_obj->f_index = t3;
                l13 = (void*) _a13_obj;
                vader_array_t* _a14_slotarr = ((vader_array_t*) l12);
                VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a14_slotarr, l6)
                vader_array_ref_store(_a14_slotarr->buf, _a14_slotarr->offset + (size_t) l6, l13);
                VADER_WRITE_BARRIER(_a14_slotarr->buf);
            } else if (l8.tag == 914u) {
                l14 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l11)->f_body;
                t0 = l8.payload.obj;
                l10 = ((vader_struct_vader_core_bytecode$GlobalSet_t*) t0)->f_index;
                vader_array_t* _a15_slotarr = ((vader_array_t*) l2);
                VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a15_slotarr, l10)
                t3 = ((int32_t*) _a15_slotarr->buf->slots)[_a15_slotarr->offset + (size_t) l10];
                vader_struct_vader_core_bytecode$GlobalSet_t* _a16_obj = (vader_struct_vader_core_bytecode$GlobalSet_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$GlobalSet_t));
                vader_obj_header_init(_a16_obj, 914u);
                _a16_obj->f_index = t3;
                l15 = (void*) _a16_obj;
                vader_array_t* _a17_slotarr = ((vader_array_t*) l14);
                VADER_ARRAY_RESOLVE_BUF(_a17_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a17_slotarr, l6)
                vader_array_ref_store(_a17_slotarr->buf, _a17_slotarr->offset + (size_t) l6, l15);
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
    vader_array_t* _a0_arr = vader_array_new(23u, 0u, 7u, 450u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(20u, 0u, 12u, 445u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(23u, 0u, 7u, 450u);
    l3 = (void*) _a2_arr;
    vader_struct_std_collections$MutableMap__i32__bool_t* _a3_obj = (vader_struct_std_collections$MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i32__bool_t));
    vader_obj_header_init(_a3_obj, 585u);
    _a3_obj->f_ekeys = l1;
    _a3_obj->f_evals = l2;
    _a3_obj->f_index = l3;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    l1 = (void*) _a3_obj;
    l2 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_functions;
    l4 = ((vader_array_t*) l2)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        t0 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l5);
        l3 = ((vader_struct_vader_core_bytecode$BcFunction_t*) t0)->f_body;
        l6 = ((vader_array_t*) l3)->length;
        l7 = INT64_C(0);
        while ((l7 < l6)) {
            vader_array_t* _a5_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
            l8 = vader_array_ref_load_box(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l7);
            if (l8.tag == 884u) {
                t0 = l8.payload.obj;
                l9 = ((vader_struct_vader_core_bytecode$CallImport_t*) t0)->f_index;
                std_collections$MutableMap$std_core$IndexSet$set_at__i32__bool(l1, l9, true);
            }
            l7 = (l7 + INT64_C(1));
        }
        l5 = (l5 + INT64_C(1));
    }
    l4 = std_collections$len__i32__bool(l1);
    l5 = ((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_imports)->length;
    if (l4 == l5) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_array_t* _a6_arr = vader_array_new(23u, 0u, 7u, 450u);
    l2 = (void*) _a6_arr;
    vader_array_t* _a7_arr = vader_array_new(72u, 0u, 13u, 854u);
    l3 = (void*) _a7_arr;
    l4 = INT64_C(0);
    l5 = ((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_imports)->length;
    while ((l4 < l5)) {
        l9 = ((int32_t) (int64_t) l4);
        t1 = std_collections$MutableMap$std_core$Index$at__i32__bool(l1, l9);
        if (t1.tag == 445u) {
            t2 = ((vader_array_t*) l3)->length;
            l10 = ((int32_t) (int64_t) t2);
            vader_array_push_i32((vader_array_t*) l2, l10);
            vader_array_t* _a8_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_imports);
            VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l4)
            l11 = vader_array_ref_load_obj(_a8_slotarr->buf, _a8_slotarr->offset + (size_t) l4);
            vader_array_push_ref((vader_array_t*) l3, l11);
        } else {
            vader_array_push_i32((vader_array_t*) l2, INT32_C(-1));
        }
        l4 = (l4 + INT64_C(1));
    }
    l1 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_functions;
    l4 = ((vader_array_t*) l1)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a9_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
        l11 = vader_array_ref_load_obj(_a9_slotarr->buf, _a9_slotarr->offset + (size_t) l5);
        l6 = INT64_C(0);
        l7 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l11)->f_body)->length;
        while ((l6 < l7)) {
            vader_array_t* _a10_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l11)->f_body);
            VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a10_slotarr, l6)
            l8 = vader_array_ref_load_box(_a10_slotarr->buf, _a10_slotarr->offset + (size_t) l6);
            if (l8.tag == 884u) {
                l12 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l11)->f_body;
                t0 = l8.payload.obj;
                l9 = ((vader_struct_vader_core_bytecode$CallImport_t*) t0)->f_index;
                vader_array_t* _a11_slotarr = ((vader_array_t*) l2);
                VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l9)
                t3 = ((int32_t*) _a11_slotarr->buf->slots)[_a11_slotarr->offset + (size_t) l9];
                vader_struct_vader_core_bytecode$CallImport_t* _a12_obj = (vader_struct_vader_core_bytecode$CallImport_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$CallImport_t));
                vader_obj_header_init(_a12_obj, 884u);
                _a12_obj->f_index = t3;
                l13 = (void*) _a12_obj;
                vader_array_t* _a13_slotarr = ((vader_array_t*) l12);
                VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a13_slotarr, l6)
                vader_array_ref_store(_a13_slotarr->buf, _a13_slotarr->offset + (size_t) l6, l13);
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
    void* l25 = NULL;
    int64_t l5, l6, l10, l11, l14, l15;
    int32_t l12, l16, l21;
    vader_box_t l17 = vader_box_null(), l18 = vader_box_null();
    vader_string_t l19 = 0;
    vader_string_t l20 = 0;
    vader_string_t l23 = 0;
    vader_string_t l24 = 0;
    bool l22;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    int32_t t2;
    bool t3;
    int64_t t4;
    vader_box_t* gc_roots[3] = { &l17, &l18, &t1 };
    void** gc_raw_roots[11] = { &l0, &l1, &l2, &l3, &l4, &l7, &l8, &l9, &l13, &l25, &t0 };
    vader_string_t* gc_atom_roots[4] = { &l19, &l20, &l23, &l24 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 11u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(23u, 0u, 7u, 450u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(20u, 0u, 12u, 445u);
    l3 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(23u, 0u, 7u, 450u);
    l4 = (void*) _a2_arr;
    vader_struct_std_collections$MutableMap__i32__bool_t* _a3_obj = (vader_struct_std_collections$MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i32__bool_t));
    vader_obj_header_init(_a3_obj, 585u);
    _a3_obj->f_ekeys = l2;
    _a3_obj->f_evals = l3;
    _a3_obj->f_index = l4;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a3_obj;
    vader_struct_std_collections$MutableSet__i32_t* _a4_obj = (vader_struct_std_collections$MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableSet__i32_t));
    vader_obj_header_init(_a4_obj, 728u);
    _a4_obj->f_inner = t0;
    l2 = (void*) _a4_obj;
    std_collections$add__i32(l2, INT32_C(0));
    vader_array_t* _a5_arr = vader_array_new(23u, 0u, 7u, 450u);
    l3 = (void*) _a5_arr;
    l4 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_functions;
    l5 = ((vader_array_t*) l4)->length;
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a6_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        l7 = vader_array_ref_load_obj(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l6);
        l8 = ((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l7)->f_signature)->f_result_types;
        vader_array_push_all((vader_array_t*) l3, (vader_array_t*) l8);
        l9 = ((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l7)->f_signature)->f_param_types;
        l10 = ((vader_array_t*) l9)->length;
        l11 = INT64_C(0);
        while ((l11 < l10)) {
            vader_array_t* _a7_slotarr = ((vader_array_t*) l9);
            VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
            l12 = ((int32_t*) _a7_slotarr->buf->slots)[_a7_slotarr->offset + (size_t) l11];
            vader_array_push_i32((vader_array_t*) l3, l12);
            l11 = (l11 + INT64_C(1));
        }
        l13 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l7)->f_body;
        l14 = ((vader_array_t*) l13)->length;
        l15 = INT64_C(0);
        while ((l15 < l14)) {
            vader_array_t* _a8_slotarr = ((vader_array_t*) l13);
            VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
            t1 = vader_array_ref_load_box(_a8_slotarr->buf, _a8_slotarr->offset + (size_t) l15);
            l16 = vader_emit_bytecode$type_index_of(t1);
            if ((l16 >= INT32_C(0))) {
                vader_array_push_i32((vader_array_t*) l3, l16);
            }
            l15 = (l15 + INT64_C(1));
        }
        l6 = (l6 + INT64_C(1));
    }
    l4 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_imports;
    l5 = ((vader_array_t*) l4)->length;
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a9_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
        l7 = vader_array_ref_load_obj(_a9_slotarr->buf, _a9_slotarr->offset + (size_t) l6);
        l8 = ((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcImport_t*) l7)->f_signature)->f_result_types;
        vader_array_push_all((vader_array_t*) l3, (vader_array_t*) l8);
        l9 = ((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcImport_t*) l7)->f_signature)->f_param_types;
        l10 = ((vader_array_t*) l9)->length;
        l11 = INT64_C(0);
        while ((l11 < l10)) {
            vader_array_t* _a10_slotarr = ((vader_array_t*) l9);
            VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
            l12 = ((int32_t*) _a10_slotarr->buf->slots)[_a10_slotarr->offset + (size_t) l11];
            vader_array_push_i32((vader_array_t*) l3, l12);
            l11 = (l11 + INT64_C(1));
        }
        l6 = (l6 + INT64_C(1));
    }
    l4 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_globals;
    l5 = ((vader_array_t*) l4)->length;
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a11_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
        t0 = vader_array_ref_load_obj(_a11_slotarr->buf, _a11_slotarr->offset + (size_t) l6);
        l12 = ((vader_struct_vader_core_bytecode$BcGlobal_t*) t0)->f_type_id;
        vader_array_push_i32((vader_array_t*) l3, l12);
        l6 = (l6 + INT64_C(1));
    }
    l4 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_pinned_types;
    l5 = ((vader_array_t*) l4)->length;
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a12_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
        l12 = ((int32_t*) _a12_slotarr->buf->slots)[_a12_slotarr->offset + (size_t) l6];
        vader_array_push_i32((vader_array_t*) l3, l12);
        l6 = (l6 + INT64_C(1));
    }
    l4 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_pinned_types_by_fn;
    l7 = ((vader_struct_std_collections$MutableMap__i32__i32___t*) l4)->f_ekeys;
    l8 = ((vader_struct_std_collections$MutableMap__i32__i32___t*) l4)->f_evals;
    l5 = INT64_C(0);
    l6 = ((vader_struct_std_collections$MutableMap__i32__i32___t*) l4)->f_size;
    while ((l5 < l6)) {
        vader_array_t* _a13_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a13_slotarr, l5)
        t2 = ((int32_t*) _a13_slotarr->buf->slots)[_a13_slotarr->offset + (size_t) l5];
        vader_array_t* _a14_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a14_slotarr, l5)
        l4 = vader_array_ref_load_obj(_a14_slotarr->buf, _a14_slotarr->offset + (size_t) l5);
        l10 = ((vader_array_t*) l4)->length;
        l11 = INT64_C(0);
        while ((l11 < l10)) {
            vader_array_t* _a15_slotarr = ((vader_array_t*) l4);
            VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
            l12 = ((int32_t*) _a15_slotarr->buf->slots)[_a15_slotarr->offset + (size_t) l11];
            vader_array_push_i32((vader_array_t*) l3, l12);
            l11 = (l11 + INT64_C(1));
        }
        l5 = (l5 + INT64_C(1));
    }
    l4 = vader_emit_bytecode$data_pool_type_roots(l0, l1);
    vader_array_push_all((vader_array_t*) l3, (vader_array_t*) l4);
    l5 = ((vader_array_t*) l3)->length;
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a16_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a16_slotarr)
        t2 = ((int32_t*) _a16_slotarr->buf->slots)[_a16_slotarr->offset + (size_t) l6];
        vader_emit_bytecode$visit_type(t2, l0, l2);
        l6 = (l6 + INT64_C(1));
    }
    l5 = std_collections$len__i32(l2);
    l6 = ((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_types)->length;
    if (l5 == l6) {
        { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l5 = ((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_types)->length;
    vader_array_t* _a17_arr = vader_array_new(23u, 0u, 7u, 450u);
    l3 = (void*) _a17_arr;
    vader_array_t* _a18_arr = vader_array_new(360u, 0u, 13u, 1827u);
    l4 = (void*) _a18_arr;
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        l12 = ((int32_t) (int64_t) l6);
        t3 = std_collections$MutableSet$std_core$Contains$contains__i32(l2, l12);
        if (t3) {
            t4 = ((vader_array_t*) l4)->length;
            l16 = ((int32_t) (int64_t) t4);
            vader_array_push_i32((vader_array_t*) l3, l16);
            vader_array_t* _a19_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_types);
            VADER_ARRAY_RESOLVE_BUF(_a19_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a19_slotarr, l6)
            l17 = vader_array_ref_load_box(_a19_slotarr->buf, _a19_slotarr->offset + (size_t) l6);
            vader_array_push_ref((vader_array_t*) l4, l17.payload.obj);
        } else {
            vader_array_push_i32((vader_array_t*) l3, INT32_C(-1));
        }
        l6 = (l6 + INT64_C(1));
    }
    l2 = l4;
    vader_struct___lambda_env_vader_emit_bytecode_2_t* _a20_obj = (vader_struct___lambda_env_vader_emit_bytecode_2_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_emit_bytecode_2_t));
    vader_obj_header_init(_a20_obj, 477u);
    _a20_obj->f_cap_0 = l3;
    l4 = (void*) _a20_obj;
    vader_array_t* _a21_arr = vader_array_new(360u, 0u, 13u, 1827u);
    l7 = (void*) _a21_arr;
    l5 = ((vader_array_t*) l2)->length;
    vader_array_t* _a22_arr = vader_array_repeat((vader_array_t*) l7, (int64_t) l5);
    l7 = (void*) _a22_arr;
    l5 = ((vader_array_t*) l2)->length;
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a23_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a23_slotarr)
        l17 = vader_array_ref_load_box(_a23_slotarr->buf, _a23_slotarr->offset + (size_t) l6);
        l18 = __lambda_vader_emit_bytecode_1(l4, l17);
        vader_array_push_ref((vader_array_t*) l7, l18.payload.obj);
        l6 = (l6 + INT64_C(1));
    }
    ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_types = l7;
    VADER_WRITE_BARRIER((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0);
    vader_array_t* _a24_arr = vader_array_new(22u, 0u, 0u, 447u);
    l2 = (void*) _a24_arr;
    vader_array_t* _a25_arr = vader_array_new(23u, 0u, 7u, 450u);
    l4 = (void*) _a25_arr;
    vader_array_t* _a26_arr = vader_array_new(23u, 0u, 7u, 450u);
    l7 = (void*) _a26_arr;
    vader_struct_std_collections$MutableMap__string__i32_t* _a27_obj = (vader_struct_std_collections$MutableMap__string__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__string__i32_t));
    vader_obj_header_init(_a27_obj, 663u);
    _a27_obj->f_ekeys = l2;
    _a27_obj->f_evals = l4;
    _a27_obj->f_index = l7;
    _a27_obj->f_mask = INT64_C(0);
    _a27_obj->f_grow_at = INT64_C(0);
    _a27_obj->f_size = INT64_C(0);
    _a27_obj->f_tombs = INT64_C(0);
    l2 = (void*) _a27_obj;
    l4 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_type_key;
    l7 = ((vader_struct_std_collections$MutableMap__string__i32_t*) l4)->f_ekeys;
    l8 = ((vader_struct_std_collections$MutableMap__string__i32_t*) l4)->f_evals;
    l5 = INT64_C(0);
    l6 = ((vader_struct_std_collections$MutableMap__string__i32_t*) l4)->f_size;
    while ((l5 < l6)) {
        vader_array_t* _a28_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a28_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a28_slotarr, l5)
        t1 = vader_array_box_slots(_a28_slotarr->buf)[_a28_slotarr->offset + (size_t) l5];
        l19 = t1.payload.s;
        vader_array_t* _a29_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a29_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a29_slotarr, l5)
        l12 = ((int32_t*) _a29_slotarr->buf->slots)[_a29_slotarr->offset + (size_t) l5];
        l20 = l19;
        l16 = l12;
        l21 = vader_emit_bytecode$remap_idx(l3, l16);
        if ((l21 >= INT32_C(0))) {
            std_collections$MutableMap$std_core$IndexSet$set_at__string__i32(l2, l20, l21);
        }
        l5 = (l5 + INT64_C(1));
    }
    ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_type_key = l2;
    VADER_WRITE_BARRIER((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0);
    l2 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_functions;
    l5 = ((vader_array_t*) l2)->length;
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a30_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a30_slotarr)
        l4 = vader_array_ref_load_obj(_a30_slotarr->buf, _a30_slotarr->offset + (size_t) l6);
        l7 = vader_emit_bytecode$remap_signature(((vader_struct_vader_core_bytecode$BcFunction_t*) l4)->f_signature, l3);
        ((vader_struct_vader_core_bytecode$BcFunction_t*) l4)->f_signature = l7;
        VADER_WRITE_BARRIER((vader_struct_vader_core_bytecode$BcFunction_t*) l4);
        l10 = INT64_C(0);
        l11 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l4)->f_body)->length;
        while ((l10 < l11)) {
            l8 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l4)->f_body;
            vader_array_t* _a31_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l4)->f_body);
            VADER_ARRAY_RESOLVE_BUF(_a31_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a31_slotarr, l10)
            t1 = vader_array_ref_load_box(_a31_slotarr->buf, _a31_slotarr->offset + (size_t) l10);
            l17 = vader_emit_bytecode$remap_type_in_op(t1, l3);
            vader_array_t* _a32_slotarr = ((vader_array_t*) l8);
            VADER_ARRAY_RESOLVE_BUF(_a32_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a32_slotarr, l10)
            vader_array_ref_store(_a32_slotarr->buf, _a32_slotarr->offset + (size_t) l10, l17.payload.obj);
            VADER_WRITE_BARRIER(_a32_slotarr->buf);
            l10 = (l10 + INT64_C(1));
        }
        l6 = (l6 + INT64_C(1));
    }
    vader_array_t* _a33_arr = vader_array_new(72u, 0u, 13u, 854u);
    l2 = (void*) _a33_arr;
    l5 = ((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_imports)->length;
    vader_array_t* _a34_arr = vader_array_repeat((vader_array_t*) l2, (int64_t) l5);
    l2 = (void*) _a34_arr;
    l4 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_imports;
    l5 = ((vader_array_t*) l4)->length;
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a35_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a35_slotarr)
        l7 = vader_array_ref_load_obj(_a35_slotarr->buf, _a35_slotarr->offset + (size_t) l6);
        l8 = l7;
        l19 = ((vader_struct_vader_core_bytecode$BcImport_t*) l8)->f_extern_name;
        l20 = ((vader_struct_vader_core_bytecode$BcImport_t*) l8)->f_mangled_name;
        l9 = vader_emit_bytecode$remap_signature(((vader_struct_vader_core_bytecode$BcImport_t*) l7)->f_signature, l3);
        l22 = ((vader_struct_vader_core_bytecode$BcImport_t*) l8)->f_is_extern;
        l23 = ((vader_struct_vader_core_bytecode$BcImport_t*) l8)->f_c_header;
        l17 = ((vader_struct_vader_core_bytecode$BcImport_t*) l8)->f_library;
        l12 = ((vader_struct_vader_core_bytecode$BcImport_t*) l8)->f_c_variadic_fixed;
        l13 = ((vader_struct_vader_core_bytecode$BcImport_t*) l8)->f_param_c_types;
        l24 = ((vader_struct_vader_core_bytecode$BcImport_t*) l8)->f_result_c_type;
        vader_struct_vader_core_bytecode$BcImport_t* _a36_obj = (vader_struct_vader_core_bytecode$BcImport_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcImport_t));
        vader_obj_header_init(_a36_obj, 854u);
        _a36_obj->f_extern_name = l19;
        _a36_obj->f_mangled_name = l20;
        _a36_obj->f_signature = l9;
        _a36_obj->f_is_extern = l22;
        _a36_obj->f_c_header = l23;
        _a36_obj->f_library = l17;
        _a36_obj->f_c_variadic_fixed = l12;
        _a36_obj->f_param_c_types = l13;
        _a36_obj->f_result_c_type = l24;
        l25 = (void*) _a36_obj;
        vader_array_push_ref((vader_array_t*) l2, l25);
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
    t0 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_slot)->f_body)->length;
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
    l3 = ((vader_array_t*) l0)->length;
    if (l1 == l3) {
        vader_array_push_ref((vader_array_t*) l0, l2.payload.obj);
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    vader_array_ref_store(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l1, l2.payload.obj);
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
    l5 = ((vader_array_t*) l0)->length;
    if (l2 == l5) {
        vader_array_push_scalar((vader_array_t*) l0, vader_box_string(447u, l3));
        vader_array_push_i32((vader_array_t*) l1, l4);
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
    vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l2] = vader_box_string(447u, l3);
    vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l2)
    ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l2] = (int32_t) l4;
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
    l3 = ((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_type_by_slot)->length;
    l4 = ((int64_t) (int32_t) l1);
    l5 = (l3 <= l4);
    while (l5) {
        l6 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_type_by_slot;
        t0 = (void*) &vader_data_17;
        vader_array_t* _a0_slotarr = ((vader_array_t*) t0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l7 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT64_C(0));
        vader_array_push_ref((vader_array_t*) l6, l7);
        l5 = (l3 < l4);
        l3 = (l3 + INT64_C(1));
    }
    vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_type_by_slot);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l1)
    vader_array_ref_store(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l1, l2.payload.obj);
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
    if (l1.tag == 1041u) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_vader_core_types$UnionType_t*) t0)->f_variants;
        l3 = ((vader_array_t*) l2)->length;
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            l5 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
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
    if (!(l1.tag == 1033u)) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    t0 = l1.payload.obj;
    l2 = ((vader_struct_vader_core_types$StructType_t*) t0)->f_args;
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
    for (;;) {
        if ((l4 < l3)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            l5 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
            t1 = vader_core_types$kept_type_argument(l5);
            if (t1.tag == 0u) {
                t0 = l1.payload.obj;
                l6 = vader_core_types$display_type(vader_ref_box(t0));
                l7 = concat_5(1680u, l0, 1248u, l6, 1279u);
                l8 = vader_core_types$display_type(l5);
                l9 = concat_3(2033u, l8, 1033u);
                t2 = concat_3(l7, 1540u, l9);
                vader_host_std_abort$panic(t2);
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
    if (!(l0.tag == 847u)) {
        { vader_box_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l0.payload.obj;
    t1 = vader_emit_bytecode$remap_data_values(((vader_struct_vader_core_bytecode$BcAggregateData_t*) t0)->f_elements, l1);
    vader_struct_vader_core_bytecode$BcAggregateData_t* _a0_obj = (vader_struct_vader_core_bytecode$BcAggregateData_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcAggregateData_t));
    vader_obj_header_init(_a0_obj, 847u);
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
    vader_box_t* gc_roots[2] = { &l7, &l8 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = l0;
    vader_struct___lambda_env_vader_emit_bytecode_6_t* _a0_obj = (vader_struct___lambda_env_vader_emit_bytecode_6_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_emit_bytecode_6_t));
    vader_obj_header_init(_a0_obj, 479u);
    _a0_obj->f_cap_0 = l1;
    l3 = (void*) _a0_obj;
    vader_array_t* _a1_arr = vader_array_new(359u, 0u, 13u, 1826u);
    l4 = (void*) _a1_arr;
    l5 = ((vader_array_t*) l2)->length;
    vader_array_t* _a2_arr = vader_array_repeat((vader_array_t*) l4, (int64_t) l5);
    l4 = (void*) _a2_arr;
    l5 = ((vader_array_t*) l2)->length;
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        l7 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l6);
        l8 = __lambda_vader_emit_bytecode_5(l3, l7);
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
    if (l0.tag == 866u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_core_bytecode$BcValStruct_t*) t0)->f_symbol_id;
        t0 = l0.payload.obj;
        l4 = vader_emit_bytecode$remap_data_values(((vader_struct_vader_core_bytecode$BcValStruct_t*) t0)->f_fields, l1);
        vader_struct_vader_core_bytecode$BcValStruct_t* _a0_obj = (vader_struct_vader_core_bytecode$BcValStruct_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcValStruct_t));
        vader_obj_header_init(_a0_obj, 866u);
        _a0_obj->f_symbol_id = l3;
        _a0_obj->f_fields = l4;
        t0 = (void*) _a0_obj;
        l2 = vader_ref_box(t0);
        { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 863u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_core_bytecode$BcValArray_t*) t0)->f_type_id;
        l3 = vader_emit_bytecode$remap_idx(l1, l3);
        t0 = l0.payload.obj;
        l4 = vader_emit_bytecode$remap_data_values(((vader_struct_vader_core_bytecode$BcValArray_t*) t0)->f_elements, l1);
        vader_struct_vader_core_bytecode$BcValArray_t* _a1_obj = (vader_struct_vader_core_bytecode$BcValArray_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcValArray_t));
        vader_obj_header_init(_a1_obj, 863u);
        _a1_obj->f_type_id = l3;
        _a1_obj->f_elements = l4;
        t0 = (void*) _a1_obj;
        l2 = vader_ref_box(t0);
    } else {
        if (!((l0.tag == 864u || l0.tag == 865u))) {
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
    vader_box_t* gc_roots[2] = { &l7, &l8 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = l0;
    vader_struct___lambda_env_vader_emit_bytecode_10_t* _a0_obj = (vader_struct___lambda_env_vader_emit_bytecode_10_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_emit_bytecode_10_t));
    vader_obj_header_init(_a0_obj, 474u);
    _a0_obj->f_cap_0 = l1;
    l3 = (void*) _a0_obj;
    vader_array_t* _a1_arr = vader_array_new(361u, 0u, 13u, 1837u);
    l4 = (void*) _a1_arr;
    l5 = ((vader_array_t*) l2)->length;
    vader_array_t* _a2_arr = vader_array_repeat((vader_array_t*) l4, (int64_t) l5);
    l4 = (void*) _a2_arr;
    l5 = ((vader_array_t*) l2)->length;
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        l7 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l6);
        l8 = __lambda_vader_emit_bytecode_9(l3, l7);
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
    vader_array_t* _a0_arr = vader_array_new(362u, 1u, 13u, 1863u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = vader_box_obj(0u, NULL).payload.obj;
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l2);
    l3 = (void*) _a1_arr;
    l4 = INT64_C(0);
    l5 = ((vader_array_t*) l0)->length;
    while ((l4 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        l6 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l4];
        if ((l6 < INT32_C(0))) {
            l4 = (l4 + INT64_C(1));
            continue;
        }
        l7 = ((int64_t) (int32_t) l6);
        if ((l7 < l2)) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l7)
            t1 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l7);
            if (t1.tag == 0u) {
                vader_array_t* _a4_slotarr = ((vader_array_t*) l0);
                VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                l8 = vader_array_ref_load_box(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l4);
                vader_array_t* _a5_slotarr = ((vader_array_t*) l3);
                VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l7)
                vader_array_ref_store(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l7, l8.payload.obj);
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
    void** gc_raw_roots[7] = { &l0, &l1, &l2, &l3, &l4, &l7, &l8 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 7u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = l0;
    vader_struct___lambda_env_vader_emit_bytecode_4_t* _a0_obj = (vader_struct___lambda_env_vader_emit_bytecode_4_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_emit_bytecode_4_t));
    vader_obj_header_init(_a0_obj, 478u);
    _a0_obj->f_cap_0 = l1;
    l3 = (void*) _a0_obj;
    vader_array_t* _a1_arr = vader_array_new(71u, 0u, 13u, 853u);
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
        l8 = __lambda_vader_emit_bytecode_3(l3, l7);
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
    l3 = ((vader_array_t*) l0)->length;
    if (!((l2 >= l3))) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
        t0 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l1];
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
    if (!(l0.tag == 841u)) {
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
        l4 = ((vader_array_t*) l1)->length;
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
        l6 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l6];
        vader_struct_vader_core_bytecode$ArrayPush_t* _a1_obj = (vader_struct_vader_core_bytecode$ArrayPush_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$ArrayPush_t));
        vader_obj_header_init(_a1_obj, 841u);
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
    vader_obj_header_init(_a0_obj, 859u);
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
    void* t0 = NULL;
    int32_t t1;
    vader_box_t* gc_roots[2] = { &l0, &l2 };
    void** gc_raw_roots[6] = { &l1, &l3, &l4, &l7, &l11, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l8, &l12 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if ((l0.tag == 857u || l0.tag == 858u)) {
        l2 = l0;
        { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 861u) {
        vader_array_t* _a0_arr = vader_array_new(69u, 0u, 13u, 850u);
        l3 = (void*) _a0_arr;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_core_bytecode$BcStruct_t*) t0)->f_fields;
        l5 = ((vader_array_t*) l4)->length;
        l6 = INT64_C(0);
        while ((l6 < l5)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l4);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            l7 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l6);
            l8 = ((vader_struct_vader_core_bytecode$BcField_t*) l7)->f_name;
            l9 = ((vader_struct_vader_core_bytecode$BcField_t*) l7)->f_type_index;
            l10 = vader_emit_bytecode$remap_idx(l1, l9);
            vader_struct_vader_core_bytecode$BcField_t* _a2_obj = (vader_struct_vader_core_bytecode$BcField_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcField_t));
            vader_obj_header_init(_a2_obj, 850u);
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
        vader_struct_vader_core_bytecode$BcStruct_t* _a3_obj = (vader_struct_vader_core_bytecode$BcStruct_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcStruct_t));
        vader_obj_header_init(_a3_obj, 861u);
        _a3_obj->f_name = l8;
        _a3_obj->f_fields = l3;
        _a3_obj->f_c_name = l12;
        _a3_obj->f_symbol_id = l9;
        t0 = (void*) _a3_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 848u) {
        t0 = l0.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$BcArray_t*) t0)->f_element;
        t1 = vader_emit_bytecode$remap_idx(l1, l9);
        vader_struct_vader_core_bytecode$BcArray_t* _a4_obj = (vader_struct_vader_core_bytecode$BcArray_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcArray_t));
        vader_obj_header_init(_a4_obj, 848u);
        _a4_obj->f_element = t1;
        t0 = (void*) _a4_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 862u) {
        vader_array_t* _a5_arr = vader_array_new(23u, 0u, 7u, 450u);
        l3 = (void*) _a5_arr;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_core_bytecode$BcUnion_t*) t0)->f_variants;
        l5 = ((vader_array_t*) l4)->length;
        l6 = INT64_C(0);
        vader_array_t* _pc99_hdr = (vader_array_t*) l3;
        size_t _pc99_len = _pc99_hdr->length;
        size_t _pc99_cap = (_pc99_hdr->offset == 0 && !vader_array_is_borrowed(_pc99_hdr) && _pc99_hdr->length >= _pc99_hdr->buf->length) ? _pc99_hdr->capacity : (size_t) 0;
        void* _pc99_slots = _pc99_hdr->buf->slots;
        for (;;) {
            if ((l6 < l5)) {
                vader_array_t* _a6_slotarr = ((vader_array_t*) l4);
                VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
                l9 = ((int32_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l6];
                l10 = vader_emit_bytecode$remap_idx(l1, l9);
                if (VADER_LIKELY(_pc99_len < _pc99_cap)) {
                    ((int32_t*) _pc99_slots)[_pc99_len] = (int32_t) (l10);
                    _pc99_len += 1;
                } else {
                    _pc99_hdr->length = _pc99_len;
                    if (_pc99_hdr->buf->length < _pc99_len) {
                        _pc99_hdr->buf->length = _pc99_len;
                    }
                    vader_array_push_i32((vader_array_t*) l3, l10);
                    _pc99_hdr = (vader_array_t*) l3;
                    _pc99_len = _pc99_hdr->length;
                    _pc99_cap = (_pc99_hdr->offset == 0 && !vader_array_is_borrowed(_pc99_hdr) && _pc99_hdr->length >= _pc99_hdr->buf->length) ? _pc99_hdr->capacity : (size_t) 0;
                    _pc99_slots = _pc99_hdr->buf->slots;
                }
                l6 = (l6 + INT64_C(1));
                continue;
            }
            _pc99_hdr->length = _pc99_len;
            if (_pc99_hdr->buf->length < _pc99_len) {
                _pc99_hdr->buf->length = _pc99_len;
            }
            break;
        }
        vader_struct_vader_core_bytecode$BcUnion_t* _a7_obj = (vader_struct_vader_core_bytecode$BcUnion_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcUnion_t));
        vader_obj_header_init(_a7_obj, 862u);
        _a7_obj->f_variants = l3;
        t0 = (void*) _a7_obj;
        l2 = vader_ref_box(t0);
    } else {
        if (!(l0.tag == 851u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        vader_array_t* _a8_arr = vader_array_new(23u, 0u, 7u, 450u);
        l3 = (void*) _a8_arr;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_core_bytecode$BcFn_t*) t0)->f_params;
        l5 = ((vader_array_t*) l4)->length;
        l6 = INT64_C(0);
        vader_array_t* _pc142_hdr = (vader_array_t*) l3;
        size_t _pc142_len = _pc142_hdr->length;
        size_t _pc142_cap = (_pc142_hdr->offset == 0 && !vader_array_is_borrowed(_pc142_hdr) && _pc142_hdr->length >= _pc142_hdr->buf->length) ? _pc142_hdr->capacity : (size_t) 0;
        void* _pc142_slots = _pc142_hdr->buf->slots;
        for (;;) {
            if ((l6 < l5)) {
                vader_array_t* _a9_slotarr = ((vader_array_t*) l4);
                VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
                l9 = ((int32_t*) _a9_slotarr->buf->slots)[_a9_slotarr->offset + (size_t) l6];
                l10 = vader_emit_bytecode$remap_idx(l1, l9);
                if (VADER_LIKELY(_pc142_len < _pc142_cap)) {
                    ((int32_t*) _pc142_slots)[_pc142_len] = (int32_t) (l10);
                    _pc142_len += 1;
                } else {
                    _pc142_hdr->length = _pc142_len;
                    if (_pc142_hdr->buf->length < _pc142_len) {
                        _pc142_hdr->buf->length = _pc142_len;
                    }
                    vader_array_push_i32((vader_array_t*) l3, l10);
                    _pc142_hdr = (vader_array_t*) l3;
                    _pc142_len = _pc142_hdr->length;
                    _pc142_cap = (_pc142_hdr->offset == 0 && !vader_array_is_borrowed(_pc142_hdr) && _pc142_hdr->length >= _pc142_hdr->buf->length) ? _pc142_hdr->capacity : (size_t) 0;
                    _pc142_slots = _pc142_hdr->buf->slots;
                }
                l6 = (l6 + INT64_C(1));
                continue;
            }
            _pc142_hdr->length = _pc142_len;
            if (_pc142_hdr->buf->length < _pc142_len) {
                _pc142_hdr->buf->length = _pc142_len;
            }
            break;
        }
        t0 = l0.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$BcFn_t*) t0)->f_return_type;
        l9 = vader_emit_bytecode$remap_idx(l1, l9);
        vader_struct_vader_core_bytecode$BcFn_t* _a10_obj = (vader_struct_vader_core_bytecode$BcFn_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcFn_t));
        vader_obj_header_init(_a10_obj, 851u);
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
    if (l0.tag == 991u) {
        l3 = l0.payload.obj;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_core_bytecode$StructNew_t*) t0)->f_type_id;
        l4 = vader_emit_bytecode$remap_idx(l1, l4);
        l5 = ((vader_struct_vader_core_bytecode$StructNew_t*) l3)->f_stack;
        vader_struct_vader_core_bytecode$StructNew_t* _a0_obj = (vader_struct_vader_core_bytecode$StructNew_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$StructNew_t));
        vader_obj_header_init(_a0_obj, 991u);
        _a0_obj->f_type_id = l4;
        _a0_obj->f_stack = l5;
        t0 = (void*) _a0_obj;
        l2 = vader_ref_box(t0);
        { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 990u) {
        l3 = l0.payload.obj;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_core_bytecode$StructGet_t*) t0)->f_type_id;
        l4 = vader_emit_bytecode$remap_idx(l1, l4);
        l6 = ((vader_struct_vader_core_bytecode$StructGet_t*) l3)->f_field_index;
        vader_struct_vader_core_bytecode$StructGet_t* _a1_obj = (vader_struct_vader_core_bytecode$StructGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$StructGet_t));
        vader_obj_header_init(_a1_obj, 990u);
        _a1_obj->f_type_id = l4;
        _a1_obj->f_field_index = l6;
        t0 = (void*) _a1_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 992u) {
        l3 = l0.payload.obj;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_core_bytecode$StructSet_t*) t0)->f_type_id;
        l4 = vader_emit_bytecode$remap_idx(l1, l4);
        l6 = ((vader_struct_vader_core_bytecode$StructSet_t*) l3)->f_field_index;
        l5 = ((vader_struct_vader_core_bytecode$StructSet_t*) l3)->f_stack;
        vader_struct_vader_core_bytecode$StructSet_t* _a2_obj = (vader_struct_vader_core_bytecode$StructSet_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$StructSet_t));
        vader_obj_header_init(_a2_obj, 992u);
        _a2_obj->f_type_id = l4;
        _a2_obj->f_field_index = l6;
        _a2_obj->f_stack = l5;
        t0 = (void*) _a2_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1007u) {
        l3 = l0.payload.obj;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_core_bytecode$UnionFieldGet_t*) t0)->f_type_id;
        l4 = vader_emit_bytecode$remap_idx(l1, l4);
        l6 = ((vader_struct_vader_core_bytecode$UnionFieldGet_t*) l3)->f_field_index;
        vader_struct_vader_core_bytecode$UnionFieldGet_t* _a3_obj = (vader_struct_vader_core_bytecode$UnionFieldGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$UnionFieldGet_t));
        vader_obj_header_init(_a3_obj, 1007u);
        _a3_obj->f_type_id = l4;
        _a3_obj->f_field_index = l6;
        t0 = (void*) _a3_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1008u) {
        l3 = l0.payload.obj;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_core_bytecode$UnionFieldSet_t*) t0)->f_type_id;
        l4 = vader_emit_bytecode$remap_idx(l1, l4);
        l6 = ((vader_struct_vader_core_bytecode$UnionFieldSet_t*) l3)->f_field_index;
        vader_struct_vader_core_bytecode$UnionFieldSet_t* _a4_obj = (vader_struct_vader_core_bytecode$UnionFieldSet_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$UnionFieldSet_t));
        vader_obj_header_init(_a4_obj, 1008u);
        _a4_obj->f_type_id = l4;
        _a4_obj->f_field_index = l6;
        t0 = (void*) _a4_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 840u) {
        l3 = l0.payload.obj;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_core_bytecode$ArrayNew_t*) t0)->f_type_id;
        l4 = vader_emit_bytecode$remap_idx(l1, l4);
        l6 = ((vader_struct_vader_core_bytecode$ArrayNew_t*) l3)->f_length;
        vader_struct_vader_core_bytecode$ArrayNew_t* _a5_obj = (vader_struct_vader_core_bytecode$ArrayNew_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$ArrayNew_t));
        vader_obj_header_init(_a5_obj, 840u);
        _a5_obj->f_type_id = l4;
        _a5_obj->f_length = l6;
        t0 = (void*) _a5_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 838u) {
        l3 = l0.payload.obj;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_core_bytecode$ArrayGet_t*) t0)->f_type_id;
        l4 = vader_emit_bytecode$remap_idx(l1, l4);
        l5 = ((vader_struct_vader_core_bytecode$ArrayGet_t*) l3)->f_bounds_safe;
        vader_struct_vader_core_bytecode$ArrayGet_t* _a6_obj = (vader_struct_vader_core_bytecode$ArrayGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$ArrayGet_t));
        vader_obj_header_init(_a6_obj, 838u);
        _a6_obj->f_type_id = l4;
        _a6_obj->f_bounds_safe = l5;
        t0 = (void*) _a6_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 845u) {
        l3 = l0.payload.obj;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_core_bytecode$ArraySet_t*) t0)->f_type_id;
        l4 = vader_emit_bytecode$remap_idx(l1, l4);
        l5 = ((vader_struct_vader_core_bytecode$ArraySet_t*) l3)->f_bounds_safe;
        vader_struct_vader_core_bytecode$ArraySet_t* _a7_obj = (vader_struct_vader_core_bytecode$ArraySet_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$ArraySet_t));
        vader_obj_header_init(_a7_obj, 845u);
        _a7_obj->f_type_id = l4;
        _a7_obj->f_bounds_safe = l5;
        t0 = (void*) _a7_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 841u) {
        l3 = l0.payload.obj;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_core_bytecode$ArrayPush_t*) t0)->f_type_id;
        l4 = vader_emit_bytecode$remap_idx(l1, l4);
        l6 = ((vader_struct_vader_core_bytecode$ArrayPush_t*) l3)->f_cache_slot;
        vader_struct_vader_core_bytecode$ArrayPush_t* _a8_obj = (vader_struct_vader_core_bytecode$ArrayPush_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$ArrayPush_t));
        vader_obj_header_init(_a8_obj, 841u);
        _a8_obj->f_type_id = l4;
        _a8_obj->f_cache_slot = l6;
        t0 = (void*) _a8_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 993u) {
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_core_bytecode$TypeCheck_t*) t0)->f_type_id;
        t1 = vader_emit_bytecode$remap_idx(l1, l4);
        vader_struct_vader_core_bytecode$TypeCheck_t* _a9_obj = (vader_struct_vader_core_bytecode$TypeCheck_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$TypeCheck_t));
        vader_obj_header_init(_a9_obj, 993u);
        _a9_obj->f_type_id = t1;
        t0 = (void*) _a9_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 994u) {
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_core_bytecode$TypeConst_t*) t0)->f_type_id;
        t1 = vader_emit_bytecode$remap_idx(l1, l4);
        vader_struct_vader_core_bytecode$TypeConst_t* _a10_obj = (vader_struct_vader_core_bytecode$TypeConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$TypeConst_t));
        vader_obj_header_init(_a10_obj, 994u);
        _a10_obj->f_type_id = t1;
        t0 = (void*) _a10_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 885u) {
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_core_bytecode$CallIndirect_t*) t0)->f_type_id;
        t1 = vader_emit_bytecode$remap_idx(l1, l4);
        vader_struct_vader_core_bytecode$CallIndirect_t* _a11_obj = (vader_struct_vader_core_bytecode$CallIndirect_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$CallIndirect_t));
        vader_obj_header_init(_a11_obj, 885u);
        _a11_obj->f_type_id = t1;
        t0 = (void*) _a11_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 969u) {
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_core_bytecode$MakeClosure_t*) t0)->f_function_index;
        t0 = l0.payload.obj;
        l6 = ((vader_struct_vader_core_bytecode$MakeClosure_t*) t0)->f_env_type_id;
        l6 = vader_emit_bytecode$remap_idx(l1, l6);
        vader_struct_vader_core_bytecode$MakeClosure_t* _a12_obj = (vader_struct_vader_core_bytecode$MakeClosure_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$MakeClosure_t));
        vader_obj_header_init(_a12_obj, 969u);
        _a12_obj->f_function_index = l4;
        _a12_obj->f_env_type_id = l6;
        t0 = (void*) _a12_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 912u) {
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_core_bytecode$FnRef_t*) t0)->f_function_index;
        t0 = l0.payload.obj;
        l6 = ((vader_struct_vader_core_bytecode$FnRef_t*) t0)->f_type_id;
        l6 = vader_emit_bytecode$remap_idx(l1, l6);
        vader_struct_vader_core_bytecode$FnRef_t* _a13_obj = (vader_struct_vader_core_bytecode$FnRef_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$FnRef_t));
        vader_obj_header_init(_a13_obj, 912u);
        _a13_obj->f_function_index = l4;
        _a13_obj->f_type_id = l6;
        t0 = (void*) _a13_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 964u) {
        l3 = l0.payload.obj;
        l4 = ((vader_struct_vader_core_bytecode$LocalField_t*) l3)->f_slot;
        t0 = l0.payload.obj;
        l6 = ((vader_struct_vader_core_bytecode$LocalField_t*) t0)->f_type_id;
        l6 = vader_emit_bytecode$remap_idx(l1, l6);
        l7 = ((vader_struct_vader_core_bytecode$LocalField_t*) l3)->f_field_index;
        vader_struct_vader_core_bytecode$LocalField_t* _a14_obj = (vader_struct_vader_core_bytecode$LocalField_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$LocalField_t));
        vader_obj_header_init(_a14_obj, 964u);
        _a14_obj->f_slot = l4;
        _a14_obj->f_type_id = l6;
        _a14_obj->f_field_index = l7;
        t0 = (void*) _a14_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 846u) {
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_core_bytecode$ArraySlice_t*) t0)->f_type_id;
        t1 = vader_emit_bytecode$remap_idx(l1, l4);
        vader_struct_vader_core_bytecode$ArraySlice_t* _a15_obj = (vader_struct_vader_core_bytecode$ArraySlice_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$ArraySlice_t));
        vader_obj_header_init(_a15_obj, 846u);
        _a15_obj->f_type_id = t1;
        t0 = (void*) _a15_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 972u) {
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_core_bytecode$RefCast_t*) t0)->f_type_id;
        t1 = vader_emit_bytecode$remap_idx(l1, l4);
        vader_struct_vader_core_bytecode$RefCast_t* _a16_obj = (vader_struct_vader_core_bytecode$RefCast_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$RefCast_t));
        vader_obj_header_init(_a16_obj, 972u);
        _a16_obj->f_type_id = t1;
        t0 = (void*) _a16_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 975u) {
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_core_bytecode$Retag_t*) t0)->f_type_id;
        t1 = vader_emit_bytecode$remap_idx(l1, l4);
        vader_struct_vader_core_bytecode$Retag_t* _a17_obj = (vader_struct_vader_core_bytecode$Retag_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$Retag_t));
        vader_obj_header_init(_a17_obj, 975u);
        _a17_obj->f_type_id = t1;
        t0 = (void*) _a17_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 890u) {
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_core_bytecode$DataConst_t*) t0)->f_pool_index;
        t0 = l0.payload.obj;
        l6 = ((vader_struct_vader_core_bytecode$DataConst_t*) t0)->f_type_id;
        l6 = vader_emit_bytecode$remap_idx(l1, l6);
        vader_struct_vader_core_bytecode$DataConst_t* _a18_obj = (vader_struct_vader_core_bytecode$DataConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$DataConst_t));
        vader_obj_header_init(_a18_obj, 890u);
        _a18_obj->f_pool_index = l4;
        _a18_obj->f_type_id = l6;
        t0 = (void*) _a18_obj;
        l2 = vader_ref_box(t0);
    } else {
        if (!((l0.tag == 836u || l0.tag == 837u || l0.tag == 839u || l0.tag == 842u || l0.tag == 843u || l0.tag == 844u || l0.tag == 867u || l0.tag == 868u || l0.tag == 869u || l0.tag == 870u || l0.tag == 871u || l0.tag == 872u || l0.tag == 873u || l0.tag == 874u || l0.tag == 875u || l0.tag == 876u || l0.tag == 877u || l0.tag == 878u || l0.tag == 879u || l0.tag == 880u || l0.tag == 883u || l0.tag == 884u || l0.tag == 886u || l0.tag == 887u || l0.tag == 888u || l0.tag == 889u || l0.tag == 892u || l0.tag == 893u || l0.tag == 894u || l0.tag == 895u || l0.tag == 896u || l0.tag == 897u || l0.tag == 898u || l0.tag == 899u || l0.tag == 900u || l0.tag == 901u || l0.tag == 902u || l0.tag == 903u || l0.tag == 904u || l0.tag == 905u || l0.tag == 906u || l0.tag == 907u || l0.tag == 908u || l0.tag == 909u || l0.tag == 910u || l0.tag == 911u || l0.tag == 913u || l0.tag == 914u || l0.tag == 915u || l0.tag == 916u || l0.tag == 917u || l0.tag == 918u || l0.tag == 919u || l0.tag == 920u || l0.tag == 921u || l0.tag == 922u || l0.tag == 923u || l0.tag == 924u || l0.tag == 925u || l0.tag == 926u || l0.tag == 927u || l0.tag == 928u || l0.tag == 929u || l0.tag == 930u || l0.tag == 931u || l0.tag == 932u || l0.tag == 933u || l0.tag == 934u || l0.tag == 935u || l0.tag == 936u || l0.tag == 937u || l0.tag == 938u || l0.tag == 939u || l0.tag == 940u || l0.tag == 941u || l0.tag == 942u || l0.tag == 943u || l0.tag == 944u || l0.tag == 945u || l0.tag == 946u || l0.tag == 947u || l0.tag == 948u || l0.tag == 949u || l0.tag == 950u || l0.tag == 951u || l0.tag == 952u || l0.tag == 953u || l0.tag == 954u || l0.tag == 955u || l0.tag == 957u || l0.tag == 958u || l0.tag == 959u || l0.tag == 960u || l0.tag == 961u || l0.tag == 962u || l0.tag == 963u || l0.tag == 965u || l0.tag == 966u || l0.tag == 967u || l0.tag == 968u || l0.tag == 970u || l0.tag == 971u || l0.tag == 973u || l0.tag == 974u || l0.tag == 976u || l0.tag == 977u || l0.tag == 978u || l0.tag == 979u || l0.tag == 980u || l0.tag == 981u || l0.tag == 982u || l0.tag == 983u || l0.tag == 984u || l0.tag == 985u || l0.tag == 986u || l0.tag == 987u || l0.tag == 988u || l0.tag == 989u || l0.tag == 995u || l0.tag == 996u || l0.tag == 997u || l0.tag == 998u || l0.tag == 999u || l0.tag == 1000u || l0.tag == 1001u || l0.tag == 1002u || l0.tag == 1003u || l0.tag == 1004u || l0.tag == 1005u || l0.tag == 1006u || l0.tag == 1009u || l0.tag == 1010u))) {
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
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = l1;
    vader_struct___lambda_env_vader_emit_bytecode_8_t* _a0_obj = (vader_struct___lambda_env_vader_emit_bytecode_8_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_emit_bytecode_8_t));
    vader_obj_header_init(_a0_obj, 480u);
    _a0_obj->f_cap_0 = l0;
    l3 = (void*) _a0_obj;
    vader_array_t* _a1_arr = vader_array_new(23u, 0u, 7u, 450u);
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
            l8 = __lambda_vader_emit_bytecode_7(l3, l7);
            if (VADER_LIKELY(_pc19_len < _pc19_cap)) {
                ((int32_t*) _pc19_slots)[_pc19_len] = (int32_t) (l8);
                _pc19_len += 1;
            } else {
                _pc19_hdr->length = _pc19_len;
                if (_pc19_hdr->buf->length < _pc19_len) {
                    _pc19_hdr->buf->length = _pc19_len;
                }
                vader_array_push_i32((vader_array_t*) l4, l8);
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

static void vader_emit_bytecode$reserve_cfg_extern(void* l0, void* l1) {
    void* l2 = NULL;
    void* l4 = NULL;
    void* l11 = NULL;
    vader_box_t l3 = vader_box_null();
    int32_t l5, l10;
    vader_string_t l6 = 0;
    vader_string_t l7 = 0;
    vader_string_t l9 = 0;
    vader_string_t l12 = 0;
    bool l8;
    int64_t t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &l3 };
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l4, &l11, &t1 };
    vader_string_t* gc_atom_roots[4] = { &l6, &l7, &l9, &l12 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_midir$CFGExternDecl_t*) l0)->f_params;
    l3 = ((vader_struct_vader_midir$CFGExternDecl_t*) l0)->f_return_type;
    vader_array_t* _a0_arr = vader_array_new(363u, 0u, 13u, 1904u);
    l4 = (void*) _a0_arr;
    l2 = vader_emit_bytecode$build_cfg_signature(l2, l3, l4, l1);
    l4 = ((vader_struct_vader_midir$CFGExternDecl_t*) l0)->f_origin;
    l2 = vader_emit_bytecode$with_param_decorators(l2, l4);
    t0 = ((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l1)->f_imports)->length;
    l5 = ((int32_t) (int64_t) t0);
    l4 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l1)->f_imports;
    l6 = ((vader_struct_vader_midir$CFGExternDecl_t*) l0)->f_extern_name;
    l7 = ((vader_struct_vader_midir$CFGExternDecl_t*) l0)->f_mangled;
    l8 = ((vader_struct_vader_midir$CFGExternDecl_t*) l0)->f_is_extern;
    l9 = ((vader_struct_vader_midir$CFGExternDecl_t*) l0)->f_c_header;
    l3 = ((vader_struct_vader_midir$CFGExternDecl_t*) l0)->f_library;
    l10 = ((vader_struct_vader_midir$CFGExternDecl_t*) l0)->f_c_variadic_fixed;
    l11 = vader_emit_bytecode$param_c_types_of(((vader_struct_vader_midir$CFGExternDecl_t*) l0)->f_origin);
    l12 = vader_emit_bytecode$result_c_type_of(((vader_struct_vader_midir$CFGExternDecl_t*) l0)->f_origin);
    vader_struct_vader_core_bytecode$BcImport_t* _a1_obj = (vader_struct_vader_core_bytecode$BcImport_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcImport_t));
    vader_obj_header_init(_a1_obj, 854u);
    _a1_obj->f_extern_name = l6;
    _a1_obj->f_mangled_name = l7;
    _a1_obj->f_signature = l2;
    _a1_obj->f_is_extern = l8;
    _a1_obj->f_c_header = l9;
    _a1_obj->f_library = l3;
    _a1_obj->f_c_variadic_fixed = l10;
    _a1_obj->f_param_c_types = l11;
    _a1_obj->f_result_c_type = l12;
    l2 = (void*) _a1_obj;
    vader_array_push_ref((vader_array_t*) l4, l2);
    l3 = ((vader_struct_vader_core_mono$MonoEntry_t*) ((vader_struct_vader_midir$CFGExternDecl_t*) l0)->f_origin)->f_symbol;
    if (l3.tag == 1015u) {
        l2 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l1)->f_import_index_by_symbol_id;
        t1 = l3.payload.obj;
        l10 = ((vader_struct_vader_core_symbol$Symbol_t*) t1)->f_id;
        std_collections$MutableMap$std_core$IndexSet$set_at__i32__i32(l2, l10, l5);
    }
    l2 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l1)->f_import_index_by_mangle;
    l6 = ((vader_struct_vader_midir$CFGExternDecl_t*) l0)->f_mangled;
    std_collections$MutableMap$std_core$IndexSet$set_at__string__i32(l2, l6, l5);
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
    t0 = ((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l1)->f_functions)->length;
    l5 = ((int32_t) (int64_t) t0);
    vader_array_t* _a0_arr = vader_array_new(358u, 0u, 13u, 1803u);
    l4 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(362u, 0u, 13u, 1863u);
    l6 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(23u, 0u, 7u, 450u);
    l7 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(73u, 0u, 13u, 855u);
    l8 = (void*) _a3_arr;
    l9 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l1)->f_functions;
    l10 = ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_mangled;
    l11 = ((vader_struct_vader_core_mono$MonoEntry_t*) ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_origin)->f_is_main;
    vader_array_t* _a4_arr = vader_array_new(23u, 0u, 7u, 450u);
    l12 = (void*) _a4_arr;
    vader_struct_vader_core_bytecode$BcFunction_t* _a5_obj = (vader_struct_vader_core_bytecode$BcFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcFunction_t));
    vader_obj_header_init(_a5_obj, 852u);
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
    if (l3.tag == 1015u) {
        l2 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l1)->f_function_index_by_symbol_id;
        t1 = l3.payload.obj;
        l13 = ((vader_struct_vader_core_symbol$Symbol_t*) t1)->f_id;
        std_collections$MutableMap$std_core$IndexSet$set_at__i32__i32(l2, l13, l5);
    }
    t2 = ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_mangled;
    if (t2 != 0u) {
        l2 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l1)->f_function_index_by_mangle;
        l10 = ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_mangled;
        t3 = std_collections$MutableMap$std_core$Index$at__string__i32(l2, l10);
        if (!(t3.tag == 0u)) {
            l10 = ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_mangled;
            t2 = concat_3(1862u, l10, 1033u);
            vader_host_std_abort$panic(t2);
            vader_unreachable("a no-return call returned");
        }
    }
    l2 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l1)->f_function_index_by_mangle;
    l10 = ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_mangled;
    std_collections$MutableMap$std_core$IndexSet$set_at__string__i32(l2, l10, l5);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_bytecode$reserve_cfg_struct(void* l0, void* l1) {
    int32_t l2, l7, l8;
    vader_box_t l3 = vader_box_null();
    void* l4 = NULL;
    void* l5 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    vader_string_t l6 = 0;
    vader_string_t l14 = 0;
    uint64_t l9;
    int64_t l10, l11;
    void* t0 = NULL;
    int64_t t1;
    vader_box_t t2 = vader_box_null();
    vader_string_t t3 = 0;
    vader_box_t* gc_roots[2] = { &l3, &t2 };
    void** gc_raw_roots[7] = { &l0, &l1, &l4, &l5, &l12, &l13, &t0 };
    vader_string_t* gc_atom_roots[3] = { &l6, &l14, &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = INT32_C(-1);
    l3 = ((vader_struct_vader_core_mono$MonoEntry_t*) ((vader_struct_vader_midir$CFGStructDecl_t*) l0)->f_origin)->f_symbol;
    if (l3.tag == 1015u) {
        t0 = l3.payload.obj;
        l2 = ((vader_struct_vader_core_symbol$Symbol_t*) t0)->f_id;
    }
    if (l3.tag == 1015u) {
        l4 = l3.payload.obj;
        l5 = ((vader_struct_vader_core_mono$MonoEntry_t*) ((vader_struct_vader_midir$CFGStructDecl_t*) l0)->f_origin)->f_type_arguments;
        l3 = vader_core_types$mk_struct(l4, l5);
        l4 = ((vader_struct_vader_midir$CFGStructDecl_t*) l0)->f_origin;
        l6 = ((vader_struct_vader_midir$CFGStructDecl_t*) l0)->f_mangled;
        l6 = vader_midir$layout_key(l4, l6);
        t1 = ((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l1)->f_types)->length;
        l7 = ((int32_t) (int64_t) t1);
        l8 = std_collections$get_or_put__string__i32(((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l1)->f_type_key, l6, l7);
        if (l8 != l7) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l1)->f_types);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l8)
            t2 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l8);
            if (t2.tag == 861u) {
                { vader_gc_top = gc_frame.prev; return; }
            }
        } else {
            l4 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l1)->f_type_hash;
            l9 = vader_midir_select$type_intern_hash(l3);
            std_collections$get_or_put__u64__i32(l4, l9, l8);
            vader_emit_bytecode$record_slot_type(l1, l8, l3);
            l4 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l1)->f_types;
            t3 = ((vader_struct_vader_midir$CFGStructDecl_t*) l0)->f_mangled;
            vader_struct_vader_core_bytecode$BcRef_t* _a1_obj = (vader_struct_vader_core_bytecode$BcRef_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcRef_t));
            vader_obj_header_init(_a1_obj, 857u);
            _a1_obj->f_trait_name = t3;
            l5 = (void*) _a1_obj;
            vader_array_push_ref((vader_array_t*) l4, l5);
        }
        vader_array_t* _a2_arr = vader_array_new(69u, 0u, 13u, 850u);
        l4 = (void*) _a2_arr;
        l10 = ((vader_array_t*) ((vader_struct_vader_midir$CFGStructDecl_t*) l0)->f_fields)->length;
        vader_array_t* _a3_arr = vader_array_repeat((vader_array_t*) l4, (int64_t) l10);
        l4 = (void*) _a3_arr;
        l5 = ((vader_struct_vader_midir$CFGStructDecl_t*) l0)->f_fields;
        l10 = ((vader_array_t*) l5)->length;
        l11 = INT64_C(0);
        while ((l11 < l10)) {
            vader_array_t* _a4_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
            l12 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l11);
            l7 = vader_emit_bytecode$intern_type(((vader_struct_vader_midir$CFGStructField_t*) l12)->f_type, l1);
            t3 = ((vader_struct_vader_midir$CFGStructField_t*) l12)->f_name;
            vader_struct_vader_core_bytecode$BcField_t* _a5_obj = (vader_struct_vader_core_bytecode$BcField_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcField_t));
            vader_obj_header_init(_a5_obj, 850u);
            _a5_obj->f_name = t3;
            _a5_obj->f_type_index = l7;
            l13 = (void*) _a5_obj;
            vader_array_push_ref((vader_array_t*) l4, l13);
            l11 = (l11 + INT64_C(1));
        }
        l5 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l1)->f_types;
        l6 = ((vader_struct_vader_midir$CFGStructDecl_t*) l0)->f_mangled;
        l14 = vader_emit_bytecode$c_struct_of(((vader_struct_vader_midir$CFGStructDecl_t*) l0)->f_origin);
        vader_struct_vader_core_bytecode$BcStruct_t* _a6_obj = (vader_struct_vader_core_bytecode$BcStruct_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcStruct_t));
        vader_obj_header_init(_a6_obj, 861u);
        _a6_obj->f_name = l6;
        _a6_obj->f_fields = l4;
        _a6_obj->f_c_name = l14;
        _a6_obj->f_symbol_id = l2;
        l4 = (void*) _a6_obj;
        vader_array_t* _a7_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l8)
        vader_array_ref_store(_a7_slotarr->buf, _a7_slotarr->offset + (size_t) l8, l4);
        VADER_WRITE_BARRIER(_a7_slotarr->buf);
        { vader_gc_top = gc_frame.prev; return; }
    }
    t1 = ((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l1)->f_types)->length;
    l7 = ((int32_t) (int64_t) t1);
    l4 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l1)->f_types;
    t3 = ((vader_struct_vader_midir$CFGStructDecl_t*) l0)->f_mangled;
    vader_struct_vader_core_bytecode$BcRef_t* _a8_obj = (vader_struct_vader_core_bytecode$BcRef_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcRef_t));
    vader_obj_header_init(_a8_obj, 857u);
    _a8_obj->f_trait_name = t3;
    l5 = (void*) _a8_obj;
    vader_array_push_ref((vader_array_t*) l4, l5);
    vader_array_t* _a9_arr = vader_array_new(69u, 0u, 13u, 850u);
    l4 = (void*) _a9_arr;
    l10 = ((vader_array_t*) ((vader_struct_vader_midir$CFGStructDecl_t*) l0)->f_fields)->length;
    vader_array_t* _a10_arr = vader_array_repeat((vader_array_t*) l4, (int64_t) l10);
    l4 = (void*) _a10_arr;
    l5 = ((vader_struct_vader_midir$CFGStructDecl_t*) l0)->f_fields;
    l10 = ((vader_array_t*) l5)->length;
    l11 = INT64_C(0);
    while ((l11 < l10)) {
        vader_array_t* _a11_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
        l12 = vader_array_ref_load_obj(_a11_slotarr->buf, _a11_slotarr->offset + (size_t) l11);
        l8 = vader_emit_bytecode$intern_type(((vader_struct_vader_midir$CFGStructField_t*) l12)->f_type, l1);
        t3 = ((vader_struct_vader_midir$CFGStructField_t*) l12)->f_name;
        vader_struct_vader_core_bytecode$BcField_t* _a12_obj = (vader_struct_vader_core_bytecode$BcField_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcField_t));
        vader_obj_header_init(_a12_obj, 850u);
        _a12_obj->f_name = t3;
        _a12_obj->f_type_index = l8;
        l13 = (void*) _a12_obj;
        vader_array_push_ref((vader_array_t*) l4, l13);
        l11 = (l11 + INT64_C(1));
    }
    l5 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l1)->f_types;
    l6 = ((vader_struct_vader_midir$CFGStructDecl_t*) l0)->f_mangled;
    l14 = vader_emit_bytecode$c_struct_of(((vader_struct_vader_midir$CFGStructDecl_t*) l0)->f_origin);
    vader_struct_vader_core_bytecode$BcStruct_t* _a13_obj = (vader_struct_vader_core_bytecode$BcStruct_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcStruct_t));
    vader_obj_header_init(_a13_obj, 861u);
    _a13_obj->f_name = l6;
    _a13_obj->f_fields = l4;
    _a13_obj->f_c_name = l14;
    _a13_obj->f_symbol_id = l2;
    l4 = (void*) _a13_obj;
    vader_array_t* _a14_slotarr = ((vader_array_t*) l5);
    VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a14_slotarr, l7)
    vader_array_ref_store(_a14_slotarr->buf, _a14_slotarr->offset + (size_t) l7, l4);
    VADER_WRITE_BARRIER(_a14_slotarr->buf);
    l4 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l1)->f_type_key;
    l5 = ((vader_struct_vader_midir$CFGStructDecl_t*) l0)->f_origin;
    l6 = ((vader_struct_vader_midir$CFGStructDecl_t*) l0)->f_mangled;
    l6 = vader_midir$layout_key(l5, l6);
    std_collections$MutableMap$std_core$IndexSet$set_at__string__i32(l4, l6, l7);
    { vader_gc_top = gc_frame.prev; return; }
}

static void* vader_emit_bytecode$resolve_direct_call(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l8 = NULL;
    int32_t l4, l9;
    vader_box_t l5 = vader_box_null(), l7 = vader_box_null();
    vader_string_t l6 = 0;
    vader_string_t l10 = 0;
    int64_t l11, l12;
    int32_t t0;
    void* t1 = NULL;
    vader_string_t t2 = 0;
    vader_box_t* gc_roots[2] = { &l5, &l7 };
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l3, &l8, &t1 };
    vader_string_t* gc_atom_roots[3] = { &l6, &l10, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_project;
    l3 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l2)->f_import_index_by_symbol_id;
    l4 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_midir$InstrCall_t*) l1)->f_callee)->f_id;
    l5 = std_collections$MutableMap$std_core$Index$at__i32__i32(l3, l4);
    if (l5.tag == 450u) {
        t0 = ((int32_t) l5.payload.i);
        l5 = vader_box_i32(450u, t0);
    } else {
        l3 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l2)->f_import_index_by_mangle;
        l6 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_midir$InstrCall_t*) l1)->f_callee)->f_name;
        l5 = std_collections$MutableMap$std_core$Index$at__string__i32(l3, l6);
    }
    if (l5.tag == 450u) {
        l4 = ((int32_t) l5.payload.i);
        l3 = vader_emit_bytecode$import_call_target(l2, l4);
        if (!(((vader_struct_vader_emit_bytecode$DirectCallTarget_t*) l3)->f_op.tag == 884u)) {
            { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    l7 = vader_emit_bytecode$resolve_fn_index(((vader_struct_vader_midir$InstrCall_t*) l1)->f_callee, l2);
    if (!(l7.tag == 0u)) {
        t0 = ((int32_t) l7.payload.i);
        vader_struct_vader_core_bytecode$Call_t* _a0_obj = (vader_struct_vader_core_bytecode$Call_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$Call_t));
        vader_obj_header_init(_a0_obj, 883u);
        _a0_obj->f_function_index = t0;
        l3 = (void*) _a0_obj;
        l8 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l2)->f_functions;
        l4 = ((int32_t) l7.payload.i);
        vader_array_t* _a1_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
        t1 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
        l8 = ((vader_struct_vader_core_bytecode$BcFunction_t*) t1)->f_signature;
        vader_struct_vader_emit_bytecode$DirectCallTarget_t* _a2_obj = (vader_struct_vader_emit_bytecode$DirectCallTarget_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_bytecode$DirectCallTarget_t));
        vader_obj_header_init(_a2_obj, 1044u);
        _a2_obj->f_op = vader_ref_box(l3);
        _a2_obj->f_signature = l8;
        t1 = (void*) _a2_obj;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l5.tag == 450u)) {
        l6 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_midir$InstrCall_t*) l1)->f_callee)->f_name;
        l9 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_midir$InstrCall_t*) l1)->f_callee)->f_id;
        l10 = ((vader_struct_vader_midir$CFGFunction_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_fn_)->f_mangled;
        l11 = vader_host_std_core$byte_len(l6);
        l12 = vader_host_std_core$byte_len(l10);
        l11 = (l11 + l12);
        l3 = (void*) vader_buffer_new((size_t) (INT64_C(102) + l11));
        l11 = INT64_C(0);
        l11 = std_core$write_string_at(l3, l11, 1865u);
        l11 = std_core$write_string_at(l3, l11, l6);
        l11 = std_core$write_string_at(l3, l11, 290u);
        l12 = ((int64_t) (int32_t) l9);
        l11 = std_core$write_int(l3, l11, l12);
        l11 = std_core$write_string_at(l3, l11, 335u);
        l11 = std_core$write_string_at(l3, l11, l10);
        l11 = std_core$write_string_at(l3, l11, 291u);
        t2 = std_core$finish_buffer(l3, l11);
        vader_host_std_abort$panic(t2);
        vader_unreachable("a no-return call returned");
    }
    l4 = ((int32_t) l5.payload.i);
    t1 = vader_emit_bytecode$import_call_target(l2, l4);
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
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
    l4 = std_collections$MutableMap$std_core$Index$at__string__i32(l2, l3);
    if (!(l4.tag == 0u)) {
        t0 = ((int32_t) l4.payload.i);
        return vader_box_i32(450u, t0);
    }
    l2 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l1)->f_function_index_by_symbol_id;
    l5 = ((vader_struct_vader_core_symbol$Symbol_t*) l0)->f_id;
    t1 = std_collections$MutableMap$std_core$Index$at__i32__i32(l2, l5);
    return t1;
}

static vader_string_t vader_emit_bytecode$result_c_type_of(void* l0) {
    vader_box_t l1;
    void* t0;
    vader_string_t t1;
    l1 = ((vader_struct_vader_core_mono$MonoEntry_t*) l0)->f_decl;
    if (!(l1.tag == 773u)) {
        return 0u;
    }
    t0 = l1.payload.obj;
    t1 = toolchain_ast$c_type_of(((vader_struct_toolchain_ast$FnDecl_t*) t0)->f_decorators);
    return t1;
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
    if (l1.tag == 1494u) {
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir$TermBranch_t*) t0)->f_span;
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_midir$TermBranch_t*) t0)->f_target;
        l4 = vader_emit_bytecode$destination(l0, l4);
        vader_struct_vader_midir$TermBranch_t* _a0_obj = (vader_struct_vader_midir$TermBranch_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$TermBranch_t));
        vader_obj_header_init(_a0_obj, 1494u);
        _a0_obj->f_span = l3;
        _a0_obj->f_target = l4;
        t0 = (void*) _a0_obj;
        l2 = vader_ref_box(t0);
        { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 1495u) {
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
        vader_obj_header_init(_a1_obj, 1495u);
        _a1_obj->f_span = l5;
        _a1_obj->f_cond = l4;
        _a1_obj->f_then_block = l6;
        _a1_obj->f_else_block = l7;
        t0 = (void*) _a1_obj;
        l2 = vader_ref_box(t0);
    } else {
        if (!((l1.tag == 1496u || l1.tag == 1497u))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l2 = l1;
    }
    { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_emit_bytecode$run_bc_const_fold_arith(void* l0) {
    void* l1 = NULL;
    void* l3 = NULL;
    void* l5 = NULL;
    int64_t l2, l4, l6;
    vader_box_t l7 = vader_box_null(), l8 = vader_box_null(), l10 = vader_box_null();
    int32_t l9, l11;
    void* t0 = NULL;
    vader_box_t* gc_roots[3] = { &l7, &l8, &l10 };
    void** gc_raw_roots[5] = { &l0, &l1, &l3, &l5, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_body;
    l2 = ((vader_array_t*) l1)->length;
    vader_array_t* _a0_arr = vader_array_new(358u, 0u, 13u, 1803u);
    l3 = (void*) _a0_arr;
    l4 = INT64_C(0);
    vader_array_t* _a1_arr = vader_array_new(23u, 1u, 7u, 450u);
    ((int32_t*) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = (int32_t) INT32_C(-1);
    t0 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l2);
    l5 = (void*) _a2_arr;
    l6 = INT64_C(0);
    while ((l6 < l2)) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        l7 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l6);
        l8 = vader_emit_bytecode$try_fold_arith(l7, l3, l4);
        if (l8.tag == 0u) {
            vader_emit_bytecode$push_or_assign(l3, l4, l7);
            l9 = ((int32_t) (int64_t) l4);
            vader_array_t* _a4_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l6)
            ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l6] = (int32_t) l9;
            l4 = vader_chk_add(i64, l4, INT64_C(1));
        } else {
            l4 = vader_chk_sub(i64, l4, INT64_C(2));
            l10 = l8;
            vader_emit_bytecode$push_or_assign(l3, l4, l10);
            l11 = ((int32_t) (int64_t) l4);
            vader_array_t* _a5_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l6)
            ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l6] = (int32_t) l11;
            l4 = vader_chk_add(i64, l4, INT64_C(1));
        }
        l6 = (l6 + INT64_C(1));
    }
    vader_array_t* _a6_arr = vader_array_slice((vader_array_t*) l3, (int64_t) INT64_C(0), (int64_t) l4);
    l1 = (void*) _a6_arr;
    l3 = vader_core_bytecode$remap_jump_table(((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_jump_table, l5, l4);
    l5 = vader_emit_bytecode$remap_debug(((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_debug, l5, l4);
    vader_struct_vader_emit_bytecode$BcPeepholeOut_t* _a7_obj = (vader_struct_vader_emit_bytecode$BcPeepholeOut_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_bytecode$BcPeepholeOut_t));
    vader_obj_header_init(_a7_obj, 1043u);
    _a7_obj->f_body = l1;
    _a7_obj->f_jump_table = l3;
    _a7_obj->f_debug = l5;
    t0 = (void*) _a7_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_emit_bytecode$run_bc_peephole(void* l0) {
    bool l1, l21, l24, l25, l26, l27;
    void* l2 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l17 = NULL;
    void* l18 = NULL;
    void* l29 = NULL;
    void* l35 = NULL;
    void* l38 = NULL;
    int64_t l3, l4, l5, l19, l22, l23, l28, l30, l31, l32, l34, l36;
    vader_box_t l10 = vader_box_null(), l20 = vader_box_null(), l33 = vader_box_null(), l37 = vader_box_null();
    int32_t l11, l12, l13, l14, l15, l16, l39;
    int64_t t0;
    void* t1 = NULL;
    int32_t t2;
    vader_box_t t3 = vader_box_null(), t4 = vader_box_null();
    bool t5;
    vader_box_t* gc_roots[6] = { &l10, &l20, &l33, &l37, &t3, &t4 };
    void** gc_raw_roots[12] = { &l0, &l2, &l6, &l7, &l8, &l9, &l17, &l18, &l29, &l35, &l38, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 6u, 12u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_core_bytecode$bc_result_arity(((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_signature);
    l1 = (t0 > INT64_C(1));
    l2 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_body;
    l3 = ((vader_array_t*) l2)->length;
    l4 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_signature)->f_params)->length;
    l5 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_locals)->length;
    l4 = vader_chk_add(i64, l4, l5);
    vader_array_t* _a0_arr = vader_array_new(23u, 1u, 7u, 450u);
    ((int32_t*) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = (int32_t) INT32_C(0);
    t1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t1, (int64_t) l4);
    l6 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(23u, 1u, 7u, 450u);
    ((int32_t*) _a2_arr->buf->slots)[_a2_arr->offset + 0u] = (int32_t) INT32_C(0);
    t1 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_repeat((vader_array_t*) t1, (int64_t) l4);
    l7 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_new(23u, 1u, 7u, 450u);
    ((int32_t*) _a4_arr->buf->slots)[_a4_arr->offset + 0u] = (int32_t) INT32_C(0);
    t1 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_repeat((vader_array_t*) t1, (int64_t) l4);
    l8 = (void*) _a5_arr;
    l9 = l2;
    l4 = ((vader_array_t*) l9)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a6_slotarr = ((vader_array_t*) l9);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        l10 = vader_array_ref_load_box(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l5);
        if (l10.tag == 966u) {
            t1 = l10.payload.obj;
            l11 = ((vader_struct_vader_core_bytecode$LocalSet_t*) t1)->f_slot;
            vader_array_t* _a7_slotarr = ((vader_array_t*) l6);
            VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l11)
            t2 = ((int32_t*) _a7_slotarr->buf->slots)[_a7_slotarr->offset + (size_t) l11];
            l12 = vader_chk_add(i32, t2, INT32_C(1));
            VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l11)
            ((int32_t*) _a7_slotarr->buf->slots)[_a7_slotarr->offset + (size_t) l11] = (int32_t) l12;
        }
        if (l10.tag == 965u) {
            t1 = l10.payload.obj;
            l13 = ((vader_struct_vader_core_bytecode$LocalGet_t*) t1)->f_slot;
            vader_array_t* _a8_slotarr = ((vader_array_t*) l7);
            VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l13)
            t2 = ((int32_t*) _a8_slotarr->buf->slots)[_a8_slotarr->offset + (size_t) l13];
            l14 = vader_chk_add(i32, t2, INT32_C(1));
            VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l13)
            ((int32_t*) _a8_slotarr->buf->slots)[_a8_slotarr->offset + (size_t) l13] = (int32_t) l14;
        }
        if (l10.tag == 967u) {
            t1 = l10.payload.obj;
            l15 = ((vader_struct_vader_core_bytecode$LocalTee_t*) t1)->f_slot;
            vader_array_t* _a9_slotarr = ((vader_array_t*) l8);
            VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l15)
            t2 = ((int32_t*) _a9_slotarr->buf->slots)[_a9_slotarr->offset + (size_t) l15];
            l16 = vader_chk_add(i32, t2, INT32_C(1));
            VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l15)
            ((int32_t*) _a9_slotarr->buf->slots)[_a9_slotarr->offset + (size_t) l15] = (int32_t) l16;
        }
        l5 = (l5 + INT64_C(1));
    }
    l9 = vader_core_bytecode$mark_jump_targets(((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_jump_table, l3);
    vader_array_t* _a10_arr = vader_array_new(358u, 0u, 13u, 1803u);
    l17 = (void*) _a10_arr;
    l4 = INT64_C(0);
    vader_array_t* _a11_arr = vader_array_new(23u, 1u, 7u, 450u);
    ((int32_t*) _a11_arr->buf->slots)[_a11_arr->offset + 0u] = (int32_t) INT32_C(-1);
    t1 = (void*) _a11_arr;
    vader_array_t* _a12_arr = vader_array_repeat((vader_array_t*) t1, (int64_t) l3);
    l18 = (void*) _a12_arr;
    l5 = INT64_C(0);
    while ((l5 < l3)) {
        vader_array_t* _a13_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
        l10 = vader_array_ref_load_box(_a13_slotarr->buf, _a13_slotarr->offset + (size_t) l5);
        if (l10.tag == 966u) {
            t0 = vader_chk_add(i64, l5, INT64_C(1));
            if ((t0 < l3)) {
                l19 = vader_chk_add(i64, l5, INT64_C(1));
                vader_array_t* _a14_slotarr = ((vader_array_t*) l2);
                VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a14_slotarr, l19)
                l20 = vader_array_ref_load_box(_a14_slotarr->buf, _a14_slotarr->offset + (size_t) l19);
                if (l20.tag == 965u) {
                    t1 = l20.payload.obj;
                    l11 = ((vader_struct_vader_core_bytecode$LocalGet_t*) t1)->f_slot;
                    t1 = l10.payload.obj;
                    l12 = ((vader_struct_vader_core_bytecode$LocalSet_t*) t1)->f_slot;
                    if (l11 == l12) {
                        l21 = false;
                        if ((l4 > INT64_C(0))) {
                            l22 = vader_chk_sub(i64, l4, INT64_C(1));
                            vader_array_t* _a15_slotarr = ((vader_array_t*) l17);
                            VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
                            VADER_ARRAY_CHECK_INDEX(_a15_slotarr, l22)
                            t3 = vader_array_ref_load_box(_a15_slotarr->buf, _a15_slotarr->offset + (size_t) l22);
                            t4 = vader_core_bytecode$const_op_of(t3);
                            if (!(t4.tag == 0u)) {
                                l21 = true;
                            }
                        }
                        t1 = l10.payload.obj;
                        t2 = ((vader_struct_vader_core_bytecode$LocalSet_t*) t1)->f_slot;
                        l23 = ((int64_t) (int32_t) t2);
                        vader_array_t* _a16_slotarr = ((vader_array_t*) l6);
                        VADER_ARRAY_RESOLVE_BUF(_a16_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a16_slotarr, l23)
                        t2 = ((int32_t*) _a16_slotarr->buf->slots)[_a16_slotarr->offset + (size_t) l23];
                        if (t2 == INT32_C(1)) {
                            vader_array_t* _a17_slotarr = ((vader_array_t*) l7);
                            VADER_ARRAY_RESOLVE_BUF(_a17_slotarr)
                            VADER_ARRAY_CHECK_INDEX(_a17_slotarr, l23)
                            t2 = ((int32_t*) _a17_slotarr->buf->slots)[_a17_slotarr->offset + (size_t) l23];
                            l25 = t2 == INT32_C(1);
                        } else {
                            l25 = false;
                        }
                        if (l25) {
                            vader_array_t* _a18_slotarr = ((vader_array_t*) l8);
                            VADER_ARRAY_RESOLVE_BUF(_a18_slotarr)
                            VADER_ARRAY_CHECK_INDEX(_a18_slotarr, l23)
                            t2 = ((int32_t*) _a18_slotarr->buf->slots)[_a18_slotarr->offset + (size_t) l23];
                            l24 = t2 == INT32_C(0);
                        } else {
                            l24 = false;
                        }
                        if (l21) {
                            l27 = l24;
                        } else {
                            l27 = false;
                        }
                        if (l27) {
                            l26 = true;
                        } else {
                            l28 = vader_chk_add(i64, l5, INT64_C(1));
                            vader_array_t* _a19_slotarr = ((vader_array_t*) l9);
                            VADER_ARRAY_RESOLVE_BUF(_a19_slotarr)
                            VADER_ARRAY_CHECK_INDEX(_a19_slotarr, l28)
                            t5 = ((uint8_t*) _a19_slotarr->buf->slots)[_a19_slotarr->offset + (size_t) l28];
                            l26 = t5;
                        }
                        if (!(l26)) {
                            t1 = l10.payload.obj;
                            t2 = ((vader_struct_vader_core_bytecode$LocalSet_t*) t1)->f_slot;
                            vader_struct_vader_core_bytecode$LocalTee_t* _a20_obj = (vader_struct_vader_core_bytecode$LocalTee_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$LocalTee_t));
                            vader_obj_header_init(_a20_obj, 967u);
                            _a20_obj->f_slot = t2;
                            l29 = (void*) _a20_obj;
                            vader_emit_bytecode$push_or_assign(l17, l4, vader_ref_box(l29));
                            l13 = ((int32_t) (int64_t) l4);
                            vader_array_t* _a21_slotarr = ((vader_array_t*) l18);
                            VADER_ARRAY_RESOLVE_BUF(_a21_slotarr)
                            VADER_ARRAY_CHECK_INDEX(_a21_slotarr, l5)
                            ((int32_t*) _a21_slotarr->buf->slots)[_a21_slotarr->offset + (size_t) l5] = (int32_t) l13;
                            l30 = vader_chk_add(i64, l5, INT64_C(1));
                            l14 = ((int32_t) (int64_t) l4);
                            VADER_ARRAY_CHECK_INDEX(_a21_slotarr, l30)
                            ((int32_t*) _a21_slotarr->buf->slots)[_a21_slotarr->offset + (size_t) l30] = (int32_t) l14;
                            l4 = vader_chk_add(i64, l4, INT64_C(1));
                            l5 = vader_chk_add(i64, l5, INT64_C(2));
                            continue;
                        }
                    }
                }
            }
        }
        if (l10.tag == 976u) {
            if (!(l1)) {
                l31 = ((vader_array_t*) l17)->length;
                if ((l31 > INT64_C(0))) {
                    l32 = vader_chk_sub(i64, l31, INT64_C(1));
                    vader_array_t* _a22_slotarr = ((vader_array_t*) l17);
                    VADER_ARRAY_RESOLVE_BUF(_a22_slotarr)
                    t3 = vader_array_ref_load_box(_a22_slotarr->buf, _a22_slotarr->offset + (size_t) l32);
                    l33 = vader_core_bytecode$const_op_of(t3);
                    if (!(l33.tag == 0u)) {
                        l34 = vader_chk_sub(i64, l31, INT64_C(1));
                        vader_struct_vader_core_bytecode$ReturnLit_t* _a23_obj = (vader_struct_vader_core_bytecode$ReturnLit_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$ReturnLit_t));
                        vader_obj_header_init(_a23_obj, 977u);
                        _a23_obj->f_value = l33;
                        l35 = (void*) _a23_obj;
                        vader_array_t* _a24_slotarr = ((vader_array_t*) l17);
                        VADER_ARRAY_RESOLVE_BUF(_a24_slotarr)
                        vader_array_ref_store(_a24_slotarr->buf, _a24_slotarr->offset + (size_t) l34, l35);
                        VADER_WRITE_BARRIER(_a24_slotarr->buf);
                        t0 = vader_chk_sub(i64, l4, INT64_C(1));
                        l15 = ((int32_t) (int64_t) t0);
                        vader_array_t* _a25_slotarr = ((vader_array_t*) l18);
                        VADER_ARRAY_RESOLVE_BUF(_a25_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a25_slotarr, l5)
                        ((int32_t*) _a25_slotarr->buf->slots)[_a25_slotarr->offset + (size_t) l5] = (int32_t) l15;
                        l5 = vader_chk_add(i64, l5, INT64_C(1));
                        continue;
                    }
                }
            }
        }
        if (l10.tag == 874u) {
            if ((l4 > INT64_C(0))) {
                l36 = vader_chk_sub(i64, l4, INT64_C(1));
                vader_array_t* _a26_slotarr = ((vader_array_t*) l17);
                VADER_ARRAY_RESOLVE_BUF(_a26_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a26_slotarr, l36)
                l37 = vader_array_ref_load_box(_a26_slotarr->buf, _a26_slotarr->offset + (size_t) l36);
                if (l37.tag == 874u) {
                    vader_array_t* _a27_slotarr = ((vader_array_t*) l18);
                    VADER_ARRAY_RESOLVE_BUF(_a27_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a27_slotarr, l5)
                    ((int32_t*) _a27_slotarr->buf->slots)[_a27_slotarr->offset + (size_t) l5] = (int32_t) INT32_C(-1);
                    l4 = vader_chk_sub(i64, l4, INT64_C(1));
                    l5 = vader_chk_add(i64, l5, INT64_C(1));
                    continue;
                }
                if (l37.tag == 871u) {
                    t1 = l37.payload.obj;
                    t5 = ((vader_struct_vader_core_bytecode$BoolConst_t*) t1)->f_value;
                    vader_struct_vader_core_bytecode$BoolConst_t* _a28_obj = (vader_struct_vader_core_bytecode$BoolConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BoolConst_t));
                    vader_obj_header_init(_a28_obj, 871u);
                    _a28_obj->f_value = !(t5);
                    l38 = (void*) _a28_obj;
                    vader_array_t* _a29_slotarr = ((vader_array_t*) l17);
                    VADER_ARRAY_RESOLVE_BUF(_a29_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a29_slotarr, l36)
                    vader_array_ref_store(_a29_slotarr->buf, _a29_slotarr->offset + (size_t) l36, l38);
                    VADER_WRITE_BARRIER(_a29_slotarr->buf);
                    l16 = ((int32_t) (int64_t) l36);
                    vader_array_t* _a30_slotarr = ((vader_array_t*) l18);
                    VADER_ARRAY_RESOLVE_BUF(_a30_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a30_slotarr, l5)
                    ((int32_t*) _a30_slotarr->buf->slots)[_a30_slotarr->offset + (size_t) l5] = (int32_t) l16;
                    l5 = vader_chk_add(i64, l5, INT64_C(1));
                    continue;
                }
            }
        }
        vader_emit_bytecode$push_or_assign(l17, l4, l10);
        l39 = ((int32_t) (int64_t) l4);
        vader_array_t* _a31_slotarr = ((vader_array_t*) l18);
        VADER_ARRAY_RESOLVE_BUF(_a31_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a31_slotarr, l5)
        ((int32_t*) _a31_slotarr->buf->slots)[_a31_slotarr->offset + (size_t) l5] = (int32_t) l39;
        l4 = vader_chk_add(i64, l4, INT64_C(1));
        l5 = vader_chk_add(i64, l5, INT64_C(1));
    }
    vader_array_t* _a32_arr = vader_array_slice((vader_array_t*) l17, (int64_t) INT64_C(0), (int64_t) l4);
    l2 = (void*) _a32_arr;
    l6 = vader_core_bytecode$remap_jump_table(((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_jump_table, l18, l4);
    l7 = vader_emit_bytecode$remap_debug(((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_debug, l18, l4);
    vader_struct_vader_emit_bytecode$BcPeepholeOut_t* _a33_obj = (vader_struct_vader_emit_bytecode$BcPeepholeOut_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_bytecode$BcPeepholeOut_t));
    vader_obj_header_init(_a33_obj, 1043u);
    _a33_obj->f_body = l2;
    _a33_obj->f_jump_table = l6;
    _a33_obj->f_debug = l7;
    t1 = (void*) _a33_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_emit_bytecode$run_bc_return_lit_fold(void* l0) {
    void* l1 = NULL;
    void* l3 = NULL;
    void* l5 = NULL;
    void* l12 = NULL;
    int64_t l2, l4, l6, l8, l9, l11;
    vader_box_t l7 = vader_box_null(), l10 = vader_box_null();
    int32_t l13, l14;
    int64_t t0;
    void* t1 = NULL;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l7, &l10, &t2 };
    void** gc_raw_roots[6] = { &l0, &l1, &l3, &l5, &l12, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 6u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_core_bytecode$bc_result_arity(((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_signature);
    if ((t0 > INT64_C(1))) {
        t1 = vader_emit_bytecode$bc_peephole_unchanged(l0);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l1 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_body;
    l2 = ((vader_array_t*) l1)->length;
    vader_array_t* _a0_arr = vader_array_new(358u, 0u, 13u, 1803u);
    l3 = (void*) _a0_arr;
    l4 = INT64_C(0);
    vader_array_t* _a1_arr = vader_array_new(23u, 1u, 7u, 450u);
    ((int32_t*) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = (int32_t) INT32_C(-1);
    t1 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_repeat((vader_array_t*) t1, (int64_t) l2);
    l5 = (void*) _a2_arr;
    l6 = INT64_C(0);
    while ((l6 < l2)) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        l7 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l6);
        if (l7.tag == 976u) {
            l8 = ((vader_array_t*) l3)->length;
            if ((l8 > INT64_C(0))) {
                l9 = vader_chk_sub(i64, l8, INT64_C(1));
                vader_array_t* _a4_slotarr = ((vader_array_t*) l3);
                VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                t2 = vader_array_ref_load_box(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l9);
                l10 = vader_core_bytecode$const_op_of(t2);
                if (!(l10.tag == 0u)) {
                    l11 = vader_chk_sub(i64, l8, INT64_C(1));
                    vader_struct_vader_core_bytecode$ReturnLit_t* _a5_obj = (vader_struct_vader_core_bytecode$ReturnLit_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$ReturnLit_t));
                    vader_obj_header_init(_a5_obj, 977u);
                    _a5_obj->f_value = l10;
                    l12 = (void*) _a5_obj;
                    vader_array_t* _a6_slotarr = ((vader_array_t*) l3);
                    VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
                    vader_array_ref_store(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l11, l12);
                    VADER_WRITE_BARRIER(_a6_slotarr->buf);
                    t0 = vader_chk_sub(i64, l8, INT64_C(1));
                    l13 = ((int32_t) (int64_t) t0);
                    vader_array_t* _a7_slotarr = ((vader_array_t*) l5);
                    VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l6)
                    ((int32_t*) _a7_slotarr->buf->slots)[_a7_slotarr->offset + (size_t) l6] = (int32_t) l13;
                    l6 = vader_chk_add(i64, l6, INT64_C(1));
                    continue;
                }
            }
        }
        vader_emit_bytecode$push_or_assign(l3, l4, l7);
        l14 = ((int32_t) (int64_t) l4);
        vader_array_t* _a8_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l6)
        ((int32_t*) _a8_slotarr->buf->slots)[_a8_slotarr->offset + (size_t) l6] = (int32_t) l14;
        l4 = vader_chk_add(i64, l4, INT64_C(1));
        l6 = vader_chk_add(i64, l6, INT64_C(1));
    }
    vader_array_t* _a9_arr = vader_array_slice((vader_array_t*) l3, (int64_t) INT64_C(0), (int64_t) l4);
    l1 = (void*) _a9_arr;
    l3 = vader_core_bytecode$remap_jump_table(((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_jump_table, l5, l4);
    l5 = vader_emit_bytecode$remap_debug(((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_debug, l5, l4);
    vader_struct_vader_emit_bytecode$BcPeepholeOut_t* _a10_obj = (vader_struct_vader_emit_bytecode$BcPeepholeOut_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_bytecode$BcPeepholeOut_t));
    vader_obj_header_init(_a10_obj, 1043u);
    _a10_obj->f_body = l1;
    _a10_obj->f_jump_table = l3;
    _a10_obj->f_debug = l5;
    t1 = (void*) _a10_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
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
    vader_array_t* _a0_arr = vader_array_new(24u, 0u, 8u, 451u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(20u, 0u, 12u, 445u);
    l3 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(23u, 0u, 7u, 450u);
    l4 = (void*) _a2_arr;
    vader_struct_std_collections$MutableMap__i64__bool_t* _a3_obj = (vader_struct_std_collections$MutableMap__i64__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i64__bool_t));
    vader_obj_header_init(_a3_obj, 631u);
    _a3_obj->f_ekeys = l2;
    _a3_obj->f_evals = l3;
    _a3_obj->f_index = l4;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a3_obj;
    vader_struct_std_collections$MutableSet__i64_t* _a4_obj = (vader_struct_std_collections$MutableSet__i64_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableSet__i64_t));
    vader_obj_header_init(_a4_obj, 729u);
    _a4_obj->f_inner = t0;
    l2 = (void*) _a4_obj;
    vader_array_t* _a5_arr = vader_array_new(24u, 0u, 8u, 451u);
    l3 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(20u, 0u, 12u, 445u);
    l4 = (void*) _a6_arr;
    vader_array_t* _a7_arr = vader_array_new(23u, 0u, 7u, 450u);
    l5 = (void*) _a7_arr;
    vader_struct_std_collections$MutableMap__i64__bool_t* _a8_obj = (vader_struct_std_collections$MutableMap__i64__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i64__bool_t));
    vader_obj_header_init(_a8_obj, 631u);
    _a8_obj->f_ekeys = l3;
    _a8_obj->f_evals = l4;
    _a8_obj->f_index = l5;
    _a8_obj->f_mask = INT64_C(0);
    _a8_obj->f_grow_at = INT64_C(0);
    _a8_obj->f_size = INT64_C(0);
    _a8_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a8_obj;
    vader_struct_std_collections$MutableSet__i64_t* _a9_obj = (vader_struct_std_collections$MutableSet__i64_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableSet__i64_t));
    vader_obj_header_init(_a9_obj, 729u);
    _a9_obj->f_inner = t0;
    l3 = (void*) _a9_obj;
    vader_array_t* _a10_arr = vader_array_new(23u, 0u, 7u, 450u);
    l4 = (void*) _a10_arr;
    vader_array_t* _a11_arr = vader_array_new(20u, 0u, 12u, 445u);
    l5 = (void*) _a11_arr;
    vader_array_t* _a12_arr = vader_array_new(23u, 0u, 7u, 450u);
    l6 = (void*) _a12_arr;
    vader_struct_std_collections$MutableMap__i32__bool_t* _a13_obj = (vader_struct_std_collections$MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i32__bool_t));
    vader_obj_header_init(_a13_obj, 585u);
    _a13_obj->f_ekeys = l4;
    _a13_obj->f_evals = l5;
    _a13_obj->f_index = l6;
    _a13_obj->f_mask = INT64_C(0);
    _a13_obj->f_grow_at = INT64_C(0);
    _a13_obj->f_size = INT64_C(0);
    _a13_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a13_obj;
    vader_struct_std_collections$MutableSet__i32_t* _a14_obj = (vader_struct_std_collections$MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableSet__i32_t));
    vader_obj_header_init(_a14_obj, 728u);
    _a14_obj->f_inner = t0;
    l4 = (void*) _a14_obj;
    vader_struct_vader_emit_bytecode$ScheduleHints_t* _a15_obj = (vader_struct_vader_emit_bytecode$ScheduleHints_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_bytecode$ScheduleHints_t));
    vader_obj_header_init(_a15_obj, 1049u);
    _a15_obj->f_skip_set = l2;
    _a15_obj->f_skip_first_get = l3;
    _a15_obj->f_skip_terminator_get = l4;
    l2 = (void*) _a15_obj;
    l3 = ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_blocks;
    l7 = ((vader_array_t*) l3)->length;
    l8 = INT64_C(0);
    while ((l8 < l7)) {
        vader_array_t* _a16_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a16_slotarr)
        l4 = vader_array_ref_load_obj(_a16_slotarr->buf, _a16_slotarr->offset + (size_t) l8);
        l9 = INT64_C(0);
        l10 = ((vader_array_t*) ((vader_struct_vader_midir$BasicBlock_t*) l4)->f_instructions)->length;
        while ((l9 < l10)) {
            l11 = vader_chk_add(i64, l9, INT64_C(1));
            l12 = ((vader_array_t*) ((vader_struct_vader_midir$BasicBlock_t*) l4)->f_instructions)->length;
            if ((l11 >= l12)) break;
            vader_array_t* _a17_slotarr = ((vader_array_t*) ((vader_struct_vader_midir$BasicBlock_t*) l4)->f_instructions);
            VADER_ARRAY_RESOLVE_BUF(_a17_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a17_slotarr, l9)
            l13 = vader_array_ref_load_box(_a17_slotarr->buf, _a17_slotarr->offset + (size_t) l9);
            l5 = ((vader_struct_vader_midir$BasicBlock_t*) l4)->f_instructions;
            l14 = vader_chk_add(i64, l9, INT64_C(1));
            vader_array_t* _a18_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a18_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a18_slotarr, l14)
            l15 = vader_array_ref_load_box(_a18_slotarr->buf, _a18_slotarr->offset + (size_t) l14);
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
        t2 = ((vader_array_t*) ((vader_struct_vader_midir$BasicBlock_t*) l4)->f_instructions)->length;
        if (t2 == INT64_C(0)) {
            l8 = (l8 + INT64_C(1));
            continue;
        }
        t2 = ((vader_array_t*) ((vader_struct_vader_midir$BasicBlock_t*) l4)->f_instructions)->length;
        l21 = vader_chk_sub(i64, t2, INT64_C(1));
        vader_array_t* _a19_slotarr = ((vader_array_t*) ((vader_struct_vader_midir$BasicBlock_t*) l4)->f_instructions);
        VADER_ARRAY_RESOLVE_BUF(_a19_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a19_slotarr, l21)
        l22 = vader_array_ref_load_box(_a19_slotarr->buf, _a19_slotarr->offset + (size_t) l21);
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
    l3 = ((vader_array_t*) ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_blocks)->length;
    l4 = vader_midir$reverse_postorder(l0);
    l5 = vader_midir$rpo_positions(l4, l3);
    l6 = vader_midir$natural_loop_bodies(l0, l1, l2);
    vader_array_t* _a0_arr = vader_array_new(20u, 1u, 12u, 445u);
    ((uint8_t*) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = (uint8_t) false;
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l3);
    l7 = (void*) _a1_arr;
    l8 = l6;
    l9 = ((vader_struct_std_collections$MutableMap__i32__std_collections_MutableSet_i32__t*) l8)->f_ekeys;
    l10 = ((vader_struct_std_collections$MutableMap__i32__std_collections_MutableSet_i32__t*) l8)->f_evals;
    l11 = INT64_C(0);
    l12 = ((vader_struct_std_collections$MutableMap__i32__std_collections_MutableSet_i32__t*) l8)->f_size;
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
    vader_array_t* _a5_arr = vader_array_new(23u, 1u, 7u, 450u);
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
                t2 = vader_emit_bytecode$closes_loop(l6, l17, l13);
                if (!(t2)) {
                    l25 = ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_mangled;
                    l26 = vader_host_std_core$byte_len(l25);
                    l27 = (void*) vader_buffer_new((size_t) (INT64_C(135) + l26));
                    l28 = INT64_C(0);
                    l28 = std_core$write_string_at(l27, l28, 1870u);
                    l28 = std_core$write_string_at(l27, l28, l25);
                    l28 = std_core$write_string_at(l27, l28, 302u);
                    l29 = ((int64_t) (int32_t) l17);
                    l28 = std_core$write_int(l27, l28, l29);
                    l28 = std_core$write_string_at(l27, l28, 245u);
                    l30 = ((int64_t) (int32_t) l13);
                    l28 = std_core$write_int(l27, l28, l30);
                    l28 = std_core$write_string_at(l27, l28, 116u);
                    t3 = std_core$finish_buffer(l27, l28);
                    vader_host_std_abort$panic(t3);
                    vader_unreachable("a no-return call returned");
                }
            }
            l16 = (l16 + INT64_C(1));
        }
        l12 = (l12 + INT64_C(1));
    }
    vader_array_t* _a13_arr = vader_array_new(20u, 1u, 12u, 445u);
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
        t2 = ((uint8_t*) _a16_slotarr->buf->slots)[_a16_slotarr->offset + (size_t) l17];
        t6 = t2;
        if (t6) {
            l31 = true;
        } else {
            l18 = l13;
            vader_array_t* _a17_slotarr = ((vader_array_t*) l7);
            VADER_ARRAY_RESOLVE_BUF(_a17_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a17_slotarr, l18)
            t2 = ((uint8_t*) _a17_slotarr->buf->slots)[_a17_slotarr->offset + (size_t) l18];
            l31 = t2;
        }
        vader_array_t* _a18_slotarr = ((vader_array_t*) l9);
        VADER_ARRAY_RESOLVE_BUF(_a18_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a18_slotarr, l14)
        ((uint8_t*) _a18_slotarr->buf->slots)[_a18_slotarr->offset + (size_t) l14] = (uint8_t) l31;
        l19 = ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_entry;
        t2 = vader_midir$BlockId$std_core$Equals$equals(l13, l19);
        if (!(t2)) {
            l20 = l13;
            vader_array_t* _a19_slotarr = ((vader_array_t*) l9);
            VADER_ARRAY_RESOLVE_BUF(_a19_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a19_slotarr, l20)
            t2 = ((uint8_t*) _a19_slotarr->buf->slots)[_a19_slotarr->offset + (size_t) l20];
            t6 = t2;
            if (t6) {
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
    vader_array_t* _a22_arr = vader_array_new(20u, 1u, 12u, 445u);
    ((uint8_t*) _a22_arr->buf->slots)[_a22_arr->offset + 0u] = (uint8_t) false;
    t0 = (void*) _a22_arr;
    vader_array_t* _a23_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l3);
    l10 = (void*) _a23_arr;
    vader_array_t* _a24_arr = vader_array_new(20u, 1u, 12u, 445u);
    ((uint8_t*) _a24_arr->buf->slots)[_a24_arr->offset + 0u] = (uint8_t) false;
    t0 = (void*) _a24_arr;
    vader_array_t* _a25_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l3);
    l27 = (void*) _a25_arr;
    vader_array_t* _a26_arr = vader_array_new(3u, 0u, 13u, 23u);
    l32 = (void*) _a26_arr;
    if ((INT64_C(0) < l3)) {
        l11 = l3;
    } else {
        l11 = INT64_C(0);
    }
    vader_array_t* _a27_arr = vader_array_repeat((vader_array_t*) l32, (int64_t) l11);
    l32 = (void*) _a27_arr;
    vader_array_t* _a28_arr = vader_array_new(3u, 0u, 13u, 23u);
    l33 = (void*) _a28_arr;
    if ((INT64_C(0) < l3)) {
        l11 = l3;
    } else {
        l11 = INT64_C(0);
    }
    vader_array_t* _a29_arr = vader_array_repeat((vader_array_t*) l33, (int64_t) l11);
    l33 = (void*) _a29_arr;
    vader_array_t* _a30_arr = vader_array_new(23u, 1u, 7u, 450u);
    ((int32_t*) _a30_arr->buf->slots)[_a30_arr->offset + 0u] = (int32_t) INT32_C(-1);
    t0 = (void*) _a30_arr;
    vader_array_t* _a31_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l3);
    l34 = (void*) _a31_arr;
    l11 = INT64_C(0);
    while ((l11 < l3)) {
        vader_array_t* _a32_arr = vader_array_new(23u, 0u, 7u, 450u);
        l35 = (void*) _a32_arr;
        vader_array_push_ref((vader_array_t*) l32, l35);
        vader_array_t* _a33_arr = vader_array_new(23u, 0u, 7u, 450u);
        l36 = (void*) _a33_arr;
        vader_array_push_ref((vader_array_t*) l33, l36);
        l11 = (l11 + INT64_C(1));
    }
    l3 = ((vader_array_t*) l4)->length;
    l11 = INT64_C(0);
    while ((l11 < l3)) {
        vader_array_t* _a34_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a34_slotarr)
        l13 = ((int32_t*) _a34_slotarr->buf->slots)[_a34_slotarr->offset + (size_t) l11];
        l14 = ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_entry;
        t2 = vader_midir$BlockId$std_core$Equals$equals(l13, l14);
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
            t2 = vader_emit_bytecode$entered_by_test(l6, l35, l13);
            l31 = !(t2);
        } else {
            l31 = false;
        }
        if (l31) {
            l36 = ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_blocks;
            l19 = l13;
            vader_array_t* _a37_slotarr = ((vader_array_t*) l36);
            VADER_ARRAY_RESOLVE_BUF(_a37_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a37_slotarr, l19)
            t0 = vader_array_ref_load_obj(_a37_slotarr->buf, _a37_slotarr->offset + (size_t) l19);
            t2 = vader_emit_bytecode$copies_cheaply(t0);
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
        l24 = vader_emit_bytecode$outermost_loop_left(l6, l5, l23, l13);
        if ((l24 >= INT32_C(0))) {
            l37 = l24;
            l38 = vader_emit_bytecode$tests_its_exit(l0, l6, l37);
            l39 = ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_blocks;
            l40 = l13;
            vader_array_t* _a40_slotarr = ((vader_array_t*) l39);
            VADER_ARRAY_RESOLVE_BUF(_a40_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a40_slotarr, l40)
            t0 = vader_array_ref_load_obj(_a40_slotarr->buf, _a40_slotarr->offset + (size_t) l40);
            l41 = vader_emit_bytecode$ends_function(((vader_struct_vader_midir$BasicBlock_t*) t0)->f_terminator);
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
                t2 = ((uint8_t*) _a42_slotarr->buf->slots)[_a42_slotarr->offset + (size_t) l44];
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
                vader_array_t* _a43_slotarr = ((vader_array_t*) l1);
                VADER_ARRAY_RESOLVE_BUF(_a43_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a43_slotarr, l50)
                t0 = vader_array_ref_load_obj(_a43_slotarr->buf, _a43_slotarr->offset + (size_t) l50);
                t2 = vader_emit_bytecode$emitted_beneath(t0, l5, l2, l34, l22);
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
    vader_struct_vader_emit_bytecode$StructureShape_t* _a50_obj = (vader_struct_vader_emit_bytecode$StructureShape_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_bytecode$StructureShape_t));
    vader_obj_header_init(_a50_obj, 1052u);
    _a50_obj->f_rpo_index = l5;
    _a50_obj->f_loop_header = l7;
    _a50_obj->f_merge = l10;
    _a50_obj->f_merges = l32;
    _a50_obj->f_exits = l33;
    _a50_obj->f_copied = l27;
    t0 = (void*) _a50_obj;
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
    l1 = ((vader_array_t*) ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_blocks)->length;
    vader_array_t* _a0_arr = vader_array_new(23u, 1u, 7u, 450u);
    ((int32_t*) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = (int32_t) INT32_C(0);
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l1);
    l2 = (void*) _a1_arr;
    l3 = ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_blocks;
    l4 = ((vader_array_t*) l3)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        t0 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l5);
        l6 = vader_midir$successors_of(t0);
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
    vader_array_t* _a5_arr = vader_array_new(23u, 1u, 7u, 450u);
    ((int32_t*) _a5_arr->buf->slots)[_a5_arr->offset + 0u] = (int32_t) INT32_C(-1);
    t0 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l1);
    l3 = (void*) _a6_arr;
    l11 = false;
    vader_array_t* _a7_arr = vader_array_new(23u, 0u, 7u, 450u);
    l6 = (void*) _a7_arr;
    l12 = ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_blocks;
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
            l14 = ((vader_struct_vader_midir$BasicBlock_t*) l13)->f_terminator;
            t2 = ((vader_array_t*) ((vader_struct_vader_midir$BasicBlock_t*) l13)->f_instructions)->length;
            if (t2 == INT64_C(0)) {
                if (l14.tag == 1494u) {
                    l9 = ((vader_struct_vader_midir$BasicBlock_t*) l13)->f_id;
                    vader_array_t* _a9_slotarr = ((vader_array_t*) l2);
                    VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l9)
                    t1 = ((int32_t*) _a9_slotarr->buf->slots)[_a9_slotarr->offset + (size_t) l9];
                    if ((t1 < INT32_C(2))) {
                        l10 = ((vader_struct_vader_midir$BasicBlock_t*) l13)->f_id;
                        t0 = l14.payload.obj;
                        l15 = ((vader_struct_vader_midir$TermBranch_t*) t0)->f_target;
                        vader_array_t* _a10_slotarr = ((vader_array_t*) l3);
                        VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a10_slotarr, l10)
                        ((int32_t*) _a10_slotarr->buf->slots)[_a10_slotarr->offset + (size_t) l10] = (int32_t) l15;
                        l11 = true;
                    } else {
                        l16 = ((vader_struct_vader_midir$BasicBlock_t*) l13)->f_id;
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
        l2 = vader_midir$predecessors_of(l0);
        l12 = vader_midir$compute_dominators(l0, l2);
        l12 = vader_midir$natural_loop_bodies(l0, l2, l12);
        l1 = ((vader_array_t*) l6)->length;
        l4 = INT64_C(0);
        while ((l4 < l1)) {
            vader_array_t* _a11_slotarr = ((vader_array_t*) l6);
            VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
            l9 = ((int32_t*) _a11_slotarr->buf->slots)[_a11_slotarr->offset + (size_t) l4];
            l13 = ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_blocks;
            l10 = l9;
            vader_array_t* _a12_slotarr = ((vader_array_t*) l13);
            VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a12_slotarr, l10)
            t0 = vader_array_ref_load_obj(_a12_slotarr->buf, _a12_slotarr->offset + (size_t) l10);
            l14 = ((vader_struct_vader_midir$BasicBlock_t*) t0)->f_terminator;
            if (l14.tag == 1494u) {
                l15 = l9;
                vader_array_t* _a13_slotarr = ((vader_array_t*) l2);
                VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a13_slotarr, l15)
                l17 = vader_array_ref_load_obj(_a13_slotarr->buf, _a13_slotarr->offset + (size_t) l15);
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
    vader_array_t* _a15_arr = vader_array_new(307u, 0u, 13u, 1428u);
    l2 = (void*) _a15_arr;
    l1 = ((vader_array_t*) ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_blocks)->length;
    vader_array_t* _a16_arr = vader_array_repeat((vader_array_t*) l2, (int64_t) l1);
    l2 = (void*) _a16_arr;
    l6 = ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_blocks;
    l1 = ((vader_array_t*) l6)->length;
    l4 = INT64_C(0);
    while ((l4 < l1)) {
        vader_array_t* _a17_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a17_slotarr)
        l12 = vader_array_ref_load_obj(_a17_slotarr->buf, _a17_slotarr->offset + (size_t) l4);
        l13 = l12;
        l9 = ((vader_struct_vader_midir$BasicBlock_t*) l13)->f_id;
        l17 = ((vader_struct_vader_midir$BasicBlock_t*) l13)->f_instructions;
        l14 = ((vader_struct_vader_midir$BasicBlock_t*) l12)->f_terminator;
        l20 = vader_emit_bytecode$retargeted(l3, l14);
        l21 = ((vader_struct_vader_midir$BasicBlock_t*) l13)->f_span;
        vader_struct_vader_midir$BasicBlock_t* _a18_obj = (vader_struct_vader_midir$BasicBlock_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$BasicBlock_t));
        vader_obj_header_init(_a18_obj, 1428u);
        _a18_obj->f_id = l9;
        _a18_obj->f_instructions = l17;
        _a18_obj->f_terminator = l20;
        _a18_obj->f_span = l21;
        l22 = (void*) _a18_obj;
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
    vader_struct_vader_midir$CFGFunction_t* _a19_obj = (vader_struct_vader_midir$CFGFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$CFGFunction_t));
    vader_obj_header_init(_a19_obj, 1430u);
    _a19_obj->f_mangled = l23;
    _a19_obj->f_params = l6;
    _a19_obj->f_return_type = l14;
    _a19_obj->f_locals = l12;
    _a19_obj->f_blocks = l2;
    _a19_obj->f_entry = l9;
    _a19_obj->f_origin = l13;
    _a19_obj->f_scalarised_results = l3;
    t0 = (void*) _a19_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_emit_bytecode$strip_self_copies(void* l0) {
    void* l1 = NULL;
    void* l3 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    int64_t l2, l5, l9, l11;
    bool l4;
    vader_box_t l8 = vader_box_null();
    int32_t l10, l12;
    bool t0;
    void* t1 = NULL;
    vader_box_t t2 = vader_box_null();
    int64_t t3;
    vader_box_t* gc_roots[2] = { &l8, &t2 };
    void** gc_raw_roots[6] = { &l0, &l1, &l3, &l6, &l7, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 6u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_body;
    l2 = ((vader_array_t*) l1)->length;
    l3 = vader_core_bytecode$mark_jump_targets(((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_jump_table, l2);
    l4 = false;
    l5 = INT64_C(0);
    while ((l5 < l2)) {
        t0 = vader_emit_bytecode$foldable_self_copy(l1, l5, l2, l3);
        if (t0) {
            l4 = true;
            break;
        }
        l5 = vader_chk_add(i64, l5, INT64_C(1));
    }
    if (!(l4)) {
        t1 = vader_emit_bytecode$bc_peephole_unchanged(l0);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a0_arr = vader_array_new(358u, 0u, 13u, 1803u);
    l6 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(23u, 1u, 7u, 450u);
    ((int32_t*) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = (int32_t) INT32_C(-1);
    t1 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_repeat((vader_array_t*) t1, (int64_t) l2);
    l7 = (void*) _a2_arr;
    l5 = INT64_C(0);
    while ((l5 < l2)) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l5)
        l8 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l5);
        t0 = vader_emit_bytecode$foldable_self_copy(l1, l5, l2, l3);
        if (t0) {
            l9 = vader_chk_add(i64, l5, INT64_C(1));
            vader_array_t* _a4_slotarr = ((vader_array_t*) l1);
            VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l9)
            t2 = vader_array_ref_load_box(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l9);
            if (t2.tag == 967u) {
                t3 = ((vader_array_t*) l6)->length;
                l10 = ((int32_t) (int64_t) t3);
                vader_array_t* _a5_slotarr = ((vader_array_t*) l7);
                VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l5)
                ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l5] = (int32_t) l10;
                vader_array_push_ref((vader_array_t*) l6, l8.payload.obj);
            } else {
                vader_array_t* _a6_slotarr = ((vader_array_t*) l7);
                VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l5)
                ((int32_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l5] = (int32_t) INT32_C(-1);
            }
            l11 = vader_chk_add(i64, l5, INT64_C(1));
            vader_array_t* _a7_slotarr = ((vader_array_t*) l7);
            VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l11)
            ((int32_t*) _a7_slotarr->buf->slots)[_a7_slotarr->offset + (size_t) l11] = (int32_t) INT32_C(-1);
            l5 = vader_chk_add(i64, l5, INT64_C(2));
            continue;
        }
        t3 = ((vader_array_t*) l6)->length;
        l12 = ((int32_t) (int64_t) t3);
        vader_array_t* _a8_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l5)
        ((int32_t*) _a8_slotarr->buf->slots)[_a8_slotarr->offset + (size_t) l5] = (int32_t) l12;
        vader_array_push_ref((vader_array_t*) l6, l8.payload.obj);
        l5 = vader_chk_add(i64, l5, INT64_C(1));
    }
    l1 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_jump_table;
    l2 = ((vader_array_t*) l6)->length;
    l1 = vader_core_bytecode$remap_jump_table(l1, l7, l2);
    l3 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_debug;
    l2 = ((vader_array_t*) l6)->length;
    l3 = vader_emit_bytecode$remap_debug(l3, l7, l2);
    vader_struct_vader_emit_bytecode$BcPeepholeOut_t* _a9_obj = (vader_struct_vader_emit_bytecode$BcPeepholeOut_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_bytecode$BcPeepholeOut_t));
    vader_obj_header_init(_a9_obj, 1043u);
    _a9_obj->f_body = l6;
    _a9_obj->f_jump_table = l1;
    _a9_obj->f_debug = l3;
    t1 = (void*) _a9_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static int32_t vader_emit_bytecode$struct_symbol_id(vader_box_t l0) {
    void* t0;
    int32_t t1;
    if (!(l0.tag == 1033u)) {
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
    t0 = ((vader_array_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_pending)->length;
    if (!((t0 > INT64_C(0)))) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l5 = ((vader_struct_vader_midir$CFGFunction_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_fn_)->f_mangled;
    l6 = vader_host_std_core$byte_len(l5);
    l1 = (void*) vader_buffer_new((size_t) (INT64_C(87) + l6));
    l6 = INT64_C(0);
    l6 = std_core$write_string_at(l1, l6, 1870u);
    l6 = std_core$write_string_at(l1, l6, l5);
    l6 = std_core$write_string_at(l1, l6, 301u);
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_pending);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
    t1 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT32_C(0));
    l7 = ((int64_t) (int32_t) ((vader_struct_vader_emit_bytecode$PendingBranch_t*) t1)->f_target_blk);
    l6 = std_core$write_int(l1, l6, l7);
    l6 = std_core$write_string_at(l1, l6, 135u);
    t2 = std_core$finish_buffer(l1, l6);
    vader_host_std_abort$panic(t2);
    vader_unreachable("a no-return call returned");
    vader_gc_top = gc_frame.prev;
}

static void vader_emit_bytecode$synthesise_cfg_intrinsic_wrappers(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    void* l15 = NULL;
    void* l16 = NULL;
    void* l17 = NULL;
    void* l19 = NULL;
    void* l21 = NULL;
    void* l22 = NULL;
    void* l23 = NULL;
    void* l24 = NULL;
    int64_t l5, l6;
    vader_string_t l7 = 0;
    vader_string_t l11 = 0;
    vader_string_t l20 = 0;
    vader_string_t l25 = 0;
    int32_t l8, l9, l10, l18;
    void* t0 = NULL;
    int64_t t1;
    bool t2;
    vader_box_t t3 = vader_box_null();
    vader_string_t t4 = 0;
    vader_box_t* gc_roots[1] = { &t3 };
    void** gc_raw_roots[17] = {
        &l0, &l1, &l2, &l3, &l4, &l12, &l13, &l14, &l15, &l16, &l17, &l19, &l21, &l22, &l23, &l24,
        &t0,
    };
    vader_string_t* gc_atom_roots[5] = { &l7, &l11, &l20, &l25, &t4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 17u, gc_roots, gc_raw_roots, 0u, NULL, 5u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(22u, 0u, 0u, 447u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(20u, 0u, 12u, 445u);
    l3 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(23u, 0u, 7u, 450u);
    l4 = (void*) _a2_arr;
    vader_struct_std_collections$MutableMap__string__bool_t* _a3_obj = (vader_struct_std_collections$MutableMap__string__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__string__bool_t));
    vader_obj_header_init(_a3_obj, 662u);
    _a3_obj->f_ekeys = l2;
    _a3_obj->f_evals = l3;
    _a3_obj->f_index = l4;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    l2 = (void*) _a3_obj;
    l3 = ((vader_struct_vader_midir$CFGProject_t*) l0)->f_vtable_entries;
    l5 = ((vader_array_t*) l3)->length;
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        t0 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l6);
        l7 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_lower_ir$LoweredVtableEntry_t*) t0)->f_fn_symbol)->f_name;
        std_collections$MutableMap$std_core$IndexSet$set_at__string__bool(l2, l7, true);
        l6 = (l6 + INT64_C(1));
    }
    t1 = ((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l1)->f_imports)->length;
    l8 = ((int32_t) (int64_t) t1);
    l9 = INT32_C(0);
    while ((l9 < l8)) {
        vader_array_t* _a5_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l1)->f_imports);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l9)
        l3 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l9);
        l10 = l9;
        l9 = vader_chk_add(i32, l9, INT32_C(1));
        t2 = ((vader_struct_vader_core_bytecode$BcImport_t*) l3)->f_is_extern;
        if (t2) {
            continue;
        }
        l7 = ((vader_struct_vader_core_bytecode$BcImport_t*) l3)->f_mangled_name;
        t3 = std_collections$MutableMap$std_core$Index$at__string__bool(l2, l7);
        if (t3.tag == 0u) {
            continue;
        }
        l4 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l1)->f_function_index_by_mangle;
        l11 = ((vader_struct_vader_core_bytecode$BcImport_t*) l3)->f_mangled_name;
        t3 = std_collections$MutableMap$std_core$Index$at__string__i32(l4, l11);
        if (t3.tag == 450u) {
            continue;
        }
        l12 = vader_emit_bytecode$build_intrinsic_wrapper_body(l3, l10);
        vader_array_t* _a6_arr = vader_array_new(362u, 1u, 13u, 1863u);
        ((void**) _a6_arr->buf->slots)[_a6_arr->offset + 0u] = vader_box_obj(0u, NULL).payload.obj;
        l13 = (void*) _a6_arr;
        l5 = ((vader_array_t*) l12)->length;
        vader_array_t* _a7_arr = vader_array_repeat((vader_array_t*) l13, (int64_t) l5);
        l14 = (void*) _a7_arr;
        vader_array_t* _a8_arr = vader_array_new(23u, 1u, 7u, 450u);
        ((int32_t*) _a8_arr->buf->slots)[_a8_arr->offset + 0u] = (int32_t) INT32_C(-1);
        l15 = (void*) _a8_arr;
        l6 = ((vader_array_t*) l12)->length;
        vader_array_t* _a9_arr = vader_array_repeat((vader_array_t*) l15, (int64_t) l6);
        l16 = (void*) _a9_arr;
        vader_array_t* _a10_arr = vader_array_new(73u, 0u, 13u, 855u);
        l17 = (void*) _a10_arr;
        t1 = ((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l1)->f_functions)->length;
        l18 = ((int32_t) (int64_t) t1);
        l19 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l1)->f_functions;
        t4 = ((vader_struct_vader_core_bytecode$BcImport_t*) l3)->f_mangled_name;
        l20 = concat_2(t4, 1030u);
        l21 = ((vader_struct_vader_core_bytecode$BcImport_t*) l3)->f_signature;
        vader_array_t* _a11_arr = vader_array_new(23u, 0u, 7u, 450u);
        l22 = (void*) _a11_arr;
        vader_struct_vader_core_bytecode$BcFunction_t* _a12_obj = (vader_struct_vader_core_bytecode$BcFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcFunction_t));
        vader_obj_header_init(_a12_obj, 852u);
        _a12_obj->f_name = l20;
        _a12_obj->f_is_main = false;
        _a12_obj->f_signature = l21;
        _a12_obj->f_locals = l17;
        _a12_obj->f_body = l12;
        _a12_obj->f_debug = l14;
        _a12_obj->f_jump_table = l16;
        _a12_obj->f_source_pc = l22;
        l23 = (void*) _a12_obj;
        vader_array_push_ref((vader_array_t*) l19, l23);
        l24 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l1)->f_function_index_by_mangle;
        l25 = ((vader_struct_vader_core_bytecode$BcImport_t*) l3)->f_mangled_name;
        std_collections$MutableMap$std_core$IndexSet$set_at__string__i32(l24, l25, l18);
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static bool vader_emit_bytecode$tests_its_exit(void* l0, void* l1, int32_t l2) {
    void* l3;
    void* l5;
    vader_box_t l4;
    int32_t l6;
    bool l7;
    void* t0;
    bool t1;
    l4 = std_collections$MutableMap$std_core$Index$at__i32__Any(l1, l2);
    if (l4.tag == 0u) {
        return false;
    }
    l3 = l4.payload.obj;
    l5 = ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_blocks;
    l6 = l2;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l6)
    t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l6);
    l4 = ((vader_struct_vader_midir$BasicBlock_t*) t0)->f_terminator;
    if (l4.tag == 1495u) {
        t0 = l4.payload.obj;
        l6 = ((vader_struct_vader_midir$TermCondBranch_t*) t0)->f_then_block;
        t1 = std_collections$MutableSet$std_core$Contains$contains__i32(l3, l6);
        if (!(t1)) {
            l7 = true;
        } else {
            t0 = l4.payload.obj;
            l6 = ((vader_struct_vader_midir$TermCondBranch_t*) t0)->f_else_block;
            t1 = std_collections$MutableSet$std_core$Contains$contains__i32(l3, l6);
            l7 = !(t1);
        }
        return l7;
    }
    return false;
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
    l4 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
    l3 = vader_chk_sub(i64, l2, INT64_C(2));
    l5 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
    if (l5.tag == 920u) {
        if (l4.tag == 920u) {
            if (l0.tag == 915u) {
                t0 = l5.payload.obj;
                l6 = ((vader_struct_vader_core_bytecode$I32Const_t*) t0)->f_value;
                t0 = l4.payload.obj;
                l7 = ((vader_struct_vader_core_bytecode$I32Const_t*) t0)->f_value;
                vader_struct_vader_core_bytecode$I32Const_t* _a1_obj = (vader_struct_vader_core_bytecode$I32Const_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$I32Const_t));
                vader_obj_header_init(_a1_obj, 920u);
                _a1_obj->f_value = (l6 + l7);
                t0 = (void*) _a1_obj;
                { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
            }
            if (l0.tag == 934u) {
                t0 = l5.payload.obj;
                l6 = ((vader_struct_vader_core_bytecode$I32Const_t*) t0)->f_value;
                t0 = l4.payload.obj;
                l7 = ((vader_struct_vader_core_bytecode$I32Const_t*) t0)->f_value;
                vader_struct_vader_core_bytecode$I32Const_t* _a2_obj = (vader_struct_vader_core_bytecode$I32Const_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$I32Const_t));
                vader_obj_header_init(_a2_obj, 920u);
                _a2_obj->f_value = (l6 - l7);
                t0 = (void*) _a2_obj;
                { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
            }
            if (l0.tag == 928u) {
                t0 = l5.payload.obj;
                l6 = ((vader_struct_vader_core_bytecode$I32Const_t*) t0)->f_value;
                t0 = l4.payload.obj;
                l7 = ((vader_struct_vader_core_bytecode$I32Const_t*) t0)->f_value;
                vader_struct_vader_core_bytecode$I32Const_t* _a3_obj = (vader_struct_vader_core_bytecode$I32Const_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$I32Const_t));
                vader_obj_header_init(_a3_obj, 920u);
                _a3_obj->f_value = (l6 * l7);
                t0 = (void*) _a3_obj;
                { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
            }
            if (l0.tag == 887u) {
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
                vader_obj_header_init(_a4_obj, 920u);
                _a4_obj->f_value = ((int32_t) (int64_t) t2);
                t0 = (void*) _a4_obj;
                { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
            }
        }
    }
    if (l5.tag == 940u) {
        if (l4.tag == 940u) {
            if (l0.tag == 935u) {
                t0 = l5.payload.obj;
                l3 = ((vader_struct_vader_core_bytecode$I64Const_t*) t0)->f_value;
                t0 = l4.payload.obj;
                l8 = ((vader_struct_vader_core_bytecode$I64Const_t*) t0)->f_value;
                vader_struct_vader_core_bytecode$I64Const_t* _a5_obj = (vader_struct_vader_core_bytecode$I64Const_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$I64Const_t));
                vader_obj_header_init(_a5_obj, 940u);
                _a5_obj->f_value = (l3 + l8);
                t0 = (void*) _a5_obj;
                { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
            }
            if (l0.tag == 954u) {
                t0 = l5.payload.obj;
                l3 = ((vader_struct_vader_core_bytecode$I64Const_t*) t0)->f_value;
                t0 = l4.payload.obj;
                l8 = ((vader_struct_vader_core_bytecode$I64Const_t*) t0)->f_value;
                vader_struct_vader_core_bytecode$I64Const_t* _a6_obj = (vader_struct_vader_core_bytecode$I64Const_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$I64Const_t));
                vader_obj_header_init(_a6_obj, 940u);
                _a6_obj->f_value = (l3 - l8);
                t0 = (void*) _a6_obj;
                { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
            }
            if (l0.tag == 948u) {
                t0 = l5.payload.obj;
                l3 = ((vader_struct_vader_core_bytecode$I64Const_t*) t0)->f_value;
                t0 = l4.payload.obj;
                l8 = ((vader_struct_vader_core_bytecode$I64Const_t*) t0)->f_value;
                vader_struct_vader_core_bytecode$I64Const_t* _a7_obj = (vader_struct_vader_core_bytecode$I64Const_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$I64Const_t));
                vader_obj_header_init(_a7_obj, 940u);
                _a7_obj->f_value = (l3 * l8);
                t0 = (void*) _a7_obj;
                { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
            }
            if (l0.tag == 887u) {
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
                vader_obj_header_init(_a8_obj, 940u);
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
    l3 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_slot)->f_body)->length;
    if (l3 == INT64_C(0)) {
        { vader_gc_top = gc_frame.prev; return false; }
    }
    l4 = ((vader_struct_vader_core_bytecode$BcFunction_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_slot)->f_body;
    l5 = vader_chk_sub(i64, l3, INT64_C(1));
    vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
    l6 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
    if (!(l6.tag == 965u)) {
        { vader_gc_top = gc_frame.prev; return false; }
    }
    t0 = l6.payload.obj;
    l7 = ((vader_struct_vader_core_bytecode$LocalGet_t*) t0)->f_slot;
    l4 = ((vader_struct_vader_core_bytecode$BcFunction_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_slot)->f_body;
    l3 = vader_chk_sub(i64, l3, INT64_C(1));
    vader_struct_vader_core_bytecode$LocalField_t* _a1_obj = (vader_struct_vader_core_bytecode$LocalField_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$LocalField_t));
    vader_obj_header_init(_a1_obj, 964u);
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

static int32_t vader_emit_bytecode$type_index_of(vader_box_t l0) {
    int32_t l1;
    void* t0;
    if (l0.tag == 991u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_core_bytecode$StructNew_t*) t0)->f_type_id;
        return l1;
    }
    if (l0.tag == 990u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_core_bytecode$StructGet_t*) t0)->f_type_id;
    } else if (l0.tag == 992u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_core_bytecode$StructSet_t*) t0)->f_type_id;
    } else if (l0.tag == 1007u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_core_bytecode$UnionFieldGet_t*) t0)->f_type_id;
    } else if (l0.tag == 1008u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_core_bytecode$UnionFieldSet_t*) t0)->f_type_id;
    } else if (l0.tag == 840u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_core_bytecode$ArrayNew_t*) t0)->f_type_id;
    } else if (l0.tag == 838u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_core_bytecode$ArrayGet_t*) t0)->f_type_id;
    } else if (l0.tag == 845u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_core_bytecode$ArraySet_t*) t0)->f_type_id;
    } else if (l0.tag == 841u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_core_bytecode$ArrayPush_t*) t0)->f_type_id;
    } else if (l0.tag == 993u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_core_bytecode$TypeCheck_t*) t0)->f_type_id;
    } else if (l0.tag == 994u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_core_bytecode$TypeConst_t*) t0)->f_type_id;
    } else if (l0.tag == 885u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_core_bytecode$CallIndirect_t*) t0)->f_type_id;
    } else if (l0.tag == 969u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_core_bytecode$MakeClosure_t*) t0)->f_env_type_id;
    } else if (l0.tag == 912u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_core_bytecode$FnRef_t*) t0)->f_type_id;
    } else if (l0.tag == 964u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_core_bytecode$LocalField_t*) t0)->f_type_id;
    } else if (l0.tag == 846u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_core_bytecode$ArraySlice_t*) t0)->f_type_id;
    } else if (l0.tag == 972u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_core_bytecode$RefCast_t*) t0)->f_type_id;
    } else if (l0.tag == 975u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_core_bytecode$Retag_t*) t0)->f_type_id;
    } else if (l0.tag == 890u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_core_bytecode$DataConst_t*) t0)->f_type_id;
    } else {
        if (!((l0.tag == 836u || l0.tag == 837u || l0.tag == 839u || l0.tag == 842u || l0.tag == 843u || l0.tag == 844u || l0.tag == 867u || l0.tag == 868u || l0.tag == 869u || l0.tag == 870u || l0.tag == 871u || l0.tag == 872u || l0.tag == 873u || l0.tag == 874u || l0.tag == 875u || l0.tag == 876u || l0.tag == 877u || l0.tag == 878u || l0.tag == 879u || l0.tag == 880u || l0.tag == 883u || l0.tag == 884u || l0.tag == 886u || l0.tag == 887u || l0.tag == 888u || l0.tag == 889u || l0.tag == 892u || l0.tag == 893u || l0.tag == 894u || l0.tag == 895u || l0.tag == 896u || l0.tag == 897u || l0.tag == 898u || l0.tag == 899u || l0.tag == 900u || l0.tag == 901u || l0.tag == 902u || l0.tag == 903u || l0.tag == 904u || l0.tag == 905u || l0.tag == 906u || l0.tag == 907u || l0.tag == 908u || l0.tag == 909u || l0.tag == 910u || l0.tag == 911u || l0.tag == 913u || l0.tag == 914u || l0.tag == 915u || l0.tag == 916u || l0.tag == 917u || l0.tag == 918u || l0.tag == 919u || l0.tag == 920u || l0.tag == 921u || l0.tag == 922u || l0.tag == 923u || l0.tag == 924u || l0.tag == 925u || l0.tag == 926u || l0.tag == 927u || l0.tag == 928u || l0.tag == 929u || l0.tag == 930u || l0.tag == 931u || l0.tag == 932u || l0.tag == 933u || l0.tag == 934u || l0.tag == 935u || l0.tag == 936u || l0.tag == 937u || l0.tag == 938u || l0.tag == 939u || l0.tag == 940u || l0.tag == 941u || l0.tag == 942u || l0.tag == 943u || l0.tag == 944u || l0.tag == 945u || l0.tag == 946u || l0.tag == 947u || l0.tag == 948u || l0.tag == 949u || l0.tag == 950u || l0.tag == 951u || l0.tag == 952u || l0.tag == 953u || l0.tag == 954u || l0.tag == 955u || l0.tag == 957u || l0.tag == 958u || l0.tag == 959u || l0.tag == 960u || l0.tag == 961u || l0.tag == 962u || l0.tag == 963u || l0.tag == 965u || l0.tag == 966u || l0.tag == 967u || l0.tag == 968u || l0.tag == 970u || l0.tag == 971u || l0.tag == 973u || l0.tag == 974u || l0.tag == 976u || l0.tag == 977u || l0.tag == 978u || l0.tag == 979u || l0.tag == 980u || l0.tag == 981u || l0.tag == 982u || l0.tag == 983u || l0.tag == 984u || l0.tag == 985u || l0.tag == 986u || l0.tag == 987u || l0.tag == 988u || l0.tag == 989u || l0.tag == 995u || l0.tag == 996u || l0.tag == 997u || l0.tag == 998u || l0.tag == 999u || l0.tag == 1000u || l0.tag == 1001u || l0.tag == 1002u || l0.tag == 1003u || l0.tag == 1004u || l0.tag == 1005u || l0.tag == 1006u || l0.tag == 1009u || l0.tag == 1010u))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = INT32_C(-1);
    }
    return l1;
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
    l4 = ((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l1)->f_types)->length;
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
    l5 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l0);
    if (l5.tag == 861u) {
        t1 = l5.payload.obj;
        l6 = ((vader_struct_vader_core_bytecode$BcStruct_t*) t1)->f_fields;
        l3 = ((vader_array_t*) l6)->length;
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l6);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            t1 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
            t2 = ((vader_struct_vader_core_bytecode$BcField_t*) t1)->f_type_index;
            vader_emit_bytecode$visit_type(t2, l1, l2);
            l4 = (l4 + INT64_C(1));
        }
    }
    if (l5.tag == 862u) {
        t1 = l5.payload.obj;
        l6 = ((vader_struct_vader_core_bytecode$BcUnion_t*) t1)->f_variants;
        l3 = ((vader_array_t*) l6)->length;
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) l6);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            t2 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l4];
            vader_emit_bytecode$visit_type(t2, l1, l2);
            l4 = (l4 + INT64_C(1));
        }
    }
    if (l5.tag == 848u) {
        t1 = l5.payload.obj;
        t2 = ((vader_struct_vader_core_bytecode$BcArray_t*) t1)->f_element;
        vader_emit_bytecode$visit_type(t2, l1, l2);
    }
    if (l5.tag == 851u) {
        t1 = l5.payload.obj;
        l6 = ((vader_struct_vader_core_bytecode$BcFn_t*) t1)->f_params;
        l3 = ((vader_array_t*) l6)->length;
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l6);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            t2 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l4];
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
    if (!(l2.tag == 773u)) {
        { void* __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a0_arr = vader_array_new(20u, 0u, 12u, 445u);
    l3 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(20u, 0u, 12u, 445u);
    l4 = (void*) _a1_arr;
    t0 = l2.payload.obj;
    l5 = ((vader_struct_toolchain_ast$FnDecl_t*) t0)->f_params;
    l6 = ((vader_array_t*) l5)->length;
    l7 = INT64_C(0);
    while ((l7 < l6)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        l8 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l7);
        l9 = toolchain_ast$decorators_have(((vader_struct_toolchain_ast$FnParam_t*) l8)->f_decorators, 1705u);
        vader_array_push_bool((vader_array_t*) l3, l9);
        l10 = toolchain_ast$decorators_have(((vader_struct_toolchain_ast$FnParam_t*) l8)->f_decorators, 1704u);
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
    vader_obj_header_init(_a3_obj, 859u);
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

static void* vader_emit_bytecode$with_peephole_out(void* l0, void* l1) {
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
    l3 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l2)->f_name;
    l4 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l2)->f_is_main;
    l5 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l2)->f_signature;
    l6 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l2)->f_locals;
    l7 = ((vader_struct_vader_emit_bytecode$BcPeepholeOut_t*) l1)->f_body;
    l8 = ((vader_struct_vader_emit_bytecode$BcPeepholeOut_t*) l1)->f_debug;
    l9 = ((vader_struct_vader_emit_bytecode$BcPeepholeOut_t*) l1)->f_jump_table;
    l2 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l2)->f_source_pc;
    vader_struct_vader_core_bytecode$BcFunction_t* _a0_obj = (vader_struct_vader_core_bytecode$BcFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcFunction_t));
    vader_obj_header_init(_a0_obj, 852u);
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
