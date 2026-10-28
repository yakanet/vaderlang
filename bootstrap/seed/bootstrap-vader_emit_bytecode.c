#include "bootstrap.split.h"

static uint8_t vader_emit_bytecode$array_element_val_type(vader_box_t l0);
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
static void vader_emit_bytecode$collect_baked_symbols(vader_box_t l0, void* l1);
static bool vader_emit_bytecode$compares_boxes(uint8_t l0, vader_box_t l1);
static bool vader_emit_bytecode$const_fills_slot(vader_box_t l0, uint8_t l1);
static uint8_t vader_emit_bytecode$const_val_type(vader_box_t l0);
static bool vader_emit_bytecode$convert_eligible(uint8_t l0);
static bool vader_emit_bytecode$copies_cheaply(void* l0);
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
static void vader_emit_bytecode$intern_data_value_strings(vader_box_t l0, void* l1);
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
static void vader_emit_bytecode$pin_baked_struct_types(void* l0, void* l1);
static void* vader_emit_bytecode$propagate_const_single_use(void* l0);
static void* vader_emit_bytecode$prune_unused_data(void* l0, void* l1);
static void vader_emit_bytecode$prune_unused_functions(void* l0, void* l1, void* l2);
static void vader_emit_bytecode$prune_unused_globals(void* l0);
static void vader_emit_bytecode$prune_unused_imports(void* l0);
static void vader_emit_bytecode$prune_unused_types(void* l0);
static void vader_emit_bytecode$push_emit(void* l0, vader_box_t l1, void* l2);
static int32_t vader_emit_bytecode$push_op_with_span(void* l0, vader_box_t l1, void* l2);
static void vader_emit_bytecode$push_or_assign(void* l0, int64_t l1, vader_box_t l2);
static void vader_emit_bytecode$push_scope(void* l0, void* l1, int64_t l2, vader_string_t l3, int32_t l4);
static vader_box_t vader_emit_bytecode$pushed_element_type(vader_box_t l0, vader_box_t l1);
static bool vader_emit_bytecode$ranges_overlap(void* l0, void* l1);
static void vader_emit_bytecode$record_slot_type(void* l0, int32_t l1, vader_box_t l2);
static void vader_emit_bytecode$refuse_shared_identity_test(vader_string_t l0, vader_box_t l1);
static void vader_emit_bytecode$refuse_shared_instance(vader_string_t l0, vader_box_t l1);
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
    if (!(l0.tag == 896u)) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 17; }
    }
    t0 = l0.payload.obj;
    t1 = vader_midir_select$val_type_of_type(((vader_struct_vader_core_types$ArrayType_t*) t0)->f_element);
    { uint8_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
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
    vader_obj_header_init(_a0_obj, 920u);
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
    if (l0.tag == 907u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_core_types$PrimitiveType_t*) t0)->f_name;
        t2 = vader_midir_select$val_type_of_primitive_name(t1);
        vader_struct_vader_core_bytecode$BcScalar_t* _a0_obj = (vader_struct_vader_core_bytecode$BcScalar_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcScalar_t));
        vader_obj_header_init(_a0_obj, 735u);
        _a0_obj->f_val = t2;
        t0 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if ((l0.tag == 898u || l0.tag == 908u)) {
        t2 = vader_midir_select$val_type_of_type(l0);
        vader_struct_vader_core_bytecode$BcScalar_t* _a1_obj = (vader_struct_vader_core_bytecode$BcScalar_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcScalar_t));
        vader_obj_header_init(_a1_obj, 735u);
        _a1_obj->f_val = t2;
        t0 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 897u) {
        t0 = l0.payload.obj;
        t3 = vader_emit_bytecode$bc_type_of_with_ctx(((vader_struct_vader_core_types$DistinctType_t*) t0)->f_backing, l1);
        { vader_box_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 910u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_core_types$StructType_t*) t0)->f_symbol)->f_name;
        vader_struct_vader_core_bytecode$BcRef_t* _a2_obj = (vader_struct_vader_core_bytecode$BcRef_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcRef_t));
        vader_obj_header_init(_a2_obj, 734u);
        _a2_obj->f_trait_name = t1;
        t0 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 912u) {
        t0 = l0.payload.obj;
        t1 = vader_core_types$trait_key_of(((vader_struct_vader_core_types$TraitType_t*) t0)->f_symbol);
        vader_struct_vader_core_bytecode$BcRef_t* _a3_obj = (vader_struct_vader_core_bytecode$BcRef_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcRef_t));
        vader_obj_header_init(_a3_obj, 734u);
        _a3_obj->f_trait_name = t1;
        t0 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 896u) {
        t0 = l0.payload.obj;
        t4 = vader_emit_bytecode$intern_type(((vader_struct_vader_core_types$ArrayType_t*) t0)->f_element, l1);
        vader_struct_vader_core_bytecode$BcArray_t* _a4_obj = (vader_struct_vader_core_bytecode$BcArray_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcArray_t));
        vader_obj_header_init(_a4_obj, 725u);
        _a4_obj->f_element = t4;
        t0 = (void*) _a4_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 918u) {
        vader_array_t* _a5_arr = vader_array_new(22u, 0u, 7u, 338u);
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
        vader_obj_header_init(_a7_obj, 739u);
        _a7_obj->f_variants = l2;
        t0 = (void*) _a7_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 899u) {
        vader_array_t* _a8_arr = vader_array_new(22u, 0u, 7u, 338u);
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
        vader_obj_header_init(_a10_obj, 728u);
        _a10_obj->f_params = l2;
        _a10_obj->f_return_type = l6;
        t0 = (void*) _a10_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 913u) {
        vader_array_t* _a11_arr = vader_array_new(59u, 0u, 13u, 727u);
        l2 = (void*) _a11_arr;
        l4 = INT64_C(0);
        t0 = l0.payload.obj;
        l5 = ((vader_array_t*) ((vader_struct_vader_core_types$TupleType_t*) t0)->f_elements)->length;
        while ((l4 < l5)) {
            l3 = (void*) vader_buffer_new((size_t) INT64_C(21));
            l7 = INT64_C(0);
            l7 = std_core$write_string_at(l3, l7, 977u);
            l7 = std_core$write_int(l3, l7, l4);
            l8 = std_core$finish_buffer(l3, l7);
            t0 = l0.payload.obj;
            vader_array_t* _a12_slotarr = ((vader_array_t*) ((vader_struct_vader_core_types$TupleType_t*) t0)->f_elements);
            VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a12_slotarr, l4)
            t3 = vader_array_ref_load_box(_a12_slotarr->buf, _a12_slotarr->offset + (size_t) l4);
            l6 = vader_emit_bytecode$intern_type(t3, l1);
            vader_struct_vader_core_bytecode$BcField_t* _a13_obj = (vader_struct_vader_core_bytecode$BcField_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcField_t));
            vader_obj_header_init(_a13_obj, 727u);
            _a13_obj->f_name = l8;
            _a13_obj->f_type_index = l6;
            l9 = (void*) _a13_obj;
            vader_array_push_ref((vader_array_t*) l2, l9);
            l4 = (l4 + INT64_C(1));
        }
        t0 = l0.payload.obj;
        l8 = vader_midir_select$tuple_shape_name(((vader_struct_vader_core_types$TupleType_t*) t0)->f_elements);
        t1 = concat_2(993u, l8);
        vader_struct_vader_core_bytecode$BcStruct_t* _a14_obj = (vader_struct_vader_core_bytecode$BcStruct_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcStruct_t));
        vader_obj_header_init(_a14_obj, 738u);
        _a14_obj->f_name = t1;
        _a14_obj->f_fields = l2;
        _a14_obj->f_c_name = 0u;
        _a14_obj->f_symbol_id = INT32_C(-1);
        t0 = (void*) _a14_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 915u) {
        t0 = (void*) &vader_data_40;
        vader_array_t* _a15_slotarr = ((vader_array_t*) t0);
        VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
        t0 = vader_array_ref_load_obj(_a15_slotarr->buf, _a15_slotarr->offset + (size_t) INT64_C(0));
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 903u) {
        t0 = l0.payload.obj;
        vader_core_types$leaked_infer_var(t0);
        vader_unreachable("a no-return call returned");
    } else {
        if (l0.tag == 914u) {
            t0 = (void*) &vader_data_40;
            vader_array_t* _a16_slotarr = ((vader_array_t*) t0);
            VADER_ARRAY_RESOLVE_BUF(_a16_slotarr)
            t0 = vader_array_ref_load_obj(_a16_slotarr->buf, _a16_slotarr->offset + (size_t) INT64_C(0));
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l0.tag == 909u) {
            t0 = (void*) &vader_data_40;
            vader_array_t* _a17_slotarr = ((vader_array_t*) t0);
            VADER_ARRAY_RESOLVE_BUF(_a17_slotarr)
            t0 = vader_array_ref_load_obj(_a17_slotarr->buf, _a17_slotarr->offset + (size_t) INT64_C(0));
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l0.tag == 919u) {
            t0 = (void*) &vader_data_40;
            vader_array_t* _a18_slotarr = ((vader_array_t*) t0);
            VADER_ARRAY_RESOLVE_BUF(_a18_slotarr)
            t0 = vader_array_ref_load_obj(_a18_slotarr->buf, _a18_slotarr->offset + (size_t) INT64_C(0));
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l0.tag == 902u) {
            t0 = (void*) &vader_data_40;
            vader_array_t* _a19_slotarr = ((vader_array_t*) t0);
            VADER_ARRAY_RESOLVE_BUF(_a19_slotarr)
            t0 = vader_array_ref_load_obj(_a19_slotarr->buf, _a19_slotarr->offset + (size_t) INT64_C(0));
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l0.tag == 900u) {
            t0 = (void*) &vader_data_40;
            vader_array_t* _a20_slotarr = ((vader_array_t*) t0);
            VADER_ARRAY_RESOLVE_BUF(_a20_slotarr)
            t0 = vader_array_ref_load_obj(_a20_slotarr->buf, _a20_slotarr->offset + (size_t) INT64_C(0));
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l0.tag == 901u) {
            t0 = (void*) &vader_data_40;
            vader_array_t* _a21_slotarr = ((vader_array_t*) t0);
            VADER_ARRAY_RESOLVE_BUF(_a21_slotarr)
            t0 = vader_array_ref_load_obj(_a21_slotarr->buf, _a21_slotarr->offset + (size_t) INT64_C(0));
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l0.tag == 905u) {
            t0 = (void*) &vader_data_40;
            vader_array_t* _a22_slotarr = ((vader_array_t*) t0);
            VADER_ARRAY_RESOLVE_BUF(_a22_slotarr)
            t0 = vader_array_ref_load_obj(_a22_slotarr->buf, _a22_slotarr->offset + (size_t) INT64_C(0));
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (!(l0.tag == 895u)) {
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
    if (l3.tag == 738u) {
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
    if (!(l2.tag == 738u)) {
        vader_array_t* _a1_arr = vader_array_new(19u, 0u, 12u, 333u);
        t0 = (void*) _a1_arr;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l2.payload.obj;
    l3 = ((vader_struct_vader_core_bytecode$BcStruct_t*) t0)->f_fields;
    vader_struct___lambda_env_vader_emit_bytecode_9_t* _a2_obj = (vader_struct___lambda_env_vader_emit_bytecode_9_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_emit_bytecode_9_t));
    vader_obj_header_init(_a2_obj, 365u);
    _a2_obj->f_cap_0 = l0;
    l4 = (void*) _a2_obj;
    vader_array_t* _a3_arr = vader_array_new(19u, 0u, 12u, 333u);
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
            l9 = __lambda_vader_emit_bytecode_8(l4, l8);
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
    vader_struct___lambda_env_vader_emit_bytecode_7_t* _a0_obj = (vader_struct___lambda_env_vader_emit_bytecode_7_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_emit_bytecode_7_t));
    vader_obj_header_init(_a0_obj, 364u);
    _a0_obj->f_cap_0 = l0;
    l3 = (void*) _a0_obj;
    vader_array_t* _a1_arr = vader_array_new(19u, 0u, 12u, 333u);
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
            l8 = __lambda_vader_emit_bytecode_6(l3, l7);
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
    vader_array_t* _a0_arr = vader_array_new(24u, 0u, 1u, 340u);
    l4 = (void*) _a0_arr;
    l5 = ((vader_array_t*) l0)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l4, (int64_t) l5);
    l4 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(22u, 0u, 7u, 338u);
    l6 = (void*) _a2_arr;
    l5 = ((vader_array_t*) l0)->length;
    vader_array_t* _a3_arr = vader_array_repeat((vader_array_t*) l6, (int64_t) l5);
    l6 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_new(21u, 0u, 0u, 335u);
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
        vader_array_push_scalar((vader_array_t*) l7, vader_box_string(335u, l13));
        l9 = (l9 + INT64_C(1));
    }
    vader_array_t* _a7_arr = vader_array_new(24u, 0u, 1u, 340u);
    l8 = (void*) _a7_arr;
    vader_array_t* _a8_arr = vader_array_new(22u, 0u, 7u, 338u);
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
    vader_array_t* _a10_arr = vader_array_new(19u, 0u, 12u, 333u);
    l14 = (void*) _a10_arr;
    vader_array_t* _a11_arr = vader_array_new(19u, 0u, 12u, 333u);
    l16 = (void*) _a11_arr;
    vader_struct_vader_core_bytecode$BcSignature_t* _a12_obj = (vader_struct_vader_core_bytecode$BcSignature_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcSignature_t));
    vader_obj_header_init(_a12_obj, 736u);
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
    vader_array_t* _a0_arr = vader_array_new(65u, 0u, 13u, 833u);
    l3 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(21u, 0u, 0u, 335u);
    l4 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(19u, 0u, 12u, 333u);
    l5 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(22u, 0u, 7u, 338u);
    l6 = (void*) _a3_arr;
    vader_struct_std_collections$MutableMap__string__bool_t* _a4_obj = (vader_struct_std_collections$MutableMap__string__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__string__bool_t));
    vader_obj_header_init(_a4_obj, 539u);
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
        if (l10.tag == 338u) {
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
                if (!((t0.tag == 725u || t0.tag == 738u))) {
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
            l19 = std_core$write_string_at(l18, l19, 3068u);
            l19 = std_core$write_string_at(l18, l19, l16);
            l15 = std_core$finish_buffer(l18, l19);
            t0 = std_collections$MutableMap$std_core$Index$at__string__bool(l4, l15);
            if (t0.tag == 333u) {
                l8 = (l8 + INT64_C(1));
                continue;
            }
            std_collections$MutableMap$std_core$IndexSet$set_at__string__bool(l4, l15, true);
            l21 = ((vader_struct_vader_lower_ir$LoweredVtableEntry_t*) l6)->f_trait_name;
            vader_struct_vader_core_bytecode$ImplEntry_t* _a7_obj = (vader_struct_vader_core_bytecode$ImplEntry_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$ImplEntry_t));
            vader_obj_header_init(_a7_obj, 833u);
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
        if (l10.tag == 738u) {
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
                l19 = std_core$write_string_at(l6, l19, 3068u);
                l19 = std_core$write_string_at(l6, l19, l16);
                l15 = std_core$finish_buffer(l6, l19);
                t0 = std_collections$MutableMap$std_core$Index$at__string__bool(l4, l15);
                if (t0.tag == 333u) {
                    l14 = (l14 + INT64_C(1));
                    continue;
                }
                std_collections$MutableMap$std_core$IndexSet$set_at__string__bool(l4, l15, true);
                vader_struct_vader_core_bytecode$ImplEntry_t* _a10_obj = (vader_struct_vader_core_bytecode$ImplEntry_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$ImplEntry_t));
                vader_obj_header_init(_a10_obj, 833u);
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
    vader_box_t* gc_roots[1] = { &l6 };
    void** gc_raw_roots[3] = { &l0, &l2, &l5 };
    vader_string_t* gc_atom_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(247u, 0u, 13u, 1677u);
    l2 = (void*) _a0_arr;
    l3 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcImport_t*) l0)->f_signature)->f_params)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l2, (int64_t) l3);
    l2 = (void*) _a1_arr;
    l3 = INT64_C(0);
    l4 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcImport_t*) l0)->f_signature)->f_params)->length;
    while ((l3 < l4)) {
        vader_struct_vader_core_bytecode$LocalGet_t* _a2_obj = (vader_struct_vader_core_bytecode$LocalGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$LocalGet_t));
        vader_obj_header_init(_a2_obj, 842u);
        _a2_obj->f_slot = ((int32_t) (int64_t) l3);
        l5 = (void*) _a2_obj;
        vader_array_push_ref((vader_array_t*) l2, l5);
        l3 = (l3 + INT64_C(1));
    }
    t0 = ((vader_struct_vader_core_bytecode$BcImport_t*) l0)->f_mangled_name;
    l6 = vader_midir_select$intrinsic_op_for_mangled(t0);
    if (l6.tag == 0u) {
        vader_struct_vader_core_bytecode$CallImport_t* _a3_obj = (vader_struct_vader_core_bytecode$CallImport_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$CallImport_t));
        vader_obj_header_init(_a3_obj, 761u);
        _a3_obj->f_index = l1;
        l5 = (void*) _a3_obj;
        vader_array_push_ref((vader_array_t*) l2, l5);
        vader_struct_vader_core_bytecode$Return_t* _a4_obj = (vader_struct_vader_core_bytecode$Return_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$Return_t));
        vader_obj_header_init(_a4_obj, 853u);
        l5 = (void*) _a4_obj;
        vader_array_push_ref((vader_array_t*) l2, l5);
        { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_push_ref((vader_array_t*) l2, l6.payload.obj);
    vader_struct_vader_core_bytecode$Return_t* _a5_obj = (vader_struct_vader_core_bytecode$Return_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$Return_t));
    vader_obj_header_init(_a5_obj, 853u);
    l5 = (void*) _a5_obj;
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
    vader_array_t* _a0_arr = vader_array_new(21u, 0u, 0u, 335u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(19u, 0u, 12u, 333u);
    l3 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(22u, 0u, 7u, 338u);
    l4 = (void*) _a2_arr;
    vader_struct_std_collections$MutableMap__string__bool_t* _a3_obj = (vader_struct_std_collections$MutableMap__string__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__string__bool_t));
    vader_obj_header_init(_a3_obj, 539u);
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
            if (l9.tag == 887u) {
                t0 = l9.payload.obj;
                l10 = ((vader_struct_vader_core_bytecode$VirtualCall_t*) t0)->f_vtable_key;
                std_collections$MutableMap$std_core$IndexSet$set_at__string__bool(l2, l10, true);
            }
            l8 = (l8 + INT64_C(1));
        }
        l6 = (l6 + INT64_C(1));
    }
    vader_array_t* _a6_arr = vader_array_new(21u, 0u, 0u, 335u);
    l3 = (void*) _a6_arr;
    vader_array_t* _a7_arr = vader_array_new(23u, 0u, 8u, 339u);
    l4 = (void*) _a7_arr;
    vader_array_t* _a8_arr = vader_array_new(22u, 0u, 7u, 338u);
    l11 = (void*) _a8_arr;
    vader_struct_std_collections$MutableMap__string__i64_t* _a9_obj = (vader_struct_std_collections$MutableMap__string__i64_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__string__i64_t));
    vader_obj_header_init(_a9_obj, 542u);
    _a9_obj->f_ekeys = l3;
    _a9_obj->f_evals = l4;
    _a9_obj->f_index = l11;
    _a9_obj->f_mask = INT64_C(0);
    _a9_obj->f_grow_at = INT64_C(0);
    _a9_obj->f_size = INT64_C(0);
    _a9_obj->f_tombs = INT64_C(0);
    l3 = (void*) _a9_obj;
    vader_array_t* _a10_arr = vader_array_new(68u, 0u, 13u, 889u);
    l4 = (void*) _a10_arr;
    vader_array_t* _a11_arr = vader_array_new(199u, 0u, 13u, 1294u);
    l11 = (void*) _a11_arr;
    vader_array_t* _a12_arr = vader_array_new(199u, 0u, 13u, 1294u);
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
        if (t2.tag == 333u) {
            l9 = vader_emit_bytecode$resolve_fn_index(((vader_struct_vader_lower_ir$LoweredVtableEntry_t*) l12)->f_fn_symbol, l1);
            if (l9.tag == 0u) {
                l6 = (l6 + INT64_C(1));
                continue;
            }
            l17 = ((int32_t) l9.payload.i);
            l18 = vader_midir_select$type_intern_key(((vader_struct_vader_lower_ir$LoweredVtableEntry_t*) l12)->f_struct_type);
            l19 = std_collections$MutableMap$std_core$Index$at__string__i32(((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l1)->f_type_key, l18);
            if (l19.tag == 338u) {
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
                    vader_obj_header_init(_a17_obj, 888u);
                    _a17_obj->f_receiver_type_index = l20;
                    _a17_obj->f_fn_index = l17;
                    l14 = (void*) _a17_obj;
                    vader_array_push_ref((vader_array_t*) l13, l14);
                } else {
                    vader_array_t* _a18_arr = vader_array_new(67u, 0u, 13u, 888u);
                    l21 = (void*) _a18_arr;
                    vader_struct_vader_core_bytecode$VtableEntry_t* _a19_obj = (vader_struct_vader_core_bytecode$VtableEntry_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$VtableEntry_t));
                    vader_obj_header_init(_a19_obj, 888u);
                    _a19_obj->f_receiver_type_index = l20;
                    _a19_obj->f_fn_index = l17;
                    l22 = (void*) _a19_obj;
                    vader_array_push_ref((vader_array_t*) l21, l22);
                    vader_struct_vader_core_bytecode$VtableRow_t* _a20_obj = (vader_struct_vader_core_bytecode$VtableRow_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$VtableRow_t));
                    vader_obj_header_init(_a20_obj, 889u);
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
    if (!(l1.tag == 693u)) {
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
    void** gc_raw_roots[4] = { &l0, &l1, &l3, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_core_bytecode$Block_t* _a0_obj = (vader_struct_vader_core_bytecode$Block_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$Block_t));
    vader_obj_header_init(_a0_obj, 746u);
    l3 = (void*) _a0_obj;
    l4 = vader_emit_bytecode$push_op_with_span(l0, vader_ref_box(l3), l1);
    l3 = ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_scopes;
    vader_struct_vader_emit_bytecode$ScopeFrame_t* _a1_obj = (vader_struct_vader_emit_bytecode$ScopeFrame_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_bytecode$ScopeFrame_t));
    vader_obj_header_init(_a1_obj, 927u);
    _a1_obj->f_kind = 1633u;
    _a1_obj->f_target_blk = l2;
    _a1_obj->f_opener_pc = l4;
    l5 = (void*) _a1_obj;
    vader_array_push_ref((vader_array_t*) l3, l5);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_bytecode$cf_br(void* l0, void* l1, int32_t l2) {
    void* l3 = NULL;
    int32_t l4;
    void** gc_raw_roots[3] = { &l0, &l1, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_core_bytecode$Branch_t* _a0_obj = (vader_struct_vader_core_bytecode$Branch_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$Branch_t));
    vader_obj_header_init(_a0_obj, 753u);
    l3 = (void*) _a0_obj;
    l4 = vader_emit_bytecode$push_op_with_span(l0, vader_ref_box(l3), l1);
    vader_emit_bytecode$defer_or_resolve_branch(l0, l2, l4);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_bytecode$cf_br_if(void* l0, void* l1, int32_t l2) {
    void* l3 = NULL;
    int32_t l4;
    void** gc_raw_roots[3] = { &l0, &l1, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_core_bytecode$BranchIf_t* _a0_obj = (vader_struct_vader_core_bytecode$BranchIf_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BranchIf_t));
    vader_obj_header_init(_a0_obj, 754u);
    l3 = (void*) _a0_obj;
    l4 = vader_emit_bytecode$push_op_with_span(l0, vader_ref_box(l3), l1);
    vader_emit_bytecode$defer_or_resolve_branch(l0, l2, l4);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_bytecode$cf_else(void* l0, void* l1) {
    void* l2 = NULL;
    void* l6 = NULL;
    int32_t l3, l7, l8;
    int64_t l4, l5;
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &l6 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_core_bytecode$Else_t* _a0_obj = (vader_struct_vader_core_bytecode$Else_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$Else_t));
    vader_obj_header_init(_a0_obj, 772u);
    l2 = (void*) _a0_obj;
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
        vader_obj_header_init(_a3_obj, 927u);
        _a3_obj->f_kind = 2134u;
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
    vader_string_t t0 = 0;
    int32_t t1;
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l6, &l7 };
    vader_string_t* gc_atom_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_struct_vader_core_bytecode$End_t* _a0_obj = (vader_struct_vader_core_bytecode$End_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$End_t));
    vader_obj_header_init(_a0_obj, 773u);
    l2 = (void*) _a0_obj;
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
    vader_array_t* _a2_arr = vader_array_new(89u, 0u, 13u, 927u);
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
    t0 = ((vader_struct_vader_emit_bytecode$ScopeFrame_t*) l2)->f_kind;
    if (t0 != 2295u) {
        l6 = ((vader_struct_vader_core_bytecode$BcFunction_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_slot)->f_jump_table;
        l8 = ((vader_struct_vader_emit_bytecode$ScopeFrame_t*) l2)->f_opener_pc;
        vader_array_t* _a4_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l8)
        t1 = ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l8];
        if ((t1 < INT32_C(0))) {
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
    t0 = ((vader_struct_vader_emit_bytecode$ScopeFrame_t*) l2)->f_kind;
    l10 = t0 == 2295u;
    l9 = ((vader_struct_vader_emit_bytecode$ScopeFrame_t*) l2)->f_opener_pc;
    vader_emit_bytecode$drain_pending(l0, l8, l10, l9, l3);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_bytecode$cf_if(void* l0, void* l1) {
    void* l2 = NULL;
    void* l4 = NULL;
    int32_t l3;
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_core_bytecode$If_t* _a0_obj = (vader_struct_vader_core_bytecode$If_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$If_t));
    vader_obj_header_init(_a0_obj, 832u);
    l2 = (void*) _a0_obj;
    l3 = vader_emit_bytecode$push_op_with_span(l0, vader_ref_box(l2), l1);
    l2 = ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_scopes;
    vader_struct_vader_emit_bytecode$ScopeFrame_t* _a1_obj = (vader_struct_vader_emit_bytecode$ScopeFrame_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_bytecode$ScopeFrame_t));
    vader_obj_header_init(_a1_obj, 927u);
    _a1_obj->f_kind = 2134u;
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
    void** gc_raw_roots[4] = { &l0, &l1, &l3, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_core_bytecode$Loop_t* _a0_obj = (vader_struct_vader_core_bytecode$Loop_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$Loop_t));
    vader_obj_header_init(_a0_obj, 845u);
    l3 = (void*) _a0_obj;
    l4 = vader_emit_bytecode$push_op_with_span(l0, vader_ref_box(l3), l1);
    l3 = ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_scopes;
    vader_struct_vader_emit_bytecode$ScopeFrame_t* _a1_obj = (vader_struct_vader_emit_bytecode$ScopeFrame_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_bytecode$ScopeFrame_t));
    vader_obj_header_init(_a1_obj, 927u);
    _a1_obj->f_kind = 2295u;
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
    if (l0.tag == 899u) {
        t0 = l0.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a0_arr = vader_array_new(252u, 0u, 13u, 1776u);
    l1 = (void*) _a0_arr;
    t0 = (void*) &vader_data_18;
    vader_array_t* _a1_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    l2 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) INT64_C(0));
    vader_array_t* _a2_arr = vader_array_new(85u, 0u, 13u, 915u);
    l3 = (void*) _a2_arr;
    t0 = vader_core_types$mk_fn(l1, vader_ref_box(l2), l3);
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_emit_bytecode$coalesce_slots(void* l0) {
    int64_t l1, l2, l4, l6, l10, l21, l22, l23, l25;
    void* l3 = NULL;
    void* l5 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l15 = NULL;
    void* l17 = NULL;
    void* l18 = NULL;
    void* l19 = NULL;
    void* l24 = NULL;
    void* l26 = NULL;
    void* l27 = NULL;
    void* l30 = NULL;
    int32_t l9, l11, l12, l13, l14, l28, l29;
    bool l16;
    uint8_t l20;
    vader_box_t l31 = vader_box_null(), l32 = vader_box_null(), l33 = vader_box_null();
    vader_string_t l34 = 0;
    vader_box_t t0 = vader_box_null();
    bool t1, t2;
    void* t3 = NULL;
    int64_t t4;
    vader_box_t* gc_roots[4] = { &l31, &l32, &l33, &t0 };
    void** gc_raw_roots[14] = {
        &l0, &l3, &l5, &l7, &l8, &l15, &l17, &l18, &l19, &l24, &l26, &l27, &l30, &t3,
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
    vader_array_t* _a0_arr = vader_array_new(90u, 0u, 13u, 928u);
    l5 = (void*) _a0_arr;
    if ((INT64_C(0) < l2)) {
        l6 = l2;
    } else {
        l6 = INT64_C(0);
    }
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l5, (int64_t) l6);
    l5 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(19u, 0u, 12u, 333u);
    l7 = (void*) _a2_arr;
    if ((INT64_C(0) < l2)) {
        l6 = l2;
    } else {
        l6 = INT64_C(0);
    }
    vader_array_t* _a3_arr = vader_array_repeat((vader_array_t*) l7, (int64_t) l6);
    l7 = (void*) _a3_arr;
    l6 = INT64_C(0);
    while ((l6 < l2)) {
        vader_struct_vader_emit_bytecode$SlotRange_t* _a4_obj = (vader_struct_vader_emit_bytecode$SlotRange_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_bytecode$SlotRange_t));
        vader_obj_header_init(_a4_obj, 928u);
        _a4_obj->f_first = INT32_C(-1);
        _a4_obj->f_last = INT32_C(-1);
        l8 = (void*) _a4_obj;
        vader_array_push_ref((vader_array_t*) l5, l8);
        vader_array_push_bool((vader_array_t*) l7, false);
        l6 = (l6 + INT64_C(1));
    }
    l6 = INT64_C(0);
    while ((l6 < l4)) {
        vader_array_t* _a5_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        t0 = vader_array_ref_load_box(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l6);
        l9 = vader_core_bytecode$slot_touched(t0);
        if ((l9 >= INT32_C(0))) {
            l10 = ((int64_t) (int32_t) l9);
            vader_array_t* _a6_slotarr = ((vader_array_t*) l7);
            VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l10)
            t1 = ((uint8_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l10];
            t2 = t1;
            if (t2) {
                vader_array_t* _a7_slotarr = ((vader_array_t*) l5);
                VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l10)
                t3 = vader_array_ref_load_obj(_a7_slotarr->buf, _a7_slotarr->offset + (size_t) l10);
                l13 = ((vader_struct_vader_emit_bytecode$SlotRange_t*) t3)->f_first;
                l14 = ((int32_t) (int64_t) l6);
                vader_struct_vader_emit_bytecode$SlotRange_t* _a8_obj = (vader_struct_vader_emit_bytecode$SlotRange_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_bytecode$SlotRange_t));
                vader_obj_header_init(_a8_obj, 928u);
                _a8_obj->f_first = l13;
                _a8_obj->f_last = l14;
                l15 = (void*) _a8_obj;
                vader_array_t* _a9_slotarr = ((vader_array_t*) l5);
                VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l10)
                vader_array_ref_store(_a9_slotarr->buf, _a9_slotarr->offset + (size_t) l10, l15);
                VADER_WRITE_BARRIER(_a9_slotarr->buf);
            } else {
                l11 = ((int32_t) (int64_t) l6);
                l12 = ((int32_t) (int64_t) l6);
                vader_struct_vader_emit_bytecode$SlotRange_t* _a10_obj = (vader_struct_vader_emit_bytecode$SlotRange_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_bytecode$SlotRange_t));
                vader_obj_header_init(_a10_obj, 928u);
                _a10_obj->f_first = l11;
                _a10_obj->f_last = l12;
                l8 = (void*) _a10_obj;
                vader_array_t* _a11_slotarr = ((vader_array_t*) l5);
                VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l10)
                vader_array_ref_store(_a11_slotarr->buf, _a11_slotarr->offset + (size_t) l10, l8);
                VADER_WRITE_BARRIER(_a11_slotarr->buf);
                vader_array_t* _a12_slotarr = ((vader_array_t*) l7);
                VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a12_slotarr, l10)
                ((uint8_t*) _a12_slotarr->buf->slots)[_a12_slotarr->offset + (size_t) l10] = (uint8_t) true;
            }
        }
        l6 = (l6 + INT64_C(1));
    }
    l8 = vader_emit_bytecode$find_loop_ranges(l3);
    t4 = ((vader_array_t*) l8)->length;
    if ((t4 > INT64_C(0))) {
        l16 = true;
        while (l16) {
            l16 = vader_emit_bytecode$extend_into_loops(l5, l7, l2, l8);
        }
    }
    l6 = INT64_C(0);
    while ((l6 < l1)) {
        l9 = ((int32_t) (int64_t) l4);
        vader_struct_vader_emit_bytecode$SlotRange_t* _a13_obj = (vader_struct_vader_emit_bytecode$SlotRange_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_bytecode$SlotRange_t));
        vader_obj_header_init(_a13_obj, 928u);
        _a13_obj->f_first = INT32_C(0);
        _a13_obj->f_last = l9;
        l8 = (void*) _a13_obj;
        vader_array_t* _a14_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a14_slotarr, l6)
        vader_array_ref_store(_a14_slotarr->buf, _a14_slotarr->offset + (size_t) l6, l8);
        VADER_WRITE_BARRIER(_a14_slotarr->buf);
        vader_array_t* _a15_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a15_slotarr, l6)
        ((uint8_t*) _a15_slotarr->buf->slots)[_a15_slotarr->offset + (size_t) l6] = (uint8_t) true;
        l6 = (l6 + INT64_C(1));
    }
    vader_array_t* _a16_arr = vader_array_new(63u, 0u, 13u, 732u);
    l8 = (void*) _a16_arr;
    vader_array_t* _a17_arr = vader_array_new(22u, 0u, 7u, 338u);
    l15 = (void*) _a17_arr;
    if ((INT64_C(0) < l2)) {
        l6 = l2;
    } else {
        l6 = INT64_C(0);
    }
    vader_array_t* _a18_arr = vader_array_repeat((vader_array_t*) l15, (int64_t) l6);
    l15 = (void*) _a18_arr;
    l6 = INT64_C(0);
    vader_array_t* _pc216_hdr = (vader_array_t*) l15;
    size_t _pc216_len = _pc216_hdr->length;
    size_t _pc216_cap = (_pc216_hdr->offset == 0 && !vader_array_is_borrowed(_pc216_hdr) && _pc216_hdr->length >= _pc216_hdr->buf->length) ? _pc216_hdr->capacity : (size_t) 0;
    void* _pc216_slots = _pc216_hdr->buf->slots;
    for (;;) {
        if ((l6 < l2)) {
            if (VADER_LIKELY(_pc216_len < _pc216_cap)) {
                ((int32_t*) _pc216_slots)[_pc216_len] = (int32_t) (INT32_C(-1));
                _pc216_len += 1;
            } else {
                _pc216_hdr->length = _pc216_len;
                if (_pc216_hdr->buf->length < _pc216_len) {
                    _pc216_hdr->buf->length = _pc216_len;
                }
                vader_array_push_i32((vader_array_t*) l15, INT32_C(-1));
                _pc216_hdr = (vader_array_t*) l15;
                _pc216_len = _pc216_hdr->length;
                _pc216_cap = (_pc216_hdr->offset == 0 && !vader_array_is_borrowed(_pc216_hdr) && _pc216_hdr->length >= _pc216_hdr->buf->length) ? _pc216_hdr->capacity : (size_t) 0;
                _pc216_slots = _pc216_hdr->buf->slots;
            }
            l6 = (l6 + INT64_C(1));
            continue;
        }
        _pc216_hdr->length = _pc216_len;
        if (_pc216_hdr->buf->length < _pc216_len) {
            _pc216_hdr->buf->length = _pc216_len;
        }
        break;
    }
    l6 = INT64_C(0);
    while ((l6 < l1)) {
        l9 = ((int32_t) (int64_t) l6);
        vader_array_t* _a19_slotarr = ((vader_array_t*) l15);
        VADER_ARRAY_RESOLVE_BUF(_a19_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a19_slotarr, l6)
        ((int32_t*) _a19_slotarr->buf->slots)[_a19_slotarr->offset + (size_t) l6] = (int32_t) l9;
        l6 = (l6 + INT64_C(1));
    }
    vader_array_t* _a20_arr = vader_array_new(90u, 0u, 13u, 928u);
    l17 = (void*) _a20_arr;
    if ((INT64_C(0) < l1)) {
        l6 = l1;
    } else {
        l6 = INT64_C(0);
    }
    vader_array_t* _a21_arr = vader_array_repeat((vader_array_t*) l17, (int64_t) l6);
    l17 = (void*) _a21_arr;
    l6 = INT64_C(0);
    while ((l6 < l1)) {
        vader_array_t* _a22_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a22_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a22_slotarr, l6)
        l18 = vader_array_ref_load_obj(_a22_slotarr->buf, _a22_slotarr->offset + (size_t) l6);
        vader_array_push_ref((vader_array_t*) l17, l18);
        l6 = (l6 + INT64_C(1));
    }
    l6 = l1;
    while ((l6 < l2)) {
        vader_array_t* _a23_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a23_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a23_slotarr, l6)
        t1 = ((uint8_t*) _a23_slotarr->buf->slots)[_a23_slotarr->offset + (size_t) l6];
        t2 = t1;
        if (t2) {
            vader_array_t* _a24_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a24_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a24_slotarr, l6)
            l18 = vader_array_ref_load_obj(_a24_slotarr->buf, _a24_slotarr->offset + (size_t) l6);
            l19 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_locals;
            l10 = vader_chk_sub(i64, l6, l1);
            vader_array_t* _a25_slotarr = ((vader_array_t*) l19);
            VADER_ARRAY_RESOLVE_BUF(_a25_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a25_slotarr, l10)
            t3 = vader_array_ref_load_obj(_a25_slotarr->buf, _a25_slotarr->offset + (size_t) l10);
            l20 = ((vader_struct_vader_core_bytecode$BcLocal_t*) t3)->f_val;
            l9 = INT32_C(-1);
            l21 = l1;
            l22 = ((vader_array_t*) l17)->length;
            while ((l21 < l22)) {
                l23 = vader_chk_sub(i64, l21, l1);
                vader_array_t* _a26_slotarr = ((vader_array_t*) l8);
                VADER_ARRAY_RESOLVE_BUF(_a26_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a26_slotarr, l23)
                t3 = vader_array_ref_load_obj(_a26_slotarr->buf, _a26_slotarr->offset + (size_t) l23);
                if (((vader_struct_vader_core_bytecode$BcLocal_t*) t3)->f_val == l20) {
                    vader_array_t* _a27_slotarr = ((vader_array_t*) l17);
                    VADER_ARRAY_RESOLVE_BUF(_a27_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a27_slotarr, l21)
                    t3 = vader_array_ref_load_obj(_a27_slotarr->buf, _a27_slotarr->offset + (size_t) l21);
                    t1 = vader_emit_bytecode$ranges_overlap(t3, l18);
                    if (!(t1)) {
                        l9 = ((int32_t) (int64_t) l21);
                        break;
                    }
                }
                l21 = (l21 + INT64_C(1));
            }
            if ((l9 < INT32_C(0))) {
                t4 = ((vader_array_t*) l17)->length;
                l9 = ((int32_t) (int64_t) t4);
                vader_array_push_ref((vader_array_t*) l17, l18);
                l24 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_locals;
                l25 = vader_chk_sub(i64, l6, l1);
                vader_array_t* _a28_slotarr = ((vader_array_t*) l24);
                VADER_ARRAY_RESOLVE_BUF(_a28_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a28_slotarr, l25)
                l26 = vader_array_ref_load_obj(_a28_slotarr->buf, _a28_slotarr->offset + (size_t) l25);
                vader_array_push_ref((vader_array_t*) l8, l26);
            } else {
                vader_array_t* _a29_slotarr = ((vader_array_t*) l17);
                VADER_ARRAY_RESOLVE_BUF(_a29_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a29_slotarr, l9)
                l27 = vader_array_ref_load_obj(_a29_slotarr->buf, _a29_slotarr->offset + (size_t) l9);
                l12 = ((vader_struct_vader_emit_bytecode$SlotRange_t*) l18)->f_first;
                l13 = ((vader_struct_vader_emit_bytecode$SlotRange_t*) l27)->f_first;
                if ((l12 < l13)) {
                    l11 = ((vader_struct_vader_emit_bytecode$SlotRange_t*) l18)->f_first;
                } else {
                    l11 = ((vader_struct_vader_emit_bytecode$SlotRange_t*) l27)->f_first;
                }
                l28 = ((vader_struct_vader_emit_bytecode$SlotRange_t*) l18)->f_last;
                l29 = ((vader_struct_vader_emit_bytecode$SlotRange_t*) l27)->f_last;
                if ((l28 > l29)) {
                    l14 = ((vader_struct_vader_emit_bytecode$SlotRange_t*) l18)->f_last;
                } else {
                    l14 = ((vader_struct_vader_emit_bytecode$SlotRange_t*) l27)->f_last;
                }
                vader_struct_vader_emit_bytecode$SlotRange_t* _a30_obj = (vader_struct_vader_emit_bytecode$SlotRange_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_bytecode$SlotRange_t));
                vader_obj_header_init(_a30_obj, 928u);
                _a30_obj->f_first = l11;
                _a30_obj->f_last = l14;
                l30 = (void*) _a30_obj;
                vader_array_t* _a31_slotarr = ((vader_array_t*) l17);
                VADER_ARRAY_RESOLVE_BUF(_a31_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a31_slotarr, l9)
                vader_array_ref_store(_a31_slotarr->buf, _a31_slotarr->offset + (size_t) l9, l30);
                VADER_WRITE_BARRIER(_a31_slotarr->buf);
            }
            vader_array_t* _a32_slotarr = ((vader_array_t*) l15);
            VADER_ARRAY_RESOLVE_BUF(_a32_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a32_slotarr, l6)
            ((int32_t*) _a32_slotarr->buf->slots)[_a32_slotarr->offset + (size_t) l6] = (int32_t) l9;
            l6 = vader_chk_add(i64, l6, INT64_C(1));
            continue;
        }
        vader_array_t* _a33_slotarr = ((vader_array_t*) l15);
        VADER_ARRAY_RESOLVE_BUF(_a33_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a33_slotarr, l6)
        ((int32_t*) _a33_slotarr->buf->slots)[_a33_slotarr->offset + (size_t) l6] = (int32_t) INT32_C(-1);
        l6 = vader_chk_add(i64, l6, INT64_C(1));
    }
    l16 = true;
    while ((l1 < l2)) {
        vader_array_t* _a34_slotarr = ((vader_array_t*) l15);
        VADER_ARRAY_RESOLVE_BUF(_a34_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a34_slotarr, l1)
        l9 = ((int32_t*) _a34_slotarr->buf->slots)[_a34_slotarr->offset + (size_t) l1];
        l11 = ((int32_t) (int64_t) l1);
        if (l9 != l11) {
            l16 = false;
            break;
        }
        l1 = (l1 + INT64_C(1));
    }
    if (l16) {
        { void* __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a35_arr = vader_array_new(247u, 0u, 13u, 1677u);
    l5 = (void*) _a35_arr;
    l1 = INT64_C(0);
    while ((l1 < l4)) {
        vader_array_t* _a36_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a36_slotarr)
        l31 = vader_array_ref_load_box(_a36_slotarr->buf, _a36_slotarr->offset + (size_t) l1);
        l9 = vader_core_bytecode$slot_touched(l31);
        if ((l9 >= INT32_C(0))) {
            vader_array_t* _a37_slotarr = ((vader_array_t*) l15);
            VADER_ARRAY_RESOLVE_BUF(_a37_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a37_slotarr, l9)
            l11 = ((int32_t*) _a37_slotarr->buf->slots)[_a37_slotarr->offset + (size_t) l9];
            if ((l11 >= INT32_C(0))) {
                l32 = vader_core_bytecode$with_remapped_slot(l31, l11);
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
    l7 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l3)->f_signature;
    l15 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l3)->f_debug;
    l17 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l3)->f_jump_table;
    l3 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l3)->f_source_pc;
    vader_struct_vader_core_bytecode$BcFunction_t* _a38_obj = (vader_struct_vader_core_bytecode$BcFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcFunction_t));
    vader_obj_header_init(_a38_obj, 729u);
    _a38_obj->f_name = l34;
    _a38_obj->f_is_main = l16;
    _a38_obj->f_signature = l7;
    _a38_obj->f_locals = l8;
    _a38_obj->f_body = l5;
    _a38_obj->f_debug = l15;
    _a38_obj->f_jump_table = l17;
    _a38_obj->f_source_pc = l3;
    t3 = (void*) _a38_obj;
    { void* __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_emit_bytecode$collect_baked_symbols(vader_box_t l0, void* l1) {
    int32_t l2;
    void* l3 = NULL;
    int64_t l4, l5;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l0, &t1 };
    void** gc_raw_roots[3] = { &l1, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 743u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_core_bytecode$BcValStruct_t*) t0)->f_symbol_id;
        std_collections$add__i32(l1, l2);
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_core_bytecode$BcValStruct_t*) t0)->f_fields;
        l4 = ((vader_array_t*) l3)->length;
        l5 = INT64_C(0);
        while ((l5 < l4)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            t1 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
            vader_emit_bytecode$collect_baked_symbols(t1, l1);
            l5 = (l5 + INT64_C(1));
        }
    } else if (l0.tag == 740u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_core_bytecode$BcValArray_t*) t0)->f_elements;
        l4 = ((vader_array_t*) l3)->length;
        l5 = INT64_C(0);
        while ((l5 < l4)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            t1 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5);
            vader_emit_bytecode$collect_baked_symbols(t1, l1);
            l5 = (l5 + INT64_C(1));
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
    if (l0.tag == 817u) {
        t0 = vader_core_bytecode$is_64_bit_int_val(l1);
        return t0;
    }
    if (!(l0.tag == 797u)) {
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
    } else if (l0.tag == 864u) {
        l1 = (uint8_t) 12;
    } else {
        if (!(l0.tag == 848u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = (uint8_t) 13;
    }
    return l1;
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
    vader_obj_header_init(_a0_obj, 768u);
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
    vader_array_t* _a0_arr = vader_array_new(21u, 0u, 0u, 335u);
    l0 = (void*) _a0_arr;
    vader_struct_vader_emit_bytecode$EmitOptions_t* _a1_obj = (vader_struct_vader_emit_bytecode$EmitOptions_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_bytecode$EmitOptions_t));
    vader_obj_header_init(_a1_obj, 922u);
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
        if (t0 == 2295u) {
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
    vader_obj_header_init(_a2_obj, 925u);
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
    vader_array_t* _a0_arr = vader_array_new(88u, 0u, 13u, 925u);
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
    int64_t l1, l2, l4, l6;
    void* l3 = NULL;
    void* l5 = NULL;
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
    void** gc_raw_roots[11] = { &l0, &l3, &l5, &l13, &l14, &l15, &l16, &l20, &l23, &l29, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l32 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 11u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_signature)->f_params)->length;
    l2 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_locals)->length;
    l2 = vader_chk_add(i64, l1, l2);
    vader_array_t* _a0_arr = vader_array_new(22u, 0u, 7u, 338u);
    l3 = (void*) _a0_arr;
    if ((INT64_C(0) < l2)) {
        l4 = l2;
    } else {
        l4 = INT64_C(0);
    }
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l3, (int64_t) l4);
    l3 = (void*) _a1_arr;
    l4 = INT64_C(0);
    vader_array_t* _pc29_hdr = (vader_array_t*) l3;
    size_t _pc29_len = _pc29_hdr->length;
    size_t _pc29_cap = (_pc29_hdr->offset == 0 && !vader_array_is_borrowed(_pc29_hdr) && _pc29_hdr->length >= _pc29_hdr->buf->length) ? _pc29_hdr->capacity : (size_t) 0;
    void* _pc29_slots = _pc29_hdr->buf->slots;
    for (;;) {
        if ((l4 < l2)) {
            if (VADER_LIKELY(_pc29_len < _pc29_cap)) {
                ((int32_t*) _pc29_slots)[_pc29_len] = (int32_t) (INT32_C(0));
                _pc29_len += 1;
            } else {
                _pc29_hdr->length = _pc29_len;
                if (_pc29_hdr->buf->length < _pc29_len) {
                    _pc29_hdr->buf->length = _pc29_len;
                }
                vader_array_push_i32((vader_array_t*) l3, INT32_C(0));
                _pc29_hdr = (vader_array_t*) l3;
                _pc29_len = _pc29_hdr->length;
                _pc29_cap = (_pc29_hdr->offset == 0 && !vader_array_is_borrowed(_pc29_hdr) && _pc29_hdr->length >= _pc29_hdr->buf->length) ? _pc29_hdr->capacity : (size_t) 0;
                _pc29_slots = _pc29_hdr->buf->slots;
            }
            l4 = (l4 + INT64_C(1));
            continue;
        }
        _pc29_hdr->length = _pc29_len;
        if (_pc29_hdr->buf->length < _pc29_len) {
            _pc29_hdr->buf->length = _pc29_len;
        }
        break;
    }
    l5 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_body;
    l4 = ((vader_array_t*) l5)->length;
    l6 = INT64_C(0);
    while ((l6 < l4)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        l7 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l6);
        if (l7.tag == 842u) {
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
        if (l7.tag == 841u) {
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
    vader_array_t* _a5_arr = vader_array_new(19u, 0u, 12u, 333u);
    l5 = (void*) _a5_arr;
    if ((INT64_C(0) < l2)) {
        l4 = l2;
    } else {
        l4 = INT64_C(0);
    }
    vader_array_t* _a6_arr = vader_array_repeat((vader_array_t*) l5, (int64_t) l4);
    l5 = (void*) _a6_arr;
    l4 = INT64_C(0);
    vader_array_t* _pc121_hdr = (vader_array_t*) l5;
    size_t _pc121_len = _pc121_hdr->length;
    size_t _pc121_cap = (_pc121_hdr->offset == 0 && !vader_array_is_borrowed(_pc121_hdr) && _pc121_hdr->length >= _pc121_hdr->buf->length) ? _pc121_hdr->capacity : (size_t) 0;
    void* _pc121_slots = _pc121_hdr->buf->slots;
    for (;;) {
        if ((l4 < l2)) {
            if (VADER_LIKELY(_pc121_len < _pc121_cap)) {
                ((uint8_t*) _pc121_slots)[_pc121_len] = (uint8_t) (false);
                _pc121_len += 1;
            } else {
                _pc121_hdr->length = _pc121_len;
                if (_pc121_hdr->buf->length < _pc121_len) {
                    _pc121_hdr->buf->length = _pc121_len;
                }
                vader_array_push_bool((vader_array_t*) l5, false);
                _pc121_hdr = (vader_array_t*) l5;
                _pc121_len = _pc121_hdr->length;
                _pc121_cap = (_pc121_hdr->offset == 0 && !vader_array_is_borrowed(_pc121_hdr) && _pc121_hdr->length >= _pc121_hdr->buf->length) ? _pc121_hdr->capacity : (size_t) 0;
                _pc121_slots = _pc121_hdr->buf->slots;
            }
            l4 = (l4 + INT64_C(1));
            continue;
        }
        _pc121_hdr->length = _pc121_len;
        if (_pc121_hdr->buf->length < _pc121_len) {
            _pc121_hdr->buf->length = _pc121_len;
        }
        break;
    }
    l12 = false;
    l4 = l1;
    while ((l4 < l2)) {
        vader_array_t* _a7_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l4)
        t1 = ((int32_t*) _a7_slotarr->buf->slots)[_a7_slotarr->offset + (size_t) l4];
        if (t1 == INT32_C(0)) {
            vader_array_t* _a8_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l4)
            ((uint8_t*) _a8_slotarr->buf->slots)[_a8_slotarr->offset + (size_t) l4] = (uint8_t) true;
            l12 = true;
        }
        l4 = (l4 + INT64_C(1));
    }
    if (!(l12)) {
        { void* __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a9_arr = vader_array_new(22u, 0u, 7u, 338u);
    l3 = (void*) _a9_arr;
    if ((INT64_C(0) < l2)) {
        l4 = l2;
    } else {
        l4 = INT64_C(0);
    }
    vader_array_t* _a10_arr = vader_array_repeat((vader_array_t*) l3, (int64_t) l4);
    l3 = (void*) _a10_arr;
    l4 = INT64_C(0);
    vader_array_t* _pc189_hdr = (vader_array_t*) l3;
    size_t _pc189_len = _pc189_hdr->length;
    size_t _pc189_cap = (_pc189_hdr->offset == 0 && !vader_array_is_borrowed(_pc189_hdr) && _pc189_hdr->length >= _pc189_hdr->buf->length) ? _pc189_hdr->capacity : (size_t) 0;
    void* _pc189_slots = _pc189_hdr->buf->slots;
    for (;;) {
        if ((l4 < l2)) {
            if (VADER_LIKELY(_pc189_len < _pc189_cap)) {
                ((int32_t*) _pc189_slots)[_pc189_len] = (int32_t) (INT32_C(-1));
                _pc189_len += 1;
            } else {
                _pc189_hdr->length = _pc189_len;
                if (_pc189_hdr->buf->length < _pc189_len) {
                    _pc189_hdr->buf->length = _pc189_len;
                }
                vader_array_push_i32((vader_array_t*) l3, INT32_C(-1));
                _pc189_hdr = (vader_array_t*) l3;
                _pc189_len = _pc189_hdr->length;
                _pc189_cap = (_pc189_hdr->offset == 0 && !vader_array_is_borrowed(_pc189_hdr) && _pc189_hdr->length >= _pc189_hdr->buf->length) ? _pc189_hdr->capacity : (size_t) 0;
                _pc189_slots = _pc189_hdr->buf->slots;
            }
            l4 = (l4 + INT64_C(1));
            continue;
        }
        _pc189_hdr->length = _pc189_len;
        if (_pc189_hdr->buf->length < _pc189_len) {
            _pc189_hdr->buf->length = _pc189_len;
        }
        break;
    }
    l8 = INT32_C(0);
    l4 = INT64_C(0);
    while ((l4 < l2)) {
        vader_array_t* _a11_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l4)
        t2 = ((uint8_t*) _a11_slotarr->buf->slots)[_a11_slotarr->offset + (size_t) l4];
        t3 = t2;
        if (!(t3)) {
            vader_array_t* _a12_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a12_slotarr, l4)
            ((int32_t*) _a12_slotarr->buf->slots)[_a12_slotarr->offset + (size_t) l4] = (int32_t) l8;
            l8 = vader_chk_add(i32, l8, INT32_C(1));
        }
        l4 = (l4 + INT64_C(1));
    }
    vader_array_t* _a13_arr = vader_array_new(247u, 0u, 13u, 1677u);
    l13 = (void*) _a13_arr;
    l4 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_body)->length;
    vader_array_t* _a14_arr = vader_array_new(22u, 0u, 7u, 338u);
    l14 = (void*) _a14_arr;
    if ((INT64_C(0) < l4)) {
        l6 = l4;
    } else {
        l6 = INT64_C(0);
    }
    vader_array_t* _a15_arr = vader_array_repeat((vader_array_t*) l14, (int64_t) l6);
    l14 = (void*) _a15_arr;
    l6 = INT64_C(0);
    vader_array_t* _pc258_hdr = (vader_array_t*) l14;
    size_t _pc258_len = _pc258_hdr->length;
    size_t _pc258_cap = (_pc258_hdr->offset == 0 && !vader_array_is_borrowed(_pc258_hdr) && _pc258_hdr->length >= _pc258_hdr->buf->length) ? _pc258_hdr->capacity : (size_t) 0;
    void* _pc258_slots = _pc258_hdr->buf->slots;
    for (;;) {
        if ((l6 < l4)) {
            if (VADER_LIKELY(_pc258_len < _pc258_cap)) {
                ((int32_t*) _pc258_slots)[_pc258_len] = (int32_t) (INT32_C(-1));
                _pc258_len += 1;
            } else {
                _pc258_hdr->length = _pc258_len;
                if (_pc258_hdr->buf->length < _pc258_len) {
                    _pc258_hdr->buf->length = _pc258_len;
                }
                vader_array_push_i32((vader_array_t*) l14, INT32_C(-1));
                _pc258_hdr = (vader_array_t*) l14;
                _pc258_len = _pc258_hdr->length;
                _pc258_cap = (_pc258_hdr->offset == 0 && !vader_array_is_borrowed(_pc258_hdr) && _pc258_hdr->length >= _pc258_hdr->buf->length) ? _pc258_hdr->capacity : (size_t) 0;
                _pc258_slots = _pc258_hdr->buf->slots;
            }
            l6 = (l6 + INT64_C(1));
            continue;
        }
        _pc258_hdr->length = _pc258_len;
        if (_pc258_hdr->buf->length < _pc258_len) {
            _pc258_hdr->buf->length = _pc258_len;
        }
        break;
    }
    l6 = INT64_C(0);
    while ((l6 < l4)) {
        vader_array_t* _a16_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_body);
        VADER_ARRAY_RESOLVE_BUF(_a16_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a16_slotarr, l6)
        l7 = vader_array_ref_load_box(_a16_slotarr->buf, _a16_slotarr->offset + (size_t) l6);
        if (l7.tag == 843u) {
            t0 = l7.payload.obj;
            l8 = ((vader_struct_vader_core_bytecode$LocalSet_t*) t0)->f_slot;
            vader_array_t* _a17_slotarr = ((vader_array_t*) l5);
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
                vader_struct_vader_core_bytecode$Drop_t* _a19_obj = (vader_struct_vader_core_bytecode$Drop_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$Drop_t));
                vader_obj_header_init(_a19_obj, 771u);
                l15 = (void*) _a19_obj;
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
                vader_obj_header_init(_a22_obj, 843u);
                _a22_obj->f_slot = t1;
                l16 = (void*) _a22_obj;
                vader_array_push_ref((vader_array_t*) l13, l16);
            }
            l6 = vader_chk_add(i64, l6, INT64_C(1));
            continue;
        }
        if (l7.tag == 844u) {
            t0 = l7.payload.obj;
            l17 = ((vader_struct_vader_core_bytecode$LocalTee_t*) t0)->f_slot;
            vader_array_t* _a23_slotarr = ((vader_array_t*) l5);
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
            vader_obj_header_init(_a26_obj, 844u);
            _a26_obj->f_slot = t1;
            l20 = (void*) _a26_obj;
            vader_array_push_ref((vader_array_t*) l13, l20);
            l6 = vader_chk_add(i64, l6, INT64_C(1));
            continue;
        }
        if (l7.tag == 842u) {
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
            vader_obj_header_init(_a29_obj, 842u);
            _a29_obj->f_slot = t1;
            l23 = (void*) _a29_obj;
            vader_array_push_ref((vader_array_t*) l13, l23);
            l6 = vader_chk_add(i64, l6, INT64_C(1));
            continue;
        }
        if (l7.tag == 841u) {
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
            vader_obj_header_init(_a32_obj, 841u);
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
    l4 = ((vader_array_t*) l13)->length;
    l3 = vader_core_bytecode$remap_jump_table(l3, l14, l4);
    l15 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_debug;
    l4 = ((vader_array_t*) l13)->length;
    l14 = vader_emit_bytecode$remap_debug(l15, l14, l4);
    vader_array_t* _a34_arr = vader_array_new(63u, 0u, 13u, 732u);
    l15 = (void*) _a34_arr;
    l4 = l1;
    while ((l4 < l2)) {
        vader_array_t* _a35_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a35_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a35_slotarr, l4)
        t2 = ((uint8_t*) _a35_slotarr->buf->slots)[_a35_slotarr->offset + (size_t) l4];
        t3 = t2;
        if (!(t3)) {
            l16 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_locals;
            l6 = vader_chk_sub(i64, l4, l1);
            vader_array_t* _a36_slotarr = ((vader_array_t*) l16);
            VADER_ARRAY_RESOLVE_BUF(_a36_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a36_slotarr, l6)
            l20 = vader_array_ref_load_obj(_a36_slotarr->buf, _a36_slotarr->offset + (size_t) l6);
            vader_array_push_ref((vader_array_t*) l15, l20);
        }
        l4 = (l4 + INT64_C(1));
    }
    l5 = l0;
    l32 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l5)->f_name;
    l12 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l5)->f_is_main;
    l16 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l5)->f_signature;
    l5 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l5)->f_source_pc;
    vader_struct_vader_core_bytecode$BcFunction_t* _a37_obj = (vader_struct_vader_core_bytecode$BcFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcFunction_t));
    vader_obj_header_init(_a37_obj, 729u);
    _a37_obj->f_name = l32;
    _a37_obj->f_is_main = l12;
    _a37_obj->f_signature = l16;
    _a37_obj->f_locals = l15;
    _a37_obj->f_body = l13;
    _a37_obj->f_debug = l14;
    _a37_obj->f_jump_table = l3;
    _a37_obj->f_source_pc = l5;
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
    vader_array_t* _a0_arr = vader_array_new(19u, 1u, 12u, 333u);
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
        if ((t0.tag == 753u || t0.tag == 754u)) {
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
    vader_array_t* _a5_arr = vader_array_new(19u, 1u, 12u, 333u);
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
        if (t0.tag == 746u) {
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
    vader_array_t* _a11_arr = vader_array_new(247u, 0u, 13u, 1677u);
    l4 = (void*) _a11_arr;
    vader_array_t* _a12_arr = vader_array_new(22u, 0u, 7u, 338u);
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
    vader_obj_header_init(_a15_obj, 920u);
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
    vader_array_t* _a5_arr = vader_array_new(22u, 0u, 7u, 338u);
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
    l7 = ((vader_array_t*) l5)->length;
    l8 = INT64_C(0);
    while ((l8 < l7)) {
        vader_array_t* _a8_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
        l19 = vader_array_ref_load_box(_a8_slotarr->buf, _a8_slotarr->offset + (size_t) l8);
        if (l19.tag == 737u) {
            t2 = l19.payload.obj;
            l6 = ((vader_struct_vader_core_bytecode$BcStrData_t*) t2)->f_values;
            l10 = ((vader_array_t*) l6)->length;
            l11 = INT64_C(0);
            while ((l11 < l10)) {
                vader_array_t* _a9_slotarr = ((vader_array_t*) l6);
                VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
                t0 = vader_array_box_slots(_a9_slotarr->buf)[_a9_slotarr->offset + (size_t) l11];
                t1 = t0.payload.s;
                vader_emit_bytecode$intern_string(t1, l3);
                l11 = (l11 + INT64_C(1));
            }
        } else if (l19.tag == 724u) {
            t2 = l19.payload.obj;
            l9 = ((vader_struct_vader_core_bytecode$BcAggregateData_t*) t2)->f_elements;
            l13 = ((vader_array_t*) l9)->length;
            l14 = INT64_C(0);
            while ((l14 < l13)) {
                vader_array_t* _a10_slotarr = ((vader_array_t*) l9);
                VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
                t0 = vader_array_ref_load_box(_a10_slotarr->buf, _a10_slotarr->offset + (size_t) l14);
                vader_emit_bytecode$intern_data_value_strings(t0, l3);
                l14 = (l14 + INT64_C(1));
            }
        }
        l8 = (l8 + INT64_C(1));
    }
    l5 = ((vader_struct_vader_midir$CFGProject_t*) l0)->f_globals;
    l7 = ((vader_array_t*) l5)->length;
    l8 = INT64_C(0);
    while ((l8 < l7)) {
        vader_array_t* _a11_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
        l6 = vader_array_ref_load_obj(_a11_slotarr->buf, _a11_slotarr->offset + (size_t) l8);
        l9 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l3)->f_globals;
        l20 = ((vader_struct_vader_lower_ir$GlobalSlot_t*) l6)->f_name;
        l18 = vader_emit_bytecode$intern_type(((vader_struct_vader_lower_ir$GlobalSlot_t*) l6)->f_type, l3);
        vader_struct_vader_core_bytecode$BcGlobal_t* _a12_obj = (vader_struct_vader_core_bytecode$BcGlobal_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcGlobal_t));
        vader_obj_header_init(_a12_obj, 730u);
        _a12_obj->f_name = l20;
        _a12_obj->f_type_id = l18;
        l12 = (void*) _a12_obj;
        vader_array_push_ref((vader_array_t*) l9, l12);
        l8 = (l8 + INT64_C(1));
    }
    l5 = ((vader_struct_vader_midir$CFGProject_t*) l0)->f_modules;
    l6 = ((vader_struct_std_collections$MutableMap__string__vader_midir_CFGModule_t*) l5)->f_ekeys;
    l9 = ((vader_struct_std_collections$MutableMap__string__vader_midir_CFGModule_t*) l5)->f_evals;
    l7 = INT64_C(0);
    l8 = ((vader_struct_std_collections$MutableMap__string__vader_midir_CFGModule_t*) l5)->f_size;
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
        l5 = ((vader_struct_vader_midir$CFGModule_t*) t2)->f_functions;
        l10 = ((vader_array_t*) l5)->length;
        l11 = INT64_C(0);
        while ((l11 < l10)) {
            vader_array_t* _a15_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a15_slotarr, l11)
            l12 = vader_array_ref_load_obj(_a15_slotarr->buf, _a15_slotarr->offset + (size_t) l11);
            l18 = INT32_C(-1);
            l19 = ((vader_struct_vader_core_mono$MonoEntry_t*) ((vader_struct_vader_midir$CFGFunction_t*) l12)->f_origin)->f_symbol;
            if (l19.tag == 892u) {
                l15 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l3)->f_function_index_by_symbol_id;
                t2 = l19.payload.obj;
                l21 = ((vader_struct_vader_core_symbol$Symbol_t*) t2)->f_id;
                l22 = std_collections$MutableMap$std_core$Index$at__i32__i32(l15, l21);
                if (l22.tag == 338u) {
                    l18 = ((int32_t) l22.payload.i);
                }
            }
            if ((l18 < INT32_C(0))) {
                l23 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l3)->f_function_index_by_mangle;
                l20 = ((vader_struct_vader_midir$CFGFunction_t*) l12)->f_mangled;
                l24 = std_collections$MutableMap$std_core$Index$at__string__i32(l23, l20);
                if (l24.tag == 338u) {
                    l18 = ((int32_t) l24.payload.i);
                }
            }
            if ((l18 >= INT32_C(0))) {
                l25 = ((vader_struct_vader_emit_bytecode$EmitOptions_t*) l2)->f_want_debug;
                vader_emit_bytecode$emit_cfg_function_body(l12, l18, l3, l4, l25);
            }
            l11 = (l11 + INT64_C(1));
        }
        l7 = (l7 + INT64_C(1));
    }
    l4 = ((vader_struct_vader_midir$CFGProject_t*) l0)->f_data_pool;
    t3 = ((vader_struct_vader_emit_bytecode$EmitOptions_t*) l2)->f_optimize;
    if (t3) {
        l7 = INT64_C(0);
        l8 = ((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l3)->f_functions)->length;
        while ((l7 < l8)) {
            vader_array_t* _a16_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l3)->f_functions);
            VADER_ARRAY_RESOLVE_BUF(_a16_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a16_slotarr, l7)
            t2 = vader_array_ref_load_obj(_a16_slotarr->buf, _a16_slotarr->offset + (size_t) l7);
            t4 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) t2)->f_body)->length;
            l10 = vader_chk_add(i64, t4, INT64_C(1));
            for (;;) {
                vader_array_t* _a17_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l3)->f_functions);
                VADER_ARRAY_RESOLVE_BUF(_a17_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a17_slotarr, l7)
                t2 = vader_array_ref_load_obj(_a17_slotarr->buf, _a17_slotarr->offset + (size_t) l7);
                t4 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) t2)->f_body)->length;
                if ((t4 < l10)) {
                    vader_array_t* _a18_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l3)->f_functions);
                    VADER_ARRAY_RESOLVE_BUF(_a18_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a18_slotarr, l7)
                    t2 = vader_array_ref_load_obj(_a18_slotarr->buf, _a18_slotarr->offset + (size_t) l7);
                    l10 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) t2)->f_body)->length;
                    l5 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l3)->f_functions;
                    VADER_ARRAY_CHECK_INDEX(_a18_slotarr, l7)
                    t2 = vader_array_ref_load_obj(_a18_slotarr->buf, _a18_slotarr->offset + (size_t) l7);
                    l6 = vader_emit_bytecode$propagate_const_single_use(t2);
                    vader_array_t* _a19_slotarr = ((vader_array_t*) l5);
                    VADER_ARRAY_RESOLVE_BUF(_a19_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a19_slotarr, l7)
                    vader_array_ref_store(_a19_slotarr->buf, _a19_slotarr->offset + (size_t) l7, l6);
                    VADER_WRITE_BARRIER(_a19_slotarr->buf);
                    continue;
                }
                break;
            }
            l9 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l3)->f_functions;
            vader_array_t* _a20_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l3)->f_functions);
            VADER_ARRAY_RESOLVE_BUF(_a20_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a20_slotarr, l7)
            l12 = vader_array_ref_load_obj(_a20_slotarr->buf, _a20_slotarr->offset + (size_t) l7);
            VADER_ARRAY_CHECK_INDEX(_a20_slotarr, l7)
            t2 = vader_array_ref_load_obj(_a20_slotarr->buf, _a20_slotarr->offset + (size_t) l7);
            l15 = vader_emit_bytecode$run_bc_peephole(t2);
            l23 = vader_emit_bytecode$with_peephole_out(l12, l15);
            vader_array_t* _a21_slotarr = ((vader_array_t*) l9);
            VADER_ARRAY_RESOLVE_BUF(_a21_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a21_slotarr, l7)
            vader_array_ref_store(_a21_slotarr->buf, _a21_slotarr->offset + (size_t) l7, l23);
            VADER_WRITE_BARRIER(_a21_slotarr->buf);
            l26 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l3)->f_functions;
            vader_array_t* _a22_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l3)->f_functions);
            VADER_ARRAY_RESOLVE_BUF(_a22_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a22_slotarr, l7)
            l27 = vader_array_ref_load_obj(_a22_slotarr->buf, _a22_slotarr->offset + (size_t) l7);
            VADER_ARRAY_CHECK_INDEX(_a22_slotarr, l7)
            t2 = vader_array_ref_load_obj(_a22_slotarr->buf, _a22_slotarr->offset + (size_t) l7);
            l28 = vader_emit_bytecode$run_bc_const_fold_arith(t2);
            l29 = vader_emit_bytecode$with_peephole_out(l27, l28);
            vader_array_t* _a23_slotarr = ((vader_array_t*) l26);
            VADER_ARRAY_RESOLVE_BUF(_a23_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a23_slotarr, l7)
            vader_array_ref_store(_a23_slotarr->buf, _a23_slotarr->offset + (size_t) l7, l29);
            VADER_WRITE_BARRIER(_a23_slotarr->buf);
            l30 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l3)->f_functions;
            vader_array_t* _a24_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l3)->f_functions);
            VADER_ARRAY_RESOLVE_BUF(_a24_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a24_slotarr, l7)
            t2 = vader_array_ref_load_obj(_a24_slotarr->buf, _a24_slotarr->offset + (size_t) l7);
            l31 = vader_emit_bytecode$drop_dead_stores(t2);
            vader_array_t* _a25_slotarr = ((vader_array_t*) l30);
            VADER_ARRAY_RESOLVE_BUF(_a25_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a25_slotarr, l7)
            vader_array_ref_store(_a25_slotarr->buf, _a25_slotarr->offset + (size_t) l7, l31);
            VADER_WRITE_BARRIER(_a25_slotarr->buf);
            l32 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l3)->f_functions;
            vader_array_t* _a26_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l3)->f_functions);
            VADER_ARRAY_RESOLVE_BUF(_a26_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a26_slotarr, l7)
            l33 = vader_array_ref_load_obj(_a26_slotarr->buf, _a26_slotarr->offset + (size_t) l7);
            VADER_ARRAY_CHECK_INDEX(_a26_slotarr, l7)
            t2 = vader_array_ref_load_obj(_a26_slotarr->buf, _a26_slotarr->offset + (size_t) l7);
            l34 = vader_emit_bytecode$run_bc_return_lit_fold(t2);
            l35 = vader_emit_bytecode$with_peephole_out(l33, l34);
            vader_array_t* _a27_slotarr = ((vader_array_t*) l32);
            VADER_ARRAY_RESOLVE_BUF(_a27_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a27_slotarr, l7)
            vader_array_ref_store(_a27_slotarr->buf, _a27_slotarr->offset + (size_t) l7, l35);
            VADER_WRITE_BARRIER(_a27_slotarr->buf);
            l36 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l3)->f_functions;
            vader_array_t* _a28_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l3)->f_functions);
            VADER_ARRAY_RESOLVE_BUF(_a28_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a28_slotarr, l7)
            t2 = vader_array_ref_load_obj(_a28_slotarr->buf, _a28_slotarr->offset + (size_t) l7);
            l37 = vader_emit_bytecode$coalesce_slots(t2);
            vader_array_t* _a29_slotarr = ((vader_array_t*) l36);
            VADER_ARRAY_RESOLVE_BUF(_a29_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a29_slotarr, l7)
            vader_array_ref_store(_a29_slotarr->buf, _a29_slotarr->offset + (size_t) l7, l37);
            VADER_WRITE_BARRIER(_a29_slotarr->buf);
            l38 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l3)->f_functions;
            vader_array_t* _a30_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l3)->f_functions);
            VADER_ARRAY_RESOLVE_BUF(_a30_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a30_slotarr, l7)
            l39 = vader_array_ref_load_obj(_a30_slotarr->buf, _a30_slotarr->offset + (size_t) l7);
            VADER_ARRAY_CHECK_INDEX(_a30_slotarr, l7)
            t2 = vader_array_ref_load_obj(_a30_slotarr->buf, _a30_slotarr->offset + (size_t) l7);
            l40 = vader_emit_bytecode$strip_self_copies(t2);
            l41 = vader_emit_bytecode$with_peephole_out(l39, l40);
            vader_array_t* _a31_slotarr = ((vader_array_t*) l38);
            VADER_ARRAY_RESOLVE_BUF(_a31_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a31_slotarr, l7)
            vader_array_ref_store(_a31_slotarr->buf, _a31_slotarr->offset + (size_t) l7, l41);
            VADER_WRITE_BARRIER(_a31_slotarr->buf);
            l7 = (l7 + INT64_C(1));
        }
        vader_array_t* _a32_arr = vader_array_new(21u, 0u, 0u, 335u);
        l5 = (void*) _a32_arr;
        vader_array_t* _a33_arr = vader_array_new(19u, 0u, 12u, 333u);
        l6 = (void*) _a33_arr;
        vader_array_t* _a34_arr = vader_array_new(22u, 0u, 7u, 338u);
        l9 = (void*) _a34_arr;
        vader_struct_std_collections$MutableMap__string__bool_t* _a35_obj = (vader_struct_std_collections$MutableMap__string__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__string__bool_t));
        vader_obj_header_init(_a35_obj, 539u);
        _a35_obj->f_ekeys = l5;
        _a35_obj->f_evals = l6;
        _a35_obj->f_index = l9;
        _a35_obj->f_mask = INT64_C(0);
        _a35_obj->f_grow_at = INT64_C(0);
        _a35_obj->f_size = INT64_C(0);
        _a35_obj->f_tombs = INT64_C(0);
        l5 = (void*) _a35_obj;
        l6 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l3)->f_functions;
        l7 = ((vader_array_t*) l6)->length;
        l8 = INT64_C(0);
        while ((l8 < l7)) {
            vader_array_t* _a36_slotarr = ((vader_array_t*) l6);
            VADER_ARRAY_RESOLVE_BUF(_a36_slotarr)
            t2 = vader_array_ref_load_obj(_a36_slotarr->buf, _a36_slotarr->offset + (size_t) l8);
            l9 = ((vader_struct_vader_core_bytecode$BcFunction_t*) t2)->f_body;
            l10 = ((vader_array_t*) l9)->length;
            l11 = INT64_C(0);
            while ((l11 < l10)) {
                vader_array_t* _a37_slotarr = ((vader_array_t*) l9);
                VADER_ARRAY_RESOLVE_BUF(_a37_slotarr)
                l19 = vader_array_ref_load_box(_a37_slotarr->buf, _a37_slotarr->offset + (size_t) l11);
                if (l19.tag == 887u) {
                    t2 = l19.payload.obj;
                    l20 = ((vader_struct_vader_core_bytecode$VirtualCall_t*) t2)->f_vtable_key;
                    std_collections$MutableMap$std_core$IndexSet$set_at__string__bool(l5, l20, true);
                }
                l11 = (l11 + INT64_C(1));
            }
            l8 = (l8 + INT64_C(1));
        }
        vader_array_t* _a38_arr = vader_array_new(22u, 0u, 7u, 338u);
        l6 = (void*) _a38_arr;
        l9 = ((vader_struct_vader_midir$CFGProject_t*) l0)->f_vtable_entries;
        l7 = ((vader_array_t*) l9)->length;
        l8 = INT64_C(0);
        while ((l8 < l7)) {
            vader_array_t* _a39_slotarr = ((vader_array_t*) l9);
            VADER_ARRAY_RESOLVE_BUF(_a39_slotarr)
            l12 = vader_array_ref_load_obj(_a39_slotarr->buf, _a39_slotarr->offset + (size_t) l8);
            l20 = ((vader_struct_vader_lower_ir$LoweredVtableEntry_t*) l12)->f_trait_name;
            l42 = ((vader_struct_vader_lower_ir$LoweredVtableEntry_t*) l12)->f_method_name;
            l43 = vader_midir$vtable_key(l20, l42);
            t0 = std_collections$MutableMap$std_core$Index$at__string__bool(l5, l43);
            if (t0.tag == 333u) {
                l44 = vader_midir_select$type_intern_key(((vader_struct_vader_lower_ir$LoweredVtableEntry_t*) l12)->f_struct_type);
                l19 = std_collections$MutableMap$std_core$Index$at__string__i32(((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l3)->f_type_key, l44);
                if (l19.tag == 338u) {
                    l15 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l3)->f_pinned_types;
                    l18 = ((int32_t) l19.payload.i);
                    vader_array_push_i32((vader_array_t*) l15, l18);
                }
                l22 = vader_emit_bytecode$resolve_fn_index(((vader_struct_vader_lower_ir$LoweredVtableEntry_t*) l12)->f_fn_symbol, l3);
                if (!(l22.tag == 0u)) {
                    l21 = ((int32_t) l22.payload.i);
                    vader_array_push_i32((vader_array_t*) l6, l21);
                }
                l8 = (l8 + INT64_C(1));
                continue;
            }
            l8 = (l8 + INT64_C(1));
        }
        l5 = ((vader_struct_vader_emit_bytecode$EmitOptions_t*) l2)->f_keep_mangles;
        vader_emit_bytecode$prune_unused_functions(l3, l6, l5);
        vader_emit_bytecode$prune_unused_imports(l3);
        l4 = vader_emit_bytecode$prune_unused_data(l3, l4);
        vader_emit_bytecode$prune_unused_globals(l3);
        vader_emit_bytecode$pin_baked_struct_types(l4, l3);
        vader_emit_bytecode$prune_unused_types(l3);
        ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l3)->f_types_frozen = true;
        l5 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l3)->f_imports;
        l7 = ((vader_array_t*) l5)->length;
        l8 = INT64_C(0);
        while ((l8 < l7)) {
            vader_array_t* _a40_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a40_slotarr)
            l6 = vader_array_ref_load_obj(_a40_slotarr->buf, _a40_slotarr->offset + (size_t) l8);
            l20 = ((vader_struct_vader_core_bytecode$BcImport_t*) l6)->f_mangled_name;
            l25 = ((vader_struct_vader_core_bytecode$BcImport_t*) l6)->f_is_extern;
            vader_midir_select$assert_host_import_wired(l20, l25);
            l8 = (l8 + INT64_C(1));
        }
    }
    l5 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l3)->f_types;
    l6 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l3)->f_strings;
    l9 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l3)->f_functions;
    l12 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l3)->f_imports;
    l15 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l3)->f_exports;
    l23 = ((vader_struct_vader_midir$CFGProject_t*) l0)->f_vtable_entries;
    l26 = ((vader_struct_vader_midir$CFGProject_t*) l0)->f_trait_membership;
    l23 = vader_emit_bytecode$build_impl_table_from_vtable(l23, l26, l3);
    l26 = vader_emit_bytecode$build_vtables_from_entries(((vader_struct_vader_midir$CFGProject_t*) l0)->f_vtable_entries, l3);
    l3 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l3)->f_globals;
    vader_struct_vader_core_bytecode$BytecodeModule_t* _a41_obj = (vader_struct_vader_core_bytecode$BytecodeModule_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BytecodeModule_t));
    vader_obj_header_init(_a41_obj, 758u);
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
        l4 = vader_box_i32(338u, t1);
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
    vader_array_t* _a1_arr = vader_array_new(22u, 0u, 7u, 338u);
    l6 = (void*) _a1_arr;
    std_collections$MutableMap$std_core$IndexSet$set_at__i32__Any(((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l2)->f_pinned_types_by_fn, l1, vader_ref_box(l6));
    vader_array_t* _a2_arr = vader_array_new(22u, 0u, 7u, 338u);
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
            vader_obj_header_init(_a4_obj, 732u);
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
    vader_array_t* _a5_arr = vader_array_new(89u, 0u, 13u, 927u);
    l19 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(88u, 0u, 13u, 925u);
    l20 = (void*) _a6_arr;
    vader_struct_vader_emit_bytecode$FnEmitCfg_t* _a7_obj = (vader_struct_vader_emit_bytecode$FnEmitCfg_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_bytecode$FnEmitCfg_t));
    vader_obj_header_init(_a7_obj, 924u);
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
    if (l3.tag == 1321u) {
        t0 = vader_midir_select$val_type_of_type(((vader_struct_vader_midir$InstrConst_t*) l1)->f_type);
        t1 = vader_core_bytecode$is_64_bit_int_val(t0);
        if (t1) {
            t2 = l3.payload.obj;
            t3 = ((vader_struct_vader_midir$ConstInt_t*) t2)->f_value;
            vader_struct_vader_core_bytecode$I64Const_t* _a0_obj = (vader_struct_vader_core_bytecode$I64Const_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$I64Const_t));
            vader_obj_header_init(_a0_obj, 817u);
            _a0_obj->f_value = t3;
            l4 = (void*) _a0_obj;
            l5 = ((vader_struct_vader_midir$InstrConst_t*) l1)->f_span;
            vader_emit_bytecode$push_emit(l0, vader_ref_box(l4), l5);
        } else {
            t2 = l3.payload.obj;
            t3 = ((vader_struct_vader_midir$ConstInt_t*) t2)->f_value;
            vader_struct_vader_core_bytecode$I32Const_t* _a1_obj = (vader_struct_vader_core_bytecode$I32Const_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$I32Const_t));
            vader_obj_header_init(_a1_obj, 797u);
            _a1_obj->f_value = ((int32_t) (int64_t) t3);
            l4 = (void*) _a1_obj;
            l5 = ((vader_struct_vader_midir$InstrConst_t*) l1)->f_span;
            vader_emit_bytecode$push_emit(l0, vader_ref_box(l4), l5);
        }
    } else if (l3.tag == 1320u) {
        t2 = l3.payload.obj;
        t4 = ((vader_struct_vader_midir$ConstFloat_t*) t2)->f_value;
        vader_struct_vader_core_bytecode$F64Const_t* _a2_obj = (vader_struct_vader_core_bytecode$F64Const_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$F64Const_t));
        vader_obj_header_init(_a2_obj, 776u);
        _a2_obj->f_value = t4;
        l4 = (void*) _a2_obj;
        l5 = ((vader_struct_vader_midir$InstrConst_t*) l1)->f_span;
        vader_emit_bytecode$push_emit(l0, vader_ref_box(l4), l5);
    } else if (l3.tag == 1318u) {
        t2 = l3.payload.obj;
        t1 = ((vader_struct_vader_midir$ConstBool_t*) t2)->f_value;
        vader_struct_vader_core_bytecode$BoolConst_t* _a3_obj = (vader_struct_vader_core_bytecode$BoolConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BoolConst_t));
        vader_obj_header_init(_a3_obj, 748u);
        _a3_obj->f_value = t1;
        l4 = (void*) _a3_obj;
        l5 = ((vader_struct_vader_midir$InstrConst_t*) l1)->f_span;
        vader_emit_bytecode$push_emit(l0, vader_ref_box(l4), l5);
    } else if (l3.tag == 1319u) {
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
        vader_obj_header_init(_a4_obj, 763u);
        _a4_obj->f_value = ((uint32_t) (uint32_t) l6);
        l4 = (void*) _a4_obj;
        l5 = ((vader_struct_vader_midir$InstrConst_t*) l1)->f_span;
        vader_emit_bytecode$push_emit(l0, vader_ref_box(l4), l5);
    } else if (l3.tag == 1322u) {
        vader_struct_vader_core_bytecode$NullConst_t* _a5_obj = (vader_struct_vader_core_bytecode$NullConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$NullConst_t));
        vader_obj_header_init(_a5_obj, 848u);
        l4 = (void*) _a5_obj;
        l5 = ((vader_struct_vader_midir$InstrConst_t*) l1)->f_span;
        vader_emit_bytecode$push_emit(l0, vader_ref_box(l4), l5);
    } else if (l3.tag == 1323u) {
        l4 = ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_string_index_map;
        t2 = l3.payload.obj;
        l8 = ((vader_struct_vader_midir$ConstString_t*) t2)->f_index;
        vader_array_t* _a6_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l8)
        t5 = ((int32_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l8];
        vader_struct_vader_core_bytecode$StringConst_t* _a7_obj = (vader_struct_vader_core_bytecode$StringConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$StringConst_t));
        vader_obj_header_init(_a7_obj, 864u);
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
    vader_obj_header_init(_a1_obj, 842u);
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
    if (l1.tag == 1341u) {
        l3 = l1.payload.obj;
        vader_emit_bytecode$emit_const_instr(l0, l3, l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 1353u) {
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
    if (l1.tag == 1334u) {
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
    if (l1.tag == 1335u) {
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
    if (l1.tag == 1357u) {
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
    if (l1.tag == 1336u) {
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
        vader_obj_header_init(_a8_obj, 762u);
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
    if (l1.tag == 1348u) {
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir$InstrFnRef_t*) t0)->f_fn_symbol;
        l12 = ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_project;
        l7 = vader_emit_bytecode$resolve_fn_index(l3, l12);
        if (!(l7.tag == 338u)) {
            t0 = l1.payload.obj;
            l18 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_midir$InstrFnRef_t*) t0)->f_fn_symbol)->f_name;
            l5 = vader_host_std_core$byte_len(l18);
            l14 = (void*) vader_buffer_new((size_t) (INT64_C(98) + l5));
            l5 = INT64_C(0);
            l5 = std_core$write_string_at(l14, l5, 1871u);
            l5 = std_core$write_string_at(l14, l5, l18);
            l5 = std_core$write_string_at(l14, l5, 287u);
            t0 = l1.payload.obj;
            t3 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_midir$InstrFnRef_t*) t0)->f_fn_symbol)->f_id;
            l13 = ((int64_t) (int32_t) t3);
            l5 = std_core$write_int(l14, l5, l13);
            l5 = std_core$write_string_at(l14, l5, 327u);
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
        vader_obj_header_init(_a9_obj, 789u);
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
    if (l1.tag == 1347u) {
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir$InstrFnAddr_t*) t0)->f_fn_symbol;
        l12 = ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_project;
        l7 = vader_emit_bytecode$resolve_fn_index(l3, l12);
        if (!(l7.tag == 338u)) {
            t0 = l1.payload.obj;
            l18 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_midir$InstrFnAddr_t*) t0)->f_fn_symbol)->f_name;
            l5 = vader_host_std_core$byte_len(l18);
            l14 = (void*) vader_buffer_new((size_t) (INT64_C(111) + l5));
            l5 = INT64_C(0);
            l5 = std_core$write_string_at(l14, l5, 1870u);
            l5 = std_core$write_string_at(l14, l5, l18);
            l5 = std_core$write_string_at(l14, l5, 287u);
            t0 = l1.payload.obj;
            t3 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_midir$InstrFnAddr_t*) t0)->f_fn_symbol)->f_id;
            l13 = ((int64_t) (int32_t) t3);
            l5 = std_core$write_int(l14, l5, l13);
            l5 = std_core$write_string_at(l14, l5, 344u);
            t4 = std_core$finish_buffer(l14, l5);
            vader_host_std_abort$panic(t4);
            vader_unreachable("a no-return call returned");
        }
        t3 = ((int32_t) l7.payload.i);
        vader_struct_vader_core_bytecode$FnAddr_t* _a10_obj = (vader_struct_vader_core_bytecode$FnAddr_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$FnAddr_t));
        vader_obj_header_init(_a10_obj, 788u);
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
    if (l1.tag == 1360u) {
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
        vader_array_t* _a11_arr = vader_array_new(24u, 1u, 1u, 340u);
        ((uint8_t*) _a11_arr->buf->slots)[_a11_arr->offset + 0u] = (uint8_t) (int32_t) (uint8_t) t6;
        l3 = (void*) _a11_arr;
        vader_struct_vader_core_bytecode$VirtualCall_t* _a12_obj = (vader_struct_vader_core_bytecode$VirtualCall_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$VirtualCall_t));
        vader_obj_header_init(_a12_obj, 887u);
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
    if (l1.tag == 1345u) {
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
            l5 = std_core$write_string_at(l3, l5, 1865u);
            l5 = std_core$write_string_at(l3, l5, l18);
            l5 = std_core$write_string_at(l3, l5, 1220u);
            l5 = std_core$write_string_at(l3, l5, l19);
            l5 = std_core$write_string_at(l3, l5, 1045u);
            t0 = l1.payload.obj;
            l13 = ((int64_t) (int32_t) ((vader_struct_vader_midir$InstrFieldGet_t*) t0)->f_target);
            l5 = std_core$write_int(l3, l5, l13);
            l5 = std_core$write_string_at(l3, l5, 84u);
            l5 = std_core$write_string_at(l3, l5, l20);
            l5 = std_core$write_string_at(l3, l5, 1277u);
            l5 = std_core$write_string_at(l3, l5, l21);
            l5 = std_core$write_string_at(l3, l5, 286u);
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
                vader_obj_header_init(_a14_obj, 867u);
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
                vader_obj_header_init(_a15_obj, 849u);
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
    } else if (l1.tag == 1346u) {
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
            vader_obj_header_init(_a17_obj, 869u);
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
        t4 = concat_7(1865u, l18, 1220u, l19, 1129u, l20, 301u);
        vader_host_std_abort$panic(t4);
        vader_unreachable("a no-return call returned");
    } else if (l1.tag == 1358u) {
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
                vader_obj_header_init(_a19_obj, 884u);
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
                    vader_obj_header_init(_a20_obj, 849u);
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
    } else if (l1.tag == 1359u) {
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
                vader_obj_header_init(_a22_obj, 885u);
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
        if (l1.tag == 1328u) {
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
                vader_obj_header_init(_a24_obj, 715u);
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
                    vader_obj_header_init(_a25_obj, 849u);
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
        if (l1.tag == 1332u) {
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
                vader_obj_header_init(_a27_obj, 722u);
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
        if (l1.tag == 1329u) {
            t0 = l1.payload.obj;
            l4 = ((vader_struct_vader_midir$InstrArrayLen_t*) t0)->f_target;
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir$InstrArrayLen_t*) t0)->f_span;
            vader_emit_bytecode$emit_first_get(l0, l2, l4, l3);
            vader_struct_vader_core_bytecode$ArrayLen_t* _a28_obj = (vader_struct_vader_core_bytecode$ArrayLen_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$ArrayLen_t));
            vader_obj_header_init(_a28_obj, 716u);
            l3 = (void*) _a28_obj;
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
        if (l1.tag == 1331u) {
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
            vader_obj_header_init(_a32_obj, 718u);
            _a32_obj->f_type_id = t3;
            _a32_obj->f_cache_slot = l4;
            l3 = (void*) _a32_obj;
            t0 = l1.payload.obj;
            l12 = ((vader_struct_vader_midir$InstrArrayPush_t*) t0)->f_span;
            vader_emit_bytecode$push_emit(l0, vader_ref_box(l3), l12);
            { vader_gc_top = gc_frame.prev; return; }
        }
        if (l1.tag == 1333u) {
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
            vader_obj_header_init(_a33_obj, 723u);
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
        if (l1.tag == 1354u) {
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
            vader_obj_header_init(_a34_obj, 868u);
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
        if (l1.tag == 1330u) {
            t0 = l1.payload.obj;
            l7 = ((vader_struct_vader_midir$InstrArrayNew_t*) t0)->f_type;
            l3 = ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_project;
            l4 = vader_emit_bytecode$intern_type(l7, l3);
            t0 = l1.payload.obj;
            t1 = vader_emit_bytecode$boxed_element(((vader_struct_vader_midir$InstrArrayNew_t*) t0)->f_type);
            vader_array_t* _a35_arr = vader_array_new(19u, 1u, 12u, 333u);
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
            vader_obj_header_init(_a37_obj, 717u);
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
        if (l1.tag == 1342u) {
            t0 = l1.payload.obj;
            l7 = ((vader_struct_vader_midir$InstrDataConst_t*) t0)->f_type;
            l3 = ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_project;
            l4 = vader_emit_bytecode$intern_type(l7, l3);
            t0 = l1.payload.obj;
            t3 = ((vader_struct_vader_midir$InstrDataConst_t*) t0)->f_pool_index;
            vader_struct_vader_core_bytecode$DataConst_t* _a38_obj = (vader_struct_vader_core_bytecode$DataConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$DataConst_t));
            vader_obj_header_init(_a38_obj, 767u);
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
        if (l1.tag == 1349u) {
            t0 = l1.payload.obj;
            t3 = ((vader_struct_vader_midir$InstrGlobalGet_t*) t0)->f_slot;
            vader_struct_vader_core_bytecode$GlobalGet_t* _a39_obj = (vader_struct_vader_core_bytecode$GlobalGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$GlobalGet_t));
            vader_obj_header_init(_a39_obj, 790u);
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
        if (l1.tag == 1350u) {
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
            vader_obj_header_init(_a40_obj, 791u);
            _a40_obj->f_index = t3;
            l3 = (void*) _a40_obj;
            t0 = l1.payload.obj;
            l12 = ((vader_struct_vader_midir$InstrGlobalSet_t*) t0)->f_span;
            vader_emit_bytecode$push_emit(l0, vader_ref_box(l3), l12);
            { vader_gc_top = gc_frame.prev; return; }
        }
        if (l1.tag == 1355u) {
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
            vader_obj_header_init(_a41_obj, 870u);
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
        if (l1.tag == 1356u) {
            t0 = l1.payload.obj;
            l7 = ((vader_struct_vader_midir$InstrTypeConst_t*) t0)->f_value_type;
            l3 = ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_project;
            t3 = vader_emit_bytecode$intern_type(l7, l3);
            vader_struct_vader_core_bytecode$TypeConst_t* _a42_obj = (vader_struct_vader_core_bytecode$TypeConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$TypeConst_t));
            vader_obj_header_init(_a42_obj, 871u);
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
        if (l1.tag == 1337u) {
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
                vader_obj_header_init(_a44_obj, 852u);
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
                    vader_obj_header_init(_a45_obj, 849u);
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
                        vader_obj_header_init(_a46_obj, 766u);
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
                        vader_obj_header_init(_a47_obj, 849u);
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
        if (l1.tag == 1339u) {
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
            vader_obj_header_init(_a48_obj, 868u);
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
        if (l1.tag == 1338u) {
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
                vader_obj_header_init(_a49_obj, 867u);
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
        if (l1.tag == 1340u) {
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
            vader_obj_header_init(_a50_obj, 869u);
            _a50_obj->f_type_id = l4;
            _a50_obj->f_field_index = INT32_C(0);
            _a50_obj->f_stack = false;
            l3 = (void*) _a50_obj;
            t0 = l1.payload.obj;
            l12 = ((vader_struct_vader_midir$InstrCellSet_t*) t0)->f_span;
            vader_emit_bytecode$push_emit(l0, vader_ref_box(l3), l12);
            { vader_gc_top = gc_frame.prev; return; }
        }
        if (l1.tag == 1352u) {
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
            if (!(l7.tag == 338u)) {
                t0 = l1.payload.obj;
                l18 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_midir$InstrMakeClosure_t*) t0)->f_fn_symbol)->f_name;
                l5 = vader_host_std_core$byte_len(l18);
                l14 = (void*) vader_buffer_new((size_t) (INT64_C(106) + l5));
                l5 = INT64_C(0);
                l5 = std_core$write_string_at(l14, l5, 1869u);
                l5 = std_core$write_string_at(l14, l5, l18);
                l5 = std_core$write_string_at(l14, l5, 287u);
                t0 = l1.payload.obj;
                t3 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_midir$InstrMakeClosure_t*) t0)->f_fn_symbol)->f_id;
                l13 = ((int64_t) (int32_t) t3);
                l5 = std_core$write_int(l14, l5, l13);
                l5 = std_core$write_string_at(l14, l5, 326u);
                t4 = std_core$finish_buffer(l14, l5);
                vader_host_std_abort$panic(t4);
                vader_unreachable("a no-return call returned");
            }
            t3 = ((int32_t) l7.payload.i);
            vader_struct_vader_core_bytecode$MakeClosure_t* _a51_obj = (vader_struct_vader_core_bytecode$MakeClosure_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$MakeClosure_t));
            vader_obj_header_init(_a51_obj, 846u);
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
        if (l1.tag == 1351u) {
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir$InstrIntrinsic_t*) t0)->f_args;
            vader_array_t* _a52_arr = vader_array_new(19u, 0u, 12u, 333u);
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
            t4 = concat_5(1867u, l18, 1129u, l19, 300u);
            vader_host_std_abort$panic(t4);
            vader_unreachable("a no-return call returned");
        } else {
            if (l1.tag == 1344u) {
                t0 = l1.payload.obj;
                l4 = ((vader_struct_vader_midir$InstrDeferPush_t*) t0)->f_value;
                t0 = l1.payload.obj;
                l3 = ((vader_struct_vader_midir$InstrDeferPush_t*) t0)->f_span;
                vader_emit_bytecode$emit_first_get(l0, l2, l4, l3);
                vader_struct_vader_core_bytecode$DeferPush_t* _a53_obj = (vader_struct_vader_core_bytecode$DeferPush_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$DeferPush_t));
                vader_obj_header_init(_a53_obj, 770u);
                l3 = (void*) _a53_obj;
                t0 = l1.payload.obj;
                l12 = ((vader_struct_vader_midir$InstrDeferPush_t*) t0)->f_span;
                vader_emit_bytecode$push_emit(l0, vader_ref_box(l3), l12);
                { vader_gc_top = gc_frame.prev; return; }
            }
            if (!(l1.tag == 1343u)) {
                vader_host_std_abort$panic(1866u);
                vader_unreachable("a no-return call returned");
            }
            t0 = l1.payload.obj;
            t3 = ((vader_struct_vader_midir$InstrDeferPopExec_t*) t0)->f_count;
            vader_struct_vader_core_bytecode$DeferPopExec_t* _a54_obj = (vader_struct_vader_core_bytecode$DeferPopExec_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$DeferPopExec_t));
            vader_obj_header_init(_a54_obj, 769u);
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
    vader_struct_vader_core_bytecode$I32Const_t* _a0_obj = (vader_struct_vader_core_bytecode$I32Const_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$I32Const_t));
    vader_obj_header_init(_a0_obj, 797u);
    _a0_obj->f_value = l4;
    l5 = (void*) _a0_obj;
    vader_emit_bytecode$push_emit(l0, vader_ref_box(l5), l2);
    vader_struct_vader_core_bytecode$I32BitAnd_t* _a1_obj = (vader_struct_vader_core_bytecode$I32BitAnd_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$I32BitAnd_t));
    vader_obj_header_init(_a1_obj, 793u);
    l5 = (void*) _a1_obj;
    vader_emit_bytecode$push_emit(l0, vader_ref_box(l5), l2);
    t0 = vader_core_bytecode$is_unsigned_val(l1);
    if (t0) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l3) {
        l4 = INT32_C(128);
    } else {
        l4 = INT32_C(32768);
    }
    vader_struct_vader_core_bytecode$I32Const_t* _a2_obj = (vader_struct_vader_core_bytecode$I32Const_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$I32Const_t));
    vader_obj_header_init(_a2_obj, 797u);
    _a2_obj->f_value = l4;
    l5 = (void*) _a2_obj;
    vader_emit_bytecode$push_emit(l0, vader_ref_box(l5), l2);
    vader_struct_vader_core_bytecode$I32BitXor_t* _a3_obj = (vader_struct_vader_core_bytecode$I32BitXor_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$I32BitXor_t));
    vader_obj_header_init(_a3_obj, 796u);
    l5 = (void*) _a3_obj;
    vader_emit_bytecode$push_emit(l0, vader_ref_box(l5), l2);
    vader_struct_vader_core_bytecode$I32Const_t* _a4_obj = (vader_struct_vader_core_bytecode$I32Const_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$I32Const_t));
    vader_obj_header_init(_a4_obj, 797u);
    _a4_obj->f_value = l4;
    l5 = (void*) _a4_obj;
    vader_emit_bytecode$push_emit(l0, vader_ref_box(l5), l2);
    vader_struct_vader_core_bytecode$I32Sub_t* _a5_obj = (vader_struct_vader_core_bytecode$I32Sub_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$I32Sub_t));
    vader_obj_header_init(_a5_obj, 811u);
    l5 = (void*) _a5_obj;
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
        vader_obj_header_init(_a1_obj, 852u);
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
    vader_box_t* gc_roots[2] = { &l3, &t1 };
    void** gc_raw_roots[4] = { &l0, &l2, &l8, &l9 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
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
                vader_obj_header_init(_a2_obj, 854u);
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
    vader_struct_vader_core_bytecode$Return_t* _a4_obj = (vader_struct_vader_core_bytecode$Return_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$Return_t));
    vader_obj_header_init(_a4_obj, 853u);
    l8 = (void*) _a4_obj;
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
    vader_obj_header_init(_a1_obj, 843u);
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
    if (l7.tag == 1372u) {
        l5 = l7.payload.obj;
        vader_emit_bytecode$emit_return(l0, l2, l5);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l7.tag == 1373u) {
        t0 = l7.payload.obj;
        t1 = ((vader_struct_vader_midir$TermUnreachable_t*) t0)->f_reason;
        vader_struct_vader_core_bytecode$Unreachable_t* _a1_obj = (vader_struct_vader_core_bytecode$Unreachable_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$Unreachable_t));
        vader_obj_header_init(_a1_obj, 886u);
        _a1_obj->f_reason = t1;
        l5 = (void*) _a1_obj;
        t0 = l7.payload.obj;
        l8 = ((vader_struct_vader_midir$TermUnreachable_t*) t0)->f_span;
        vader_emit_bytecode$push_emit(l0, vader_ref_box(l5), l8);
    } else if (l7.tag == 1370u) {
        t0 = l7.payload.obj;
        l6 = ((vader_struct_vader_midir$TermBranch_t*) t0)->f_target;
        t0 = l7.payload.obj;
        l5 = ((vader_struct_vader_midir$TermBranch_t*) t0)->f_span;
        vader_emit_bytecode$emit_branch(l0, l1, l2, l6, l3, l5);
    } else {
        if (!(l7.tag == 1371u)) {
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
    return (l0.tag == 1372u || l0.tag == 1373u);
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
    vader_array_t* _a0_arr = vader_array_new(19u, 1u, 12u, 333u);
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
                            vader_obj_header_init(_a3_obj, 928u);
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
                            vader_obj_header_init(_a4_obj, 928u);
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
    vader_array_t* _a0_arr = vader_array_new(90u, 0u, 13u, 928u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(21u, 0u, 0u, 335u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(22u, 0u, 7u, 338u);
    l3 = (void*) _a2_arr;
    l4 = INT64_C(0);
    l5 = ((vader_array_t*) l0)->length;
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        l7 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l6);
        if (l7.tag == 746u) {
            l8 = ((int32_t) (int64_t) l6);
            vader_emit_bytecode$push_scope(l2, l3, l4, 1633u, l8);
            l4 = vader_chk_add(i64, l4, INT64_C(1));
        } else if (l7.tag == 845u) {
            l9 = ((int32_t) (int64_t) l6);
            vader_emit_bytecode$push_scope(l2, l3, l4, 2295u, l9);
            l4 = vader_chk_add(i64, l4, INT64_C(1));
        } else if (l7.tag == 832u) {
            l10 = ((int32_t) (int64_t) l6);
            vader_emit_bytecode$push_scope(l2, l3, l4, 2134u, l10);
            l4 = vader_chk_add(i64, l4, INT64_C(1));
        } else if (l7.tag == 773u) {
            if ((l4 > INT64_C(0))) {
                l4 = vader_chk_sub(i64, l4, INT64_C(1));
                vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
                VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l4)
                t0 = vader_array_box_slots(_a4_slotarr->buf)[_a4_slotarr->offset + (size_t) l4];
                t1 = t0.payload.s;
                if (t1 == 2295u) {
                    vader_array_t* _a5_slotarr = ((vader_array_t*) l3);
                    VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l4)
                    l11 = ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l4];
                    l12 = ((int32_t) (int64_t) l6);
                    vader_struct_vader_emit_bytecode$SlotRange_t* _a6_obj = (vader_struct_vader_emit_bytecode$SlotRange_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_bytecode$SlotRange_t));
                    vader_obj_header_init(_a6_obj, 928u);
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
    if (l3.tag == 738u) {
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
                return vader_box_i64(339u, l4);
            }
            l4 = (l4 + INT64_C(1));
        }
    }
    return vader_box_obj(0u, NULL);
}

