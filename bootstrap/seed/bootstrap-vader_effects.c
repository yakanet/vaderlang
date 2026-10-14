#include "bootstrap.split.h"

static int64_t vader_effects_access_key(void* l0);
static void* vader_effects_accesses_of_param(vader_box_t l0, size_t l1, void* l2);
static size_t vader_effects_add_copy(void* l0, size_t l1, size_t l2);
static void vader_effects_add_flow(void* l0, size_t l1, size_t l2, int32_t l3);
static void vader_effects_add_mark(void* l0, size_t l1, int32_t l2, uint8_t l3);
static size_t vader_effects_add_root(void* l0, size_t l1);
static size_t vader_effects_add_site(void* l0, void* l1, void* l2);
static void* vader_effects_any_effects(void);
static void vader_effects_apply_constraints(void* l0, void* l1, void* l2, void* l3, void* l4);
static void vader_effects_apply_site(void* l0, void* l1, void* l2, void* l3);
static vader_string_t vader_effects_argument_label(void* l0, void* l1, int32_t l2);
static void vader_effects_assign(void* l0, vader_box_t l1, vader_box_t l2);
static void vader_effects_assign_element(void* l0, void* l1, vader_box_t l2);
static void vader_effects_assign_name(void* l0, void* l1, vader_box_t l2);
static vader_box_t vader_effects_binary_value(void* l0, void* l1);
static void vader_effects_bind(void* l0, vader_box_t l1, vader_box_t l2);
static void vader_effects_bind_copy(void* l0, size_t l1, size_t l2, void* l3);
static void vader_effects_bind_pattern(void* l0, vader_box_t l1, vader_box_t l2);
static void vader_effects_bind_symbol(void* l0, void* l1, vader_box_t l2);
static uint8_t vader_effects_binding_outcome(void* l0, void* l1);
static vader_box_t vader_effects_block_value(void* l0, void* l1);
static void* vader_effects_body_ctx(void* l0, void* l1, void* l2, void* l3);
static vader_box_t vader_effects_bodyless_target(void* l0, void* l1, void* l2);
static bool vader_effects_breaks_widening(void* l0, void* l1, int32_t l2);
static vader_box_t vader_effects_call(void* l0, vader_box_t l1, void* l2, void* l3);
static void* vader_effects_call_sources(void* l0, void* l1, vader_box_t l2);
static vader_box_t vader_effects_call_value(void* l0, void* l1);
static void* vader_effects_callee_nodes(void* l0);
static void* vader_effects_carried(void* l0, void* l1, void* l2);
static vader_box_t vader_effects_chain_position(void* l0, int32_t l1, int32_t l2);
static int32_t vader_effects_child(void* l0, int32_t l1, int32_t l2);
static bool vader_effects_collect_returned(void* l0, void* l1, void* l2);
static void* vader_effects_component_of_each_node(void* l0);
static int32_t vader_effects_composed(void* l0, int32_t l1, int32_t l2, bool l3);
static vader_box_t vader_effects_converted(void* l0, vader_box_t l1, vader_box_t l2);
static vader_box_t vader_effects_converted_by(void* l0, vader_box_t l1, vader_box_t l2, vader_box_t l3);
static uint8_t vader_effects_copy_or_elided(void* l0, void* l1, void* l2);
static void* vader_effects_copy_to_effects(int32_t l0);
static bool vader_effects_covered(void* l0, void* l1, void* l2);
static int32_t vader_effects_cut(void* l0, int32_t l1);
static void vader_effects_decide(void* l0, void* l1, void* l2, void* l3, void* l4);
static void vader_effects_defer_stmt(void* l0, void* l1);
static void vader_effects_destructure_assign(void* l0, void* l1);
static void* vader_effects_direct_targets(void* l0, void* l1);
static void vader_effects_discard(void* l0, vader_box_t l1);
static vader_string_t vader_effects_display_callee(vader_box_t l0);
static vader_string_t vader_effects_display_steps(void* l0, int32_t l1);
static void vader_effects_drop_covered(void* l0, void* l1, void* l2);
static void* vader_effects_each_targets(void* l0, void* l1);
static void* vader_effects_effects_of(uint8_t l0, int32_t l1);
static bool vader_effects_either(void* l0, void* l1);
static vader_box_t vader_effects_else_value(void* l0, vader_box_t l1);
static void vader_effects_escape(void* l0, vader_box_t l1, uint8_t l2);
static void* vader_effects_evaluate(void* l0, void* l1);
static void* vader_effects_evaluate_roots(void* l0, void* l1);
static bool vader_effects_extends(void* l0, int32_t l1, int32_t l2);
static vader_box_t vader_effects_fallback_value(void* l0, vader_box_t l1);
static void* vader_effects_ffi_call_effects(int32_t l0);
static vader_string_t vader_effects_field_step(void* l0);
static vader_box_t vader_effects_field_value(void* l0, void* l1);
static bool vader_effects_fields_may_be_written(void* l0, void* l1, void* l2, void* l3);
static void* vader_effects_first_cuts(void);
static void* vader_effects_first_paths(void);
static void* vader_effects_flowed_root(void* l0, void* l1, void* l2, void* l3);
static void vader_effects_for_stmt(void* l0, void* l1);
static void* vader_effects_foreign_effects(void* l0);
static size_t vader_effects_fresh_slot(void* l0);
static size_t vader_effects_frozen_source(void* l0, vader_box_t l1, vader_string_t l2, vader_box_t l3);
static vader_box_t vader_effects_frozen_use(void* l0, vader_box_t l1, void* l2);
static vader_box_t vader_effects_frozen_view(void* l0, void* l1, vader_box_t l2);
static bool vader_effects_hands_on_written(void* l0, void* l1, void* l2);
static vader_box_t vader_effects_held_by(void* l0, void* l1);
static bool vader_effects_holds(void* l0, int32_t l1, uint8_t l2);
static vader_box_t vader_effects_ident_value(void* l0, void* l1);
static vader_box_t vader_effects_if_value(void* l0, void* l1);
static bool vader_effects_include(void* l0, void* l1, void* l2);
static bool vader_effects_include_all(void* l0, void* l1, void* l2);
static bool vader_effects_include_root(void* l0, size_t l1, void* l2);
static void* vader_effects_index_functions(void* l0, void* l1);
static vader_box_t vader_effects_index_value(void* l0, void* l1);
static void* vader_effects_initialiser_ctx(void* l0, void* l1, void* l2, void* l3);
static void vader_effects_insert(void* l0, void* l1);
static vader_box_t vader_effects_intrinsic_effects(void* l0, vader_string_t l1);
static vader_string_t vader_effects_intrinsic_key(void* l0, void* l1, void* l2);
static int32_t vader_effects_joined(void* l0, int32_t l1, int32_t l2);
static vader_box_t vader_effects_known_params(vader_box_t l0, void* l1);
static vader_box_t vader_effects_lambda_value(void* l0, void* l1);
static size_t vader_effects_local_slot(void* l0, int32_t l1);
static vader_box_t vader_effects_loop_element(void* l0, vader_box_t l1, vader_box_t l2);
static bool vader_effects_makes_frozen_view(vader_string_t l0);
static void vader_effects_mark(void* l0, vader_box_t l1, int32_t l2, uint8_t l3);
static bool vader_effects_mark_fresh(void* l0, void* l1);
static void vader_effects_mark_roots(void* l0, void* l1, int32_t l2, uint8_t l3, void* l4, bool l5);
static vader_box_t vader_effects_match_value(void* l0, void* l1);
static void* vader_effects_member_targets(void* l0, vader_string_t l1, vader_string_t l2);
static void* vader_effects_memory_copy_effects(int32_t l0);
static vader_box_t vader_effects_namespace_member(void* l0, void* l1);
static void* vader_effects_new_skeleton(size_t l0);
static size_t vader_effects_next_root(void* l0);
static void vader_effects_note_frozen_body(void* l0, int32_t l1, vader_box_t l2);
static void vader_effects_note_initialisers(void* l0, void* l1, void* l2);
static void vader_effects_note_kept_by_constant(void* l0, void* l1, void* l2);
static void vader_effects_note_known_writes(void* l0, void* l1, size_t l2, vader_box_t l3);
static void vader_effects_note_widened(void* l0, vader_box_t l1, void* l2, size_t l3, vader_box_t l4);
static void vader_effects_note_write(void* l0, vader_box_t l1);
static void vader_effects_note_written(void* l0, vader_box_t l1);
static vader_box_t vader_effects_nothing(void* l0, vader_box_t l1);
static vader_box_t vader_effects_outcome(void* l0, void* l1, void* l2);
static int64_t vader_effects_pair_key(int32_t l0, int32_t l1);
static vader_box_t vader_effects_parameter_name(vader_box_t l0, size_t l1);
static bool vader_effects_passes_receiver(void* l0, void* l1, void* l2, vader_box_t l3);
static int32_t vader_effects_path_to(void* l0, vader_string_t l1);
static void* vader_effects_push_effects(int32_t l0);
static vader_box_t vader_effects_range_value(void* l0, void* l1);
static void vader_effects_read_fresh(void* l0, void* l1);
static bool vader_effects_reads_fresh(void* l0, void* l1, uint8_t l2);
static void vader_effects_record(void* l0, void* l1, void* l2, uint8_t l3, vader_string_t l4, bool l5);
static bool vader_effects_recursive(void* l0, vader_box_t l1);
static void vader_effects_register(void* l0, void* l1, void* l2);
static void vader_effects_register_defaults(void* l0, void* l1, void* l2);
static void* vader_effects_remove_last_effects(int32_t l0);
static bool vader_effects_reroot(void* l0, void* l1, void* l2, void* l3);
static bool vader_effects_reroot_below(void* l0, size_t l1, int32_t l2, size_t l3, void* l4, bool l5);
static uint8_t vader_effects_return_effect(void* l0);
static void vader_effects_return_stmt(void* l0, void* l1);
static void* vader_effects_root_record(void* l0, size_t l1);
static vader_box_t vader_effects_sequence_value(void* l0, void* l1);
static vader_box_t vader_effects_sequence_walked(void* l0, void* l1);
static void vader_effects_settle_frozen(void* l0, void* l1, void* l2, void* l3);
static void* vader_effects_settle_widenings(void* l0, void* l1, void* l2);
static void* vader_effects_settled_slots(void* l0, void* l1, bool l2);
static vader_box_t vader_effects_single(void* l0);
static vader_box_t vader_effects_site_callee(void* l0, uint8_t l1, size_t l2);
static void* vader_effects_skeleton_of(void* l0, void* l1, void* l2, void* l3, void* l4, int32_t l5);
static void vader_effects_spread(void* l0, vader_box_t l1, void* l2);
static void vader_effects_spread_fresh(void* l0);
static int32_t vader_effects_step_id(void* l0, vader_string_t l1);
static vader_box_t vader_effects_step_slot(void* l0, vader_box_t l1, vader_string_t l2);
static vader_box_t vader_effects_step_type(void* l0, vader_box_t l1, vader_string_t l2);
static void* vader_effects_steps_of(void* l0, int32_t l1);
static bool vader_effects_steps_through_elements(void* l0, vader_box_t l1);
static void vader_effects_stmt(void* l0, vader_box_t l1);
static vader_box_t vader_effects_string_value(void* l0, void* l1);
static vader_box_t vader_effects_struct_fields_of(void* l0, vader_box_t l1);
static vader_string_t vader_effects_struct_key(void* l0);
static vader_box_t vader_effects_struct_literal_value(void* l0, void* l1);
static vader_box_t vader_effects_target_of_decl(void* l0, void* l1);
static vader_box_t vader_effects_type_below(void* l0, void* l1, vader_box_t l2, int32_t l3);
static vader_box_t vader_effects_union_of(void* l0, void* l1);
static vader_box_t vader_effects_use_outcome(void* l0, void* l1);
static vader_box_t vader_effects_value(void* l0, vader_box_t l1);
static vader_box_t vader_effects_value_of(void* l0, vader_box_t l1);
static vader_string_t vader_effects_what_it_may_do(uint8_t l0, vader_string_t l1);
static vader_string_t vader_effects_widening_detail(void* l0, void* l1);
static void* vader_effects_widening_outcome(void* l0, void* l1, void* l2, void* l3);
static void* vader_effects_writes_bytes(int32_t l0);
static void* vader_effects_written_keys(vader_box_t l0);

static int64_t vader_effects_access_key(void* l0) {
    int64_t l1, l2;
    int32_t t0;
    int64_t t1;
    t0 = ((vader_struct_vader_effects_Access_t*) l0)->f_path;
    l1 = vader_chk_mul(i64, ((int64_t) (int32_t) t0), INT64_C(8));
    l2 = ((int64_t) (uint8_t) ((vader_struct_vader_effects_Access_t*) l0)->f_effect);
    t1 = vader_chk_add(i64, l1, l2);
    return t1;
}

static void* vader_effects_accesses_of_param(vader_box_t l0, size_t l1, void* l2) {
    bool l3;
    size_t l4;
    void* t0;
    if (l0.tag == 0u) {
        l3 = true;
    } else {
        t0 = l0.payload.obj;
        l4 = ((vader_array_t*) t0)->length;
        l3 = (l1 >= l4);
    }
    if (!(l3)) {
        t0 = l0.payload.obj;
        vader_array_t* _a0_slotarr = ((vader_array_t*) t0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l1);
        return ((vader_struct_vader_effects_ParamEffects_t*) t0)->f_accesses;
    }
    return ((vader_struct_vader_effects_ParamEffects_t*) l2)->f_accesses;
}

static size_t vader_effects_add_copy(void* l0, size_t l1, size_t l2) {
    size_t l3;
    void* l4 = NULL;
    void* l5 = NULL;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[3] = { &l0, &l4, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = vader_effects_next_root(l0);
    l4 = ((vader_struct_vader_effects_Skeleton_t*) l0)->f_flows;
    t0 = vader_box_i64(292u, (int64_t)(uint64_t) l3);
    vader_struct_vader_effects_Flow_t* _a0_obj = (vader_struct_vader_effects_Flow_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_Flow_t));
    vader_obj_header_init(_a0_obj, 877u);
    _a0_obj->f_into = l1;
    _a0_obj->f_from = l2;
    _a0_obj->f_path = INT32_C(0);
    _a0_obj->f_copy = t0;
    l5 = (void*) _a0_obj;
    vader_array_push((vader_array_t*) l4, vader_ref_box(l5));
    { size_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_effects_add_flow(void* l0, size_t l1, size_t l2, int32_t l3) {
    void* l4 = NULL;
    void* l5 = NULL;
    void** gc_raw_roots[3] = { &l0, &l4, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l4 = ((vader_struct_vader_effects_Skeleton_t*) l0)->f_flows;
    vader_struct_vader_effects_Flow_t* _a0_obj = (vader_struct_vader_effects_Flow_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_Flow_t));
    vader_obj_header_init(_a0_obj, 877u);
    _a0_obj->f_into = l1;
    _a0_obj->f_from = l2;
    _a0_obj->f_path = l3;
    _a0_obj->f_copy = vader_box_obj(0u, NULL);
    l5 = (void*) _a0_obj;
    vader_array_push((vader_array_t*) l4, vader_ref_box(l5));
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_effects_add_mark(void* l0, size_t l1, int32_t l2, uint8_t l3) {
    void* l4 = NULL;
    void* l5 = NULL;
    void** gc_raw_roots[3] = { &l0, &l4, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l4 = ((vader_struct_vader_effects_Skeleton_t*) l0)->f_marks;
    vader_struct_vader_effects_Mark_t* _a0_obj = (vader_struct_vader_effects_Mark_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_Mark_t));
    vader_obj_header_init(_a0_obj, 885u);
    _a0_obj->f_slot = l1;
    _a0_obj->f_path = l2;
    _a0_obj->f_effect = l3;
    l5 = (void*) _a0_obj;
    vader_array_push((vader_array_t*) l4, vader_ref_box(l5));
    { vader_gc_top = gc_frame.prev; return; }
}

static size_t vader_effects_add_root(void* l0, size_t l1) {
    size_t l2;
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = vader_effects_next_root(l0);
    std_collections_MutableMap_IndexSet_set_at__usize__usize(((vader_struct_vader_effects_Skeleton_t*) l0)->f_seeds, l2, l1);
    { size_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static size_t vader_effects_add_site(void* l0, void* l1, void* l2) {
    size_t l3;
    void* l4 = NULL;
    void* l5 = NULL;
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l4, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = vader_effects_fresh_slot(l0);
    l4 = ((vader_struct_vader_effects_Skeleton_t*) l0)->f_sites;
    vader_struct_vader_effects_Site_t* _a0_obj = (vader_struct_vader_effects_Site_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_Site_t));
    vader_obj_header_init(_a0_obj, 893u);
    _a0_obj->f_targets = l1;
    _a0_obj->f_args = l2;
    _a0_obj->f_result = l3;
    l5 = (void*) _a0_obj;
    vader_array_push((vader_array_t*) l4, vader_ref_box(l5));
    { size_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_effects_any_effects(void) {
    void* l0 = NULL;
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(83u, 0u, 13u, 869u);
    l0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(17u, 0u, 8u, 286u);
    l1 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(13u, 0u, 12u, 280u);
    l2 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(16u, 0u, 7u, 285u);
    l3 = (void*) _a3_arr;
    vader_struct_std_collections_MutableMap__i64__bool_t* _a4_obj = (vader_struct_std_collections_MutableMap__i64__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i64__bool_t));
    vader_obj_header_init(_a4_obj, 385u);
    _a4_obj->f_ekeys = l1;
    _a4_obj->f_evals = l2;
    _a4_obj->f_index = l3;
    _a4_obj->f_mask = (size_t) 0;
    _a4_obj->f_size = (size_t) 0;
    _a4_obj->f_tombs = (size_t) 0;
    t0 = (void*) _a4_obj;
    vader_struct_std_collections_MutableSet__i64_t* _a5_obj = (vader_struct_std_collections_MutableSet__i64_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i64_t));
    vader_obj_header_init(_a5_obj, 486u);
    _a5_obj->f_inner = t0;
    l1 = (void*) _a5_obj;
    vader_struct_vader_effects_ParamEffects_t* _a6_obj = (vader_struct_vader_effects_ParamEffects_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_ParamEffects_t));
    vader_obj_header_init(_a6_obj, 886u);
    _a6_obj->f_accesses = l0;
    _a6_obj->f_keys = l1;
    l0 = (void*) _a6_obj;
    vader_struct_vader_effects_Access_t* _a7_obj = (vader_struct_vader_effects_Access_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_Access_t));
    vader_obj_header_init(_a7_obj, 869u);
    _a7_obj->f_path = INT32_C(1);
    _a7_obj->f_effect = (uint8_t) 5;
    l1 = (void*) _a7_obj;
    vader_effects_insert(l0, l1);
    vader_struct_vader_effects_Access_t* _a8_obj = (vader_struct_vader_effects_Access_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_Access_t));
    vader_obj_header_init(_a8_obj, 869u);
    _a8_obj->f_path = INT32_C(1);
    _a8_obj->f_effect = (uint8_t) 3;
    l1 = (void*) _a8_obj;
    vader_effects_insert(l0, l1);
    { void* __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_effects_apply_constraints(void* l0, void* l1, void* l2, void* l3, void* l4) {
    void* l5 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l11 = NULL;
    void* l14 = NULL;
    size_t l6, l7, l10;
    int32_t l12;
    uint8_t l13;
    int64_t t0;
    void** gc_raw_roots[10] = { &l0, &l1, &l2, &l3, &l4, &l5, &l8, &l9, &l11, &l14 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 10u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l5 = ((vader_struct_vader_effects_Skeleton_t*) l0)->f_marks;
    l6 = ((vader_array_t*) l5)->length;
    l7 = (size_t) 0;
    while ((l7 < l6)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l8 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l7);
        l9 = ((vader_struct_vader_effects_SlotRoots_t*) l1)->f_roots;
        l10 = ((vader_struct_vader_effects_Mark_t*) l8)->f_slot;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l9);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l10)
        l11 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l10);
        l12 = ((vader_struct_vader_effects_Mark_t*) l8)->f_path;
        l13 = ((vader_struct_vader_effects_Mark_t*) l8)->f_effect;
        l14 = ((vader_struct_vader_effects_EvalCtx_t*) l2)->f_paths;
        vader_effects_mark_roots(l3, l11, l12, l13, l14, false);
        t0 = (l7 + INT64_C(1));
        l7 = (size_t) (int64_t) t0;
    }
    l5 = ((vader_struct_vader_effects_Skeleton_t*) l0)->f_sites;
    l6 = ((vader_array_t*) l5)->length;
    l7 = (size_t) 0;
    while ((l7 < l6)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        l8 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l7);
        vader_effects_apply_site(l4, l1, l8, l2);
        t0 = (l7 + INT64_C(1));
        l7 = (size_t) (int64_t) t0;
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_effects_apply_site(void* l0, void* l1, void* l2, void* l3) {
    void* l4 = NULL;
    void* l8 = NULL;
    void* l15 = NULL;
    void* l16 = NULL;
    void* l19 = NULL;
    void* l20 = NULL;
    void* l23 = NULL;
    size_t l5, l6, l11, l12, l13, l17, l18;
    vader_box_t l7 = vader_box_null(), l9 = vader_box_null(), l14 = vader_box_null();
    bool l10;
    int32_t l21;
    uint8_t l22;
    int64_t t0;
    vader_box_t* gc_roots[3] = { &l7, &l9, &l14 };
    void** gc_raw_roots[11] = { &l0, &l1, &l2, &l3, &l4, &l8, &l15, &l16, &l19, &l20, &l23 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 11u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l4 = ((vader_struct_vader_effects_Site_t*) l2)->f_targets;
    l5 = ((vader_array_t*) l4)->length;
    l6 = (size_t) 0;
    while ((l6 < l5)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l7 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l6);
        l8 = ((vader_struct_vader_effects_EvalCtx_t*) l3)->f_facts;
        l9 = vader_effects_known_params(l7, l8);
        l10 = vader_effects_recursive(l3, l7);
        l11 = (size_t) 0;
        l12 = ((vader_array_t*) ((vader_struct_vader_effects_Site_t*) l2)->f_args)->length;
        while ((l11 < l12)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_effects_Site_t*) l2)->f_args);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l11)
            l14 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l11];
            if (l14.tag == 0u) {
                t0 = (l11 + INT64_C(1));
                l11 = (size_t) (int64_t) t0;
                continue;
            }
            l13 = ((size_t) l14.payload.i);
            l15 = ((vader_struct_vader_effects_EvalCtx_t*) l3)->f_any;
            l16 = vader_effects_accesses_of_param(l9, l11, l15);
            l17 = ((vader_array_t*) l16)->length;
            l18 = (size_t) 0;
            while ((l18 < l17)) {
                vader_array_t* _a2_slotarr = ((vader_array_t*) l16);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                l19 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l18);
                if (((vader_struct_vader_effects_Access_t*) l19)->f_effect != INT32_C(4)) {
                    vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_effects_SlotRoots_t*) l1)->f_roots);
                    VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l13)
                    l20 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l13);
                    l21 = ((vader_struct_vader_effects_Access_t*) l19)->f_path;
                    l22 = ((vader_struct_vader_effects_Access_t*) l19)->f_effect;
                    l23 = ((vader_struct_vader_effects_EvalCtx_t*) l3)->f_paths;
                    vader_effects_mark_roots(l0, l20, l21, l22, l23, l10);
                }
                t0 = (l18 + INT64_C(1));
                l18 = (size_t) (int64_t) t0;
            }
            t0 = (l11 + INT64_C(1));
            l11 = (size_t) (int64_t) t0;
        }
        t0 = (l6 + INT64_C(1));
        l6 = (size_t) (int64_t) t0;
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_string_t vader_effects_argument_label(void* l0, void* l1, int32_t l2) {
    vader_string_t l3 = 0;
    vader_string_t l6 = 0;
    vader_box_t l4 = vader_box_null();
    size_t l5;
    vader_string_t t0 = 0;
    vader_box_t* gc_roots[1] = { &l4 };
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_string_t* gc_atom_roots[3] = { &l3, &l6, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = vader_effects_display_steps(l1, l2);
    l4 = ((vader_struct_vader_effects_WideningSite_t*) l0)->f_callee;
    l5 = ((vader_struct_vader_effects_WideningSite_t*) l0)->f_param;
    l4 = vader_effects_parameter_name(l4, l5);
    if (!(l4.tag == 0u)) {
        l6 = l4.payload.s;
        t0 = concat_4(898u, l6, l3, 898u);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l3 == 0u)) {
        t0 = concat_3(1977u, l3, 898u);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return 1959u; }
}

