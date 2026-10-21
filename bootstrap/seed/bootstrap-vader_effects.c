#include "bootstrap.split.h"

static int64_t vader_effects_access_key(void* l0);
static void* vader_effects_accesses_of_param(vader_box_t l0, int64_t l1, void* l2);
static int64_t vader_effects_add_copy(void* l0, int64_t l1, int64_t l2);
static void vader_effects_add_flow(void* l0, int64_t l1, int64_t l2, int32_t l3);
static void vader_effects_add_mark(void* l0, int64_t l1, int32_t l2, uint8_t l3, void* l4);
static int64_t vader_effects_add_root(void* l0, int64_t l1);
static int64_t vader_effects_add_site(void* l0, void* l1, void* l2, vader_box_t l3, void* l4);
static void* vader_effects_any_effects(void);
static vader_box_t vader_effects_any_field(void* l0, vader_box_t l1, vader_box_t l2);
static bool vader_effects_apply_constraints(void* l0, void* l1, void* l2, void* l3, void* l4);
static bool vader_effects_apply_site(void* l0, void* l1, void* l2, int64_t l3, void* l4);
static vader_string_t vader_effects_argument_label(void* l0, void* l1, int32_t l2);
static void vader_effects_assign(void* l0, vader_box_t l1, vader_box_t l2);
static void vader_effects_assign_element(void* l0, void* l1, vader_box_t l2);
static void vader_effects_assign_name(void* l0, void* l1, vader_box_t l2);
static void* vader_effects_at_path(void* l0, int32_t l1);
static vader_box_t vader_effects_binary_value(void* l0, void* l1);
static void vader_effects_bind(void* l0, vader_box_t l1, vader_box_t l2);
static void vader_effects_bind_copy(void* l0, int64_t l1, vader_box_t l2, void* l3, void* l4);
static void vader_effects_bind_pattern(void* l0, vader_box_t l1, vader_box_t l2);
static void vader_effects_bind_symbol(void* l0, void* l1, vader_box_t l2);
static uint8_t vader_effects_binding_outcome(void* l0, void* l1, bool l2);
static vader_box_t vader_effects_block_value(void* l0, void* l1);
static void* vader_effects_body_ctx(void* l0, void* l1, void* l2, void* l3);
static vader_box_t vader_effects_bodyless_target(void* l0, void* l1, void* l2);
static bool vader_effects_breaks_widening(void* l0, void* l1, int32_t l2);
static vader_box_t vader_effects_call(void* l0, vader_box_t l1, void* l2, void* l3, void* l4);
static int64_t vader_effects_call_origin(int64_t l0, int64_t l1, int64_t l2);
static void* vader_effects_call_sources(void* l0, void* l1, vader_box_t l2);
static vader_box_t vader_effects_call_value(void* l0, void* l1);
static void* vader_effects_callee_nodes(void* l0);
static void* vader_effects_callers_of(void* l0, void* l1);
static void* vader_effects_carried(void* l0, void* l1, void* l2);
static int64_t vader_effects_carried_at(void* l0, int64_t l1);
static vader_box_t vader_effects_chain_position(void* l0, int32_t l1, int32_t l2);
static int32_t vader_effects_child(void* l0, int32_t l1, int32_t l2);
static bool vader_effects_collect_returned(void* l0, void* l1, void* l2, void* l3);
static int32_t vader_effects_composed(void* l0, int32_t l1, int32_t l2, bool l3);
static void* vader_effects_constant_initialiser(void* l0, void* l1, void* l2);
static int64_t vader_effects_constraint_at(void* l0, int64_t l1);
static vader_box_t vader_effects_converted(void* l0, vader_box_t l1, vader_box_t l2);
static vader_box_t vader_effects_converted_by(void* l0, vader_box_t l1, vader_box_t l2, vader_box_t l3);
static vader_string_t vader_effects_copy_hint(void* l0, vader_string_t l1);
static uint8_t vader_effects_copy_or_elided(void* l0, void* l1, void* l2);
static void* vader_effects_copy_to_effects(int32_t l0);
static bool vader_effects_covered(void* l0, void* l1, int32_t l2, uint8_t l3);
static bool vader_effects_covers(void* l0, void* l1, void* l2);
static bool vader_effects_covers_key(void* l0, void* l1, int64_t l2);
static int32_t vader_effects_cut(void* l0, int32_t l1);
static void vader_effects_decide(void* l0, void* l1, void* l2, void* l3, void* l4);
static void vader_effects_defer_stmt(void* l0, void* l1);
static void vader_effects_destructure_assign(void* l0, void* l1);
static void* vader_effects_direct_targets(void* l0, void* l1);
static void vader_effects_discard(void* l0, vader_box_t l1);
static vader_string_t vader_effects_display_callee(vader_box_t l0);
static vader_string_t vader_effects_display_path(void* l0, int32_t l1);
static vader_string_t vader_effects_display_steps(void* l0, int32_t l1);
static vader_box_t vader_effects_drop_covered(void* l0, void* l1, void* l2);
static void* vader_effects_each_targets(void* l0, void* l1);
static void* vader_effects_effects_of(uint8_t l0, int32_t l1);
static bool vader_effects_either(void* l0, void* l1);
static vader_box_t vader_effects_else_value(void* l0, vader_box_t l1);
static void vader_effects_escape(void* l0, vader_box_t l1, uint8_t l2, void* l3);
static bool vader_effects_evaluate(void* l0, void* l1, void* l2);
static void* vader_effects_evaluate_roots(void* l0, void* l1);
static bool vader_effects_extends(void* l0, int32_t l1, int32_t l2);
static vader_box_t vader_effects_fallback_value(void* l0, vader_box_t l1);
static vader_box_t vader_effects_fault_chain(void* l0, void* l1, void* l2, void* l3, uint8_t l4, bool l5);
static vader_string_t vader_effects_fault_detail(void* l0);
static vader_box_t vader_effects_fault_of(void* l0, void* l1);
static vader_box_t vader_effects_fault_set(void* l0, int64_t l1, uint8_t l2);
static void* vader_effects_ffi_call_effects(int32_t l0);
static vader_string_t vader_effects_field_step(void* l0);
static vader_box_t vader_effects_field_value(void* l0, void* l1);
static bool vader_effects_fields_may_be_written(void* l0, void* l1, void* l2, void* l3);
static vader_box_t vader_effects_find_access(void* l0, void* l1, int64_t l2);
static vader_box_t vader_effects_first_covered(void* l0, void* l1, void* l2);
static void* vader_effects_first_paths(void);
static bool vader_effects_first_step_is(void* l0, int32_t l1, vader_string_t l2);
static void* vader_effects_flowed_root(void* l0, void* l1, void* l2, void* l3);
static void vader_effects_for_stmt(void* l0, void* l1);
static void* vader_effects_foreign_effects(void* l0);
static int64_t vader_effects_fresh_slot(void* l0);
static int64_t vader_effects_frozen_source(void* l0, vader_box_t l1, vader_string_t l2, uint8_t l3, vader_box_t l4);
static vader_box_t vader_effects_frozen_use(void* l0, vader_box_t l1, void* l2);
static vader_box_t vader_effects_frozen_variant_data(void* l0, void* l1);
static vader_box_t vader_effects_frozen_view(void* l0, void* l1, vader_box_t l2);
static vader_string_t vader_effects_frozen_what(void* l0);
static bool vader_effects_hands_on_written(void* l0, void* l1, void* l2);
static vader_box_t vader_effects_held_by(void* l0, void* l1);
static int64_t vader_effects_held_count(void* l0, int64_t l1);
static bool vader_effects_holds_view(void* l0);
static vader_box_t vader_effects_ident_value(void* l0, void* l1);
static vader_box_t vader_effects_if_value(void* l0, void* l1);
static bool vader_effects_include(void* l0, void* l1, int32_t l2, uint8_t l3, int64_t l4, int64_t l5);
static bool vader_effects_include_root(void* l0, int64_t l1, void* l2);
static void* vader_effects_index_functions(void* l0, void* l1);
static vader_box_t vader_effects_index_value(void* l0, void* l1);
static void* vader_effects_initialiser_ctx(void* l0, void* l1, void* l2, void* l3);
static void vader_effects_insert(void* l0, void* l1, int64_t l2, int64_t l3);
static vader_box_t vader_effects_intrinsic_effects(void* l0, vader_string_t l1);
static vader_string_t vader_effects_intrinsic_key(void* l0, void* l1, void* l2);
static vader_box_t vader_effects_intrinsic_value(void* l0, void* l1);
static bool vader_effects_is_seed(void* l0, int64_t l1);
static int32_t vader_effects_joined(void* l0, int32_t l1, int32_t l2);
static int64_t vader_effects_key_of(int32_t l0, uint8_t l1);
static void* vader_effects_key_set(void* l0);
static vader_box_t vader_effects_known_params(vader_box_t l0, void* l1);
static vader_box_t vader_effects_lambda_value(void* l0, void* l1);
static int64_t vader_effects_local_slot(void* l0, int32_t l1);
static vader_box_t vader_effects_loop_element(void* l0, vader_box_t l1, vader_box_t l2);
static void* vader_effects_lost_write(void* l0);
static bool vader_effects_makes_frozen_view(vader_string_t l0);
static bool vader_effects_makes_view(void* l0, vader_box_t l1);
static void vader_effects_mark(void* l0, vader_box_t l1, int32_t l2, uint8_t l3, void* l4);
static bool vader_effects_mark_fresh(void* l0, void* l1);
static int64_t vader_effects_mark_origin(int64_t l0);
static bool vader_effects_mark_roots(void* l0, void* l1, int32_t l2, uint8_t l3, void* l4, bool l5, int64_t l6, int64_t l7);
static vader_box_t vader_effects_match_value(void* l0, void* l1);
static void* vader_effects_member_targets(void* l0, vader_string_t l1, vader_string_t l2);
static void* vader_effects_memory_copy_effects(int32_t l0);
static vader_string_t vader_effects_modified_how(void* l0);
static void* vader_effects_named_use(void* l0);
static vader_box_t vader_effects_namespace_member(void* l0, void* l1);
static vader_box_t vader_effects_narrowed(void* l0, vader_box_t l1, vader_box_t l2, vader_box_t l3);
static void* vader_effects_new_skeleton(int64_t l0);
static int64_t vader_effects_next_root(void* l0);
static void vader_effects_note_frozen_body(void* l0, int32_t l1, vader_box_t l2);
static void vader_effects_note_initialisers(void* l0, void* l1, void* l2);
static void vader_effects_note_kept_by_constant(void* l0, void* l1, void* l2);
static void vader_effects_note_known_writes(void* l0, void* l1, int64_t l2, vader_box_t l3);
static void vader_effects_note_place(void* l0, vader_box_t l1);
static void vader_effects_note_widened(void* l0, vader_box_t l1, void* l2, int64_t l3, vader_box_t l4);
static void vader_effects_note_write(void* l0, vader_box_t l1);
static void vader_effects_note_written(void* l0, vader_box_t l1);
static vader_box_t vader_effects_nothing(void* l0, vader_box_t l1);
static vader_box_t vader_effects_one_of(void* l0, void* l1);
static vader_box_t vader_effects_origin_call(int64_t l0);
static vader_box_t vader_effects_origin_mark(int64_t l0);
static vader_box_t vader_effects_outcome(void* l0, void* l1, void* l2, bool l3);
static int64_t vader_effects_pair_key(int32_t l0, int32_t l1);
static vader_box_t vader_effects_parameter_name(vader_box_t l0, int64_t l1);
static bool vader_effects_passes_receiver(void* l0, void* l1, void* l2, vader_box_t l3);
static vader_box_t vader_effects_path_slot(void* l0, vader_box_t l1, int32_t l2);
static int32_t vader_effects_path_to(void* l0, vader_string_t l1);
static vader_string_t vader_effects_place_label(void* l0, vader_string_t l1, int32_t l2);
static int64_t vader_effects_pure_source(void* l0, int64_t l1);
static void* vader_effects_push_effects(int32_t l0);
static vader_box_t vader_effects_range_value(void* l0, void* l1);
static bool vader_effects_reaches_view(void* l0, void* l1);
static void vader_effects_read_fresh(void* l0, void* l1);
static bool vader_effects_reads_fresh(void* l0, void* l1, uint8_t l2);
static bool vader_effects_recursive(void* l0, vader_box_t l1);
static void vader_effects_register(void* l0, void* l1, void* l2);
static void vader_effects_register_defaults(void* l0, void* l1, void* l2);
static void* vader_effects_remove_last_effects(int32_t l0);
static void vader_effects_replace_body(void* l0, void* l1);
static bool vader_effects_reroot(void* l0, void* l1, int64_t l2, int64_t l3, void* l4, void* l5);
static bool vader_effects_reroot_below(void* l0, int64_t l1, int64_t l2, int64_t l3, int32_t l4, int64_t l5, void* l6, bool l7);
static uint8_t vader_effects_result_effect_of(void* l0);
static uint8_t vader_effects_return_effect(void* l0);
static void vader_effects_return_stmt(void* l0, void* l1);
static vader_box_t vader_effects_returned_array(vader_box_t l0);
static bool vader_effects_returns_it(void* l0);
static vader_box_t vader_effects_root_case(void* l0, void* l1, void* l2, void* l3);
static vader_box_t vader_effects_sequence_value(void* l0, void* l1);
static vader_box_t vader_effects_sequence_walked(void* l0, void* l1);
static void vader_effects_settle_frozen(void* l0, void* l1, void* l2);
static void* vader_effects_settle_widenings(void* l0, void* l1, void* l2);
static void* vader_effects_settled_slots(void* l0, void* l1, bool l2);
static vader_box_t vader_effects_single(void* l0);
static vader_box_t vader_effects_site_callee(void* l0, uint8_t l1, int64_t l2);
static void* vader_effects_skeleton_of(void* l0, void* l1, void* l2, void* l3, void* l4, int32_t l5);
static void vader_effects_spread(void* l0, vader_box_t l1, void* l2);
static void vader_effects_spread_fresh(void* l0);
static void vader_effects_spread_views(void* l0, void* l1, void* l2, void* l3, void* l4, void* l5);
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
static vader_string_t vader_effects_through(void* l0);
static void* vader_effects_trace(void* l0, void* l1, int64_t l2);
static vader_box_t vader_effects_type_below(void* l0, void* l1, vader_box_t l2, int32_t l3);
static vader_box_t vader_effects_union_of(void* l0, void* l1);
static vader_box_t vader_effects_use_outcome(void* l0, void* l1);
static vader_box_t vader_effects_value(void* l0, vader_box_t l1);
static vader_box_t vader_effects_value_of(void* l0, vader_box_t l1);
static int64_t vader_effects_variant_data_use(void* l0, void* l1, void* l2);
static vader_string_t vader_effects_view_label(vader_box_t l0);
static vader_box_t vader_effects_view_outcome(void* l0);
static void* vader_effects_view_returners(void* l0, void* l1, void* l2, void* l3);
static vader_string_t vader_effects_what_it_may_do(uint8_t l0, vader_string_t l1);
static vader_string_t vader_effects_widening_detail(void* l0, void* l1);
static void* vader_effects_widening_outcome(void* l0, void* l1, void* l2, void* l3);
static vader_string_t vader_effects_write_phrase(vader_box_t l0);
static void* vader_effects_writes_bytes(int32_t l0);
static void* vader_effects_written_by(void* l0, void* l1, void* l2, void* l3, vader_box_t l4);
static void* vader_effects_written_keys(vader_box_t l0);

static int64_t vader_effects_access_key(void* l0) {
    int32_t l1;
    uint8_t l2;
    int64_t t0;
    l1 = ((vader_struct_vader_effects_Access_t*) l0)->f_path;
    l2 = ((vader_struct_vader_effects_Access_t*) l0)->f_effect;
    t0 = vader_effects_key_of(l1, l2);
    return t0;
}

static void* vader_effects_accesses_of_param(vader_box_t l0, int64_t l1, void* l2) {
    bool l3;
    int64_t l4;
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

static int64_t vader_effects_add_copy(void* l0, int64_t l1, int64_t l2) {
    int64_t l3;
    void* l4 = NULL;
    void* l5 = NULL;
    void** gc_raw_roots[3] = { &l0, &l4, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = vader_effects_next_root(l0);
    l4 = ((vader_struct_vader_effects_Skeleton_t*) l0)->f_flows;
    vader_struct_vader_effects_Flow_t* _a0_obj = (vader_struct_vader_effects_Flow_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_Flow_t));
    vader_obj_header_init(_a0_obj, 922u);
    _a0_obj->f_into = l1;
    _a0_obj->f_from = l2;
    _a0_obj->f_path = INT32_C(0);
    _a0_obj->f_copy = vader_box_i64(292u, l3);
    l5 = (void*) _a0_obj;
    vader_array_push((vader_array_t*) l4, vader_ref_box(l5));
    { int64_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_effects_add_flow(void* l0, int64_t l1, int64_t l2, int32_t l3) {
    void* l4 = NULL;
    void* l5 = NULL;
    void** gc_raw_roots[3] = { &l0, &l4, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l4 = ((vader_struct_vader_effects_Skeleton_t*) l0)->f_flows;
    vader_struct_vader_effects_Flow_t* _a0_obj = (vader_struct_vader_effects_Flow_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_Flow_t));
    vader_obj_header_init(_a0_obj, 922u);
    _a0_obj->f_into = l1;
    _a0_obj->f_from = l2;
    _a0_obj->f_path = l3;
    _a0_obj->f_copy = vader_box_obj(0u, NULL);
    l5 = (void*) _a0_obj;
    vader_array_push((vader_array_t*) l4, vader_ref_box(l5));
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_effects_add_mark(void* l0, int64_t l1, int32_t l2, uint8_t l3, void* l4) {
    void* l5 = NULL;
    void** gc_raw_roots[3] = { &l0, &l4, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_effects_Mark_t* _a0_obj = (vader_struct_vader_effects_Mark_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_Mark_t));
    vader_obj_header_init(_a0_obj, 931u);
    _a0_obj->f_slot = l1;
    _a0_obj->f_path = l2;
    _a0_obj->f_effect = l3;
    _a0_obj->f_at = l4;
    l5 = (void*) _a0_obj;
    vader_array_push((vader_array_t*) ((vader_struct_vader_effects_Skeleton_t*) l0)->f_marks, vader_ref_box(l5));
    { vader_gc_top = gc_frame.prev; return; }
}

static int64_t vader_effects_add_root(void* l0, int64_t l1) {
    int64_t l2;
    void* l3 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    vader_box_t l4 = vader_box_null();
    vader_box_t* gc_roots[1] = { &l4 };
    void** gc_raw_roots[4] = { &l0, &l3, &l5, &l6 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = vader_effects_next_root(l0);
    l4 = ((vader_struct_vader_effects_Skeleton_t*) l0)->f_seeds;
    if (l4.tag == 0u) {
        vader_array_t* _a0_arr = vader_array_new(16u, 0u, 8u, 292u);
        l3 = (void*) _a0_arr;
        vader_array_t* _a1_arr = vader_array_new(16u, 0u, 8u, 292u);
        l5 = (void*) _a1_arr;
        vader_array_t* _a2_arr = vader_array_new(15u, 0u, 7u, 291u);
        l6 = (void*) _a2_arr;
        vader_struct_std_collections_MutableMap__i64__i64_t* _a3_obj = (vader_struct_std_collections_MutableMap__i64__i64_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i64__i64_t));
        vader_obj_header_init(_a3_obj, 429u);
        _a3_obj->f_ekeys = l3;
        _a3_obj->f_evals = l5;
        _a3_obj->f_index = l6;
        _a3_obj->f_mask = INT64_C(0);
        _a3_obj->f_size = INT64_C(0);
        _a3_obj->f_tombs = INT64_C(0);
        l3 = (void*) _a3_obj;
        std_collections_MutableMap_std_core_IndexSet_set_at__i64__i64(l3, l2, l1);
        ((vader_struct_vader_effects_Skeleton_t*) l0)->f_seeds = vader_ref_box(l3);
        VADER_WRITE_BARRIER((vader_struct_vader_effects_Skeleton_t*) l0);
        { int64_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = l4.payload.obj;
    std_collections_MutableMap_std_core_IndexSet_set_at__i64__i64(l3, l2, l1);
    ((vader_struct_vader_effects_Skeleton_t*) l0)->f_seeds = vader_ref_box(l3);
    VADER_WRITE_BARRIER((vader_struct_vader_effects_Skeleton_t*) l0);
    { int64_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static int64_t vader_effects_add_site(void* l0, void* l1, void* l2, vader_box_t l3, void* l4) {
    int64_t l5, l6, l8;
    void* l7 = NULL;
    vader_box_t* gc_roots[1] = { &l3 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l4, &l7 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l5 = vader_effects_fresh_slot(l0);
    l6 = ((vader_struct_vader_effects_Skeleton_t*) l0)->f_arguments;
    vader_struct_vader_effects_Site_t* _a0_obj = (vader_struct_vader_effects_Site_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_Site_t));
    vader_obj_header_init(_a0_obj, 939u);
    _a0_obj->f_targets = l1;
    _a0_obj->f_args = l2;
    _a0_obj->f_result = l5;
    _a0_obj->f_first_argument = l6;
    _a0_obj->f_callee = l3;
    _a0_obj->f_at = l4;
    l7 = (void*) _a0_obj;
    l6 = ((vader_struct_vader_effects_Skeleton_t*) l0)->f_arguments;
    l8 = ((vader_array_t*) l2)->length;
    l6 = vader_chk_add(i64, l6, l8);
    ((vader_struct_vader_effects_Skeleton_t*) l0)->f_arguments = l6;
    vader_array_push((vader_array_t*) ((vader_struct_vader_effects_Skeleton_t*) l0)->f_sites, vader_ref_box(l7));
    { int64_t __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_effects_any_effects(void) {
    void* l0 = NULL;
    void* l1 = NULL;
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(85u, 0u, 13u, 911u);
    l0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(16u, 0u, 8u, 292u);
    l1 = (void*) _a1_arr;
    vader_struct_vader_effects_ParamEffects_t* _a2_obj = (vader_struct_vader_effects_ParamEffects_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_ParamEffects_t));
    vader_obj_header_init(_a2_obj, 932u);
    _a2_obj->f_accesses = l0;
    _a2_obj->f_origins = l1;
    _a2_obj->f_keys = vader_box_obj(0u, NULL);
    l0 = (void*) _a2_obj;
    vader_struct_vader_effects_Access_t* _a3_obj = (vader_struct_vader_effects_Access_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_Access_t));
    vader_obj_header_init(_a3_obj, 911u);
    _a3_obj->f_path = INT32_C(1);
    _a3_obj->f_effect = (uint8_t) 5;
    l1 = (void*) _a3_obj;
    vader_effects_insert(l0, l1, INT64_C(-1), INT64_C(-1));
    vader_struct_vader_effects_Access_t* _a4_obj = (vader_struct_vader_effects_Access_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_Access_t));
    vader_obj_header_init(_a4_obj, 911u);
    _a4_obj->f_path = INT32_C(1);
    _a4_obj->f_effect = (uint8_t) 3;
    l1 = (void*) _a4_obj;
    vader_effects_insert(l0, l1, INT64_C(-1), INT64_C(-1));
    { void* __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_effects_any_field(void* l0, vader_box_t l1, vader_box_t l2) {
    void* l3 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    vader_box_t l4 = vader_box_null(), l12 = vader_box_null();
    int64_t l8, l9;
    vader_string_t l10 = 0;
    vader_string_t l11 = 0;
    vader_box_t t0 = vader_box_null();
    bool t1;
    vader_box_t* gc_roots[5] = { &l1, &l2, &l4, &l12, &t0 };
    void** gc_raw_roots[5] = { &l0, &l3, &l5, &l6, &l7 };
    vader_string_t* gc_atom_roots[2] = { &l10, &l11 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 5u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = vader_effects_struct_fields_of(l0, l1);
    if (l4.tag == 0u) {
        t0 = vader_effects_path_slot(l0, l2, INT32_C(1));
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = l4.payload.obj;
    vader_array_t* _a0_arr = vader_array_new(214u, 0u, 0u, 1414u);
    l5 = (void*) _a0_arr;
    l6 = ((vader_struct_std_collections_MutableMap__string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_t*) l3)->f_ekeys;
    l7 = ((vader_struct_std_collections_MutableMap__string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_t*) l3)->f_evals;
    l8 = INT64_C(0);
    l9 = ((vader_struct_std_collections_MutableMap__string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_t*) l3)->f_size;
    while ((l8 < l9)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l8)
        t0 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l8];
        l10 = t0.payload.s;
        vader_array_t* _a2_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l8)
        l4 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l8);
        l11 = l10;
        t1 = vader_effects_holds_references(l4);
        if (t1) {
            l12 = vader_effects_step_slot(l0, l2, l11);
            vader_array_push((vader_array_t*) l5, l12);
        }
        l8 = (l8 + INT64_C(1));
    }
    t0 = vader_effects_union_of(l0, l5);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_effects_apply_constraints(void* l0, void* l1, void* l2, void* l3, void* l4) {
    bool l5;
    int64_t l6, l7, l11, l16;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    void* l15 = NULL;
    vader_box_t l12 = vader_box_null();
    int32_t l13;
    uint8_t l14;
    bool t0;
    vader_box_t* gc_roots[1] = { &l12 };
    void** gc_raw_roots[9] = { &l0, &l1, &l2, &l3, &l4, &l8, &l9, &l10, &l15 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 9u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l5 = false;
    l6 = INT64_C(0);
    l7 = ((vader_array_t*) ((vader_struct_vader_effects_Skeleton_t*) l0)->f_marks)->length;
    while ((l6 < l7)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_effects_Skeleton_t*) l0)->f_marks);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l6)
        l8 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l6);
        l10 = ((vader_struct_vader_effects_SlotRoots_t*) l1)->f_roots;
        l11 = ((vader_struct_vader_effects_Mark_t*) l8)->f_slot;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l10);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l11)
        l12 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l11);
        if (l12.tag == 0u) {
            l6 = (l6 + INT64_C(1));
            continue;
        }
        l9 = l12.payload.obj;
        l13 = ((vader_struct_vader_effects_Mark_t*) l8)->f_path;
        l14 = ((vader_struct_vader_effects_Mark_t*) l8)->f_effect;
        l15 = ((vader_struct_vader_effects_EvalCtx_t*) l2)->f_paths;
        l16 = vader_effects_mark_origin(l6);
        t0 = vader_effects_mark_roots(l3, l9, l13, l14, l15, false, l16, INT64_C(-1));
        if (t0) {
            l5 = true;
        }
        l6 = (l6 + INT64_C(1));
    }
    l6 = INT64_C(0);
    l7 = ((vader_array_t*) ((vader_struct_vader_effects_Skeleton_t*) l0)->f_sites)->length;
    while ((l6 < l7)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_effects_Skeleton_t*) l0)->f_sites);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l6)
        l8 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l6);
        t0 = vader_effects_apply_site(l4, l1, l8, l6, l2);
        if (t0) {
            l5 = true;
        }
        l6 = (l6 + INT64_C(1));
    }
    { bool __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_effects_apply_site(void* l0, void* l1, void* l2, int64_t l3, void* l4) {
    bool l5, l11;
    int64_t l6, l7, l12, l13, l14, l18, l21, l22, l24;
    vader_box_t l8 = vader_box_null(), l10 = vader_box_null(), l15 = vader_box_null(), l17 = vader_box_null();
    void* l9 = NULL;
    void* l16 = NULL;
    void* l19 = NULL;
    void* l20 = NULL;
    void* l23 = NULL;
    void* l27 = NULL;
    int32_t l25;
    uint8_t l26;
    bool t0;
    vader_box_t* gc_roots[4] = { &l8, &l10, &l15, &l17 };
    void** gc_raw_roots[10] = { &l0, &l1, &l2, &l4, &l9, &l16, &l19, &l20, &l23, &l27 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 10u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l5 = false;
    l6 = INT64_C(0);
    l7 = ((vader_array_t*) ((vader_struct_vader_effects_Site_t*) l2)->f_targets)->length;
    while ((l6 < l7)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_effects_Site_t*) l2)->f_targets);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l6)
        l8 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l6);
        l9 = ((vader_struct_vader_effects_EvalCtx_t*) l4)->f_facts;
        l10 = vader_effects_known_params(l8, l9);
        l11 = vader_effects_recursive(l4, l8);
        l12 = INT64_C(0);
        l13 = ((vader_array_t*) ((vader_struct_vader_effects_Site_t*) l2)->f_args)->length;
        while ((l12 < l13)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_effects_Site_t*) l2)->f_args);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l12)
            l15 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l12];
            if (l15.tag == 0u) {
                l12 = (l12 + INT64_C(1));
                continue;
            }
            l14 = ((int64_t) l15.payload.i);
            vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_effects_SlotRoots_t*) l1)->f_roots);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l14)
            l17 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l14);
            if (l17.tag == 0u) {
                l12 = (l12 + INT64_C(1));
                continue;
            }
            l16 = l17.payload.obj;
            l18 = vader_effects_call_origin(l3, l6, l12);
            l19 = ((vader_struct_vader_effects_EvalCtx_t*) l4)->f_any;
            l20 = vader_effects_accesses_of_param(l10, l12, l19);
            l21 = ((vader_array_t*) l20)->length;
            l22 = INT64_C(0);
            while ((l22 < l21)) {
                vader_array_t* _a3_slotarr = ((vader_array_t*) l20);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                l23 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l22);
                if (((vader_struct_vader_effects_Access_t*) l23)->f_effect != INT32_C(4)) {
                    l24 = vader_effects_access_key(l23);
                    l25 = ((vader_struct_vader_effects_Access_t*) l23)->f_path;
                    l26 = ((vader_struct_vader_effects_Access_t*) l23)->f_effect;
                    l27 = ((vader_struct_vader_effects_EvalCtx_t*) l4)->f_paths;
                    t0 = vader_effects_mark_roots(l0, l16, l25, l26, l27, l11, l18, l24);
                    if (t0) {
                        l5 = true;
                    }
                }
                l22 = (l22 + INT64_C(1));
            }
            l12 = (l12 + INT64_C(1));
        }
        l6 = (l6 + INT64_C(1));
    }
    { bool __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_effects_argument_label(void* l0, void* l1, int32_t l2) {
    vader_string_t l3 = 0;
    vader_string_t l6 = 0;
    vader_box_t l4 = vader_box_null();
    int64_t l5;
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
        t0 = concat_4(924u, l6, l3, 924u);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l3 == 0u)) {
        t0 = concat_3(2052u, l3, 924u);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return 2044u; }
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
    if (l1.tag == 569u) {
        l3 = l1.payload.obj;
        vader_effects_assign_name(l0, l3, l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 562u) {
        t0 = l1.payload.obj;
        l4 = ((vader_struct_toolchain_ast_FieldExpr_t*) t0)->f_target;
        vader_effects_note_write(l0, l4);
        l3 = ((vader_struct_vader_effects_CalleeIndex_t*) ((vader_struct_vader_effects_WalkCtx_t*) l0)->f_index)->f_paths;
        t0 = l1.payload.obj;
        l5 = vader_effects_field_step(t0);
        l6 = vader_effects_path_to(l3, l5);
        t0 = l1.payload.obj;
        l4 = ((vader_struct_toolchain_ast_FieldExpr_t*) t0)->f_target;
        l4 = vader_effects_value(l0, l4);
        t0 = l1.payload.obj;
        l3 = ((vader_struct_toolchain_ast_FieldExpr_t*) t0)->f_span;
        vader_effects_mark(l0, l4, l6, (uint8_t) 0, l3);
        t0 = l1.payload.obj;
        l3 = ((vader_struct_toolchain_ast_FieldExpr_t*) t0)->f_span;
        vader_effects_escape(l0, l2, (uint8_t) 3, l3);
    } else if (l1.tag == 577u) {
        l3 = l1.payload.obj;
        vader_effects_assign_element(l0, l3, l2);
    } else {
        l4 = l1;
        vader_effects_discard(l0, l4);
        l3 = VADER_UNION_FIELD(void*, vader_struct_toolchain_ast_ArrayTypeExpr_t, f_span, l1.payload.obj);
        vader_effects_escape(l0, l2, (uint8_t) 3, l3);
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_effects_assign_element(void* l0, void* l1, vader_box_t l2) {
    vader_box_t l3 = vader_box_null(), l4 = vader_box_null(), l6 = vader_box_null();
    int64_t l5;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    int32_t l10;
    vader_box_t* gc_roots[4] = { &l2, &l3, &l4, &l6 };
    void** gc_raw_roots[5] = { &l0, &l1, &l7, &l8, &l9 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
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
        if (!(l6.tag == 1198u)) {
            if (!(l6.tag == 1214u)) {
                vader_array_t* _a0_arr = vader_array_new(214u, 3u, 0u, 1414u);
                vader_array_box_slots(_a0_arr->buf)[_a0_arr->offset + 2u] = l2;
                vader_array_box_slots(_a0_arr->buf)[_a0_arr->offset + 1u] = l4;
                vader_array_box_slots(_a0_arr->buf)[_a0_arr->offset + 0u] = l3;
                l7 = (void*) _a0_arr;
                l8 = ((vader_struct_toolchain_ast_IndexExpr_t*) l1)->f_span;
                l4 = ((vader_struct_toolchain_ast_IndexExpr_t*) l1)->f_index;
                vader_array_t* _a1_arr = vader_array_new(216u, 3u, 13u, 1457u);
                ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 2u] = vader_box_obj(0u, NULL).payload.obj;
                ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 1u] = l4.payload.obj;
                ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = vader_box_obj(0u, NULL).payload.obj;
                l9 = (void*) _a1_arr;
                vader_effects_call(l0, l6, l7, l8, l9);
                { vader_gc_top = gc_frame.prev; return; }
            }
        }
    }
    l10 = vader_effects_path_to(((vader_struct_vader_effects_CalleeIndex_t*) ((vader_struct_vader_effects_WalkCtx_t*) l0)->f_index)->f_paths, 856u);
    l7 = ((vader_struct_toolchain_ast_IndexExpr_t*) l1)->f_span;
    vader_effects_mark(l0, l3, l10, (uint8_t) 0, l7);
    l7 = ((vader_struct_toolchain_ast_IndexExpr_t*) l1)->f_span;
    vader_effects_escape(l0, l2, (uint8_t) 3, l7);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_effects_assign_name(void* l0, void* l1, vader_box_t l2) {
    vader_box_t l3 = vader_box_null(), l7 = vader_box_null();
    void* l4 = NULL;
    void* l5 = NULL;
    uint64_t l6;
    int64_t l8;
    vader_box_t* gc_roots[3] = { &l2, &l3, &l7 };
    void** gc_raw_roots[4] = { &l0, &l1, &l4, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = vader_effects_ident_value(l0, l1);
    if (l3.tag == 0u) {
        l4 = ((vader_struct_toolchain_ast_IdentExpr_t*) l1)->f_span;
        vader_effects_escape(l0, l2, (uint8_t) 3, l4);
        { vader_gc_top = gc_frame.prev; return; }
    }
    l5 = ((vader_struct_vader_resolver_ResolvedModule_t*) ((vader_struct_vader_typecheck_TypedProgram_t*) ((vader_struct_vader_effects_WalkCtx_t*) l0)->f_typed)->f_resolved)->f_idents;
    l6 = toolchain_span_Span_std_core_Hash_hash(((vader_struct_toolchain_ast_IdentExpr_t*) l1)->f_span);
    l7 = std_collections_MutableMap_std_core_Index_at__u64__Any(l5, l6);
    if (l7.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l4 = l7.payload.obj;
    l8 = ((int64_t) l3.payload.i);
    l5 = ((vader_struct_toolchain_ast_IdentExpr_t*) l1)->f_span;
    vader_effects_bind_copy(l0, l8, l2, l5, l4);
    { vader_gc_top = gc_frame.prev; return; }
}

static void* vader_effects_at_path(void* l0, int32_t l1) {
    int32_t l2;
    int64_t t0;
    void* t1 = NULL;
    void** gc_raw_roots[2] = { &l0, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_effects_Root_t*) l0)->f_path;
    if (!(l1 == l2)) {
        t0 = ((vader_struct_vader_effects_Root_t*) l0)->f_param;
        vader_struct_vader_effects_Root_t* _a0_obj = (vader_struct_vader_effects_Root_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_Root_t));
        vader_obj_header_init(_a0_obj, 936u);
        _a0_obj->f_param = t0;
        _a0_obj->f_path = l1;
        t1 = (void*) _a0_obj;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { void* __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_effects_binary_value(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l3 = vader_box_null(), l4 = vader_box_null(), l10 = vader_box_null(), l11 = vader_box_null();
    int64_t l5;
    bool l6;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[6] = { &l2, &l3, &l4, &l10, &l11, &t0 };
    void** gc_raw_roots[5] = { &l0, &l1, &l7, &l8, &l9 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 6u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_toolchain_ast_BinaryExpr_t*) l1)->f_left;
    l2 = vader_effects_value(l0, l2);
    l3 = ((vader_struct_toolchain_ast_BinaryExpr_t*) l1)->f_right;
    l3 = vader_effects_value(l0, l3);
    l5 = ((vader_struct_toolchain_ast_BinaryExpr_t*) l1)->f_id;
    l4 = vader_effects_site_callee(l0, (uint8_t) 1, l5);
    if (l4.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    if (((vader_struct_toolchain_ast_BinaryExpr_t*) l1)->f_op == INT32_C(19)) {
        l6 = true;
    } else {
        l6 = ((vader_struct_toolchain_ast_BinaryExpr_t*) l1)->f_op == INT32_C(20);
    }
    if (!(l6)) {
        vader_array_t* _a0_arr = vader_array_new(214u, 2u, 0u, 1414u);
        vader_array_box_slots(_a0_arr->buf)[_a0_arr->offset + 1u] = l3;
        vader_array_box_slots(_a0_arr->buf)[_a0_arr->offset + 0u] = l2;
        l7 = (void*) _a0_arr;
        l8 = ((vader_struct_toolchain_ast_BinaryExpr_t*) l1)->f_span;
        l10 = ((vader_struct_toolchain_ast_BinaryExpr_t*) l1)->f_left;
        l11 = ((vader_struct_toolchain_ast_BinaryExpr_t*) l1)->f_right;
        vader_array_t* _a1_arr = vader_array_new(216u, 2u, 13u, 1457u);
        ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 1u] = l11.payload.obj;
        ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = l10.payload.obj;
        l9 = (void*) _a1_arr;
        t0 = vader_effects_call(l0, l4, l7, l8, l9);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a2_arr = vader_array_new(214u, 2u, 0u, 1414u);
    vader_array_box_slots(_a2_arr->buf)[_a2_arr->offset + 1u] = l2;
    vader_array_box_slots(_a2_arr->buf)[_a2_arr->offset + 0u] = l3;
    l7 = (void*) _a2_arr;
    l8 = ((vader_struct_toolchain_ast_BinaryExpr_t*) l1)->f_span;
    l2 = ((vader_struct_toolchain_ast_BinaryExpr_t*) l1)->f_right;
    l3 = ((vader_struct_toolchain_ast_BinaryExpr_t*) l1)->f_left;
    vader_array_t* _a3_arr = vader_array_new(216u, 2u, 13u, 1457u);
    ((void**) _a3_arr->buf->slots)[_a3_arr->offset + 1u] = l3.payload.obj;
    ((void**) _a3_arr->buf->slots)[_a3_arr->offset + 0u] = l2.payload.obj;
    l9 = (void*) _a3_arr;
    t0 = vader_effects_call(l0, l4, l7, l8, l9);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_effects_bind(void* l0, vader_box_t l1, vader_box_t l2) {
    void* l3 = NULL;
    int64_t l4, l5;
    vader_box_t l6 = vader_box_null(), l7 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[4] = { &l1, &l2, &l6, &l7 };
    void** gc_raw_roots[3] = { &l0, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l1.tag == 603u) {
        t0 = l1.payload.obj;
        l3 = ((vader_struct_toolchain_ast_SimpleBinding_t*) t0)->f_name_span;
        vader_effects_bind_symbol(l0, l3, l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 615u) {
        t0 = l1.payload.obj;
        l3 = ((vader_struct_toolchain_ast_TupleBinding_t*) t0)->f_elements;
        l4 = ((vader_array_t*) l3)->length;
        l5 = INT64_C(0);
        while ((l5 < l4)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            l6 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
            l7 = vader_effects_step_slot(l0, l2, 856u);
            vader_effects_bind(l0, l6, l7);
            l5 = (l5 + INT64_C(1));
        }
    } else if (l1.tag == 599u) {
        t0 = l1.payload.obj;
        l3 = ((vader_struct_toolchain_ast_RestBinding_t*) t0)->f_span;
        vader_effects_bind_symbol(l0, l3, l2);
    } else if (!(l1.tag == 620u)) {
        vader_unreachable("non-exhaustive match (T3013 should have caught this)");
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_effects_bind_copy(void* l0, int64_t l1, vader_box_t l2, void* l3, void* l4) {
    bool l5;
    int64_t l6;
    void* l7 = NULL;
    int32_t l8;
    vader_box_t l9 = vader_box_null();
    vader_string_t l10 = 0;
    bool t0;
    vader_box_t* gc_roots[2] = { &l2, &l9 };
    void** gc_raw_roots[4] = { &l0, &l3, &l4, &l7 };
    vader_string_t* gc_atom_roots[1] = { &l10 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l2.tag == 0u) {
        l5 = true;
    } else {
        l6 = ((int64_t) l2.payload.i);
        t0 = std_collections_MutableSet_std_core_Contains_contains__i64(((vader_struct_vader_effects_WalkCtx_t*) l0)->f_pure, l6);
        l5 = !(t0);
    }
    if (l5) {
        l7 = ((vader_struct_vader_effects_WalkCtx_t*) l0)->f_seen_names;
        l8 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l4)->f_id;
        std_collections_add__i32(l7, l8);
    }
    l9 = l2;
    if (l9.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l6 = ((int64_t) l9.payload.i);
    l6 = vader_effects_add_copy(((vader_struct_vader_effects_WalkCtx_t*) l0)->f_s, l1, l6);
    l10 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l4)->f_name;
    l8 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l4)->f_id;
    vader_struct_vader_effects_FrozenRoot_t* _a0_obj = (vader_struct_vader_effects_FrozenRoot_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_FrozenRoot_t));
    vader_obj_header_init(_a0_obj, 924u);
    _a0_obj->f_root = l6;
    _a0_obj->f_span = l3;
    _a0_obj->f_label = l10;
    _a0_obj->f_binding = vader_box_i32(291u, l8);
    _a0_obj->f_origin = (uint8_t) 0;
    _a0_obj->f_constant = vader_box_obj(0u, NULL);
    _a0_obj->f_type = vader_box_obj(0u, NULL);
    l7 = (void*) _a0_obj;
    vader_array_push((vader_array_t*) ((vader_struct_vader_effects_WalkCtx_t*) l0)->f_roots, vader_ref_box(l7));
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_effects_bind_pattern(void* l0, vader_box_t l1, vader_box_t l2) {
    vader_box_t l3 = vader_box_null();
    void* l4 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    int64_t l5, l6;
    vader_string_t l9 = 0;
    void* t0 = NULL;
    vader_box_t* gc_roots[3] = { &l1, &l2, &l3 };
    void** gc_raw_roots[5] = { &l0, &l4, &l7, &l8, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l9 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l1.tag == 581u) {
        t0 = l1.payload.obj;
        l3 = ((vader_struct_toolchain_ast_IsPattern_t*) t0)->f_inner;
        if (!(l3.tag == 0u)) {
            vader_effects_bind_pattern(l0, l3, l2);
        }
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 612u) {
        t0 = l1.payload.obj;
        l4 = ((vader_struct_toolchain_ast_StructPattern_t*) t0)->f_fields;
        l5 = ((vader_array_t*) l4)->length;
        l6 = INT64_C(0);
        while ((l6 < l5)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            l7 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l6);
            if (((vader_struct_toolchain_ast_StructPatternField_t*) l7)->f_value.tag == 593u) {
                l8 = ((vader_struct_toolchain_ast_StructPatternField_t*) l7)->f_name_span;
                l9 = ((vader_struct_toolchain_ast_StructPatternField_t*) l7)->f_name;
                l3 = vader_effects_step_slot(l0, l2, l9);
                vader_effects_bind_symbol(l0, l8, l3);
            }
            l6 = (l6 + INT64_C(1));
        }
    } else if (l1.tag == 592u) {
        t0 = l1.payload.obj;
        l4 = ((vader_struct_toolchain_ast_OrPattern_t*) t0)->f_patterns;
        l5 = ((vader_array_t*) l4)->length;
        l6 = INT64_C(0);
        while ((l6 < l5)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l4);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            l3 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l6);
            vader_effects_bind_pattern(l0, l3, l2);
            l6 = (l6 + INT64_C(1));
        }
    } else if (!((l1.tag == 560u || l1.tag == 584u || l1.tag == 598u || l1.tag == 622u))) {
        vader_unreachable("non-exhaustive match (T3013 should have caught this)");
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_effects_bind_symbol(void* l0, void* l1, vader_box_t l2) {
    void* l3 = NULL;
    uint64_t l4;
    vader_box_t l5 = vader_box_null();
    int32_t l6;
    int64_t l7;
    vader_box_t* gc_roots[2] = { &l2, &l5 };
    void** gc_raw_roots[3] = { &l0, &l1, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_resolver_ResolvedModule_t*) ((vader_struct_vader_typecheck_TypedProgram_t*) ((vader_struct_vader_effects_WalkCtx_t*) l0)->f_typed)->f_resolved)->f_idents;
    l4 = toolchain_span_Span_std_core_Hash_hash(l1);
    l5 = std_collections_MutableMap_std_core_Index_at__u64__Any(l3, l4);
    if (l5.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l3 = l5.payload.obj;
    l6 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l3)->f_id;
    l7 = vader_effects_local_slot(l0, l6);
    vader_effects_bind_copy(l0, l7, l2, l1, l3);
    { vader_gc_top = gc_frame.prev; return; }
}

static uint8_t vader_effects_binding_outcome(void* l0, void* l1, bool l2) {
    void* l3 = NULL;
    bool l4;
    int64_t l5, l6;
    bool t0;
    void* t1 = NULL;
    uint8_t t2;
    void** gc_raw_roots[4] = { &l0, &l1, &l3, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = (void*) &vader_fn_static_vader_effects_modifies;
    t0 = vader_effects_either(l1, l3);
    if (t0) {
        if (l2) {
            l3 = ((vader_struct_vader_effects_RootCase_t*) l1)->f_marked;
            l4 = false;
            l5 = ((vader_array_t*) l3)->length;
            l6 = INT64_C(0);
            {
                while ((l6 < l5)) {
                    vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
                    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
                    t1 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l6);
                    t0 = vader_effects_modifies(t1);
                    if (t0) {
                        l4 = true;
                        goto end_17;
                    }
                    l6 = (l6 + INT64_C(1));
                }
                l4 = false;
            } end_17: ;
            if (l4) {
                l3 = (void*) &vader_fn_static_vader_effects_escapes;
                t0 = vader_effects_either(l1, l3);
                if (!(t0)) {
                    { vader_gc_top = gc_frame.prev; return (uint8_t) 6; }
                }
                { vader_gc_top = gc_frame.prev; return (uint8_t) 3; }
            }
            { vader_gc_top = gc_frame.prev; return (uint8_t) 3; }
        }
        { vader_gc_top = gc_frame.prev; return (uint8_t) 3; }
    }
    l3 = (void*) &vader_fn_static_vader_effects_escapes;
    t0 = vader_effects_either(l1, l3);
    if (!(t0)) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 5; }
    }
    l3 = (void*) &vader_fn_static_vader_effects_escapes;
    t2 = vader_effects_copy_or_elided(l0, l1, l3);
    { uint8_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_effects_block_value(void* l0, void* l1) {
    void* l2 = NULL;
    int64_t l3, l4;
    vader_box_t l5 = vader_box_null(), l6 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l5, &l6, &t0 };
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_toolchain_ast_BlockExpr_t*) l1)->f_stmts;
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        l5 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        vader_effects_stmt(l0, l5);
        l4 = (l4 + INT64_C(1));
    }
    l6 = ((vader_struct_toolchain_ast_BlockExpr_t*) l1)->f_trailing;
    if (l6.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l5 = l6;
    t0 = vader_effects_value(l0, l5);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_effects_body_ctx(void* l0, void* l1, void* l2, void* l3) {
    void* l4 = NULL;
    int32_t l5;
    int32_t t0;
    void* t1 = NULL;
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l3, &l4, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 6u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_effects_FrozenBody_t*) l0)->f_node;
    if (!((t0 < INT32_C(0)))) {
        l5 = ((vader_struct_vader_effects_FrozenBody_t*) l0)->f_node;
        t1 = vader_effects_node_ctx(l1, l2, l3, l5);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a0_arr = vader_array_new(15u, 0u, 7u, 291u);
    l4 = (void*) _a0_arr;
    t1 = vader_effects_node_ctx(l1, l2, l4, INT32_C(0));
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_effects_bodyless_target(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void* l7 = NULL;
    int64_t l5, l6;
    vader_string_t l8 = 0;
    vader_box_t l9 = vader_box_null();
    bool l10;
    bool t0;
    void* t1 = NULL;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l9, &t2 };
    void** gc_raw_roots[7] = { &l0, &l1, &l2, &l3, &l4, &l7, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l8 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = toolchain_ast_decorators_have(((vader_struct_toolchain_ast_FnDecl_t*) l1)->f_decorators, 1778u);
    if (t0) {
        l3 = ((vader_struct_toolchain_ast_FnDecl_t*) l1)->f_params;
        vader_array_t* _a0_arr = vader_array_new(95u, 0u, 13u, 932u);
        l4 = (void*) _a0_arr;
        l5 = ((vader_array_t*) l3)->length;
        vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l4, (int64_t) l5);
        l4 = (void*) _a1_arr;
        l5 = ((vader_array_t*) l3)->length;
        l6 = INT64_C(0);
        while ((l6 < l5)) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            t1 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l6);
            l7 = vader_effects_foreign_effects(t1);
            vader_array_push((vader_array_t*) l4, vader_ref_box(l7));
            l6 = (l6 + INT64_C(1));
        }
        vader_struct_vader_effects_KnownEffects_t* _a3_obj = (vader_struct_vader_effects_KnownEffects_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_KnownEffects_t));
        vader_obj_header_init(_a3_obj, 929u);
        _a3_obj->f_params = l4;
        t1 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l8 = vader_effects_intrinsic_key(l0, l1, l2);
    t0 = vader_effects_makes_frozen_view(l8);
    if (t0) {
        l3 = ((vader_struct_vader_effects_CalleeIndex_t*) l0)->f_frozen_views;
        l5 = ((vader_struct_toolchain_ast_FnDecl_t*) l1)->f_id;
        std_collections_add__i64(l3, l5);
        l3 = ((vader_struct_toolchain_ast_FnDecl_t*) l1)->f_name_span;
        t2 = vader_typecheck_declared_type_at(l2, l3);
        l9 = vader_effects_returned_array(t2);
        ((vader_struct_vader_effects_CalleeIndex_t*) l0)->f_view = l9;
        VADER_WRITE_BARRIER((vader_struct_vader_effects_CalleeIndex_t*) l0);
    }
    l9 = vader_effects_intrinsic_effects(((vader_struct_vader_effects_CalleeIndex_t*) l0)->f_paths, l8);
    if (!(l9.tag == 0u)) {
        t1 = l9.payload.obj;
        vader_struct_vader_effects_KnownEffects_t* _a4_obj = (vader_struct_vader_effects_KnownEffects_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_KnownEffects_t));
        vader_obj_header_init(_a4_obj, 929u);
        _a4_obj->f_params = t1;
        t1 = (void*) _a4_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = ((vader_struct_toolchain_ast_FnDecl_t*) l1)->f_params;
    vader_struct___lambda_env_vader_effects_13_t* _a5_obj = (vader_struct___lambda_env_vader_effects_13_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_effects_13_t));
    vader_obj_header_init(_a5_obj, 317u);
    _a5_obj->f_cap_0 = l2;
    l4 = (void*) _a5_obj;
    l10 = false;
    l5 = ((vader_array_t*) l3)->length;
    l6 = INT64_C(0);
    {
        for (;;) {
            if ((l6 < l5)) {
                vader_array_t* _a6_slotarr = ((vader_array_t*) l3);
                VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
                l7 = vader_array_ref_load_obj(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l6);
                t0 = __lambda_vader_effects_12(l4, l7);
                if (t0) {
                    l6 = (l6 + INT64_C(1));
                    continue;
                }
                l10 = false;
                goto end_95;
            }
            break;
        }
        l10 = true;
    } end_95: ;
    if (!(l10)) {
        vader_array_push((vader_array_t*) ((vader_struct_vader_effects_CalleeIndex_t*) l0)->f_unknown, vader_box_string(288u, l8));
        vader_struct_vader_effects_AnyCallee_t* _a7_obj = (vader_struct_vader_effects_AnyCallee_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_AnyCallee_t));
        vader_obj_header_init(_a7_obj, 912u);
        t1 = (void*) _a7_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = ((vader_struct_toolchain_ast_FnDecl_t*) l1)->f_params;
    vader_array_t* _a8_arr = vader_array_new(95u, 0u, 13u, 932u);
    l4 = (void*) _a8_arr;
    l5 = ((vader_array_t*) l3)->length;
    vader_array_t* _a9_arr = vader_array_repeat((vader_array_t*) l4, (int64_t) l5);
    l4 = (void*) _a9_arr;
    l5 = ((vader_array_t*) l3)->length;
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a10_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
        t1 = vader_array_ref_load_obj(_a10_slotarr->buf, _a10_slotarr->offset + (size_t) l6);
        l7 = __lambda_vader_effects_14(t1);
        vader_array_push((vader_array_t*) l4, vader_ref_box(l7));
        l6 = (l6 + INT64_C(1));
    }
    vader_struct_vader_effects_KnownEffects_t* _a11_obj = (vader_struct_vader_effects_KnownEffects_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_KnownEffects_t));
    vader_obj_header_init(_a11_obj, 929u);
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

static vader_box_t vader_effects_call(void* l0, vader_box_t l1, void* l2, void* l3, void* l4) {
    vader_box_t l5 = vader_box_null(), l9 = vader_box_null(), l10 = vader_box_null();
    void* l6 = NULL;
    int64_t l7, l8;
    int64_t t0;
    vader_box_t* gc_roots[4] = { &l1, &l5, &l9, &l10 };
    void** gc_raw_roots[5] = { &l0, &l2, &l3, &l4, &l6 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l5 = l1;
    if (l5.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l6 = vader_effects_targets_of(((vader_struct_vader_effects_WalkCtx_t*) l0)->f_index, l5);
    t0 = ((vader_array_t*) l6)->length;
    if (t0 == INT64_C(0)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l7 = INT64_C(0);
    l8 = ((vader_array_t*) l4)->length;
    while ((l7 < l8)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l10 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l7);
        if (l10.tag == 0u) {
            l7 = (l7 + INT64_C(1));
            continue;
        }
        l9 = l10;
        vader_effects_note_known_writes(l0, l6, l7, l9);
        vader_effects_note_widened(l0, l5, l6, l7, l9);
        l7 = (l7 + INT64_C(1));
    }
    t0 = vader_effects_add_site(((vader_struct_vader_effects_WalkCtx_t*) l0)->f_s, l6, l2, l5, l3);
    { vader_box_t __vret = vader_box_i64(292u, t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static int64_t vader_effects_call_origin(int64_t l0, int64_t l1, int64_t l2) {
    int64_t l3, l4;
    l3 = (l0 << INT64_C(32));
    l4 = (l1 << INT64_C(16));
    return ((l3 | l4) | l2);
}

static void* vader_effects_call_sources(void* l0, void* l1, vader_box_t l2) {
    void* l3 = NULL;
    void* l5 = NULL;
    vader_box_t l4 = vader_box_null(), l6 = vader_box_null();
    int64_t l7, l8;
    bool t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[3] = { &l2, &l4, &l6 };
    void** gc_raw_roots[5] = { &l0, &l1, &l3, &l5, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(217u, 0u, 13u, 1458u);
    l3 = (void*) _a0_arr;
    l4 = ((vader_struct_toolchain_ast_CallExpr_t*) l1)->f_callee;
    if (l4.tag == 562u) {
        l5 = l4.payload.obj;
        t0 = vader_effects_passes_receiver(l0, l1, l5, l2);
        if (t0) {
            t1 = l4.payload.obj;
            l6 = ((vader_struct_toolchain_ast_FieldExpr_t*) t1)->f_target;
            vader_array_push((vader_array_t*) l3, l6);
        } else {
            t1 = l4.payload.obj;
            l4 = ((vader_struct_toolchain_ast_FieldExpr_t*) t1)->f_target;
            vader_effects_discard(l0, l4);
        }
    } else {
        l4 = ((vader_struct_toolchain_ast_CallExpr_t*) l1)->f_callee;
        vader_effects_discard(l0, l4);
    }
    l5 = ((vader_struct_toolchain_ast_CallExpr_t*) l1)->f_args;
    l7 = ((vader_array_t*) l5)->length;
    l8 = INT64_C(0);
    while ((l8 < l7)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        t1 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l8);
        l4 = ((vader_struct_toolchain_ast_CallArg_t*) t1)->f_value;
        vader_array_push((vader_array_t*) l3, l4);
        l8 = (l8 + INT64_C(1));
    }
    { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_effects_call_value(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l4 = vader_box_null(), l9 = vader_box_null(), l10 = vader_box_null();
    int64_t l3, l8;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[5] = { &l2, &l4, &l9, &l10, &t1 };
    void** gc_raw_roots[6] = { &l0, &l1, &l5, &l6, &l7, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 5u, 6u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_toolchain_ast_CallExpr_t*) l1)->f_id;
    l4 = vader_effects_site_callee(l0, (uint8_t) 0, l3);
    if (l4.tag == 0u) {
        vader_struct_vader_typecheck_UnsettledCallee_t* _a0_obj = (vader_struct_vader_typecheck_UnsettledCallee_t*) vader_gc_alloc(sizeof(vader_struct_vader_typecheck_UnsettledCallee_t));
        vader_obj_header_init(_a0_obj, 1258u);
        t0 = (void*) _a0_obj;
        l2 = vader_ref_box(t0);
    } else {
        l2 = l4;
    }
    l5 = vader_effects_call_sources(l0, l1, l2);
    vader_array_t* _a1_arr = vader_array_new(214u, 0u, 0u, 1414u);
    l6 = (void*) _a1_arr;
    l3 = ((vader_array_t*) l5)->length;
    vader_array_t* _a2_arr = vader_array_repeat((vader_array_t*) l6, (int64_t) l3);
    l6 = (void*) _a2_arr;
    l7 = l5;
    l3 = ((vader_array_t*) l7)->length;
    l8 = INT64_C(0);
    while ((l8 < l3)) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l8)
        l4 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l8);
        l9 = vader_effects_value(l0, l4);
        vader_array_push((vader_array_t*) l6, l9);
        l8 = (l8 + INT64_C(1));
    }
    if (!(l2.tag == 1198u)) {
        l9 = l2;
        l7 = ((vader_struct_toolchain_ast_CallExpr_t*) l1)->f_span;
        l9 = vader_effects_call(l0, l9, l6, l7, l5);
        l10 = l2;
        l10 = vader_effects_frozen_view(l0, l1, l10);
        vader_array_t* _a4_arr = vader_array_new(214u, 2u, 0u, 1414u);
        vader_array_box_slots(_a4_arr->buf)[_a4_arr->offset + 1u] = l10;
        vader_array_box_slots(_a4_arr->buf)[_a4_arr->offset + 0u] = l9;
        l7 = (void*) _a4_arr;
        t1 = vader_effects_union_of(l0, l7);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = vader_effects_single(l6);
    l4 = vader_effects_frozen_variant_data(l0, l1);
    vader_array_t* _a5_arr = vader_array_new(214u, 2u, 0u, 1414u);
    vader_array_box_slots(_a5_arr->buf)[_a5_arr->offset + 1u] = l4;
    vader_array_box_slots(_a5_arr->buf)[_a5_arr->offset + 0u] = l2;
    l5 = (void*) _a5_arr;
    t1 = vader_effects_union_of(l0, l5);
    { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_effects_callee_nodes(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l5 = NULL;
    int64_t l3, l4, l6, l7;
    vader_box_t l8 = vader_box_null();
    int32_t l9;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l8 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l5, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(15u, 0u, 7u, 291u);
    l1 = (void*) _a0_arr;
    l2 = ((vader_struct_vader_effects_Skeleton_t*) l0)->f_sites;
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
        l5 = ((vader_struct_vader_effects_Site_t*) t0)->f_targets;
        l6 = ((vader_array_t*) l5)->length;
        l7 = INT64_C(0);
        vader_array_t* _pc22_hdr = (vader_array_t*) l1;
        size_t _pc22_len = _pc22_hdr->length;
        size_t _pc22_cap = (_pc22_hdr->offset == 0 && !vader_array_is_borrowed(_pc22_hdr) && _pc22_hdr->length >= _pc22_hdr->buf->length) ? _pc22_hdr->capacity : (size_t) 0;
        void* _pc22_slots = _pc22_hdr->buf->slots;
        for (;;) {
            if ((l7 < l6)) {
                vader_array_t* _a2_slotarr = ((vader_array_t*) l5);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                l8 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l7);
                if (l8.tag == 914u) {
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
                l7 = (l7 + INT64_C(1));
                continue;
            }
            _pc22_hdr->length = _pc22_len;
            if (_pc22_hdr->buf->length < _pc22_len) {
                _pc22_hdr->buf->length = _pc22_len;
            }
            break;
        }
        l4 = (l4 + INT64_C(1));
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_effects_callers_of(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l8 = NULL;
    int64_t l5, l6, l10, l11;
    int32_t l7, l12;
    bool l9;
    void* t0 = NULL;
    bool t1;
    void** gc_raw_roots[7] = { &l0, &l1, &l2, &l3, &l4, &l8, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 7u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(15u, 0u, 7u, 291u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(12u, 0u, 12u, 286u);
    l3 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(15u, 0u, 7u, 291u);
    l4 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__i32__bool_t* _a3_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
    vader_obj_header_init(_a3_obj, 385u);
    _a3_obj->f_ekeys = l2;
    _a3_obj->f_evals = l3;
    _a3_obj->f_index = l4;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a3_obj;
    vader_struct_std_collections_MutableSet__i32_t* _a4_obj = (vader_struct_std_collections_MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i32_t));
    vader_obj_header_init(_a4_obj, 522u);
    _a4_obj->f_inner = t0;
    l2 = (void*) _a4_obj;
    l3 = l1;
    l5 = ((vader_array_t*) l3)->length;
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a5_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        l7 = ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l6];
        std_collections_add__i32(l2, l7);
        l6 = (l6 + INT64_C(1));
    }
    vader_array_t* _a6_arr = vader_array_new(15u, 0u, 7u, 291u);
    l3 = (void*) _a6_arr;
    l5 = INT64_C(0);
    l6 = ((vader_array_t*) l0)->length;
    while ((l5 < l6)) {
        vader_array_t* _a7_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
        l4 = vader_array_ref_load_obj(_a7_slotarr->buf, _a7_slotarr->offset + (size_t) l5);
        vader_struct___lambda_env_vader_effects_8_t* _a8_obj = (vader_struct___lambda_env_vader_effects_8_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_effects_8_t));
        vader_obj_header_init(_a8_obj, 331u);
        _a8_obj->f_cap_0 = l2;
        l8 = (void*) _a8_obj;
        l9 = false;
        l10 = ((vader_array_t*) l4)->length;
        l11 = INT64_C(0);
        {
            while ((l11 < l10)) {
                vader_array_t* _a9_slotarr = ((vader_array_t*) l4);
                VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
                l7 = ((int32_t*) _a9_slotarr->buf->slots)[_a9_slotarr->offset + (size_t) l11];
                t1 = __lambda_vader_effects_7(l8, l7);
                if (t1) {
                    l9 = true;
                    goto end_67;
                }
                l11 = (l11 + INT64_C(1));
            }
            l9 = false;
        } end_67: ;
        if (l9) {
            l12 = ((int32_t) (int64_t) l5);
            vader_array_push_i32((vader_array_t*) l3, l12);
        }
        l5 = (l5 + INT64_C(1));
    }
    { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_effects_carried(void* l0, void* l1, void* l2) {
    int32_t l3, l4;
    void* t0 = NULL;
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_effects_Root_t*) l0)->f_path;
    l4 = ((vader_struct_vader_effects_Flow_t*) l1)->f_path;
    l3 = vader_effects_joined(l2, l3, l4);
    t0 = vader_effects_at_path(l0, l3);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static int64_t vader_effects_carried_at(void* l0, int64_t l1) {
    void* l2;
    int64_t l3;
    int64_t t0;
    l2 = ((vader_struct_vader_effects_ParamEffects_t*) l0)->f_origins;
    t0 = vader_chk_mul(i64, INT64_C(2), l1);
    l3 = vader_chk_add(i64, t0, INT64_C(1));
    vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
    t0 = ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
    return t0;
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
            if (t3 != 856u) {
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
    return vader_box_i32(291u, l3);
}

static int32_t vader_effects_child(void* l0, int32_t l1, int32_t l2) {
    void* l3 = NULL;
    void* l7 = NULL;
    int64_t l4;
    vader_box_t l5 = vader_box_null();
    int32_t l6, l8;
    bool t0;
    int32_t t1;
    int64_t t2;
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
    l5 = std_collections_MutableMap_std_core_Index_at__i64__i32(((vader_struct_vader_effects_PathTable_t*) l0)->f_children, l4);
    if (!(l5.tag == 0u)) {
        t1 = ((int32_t) l5.payload.i);
        { int32_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = ((vader_array_t*) ((vader_struct_vader_effects_PathTable_t*) l0)->f_nodes)->length;
    l6 = ((int32_t) (int64_t) t2);
    l7 = ((vader_struct_vader_effects_PathTable_t*) l0)->f_nodes;
    t1 = ((vader_struct_vader_effects_PathNode_t*) l3)->f_length;
    l8 = vader_chk_add(i32, t1, INT32_C(1));
    vader_struct_vader_effects_PathNode_t* _a1_obj = (vader_struct_vader_effects_PathNode_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_PathNode_t));
    vader_obj_header_init(_a1_obj, 933u);
    _a1_obj->f_parent = l1;
    _a1_obj->f_step = l2;
    _a1_obj->f_length = l8;
    _a1_obj->f_deeper = false;
    _a1_obj->f_cut = vader_box_obj(0u, NULL);
    l3 = (void*) _a1_obj;
    vader_array_push((vader_array_t*) l7, vader_ref_box(l3));
    std_collections_MutableMap_std_core_IndexSet_set_at__i64__i32(((vader_struct_vader_effects_PathTable_t*) l0)->f_children, l4, l6);
    { int32_t __vret = l6; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_effects_collect_returned(void* l0, void* l1, void* l2, void* l3) {
    bool l4, l11;
    void* l5 = NULL;
    void* l9 = NULL;
    void* l19 = NULL;
    void* l20 = NULL;
    void* l23 = NULL;
    void* l26 = NULL;
    int64_t l6, l7, l12, l13, l14, l16, l17, l18, l21, l22, l25;
    vader_box_t l8 = vader_box_null(), l10 = vader_box_null(), l15 = vader_box_null();
    int32_t l24;
    int64_t t0;
    bool t1;
    vader_box_t* gc_roots[3] = { &l8, &l10, &l15 };
    void** gc_raw_roots[10] = { &l0, &l1, &l2, &l3, &l5, &l9, &l19, &l20, &l23, &l26 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 10u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l4 = false;
    l5 = ((vader_struct_vader_effects_Site_t*) l1)->f_targets;
    l6 = ((vader_array_t*) l5)->length;
    l7 = INT64_C(0);
    while ((l7 < l6)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l8 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l7);
        l9 = ((vader_struct_vader_effects_EvalCtx_t*) l2)->f_facts;
        l10 = vader_effects_known_params(l8, l9);
        l11 = vader_effects_recursive(l2, l8);
        l12 = INT64_C(0);
        l13 = ((vader_array_t*) ((vader_struct_vader_effects_Site_t*) l1)->f_args)->length;
        while ((l12 < l13)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_effects_Site_t*) l1)->f_args);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l12)
            l15 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l12];
            if (l15.tag == 0u) {
                l12 = (l12 + INT64_C(1));
                continue;
            }
            l14 = ((int64_t) l15.payload.i);
            t0 = ((vader_struct_vader_effects_Site_t*) l1)->f_first_argument;
            l16 = vader_chk_add(i64, t0, l12);
            vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l16)
            l17 = ((int64_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l16];
            l18 = vader_effects_held_count(l0, l14);
            if (l17 == l18) {
                l12 = (l12 + INT64_C(1));
                continue;
            }
            l19 = ((vader_struct_vader_effects_EvalCtx_t*) l2)->f_any;
            l20 = vader_effects_accesses_of_param(l10, l12, l19);
            l21 = ((vader_array_t*) l20)->length;
            l22 = INT64_C(0);
            while ((l22 < l21)) {
                vader_array_t* _a3_slotarr = ((vader_array_t*) l20);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                l23 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l22);
                if (((vader_struct_vader_effects_Access_t*) l23)->f_effect != INT32_C(4)) {
                    l22 = (l22 + INT64_C(1));
                    continue;
                }
                l24 = ((vader_struct_vader_effects_Access_t*) l23)->f_path;
                l25 = ((vader_struct_vader_effects_Site_t*) l1)->f_result;
                l26 = ((vader_struct_vader_effects_EvalCtx_t*) l2)->f_paths;
                t1 = vader_effects_reroot_below(l0, l14, l17, l18, l24, l25, l26, l11);
                if (t1) {
                    l4 = true;
                }
                l22 = (l22 + INT64_C(1));
            }
            l12 = (l12 + INT64_C(1));
        }
        l7 = (l7 + INT64_C(1));
    }
    l6 = INT64_C(0);
    l7 = ((vader_array_t*) ((vader_struct_vader_effects_Site_t*) l1)->f_args)->length;
    while ((l6 < l7)) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_vader_effects_Site_t*) l1)->f_args);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l6)
        l8 = vader_array_box_slots(_a4_slotarr->buf)[_a4_slotarr->offset + (size_t) l6];
        if (l8.tag == 0u) {
            l6 = (l6 + INT64_C(1));
            continue;
        }
        l12 = ((int64_t) l8.payload.i);
        t0 = ((vader_struct_vader_effects_Site_t*) l1)->f_first_argument;
        l13 = vader_chk_add(i64, t0, l6);
        l14 = vader_effects_held_count(l0, l12);
        vader_array_t* _a5_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l13)
        ((int64_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l13] = (int64_t) l14;
        l6 = (l6 + INT64_C(1));
    }
    { bool __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
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

static void* vader_effects_constant_initialiser(void* l0, void* l1, void* l2) {
    vader_box_t l3 = vader_box_null();
    int32_t l4;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l3 };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_toolchain_ast_ConstDecl_t*) l0)->f_value;
    l4 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l1)->f_id;
    vader_struct_vader_effects_Initialiser_t* _a0_obj = (vader_struct_vader_effects_Initialiser_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_Initialiser_t));
    vader_obj_header_init(_a0_obj, 928u);
    _a0_obj->f_value = l3;
    _a0_obj->f_typed = l2;
    _a0_obj->f_initialises = vader_box_i32(291u, l4);
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static int64_t vader_effects_constraint_at(void* l0, int64_t l1) {
    void* l2;
    int64_t l3;
    int64_t t0;
    l2 = ((vader_struct_vader_effects_ParamEffects_t*) l0)->f_origins;
    l3 = vader_chk_mul(i64, INT64_C(2), l1);
    vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
    t0 = ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
    return t0;
}

static vader_box_t vader_effects_converted(void* l0, vader_box_t l1, vader_box_t l2) {
    int64_t l3;
    vader_box_t l4 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[4] = { &l1, &l2, &l4, &t0 };
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = VADER_UNION_FIELD(int64_t, vader_struct_toolchain_ast_ArrayTypeExpr_t, f_id, l1.payload.obj);
    l4 = vader_effects_site_callee(l0, (uint8_t) 4, l3);
    t0 = vader_effects_converted_by(l0, l4, l2, l1);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_effects_converted_by(void* l0, vader_box_t l1, vader_box_t l2, vader_box_t l3) {
    vader_box_t l4 = vader_box_null();
    void* l5 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    int64_t t0;
    vader_box_t* gc_roots[4] = { &l1, &l2, &l3, &l4 };
    void** gc_raw_roots[4] = { &l0, &l5, &l6, &l7 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l4 = l1;
    if (l4.tag == 0u) {
        { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a0_arr = vader_array_new(214u, 1u, 0u, 1414u);
    vader_array_box_slots(_a0_arr->buf)[_a0_arr->offset + 0u] = l2;
    l5 = (void*) _a0_arr;
    l6 = VADER_UNION_FIELD(void*, vader_struct_toolchain_ast_ArrayTypeExpr_t, f_span, l3.payload.obj);
    vader_array_t* _a1_arr = vader_array_new(216u, 1u, 13u, 1457u);
    ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = l3.payload.obj;
    l7 = (void*) _a1_arr;
    l4 = vader_effects_call(l0, l4, l5, l6, l7);
    if (!(l4.tag == 0u)) {
        t0 = ((int64_t) l4.payload.i);
        { vader_box_t __vret = vader_box_i64(292u, t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_effects_copy_hint(void* l0, vader_string_t l1) {
    uint8_t l2;
    bool l3;
    vader_string_t t0 = 0;
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[2] = { &l1, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_effects_FrozenSite_t*) l0)->f_origin;
    if (l2 == INT32_C(0)) {
        l3 = true;
    } else {
        l3 = l2 == INT32_C(2);
    }
    if (l3) {
        t0 = concat_2(1339u, l1);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l2 == INT32_C(1))) {
        vader_unreachable("non-exhaustive match (T3013 should have caught this)");
    }
    t0 = concat_2(1186u, l1);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
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
    vader_array_t* _a0_arr = vader_array_new(95u, 5u, 13u, 932u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 4u] = l5;
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 3u] = l4;
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 2u] = l3;
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 1u] = l2;
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = l1;
    t0 = (void*) _a0_arr;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_effects_covered(void* l0, void* l1, int32_t l2, uint8_t l3) {
    int64_t l4;
    void* l5;
    void* l8;
    vader_box_t l6;
    int32_t l7;
    vader_box_t t0;
    bool t1;
    int32_t t2;
    l4 = vader_effects_key_of(l2, l3);
    l6 = ((vader_struct_vader_effects_ParamEffects_t*) l1)->f_keys;
    if (l6.tag == 0u) {
        t0 = vader_effects_find_access(l0, l1, l4);
        return !(t0.tag == 0u);
    }
    l5 = l6.payload.obj;
    t1 = std_collections_MutableSet_std_core_Contains_contains__i64(l5, l4);
    if (t1) {
        return true;
    }
    l7 = l2;
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_effects_PathTable_t*) l0)->f_nodes);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l7)
        l8 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l7);
        l6 = ((vader_struct_vader_effects_PathNode_t*) l8)->f_cut;
        if (!(l6.tag == 0u)) {
            t2 = ((int32_t) l6.payload.i);
            l4 = vader_effects_key_of(t2, l3);
            t1 = std_collections_MutableSet_std_core_Contains_contains__i64(l5, l4);
            if (t1) {
                return true;
            }
        }
        t2 = ((vader_struct_vader_effects_PathNode_t*) l8)->f_length;
        if (t2 == INT32_C(0)) {
            return false;
        }
        l7 = ((vader_struct_vader_effects_PathNode_t*) l8)->f_parent;
        continue;
    }
}

static bool vader_effects_covers(void* l0, void* l1, void* l2) {
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

static bool vader_effects_covers_key(void* l0, void* l1, int64_t l2) {
    int32_t l3, l7;
    int64_t l4, l5;
    void* l6;
    int64_t t0;
    int32_t t1;
    void* t2;
    bool t3;
    t0 = vader_div_i64(l2, INT64_C(8));
    l3 = ((int32_t) (int64_t) t0);
    l4 = ((int64_t) (uint8_t) ((vader_struct_vader_effects_Access_t*) l1)->f_effect);
    l5 = vader_mod_i64(l2, INT64_C(8));
    if (l4 != l5) {
        return false;
    }
    t1 = ((vader_struct_vader_effects_Access_t*) l1)->f_path;
    if (t1 == l3) {
        return false;
    }
    l6 = ((vader_struct_vader_effects_PathTable_t*) l0)->f_nodes;
    l7 = ((vader_struct_vader_effects_Access_t*) l1)->f_path;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l6);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l7)
    t2 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l7);
    t3 = ((vader_struct_vader_effects_PathNode_t*) t2)->f_deeper;
    if (t3) {
        l7 = ((vader_struct_vader_effects_Access_t*) l1)->f_path;
        t3 = vader_effects_extends(l0, l3, l7);
        return t3;
    }
    return false;
}

static int32_t vader_effects_cut(void* l0, int32_t l1) {
    void* l2 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    vader_box_t l3 = vader_box_null();
    int32_t l4, l7, l8, l9;
    bool t0;
    int32_t t1;
    int64_t t2;
    vader_box_t* gc_roots[1] = { &l3 };
    void** gc_raw_roots[4] = { &l0, &l2, &l5, &l6 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_effects_PathTable_t*) l0)->f_nodes);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    l2 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l1);
    t0 = ((vader_struct_vader_effects_PathNode_t*) l2)->f_deeper;
    if (t0) {
        { int32_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = ((vader_struct_vader_effects_PathNode_t*) l2)->f_cut;
    if (!(l3.tag == 0u)) {
        t1 = ((int32_t) l3.payload.i);
        { int32_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = ((vader_array_t*) ((vader_struct_vader_effects_PathTable_t*) l0)->f_nodes)->length;
    l4 = ((int32_t) (int64_t) t2);
    l5 = ((vader_struct_vader_effects_PathTable_t*) l0)->f_nodes;
    l6 = l2;
    l7 = ((vader_struct_vader_effects_PathNode_t*) l6)->f_parent;
    l8 = ((vader_struct_vader_effects_PathNode_t*) l6)->f_step;
    l9 = ((vader_struct_vader_effects_PathNode_t*) l6)->f_length;
    l3 = ((vader_struct_vader_effects_PathNode_t*) l6)->f_cut;
    vader_struct_vader_effects_PathNode_t* _a1_obj = (vader_struct_vader_effects_PathNode_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_PathNode_t));
    vader_obj_header_init(_a1_obj, 933u);
    _a1_obj->f_parent = l7;
    _a1_obj->f_step = l8;
    _a1_obj->f_length = l9;
    _a1_obj->f_deeper = true;
    _a1_obj->f_cut = l3;
    l6 = (void*) _a1_obj;
    vader_array_push((vader_array_t*) l5, vader_ref_box(l6));
    ((vader_struct_vader_effects_PathNode_t*) l2)->f_cut = vader_box_i32(291u, l4);
    VADER_WRITE_BARRIER((vader_struct_vader_effects_PathNode_t*) l2);
    { int32_t __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_effects_decide(void* l0, void* l1, void* l2, void* l3, void* l4) {
    void* l5 = NULL;
    void* l7 = NULL;
    void* l10 = NULL;
    vader_box_t l6 = vader_box_null();
    bool l8, l15;
    uint8_t l9, l13;
    vader_string_t l11 = 0;
    vader_string_t l12 = 0;
    int64_t l14, l16, l17;
    bool t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &l6 };
    void** gc_raw_roots[9] = { &l0, &l1, &l2, &l3, &l4, &l5, &l7, &l10, &t1 };
    vader_string_t* gc_atom_roots[2] = { &l11, &l12 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 9u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l5 = ((vader_struct_vader_effects_CalleeIndex_t*) ((vader_struct_vader_effects_TraceCtx_t*) l4)->f_index)->f_paths;
    l6 = vader_effects_root_case(l1, l2, l3, l5);
    if (l6.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l5 = l6.payload.obj;
    vader_effects_note_kept_by_constant(l0, l5, l2);
    l7 = vader_effects_named_use(l5);
    l8 = vader_effects_is_view(l7);
    l6 = vader_effects_outcome(l0, l5, l2, l8);
    if (l6.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l9 = ((uint8_t) l6.payload.i);
    l10 = ((vader_struct_vader_effects_FrozenRoot_t*) l2)->f_span;
    l11 = ((vader_struct_vader_resolver_ResolvedModule_t*) ((vader_struct_vader_typecheck_TypedProgram_t*) ((vader_struct_vader_effects_FrozenBody_t*) l1)->f_typed)->f_resolved)->f_display_path;
    l12 = ((vader_struct_vader_effects_FrozenRoot_t*) l7)->f_label;
    l13 = ((vader_struct_vader_effects_FrozenRoot_t*) l7)->f_origin;
    l7 = ((vader_struct_vader_effects_RootEffects_t*) l3)->f_mixed;
    l14 = ((vader_struct_vader_effects_FrozenRoot_t*) l2)->f_root;
    l15 = std_collections_MutableSet_std_core_Contains_contains__i64(l7, l14);
    l6 = vader_effects_fault_chain(l4, l1, l2, l3, l9, l8);
    vader_struct_vader_effects_FrozenSite_t* _a0_obj = (vader_struct_vader_effects_FrozenSite_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_FrozenSite_t));
    vader_obj_header_init(_a0_obj, 925u);
    _a0_obj->f_span = l10;
    _a0_obj->f_module = l11;
    _a0_obj->f_kind = l9;
    _a0_obj->f_root = l12;
    _a0_obj->f_origin = l13;
    _a0_obj->f_mixed = l15;
    _a0_obj->f_chain = l6;
    l7 = (void*) _a0_obj;
    vader_array_push((vader_array_t*) ((vader_struct_vader_effects_FrozenSites_t*) l0)->f_sites, vader_ref_box(l7));
    t0 = vader_effects_reads_fresh(l0, l5, l9);
    if (t0) {
        l5 = ((vader_struct_vader_effects_RootCase_t*) l5)->f_held;
        l14 = ((vader_array_t*) l5)->length;
        l16 = INT64_C(0);
        while ((l16 < l14)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            t1 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l16);
            l17 = ((vader_struct_vader_effects_Root_t*) t1)->f_param;
            l7 = vader_effects_root_record(l1, l17);
            vader_effects_read_fresh(l0, l7);
            l16 = (l16 + INT64_C(1));
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
    if (l2.tag == 552u) {
        t0 = l3.payload.obj;
        l4 = ((vader_struct_toolchain_ast_DeferStmtBody_t*) t0)->f_stmt;
        vader_effects_stmt(l0, l4);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (!(l2.tag == 550u)) {
        vader_unreachable("non-exhaustive match (T3013 should have caught this)");
    }
    t0 = l3.payload.obj;
    l5 = ((vader_struct_toolchain_ast_DeferBlockBody_t*) t0)->f_block;
    vader_effects_block_value(l0, l5);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_effects_destructure_assign(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l6 = vader_box_null(), l7 = vader_box_null(), l8 = vader_box_null(), l9 = vader_box_null(), l10 = vader_box_null(), l11 = vader_box_null();
    void* l3 = NULL;
    int64_t l4, l5;
    void* t0 = NULL;
    vader_box_t* gc_roots[7] = { &l2, &l6, &l7, &l8, &l9, &l10, &l11 };
    void** gc_raw_roots[4] = { &l0, &l1, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 7u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_toolchain_ast_DestructureAssignStmt_t*) l1)->f_value;
    l2 = vader_effects_value(l0, l2);
    l3 = ((vader_struct_toolchain_ast_DestructureAssignStmt_t*) l1)->f_targets;
    l4 = ((vader_array_t*) l3)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
        l6 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
        if (l6.tag == 595u) {
            t0 = l6.payload.obj;
            l7 = ((vader_struct_toolchain_ast_PlaceTarget_t*) t0)->f_place;
            vader_effects_note_place(l0, l7);
            t0 = l6.payload.obj;
            l8 = ((vader_struct_toolchain_ast_PlaceTarget_t*) t0)->f_place;
            l9 = vader_effects_step_slot(l0, l2, 856u);
            vader_effects_assign(l0, l8, l9);
        } else if (l6.tag == 600u) {
            t0 = l6.payload.obj;
            l10 = ((vader_struct_toolchain_ast_RestTarget_t*) t0)->f_place;
            vader_effects_note_place(l0, l10);
            t0 = l6.payload.obj;
            l11 = ((vader_struct_toolchain_ast_RestTarget_t*) t0)->f_place;
            vader_effects_assign(l0, l11, l2);
        } else if (!(l6.tag == 623u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l5 = (l5 + INT64_C(1));
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
        vader_array_t* _a0_arr = vader_array_new(238u, 1u, 13u, 1666u);
        ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = l3.payload.obj;
        t1 = (void*) _a0_arr;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = ((vader_struct_vader_effects_CalleeIndex_t*) l0)->f_impls;
    l5 = ((vader_struct_vader_typecheck_DirectFn_t*) l1)->f_decl;
    l6 = vader_typecheck_member_entry(l4, l5);
    if (l6.tag == 0u) {
        vader_array_t* _a1_arr = vader_array_new(238u, 1u, 13u, 1666u);
        ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = l3.payload.obj;
        t1 = (void*) _a1_arr;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = l6.payload.obj;
    vader_array_t* _a2_arr = vader_array_new(238u, 1u, 13u, 1666u);
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
    if (l0.tag == 1209u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_toolchain_ast_FnDecl_t*) ((vader_struct_vader_typecheck_DirectFn_t*) t0)->f_decl)->f_name;
        l1 = concat_3(924u, l1, 924u);
        { vader_string_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1196u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_typecheck_BoundMember_t*) t0)->f_member;
        l1 = concat_3(924u, l2, 924u);
    } else if (l0.tag == 1250u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_typecheck_TraitMember_t*) t0)->f_member;
        l1 = concat_3(924u, l2, 924u);
    } else if (l0.tag == 1219u) {
        l1 = 1328u;
    } else {
        if (!((l0.tag == 1198u || l0.tag == 1211u || l0.tag == 1214u || l0.tag == 1258u))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = 2510u;
    }
    { vader_string_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_effects_display_path(void* l0, int32_t l1) {
    void* t0 = NULL;
    bool t1;
    vader_string_t t2 = 0;
    vader_string_t t3 = 0;
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_string_t* gc_atom_roots[2] = { &t2, &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_effects_PathTable_t*) l0)->f_nodes);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l1);
    t1 = ((vader_struct_vader_effects_PathNode_t*) t0)->f_deeper;
    if (!(t1)) {
        t2 = vader_effects_display_steps(l0, l1);
        { vader_string_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = vader_effects_display_steps(l0, l1);
    t3 = concat_2(t2, 2861u);
    { vader_string_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_effects_display_steps(void* l0, int32_t l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    int64_t l4, l5;
    int32_t l6;
    vader_string_t l7 = 0;
    vader_string_t l8 = 0;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_string_t t2 = 0;
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[4] = { &l0, &l2, &l3, &t0 };
    vader_string_t* gc_atom_roots[3] = { &l7, &l8, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(14u, 0u, 0u, 288u);
    t0 = (void*) _a0_arr;
    vader_struct_std_string_builder_StringBuilder_t* _a1_obj = (vader_struct_std_string_builder_StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string_builder_StringBuilder_t));
    vader_obj_header_init(_a1_obj, 534u);
    _a1_obj->f_parts = t0;
    l2 = (void*) _a1_obj;
    l3 = vader_effects_steps_of(l0, l1);
    l4 = ((vader_array_t*) l3)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        l6 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l5];
        vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_effects_PathTable_t*) l0)->f_step_names);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l6)
        t1 = vader_array_box_slots(_a3_slotarr->buf)[_a3_slotarr->offset + (size_t) l6];
        l7 = t1.payload.s;
        if (l7 == 856u) {
            std_string_builder_append(l2, 856u);
        } else if (l7 != 454u) {
            l8 = concat_2(343u, l7);
            std_string_builder_append(l2, l8);
        }
        l5 = (l5 + INT64_C(1));
    }
    t2 = std_string_builder_StringBuilder_std_core_Display_to_string(l2);
    { vader_string_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_effects_drop_covered(void* l0, void* l1, void* l2) {
    int64_t l3, l5, l6, l13, l14, l15;
    vader_box_t l4 = vader_box_null();
    void* l7 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    void* l12 = NULL;
    bool l11;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l4, &t0 };
    void** gc_raw_roots[8] = { &l0, &l1, &l2, &l7, &l8, &l9, &l10, &l12 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 8u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l4 = vader_effects_first_covered(l0, l2, l1);
    if (l4.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l3 = ((int64_t) l4.payload.i);
    l5 = vader_effects_constraint_at(l1, l3);
    l6 = vader_effects_carried_at(l1, l3);
    vader_struct___Tuple_i64_i64_f049c617_t* _a0_obj = (vader_struct___Tuple_i64_i64_f049c617_t*) vader_gc_alloc(sizeof(vader_struct___Tuple_i64_i64_f049c617_t));
    vader_obj_header_init(_a0_obj, 305u);
    _a0_obj->f__0 = l5;
    _a0_obj->f__1 = l6;
    l7 = (void*) _a0_obj;
    vader_array_t* _a1_arr = vader_array_new(85u, 0u, 13u, 911u);
    l8 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(16u, 0u, 8u, 292u);
    l9 = (void*) _a2_arr;
    l5 = INT64_C(0);
    l6 = ((vader_array_t*) ((vader_struct_vader_effects_ParamEffects_t*) l1)->f_accesses)->length;
    while ((l5 < l6)) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_effects_ParamEffects_t*) l1)->f_accesses);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l5)
        l10 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l5);
        if ((l5 >= l3)) {
            l11 = vader_effects_covers(l0, l2, l10);
        } else {
            l11 = false;
        }
        if (l11) {
            if (!(((vader_struct_vader_effects_ParamEffects_t*) l1)->f_keys.tag == 0u)) {
                t0 = ((vader_struct_vader_effects_ParamEffects_t*) l1)->f_keys;
                l12 = t0.payload.obj;
                l13 = vader_effects_access_key(l10);
                std_collections_remove__i64(l12, l13);
            }
        } else {
            vader_array_push((vader_array_t*) l8, vader_ref_box(l10));
            l14 = vader_effects_constraint_at(l1, l5);
            vader_array_push_i64((vader_array_t*) l9, l14);
            l15 = vader_effects_carried_at(l1, l5);
            vader_array_push_i64((vader_array_t*) l9, l15);
        }
        l5 = (l5 + INT64_C(1));
    }
    ((vader_struct_vader_effects_ParamEffects_t*) l1)->f_accesses = l8;
    VADER_WRITE_BARRIER((vader_struct_vader_effects_ParamEffects_t*) l1);
    ((vader_struct_vader_effects_ParamEffects_t*) l1)->f_origins = l9;
    VADER_WRITE_BARRIER((vader_struct_vader_effects_ParamEffects_t*) l1);
    { vader_box_t __vret = vader_ref_box(l7); vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_effects_each_targets(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l8 = NULL;
    int64_t l5, l6, l9, l10;
    vader_box_t l7 = vader_box_null(), l11 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l7, &l11 };
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l3, &l4, &l8 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 6u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = l1;
    vader_struct___lambda_env_vader_effects_35_t* _a0_obj = (vader_struct___lambda_env_vader_effects_35_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_effects_35_t));
    vader_obj_header_init(_a0_obj, 326u);
    _a0_obj->f_cap_0 = l0;
    l3 = (void*) _a0_obj;
    vader_array_t* _a1_arr = vader_array_new(238u, 0u, 13u, 1666u);
    l4 = (void*) _a1_arr;
    l5 = ((vader_array_t*) l2)->length;
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        l7 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l6);
        l8 = __lambda_vader_effects_34(l3, l7);
        l9 = ((vader_array_t*) l8)->length;
        l10 = INT64_C(0);
        while ((l10 < l9)) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l8);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            l11 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l10);
            vader_array_push((vader_array_t*) l4, l11);
            l10 = (l10 + INT64_C(1));
        }
        l6 = (l6 + INT64_C(1));
    }
    { void* __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_effects_effects_of(uint8_t l0, int32_t l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void** gc_raw_roots[2] = { &l2, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(85u, 0u, 13u, 911u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(16u, 0u, 8u, 292u);
    l3 = (void*) _a1_arr;
    vader_struct_vader_effects_ParamEffects_t* _a2_obj = (vader_struct_vader_effects_ParamEffects_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_ParamEffects_t));
    vader_obj_header_init(_a2_obj, 932u);
    _a2_obj->f_accesses = l2;
    _a2_obj->f_origins = l3;
    _a2_obj->f_keys = vader_box_obj(0u, NULL);
    l2 = (void*) _a2_obj;
    vader_struct_vader_effects_Access_t* _a3_obj = (vader_struct_vader_effects_Access_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_Access_t));
    vader_obj_header_init(_a3_obj, 911u);
    _a3_obj->f_path = l1;
    _a3_obj->f_effect = l0;
    l3 = (void*) _a3_obj;
    vader_effects_insert(l2, l3, INT64_C(-1), INT64_C(-1));
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_effects_either(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    bool l4;
    int64_t l5, l6;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    bool t2;
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_effects_RootCase_t*) l0)->f_marked;
    l3 = l1;
    l4 = false;
    l5 = ((vader_array_t*) l2)->length;
    l6 = INT64_C(0);
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
            l6 = (l6 + INT64_C(1));
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
    l6 = INT64_C(0);
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
            l6 = (l6 + INT64_C(1));
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
    if (l1.tag == 571u) {
        t0 = l1.payload.obj;
        l3 = ((vader_struct_toolchain_ast_IfElseIf_t*) t0)->f_branch;
        l2 = vader_effects_if_value(l0, l3);
        { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 570u) {
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

static void vader_effects_escape(void* l0, vader_box_t l1, uint8_t l2, void* l3) {
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[2] = { &l0, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_effects_mark(l0, l1, INT32_C(0), l2, l3);
    { vader_gc_top = gc_frame.prev; return; }
}

bool vader_effects_escapes(void* l0) {
    bool t0;
    t0 = vader_effects_modifies(l0);
    return !(t0);
}

static bool vader_effects_evaluate(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    bool t0;
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = vader_effects_settled_slots(l0, l1, false);
    t0 = vader_effects_apply_constraints(l0, l3, l1, l2, l2);
    { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
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
    void* l16 = NULL;
    void* l19 = NULL;
    void* l21 = NULL;
    void* l23 = NULL;
    void* l24 = NULL;
    int64_t l3, l4, l11, l14, l17, l18, l20;
    vader_box_t l12 = vader_box_null(), l15 = vader_box_null(), l22 = vader_box_null();
    void* t0 = NULL;
    bool t1;
    vader_box_t* gc_roots[3] = { &l12, &l15, &l22 };
    void** gc_raw_roots[16] = {
        &l0, &l1, &l2, &l5, &l6, &l7, &l8, &l9, &l10, &l13, &l16, &l19, &l21, &l23, &l24, &t0,
    };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 16u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = vader_effects_settled_slots(l0, l1, true);
    l3 = ((vader_struct_vader_effects_Skeleton_t*) l0)->f_params;
    l4 = ((vader_struct_vader_effects_Skeleton_t*) l0)->f_extra;
    l3 = vader_chk_add(i64, l3, l4);
    l5 = (void*) &vader_fn_static___lambda_vader_effects_9;
    l5 = std_core_filled__vader_effects_ParamEffects(l3, l5);
    l6 = (void*) &vader_fn_static___lambda_vader_effects_10;
    l6 = std_core_filled__vader_effects_ParamEffects(l3, l6);
    vader_effects_apply_constraints(l0, l2, l1, l5, l6);
    vader_array_t* _a0_arr = vader_array_new(16u, 0u, 8u, 292u);
    l7 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(21u, 0u, 0u, 299u);
    l8 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(15u, 0u, 7u, 291u);
    l9 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__i64__Any___t* _a3_obj = (vader_struct_std_collections_MutableMap__i64__Any___t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i64__Any___t));
    vader_obj_header_init(_a3_obj, 426u);
    _a3_obj->f_ekeys = l7;
    _a3_obj->f_evals = l8;
    _a3_obj->f_index = l9;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    l7 = (void*) _a3_obj;
    vader_array_t* _a4_arr = vader_array_new(16u, 0u, 8u, 292u);
    l8 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_new(12u, 0u, 12u, 286u);
    l9 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(15u, 0u, 7u, 291u);
    l10 = (void*) _a6_arr;
    vader_struct_std_collections_MutableMap__i64__bool_t* _a7_obj = (vader_struct_std_collections_MutableMap__i64__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i64__bool_t));
    vader_obj_header_init(_a7_obj, 427u);
    _a7_obj->f_ekeys = l8;
    _a7_obj->f_evals = l9;
    _a7_obj->f_index = l10;
    _a7_obj->f_mask = INT64_C(0);
    _a7_obj->f_size = INT64_C(0);
    _a7_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a7_obj;
    vader_struct_std_collections_MutableSet__i64_t* _a8_obj = (vader_struct_std_collections_MutableSet__i64_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i64_t));
    vader_obj_header_init(_a8_obj, 523u);
    _a8_obj->f_inner = t0;
    l8 = (void*) _a8_obj;
    l9 = ((vader_struct_vader_effects_Skeleton_t*) l0)->f_flows;
    l3 = ((vader_array_t*) l9)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a9_slotarr = ((vader_array_t*) l9);
        VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
        l10 = vader_array_ref_load_obj(_a9_slotarr->buf, _a9_slotarr->offset + (size_t) l4);
        l12 = ((vader_struct_vader_effects_Flow_t*) l10)->f_copy;
        if (l12.tag == 0u) {
            l4 = (l4 + INT64_C(1));
            continue;
        }
        l11 = ((int64_t) l12.payload.i);
        l13 = ((vader_struct_vader_effects_SlotRoots_t*) l2)->f_roots;
        l14 = ((vader_struct_vader_effects_Flow_t*) l10)->f_from;
        vader_array_t* _a10_slotarr = ((vader_array_t*) l13);
        VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a10_slotarr, l14)
        l15 = vader_array_ref_load_box(_a10_slotarr->buf, _a10_slotarr->offset + (size_t) l14);
        if (l15.tag == 0u) {
            l4 = (l4 + INT64_C(1));
            continue;
        }
        l16 = l15.payload.obj;
        l17 = ((vader_array_t*) l16)->length;
        l18 = INT64_C(0);
        while ((l18 < l17)) {
            vader_array_t* _a11_slotarr = ((vader_array_t*) l16);
            VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
            l19 = vader_array_ref_load_obj(_a11_slotarr->buf, _a11_slotarr->offset + (size_t) l18);
            l20 = ((vader_struct_vader_effects_Root_t*) l19)->f_param;
            t1 = vader_effects_is_seed(l0, l20);
            if (t1) {
                l22 = std_collections_MutableMap_std_core_Index_at__i64__Any(l7, l11);
                if (l22.tag == 0u) {
                    vader_array_t* _a12_arr = vader_array_new(98u, 0u, 13u, 936u);
                    l21 = (void*) _a12_arr;
                } else {
                    l21 = l22.payload.obj;
                }
                l23 = ((vader_struct_vader_effects_EvalCtx_t*) l1)->f_paths;
                l24 = vader_effects_carried(l19, l10, l23);
                vader_array_push((vader_array_t*) l21, vader_ref_box(l24));
                std_collections_MutableMap_std_core_IndexSet_set_at__i64__Any(l7, l11, vader_ref_box(l21));
            } else {
                std_collections_add__i64(l8, l11);
            }
            l18 = (l18 + INT64_C(1));
        }
        l4 = (l4 + INT64_C(1));
    }
    vader_struct_vader_effects_RootEffects_t* _a13_obj = (vader_struct_vader_effects_RootEffects_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_RootEffects_t));
    vader_obj_header_init(_a13_obj, 938u);
    _a13_obj->f_marked = l5;
    _a13_obj->f_lent = l6;
    _a13_obj->f_took = l7;
    _a13_obj->f_mixed = l8;
    t0 = (void*) _a13_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_effects_extends(void* l0, int32_t l1, int32_t l2) {
    int32_t l3, l4;
    void* t0;
    int32_t t1;
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
    vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_effects_PathTable_t*) l0)->f_nodes);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
    t0 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
    return vader_box_eq(((vader_struct_vader_effects_PathNode_t*) t0)->f_cut, vader_box_i32(291u, l2));
}

static vader_box_t vader_effects_fallback_value(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    vader_box_t l3 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l1, &l3, &t0 };
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l1.tag == 601u) {
        l2 = l1.payload.obj;
        vader_effects_return_stmt(l0, l2);
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    if ((l1.tag == 542u || l1.tag == 548u)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    if (!((l1.tag == 535u || l1.tag == 538u || l1.tag == 539u || l1.tag == 540u || l1.tag == 541u || l1.tag == 544u || l1.tag == 545u || l1.tag == 546u || l1.tag == 557u || l1.tag == 562u || l1.tag == 563u || l1.tag == 566u || l1.tag == 568u || l1.tag == 569u || l1.tag == 572u || l1.tag == 577u || l1.tag == 579u || l1.tag == 580u || l1.tag == 582u || l1.tag == 586u || l1.tag == 590u || l1.tag == 591u || l1.tag == 597u || l1.tag == 602u || l1.tag == 604u || l1.tag == 609u || l1.tag == 618u))) {
        vader_unreachable("non-exhaustive match (T3013 should have caught this)");
    }
    l3 = l1;
    t0 = vader_effects_value(l0, l3);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_effects_fault_chain(void* l0, void* l1, void* l2, void* l3, uint8_t l4, bool l5) {
    void* l6 = NULL;
    void* l9 = NULL;
    void* l11 = NULL;
    void* l15 = NULL;
    void* l18 = NULL;
    int64_t l7, l10;
    vader_box_t l8 = vader_box_null();
    bool l12, l13, l14;
    vader_string_t l16 = 0;
    vader_string_t l17 = 0;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l8 };
    void** gc_raw_roots[10] = { &l0, &l1, &l2, &l3, &l6, &l9, &l11, &l15, &l18, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l16, &l17 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 10u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l7 = ((vader_struct_vader_effects_FrozenRoot_t*) l2)->f_root;
    l8 = vader_effects_fault_set(l3, l7, l4);
    if (l8.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l6 = l8.payload.obj;
    l9 = ((vader_struct_vader_effects_CalleeIndex_t*) ((vader_struct_vader_effects_TraceCtx_t*) l0)->f_index)->f_paths;
    l7 = INT64_C(0);
    l10 = ((vader_array_t*) ((vader_struct_vader_effects_ParamEffects_t*) l6)->f_accesses)->length;
    while ((l7 < l10)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_effects_ParamEffects_t*) l6)->f_accesses);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l7)
        l11 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l7);
        if (!(l5)) {
            l12 = vader_effects_modifies(l11);
        } else {
            l12 = false;
        }
        if (l12) {
            l13 = true;
        } else {
            if (l5) {
                l14 = vader_effects_writes_view(l9, l11);
            } else {
                l14 = false;
            }
            l13 = l14;
        }
        if (l13) {
            l15 = ((vader_struct_vader_effects_FrozenBody_t*) l1)->f_skeleton;
            l16 = ((vader_struct_vader_resolver_ResolvedModule_t*) ((vader_struct_vader_typecheck_TypedProgram_t*) ((vader_struct_vader_effects_FrozenBody_t*) l1)->f_typed)->f_resolved)->f_display_path;
            l17 = ((vader_struct_vader_effects_FrozenRoot_t*) l2)->f_label;
            vader_struct_vader_effects_Link_t* _a1_obj = (vader_struct_vader_effects_Link_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_Link_t));
            vader_obj_header_init(_a1_obj, 930u);
            _a1_obj->f_s = l15;
            _a1_obj->f_module = l16;
            _a1_obj->f_effects = l6;
            _a1_obj->f_name = l17;
            l18 = (void*) _a1_obj;
            t0 = vader_effects_trace(l0, l18, l7);
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l7 = (l7 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static vader_string_t vader_effects_fault_detail(void* l0) {
    vader_string_t l1 = 0;
    vader_string_t l2 = 0;
    vader_string_t l3 = 0;
    vader_string_t t0 = 0;
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[4] = { &l1, &l2, &l3, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = vader_effects_frozen_what(l0);
    l2 = vader_effects_modified_how(l0);
    l3 = vader_effects_copy_hint(l0, 2177u);
    t0 = concat_5(l1, 316u, l2, 51u, l3);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_effects_fault_of(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    bool l4;
    int64_t l5, l6;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    bool t2;
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_effects_RootCase_t*) l0)->f_marked;
    l3 = l1;
    l4 = false;
    l5 = ((vader_array_t*) l2)->length;
    l6 = INT64_C(0);
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
            l6 = (l6 + INT64_C(1));
        }
        l4 = false;
    } end_11: ;
    if (l4) {
        { vader_box_t __vret = vader_box_i32(293u, INT32_C(0)); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = ((vader_struct_vader_effects_RootCase_t*) l0)->f_lent;
    l3 = l1;
    l4 = false;
    l5 = ((vader_array_t*) l2)->length;
    l6 = INT64_C(0);
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
                goto end_54;
            }
            l6 = (l6 + INT64_C(1));
        }
        l4 = false;
    } end_54: ;
    if (!(l4)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    { vader_box_t __vret = vader_box_i32(293u, INT32_C(1)); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_effects_fault_set(void* l0, int64_t l1, uint8_t l2) {
    vader_box_t l3;
    bool l4;
    void* t0;
    if (l2 == INT32_C(0)) {
        l4 = true;
    } else {
        l4 = l2 == INT32_C(6);
    }
    if (l4) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_effects_RootEffects_t*) l0)->f_marked);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l1);
        l3 = vader_ref_box(t0);
        return l3;
    }
    if (l2 == INT32_C(1)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_effects_RootEffects_t*) l0)->f_lent);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l1)
        t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l1);
        l3 = vader_ref_box(t0);
    } else {
        if (l2 == INT32_C(2)) {
            l4 = true;
        } else {
            l4 = l2 == INT32_C(3);
        }
        if (l4) {
            l4 = true;
        } else {
            l4 = l2 == INT32_C(4);
        }
        if (l4) {
            l4 = true;
        } else {
            l4 = l2 == INT32_C(5);
        }
        if (l4) {
            l4 = true;
        } else {
            l4 = l2 == INT32_C(7);
        }
        if (l4) {
            l4 = true;
        } else {
            l4 = l2 == INT32_C(8);
        }
        if (!(l4)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l3 = vader_box_obj(0u, NULL);
    }
    return l3;
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
    vader_array_t* _a0_arr = vader_array_new(95u, 4u, 13u, 932u);
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
    return 856u;
}

static vader_box_t vader_effects_field_value(void* l0, void* l1) {
    int64_t l2;
    vader_box_t l3 = vader_box_null(), l4 = vader_box_null();
    void* l5 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    vader_string_t l8 = 0;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l3, &l4, &t0 };
    void** gc_raw_roots[5] = { &l0, &l1, &l5, &l6, &l7 };
    vader_string_t* gc_atom_roots[1] = { &l8 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_toolchain_ast_FieldExpr_t*) l1)->f_id;
    l3 = vader_effects_site_callee(l0, (uint8_t) 9, l2);
    if (!(l3.tag == 0u)) {
        l4 = ((vader_struct_toolchain_ast_FieldExpr_t*) l1)->f_target;
        t0 = vader_effects_value(l0, l4);
        vader_array_t* _a0_arr = vader_array_new(214u, 1u, 0u, 1414u);
        vader_array_box_slots(_a0_arr->buf)[_a0_arr->offset + 0u] = t0;
        l5 = (void*) _a0_arr;
        l6 = ((vader_struct_toolchain_ast_FieldExpr_t*) l1)->f_span;
        vader_array_t* _a1_arr = vader_array_new(216u, 1u, 13u, 1457u);
        ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = ((vader_struct_toolchain_ast_FieldExpr_t*) l1)->f_target.payload.obj;
        l7 = (void*) _a1_arr;
        vader_effects_call(l0, l3, l5, l6, l7);
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l3 = vader_effects_namespace_member(l0, l1);
    if (l3.tag == 0u) {
        l4 = ((vader_struct_toolchain_ast_FieldExpr_t*) l1)->f_target;
        l4 = vader_effects_value(l0, l4);
        l8 = vader_effects_field_step(l1);
        t0 = vader_effects_step_slot(l0, l4, l8);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l5 = l3.payload.obj;
    t0 = vader_effects_frozen_use(l0, vader_ref_box(l1), l5);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_effects_fields_may_be_written(void* l0, void* l1, void* l2, void* l3) {
    int32_t l4;
    void* l5 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    vader_box_t l6 = vader_box_null();
    int64_t l9, l10;
    bool t0;
    vader_box_t t1 = vader_box_null();
    vader_string_t t2 = 0;
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
    l6 = std_collections_MutableMap_std_core_Index_at__i32__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_(l5, l4);
    if (l6.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return true; }
    }
    l5 = l6.payload.obj;
    l7 = ((vader_struct_std_collections_MutableMap__string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_t*) l5)->f_ekeys;
    l8 = ((vader_struct_std_collections_MutableMap__string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_t*) l5)->f_evals;
    l9 = INT64_C(0);
    l10 = ((vader_struct_std_collections_MutableMap__string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_t*) l5)->f_size;
    while ((l9 < l10)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l9)
        t1 = vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l9];
        t2 = t1.payload.s;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l9)
        l6 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l9);
        t0 = vader_effects_may_be_written(l0, l6, l2, l3);
        if (t0) {
            { vader_gc_top = gc_frame.prev; return true; }
        }
        l9 = (l9 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return false; }
}

static vader_box_t vader_effects_find_access(void* l0, void* l1, int64_t l2) {
    int64_t l3, l4;
    void* l5;
    int64_t t0;
    bool t1;
    if (l2 == INT64_C(-1)) {
        return vader_box_obj(0u, NULL);
    }
    l3 = INT64_C(0);
    l4 = ((vader_array_t*) ((vader_struct_vader_effects_ParamEffects_t*) l1)->f_accesses)->length;
    while ((l3 < l4)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_effects_ParamEffects_t*) l1)->f_accesses);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        l5 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
        t0 = vader_effects_access_key(l5);
        if (t0 == l2) {
            return vader_box_i64(292u, l3);
        }
        t1 = vader_effects_covers_key(l0, l5, l2);
        if (t1) {
            return vader_box_i64(292u, l3);
        }
        l3 = (l3 + INT64_C(1));
    }
    return vader_box_obj(0u, NULL);
}

static vader_box_t vader_effects_first_covered(void* l0, void* l1, void* l2) {
    int64_t l3, l4;
    void* l5;
    bool t0;
    l3 = INT64_C(0);
    l4 = ((vader_array_t*) ((vader_struct_vader_effects_ParamEffects_t*) l2)->f_accesses)->length;
    while ((l3 < l4)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_effects_ParamEffects_t*) l2)->f_accesses);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        l5 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
        t0 = vader_effects_covers(l0, l1, l5);
        if (t0) {
            return vader_box_i64(292u, l3);
        }
        l3 = (l3 + INT64_C(1));
    }
    return vader_box_obj(0u, NULL);
}

static void* vader_effects_first_paths(void) {
    void* l0 = NULL;
    void* l1 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[3] = { &l0, &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_effects_PathNode_t* _a0_obj = (vader_struct_vader_effects_PathNode_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_PathNode_t));
    vader_obj_header_init(_a0_obj, 933u);
    _a0_obj->f_parent = INT32_C(0);
    _a0_obj->f_step = INT32_C(0);
    _a0_obj->f_length = INT32_C(0);
    _a0_obj->f_deeper = false;
    _a0_obj->f_cut = vader_box_i32(291u, INT32_C(1));
    l0 = (void*) _a0_obj;
    vader_struct_vader_effects_PathNode_t* _a1_obj = (vader_struct_vader_effects_PathNode_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_PathNode_t));
    vader_obj_header_init(_a1_obj, 933u);
    _a1_obj->f_parent = INT32_C(0);
    _a1_obj->f_step = INT32_C(0);
    _a1_obj->f_length = INT32_C(0);
    _a1_obj->f_deeper = true;
    _a1_obj->f_cut = vader_box_obj(0u, NULL);
    l1 = (void*) _a1_obj;
    vader_array_t* _a2_arr = vader_array_new(96u, 2u, 13u, 933u);
    ((void**) _a2_arr->buf->slots)[_a2_arr->offset + 1u] = l1;
    ((void**) _a2_arr->buf->slots)[_a2_arr->offset + 0u] = l0;
    t0 = (void*) _a2_arr;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_effects_first_step_is(void* l0, int32_t l1, vader_string_t l2) {
    int32_t l3;
    void* l4;
    void* t0;
    int32_t t1;
    vader_box_t t2;
    vader_string_t t3;
    l3 = l1;
    for (;;) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_effects_PathTable_t*) l0)->f_nodes);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
        t1 = ((vader_struct_vader_effects_PathNode_t*) t0)->f_length;
        if ((t1 > INT32_C(1))) {
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
            t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
            l3 = ((vader_struct_vader_effects_PathNode_t*) t0)->f_parent;
            continue;
        }
        break;
    }
    vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_effects_PathTable_t*) l0)->f_nodes);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
    t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l3);
    t1 = ((vader_struct_vader_effects_PathNode_t*) t0)->f_length;
    if (t1 == INT32_C(1)) {
        l4 = ((vader_struct_vader_effects_PathTable_t*) l0)->f_step_names;
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
        t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l3);
        l3 = ((vader_struct_vader_effects_PathNode_t*) t0)->f_step;
        vader_array_t* _a2_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
        t2 = vader_array_box_slots(_a2_slotarr->buf)[_a2_slotarr->offset + (size_t) l3];
        t3 = t2.payload.s;
        return t3 == l2;
    }
    return false;
}

static void* vader_effects_flowed_root(void* l0, void* l1, void* l2, void* l3) {
    vader_box_t l4 = vader_box_null();
    int64_t l5;
    void* t0 = NULL;
    bool t1;
    int64_t t2;
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
    t1 = vader_effects_is_seed(l2, l5);
    if (t1) {
        t2 = ((int64_t) l4.payload.i);
        vader_struct_vader_effects_Root_t* _a0_obj = (vader_struct_vader_effects_Root_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_Root_t));
        vader_obj_header_init(_a0_obj, 936u);
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
    if (l2.tag == 578u) {
        l6 = ((vader_struct_toolchain_ast_ForStmt_t*) l1)->f_body;
        vader_effects_block_value(l0, l6);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 619u) {
        t0 = l3.payload.obj;
        l4 = ((vader_struct_toolchain_ast_WhileFor_t*) t0)->f_cond;
        vader_effects_discard(l0, l4);
    } else {
        if (!(l2.tag == 576u)) {
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
        if (l3.tag == 589u) {
            t0 = l4.payload.obj;
            l5 = ((vader_struct_toolchain_ast_NamedVar_t*) t0)->f_span;
            vader_effects_bind_symbol(l0, l5, l2);
        } else if (l3.tag == 555u) {
            t0 = l4.payload.obj;
            l4 = ((vader_struct_toolchain_ast_DestructureVar_t*) t0)->f_pattern;
            vader_effects_bind(l0, l4, l2);
        } else if (!(l3.tag == 556u)) {
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
    t0 = toolchain_ast_decorators_have(((vader_struct_toolchain_ast_FnParam_t*) l0)->f_decorators, 1552u);
    if (!(t0)) {
        t1 = vader_effects_none();
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_effects_effects_of((uint8_t) 0, INT32_C(1));
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static int64_t vader_effects_fresh_slot(void* l0) {
    int64_t l1, l2;
    int64_t t0;
    l1 = ((vader_struct_vader_effects_Skeleton_t*) l0)->f_slots;
    t0 = ((vader_struct_vader_effects_Skeleton_t*) l0)->f_slots;
    l2 = vader_chk_add(i64, t0, INT64_C(1));
    ((vader_struct_vader_effects_Skeleton_t*) l0)->f_slots = l2;
    return l1;
}

void* vader_effects_frozen_diagnostics(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l8 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    void* l13 = NULL;
    void* l17 = NULL;
    void* l18 = NULL;
    void* l19 = NULL;
    void* l21 = NULL;
    int64_t l5, l6;
    uint8_t l7;
    vader_string_t l9 = 0;
    vader_string_t l12 = 0;
    vader_string_t l14 = 0;
    vader_string_t l15 = 0;
    vader_string_t l16 = 0;
    vader_string_t l20 = 0;
    bool l22, l23, l24, l25;
    void* t0 = NULL;
    bool t1;
    vader_string_t t2 = 0;
    void** gc_raw_roots[14] = {
        &l0, &l1, &l2, &l3, &l4, &l8, &l10, &l11, &l13, &l17, &l18, &l19, &l21, &t0,
    };
    vader_string_t* gc_atom_roots[7] = { &l9, &l12, &l14, &l15, &l16, &l20, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 14u, NULL, gc_raw_roots, 0u, NULL, 7u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(84u, 0u, 13u, 910u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(21u, 0u, 0u, 299u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(12u, 0u, 12u, 286u);
    l3 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(15u, 0u, 7u, 291u);
    l4 = (void*) _a3_arr;
    vader_struct_std_collections_MutableMap__Any__bool_t* _a4_obj = (vader_struct_std_collections_MutableMap__Any__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__Any__bool_t));
    vader_obj_header_init(_a4_obj, 382u);
    _a4_obj->f_ekeys = l2;
    _a4_obj->f_evals = l3;
    _a4_obj->f_index = l4;
    _a4_obj->f_mask = INT64_C(0);
    _a4_obj->f_size = INT64_C(0);
    _a4_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a4_obj;
    vader_struct_std_collections_MutableSet__Any_t* _a5_obj = (vader_struct_std_collections_MutableSet__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__Any_t));
    vader_obj_header_init(_a5_obj, 521u);
    _a5_obj->f_inner = t0;
    l2 = (void*) _a5_obj;
    l3 = ((vader_struct_vader_effects_EffectSummary_t*) l0)->f_frozen;
    l5 = ((vader_array_t*) l3)->length;
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a6_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        l4 = vader_array_ref_load_obj(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l6);
        l7 = ((vader_struct_vader_effects_FrozenSite_t*) l4)->f_kind;
        if (l7 == INT32_C(0)) {
            l8 = ((vader_struct_vader_effects_FrozenSite_t*) l4)->f_span;
            l9 = vader_effects_fault_detail(l4);
            l10 = vader_diagnostics_typecheck_error((uint8_t) 58, l8, l9);
            vader_array_push((vader_array_t*) l1, vader_ref_box(l10));
        } else if (l7 == INT32_C(1)) {
            l11 = ((vader_struct_vader_effects_FrozenSite_t*) l4)->f_span;
            l12 = vader_effects_fault_detail(l4);
            l13 = vader_diagnostics_typecheck_error((uint8_t) 60, l11, l12);
            vader_array_push((vader_array_t*) l1, vader_ref_box(l13));
        } else if (l7 == INT32_C(7)) {
            l14 = vader_effects_frozen_what(l4);
            l15 = vader_effects_copy_hint(l4, 2055u);
            l16 = concat_3(l14, 51u, l15);
            l17 = ((vader_struct_vader_effects_FrozenSite_t*) l4)->f_span;
            l18 = vader_diagnostics_typecheck_error((uint8_t) 59, l17, l16);
            vader_array_push((vader_array_t*) l1, vader_ref_box(l18));
        } else if (l7 == INT32_C(6)) {
            l19 = vader_effects_lost_write(l4);
            t1 = std_collections_add__toolchain_span_Span(l2, l19);
            if (t1) {
                t2 = vader_effects_frozen_what(l4);
                l20 = concat_2(t2, 54u);
                l21 = vader_diagnostics_warning((uint8_t) 13, l19, l20);
                vader_array_push((vader_array_t*) l1, vader_ref_box(l21));
            }
        } else {
            if (l7 == INT32_C(2)) {
                l22 = true;
            } else {
                l22 = l7 == INT32_C(3);
            }
            if (l22) {
                l23 = true;
            } else {
                l23 = l7 == INT32_C(4);
            }
            if (l23) {
                l24 = true;
            } else {
                l24 = l7 == INT32_C(5);
            }
            if (l24) {
                l25 = true;
            } else {
                l25 = l7 == INT32_C(8);
            }
            if (!(l25)) {
                vader_unreachable("non-exhaustive match (T3013 should have caught this)");
            }
        }
        l6 = (l6 + INT64_C(1));
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static int64_t vader_effects_frozen_source(void* l0, vader_box_t l1, vader_string_t l2, uint8_t l3, vader_box_t l4) {
    int64_t l5, l6, l9;
    void* l7 = NULL;
    void* l8 = NULL;
    vader_box_t l10 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l1, &l4, &l10 };
    void** gc_raw_roots[3] = { &l0, &l7, &l8 };
    vader_string_t* gc_atom_roots[1] = { &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l5 = vader_effects_fresh_slot(((vader_struct_vader_effects_WalkCtx_t*) l0)->f_s);
    l6 = vader_effects_add_root(((vader_struct_vader_effects_WalkCtx_t*) l0)->f_s, l5);
    l7 = VADER_UNION_FIELD(void*, vader_struct_toolchain_ast_ArrayTypeExpr_t, f_span, l1.payload.obj);
    l8 = ((vader_struct_vader_typecheck_TypedProgram_t*) ((vader_struct_vader_effects_WalkCtx_t*) l0)->f_typed)->f_expr_types;
    l9 = VADER_UNION_FIELD(int64_t, vader_struct_toolchain_ast_ArrayTypeExpr_t, f_id, l1.payload.obj);
    l10 = std_collections_MutableMap_std_core_Index_at__i64__Any(l8, l9);
    vader_struct_vader_effects_FrozenRoot_t* _a0_obj = (vader_struct_vader_effects_FrozenRoot_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_FrozenRoot_t));
    vader_obj_header_init(_a0_obj, 924u);
    _a0_obj->f_root = l6;
    _a0_obj->f_span = l7;
    _a0_obj->f_label = l2;
    _a0_obj->f_binding = vader_box_obj(0u, NULL);
    _a0_obj->f_origin = l3;
    _a0_obj->f_constant = l4;
    _a0_obj->f_type = l10;
    l7 = (void*) _a0_obj;
    vader_array_push((vader_array_t*) ((vader_struct_vader_effects_WalkCtx_t*) l0)->f_roots, vader_ref_box(l7));
    { int64_t __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_effects_frozen_use(void* l0, vader_box_t l1, void* l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    int64_t l5;
    int32_t l6;
    vader_string_t l7 = 0;
    bool t0;
    vader_box_t t1 = vader_box_null();
    int64_t t2;
    vader_box_t* gc_roots[2] = { &l1, &t1 };
    void** gc_raw_roots[4] = { &l0, &l2, &l3, &l4 };
    vader_string_t* gc_atom_roots[1] = { &l7 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_effects_WalkCtx_t*) l0)->f_typed;
    l3 = vader_typecheck_declared_symbol(l2, l3);
    t0 = vader_resolver_symbol_is_frozen_const(l3);
    if (t0) {
        l4 = ((vader_struct_vader_typecheck_TypedProgram_t*) ((vader_struct_vader_effects_WalkCtx_t*) l0)->f_typed)->f_resolved;
        t0 = vader_typecheck_names_a_type(l3, l4);
        if (t0) {
            { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
        }
        l4 = ((vader_struct_vader_typecheck_TypedProgram_t*) ((vader_struct_vader_effects_WalkCtx_t*) l0)->f_typed)->f_expr_types;
        l5 = VADER_UNION_FIELD(int64_t, vader_struct_toolchain_ast_ArrayTypeExpr_t, f_id, l1.payload.obj);
        t1 = std_collections_MutableMap_std_core_Index_at__i64__Any(l4, l5);
        t0 = vader_effects_holds_references(t1);
        if (!(t0)) {
            { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
        }
        l5 = VADER_UNION_FIELD(int64_t, vader_struct_toolchain_ast_ArrayTypeExpr_t, f_id, l1.payload.obj);
        l6 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l3)->f_id;
        vader_struct_vader_effects_ConstantUse_t* _a0_obj = (vader_struct_vader_effects_ConstantUse_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_ConstantUse_t));
        vader_obj_header_init(_a0_obj, 916u);
        _a0_obj->f_node = l5;
        _a0_obj->f_symbol = l6;
        l3 = (void*) _a0_obj;
        l7 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l2)->f_name;
        l5 = vader_effects_frozen_source(l0, l1, l7, (uint8_t) 0, vader_ref_box(l3));
        t2 = vader_effects_pure_source(l0, l5);
        { vader_box_t __vret = vader_box_i64(292u, t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static vader_box_t vader_effects_frozen_variant_data(void* l0, void* l1) {
    void* l2 = NULL;
    int64_t l3;
    vader_box_t l4 = vader_box_null(), l5 = vader_box_null(), l6 = vader_box_null();
    int32_t l7;
    int64_t t0;
    void* t1 = NULL;
    bool t2;
    vader_box_t* gc_roots[3] = { &l4, &l5, &l6 };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_toolchain_ast_CallExpr_t*) l1)->f_args)->length;
    if (t0 != INT64_C(1)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l2 = ((vader_struct_vader_typecheck_TypedProgram_t*) ((vader_struct_vader_effects_WalkCtx_t*) l0)->f_typed)->f_expr_types;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_CallExpr_t*) l1)->f_args);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
    t1 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT32_C(0));
    l3 = VADER_UNION_FIELD(int64_t, vader_struct_toolchain_ast_ArrayTypeExpr_t, f_id, ((vader_struct_toolchain_ast_CallArg_t*) t1)->f_value.payload.obj);
    l4 = std_collections_MutableMap_std_core_Index_at__i64__Any(l2, l3);
    l2 = ((vader_struct_vader_typecheck_TypedProgram_t*) ((vader_struct_vader_effects_WalkCtx_t*) l0)->f_typed)->f_expr_types;
    l3 = ((vader_struct_toolchain_ast_CallExpr_t*) l1)->f_id;
    l5 = std_collections_MutableMap_std_core_Index_at__i64__Any(l2, l3);
    if (l5.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    if (l4.tag == 1265u) {
        t1 = l4.payload.obj;
        l6 = vader_typecheck_enum_data_of(vader_ref_box(t1), l5);
        if (l6.tag == 0u) {
            { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
        }
        l2 = l6.payload.obj;
        l3 = vader_effects_variant_data_use(l0, l1, l2);
        t0 = vader_effects_pure_source(l0, l3);
        { vader_box_t __vret = vader_box_i64(292u, t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l4.tag == 1280u)) {
        if (!(l4.tag == 1262u)) {
            { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
        }
    }
    if (l5.tag == 1276u) {
        t1 = l5.payload.obj;
        l7 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_types_StructType_t*) t1)->f_symbol)->f_id;
        t2 = std_collections_MutableSet_std_core_Contains_contains__i32(((vader_struct_vader_effects_CalleeIndex_t*) ((vader_struct_vader_effects_WalkCtx_t*) l0)->f_index)->f_variant_data, l7);
        if (t2) {
            l2 = l5.payload.obj;
            t0 = vader_effects_variant_data_use(l0, l1, l2);
            { vader_box_t __vret = vader_box_i64(292u, t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static vader_box_t vader_effects_frozen_view(void* l0, void* l1, vader_box_t l2) {
    vader_string_t l3 = 0;
    bool t0;
    int64_t t1;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_string_t* gc_atom_roots[1] = { &l3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_effects_makes_view(((vader_struct_vader_effects_WalkCtx_t*) l0)->f_index, l2);
    if (!(t0)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l3 = vader_effects_view_label(l2);
    t1 = vader_effects_frozen_source(l0, vader_ref_box(l1), l3, (uint8_t) 1, vader_box_obj(0u, NULL));
    { vader_box_t __vret = vader_box_i64(292u, t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_effects_frozen_what(void* l0) {
    uint8_t l1;
    vader_string_t l2 = 0;
    vader_string_t l3 = 0;
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[2] = { &l2, &l3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct_vader_effects_FrozenSite_t*) l0)->f_origin;
    if (l1 == INT32_C(0)) {
        l2 = ((vader_struct_vader_effects_FrozenSite_t*) l0)->f_root;
        l2 = concat_3(924u, l2, 1018u);
        { vader_string_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == INT32_C(1)) {
        l3 = ((vader_struct_vader_effects_FrozenSite_t*) l0)->f_root;
        l2 = concat_3(924u, l3, 1108u);
    } else {
        if (!(l1 == INT32_C(2))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l3 = ((vader_struct_vader_effects_FrozenSite_t*) l0)->f_root;
        l2 = concat_3(924u, l3, 1099u);
    }
    { vader_string_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_effects_hands_on_written(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    void* t0 = NULL;
    bool t1;
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct___lambda_env_vader_effects_22_t* _a0_obj = (vader_struct___lambda_env_vader_effects_22_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_effects_22_t));
    vader_obj_header_init(_a0_obj, 320u);
    _a0_obj->f_cap_0 = l2;
    _a0_obj->f_cap_1 = l1;
    _a0_obj->f_cap_2 = l0;
    t0 = (void*) _a0_obj;
    vader_fn_t* _a1_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
    vader_obj_header_init(_a1_closure, 273u);
    _a1_closure->code = (void*) &vader_fn_lift___lambda_vader_effects_21;
    _a1_closure->env = t0;
    l3 = (void*) _a1_closure;
    t1 = vader_effects_either(l1, l3);
    { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

bool vader_effects_has_news(void* l0, int32_t l1, void* l2) {
    int64_t l3, l7;
    void* l4 = NULL;
    void* l5 = NULL;
    bool l6;
    int32_t l8;
    bool t0;
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
    vader_struct___lambda_env_vader_effects_6_t* _a1_obj = (vader_struct___lambda_env_vader_effects_6_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_effects_6_t));
    vader_obj_header_init(_a1_obj, 330u);
    _a1_obj->f_cap_0 = l0;
    _a1_obj->f_cap_1 = l3;
    l5 = (void*) _a1_obj;
    l6 = false;
    l3 = ((vader_array_t*) l4)->length;
    l7 = INT64_C(0);
    {
        while ((l7 < l3)) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) l4);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            l8 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l7];
            t0 = __lambda_vader_effects_5(l5, l8);
            if (t0) {
                l6 = true;
                goto end_22;
            }
            l7 = (l7 + INT64_C(1));
        }
        l6 = false;
    } end_22: ;
    { bool __vret = l6; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_effects_held_by(void* l0, void* l1) {
    void* l2 = NULL;
    int64_t l3;
    vader_box_t t0 = vader_box_null();
    int64_t t1;
    void* t2 = NULL;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (!(((vader_struct_vader_effects_FrozenRoot_t*) l0)->f_binding.tag == 0u)) {
        l2 = ((vader_struct_vader_effects_RootEffects_t*) l1)->f_took;
        l3 = ((vader_struct_vader_effects_FrozenRoot_t*) l0)->f_root;
        t0 = std_collections_MutableMap_std_core_Index_at__i64__Any(l2, l3);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = ((vader_struct_vader_effects_FrozenRoot_t*) l0)->f_root;
    vader_struct_vader_effects_Root_t* _a0_obj = (vader_struct_vader_effects_Root_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_Root_t));
    vader_obj_header_init(_a0_obj, 936u);
    _a0_obj->f_param = t1;
    _a0_obj->f_path = INT32_C(0);
    t2 = (void*) _a0_obj;
    vader_array_t* _a1_arr = vader_array_new(98u, 1u, 13u, 936u);
    ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = t2;
    t2 = (void*) _a1_arr;
    { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
}

static int64_t vader_effects_held_count(void* l0, int64_t l1) {
    vader_box_t l2;
    void* t0;
    int64_t t1;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_effects_SlotRoots_t*) l0)->f_roots);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    l2 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l1);
    if (l2.tag == 0u) {
        return INT64_C(0);
    }
    t0 = l2.payload.obj;
    t1 = ((vader_array_t*) t0)->length;
    return t1;
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

static bool vader_effects_holds_view(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l5 = NULL;
    int64_t l3, l4;
    bool t0;
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct_vader_effects_RootCase_t*) l0)->f_held;
    vader_struct___lambda_env_vader_effects_18_t* _a0_obj = (vader_struct___lambda_env_vader_effects_18_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_effects_18_t));
    vader_obj_header_init(_a0_obj, 319u);
    _a0_obj->f_cap_0 = l0;
    l2 = (void*) _a0_obj;
    l3 = ((vader_array_t*) l1)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l5 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
        t0 = __lambda_vader_effects_17(l2, l5);
        if (t0) {
            { vader_gc_top = gc_frame.prev; return true; }
        }
        l4 = (l4 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return false; }
}

static vader_box_t vader_effects_ident_value(void* l0, void* l1) {
    void* l2 = NULL;
    void* l5 = NULL;
    uint64_t l3;
    vader_box_t l4 = vader_box_null(), l9 = vader_box_null();
    int32_t l6;
    int64_t l7, l8;
    vader_box_t t0 = vader_box_null();
    bool t1;
    vader_box_t* gc_roots[3] = { &l4, &l9, &t0 };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_resolver_ResolvedModule_t*) ((vader_struct_vader_typecheck_TypedProgram_t*) ((vader_struct_vader_effects_WalkCtx_t*) l0)->f_typed)->f_resolved)->f_idents;
    l3 = toolchain_span_Span_std_core_Hash_hash(((vader_struct_toolchain_ast_IdentExpr_t*) l1)->f_span);
    l4 = std_collections_MutableMap_std_core_Index_at__u64__Any(l2, l3);
    if (l4.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l2 = l4.payload.obj;
    l5 = ((vader_struct_vader_effects_WalkCtx_t*) l0)->f_slots;
    l6 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l2)->f_id;
    l4 = std_collections_MutableMap_std_core_Index_at__i32__i64(l5, l6);
    if (l4.tag == 0u) {
        t0 = vader_effects_frozen_use(l0, vader_ref_box(l1), l2);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l5 = ((vader_struct_vader_effects_WalkCtx_t*) l0)->f_place_bases;
    l7 = ((vader_struct_toolchain_ast_IdentExpr_t*) l1)->f_id;
    t1 = std_collections_MutableSet_std_core_Contains_contains__i64(l5, l7);
    if (!(t1)) {
        l5 = ((vader_struct_vader_effects_WalkCtx_t*) l0)->f_seen_names;
        l6 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l2)->f_id;
        std_collections_add__i32(l5, l6);
    }
    l7 = ((int64_t) l4.payload.i);
    l5 = ((vader_struct_vader_effects_WalkCtx_t*) l0)->f_typed;
    l4 = vader_typecheck_type_of_symbol(l2, l5);
    l2 = ((vader_struct_vader_typecheck_TypedProgram_t*) ((vader_struct_vader_effects_WalkCtx_t*) l0)->f_typed)->f_expr_types;
    l8 = ((vader_struct_toolchain_ast_IdentExpr_t*) l1)->f_id;
    l9 = std_collections_MutableMap_std_core_Index_at__i64__Any(l2, l8);
    t0 = vader_effects_narrowed(l0, vader_box_i64(292u, l7), l4, l9);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
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
    vader_array_t* _a0_arr = vader_array_new(214u, 2u, 0u, 1414u);
    vader_array_box_slots(_a0_arr->buf)[_a0_arr->offset + 1u] = l4;
    vader_array_box_slots(_a0_arr->buf)[_a0_arr->offset + 0u] = l2;
    l3 = (void*) _a0_arr;
    t0 = vader_effects_one_of(l0, l3);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_effects_include(void* l0, void* l1, int32_t l2, uint8_t l3, int64_t l4, int64_t l5) {
    void* l6 = NULL;
    vader_box_t l7 = vader_box_null();
    int64_t l8, l9;
    bool t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &l7 };
    void** gc_raw_roots[4] = { &l0, &l1, &l6, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_effects_covered(l0, l1, l2, l3);
    if (t0) {
        { vader_gc_top = gc_frame.prev; return false; }
    }
    vader_struct_vader_effects_Access_t* _a0_obj = (vader_struct_vader_effects_Access_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_Access_t));
    vader_obj_header_init(_a0_obj, 911u);
    _a0_obj->f_path = l2;
    _a0_obj->f_effect = l3;
    l6 = (void*) _a0_obj;
    vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_effects_PathTable_t*) l0)->f_nodes);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l2)
    t1 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l2);
    t0 = ((vader_struct_vader_effects_PathNode_t*) t1)->f_deeper;
    if (t0) {
        l7 = vader_effects_drop_covered(l0, l1, l6);
        if (!(l7.tag == 0u)) {
            t1 = l7.payload.obj;
            l8 = ((vader_struct___Tuple_i64_i64_f049c617_t*) t1)->f__0;
            t1 = l7.payload.obj;
            l9 = ((vader_struct___Tuple_i64_i64_f049c617_t*) t1)->f__1;
            vader_effects_insert(l1, l6, l8, l9);
            { vader_gc_top = gc_frame.prev; return true; }
        }
        vader_effects_insert(l1, l6, l4, l5);
        { vader_gc_top = gc_frame.prev; return true; }
    }
    vader_effects_insert(l1, l6, l4, l5);
    { vader_gc_top = gc_frame.prev; return true; }
}

static bool vader_effects_include_root(void* l0, int64_t l1, void* l2) {
    int64_t l3, l4;
    vader_box_t l5 = vader_box_null();
    void* l6 = NULL;
    void* l7 = NULL;
    int64_t t0;
    int32_t t1;
    bool t2;
    void* t3 = NULL;
    vader_box_t* gc_roots[1] = { &l5 };
    void** gc_raw_roots[5] = { &l0, &l2, &l6, &l7, &t3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_effects_SlotRoots_t*) l0)->f_root_count;
    l3 = vader_chk_mul(i64, l1, l3);
    l4 = ((vader_struct_vader_effects_Root_t*) l2)->f_param;
    t0 = vader_chk_add(i64, l3, l4);
    l3 = (t0 << INT64_C(32));
    t1 = ((vader_struct_vader_effects_Root_t*) l2)->f_path;
    l4 = ((int64_t) (int32_t) t1);
    l3 = (l3 | l4);
    t2 = std_collections_add__i64(((vader_struct_vader_effects_SlotRoots_t*) l0)->f_seen, l3);
    if (!(t2)) {
        { vader_gc_top = gc_frame.prev; return false; }
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_effects_SlotRoots_t*) l0)->f_roots);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    l5 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l1);
    if (l5.tag == 0u) {
        l6 = ((vader_struct_vader_effects_SlotRoots_t*) l0)->f_roots;
        vader_array_t* _a1_arr = vader_array_new(98u, 1u, 13u, 936u);
        ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = l2;
        l7 = (void*) _a1_arr;
        vader_array_t* _a2_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l1)
        vader_array_ref_store(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l1, l7);
        VADER_WRITE_BARRIER(_a2_slotarr->buf);
        { vader_gc_top = gc_frame.prev; return true; }
    }
    t3 = l5.payload.obj;
    vader_array_push((vader_array_t*) t3, vader_ref_box(l2));
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
    void* l17 = NULL;
    void* l18 = NULL;
    void* l33 = NULL;
    void* l34 = NULL;
    void* l35 = NULL;
    void* l36 = NULL;
    void* l38 = NULL;
    int64_t l19, l20, l24, l25, l26, l27, l29, l30;
    vader_string_t l21 = 0;
    vader_string_t l22 = 0;
    vader_string_t l31 = 0;
    vader_box_t l23 = vader_box_null(), l28 = vader_box_null(), l32 = vader_box_null(), l37 = vader_box_null();
    int32_t l39;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[5] = { &l23, &l28, &l32, &l37, &t1 };
    void** gc_raw_roots[25] = {
        &l0, &l1, &l2, &l3, &l4, &l5, &l6, &l7, &l8, &l9, &l10, &l11, &l12, &l13, &l14, &l15, &l16,
        &l17, &l18, &l33, &l34, &l35, &l36, &l38, &t0,
    };
    vader_string_t* gc_atom_roots[3] = { &l21, &l22, &l31 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 5u, 25u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(92u, 0u, 13u, 927u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(16u, 0u, 8u, 292u);
    l3 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(15u, 0u, 7u, 291u);
    l4 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(15u, 0u, 7u, 291u);
    l5 = (void*) _a3_arr;
    vader_struct_std_collections_MutableMap__i64__i32_t* _a4_obj = (vader_struct_std_collections_MutableMap__i64__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i64__i32_t));
    vader_obj_header_init(_a4_obj, 428u);
    _a4_obj->f_ekeys = l3;
    _a4_obj->f_evals = l4;
    _a4_obj->f_index = l5;
    _a4_obj->f_mask = INT64_C(0);
    _a4_obj->f_size = INT64_C(0);
    _a4_obj->f_tombs = INT64_C(0);
    l3 = (void*) _a4_obj;
    vader_array_t* _a5_arr = vader_array_new(16u, 0u, 8u, 292u);
    l4 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(21u, 0u, 0u, 299u);
    l5 = (void*) _a6_arr;
    vader_array_t* _a7_arr = vader_array_new(15u, 0u, 7u, 291u);
    l6 = (void*) _a7_arr;
    vader_struct_std_collections_MutableMap__i64__Any_t* _a8_obj = (vader_struct_std_collections_MutableMap__i64__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i64__Any_t));
    vader_obj_header_init(_a8_obj, 425u);
    _a8_obj->f_ekeys = l4;
    _a8_obj->f_evals = l5;
    _a8_obj->f_index = l6;
    _a8_obj->f_mask = INT64_C(0);
    _a8_obj->f_size = INT64_C(0);
    _a8_obj->f_tombs = INT64_C(0);
    l4 = (void*) _a8_obj;
    vader_array_t* _a9_arr = vader_array_new(16u, 0u, 8u, 292u);
    l5 = (void*) _a9_arr;
    vader_array_t* _a10_arr = vader_array_new(12u, 0u, 12u, 286u);
    l6 = (void*) _a10_arr;
    vader_array_t* _a11_arr = vader_array_new(15u, 0u, 7u, 291u);
    l7 = (void*) _a11_arr;
    vader_struct_std_collections_MutableMap__i64__bool_t* _a12_obj = (vader_struct_std_collections_MutableMap__i64__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i64__bool_t));
    vader_obj_header_init(_a12_obj, 427u);
    _a12_obj->f_ekeys = l5;
    _a12_obj->f_evals = l6;
    _a12_obj->f_index = l7;
    _a12_obj->f_mask = INT64_C(0);
    _a12_obj->f_size = INT64_C(0);
    _a12_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a12_obj;
    vader_struct_std_collections_MutableSet__i64_t* _a13_obj = (vader_struct_std_collections_MutableSet__i64_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i64_t));
    vader_obj_header_init(_a13_obj, 523u);
    _a13_obj->f_inner = t0;
    l5 = (void*) _a13_obj;
    vader_array_t* _a14_arr = vader_array_new(15u, 0u, 7u, 291u);
    l6 = (void*) _a14_arr;
    vader_array_t* _a15_arr = vader_array_new(12u, 0u, 12u, 286u);
    l7 = (void*) _a15_arr;
    vader_array_t* _a16_arr = vader_array_new(15u, 0u, 7u, 291u);
    l8 = (void*) _a16_arr;
    vader_struct_std_collections_MutableMap__i32__bool_t* _a17_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
    vader_obj_header_init(_a17_obj, 385u);
    _a17_obj->f_ekeys = l6;
    _a17_obj->f_evals = l7;
    _a17_obj->f_index = l8;
    _a17_obj->f_mask = INT64_C(0);
    _a17_obj->f_size = INT64_C(0);
    _a17_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a17_obj;
    vader_struct_std_collections_MutableSet__i32_t* _a18_obj = (vader_struct_std_collections_MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i32_t));
    vader_obj_header_init(_a18_obj, 522u);
    _a18_obj->f_inner = t0;
    l6 = (void*) _a18_obj;
    vader_array_t* _a19_arr = vader_array_new(15u, 0u, 7u, 291u);
    l7 = (void*) _a19_arr;
    vader_array_t* _a20_arr = vader_array_new(12u, 0u, 12u, 286u);
    l8 = (void*) _a20_arr;
    vader_array_t* _a21_arr = vader_array_new(15u, 0u, 7u, 291u);
    l9 = (void*) _a21_arr;
    vader_struct_std_collections_MutableMap__i32__bool_t* _a22_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
    vader_obj_header_init(_a22_obj, 385u);
    _a22_obj->f_ekeys = l7;
    _a22_obj->f_evals = l8;
    _a22_obj->f_index = l9;
    _a22_obj->f_mask = INT64_C(0);
    _a22_obj->f_size = INT64_C(0);
    _a22_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a22_obj;
    vader_struct_std_collections_MutableSet__i32_t* _a23_obj = (vader_struct_std_collections_MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i32_t));
    vader_obj_header_init(_a23_obj, 522u);
    _a23_obj->f_inner = t0;
    l7 = (void*) _a23_obj;
    vader_array_t* _a24_arr = vader_array_new(93u, 0u, 13u, 928u);
    l8 = (void*) _a24_arr;
    vader_array_t* _a25_arr = vader_array_new(93u, 0u, 13u, 928u);
    l9 = (void*) _a25_arr;
    vader_array_t* _a26_arr = vader_array_new(14u, 0u, 0u, 288u);
    l10 = (void*) _a26_arr;
    vader_array_t* _a27_arr = vader_array_new(21u, 0u, 0u, 299u);
    l11 = (void*) _a27_arr;
    vader_array_t* _a28_arr = vader_array_new(15u, 0u, 7u, 291u);
    l12 = (void*) _a28_arr;
    vader_struct_std_collections_MutableMap__string__Any___t* _a29_obj = (vader_struct_std_collections_MutableMap__string__Any___t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__Any___t));
    vader_obj_header_init(_a29_obj, 453u);
    _a29_obj->f_ekeys = l10;
    _a29_obj->f_evals = l11;
    _a29_obj->f_index = l12;
    _a29_obj->f_mask = INT64_C(0);
    _a29_obj->f_size = INT64_C(0);
    _a29_obj->f_tombs = INT64_C(0);
    l10 = (void*) _a29_obj;
    vader_array_t* _a30_arr = vader_array_new(20u, 0u, 4u, 296u);
    l11 = (void*) _a30_arr;
    vader_array_t* _a31_arr = vader_array_new(21u, 0u, 0u, 299u);
    l12 = (void*) _a31_arr;
    vader_array_t* _a32_arr = vader_array_new(15u, 0u, 7u, 291u);
    l13 = (void*) _a32_arr;
    vader_struct_std_collections_MutableMap__u64__Any_t* _a33_obj = (vader_struct_std_collections_MutableMap__u64__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__u64__Any_t));
    vader_obj_header_init(_a33_obj, 508u);
    _a33_obj->f_ekeys = l11;
    _a33_obj->f_evals = l12;
    _a33_obj->f_index = l13;
    _a33_obj->f_mask = INT64_C(0);
    _a33_obj->f_size = INT64_C(0);
    _a33_obj->f_tombs = INT64_C(0);
    l11 = (void*) _a33_obj;
    vader_array_t* _a34_arr = vader_array_new(16u, 0u, 8u, 292u);
    l12 = (void*) _a34_arr;
    vader_array_t* _a35_arr = vader_array_new(21u, 0u, 0u, 299u);
    l13 = (void*) _a35_arr;
    vader_array_t* _a36_arr = vader_array_new(15u, 0u, 7u, 291u);
    l14 = (void*) _a36_arr;
    vader_struct_std_collections_MutableMap__i64__Any_t* _a37_obj = (vader_struct_std_collections_MutableMap__i64__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i64__Any_t));
    vader_obj_header_init(_a37_obj, 425u);
    _a37_obj->f_ekeys = l12;
    _a37_obj->f_evals = l13;
    _a37_obj->f_index = l14;
    _a37_obj->f_mask = INT64_C(0);
    _a37_obj->f_size = INT64_C(0);
    _a37_obj->f_tombs = INT64_C(0);
    l12 = (void*) _a37_obj;
    vader_array_t* _a38_arr = vader_array_new(175u, 0u, 13u, 1227u);
    l13 = (void*) _a38_arr;
    vader_array_t* _a39_arr = vader_array_new(14u, 0u, 0u, 288u);
    l14 = (void*) _a39_arr;
    vader_array_t* _a40_arr = vader_array_new(21u, 0u, 0u, 299u);
    l15 = (void*) _a40_arr;
    vader_array_t* _a41_arr = vader_array_new(15u, 0u, 7u, 291u);
    l16 = (void*) _a41_arr;
    vader_struct_std_collections_MutableMap__string__Any___t* _a42_obj = (vader_struct_std_collections_MutableMap__string__Any___t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__Any___t));
    vader_obj_header_init(_a42_obj, 453u);
    _a42_obj->f_ekeys = l14;
    _a42_obj->f_evals = l15;
    _a42_obj->f_index = l16;
    _a42_obj->f_mask = INT64_C(0);
    _a42_obj->f_size = INT64_C(0);
    _a42_obj->f_tombs = INT64_C(0);
    l14 = (void*) _a42_obj;
    vader_array_t* _a43_arr = vader_array_new(14u, 0u, 0u, 288u);
    l15 = (void*) _a43_arr;
    vader_array_t* _a44_arr = vader_array_new(12u, 0u, 12u, 286u);
    l16 = (void*) _a44_arr;
    vader_array_t* _a45_arr = vader_array_new(15u, 0u, 7u, 291u);
    l17 = (void*) _a45_arr;
    vader_struct_std_collections_MutableMap__string__bool_t* _a46_obj = (vader_struct_std_collections_MutableMap__string__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__bool_t));
    vader_obj_header_init(_a46_obj, 458u);
    _a46_obj->f_ekeys = l15;
    _a46_obj->f_evals = l16;
    _a46_obj->f_index = l17;
    _a46_obj->f_mask = INT64_C(0);
    _a46_obj->f_size = INT64_C(0);
    _a46_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a46_obj;
    vader_struct_std_collections_MutableSet__string_t* _a47_obj = (vader_struct_std_collections_MutableSet__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__string_t));
    vader_obj_header_init(_a47_obj, 524u);
    _a47_obj->f_inner = t0;
    l15 = (void*) _a47_obj;
    vader_array_t* _a48_arr = vader_array_new(14u, 0u, 0u, 288u);
    l16 = (void*) _a48_arr;
    vader_array_t* _a49_arr = vader_array_new(12u, 0u, 12u, 286u);
    l17 = (void*) _a49_arr;
    vader_array_t* _a50_arr = vader_array_new(15u, 0u, 7u, 291u);
    l18 = (void*) _a50_arr;
    vader_struct_std_collections_MutableMap__string__bool_t* _a51_obj = (vader_struct_std_collections_MutableMap__string__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__bool_t));
    vader_obj_header_init(_a51_obj, 458u);
    _a51_obj->f_ekeys = l16;
    _a51_obj->f_evals = l17;
    _a51_obj->f_index = l18;
    _a51_obj->f_mask = INT64_C(0);
    _a51_obj->f_size = INT64_C(0);
    _a51_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a51_obj;
    vader_struct_std_collections_MutableSet__string_t* _a52_obj = (vader_struct_std_collections_MutableSet__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__string_t));
    vader_obj_header_init(_a52_obj, 524u);
    _a52_obj->f_inner = t0;
    l16 = (void*) _a52_obj;
    vader_struct_vader_typecheck_ImplRegistry_t* _a53_obj = (vader_struct_vader_typecheck_ImplRegistry_t*) vader_gc_alloc(sizeof(vader_struct_vader_typecheck_ImplRegistry_t));
    vader_obj_header_init(_a53_obj, 1229u);
    _a53_obj->f_by_target = l10;
    _a53_obj->f_by_decl = l11;
    _a53_obj->f_by_member = l12;
    _a53_obj->f_all = l13;
    _a53_obj->f_by_base = l14;
    _a53_obj->f_specialized_args = l15;
    _a53_obj->f_overloaded_bases = l16;
    l10 = (void*) _a53_obj;
    l11 = vader_effects_first_paths();
    vader_array_t* _a54_arr = vader_array_new(14u, 0u, 0u, 288u);
    l12 = (void*) _a54_arr;
    vader_array_t* _a55_arr = vader_array_new(14u, 0u, 0u, 288u);
    l13 = (void*) _a55_arr;
    vader_array_t* _a56_arr = vader_array_new(15u, 0u, 7u, 291u);
    l14 = (void*) _a56_arr;
    vader_array_t* _a57_arr = vader_array_new(15u, 0u, 7u, 291u);
    l15 = (void*) _a57_arr;
    vader_struct_std_collections_MutableMap__string__i32_t* _a58_obj = (vader_struct_std_collections_MutableMap__string__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__i32_t));
    vader_obj_header_init(_a58_obj, 459u);
    _a58_obj->f_ekeys = l13;
    _a58_obj->f_evals = l14;
    _a58_obj->f_index = l15;
    _a58_obj->f_mask = INT64_C(0);
    _a58_obj->f_size = INT64_C(0);
    _a58_obj->f_tombs = INT64_C(0);
    l13 = (void*) _a58_obj;
    vader_array_t* _a59_arr = vader_array_new(16u, 0u, 8u, 292u);
    l14 = (void*) _a59_arr;
    vader_array_t* _a60_arr = vader_array_new(15u, 0u, 7u, 291u);
    l15 = (void*) _a60_arr;
    vader_array_t* _a61_arr = vader_array_new(15u, 0u, 7u, 291u);
    l16 = (void*) _a61_arr;
    vader_struct_std_collections_MutableMap__i64__i32_t* _a62_obj = (vader_struct_std_collections_MutableMap__i64__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i64__i32_t));
    vader_obj_header_init(_a62_obj, 428u);
    _a62_obj->f_ekeys = l14;
    _a62_obj->f_evals = l15;
    _a62_obj->f_index = l16;
    _a62_obj->f_mask = INT64_C(0);
    _a62_obj->f_size = INT64_C(0);
    _a62_obj->f_tombs = INT64_C(0);
    l14 = (void*) _a62_obj;
    vader_array_t* _a63_arr = vader_array_new(16u, 0u, 8u, 292u);
    l15 = (void*) _a63_arr;
    vader_array_t* _a64_arr = vader_array_new(15u, 0u, 7u, 291u);
    l16 = (void*) _a64_arr;
    vader_array_t* _a65_arr = vader_array_new(15u, 0u, 7u, 291u);
    l17 = (void*) _a65_arr;
    vader_struct_std_collections_MutableMap__i64__i32_t* _a66_obj = (vader_struct_std_collections_MutableMap__i64__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i64__i32_t));
    vader_obj_header_init(_a66_obj, 428u);
    _a66_obj->f_ekeys = l15;
    _a66_obj->f_evals = l16;
    _a66_obj->f_index = l17;
    _a66_obj->f_mask = INT64_C(0);
    _a66_obj->f_size = INT64_C(0);
    _a66_obj->f_tombs = INT64_C(0);
    l15 = (void*) _a66_obj;
    vader_struct_vader_effects_PathTable_t* _a67_obj = (vader_struct_vader_effects_PathTable_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_PathTable_t));
    vader_obj_header_init(_a67_obj, 934u);
    _a67_obj->f_nodes = l11;
    _a67_obj->f_step_names = l12;
    _a67_obj->f_step_ids = l13;
    _a67_obj->f_children = l14;
    _a67_obj->f_joins = l15;
    l11 = (void*) _a67_obj;
    l12 = vader_effects_any_effects();
    vader_array_t* _a68_arr = vader_array_new(14u, 0u, 0u, 288u);
    l13 = (void*) _a68_arr;
    vader_array_t* _a69_arr = vader_array_new(21u, 0u, 0u, 299u);
    l14 = (void*) _a69_arr;
    vader_array_t* _a70_arr = vader_array_new(15u, 0u, 7u, 291u);
    l15 = (void*) _a70_arr;
    vader_struct_std_collections_MutableMap__string__Any___t* _a71_obj = (vader_struct_std_collections_MutableMap__string__Any___t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__Any___t));
    vader_obj_header_init(_a71_obj, 453u);
    _a71_obj->f_ekeys = l13;
    _a71_obj->f_evals = l14;
    _a71_obj->f_index = l15;
    _a71_obj->f_mask = INT64_C(0);
    _a71_obj->f_size = INT64_C(0);
    _a71_obj->f_tombs = INT64_C(0);
    l13 = (void*) _a71_obj;
    vader_array_t* _a72_arr = vader_array_new(14u, 0u, 0u, 288u);
    l14 = (void*) _a72_arr;
    vader_struct_vader_effects_CalleeIndex_t* _a73_obj = (vader_struct_vader_effects_CalleeIndex_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_CalleeIndex_t));
    vader_obj_header_init(_a73_obj, 913u);
    _a73_obj->f_functions = l2;
    _a73_obj->f_nodes = l3;
    _a73_obj->f_bodyless = l4;
    _a73_obj->f_frozen_views = l5;
    _a73_obj->f_view = vader_box_obj(0u, NULL);
    _a73_obj->f_view_nodes = l6;
    _a73_obj->f_variant_data = l7;
    _a73_obj->f_constants = l8;
    _a73_obj->f_defaults = l9;
    _a73_obj->f_impls = l10;
    _a73_obj->f_paths = l11;
    _a73_obj->f_any = l12;
    _a73_obj->f_project = l0;
    _a73_obj->f_members = l13;
    _a73_obj->f_unknown = l14;
    l2 = (void*) _a73_obj;
    l3 = ((vader_struct_vader_resolver_LoadedProject_t*) l0)->f_modules;
    l4 = ((vader_struct_std_collections_MutableMap__string__vader_resolver_LoadedModule_t*) l3)->f_ekeys;
    l5 = ((vader_struct_std_collections_MutableMap__string__vader_resolver_LoadedModule_t*) l3)->f_evals;
    l19 = INT64_C(0);
    l20 = ((vader_struct_std_collections_MutableMap__string__vader_resolver_LoadedModule_t*) l3)->f_size;
    while ((l19 < l20)) {
        vader_array_t* _a74_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a74_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a74_slotarr, l19)
        t1 = vader_array_box_slots(_a74_slotarr->buf)[_a74_slotarr->offset + (size_t) l19];
        l21 = t1.payload.s;
        vader_array_t* _a75_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a75_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a75_slotarr, l19)
        l3 = vader_array_ref_load_obj(_a75_slotarr->buf, _a75_slotarr->offset + (size_t) l19);
        l22 = l21;
        l6 = l3;
        l23 = std_collections_MutableMap_std_core_Index_at__string__Any(l1, l22);
        if (!(l23.tag == 0u)) {
            l7 = l23.payload.obj;
            l8 = ((vader_struct_vader_resolver_Module_t*) ((vader_struct_vader_resolver_LoadedModule_t*) l6)->f_module)->f_files;
            l24 = ((vader_array_t*) l8)->length;
            l25 = INT64_C(0);
            while ((l25 < l24)) {
                vader_array_t* _a76_slotarr = ((vader_array_t*) l8);
                VADER_ARRAY_RESOLVE_BUF(_a76_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a76_slotarr, l25)
                l9 = vader_array_ref_load_obj(_a76_slotarr->buf, _a76_slotarr->offset + (size_t) l25);
                l10 = ((vader_struct_vader_effects_CalleeIndex_t*) l2)->f_impls;
                l11 = ((vader_struct_toolchain_ast_Program_t*) ((vader_struct_vader_resolver_SourceFile_t*) l9)->f_program)->f_decls;
                l12 = ((vader_struct_vader_typecheck_TypedProgram_t*) l7)->f_resolved;
                vader_typecheck_collect_impls(l10, l11, l12);
                l13 = ((vader_struct_toolchain_ast_Program_t*) ((vader_struct_vader_resolver_SourceFile_t*) l9)->f_program)->f_decls;
                l26 = ((vader_array_t*) l13)->length;
                l27 = INT64_C(0);
                while ((l27 < l26)) {
                    vader_array_t* _a77_slotarr = ((vader_array_t*) l13);
                    VADER_ARRAY_RESOLVE_BUF(_a77_slotarr)
                    l28 = vader_array_ref_load_box(_a77_slotarr->buf, _a77_slotarr->offset + (size_t) l27);
                    if (l28.tag == 564u) {
                        l14 = l28.payload.obj;
                        vader_effects_register(l2, l14, l7);
                    } else if (l28.tag == 573u) {
                        t0 = l28.payload.obj;
                        l15 = ((vader_struct_toolchain_ast_ImplDecl_t*) t0)->f_members;
                        l29 = ((vader_array_t*) l15)->length;
                        l30 = INT64_C(0);
                        while ((l30 < l29)) {
                            vader_array_t* _a78_slotarr = ((vader_array_t*) l15);
                            VADER_ARRAY_RESOLVE_BUF(_a78_slotarr)
                            l16 = vader_array_ref_load_obj(_a78_slotarr->buf, _a78_slotarr->offset + (size_t) l30);
                            vader_effects_register(l2, l16, l7);
                            l30 = (l30 + INT64_C(1));
                        }
                    } else if (l28.tag == 547u) {
                        l18 = ((vader_struct_vader_resolver_CollectedModule_t*) ((vader_struct_vader_resolver_LoadedModule_t*) l6)->f_collected)->f_symbols;
                        t0 = l28.payload.obj;
                        l31 = ((vader_struct_toolchain_ast_ConstDecl_t*) t0)->f_name;
                        l32 = std_collections_MutableMap_std_core_Index_at__string__Any(l18, l31);
                        if (l32.tag == 0u) {
                            l27 = (l27 + INT64_C(1));
                            continue;
                        }
                        l17 = l32.payload.obj;
                        l33 = ((vader_struct_vader_effects_CalleeIndex_t*) l2)->f_constants;
                        t0 = l28.payload.obj;
                        l34 = vader_effects_constant_initialiser(t0, l17, l7);
                        vader_array_push((vader_array_t*) l33, vader_ref_box(l34));
                    } else if (l28.tag == 607u) {
                        l35 = l28.payload.obj;
                        vader_effects_register_defaults(l2, l35, l7);
                    } else if (l28.tag == 558u) {
                        t0 = l28.payload.obj;
                        l37 = vader_typecheck_declared_enum_data(t0, l7);
                        if (l37.tag == 0u) {
                            l27 = (l27 + INT64_C(1));
                            continue;
                        }
                        l36 = l37.payload.obj;
                        l38 = ((vader_struct_vader_effects_CalleeIndex_t*) l2)->f_variant_data;
                        l39 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_types_StructType_t*) l36)->f_symbol)->f_id;
                        std_collections_add__i32(l38, l39);
                    } else if (!((l28.tag == 536u || l28.tag == 574u || l28.tag == 614u || l28.tag == 616u))) {
                        vader_unreachable("non-exhaustive match (T3013 should have caught this)");
                    }
                    l27 = (l27 + INT64_C(1));
                }
                l25 = (l25 + INT64_C(1));
            }
        }
        l19 = (l19 + INT64_C(1));
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_effects_index_value(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l3 = vader_box_null(), l5 = vader_box_null(), l8 = vader_box_null();
    int64_t l4;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l9 = NULL;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[5] = { &l2, &l3, &l5, &l8, &t0 };
    void** gc_raw_roots[5] = { &l0, &l1, &l6, &l7, &l9 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 5u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_toolchain_ast_IndexExpr_t*) l1)->f_target;
    l2 = vader_effects_value(l0, l2);
    l3 = ((vader_struct_toolchain_ast_IndexExpr_t*) l1)->f_index;
    l3 = vader_effects_value(l0, l3);
    l4 = ((vader_struct_toolchain_ast_IndexExpr_t*) l1)->f_id;
    l5 = vader_effects_site_callee(l0, (uint8_t) 2, l4);
    if (!(l5.tag == 0u)) {
        if (!(l5.tag == 1198u)) {
            vader_array_t* _a0_arr = vader_array_new(214u, 2u, 0u, 1414u);
            vader_array_box_slots(_a0_arr->buf)[_a0_arr->offset + 1u] = l3;
            vader_array_box_slots(_a0_arr->buf)[_a0_arr->offset + 0u] = l2;
            l6 = (void*) _a0_arr;
            l7 = ((vader_struct_toolchain_ast_IndexExpr_t*) l1)->f_span;
            l3 = ((vader_struct_toolchain_ast_IndexExpr_t*) l1)->f_target;
            l8 = ((vader_struct_toolchain_ast_IndexExpr_t*) l1)->f_index;
            vader_array_t* _a1_arr = vader_array_new(216u, 2u, 13u, 1457u);
            ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 1u] = l8.payload.obj;
            ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = l3.payload.obj;
            l9 = (void*) _a1_arr;
            t0 = vader_effects_call(l0, l5, l6, l7, l9);
            { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    if (!(((vader_struct_toolchain_ast_IndexExpr_t*) l1)->f_index.tag == 597u)) {
        t0 = vader_effects_step_slot(l0, l2, 856u);
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
    void* l9 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    void* l12 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[14] = {
        &l0, &l1, &l2, &l3, &l4, &l5, &l6, &l7, &l8, &l9, &l10, &l11, &l12, &t0,
    };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 14u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l4 = vader_effects_new_skeleton(INT64_C(0));
    l5 = ((vader_struct_vader_effects_Initialiser_t*) l3)->f_typed;
    vader_array_t* _a0_arr = vader_array_new(15u, 0u, 7u, 291u);
    l6 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(16u, 0u, 8u, 292u);
    l7 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(15u, 0u, 7u, 291u);
    l8 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__i32__i64_t* _a3_obj = (vader_struct_std_collections_MutableMap__i32__i64_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__i64_t));
    vader_obj_header_init(_a3_obj, 388u);
    _a3_obj->f_ekeys = l6;
    _a3_obj->f_evals = l7;
    _a3_obj->f_index = l8;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    l6 = (void*) _a3_obj;
    vader_array_t* _a4_arr = vader_array_new(90u, 0u, 13u, 924u);
    l7 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_new(16u, 0u, 8u, 292u);
    l8 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(12u, 0u, 12u, 286u);
    l9 = (void*) _a6_arr;
    vader_array_t* _a7_arr = vader_array_new(15u, 0u, 7u, 291u);
    l10 = (void*) _a7_arr;
    vader_struct_std_collections_MutableMap__i64__bool_t* _a8_obj = (vader_struct_std_collections_MutableMap__i64__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i64__bool_t));
    vader_obj_header_init(_a8_obj, 427u);
    _a8_obj->f_ekeys = l8;
    _a8_obj->f_evals = l9;
    _a8_obj->f_index = l10;
    _a8_obj->f_mask = INT64_C(0);
    _a8_obj->f_size = INT64_C(0);
    _a8_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a8_obj;
    vader_struct_std_collections_MutableSet__i64_t* _a9_obj = (vader_struct_std_collections_MutableSet__i64_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i64_t));
    vader_obj_header_init(_a9_obj, 523u);
    _a9_obj->f_inner = t0;
    l8 = (void*) _a9_obj;
    vader_array_t* _a10_arr = vader_array_new(16u, 0u, 8u, 292u);
    l9 = (void*) _a10_arr;
    vader_array_t* _a11_arr = vader_array_new(12u, 0u, 12u, 286u);
    l10 = (void*) _a11_arr;
    vader_array_t* _a12_arr = vader_array_new(15u, 0u, 7u, 291u);
    l11 = (void*) _a12_arr;
    vader_struct_std_collections_MutableMap__i64__bool_t* _a13_obj = (vader_struct_std_collections_MutableMap__i64__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i64__bool_t));
    vader_obj_header_init(_a13_obj, 427u);
    _a13_obj->f_ekeys = l9;
    _a13_obj->f_evals = l10;
    _a13_obj->f_index = l11;
    _a13_obj->f_mask = INT64_C(0);
    _a13_obj->f_size = INT64_C(0);
    _a13_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a13_obj;
    vader_struct_std_collections_MutableSet__i64_t* _a14_obj = (vader_struct_std_collections_MutableSet__i64_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i64_t));
    vader_obj_header_init(_a14_obj, 523u);
    _a14_obj->f_inner = t0;
    l9 = (void*) _a14_obj;
    vader_array_t* _a15_arr = vader_array_new(15u, 0u, 7u, 291u);
    l10 = (void*) _a15_arr;
    vader_array_t* _a16_arr = vader_array_new(12u, 0u, 12u, 286u);
    l11 = (void*) _a16_arr;
    vader_array_t* _a17_arr = vader_array_new(15u, 0u, 7u, 291u);
    l12 = (void*) _a17_arr;
    vader_struct_std_collections_MutableMap__i32__bool_t* _a18_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
    vader_obj_header_init(_a18_obj, 385u);
    _a18_obj->f_ekeys = l10;
    _a18_obj->f_evals = l11;
    _a18_obj->f_index = l12;
    _a18_obj->f_mask = INT64_C(0);
    _a18_obj->f_size = INT64_C(0);
    _a18_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a18_obj;
    vader_struct_std_collections_MutableSet__i32_t* _a19_obj = (vader_struct_std_collections_MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i32_t));
    vader_obj_header_init(_a19_obj, 522u);
    _a19_obj->f_inner = t0;
    l10 = (void*) _a19_obj;
    vader_struct_vader_effects_WalkCtx_t* _a20_obj = (vader_struct_vader_effects_WalkCtx_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_WalkCtx_t));
    vader_obj_header_init(_a20_obj, 943u);
    _a20_obj->f_s = l4;
    _a20_obj->f_typed = l5;
    _a20_obj->f_index = l0;
    _a20_obj->f_slots = l6;
    _a20_obj->f_lambda_depth = INT32_C(0);
    _a20_obj->f_result_effect = (uint8_t) 4;
    _a20_obj->f_frozen = l1;
    _a20_obj->f_widenings = l2;
    _a20_obj->f_roots = l7;
    _a20_obj->f_place_bases = l8;
    _a20_obj->f_pure = l9;
    _a20_obj->f_seen_names = l10;
    t0 = (void*) _a20_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_effects_insert(void* l0, void* l1, int64_t l2, int64_t l3) {
    void* l4 = NULL;
    int64_t l5;
    vader_box_t t0 = vader_box_null();
    int64_t t1;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[3] = { &l0, &l1, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_push((vader_array_t*) ((vader_struct_vader_effects_ParamEffects_t*) l0)->f_accesses, vader_ref_box(l1));
    vader_array_push_i64((vader_array_t*) ((vader_struct_vader_effects_ParamEffects_t*) l0)->f_origins, l2);
    vader_array_push_i64((vader_array_t*) ((vader_struct_vader_effects_ParamEffects_t*) l0)->f_origins, l3);
    if (!(((vader_struct_vader_effects_ParamEffects_t*) l0)->f_keys.tag == 0u)) {
        t0 = ((vader_struct_vader_effects_ParamEffects_t*) l0)->f_keys;
        l4 = t0.payload.obj;
        l5 = vader_effects_access_key(l1);
        std_collections_add__i64(l4, l5);
        { vader_gc_top = gc_frame.prev; return; }
    }
    t1 = ((vader_array_t*) ((vader_struct_vader_effects_ParamEffects_t*) l0)->f_accesses)->length;
    if ((t1 > INT64_C(8))) {
        l4 = vader_effects_key_set(((vader_struct_vader_effects_ParamEffects_t*) l0)->f_accesses);
        ((vader_struct_vader_effects_ParamEffects_t*) l0)->f_keys = vader_ref_box(l4);
        VADER_WRITE_BARRIER((vader_struct_vader_effects_ParamEffects_t*) l0);
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
    l2 = vader_effects_path_to(l0, 856u);
    l3 = vader_types_core_trait_key(485u);
    l4 = vader_types_core_trait_key(499u);
    l5 = concat_2(l3, 363u);
    if (l1 == l5) {
        t0 = vader_effects_none();
        vader_array_t* _a0_arr = vader_array_new(95u, 1u, 13u, 932u);
        ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = t0;
        t0 = (void*) _a0_arr;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l5 = concat_2(l3, 371u);
    if (l1 == l5) {
        t0 = vader_effects_push_effects(INT32_C(0));
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l5 = concat_2(l3, 372u);
    if (l1 == l5) {
        t0 = vader_effects_push_effects(l2);
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l5 = concat_2(l3, 356u);
    if (l1 == l5) {
        t0 = vader_effects_copy_to_effects(l2);
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l5 = concat_2(l3, 373u);
    if (l1 == l5) {
        t0 = vader_effects_remove_last_effects(l2);
        vader_array_t* _a1_arr = vader_array_new(95u, 1u, 13u, 932u);
        ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = t0;
        t0 = (void*) _a1_arr;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = concat_2(l3, 355u);
    if (l1 == l3) {
        t0 = vader_effects_effects_of((uint8_t) 2, INT32_C(0));
        vader_array_t* _a2_arr = vader_array_new(95u, 1u, 13u, 932u);
        ((void**) _a2_arr->buf->slots)[_a2_arr->offset + 0u] = t0;
        t0 = (void*) _a2_arr;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = concat_2(l4, 364u);
    if (l1 == l3) {
        l6 = vader_effects_none();
        l7 = vader_effects_none();
        vader_array_t* _a3_arr = vader_array_new(95u, 2u, 13u, 932u);
        ((void**) _a3_arr->buf->slots)[_a3_arr->offset + 1u] = l7;
        ((void**) _a3_arr->buf->slots)[_a3_arr->offset + 0u] = l6;
        t0 = (void*) _a3_arr;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = concat_2(l4, 380u);
    if (l1 == l3) {
        t0 = vader_effects_writes_bytes(l2);
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = concat_2(l4, 365u);
    if (l1 == l3) {
        t0 = vader_effects_memory_copy_effects(l2);
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = concat_2(l4, 361u);
    if (l1 == l3) {
        l6 = vader_effects_none();
        l7 = vader_effects_none();
        vader_array_t* _a4_arr = vader_array_new(95u, 2u, 13u, 932u);
        ((void**) _a4_arr->buf->slots)[_a4_arr->offset + 1u] = l7;
        ((void**) _a4_arr->buf->slots)[_a4_arr->offset + 0u] = l6;
        t0 = (void*) _a4_arr;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = concat_2(l4, 383u);
    if (l1 == l3) {
        t0 = vader_effects_writes_bytes(l2);
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == 2404u) {
        t0 = vader_effects_none();
        vader_array_t* _a5_arr = vader_array_new(95u, 1u, 13u, 932u);
        ((void**) _a5_arr->buf->slots)[_a5_arr->offset + 0u] = t0;
        t0 = (void*) _a5_arr;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l1 == 2655u)) {
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
        t1 = concat_3(l4, 343u, l5);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = ((vader_struct_vader_resolver_ResolvedModule_t*) ((vader_struct_vader_typecheck_TypedProgram_t*) l2)->f_resolved)->f_display_path;
    l5 = ((vader_struct_toolchain_ast_FnDecl_t*) l1)->f_name;
    t1 = concat_3(l4, 343u, l5);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_effects_intrinsic_value(void* l0, void* l1) {
    bool l2;
    void* l3 = NULL;
    vader_box_t l4 = vader_box_null(), l5 = vader_box_null(), l7 = vader_box_null();
    vader_string_t l6 = 0;
    vader_string_t t0 = 0;
    int64_t t1;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[4] = { &l4, &l5, &l7, &t2 };
    void** gc_raw_roots[3] = { &l0, &l1, &l3 };
    vader_string_t* gc_atom_roots[2] = { &l6, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l1)->f_name;
    if (t0 != 1812u) {
        l2 = true;
    } else {
        t1 = ((vader_array_t*) ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l1)->f_args)->length;
        l2 = t1 != INT64_C(2);
    }
    if (l2) {
        l3 = ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l1)->f_args;
        t2 = vader_effects_sequence_walked(l0, l3);
        { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l1)->f_args);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
    l4 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT32_C(0));
    l4 = vader_effects_value(l0, l4);
    vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l1)->f_args);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, INT32_C(1))
    l5 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) INT32_C(1));
    vader_effects_discard(l0, l5);
    vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l1)->f_args);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, INT32_C(1))
    t2 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) INT32_C(1));
    l5 = toolchain_ast_string_literal_text(t2);
    if (l5.tag == 0u) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l1)->f_args);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, INT32_C(0))
        l7 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) INT32_C(0));
        t2 = vader_effects_any_field(l0, l7, l4);
        { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l6 = l5.payload.s;
    t2 = vader_effects_step_slot(l0, l4, l6);
    { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
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

static bool vader_effects_is_seed(void* l0, int64_t l1) {
    int64_t l2;
    vader_box_t l3;
    void* t0;
    bool t1;
    l2 = ((vader_struct_vader_effects_Skeleton_t*) l0)->f_params;
    if ((l1 < l2)) {
        return false;
    }
    l3 = ((vader_struct_vader_effects_Skeleton_t*) l0)->f_seeds;
    if (l3.tag == 0u) {
        return false;
    }
    t0 = l3.payload.obj;
    t1 = std_collections_MutableMap_std_core_Contains_contains__i64__i64(t0, l1);
    return t1;
}

bool vader_effects_is_the_view(void* l0) {
    int32_t t0;
    t0 = ((vader_struct_vader_effects_Access_t*) l0)->f_path;
    if (t0 == INT32_C(0)) {
        return true;
    }
    t0 = ((vader_struct_vader_effects_Access_t*) l0)->f_path;
    return t0 == INT32_C(1);
}

bool vader_effects_is_unknown(void* l0) {
    return ((vader_struct_vader_effects_Access_t*) l0)->f_effect == INT32_C(5);
}

bool vader_effects_is_view(void* l0) {
    if (((vader_struct_vader_effects_FrozenRoot_t*) l0)->f_binding.tag == 0u) {
        return ((vader_struct_vader_effects_FrozenRoot_t*) l0)->f_origin == INT32_C(1);
    }
    return false;
}

static int32_t vader_effects_joined(void* l0, int32_t l1, int32_t l2) {
    int64_t l3, l7, l8;
    vader_box_t l4 = vader_box_null();
    int32_t l5, l9;
    void* l6 = NULL;
    void* t0 = NULL;
    bool t1;
    int32_t t2;
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
    if (l1 == INT32_C(0)) {
        { int32_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = vader_effects_pair_key(l1, l2);
    l4 = std_collections_MutableMap_std_core_Index_at__i64__i32(((vader_struct_vader_effects_PathTable_t*) l0)->f_joins, l3);
    if (!(l4.tag == 0u)) {
        t2 = ((int32_t) l4.payload.i);
        { int32_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l5 = l1;
    l6 = vader_effects_steps_of(l0, l2);
    l7 = ((vader_array_t*) l6)->length;
    l8 = INT64_C(0);
    while ((l8 < l7)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l9 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l8];
        l5 = vader_effects_child(l0, l5, l9);
        l8 = (l8 + INT64_C(1));
    }
    vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_effects_PathTable_t*) l0)->f_nodes);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l2)
    t0 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l2);
    t1 = ((vader_struct_vader_effects_PathNode_t*) t0)->f_deeper;
    if (t1) {
        l5 = vader_effects_cut(l0, l5);
        std_collections_MutableMap_std_core_IndexSet_set_at__i64__i32(((vader_struct_vader_effects_PathTable_t*) l0)->f_joins, l3, l5);
        { int32_t __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
    }
    std_collections_MutableMap_std_core_IndexSet_set_at__i64__i32(((vader_struct_vader_effects_PathTable_t*) l0)->f_joins, l3, l5);
    { int32_t __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
}

bool vader_effects_keeps(void* l0) {
    bool t0;
    t0 = vader_effects_is_unknown(l0);
    if (t0) {
        return true;
    }
    return ((vader_struct_vader_effects_Access_t*) l0)->f_effect == INT32_C(3);
}

static int64_t vader_effects_key_of(int32_t l0, uint8_t l1) {
    int64_t l2, l3;
    int64_t t0;
    l2 = vader_chk_mul(i64, ((int64_t) (int32_t) l0), INT64_C(8));
    l3 = ((int64_t) (uint8_t) l1);
    t0 = vader_chk_add(i64, l2, l3);
    return t0;
}

static void* vader_effects_key_set(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    int64_t l4, l5, l6;
    void* t0 = NULL;
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(16u, 0u, 8u, 292u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(12u, 0u, 12u, 286u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(15u, 0u, 7u, 291u);
    l3 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__i64__bool_t* _a3_obj = (vader_struct_std_collections_MutableMap__i64__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i64__bool_t));
    vader_obj_header_init(_a3_obj, 427u);
    _a3_obj->f_ekeys = l1;
    _a3_obj->f_evals = l2;
    _a3_obj->f_index = l3;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a3_obj;
    vader_struct_std_collections_MutableSet__i64_t* _a4_obj = (vader_struct_std_collections_MutableSet__i64_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i64_t));
    vader_obj_header_init(_a4_obj, 523u);
    _a4_obj->f_inner = t0;
    l1 = (void*) _a4_obj;
    l2 = l0;
    l4 = ((vader_array_t*) l2)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a5_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        t0 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l5);
        l6 = vader_effects_access_key(t0);
        std_collections_add__i64(l1, l6);
        l5 = (l5 + INT64_C(1));
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_effects_known_params(vader_box_t l0, void* l1) {
    vader_box_t l2;
    int32_t l3;
    void* t0;
    void* t1;
    if (l0.tag == 914u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_effects_CalleeNode_t*) t0)->f_node;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
        l2 = vader_ref_box(t0);
        return l2;
    }
    if (l0.tag == 929u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_effects_KnownEffects_t*) t0)->f_params;
        l2 = vader_ref_box(t1);
    } else {
        if (!(l0.tag == 912u)) {
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
    l3 = ((vader_struct_toolchain_ast_LambdaExpr_t*) l1)->f_span;
    vader_effects_escape(l0, l4, (uint8_t) 3, l3);
    t0 = ((vader_struct_vader_effects_WalkCtx_t*) l0)->f_lambda_depth;
    l2 = vader_chk_sub(i32, t0, INT32_C(1));
    ((vader_struct_vader_effects_WalkCtx_t*) l0)->f_lambda_depth = l2;
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static int64_t vader_effects_local_slot(void* l0, int32_t l1) {
    vader_box_t l2 = vader_box_null();
    int64_t l3;
    int64_t t0;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = std_collections_MutableMap_std_core_Index_at__i32__i64(((vader_struct_vader_effects_WalkCtx_t*) l0)->f_slots, l1);
    if (!(l2.tag == 0u)) {
        t0 = ((int64_t) l2.payload.i);
        { int64_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = vader_effects_fresh_slot(((vader_struct_vader_effects_WalkCtx_t*) l0)->f_s);
    std_collections_MutableMap_std_core_IndexSet_set_at__i32__i64(((vader_struct_vader_effects_WalkCtx_t*) l0)->f_slots, l1, l3);
    { int64_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_effects_loop_element(void* l0, vader_box_t l1, vader_box_t l2) {
    int64_t l3;
    vader_box_t l4 = vader_box_null(), l5 = vader_box_null();
    void* l6 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    bool t0;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[5] = { &l1, &l2, &l4, &l5, &t1 };
    void** gc_raw_roots[4] = { &l0, &l6, &l7, &l8 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 5u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_effects_steps_through_elements(l0, l1);
    if (!(t0)) {
        l3 = VADER_UNION_FIELD(int64_t, vader_struct_toolchain_ast_ArrayTypeExpr_t, f_id, l1.payload.obj);
        l4 = vader_effects_site_callee(l0, (uint8_t) 5, l3);
        l4 = vader_effects_converted_by(l0, l4, l2, l1);
        l3 = VADER_UNION_FIELD(int64_t, vader_struct_toolchain_ast_ArrayTypeExpr_t, f_id, l1.payload.obj);
        l5 = vader_effects_site_callee(l0, (uint8_t) 6, l3);
        vader_array_t* _a0_arr = vader_array_new(214u, 1u, 0u, 1414u);
        vader_array_box_slots(_a0_arr->buf)[_a0_arr->offset + 0u] = l4;
        l6 = (void*) _a0_arr;
        l7 = VADER_UNION_FIELD(void*, vader_struct_toolchain_ast_ArrayTypeExpr_t, f_span, l1.payload.obj);
        vader_array_t* _a1_arr = vader_array_new(216u, 0u, 13u, 1457u);
        l8 = (void*) _a1_arr;
        t1 = vader_effects_call(l0, l5, l6, l7, l8);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_effects_step_slot(l0, l2, 856u);
    { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_effects_lost_write(void* l0) {
    void* l1;
    vader_box_t l2;
    l2 = ((vader_struct_vader_effects_FrozenSite_t*) l0)->f_chain;
    if (l2.tag == 0u) {
        return ((vader_struct_vader_effects_FrozenSite_t*) l0)->f_span;
    }
    l1 = l2.payload.obj;
    l2 = ((vader_struct_vader_effects_FaultChain_t*) l1)->f_write;
    if (l2.tag == 0u) {
        return ((vader_struct_vader_effects_FrozenSite_t*) l0)->f_span;
    }
    l1 = l2.payload.obj;
    return ((vader_struct_vader_effects_FaultWrite_t*) l1)->f_span;
}

static bool vader_effects_makes_frozen_view(vader_string_t l0) {
    return l0 == 2403u;
}

static bool vader_effects_makes_view(void* l0, vader_box_t l1) {
    int64_t l2, l5;
    void* l3 = NULL;
    void* l4 = NULL;
    vader_box_t l6 = vader_box_null();
    void* t0 = NULL;
    bool t1;
    vader_box_t* gc_roots[2] = { &l1, &l6 };
    void** gc_raw_roots[4] = { &l0, &l3, &l4, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l1.tag == 1209u) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_toolchain_ast_FnDecl_t*) ((vader_struct_vader_typecheck_DirectFn_t*) t0)->f_decl)->f_id;
        t1 = std_collections_MutableSet_std_core_Contains_contains__i64(((vader_struct_vader_effects_CalleeIndex_t*) l0)->f_frozen_views, l2);
        if (t1) {
            { vader_gc_top = gc_frame.prev; return true; }
        }
    }
    t1 = std_collections_is_empty__i32(((vader_struct_vader_effects_CalleeIndex_t*) l0)->f_view_nodes);
    if (t1) {
        { vader_gc_top = gc_frame.prev; return false; }
    }
    l3 = vader_effects_targets_of(l0, l1);
    vader_struct___lambda_env_vader_effects_29_t* _a0_obj = (vader_struct___lambda_env_vader_effects_29_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_effects_29_t));
    vader_obj_header_init(_a0_obj, 323u);
    _a0_obj->f_cap_0 = l0;
    l4 = (void*) _a0_obj;
    l2 = ((vader_array_t*) l3)->length;
    l5 = INT64_C(0);
    while ((l5 < l2)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l6 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5);
        t1 = __lambda_vader_effects_28(l4, l6);
        if (t1) {
            { vader_gc_top = gc_frame.prev; return true; }
        }
        l5 = (l5 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return false; }
}

static void vader_effects_mark(void* l0, vader_box_t l1, int32_t l2, uint8_t l3, void* l4) {
    void* l5 = NULL;
    int64_t l6;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[3] = { &l0, &l4, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l1.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l5 = ((vader_struct_vader_effects_WalkCtx_t*) l0)->f_s;
    l6 = ((int64_t) l1.payload.i);
    vader_effects_add_mark(l5, l6, l2, l3, l4);
    { vader_gc_top = gc_frame.prev; return; }
}

static bool vader_effects_mark_fresh(void* l0, void* l1) {
    void* l2 = NULL;
    int64_t l3;
    int32_t l4;
    bool t0;
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_typecheck_FreshReads_t*) ((vader_struct_vader_effects_FrozenSites_t*) l0)->f_fresh)->f_uses;
    l3 = ((vader_struct_vader_effects_ConstantUse_t*) l1)->f_node;
    std_collections_add__i64(l2, l3);
    l2 = ((vader_struct_vader_typecheck_FreshReads_t*) ((vader_struct_vader_effects_FrozenSites_t*) l0)->f_fresh)->f_constants;
    l4 = ((vader_struct_vader_effects_ConstantUse_t*) l1)->f_symbol;
    t0 = std_collections_add__i32(l2, l4);
    { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static int64_t vader_effects_mark_origin(int64_t l0) {
    int64_t t0;
    t0 = vader_chk_sub(i64, INT64_C(-2), l0);
    return t0;
}

static bool vader_effects_mark_roots(void* l0, void* l1, int32_t l2, uint8_t l3, void* l4, bool l5, int64_t l6, int64_t l7) {
    bool l8;
    void* l9 = NULL;
    void* l12 = NULL;
    void* l16 = NULL;
    int64_t l10, l11, l15;
    int32_t l13, l14;
    bool t0;
    void** gc_raw_roots[6] = { &l0, &l1, &l4, &l9, &l12, &l16 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 6u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l8 = false;
    l9 = l1;
    l10 = ((vader_array_t*) l9)->length;
    l11 = INT64_C(0);
    while ((l11 < l10)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l9);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l12 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l11);
        l13 = ((vader_struct_vader_effects_Root_t*) l12)->f_path;
        l14 = vader_effects_composed(l4, l13, l2, l5);
        l15 = ((vader_struct_vader_effects_Root_t*) l12)->f_param;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l15)
        l16 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l15);
        t0 = vader_effects_include(l4, l16, l14, l3, l6, l7);
        if (t0) {
            l8 = true;
        }
        l11 = (l11 + INT64_C(1));
    }
    { bool __vret = l8; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_effects_match_value(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l8 = vader_box_null(), l9 = vader_box_null(), l10 = vader_box_null(), l11 = vader_box_null(), l12 = vader_box_null();
    void* l3 = NULL;
    void* l5 = NULL;
    void* l7 = NULL;
    int64_t l4, l6;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[7] = { &l2, &l8, &l9, &l10, &l11, &l12, &t0 };
    void** gc_raw_roots[5] = { &l0, &l1, &l3, &l5, &l7 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 7u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_toolchain_ast_MatchExpr_t*) l1)->f_scrutinee;
    l2 = vader_effects_value(l0, l2);
    if (!(((vader_struct_toolchain_ast_MatchExpr_t*) l1)->f_binding.tag == 0u)) {
        t0 = ((vader_struct_toolchain_ast_MatchExpr_t*) l1)->f_binding;
        l3 = t0.payload.obj;
        vader_effects_bind(l0, vader_ref_box(l3), l2);
    }
    vader_array_t* _a0_arr = vader_array_new(214u, 0u, 0u, 1414u);
    l3 = (void*) _a0_arr;
    l4 = ((vader_array_t*) ((vader_struct_toolchain_ast_MatchExpr_t*) l1)->f_arms)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l3, (int64_t) l4);
    l3 = (void*) _a1_arr;
    l5 = ((vader_struct_toolchain_ast_MatchExpr_t*) l1)->f_arms;
    l4 = ((vader_array_t*) l5)->length;
    l6 = INT64_C(0);
    while ((l6 < l4)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l6)
        l7 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l6);
        l8 = ((vader_struct_toolchain_ast_MatchArm_t*) l7)->f_pattern;
        vader_effects_bind_pattern(l0, l8, l2);
        l9 = ((vader_struct_toolchain_ast_MatchArm_t*) l7)->f_guard;
        if (!(l9.tag == 0u)) {
            l10 = l9;
            vader_effects_discard(l0, l10);
        }
        l11 = ((vader_struct_toolchain_ast_MatchArm_t*) l7)->f_body;
        l12 = vader_effects_value(l0, l11);
        vader_array_push((vader_array_t*) l3, l12);
        l6 = (l6 + INT64_C(1));
    }
    t0 = vader_effects_one_of(l0, l3);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

bool vader_effects_may_be_element(vader_box_t l0, vader_box_t l1) {
    bool l2;
    void* l3 = NULL;
    void* l4 = NULL;
    int64_t l5, l6;
    vader_box_t l7 = vader_box_null();
    void* t0 = NULL;
    bool t1;
    vader_box_t* gc_roots[3] = { &l0, &l1, &l7 };
    void** gc_raw_roots[3] = { &l3, &l4, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 1281u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_types_UnionType_t*) t0)->f_variants;
        vader_struct___lambda_env_vader_effects_39_t* _a0_obj = (vader_struct___lambda_env_vader_effects_39_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_effects_39_t));
        vader_obj_header_init(_a0_obj, 328u);
        _a0_obj->f_cap_0 = l1;
        l4 = (void*) _a0_obj;
        l2 = false;
        l5 = ((vader_array_t*) l3)->length;
        l6 = INT64_C(0);
        {
            while ((l6 < l5)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                l7 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l6);
                t1 = __lambda_vader_effects_38(l4, l7);
                if (t1) {
                    l2 = true;
                    goto end_17;
                }
                l6 = (l6 + INT64_C(1));
            }
            l2 = false;
        } end_17: ;
        { bool __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1264u) {
        t0 = l0.payload.obj;
        l2 = vader_effects_may_be_element(((vader_struct_vader_types_DistinctType_t*) t0)->f_backing, l1);
    } else if ((l0.tag == 1262u || l0.tag == 1275u || l0.tag == 1277u || l0.tag == 1280u || l0.tag == 1282u)) {
        l2 = true;
    } else if (l0.tag == 1270u) {
        t0 = l0.payload.obj;
        vader_types_leaked_infer_var(t0);
        vader_unreachable("a no-return call returned");
    } else if ((l0.tag == 1263u || l0.tag == 1265u || l0.tag == 1266u || l0.tag == 1273u || l0.tag == 1274u || l0.tag == 1276u || l0.tag == 1278u)) {
        l2 = vader_typecheck_equals_type(l0, l1);
    } else {
        if (!((l0.tag == 1267u || l0.tag == 1268u || l0.tag == 1269u || l0.tag == 1271u || l0.tag == 1279u))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l2 = false;
    }
    { bool __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

bool vader_effects_may_be_written(void* l0, vader_box_t l1, void* l2, void* l3) {
    void* l4 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    bool l5, l9;
    vader_string_t l6 = 0;
    int64_t l10, l11;
    bool t0;
    void* t1 = NULL;
    vader_box_t t2 = vader_box_null(), t3 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l1, &t2, &t3 };
    void** gc_raw_roots[7] = { &l0, &l2, &l3, &l4, &l7, &l8, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l6 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = std_collections_MutableSet_std_core_Contains_contains__string(l0, 1407u);
    if (t0) {
        { vader_gc_top = gc_frame.prev; return true; }
    }
    vader_struct___lambda_env_vader_effects_33_t* _a0_obj = (vader_struct___lambda_env_vader_effects_33_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_effects_33_t));
    vader_obj_header_init(_a0_obj, 325u);
    _a0_obj->f_cap_0 = l0;
    _a0_obj->f_cap_1 = l2;
    _a0_obj->f_cap_2 = l3;
    t1 = (void*) _a0_obj;
    vader_fn_t* _a1_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
    vader_obj_header_init(_a1_closure, 282u);
    _a1_closure->code = (void*) &vader_fn_lift___lambda_vader_effects_32;
    _a1_closure->env = t1;
    l4 = (void*) _a1_closure;
    if (l1.tag == 1276u) {
        t1 = l1.payload.obj;
        l6 = vader_effects_struct_key(t1);
        t0 = std_collections_MutableSet_std_core_Contains_contains__string(l0, l6);
        if (t0) {
            l5 = true;
        } else {
            l7 = l1.payload.obj;
            l5 = vader_effects_fields_may_be_written(l0, l7, l2, l3);
        }
        { bool __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 1263u) {
        t0 = std_collections_MutableSet_std_core_Contains_contains__string(l0, 1417u);
        if (t0) {
            l5 = true;
        } else {
            t1 = l1.payload.obj;
            vader_fn_t* _a2_fnobj = (vader_fn_t*) l4;
            t2 = ((vader_fn_erased_sig_1_t) _a2_fnobj->code)(_a2_fnobj->env, ((vader_struct_vader_types_ArrayType_t*) t1)->f_element);
            l5 = t2.payload.b;
        }
    } else if (l1.tag == 1278u) {
        t0 = std_collections_MutableSet_std_core_Contains_contains__string(l0, 2547u);
        if (t0) {
            l5 = true;
        } else {
            t1 = l1.payload.obj;
            l7 = ((vader_struct_vader_types_TupleType_t*) t1)->f_elements;
            l8 = l4;
            l9 = false;
            l10 = ((vader_array_t*) l7)->length;
            l11 = INT64_C(0);
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
                    l11 = (l11 + INT64_C(1));
                }
                l9 = false;
            } end_80: ;
            l5 = l9;
        }
    } else if (l1.tag == 1281u) {
        t1 = l1.payload.obj;
        l7 = ((vader_struct_vader_types_UnionType_t*) t1)->f_variants;
        l8 = l4;
        l9 = false;
        l10 = ((vader_array_t*) l7)->length;
        l11 = INT64_C(0);
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
                l11 = (l11 + INT64_C(1));
            }
            l9 = false;
        } end_126: ;
        l5 = l9;
    } else if (l1.tag == 1264u) {
        t1 = l1.payload.obj;
        vader_fn_t* _a7_fnobj = (vader_fn_t*) l4;
        t2 = ((vader_fn_erased_sig_1_t) _a7_fnobj->code)(_a7_fnobj->env, ((vader_struct_vader_types_DistinctType_t*) t1)->f_backing);
        l5 = t2.payload.b;
    } else if ((l1.tag == 1262u || l1.tag == 0u || l1.tag == 1275u || l1.tag == 1277u || l1.tag == 1280u || l1.tag == 1282u)) {
        l5 = true;
    } else if (l1.tag == 1270u) {
        t1 = l1.payload.obj;
        vader_types_leaked_infer_var(t1);
        vader_unreachable("a no-return call returned");
    } else {
        if (!((l1.tag == 1265u || l1.tag == 1266u || l1.tag == 1267u || l1.tag == 1268u || l1.tag == 1269u || l1.tag == 1271u || l1.tag == 1273u || l1.tag == 1274u || l1.tag == 1279u))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l5 = false;
    }
    { bool __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
}

bool vader_effects_may_hold_view(vader_box_t l0, void* l1) {
    bool l2, l7;
    vader_box_t l3 = vader_box_null(), l4 = vader_box_null();
    void* l5 = NULL;
    void* l6 = NULL;
    int64_t l8, l9;
    void* t0 = NULL;
    bool t1;
    vader_box_t* gc_roots[3] = { &l0, &l3, &l4 };
    void** gc_raw_roots[4] = { &l1, &l5, &l6, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 1263u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_types_ArrayType_t*) t0)->f_element;
        l4 = ((vader_struct_vader_types_ArrayType_t*) l1)->f_element;
        l2 = vader_effects_may_be_element(l3, l4);
        { bool __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1281u) {
        t0 = l0.payload.obj;
        l5 = ((vader_struct_vader_types_UnionType_t*) t0)->f_variants;
        vader_struct___lambda_env_vader_effects_31_t* _a0_obj = (vader_struct___lambda_env_vader_effects_31_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_effects_31_t));
        vader_obj_header_init(_a0_obj, 324u);
        _a0_obj->f_cap_0 = l1;
        l6 = (void*) _a0_obj;
        l7 = false;
        l8 = ((vader_array_t*) l5)->length;
        l9 = INT64_C(0);
        {
            while ((l9 < l8)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                l3 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l9);
                t1 = __lambda_vader_effects_30(l6, l3);
                if (t1) {
                    l7 = true;
                    goto end_32;
                }
                l9 = (l9 + INT64_C(1));
            }
            l7 = false;
        } end_32: ;
        l2 = l7;
    } else if (l0.tag == 1264u) {
        t0 = l0.payload.obj;
        l2 = vader_effects_may_hold_view(((vader_struct_vader_types_DistinctType_t*) t0)->f_backing, l1);
    } else if ((l0.tag == 1262u || l0.tag == 0u || l0.tag == 1275u || l0.tag == 1277u || l0.tag == 1280u || l0.tag == 1282u)) {
        l2 = true;
    } else if (l0.tag == 1270u) {
        t0 = l0.payload.obj;
        vader_types_leaked_infer_var(t0);
        vader_unreachable("a no-return call returned");
    } else {
        if (!((l0.tag == 1265u || l0.tag == 1266u || l0.tag == 1267u || l0.tag == 1268u || l0.tag == 1269u || l0.tag == 1271u || l0.tag == 1273u || l0.tag == 1274u || l0.tag == 1276u || l0.tag == 1278u || l0.tag == 1279u))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l2 = false;
    }
    { bool __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
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
    int64_t l7, l8, l13, l14;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    bool t2;
    vader_box_t* gc_roots[3] = { &l4, &l12, &l18 };
    void** gc_raw_roots[10] = { &l0, &l5, &l6, &l9, &l10, &l11, &l15, &l16, &l17, &t0 };
    vader_string_t* gc_atom_roots[4] = { &l1, &l2, &l3, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 10u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = concat_3(l1, 343u, l2);
    l4 = std_collections_MutableMap_std_core_Index_at__string__Any(((vader_struct_vader_effects_CalleeIndex_t*) l0)->f_members, l3);
    if (!(l4.tag == 0u)) {
        t0 = l4.payload.obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a0_arr = vader_array_new(238u, 0u, 13u, 1666u);
    l5 = (void*) _a0_arr;
    l6 = ((vader_struct_vader_typecheck_ImplRegistry_t*) ((vader_struct_vader_effects_CalleeIndex_t*) l0)->f_impls)->f_all;
    l7 = ((vader_array_t*) l6)->length;
    l8 = INT64_C(0);
    while ((l8 < l7)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l9 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l8);
        t1 = ((vader_struct_vader_typecheck_ImplEntry_t*) l9)->f_trait_key;
        if (t1 != l1) {
            l8 = (l8 + INT64_C(1));
            continue;
        }
        l10 = ((vader_struct_toolchain_ast_ImplDecl_t*) ((vader_struct_vader_typecheck_ImplEntry_t*) l9)->f_decl)->f_members;
        vader_struct___lambda_env_vader_effects_37_t* _a2_obj = (vader_struct___lambda_env_vader_effects_37_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_effects_37_t));
        vader_obj_header_init(_a2_obj, 327u);
        _a2_obj->f_cap_0 = l2;
        l11 = (void*) _a2_obj;
        l12 = vader_box_obj(0u, NULL);
        l13 = ((vader_array_t*) l10)->length;
        l14 = INT64_C(0);
        {
            while ((l14 < l13)) {
                vader_array_t* _a3_slotarr = ((vader_array_t*) l10);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                l15 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l14);
                t2 = __lambda_vader_effects_36(l11, l15);
                if (t2) {
                    l12 = vader_ref_box(l15);
                    goto end_58;
                }
                l14 = (l14 + INT64_C(1));
            }
            l12 = vader_box_obj(0u, NULL);
        } end_58: ;
        l4 = l12;
        if (l4.tag == 0u) {
            vader_struct_vader_effects_AnyCallee_t* _a4_obj = (vader_struct_vader_effects_AnyCallee_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_AnyCallee_t));
            vader_obj_header_init(_a4_obj, 912u);
            l16 = (void*) _a4_obj;
            vader_array_push((vader_array_t*) l5, vader_ref_box(l16));
        } else {
            l17 = l4.payload.obj;
            l18 = vader_effects_target_of_decl(l0, l17);
            vader_array_push((vader_array_t*) l5, l18);
        }
        l8 = (l8 + INT64_C(1));
    }
    std_collections_MutableMap_std_core_IndexSet_set_at__string__Any(((vader_struct_vader_effects_CalleeIndex_t*) l0)->f_members, l3, vader_ref_box(l5));
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
    vader_array_t* _a0_arr = vader_array_new(95u, 5u, 13u, 932u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 4u] = l5;
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 3u] = l4;
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 2u] = l3;
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 1u] = l2;
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = l1;
    t0 = (void*) _a0_arr;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_effects_modified_how(void* l0) {
    void* l1 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    vader_box_t l2 = vader_box_null(), l8 = vader_box_null();
    int64_t l5, l6;
    vader_string_t l7 = 0;
    vader_string_t l9 = 0;
    void* t0 = NULL;
    bool t1;
    vader_string_t t2 = 0;
    vader_box_t t3 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l2, &l8, &t3 };
    void** gc_raw_roots[5] = { &l0, &l1, &l3, &l4, &t0 };
    vader_string_t* gc_atom_roots[3] = { &l7, &l9, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_effects_FrozenSite_t*) l0)->f_chain;
    if (l2.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return 1325u; }
    }
    l1 = l2.payload.obj;
    l3 = ((vader_struct_vader_effects_FaultChain_t*) l1)->f_via;
    vader_array_t* _a0_arr = vader_array_new(14u, 0u, 0u, 288u);
    l4 = (void*) _a0_arr;
    l5 = ((vader_array_t*) l3)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l4, (int64_t) l5);
    l4 = (void*) _a1_arr;
    l5 = ((vader_array_t*) l3)->length;
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        t0 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l6);
        l7 = __lambda_vader_effects_11(t0);
        vader_array_push((vader_array_t*) l4, vader_box_string(288u, l7));
        l6 = (l6 + INT64_C(1));
    }
    l3 = l4;
    l2 = ((vader_struct_vader_effects_FaultChain_t*) l1)->f_write;
    if (!(l2.tag == 0u)) {
        t0 = l2.payload.obj;
        l8 = ((vader_struct_vader_effects_FaultWrite_t*) t0)->f_by;
        if (!(l8.tag == 0u)) {
            l7 = l8.payload.s;
            vader_array_push((vader_array_t*) l3, vader_box_string(288u, l7));
        }
    }
    t1 = std_iter_is_empty__string(l3);
    if (t1) {
        t2 = vader_effects_write_phrase(l2);
        { vader_string_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a3_slotarr = ((vader_array_t*) l3);
    VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a3_slotarr, INT32_C(0))
    t3 = vader_array_box_slots(_a3_slotarr->buf)[_a3_slotarr->offset + (size_t) INT32_C(0)];
    l7 = t3.payload.s;
    l9 = vader_effects_through(l3);
    l7 = concat_3(l7, 135u, l9);
    if (!(l2.tag == 0u)) {
        t0 = l2.payload.obj;
        l9 = vader_effects_write_phrase(vader_ref_box(t0));
        t2 = concat_4(l7, 33u, l9, 277u);
        { vader_string_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_string_t __vret = l7; vader_gc_top = gc_frame.prev; return __vret; }
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

static void* vader_effects_named_use(void* l0) {
    void* l1;
    void* l4;
    void* l5;
    void* l7;
    int64_t l2, l3, l6;
    bool t0;
    void* t1;
    l1 = ((vader_struct_vader_effects_RootCase_t*) l0)->f_held;
    l2 = ((vader_array_t*) l1)->length;
    l3 = INT64_C(0);
    while ((l3 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l4 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
        l5 = ((vader_struct_vader_effects_RootCase_t*) l0)->f_body;
        l6 = ((vader_struct_vader_effects_Root_t*) l4)->f_param;
        l7 = vader_effects_root_record(l5, l6);
        t0 = vader_effects_is_view(l7);
        if (t0) {
            return l7;
        }
        l3 = (l3 + INT64_C(1));
    }
    l1 = ((vader_struct_vader_effects_RootCase_t*) l0)->f_body;
    vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_effects_RootCase_t*) l0)->f_held);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, INT32_C(0))
    t1 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) INT32_C(0));
    l2 = ((vader_struct_vader_effects_Root_t*) t1)->f_param;
    t1 = vader_effects_root_record(l1, l2);
    return t1;
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
    l3 = std_collections_MutableMap_std_core_Index_at__string__Any(((vader_struct_vader_resolver_LoadedProject_t*) ((vader_struct_vader_effects_CalleeIndex_t*) ((vader_struct_vader_effects_WalkCtx_t*) l0)->f_index)->f_project)->f_modules, l2);
    if (l3.tag == 0u) {
        return vader_box_obj(0u, NULL);
    }
    l4 = l3.payload.obj;
    l4 = ((vader_struct_vader_resolver_CollectedModule_t*) ((vader_struct_vader_resolver_LoadedModule_t*) l4)->f_collected)->f_symbols;
    l2 = ((vader_struct_toolchain_ast_FieldExpr_t*) l1)->f_field;
    t0 = std_collections_MutableMap_std_core_Index_at__string__Any(l4, l2);
    return t0;
}

static vader_box_t vader_effects_narrowed(void* l0, vader_box_t l1, vader_box_t l2, vader_box_t l3) {
    void* l4 = NULL;
    vader_box_t l5 = vader_box_null();
    bool t0;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[5] = { &l1, &l2, &l3, &l5, &t1 };
    void** gc_raw_roots[2] = { &l0, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 5u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l5 = ((vader_struct_vader_effects_CalleeIndex_t*) ((vader_struct_vader_effects_WalkCtx_t*) l0)->f_index)->f_view;
    if (l5.tag == 0u) {
        { vader_box_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = l5.payload.obj;
    t0 = vader_effects_may_hold_view(l2, l4);
    if (t0) {
        t0 = vader_effects_may_hold_view(l3, l4);
        if (!(t0)) {
            t1 = vader_effects_step_slot(l0, l1, 454u);
            { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
        }
        { vader_box_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_box_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_effects_new_skeleton(int64_t l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[4] = { &l1, &l2, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(88u, 0u, 13u, 922u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(99u, 0u, 13u, 939u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(94u, 0u, 13u, 931u);
    l3 = (void*) _a2_arr;
    vader_struct_vader_effects_Skeleton_t* _a3_obj = (vader_struct_vader_effects_Skeleton_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_Skeleton_t));
    vader_obj_header_init(_a3_obj, 940u);
    _a3_obj->f_params = l0;
    _a3_obj->f_slots = l0;
    _a3_obj->f_flows = l1;
    _a3_obj->f_sites = l2;
    _a3_obj->f_marks = l3;
    _a3_obj->f_extra = INT64_C(0);
    _a3_obj->f_arguments = INT64_C(0);
    _a3_obj->f_seeds = vader_box_obj(0u, NULL);
    t0 = (void*) _a3_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static int64_t vader_effects_next_root(void* l0) {
    int64_t l1, l2;
    int64_t t0;
    l1 = ((vader_struct_vader_effects_Skeleton_t*) l0)->f_params;
    l2 = ((vader_struct_vader_effects_Skeleton_t*) l0)->f_extra;
    l1 = vader_chk_add(i64, l1, l2);
    t0 = ((vader_struct_vader_effects_Skeleton_t*) l0)->f_extra;
    l2 = vader_chk_add(i64, t0, INT64_C(1));
    ((vader_struct_vader_effects_Skeleton_t*) l0)->f_extra = l2;
    return l1;
}

void* vader_effects_node_ctx(void* l0, void* l1, void* l2, int32_t l3) {
    void* l4 = NULL;
    void* l5 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l4, &l5, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 6u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l4 = ((vader_struct_vader_effects_CalleeIndex_t*) l1)->f_paths;
    l5 = ((vader_struct_vader_effects_CalleeIndex_t*) l1)->f_any;
    vader_struct_vader_effects_EvalCtx_t* _a0_obj = (vader_struct_vader_effects_EvalCtx_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_EvalCtx_t));
    vader_obj_header_init(_a0_obj, 918u);
    _a0_obj->f_facts = l0;
    _a0_obj->f_paths = l4;
    _a0_obj->f_components = l2;
    _a0_obj->f_node = l3;
    _a0_obj->f_any = l5;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_effects_none(void) {
    void* l0 = NULL;
    void* l1 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[3] = { &l0, &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(85u, 0u, 13u, 911u);
    l0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(16u, 0u, 8u, 292u);
    l1 = (void*) _a1_arr;
    vader_struct_vader_effects_ParamEffects_t* _a2_obj = (vader_struct_vader_effects_ParamEffects_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_ParamEffects_t));
    vader_obj_header_init(_a2_obj, 932u);
    _a2_obj->f_accesses = l0;
    _a2_obj->f_origins = l1;
    _a2_obj->f_keys = vader_box_obj(0u, NULL);
    t0 = (void*) _a2_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_effects_note_frozen_body(void* l0, int32_t l1, vader_box_t l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[5] = { &l0, &l3, &l4, &l5, &l6 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (!(((vader_struct_vader_effects_Skeleton_t*) ((vader_struct_vader_effects_WalkCtx_t*) l0)->f_s)->f_seeds.tag == 0u)) {
        l3 = ((vader_struct_vader_effects_WalkCtx_t*) l0)->f_s;
        l4 = ((vader_struct_vader_effects_WalkCtx_t*) l0)->f_roots;
        l5 = ((vader_struct_vader_effects_WalkCtx_t*) l0)->f_typed;
        l6 = ((vader_struct_vader_effects_WalkCtx_t*) l0)->f_seen_names;
        vader_struct_vader_effects_FrozenBody_t* _a0_obj = (vader_struct_vader_effects_FrozenBody_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_FrozenBody_t));
        vader_obj_header_init(_a0_obj, 923u);
        _a0_obj->f_skeleton = l3;
        _a0_obj->f_roots = l4;
        _a0_obj->f_typed = l5;
        _a0_obj->f_node = l1;
        _a0_obj->f_initialises = l2;
        _a0_obj->f_seen_names = l6;
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
    void* l11 = NULL;
    int64_t l5, l6;
    vader_box_t l9 = vader_box_null(), l10 = vader_box_null(), l12 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l9, &l10, &l12 };
    void** gc_raw_roots[8] = { &l0, &l1, &l2, &l3, &l4, &l7, &l8, &l11 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 8u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_effects_CalleeIndex_t*) l0)->f_constants;
    l4 = ((vader_struct_vader_effects_CalleeIndex_t*) l0)->f_defaults;
    l5 = ((vader_array_t*) l3)->length;
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l6)
        l7 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l6);
        l8 = vader_effects_initialiser_ctx(l0, l1, l2, l7);
        l9 = ((vader_struct_vader_effects_Initialiser_t*) l7)->f_value;
        l10 = vader_effects_value(l8, l9);
        l11 = VADER_UNION_FIELD(void*, vader_struct_toolchain_ast_ArrayTypeExpr_t, f_span, ((vader_struct_vader_effects_Initialiser_t*) l7)->f_value.payload.obj);
        vader_effects_escape(l8, l10, (uint8_t) 3, l11);
        l12 = ((vader_struct_vader_effects_Initialiser_t*) l7)->f_initialises;
        vader_effects_note_frozen_body(l8, INT32_C(-1), l12);
        l6 = (l6 + INT64_C(1));
    }
    l5 = ((vader_array_t*) l4)->length;
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l6)
        l3 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l6);
        l7 = vader_effects_initialiser_ctx(l0, l1, l2, l3);
        l9 = ((vader_struct_vader_effects_Initialiser_t*) l3)->f_value;
        l10 = vader_effects_value(l7, l9);
        l8 = VADER_UNION_FIELD(void*, vader_struct_toolchain_ast_ArrayTypeExpr_t, f_span, ((vader_struct_vader_effects_Initialiser_t*) l3)->f_value.payload.obj);
        vader_effects_escape(l7, l10, (uint8_t) 3, l8);
        l12 = ((vader_struct_vader_effects_Initialiser_t*) l3)->f_initialises;
        vader_effects_note_frozen_body(l7, INT32_C(-1), l12);
        l6 = (l6 + INT64_C(1));
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
    l4 = std_collections_MutableMap_std_core_Index_at__i32__Any(((vader_struct_vader_effects_FrozenSites_t*) l0)->f_kept_by_constants, l3);
    if (l4.tag == 0u) {
        vader_array_t* _a0_arr = vader_array_new(86u, 0u, 13u, 916u);
        l6 = (void*) _a0_arr;
    } else {
        l6 = l4.payload.obj;
    }
    vader_array_push((vader_array_t*) l6, vader_ref_box(l5));
    std_collections_MutableMap_std_core_IndexSet_set_at__i32__Any(((vader_struct_vader_effects_FrozenSites_t*) l0)->f_kept_by_constants, l3, vader_ref_box(l6));
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_effects_note_known_writes(void* l0, void* l1, int64_t l2, vader_box_t l3) {
    void* l4 = NULL;
    void* l9 = NULL;
    void* l13 = NULL;
    int64_t l5, l6, l8, l11, l12, l14;
    vader_box_t l7 = vader_box_null(), l15 = vader_box_null();
    bool l10;
    void* t0 = NULL;
    bool t1;
    vader_box_t* gc_roots[3] = { &l3, &l7, &l15 };
    void** gc_raw_roots[6] = { &l0, &l1, &l4, &l9, &l13, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 6u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l4 = l1;
    l5 = ((vader_array_t*) l4)->length;
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l7 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l6);
        if (l7.tag == 929u) {
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
                l12 = INT64_C(0);
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
                        l12 = (l12 + INT64_C(1));
                    }
                    l10 = false;
                } end_40: ;
                if (l10) {
                    l13 = ((vader_struct_vader_typecheck_TypedProgram_t*) ((vader_struct_vader_effects_WalkCtx_t*) l0)->f_typed)->f_expr_types;
                    l14 = VADER_UNION_FIELD(int64_t, vader_struct_toolchain_ast_ArrayTypeExpr_t, f_id, l3.payload.obj);
                    l15 = std_collections_MutableMap_std_core_Index_at__i64__Any(l13, l14);
                    vader_effects_note_written(l0, l15);
                }
            }
        }
        l6 = (l6 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_effects_note_place(void* l0, vader_box_t l1) {
    vader_box_t l2 = vader_box_null();
    void* l3 = NULL;
    int64_t l4;
    void* t0 = NULL;
    vader_box_t* gc_roots[2] = { &l1, &l2 };
    void** gc_raw_roots[3] = { &l0, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l1.tag == 562u) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_toolchain_ast_FieldExpr_t*) t0)->f_target;
        vader_effects_note_place(l0, l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 577u) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_toolchain_ast_IndexExpr_t*) t0)->f_target;
        vader_effects_note_place(l0, l2);
    } else if (l1.tag == 569u) {
        l3 = ((vader_struct_vader_effects_WalkCtx_t*) l0)->f_place_bases;
        t0 = l1.payload.obj;
        l4 = ((vader_struct_toolchain_ast_IdentExpr_t*) t0)->f_id;
        std_collections_add__i64(l3, l4);
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_effects_note_widened(void* l0, vader_box_t l1, void* l2, int64_t l3, vader_box_t l4) {
    void* l5 = NULL;
    void* l8 = NULL;
    int64_t l6;
    vader_box_t l7 = vader_box_null();
    vader_string_t l9 = 0;
    int32_t l10;
    vader_box_t* gc_roots[3] = { &l1, &l4, &l7 };
    void** gc_raw_roots[4] = { &l0, &l2, &l5, &l8 };
    vader_string_t* gc_atom_roots[1] = { &l9 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l5 = ((vader_struct_vader_typecheck_TypedProgram_t*) ((vader_struct_vader_effects_WalkCtx_t*) l0)->f_typed)->f_widened_arguments;
    l6 = VADER_UNION_FIELD(int64_t, vader_struct_toolchain_ast_ArrayTypeExpr_t, f_id, l4.payload.obj);
    l7 = std_collections_MutableMap_std_core_Index_at__i64__Any(l5, l6);
    if (l7.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l5 = l7.payload.obj;
    l6 = VADER_UNION_FIELD(int64_t, vader_struct_toolchain_ast_ArrayTypeExpr_t, f_id, l4.payload.obj);
    l8 = VADER_UNION_FIELD(void*, vader_struct_toolchain_ast_ArrayTypeExpr_t, f_span, l4.payload.obj);
    l9 = ((vader_struct_vader_resolver_ResolvedModule_t*) ((vader_struct_vader_typecheck_TypedProgram_t*) ((vader_struct_vader_effects_WalkCtx_t*) l0)->f_typed)->f_resolved)->f_display_path;
    l10 = ((vader_struct_vader_typecheck_WidenedArgument_t*) l5)->f_depth;
    vader_struct_vader_effects_WideningSite_t* _a0_obj = (vader_struct_vader_effects_WideningSite_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_WideningSite_t));
    vader_obj_header_init(_a0_obj, 944u);
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
    vader_obj_header_init(_a1_obj, 935u);
    _a1_obj->f_site = l5;
    _a1_obj->f_targets = l2;
    l5 = (void*) _a1_obj;
    vader_array_push((vader_array_t*) l8, vader_ref_box(l5));
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_effects_note_write(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    int64_t l3;
    vader_box_t l4 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l1, &l4 };
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_typecheck_TypedProgram_t*) ((vader_struct_vader_effects_WalkCtx_t*) l0)->f_typed)->f_expr_types;
    l3 = VADER_UNION_FIELD(int64_t, vader_struct_toolchain_ast_ArrayTypeExpr_t, f_id, l1.payload.obj);
    l4 = std_collections_MutableMap_std_core_Index_at__i64__Any(l2, l3);
    vader_effects_note_written(l0, l4);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_effects_note_written(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    int64_t l3, l4;
    vader_string_t l5 = 0;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l1, &t0 };
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_string_t* gc_atom_roots[1] = { &l5 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_effects_written_keys(l1);
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l4];
        l5 = t0.payload.s;
        std_collections_add__string(((vader_struct_vader_effects_FrozenSites_t*) ((vader_struct_vader_effects_WalkCtx_t*) l0)->f_frozen)->f_written, l5);
        l4 = (l4 + INT64_C(1));
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

static vader_box_t vader_effects_one_of(void* l0, void* l1) {
    int64_t l2, l6, l7;
    vader_box_t l3 = vader_box_null();
    void* l4 = NULL;
    bool l5;
    bool t0;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l3, &t1 };
    void** gc_raw_roots[3] = { &l0, &l1, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = vader_effects_union_of(l0, l1);
    if (l3.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l2 = ((int64_t) l3.payload.i);
    t0 = std_collections_MutableSet_std_core_Contains_contains__i64(((vader_struct_vader_effects_WalkCtx_t*) l0)->f_pure, l2);
    if (t0) {
        l4 = l1;
        l5 = false;
        l6 = ((vader_array_t*) l4)->length;
        l7 = INT64_C(0);
        {
            for (;;) {
                if ((l7 < l6)) {
                    vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
                    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
                    t1 = vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l7];
                    t0 = __lambda_vader_effects_20(t1);
                    if (t0) {
                        l7 = (l7 + INT64_C(1));
                        continue;
                    }
                    l5 = false;
                    goto end_24;
                }
                break;
            }
            l5 = true;
        } end_24: ;
        if (!(l5)) {
            l6 = vader_effects_fresh_slot(((vader_struct_vader_effects_WalkCtx_t*) l0)->f_s);
            vader_effects_add_flow(((vader_struct_vader_effects_WalkCtx_t*) l0)->f_s, l6, l2, INT32_C(0));
            { vader_box_t __vret = vader_box_i64(292u, l6); vader_gc_top = gc_frame.prev; return __vret; }
        }
        { vader_box_t __vret = vader_box_i64(292u, l2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_box_t __vret = vader_box_i64(292u, l2); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_effects_origin_call(int64_t l0) {
    int64_t l1, l2, l3;
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (!((l0 < INT64_C(0)))) {
        l1 = (l0 >> INT64_C(32));
        l2 = ((l0 >> INT64_C(16)) & INT64_C(65535));
        l3 = (l0 & INT64_C(65535));
        vader_struct___Tuple_i64_i64_i64_2cc25dbf_t* _a0_obj = (vader_struct___Tuple_i64_i64_i64_2cc25dbf_t*) vader_gc_alloc(sizeof(vader_struct___Tuple_i64_i64_i64_2cc25dbf_t));
        vader_obj_header_init(_a0_obj, 306u);
        _a0_obj->f__0 = l1;
        _a0_obj->f__1 = l2;
        _a0_obj->f__2 = l3;
        t0 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static vader_box_t vader_effects_origin_mark(int64_t l0) {
    int64_t t0;
    if (!((l0 >= INT64_C(-1)))) {
        t0 = vader_chk_sub(i64, INT64_C(-2), l0);
        return vader_box_i64(292u, t0);
    }
    return vader_box_obj(0u, NULL);
}

static vader_box_t vader_effects_outcome(void* l0, void* l1, void* l2, bool l3) {
    void* l4 = NULL;
    int32_t l5;
    bool l6;
    vader_box_t t0 = vader_box_null();
    bool t1;
    uint8_t t2;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l3) {
        t0 = vader_effects_view_outcome(l1);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(((vader_struct_vader_effects_FrozenRoot_t*) l2)->f_binding.tag == 0u)) {
        l4 = ((vader_struct_vader_effects_FrozenBody_t*) ((vader_struct_vader_effects_RootCase_t*) l1)->f_body)->f_seen_names;
        l5 = ((int32_t) ((vader_struct_vader_effects_FrozenRoot_t*) l2)->f_binding.payload.i);
        t1 = std_collections_MutableSet_std_core_Contains_contains__i32(l4, l5);
        l6 = !(t1);
        t2 = vader_effects_binding_outcome(l0, l1, l6);
        { vader_box_t __vret = vader_box_i32(293u, (int32_t)(uint32_t) t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_effects_use_outcome(l0, l1);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static int64_t vader_effects_pair_key(int32_t l0, int32_t l1) {
    int64_t l2, l3;
    l2 = (((int64_t) (int32_t) l0) << INT64_C(32));
    l3 = ((int64_t) (int32_t) l1);
    return (l2 | l3);
}

static vader_box_t vader_effects_parameter_name(vader_box_t l0, int64_t l1) {
    int64_t l2;
    void* t0;
    vader_string_t t1;
    if (l0.tag == 1209u) {
        t0 = l0.payload.obj;
        l2 = ((vader_array_t*) ((vader_struct_toolchain_ast_FnDecl_t*) ((vader_struct_vader_typecheck_DirectFn_t*) t0)->f_decl)->f_params)->length;
        if ((l1 < l2)) {
            t0 = l0.payload.obj;
            vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_FnDecl_t*) ((vader_struct_vader_typecheck_DirectFn_t*) t0)->f_decl)->f_params);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
            t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l1);
            t1 = ((vader_struct_toolchain_ast_FnParam_t*) t0)->f_name;
            return vader_box_string(288u, t1);
        }
        return vader_box_obj(0u, NULL);
    }
    return vader_box_obj(0u, NULL);
}

static bool vader_effects_passes_receiver(void* l0, void* l1, void* l2, vader_box_t l3) {
    bool l4;
    void* l5;
    void* l6;
    int64_t l7;
    void* t0;
    int64_t t1;
    bool t2;
    if (l3.tag == 1209u) {
        t0 = l3.payload.obj;
        l5 = ((vader_struct_vader_typecheck_DirectFn_t*) t0)->f_decl;
        l6 = ((vader_struct_vader_effects_WalkCtx_t*) l0)->f_typed;
        t1 = vader_typecheck_receiver_offset(l1, l5, l6);
        l4 = t1 == INT64_C(1);
        return l4;
    }
    if ((l3.tag == 1196u || l3.tag == 1250u || l3.tag == 1258u)) {
        l5 = ((vader_struct_vader_typecheck_TypedProgram_t*) ((vader_struct_vader_effects_WalkCtx_t*) l0)->f_typed)->f_static_members;
        l7 = ((vader_struct_toolchain_ast_FieldExpr_t*) l2)->f_id;
        t2 = std_collections_MutableMap_std_core_Contains_contains__i64__Any(l5, l7);
        l4 = !(t2);
    } else {
        if (!((l3.tag == 1198u || l3.tag == 1211u || l3.tag == 1214u || l3.tag == 1219u))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l4 = false;
    }
    return l4;
}

static vader_box_t vader_effects_path_slot(void* l0, vader_box_t l1, int32_t l2) {
    int64_t l3, l5;
    vader_box_t l4 = vader_box_null();
    bool t0;
    vader_box_t* gc_roots[2] = { &l1, &l4 };
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l4 = l1;
    if (l4.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l3 = ((int64_t) l4.payload.i);
    l5 = vader_effects_fresh_slot(((vader_struct_vader_effects_WalkCtx_t*) l0)->f_s);
    vader_effects_add_flow(((vader_struct_vader_effects_WalkCtx_t*) l0)->f_s, l5, l3, l2);
    t0 = std_collections_MutableSet_std_core_Contains_contains__i64(((vader_struct_vader_effects_WalkCtx_t*) l0)->f_pure, l3);
    if (t0) {
        std_collections_add__i64(((vader_struct_vader_effects_WalkCtx_t*) l0)->f_pure, l5);
        { vader_box_t __vret = vader_box_i64(292u, l5); vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_box_t __vret = vader_box_i64(292u, l5); vader_gc_top = gc_frame.prev; return __vret; }
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

static vader_string_t vader_effects_place_label(void* l0, vader_string_t l1, int32_t l2) {
    vader_string_t l3 = 0;
    vader_string_t t0 = 0;
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[3] = { &l1, &l3, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = vader_effects_display_path(l0, l2);
    t0 = concat_2(l1, l3);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static int64_t vader_effects_pure_source(void* l0, int64_t l1) {
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    std_collections_add__i64(((vader_struct_vader_effects_WalkCtx_t*) l0)->f_pure, l1);
    { int64_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
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
    vader_array_t* _a0_arr = vader_array_new(95u, 2u, 13u, 932u);
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

bool vader_effects_reaches(void* l0, void* l1) {
    int32_t l2;
    bool t0;
    l2 = ((vader_struct_vader_effects_Root_t*) l1)->f_path;
    t0 = vader_effects_first_step_is(l0, l2, 454u);
    return !(t0);
}

static bool vader_effects_reaches_view(void* l0, void* l1) {
    int32_t l2;
    bool t0;
    l2 = ((vader_struct_vader_effects_Access_t*) l1)->f_path;
    t0 = vader_effects_first_step_is(l0, l2, 454u);
    return !(t0);
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
    } else {
        l3 = l2 == INT32_C(6);
    }
    if (l3) {
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
        if (l5) {
            l5 = true;
        } else {
            l5 = l2 == INT32_C(7);
        }
        if (l5) {
            l5 = true;
        } else {
            l5 = l2 == INT32_C(8);
        }
        if (!(l5)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l3 = false;
    }
    { bool __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_effects_recursive(void* l0, vader_box_t l1) {
    void* l2;
    int32_t l3, l4;
    int64_t t0;
    void* t1;
    if (l1.tag == 914u) {
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
    int64_t l4;
    int32_t l5;
    vader_box_t l7 = vader_box_null();
    int64_t t0;
    vader_box_t* gc_roots[1] = { &l7 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &l6 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (!(((vader_struct_toolchain_ast_FnDecl_t*) l1)->f_body.tag == 0u)) {
        l3 = ((vader_struct_vader_effects_CalleeIndex_t*) l0)->f_nodes;
        l4 = ((vader_struct_toolchain_ast_FnDecl_t*) l1)->f_id;
        t0 = ((vader_array_t*) ((vader_struct_vader_effects_CalleeIndex_t*) l0)->f_functions)->length;
        l5 = ((int32_t) (int64_t) t0);
        std_collections_MutableMap_std_core_IndexSet_set_at__i64__i32(l3, l4, l5);
        l3 = ((vader_struct_vader_effects_CalleeIndex_t*) l0)->f_functions;
        vader_struct_vader_effects_Function_t* _a0_obj = (vader_struct_vader_effects_Function_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_Function_t));
        vader_obj_header_init(_a0_obj, 927u);
        _a0_obj->f_decl = l1;
        _a0_obj->f_typed = l2;
        l6 = (void*) _a0_obj;
        vader_array_push((vader_array_t*) l3, vader_ref_box(l6));
        { vader_gc_top = gc_frame.prev; return; }
    }
    l3 = ((vader_struct_vader_effects_CalleeIndex_t*) l0)->f_bodyless;
    l4 = ((vader_struct_toolchain_ast_FnDecl_t*) l1)->f_id;
    l7 = vader_effects_bodyless_target(l0, l1, l2);
    std_collections_MutableMap_std_core_IndexSet_set_at__i64__Any(l3, l4, l7);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_effects_register_defaults(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    int64_t l4, l5;
    vader_box_t l6 = vader_box_null(), l7 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[2] = { &l6, &l7 };
    void** gc_raw_roots[7] = { &l0, &l1, &l2, &l3, &l8, &l9, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 7u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_toolchain_ast_StructDecl_t*) l1)->f_fields;
    l4 = ((vader_array_t*) l3)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
        l7 = ((vader_struct_toolchain_ast_StructField_t*) t0)->f_default_v;
        if (l7.tag == 0u) {
            l5 = (l5 + INT64_C(1));
            continue;
        }
        l6 = l7;
        l8 = ((vader_struct_vader_effects_CalleeIndex_t*) l0)->f_defaults;
        vader_struct_vader_effects_Initialiser_t* _a1_obj = (vader_struct_vader_effects_Initialiser_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_Initialiser_t));
        vader_obj_header_init(_a1_obj, 928u);
        _a1_obj->f_value = l6;
        _a1_obj->f_typed = l2;
        _a1_obj->f_initialises = vader_box_obj(0u, NULL);
        l9 = (void*) _a1_obj;
        vader_array_push((vader_array_t*) l8, vader_ref_box(l9));
        l5 = (l5 + INT64_C(1));
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
    vader_obj_header_init(_a0_obj, 911u);
    _a0_obj->f_path = l0;
    _a0_obj->f_effect = (uint8_t) 4;
    l2 = (void*) _a0_obj;
    vader_effects_insert(l1, l2, INT64_C(-1), INT64_C(-1));
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_effects_replace_body(void* l0, void* l1) {
    int64_t l2, l3;
    int32_t l4, l5;
    void* t0 = NULL;
    void** gc_raw_roots[3] = { &l0, &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = INT64_C(0);
    l3 = ((vader_array_t*) ((vader_struct_vader_effects_FrozenSites_t*) l0)->f_bodies)->length;
    while ((l2 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_effects_FrozenSites_t*) l0)->f_bodies);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
        l4 = ((vader_struct_vader_effects_FrozenBody_t*) t0)->f_node;
        l5 = ((vader_struct_vader_effects_FrozenBody_t*) l1)->f_node;
        if (l4 == l5) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_effects_FrozenSites_t*) l0)->f_bodies);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l2)
            vader_array_ref_store(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l2, l1);
            VADER_WRITE_BARRIER(_a1_slotarr->buf);
            { vader_gc_top = gc_frame.prev; return; }
        }
        l2 = (l2 + INT64_C(1));
    }
    vader_array_push((vader_array_t*) ((vader_struct_vader_effects_FrozenSites_t*) l0)->f_bodies, vader_ref_box(l1));
    { vader_gc_top = gc_frame.prev; return; }
}

static bool vader_effects_reroot(void* l0, void* l1, int64_t l2, int64_t l3, void* l4, void* l5) {
    void* l6 = NULL;
    void* l10 = NULL;
    int64_t l7, l11;
    vader_box_t l8 = vader_box_null();
    bool l9;
    void* t0 = NULL;
    bool t1;
    vader_box_t* gc_roots[1] = { &l8 };
    void** gc_raw_roots[7] = { &l0, &l1, &l4, &l5, &l6, &l10, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 7u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l6 = ((vader_struct_vader_effects_SlotRoots_t*) l0)->f_roots;
    l7 = ((vader_struct_vader_effects_Flow_t*) l1)->f_from;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l6);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l7)
    l8 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l7);
    if (l8.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return false; }
    }
    l6 = l8.payload.obj;
    l9 = false;
    l7 = l2;
    while ((l7 < l3)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l7)
        t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l7);
        l10 = vader_effects_flowed_root(t0, l1, l4, l5);
        l11 = ((vader_struct_vader_effects_Flow_t*) l1)->f_into;
        t1 = vader_effects_include_root(l0, l11, l10);
        if (t1) {
            l9 = true;
        }
        l7 = (l7 + INT64_C(1));
    }
    { bool __vret = l9; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_effects_reroot_below(void* l0, int64_t l1, int64_t l2, int64_t l3, int32_t l4, int64_t l5, void* l6, bool l7) {
    void* l8 = NULL;
    void* l12 = NULL;
    void* l15 = NULL;
    vader_box_t l9 = vader_box_null();
    bool l10;
    int64_t l11;
    int32_t l13, l14;
    bool t0;
    vader_box_t* gc_roots[1] = { &l9 };
    void** gc_raw_roots[5] = { &l0, &l6, &l8, &l12, &l15 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_effects_SlotRoots_t*) l0)->f_roots);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    l9 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l1);
    if (l9.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return false; }
    }
    l8 = l9.payload.obj;
    l10 = false;
    l11 = l2;
    while ((l11 < l3)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l11)
        l12 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l11);
        l13 = ((vader_struct_vader_effects_Root_t*) l12)->f_path;
        l14 = vader_effects_composed(l6, l13, l4, l7);
        l15 = vader_effects_at_path(l12, l14);
        t0 = vader_effects_include_root(l0, l5, l15);
        if (t0) {
            l10 = true;
        }
        l11 = (l11 + INT64_C(1));
    }
    { bool __vret = l10; vader_gc_top = gc_frame.prev; return __vret; }
}

static uint8_t vader_effects_result_effect_of(void* l0) {
    bool t0;
    t0 = toolchain_ast_decorators_have(((vader_struct_toolchain_ast_FnDecl_t*) l0)->f_decorators, 2373u);
    if (!(t0)) {
        return (uint8_t) 4;
    }
    return (uint8_t) 3;
}

static uint8_t vader_effects_return_effect(void* l0) {
    int32_t t0;
    t0 = ((vader_struct_vader_effects_WalkCtx_t*) l0)->f_lambda_depth;
    if (!((t0 > INT32_C(0)))) {
        return ((vader_struct_vader_effects_WalkCtx_t*) l0)->f_result_effect;
    }
    return (uint8_t) 3;
}

static void vader_effects_return_stmt(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null();
    uint8_t l3;
    void* l4 = NULL;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[3] = { &l0, &l1, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_toolchain_ast_ReturnStmt_t*) l1)->f_value;
    if (l2.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l2 = vader_effects_value(l0, l2);
    l3 = vader_effects_return_effect(l0);
    l4 = ((vader_struct_toolchain_ast_ReturnStmt_t*) l1)->f_span;
    vader_effects_escape(l0, l2, l3, l4);
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_effects_returned_array(vader_box_t l0) {
    void* t0;
    vader_box_t t1;
    if (!(l0.tag == 1266u)) {
        return vader_box_obj(0u, NULL);
    }
    t0 = l0.payload.obj;
    t1 = vader_types_array_backing(((vader_struct_vader_types_FnType_t*) t0)->f_return_type);
    return t1;
}

static bool vader_effects_returns_it(void* l0) {
    void* l1;
    int64_t l2, l3;
    void* t0;
    bool t1;
    l1 = ((vader_struct_vader_effects_RootCase_t*) l0)->f_marked;
    l2 = ((vader_array_t*) l1)->length;
    l3 = INT64_C(0);
    while ((l3 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
        t1 = __lambda_vader_effects_19(t0);
        if (t1) {
            return true;
        }
        l3 = (l3 + INT64_C(1));
    }
    return false;
}

static vader_box_t vader_effects_root_case(void* l0, void* l1, void* l2, void* l3) {
    vader_box_t l4 = vader_box_null();
    void* l5 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    int64_t l8, l9;
    bool t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &l4 };
    void** gc_raw_roots[10] = { &l0, &l1, &l2, &l3, &l5, &l6, &l7, &l10, &l11, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 10u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l4 = vader_effects_held_by(l1, l2);
    if (l4.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l5 = l4.payload.obj;
    vader_struct___lambda_env_vader_effects_16_t* _a0_obj = (vader_struct___lambda_env_vader_effects_16_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_effects_16_t));
    vader_obj_header_init(_a0_obj, 318u);
    _a0_obj->f_cap_0 = l0;
    _a0_obj->f_cap_1 = l3;
    l6 = (void*) _a0_obj;
    vader_array_t* _a1_arr = vader_array_new(98u, 0u, 13u, 936u);
    l7 = (void*) _a1_arr;
    l8 = ((vader_array_t*) l5)->length;
    l9 = INT64_C(0);
    while ((l9 < l8)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        l10 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l9);
        t0 = __lambda_vader_effects_15(l6, l10);
        if (t0) {
            l11 = l10;
            vader_array_push((vader_array_t*) l7, vader_ref_box(l11));
        }
        l9 = (l9 + INT64_C(1));
    }
    l5 = l7;
    t0 = std_iter_is_empty__toolchain_ast_AssertDecl___toolchain_ast_ConstDecl___toolchain_ast_EnumDecl___toolchain_ast_FnDecl___toolchain_ast_ImplDecl___toolchain_ast_ImportDecl___toolchain_ast_StructDecl___toolchain_ast_TraitDecl___toolchain_ast_TypeAliasDecl(l5);
    if (!(t0)) {
        l6 = ((vader_struct_vader_effects_RootEffects_t*) l2)->f_marked;
        l8 = ((vader_struct_vader_effects_FrozenRoot_t*) l1)->f_root;
        vader_array_t* _a3_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l8)
        t1 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l8);
        l6 = ((vader_struct_vader_effects_ParamEffects_t*) t1)->f_accesses;
        l7 = ((vader_struct_vader_effects_RootEffects_t*) l2)->f_lent;
        l8 = ((vader_struct_vader_effects_FrozenRoot_t*) l1)->f_root;
        vader_array_t* _a4_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l8)
        t1 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l8);
        l7 = ((vader_struct_vader_effects_ParamEffects_t*) t1)->f_accesses;
        vader_struct_vader_effects_RootCase_t* _a5_obj = (vader_struct_vader_effects_RootCase_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_RootCase_t));
        vader_obj_header_init(_a5_obj, 937u);
        _a5_obj->f_body = l0;
        _a5_obj->f_paths = l3;
        _a5_obj->f_held = l5;
        _a5_obj->f_marked = l6;
        _a5_obj->f_lent = l7;
        t1 = (void*) _a5_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

void* vader_effects_root_record(void* l0, int64_t l1) {
    void* l2;
    int64_t l3;
    void* t0;
    l2 = ((vader_struct_vader_effects_FrozenBody_t*) l0)->f_roots;
    l3 = ((vader_struct_vader_effects_Skeleton_t*) ((vader_struct_vader_effects_FrozenBody_t*) l0)->f_skeleton)->f_params;
    l3 = vader_chk_sub(i64, l1, l3);
    vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
    t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
    return t0;
}

static vader_box_t vader_effects_sequence_value(void* l0, void* l1) {
    void* l2 = NULL;
    void* l7 = NULL;
    int64_t l3, l4;
    vader_box_t l5 = vader_box_null(), l6 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l5, &l6 };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &l7 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_toolchain_ast_SeqLitExpr_t*) l1)->f_elements;
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        l5 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        l6 = vader_effects_value(l0, l5);
        l7 = VADER_UNION_FIELD(void*, vader_struct_toolchain_ast_ArrayTypeExpr_t, f_span, l5.payload.obj);
        vader_effects_escape(l0, l6, (uint8_t) 3, l7);
        l4 = (l4 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static vader_box_t vader_effects_sequence_walked(void* l0, void* l1) {
    void* l2 = NULL;
    int64_t l3, l4;
    vader_box_t l5 = vader_box_null();
    vader_box_t* gc_roots[1] = { &l5 };
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = l1;
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        l5 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        vader_effects_discard(l0, l5);
        l4 = (l4 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

bool vader_effects_settle(void* l0, void* l1) {
    void* l2 = NULL;
    int32_t l3;
    bool t0;
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_effects_EvalCtx_t*) l1)->f_facts;
    l3 = ((vader_struct_vader_effects_EvalCtx_t*) l1)->f_node;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
    l2 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
    t0 = vader_effects_evaluate(l0, l1, l2);
    { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_effects_settle_frozen(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    void* l14 = NULL;
    int64_t l4, l5, l12, l13;
    void** gc_raw_roots[11] = { &l0, &l1, &l2, &l3, &l6, &l7, &l8, &l9, &l10, &l11, &l14 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 11u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_effects_FrozenSites_t*) l0)->f_bodies;
    l4 = ((vader_array_t*) l3)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
        l6 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
        l7 = ((vader_struct_vader_effects_TraceCtx_t*) l1)->f_facts;
        l8 = ((vader_struct_vader_effects_TraceCtx_t*) l1)->f_index;
        l9 = vader_effects_body_ctx(l6, l7, l8, l2);
        l10 = vader_effects_evaluate_roots(((vader_struct_vader_effects_FrozenBody_t*) l6)->f_skeleton, l9);
        l11 = ((vader_struct_vader_effects_FrozenBody_t*) l6)->f_roots;
        l12 = ((vader_array_t*) l11)->length;
        l13 = INT64_C(0);
        while ((l13 < l12)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l11);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l13)
            l14 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l13);
            vader_effects_decide(l0, l6, l14, l10, l1);
            l13 = (l13 + INT64_C(1));
        }
        l5 = (l5 + INT64_C(1));
    }
    vader_effects_spread_fresh(l0);
    { vader_gc_top = gc_frame.prev; return; }
}

static void* vader_effects_settle_widenings(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    void* l5 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    int64_t l4, l6;
    void** gc_raw_roots[9] = { &l0, &l1, &l2, &l3, &l5, &l7, &l8, &l9, &l10 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 9u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(101u, 0u, 13u, 944u);
    l3 = (void*) _a0_arr;
    l4 = ((vader_array_t*) l0)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l3, (int64_t) l4);
    l3 = (void*) _a1_arr;
    l5 = l0;
    l4 = ((vader_array_t*) l5)->length;
    l6 = INT64_C(0);
    while ((l6 < l4)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        l7 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l6);
        l8 = ((vader_struct_vader_effects_CalleeIndex_t*) l2)->f_paths;
        l9 = ((vader_struct_vader_effects_CalleeIndex_t*) l2)->f_any;
        l10 = vader_effects_widening_outcome(l7, l1, l8, l9);
        vader_array_push((vader_array_t*) l3, vader_ref_box(l10));
        l6 = (l6 + INT64_C(1));
    }
    { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_effects_settled_slots(void* l0, void* l1, bool l2) {
    void* l3 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l15 = NULL;
    void* l16 = NULL;
    void* l18 = NULL;
    int64_t l4, l5, l10, l11, l12, l13, l17;
    vader_box_t l9 = vader_box_null();
    bool l14;
    void* t0 = NULL;
    bool t1;
    vader_box_t* gc_roots[1] = { &l9 };
    void** gc_raw_roots[10] = { &l0, &l1, &l3, &l6, &l7, &l8, &l15, &l16, &l18, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 10u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(212u, 1u, 13u, 1355u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = vader_box_obj(0u, NULL).payload.obj;
    l3 = (void*) _a0_arr;
    l4 = ((vader_struct_vader_effects_Skeleton_t*) l0)->f_slots;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l3, (int64_t) l4);
    l3 = (void*) _a1_arr;
    l4 = ((vader_struct_vader_effects_Skeleton_t*) l0)->f_params;
    l5 = ((vader_struct_vader_effects_Skeleton_t*) l0)->f_extra;
    l4 = vader_chk_add(i64, l4, l5);
    vader_array_t* _a2_arr = vader_array_new(16u, 0u, 8u, 292u);
    l6 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(12u, 0u, 12u, 286u);
    l7 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_new(15u, 0u, 7u, 291u);
    l8 = (void*) _a4_arr;
    vader_struct_std_collections_MutableMap__i64__bool_t* _a5_obj = (vader_struct_std_collections_MutableMap__i64__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i64__bool_t));
    vader_obj_header_init(_a5_obj, 427u);
    _a5_obj->f_ekeys = l6;
    _a5_obj->f_evals = l7;
    _a5_obj->f_index = l8;
    _a5_obj->f_mask = INT64_C(0);
    _a5_obj->f_size = INT64_C(0);
    _a5_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a5_obj;
    vader_struct_std_collections_MutableSet__i64_t* _a6_obj = (vader_struct_std_collections_MutableSet__i64_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i64_t));
    vader_obj_header_init(_a6_obj, 523u);
    _a6_obj->f_inner = t0;
    l6 = (void*) _a6_obj;
    vader_struct_vader_effects_SlotRoots_t* _a7_obj = (vader_struct_vader_effects_SlotRoots_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_SlotRoots_t));
    vader_obj_header_init(_a7_obj, 941u);
    _a7_obj->f_roots = l3;
    _a7_obj->f_root_count = l4;
    _a7_obj->f_seen = l6;
    l3 = (void*) _a7_obj;
    l4 = INT64_C(0);
    l5 = ((vader_struct_vader_effects_Skeleton_t*) l0)->f_params;
    while ((l4 < l5)) {
        vader_struct_vader_effects_Root_t* _a8_obj = (vader_struct_vader_effects_Root_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_Root_t));
        vader_obj_header_init(_a8_obj, 936u);
        _a8_obj->f_param = l4;
        _a8_obj->f_path = INT32_C(0);
        l6 = (void*) _a8_obj;
        vader_effects_include_root(l3, l4, l6);
        l4 = (l4 + INT64_C(1));
    }
    l9 = ((vader_struct_vader_effects_Skeleton_t*) l0)->f_seeds;
    if (l2) {
        if (!(l9.tag == 0u)) {
            l6 = l9.payload.obj;
            l7 = ((vader_struct_std_collections_MutableMap__i64__i64_t*) l6)->f_ekeys;
            l8 = ((vader_struct_std_collections_MutableMap__i64__i64_t*) l6)->f_evals;
            l4 = INT64_C(0);
            l5 = ((vader_struct_std_collections_MutableMap__i64__i64_t*) l6)->f_size;
            while ((l4 < l5)) {
                vader_array_t* _a9_slotarr = ((vader_array_t*) l7);
                VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l4)
                l10 = ((int64_t*) _a9_slotarr->buf->slots)[_a9_slotarr->offset + (size_t) l4];
                vader_array_t* _a10_slotarr = ((vader_array_t*) l8);
                VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a10_slotarr, l4)
                l11 = ((int64_t*) _a10_slotarr->buf->slots)[_a10_slotarr->offset + (size_t) l4];
                l12 = l10;
                l13 = l11;
                vader_struct_vader_effects_Root_t* _a11_obj = (vader_struct_vader_effects_Root_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_Root_t));
                vader_obj_header_init(_a11_obj, 936u);
                _a11_obj->f_param = l12;
                _a11_obj->f_path = INT32_C(0);
                l6 = (void*) _a11_obj;
                vader_effects_include_root(l3, l13, l6);
                l4 = (l4 + INT64_C(1));
            }
        }
    }
    vader_array_t* _a12_arr = vader_array_new(16u, 1u, 8u, 292u);
    ((int64_t*) _a12_arr->buf->slots)[_a12_arr->offset + 0u] = (int64_t) INT64_C(0);
    l6 = (void*) _a12_arr;
    l4 = ((vader_array_t*) ((vader_struct_vader_effects_Skeleton_t*) l0)->f_flows)->length;
    vader_array_t* _a13_arr = vader_array_repeat((vader_array_t*) l6, (int64_t) l4);
    l6 = (void*) _a13_arr;
    vader_array_t* _a14_arr = vader_array_new(16u, 1u, 8u, 292u);
    ((int64_t*) _a14_arr->buf->slots)[_a14_arr->offset + 0u] = (int64_t) INT64_C(0);
    l7 = (void*) _a14_arr;
    l4 = ((vader_struct_vader_effects_Skeleton_t*) l0)->f_arguments;
    vader_array_t* _a15_arr = vader_array_repeat((vader_array_t*) l7, (int64_t) l4);
    l7 = (void*) _a15_arr;
    for (;;) {
        l14 = false;
        l4 = INT64_C(0);
        l5 = ((vader_array_t*) ((vader_struct_vader_effects_Skeleton_t*) l0)->f_flows)->length;
        while ((l4 < l5)) {
            vader_array_t* _a16_slotarr = ((vader_array_t*) ((vader_struct_vader_effects_Skeleton_t*) l0)->f_flows);
            VADER_ARRAY_RESOLVE_BUF(_a16_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a16_slotarr, l4)
            l8 = vader_array_ref_load_obj(_a16_slotarr->buf, _a16_slotarr->offset + (size_t) l4);
            vader_array_t* _a17_slotarr = ((vader_array_t*) l6);
            VADER_ARRAY_RESOLVE_BUF(_a17_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a17_slotarr, l4)
            l10 = ((int64_t*) _a17_slotarr->buf->slots)[_a17_slotarr->offset + (size_t) l4];
            l11 = ((vader_struct_vader_effects_Flow_t*) l8)->f_from;
            l12 = vader_effects_held_count(l3, l11);
            if (l10 == l12) {
                l4 = (l4 + INT64_C(1));
                continue;
            }
            vader_array_t* _a18_slotarr = ((vader_array_t*) l6);
            VADER_ARRAY_RESOLVE_BUF(_a18_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a18_slotarr, l4)
            ((int64_t*) _a18_slotarr->buf->slots)[_a18_slotarr->offset + (size_t) l4] = (int64_t) l12;
            l15 = ((vader_struct_vader_effects_EvalCtx_t*) l1)->f_paths;
            t1 = vader_effects_reroot(l3, l8, l10, l12, l0, l15);
            if (t1) {
                l14 = true;
            }
            l4 = (l4 + INT64_C(1));
        }
        l16 = ((vader_struct_vader_effects_Skeleton_t*) l0)->f_sites;
        l13 = ((vader_array_t*) l16)->length;
        l17 = INT64_C(0);
        while ((l17 < l13)) {
            vader_array_t* _a19_slotarr = ((vader_array_t*) l16);
            VADER_ARRAY_RESOLVE_BUF(_a19_slotarr)
            l18 = vader_array_ref_load_obj(_a19_slotarr->buf, _a19_slotarr->offset + (size_t) l17);
            t1 = vader_effects_collect_returned(l3, l18, l1, l7);
            if (t1) {
                l14 = true;
            }
            l17 = (l17 + INT64_C(1));
        }
        if (!(l14)) {
            { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
        }
        continue;
    }
    vader_gc_top = gc_frame.prev;
}

static vader_box_t vader_effects_single(void* l0) {
    int64_t t0;
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

static vader_box_t vader_effects_site_callee(void* l0, uint8_t l1, int64_t l2) {
    void* t0;
    vader_box_t t1;
    t0 = vader_typecheck_sites_of(((vader_struct_vader_typecheck_TypedProgram_t*) ((vader_struct_vader_effects_WalkCtx_t*) l0)->f_typed)->f_call_sites, l1);
    t1 = std_collections_MutableMap_std_core_Index_at__i64__Any(t0, l2);
    return t1;
}

static void* vader_effects_skeleton_of(void* l0, void* l1, void* l2, void* l3, void* l4, int32_t l5) {
    void* l6 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l11 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    uint8_t l10;
    int64_t l15, l16;
    uint64_t l17, l19;
    vader_box_t l18 = vader_box_null();
    int32_t l20, l21;
    int64_t t0;
    void* t1 = NULL;
    vader_box_t t2 = vader_box_null();
    bool t3;
    vader_box_t* gc_roots[2] = { &l18, &t2 };
    void** gc_raw_roots[14] = {
        &l0, &l1, &l2, &l3, &l4, &l6, &l7, &l8, &l9, &l11, &l12, &l13, &l14, &t1,
    };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 14u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_toolchain_ast_FnDecl_t*) l0)->f_params)->length;
    l6 = vader_effects_new_skeleton(t0);
    vader_array_t* _a0_arr = vader_array_new(15u, 0u, 7u, 291u);
    l7 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(16u, 0u, 8u, 292u);
    l8 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(15u, 0u, 7u, 291u);
    l9 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__i32__i64_t* _a3_obj = (vader_struct_std_collections_MutableMap__i32__i64_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__i64_t));
    vader_obj_header_init(_a3_obj, 388u);
    _a3_obj->f_ekeys = l7;
    _a3_obj->f_evals = l8;
    _a3_obj->f_index = l9;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    l7 = (void*) _a3_obj;
    l10 = vader_effects_result_effect_of(l0);
    vader_array_t* _a4_arr = vader_array_new(90u, 0u, 13u, 924u);
    l8 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_new(16u, 0u, 8u, 292u);
    l9 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(12u, 0u, 12u, 286u);
    l11 = (void*) _a6_arr;
    vader_array_t* _a7_arr = vader_array_new(15u, 0u, 7u, 291u);
    l12 = (void*) _a7_arr;
    vader_struct_std_collections_MutableMap__i64__bool_t* _a8_obj = (vader_struct_std_collections_MutableMap__i64__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i64__bool_t));
    vader_obj_header_init(_a8_obj, 427u);
    _a8_obj->f_ekeys = l9;
    _a8_obj->f_evals = l11;
    _a8_obj->f_index = l12;
    _a8_obj->f_mask = INT64_C(0);
    _a8_obj->f_size = INT64_C(0);
    _a8_obj->f_tombs = INT64_C(0);
    t1 = (void*) _a8_obj;
    vader_struct_std_collections_MutableSet__i64_t* _a9_obj = (vader_struct_std_collections_MutableSet__i64_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i64_t));
    vader_obj_header_init(_a9_obj, 523u);
    _a9_obj->f_inner = t1;
    l9 = (void*) _a9_obj;
    vader_array_t* _a10_arr = vader_array_new(16u, 0u, 8u, 292u);
    l11 = (void*) _a10_arr;
    vader_array_t* _a11_arr = vader_array_new(12u, 0u, 12u, 286u);
    l12 = (void*) _a11_arr;
    vader_array_t* _a12_arr = vader_array_new(15u, 0u, 7u, 291u);
    l13 = (void*) _a12_arr;
    vader_struct_std_collections_MutableMap__i64__bool_t* _a13_obj = (vader_struct_std_collections_MutableMap__i64__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i64__bool_t));
    vader_obj_header_init(_a13_obj, 427u);
    _a13_obj->f_ekeys = l11;
    _a13_obj->f_evals = l12;
    _a13_obj->f_index = l13;
    _a13_obj->f_mask = INT64_C(0);
    _a13_obj->f_size = INT64_C(0);
    _a13_obj->f_tombs = INT64_C(0);
    t1 = (void*) _a13_obj;
    vader_struct_std_collections_MutableSet__i64_t* _a14_obj = (vader_struct_std_collections_MutableSet__i64_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i64_t));
    vader_obj_header_init(_a14_obj, 523u);
    _a14_obj->f_inner = t1;
    l11 = (void*) _a14_obj;
    vader_array_t* _a15_arr = vader_array_new(15u, 0u, 7u, 291u);
    l12 = (void*) _a15_arr;
    vader_array_t* _a16_arr = vader_array_new(12u, 0u, 12u, 286u);
    l13 = (void*) _a16_arr;
    vader_array_t* _a17_arr = vader_array_new(15u, 0u, 7u, 291u);
    l14 = (void*) _a17_arr;
    vader_struct_std_collections_MutableMap__i32__bool_t* _a18_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
    vader_obj_header_init(_a18_obj, 385u);
    _a18_obj->f_ekeys = l12;
    _a18_obj->f_evals = l13;
    _a18_obj->f_index = l14;
    _a18_obj->f_mask = INT64_C(0);
    _a18_obj->f_size = INT64_C(0);
    _a18_obj->f_tombs = INT64_C(0);
    t1 = (void*) _a18_obj;
    vader_struct_std_collections_MutableSet__i32_t* _a19_obj = (vader_struct_std_collections_MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i32_t));
    vader_obj_header_init(_a19_obj, 522u);
    _a19_obj->f_inner = t1;
    l12 = (void*) _a19_obj;
    vader_struct_vader_effects_WalkCtx_t* _a20_obj = (vader_struct_vader_effects_WalkCtx_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_WalkCtx_t));
    vader_obj_header_init(_a20_obj, 943u);
    _a20_obj->f_s = l6;
    _a20_obj->f_typed = l1;
    _a20_obj->f_index = l2;
    _a20_obj->f_slots = l7;
    _a20_obj->f_lambda_depth = INT32_C(0);
    _a20_obj->f_result_effect = l10;
    _a20_obj->f_frozen = l3;
    _a20_obj->f_widenings = l4;
    _a20_obj->f_roots = l8;
    _a20_obj->f_place_bases = l9;
    _a20_obj->f_pure = l11;
    _a20_obj->f_seen_names = l12;
    l6 = (void*) _a20_obj;
    l15 = INT64_C(0);
    l16 = ((vader_array_t*) ((vader_struct_toolchain_ast_FnDecl_t*) l0)->f_params)->length;
    while ((l15 < l16)) {
        vader_array_t* _a21_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_FnDecl_t*) l0)->f_params);
        VADER_ARRAY_RESOLVE_BUF(_a21_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a21_slotarr, l15)
        l7 = vader_array_ref_load_obj(_a21_slotarr->buf, _a21_slotarr->offset + (size_t) l15);
        l9 = ((vader_struct_vader_resolver_ResolvedModule_t*) ((vader_struct_vader_typecheck_TypedProgram_t*) l1)->f_resolved)->f_idents;
        l17 = toolchain_span_Span_std_core_Hash_hash(((vader_struct_toolchain_ast_FnParam_t*) l7)->f_span);
        l18 = std_collections_MutableMap_std_core_Index_at__u64__Any(l9, l17);
        if (l18.tag == 0u) {
            l15 = (l15 + INT64_C(1));
            continue;
        }
        l8 = l18.payload.obj;
        l11 = ((vader_struct_vader_typecheck_TypedProgram_t*) l1)->f_param_types;
        l19 = toolchain_span_Span_std_core_Hash_hash(((vader_struct_toolchain_ast_FnParam_t*) l7)->f_span);
        t2 = std_collections_MutableMap_std_core_Index_at__u64__Any(l11, l19);
        t3 = vader_effects_holds_references(t2);
        if (t3) {
            l12 = ((vader_struct_vader_effects_WalkCtx_t*) l6)->f_slots;
            l20 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l8)->f_id;
            std_collections_MutableMap_std_core_IndexSet_set_at__i32__i64(l12, l20, l15);
            l13 = ((vader_struct_vader_effects_WalkCtx_t*) l6)->f_seen_names;
            l21 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l8)->f_id;
            std_collections_add__i32(l13, l21);
        }
        l15 = (l15 + INT64_C(1));
    }
    l18 = ((vader_struct_toolchain_ast_FnDecl_t*) l0)->f_body;
    if (l18.tag == 0u) {
        { void* __vret = ((vader_struct_vader_effects_WalkCtx_t*) l6)->f_s; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l7 = l18.payload.obj;
    l18 = vader_effects_block_value(l6, l7);
    l10 = ((vader_struct_vader_effects_WalkCtx_t*) l6)->f_result_effect;
    l7 = ((vader_struct_toolchain_ast_BlockExpr_t*) l7)->f_span;
    vader_effects_escape(l6, l18, l10, l7);
    vader_effects_note_frozen_body(l6, l5, vader_box_obj(0u, NULL));
    { void* __vret = ((vader_struct_vader_effects_WalkCtx_t*) l6)->f_s; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_effects_spread(void* l0, vader_box_t l1, void* l2) {
    int64_t l3, l8, l9;
    vader_box_t l4 = vader_box_null(), l12 = vader_box_null();
    void* l5 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l14 = NULL;
    vader_string_t l10 = 0;
    vader_string_t l11 = 0;
    int32_t l13;
    vader_box_t t0 = vader_box_null();
    bool t1;
    vader_box_t* gc_roots[4] = { &l1, &l4, &l12, &t0 };
    void** gc_raw_roots[6] = { &l0, &l2, &l5, &l6, &l7, &l14 };
    vader_string_t* gc_atom_roots[2] = { &l10, &l11 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = vader_effects_value(l0, l1);
    if (l4.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l3 = ((int64_t) l4.payload.i);
    l4 = vader_effects_struct_fields_of(l0, l1);
    if (l4.tag == 0u) {
        l5 = ((vader_struct_vader_effects_WalkCtx_t*) l0)->f_s;
        l6 = VADER_UNION_FIELD(void*, vader_struct_toolchain_ast_ArrayTypeExpr_t, f_span, l1.payload.obj);
        vader_effects_add_mark(l5, l3, INT32_C(1), (uint8_t) 3, l6);
        { vader_gc_top = gc_frame.prev; return; }
    }
    l5 = l4.payload.obj;
    l6 = ((vader_struct_std_collections_MutableMap__string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_t*) l5)->f_ekeys;
    l7 = ((vader_struct_std_collections_MutableMap__string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_t*) l5)->f_evals;
    l8 = INT64_C(0);
    l9 = ((vader_struct_std_collections_MutableMap__string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_t*) l5)->f_size;
    while ((l8 < l9)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l8)
        t0 = vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l8];
        l10 = t0.payload.s;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l8)
        l4 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l8);
        l11 = l10;
        l12 = l4;
        t1 = std_collections_MutableSet_std_core_Contains_contains__string(l2, l11);
        if (!(t1)) {
            t1 = vader_effects_holds_references(l12);
            if (t1) {
                l5 = ((vader_struct_vader_effects_WalkCtx_t*) l0)->f_s;
                l13 = vader_effects_path_to(((vader_struct_vader_effects_CalleeIndex_t*) ((vader_struct_vader_effects_WalkCtx_t*) l0)->f_index)->f_paths, l11);
                l14 = VADER_UNION_FIELD(void*, vader_struct_toolchain_ast_ArrayTypeExpr_t, f_span, l1.payload.obj);
                vader_effects_add_mark(l5, l3, l13, (uint8_t) 3, l14);
            }
        }
        l8 = (l8 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_effects_spread_fresh(void* l0) {
    void* l1 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    int64_t l2, l5;
    int32_t l6, l9;
    vader_box_t l7 = vader_box_null(), l8 = vader_box_null();
    int64_t t0;
    bool t1;
    vader_box_t* gc_roots[2] = { &l7, &l8 };
    void** gc_raw_roots[4] = { &l0, &l1, &l3, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(15u, 0u, 7u, 291u);
    l1 = (void*) _a0_arr;
    l2 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) ((vader_struct_std_collections_MutableSet__i32_t*) ((vader_struct_vader_typecheck_FreshReads_t*) ((vader_struct_vader_effects_FrozenSites_t*) l0)->f_fresh)->f_constants)->f_inner)->f_size;
    if ((INT64_C(0) < l2)) {
        l2 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) ((vader_struct_std_collections_MutableSet__i32_t*) ((vader_struct_vader_typecheck_FreshReads_t*) ((vader_struct_vader_effects_FrozenSites_t*) l0)->f_fresh)->f_constants)->f_inner)->f_size;
    } else {
        l2 = INT64_C(0);
    }
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l1, (int64_t) l2);
    l1 = (void*) _a1_arr;
    l3 = ((vader_struct_vader_typecheck_FreshReads_t*) ((vader_struct_vader_effects_FrozenSites_t*) l0)->f_fresh)->f_constants;
    l4 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) ((vader_struct_std_collections_MutableSet__i32_t*) l3)->f_inner)->f_ekeys;
    l2 = INT64_C(0);
    l5 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) ((vader_struct_std_collections_MutableSet__i32_t*) l3)->f_inner)->f_size;
    vader_array_t* _pc38_hdr = (vader_array_t*) l1;
    size_t _pc38_len = _pc38_hdr->length;
    size_t _pc38_cap = (_pc38_hdr->offset == 0 && !vader_array_is_borrowed(_pc38_hdr) && _pc38_hdr->length >= _pc38_hdr->buf->length) ? _pc38_hdr->capacity : (size_t) 0;
    void* _pc38_slots = _pc38_hdr->buf->slots;
    for (;;) {
        if ((l2 < l5)) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) l4);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l2)
            l6 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l2];
            if (VADER_LIKELY(_pc38_len < _pc38_cap)) {
                ((int32_t*) _pc38_slots)[_pc38_len] = (int32_t) (l6);
                _pc38_len += 1;
            } else {
                _pc38_hdr->length = _pc38_len;
                if (_pc38_hdr->buf->length < _pc38_len) {
                    _pc38_hdr->buf->length = _pc38_len;
                }
                vader_array_push_i32((vader_array_t*) l1, l6);
                _pc38_hdr = (vader_array_t*) l1;
                _pc38_len = _pc38_hdr->length;
                _pc38_cap = (_pc38_hdr->offset == 0 && !vader_array_is_borrowed(_pc38_hdr) && _pc38_hdr->length >= _pc38_hdr->buf->length) ? _pc38_hdr->capacity : (size_t) 0;
                _pc38_slots = _pc38_hdr->buf->slots;
            }
            l2 = (l2 + INT64_C(1));
            continue;
        }
        _pc38_hdr->length = _pc38_len;
        if (_pc38_hdr->buf->length < _pc38_len) {
            _pc38_hdr->buf->length = _pc38_len;
        }
        break;
    }
    for (;;) {
        t0 = ((vader_array_t*) l1)->length;
        if ((t0 > INT64_C(0))) {
            l7 = vader_array_remove_last((vader_array_t*) l1);
            if (l7.tag == 0u) break;
            l6 = ((int32_t) l7.payload.i);
            l8 = std_collections_MutableMap_std_core_Index_at__i32__Any(((vader_struct_vader_effects_FrozenSites_t*) l0)->f_kept_by_constants, l6);
            if (l8.tag == 0u) {
                vader_array_t* _a3_arr = vader_array_new(86u, 0u, 13u, 916u);
                l3 = (void*) _a3_arr;
            } else {
                l3 = l8.payload.obj;
            }
            l2 = ((vader_array_t*) l3)->length;
            l5 = INT64_C(0);
            while ((l5 < l2)) {
                vader_array_t* _a4_slotarr = ((vader_array_t*) l3);
                VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                l4 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l5);
                t1 = vader_effects_mark_fresh(l0, l4);
                if (t1) {
                    l9 = ((vader_struct_vader_effects_ConstantUse_t*) l4)->f_symbol;
                    vader_array_push_i32((vader_array_t*) l1, l9);
                }
                l5 = (l5 + INT64_C(1));
            }
            continue;
        }
        break;
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_effects_spread_views(void* l0, void* l1, void* l2, void* l3, void* l4, void* l5) {
    void* l6 = NULL;
    void* l7 = NULL;
    void* l11 = NULL;
    void* l15 = NULL;
    void* l16 = NULL;
    void* l17 = NULL;
    void* l18 = NULL;
    void* l19 = NULL;
    void* l20 = NULL;
    void* l21 = NULL;
    void* l22 = NULL;
    void* l23 = NULL;
    void* l24 = NULL;
    void* l25 = NULL;
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
    void* l43 = NULL;
    int64_t l8, l9, l12, l13, l41, l42;
    int32_t l10, l14;
    bool t0;
    void* t1 = NULL;
    void** gc_raw_roots[37] = {
        &l0, &l1, &l2, &l3, &l4, &l5, &l6, &l7, &l11, &l15, &l16, &l17, &l18, &l19, &l20, &l21,
        &l22, &l23, &l24, &l25, &l26, &l27, &l28, &l29, &l30, &l31, &l32, &l33, &l34, &l35, &l36,
        &l37, &l38, &l39, &l40, &l43, &t1,
    };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 37u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l6 = vader_effects_view_returners(l0, l1, l3, l4);
    for (;;) {
        t0 = std_iter_is_empty__i32(l6);
        if (!(t0)) {
            l7 = l6;
            l8 = ((vader_array_t*) l7)->length;
            l9 = INT64_C(0);
            while ((l9 < l8)) {
                vader_array_t* _a0_slotarr = ((vader_array_t*) l7);
                VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
                l10 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l9];
                std_collections_add__i32(((vader_struct_vader_effects_CalleeIndex_t*) l0)->f_view_nodes, l10);
                l9 = (l9 + INT64_C(1));
            }
            l11 = vader_effects_callers_of(l5, l6);
            l12 = ((vader_array_t*) l11)->length;
            l13 = INT64_C(0);
            while ((l13 < l12)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) l11);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l13)
                l14 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l13];
                vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_effects_CalleeIndex_t*) l0)->f_functions);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l14)
                l15 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l14);
                vader_array_t* _a3_arr = vader_array_new(91u, 0u, 13u, 925u);
                l16 = (void*) _a3_arr;
                vader_array_t* _a4_arr = vader_array_new(89u, 0u, 13u, 923u);
                l17 = (void*) _a4_arr;
                vader_array_t* _a5_arr = vader_array_new(14u, 0u, 0u, 288u);
                l18 = (void*) _a5_arr;
                vader_array_t* _a6_arr = vader_array_new(12u, 0u, 12u, 286u);
                l19 = (void*) _a6_arr;
                vader_array_t* _a7_arr = vader_array_new(15u, 0u, 7u, 291u);
                l20 = (void*) _a7_arr;
                vader_struct_std_collections_MutableMap__string__bool_t* _a8_obj = (vader_struct_std_collections_MutableMap__string__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__bool_t));
                vader_obj_header_init(_a8_obj, 458u);
                _a8_obj->f_ekeys = l18;
                _a8_obj->f_evals = l19;
                _a8_obj->f_index = l20;
                _a8_obj->f_mask = INT64_C(0);
                _a8_obj->f_size = INT64_C(0);
                _a8_obj->f_tombs = INT64_C(0);
                t1 = (void*) _a8_obj;
                vader_struct_std_collections_MutableSet__string_t* _a9_obj = (vader_struct_std_collections_MutableSet__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__string_t));
                vader_obj_header_init(_a9_obj, 524u);
                _a9_obj->f_inner = t1;
                l21 = (void*) _a9_obj;
                vader_array_t* _a10_arr = vader_array_new(16u, 0u, 8u, 292u);
                l22 = (void*) _a10_arr;
                vader_array_t* _a11_arr = vader_array_new(12u, 0u, 12u, 286u);
                l23 = (void*) _a11_arr;
                vader_array_t* _a12_arr = vader_array_new(15u, 0u, 7u, 291u);
                l24 = (void*) _a12_arr;
                vader_struct_std_collections_MutableMap__i64__bool_t* _a13_obj = (vader_struct_std_collections_MutableMap__i64__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i64__bool_t));
                vader_obj_header_init(_a13_obj, 427u);
                _a13_obj->f_ekeys = l22;
                _a13_obj->f_evals = l23;
                _a13_obj->f_index = l24;
                _a13_obj->f_mask = INT64_C(0);
                _a13_obj->f_size = INT64_C(0);
                _a13_obj->f_tombs = INT64_C(0);
                t1 = (void*) _a13_obj;
                vader_struct_std_collections_MutableSet__i64_t* _a14_obj = (vader_struct_std_collections_MutableSet__i64_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i64_t));
                vader_obj_header_init(_a14_obj, 523u);
                _a14_obj->f_inner = t1;
                l25 = (void*) _a14_obj;
                vader_array_t* _a15_arr = vader_array_new(15u, 0u, 7u, 291u);
                l26 = (void*) _a15_arr;
                vader_array_t* _a16_arr = vader_array_new(12u, 0u, 12u, 286u);
                l27 = (void*) _a16_arr;
                vader_array_t* _a17_arr = vader_array_new(15u, 0u, 7u, 291u);
                l28 = (void*) _a17_arr;
                vader_struct_std_collections_MutableMap__i32__bool_t* _a18_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
                vader_obj_header_init(_a18_obj, 385u);
                _a18_obj->f_ekeys = l26;
                _a18_obj->f_evals = l27;
                _a18_obj->f_index = l28;
                _a18_obj->f_mask = INT64_C(0);
                _a18_obj->f_size = INT64_C(0);
                _a18_obj->f_tombs = INT64_C(0);
                t1 = (void*) _a18_obj;
                vader_struct_std_collections_MutableSet__i32_t* _a19_obj = (vader_struct_std_collections_MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i32_t));
                vader_obj_header_init(_a19_obj, 522u);
                _a19_obj->f_inner = t1;
                l29 = (void*) _a19_obj;
                vader_struct_vader_typecheck_FreshReads_t* _a20_obj = (vader_struct_vader_typecheck_FreshReads_t*) vader_gc_alloc(sizeof(vader_struct_vader_typecheck_FreshReads_t));
                vader_obj_header_init(_a20_obj, 1221u);
                _a20_obj->f_uses = l25;
                _a20_obj->f_constants = l29;
                l30 = (void*) _a20_obj;
                vader_array_t* _a21_arr = vader_array_new(15u, 0u, 7u, 291u);
                l31 = (void*) _a21_arr;
                vader_array_t* _a22_arr = vader_array_new(21u, 0u, 0u, 299u);
                l32 = (void*) _a22_arr;
                vader_array_t* _a23_arr = vader_array_new(15u, 0u, 7u, 291u);
                l33 = (void*) _a23_arr;
                vader_struct_std_collections_MutableMap__i32__Any___t* _a24_obj = (vader_struct_std_collections_MutableMap__i32__Any___t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__Any___t));
                vader_obj_header_init(_a24_obj, 384u);
                _a24_obj->f_ekeys = l31;
                _a24_obj->f_evals = l32;
                _a24_obj->f_index = l33;
                _a24_obj->f_mask = INT64_C(0);
                _a24_obj->f_size = INT64_C(0);
                _a24_obj->f_tombs = INT64_C(0);
                l34 = (void*) _a24_obj;
                vader_struct_vader_effects_FrozenSites_t* _a25_obj = (vader_struct_vader_effects_FrozenSites_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_FrozenSites_t));
                vader_obj_header_init(_a25_obj, 926u);
                _a25_obj->f_sites = l16;
                _a25_obj->f_bodies = l17;
                _a25_obj->f_written = l21;
                _a25_obj->f_fresh = l30;
                _a25_obj->f_kept_by_constants = l34;
                l35 = (void*) _a25_obj;
                vader_array_t* _a26_arr = vader_array_new(97u, 0u, 13u, 935u);
                l36 = (void*) _a26_arr;
                l37 = ((vader_struct_vader_effects_Function_t*) l15)->f_decl;
                l38 = ((vader_struct_vader_effects_Function_t*) l15)->f_typed;
                l39 = vader_effects_skeleton_of(l37, l38, l0, l35, l36, l14);
                vader_array_t* _a27_slotarr = ((vader_array_t*) l2);
                VADER_ARRAY_RESOLVE_BUF(_a27_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a27_slotarr, l14)
                vader_array_ref_store(_a27_slotarr->buf, _a27_slotarr->offset + (size_t) l14, l39);
                VADER_WRITE_BARRIER(_a27_slotarr->buf);
                l40 = ((vader_struct_vader_effects_FrozenSites_t*) l35)->f_bodies;
                l41 = ((vader_array_t*) l40)->length;
                l42 = INT64_C(0);
                while ((l42 < l41)) {
                    vader_array_t* _a28_slotarr = ((vader_array_t*) l40);
                    VADER_ARRAY_RESOLVE_BUF(_a28_slotarr)
                    l43 = vader_array_ref_load_obj(_a28_slotarr->buf, _a28_slotarr->offset + (size_t) l42);
                    vader_effects_replace_body(l1, l43);
                    l42 = (l42 + INT64_C(1));
                }
                l13 = (l13 + INT64_C(1));
            }
            l6 = vader_effects_view_returners(l0, l1, l3, l4);
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
    int64_t t1;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = std_collections_MutableMap_std_core_Index_at__string__i32(((vader_struct_vader_effects_PathTable_t*) l0)->f_step_ids, l1);
    if (!(l2.tag == 0u)) {
        t0 = ((int32_t) l2.payload.i);
        { int32_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = ((vader_array_t*) ((vader_struct_vader_effects_PathTable_t*) l0)->f_step_names)->length;
    l3 = ((int32_t) (int64_t) t1);
    vader_array_push((vader_array_t*) ((vader_struct_vader_effects_PathTable_t*) l0)->f_step_names, vader_box_string(288u, l1));
    std_collections_MutableMap_std_core_IndexSet_set_at__string__i32(((vader_struct_vader_effects_PathTable_t*) l0)->f_step_ids, l1, l3);
    { int32_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_effects_step_slot(void* l0, vader_box_t l1, vader_string_t l2) {
    int64_t l3;
    vader_box_t l4 = vader_box_null();
    int32_t l5;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l1, &l4, &t0 };
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[1] = { &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = l1;
    if (l4.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l3 = ((int64_t) l4.payload.i);
    l5 = vader_effects_path_to(((vader_struct_vader_effects_CalleeIndex_t*) ((vader_struct_vader_effects_WalkCtx_t*) l0)->f_index)->f_paths, l2);
    t0 = vader_effects_path_slot(l0, vader_box_i64(292u, l3), l5);
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
    if (!(l2 == 856u)) {
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
    int64_t l6, l7, l8;
    void* t0 = NULL;
    int32_t t1;
    int64_t t2, t3;
    void** gc_raw_roots[4] = { &l0, &l2, &l5, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(15u, 0u, 7u, 291u);
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
    vader_array_t* _a4_arr = vader_array_new(15u, 0u, 7u, 291u);
    l5 = (void*) _a4_arr;
    l6 = ((vader_array_t*) l2)->length;
    vader_array_t* _a5_arr = vader_array_repeat((vader_array_t*) l5, (int64_t) l6);
    l5 = (void*) _a5_arr;
    l6 = INT64_C(0);
    l7 = ((vader_array_t*) l2)->length;
    vader_array_t* _pc45_hdr = (vader_array_t*) l5;
    size_t _pc45_len = _pc45_hdr->length;
    size_t _pc45_cap = (_pc45_hdr->offset == 0 && !vader_array_is_borrowed(_pc45_hdr) && _pc45_hdr->length >= _pc45_hdr->buf->length) ? _pc45_hdr->capacity : (size_t) 0;
    void* _pc45_slots = _pc45_hdr->buf->slots;
    for (;;) {
        if ((l6 < l7)) {
            t2 = ((vader_array_t*) l2)->length;
            t3 = vader_chk_sub(i64, t2, INT64_C(1));
            l8 = vader_chk_sub(i64, t3, l6);
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
            l6 = (l6 + INT64_C(1));
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
    int64_t l2;
    vader_box_t l3;
    l2 = VADER_UNION_FIELD(int64_t, vader_struct_toolchain_ast_ArrayTypeExpr_t, f_id, l1.payload.obj);
    l3 = vader_effects_site_callee(l0, (uint8_t) 6, l2);
    if (l3.tag == 0u) {
        return true;
    }
    return l3.tag == 1198u;
}

static void vader_effects_stmt(void* l0, vader_box_t l1) {
    vader_box_t l2 = vader_box_null(), l3 = vader_box_null();
    void* l4 = NULL;
    void* t0 = NULL;
    vader_box_t* gc_roots[3] = { &l1, &l2, &l3 };
    void** gc_raw_roots[3] = { &l0, &l4, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l1.tag == 583u) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_toolchain_ast_LetStmt_t*) t0)->f_binding;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_toolchain_ast_LetStmt_t*) t0)->f_value;
        l3 = vader_effects_value(l0, l3);
        vader_effects_bind(l0, l2, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 537u) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_toolchain_ast_AssignStmt_t*) t0)->f_target;
        vader_effects_note_place(l0, l2);
        t0 = l1.payload.obj;
        l2 = ((vader_struct_toolchain_ast_AssignStmt_t*) t0)->f_target;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_toolchain_ast_AssignStmt_t*) t0)->f_value;
        l3 = vader_effects_value(l0, l3);
        vader_effects_assign(l0, l2, l3);
    } else if (l1.tag == 553u) {
        l4 = l1.payload.obj;
        vader_effects_destructure_assign(l0, l4);
    } else if (l1.tag == 561u) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_toolchain_ast_ExprStmt_t*) t0)->f_expr;
        vader_effects_discard(l0, l2);
    } else if (l1.tag == 601u) {
        l4 = l1.payload.obj;
        vader_effects_return_stmt(l0, l4);
    } else if (l1.tag == 624u) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_toolchain_ast_YieldStmt_t*) t0)->f_value;
        l2 = vader_effects_value(l0, l2);
        t0 = l1.payload.obj;
        l4 = ((vader_struct_toolchain_ast_YieldStmt_t*) t0)->f_span;
        vader_effects_escape(l0, l2, (uint8_t) 3, l4);
    } else if (l1.tag == 567u) {
        l4 = l1.payload.obj;
        vader_effects_for_stmt(l0, l4);
    } else if (!((l1.tag == 542u || l1.tag == 548u))) {
        if (!(l1.tag == 551u)) {
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
    void* l11 = NULL;
    int64_t l3, l4, l6;
    vader_box_t l5 = vader_box_null(), l7 = vader_box_null(), l8 = vader_box_null();
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[4] = { &l5, &l7, &l8, &t1 };
    void** gc_raw_roots[7] = { &l0, &l1, &l2, &l9, &l10, &l11, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 7u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_toolchain_ast_StringLitExpr_t*) l1)->f_parts;
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        l5 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        if (l5.tag == 605u) {
            t0 = l5.payload.obj;
            l6 = VADER_UNION_FIELD(int64_t, vader_struct_toolchain_ast_ArrayTypeExpr_t, f_id, ((vader_struct_toolchain_ast_StringLitInterp_t*) t0)->f_expr.payload.obj);
            l7 = vader_effects_site_callee(l0, (uint8_t) 7, l6);
            t0 = l5.payload.obj;
            l8 = ((vader_struct_toolchain_ast_StringLitInterp_t*) t0)->f_expr;
            t1 = vader_effects_value(l0, l8);
            vader_array_t* _a1_arr = vader_array_new(214u, 1u, 0u, 1414u);
            vader_array_box_slots(_a1_arr->buf)[_a1_arr->offset + 0u] = t1;
            l9 = (void*) _a1_arr;
            t0 = l5.payload.obj;
            l10 = ((vader_struct_toolchain_ast_StringLitInterp_t*) t0)->f_span;
            t0 = l5.payload.obj;
            vader_array_t* _a2_arr = vader_array_new(216u, 1u, 13u, 1457u);
            ((void**) _a2_arr->buf->slots)[_a2_arr->offset + 0u] = ((vader_struct_toolchain_ast_StringLitInterp_t*) t0)->f_expr.payload.obj;
            l11 = (void*) _a2_arr;
            vader_effects_call(l0, l7, l9, l10, l11);
        }
        l4 = (l4 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static vader_box_t vader_effects_struct_fields_of(void* l0, vader_box_t l1) {
    vader_box_t l2;
    void* l3;
    int64_t l4;
    int32_t l5;
    void* t0;
    vader_box_t t1;
    l3 = ((vader_struct_vader_typecheck_TypedProgram_t*) ((vader_struct_vader_effects_WalkCtx_t*) l0)->f_typed)->f_expr_types;
    l4 = VADER_UNION_FIELD(int64_t, vader_struct_toolchain_ast_ArrayTypeExpr_t, f_id, l1.payload.obj);
    l2 = std_collections_MutableMap_std_core_Index_at__i64__Any(l3, l4);
    if (l2.tag == 0u) {
        return vader_box_obj(0u, NULL);
    }
    if (!(l2.tag == 1276u)) {
        return vader_box_obj(0u, NULL);
    }
    l3 = ((vader_struct_vader_typecheck_TypedProgram_t*) ((vader_struct_vader_effects_WalkCtx_t*) l0)->f_typed)->f_struct_field_types;
    t0 = l2.payload.obj;
    l5 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_types_StructType_t*) t0)->f_symbol)->f_id;
    t1 = std_collections_MutableMap_std_core_Index_at__i32__std_collections_MutableMap_string__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_(l3, l5);
    return t1;
}

static vader_string_t vader_effects_struct_key(void* l0) {
    void* l1 = NULL;
    int64_t l2, l3;
    int32_t t0;
    vader_string_t t1 = 0;
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = (void*) vader_buffer_new((size_t) INT64_C(21));
    l2 = INT64_C(0);
    l2 = std_core_write_string_at(l1, l2, 2350u);
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
    int64_t l5, l6;
    vader_box_t l7 = vader_box_null(), l9 = vader_box_null(), l10 = vader_box_null();
    vader_string_t l8 = 0;
    void* t0 = NULL;
    vader_box_t* gc_roots[3] = { &l7, &l9, &l10 };
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l3, &l4, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l8 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(14u, 0u, 0u, 288u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(12u, 0u, 12u, 286u);
    l3 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(15u, 0u, 7u, 291u);
    l4 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__string__bool_t* _a3_obj = (vader_struct_std_collections_MutableMap__string__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__bool_t));
    vader_obj_header_init(_a3_obj, 458u);
    _a3_obj->f_ekeys = l2;
    _a3_obj->f_evals = l3;
    _a3_obj->f_index = l4;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a3_obj;
    vader_struct_std_collections_MutableSet__string_t* _a4_obj = (vader_struct_std_collections_MutableSet__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__string_t));
    vader_obj_header_init(_a4_obj, 524u);
    _a4_obj->f_inner = t0;
    l2 = (void*) _a4_obj;
    l3 = ((vader_struct_toolchain_ast_StructLitExpr_t*) l1)->f_items;
    l5 = ((vader_array_t*) l3)->length;
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a5_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l6)
        l7 = vader_array_ref_load_box(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l6);
        if (l7.tag == 610u) {
            t0 = l7.payload.obj;
            l8 = ((vader_struct_toolchain_ast_StructLitField_t*) t0)->f_name;
            std_collections_add__string(l2, l8);
            t0 = l7.payload.obj;
            l9 = ((vader_struct_toolchain_ast_StructLitField_t*) t0)->f_value;
            l10 = vader_effects_value(l0, l9);
            t0 = l7.payload.obj;
            l4 = VADER_UNION_FIELD(void*, vader_struct_toolchain_ast_ArrayTypeExpr_t, f_span, ((vader_struct_toolchain_ast_StructLitField_t*) t0)->f_value.payload.obj);
            vader_effects_escape(l0, l10, (uint8_t) 3, l4);
        }
        l6 = (l6 + INT64_C(1));
    }
    l3 = ((vader_struct_toolchain_ast_StructLitExpr_t*) l1)->f_items;
    l5 = ((vader_array_t*) l3)->length;
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a6_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l6)
        l7 = vader_array_ref_load_box(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l6);
        if (l7.tag == 611u) {
            t0 = l7.payload.obj;
            l9 = ((vader_struct_toolchain_ast_StructLitSpread_t*) t0)->f_expr;
            vader_effects_spread(l0, l9, l2);
        }
        l6 = (l6 + INT64_C(1));
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
    int64_t l10, l11, l15, l19;
    int32_t l13;
    void* t0 = NULL;
    void** gc_raw_roots[16] = {
        &l0, &l1, &l2, &l3, &l4, &l5, &l6, &l7, &l8, &l9, &l12, &l14, &l16, &l17, &l18, &t0,
    };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 16u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_typecheck_CheckResult_t*) l1)->f_all_modules;
    l2 = vader_effects_index_functions(l0, l2);
    vader_array_t* _a0_arr = vader_array_new(91u, 0u, 13u, 925u);
    l3 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(89u, 0u, 13u, 923u);
    l4 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(14u, 0u, 0u, 288u);
    l5 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(12u, 0u, 12u, 286u);
    l6 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_new(15u, 0u, 7u, 291u);
    l7 = (void*) _a4_arr;
    vader_struct_std_collections_MutableMap__string__bool_t* _a5_obj = (vader_struct_std_collections_MutableMap__string__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__bool_t));
    vader_obj_header_init(_a5_obj, 458u);
    _a5_obj->f_ekeys = l5;
    _a5_obj->f_evals = l6;
    _a5_obj->f_index = l7;
    _a5_obj->f_mask = INT64_C(0);
    _a5_obj->f_size = INT64_C(0);
    _a5_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a5_obj;
    vader_struct_std_collections_MutableSet__string_t* _a6_obj = (vader_struct_std_collections_MutableSet__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__string_t));
    vader_obj_header_init(_a6_obj, 524u);
    _a6_obj->f_inner = t0;
    l5 = (void*) _a6_obj;
    vader_array_t* _a7_arr = vader_array_new(16u, 0u, 8u, 292u);
    l6 = (void*) _a7_arr;
    vader_array_t* _a8_arr = vader_array_new(12u, 0u, 12u, 286u);
    l7 = (void*) _a8_arr;
    vader_array_t* _a9_arr = vader_array_new(15u, 0u, 7u, 291u);
    l8 = (void*) _a9_arr;
    vader_struct_std_collections_MutableMap__i64__bool_t* _a10_obj = (vader_struct_std_collections_MutableMap__i64__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i64__bool_t));
    vader_obj_header_init(_a10_obj, 427u);
    _a10_obj->f_ekeys = l6;
    _a10_obj->f_evals = l7;
    _a10_obj->f_index = l8;
    _a10_obj->f_mask = INT64_C(0);
    _a10_obj->f_size = INT64_C(0);
    _a10_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a10_obj;
    vader_struct_std_collections_MutableSet__i64_t* _a11_obj = (vader_struct_std_collections_MutableSet__i64_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i64_t));
    vader_obj_header_init(_a11_obj, 523u);
    _a11_obj->f_inner = t0;
    l6 = (void*) _a11_obj;
    vader_array_t* _a12_arr = vader_array_new(15u, 0u, 7u, 291u);
    l7 = (void*) _a12_arr;
    vader_array_t* _a13_arr = vader_array_new(12u, 0u, 12u, 286u);
    l8 = (void*) _a13_arr;
    vader_array_t* _a14_arr = vader_array_new(15u, 0u, 7u, 291u);
    l9 = (void*) _a14_arr;
    vader_struct_std_collections_MutableMap__i32__bool_t* _a15_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
    vader_obj_header_init(_a15_obj, 385u);
    _a15_obj->f_ekeys = l7;
    _a15_obj->f_evals = l8;
    _a15_obj->f_index = l9;
    _a15_obj->f_mask = INT64_C(0);
    _a15_obj->f_size = INT64_C(0);
    _a15_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a15_obj;
    vader_struct_std_collections_MutableSet__i32_t* _a16_obj = (vader_struct_std_collections_MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i32_t));
    vader_obj_header_init(_a16_obj, 522u);
    _a16_obj->f_inner = t0;
    l7 = (void*) _a16_obj;
    vader_struct_vader_typecheck_FreshReads_t* _a17_obj = (vader_struct_vader_typecheck_FreshReads_t*) vader_gc_alloc(sizeof(vader_struct_vader_typecheck_FreshReads_t));
    vader_obj_header_init(_a17_obj, 1221u);
    _a17_obj->f_uses = l6;
    _a17_obj->f_constants = l7;
    l6 = (void*) _a17_obj;
    vader_array_t* _a18_arr = vader_array_new(15u, 0u, 7u, 291u);
    l7 = (void*) _a18_arr;
    vader_array_t* _a19_arr = vader_array_new(21u, 0u, 0u, 299u);
    l8 = (void*) _a19_arr;
    vader_array_t* _a20_arr = vader_array_new(15u, 0u, 7u, 291u);
    l9 = (void*) _a20_arr;
    vader_struct_std_collections_MutableMap__i32__Any___t* _a21_obj = (vader_struct_std_collections_MutableMap__i32__Any___t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__Any___t));
    vader_obj_header_init(_a21_obj, 384u);
    _a21_obj->f_ekeys = l7;
    _a21_obj->f_evals = l8;
    _a21_obj->f_index = l9;
    _a21_obj->f_mask = INT64_C(0);
    _a21_obj->f_size = INT64_C(0);
    _a21_obj->f_tombs = INT64_C(0);
    l7 = (void*) _a21_obj;
    vader_struct_vader_effects_FrozenSites_t* _a22_obj = (vader_struct_vader_effects_FrozenSites_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_FrozenSites_t));
    vader_obj_header_init(_a22_obj, 926u);
    _a22_obj->f_sites = l3;
    _a22_obj->f_bodies = l4;
    _a22_obj->f_written = l5;
    _a22_obj->f_fresh = l6;
    _a22_obj->f_kept_by_constants = l7;
    l3 = (void*) _a22_obj;
    vader_array_t* _a23_arr = vader_array_new(97u, 0u, 13u, 935u);
    l4 = (void*) _a23_arr;
    vader_array_t* _a24_arr = vader_array_new(100u, 0u, 13u, 940u);
    l5 = (void*) _a24_arr;
    l10 = ((vader_array_t*) ((vader_struct_vader_effects_CalleeIndex_t*) l2)->f_functions)->length;
    vader_array_t* _a25_arr = vader_array_repeat((vader_array_t*) l5, (int64_t) l10);
    l5 = (void*) _a25_arr;
    vader_array_t* _a26_arr = vader_array_new(5u, 0u, 13u, 95u);
    l6 = (void*) _a26_arr;
    l10 = ((vader_array_t*) ((vader_struct_vader_effects_CalleeIndex_t*) l2)->f_functions)->length;
    vader_array_t* _a27_arr = vader_array_repeat((vader_array_t*) l6, (int64_t) l10);
    l6 = (void*) _a27_arr;
    vader_array_t* _a28_arr = vader_array_new(2u, 0u, 13u, 15u);
    l7 = (void*) _a28_arr;
    l10 = ((vader_array_t*) ((vader_struct_vader_effects_CalleeIndex_t*) l2)->f_functions)->length;
    vader_array_t* _a29_arr = vader_array_repeat((vader_array_t*) l7, (int64_t) l10);
    l7 = (void*) _a29_arr;
    l10 = INT64_C(0);
    l11 = ((vader_array_t*) ((vader_struct_vader_effects_CalleeIndex_t*) l2)->f_functions)->length;
    while ((l10 < l11)) {
        vader_array_t* _a30_slotarr = ((vader_array_t*) ((vader_struct_vader_effects_CalleeIndex_t*) l2)->f_functions);
        VADER_ARRAY_RESOLVE_BUF(_a30_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a30_slotarr, l10)
        l8 = vader_array_ref_load_obj(_a30_slotarr->buf, _a30_slotarr->offset + (size_t) l10);
        l9 = ((vader_struct_vader_effects_Function_t*) l8)->f_decl;
        l12 = ((vader_struct_vader_effects_Function_t*) l8)->f_typed;
        l13 = ((int32_t) (int64_t) l10);
        l14 = vader_effects_skeleton_of(l9, l12, l2, l3, l4, l13);
        vader_array_push((vader_array_t*) l5, vader_ref_box(l14));
        l15 = ((vader_struct_vader_effects_Skeleton_t*) l14)->f_params;
        l16 = (void*) &vader_fn_static___lambda_vader_effects_0;
        l17 = std_core_filled__vader_effects_ParamEffects(l15, l16);
        vader_array_push((vader_array_t*) l6, vader_ref_box(l17));
        l18 = vader_effects_callee_nodes(l14);
        vader_array_push((vader_array_t*) l7, vader_ref_box(l18));
        l10 = (l10 + INT64_C(1));
    }
    vader_struct_vader_fixpoint_Graph_t* _a31_obj = (vader_struct_vader_fixpoint_Graph_t*) vader_gc_alloc(sizeof(vader_struct_vader_fixpoint_Graph_t));
    vader_obj_header_init(_a31_obj, 945u);
    _a31_obj->f_successors = l7;
    l8 = (void*) _a31_obj;
    l9 = vader_fixpoint_component_of_each_node(l8);
    l10 = ((vader_array_t*) l7)->length;
    l12 = (void*) &vader_fn_static___lambda_vader_effects_1;
    l12 = std_core_filled__i64(l10, l12);
    l10 = ((vader_array_t*) l7)->length;
    l14 = (void*) &vader_fn_static___lambda_vader_effects_2;
    l14 = std_core_filled__i64(l10, l14);
    vader_struct_vader_effects_Clock_t* _a32_obj = (vader_struct_vader_effects_Clock_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_Clock_t));
    vader_obj_header_init(_a32_obj, 915u);
    _a32_obj->f_now = INT64_C(0);
    _a32_obj->f_grew_at = l12;
    _a32_obj->f_evaluated_at = l14;
    t0 = (void*) _a32_obj;
    vader_struct___lambda_env_vader_effects_4_t* _a33_obj = (vader_struct___lambda_env_vader_effects_4_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_effects_4_t));
    vader_obj_header_init(_a33_obj, 329u);
    _a33_obj->f_cap_0 = t0;
    _a33_obj->f_cap_1 = l7;
    _a33_obj->f_cap_2 = l6;
    _a33_obj->f_cap_3 = l2;
    _a33_obj->f_cap_4 = l9;
    _a33_obj->f_cap_5 = l5;
    t0 = (void*) _a33_obj;
    vader_fn_t* _a34_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
    vader_obj_header_init(_a34_closure, 262u);
    _a34_closure->code = (void*) &vader_fn_lift___lambda_vader_effects_3;
    _a34_closure->env = t0;
    l12 = (void*) _a34_closure;
    l8 = vader_fixpoint_solve_bottom_up(l8, l12, INT32_C(64));
    l12 = l8;
    l10 = ((vader_array_t*) l12)->length;
    l11 = INT64_C(0);
    while ((l11 < l10)) {
        vader_array_t* _a35_slotarr = ((vader_array_t*) l12);
        VADER_ARRAY_RESOLVE_BUF(_a35_slotarr)
        l13 = ((int32_t*) _a35_slotarr->buf->slots)[_a35_slotarr->offset + (size_t) l11];
        l15 = INT64_C(0);
        vader_array_t* _a36_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a36_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a36_slotarr, l13)
        t0 = vader_array_ref_load_obj(_a36_slotarr->buf, _a36_slotarr->offset + (size_t) l13);
        l19 = ((vader_array_t*) t0)->length;
        while ((l15 < l19)) {
            vader_array_t* _a37_slotarr = ((vader_array_t*) l6);
            VADER_ARRAY_RESOLVE_BUF(_a37_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a37_slotarr, l13)
            l14 = vader_array_ref_load_obj(_a37_slotarr->buf, _a37_slotarr->offset + (size_t) l13);
            l16 = vader_effects_any_effects();
            vader_array_t* _a38_slotarr = ((vader_array_t*) l14);
            VADER_ARRAY_RESOLVE_BUF(_a38_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a38_slotarr, l15)
            vader_array_ref_store(_a38_slotarr->buf, _a38_slotarr->offset + (size_t) l15, l16);
            VADER_WRITE_BARRIER(_a38_slotarr->buf);
            l15 = (l15 + INT64_C(1));
        }
        l11 = (l11 + INT64_C(1));
    }
    vader_effects_spread_views(l2, l3, l5, l6, l9, l7);
    vader_effects_note_initialisers(l2, l3, l4);
    vader_struct_vader_effects_TraceCtx_t* _a39_obj = (vader_struct_vader_effects_TraceCtx_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_TraceCtx_t));
    vader_obj_header_init(_a39_obj, 942u);
    _a39_obj->f_index = l2;
    _a39_obj->f_skeletons = l5;
    _a39_obj->f_facts = l6;
    l5 = (void*) _a39_obj;
    vader_effects_settle_frozen(l3, l5, l9);
    l5 = ((vader_struct_vader_effects_FrozenSites_t*) l3)->f_sites;
    l3 = ((vader_struct_vader_effects_FrozenSites_t*) l3)->f_fresh;
    l4 = vader_effects_settle_widenings(l4, l6, l2);
    vader_struct_vader_effects_EffectSummary_t* _a40_obj = (vader_struct_vader_effects_EffectSummary_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_EffectSummary_t));
    vader_obj_header_init(_a40_obj, 917u);
    _a40_obj->f_index = l2;
    _a40_obj->f_facts = l6;
    _a40_obj->f_unsettled = l8;
    _a40_obj->f_frozen = l5;
    _a40_obj->f_fresh = l3;
    _a40_obj->f_widenings = l4;
    t0 = (void*) _a40_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_effects_target_of_decl(void* l0, void* l1) {
    void* l2 = NULL;
    int64_t l3;
    vader_box_t l4 = vader_box_null();
    int32_t t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &l4 };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_effects_CalleeIndex_t*) l0)->f_nodes;
    l3 = ((vader_struct_toolchain_ast_FnDecl_t*) l1)->f_id;
    l4 = std_collections_MutableMap_std_core_Index_at__i64__i32(l2, l3);
    if (!(l4.tag == 0u)) {
        t0 = ((int32_t) l4.payload.i);
        vader_struct_vader_effects_CalleeNode_t* _a0_obj = (vader_struct_vader_effects_CalleeNode_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_CalleeNode_t));
        vader_obj_header_init(_a0_obj, 914u);
        _a0_obj->f_node = t0;
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = ((vader_struct_vader_effects_CalleeIndex_t*) l0)->f_bodyless;
    l3 = ((vader_struct_toolchain_ast_FnDecl_t*) l1)->f_id;
    l4 = std_collections_MutableMap_std_core_Index_at__i64__Any(l2, l3);
    if (l4.tag == 0u) {
        vader_struct_vader_effects_AnyCallee_t* _a1_obj = (vader_struct_vader_effects_AnyCallee_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_AnyCallee_t));
        vader_obj_header_init(_a1_obj, 912u);
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
    if (l1.tag == 1209u) {
        l2 = l1.payload.obj;
        l2 = vader_effects_direct_targets(l0, l2);
        { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 1196u) {
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_typecheck_BoundMember_t*) t0)->f_trait_key;
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_typecheck_BoundMember_t*) t0)->f_member;
        l2 = vader_effects_member_targets(l0, l3, l4);
    } else if (l1.tag == 1250u) {
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_typecheck_TraitMember_t*) t0)->f_trait_key;
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_typecheck_TraitMember_t*) t0)->f_member;
        l2 = vader_effects_member_targets(l0, l3, l4);
    } else if (l1.tag == 1211u) {
        t0 = l1.payload.obj;
        l5 = ((vader_struct_vader_typecheck_EachOf_t*) t0)->f_callees;
        l2 = vader_effects_each_targets(l0, l5);
    } else if (l1.tag == 1198u) {
        vader_array_t* _a0_arr = vader_array_new(238u, 0u, 13u, 1666u);
        l2 = (void*) _a0_arr;
    } else {
        if (!((l1.tag == 1214u || l1.tag == 1219u || l1.tag == 1258u))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        vader_struct_vader_effects_AnyCallee_t* _a1_obj = (vader_struct_vader_effects_AnyCallee_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_AnyCallee_t));
        vader_obj_header_init(_a1_obj, 912u);
        t0 = (void*) _a1_obj;
        vader_array_t* _a2_arr = vader_array_new(238u, 1u, 13u, 1666u);
        ((void**) _a2_arr->buf->slots)[_a2_arr->offset + 0u] = t0;
        l2 = (void*) _a2_arr;
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_effects_through(void* l0) {
    int64_t l1;
    vader_string_t l2 = 0;
    int64_t t0;
    void* t1 = NULL;
    vader_string_t t2 = 0;
    void** gc_raw_roots[2] = { &l0, &t1 };
    vader_string_t* gc_atom_roots[2] = { &l2, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) l0)->length;
    if (!((t0 < INT64_C(2)))) {
        l1 = ((vader_array_t*) l0)->length;
        vader_array_t* _a0_arr = vader_array_slice((vader_array_t*) l0, (int64_t) INT64_C(1), (int64_t) l1);
        t1 = (void*) _a0_arr;
        l2 = std_string_join(t1, 313u);
        t2 = concat_2(173u, l2);
        { vader_string_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return 0u; }
}

static void* vader_effects_trace(void* l0, void* l1, int64_t l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void* l7 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    void* l15 = NULL;
    void* l17 = NULL;
    void* l19 = NULL;
    void* l21 = NULL;
    void* l22 = NULL;
    void* l27 = NULL;
    void* l28 = NULL;
    void* l29 = NULL;
    void* l30 = NULL;
    void* l32 = NULL;
    void* l36 = NULL;
    void* l38 = NULL;
    void* l39 = NULL;
    void* l41 = NULL;
    void* l42 = NULL;
    void* l45 = NULL;
    void* l47 = NULL;
    int64_t l5, l8, l12, l18, l20, l23, l43;
    int32_t l6, l31, l40, l46;
    vader_box_t l9 = vader_box_null(), l16 = vader_box_null(), l24 = vader_box_null(), l25 = vader_box_null(), l44 = vader_box_null();
    vader_string_t l26 = 0;
    vader_string_t l33 = 0;
    vader_string_t l34 = 0;
    vader_string_t l35 = 0;
    vader_string_t l37 = 0;
    vader_string_t l48 = 0;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    vader_box_t* gc_roots[5] = { &l9, &l16, &l24, &l25, &l44 };
    void** gc_raw_roots[27] = {
        &l0, &l1, &l3, &l4, &l7, &l10, &l11, &l13, &l14, &l15, &l17, &l19, &l21, &l22, &l27, &l28,
        &l29, &l30, &l32, &l36, &l38, &l39, &l41, &l42, &l45, &l47, &t0,
    };
    vader_string_t* gc_atom_roots[7] = { &l26, &l33, &l34, &l35, &l37, &l48, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 5u, 27u, gc_roots, gc_raw_roots, 0u, NULL, 7u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(87u, 0u, 13u, 920u);
    t0 = (void*) _a0_arr;
    vader_struct_vader_effects_FaultChain_t* _a1_obj = (vader_struct_vader_effects_FaultChain_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_FaultChain_t));
    vader_obj_header_init(_a1_obj, 919u);
    _a1_obj->f_via = t0;
    _a1_obj->f_write = vader_box_obj(0u, NULL);
    l3 = (void*) _a1_obj;
    l4 = l1;
    l5 = l2;
    l6 = INT32_C(0);
    for (;;) {
        if ((l6 < INT32_C(4096))) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_effects_ParamEffects_t*) ((vader_struct_vader_effects_Link_t*) l4)->f_effects)->f_accesses);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l5)
            l7 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l5);
            l8 = vader_effects_constraint_at(((vader_struct_vader_effects_Link_t*) l4)->f_effects, l5);
            l9 = vader_effects_origin_mark(l8);
            if (!(l9.tag == 0u)) {
                l10 = ((vader_struct_vader_effects_CalleeIndex_t*) ((vader_struct_vader_effects_TraceCtx_t*) l0)->f_index)->f_paths;
                l11 = ((vader_struct_vader_effects_Skeleton_t*) ((vader_struct_vader_effects_Link_t*) l4)->f_s)->f_marks;
                l12 = ((int64_t) l9.payload.i);
                vader_array_t* _a3_slotarr = ((vader_array_t*) l11);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l12)
                t0 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l12);
                l13 = ((vader_struct_vader_effects_Mark_t*) t0)->f_at;
                l14 = vader_effects_written_by(l10, l4, l7, l13, vader_box_obj(0u, NULL));
                ((vader_struct_vader_effects_FaultChain_t*) l3)->f_write = vader_ref_box(l14);
                VADER_WRITE_BARRIER((vader_struct_vader_effects_FaultChain_t*) l3);
                { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
            }
            l16 = vader_effects_origin_call(l8);
            if (l16.tag == 0u) {
                { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
            }
            l15 = l16.payload.obj;
            l17 = ((vader_struct_vader_effects_Skeleton_t*) ((vader_struct_vader_effects_Link_t*) l4)->f_s)->f_sites;
            l18 = ((vader_struct___Tuple_i64_i64_i64_2cc25dbf_t*) l15)->f__0;
            vader_array_t* _a4_slotarr = ((vader_array_t*) l17);
            VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l18)
            l19 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l18);
            l20 = ((vader_struct___Tuple_i64_i64_i64_2cc25dbf_t*) l15)->f__2;
            l22 = ((vader_struct_vader_effects_Site_t*) l19)->f_targets;
            l23 = ((vader_struct___Tuple_i64_i64_i64_2cc25dbf_t*) l15)->f__1;
            vader_array_t* _a5_slotarr = ((vader_array_t*) l22);
            VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l23)
            l24 = vader_array_ref_load_box(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l23);
            l25 = l24;
            if (l24.tag == 914u) {
                l21 = l25.payload.obj;
                l30 = ((vader_struct_vader_effects_CalleeIndex_t*) ((vader_struct_vader_effects_TraceCtx_t*) l0)->f_index)->f_functions;
                l31 = ((vader_struct_vader_effects_CalleeNode_t*) l21)->f_node;
                vader_array_t* _a6_slotarr = ((vader_array_t*) l30);
                VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l31)
                l32 = vader_array_ref_load_obj(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l31);
                vader_array_t* _a7_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_FnDecl_t*) ((vader_struct_vader_effects_Function_t*) l32)->f_decl)->f_params);
                VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l20)
                t0 = vader_array_ref_load_obj(_a7_slotarr->buf, _a7_slotarr->offset + (size_t) l20);
                l33 = ((vader_struct_toolchain_ast_FnParam_t*) t0)->f_name;
                l34 = ((vader_struct_toolchain_ast_FnDecl_t*) ((vader_struct_vader_effects_Function_t*) l32)->f_decl)->f_name;
                l35 = concat_3(924u, l34, 924u);
                l36 = ((vader_struct_vader_effects_Site_t*) l19)->f_at;
                l37 = ((vader_struct_vader_effects_Link_t*) l4)->f_module;
                vader_struct_vader_effects_FaultHop_t* _a8_obj = (vader_struct_vader_effects_FaultHop_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_FaultHop_t));
                vader_obj_header_init(_a8_obj, 920u);
                _a8_obj->f_callee = l35;
                _a8_obj->f_param = l33;
                _a8_obj->f_span = l36;
                _a8_obj->f_module = l37;
                l38 = (void*) _a8_obj;
                vader_array_push((vader_array_t*) ((vader_struct_vader_effects_FaultChain_t*) l3)->f_via, vader_ref_box(l38));
                l39 = ((vader_struct_vader_effects_TraceCtx_t*) l0)->f_facts;
                l40 = ((vader_struct_vader_effects_CalleeNode_t*) l21)->f_node;
                vader_array_t* _a9_slotarr = ((vader_array_t*) l39);
                VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l40)
                t0 = vader_array_ref_load_obj(_a9_slotarr->buf, _a9_slotarr->offset + (size_t) l40);
                vader_array_t* _a10_slotarr = ((vader_array_t*) t0);
                VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a10_slotarr, l20)
                l41 = vader_array_ref_load_obj(_a10_slotarr->buf, _a10_slotarr->offset + (size_t) l20);
                l42 = ((vader_struct_vader_effects_CalleeIndex_t*) ((vader_struct_vader_effects_TraceCtx_t*) l0)->f_index)->f_paths;
                l43 = vader_effects_carried_at(((vader_struct_vader_effects_Link_t*) l4)->f_effects, l5);
                l44 = vader_effects_find_access(l42, l41, l43);
                if (l44.tag == 0u) {
                    { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
                }
                l5 = ((int64_t) l44.payload.i);
                l45 = ((vader_struct_vader_effects_TraceCtx_t*) l0)->f_skeletons;
                l46 = ((vader_struct_vader_effects_CalleeNode_t*) l21)->f_node;
                vader_array_t* _a11_slotarr = ((vader_array_t*) l45);
                VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l46)
                l47 = vader_array_ref_load_obj(_a11_slotarr->buf, _a11_slotarr->offset + (size_t) l46);
                l48 = ((vader_struct_vader_resolver_ResolvedModule_t*) ((vader_struct_vader_typecheck_TypedProgram_t*) ((vader_struct_vader_effects_Function_t*) l32)->f_typed)->f_resolved)->f_display_path;
                vader_struct_vader_effects_Link_t* _a12_obj = (vader_struct_vader_effects_Link_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_Link_t));
                vader_obj_header_init(_a12_obj, 930u);
                _a12_obj->f_s = l47;
                _a12_obj->f_module = l48;
                _a12_obj->f_effects = l41;
                _a12_obj->f_name = l33;
                l4 = (void*) _a12_obj;
                l6 = (l6 + INT32_C(1));
                continue;
            }
            if (l24.tag == 929u) {
                l26 = vader_effects_display_callee(((vader_struct_vader_effects_Site_t*) l19)->f_callee);
                l27 = ((vader_struct_vader_effects_CalleeIndex_t*) ((vader_struct_vader_effects_TraceCtx_t*) l0)->f_index)->f_paths;
                l28 = ((vader_struct_vader_effects_Site_t*) l19)->f_at;
                l29 = vader_effects_written_by(l27, l4, l7, l28, vader_box_string(288u, l26));
                ((vader_struct_vader_effects_FaultChain_t*) l3)->f_write = vader_ref_box(l29);
                VADER_WRITE_BARRIER((vader_struct_vader_effects_FaultChain_t*) l3);
                { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
            }
            if (!(l24.tag == 912u)) {
                vader_unreachable("non-exhaustive match (T3013 should have caught this)");
            }
            { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
        }
        break;
    }
    l3 = (void*) vader_buffer_new((size_t) INT64_C(83));
    l5 = INT64_C(0);
    l5 = std_core_write_string_at(l3, l5, 1697u);
    l5 = std_core_write_int(l3, l5, INT64_C(4096));
    l5 = std_core_write_string_at(l3, l5, 79u);
    t1 = std_core_finish_buffer(l3, l5);
    vader_host_std_abort_panic(t1);
    vader_unreachable("a no-return call returned");
    vader_gc_top = gc_frame.prev;
}

static vader_box_t vader_effects_type_below(void* l0, void* l1, vader_box_t l2, int32_t l3) {
    vader_box_t l4 = vader_box_null(), l10 = vader_box_null();
    void* l5 = NULL;
    int64_t l6, l7;
    int32_t l8;
    vader_string_t l9 = 0;
    vader_box_t t0 = vader_box_null();
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
    l7 = INT64_C(0);
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
        l7 = (l7 + INT64_C(1));
    }
    { vader_box_t __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_effects_union_of(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l9 = vader_box_null();
    int32_t l3;
    bool l4;
    void* l5 = NULL;
    int64_t l6, l7, l8, l10;
    bool t0;
    vader_box_t* gc_roots[2] = { &l2, &l9 };
    void** gc_raw_roots[3] = { &l0, &l1, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = vader_box_obj(0u, NULL);
    l3 = INT32_C(0);
    l4 = true;
    l5 = l1;
    l6 = ((vader_array_t*) l5)->length;
    l7 = INT64_C(0);
    while ((l7 < l6)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l9 = vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l7];
        if (l9.tag == 0u) {
            l7 = (l7 + INT64_C(1));
            continue;
        }
        l8 = ((int64_t) l9.payload.i);
        if (l2.tag == 0u) {
            l2 = vader_box_i64(292u, l8);
        }
        l3 = vader_chk_add(i32, l3, INT32_C(1));
        t0 = std_collections_MutableSet_std_core_Contains_contains__i64(((vader_struct_vader_effects_WalkCtx_t*) l0)->f_pure, l8);
        if (!(t0)) {
            l4 = false;
        }
        l7 = (l7 + INT64_C(1));
    }
    if ((l3 < INT32_C(2))) {
        { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l6 = vader_effects_fresh_slot(((vader_struct_vader_effects_WalkCtx_t*) l0)->f_s);
    l5 = l1;
    l7 = ((vader_array_t*) l5)->length;
    l8 = INT64_C(0);
    while ((l8 < l7)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l2 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l8];
        if (l2.tag == 0u) {
            l8 = (l8 + INT64_C(1));
            continue;
        }
        l10 = ((int64_t) l2.payload.i);
        vader_effects_add_flow(((vader_struct_vader_effects_WalkCtx_t*) l0)->f_s, l6, l10, INT32_C(0));
        l8 = (l8 + INT64_C(1));
    }
    if (l4) {
        std_collections_add__i64(((vader_struct_vader_effects_WalkCtx_t*) l0)->f_pure, l6);
        { vader_box_t __vret = vader_box_i64(292u, l6); vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_box_t __vret = vader_box_i64(292u, l6); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_effects_use_outcome(void* l0, void* l1) {
    void* l2 = NULL;
    vader_box_t l3 = vader_box_null();
    uint8_t t0;
    bool t1;
    vader_box_t* gc_roots[1] = { &l3 };
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = (void*) &vader_fn_static_vader_effects_modifies;
    l3 = vader_effects_fault_of(l1, l2);
    if (!(l3.tag == 0u)) {
        t0 = ((uint8_t) l3.payload.i);
        { vader_box_t __vret = vader_box_i32(293u, (int32_t)(uint32_t) t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = (void*) &vader_fn_static_vader_effects_is_unknown;
    t1 = vader_effects_either(l1, l2);
    if (t1) {
        { vader_box_t __vret = vader_box_i32(293u, INT32_C(2)); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (((vader_struct_vader_effects_FrozenBody_t*) ((vader_struct_vader_effects_RootCase_t*) l1)->f_body)->f_initialises.tag == 0u) {
        l2 = (void*) &vader_fn_static_vader_effects_is_kept;
        t1 = vader_effects_either(l1, l2);
        if (t1) {
            l2 = (void*) &vader_fn_static_vader_effects_is_kept;
            t0 = vader_effects_copy_or_elided(l0, l1, l2);
            { vader_box_t __vret = vader_box_i32(293u, (int32_t)(uint32_t) t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static vader_box_t vader_effects_value(void* l0, vader_box_t l1) {
    vader_box_t l2 = vader_box_null();
    void* l3 = NULL;
    int64_t l4;
    vader_box_t t0 = vader_box_null();
    bool t1;
    vader_box_t* gc_roots[3] = { &l1, &l2, &t0 };
    void** gc_raw_roots[2] = { &l0, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = vader_effects_value_of(l0, l1);
    l2 = vader_effects_converted(l0, l1, l2);
    l3 = ((vader_struct_vader_typecheck_TypedProgram_t*) ((vader_struct_vader_effects_WalkCtx_t*) l0)->f_typed)->f_expr_types;
    l4 = VADER_UNION_FIELD(int64_t, vader_struct_toolchain_ast_ArrayTypeExpr_t, f_id, l1.payload.obj);
    t0 = std_collections_MutableMap_std_core_Index_at__i64__Any(l3, l4);
    t1 = vader_effects_holds_references(t0);
    if (!(t1)) {
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
    if (l1.tag == 569u) {
        l3 = l1.payload.obj;
        l2 = vader_effects_ident_value(l0, l3);
        { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 562u) {
        l3 = l1.payload.obj;
        l2 = vader_effects_field_value(l0, l3);
    } else if (l1.tag == 577u) {
        l3 = l1.payload.obj;
        l2 = vader_effects_index_value(l0, l3);
    } else if (l1.tag == 544u) {
        l3 = l1.payload.obj;
        l2 = vader_effects_call_value(l0, l3);
    } else if (l1.tag == 539u) {
        l3 = l1.payload.obj;
        l2 = vader_effects_binary_value(l0, l3);
    } else if (l1.tag == 618u) {
        t0 = l1.payload.obj;
        l4 = ((vader_struct_toolchain_ast_UnaryExpr_t*) t0)->f_operand;
        l2 = vader_effects_nothing(l0, l4);
    } else if (l1.tag == 590u) {
        t0 = l1.payload.obj;
        l4 = ((vader_struct_toolchain_ast_NullCoalesceExpr_t*) t0)->f_left;
        l4 = vader_effects_value(l0, l4);
        t0 = l1.payload.obj;
        l5 = ((vader_struct_toolchain_ast_NullCoalesceExpr_t*) t0)->f_fallback;
        l5 = vader_effects_fallback_value(l0, l5);
        vader_array_t* _a0_arr = vader_array_new(214u, 2u, 0u, 1414u);
        vader_array_box_slots(_a0_arr->buf)[_a0_arr->offset + 1u] = l5;
        vader_array_box_slots(_a0_arr->buf)[_a0_arr->offset + 0u] = l4;
        l3 = (void*) _a0_arr;
        l2 = vader_effects_one_of(l0, l3);
    } else if (l1.tag == 572u) {
        l3 = l1.payload.obj;
        l2 = vader_effects_if_value(l0, l3);
    } else if (l1.tag == 586u) {
        l3 = l1.payload.obj;
        l2 = vader_effects_match_value(l0, l3);
    } else if (l1.tag == 540u) {
        l3 = l1.payload.obj;
        l2 = vader_effects_block_value(l0, l3);
    } else if (l1.tag == 582u) {
        l3 = l1.payload.obj;
        l2 = vader_effects_lambda_value(l0, l3);
    } else if (l1.tag == 609u) {
        l3 = l1.payload.obj;
        l2 = vader_effects_struct_literal_value(l0, l3);
    } else if (l1.tag == 602u) {
        l3 = l1.payload.obj;
        l2 = vader_effects_sequence_value(l0, l3);
    } else if (l1.tag == 597u) {
        l3 = l1.payload.obj;
        l2 = vader_effects_range_value(l0, l3);
    } else if (l1.tag == 545u) {
        t0 = l1.payload.obj;
        l4 = ((vader_struct_toolchain_ast_CastExpr_t*) t0)->f_value;
        l2 = vader_effects_value(l0, l4);
    } else if (l1.tag == 604u) {
        l3 = l1.payload.obj;
        l2 = vader_effects_string_value(l0, l3);
    } else if (l1.tag == 580u) {
        l3 = l1.payload.obj;
        l2 = vader_effects_intrinsic_value(l0, l3);
    } else if (l1.tag == 538u) {
        t0 = l1.payload.obj;
        l4 = ((vader_struct_toolchain_ast_AwaitExpr_t*) t0)->f_inner;
        l2 = vader_effects_nothing(l0, l4);
    } else {
        if (!((l1.tag == 535u || l1.tag == 541u || l1.tag == 546u || l1.tag == 557u || l1.tag == 563u || l1.tag == 566u || l1.tag == 568u || l1.tag == 579u || l1.tag == 591u))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l2 = vader_box_obj(0u, NULL);
    }
    { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static int64_t vader_effects_variant_data_use(void* l0, void* l1, void* l2) {
    int64_t l3;
    int32_t l4;
    void* l5 = NULL;
    vader_string_t l6 = 0;
    vader_string_t t0 = 0;
    int64_t t1;
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &l5 };
    vader_string_t* gc_atom_roots[2] = { &l6, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_toolchain_ast_CallExpr_t*) l1)->f_id;
    l4 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_types_StructType_t*) l2)->f_symbol)->f_id;
    vader_struct_vader_effects_ConstantUse_t* _a0_obj = (vader_struct_vader_effects_ConstantUse_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_ConstantUse_t));
    vader_obj_header_init(_a0_obj, 916u);
    _a0_obj->f_node = l3;
    _a0_obj->f_symbol = l4;
    l5 = (void*) _a0_obj;
    t0 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_types_StructType_t*) l2)->f_symbol)->f_name;
    l6 = concat_2(t0, 274u);
    t1 = vader_effects_frozen_source(l0, vader_ref_box(l1), l6, (uint8_t) 2, vader_ref_box(l5));
    { int64_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_effects_view_label(vader_box_t l0) {
    vader_string_t l1 = 0;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[1] = { &t0 };
    vader_string_t* gc_atom_roots[2] = { &l1, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l0.tag == 1209u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_toolchain_ast_FnDecl_t*) ((vader_struct_vader_typecheck_DirectFn_t*) t0)->f_decl)->f_name;
        l1 = concat_2(t1, 265u);
        { vader_string_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if ((l0.tag == 1196u || l0.tag == 1250u)) {
        t1 = VADER_UNION_FIELD(vader_string_t, vader_struct_vader_typecheck_BoundMember_t, f_member, l0.payload.obj);
        l1 = concat_2(t1, 265u);
    } else {
        if (!((l0.tag == 1198u || l0.tag == 1211u || l0.tag == 1214u || l0.tag == 1219u || l0.tag == 1258u))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = 1306u;
    }
    { vader_string_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_effects_view_outcome(void* l0) {
    void* l1 = NULL;
    vader_box_t l2 = vader_box_null();
    void* t0 = NULL;
    uint8_t t1;
    bool t2;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[3] = { &l0, &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct___lambda_env_vader_effects_26_t* _a0_obj = (vader_struct___lambda_env_vader_effects_26_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_effects_26_t));
    vader_obj_header_init(_a0_obj, 322u);
    _a0_obj->f_cap_0 = l0;
    t0 = (void*) _a0_obj;
    vader_fn_t* _a1_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
    vader_obj_header_init(_a1_closure, 273u);
    _a1_closure->code = (void*) &vader_fn_lift___lambda_vader_effects_25;
    _a1_closure->env = t0;
    l1 = (void*) _a1_closure;
    l2 = vader_effects_fault_of(l0, l1);
    if (!(l2.tag == 0u)) {
        t1 = ((uint8_t) l2.payload.i);
        { vader_box_t __vret = vader_box_i32(293u, (int32_t)(uint32_t) t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l1 = (void*) &vader_fn_static___lambda_vader_effects_27;
    t2 = vader_effects_either(l0, l1);
    if (t2) {
        { vader_box_t __vret = vader_box_i32(293u, INT32_C(7)); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = vader_effects_returns_it(l0);
    if (!(t2)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    { vader_box_t __vret = vader_box_i32(293u, INT32_C(8)); vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_effects_view_returners(void* l0, void* l1, void* l2, void* l3) {
    void* l4 = NULL;
    void* l5 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l11 = NULL;
    void* l15 = NULL;
    void* l16 = NULL;
    void* l17 = NULL;
    void* l20 = NULL;
    void* l21 = NULL;
    void* l22 = NULL;
    int64_t l6, l7, l13, l14, l18, l19;
    int32_t l10, l24;
    bool l12;
    vader_box_t l23 = vader_box_null();
    int32_t t0;
    bool t1;
    void* t2 = NULL;
    vader_box_t* gc_roots[1] = { &l23 };
    void** gc_raw_roots[16] = {
        &l0, &l1, &l2, &l3, &l4, &l5, &l8, &l9, &l11, &l15, &l16, &l17, &l20, &l21, &l22, &t2,
    };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 16u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(15u, 0u, 7u, 291u);
    l4 = (void*) _a0_arr;
    l5 = ((vader_struct_vader_effects_FrozenSites_t*) l1)->f_bodies;
    l6 = ((vader_array_t*) l5)->length;
    l7 = INT64_C(0);
    while ((l7 < l6)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l7)
        l8 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l7);
        t0 = ((vader_struct_vader_effects_FrozenBody_t*) l8)->f_node;
        if (!((t0 < INT32_C(0)))) {
            l9 = ((vader_struct_vader_effects_CalleeIndex_t*) l0)->f_view_nodes;
            l10 = ((vader_struct_vader_effects_FrozenBody_t*) l8)->f_node;
            t1 = std_collections_MutableSet_std_core_Contains_contains__i32(l9, l10);
            if (!(t1)) {
                l11 = ((vader_struct_vader_effects_FrozenBody_t*) l8)->f_roots;
                l12 = false;
                l13 = ((vader_array_t*) l11)->length;
                l14 = INT64_C(0);
                {
                    while ((l14 < l13)) {
                        vader_array_t* _a2_slotarr = ((vader_array_t*) l11);
                        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                        t2 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l14);
                        t1 = vader_effects_is_view(t2);
                        if (t1) {
                            l12 = true;
                            goto end_42;
                        }
                        l14 = (l14 + INT64_C(1));
                    }
                    l12 = false;
                } end_42: ;
                if (l12) {
                    l15 = vader_effects_body_ctx(l8, l2, l0, l3);
                    l16 = vader_effects_evaluate_roots(((vader_struct_vader_effects_FrozenBody_t*) l8)->f_skeleton, l15);
                    l17 = ((vader_struct_vader_effects_FrozenBody_t*) l8)->f_roots;
                    l18 = ((vader_array_t*) l17)->length;
                    l19 = INT64_C(0);
                    while ((l19 < l18)) {
                        vader_array_t* _a3_slotarr = ((vader_array_t*) l17);
                        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                        l20 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l19);
                        l22 = ((vader_struct_vader_effects_CalleeIndex_t*) l0)->f_paths;
                        l23 = vader_effects_root_case(l8, l20, l16, l22);
                        if (l23.tag == 0u) {
                            l19 = (l19 + INT64_C(1));
                            continue;
                        }
                        l21 = l23.payload.obj;
                        t1 = vader_effects_holds_view(l21);
                        if (t1) {
                            t1 = vader_effects_returns_it(l21);
                            if (t1) {
                                l24 = ((vader_struct_vader_effects_FrozenBody_t*) l8)->f_node;
                                vader_array_push_i32((vader_array_t*) l4, l24);
                                break;
                            }
                        }
                        l19 = (l19 + INT64_C(1));
                    }
                    l7 = (l7 + INT64_C(1));
                    continue;
                }
            }
        }
        l7 = (l7 + INT64_C(1));
    }
    { void* __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_effects_what_it_may_do(uint8_t l0, vader_string_t l1) {
    vader_string_t l2 = 0;
    vader_string_t* gc_atom_roots[2] = { &l1, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    if (l0 == INT32_C(0)) {
        l2 = concat_2(2134u, l1);
        { vader_string_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(1)) {
        l2 = concat_2(2135u, l1);
    } else if (l0 == INT32_C(3)) {
        l2 = concat_2(2137u, l1);
    } else if (l0 == INT32_C(4)) {
        l2 = concat_2(2138u, l1);
    } else if (l0 == INT32_C(5)) {
        l2 = concat_3(2136u, l1, 176u);
    } else {
        if (!(l0 == INT32_C(2))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l2 = concat_2(2139u, l1);
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
        t0 = concat_2(l2, 133u);
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
    int64_t l6, l7, l8, l13, l14, l15;
    vader_string_t l10 = 0;
    void* t0 = NULL;
    bool t1;
    void** gc_raw_roots[13] = {
        &l0, &l1, &l2, &l3, &l4, &l5, &l9, &l11, &l12, &l16, &l17, &l18, &t0,
    };
    vader_string_t* gc_atom_roots[1] = { &l10 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 13u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(84u, 0u, 13u, 910u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(16u, 0u, 8u, 292u);
    l3 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(12u, 0u, 12u, 286u);
    l4 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(15u, 0u, 7u, 291u);
    l5 = (void*) _a3_arr;
    vader_struct_std_collections_MutableMap__i64__bool_t* _a4_obj = (vader_struct_std_collections_MutableMap__i64__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i64__bool_t));
    vader_obj_header_init(_a4_obj, 427u);
    _a4_obj->f_ekeys = l3;
    _a4_obj->f_evals = l4;
    _a4_obj->f_index = l5;
    _a4_obj->f_mask = INT64_C(0);
    _a4_obj->f_size = INT64_C(0);
    _a4_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a4_obj;
    vader_struct_std_collections_MutableSet__i64_t* _a5_obj = (vader_struct_std_collections_MutableSet__i64_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i64_t));
    vader_obj_header_init(_a5_obj, 523u);
    _a5_obj->f_inner = t0;
    l3 = (void*) _a5_obj;
    l4 = ((vader_struct_vader_effects_EffectSummary_t*) l0)->f_widenings;
    l6 = ((vader_array_t*) l4)->length;
    l7 = INT64_C(0);
    while ((l7 < l6)) {
        vader_array_t* _a6_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        l5 = vader_array_ref_load_obj(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l7);
        l8 = ((vader_struct_vader_effects_WideningSite_t*) l5)->f_arg;
        std_collections_add__i64(l3, l8);
        if (((vader_struct_vader_effects_WideningSite_t*) l5)->f_verdict != INT32_C(0)) {
            l9 = ((vader_struct_vader_effects_CalleeIndex_t*) ((vader_struct_vader_effects_EffectSummary_t*) l0)->f_index)->f_paths;
            l10 = vader_effects_widening_detail(l5, l9);
            l11 = ((vader_struct_vader_effects_WideningSite_t*) l5)->f_span;
            l12 = vader_diagnostics_typecheck_error((uint8_t) 85, l11, l10);
            vader_array_push((vader_array_t*) l2, vader_ref_box(l12));
        }
        l7 = (l7 + INT64_C(1));
    }
    l4 = std_collections_values__string__vader_typecheck_TypedProgram(((vader_struct_vader_typecheck_CheckResult_t*) l1)->f_all_modules);
    l6 = ((vader_array_t*) l4)->length;
    l7 = INT64_C(0);
    while ((l7 < l6)) {
        vader_array_t* _a7_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
        t0 = vader_array_ref_load_obj(_a7_slotarr->buf, _a7_slotarr->offset + (size_t) l7);
        l5 = ((vader_struct_vader_typecheck_TypedProgram_t*) t0)->f_widened_arguments;
        l9 = ((vader_struct_std_collections_MutableMap__i64__vader_typecheck_WidenedArgument_t*) l5)->f_ekeys;
        l11 = ((vader_struct_std_collections_MutableMap__i64__vader_typecheck_WidenedArgument_t*) l5)->f_evals;
        l8 = INT64_C(0);
        l13 = ((vader_struct_std_collections_MutableMap__i64__vader_typecheck_WidenedArgument_t*) l5)->f_size;
        while ((l8 < l13)) {
            vader_array_t* _a8_slotarr = ((vader_array_t*) l9);
            VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l8)
            l14 = ((int64_t*) _a8_slotarr->buf->slots)[_a8_slotarr->offset + (size_t) l8];
            vader_array_t* _a9_slotarr = ((vader_array_t*) l11);
            VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l8)
            l12 = vader_array_ref_load_obj(_a9_slotarr->buf, _a9_slotarr->offset + (size_t) l8);
            l15 = l14;
            l16 = l12;
            t1 = std_collections_MutableSet_std_core_Contains_contains__i64(l3, l15);
            if (!(t1)) {
                l17 = ((vader_struct_vader_typecheck_WidenedArgument_t*) l16)->f_span;
                l18 = vader_diagnostics_typecheck_error((uint8_t) 85, l17, 2213u);
                vader_array_push((vader_array_t*) l2, vader_ref_box(l18));
            }
            l8 = (l8 + INT64_C(1));
        }
        l7 = (l7 + INT64_C(1));
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
    int64_t l5, l6, l9, l14, l17, l19, l20, l24, l29;
    vader_box_t l7 = vader_box_null(), l13 = vader_box_null(), l15 = vader_box_null(), l16 = vader_box_null(), l28 = vader_box_null();
    vader_string_t l11 = 0;
    vader_string_t l26 = 0;
    int32_t l12, l22, l27;
    void* t0 = NULL;
    bool t1;
    vader_box_t* gc_roots[5] = { &l7, &l13, &l15, &l16, &l28 };
    void** gc_raw_roots[12] = { &l0, &l1, &l2, &l3, &l4, &l8, &l10, &l18, &l21, &l23, &l25, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l11, &l26 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 5u, 12u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = ((vader_struct_vader_effects_PendingWidening_t*) l0)->f_targets;
    l5 = ((vader_array_t*) l4)->length;
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l7 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l6);
        if (l7.tag == 912u) {
            l8 = ((vader_struct_vader_effects_PendingWidening_t*) l0)->f_site;
            l9 = ((vader_struct_vader_effects_WideningSite_t*) l8)->f_arg;
            l10 = ((vader_struct_vader_effects_WideningSite_t*) l8)->f_span;
            l11 = ((vader_struct_vader_effects_WideningSite_t*) l8)->f_module;
            l12 = ((vader_struct_vader_effects_WideningSite_t*) l8)->f_depth;
            l13 = ((vader_struct_vader_effects_WideningSite_t*) l8)->f_callee;
            l14 = ((vader_struct_vader_effects_WideningSite_t*) l8)->f_param;
            l15 = ((vader_struct_vader_effects_WideningSite_t*) l8)->f_breaking;
            vader_struct_vader_effects_WideningSite_t* _a1_obj = (vader_struct_vader_effects_WideningSite_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_WideningSite_t));
            vader_obj_header_init(_a1_obj, 944u);
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
        l20 = INT64_C(0);
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
                vader_obj_header_init(_a3_obj, 944u);
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
            l20 = (l20 + INT64_C(1));
        }
        l6 = (l6 + INT64_C(1));
    }
    { void* __vret = ((vader_struct_vader_effects_PendingWidening_t*) l0)->f_site; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_effects_write_phrase(vader_box_t l0) {
    vader_string_t l1 = 0;
    vader_string_t l3 = 0;
    uint8_t l2;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[1] = { &t0 };
    vader_string_t* gc_atom_roots[2] = { &l1, &l3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l0.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return 2047u; }
    }
    t0 = l0.payload.obj;
    l1 = ((vader_struct_vader_effects_FaultWrite_t*) t0)->f_place;
    l1 = concat_3(924u, l1, 924u);
    t0 = l0.payload.obj;
    l2 = ((vader_struct_vader_effects_FaultWrite_t*) t0)->f_effect;
    if (l2 == INT32_C(0)) {
        l3 = concat_2(l1, 113u);
        { vader_string_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l2 == INT32_C(1)) {
        l3 = concat_2(l1, 98u);
    } else if (l2 == INT32_C(2)) {
        l3 = concat_2(l1, 164u);
    } else if (l2 == INT32_C(3)) {
        l3 = concat_2(l1, 115u);
    } else if (l2 == INT32_C(4)) {
        l3 = concat_2(l1, 125u);
    } else {
        if (!(l2 == INT32_C(5))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l3 = concat_2(l1, 114u);
    }
    { vader_string_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
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
    vader_array_t* _a0_arr = vader_array_new(95u, 3u, 13u, 932u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 2u] = l3;
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 1u] = l2;
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = l1;
    t0 = (void*) _a0_arr;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

bool vader_effects_writes_view(void* l0, void* l1) {
    bool t0;
    t0 = vader_effects_modifies(l1);
    if (t0) {
        t0 = vader_effects_reaches_view(l0, l1);
        return t0;
    }
    return false;
}

bool vader_effects_written_at(void* l0, void* l1, void* l2, void* l3) {
    void* l4 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    int64_t l5;
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
    vader_array_t* _a0_arr = vader_array_new(15u, 0u, 7u, 291u);
    l4 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(12u, 0u, 12u, 286u);
    l6 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(15u, 0u, 7u, 291u);
    l7 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__i32__bool_t* _a3_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
    vader_obj_header_init(_a3_obj, 385u);
    _a3_obj->f_ekeys = l4;
    _a3_obj->f_evals = l6;
    _a3_obj->f_index = l7;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a3_obj;
    vader_struct_std_collections_MutableSet__i32_t* _a4_obj = (vader_struct_std_collections_MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i32_t));
    vader_obj_header_init(_a4_obj, 522u);
    _a4_obj->f_inner = t0;
    l4 = (void*) _a4_obj;
    l6 = ((vader_struct_vader_effects_FrozenSites_t*) l0)->f_written;
    l7 = ((vader_struct_vader_effects_FrozenBody_t*) ((vader_struct_vader_effects_RootCase_t*) l1)->f_body)->f_typed;
    t1 = vader_effects_may_be_written(l6, l8, l7, l4);
    { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_effects_written_by(void* l0, void* l1, void* l2, void* l3, vader_box_t l4) {
    uint8_t l5;
    vader_string_t l6 = 0;
    vader_string_t l8 = 0;
    int32_t l7;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l4 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l6, &l8 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l5 = ((vader_struct_vader_effects_Access_t*) l2)->f_effect;
    l6 = ((vader_struct_vader_effects_Link_t*) l1)->f_name;
    l7 = ((vader_struct_vader_effects_Access_t*) l2)->f_path;
    l6 = vader_effects_place_label(l0, l6, l7);
    l8 = ((vader_struct_vader_effects_Link_t*) l1)->f_module;
    vader_struct_vader_effects_FaultWrite_t* _a0_obj = (vader_struct_vader_effects_FaultWrite_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_FaultWrite_t));
    vader_obj_header_init(_a0_obj, 921u);
    _a0_obj->f_effect = l5;
    _a0_obj->f_place = l6;
    _a0_obj->f_by = l4;
    _a0_obj->f_span = l3;
    _a0_obj->f_module = l8;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_effects_written_keys(vader_box_t l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l6 = NULL;
    int64_t l4, l5, l7, l8;
    vader_string_t l9 = 0;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l0, &t2 };
    void** gc_raw_roots[5] = { &l1, &l2, &l3, &l6, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l9, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l0.tag == 1276u) {
        t0 = l0.payload.obj;
        t1 = vader_effects_struct_key(t0);
        vader_array_t* _a0_arr = vader_array_new(14u, 1u, 0u, 288u);
        vader_array_box_slots(_a0_arr->buf)[_a0_arr->offset + 0u] = vader_box_string(288u, t1);
        l1 = (void*) _a0_arr;
        { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1263u) {
        vader_array_t* _a1_arr = vader_array_new(14u, 1u, 0u, 288u);
        vader_array_box_slots(_a1_arr->buf)[_a1_arr->offset + 0u] = vader_box_string(288u, 1417u);
        l1 = (void*) _a1_arr;
    } else if (l0.tag == 1278u) {
        vader_array_t* _a2_arr = vader_array_new(14u, 1u, 0u, 288u);
        vader_array_box_slots(_a2_arr->buf)[_a2_arr->offset + 0u] = vader_box_string(288u, 2547u);
        l1 = (void*) _a2_arr;
    } else if (l0.tag == 1281u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_types_UnionType_t*) t0)->f_variants;
        vader_array_t* _a3_arr = vader_array_new(14u, 0u, 0u, 288u);
        l3 = (void*) _a3_arr;
        l4 = ((vader_array_t*) l2)->length;
        l5 = INT64_C(0);
        while ((l5 < l4)) {
            vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
            t2 = vader_array_ref_load_box(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l5);
            l6 = vader_effects_written_keys(t2);
            l7 = ((vader_array_t*) l6)->length;
            l8 = INT64_C(0);
            while ((l8 < l7)) {
                vader_array_t* _a5_slotarr = ((vader_array_t*) l6);
                VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
                t2 = vader_array_box_slots(_a5_slotarr->buf)[_a5_slotarr->offset + (size_t) l8];
                l9 = t2.payload.s;
                vader_array_push((vader_array_t*) l3, vader_box_string(288u, l9));
                l8 = (l8 + INT64_C(1));
            }
            l5 = (l5 + INT64_C(1));
        }
        l1 = l3;
    } else if (l0.tag == 1264u) {
        t0 = l0.payload.obj;
        l1 = vader_effects_written_keys(((vader_struct_vader_types_DistinctType_t*) t0)->f_backing);
    } else if ((l0.tag == 1262u || l0.tag == 0u || l0.tag == 1275u || l0.tag == 1277u || l0.tag == 1280u || l0.tag == 1282u)) {
        vader_array_t* _a6_arr = vader_array_new(14u, 1u, 0u, 288u);
        vader_array_box_slots(_a6_arr->buf)[_a6_arr->offset + 0u] = vader_box_string(288u, 1407u);
        l1 = (void*) _a6_arr;
    } else if (l0.tag == 1270u) {
        t0 = l0.payload.obj;
        vader_types_leaked_infer_var(t0);
        vader_unreachable("a no-return call returned");
    } else {
        if (!((l0.tag == 1265u || l0.tag == 1266u || l0.tag == 1267u || l0.tag == 1268u || l0.tag == 1269u || l0.tag == 1271u || l0.tag == 1273u || l0.tag == 1274u || l0.tag == 1279u))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        vader_array_t* _a7_arr = vader_array_new(14u, 0u, 0u, 288u);
        l1 = (void*) _a7_arr;
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}