static vader_box_t vader_emit_bytecode$first_stack_operand(vader_box_t l0) {
    void* t0;
    int64_t t1;
    int32_t t2;
    if (l0.tag == 1341u) {
        return vader_box_obj(0u, NULL);
    }
    if (l0.tag == 1348u) {
        return vader_box_obj(0u, NULL);
    }
    if (l0.tag == 1347u) {
        return vader_box_obj(0u, NULL);
    }
    if (l0.tag == 1342u) {
        return vader_box_obj(0u, NULL);
    }
    if (l0.tag == 1349u) {
        return vader_box_obj(0u, NULL);
    }
    if (l0.tag == 1356u) {
        return vader_box_obj(0u, NULL);
    }
    if (l0.tag == 1353u) {
        t0 = l0.payload.obj;
        return vader_box_i32(338u, ((vader_struct_vader_midir$InstrMove_t*) t0)->f_src);
    }
    if (l0.tag == 1334u) {
        t0 = l0.payload.obj;
        return vader_box_i32(338u, ((vader_struct_vader_midir$InstrBinOp_t*) t0)->f_lhs);
    }
    if (l0.tag == 1357u) {
        t0 = l0.payload.obj;
        return vader_box_i32(338u, ((vader_struct_vader_midir$InstrUnOp_t*) t0)->f_operand);
    }
    if (l0.tag == 1335u) {
        t0 = l0.payload.obj;
        t1 = ((vader_array_t*) ((vader_struct_vader_midir$InstrCall_t*) t0)->f_args)->length;
        if (!((t1 > INT64_C(0)))) {
            return vader_box_obj(0u, NULL);
        }
        t0 = l0.payload.obj;
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_midir$InstrCall_t*) t0)->f_args);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
        t2 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) INT32_C(0)];
        return vader_box_i32(338u, t2);
    }
    if (l0.tag == 1336u) {
        t0 = l0.payload.obj;
        t1 = ((vader_array_t*) ((vader_struct_vader_midir$InstrCallIndirect_t*) t0)->f_args)->length;
        if (!((t1 > INT64_C(0)))) {
            t0 = l0.payload.obj;
            return vader_box_i32(338u, ((vader_struct_vader_midir$InstrCallIndirect_t*) t0)->f_callee);
        }
        t0 = l0.payload.obj;
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_midir$InstrCallIndirect_t*) t0)->f_args);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, INT32_C(0))
        t2 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) INT32_C(0)];
        return vader_box_i32(338u, t2);
    }
    if (l0.tag == 1360u) {
        t0 = l0.payload.obj;
        t1 = ((vader_array_t*) ((vader_struct_vader_midir$InstrVirtualCall_t*) t0)->f_args)->length;
        if (!((t1 > INT64_C(0)))) {
            t0 = l0.payload.obj;
            return vader_box_i32(338u, ((vader_struct_vader_midir$InstrVirtualCall_t*) t0)->f_receiver);
        }
        t0 = l0.payload.obj;
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_midir$InstrVirtualCall_t*) t0)->f_args);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, INT32_C(0))
        t2 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) INT32_C(0)];
        return vader_box_i32(338u, t2);
    }
    if (l0.tag == 1345u) {
        t0 = l0.payload.obj;
        return vader_box_i32(338u, ((vader_struct_vader_midir$InstrFieldGet_t*) t0)->f_target);
    }
    if (l0.tag == 1346u) {
        t0 = l0.payload.obj;
        return vader_box_i32(338u, ((vader_struct_vader_midir$InstrFieldSet_t*) t0)->f_target);
    }
    if (l0.tag == 1358u) {
        t0 = l0.payload.obj;
        return vader_box_i32(338u, ((vader_struct_vader_midir$InstrUnionFieldGet_t*) t0)->f_target);
    }
    if (l0.tag == 1359u) {
        t0 = l0.payload.obj;
        return vader_box_i32(338u, ((vader_struct_vader_midir$InstrUnionFieldSet_t*) t0)->f_target);
    }
    if (l0.tag == 1328u) {
        t0 = l0.payload.obj;
        return vader_box_i32(338u, ((vader_struct_vader_midir$InstrArrayGet_t*) t0)->f_target);
    }
    if (l0.tag == 1332u) {
        t0 = l0.payload.obj;
        return vader_box_i32(338u, ((vader_struct_vader_midir$InstrArraySet_t*) t0)->f_target);
    }
    if (l0.tag == 1329u) {
        t0 = l0.payload.obj;
        return vader_box_i32(338u, ((vader_struct_vader_midir$InstrArrayLen_t*) t0)->f_target);
    }
    if (l0.tag == 1331u) {
        t0 = l0.payload.obj;
        return vader_box_i32(338u, ((vader_struct_vader_midir$InstrArrayPush_t*) t0)->f_target);
    }
    if (l0.tag == 1333u) {
        t0 = l0.payload.obj;
        return vader_box_i32(338u, ((vader_struct_vader_midir$InstrArraySlice_t*) t0)->f_target);
    }
    if (l0.tag == 1354u) {
        t0 = l0.payload.obj;
        t1 = ((vader_array_t*) ((vader_struct_vader_midir$InstrStructNew_t*) t0)->f_fields)->length;
        if (!((t1 > INT64_C(0)))) {
            return vader_box_obj(0u, NULL);
        }
        t0 = l0.payload.obj;
        vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_midir$InstrStructNew_t*) t0)->f_fields);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, INT32_C(0))
        t2 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) INT32_C(0)];
        return vader_box_i32(338u, t2);
    }
    if (l0.tag == 1330u) {
        t0 = l0.payload.obj;
        t1 = ((vader_array_t*) ((vader_struct_vader_midir$InstrArrayNew_t*) t0)->f_elements)->length;
        if (!((t1 > INT64_C(0)))) {
            return vader_box_obj(0u, NULL);
        }
        t0 = l0.payload.obj;
        vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_vader_midir$InstrArrayNew_t*) t0)->f_elements);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, INT32_C(0))
        t2 = ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) INT32_C(0)];
        return vader_box_i32(338u, t2);
    }
    if (l0.tag == 1355u) {
        t0 = l0.payload.obj;
        return vader_box_i32(338u, ((vader_struct_vader_midir$InstrTypeCheck_t*) t0)->f_value);
    }
    if (l0.tag == 1337u) {
        t0 = l0.payload.obj;
        return vader_box_i32(338u, ((vader_struct_vader_midir$InstrCast_t*) t0)->f_value);
    }
    if (l0.tag == 1339u) {
        t0 = l0.payload.obj;
        return vader_box_i32(338u, ((vader_struct_vader_midir$InstrCellNew_t*) t0)->f_value);
    }
    if (l0.tag == 1338u) {
        t0 = l0.payload.obj;
        return vader_box_i32(338u, ((vader_struct_vader_midir$InstrCellGet_t*) t0)->f_cell);
    }
    if (l0.tag == 1340u) {
        t0 = l0.payload.obj;
        return vader_box_i32(338u, ((vader_struct_vader_midir$InstrCellSet_t*) t0)->f_cell);
    }
    if (l0.tag == 1350u) {
        t0 = l0.payload.obj;
        return vader_box_i32(338u, ((vader_struct_vader_midir$InstrGlobalSet_t*) t0)->f_value);
    }
    if (l0.tag == 1352u) {
        t0 = l0.payload.obj;
        return vader_box_i32(338u, ((vader_struct_vader_midir$InstrMakeClosure_t*) t0)->f_env);
    }
    if (l0.tag == 1351u) {
        t0 = l0.payload.obj;
        t1 = ((vader_array_t*) ((vader_struct_vader_midir$InstrIntrinsic_t*) t0)->f_args)->length;
        if (!((t1 > INT64_C(0)))) {
            return vader_box_obj(0u, NULL);
        }
        t0 = l0.payload.obj;
        vader_array_t* _a5_slotarr = ((vader_array_t*) ((vader_struct_vader_midir$InstrIntrinsic_t*) t0)->f_args);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, INT32_C(0))
        t2 = ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) INT32_C(0)];
        return vader_box_i32(338u, t2);
    }
    if (l0.tag == 1344u) {
        t0 = l0.payload.obj;
        return vader_box_i32(338u, ((vader_struct_vader_midir$InstrDeferPush_t*) t0)->f_value);
    }
    if (!(l0.tag == 1343u)) {
        vader_unreachable("non-exhaustive match (T3013 should have caught this)");
    }
    return vader_box_obj(0u, NULL);
}