static void vader_effects_assign(void* l0, vader_box_t l1, vader_box_t l2) {
    void* l3 = NULL;
    vader_box_t l4 = vader_box_null();
    vader_string_t l5 = 0;
    int32_t l6;
    void* t0 = NULL;
    vader_box_t* gc_roots[3] = { &l1, &l2, &l4 };
    void** gc_raw_roots[3] = { &l0, &l3, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l5 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l1.tag == 534u) {
        l3 = l1.payload.obj;
        vader_effects_assign_name(l0, l3, l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 527u) {
        t0 = l1.payload.obj;
        l4 = ((vader_struct_toolchain_ast_FieldExpr_t*) t0)->f_target;
        vader_effects_note_write(l0, l4);
        t0 = l1.payload.obj;
        l4 = ((vader_struct_toolchain_ast_FieldExpr_t*) t0)->f_target;
        l4 = vader_effects_value(l0, l4);
        l3 = ((vader_struct_vader_effects_CalleeIndex_t*) ((vader_struct_vader_effects_WalkCtx_t*) l0)->f_index)->f_paths;
        t0 = l1.payload.obj;
        l5 = vader_effects_field_step(t0);
        l6 = vader_effects_path_to(l3, l5);
        vader_effects_mark(l0, l4, l6, (uint8_t) 0);
        vader_effects_escape(l0, l2, (uint8_t) 3);
    } else if (l1.tag == 542u) {
        l3 = l1.payload.obj;
        vader_effects_assign_element(l0, l3, l2);
    } else {
        l4 = l1;
        vader_effects_discard(l0, l4);
        vader_effects_escape(l0, l2, (uint8_t) 3);
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_effects_assign_element(void* l0, void* l1, vader_box_t l2) {
    vader_box_t l3 = vader_box_null(), l4 = vader_box_null(), l6 = vader_box_null();
    size_t l5;
    void* l7 = NULL;
    void* l8 = NULL;
    int32_t l9;
    vader_box_t* gc_roots[4] = { &l2, &l3, &l4, &l6 };
    void** gc_raw_roots[4] = { &l0, &l1, &l7, &l8 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_toolchain_ast_IndexExpr_t*) l1)->f_target;
    vader_effects_note_write(l0, l3);
    l3 = ((vader_struct_toolchain_ast_IndexExpr_t*) l1)->f_target;
    l3 = vader_effects_value(l0, l3);
    l4 = ((vader_struct_toolchain_ast_IndexExpr_t*) l1)->f_index;
    l4 = vader_effects_value(l0, l4);
    l5 = ((vader_struct_toolchain_ast_IndexExpr_t*) l1)->f_id;
    l6 = vader_effects_site_callee(l0, (uint8_t) 3, l5);
    if (!(l6.tag == 0u)) {
        if (!(l6.tag == 1130u)) {
            if (!(l6.tag == 1142u)) {
                vader_array_t* _a0_arr = vader_array_new(206u, 3u, 0u, 1286u);
                vader_array_box_slots(_a0_arr->buf)[_a0_arr->offset + 2u] = l2;
                vader_array_box_slots(_a0_arr->buf)[_a0_arr->offset + 1u] = l4;
                vader_array_box_slots(_a0_arr->buf)[_a0_arr->offset + 0u] = l3;
                l7 = (void*) _a0_arr;
                l4 = ((vader_struct_toolchain_ast_IndexExpr_t*) l1)->f_index;
                vader_array_t* _a1_arr = vader_array_new(209u, 3u, 13u, 1373u);
                ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 2u] = vader_box_obj(0u, NULL).payload.obj;
                ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 1u] = l4.payload.obj;
                ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = vader_box_obj(0u, NULL).payload.obj;
                l8 = (void*) _a1_arr;
                vader_effects_call(l0, l6, l7, l8);
                { vader_gc_top = gc_frame.prev; return; }
            }
        }
    }
    l9 = vader_effects_path_to(((vader_struct_vader_effects_CalleeIndex_t*) ((vader_struct_vader_effects_WalkCtx_t*) l0)->f_index)->f_paths, 832u);
    vader_effects_mark(l0, l3, l9, (uint8_t) 0);
    vader_effects_escape(l0, l2, (uint8_t) 3);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_effects_assign_name(void* l0, void* l1, vader_box_t l2) {
    vader_box_t l3 = vader_box_null();
    size_t l4, l5;
    void* l6 = NULL;
    vader_box_t* gc_roots[2] = { &l2, &l3 };
    void** gc_raw_roots[3] = { &l0, &l1, &l6 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = vader_effects_ident_value(l0, l1);
    if (l3.tag == 0u) {
        vader_effects_escape(l0, l2, (uint8_t) 3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (!(l2.tag == 0u)) {
        l4 = ((size_t) l3.payload.i);
        l5 = ((size_t) l2.payload.i);
        l6 = ((vader_struct_toolchain_ast_IdentExpr_t*) l1)->f_span;
        vader_effects_bind_copy(l0, l4, l5, l6);
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_effects_binary_value(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l3 = vader_box_null(), l4 = vader_box_null(), l7 = vader_box_null(), l10 = vader_box_null();
    void* l5 = NULL;
    void* l9 = NULL;
    void* l11 = NULL;
    size_t l6;
    bool l8;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[6] = { &l2, &l3, &l4, &l7, &l10, &t1 };
    void** gc_raw_roots[6] = { &l0, &l1, &l5, &l9, &l11, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 6u, 6u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_toolchain_ast_BinaryExpr_t*) l1)->f_left;
    l2 = vader_effects_value(l0, l2);
    l3 = ((vader_struct_toolchain_ast_BinaryExpr_t*) l1)->f_right;
    l3 = vader_effects_value(l0, l3);
    l4 = ((vader_struct_toolchain_ast_BinaryExpr_t*) l1)->f_bind_as;
    if (!(l4.tag == 0u)) {
        t0 = l4.payload.obj;
        l5 = ((vader_struct_toolchain_ast_AsBinding_t*) t0)->f_span;
        vader_effects_bind_symbol(l0, l5, l2);
    }
    l6 = ((vader_struct_toolchain_ast_BinaryExpr_t*) l1)->f_id;
    l7 = vader_effects_site_callee(l0, (uint8_t) 1, l6);
    if (l7.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l4 = l7;
    if (((vader_struct_toolchain_ast_BinaryExpr_t*) l1)->f_op == INT32_C(19)) {
        l8 = true;
    } else {
        l8 = ((vader_struct_toolchain_ast_BinaryExpr_t*) l1)->f_op == INT32_C(20);
    }
    if (!(l8)) {
        vader_array_t* _a0_arr = vader_array_new(206u, 2u, 0u, 1286u);
        vader_array_box_slots(_a0_arr->buf)[_a0_arr->offset + 1u] = l3;
        vader_array_box_slots(_a0_arr->buf)[_a0_arr->offset + 0u] = l2;
        l9 = (void*) _a0_arr;
        l7 = ((vader_struct_toolchain_ast_BinaryExpr_t*) l1)->f_left;
        l10 = ((vader_struct_toolchain_ast_BinaryExpr_t*) l1)->f_right;
        vader_array_t* _a1_arr = vader_array_new(209u, 2u, 13u, 1373u);
        ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 1u] = l10.payload.obj;
        ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = l7.payload.obj;
        l11 = (void*) _a1_arr;
        t1 = vader_effects_call(l0, l4, l9, l11);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a2_arr = vader_array_new(206u, 2u, 0u, 1286u);
    vader_array_box_slots(_a2_arr->buf)[_a2_arr->offset + 1u] = l2;
    vader_array_box_slots(_a2_arr->buf)[_a2_arr->offset + 0u] = l3;
    l5 = (void*) _a2_arr;
    l2 = ((vader_struct_toolchain_ast_BinaryExpr_t*) l1)->f_right;
    l3 = ((vader_struct_toolchain_ast_BinaryExpr_t*) l1)->f_left;
    vader_array_t* _a3_arr = vader_array_new(209u, 2u, 13u, 1373u);
    ((void**) _a3_arr->buf->slots)[_a3_arr->offset + 1u] = l3.payload.obj;
    ((void**) _a3_arr->buf->slots)[_a3_arr->offset + 0u] = l2.payload.obj;
    l9 = (void*) _a3_arr;
    t1 = vader_effects_call(l0, l4, l5, l9);
    { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_effects_bind(void* l0, vader_box_t l1, vader_box_t l2) {
    void* l3 = NULL;
    size_t l4, l5;
    vader_box_t l6 = vader_box_null(), l7 = vader_box_null();
    void* t0 = NULL;
    int64_t t1;
    vader_box_t* gc_roots[4] = { &l1, &l2, &l6, &l7 };
    void** gc_raw_roots[3] = { &l0, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l1.tag == 569u) {
        t0 = l1.payload.obj;
        l3 = ((vader_struct_toolchain_ast_SimpleBinding_t*) t0)->f_name_span;
        vader_effects_bind_symbol(l0, l3, l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 581u) {
        t0 = l1.payload.obj;
        l3 = ((vader_struct_toolchain_ast_TupleBinding_t*) t0)->f_elements;
        l4 = ((vader_array_t*) l3)->length;
        l5 = (size_t) 0;
        while ((l5 < l4)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            l6 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
            l7 = vader_effects_step_slot(l0, l2, 832u);
            vader_effects_bind(l0, l6, l7);
            t1 = (l5 + INT64_C(1));
            l5 = (size_t) (int64_t) t1;
        }
    } else if (l1.tag == 565u) {
        t0 = l1.payload.obj;
        l3 = ((vader_struct_toolchain_ast_RestBinding_t*) t0)->f_span;
        vader_effects_bind_symbol(l0, l3, l2);
    } else if (!(l1.tag == 586u)) {
        vader_unreachable("non-exhaustive match (T3013 should have caught this)");
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_effects_bind_copy(void* l0, size_t l1, size_t l2, void* l3) {
    void* l4 = NULL;
    size_t t0;
    void** gc_raw_roots[3] = { &l0, &l3, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_effects_add_copy(((vader_struct_vader_effects_WalkCtx_t*) l0)->f_s, l1, l2);
    vader_struct_vader_effects_FrozenRoot_t* _a0_obj = (vader_struct_vader_effects_FrozenRoot_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_FrozenRoot_t));
    vader_obj_header_init(_a0_obj, 879u);
    _a0_obj->f_root = t0;
    _a0_obj->f_span = l3;
    _a0_obj->f_label = 0u;
    _a0_obj->f_binding = true;
    _a0_obj->f_constant = vader_box_obj(0u, NULL);
    _a0_obj->f_type = vader_box_obj(0u, NULL);
    l4 = (void*) _a0_obj;
    vader_array_push((vader_array_t*) ((vader_struct_vader_effects_WalkCtx_t*) l0)->f_roots, vader_ref_box(l4));
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_effects_bind_pattern(void* l0, vader_box_t l1, vader_box_t l2) {
    vader_box_t l3 = vader_box_null();
    void* l4 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    size_t l5, l6;
    vader_string_t l9 = 0;
    void* t0 = NULL;
    int64_t t1;
    vader_box_t* gc_roots[3] = { &l1, &l2, &l3 };
    void** gc_raw_roots[5] = { &l0, &l4, &l7, &l8, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l9 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l1.tag == 546u) {
        t0 = l1.payload.obj;
        l3 = ((vader_struct_toolchain_ast_IsPattern_t*) t0)->f_inner;
        if (!(l3.tag == 0u)) {
            vader_effects_bind_pattern(l0, l3, l2);
        }
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 578u) {
        t0 = l1.payload.obj;
        l4 = ((vader_struct_toolchain_ast_StructPattern_t*) t0)->f_fields;
        l5 = ((vader_array_t*) l4)->length;
        l6 = (size_t) 0;
        while ((l6 < l5)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            l7 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l6);
            if (((vader_struct_toolchain_ast_StructPatternField_t*) l7)->f_value.tag == 559u) {
                l8 = ((vader_struct_toolchain_ast_StructPatternField_t*) l7)->f_name_span;
                l9 = ((vader_struct_toolchain_ast_StructPatternField_t*) l7)->f_name;
                l3 = vader_effects_step_slot(l0, l2, l9);
                vader_effects_bind_symbol(l0, l8, l3);
            }
            t1 = (l6 + INT64_C(1));
            l6 = (size_t) (int64_t) t1;
        }
    } else if (l1.tag == 558u) {
        t0 = l1.payload.obj;
        l4 = ((vader_struct_toolchain_ast_OrPattern_t*) t0)->f_patterns;
        l5 = ((vader_array_t*) l4)->length;
        l6 = (size_t) 0;
        while ((l6 < l5)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l4);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            l3 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l6);
            vader_effects_bind_pattern(l0, l3, l2);
            t1 = (l6 + INT64_C(1));
            l6 = (size_t) (int64_t) t1;
        }
    } else if (!((l1.tag == 525u || l1.tag == 549u || l1.tag == 564u || l1.tag == 588u))) {
        vader_unreachable("non-exhaustive match (T3013 should have caught this)");
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_effects_bind_symbol(void* l0, void* l1, vader_box_t l2) {
    void* l3 = NULL;
    uint64_t l4;
    vader_box_t l5 = vader_box_null();
    int32_t l6;
    size_t l7, l8;
    vader_box_t* gc_roots[2] = { &l2, &l5 };
    void** gc_raw_roots[3] = { &l0, &l1, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_resolver_ResolvedModule_t*) ((vader_struct_vader_typecheck_TypedProgram_t*) ((vader_struct_vader_effects_WalkCtx_t*) l0)->f_typed)->f_resolved)->f_idents;
    l4 = toolchain_span_Span_Hash_hash(l1);
    l5 = std_collections_MutableMap_Index_at__u64__Any(l3, l4);
    if (l5.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l3 = l5.payload.obj;
    l6 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l3)->f_id;
    l7 = vader_effects_local_slot(l0, l6);
    if (l2.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l8 = ((size_t) l2.payload.i);
    vader_effects_bind_copy(l0, l7, l8, l1);
    { vader_gc_top = gc_frame.prev; return; }
}

static uint8_t vader_effects_binding_outcome(void* l0, void* l1) {
    void* l2 = NULL;
    bool t0;
    uint8_t t1;
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = (void*) &vader_fn_static_vader_effects_modifies;
    t0 = vader_effects_either(l1, l2);
    if (t0) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 3; }
    }
    l2 = (void*) &vader_fn_static_vader_effects_escapes;
    t0 = vader_effects_either(l1, l2);
    if (!(t0)) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 5; }
    }
    l2 = (void*) &vader_fn_static_vader_effects_escapes;
    t1 = vader_effects_copy_or_elided(l0, l1, l2);
    { uint8_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_effects_block_value(void* l0, void* l1) {
    void* l2 = NULL;
    size_t l3, l4;
    vader_box_t l5 = vader_box_null(), l6 = vader_box_null();
    int64_t t0;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l5, &l6, &t1 };
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_toolchain_ast_BlockExpr_t*) l1)->f_stmts;
    l3 = ((vader_array_t*) l2)->length;
    l4 = (size_t) 0;
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l5 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        vader_effects_stmt(l0, l5);
        t0 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t0;
    }
    l6 = ((vader_struct_toolchain_ast_BlockExpr_t*) l1)->f_trailing;
    if (l6.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l5 = l6;
    t1 = vader_effects_value(l0, l5);
    { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_effects_body_ctx(void* l0, void* l1, void* l2, void* l3) {
    void* l4 = NULL;
    void* l5 = NULL;
    int32_t l6;
    int32_t t0;
    void* t1 = NULL;
    void** gc_raw_roots[7] = { &l0, &l1, &l2, &l3, &l4, &l5, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 7u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_effects_FrozenBody_t*) l0)->f_node;
    if (!((t0 < INT32_C(0)))) {
        l6 = ((vader_struct_vader_effects_FrozenBody_t*) l0)->f_node;
        t1 = vader_effects_node_ctx(l1, l2, l3, l6);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a0_arr = vader_array_new(16u, 0u, 7u, 285u);
    l4 = (void*) _a0_arr;
    l5 = vader_effects_any_effects();
    vader_struct_vader_effects_EvalCtx_t* _a1_obj = (vader_struct_vader_effects_EvalCtx_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_EvalCtx_t));
    vader_obj_header_init(_a1_obj, 876u);
    _a1_obj->f_facts = l1;
    _a1_obj->f_paths = l2;
    _a1_obj->f_components = l4;
    _a1_obj->f_node = INT32_C(0);
    _a1_obj->f_any = l5;
    t1 = (void*) _a1_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_effects_bodyless_target(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void* l7 = NULL;
    size_t l5, l6;
    vader_string_t l8 = 0;
    vader_box_t l9 = vader_box_null();
    bool l10;
    bool t0;
    void* t1 = NULL;
    int64_t t2;
    vader_box_t* gc_roots[1] = { &l9 };
    void** gc_raw_roots[7] = { &l0, &l1, &l2, &l3, &l4, &l7, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l8 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = toolchain_ast_decorators_have(((vader_struct_toolchain_ast_FnDecl_t*) l1)->f_decorators, 1700u);
    if (t0) {
        l3 = ((vader_struct_toolchain_ast_FnDecl_t*) l1)->f_params;
        vader_array_t* _a0_arr = vader_array_new(92u, 0u, 13u, 886u);
        l4 = (void*) _a0_arr;
        l5 = ((vader_array_t*) l3)->length;
        vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l4, (size_t) l5);
        l4 = (void*) _a1_arr;
        l5 = ((vader_array_t*) l3)->length;
        l6 = (size_t) 0;
        while ((l6 < l5)) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            t1 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l6);
            l7 = vader_effects_foreign_effects(t1);
            vader_array_push((vader_array_t*) l4, vader_ref_box(l7));
            t2 = (l6 + INT64_C(1));
            l6 = (size_t) (int64_t) t2;
        }
        vader_struct_vader_effects_KnownEffects_t* _a3_obj = (vader_struct_vader_effects_KnownEffects_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_KnownEffects_t));
        vader_obj_header_init(_a3_obj, 884u);
        _a3_obj->f_params = l4;
        t1 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l8 = vader_effects_intrinsic_key(l0, l1, l2);
    t0 = vader_effects_makes_frozen_view(l8);
    if (t0) {
        l3 = ((vader_struct_vader_effects_CalleeIndex_t*) l0)->f_frozen_views;
        l5 = ((vader_struct_toolchain_ast_FnDecl_t*) l1)->f_id;
        std_collections_add__usize(l3, l5);
    }
    l9 = vader_effects_intrinsic_effects(((vader_struct_vader_effects_CalleeIndex_t*) l0)->f_paths, l8);
    if (!(l9.tag == 0u)) {
        t1 = l9.payload.obj;
        vader_struct_vader_effects_KnownEffects_t* _a4_obj = (vader_struct_vader_effects_KnownEffects_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_KnownEffects_t));
        vader_obj_header_init(_a4_obj, 884u);
        _a4_obj->f_params = t1;
        t1 = (void*) _a4_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = ((vader_struct_toolchain_ast_FnDecl_t*) l1)->f_params;
    vader_struct___lambda_env_vader_effects_12_t* _a5_obj = (vader_struct___lambda_env_vader_effects_12_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_effects_12_t));
    vader_obj_header_init(_a5_obj, 304u);
    _a5_obj->f_cap_0 = l2;
    l4 = (void*) _a5_obj;
    l10 = false;
    l5 = ((vader_array_t*) l3)->length;
    l6 = (size_t) 0;
    {
        for (;;) {
            if ((l6 < l5)) {
                vader_array_t* _a6_slotarr = ((vader_array_t*) l3);
                VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
                l7 = vader_array_ref_load_obj(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l6);
                t0 = __lambda_vader_effects_11(l4, l7);
                if (t0) {
                    t2 = (l6 + INT64_C(1));
                    l6 = (size_t) (int64_t) t2;
                    continue;
                }
                l10 = false;
                goto end_85;
            }
            break;
        }
        l10 = true;
    } end_85: ;
    if (!(l10)) {
        vader_array_push((vader_array_t*) ((vader_struct_vader_effects_CalleeIndex_t*) l0)->f_unknown, vader_box_string(282u, l8));
        vader_struct_vader_effects_AnyCallee_t* _a7_obj = (vader_struct_vader_effects_AnyCallee_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_AnyCallee_t));
        vader_obj_header_init(_a7_obj, 870u);
        t1 = (void*) _a7_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = ((vader_struct_toolchain_ast_FnDecl_t*) l1)->f_params;
    vader_array_t* _a8_arr = vader_array_new(92u, 0u, 13u, 886u);
    l4 = (void*) _a8_arr;
    l5 = ((vader_array_t*) l3)->length;
    vader_array_t* _a9_arr = vader_array_repeat((vader_array_t*) l4, (size_t) l5);
    l4 = (void*) _a9_arr;
    l5 = ((vader_array_t*) l3)->length;
    l6 = (size_t) 0;
    while ((l6 < l5)) {
        vader_array_t* _a10_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
        t1 = vader_array_ref_load_obj(_a10_slotarr->buf, _a10_slotarr->offset + (size_t) l6);
        l7 = __lambda_vader_effects_13(t1);
        vader_array_push((vader_array_t*) l4, vader_ref_box(l7));
        t2 = (l6 + INT64_C(1));
        l6 = (size_t) (int64_t) t2;
    }
    vader_struct_vader_effects_KnownEffects_t* _a11_obj = (vader_struct_vader_effects_KnownEffects_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_KnownEffects_t));
    vader_obj_header_init(_a11_obj, 884u);
    _a11_obj->f_params = l4;
    t1 = (void*) _a11_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_effects_breaks_widening(void* l0, void* l1, int32_t l2) {
    int32_t l3, l8;
    vader_box_t l4;
    uint8_t l5;
    bool l6, l9;
    void* l7;
    void* t0;
    l3 = ((vader_struct_vader_effects_Access_t*) l1)->f_path;
    l4 = vader_effects_chain_position(l0, l3, l2);
    if (l4.tag == 0u) {
        return false;
    }
    l3 = ((int32_t) l4.payload.i);
    l5 = ((vader_struct_vader_effects_Access_t*) l1)->f_effect;
    if (l5 == INT32_C(2)) {
        l6 = false;
        return l6;
    }
    if (l5 == INT32_C(0)) {
        if ((l3 >= INT32_C(1))) {
            l6 = true;
        } else {
            l7 = ((vader_struct_vader_effects_PathTable_t*) l0)->f_nodes;
            l8 = ((vader_struct_vader_effects_Access_t*) l1)->f_path;
            vader_array_t* _a0_slotarr = ((vader_array_t*) l7);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l8)
            t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l8);
            l6 = ((vader_struct_vader_effects_PathNode_t*) t0)->f_deeper;
        }
    } else {
        if (l5 == INT32_C(1)) {
            l9 = true;
        } else {
            l9 = l5 == INT32_C(3);
        }
        if (l9) {
            l9 = true;
        } else {
            l9 = l5 == INT32_C(4);
        }
        if (l9) {
            l9 = true;
        } else {
            l9 = l5 == INT32_C(5);
        }
        if (!(l9)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l6 = (l3 < l2);
    }
    return l6;
}

static vader_box_t vader_effects_call(void* l0, vader_box_t l1, void* l2, void* l3) {
    vader_box_t l4 = vader_box_null(), l8 = vader_box_null(), l9 = vader_box_null();
    void* l5 = NULL;
    size_t l6, l7;
    size_t t0;
    int64_t t1;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[5] = { &l1, &l4, &l8, &l9, &t2 };
    void** gc_raw_roots[4] = { &l0, &l2, &l3, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 5u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l4 = l1;
    if (l4.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l5 = vader_effects_targets_of(((vader_struct_vader_effects_WalkCtx_t*) l0)->f_index, l4);
    t0 = ((vader_array_t*) l5)->length;
    if (t0 == INT64_C(0)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l6 = (size_t) 0;
    l7 = ((vader_array_t*) l3)->length;
    while ((l6 < l7)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l9 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l6);
        if (l9.tag == 0u) {
            t1 = (l6 + INT64_C(1));
            l6 = (size_t) (int64_t) t1;
            continue;
        }
        l8 = l9;
        vader_effects_note_known_writes(l0, l5, l6, l8);
        vader_effects_note_widened(l0, l4, l5, l6, l8);
        t1 = (l6 + INT64_C(1));
        l6 = (size_t) (int64_t) t1;
    }
    t0 = vader_effects_add_site(((vader_struct_vader_effects_WalkCtx_t*) l0)->f_s, l5, l2);
    t2 = vader_box_i64(292u, (int64_t)(uint64_t) t0);
    { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_effects_call_sources(void* l0, void* l1, vader_box_t l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    vader_box_t l5 = vader_box_null();
    size_t l6, l7;
    bool t0;
    void* t1 = NULL;
    int64_t t2;
    vader_box_t* gc_roots[2] = { &l2, &l5 };
    void** gc_raw_roots[5] = { &l0, &l1, &l3, &l4, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(210u, 0u, 13u, 1374u);
    l3 = (void*) _a0_arr;
    if (((vader_struct_toolchain_ast_CallExpr_t*) l1)->f_callee.tag == 527u) {
        l4 = ((vader_struct_toolchain_ast_CallExpr_t*) l1)->f_callee.payload.obj;
        t0 = vader_effects_passes_receiver(l0, l1, l4, l2);
        if (t0) {
            l5 = ((vader_struct_toolchain_ast_FieldExpr_t*) l4)->f_target;
            vader_array_push((vader_array_t*) l3, l5);
        } else {
            l5 = ((vader_struct_toolchain_ast_FieldExpr_t*) l4)->f_target;
            vader_effects_discard(l0, l5);
        }
    } else {
        l5 = ((vader_struct_toolchain_ast_CallExpr_t*) l1)->f_callee;
        vader_effects_discard(l0, l5);
    }
    l4 = ((vader_struct_toolchain_ast_CallExpr_t*) l1)->f_args;
    l6 = ((vader_array_t*) l4)->length;
    l7 = (size_t) 0;
    while ((l7 < l6)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        t1 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l7);
        l5 = ((vader_struct_toolchain_ast_CallArg_t*) t1)->f_value;
        vader_array_push((vader_array_t*) l3, l5);
        t2 = (l7 + INT64_C(1));
        l7 = (size_t) (int64_t) t2;
    }
    { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_effects_call_value(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l4 = vader_box_null(), l9 = vader_box_null();
    size_t l3, l8;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* t0 = NULL;
    int64_t t1;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[4] = { &l2, &l4, &l9, &t2 };
    void** gc_raw_roots[6] = { &l0, &l1, &l5, &l6, &l7, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 6u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_toolchain_ast_CallExpr_t*) l1)->f_id;
    l4 = vader_effects_site_callee(l0, (uint8_t) 0, l3);
    if (l4.tag == 0u) {
        vader_struct_vader_typecheck_UnsettledCallee_t* _a0_obj = (vader_struct_vader_typecheck_UnsettledCallee_t*) vader_gc_alloc(sizeof(vader_struct_vader_typecheck_UnsettledCallee_t));
        vader_obj_header_init(_a0_obj, 1183u);
        t0 = (void*) _a0_obj;
        l2 = vader_ref_box(t0);
    } else {
        l2 = l4;
    }
    l5 = vader_effects_call_sources(l0, l1, l2);
    vader_array_t* _a1_arr = vader_array_new(206u, 0u, 0u, 1286u);
    l6 = (void*) _a1_arr;
    l3 = ((vader_array_t*) l5)->length;
    vader_array_t* _a2_arr = vader_array_repeat((vader_array_t*) l6, (size_t) l3);
    l6 = (void*) _a2_arr;
    l7 = l5;
    l3 = ((vader_array_t*) l7)->length;
    l8 = (size_t) 0;
    while ((l8 < l3)) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        l4 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l8);
        l9 = vader_effects_value(l0, l4);
        vader_array_push((vader_array_t*) l6, l9);
        t1 = (l8 + INT64_C(1));
        l8 = (size_t) (int64_t) t1;
    }
    if (!(l2.tag == 1130u)) {
        l4 = l2;
        l4 = vader_effects_call(l0, l4, l6, l5);
        l2 = vader_effects_frozen_view(l0, l1, l2);
        vader_array_t* _a4_arr = vader_array_new(206u, 2u, 0u, 1286u);
        vader_array_box_slots(_a4_arr->buf)[_a4_arr->offset + 1u] = l2;
        vader_array_box_slots(_a4_arr->buf)[_a4_arr->offset + 0u] = l4;
        l5 = (void*) _a4_arr;
        t2 = vader_effects_union_of(l0, l5);
        { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = vader_effects_single(l6);
    { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_effects_callee_nodes(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l5 = NULL;
    size_t l3, l4, l6, l7;
    vader_box_t l8 = vader_box_null();
    int32_t l9;
    void* t0 = NULL;
    int64_t t1;
    vader_box_t* gc_roots[1] = { &l8 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l5, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(16u, 0u, 7u, 285u);
    l1 = (void*) _a0_arr;
    l2 = ((vader_struct_vader_effects_Skeleton_t*) l0)->f_sites;
    l3 = ((vader_array_t*) l2)->length;
    l4 = (size_t) 0;
    while ((l4 < l3)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
        l5 = ((vader_struct_vader_effects_Site_t*) t0)->f_targets;
        l6 = ((vader_array_t*) l5)->length;
        l7 = (size_t) 0;
        vader_array_t* _pc22_hdr = (vader_array_t*) l1;
        size_t _pc22_len = _pc22_hdr->length;
        size_t _pc22_cap = (_pc22_hdr->offset == 0 && !vader_array_is_borrowed(_pc22_hdr) && _pc22_hdr->length >= _pc22_hdr->buf->length) ? _pc22_hdr->capacity : (size_t) 0;
        void* _pc22_slots = _pc22_hdr->buf->slots;
        for (;;) {
            if ((l7 < l6)) {
                vader_array_t* _a2_slotarr = ((vader_array_t*) l5);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                l8 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l7);
                if (l8.tag == 872u) {
                    t0 = l8.payload.obj;
                    l9 = ((vader_struct_vader_effects_CalleeNode_t*) t0)->f_node;
                    if (VADER_LIKELY(_pc22_len < _pc22_cap)) {
                        ((int32_t*) _pc22_slots)[_pc22_len] = (int32_t) (l9);
                        _pc22_len += 1;
                    } else {
                        _pc22_hdr->length = _pc22_len;
                        if (_pc22_hdr->buf->length < _pc22_len) {
                            _pc22_hdr->buf->length = _pc22_len;
                        }
                        vader_array_push_i32((vader_array_t*) l1, l9);
                        _pc22_hdr = (vader_array_t*) l1;
                        _pc22_len = _pc22_hdr->length;
                        _pc22_cap = (_pc22_hdr->offset == 0 && !vader_array_is_borrowed(_pc22_hdr) && _pc22_hdr->length >= _pc22_hdr->buf->length) ? _pc22_hdr->capacity : (size_t) 0;
                        _pc22_slots = _pc22_hdr->buf->slots;
                    }
                }
                t1 = (l7 + INT64_C(1));
                l7 = (size_t) (int64_t) t1;
                continue;
            }
            _pc22_hdr->length = _pc22_len;
            if (_pc22_hdr->buf->length < _pc22_len) {
                _pc22_hdr->buf->length = _pc22_len;
            }
            break;
        }
        t1 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t1;
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_effects_carried(void* l0, void* l1, void* l2) {
    size_t l3;
    int32_t l4, l5;
    void* t0 = NULL;
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_effects_Root_t*) l0)->f_param;
    l4 = ((vader_struct_vader_effects_Root_t*) l0)->f_path;
    l5 = ((vader_struct_vader_effects_Flow_t*) l1)->f_path;
    l4 = vader_effects_joined(l2, l4, l5);
    vader_struct_vader_effects_Root_t* _a0_obj = (vader_struct_vader_effects_Root_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_Root_t));
    vader_obj_header_init(_a0_obj, 890u);
    _a0_obj->f_param = l3;
    _a0_obj->f_path = l4;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_effects_chain_position(void* l0, int32_t l1, int32_t l2) {
    int32_t l3, l4, l6;
    void* l5;
    void* t0;
    int32_t t1;
    vader_box_t t2;
    vader_string_t t3;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_effects_PathTable_t*) l0)->f_nodes);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l1);
    l3 = ((vader_struct_vader_effects_PathNode_t*) t0)->f_length;
    if ((l3 > l2)) {
        return vader_box_obj(0u, NULL);
    }
    l4 = l1;
    for (;;) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_effects_PathTable_t*) l0)->f_nodes);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
        t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
        t1 = ((vader_struct_vader_effects_PathNode_t*) t0)->f_length;
        if ((t1 > INT32_C(0))) {
            l5 = ((vader_struct_vader_effects_PathTable_t*) l0)->f_step_names;
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
            t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
            l6 = ((vader_struct_vader_effects_PathNode_t*) t0)->f_step;
            vader_array_t* _a2_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l6)
            t2 = vader_array_box_slots(_a2_slotarr->buf)[_a2_slotarr->offset + (size_t) l6];
            t3 = t2.payload.s;
            if (t3 != 832u) {
                return vader_box_obj(0u, NULL);
            }
            vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_effects_PathTable_t*) l0)->f_nodes);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l4)
            t0 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l4);
            l4 = ((vader_struct_vader_effects_PathNode_t*) t0)->f_parent;
            continue;
        }
        break;
    }
    t2 = vader_box_i32(285u, l3);
    return t2;
}