static vader_box_t vader_emit_bytecode$first_terminator_operand(vader_box_t l0) {
    void* t0;
    vader_box_t t1;
    if (l0.tag == 1370u) {
        return vader_box_obj(0u, NULL);
    }
    if (l0.tag == 1373u) {
        return vader_box_obj(0u, NULL);
    }
    if (l0.tag == 1371u) {
        t0 = l0.payload.obj;
        return vader_box_i32(338u, ((vader_struct_vader_midir$TermCondBranch_t*) t0)->f_cond);
    }
    if (!(l0.tag == 1372u)) {
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
    if (l5.tag == 842u) {
        l4 = vader_chk_add(i64, l1, INT64_C(1));
        vader_array_t* _a2_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        l6 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
        if (l6.tag == 844u) {
            t3 = l6.payload.obj;
            l7 = ((vader_struct_vader_core_bytecode$LocalTee_t*) t3)->f_slot;
            t3 = l5.payload.obj;
            l8 = ((vader_struct_vader_core_bytecode$LocalGet_t*) t3)->f_slot;
            return l7 == l8;
        }
        if (l6.tag == 843u) {
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
    if (l16.tag == 1371u) {
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
        vader_obj_header_init(_a1_obj, 761u);
        _a1_obj->f_index = l1;
        t2 = (void*) _a1_obj;
        l4 = vader_ref_box(t2);
        l5 = ((vader_struct_vader_core_bytecode$BcImport_t*) l2)->f_signature;
        vader_struct_vader_emit_bytecode$DirectCallTarget_t* _a2_obj = (vader_struct_vader_emit_bytecode$DirectCallTarget_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_bytecode$DirectCallTarget_t));
        vader_obj_header_init(_a2_obj, 921u);
        _a2_obj->f_op = l4;
        _a2_obj->f_signature = l5;
        t2 = (void*) _a2_obj;
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = l3;
    l5 = ((vader_struct_vader_core_bytecode$BcImport_t*) l2)->f_signature;
    vader_struct_vader_emit_bytecode$DirectCallTarget_t* _a3_obj = (vader_struct_vader_emit_bytecode$DirectCallTarget_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_bytecode$DirectCallTarget_t));
    vader_obj_header_init(_a3_obj, 921u);
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
    l4 = concat_3(260u, l3, 526u);
    t0 = ((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l1)->f_types)->length;
    l5 = ((int32_t) (int64_t) t0);
    l6 = std_collections$get_or_put__string__i32(((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l1)->f_type_key, l4, l5);
    if (!(l6 != l5)) {
        vader_struct_vader_core_bytecode$BcField_t* _a0_obj = (vader_struct_vader_core_bytecode$BcField_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcField_t));
        vader_obj_header_init(_a0_obj, 727u);
        _a0_obj->f_name = 2990u;
        _a0_obj->f_type_index = l2;
        l7 = (void*) _a0_obj;
        vader_array_t* _a1_arr = vader_array_new(59u, 0u, 13u, 727u);
        l8 = (void*) _a1_arr;
        vader_array_push_ref((vader_array_t*) l8, l7);
        l7 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l1)->f_types;
        l3 = vader_midir_select$cell_shape_name(l3);
        t1 = concat_2(261u, l3);
        vader_struct_vader_core_bytecode$BcStruct_t* _a2_obj = (vader_struct_vader_core_bytecode$BcStruct_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcStruct_t));
        vader_obj_header_init(_a2_obj, 738u);
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

static void vader_emit_bytecode$intern_data_value_strings(vader_box_t l0, void* l1) {
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
    if (l0.tag == 742u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_core_bytecode$BcValStr_t*) t0)->f_value;
        vader_emit_bytecode$intern_string(t1, l1);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 743u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_core_bytecode$BcValStruct_t*) t0)->f_fields;
        l3 = ((vader_array_t*) l2)->length;
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            t2 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
            vader_emit_bytecode$intern_data_value_strings(t2, l1);
            l4 = (l4 + INT64_C(1));
        }
    } else if (l0.tag == 740u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_core_bytecode$BcValArray_t*) t0)->f_elements;
        l3 = ((vader_array_t*) l2)->length;
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            t2 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
            vader_emit_bytecode$intern_data_value_strings(t2, l1);
            l4 = (l4 + INT64_C(1));
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
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
        vader_array_push_scalar((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l1)->f_strings, vader_box_string(335u, l0));
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
    if (l3.tag == 338u) {
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
        t3 = concat_3(1872u, l10, 1052u);
        vader_host_std_abort$panic(t3);
        vader_unreachable("a no-return call returned");
    } else {
        vader_struct_vader_core_bytecode$BcRef_t* _a1_obj = (vader_struct_vader_core_bytecode$BcRef_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcRef_t));
        vader_obj_header_init(_a1_obj, 734u);
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
    return (t0.tag == 734u || t0.tag == 739u);
}