static int32_t vader_effects_child(void* l0, int32_t l1, int32_t l2) {
    void* l3 = NULL;
    void* l7 = NULL;
    int64_t l4;
    vader_box_t l5 = vader_box_null();
    int32_t l6, l8;
    bool t0;
    int32_t t1;
    size_t t2;
    vader_box_t* gc_roots[1] = { &l5 };
    void** gc_raw_roots[3] = { &l0, &l3, &l7 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_effects_PathTable_t*) l0)->f_nodes);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    l3 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l1);
    t0 = ((vader_struct_vader_effects_PathNode_t*) l3)->f_deeper;
    if (t0) {
        { int32_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = ((vader_struct_vader_effects_PathNode_t*) l3)->f_length;
    if (t1 == INT32_C(3)) {
        t1 = vader_effects_cut(l0, l1);
        { int32_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = vader_effects_pair_key(l1, l2);
    l5 = std_collections_MutableMap_Index_at__i64__i32(((vader_struct_vader_effects_PathTable_t*) l0)->f_children, l4);
    if (!(l5.tag == 0u)) {
        t1 = ((int32_t) l5.payload.i);
        { int32_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = ((vader_array_t*) ((vader_struct_vader_effects_PathTable_t*) l0)->f_nodes)->length;
    l6 = ((int32_t) (size_t) t2);
    l7 = ((vader_struct_vader_effects_PathTable_t*) l0)->f_nodes;
    t1 = ((vader_struct_vader_effects_PathNode_t*) l3)->f_length;
    l8 = vader_chk_add(i32, t1, INT32_C(1));
    vader_struct_vader_effects_PathNode_t* _a1_obj = (vader_struct_vader_effects_PathNode_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_PathNode_t));
    vader_obj_header_init(_a1_obj, 887u);
    _a1_obj->f_parent = l1;
    _a1_obj->f_step = l2;
    _a1_obj->f_length = l8;
    _a1_obj->f_deeper = false;
    l3 = (void*) _a1_obj;
    vader_array_push((vader_array_t*) l7, vader_ref_box(l3));
    std_collections_MutableMap_IndexSet_set_at__i64__i32(((vader_struct_vader_effects_PathTable_t*) l0)->f_children, l4, l6);
    { int32_t __vret = l6; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_effects_collect_returned(void* l0, void* l1, void* l2) {
    bool l3, l10;
    void* l4 = NULL;
    void* l8 = NULL;
    void* l15 = NULL;
    void* l16 = NULL;
    void* l19 = NULL;
    void* l22 = NULL;
    size_t l5, l6, l11, l12, l13, l17, l18, l21;
    vader_box_t l7 = vader_box_null(), l9 = vader_box_null(), l14 = vader_box_null();
    int32_t l20;
    int64_t t0;
    bool t1;
    vader_box_t* gc_roots[3] = { &l7, &l9, &l14 };
    void** gc_raw_roots[9] = { &l0, &l1, &l2, &l4, &l8, &l15, &l16, &l19, &l22 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 9u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = false;
    l4 = ((vader_struct_vader_effects_Site_t*) l1)->f_targets;
    l5 = ((vader_array_t*) l4)->length;
    l6 = (size_t) 0;
    while ((l6 < l5)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l7 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l6);
        l8 = ((vader_struct_vader_effects_EvalCtx_t*) l2)->f_facts;
        l9 = vader_effects_known_params(l7, l8);
        l10 = vader_effects_recursive(l2, l7);
        l11 = (size_t) 0;
        l12 = ((vader_array_t*) ((vader_struct_vader_effects_Site_t*) l1)->f_args)->length;
        while ((l11 < l12)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_effects_Site_t*) l1)->f_args);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l11)
            l14 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l11];
            if (l14.tag == 0u) {
                t0 = (l11 + INT64_C(1));
                l11 = (size_t) (int64_t) t0;
                continue;
            }
            l13 = ((size_t) l14.payload.i);
            l15 = ((vader_struct_vader_effects_EvalCtx_t*) l2)->f_any;
            l16 = vader_effects_accesses_of_param(l9, l11, l15);
            l17 = ((vader_array_t*) l16)->length;
            l18 = (size_t) 0;
            while ((l18 < l17)) {
                vader_array_t* _a2_slotarr = ((vader_array_t*) l16);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                l19 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l18);
                if (((vader_struct_vader_effects_Access_t*) l19)->f_effect != INT32_C(4)) {
                    t0 = (l18 + INT64_C(1));
                    l18 = (size_t) (int64_t) t0;
                    continue;
                }
                l20 = ((vader_struct_vader_effects_Access_t*) l19)->f_path;
                l21 = ((vader_struct_vader_effects_Site_t*) l1)->f_result;
                l22 = ((vader_struct_vader_effects_EvalCtx_t*) l2)->f_paths;
                t1 = vader_effects_reroot_below(l0, l13, l20, l21, l22, l10);
                if (t1) {
                    l3 = true;
                }
                t0 = (l18 + INT64_C(1));
                l18 = (size_t) (int64_t) t0;
            }
            t0 = (l11 + INT64_C(1));
            l11 = (size_t) (int64_t) t0;
        }
        t0 = (l6 + INT64_C(1));
        l6 = (size_t) (int64_t) t0;
    }
    { bool __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_effects_component_of_each_node(void* l0) {
    size_t l1, l4, l6, l7;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l5 = NULL;
    int32_t l8, l9;
    int64_t t0;
    void** gc_raw_roots[4] = { &l0, &l2, &l3, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = ((vader_array_t*) ((vader_struct_vader_fixpoint_Graph_t*) l0)->f_successors)->length;
    l2 = (void*) &vader_fn_static___lambda_vader_effects_5;
    l2 = std_core_filled__i32(l1, l2);
    l3 = vader_fixpoint_components_bottom_up(l0);
    l1 = (size_t) 0;
    l4 = ((vader_array_t*) l3)->length;
    while ((l1 < l4)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l5 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l1);
        l6 = ((vader_array_t*) l5)->length;
        l7 = (size_t) 0;
        while ((l7 < l6)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            l8 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l7];
            l9 = ((int32_t) (size_t) l1);
            vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l8)
            ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l8] = (int32_t) l9;
            t0 = (l7 + INT64_C(1));
            l7 = (size_t) (int64_t) t0;
        }
        t0 = (l1 + INT64_C(1));
        l1 = (size_t) (int64_t) t0;
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static int32_t vader_effects_composed(void* l0, int32_t l1, int32_t l2, bool l3) {
    int32_t t0;
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l3) {
        if (l1 != INT32_C(0)) {
            if (l2 != INT32_C(0)) {
                t0 = vader_effects_cut(l0, l1);
                { int32_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
            }
            t0 = vader_effects_joined(l0, l1, l2);
            { int32_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        t0 = vader_effects_joined(l0, l1, l2);
        { int32_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_effects_joined(l0, l1, l2);
    { int32_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_effects_converted(void* l0, vader_box_t l1, vader_box_t l2) {
    size_t l3;
    vader_box_t l4 = vader_box_null();
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[4] = { &l1, &l2, &l4, &t1 };
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = l1.payload.obj;
    l3 = ((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t0)->f_id;
    l4 = vader_effects_site_callee(l0, (uint8_t) 4, l3);
    t1 = vader_effects_converted_by(l0, l4, l2, l1);
    { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_effects_converted_by(void* l0, vader_box_t l1, vader_box_t l2, vader_box_t l3) {
    vader_box_t l4 = vader_box_null();
    void* l5 = NULL;
    void* l6 = NULL;
    size_t t0;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[5] = { &l1, &l2, &l3, &l4, &t1 };
    void** gc_raw_roots[3] = { &l0, &l5, &l6 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 5u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l4 = l1;
    if (l4.tag == 0u) {
        { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a0_arr = vader_array_new(206u, 1u, 0u, 1286u);
    vader_array_box_slots(_a0_arr->buf)[_a0_arr->offset + 0u] = l2;
    l5 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(209u, 1u, 13u, 1373u);
    ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = l3.payload.obj;
    l6 = (void*) _a1_arr;
    l4 = vader_effects_call(l0, l4, l5, l6);
    if (!(l4.tag == 0u)) {
        t0 = ((size_t) l4.payload.i);
        t1 = vader_box_i64(292u, (int64_t)(uint64_t) t0);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static uint8_t vader_effects_copy_or_elided(void* l0, void* l1, void* l2) {
    bool t0;
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_effects_hands_on_written(l0, l1, l2);
    if (!(t0)) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 4; }
    }
    { vader_gc_top = gc_frame.prev; return (uint8_t) 3; }
}

static void* vader_effects_copy_to_effects(int32_t l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[6] = { &l1, &l2, &l3, &l4, &l5, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 6u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_effects_effects_of((uint8_t) 3, l0);
    l2 = vader_effects_none();
    l3 = vader_effects_effects_of((uint8_t) 0, l0);
    l4 = vader_effects_none();
    l5 = vader_effects_none();
    vader_array_t* _a0_arr = vader_array_new(92u, 5u, 13u, 886u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 4u] = l5;
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 3u] = l4;
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 2u] = l3;
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 1u] = l2;
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = l1;
    t0 = (void*) _a0_arr;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_effects_covered(void* l0, void* l1, void* l2) {
    int64_t l3;
    int32_t l4, l6;
    vader_box_t l5 = vader_box_null();
    uint8_t l7;
    bool t0;
    void* t1 = NULL;
    int32_t t2;
    vader_box_t* gc_roots[1] = { &l5 };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = vader_effects_access_key(l2);
    t0 = std_collections_MutableSet_Contains_contains__i64(((vader_struct_vader_effects_ParamEffects_t*) l1)->f_keys, l3);
    if (t0) {
        { vader_gc_top = gc_frame.prev; return true; }
    }
    l4 = ((vader_struct_vader_effects_Access_t*) l2)->f_path;
    for (;;) {
        l5 = std_collections_MutableMap_Index_at__i32__i32(((vader_struct_vader_effects_PathTable_t*) l0)->f_cuts, l4);
        if (!(l5.tag == 0u)) {
            l6 = ((int32_t) l5.payload.i);
            l7 = ((vader_struct_vader_effects_Access_t*) l2)->f_effect;
            t0 = vader_effects_holds(l1, l6, l7);
            if (t0) {
                { vader_gc_top = gc_frame.prev; return true; }
            }
        }
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_effects_PathTable_t*) l0)->f_nodes);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        t1 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        t2 = ((vader_struct_vader_effects_PathNode_t*) t1)->f_length;
        if (t2 == INT32_C(0)) {
            { vader_gc_top = gc_frame.prev; return false; }
        }
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_effects_PathTable_t*) l0)->f_nodes);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
        t1 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
        l4 = ((vader_struct_vader_effects_PathNode_t*) t1)->f_parent;
        continue;
    }
    vader_gc_top = gc_frame.prev;
}

bool vader_effects_covers(void* l0, void* l1, void* l2) {
    uint8_t l3, l4;
    bool l5;
    int32_t l6, l7;
    bool t0;
    l3 = ((vader_struct_vader_effects_Access_t*) l2)->f_effect;
    l4 = ((vader_struct_vader_effects_Access_t*) l1)->f_effect;
    if (l3 == l4) {
        l6 = ((vader_struct_vader_effects_Access_t*) l2)->f_path;
        l7 = ((vader_struct_vader_effects_Access_t*) l1)->f_path;
        l5 = l6 != l7;
    } else {
        l5 = false;
    }
    if (l5) {
        l6 = ((vader_struct_vader_effects_Access_t*) l2)->f_path;
        l7 = ((vader_struct_vader_effects_Access_t*) l1)->f_path;
        t0 = vader_effects_extends(l0, l6, l7);
        return t0;
    }
    return false;
}

static int32_t vader_effects_cut(void* l0, int32_t l1) {
    void* l2 = NULL;
    void* l5 = NULL;
    vader_box_t l3 = vader_box_null();
    int32_t l4, l6, l7, l8;
    bool t0;
    int32_t t1;
    size_t t2;
    vader_box_t* gc_roots[1] = { &l3 };
    void** gc_raw_roots[3] = { &l0, &l2, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_effects_PathTable_t*) l0)->f_nodes);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    l2 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l1);
    t0 = ((vader_struct_vader_effects_PathNode_t*) l2)->f_deeper;
    if (t0) {
        { int32_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = std_collections_MutableMap_Index_at__i32__i32(((vader_struct_vader_effects_PathTable_t*) l0)->f_cuts, l1);
    if (!(l3.tag == 0u)) {
        t1 = ((int32_t) l3.payload.i);
        { int32_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = ((vader_array_t*) ((vader_struct_vader_effects_PathTable_t*) l0)->f_nodes)->length;
    l4 = ((int32_t) (size_t) t2);
    l5 = ((vader_struct_vader_effects_PathTable_t*) l0)->f_nodes;
    l6 = ((vader_struct_vader_effects_PathNode_t*) l2)->f_parent;
    l7 = ((vader_struct_vader_effects_PathNode_t*) l2)->f_step;
    l8 = ((vader_struct_vader_effects_PathNode_t*) l2)->f_length;
    vader_struct_vader_effects_PathNode_t* _a1_obj = (vader_struct_vader_effects_PathNode_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_PathNode_t));
    vader_obj_header_init(_a1_obj, 887u);
    _a1_obj->f_parent = l6;
    _a1_obj->f_step = l7;
    _a1_obj->f_length = l8;
    _a1_obj->f_deeper = true;
    l2 = (void*) _a1_obj;
    vader_array_push((vader_array_t*) l5, vader_ref_box(l2));
    std_collections_MutableMap_IndexSet_set_at__i32__i32(((vader_struct_vader_effects_PathTable_t*) l0)->f_cuts, l1, l4);
    { int32_t __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_effects_decide(void* l0, void* l1, void* l2, void* l3, void* l4) {
    void* l5 = NULL;
    void* l7 = NULL;
    void* l9 = NULL;
    vader_box_t l6 = vader_box_null();
    size_t l8, l13, l14;
    uint8_t l10;
    vader_string_t l11 = 0;
    bool l12;
    void* t0 = NULL;
    bool t1;
    int64_t t2;
    vader_box_t* gc_roots[1] = { &l6 };
    void** gc_raw_roots[9] = { &l0, &l1, &l2, &l3, &l4, &l5, &l7, &l9, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l11 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 9u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l6 = vader_effects_held_by(l2, l3);
    if (l6.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l5 = l6.payload.obj;
    l7 = ((vader_struct_vader_effects_RootEffects_t*) l3)->f_marked;
    l8 = ((vader_struct_vader_effects_FrozenRoot_t*) l2)->f_root;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l7);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l8)
    t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l8);
    l7 = ((vader_struct_vader_effects_ParamEffects_t*) t0)->f_accesses;
    l9 = ((vader_struct_vader_effects_RootEffects_t*) l3)->f_lent;
    l8 = ((vader_struct_vader_effects_FrozenRoot_t*) l2)->f_root;
    vader_array_t* _a1_slotarr = ((vader_array_t*) l9);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l8)
    t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l8);
    l9 = ((vader_struct_vader_effects_ParamEffects_t*) t0)->f_accesses;
    vader_struct_vader_effects_RootCase_t* _a2_obj = (vader_struct_vader_effects_RootCase_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_RootCase_t));
    vader_obj_header_init(_a2_obj, 891u);
    _a2_obj->f_body = l1;
    _a2_obj->f_paths = l4;
    _a2_obj->f_held = l5;
    _a2_obj->f_marked = l7;
    _a2_obj->f_lent = l9;
    l7 = (void*) _a2_obj;
    vader_effects_note_kept_by_constant(l0, l7, l2);
    l6 = vader_effects_outcome(l0, l7, l2);
    if (l6.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l10 = ((uint8_t) l6.payload.i);
    vader_array_t* _a3_slotarr = ((vader_array_t*) l5);
    VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a3_slotarr, INT32_C(0))
    t0 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) INT32_C(0));
    l8 = ((vader_struct_vader_effects_Root_t*) t0)->f_param;
    t0 = vader_effects_root_record(l1, l8);
    l11 = ((vader_struct_vader_effects_FrozenRoot_t*) t0)->f_label;
    l9 = ((vader_struct_vader_effects_RootEffects_t*) l3)->f_mixed;
    l8 = ((vader_struct_vader_effects_FrozenRoot_t*) l2)->f_root;
    l12 = std_collections_MutableSet_Contains_contains__usize(l9, l8);
    vader_effects_record(l0, l1, l2, l10, l11, l12);
    t1 = vader_effects_reads_fresh(l0, l7, l10);
    if (t1) {
        l8 = ((vader_array_t*) l5)->length;
        l13 = (size_t) 0;
        while ((l13 < l8)) {
            vader_array_t* _a4_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
            t0 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l13);
            l14 = ((vader_struct_vader_effects_Root_t*) t0)->f_param;
            l7 = vader_effects_root_record(l1, l14);
            vader_effects_read_fresh(l0, l7);
            t2 = (l13 + INT64_C(1));
            l13 = (size_t) (int64_t) t2;
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_effects_defer_stmt(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l3 = vader_box_null(), l4 = vader_box_null();
    void* l5 = NULL;
    void* t0 = NULL;
    vader_box_t* gc_roots[3] = { &l2, &l3, &l4 };
    void** gc_raw_roots[4] = { &l0, &l1, &l5, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_toolchain_ast_DeferStmt_t*) l1)->f_body;
    l3 = l2;
    if (l2.tag == 517u) {
        t0 = l3.payload.obj;
        l4 = ((vader_struct_toolchain_ast_DeferStmtBody_t*) t0)->f_stmt;
        vader_effects_stmt(l0, l4);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (!(l2.tag == 515u)) {
        vader_unreachable("non-exhaustive match (T3013 should have caught this)");
    }
    t0 = l3.payload.obj;
    l5 = ((vader_struct_toolchain_ast_DeferBlockBody_t*) t0)->f_block;
    vader_effects_block_value(l0, l5);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_effects_destructure_assign(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l6 = vader_box_null(), l7 = vader_box_null(), l8 = vader_box_null(), l9 = vader_box_null();
    void* l3 = NULL;
    size_t l4, l5;
    void* t0 = NULL;
    int64_t t1;
    vader_box_t* gc_roots[5] = { &l2, &l6, &l7, &l8, &l9 };
    void** gc_raw_roots[4] = { &l0, &l1, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 5u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_toolchain_ast_DestructureAssignStmt_t*) l1)->f_value;
    l2 = vader_effects_value(l0, l2);
    l3 = ((vader_struct_toolchain_ast_DestructureAssignStmt_t*) l1)->f_targets;
    l4 = ((vader_array_t*) l3)->length;
    l5 = (size_t) 0;
    while ((l5 < l4)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l6 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
        if (l6.tag == 561u) {
            t0 = l6.payload.obj;
            l7 = ((vader_struct_toolchain_ast_PlaceTarget_t*) t0)->f_place;
            l8 = vader_effects_step_slot(l0, l2, 832u);
            vader_effects_assign(l0, l7, l8);
        } else if (l6.tag == 566u) {
            t0 = l6.payload.obj;
            l9 = ((vader_struct_toolchain_ast_RestTarget_t*) t0)->f_place;
            vader_effects_assign(l0, l9, l2);
        } else if (!(l6.tag == 589u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        t1 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t1;
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void* vader_effects_direct_targets(void* l0, void* l1) {
    void* l2 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    vader_box_t l3 = vader_box_null(), l6 = vader_box_null();
    vader_string_t l7 = 0;
    vader_string_t l8 = 0;
    bool t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[2] = { &l3, &l6 };
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l4, &l5, &t1 };
    vader_string_t* gc_atom_roots[2] = { &l7, &l8 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_typecheck_DirectFn_t*) l1)->f_decl;
    l3 = vader_effects_target_of_decl(l0, l2);
    t0 = ((vader_struct_vader_typecheck_DirectFn_t*) l1)->f_per_instance;
    if (!(t0)) {
        vader_array_t* _a0_arr = vader_array_new(231u, 1u, 13u, 1559u);
        ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = l3.payload.obj;
        t1 = (void*) _a0_arr;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = ((vader_struct_vader_effects_CalleeIndex_t*) l0)->f_impls;
    l5 = ((vader_struct_vader_typecheck_DirectFn_t*) l1)->f_decl;
    l6 = vader_typecheck_member_entry(l4, l5);
    if (l6.tag == 0u) {
        vader_array_t* _a1_arr = vader_array_new(231u, 1u, 13u, 1559u);
        ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = l3.payload.obj;
        t1 = (void*) _a1_arr;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = l6.payload.obj;
    vader_array_t* _a2_arr = vader_array_new(231u, 1u, 13u, 1559u);
    ((void**) _a2_arr->buf->slots)[_a2_arr->offset + 0u] = l3.payload.obj;
    l4 = (void*) _a2_arr;
    l7 = ((vader_struct_vader_typecheck_ImplEntry_t*) l2)->f_trait_key;
    l8 = ((vader_struct_toolchain_ast_FnDecl_t*) ((vader_struct_vader_typecheck_DirectFn_t*) l1)->f_decl)->f_name;
    l2 = vader_effects_member_targets(l0, l7, l8);
    vader_array_push_all((vader_array_t*) l4, (vader_array_t*) l2);
    { void* __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_effects_discard(void* l0, vader_box_t l1) {
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_effects_value(l0, l1);
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_string_t vader_effects_display_callee(vader_box_t l0) {
    vader_string_t l1 = 0;
    vader_string_t l2 = 0;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[1] = { &t0 };
    vader_string_t* gc_atom_roots[2] = { &l1, &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l0.tag == 1138u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_toolchain_ast_FnDecl_t*) ((vader_struct_vader_typecheck_DirectFn_t*) t0)->f_decl)->f_name;
        l1 = concat_3(898u, l1, 898u);
        { vader_string_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1128u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_typecheck_BoundMember_t*) t0)->f_member;
        l1 = concat_3(898u, l2, 898u);
    } else if (l0.tag == 1175u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_typecheck_TraitMember_t*) t0)->f_member;
        l1 = concat_3(898u, l2, 898u);
    } else if (l0.tag == 1147u) {
        l1 = 1254u;
    } else {
        if (!((l0.tag == 1130u || l0.tag == 1139u || l0.tag == 1142u || l0.tag == 1183u))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = 2418u;
    }
    { vader_string_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_effects_display_steps(void* l0, int32_t l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    size_t l4, l5;
    int32_t l6;
    vader_string_t l7 = 0;
    vader_string_t l8 = 0;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    int64_t t2;
    vader_string_t t3 = 0;
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[4] = { &l0, &l2, &l3, &t0 };
    vader_string_t* gc_atom_roots[3] = { &l7, &l8, &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(15u, 0u, 0u, 282u);
    t0 = (void*) _a0_arr;
    vader_struct_std_string_builder_StringBuilder_t* _a1_obj = (vader_struct_std_string_builder_StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string_builder_StringBuilder_t));
    vader_obj_header_init(_a1_obj, 498u);
    _a1_obj->f_parts = t0;
    l2 = (void*) _a1_obj;
    l3 = vader_effects_steps_of(l0, l1);
    l4 = ((vader_array_t*) l3)->length;
    l5 = (size_t) 0;
    while ((l5 < l4)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        l6 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l5];
        vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_effects_PathTable_t*) l0)->f_step_names);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l6)
        t1 = vader_array_box_slots(_a3_slotarr->buf)[_a3_slotarr->offset + (size_t) l6];
        l7 = t1.payload.s;
        if (l7 == 832u) {
            std_string_builder_append(l2, 832u);
        } else {
            l8 = concat_2(319u, l7);
            std_string_builder_append(l2, l8);
        }
        t2 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t2;
    }
    t3 = std_string_builder_StringBuilder_Display_to_string(l2);
    { vader_string_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_effects_drop_covered(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    bool l5;
    size_t l6, l7;
    int64_t l10;
    bool t0;
    int64_t t1;
    void** gc_raw_roots[7] = { &l0, &l1, &l2, &l3, &l4, &l8, &l9 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 7u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_effects_ParamEffects_t*) l1)->f_accesses;
    vader_struct___lambda_env_vader_effects_15_t* _a0_obj = (vader_struct___lambda_env_vader_effects_15_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_effects_15_t));
    vader_obj_header_init(_a0_obj, 305u);
    _a0_obj->f_cap_0 = l0;
    _a0_obj->f_cap_1 = l2;
    l4 = (void*) _a0_obj;
    l5 = false;
    l6 = ((vader_array_t*) l3)->length;
    l7 = (size_t) 0;
    {
        while ((l7 < l6)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            l8 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l7);
            t0 = __lambda_vader_effects_14(l4, l8);
            if (t0) {
                l5 = true;
                goto end_13;
            }
            t1 = (l7 + INT64_C(1));
            l7 = (size_t) (int64_t) t1;
        }
        l5 = false;
    } end_13: ;
    if (!(l5)) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_array_t* _a2_arr = vader_array_new(83u, 0u, 13u, 869u);
    l3 = (void*) _a2_arr;
    l4 = ((vader_struct_vader_effects_ParamEffects_t*) l1)->f_accesses;
    l6 = ((vader_array_t*) l4)->length;
    l7 = (size_t) 0;
    while ((l7 < l6)) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        l8 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l7);
        t0 = vader_effects_covers(l0, l2, l8);
        if (t0) {
            l9 = ((vader_struct_vader_effects_ParamEffects_t*) l1)->f_keys;
            l10 = vader_effects_access_key(l8);
            std_collections_remove__i64(l9, l10);
        } else {
            vader_array_push((vader_array_t*) l3, vader_ref_box(l8));
        }
        t1 = (l7 + INT64_C(1));
        l7 = (size_t) (int64_t) t1;
    }
    ((vader_struct_vader_effects_ParamEffects_t*) l1)->f_accesses = l3;
    VADER_WRITE_BARRIER((vader_struct_vader_effects_ParamEffects_t*) l1);
    { vader_gc_top = gc_frame.prev; return; }
}

static void* vader_effects_each_targets(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l8 = NULL;
    size_t l5, l6, l9, l10;
    vader_box_t l7 = vader_box_null(), l11 = vader_box_null();
    int64_t t0;
    vader_box_t* gc_roots[2] = { &l7, &l11 };
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l3, &l4, &l8 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 6u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = l1;
    vader_struct___lambda_env_vader_effects_23_t* _a0_obj = (vader_struct___lambda_env_vader_effects_23_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_effects_23_t));
    vader_obj_header_init(_a0_obj, 309u);
    _a0_obj->f_cap_0 = l0;
    l3 = (void*) _a0_obj;
    vader_array_t* _a1_arr = vader_array_new(231u, 0u, 13u, 1559u);
    l4 = (void*) _a1_arr;
    l5 = ((vader_array_t*) l2)->length;
    l6 = (size_t) 0;
    while ((l6 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        l7 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l6);
        l8 = __lambda_vader_effects_22(l3, l7);
        l9 = ((vader_array_t*) l8)->length;
        l10 = (size_t) 0;
        while ((l10 < l9)) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l8);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            l11 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l10);
            vader_array_push((vader_array_t*) l4, l11);
            t0 = (l10 + INT64_C(1));
            l10 = (size_t) (int64_t) t0;
        }
        t0 = (l6 + INT64_C(1));
        l6 = (size_t) (int64_t) t0;
    }
    { void* __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_effects_effects_of(uint8_t l0, int32_t l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[5] = { &l2, &l3, &l4, &l5, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(83u, 0u, 13u, 869u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(17u, 0u, 8u, 286u);
    l3 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(13u, 0u, 12u, 280u);
    l4 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(16u, 0u, 7u, 285u);
    l5 = (void*) _a3_arr;
    vader_struct_std_collections_MutableMap__i64__bool_t* _a4_obj = (vader_struct_std_collections_MutableMap__i64__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i64__bool_t));
    vader_obj_header_init(_a4_obj, 385u);
    _a4_obj->f_ekeys = l3;
    _a4_obj->f_evals = l4;
    _a4_obj->f_index = l5;
    _a4_obj->f_mask = (size_t) 0;
    _a4_obj->f_size = (size_t) 0;
    _a4_obj->f_tombs = (size_t) 0;
    t0 = (void*) _a4_obj;
    vader_struct_std_collections_MutableSet__i64_t* _a5_obj = (vader_struct_std_collections_MutableSet__i64_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i64_t));
    vader_obj_header_init(_a5_obj, 486u);
    _a5_obj->f_inner = t0;
    l3 = (void*) _a5_obj;
    vader_struct_vader_effects_ParamEffects_t* _a6_obj = (vader_struct_vader_effects_ParamEffects_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_ParamEffects_t));
    vader_obj_header_init(_a6_obj, 886u);
    _a6_obj->f_accesses = l2;
    _a6_obj->f_keys = l3;
    l2 = (void*) _a6_obj;
    vader_struct_vader_effects_Access_t* _a7_obj = (vader_struct_vader_effects_Access_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_Access_t));
    vader_obj_header_init(_a7_obj, 869u);
    _a7_obj->f_path = l1;
    _a7_obj->f_effect = l0;
    l3 = (void*) _a7_obj;
    vader_effects_insert(l2, l3);
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_effects_either(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    bool l4;
    size_t l5, l6;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    bool t2;
    int64_t t3;
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_effects_RootCase_t*) l0)->f_marked;
    l3 = l1;
    l4 = false;
    l5 = ((vader_array_t*) l2)->length;
    l6 = (size_t) 0;
    {
        while ((l6 < l5)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l6)
            t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l6);
            vader_fn_t* _a1_fnobj = (vader_fn_t*) l3;
            t1 = ((vader_fn_erased_sig_1_t) _a1_fnobj->code)(_a1_fnobj->env, vader_ref_box(t0));
            t2 = t1.payload.b;
            if (t2) {
                l4 = true;
                goto end_11;
            }
            t3 = (l6 + INT64_C(1));
            l6 = (size_t) (int64_t) t3;
        }
        l4 = false;
    } end_11: ;
    if (l4) {
        { vader_gc_top = gc_frame.prev; return true; }
    }
    l2 = ((vader_struct_vader_effects_RootCase_t*) l0)->f_lent;
    l3 = l1;
    l4 = false;
    l5 = ((vader_array_t*) l2)->length;
    l6 = (size_t) 0;
    {
        while ((l6 < l5)) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l6)
            t0 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l6);
            vader_fn_t* _a3_fnobj = (vader_fn_t*) l3;
            t1 = ((vader_fn_erased_sig_1_t) _a3_fnobj->code)(_a3_fnobj->env, vader_ref_box(t0));
            t2 = t1.payload.b;
            if (t2) {
                l4 = true;
                goto end_52;
            }
            t3 = (l6 + INT64_C(1));
            l6 = (size_t) (int64_t) t3;
        }
        l4 = false;
    } end_52: ;
    { bool __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_effects_else_value(void* l0, vader_box_t l1) {
    vader_box_t l2 = vader_box_null();
    void* l3 = NULL;
    void* t0 = NULL;
    vader_box_t* gc_roots[2] = { &l1, &l2 };
    void** gc_raw_roots[3] = { &l0, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l1.tag == 536u) {
        t0 = l1.payload.obj;
        l3 = ((vader_struct_toolchain_ast_IfElseIf_t*) t0)->f_branch;
        l2 = vader_effects_if_value(l0, l3);
        { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 535u) {
        t0 = l1.payload.obj;
        l3 = ((vader_struct_toolchain_ast_IfElseBlock_t*) t0)->f_block;
        l2 = vader_effects_block_value(l0, l3);
    } else {
        if (!(l1.tag == 0u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l2 = vader_box_obj(0u, NULL);
    }
    { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_effects_escape(void* l0, vader_box_t l1, uint8_t l2) {
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_effects_mark(l0, l1, INT32_C(0), l2);
    { vader_gc_top = gc_frame.prev; return; }
}

bool vader_effects_escapes(void* l0) {
    bool t0;
    t0 = vader_effects_modifies(l0);
    return !(t0);
}

static void* vader_effects_evaluate(void* l0, void* l1) {
    void* l2 = NULL;
    void* l4 = NULL;
    size_t l3;
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = vader_effects_settled_slots(l0, l1, false);
    l3 = ((vader_struct_vader_effects_Skeleton_t*) l0)->f_params;
    l4 = (void*) &vader_fn_static___lambda_vader_effects_8;
    l4 = std_core_filled__ParamEffects(l3, l4);
    vader_effects_apply_constraints(l0, l2, l1, l4, l4);
    { void* __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_effects_evaluate_roots(void* l0, void* l1) {
    void* l2 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    void* l13 = NULL;
    void* l15 = NULL;
    void* l18 = NULL;
    void* l19 = NULL;
    void* l21 = NULL;
    void* l23 = NULL;
    void* l24 = NULL;
    size_t l3, l4, l11, l14, l16, l17, l20;
    vader_box_t l12 = vader_box_null(), l22 = vader_box_null();
    int64_t t0;
    void* t1 = NULL;
    bool t2;
    vader_box_t* gc_roots[2] = { &l12, &l22 };
    void** gc_raw_roots[17] = {
        &l0, &l1, &l2, &l5, &l6, &l7, &l8, &l9, &l10, &l13, &l15, &l18, &l19, &l21, &l23, &l24, &t1,
    };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 17u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = vader_effects_settled_slots(l0, l1, true);
    l3 = ((vader_struct_vader_effects_Skeleton_t*) l0)->f_params;
    l4 = ((vader_struct_vader_effects_Skeleton_t*) l0)->f_extra;
    t0 = vader_chk_add(usize, l3, l4);
    l3 = (size_t) (int64_t) t0;
    l5 = (void*) &vader_fn_static___lambda_vader_effects_9;
    l5 = std_core_filled__ParamEffects(l3, l5);
    l6 = (void*) &vader_fn_static___lambda_vader_effects_10;
    l6 = std_core_filled__ParamEffects(l3, l6);
    vader_effects_apply_constraints(l0, l2, l1, l5, l6);
    vader_array_t* _a0_arr = vader_array_new(22u, 0u, 4u, 292u);
    l7 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(23u, 0u, 0u, 293u);
    l8 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(16u, 0u, 7u, 285u);
    l9 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__usize__Any___t* _a3_obj = (vader_struct_std_collections_MutableMap__usize__Any___t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__usize__Any___t));
    vader_obj_header_init(_a3_obj, 466u);
    _a3_obj->f_ekeys = l7;
    _a3_obj->f_evals = l8;
    _a3_obj->f_index = l9;
    _a3_obj->f_mask = (size_t) 0;
    _a3_obj->f_size = (size_t) 0;
    _a3_obj->f_tombs = (size_t) 0;
    l7 = (void*) _a3_obj;
    vader_array_t* _a4_arr = vader_array_new(22u, 0u, 4u, 292u);
    l8 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_new(13u, 0u, 12u, 280u);
    l9 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(16u, 0u, 7u, 285u);
    l10 = (void*) _a6_arr;
    vader_struct_std_collections_MutableMap__usize__bool_t* _a7_obj = (vader_struct_std_collections_MutableMap__usize__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__usize__bool_t));
    vader_obj_header_init(_a7_obj, 480u);
    _a7_obj->f_ekeys = l8;
    _a7_obj->f_evals = l9;
    _a7_obj->f_index = l10;
    _a7_obj->f_mask = (size_t) 0;
    _a7_obj->f_size = (size_t) 0;
    _a7_obj->f_tombs = (size_t) 0;
    t1 = (void*) _a7_obj;
    vader_struct_std_collections_MutableSet__usize_t* _a8_obj = (vader_struct_std_collections_MutableSet__usize_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__usize_t));
    vader_obj_header_init(_a8_obj, 489u);
    _a8_obj->f_inner = t1;
    l8 = (void*) _a8_obj;
    l9 = ((vader_struct_vader_effects_Skeleton_t*) l0)->f_flows;
    l3 = ((vader_array_t*) l9)->length;
    l4 = (size_t) 0;
    while ((l4 < l3)) {
        vader_array_t* _a9_slotarr = ((vader_array_t*) l9);
        VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
        l10 = vader_array_ref_load_obj(_a9_slotarr->buf, _a9_slotarr->offset + (size_t) l4);
        l12 = ((vader_struct_vader_effects_Flow_t*) l10)->f_copy;
        if (l12.tag == 0u) {
            t0 = (l4 + INT64_C(1));
            l4 = (size_t) (int64_t) t0;
            continue;
        }
        l11 = ((size_t) l12.payload.i);
        l13 = ((vader_struct_vader_effects_SlotRoots_t*) l2)->f_roots;
        l14 = ((vader_struct_vader_effects_Flow_t*) l10)->f_from;
        vader_array_t* _a10_slotarr = ((vader_array_t*) l13);
        VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a10_slotarr, l14)
        l15 = vader_array_ref_load_obj(_a10_slotarr->buf, _a10_slotarr->offset + (size_t) l14);
        l16 = ((vader_array_t*) l15)->length;
        l17 = (size_t) 0;
        while ((l17 < l16)) {
            vader_array_t* _a11_slotarr = ((vader_array_t*) l15);
            VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
            l18 = vader_array_ref_load_obj(_a11_slotarr->buf, _a11_slotarr->offset + (size_t) l17);
            l19 = ((vader_struct_vader_effects_Skeleton_t*) l0)->f_seeds;
            l20 = ((vader_struct_vader_effects_Root_t*) l18)->f_param;
            t2 = std_collections_MutableMap_Contains_contains__usize__usize(l19, l20);
            if (t2) {
                l22 = std_collections_MutableMap_Index_at__usize__Any(l7, l11);
                if (l22.tag == 0u) {
                    vader_array_t* _a12_arr = vader_array_new(95u, 0u, 13u, 890u);
                    l21 = (void*) _a12_arr;
                } else {
                    l21 = l22.payload.obj;
                }
                l23 = ((vader_struct_vader_effects_EvalCtx_t*) l1)->f_paths;
                l24 = vader_effects_carried(l18, l10, l23);
                vader_array_push((vader_array_t*) l21, vader_ref_box(l24));
                std_collections_MutableMap_IndexSet_set_at__usize__Any(l7, l11, vader_ref_box(l21));
            } else {
                std_collections_add__usize(l8, l11);
            }
            t0 = (l17 + INT64_C(1));
            l17 = (size_t) (int64_t) t0;
        }
        t0 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t0;
    }
    vader_struct_vader_effects_RootEffects_t* _a13_obj = (vader_struct_vader_effects_RootEffects_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_RootEffects_t));
    vader_obj_header_init(_a13_obj, 892u);
    _a13_obj->f_marked = l5;
    _a13_obj->f_lent = l6;
    _a13_obj->f_took = l7;
    _a13_obj->f_mixed = l8;
    t1 = (void*) _a13_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_effects_extends(void* l0, int32_t l1, int32_t l2) {
    int32_t l3, l4;
    void* t0;
    int32_t t1;
    vader_box_t t2, t3;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_effects_PathTable_t*) l0)->f_nodes);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
    t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
    l3 = ((vader_struct_vader_effects_PathNode_t*) t0)->f_length;
    l4 = l1;
    for (;;) {
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        t1 = ((vader_struct_vader_effects_PathNode_t*) t0)->f_length;
        if ((t1 > l3)) {
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
            t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
            l4 = ((vader_struct_vader_effects_PathNode_t*) t0)->f_parent;
            continue;
        }
        break;
    }
    vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_effects_PathTable_t*) l0)->f_nodes);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
    t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
    t1 = ((vader_struct_vader_effects_PathNode_t*) t0)->f_length;
    if (t1 != l3) {
        return false;
    }
    if (l4 == l2) {
        return true;
    }
    t2 = std_collections_MutableMap_Index_at__i32__i32(((vader_struct_vader_effects_PathTable_t*) l0)->f_cuts, l4);
    t3 = vader_box_i32(285u, l2);
    return vader_box_eq(t2, t3);
}

static vader_box_t vader_effects_fallback_value(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    vader_box_t l3 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l1, &l3, &t0 };
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l1.tag == 567u) {
        l2 = l1.payload.obj;
        vader_effects_return_stmt(l0, l2);
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    if ((l1.tag == 507u || l1.tag == 513u)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    if (!((l1.tag == 499u || l1.tag == 503u || l1.tag == 504u || l1.tag == 505u || l1.tag == 506u || l1.tag == 509u || l1.tag == 510u || l1.tag == 511u || l1.tag == 522u || l1.tag == 527u || l1.tag == 528u || l1.tag == 531u || l1.tag == 533u || l1.tag == 534u || l1.tag == 537u || l1.tag == 542u || l1.tag == 544u || l1.tag == 545u || l1.tag == 547u || l1.tag == 551u || l1.tag == 553u || l1.tag == 556u || l1.tag == 557u || l1.tag == 563u || l1.tag == 568u || l1.tag == 570u || l1.tag == 575u || l1.tag == 584u))) {
        vader_unreachable("non-exhaustive match (T3013 should have caught this)");
    }
    l3 = l1;
    t0 = vader_effects_value(l0, l3);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_effects_ffi_call_effects(int32_t l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[5] = { &l1, &l2, &l3, &l4, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_effects_none();
    l2 = vader_effects_none();
    l3 = vader_effects_effects_of((uint8_t) 0, l0);
    l4 = vader_effects_none();
    vader_array_t* _a0_arr = vader_array_new(92u, 4u, 13u, 886u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 3u] = l4;
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 2u] = l3;
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 1u] = l2;
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = l1;
    t0 = (void*) _a0_arr;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_effects_field_step(void* l0) {
    bool t0;
    vader_string_t t1;
    t0 = ((vader_struct_toolchain_ast_FieldExpr_t*) l0)->f_is_numeric;
    if (!(t0)) {
        t1 = ((vader_struct_toolchain_ast_FieldExpr_t*) l0)->f_field;
        return t1;
    }
    return 832u;
}

static vader_box_t vader_effects_field_value(void* l0, void* l1) {
    void* l2 = NULL;
    vader_box_t l3 = vader_box_null(), l4 = vader_box_null();
    vader_string_t l5 = 0;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l3, &l4, &t0 };
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_string_t* gc_atom_roots[1] = { &l5 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = vader_effects_namespace_member(l0, l1);
    if (l3.tag == 0u) {
        l4 = ((vader_struct_toolchain_ast_FieldExpr_t*) l1)->f_target;
        l4 = vader_effects_value(l0, l4);
        l5 = vader_effects_field_step(l1);
        t0 = vader_effects_step_slot(l0, l4, l5);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = l3.payload.obj;
    t0 = vader_effects_frozen_use(l0, vader_ref_box(l1), l2);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_effects_fields_may_be_written(void* l0, void* l1, void* l2, void* l3) {
    int32_t l4;
    void* l5 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    vader_box_t l6 = vader_box_null();
    size_t l9, l10;
    bool t0;
    vader_box_t t1 = vader_box_null();
    vader_string_t t2 = 0;
    int64_t t3;
    vader_box_t* gc_roots[2] = { &l6, &t1 };
    void** gc_raw_roots[7] = { &l0, &l1, &l2, &l3, &l5, &l7, &l8 };
    vader_string_t* gc_atom_roots[1] = { &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_types_StructType_t*) l1)->f_symbol)->f_id;
    t0 = std_collections_add__i32(l3, l4);
    if (!(t0)) {
        { vader_gc_top = gc_frame.prev; return false; }
    }
    l5 = ((vader_struct_vader_typecheck_TypedProgram_t*) l2)->f_struct_field_types;
    l4 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_types_StructType_t*) l1)->f_symbol)->f_id;
    l6 = std_collections_MutableMap_Index_at__i32__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_(l5, l4);
    if (l6.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return true; }
    }
    l5 = l6.payload.obj;
    l7 = ((vader_struct_std_collections_MutableMap__string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_t*) l5)->f_ekeys;
    l8 = ((vader_struct_std_collections_MutableMap__string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_t*) l5)->f_evals;
    l9 = ((vader_struct_std_collections_MutableMap__string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_t*) l5)->f_size;
    l10 = (size_t) 0;
    for (;;) {
        if (!((l10 >= l9))) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l7);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l10)
            t1 = vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l10];
            t2 = t1.payload.s;
            vader_array_t* _a1_slotarr = ((vader_array_t*) l8);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l10)
            l6 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l10);
            t3 = (l10 + INT64_C(1));
            l10 = (size_t) (int64_t) t3;
            t0 = vader_effects_may_be_written(l0, l6, l2, l3);
            if (!(t0)) {
                continue;
            }
            { vader_gc_top = gc_frame.prev; return true; }
        }
        break;
    }
    { vader_gc_top = gc_frame.prev; return false; }
}

static void* vader_effects_first_cuts(void) {
    void* l0 = NULL;
    void* l1 = NULL;
    void* l2 = NULL;
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(16u, 0u, 7u, 285u);
    l0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(16u, 0u, 7u, 285u);
    l1 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(16u, 0u, 7u, 285u);
    l2 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__i32__i32_t* _a3_obj = (vader_struct_std_collections_MutableMap__i32__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__i32_t));
    vader_obj_header_init(_a3_obj, 380u);
    _a3_obj->f_ekeys = l0;
    _a3_obj->f_evals = l1;
    _a3_obj->f_index = l2;
    _a3_obj->f_mask = (size_t) 0;
    _a3_obj->f_size = (size_t) 0;
    _a3_obj->f_tombs = (size_t) 0;
    l0 = (void*) _a3_obj;
    std_collections_MutableMap_IndexSet_set_at__i32__i32(l0, INT32_C(0), INT32_C(1));
    { void* __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_effects_first_paths(void) {
    void* l0 = NULL;
    void* l1 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[3] = { &l0, &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_effects_PathNode_t* _a0_obj = (vader_struct_vader_effects_PathNode_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_PathNode_t));
    vader_obj_header_init(_a0_obj, 887u);
    _a0_obj->f_parent = INT32_C(0);
    _a0_obj->f_step = INT32_C(0);
    _a0_obj->f_length = INT32_C(0);
    _a0_obj->f_deeper = false;
    l0 = (void*) _a0_obj;
    vader_struct_vader_effects_PathNode_t* _a1_obj = (vader_struct_vader_effects_PathNode_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_PathNode_t));
    vader_obj_header_init(_a1_obj, 887u);
    _a1_obj->f_parent = INT32_C(0);
    _a1_obj->f_step = INT32_C(0);
    _a1_obj->f_length = INT32_C(0);
    _a1_obj->f_deeper = true;
    l1 = (void*) _a1_obj;
    vader_array_t* _a2_arr = vader_array_new(93u, 2u, 13u, 887u);
    ((void**) _a2_arr->buf->slots)[_a2_arr->offset + 1u] = l1;
    ((void**) _a2_arr->buf->slots)[_a2_arr->offset + 0u] = l0;
    t0 = (void*) _a2_arr;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_effects_flowed_root(void* l0, void* l1, void* l2, void* l3) {
    vader_box_t l4 = vader_box_null();
    size_t l5;
    void* t0 = NULL;
    bool t1;
    size_t t2;
    vader_box_t* gc_roots[1] = { &l4 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l4 = ((vader_struct_vader_effects_Flow_t*) l1)->f_copy;
    if (l4.tag == 0u) {
        t0 = vader_effects_carried(l0, l1, l3);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l5 = ((vader_struct_vader_effects_Root_t*) l0)->f_param;
    t1 = std_collections_MutableMap_Contains_contains__usize__usize(l2, l5);
    if (t1) {
        t2 = ((size_t) l4.payload.i);
        vader_struct_vader_effects_Root_t* _a0_obj = (vader_struct_vader_effects_Root_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_Root_t));
        vader_obj_header_init(_a0_obj, 890u);
        _a0_obj->f_param = t2;
        _a0_obj->f_path = INT32_C(0);
        t0 = (void*) _a0_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_effects_carried(l0, l1, l3);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_effects_for_stmt(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l3 = vader_box_null(), l4 = vader_box_null();
    void* l5 = NULL;
    void* l6 = NULL;
    void* t0 = NULL;
    vader_box_t* gc_roots[3] = { &l2, &l3, &l4 };
    void** gc_raw_roots[5] = { &l0, &l1, &l5, &l6, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_toolchain_ast_ForStmt_t*) l1)->f_form;
    l3 = l2;
    if (l2.tag == 543u) {
        l6 = ((vader_struct_toolchain_ast_ForStmt_t*) l1)->f_body;
        vader_effects_block_value(l0, l6);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 585u) {
        t0 = l3.payload.obj;
        l4 = ((vader_struct_toolchain_ast_WhileFor_t*) t0)->f_cond;
        vader_effects_discard(l0, l4);
    } else {
        if (!(l2.tag == 541u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        t0 = l3.payload.obj;
        l2 = ((vader_struct_toolchain_ast_InFor_t*) t0)->f_iter;
        t0 = l3.payload.obj;
        l4 = ((vader_struct_toolchain_ast_InFor_t*) t0)->f_iter;
        l4 = vader_effects_value(l0, l4);
        l2 = vader_effects_loop_element(l0, l2, l4);
        t0 = l3.payload.obj;
        l3 = ((vader_struct_toolchain_ast_InFor_t*) t0)->f_loop_var;
        l4 = l3;
        if (l3.tag == 555u) {
            t0 = l4.payload.obj;
            l5 = ((vader_struct_toolchain_ast_NamedVar_t*) t0)->f_span;
            vader_effects_bind_symbol(l0, l5, l2);
        } else if (l3.tag == 520u) {
            t0 = l4.payload.obj;
            l4 = ((vader_struct_toolchain_ast_DestructureVar_t*) t0)->f_pattern;
            vader_effects_bind(l0, l4, l2);
        } else if (!(l3.tag == 521u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
    }
    l6 = ((vader_struct_toolchain_ast_ForStmt_t*) l1)->f_body;
    vader_effects_block_value(l0, l6);
    { vader_gc_top = gc_frame.prev; return; }
}

static void* vader_effects_foreign_effects(void* l0) {
    bool t0;
    void* t1 = NULL;
    void** gc_raw_roots[2] = { &l0, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = toolchain_ast_decorators_have(((vader_struct_toolchain_ast_FnParam_t*) l0)->f_decorators, 1475u);
    if (!(t0)) {
        t1 = vader_effects_none();
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_effects_effects_of((uint8_t) 0, INT32_C(1));
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static size_t vader_effects_fresh_slot(void* l0) {
    size_t l1, l2;
    size_t t0;
    int64_t t1;
    l1 = ((vader_struct_vader_effects_Skeleton_t*) l0)->f_slots;
    t0 = ((vader_struct_vader_effects_Skeleton_t*) l0)->f_slots;
    t1 = vader_chk_add(usize, t0, INT64_C(1));
    l2 = (size_t) (int64_t) t1;
    ((vader_struct_vader_effects_Skeleton_t*) l0)->f_slots = l2;
    return l1;
}

static size_t vader_effects_frozen_source(void* l0, vader_box_t l1, vader_string_t l2, vader_box_t l3) {
    size_t l4, l5, l8;
    void* l6 = NULL;
    void* l7 = NULL;
    vader_box_t l9 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[3] = { &l1, &l3, &l9 };
    void** gc_raw_roots[4] = { &l0, &l6, &l7, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = vader_effects_fresh_slot(((vader_struct_vader_effects_WalkCtx_t*) l0)->f_s);
    l5 = vader_effects_add_root(((vader_struct_vader_effects_WalkCtx_t*) l0)->f_s, l4);
    t0 = l1.payload.obj;
    l6 = ((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t0)->f_span;
    l7 = ((vader_struct_vader_typecheck_TypedProgram_t*) ((vader_struct_vader_effects_WalkCtx_t*) l0)->f_typed)->f_expr_types;
    t0 = l1.payload.obj;
    l8 = ((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t0)->f_id;
    l9 = std_collections_MutableMap_Index_at__usize__Any(l7, l8);
    vader_struct_vader_effects_FrozenRoot_t* _a0_obj = (vader_struct_vader_effects_FrozenRoot_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_FrozenRoot_t));
    vader_obj_header_init(_a0_obj, 879u);
    _a0_obj->f_root = l5;
    _a0_obj->f_span = l6;
    _a0_obj->f_label = l2;
    _a0_obj->f_binding = false;
    _a0_obj->f_constant = l3;
    _a0_obj->f_type = l9;
    l6 = (void*) _a0_obj;
    vader_array_push((vader_array_t*) ((vader_struct_vader_effects_WalkCtx_t*) l0)->f_roots, vader_ref_box(l6));
    { size_t __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_effects_frozen_use(void* l0, vader_box_t l1, void* l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    size_t l5;
    int32_t l6;
    vader_string_t l7 = 0;
    bool t0;
    void* t1 = NULL;
    vader_box_t t2 = vader_box_null();
    size_t t3;
    vader_box_t* gc_roots[2] = { &l1, &t2 };
    void** gc_raw_roots[5] = { &l0, &l2, &l3, &l4, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l7 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_effects_WalkCtx_t*) l0)->f_typed;
    l3 = vader_typecheck_declared_symbol(l2, l3);
    t0 = vader_resolver_symbol_is_frozen_const(l3);
    if (t0) {
        l4 = ((vader_struct_vader_typecheck_TypedProgram_t*) ((vader_struct_vader_effects_WalkCtx_t*) l0)->f_typed)->f_expr_types;
        t1 = l1.payload.obj;
        l5 = ((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t1)->f_id;
        t2 = std_collections_MutableMap_Index_at__usize__Any(l4, l5);
        t0 = vader_effects_holds_references(t2);
        if (t0) {
            t1 = l1.payload.obj;
            l5 = ((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t1)->f_id;
            l6 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l3)->f_id;
            vader_struct_vader_effects_ConstantUse_t* _a0_obj = (vader_struct_vader_effects_ConstantUse_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_ConstantUse_t));
            vader_obj_header_init(_a0_obj, 874u);
            _a0_obj->f_node = l5;
            _a0_obj->f_symbol = l6;
            l3 = (void*) _a0_obj;
            l7 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l2)->f_name;
            t3 = vader_effects_frozen_source(l0, l1, l7, vader_ref_box(l3));
            t2 = vader_box_i64(292u, (int64_t)(uint64_t) t3);
            { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
        }
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static vader_box_t vader_effects_frozen_view(void* l0, void* l1, vader_box_t l2) {
    size_t l3;
    void* t0 = NULL;
    bool t1;
    size_t t2;
    vader_box_t t3 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l2, &t3 };
    void** gc_raw_roots[3] = { &l0, &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l2.tag == 1138u) {
        t0 = l2.payload.obj;
        l3 = ((vader_struct_toolchain_ast_FnDecl_t*) ((vader_struct_vader_typecheck_DirectFn_t*) t0)->f_decl)->f_id;
        t1 = std_collections_MutableSet_Contains_contains__usize(((vader_struct_vader_effects_CalleeIndex_t*) ((vader_struct_vader_effects_WalkCtx_t*) l0)->f_index)->f_frozen_views, l3);
        if (!(!(t1))) {
            t2 = vader_effects_frozen_source(l0, vader_ref_box(l1), 1458u, vader_box_obj(0u, NULL));
            t3 = vader_box_i64(292u, (int64_t)(uint64_t) t2);
            { vader_box_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
        }
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static bool vader_effects_hands_on_written(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    void* t0 = NULL;
    bool t1;
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct___lambda_env_vader_effects_17_t* _a0_obj = (vader_struct___lambda_env_vader_effects_17_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_effects_17_t));
    vader_obj_header_init(_a0_obj, 306u);
    _a0_obj->f_cap_0 = l2;
    _a0_obj->f_cap_1 = l1;
    _a0_obj->f_cap_2 = l0;
    t0 = (void*) _a0_obj;
    vader_fn_t* _a1_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
    vader_obj_header_init(_a1_closure, 264u);
    _a1_closure->code = (void*) &vader_fn_lift___lambda_vader_effects_16;
    _a1_closure->env = t0;
    l3 = (void*) _a1_closure;
    t1 = vader_effects_either(l1, l3);
    { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

bool vader_effects_has_news(void* l0, int32_t l1, void* l2) {
    int64_t l3;
    void* l4 = NULL;
    void* l5 = NULL;
    bool l6;
    size_t l7, l8;
    int32_t l9;
    bool t0;
    int64_t t1;
    void** gc_raw_roots[4] = { &l0, &l2, &l4, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_effects_Clock_t*) l0)->f_evaluated_at);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    l3 = ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l1];
    if (l3 == INT64_C(0)) {
        { vader_gc_top = gc_frame.prev; return true; }
    }
    l4 = l2;
    vader_struct___lambda_env_vader_effects_7_t* _a1_obj = (vader_struct___lambda_env_vader_effects_7_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_effects_7_t));
    vader_obj_header_init(_a1_obj, 312u);
    _a1_obj->f_cap_0 = l0;
    _a1_obj->f_cap_1 = l3;
    l5 = (void*) _a1_obj;
    l6 = false;
    l7 = ((vader_array_t*) l4)->length;
    l8 = (size_t) 0;
    {
        while ((l8 < l7)) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) l4);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            l9 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l8];
            t0 = __lambda_vader_effects_6(l5, l9);
            if (t0) {
                l6 = true;
                goto end_22;
            }
            t1 = (l8 + INT64_C(1));
            l8 = (size_t) (int64_t) t1;
        }
        l6 = false;
    } end_22: ;
    { bool __vret = l6; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_effects_held_by(void* l0, void* l1) {
    void* l2 = NULL;
    size_t l3;
    bool t0;
    size_t t1;
    void* t2 = NULL;
    vader_box_t t3 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t3 };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_effects_FrozenRoot_t*) l0)->f_binding;
    if (!(t0)) {
        t1 = ((vader_struct_vader_effects_FrozenRoot_t*) l0)->f_root;
        vader_struct_vader_effects_Root_t* _a0_obj = (vader_struct_vader_effects_Root_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_Root_t));
        vader_obj_header_init(_a0_obj, 890u);
        _a0_obj->f_param = t1;
        _a0_obj->f_path = INT32_C(0);
        t2 = (void*) _a0_obj;
        vader_array_t* _a1_arr = vader_array_new(95u, 1u, 13u, 890u);
        ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = t2;
        t2 = (void*) _a1_arr;
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = ((vader_struct_vader_effects_RootEffects_t*) l1)->f_took;
    l3 = ((vader_struct_vader_effects_FrozenRoot_t*) l0)->f_root;
    t3 = std_collections_MutableMap_Index_at__usize__Any(l2, l3);
    { vader_box_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_effects_holds(void* l0, int32_t l1, uint8_t l2) {
    int64_t l3;
    void* t0 = NULL;
    bool t1;
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_effects_Access_t* _a0_obj = (vader_struct_vader_effects_Access_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_Access_t));
    vader_obj_header_init(_a0_obj, 869u);
    _a0_obj->f_path = l1;
    _a0_obj->f_effect = l2;
    t0 = (void*) _a0_obj;
    l3 = vader_effects_access_key(t0);
    t1 = std_collections_MutableSet_Contains_contains__i64(((vader_struct_vader_effects_ParamEffects_t*) l0)->f_keys, l3);
    { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

bool vader_effects_holds_references(vader_box_t l0) {
    vader_box_t l1;
    bool t0;
    l1 = l0;
    if (l1.tag == 0u) {
        return true;
    }
    t0 = vader_typecheck_is_value_only_type(l1);
    return !(t0);
}

static vader_box_t vader_effects_ident_value(void* l0, void* l1) {
    void* l2 = NULL;
    void* l5 = NULL;
    uint64_t l3;
    vader_box_t l4 = vader_box_null();
    int32_t l6;
    size_t t0;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l4, &t1 };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_resolver_ResolvedModule_t*) ((vader_struct_vader_typecheck_TypedProgram_t*) ((vader_struct_vader_effects_WalkCtx_t*) l0)->f_typed)->f_resolved)->f_idents;
    l3 = toolchain_span_Span_Hash_hash(((vader_struct_toolchain_ast_IdentExpr_t*) l1)->f_span);
    l4 = std_collections_MutableMap_Index_at__u64__Any(l2, l3);
    if (l4.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l2 = l4.payload.obj;
    l5 = ((vader_struct_vader_effects_WalkCtx_t*) l0)->f_slots;
    l6 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l2)->f_id;
    l4 = std_collections_MutableMap_Index_at__i32__usize(l5, l6);
    if (!(l4.tag == 0u)) {
        t0 = ((size_t) l4.payload.i);
        t1 = vader_box_i64(292u, (int64_t)(uint64_t) t0);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_effects_frozen_use(l0, vader_ref_box(l1), l2);
    { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_effects_if_value(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l4 = vader_box_null();
    void* l3 = NULL;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l2, &l4, &t0 };
    void** gc_raw_roots[3] = { &l0, &l1, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_toolchain_ast_IfExpr_t*) l1)->f_cond;
    vader_effects_discard(l0, l2);
    l3 = ((vader_struct_toolchain_ast_IfExpr_t*) l1)->f_then_block;
    l2 = vader_effects_block_value(l0, l3);
    l4 = ((vader_struct_toolchain_ast_IfExpr_t*) l1)->f_else_branch;
    l4 = vader_effects_else_value(l0, l4);
    vader_array_t* _a0_arr = vader_array_new(206u, 2u, 0u, 1286u);
    vader_array_box_slots(_a0_arr->buf)[_a0_arr->offset + 1u] = l4;
    vader_array_box_slots(_a0_arr->buf)[_a0_arr->offset + 0u] = l2;
    l3 = (void*) _a0_arr;
    t0 = vader_effects_union_of(l0, l3);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_effects_include(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    int32_t l4;
    bool t0;
    void* t1 = NULL;
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_effects_covered(l0, l1, l2);
    if (t0) {
        { vader_gc_top = gc_frame.prev; return false; }
    }
    l3 = ((vader_struct_vader_effects_PathTable_t*) l0)->f_nodes;
    l4 = ((vader_struct_vader_effects_Access_t*) l2)->f_path;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
    t1 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
    t0 = ((vader_struct_vader_effects_PathNode_t*) t1)->f_deeper;
    if (t0) {
        vader_effects_drop_covered(l0, l1, l2);
        vader_effects_insert(l1, l2);
        { vader_gc_top = gc_frame.prev; return true; }
    }
    vader_effects_insert(l1, l2);
    { vader_gc_top = gc_frame.prev; return true; }
}

static bool vader_effects_include_all(void* l0, void* l1, void* l2) {
    bool l3;
    void* l4 = NULL;
    void* l7 = NULL;
    size_t l5, l6;
    bool t0;
    int64_t t1;
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l4, &l7 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = false;
    l4 = ((vader_struct_vader_effects_ParamEffects_t*) l2)->f_accesses;
    l5 = ((vader_array_t*) l4)->length;
    l6 = (size_t) 0;
    while ((l6 < l5)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l7 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l6);
        t0 = vader_effects_include(l0, l1, l7);
        if (t0) {
            l3 = true;
        }
        t1 = (l6 + INT64_C(1));
        l6 = (size_t) (int64_t) t1;
    }
    { bool __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_effects_include_root(void* l0, size_t l1, void* l2) {
    int64_t l3, l4;
    size_t t0;
    int64_t t1;
    int32_t t2;
    bool t3;
    void* t4 = NULL;
    void** gc_raw_roots[3] = { &l0, &l2, &t4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((int64_t) (size_t) l1);
    l4 = ((vader_struct_vader_effects_SlotRoots_t*) l0)->f_root_count;
    l3 = vader_chk_mul(i64, l3, l4);
    t0 = ((vader_struct_vader_effects_Root_t*) l2)->f_param;
    l4 = ((int64_t) (size_t) t0);
    t1 = vader_chk_add(i64, l3, l4);
    l3 = (t1 << INT64_C(32));
    t2 = ((vader_struct_vader_effects_Root_t*) l2)->f_path;
    l4 = ((int64_t) (int32_t) t2);
    l3 = (l3 | l4);
    t3 = std_collections_add__i64(((vader_struct_vader_effects_SlotRoots_t*) l0)->f_seen, l3);
    if (!(t3)) {
        { vader_gc_top = gc_frame.prev; return false; }
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_effects_SlotRoots_t*) l0)->f_roots);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    t4 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l1);
    vader_array_push((vader_array_t*) t4, vader_ref_box(l2));
    { vader_gc_top = gc_frame.prev; return true; }
}

static void* vader_effects_index_functions(void* l0, void* l1) {
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
    void* l12 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    void* l15 = NULL;
    void* l16 = NULL;
    void* l29 = NULL;
    void* l30 = NULL;
    void* l35 = NULL;
    void* l36 = NULL;
    size_t l17, l18, l22, l23, l24, l25, l27, l28;
    vader_string_t l19 = 0;
    vader_string_t l20 = 0;
    vader_string_t l31 = 0;
    vader_box_t l21 = vader_box_null(), l26 = vader_box_null(), l32 = vader_box_null(), l33 = vader_box_null();
    int32_t l34;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    int64_t t2;
    vader_box_t* gc_roots[5] = { &l21, &l26, &l32, &l33, &t1 };
    void** gc_raw_roots[22] = {
        &l0, &l1, &l2, &l3, &l4, &l5, &l6, &l7, &l8, &l9, &l10, &l11, &l12, &l13, &l14, &l15, &l16,
        &l29, &l30, &l35, &l36, &t0,
    };
    vader_string_t* gc_atom_roots[3] = { &l19, &l20, &l31 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 5u, 22u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(89u, 0u, 13u, 882u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(22u, 0u, 4u, 292u);
    l3 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(16u, 0u, 7u, 285u);
    l4 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(16u, 0u, 7u, 285u);
    l5 = (void*) _a3_arr;
    vader_struct_std_collections_MutableMap__usize__i32_t* _a4_obj = (vader_struct_std_collections_MutableMap__usize__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__usize__i32_t));
    vader_obj_header_init(_a4_obj, 481u);
    _a4_obj->f_ekeys = l3;
    _a4_obj->f_evals = l4;
    _a4_obj->f_index = l5;
    _a4_obj->f_mask = (size_t) 0;
    _a4_obj->f_size = (size_t) 0;
    _a4_obj->f_tombs = (size_t) 0;
    l3 = (void*) _a4_obj;
    vader_array_t* _a5_arr = vader_array_new(22u, 0u, 4u, 292u);
    l4 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(23u, 0u, 0u, 293u);
    l5 = (void*) _a6_arr;
    vader_array_t* _a7_arr = vader_array_new(16u, 0u, 7u, 285u);
    l6 = (void*) _a7_arr;
    vader_struct_std_collections_MutableMap__usize__Any_t* _a8_obj = (vader_struct_std_collections_MutableMap__usize__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__usize__Any_t));
    vader_obj_header_init(_a8_obj, 463u);
    _a8_obj->f_ekeys = l4;
    _a8_obj->f_evals = l5;
    _a8_obj->f_index = l6;
    _a8_obj->f_mask = (size_t) 0;
    _a8_obj->f_size = (size_t) 0;
    _a8_obj->f_tombs = (size_t) 0;
    l4 = (void*) _a8_obj;
    vader_array_t* _a9_arr = vader_array_new(22u, 0u, 4u, 292u);
    l5 = (void*) _a9_arr;
    vader_array_t* _a10_arr = vader_array_new(13u, 0u, 12u, 280u);
    l6 = (void*) _a10_arr;
    vader_array_t* _a11_arr = vader_array_new(16u, 0u, 7u, 285u);
    l7 = (void*) _a11_arr;
    vader_struct_std_collections_MutableMap__usize__bool_t* _a12_obj = (vader_struct_std_collections_MutableMap__usize__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__usize__bool_t));
    vader_obj_header_init(_a12_obj, 480u);
    _a12_obj->f_ekeys = l5;
    _a12_obj->f_evals = l6;
    _a12_obj->f_index = l7;
    _a12_obj->f_mask = (size_t) 0;
    _a12_obj->f_size = (size_t) 0;
    _a12_obj->f_tombs = (size_t) 0;
    t0 = (void*) _a12_obj;
    vader_struct_std_collections_MutableSet__usize_t* _a13_obj = (vader_struct_std_collections_MutableSet__usize_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__usize_t));
    vader_obj_header_init(_a13_obj, 489u);
    _a13_obj->f_inner = t0;
    l5 = (void*) _a13_obj;
    vader_array_t* _a14_arr = vader_array_new(90u, 0u, 13u, 883u);
    l6 = (void*) _a14_arr;
    vader_array_t* _a15_arr = vader_array_new(90u, 0u, 13u, 883u);
    l7 = (void*) _a15_arr;
    vader_array_t* _a16_arr = vader_array_new(15u, 0u, 0u, 282u);
    l8 = (void*) _a16_arr;
    vader_array_t* _a17_arr = vader_array_new(23u, 0u, 0u, 293u);
    l9 = (void*) _a17_arr;
    vader_array_t* _a18_arr = vader_array_new(16u, 0u, 7u, 285u);
    l10 = (void*) _a18_arr;
    vader_struct_std_collections_MutableMap__string__Any___t* _a19_obj = (vader_struct_std_collections_MutableMap__string__Any___t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__Any___t));
    vader_obj_header_init(_a19_obj, 389u);
    _a19_obj->f_ekeys = l8;
    _a19_obj->f_evals = l9;
    _a19_obj->f_index = l10;
    _a19_obj->f_mask = (size_t) 0;
    _a19_obj->f_size = (size_t) 0;
    _a19_obj->f_tombs = (size_t) 0;
    l8 = (void*) _a19_obj;
    vader_array_t* _a20_arr = vader_array_new(21u, 0u, 4u, 291u);
    l9 = (void*) _a20_arr;
    vader_array_t* _a21_arr = vader_array_new(23u, 0u, 0u, 293u);
    l10 = (void*) _a21_arr;
    vader_array_t* _a22_arr = vader_array_new(16u, 0u, 7u, 285u);
    l11 = (void*) _a22_arr;
    vader_struct_std_collections_MutableMap__u64__Any_t* _a23_obj = (vader_struct_std_collections_MutableMap__u64__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__u64__Any_t));
    vader_obj_header_init(_a23_obj, 444u);
    _a23_obj->f_ekeys = l9;
    _a23_obj->f_evals = l10;
    _a23_obj->f_index = l11;
    _a23_obj->f_mask = (size_t) 0;
    _a23_obj->f_size = (size_t) 0;
    _a23_obj->f_tombs = (size_t) 0;
    l9 = (void*) _a23_obj;
    vader_array_t* _a24_arr = vader_array_new(22u, 0u, 4u, 292u);
    l10 = (void*) _a24_arr;
    vader_array_t* _a25_arr = vader_array_new(23u, 0u, 0u, 293u);
    l11 = (void*) _a25_arr;
    vader_array_t* _a26_arr = vader_array_new(16u, 0u, 7u, 285u);
    l12 = (void*) _a26_arr;
    vader_struct_std_collections_MutableMap__usize__Any_t* _a27_obj = (vader_struct_std_collections_MutableMap__usize__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__usize__Any_t));
    vader_obj_header_init(_a27_obj, 463u);
    _a27_obj->f_ekeys = l10;
    _a27_obj->f_evals = l11;
    _a27_obj->f_index = l12;
    _a27_obj->f_mask = (size_t) 0;
    _a27_obj->f_size = (size_t) 0;
    _a27_obj->f_tombs = (size_t) 0;
    l10 = (void*) _a27_obj;
    vader_array_t* _a28_arr = vader_array_new(166u, 0u, 13u, 1151u);
    l11 = (void*) _a28_arr;
    vader_array_t* _a29_arr = vader_array_new(15u, 0u, 0u, 282u);
    l12 = (void*) _a29_arr;
    vader_array_t* _a30_arr = vader_array_new(23u, 0u, 0u, 293u);
    l13 = (void*) _a30_arr;
    vader_array_t* _a31_arr = vader_array_new(16u, 0u, 7u, 285u);
    l14 = (void*) _a31_arr;
    vader_struct_std_collections_MutableMap__string__Any___t* _a32_obj = (vader_struct_std_collections_MutableMap__string__Any___t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__Any___t));
    vader_obj_header_init(_a32_obj, 389u);
    _a32_obj->f_ekeys = l12;
    _a32_obj->f_evals = l13;
    _a32_obj->f_index = l14;
    _a32_obj->f_mask = (size_t) 0;
    _a32_obj->f_size = (size_t) 0;
    _a32_obj->f_tombs = (size_t) 0;
    l12 = (void*) _a32_obj;
    vader_array_t* _a33_arr = vader_array_new(15u, 0u, 0u, 282u);
    l13 = (void*) _a33_arr;
    vader_array_t* _a34_arr = vader_array_new(13u, 0u, 12u, 280u);
    l14 = (void*) _a34_arr;
    vader_array_t* _a35_arr = vader_array_new(16u, 0u, 7u, 285u);
    l15 = (void*) _a35_arr;
    vader_struct_std_collections_MutableMap__string__bool_t* _a36_obj = (vader_struct_std_collections_MutableMap__string__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__bool_t));
    vader_obj_header_init(_a36_obj, 437u);
    _a36_obj->f_ekeys = l13;
    _a36_obj->f_evals = l14;
    _a36_obj->f_index = l15;
    _a36_obj->f_mask = (size_t) 0;
    _a36_obj->f_size = (size_t) 0;
    _a36_obj->f_tombs = (size_t) 0;
    t0 = (void*) _a36_obj;
    vader_struct_std_collections_MutableSet__string_t* _a37_obj = (vader_struct_std_collections_MutableSet__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__string_t));
    vader_obj_header_init(_a37_obj, 487u);
    _a37_obj->f_inner = t0;
    l13 = (void*) _a37_obj;
    vader_array_t* _a38_arr = vader_array_new(15u, 0u, 0u, 282u);
    l14 = (void*) _a38_arr;
    vader_array_t* _a39_arr = vader_array_new(13u, 0u, 12u, 280u);
    l15 = (void*) _a39_arr;
    vader_array_t* _a40_arr = vader_array_new(16u, 0u, 7u, 285u);
    l16 = (void*) _a40_arr;
    vader_struct_std_collections_MutableMap__string__bool_t* _a41_obj = (vader_struct_std_collections_MutableMap__string__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__bool_t));
    vader_obj_header_init(_a41_obj, 437u);
    _a41_obj->f_ekeys = l14;
    _a41_obj->f_evals = l15;
    _a41_obj->f_index = l16;
    _a41_obj->f_mask = (size_t) 0;
    _a41_obj->f_size = (size_t) 0;
    _a41_obj->f_tombs = (size_t) 0;
    t0 = (void*) _a41_obj;
    vader_struct_std_collections_MutableSet__string_t* _a42_obj = (vader_struct_std_collections_MutableSet__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__string_t));
    vader_obj_header_init(_a42_obj, 487u);
    _a42_obj->f_inner = t0;
    l14 = (void*) _a42_obj;
    vader_struct_vader_typecheck_ImplRegistry_t* _a43_obj = (vader_struct_vader_typecheck_ImplRegistry_t*) vader_gc_alloc(sizeof(vader_struct_vader_typecheck_ImplRegistry_t));
    vader_obj_header_init(_a43_obj, 1153u);
    _a43_obj->f_by_target = l8;
    _a43_obj->f_by_decl = l9;
    _a43_obj->f_by_member = l10;
    _a43_obj->f_all = l11;
    _a43_obj->f_by_base = l12;
    _a43_obj->f_specialized_args = l13;
    _a43_obj->f_overloaded_bases = l14;
    l8 = (void*) _a43_obj;
    l9 = vader_effects_first_paths();
    vader_array_t* _a44_arr = vader_array_new(15u, 0u, 0u, 282u);
    l10 = (void*) _a44_arr;
    vader_array_t* _a45_arr = vader_array_new(15u, 0u, 0u, 282u);
    l11 = (void*) _a45_arr;
    vader_array_t* _a46_arr = vader_array_new(16u, 0u, 7u, 285u);
    l12 = (void*) _a46_arr;
    vader_array_t* _a47_arr = vader_array_new(16u, 0u, 7u, 285u);
    l13 = (void*) _a47_arr;
    vader_struct_std_collections_MutableMap__string__i32_t* _a48_obj = (vader_struct_std_collections_MutableMap__string__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__i32_t));
    vader_obj_header_init(_a48_obj, 438u);
    _a48_obj->f_ekeys = l11;
    _a48_obj->f_evals = l12;
    _a48_obj->f_index = l13;
    _a48_obj->f_mask = (size_t) 0;
    _a48_obj->f_size = (size_t) 0;
    _a48_obj->f_tombs = (size_t) 0;
    l11 = (void*) _a48_obj;
    vader_array_t* _a49_arr = vader_array_new(17u, 0u, 8u, 286u);
    l12 = (void*) _a49_arr;
    vader_array_t* _a50_arr = vader_array_new(16u, 0u, 7u, 285u);
    l13 = (void*) _a50_arr;
    vader_array_t* _a51_arr = vader_array_new(16u, 0u, 7u, 285u);
    l14 = (void*) _a51_arr;
    vader_struct_std_collections_MutableMap__i64__i32_t* _a52_obj = (vader_struct_std_collections_MutableMap__i64__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i64__i32_t));
    vader_obj_header_init(_a52_obj, 386u);
    _a52_obj->f_ekeys = l12;
    _a52_obj->f_evals = l13;
    _a52_obj->f_index = l14;
    _a52_obj->f_mask = (size_t) 0;
    _a52_obj->f_size = (size_t) 0;
    _a52_obj->f_tombs = (size_t) 0;
    l12 = (void*) _a52_obj;
    l13 = vader_effects_first_cuts();
    vader_array_t* _a53_arr = vader_array_new(17u, 0u, 8u, 286u);
    l14 = (void*) _a53_arr;
    vader_array_t* _a54_arr = vader_array_new(16u, 0u, 7u, 285u);
    l15 = (void*) _a54_arr;
    vader_array_t* _a55_arr = vader_array_new(16u, 0u, 7u, 285u);
    l16 = (void*) _a55_arr;
    vader_struct_std_collections_MutableMap__i64__i32_t* _a56_obj = (vader_struct_std_collections_MutableMap__i64__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i64__i32_t));
    vader_obj_header_init(_a56_obj, 386u);
    _a56_obj->f_ekeys = l14;
    _a56_obj->f_evals = l15;
    _a56_obj->f_index = l16;
    _a56_obj->f_mask = (size_t) 0;
    _a56_obj->f_size = (size_t) 0;
    _a56_obj->f_tombs = (size_t) 0;
    l14 = (void*) _a56_obj;
    vader_struct_vader_effects_PathTable_t* _a57_obj = (vader_struct_vader_effects_PathTable_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_PathTable_t));
    vader_obj_header_init(_a57_obj, 888u);
    _a57_obj->f_nodes = l9;
    _a57_obj->f_step_names = l10;
    _a57_obj->f_step_ids = l11;
    _a57_obj->f_children = l12;
    _a57_obj->f_cuts = l13;
    _a57_obj->f_joins = l14;
    l9 = (void*) _a57_obj;
    vader_array_t* _a58_arr = vader_array_new(15u, 0u, 0u, 282u);
    l10 = (void*) _a58_arr;
    vader_array_t* _a59_arr = vader_array_new(23u, 0u, 0u, 293u);
    l11 = (void*) _a59_arr;
    vader_array_t* _a60_arr = vader_array_new(16u, 0u, 7u, 285u);
    l12 = (void*) _a60_arr;
    vader_struct_std_collections_MutableMap__string__Any___t* _a61_obj = (vader_struct_std_collections_MutableMap__string__Any___t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__Any___t));
    vader_obj_header_init(_a61_obj, 389u);
    _a61_obj->f_ekeys = l10;
    _a61_obj->f_evals = l11;
    _a61_obj->f_index = l12;
    _a61_obj->f_mask = (size_t) 0;
    _a61_obj->f_size = (size_t) 0;
    _a61_obj->f_tombs = (size_t) 0;
    l10 = (void*) _a61_obj;
    vader_array_t* _a62_arr = vader_array_new(15u, 0u, 0u, 282u);
    l11 = (void*) _a62_arr;
    vader_struct_vader_effects_CalleeIndex_t* _a63_obj = (vader_struct_vader_effects_CalleeIndex_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_CalleeIndex_t));
    vader_obj_header_init(_a63_obj, 871u);
    _a63_obj->f_functions = l2;
    _a63_obj->f_nodes = l3;
    _a63_obj->f_bodyless = l4;
    _a63_obj->f_frozen_views = l5;
    _a63_obj->f_constants = l6;
    _a63_obj->f_defaults = l7;
    _a63_obj->f_impls = l8;
    _a63_obj->f_paths = l9;
    _a63_obj->f_project = l0;
    _a63_obj->f_members = l10;
    _a63_obj->f_unknown = l11;
    l2 = (void*) _a63_obj;
    l3 = ((vader_struct_vader_resolver_LoadedProject_t*) l0)->f_modules;
    l4 = ((vader_struct_std_collections_MutableMap__string__LoadedModule_t*) l3)->f_ekeys;
    l5 = ((vader_struct_std_collections_MutableMap__string__LoadedModule_t*) l3)->f_evals;
    l17 = ((vader_struct_std_collections_MutableMap__string__LoadedModule_t*) l3)->f_size;
    l18 = (size_t) 0;
    while (!((l18 >= l17))) {
        vader_array_t* _a64_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a64_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a64_slotarr, l18)
        t1 = vader_array_box_slots(_a64_slotarr->buf)[_a64_slotarr->offset + (size_t) l18];
        l19 = t1.payload.s;
        vader_array_t* _a65_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a65_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a65_slotarr, l18)
        l3 = vader_array_ref_load_obj(_a65_slotarr->buf, _a65_slotarr->offset + (size_t) l18);
        l20 = l19;
        l6 = l3;
        t2 = (l18 + INT64_C(1));
        l18 = (size_t) (int64_t) t2;
        l21 = std_collections_MutableMap_Index_at__string__Any(l1, l20);
        if (l21.tag == 0u) {
            continue;
        }
        l7 = l21.payload.obj;
        l8 = ((vader_struct_vader_resolver_Module_t*) ((vader_struct_vader_resolver_LoadedModule_t*) l6)->f_module)->f_files;
        l22 = ((vader_array_t*) l8)->length;
        l23 = (size_t) 0;
        while ((l23 < l22)) {
            vader_array_t* _a66_slotarr = ((vader_array_t*) l8);
            VADER_ARRAY_RESOLVE_BUF(_a66_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a66_slotarr, l23)
            l9 = vader_array_ref_load_obj(_a66_slotarr->buf, _a66_slotarr->offset + (size_t) l23);
            l10 = ((vader_struct_vader_effects_CalleeIndex_t*) l2)->f_impls;
            l11 = ((vader_struct_toolchain_ast_Program_t*) ((vader_struct_vader_resolver_SourceFile_t*) l9)->f_program)->f_decls;
            l12 = ((vader_struct_vader_typecheck_TypedProgram_t*) l7)->f_resolved;
            vader_typecheck_collect_impls(l10, l11, l12);
            l13 = ((vader_struct_toolchain_ast_Program_t*) ((vader_struct_vader_resolver_SourceFile_t*) l9)->f_program)->f_decls;
            l24 = ((vader_array_t*) l13)->length;
            l25 = (size_t) 0;
            while ((l25 < l24)) {
                vader_array_t* _a67_slotarr = ((vader_array_t*) l13);
                VADER_ARRAY_RESOLVE_BUF(_a67_slotarr)
                l26 = vader_array_ref_load_box(_a67_slotarr->buf, _a67_slotarr->offset + (size_t) l25);
                if (l26.tag == 529u) {
                    l14 = l26.payload.obj;
                    vader_effects_register(l2, l14, l7);
                } else if (l26.tag == 538u) {
                    t0 = l26.payload.obj;
                    l15 = ((vader_struct_toolchain_ast_ImplDecl_t*) t0)->f_members;
                    l27 = ((vader_array_t*) l15)->length;
                    l28 = (size_t) 0;
                    while ((l28 < l27)) {
                        vader_array_t* _a68_slotarr = ((vader_array_t*) l15);
                        VADER_ARRAY_RESOLVE_BUF(_a68_slotarr)
                        l16 = vader_array_ref_load_obj(_a68_slotarr->buf, _a68_slotarr->offset + (size_t) l28);
                        vader_effects_register(l2, l16, l7);
                        t2 = (l28 + INT64_C(1));
                        l28 = (size_t) (int64_t) t2;
                    }
                } else if (l26.tag == 512u) {
                    l30 = ((vader_struct_vader_resolver_CollectedModule_t*) ((vader_struct_vader_resolver_LoadedModule_t*) l6)->f_collected)->f_symbols;
                    t0 = l26.payload.obj;
                    l31 = ((vader_struct_toolchain_ast_ConstDecl_t*) t0)->f_name;
                    l32 = std_collections_MutableMap_Index_at__string__Any(l30, l31);
                    if (l32.tag == 0u) {
                        t2 = (l25 + INT64_C(1));
                        l25 = (size_t) (int64_t) t2;
                        continue;
                    }
                    l29 = l32.payload.obj;
                    t0 = l26.payload.obj;
                    l33 = ((vader_struct_toolchain_ast_ConstDecl_t*) t0)->f_value;
                    l34 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l29)->f_id;
                    t1 = vader_box_i32(285u, l34);
                    vader_struct_vader_effects_Initialiser_t* _a69_obj = (vader_struct_vader_effects_Initialiser_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_Initialiser_t));
                    vader_obj_header_init(_a69_obj, 883u);
                    _a69_obj->f_value = l33;
                    _a69_obj->f_typed = l7;
                    _a69_obj->f_initialises = t1;
                    l35 = (void*) _a69_obj;
                    vader_array_push((vader_array_t*) ((vader_struct_vader_effects_CalleeIndex_t*) l2)->f_constants, vader_ref_box(l35));
                } else if (l26.tag == 573u) {
                    l36 = l26.payload.obj;
                    vader_effects_register_defaults(l2, l36, l7);
                }
                t2 = (l25 + INT64_C(1));
                l25 = (size_t) (int64_t) t2;
            }
            t2 = (l23 + INT64_C(1));
            l23 = (size_t) (int64_t) t2;
        }
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_effects_index_value(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l3 = vader_box_null(), l5 = vader_box_null(), l7 = vader_box_null();
    size_t l4;
    void* l6 = NULL;
    void* l8 = NULL;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[5] = { &l2, &l3, &l5, &l7, &t0 };
    void** gc_raw_roots[4] = { &l0, &l1, &l6, &l8 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 5u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_toolchain_ast_IndexExpr_t*) l1)->f_target;
    l2 = vader_effects_value(l0, l2);
    l3 = ((vader_struct_toolchain_ast_IndexExpr_t*) l1)->f_index;
    l3 = vader_effects_value(l0, l3);
    l4 = ((vader_struct_toolchain_ast_IndexExpr_t*) l1)->f_id;
    l5 = vader_effects_site_callee(l0, (uint8_t) 2, l4);
    if (!(l5.tag == 0u)) {
        if (!(l5.tag == 1130u)) {
            vader_array_t* _a0_arr = vader_array_new(206u, 2u, 0u, 1286u);
            vader_array_box_slots(_a0_arr->buf)[_a0_arr->offset + 1u] = l3;
            vader_array_box_slots(_a0_arr->buf)[_a0_arr->offset + 0u] = l2;
            l6 = (void*) _a0_arr;
            l3 = ((vader_struct_toolchain_ast_IndexExpr_t*) l1)->f_target;
            l7 = ((vader_struct_toolchain_ast_IndexExpr_t*) l1)->f_index;
            vader_array_t* _a1_arr = vader_array_new(209u, 2u, 13u, 1373u);
            ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 1u] = l7.payload.obj;
            ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = l3.payload.obj;
            l8 = (void*) _a1_arr;
            t0 = vader_effects_call(l0, l5, l6, l8);
            { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    if (!(((vader_struct_toolchain_ast_IndexExpr_t*) l1)->f_index.tag == 563u)) {
        t0 = vader_effects_step_slot(l0, l2, 832u);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_effects_initialiser_ctx(void* l0, void* l1, void* l2, void* l3) {
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[10] = { &l0, &l1, &l2, &l3, &l4, &l5, &l6, &l7, &l8, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 10u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l4 = vader_effects_new_skeleton((size_t) 0);
    l5 = ((vader_struct_vader_effects_Initialiser_t*) l3)->f_typed;
    vader_array_t* _a0_arr = vader_array_new(16u, 0u, 7u, 285u);
    l6 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(22u, 0u, 4u, 292u);
    l7 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(16u, 0u, 7u, 285u);
    l8 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__i32__usize_t* _a3_obj = (vader_struct_std_collections_MutableMap__i32__usize_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__usize_t));
    vader_obj_header_init(_a3_obj, 384u);
    _a3_obj->f_ekeys = l6;
    _a3_obj->f_evals = l7;
    _a3_obj->f_index = l8;
    _a3_obj->f_mask = (size_t) 0;
    _a3_obj->f_size = (size_t) 0;
    _a3_obj->f_tombs = (size_t) 0;
    l6 = (void*) _a3_obj;
    vader_array_t* _a4_arr = vader_array_new(87u, 0u, 13u, 879u);
    l7 = (void*) _a4_arr;
    vader_struct_vader_effects_WalkCtx_t* _a5_obj = (vader_struct_vader_effects_WalkCtx_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_WalkCtx_t));
    vader_obj_header_init(_a5_obj, 896u);
    _a5_obj->f_s = l4;
    _a5_obj->f_typed = l5;
    _a5_obj->f_index = l0;
    _a5_obj->f_slots = l6;
    _a5_obj->f_lambda_depth = INT32_C(0);
    _a5_obj->f_frozen = l1;
    _a5_obj->f_widenings = l2;
    _a5_obj->f_roots = l7;
    t0 = (void*) _a5_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_effects_insert(void* l0, void* l1) {
    void* l2 = NULL;
    int64_t l3;
    bool t0;
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_effects_ParamEffects_t*) l0)->f_keys;
    l3 = vader_effects_access_key(l1);
    t0 = std_collections_add__i64(l2, l3);
    if (t0) {
        vader_array_push((vader_array_t*) ((vader_struct_vader_effects_ParamEffects_t*) l0)->f_accesses, vader_ref_box(l1));
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_effects_intrinsic_effects(void* l0, vader_string_t l1) {
    int32_t l2;
    vader_string_t l3 = 0;
    vader_string_t l4 = 0;
    vader_string_t l5 = 0;
    void* l6 = NULL;
    void* l7 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[4] = { &l0, &l6, &l7, &t0 };
    vader_string_t* gc_atom_roots[4] = { &l1, &l3, &l4, &l5 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_effects_path_to(l0, 832u);
    l3 = vader_types_core_trait_key(456u);
    l4 = vader_types_core_trait_key(470u);
    l5 = concat_2(l3, 338u);
    if (l1 == l5) {
        t0 = vader_effects_none();
        vader_array_t* _a0_arr = vader_array_new(92u, 1u, 13u, 886u);
        ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = t0;
        t0 = (void*) _a0_arr;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l5 = concat_2(l3, 345u);
    if (l1 == l5) {
        t0 = vader_effects_push_effects(INT32_C(0));
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l5 = concat_2(l3, 346u);
    if (l1 == l5) {
        t0 = vader_effects_push_effects(l2);
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l5 = concat_2(l3, 332u);
    if (l1 == l5) {
        t0 = vader_effects_copy_to_effects(l2);
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l5 = concat_2(l3, 347u);
    if (l1 == l5) {
        t0 = vader_effects_remove_last_effects(l2);
        vader_array_t* _a1_arr = vader_array_new(92u, 1u, 13u, 886u);
        ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = t0;
        t0 = (void*) _a1_arr;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = concat_2(l3, 331u);
    if (l1 == l3) {
        t0 = vader_effects_effects_of((uint8_t) 2, INT32_C(0));
        vader_array_t* _a2_arr = vader_array_new(92u, 1u, 13u, 886u);
        ((void**) _a2_arr->buf->slots)[_a2_arr->offset + 0u] = t0;
        t0 = (void*) _a2_arr;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = concat_2(l4, 339u);
    if (l1 == l3) {
        l6 = vader_effects_none();
        l7 = vader_effects_none();
        vader_array_t* _a3_arr = vader_array_new(92u, 2u, 13u, 886u);
        ((void**) _a3_arr->buf->slots)[_a3_arr->offset + 1u] = l7;
        ((void**) _a3_arr->buf->slots)[_a3_arr->offset + 0u] = l6;
        t0 = (void*) _a3_arr;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = concat_2(l4, 353u);
    if (l1 == l3) {
        t0 = vader_effects_writes_bytes(l2);
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = concat_2(l4, 340u);
    if (l1 == l3) {
        t0 = vader_effects_memory_copy_effects(l2);
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = concat_2(l4, 336u);
    if (l1 == l3) {
        l6 = vader_effects_none();
        l7 = vader_effects_none();
        vader_array_t* _a4_arr = vader_array_new(92u, 2u, 13u, 886u);
        ((void**) _a4_arr->buf->slots)[_a4_arr->offset + 1u] = l7;
        ((void**) _a4_arr->buf->slots)[_a4_arr->offset + 0u] = l6;
        t0 = (void*) _a4_arr;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = concat_2(l4, 356u);
    if (l1 == l3) {
        t0 = vader_effects_writes_bytes(l2);
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == 2311u) {
        t0 = vader_effects_none();
        vader_array_t* _a5_arr = vader_array_new(92u, 1u, 13u, 886u);
        ((void**) _a5_arr->buf->slots)[_a5_arr->offset + 0u] = t0;
        t0 = (void*) _a5_arr;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l1 == 2573u)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    t0 = vader_effects_ffi_call_effects(l2);
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_effects_intrinsic_key(void* l0, void* l1, void* l2) {
    vader_box_t l3 = vader_box_null();
    vader_string_t l4 = 0;
    vader_string_t l5 = 0;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    vader_box_t* gc_roots[1] = { &l3 };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t0 };
    vader_string_t* gc_atom_roots[3] = { &l4, &l5, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = vader_typecheck_member_entry(((vader_struct_vader_effects_CalleeIndex_t*) l0)->f_impls, l1);
    if (!(l3.tag == 0u)) {
        t0 = l3.payload.obj;
        l4 = ((vader_struct_vader_typecheck_ImplEntry_t*) t0)->f_trait_key;
        l5 = ((vader_struct_toolchain_ast_FnDecl_t*) l1)->f_name;
        t1 = concat_3(l4, 319u, l5);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = ((vader_struct_vader_resolver_ResolvedModule_t*) ((vader_struct_vader_typecheck_TypedProgram_t*) l2)->f_resolved)->f_display_path;
    l5 = ((vader_struct_toolchain_ast_FnDecl_t*) l1)->f_name;
    t1 = concat_3(l4, 319u, l5);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

bool vader_effects_is_kept(void* l0) {
    uint8_t l1;
    bool l2;
    l1 = ((vader_struct_vader_effects_Access_t*) l0)->f_effect;
    if (l1 == INT32_C(3)) {
        l2 = true;
    } else {
        l2 = l1 == INT32_C(4);
    }
    if (l2) {
        return true;
    }
    if (l1 == INT32_C(0)) {
        l2 = true;
    } else {
        l2 = l1 == INT32_C(1);
    }
    if (l2) {
        l2 = true;
    } else {
        l2 = l1 == INT32_C(2);
    }
    if (l2) {
        l2 = true;
    } else {
        l2 = l1 == INT32_C(5);
    }
    if (!(l2)) {
        vader_unreachable("non-exhaustive match (T3013 should have caught this)");
    }
    return false;
}

bool vader_effects_is_unknown(void* l0) {
    return ((vader_struct_vader_effects_Access_t*) l0)->f_effect == INT32_C(5);
}

static int32_t vader_effects_joined(void* l0, int32_t l1, int32_t l2) {
    int64_t l3;
    vader_box_t l4 = vader_box_null();
    int32_t l5, l9;
    void* l6 = NULL;
    size_t l7, l8;
    void* t0 = NULL;
    bool t1;
    int32_t t2;
    int64_t t3;
    vader_box_t* gc_roots[1] = { &l4 };
    void** gc_raw_roots[3] = { &l0, &l6, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l2 == INT32_C(0)) {
        { int32_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_effects_PathTable_t*) l0)->f_nodes);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l1);
    t1 = ((vader_struct_vader_effects_PathNode_t*) t0)->f_deeper;
    if (t1) {
        { int32_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = vader_effects_pair_key(l1, l2);
    l4 = std_collections_MutableMap_Index_at__i64__i32(((vader_struct_vader_effects_PathTable_t*) l0)->f_joins, l3);
    if (!(l4.tag == 0u)) {
        t2 = ((int32_t) l4.payload.i);
        { int32_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l5 = l1;
    l6 = vader_effects_steps_of(l0, l2);
    l7 = ((vader_array_t*) l6)->length;
    l8 = (size_t) 0;
    while ((l8 < l7)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l9 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l8];
        l5 = vader_effects_child(l0, l5, l9);
        t3 = (l8 + INT64_C(1));
        l8 = (size_t) (int64_t) t3;
    }
    vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_effects_PathTable_t*) l0)->f_nodes);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l2)
    t0 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l2);
    t1 = ((vader_struct_vader_effects_PathNode_t*) t0)->f_deeper;
    if (t1) {
        l5 = vader_effects_cut(l0, l5);
        std_collections_MutableMap_IndexSet_set_at__i64__i32(((vader_struct_vader_effects_PathTable_t*) l0)->f_joins, l3, l5);
        { int32_t __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
    }
    std_collections_MutableMap_IndexSet_set_at__i64__i32(((vader_struct_vader_effects_PathTable_t*) l0)->f_joins, l3, l5);
    { int32_t __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_effects_known_params(vader_box_t l0, void* l1) {
    vader_box_t l2;
    int32_t l3;
    void* t0;
    void* t1;
    if (l0.tag == 872u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_effects_CalleeNode_t*) t0)->f_node;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
        l2 = vader_ref_box(t0);
        return l2;
    }
    if (l0.tag == 884u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_effects_KnownEffects_t*) t0)->f_params;
        l2 = vader_ref_box(t1);
    } else {
        if (!(l0.tag == 870u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l2 = vader_box_obj(0u, NULL);
    }
    return l2;
}

static vader_box_t vader_effects_lambda_value(void* l0, void* l1) {
    int32_t l2;
    void* l3 = NULL;
    vader_box_t l4 = vader_box_null();
    int32_t t0;
    vader_box_t* gc_roots[1] = { &l4 };
    void** gc_raw_roots[3] = { &l0, &l1, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_effects_WalkCtx_t*) l0)->f_lambda_depth;
    l2 = vader_chk_add(i32, t0, INT32_C(1));
    ((vader_struct_vader_effects_WalkCtx_t*) l0)->f_lambda_depth = l2;
    l3 = ((vader_struct_toolchain_ast_LambdaExpr_t*) l1)->f_body;
    l4 = vader_effects_block_value(l0, l3);
    vader_effects_escape(l0, l4, (uint8_t) 3);
    t0 = ((vader_struct_vader_effects_WalkCtx_t*) l0)->f_lambda_depth;
    l2 = vader_chk_sub(i32, t0, INT32_C(1));
    ((vader_struct_vader_effects_WalkCtx_t*) l0)->f_lambda_depth = l2;
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static size_t vader_effects_local_slot(void* l0, int32_t l1) {
    vader_box_t l2 = vader_box_null();
    size_t l3;
    size_t t0;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = std_collections_MutableMap_Index_at__i32__usize(((vader_struct_vader_effects_WalkCtx_t*) l0)->f_slots, l1);
    if (!(l2.tag == 0u)) {
        t0 = ((size_t) l2.payload.i);
        { size_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = vader_effects_fresh_slot(((vader_struct_vader_effects_WalkCtx_t*) l0)->f_s);
    std_collections_MutableMap_IndexSet_set_at__i32__usize(((vader_struct_vader_effects_WalkCtx_t*) l0)->f_slots, l1, l3);
    { size_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_effects_loop_element(void* l0, vader_box_t l1, vader_box_t l2) {
    size_t l3;
    vader_box_t l4 = vader_box_null(), l5 = vader_box_null();
    void* l6 = NULL;
    void* l7 = NULL;
    bool t0;
    void* t1 = NULL;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[5] = { &l1, &l2, &l4, &l5, &t2 };
    void** gc_raw_roots[4] = { &l0, &l6, &l7, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 5u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_effects_steps_through_elements(l0, l1);
    if (!(t0)) {
        t1 = l1.payload.obj;
        l3 = ((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t1)->f_id;
        l4 = vader_effects_site_callee(l0, (uint8_t) 5, l3);
        l4 = vader_effects_converted_by(l0, l4, l2, l1);
        t1 = l1.payload.obj;
        l3 = ((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t1)->f_id;
        l5 = vader_effects_site_callee(l0, (uint8_t) 6, l3);
        vader_array_t* _a0_arr = vader_array_new(206u, 1u, 0u, 1286u);
        vader_array_box_slots(_a0_arr->buf)[_a0_arr->offset + 0u] = l4;
        l6 = (void*) _a0_arr;
        vader_array_t* _a1_arr = vader_array_new(209u, 0u, 13u, 1373u);
        l7 = (void*) _a1_arr;
        t2 = vader_effects_call(l0, l5, l6, l7);
        { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = vader_effects_step_slot(l0, l2, 832u);
    { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_effects_makes_frozen_view(vader_string_t l0) {
    return l0 == 2310u;
}

static void vader_effects_mark(void* l0, vader_box_t l1, int32_t l2, uint8_t l3) {
    void* l4 = NULL;
    size_t l5;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[2] = { &l0, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l1.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l4 = ((vader_struct_vader_effects_WalkCtx_t*) l0)->f_s;
    l5 = ((size_t) l1.payload.i);
    vader_effects_add_mark(l4, l5, l2, l3);
    { vader_gc_top = gc_frame.prev; return; }
}

static bool vader_effects_mark_fresh(void* l0, void* l1) {
    void* l2 = NULL;
    size_t l3;
    int32_t l4;
    bool t0;
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_typecheck_FreshReads_t*) ((vader_struct_vader_effects_FrozenSites_t*) l0)->f_fresh)->f_uses;
    l3 = ((vader_struct_vader_effects_ConstantUse_t*) l1)->f_node;
    std_collections_add__usize(l2, l3);
    l2 = ((vader_struct_vader_typecheck_FreshReads_t*) ((vader_struct_vader_effects_FrozenSites_t*) l0)->f_fresh)->f_constants;
    l4 = ((vader_struct_vader_effects_ConstantUse_t*) l1)->f_symbol;
    t0 = std_collections_add__i32(l2, l4);
    { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_effects_mark_roots(void* l0, void* l1, int32_t l2, uint8_t l3, void* l4, bool l5) {
    void* l6 = NULL;
    void* l9 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    size_t l7, l8, l12;
    int32_t l10, l11;
    int64_t t0;
    void** gc_raw_roots[7] = { &l0, &l1, &l4, &l6, &l9, &l13, &l14 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 7u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l6 = l1;
    l7 = ((vader_array_t*) l6)->length;
    l8 = (size_t) 0;
    while ((l8 < l7)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l9 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l8);
        l10 = ((vader_struct_vader_effects_Root_t*) l9)->f_path;
        l11 = vader_effects_composed(l4, l10, l2, l5);
        l12 = ((vader_struct_vader_effects_Root_t*) l9)->f_param;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l12)
        l13 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l12);
        vader_struct_vader_effects_Access_t* _a2_obj = (vader_struct_vader_effects_Access_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_Access_t));
        vader_obj_header_init(_a2_obj, 869u);
        _a2_obj->f_path = l11;
        _a2_obj->f_effect = l3;
        l14 = (void*) _a2_obj;
        vader_effects_include(l4, l13, l14);
        t0 = (l8 + INT64_C(1));
        l8 = (size_t) (int64_t) t0;
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_effects_match_value(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l3 = vader_box_null(), l9 = vader_box_null(), l10 = vader_box_null(), l11 = vader_box_null(), l12 = vader_box_null();
    void* l4 = NULL;
    void* l6 = NULL;
    void* l8 = NULL;
    size_t l5, l7;
    void* t0 = NULL;
    int64_t t1;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[7] = { &l2, &l3, &l9, &l10, &l11, &l12, &t2 };
    void** gc_raw_roots[6] = { &l0, &l1, &l4, &l6, &l8, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 7u, 6u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_toolchain_ast_MatchExpr_t*) l1)->f_scrutinee;
    l2 = vader_effects_value(l0, l2);
    l3 = ((vader_struct_toolchain_ast_MatchExpr_t*) l1)->f_bind_as;
    if (!(l3.tag == 0u)) {
        t0 = l3.payload.obj;
        l4 = ((vader_struct_toolchain_ast_AsBinding_t*) t0)->f_span;
        vader_effects_bind_symbol(l0, l4, l2);
    }
    vader_array_t* _a0_arr = vader_array_new(206u, 0u, 0u, 1286u);
    l4 = (void*) _a0_arr;
    l5 = ((vader_array_t*) ((vader_struct_toolchain_ast_MatchExpr_t*) l1)->f_arms)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l4, (size_t) l5);
    l4 = (void*) _a1_arr;
    l6 = ((vader_struct_toolchain_ast_MatchExpr_t*) l1)->f_arms;
    l5 = ((vader_array_t*) l6)->length;
    l7 = (size_t) 0;
    while ((l7 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        l8 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l7);
        l3 = ((vader_struct_toolchain_ast_MatchArm_t*) l8)->f_pattern;
        vader_effects_bind_pattern(l0, l3, l2);
        l9 = ((vader_struct_toolchain_ast_MatchArm_t*) l8)->f_guard;
        if (!(l9.tag == 0u)) {
            l10 = l9;
            vader_effects_discard(l0, l10);
        }
        l11 = ((vader_struct_toolchain_ast_MatchArm_t*) l8)->f_body;
        l12 = vader_effects_value(l0, l11);
        vader_array_push((vader_array_t*) l4, l12);
        t1 = (l7 + INT64_C(1));
        l7 = (size_t) (int64_t) t1;
    }
    t2 = vader_effects_union_of(l0, l4);
    { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

bool vader_effects_may_be_written(void* l0, vader_box_t l1, void* l2, void* l3) {
    void* l4 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    bool l5, l9;
    vader_string_t l6 = 0;
    size_t l10, l11;
    bool t0;
    void* t1 = NULL;
    vader_box_t t2 = vader_box_null(), t3 = vader_box_null();
    int64_t t4;
    vader_box_t* gc_roots[3] = { &l1, &t2, &t3 };
    void** gc_raw_roots[7] = { &l0, &l2, &l3, &l4, &l7, &l8, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l6 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = std_collections_MutableSet_Contains_contains__string(l0, 1330u);
    if (t0) {
        { vader_gc_top = gc_frame.prev; return true; }
    }
    vader_struct___lambda_env_vader_effects_21_t* _a0_obj = (vader_struct___lambda_env_vader_effects_21_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_effects_21_t));
    vader_obj_header_init(_a0_obj, 308u);
    _a0_obj->f_cap_0 = l0;
    _a0_obj->f_cap_1 = l2;
    _a0_obj->f_cap_2 = l3;
    t1 = (void*) _a0_obj;
    vader_fn_t* _a1_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
    vader_obj_header_init(_a1_closure, 276u);
    _a1_closure->code = (void*) &vader_fn_lift___lambda_vader_effects_20;
    _a1_closure->env = t1;
    l4 = (void*) _a1_closure;
    if (l1.tag == 1199u) {
        t1 = l1.payload.obj;
        l6 = vader_effects_struct_key(t1);
        t0 = std_collections_MutableSet_Contains_contains__string(l0, l6);
        if (t0) {
            l5 = true;
        } else {
            l7 = l1.payload.obj;
            l5 = vader_effects_fields_may_be_written(l0, l7, l2, l3);
        }
        { bool __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 1188u) {
        t0 = std_collections_MutableSet_Contains_contains__string(l0, 1340u);
        if (t0) {
            l5 = true;
        } else {
            t1 = l1.payload.obj;
            vader_fn_t* _a2_fnobj = (vader_fn_t*) l4;
            t2 = ((vader_fn_erased_sig_1_t) _a2_fnobj->code)(_a2_fnobj->env, ((vader_struct_vader_types_ArrayType_t*) t1)->f_element);
            l5 = t2.payload.b;
        }
    } else if (l1.tag == 1201u) {
        t0 = std_collections_MutableSet_Contains_contains__string(l0, 2465u);
        if (t0) {
            l5 = true;
        } else {
            t1 = l1.payload.obj;
            l7 = ((vader_struct_vader_types_TupleType_t*) t1)->f_elements;
            l8 = l4;
            l9 = false;
            l10 = ((vader_array_t*) l7)->length;
            l11 = (size_t) 0;
            {
                while ((l11 < l10)) {
                    vader_array_t* _a3_slotarr = ((vader_array_t*) l7);
                    VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l11)
                    t2 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l11);
                    vader_fn_t* _a4_fnobj = (vader_fn_t*) l8;
                    t3 = ((vader_fn_erased_sig_1_t) _a4_fnobj->code)(_a4_fnobj->env, t2);
                    t0 = t3.payload.b;
                    if (t0) {
                        l9 = true;
                        goto end_80;
                    }
                    t4 = (l11 + INT64_C(1));
                    l11 = (size_t) (int64_t) t4;
                }
                l9 = false;
            } end_80: ;
            l5 = l9;
        }
    } else if (l1.tag == 1204u) {
        t1 = l1.payload.obj;
        l7 = ((vader_struct_vader_types_UnionType_t*) t1)->f_variants;
        l8 = l4;
        l9 = false;
        l10 = ((vader_array_t*) l7)->length;
        l11 = (size_t) 0;
        {
            while ((l11 < l10)) {
                vader_array_t* _a5_slotarr = ((vader_array_t*) l7);
                VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l11)
                t2 = vader_array_ref_load_box(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l11);
                vader_fn_t* _a6_fnobj = (vader_fn_t*) l8;
                t3 = ((vader_fn_erased_sig_1_t) _a6_fnobj->code)(_a6_fnobj->env, t2);
                t0 = t3.payload.b;
                if (t0) {
                    l9 = true;
                    goto end_126;
                }
                t4 = (l11 + INT64_C(1));
                l11 = (size_t) (int64_t) t4;
            }
            l9 = false;
        } end_126: ;
        l5 = l9;
    } else if (l1.tag == 1189u) {
        t1 = l1.payload.obj;
        vader_fn_t* _a7_fnobj = (vader_fn_t*) l4;
        t2 = ((vader_fn_erased_sig_1_t) _a7_fnobj->code)(_a7_fnobj->env, ((vader_struct_vader_types_DistinctType_t*) t1)->f_backing);
        l5 = t2.payload.b;
    } else if ((l1.tag == 1187u || l1.tag == 0u || l1.tag == 1198u || l1.tag == 1200u || l1.tag == 1203u || l1.tag == 1205u)) {
        l5 = true;
    } else {
        if (!((l1.tag == 1190u || l1.tag == 1191u || l1.tag == 1192u || l1.tag == 1193u || l1.tag == 1194u || l1.tag == 1195u || l1.tag == 1197u || l1.tag == 1202u))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l5 = false;
    }
    { bool __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_effects_member_targets(void* l0, vader_string_t l1, vader_string_t l2) {
    vader_string_t l3 = 0;
    vader_box_t l4 = vader_box_null(), l12 = vader_box_null(), l18 = vader_box_null();
    void* l5 = NULL;
    void* l6 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    void* l15 = NULL;
    void* l16 = NULL;
    void* l17 = NULL;
    size_t l7, l8, l13, l14;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    int64_t t2;
    bool t3;
    vader_box_t* gc_roots[3] = { &l4, &l12, &l18 };
    void** gc_raw_roots[10] = { &l0, &l5, &l6, &l9, &l10, &l11, &l15, &l16, &l17, &t0 };
    vader_string_t* gc_atom_roots[4] = { &l1, &l2, &l3, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 10u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = concat_3(l1, 319u, l2);
    l4 = std_collections_MutableMap_Index_at__string__Any(((vader_struct_vader_effects_CalleeIndex_t*) l0)->f_members, l3);
    if (!(l4.tag == 0u)) {
        t0 = l4.payload.obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a0_arr = vader_array_new(231u, 0u, 13u, 1559u);
    l5 = (void*) _a0_arr;
    l6 = ((vader_struct_vader_typecheck_ImplRegistry_t*) ((vader_struct_vader_effects_CalleeIndex_t*) l0)->f_impls)->f_all;
    l7 = ((vader_array_t*) l6)->length;
    l8 = (size_t) 0;
    while ((l8 < l7)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l9 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l8);
        t1 = ((vader_struct_vader_typecheck_ImplEntry_t*) l9)->f_trait_key;
        if (t1 != l1) {
            t2 = (l8 + INT64_C(1));
            l8 = (size_t) (int64_t) t2;
            continue;
        }
        l10 = ((vader_struct_toolchain_ast_ImplDecl_t*) ((vader_struct_vader_typecheck_ImplEntry_t*) l9)->f_decl)->f_members;
        vader_struct___lambda_env_vader_effects_25_t* _a2_obj = (vader_struct___lambda_env_vader_effects_25_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_effects_25_t));
        vader_obj_header_init(_a2_obj, 310u);
        _a2_obj->f_cap_0 = l2;
        l11 = (void*) _a2_obj;
        l12 = vader_box_obj(0u, NULL);
        l13 = ((vader_array_t*) l10)->length;
        l14 = (size_t) 0;
        {
            while ((l14 < l13)) {
                vader_array_t* _a3_slotarr = ((vader_array_t*) l10);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                l15 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l14);
                t3 = __lambda_vader_effects_24(l11, l15);
                if (t3) {
                    l12 = vader_ref_box(l15);
                    goto end_58;
                }
                t2 = (l14 + INT64_C(1));
                l14 = (size_t) (int64_t) t2;
            }
            l12 = vader_box_obj(0u, NULL);
        } end_58: ;
        l4 = l12;
        if (l4.tag == 0u) {
            vader_struct_vader_effects_AnyCallee_t* _a4_obj = (vader_struct_vader_effects_AnyCallee_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_AnyCallee_t));
            vader_obj_header_init(_a4_obj, 870u);
            l16 = (void*) _a4_obj;
            vader_array_push((vader_array_t*) l5, vader_ref_box(l16));
        } else {
            l17 = l4.payload.obj;
            l18 = vader_effects_target_of_decl(l0, l17);
            vader_array_push((vader_array_t*) l5, l18);
        }
        t2 = (l8 + INT64_C(1));
        l8 = (size_t) (int64_t) t2;
    }
    std_collections_MutableMap_IndexSet_set_at__string__Any(((vader_struct_vader_effects_CalleeIndex_t*) l0)->f_members, l3, vader_ref_box(l5));
    { void* __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_effects_memory_copy_effects(int32_t l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[6] = { &l1, &l2, &l3, &l4, &l5, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 6u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_effects_effects_of((uint8_t) 0, l0);
    l2 = vader_effects_none();
    l3 = vader_effects_none();
    l4 = vader_effects_none();
    l5 = vader_effects_none();
    vader_array_t* _a0_arr = vader_array_new(92u, 5u, 13u, 886u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 4u] = l5;
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 3u] = l4;
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 2u] = l3;
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 1u] = l2;
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = l1;
    t0 = (void*) _a0_arr;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

bool vader_effects_modifies(void* l0) {
    uint8_t l1;
    bool l2;
    l1 = ((vader_struct_vader_effects_Access_t*) l0)->f_effect;
    if (l1 == INT32_C(0)) {
        l2 = true;
    } else {
        l2 = l1 == INT32_C(1);
    }
    if (l2) {
        l2 = true;
    } else {
        l2 = l1 == INT32_C(2);
    }
    if (l2) {
        return true;
    }
    if (l1 == INT32_C(3)) {
        l2 = true;
    } else {
        l2 = l1 == INT32_C(4);
    }
    if (l2) {
        l2 = true;
    } else {
        l2 = l1 == INT32_C(5);
    }
    if (!(l2)) {
        vader_unreachable("non-exhaustive match (T3013 should have caught this)");
    }
    return false;
}

static vader_box_t vader_effects_namespace_member(void* l0, void* l1) {
    vader_string_t l2;
    vader_box_t l3;
    void* l4;
    vader_box_t t0;
    l3 = ((vader_struct_toolchain_ast_FieldExpr_t*) l1)->f_target;
    l4 = ((vader_struct_vader_effects_WalkCtx_t*) l0)->f_typed;
    l3 = vader_typecheck_namespace_base_mod_id(l3, l4);
    if (l3.tag == 0u) {
        return vader_box_obj(0u, NULL);
    }
    l2 = l3.payload.s;
    l3 = std_collections_MutableMap_Index_at__string__Any(((vader_struct_vader_resolver_LoadedProject_t*) ((vader_struct_vader_effects_CalleeIndex_t*) ((vader_struct_vader_effects_WalkCtx_t*) l0)->f_index)->f_project)->f_modules, l2);
    if (l3.tag == 0u) {
        return vader_box_obj(0u, NULL);
    }
    l4 = l3.payload.obj;
    l4 = ((vader_struct_vader_resolver_CollectedModule_t*) ((vader_struct_vader_resolver_LoadedModule_t*) l4)->f_collected)->f_symbols;
    l2 = ((vader_struct_toolchain_ast_FieldExpr_t*) l1)->f_field;
    t0 = std_collections_MutableMap_Index_at__string__Any(l4, l2);
    return t0;
}

static void* vader_effects_new_skeleton(size_t l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[7] = { &l1, &l2, &l3, &l4, &l5, &l6, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 7u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(85u, 0u, 13u, 877u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(96u, 0u, 13u, 893u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(91u, 0u, 13u, 885u);
    l3 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(22u, 0u, 4u, 292u);
    l4 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_new(22u, 0u, 4u, 292u);
    l5 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_new(16u, 0u, 7u, 285u);
    l6 = (void*) _a5_arr;
    vader_struct_std_collections_MutableMap__usize__usize_t* _a6_obj = (vader_struct_std_collections_MutableMap__usize__usize_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__usize__usize_t));
    vader_obj_header_init(_a6_obj, 483u);
    _a6_obj->f_ekeys = l4;
    _a6_obj->f_evals = l5;
    _a6_obj->f_index = l6;
    _a6_obj->f_mask = (size_t) 0;
    _a6_obj->f_size = (size_t) 0;
    _a6_obj->f_tombs = (size_t) 0;
    l4 = (void*) _a6_obj;
    vader_struct_vader_effects_Skeleton_t* _a7_obj = (vader_struct_vader_effects_Skeleton_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_Skeleton_t));
    vader_obj_header_init(_a7_obj, 894u);
    _a7_obj->f_params = l0;
    _a7_obj->f_slots = l0;
    _a7_obj->f_flows = l1;
    _a7_obj->f_sites = l2;
    _a7_obj->f_marks = l3;
    _a7_obj->f_extra = (size_t) 0;
    _a7_obj->f_seeds = l4;
    t0 = (void*) _a7_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static size_t vader_effects_next_root(void* l0) {
    size_t l1, l2;
    int64_t t0;
    size_t t1;
    l1 = ((vader_struct_vader_effects_Skeleton_t*) l0)->f_params;
    l2 = ((vader_struct_vader_effects_Skeleton_t*) l0)->f_extra;
    t0 = vader_chk_add(usize, l1, l2);
    l1 = (size_t) (int64_t) t0;
    t1 = ((vader_struct_vader_effects_Skeleton_t*) l0)->f_extra;
    t0 = vader_chk_add(usize, t1, INT64_C(1));
    l2 = (size_t) (int64_t) t0;
    ((vader_struct_vader_effects_Skeleton_t*) l0)->f_extra = l2;
    return l1;
}

void* vader_effects_no_roots(void) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(95u, 0u, 13u, 890u);
    t0 = (void*) _a0_arr;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_effects_node_ctx(void* l0, void* l1, void* l2, int32_t l3) {
    void* l4 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l4, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l4 = vader_effects_any_effects();
    vader_struct_vader_effects_EvalCtx_t* _a0_obj = (vader_struct_vader_effects_EvalCtx_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_EvalCtx_t));
    vader_obj_header_init(_a0_obj, 876u);
    _a0_obj->f_facts = l0;
    _a0_obj->f_paths = l1;
    _a0_obj->f_components = l2;
    _a0_obj->f_node = l3;
    _a0_obj->f_any = l4;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_effects_none(void) {
    void* l0 = NULL;
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(83u, 0u, 13u, 869u);
    l0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(17u, 0u, 8u, 286u);
    l1 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(13u, 0u, 12u, 280u);
    l2 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(16u, 0u, 7u, 285u);
    l3 = (void*) _a3_arr;
    vader_struct_std_collections_MutableMap__i64__bool_t* _a4_obj = (vader_struct_std_collections_MutableMap__i64__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i64__bool_t));
    vader_obj_header_init(_a4_obj, 385u);
    _a4_obj->f_ekeys = l1;
    _a4_obj->f_evals = l2;
    _a4_obj->f_index = l3;
    _a4_obj->f_mask = (size_t) 0;
    _a4_obj->f_size = (size_t) 0;
    _a4_obj->f_tombs = (size_t) 0;
    t0 = (void*) _a4_obj;
    vader_struct_std_collections_MutableSet__i64_t* _a5_obj = (vader_struct_std_collections_MutableSet__i64_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i64_t));
    vader_obj_header_init(_a5_obj, 486u);
    _a5_obj->f_inner = t0;
    l1 = (void*) _a5_obj;
    vader_struct_vader_effects_ParamEffects_t* _a6_obj = (vader_struct_vader_effects_ParamEffects_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_ParamEffects_t));
    vader_obj_header_init(_a6_obj, 886u);
    _a6_obj->f_accesses = l0;
    _a6_obj->f_keys = l1;
    t0 = (void*) _a6_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_effects_note_frozen_body(void* l0, int32_t l1, vader_box_t l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    bool t0;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[4] = { &l0, &l3, &l4, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = std_collections_is_empty__usize__usize(((vader_struct_vader_effects_Skeleton_t*) ((vader_struct_vader_effects_WalkCtx_t*) l0)->f_s)->f_seeds);
    if (!(t0)) {
        l3 = ((vader_struct_vader_effects_WalkCtx_t*) l0)->f_s;
        l4 = ((vader_struct_vader_effects_WalkCtx_t*) l0)->f_roots;
        l5 = ((vader_struct_vader_effects_WalkCtx_t*) l0)->f_typed;
        vader_struct_vader_effects_FrozenBody_t* _a0_obj = (vader_struct_vader_effects_FrozenBody_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_FrozenBody_t));
        vader_obj_header_init(_a0_obj, 878u);
        _a0_obj->f_skeleton = l3;
        _a0_obj->f_roots = l4;
        _a0_obj->f_typed = l5;
        _a0_obj->f_node = l1;
        _a0_obj->f_initialises = l2;
        l3 = (void*) _a0_obj;
        vader_array_push((vader_array_t*) ((vader_struct_vader_effects_FrozenSites_t*) ((vader_struct_vader_effects_WalkCtx_t*) l0)->f_frozen)->f_bodies, vader_ref_box(l3));
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_effects_note_initialisers(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    size_t l5, l6;
    vader_box_t l9 = vader_box_null(), l10 = vader_box_null(), l11 = vader_box_null();
    int64_t t0;
    vader_box_t* gc_roots[3] = { &l9, &l10, &l11 };
    void** gc_raw_roots[7] = { &l0, &l1, &l2, &l3, &l4, &l7, &l8 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 7u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_effects_CalleeIndex_t*) l0)->f_constants;
    l4 = ((vader_struct_vader_effects_CalleeIndex_t*) l0)->f_defaults;
    l5 = ((vader_array_t*) l3)->length;
    l6 = (size_t) 0;
    while ((l6 < l5)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l7 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l6);
        l8 = vader_effects_initialiser_ctx(l0, l1, l2, l7);
        l9 = ((vader_struct_vader_effects_Initialiser_t*) l7)->f_value;
        l10 = vader_effects_value(l8, l9);
        vader_effects_escape(l8, l10, (uint8_t) 3);
        l11 = ((vader_struct_vader_effects_Initialiser_t*) l7)->f_initialises;
        vader_effects_note_frozen_body(l8, INT32_C(-1), l11);
        t0 = (l6 + INT64_C(1));
        l6 = (size_t) (int64_t) t0;
    }
    l5 = ((vader_array_t*) l4)->length;
    l6 = (size_t) 0;
    while ((l6 < l5)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l3 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l6);
        l7 = vader_effects_initialiser_ctx(l0, l1, l2, l3);
        l9 = ((vader_struct_vader_effects_Initialiser_t*) l3)->f_value;
        l10 = vader_effects_value(l7, l9);
        vader_effects_escape(l7, l10, (uint8_t) 3);
        l11 = ((vader_struct_vader_effects_Initialiser_t*) l3)->f_initialises;
        vader_effects_note_frozen_body(l7, INT32_C(-1), l11);
        t0 = (l6 + INT64_C(1));
        l6 = (size_t) (int64_t) t0;
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_effects_note_kept_by_constant(void* l0, void* l1, void* l2) {
    int32_t l3;
    vader_box_t l4 = vader_box_null();
    void* l5 = NULL;
    void* l6 = NULL;
    bool t0;
    vader_box_t* gc_roots[1] = { &l4 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l5, &l6 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l4 = ((vader_struct_vader_effects_FrozenBody_t*) ((vader_struct_vader_effects_RootCase_t*) l1)->f_body)->f_initialises;
    if (l4.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l3 = ((int32_t) l4.payload.i);
    l4 = ((vader_struct_vader_effects_FrozenRoot_t*) l2)->f_constant;
    if (l4.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l5 = l4.payload.obj;
    l6 = (void*) &vader_fn_static_vader_effects_is_kept;
    t0 = vader_effects_hands_on_written(l0, l1, l6);
    if (!(t0)) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l4 = std_collections_MutableMap_Index_at__i32__Any(((vader_struct_vader_effects_FrozenSites_t*) l0)->f_kept_by_constants, l3);
    if (l4.tag == 0u) {
        vader_array_t* _a0_arr = vader_array_new(84u, 0u, 13u, 874u);
        l6 = (void*) _a0_arr;
    } else {
        l6 = l4.payload.obj;
    }
    vader_array_push((vader_array_t*) l6, vader_ref_box(l5));
    std_collections_MutableMap_IndexSet_set_at__i32__Any(((vader_struct_vader_effects_FrozenSites_t*) l0)->f_kept_by_constants, l3, vader_ref_box(l6));
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_effects_note_known_writes(void* l0, void* l1, size_t l2, vader_box_t l3) {
    void* l4 = NULL;
    void* l9 = NULL;
    void* l13 = NULL;
    size_t l5, l6, l8, l11, l12, l14;
    vader_box_t l7 = vader_box_null(), l15 = vader_box_null();
    bool l10;
    void* t0 = NULL;
    bool t1;
    int64_t t2;
    vader_box_t* gc_roots[3] = { &l3, &l7, &l15 };
    void** gc_raw_roots[6] = { &l0, &l1, &l4, &l9, &l13, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 6u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l4 = l1;
    l5 = ((vader_array_t*) l4)->length;
    l6 = (size_t) 0;
    while ((l6 < l5)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l7 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l6);
        if (l7.tag == 884u) {
            t0 = l7.payload.obj;
            l8 = ((vader_array_t*) ((vader_struct_vader_effects_KnownEffects_t*) t0)->f_params)->length;
            if ((l2 < l8)) {
                t0 = l7.payload.obj;
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_effects_KnownEffects_t*) t0)->f_params);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l2)
                t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l2);
                l9 = ((vader_struct_vader_effects_ParamEffects_t*) t0)->f_accesses;
                l10 = false;
                l11 = ((vader_array_t*) l9)->length;
                l12 = (size_t) 0;
                {
                    while ((l12 < l11)) {
                        vader_array_t* _a2_slotarr = ((vader_array_t*) l9);
                        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                        t0 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l12);
                        t1 = vader_effects_modifies(t0);
                        if (t1) {
                            l10 = true;
                            goto end_40;
                        }
                        t2 = (l12 + INT64_C(1));
                        l12 = (size_t) (int64_t) t2;
                    }
                    l10 = false;
                } end_40: ;
                if (l10) {
                    l13 = ((vader_struct_vader_typecheck_TypedProgram_t*) ((vader_struct_vader_effects_WalkCtx_t*) l0)->f_typed)->f_expr_types;
                    t0 = l3.payload.obj;
                    l14 = ((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t0)->f_id;
                    l15 = std_collections_MutableMap_Index_at__usize__Any(l13, l14);
                    vader_effects_note_written(l0, l15);
                }
            }
        }
        t2 = (l6 + INT64_C(1));
        l6 = (size_t) (int64_t) t2;
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_effects_note_widened(void* l0, vader_box_t l1, void* l2, size_t l3, vader_box_t l4) {
    void* l5 = NULL;
    void* l8 = NULL;
    size_t l6;
    vader_box_t l7 = vader_box_null();
    vader_string_t l9 = 0;
    int32_t l10;
    void* t0 = NULL;
    vader_box_t* gc_roots[3] = { &l1, &l4, &l7 };
    void** gc_raw_roots[5] = { &l0, &l2, &l5, &l8, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l9 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l5 = ((vader_struct_vader_typecheck_TypedProgram_t*) ((vader_struct_vader_effects_WalkCtx_t*) l0)->f_typed)->f_widened_arguments;
    t0 = l4.payload.obj;
    l6 = ((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t0)->f_id;
    l7 = std_collections_MutableMap_Index_at__usize__Any(l5, l6);
    if (l7.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l5 = l7.payload.obj;
    t0 = l4.payload.obj;
    l6 = ((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t0)->f_id;
    t0 = l4.payload.obj;
    l8 = ((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t0)->f_span;
    l9 = ((vader_struct_vader_resolver_ResolvedModule_t*) ((vader_struct_vader_typecheck_TypedProgram_t*) ((vader_struct_vader_effects_WalkCtx_t*) l0)->f_typed)->f_resolved)->f_display_path;
    l10 = ((vader_struct_vader_typecheck_WidenedArgument_t*) l5)->f_depth;
    vader_struct_vader_effects_WideningSite_t* _a0_obj = (vader_struct_vader_effects_WideningSite_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_WideningSite_t));
    vader_obj_header_init(_a0_obj, 897u);
    _a0_obj->f_arg = l6;
    _a0_obj->f_span = l8;
    _a0_obj->f_module = l9;
    _a0_obj->f_depth = l10;
    _a0_obj->f_callee = l1;
    _a0_obj->f_param = l3;
    _a0_obj->f_verdict = (uint8_t) 0;
    _a0_obj->f_breaking = vader_box_obj(0u, NULL);
    l5 = (void*) _a0_obj;
    l8 = ((vader_struct_vader_effects_WalkCtx_t*) l0)->f_widenings;
    vader_struct_vader_effects_PendingWidening_t* _a1_obj = (vader_struct_vader_effects_PendingWidening_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_PendingWidening_t));
    vader_obj_header_init(_a1_obj, 889u);
    _a1_obj->f_site = l5;
    _a1_obj->f_targets = l2;
    l5 = (void*) _a1_obj;
    vader_array_push((vader_array_t*) l8, vader_ref_box(l5));
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_effects_note_write(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    size_t l3;
    vader_box_t l4 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[2] = { &l1, &l4 };
    void** gc_raw_roots[3] = { &l0, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_typecheck_TypedProgram_t*) ((vader_struct_vader_effects_WalkCtx_t*) l0)->f_typed)->f_expr_types;
    t0 = l1.payload.obj;
    l3 = ((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t0)->f_id;
    l4 = std_collections_MutableMap_Index_at__usize__Any(l2, l3);
    vader_effects_note_written(l0, l4);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_effects_note_written(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    size_t l3, l4;
    vader_string_t l5 = 0;
    vader_box_t t0 = vader_box_null();
    int64_t t1;
    vader_box_t* gc_roots[2] = { &l1, &t0 };
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_string_t* gc_atom_roots[1] = { &l5 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_effects_written_keys(l1);
    l3 = ((vader_array_t*) l2)->length;
    l4 = (size_t) 0;
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l4];
        l5 = t0.payload.s;
        std_collections_add__string(((vader_struct_vader_effects_FrozenSites_t*) ((vader_struct_vader_effects_WalkCtx_t*) l0)->f_frozen)->f_written, l5);
        t1 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t1;
    }
    { vader_gc_top = gc_frame.prev; return; }
}

bool vader_effects_noted(void* l0, int32_t l1, bool l2) {
    int64_t l3;
    void* l4;
    int64_t t0;
    t0 = ((vader_struct_vader_effects_Clock_t*) l0)->f_now;
    l3 = vader_chk_add(i64, t0, INT64_C(1));
    ((vader_struct_vader_effects_Clock_t*) l0)->f_now = l3;
    l4 = ((vader_struct_vader_effects_Clock_t*) l0)->f_evaluated_at;
    l3 = ((vader_struct_vader_effects_Clock_t*) l0)->f_now;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l1] = (int64_t) l3;
    if (l2) {
        t0 = ((vader_struct_vader_effects_Clock_t*) l0)->f_now;
        l3 = vader_chk_add(i64, t0, INT64_C(1));
        ((vader_struct_vader_effects_Clock_t*) l0)->f_now = l3;
        l4 = ((vader_struct_vader_effects_Clock_t*) l0)->f_grew_at;
        l3 = ((vader_struct_vader_effects_Clock_t*) l0)->f_now;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l1)
        ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l1] = (int64_t) l3;
        return l2;
    }
    return l2;
}

static vader_box_t vader_effects_nothing(void* l0, vader_box_t l1) {
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_effects_discard(l0, l1);
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static vader_box_t vader_effects_outcome(void* l0, void* l1, void* l2) {
    bool t0;
    vader_box_t t1 = vader_box_null();
    uint8_t t2;
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_effects_FrozenRoot_t*) l2)->f_binding;
    if (!(t0)) {
        t1 = vader_effects_use_outcome(l0, l1);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = vader_effects_binding_outcome(l0, l1);
    t1 = vader_box_i32(288u, (int32_t)(uint32_t) t2);
    { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static int64_t vader_effects_pair_key(int32_t l0, int32_t l1) {
    int64_t l2, l3;
    l2 = (((int64_t) (int32_t) l0) << INT64_C(32));
    l3 = ((int64_t) (int32_t) l1);
    return (l2 | l3);
}

static vader_box_t vader_effects_parameter_name(vader_box_t l0, size_t l1) {
    size_t l2;
    void* t0;
    vader_string_t t1;
    vader_box_t t2;
    if (l0.tag == 1138u) {
        t0 = l0.payload.obj;
        l2 = ((vader_array_t*) ((vader_struct_toolchain_ast_FnDecl_t*) ((vader_struct_vader_typecheck_DirectFn_t*) t0)->f_decl)->f_params)->length;
        if ((l1 < l2)) {
            t0 = l0.payload.obj;
            vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_FnDecl_t*) ((vader_struct_vader_typecheck_DirectFn_t*) t0)->f_decl)->f_params);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
            t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l1);
            t1 = ((vader_struct_toolchain_ast_FnParam_t*) t0)->f_name;
            t2 = vader_box_string(282u, t1);
            return t2;
        }
        return vader_box_obj(0u, NULL);
    }
    return vader_box_obj(0u, NULL);
}

static bool vader_effects_passes_receiver(void* l0, void* l1, void* l2, vader_box_t l3) {
    bool l4;
    void* l5;
    void* l6;
    size_t l7;
    void* t0;
    size_t t1;
    bool t2;
    if (l3.tag == 1138u) {
        t0 = l3.payload.obj;
        l5 = ((vader_struct_vader_typecheck_DirectFn_t*) t0)->f_decl;
        l6 = ((vader_struct_vader_effects_WalkCtx_t*) l0)->f_typed;
        t1 = vader_typecheck_receiver_offset(l1, l5, l6);
        l4 = t1 == INT64_C(1);
        return l4;
    }
    if ((l3.tag == 1128u || l3.tag == 1175u || l3.tag == 1183u)) {
        l5 = ((vader_struct_vader_typecheck_TypedProgram_t*) ((vader_struct_vader_effects_WalkCtx_t*) l0)->f_typed)->f_static_members;
        l7 = ((vader_struct_toolchain_ast_FieldExpr_t*) l2)->f_id;
        t2 = std_collections_MutableMap_Contains_contains__usize__Any(l5, l7);
        l4 = !(t2);
    } else {
        if (!((l3.tag == 1130u || l3.tag == 1139u || l3.tag == 1142u || l3.tag == 1147u))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l4 = false;
    }
    return l4;
}

static int32_t vader_effects_path_to(void* l0, vader_string_t l1) {
    int32_t l2;
    int32_t t0;
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_effects_step_id(l0, l1);
    t0 = vader_effects_child(l0, INT32_C(0), l2);
    { int32_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_effects_push_effects(int32_t l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[3] = { &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_effects_effects_of((uint8_t) 1, INT32_C(0));
    l2 = vader_effects_effects_of((uint8_t) 3, l0);
    vader_array_t* _a0_arr = vader_array_new(92u, 2u, 13u, 886u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 1u] = l2;
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = l1;
    t0 = (void*) _a0_arr;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_effects_range_value(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null();
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_toolchain_ast_RangeExpr_t*) l1)->f_lower;
    vader_effects_discard(l0, l2);
    l2 = ((vader_struct_toolchain_ast_RangeExpr_t*) l1)->f_upper;
    vader_effects_discard(l0, l2);
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static void vader_effects_read_fresh(void* l0, void* l1) {
    void* l2 = NULL;
    vader_box_t l3 = vader_box_null();
    vader_box_t* gc_roots[1] = { &l3 };
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_effects_FrozenRoot_t*) l1)->f_constant;
    if (l3.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l2 = l3.payload.obj;
    vader_effects_mark_fresh(l0, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static bool vader_effects_reads_fresh(void* l0, void* l1, uint8_t l2) {
    bool l3, l5;
    void* l4 = NULL;
    void** gc_raw_roots[3] = { &l0, &l1, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l2 == INT32_C(3)) {
        l3 = true;
        { bool __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l2 == INT32_C(2)) {
        l4 = (void*) &vader_fn_static_vader_effects_is_unknown;
        l3 = vader_effects_hands_on_written(l0, l1, l4);
    } else {
        if (l2 == INT32_C(0)) {
            l5 = true;
        } else {
            l5 = l2 == INT32_C(1);
        }
        if (l5) {
            l5 = true;
        } else {
            l5 = l2 == INT32_C(4);
        }
        if (l5) {
            l5 = true;
        } else {
            l5 = l2 == INT32_C(5);
        }
        if (!(l5)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l3 = false;
    }
    { bool __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_effects_record(void* l0, void* l1, void* l2, uint8_t l3, vader_string_t l4, bool l5) {
    void* l6 = NULL;
    vader_string_t l7 = 0;
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &l6 };
    vader_string_t* gc_atom_roots[2] = { &l4, &l7 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l6 = ((vader_struct_vader_effects_FrozenRoot_t*) l2)->f_span;
    l7 = ((vader_struct_vader_resolver_ResolvedModule_t*) ((vader_struct_vader_typecheck_TypedProgram_t*) ((vader_struct_vader_effects_FrozenBody_t*) l1)->f_typed)->f_resolved)->f_display_path;
    vader_struct_vader_effects_FrozenSite_t* _a0_obj = (vader_struct_vader_effects_FrozenSite_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_FrozenSite_t));
    vader_obj_header_init(_a0_obj, 880u);
    _a0_obj->f_span = l6;
    _a0_obj->f_module = l7;
    _a0_obj->f_kind = l3;
    _a0_obj->f_root = l4;
    _a0_obj->f_mixed = l5;
    l6 = (void*) _a0_obj;
    vader_array_push((vader_array_t*) ((vader_struct_vader_effects_FrozenSites_t*) l0)->f_sites, vader_ref_box(l6));
    { vader_gc_top = gc_frame.prev; return; }
}

static bool vader_effects_recursive(void* l0, vader_box_t l1) {
    void* l2;
    int32_t l3, l4;
    size_t t0;
    void* t1;
    if (l1.tag == 872u) {
        t0 = ((vader_array_t*) ((vader_struct_vader_effects_EvalCtx_t*) l0)->f_components)->length;
        if (!(t0 == INT64_C(0))) {
            l2 = ((vader_struct_vader_effects_EvalCtx_t*) l0)->f_components;
            t1 = l1.payload.obj;
            l3 = ((vader_struct_vader_effects_CalleeNode_t*) t1)->f_node;
            vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
            l3 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            l2 = ((vader_struct_vader_effects_EvalCtx_t*) l0)->f_components;
            l4 = ((vader_struct_vader_effects_EvalCtx_t*) l0)->f_node;
            vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
            l4 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
            return l3 == l4;
        }
        return false;
    }
    return false;
}

static void vader_effects_register(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    void* l6 = NULL;
    size_t l4;
    int32_t l5;
    vader_box_t l7 = vader_box_null();
    size_t t0;
    vader_box_t* gc_roots[1] = { &l7 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &l6 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (!(((vader_struct_toolchain_ast_FnDecl_t*) l1)->f_body.tag == 0u)) {
        l3 = ((vader_struct_vader_effects_CalleeIndex_t*) l0)->f_nodes;
        l4 = ((vader_struct_toolchain_ast_FnDecl_t*) l1)->f_id;
        t0 = ((vader_array_t*) ((vader_struct_vader_effects_CalleeIndex_t*) l0)->f_functions)->length;
        l5 = ((int32_t) (size_t) t0);
        std_collections_MutableMap_IndexSet_set_at__usize__i32(l3, l4, l5);
        l3 = ((vader_struct_vader_effects_CalleeIndex_t*) l0)->f_functions;
        vader_struct_vader_effects_Function_t* _a0_obj = (vader_struct_vader_effects_Function_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_Function_t));
        vader_obj_header_init(_a0_obj, 882u);
        _a0_obj->f_decl = l1;
        _a0_obj->f_typed = l2;
        l6 = (void*) _a0_obj;
        vader_array_push((vader_array_t*) l3, vader_ref_box(l6));
        { vader_gc_top = gc_frame.prev; return; }
    }
    l3 = ((vader_struct_vader_effects_CalleeIndex_t*) l0)->f_bodyless;
    l4 = ((vader_struct_toolchain_ast_FnDecl_t*) l1)->f_id;
    l7 = vader_effects_bodyless_target(l0, l1, l2);
    std_collections_MutableMap_IndexSet_set_at__usize__Any(l3, l4, l7);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_effects_register_defaults(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    size_t l4, l5;
    vader_box_t l6 = vader_box_null(), l7 = vader_box_null();
    void* t0 = NULL;
    int64_t t1;
    vader_box_t* gc_roots[2] = { &l6, &l7 };
    void** gc_raw_roots[7] = { &l0, &l1, &l2, &l3, &l8, &l9, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 7u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_toolchain_ast_StructDecl_t*) l1)->f_fields;
    l4 = ((vader_array_t*) l3)->length;
    l5 = (size_t) 0;
    while ((l5 < l4)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
        l7 = ((vader_struct_toolchain_ast_StructField_t*) t0)->f_default_v;
        if (l7.tag == 0u) {
            t1 = (l5 + INT64_C(1));
            l5 = (size_t) (int64_t) t1;
            continue;
        }
        l6 = l7;
        l8 = ((vader_struct_vader_effects_CalleeIndex_t*) l0)->f_defaults;
        vader_struct_vader_effects_Initialiser_t* _a1_obj = (vader_struct_vader_effects_Initialiser_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_Initialiser_t));
        vader_obj_header_init(_a1_obj, 883u);
        _a1_obj->f_value = l6;
        _a1_obj->f_typed = l2;
        _a1_obj->f_initialises = vader_box_obj(0u, NULL);
        l9 = (void*) _a1_obj;
        vader_array_push((vader_array_t*) l8, vader_ref_box(l9));
        t1 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t1;
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void* vader_effects_remove_last_effects(int32_t l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void** gc_raw_roots[2] = { &l1, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_effects_effects_of((uint8_t) 2, INT32_C(0));
    vader_struct_vader_effects_Access_t* _a0_obj = (vader_struct_vader_effects_Access_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_Access_t));
    vader_obj_header_init(_a0_obj, 869u);
    _a0_obj->f_path = l0;
    _a0_obj->f_effect = (uint8_t) 4;
    l2 = (void*) _a0_obj;
    vader_effects_insert(l1, l2);
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_effects_reroot(void* l0, void* l1, void* l2, void* l3) {
    bool l4;
    void* l5 = NULL;
    void* l9 = NULL;
    size_t l6, l7, l8, l10;
    void* t0 = NULL;
    bool t1;
    int64_t t2;
    void** gc_raw_roots[7] = { &l0, &l1, &l2, &l3, &l5, &l9, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 7u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l4 = false;
    l5 = ((vader_struct_vader_effects_SlotRoots_t*) l0)->f_roots;
    l6 = ((vader_struct_vader_effects_Flow_t*) l1)->f_from;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l6)
    t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l6);
    l6 = ((vader_array_t*) t0)->length;
    l7 = (size_t) 0;
    while ((l7 < l6)) {
        l5 = ((vader_struct_vader_effects_SlotRoots_t*) l0)->f_roots;
        l8 = ((vader_struct_vader_effects_Flow_t*) l1)->f_from;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l8)
        t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l8);
        vader_array_t* _a2_slotarr = ((vader_array_t*) t0);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l7)
        t0 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l7);
        l9 = vader_effects_flowed_root(t0, l1, l2, l3);
        l10 = ((vader_struct_vader_effects_Flow_t*) l1)->f_into;
        t1 = vader_effects_include_root(l0, l10, l9);
        if (t1) {
            l4 = true;
        }
        t2 = (l7 + INT64_C(1));
        l7 = (size_t) (int64_t) t2;
    }
    { bool __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_effects_reroot_below(void* l0, size_t l1, int32_t l2, size_t l3, void* l4, bool l5) {
    bool l6;
    size_t l7, l8, l10;
    void* l9 = NULL;
    void* l13 = NULL;
    int32_t l11, l12;
    void* t0 = NULL;
    bool t1;
    int64_t t2;
    void** gc_raw_roots[5] = { &l0, &l4, &l9, &l13, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l6 = false;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_effects_SlotRoots_t*) l0)->f_roots);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l1);
    l7 = ((vader_array_t*) t0)->length;
    l8 = (size_t) 0;
    while ((l8 < l7)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_effects_SlotRoots_t*) l0)->f_roots);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l1)
        t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l1);
        vader_array_t* _a2_slotarr = ((vader_array_t*) t0);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l8)
        l9 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l8);
        l10 = ((vader_struct_vader_effects_Root_t*) l9)->f_param;
        l11 = ((vader_struct_vader_effects_Root_t*) l9)->f_path;
        l12 = vader_effects_composed(l4, l11, l2, l5);
        vader_struct_vader_effects_Root_t* _a3_obj = (vader_struct_vader_effects_Root_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_Root_t));
        vader_obj_header_init(_a3_obj, 890u);
        _a3_obj->f_param = l10;
        _a3_obj->f_path = l12;
        l13 = (void*) _a3_obj;
        t1 = vader_effects_include_root(l0, l3, l13);
        if (t1) {
            l6 = true;
        }
        t2 = (l8 + INT64_C(1));
        l8 = (size_t) (int64_t) t2;
    }
    { bool __vret = l6; vader_gc_top = gc_frame.prev; return __vret; }
}

static uint8_t vader_effects_return_effect(void* l0) {
    int32_t t0;
    t0 = ((vader_struct_vader_effects_WalkCtx_t*) l0)->f_lambda_depth;
    if (!((t0 > INT32_C(0)))) {
        return (uint8_t) 4;
    }
    return (uint8_t) 3;
}

static void vader_effects_return_stmt(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null();
    uint8_t l3;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_toolchain_ast_ReturnStmt_t*) l1)->f_value;
    if (l2.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l2 = vader_effects_value(l0, l2);
    l3 = vader_effects_return_effect(l0);
    vader_effects_escape(l0, l2, l3);
    { vader_gc_top = gc_frame.prev; return; }
}

static void* vader_effects_root_record(void* l0, size_t l1) {
    void* l2;
    size_t l3;
    int64_t t0;
    void* t1;
    l2 = ((vader_struct_vader_effects_FrozenBody_t*) l0)->f_roots;
    l3 = ((vader_struct_vader_effects_Skeleton_t*) ((vader_struct_vader_effects_FrozenBody_t*) l0)->f_skeleton)->f_params;
    t0 = vader_chk_sub(usize, l1, l3);
    l3 = (size_t) (int64_t) t0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
    t1 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
    return t1;
}

static vader_box_t vader_effects_sequence_value(void* l0, void* l1) {
    void* l2 = NULL;
    size_t l3, l4;
    vader_box_t l5 = vader_box_null(), l6 = vader_box_null();
    int64_t t0;
    vader_box_t* gc_roots[2] = { &l5, &l6 };
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_toolchain_ast_SeqLitExpr_t*) l1)->f_elements;
    l3 = ((vader_array_t*) l2)->length;
    l4 = (size_t) 0;
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l5 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        l6 = vader_effects_value(l0, l5);
        vader_effects_escape(l0, l6, (uint8_t) 3);
        t0 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t0;
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static vader_box_t vader_effects_sequence_walked(void* l0, void* l1) {
    void* l2 = NULL;
    size_t l3, l4;
    vader_box_t l5 = vader_box_null();
    int64_t t0;
    vader_box_t* gc_roots[1] = { &l5 };
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = l1;
    l3 = ((vader_array_t*) l2)->length;
    l4 = (size_t) 0;
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l5 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        vader_effects_discard(l0, l5);
        t0 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t0;
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

bool vader_effects_settle(void* l0, void* l1) {
    void* l2 = NULL;
    void* l6 = NULL;
    void* l8 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    void* l15 = NULL;
    void* l16 = NULL;
    bool l3;
    size_t l4, l5;
    int32_t l7, l9, l14;
    void* t0 = NULL;
    size_t t1;
    bool t2;
    int64_t t3;
    void** gc_raw_roots[12] = { &l0, &l1, &l2, &l6, &l8, &l10, &l11, &l12, &l13, &l15, &l16, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 12u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = vader_effects_evaluate(l0, l1);
    l3 = false;
    l4 = (size_t) 0;
    l5 = ((vader_array_t*) l2)->length;
    while ((l4 < l5)) {
        l6 = ((vader_struct_vader_effects_EvalCtx_t*) l1)->f_facts;
        l7 = ((vader_struct_vader_effects_EvalCtx_t*) l1)->f_node;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l7)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l7);
        vader_array_t* _a1_slotarr = ((vader_array_t*) t0);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
        t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
        t1 = ((vader_array_t*) ((vader_struct_vader_effects_ParamEffects_t*) t0)->f_accesses)->length;
        if (t1 == INT64_C(0)) {
            l8 = ((vader_struct_vader_effects_EvalCtx_t*) l1)->f_facts;
            l9 = ((vader_struct_vader_effects_EvalCtx_t*) l1)->f_node;
            vader_array_t* _a2_slotarr = ((vader_array_t*) l8);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l9)
            l10 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l9);
            vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            l11 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l4);
            vader_array_t* _a4_slotarr = ((vader_array_t*) l10);
            VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l4)
            vader_array_ref_store(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l4, l11);
            VADER_WRITE_BARRIER(_a4_slotarr->buf);
            t0 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l4);
            t1 = ((vader_array_t*) ((vader_struct_vader_effects_ParamEffects_t*) t0)->f_accesses)->length;
            if ((t1 > INT64_C(0))) {
                l3 = true;
            }
        } else {
            l12 = ((vader_struct_vader_effects_EvalCtx_t*) l1)->f_paths;
            l13 = ((vader_struct_vader_effects_EvalCtx_t*) l1)->f_facts;
            l14 = ((vader_struct_vader_effects_EvalCtx_t*) l1)->f_node;
            vader_array_t* _a5_slotarr = ((vader_array_t*) l13);
            VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l14)
            t0 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l14);
            vader_array_t* _a6_slotarr = ((vader_array_t*) t0);
            VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l4)
            l15 = vader_array_ref_load_obj(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l4);
            vader_array_t* _a7_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
            l16 = vader_array_ref_load_obj(_a7_slotarr->buf, _a7_slotarr->offset + (size_t) l4);
            t2 = vader_effects_include_all(l12, l15, l16);
            if (t2) {
                l3 = true;
            }
        }
        t3 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t3;
    }
    { bool __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_effects_settle_frozen(void* l0, void* l1, void* l2, void* l3) {
    void* l4 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    void* l13 = NULL;
    size_t l5, l6, l11, l12;
    int64_t t0;
    void** gc_raw_roots[10] = { &l0, &l1, &l2, &l3, &l4, &l7, &l8, &l9, &l10, &l13 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 10u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l4 = ((vader_struct_vader_effects_FrozenSites_t*) l0)->f_bodies;
    l5 = ((vader_array_t*) l4)->length;
    l6 = (size_t) 0;
    while ((l6 < l5)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l6)
        l7 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l6);
        l8 = vader_effects_body_ctx(l7, l1, l2, l3);
        l9 = vader_effects_evaluate_roots(((vader_struct_vader_effects_FrozenBody_t*) l7)->f_skeleton, l8);
        l10 = ((vader_struct_vader_effects_FrozenBody_t*) l7)->f_roots;
        l11 = ((vader_array_t*) l10)->length;
        l12 = (size_t) 0;
        while ((l12 < l11)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l10);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l12)
            l13 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l12);
            vader_effects_decide(l0, l7, l13, l9, l2);
            t0 = (l12 + INT64_C(1));
            l12 = (size_t) (int64_t) t0;
        }
        t0 = (l6 + INT64_C(1));
        l6 = (size_t) (int64_t) t0;
    }
    vader_effects_spread_fresh(l0);
    { vader_gc_top = gc_frame.prev; return; }
}

static void* vader_effects_settle_widenings(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void* l6 = NULL;
    void* l8 = NULL;
    size_t l5, l7;
    void* t0 = NULL;
    int64_t t1;
    void** gc_raw_roots[8] = { &l0, &l1, &l2, &l3, &l4, &l6, &l8, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 8u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = vader_effects_any_effects();
    vader_array_t* _a0_arr = vader_array_new(98u, 0u, 13u, 897u);
    l4 = (void*) _a0_arr;
    l5 = ((vader_array_t*) l0)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l4, (size_t) l5);
    l4 = (void*) _a1_arr;
    l6 = l0;
    l5 = ((vader_array_t*) l6)->length;
    l7 = (size_t) 0;
    while ((l7 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        t0 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l7);
        l8 = vader_effects_widening_outcome(t0, l1, l2, l3);
        vader_array_push((vader_array_t*) l4, vader_ref_box(l8));
        t1 = (l7 + INT64_C(1));
        l7 = (size_t) (int64_t) t1;
    }
    { void* __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_effects_settled_slots(void* l0, void* l1, bool l2) {
    size_t l3, l5, l10, l11, l12, l13;
    void* l4 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l15 = NULL;
    void* l16 = NULL;
    void* l17 = NULL;
    int64_t l6;
    bool l14;
    int64_t t0;
    void* t1 = NULL;
    bool t2;
    void** gc_raw_roots[10] = { &l0, &l1, &l4, &l7, &l8, &l9, &l15, &l16, &l17, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 10u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_effects_Skeleton_t*) l0)->f_slots;
    l4 = (void*) &vader_fn_static_vader_effects_no_roots;
    l4 = std_core_filled__Root__(l3, l4);
    l3 = ((vader_struct_vader_effects_Skeleton_t*) l0)->f_params;
    l5 = ((vader_struct_vader_effects_Skeleton_t*) l0)->f_extra;
    t0 = vader_chk_add(usize, l3, l5);
    l6 = t0;
    vader_array_t* _a0_arr = vader_array_new(17u, 0u, 8u, 286u);
    l7 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(13u, 0u, 12u, 280u);
    l8 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(16u, 0u, 7u, 285u);
    l9 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__i64__bool_t* _a3_obj = (vader_struct_std_collections_MutableMap__i64__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i64__bool_t));
    vader_obj_header_init(_a3_obj, 385u);
    _a3_obj->f_ekeys = l7;
    _a3_obj->f_evals = l8;
    _a3_obj->f_index = l9;
    _a3_obj->f_mask = (size_t) 0;
    _a3_obj->f_size = (size_t) 0;
    _a3_obj->f_tombs = (size_t) 0;
    t1 = (void*) _a3_obj;
    vader_struct_std_collections_MutableSet__i64_t* _a4_obj = (vader_struct_std_collections_MutableSet__i64_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i64_t));
    vader_obj_header_init(_a4_obj, 486u);
    _a4_obj->f_inner = t1;
    l7 = (void*) _a4_obj;
    vader_struct_vader_effects_SlotRoots_t* _a5_obj = (vader_struct_vader_effects_SlotRoots_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_SlotRoots_t));
    vader_obj_header_init(_a5_obj, 895u);
    _a5_obj->f_roots = l4;
    _a5_obj->f_root_count = l6;
    _a5_obj->f_seen = l7;
    l4 = (void*) _a5_obj;
    l3 = (size_t) 0;
    l5 = ((vader_struct_vader_effects_Skeleton_t*) l0)->f_params;
    while ((l3 < l5)) {
        vader_struct_vader_effects_Root_t* _a6_obj = (vader_struct_vader_effects_Root_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_Root_t));
        vader_obj_header_init(_a6_obj, 890u);
        _a6_obj->f_param = l3;
        _a6_obj->f_path = INT32_C(0);
        l7 = (void*) _a6_obj;
        vader_effects_include_root(l4, l3, l7);
        t0 = (l3 + INT64_C(1));
        l3 = (size_t) (int64_t) t0;
    }
    if (l2) {
        l7 = ((vader_struct_vader_effects_Skeleton_t*) l0)->f_seeds;
        l8 = ((vader_struct_std_collections_MutableMap__usize__usize_t*) l7)->f_ekeys;
        l9 = ((vader_struct_std_collections_MutableMap__usize__usize_t*) l7)->f_evals;
        l3 = ((vader_struct_std_collections_MutableMap__usize__usize_t*) l7)->f_size;
        l5 = (size_t) 0;
        while (!((l5 >= l3))) {
            vader_array_t* _a7_slotarr = ((vader_array_t*) l8);
            VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l5)
            t0 = ((int64_t*) _a7_slotarr->buf->slots)[_a7_slotarr->offset + (size_t) l5];
            l10 = (size_t) (int64_t) t0;
            vader_array_t* _a8_slotarr = ((vader_array_t*) l9);
            VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l5)
            t0 = ((int64_t*) _a8_slotarr->buf->slots)[_a8_slotarr->offset + (size_t) l5];
            l11 = (size_t) (int64_t) t0;
            l12 = l10;
            l13 = l11;
            t0 = (l5 + INT64_C(1));
            l5 = (size_t) (int64_t) t0;
            vader_struct_vader_effects_Root_t* _a9_obj = (vader_struct_vader_effects_Root_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_Root_t));
            vader_obj_header_init(_a9_obj, 890u);
            _a9_obj->f_param = l12;
            _a9_obj->f_path = INT32_C(0);
            l7 = (void*) _a9_obj;
            vader_effects_include_root(l4, l13, l7);
        }
    }
    for (;;) {
        l14 = false;
        l7 = ((vader_struct_vader_effects_Skeleton_t*) l0)->f_flows;
        l3 = ((vader_array_t*) l7)->length;
        l5 = (size_t) 0;
        while ((l5 < l3)) {
            vader_array_t* _a10_slotarr = ((vader_array_t*) l7);
            VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
            l8 = vader_array_ref_load_obj(_a10_slotarr->buf, _a10_slotarr->offset + (size_t) l5);
            l9 = ((vader_struct_vader_effects_Skeleton_t*) l0)->f_seeds;
            l15 = ((vader_struct_vader_effects_EvalCtx_t*) l1)->f_paths;
            t2 = vader_effects_reroot(l4, l8, l9, l15);
            if (t2) {
                l14 = true;
            }
            t0 = (l5 + INT64_C(1));
            l5 = (size_t) (int64_t) t0;
        }
        l16 = ((vader_struct_vader_effects_Skeleton_t*) l0)->f_sites;
        l10 = ((vader_array_t*) l16)->length;
        l11 = (size_t) 0;
        while ((l11 < l10)) {
            vader_array_t* _a11_slotarr = ((vader_array_t*) l16);
            VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
            l17 = vader_array_ref_load_obj(_a11_slotarr->buf, _a11_slotarr->offset + (size_t) l11);
            t2 = vader_effects_collect_returned(l4, l17, l1);
            if (t2) {
                l14 = true;
            }
            t0 = (l11 + INT64_C(1));
            l11 = (size_t) (int64_t) t0;
        }
        if (!(l14)) {
            { void* __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
        }
        continue;
    }
    vader_gc_top = gc_frame.prev;
}

static vader_box_t vader_effects_single(void* l0) {
    size_t t0;
    vader_box_t t1;
    t0 = ((vader_array_t*) l0)->length;
    if (!(t0 == INT64_C(1))) {
        return vader_box_obj(0u, NULL);
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    t1 = vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) INT32_C(0)];
    return t1;
}

static vader_box_t vader_effects_site_callee(void* l0, uint8_t l1, size_t l2) {
    void* t0;
    vader_box_t t1;
    t0 = vader_typecheck_sites_of(((vader_struct_vader_typecheck_TypedProgram_t*) ((vader_struct_vader_effects_WalkCtx_t*) l0)->f_typed)->f_call_sites, l1);
    t1 = std_collections_MutableMap_Index_at__usize__Any(t0, l2);
    return t1;
}

static void* vader_effects_skeleton_of(void* l0, void* l1, void* l2, void* l3, void* l4, int32_t l5) {
    void* l6 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l14 = NULL;
    void* l16 = NULL;
    size_t l10, l11;
    uint64_t l12, l15;
    vader_box_t l13 = vader_box_null();
    int32_t l17;
    size_t t0;
    int64_t t1;
    vader_box_t t2 = vader_box_null();
    bool t3;
    vader_box_t* gc_roots[2] = { &l13, &t2 };
    void** gc_raw_roots[11] = { &l0, &l1, &l2, &l3, &l4, &l6, &l7, &l8, &l9, &l14, &l16 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 11u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_toolchain_ast_FnDecl_t*) l0)->f_params)->length;
    l6 = vader_effects_new_skeleton(t0);
    vader_array_t* _a0_arr = vader_array_new(16u, 0u, 7u, 285u);
    l7 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(22u, 0u, 4u, 292u);
    l8 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(16u, 0u, 7u, 285u);
    l9 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__i32__usize_t* _a3_obj = (vader_struct_std_collections_MutableMap__i32__usize_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__usize_t));
    vader_obj_header_init(_a3_obj, 384u);
    _a3_obj->f_ekeys = l7;
    _a3_obj->f_evals = l8;
    _a3_obj->f_index = l9;
    _a3_obj->f_mask = (size_t) 0;
    _a3_obj->f_size = (size_t) 0;
    _a3_obj->f_tombs = (size_t) 0;
    l7 = (void*) _a3_obj;
    vader_array_t* _a4_arr = vader_array_new(87u, 0u, 13u, 879u);
    l8 = (void*) _a4_arr;
    vader_struct_vader_effects_WalkCtx_t* _a5_obj = (vader_struct_vader_effects_WalkCtx_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_WalkCtx_t));
    vader_obj_header_init(_a5_obj, 896u);
    _a5_obj->f_s = l6;
    _a5_obj->f_typed = l1;
    _a5_obj->f_index = l2;
    _a5_obj->f_slots = l7;
    _a5_obj->f_lambda_depth = INT32_C(0);
    _a5_obj->f_frozen = l3;
    _a5_obj->f_widenings = l4;
    _a5_obj->f_roots = l8;
    l6 = (void*) _a5_obj;
    l10 = (size_t) 0;
    l11 = ((vader_array_t*) ((vader_struct_toolchain_ast_FnDecl_t*) l0)->f_params)->length;
    while ((l10 < l11)) {
        vader_array_t* _a6_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_FnDecl_t*) l0)->f_params);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l10)
        l7 = vader_array_ref_load_obj(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l10);
        l9 = ((vader_struct_vader_resolver_ResolvedModule_t*) ((vader_struct_vader_typecheck_TypedProgram_t*) l1)->f_resolved)->f_idents;
        l12 = toolchain_span_Span_Hash_hash(((vader_struct_toolchain_ast_FnParam_t*) l7)->f_span);
        l13 = std_collections_MutableMap_Index_at__u64__Any(l9, l12);
        if (l13.tag == 0u) {
            t1 = (l10 + INT64_C(1));
            l10 = (size_t) (int64_t) t1;
            continue;
        }
        l8 = l13.payload.obj;
        l14 = ((vader_struct_vader_typecheck_TypedProgram_t*) l1)->f_param_types;
        l15 = toolchain_span_Span_Hash_hash(((vader_struct_toolchain_ast_FnParam_t*) l7)->f_span);
        t2 = std_collections_MutableMap_Index_at__u64__Any(l14, l15);
        t3 = vader_effects_holds_references(t2);
        if (t3) {
            l16 = ((vader_struct_vader_effects_WalkCtx_t*) l6)->f_slots;
            l17 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l8)->f_id;
            std_collections_MutableMap_IndexSet_set_at__i32__usize(l16, l17, l10);
        }
        t1 = (l10 + INT64_C(1));
        l10 = (size_t) (int64_t) t1;
    }
    l13 = ((vader_struct_toolchain_ast_FnDecl_t*) l0)->f_body;
    if (l13.tag == 0u) {
        { void* __vret = ((vader_struct_vader_effects_WalkCtx_t*) l6)->f_s; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l7 = l13.payload.obj;
    l13 = vader_effects_block_value(l6, l7);
    vader_effects_escape(l6, l13, (uint8_t) 4);
    vader_effects_note_frozen_body(l6, l5, vader_box_obj(0u, NULL));
    { void* __vret = ((vader_struct_vader_effects_WalkCtx_t*) l6)->f_s; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_effects_spread(void* l0, vader_box_t l1, void* l2) {
    size_t l3, l8, l9;
    vader_box_t l4 = vader_box_null(), l12 = vader_box_null();
    void* l5 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    vader_string_t l10 = 0;
    vader_string_t l11 = 0;
    int32_t l13;
    vader_box_t t0 = vader_box_null();
    int64_t t1;
    bool t2;
    vader_box_t* gc_roots[4] = { &l1, &l4, &l12, &t0 };
    void** gc_raw_roots[5] = { &l0, &l2, &l5, &l6, &l7 };
    vader_string_t* gc_atom_roots[2] = { &l10, &l11 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = vader_effects_value(l0, l1);
    if (l4.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l3 = ((size_t) l4.payload.i);
    l4 = vader_effects_struct_fields_of(l0, l1);
    if (l4.tag == 0u) {
        vader_effects_add_mark(((vader_struct_vader_effects_WalkCtx_t*) l0)->f_s, l3, INT32_C(1), (uint8_t) 3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    l5 = l4.payload.obj;
    l6 = ((vader_struct_std_collections_MutableMap__string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_t*) l5)->f_ekeys;
    l7 = ((vader_struct_std_collections_MutableMap__string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_t*) l5)->f_evals;
    l8 = ((vader_struct_std_collections_MutableMap__string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_t*) l5)->f_size;
    l9 = (size_t) 0;
    while (!((l9 >= l8))) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l9)
        t0 = vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l9];
        l10 = t0.payload.s;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l9)
        l4 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l9);
        l11 = l10;
        l12 = l4;
        t1 = (l9 + INT64_C(1));
        l9 = (size_t) (int64_t) t1;
        t2 = std_collections_MutableSet_Contains_contains__string(l2, l11);
        if (t2) {
            continue;
        }
        t2 = vader_effects_holds_references(l12);
        if (!(t2)) {
            continue;
        }
        l5 = ((vader_struct_vader_effects_WalkCtx_t*) l0)->f_s;
        l13 = vader_effects_path_to(((vader_struct_vader_effects_CalleeIndex_t*) ((vader_struct_vader_effects_WalkCtx_t*) l0)->f_index)->f_paths, l11);
        vader_effects_add_mark(l5, l3, l13, (uint8_t) 3);
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_effects_spread_fresh(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    size_t l4, l5;
    int32_t l6, l9;
    vader_box_t l7 = vader_box_null(), l8 = vader_box_null();
    int64_t t0;
    size_t t1;
    bool t2;
    vader_box_t* gc_roots[2] = { &l7, &l8 };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(16u, 0u, 7u, 285u);
    l1 = (void*) _a0_arr;
    l2 = ((vader_struct_vader_typecheck_FreshReads_t*) ((vader_struct_vader_effects_FrozenSites_t*) l0)->f_fresh)->f_constants;
    l3 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) ((vader_struct_std_collections_MutableSet__i32_t*) l2)->f_inner)->f_ekeys;
    l4 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) ((vader_struct_std_collections_MutableSet__i32_t*) l2)->f_inner)->f_size;
    l5 = (size_t) 0;
    vader_array_t* _pc14_hdr = (vader_array_t*) l1;
    size_t _pc14_len = _pc14_hdr->length;
    size_t _pc14_cap = (_pc14_hdr->offset == 0 && !vader_array_is_borrowed(_pc14_hdr) && _pc14_hdr->length >= _pc14_hdr->buf->length) ? _pc14_hdr->capacity : (size_t) 0;
    void* _pc14_slots = _pc14_hdr->buf->slots;
    for (;;) {
        if (!((l5 >= l4))) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
            l6 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l5];
            t0 = (l5 + INT64_C(1));
            l5 = (size_t) (int64_t) t0;
            if (VADER_LIKELY(_pc14_len < _pc14_cap)) {
                ((int32_t*) _pc14_slots)[_pc14_len] = (int32_t) (l6);
                _pc14_len += 1;
            } else {
                _pc14_hdr->length = _pc14_len;
                if (_pc14_hdr->buf->length < _pc14_len) {
                    _pc14_hdr->buf->length = _pc14_len;
                }
                vader_array_push_i32((vader_array_t*) l1, l6);
                _pc14_hdr = (vader_array_t*) l1;
                _pc14_len = _pc14_hdr->length;
                _pc14_cap = (_pc14_hdr->offset == 0 && !vader_array_is_borrowed(_pc14_hdr) && _pc14_hdr->length >= _pc14_hdr->buf->length) ? _pc14_hdr->capacity : (size_t) 0;
                _pc14_slots = _pc14_hdr->buf->slots;
            }
            continue;
        }
        _pc14_hdr->length = _pc14_len;
        if (_pc14_hdr->buf->length < _pc14_len) {
            _pc14_hdr->buf->length = _pc14_len;
        }
        break;
    }
    for (;;) {
        t1 = ((vader_array_t*) l1)->length;
        if ((t1 > INT64_C(0))) {
            l7 = vader_array_remove_last((vader_array_t*) l1);
            if (l7.tag == 0u) break;
            l6 = ((int32_t) l7.payload.i);
            l8 = std_collections_MutableMap_Index_at__i32__Any(((vader_struct_vader_effects_FrozenSites_t*) l0)->f_kept_by_constants, l6);
            if (l8.tag == 0u) {
                vader_array_t* _a2_arr = vader_array_new(84u, 0u, 13u, 874u);
                l2 = (void*) _a2_arr;
            } else {
                l2 = l8.payload.obj;
            }
            l4 = ((vader_array_t*) l2)->length;
            l5 = (size_t) 0;
            while ((l5 < l4)) {
                vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                l3 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l5);
                t2 = vader_effects_mark_fresh(l0, l3);
                if (t2) {
                    l9 = ((vader_struct_vader_effects_ConstantUse_t*) l3)->f_symbol;
                    vader_array_push_i32((vader_array_t*) l1, l9);
                }
                t0 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t0;
            }
            continue;
        }
        break;
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static int32_t vader_effects_step_id(void* l0, vader_string_t l1) {
    vader_box_t l2 = vader_box_null();
    int32_t l3;
    int32_t t0;
    size_t t1;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = std_collections_MutableMap_Index_at__string__i32(((vader_struct_vader_effects_PathTable_t*) l0)->f_step_ids, l1);
    if (!(l2.tag == 0u)) {
        t0 = ((int32_t) l2.payload.i);
        { int32_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = ((vader_array_t*) ((vader_struct_vader_effects_PathTable_t*) l0)->f_step_names)->length;
    l3 = ((int32_t) (size_t) t1);
    vader_array_push((vader_array_t*) ((vader_struct_vader_effects_PathTable_t*) l0)->f_step_names, vader_box_string(282u, l1));
    std_collections_MutableMap_IndexSet_set_at__string__i32(((vader_struct_vader_effects_PathTable_t*) l0)->f_step_ids, l1, l3);
    { int32_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_effects_step_slot(void* l0, vader_box_t l1, vader_string_t l2) {
    size_t l3, l5;
    vader_box_t l4 = vader_box_null();
    void* l6 = NULL;
    int32_t l7;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l1, &l4, &t0 };
    void** gc_raw_roots[2] = { &l0, &l6 };
    vader_string_t* gc_atom_roots[1] = { &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = l1;
    if (l4.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l3 = ((size_t) l4.payload.i);
    l5 = vader_effects_fresh_slot(((vader_struct_vader_effects_WalkCtx_t*) l0)->f_s);
    l6 = ((vader_struct_vader_effects_WalkCtx_t*) l0)->f_s;
    l7 = vader_effects_path_to(((vader_struct_vader_effects_CalleeIndex_t*) ((vader_struct_vader_effects_WalkCtx_t*) l0)->f_index)->f_paths, l2);
    vader_effects_add_flow(l6, l5, l3, l7);
    t0 = vader_box_i64(292u, (int64_t)(uint64_t) l5);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_effects_step_type(void* l0, vader_box_t l1, vader_string_t l2) {
    void* l3 = NULL;
    vader_box_t l4 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l1, &l4, &t0 };
    void** gc_raw_roots[2] = { &l0, &l3 };
    vader_string_t* gc_atom_roots[1] = { &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l1.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    if (!(l2 == 832u)) {
        t0 = vader_typecheck_declared_struct_field_type(l1, l2, l0);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = vader_types_array_backing(l1);
    if (l4.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l3 = l4.payload.obj;
    { vader_box_t __vret = ((vader_struct_vader_types_ArrayType_t*) l3)->f_element; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_effects_steps_of(void* l0, int32_t l1) {
    void* l2 = NULL;
    void* l5 = NULL;
    int32_t l3, l4;
    size_t l6, l7, l8;
    void* t0 = NULL;
    int32_t t1;
    size_t t2;
    int64_t t3, t4;
    void** gc_raw_roots[4] = { &l0, &l2, &l5, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(16u, 0u, 7u, 285u);
    l2 = (void*) _a0_arr;
    l3 = l1;
    vader_array_t* _pc4_hdr = (vader_array_t*) l2;
    size_t _pc4_len = _pc4_hdr->length;
    size_t _pc4_cap = (_pc4_hdr->offset == 0 && !vader_array_is_borrowed(_pc4_hdr) && _pc4_hdr->length >= _pc4_hdr->buf->length) ? _pc4_hdr->capacity : (size_t) 0;
    void* _pc4_slots = _pc4_hdr->buf->slots;
    for (;;) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_effects_PathTable_t*) l0)->f_nodes);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
        t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l3);
        t1 = ((vader_struct_vader_effects_PathNode_t*) t0)->f_length;
        if ((t1 > INT32_C(0))) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_effects_PathTable_t*) l0)->f_nodes);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
            t0 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l3);
            l4 = ((vader_struct_vader_effects_PathNode_t*) t0)->f_step;
            if (VADER_LIKELY(_pc4_len < _pc4_cap)) {
                ((int32_t*) _pc4_slots)[_pc4_len] = (int32_t) (l4);
                _pc4_len += 1;
            } else {
                _pc4_hdr->length = _pc4_len;
                if (_pc4_hdr->buf->length < _pc4_len) {
                    _pc4_hdr->buf->length = _pc4_len;
                }
                vader_array_push_i32((vader_array_t*) l2, l4);
                _pc4_hdr = (vader_array_t*) l2;
                _pc4_len = _pc4_hdr->length;
                _pc4_cap = (_pc4_hdr->offset == 0 && !vader_array_is_borrowed(_pc4_hdr) && _pc4_hdr->length >= _pc4_hdr->buf->length) ? _pc4_hdr->capacity : (size_t) 0;
                _pc4_slots = _pc4_hdr->buf->slots;
            }
            vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_effects_PathTable_t*) l0)->f_nodes);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l3)
            t0 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l3);
            l3 = ((vader_struct_vader_effects_PathNode_t*) t0)->f_parent;
            continue;
        }
        _pc4_hdr->length = _pc4_len;
        if (_pc4_hdr->buf->length < _pc4_len) {
            _pc4_hdr->buf->length = _pc4_len;
        }
        break;
    }
    vader_array_t* _a4_arr = vader_array_new(16u, 0u, 7u, 285u);
    l5 = (void*) _a4_arr;
    l6 = ((vader_array_t*) l2)->length;
    vader_array_t* _a5_arr = vader_array_repeat((vader_array_t*) l5, (size_t) l6);
    l5 = (void*) _a5_arr;
    l6 = (size_t) 0;
    l7 = ((vader_array_t*) l2)->length;
    vader_array_t* _pc45_hdr = (vader_array_t*) l5;
    size_t _pc45_len = _pc45_hdr->length;
    size_t _pc45_cap = (_pc45_hdr->offset == 0 && !vader_array_is_borrowed(_pc45_hdr) && _pc45_hdr->length >= _pc45_hdr->buf->length) ? _pc45_hdr->capacity : (size_t) 0;
    void* _pc45_slots = _pc45_hdr->buf->slots;
    for (;;) {
        if ((l6 < l7)) {
            t2 = ((vader_array_t*) l2)->length;
            t3 = vader_chk_sub(usize, t2, INT64_C(1));
            t4 = vader_chk_sub(usize, t3, l6);
            l8 = (size_t) (int64_t) t4;
            vader_array_t* _a6_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l8)
            l3 = ((int32_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l8];
            if (VADER_LIKELY(_pc45_len < _pc45_cap)) {
                ((int32_t*) _pc45_slots)[_pc45_len] = (int32_t) (l3);
                _pc45_len += 1;
            } else {
                _pc45_hdr->length = _pc45_len;
                if (_pc45_hdr->buf->length < _pc45_len) {
                    _pc45_hdr->buf->length = _pc45_len;
                }
                vader_array_push_i32((vader_array_t*) l5, l3);
                _pc45_hdr = (vader_array_t*) l5;
                _pc45_len = _pc45_hdr->length;
                _pc45_cap = (_pc45_hdr->offset == 0 && !vader_array_is_borrowed(_pc45_hdr) && _pc45_hdr->length >= _pc45_hdr->buf->length) ? _pc45_hdr->capacity : (size_t) 0;
                _pc45_slots = _pc45_hdr->buf->slots;
            }
            t3 = (l6 + INT64_C(1));
            l6 = (size_t) (int64_t) t3;
            continue;
        }
        _pc45_hdr->length = _pc45_len;
        if (_pc45_hdr->buf->length < _pc45_len) {
            _pc45_hdr->buf->length = _pc45_len;
        }
        break;
    }
    { void* __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_effects_steps_through_elements(void* l0, vader_box_t l1) {
    size_t l2;
    vader_box_t l3;
    void* t0;
    t0 = l1.payload.obj;
    l2 = ((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t0)->f_id;
    l3 = vader_effects_site_callee(l0, (uint8_t) 6, l2);
    if (l3.tag == 0u) {
        return true;
    }
    return l3.tag == 1130u;
}

static void vader_effects_stmt(void* l0, vader_box_t l1) {
    vader_box_t l2 = vader_box_null(), l3 = vader_box_null();
    void* l4 = NULL;
    void* t0 = NULL;
    vader_box_t* gc_roots[3] = { &l1, &l2, &l3 };
    void** gc_raw_roots[3] = { &l0, &l4, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l1.tag == 548u) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_toolchain_ast_LetStmt_t*) t0)->f_binding;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_toolchain_ast_LetStmt_t*) t0)->f_value;
        l3 = vader_effects_value(l0, l3);
        vader_effects_bind(l0, l2, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 502u) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_toolchain_ast_AssignStmt_t*) t0)->f_target;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_toolchain_ast_AssignStmt_t*) t0)->f_value;
        l3 = vader_effects_value(l0, l3);
        vader_effects_assign(l0, l2, l3);
    } else if (l1.tag == 518u) {
        l4 = l1.payload.obj;
        vader_effects_destructure_assign(l0, l4);
    } else if (l1.tag == 526u) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_toolchain_ast_ExprStmt_t*) t0)->f_expr;
        vader_effects_discard(l0, l2);
    } else if (l1.tag == 567u) {
        l4 = l1.payload.obj;
        vader_effects_return_stmt(l0, l4);
    } else if (l1.tag == 590u) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_toolchain_ast_YieldStmt_t*) t0)->f_value;
        l2 = vader_effects_value(l0, l2);
        vader_effects_escape(l0, l2, (uint8_t) 3);
    } else if (l1.tag == 532u) {
        l4 = l1.payload.obj;
        vader_effects_for_stmt(l0, l4);
    } else if (!((l1.tag == 507u || l1.tag == 513u))) {
        if (!(l1.tag == 516u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l4 = l1.payload.obj;
        vader_effects_defer_stmt(l0, l4);
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_effects_string_value(void* l0, void* l1) {
    void* l2 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    size_t l3, l4, l6;
    vader_box_t l5 = vader_box_null(), l7 = vader_box_null(), l8 = vader_box_null();
    void* t0 = NULL;
    void* t1 = NULL;
    vader_box_t t2 = vader_box_null();
    int64_t t3;
    vader_box_t* gc_roots[4] = { &l5, &l7, &l8, &t2 };
    void** gc_raw_roots[7] = { &l0, &l1, &l2, &l9, &l10, &t0, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 7u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_toolchain_ast_StringLitExpr_t*) l1)->f_parts;
    l3 = ((vader_array_t*) l2)->length;
    l4 = (size_t) 0;
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l5 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        if (l5.tag == 571u) {
            t0 = l5.payload.obj;
            t1 = ((vader_struct_toolchain_ast_StringLitInterp_t*) t0)->f_expr.payload.obj;
            l6 = ((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t1)->f_id;
            l7 = vader_effects_site_callee(l0, (uint8_t) 7, l6);
            t0 = l5.payload.obj;
            l8 = ((vader_struct_toolchain_ast_StringLitInterp_t*) t0)->f_expr;
            t2 = vader_effects_value(l0, l8);
            vader_array_t* _a1_arr = vader_array_new(206u, 1u, 0u, 1286u);
            vader_array_box_slots(_a1_arr->buf)[_a1_arr->offset + 0u] = t2;
            l9 = (void*) _a1_arr;
            t0 = l5.payload.obj;
            vader_array_t* _a2_arr = vader_array_new(209u, 1u, 13u, 1373u);
            ((void**) _a2_arr->buf->slots)[_a2_arr->offset + 0u] = ((vader_struct_toolchain_ast_StringLitInterp_t*) t0)->f_expr.payload.obj;
            l10 = (void*) _a2_arr;
            vader_effects_call(l0, l7, l9, l10);
        }
        t3 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t3;
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static vader_box_t vader_effects_struct_fields_of(void* l0, vader_box_t l1) {
    vader_box_t l2;
    void* l3;
    size_t l4;
    int32_t l5;
    void* t0;
    vader_box_t t1;
    l3 = ((vader_struct_vader_typecheck_TypedProgram_t*) ((vader_struct_vader_effects_WalkCtx_t*) l0)->f_typed)->f_expr_types;
    t0 = l1.payload.obj;
    l4 = ((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t0)->f_id;
    l2 = std_collections_MutableMap_Index_at__usize__Any(l3, l4);
    if (l2.tag == 0u) {
        return vader_box_obj(0u, NULL);
    }
    if (!(l2.tag == 1199u)) {
        return vader_box_obj(0u, NULL);
    }
    l3 = ((vader_struct_vader_typecheck_TypedProgram_t*) ((vader_struct_vader_effects_WalkCtx_t*) l0)->f_typed)->f_struct_field_types;
    t0 = l2.payload.obj;
    l5 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_types_StructType_t*) t0)->f_symbol)->f_id;
    t1 = std_collections_MutableMap_Index_at__i32__MutableMap_string__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_(l3, l5);
    return t1;
}

static vader_string_t vader_effects_struct_key(void* l0) {
    void* l1 = NULL;
    size_t l2;
    int64_t l3;
    int32_t t0;
    vader_string_t t1 = 0;
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = std_core_new_byte_buffer((size_t) 21);
    l2 = (size_t) 0;
    l2 = std_core_write_string_at(l1, l2, 2257u);
    t0 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_types_StructType_t*) l0)->f_symbol)->f_id;
    l3 = ((int64_t) (int32_t) t0);
    l2 = std_core_write_int(l1, l2, l3);
    t1 = std_core_finish_buffer(l1, l2);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_effects_struct_literal_value(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    size_t l5, l6;
    vader_box_t l7 = vader_box_null(), l9 = vader_box_null(), l10 = vader_box_null();
    vader_string_t l8 = 0;
    void* t0 = NULL;
    int64_t t1;
    vader_box_t* gc_roots[3] = { &l7, &l9, &l10 };
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l3, &l4, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l8 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(15u, 0u, 0u, 282u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(13u, 0u, 12u, 280u);
    l3 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(16u, 0u, 7u, 285u);
    l4 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__string__bool_t* _a3_obj = (vader_struct_std_collections_MutableMap__string__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__bool_t));
    vader_obj_header_init(_a3_obj, 437u);
    _a3_obj->f_ekeys = l2;
    _a3_obj->f_evals = l3;
    _a3_obj->f_index = l4;
    _a3_obj->f_mask = (size_t) 0;
    _a3_obj->f_size = (size_t) 0;
    _a3_obj->f_tombs = (size_t) 0;
    t0 = (void*) _a3_obj;
    vader_struct_std_collections_MutableSet__string_t* _a4_obj = (vader_struct_std_collections_MutableSet__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__string_t));
    vader_obj_header_init(_a4_obj, 487u);
    _a4_obj->f_inner = t0;
    l2 = (void*) _a4_obj;
    l3 = ((vader_struct_toolchain_ast_StructLitExpr_t*) l1)->f_items;
    l5 = ((vader_array_t*) l3)->length;
    l6 = (size_t) 0;
    while ((l6 < l5)) {
        vader_array_t* _a5_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        l7 = vader_array_ref_load_box(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l6);
        if (l7.tag == 576u) {
            t0 = l7.payload.obj;
            l8 = ((vader_struct_toolchain_ast_StructLitField_t*) t0)->f_name;
            std_collections_add__string(l2, l8);
            t0 = l7.payload.obj;
            l9 = ((vader_struct_toolchain_ast_StructLitField_t*) t0)->f_value;
            l10 = vader_effects_value(l0, l9);
            vader_effects_escape(l0, l10, (uint8_t) 3);
        }
        t1 = (l6 + INT64_C(1));
        l6 = (size_t) (int64_t) t1;
    }
    l3 = ((vader_struct_toolchain_ast_StructLitExpr_t*) l1)->f_items;
    l5 = ((vader_array_t*) l3)->length;
    l6 = (size_t) 0;
    while ((l6 < l5)) {
        vader_array_t* _a6_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        l7 = vader_array_ref_load_box(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l6);
        if (l7.tag == 577u) {
            t0 = l7.payload.obj;
            l9 = ((vader_struct_toolchain_ast_StructLitSpread_t*) t0)->f_expr;
            vader_effects_spread(l0, l9, l2);
        }
        t1 = (l6 + INT64_C(1));
        l6 = (size_t) (int64_t) t1;
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

void* vader_effects_summarise_effects(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l12 = NULL;
    void* l14 = NULL;
    void* l16 = NULL;
    void* l17 = NULL;
    void* l18 = NULL;
    size_t l10, l11, l15, l19;
    int32_t l13;
    void* t0 = NULL;
    int64_t t1;
    void** gc_raw_roots[16] = {
        &l0, &l1, &l2, &l3, &l4, &l5, &l6, &l7, &l8, &l9, &l12, &l14, &l16, &l17, &l18, &t0,
    };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 16u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_typecheck_CheckResult_t*) l1)->f_all_modules;
    l2 = vader_effects_index_functions(l0, l2);
    vader_array_t* _a0_arr = vader_array_new(88u, 0u, 13u, 880u);
    l3 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(86u, 0u, 13u, 878u);
    l4 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(15u, 0u, 0u, 282u);
    l5 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(13u, 0u, 12u, 280u);
    l6 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_new(16u, 0u, 7u, 285u);
    l7 = (void*) _a4_arr;
    vader_struct_std_collections_MutableMap__string__bool_t* _a5_obj = (vader_struct_std_collections_MutableMap__string__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__bool_t));
    vader_obj_header_init(_a5_obj, 437u);
    _a5_obj->f_ekeys = l5;
    _a5_obj->f_evals = l6;
    _a5_obj->f_index = l7;
    _a5_obj->f_mask = (size_t) 0;
    _a5_obj->f_size = (size_t) 0;
    _a5_obj->f_tombs = (size_t) 0;
    t0 = (void*) _a5_obj;
    vader_struct_std_collections_MutableSet__string_t* _a6_obj = (vader_struct_std_collections_MutableSet__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__string_t));
    vader_obj_header_init(_a6_obj, 487u);
    _a6_obj->f_inner = t0;
    l5 = (void*) _a6_obj;
    vader_array_t* _a7_arr = vader_array_new(22u, 0u, 4u, 292u);
    l6 = (void*) _a7_arr;
    vader_array_t* _a8_arr = vader_array_new(13u, 0u, 12u, 280u);
    l7 = (void*) _a8_arr;
    vader_array_t* _a9_arr = vader_array_new(16u, 0u, 7u, 285u);
    l8 = (void*) _a9_arr;
    vader_struct_std_collections_MutableMap__usize__bool_t* _a10_obj = (vader_struct_std_collections_MutableMap__usize__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__usize__bool_t));
    vader_obj_header_init(_a10_obj, 480u);
    _a10_obj->f_ekeys = l6;
    _a10_obj->f_evals = l7;
    _a10_obj->f_index = l8;
    _a10_obj->f_mask = (size_t) 0;
    _a10_obj->f_size = (size_t) 0;
    _a10_obj->f_tombs = (size_t) 0;
    t0 = (void*) _a10_obj;
    vader_struct_std_collections_MutableSet__usize_t* _a11_obj = (vader_struct_std_collections_MutableSet__usize_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__usize_t));
    vader_obj_header_init(_a11_obj, 489u);
    _a11_obj->f_inner = t0;
    l6 = (void*) _a11_obj;
    vader_array_t* _a12_arr = vader_array_new(16u, 0u, 7u, 285u);
    l7 = (void*) _a12_arr;
    vader_array_t* _a13_arr = vader_array_new(13u, 0u, 12u, 280u);
    l8 = (void*) _a13_arr;
    vader_array_t* _a14_arr = vader_array_new(16u, 0u, 7u, 285u);
    l9 = (void*) _a14_arr;
    vader_struct_std_collections_MutableMap__i32__bool_t* _a15_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
    vader_obj_header_init(_a15_obj, 379u);
    _a15_obj->f_ekeys = l7;
    _a15_obj->f_evals = l8;
    _a15_obj->f_index = l9;
    _a15_obj->f_mask = (size_t) 0;
    _a15_obj->f_size = (size_t) 0;
    _a15_obj->f_tombs = (size_t) 0;
    t0 = (void*) _a15_obj;
    vader_struct_std_collections_MutableSet__i32_t* _a16_obj = (vader_struct_std_collections_MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i32_t));
    vader_obj_header_init(_a16_obj, 485u);
    _a16_obj->f_inner = t0;
    l7 = (void*) _a16_obj;
    vader_struct_vader_typecheck_FreshReads_t* _a17_obj = (vader_struct_vader_typecheck_FreshReads_t*) vader_gc_alloc(sizeof(vader_struct_vader_typecheck_FreshReads_t));
    vader_obj_header_init(_a17_obj, 1149u);
    _a17_obj->f_uses = l6;
    _a17_obj->f_constants = l7;
    l6 = (void*) _a17_obj;
    vader_array_t* _a18_arr = vader_array_new(16u, 0u, 7u, 285u);
    l7 = (void*) _a18_arr;
    vader_array_t* _a19_arr = vader_array_new(23u, 0u, 0u, 293u);
    l8 = (void*) _a19_arr;
    vader_array_t* _a20_arr = vader_array_new(16u, 0u, 7u, 285u);
    l9 = (void*) _a20_arr;
    vader_struct_std_collections_MutableMap__i32__Any___t* _a21_obj = (vader_struct_std_collections_MutableMap__i32__Any___t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__Any___t));
    vader_obj_header_init(_a21_obj, 348u);
    _a21_obj->f_ekeys = l7;
    _a21_obj->f_evals = l8;
    _a21_obj->f_index = l9;
    _a21_obj->f_mask = (size_t) 0;
    _a21_obj->f_size = (size_t) 0;
    _a21_obj->f_tombs = (size_t) 0;
    l7 = (void*) _a21_obj;
    vader_struct_vader_effects_FrozenSites_t* _a22_obj = (vader_struct_vader_effects_FrozenSites_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_FrozenSites_t));
    vader_obj_header_init(_a22_obj, 881u);
    _a22_obj->f_sites = l3;
    _a22_obj->f_bodies = l4;
    _a22_obj->f_written = l5;
    _a22_obj->f_fresh = l6;
    _a22_obj->f_kept_by_constants = l7;
    l3 = (void*) _a22_obj;
    vader_array_t* _a23_arr = vader_array_new(94u, 0u, 13u, 889u);
    l4 = (void*) _a23_arr;
    vader_array_t* _a24_arr = vader_array_new(97u, 0u, 13u, 894u);
    l5 = (void*) _a24_arr;
    l10 = ((vader_array_t*) ((vader_struct_vader_effects_CalleeIndex_t*) l2)->f_functions)->length;
    vader_array_t* _a25_arr = vader_array_repeat((vader_array_t*) l5, (size_t) l10);
    l5 = (void*) _a25_arr;
    vader_array_t* _a26_arr = vader_array_new(5u, 0u, 13u, 92u);
    l6 = (void*) _a26_arr;
    l10 = ((vader_array_t*) ((vader_struct_vader_effects_CalleeIndex_t*) l2)->f_functions)->length;
    vader_array_t* _a27_arr = vader_array_repeat((vader_array_t*) l6, (size_t) l10);
    l6 = (void*) _a27_arr;
    vader_array_t* _a28_arr = vader_array_new(2u, 0u, 13u, 16u);
    l7 = (void*) _a28_arr;
    l10 = ((vader_array_t*) ((vader_struct_vader_effects_CalleeIndex_t*) l2)->f_functions)->length;
    vader_array_t* _a29_arr = vader_array_repeat((vader_array_t*) l7, (size_t) l10);
    l7 = (void*) _a29_arr;
    l10 = (size_t) 0;
    l11 = ((vader_array_t*) ((vader_struct_vader_effects_CalleeIndex_t*) l2)->f_functions)->length;
    while ((l10 < l11)) {
        vader_array_t* _a30_slotarr = ((vader_array_t*) ((vader_struct_vader_effects_CalleeIndex_t*) l2)->f_functions);
        VADER_ARRAY_RESOLVE_BUF(_a30_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a30_slotarr, l10)
        l8 = vader_array_ref_load_obj(_a30_slotarr->buf, _a30_slotarr->offset + (size_t) l10);
        l9 = ((vader_struct_vader_effects_Function_t*) l8)->f_decl;
        l12 = ((vader_struct_vader_effects_Function_t*) l8)->f_typed;
        l13 = ((int32_t) (size_t) l10);
        l14 = vader_effects_skeleton_of(l9, l12, l2, l3, l4, l13);
        vader_array_push((vader_array_t*) l5, vader_ref_box(l14));
        l15 = ((vader_struct_vader_effects_Skeleton_t*) l14)->f_params;
        l16 = (void*) &vader_fn_static___lambda_vader_effects_0;
        l17 = std_core_filled__ParamEffects(l15, l16);
        vader_array_push((vader_array_t*) l6, vader_ref_box(l17));
        l18 = vader_effects_callee_nodes(l14);
        vader_array_push((vader_array_t*) l7, vader_ref_box(l18));
        t1 = (l10 + INT64_C(1));
        l10 = (size_t) (int64_t) t1;
    }
    vader_struct_vader_fixpoint_Graph_t* _a31_obj = (vader_struct_vader_fixpoint_Graph_t*) vader_gc_alloc(sizeof(vader_struct_vader_fixpoint_Graph_t));
    vader_obj_header_init(_a31_obj, 898u);
    _a31_obj->f_successors = l7;
    l8 = (void*) _a31_obj;
    l9 = vader_effects_component_of_each_node(l8);
    l10 = ((vader_array_t*) l7)->length;
    l12 = (void*) &vader_fn_static___lambda_vader_effects_1;
    l12 = std_core_filled__i64(l10, l12);
    l10 = ((vader_array_t*) l7)->length;
    l14 = (void*) &vader_fn_static___lambda_vader_effects_2;
    l14 = std_core_filled__i64(l10, l14);
    vader_struct_vader_effects_Clock_t* _a32_obj = (vader_struct_vader_effects_Clock_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_Clock_t));
    vader_obj_header_init(_a32_obj, 873u);
    _a32_obj->f_now = INT64_C(0);
    _a32_obj->f_grew_at = l12;
    _a32_obj->f_evaluated_at = l14;
    t0 = (void*) _a32_obj;
    vader_struct___lambda_env_vader_effects_4_t* _a33_obj = (vader_struct___lambda_env_vader_effects_4_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_effects_4_t));
    vader_obj_header_init(_a33_obj, 311u);
    _a33_obj->f_cap_0 = t0;
    _a33_obj->f_cap_1 = l7;
    _a33_obj->f_cap_2 = l6;
    _a33_obj->f_cap_3 = l2;
    _a33_obj->f_cap_4 = l9;
    _a33_obj->f_cap_5 = l5;
    t0 = (void*) _a33_obj;
    vader_fn_t* _a34_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
    vader_obj_header_init(_a34_closure, 254u);
    _a34_closure->code = (void*) &vader_fn_lift___lambda_vader_effects_3;
    _a34_closure->env = t0;
    l5 = (void*) _a34_closure;
    l5 = vader_fixpoint_solve_bottom_up(l8, l5, INT32_C(64));
    l7 = l5;
    l10 = ((vader_array_t*) l7)->length;
    l11 = (size_t) 0;
    while ((l11 < l10)) {
        vader_array_t* _a35_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a35_slotarr)
        l13 = ((int32_t*) _a35_slotarr->buf->slots)[_a35_slotarr->offset + (size_t) l11];
        l15 = (size_t) 0;
        vader_array_t* _a36_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a36_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a36_slotarr, l13)
        t0 = vader_array_ref_load_obj(_a36_slotarr->buf, _a36_slotarr->offset + (size_t) l13);
        l19 = ((vader_array_t*) t0)->length;
        while ((l15 < l19)) {
            vader_array_t* _a37_slotarr = ((vader_array_t*) l6);
            VADER_ARRAY_RESOLVE_BUF(_a37_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a37_slotarr, l13)
            l8 = vader_array_ref_load_obj(_a37_slotarr->buf, _a37_slotarr->offset + (size_t) l13);
            l12 = vader_effects_any_effects();
            vader_array_t* _a38_slotarr = ((vader_array_t*) l8);
            VADER_ARRAY_RESOLVE_BUF(_a38_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a38_slotarr, l15)
            vader_array_ref_store(_a38_slotarr->buf, _a38_slotarr->offset + (size_t) l15, l12);
            VADER_WRITE_BARRIER(_a38_slotarr->buf);
            t1 = (l15 + INT64_C(1));
            l15 = (size_t) (int64_t) t1;
        }
        t1 = (l11 + INT64_C(1));
        l11 = (size_t) (int64_t) t1;
    }
    vader_effects_note_initialisers(l2, l3, l4);
    l7 = ((vader_struct_vader_effects_CalleeIndex_t*) l2)->f_paths;
    vader_effects_settle_frozen(l3, l6, l7, l9);
    l7 = ((vader_struct_vader_effects_FrozenSites_t*) l3)->f_sites;
    l3 = ((vader_struct_vader_effects_FrozenSites_t*) l3)->f_fresh;
    l8 = ((vader_struct_vader_effects_CalleeIndex_t*) l2)->f_paths;
    l4 = vader_effects_settle_widenings(l4, l6, l8);
    vader_struct_vader_effects_EffectSummary_t* _a39_obj = (vader_struct_vader_effects_EffectSummary_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_EffectSummary_t));
    vader_obj_header_init(_a39_obj, 875u);
    _a39_obj->f_index = l2;
    _a39_obj->f_facts = l6;
    _a39_obj->f_unsettled = l5;
    _a39_obj->f_frozen = l7;
    _a39_obj->f_fresh = l3;
    _a39_obj->f_widenings = l4;
    t0 = (void*) _a39_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_effects_target_of_decl(void* l0, void* l1) {
    void* l2 = NULL;
    size_t l3;
    vader_box_t l4 = vader_box_null();
    int32_t t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &l4 };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_effects_CalleeIndex_t*) l0)->f_nodes;
    l3 = ((vader_struct_toolchain_ast_FnDecl_t*) l1)->f_id;
    l4 = std_collections_MutableMap_Index_at__usize__i32(l2, l3);
    if (!(l4.tag == 0u)) {
        t0 = ((int32_t) l4.payload.i);
        vader_struct_vader_effects_CalleeNode_t* _a0_obj = (vader_struct_vader_effects_CalleeNode_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_CalleeNode_t));
        vader_obj_header_init(_a0_obj, 872u);
        _a0_obj->f_node = t0;
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = ((vader_struct_vader_effects_CalleeIndex_t*) l0)->f_bodyless;
    l3 = ((vader_struct_toolchain_ast_FnDecl_t*) l1)->f_id;
    l4 = std_collections_MutableMap_Index_at__usize__Any(l2, l3);
    if (l4.tag == 0u) {
        vader_struct_vader_effects_AnyCallee_t* _a1_obj = (vader_struct_vader_effects_AnyCallee_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_AnyCallee_t));
        vader_obj_header_init(_a1_obj, 870u);
        t1 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_box_t __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_effects_targets_of(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    void* l5 = NULL;
    vader_string_t l3 = 0;
    vader_string_t l4 = 0;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[4] = { &l0, &l2, &l5, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l3, &l4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l1.tag == 1138u) {
        l2 = l1.payload.obj;
        l2 = vader_effects_direct_targets(l0, l2);
        { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 1128u) {
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_typecheck_BoundMember_t*) t0)->f_trait_key;
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_typecheck_BoundMember_t*) t0)->f_member;
        l2 = vader_effects_member_targets(l0, l3, l4);
    } else if (l1.tag == 1175u) {
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_typecheck_TraitMember_t*) t0)->f_trait_key;
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_typecheck_TraitMember_t*) t0)->f_member;
        l2 = vader_effects_member_targets(l0, l3, l4);
    } else if (l1.tag == 1139u) {
        t0 = l1.payload.obj;
        l5 = ((vader_struct_vader_typecheck_EachOf_t*) t0)->f_callees;
        l2 = vader_effects_each_targets(l0, l5);
    } else if (l1.tag == 1130u) {
        vader_array_t* _a0_arr = vader_array_new(231u, 0u, 13u, 1559u);
        l2 = (void*) _a0_arr;
    } else {
        if (!((l1.tag == 1142u || l1.tag == 1147u || l1.tag == 1183u))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        vader_struct_vader_effects_AnyCallee_t* _a1_obj = (vader_struct_vader_effects_AnyCallee_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_AnyCallee_t));
        vader_obj_header_init(_a1_obj, 870u);
        t0 = (void*) _a1_obj;
        vader_array_t* _a2_arr = vader_array_new(231u, 1u, 13u, 1559u);
        ((void**) _a2_arr->buf->slots)[_a2_arr->offset + 0u] = t0;
        l2 = (void*) _a2_arr;
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_effects_type_below(void* l0, void* l1, vader_box_t l2, int32_t l3) {
    vader_box_t l4 = vader_box_null(), l10 = vader_box_null();
    void* l5 = NULL;
    size_t l6, l7;
    int32_t l8;
    vader_string_t l9 = 0;
    vader_box_t t0 = vader_box_null();
    int64_t t1;
    vader_box_t* gc_roots[4] = { &l2, &l4, &l10, &t0 };
    void** gc_raw_roots[3] = { &l0, &l1, &l5 };
    vader_string_t* gc_atom_roots[1] = { &l9 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = l2;
    l5 = vader_effects_steps_of(l0, l3);
    l6 = ((vader_array_t*) l5)->length;
    l7 = (size_t) 0;
    while ((l7 < l6)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l7)
        l8 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l7];
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_effects_PathTable_t*) l0)->f_step_names);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l8)
        t0 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l8];
        l9 = t0.payload.s;
        l10 = vader_effects_step_type(l1, l4, l9);
        if (l10.tag == 0u) {
            { vader_box_t __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l4 = l10;
        t1 = (l7 + INT64_C(1));
        l7 = (size_t) (int64_t) t1;
    }
    { vader_box_t __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_effects_union_of(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    size_t l4, l5, l7, l8;
    vader_box_t l6 = vader_box_null();
    int64_t t0;
    size_t t1;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l6, &t2 };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = l1;
    vader_array_t* _a0_arr = vader_array_new(22u, 0u, 4u, 292u);
    l3 = (void*) _a0_arr;
    l4 = ((vader_array_t*) l2)->length;
    l5 = (size_t) 0;
    vader_array_t* _pc9_hdr = (vader_array_t*) l3;
    size_t _pc9_len = _pc9_hdr->length;
    size_t _pc9_cap = (_pc9_hdr->offset == 0 && !vader_array_is_borrowed(_pc9_hdr) && _pc9_hdr->length >= _pc9_hdr->buf->length) ? _pc9_hdr->capacity : (size_t) 0;
    void* _pc9_slots = _pc9_hdr->buf->slots;
    for (;;) {
        if ((l5 < l4)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            l6 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l5];
            if (!(l6.tag == 0u)) {
                l7 = ((size_t) l6.payload.i);
                if (VADER_LIKELY(_pc9_len < _pc9_cap)) {
                    ((int64_t*) _pc9_slots)[_pc9_len] = (int64_t) ((int64_t) (size_t) l7);
                    _pc9_len += 1;
                } else {
                    _pc9_hdr->length = _pc9_len;
                    if (_pc9_hdr->buf->length < _pc9_len) {
                        _pc9_hdr->buf->length = _pc9_len;
                    }
                    vader_array_push_i64((vader_array_t*) l3, (int64_t) (size_t) l7);
                    _pc9_hdr = (vader_array_t*) l3;
                    _pc9_len = _pc9_hdr->length;
                    _pc9_cap = (_pc9_hdr->offset == 0 && !vader_array_is_borrowed(_pc9_hdr) && _pc9_hdr->length >= _pc9_hdr->buf->length) ? _pc9_hdr->capacity : (size_t) 0;
                    _pc9_slots = _pc9_hdr->buf->slots;
                }
            }
            t0 = (l5 + INT64_C(1));
            l5 = (size_t) (int64_t) t0;
            continue;
        }
        _pc9_hdr->length = _pc9_len;
        if (_pc9_hdr->buf->length < _pc9_len) {
            _pc9_hdr->buf->length = _pc9_len;
        }
        break;
    }
    l2 = l3;
    t1 = ((vader_array_t*) l2)->length;
    if (t1 == INT64_C(0)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    t1 = ((vader_array_t*) l2)->length;
    if (t1 == INT64_C(1)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        t0 = ((int64_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) INT32_C(0)];
        t2 = vader_box_i64(292u, t0);
        { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = vader_effects_fresh_slot(((vader_struct_vader_effects_WalkCtx_t*) l0)->f_s);
    l5 = ((vader_array_t*) l2)->length;
    l7 = (size_t) 0;
    while ((l7 < l5)) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        t0 = ((int64_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l7];
        l8 = (size_t) (int64_t) t0;
        vader_effects_add_flow(((vader_struct_vader_effects_WalkCtx_t*) l0)->f_s, l4, l8, INT32_C(0));
        t0 = (l7 + INT64_C(1));
        l7 = (size_t) (int64_t) t0;
    }
    t2 = vader_box_i64(292u, (int64_t)(uint64_t) l4);
    { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_effects_use_outcome(void* l0, void* l1) {
    void* l2 = NULL;
    bool l3;
    size_t l4, l5;
    void* t0 = NULL;
    bool t1;
    int64_t t2;
    uint8_t t3;
    vader_box_t t4 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t4 };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_effects_RootCase_t*) l1)->f_marked;
    l3 = false;
    l4 = ((vader_array_t*) l2)->length;
    l5 = (size_t) 0;
    {
        while ((l5 < l4)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
            t1 = vader_effects_modifies(t0);
            if (t1) {
                l3 = true;
                goto end_9;
            }
            t2 = (l5 + INT64_C(1));
            l5 = (size_t) (int64_t) t2;
        }
        l3 = false;
    } end_9: ;
    if (l3) {
        { vader_box_t __vret = vader_box_i32(288u, INT32_C(0)); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = ((vader_struct_vader_effects_RootCase_t*) l1)->f_lent;
    l3 = false;
    l4 = ((vader_array_t*) l2)->length;
    l5 = (size_t) 0;
    {
        while ((l5 < l4)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5);
            t1 = vader_effects_modifies(t0);
            if (t1) {
                l3 = true;
                goto end_49;
            }
            t2 = (l5 + INT64_C(1));
            l5 = (size_t) (int64_t) t2;
        }
        l3 = false;
    } end_49: ;
    if (l3) {
        { vader_box_t __vret = vader_box_i32(288u, INT32_C(1)); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = (void*) &vader_fn_static_vader_effects_is_unknown;
    t1 = vader_effects_either(l1, l2);
    if (t1) {
        { vader_box_t __vret = vader_box_i32(288u, INT32_C(2)); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (((vader_struct_vader_effects_FrozenBody_t*) ((vader_struct_vader_effects_RootCase_t*) l1)->f_body)->f_initialises.tag == 0u) {
        l2 = (void*) &vader_fn_static_vader_effects_is_kept;
        t1 = vader_effects_either(l1, l2);
        if (t1) {
            l2 = (void*) &vader_fn_static_vader_effects_is_kept;
            t3 = vader_effects_copy_or_elided(l0, l1, l2);
            t4 = vader_box_i32(288u, (int32_t)(uint32_t) t3);
            { vader_box_t __vret = t4; vader_gc_top = gc_frame.prev; return __vret; }
        }
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static vader_box_t vader_effects_value(void* l0, vader_box_t l1) {
    vader_box_t l2 = vader_box_null();
    void* l3 = NULL;
    size_t l4;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    bool t2;
    vader_box_t* gc_roots[3] = { &l1, &l2, &t1 };
    void** gc_raw_roots[3] = { &l0, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = vader_effects_value_of(l0, l1);
    l2 = vader_effects_converted(l0, l1, l2);
    l3 = ((vader_struct_vader_typecheck_TypedProgram_t*) ((vader_struct_vader_effects_WalkCtx_t*) l0)->f_typed)->f_expr_types;
    t0 = l1.payload.obj;
    l4 = ((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t0)->f_id;
    t1 = std_collections_MutableMap_Index_at__usize__Any(l3, l4);
    t2 = vader_effects_holds_references(t1);
    if (!(t2)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_effects_value_of(void* l0, vader_box_t l1) {
    vader_box_t l2 = vader_box_null(), l4 = vader_box_null(), l5 = vader_box_null();
    void* l3 = NULL;
    void* t0 = NULL;
    vader_box_t* gc_roots[4] = { &l1, &l2, &l4, &l5 };
    void** gc_raw_roots[3] = { &l0, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l1.tag == 534u) {
        l3 = l1.payload.obj;
        l2 = vader_effects_ident_value(l0, l3);
        { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 527u) {
        l3 = l1.payload.obj;
        l2 = vader_effects_field_value(l0, l3);
    } else if (l1.tag == 542u) {
        l3 = l1.payload.obj;
        l2 = vader_effects_index_value(l0, l3);
    } else if (l1.tag == 509u) {
        l3 = l1.payload.obj;
        l2 = vader_effects_call_value(l0, l3);
    } else if (l1.tag == 504u) {
        l3 = l1.payload.obj;
        l2 = vader_effects_binary_value(l0, l3);
    } else if (l1.tag == 584u) {
        t0 = l1.payload.obj;
        l4 = ((vader_struct_toolchain_ast_UnaryExpr_t*) t0)->f_operand;
        l2 = vader_effects_nothing(l0, l4);
    } else if (l1.tag == 556u) {
        t0 = l1.payload.obj;
        l4 = ((vader_struct_toolchain_ast_NullCoalesceExpr_t*) t0)->f_left;
        l4 = vader_effects_value(l0, l4);
        t0 = l1.payload.obj;
        l5 = ((vader_struct_toolchain_ast_NullCoalesceExpr_t*) t0)->f_fallback;
        l5 = vader_effects_fallback_value(l0, l5);
        vader_array_t* _a0_arr = vader_array_new(206u, 2u, 0u, 1286u);
        vader_array_box_slots(_a0_arr->buf)[_a0_arr->offset + 1u] = l5;
        vader_array_box_slots(_a0_arr->buf)[_a0_arr->offset + 0u] = l4;
        l3 = (void*) _a0_arr;
        l2 = vader_effects_union_of(l0, l3);
    } else if (l1.tag == 537u) {
        l3 = l1.payload.obj;
        l2 = vader_effects_if_value(l0, l3);
    } else if (l1.tag == 551u) {
        l3 = l1.payload.obj;
        l2 = vader_effects_match_value(l0, l3);
    } else if (l1.tag == 505u) {
        l3 = l1.payload.obj;
        l2 = vader_effects_block_value(l0, l3);
    } else if (l1.tag == 547u) {
        l3 = l1.payload.obj;
        l2 = vader_effects_lambda_value(l0, l3);
    } else if (l1.tag == 575u) {
        l3 = l1.payload.obj;
        l2 = vader_effects_struct_literal_value(l0, l3);
    } else if (l1.tag == 568u) {
        l3 = l1.payload.obj;
        l2 = vader_effects_sequence_value(l0, l3);
    } else if (l1.tag == 563u) {
        l3 = l1.payload.obj;
        l2 = vader_effects_range_value(l0, l3);
    } else if (l1.tag == 510u) {
        t0 = l1.payload.obj;
        l4 = ((vader_struct_toolchain_ast_CastExpr_t*) t0)->f_value;
        l2 = vader_effects_value(l0, l4);
    } else if (l1.tag == 570u) {
        l3 = l1.payload.obj;
        l2 = vader_effects_string_value(l0, l3);
    } else if (l1.tag == 545u) {
        t0 = l1.payload.obj;
        l3 = ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) t0)->f_args;
        l2 = vader_effects_sequence_walked(l0, l3);
    } else if (l1.tag == 503u) {
        t0 = l1.payload.obj;
        l4 = ((vader_struct_toolchain_ast_AwaitExpr_t*) t0)->f_inner;
        l2 = vader_effects_nothing(l0, l4);
    } else {
        if (!((l1.tag == 499u || l1.tag == 506u || l1.tag == 511u || l1.tag == 522u || l1.tag == 528u || l1.tag == 531u || l1.tag == 533u || l1.tag == 544u || l1.tag == 553u || l1.tag == 557u))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l2 = vader_box_obj(0u, NULL);
    }
    { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_effects_what_it_may_do(uint8_t l0, vader_string_t l1) {
    vader_string_t l2 = 0;
    vader_string_t* gc_atom_roots[2] = { &l1, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    if (l0 == INT32_C(0)) {
        l2 = concat_2(2054u, l1);
        { vader_string_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(1)) {
        l2 = concat_2(2055u, l1);
    } else if (l0 == INT32_C(3)) {
        l2 = concat_2(2057u, l1);
    } else if (l0 == INT32_C(4)) {
        l2 = concat_2(2058u, l1);
    } else if (l0 == INT32_C(5)) {
        l2 = concat_3(2056u, l1, 146u);
    } else {
        if (!(l0 == INT32_C(2))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l2 = concat_2(2059u, l1);
    }
    { vader_string_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_effects_widening_detail(void* l0, void* l1) {
    vader_string_t l2 = 0;
    vader_string_t l6 = 0;
    void* l3 = NULL;
    vader_box_t l4 = vader_box_null();
    int32_t l5;
    vader_string_t t0 = 0;
    vader_box_t* gc_roots[1] = { &l4 };
    void** gc_raw_roots[3] = { &l0, &l1, &l3 };
    vader_string_t* gc_atom_roots[3] = { &l2, &l6, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_effects_display_callee(((vader_struct_vader_effects_WideningSite_t*) l0)->f_callee);
    l4 = ((vader_struct_vader_effects_WideningSite_t*) l0)->f_breaking;
    if (l4.tag == 0u) {
        t0 = concat_2(l2, 106u);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = l4.payload.obj;
    l5 = ((vader_struct_vader_effects_Access_t*) l3)->f_path;
    l6 = vader_effects_argument_label(l0, l1, l5);
    l6 = vader_effects_what_it_may_do(((vader_struct_vader_effects_Access_t*) l3)->f_effect, l6);
    t0 = concat_3(l2, 10u, l6);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_effects_widening_diagnostics(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l9 = NULL;
    void* l11 = NULL;
    void* l12 = NULL;
    void* l16 = NULL;
    void* l17 = NULL;
    void* l18 = NULL;
    size_t l6, l7, l8, l13, l14, l15;
    vader_string_t l10 = 0;
    void* t0 = NULL;
    int64_t t1;
    bool t2;
    void** gc_raw_roots[13] = {
        &l0, &l1, &l2, &l3, &l4, &l5, &l9, &l11, &l12, &l16, &l17, &l18, &t0,
    };
    vader_string_t* gc_atom_roots[1] = { &l10 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 13u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(82u, 0u, 13u, 868u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(22u, 0u, 4u, 292u);
    l3 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(13u, 0u, 12u, 280u);
    l4 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(16u, 0u, 7u, 285u);
    l5 = (void*) _a3_arr;
    vader_struct_std_collections_MutableMap__usize__bool_t* _a4_obj = (vader_struct_std_collections_MutableMap__usize__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__usize__bool_t));
    vader_obj_header_init(_a4_obj, 480u);
    _a4_obj->f_ekeys = l3;
    _a4_obj->f_evals = l4;
    _a4_obj->f_index = l5;
    _a4_obj->f_mask = (size_t) 0;
    _a4_obj->f_size = (size_t) 0;
    _a4_obj->f_tombs = (size_t) 0;
    t0 = (void*) _a4_obj;
    vader_struct_std_collections_MutableSet__usize_t* _a5_obj = (vader_struct_std_collections_MutableSet__usize_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__usize_t));
    vader_obj_header_init(_a5_obj, 489u);
    _a5_obj->f_inner = t0;
    l3 = (void*) _a5_obj;
    l4 = ((vader_struct_vader_effects_EffectSummary_t*) l0)->f_widenings;
    l6 = ((vader_array_t*) l4)->length;
    l7 = (size_t) 0;
    while ((l7 < l6)) {
        vader_array_t* _a6_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        l5 = vader_array_ref_load_obj(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l7);
        l8 = ((vader_struct_vader_effects_WideningSite_t*) l5)->f_arg;
        std_collections_add__usize(l3, l8);
        if (((vader_struct_vader_effects_WideningSite_t*) l5)->f_verdict != INT32_C(0)) {
            l9 = ((vader_struct_vader_effects_CalleeIndex_t*) ((vader_struct_vader_effects_EffectSummary_t*) l0)->f_index)->f_paths;
            l10 = vader_effects_widening_detail(l5, l9);
            l11 = ((vader_struct_vader_effects_WideningSite_t*) l5)->f_span;
            l12 = vader_diagnostics_typecheck_error((uint8_t) 91, l11, l10);
            vader_array_push((vader_array_t*) l2, vader_ref_box(l12));
        }
        t1 = (l7 + INT64_C(1));
        l7 = (size_t) (int64_t) t1;
    }
    l4 = std_collections_values__string__TypedProgram(((vader_struct_vader_typecheck_CheckResult_t*) l1)->f_all_modules);
    l6 = ((vader_array_t*) l4)->length;
    l7 = (size_t) 0;
    while ((l7 < l6)) {
        vader_array_t* _a7_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
        t0 = vader_array_ref_load_obj(_a7_slotarr->buf, _a7_slotarr->offset + (size_t) l7);
        l5 = ((vader_struct_vader_typecheck_TypedProgram_t*) t0)->f_widened_arguments;
        l9 = ((vader_struct_std_collections_MutableMap__usize__WidenedArgument_t*) l5)->f_ekeys;
        l11 = ((vader_struct_std_collections_MutableMap__usize__WidenedArgument_t*) l5)->f_evals;
        l8 = ((vader_struct_std_collections_MutableMap__usize__WidenedArgument_t*) l5)->f_size;
        l13 = (size_t) 0;
        while (!((l13 >= l8))) {
            vader_array_t* _a8_slotarr = ((vader_array_t*) l9);
            VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l13)
            t1 = ((int64_t*) _a8_slotarr->buf->slots)[_a8_slotarr->offset + (size_t) l13];
            l14 = (size_t) (int64_t) t1;
            vader_array_t* _a9_slotarr = ((vader_array_t*) l11);
            VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l13)
            l12 = vader_array_ref_load_obj(_a9_slotarr->buf, _a9_slotarr->offset + (size_t) l13);
            l15 = l14;
            l16 = l12;
            t1 = (l13 + INT64_C(1));
            l13 = (size_t) (int64_t) t1;
            t2 = std_collections_MutableSet_Contains_contains__usize(l3, l15);
            if (t2) {
                continue;
            }
            l17 = ((vader_struct_vader_typecheck_WidenedArgument_t*) l16)->f_span;
            l18 = vader_diagnostics_typecheck_error((uint8_t) 91, l17, 2126u);
            vader_array_push((vader_array_t*) l2, vader_ref_box(l18));
        }
        t1 = (l7 + INT64_C(1));
        l7 = (size_t) (int64_t) t1;
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_effects_widening_outcome(void* l0, void* l1, void* l2, void* l3) {
    void* l4 = NULL;
    void* l8 = NULL;
    void* l10 = NULL;
    void* l18 = NULL;
    void* l21 = NULL;
    void* l23 = NULL;
    void* l25 = NULL;
    size_t l5, l6, l9, l14, l17, l19, l20, l24, l29;
    vader_box_t l7 = vader_box_null(), l13 = vader_box_null(), l15 = vader_box_null(), l16 = vader_box_null(), l28 = vader_box_null();
    vader_string_t l11 = 0;
    vader_string_t l26 = 0;
    int32_t l12, l22, l27;
    void* t0 = NULL;
    bool t1;
    int64_t t2;
    vader_box_t* gc_roots[5] = { &l7, &l13, &l15, &l16, &l28 };
    void** gc_raw_roots[12] = { &l0, &l1, &l2, &l3, &l4, &l8, &l10, &l18, &l21, &l23, &l25, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l11, &l26 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 5u, 12u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = ((vader_struct_vader_effects_PendingWidening_t*) l0)->f_targets;
    l5 = ((vader_array_t*) l4)->length;
    l6 = (size_t) 0;
    while ((l6 < l5)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l7 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l6);
        if (l7.tag == 870u) {
            l8 = ((vader_struct_vader_effects_PendingWidening_t*) l0)->f_site;
            l9 = ((vader_struct_vader_effects_WideningSite_t*) l8)->f_arg;
            l10 = ((vader_struct_vader_effects_WideningSite_t*) l8)->f_span;
            l11 = ((vader_struct_vader_effects_WideningSite_t*) l8)->f_module;
            l12 = ((vader_struct_vader_effects_WideningSite_t*) l8)->f_depth;
            l13 = ((vader_struct_vader_effects_WideningSite_t*) l8)->f_callee;
            l14 = ((vader_struct_vader_effects_WideningSite_t*) l8)->f_param;
            l15 = ((vader_struct_vader_effects_WideningSite_t*) l8)->f_breaking;
            vader_struct_vader_effects_WideningSite_t* _a1_obj = (vader_struct_vader_effects_WideningSite_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_WideningSite_t));
            vader_obj_header_init(_a1_obj, 897u);
            _a1_obj->f_arg = l9;
            _a1_obj->f_span = l10;
            _a1_obj->f_module = l11;
            _a1_obj->f_depth = l12;
            _a1_obj->f_callee = l13;
            _a1_obj->f_param = l14;
            _a1_obj->f_verdict = (uint8_t) 2;
            _a1_obj->f_breaking = l15;
            t0 = (void*) _a1_obj;
            { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l16 = vader_effects_known_params(l7, l1);
        l17 = ((vader_struct_vader_effects_WideningSite_t*) ((vader_struct_vader_effects_PendingWidening_t*) l0)->f_site)->f_param;
        l18 = vader_effects_accesses_of_param(l16, l17, l3);
        l19 = ((vader_array_t*) l18)->length;
        l20 = (size_t) 0;
        while ((l20 < l19)) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) l18);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            l21 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l20);
            l22 = ((vader_struct_vader_effects_WideningSite_t*) ((vader_struct_vader_effects_PendingWidening_t*) l0)->f_site)->f_depth;
            t1 = vader_effects_breaks_widening(l2, l21, l22);
            if (t1) {
                l23 = ((vader_struct_vader_effects_PendingWidening_t*) l0)->f_site;
                l24 = ((vader_struct_vader_effects_WideningSite_t*) l23)->f_arg;
                l25 = ((vader_struct_vader_effects_WideningSite_t*) l23)->f_span;
                l26 = ((vader_struct_vader_effects_WideningSite_t*) l23)->f_module;
                l27 = ((vader_struct_vader_effects_WideningSite_t*) l23)->f_depth;
                l28 = ((vader_struct_vader_effects_WideningSite_t*) l23)->f_callee;
                l29 = ((vader_struct_vader_effects_WideningSite_t*) l23)->f_param;
                vader_struct_vader_effects_WideningSite_t* _a3_obj = (vader_struct_vader_effects_WideningSite_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_WideningSite_t));
                vader_obj_header_init(_a3_obj, 897u);
                _a3_obj->f_arg = l24;
                _a3_obj->f_span = l25;
                _a3_obj->f_module = l26;
                _a3_obj->f_depth = l27;
                _a3_obj->f_callee = l28;
                _a3_obj->f_param = l29;
                _a3_obj->f_verdict = (uint8_t) 1;
                _a3_obj->f_breaking = vader_ref_box(l21);
                t0 = (void*) _a3_obj;
                { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
            }
            t2 = (l20 + INT64_C(1));
            l20 = (size_t) (int64_t) t2;
        }
        t2 = (l6 + INT64_C(1));
        l6 = (size_t) (int64_t) t2;
    }
    { void* __vret = ((vader_struct_vader_effects_PendingWidening_t*) l0)->f_site; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_effects_writes_bytes(int32_t l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[4] = { &l1, &l2, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_effects_effects_of((uint8_t) 0, l0);
    l2 = vader_effects_none();
    l3 = vader_effects_none();
    vader_array_t* _a0_arr = vader_array_new(92u, 3u, 13u, 886u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 2u] = l3;
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 1u] = l2;
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = l1;
    t0 = (void*) _a0_arr;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

bool vader_effects_written_at(void* l0, void* l1, void* l2, void* l3) {
    void* l4 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    size_t l5;
    vader_box_t l8 = vader_box_null();
    int32_t l9, l10;
    void* t0 = NULL;
    bool t1;
    vader_box_t* gc_roots[1] = { &l8 };
    void** gc_raw_roots[8] = { &l0, &l1, &l2, &l3, &l4, &l6, &l7, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 8u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l4 = ((vader_struct_vader_effects_RootCase_t*) l1)->f_body;
    l5 = ((vader_struct_vader_effects_Root_t*) l2)->f_param;
    l4 = vader_effects_root_record(l4, l5);
    l6 = ((vader_struct_vader_effects_RootCase_t*) l1)->f_paths;
    l7 = ((vader_struct_vader_effects_FrozenBody_t*) ((vader_struct_vader_effects_RootCase_t*) l1)->f_body)->f_typed;
    l8 = ((vader_struct_vader_effects_FrozenRoot_t*) l4)->f_type;
    l4 = ((vader_struct_vader_effects_RootCase_t*) l1)->f_paths;
    l9 = ((vader_struct_vader_effects_Root_t*) l2)->f_path;
    l10 = ((vader_struct_vader_effects_Access_t*) l3)->f_path;
    l9 = vader_effects_joined(l4, l9, l10);
    l8 = vader_effects_type_below(l6, l7, l8, l9);
    vader_array_t* _a0_arr = vader_array_new(16u, 0u, 7u, 285u);
    l4 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(13u, 0u, 12u, 280u);
    l6 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(16u, 0u, 7u, 285u);
    l7 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__i32__bool_t* _a3_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
    vader_obj_header_init(_a3_obj, 379u);
    _a3_obj->f_ekeys = l4;
    _a3_obj->f_evals = l6;
    _a3_obj->f_index = l7;
    _a3_obj->f_mask = (size_t) 0;
    _a3_obj->f_size = (size_t) 0;
    _a3_obj->f_tombs = (size_t) 0;
    t0 = (void*) _a3_obj;
    vader_struct_std_collections_MutableSet__i32_t* _a4_obj = (vader_struct_std_collections_MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i32_t));
    vader_obj_header_init(_a4_obj, 485u);
    _a4_obj->f_inner = t0;
    l4 = (void*) _a4_obj;
    l6 = ((vader_struct_vader_effects_FrozenSites_t*) l0)->f_written;
    l7 = ((vader_struct_vader_effects_FrozenBody_t*) ((vader_struct_vader_effects_RootCase_t*) l1)->f_body)->f_typed;
    t1 = vader_effects_may_be_written(l6, l8, l7, l4);
    { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_effects_written_keys(vader_box_t l0) {
    vader_box_t l1 = vader_box_null();
    void* l2 = NULL;
    void* l3 = NULL;
    void* l6 = NULL;
    size_t l4, l5, l7, l8;
    vader_string_t l9 = 0;
    void* t0 = NULL;
    void* t4 = NULL;
    vader_string_t t1 = 0;
    vader_box_t t2 = vader_box_null();
    int64_t t3;
    vader_box_t* gc_roots[3] = { &l0, &l1, &t2 };
    void** gc_raw_roots[5] = { &l2, &l3, &l6, &t0, &t4 };
    vader_string_t* gc_atom_roots[2] = { &l9, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l0.tag == 1199u) {
        t0 = l0.payload.obj;
        t1 = vader_effects_struct_key(t0);
        vader_array_t* _a0_arr = vader_array_new(15u, 1u, 0u, 282u);
        vader_array_box_slots(_a0_arr->buf)[_a0_arr->offset + 0u] = vader_box_string(282u, t1);
        t0 = (void*) _a0_arr;
        l1 = vader_ref_box(t0);
        { void* __vret = l1.payload.obj; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1188u) {
        vader_array_t* _a1_arr = vader_array_new(15u, 1u, 0u, 282u);
        vader_array_box_slots(_a1_arr->buf)[_a1_arr->offset + 0u] = vader_box_string(282u, 1340u);
        t0 = (void*) _a1_arr;
        l1 = vader_ref_box(t0);
    } else if (l0.tag == 1201u) {
        vader_array_t* _a2_arr = vader_array_new(15u, 1u, 0u, 282u);
        vader_array_box_slots(_a2_arr->buf)[_a2_arr->offset + 0u] = vader_box_string(282u, 2465u);
        t0 = (void*) _a2_arr;
        l1 = vader_ref_box(t0);
    } else if (l0.tag == 1204u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_types_UnionType_t*) t0)->f_variants;
        vader_array_t* _a3_arr = vader_array_new(15u, 0u, 0u, 282u);
        l3 = (void*) _a3_arr;
        l4 = ((vader_array_t*) l2)->length;
        l5 = (size_t) 0;
        while ((l5 < l4)) {
            vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
            t2 = vader_array_ref_load_box(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l5);
            l6 = vader_effects_written_keys(t2);
            l7 = ((vader_array_t*) l6)->length;
            l8 = (size_t) 0;
            while ((l8 < l7)) {
                vader_array_t* _a5_slotarr = ((vader_array_t*) l6);
                VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
                t2 = vader_array_box_slots(_a5_slotarr->buf)[_a5_slotarr->offset + (size_t) l8];
                l9 = t2.payload.s;
                vader_array_push((vader_array_t*) l3, vader_box_string(282u, l9));
                t3 = (l8 + INT64_C(1));
                l8 = (size_t) (int64_t) t3;
            }
            t3 = (l5 + INT64_C(1));
            l5 = (size_t) (int64_t) t3;
        }
        l1 = vader_ref_box(l3);
    } else if (l0.tag == 1189u) {
        t0 = l0.payload.obj;
        t4 = vader_effects_written_keys(((vader_struct_vader_types_DistinctType_t*) t0)->f_backing);
        l1 = vader_ref_box(t4);
    } else if ((l0.tag == 1187u || l0.tag == 0u || l0.tag == 1198u || l0.tag == 1200u || l0.tag == 1203u || l0.tag == 1205u)) {
        vader_array_t* _a6_arr = vader_array_new(15u, 1u, 0u, 282u);
        vader_array_box_slots(_a6_arr->buf)[_a6_arr->offset + 0u] = vader_box_string(282u, 1330u);
        t0 = (void*) _a6_arr;
        l1 = vader_ref_box(t0);
    } else {
        if (!((l0.tag == 1190u || l0.tag == 1191u || l0.tag == 1192u || l0.tag == 1193u || l0.tag == 1194u || l0.tag == 1195u || l0.tag == 1197u || l0.tag == 1202u))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        vader_array_t* _a7_arr = vader_array_new(15u, 0u, 0u, 282u);
        t0 = (void*) _a7_arr;
        l1 = vader_ref_box(t0);
    }
    { void* __vret = l1.payload.obj; vader_gc_top = gc_frame.prev; return __vret; }
}