static bool vader_emit_bytecode$is_union_slot(vader_box_t l0) {
    bool l1;
    void* t0;
    if (l0.tag == 918u) {
        return true;
    }
    if (l0.tag == 897u) {
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
        return (t1.tag == 753u || t1.tag == 853u || t1.tag == 854u);
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
    if (!(l5.tag == 1371u)) {
        { vader_gc_top = gc_frame.prev; return INT32_C(-1); }
    }
    t0 = l5.payload.obj;
    l4 = ((vader_struct_vader_midir$TermCondBranch_t*) t0)->f_else_block;
    t0 = l5.payload.obj;
    l6 = ((vader_struct_vader_midir$TermCondBranch_t*) t0)->f_then_block;
    vader_array_t* _a1_arr = vader_array_new(22u, 2u, 7u, 338u);
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
    if (l0.tag == 908u) {
        return true;
    }
    if (l0.tag == 907u) {
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
    vader_array_t* _a0_arr = vader_array_new(249u, 0u, 13u, 1701u);
    l0 = (void*) _a0_arr;
    vader_struct_vader_core_bytecode$BcScalar_t* _a1_obj = (vader_struct_vader_core_bytecode$BcScalar_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcScalar_t));
    vader_obj_header_init(_a1_obj, 735u);
    _a1_obj->f_val = (uint8_t) 13;
    l1 = (void*) _a1_obj;
    vader_array_push_ref((vader_array_t*) l0, l1);
    vader_array_t* _a2_arr = vader_array_new(21u, 0u, 0u, 335u);
    l1 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(22u, 0u, 7u, 338u);
    l2 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_new(22u, 0u, 7u, 338u);
    l3 = (void*) _a4_arr;
    vader_struct_std_collections$MutableMap__string__i32_t* _a5_obj = (vader_struct_std_collections$MutableMap__string__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__string__i32_t));
    vader_obj_header_init(_a5_obj, 540u);
    _a5_obj->f_ekeys = l1;
    _a5_obj->f_evals = l2;
    _a5_obj->f_index = l3;
    _a5_obj->f_mask = INT64_C(0);
    _a5_obj->f_grow_at = INT64_C(0);
    _a5_obj->f_size = INT64_C(0);
    _a5_obj->f_tombs = INT64_C(0);
    l1 = (void*) _a5_obj;
    std_collections$MutableMap$std_core$IndexSet$set_at__string__i32(l1, 2416u, INT32_C(0));
    vader_array_t* _a6_arr = vader_array_new(27u, 0u, 4u, 343u);
    l2 = (void*) _a6_arr;
    vader_array_t* _a7_arr = vader_array_new(22u, 0u, 7u, 338u);
    l3 = (void*) _a7_arr;
    vader_array_t* _a8_arr = vader_array_new(22u, 0u, 7u, 338u);
    l4 = (void*) _a8_arr;
    vader_struct_std_collections$MutableMap__u64__i32_t* _a9_obj = (vader_struct_std_collections$MutableMap__u64__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__u64__i32_t));
    vader_obj_header_init(_a9_obj, 591u);
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
    vader_array_t* _a12_arr = vader_array_new(252u, 1u, 13u, 1776u);
    ((void**) _a12_arr->buf->slots)[_a12_arr->offset + 0u] = t0;
    l3 = (void*) _a12_arr;
    vader_array_t* _a13_arr = vader_array_new(61u, 0u, 13u, 730u);
    l4 = (void*) _a13_arr;
    vader_array_t* _a14_arr = vader_array_new(21u, 0u, 0u, 335u);
    l6 = (void*) _a14_arr;
    vader_array_t* _a15_arr = vader_array_new(21u, 0u, 0u, 335u);
    l7 = (void*) _a15_arr;
    vader_array_t* _a16_arr = vader_array_new(22u, 0u, 7u, 338u);
    l8 = (void*) _a16_arr;
    vader_array_t* _a17_arr = vader_array_new(22u, 0u, 7u, 338u);
    l9 = (void*) _a17_arr;
    vader_struct_std_collections$MutableMap__string__i32_t* _a18_obj = (vader_struct_std_collections$MutableMap__string__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__string__i32_t));
    vader_obj_header_init(_a18_obj, 540u);
    _a18_obj->f_ekeys = l7;
    _a18_obj->f_evals = l8;
    _a18_obj->f_index = l9;
    _a18_obj->f_mask = INT64_C(0);
    _a18_obj->f_grow_at = INT64_C(0);
    _a18_obj->f_size = INT64_C(0);
    _a18_obj->f_tombs = INT64_C(0);
    l7 = (void*) _a18_obj;
    vader_array_t* _a19_arr = vader_array_new(60u, 0u, 13u, 729u);
    l8 = (void*) _a19_arr;
    vader_array_t* _a20_arr = vader_array_new(22u, 0u, 7u, 338u);
    l9 = (void*) _a20_arr;
    vader_array_t* _a21_arr = vader_array_new(22u, 0u, 7u, 338u);
    l10 = (void*) _a21_arr;
    vader_array_t* _a22_arr = vader_array_new(22u, 0u, 7u, 338u);
    l11 = (void*) _a22_arr;
    vader_struct_std_collections$MutableMap__i32__i32_t* _a23_obj = (vader_struct_std_collections$MutableMap__i32__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i32__i32_t));
    vader_obj_header_init(_a23_obj, 463u);
    _a23_obj->f_ekeys = l9;
    _a23_obj->f_evals = l10;
    _a23_obj->f_index = l11;
    _a23_obj->f_mask = INT64_C(0);
    _a23_obj->f_grow_at = INT64_C(0);
    _a23_obj->f_size = INT64_C(0);
    _a23_obj->f_tombs = INT64_C(0);
    l9 = (void*) _a23_obj;
    vader_array_t* _a24_arr = vader_array_new(21u, 0u, 0u, 335u);
    l10 = (void*) _a24_arr;
    vader_array_t* _a25_arr = vader_array_new(22u, 0u, 7u, 338u);
    l11 = (void*) _a25_arr;
    vader_array_t* _a26_arr = vader_array_new(22u, 0u, 7u, 338u);
    l12 = (void*) _a26_arr;
    vader_struct_std_collections$MutableMap__string__i32_t* _a27_obj = (vader_struct_std_collections$MutableMap__string__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__string__i32_t));
    vader_obj_header_init(_a27_obj, 540u);
    _a27_obj->f_ekeys = l10;
    _a27_obj->f_evals = l11;
    _a27_obj->f_index = l12;
    _a27_obj->f_mask = INT64_C(0);
    _a27_obj->f_grow_at = INT64_C(0);
    _a27_obj->f_size = INT64_C(0);
    _a27_obj->f_tombs = INT64_C(0);
    l10 = (void*) _a27_obj;
    vader_array_t* _a28_arr = vader_array_new(62u, 0u, 13u, 731u);
    l11 = (void*) _a28_arr;
    vader_array_t* _a29_arr = vader_array_new(22u, 0u, 7u, 338u);
    l12 = (void*) _a29_arr;
    vader_array_t* _a30_arr = vader_array_new(22u, 0u, 7u, 338u);
    l13 = (void*) _a30_arr;
    vader_array_t* _a31_arr = vader_array_new(22u, 0u, 7u, 338u);
    l14 = (void*) _a31_arr;
    vader_struct_std_collections$MutableMap__i32__i32_t* _a32_obj = (vader_struct_std_collections$MutableMap__i32__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i32__i32_t));
    vader_obj_header_init(_a32_obj, 463u);
    _a32_obj->f_ekeys = l12;
    _a32_obj->f_evals = l13;
    _a32_obj->f_index = l14;
    _a32_obj->f_mask = INT64_C(0);
    _a32_obj->f_grow_at = INT64_C(0);
    _a32_obj->f_size = INT64_C(0);
    _a32_obj->f_tombs = INT64_C(0);
    l12 = (void*) _a32_obj;
    vader_array_t* _a33_arr = vader_array_new(21u, 0u, 0u, 335u);
    l13 = (void*) _a33_arr;
    vader_array_t* _a34_arr = vader_array_new(22u, 0u, 7u, 338u);
    l14 = (void*) _a34_arr;
    vader_array_t* _a35_arr = vader_array_new(22u, 0u, 7u, 338u);
    l15 = (void*) _a35_arr;
    vader_struct_std_collections$MutableMap__string__i32_t* _a36_obj = (vader_struct_std_collections$MutableMap__string__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__string__i32_t));
    vader_obj_header_init(_a36_obj, 540u);
    _a36_obj->f_ekeys = l13;
    _a36_obj->f_evals = l14;
    _a36_obj->f_index = l15;
    _a36_obj->f_mask = INT64_C(0);
    _a36_obj->f_grow_at = INT64_C(0);
    _a36_obj->f_size = INT64_C(0);
    _a36_obj->f_tombs = INT64_C(0);
    l13 = (void*) _a36_obj;
    vader_array_t* _a37_arr = vader_array_new(58u, 0u, 13u, 726u);
    l14 = (void*) _a37_arr;
    vader_array_t* _a38_arr = vader_array_new(22u, 0u, 7u, 338u);
    l15 = (void*) _a38_arr;
    vader_array_t* _a39_arr = vader_array_new(22u, 0u, 7u, 338u);
    l16 = (void*) _a39_arr;
    vader_array_t* _a40_arr = vader_array_new(28u, 0u, 0u, 346u);
    l17 = (void*) _a40_arr;
    vader_array_t* _a41_arr = vader_array_new(22u, 0u, 7u, 338u);
    l18 = (void*) _a41_arr;
    vader_struct_std_collections$MutableMap__i32__Any___t* _a42_obj = (vader_struct_std_collections$MutableMap__i32__Any___t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i32__Any___t));
    vader_obj_header_init(_a42_obj, 460u);
    _a42_obj->f_ekeys = l16;
    _a42_obj->f_evals = l17;
    _a42_obj->f_index = l18;
    _a42_obj->f_mask = INT64_C(0);
    _a42_obj->f_grow_at = INT64_C(0);
    _a42_obj->f_size = INT64_C(0);
    _a42_obj->f_tombs = INT64_C(0);
    l16 = (void*) _a42_obj;
    vader_struct_vader_emit_bytecode$EmitterCtx_t* _a43_obj = (vader_struct_vader_emit_bytecode$EmitterCtx_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_bytecode$EmitterCtx_t));
    vader_obj_header_init(_a43_obj, 923u);
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
    t0 = concat_7(1864u, l1, 1220u, l3, 1129u, l4, 286u);
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
    t0 = ((vader_array_t*) l1)->length;
    if ((t0 > INT64_C(0))) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        t3 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) INT32_C(0)];
        { int32_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { int32_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
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
    vader_array_t* _a0_arr = vader_array_new(21u, 0u, 0u, 335u);
    l2 = (void*) _a0_arr;
    if (!(l1.tag == 650u)) {
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
        vader_array_push_scalar((vader_array_t*) l2, vader_box_string(335u, l7));
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

static void vader_emit_bytecode$pin_baked_struct_types(void* l0, void* l1) {
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
    l3 = l0;
    l5 = ((vader_array_t*) l3)->length;
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a5_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        l7 = vader_array_ref_load_box(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l6);
        if (l7.tag == 724u) {
            t0 = l7.payload.obj;
            l4 = ((vader_struct_vader_core_bytecode$BcAggregateData_t*) t0)->f_elements;
            l8 = ((vader_array_t*) l4)->length;
            l9 = INT64_C(0);
            while ((l9 < l8)) {
                vader_array_t* _a6_slotarr = ((vader_array_t*) l4);
                VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
                t1 = vader_array_ref_load_box(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l9);
                vader_emit_bytecode$collect_baked_symbols(t1, l2);
                l9 = (l9 + INT64_C(1));
            }
        }
        l6 = (l6 + INT64_C(1));
    }
    l3 = ((vader_struct_std_collections$MutableMap__i32__bool_t*) ((vader_struct_std_collections$MutableSet__i32_t*) l2)->f_inner)->f_ekeys;
    l5 = INT64_C(0);
    l6 = ((vader_struct_std_collections$MutableMap__i32__bool_t*) ((vader_struct_std_collections$MutableSet__i32_t*) l2)->f_inner)->f_size;
    while ((l5 < l6)) {
        vader_array_t* _a7_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l5)
        l10 = ((int32_t*) _a7_slotarr->buf->slots)[_a7_slotarr->offset + (size_t) l5];
        l11 = vader_core_bytecode$struct_symbol_type_index(((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l1)->f_types, l10);
        if ((l11 >= INT32_C(0))) {
            vader_array_push_i32((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l1)->f_pinned_types, l11);
        }
        l5 = (l5 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void* vader_emit_bytecode$propagate_const_single_use(void* l0) {
    int64_t l1, l2, l4, l10, l12, l17;
    void* l3 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
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
    void** gc_raw_roots[12] = { &l0, &l3, &l5, &l6, &l7, &l8, &l9, &l20, &l21, &l22, &l23, &t0 };
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
    vader_array_t* _a0_arr = vader_array_new(22u, 0u, 7u, 338u);
    l3 = (void*) _a0_arr;
    if ((INT64_C(0) < l2)) {
        l4 = l2;
    } else {
        l4 = INT64_C(0);
    }
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l3, (int64_t) l4);
    l3 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(22u, 0u, 7u, 338u);
    l5 = (void*) _a2_arr;
    if ((INT64_C(0) < l2)) {
        l4 = l2;
    } else {
        l4 = INT64_C(0);
    }
    vader_array_t* _a3_arr = vader_array_repeat((vader_array_t*) l5, (int64_t) l4);
    l5 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_new(22u, 0u, 7u, 338u);
    l6 = (void*) _a4_arr;
    if ((INT64_C(0) < l2)) {
        l4 = l2;
    } else {
        l4 = INT64_C(0);
    }
    vader_array_t* _a5_arr = vader_array_repeat((vader_array_t*) l6, (int64_t) l4);
    l6 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(22u, 0u, 7u, 338u);
    l7 = (void*) _a6_arr;
    if ((INT64_C(0) < l2)) {
        l4 = l2;
    } else {
        l4 = INT64_C(0);
    }
    vader_array_t* _a7_arr = vader_array_repeat((vader_array_t*) l7, (int64_t) l4);
    l7 = (void*) _a7_arr;
    vader_array_t* _a8_arr = vader_array_new(22u, 0u, 7u, 338u);
    l8 = (void*) _a8_arr;
    if ((INT64_C(0) < l2)) {
        l4 = l2;
    } else {
        l4 = INT64_C(0);
    }
    vader_array_t* _a9_arr = vader_array_repeat((vader_array_t*) l8, (int64_t) l4);
    l8 = (void*) _a9_arr;
    l4 = INT64_C(0);
    while ((l4 < l2)) {
        vader_array_push_i32((vader_array_t*) l3, INT32_C(0));
        vader_array_push_i32((vader_array_t*) l5, INT32_C(0));
        vader_array_push_i32((vader_array_t*) l6, INT32_C(0));
        vader_array_push_i32((vader_array_t*) l7, INT32_C(-1));
        vader_array_push_i32((vader_array_t*) l8, INT32_C(-1));
        l4 = (l4 + INT64_C(1));
    }
    l9 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_body;
    l4 = ((vader_array_t*) l9)->length;
    l10 = INT64_C(0);
    while ((l10 < l4)) {
        vader_array_t* _a10_slotarr = ((vader_array_t*) l9);
        VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
        l11 = vader_array_ref_load_box(_a10_slotarr->buf, _a10_slotarr->offset + (size_t) l10);
        if (l11.tag == 843u) {
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
            vader_array_t* _a12_slotarr = ((vader_array_t*) l7);
            VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a12_slotarr, l12)
            ((int32_t*) _a12_slotarr->buf->slots)[_a12_slotarr->offset + (size_t) l12] = (int32_t) l14;
        }
        if (l11.tag == 844u) {
            t0 = l11.payload.obj;
            l15 = ((vader_struct_vader_core_bytecode$LocalTee_t*) t0)->f_slot;
            vader_array_t* _a13_slotarr = ((vader_array_t*) l6);
            VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a13_slotarr, l15)
            t1 = ((int32_t*) _a13_slotarr->buf->slots)[_a13_slotarr->offset + (size_t) l15];
            l16 = vader_chk_add(i32, t1, INT32_C(1));
            VADER_ARRAY_CHECK_INDEX(_a13_slotarr, l15)
            ((int32_t*) _a13_slotarr->buf->slots)[_a13_slotarr->offset + (size_t) l15] = (int32_t) l16;
        }
        if (l11.tag == 842u) {
            t0 = l11.payload.obj;
            t1 = ((vader_struct_vader_core_bytecode$LocalGet_t*) t0)->f_slot;
            l17 = ((int64_t) (int32_t) t1);
            vader_array_t* _a14_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a14_slotarr, l17)
            t1 = ((int32_t*) _a14_slotarr->buf->slots)[_a14_slotarr->offset + (size_t) l17];
            l18 = vader_chk_add(i32, t1, INT32_C(1));
            VADER_ARRAY_CHECK_INDEX(_a14_slotarr, l17)
            ((int32_t*) _a14_slotarr->buf->slots)[_a14_slotarr->offset + (size_t) l17] = (int32_t) l18;
            l19 = ((int32_t) (int64_t) l10);
            vader_array_t* _a15_slotarr = ((vader_array_t*) l8);
            VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a15_slotarr, l17)
            ((int32_t*) _a15_slotarr->buf->slots)[_a15_slotarr->offset + (size_t) l17] = (int32_t) l19;
        }
        l10 = (l10 + INT64_C(1));
    }
    vader_array_t* _a16_arr = vader_array_new(22u, 0u, 7u, 338u);
    l20 = (void*) _a16_arr;
    vader_array_t* _a17_arr = vader_array_new(19u, 0u, 12u, 333u);
    l21 = (void*) _a17_arr;
    vader_array_t* _a18_arr = vader_array_new(22u, 0u, 7u, 338u);
    l22 = (void*) _a18_arr;
    vader_struct_std_collections$MutableMap__i32__bool_t* _a19_obj = (vader_struct_std_collections$MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i32__bool_t));
    vader_obj_header_init(_a19_obj, 462u);
    _a19_obj->f_ekeys = l20;
    _a19_obj->f_evals = l21;
    _a19_obj->f_index = l22;
    _a19_obj->f_mask = INT64_C(0);
    _a19_obj->f_grow_at = INT64_C(0);
    _a19_obj->f_size = INT64_C(0);
    _a19_obj->f_tombs = INT64_C(0);
    l20 = (void*) _a19_obj;
    vader_array_t* _a20_arr = vader_array_new(22u, 0u, 7u, 338u);
    l21 = (void*) _a20_arr;
    vader_array_t* _a21_arr = vader_array_new(28u, 0u, 0u, 346u);
    l22 = (void*) _a21_arr;
    vader_array_t* _a22_arr = vader_array_new(22u, 0u, 7u, 338u);
    l23 = (void*) _a22_arr;
    vader_struct_std_collections$MutableMap__i32__Any_t* _a23_obj = (vader_struct_std_collections$MutableMap__i32__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i32__Any_t));
    vader_obj_header_init(_a23_obj, 459u);
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
        vader_array_t* _a24_slotarr = ((vader_array_t*) l6);
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
        vader_array_t* _a26_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a26_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a26_slotarr, l10)
        t1 = ((int32_t*) _a26_slotarr->buf->slots)[_a26_slotarr->offset + (size_t) l10];
        if (t1 != INT32_C(1)) {
            l24 = false;
        }
        l13 = INT32_C(-1);
        l14 = INT32_C(-1);
        if (l24) {
            vader_array_t* _a27_slotarr = ((vader_array_t*) l7);
            VADER_ARRAY_RESOLVE_BUF(_a27_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a27_slotarr, l10)
            l13 = ((int32_t*) _a27_slotarr->buf->slots)[_a27_slotarr->offset + (size_t) l10];
            vader_array_t* _a28_slotarr = ((vader_array_t*) l8);
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
            vader_array_t* _a29_slotarr = ((vader_array_t*) l9);
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
    vader_array_t* _a31_arr = vader_array_new(247u, 0u, 13u, 1677u);
    l3 = (void*) _a31_arr;
    vader_array_t* _a32_arr = vader_array_new(251u, 0u, 13u, 1735u);
    l5 = (void*) _a32_arr;
    vader_array_t* _a33_arr = vader_array_new(22u, 0u, 7u, 338u);
    l6 = (void*) _a33_arr;
    if ((INT64_C(0) < l4)) {
        l1 = l4;
    } else {
        l1 = INT64_C(0);
    }
    vader_array_t* _a34_arr = vader_array_repeat((vader_array_t*) l6, (int64_t) l1);
    l6 = (void*) _a34_arr;
    l1 = INT64_C(0);
    vader_array_t* _pc404_hdr = (vader_array_t*) l6;
    size_t _pc404_len = _pc404_hdr->length;
    size_t _pc404_cap = (_pc404_hdr->offset == 0 && !vader_array_is_borrowed(_pc404_hdr) && _pc404_hdr->length >= _pc404_hdr->buf->length) ? _pc404_hdr->capacity : (size_t) 0;
    void* _pc404_slots = _pc404_hdr->buf->slots;
    for (;;) {
        if ((l1 < l4)) {
            if (VADER_LIKELY(_pc404_len < _pc404_cap)) {
                ((int32_t*) _pc404_slots)[_pc404_len] = (int32_t) (INT32_C(-1));
                _pc404_len += 1;
            } else {
                _pc404_hdr->length = _pc404_len;
                if (_pc404_hdr->buf->length < _pc404_len) {
                    _pc404_hdr->buf->length = _pc404_len;
                }
                vader_array_push_i32((vader_array_t*) l6, INT32_C(-1));
                _pc404_hdr = (vader_array_t*) l6;
                _pc404_len = _pc404_hdr->length;
                _pc404_cap = (_pc404_hdr->offset == 0 && !vader_array_is_borrowed(_pc404_hdr) && _pc404_hdr->length >= _pc404_hdr->buf->length) ? _pc404_hdr->capacity : (size_t) 0;
                _pc404_slots = _pc404_hdr->buf->slots;
            }
            l1 = (l1 + INT64_C(1));
            continue;
        }
        _pc404_hdr->length = _pc404_len;
        if (_pc404_hdr->buf->length < _pc404_len) {
            _pc404_hdr->buf->length = _pc404_len;
        }
        break;
    }
    l1 = INT64_C(0);
    while ((l1 < l4)) {
        l13 = ((int32_t) (int64_t) l1);
        t3 = std_collections$MutableMap$std_core$Index$at__i32__bool(l20, l13);
        if (t3.tag == 333u) {
            l1 = vader_chk_add(i64, l1, INT64_C(1));
            continue;
        }
        l14 = ((int32_t) (int64_t) l1);
        l11 = std_collections$MutableMap$std_core$Index$at__i32__Any(l21, l14);
        if (l11.tag == 0u) {
            t4 = ((vader_array_t*) l3)->length;
            l15 = ((int32_t) (int64_t) t4);
            vader_array_t* _a35_slotarr = ((vader_array_t*) l6);
            VADER_ARRAY_RESOLVE_BUF(_a35_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a35_slotarr, l1)
            ((int32_t*) _a35_slotarr->buf->slots)[_a35_slotarr->offset + (size_t) l1] = (int32_t) l15;
            vader_array_t* _a36_slotarr = ((vader_array_t*) l9);
            VADER_ARRAY_RESOLVE_BUF(_a36_slotarr)
            l25 = vader_array_ref_load_box(_a36_slotarr->buf, _a36_slotarr->offset + (size_t) l1);
            vader_array_push_ref((vader_array_t*) l3, l25.payload.obj);
            vader_array_t* _a37_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_debug);
            VADER_ARRAY_RESOLVE_BUF(_a37_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a37_slotarr, l1)
            l27 = vader_array_ref_load_box(_a37_slotarr->buf, _a37_slotarr->offset + (size_t) l1);
            vader_array_push_ref((vader_array_t*) l5, l27.payload.obj);
        } else {
            t4 = ((vader_array_t*) l3)->length;
            l16 = ((int32_t) (int64_t) t4);
            vader_array_t* _a38_slotarr = ((vader_array_t*) l6);
            VADER_ARRAY_RESOLVE_BUF(_a38_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a38_slotarr, l1)
            ((int32_t*) _a38_slotarr->buf->slots)[_a38_slotarr->offset + (size_t) l1] = (int32_t) l16;
            l28 = l11;
            vader_array_push_ref((vader_array_t*) l3, l28.payload.obj);
            vader_array_t* _a39_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_debug);
            VADER_ARRAY_RESOLVE_BUF(_a39_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a39_slotarr, l1)
            l29 = vader_array_ref_load_box(_a39_slotarr->buf, _a39_slotarr->offset + (size_t) l1);
            vader_array_push_ref((vader_array_t*) l5, l29.payload.obj);
        }
        l1 = vader_chk_add(i64, l1, INT64_C(1));
    }
    l7 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_jump_table;
    l1 = ((vader_array_t*) l3)->length;
    l6 = vader_core_bytecode$remap_jump_table(l7, l6, l1);
    l7 = l0;
    l30 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l7)->f_name;
    l24 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l7)->f_is_main;
    l8 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l7)->f_signature;
    l9 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l7)->f_locals;
    l7 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l7)->f_source_pc;
    vader_struct_vader_core_bytecode$BcFunction_t* _a40_obj = (vader_struct_vader_core_bytecode$BcFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcFunction_t));
    vader_obj_header_init(_a40_obj, 729u);
    _a40_obj->f_name = l30;
    _a40_obj->f_is_main = l24;
    _a40_obj->f_signature = l8;
    _a40_obj->f_locals = l9;
    _a40_obj->f_body = l3;
    _a40_obj->f_debug = l5;
    _a40_obj->f_jump_table = l6;
    _a40_obj->f_source_pc = l7;
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
            if (l9.tag == 767u) {
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
    vader_array_t* _a7_arr = vader_array_new(22u, 0u, 7u, 338u);
    l3 = (void*) _a7_arr;
    vader_array_t* _a8_arr = vader_array_new(248u, 0u, 13u, 1700u);
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
            if (l9.tag == 767u) {
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
                vader_obj_header_init(_a13_obj, 767u);
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
    int64_t l3, l7, l11, l14, l15, l17, l18;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    void* l25 = NULL;
    void* l26 = NULL;
    void* l27 = NULL;
    void* l28 = NULL;
    void* l29 = NULL;
    void* l30 = NULL;
    void* l34 = NULL;
    int32_t l8, l10, l20, l23, l24, l31, l32, l33;
    vader_string_t l9 = 0;
    vader_string_t l35 = 0;
    bool l16, l21, l22;
    vader_box_t l19 = vader_box_null();
    bool t0, t2;
    void* t1 = NULL;
    int64_t t3;
    vader_box_t t4 = vader_box_null();
    int32_t t5;
    vader_string_t t6 = 0;
    vader_box_t* gc_roots[2] = { &l19, &t4 };
    void** gc_raw_roots[16] = {
        &l0, &l1, &l2, &l4, &l5, &l6, &l12, &l13, &l25, &l26, &l27, &l28, &l29, &l30, &l34, &t1,
    };
    vader_string_t* gc_atom_roots[3] = { &l9, &l35, &t6 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 16u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = ((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_functions)->length;
    vader_array_t* _a0_arr = vader_array_new(22u, 0u, 7u, 338u);
    l4 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(19u, 0u, 12u, 333u);
    l5 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(22u, 0u, 7u, 338u);
    l6 = (void*) _a2_arr;
    vader_struct_std_collections$MutableMap__i32__bool_t* _a3_obj = (vader_struct_std_collections$MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i32__bool_t));
    vader_obj_header_init(_a3_obj, 462u);
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
        t1 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l11);
        l8 = ((vader_struct_vader_core_bytecode$BcExport_t*) t1)->f_fn_index;
        std_collections$MutableMap$std_core$IndexSet$set_at__i32__bool(l4, l8, true);
        l11 = (l11 + INT64_C(1));
    }
    l5 = l1;
    l7 = ((vader_array_t*) l5)->length;
    l11 = INT64_C(0);
    while ((l11 < l7)) {
        vader_array_t* _a6_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        l8 = ((int32_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l11];
        if ((l8 >= INT32_C(0))) {
            l10 = ((int32_t) (int64_t) l3);
            if ((l8 < l10)) {
                std_collections$MutableMap$std_core$IndexSet$set_at__i32__bool(l4, l8, true);
            }
        }
        l11 = (l11 + INT64_C(1));
    }
    vader_array_t* _a7_arr = vader_array_new(22u, 0u, 7u, 338u);
    l5 = (void*) _a7_arr;
    l11 = ((vader_struct_std_collections$MutableMap__i32__bool_t*) l4)->f_size;
    if ((INT64_C(0) < l11)) {
        l7 = ((vader_struct_std_collections$MutableMap__i32__bool_t*) l4)->f_size;
    } else {
        l7 = INT64_C(0);
    }
    vader_array_t* _a8_arr = vader_array_repeat((vader_array_t*) l5, (int64_t) l7);
    l5 = (void*) _a8_arr;
    l6 = l4;
    l12 = ((vader_struct_std_collections$MutableMap__i32__bool_t*) l6)->f_ekeys;
    l13 = ((vader_struct_std_collections$MutableMap__i32__bool_t*) l6)->f_evals;
    l7 = INT64_C(0);
    l11 = ((vader_struct_std_collections$MutableMap__i32__bool_t*) l6)->f_size;
    vader_array_t* _pc159_hdr = (vader_array_t*) l5;
    size_t _pc159_len = _pc159_hdr->length;
    size_t _pc159_cap = (_pc159_hdr->offset == 0 && !vader_array_is_borrowed(_pc159_hdr) && _pc159_hdr->length >= _pc159_hdr->buf->length) ? _pc159_hdr->capacity : (size_t) 0;
    void* _pc159_slots = _pc159_hdr->buf->slots;
    for (;;) {
        if ((l7 < l11)) {
            vader_array_t* _a9_slotarr = ((vader_array_t*) l12);
            VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l7)
            l8 = ((int32_t*) _a9_slotarr->buf->slots)[_a9_slotarr->offset + (size_t) l7];
            vader_array_t* _a10_slotarr = ((vader_array_t*) l13);
            VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a10_slotarr, l7)
            t0 = ((uint8_t*) _a10_slotarr->buf->slots)[_a10_slotarr->offset + (size_t) l7];
            t2 = t0;
            l10 = l8;
            if (VADER_LIKELY(_pc159_len < _pc159_cap)) {
                ((int32_t*) _pc159_slots)[_pc159_len] = (int32_t) (l10);
                _pc159_len += 1;
            } else {
                _pc159_hdr->length = _pc159_len;
                if (_pc159_hdr->buf->length < _pc159_len) {
                    _pc159_hdr->buf->length = _pc159_len;
                }
                vader_array_push_i32((vader_array_t*) l5, l10);
                _pc159_hdr = (vader_array_t*) l5;
                _pc159_len = _pc159_hdr->length;
                _pc159_cap = (_pc159_hdr->offset == 0 && !vader_array_is_borrowed(_pc159_hdr) && _pc159_hdr->length >= _pc159_hdr->buf->length) ? _pc159_hdr->capacity : (size_t) 0;
                _pc159_slots = _pc159_hdr->buf->slots;
            }
            l7 = (l7 + INT64_C(1));
            continue;
        }
        _pc159_hdr->length = _pc159_len;
        if (_pc159_hdr->buf->length < _pc159_len) {
            _pc159_hdr->buf->length = _pc159_len;
        }
        break;
    }
    for (;;) {
        t3 = ((vader_array_t*) l5)->length;
        if ((t3 > INT64_C(0))) {
            t3 = ((vader_array_t*) l5)->length;
            l7 = vader_chk_sub(i64, t3, INT64_C(1));
            vader_array_t* _a11_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
            l8 = ((int32_t*) _a11_slotarr->buf->slots)[_a11_slotarr->offset + (size_t) l7];
            vader_array_t* _a12_arr = vader_array_new(22u, 0u, 7u, 338u);
            l6 = (void*) _a12_arr;
            l11 = INT64_C(0);
            t3 = ((vader_array_t*) l5)->length;
            l14 = vader_chk_sub(i64, t3, INT64_C(1));
            vader_array_t* _pc209_hdr = (vader_array_t*) l6;
            size_t _pc209_len = _pc209_hdr->length;
            size_t _pc209_cap = (_pc209_hdr->offset == 0 && !vader_array_is_borrowed(_pc209_hdr) && _pc209_hdr->length >= _pc209_hdr->buf->length) ? _pc209_hdr->capacity : (size_t) 0;
            void* _pc209_slots = _pc209_hdr->buf->slots;
            for (;;) {
                if ((l11 < l14)) {
                    vader_array_t* _a13_slotarr = ((vader_array_t*) l5);
                    VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
                    l10 = ((int32_t*) _a13_slotarr->buf->slots)[_a13_slotarr->offset + (size_t) l11];
                    if (VADER_LIKELY(_pc209_len < _pc209_cap)) {
                        ((int32_t*) _pc209_slots)[_pc209_len] = (int32_t) (l10);
                        _pc209_len += 1;
                    } else {
                        _pc209_hdr->length = _pc209_len;
                        if (_pc209_hdr->buf->length < _pc209_len) {
                            _pc209_hdr->buf->length = _pc209_len;
                        }
                        vader_array_push_i32((vader_array_t*) l6, l10);
                        _pc209_hdr = (vader_array_t*) l6;
                        _pc209_len = _pc209_hdr->length;
                        _pc209_cap = (_pc209_hdr->offset == 0 && !vader_array_is_borrowed(_pc209_hdr) && _pc209_hdr->length >= _pc209_hdr->buf->length) ? _pc209_hdr->capacity : (size_t) 0;
                        _pc209_slots = _pc209_hdr->buf->slots;
                    }
                    l11 = (l11 + INT64_C(1));
                    continue;
                }
                _pc209_hdr->length = _pc209_len;
                if (_pc209_hdr->buf->length < _pc209_len) {
                    _pc209_hdr->buf->length = _pc209_len;
                }
                break;
            }
            l5 = l6;
            l15 = ((int64_t) (int32_t) l8);
            if ((INT64_C(0) <= l15)) {
                l16 = (l15 < l3);
            } else {
                l16 = false;
            }
            if (!(l16)) {
                continue;
            }
            vader_array_t* _a14_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_functions);
            VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a14_slotarr, l8)
            t1 = vader_array_ref_load_obj(_a14_slotarr->buf, _a14_slotarr->offset + (size_t) l8);
            l12 = ((vader_struct_vader_core_bytecode$BcFunction_t*) t1)->f_body;
            l17 = ((vader_array_t*) l12)->length;
            l18 = INT64_C(0);
            while ((l18 < l17)) {
                vader_array_t* _a15_slotarr = ((vader_array_t*) l12);
                VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
                l19 = vader_array_ref_load_box(_a15_slotarr->buf, _a15_slotarr->offset + (size_t) l18);
                l20 = INT32_C(-1);
                if (l19.tag == 760u) {
                    t1 = l19.payload.obj;
                    l20 = ((vader_struct_vader_core_bytecode$Call_t*) t1)->f_function_index;
                }
                if (l19.tag == 789u) {
                    t1 = l19.payload.obj;
                    l20 = ((vader_struct_vader_core_bytecode$FnRef_t*) t1)->f_function_index;
                }
                if (l19.tag == 788u) {
                    t1 = l19.payload.obj;
                    l20 = ((vader_struct_vader_core_bytecode$FnAddr_t*) t1)->f_function_index;
                }
                if (l19.tag == 846u) {
                    t1 = l19.payload.obj;
                    l20 = ((vader_struct_vader_core_bytecode$MakeClosure_t*) t1)->f_function_index;
                }
                if ((l20 < INT32_C(0))) {
                    l18 = (l18 + INT64_C(1));
                    continue;
                }
                t4 = std_collections$MutableMap$std_core$Index$at__i32__bool(l4, l20);
                if (t4.tag == 333u) {
                    l18 = (l18 + INT64_C(1));
                    continue;
                }
                std_collections$MutableMap$std_core$IndexSet$set_at__i32__bool(l4, l20, true);
                vader_array_push_i32((vader_array_t*) l5, l20);
                l18 = (l18 + INT64_C(1));
            }
            continue;
        }
        break;
    }
    l16 = std_collections$is_empty__i32__bool(l4);
    vader_array_t* _a16_arr = vader_array_new(21u, 0u, 0u, 335u);
    l5 = (void*) _a16_arr;
    vader_array_t* _a17_arr = vader_array_new(22u, 0u, 7u, 338u);
    l6 = (void*) _a17_arr;
    vader_array_t* _a18_arr = vader_array_new(22u, 0u, 7u, 338u);
    l12 = (void*) _a18_arr;
    vader_struct_std_collections$MutableMap__string__i32_t* _a19_obj = (vader_struct_std_collections$MutableMap__string__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__string__i32_t));
    vader_obj_header_init(_a19_obj, 540u);
    _a19_obj->f_ekeys = l5;
    _a19_obj->f_evals = l6;
    _a19_obj->f_index = l12;
    _a19_obj->f_mask = INT64_C(0);
    _a19_obj->f_grow_at = INT64_C(0);
    _a19_obj->f_size = INT64_C(0);
    _a19_obj->f_tombs = INT64_C(0);
    l5 = (void*) _a19_obj;
    l21 = false;
    l7 = INT64_C(0);
    while ((l7 < l3)) {
        if (l16) {
            l22 = true;
        } else {
            l8 = ((int32_t) (int64_t) l7);
            t4 = std_collections$MutableMap$std_core$Index$at__i32__bool(l4, l8);
            l22 = t4.tag == 333u;
        }
        if (l22) {
            vader_array_t* _a20_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_functions);
            VADER_ARRAY_RESOLVE_BUF(_a20_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a20_slotarr, l7)
            t1 = vader_array_ref_load_obj(_a20_slotarr->buf, _a20_slotarr->offset + (size_t) l7);
            l9 = ((vader_struct_vader_core_bytecode$BcFunction_t*) t1)->f_name;
            if (l9 != 0u) {
                l10 = ((int32_t) (int64_t) l7);
                l20 = std_collections$get_or_put__string__i32(l5, l9, l10);
                l23 = ((int32_t) (int64_t) l7);
                if (l20 != l23) {
                    l21 = true;
                    vader_array_t* _a21_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_functions);
                    VADER_ARRAY_RESOLVE_BUF(_a21_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a21_slotarr, l7)
                    t1 = vader_array_ref_load_obj(_a21_slotarr->buf, _a21_slotarr->offset + (size_t) l7);
                    t3 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) t1)->f_body)->length;
                    if ((t3 > INT64_C(0))) {
                        vader_array_t* _a22_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_functions);
                        VADER_ARRAY_RESOLVE_BUF(_a22_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a22_slotarr, l20)
                        t1 = vader_array_ref_load_obj(_a22_slotarr->buf, _a22_slotarr->offset + (size_t) l20);
                        t3 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) t1)->f_body)->length;
                        if (t3 == INT64_C(0)) {
                            l24 = ((int32_t) (int64_t) l7);
                            std_collections$MutableMap$std_core$IndexSet$set_at__string__i32(l5, l9, l24);
                        }
                    }
                }
            }
        }
        l7 = (l7 + INT64_C(1));
    }
    if (!(l21)) {
        if (l16) {
            { vader_gc_top = gc_frame.prev; return; }
        }
        t3 = std_collections$len__i32__bool(l4);
        if (t3 == l3) {
            { vader_gc_top = gc_frame.prev; return; }
        }
    }
    vader_array_t* _a23_arr = vader_array_new(22u, 0u, 7u, 338u);
    l6 = (void*) _a23_arr;
    if ((INT64_C(0) < l3)) {
        l7 = l3;
    } else {
        l7 = INT64_C(0);
    }
    vader_array_t* _a24_arr = vader_array_repeat((vader_array_t*) l6, (int64_t) l7);
    l6 = (void*) _a24_arr;
    l7 = INT64_C(0);
    while ((l7 < l3)) {
        vader_array_t* _a25_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_functions);
        VADER_ARRAY_RESOLVE_BUF(_a25_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a25_slotarr, l7)
        t1 = vader_array_ref_load_obj(_a25_slotarr->buf, _a25_slotarr->offset + (size_t) l7);
        l9 = ((vader_struct_vader_core_bytecode$BcFunction_t*) t1)->f_name;
        l8 = ((int32_t) (int64_t) l7);
        if (l9 != 0u) {
            l19 = std_collections$MutableMap$std_core$Index$at__string__i32(l5, l9);
            if (l19.tag == 338u) {
                l8 = ((int32_t) l19.payload.i);
            }
        }
        vader_array_push_i32((vader_array_t*) l6, l8);
        l7 = (l7 + INT64_C(1));
    }
    vader_array_t* _a26_arr = vader_array_new(22u, 0u, 7u, 338u);
    l5 = (void*) _a26_arr;
    vader_array_t* _a27_arr = vader_array_new(22u, 0u, 7u, 338u);
    l12 = (void*) _a27_arr;
    vader_array_t* _a28_arr = vader_array_new(22u, 0u, 7u, 338u);
    l13 = (void*) _a28_arr;
    vader_struct_std_collections$MutableMap__i32__i32_t* _a29_obj = (vader_struct_std_collections$MutableMap__i32__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i32__i32_t));
    vader_obj_header_init(_a29_obj, 463u);
    _a29_obj->f_ekeys = l5;
    _a29_obj->f_evals = l12;
    _a29_obj->f_index = l13;
    _a29_obj->f_mask = INT64_C(0);
    _a29_obj->f_grow_at = INT64_C(0);
    _a29_obj->f_size = INT64_C(0);
    _a29_obj->f_tombs = INT64_C(0);
    l5 = (void*) _a29_obj;
    vader_array_t* _a30_arr = vader_array_new(60u, 0u, 13u, 729u);
    l12 = (void*) _a30_arr;
    l7 = INT64_C(0);
    while ((l7 < l3)) {
        {
            if (!(l16)) {
                l8 = ((int32_t) (int64_t) l7);
                t4 = std_collections$MutableMap$std_core$Index$at__i32__bool(l4, l8);
                if (!(t4.tag == 333u)) {
                    goto end_544;
                }
            }
            vader_array_t* _a31_slotarr = ((vader_array_t*) l6);
            VADER_ARRAY_RESOLVE_BUF(_a31_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a31_slotarr, l7)
            l10 = ((int32_t*) _a31_slotarr->buf->slots)[_a31_slotarr->offset + (size_t) l7];
            l20 = ((int32_t) (int64_t) l7);
            if (l10 == l20) {
                l23 = ((int32_t) (int64_t) l7);
                t3 = ((vader_array_t*) l12)->length;
                l24 = ((int32_t) (int64_t) t3);
                std_collections$MutableMap$std_core$IndexSet$set_at__i32__i32(l5, l23, l24);
                vader_array_t* _a32_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_functions);
                VADER_ARRAY_RESOLVE_BUF(_a32_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a32_slotarr, l7)
                l13 = vader_array_ref_load_obj(_a32_slotarr->buf, _a32_slotarr->offset + (size_t) l7);
                vader_array_push_ref((vader_array_t*) l12, l13);
            }
        } end_544: ;
        l7 = (l7 + INT64_C(1));
    }
    vader_array_t* _a33_arr = vader_array_new(22u, 0u, 7u, 338u);
    l13 = (void*) _a33_arr;
    if ((INT64_C(0) < l3)) {
        l7 = l3;
    } else {
        l7 = INT64_C(0);
    }
    vader_array_t* _a34_arr = vader_array_repeat((vader_array_t*) l13, (int64_t) l7);
    l13 = (void*) _a34_arr;
    l7 = INT64_C(0);
    vader_array_t* _pc616_hdr = (vader_array_t*) l13;
    size_t _pc616_len = _pc616_hdr->length;
    size_t _pc616_cap = (_pc616_hdr->offset == 0 && !vader_array_is_borrowed(_pc616_hdr) && _pc616_hdr->length >= _pc616_hdr->buf->length) ? _pc616_hdr->capacity : (size_t) 0;
    void* _pc616_slots = _pc616_hdr->buf->slots;
    for (;;) {
        if ((l7 < l3)) {
            l8 = INT32_C(-1);
            if (l16) {
                l21 = true;
            } else {
                l10 = ((int32_t) (int64_t) l7);
                t4 = std_collections$MutableMap$std_core$Index$at__i32__bool(l4, l10);
                l21 = t4.tag == 333u;
            }
            if (l21) {
                vader_array_t* _a35_slotarr = ((vader_array_t*) l6);
                VADER_ARRAY_RESOLVE_BUF(_a35_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a35_slotarr, l7)
                l20 = ((int32_t*) _a35_slotarr->buf->slots)[_a35_slotarr->offset + (size_t) l7];
                l19 = std_collections$MutableMap$std_core$Index$at__i32__i32(l5, l20);
                if (l19.tag == 338u) {
                    l8 = ((int32_t) l19.payload.i);
                }
            }
            if (VADER_LIKELY(_pc616_len < _pc616_cap)) {
                ((int32_t*) _pc616_slots)[_pc616_len] = (int32_t) (l8);
                _pc616_len += 1;
            } else {
                _pc616_hdr->length = _pc616_len;
                if (_pc616_hdr->buf->length < _pc616_len) {
                    _pc616_hdr->buf->length = _pc616_len;
                }
                vader_array_push_i32((vader_array_t*) l13, l8);
                _pc616_hdr = (vader_array_t*) l13;
                _pc616_len = _pc616_hdr->length;
                _pc616_cap = (_pc616_hdr->offset == 0 && !vader_array_is_borrowed(_pc616_hdr) && _pc616_hdr->length >= _pc616_hdr->buf->length) ? _pc616_hdr->capacity : (size_t) 0;
                _pc616_slots = _pc616_hdr->buf->slots;
            }
            l7 = (l7 + INT64_C(1));
            continue;
        }
        _pc616_hdr->length = _pc616_len;
        if (_pc616_hdr->buf->length < _pc616_len) {
            _pc616_hdr->buf->length = _pc616_len;
        }
        break;
    }
    l4 = l12;
    l3 = ((vader_array_t*) l4)->length;
    l7 = INT64_C(0);
    while ((l7 < l3)) {
        vader_array_t* _a36_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a36_slotarr)
        l5 = vader_array_ref_load_obj(_a36_slotarr->buf, _a36_slotarr->offset + (size_t) l7);
        l11 = INT64_C(0);
        l14 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l5)->f_body)->length;
        while ((l11 < l14)) {
            vader_array_t* _a37_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l5)->f_body);
            VADER_ARRAY_RESOLVE_BUF(_a37_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a37_slotarr, l11)
            l19 = vader_array_ref_load_box(_a37_slotarr->buf, _a37_slotarr->offset + (size_t) l11);
            if (l19.tag == 760u) {
                l6 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l5)->f_body;
                t1 = l19.payload.obj;
                l8 = ((vader_struct_vader_core_bytecode$Call_t*) t1)->f_function_index;
                vader_array_t* _a38_slotarr = ((vader_array_t*) l13);
                VADER_ARRAY_RESOLVE_BUF(_a38_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a38_slotarr, l8)
                t5 = ((int32_t*) _a38_slotarr->buf->slots)[_a38_slotarr->offset + (size_t) l8];
                vader_struct_vader_core_bytecode$Call_t* _a39_obj = (vader_struct_vader_core_bytecode$Call_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$Call_t));
                vader_obj_header_init(_a39_obj, 760u);
                _a39_obj->f_function_index = t5;
                l25 = (void*) _a39_obj;
                vader_array_t* _a40_slotarr = ((vader_array_t*) l6);
                VADER_ARRAY_RESOLVE_BUF(_a40_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a40_slotarr, l11)
                vader_array_ref_store(_a40_slotarr->buf, _a40_slotarr->offset + (size_t) l11, l25);
                VADER_WRITE_BARRIER(_a40_slotarr->buf);
            }
            if (l19.tag == 789u) {
                l26 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l5)->f_body;
                t1 = l19.payload.obj;
                l10 = ((vader_struct_vader_core_bytecode$FnRef_t*) t1)->f_function_index;
                vader_array_t* _a41_slotarr = ((vader_array_t*) l13);
                VADER_ARRAY_RESOLVE_BUF(_a41_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a41_slotarr, l10)
                l20 = ((int32_t*) _a41_slotarr->buf->slots)[_a41_slotarr->offset + (size_t) l10];
                t1 = l19.payload.obj;
                l23 = ((vader_struct_vader_core_bytecode$FnRef_t*) t1)->f_type_id;
                vader_struct_vader_core_bytecode$FnRef_t* _a42_obj = (vader_struct_vader_core_bytecode$FnRef_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$FnRef_t));
                vader_obj_header_init(_a42_obj, 789u);
                _a42_obj->f_function_index = l20;
                _a42_obj->f_type_id = l23;
                l27 = (void*) _a42_obj;
                vader_array_t* _a43_slotarr = ((vader_array_t*) l26);
                VADER_ARRAY_RESOLVE_BUF(_a43_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a43_slotarr, l11)
                vader_array_ref_store(_a43_slotarr->buf, _a43_slotarr->offset + (size_t) l11, l27);
                VADER_WRITE_BARRIER(_a43_slotarr->buf);
            }
            if (l19.tag == 788u) {
                l28 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l5)->f_body;
                t1 = l19.payload.obj;
                l24 = ((vader_struct_vader_core_bytecode$FnAddr_t*) t1)->f_function_index;
                vader_array_t* _a44_slotarr = ((vader_array_t*) l13);
                VADER_ARRAY_RESOLVE_BUF(_a44_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a44_slotarr, l24)
                t5 = ((int32_t*) _a44_slotarr->buf->slots)[_a44_slotarr->offset + (size_t) l24];
                vader_struct_vader_core_bytecode$FnAddr_t* _a45_obj = (vader_struct_vader_core_bytecode$FnAddr_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$FnAddr_t));
                vader_obj_header_init(_a45_obj, 788u);
                _a45_obj->f_function_index = t5;
                l29 = (void*) _a45_obj;
                vader_array_t* _a46_slotarr = ((vader_array_t*) l28);
                VADER_ARRAY_RESOLVE_BUF(_a46_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a46_slotarr, l11)
                vader_array_ref_store(_a46_slotarr->buf, _a46_slotarr->offset + (size_t) l11, l29);
                VADER_WRITE_BARRIER(_a46_slotarr->buf);
            }
            if (l19.tag == 846u) {
                l30 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l5)->f_body;
                t1 = l19.payload.obj;
                l31 = ((vader_struct_vader_core_bytecode$MakeClosure_t*) t1)->f_function_index;
                vader_array_t* _a47_slotarr = ((vader_array_t*) l13);
                VADER_ARRAY_RESOLVE_BUF(_a47_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a47_slotarr, l31)
                l32 = ((int32_t*) _a47_slotarr->buf->slots)[_a47_slotarr->offset + (size_t) l31];
                t1 = l19.payload.obj;
                l33 = ((vader_struct_vader_core_bytecode$MakeClosure_t*) t1)->f_env_type_id;
                vader_struct_vader_core_bytecode$MakeClosure_t* _a48_obj = (vader_struct_vader_core_bytecode$MakeClosure_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$MakeClosure_t));
                vader_obj_header_init(_a48_obj, 846u);
                _a48_obj->f_function_index = l32;
                _a48_obj->f_env_type_id = l33;
                l34 = (void*) _a48_obj;
                vader_array_t* _a49_slotarr = ((vader_array_t*) l30);
                VADER_ARRAY_RESOLVE_BUF(_a49_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a49_slotarr, l11)
                vader_array_ref_store(_a49_slotarr->buf, _a49_slotarr->offset + (size_t) l11, l34);
                VADER_WRITE_BARRIER(_a49_slotarr->buf);
            }
            l11 = (l11 + INT64_C(1));
        }
        l7 = (l7 + INT64_C(1));
    }
    vader_array_t* _a50_arr = vader_array_new(58u, 0u, 13u, 726u);
    l4 = (void*) _a50_arr;
    l5 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_exports;
    l3 = ((vader_array_t*) l5)->length;
    l7 = INT64_C(0);
    while ((l7 < l3)) {
        vader_array_t* _a51_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a51_slotarr)
        l6 = vader_array_ref_load_obj(_a51_slotarr->buf, _a51_slotarr->offset + (size_t) l7);
        l8 = ((vader_struct_vader_core_bytecode$BcExport_t*) l6)->f_fn_index;
        vader_array_t* _a52_slotarr = ((vader_array_t*) l13);
        VADER_ARRAY_RESOLVE_BUF(_a52_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a52_slotarr, l8)
        l10 = ((int32_t*) _a52_slotarr->buf->slots)[_a52_slotarr->offset + (size_t) l8];
        if ((l10 >= INT32_C(0))) {
            t6 = ((vader_struct_vader_core_bytecode$BcExport_t*) l6)->f_extern_name;
            vader_struct_vader_core_bytecode$BcExport_t* _a53_obj = (vader_struct_vader_core_bytecode$BcExport_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcExport_t));
            vader_obj_header_init(_a53_obj, 726u);
            _a53_obj->f_extern_name = t6;
            _a53_obj->f_fn_index = l10;
            l25 = (void*) _a53_obj;
            vader_array_push_ref((vader_array_t*) l4, l25);
        }
        l7 = (l7 + INT64_C(1));
    }
    ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_exports = l4;
    VADER_WRITE_BARRIER((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0);
    vader_array_t* _a54_arr = vader_array_new(22u, 0u, 7u, 338u);
    l4 = (void*) _a54_arr;
    vader_array_t* _a55_arr = vader_array_new(22u, 0u, 7u, 338u);
    l5 = (void*) _a55_arr;
    vader_array_t* _a56_arr = vader_array_new(22u, 0u, 7u, 338u);
    l6 = (void*) _a56_arr;
    vader_struct_std_collections$MutableMap__i32__i32_t* _a57_obj = (vader_struct_std_collections$MutableMap__i32__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i32__i32_t));
    vader_obj_header_init(_a57_obj, 463u);
    _a57_obj->f_ekeys = l4;
    _a57_obj->f_evals = l5;
    _a57_obj->f_index = l6;
    _a57_obj->f_mask = INT64_C(0);
    _a57_obj->f_grow_at = INT64_C(0);
    _a57_obj->f_size = INT64_C(0);
    _a57_obj->f_tombs = INT64_C(0);
    l4 = (void*) _a57_obj;
    l5 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_function_index_by_symbol_id;
    l6 = ((vader_struct_std_collections$MutableMap__i32__i32_t*) l5)->f_ekeys;
    l25 = ((vader_struct_std_collections$MutableMap__i32__i32_t*) l5)->f_evals;
    l3 = INT64_C(0);
    l7 = ((vader_struct_std_collections$MutableMap__i32__i32_t*) l5)->f_size;
    while ((l3 < l7)) {
        vader_array_t* _a58_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a58_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a58_slotarr, l3)
        l8 = ((int32_t*) _a58_slotarr->buf->slots)[_a58_slotarr->offset + (size_t) l3];
        vader_array_t* _a59_slotarr = ((vader_array_t*) l25);
        VADER_ARRAY_RESOLVE_BUF(_a59_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a59_slotarr, l3)
        l10 = ((int32_t*) _a59_slotarr->buf->slots)[_a59_slotarr->offset + (size_t) l3];
        l20 = l8;
        l23 = l10;
        vader_array_t* _a60_slotarr = ((vader_array_t*) l13);
        VADER_ARRAY_RESOLVE_BUF(_a60_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a60_slotarr, l23)
        l24 = ((int32_t*) _a60_slotarr->buf->slots)[_a60_slotarr->offset + (size_t) l23];
        if ((l24 >= INT32_C(0))) {
            std_collections$MutableMap$std_core$IndexSet$set_at__i32__i32(l4, l20, l24);
        }
        l3 = (l3 + INT64_C(1));
    }
    ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_function_index_by_symbol_id = l4;
    VADER_WRITE_BARRIER((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0);
    vader_array_t* _a61_arr = vader_array_new(21u, 0u, 0u, 335u);
    l4 = (void*) _a61_arr;
    vader_array_t* _a62_arr = vader_array_new(22u, 0u, 7u, 338u);
    l5 = (void*) _a62_arr;
    vader_array_t* _a63_arr = vader_array_new(22u, 0u, 7u, 338u);
    l6 = (void*) _a63_arr;
    vader_struct_std_collections$MutableMap__string__i32_t* _a64_obj = (vader_struct_std_collections$MutableMap__string__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__string__i32_t));
    vader_obj_header_init(_a64_obj, 540u);
    _a64_obj->f_ekeys = l4;
    _a64_obj->f_evals = l5;
    _a64_obj->f_index = l6;
    _a64_obj->f_mask = INT64_C(0);
    _a64_obj->f_grow_at = INT64_C(0);
    _a64_obj->f_size = INT64_C(0);
    _a64_obj->f_tombs = INT64_C(0);
    l4 = (void*) _a64_obj;
    l5 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_function_index_by_mangle;
    l6 = ((vader_struct_std_collections$MutableMap__string__i32_t*) l5)->f_ekeys;
    l25 = ((vader_struct_std_collections$MutableMap__string__i32_t*) l5)->f_evals;
    l3 = INT64_C(0);
    l7 = ((vader_struct_std_collections$MutableMap__string__i32_t*) l5)->f_size;
    while ((l3 < l7)) {
        vader_array_t* _a65_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a65_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a65_slotarr, l3)
        t4 = vader_array_box_slots(_a65_slotarr->buf)[_a65_slotarr->offset + (size_t) l3];
        l9 = t4.payload.s;
        vader_array_t* _a66_slotarr = ((vader_array_t*) l25);
        VADER_ARRAY_RESOLVE_BUF(_a66_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a66_slotarr, l3)
        l8 = ((int32_t*) _a66_slotarr->buf->slots)[_a66_slotarr->offset + (size_t) l3];
        l35 = l9;
        l10 = l8;
        vader_array_t* _a67_slotarr = ((vader_array_t*) l13);
        VADER_ARRAY_RESOLVE_BUF(_a67_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a67_slotarr, l10)
        l20 = ((int32_t*) _a67_slotarr->buf->slots)[_a67_slotarr->offset + (size_t) l10];
        if ((l20 >= INT32_C(0))) {
            std_collections$MutableMap$std_core$IndexSet$set_at__string__i32(l4, l35, l20);
        }
        l3 = (l3 + INT64_C(1));
    }
    ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_function_index_by_mangle = l4;
    VADER_WRITE_BARRIER((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0);
    vader_array_t* _a68_arr = vader_array_new(22u, 0u, 7u, 338u);
    l4 = (void*) _a68_arr;
    vader_array_t* _a69_arr = vader_array_new(28u, 0u, 0u, 346u);
    l5 = (void*) _a69_arr;
    vader_array_t* _a70_arr = vader_array_new(22u, 0u, 7u, 338u);
    l6 = (void*) _a70_arr;
    vader_struct_std_collections$MutableMap__i32__Any___t* _a71_obj = (vader_struct_std_collections$MutableMap__i32__Any___t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i32__Any___t));
    vader_obj_header_init(_a71_obj, 460u);
    _a71_obj->f_ekeys = l4;
    _a71_obj->f_evals = l5;
    _a71_obj->f_index = l6;
    _a71_obj->f_mask = INT64_C(0);
    _a71_obj->f_grow_at = INT64_C(0);
    _a71_obj->f_size = INT64_C(0);
    _a71_obj->f_tombs = INT64_C(0);
    l4 = (void*) _a71_obj;
    l5 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_pinned_types_by_fn;
    l6 = ((vader_struct_std_collections$MutableMap__i32__i32___t*) l5)->f_ekeys;
    l25 = ((vader_struct_std_collections$MutableMap__i32__i32___t*) l5)->f_evals;
    l3 = INT64_C(0);
    l7 = ((vader_struct_std_collections$MutableMap__i32__i32___t*) l5)->f_size;
    while ((l3 < l7)) {
        vader_array_t* _a72_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a72_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a72_slotarr, l3)
        l8 = ((int32_t*) _a72_slotarr->buf->slots)[_a72_slotarr->offset + (size_t) l3];
        vader_array_t* _a73_slotarr = ((vader_array_t*) l25);
        VADER_ARRAY_RESOLVE_BUF(_a73_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a73_slotarr, l3)
        l5 = vader_array_ref_load_obj(_a73_slotarr->buf, _a73_slotarr->offset + (size_t) l3);
        l10 = l8;
        l26 = l5;
        l11 = ((int64_t) (int32_t) l10);
        if ((INT64_C(0) <= l11)) {
            l14 = ((vader_array_t*) l13)->length;
            l16 = (l11 < l14);
        } else {
            l16 = false;
        }
        if (!(!(l16))) {
            vader_array_t* _a74_slotarr = ((vader_array_t*) l13);
            VADER_ARRAY_RESOLVE_BUF(_a74_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a74_slotarr, l10)
            l20 = ((int32_t*) _a74_slotarr->buf->slots)[_a74_slotarr->offset + (size_t) l10];
            if (!((l20 < INT32_C(0)))) {
                l15 = std_collections$len__i32__Any(l4);
                l27 = std_collections$get_or_put__i32__i32__(l4, l20, l26);
                t3 = std_collections$len__i32__Any(l4);
                if (t3 == l15) {
                    l28 = l26;
                    l17 = ((vader_array_t*) l28)->length;
                    l18 = INT64_C(0);
                    while ((l18 < l17)) {
                        vader_array_t* _a75_slotarr = ((vader_array_t*) l28);
                        VADER_ARRAY_RESOLVE_BUF(_a75_slotarr)
                        l23 = ((int32_t*) _a75_slotarr->buf->slots)[_a75_slotarr->offset + (size_t) l18];
                        vader_array_push_i32((vader_array_t*) l27, l23);
                        l18 = (l18 + INT64_C(1));
                    }
                }
            }
        }
        l3 = (l3 + INT64_C(1));
    }
    ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_pinned_types_by_fn = l4;
    VADER_WRITE_BARRIER((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0);
    ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_functions = l12;
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
    vader_array_t* _a0_arr = vader_array_new(22u, 0u, 7u, 338u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(19u, 0u, 12u, 333u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(22u, 0u, 7u, 338u);
    l3 = (void*) _a2_arr;
    vader_struct_std_collections$MutableMap__i32__bool_t* _a3_obj = (vader_struct_std_collections$MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i32__bool_t));
    vader_obj_header_init(_a3_obj, 462u);
    _a3_obj->f_ekeys = l1;
    _a3_obj->f_evals = l2;
    _a3_obj->f_index = l3;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a3_obj;
    vader_struct_std_collections$MutableSet__i32_t* _a4_obj = (vader_struct_std_collections$MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableSet__i32_t));
    vader_obj_header_init(_a4_obj, 605u);
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
            if (l8.tag == 790u) {
                t0 = l8.payload.obj;
                l9 = ((vader_struct_vader_core_bytecode$GlobalGet_t*) t0)->f_index;
                std_collections$add__i32(l1, l9);
            } else if (l8.tag == 791u) {
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
    vader_array_t* _a7_arr = vader_array_new(22u, 0u, 7u, 338u);
    l2 = (void*) _a7_arr;
    vader_array_t* _a8_arr = vader_array_new(61u, 0u, 13u, 730u);
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
            if (l8.tag == 790u) {
                l12 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l11)->f_body;
                t0 = l8.payload.obj;
                l9 = ((vader_struct_vader_core_bytecode$GlobalGet_t*) t0)->f_index;
                vader_array_t* _a12_slotarr = ((vader_array_t*) l2);
                VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a12_slotarr, l9)
                t3 = ((int32_t*) _a12_slotarr->buf->slots)[_a12_slotarr->offset + (size_t) l9];
                vader_struct_vader_core_bytecode$GlobalGet_t* _a13_obj = (vader_struct_vader_core_bytecode$GlobalGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$GlobalGet_t));
                vader_obj_header_init(_a13_obj, 790u);
                _a13_obj->f_index = t3;
                l13 = (void*) _a13_obj;
                vader_array_t* _a14_slotarr = ((vader_array_t*) l12);
                VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a14_slotarr, l6)
                vader_array_ref_store(_a14_slotarr->buf, _a14_slotarr->offset + (size_t) l6, l13);
                VADER_WRITE_BARRIER(_a14_slotarr->buf);
            } else if (l8.tag == 791u) {
                l14 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l11)->f_body;
                t0 = l8.payload.obj;
                l10 = ((vader_struct_vader_core_bytecode$GlobalSet_t*) t0)->f_index;
                vader_array_t* _a15_slotarr = ((vader_array_t*) l2);
                VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a15_slotarr, l10)
                t3 = ((int32_t*) _a15_slotarr->buf->slots)[_a15_slotarr->offset + (size_t) l10];
                vader_struct_vader_core_bytecode$GlobalSet_t* _a16_obj = (vader_struct_vader_core_bytecode$GlobalSet_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$GlobalSet_t));
                vader_obj_header_init(_a16_obj, 791u);
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
    vader_array_t* _a0_arr = vader_array_new(22u, 0u, 7u, 338u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(19u, 0u, 12u, 333u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(22u, 0u, 7u, 338u);
    l3 = (void*) _a2_arr;
    vader_struct_std_collections$MutableMap__i32__bool_t* _a3_obj = (vader_struct_std_collections$MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i32__bool_t));
    vader_obj_header_init(_a3_obj, 462u);
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
            if (l8.tag == 761u) {
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
    vader_array_t* _a6_arr = vader_array_new(22u, 0u, 7u, 338u);
    l2 = (void*) _a6_arr;
    vader_array_t* _a7_arr = vader_array_new(62u, 0u, 13u, 731u);
    l3 = (void*) _a7_arr;
    l4 = INT64_C(0);
    l5 = ((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_imports)->length;
    while ((l4 < l5)) {
        l9 = ((int32_t) (int64_t) l4);
        t1 = std_collections$MutableMap$std_core$Index$at__i32__bool(l1, l9);
        if (t1.tag == 333u) {
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
            if (l8.tag == 761u) {
                l12 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l11)->f_body;
                t0 = l8.payload.obj;
                l9 = ((vader_struct_vader_core_bytecode$CallImport_t*) t0)->f_index;
                vader_array_t* _a11_slotarr = ((vader_array_t*) l2);
                VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l9)
                t3 = ((int32_t*) _a11_slotarr->buf->slots)[_a11_slotarr->offset + (size_t) l9];
                vader_struct_vader_core_bytecode$CallImport_t* _a12_obj = (vader_struct_vader_core_bytecode$CallImport_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$CallImport_t));
                vader_obj_header_init(_a12_obj, 761u);
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

static void vader_emit_bytecode$prune_unused_types(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l12 = NULL;
    void* l24 = NULL;
    int64_t l4, l5, l9, l10, l13, l14;
    int32_t l11, l15, l20;
    vader_box_t l16 = vader_box_null(), l17 = vader_box_null();
    vader_string_t l18 = 0;
    vader_string_t l19 = 0;
    vader_string_t l22 = 0;
    vader_string_t l23 = 0;
    bool l21;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    int32_t t2;
    bool t3;
    int64_t t4;
    vader_box_t* gc_roots[3] = { &l16, &l17, &t1 };
    void** gc_raw_roots[10] = { &l0, &l1, &l2, &l3, &l6, &l7, &l8, &l12, &l24, &t0 };
    vader_string_t* gc_atom_roots[4] = { &l18, &l19, &l22, &l23 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 10u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(22u, 0u, 7u, 338u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(19u, 0u, 12u, 333u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(22u, 0u, 7u, 338u);
    l3 = (void*) _a2_arr;
    vader_struct_std_collections$MutableMap__i32__bool_t* _a3_obj = (vader_struct_std_collections$MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i32__bool_t));
    vader_obj_header_init(_a3_obj, 462u);
    _a3_obj->f_ekeys = l1;
    _a3_obj->f_evals = l2;
    _a3_obj->f_index = l3;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a3_obj;
    vader_struct_std_collections$MutableSet__i32_t* _a4_obj = (vader_struct_std_collections$MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableSet__i32_t));
    vader_obj_header_init(_a4_obj, 605u);
    _a4_obj->f_inner = t0;
    l1 = (void*) _a4_obj;
    std_collections$add__i32(l1, INT32_C(0));
    vader_array_t* _a5_arr = vader_array_new(22u, 0u, 7u, 338u);
    l2 = (void*) _a5_arr;
    l3 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_functions;
    l4 = ((vader_array_t*) l3)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a6_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        l6 = vader_array_ref_load_obj(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l5);
        l7 = ((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l6)->f_signature)->f_result_types;
        vader_array_push_all((vader_array_t*) l2, (vader_array_t*) l7);
        l8 = ((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l6)->f_signature)->f_param_types;
        l9 = ((vader_array_t*) l8)->length;
        l10 = INT64_C(0);
        while ((l10 < l9)) {
            vader_array_t* _a7_slotarr = ((vader_array_t*) l8);
            VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
            l11 = ((int32_t*) _a7_slotarr->buf->slots)[_a7_slotarr->offset + (size_t) l10];
            vader_array_push_i32((vader_array_t*) l2, l11);
            l10 = (l10 + INT64_C(1));
        }
        l12 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l6)->f_body;
        l13 = ((vader_array_t*) l12)->length;
        l14 = INT64_C(0);
        while ((l14 < l13)) {
            vader_array_t* _a8_slotarr = ((vader_array_t*) l12);
            VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
            t1 = vader_array_ref_load_box(_a8_slotarr->buf, _a8_slotarr->offset + (size_t) l14);
            l15 = vader_emit_bytecode$type_index_of(t1);
            if ((l15 >= INT32_C(0))) {
                vader_array_push_i32((vader_array_t*) l2, l15);
            }
            l14 = (l14 + INT64_C(1));
        }
        l5 = (l5 + INT64_C(1));
    }
    l3 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_imports;
    l4 = ((vader_array_t*) l3)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a9_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
        l6 = vader_array_ref_load_obj(_a9_slotarr->buf, _a9_slotarr->offset + (size_t) l5);
        l7 = ((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcImport_t*) l6)->f_signature)->f_result_types;
        vader_array_push_all((vader_array_t*) l2, (vader_array_t*) l7);
        l8 = ((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcImport_t*) l6)->f_signature)->f_param_types;
        l9 = ((vader_array_t*) l8)->length;
        l10 = INT64_C(0);
        while ((l10 < l9)) {
            vader_array_t* _a10_slotarr = ((vader_array_t*) l8);
            VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
            l11 = ((int32_t*) _a10_slotarr->buf->slots)[_a10_slotarr->offset + (size_t) l10];
            vader_array_push_i32((vader_array_t*) l2, l11);
            l10 = (l10 + INT64_C(1));
        }
        l5 = (l5 + INT64_C(1));
    }
    l3 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_globals;
    l4 = ((vader_array_t*) l3)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a11_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
        t0 = vader_array_ref_load_obj(_a11_slotarr->buf, _a11_slotarr->offset + (size_t) l5);
        l11 = ((vader_struct_vader_core_bytecode$BcGlobal_t*) t0)->f_type_id;
        vader_array_push_i32((vader_array_t*) l2, l11);
        l5 = (l5 + INT64_C(1));
    }
    l3 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_pinned_types;
    l4 = ((vader_array_t*) l3)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a12_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
        l11 = ((int32_t*) _a12_slotarr->buf->slots)[_a12_slotarr->offset + (size_t) l5];
        vader_array_push_i32((vader_array_t*) l2, l11);
        l5 = (l5 + INT64_C(1));
    }
    l3 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_pinned_types_by_fn;
    l6 = ((vader_struct_std_collections$MutableMap__i32__i32___t*) l3)->f_ekeys;
    l7 = ((vader_struct_std_collections$MutableMap__i32__i32___t*) l3)->f_evals;
    l4 = INT64_C(0);
    l5 = ((vader_struct_std_collections$MutableMap__i32__i32___t*) l3)->f_size;
    while ((l4 < l5)) {
        vader_array_t* _a13_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a13_slotarr, l4)
        t2 = ((int32_t*) _a13_slotarr->buf->slots)[_a13_slotarr->offset + (size_t) l4];
        vader_array_t* _a14_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a14_slotarr, l4)
        l3 = vader_array_ref_load_obj(_a14_slotarr->buf, _a14_slotarr->offset + (size_t) l4);
        l9 = ((vader_array_t*) l3)->length;
        l10 = INT64_C(0);
        while ((l10 < l9)) {
            vader_array_t* _a15_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
            l11 = ((int32_t*) _a15_slotarr->buf->slots)[_a15_slotarr->offset + (size_t) l10];
            vader_array_push_i32((vader_array_t*) l2, l11);
            l10 = (l10 + INT64_C(1));
        }
        l4 = (l4 + INT64_C(1));
    }
    l4 = ((vader_array_t*) l2)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a16_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a16_slotarr)
        t2 = ((int32_t*) _a16_slotarr->buf->slots)[_a16_slotarr->offset + (size_t) l5];
        vader_emit_bytecode$visit_type(t2, l0, l1);
        l5 = (l5 + INT64_C(1));
    }
    l4 = std_collections$len__i32(l1);
    l5 = ((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_types)->length;
    if (l4 == l5) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l4 = ((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_types)->length;
    vader_array_t* _a17_arr = vader_array_new(22u, 0u, 7u, 338u);
    l2 = (void*) _a17_arr;
    vader_array_t* _a18_arr = vader_array_new(249u, 0u, 13u, 1701u);
    l3 = (void*) _a18_arr;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        l11 = ((int32_t) (int64_t) l5);
        t3 = std_collections$MutableSet$std_core$Contains$contains__i32(l1, l11);
        if (t3) {
            t4 = ((vader_array_t*) l3)->length;
            l15 = ((int32_t) (int64_t) t4);
            vader_array_push_i32((vader_array_t*) l2, l15);
            vader_array_t* _a19_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_types);
            VADER_ARRAY_RESOLVE_BUF(_a19_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a19_slotarr, l5)
            l16 = vader_array_ref_load_box(_a19_slotarr->buf, _a19_slotarr->offset + (size_t) l5);
            vader_array_push_ref((vader_array_t*) l3, l16.payload.obj);
        } else {
            vader_array_push_i32((vader_array_t*) l2, INT32_C(-1));
        }
        l5 = (l5 + INT64_C(1));
    }
    l1 = l3;
    vader_struct___lambda_env_vader_emit_bytecode_1_t* _a20_obj = (vader_struct___lambda_env_vader_emit_bytecode_1_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_emit_bytecode_1_t));
    vader_obj_header_init(_a20_obj, 361u);
    _a20_obj->f_cap_0 = l2;
    l3 = (void*) _a20_obj;
    vader_array_t* _a21_arr = vader_array_new(249u, 0u, 13u, 1701u);
    l6 = (void*) _a21_arr;
    l4 = ((vader_array_t*) l1)->length;
    vader_array_t* _a22_arr = vader_array_repeat((vader_array_t*) l6, (int64_t) l4);
    l6 = (void*) _a22_arr;
    l4 = ((vader_array_t*) l1)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a23_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a23_slotarr)
        l16 = vader_array_ref_load_box(_a23_slotarr->buf, _a23_slotarr->offset + (size_t) l5);
        l17 = __lambda_vader_emit_bytecode_0(l3, l16);
        vader_array_push_ref((vader_array_t*) l6, l17.payload.obj);
        l5 = (l5 + INT64_C(1));
    }
    ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_types = l6;
    VADER_WRITE_BARRIER((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0);
    vader_array_t* _a24_arr = vader_array_new(21u, 0u, 0u, 335u);
    l1 = (void*) _a24_arr;
    vader_array_t* _a25_arr = vader_array_new(22u, 0u, 7u, 338u);
    l3 = (void*) _a25_arr;
    vader_array_t* _a26_arr = vader_array_new(22u, 0u, 7u, 338u);
    l6 = (void*) _a26_arr;
    vader_struct_std_collections$MutableMap__string__i32_t* _a27_obj = (vader_struct_std_collections$MutableMap__string__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__string__i32_t));
    vader_obj_header_init(_a27_obj, 540u);
    _a27_obj->f_ekeys = l1;
    _a27_obj->f_evals = l3;
    _a27_obj->f_index = l6;
    _a27_obj->f_mask = INT64_C(0);
    _a27_obj->f_grow_at = INT64_C(0);
    _a27_obj->f_size = INT64_C(0);
    _a27_obj->f_tombs = INT64_C(0);
    l1 = (void*) _a27_obj;
    l3 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_type_key;
    l6 = ((vader_struct_std_collections$MutableMap__string__i32_t*) l3)->f_ekeys;
    l7 = ((vader_struct_std_collections$MutableMap__string__i32_t*) l3)->f_evals;
    l4 = INT64_C(0);
    l5 = ((vader_struct_std_collections$MutableMap__string__i32_t*) l3)->f_size;
    while ((l4 < l5)) {
        vader_array_t* _a28_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a28_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a28_slotarr, l4)
        t1 = vader_array_box_slots(_a28_slotarr->buf)[_a28_slotarr->offset + (size_t) l4];
        l18 = t1.payload.s;
        vader_array_t* _a29_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a29_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a29_slotarr, l4)
        l11 = ((int32_t*) _a29_slotarr->buf->slots)[_a29_slotarr->offset + (size_t) l4];
        l19 = l18;
        l15 = l11;
        l20 = vader_emit_bytecode$remap_idx(l2, l15);
        if ((l20 >= INT32_C(0))) {
            std_collections$MutableMap$std_core$IndexSet$set_at__string__i32(l1, l19, l20);
        }
        l4 = (l4 + INT64_C(1));
    }
    ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_type_key = l1;
    VADER_WRITE_BARRIER((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0);
    l1 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_functions;
    l4 = ((vader_array_t*) l1)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a30_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a30_slotarr)
        l3 = vader_array_ref_load_obj(_a30_slotarr->buf, _a30_slotarr->offset + (size_t) l5);
        l6 = vader_emit_bytecode$remap_signature(((vader_struct_vader_core_bytecode$BcFunction_t*) l3)->f_signature, l2);
        ((vader_struct_vader_core_bytecode$BcFunction_t*) l3)->f_signature = l6;
        VADER_WRITE_BARRIER((vader_struct_vader_core_bytecode$BcFunction_t*) l3);
        l9 = INT64_C(0);
        l10 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l3)->f_body)->length;
        while ((l9 < l10)) {
            l7 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l3)->f_body;
            vader_array_t* _a31_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l3)->f_body);
            VADER_ARRAY_RESOLVE_BUF(_a31_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a31_slotarr, l9)
            t1 = vader_array_ref_load_box(_a31_slotarr->buf, _a31_slotarr->offset + (size_t) l9);
            l16 = vader_emit_bytecode$remap_type_in_op(t1, l2);
            vader_array_t* _a32_slotarr = ((vader_array_t*) l7);
            VADER_ARRAY_RESOLVE_BUF(_a32_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a32_slotarr, l9)
            vader_array_ref_store(_a32_slotarr->buf, _a32_slotarr->offset + (size_t) l9, l16.payload.obj);
            VADER_WRITE_BARRIER(_a32_slotarr->buf);
            l9 = (l9 + INT64_C(1));
        }
        l5 = (l5 + INT64_C(1));
    }
    vader_array_t* _a33_arr = vader_array_new(62u, 0u, 13u, 731u);
    l1 = (void*) _a33_arr;
    l4 = ((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_imports)->length;
    vader_array_t* _a34_arr = vader_array_repeat((vader_array_t*) l1, (int64_t) l4);
    l1 = (void*) _a34_arr;
    l3 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_imports;
    l4 = ((vader_array_t*) l3)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a35_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a35_slotarr)
        l6 = vader_array_ref_load_obj(_a35_slotarr->buf, _a35_slotarr->offset + (size_t) l5);
        l7 = l6;
        l18 = ((vader_struct_vader_core_bytecode$BcImport_t*) l7)->f_extern_name;
        l19 = ((vader_struct_vader_core_bytecode$BcImport_t*) l7)->f_mangled_name;
        l8 = vader_emit_bytecode$remap_signature(((vader_struct_vader_core_bytecode$BcImport_t*) l6)->f_signature, l2);
        l21 = ((vader_struct_vader_core_bytecode$BcImport_t*) l7)->f_is_extern;
        l22 = ((vader_struct_vader_core_bytecode$BcImport_t*) l7)->f_c_header;
        l16 = ((vader_struct_vader_core_bytecode$BcImport_t*) l7)->f_library;
        l11 = ((vader_struct_vader_core_bytecode$BcImport_t*) l7)->f_c_variadic_fixed;
        l12 = ((vader_struct_vader_core_bytecode$BcImport_t*) l7)->f_param_c_types;
        l23 = ((vader_struct_vader_core_bytecode$BcImport_t*) l7)->f_result_c_type;
        vader_struct_vader_core_bytecode$BcImport_t* _a36_obj = (vader_struct_vader_core_bytecode$BcImport_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcImport_t));
        vader_obj_header_init(_a36_obj, 731u);
        _a36_obj->f_extern_name = l18;
        _a36_obj->f_mangled_name = l19;
        _a36_obj->f_signature = l8;
        _a36_obj->f_is_extern = l21;
        _a36_obj->f_c_header = l22;
        _a36_obj->f_library = l16;
        _a36_obj->f_c_variadic_fixed = l11;
        _a36_obj->f_param_c_types = l12;
        _a36_obj->f_result_c_type = l23;
        l24 = (void*) _a36_obj;
        vader_array_push_ref((vader_array_t*) l1, l24);
        l5 = (l5 + INT64_C(1));
    }
    ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_imports = l1;
    VADER_WRITE_BARRIER((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0);
    l1 = vader_emit_bytecode$remap_globals(((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_globals, l2);
    ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0)->f_globals = l1;
    VADER_WRITE_BARRIER((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l0);
    { vader_gc_top = gc_frame.prev; return; }
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
        vader_array_push_scalar((vader_array_t*) l0, vader_box_string(335u, l3));
        vader_array_push_i32((vader_array_t*) l1, l4);
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
    vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l2] = vader_box_string(335u, l3);
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
    if (l1.tag == 918u) {
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
    if (!(l1.tag == 910u)) {
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
                l7 = concat_5(1683u, l0, 1257u, l6, 1289u);
                l8 = vader_core_types$display_type(l5);
                l9 = concat_3(2037u, l8, 1038u);
                t2 = concat_3(l7, 1544u, l9);
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
    vader_array_t* _a0_arr = vader_array_new(251u, 1u, 13u, 1735u);
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
    vader_struct___lambda_env_vader_emit_bytecode_3_t* _a0_obj = (vader_struct___lambda_env_vader_emit_bytecode_3_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_emit_bytecode_3_t));
    vader_obj_header_init(_a0_obj, 362u);
    _a0_obj->f_cap_0 = l1;
    l3 = (void*) _a0_obj;
    vader_array_t* _a1_arr = vader_array_new(61u, 0u, 13u, 730u);
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
        l8 = __lambda_vader_emit_bytecode_2(l3, l7);
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
    if (!(l0.tag == 718u)) {
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
        vader_obj_header_init(_a1_obj, 718u);
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
    vader_obj_header_init(_a0_obj, 736u);
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
    if ((l0.tag == 734u || l0.tag == 735u)) {
        l2 = l0;
        { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 738u) {
        vader_array_t* _a0_arr = vader_array_new(59u, 0u, 13u, 727u);
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
            vader_obj_header_init(_a2_obj, 727u);
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
        vader_obj_header_init(_a3_obj, 738u);
        _a3_obj->f_name = l8;
        _a3_obj->f_fields = l3;
        _a3_obj->f_c_name = l12;
        _a3_obj->f_symbol_id = l9;
        t0 = (void*) _a3_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 725u) {
        t0 = l0.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$BcArray_t*) t0)->f_element;
        t1 = vader_emit_bytecode$remap_idx(l1, l9);
        vader_struct_vader_core_bytecode$BcArray_t* _a4_obj = (vader_struct_vader_core_bytecode$BcArray_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcArray_t));
        vader_obj_header_init(_a4_obj, 725u);
        _a4_obj->f_element = t1;
        t0 = (void*) _a4_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 739u) {
        vader_array_t* _a5_arr = vader_array_new(22u, 0u, 7u, 338u);
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
        vader_obj_header_init(_a7_obj, 739u);
        _a7_obj->f_variants = l3;
        t0 = (void*) _a7_obj;
        l2 = vader_ref_box(t0);
    } else {
        if (!(l0.tag == 728u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        vader_array_t* _a8_arr = vader_array_new(22u, 0u, 7u, 338u);
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
        vader_obj_header_init(_a10_obj, 728u);
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
    if (l0.tag == 868u) {
        l3 = l0.payload.obj;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_core_bytecode$StructNew_t*) t0)->f_type_id;
        l4 = vader_emit_bytecode$remap_idx(l1, l4);
        l5 = ((vader_struct_vader_core_bytecode$StructNew_t*) l3)->f_stack;
        vader_struct_vader_core_bytecode$StructNew_t* _a0_obj = (vader_struct_vader_core_bytecode$StructNew_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$StructNew_t));
        vader_obj_header_init(_a0_obj, 868u);
        _a0_obj->f_type_id = l4;
        _a0_obj->f_stack = l5;
        t0 = (void*) _a0_obj;
        l2 = vader_ref_box(t0);
        { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 867u) {
        l3 = l0.payload.obj;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_core_bytecode$StructGet_t*) t0)->f_type_id;
        l4 = vader_emit_bytecode$remap_idx(l1, l4);
        l6 = ((vader_struct_vader_core_bytecode$StructGet_t*) l3)->f_field_index;
        vader_struct_vader_core_bytecode$StructGet_t* _a1_obj = (vader_struct_vader_core_bytecode$StructGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$StructGet_t));
        vader_obj_header_init(_a1_obj, 867u);
        _a1_obj->f_type_id = l4;
        _a1_obj->f_field_index = l6;
        t0 = (void*) _a1_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 869u) {
        l3 = l0.payload.obj;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_core_bytecode$StructSet_t*) t0)->f_type_id;
        l4 = vader_emit_bytecode$remap_idx(l1, l4);
        l6 = ((vader_struct_vader_core_bytecode$StructSet_t*) l3)->f_field_index;
        l5 = ((vader_struct_vader_core_bytecode$StructSet_t*) l3)->f_stack;
        vader_struct_vader_core_bytecode$StructSet_t* _a2_obj = (vader_struct_vader_core_bytecode$StructSet_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$StructSet_t));
        vader_obj_header_init(_a2_obj, 869u);
        _a2_obj->f_type_id = l4;
        _a2_obj->f_field_index = l6;
        _a2_obj->f_stack = l5;
        t0 = (void*) _a2_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 884u) {
        l3 = l0.payload.obj;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_core_bytecode$UnionFieldGet_t*) t0)->f_type_id;
        l4 = vader_emit_bytecode$remap_idx(l1, l4);
        l6 = ((vader_struct_vader_core_bytecode$UnionFieldGet_t*) l3)->f_field_index;
        vader_struct_vader_core_bytecode$UnionFieldGet_t* _a3_obj = (vader_struct_vader_core_bytecode$UnionFieldGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$UnionFieldGet_t));
        vader_obj_header_init(_a3_obj, 884u);
        _a3_obj->f_type_id = l4;
        _a3_obj->f_field_index = l6;
        t0 = (void*) _a3_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 885u) {
        l3 = l0.payload.obj;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_core_bytecode$UnionFieldSet_t*) t0)->f_type_id;
        l4 = vader_emit_bytecode$remap_idx(l1, l4);
        l6 = ((vader_struct_vader_core_bytecode$UnionFieldSet_t*) l3)->f_field_index;
        vader_struct_vader_core_bytecode$UnionFieldSet_t* _a4_obj = (vader_struct_vader_core_bytecode$UnionFieldSet_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$UnionFieldSet_t));
        vader_obj_header_init(_a4_obj, 885u);
        _a4_obj->f_type_id = l4;
        _a4_obj->f_field_index = l6;
        t0 = (void*) _a4_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 717u) {
        l3 = l0.payload.obj;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_core_bytecode$ArrayNew_t*) t0)->f_type_id;
        l4 = vader_emit_bytecode$remap_idx(l1, l4);
        l6 = ((vader_struct_vader_core_bytecode$ArrayNew_t*) l3)->f_length;
        vader_struct_vader_core_bytecode$ArrayNew_t* _a5_obj = (vader_struct_vader_core_bytecode$ArrayNew_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$ArrayNew_t));
        vader_obj_header_init(_a5_obj, 717u);
        _a5_obj->f_type_id = l4;
        _a5_obj->f_length = l6;
        t0 = (void*) _a5_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 715u) {
        l3 = l0.payload.obj;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_core_bytecode$ArrayGet_t*) t0)->f_type_id;
        l4 = vader_emit_bytecode$remap_idx(l1, l4);
        l5 = ((vader_struct_vader_core_bytecode$ArrayGet_t*) l3)->f_bounds_safe;
        vader_struct_vader_core_bytecode$ArrayGet_t* _a6_obj = (vader_struct_vader_core_bytecode$ArrayGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$ArrayGet_t));
        vader_obj_header_init(_a6_obj, 715u);
        _a6_obj->f_type_id = l4;
        _a6_obj->f_bounds_safe = l5;
        t0 = (void*) _a6_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 722u) {
        l3 = l0.payload.obj;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_core_bytecode$ArraySet_t*) t0)->f_type_id;
        l4 = vader_emit_bytecode$remap_idx(l1, l4);
        l5 = ((vader_struct_vader_core_bytecode$ArraySet_t*) l3)->f_bounds_safe;
        vader_struct_vader_core_bytecode$ArraySet_t* _a7_obj = (vader_struct_vader_core_bytecode$ArraySet_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$ArraySet_t));
        vader_obj_header_init(_a7_obj, 722u);
        _a7_obj->f_type_id = l4;
        _a7_obj->f_bounds_safe = l5;
        t0 = (void*) _a7_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 718u) {
        l3 = l0.payload.obj;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_core_bytecode$ArrayPush_t*) t0)->f_type_id;
        l4 = vader_emit_bytecode$remap_idx(l1, l4);
        l6 = ((vader_struct_vader_core_bytecode$ArrayPush_t*) l3)->f_cache_slot;
        vader_struct_vader_core_bytecode$ArrayPush_t* _a8_obj = (vader_struct_vader_core_bytecode$ArrayPush_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$ArrayPush_t));
        vader_obj_header_init(_a8_obj, 718u);
        _a8_obj->f_type_id = l4;
        _a8_obj->f_cache_slot = l6;
        t0 = (void*) _a8_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 870u) {
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_core_bytecode$TypeCheck_t*) t0)->f_type_id;
        t1 = vader_emit_bytecode$remap_idx(l1, l4);
        vader_struct_vader_core_bytecode$TypeCheck_t* _a9_obj = (vader_struct_vader_core_bytecode$TypeCheck_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$TypeCheck_t));
        vader_obj_header_init(_a9_obj, 870u);
        _a9_obj->f_type_id = t1;
        t0 = (void*) _a9_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 871u) {
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_core_bytecode$TypeConst_t*) t0)->f_type_id;
        t1 = vader_emit_bytecode$remap_idx(l1, l4);
        vader_struct_vader_core_bytecode$TypeConst_t* _a10_obj = (vader_struct_vader_core_bytecode$TypeConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$TypeConst_t));
        vader_obj_header_init(_a10_obj, 871u);
        _a10_obj->f_type_id = t1;
        t0 = (void*) _a10_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 762u) {
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_core_bytecode$CallIndirect_t*) t0)->f_type_id;
        t1 = vader_emit_bytecode$remap_idx(l1, l4);
        vader_struct_vader_core_bytecode$CallIndirect_t* _a11_obj = (vader_struct_vader_core_bytecode$CallIndirect_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$CallIndirect_t));
        vader_obj_header_init(_a11_obj, 762u);
        _a11_obj->f_type_id = t1;
        t0 = (void*) _a11_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 846u) {
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_core_bytecode$MakeClosure_t*) t0)->f_function_index;
        t0 = l0.payload.obj;
        l6 = ((vader_struct_vader_core_bytecode$MakeClosure_t*) t0)->f_env_type_id;
        l6 = vader_emit_bytecode$remap_idx(l1, l6);
        vader_struct_vader_core_bytecode$MakeClosure_t* _a12_obj = (vader_struct_vader_core_bytecode$MakeClosure_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$MakeClosure_t));
        vader_obj_header_init(_a12_obj, 846u);
        _a12_obj->f_function_index = l4;
        _a12_obj->f_env_type_id = l6;
        t0 = (void*) _a12_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 789u) {
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_core_bytecode$FnRef_t*) t0)->f_function_index;
        t0 = l0.payload.obj;
        l6 = ((vader_struct_vader_core_bytecode$FnRef_t*) t0)->f_type_id;
        l6 = vader_emit_bytecode$remap_idx(l1, l6);
        vader_struct_vader_core_bytecode$FnRef_t* _a13_obj = (vader_struct_vader_core_bytecode$FnRef_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$FnRef_t));
        vader_obj_header_init(_a13_obj, 789u);
        _a13_obj->f_function_index = l4;
        _a13_obj->f_type_id = l6;
        t0 = (void*) _a13_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 841u) {
        l3 = l0.payload.obj;
        l4 = ((vader_struct_vader_core_bytecode$LocalField_t*) l3)->f_slot;
        t0 = l0.payload.obj;
        l6 = ((vader_struct_vader_core_bytecode$LocalField_t*) t0)->f_type_id;
        l6 = vader_emit_bytecode$remap_idx(l1, l6);
        l7 = ((vader_struct_vader_core_bytecode$LocalField_t*) l3)->f_field_index;
        vader_struct_vader_core_bytecode$LocalField_t* _a14_obj = (vader_struct_vader_core_bytecode$LocalField_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$LocalField_t));
        vader_obj_header_init(_a14_obj, 841u);
        _a14_obj->f_slot = l4;
        _a14_obj->f_type_id = l6;
        _a14_obj->f_field_index = l7;
        t0 = (void*) _a14_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 723u) {
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_core_bytecode$ArraySlice_t*) t0)->f_type_id;
        t1 = vader_emit_bytecode$remap_idx(l1, l4);
        vader_struct_vader_core_bytecode$ArraySlice_t* _a15_obj = (vader_struct_vader_core_bytecode$ArraySlice_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$ArraySlice_t));
        vader_obj_header_init(_a15_obj, 723u);
        _a15_obj->f_type_id = t1;
        t0 = (void*) _a15_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 849u) {
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_core_bytecode$RefCast_t*) t0)->f_type_id;
        t1 = vader_emit_bytecode$remap_idx(l1, l4);
        vader_struct_vader_core_bytecode$RefCast_t* _a16_obj = (vader_struct_vader_core_bytecode$RefCast_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$RefCast_t));
        vader_obj_header_init(_a16_obj, 849u);
        _a16_obj->f_type_id = t1;
        t0 = (void*) _a16_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 852u) {
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_core_bytecode$Retag_t*) t0)->f_type_id;
        t1 = vader_emit_bytecode$remap_idx(l1, l4);
        vader_struct_vader_core_bytecode$Retag_t* _a17_obj = (vader_struct_vader_core_bytecode$Retag_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$Retag_t));
        vader_obj_header_init(_a17_obj, 852u);
        _a17_obj->f_type_id = t1;
        t0 = (void*) _a17_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 767u) {
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_core_bytecode$DataConst_t*) t0)->f_pool_index;
        t0 = l0.payload.obj;
        l6 = ((vader_struct_vader_core_bytecode$DataConst_t*) t0)->f_type_id;
        l6 = vader_emit_bytecode$remap_idx(l1, l6);
        vader_struct_vader_core_bytecode$DataConst_t* _a18_obj = (vader_struct_vader_core_bytecode$DataConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$DataConst_t));
        vader_obj_header_init(_a18_obj, 767u);
        _a18_obj->f_pool_index = l4;
        _a18_obj->f_type_id = l6;
        t0 = (void*) _a18_obj;
        l2 = vader_ref_box(t0);
    } else {
        if (!((l0.tag == 713u || l0.tag == 714u || l0.tag == 716u || l0.tag == 719u || l0.tag == 720u || l0.tag == 721u || l0.tag == 744u || l0.tag == 745u || l0.tag == 746u || l0.tag == 747u || l0.tag == 748u || l0.tag == 749u || l0.tag == 750u || l0.tag == 751u || l0.tag == 752u || l0.tag == 753u || l0.tag == 754u || l0.tag == 755u || l0.tag == 756u || l0.tag == 757u || l0.tag == 760u || l0.tag == 761u || l0.tag == 763u || l0.tag == 764u || l0.tag == 765u || l0.tag == 766u || l0.tag == 769u || l0.tag == 770u || l0.tag == 771u || l0.tag == 772u || l0.tag == 773u || l0.tag == 774u || l0.tag == 775u || l0.tag == 776u || l0.tag == 777u || l0.tag == 778u || l0.tag == 779u || l0.tag == 780u || l0.tag == 781u || l0.tag == 782u || l0.tag == 783u || l0.tag == 784u || l0.tag == 785u || l0.tag == 786u || l0.tag == 787u || l0.tag == 788u || l0.tag == 790u || l0.tag == 791u || l0.tag == 792u || l0.tag == 793u || l0.tag == 794u || l0.tag == 795u || l0.tag == 796u || l0.tag == 797u || l0.tag == 798u || l0.tag == 799u || l0.tag == 800u || l0.tag == 801u || l0.tag == 802u || l0.tag == 803u || l0.tag == 804u || l0.tag == 805u || l0.tag == 806u || l0.tag == 807u || l0.tag == 808u || l0.tag == 809u || l0.tag == 810u || l0.tag == 811u || l0.tag == 812u || l0.tag == 813u || l0.tag == 814u || l0.tag == 815u || l0.tag == 816u || l0.tag == 817u || l0.tag == 818u || l0.tag == 819u || l0.tag == 820u || l0.tag == 821u || l0.tag == 822u || l0.tag == 823u || l0.tag == 824u || l0.tag == 825u || l0.tag == 826u || l0.tag == 827u || l0.tag == 828u || l0.tag == 829u || l0.tag == 830u || l0.tag == 831u || l0.tag == 832u || l0.tag == 834u || l0.tag == 835u || l0.tag == 836u || l0.tag == 837u || l0.tag == 838u || l0.tag == 839u || l0.tag == 840u || l0.tag == 842u || l0.tag == 843u || l0.tag == 844u || l0.tag == 845u || l0.tag == 847u || l0.tag == 848u || l0.tag == 850u || l0.tag == 851u || l0.tag == 853u || l0.tag == 854u || l0.tag == 855u || l0.tag == 856u || l0.tag == 857u || l0.tag == 858u || l0.tag == 859u || l0.tag == 860u || l0.tag == 861u || l0.tag == 862u || l0.tag == 863u || l0.tag == 864u || l0.tag == 865u || l0.tag == 866u || l0.tag == 872u || l0.tag == 873u || l0.tag == 874u || l0.tag == 875u || l0.tag == 876u || l0.tag == 877u || l0.tag == 878u || l0.tag == 879u || l0.tag == 880u || l0.tag == 881u || l0.tag == 882u || l0.tag == 883u || l0.tag == 886u || l0.tag == 887u))) {
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
    vader_struct___lambda_env_vader_emit_bytecode_5_t* _a0_obj = (vader_struct___lambda_env_vader_emit_bytecode_5_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_emit_bytecode_5_t));
    vader_obj_header_init(_a0_obj, 363u);
    _a0_obj->f_cap_0 = l0;
    l3 = (void*) _a0_obj;
    vader_array_t* _a1_arr = vader_array_new(22u, 0u, 7u, 338u);
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
            l8 = __lambda_vader_emit_bytecode_4(l3, l7);
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
    vader_array_t* _a0_arr = vader_array_new(252u, 0u, 13u, 1776u);
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
    vader_obj_header_init(_a1_obj, 731u);
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
    if (l3.tag == 892u) {
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
    vader_box_t* gc_roots[1] = { &l3 };
    void** gc_raw_roots[10] = { &l0, &l1, &l2, &l4, &l6, &l7, &l8, &l9, &l12, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l10 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 10u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_params;
    l3 = ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_return_type;
    l4 = ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_scalarised_results;
    l2 = vader_emit_bytecode$build_cfg_signature(l2, l3, l4, l1);
    t0 = ((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l1)->f_functions)->length;
    l5 = ((int32_t) (int64_t) t0);
    vader_array_t* _a0_arr = vader_array_new(247u, 0u, 13u, 1677u);
    l4 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(251u, 0u, 13u, 1735u);
    l6 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(22u, 0u, 7u, 338u);
    l7 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(63u, 0u, 13u, 732u);
    l8 = (void*) _a3_arr;
    l9 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l1)->f_functions;
    l10 = ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_mangled;
    l11 = ((vader_struct_vader_core_mono$MonoEntry_t*) ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_origin)->f_is_main;
    vader_array_t* _a4_arr = vader_array_new(22u, 0u, 7u, 338u);
    l12 = (void*) _a4_arr;
    vader_struct_vader_core_bytecode$BcFunction_t* _a5_obj = (vader_struct_vader_core_bytecode$BcFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcFunction_t));
    vader_obj_header_init(_a5_obj, 729u);
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
    if (l3.tag == 892u) {
        l2 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l1)->f_function_index_by_symbol_id;
        t1 = l3.payload.obj;
        l13 = ((vader_struct_vader_core_symbol$Symbol_t*) t1)->f_id;
        std_collections$MutableMap$std_core$IndexSet$set_at__i32__i32(l2, l13, l5);
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
    if (l3.tag == 892u) {
        t0 = l3.payload.obj;
        l2 = ((vader_struct_vader_core_symbol$Symbol_t*) t0)->f_id;
    }
    if (l3.tag == 892u) {
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
            if (t2.tag == 738u) {
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
            vader_obj_header_init(_a1_obj, 734u);
            _a1_obj->f_trait_name = t3;
            l5 = (void*) _a1_obj;
            vader_array_push_ref((vader_array_t*) l4, l5);
        }
        vader_array_t* _a2_arr = vader_array_new(59u, 0u, 13u, 727u);
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
            vader_obj_header_init(_a5_obj, 727u);
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
        vader_obj_header_init(_a6_obj, 738u);
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
    vader_obj_header_init(_a8_obj, 734u);
    _a8_obj->f_trait_name = t3;
    l5 = (void*) _a8_obj;
    vader_array_push_ref((vader_array_t*) l4, l5);
    vader_array_t* _a9_arr = vader_array_new(59u, 0u, 13u, 727u);
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
        vader_obj_header_init(_a12_obj, 727u);
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
    vader_obj_header_init(_a13_obj, 738u);
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
    l2 = ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_project;
    l3 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l2)->f_import_index_by_symbol_id;
    l4 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_midir$InstrCall_t*) l1)->f_callee)->f_id;
    l5 = std_collections$MutableMap$std_core$Index$at__i32__i32(l3, l4);
    if (l5.tag == 338u) {
        t0 = ((int32_t) l5.payload.i);
        l5 = vader_box_i32(338u, t0);
    } else {
        l3 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l2)->f_import_index_by_mangle;
        l6 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_midir$InstrCall_t*) l1)->f_callee)->f_name;
        l5 = std_collections$MutableMap$std_core$Index$at__string__i32(l3, l6);
    }
    if (l5.tag == 338u) {
        l4 = ((int32_t) l5.payload.i);
        l3 = vader_emit_bytecode$import_call_target(l2, l4);
        if (!(((vader_struct_vader_emit_bytecode$DirectCallTarget_t*) l3)->f_op.tag == 761u)) {
            { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    l7 = vader_emit_bytecode$resolve_fn_index(((vader_struct_vader_midir$InstrCall_t*) l1)->f_callee, l2);
    if (!(l7.tag == 0u)) {
        t0 = ((int32_t) l7.payload.i);
        vader_struct_vader_core_bytecode$Call_t* _a0_obj = (vader_struct_vader_core_bytecode$Call_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$Call_t));
        vader_obj_header_init(_a0_obj, 760u);
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
        vader_obj_header_init(_a2_obj, 921u);
        _a2_obj->f_op = vader_ref_box(l3);
        _a2_obj->f_signature = l8;
        t1 = (void*) _a2_obj;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l5.tag == 338u)) {
        l6 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_midir$InstrCall_t*) l1)->f_callee)->f_name;
        l9 = ((vader_struct_vader_midir$CFGFunction_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_fn_)->f_mangled;
        l10 = vader_host_std_core$byte_len(l6);
        l11 = vader_host_std_core$byte_len(l9);
        l10 = (l10 + l11);
        l3 = (void*) vader_buffer_new((size_t) (INT64_C(102) + l10));
        l10 = INT64_C(0);
        l10 = std_core$write_string_at(l3, l10, 1868u);
        l10 = std_core$write_string_at(l3, l10, l6);
        l10 = std_core$write_string_at(l3, l10, 287u);
        t0 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_midir$InstrCall_t*) l1)->f_callee)->f_id;
        l11 = ((int64_t) (int32_t) t0);
        l10 = std_core$write_int(l3, l10, l11);
        l10 = std_core$write_string_at(l3, l10, 332u);
        l10 = std_core$write_string_at(l3, l10, l9);
        l10 = std_core$write_string_at(l3, l10, 288u);
        t2 = std_core$finish_buffer(l3, l10);
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
        return vader_box_i32(338u, t0);
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
    if (!(l1.tag == 650u)) {
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
    if (l1.tag == 1370u) {
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir$TermBranch_t*) t0)->f_span;
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_midir$TermBranch_t*) t0)->f_target;
        l4 = vader_emit_bytecode$destination(l0, l4);
        vader_struct_vader_midir$TermBranch_t* _a0_obj = (vader_struct_vader_midir$TermBranch_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$TermBranch_t));
        vader_obj_header_init(_a0_obj, 1370u);
        _a0_obj->f_span = l3;
        _a0_obj->f_target = l4;
        t0 = (void*) _a0_obj;
        l2 = vader_ref_box(t0);
        { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 1371u) {
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
        vader_obj_header_init(_a1_obj, 1371u);
        _a1_obj->f_span = l5;
        _a1_obj->f_cond = l4;
        _a1_obj->f_then_block = l6;
        _a1_obj->f_else_block = l7;
        t0 = (void*) _a1_obj;
        l2 = vader_ref_box(t0);
    } else {
        if (!((l1.tag == 1372u || l1.tag == 1373u))) {
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
    vader_array_t* _a0_arr = vader_array_new(247u, 0u, 13u, 1677u);
    l3 = (void*) _a0_arr;
    l4 = INT64_C(0);
    vader_array_t* _a1_arr = vader_array_new(22u, 0u, 7u, 338u);
    l5 = (void*) _a1_arr;
    if ((INT64_C(0) < l2)) {
        l6 = l2;
    } else {
        l6 = INT64_C(0);
    }
    vader_array_t* _a2_arr = vader_array_repeat((vader_array_t*) l5, (int64_t) l6);
    l5 = (void*) _a2_arr;
    l6 = INT64_C(0);
    vader_array_t* _pc26_hdr = (vader_array_t*) l5;
    size_t _pc26_len = _pc26_hdr->length;
    size_t _pc26_cap = (_pc26_hdr->offset == 0 && !vader_array_is_borrowed(_pc26_hdr) && _pc26_hdr->length >= _pc26_hdr->buf->length) ? _pc26_hdr->capacity : (size_t) 0;
    void* _pc26_slots = _pc26_hdr->buf->slots;
    for (;;) {
        if ((l6 < l2)) {
            if (VADER_LIKELY(_pc26_len < _pc26_cap)) {
                ((int32_t*) _pc26_slots)[_pc26_len] = (int32_t) (INT32_C(-1));
                _pc26_len += 1;
            } else {
                _pc26_hdr->length = _pc26_len;
                if (_pc26_hdr->buf->length < _pc26_len) {
                    _pc26_hdr->buf->length = _pc26_len;
                }
                vader_array_push_i32((vader_array_t*) l5, INT32_C(-1));
                _pc26_hdr = (vader_array_t*) l5;
                _pc26_len = _pc26_hdr->length;
                _pc26_cap = (_pc26_hdr->offset == 0 && !vader_array_is_borrowed(_pc26_hdr) && _pc26_hdr->length >= _pc26_hdr->buf->length) ? _pc26_hdr->capacity : (size_t) 0;
                _pc26_slots = _pc26_hdr->buf->slots;
            }
            l6 = (l6 + INT64_C(1));
            continue;
        }
        _pc26_hdr->length = _pc26_len;
        if (_pc26_hdr->buf->length < _pc26_len) {
            _pc26_hdr->buf->length = _pc26_len;
        }
        break;
    }
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
    vader_obj_header_init(_a7_obj, 920u);
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
    vader_array_t* _a0_arr = vader_array_new(22u, 0u, 7u, 338u);
    l6 = (void*) _a0_arr;
    if ((INT64_C(0) < l4)) {
        l5 = l4;
    } else {
        l5 = INT64_C(0);
    }
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l6, (int64_t) l5);
    l6 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(22u, 0u, 7u, 338u);
    l7 = (void*) _a2_arr;
    if ((INT64_C(0) < l4)) {
        l5 = l4;
    } else {
        l5 = INT64_C(0);
    }
    vader_array_t* _a3_arr = vader_array_repeat((vader_array_t*) l7, (int64_t) l5);
    l7 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_new(22u, 0u, 7u, 338u);
    l8 = (void*) _a4_arr;
    if ((INT64_C(0) < l4)) {
        l5 = l4;
    } else {
        l5 = INT64_C(0);
    }
    vader_array_t* _a5_arr = vader_array_repeat((vader_array_t*) l8, (int64_t) l5);
    l8 = (void*) _a5_arr;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_push_i32((vader_array_t*) l6, INT32_C(0));
        vader_array_push_i32((vader_array_t*) l7, INT32_C(0));
        vader_array_push_i32((vader_array_t*) l8, INT32_C(0));
        l5 = (l5 + INT64_C(1));
    }
    l9 = l2;
    l4 = ((vader_array_t*) l9)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a6_slotarr = ((vader_array_t*) l9);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        l10 = vader_array_ref_load_box(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l5);
        if (l10.tag == 843u) {
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
        if (l10.tag == 842u) {
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
        if (l10.tag == 844u) {
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
    vader_array_t* _a10_arr = vader_array_new(247u, 0u, 13u, 1677u);
    l17 = (void*) _a10_arr;
    l4 = INT64_C(0);
    vader_array_t* _a11_arr = vader_array_new(22u, 0u, 7u, 338u);
    l18 = (void*) _a11_arr;
    if ((INT64_C(0) < l3)) {
        l5 = l3;
    } else {
        l5 = INT64_C(0);
    }
    vader_array_t* _a12_arr = vader_array_repeat((vader_array_t*) l18, (int64_t) l5);
    l18 = (void*) _a12_arr;
    l5 = INT64_C(0);
    vader_array_t* _pc195_hdr = (vader_array_t*) l18;
    size_t _pc195_len = _pc195_hdr->length;
    size_t _pc195_cap = (_pc195_hdr->offset == 0 && !vader_array_is_borrowed(_pc195_hdr) && _pc195_hdr->length >= _pc195_hdr->buf->length) ? _pc195_hdr->capacity : (size_t) 0;
    void* _pc195_slots = _pc195_hdr->buf->slots;
    for (;;) {
        if ((l5 < l3)) {
            if (VADER_LIKELY(_pc195_len < _pc195_cap)) {
                ((int32_t*) _pc195_slots)[_pc195_len] = (int32_t) (INT32_C(-1));
                _pc195_len += 1;
            } else {
                _pc195_hdr->length = _pc195_len;
                if (_pc195_hdr->buf->length < _pc195_len) {
                    _pc195_hdr->buf->length = _pc195_len;
                }
                vader_array_push_i32((vader_array_t*) l18, INT32_C(-1));
                _pc195_hdr = (vader_array_t*) l18;
                _pc195_len = _pc195_hdr->length;
                _pc195_cap = (_pc195_hdr->offset == 0 && !vader_array_is_borrowed(_pc195_hdr) && _pc195_hdr->length >= _pc195_hdr->buf->length) ? _pc195_hdr->capacity : (size_t) 0;
                _pc195_slots = _pc195_hdr->buf->slots;
            }
            l5 = (l5 + INT64_C(1));
            continue;
        }
        _pc195_hdr->length = _pc195_len;
        if (_pc195_hdr->buf->length < _pc195_len) {
            _pc195_hdr->buf->length = _pc195_len;
        }
        break;
    }
    l5 = INT64_C(0);
    while ((l5 < l3)) {
        vader_array_t* _a13_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
        l10 = vader_array_ref_load_box(_a13_slotarr->buf, _a13_slotarr->offset + (size_t) l5);
        if (l10.tag == 843u) {
            t0 = vader_chk_add(i64, l5, INT64_C(1));
            if ((t0 < l3)) {
                l19 = vader_chk_add(i64, l5, INT64_C(1));
                vader_array_t* _a14_slotarr = ((vader_array_t*) l2);
                VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a14_slotarr, l19)
                l20 = vader_array_ref_load_box(_a14_slotarr->buf, _a14_slotarr->offset + (size_t) l19);
                if (l20.tag == 842u) {
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
                            vader_obj_header_init(_a20_obj, 844u);
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
        if (l10.tag == 853u) {
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
                        vader_obj_header_init(_a23_obj, 854u);
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
        if (l10.tag == 751u) {
            if ((l4 > INT64_C(0))) {
                l36 = vader_chk_sub(i64, l4, INT64_C(1));
                vader_array_t* _a26_slotarr = ((vader_array_t*) l17);
                VADER_ARRAY_RESOLVE_BUF(_a26_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a26_slotarr, l36)
                l37 = vader_array_ref_load_box(_a26_slotarr->buf, _a26_slotarr->offset + (size_t) l36);
                if (l37.tag == 751u) {
                    vader_array_t* _a27_slotarr = ((vader_array_t*) l18);
                    VADER_ARRAY_RESOLVE_BUF(_a27_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a27_slotarr, l5)
                    ((int32_t*) _a27_slotarr->buf->slots)[_a27_slotarr->offset + (size_t) l5] = (int32_t) INT32_C(-1);
                    l4 = vader_chk_sub(i64, l4, INT64_C(1));
                    l5 = vader_chk_add(i64, l5, INT64_C(1));
                    continue;
                }
                if (l37.tag == 748u) {
                    t1 = l37.payload.obj;
                    t5 = ((vader_struct_vader_core_bytecode$BoolConst_t*) t1)->f_value;
                    vader_struct_vader_core_bytecode$BoolConst_t* _a28_obj = (vader_struct_vader_core_bytecode$BoolConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BoolConst_t));
                    vader_obj_header_init(_a28_obj, 748u);
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
    vader_obj_header_init(_a33_obj, 920u);
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
    vader_array_t* _a0_arr = vader_array_new(247u, 0u, 13u, 1677u);
    l3 = (void*) _a0_arr;
    l4 = INT64_C(0);
    vader_array_t* _a1_arr = vader_array_new(22u, 0u, 7u, 338u);
    l5 = (void*) _a1_arr;
    if ((INT64_C(0) < l2)) {
        l6 = l2;
    } else {
        l6 = INT64_C(0);
    }
    vader_array_t* _a2_arr = vader_array_repeat((vader_array_t*) l5, (int64_t) l6);
    l5 = (void*) _a2_arr;
    l6 = INT64_C(0);
    vader_array_t* _pc35_hdr = (vader_array_t*) l5;
    size_t _pc35_len = _pc35_hdr->length;
    size_t _pc35_cap = (_pc35_hdr->offset == 0 && !vader_array_is_borrowed(_pc35_hdr) && _pc35_hdr->length >= _pc35_hdr->buf->length) ? _pc35_hdr->capacity : (size_t) 0;
    void* _pc35_slots = _pc35_hdr->buf->slots;
    for (;;) {
        if ((l6 < l2)) {
            if (VADER_LIKELY(_pc35_len < _pc35_cap)) {
                ((int32_t*) _pc35_slots)[_pc35_len] = (int32_t) (INT32_C(-1));
                _pc35_len += 1;
            } else {
                _pc35_hdr->length = _pc35_len;
                if (_pc35_hdr->buf->length < _pc35_len) {
                    _pc35_hdr->buf->length = _pc35_len;
                }
                vader_array_push_i32((vader_array_t*) l5, INT32_C(-1));
                _pc35_hdr = (vader_array_t*) l5;
                _pc35_len = _pc35_hdr->length;
                _pc35_cap = (_pc35_hdr->offset == 0 && !vader_array_is_borrowed(_pc35_hdr) && _pc35_hdr->length >= _pc35_hdr->buf->length) ? _pc35_hdr->capacity : (size_t) 0;
                _pc35_slots = _pc35_hdr->buf->slots;
            }
            l6 = (l6 + INT64_C(1));
            continue;
        }
        _pc35_hdr->length = _pc35_len;
        if (_pc35_hdr->buf->length < _pc35_len) {
            _pc35_hdr->buf->length = _pc35_len;
        }
        break;
    }
    l6 = INT64_C(0);
    while ((l6 < l2)) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        l7 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l6);
        if (l7.tag == 853u) {
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
                    vader_obj_header_init(_a5_obj, 854u);
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
    vader_obj_header_init(_a10_obj, 920u);
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
    vader_array_t* _a0_arr = vader_array_new(23u, 0u, 8u, 339u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(19u, 0u, 12u, 333u);
    l3 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(22u, 0u, 7u, 338u);
    l4 = (void*) _a2_arr;
    vader_struct_std_collections$MutableMap__i64__bool_t* _a3_obj = (vader_struct_std_collections$MutableMap__i64__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i64__bool_t));
    vader_obj_header_init(_a3_obj, 508u);
    _a3_obj->f_ekeys = l2;
    _a3_obj->f_evals = l3;
    _a3_obj->f_index = l4;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a3_obj;
    vader_struct_std_collections$MutableSet__i64_t* _a4_obj = (vader_struct_std_collections$MutableSet__i64_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableSet__i64_t));
    vader_obj_header_init(_a4_obj, 606u);
    _a4_obj->f_inner = t0;
    l2 = (void*) _a4_obj;
    vader_array_t* _a5_arr = vader_array_new(23u, 0u, 8u, 339u);
    l3 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(19u, 0u, 12u, 333u);
    l4 = (void*) _a6_arr;
    vader_array_t* _a7_arr = vader_array_new(22u, 0u, 7u, 338u);
    l5 = (void*) _a7_arr;
    vader_struct_std_collections$MutableMap__i64__bool_t* _a8_obj = (vader_struct_std_collections$MutableMap__i64__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i64__bool_t));
    vader_obj_header_init(_a8_obj, 508u);
    _a8_obj->f_ekeys = l3;
    _a8_obj->f_evals = l4;
    _a8_obj->f_index = l5;
    _a8_obj->f_mask = INT64_C(0);
    _a8_obj->f_grow_at = INT64_C(0);
    _a8_obj->f_size = INT64_C(0);
    _a8_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a8_obj;
    vader_struct_std_collections$MutableSet__i64_t* _a9_obj = (vader_struct_std_collections$MutableSet__i64_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableSet__i64_t));
    vader_obj_header_init(_a9_obj, 606u);
    _a9_obj->f_inner = t0;
    l3 = (void*) _a9_obj;
    vader_array_t* _a10_arr = vader_array_new(22u, 0u, 7u, 338u);
    l4 = (void*) _a10_arr;
    vader_array_t* _a11_arr = vader_array_new(19u, 0u, 12u, 333u);
    l5 = (void*) _a11_arr;
    vader_array_t* _a12_arr = vader_array_new(22u, 0u, 7u, 338u);
    l6 = (void*) _a12_arr;
    vader_struct_std_collections$MutableMap__i32__bool_t* _a13_obj = (vader_struct_std_collections$MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i32__bool_t));
    vader_obj_header_init(_a13_obj, 462u);
    _a13_obj->f_ekeys = l4;
    _a13_obj->f_evals = l5;
    _a13_obj->f_index = l6;
    _a13_obj->f_mask = INT64_C(0);
    _a13_obj->f_grow_at = INT64_C(0);
    _a13_obj->f_size = INT64_C(0);
    _a13_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a13_obj;
    vader_struct_std_collections$MutableSet__i32_t* _a14_obj = (vader_struct_std_collections$MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableSet__i32_t));
    vader_obj_header_init(_a14_obj, 605u);
    _a14_obj->f_inner = t0;
    l4 = (void*) _a14_obj;
    vader_struct_vader_emit_bytecode$ScheduleHints_t* _a15_obj = (vader_struct_vader_emit_bytecode$ScheduleHints_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_bytecode$ScheduleHints_t));
    vader_obj_header_init(_a15_obj, 926u);
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
    vader_array_t* _a0_arr = vader_array_new(19u, 1u, 12u, 333u);
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
    vader_array_t* _a5_arr = vader_array_new(22u, 1u, 7u, 338u);
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
                    l28 = std_core$write_string_at(l27, l28, 1873u);
                    l28 = std_core$write_string_at(l27, l28, l25);
                    l28 = std_core$write_string_at(l27, l28, 299u);
                    l29 = ((int64_t) (int32_t) l17);
                    l28 = std_core$write_int(l27, l28, l29);
                    l28 = std_core$write_string_at(l27, l28, 243u);
                    l30 = ((int64_t) (int32_t) l13);
                    l28 = std_core$write_int(l27, l28, l30);
                    l28 = std_core$write_string_at(l27, l28, 115u);
                    t3 = std_core$finish_buffer(l27, l28);
                    vader_host_std_abort$panic(t3);
                    vader_unreachable("a no-return call returned");
                }
            }
            l16 = (l16 + INT64_C(1));
        }
        l12 = (l12 + INT64_C(1));
    }
    vader_array_t* _a13_arr = vader_array_new(19u, 1u, 12u, 333u);
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
    vader_array_t* _a22_arr = vader_array_new(19u, 1u, 12u, 333u);
    ((uint8_t*) _a22_arr->buf->slots)[_a22_arr->offset + 0u] = (uint8_t) false;
    t0 = (void*) _a22_arr;
    vader_array_t* _a23_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l3);
    l10 = (void*) _a23_arr;
    vader_array_t* _a24_arr = vader_array_new(19u, 1u, 12u, 333u);
    ((uint8_t*) _a24_arr->buf->slots)[_a24_arr->offset + 0u] = (uint8_t) false;
    t0 = (void*) _a24_arr;
    vader_array_t* _a25_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l3);
    l27 = (void*) _a25_arr;
    vader_array_t* _a26_arr = vader_array_new(3u, 0u, 13u, 22u);
    l32 = (void*) _a26_arr;
    if ((INT64_C(0) < l3)) {
        l11 = l3;
    } else {
        l11 = INT64_C(0);
    }
    vader_array_t* _a27_arr = vader_array_repeat((vader_array_t*) l32, (int64_t) l11);
    l32 = (void*) _a27_arr;
    vader_array_t* _a28_arr = vader_array_new(3u, 0u, 13u, 22u);
    l33 = (void*) _a28_arr;
    if ((INT64_C(0) < l3)) {
        l11 = l3;
    } else {
        l11 = INT64_C(0);
    }
    vader_array_t* _a29_arr = vader_array_repeat((vader_array_t*) l33, (int64_t) l11);
    l33 = (void*) _a29_arr;
    vader_array_t* _a30_arr = vader_array_new(22u, 1u, 7u, 338u);
    ((int32_t*) _a30_arr->buf->slots)[_a30_arr->offset + 0u] = (int32_t) INT32_C(-1);
    t0 = (void*) _a30_arr;
    vader_array_t* _a31_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l3);
    l34 = (void*) _a31_arr;
    l11 = INT64_C(0);
    while ((l11 < l3)) {
        vader_array_t* _a32_arr = vader_array_new(22u, 0u, 7u, 338u);
        l35 = (void*) _a32_arr;
        vader_array_push_ref((vader_array_t*) l32, l35);
        vader_array_t* _a33_arr = vader_array_new(22u, 0u, 7u, 338u);
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
    vader_obj_header_init(_a50_obj, 929u);
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
    vader_array_t* _a0_arr = vader_array_new(22u, 1u, 7u, 338u);
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
    vader_array_t* _a5_arr = vader_array_new(22u, 1u, 7u, 338u);
    ((int32_t*) _a5_arr->buf->slots)[_a5_arr->offset + 0u] = (int32_t) INT32_C(-1);
    t0 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l1);
    l3 = (void*) _a6_arr;
    l11 = false;
    vader_array_t* _a7_arr = vader_array_new(22u, 0u, 7u, 338u);
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
                if (l14.tag == 1370u) {
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
            if (l14.tag == 1370u) {
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
    vader_array_t* _a15_arr = vader_array_new(201u, 0u, 13u, 1304u);
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
        vader_obj_header_init(_a18_obj, 1304u);
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
    vader_obj_header_init(_a19_obj, 1306u);
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
    vader_array_t* _a0_arr = vader_array_new(247u, 0u, 13u, 1677u);
    l6 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(22u, 1u, 7u, 338u);
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
            if (t2.tag == 844u) {
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
    vader_obj_header_init(_a9_obj, 920u);
    _a9_obj->f_body = l6;
    _a9_obj->f_jump_table = l1;
    _a9_obj->f_debug = l3;
    t1 = (void*) _a9_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
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
    l6 = std_core$write_string_at(l1, l6, 1873u);
    l6 = std_core$write_string_at(l1, l6, l5);
    l6 = std_core$write_string_at(l1, l6, 298u);
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_pending);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
    t1 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT32_C(0));
    l7 = ((int64_t) (int32_t) ((vader_struct_vader_emit_bytecode$PendingBranch_t*) t1)->f_target_blk);
    l6 = std_core$write_int(l1, l6, l7);
    l6 = std_core$write_string_at(l1, l6, 134u);
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
    vader_array_t* _a0_arr = vader_array_new(21u, 0u, 0u, 335u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(19u, 0u, 12u, 333u);
    l3 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(22u, 0u, 7u, 338u);
    l4 = (void*) _a2_arr;
    vader_struct_std_collections$MutableMap__string__bool_t* _a3_obj = (vader_struct_std_collections$MutableMap__string__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__string__bool_t));
    vader_obj_header_init(_a3_obj, 539u);
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
        if (t3.tag == 338u) {
            continue;
        }
        l12 = vader_emit_bytecode$build_intrinsic_wrapper_body(l3, l10);
        vader_array_t* _a6_arr = vader_array_new(251u, 0u, 13u, 1735u);
        l13 = (void*) _a6_arr;
        l5 = ((vader_array_t*) l12)->length;
        vader_array_t* _a7_arr = vader_array_repeat((vader_array_t*) l13, (int64_t) l5);
        l14 = (void*) _a7_arr;
        l6 = INT64_C(0);
        l15 = ((vader_array_t*) l12)->length;
        while ((l6 < l15)) {
            vader_array_push_ref((vader_array_t*) l14, vader_box_obj(0u, NULL).payload.obj);
            l6 = (l6 + INT64_C(1));
        }
        vader_array_t* _a8_arr = vader_array_new(22u, 0u, 7u, 338u);
        l16 = (void*) _a8_arr;
        l17 = ((vader_array_t*) l12)->length;
        vader_array_t* _a9_arr = vader_array_repeat((vader_array_t*) l16, (int64_t) l17);
        l18 = (void*) _a9_arr;
        l19 = INT64_C(0);
        l20 = ((vader_array_t*) l12)->length;
        vader_array_t* _pc139_hdr = (vader_array_t*) l18;
        size_t _pc139_len = _pc139_hdr->length;
        size_t _pc139_cap = (_pc139_hdr->offset == 0 && !vader_array_is_borrowed(_pc139_hdr) && _pc139_hdr->length >= _pc139_hdr->buf->length) ? _pc139_hdr->capacity : (size_t) 0;
        void* _pc139_slots = _pc139_hdr->buf->slots;
        for (;;) {
            if ((l19 < l20)) {
                if (VADER_LIKELY(_pc139_len < _pc139_cap)) {
                    ((int32_t*) _pc139_slots)[_pc139_len] = (int32_t) (INT32_C(-1));
                    _pc139_len += 1;
                } else {
                    _pc139_hdr->length = _pc139_len;
                    if (_pc139_hdr->buf->length < _pc139_len) {
                        _pc139_hdr->buf->length = _pc139_len;
                    }
                    vader_array_push_i32((vader_array_t*) l18, INT32_C(-1));
                    _pc139_hdr = (vader_array_t*) l18;
                    _pc139_len = _pc139_hdr->length;
                    _pc139_cap = (_pc139_hdr->offset == 0 && !vader_array_is_borrowed(_pc139_hdr) && _pc139_hdr->length >= _pc139_hdr->buf->length) ? _pc139_hdr->capacity : (size_t) 0;
                    _pc139_slots = _pc139_hdr->buf->slots;
                }
                l19 = (l19 + INT64_C(1));
                continue;
            }
            _pc139_hdr->length = _pc139_len;
            if (_pc139_hdr->buf->length < _pc139_len) {
                _pc139_hdr->buf->length = _pc139_len;
            }
            break;
        }
        vader_array_t* _a10_arr = vader_array_new(63u, 0u, 13u, 732u);
        l21 = (void*) _a10_arr;
        t1 = ((vader_array_t*) ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l1)->f_functions)->length;
        l22 = ((int32_t) (int64_t) t1);
        l23 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l1)->f_functions;
        t4 = ((vader_struct_vader_core_bytecode$BcImport_t*) l3)->f_mangled_name;
        l24 = concat_2(t4, 1035u);
        l25 = ((vader_struct_vader_core_bytecode$BcImport_t*) l3)->f_signature;
        vader_array_t* _a11_arr = vader_array_new(22u, 0u, 7u, 338u);
        l26 = (void*) _a11_arr;
        vader_struct_vader_core_bytecode$BcFunction_t* _a12_obj = (vader_struct_vader_core_bytecode$BcFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcFunction_t));
        vader_obj_header_init(_a12_obj, 729u);
        _a12_obj->f_name = l24;
        _a12_obj->f_is_main = false;
        _a12_obj->f_signature = l25;
        _a12_obj->f_locals = l21;
        _a12_obj->f_body = l12;
        _a12_obj->f_debug = l14;
        _a12_obj->f_jump_table = l18;
        _a12_obj->f_source_pc = l26;
        l27 = (void*) _a12_obj;
        vader_array_push_ref((vader_array_t*) l23, l27);
        l28 = ((vader_struct_vader_emit_bytecode$EmitterCtx_t*) l1)->f_function_index_by_mangle;
        l29 = ((vader_struct_vader_core_bytecode$BcImport_t*) l3)->f_mangled_name;
        std_collections$MutableMap$std_core$IndexSet$set_at__string__i32(l28, l29, l22);
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
    if (l4.tag == 1371u) {
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
    if (l5.tag == 797u) {
        if (l4.tag == 797u) {
            if (l0.tag == 792u) {
                t0 = l5.payload.obj;
                l6 = ((vader_struct_vader_core_bytecode$I32Const_t*) t0)->f_value;
                t0 = l4.payload.obj;
                l7 = ((vader_struct_vader_core_bytecode$I32Const_t*) t0)->f_value;
                vader_struct_vader_core_bytecode$I32Const_t* _a1_obj = (vader_struct_vader_core_bytecode$I32Const_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$I32Const_t));
                vader_obj_header_init(_a1_obj, 797u);
                _a1_obj->f_value = (l6 + l7);
                t0 = (void*) _a1_obj;
                { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
            }
            if (l0.tag == 811u) {
                t0 = l5.payload.obj;
                l6 = ((vader_struct_vader_core_bytecode$I32Const_t*) t0)->f_value;
                t0 = l4.payload.obj;
                l7 = ((vader_struct_vader_core_bytecode$I32Const_t*) t0)->f_value;
                vader_struct_vader_core_bytecode$I32Const_t* _a2_obj = (vader_struct_vader_core_bytecode$I32Const_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$I32Const_t));
                vader_obj_header_init(_a2_obj, 797u);
                _a2_obj->f_value = (l6 - l7);
                t0 = (void*) _a2_obj;
                { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
            }
            if (l0.tag == 805u) {
                t0 = l5.payload.obj;
                l6 = ((vader_struct_vader_core_bytecode$I32Const_t*) t0)->f_value;
                t0 = l4.payload.obj;
                l7 = ((vader_struct_vader_core_bytecode$I32Const_t*) t0)->f_value;
                vader_struct_vader_core_bytecode$I32Const_t* _a3_obj = (vader_struct_vader_core_bytecode$I32Const_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$I32Const_t));
                vader_obj_header_init(_a3_obj, 797u);
                _a3_obj->f_value = (l6 * l7);
                t0 = (void*) _a3_obj;
                { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
            }
            if (l0.tag == 764u) {
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
                vader_obj_header_init(_a4_obj, 797u);
                _a4_obj->f_value = ((int32_t) (int64_t) t2);
                t0 = (void*) _a4_obj;
                { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
            }
        }
    }
    if (l5.tag == 817u) {
        if (l4.tag == 817u) {
            if (l0.tag == 812u) {
                t0 = l5.payload.obj;
                l3 = ((vader_struct_vader_core_bytecode$I64Const_t*) t0)->f_value;
                t0 = l4.payload.obj;
                l8 = ((vader_struct_vader_core_bytecode$I64Const_t*) t0)->f_value;
                vader_struct_vader_core_bytecode$I64Const_t* _a5_obj = (vader_struct_vader_core_bytecode$I64Const_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$I64Const_t));
                vader_obj_header_init(_a5_obj, 817u);
                _a5_obj->f_value = (l3 + l8);
                t0 = (void*) _a5_obj;
                { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
            }
            if (l0.tag == 831u) {
                t0 = l5.payload.obj;
                l3 = ((vader_struct_vader_core_bytecode$I64Const_t*) t0)->f_value;
                t0 = l4.payload.obj;
                l8 = ((vader_struct_vader_core_bytecode$I64Const_t*) t0)->f_value;
                vader_struct_vader_core_bytecode$I64Const_t* _a6_obj = (vader_struct_vader_core_bytecode$I64Const_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$I64Const_t));
                vader_obj_header_init(_a6_obj, 817u);
                _a6_obj->f_value = (l3 - l8);
                t0 = (void*) _a6_obj;
                { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
            }
            if (l0.tag == 825u) {
                t0 = l5.payload.obj;
                l3 = ((vader_struct_vader_core_bytecode$I64Const_t*) t0)->f_value;
                t0 = l4.payload.obj;
                l8 = ((vader_struct_vader_core_bytecode$I64Const_t*) t0)->f_value;
                vader_struct_vader_core_bytecode$I64Const_t* _a7_obj = (vader_struct_vader_core_bytecode$I64Const_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$I64Const_t));
                vader_obj_header_init(_a7_obj, 817u);
                _a7_obj->f_value = (l3 * l8);
                t0 = (void*) _a7_obj;
                { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
            }
            if (l0.tag == 764u) {
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
                vader_obj_header_init(_a8_obj, 817u);
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
    if (!(l6.tag == 842u)) {
        { vader_gc_top = gc_frame.prev; return false; }
    }
    t0 = l6.payload.obj;
    l7 = ((vader_struct_vader_core_bytecode$LocalGet_t*) t0)->f_slot;
    l4 = ((vader_struct_vader_core_bytecode$BcFunction_t*) ((vader_struct_vader_emit_bytecode$FnEmitCfg_t*) l0)->f_slot)->f_body;
    l3 = vader_chk_sub(i64, l3, INT64_C(1));
    vader_struct_vader_core_bytecode$LocalField_t* _a1_obj = (vader_struct_vader_core_bytecode$LocalField_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$LocalField_t));
    vader_obj_header_init(_a1_obj, 841u);
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
    if (l0.tag == 868u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_core_bytecode$StructNew_t*) t0)->f_type_id;
        return l1;
    }
    if (l0.tag == 867u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_core_bytecode$StructGet_t*) t0)->f_type_id;
    } else if (l0.tag == 869u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_core_bytecode$StructSet_t*) t0)->f_type_id;
    } else if (l0.tag == 884u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_core_bytecode$UnionFieldGet_t*) t0)->f_type_id;
    } else if (l0.tag == 885u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_core_bytecode$UnionFieldSet_t*) t0)->f_type_id;
    } else if (l0.tag == 717u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_core_bytecode$ArrayNew_t*) t0)->f_type_id;
    } else if (l0.tag == 715u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_core_bytecode$ArrayGet_t*) t0)->f_type_id;
    } else if (l0.tag == 722u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_core_bytecode$ArraySet_t*) t0)->f_type_id;
    } else if (l0.tag == 718u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_core_bytecode$ArrayPush_t*) t0)->f_type_id;
    } else if (l0.tag == 870u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_core_bytecode$TypeCheck_t*) t0)->f_type_id;
    } else if (l0.tag == 871u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_core_bytecode$TypeConst_t*) t0)->f_type_id;
    } else if (l0.tag == 762u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_core_bytecode$CallIndirect_t*) t0)->f_type_id;
    } else if (l0.tag == 846u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_core_bytecode$MakeClosure_t*) t0)->f_env_type_id;
    } else if (l0.tag == 789u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_core_bytecode$FnRef_t*) t0)->f_type_id;
    } else if (l0.tag == 841u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_core_bytecode$LocalField_t*) t0)->f_type_id;
    } else if (l0.tag == 723u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_core_bytecode$ArraySlice_t*) t0)->f_type_id;
    } else if (l0.tag == 849u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_core_bytecode$RefCast_t*) t0)->f_type_id;
    } else if (l0.tag == 852u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_core_bytecode$Retag_t*) t0)->f_type_id;
    } else if (l0.tag == 767u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_core_bytecode$DataConst_t*) t0)->f_type_id;
    } else {
        if (!((l0.tag == 713u || l0.tag == 714u || l0.tag == 716u || l0.tag == 719u || l0.tag == 720u || l0.tag == 721u || l0.tag == 744u || l0.tag == 745u || l0.tag == 746u || l0.tag == 747u || l0.tag == 748u || l0.tag == 749u || l0.tag == 750u || l0.tag == 751u || l0.tag == 752u || l0.tag == 753u || l0.tag == 754u || l0.tag == 755u || l0.tag == 756u || l0.tag == 757u || l0.tag == 760u || l0.tag == 761u || l0.tag == 763u || l0.tag == 764u || l0.tag == 765u || l0.tag == 766u || l0.tag == 769u || l0.tag == 770u || l0.tag == 771u || l0.tag == 772u || l0.tag == 773u || l0.tag == 774u || l0.tag == 775u || l0.tag == 776u || l0.tag == 777u || l0.tag == 778u || l0.tag == 779u || l0.tag == 780u || l0.tag == 781u || l0.tag == 782u || l0.tag == 783u || l0.tag == 784u || l0.tag == 785u || l0.tag == 786u || l0.tag == 787u || l0.tag == 788u || l0.tag == 790u || l0.tag == 791u || l0.tag == 792u || l0.tag == 793u || l0.tag == 794u || l0.tag == 795u || l0.tag == 796u || l0.tag == 797u || l0.tag == 798u || l0.tag == 799u || l0.tag == 800u || l0.tag == 801u || l0.tag == 802u || l0.tag == 803u || l0.tag == 804u || l0.tag == 805u || l0.tag == 806u || l0.tag == 807u || l0.tag == 808u || l0.tag == 809u || l0.tag == 810u || l0.tag == 811u || l0.tag == 812u || l0.tag == 813u || l0.tag == 814u || l0.tag == 815u || l0.tag == 816u || l0.tag == 817u || l0.tag == 818u || l0.tag == 819u || l0.tag == 820u || l0.tag == 821u || l0.tag == 822u || l0.tag == 823u || l0.tag == 824u || l0.tag == 825u || l0.tag == 826u || l0.tag == 827u || l0.tag == 828u || l0.tag == 829u || l0.tag == 830u || l0.tag == 831u || l0.tag == 832u || l0.tag == 834u || l0.tag == 835u || l0.tag == 836u || l0.tag == 837u || l0.tag == 838u || l0.tag == 839u || l0.tag == 840u || l0.tag == 842u || l0.tag == 843u || l0.tag == 844u || l0.tag == 845u || l0.tag == 847u || l0.tag == 848u || l0.tag == 850u || l0.tag == 851u || l0.tag == 853u || l0.tag == 854u || l0.tag == 855u || l0.tag == 856u || l0.tag == 857u || l0.tag == 858u || l0.tag == 859u || l0.tag == 860u || l0.tag == 861u || l0.tag == 862u || l0.tag == 863u || l0.tag == 864u || l0.tag == 865u || l0.tag == 866u || l0.tag == 872u || l0.tag == 873u || l0.tag == 874u || l0.tag == 875u || l0.tag == 876u || l0.tag == 877u || l0.tag == 878u || l0.tag == 879u || l0.tag == 880u || l0.tag == 881u || l0.tag == 882u || l0.tag == 883u || l0.tag == 886u || l0.tag == 887u))) {
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
    if (l5.tag == 738u) {
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
    if (l5.tag == 739u) {
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
    if (l5.tag == 725u) {
        t1 = l5.payload.obj;
        t2 = ((vader_struct_vader_core_bytecode$BcArray_t*) t1)->f_element;
        vader_emit_bytecode$visit_type(t2, l1, l2);
    }
    if (l5.tag == 728u) {
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
    if (!(l2.tag == 650u)) {
        { void* __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a0_arr = vader_array_new(19u, 0u, 12u, 333u);
    l3 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(19u, 0u, 12u, 333u);
    l4 = (void*) _a1_arr;
    t0 = l2.payload.obj;
    l5 = ((vader_struct_toolchain_ast$FnDecl_t*) t0)->f_params;
    l6 = ((vader_array_t*) l5)->length;
    l7 = INT64_C(0);
    while ((l7 < l6)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        l8 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l7);
        l9 = toolchain_ast$decorators_have(((vader_struct_toolchain_ast$FnParam_t*) l8)->f_decorators, 1708u);
        vader_array_push_bool((vader_array_t*) l3, l9);
        l10 = toolchain_ast$decorators_have(((vader_struct_toolchain_ast$FnParam_t*) l8)->f_decorators, 1707u);
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
    vader_obj_header_init(_a3_obj, 736u);
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
    vader_obj_header_init(_a0_obj, 729u);
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
