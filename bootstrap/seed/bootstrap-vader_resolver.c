#include "bootstrap.split.h"

static void vader_resolver_add_fn(void* l0, void* l1, vader_string_t l2, vader_string_t l3, void* l4, void* l5);
static void vader_resolver_add_named(void* l0, int32_t l1, vader_string_t l2, void* l3, uint8_t l4, vader_string_t l5, vader_string_t l6, void* l7, void* l8);
static bool vader_resolver_any_has_body(void* l0);
static void vader_resolver_auto_bind_for_type_params(void* l0, vader_box_t l1);
static void vader_resolver_bind(void* l0, vader_string_t l1, void* l2);
static void vader_resolver_bind_1(void* l0, vader_string_t l1, vader_box_t l2);
static void vader_resolver_bind_cond_is_as(void* l0, vader_box_t l1, bool l2);
static void vader_resolver_bind_import(void* l0, vader_string_t l1, void* l2, vader_string_t l3, vader_box_t l4, vader_string_t l5, void* l6, void* l7);
static void vader_resolver_bind_let_binding(void* l0, vader_box_t l1);
static void* vader_resolver_bind_local_checked(void* l0, int32_t l1, vader_string_t l2, void* l3);
static void vader_resolver_bind_pattern(void* l0, vader_box_t l1);
static bool vader_resolver_body_survives(void* l0, void* l1);
static void* vader_resolver_build_subst(void* l0, void* l1);
static void* vader_resolver_builtin_type_names(void);
static void vader_resolver_check_groups(void* l0, void* l1);
static void vader_resolver_check_import_form_conflict(void* l0, void* l1);
static void vader_resolver_check_orphan_rule(void* l0, vader_string_t l1, void* l2, void* l3, void* l4, void* l5);
static void vader_resolver_check_selectors(void* l0, void* l1);
static void vader_resolver_check_signature(void* l0, void* l1, void* l2);
static void vader_resolver_check_target_selectors(void* l0, void* l1);
static void vader_resolver_check_wildcard_ambiguity(void* l0, void* l1, void* l2);
static void* vader_resolver_clone_ident(void* l0);
static vader_box_t vader_resolver_clone_let_binding(vader_box_t l0);
static void vader_resolver_collect_decl(void* l0, vader_box_t l1, vader_string_t l2, vader_string_t l3, void* l4, void* l5, void* l6, void* l7);
static void* vader_resolver_collect_files(void* l0, vader_string_t l1, vader_string_t l2, void* l3, void* l4, void* l5, void* l6);
static void vader_resolver_collect_import(void* l0, void* l1, vader_string_t l2, vader_string_t l3, void* l4, void* l5, void* l6, void* l7);
static void* vader_resolver_collect_module(void* l0, vader_string_t l1, vader_string_t l2, void* l3, void* l4, void* l5, void* l6);
static void* vader_resolver_collect_module_no_index(void* l0, vader_string_t l1, void* l2);
static size_t vader_resolver_count_sam_synthetics(void* l0);
static void vader_resolver_detect_import_cycles(void* l0, void* l1, void* l2);
static vader_box_t vader_resolver_diagnose_import_path(vader_string_t l0, void* l1, vader_string_t l2, void* l3, void* l4, void* l5);
static vader_string_t vader_resolver_dir_of(vader_string_t l0);
static void* vader_resolver_discarded_bodies(void* l0, vader_box_t l1);
static void vader_resolver_drain_load_queue(void* l0, void* l1, void* l2, void* l3, void* l4, void* l5, void* l6, void* l7, vader_box_t l8);
static vader_string_t vader_resolver_entry_folder_of(vader_string_t l0);
static vader_box_t vader_resolver_find_manifest_root(vader_string_t l0);
static vader_string_t vader_resolver_for_type_display_name(vader_box_t l0);
static vader_box_t vader_resolver_for_type_owner_sym(vader_box_t l0, void* l1, void* l2);
static int32_t vader_resolver_frame_count(void* l0);
static vader_string_t vader_resolver_generated_root_for(vader_box_t l0);
static void* vader_resolver_graft_body(void* l0, void* l1);
static bool vader_resolver_has_module(void* l0, vader_string_t l1);
static vader_box_t vader_resolver_home_root(vader_string_t l0, vader_string_t l1);
static uint8_t vader_resolver_importer_origin(void* l0, vader_string_t l1);
static void* vader_resolver_include_paths(vader_string_t l0, vader_string_t l1, void* l2, vader_string_t l3);
static void vader_resolver_ingest_module(void* l0, void* l1, void* l2, void* l3, void* l4, void* l5, void* l6, void* l7, vader_box_t l8);
static void* vader_resolver_intrinsic_decorator(void* l0);
static bool vader_resolver_is_host_bound(void* l0);
static bool vader_resolver_is_intrinsic(void* l0);
static bool vader_resolver_is_known_decorator(vader_string_t l0);
static vader_string_t vader_resolver_join_path(vader_string_t l0, vader_string_t l1);
static void vader_resolver_load_baked_target(void* l0, void* l1, void* l2, void* l3, void* l4, void* l5, void* l6, void* l7);
static void* vader_resolver_load_project_with_overlay(vader_string_t l0, void* l1, void* l2, vader_box_t l3);
static vader_box_t vader_resolver_lookup(void* l0, vader_string_t l1);
static int32_t vader_resolver_lookup_frame_index(void* l0, vader_string_t l1);
static vader_box_t vader_resolver_lookup_subst(void* l0, vader_string_t l1);
static vader_box_t vader_resolver_lookup_trait_sym(void* l0, void* l1, void* l2);
static void* vader_resolver_make_builtin_scope(void* l0);
static void vader_resolver_mark_binding_immutable(void* l0, vader_box_t l1);
static void vader_resolver_mark_param_borrow(void* l0, void* l1, void* l2);
static bool vader_resolver_matches_target(void* l0, void* l1);
static void vader_resolver_merge_bucket_map__string__string(void* l0, void* l1);
static void vader_resolver_merge_collected(void* l0, void* l1, void* l2);
static void* vader_resolver_mint_local(void* l0, int32_t l1, vader_string_t l2, void* l3);
static vader_box_t vader_resolver_misplaced_module_at(vader_string_t l0, void* l1);
static bool vader_resolver_names_equal(vader_box_t l0, vader_box_t l1);
static void* vader_resolver_new_import_table(void);
static void* vader_resolver_new_import_target_table(void);
static void* vader_resolver_new_scope(void* l0);
static void* vader_resolver_new_subst(void);
static void* vader_resolver_next_clone_span(void* l0);
static uint8_t vader_resolver_origin_of_root(vader_string_t l0);
static void* vader_resolver_parse_module_files(void* l0, void* l1, void* l2, void* l3);
static void* vader_resolver_plain_root(vader_string_t l0, uint8_t l1);
static void vader_resolver_pop(void* l0);
static void vader_resolver_preresolve_imports(void* l0, void* l1, void* l2, void* l3);
static void* vader_resolver_project_include_paths(vader_box_t l0, void* l1, void* l2);
static void* vader_resolver_provided_names(void* l0);
static void vader_resolver_push(void* l0);
static void* vader_resolver_read_manifest(vader_string_t l0);
static vader_string_t vader_resolver_read_with_overlay(void* l0, vader_string_t l1);
static void vader_resolver_report_uncovered(void* l0, void* l1, void* l2, void* l3, void* l4);
static vader_box_t vader_resolver_resolve_decl(vader_box_t l0, void* l1, void* l2, void* l3);
static vader_box_t vader_resolver_resolve_lazy(vader_string_t l0, void* l1, void* l2, void* l3);
static void* vader_resolver_resolve_module_with_collected_dp(void* l0, vader_string_t l1, vader_string_t l2, void* l3, void* l4);
static void* vader_resolver_resolve_program(void* l0, void* l1, vader_string_t l2, void* l3, void* l4);
static vader_box_t vader_resolver_rooted_candidate(void* l0, vader_string_t l1);
static vader_box_t vader_resolver_scan_folder(vader_string_t l0, void* l1);
static vader_box_t vader_resolver_seed_entry(vader_string_t l0, void* l1);
static void* vader_resolver_select_target_bodies(void* l0, vader_box_t l1, void* l2);
static vader_box_t vader_resolver_sidecar_root(vader_string_t l0, vader_string_t l1);
static void* vader_resolver_sort_by_name(void* l0);
static vader_string_t vader_resolver_span_origin(void* l0);
static void vader_resolver_stamp_binding_spans(vader_box_t l0, void* l1);
static void vader_resolver_stamp_block_spans(void* l0, void* l1);
static void vader_resolver_stamp_expr_spans(vader_box_t l0, void* l1);
static void vader_resolver_stamp_pattern_spans(vader_box_t l0, void* l1);
static void vader_resolver_stamp_stmt_spans(vader_box_t l0, void* l1);
static vader_box_t vader_resolver_subst_opt_expr(vader_box_t l0, void* l1);
static void* vader_resolver_substitute_block(void* l0, void* l1);
static void* vader_resolver_substitute_block_materialized(void* l0, void* l1, void* l2, void* l3);
static vader_box_t vader_resolver_substitute_coalesce_fallback(vader_box_t l0, void* l1);
static vader_box_t vader_resolver_substitute_expr_full(vader_box_t l0, void* l1);
static vader_box_t vader_resolver_substitute_opt_type(vader_box_t l0, void* l1);
static void* vader_resolver_substitute_params(void* l0, void* l1);
static void* vader_resolver_substitute_params_disambiguated(void* l0, void* l1, void* l2, void* l3);
static void* vader_resolver_substitute_params_stamped(void* l0, void* l1, void* l2);
static vader_box_t vader_resolver_substitute_pattern(vader_box_t l0, void* l1);
static vader_box_t vader_resolver_substitute_stmt(vader_box_t l0, void* l1);
static vader_box_t vader_resolver_substitute_type_expr(vader_box_t l0, void* l1);
static void* vader_resolver_synth_clone_span(void* l0);
static void* vader_resolver_synth_signature(void* l0, void* l1, void* l2, void* l3);
static void* vader_resolver_synth_with_body(void* l0, void* l1, void* l2, void* l3, void* l4);
static vader_box_t vader_resolver_target_selectors(void* l0);
static vader_box_t vader_resolver_try_read(vader_string_t l0);
static void vader_resolver_walk_block(void* l0, void* l1);
static void vader_resolver_walk_decl(void* l0, vader_box_t l1);
static void vader_resolver_walk_decorators(void* l0, void* l1);
static void vader_resolver_walk_defer(void* l0, void* l1);
static void vader_resolver_walk_expr(void* l0, vader_box_t l1);
static void vader_resolver_walk_fn_decl(void* l0, void* l1);
static void vader_resolver_walk_for(void* l0, void* l1);
static void vader_resolver_walk_if(void* l0, void* l1);
static void vader_resolver_walk_impl_decl(void* l0, void* l1);
static void vader_resolver_walk_import_cycle(vader_string_t l0, void* l1, void* l2, void* l3, void* l4);
static void vader_resolver_walk_lambda(void* l0, void* l1);
static void vader_resolver_walk_match(void* l0, void* l1);
static void vader_resolver_walk_opt_expr(void* l0, vader_box_t l1);
static void vader_resolver_walk_stmt(void* l0, vader_box_t l1);
static void vader_resolver_walk_struct_decl(void* l0, void* l1);
static void vader_resolver_walk_struct_lit(void* l0, void* l1);
static void vader_resolver_walk_trait_decl(void* l0, void* l1);
static bool vader_resolver_wildcard_exposable(int32_t l0);
static void vader_resolver_wire_module(void* l0, void* l1, void* l2, void* l3);
static void* vader_resolver_zero_span(vader_string_t l0);

static void vader_resolver_add_fn(void* l0, void* l1, vader_string_t l2, vader_string_t l3, void* l4, void* l5) {
    uint8_t l6;
    void* l7 = NULL;
    void* l11 = NULL;
    void* l13 = NULL;
    vader_string_t l8 = 0;
    vader_box_t l9 = vader_box_null(), l12 = vader_box_null();
    bool l10;
    vader_string_t t0 = 0;
    void* t1 = NULL;
    vader_box_t* gc_roots[2] = { &l9, &l12 };
    void** gc_raw_roots[8] = { &l0, &l1, &l4, &l5, &l7, &l11, &l13, &t1 };
    vader_string_t* gc_atom_roots[4] = { &l2, &l3, &l8, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l6 = ((vader_struct_toolchain_ast_FnDecl_t*) l1)->f_visibility;
    t0 = ((vader_struct_toolchain_ast_FnDecl_t*) l1)->f_name;
    if (t0 == 1840u) {
        l6 = (uint8_t) (int32_t) INT32_C(0);
    }
    l7 = ((vader_struct_vader_resolver_CollectedModule_t*) l0)->f_symbols;
    l8 = ((vader_struct_toolchain_ast_FnDecl_t*) l1)->f_name;
    l9 = std_collections_get__string__Any(l7, l8);
    if (l9.tag == 889u) {
        t1 = l9.payload.obj;
        if (((vader_struct_vader_resolver_symbol_Symbol_t*) t1)->f_kind != INT32_C(0)) {
            t1 = l9.payload.obj;
            l10 = ((vader_struct_vader_resolver_symbol_Symbol_t*) t1)->f_kind != INT32_C(7);
        } else {
            l10 = false;
        }
        if (l10) {
            l7 = ((vader_struct_toolchain_ast_FnDecl_t*) l1)->f_name_span;
            l8 = ((vader_struct_toolchain_ast_FnDecl_t*) l1)->f_name;
            l8 = concat_3(930u, l8, 939u);
            l7 = vader_diagnostics_resolver_error((uint8_t) (int32_t) INT32_C(3), l7, l8);
            vader_array_push((vader_array_t*) l5, vader_ref_box(l7));
            { vader_gc_top = gc_frame.prev; return; }
        }
    }
    l8 = ((vader_struct_toolchain_ast_FnDecl_t*) l1)->f_name;
    l7 = ((vader_struct_toolchain_ast_FnDecl_t*) l1)->f_name_span;
    l7 = vader_resolver_symbol_make(l4, INT32_C(0), l8, l2, l3, l6, vader_ref_box(l7));
    l11 = ((vader_struct_vader_resolver_CollectedModule_t*) l0)->f_fn_overloads;
    l8 = ((vader_struct_toolchain_ast_FnDecl_t*) l1)->f_name;
    l12 = std_collections_get__string__Any(l11, l8);
    if (l12.tag == 0u) {
        l11 = ((vader_struct_vader_resolver_CollectedModule_t*) l0)->f_fn_overloads;
        l8 = ((vader_struct_toolchain_ast_FnDecl_t*) l1)->f_name;
        vader_array_t* _a0_arr = vader_array_new(89u, 1u, 13u, 889u);
        ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = l7;
        l13 = (void*) _a0_arr;
        std_collections_put__string__Any(l11, l8, vader_ref_box(l13));
    } else {
        t1 = l12.payload.obj;
        vader_array_push((vader_array_t*) t1, vader_ref_box(l7));
        l11 = ((vader_struct_vader_resolver_CollectedModule_t*) l0)->f_fn_overloads;
        l8 = ((vader_struct_toolchain_ast_FnDecl_t*) l1)->f_name;
        l13 = l12.payload.obj;
        std_collections_put__string__Any(l11, l8, vader_ref_box(l13));
    }
    if (l9.tag == 0u) {
        l11 = ((vader_struct_vader_resolver_CollectedModule_t*) l0)->f_symbols;
        l8 = ((vader_struct_toolchain_ast_FnDecl_t*) l1)->f_name;
        std_collections_put__string__Any(l11, l8, vader_ref_box(l7));
    } else {
        if (l9.tag == 889u) {
            t1 = l9.payload.obj;
            if (((vader_struct_vader_resolver_symbol_Symbol_t*) t1)->f_kind == INT32_C(7)) {
                l11 = ((vader_struct_vader_resolver_CollectedModule_t*) l0)->f_symbols;
                l8 = ((vader_struct_toolchain_ast_FnDecl_t*) l1)->f_name;
                std_collections_put__string__Any(l11, l8, vader_ref_box(l7));
            }
        } else {
            { vader_gc_top = gc_frame.prev; return; }
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_resolver_add_named(void* l0, int32_t l1, vader_string_t l2, void* l3, uint8_t l4, vader_string_t l5, vader_string_t l6, void* l7, void* l8) {
    vader_box_t l9 = vader_box_null();
    vader_string_t l10 = 0;
    void* l11 = NULL;
    vader_box_t* gc_roots[1] = { &l9 };
    void** gc_raw_roots[5] = { &l0, &l3, &l7, &l8, &l11 };
    vader_string_t* gc_atom_roots[4] = { &l2, &l5, &l6, &l10 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l9 = std_collections_get__string__Any(((vader_struct_vader_resolver_CollectedModule_t*) l0)->f_symbols, l2);
    if (l9.tag == 889u) {
        l10 = concat_3(930u, l2, 939u);
        l11 = vader_diagnostics_resolver_error((uint8_t) (int32_t) INT32_C(3), l3, l10);
        vader_array_push((vader_array_t*) l8, vader_ref_box(l11));
    } else {
        if (l9.tag == 0u) {
            l11 = vader_resolver_symbol_make(l7, l1, l2, l5, l6, l4, vader_ref_box(l3));
            std_collections_put__string__Any(((vader_struct_vader_resolver_CollectedModule_t*) l0)->f_symbols, l2, vader_ref_box(l11));
        } else {
            { vader_gc_top = gc_frame.prev; return; }
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

void* vader_resolver_all_wildcard_excludes(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    size_t l4, l5;
    void* t0 = NULL;
    int64_t t1;
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 169u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(16u, 0u, 0u, 180u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 172u);
    l3 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__string__Any___t* _a3_obj = (vader_struct_std_collections_MutableMap__string__Any___t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__Any___t));
    vader_obj_header_init(_a3_obj, 323u);
    _a3_obj->f_ekeys = l1;
    _a3_obj->f_evals = l2;
    _a3_obj->f_index = l3;
    _a3_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l1 = (void*) _a3_obj;
    l2 = ((vader_struct_vader_resolver_CollectedModule_t*) l0)->f_wildcards;
    l4 = ((vader_array_t*) l2)->length;
    l5 = (size_t) (int64_t) INT64_C(0);
    {
        loop_21: {
            if ((l5 < l4)) {
                vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
                if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                if ((size_t) l5 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l5);
                l3 = ((vader_struct_vader_resolver_FileWildcards_t*) t0)->f_excludes;
                vader_resolver_merge_bucket_map__string__string(l1, l3);
                t1 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t1;
                goto loop_21;
            }
        }
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

void* vader_resolver_all_wildcard_paths(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l5 = NULL;
    size_t l3, l4;
    void* t0 = NULL;
    int64_t t1;
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l5, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 169u);
    l1 = (void*) _a0_arr;
    l2 = ((vader_struct_vader_resolver_CollectedModule_t*) l0)->f_wildcards;
    l3 = ((vader_array_t*) l2)->length;
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_9: {
            if ((l4 < l3)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l4 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
                l5 = ((vader_struct_vader_resolver_FileWildcards_t*) t0)->f_paths;
                vader_array_push_all((vader_array_t*) l1, (vader_array_t*) l5);
                t1 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t1;
                goto loop_9;
            }
        }
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static bool vader_resolver_any_has_body(void* l0) {
    void* l1;
    size_t l2, l3;
    vader_box_t l4;
    void* t0;
    int64_t t1;
    l1 = l0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    l2 = ((vader_array_t*) l1)->length;
    l3 = (size_t) (int64_t) INT64_C(0);
    {
        loop_7: {
            if ((l3 < l2)) {
                if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
                l4 = ((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_body;
                if (l4.tag == 398u) {
                    return true;
                }
                if (l4.tag == 0u) {
                } else {
                    vader_unreachable("unreachable return in vader_resolver$any_has_body");
                }
                t1 = (l3 + INT64_C(1));
                l3 = (size_t) (int64_t) t1;
                goto loop_7;
            }
        }
    }
    return false;
}

static void vader_resolver_auto_bind_for_type_params(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    void* l6 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    size_t l3, l4;
    vader_box_t l5 = vader_box_null();
    vader_string_t l7 = 0;
    vader_string_t l8 = 0;
    vader_string_t l12 = 0;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    int64_t t2;
    vader_box_t* gc_roots[3] = { &l1, &l5, &t1 };
    void** gc_raw_roots[7] = { &l0, &l2, &l6, &l9, &l10, &l11, &t0 };
    vader_string_t* gc_atom_roots[3] = { &l7, &l8, &l12 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    if (!(l1.tag == 425u)) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    t0 = l1.payload.obj;
    l2 = ((vader_struct_toolchain_ast_GenericInstExpr_t*) t0)->f_type_args;
    l3 = ((vader_array_t*) l2)->length;
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_15: {
            if ((l4 < l3)) {
                vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
                if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                if ((size_t) l4 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                l5 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
                if (l5.tag == 426u) {
                    l6 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_scope;
                    t0 = l5.payload.obj;
                    l7 = ((vader_struct_toolchain_ast_IdentExpr_t*) t0)->f_name;
                    t1 = vader_resolver_lookup(l6, l7);
                    if (t1.tag == 0u) {
                        t0 = l5.payload.obj;
                        l8 = ((vader_struct_toolchain_ast_IdentExpr_t*) t0)->f_name;
                        t0 = l5.payload.obj;
                        l9 = ((vader_struct_toolchain_ast_IdentExpr_t*) t0)->f_span;
                        l10 = vader_resolver_mint_local(l0, INT32_C(9), l8, l9);
                        l11 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_scope;
                        t0 = l5.payload.obj;
                        l12 = ((vader_struct_toolchain_ast_IdentExpr_t*) t0)->f_name;
                        vader_resolver_bind(l11, l12, l10);
                    }
                }
                t2 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t2;
                goto loop_15;
            }
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_resolver_bind(void* l0, vader_string_t l1, void* l2) {
    size_t l3;
    void* l4 = NULL;
    int64_t t0;
    void* t1 = NULL;
    void** gc_raw_roots[4] = { &l0, &l2, &l4, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l3 = ((vader_array_t*) ((vader_struct_vader_resolver_Scope_t*) l0)->f_frames)->length;
    if (l3 == INT64_C(0)) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l4 = ((vader_struct_vader_resolver_Scope_t*) l0)->f_frames;
    t0 = (l3 - INT64_C(1));
    l3 = (size_t) (int64_t) t0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
    t1 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
    std_collections_put__string__Any(t1, l1, vader_ref_box(l2));
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_resolver_bind_1(void* l0, vader_string_t l1, vader_box_t l2) {
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    std_collections_put__string__Any(((vader_struct_vader_resolver_Subst_t*) l0)->f_entries, l1, l2);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_resolver_bind_cond_is_as(void* l0, vader_box_t l1, bool l2) {
    vader_box_t l3 = vader_box_null();
    void* l4 = NULL;
    void* l5 = NULL;
    vader_string_t l6 = 0;
    void* t0 = NULL;
    void* t2 = NULL;
    vader_string_t t1 = 0;
    vader_box_t* gc_roots[2] = { &l1, &l3 };
    void** gc_raw_roots[5] = { &l0, &l4, &l5, &t0, &t2 };
    vader_string_t* gc_atom_roots[2] = { &l6, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    if (l1.tag == 396u) {
        t0 = l1.payload.obj;
        if (((vader_struct_toolchain_ast_BinaryExpr_t*) t0)->f_op == INT32_C(10)) {
            t0 = l1.payload.obj;
            l3 = ((vader_struct_toolchain_ast_BinaryExpr_t*) t0)->f_left;
            vader_resolver_bind_cond_is_as(l0, l3, true);
            t0 = l1.payload.obj;
            l3 = ((vader_struct_toolchain_ast_BinaryExpr_t*) t0)->f_right;
            vader_resolver_bind_cond_is_as(l0, l3, true);
            { vader_gc_top = gc_frame.prev; return; }
        }
        t0 = l1.payload.obj;
        if (((vader_struct_toolchain_ast_BinaryExpr_t*) t0)->f_op == INT32_C(18)) {
            t0 = l1.payload.obj;
            l3 = ((vader_struct_toolchain_ast_BinaryExpr_t*) t0)->f_left;
            vader_resolver_walk_expr(l0, l3);
            t0 = l1.payload.obj;
            l3 = ((vader_struct_toolchain_ast_BinaryExpr_t*) t0)->f_right;
            vader_resolver_walk_expr(l0, l3);
            t0 = l1.payload.obj;
            t1 = ((vader_struct_toolchain_ast_BinaryExpr_t*) t0)->f_bind_as;
            if (t1 != 0u) {
                if (l2) {
                    l4 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_diags;
                    t0 = l1.payload.obj;
                    t2 = ((vader_struct_toolchain_ast_BinaryExpr_t*) t0)->f_right.payload.obj;
                    l5 = ((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t2)->f_span;
                    l5 = vader_diagnostics_resolver_error((uint8_t) (int32_t) INT32_C(28), l5, 1183u);
                    vader_array_push((vader_array_t*) l4, vader_ref_box(l5));
                }
                t0 = l1.payload.obj;
                l6 = ((vader_struct_toolchain_ast_BinaryExpr_t*) t0)->f_bind_as;
                t0 = l1.payload.obj;
                t2 = ((vader_struct_toolchain_ast_BinaryExpr_t*) t0)->f_right.payload.obj;
                l4 = ((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t2)->f_span;
                l4 = vader_resolver_mint_local(l0, INT32_C(11), l6, l4);
                l5 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_scope;
                t0 = l1.payload.obj;
                l6 = ((vader_struct_toolchain_ast_BinaryExpr_t*) t0)->f_bind_as;
                vader_resolver_bind(l5, l6, l4);
            }
            { vader_gc_top = gc_frame.prev; return; }
        }
    }
    vader_resolver_walk_expr(l0, l1);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_resolver_bind_import(void* l0, vader_string_t l1, void* l2, vader_string_t l3, vader_box_t l4, vader_string_t l5, void* l6, void* l7) {
    vader_box_t l8 = vader_box_null(), l11 = vader_box_null();
    void* l9 = NULL;
    void* l14 = NULL;
    int32_t l10;
    bool l12;
    vader_string_t l13 = 0;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    vader_box_t* gc_roots[3] = { &l4, &l8, &l11 };
    void** gc_raw_roots[7] = { &l0, &l2, &l6, &l7, &l9, &l14, &t0 };
    vader_string_t* gc_atom_roots[5] = { &l1, &l3, &l5, &l13, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 5u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l8 = std_collections_get__string__Any(((vader_struct_vader_resolver_CollectedModule_t*) l0)->f_symbols, l1);
    if (l8.tag == 889u) {
        t0 = l8.payload.obj;
        if (((vader_struct_vader_resolver_symbol_Symbol_t*) t0)->f_kind == INT32_C(7)) {
            l9 = ((vader_struct_vader_resolver_CollectedModule_t*) l0)->f_imports;
            t0 = l8.payload.obj;
            l10 = ((vader_struct_vader_resolver_symbol_Symbol_t*) t0)->f_id;
            l11 = std_collections_get__i32__Any(l9, l10);
            if (!(l11.tag == 0u)) {
                t0 = l11.payload.obj;
                t1 = ((vader_struct_vader_resolver_ImportInfo_t*) t0)->f_path;
                if (t1 == l3) {
                    t0 = l11.payload.obj;
                    l12 = vader_resolver_names_equal(((vader_struct_vader_resolver_ImportInfo_t*) t0)->f_imported_name, l4);
                } else {
                    l12 = false;
                }
                l12 = !(l12);
            } else {
                l12 = false;
            }
            if (l12) {
                l13 = concat_3(930u, l1, 930u);
                l9 = vader_diagnostics_resolver_error((uint8_t) (int32_t) INT32_C(10), l2, l13);
                vader_array_push((vader_array_t*) l7, vader_ref_box(l9));
            }
        } else {
            t0 = l8.payload.obj;
            if (((vader_struct_vader_resolver_symbol_Symbol_t*) t0)->f_kind == INT32_C(0)) {
                l9 = vader_resolver_symbol_make(l6, INT32_C(7), l1, l5, l5, (uint8_t) (int32_t) INT32_C(1), vader_ref_box(l2));
                l14 = ((vader_struct_vader_resolver_CollectedModule_t*) l0)->f_imports;
                l10 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l9)->f_id;
                vader_struct_vader_resolver_ImportInfo_t* _a0_obj = (vader_struct_vader_resolver_ImportInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_resolver_ImportInfo_t));
                vader_obj_header_init(_a0_obj, 873u);
                _a0_obj->f_path = l3;
                _a0_obj->f_imported_name = l4;
                _a0_obj->f_local = l1;
                _a0_obj->f_binding_span = l2;
                l9 = (void*) _a0_obj;
                std_collections_put__i32__Any(l14, l10, vader_ref_box(l9));
            } else {
                l13 = concat_3(930u, l1, 930u);
                l9 = vader_diagnostics_resolver_error((uint8_t) (int32_t) INT32_C(10), l2, l13);
                vader_array_push((vader_array_t*) l7, vader_ref_box(l9));
            }
        }
    } else {
        if (l8.tag == 0u) {
            l9 = vader_resolver_symbol_make(l6, INT32_C(7), l1, l5, l5, (uint8_t) (int32_t) INT32_C(1), vader_ref_box(l2));
            std_collections_put__string__Any(((vader_struct_vader_resolver_CollectedModule_t*) l0)->f_symbols, l1, vader_ref_box(l9));
            l14 = ((vader_struct_vader_resolver_CollectedModule_t*) l0)->f_imports;
            l10 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l9)->f_id;
            vader_struct_vader_resolver_ImportInfo_t* _a1_obj = (vader_struct_vader_resolver_ImportInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_resolver_ImportInfo_t));
            vader_obj_header_init(_a1_obj, 873u);
            _a1_obj->f_path = l3;
            _a1_obj->f_imported_name = l4;
            _a1_obj->f_local = l1;
            _a1_obj->f_binding_span = l2;
            l9 = (void*) _a1_obj;
            std_collections_put__i32__Any(l14, l10, vader_ref_box(l9));
        } else {
            { vader_gc_top = gc_frame.prev; return; }
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_resolver_bind_let_binding(void* l0, vader_box_t l1) {
    vader_string_t l2 = 0;
    void* l3 = NULL;
    void* l4 = NULL;
    uint64_t l5;
    size_t l6, l7;
    vader_box_t l8 = vader_box_null();
    void* t0 = NULL;
    int64_t t1;
    vader_box_t* gc_roots[2] = { &l1, &l8 };
    void** gc_raw_roots[4] = { &l0, &l3, &l4, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    if (l1.tag == 459u) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_toolchain_ast_SimpleBinding_t*) t0)->f_name;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_toolchain_ast_SimpleBinding_t*) t0)->f_name_span;
        l3 = vader_resolver_bind_local_checked(l0, INT32_C(10), l2, l3);
        l4 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_idents;
        t0 = l1.payload.obj;
        l5 = toolchain_span_Span_Hash_hash(((vader_struct_toolchain_ast_SimpleBinding_t*) t0)->f_name_span);
        std_collections_put__u64__Any(l4, l5, vader_ref_box(l3));
    } else {
        if (l1.tag == 471u) {
            t0 = l1.payload.obj;
            l3 = ((vader_struct_toolchain_ast_TupleBinding_t*) t0)->f_elements;
            l6 = ((vader_array_t*) l3)->length;
            l7 = (size_t) (int64_t) INT64_C(0);
            {
                loop_42: {
                    if ((l7 < l6)) {
                        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
                        if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                        if ((size_t) l7 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                        l8 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l7);
                        vader_resolver_bind_let_binding(l0, l8);
                        t1 = (l7 + INT64_C(1));
                        l7 = (size_t) (int64_t) t1;
                        goto loop_42;
                    }
                }
            }
        } else {
            if (l1.tag == 477u) {
            } else {
                if (l1.tag == 456u) {
                    t0 = l1.payload.obj;
                    l2 = ((vader_struct_toolchain_ast_RestBinding_t*) t0)->f_name;
                    t0 = l1.payload.obj;
                    l3 = ((vader_struct_toolchain_ast_RestBinding_t*) t0)->f_span;
                    l3 = vader_resolver_bind_local_checked(l0, INT32_C(10), l2, l3);
                    l4 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_idents;
                    t0 = l1.payload.obj;
                    l5 = toolchain_span_Span_Hash_hash(((vader_struct_toolchain_ast_RestBinding_t*) t0)->f_span);
                    std_collections_put__u64__Any(l4, l5, vader_ref_box(l3));
                } else {
                    { vader_gc_top = gc_frame.prev; return; }
                }
            }
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_resolver_bind_local_checked(void* l0, int32_t l1, vader_string_t l2, void* l3) {
    int32_t l4, l5;
    void* l6 = NULL;
    void* l8 = NULL;
    vader_string_t l7 = 0;
    int32_t t0;
    void** gc_raw_roots[4] = { &l0, &l3, &l6, &l8 };
    vader_string_t* gc_atom_roots[2] = { &l2, &l7 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    if (l2 == 869u) {
        l4 = -(INT32_C(1));
    } else {
        l4 = vader_resolver_lookup_frame_index(((vader_struct_vader_resolver_ResolveState_t*) l0)->f_scope, l2);
    }
    if ((l4 > INT32_C(0))) {
        t0 = vader_resolver_frame_count(((vader_struct_vader_resolver_ResolveState_t*) l0)->f_scope);
        l5 = (t0 - INT32_C(1));
        if (l4 == l5) {
            l6 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_diags;
            l7 = concat_3(930u, l2, 930u);
            l8 = vader_diagnostics_warning((uint8_t) (int32_t) INT32_C(5), l3, l7);
            vader_array_push((vader_array_t*) l6, vader_ref_box(l8));
        } else {
            l6 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_diags;
            l7 = concat_3(930u, l2, 930u);
            l8 = vader_diagnostics_warning((uint8_t) (int32_t) INT32_C(4), l3, l7);
            vader_array_push((vader_array_t*) l6, vader_ref_box(l8));
        }
    }
    l6 = vader_resolver_mint_local(l0, l1, l2, l3);
    vader_resolver_bind(((vader_struct_vader_resolver_ResolveState_t*) l0)->f_scope, l2, l6);
    { void* __vret = l6; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void vader_resolver_bind_pattern(void* l0, vader_box_t l1) {
    vader_box_t l2 = vader_box_null(), l12 = vader_box_null();
    vader_string_t l3 = 0;
    vader_string_t l11 = 0;
    void* l4 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    size_t l5, l6;
    void* t0 = NULL;
    int64_t t1;
    vader_box_t* gc_roots[3] = { &l1, &l2, &l12 };
    void** gc_raw_roots[7] = { &l0, &l4, &l7, &l8, &l9, &l10, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l3, &l11 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    if (l1.tag == 438u) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_toolchain_ast_IsPattern_t*) t0)->f_ty;
        vader_resolver_walk_expr(l0, l2);
        t0 = l1.payload.obj;
        l2 = ((vader_struct_toolchain_ast_IsPattern_t*) t0)->f_bind_as;
        if (l2.tag == 0u) {
        } else {
            if (l2.tag == 169u) {
                l3 = l2.payload.s;
                t0 = l1.payload.obj;
                l4 = ((vader_struct_toolchain_ast_IsPattern_t*) t0)->f_span;
                l4 = vader_resolver_mint_local(l0, INT32_C(11), l3, l4);
                vader_resolver_bind(((vader_struct_vader_resolver_ResolveState_t*) l0)->f_scope, l3, l4);
            } else {
                { vader_gc_top = gc_frame.prev; return; }
            }
        }
        t0 = l1.payload.obj;
        if (!(((vader_struct_toolchain_ast_IsPattern_t*) t0)->f_inner.tag == 0u)) {
            t0 = l1.payload.obj;
            l2 = ((vader_struct_toolchain_ast_IsPattern_t*) t0)->f_inner;
            vader_resolver_bind_pattern(l0, l2);
        }
    } else {
        if (l1.tag == 468u) {
            t0 = l1.payload.obj;
            l4 = ((vader_struct_toolchain_ast_StructPattern_t*) t0)->f_fields;
            l5 = ((vader_array_t*) l4)->length;
            l6 = (size_t) (int64_t) INT64_C(0);
            {
                loop_68: {
                    if ((l6 < l5)) {
                        vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
                        if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                        if ((size_t) l6 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                        l7 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l6);
                        l2 = ((vader_struct_toolchain_ast_StructPatternField_t*) l7)->f_value;
                        if (l2.tag == 451u) {
                            l3 = ((vader_struct_toolchain_ast_StructPatternField_t*) l7)->f_name;
                            l8 = ((vader_struct_toolchain_ast_StructPatternField_t*) l7)->f_name_span;
                            l9 = vader_resolver_mint_local(l0, INT32_C(11), l3, l8);
                            l10 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_scope;
                            l11 = ((vader_struct_toolchain_ast_StructPatternField_t*) l7)->f_name;
                            vader_resolver_bind(l10, l11, l9);
                        } else {
                            if (l2.tag == 452u) {
                                t0 = l2.payload.obj;
                                l12 = ((vader_struct_toolchain_ast_PatternLiteral_t*) t0)->f_value;
                                vader_resolver_walk_expr(l0, l12);
                            } else {
                                { vader_gc_top = gc_frame.prev; return; }
                            }
                        }
                        t1 = (l6 + INT64_C(1));
                        l6 = (size_t) (int64_t) t1;
                        goto loop_68;
                    }
                }
            }
        } else {
            if (l1.tag == 472u) {
                t0 = l1.payload.obj;
                l4 = ((vader_struct_toolchain_ast_TuplePattern_t*) t0)->f_elements;
                l5 = ((vader_array_t*) l4)->length;
                l6 = (size_t) (int64_t) INT64_C(0);
                {
                    loop_137: {
                        if ((l6 < l5)) {
                            vader_array_t* _a1_slotarr = ((vader_array_t*) l4);
                            if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                            if ((size_t) l6 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                            l2 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l6);
                            vader_resolver_bind_pattern(l0, l2);
                            t1 = (l6 + INT64_C(1));
                            l6 = (size_t) (int64_t) t1;
                            goto loop_137;
                        }
                    }
                }
            } else {
                if (l1.tag == 479u) {
                } else {
                    if (l1.tag == 397u) {
                        t0 = l1.payload.obj;
                        l3 = ((vader_struct_toolchain_ast_BindingPattern_t*) t0)->f_name;
                        t0 = l1.payload.obj;
                        l4 = ((vader_struct_toolchain_ast_BindingPattern_t*) t0)->f_span;
                        l4 = vader_resolver_mint_local(l0, INT32_C(11), l3, l4);
                        l7 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_scope;
                        t0 = l1.payload.obj;
                        l3 = ((vader_struct_toolchain_ast_BindingPattern_t*) t0)->f_name;
                        vader_resolver_bind(l7, l3, l4);
                    } else {
                        if (l1.tag == 417u) {
                        } else {
                            if (l1.tag == 441u) {
                                t0 = l1.payload.obj;
                                l2 = ((vader_struct_toolchain_ast_LiteralPattern_t*) t0)->f_value;
                                vader_resolver_walk_expr(l0, l2);
                            } else {
                                if (l1.tag == 455u) {
                                    t0 = l1.payload.obj;
                                    l2 = ((vader_struct_toolchain_ast_RangePattern_t*) t0)->f_lower;
                                    vader_resolver_walk_expr(l0, l2);
                                    t0 = l1.payload.obj;
                                    l2 = ((vader_struct_toolchain_ast_RangePattern_t*) t0)->f_upper;
                                    vader_resolver_walk_expr(l0, l2);
                                } else {
                                    if (l1.tag == 450u) {
                                        t0 = l1.payload.obj;
                                        l4 = ((vader_struct_toolchain_ast_OrPattern_t*) t0)->f_patterns;
                                        l5 = ((vader_array_t*) l4)->length;
                                        l6 = (size_t) (int64_t) INT64_C(0);
                                        {
                                            loop_237: {
                                                if ((l6 < l5)) {
                                                    vader_array_t* _a2_slotarr = ((vader_array_t*) l4);
                                                    if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                                                    if ((size_t) l6 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                                                    l2 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l6);
                                                    vader_resolver_bind_pattern(l0, l2);
                                                    t1 = (l6 + INT64_C(1));
                                                    l6 = (size_t) (int64_t) t1;
                                                    goto loop_237;
                                                }
                                            }
                                        }
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
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static bool vader_resolver_body_survives(void* l0, void* l1) {
    vader_box_t l2, l9, l10;
    void* l3;
    void* l6;
    void* l11;
    void* l12;
    size_t l4, l5, l7, l8;
    void* t0;
    bool t1;
    int64_t t2;
    l2 = ((vader_struct_toolchain_ast_FnDecl_t*) l0)->f_body;
    if (l2.tag == 0u) {
        return false;
    }
    l3 = l1;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    l4 = ((vader_array_t*) l3)->length;
    l5 = (size_t) (int64_t) INT64_C(0);
    {
        loop_13: {
            if ((l5 < l4)) {
                if ((size_t) l5 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
                l6 = ((vader_struct_toolchain_ast_Program_t*) ((vader_struct_vader_resolver_SourceFile_t*) t0)->f_program)->f_decls;
                vader_array_t* _a1_slotarr = ((vader_array_t*) l6);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                l7 = ((vader_array_t*) l6)->length;
                l8 = (size_t) (int64_t) INT64_C(0);
                {
                    loop_29: {
                        if ((l8 < l7)) {
                            if ((size_t) l8 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                            l9 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l8);
                            if (l9.tag == 421u) {
                                t0 = l9.payload.obj;
                                l10 = ((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_body;
                                if (!(l10.tag == 0u)) {
                                    t0 = l10.payload.obj;
                                    l11 = ((vader_struct_toolchain_ast_BlockExpr_t*) t0)->f_span;
                                    t0 = l2.payload.obj;
                                    l12 = ((vader_struct_toolchain_ast_BlockExpr_t*) t0)->f_span;
                                    t1 = toolchain_span_Span_Equals_equals(l11, l12);
                                    if (t1) {
                                        return true;
                                    }
                                }
                            }
                            t2 = (l8 + INT64_C(1));
                            l8 = (size_t) (int64_t) t2;
                            goto loop_29;
                        }
                    }
                }
                t2 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t2;
                goto loop_13;
            }
        }
    }
    return false;
}

void* vader_resolver_build_core_seed(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l5 = NULL;
    void* l9 = NULL;
    void* l11 = NULL;
    vader_box_t l4 = vader_box_null();
    size_t l6, l7;
    vader_string_t l8 = 0;
    vader_string_t l10 = 0;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    int64_t t2;
    vader_box_t* gc_roots[2] = { &l4, &t1 };
    void** gc_raw_roots[8] = { &l0, &l1, &l2, &l3, &l5, &l9, &l11, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l8, &l10 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 169u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(16u, 0u, 0u, 180u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 172u);
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
    l4 = std_collections_get__string__Any(((vader_struct_vader_resolver_LoadedProject_t*) l0)->f_modules, 507u);
    if (l4.tag == 876u) {
        t0 = l4.payload.obj;
        l2 = ((vader_struct_vader_resolver_CollectedModule_t*) ((vader_struct_vader_resolver_LoadedModule_t*) t0)->f_collected)->f_symbols;
        l3 = ((vader_struct_std_collections_MutableMap__string__Symbol_t*) l2)->f_ekeys;
        l5 = ((vader_struct_std_collections_MutableMap__string__Symbol_t*) l2)->f_evals;
        l6 = ((vader_struct_std_collections_MutableMap__string__Symbol_t*) l2)->f_size;
        l7 = (size_t) (int64_t) INT64_C(0);
        {
            loop_35: {
                if ((l7 >= l6)) {
                } else {
                    vader_array_t* _a4_slotarr = ((vader_array_t*) l3);
                    if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                    if ((size_t) l7 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                    t1 = vader_array_box_slots(_a4_slotarr->buf)[_a4_slotarr->offset + (size_t) l7];
                    l8 = t1.payload.s;
                    vader_array_t* _a5_slotarr = ((vader_array_t*) l5);
                    if (_a5_slotarr->buf != NULL && _a5_slotarr->buf->header.forward != NULL) { _a5_slotarr->buf = vader_array_buf_forward(_a5_slotarr->buf); }
                    if ((size_t) l7 >= _a5_slotarr->length) { vader_trap("array index out of bounds"); }
                    l2 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l7);
                    vader_struct___Tuple_2_cb60e7c5b39cd1d9_t* _a6_obj = (vader_struct___Tuple_2_cb60e7c5b39cd1d9_t*) vader_gc_alloc(sizeof(vader_struct___Tuple_2_cb60e7c5b39cd1d9_t));
                    vader_obj_header_init(_a6_obj, 223u);
                    _a6_obj->f__0 = l8;
                    _a6_obj->f__1 = l2;
                    l9 = (void*) _a6_obj;
                    l10 = ((vader_struct___Tuple_2_cb60e7c5b39cd1d9_t*) l9)->f__0;
                    l11 = ((vader_struct___Tuple_2_cb60e7c5b39cd1d9_t*) l9)->f__1;
                    t2 = (l7 + INT64_C(1));
                    l7 = (size_t) (int64_t) t2;
                    std_collections_put__string__Any(l1, l10, vader_ref_box(l11));
                    goto loop_35;
                }
            }
        }
    }
    l4 = vader_resolver_find_core_module_id(l0);
    if (l4.tag == 0u) {
        { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l8 = l4.payload.s;
    l4 = std_collections_get__string__Any(((vader_struct_vader_resolver_LoadedProject_t*) l0)->f_modules, l8);
    if (l4.tag == 0u) {
        { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = l4.payload.obj;
    l2 = ((vader_struct_vader_resolver_CollectedModule_t*) ((vader_struct_vader_resolver_LoadedModule_t*) l2)->f_collected)->f_symbols;
    l3 = ((vader_struct_std_collections_MutableMap__string__Symbol_t*) l2)->f_ekeys;
    l5 = ((vader_struct_std_collections_MutableMap__string__Symbol_t*) l2)->f_evals;
    l6 = ((vader_struct_std_collections_MutableMap__string__Symbol_t*) l2)->f_size;
    l7 = (size_t) (int64_t) INT64_C(0);
    {
        loop_108: {
            if ((l7 >= l6)) {
            } else {
                vader_array_t* _a7_slotarr = ((vader_array_t*) l3);
                if (_a7_slotarr->buf != NULL && _a7_slotarr->buf->header.forward != NULL) { _a7_slotarr->buf = vader_array_buf_forward(_a7_slotarr->buf); }
                if ((size_t) l7 >= _a7_slotarr->length) { vader_trap("array index out of bounds"); }
                t1 = vader_array_box_slots(_a7_slotarr->buf)[_a7_slotarr->offset + (size_t) l7];
                l8 = t1.payload.s;
                vader_array_t* _a8_slotarr = ((vader_array_t*) l5);
                if (_a8_slotarr->buf != NULL && _a8_slotarr->buf->header.forward != NULL) { _a8_slotarr->buf = vader_array_buf_forward(_a8_slotarr->buf); }
                if ((size_t) l7 >= _a8_slotarr->length) { vader_trap("array index out of bounds"); }
                l2 = vader_array_ref_load_obj(_a8_slotarr->buf, _a8_slotarr->offset + (size_t) l7);
                vader_struct___Tuple_2_cb60e7c5b39cd1d9_t* _a9_obj = (vader_struct___Tuple_2_cb60e7c5b39cd1d9_t*) vader_gc_alloc(sizeof(vader_struct___Tuple_2_cb60e7c5b39cd1d9_t));
                vader_obj_header_init(_a9_obj, 223u);
                _a9_obj->f__0 = l8;
                _a9_obj->f__1 = l2;
                l9 = (void*) _a9_obj;
                l10 = ((vader_struct___Tuple_2_cb60e7c5b39cd1d9_t*) l9)->f__0;
                l11 = ((vader_struct___Tuple_2_cb60e7c5b39cd1d9_t*) l9)->f__1;
                t2 = (l7 + INT64_C(1));
                l7 = (size_t) (int64_t) t2;
                std_collections_put__string__Any(l1, l10, vader_ref_box(l11));
                goto loop_108;
            }
        }
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_resolver_build_subst(void* l0, void* l1) {
    void* l2 = NULL;
    vader_box_t l3 = vader_box_null(), l7 = vader_box_null(), l8 = vader_box_null();
    size_t l4, l5;
    vader_string_t l6 = 0;
    void* t0 = NULL;
    int64_t t1;
    vader_box_t* gc_roots[3] = { &l3, &l7, &l8 };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l6 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = vader_resolver_new_subst();
    l3 = ((vader_struct_toolchain_ast_ImplDecl_t*) l0)->f_for_type;
    vader_resolver_bind_1(l2, 739u, l3);
    l4 = ((vader_array_t*) ((vader_struct_toolchain_ast_TraitDecl_t*) l1)->f_type_params)->length;
    l5 = ((vader_array_t*) ((vader_struct_toolchain_ast_ImplDecl_t*) l0)->f_trait_args)->length;
    l4 = std_math_min_2(l4, l5);
    l5 = (size_t) (int64_t) INT64_C(0);
    {
        loop_21: {
            if ((l5 < l4)) {
                vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_TraitDecl_t*) l1)->f_type_params);
                if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                if ((size_t) l5 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
                l6 = ((vader_struct_toolchain_ast_TypeParam_t*) t0)->f_name;
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_ImplDecl_t*) l0)->f_trait_args);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l5 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                l3 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5);
                vader_resolver_bind_1(l2, l6, l3);
                t1 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t1;
                goto loop_21;
            }
        }
    }
    l5 = ((vader_array_t*) ((vader_struct_toolchain_ast_TraitDecl_t*) l1)->f_type_params)->length;
    {
        loop_52: {
            if ((l4 < l5)) {
                vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_TraitDecl_t*) l1)->f_type_params);
                if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                if ((size_t) l4 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
                l7 = ((vader_struct_toolchain_ast_TypeParam_t*) t0)->f_default_v;
                if (l7.tag == 0u) {
                } else {
                    l3 = l7;
                    vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_TraitDecl_t*) l1)->f_type_params);
                    if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                    if ((size_t) l4 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                    t0 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l4);
                    l6 = ((vader_struct_toolchain_ast_TypeParam_t*) t0)->f_name;
                    l8 = vader_resolver_substitute_type_expr(l3, l2);
                    vader_resolver_bind_1(l2, l6, l8);
                    t1 = (l4 + INT64_C(1));
                    l4 = (size_t) (int64_t) t1;
                    goto loop_52;
                }
            }
        }
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

void* vader_resolver_build_wildcard_seed(void* l0, void* l1, void* l2, void* l3) {
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l11 = NULL;
    void* l13 = NULL;
    void* l18 = NULL;
    void* l19 = NULL;
    void* l21 = NULL;
    size_t l8, l9, l16, l17;
    vader_string_t l10 = 0;
    vader_string_t l12 = 0;
    vader_string_t l22 = 0;
    vader_string_t l23 = 0;
    vader_string_t l24 = 0;
    vader_box_t l14 = vader_box_null(), l15 = vader_box_null();
    bool l20;
    size_t t0;
    vader_box_t t1 = vader_box_null();
    int64_t t2;
    void* t3 = NULL;
    bool t4;
    vader_box_t* gc_roots[3] = { &l14, &l15, &t1 };
    void** gc_raw_roots[14] = { &l0, &l1, &l2, &l3, &l4, &l5, &l6, &l7, &l11, &l13, &l18, &l19, &l21, &t3 };
    vader_string_t* gc_atom_roots[5] = { &l10, &l12, &l22, &l23, &l24 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 14u, gc_roots, gc_raw_roots, 0u, NULL, 5u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) l1)->length;
    if (t0 == INT64_C(0)) {
        { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 169u);
    l4 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(16u, 0u, 0u, 180u);
    l5 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 172u);
    l6 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__string__Any_t* _a3_obj = (vader_struct_std_collections_MutableMap__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__Any_t));
    vader_obj_header_init(_a3_obj, 321u);
    _a3_obj->f_ekeys = l4;
    _a3_obj->f_evals = l5;
    _a3_obj->f_index = l6;
    _a3_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l4 = (void*) _a3_obj;
    l5 = l3;
    l6 = ((vader_struct_std_collections_MutableMap__string__Symbol_t*) l5)->f_ekeys;
    l7 = ((vader_struct_std_collections_MutableMap__string__Symbol_t*) l5)->f_evals;
    l8 = ((vader_struct_std_collections_MutableMap__string__Symbol_t*) l5)->f_size;
    l9 = (size_t) (int64_t) INT64_C(0);
    {
        loop_34: {
            if ((l9 >= l8)) {
            } else {
                vader_array_t* _a4_slotarr = ((vader_array_t*) l6);
                if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                if ((size_t) l9 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                t1 = vader_array_box_slots(_a4_slotarr->buf)[_a4_slotarr->offset + (size_t) l9];
                l10 = t1.payload.s;
                vader_array_t* _a5_slotarr = ((vader_array_t*) l7);
                if (_a5_slotarr->buf != NULL && _a5_slotarr->buf->header.forward != NULL) { _a5_slotarr->buf = vader_array_buf_forward(_a5_slotarr->buf); }
                if ((size_t) l9 >= _a5_slotarr->length) { vader_trap("array index out of bounds"); }
                l5 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l9);
                vader_struct___Tuple_2_cb60e7c5b39cd1d9_t* _a6_obj = (vader_struct___Tuple_2_cb60e7c5b39cd1d9_t*) vader_gc_alloc(sizeof(vader_struct___Tuple_2_cb60e7c5b39cd1d9_t));
                vader_obj_header_init(_a6_obj, 223u);
                _a6_obj->f__0 = l10;
                _a6_obj->f__1 = l5;
                l11 = (void*) _a6_obj;
                l12 = ((vader_struct___Tuple_2_cb60e7c5b39cd1d9_t*) l11)->f__0;
                l13 = ((vader_struct___Tuple_2_cb60e7c5b39cd1d9_t*) l11)->f__1;
                t2 = (l9 + INT64_C(1));
                l9 = (size_t) (int64_t) t2;
                std_collections_put__string__Any(l4, l12, vader_ref_box(l13));
                goto loop_34;
            }
        }
    }
    l5 = l1;
    l8 = ((vader_array_t*) l5)->length;
    l9 = (size_t) (int64_t) INT64_C(0);
    {
        loop_77: {
            if ((l9 < l8)) {
                vader_array_t* _a7_slotarr = ((vader_array_t*) l5);
                if (_a7_slotarr->buf != NULL && _a7_slotarr->buf->header.forward != NULL) { _a7_slotarr->buf = vader_array_buf_forward(_a7_slotarr->buf); }
                if ((size_t) l9 >= _a7_slotarr->length) { vader_trap("array index out of bounds"); }
                t1 = vader_array_box_slots(_a7_slotarr->buf)[_a7_slotarr->offset + (size_t) l9];
                l10 = t1.payload.s;
                l14 = std_collections_get__string__Any(l0, l10);
                if (l14.tag == 0u) {
                    t2 = (l9 + INT64_C(1));
                    l9 = (size_t) (int64_t) t2;
                    goto loop_77;
                }
                l6 = l14.payload.obj;
                l15 = std_collections_get__string__Any(l2, l10);
                l7 = ((vader_struct_vader_resolver_CollectedModule_t*) ((vader_struct_vader_resolver_LoadedModule_t*) l6)->f_collected)->f_symbols;
                l11 = ((vader_struct_std_collections_MutableMap__string__Symbol_t*) l7)->f_ekeys;
                l13 = ((vader_struct_std_collections_MutableMap__string__Symbol_t*) l7)->f_evals;
                l16 = ((vader_struct_std_collections_MutableMap__string__Symbol_t*) l7)->f_size;
                l17 = (size_t) (int64_t) INT64_C(0);
                {
                    loop_119: {
                        if ((l17 >= l16)) {
                        } else {
                            vader_array_t* _a8_slotarr = ((vader_array_t*) l11);
                            if (_a8_slotarr->buf != NULL && _a8_slotarr->buf->header.forward != NULL) { _a8_slotarr->buf = vader_array_buf_forward(_a8_slotarr->buf); }
                            if ((size_t) l17 >= _a8_slotarr->length) { vader_trap("array index out of bounds"); }
                            t1 = vader_array_box_slots(_a8_slotarr->buf)[_a8_slotarr->offset + (size_t) l17];
                            l12 = t1.payload.s;
                            vader_array_t* _a9_slotarr = ((vader_array_t*) l13);
                            if (_a9_slotarr->buf != NULL && _a9_slotarr->buf->header.forward != NULL) { _a9_slotarr->buf = vader_array_buf_forward(_a9_slotarr->buf); }
                            if ((size_t) l17 >= _a9_slotarr->length) { vader_trap("array index out of bounds"); }
                            l18 = vader_array_ref_load_obj(_a9_slotarr->buf, _a9_slotarr->offset + (size_t) l17);
                            vader_struct___Tuple_2_cb60e7c5b39cd1d9_t* _a10_obj = (vader_struct___Tuple_2_cb60e7c5b39cd1d9_t*) vader_gc_alloc(sizeof(vader_struct___Tuple_2_cb60e7c5b39cd1d9_t));
                            vader_obj_header_init(_a10_obj, 223u);
                            _a10_obj->f__0 = l12;
                            _a10_obj->f__1 = l18;
                            t3 = (void*) _a10_obj;
                            l19 = ((vader_struct___Tuple_2_cb60e7c5b39cd1d9_t*) t3)->f__1;
                            t2 = (l17 + INT64_C(1));
                            l17 = (size_t) (int64_t) t2;
                            t4 = vader_resolver_wildcard_exposable(((vader_struct_vader_resolver_symbol_Symbol_t*) l19)->f_kind);
                            if (!(t4)) {
                                goto loop_119;
                            }
                            if (((vader_struct_vader_resolver_symbol_Symbol_t*) l19)->f_visibility != INT32_C(0)) {
                                goto loop_119;
                            }
                            if (!(l15.tag == 0u)) {
                                l21 = l15.payload.obj;
                                l22 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l19)->f_name;
                                l20 = std_core____Contains_contains__string(l21, l22);
                            } else {
                                l20 = false;
                            }
                            if (l20) {
                                goto loop_119;
                            }
                            l23 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l19)->f_name;
                            t1 = std_collections_get__string__Any(l4, l23);
                            if (t1.tag == 0u) {
                                l24 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l19)->f_name;
                                std_collections_put__string__Any(l4, l24, vader_ref_box(l19));
                            }
                            goto loop_119;
                        }
                    }
                }
                t2 = (l9 + INT64_C(1));
                l9 = (size_t) (int64_t) t2;
                goto loop_77;
            }
        }
    }
    { void* __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_resolver_builtin_type_names(void) {
    void* l0 = NULL;
    void* l1 = NULL;
    size_t l2, l3;
    vader_string_t l4 = 0;
    void* t0 = NULL;
    int64_t t1;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t2 };
    void** gc_raw_roots[3] = { &l0, &l1, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 169u);
    l0 = (void*) _a0_arr;
    l1 = (void*) &vader_data_10;
    l2 = ((vader_array_t*) l1)->length;
    l3 = (size_t) (int64_t) INT64_C(0);
    {
        loop_9: {
            if ((l3 < l2)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l3 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l3);
                l4 = ((vader_struct_vader_types_PrimitiveMeta_t*) t0)->f_name;
                vader_array_push((vader_array_t*) l0, vader_box_string(169u, l4));
                t1 = (l3 + INT64_C(1));
                l3 = (size_t) (int64_t) t1;
                goto loop_9;
            }
        }
    }
    l1 = (void*) &vader_data_11;
    l2 = ((vader_array_t*) l1)->length;
    l3 = (size_t) (int64_t) INT64_C(0);
    {
        loop_38: {
            if ((l3 < l2)) {
                vader_array_t* _a2_slotarr = ((vader_array_t*) l1);
                if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                if ((size_t) l3 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l3);
                vader_array_t* _a3_slotarr = ((vader_array_t*) t0);
                if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                if ((size_t) INT32_C(0) >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                t2 = vader_array_box_slots(_a3_slotarr->buf)[_a3_slotarr->offset + (size_t) INT32_C(0)];
                l4 = t2.payload.s;
                vader_array_push((vader_array_t*) l0, vader_box_string(169u, l4));
                t1 = (l3 + INT64_C(1));
                l3 = (size_t) (int64_t) t1;
                goto loop_38;
            }
        }
    }
    l1 = (void*) &vader_data_6;
    l2 = ((vader_array_t*) l1)->length;
    l3 = (size_t) (int64_t) INT64_C(0);
    {
        loop_68: {
            if ((l3 < l2)) {
                vader_array_t* _a4_slotarr = ((vader_array_t*) l1);
                if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                if ((size_t) l3 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                t2 = vader_array_box_slots(_a4_slotarr->buf)[_a4_slotarr->offset + (size_t) l3];
                l4 = t2.payload.s;
                vader_array_push((vader_array_t*) l0, vader_box_string(169u, l4));
                t1 = (l3 + INT64_C(1));
                l3 = (size_t) (int64_t) t1;
                goto loop_68;
            }
        }
    }
    { void* __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void vader_resolver_check_groups(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l17 = NULL;
    void* l21 = NULL;
    void* l23 = NULL;
    void* l25 = NULL;
    void* l26 = NULL;
    void* l27 = NULL;
    void* l28 = NULL;
    void* l34 = NULL;
    void* l35 = NULL;
    void* l41 = NULL;
    void* l42 = NULL;
    void* l43 = NULL;
    size_t l6, l7, l8, l9, l14, l15, l24;
    vader_box_t l10 = vader_box_null(), l11 = vader_box_null(), l13 = vader_box_null(), l32 = vader_box_null();
    vader_string_t l12 = 0;
    vader_string_t l16 = 0;
    vader_string_t l18 = 0;
    vader_string_t l19 = 0;
    vader_string_t l20 = 0;
    vader_string_t l22 = 0;
    vader_string_t l30 = 0;
    vader_string_t l31 = 0;
    vader_string_t l33 = 0;
    vader_string_t l36 = 0;
    vader_string_t l37 = 0;
    vader_string_t l38 = 0;
    vader_string_t l39 = 0;
    vader_string_t l40 = 0;
    uint8_t l29;
    void* t0 = NULL;
    int64_t t1;
    bool t2;
    vader_box_t t3 = vader_box_null();
    vader_box_t* gc_roots[5] = { &l10, &l11, &l13, &l32, &t3 };
    void** gc_raw_roots[19] = { &l0, &l1, &l2, &l3, &l4, &l5, &l17, &l21, &l23, &l25, &l26, &l27, &l28, &l34, &l35, &l41, &l42, &l43, &t0 };
    vader_string_t* gc_atom_roots[14] = { &l12, &l16, &l18, &l19, &l20, &l22, &l30, &l31, &l33, &l36, &l37, &l38, &l39, &l40 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 5u, 19u, gc_roots, gc_raw_roots, 0u, NULL, 14u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 169u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(16u, 0u, 0u, 180u);
    l3 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 172u);
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
    vader_array_t* _a4_arr = vader_array_new(8u, 0u, 0u, 169u);
    l3 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_new(16u, 0u, 0u, 180u);
    l4 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(9u, 0u, 7u, 172u);
    l5 = (void*) _a6_arr;
    vader_struct_std_collections_MutableMap__string__Any_t* _a7_obj = (vader_struct_std_collections_MutableMap__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__Any_t));
    vader_obj_header_init(_a7_obj, 321u);
    _a7_obj->f_ekeys = l3;
    _a7_obj->f_evals = l4;
    _a7_obj->f_index = l5;
    _a7_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a7_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a7_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l3 = (void*) _a7_obj;
    l4 = l0;
    l6 = ((vader_array_t*) l4)->length;
    l7 = (size_t) (int64_t) INT64_C(0);
    {
        loop_35: {
            if ((l7 < l6)) {
                vader_array_t* _a8_slotarr = ((vader_array_t*) l4);
                if (_a8_slotarr->buf != NULL && _a8_slotarr->buf->header.forward != NULL) { _a8_slotarr->buf = vader_array_buf_forward(_a8_slotarr->buf); }
                if ((size_t) l7 >= _a8_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_ref_load_obj(_a8_slotarr->buf, _a8_slotarr->offset + (size_t) l7);
                l5 = ((vader_struct_toolchain_ast_Program_t*) ((vader_struct_vader_resolver_SourceFile_t*) t0)->f_program)->f_decls;
                l8 = ((vader_array_t*) l5)->length;
                l9 = (size_t) (int64_t) INT64_C(0);
                {
                    loop_51: {
                        if ((l9 < l8)) {
                            vader_array_t* _a9_slotarr = ((vader_array_t*) l5);
                            if (_a9_slotarr->buf != NULL && _a9_slotarr->buf->header.forward != NULL) { _a9_slotarr->buf = vader_array_buf_forward(_a9_slotarr->buf); }
                            if ((size_t) l9 >= _a9_slotarr->length) { vader_trap("array index out of bounds"); }
                            l10 = vader_array_ref_load_box(_a9_slotarr->buf, _a9_slotarr->offset + (size_t) l9);
                            if (l10.tag == 421u) {
                                t0 = l10.payload.obj;
                                l11 = vader_resolver_target_selectors(((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_decorators);
                                if (l11.tag == 0u) {
                                    t1 = (l9 + INT64_C(1));
                                    l9 = (size_t) (int64_t) t1;
                                    goto loop_51;
                                }
                                t0 = l11.payload.obj;
                                t2 = ((vader_struct_vader_resolver_TargetSelectors_t*) t0)->f_is_bare;
                                if (!(t2)) {
                                    t1 = (l9 + INT64_C(1));
                                    l9 = (size_t) (int64_t) t1;
                                    goto loop_51;
                                }
                                t0 = l10.payload.obj;
                                l12 = ((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_name;
                                l13 = std_collections_get__string__Any(l2, l12);
                                if (!(l13.tag == 0u)) {
                                    t0 = l13.payload.obj;
                                    l14 = ((vader_array_t*) ((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_params)->length;
                                    t0 = l10.payload.obj;
                                    l15 = ((vader_array_t*) ((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_params)->length;
                                    if (l14 != l15) {
                                        l16 = 212u;
                                    } else {
                                        l16 = 0u;
                                    }
                                    t0 = l10.payload.obj;
                                    l17 = ((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_name_span;
                                    t0 = l10.payload.obj;
                                    l18 = ((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_name;
                                    t0 = l13.payload.obj;
                                    l19 = vader_resolver_span_origin(((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_name_span);
                                    l20 = concat_5(930u, l18, 979u, l19, l16);
                                    l21 = vader_diagnostics_resolver_error((uint8_t) (int32_t) INT32_C(38), l17, l20);
                                    vader_array_push((vader_array_t*) l1, vader_ref_box(l21));
                                    t1 = (l9 + INT64_C(1));
                                    l9 = (size_t) (int64_t) t1;
                                    goto loop_51;
                                }
                                t0 = l10.payload.obj;
                                l22 = ((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_name;
                                l23 = l10.payload.obj;
                                std_collections_put__string__Any(l2, l22, vader_ref_box(l23));
                                l24 = (size_t) (int64_t) INT64_C(1);
                                t1 = (l9 + l24);
                                l9 = (size_t) (int64_t) t1;
                                goto loop_51;
                            }
                            l24 = (size_t) (int64_t) INT64_C(1);
                            t1 = (l9 + l24);
                            l9 = (size_t) (int64_t) t1;
                            goto loop_51;
                        }
                    }
                }
                t1 = (l7 + INT64_C(1));
                l7 = (size_t) (int64_t) t1;
                goto loop_35;
            }
        }
    }
    l4 = l0;
    l6 = ((vader_array_t*) l4)->length;
    l7 = (size_t) (int64_t) INT64_C(0);
    {
        loop_199: {
            if ((l7 < l6)) {
                vader_array_t* _a10_slotarr = ((vader_array_t*) l4);
                if (_a10_slotarr->buf != NULL && _a10_slotarr->buf->header.forward != NULL) { _a10_slotarr->buf = vader_array_buf_forward(_a10_slotarr->buf); }
                if ((size_t) l7 >= _a10_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_ref_load_obj(_a10_slotarr->buf, _a10_slotarr->offset + (size_t) l7);
                l5 = ((vader_struct_toolchain_ast_Program_t*) ((vader_struct_vader_resolver_SourceFile_t*) t0)->f_program)->f_decls;
                l8 = ((vader_array_t*) l5)->length;
                l9 = (size_t) (int64_t) INT64_C(0);
                {
                    loop_215: {
                        if ((l9 < l8)) {
                            vader_array_t* _a11_slotarr = ((vader_array_t*) l5);
                            if (_a11_slotarr->buf != NULL && _a11_slotarr->buf->header.forward != NULL) { _a11_slotarr->buf = vader_array_buf_forward(_a11_slotarr->buf); }
                            if ((size_t) l9 >= _a11_slotarr->length) { vader_trap("array index out of bounds"); }
                            l10 = vader_array_ref_load_box(_a11_slotarr->buf, _a11_slotarr->offset + (size_t) l9);
                            if (l10.tag == 421u) {
                                t0 = l10.payload.obj;
                                l11 = vader_resolver_target_selectors(((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_decorators);
                                if (l11.tag == 0u) {
                                    t1 = (l9 + INT64_C(1));
                                    l9 = (size_t) (int64_t) t1;
                                    goto loop_215;
                                }
                                t0 = l11.payload.obj;
                                t2 = ((vader_struct_vader_resolver_TargetSelectors_t*) t0)->f_is_bare;
                                if (t2) {
                                    t1 = (l9 + INT64_C(1));
                                    l9 = (size_t) (int64_t) t1;
                                    goto loop_215;
                                }
                                t0 = l10.payload.obj;
                                l12 = ((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_name;
                                l13 = std_collections_get__string__Any(l2, l12);
                                if (l13.tag == 0u) {
                                    t0 = l10.payload.obj;
                                    l17 = ((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_name_span;
                                    t0 = l10.payload.obj;
                                    l16 = ((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_name;
                                    l18 = concat_3(930u, l16, 962u);
                                    l21 = vader_diagnostics_resolver_error((uint8_t) (int32_t) INT32_C(35), l17, l18);
                                    vader_array_push((vader_array_t*) l1, vader_ref_box(l21));
                                } else {
                                    l23 = l13.payload.obj;
                                    l25 = l10.payload.obj;
                                    vader_resolver_check_signature(l23, l25, l1);
                                }
                                t0 = l10.payload.obj;
                                if (((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_visibility == INT32_C(0)) {
                                    t0 = l10.payload.obj;
                                    l26 = ((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_name_span;
                                    t0 = l10.payload.obj;
                                    l19 = ((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_name;
                                    l20 = concat_3(930u, l19, 975u);
                                    l27 = vader_diagnostics_resolver_error((uint8_t) (int32_t) INT32_C(36), l26, l20);
                                    vader_array_push((vader_array_t*) l1, vader_ref_box(l27));
                                }
                                t0 = l11.payload.obj;
                                l28 = ((vader_struct_vader_resolver_TargetSelectors_t*) t0)->f_os;
                                l14 = ((vader_array_t*) l28)->length;
                                l15 = (size_t) (int64_t) INT64_C(0);
                                {
                                    loop_333: {
                                        if ((l15 < l14)) {
                                            vader_array_t* _a12_slotarr = ((vader_array_t*) l28);
                                            if (_a12_slotarr->buf != NULL && _a12_slotarr->buf->header.forward != NULL) { _a12_slotarr->buf = vader_array_buf_forward(_a12_slotarr->buf); }
                                            if ((size_t) l15 >= _a12_slotarr->length) { vader_trap("array index out of bounds"); }
                                            t3 = vader_array_read_u8(_a12_slotarr, _a12_slotarr->offset + (size_t) l15, 175u);
                                            l29 = ((uint8_t) t3.payload.i);
                                            t0 = l10.payload.obj;
                                            l22 = ((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_name;
                                            if (l29 == INT32_C(0)) {
                                                l30 = 2407u;
                                            } else {
                                                if (l29 == INT32_C(1)) {
                                                    l30 = 1811u;
                                                } else {
                                                    if (l29 == INT32_C(2)) {
                                                        l30 = 1430u;
                                                    } else {
                                                        if (l29 == INT32_C(3)) {
                                                            l30 = 2400u;
                                                        } else {
                                                            if (l29 == INT32_C(4)) {
                                                                l30 = 1286u;
                                                            } else {
                                                                { vader_gc_top = gc_frame.prev; return; }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                            l31 = concat_3(l22, 2431u, l30);
                                            l32 = std_collections_get__string__Any(l3, l31);
                                            if (!(l32.tag == 0u)) {
                                                l34 = l32.payload.obj;
                                                t0 = l10.payload.obj;
                                                l35 = ((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_name_span;
                                                t2 = toolchain_span_Span_Equals_equals(l34, l35);
                                                if (t2) {
                                                    t0 = l10.payload.obj;
                                                    l36 = ((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_name;
                                                    if (l29 == INT32_C(0)) {
                                                        l37 = 2407u;
                                                    } else {
                                                        if (l29 == INT32_C(1)) {
                                                            l37 = 1811u;
                                                        } else {
                                                            if (l29 == INT32_C(2)) {
                                                                l37 = 1430u;
                                                            } else {
                                                                if (l29 == INT32_C(3)) {
                                                                    l37 = 2400u;
                                                                } else {
                                                                    if (l29 == INT32_C(4)) {
                                                                        l37 = 1286u;
                                                                    } else {
                                                                        { vader_gc_top = gc_frame.prev; return; }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                    l33 = concat_5(930u, l36, 1001u, l37, 1024u);
                                                } else {
                                                    t0 = l10.payload.obj;
                                                    l38 = ((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_name;
                                                    if (l29 == INT32_C(0)) {
                                                        l39 = 2407u;
                                                    } else {
                                                        if (l29 == INT32_C(1)) {
                                                            l39 = 1811u;
                                                        } else {
                                                            if (l29 == INT32_C(2)) {
                                                                l39 = 1430u;
                                                            } else {
                                                                if (l29 == INT32_C(3)) {
                                                                    l39 = 2400u;
                                                                } else {
                                                                    if (l29 == INT32_C(4)) {
                                                                        l39 = 1286u;
                                                                    } else {
                                                                        { vader_gc_top = gc_frame.prev; return; }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                    t0 = l32.payload.obj;
                                                    l40 = vader_resolver_span_origin(t0);
                                                    l33 = concat_6(930u, l38, 940u, l39, 945u, l40);
                                                }
                                                t0 = l10.payload.obj;
                                                l41 = ((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_name_span;
                                                l42 = vader_diagnostics_resolver_error((uint8_t) (int32_t) INT32_C(37), l41, l33);
                                                vader_array_push((vader_array_t*) l1, vader_ref_box(l42));
                                            } else {
                                                t0 = l10.payload.obj;
                                                l43 = ((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_name_span;
                                                std_collections_put__string__Any(l3, l31, vader_ref_box(l43));
                                            }
                                            t1 = (l15 + INT64_C(1));
                                            l15 = (size_t) (int64_t) t1;
                                            goto loop_333;
                                        }
                                    }
                                }
                            }
                            t1 = (l9 + INT64_C(1));
                            l9 = (size_t) (int64_t) t1;
                            goto loop_215;
                        }
                    }
                }
                t1 = (l7 + INT64_C(1));
                l7 = (size_t) (int64_t) t1;
                goto loop_199;
            }
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_resolver_check_import_form_conflict(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l13 = NULL;
    void* l15 = NULL;
    void* l17 = NULL;
    void* l20 = NULL;
    void* l22 = NULL;
    size_t l6, l7;
    vader_box_t l8 = vader_box_null(), l9 = vader_box_null();
    vader_string_t l10 = 0;
    vader_string_t l11 = 0;
    vader_string_t l12 = 0;
    vader_string_t l14 = 0;
    vader_string_t l16 = 0;
    vader_string_t l18 = 0;
    vader_string_t l19 = 0;
    vader_string_t l21 = 0;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    int64_t t2;
    vader_box_t* gc_roots[3] = { &l8, &l9, &t1 };
    void** gc_raw_roots[12] = { &l0, &l1, &l2, &l3, &l4, &l5, &l13, &l15, &l17, &l20, &l22, &t0 };
    vader_string_t* gc_atom_roots[8] = { &l10, &l11, &l12, &l14, &l16, &l18, &l19, &l21 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 12u, gc_roots, gc_raw_roots, 0u, NULL, 8u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 169u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(16u, 0u, 0u, 180u);
    l3 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 172u);
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
    vader_array_t* _a4_arr = vader_array_new(8u, 0u, 0u, 169u);
    l3 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_new(16u, 0u, 0u, 180u);
    l4 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(9u, 0u, 7u, 172u);
    l5 = (void*) _a6_arr;
    vader_struct_std_collections_MutableMap__string__Any_t* _a7_obj = (vader_struct_std_collections_MutableMap__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__Any_t));
    vader_obj_header_init(_a7_obj, 321u);
    _a7_obj->f_ekeys = l3;
    _a7_obj->f_evals = l4;
    _a7_obj->f_index = l5;
    _a7_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a7_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a7_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l3 = (void*) _a7_obj;
    l4 = l0;
    l6 = ((vader_array_t*) l4)->length;
    l7 = (size_t) (int64_t) INT64_C(0);
    {
        loop_35: {
            if ((l7 < l6)) {
                vader_array_t* _a8_slotarr = ((vader_array_t*) l4);
                if (_a8_slotarr->buf != NULL && _a8_slotarr->buf->header.forward != NULL) { _a8_slotarr->buf = vader_array_buf_forward(_a8_slotarr->buf); }
                if ((size_t) l7 >= _a8_slotarr->length) { vader_trap("array index out of bounds"); }
                l8 = vader_array_ref_load_box(_a8_slotarr->buf, _a8_slotarr->offset + (size_t) l7);
                if (l8.tag == 431u) {
                    t0 = l8.payload.obj;
                    l9 = ((vader_struct_toolchain_ast_ImportDecl_t*) t0)->f_binding;
                    if (l9.tag == 478u) {
                        t0 = l8.payload.obj;
                        l10 = ((vader_struct_toolchain_ast_ImportDecl_t*) t0)->f_path;
                        t1 = std_collections_get__string__Any(l3, l10);
                        if (!(t1.tag == 0u)) {
                            t0 = l8.payload.obj;
                            l5 = ((vader_struct_toolchain_ast_ImportDecl_t*) t0)->f_span;
                            t0 = l8.payload.obj;
                            l11 = ((vader_struct_toolchain_ast_ImportDecl_t*) t0)->f_path;
                            l12 = concat_3(930u, l11, 930u);
                            l13 = vader_diagnostics_resolver_error((uint8_t) (int32_t) INT32_C(31), l5, l12);
                            vader_array_push((vader_array_t*) l1, vader_ref_box(l13));
                        }
                        t0 = l8.payload.obj;
                        l14 = ((vader_struct_toolchain_ast_ImportDecl_t*) t0)->f_path;
                        t0 = l8.payload.obj;
                        l15 = ((vader_struct_toolchain_ast_ImportDecl_t*) t0)->f_span;
                        std_collections_put__string__Any(l2, l14, vader_ref_box(l15));
                    } else {
                        if (l9.tag == 411u) {
                            t0 = l8.payload.obj;
                            l16 = ((vader_struct_toolchain_ast_ImportDecl_t*) t0)->f_path;
                            t1 = std_collections_get__string__Any(l2, l16);
                            if (!(t1.tag == 0u)) {
                                t0 = l8.payload.obj;
                                l17 = ((vader_struct_toolchain_ast_ImportDecl_t*) t0)->f_span;
                                t0 = l8.payload.obj;
                                l18 = ((vader_struct_toolchain_ast_ImportDecl_t*) t0)->f_path;
                                l19 = concat_3(930u, l18, 930u);
                                l20 = vader_diagnostics_resolver_error((uint8_t) (int32_t) INT32_C(31), l17, l19);
                                vader_array_push((vader_array_t*) l1, vader_ref_box(l20));
                            }
                            t0 = l8.payload.obj;
                            l21 = ((vader_struct_toolchain_ast_ImportDecl_t*) t0)->f_path;
                            t0 = l8.payload.obj;
                            l22 = ((vader_struct_toolchain_ast_ImportDecl_t*) t0)->f_span;
                            std_collections_put__string__Any(l3, l21, vader_ref_box(l22));
                        } else {
                        }
                    }
                }
                t2 = (l7 + INT64_C(1));
                l7 = (size_t) (int64_t) t2;
                goto loop_35;
            }
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_resolver_check_orphan_rule(void* l0, vader_string_t l1, void* l2, void* l3, void* l4, void* l5) {
    void* l6 = NULL;
    vader_box_t l7 = vader_box_null();
    bool l8, l9, l10;
    vader_string_t l11 = 0;
    vader_string_t l12 = 0;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    vader_box_t* gc_roots[1] = { &l7 };
    void** gc_raw_roots[7] = { &l0, &l2, &l3, &l4, &l5, &l6, &t0 };
    vader_string_t* gc_atom_roots[4] = { &l1, &l11, &l12, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l7 = vader_resolver_lookup_trait_sym(l0, l2, l4);
    if (l7.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l6 = l7.payload.obj;
    if (((vader_struct_vader_resolver_symbol_Symbol_t*) l6)->f_kind != INT32_C(3)) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l7 = vader_resolver_for_type_owner_sym(((vader_struct_toolchain_ast_ImplDecl_t*) l0)->f_for_type, l3, l4);
    l8 = false;
    l9 = false;
    if (l7.tag == 889u) {
        t0 = l7.payload.obj;
        l8 = ((vader_struct_vader_resolver_symbol_Symbol_t*) t0)->f_kind == INT32_C(12);
        t0 = l7.payload.obj;
        t1 = ((vader_struct_vader_resolver_symbol_Symbol_t*) t0)->f_module;
        l9 = t1 == l1;
    }
    t1 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l6)->f_module;
    l10 = t1 == l1;
    if (!(l8)) {
        l8 = !(l9);
    } else {
        l8 = false;
    }
    if (l8) {
        l8 = !(l10);
    } else {
        l8 = false;
    }
    if (l8) {
        l6 = ((vader_struct_toolchain_ast_ImplDecl_t*) l0)->f_span;
        l11 = ((vader_struct_toolchain_ast_ImplDecl_t*) l0)->f_trait_name;
        l12 = vader_resolver_for_type_display_name(((vader_struct_toolchain_ast_ImplDecl_t*) l0)->f_for_type);
        l11 = concat_4(l11, 116u, l12, 217u);
        l6 = vader_diagnostics_resolver_error((uint8_t) (int32_t) INT32_C(17), l6, l11);
        vader_array_push((vader_array_t*) l5, vader_ref_box(l6));
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_resolver_check_selectors(void* l0, void* l1) {
    void* l2 = NULL;
    void* l5 = NULL;
    void* l9 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    void* l17 = NULL;
    void* l20 = NULL;
    void* l21 = NULL;
    void* l23 = NULL;
    size_t l3, l4, l6, l7, l10, l11, l14, l15;
    vader_box_t l8 = vader_box_null(), l16 = vader_box_null();
    vader_string_t l18 = 0;
    vader_string_t l19 = 0;
    vader_string_t l22 = 0;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    vader_string_t t3 = 0;
    int64_t t2;
    vader_box_t t4 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l8, &l16, &t4 };
    void** gc_raw_roots[12] = { &l0, &l1, &l2, &l5, &l9, &l12, &l13, &l17, &l20, &l21, &l23, &t0 };
    vader_string_t* gc_atom_roots[5] = { &l18, &l19, &l22, &t1, &t3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 12u, gc_roots, gc_raw_roots, 0u, NULL, 5u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = l0;
    l3 = ((vader_array_t*) l2)->length;
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_7: {
            if ((l4 < l3)) {
                vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
                if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                if ((size_t) l4 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
                l5 = ((vader_struct_toolchain_ast_Program_t*) ((vader_struct_vader_resolver_SourceFile_t*) t0)->f_program)->f_decls;
                l6 = ((vader_array_t*) l5)->length;
                l7 = (size_t) (int64_t) INT64_C(0);
                {
                    loop_23: {
                        if ((l7 < l6)) {
                            vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
                            if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                            if ((size_t) l7 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                            l8 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l7);
                            if (l8.tag == 421u) {
                                t0 = l8.payload.obj;
                                l9 = ((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_decorators;
                                l10 = ((vader_array_t*) l9)->length;
                                l11 = (size_t) (int64_t) INT64_C(0);
                                {
                                    loop_43: {
                                        if ((l11 < l10)) {
                                            vader_array_t* _a2_slotarr = ((vader_array_t*) l9);
                                            if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                                            if ((size_t) l11 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                                            l12 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l11);
                                            t1 = ((vader_struct_toolchain_ast_Decorator_t*) l12)->f_name;
                                            if (t1 != 2143u) {
                                                t2 = (l11 + INT64_C(1));
                                                l11 = (size_t) (int64_t) t2;
                                                goto loop_43;
                                            }
                                            l13 = ((vader_struct_toolchain_ast_Decorator_t*) l12)->f_args;
                                            l14 = ((vader_array_t*) l13)->length;
                                            l15 = (size_t) (int64_t) INT64_C(0);
                                            {
                                                loop_70: {
                                                    if ((l15 < l14)) {
                                                        vader_array_t* _a3_slotarr = ((vader_array_t*) l13);
                                                        if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                                                        if ((size_t) l15 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                                                        l16 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l15);
                                                        if (l16.tag == 414u) {
                                                            t0 = l16.payload.obj;
                                                            t1 = ((vader_struct_toolchain_ast_DotVariantExpr_t*) t0)->f_variant;
                                                            t3 = std_string_to_lower(t1);
                                                            t4 = vader_target_parse_os(t3);
                                                            if (t4.tag == 0u) {
                                                                t0 = l16.payload.obj;
                                                                l17 = ((vader_struct_toolchain_ast_DotVariantExpr_t*) t0)->f_span;
                                                                t0 = l16.payload.obj;
                                                                l18 = ((vader_struct_toolchain_ast_DotVariantExpr_t*) t0)->f_variant;
                                                                l19 = concat_3(1071u, l18, 1010u);
                                                                l20 = vader_diagnostics_resolver_error((uint8_t) (int32_t) INT32_C(34), l17, l19);
                                                                vader_array_push((vader_array_t*) l1, vader_ref_box(l20));
                                                            }
                                                        } else {
                                                            t0 = l16.payload.obj;
                                                            l21 = ((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t0)->f_span;
                                                            l22 = concat_2(1153u, 2416u);
                                                            l23 = vader_diagnostics_resolver_error((uint8_t) (int32_t) INT32_C(34), l21, l22);
                                                            vader_array_push((vader_array_t*) l1, vader_ref_box(l23));
                                                        }
                                                        t2 = (l15 + INT64_C(1));
                                                        l15 = (size_t) (int64_t) t2;
                                                        goto loop_70;
                                                    }
                                                }
                                            }
                                            t2 = (l11 + INT64_C(1));
                                            l11 = (size_t) (int64_t) t2;
                                            goto loop_43;
                                        }
                                    }
                                }
                            }
                            t2 = (l7 + INT64_C(1));
                            l7 = (size_t) (int64_t) t2;
                            goto loop_23;
                        }
                    }
                }
                t2 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t2;
                goto loop_7;
            }
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_resolver_check_signature(void* l0, void* l1, void* l2) {
    size_t l3, l4, l13, l14, l15, l16, l17, l18;
    void* l5 = NULL;
    void* l8 = NULL;
    void* l22 = NULL;
    vader_string_t l6 = 0;
    vader_string_t l7 = 0;
    vader_string_t l10 = 0;
    vader_string_t l11 = 0;
    vader_string_t l12 = 0;
    vader_string_t l19 = 0;
    vader_string_t l20 = 0;
    vader_string_t l21 = 0;
    uint64_t l9;
    int64_t t0;
    size_t t1;
    void* t2 = NULL;
    void** gc_raw_roots[7] = { &l0, &l1, &l2, &l5, &l8, &l22, &t2 };
    vader_string_t* gc_atom_roots[8] = { &l6, &l7, &l10, &l11, &l12, &l19, &l20, &l21 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 7u, NULL, gc_raw_roots, 0u, NULL, 8u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l3 = ((vader_array_t*) ((vader_struct_toolchain_ast_FnDecl_t*) l0)->f_params)->length;
    l4 = ((vader_array_t*) ((vader_struct_toolchain_ast_FnDecl_t*) l1)->f_params)->length;
    if (l3 != l4) {
        l5 = ((vader_struct_toolchain_ast_FnDecl_t*) l1)->f_name_span;
        l6 = ((vader_struct_toolchain_ast_FnDecl_t*) l1)->f_name;
        l7 = vader_resolver_span_origin(((vader_struct_toolchain_ast_FnDecl_t*) l0)->f_name_span);
        l3 = vader_host_std_core_byte_len(l6);
        l4 = vader_host_std_core_byte_len(l7);
        t0 = (l3 + l4);
        l3 = (size_t) (int64_t) t0;
        l8 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(48) + l3));
        l3 = (size_t) (int64_t) INT64_C(0);
        l3 = std_core_write_string_at(l8, l3, 930u);
        l3 = std_core_write_string_at(l8, l3, l6);
        l3 = std_core_write_string_at(l8, l3, 1023u);
        t1 = ((vader_array_t*) ((vader_struct_toolchain_ast_FnDecl_t*) l0)->f_params)->length;
        t0 = ((int64_t) (size_t) t1);
        l9 = (uint64_t) (int64_t) t0;
        l3 = std_core_write_unsigned(l8, l3, l9);
        l3 = std_core_write_string_at(l8, l3, 160u);
        l3 = std_core_write_string_at(l8, l3, l7);
        l3 = std_core_write_string_at(l8, l3, 371u);
        l6 = std_core_finish_buffer(l8, l3);
        l8 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(36));
        l3 = (size_t) (int64_t) INT64_C(0);
        l3 = std_core_write_string_at(l8, l3, 2155u);
        t1 = ((vader_array_t*) ((vader_struct_toolchain_ast_FnDecl_t*) l1)->f_params)->length;
        t0 = ((int64_t) (size_t) t1);
        l9 = (uint64_t) (int64_t) t0;
        l3 = std_core_write_unsigned(l8, l3, l9);
        l7 = std_core_finish_buffer(l8, l3);
        l6 = concat_2(l6, l7);
        l5 = vader_diagnostics_resolver_error((uint8_t) (int32_t) INT32_C(39), l5, l6);
        vader_array_push((vader_array_t*) l2, vader_ref_box(l5));
        { vader_gc_top = gc_frame.prev; return; }
    }
    l3 = ((vader_array_t*) ((vader_struct_toolchain_ast_FnDecl_t*) l0)->f_params)->length;
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_121: {
            if ((l4 < l3)) {
                vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_FnDecl_t*) l0)->f_params);
                if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                if ((size_t) l4 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                t2 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
                l6 = ((vader_struct_toolchain_ast_FnParam_t*) t2)->f_name;
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_FnDecl_t*) l1)->f_params);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l4 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                t2 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
                l7 = ((vader_struct_toolchain_ast_FnParam_t*) t2)->f_name;
                if (l6 != l7) {
                    vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_FnDecl_t*) l1)->f_params);
                    if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                    if ((size_t) l4 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                    t2 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
                    l5 = ((vader_struct_toolchain_ast_FnParam_t*) t2)->f_span;
                    l10 = ((vader_struct_toolchain_ast_FnDecl_t*) l1)->f_name;
                    l11 = l6;
                    l12 = vader_resolver_span_origin(((vader_struct_toolchain_ast_FnDecl_t*) l0)->f_name_span);
                    l13 = vader_host_std_core_byte_len(l10);
                    l14 = vader_host_std_core_byte_len(l11);
                    t0 = (l13 + l14);
                    l15 = (size_t) (int64_t) t0;
                    l16 = vader_host_std_core_byte_len(l12);
                    t0 = (l15 + l16);
                    l17 = (size_t) (int64_t) t0;
                    l8 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(48) + l17));
                    l18 = (size_t) (int64_t) INT64_C(0);
                    l18 = std_core_write_string_at(l8, l18, 1940u);
                    t0 = (l4 + INT64_C(1));
                    l9 = (uint64_t) (int64_t) t0;
                    l18 = std_core_write_unsigned(l8, l18, l9);
                    l18 = std_core_write_string_at(l8, l18, 148u);
                    l18 = std_core_write_string_at(l8, l18, l10);
                    l18 = std_core_write_string_at(l8, l18, 972u);
                    l18 = std_core_write_string_at(l8, l18, l11);
                    l18 = std_core_write_string_at(l8, l18, 945u);
                    l18 = std_core_write_string_at(l8, l18, l12);
                    l18 = std_core_write_string_at(l8, l18, 371u);
                    l19 = std_core_finish_buffer(l8, l18);
                    l20 = concat_3(930u, l7, 967u);
                    l21 = concat_3(l19, l20, 1397u);
                    l22 = vader_diagnostics_resolver_error((uint8_t) (int32_t) INT32_C(39), l5, l21);
                    vader_array_push((vader_array_t*) l2, vader_ref_box(l22));
                }
                t0 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                goto loop_121;
            }
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_resolver_check_target_selectors(void* l0, void* l1) {
    void* l2 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    size_t l3, l4;
    vader_box_t l5 = vader_box_null();
    vader_string_t l8 = 0;
    vader_string_t l9 = 0;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    vader_string_t t2 = 0;
    vader_box_t t3 = vader_box_null();
    int64_t t4;
    vader_box_t* gc_roots[2] = { &l5, &t3 };
    void** gc_raw_roots[10] = { &l0, &l1, &l2, &l6, &l7, &l10, &l11, &l12, &l13, &t0 };
    vader_string_t* gc_atom_roots[4] = { &l8, &l9, &t1, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 10u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_toolchain_ast_Decorator_t*) l1)->f_args;
    l3 = ((vader_array_t*) l2)->length;
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_7: {
            if ((l4 < l3)) {
                vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
                if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                if ((size_t) l4 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                l5 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
                if (l5.tag == 414u) {
                    t0 = l5.payload.obj;
                    t1 = ((vader_struct_toolchain_ast_DotVariantExpr_t*) t0)->f_variant;
                    t2 = std_string_to_lower(t1);
                    t3 = vader_target_parse_os(t2);
                    if (t3.tag == 0u) {
                        l6 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_diags;
                        t0 = l5.payload.obj;
                        l7 = ((vader_struct_toolchain_ast_DotVariantExpr_t*) t0)->f_span;
                        t0 = l5.payload.obj;
                        l8 = ((vader_struct_toolchain_ast_DotVariantExpr_t*) t0)->f_variant;
                        l9 = concat_3(1071u, l8, 1010u);
                        l10 = vader_diagnostics_resolver_error((uint8_t) (int32_t) INT32_C(34), l7, l9);
                        vader_array_push((vader_array_t*) l6, vader_ref_box(l10));
                    }
                } else {
                    l11 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_diags;
                    t0 = l5.payload.obj;
                    l12 = ((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t0)->f_span;
                    l13 = vader_diagnostics_resolver_error((uint8_t) (int32_t) INT32_C(34), l12, 1506u);
                    vader_array_push((vader_array_t*) l11, vader_ref_box(l13));
                }
                t4 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t4;
                goto loop_7;
            }
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_resolver_check_wildcard_ambiguity(void* l0, void* l1, void* l2) {
    vader_string_t l3 = 0;
    vader_string_t l4 = 0;
    vader_string_t l10 = 0;
    void* l5 = NULL;
    void* l9 = NULL;
    vader_box_t l6 = vader_box_null();
    size_t l7, l8;
    vader_box_t t0 = vader_box_null();
    int64_t t1;
    vader_box_t* gc_roots[2] = { &l6, &t0 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l5, &l9 };
    vader_string_t* gc_atom_roots[3] = { &l3, &l4, &l10 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l2)->f_module;
    l4 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_module_path;
    if (l3 == l4) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l5 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_ambiguous;
    l3 = ((vader_struct_toolchain_ast_IdentExpr_t*) l1)->f_name;
    l6 = std_collections_get__string__Any(l5, l3);
    if (l6.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l5 = l6.payload.obj;
    l3 = 0u;
    l7 = ((vader_array_t*) l5)->length;
    l8 = (size_t) (int64_t) INT64_C(0);
    {
        loop_36: {
            if ((l8 < l7)) {
                if ((l8 > INT64_C(0))) {
                    l3 = concat_2(l3, 371u);
                }
                vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
                if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                if ((size_t) l8 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l8];
                l4 = t0.payload.s;
                l3 = concat_2(l3, l4);
                t1 = (l8 + INT64_C(1));
                l8 = (size_t) (int64_t) t1;
                goto loop_36;
            }
        }
    }
    l5 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_diags;
    l9 = ((vader_struct_toolchain_ast_IdentExpr_t*) l1)->f_span;
    l4 = ((vader_struct_toolchain_ast_IdentExpr_t*) l1)->f_name;
    l10 = ((vader_struct_toolchain_ast_IdentExpr_t*) l1)->f_name;
    l3 = concat_7(930u, l4, 984u, l3, 219u, l10, 1054u);
    l9 = vader_diagnostics_resolver_error((uint8_t) (int32_t) INT32_C(30), l9, l3);
    vader_array_push((vader_array_t*) l5, vader_ref_box(l9));
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_resolver_clone_ident(void* l0) {
    void* l1 = NULL;
    vader_string_t l2 = 0;
    bool l3, l4;
    void* t0 = NULL;
    void** gc_raw_roots[3] = { &l0, &l1, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct_toolchain_ast_IdentExpr_t*) l0)->f_span;
    l2 = ((vader_struct_toolchain_ast_IdentExpr_t*) l0)->f_name;
    l3 = ((vader_struct_toolchain_ast_IdentExpr_t*) l0)->f_implicit_dot;
    l4 = ((vader_struct_toolchain_ast_IdentExpr_t*) l0)->f_is_type_param_intro;
    vader_struct_toolchain_ast_IdentExpr_t* _a0_obj = (vader_struct_toolchain_ast_IdentExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_IdentExpr_t));
    vader_obj_header_init(_a0_obj, 426u);
    _a0_obj->f_span = l1;
    _a0_obj->f_id = (size_t) (int64_t) INT64_C(0);
    _a0_obj->f_name = l2;
    _a0_obj->f_implicit_dot = l3;
    _a0_obj->f_is_type_param_intro = l4;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_box_t vader_resolver_clone_let_binding(vader_box_t l0) {
    void* l1 = NULL;
    void* l3 = NULL;
    vader_string_t l2 = 0;
    size_t l4, l5;
    vader_box_t l6 = vader_box_null();
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    int64_t t2;
    vader_box_t* gc_roots[3] = { &l0, &l6, &t1 };
    void** gc_raw_roots[3] = { &l1, &l3, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    if (l0.tag == 459u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_toolchain_ast_SimpleBinding_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast_SimpleBinding_t*) t0)->f_name;
        t0 = l0.payload.obj;
        l3 = ((vader_struct_toolchain_ast_SimpleBinding_t*) t0)->f_name_span;
        vader_struct_toolchain_ast_SimpleBinding_t* _a0_obj = (vader_struct_toolchain_ast_SimpleBinding_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_SimpleBinding_t));
        vader_obj_header_init(_a0_obj, 459u);
        _a0_obj->f_span = l1;
        _a0_obj->f_id = (size_t) (int64_t) INT64_C(0);
        _a0_obj->f_name = l2;
        _a0_obj->f_name_span = l3;
        t0 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 471u) {
        vader_array_t* _a1_arr = vader_array_new(118u, 0u, 13u, 1079u);
        l1 = (void*) _a1_arr;
        t0 = l0.payload.obj;
        l3 = ((vader_struct_toolchain_ast_TupleBinding_t*) t0)->f_elements;
        l4 = ((vader_array_t*) l3)->length;
        l5 = (size_t) (int64_t) INT64_C(0);
        {
            loop_37: {
                if ((l5 < l4)) {
                    vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
                    if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                    if ((size_t) l5 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                    t1 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l5);
                    l6 = vader_resolver_clone_let_binding(t1);
                    vader_array_push((vader_array_t*) l1, l6);
                    t2 = (l5 + INT64_C(1));
                    l5 = (size_t) (int64_t) t2;
                    goto loop_37;
                }
            }
        }
        t0 = l0.payload.obj;
        vader_struct_toolchain_ast_TupleBinding_t* _a3_obj = (vader_struct_toolchain_ast_TupleBinding_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_TupleBinding_t));
        vader_obj_header_init(_a3_obj, 471u);
        _a3_obj->f_span = ((vader_struct_toolchain_ast_TupleBinding_t*) t0)->f_span;
        _a3_obj->f_id = (size_t) (int64_t) INT64_C(0);
        _a3_obj->f_elements = l1;
        t0 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 477u) {
        t0 = l0.payload.obj;
        vader_struct_toolchain_ast_WildcardBinding_t* _a4_obj = (vader_struct_toolchain_ast_WildcardBinding_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_WildcardBinding_t));
        vader_obj_header_init(_a4_obj, 477u);
        _a4_obj->f_span = ((vader_struct_toolchain_ast_WildcardBinding_t*) t0)->f_span;
        _a4_obj->f_id = (size_t) (int64_t) INT64_C(0);
        t0 = (void*) _a4_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 456u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_toolchain_ast_RestBinding_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast_RestBinding_t*) t0)->f_name;
        t0 = l0.payload.obj;
        l3 = ((vader_struct_toolchain_ast_RestBinding_t*) t0)->f_name_span;
        vader_struct_toolchain_ast_RestBinding_t* _a5_obj = (vader_struct_toolchain_ast_RestBinding_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_RestBinding_t));
        vader_obj_header_init(_a5_obj, 456u);
        _a5_obj->f_span = l1;
        _a5_obj->f_id = (size_t) (int64_t) INT64_C(0);
        _a5_obj->f_name = l2;
        _a5_obj->f_name_span = l3;
        t0 = (void*) _a5_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_unreachable("unreachable return in vader_resolver$clone_let_binding");
    vader_gc_top = gc_frame.prev;
}

static void vader_resolver_collect_decl(void* l0, vader_box_t l1, vader_string_t l2, vader_string_t l3, void* l4, void* l5, void* l6, void* l7) {
    void* l8 = NULL;
    vader_string_t l9 = 0;
    uint8_t l10;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[7] = { &l0, &l4, &l5, &l6, &l7, &l8, &t0 };
    vader_string_t* gc_atom_roots[3] = { &l2, &l3, &l9 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    if (l1.tag == 431u) {
        l8 = l1.payload.obj;
        vader_resolver_collect_import(l0, l8, l2, l3, l4, l5, l6, l7);
    } else {
        if (l1.tag == 421u) {
            l8 = l1.payload.obj;
            vader_resolver_add_fn(l0, l8, l2, l3, l4, l7);
        } else {
            if (l1.tag == 463u) {
                t0 = l1.payload.obj;
                l9 = ((vader_struct_toolchain_ast_StructDecl_t*) t0)->f_name;
                t0 = l1.payload.obj;
                l8 = ((vader_struct_toolchain_ast_StructDecl_t*) t0)->f_name_span;
                t0 = l1.payload.obj;
                l10 = ((vader_struct_toolchain_ast_StructDecl_t*) t0)->f_visibility;
                vader_resolver_add_named(l0, INT32_C(1), l9, l8, l10, l2, l3, l4, l7);
            } else {
                if (l1.tag == 415u) {
                    t0 = l1.payload.obj;
                    l9 = ((vader_struct_toolchain_ast_EnumDecl_t*) t0)->f_name;
                    t0 = l1.payload.obj;
                    l8 = ((vader_struct_toolchain_ast_EnumDecl_t*) t0)->f_name_span;
                    t0 = l1.payload.obj;
                    l10 = ((vader_struct_toolchain_ast_EnumDecl_t*) t0)->f_visibility;
                    vader_resolver_add_named(l0, INT32_C(2), l9, l8, l10, l2, l3, l4, l7);
                } else {
                    if (l1.tag == 470u) {
                        t0 = l1.payload.obj;
                        l9 = ((vader_struct_toolchain_ast_TraitDecl_t*) t0)->f_name;
                        t0 = l1.payload.obj;
                        l8 = ((vader_struct_toolchain_ast_TraitDecl_t*) t0)->f_name_span;
                        t0 = l1.payload.obj;
                        l10 = ((vader_struct_toolchain_ast_TraitDecl_t*) t0)->f_visibility;
                        vader_resolver_add_named(l0, INT32_C(3), l9, l8, l10, l2, l3, l4, l7);
                    } else {
                        if (l1.tag == 473u) {
                            t0 = l1.payload.obj;
                            l9 = ((vader_struct_toolchain_ast_TypeAliasDecl_t*) t0)->f_name;
                            t0 = l1.payload.obj;
                            l8 = ((vader_struct_toolchain_ast_TypeAliasDecl_t*) t0)->f_name_span;
                            t0 = l1.payload.obj;
                            l10 = ((vader_struct_toolchain_ast_TypeAliasDecl_t*) t0)->f_visibility;
                            vader_resolver_add_named(l0, INT32_C(5), l9, l8, l10, l2, l3, l4, l7);
                        } else {
                            if (l1.tag == 405u) {
                                t0 = l1.payload.obj;
                                l9 = ((vader_struct_toolchain_ast_ConstDecl_t*) t0)->f_name;
                                t0 = l1.payload.obj;
                                l8 = ((vader_struct_toolchain_ast_ConstDecl_t*) t0)->f_name_span;
                                t0 = l1.payload.obj;
                                l10 = ((vader_struct_toolchain_ast_ConstDecl_t*) t0)->f_visibility;
                                vader_resolver_add_named(l0, INT32_C(6), l9, l8, l10, l2, l3, l4, l7);
                            } else {
                                if (l1.tag == 430u) {
                                } else {
                                    if (l1.tag == 393u) {
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
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_resolver_collect_files(void* l0, vader_string_t l1, vader_string_t l2, void* l3, void* l4, void* l5, void* l6) {
    void* l7 = NULL;
    void* l10 = NULL;
    size_t l8, l9;
    void* t0 = NULL;
    int64_t t1;
    void** gc_raw_roots[8] = { &l0, &l3, &l4, &l5, &l6, &l7, &l10, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l1, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 8u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    if ((size_t) INT32_C(0) >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
    t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT32_C(0));
    l7 = vader_resolver_collect_module(((vader_struct_vader_resolver_SourceFile_t*) t0)->f_program, l1, l2, l3, l4, l5, l6);
    l8 = ((vader_array_t*) l0)->length;
    l9 = (size_t) (int64_t) INT64_C(1);
    {
        loop_18: {
            if ((l9 < l8)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l9 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l9);
                l10 = vader_resolver_collect_module(((vader_struct_vader_resolver_SourceFile_t*) t0)->f_program, l1, l2, l3, l4, l5, l6);
                vader_resolver_merge_collected(l7, l10, l6);
                t1 = (l9 + INT64_C(1));
                l9 = (size_t) (int64_t) t1;
                goto loop_18;
            }
        }
    }
    { void* __vret = l7; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void vader_resolver_collect_import(void* l0, void* l1, vader_string_t l2, vader_string_t l3, void* l4, void* l5, void* l6, void* l7) {
    void* l8 = NULL;
    void* l12 = NULL;
    void* l15 = NULL;
    void* l16 = NULL;
    void* l17 = NULL;
    void* l20 = NULL;
    vader_string_t l9 = 0;
    vader_string_t l11 = 0;
    vader_string_t l18 = 0;
    vader_string_t l19 = 0;
    vader_string_t l21 = 0;
    vader_string_t l22 = 0;
    vader_box_t l10 = vader_box_null();
    size_t l13, l14;
    vader_string_t t0 = 0;
    void* t1 = NULL;
    size_t t2;
    int64_t t3;
    vader_box_t* gc_roots[1] = { &l10 };
    void** gc_raw_roots[13] = { &l0, &l1, &l4, &l5, &l6, &l7, &l8, &l12, &l15, &l16, &l17, &l20, &t1 };
    vader_string_t* gc_atom_roots[9] = { &l2, &l3, &l9, &l11, &l18, &l19, &l21, &l22, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 13u, gc_roots, gc_raw_roots, 0u, NULL, 9u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_toolchain_ast_ImportDecl_t*) l1)->f_path;
    if (t0 == 0u) {
        l8 = ((vader_struct_toolchain_ast_ImportDecl_t*) l1)->f_span;
        l8 = vader_diagnostics_resolver_error((uint8_t) (int32_t) INT32_C(1), l8, 0u);
        vader_array_push((vader_array_t*) l7, vader_ref_box(l8));
    } else {
        l8 = ((vader_struct_vader_resolver_CollectedModule_t*) l0)->f_import_paths;
        l9 = ((vader_struct_toolchain_ast_ImportDecl_t*) l1)->f_path;
        vader_array_push((vader_array_t*) l8, vader_box_string(169u, l9));
        l9 = ((vader_struct_toolchain_ast_ImportDecl_t*) l1)->f_path;
        l8 = ((vader_struct_toolchain_ast_ImportDecl_t*) l1)->f_span;
        vader_resolver_diagnose_import_path(l9, l8, l3, l5, l6, l7);
    }
    l10 = ((vader_struct_toolchain_ast_ImportDecl_t*) l1)->f_binding;
    if (l10.tag == 446u) {
        t1 = l10.payload.obj;
        l9 = ((vader_struct_toolchain_ast_NamedNamespaceImport_t*) t1)->f_name;
        l8 = ((vader_struct_toolchain_ast_ImportDecl_t*) l1)->f_span;
        l11 = ((vader_struct_toolchain_ast_ImportDecl_t*) l1)->f_path;
        vader_resolver_bind_import(l0, l9, l8, l11, vader_box_obj(0u, NULL), l2, l4, l7);
    } else {
        if (l10.tag == 478u) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_resolver_CollectedModule_t*) l0)->f_wildcards);
            if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
            if ((size_t) INT32_C(0) >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
            t1 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT32_C(0));
            l8 = ((vader_struct_vader_resolver_FileWildcards_t*) t1)->f_paths;
            l9 = ((vader_struct_toolchain_ast_ImportDecl_t*) l1)->f_path;
            vader_array_push((vader_array_t*) l8, vader_box_string(169u, l9));
        } else {
            if (l10.tag == 411u) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_resolver_CollectedModule_t*) l0)->f_wildcards);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) INT32_C(0) >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                t1 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) INT32_C(0));
                l8 = ((vader_struct_vader_resolver_FileWildcards_t*) t1)->f_paths;
                l9 = ((vader_struct_toolchain_ast_ImportDecl_t*) l1)->f_path;
                vader_array_push((vader_array_t*) l8, vader_box_string(169u, l9));
                t1 = l10.payload.obj;
                t2 = ((vader_array_t*) ((vader_struct_toolchain_ast_DestructureImport_t*) t1)->f_names)->length;
                if (t2 == INT64_C(0)) {
                    l8 = ((vader_struct_toolchain_ast_ImportDecl_t*) l1)->f_span;
                    l9 = ((vader_struct_toolchain_ast_ImportDecl_t*) l1)->f_path;
                    l9 = concat_3(930u, l9, 930u);
                    l8 = vader_diagnostics_warning((uint8_t) (int32_t) INT32_C(7), l8, l9);
                    vader_array_push((vader_array_t*) l7, vader_ref_box(l8));
                }
                vader_array_t* _a2_arr = vader_array_new(8u, 0u, 0u, 169u);
                l8 = (void*) _a2_arr;
                t1 = l10.payload.obj;
                l12 = ((vader_struct_toolchain_ast_DestructureImport_t*) t1)->f_names;
                l13 = ((vader_array_t*) l12)->length;
                l14 = (size_t) (int64_t) INT64_C(0);
                {
                    loop_128: {
                        if ((l14 < l13)) {
                            vader_array_t* _a3_slotarr = ((vader_array_t*) l12);
                            if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                            if ((size_t) l14 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                            l15 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l14);
                            l10 = ((vader_struct_toolchain_ast_ImportName_t*) l15)->f_alias;
                            if (l10.tag == 0u) {
                                l16 = ((vader_struct_toolchain_ast_ImportName_t*) l15)->f_span;
                                l9 = ((vader_struct_toolchain_ast_ImportName_t*) l15)->f_name;
                                l11 = concat_3(930u, l9, 930u);
                                l17 = vader_diagnostics_resolver_error((uint8_t) (int32_t) INT32_C(32), l16, l11);
                                vader_array_push((vader_array_t*) l7, vader_ref_box(l17));
                            } else {
                                if (l10.tag == 169u) {
                                    l18 = l10.payload.s;
                                    l19 = ((vader_struct_toolchain_ast_ImportName_t*) l15)->f_name;
                                    vader_array_push((vader_array_t*) l8, vader_box_string(169u, l19));
                                    if (l18 != 869u) {
                                        l20 = ((vader_struct_toolchain_ast_ImportName_t*) l15)->f_span;
                                        l21 = ((vader_struct_toolchain_ast_ImportDecl_t*) l1)->f_path;
                                        l22 = ((vader_struct_toolchain_ast_ImportName_t*) l15)->f_name;
                                        vader_resolver_bind_import(l0, l18, l20, l21, vader_box_string(169u, l22), l2, l4, l7);
                                    }
                                } else {
                                    { vader_gc_top = gc_frame.prev; return; }
                                }
                            }
                            t3 = (l14 + INT64_C(1));
                            l14 = (size_t) (int64_t) t3;
                            goto loop_128;
                        }
                    }
                }
                vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_vader_resolver_CollectedModule_t*) l0)->f_wildcards);
                if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                if ((size_t) INT32_C(0) >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                t1 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) INT32_C(0));
                l12 = ((vader_struct_vader_resolver_FileWildcards_t*) t1)->f_excludes;
                l9 = ((vader_struct_toolchain_ast_ImportDecl_t*) l1)->f_path;
                std_collections_put__string__Any(l12, l9, vader_ref_box(l8));
            } else {
                { vader_gc_top = gc_frame.prev; return; }
            }
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_resolver_collect_module(void* l0, vader_string_t l1, vader_string_t l2, void* l3, void* l4, void* l5, void* l6) {
    void* l7 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    void* l15 = NULL;
    vader_string_t l11 = 0;
    size_t l16, l17;
    vader_box_t l18 = vader_box_null();
    void* t0 = NULL;
    int64_t t1;
    vader_box_t* gc_roots[1] = { &l18 };
    void** gc_raw_roots[14] = { &l0, &l3, &l4, &l5, &l6, &l7, &l8, &l9, &l10, &l12, &l13, &l14, &l15, &t0 };
    vader_string_t* gc_atom_roots[3] = { &l1, &l2, &l11 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 14u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 169u);
    l7 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(16u, 0u, 0u, 180u);
    l8 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 172u);
    l9 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__string__Any_t* _a3_obj = (vader_struct_std_collections_MutableMap__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__Any_t));
    vader_obj_header_init(_a3_obj, 321u);
    _a3_obj->f_ekeys = l7;
    _a3_obj->f_evals = l8;
    _a3_obj->f_index = l9;
    _a3_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l7 = (void*) _a3_obj;
    vader_array_t* _a4_arr = vader_array_new(8u, 0u, 0u, 169u);
    l8 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_new(16u, 0u, 0u, 180u);
    l9 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(9u, 0u, 7u, 172u);
    l10 = (void*) _a6_arr;
    vader_struct_std_collections_MutableMap__string__Any___t* _a7_obj = (vader_struct_std_collections_MutableMap__string__Any___t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__Any___t));
    vader_obj_header_init(_a7_obj, 323u);
    _a7_obj->f_ekeys = l8;
    _a7_obj->f_evals = l9;
    _a7_obj->f_index = l10;
    _a7_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a7_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a7_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l8 = (void*) _a7_obj;
    l9 = vader_resolver_new_import_table();
    vader_array_t* _a8_arr = vader_array_new(8u, 0u, 0u, 169u);
    l10 = (void*) _a8_arr;
    l11 = ((vader_struct_toolchain_ast_Program_t*) l0)->f_file;
    vader_array_t* _a9_arr = vader_array_new(8u, 0u, 0u, 169u);
    l12 = (void*) _a9_arr;
    vader_array_t* _a10_arr = vader_array_new(8u, 0u, 0u, 169u);
    l13 = (void*) _a10_arr;
    vader_array_t* _a11_arr = vader_array_new(16u, 0u, 0u, 180u);
    l14 = (void*) _a11_arr;
    vader_array_t* _a12_arr = vader_array_new(9u, 0u, 7u, 172u);
    l15 = (void*) _a12_arr;
    vader_struct_std_collections_MutableMap__string__Any___t* _a13_obj = (vader_struct_std_collections_MutableMap__string__Any___t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__Any___t));
    vader_obj_header_init(_a13_obj, 323u);
    _a13_obj->f_ekeys = l13;
    _a13_obj->f_evals = l14;
    _a13_obj->f_index = l15;
    _a13_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a13_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a13_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l13 = (void*) _a13_obj;
    vader_struct_vader_resolver_FileWildcards_t* _a14_obj = (vader_struct_vader_resolver_FileWildcards_t*) vader_gc_alloc(sizeof(vader_struct_vader_resolver_FileWildcards_t));
    vader_obj_header_init(_a14_obj, 871u);
    _a14_obj->f_file = l11;
    _a14_obj->f_paths = l12;
    _a14_obj->f_excludes = l13;
    t0 = (void*) _a14_obj;
    vader_array_t* _a15_arr = vader_array_new(82u, 1u, 13u, 871u);
    ((void**) _a15_arr->buf->slots)[_a15_arr->offset + 0u] = t0;
    l12 = (void*) _a15_arr;
    vader_struct_vader_resolver_CollectedModule_t* _a16_obj = (vader_struct_vader_resolver_CollectedModule_t*) vader_gc_alloc(sizeof(vader_struct_vader_resolver_CollectedModule_t));
    vader_obj_header_init(_a16_obj, 869u);
    _a16_obj->f_symbols = l7;
    _a16_obj->f_fn_overloads = l8;
    _a16_obj->f_imports = l9;
    _a16_obj->f_import_paths = l10;
    _a16_obj->f_wildcards = l12;
    l7 = (void*) _a16_obj;
    vader_resolver_check_import_form_conflict(((vader_struct_toolchain_ast_Program_t*) l0)->f_decls, l6);
    l8 = ((vader_struct_toolchain_ast_Program_t*) l0)->f_decls;
    l16 = ((vader_array_t*) l8)->length;
    l17 = (size_t) (int64_t) INT64_C(0);
    {
        loop_74: {
            if ((l17 < l16)) {
                vader_array_t* _a17_slotarr = ((vader_array_t*) l8);
                if (_a17_slotarr->buf != NULL && _a17_slotarr->buf->header.forward != NULL) { _a17_slotarr->buf = vader_array_buf_forward(_a17_slotarr->buf); }
                if ((size_t) l17 >= _a17_slotarr->length) { vader_trap("array index out of bounds"); }
                l18 = vader_array_ref_load_box(_a17_slotarr->buf, _a17_slotarr->offset + (size_t) l17);
                vader_resolver_collect_decl(l7, l18, l1, l2, l3, l4, l5, l6);
                t1 = (l17 + INT64_C(1));
                l17 = (size_t) (int64_t) t1;
                goto loop_74;
            }
        }
    }
    { void* __vret = l7; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_resolver_collect_module_no_index(void* l0, vader_string_t l1, void* l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[6] = { &l0, &l2, &l3, &l4, &l5, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 6u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 169u);
    l3 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(16u, 0u, 0u, 180u);
    l4 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 172u);
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
    vader_array_t* _a4_arr = vader_array_new(51u, 0u, 13u, 700u);
    l4 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_new(84u, 0u, 13u, 875u);
    l5 = (void*) _a5_arr;
    t0 = vader_resolver_collect_module(l0, l1, l1, l2, l3, l5, l4);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

void* vader_resolver_concat_file_decls(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l5 = NULL;
    size_t l3, l4, l6, l7;
    vader_box_t l8 = vader_box_null();
    size_t t0;
    void* t1 = NULL;
    int64_t t2;
    vader_box_t* gc_roots[1] = { &l8 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l5, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) l0)->length;
    if (t0 == INT64_C(1)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
        if ((size_t) INT32_C(0) >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
        t1 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT32_C(0));
        { void* __vret = ((vader_struct_toolchain_ast_Program_t*) ((vader_struct_vader_resolver_SourceFile_t*) t1)->f_program)->f_decls; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a1_arr = vader_array_new(114u, 0u, 13u, 1047u);
    l1 = (void*) _a1_arr;
    l2 = l0;
    l3 = ((vader_array_t*) l2)->length;
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_21: {
            if ((l4 < l3)) {
                vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
                if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                if ((size_t) l4 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                t1 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
                l5 = ((vader_struct_toolchain_ast_Program_t*) ((vader_struct_vader_resolver_SourceFile_t*) t1)->f_program)->f_decls;
                l6 = ((vader_array_t*) l5)->length;
                l7 = (size_t) (int64_t) INT64_C(0);
                {
                    loop_37: {
                        if ((l7 < l6)) {
                            vader_array_t* _a3_slotarr = ((vader_array_t*) l5);
                            if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                            if ((size_t) l7 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                            l8 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l7);
                            vader_array_push((vader_array_t*) l1, l8);
                            t2 = (l7 + INT64_C(1));
                            l7 = (size_t) (int64_t) t2;
                            goto loop_37;
                        }
                    }
                }
                t2 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t2;
                goto loop_21;
            }
        }
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static size_t vader_resolver_count_sam_synthetics(void* l0) {
    size_t l1, l3, l4;
    void* l2;
    void* t0;
    bool t1;
    int64_t t2;
    l1 = (size_t) (int64_t) INT64_C(0);
    l2 = l0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    l3 = ((vader_array_t*) l2)->length;
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_9: {
            if ((l4 < l3)) {
                if ((size_t) l4 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
                t1 = ((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_sam_synthetic;
                if (t1) {
                    t2 = (l1 + INT64_C(1));
                    l1 = (size_t) (int64_t) t2;
                }
                t2 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t2;
                goto loop_9;
            }
        }
    }
    return l1;
}

static void vader_resolver_detect_import_cycles(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    size_t l7, l8;
    vader_string_t l9 = 0;
    vader_string_t l10 = 0;
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    int64_t t2;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[8] = { &l0, &l1, &l2, &l3, &l4, &l5, &l6, &t1 };
    vader_struct___Tuple_2_122be429df783e3b_t _a6_storage = {0};
    void* gc_stack_objs[1] = { (void*) &_a6_storage };
    vader_string_t* gc_atom_roots[2] = { &l9, &l10 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 8u, gc_roots, gc_raw_roots, 1u, gc_stack_objs, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 169u);
    l3 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(9u, 0u, 7u, 172u);
    l4 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 172u);
    l5 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__string__i32_t* _a3_obj = (vader_struct_std_collections_MutableMap__string__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__i32_t));
    vader_obj_header_init(_a3_obj, 360u);
    _a3_obj->f_ekeys = l3;
    _a3_obj->f_evals = l4;
    _a3_obj->f_index = l5;
    _a3_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l3 = (void*) _a3_obj;
    l4 = l0;
    l5 = ((vader_struct_std_collections_MutableMap__string__LoadedModule_t*) l4)->f_ekeys;
    l6 = ((vader_struct_std_collections_MutableMap__string__LoadedModule_t*) l4)->f_evals;
    l7 = ((vader_struct_std_collections_MutableMap__string__LoadedModule_t*) l4)->f_size;
    l8 = (size_t) (int64_t) INT64_C(0);
    {
        loop_26: {
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
                vader_struct___Tuple_2_122be429df783e3b_t* _a7_obj = &_a6_storage;
                vader_obj_header_init(_a7_obj, 202u);
                _a7_obj->f__0 = l9;
                _a7_obj->f__1 = l4;
                t1 = (void*) _a7_obj;
                l10 = ((vader_struct___Tuple_2_122be429df783e3b_t*) t1)->f__0;
                t2 = (l8 + INT64_C(1));
                l8 = (size_t) (int64_t) t2;
                t0 = std_collections_get__string__i32(l3, l10);
                if (t0.tag == 0u) {
                    vader_resolver_walk_import_cycle(l10, l0, l1, l3, l2);
                }
                goto loop_26;
            }
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static vader_box_t vader_resolver_diagnose_import_path(vader_string_t l0, void* l1, vader_string_t l2, void* l3, void* l4, void* l5) {
    bool l6;
    vader_string_t l7 = 0;
    void* l8 = NULL;
    vader_box_t l9 = vader_box_null();
    bool t0;
    vader_box_t t1 = vader_box_null();
    uint8_t t2;
    size_t t3;
    void* t4 = NULL;
    vader_string_t t5 = 0;
    vader_box_t* gc_roots[2] = { &l9, &t1 };
    void** gc_raw_roots[6] = { &l1, &l3, &l4, &l5, &l8, &t4 };
    vader_string_t* gc_atom_roots[4] = { &l0, &l2, &l7, &t5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = std_string_starts_with(l0, 419u);
    if (t0) {
        l6 = true;
    } else {
        l6 = std_string_starts_with(l0, 416u);
    }
    if (l6) {
        l7 = concat_3(930u, l0, 930u);
        l8 = vader_diagnostics_resolver_error((uint8_t) (int32_t) INT32_C(24), l1, l7);
        vader_array_push((vader_array_t*) l5, vader_ref_box(l8));
        t1 = vader_box_obj(0u, NULL);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == l2) {
        l7 = concat_3(930u, l0, 930u);
        l8 = vader_diagnostics_resolver_error((uint8_t) (int32_t) INT32_C(23), l1, l7);
        vader_array_push((vader_array_t*) l5, vader_ref_box(l8));
        t1 = vader_box_obj(0u, NULL);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == 2043u) {
        l6 = l2 != 2043u;
    } else {
        l6 = false;
    }
    if (l6) {
        l8 = vader_diagnostics_resolver_error((uint8_t) (int32_t) INT32_C(27), l1, 0u);
        vader_array_push((vader_array_t*) l5, vader_ref_box(l8));
        t1 = vader_box_obj(0u, NULL);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = std_string_starts_with(l0, 2303u);
    if (t0) {
        t0 = std_string_starts_with(l2, 2303u);
        l6 = !(t0);
    } else {
        l6 = false;
    }
    if (l6) {
        l6 = l2 != 2163u;
    } else {
        l6 = false;
    }
    if (l6) {
        t2 = vader_resolver_importer_origin(l3, l2);
        l6 = t2 == INT32_C(1);
    } else {
        l6 = false;
    }
    if (l6) {
        l7 = concat_7(930u, l2, 999u, l0, 1038u, 2163u, 1002u);
        l8 = vader_diagnostics_resolver_error((uint8_t) (int32_t) INT32_C(33), l1, l7);
        vader_array_push((vader_array_t*) l5, vader_ref_box(l8));
        t1 = vader_box_obj(0u, NULL);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t3 = ((vader_struct_std_collections_MutableMap__string__DiscoveredModule_t*) l3)->f_size;
    if (t3 == INT64_C(0)) {
        t1 = vader_box_obj(0u, NULL);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l9 = std_collections_get__string__Any(l3, l0);
    if (l9.tag == 870u) {
        t4 = l9.payload.obj;
        t5 = ((vader_struct_vader_resolver_DiscoveredModule_t*) t4)->f_folder;
        t1 = vader_box_string(169u, t5);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l9.tag == 0u) {
        l9 = vader_resolver_misplaced_module_at(l0, l4);
        if (l9.tag == 0u) {
            l7 = concat_3(930u, l0, 930u);
            l8 = vader_diagnostics_resolver_error((uint8_t) (int32_t) INT32_C(0), l1, l7);
            vader_array_push((vader_array_t*) l5, vader_ref_box(l8));
        } else {
            l7 = l9.payload.s;
            l7 = concat_5(930u, l0, 1036u, l7, 233u);
            l8 = vader_diagnostics_resolver_error((uint8_t) (int32_t) INT32_C(0), l1, l7);
            vader_array_push((vader_array_t*) l5, vader_ref_box(l8));
        }
        t1 = vader_box_obj(0u, NULL);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_unreachable("unreachable return in vader_resolver$diagnose_import_path");
    vader_gc_top = gc_frame.prev;
}

static vader_string_t vader_resolver_dir_of(vader_string_t l0) {
    vader_string_t t0 = 0;
    vader_string_t t1 = 0;
    vader_string_t* gc_atom_roots[3] = { &l0, &t0, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 3u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = std_path_to_path(l0);
    t1 = std_path_parent(t0);
    t0 = std_path_as_string(t1);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_resolver_discarded_bodies(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l7 = NULL;
    void* l11 = NULL;
    size_t l5, l6, l8, l9, l12;
    vader_box_t l10 = vader_box_null();
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    int64_t t2;
    bool t3;
    vader_box_t* gc_roots[3] = { &l1, &l10, &t1 };
    void** gc_raw_roots[7] = { &l0, &l2, &l3, &l4, &l7, &l11, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 7u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(24u, 0u, 13u, 421u);
    l2 = (void*) _a0_arr;
    if (l1.tag == 0u) {
        { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = l1.payload.obj;
    vader_array_t* _a1_arr = vader_array_new(51u, 0u, 13u, 700u);
    l4 = (void*) _a1_arr;
    l3 = vader_resolver_select_target_bodies(l0, vader_ref_box(l3), l4);
    l4 = l0;
    l5 = ((vader_array_t*) l4)->length;
    l6 = (size_t) (int64_t) INT64_C(0);
    {
        loop_25: {
            if ((l6 < l5)) {
                vader_array_t* _a2_slotarr = ((vader_array_t*) l4);
                if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                if ((size_t) l6 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l6);
                l7 = ((vader_struct_toolchain_ast_Program_t*) ((vader_struct_vader_resolver_SourceFile_t*) t0)->f_program)->f_decls;
                l8 = ((vader_array_t*) l7)->length;
                l9 = (size_t) (int64_t) INT64_C(0);
                {
                    loop_41: {
                        if ((l9 < l8)) {
                            vader_array_t* _a3_slotarr = ((vader_array_t*) l7);
                            if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                            if ((size_t) l9 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                            l10 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l9);
                            if (l10.tag == 421u) {
                                t0 = l10.payload.obj;
                                t1 = vader_resolver_target_selectors(((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_decorators);
                                if (t1.tag == 0u) {
                                    t2 = (l9 + INT64_C(1));
                                    l9 = (size_t) (int64_t) t2;
                                    goto loop_41;
                                }
                                t0 = l10.payload.obj;
                                t3 = vader_resolver_body_survives(t0, l3);
                                if (t3) {
                                    t2 = (l9 + INT64_C(1));
                                    l9 = (size_t) (int64_t) t2;
                                    goto loop_41;
                                }
                                l11 = l10.payload.obj;
                                vader_array_push((vader_array_t*) l2, vader_ref_box(l11));
                                l12 = (size_t) (int64_t) INT64_C(1);
                                t2 = (l9 + l12);
                                l9 = (size_t) (int64_t) t2;
                                goto loop_41;
                            }
                            l12 = (size_t) (int64_t) INT64_C(1);
                            t2 = (l9 + l12);
                            l9 = (size_t) (int64_t) t2;
                            goto loop_41;
                        }
                    }
                }
                t2 = (l6 + INT64_C(1));
                l6 = (size_t) (int64_t) t2;
                goto loop_25;
            }
        }
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void vader_resolver_drain_load_queue(void* l0, void* l1, void* l2, void* l3, void* l4, void* l5, void* l6, void* l7, vader_box_t l8) {
    size_t l9, l10, l15, l16;
    void* l11 = NULL;
    void* l14 = NULL;
    void* l20 = NULL;
    vader_string_t l12 = 0;
    vader_string_t l17 = 0;
    vader_string_t l19 = 0;
    vader_box_t l13 = vader_box_null(), l18 = vader_box_null();
    int64_t t0;
    bool t1;
    void* t2 = NULL;
    vader_box_t t3 = vader_box_null();
    vader_box_t* gc_roots[4] = { &l8, &l13, &l18, &t3 };
    void** gc_raw_roots[12] = { &l0, &l1, &l2, &l3, &l4, &l5, &l6, &l7, &l11, &l14, &l20, &t2 };
    vader_string_t* gc_atom_roots[3] = { &l12, &l17, &l19 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 12u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l9 = (size_t) (int64_t) INT64_C(0);
    {
        loop_3: {
            l10 = ((vader_array_t*) l0)->length;
            if ((l9 < l10)) {
                vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
                if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                if ((size_t) l9 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                l11 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l9);
                t0 = (l9 + INT64_C(1));
                l9 = (size_t) (int64_t) t0;
                l12 = ((vader_struct_vader_resolver_DiscoveredModule_t*) l11)->f_folder;
                t1 = vader_resolver_has_module(l2, l12);
                if (t1) {
                    goto loop_3;
                }
                vader_resolver_ingest_module(l11, l1, l2, l3, l4, l5, l6, l7, l8);
                l13 = std_collections_get__string__Any(l2, l12);
                if (l13.tag == 0u) {
                } else {
                    if (l13.tag == 876u) {
                        t2 = l13.payload.obj;
                        l14 = ((vader_struct_vader_resolver_CollectedModule_t*) ((vader_struct_vader_resolver_LoadedModule_t*) t2)->f_collected)->f_import_paths;
                        l15 = ((vader_array_t*) l14)->length;
                        l16 = (size_t) (int64_t) INT64_C(0);
                        {
                            loop_58: {
                                if ((l16 < l15)) {
                                    vader_array_t* _a1_slotarr = ((vader_array_t*) l14);
                                    if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                                    if ((size_t) l16 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                                    t3 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l16];
                                    l17 = t3.payload.s;
                                    l18 = std_collections_get__string__Any(l4, l17);
                                    if (l18.tag == 870u) {
                                        t2 = l18.payload.obj;
                                        l19 = ((vader_struct_vader_resolver_DiscoveredModule_t*) t2)->f_folder;
                                        t1 = vader_resolver_has_module(l2, l19);
                                        if (!(t1)) {
                                            l20 = l18.payload.obj;
                                            vader_array_push((vader_array_t*) l0, vader_ref_box(l20));
                                        }
                                    } else {
                                    }
                                    t0 = (l16 + INT64_C(1));
                                    l16 = (size_t) (int64_t) t0;
                                    goto loop_58;
                                }
                            }
                        }
                    } else {
                        { vader_gc_top = gc_frame.prev; return; }
                    }
                }
                goto loop_3;
            }
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static vader_string_t vader_resolver_entry_folder_of(vader_string_t l0) {
    bool l1;
    vader_string_t l2 = 0;
    bool t0;
    vader_string_t* gc_atom_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = std_io_exists(l0);
    if (t0) {
        l1 = std_io_is_dir(l0);
    } else {
        l1 = false;
    }
    if (l1) {
        { vader_string_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = vader_resolver_dir_of(l0);
    if (l2 == 0u) {
        { vader_gc_top = gc_frame.prev; return 413u; }
    }
    { vader_string_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

vader_box_t vader_resolver_find_async_module_id(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    size_t l4, l5;
    vader_string_t l6 = 0;
    vader_string_t l7 = 0;
    bool l8;
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    int64_t t2;
    bool t3;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &t1 };
    vader_struct___Tuple_2_122be429df783e3b_t _a2_storage = {0};
    void* gc_stack_objs[1] = { (void*) &_a2_storage };
    vader_string_t* gc_atom_roots[2] = { &l6, &l7 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 1u, gc_stack_objs, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct_vader_resolver_LoadedProject_t*) l0)->f_modules;
    l2 = ((vader_struct_std_collections_MutableMap__string__LoadedModule_t*) l1)->f_ekeys;
    l3 = ((vader_struct_std_collections_MutableMap__string__LoadedModule_t*) l1)->f_evals;
    l4 = ((vader_struct_std_collections_MutableMap__string__LoadedModule_t*) l1)->f_size;
    l5 = (size_t) (int64_t) INT64_C(0);
    {
        loop_12: {
            if ((l5 >= l4)) {
                t0 = vader_box_obj(0u, NULL);
                { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
            }
            vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
            if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
            if ((size_t) l5 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
            t0 = vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l5];
            l6 = t0.payload.s;
            vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
            if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
            if ((size_t) l5 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
            l1 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5);
            vader_struct___Tuple_2_122be429df783e3b_t* _a3_obj = &_a2_storage;
            vader_obj_header_init(_a3_obj, 202u);
            _a3_obj->f__0 = l6;
            _a3_obj->f__1 = l1;
            t1 = (void*) _a3_obj;
            l7 = ((vader_struct___Tuple_2_122be429df783e3b_t*) t1)->f__0;
            t2 = (l5 + INT64_C(1));
            l5 = (size_t) (int64_t) t2;
            t3 = std_string_ends_with(l7, 2041u);
            if (t3) {
                l8 = true;
            } else {
                l8 = std_string_ends_with(l7, 2040u);
            }
            if (l8) {
                t0 = vader_box_string(169u, l7);
                { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
            }
            goto loop_12;
        }
    }
    t0 = vader_box_obj(0u, NULL);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

vader_box_t vader_resolver_find_core_module_id(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    size_t l4, l5;
    vader_string_t l6 = 0;
    vader_string_t l7 = 0;
    bool l8;
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    int64_t t2;
    bool t3;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &t1 };
    vader_struct___Tuple_2_122be429df783e3b_t _a2_storage = {0};
    void* gc_stack_objs[1] = { (void*) &_a2_storage };
    vader_string_t* gc_atom_roots[2] = { &l6, &l7 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 1u, gc_stack_objs, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct_vader_resolver_LoadedProject_t*) l0)->f_modules;
    l2 = ((vader_struct_std_collections_MutableMap__string__LoadedModule_t*) l1)->f_ekeys;
    l3 = ((vader_struct_std_collections_MutableMap__string__LoadedModule_t*) l1)->f_evals;
    l4 = ((vader_struct_std_collections_MutableMap__string__LoadedModule_t*) l1)->f_size;
    l5 = (size_t) (int64_t) INT64_C(0);
    {
        loop_12: {
            if ((l5 >= l4)) {
                t0 = vader_box_obj(0u, NULL);
                { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
            }
            vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
            if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
            if ((size_t) l5 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
            t0 = vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l5];
            l6 = t0.payload.s;
            vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
            if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
            if ((size_t) l5 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
            l1 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5);
            vader_struct___Tuple_2_122be429df783e3b_t* _a3_obj = &_a2_storage;
            vader_obj_header_init(_a3_obj, 202u);
            _a3_obj->f__0 = l6;
            _a3_obj->f__1 = l1;
            t1 = (void*) _a3_obj;
            l7 = ((vader_struct___Tuple_2_122be429df783e3b_t*) t1)->f__0;
            t2 = (l5 + INT64_C(1));
            l5 = (size_t) (int64_t) t2;
            t3 = std_string_ends_with(l7, 2044u);
            if (t3) {
                l8 = true;
            } else {
                l8 = std_string_ends_with(l7, 2043u);
            }
            if (l8) {
                t0 = vader_box_string(169u, l7);
                { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
            }
            goto loop_12;
        }
    }
    t0 = vader_box_obj(0u, NULL);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_box_t vader_resolver_find_manifest_root(vader_string_t l0) {
    vader_string_t l1 = 0;
    vader_string_t l2 = 0;
    bool t0;
    vader_string_t t1 = 0;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t2 };
    vader_string_t* gc_atom_roots[4] = { &l0, &l1, &l2, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 0u, gc_roots, NULL, 0u, NULL, 4u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l1 = l0;
    t0 = std_io_exists(l1);
    if (t0) {
        t0 = std_io_is_dir(l1);
        if (!(t0)) {
            l1 = vader_resolver_dir_of(l1);
        }
    } else {
        l1 = vader_resolver_dir_of(l1);
    }
    {
        loop_18: {
            t1 = vader_resolver_join_path(l1, 2301u);
            t0 = std_io_exists(t1);
            if (t0) {
                t2 = vader_box_string(169u, l1);
                { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
            }
            l2 = vader_resolver_dir_of(l1);
            if (l2 == l1) {
                t2 = vader_box_obj(0u, NULL);
                { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
            }
            l1 = l2;
            goto loop_18;
        }
    }
    t2 = vader_box_string(169u, l1);
    { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_string_t vader_resolver_for_type_display_name(vader_box_t l0) {
    void* t0;
    void* t2;
    vader_string_t t1;
    if (l0.tag == 426u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_toolchain_ast_IdentExpr_t*) t0)->f_name;
        return t1;
    }
    if (l0.tag == 425u) {
        t0 = l0.payload.obj;
        if (((vader_struct_toolchain_ast_GenericInstExpr_t*) t0)->f_callee.tag == 426u) {
            t0 = l0.payload.obj;
            t2 = ((vader_struct_toolchain_ast_GenericInstExpr_t*) t0)->f_callee.payload.obj;
            t1 = ((vader_struct_toolchain_ast_IdentExpr_t*) t2)->f_name;
            return t1;
        }
    }
    return 527u;
}

static vader_box_t vader_resolver_for_type_owner_sym(vader_box_t l0, void* l1, void* l2) {
    uint64_t l3;
    vader_box_t l4 = vader_box_null();
    void* t0 = NULL;
    void* t2 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l0, &l4, &t1 };
    void** gc_raw_roots[4] = { &l1, &l2, &t0, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 426u) {
        t0 = l0.payload.obj;
        l3 = toolchain_span_Span_Hash_hash(((vader_struct_toolchain_ast_IdentExpr_t*) t0)->f_span);
        l4 = std_collections_get__u64__Any(l1, l3);
        if (l4.tag == 0u) {
            t1 = vader_box_obj(0u, NULL);
            { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
        }
        t0 = l4.payload.obj;
        t2 = vader_resolver_resolve_import_redirect(t0, l2);
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 425u) {
        t0 = l0.payload.obj;
        if (((vader_struct_toolchain_ast_GenericInstExpr_t*) t0)->f_callee.tag == 426u) {
            t0 = l0.payload.obj;
            t2 = ((vader_struct_toolchain_ast_GenericInstExpr_t*) t0)->f_callee.payload.obj;
            l3 = toolchain_span_Span_Hash_hash(((vader_struct_toolchain_ast_IdentExpr_t*) t2)->f_span);
            l4 = std_collections_get__u64__Any(l1, l3);
            if (l4.tag == 0u) {
                t1 = vader_box_obj(0u, NULL);
                { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
            }
            t0 = l4.payload.obj;
            t2 = vader_resolver_resolve_import_redirect(t0, l2);
            { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    t1 = vader_box_obj(0u, NULL);
    { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static int32_t vader_resolver_frame_count(void* l0) {
    size_t t0;
    t0 = ((vader_array_t*) ((vader_struct_vader_resolver_Scope_t*) l0)->f_frames)->length;
    return ((int32_t) (size_t) t0);
}

static vader_string_t vader_resolver_generated_root_for(vader_box_t l0) {
    vader_string_t l1 = 0;
    bool t0;
    vader_box_t* gc_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 0u, gc_roots, NULL, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    if (l0.tag == 169u) {
        l1 = l0.payload.s;
    } else {
        if (l0.tag == 0u) {
            l1 = std_io_current_working_directory();
        } else {
            vader_unreachable("unreachable return in vader_resolver$generated_root_for");
        }
    }
    l1 = vader_resolver_join_path(l1, 1303u);
    t0 = std_io_is_dir(l1);
    if (!(t0)) {
        { vader_gc_top = gc_frame.prev; return 0u; }
    }
    { vader_string_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_resolver_graft_body(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l6 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    size_t l4, l5;
    bool l7, l14, l15;
    vader_string_t l8 = 0;
    uint8_t l9;
    vader_box_t l12 = vader_box_null(), l13 = vader_box_null();
    int64_t t0;
    vader_string_t t1 = 0;
    void* t2 = NULL;
    vader_box_t* gc_roots[2] = { &l12, &l13 };
    void** gc_raw_roots[8] = { &l0, &l1, &l2, &l3, &l6, &l10, &l11, &t2 };
    vader_string_t* gc_atom_roots[2] = { &l8, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(22u, 0u, 13u, 407u);
    l2 = (void*) _a0_arr;
    l3 = ((vader_struct_toolchain_ast_FnDecl_t*) l0)->f_decorators;
    l4 = ((vader_array_t*) l3)->length;
    l5 = (size_t) (int64_t) INT64_C(0);
    {
        loop_9: {
            if ((l5 < l4)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l5 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                l6 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5);
                vader_array_push((vader_array_t*) l2, vader_ref_box(l6));
                t0 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t0;
                goto loop_9;
            }
        }
    }
    l3 = ((vader_struct_toolchain_ast_FnDecl_t*) l1)->f_decorators;
    l4 = ((vader_array_t*) l3)->length;
    l5 = (size_t) (int64_t) INT64_C(0);
    {
        loop_36: {
            if ((l5 < l4)) {
                vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
                if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                if ((size_t) l5 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                l6 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l5);
                t1 = ((vader_struct_toolchain_ast_Decorator_t*) l6)->f_name;
                if (t1 == 1534u) {
                    l7 = true;
                } else {
                    t1 = ((vader_struct_toolchain_ast_Decorator_t*) l6)->f_name;
                    l7 = t1 == 1747u;
                }
                if (l7) {
                    vader_array_push((vader_array_t*) l2, vader_ref_box(l6));
                }
                t0 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t0;
                goto loop_36;
            }
        }
    }
    l3 = ((vader_struct_toolchain_ast_FnDecl_t*) l0)->f_span;
    l4 = ((vader_struct_toolchain_ast_FnDecl_t*) l0)->f_id;
    l8 = ((vader_struct_toolchain_ast_FnDecl_t*) l0)->f_name;
    l6 = ((vader_struct_toolchain_ast_FnDecl_t*) l0)->f_name_span;
    l9 = ((vader_struct_toolchain_ast_FnDecl_t*) l0)->f_visibility;
    l10 = ((vader_struct_toolchain_ast_FnDecl_t*) l0)->f_type_params;
    l11 = ((vader_struct_toolchain_ast_FnDecl_t*) l0)->f_params;
    l12 = ((vader_struct_toolchain_ast_FnDecl_t*) l0)->f_return_type;
    l13 = ((vader_struct_toolchain_ast_FnDecl_t*) l1)->f_body;
    l7 = ((vader_struct_toolchain_ast_FnDecl_t*) l0)->f_sam_synthetic;
    l14 = ((vader_struct_toolchain_ast_FnDecl_t*) l1)->f_is_expression_bodied;
    l15 = ((vader_struct_toolchain_ast_FnDecl_t*) l0)->f_materialized;
    vader_struct_toolchain_ast_FnDecl_t* _a3_obj = (vader_struct_toolchain_ast_FnDecl_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_FnDecl_t));
    vader_obj_header_init(_a3_obj, 421u);
    _a3_obj->f_span = l3;
    _a3_obj->f_id = l4;
    _a3_obj->f_name = l8;
    _a3_obj->f_name_span = l6;
    _a3_obj->f_visibility = l9;
    _a3_obj->f_type_params = l10;
    _a3_obj->f_params = l11;
    _a3_obj->f_return_type = l12;
    _a3_obj->f_body = l13;
    _a3_obj->f_decorators = l2;
    _a3_obj->f_sam_synthetic = l7;
    _a3_obj->f_is_expression_bodied = l14;
    _a3_obj->f_materialized = l15;
    _a3_obj->f_comptime_synthetic = false;
    _a3_obj->f_trailing_comma = false;
    t2 = (void*) _a3_obj;
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static bool vader_resolver_has_module(void* l0, vader_string_t l1) {
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = std_collections_get__string__Any(l0, l1);
    { bool __vret = !(t0.tag == 0u); vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_box_t vader_resolver_home_root(vader_string_t l0, vader_string_t l1) {
    vader_box_t l2 = vader_box_null();
    vader_string_t l3 = 0;
    vader_box_t t0 = vader_box_null();
    vader_string_t t1 = 0;
    bool t2;
    vader_box_t* gc_roots[2] = { &l2, &t0 };
    vader_string_t* gc_atom_roots[4] = { &l0, &l1, &l3, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 0u, gc_roots, NULL, 0u, NULL, 4u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = vader_host_std_env_get_env(829u);
    if (l2.tag == 0u) {
        t0 = vader_box_obj(0u, NULL);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = l2.payload.s;
    if (t1 == 0u) {
        t0 = vader_box_obj(0u, NULL);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = l2.payload.s;
    l3 = vader_resolver_join_path(t1, l0);
    t1 = vader_resolver_join_path(l3, l1);
    t2 = std_io_exists(t1);
    if (t2) {
        t0 = vader_box_string(169u, l3);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_box_obj(0u, NULL);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static uint8_t vader_resolver_importer_origin(void* l0, vader_string_t l1) {
    void* l2 = NULL;
    vader_box_t l3 = vader_box_null();
    vader_box_t* gc_roots[1] = { &l3 };
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l3 = std_collections_get__string__Any(l0, l1);
    if (l3.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) (int32_t) INT32_C(0); }
    }
    l2 = l3.payload.obj;
    { uint8_t __vret = ((vader_struct_vader_resolver_DiscoveredModule_t*) l2)->f_origin; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_resolver_include_paths(vader_string_t l0, vader_string_t l1, void* l2, vader_string_t l3) {
    void* l4 = NULL;
    void* l5 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[4] = { &l2, &l4, &l5, &t0 };
    vader_string_t* gc_atom_roots[3] = { &l0, &l1, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_struct_vader_resolver_IncludePath_t* _a0_obj = (vader_struct_vader_resolver_IncludePath_t*) vader_gc_alloc(sizeof(vader_struct_vader_resolver_IncludePath_t));
    vader_obj_header_init(_a0_obj, 875u);
    _a0_obj->f_dir = l1;
    _a0_obj->f_prefix = l0;
    _a0_obj->f_merge = false;
    _a0_obj->f_origin = (uint8_t) (int32_t) INT32_C(0);
    t0 = (void*) _a0_obj;
    vader_array_t* _a1_arr = vader_array_new(84u, 1u, 13u, 875u);
    ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = t0;
    l4 = (void*) _a1_arr;
    vader_array_push_all((vader_array_t*) l4, (vader_array_t*) l2);
    if (l3 != 0u) {
        vader_struct_vader_resolver_IncludePath_t* _a2_obj = (vader_struct_vader_resolver_IncludePath_t*) vader_gc_alloc(sizeof(vader_struct_vader_resolver_IncludePath_t));
        vader_obj_header_init(_a2_obj, 875u);
        _a2_obj->f_dir = l3;
        _a2_obj->f_prefix = 0u;
        _a2_obj->f_merge = true;
        _a2_obj->f_origin = (uint8_t) (int32_t) INT32_C(0);
        l5 = (void*) _a2_obj;
        vader_array_push((vader_array_t*) l4, vader_ref_box(l5));
    }
    { void* __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void vader_resolver_ingest_module(void* l0, void* l1, void* l2, void* l3, void* l4, void* l5, void* l6, void* l7, vader_box_t l8) {
    void* l9 = NULL;
    void* l10 = NULL;
    void* l13 = NULL;
    vader_string_t l11 = 0;
    vader_string_t l12 = 0;
    vader_string_t l14 = 0;
    vader_string_t l15 = 0;
    uint8_t l16;
    size_t t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &l8 };
    void** gc_raw_roots[12] = { &l0, &l1, &l2, &l3, &l4, &l5, &l6, &l7, &l9, &l10, &l13, &t1 };
    vader_string_t* gc_atom_roots[4] = { &l11, &l12, &l14, &l15 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 12u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_vader_resolver_DiscoveredModule_t*) l0)->f_files)->length;
    if (t0 == INT64_C(0)) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l9 = vader_resolver_parse_module_files(((vader_struct_vader_resolver_DiscoveredModule_t*) l0)->f_files, l5, l6, l7);
    t0 = ((vader_array_t*) l9)->length;
    if (t0 == INT64_C(0)) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l10 = vader_resolver_discarded_bodies(l9, l8);
    l9 = vader_resolver_select_target_bodies(l9, l8, l5);
    vader_resolver_preresolve_imports(l9, l1, l4, l5);
    l11 = ((vader_struct_vader_resolver_DiscoveredModule_t*) l0)->f_folder;
    l12 = ((vader_struct_vader_resolver_DiscoveredModule_t*) l0)->f_name;
    l13 = vader_resolver_collect_files(l9, l11, l12, l3, l4, l1, l5);
    l11 = ((vader_struct_vader_resolver_DiscoveredModule_t*) l0)->f_folder;
    l12 = ((vader_struct_vader_resolver_DiscoveredModule_t*) l0)->f_folder;
    l14 = ((vader_struct_vader_resolver_DiscoveredModule_t*) l0)->f_name;
    l15 = ((vader_struct_vader_resolver_DiscoveredModule_t*) l0)->f_name;
    l16 = ((vader_struct_vader_resolver_DiscoveredModule_t*) l0)->f_origin;
    vader_struct_vader_resolver_Module_t* _a0_obj = (vader_struct_vader_resolver_Module_t*) vader_gc_alloc(sizeof(vader_struct_vader_resolver_Module_t));
    vader_obj_header_init(_a0_obj, 879u);
    _a0_obj->f_id = l12;
    _a0_obj->f_display_path = l14;
    _a0_obj->f_module_name = l15;
    _a0_obj->f_origin = l16;
    _a0_obj->f_files = l9;
    t1 = (void*) _a0_obj;
    vader_struct_vader_resolver_LoadedModule_t* _a1_obj = (vader_struct_vader_resolver_LoadedModule_t*) vader_gc_alloc(sizeof(vader_struct_vader_resolver_LoadedModule_t));
    vader_obj_header_init(_a1_obj, 876u);
    _a1_obj->f_module = t1;
    _a1_obj->f_collected = l13;
    _a1_obj->f_node_id_factory = l7;
    _a1_obj->f_discarded_bodies = l10;
    l9 = (void*) _a1_obj;
    std_collections_put__string__Any(l2, l11, vader_ref_box(l9));
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_resolver_intrinsic_decorator(void* l0) {
    void* l1 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[3] = { &l0, &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(113u, 0u, 13u, 1039u);
    l1 = (void*) _a0_arr;
    vader_struct_toolchain_ast_Decorator_t* _a1_obj = (vader_struct_toolchain_ast_Decorator_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_Decorator_t));
    vader_obj_header_init(_a1_obj, 407u);
    _a1_obj->f_span = l0;
    _a1_obj->f_id = (size_t) (int64_t) INT64_C(0);
    _a1_obj->f_name = 1747u;
    _a1_obj->f_args = l1;
    t0 = (void*) _a1_obj;
    vader_array_t* _a2_arr = vader_array_new(22u, 1u, 13u, 407u);
    ((void**) _a2_arr->buf->slots)[_a2_arr->offset + 0u] = t0;
    t0 = (void*) _a2_arr;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static bool vader_resolver_is_host_bound(void* l0) {
    void* l1;
    void* l4;
    size_t l2, l3;
    vader_string_t t0;
    int64_t t1;
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
                if (t0 == 1747u) {
                    return true;
                }
                t0 = ((vader_struct_toolchain_ast_Decorator_t*) l4)->f_name;
                if (t0 == 1534u) {
                    return true;
                }
                t1 = (l3 + INT64_C(1));
                l3 = (size_t) (int64_t) t1;
                goto loop_7;
            }
        }
    }
    return false;
}

static bool vader_resolver_is_intrinsic(void* l0) {
    void* l1;
    size_t l2, l3;
    void* t0;
    vader_string_t t1;
    int64_t t2;
    l1 = l0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    l2 = ((vader_array_t*) l1)->length;
    l3 = (size_t) (int64_t) INT64_C(0);
    {
        loop_7: {
            if ((l3 < l2)) {
                if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
                t1 = ((vader_struct_toolchain_ast_Decorator_t*) t0)->f_name;
                if (t1 == 1747u) {
                    return true;
                }
                t2 = (l3 + INT64_C(1));
                l3 = (size_t) (int64_t) t2;
                goto loop_7;
            }
        }
    }
    return false;
}

static bool vader_resolver_is_known_decorator(vader_string_t l0) {
    bool l1;
    if (l0 == 1385u) {
        l1 = true;
    } else {
        l1 = l0 == 1534u;
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == 1520u;
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == 2145u;
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == 1747u;
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == 1448u;
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == 1243u;
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == 1909u;
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == 1178u;
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == 2143u;
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == 1325u;
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == 1326u;
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == 1327u;
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == 1328u;
    }
    return l1;
}

static vader_string_t vader_resolver_join_path(vader_string_t l0, vader_string_t l1) {
    vader_string_t l2 = 0;
    size_t l3;
    size_t t0;
    int64_t t1;
    uint8_t t2;
    vader_string_t t3 = 0;
    vader_string_t* gc_atom_roots[4] = { &l0, &l1, &l2, &t3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 4u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = std_string_trim_prefix(l1, 419u);
    if (l0 == 0u) {
        { vader_string_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_host_std_core_byte_len(l0);
    t1 = (t0 - INT64_C(1));
    l3 = (size_t) (int64_t) t1;
    t2 = vader_host_std_core_byte_at(l0, l3);
    if (t2 == INT32_C(47)) {
        t3 = concat_2(l0, l2);
        { vader_string_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t3 = concat_3(l0, 436u, l2);
    { vader_string_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void vader_resolver_load_baked_target(void* l0, void* l1, void* l2, void* l3, void* l4, void* l5, void* l6, void* l7) {
    vader_box_t l8 = vader_box_null();
    vader_string_t l9 = 0;
    vader_string_t l16 = 0;
    vader_string_t l17 = 0;
    vader_string_t l18 = 0;
    void* l10 = NULL;
    void* l11 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    size_t l14, l15;
    void* t0 = NULL;
    bool t1;
    vader_box_t t2 = vader_box_null();
    int64_t t3;
    vader_box_t* gc_roots[2] = { &l8, &t2 };
    void** gc_raw_roots[13] = { &l0, &l1, &l2, &l3, &l4, &l5, &l6, &l7, &l10, &l11, &l12, &l13, &t0 };
    vader_struct___Tuple_string_string_66940ed4_t _a7_storage = {0};
    void* gc_stack_objs[1] = { (void*) &_a7_storage };
    vader_string_t* gc_atom_roots[4] = { &l9, &l16, &l17, &l18 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 13u, gc_roots, gc_raw_roots, 1u, gc_stack_objs, 4u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l8 = vader_resolver_resolve_lazy(2047u, l1, l2, l3);
    if (l8.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    t0 = l8.payload.obj;
    l9 = ((vader_struct_vader_resolver_DiscoveredModule_t*) t0)->f_folder;
    t1 = vader_resolver_has_module(l0, l9);
    if (!(t1)) {
        t0 = l8.payload.obj;
        vader_array_t* _a0_arr = vader_array_new(81u, 1u, 13u, 870u);
        ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = t0;
        t0 = (void*) _a0_arr;
        vader_resolver_drain_load_queue(t0, l1, l0, l5, l2, l3, l4, l6, vader_ref_box(l7));
    }
    vader_array_t* _a1_arr = vader_array_new(8u, 0u, 0u, 169u);
    l10 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(8u, 0u, 0u, 169u);
    l11 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(9u, 0u, 7u, 172u);
    l12 = (void*) _a3_arr;
    vader_struct_std_collections_MutableMap__string__string_t* _a4_obj = (vader_struct_std_collections_MutableMap__string__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__string_t));
    vader_obj_header_init(_a4_obj, 363u);
    _a4_obj->f_ekeys = l10;
    _a4_obj->f_evals = l11;
    _a4_obj->f_index = l12;
    _a4_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a4_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a4_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l10 = (void*) _a4_obj;
    l11 = l4;
    l12 = ((vader_struct_std_collections_MutableMap__string__string_t*) l11)->f_ekeys;
    l13 = ((vader_struct_std_collections_MutableMap__string__string_t*) l11)->f_evals;
    l14 = ((vader_struct_std_collections_MutableMap__string__string_t*) l11)->f_size;
    l15 = (size_t) (int64_t) INT64_C(0);
    {
        loop_59: {
            if ((l15 >= l14)) {
            } else {
                vader_array_t* _a5_slotarr = ((vader_array_t*) l12);
                if (_a5_slotarr->buf != NULL && _a5_slotarr->buf->header.forward != NULL) { _a5_slotarr->buf = vader_array_buf_forward(_a5_slotarr->buf); }
                if ((size_t) l15 >= _a5_slotarr->length) { vader_trap("array index out of bounds"); }
                t2 = vader_array_box_slots(_a5_slotarr->buf)[_a5_slotarr->offset + (size_t) l15];
                l9 = t2.payload.s;
                vader_array_t* _a6_slotarr = ((vader_array_t*) l13);
                if (_a6_slotarr->buf != NULL && _a6_slotarr->buf->header.forward != NULL) { _a6_slotarr->buf = vader_array_buf_forward(_a6_slotarr->buf); }
                if ((size_t) l15 >= _a6_slotarr->length) { vader_trap("array index out of bounds"); }
                t2 = vader_array_box_slots(_a6_slotarr->buf)[_a6_slotarr->offset + (size_t) l15];
                l16 = t2.payload.s;
                vader_struct___Tuple_string_string_66940ed4_t* _a8_obj = &_a7_storage;
                vader_obj_header_init(_a8_obj, 238u);
                _a8_obj->f__0 = l9;
                _a8_obj->f__1 = l16;
                l11 = (void*) _a8_obj;
                l17 = ((vader_struct___Tuple_string_string_66940ed4_t*) l11)->f__0;
                l18 = ((vader_struct___Tuple_string_string_66940ed4_t*) l11)->f__1;
                t3 = (l15 + INT64_C(1));
                l15 = (size_t) (int64_t) t3;
                std_collections_put__string__string(l10, l17, l18);
                goto loop_59;
            }
        }
    }
    l9 = vader_target_baked_module_source(l7);
    std_collections_put__string__string(l10, 508u, l9);
    vader_array_t* _a9_arr = vader_array_new(8u, 1u, 0u, 169u);
    vader_array_box_slots(_a9_arr->buf)[_a9_arr->offset + 0u] = vader_box_string(169u, 508u);
    l11 = (void*) _a9_arr;
    vader_struct_vader_resolver_DiscoveredModule_t* _a10_obj = (vader_struct_vader_resolver_DiscoveredModule_t*) vader_gc_alloc(sizeof(vader_struct_vader_resolver_DiscoveredModule_t));
    vader_obj_header_init(_a10_obj, 870u);
    _a10_obj->f_name = 2048u;
    _a10_obj->f_folder = 507u;
    _a10_obj->f_files = l11;
    _a10_obj->f_origin = (uint8_t) (int32_t) INT32_C(1);
    t0 = (void*) _a10_obj;
    vader_array_t* _a11_arr = vader_array_new(81u, 1u, 13u, 870u);
    ((void**) _a11_arr->buf->slots)[_a11_arr->offset + 0u] = t0;
    t0 = (void*) _a11_arr;
    vader_resolver_drain_load_queue(t0, l1, l0, l5, l2, l3, l10, l6, vader_ref_box(l7));
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

void* vader_resolver_load_project(vader_string_t l0, void* l1, vader_box_t l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[5] = { &l1, &l3, &l4, &l5, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 169u);
    l3 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(8u, 0u, 0u, 169u);
    l4 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 172u);
    l5 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__string__string_t* _a3_obj = (vader_struct_std_collections_MutableMap__string__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__string_t));
    vader_obj_header_init(_a3_obj, 363u);
    _a3_obj->f_ekeys = l3;
    _a3_obj->f_evals = l4;
    _a3_obj->f_index = l5;
    _a3_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l3 = (void*) _a3_obj;
    t0 = vader_resolver_load_project_with_overlay(l0, l3, l1, l2);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_resolver_load_project_with_overlay(vader_string_t l0, void* l1, void* l2, vader_box_t l3) {
    void* l4 = NULL;
    void* l5 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    void* l12 = NULL;
    void* l15 = NULL;
    void* l16 = NULL;
    void* l17 = NULL;
    vader_string_t l6 = 0;
    vader_string_t l13 = 0;
    vader_string_t l14 = 0;
    vader_box_t l7 = vader_box_null(), l8 = vader_box_null(), l18 = vader_box_null(), l19 = vader_box_null();
    void* t0 = NULL;
    vader_string_t t1 = 0;
    bool t2;
    vader_box_t* gc_roots[5] = { &l3, &l7, &l8, &l18, &l19 };
    void** gc_raw_roots[12] = { &l1, &l2, &l4, &l5, &l9, &l10, &l11, &l12, &l15, &l16, &l17, &t0 };
    vader_string_t* gc_atom_roots[5] = { &l0, &l6, &l13, &l14, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 5u, 12u, gc_roots, gc_raw_roots, 0u, NULL, 5u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_struct_vader_resolver_symbol_SymbolFactory_t* _a0_obj = (vader_struct_vader_resolver_symbol_SymbolFactory_t*) vader_gc_alloc(sizeof(vader_struct_vader_resolver_symbol_SymbolFactory_t));
    vader_obj_header_init(_a0_obj, 890u);
    _a0_obj->f_next = INT32_C(1);
    l4 = (void*) _a0_obj;
    l5 = vader_parser_new_node_id_factory();
    l6 = std_path_to_posix(l0);
    l8 = l3;
    if (l8.tag == 0u) {
        t0 = vader_target_host_target();
        l7 = vader_ref_box(t0);
    } else {
        l7 = l8;
    }
    if (l7.tag == 891u) {
        l9 = vader_target_host_target();
    } else {
        l9 = l7.payload.obj;
    }
    if (l7.tag == 891u) {
        l8 = vader_box_obj(0u, NULL);
    } else {
        t0 = l7.payload.obj;
        l8 = vader_ref_box(t0);
    }
    vader_array_t* _a1_arr = vader_array_new(8u, 0u, 0u, 169u);
    l10 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(16u, 0u, 0u, 180u);
    l11 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(9u, 0u, 7u, 172u);
    l12 = (void*) _a3_arr;
    vader_struct_std_collections_MutableMap__string__Any_t* _a4_obj = (vader_struct_std_collections_MutableMap__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__Any_t));
    vader_obj_header_init(_a4_obj, 321u);
    _a4_obj->f_ekeys = l10;
    _a4_obj->f_evals = l11;
    _a4_obj->f_index = l12;
    _a4_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a4_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a4_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l10 = (void*) _a4_obj;
    vader_array_t* _a5_arr = vader_array_new(51u, 0u, 13u, 700u);
    l11 = (void*) _a5_arr;
    l7 = vader_resolver_find_manifest_root(l6);
    if (l7.tag == 169u) {
        t1 = l7.payload.s;
        l12 = vader_resolver_read_manifest(t1);
    } else {
        if (l7.tag == 0u) {
            vader_array_t* _a6_arr = vader_array_new(8u, 0u, 0u, 169u);
            t0 = (void*) _a6_arr;
            vader_struct_vader_resolver_Manifest_t* _a7_obj = (vader_struct_vader_resolver_Manifest_t*) vader_gc_alloc(sizeof(vader_struct_vader_resolver_Manifest_t));
            vader_obj_header_init(_a7_obj, 878u);
            _a7_obj->f_include_paths = t0;
            l12 = (void*) _a7_obj;
        } else {
            vader_unreachable("unreachable return in vader_resolver$load_project_with_overlay");
        }
    }
    l13 = vader_resolver_entry_folder_of(l6);
    l12 = vader_resolver_project_include_paths(l7, l12, l2);
    l14 = vader_resolver_generated_root_for(l7);
    vader_array_t* _a8_arr = vader_array_new(8u, 0u, 0u, 169u);
    l15 = (void*) _a8_arr;
    vader_array_t* _a9_arr = vader_array_new(16u, 0u, 0u, 180u);
    l16 = (void*) _a9_arr;
    vader_array_t* _a10_arr = vader_array_new(9u, 0u, 7u, 172u);
    l17 = (void*) _a10_arr;
    vader_struct_std_collections_MutableMap__string__Any_t* _a11_obj = (vader_struct_std_collections_MutableMap__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__Any_t));
    vader_obj_header_init(_a11_obj, 321u);
    _a11_obj->f_ekeys = l15;
    _a11_obj->f_evals = l16;
    _a11_obj->f_index = l17;
    _a11_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a11_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a11_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l15 = (void*) _a11_obj;
    l18 = vader_resolver_seed_entry(l13, l11);
    if (l18.tag == 0u) {
        l16 = vader_resolver_zero_span(l6);
        l16 = vader_diagnostics_resolver_error((uint8_t) (int32_t) INT32_C(0), l16, 1480u);
        vader_array_push((vader_array_t*) l11, vader_ref_box(l16));
        vader_struct_vader_resolver_LoadedProject_t* _a12_obj = (vader_struct_vader_resolver_LoadedProject_t*) vader_gc_alloc(sizeof(vader_struct_vader_resolver_LoadedProject_t));
        vader_obj_header_init(_a12_obj, 877u);
        _a12_obj->f_entry = l13;
        _a12_obj->f_modules = l10;
        _a12_obj->f_factory = l4;
        _a12_obj->f_project_root = l7;
        _a12_obj->f_diags = l11;
        t0 = (void*) _a12_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l18.tag == 870u) {
        t0 = l18.payload.obj;
        l6 = ((vader_struct_vader_resolver_DiscoveredModule_t*) t0)->f_name;
        t0 = l18.payload.obj;
        l13 = ((vader_struct_vader_resolver_DiscoveredModule_t*) t0)->f_folder;
        l12 = vader_resolver_include_paths(l6, l13, l12, l14);
        t0 = l18.payload.obj;
        t1 = ((vader_struct_vader_resolver_DiscoveredModule_t*) t0)->f_name;
        l19 = vader_resolver_resolve_lazy(t1, l12, l15, l11);
        if (l19.tag == 0u) {
            l16 = l18.payload.obj;
        } else {
            l16 = l19.payload.obj;
        }
        vader_array_t* _a13_arr = vader_array_new(81u, 1u, 13u, 870u);
        ((void**) _a13_arr->buf->slots)[_a13_arr->offset + 0u] = l16;
        l16 = (void*) _a13_arr;
        l19 = vader_resolver_resolve_lazy(2043u, l12, l15, l11);
        if (l19.tag == 870u) {
            t0 = l19.payload.obj;
            l6 = ((vader_struct_vader_resolver_DiscoveredModule_t*) t0)->f_folder;
            t0 = l18.payload.obj;
            l13 = ((vader_struct_vader_resolver_DiscoveredModule_t*) t0)->f_folder;
            if (l6 != l13) {
                l17 = l19.payload.obj;
                vader_array_push((vader_array_t*) l16, vader_ref_box(l17));
            }
        } else {
        }
        vader_resolver_drain_load_queue(l16, l12, l10, l4, l15, l11, l1, l5, l8);
        l19 = vader_resolver_resolve_lazy(2046u, l12, l15, l11);
        if (l19.tag == 870u) {
            t0 = l19.payload.obj;
            l6 = ((vader_struct_vader_resolver_DiscoveredModule_t*) t0)->f_folder;
            t2 = vader_resolver_has_module(l10, l6);
            if (!(t2)) {
                t0 = l19.payload.obj;
                vader_array_t* _a14_arr = vader_array_new(81u, 1u, 13u, 870u);
                ((void**) _a14_arr->buf->slots)[_a14_arr->offset + 0u] = t0;
                t0 = (void*) _a14_arr;
                vader_resolver_drain_load_queue(t0, l12, l10, l4, l15, l11, l1, l5, l8);
            }
        } else {
        }
        vader_resolver_load_baked_target(l10, l12, l15, l11, l1, l4, l5, l9);
        vader_resolver_detect_import_cycles(l10, l15, l11);
        t0 = l18.payload.obj;
        t1 = ((vader_struct_vader_resolver_DiscoveredModule_t*) t0)->f_folder;
        vader_struct_vader_resolver_LoadedProject_t* _a15_obj = (vader_struct_vader_resolver_LoadedProject_t*) vader_gc_alloc(sizeof(vader_struct_vader_resolver_LoadedProject_t));
        vader_obj_header_init(_a15_obj, 877u);
        _a15_obj->f_entry = t1;
        _a15_obj->f_modules = l10;
        _a15_obj->f_factory = l4;
        _a15_obj->f_project_root = l7;
        _a15_obj->f_diags = l11;
        t0 = (void*) _a15_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_unreachable("unreachable return in vader_resolver$load_project_with_overlay");
    vader_gc_top = gc_frame.prev;
}

static vader_box_t vader_resolver_lookup(void* l0, vader_string_t l1) {
    size_t l2;
    vader_box_t l3 = vader_box_null();
    int64_t t0;
    void* t1 = NULL;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l3, &t2 };
    void** gc_raw_roots[2] = { &l0, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = ((vader_array_t*) ((vader_struct_vader_resolver_Scope_t*) l0)->f_frames)->length;
    {
        loop_4: {
            if ((l2 > INT64_C(0))) {
                t0 = (l2 - INT64_C(1));
                l2 = (size_t) (int64_t) t0;
                vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_resolver_Scope_t*) l0)->f_frames);
                if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                if ((size_t) l2 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                t1 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
                l3 = std_collections_get__string__Any(t1, l1);
                if (l3.tag == 889u) {
                    t1 = l3.payload.obj;
                    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                }
                if (l3.tag == 0u) {
                } else {
                    vader_unreachable("unreachable return in vader_resolver$lookup");
                }
                goto loop_4;
            }
        }
    }
    t2 = vader_box_obj(0u, NULL);
    { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static int32_t vader_resolver_lookup_frame_index(void* l0, vader_string_t l1) {
    size_t l2;
    int64_t t0;
    void* t1 = NULL;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t2 };
    void** gc_raw_roots[2] = { &l0, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = ((vader_array_t*) ((vader_struct_vader_resolver_Scope_t*) l0)->f_frames)->length;
    {
        loop_4: {
            if ((l2 > INT64_C(0))) {
                t0 = (l2 - INT64_C(1));
                l2 = (size_t) (int64_t) t0;
                vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_resolver_Scope_t*) l0)->f_frames);
                if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                if ((size_t) l2 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                t1 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
                t2 = std_collections_get__string__Any(t1, l1);
                if (!(t2.tag == 0u)) {
                    { int32_t __vret = ((int32_t) (size_t) l2); vader_gc_top = gc_frame.prev; return __vret; }
                }
                goto loop_4;
            }
        }
    }
    { int32_t __vret = -(INT32_C(1)); vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_box_t vader_resolver_lookup_subst(void* l0, vader_string_t l1) {
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = std_collections_get__string__Any(((vader_struct_vader_resolver_Subst_t*) l0)->f_entries, l1);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_box_t vader_resolver_lookup_trait_sym(void* l0, void* l1, void* l2) {
    vader_string_t l3 = 0;
    vader_box_t l4 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    void* t2 = NULL;
    vader_box_t* gc_roots[2] = { &l4, &t0 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &t1, &t2 };
    vader_string_t* gc_atom_roots[1] = { &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_toolchain_ast_ImplDecl_t*) l0)->f_trait_name;
    l4 = std_collections_get__string__Any(l1, l3);
    if (l4.tag == 0u) {
        t0 = vader_box_obj(0u, NULL);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = l4.payload.obj;
    t2 = vader_resolver_resolve_import_redirect(t1, l2);
    { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_resolver_make_builtin_scope(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    size_t l4, l5;
    vader_string_t l6 = 0;
    vader_box_t t0 = vader_box_null();
    int64_t t1;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &l3 };
    vader_string_t* gc_atom_roots[1] = { &l6 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 169u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(16u, 0u, 0u, 180u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 172u);
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
    l2 = vader_resolver_builtin_type_names();
    l4 = ((vader_array_t*) l2)->length;
    l5 = (size_t) (int64_t) INT64_C(0);
    {
        loop_21: {
            if ((l5 < l4)) {
                vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
                if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                if ((size_t) l5 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_box_slots(_a4_slotarr->buf)[_a4_slotarr->offset + (size_t) l5];
                l6 = t0.payload.s;
                l3 = vader_resolver_symbol_make(l0, INT32_C(12), l6, 509u, 509u, (uint8_t) (int32_t) INT32_C(0), vader_box_obj(0u, NULL));
                std_collections_put__string__Any(l1, l6, vader_ref_box(l3));
                t1 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t1;
                goto loop_21;
            }
        }
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void vader_resolver_mark_binding_immutable(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    vader_string_t l3 = 0;
    vader_box_t l4 = vader_box_null();
    int32_t l5;
    size_t l6, l7;
    void* t0 = NULL;
    int64_t t1;
    vader_box_t* gc_roots[2] = { &l1, &l4 };
    void** gc_raw_roots[3] = { &l0, &l2, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    if (l1.tag == 459u) {
        l2 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_scope;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_toolchain_ast_SimpleBinding_t*) t0)->f_name;
        l4 = vader_resolver_lookup(l2, l3);
        if (l4.tag == 889u) {
            l2 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_immutable_locals;
            t0 = l4.payload.obj;
            l5 = ((vader_struct_vader_resolver_symbol_Symbol_t*) t0)->f_id;
            std_collections_put__i32__bool(l2, l5, true);
        } else {
            if (l4.tag == 0u) {
            } else {
                { vader_gc_top = gc_frame.prev; return; }
            }
        }
    } else {
        if (l1.tag == 471u) {
            t0 = l1.payload.obj;
            l2 = ((vader_struct_toolchain_ast_TupleBinding_t*) t0)->f_elements;
            l6 = ((vader_array_t*) l2)->length;
            l7 = (size_t) (int64_t) INT64_C(0);
            {
                loop_48: {
                    if ((l7 < l6)) {
                        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
                        if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                        if ((size_t) l7 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                        l4 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l7);
                        vader_resolver_mark_binding_immutable(l0, l4);
                        t1 = (l7 + INT64_C(1));
                        l7 = (size_t) (int64_t) t1;
                        goto loop_48;
                    }
                }
            }
        } else {
            if (l1.tag == 456u) {
                l2 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_scope;
                t0 = l1.payload.obj;
                l3 = ((vader_struct_toolchain_ast_RestBinding_t*) t0)->f_name;
                l4 = vader_resolver_lookup(l2, l3);
                if (l4.tag == 889u) {
                    l2 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_immutable_locals;
                    t0 = l4.payload.obj;
                    l5 = ((vader_struct_vader_resolver_symbol_Symbol_t*) t0)->f_id;
                    std_collections_put__i32__bool(l2, l5, true);
                }
            } else {
            }
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_resolver_mark_param_borrow(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    int32_t l4;
    bool t0;
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = toolchain_ast_param_is_mutable(l1);
    if (t0) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    t0 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_params_immutable_default;
    if (!(t0)) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l3 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_immutable_borrows;
    l4 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l2)->f_id;
    std_collections_put__i32__bool(l3, l4, true);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static bool vader_resolver_matches_target(void* l0, void* l1) {
    void* l2;
    size_t l3, l4;
    uint8_t l5, l6;
    vader_box_t t0;
    int64_t t1;
    l2 = l0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    l3 = ((vader_array_t*) l2)->length;
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_7: {
            if ((l4 < l3)) {
                if ((size_t) l4 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l4, 175u);
                l5 = ((uint8_t) t0.payload.i);
                l6 = ((vader_struct_vader_target_Target_t*) l1)->f_os;
                if (l5 == l6) {
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

void vader_resolver_materialize_default_members(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l9 = NULL;
    void* l12 = NULL;
    void* l14 = NULL;
    void* l15 = NULL;
    void* l16 = NULL;
    void* l17 = NULL;
    void* l18 = NULL;
    int32_t l6, l7;
    vader_string_t l8 = 0;
    size_t l10, l11;
    vader_box_t l13 = vader_box_null();
    bool t0;
    int32_t t1;
    int64_t t2;
    void* t3 = NULL;
    vader_box_t* gc_roots[1] = { &l13 };
    void** gc_raw_roots[14] = { &l0, &l1, &l2, &l3, &l4, &l5, &l9, &l12, &l14, &l15, &l16, &l17, &l18, &t3 };
    vader_string_t* gc_atom_roots[1] = { &l8 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 14u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = vader_resolver_any_has_body(((vader_struct_toolchain_ast_TraitDecl_t*) l1)->f_members);
    if (!(t0)) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l3 = vader_resolver_provided_names(((vader_struct_toolchain_ast_ImplDecl_t*) l0)->f_members);
    l4 = vader_resolver_build_subst(l0, l1);
    l5 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_toolchain_ast_ImplDecl_t*) l0)->f_trait_name_span)->f_start;
    t1 = ((vader_struct_toolchain_span_Position_t*) l5)->f_line;
    l6 = (t1 * INT32_C(1024));
    l7 = ((vader_struct_toolchain_span_Position_t*) l5)->f_column;
    l6 = (l6 + l7);
    l8 = ((vader_struct_toolchain_span_Position_t*) l5)->f_file;
    l8 = concat_2(511u, l8);
    vader_struct_vader_resolver_StampCtx_t* _a0_obj = (vader_struct_vader_resolver_StampCtx_t*) vader_gc_alloc(sizeof(vader_struct_vader_resolver_StampCtx_t));
    vader_obj_header_init(_a0_obj, 885u);
    _a0_obj->f_base_line = l6;
    _a0_obj->f_counter = INT32_C(0);
    _a0_obj->f_file = l8;
    l5 = (void*) _a0_obj;
    l9 = ((vader_struct_toolchain_ast_TraitDecl_t*) l1)->f_members;
    l10 = ((vader_array_t*) l9)->length;
    l11 = (size_t) (int64_t) INT64_C(0);
    {
        loop_47: {
            if ((l11 < l10)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) l9);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l11 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                l12 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l11);
                l13 = ((vader_struct_toolchain_ast_FnDecl_t*) l12)->f_body;
                if (l13.tag == 0u) {
                } else {
                    if (l13.tag == 398u) {
                        l14 = ((vader_struct_std_collections_MutableSet__string_t*) l3)->f_inner;
                        l8 = ((vader_struct_toolchain_ast_FnDecl_t*) l12)->f_name;
                        t0 = std_collections_contains_key__string__bool(l14, l8);
                        if (t0) {
                            t2 = (l11 + INT64_C(1));
                            l11 = (size_t) (int64_t) t2;
                            goto loop_47;
                        }
                        vader_array_t* _a2_arr = vader_array_new(22u, 0u, 13u, 407u);
                        l15 = (void*) _a2_arr;
                        t3 = l13.payload.obj;
                        l16 = vader_resolver_substitute_block_materialized(t3, l4, l2, l5);
                        l17 = ((vader_struct_toolchain_ast_ImplDecl_t*) l0)->f_members;
                        l18 = vader_resolver_synth_with_body(l12, l4, l15, l16, l5);
                        vader_array_push((vader_array_t*) l17, vader_ref_box(l18));
                    } else {
                        { vader_gc_top = gc_frame.prev; return; }
                    }
                }
                t2 = (l11 + INT64_C(1));
                l11 = (size_t) (int64_t) t2;
                goto loop_47;
            }
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

void vader_resolver_materialize_intrinsic_members(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l7 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    int32_t l4, l5;
    vader_string_t l6 = 0;
    size_t l8, l9;
    bool t0;
    size_t t1;
    int32_t t2;
    int64_t t3;
    void** gc_raw_roots[10] = { &l0, &l1, &l2, &l3, &l7, &l10, &l11, &l12, &l13, &l14 };
    vader_string_t* gc_atom_roots[1] = { &l6 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 10u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = vader_resolver_is_intrinsic(((vader_struct_toolchain_ast_ImplDecl_t*) l0)->f_decorators);
    if (!(t0)) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    t1 = ((vader_array_t*) ((vader_struct_toolchain_ast_ImplDecl_t*) l0)->f_members)->length;
    if ((t1 > INT64_C(0))) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l2 = vader_resolver_build_subst(l0, l1);
    l3 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_toolchain_ast_ImplDecl_t*) l0)->f_trait_name_span)->f_start;
    t2 = ((vader_struct_toolchain_span_Position_t*) l3)->f_line;
    l4 = (t2 * INT32_C(1024));
    l5 = ((vader_struct_toolchain_span_Position_t*) l3)->f_column;
    l4 = (l4 + l5);
    l6 = ((vader_struct_toolchain_span_Position_t*) l3)->f_file;
    l6 = concat_2(511u, l6);
    vader_struct_vader_resolver_StampCtx_t* _a0_obj = (vader_struct_vader_resolver_StampCtx_t*) vader_gc_alloc(sizeof(vader_struct_vader_resolver_StampCtx_t));
    vader_obj_header_init(_a0_obj, 885u);
    _a0_obj->f_base_line = l4;
    _a0_obj->f_counter = INT32_C(0);
    _a0_obj->f_file = l6;
    l3 = (void*) _a0_obj;
    l7 = ((vader_struct_toolchain_ast_TraitDecl_t*) l1)->f_members;
    l8 = ((vader_array_t*) l7)->length;
    l9 = (size_t) (int64_t) INT64_C(0);
    {
        loop_51: {
            if ((l9 < l8)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) l7);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l9 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                l10 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l9);
                l11 = ((vader_struct_toolchain_ast_ImplDecl_t*) l0)->f_members;
                l12 = vader_resolver_next_clone_span(l3);
                l13 = vader_resolver_intrinsic_decorator(((vader_struct_toolchain_ast_ImplDecl_t*) l0)->f_span);
                l14 = vader_resolver_synth_signature(l10, l12, l2, l13);
                vader_array_push((vader_array_t*) l11, vader_ref_box(l14));
                t3 = (l9 + INT64_C(1));
                l9 = (size_t) (int64_t) t3;
                goto loop_51;
            }
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

void vader_resolver_materialize_sam_members(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void* l7 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    size_t l5, l6;
    vader_string_t l8 = 0;
    vader_box_t l12 = vader_box_null();
    size_t t0;
    bool t1;
    int64_t t2;
    vader_box_t* gc_roots[1] = { &l12 };
    void** gc_raw_roots[9] = { &l0, &l1, &l2, &l3, &l4, &l7, &l9, &l10, &l11 };
    vader_string_t* gc_atom_roots[1] = { &l8 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 9u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = vader_resolver_count_sam_synthetics(((vader_struct_toolchain_ast_ImplDecl_t*) l0)->f_members);
    if (t0 == INT64_C(0)) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l3 = vader_resolver_required_methods(((vader_struct_toolchain_ast_TraitDecl_t*) l1)->f_members);
    t1 = std_iter_is_empty__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType(l3);
    if (t1) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    if ((size_t) INT32_C(0) >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
    l3 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT32_C(0));
    l4 = vader_resolver_build_subst(l0, l1);
    l5 = ((vader_array_t*) ((vader_struct_toolchain_ast_ImplDecl_t*) l0)->f_members)->length;
    l6 = (size_t) (int64_t) INT64_C(0);
    {
        loop_28: {
            if ((l6 < l5)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_ImplDecl_t*) l0)->f_members);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l6 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                l7 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l6);
                t1 = ((vader_struct_toolchain_ast_FnDecl_t*) l7)->f_sam_synthetic;
                if (!(t1)) {
                    t2 = (l6 + INT64_C(1));
                    l6 = (size_t) (int64_t) t2;
                    goto loop_28;
                }
                l8 = ((vader_struct_toolchain_ast_FnDecl_t*) l3)->f_name;
                ((vader_struct_toolchain_ast_FnDecl_t*) l7)->f_name = l8;
                VADER_WRITE_BARRIER((vader_struct_toolchain_ast_FnDecl_t*) l7);
                l9 = ((vader_struct_toolchain_ast_FnDecl_t*) l3)->f_params;
                l10 = ((vader_struct_toolchain_ast_FnDecl_t*) l7)->f_name_span;
                l11 = vader_resolver_substitute_params_disambiguated(l9, l4, l10, l2);
                ((vader_struct_toolchain_ast_FnDecl_t*) l7)->f_params = l11;
                VADER_WRITE_BARRIER((vader_struct_toolchain_ast_FnDecl_t*) l7);
                l12 = vader_resolver_substitute_opt_type(((vader_struct_toolchain_ast_FnDecl_t*) l3)->f_return_type, l4);
                ((vader_struct_toolchain_ast_FnDecl_t*) l7)->f_return_type = l12;
                VADER_WRITE_BARRIER((vader_struct_toolchain_ast_FnDecl_t*) l7);
                t2 = (l6 + INT64_C(1));
                l6 = (size_t) (int64_t) t2;
                goto loop_28;
            }
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_resolver_merge_bucket_map__string__string(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l8 = NULL;
    void* l10 = NULL;
    void* l12 = NULL;
    size_t l5, l6;
    vader_string_t l7 = 0;
    vader_string_t l9 = 0;
    vader_box_t l11 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    int64_t t1;
    void* t2 = NULL;
    vader_box_t* gc_roots[2] = { &l11, &t0 };
    void** gc_raw_roots[9] = { &l0, &l1, &l2, &l3, &l4, &l8, &l10, &l12, &t2 };
    vader_string_t* gc_atom_roots[2] = { &l7, &l9 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 9u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = l1;
    l3 = ((vader_struct_std_collections_MutableMap__string__string___t*) l2)->f_ekeys;
    l4 = ((vader_struct_std_collections_MutableMap__string__string___t*) l2)->f_evals;
    l5 = ((vader_struct_std_collections_MutableMap__string__string___t*) l2)->f_size;
    l6 = (size_t) (int64_t) INT64_C(0);
    {
        loop_12: {
            if ((l6 >= l5)) {
            } else {
                vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
                if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                if ((size_t) l6 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l6];
                l7 = t0.payload.s;
                vader_array_t* _a1_slotarr = ((vader_array_t*) l4);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l6 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                l2 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l6);
                vader_struct___Tuple_string_Array_string__55ab4b78_t* _a2_obj = (vader_struct___Tuple_string_Array_string__55ab4b78_t*) vader_gc_alloc(sizeof(vader_struct___Tuple_string_Array_string__55ab4b78_t));
                vader_obj_header_init(_a2_obj, 235u);
                _a2_obj->f__0 = l7;
                _a2_obj->f__1 = l2;
                l8 = (void*) _a2_obj;
                l9 = ((vader_struct___Tuple_string_Array_string__55ab4b78_t*) l8)->f__0;
                l10 = ((vader_struct___Tuple_string_Array_string__55ab4b78_t*) l8)->f__1;
                t1 = (l6 + INT64_C(1));
                l6 = (size_t) (int64_t) t1;
                l11 = std_collections_get__string__Any(l0, l9);
                if (l11.tag == 0u) {
                    std_collections_put__string__Any(l0, l9, vader_ref_box(l10));
                } else {
                    t2 = l11.payload.obj;
                    vader_array_push_all((vader_array_t*) t2, (vader_array_t*) l10);
                    l12 = l11.payload.obj;
                    std_collections_put__string__Any(l0, l9, vader_ref_box(l12));
                }
                goto loop_12;
            }
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_resolver_merge_collected(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l9 = NULL;
    void* l11 = NULL;
    void* l16 = NULL;
    void* l19 = NULL;
    void* l20 = NULL;
    void* l21 = NULL;
    void* l22 = NULL;
    void* l26 = NULL;
    void* l27 = NULL;
    void* l29 = NULL;
    void* l32 = NULL;
    void* l35 = NULL;
    void* l37 = NULL;
    void* l38 = NULL;
    void* l39 = NULL;
    void* l40 = NULL;
    void* l41 = NULL;
    void* l45 = NULL;
    void* l46 = NULL;
    void* l48 = NULL;
    void* l50 = NULL;
    void* l55 = NULL;
    void* l56 = NULL;
    size_t l6, l7, l23, l24, l30, l33, l34, l36, l42, l43, l49, l51, l52, l54;
    vader_string_t l8 = 0;
    vader_string_t l10 = 0;
    vader_string_t l18 = 0;
    vader_string_t l25 = 0;
    vader_string_t l28 = 0;
    vader_string_t l53 = 0;
    vader_box_t l12 = vader_box_null(), l17 = vader_box_null(), l31 = vader_box_null();
    bool l13, l14, l15;
    int32_t l44, l47;
    vader_box_t t0 = vader_box_null();
    int64_t t1;
    void* t2 = NULL;
    vader_box_t* gc_roots[4] = { &l12, &l17, &l31, &t0 };
    void** gc_raw_roots[30] = { &l0, &l1, &l2, &l3, &l4, &l5, &l9, &l11, &l16, &l19, &l20, &l21, &l22, &l26, &l27, &l29, &l32, &l35, &l37, &l38, &l39, &l40, &l41, &l45, &l46, &l48, &l50, &l55, &l56, &t2 };
    vader_string_t* gc_atom_roots[6] = { &l8, &l10, &l18, &l25, &l28, &l53 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 30u, gc_roots, gc_raw_roots, 0u, NULL, 6u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_resolver_CollectedModule_t*) l1)->f_symbols;
    l4 = ((vader_struct_std_collections_MutableMap__string__Symbol_t*) l3)->f_ekeys;
    l5 = ((vader_struct_std_collections_MutableMap__string__Symbol_t*) l3)->f_evals;
    l6 = ((vader_struct_std_collections_MutableMap__string__Symbol_t*) l3)->f_size;
    l7 = (size_t) (int64_t) INT64_C(0);
    {
        loop_12: {
            if ((l7 >= l6)) {
                l20 = ((vader_struct_vader_resolver_CollectedModule_t*) l1)->f_fn_overloads;
                l21 = ((vader_struct_std_collections_MutableMap__string__Symbol___t*) l20)->f_ekeys;
                l22 = ((vader_struct_std_collections_MutableMap__string__Symbol___t*) l20)->f_evals;
                l23 = ((vader_struct_std_collections_MutableMap__string__Symbol___t*) l20)->f_size;
                l24 = (size_t) (int64_t) INT64_C(0);
                {
                    loop_29: {
                        if ((l24 >= l23)) {
                        } else {
                            vader_array_t* _a0_slotarr = ((vader_array_t*) l21);
                            if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                            if ((size_t) l24 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                            t0 = vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l24];
                            l25 = t0.payload.s;
                            vader_array_t* _a1_slotarr = ((vader_array_t*) l22);
                            if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                            if ((size_t) l24 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                            l26 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l24);
                            vader_struct___Tuple_2_a210c611876f2162_t* _a2_obj = (vader_struct___Tuple_2_a210c611876f2162_t*) vader_gc_alloc(sizeof(vader_struct___Tuple_2_a210c611876f2162_t));
                            vader_obj_header_init(_a2_obj, 218u);
                            _a2_obj->f__0 = l25;
                            _a2_obj->f__1 = l26;
                            l27 = (void*) _a2_obj;
                            l28 = ((vader_struct___Tuple_2_a210c611876f2162_t*) l27)->f__0;
                            l29 = ((vader_struct___Tuple_2_a210c611876f2162_t*) l27)->f__1;
                            l30 = (size_t) (int64_t) INT64_C(1);
                            t1 = (l24 + l30);
                            l24 = (size_t) (int64_t) t1;
                            l31 = std_collections_get__string__Any(((vader_struct_vader_resolver_CollectedModule_t*) l0)->f_fn_overloads, l28);
                            if (l31.tag == 0u) {
                                std_collections_put__string__Any(((vader_struct_vader_resolver_CollectedModule_t*) l0)->f_fn_overloads, l28, vader_ref_box(l29));
                            } else {
                                l32 = l29;
                                l33 = ((vader_array_t*) l32)->length;
                                l34 = (size_t) (int64_t) INT64_C(0);
                                {
                                    loop_77: {
                                        if ((l34 < l33)) {
                                            vader_array_t* _a3_slotarr = ((vader_array_t*) l32);
                                            if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                                            if ((size_t) l34 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                                            l35 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l34);
                                            t2 = l31.payload.obj;
                                            vader_array_push((vader_array_t*) t2, vader_ref_box(l35));
                                            l36 = (size_t) (int64_t) INT64_C(1);
                                            t1 = (l34 + l36);
                                            l34 = (size_t) (int64_t) t1;
                                            goto loop_77;
                                        }
                                    }
                                }
                                l37 = ((vader_struct_vader_resolver_CollectedModule_t*) l0)->f_fn_overloads;
                                l38 = l31.payload.obj;
                                std_collections_put__string__Any(l37, l28, vader_ref_box(l38));
                            }
                            goto loop_29;
                        }
                    }
                }
                l39 = ((vader_struct_vader_resolver_CollectedModule_t*) l1)->f_imports;
                l40 = ((vader_struct_std_collections_MutableMap__i32__ImportInfo_t*) l39)->f_ekeys;
                l41 = ((vader_struct_std_collections_MutableMap__i32__ImportInfo_t*) l39)->f_evals;
                l42 = ((vader_struct_std_collections_MutableMap__i32__ImportInfo_t*) l39)->f_size;
                l43 = (size_t) (int64_t) INT64_C(0);
                {
                    loop_126: {
                        if ((l43 >= l42)) {
                        } else {
                            vader_array_t* _a4_slotarr = ((vader_array_t*) l40);
                            if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                            if ((size_t) l43 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                            l44 = ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l43];
                            vader_array_t* _a5_slotarr = ((vader_array_t*) l41);
                            if (_a5_slotarr->buf != NULL && _a5_slotarr->buf->header.forward != NULL) { _a5_slotarr->buf = vader_array_buf_forward(_a5_slotarr->buf); }
                            if ((size_t) l43 >= _a5_slotarr->length) { vader_trap("array index out of bounds"); }
                            l45 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l43);
                            vader_struct___Tuple_2_5e4ffda3bebebd74_t* _a6_obj = (vader_struct___Tuple_2_5e4ffda3bebebd74_t*) vader_gc_alloc(sizeof(vader_struct___Tuple_2_5e4ffda3bebebd74_t));
                            vader_obj_header_init(_a6_obj, 206u);
                            _a6_obj->f__0 = l44;
                            _a6_obj->f__1 = l45;
                            l46 = (void*) _a6_obj;
                            l47 = ((vader_struct___Tuple_2_5e4ffda3bebebd74_t*) l46)->f__0;
                            l48 = ((vader_struct___Tuple_2_5e4ffda3bebebd74_t*) l46)->f__1;
                            l49 = (size_t) (int64_t) INT64_C(1);
                            t1 = (l43 + l49);
                            l43 = (size_t) (int64_t) t1;
                            std_collections_put__i32__Any(((vader_struct_vader_resolver_CollectedModule_t*) l0)->f_imports, l47, vader_ref_box(l48));
                            goto loop_126;
                        }
                    }
                }
                l50 = ((vader_struct_vader_resolver_CollectedModule_t*) l1)->f_import_paths;
                l51 = ((vader_array_t*) l50)->length;
                l52 = (size_t) (int64_t) INT64_C(0);
                {
                    loop_170: {
                        if ((l52 < l51)) {
                            vader_array_t* _a7_slotarr = ((vader_array_t*) l50);
                            if (_a7_slotarr->buf != NULL && _a7_slotarr->buf->header.forward != NULL) { _a7_slotarr->buf = vader_array_buf_forward(_a7_slotarr->buf); }
                            if ((size_t) l52 >= _a7_slotarr->length) { vader_trap("array index out of bounds"); }
                            t0 = vader_array_box_slots(_a7_slotarr->buf)[_a7_slotarr->offset + (size_t) l52];
                            l53 = t0.payload.s;
                            vader_array_push((vader_array_t*) ((vader_struct_vader_resolver_CollectedModule_t*) l0)->f_import_paths, vader_box_string(169u, l53));
                            l54 = (size_t) (int64_t) INT64_C(1);
                            t1 = (l52 + l54);
                            l52 = (size_t) (int64_t) t1;
                            goto loop_170;
                        }
                    }
                }
                l55 = ((vader_struct_vader_resolver_CollectedModule_t*) l0)->f_wildcards;
                l56 = ((vader_struct_vader_resolver_CollectedModule_t*) l1)->f_wildcards;
                vader_array_push_all((vader_array_t*) l55, (vader_array_t*) l56);
                { vader_gc_top = gc_frame.prev; return; }
            }
            vader_array_t* _a8_slotarr = ((vader_array_t*) l4);
            if (_a8_slotarr->buf != NULL && _a8_slotarr->buf->header.forward != NULL) { _a8_slotarr->buf = vader_array_buf_forward(_a8_slotarr->buf); }
            if ((size_t) l7 >= _a8_slotarr->length) { vader_trap("array index out of bounds"); }
            t0 = vader_array_box_slots(_a8_slotarr->buf)[_a8_slotarr->offset + (size_t) l7];
            l8 = t0.payload.s;
            vader_array_t* _a9_slotarr = ((vader_array_t*) l5);
            if (_a9_slotarr->buf != NULL && _a9_slotarr->buf->header.forward != NULL) { _a9_slotarr->buf = vader_array_buf_forward(_a9_slotarr->buf); }
            if ((size_t) l7 >= _a9_slotarr->length) { vader_trap("array index out of bounds"); }
            l3 = vader_array_ref_load_obj(_a9_slotarr->buf, _a9_slotarr->offset + (size_t) l7);
            vader_struct___Tuple_2_cb60e7c5b39cd1d9_t* _a10_obj = (vader_struct___Tuple_2_cb60e7c5b39cd1d9_t*) vader_gc_alloc(sizeof(vader_struct___Tuple_2_cb60e7c5b39cd1d9_t));
            vader_obj_header_init(_a10_obj, 223u);
            _a10_obj->f__0 = l8;
            _a10_obj->f__1 = l3;
            l9 = (void*) _a10_obj;
            l10 = ((vader_struct___Tuple_2_cb60e7c5b39cd1d9_t*) l9)->f__0;
            l11 = ((vader_struct___Tuple_2_cb60e7c5b39cd1d9_t*) l9)->f__1;
            t1 = (l7 + INT64_C(1));
            l7 = (size_t) (int64_t) t1;
            l12 = std_collections_get__string__Any(((vader_struct_vader_resolver_CollectedModule_t*) l0)->f_symbols, l10);
            if (l12.tag == 0u) {
                std_collections_put__string__Any(((vader_struct_vader_resolver_CollectedModule_t*) l0)->f_symbols, l10, vader_ref_box(l11));
            } else {
                if (l12.tag == 889u) {
                    t2 = l12.payload.obj;
                    if (((vader_struct_vader_resolver_symbol_Symbol_t*) t2)->f_kind == INT32_C(0)) {
                        l13 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l11)->f_kind == INT32_C(0);
                    } else {
                        l13 = false;
                    }
                    t2 = l12.payload.obj;
                    if (((vader_struct_vader_resolver_symbol_Symbol_t*) t2)->f_kind == INT32_C(7)) {
                        l14 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l11)->f_kind == INT32_C(7);
                    } else {
                        l14 = false;
                    }
                    if (!(l13)) {
                        l15 = !(l14);
                    } else {
                        l15 = false;
                    }
                    if (l15) {
                        l17 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l11)->f_defined_at;
                        if (l17.tag == 482u) {
                            l16 = l17.payload.obj;
                        } else {
                            if (l17.tag == 0u) {
                                l16 = vader_resolver_zero_span(0u);
                            } else {
                                { vader_gc_top = gc_frame.prev; return; }
                            }
                        }
                        l18 = concat_3(930u, l10, 938u);
                        l19 = vader_diagnostics_resolver_error((uint8_t) (int32_t) INT32_C(25), l16, l18);
                        vader_array_push((vader_array_t*) l2, vader_ref_box(l19));
                    }
                } else {
                    { vader_gc_top = gc_frame.prev; return; }
                }
            }
            goto loop_12;
        }
    }
    l20 = ((vader_struct_vader_resolver_CollectedModule_t*) l1)->f_fn_overloads;
    l21 = ((vader_struct_std_collections_MutableMap__string__Symbol___t*) l20)->f_ekeys;
    l22 = ((vader_struct_std_collections_MutableMap__string__Symbol___t*) l20)->f_evals;
    l23 = ((vader_struct_std_collections_MutableMap__string__Symbol___t*) l20)->f_size;
    l24 = (size_t) (int64_t) INT64_C(0);
    {
        loop_329: {
            if ((l24 >= l23)) {
            } else {
                vader_array_t* _a11_slotarr = ((vader_array_t*) l21);
                if (_a11_slotarr->buf != NULL && _a11_slotarr->buf->header.forward != NULL) { _a11_slotarr->buf = vader_array_buf_forward(_a11_slotarr->buf); }
                if ((size_t) l24 >= _a11_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_box_slots(_a11_slotarr->buf)[_a11_slotarr->offset + (size_t) l24];
                l25 = t0.payload.s;
                vader_array_t* _a12_slotarr = ((vader_array_t*) l22);
                if (_a12_slotarr->buf != NULL && _a12_slotarr->buf->header.forward != NULL) { _a12_slotarr->buf = vader_array_buf_forward(_a12_slotarr->buf); }
                if ((size_t) l24 >= _a12_slotarr->length) { vader_trap("array index out of bounds"); }
                l26 = vader_array_ref_load_obj(_a12_slotarr->buf, _a12_slotarr->offset + (size_t) l24);
                vader_struct___Tuple_2_a210c611876f2162_t* _a13_obj = (vader_struct___Tuple_2_a210c611876f2162_t*) vader_gc_alloc(sizeof(vader_struct___Tuple_2_a210c611876f2162_t));
                vader_obj_header_init(_a13_obj, 218u);
                _a13_obj->f__0 = l25;
                _a13_obj->f__1 = l26;
                l27 = (void*) _a13_obj;
                l28 = ((vader_struct___Tuple_2_a210c611876f2162_t*) l27)->f__0;
                l29 = ((vader_struct___Tuple_2_a210c611876f2162_t*) l27)->f__1;
                l30 = (size_t) (int64_t) INT64_C(1);
                t1 = (l24 + l30);
                l24 = (size_t) (int64_t) t1;
                l31 = std_collections_get__string__Any(((vader_struct_vader_resolver_CollectedModule_t*) l0)->f_fn_overloads, l28);
                if (l31.tag == 0u) {
                    std_collections_put__string__Any(((vader_struct_vader_resolver_CollectedModule_t*) l0)->f_fn_overloads, l28, vader_ref_box(l29));
                } else {
                    l32 = l29;
                    l33 = ((vader_array_t*) l32)->length;
                    l34 = (size_t) (int64_t) INT64_C(0);
                    {
                        loop_377: {
                            if ((l34 < l33)) {
                                vader_array_t* _a14_slotarr = ((vader_array_t*) l32);
                                if (_a14_slotarr->buf != NULL && _a14_slotarr->buf->header.forward != NULL) { _a14_slotarr->buf = vader_array_buf_forward(_a14_slotarr->buf); }
                                if ((size_t) l34 >= _a14_slotarr->length) { vader_trap("array index out of bounds"); }
                                l35 = vader_array_ref_load_obj(_a14_slotarr->buf, _a14_slotarr->offset + (size_t) l34);
                                t2 = l31.payload.obj;
                                vader_array_push((vader_array_t*) t2, vader_ref_box(l35));
                                l36 = (size_t) (int64_t) INT64_C(1);
                                t1 = (l34 + l36);
                                l34 = (size_t) (int64_t) t1;
                                goto loop_377;
                            }
                        }
                    }
                    l37 = ((vader_struct_vader_resolver_CollectedModule_t*) l0)->f_fn_overloads;
                    l38 = l31.payload.obj;
                    std_collections_put__string__Any(l37, l28, vader_ref_box(l38));
                }
                goto loop_329;
            }
        }
    }
    l39 = ((vader_struct_vader_resolver_CollectedModule_t*) l1)->f_imports;
    l40 = ((vader_struct_std_collections_MutableMap__i32__ImportInfo_t*) l39)->f_ekeys;
    l41 = ((vader_struct_std_collections_MutableMap__i32__ImportInfo_t*) l39)->f_evals;
    l42 = ((vader_struct_std_collections_MutableMap__i32__ImportInfo_t*) l39)->f_size;
    l43 = (size_t) (int64_t) INT64_C(0);
    {
        loop_426: {
            if ((l43 >= l42)) {
            } else {
                vader_array_t* _a15_slotarr = ((vader_array_t*) l40);
                if (_a15_slotarr->buf != NULL && _a15_slotarr->buf->header.forward != NULL) { _a15_slotarr->buf = vader_array_buf_forward(_a15_slotarr->buf); }
                if ((size_t) l43 >= _a15_slotarr->length) { vader_trap("array index out of bounds"); }
                l44 = ((int32_t*) _a15_slotarr->buf->slots)[_a15_slotarr->offset + (size_t) l43];
                vader_array_t* _a16_slotarr = ((vader_array_t*) l41);
                if (_a16_slotarr->buf != NULL && _a16_slotarr->buf->header.forward != NULL) { _a16_slotarr->buf = vader_array_buf_forward(_a16_slotarr->buf); }
                if ((size_t) l43 >= _a16_slotarr->length) { vader_trap("array index out of bounds"); }
                l45 = vader_array_ref_load_obj(_a16_slotarr->buf, _a16_slotarr->offset + (size_t) l43);
                vader_struct___Tuple_2_5e4ffda3bebebd74_t* _a17_obj = (vader_struct___Tuple_2_5e4ffda3bebebd74_t*) vader_gc_alloc(sizeof(vader_struct___Tuple_2_5e4ffda3bebebd74_t));
                vader_obj_header_init(_a17_obj, 206u);
                _a17_obj->f__0 = l44;
                _a17_obj->f__1 = l45;
                l46 = (void*) _a17_obj;
                l47 = ((vader_struct___Tuple_2_5e4ffda3bebebd74_t*) l46)->f__0;
                l48 = ((vader_struct___Tuple_2_5e4ffda3bebebd74_t*) l46)->f__1;
                l49 = (size_t) (int64_t) INT64_C(1);
                t1 = (l43 + l49);
                l43 = (size_t) (int64_t) t1;
                std_collections_put__i32__Any(((vader_struct_vader_resolver_CollectedModule_t*) l0)->f_imports, l47, vader_ref_box(l48));
                goto loop_426;
            }
        }
    }
    l50 = ((vader_struct_vader_resolver_CollectedModule_t*) l1)->f_import_paths;
    l51 = ((vader_array_t*) l50)->length;
    l52 = (size_t) (int64_t) INT64_C(0);
    {
        loop_470: {
            if ((l52 < l51)) {
                vader_array_t* _a18_slotarr = ((vader_array_t*) l50);
                if (_a18_slotarr->buf != NULL && _a18_slotarr->buf->header.forward != NULL) { _a18_slotarr->buf = vader_array_buf_forward(_a18_slotarr->buf); }
                if ((size_t) l52 >= _a18_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_box_slots(_a18_slotarr->buf)[_a18_slotarr->offset + (size_t) l52];
                l53 = t0.payload.s;
                vader_array_push((vader_array_t*) ((vader_struct_vader_resolver_CollectedModule_t*) l0)->f_import_paths, vader_box_string(169u, l53));
                l54 = (size_t) (int64_t) INT64_C(1);
                t1 = (l52 + l54);
                l52 = (size_t) (int64_t) t1;
                goto loop_470;
            }
        }
    }
    l55 = ((vader_struct_vader_resolver_CollectedModule_t*) l0)->f_wildcards;
    l56 = ((vader_struct_vader_resolver_CollectedModule_t*) l1)->f_wildcards;
    vader_array_push_all((vader_array_t*) l55, (vader_array_t*) l56);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_resolver_mint_local(void* l0, int32_t l1, vader_string_t l2, void* l3) {
    void* l4 = NULL;
    void* l6 = NULL;
    vader_string_t l5 = 0;
    vader_string_t l7 = 0;
    void* t0 = NULL;
    void** gc_raw_roots[5] = { &l0, &l3, &l4, &l6, &t0 };
    vader_string_t* gc_atom_roots[3] = { &l2, &l5, &l7 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    if (l2 == 2390u) {
        l4 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_diags;
        l5 = concat_3(930u, l2, 930u);
        l6 = vader_diagnostics_resolver_error((uint8_t) (int32_t) INT32_C(18), l3, l5);
        vader_array_push((vader_array_t*) l4, vader_ref_box(l6));
    }
    l4 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_factory;
    l5 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_module_path;
    l7 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_module_path;
    t0 = vader_resolver_symbol_make(l4, l1, l2, l5, l7, (uint8_t) (int32_t) INT32_C(1), vader_ref_box(l3));
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_box_t vader_resolver_misplaced_module_at(vader_string_t l0, void* l1) {
    void* l2 = NULL;
    void* l7 = NULL;
    size_t l3, l4;
    vader_box_t l5 = vader_box_null(), l8 = vader_box_null();
    vader_string_t l6 = 0;
    bool l9;
    void* t0 = NULL;
    int64_t t1;
    bool t2;
    vader_string_t t3 = 0;
    vader_box_t t4 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l5, &l8, &t4 };
    void** gc_raw_roots[4] = { &l1, &l2, &l7, &t0 };
    vader_string_t* gc_atom_roots[3] = { &l0, &l6, &t3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(51u, 0u, 13u, 700u);
    l2 = (void*) _a0_arr;
    l3 = ((vader_array_t*) l1)->length;
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_8: {
            if ((l4 < l3)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l4 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
                l5 = vader_resolver_rooted_candidate(t0, l0);
                if (l5.tag == 0u) {
                    t1 = (l4 + INT64_C(1));
                    l4 = (size_t) (int64_t) t1;
                    goto loop_8;
                }
                l6 = l5.payload.s;
                t2 = std_io_is_dir(l6);
                if (!(t2)) {
                    t1 = (l4 + INT64_C(1));
                    l4 = (size_t) (int64_t) t1;
                    goto loop_8;
                }
                l8 = vader_resolver_scan_folder(l6, l2);
                if (l8.tag == 0u) {
                    t1 = (l4 + INT64_C(1));
                    l4 = (size_t) (int64_t) t1;
                    goto loop_8;
                }
                l7 = l8.payload.obj;
                t3 = ((vader_struct_vader_resolver_FolderBucket_t*) l7)->f_name;
                if (t3 != 0u) {
                    t3 = ((vader_struct_vader_resolver_FolderBucket_t*) l7)->f_name;
                    l9 = t3 != l0;
                } else {
                    l9 = false;
                }
                if (l9) {
                    t3 = ((vader_struct_vader_resolver_FolderBucket_t*) l7)->f_name;
                    t4 = vader_box_string(169u, t3);
                    { vader_box_t __vret = t4; vader_gc_top = gc_frame.prev; return __vret; }
                }
                t1 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t1;
                goto loop_8;
            }
        }
    }
    t4 = vader_box_obj(0u, NULL);
    { vader_box_t __vret = t4; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

void* vader_resolver_module_index_by_name(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l8 = NULL;
    size_t l5, l6;
    vader_string_t l7 = 0;
    vader_string_t l9 = 0;
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    int64_t t2;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[7] = { &l0, &l1, &l2, &l3, &l4, &l8, &t1 };
    vader_string_t* gc_atom_roots[2] = { &l7, &l9 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 169u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(16u, 0u, 0u, 180u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 172u);
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
    l2 = ((vader_struct_vader_resolver_LoadedProject_t*) l0)->f_modules;
    l3 = ((vader_struct_std_collections_MutableMap__string__LoadedModule_t*) l2)->f_ekeys;
    l4 = ((vader_struct_std_collections_MutableMap__string__LoadedModule_t*) l2)->f_evals;
    l5 = ((vader_struct_std_collections_MutableMap__string__LoadedModule_t*) l2)->f_size;
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
                vader_struct___Tuple_2_122be429df783e3b_t* _a6_obj = (vader_struct___Tuple_2_122be429df783e3b_t*) vader_gc_alloc(sizeof(vader_struct___Tuple_2_122be429df783e3b_t));
                vader_obj_header_init(_a6_obj, 202u);
                _a6_obj->f__0 = l7;
                _a6_obj->f__1 = l2;
                t1 = (void*) _a6_obj;
                l8 = ((vader_struct___Tuple_2_122be429df783e3b_t*) t1)->f__1;
                t2 = (l6 + INT64_C(1));
                l6 = (size_t) (int64_t) t2;
                l9 = ((vader_struct_vader_resolver_Module_t*) ((vader_struct_vader_resolver_LoadedModule_t*) l8)->f_module)->f_module_name;
                std_collections_put__string__Any(l1, l9, vader_ref_box(l8));
                goto loop_26;
            }
        }
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static bool vader_resolver_names_equal(vader_box_t l0, vader_box_t l1) {
    vader_string_t l2, l3;
    if (l0.tag == 0u) {
        return l1.tag == 0u;
    }
    if (l1.tag == 0u) {
        return false;
    }
    l2 = l0.payload.s;
    l3 = l1.payload.s;
    return l2 == l3;
}

static void* vader_resolver_new_import_table(void) {
    void* l0 = NULL;
    void* l1 = NULL;
    void* l2 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(9u, 0u, 7u, 172u);
    l0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(16u, 0u, 0u, 180u);
    l1 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 172u);
    l2 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__i32__Any_t* _a3_obj = (vader_struct_std_collections_MutableMap__i32__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__Any_t));
    vader_obj_header_init(_a3_obj, 283u);
    _a3_obj->f_ekeys = l0;
    _a3_obj->f_evals = l1;
    _a3_obj->f_index = l2;
    _a3_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    t0 = (void*) _a3_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_resolver_new_import_target_table(void) {
    void* l0 = NULL;
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l3, &l4, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 6u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(9u, 0u, 7u, 172u);
    l0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(16u, 0u, 0u, 180u);
    l1 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 172u);
    l2 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__i32__Any_t* _a3_obj = (vader_struct_std_collections_MutableMap__i32__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__Any_t));
    vader_obj_header_init(_a3_obj, 283u);
    _a3_obj->f_ekeys = l0;
    _a3_obj->f_evals = l1;
    _a3_obj->f_index = l2;
    _a3_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l0 = (void*) _a3_obj;
    vader_array_t* _a4_arr = vader_array_new(9u, 0u, 7u, 172u);
    l1 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_new(8u, 0u, 0u, 169u);
    l2 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(9u, 0u, 7u, 172u);
    l3 = (void*) _a6_arr;
    vader_struct_std_collections_MutableMap__i32__string_t* _a7_obj = (vader_struct_std_collections_MutableMap__i32__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__string_t));
    vader_obj_header_init(_a7_obj, 315u);
    _a7_obj->f_ekeys = l1;
    _a7_obj->f_evals = l2;
    _a7_obj->f_index = l3;
    _a7_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a7_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a7_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l1 = (void*) _a7_obj;
    vader_array_t* _a8_arr = vader_array_new(9u, 0u, 7u, 172u);
    l2 = (void*) _a8_arr;
    vader_array_t* _a9_arr = vader_array_new(6u, 0u, 12u, 167u);
    l3 = (void*) _a9_arr;
    vader_array_t* _a10_arr = vader_array_new(9u, 0u, 7u, 172u);
    l4 = (void*) _a10_arr;
    vader_struct_std_collections_MutableMap__i32__bool_t* _a11_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
    vader_obj_header_init(_a11_obj, 311u);
    _a11_obj->f_ekeys = l2;
    _a11_obj->f_evals = l3;
    _a11_obj->f_index = l4;
    _a11_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a11_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a11_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l2 = (void*) _a11_obj;
    vader_struct_vader_resolver_ImportTargetTable_t* _a12_obj = (vader_struct_vader_resolver_ImportTargetTable_t*) vader_gc_alloc(sizeof(vader_struct_vader_resolver_ImportTargetTable_t));
    vader_obj_header_init(_a12_obj, 874u);
    _a12_obj->f_symbol_targets = l0;
    _a12_obj->f_namespace_targets = l1;
    _a12_obj->f_missing = l2;
    t0 = (void*) _a12_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_resolver_new_scope(void* l0) {
    void* t0 = NULL;
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(18u, 1u, 13u, 355u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = l0;
    t0 = (void*) _a0_arr;
    vader_struct_vader_resolver_Scope_t* _a1_obj = (vader_struct_vader_resolver_Scope_t*) vader_gc_alloc(sizeof(vader_struct_vader_resolver_Scope_t));
    vader_obj_header_init(_a1_obj, 883u);
    _a1_obj->f_frames = t0;
    t0 = (void*) _a1_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_resolver_new_subst(void) {
    void* l0 = NULL;
    void* l1 = NULL;
    void* l2 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 169u);
    l0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(16u, 0u, 0u, 180u);
    l1 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 172u);
    l2 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__string__Any_t* _a3_obj = (vader_struct_std_collections_MutableMap__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__Any_t));
    vader_obj_header_init(_a3_obj, 321u);
    _a3_obj->f_ekeys = l0;
    _a3_obj->f_evals = l1;
    _a3_obj->f_index = l2;
    _a3_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    t0 = (void*) _a3_obj;
    vader_struct_vader_resolver_Subst_t* _a4_obj = (vader_struct_vader_resolver_Subst_t*) vader_gc_alloc(sizeof(vader_struct_vader_resolver_Subst_t));
    vader_obj_header_init(_a4_obj, 886u);
    _a4_obj->f_entries = t0;
    t0 = (void*) _a4_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_resolver_next_clone_span(void* l0) {
    int32_t l1, l2;
    vader_string_t l3 = 0;
    void* l4 = NULL;
    int32_t t0;
    void* t1 = NULL;
    void** gc_raw_roots[3] = { &l0, &l4, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct_vader_resolver_StampCtx_t*) l0)->f_counter;
    t0 = ((vader_struct_vader_resolver_StampCtx_t*) l0)->f_counter;
    l2 = (t0 + INT32_C(1));
    ((vader_struct_vader_resolver_StampCtx_t*) l0)->f_counter = l2;
    VADER_WRITE_BARRIER((vader_struct_vader_resolver_StampCtx_t*) l0);
    l3 = ((vader_struct_vader_resolver_StampCtx_t*) l0)->f_file;
    l2 = ((vader_struct_vader_resolver_StampCtx_t*) l0)->f_base_line;
    vader_struct_toolchain_span_Position_t* _a0_obj = (vader_struct_toolchain_span_Position_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Position_t));
    vader_obj_header_init(_a0_obj, 481u);
    _a0_obj->f_file = l3;
    _a0_obj->f_offset = (size_t) (int64_t) INT64_C(0);
    _a0_obj->f_line = l2;
    _a0_obj->f_column = l1;
    l4 = (void*) _a0_obj;
    vader_struct_toolchain_span_Span_t* _a1_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
    vader_obj_header_init(_a1_obj, 482u);
    _a1_obj->f_start = l4;
    _a1_obj->f_end = l4;
    t1 = (void*) _a1_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static uint8_t vader_resolver_origin_of_root(vader_string_t l0) {
    vader_string_t t0 = 0;
    bool t1;
    vader_string_t* gc_atom_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = vader_resolver_join_path(l0, 2045u);
    t1 = std_io_exists(t0);
    if (t1) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) (int32_t) INT32_C(1); }
    }
    { vader_gc_top = gc_frame.prev; return (uint8_t) (int32_t) INT32_C(0); }
    vader_gc_top = gc_frame.prev;
}

static void* vader_resolver_parse_module_files(void* l0, void* l1, void* l2, void* l3) {
    void* l4 = NULL;
    void* l5 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    void* l14 = NULL;
    void* l15 = NULL;
    void* l16 = NULL;
    size_t l6, l7, l12, l13;
    vader_string_t l8 = 0;
    vader_string_t l9 = 0;
    vader_box_t t0 = vader_box_null();
    int64_t t1;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[11] = { &l0, &l1, &l2, &l3, &l4, &l5, &l10, &l11, &l14, &l15, &l16 };
    vader_string_t* gc_atom_roots[2] = { &l8, &l9 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 11u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(87u, 0u, 13u, 884u);
    l4 = (void*) _a0_arr;
    l5 = l0;
    l6 = ((vader_array_t*) l5)->length;
    l7 = (size_t) (int64_t) INT64_C(0);
    {
        loop_9: {
            if ((l7 < l6)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l7 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l7];
                l8 = t0.payload.s;
                l9 = vader_resolver_read_with_overlay(l2, l8);
                if (l9 == 0u) {
                    t1 = (l7 + INT64_C(1));
                    l7 = (size_t) (int64_t) t1;
                    goto loop_9;
                }
                l10 = vader_parser_parse_source(l9, l8);
                l11 = ((vader_struct_vader_parser_ParsedSource_t*) l10)->f_errors;
                l12 = ((vader_array_t*) l11)->length;
                l13 = (size_t) (int64_t) INT64_C(0);
                {
                    loop_43: {
                        if ((l13 < l12)) {
                            vader_array_t* _a2_slotarr = ((vader_array_t*) l11);
                            if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                            if ((size_t) l13 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                            l14 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l13);
                            vader_array_push((vader_array_t*) l1, vader_ref_box(l14));
                            t1 = (l13 + INT64_C(1));
                            l13 = (size_t) (int64_t) t1;
                            goto loop_43;
                        }
                    }
                }
                vader_parser_assign_program_ids(((vader_struct_vader_parser_ParsedSource_t*) l10)->f_program, l3);
                l15 = ((vader_struct_vader_parser_ParsedSource_t*) l10)->f_program;
                vader_struct_vader_resolver_SourceFile_t* _a3_obj = (vader_struct_vader_resolver_SourceFile_t*) vader_gc_alloc(sizeof(vader_struct_vader_resolver_SourceFile_t));
                vader_obj_header_init(_a3_obj, 884u);
                _a3_obj->f_path = l8;
                _a3_obj->f_content = l9;
                _a3_obj->f_program = l15;
                _a3_obj->f_id_factory = l3;
                l16 = (void*) _a3_obj;
                vader_array_push((vader_array_t*) l4, vader_ref_box(l16));
                t1 = (l7 + INT64_C(1));
                l7 = (size_t) (int64_t) t1;
                goto loop_9;
            }
        }
    }
    { void* __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_resolver_plain_root(vader_string_t l0, uint8_t l1) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_struct_vader_resolver_IncludePath_t* _a0_obj = (vader_struct_vader_resolver_IncludePath_t*) vader_gc_alloc(sizeof(vader_struct_vader_resolver_IncludePath_t));
    vader_obj_header_init(_a0_obj, 875u);
    _a0_obj->f_dir = l0;
    _a0_obj->f_prefix = 0u;
    _a0_obj->f_merge = false;
    _a0_obj->f_origin = l1;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void vader_resolver_pop(void* l0) {
    size_t l1, l3;
    void* l2 = NULL;
    void* l4 = NULL;
    int64_t t0;
    void** gc_raw_roots[3] = { &l0, &l2, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = ((vader_array_t*) ((vader_struct_vader_resolver_Scope_t*) l0)->f_frames)->length;
    if (l1 == INT64_C(0)) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_array_t* _a0_arr = vader_array_new(18u, 0u, 13u, 355u);
    l2 = (void*) _a0_arr;
    t0 = (l1 - INT64_C(1));
    l1 = (size_t) (int64_t) t0;
    l3 = (size_t) (int64_t) INT64_C(0);
    {
        loop_17: {
            if ((l3 < l1)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_resolver_Scope_t*) l0)->f_frames);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l3 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                l4 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l3);
                vader_array_push((vader_array_t*) l2, vader_ref_box(l4));
                t0 = (l3 + INT64_C(1));
                l3 = (size_t) (int64_t) t0;
                goto loop_17;
            }
        }
    }
    ((vader_struct_vader_resolver_Scope_t*) l0)->f_frames = l2;
    VADER_WRITE_BARRIER((vader_struct_vader_resolver_Scope_t*) l0);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_resolver_preresolve_imports(void* l0, void* l1, void* l2, void* l3) {
    void* l4 = NULL;
    void* l7 = NULL;
    size_t l5, l6, l8, l9;
    vader_box_t l10 = vader_box_null();
    void* t0 = NULL;
    vader_string_t t1 = 0;
    int64_t t2;
    vader_box_t* gc_roots[1] = { &l10 };
    void** gc_raw_roots[7] = { &l0, &l1, &l2, &l3, &l4, &l7, &t0 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l4 = l0;
    l5 = ((vader_array_t*) l4)->length;
    l6 = (size_t) (int64_t) INT64_C(0);
    {
        loop_7: {
            if ((l6 < l5)) {
                vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
                if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                if ((size_t) l6 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l6);
                l7 = ((vader_struct_toolchain_ast_Program_t*) ((vader_struct_vader_resolver_SourceFile_t*) t0)->f_program)->f_decls;
                l8 = ((vader_array_t*) l7)->length;
                l9 = (size_t) (int64_t) INT64_C(0);
                {
                    loop_23: {
                        if ((l9 < l8)) {
                            vader_array_t* _a1_slotarr = ((vader_array_t*) l7);
                            if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                            if ((size_t) l9 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                            l10 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l9);
                            if (l10.tag == 431u) {
                                t0 = l10.payload.obj;
                                t1 = ((vader_struct_toolchain_ast_ImportDecl_t*) t0)->f_path;
                                vader_resolver_resolve_lazy(t1, l1, l2, l3);
                            }
                            t2 = (l9 + INT64_C(1));
                            l9 = (size_t) (int64_t) t2;
                            goto loop_23;
                        }
                    }
                }
                t2 = (l6 + INT64_C(1));
                l6 = (size_t) (int64_t) t2;
                goto loop_7;
            }
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_resolver_project_include_paths(vader_box_t l0, void* l1, void* l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void* l9 = NULL;
    size_t l5, l6;
    vader_string_t l7 = 0;
    vader_string_t l11 = 0;
    uint8_t l8;
    vader_box_t l10 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    int64_t t1;
    vader_string_t t2 = 0;
    vader_box_t* gc_roots[3] = { &l0, &l10, &t0 };
    void** gc_raw_roots[5] = { &l1, &l2, &l3, &l4, &l9 };
    vader_string_t* gc_atom_roots[3] = { &l7, &l11, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(84u, 0u, 13u, 875u);
    l3 = (void*) _a0_arr;
    l4 = l2;
    l5 = ((vader_array_t*) l4)->length;
    l6 = (size_t) (int64_t) INT64_C(0);
    {
        loop_9: {
            if ((l6 < l5)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) l4);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l6 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l6];
                l7 = t0.payload.s;
                l8 = vader_resolver_origin_of_root(l7);
                l9 = vader_resolver_plain_root(l7, l8);
                vader_array_push((vader_array_t*) l3, vader_ref_box(l9));
                t1 = (l6 + INT64_C(1));
                l6 = (size_t) (int64_t) t1;
                goto loop_9;
            }
        }
    }
    l10 = vader_resolver_sidecar_root(1810u, 2045u);
    if (!(l10.tag == 0u)) {
        t2 = l10.payload.s;
        l4 = vader_resolver_plain_root(t2, (uint8_t) (int32_t) INT32_C(1));
        vader_array_push((vader_array_t*) l3, vader_ref_box(l4));
    }
    if (l0.tag == 169u) {
        t2 = l0.payload.s;
        l4 = vader_resolver_plain_root(t2, (uint8_t) (int32_t) INT32_C(0));
        vader_array_push((vader_array_t*) l3, vader_ref_box(l4));
        l4 = ((vader_struct_vader_resolver_Manifest_t*) l1)->f_include_paths;
        l5 = ((vader_array_t*) l4)->length;
        l6 = (size_t) (int64_t) INT64_C(0);
        {
            loop_70: {
                if ((l6 < l5)) {
                    vader_array_t* _a2_slotarr = ((vader_array_t*) l4);
                    if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                    if ((size_t) l6 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                    t0 = vader_array_box_slots(_a2_slotarr->buf)[_a2_slotarr->offset + (size_t) l6];
                    l7 = t0.payload.s;
                    t2 = l0.payload.s;
                    l11 = vader_resolver_join_path(t2, l7);
                    l8 = vader_resolver_origin_of_root(l11);
                    l9 = vader_resolver_plain_root(l11, l8);
                    vader_array_push((vader_array_t*) l3, vader_ref_box(l9));
                    t1 = (l6 + INT64_C(1));
                    l6 = (size_t) (int64_t) t1;
                    goto loop_70;
                }
            }
        }
    } else {
        if (l0.tag == 0u) {
        } else {
            vader_unreachable("unreachable return in vader_resolver$project_include_paths");
        }
    }
    if (l10.tag == 0u) {
        l8 = vader_resolver_origin_of_root(1810u);
        l4 = vader_resolver_plain_root(1810u, l8);
        vader_array_push((vader_array_t*) l3, vader_ref_box(l4));
    }
    { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_resolver_provided_names(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    size_t l4, l5;
    vader_string_t l6 = 0;
    void* t0 = NULL;
    int64_t t1;
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l6 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 169u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(6u, 0u, 12u, 167u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 172u);
    l3 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__string__bool_t* _a3_obj = (vader_struct_std_collections_MutableMap__string__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__bool_t));
    vader_obj_header_init(_a3_obj, 359u);
    _a3_obj->f_ekeys = l1;
    _a3_obj->f_evals = l2;
    _a3_obj->f_index = l3;
    _a3_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    t0 = (void*) _a3_obj;
    vader_struct_std_collections_MutableSet__string_t* _a4_obj = (vader_struct_std_collections_MutableSet__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__string_t));
    vader_obj_header_init(_a4_obj, 380u);
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
                t0 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l5);
                l6 = ((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_name;
                std_collections_add__string(l1, l6);
                t1 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t1;
                goto loop_22;
            }
        }
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void vader_resolver_push(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct_vader_resolver_Scope_t*) l0)->f_frames;
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 169u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(16u, 0u, 0u, 180u);
    l3 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 172u);
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
    vader_array_push((vader_array_t*) l1, vader_ref_box(l2));
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_resolver_read_manifest(vader_string_t l0) {
    void* l1 = NULL;
    void* l4 = NULL;
    vader_string_t l2 = 0;
    vader_box_t l3 = vader_box_null();
    size_t l5, l6;
    bool t0;
    void* t1 = NULL;
    int64_t t2;
    vader_box_t* gc_roots[1] = { &l3 };
    void** gc_raw_roots[3] = { &l1, &l4, &t1 };
    vader_string_t* gc_atom_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 169u);
    l1 = (void*) _a0_arr;
    l2 = vader_resolver_join_path(l0, 2301u);
    t0 = std_io_exists(l2);
    if (!(t0)) {
        vader_struct_vader_resolver_Manifest_t* _a1_obj = (vader_struct_vader_resolver_Manifest_t*) vader_gc_alloc(sizeof(vader_struct_vader_resolver_Manifest_t));
        vader_obj_header_init(_a1_obj, 878u);
        _a1_obj->f_include_paths = l1;
        t1 = (void*) _a1_obj;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = vader_resolver_try_read(l2);
    if (l3.tag == 0u) {
        l2 = 0u;
    } else {
        l2 = l3.payload.s;
    }
    if (l2 == 0u) {
        vader_struct_vader_resolver_Manifest_t* _a2_obj = (vader_struct_vader_resolver_Manifest_t*) vader_gc_alloc(sizeof(vader_struct_vader_resolver_Manifest_t));
        vader_obj_header_init(_a2_obj, 878u);
        _a2_obj->f_include_paths = l1;
        t1 = (void*) _a2_obj;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = json_parse(l2);
    if (l3.tag == 280u) {
        t1 = l3.payload.obj;
        l3 = std_collections_get__string__Any(((vader_struct_json_JsonObject_t*) t1)->f_entries, 1719u);
        if (l3.tag == 275u) {
            t1 = l3.payload.obj;
            l4 = ((vader_struct_json_JsonArray_t*) t1)->f_items;
            l5 = ((vader_array_t*) l4)->length;
            l6 = (size_t) (int64_t) INT64_C(0);
            {
                loop_55: {
                    if ((l6 < l5)) {
                        vader_array_t* _a3_slotarr = ((vader_array_t*) l4);
                        if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                        if ((size_t) l6 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                        l3 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l6);
                        if (l3.tag == 281u) {
                            t1 = l3.payload.obj;
                            l2 = ((vader_struct_json_JsonString_t*) t1)->f_value;
                            vader_array_push((vader_array_t*) l1, vader_box_string(169u, l2));
                        }
                        t2 = (l6 + INT64_C(1));
                        l6 = (size_t) (int64_t) t2;
                        goto loop_55;
                    }
                }
            }
        }
    }
    vader_struct_vader_resolver_Manifest_t* _a4_obj = (vader_struct_vader_resolver_Manifest_t*) vader_gc_alloc(sizeof(vader_struct_vader_resolver_Manifest_t));
    vader_obj_header_init(_a4_obj, 878u);
    _a4_obj->f_include_paths = l1;
    t1 = (void*) _a4_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_string_t vader_resolver_read_with_overlay(void* l0, vader_string_t l1) {
    vader_box_t l2 = vader_box_null();
    vader_string_t t0 = 0;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[2] = { &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = std_collections_get__string__string(l0, l1);
    if (!(l2.tag == 0u)) {
        t0 = l2.payload.s;
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = std_io_read_file_string(l1, (size_t) (int64_t) INT64_C(16777216));
    if (l2.tag == 169u) {
        t0 = l2.payload.s;
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return 0u; }
    vader_gc_top = gc_frame.prev;
}

static void vader_resolver_report_uncovered(void* l0, void* l1, void* l2, void* l3, void* l4) {
    void* l5 = NULL;
    void* l8 = NULL;
    void* l17 = NULL;
    void* l23 = NULL;
    size_t l6, l7, l9, l10, l24;
    vader_box_t l11 = vader_box_null(), l12 = vader_box_null(), l16 = vader_box_null();
    vader_string_t l13 = 0;
    vader_string_t l14 = 0;
    vader_string_t l15 = 0;
    vader_string_t l18 = 0;
    vader_string_t l19 = 0;
    vader_string_t l20 = 0;
    vader_string_t l21 = 0;
    vader_string_t l22 = 0;
    void* t0 = NULL;
    int64_t t1;
    bool t2;
    vader_box_t t3 = vader_box_null();
    vader_box_t* gc_roots[4] = { &l11, &l12, &l16, &t3 };
    void** gc_raw_roots[10] = { &l0, &l1, &l2, &l3, &l4, &l5, &l8, &l17, &l23, &t0 };
    vader_string_t* gc_atom_roots[8] = { &l13, &l14, &l15, &l18, &l19, &l20, &l21, &l22 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 10u, gc_roots, gc_raw_roots, 0u, NULL, 8u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l5 = l0;
    l6 = ((vader_array_t*) l5)->length;
    l7 = (size_t) (int64_t) INT64_C(0);
    {
        loop_7: {
            if ((l7 < l6)) {
                vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
                if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                if ((size_t) l7 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l7);
                l8 = ((vader_struct_toolchain_ast_Program_t*) ((vader_struct_vader_resolver_SourceFile_t*) t0)->f_program)->f_decls;
                l9 = ((vader_array_t*) l8)->length;
                l10 = (size_t) (int64_t) INT64_C(0);
                {
                    loop_23: {
                        if ((l10 < l9)) {
                            vader_array_t* _a1_slotarr = ((vader_array_t*) l8);
                            if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                            if ((size_t) l10 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                            l11 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l10);
                            if (l11.tag == 421u) {
                                t0 = l11.payload.obj;
                                l12 = vader_resolver_target_selectors(((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_decorators);
                                if (l12.tag == 0u) {
                                    t1 = (l10 + INT64_C(1));
                                    l10 = (size_t) (int64_t) t1;
                                    goto loop_23;
                                }
                                t0 = l12.payload.obj;
                                t2 = ((vader_struct_vader_resolver_TargetSelectors_t*) t0)->f_is_bare;
                                if (!(t2)) {
                                    t1 = (l10 + INT64_C(1));
                                    l10 = (size_t) (int64_t) t1;
                                    goto loop_23;
                                }
                                t0 = l11.payload.obj;
                                if (!(((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_body.tag == 0u)) {
                                    t1 = (l10 + INT64_C(1));
                                    l10 = (size_t) (int64_t) t1;
                                    goto loop_23;
                                }
                                t0 = l11.payload.obj;
                                l13 = ((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_name;
                                t3 = std_collections_get__string__Any(l2, l13);
                                if (!(t3.tag == 0u)) {
                                    t1 = (l10 + INT64_C(1));
                                    l10 = (size_t) (int64_t) t1;
                                    goto loop_23;
                                }
                                t0 = l11.payload.obj;
                                t2 = vader_resolver_is_host_bound(t0);
                                if (t2) {
                                    t1 = (l10 + INT64_C(1));
                                    l10 = (size_t) (int64_t) t1;
                                    goto loop_23;
                                }
                                t0 = l11.payload.obj;
                                l15 = ((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_name;
                                l16 = std_collections_get__string__string(l3, l15);
                                if (l16.tag == 0u) {
                                    l14 = 315u;
                                } else {
                                    l14 = l16.payload.s;
                                }
                                t0 = l11.payload.obj;
                                l17 = ((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_name_span;
                                t0 = l11.payload.obj;
                                l18 = ((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_name;
                                l19 = vader_target_display_target(l1);
                                l20 = concat_5(930u, l18, 963u, l19, 943u);
                                l21 = concat_2(1774u, l14);
                                l22 = concat_2(l20, l21);
                                l23 = vader_diagnostics_resolver_error((uint8_t) (int32_t) INT32_C(40), l17, l22);
                                vader_array_push((vader_array_t*) l4, vader_ref_box(l23));
                                l24 = (size_t) (int64_t) INT64_C(1);
                                t1 = (l10 + l24);
                                l10 = (size_t) (int64_t) t1;
                                goto loop_23;
                            }
                            l24 = (size_t) (int64_t) INT64_C(1);
                            t1 = (l10 + l24);
                            l10 = (size_t) (int64_t) t1;
                            goto loop_23;
                        }
                    }
                }
                t1 = (l7 + INT64_C(1));
                l7 = (size_t) (int64_t) t1;
                goto loop_7;
            }
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

void* vader_resolver_required_methods(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l5 = NULL;
    size_t l3, l4;
    vader_box_t l6 = vader_box_null();
    int64_t t0;
    vader_box_t* gc_roots[1] = { &l6 };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(24u, 0u, 13u, 421u);
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
                l5 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
                l6 = ((vader_struct_toolchain_ast_FnDecl_t*) l5)->f_body;
                if (l6.tag == 0u) {
                    vader_array_push((vader_array_t*) l1, vader_ref_box(l5));
                } else {
                    if (l6.tag == 398u) {
                    } else {
                        vader_unreachable("unreachable return in vader_resolver$required_methods");
                    }
                }
                t0 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                goto loop_9;
            }
        }
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_box_t vader_resolver_resolve_decl(vader_box_t l0, void* l1, void* l2, void* l3) {
    vader_box_t l4 = vader_box_null();
    vader_string_t l5 = 0;
    void* l6 = NULL;
    void* l7 = NULL;
    void* t0 = NULL;
    bool t1;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l0, &l4, &t2 };
    void** gc_raw_roots[6] = { &l1, &l2, &l3, &l6, &l7, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    if (l0.tag == 463u) {
        t0 = l0.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 421u) {
        t0 = l0.payload.obj;
        l4 = vader_resolver_target_selectors(((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_decorators);
        if (l4.tag == 0u) {
            t0 = l0.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t0 = l4.payload.obj;
        t1 = ((vader_struct_vader_resolver_TargetSelectors_t*) t0)->f_is_bare;
        if (t1) {
            t0 = l0.payload.obj;
            l5 = ((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_name;
            l4 = std_collections_get__string__Any(l2, l5);
            if (l4.tag == 0u) {
                t0 = l0.payload.obj;
                { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l6 = l0.payload.obj;
            l7 = l4.payload.obj;
            t0 = vader_resolver_graft_body(l6, l7);
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t2 = vader_box_obj(0u, NULL);
        { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_box_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

void* vader_resolver_resolve_import_redirect(void* l0, void* l1) {
    void* l2;
    int32_t l3;
    vader_box_t l4;
    if (((vader_struct_vader_resolver_symbol_Symbol_t*) l0)->f_kind != INT32_C(7)) {
        return l0;
    }
    l2 = ((vader_struct_vader_resolver_ImportTargetTable_t*) l1)->f_symbol_targets;
    l3 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l0)->f_id;
    l4 = std_collections_get__i32__Any(l2, l3);
    if (l4.tag == 0u) {
        return l0;
    }
    l2 = l4.payload.obj;
    return ((vader_struct_vader_resolver_SymbolTarget_t*) l2)->f_symbol;
}

static vader_box_t vader_resolver_resolve_lazy(vader_string_t l0, void* l1, void* l2, void* l3) {
    vader_box_t l4 = vader_box_null(), l10 = vader_box_null(), l13 = vader_box_null();
    uint8_t l5;
    void* l6 = NULL;
    void* l12 = NULL;
    void* l14 = NULL;
    void* l16 = NULL;
    size_t l7, l8;
    bool l9;
    vader_string_t l11 = 0;
    vader_string_t l15 = 0;
    void* t0 = NULL;
    bool t1;
    int64_t t2;
    vader_string_t t3 = 0;
    vader_box_t t4 = vader_box_null();
    vader_box_t* gc_roots[4] = { &l4, &l10, &l13, &t4 };
    void** gc_raw_roots[8] = { &l1, &l2, &l3, &l6, &l12, &l14, &l16, &t0 };
    vader_string_t* gc_atom_roots[4] = { &l0, &l11, &l15, &t3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l4 = std_collections_get__string__Any(l2, l0);
    if (l4.tag == 870u) {
        t0 = l4.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = vader_box_obj(0u, NULL);
    l5 = (uint8_t) (int32_t) INT32_C(0);
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 169u);
    l6 = (void*) _a0_arr;
    l7 = ((vader_array_t*) l1)->length;
    l8 = (size_t) (int64_t) INT64_C(0);
    {
        loop_22: {
            if ((l8 < l7)) {
                if (!(l4.tag == 0u)) {
                    vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
                    if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                    if ((size_t) l8 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                    t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l8);
                    t1 = ((vader_struct_vader_resolver_IncludePath_t*) t0)->f_merge;
                    l9 = !(t1);
                } else {
                    l9 = false;
                }
                if (l9) {
                    t2 = (l8 + INT64_C(1));
                    l8 = (size_t) (int64_t) t2;
                    goto loop_22;
                }
                vader_array_t* _a2_slotarr = ((vader_array_t*) l1);
                if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                if ((size_t) l8 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l8);
                l10 = vader_resolver_rooted_candidate(t0, l0);
                if (l10.tag == 0u) {
                    t2 = (l8 + INT64_C(1));
                    l8 = (size_t) (int64_t) t2;
                    goto loop_22;
                }
                l11 = l10.payload.s;
                t1 = std_io_is_dir(l11);
                if (!(t1)) {
                    t2 = (l8 + INT64_C(1));
                    l8 = (size_t) (int64_t) t2;
                    goto loop_22;
                }
                l13 = vader_resolver_scan_folder(l11, l3);
                if (l13.tag == 0u) {
                    t2 = (l8 + INT64_C(1));
                    l8 = (size_t) (int64_t) t2;
                    goto loop_22;
                }
                l12 = l13.payload.obj;
                t3 = ((vader_struct_vader_resolver_FolderBucket_t*) l12)->f_name;
                if (t3 != l0) {
                    t2 = (l8 + INT64_C(1));
                    l8 = (size_t) (int64_t) t2;
                    goto loop_22;
                }
                if (l4.tag == 0u) {
                    l4 = vader_box_string(169u, l11);
                    vader_array_t* _a3_slotarr = ((vader_array_t*) l1);
                    if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                    if ((size_t) l8 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                    t0 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l8);
                    l5 = ((vader_struct_vader_resolver_IncludePath_t*) t0)->f_origin;
                    l14 = ((vader_struct_vader_resolver_FolderBucket_t*) l12)->f_files;
                    vader_array_push_all((vader_array_t*) l6, (vader_array_t*) l14);
                    t2 = (l8 + INT64_C(1));
                    l8 = (size_t) (int64_t) t2;
                    goto loop_22;
                }
                l15 = l4.payload.s;
                if (l11 == l15) {
                    t2 = (l8 + INT64_C(1));
                    l8 = (size_t) (int64_t) t2;
                    goto loop_22;
                }
                l16 = ((vader_struct_vader_resolver_FolderBucket_t*) l12)->f_files;
                vader_array_push_all((vader_array_t*) l6, (vader_array_t*) l16);
                t2 = (l8 + INT64_C(1));
                l8 = (size_t) (int64_t) t2;
                goto loop_22;
            }
        }
    }
    if (l4.tag == 0u) {
        t4 = vader_box_obj(0u, NULL);
        { vader_box_t __vret = t4; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l11 = l4.payload.s;
    vader_struct_vader_resolver_DiscoveredModule_t* _a4_obj = (vader_struct_vader_resolver_DiscoveredModule_t*) vader_gc_alloc(sizeof(vader_struct_vader_resolver_DiscoveredModule_t));
    vader_obj_header_init(_a4_obj, 870u);
    _a4_obj->f_name = l0;
    _a4_obj->f_folder = l11;
    _a4_obj->f_files = l6;
    _a4_obj->f_origin = l5;
    l6 = (void*) _a4_obj;
    std_collections_put__string__Any(l2, l0, vader_ref_box(l6));
    { vader_box_t __vret = vader_ref_box(l6); vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

void* vader_resolver_resolve_module(void* l0, vader_string_t l1, void* l2) {
    void* l3 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[4] = { &l0, &l2, &l3, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l3 = vader_resolver_collect_module_no_index(l0, l1, l2);
    t0 = vader_resolver_resolve_module_with_collected_dp(l0, l1, l1, l2, l3);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_resolver_resolve_module_with_collected_dp(void* l0, vader_string_t l1, vader_string_t l2, void* l3, void* l4) {
    void* l5 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[8] = { &l0, &l3, &l4, &l5, &l6, &l7, &l8, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l1, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 8u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 169u);
    l5 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(16u, 0u, 0u, 180u);
    l6 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 172u);
    l7 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__string__Any_t* _a3_obj = (vader_struct_std_collections_MutableMap__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__Any_t));
    vader_obj_header_init(_a3_obj, 321u);
    _a3_obj->f_ekeys = l5;
    _a3_obj->f_evals = l6;
    _a3_obj->f_index = l7;
    _a3_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l5 = (void*) _a3_obj;
    vader_array_t* _a4_arr = vader_array_new(8u, 0u, 0u, 169u);
    l6 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_new(16u, 0u, 0u, 180u);
    l7 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(9u, 0u, 7u, 172u);
    l8 = (void*) _a6_arr;
    vader_struct_std_collections_MutableMap__string__Any___t* _a7_obj = (vader_struct_std_collections_MutableMap__string__Any___t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__Any___t));
    vader_obj_header_init(_a7_obj, 323u);
    _a7_obj->f_ekeys = l6;
    _a7_obj->f_evals = l7;
    _a7_obj->f_index = l8;
    _a7_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a7_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a7_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l6 = (void*) _a7_obj;
    t0 = vader_resolver_resolve_module_with_collected_dp_seeded(l0, l1, l2, l3, l4, l5, l6);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

void* vader_resolver_resolve_module_with_collected_dp_seeded(void* l0, vader_string_t l1, vader_string_t l2, void* l3, void* l4, void* l5, void* l6) {
    void* l7 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l12 = NULL;
    void* l14 = NULL;
    void* l15 = NULL;
    void* l17 = NULL;
    void* l18 = NULL;
    void* l19 = NULL;
    void* l20 = NULL;
    void* l21 = NULL;
    void* l22 = NULL;
    void* l23 = NULL;
    void* l24 = NULL;
    void* l25 = NULL;
    size_t l10, l11;
    vader_string_t l13 = 0;
    vader_string_t l16 = 0;
    int64_t t0;
    vader_box_t t1 = vader_box_null();
    void* t2 = NULL;
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[21] = { &l0, &l3, &l4, &l5, &l6, &l7, &l8, &l9, &l12, &l14, &l15, &l17, &l18, &l19, &l20, &l21, &l22, &l23, &l24, &l25, &t2 };
    vader_string_t* gc_atom_roots[4] = { &l1, &l2, &l13, &l16 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 21u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l7 = vader_resolver_make_builtin_scope(l3);
    l8 = std_collections_values__string__Symbol(((vader_struct_vader_resolver_CollectedModule_t*) l4)->f_symbols);
    l9 = l8;
    l10 = ((vader_array_t*) l9)->length;
    l11 = (size_t) (int64_t) INT64_C(0);
    {
        loop_12: {
            if ((l11 < l10)) {
                vader_array_t* _a0_slotarr = ((vader_array_t*) l9);
                if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                if ((size_t) l11 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                l12 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l11);
                l13 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l12)->f_name;
                std_collections_put__string__Any(l7, l13, vader_ref_box(l12));
                t0 = (l11 + INT64_C(1));
                l11 = (size_t) (int64_t) t0;
                goto loop_12;
            }
        }
    }
    l9 = l5;
    l12 = ((vader_struct_std_collections_MutableMap__string__Symbol_t*) l9)->f_ekeys;
    l14 = ((vader_struct_std_collections_MutableMap__string__Symbol_t*) l9)->f_evals;
    l10 = ((vader_struct_std_collections_MutableMap__string__Symbol_t*) l9)->f_size;
    l11 = (size_t) (int64_t) INT64_C(0);
    {
        loop_48: {
            if ((l11 >= l10)) {
            } else {
                vader_array_t* _a1_slotarr = ((vader_array_t*) l12);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l11 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                t1 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l11];
                l13 = t1.payload.s;
                vader_array_t* _a2_slotarr = ((vader_array_t*) l14);
                if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                if ((size_t) l11 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                l9 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l11);
                vader_struct___Tuple_2_cb60e7c5b39cd1d9_t* _a3_obj = (vader_struct___Tuple_2_cb60e7c5b39cd1d9_t*) vader_gc_alloc(sizeof(vader_struct___Tuple_2_cb60e7c5b39cd1d9_t));
                vader_obj_header_init(_a3_obj, 223u);
                _a3_obj->f__0 = l13;
                _a3_obj->f__1 = l9;
                l15 = (void*) _a3_obj;
                l16 = ((vader_struct___Tuple_2_cb60e7c5b39cd1d9_t*) l15)->f__0;
                l17 = ((vader_struct___Tuple_2_cb60e7c5b39cd1d9_t*) l15)->f__1;
                t0 = (l11 + INT64_C(1));
                l11 = (size_t) (int64_t) t0;
                t1 = std_collections_get__string__Any(l7, l16);
                if (t1.tag == 0u) {
                    std_collections_put__string__Any(l7, l16, vader_ref_box(l17));
                }
                goto loop_48;
            }
        }
    }
    l7 = vader_resolver_resolve_program(l0, l7, l1, l3, l6);
    l8 = vader_resolver_sort_by_name(l8);
    l9 = ((vader_struct_vader_resolver_ResolvedFile_t*) l7)->f_idents;
    l12 = ((vader_struct_vader_resolver_ResolvedFile_t*) l7)->f_immutable_locals;
    l14 = ((vader_struct_vader_resolver_ResolvedFile_t*) l7)->f_immutable_borrows;
    l15 = ((vader_struct_vader_resolver_CollectedModule_t*) l4)->f_fn_overloads;
    vader_array_t* _a4_arr = vader_array_new(9u, 0u, 7u, 172u);
    l17 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_new(16u, 0u, 0u, 180u);
    l18 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(9u, 0u, 7u, 172u);
    l19 = (void*) _a6_arr;
    vader_struct_std_collections_MutableMap__i32__Any_t* _a7_obj = (vader_struct_std_collections_MutableMap__i32__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__Any_t));
    vader_obj_header_init(_a7_obj, 283u);
    _a7_obj->f_ekeys = l17;
    _a7_obj->f_evals = l18;
    _a7_obj->f_index = l19;
    _a7_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a7_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a7_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l17 = (void*) _a7_obj;
    vader_array_t* _a8_arr = vader_array_new(9u, 0u, 7u, 172u);
    l18 = (void*) _a8_arr;
    vader_array_t* _a9_arr = vader_array_new(16u, 0u, 0u, 180u);
    l19 = (void*) _a9_arr;
    vader_array_t* _a10_arr = vader_array_new(9u, 0u, 7u, 172u);
    l20 = (void*) _a10_arr;
    vader_struct_std_collections_MutableMap__i32__Any_t* _a11_obj = (vader_struct_std_collections_MutableMap__i32__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__Any_t));
    vader_obj_header_init(_a11_obj, 283u);
    _a11_obj->f_ekeys = l18;
    _a11_obj->f_evals = l19;
    _a11_obj->f_index = l20;
    _a11_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a11_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a11_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l18 = (void*) _a11_obj;
    vader_array_t* _a12_arr = vader_array_new(9u, 0u, 7u, 172u);
    l19 = (void*) _a12_arr;
    vader_array_t* _a13_arr = vader_array_new(16u, 0u, 0u, 180u);
    l20 = (void*) _a13_arr;
    vader_array_t* _a14_arr = vader_array_new(9u, 0u, 7u, 172u);
    l21 = (void*) _a14_arr;
    vader_struct_std_collections_MutableMap__i32__Any_t* _a15_obj = (vader_struct_std_collections_MutableMap__i32__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__Any_t));
    vader_obj_header_init(_a15_obj, 283u);
    _a15_obj->f_ekeys = l19;
    _a15_obj->f_evals = l20;
    _a15_obj->f_index = l21;
    _a15_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a15_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a15_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l19 = (void*) _a15_obj;
    l20 = ((vader_struct_vader_resolver_ResolvedFile_t*) l7)->f_type_param_bounds;
    l7 = ((vader_struct_vader_resolver_ResolvedFile_t*) l7)->f_diags;
    vader_array_t* _a16_arr = vader_array_new(9u, 0u, 7u, 172u);
    l21 = (void*) _a16_arr;
    vader_array_t* _a17_arr = vader_array_new(8u, 0u, 0u, 169u);
    l22 = (void*) _a17_arr;
    vader_array_t* _a18_arr = vader_array_new(9u, 0u, 7u, 172u);
    l23 = (void*) _a18_arr;
    vader_struct_std_collections_MutableMap__i32__string_t* _a19_obj = (vader_struct_std_collections_MutableMap__i32__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__string_t));
    vader_obj_header_init(_a19_obj, 315u);
    _a19_obj->f_ekeys = l21;
    _a19_obj->f_evals = l22;
    _a19_obj->f_index = l23;
    _a19_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a19_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a19_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l21 = (void*) _a19_obj;
    vader_array_t* _a20_arr = vader_array_new(9u, 0u, 7u, 172u);
    l22 = (void*) _a20_arr;
    vader_array_t* _a21_arr = vader_array_new(16u, 0u, 0u, 180u);
    l23 = (void*) _a21_arr;
    vader_array_t* _a22_arr = vader_array_new(9u, 0u, 7u, 172u);
    l24 = (void*) _a22_arr;
    vader_struct_std_collections_MutableMap__i32__MutableMap_Any__Any__t* _a23_obj = (vader_struct_std_collections_MutableMap__i32__MutableMap_Any__Any__t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__MutableMap_Any__Any__t));
    vader_obj_header_init(_a23_obj, 298u);
    _a23_obj->f_ekeys = l22;
    _a23_obj->f_evals = l23;
    _a23_obj->f_index = l24;
    _a23_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a23_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a23_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l22 = (void*) _a23_obj;
    vader_array_t* _a24_arr = vader_array_new(9u, 0u, 7u, 172u);
    l23 = (void*) _a24_arr;
    vader_array_t* _a25_arr = vader_array_new(16u, 0u, 0u, 180u);
    l24 = (void*) _a25_arr;
    vader_array_t* _a26_arr = vader_array_new(9u, 0u, 7u, 172u);
    l25 = (void*) _a26_arr;
    vader_struct_std_collections_MutableMap__i32__MutableMap_Any__Any__t* _a27_obj = (vader_struct_std_collections_MutableMap__i32__MutableMap_Any__Any__t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__MutableMap_Any__Any__t));
    vader_obj_header_init(_a27_obj, 298u);
    _a27_obj->f_ekeys = l23;
    _a27_obj->f_evals = l24;
    _a27_obj->f_index = l25;
    _a27_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a27_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a27_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l23 = (void*) _a27_obj;
    vader_struct_vader_resolver_ResolvedModule_t* _a28_obj = (vader_struct_vader_resolver_ResolvedModule_t*) vader_gc_alloc(sizeof(vader_struct_vader_resolver_ResolvedModule_t));
    vader_obj_header_init(_a28_obj, 882u);
    _a28_obj->f_path = l1;
    _a28_obj->f_display_path = l2;
    _a28_obj->f_symbols = l8;
    _a28_obj->f_idents = l9;
    _a28_obj->f_immutable_locals = l12;
    _a28_obj->f_immutable_borrows = l14;
    _a28_obj->f_fn_overloads = l15;
    _a28_obj->f_imports_to = l17;
    _a28_obj->f_alias_types = l18;
    _a28_obj->f_alias_decls = l19;
    _a28_obj->f_type_param_bounds = l20;
    _a28_obj->f_diags = l7;
    _a28_obj->f_deprecated_messages = l21;
    _a28_obj->f_namespace_member_types = l22;
    _a28_obj->f_namespace_private_members = l23;
    t2 = (void*) _a28_obj;
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_resolver_resolve_program(void* l0, void* l1, vader_string_t l2, void* l3, void* l4) {
    void* l5 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    size_t l11, l12;
    vader_box_t l13 = vader_box_null();
    int64_t t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &l13 };
    void** gc_raw_roots[11] = { &l0, &l1, &l3, &l4, &l5, &l6, &l7, &l8, &l9, &l10, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 11u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(14u, 0u, 4u, 178u);
    l5 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(16u, 0u, 0u, 180u);
    l6 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 172u);
    l7 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__u64__Any_t* _a3_obj = (vader_struct_std_collections_MutableMap__u64__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__u64__Any_t));
    vader_obj_header_init(_a3_obj, 366u);
    _a3_obj->f_ekeys = l5;
    _a3_obj->f_evals = l6;
    _a3_obj->f_index = l7;
    _a3_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l5 = (void*) _a3_obj;
    vader_array_t* _a4_arr = vader_array_new(9u, 0u, 7u, 172u);
    l6 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_new(6u, 0u, 12u, 167u);
    l7 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(9u, 0u, 7u, 172u);
    l8 = (void*) _a6_arr;
    vader_struct_std_collections_MutableMap__i32__bool_t* _a7_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
    vader_obj_header_init(_a7_obj, 311u);
    _a7_obj->f_ekeys = l6;
    _a7_obj->f_evals = l7;
    _a7_obj->f_index = l8;
    _a7_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a7_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a7_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l6 = (void*) _a7_obj;
    vader_array_t* _a8_arr = vader_array_new(9u, 0u, 7u, 172u);
    l7 = (void*) _a8_arr;
    vader_array_t* _a9_arr = vader_array_new(6u, 0u, 12u, 167u);
    l8 = (void*) _a9_arr;
    vader_array_t* _a10_arr = vader_array_new(9u, 0u, 7u, 172u);
    l9 = (void*) _a10_arr;
    vader_struct_std_collections_MutableMap__i32__bool_t* _a11_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
    vader_obj_header_init(_a11_obj, 311u);
    _a11_obj->f_ekeys = l7;
    _a11_obj->f_evals = l8;
    _a11_obj->f_index = l9;
    _a11_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a11_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a11_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l7 = (void*) _a11_obj;
    vader_array_t* _a12_arr = vader_array_new(9u, 0u, 7u, 172u);
    l8 = (void*) _a12_arr;
    vader_array_t* _a13_arr = vader_array_new(16u, 0u, 0u, 180u);
    l9 = (void*) _a13_arr;
    vader_array_t* _a14_arr = vader_array_new(9u, 0u, 7u, 172u);
    l10 = (void*) _a14_arr;
    vader_struct_std_collections_MutableMap__i32__Any_t* _a15_obj = (vader_struct_std_collections_MutableMap__i32__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__Any_t));
    vader_obj_header_init(_a15_obj, 283u);
    _a15_obj->f_ekeys = l8;
    _a15_obj->f_evals = l9;
    _a15_obj->f_index = l10;
    _a15_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a15_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a15_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l8 = (void*) _a15_obj;
    vader_array_t* _a16_arr = vader_array_new(51u, 0u, 13u, 700u);
    l9 = (void*) _a16_arr;
    l10 = vader_resolver_new_scope(l1);
    vader_struct_vader_resolver_ResolveState_t* _a17_obj = (vader_struct_vader_resolver_ResolveState_t*) vader_gc_alloc(sizeof(vader_struct_vader_resolver_ResolveState_t));
    vader_obj_header_init(_a17_obj, 880u);
    _a17_obj->f_idents = l5;
    _a17_obj->f_immutable_locals = l6;
    _a17_obj->f_immutable_borrows = l7;
    _a17_obj->f_params_immutable_default = true;
    _a17_obj->f_type_param_bounds = l8;
    _a17_obj->f_diags = l9;
    _a17_obj->f_scope = l10;
    _a17_obj->f_module_path = l2;
    _a17_obj->f_factory = l3;
    _a17_obj->f_ambiguous = l4;
    l5 = (void*) _a17_obj;
    l6 = ((vader_struct_toolchain_ast_Program_t*) l0)->f_decls;
    l11 = ((vader_array_t*) l6)->length;
    l12 = (size_t) (int64_t) INT64_C(0);
    {
        loop_80: {
            if ((l12 < l11)) {
                vader_array_t* _a18_slotarr = ((vader_array_t*) l6);
                if (_a18_slotarr->buf != NULL && _a18_slotarr->buf->header.forward != NULL) { _a18_slotarr->buf = vader_array_buf_forward(_a18_slotarr->buf); }
                if ((size_t) l12 >= _a18_slotarr->length) { vader_trap("array index out of bounds"); }
                l13 = vader_array_ref_load_box(_a18_slotarr->buf, _a18_slotarr->offset + (size_t) l12);
                vader_resolver_walk_decl(l5, l13);
                t0 = (l12 + INT64_C(1));
                l12 = (size_t) (int64_t) t0;
                goto loop_80;
            }
        }
    }
    l6 = ((vader_struct_vader_resolver_ResolveState_t*) l5)->f_idents;
    l7 = ((vader_struct_vader_resolver_ResolveState_t*) l5)->f_immutable_locals;
    l8 = ((vader_struct_vader_resolver_ResolveState_t*) l5)->f_immutable_borrows;
    l9 = ((vader_struct_vader_resolver_ResolveState_t*) l5)->f_type_param_bounds;
    l5 = ((vader_struct_vader_resolver_ResolveState_t*) l5)->f_diags;
    vader_struct_vader_resolver_ResolvedFile_t* _a19_obj = (vader_struct_vader_resolver_ResolvedFile_t*) vader_gc_alloc(sizeof(vader_struct_vader_resolver_ResolvedFile_t));
    vader_obj_header_init(_a19_obj, 881u);
    _a19_obj->f_top_level = l1;
    _a19_obj->f_idents = l6;
    _a19_obj->f_immutable_locals = l7;
    _a19_obj->f_immutable_borrows = l8;
    _a19_obj->f_type_param_bounds = l9;
    _a19_obj->f_diags = l5;
    t1 = (void*) _a19_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_box_t vader_resolver_rooted_candidate(void* l0, vader_string_t l1) {
    vader_string_t l2 = 0;
    vader_string_t l3 = 0;
    vader_string_t t0 = 0;
    vader_string_t t1 = 0;
    vader_box_t t2 = vader_box_null();
    bool t3;
    vader_box_t* gc_roots[1] = { &t2 };
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[5] = { &l1, &l2, &l3, &t0, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 5u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_resolver_IncludePath_t*) l0)->f_prefix;
    if (t0 == 0u) {
        t0 = ((vader_struct_vader_resolver_IncludePath_t*) l0)->f_dir;
        t1 = vader_resolver_join_path(t0, l1);
        t2 = vader_box_string(169u, t1);
        { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = ((vader_struct_vader_resolver_IncludePath_t*) l0)->f_prefix;
    if (l1 == l2) {
        t0 = ((vader_struct_vader_resolver_IncludePath_t*) l0)->f_dir;
        t2 = vader_box_string(169u, t0);
        { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_vader_resolver_IncludePath_t*) l0)->f_prefix;
    l2 = concat_2(t0, 436u);
    t3 = std_string_starts_with(l1, l2);
    if (t3) {
        l2 = ((vader_struct_vader_resolver_IncludePath_t*) l0)->f_dir;
        t0 = ((vader_struct_vader_resolver_IncludePath_t*) l0)->f_prefix;
        l3 = concat_2(t0, 436u);
        l3 = std_string_trim_prefix(l1, l3);
        t0 = vader_resolver_join_path(l2, l3);
        t2 = vader_box_string(169u, t0);
        { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = vader_box_obj(0u, NULL);
    { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

void vader_resolver_run_orphan_rule_check_for_module(void* l0, vader_string_t l1, void* l2, void* l3, void* l4) {
    void* l5 = NULL;
    void* l8 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    size_t l6, l7, l9, l10;
    vader_box_t l11 = vader_box_null();
    void* t0 = NULL;
    int64_t t1;
    vader_box_t* gc_roots[1] = { &l11 };
    void** gc_raw_roots[9] = { &l0, &l2, &l3, &l4, &l5, &l8, &l12, &l13, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 9u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l5 = ((vader_struct_vader_resolver_Module_t*) ((vader_struct_vader_resolver_LoadedModule_t*) l0)->f_module)->f_files;
    l6 = ((vader_array_t*) l5)->length;
    l7 = (size_t) (int64_t) INT64_C(0);
    {
        loop_8: {
            if ((l7 < l6)) {
                vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
                if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                if ((size_t) l7 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l7);
                l8 = ((vader_struct_toolchain_ast_Program_t*) ((vader_struct_vader_resolver_SourceFile_t*) t0)->f_program)->f_decls;
                l9 = ((vader_array_t*) l8)->length;
                l10 = (size_t) (int64_t) INT64_C(0);
                {
                    loop_24: {
                        if ((l10 < l9)) {
                            vader_array_t* _a1_slotarr = ((vader_array_t*) l8);
                            if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                            if ((size_t) l10 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                            l11 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l10);
                            if (l11.tag == 430u) {
                                l12 = l11.payload.obj;
                                l13 = ((vader_struct_vader_resolver_CollectedModule_t*) ((vader_struct_vader_resolver_LoadedModule_t*) l0)->f_collected)->f_symbols;
                                vader_resolver_check_orphan_rule(l12, l1, l13, l2, l3, l4);
                            }
                            t1 = (l10 + INT64_C(1));
                            l10 = (size_t) (int64_t) t1;
                            goto loop_24;
                        }
                    }
                }
                t1 = (l7 + INT64_C(1));
                l7 = (size_t) (int64_t) t1;
                goto loop_8;
            }
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static vader_box_t vader_resolver_scan_folder(vader_string_t l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l11 = vader_box_null();
    void* l3 = NULL;
    void* l4 = NULL;
    void* l10 = NULL;
    void* l13 = NULL;
    void* l15 = NULL;
    void* l18 = NULL;
    void* l22 = NULL;
    size_t l5, l6;
    vader_string_t l7 = 0;
    vader_string_t l8 = 0;
    vader_string_t l12 = 0;
    vader_string_t l14 = 0;
    vader_string_t l16 = 0;
    vader_string_t l17 = 0;
    vader_string_t l19 = 0;
    vader_string_t l20 = 0;
    vader_string_t l21 = 0;
    bool l9;
    size_t t0;
    vader_box_t t1 = vader_box_null();
    void* t2 = NULL;
    bool t3;
    int64_t t4;
    vader_string_t t5 = 0;
    vader_box_t* gc_roots[3] = { &l2, &l11, &t1 };
    void** gc_raw_roots[9] = { &l1, &l3, &l4, &l10, &l13, &l15, &l18, &l22, &t2 };
    vader_string_t* gc_atom_roots[11] = { &l0, &l7, &l8, &l12, &l14, &l16, &l17, &l19, &l20, &l21, &t5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 9u, gc_roots, gc_raw_roots, 0u, NULL, 11u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = std_io_read_dir(l0);
    if (l2.tag == 8u) {
        l3 = l2.payload.obj;
    } else {
        if (l2.tag == 388u) {
            vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 169u);
            l3 = (void*) _a0_arr;
        } else {
            vader_unreachable("unreachable return in vader_resolver$scan_folder");
        }
    }
    t0 = ((vader_array_t*) l3)->length;
    if (t0 == INT64_C(0)) {
        t1 = vader_box_obj(0u, NULL);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct___lambda_env_vader_resolver_3_t* _a1_obj = (vader_struct___lambda_env_vader_resolver_3_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_resolver_3_t));
    vader_obj_header_init(_a1_obj, 267u);
    t2 = (void*) _a1_obj;
    vader_fn_t* _a2_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
    vader_obj_header_init(_a2_closure, 141u);
    _a2_closure->code = (void*) &vader_fn_lift___lambda_vader_resolver_2;
    _a2_closure->env = t2;
    l4 = (void*) _a2_closure;
    l4 = std_sort_sort__string(l3, l4);
    vader_array_t* _a3_arr = vader_array_new(8u, 0u, 0u, 169u);
    l3 = (void*) _a3_arr;
    l5 = ((vader_array_t*) l4)->length;
    l6 = (size_t) (int64_t) INT64_C(0);
    {
        loop_42: {
            if ((l6 < l5)) {
                vader_array_t* _a4_slotarr = ((vader_array_t*) l4);
                if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                if ((size_t) l6 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                t1 = vader_array_box_slots(_a4_slotarr->buf)[_a4_slotarr->offset + (size_t) l6];
                l7 = t1.payload.s;
                l8 = vader_resolver_join_path(l0, l7);
                t3 = std_string_ends_with(l7, 435u);
                if (t3) {
                    t3 = std_io_is_dir(l8);
                    l9 = !(t3);
                } else {
                    l9 = false;
                }
                if (l9) {
                    vader_array_push((vader_array_t*) l3, vader_box_string(169u, l8));
                }
                t4 = (l6 + INT64_C(1));
                l6 = (size_t) (int64_t) t4;
                goto loop_42;
            }
        }
    }
    t0 = ((vader_array_t*) l3)->length;
    if (t0 == INT64_C(0)) {
        t1 = vader_box_obj(0u, NULL);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = toolchain_span_empty_span();
    vader_array_t* _a5_arr = vader_array_new(8u, 0u, 0u, 169u);
    l10 = (void*) _a5_arr;
    vader_struct_vader_resolver_FolderBucket_t* _a6_obj = (vader_struct_vader_resolver_FolderBucket_t*) vader_gc_alloc(sizeof(vader_struct_vader_resolver_FolderBucket_t));
    vader_obj_header_init(_a6_obj, 872u);
    _a6_obj->f_name = 0u;
    _a6_obj->f_first_decl_span = l4;
    _a6_obj->f_files = l10;
    l4 = (void*) _a6_obj;
    l5 = ((vader_array_t*) l3)->length;
    l6 = (size_t) (int64_t) INT64_C(0);
    {
        loop_106: {
            if ((l6 < l5)) {
                vader_array_t* _a7_slotarr = ((vader_array_t*) l3);
                if (_a7_slotarr->buf != NULL && _a7_slotarr->buf->header.forward != NULL) { _a7_slotarr->buf = vader_array_buf_forward(_a7_slotarr->buf); }
                if ((size_t) l6 >= _a7_slotarr->length) { vader_trap("array index out of bounds"); }
                t1 = vader_array_box_slots(_a7_slotarr->buf)[_a7_slotarr->offset + (size_t) l6];
                l7 = t1.payload.s;
                l2 = std_io_read_file_string(l7, (size_t) (int64_t) INT64_C(16777216));
                if (l2.tag == 169u) {
                    l8 = l2.payload.s;
                } else {
                    if (l2.tag == 388u) {
                        l8 = 0u;
                    } else {
                        vader_unreachable("unreachable return in vader_resolver$scan_folder");
                    }
                }
                if (l8 == 0u) {
                    t4 = (l6 + INT64_C(1));
                    l6 = (size_t) (int64_t) t4;
                    goto loop_106;
                }
                vader_array_push((vader_array_t*) ((vader_struct_vader_resolver_FolderBucket_t*) l4)->f_files, vader_box_string(169u, l7));
                l11 = vader_parser_parse_module_header(l8, l7);
                if (l11.tag == 0u) {
                    l10 = toolchain_span_empty_span();
                    l12 = concat_3(930u, l7, 930u);
                    l13 = vader_diagnostics_resolver_error((uint8_t) (int32_t) INT32_C(19), l10, l12);
                    vader_array_push((vader_array_t*) l1, vader_ref_box(l13));
                } else {
                    if (l11.tag == 864u) {
                        t5 = ((vader_struct_vader_resolver_FolderBucket_t*) l4)->f_name;
                        if (t5 == 0u) {
                            t2 = l11.payload.obj;
                            l14 = ((vader_struct_vader_parser_ModuleHeader_t*) t2)->f_name;
                            ((vader_struct_vader_resolver_FolderBucket_t*) l4)->f_name = l14;
                            VADER_WRITE_BARRIER((vader_struct_vader_resolver_FolderBucket_t*) l4);
                            t2 = l11.payload.obj;
                            l15 = ((vader_struct_vader_parser_ModuleHeader_t*) t2)->f_name_span;
                            ((vader_struct_vader_resolver_FolderBucket_t*) l4)->f_first_decl_span = l15;
                            VADER_WRITE_BARRIER((vader_struct_vader_resolver_FolderBucket_t*) l4);
                        } else {
                            t2 = l11.payload.obj;
                            l16 = ((vader_struct_vader_parser_ModuleHeader_t*) t2)->f_name;
                            l17 = ((vader_struct_vader_resolver_FolderBucket_t*) l4)->f_name;
                            if (l16 != l17) {
                                t2 = l11.payload.obj;
                                l18 = ((vader_struct_vader_parser_ModuleHeader_t*) t2)->f_name_span;
                                t2 = l11.payload.obj;
                                l19 = ((vader_struct_vader_parser_ModuleHeader_t*) t2)->f_name;
                                l20 = ((vader_struct_vader_resolver_FolderBucket_t*) l4)->f_name;
                                l21 = concat_5(930u, l19, 951u, l20, 1027u);
                                l22 = vader_diagnostics_resolver_error((uint8_t) (int32_t) INT32_C(21), l18, l21);
                                vader_array_push((vader_array_t*) l1, vader_ref_box(l22));
                            }
                        }
                    } else {
                        vader_unreachable("unreachable return in vader_resolver$scan_folder");
                    }
                }
                t4 = (l6 + INT64_C(1));
                l6 = (size_t) (int64_t) t4;
                goto loop_106;
            }
        }
    }
    { vader_box_t __vret = vader_ref_box(l4); vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_box_t vader_resolver_seed_entry(vader_string_t l0, void* l1) {
    void* l2 = NULL;
    vader_box_t l3 = vader_box_null();
    vader_string_t l4 = 0;
    vader_box_t t0 = vader_box_null();
    vader_string_t t1 = 0;
    void* t2 = NULL;
    vader_box_t* gc_roots[2] = { &l3, &t0 };
    void** gc_raw_roots[3] = { &l1, &l2, &t2 };
    vader_string_t* gc_atom_roots[3] = { &l0, &l4, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l3 = vader_resolver_scan_folder(l0, l1);
    if (l3.tag == 0u) {
        t0 = vader_box_obj(0u, NULL);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = l3.payload.obj;
    t1 = ((vader_struct_vader_resolver_FolderBucket_t*) l2)->f_name;
    if (t1 == 0u) {
        t0 = vader_box_obj(0u, NULL);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = ((vader_struct_vader_resolver_FolderBucket_t*) l2)->f_name;
    l2 = ((vader_struct_vader_resolver_FolderBucket_t*) l2)->f_files;
    vader_struct_vader_resolver_DiscoveredModule_t* _a0_obj = (vader_struct_vader_resolver_DiscoveredModule_t*) vader_gc_alloc(sizeof(vader_struct_vader_resolver_DiscoveredModule_t));
    vader_obj_header_init(_a0_obj, 870u);
    _a0_obj->f_name = l4;
    _a0_obj->f_folder = l0;
    _a0_obj->f_files = l2;
    _a0_obj->f_origin = (uint8_t) (int32_t) INT32_C(0);
    t2 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_resolver_select_target_bodies(void* l0, vader_box_t l1, void* l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l15 = NULL;
    void* l26 = NULL;
    void* l27 = NULL;
    void* l29 = NULL;
    void* l31 = NULL;
    void* l32 = NULL;
    void* l33 = NULL;
    size_t l8, l9, l10, l11, l16, l17;
    vader_box_t l12 = vader_box_null(), l13 = vader_box_null(), l20 = vader_box_null(), l30 = vader_box_null();
    vader_string_t l14 = 0;
    vader_string_t l19 = 0;
    vader_string_t l21 = 0;
    vader_string_t l22 = 0;
    vader_string_t l23 = 0;
    vader_string_t l24 = 0;
    vader_string_t l25 = 0;
    vader_string_t l28 = 0;
    uint8_t l18;
    void* t0 = NULL;
    int64_t t1;
    bool t2;
    vader_box_t t3 = vader_box_null();
    vader_box_t* gc_roots[6] = { &l1, &l12, &l13, &l20, &l30, &t3 };
    void** gc_raw_roots[15] = { &l0, &l2, &l3, &l4, &l5, &l6, &l7, &l15, &l26, &l27, &l29, &l31, &l32, &l33, &t0 };
    vader_string_t* gc_atom_roots[8] = { &l14, &l19, &l21, &l22, &l23, &l24, &l25, &l28 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 6u, 15u, gc_roots, gc_raw_roots, 0u, NULL, 8u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_resolver_check_selectors(l0, l2);
    vader_resolver_check_groups(l0, l2);
    if (l1.tag == 0u) {
        { void* __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 169u);
    l3 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(16u, 0u, 0u, 180u);
    l4 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 172u);
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
    vader_array_t* _a4_arr = vader_array_new(8u, 0u, 0u, 169u);
    l4 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_new(6u, 0u, 12u, 167u);
    l5 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(9u, 0u, 7u, 172u);
    l6 = (void*) _a6_arr;
    vader_struct_std_collections_MutableMap__string__bool_t* _a7_obj = (vader_struct_std_collections_MutableMap__string__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__bool_t));
    vader_obj_header_init(_a7_obj, 359u);
    _a7_obj->f_ekeys = l4;
    _a7_obj->f_evals = l5;
    _a7_obj->f_index = l6;
    _a7_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a7_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a7_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l4 = (void*) _a7_obj;
    vader_array_t* _a8_arr = vader_array_new(8u, 0u, 0u, 169u);
    l5 = (void*) _a8_arr;
    vader_array_t* _a9_arr = vader_array_new(8u, 0u, 0u, 169u);
    l6 = (void*) _a9_arr;
    vader_array_t* _a10_arr = vader_array_new(9u, 0u, 7u, 172u);
    l7 = (void*) _a10_arr;
    vader_struct_std_collections_MutableMap__string__string_t* _a11_obj = (vader_struct_std_collections_MutableMap__string__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__string_t));
    vader_obj_header_init(_a11_obj, 363u);
    _a11_obj->f_ekeys = l5;
    _a11_obj->f_evals = l6;
    _a11_obj->f_index = l7;
    _a11_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a11_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a11_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l5 = (void*) _a11_obj;
    l6 = l0;
    l8 = ((vader_array_t*) l6)->length;
    l9 = (size_t) (int64_t) INT64_C(0);
    {
        loop_61: {
            if ((l9 < l8)) {
                vader_array_t* _a12_slotarr = ((vader_array_t*) l6);
                if (_a12_slotarr->buf != NULL && _a12_slotarr->buf->header.forward != NULL) { _a12_slotarr->buf = vader_array_buf_forward(_a12_slotarr->buf); }
                if ((size_t) l9 >= _a12_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_ref_load_obj(_a12_slotarr->buf, _a12_slotarr->offset + (size_t) l9);
                l7 = ((vader_struct_toolchain_ast_Program_t*) ((vader_struct_vader_resolver_SourceFile_t*) t0)->f_program)->f_decls;
                l10 = ((vader_array_t*) l7)->length;
                l11 = (size_t) (int64_t) INT64_C(0);
                {
                    loop_77: {
                        if ((l11 < l10)) {
                            vader_array_t* _a13_slotarr = ((vader_array_t*) l7);
                            if (_a13_slotarr->buf != NULL && _a13_slotarr->buf->header.forward != NULL) { _a13_slotarr->buf = vader_array_buf_forward(_a13_slotarr->buf); }
                            if ((size_t) l11 >= _a13_slotarr->length) { vader_trap("array index out of bounds"); }
                            l12 = vader_array_ref_load_box(_a13_slotarr->buf, _a13_slotarr->offset + (size_t) l11);
                            if (l12.tag == 421u) {
                                t0 = l12.payload.obj;
                                l13 = vader_resolver_target_selectors(((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_decorators);
                                if (l13.tag == 0u) {
                                    t1 = (l11 + INT64_C(1));
                                    l11 = (size_t) (int64_t) t1;
                                    goto loop_77;
                                }
                                t0 = l13.payload.obj;
                                t2 = ((vader_struct_vader_resolver_TargetSelectors_t*) t0)->f_is_bare;
                                if (t2) {
                                    t0 = l12.payload.obj;
                                    l14 = ((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_name;
                                    std_collections_put__string__bool(l4, l14, true);
                                } else {
                                    t0 = l13.payload.obj;
                                    l15 = ((vader_struct_vader_resolver_TargetSelectors_t*) t0)->f_os;
                                    l16 = ((vader_array_t*) l15)->length;
                                    l17 = (size_t) (int64_t) INT64_C(0);
                                    {
                                        loop_125: {
                                            if ((l17 < l16)) {
                                                vader_array_t* _a14_slotarr = ((vader_array_t*) l15);
                                                if (_a14_slotarr->buf != NULL && _a14_slotarr->buf->header.forward != NULL) { _a14_slotarr->buf = vader_array_buf_forward(_a14_slotarr->buf); }
                                                if ((size_t) l17 >= _a14_slotarr->length) { vader_trap("array index out of bounds"); }
                                                t3 = vader_array_read_u8(_a14_slotarr, _a14_slotarr->offset + (size_t) l17, 175u);
                                                l18 = ((uint8_t) t3.payload.i);
                                                t0 = l12.payload.obj;
                                                l19 = ((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_name;
                                                l20 = std_collections_get__string__string(l5, l19);
                                                t0 = l12.payload.obj;
                                                l21 = ((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_name;
                                                if (l20.tag == 0u) {
                                                    if (l18 == INT32_C(0)) {
                                                        l23 = 2407u;
                                                    } else {
                                                        if (l18 == INT32_C(1)) {
                                                            l23 = 1811u;
                                                        } else {
                                                            if (l18 == INT32_C(2)) {
                                                                l23 = 1430u;
                                                            } else {
                                                                if (l18 == INT32_C(3)) {
                                                                    l23 = 2400u;
                                                                } else {
                                                                    if (l18 == INT32_C(4)) {
                                                                        l23 = 1286u;
                                                                    } else {
                                                                        vader_unreachable("unreachable return in vader_resolver$select_target_bodies");
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                    l22 = concat_2(413u, l23);
                                                } else {
                                                    l24 = l20.payload.s;
                                                    if (l18 == INT32_C(0)) {
                                                        l25 = 2407u;
                                                    } else {
                                                        if (l18 == INT32_C(1)) {
                                                            l25 = 1811u;
                                                        } else {
                                                            if (l18 == INT32_C(2)) {
                                                                l25 = 1430u;
                                                            } else {
                                                                if (l18 == INT32_C(3)) {
                                                                    l25 = 2400u;
                                                                } else {
                                                                    if (l18 == INT32_C(4)) {
                                                                        l25 = 1286u;
                                                                    } else {
                                                                        vader_unreachable("unreachable return in vader_resolver$select_target_bodies");
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                    l22 = concat_3(l24, 377u, l25);
                                                }
                                                std_collections_put__string__string(l5, l21, l22);
                                                t1 = (l17 + INT64_C(1));
                                                l17 = (size_t) (int64_t) t1;
                                                goto loop_125;
                                            }
                                        }
                                    }
                                    t0 = l13.payload.obj;
                                    l26 = ((vader_struct_vader_resolver_TargetSelectors_t*) t0)->f_os;
                                    l27 = l1.payload.obj;
                                    t2 = vader_resolver_matches_target(l26, l27);
                                    if (t2) {
                                        t0 = l12.payload.obj;
                                        l28 = ((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_name;
                                        l29 = l12.payload.obj;
                                        std_collections_put__string__Any(l3, l28, vader_ref_box(l29));
                                    }
                                }
                            }
                            t1 = (l11 + INT64_C(1));
                            l11 = (size_t) (int64_t) t1;
                            goto loop_77;
                        }
                    }
                }
                t1 = (l9 + INT64_C(1));
                l9 = (size_t) (int64_t) t1;
                goto loop_61;
            }
        }
    }
    l6 = l1.payload.obj;
    vader_resolver_report_uncovered(l0, l6, l3, l5, l2);
    vader_array_t* _a15_arr = vader_array_new(87u, 0u, 13u, 884u);
    l5 = (void*) _a15_arr;
    l6 = l0;
    l8 = ((vader_array_t*) l6)->length;
    l9 = (size_t) (int64_t) INT64_C(0);
    {
        loop_319: {
            if ((l9 < l8)) {
                vader_array_t* _a16_slotarr = ((vader_array_t*) l6);
                if (_a16_slotarr->buf != NULL && _a16_slotarr->buf->header.forward != NULL) { _a16_slotarr->buf = vader_array_buf_forward(_a16_slotarr->buf); }
                if ((size_t) l9 >= _a16_slotarr->length) { vader_trap("array index out of bounds"); }
                l7 = vader_array_ref_load_obj(_a16_slotarr->buf, _a16_slotarr->offset + (size_t) l9);
                vader_array_t* _a17_arr = vader_array_new(114u, 0u, 13u, 1047u);
                l15 = (void*) _a17_arr;
                l26 = ((vader_struct_toolchain_ast_Program_t*) ((vader_struct_vader_resolver_SourceFile_t*) l7)->f_program)->f_decls;
                l10 = ((vader_array_t*) l26)->length;
                l11 = (size_t) (int64_t) INT64_C(0);
                {
                    loop_338: {
                        if ((l11 < l10)) {
                            vader_array_t* _a18_slotarr = ((vader_array_t*) l26);
                            if (_a18_slotarr->buf != NULL && _a18_slotarr->buf->header.forward != NULL) { _a18_slotarr->buf = vader_array_buf_forward(_a18_slotarr->buf); }
                            if ((size_t) l11 >= _a18_slotarr->length) { vader_trap("array index out of bounds"); }
                            l12 = vader_array_ref_load_box(_a18_slotarr->buf, _a18_slotarr->offset + (size_t) l11);
                            l27 = l1.payload.obj;
                            l13 = vader_resolver_resolve_decl(l12, l27, l3, l4);
                            if (!(l13.tag == 0u)) {
                                l20 = l13;
                                vader_array_push((vader_array_t*) l15, l20);
                            }
                            t1 = (l11 + INT64_C(1));
                            l11 = (size_t) (int64_t) t1;
                            goto loop_338;
                        }
                    }
                }
                l14 = ((vader_struct_vader_resolver_SourceFile_t*) l7)->f_path;
                l19 = ((vader_struct_vader_resolver_SourceFile_t*) l7)->f_content;
                l21 = ((vader_struct_toolchain_ast_Program_t*) ((vader_struct_vader_resolver_SourceFile_t*) l7)->f_program)->f_file;
                l29 = ((vader_struct_toolchain_ast_Program_t*) ((vader_struct_vader_resolver_SourceFile_t*) l7)->f_program)->f_span;
                l16 = ((vader_struct_toolchain_ast_Program_t*) ((vader_struct_vader_resolver_SourceFile_t*) l7)->f_program)->f_id;
                l30 = ((vader_struct_toolchain_ast_Program_t*) ((vader_struct_vader_resolver_SourceFile_t*) l7)->f_program)->f_module;
                vader_struct_toolchain_ast_Program_t* _a19_obj = (vader_struct_toolchain_ast_Program_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_Program_t));
                vader_obj_header_init(_a19_obj, 453u);
                _a19_obj->f_file = l21;
                _a19_obj->f_span = l29;
                _a19_obj->f_id = l16;
                _a19_obj->f_module = l30;
                _a19_obj->f_decls = l15;
                l31 = (void*) _a19_obj;
                l32 = ((vader_struct_vader_resolver_SourceFile_t*) l7)->f_id_factory;
                vader_struct_vader_resolver_SourceFile_t* _a20_obj = (vader_struct_vader_resolver_SourceFile_t*) vader_gc_alloc(sizeof(vader_struct_vader_resolver_SourceFile_t));
                vader_obj_header_init(_a20_obj, 884u);
                _a20_obj->f_path = l14;
                _a20_obj->f_content = l19;
                _a20_obj->f_program = l31;
                _a20_obj->f_id_factory = l32;
                l33 = (void*) _a20_obj;
                vader_array_push((vader_array_t*) l5, vader_ref_box(l33));
                t1 = (l9 + INT64_C(1));
                l9 = (size_t) (int64_t) t1;
                goto loop_319;
            }
        }
    }
    { void* __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_box_t vader_resolver_sidecar_root(vader_string_t l0, vader_string_t l1) {
    vader_box_t l2 = vader_box_null();
    vader_string_t l3 = 0;
    vader_string_t t0 = 0;
    vader_string_t t2 = 0;
    vader_box_t t1 = vader_box_null();
    bool t3;
    vader_box_t* gc_roots[2] = { &l2, &t1 };
    vader_string_t* gc_atom_roots[5] = { &l0, &l1, &l3, &t0, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 0u, gc_roots, NULL, 0u, NULL, 5u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = vader_resolver_home_root(l0, l1);
    if (!(l2.tag == 0u)) {
        t0 = l2.payload.s;
        t1 = vader_box_string(169u, t0);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = std_io_current_executable_location();
    t2 = vader_resolver_dir_of(t0);
    l3 = vader_resolver_join_path(t2, l0);
    t0 = vader_resolver_join_path(l3, l1);
    t3 = std_io_exists(t0);
    if (t3) {
        t1 = vader_box_string(169u, l3);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_box_obj(0u, NULL);
    { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_resolver_sort_by_name(void* l0) {
    void* l1 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[3] = { &l0, &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct___lambda_env_vader_resolver_1_t* _a0_obj = (vader_struct___lambda_env_vader_resolver_1_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_resolver_1_t));
    vader_obj_header_init(_a0_obj, 266u);
    t0 = (void*) _a0_obj;
    vader_fn_t* _a1_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
    vader_obj_header_init(_a1_closure, 157u);
    _a1_closure->code = (void*) &vader_fn_lift___lambda_vader_resolver_0;
    _a1_closure->env = t0;
    l1 = (void*) _a1_closure;
    t0 = std_sort_sort__Symbol(l0, l1);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_string_t vader_resolver_span_origin(void* l0) {
    vader_string_t l1 = 0;
    size_t l2;
    void* l3 = NULL;
    int64_t l4;
    int32_t t0;
    vader_string_t t1 = 0;
    void** gc_raw_roots[2] = { &l0, &l3 };
    vader_string_t* gc_atom_roots[2] = { &l1, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct_toolchain_span_Position_t*) ((vader_struct_toolchain_span_Span_t*) l0)->f_start)->f_file;
    l2 = vader_host_std_core_byte_len(l1);
    l3 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(21) + l2));
    l2 = (size_t) (int64_t) INT64_C(0);
    l2 = std_core_write_string_at(l3, l2, l1);
    l2 = std_core_write_string_at(l3, l2, 468u);
    t0 = ((vader_struct_toolchain_span_Position_t*) ((vader_struct_toolchain_span_Span_t*) l0)->f_start)->f_line;
    l4 = ((int64_t) (int32_t) t0);
    l2 = std_core_write_int(l3, l2, l4);
    t1 = std_core_finish_buffer(l3, l2);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void vader_resolver_stamp_binding_spans(vader_box_t l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    size_t l4, l5;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    int64_t t2;
    vader_box_t* gc_roots[2] = { &l0, &t1 };
    void** gc_raw_roots[4] = { &l1, &l2, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 459u) {
        l2 = l0.payload.obj;
        l3 = vader_resolver_next_clone_span(l1);
        ((vader_struct_toolchain_ast_SimpleBinding_t*) l2)->f_span = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_SimpleBinding_t*) l2);
        l2 = l0.payload.obj;
        l3 = vader_resolver_next_clone_span(l1);
        ((vader_struct_toolchain_ast_SimpleBinding_t*) l2)->f_name_span = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_SimpleBinding_t*) l2);
    } else {
        if (l0.tag == 471u) {
            l2 = l0.payload.obj;
            l3 = vader_resolver_next_clone_span(l1);
            ((vader_struct_toolchain_ast_TupleBinding_t*) l2)->f_span = l3;
            VADER_WRITE_BARRIER((vader_struct_toolchain_ast_TupleBinding_t*) l2);
            t0 = l0.payload.obj;
            l2 = ((vader_struct_toolchain_ast_TupleBinding_t*) t0)->f_elements;
            l4 = ((vader_array_t*) l2)->length;
            l5 = (size_t) (int64_t) INT64_C(0);
            {
                loop_43: {
                    if ((l5 < l4)) {
                        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
                        if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                        if ((size_t) l5 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                        t1 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
                        vader_resolver_stamp_binding_spans(t1, l1);
                        t2 = (l5 + INT64_C(1));
                        l5 = (size_t) (int64_t) t2;
                        goto loop_43;
                    }
                }
            }
        } else {
            if (l0.tag == 477u) {
                l2 = l0.payload.obj;
                l3 = vader_resolver_next_clone_span(l1);
                ((vader_struct_toolchain_ast_WildcardBinding_t*) l2)->f_span = l3;
                VADER_WRITE_BARRIER((vader_struct_toolchain_ast_WildcardBinding_t*) l2);
            } else {
                if (l0.tag == 456u) {
                    l2 = l0.payload.obj;
                    l3 = vader_resolver_next_clone_span(l1);
                    ((vader_struct_toolchain_ast_RestBinding_t*) l2)->f_span = l3;
                    VADER_WRITE_BARRIER((vader_struct_toolchain_ast_RestBinding_t*) l2);
                    l2 = l0.payload.obj;
                    l3 = vader_resolver_next_clone_span(l1);
                    ((vader_struct_toolchain_ast_RestBinding_t*) l2)->f_name_span = l3;
                    VADER_WRITE_BARRIER((vader_struct_toolchain_ast_RestBinding_t*) l2);
                } else {
                    { vader_gc_top = gc_frame.prev; return; }
                }
            }
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_resolver_stamp_block_spans(void* l0, void* l1) {
    void* l2 = NULL;
    size_t l3, l4;
    vader_box_t t0 = vader_box_null();
    int64_t t1;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = vader_resolver_next_clone_span(l1);
    ((vader_struct_toolchain_ast_BlockExpr_t*) l0)->f_span = l2;
    VADER_WRITE_BARRIER((vader_struct_toolchain_ast_BlockExpr_t*) l0);
    l2 = ((vader_struct_toolchain_ast_BlockExpr_t*) l0)->f_stmts;
    l3 = ((vader_array_t*) l2)->length;
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_13: {
            if ((l4 < l3)) {
                vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
                if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                if ((size_t) l4 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
                vader_resolver_stamp_stmt_spans(t0, l1);
                t1 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t1;
                goto loop_13;
            }
        }
    }
    if (!(((vader_struct_toolchain_ast_BlockExpr_t*) l0)->f_trailing.tag == 0u)) {
        vader_resolver_stamp_expr_spans(((vader_struct_toolchain_ast_BlockExpr_t*) l0)->f_trailing, l1);
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_resolver_stamp_expr_spans(vader_box_t l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l6 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    size_t l4, l5;
    vader_box_t l7 = vader_box_null();
    void* t0 = NULL;
    int64_t t1;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l0, &l7, &t2 };
    void** gc_raw_roots[9] = { &l1, &l2, &l3, &l6, &l8, &l9, &l10, &l11, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 9u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 436u) {
        l2 = l0.payload.obj;
        l3 = vader_resolver_next_clone_span(l1);
        ((vader_struct_toolchain_ast_IntLitExpr_t*) l2)->f_span = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_IntLitExpr_t*) l2);
    } else {
        if (l0.tag == 420u) {
            l2 = l0.payload.obj;
            l3 = vader_resolver_next_clone_span(l1);
            ((vader_struct_toolchain_ast_FloatLitExpr_t*) l2)->f_span = l3;
            VADER_WRITE_BARRIER((vader_struct_toolchain_ast_FloatLitExpr_t*) l2);
        } else {
            if (l0.tag == 399u) {
                l2 = l0.payload.obj;
                l3 = vader_resolver_next_clone_span(l1);
                ((vader_struct_toolchain_ast_BoolLitExpr_t*) l2)->f_span = l3;
                VADER_WRITE_BARRIER((vader_struct_toolchain_ast_BoolLitExpr_t*) l2);
            } else {
                if (l0.tag == 449u) {
                    l2 = l0.payload.obj;
                    l3 = vader_resolver_next_clone_span(l1);
                    ((vader_struct_toolchain_ast_NullLitExpr_t*) l2)->f_span = l3;
                    VADER_WRITE_BARRIER((vader_struct_toolchain_ast_NullLitExpr_t*) l2);
                } else {
                    if (l0.tag == 404u) {
                        l2 = l0.payload.obj;
                        l3 = vader_resolver_next_clone_span(l1);
                        ((vader_struct_toolchain_ast_CharLitExpr_t*) l2)->f_span = l3;
                        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_CharLitExpr_t*) l2);
                    } else {
                        if (l0.tag == 426u) {
                            l2 = l0.payload.obj;
                            l3 = vader_resolver_next_clone_span(l1);
                            ((vader_struct_toolchain_ast_IdentExpr_t*) l2)->f_span = l3;
                            VADER_WRITE_BARRIER((vader_struct_toolchain_ast_IdentExpr_t*) l2);
                        } else {
                            if (l0.tag == 402u) {
                                l2 = l0.payload.obj;
                                l3 = vader_resolver_next_clone_span(l1);
                                ((vader_struct_toolchain_ast_CallExpr_t*) l2)->f_span = l3;
                                VADER_WRITE_BARRIER((vader_struct_toolchain_ast_CallExpr_t*) l2);
                                t0 = l0.payload.obj;
                                vader_resolver_stamp_expr_spans(((vader_struct_toolchain_ast_CallExpr_t*) t0)->f_callee, l1);
                                t0 = l0.payload.obj;
                                l2 = ((vader_struct_toolchain_ast_CallExpr_t*) t0)->f_args;
                                l4 = ((vader_array_t*) l2)->length;
                                l5 = (size_t) (int64_t) INT64_C(0);
                                {
                                    loop_104: {
                                        if ((l5 < l4)) {
                                            vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
                                            if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                                            if ((size_t) l5 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                                            l3 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
                                            l6 = vader_resolver_next_clone_span(l1);
                                            ((vader_struct_toolchain_ast_CallArg_t*) l3)->f_span = l6;
                                            VADER_WRITE_BARRIER((vader_struct_toolchain_ast_CallArg_t*) l3);
                                            vader_resolver_stamp_expr_spans(((vader_struct_toolchain_ast_CallArg_t*) l3)->f_value, l1);
                                            t1 = (l5 + INT64_C(1));
                                            l5 = (size_t) (int64_t) t1;
                                            goto loop_104;
                                        }
                                    }
                                }
                            } else {
                                if (l0.tag == 419u) {
                                    l2 = l0.payload.obj;
                                    l3 = vader_resolver_next_clone_span(l1);
                                    ((vader_struct_toolchain_ast_FieldExpr_t*) l2)->f_span = l3;
                                    VADER_WRITE_BARRIER((vader_struct_toolchain_ast_FieldExpr_t*) l2);
                                    t0 = l0.payload.obj;
                                    vader_resolver_stamp_expr_spans(((vader_struct_toolchain_ast_FieldExpr_t*) t0)->f_target, l1);
                                } else {
                                    if (l0.tag == 434u) {
                                        l2 = l0.payload.obj;
                                        l3 = vader_resolver_next_clone_span(l1);
                                        ((vader_struct_toolchain_ast_IndexExpr_t*) l2)->f_span = l3;
                                        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_IndexExpr_t*) l2);
                                        t0 = l0.payload.obj;
                                        vader_resolver_stamp_expr_spans(((vader_struct_toolchain_ast_IndexExpr_t*) t0)->f_target, l1);
                                        t0 = l0.payload.obj;
                                        vader_resolver_stamp_expr_spans(((vader_struct_toolchain_ast_IndexExpr_t*) t0)->f_index, l1);
                                    } else {
                                        if (l0.tag == 475u) {
                                            l2 = l0.payload.obj;
                                            l3 = vader_resolver_next_clone_span(l1);
                                            ((vader_struct_toolchain_ast_UnaryExpr_t*) l2)->f_span = l3;
                                            VADER_WRITE_BARRIER((vader_struct_toolchain_ast_UnaryExpr_t*) l2);
                                            t0 = l0.payload.obj;
                                            vader_resolver_stamp_expr_spans(((vader_struct_toolchain_ast_UnaryExpr_t*) t0)->f_operand, l1);
                                        } else {
                                            if (l0.tag == 396u) {
                                                l2 = l0.payload.obj;
                                                l3 = vader_resolver_next_clone_span(l1);
                                                ((vader_struct_toolchain_ast_BinaryExpr_t*) l2)->f_span = l3;
                                                VADER_WRITE_BARRIER((vader_struct_toolchain_ast_BinaryExpr_t*) l2);
                                                t0 = l0.payload.obj;
                                                vader_resolver_stamp_expr_spans(((vader_struct_toolchain_ast_BinaryExpr_t*) t0)->f_left, l1);
                                                t0 = l0.payload.obj;
                                                vader_resolver_stamp_expr_spans(((vader_struct_toolchain_ast_BinaryExpr_t*) t0)->f_right, l1);
                                            } else {
                                                if (l0.tag == 429u) {
                                                    l2 = l0.payload.obj;
                                                    l3 = vader_resolver_next_clone_span(l1);
                                                    ((vader_struct_toolchain_ast_IfExpr_t*) l2)->f_span = l3;
                                                    VADER_WRITE_BARRIER((vader_struct_toolchain_ast_IfExpr_t*) l2);
                                                    t0 = l0.payload.obj;
                                                    vader_resolver_stamp_expr_spans(((vader_struct_toolchain_ast_IfExpr_t*) t0)->f_cond, l1);
                                                    t0 = l0.payload.obj;
                                                    vader_resolver_stamp_block_spans(((vader_struct_toolchain_ast_IfExpr_t*) t0)->f_then_block, l1);
                                                    t0 = l0.payload.obj;
                                                    l7 = ((vader_struct_toolchain_ast_IfExpr_t*) t0)->f_else_branch;
                                                    if (l7.tag == 0u) {
                                                    } else {
                                                        if (l7.tag == 427u) {
                                                            t0 = l7.payload.obj;
                                                            vader_resolver_stamp_block_spans(((vader_struct_toolchain_ast_IfElseBlock_t*) t0)->f_block, l1);
                                                        } else {
                                                            if (l7.tag == 428u) {
                                                                t0 = l7.payload.obj;
                                                                vader_resolver_stamp_expr_spans(vader_ref_box(((vader_struct_toolchain_ast_IfElseIf_t*) t0)->f_branch), l1);
                                                            } else {
                                                                { vader_gc_top = gc_frame.prev; return; }
                                                            }
                                                        }
                                                    }
                                                } else {
                                                    if (l0.tag == 443u) {
                                                        l2 = l0.payload.obj;
                                                        l3 = vader_resolver_next_clone_span(l1);
                                                        ((vader_struct_toolchain_ast_MatchExpr_t*) l2)->f_span = l3;
                                                        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_MatchExpr_t*) l2);
                                                        t0 = l0.payload.obj;
                                                        vader_resolver_stamp_expr_spans(((vader_struct_toolchain_ast_MatchExpr_t*) t0)->f_scrutinee, l1);
                                                        t0 = l0.payload.obj;
                                                        l2 = ((vader_struct_toolchain_ast_MatchExpr_t*) t0)->f_arms;
                                                        l4 = ((vader_array_t*) l2)->length;
                                                        l5 = (size_t) (int64_t) INT64_C(0);
                                                        {
                                                            loop_291: {
                                                                if ((l5 < l4)) {
                                                                    vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
                                                                    if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                                                                    if ((size_t) l5 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                                                                    l3 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5);
                                                                    l6 = vader_resolver_next_clone_span(l1);
                                                                    ((vader_struct_toolchain_ast_MatchArm_t*) l3)->f_span = l6;
                                                                    VADER_WRITE_BARRIER((vader_struct_toolchain_ast_MatchArm_t*) l3);
                                                                    vader_resolver_stamp_pattern_spans(((vader_struct_toolchain_ast_MatchArm_t*) l3)->f_pattern, l1);
                                                                    if (!(((vader_struct_toolchain_ast_MatchArm_t*) l3)->f_guard.tag == 0u)) {
                                                                        vader_resolver_stamp_expr_spans(((vader_struct_toolchain_ast_MatchArm_t*) l3)->f_guard, l1);
                                                                    }
                                                                    vader_resolver_stamp_expr_spans(((vader_struct_toolchain_ast_MatchArm_t*) l3)->f_body, l1);
                                                                    t1 = (l5 + INT64_C(1));
                                                                    l5 = (size_t) (int64_t) t1;
                                                                    goto loop_291;
                                                                }
                                                            }
                                                        }
                                                    } else {
                                                        if (l0.tag == 398u) {
                                                            t0 = l0.payload.obj;
                                                            vader_resolver_stamp_block_spans(t0, l1);
                                                        } else {
                                                            if (l0.tag == 465u) {
                                                                l2 = l0.payload.obj;
                                                                l3 = vader_resolver_next_clone_span(l1);
                                                                ((vader_struct_toolchain_ast_StructLitExpr_t*) l2)->f_span = l3;
                                                                VADER_WRITE_BARRIER((vader_struct_toolchain_ast_StructLitExpr_t*) l2);
                                                                t0 = l0.payload.obj;
                                                                vader_resolver_stamp_expr_spans(((vader_struct_toolchain_ast_StructLitExpr_t*) t0)->f_type_name, l1);
                                                                t0 = l0.payload.obj;
                                                                l2 = ((vader_struct_toolchain_ast_StructLitExpr_t*) t0)->f_items;
                                                                l4 = ((vader_array_t*) l2)->length;
                                                                l5 = (size_t) (int64_t) INT64_C(0);
                                                                {
                                                                    loop_363: {
                                                                        if ((l5 < l4)) {
                                                                            vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
                                                                            if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                                                                            if ((size_t) l5 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                                                                            l7 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l5);
                                                                            if (l7.tag == 466u) {
                                                                                l3 = l7.payload.obj;
                                                                                l6 = vader_resolver_next_clone_span(l1);
                                                                                ((vader_struct_toolchain_ast_StructLitField_t*) l3)->f_span = l6;
                                                                                VADER_WRITE_BARRIER((vader_struct_toolchain_ast_StructLitField_t*) l3);
                                                                                l8 = l7.payload.obj;
                                                                                l9 = vader_resolver_next_clone_span(l1);
                                                                                ((vader_struct_toolchain_ast_StructLitField_t*) l8)->f_name_span = l9;
                                                                                VADER_WRITE_BARRIER((vader_struct_toolchain_ast_StructLitField_t*) l8);
                                                                                t0 = l7.payload.obj;
                                                                                vader_resolver_stamp_expr_spans(((vader_struct_toolchain_ast_StructLitField_t*) t0)->f_value, l1);
                                                                            } else {
                                                                                if (l7.tag == 467u) {
                                                                                    l10 = l7.payload.obj;
                                                                                    l11 = vader_resolver_next_clone_span(l1);
                                                                                    ((vader_struct_toolchain_ast_StructLitSpread_t*) l10)->f_span = l11;
                                                                                    VADER_WRITE_BARRIER((vader_struct_toolchain_ast_StructLitSpread_t*) l10);
                                                                                    t0 = l7.payload.obj;
                                                                                    vader_resolver_stamp_expr_spans(((vader_struct_toolchain_ast_StructLitSpread_t*) t0)->f_expr, l1);
                                                                                } else {
                                                                                    { vader_gc_top = gc_frame.prev; return; }
                                                                                }
                                                                            }
                                                                            t1 = (l5 + INT64_C(1));
                                                                            l5 = (size_t) (int64_t) t1;
                                                                            goto loop_363;
                                                                        }
                                                                    }
                                                                }
                                                            } else {
                                                                if (l0.tag == 458u) {
                                                                    l2 = l0.payload.obj;
                                                                    l3 = vader_resolver_next_clone_span(l1);
                                                                    ((vader_struct_toolchain_ast_SeqLitExpr_t*) l2)->f_span = l3;
                                                                    VADER_WRITE_BARRIER((vader_struct_toolchain_ast_SeqLitExpr_t*) l2);
                                                                    t0 = l0.payload.obj;
                                                                    l2 = ((vader_struct_toolchain_ast_SeqLitExpr_t*) t0)->f_elements;
                                                                    l4 = ((vader_array_t*) l2)->length;
                                                                    l5 = (size_t) (int64_t) INT64_C(0);
                                                                    {
                                                                        loop_449: {
                                                                            if ((l5 < l4)) {
                                                                                vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
                                                                                if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                                                                                if ((size_t) l5 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                                                                                t2 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l5);
                                                                                vader_resolver_stamp_expr_spans(t2, l1);
                                                                                t1 = (l5 + INT64_C(1));
                                                                                l5 = (size_t) (int64_t) t1;
                                                                                goto loop_449;
                                                                            }
                                                                        }
                                                                    }
                                                                } else {
                                                                    if (l0.tag == 454u) {
                                                                        l2 = l0.payload.obj;
                                                                        l3 = vader_resolver_next_clone_span(l1);
                                                                        ((vader_struct_toolchain_ast_RangeExpr_t*) l2)->f_span = l3;
                                                                        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_RangeExpr_t*) l2);
                                                                        t0 = l0.payload.obj;
                                                                        vader_resolver_stamp_expr_spans(((vader_struct_toolchain_ast_RangeExpr_t*) t0)->f_lower, l1);
                                                                        t0 = l0.payload.obj;
                                                                        vader_resolver_stamp_expr_spans(((vader_struct_toolchain_ast_RangeExpr_t*) t0)->f_upper, l1);
                                                                    } else {
                                                                        if (l0.tag == 395u) {
                                                                            l2 = l0.payload.obj;
                                                                            l3 = vader_resolver_next_clone_span(l1);
                                                                            ((vader_struct_toolchain_ast_AwaitExpr_t*) l2)->f_span = l3;
                                                                            VADER_WRITE_BARRIER((vader_struct_toolchain_ast_AwaitExpr_t*) l2);
                                                                            t0 = l0.payload.obj;
                                                                            vader_resolver_stamp_expr_spans(((vader_struct_toolchain_ast_AwaitExpr_t*) t0)->f_inner, l1);
                                                                        } else {
                                                                            if (l0.tag == 403u) {
                                                                                l2 = l0.payload.obj;
                                                                                l3 = vader_resolver_next_clone_span(l1);
                                                                                ((vader_struct_toolchain_ast_CastExpr_t*) l2)->f_span = l3;
                                                                                VADER_WRITE_BARRIER((vader_struct_toolchain_ast_CastExpr_t*) l2);
                                                                                t0 = l0.payload.obj;
                                                                                vader_resolver_stamp_expr_spans(((vader_struct_toolchain_ast_CastExpr_t*) t0)->f_target, l1);
                                                                                t0 = l0.payload.obj;
                                                                                vader_resolver_stamp_expr_spans(((vader_struct_toolchain_ast_CastExpr_t*) t0)->f_value, l1);
                                                                            } else {
                                                                                if (l0.tag == 437u) {
                                                                                    l2 = l0.payload.obj;
                                                                                    l3 = vader_resolver_next_clone_span(l1);
                                                                                    ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l2)->f_span = l3;
                                                                                    VADER_WRITE_BARRIER((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l2);
                                                                                    l2 = l0.payload.obj;
                                                                                    l3 = vader_resolver_next_clone_span(l1);
                                                                                    ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l2)->f_name_span = l3;
                                                                                    VADER_WRITE_BARRIER((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l2);
                                                                                    t0 = l0.payload.obj;
                                                                                    l2 = ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) t0)->f_args;
                                                                                    l4 = ((vader_array_t*) l2)->length;
                                                                                    l5 = (size_t) (int64_t) INT64_C(0);
                                                                                    {
                                                                                        loop_562: {
                                                                                            if ((l5 < l4)) {
                                                                                                vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
                                                                                                if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                                                                                                if ((size_t) l5 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                                                                                                t2 = vader_array_ref_load_box(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l5);
                                                                                                vader_resolver_stamp_expr_spans(t2, l1);
                                                                                                t1 = (l5 + INT64_C(1));
                                                                                                l5 = (size_t) (int64_t) t1;
                                                                                                goto loop_562;
                                                                                            }
                                                                                        }
                                                                                    }
                                                                                } else {
                                                                                    if (l0.tag == 414u) {
                                                                                        l2 = l0.payload.obj;
                                                                                        l3 = vader_resolver_next_clone_span(l1);
                                                                                        ((vader_struct_toolchain_ast_DotVariantExpr_t*) l2)->f_span = l3;
                                                                                        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_DotVariantExpr_t*) l2);
                                                                                        l2 = l0.payload.obj;
                                                                                        l3 = vader_resolver_next_clone_span(l1);
                                                                                        ((vader_struct_toolchain_ast_DotVariantExpr_t*) l2)->f_variant_span = l3;
                                                                                        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_DotVariantExpr_t*) l2);
                                                                                    } else {
                                                                                        if (l0.tag == 460u) {
                                                                                            l2 = l0.payload.obj;
                                                                                            l3 = vader_resolver_next_clone_span(l1);
                                                                                            ((vader_struct_toolchain_ast_StringLitExpr_t*) l2)->f_span = l3;
                                                                                            VADER_WRITE_BARRIER((vader_struct_toolchain_ast_StringLitExpr_t*) l2);
                                                                                            t0 = l0.payload.obj;
                                                                                            l2 = ((vader_struct_toolchain_ast_StringLitExpr_t*) t0)->f_parts;
                                                                                            l4 = ((vader_array_t*) l2)->length;
                                                                                            l5 = (size_t) (int64_t) INT64_C(0);
                                                                                            {
                                                                                                loop_624: {
                                                                                                    if ((l5 < l4)) {
                                                                                                        vader_array_t* _a5_slotarr = ((vader_array_t*) l2);
                                                                                                        if (_a5_slotarr->buf != NULL && _a5_slotarr->buf->header.forward != NULL) { _a5_slotarr->buf = vader_array_buf_forward(_a5_slotarr->buf); }
                                                                                                        if ((size_t) l5 >= _a5_slotarr->length) { vader_trap("array index out of bounds"); }
                                                                                                        l7 = vader_array_ref_load_box(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l5);
                                                                                                        if (l7.tag == 462u) {
                                                                                                            l3 = l7.payload.obj;
                                                                                                            l6 = vader_resolver_next_clone_span(l1);
                                                                                                            ((vader_struct_toolchain_ast_StringLitText_t*) l3)->f_span = l6;
                                                                                                            VADER_WRITE_BARRIER((vader_struct_toolchain_ast_StringLitText_t*) l3);
                                                                                                        } else {
                                                                                                            if (l7.tag == 461u) {
                                                                                                                l8 = l7.payload.obj;
                                                                                                                l9 = vader_resolver_next_clone_span(l1);
                                                                                                                ((vader_struct_toolchain_ast_StringLitInterp_t*) l8)->f_span = l9;
                                                                                                                VADER_WRITE_BARRIER((vader_struct_toolchain_ast_StringLitInterp_t*) l8);
                                                                                                                t0 = l7.payload.obj;
                                                                                                                vader_resolver_stamp_expr_spans(((vader_struct_toolchain_ast_StringLitInterp_t*) t0)->f_expr, l1);
                                                                                                            } else {
                                                                                                                { vader_gc_top = gc_frame.prev; return; }
                                                                                                            }
                                                                                                        }
                                                                                                        t1 = (l5 + INT64_C(1));
                                                                                                        l5 = (size_t) (int64_t) t1;
                                                                                                        goto loop_624;
                                                                                                    }
                                                                                                }
                                                                                            }
                                                                                        } else {
                                                                                            if (l0.tag == 439u) {
                                                                                                l2 = l0.payload.obj;
                                                                                                l3 = vader_resolver_next_clone_span(l1);
                                                                                                ((vader_struct_toolchain_ast_LambdaExpr_t*) l2)->f_span = l3;
                                                                                                VADER_WRITE_BARRIER((vader_struct_toolchain_ast_LambdaExpr_t*) l2);
                                                                                                t0 = l0.payload.obj;
                                                                                                l2 = ((vader_struct_toolchain_ast_LambdaExpr_t*) t0)->f_params;
                                                                                                l4 = ((vader_array_t*) l2)->length;
                                                                                                l5 = (size_t) (int64_t) INT64_C(0);
                                                                                                {
                                                                                                    loop_696: {
                                                                                                        if ((l5 < l4)) {
                                                                                                            vader_array_t* _a6_slotarr = ((vader_array_t*) l2);
                                                                                                            if (_a6_slotarr->buf != NULL && _a6_slotarr->buf->header.forward != NULL) { _a6_slotarr->buf = vader_array_buf_forward(_a6_slotarr->buf); }
                                                                                                            if ((size_t) l5 >= _a6_slotarr->length) { vader_trap("array index out of bounds"); }
                                                                                                            l3 = vader_array_ref_load_obj(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l5);
                                                                                                            l6 = vader_resolver_next_clone_span(l1);
                                                                                                            ((vader_struct_toolchain_ast_FnParam_t*) l3)->f_span = l6;
                                                                                                            VADER_WRITE_BARRIER((vader_struct_toolchain_ast_FnParam_t*) l3);
                                                                                                            if (!(((vader_struct_toolchain_ast_FnParam_t*) l3)->f_ty.tag == 0u)) {
                                                                                                                vader_resolver_stamp_expr_spans(((vader_struct_toolchain_ast_FnParam_t*) l3)->f_ty, l1);
                                                                                                            }
                                                                                                            if (!(((vader_struct_toolchain_ast_FnParam_t*) l3)->f_default_value.tag == 0u)) {
                                                                                                                vader_resolver_stamp_expr_spans(((vader_struct_toolchain_ast_FnParam_t*) l3)->f_default_value, l1);
                                                                                                            }
                                                                                                            t1 = (l5 + INT64_C(1));
                                                                                                            l5 = (size_t) (int64_t) t1;
                                                                                                            goto loop_696;
                                                                                                        }
                                                                                                    }
                                                                                                }
                                                                                                t0 = l0.payload.obj;
                                                                                                if (!(((vader_struct_toolchain_ast_LambdaExpr_t*) t0)->f_return_type.tag == 0u)) {
                                                                                                    t0 = l0.payload.obj;
                                                                                                    vader_resolver_stamp_expr_spans(((vader_struct_toolchain_ast_LambdaExpr_t*) t0)->f_return_type, l1);
                                                                                                }
                                                                                                t0 = l0.payload.obj;
                                                                                                vader_resolver_stamp_block_spans(((vader_struct_toolchain_ast_LambdaExpr_t*) t0)->f_body, l1);
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

static void vader_resolver_stamp_pattern_spans(vader_box_t l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[4] = { &l1, &l2, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 438u) {
        l2 = l0.payload.obj;
        l3 = vader_resolver_next_clone_span(l1);
        ((vader_struct_toolchain_ast_IsPattern_t*) l2)->f_span = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_IsPattern_t*) l2);
        t0 = l0.payload.obj;
        if (!(((vader_struct_toolchain_ast_IsPattern_t*) t0)->f_inner.tag == 0u)) {
            t0 = l0.payload.obj;
            vader_resolver_stamp_pattern_spans(((vader_struct_toolchain_ast_IsPattern_t*) t0)->f_inner, l1);
        }
    } else {
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_resolver_stamp_stmt_spans(vader_box_t l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    vader_box_t l4 = vader_box_null(), l5 = vader_box_null();
    vader_string_t l6 = 0;
    void* t0 = NULL;
    vader_box_t* gc_roots[3] = { &l0, &l4, &l5 };
    void** gc_raw_roots[4] = { &l1, &l2, &l3, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l6 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    if (l0.tag == 440u) {
        l2 = l0.payload.obj;
        l3 = vader_resolver_next_clone_span(l1);
        ((vader_struct_toolchain_ast_LetStmt_t*) l2)->f_span = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_LetStmt_t*) l2);
        t0 = l0.payload.obj;
        vader_resolver_stamp_binding_spans(((vader_struct_toolchain_ast_LetStmt_t*) t0)->f_binding, l1);
        t0 = l0.payload.obj;
        if (!(((vader_struct_toolchain_ast_LetStmt_t*) t0)->f_ty.tag == 0u)) {
            t0 = l0.payload.obj;
            vader_resolver_stamp_expr_spans(((vader_struct_toolchain_ast_LetStmt_t*) t0)->f_ty, l1);
        }
        t0 = l0.payload.obj;
        vader_resolver_stamp_expr_spans(((vader_struct_toolchain_ast_LetStmt_t*) t0)->f_value, l1);
    } else {
        if (l0.tag == 418u) {
            l2 = l0.payload.obj;
            l3 = vader_resolver_next_clone_span(l1);
            ((vader_struct_toolchain_ast_ExprStmt_t*) l2)->f_span = l3;
            VADER_WRITE_BARRIER((vader_struct_toolchain_ast_ExprStmt_t*) l2);
            t0 = l0.payload.obj;
            vader_resolver_stamp_expr_spans(((vader_struct_toolchain_ast_ExprStmt_t*) t0)->f_expr, l1);
        } else {
            if (l0.tag == 457u) {
                l2 = l0.payload.obj;
                l3 = vader_resolver_next_clone_span(l1);
                ((vader_struct_toolchain_ast_ReturnStmt_t*) l2)->f_span = l3;
                VADER_WRITE_BARRIER((vader_struct_toolchain_ast_ReturnStmt_t*) l2);
                t0 = l0.payload.obj;
                if (!(((vader_struct_toolchain_ast_ReturnStmt_t*) t0)->f_value.tag == 0u)) {
                    t0 = l0.payload.obj;
                    vader_resolver_stamp_expr_spans(((vader_struct_toolchain_ast_ReturnStmt_t*) t0)->f_value, l1);
                }
            } else {
                if (l0.tag == 394u) {
                    l2 = l0.payload.obj;
                    l3 = vader_resolver_next_clone_span(l1);
                    ((vader_struct_toolchain_ast_AssignStmt_t*) l2)->f_span = l3;
                    VADER_WRITE_BARRIER((vader_struct_toolchain_ast_AssignStmt_t*) l2);
                    t0 = l0.payload.obj;
                    vader_resolver_stamp_expr_spans(((vader_struct_toolchain_ast_AssignStmt_t*) t0)->f_target, l1);
                    t0 = l0.payload.obj;
                    vader_resolver_stamp_expr_spans(((vader_struct_toolchain_ast_AssignStmt_t*) t0)->f_value, l1);
                } else {
                    if (l0.tag == 424u) {
                        l2 = l0.payload.obj;
                        l3 = vader_resolver_next_clone_span(l1);
                        ((vader_struct_toolchain_ast_ForStmt_t*) l2)->f_span = l3;
                        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_ForStmt_t*) l2);
                        t0 = l0.payload.obj;
                        l4 = ((vader_struct_toolchain_ast_ForStmt_t*) t0)->f_form;
                        if (l4.tag == 476u) {
                            t0 = l4.payload.obj;
                            vader_resolver_stamp_expr_spans(((vader_struct_toolchain_ast_WhileFor_t*) t0)->f_cond, l1);
                        } else {
                            if (l4.tag == 433u) {
                                l2 = l4.payload.obj;
                                l5 = ((vader_struct_toolchain_ast_InFor_t*) l2)->f_loop_var;
                                if (l5.tag == 447u) {
                                    t0 = l5.payload.obj;
                                    l6 = ((vader_struct_toolchain_ast_NamedVar_t*) t0)->f_name;
                                    l3 = vader_resolver_next_clone_span(l1);
                                    vader_struct_toolchain_ast_NamedVar_t* _a0_obj = (vader_struct_toolchain_ast_NamedVar_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_NamedVar_t));
                                    vader_obj_header_init(_a0_obj, 447u);
                                    _a0_obj->f_name = l6;
                                    _a0_obj->f_span = l3;
                                    l3 = (void*) _a0_obj;
                                    ((vader_struct_toolchain_ast_InFor_t*) l2)->f_loop_var = vader_ref_box(l3);
                                    VADER_WRITE_BARRIER((vader_struct_toolchain_ast_InFor_t*) l2);
                                } else {
                                    if (l5.tag == 412u) {
                                        t0 = l5.payload.obj;
                                        vader_resolver_stamp_binding_spans(((vader_struct_toolchain_ast_DestructureVar_t*) t0)->f_pattern, l1);
                                    } else {
                                        if (l5.tag == 413u) {
                                        } else {
                                            { vader_gc_top = gc_frame.prev; return; }
                                        }
                                    }
                                }
                                vader_resolver_stamp_expr_spans(((vader_struct_toolchain_ast_InFor_t*) l2)->f_iter, l1);
                            } else {
                                if (l4.tag == 435u) {
                                } else {
                                    { vader_gc_top = gc_frame.prev; return; }
                                }
                            }
                        }
                        t0 = l0.payload.obj;
                        vader_resolver_stamp_block_spans(((vader_struct_toolchain_ast_ForStmt_t*) t0)->f_body, l1);
                    } else {
                    }
                }
            }
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static vader_box_t vader_resolver_subst_opt_expr(vader_box_t l0, void* l1) {
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l0, &t0 };
    void** gc_raw_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 0u) {
        t0 = vader_box_obj(0u, NULL);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_resolver_substitute_expr_full(l0, l1);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_resolver_substitute_block(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    size_t l4, l5;
    vader_box_t l6 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    int64_t t1;
    void* t2 = NULL;
    vader_box_t* gc_roots[2] = { &l6, &t0 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(115u, 0u, 13u, 1052u);
    l2 = (void*) _a0_arr;
    l3 = ((vader_struct_toolchain_ast_BlockExpr_t*) l0)->f_stmts;
    l4 = ((vader_array_t*) l3)->length;
    l5 = (size_t) (int64_t) INT64_C(0);
    {
        loop_9: {
            if ((l5 < l4)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l5 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5);
                l6 = vader_resolver_substitute_stmt(t0, l1);
                vader_array_push((vader_array_t*) l2, l6);
                t1 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t1;
                goto loop_9;
            }
        }
    }
    l6 = vader_box_obj(0u, NULL);
    if (!(((vader_struct_toolchain_ast_BlockExpr_t*) l0)->f_trailing.tag == 0u)) {
        l6 = vader_resolver_substitute_expr_full(((vader_struct_toolchain_ast_BlockExpr_t*) l0)->f_trailing, l1);
    }
    vader_struct_toolchain_ast_BlockExpr_t* _a2_obj = (vader_struct_toolchain_ast_BlockExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_BlockExpr_t));
    vader_obj_header_init(_a2_obj, 398u);
    _a2_obj->f_span = ((vader_struct_toolchain_ast_BlockExpr_t*) l0)->f_span;
    _a2_obj->f_id = (size_t) (int64_t) INT64_C(0);
    _a2_obj->f_stmts = l2;
    _a2_obj->f_trailing = l6;
    t2 = (void*) _a2_obj;
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_resolver_substitute_block_materialized(void* l0, void* l1, void* l2, void* l3) {
    void* l4 = NULL;
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l4 = vader_resolver_substitute_block(l0, l1);
    vader_parser_assign_block_ids(l4, l2);
    vader_resolver_stamp_block_spans(l4, l3);
    { void* __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_box_t vader_resolver_substitute_coalesce_fallback(vader_box_t l0, void* l1) {
    vader_box_t l2 = vader_box_null();
    void* l3 = NULL;
    void* t0 = NULL;
    vader_box_t* gc_roots[2] = { &l0, &l2 };
    void** gc_raw_roots[3] = { &l1, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 457u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_toolchain_ast_ReturnStmt_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l2 = vader_resolver_subst_opt_expr(((vader_struct_toolchain_ast_ReturnStmt_t*) t0)->f_value, l1);
        vader_struct_toolchain_ast_ReturnStmt_t* _a0_obj = (vader_struct_toolchain_ast_ReturnStmt_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_ReturnStmt_t));
        vader_obj_header_init(_a0_obj, 457u);
        _a0_obj->f_span = l3;
        _a0_obj->f_id = (size_t) (int64_t) INT64_C(0);
        _a0_obj->f_value = l2;
        t0 = (void*) _a0_obj;
        l2 = vader_ref_box(t0);
    } else {
        if ((l0.tag == 400u || l0.tag == 406u)) {
            l2 = l0;
        } else {
            if ((l0.tag == 392u || l0.tag == 395u || l0.tag == 396u || l0.tag == 398u || l0.tag == 399u || l0.tag == 402u || l0.tag == 403u || l0.tag == 404u || l0.tag == 414u || l0.tag == 419u || l0.tag == 420u || l0.tag == 423u || l0.tag == 425u || l0.tag == 426u || l0.tag == 429u || l0.tag == 434u || l0.tag == 436u || l0.tag == 437u || l0.tag == 439u || l0.tag == 443u || l0.tag == 445u || l0.tag == 448u || l0.tag == 449u || l0.tag == 454u || l0.tag == 458u || l0.tag == 460u || l0.tag == 465u || l0.tag == 475u)) {
                l2 = vader_resolver_substitute_expr_full(l0, l1);
            } else {
                vader_unreachable("unreachable return in vader_resolver$substitute_coalesce_fallback");
            }
        }
    }
    { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_box_t vader_resolver_substitute_expr_full(vader_box_t l0, void* l1) {
    void* l2 = NULL;
    void* l5 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l11 = NULL;
    void* l16 = NULL;
    void* l17 = NULL;
    vader_box_t l3 = vader_box_null(), l4 = vader_box_null(), l14 = vader_box_null();
    size_t l6, l7;
    bool l10, l15;
    vader_string_t l12 = 0;
    uint8_t l13;
    void* t0 = NULL;
    void* t3 = NULL;
    vader_box_t t1 = vader_box_null();
    int64_t t2;
    vader_box_t* gc_roots[5] = { &l0, &l3, &l4, &l14, &t1 };
    void** gc_raw_roots[10] = { &l1, &l2, &l5, &l8, &l9, &l11, &l16, &l17, &t0, &t3 };
    vader_string_t* gc_atom_roots[1] = { &l12 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 5u, 10u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    if ((l0.tag == 399u || l0.tag == 404u || l0.tag == 420u || l0.tag == 436u || l0.tag == 449u)) {
        { vader_box_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 448u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast_NullCoalesceExpr_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l3 = vader_resolver_substitute_expr_full(((vader_struct_toolchain_ast_NullCoalesceExpr_t*) t0)->f_left, l1);
        t0 = l0.payload.obj;
        l4 = vader_resolver_substitute_coalesce_fallback(((vader_struct_toolchain_ast_NullCoalesceExpr_t*) t0)->f_fallback, l1);
        vader_struct_toolchain_ast_NullCoalesceExpr_t* _a0_obj = (vader_struct_toolchain_ast_NullCoalesceExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_NullCoalesceExpr_t));
        vader_obj_header_init(_a0_obj, 448u);
        _a0_obj->f_span = l2;
        _a0_obj->f_id = (size_t) (int64_t) INT64_C(0);
        _a0_obj->f_left = l3;
        _a0_obj->f_fallback = l4;
        t0 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 426u) {
        t0 = l0.payload.obj;
        t1 = vader_resolver_substitute_type_expr(vader_ref_box(t0), l1);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 425u) {
        t0 = l0.payload.obj;
        t1 = vader_resolver_substitute_type_expr(vader_ref_box(t0), l1);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 423u) {
        t0 = l0.payload.obj;
        t1 = vader_resolver_substitute_type_expr(vader_ref_box(t0), l1);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 392u) {
        t0 = l0.payload.obj;
        t1 = vader_resolver_substitute_type_expr(vader_ref_box(t0), l1);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 445u) {
        t0 = l0.payload.obj;
        t1 = vader_resolver_substitute_type_expr(vader_ref_box(t0), l1);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 402u) {
        vader_array_t* _a1_arr = vader_array_new(20u, 0u, 13u, 401u);
        l2 = (void*) _a1_arr;
        t0 = l0.payload.obj;
        l5 = ((vader_struct_toolchain_ast_CallExpr_t*) t0)->f_args;
        l6 = ((vader_array_t*) l5)->length;
        l7 = (size_t) (int64_t) INT64_C(0);
        {
            loop_91: {
                if ((l7 < l6)) {
                    vader_array_t* _a2_slotarr = ((vader_array_t*) l5);
                    if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                    if ((size_t) l7 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                    l8 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l7);
                    l9 = ((vader_struct_toolchain_ast_CallArg_t*) l8)->f_span;
                    l3 = ((vader_struct_toolchain_ast_CallArg_t*) l8)->f_name;
                    l4 = vader_resolver_substitute_expr_full(((vader_struct_toolchain_ast_CallArg_t*) l8)->f_value, l1);
                    l10 = ((vader_struct_toolchain_ast_CallArg_t*) l8)->f_spread;
                    vader_struct_toolchain_ast_CallArg_t* _a3_obj = (vader_struct_toolchain_ast_CallArg_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_CallArg_t));
                    vader_obj_header_init(_a3_obj, 401u);
                    _a3_obj->f_span = l9;
                    _a3_obj->f_id = (size_t) (int64_t) INT64_C(0);
                    _a3_obj->f_name = l3;
                    _a3_obj->f_value = l4;
                    _a3_obj->f_spread = l10;
                    l11 = (void*) _a3_obj;
                    vader_array_push((vader_array_t*) l2, vader_ref_box(l11));
                    t2 = (l7 + INT64_C(1));
                    l7 = (size_t) (int64_t) t2;
                    goto loop_91;
                }
            }
        }
        t0 = l0.payload.obj;
        l5 = ((vader_struct_toolchain_ast_CallExpr_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l3 = vader_resolver_substitute_expr_full(((vader_struct_toolchain_ast_CallExpr_t*) t0)->f_callee, l1);
        vader_struct_toolchain_ast_CallExpr_t* _a4_obj = (vader_struct_toolchain_ast_CallExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_CallExpr_t));
        vader_obj_header_init(_a4_obj, 402u);
        _a4_obj->f_span = l5;
        _a4_obj->f_id = (size_t) (int64_t) INT64_C(0);
        _a4_obj->f_callee = l3;
        _a4_obj->f_args = l2;
        _a4_obj->f_trailing_comma = false;
        t0 = (void*) _a4_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 419u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast_FieldExpr_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l3 = vader_resolver_substitute_expr_full(((vader_struct_toolchain_ast_FieldExpr_t*) t0)->f_target, l1);
        t0 = l0.payload.obj;
        l12 = ((vader_struct_toolchain_ast_FieldExpr_t*) t0)->f_field;
        t0 = l0.payload.obj;
        l5 = ((vader_struct_toolchain_ast_FieldExpr_t*) t0)->f_field_span;
        t0 = l0.payload.obj;
        l10 = ((vader_struct_toolchain_ast_FieldExpr_t*) t0)->f_is_numeric;
        vader_struct_toolchain_ast_FieldExpr_t* _a5_obj = (vader_struct_toolchain_ast_FieldExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_FieldExpr_t));
        vader_obj_header_init(_a5_obj, 419u);
        _a5_obj->f_span = l2;
        _a5_obj->f_id = (size_t) (int64_t) INT64_C(0);
        _a5_obj->f_target = l3;
        _a5_obj->f_field = l12;
        _a5_obj->f_field_span = l5;
        _a5_obj->f_is_numeric = l10;
        t0 = (void*) _a5_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 434u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast_IndexExpr_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l3 = vader_resolver_substitute_expr_full(((vader_struct_toolchain_ast_IndexExpr_t*) t0)->f_target, l1);
        t0 = l0.payload.obj;
        l4 = vader_resolver_substitute_expr_full(((vader_struct_toolchain_ast_IndexExpr_t*) t0)->f_index, l1);
        vader_struct_toolchain_ast_IndexExpr_t* _a6_obj = (vader_struct_toolchain_ast_IndexExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_IndexExpr_t));
        vader_obj_header_init(_a6_obj, 434u);
        _a6_obj->f_span = l2;
        _a6_obj->f_id = (size_t) (int64_t) INT64_C(0);
        _a6_obj->f_target = l3;
        _a6_obj->f_index = l4;
        t0 = (void*) _a6_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 475u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast_UnaryExpr_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l13 = ((vader_struct_toolchain_ast_UnaryExpr_t*) t0)->f_op;
        t0 = l0.payload.obj;
        l3 = vader_resolver_substitute_expr_full(((vader_struct_toolchain_ast_UnaryExpr_t*) t0)->f_operand, l1);
        vader_struct_toolchain_ast_UnaryExpr_t* _a7_obj = (vader_struct_toolchain_ast_UnaryExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_UnaryExpr_t));
        vader_obj_header_init(_a7_obj, 475u);
        _a7_obj->f_span = l2;
        _a7_obj->f_id = (size_t) (int64_t) INT64_C(0);
        _a7_obj->f_op = l13;
        _a7_obj->f_operand = l3;
        t0 = (void*) _a7_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 396u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast_BinaryExpr_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l13 = ((vader_struct_toolchain_ast_BinaryExpr_t*) t0)->f_op;
        t0 = l0.payload.obj;
        l3 = vader_resolver_substitute_expr_full(((vader_struct_toolchain_ast_BinaryExpr_t*) t0)->f_left, l1);
        t0 = l0.payload.obj;
        l4 = vader_resolver_substitute_expr_full(((vader_struct_toolchain_ast_BinaryExpr_t*) t0)->f_right, l1);
        t0 = l0.payload.obj;
        l12 = ((vader_struct_toolchain_ast_BinaryExpr_t*) t0)->f_bind_as;
        vader_struct_toolchain_ast_BinaryExpr_t* _a8_obj = (vader_struct_toolchain_ast_BinaryExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_BinaryExpr_t));
        vader_obj_header_init(_a8_obj, 396u);
        _a8_obj->f_span = l2;
        _a8_obj->f_id = (size_t) (int64_t) INT64_C(0);
        _a8_obj->f_op = l13;
        _a8_obj->f_left = l3;
        _a8_obj->f_right = l4;
        _a8_obj->f_bind_as = l12;
        t0 = (void*) _a8_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 429u) {
        l3 = vader_box_obj(0u, NULL);
        t0 = l0.payload.obj;
        l4 = ((vader_struct_toolchain_ast_IfExpr_t*) t0)->f_else_branch;
        if (l4.tag == 0u) {
        } else {
            if (l4.tag == 427u) {
                t0 = l4.payload.obj;
                t3 = vader_resolver_substitute_block(((vader_struct_toolchain_ast_IfElseBlock_t*) t0)->f_block, l1);
                vader_struct_toolchain_ast_IfElseBlock_t* _a9_obj = (vader_struct_toolchain_ast_IfElseBlock_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_IfElseBlock_t));
                vader_obj_header_init(_a9_obj, 427u);
                _a9_obj->f_block = t3;
                t0 = (void*) _a9_obj;
                l3 = vader_ref_box(t0);
            } else {
                if (l4.tag == 428u) {
                    t0 = l4.payload.obj;
                    l4 = vader_resolver_substitute_expr_full(vader_ref_box(((vader_struct_toolchain_ast_IfElseIf_t*) t0)->f_branch), l1);
                    if (l4.tag == 429u) {
                        t0 = l4.payload.obj;
                        vader_struct_toolchain_ast_IfElseIf_t* _a10_obj = (vader_struct_toolchain_ast_IfElseIf_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_IfElseIf_t));
                        vader_obj_header_init(_a10_obj, 428u);
                        _a10_obj->f_branch = t0;
                        t0 = (void*) _a10_obj;
                        l3 = vader_ref_box(t0);
                    } else {
                    }
                } else {
                    vader_unreachable("unreachable return in vader_resolver$substitute_expr_full");
                }
            }
        }
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast_IfExpr_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l4 = vader_resolver_substitute_expr_full(((vader_struct_toolchain_ast_IfExpr_t*) t0)->f_cond, l1);
        t0 = l0.payload.obj;
        l5 = vader_resolver_substitute_block(((vader_struct_toolchain_ast_IfExpr_t*) t0)->f_then_block, l1);
        vader_struct_toolchain_ast_IfExpr_t* _a11_obj = (vader_struct_toolchain_ast_IfExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_IfExpr_t));
        vader_obj_header_init(_a11_obj, 429u);
        _a11_obj->f_span = l2;
        _a11_obj->f_id = (size_t) (int64_t) INT64_C(0);
        _a11_obj->f_cond = l4;
        _a11_obj->f_then_block = l5;
        _a11_obj->f_else_branch = l3;
        t0 = (void*) _a11_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 443u) {
        vader_array_t* _a12_arr = vader_array_new(28u, 0u, 13u, 442u);
        l2 = (void*) _a12_arr;
        t0 = l0.payload.obj;
        l5 = ((vader_struct_toolchain_ast_MatchExpr_t*) t0)->f_arms;
        l6 = ((vader_array_t*) l5)->length;
        l7 = (size_t) (int64_t) INT64_C(0);
        {
            loop_353: {
                if ((l7 < l6)) {
                    vader_array_t* _a13_slotarr = ((vader_array_t*) l5);
                    if (_a13_slotarr->buf != NULL && _a13_slotarr->buf->header.forward != NULL) { _a13_slotarr->buf = vader_array_buf_forward(_a13_slotarr->buf); }
                    if ((size_t) l7 >= _a13_slotarr->length) { vader_trap("array index out of bounds"); }
                    l8 = vader_array_ref_load_obj(_a13_slotarr->buf, _a13_slotarr->offset + (size_t) l7);
                    l3 = vader_box_obj(0u, NULL);
                    if (!(((vader_struct_toolchain_ast_MatchArm_t*) l8)->f_guard.tag == 0u)) {
                        l3 = vader_resolver_substitute_expr_full(((vader_struct_toolchain_ast_MatchArm_t*) l8)->f_guard, l1);
                    }
                    l9 = ((vader_struct_toolchain_ast_MatchArm_t*) l8)->f_span;
                    l4 = vader_resolver_substitute_pattern(((vader_struct_toolchain_ast_MatchArm_t*) l8)->f_pattern, l1);
                    l14 = vader_resolver_substitute_expr_full(((vader_struct_toolchain_ast_MatchArm_t*) l8)->f_body, l1);
                    vader_struct_toolchain_ast_MatchArm_t* _a14_obj = (vader_struct_toolchain_ast_MatchArm_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_MatchArm_t));
                    vader_obj_header_init(_a14_obj, 442u);
                    _a14_obj->f_span = l9;
                    _a14_obj->f_id = (size_t) (int64_t) INT64_C(0);
                    _a14_obj->f_pattern = l4;
                    _a14_obj->f_guard = l3;
                    _a14_obj->f_body = l14;
                    l11 = (void*) _a14_obj;
                    vader_array_push((vader_array_t*) l2, vader_ref_box(l11));
                    t2 = (l7 + INT64_C(1));
                    l7 = (size_t) (int64_t) t2;
                    goto loop_353;
                }
            }
        }
        t0 = l0.payload.obj;
        l5 = ((vader_struct_toolchain_ast_MatchExpr_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l3 = vader_resolver_substitute_expr_full(((vader_struct_toolchain_ast_MatchExpr_t*) t0)->f_scrutinee, l1);
        t0 = l0.payload.obj;
        l10 = ((vader_struct_toolchain_ast_MatchExpr_t*) t0)->f_partial;
        t0 = l0.payload.obj;
        l15 = ((vader_struct_toolchain_ast_MatchExpr_t*) t0)->f_unreachable;
        t0 = l0.payload.obj;
        l12 = ((vader_struct_toolchain_ast_MatchExpr_t*) t0)->f_bind_as;
        vader_struct_toolchain_ast_MatchExpr_t* _a15_obj = (vader_struct_toolchain_ast_MatchExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_MatchExpr_t));
        vader_obj_header_init(_a15_obj, 443u);
        _a15_obj->f_span = l5;
        _a15_obj->f_id = (size_t) (int64_t) INT64_C(0);
        _a15_obj->f_scrutinee = l3;
        _a15_obj->f_arms = l2;
        _a15_obj->f_partial = l10;
        _a15_obj->f_unreachable = l15;
        _a15_obj->f_bind_as = l12;
        t0 = (void*) _a15_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 398u) {
        t0 = l0.payload.obj;
        t3 = vader_resolver_substitute_block(t0, l1);
        { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 465u) {
        vader_array_t* _a16_arr = vader_array_new(120u, 0u, 13u, 1082u);
        l2 = (void*) _a16_arr;
        t0 = l0.payload.obj;
        l5 = ((vader_struct_toolchain_ast_StructLitExpr_t*) t0)->f_items;
        l6 = ((vader_array_t*) l5)->length;
        l7 = (size_t) (int64_t) INT64_C(0);
        {
            loop_459: {
                if ((l7 < l6)) {
                    vader_array_t* _a17_slotarr = ((vader_array_t*) l5);
                    if (_a17_slotarr->buf != NULL && _a17_slotarr->buf->header.forward != NULL) { _a17_slotarr->buf = vader_array_buf_forward(_a17_slotarr->buf); }
                    if ((size_t) l7 >= _a17_slotarr->length) { vader_trap("array index out of bounds"); }
                    l3 = vader_array_ref_load_box(_a17_slotarr->buf, _a17_slotarr->offset + (size_t) l7);
                    if (l3.tag == 466u) {
                        t0 = l3.payload.obj;
                        l8 = ((vader_struct_toolchain_ast_StructLitField_t*) t0)->f_span;
                        t0 = l3.payload.obj;
                        l12 = ((vader_struct_toolchain_ast_StructLitField_t*) t0)->f_name;
                        t0 = l3.payload.obj;
                        l9 = ((vader_struct_toolchain_ast_StructLitField_t*) t0)->f_name_span;
                        t0 = l3.payload.obj;
                        l4 = vader_resolver_substitute_expr_full(((vader_struct_toolchain_ast_StructLitField_t*) t0)->f_value, l1);
                        vader_struct_toolchain_ast_StructLitField_t* _a18_obj = (vader_struct_toolchain_ast_StructLitField_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_StructLitField_t));
                        vader_obj_header_init(_a18_obj, 466u);
                        _a18_obj->f_span = l8;
                        _a18_obj->f_id = (size_t) (int64_t) INT64_C(0);
                        _a18_obj->f_name = l12;
                        _a18_obj->f_name_span = l9;
                        _a18_obj->f_value = l4;
                        l11 = (void*) _a18_obj;
                        vader_array_push((vader_array_t*) l2, vader_ref_box(l11));
                    } else {
                        if (l3.tag == 467u) {
                            t0 = l3.payload.obj;
                            l16 = ((vader_struct_toolchain_ast_StructLitSpread_t*) t0)->f_span;
                            t0 = l3.payload.obj;
                            l14 = vader_resolver_substitute_expr_full(((vader_struct_toolchain_ast_StructLitSpread_t*) t0)->f_expr, l1);
                            vader_struct_toolchain_ast_StructLitSpread_t* _a19_obj = (vader_struct_toolchain_ast_StructLitSpread_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_StructLitSpread_t));
                            vader_obj_header_init(_a19_obj, 467u);
                            _a19_obj->f_span = l16;
                            _a19_obj->f_id = (size_t) (int64_t) INT64_C(0);
                            _a19_obj->f_expr = l14;
                            l17 = (void*) _a19_obj;
                            vader_array_push((vader_array_t*) l2, vader_ref_box(l17));
                        } else {
                            vader_unreachable("unreachable return in vader_resolver$substitute_expr_full");
                        }
                    }
                    t2 = (l7 + INT64_C(1));
                    l7 = (size_t) (int64_t) t2;
                    goto loop_459;
                }
            }
        }
        t0 = l0.payload.obj;
        l5 = ((vader_struct_toolchain_ast_StructLitExpr_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l3 = vader_resolver_substitute_type_expr(((vader_struct_toolchain_ast_StructLitExpr_t*) t0)->f_type_name, l1);
        vader_struct_toolchain_ast_StructLitExpr_t* _a20_obj = (vader_struct_toolchain_ast_StructLitExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_StructLitExpr_t));
        vader_obj_header_init(_a20_obj, 465u);
        _a20_obj->f_span = l5;
        _a20_obj->f_id = (size_t) (int64_t) INT64_C(0);
        _a20_obj->f_type_name = l3;
        _a20_obj->f_items = l2;
        _a20_obj->f_trailing_comma = false;
        t0 = (void*) _a20_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 458u) {
        vader_array_t* _a21_arr = vader_array_new(113u, 0u, 13u, 1039u);
        l2 = (void*) _a21_arr;
        t0 = l0.payload.obj;
        l5 = ((vader_struct_toolchain_ast_SeqLitExpr_t*) t0)->f_elements;
        l6 = ((vader_array_t*) l5)->length;
        l7 = (size_t) (int64_t) INT64_C(0);
        {
            loop_565: {
                if ((l7 < l6)) {
                    vader_array_t* _a22_slotarr = ((vader_array_t*) l5);
                    if (_a22_slotarr->buf != NULL && _a22_slotarr->buf->header.forward != NULL) { _a22_slotarr->buf = vader_array_buf_forward(_a22_slotarr->buf); }
                    if ((size_t) l7 >= _a22_slotarr->length) { vader_trap("array index out of bounds"); }
                    t1 = vader_array_ref_load_box(_a22_slotarr->buf, _a22_slotarr->offset + (size_t) l7);
                    l3 = vader_resolver_substitute_expr_full(t1, l1);
                    vader_array_push((vader_array_t*) l2, l3);
                    t2 = (l7 + INT64_C(1));
                    l7 = (size_t) (int64_t) t2;
                    goto loop_565;
                }
            }
        }
        t0 = l0.payload.obj;
        vader_struct_toolchain_ast_SeqLitExpr_t* _a23_obj = (vader_struct_toolchain_ast_SeqLitExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_SeqLitExpr_t));
        vader_obj_header_init(_a23_obj, 458u);
        _a23_obj->f_span = ((vader_struct_toolchain_ast_SeqLitExpr_t*) t0)->f_span;
        _a23_obj->f_id = (size_t) (int64_t) INT64_C(0);
        _a23_obj->f_elements = l2;
        _a23_obj->f_trailing_comma = false;
        t0 = (void*) _a23_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 454u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast_RangeExpr_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l10 = ((vader_struct_toolchain_ast_RangeExpr_t*) t0)->f_inclusive;
        t0 = l0.payload.obj;
        l3 = vader_resolver_substitute_expr_full(((vader_struct_toolchain_ast_RangeExpr_t*) t0)->f_lower, l1);
        t0 = l0.payload.obj;
        l4 = vader_resolver_substitute_expr_full(((vader_struct_toolchain_ast_RangeExpr_t*) t0)->f_upper, l1);
        vader_struct_toolchain_ast_RangeExpr_t* _a24_obj = (vader_struct_toolchain_ast_RangeExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_RangeExpr_t));
        vader_obj_header_init(_a24_obj, 454u);
        _a24_obj->f_span = l2;
        _a24_obj->f_id = (size_t) (int64_t) INT64_C(0);
        _a24_obj->f_inclusive = l10;
        _a24_obj->f_lower = l3;
        _a24_obj->f_upper = l4;
        t0 = (void*) _a24_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 395u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast_AwaitExpr_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l3 = vader_resolver_substitute_expr_full(((vader_struct_toolchain_ast_AwaitExpr_t*) t0)->f_inner, l1);
        vader_struct_toolchain_ast_AwaitExpr_t* _a25_obj = (vader_struct_toolchain_ast_AwaitExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_AwaitExpr_t));
        vader_obj_header_init(_a25_obj, 395u);
        _a25_obj->f_span = l2;
        _a25_obj->f_id = (size_t) (int64_t) INT64_C(0);
        _a25_obj->f_inner = l3;
        t0 = (void*) _a25_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 403u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast_CastExpr_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l3 = vader_resolver_substitute_type_expr(((vader_struct_toolchain_ast_CastExpr_t*) t0)->f_target, l1);
        t0 = l0.payload.obj;
        l4 = vader_resolver_substitute_expr_full(((vader_struct_toolchain_ast_CastExpr_t*) t0)->f_value, l1);
        vader_struct_toolchain_ast_CastExpr_t* _a26_obj = (vader_struct_toolchain_ast_CastExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_CastExpr_t));
        vader_obj_header_init(_a26_obj, 403u);
        _a26_obj->f_span = l2;
        _a26_obj->f_id = (size_t) (int64_t) INT64_C(0);
        _a26_obj->f_target = l3;
        _a26_obj->f_value = l4;
        t0 = (void*) _a26_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 437u) {
        vader_array_t* _a27_arr = vader_array_new(113u, 0u, 13u, 1039u);
        l2 = (void*) _a27_arr;
        t0 = l0.payload.obj;
        l5 = ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) t0)->f_args;
        l6 = ((vader_array_t*) l5)->length;
        l7 = (size_t) (int64_t) INT64_C(0);
        {
            loop_687: {
                if ((l7 < l6)) {
                    vader_array_t* _a28_slotarr = ((vader_array_t*) l5);
                    if (_a28_slotarr->buf != NULL && _a28_slotarr->buf->header.forward != NULL) { _a28_slotarr->buf = vader_array_buf_forward(_a28_slotarr->buf); }
                    if ((size_t) l7 >= _a28_slotarr->length) { vader_trap("array index out of bounds"); }
                    t1 = vader_array_ref_load_box(_a28_slotarr->buf, _a28_slotarr->offset + (size_t) l7);
                    l3 = vader_resolver_substitute_expr_full(t1, l1);
                    vader_array_push((vader_array_t*) l2, l3);
                    t2 = (l7 + INT64_C(1));
                    l7 = (size_t) (int64_t) t2;
                    goto loop_687;
                }
            }
        }
        t0 = l0.payload.obj;
        l5 = ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l12 = ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) t0)->f_name;
        t0 = l0.payload.obj;
        l8 = ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) t0)->f_name_span;
        vader_struct_toolchain_ast_IntrinsicCallExpr_t* _a29_obj = (vader_struct_toolchain_ast_IntrinsicCallExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_IntrinsicCallExpr_t));
        vader_obj_header_init(_a29_obj, 437u);
        _a29_obj->f_span = l5;
        _a29_obj->f_id = (size_t) (int64_t) INT64_C(0);
        _a29_obj->f_name = l12;
        _a29_obj->f_name_span = l8;
        _a29_obj->f_args = l2;
        _a29_obj->f_trailing_comma = false;
        t0 = (void*) _a29_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 414u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast_DotVariantExpr_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l12 = ((vader_struct_toolchain_ast_DotVariantExpr_t*) t0)->f_variant;
        t0 = l0.payload.obj;
        l5 = ((vader_struct_toolchain_ast_DotVariantExpr_t*) t0)->f_variant_span;
        vader_struct_toolchain_ast_DotVariantExpr_t* _a30_obj = (vader_struct_toolchain_ast_DotVariantExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_DotVariantExpr_t));
        vader_obj_header_init(_a30_obj, 414u);
        _a30_obj->f_span = l2;
        _a30_obj->f_id = (size_t) (int64_t) INT64_C(0);
        _a30_obj->f_variant = l12;
        _a30_obj->f_variant_span = l5;
        t0 = (void*) _a30_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 460u) {
        vader_array_t* _a31_arr = vader_array_new(119u, 0u, 13u, 1081u);
        l2 = (void*) _a31_arr;
        t0 = l0.payload.obj;
        l5 = ((vader_struct_toolchain_ast_StringLitExpr_t*) t0)->f_parts;
        l6 = ((vader_array_t*) l5)->length;
        l7 = (size_t) (int64_t) INT64_C(0);
        {
            loop_768: {
                if ((l7 < l6)) {
                    vader_array_t* _a32_slotarr = ((vader_array_t*) l5);
                    if (_a32_slotarr->buf != NULL && _a32_slotarr->buf->header.forward != NULL) { _a32_slotarr->buf = vader_array_buf_forward(_a32_slotarr->buf); }
                    if ((size_t) l7 >= _a32_slotarr->length) { vader_trap("array index out of bounds"); }
                    l3 = vader_array_ref_load_box(_a32_slotarr->buf, _a32_slotarr->offset + (size_t) l7);
                    if (l3.tag == 462u) {
                        t0 = l3.payload.obj;
                        l12 = ((vader_struct_toolchain_ast_StringLitText_t*) t0)->f_value;
                        t0 = l3.payload.obj;
                        l8 = ((vader_struct_toolchain_ast_StringLitText_t*) t0)->f_span;
                        vader_struct_toolchain_ast_StringLitText_t* _a33_obj = (vader_struct_toolchain_ast_StringLitText_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_StringLitText_t));
                        vader_obj_header_init(_a33_obj, 462u);
                        _a33_obj->f_value = l12;
                        _a33_obj->f_span = l8;
                        _a33_obj->f_id = (size_t) (int64_t) INT64_C(0);
                        l9 = (void*) _a33_obj;
                        vader_array_push((vader_array_t*) l2, vader_ref_box(l9));
                    } else {
                        if (l3.tag == 461u) {
                            t0 = l3.payload.obj;
                            l4 = vader_resolver_substitute_expr_full(((vader_struct_toolchain_ast_StringLitInterp_t*) t0)->f_expr, l1);
                            t0 = l3.payload.obj;
                            l11 = ((vader_struct_toolchain_ast_StringLitInterp_t*) t0)->f_span;
                            vader_struct_toolchain_ast_StringLitInterp_t* _a34_obj = (vader_struct_toolchain_ast_StringLitInterp_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_StringLitInterp_t));
                            vader_obj_header_init(_a34_obj, 461u);
                            _a34_obj->f_expr = l4;
                            _a34_obj->f_span = l11;
                            _a34_obj->f_id = (size_t) (int64_t) INT64_C(0);
                            l16 = (void*) _a34_obj;
                            vader_array_push((vader_array_t*) l2, vader_ref_box(l16));
                        } else {
                            vader_unreachable("unreachable return in vader_resolver$substitute_expr_full");
                        }
                    }
                    t2 = (l7 + INT64_C(1));
                    l7 = (size_t) (int64_t) t2;
                    goto loop_768;
                }
            }
        }
        t0 = l0.payload.obj;
        vader_struct_toolchain_ast_StringLitExpr_t* _a35_obj = (vader_struct_toolchain_ast_StringLitExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_StringLitExpr_t));
        vader_obj_header_init(_a35_obj, 460u);
        _a35_obj->f_span = ((vader_struct_toolchain_ast_StringLitExpr_t*) t0)->f_span;
        _a35_obj->f_id = (size_t) (int64_t) INT64_C(0);
        _a35_obj->f_parts = l2;
        t0 = (void*) _a35_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 439u) {
        vader_array_t* _a36_arr = vader_array_new(25u, 0u, 13u, 422u);
        l2 = (void*) _a36_arr;
        t0 = l0.payload.obj;
        l5 = ((vader_struct_toolchain_ast_LambdaExpr_t*) t0)->f_params;
        l6 = ((vader_array_t*) l5)->length;
        l7 = (size_t) (int64_t) INT64_C(0);
        {
            loop_852: {
                if ((l7 < l6)) {
                    vader_array_t* _a37_slotarr = ((vader_array_t*) l5);
                    if (_a37_slotarr->buf != NULL && _a37_slotarr->buf->header.forward != NULL) { _a37_slotarr->buf = vader_array_buf_forward(_a37_slotarr->buf); }
                    if ((size_t) l7 >= _a37_slotarr->length) { vader_trap("array index out of bounds"); }
                    l8 = vader_array_ref_load_obj(_a37_slotarr->buf, _a37_slotarr->offset + (size_t) l7);
                    l3 = vader_box_obj(0u, NULL);
                    if (!(((vader_struct_toolchain_ast_FnParam_t*) l8)->f_ty.tag == 0u)) {
                        l3 = vader_resolver_substitute_type_expr(((vader_struct_toolchain_ast_FnParam_t*) l8)->f_ty, l1);
                    }
                    l4 = vader_box_obj(0u, NULL);
                    if (!(((vader_struct_toolchain_ast_FnParam_t*) l8)->f_default_value.tag == 0u)) {
                        l4 = vader_resolver_substitute_expr_full(((vader_struct_toolchain_ast_FnParam_t*) l8)->f_default_value, l1);
                    }
                    l9 = ((vader_struct_toolchain_ast_FnParam_t*) l8)->f_span;
                    l12 = ((vader_struct_toolchain_ast_FnParam_t*) l8)->f_name;
                    l10 = ((vader_struct_toolchain_ast_FnParam_t*) l8)->f_variadic;
                    l15 = ((vader_struct_toolchain_ast_FnParam_t*) l8)->f_mutable;
                    l11 = ((vader_struct_toolchain_ast_FnParam_t*) l8)->f_decorators;
                    vader_struct_toolchain_ast_FnParam_t* _a38_obj = (vader_struct_toolchain_ast_FnParam_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_FnParam_t));
                    vader_obj_header_init(_a38_obj, 422u);
                    _a38_obj->f_span = l9;
                    _a38_obj->f_id = (size_t) (int64_t) INT64_C(0);
                    _a38_obj->f_name = l12;
                    _a38_obj->f_ty = l3;
                    _a38_obj->f_default_value = l4;
                    _a38_obj->f_variadic = l10;
                    _a38_obj->f_mutable = l15;
                    _a38_obj->f_decorators = l11;
                    l16 = (void*) _a38_obj;
                    vader_array_push((vader_array_t*) l2, vader_ref_box(l16));
                    t2 = (l7 + INT64_C(1));
                    l7 = (size_t) (int64_t) t2;
                    goto loop_852;
                }
            }
        }
        l3 = vader_box_obj(0u, NULL);
        t0 = l0.payload.obj;
        if (!(((vader_struct_toolchain_ast_LambdaExpr_t*) t0)->f_return_type.tag == 0u)) {
            t0 = l0.payload.obj;
            l3 = vader_resolver_substitute_type_expr(((vader_struct_toolchain_ast_LambdaExpr_t*) t0)->f_return_type, l1);
        }
        t0 = l0.payload.obj;
        l5 = ((vader_struct_toolchain_ast_LambdaExpr_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l8 = vader_resolver_substitute_block(((vader_struct_toolchain_ast_LambdaExpr_t*) t0)->f_body, l1);
        vader_struct_toolchain_ast_LambdaExpr_t* _a39_obj = (vader_struct_toolchain_ast_LambdaExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_LambdaExpr_t));
        vader_obj_header_init(_a39_obj, 439u);
        _a39_obj->f_span = l5;
        _a39_obj->f_id = (size_t) (int64_t) INT64_C(0);
        _a39_obj->f_params = l2;
        _a39_obj->f_return_type = l3;
        _a39_obj->f_body = l8;
        _a39_obj->f_trailing_comma = false;
        t0 = (void*) _a39_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_unreachable("unreachable return in vader_resolver$substitute_expr_full");
    vader_gc_top = gc_frame.prev;
}

static vader_box_t vader_resolver_substitute_opt_type(vader_box_t l0, void* l1) {
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l0, &t0 };
    void** gc_raw_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 0u) {
        t0 = vader_box_obj(0u, NULL);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_resolver_substitute_type_expr(l0, l1);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_resolver_substitute_params(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    size_t l4, l5;
    vader_string_t l8 = 0;
    vader_box_t l9 = vader_box_null(), l10 = vader_box_null();
    bool l11, l12;
    int64_t t0;
    vader_box_t* gc_roots[2] = { &l9, &l10 };
    void** gc_raw_roots[8] = { &l0, &l1, &l2, &l3, &l6, &l7, &l13, &l14 };
    vader_string_t* gc_atom_roots[1] = { &l8 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(25u, 0u, 13u, 422u);
    l2 = (void*) _a0_arr;
    l3 = l0;
    l4 = ((vader_array_t*) l3)->length;
    l5 = (size_t) (int64_t) INT64_C(0);
    {
        loop_9: {
            if ((l5 < l4)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l5 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                l6 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5);
                l7 = ((vader_struct_toolchain_ast_FnParam_t*) l6)->f_span;
                l8 = ((vader_struct_toolchain_ast_FnParam_t*) l6)->f_name;
                l9 = vader_resolver_substitute_opt_type(((vader_struct_toolchain_ast_FnParam_t*) l6)->f_ty, l1);
                l10 = ((vader_struct_toolchain_ast_FnParam_t*) l6)->f_default_value;
                l11 = ((vader_struct_toolchain_ast_FnParam_t*) l6)->f_variadic;
                l12 = ((vader_struct_toolchain_ast_FnParam_t*) l6)->f_mutable;
                l13 = ((vader_struct_toolchain_ast_FnParam_t*) l6)->f_decorators;
                vader_struct_toolchain_ast_FnParam_t* _a2_obj = (vader_struct_toolchain_ast_FnParam_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_FnParam_t));
                vader_obj_header_init(_a2_obj, 422u);
                _a2_obj->f_span = l7;
                _a2_obj->f_id = (size_t) (int64_t) INT64_C(0);
                _a2_obj->f_name = l8;
                _a2_obj->f_ty = l9;
                _a2_obj->f_default_value = l10;
                _a2_obj->f_variadic = l11;
                _a2_obj->f_mutable = l12;
                _a2_obj->f_decorators = l13;
                l14 = (void*) _a2_obj;
                vader_array_push((vader_array_t*) l2, vader_ref_box(l14));
                t0 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t0;
                goto loop_9;
            }
        }
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_resolver_substitute_params_disambiguated(void* l0, void* l1, void* l2, void* l3) {
    void* l4 = NULL;
    void* l5 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l15 = NULL;
    void* l16 = NULL;
    size_t l6, l7;
    vader_string_t l10 = 0;
    vader_box_t l11 = vader_box_null(), l12 = vader_box_null();
    bool l13, l14;
    vader_string_t t0 = 0;
    int64_t t1;
    vader_box_t* gc_roots[2] = { &l11, &l12 };
    void** gc_raw_roots[10] = { &l0, &l1, &l2, &l3, &l4, &l5, &l8, &l9, &l15, &l16 };
    vader_string_t* gc_atom_roots[2] = { &l10, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 10u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(25u, 0u, 13u, 422u);
    l4 = (void*) _a0_arr;
    l5 = l0;
    l6 = ((vader_array_t*) l5)->length;
    l7 = (size_t) (int64_t) INT64_C(0);
    {
        loop_9: {
            if ((l7 < l6)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l7 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                l8 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l7);
                t0 = ((vader_struct_toolchain_ast_FnParam_t*) l8)->f_name;
                if (t0 == 2006u) {
                    l9 = l2;
                } else {
                    l9 = vader_resolver_synth_clone_span(l3);
                }
                l10 = ((vader_struct_toolchain_ast_FnParam_t*) l8)->f_name;
                l11 = vader_resolver_substitute_opt_type(((vader_struct_toolchain_ast_FnParam_t*) l8)->f_ty, l1);
                l12 = ((vader_struct_toolchain_ast_FnParam_t*) l8)->f_default_value;
                l13 = ((vader_struct_toolchain_ast_FnParam_t*) l8)->f_variadic;
                l14 = ((vader_struct_toolchain_ast_FnParam_t*) l8)->f_mutable;
                l15 = ((vader_struct_toolchain_ast_FnParam_t*) l8)->f_decorators;
                vader_struct_toolchain_ast_FnParam_t* _a2_obj = (vader_struct_toolchain_ast_FnParam_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_FnParam_t));
                vader_obj_header_init(_a2_obj, 422u);
                _a2_obj->f_span = l9;
                _a2_obj->f_id = (size_t) (int64_t) INT64_C(0);
                _a2_obj->f_name = l10;
                _a2_obj->f_ty = l11;
                _a2_obj->f_default_value = l12;
                _a2_obj->f_variadic = l13;
                _a2_obj->f_mutable = l14;
                _a2_obj->f_decorators = l15;
                l16 = (void*) _a2_obj;
                vader_array_push((vader_array_t*) l4, vader_ref_box(l16));
                t1 = (l7 + INT64_C(1));
                l7 = (size_t) (int64_t) t1;
                goto loop_9;
            }
        }
    }
    { void* __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_resolver_substitute_params_stamped(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l14 = NULL;
    void* l15 = NULL;
    size_t l5, l6;
    vader_string_t l9 = 0;
    vader_box_t l10 = vader_box_null(), l11 = vader_box_null();
    bool l12, l13;
    int64_t t0;
    vader_box_t* gc_roots[2] = { &l10, &l11 };
    void** gc_raw_roots[9] = { &l0, &l1, &l2, &l3, &l4, &l7, &l8, &l14, &l15 };
    vader_string_t* gc_atom_roots[1] = { &l9 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 9u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(25u, 0u, 13u, 422u);
    l3 = (void*) _a0_arr;
    l4 = l0;
    l5 = ((vader_array_t*) l4)->length;
    l6 = (size_t) (int64_t) INT64_C(0);
    {
        loop_9: {
            if ((l6 < l5)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) l4);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l6 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                l7 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l6);
                l8 = vader_resolver_next_clone_span(l2);
                l9 = ((vader_struct_toolchain_ast_FnParam_t*) l7)->f_name;
                l10 = vader_resolver_substitute_opt_type(((vader_struct_toolchain_ast_FnParam_t*) l7)->f_ty, l1);
                l11 = ((vader_struct_toolchain_ast_FnParam_t*) l7)->f_default_value;
                l12 = ((vader_struct_toolchain_ast_FnParam_t*) l7)->f_variadic;
                l13 = ((vader_struct_toolchain_ast_FnParam_t*) l7)->f_mutable;
                l14 = ((vader_struct_toolchain_ast_FnParam_t*) l7)->f_decorators;
                vader_struct_toolchain_ast_FnParam_t* _a2_obj = (vader_struct_toolchain_ast_FnParam_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_FnParam_t));
                vader_obj_header_init(_a2_obj, 422u);
                _a2_obj->f_span = l8;
                _a2_obj->f_id = (size_t) (int64_t) INT64_C(0);
                _a2_obj->f_name = l9;
                _a2_obj->f_ty = l10;
                _a2_obj->f_default_value = l11;
                _a2_obj->f_variadic = l12;
                _a2_obj->f_mutable = l13;
                _a2_obj->f_decorators = l14;
                l15 = (void*) _a2_obj;
                vader_array_push((vader_array_t*) l3, vader_ref_box(l15));
                t0 = (l6 + INT64_C(1));
                l6 = (size_t) (int64_t) t0;
                goto loop_9;
            }
        }
    }
    { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_box_t vader_resolver_substitute_pattern(vader_box_t l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l4 = vader_box_null(), l5 = vader_box_null();
    void* l3 = NULL;
    void* t0 = NULL;
    vader_box_t* gc_roots[4] = { &l0, &l2, &l4, &l5 };
    void** gc_raw_roots[3] = { &l1, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 438u) {
        l2 = vader_box_obj(0u, NULL);
        t0 = l0.payload.obj;
        if (!(((vader_struct_toolchain_ast_IsPattern_t*) t0)->f_inner.tag == 0u)) {
            t0 = l0.payload.obj;
            l2 = vader_resolver_substitute_pattern(((vader_struct_toolchain_ast_IsPattern_t*) t0)->f_inner, l1);
        }
        t0 = l0.payload.obj;
        l3 = ((vader_struct_toolchain_ast_IsPattern_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l4 = vader_resolver_substitute_type_expr(((vader_struct_toolchain_ast_IsPattern_t*) t0)->f_ty, l1);
        t0 = l0.payload.obj;
        l5 = ((vader_struct_toolchain_ast_IsPattern_t*) t0)->f_bind_as;
        vader_struct_toolchain_ast_IsPattern_t* _a0_obj = (vader_struct_toolchain_ast_IsPattern_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_IsPattern_t));
        vader_obj_header_init(_a0_obj, 438u);
        _a0_obj->f_span = l3;
        _a0_obj->f_id = (size_t) (int64_t) INT64_C(0);
        _a0_obj->f_ty = l4;
        _a0_obj->f_inner = l2;
        _a0_obj->f_bind_as = l5;
        t0 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_box_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_box_t vader_resolver_substitute_stmt(vader_box_t l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l5 = vader_box_null(), l6 = vader_box_null(), l7 = vader_box_null();
    void* l3 = NULL;
    void* l8 = NULL;
    bool l4;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[6] = { &l0, &l2, &l5, &l6, &l7, &t1 };
    void** gc_raw_roots[4] = { &l1, &l3, &l8, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 6u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 440u) {
        l2 = vader_box_obj(0u, NULL);
        t0 = l0.payload.obj;
        if (!(((vader_struct_toolchain_ast_LetStmt_t*) t0)->f_ty.tag == 0u)) {
            t0 = l0.payload.obj;
            l2 = vader_resolver_substitute_type_expr(((vader_struct_toolchain_ast_LetStmt_t*) t0)->f_ty, l1);
        }
        t0 = l0.payload.obj;
        l3 = ((vader_struct_toolchain_ast_LetStmt_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_toolchain_ast_LetStmt_t*) t0)->f_mutable;
        t0 = l0.payload.obj;
        l5 = vader_resolver_clone_let_binding(((vader_struct_toolchain_ast_LetStmt_t*) t0)->f_binding);
        t0 = l0.payload.obj;
        l6 = vader_resolver_substitute_expr_full(((vader_struct_toolchain_ast_LetStmt_t*) t0)->f_value, l1);
        vader_struct_toolchain_ast_LetStmt_t* _a0_obj = (vader_struct_toolchain_ast_LetStmt_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_LetStmt_t));
        vader_obj_header_init(_a0_obj, 440u);
        _a0_obj->f_span = l3;
        _a0_obj->f_id = (size_t) (int64_t) INT64_C(0);
        _a0_obj->f_mutable = l4;
        _a0_obj->f_binding = l5;
        _a0_obj->f_ty = l2;
        _a0_obj->f_value = l6;
        t0 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 418u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_toolchain_ast_ExprStmt_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l2 = vader_resolver_substitute_expr_full(((vader_struct_toolchain_ast_ExprStmt_t*) t0)->f_expr, l1);
        vader_struct_toolchain_ast_ExprStmt_t* _a1_obj = (vader_struct_toolchain_ast_ExprStmt_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_ExprStmt_t));
        vader_obj_header_init(_a1_obj, 418u);
        _a1_obj->f_span = l3;
        _a1_obj->f_id = (size_t) (int64_t) INT64_C(0);
        _a1_obj->f_expr = l2;
        t0 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 457u) {
        l2 = vader_box_obj(0u, NULL);
        t0 = l0.payload.obj;
        if (!(((vader_struct_toolchain_ast_ReturnStmt_t*) t0)->f_value.tag == 0u)) {
            t0 = l0.payload.obj;
            l2 = vader_resolver_substitute_expr_full(((vader_struct_toolchain_ast_ReturnStmt_t*) t0)->f_value, l1);
        }
        t0 = l0.payload.obj;
        vader_struct_toolchain_ast_ReturnStmt_t* _a2_obj = (vader_struct_toolchain_ast_ReturnStmt_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_ReturnStmt_t));
        vader_obj_header_init(_a2_obj, 457u);
        _a2_obj->f_span = ((vader_struct_toolchain_ast_ReturnStmt_t*) t0)->f_span;
        _a2_obj->f_id = (size_t) (int64_t) INT64_C(0);
        _a2_obj->f_value = l2;
        t0 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 394u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_toolchain_ast_AssignStmt_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l2 = vader_resolver_substitute_expr_full(((vader_struct_toolchain_ast_AssignStmt_t*) t0)->f_target, l1);
        t0 = l0.payload.obj;
        l5 = vader_resolver_substitute_expr_full(((vader_struct_toolchain_ast_AssignStmt_t*) t0)->f_value, l1);
        vader_struct_toolchain_ast_AssignStmt_t* _a3_obj = (vader_struct_toolchain_ast_AssignStmt_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_AssignStmt_t));
        vader_obj_header_init(_a3_obj, 394u);
        _a3_obj->f_span = l3;
        _a3_obj->f_id = (size_t) (int64_t) INT64_C(0);
        _a3_obj->f_target = l2;
        _a3_obj->f_value = l5;
        t0 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 424u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast_ForStmt_t*) t0)->f_form;
        t0 = l0.payload.obj;
        l5 = ((vader_struct_toolchain_ast_ForStmt_t*) t0)->f_form;
        if (l5.tag == 476u) {
            t0 = l5.payload.obj;
            t1 = vader_resolver_substitute_expr_full(((vader_struct_toolchain_ast_WhileFor_t*) t0)->f_cond, l1);
            vader_struct_toolchain_ast_WhileFor_t* _a4_obj = (vader_struct_toolchain_ast_WhileFor_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_WhileFor_t));
            vader_obj_header_init(_a4_obj, 476u);
            _a4_obj->f_cond = t1;
            t0 = (void*) _a4_obj;
            l2 = vader_ref_box(t0);
        } else {
            if (l5.tag == 433u) {
                l3 = l5.payload.obj;
                l6 = ((vader_struct_toolchain_ast_InFor_t*) l3)->f_loop_var;
                l7 = vader_resolver_substitute_expr_full(((vader_struct_toolchain_ast_InFor_t*) l3)->f_iter, l1);
                vader_struct_toolchain_ast_InFor_t* _a5_obj = (vader_struct_toolchain_ast_InFor_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_InFor_t));
                vader_obj_header_init(_a5_obj, 433u);
                _a5_obj->f_loop_var = l6;
                _a5_obj->f_iter = l7;
                t0 = (void*) _a5_obj;
                l2 = vader_ref_box(t0);
            } else {
                if (l5.tag == 435u) {
                } else {
                    vader_unreachable("unreachable return in vader_resolver$substitute_stmt");
                }
            }
        }
        t0 = l0.payload.obj;
        l3 = ((vader_struct_toolchain_ast_ForStmt_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l5 = ((vader_struct_toolchain_ast_ForStmt_t*) t0)->f_label;
        t0 = l0.payload.obj;
        l8 = vader_resolver_substitute_block(((vader_struct_toolchain_ast_ForStmt_t*) t0)->f_body, l1);
        t0 = l0.payload.obj;
        l4 = ((vader_struct_toolchain_ast_ForStmt_t*) t0)->f_is_comptime;
        vader_struct_toolchain_ast_ForStmt_t* _a6_obj = (vader_struct_toolchain_ast_ForStmt_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_ForStmt_t));
        vader_obj_header_init(_a6_obj, 424u);
        _a6_obj->f_span = l3;
        _a6_obj->f_id = (size_t) (int64_t) INT64_C(0);
        _a6_obj->f_label = l5;
        _a6_obj->f_form = l2;
        _a6_obj->f_body = l8;
        _a6_obj->f_is_comptime = l4;
        t0 = (void*) _a6_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 400u) {
        t0 = l0.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 406u) {
        t0 = l0.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_box_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_box_t vader_resolver_substitute_type_expr(vader_box_t l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l6 = vader_box_null();
    vader_string_t l3 = 0;
    void* l4 = NULL;
    void* l7 = NULL;
    void* l10 = NULL;
    uint8_t l5;
    size_t l8, l9;
    void* t0 = NULL;
    void* t1 = NULL;
    vader_box_t t2 = vader_box_null();
    int64_t t3;
    vader_box_t* gc_roots[4] = { &l0, &l2, &l6, &t2 };
    void** gc_raw_roots[6] = { &l1, &l4, &l7, &l10, &t0, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    if (l0.tag == 426u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_toolchain_ast_IdentExpr_t*) t0)->f_name;
        l2 = vader_resolver_lookup_subst(l1, l3);
        if (l2.tag == 0u) {
            t0 = l0.payload.obj;
            t1 = vader_resolver_clone_ident(t0);
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l4 = vader_resolver_new_subst();
        t2 = vader_resolver_substitute_type_expr(l2, l4);
        { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 396u) {
        t0 = l0.payload.obj;
        l4 = ((vader_struct_toolchain_ast_BinaryExpr_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l5 = ((vader_struct_toolchain_ast_BinaryExpr_t*) t0)->f_op;
        t0 = l0.payload.obj;
        l2 = vader_resolver_substitute_type_expr(((vader_struct_toolchain_ast_BinaryExpr_t*) t0)->f_left, l1);
        t0 = l0.payload.obj;
        l6 = vader_resolver_substitute_type_expr(((vader_struct_toolchain_ast_BinaryExpr_t*) t0)->f_right, l1);
        t0 = l0.payload.obj;
        l3 = ((vader_struct_toolchain_ast_BinaryExpr_t*) t0)->f_bind_as;
        vader_struct_toolchain_ast_BinaryExpr_t* _a0_obj = (vader_struct_toolchain_ast_BinaryExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_BinaryExpr_t));
        vader_obj_header_init(_a0_obj, 396u);
        _a0_obj->f_span = l4;
        _a0_obj->f_id = (size_t) (int64_t) INT64_C(0);
        _a0_obj->f_op = l5;
        _a0_obj->f_left = l2;
        _a0_obj->f_right = l6;
        _a0_obj->f_bind_as = l3;
        t0 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 423u) {
        vader_array_t* _a1_arr = vader_array_new(113u, 0u, 13u, 1039u);
        l4 = (void*) _a1_arr;
        t0 = l0.payload.obj;
        l7 = ((vader_struct_toolchain_ast_FnTypeExpr_t*) t0)->f_params;
        l8 = ((vader_array_t*) l7)->length;
        l9 = (size_t) (int64_t) INT64_C(0);
        {
            loop_77: {
                if ((l9 < l8)) {
                    vader_array_t* _a2_slotarr = ((vader_array_t*) l7);
                    if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                    if ((size_t) l9 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                    t2 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l9);
                    l2 = vader_resolver_substitute_type_expr(t2, l1);
                    vader_array_push((vader_array_t*) l4, l2);
                    t3 = (l9 + INT64_C(1));
                    l9 = (size_t) (int64_t) t3;
                    goto loop_77;
                }
            }
        }
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast_FnTypeExpr_t*) t0)->f_return_type;
        l6 = vader_box_obj(0u, NULL);
        if (!(l2.tag == 0u)) {
            l6 = vader_resolver_substitute_type_expr(l2, l1);
        }
        t0 = l0.payload.obj;
        l7 = ((vader_struct_toolchain_ast_FnTypeExpr_t*) t0)->f_span;
        vader_array_t* _a3_arr = vader_array_new(6u, 0u, 12u, 167u);
        l10 = (void*) _a3_arr;
        vader_struct_toolchain_ast_FnTypeExpr_t* _a4_obj = (vader_struct_toolchain_ast_FnTypeExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_FnTypeExpr_t));
        vader_obj_header_init(_a4_obj, 423u);
        _a4_obj->f_span = l7;
        _a4_obj->f_id = (size_t) (int64_t) INT64_C(0);
        _a4_obj->f_params = l4;
        _a4_obj->f_params_mutable = l10;
        _a4_obj->f_return_type = l6;
        t0 = (void*) _a4_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 392u) {
        t0 = l0.payload.obj;
        l4 = ((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l2 = vader_resolver_substitute_type_expr(((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t0)->f_element, l1);
        vader_struct_toolchain_ast_ArrayTypeExpr_t* _a5_obj = (vader_struct_toolchain_ast_ArrayTypeExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_ArrayTypeExpr_t));
        vader_obj_header_init(_a5_obj, 392u);
        _a5_obj->f_span = l4;
        _a5_obj->f_id = (size_t) (int64_t) INT64_C(0);
        _a5_obj->f_element = l2;
        t0 = (void*) _a5_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 445u) {
        t0 = l0.payload.obj;
        l4 = ((vader_struct_toolchain_ast_MutableTypeExpr_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l2 = vader_resolver_substitute_type_expr(((vader_struct_toolchain_ast_MutableTypeExpr_t*) t0)->f_inner, l1);
        vader_struct_toolchain_ast_MutableTypeExpr_t* _a6_obj = (vader_struct_toolchain_ast_MutableTypeExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_MutableTypeExpr_t));
        vader_obj_header_init(_a6_obj, 445u);
        _a6_obj->f_span = l4;
        _a6_obj->f_id = (size_t) (int64_t) INT64_C(0);
        _a6_obj->f_inner = l2;
        t0 = (void*) _a6_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 458u) {
        vader_array_t* _a7_arr = vader_array_new(113u, 0u, 13u, 1039u);
        l4 = (void*) _a7_arr;
        t0 = l0.payload.obj;
        l7 = ((vader_struct_toolchain_ast_SeqLitExpr_t*) t0)->f_elements;
        l8 = ((vader_array_t*) l7)->length;
        l9 = (size_t) (int64_t) INT64_C(0);
        {
            loop_180: {
                if ((l9 < l8)) {
                    vader_array_t* _a8_slotarr = ((vader_array_t*) l7);
                    if (_a8_slotarr->buf != NULL && _a8_slotarr->buf->header.forward != NULL) { _a8_slotarr->buf = vader_array_buf_forward(_a8_slotarr->buf); }
                    if ((size_t) l9 >= _a8_slotarr->length) { vader_trap("array index out of bounds"); }
                    t2 = vader_array_ref_load_box(_a8_slotarr->buf, _a8_slotarr->offset + (size_t) l9);
                    l2 = vader_resolver_substitute_type_expr(t2, l1);
                    vader_array_push((vader_array_t*) l4, l2);
                    t3 = (l9 + INT64_C(1));
                    l9 = (size_t) (int64_t) t3;
                    goto loop_180;
                }
            }
        }
        t0 = l0.payload.obj;
        vader_struct_toolchain_ast_SeqLitExpr_t* _a9_obj = (vader_struct_toolchain_ast_SeqLitExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_SeqLitExpr_t));
        vader_obj_header_init(_a9_obj, 458u);
        _a9_obj->f_span = ((vader_struct_toolchain_ast_SeqLitExpr_t*) t0)->f_span;
        _a9_obj->f_id = (size_t) (int64_t) INT64_C(0);
        _a9_obj->f_elements = l4;
        _a9_obj->f_trailing_comma = false;
        t0 = (void*) _a9_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 425u) {
        vader_array_t* _a10_arr = vader_array_new(113u, 0u, 13u, 1039u);
        l4 = (void*) _a10_arr;
        t0 = l0.payload.obj;
        l7 = ((vader_struct_toolchain_ast_GenericInstExpr_t*) t0)->f_type_args;
        l8 = ((vader_array_t*) l7)->length;
        l9 = (size_t) (int64_t) INT64_C(0);
        {
            loop_225: {
                if ((l9 < l8)) {
                    vader_array_t* _a11_slotarr = ((vader_array_t*) l7);
                    if (_a11_slotarr->buf != NULL && _a11_slotarr->buf->header.forward != NULL) { _a11_slotarr->buf = vader_array_buf_forward(_a11_slotarr->buf); }
                    if ((size_t) l9 >= _a11_slotarr->length) { vader_trap("array index out of bounds"); }
                    t2 = vader_array_ref_load_box(_a11_slotarr->buf, _a11_slotarr->offset + (size_t) l9);
                    l2 = vader_resolver_substitute_type_expr(t2, l1);
                    vader_array_push((vader_array_t*) l4, l2);
                    t3 = (l9 + INT64_C(1));
                    l9 = (size_t) (int64_t) t3;
                    goto loop_225;
                }
            }
        }
        t0 = l0.payload.obj;
        l7 = ((vader_struct_toolchain_ast_GenericInstExpr_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast_GenericInstExpr_t*) t0)->f_callee;
        vader_struct_toolchain_ast_GenericInstExpr_t* _a12_obj = (vader_struct_toolchain_ast_GenericInstExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_GenericInstExpr_t));
        vader_obj_header_init(_a12_obj, 425u);
        _a12_obj->f_span = l7;
        _a12_obj->f_id = (size_t) (int64_t) INT64_C(0);
        _a12_obj->f_callee = l2;
        _a12_obj->f_type_args = l4;
        t0 = (void*) _a12_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_box_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_resolver_synth_clone_span(void* l0) {
    int32_t l1;
    void* l2 = NULL;
    size_t t0;
    void* t1 = NULL;
    void** gc_raw_roots[3] = { &l0, &l2, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_parser_mint(l0);
    l1 = ((int32_t) (size_t) t0);
    vader_struct_toolchain_span_Position_t* _a0_obj = (vader_struct_toolchain_span_Position_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Position_t));
    vader_obj_header_init(_a0_obj, 481u);
    _a0_obj->f_file = 0u;
    _a0_obj->f_offset = (size_t) (int64_t) INT64_C(0);
    _a0_obj->f_line = INT32_C(0);
    _a0_obj->f_column = l1;
    l2 = (void*) _a0_obj;
    vader_struct_toolchain_span_Span_t* _a1_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
    vader_obj_header_init(_a1_obj, 482u);
    _a1_obj->f_start = l2;
    _a1_obj->f_end = l2;
    t1 = (void*) _a1_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_resolver_synth_signature(void* l0, void* l1, void* l2, void* l3) {
    void* l4 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    vader_string_t l5 = 0;
    vader_box_t l8 = vader_box_null();
    bool l9;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l8 };
    void** gc_raw_roots[8] = { &l0, &l1, &l2, &l3, &l4, &l6, &l7, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l4 = ((vader_struct_toolchain_ast_FnDecl_t*) l0)->f_span;
    l5 = ((vader_struct_toolchain_ast_FnDecl_t*) l0)->f_name;
    vader_array_t* _a0_arr = vader_array_new(34u, 0u, 13u, 474u);
    l6 = (void*) _a0_arr;
    l7 = vader_resolver_substitute_params(((vader_struct_toolchain_ast_FnDecl_t*) l0)->f_params, l2);
    l8 = vader_resolver_substitute_opt_type(((vader_struct_toolchain_ast_FnDecl_t*) l0)->f_return_type, l2);
    l9 = ((vader_struct_toolchain_ast_FnDecl_t*) l0)->f_is_expression_bodied;
    vader_struct_toolchain_ast_FnDecl_t* _a1_obj = (vader_struct_toolchain_ast_FnDecl_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_FnDecl_t));
    vader_obj_header_init(_a1_obj, 421u);
    _a1_obj->f_span = l4;
    _a1_obj->f_id = (size_t) (int64_t) INT64_C(0);
    _a1_obj->f_name = l5;
    _a1_obj->f_name_span = l1;
    _a1_obj->f_visibility = (uint8_t) (int32_t) INT32_C(0);
    _a1_obj->f_type_params = l6;
    _a1_obj->f_params = l7;
    _a1_obj->f_return_type = l8;
    _a1_obj->f_body = vader_box_obj(0u, NULL);
    _a1_obj->f_decorators = l3;
    _a1_obj->f_sam_synthetic = false;
    _a1_obj->f_is_expression_bodied = l9;
    _a1_obj->f_materialized = true;
    _a1_obj->f_comptime_synthetic = false;
    _a1_obj->f_trailing_comma = false;
    t0 = (void*) _a1_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_resolver_synth_with_body(void* l0, void* l1, void* l2, void* l3, void* l4) {
    void* l5 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    vader_string_t l6 = 0;
    vader_box_t l10 = vader_box_null();
    bool l11;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l10 };
    void** gc_raw_roots[10] = { &l0, &l1, &l2, &l3, &l4, &l5, &l7, &l8, &l9, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l6 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 10u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l5 = ((vader_struct_toolchain_ast_FnDecl_t*) l0)->f_span;
    l6 = ((vader_struct_toolchain_ast_FnDecl_t*) l0)->f_name;
    l7 = ((vader_struct_toolchain_ast_FnDecl_t*) l0)->f_name_span;
    vader_array_t* _a0_arr = vader_array_new(34u, 0u, 13u, 474u);
    l8 = (void*) _a0_arr;
    l9 = vader_resolver_substitute_params_stamped(((vader_struct_toolchain_ast_FnDecl_t*) l0)->f_params, l1, l4);
    l10 = vader_resolver_substitute_opt_type(((vader_struct_toolchain_ast_FnDecl_t*) l0)->f_return_type, l1);
    l11 = ((vader_struct_toolchain_ast_FnDecl_t*) l0)->f_is_expression_bodied;
    vader_struct_toolchain_ast_FnDecl_t* _a1_obj = (vader_struct_toolchain_ast_FnDecl_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_FnDecl_t));
    vader_obj_header_init(_a1_obj, 421u);
    _a1_obj->f_span = l5;
    _a1_obj->f_id = (size_t) (int64_t) INT64_C(0);
    _a1_obj->f_name = l6;
    _a1_obj->f_name_span = l7;
    _a1_obj->f_visibility = (uint8_t) (int32_t) INT32_C(0);
    _a1_obj->f_type_params = l8;
    _a1_obj->f_params = l9;
    _a1_obj->f_return_type = l10;
    _a1_obj->f_body = vader_ref_box(l3);
    _a1_obj->f_decorators = l2;
    _a1_obj->f_sam_synthetic = false;
    _a1_obj->f_is_expression_bodied = l11;
    _a1_obj->f_materialized = true;
    _a1_obj->f_comptime_synthetic = false;
    _a1_obj->f_trailing_comma = false;
    t0 = (void*) _a1_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_box_t vader_resolver_target_selectors(void* l0) {
    void* l1 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    size_t l2, l3, l7, l8;
    vader_box_t l9 = vader_box_null(), l10 = vader_box_null();
    uint8_t l11;
    bool l12;
    vader_string_t t0 = 0;
    vader_string_t t3 = 0;
    int64_t t1;
    void* t2 = NULL;
    size_t t4;
    vader_box_t t5 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l9, &l10, &t5 };
    void** gc_raw_roots[6] = { &l0, &l1, &l4, &l5, &l6, &t2 };
    vader_string_t* gc_atom_roots[2] = { &t0, &t3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l1 = l0;
    l2 = ((vader_array_t*) l1)->length;
    l3 = (size_t) (int64_t) INT64_C(0);
    {
        loop_7: {
            if ((l3 < l2)) {
                vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
                if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                l4 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
                t0 = ((vader_struct_toolchain_ast_Decorator_t*) l4)->f_name;
                if (t0 != 2143u) {
                    t1 = (l3 + INT64_C(1));
                    l3 = (size_t) (int64_t) t1;
                    goto loop_7;
                }
                vader_array_t* _a1_arr = vader_array_new(11u, 0u, 1u, 175u);
                l5 = (void*) _a1_arr;
                l6 = ((vader_struct_toolchain_ast_Decorator_t*) l4)->f_args;
                l7 = ((vader_array_t*) l6)->length;
                l8 = (size_t) (int64_t) INT64_C(0);
                {
                    loop_36: {
                        if ((l8 < l7)) {
                            vader_array_t* _a2_slotarr = ((vader_array_t*) l6);
                            if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                            if ((size_t) l8 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                            l9 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l8);
                            if (l9.tag == 414u) {
                                t2 = l9.payload.obj;
                                t0 = ((vader_struct_toolchain_ast_DotVariantExpr_t*) t2)->f_variant;
                                t3 = std_string_to_lower(t0);
                                l10 = vader_target_parse_os(t3);
                                if (!(l10.tag == 0u)) {
                                    l11 = ((uint8_t) l10.payload.i);
                                    vader_array_push_u8((vader_array_t*) l5, (int32_t) (uint8_t) l11);
                                }
                            }
                            t1 = (l8 + INT64_C(1));
                            l8 = (size_t) (int64_t) t1;
                            goto loop_36;
                        }
                    }
                }
                t4 = ((vader_array_t*) ((vader_struct_toolchain_ast_Decorator_t*) l4)->f_args)->length;
                l12 = t4 == INT64_C(0);
                vader_struct_vader_resolver_TargetSelectors_t* _a3_obj = (vader_struct_vader_resolver_TargetSelectors_t*) vader_gc_alloc(sizeof(vader_struct_vader_resolver_TargetSelectors_t));
                vader_obj_header_init(_a3_obj, 888u);
                _a3_obj->f_os = l5;
                _a3_obj->f_is_bare = l12;
                t2 = (void*) _a3_obj;
                { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
            }
        }
    }
    t5 = vader_box_obj(0u, NULL);
    { vader_box_t __vret = t5; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_box_t vader_resolver_try_read(vader_string_t l0) {
    vader_box_t l1 = vader_box_null();
    vader_string_t t0 = 0;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l1, &t1 };
    vader_string_t* gc_atom_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 0u, gc_roots, NULL, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l1 = std_io_read_file_string(l0, (size_t) (int64_t) INT64_C(16777216));
    if (l1.tag == 169u) {
        t0 = l1.payload.s;
        t1 = vader_box_string(169u, t0);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_box_obj(0u, NULL);
    { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void vader_resolver_walk_block(void* l0, void* l1) {
    void* l2 = NULL;
    size_t l3, l4;
    vader_box_t l5 = vader_box_null();
    int64_t t0;
    vader_box_t* gc_roots[1] = { &l5 };
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_resolver_push(((vader_struct_vader_resolver_ResolveState_t*) l0)->f_scope);
    l2 = ((vader_struct_toolchain_ast_BlockExpr_t*) l1)->f_stmts;
    l3 = ((vader_array_t*) l2)->length;
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_9: {
            if ((l4 < l3)) {
                vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
                if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                if ((size_t) l4 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                l5 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
                vader_resolver_walk_stmt(l0, l5);
                t0 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                goto loop_9;
            }
        }
    }
    l5 = ((vader_struct_toolchain_ast_BlockExpr_t*) l1)->f_trailing;
    vader_resolver_walk_opt_expr(l0, l5);
    vader_resolver_pop(((vader_struct_vader_resolver_ResolveState_t*) l0)->f_scope);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_resolver_walk_decl(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    void* l5 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    size_t l3, l4;
    vader_string_t l6 = 0;
    vader_string_t l10 = 0;
    vader_box_t l11 = vader_box_null();
    void* t0 = NULL;
    int64_t t1;
    vader_box_t* gc_roots[2] = { &l1, &l11 };
    void** gc_raw_roots[7] = { &l0, &l2, &l5, &l7, &l8, &l9, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l6, &l10 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    if (l1.tag == 431u) {
    } else {
        if (l1.tag == 421u) {
            l2 = l1.payload.obj;
            vader_resolver_walk_fn_decl(l0, l2);
        } else {
            if (l1.tag == 463u) {
                l2 = l1.payload.obj;
                vader_resolver_walk_struct_decl(l0, l2);
            } else {
                if (l1.tag == 415u) {
                } else {
                    if (l1.tag == 470u) {
                        l2 = l1.payload.obj;
                        vader_resolver_walk_trait_decl(l0, l2);
                    } else {
                        if (l1.tag == 430u) {
                            l2 = l1.payload.obj;
                            vader_resolver_walk_impl_decl(l0, l2);
                        } else {
                            if (l1.tag == 473u) {
                                vader_resolver_push(((vader_struct_vader_resolver_ResolveState_t*) l0)->f_scope);
                                t0 = l1.payload.obj;
                                l2 = ((vader_struct_toolchain_ast_TypeAliasDecl_t*) t0)->f_type_params;
                                l3 = ((vader_array_t*) l2)->length;
                                l4 = (size_t) (int64_t) INT64_C(0);
                                {
                                    loop_62: {
                                        if ((l4 < l3)) {
                                            vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
                                            if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                                            if ((size_t) l4 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                                            l5 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
                                            l6 = ((vader_struct_toolchain_ast_TypeParam_t*) l5)->f_name;
                                            l7 = ((vader_struct_toolchain_ast_TypeParam_t*) l5)->f_span;
                                            l8 = vader_resolver_mint_local(l0, INT32_C(9), l6, l7);
                                            l9 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_scope;
                                            l10 = ((vader_struct_toolchain_ast_TypeParam_t*) l5)->f_name;
                                            vader_resolver_bind(l9, l10, l8);
                                            l11 = ((vader_struct_toolchain_ast_TypeParam_t*) l5)->f_bound;
                                            vader_resolver_walk_opt_expr(l0, l11);
                                            t1 = (l4 + INT64_C(1));
                                            l4 = (size_t) (int64_t) t1;
                                            goto loop_62;
                                        }
                                    }
                                }
                                t0 = l1.payload.obj;
                                l11 = ((vader_struct_toolchain_ast_TypeAliasDecl_t*) t0)->f_aliased;
                                vader_resolver_walk_opt_expr(l0, l11);
                                vader_resolver_pop(((vader_struct_vader_resolver_ResolveState_t*) l0)->f_scope);
                            } else {
                                if (l1.tag == 405u) {
                                    t0 = l1.payload.obj;
                                    l11 = ((vader_struct_toolchain_ast_ConstDecl_t*) t0)->f_ty;
                                    vader_resolver_walk_opt_expr(l0, l11);
                                    t0 = l1.payload.obj;
                                    l11 = ((vader_struct_toolchain_ast_ConstDecl_t*) t0)->f_value;
                                    vader_resolver_walk_expr(l0, l11);
                                } else {
                                    if (l1.tag == 393u) {
                                        t0 = l1.payload.obj;
                                        l11 = ((vader_struct_toolchain_ast_AssertDecl_t*) t0)->f_condition;
                                        vader_resolver_walk_expr(l0, l11);
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
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_resolver_walk_decorators(void* l0, void* l1) {
    void* l2 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    size_t l3, l4, l12, l13;
    vader_string_t l8 = 0;
    vader_string_t l9 = 0;
    vader_box_t l14 = vader_box_null();
    vader_string_t t0 = 0;
    bool t1;
    int64_t t2;
    vader_box_t* gc_roots[1] = { &l14 };
    void** gc_raw_roots[8] = { &l0, &l1, &l2, &l5, &l6, &l7, &l10, &l11 };
    vader_string_t* gc_atom_roots[3] = { &l8, &l9, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = l1;
    l3 = ((vader_array_t*) l2)->length;
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_7: {
            if ((l4 < l3)) {
                vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
                if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                if ((size_t) l4 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                l5 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
                t0 = ((vader_struct_toolchain_ast_Decorator_t*) l5)->f_name;
                t1 = vader_resolver_is_known_decorator(t0);
                if (!(t1)) {
                    l6 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_diags;
                    l7 = ((vader_struct_toolchain_ast_Decorator_t*) l5)->f_span;
                    l8 = ((vader_struct_toolchain_ast_Decorator_t*) l5)->f_name;
                    l9 = concat_3(1085u, l8, 930u);
                    l10 = vader_diagnostics_resolver_error((uint8_t) (int32_t) INT32_C(9), l7, l9);
                    vader_array_push((vader_array_t*) l6, vader_ref_box(l10));
                }
                t0 = ((vader_struct_toolchain_ast_Decorator_t*) l5)->f_name;
                if (t0 == 2143u) {
                    vader_resolver_check_target_selectors(l0, l5);
                    t2 = (l4 + INT64_C(1));
                    l4 = (size_t) (int64_t) t2;
                    goto loop_7;
                }
                l11 = ((vader_struct_toolchain_ast_Decorator_t*) l5)->f_args;
                l12 = ((vader_array_t*) l11)->length;
                l13 = (size_t) (int64_t) INT64_C(0);
                {
                    loop_63: {
                        if ((l13 < l12)) {
                            vader_array_t* _a1_slotarr = ((vader_array_t*) l11);
                            if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                            if ((size_t) l13 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                            l14 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l13);
                            vader_resolver_walk_expr(l0, l14);
                            t2 = (l13 + INT64_C(1));
                            l13 = (size_t) (int64_t) t2;
                            goto loop_63;
                        }
                    }
                }
                t2 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t2;
                goto loop_7;
            }
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_resolver_walk_defer(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l3 = vader_box_null();
    void* l4 = NULL;
    void* t0 = NULL;
    vader_box_t* gc_roots[2] = { &l2, &l3 };
    void** gc_raw_roots[4] = { &l0, &l1, &l4, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_toolchain_ast_DeferStmt_t*) l1)->f_body;
    if (l2.tag == 410u) {
        t0 = l2.payload.obj;
        l3 = ((vader_struct_toolchain_ast_DeferStmtBody_t*) t0)->f_stmt;
        vader_resolver_walk_stmt(l0, l3);
    } else {
        if (l2.tag == 408u) {
            t0 = l2.payload.obj;
            l4 = ((vader_struct_toolchain_ast_DeferBlockBody_t*) t0)->f_block;
            vader_resolver_walk_block(l0, l4);
        } else {
            { vader_gc_top = gc_frame.prev; return; }
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_resolver_walk_expr(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    void* l6 = NULL;
    vader_string_t l3 = 0;
    vader_box_t l4 = vader_box_null(), l9 = vader_box_null();
    uint64_t l5;
    size_t l7, l8;
    void* t0 = NULL;
    int64_t t1;
    vader_box_t* gc_roots[3] = { &l1, &l4, &l9 };
    void** gc_raw_roots[4] = { &l0, &l2, &l6, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    if (l1.tag == 426u) {
        l2 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_scope;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_toolchain_ast_IdentExpr_t*) t0)->f_name;
        l4 = vader_resolver_lookup(l2, l3);
        if (l4.tag == 889u) {
            l2 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_idents;
            t0 = l1.payload.obj;
            l5 = toolchain_span_Span_Hash_hash(((vader_struct_toolchain_ast_IdentExpr_t*) t0)->f_span);
            l6 = l4.payload.obj;
            std_collections_put__u64__Any(l2, l5, vader_ref_box(l6));
            l2 = l1.payload.obj;
            l6 = l4.payload.obj;
            vader_resolver_check_wildcard_ambiguity(l0, l2, l6);
        } else {
            if (l4.tag == 0u) {
                l2 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_diags;
                t0 = l1.payload.obj;
                l6 = ((vader_struct_toolchain_ast_IdentExpr_t*) t0)->f_span;
                t0 = l1.payload.obj;
                l3 = ((vader_struct_toolchain_ast_IdentExpr_t*) t0)->f_name;
                l3 = concat_3(930u, l3, 930u);
                l6 = vader_diagnostics_resolver_error((uint8_t) (int32_t) INT32_C(5), l6, l3);
                vader_array_push((vader_array_t*) l2, vader_ref_box(l6));
            } else {
                { vader_gc_top = gc_frame.prev; return; }
            }
        }
    } else {
        if (l1.tag == 402u) {
            t0 = l1.payload.obj;
            l4 = ((vader_struct_toolchain_ast_CallExpr_t*) t0)->f_callee;
            vader_resolver_walk_expr(l0, l4);
            t0 = l1.payload.obj;
            l2 = ((vader_struct_toolchain_ast_CallExpr_t*) t0)->f_args;
            l7 = ((vader_array_t*) l2)->length;
            l8 = (size_t) (int64_t) INT64_C(0);
            {
                loop_92: {
                    if ((l8 < l7)) {
                        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
                        if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                        if ((size_t) l8 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l8);
                        l4 = ((vader_struct_toolchain_ast_CallArg_t*) t0)->f_value;
                        vader_resolver_walk_expr(l0, l4);
                        t1 = (l8 + INT64_C(1));
                        l8 = (size_t) (int64_t) t1;
                        goto loop_92;
                    }
                }
            }
        } else {
            if (l1.tag == 419u) {
                t0 = l1.payload.obj;
                l4 = ((vader_struct_toolchain_ast_FieldExpr_t*) t0)->f_target;
                vader_resolver_walk_expr(l0, l4);
            } else {
                if (l1.tag == 434u) {
                    t0 = l1.payload.obj;
                    l4 = ((vader_struct_toolchain_ast_IndexExpr_t*) t0)->f_target;
                    vader_resolver_walk_expr(l0, l4);
                    t0 = l1.payload.obj;
                    l4 = ((vader_struct_toolchain_ast_IndexExpr_t*) t0)->f_index;
                    vader_resolver_walk_expr(l0, l4);
                } else {
                    if (l1.tag == 475u) {
                        t0 = l1.payload.obj;
                        l4 = ((vader_struct_toolchain_ast_UnaryExpr_t*) t0)->f_operand;
                        vader_resolver_walk_expr(l0, l4);
                    } else {
                        if (l1.tag == 396u) {
                            t0 = l1.payload.obj;
                            l4 = ((vader_struct_toolchain_ast_BinaryExpr_t*) t0)->f_left;
                            vader_resolver_walk_expr(l0, l4);
                            t0 = l1.payload.obj;
                            l4 = ((vader_struct_toolchain_ast_BinaryExpr_t*) t0)->f_right;
                            vader_resolver_walk_expr(l0, l4);
                        } else {
                            if (l1.tag == 448u) {
                                t0 = l1.payload.obj;
                                l4 = ((vader_struct_toolchain_ast_NullCoalesceExpr_t*) t0)->f_left;
                                vader_resolver_walk_expr(l0, l4);
                                t0 = l1.payload.obj;
                                l4 = ((vader_struct_toolchain_ast_NullCoalesceExpr_t*) t0)->f_fallback;
                                if ((l4.tag == 400u || l4.tag == 406u || l4.tag == 457u)) {
                                    l9 = l4;
                                    vader_resolver_walk_stmt(l0, l9);
                                } else {
                                    if ((l4.tag == 392u || l4.tag == 395u || l4.tag == 396u || l4.tag == 398u || l4.tag == 399u || l4.tag == 402u || l4.tag == 403u || l4.tag == 404u || l4.tag == 414u || l4.tag == 419u || l4.tag == 420u || l4.tag == 423u || l4.tag == 425u || l4.tag == 426u || l4.tag == 429u || l4.tag == 434u || l4.tag == 436u || l4.tag == 437u || l4.tag == 439u || l4.tag == 443u || l4.tag == 445u || l4.tag == 448u || l4.tag == 449u || l4.tag == 454u || l4.tag == 458u || l4.tag == 460u || l4.tag == 465u || l4.tag == 475u)) {
                                        vader_resolver_walk_expr(l0, l4);
                                    } else {
                                        { vader_gc_top = gc_frame.prev; return; }
                                    }
                                }
                            } else {
                                if (l1.tag == 429u) {
                                    l2 = l1.payload.obj;
                                    vader_resolver_walk_if(l0, l2);
                                } else {
                                    if (l1.tag == 443u) {
                                        l2 = l1.payload.obj;
                                        vader_resolver_walk_match(l0, l2);
                                    } else {
                                        if (l1.tag == 398u) {
                                            l2 = l1.payload.obj;
                                            vader_resolver_walk_block(l0, l2);
                                        } else {
                                            if (l1.tag == 439u) {
                                                l2 = l1.payload.obj;
                                                vader_resolver_walk_lambda(l0, l2);
                                            } else {
                                                if (l1.tag == 465u) {
                                                    l2 = l1.payload.obj;
                                                    vader_resolver_walk_struct_lit(l0, l2);
                                                } else {
                                                    if (l1.tag == 458u) {
                                                        t0 = l1.payload.obj;
                                                        l2 = ((vader_struct_toolchain_ast_SeqLitExpr_t*) t0)->f_elements;
                                                        l7 = ((vader_array_t*) l2)->length;
                                                        l8 = (size_t) (int64_t) INT64_C(0);
                                                        {
                                                            loop_267: {
                                                                if ((l8 < l7)) {
                                                                    vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
                                                                    if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                                                                    if ((size_t) l8 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                                                                    l4 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l8);
                                                                    vader_resolver_walk_expr(l0, l4);
                                                                    t1 = (l8 + INT64_C(1));
                                                                    l8 = (size_t) (int64_t) t1;
                                                                    goto loop_267;
                                                                }
                                                            }
                                                        }
                                                    } else {
                                                        if (l1.tag == 454u) {
                                                            t0 = l1.payload.obj;
                                                            l4 = ((vader_struct_toolchain_ast_RangeExpr_t*) t0)->f_lower;
                                                            vader_resolver_walk_expr(l0, l4);
                                                            t0 = l1.payload.obj;
                                                            l4 = ((vader_struct_toolchain_ast_RangeExpr_t*) t0)->f_upper;
                                                            vader_resolver_walk_expr(l0, l4);
                                                        } else {
                                                            if (l1.tag == 395u) {
                                                                t0 = l1.payload.obj;
                                                                l4 = ((vader_struct_toolchain_ast_AwaitExpr_t*) t0)->f_inner;
                                                                vader_resolver_walk_expr(l0, l4);
                                                            } else {
                                                                if (l1.tag == 403u) {
                                                                    t0 = l1.payload.obj;
                                                                    l4 = ((vader_struct_toolchain_ast_CastExpr_t*) t0)->f_value;
                                                                    vader_resolver_walk_expr(l0, l4);
                                                                    t0 = l1.payload.obj;
                                                                    l4 = ((vader_struct_toolchain_ast_CastExpr_t*) t0)->f_target;
                                                                    vader_resolver_walk_expr(l0, l4);
                                                                } else {
                                                                    if (l1.tag == 425u) {
                                                                        t0 = l1.payload.obj;
                                                                        l4 = ((vader_struct_toolchain_ast_GenericInstExpr_t*) t0)->f_callee;
                                                                        vader_resolver_walk_expr(l0, l4);
                                                                        t0 = l1.payload.obj;
                                                                        l2 = ((vader_struct_toolchain_ast_GenericInstExpr_t*) t0)->f_type_args;
                                                                        l7 = ((vader_array_t*) l2)->length;
                                                                        l8 = (size_t) (int64_t) INT64_C(0);
                                                                        {
                                                                            loop_354: {
                                                                                if ((l8 < l7)) {
                                                                                    vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
                                                                                    if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                                                                                    if ((size_t) l8 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                                                                                    l4 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l8);
                                                                                    vader_resolver_walk_expr(l0, l4);
                                                                                    t1 = (l8 + INT64_C(1));
                                                                                    l8 = (size_t) (int64_t) t1;
                                                                                    goto loop_354;
                                                                                }
                                                                            }
                                                                        }
                                                                    } else {
                                                                        if (l1.tag == 437u) {
                                                                            t0 = l1.payload.obj;
                                                                            l2 = ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) t0)->f_args;
                                                                            l7 = ((vader_array_t*) l2)->length;
                                                                            l8 = (size_t) (int64_t) INT64_C(0);
                                                                            {
                                                                                loop_387: {
                                                                                    if ((l8 < l7)) {
                                                                                        vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
                                                                                        if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                                                                                        if ((size_t) l8 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                                                                                        l4 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l8);
                                                                                        vader_resolver_walk_expr(l0, l4);
                                                                                        t1 = (l8 + INT64_C(1));
                                                                                        l8 = (size_t) (int64_t) t1;
                                                                                        goto loop_387;
                                                                                    }
                                                                                }
                                                                            }
                                                                        } else {
                                                                            if (l1.tag == 414u) {
                                                                            } else {
                                                                                if (l1.tag == 423u) {
                                                                                    t0 = l1.payload.obj;
                                                                                    l2 = ((vader_struct_toolchain_ast_FnTypeExpr_t*) t0)->f_params;
                                                                                    l7 = ((vader_array_t*) l2)->length;
                                                                                    l8 = (size_t) (int64_t) INT64_C(0);
                                                                                    {
                                                                                        loop_424: {
                                                                                            if ((l8 < l7)) {
                                                                                                vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
                                                                                                if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                                                                                                if ((size_t) l8 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                                                                                                l4 = vader_array_ref_load_box(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l8);
                                                                                                vader_resolver_walk_expr(l0, l4);
                                                                                                t1 = (l8 + INT64_C(1));
                                                                                                l8 = (size_t) (int64_t) t1;
                                                                                                goto loop_424;
                                                                                            }
                                                                                        }
                                                                                    }
                                                                                    t0 = l1.payload.obj;
                                                                                    l4 = ((vader_struct_toolchain_ast_FnTypeExpr_t*) t0)->f_return_type;
                                                                                    vader_resolver_walk_opt_expr(l0, l4);
                                                                                } else {
                                                                                    if (l1.tag == 392u) {
                                                                                        t0 = l1.payload.obj;
                                                                                        l4 = ((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t0)->f_element;
                                                                                        vader_resolver_walk_expr(l0, l4);
                                                                                    } else {
                                                                                        if (l1.tag == 445u) {
                                                                                            t0 = l1.payload.obj;
                                                                                            l4 = ((vader_struct_toolchain_ast_MutableTypeExpr_t*) t0)->f_inner;
                                                                                            vader_resolver_walk_expr(l0, l4);
                                                                                        } else {
                                                                                            if (l1.tag == 436u) {
                                                                                            } else {
                                                                                                if (l1.tag == 420u) {
                                                                                                } else {
                                                                                                    if (l1.tag == 399u) {
                                                                                                    } else {
                                                                                                        if (l1.tag == 449u) {
                                                                                                        } else {
                                                                                                            if (l1.tag == 404u) {
                                                                                                            } else {
                                                                                                                if (l1.tag == 460u) {
                                                                                                                    t0 = l1.payload.obj;
                                                                                                                    l2 = ((vader_struct_toolchain_ast_StringLitExpr_t*) t0)->f_parts;
                                                                                                                    l7 = ((vader_array_t*) l2)->length;
                                                                                                                    l8 = (size_t) (int64_t) INT64_C(0);
                                                                                                                    {
                                                                                                                        loop_506: {
                                                                                                                            if ((l8 < l7)) {
                                                                                                                                vader_array_t* _a5_slotarr = ((vader_array_t*) l2);
                                                                                                                                if (_a5_slotarr->buf != NULL && _a5_slotarr->buf->header.forward != NULL) { _a5_slotarr->buf = vader_array_buf_forward(_a5_slotarr->buf); }
                                                                                                                                if ((size_t) l8 >= _a5_slotarr->length) { vader_trap("array index out of bounds"); }
                                                                                                                                l4 = vader_array_ref_load_box(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l8);
                                                                                                                                if (l4.tag == 461u) {
                                                                                                                                    t0 = l4.payload.obj;
                                                                                                                                    l9 = ((vader_struct_toolchain_ast_StringLitInterp_t*) t0)->f_expr;
                                                                                                                                    vader_resolver_walk_expr(l0, l9);
                                                                                                                                } else {
                                                                                                                                }
                                                                                                                                t1 = (l8 + INT64_C(1));
                                                                                                                                l8 = (size_t) (int64_t) t1;
                                                                                                                                goto loop_506;
                                                                                                                            }
                                                                                                                        }
                                                                                                                    }
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
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_resolver_walk_fn_decl(void* l0, void* l1) {
    void* l2 = NULL;
    void* l5 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l11 = NULL;
    void* l14 = NULL;
    size_t l3, l4;
    vader_string_t l6 = 0;
    vader_string_t l10 = 0;
    uint64_t l12;
    vader_box_t l13 = vader_box_null(), l16 = vader_box_null();
    int32_t l15;
    int64_t t0;
    vader_box_t* gc_roots[2] = { &l13, &l16 };
    void** gc_raw_roots[9] = { &l0, &l1, &l2, &l5, &l7, &l8, &l9, &l11, &l14 };
    vader_string_t* gc_atom_roots[2] = { &l6, &l10 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 9u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_toolchain_ast_FnDecl_t*) l1)->f_decorators;
    vader_resolver_walk_decorators(l0, l2);
    vader_resolver_push(((vader_struct_vader_resolver_ResolveState_t*) l0)->f_scope);
    l2 = ((vader_struct_toolchain_ast_FnDecl_t*) l1)->f_type_params;
    l3 = ((vader_array_t*) l2)->length;
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_14: {
            if ((l4 < l3)) {
                vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
                if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                if ((size_t) l4 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                l5 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
                l6 = ((vader_struct_toolchain_ast_TypeParam_t*) l5)->f_name;
                l7 = ((vader_struct_toolchain_ast_TypeParam_t*) l5)->f_span;
                l8 = vader_resolver_mint_local(l0, INT32_C(9), l6, l7);
                l9 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_scope;
                l10 = ((vader_struct_toolchain_ast_TypeParam_t*) l5)->f_name;
                vader_resolver_bind(l9, l10, l8);
                l11 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_idents;
                l12 = toolchain_span_Span_Hash_hash(((vader_struct_toolchain_ast_TypeParam_t*) l5)->f_span);
                std_collections_put__u64__Any(l11, l12, vader_ref_box(l8));
                l13 = ((vader_struct_toolchain_ast_TypeParam_t*) l5)->f_bound;
                vader_resolver_walk_opt_expr(l0, l13);
                if (!(((vader_struct_toolchain_ast_TypeParam_t*) l5)->f_bound.tag == 0u)) {
                    l14 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_type_param_bounds;
                    l15 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l8)->f_id;
                    l16 = ((vader_struct_toolchain_ast_TypeParam_t*) l5)->f_bound;
                    std_collections_put__i32__Any(l14, l15, l16);
                }
                t0 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                goto loop_14;
            }
        }
    }
    l2 = ((vader_struct_toolchain_ast_FnDecl_t*) l1)->f_params;
    l3 = ((vader_array_t*) l2)->length;
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_88: {
            if ((l4 < l3)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l4 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                l5 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
                l13 = ((vader_struct_toolchain_ast_FnParam_t*) l5)->f_ty;
                vader_resolver_walk_opt_expr(l0, l13);
                l16 = ((vader_struct_toolchain_ast_FnParam_t*) l5)->f_default_value;
                vader_resolver_walk_opt_expr(l0, l16);
                l6 = ((vader_struct_toolchain_ast_FnParam_t*) l5)->f_name;
                l7 = ((vader_struct_toolchain_ast_FnParam_t*) l5)->f_span;
                l8 = vader_resolver_bind_local_checked(l0, INT32_C(8), l6, l7);
                l9 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_idents;
                l12 = toolchain_span_Span_Hash_hash(((vader_struct_toolchain_ast_FnParam_t*) l5)->f_span);
                std_collections_put__u64__Any(l9, l12, vader_ref_box(l8));
                vader_resolver_mark_param_borrow(l0, l5, l8);
                t0 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                goto loop_88;
            }
        }
    }
    l13 = ((vader_struct_toolchain_ast_FnDecl_t*) l1)->f_return_type;
    vader_resolver_walk_opt_expr(l0, l13);
    l13 = ((vader_struct_toolchain_ast_FnDecl_t*) l1)->f_body;
    if (l13.tag == 0u) {
    } else {
        if (l13.tag == 398u) {
            l2 = l13.payload.obj;
            vader_resolver_walk_block(l0, l2);
        } else {
            { vader_gc_top = gc_frame.prev; return; }
        }
    }
    vader_resolver_pop(((vader_struct_vader_resolver_ResolveState_t*) l0)->f_scope);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_resolver_walk_for(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l3 = vader_box_null();
    void* l4 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    vader_string_t l5 = 0;
    uint64_t l8;
    void* t0 = NULL;
    vader_box_t* gc_roots[2] = { &l2, &l3 };
    void** gc_raw_roots[6] = { &l0, &l1, &l4, &l6, &l7, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_toolchain_ast_ForStmt_t*) l1)->f_form;
    if (l2.tag == 435u) {
    } else {
        if (l2.tag == 476u) {
            t0 = l2.payload.obj;
            l3 = ((vader_struct_toolchain_ast_WhileFor_t*) t0)->f_cond;
            vader_resolver_walk_expr(l0, l3);
        } else {
            if (l2.tag == 433u) {
                t0 = l2.payload.obj;
                l2 = ((vader_struct_toolchain_ast_InFor_t*) t0)->f_iter;
                vader_resolver_walk_expr(l0, l2);
            } else {
                { vader_gc_top = gc_frame.prev; return; }
            }
        }
    }
    vader_resolver_push(((vader_struct_vader_resolver_ResolveState_t*) l0)->f_scope);
    l2 = ((vader_struct_toolchain_ast_ForStmt_t*) l1)->f_form;
    if (l2.tag == 433u) {
        t0 = l2.payload.obj;
        l2 = ((vader_struct_toolchain_ast_InFor_t*) t0)->f_loop_var;
        if (l2.tag == 447u) {
            l4 = l2.payload.obj;
            l5 = ((vader_struct_toolchain_ast_NamedVar_t*) l4)->f_name;
            l6 = ((vader_struct_toolchain_ast_NamedVar_t*) l4)->f_span;
            l6 = vader_resolver_bind_local_checked(l0, INT32_C(10), l5, l6);
            l7 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_idents;
            l8 = toolchain_span_Span_Hash_hash(((vader_struct_toolchain_ast_NamedVar_t*) l4)->f_span);
            std_collections_put__u64__Any(l7, l8, vader_ref_box(l6));
        } else {
            if (l2.tag == 412u) {
                t0 = l2.payload.obj;
                l3 = ((vader_struct_toolchain_ast_DestructureVar_t*) t0)->f_pattern;
                vader_resolver_bind_let_binding(l0, l3);
            } else {
                if (l2.tag == 413u) {
                } else {
                    { vader_gc_top = gc_frame.prev; return; }
                }
            }
        }
    } else {
    }
    l4 = ((vader_struct_toolchain_ast_ForStmt_t*) l1)->f_body;
    vader_resolver_walk_block(l0, l4);
    vader_resolver_pop(((vader_struct_vader_resolver_ResolveState_t*) l0)->f_scope);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_resolver_walk_if(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null();
    void* l3 = NULL;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[4] = { &l0, &l1, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_resolver_push(((vader_struct_vader_resolver_ResolveState_t*) l0)->f_scope);
    l2 = ((vader_struct_toolchain_ast_IfExpr_t*) l1)->f_cond;
    vader_resolver_bind_cond_is_as(l0, l2, false);
    l3 = ((vader_struct_toolchain_ast_IfExpr_t*) l1)->f_then_block;
    vader_resolver_walk_block(l0, l3);
    vader_resolver_pop(((vader_struct_vader_resolver_ResolveState_t*) l0)->f_scope);
    l2 = ((vader_struct_toolchain_ast_IfExpr_t*) l1)->f_else_branch;
    if (l2.tag == 0u) {
    } else {
        if (l2.tag == 428u) {
            t0 = l2.payload.obj;
            l3 = ((vader_struct_toolchain_ast_IfElseIf_t*) t0)->f_branch;
            vader_resolver_walk_if(l0, l3);
        } else {
            if (l2.tag == 427u) {
                t0 = l2.payload.obj;
                l3 = ((vader_struct_toolchain_ast_IfElseBlock_t*) t0)->f_block;
                vader_resolver_walk_block(l0, l3);
            } else {
                { vader_gc_top = gc_frame.prev; return; }
            }
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_resolver_walk_impl_decl(void* l0, void* l1) {
    void* l2 = NULL;
    void* l5 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l12 = NULL;
    size_t l3, l4;
    vader_string_t l6 = 0;
    vader_string_t l10 = 0;
    vader_box_t l11 = vader_box_null(), l14 = vader_box_null();
    int32_t l13;
    bool l15;
    int64_t t0;
    bool t1;
    vader_box_t* gc_roots[2] = { &l11, &l14 };
    void** gc_raw_roots[8] = { &l0, &l1, &l2, &l5, &l7, &l8, &l9, &l12 };
    vader_string_t* gc_atom_roots[2] = { &l6, &l10 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_toolchain_ast_ImplDecl_t*) l1)->f_decorators;
    vader_resolver_walk_decorators(l0, l2);
    vader_resolver_push(((vader_struct_vader_resolver_ResolveState_t*) l0)->f_scope);
    l2 = ((vader_struct_toolchain_ast_ImplDecl_t*) l1)->f_type_params;
    l3 = ((vader_array_t*) l2)->length;
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_14: {
            if ((l4 < l3)) {
                vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
                if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                if ((size_t) l4 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                l5 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
                l6 = ((vader_struct_toolchain_ast_TypeParam_t*) l5)->f_name;
                l7 = ((vader_struct_toolchain_ast_TypeParam_t*) l5)->f_span;
                l8 = vader_resolver_mint_local(l0, INT32_C(9), l6, l7);
                l9 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_scope;
                l10 = ((vader_struct_toolchain_ast_TypeParam_t*) l5)->f_name;
                vader_resolver_bind(l9, l10, l8);
                l11 = ((vader_struct_toolchain_ast_TypeParam_t*) l5)->f_bound;
                vader_resolver_walk_opt_expr(l0, l11);
                if (!(((vader_struct_toolchain_ast_TypeParam_t*) l5)->f_bound.tag == 0u)) {
                    l12 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_type_param_bounds;
                    l13 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l8)->f_id;
                    l14 = ((vader_struct_toolchain_ast_TypeParam_t*) l5)->f_bound;
                    std_collections_put__i32__Any(l12, l13, l14);
                }
                t0 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                goto loop_14;
            }
        }
    }
    l11 = ((vader_struct_toolchain_ast_ImplDecl_t*) l1)->f_for_type;
    vader_resolver_auto_bind_for_type_params(l0, l11);
    l11 = ((vader_struct_toolchain_ast_ImplDecl_t*) l1)->f_for_type;
    vader_resolver_walk_expr(l0, l11);
    l2 = ((vader_struct_toolchain_ast_ImplDecl_t*) l1)->f_trait_args;
    l3 = ((vader_array_t*) l2)->length;
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_89: {
            if ((l4 < l3)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l4 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                l11 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
                vader_resolver_walk_expr(l0, l11);
                t0 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                goto loop_89;
            }
        }
    }
    l2 = ((vader_struct_toolchain_ast_ImplDecl_t*) l1)->f_members;
    l3 = ((vader_array_t*) l2)->length;
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_116: {
            if ((l4 < l3)) {
                vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
                if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                if ((size_t) l4 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                l5 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
                t1 = ((vader_struct_toolchain_ast_FnDecl_t*) l5)->f_materialized;
                if (t1) {
                    l15 = ((vader_struct_toolchain_ast_FnDecl_t*) l5)->f_sam_synthetic;
                } else {
                    l15 = false;
                }
                if (l15) {
                    t0 = (l4 + INT64_C(1));
                    l4 = (size_t) (int64_t) t0;
                    goto loop_116;
                }
                vader_resolver_walk_fn_decl(l0, l5);
                t0 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                goto loop_116;
            }
        }
    }
    vader_resolver_pop(((vader_struct_vader_resolver_ResolveState_t*) l0)->f_scope);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_resolver_walk_import_cycle(vader_string_t l0, void* l1, void* l2, void* l3, void* l4) {
    vader_box_t l5 = vader_box_null(), l10 = vader_box_null(), l12 = vader_box_null();
    void* l6 = NULL;
    void* l13 = NULL;
    void* l16 = NULL;
    size_t l7, l8;
    vader_string_t l9 = 0;
    vader_string_t l11 = 0;
    vader_string_t l14 = 0;
    vader_string_t l15 = 0;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_string_t t2 = 0;
    int32_t t3;
    int64_t t4;
    vader_box_t* gc_roots[4] = { &l5, &l10, &l12, &t1 };
    void** gc_raw_roots[8] = { &l1, &l2, &l3, &l4, &l6, &l13, &l16, &t0 };
    vader_string_t* gc_atom_roots[6] = { &l0, &l9, &l11, &l14, &l15, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 6u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    std_collections_put__string__i32(l3, l0, INT32_C(1));
    l5 = std_collections_get__string__Any(l1, l0);
    if (l5.tag == 876u) {
        t0 = l5.payload.obj;
        l6 = ((vader_struct_vader_resolver_CollectedModule_t*) ((vader_struct_vader_resolver_LoadedModule_t*) t0)->f_collected)->f_import_paths;
        l7 = ((vader_array_t*) l6)->length;
        l8 = (size_t) (int64_t) INT64_C(0);
        {
            loop_20: {
                if ((l8 < l7)) {
                    vader_array_t* _a0_slotarr = ((vader_array_t*) l6);
                    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                    if ((size_t) l8 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                    t1 = vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l8];
                    l9 = t1.payload.s;
                    l10 = std_collections_get__string__Any(l2, l9);
                    if (l10.tag == 870u) {
                        t0 = l10.payload.obj;
                        l11 = ((vader_struct_vader_resolver_DiscoveredModule_t*) t0)->f_folder;
                        l12 = std_collections_get__string__i32(l3, l11);
                        if (l12.tag == 0u) {
                            t0 = l10.payload.obj;
                            t2 = ((vader_struct_vader_resolver_DiscoveredModule_t*) t0)->f_folder;
                            vader_resolver_walk_import_cycle(t2, l1, l2, l3, l4);
                        } else {
                            t3 = ((int32_t) l12.payload.i);
                            if (t3 == INT32_C(1)) {
                                t0 = l5.payload.obj;
                                t2 = ((vader_struct_vader_resolver_Module_t*) ((vader_struct_vader_resolver_LoadedModule_t*) t0)->f_module)->f_display_path;
                                l13 = vader_resolver_zero_span(t2);
                                t0 = l5.payload.obj;
                                l14 = ((vader_struct_vader_resolver_Module_t*) ((vader_struct_vader_resolver_LoadedModule_t*) t0)->f_module)->f_display_path;
                                l15 = concat_5(930u, l14, 968u, l9, 1064u);
                                l16 = vader_diagnostics_resolver_error((uint8_t) (int32_t) INT32_C(4), l13, l15);
                                vader_array_push((vader_array_t*) l4, vader_ref_box(l16));
                            }
                        }
                    }
                    t4 = (l8 + INT64_C(1));
                    l8 = (size_t) (int64_t) t4;
                    goto loop_20;
                }
            }
        }
    }
    std_collections_put__string__i32(l3, l0, INT32_C(2));
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_resolver_walk_lambda(void* l0, void* l1) {
    void* l2 = NULL;
    void* l5 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    size_t l3, l4;
    vader_box_t l6 = vader_box_null();
    vader_string_t l7 = 0;
    uint64_t l11;
    int64_t t0;
    vader_box_t* gc_roots[1] = { &l6 };
    void** gc_raw_roots[7] = { &l0, &l1, &l2, &l5, &l8, &l9, &l10 };
    vader_string_t* gc_atom_roots[1] = { &l7 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_resolver_push(((vader_struct_vader_resolver_ResolveState_t*) l0)->f_scope);
    l2 = ((vader_struct_toolchain_ast_LambdaExpr_t*) l1)->f_params;
    l3 = ((vader_array_t*) l2)->length;
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_9: {
            if ((l4 < l3)) {
                vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
                if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                if ((size_t) l4 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                l5 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
                l6 = ((vader_struct_toolchain_ast_FnParam_t*) l5)->f_ty;
                vader_resolver_walk_opt_expr(l0, l6);
                l7 = ((vader_struct_toolchain_ast_FnParam_t*) l5)->f_name;
                l8 = ((vader_struct_toolchain_ast_FnParam_t*) l5)->f_span;
                l9 = vader_resolver_bind_local_checked(l0, INT32_C(8), l7, l8);
                l10 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_idents;
                l11 = toolchain_span_Span_Hash_hash(((vader_struct_toolchain_ast_FnParam_t*) l5)->f_span);
                std_collections_put__u64__Any(l10, l11, vader_ref_box(l9));
                t0 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                goto loop_9;
            }
        }
    }
    l6 = ((vader_struct_toolchain_ast_LambdaExpr_t*) l1)->f_return_type;
    vader_resolver_walk_opt_expr(l0, l6);
    l2 = ((vader_struct_toolchain_ast_LambdaExpr_t*) l1)->f_body;
    vader_resolver_walk_block(l0, l2);
    vader_resolver_pop(((vader_struct_vader_resolver_ResolveState_t*) l0)->f_scope);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_resolver_walk_match(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l9 = vader_box_null(), l10 = vader_box_null();
    vader_string_t l3 = 0;
    void* l4 = NULL;
    void* l5 = NULL;
    uint64_t l6;
    size_t l7, l8;
    vader_string_t t0 = 0;
    int64_t t1;
    vader_box_t* gc_roots[3] = { &l2, &l9, &l10 };
    void** gc_raw_roots[4] = { &l0, &l1, &l4, &l5 };
    vader_string_t* gc_atom_roots[2] = { &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_toolchain_ast_MatchExpr_t*) l1)->f_scrutinee;
    vader_resolver_walk_expr(l0, l2);
    vader_resolver_push(((vader_struct_vader_resolver_ResolveState_t*) l0)->f_scope);
    t0 = ((vader_struct_toolchain_ast_MatchExpr_t*) l1)->f_bind_as;
    if (t0 != 0u) {
        l3 = ((vader_struct_toolchain_ast_MatchExpr_t*) l1)->f_bind_as;
        l4 = ((vader_struct_toolchain_ast_MatchExpr_t*) l1)->f_span;
        l4 = vader_resolver_mint_local(l0, INT32_C(11), l3, l4);
        l5 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_scope;
        l3 = ((vader_struct_toolchain_ast_MatchExpr_t*) l1)->f_bind_as;
        vader_resolver_bind(l5, l3, l4);
        l5 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_idents;
        l6 = toolchain_span_Span_Hash_hash(((vader_struct_toolchain_ast_MatchExpr_t*) l1)->f_span);
        std_collections_put__u64__Any(l5, l6, vader_ref_box(l4));
    }
    l4 = ((vader_struct_toolchain_ast_MatchExpr_t*) l1)->f_arms;
    l7 = ((vader_array_t*) l4)->length;
    l8 = (size_t) (int64_t) INT64_C(0);
    {
        loop_49: {
            if ((l8 < l7)) {
                vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
                if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                if ((size_t) l8 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                l5 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l8);
                vader_resolver_push(((vader_struct_vader_resolver_ResolveState_t*) l0)->f_scope);
                l2 = ((vader_struct_toolchain_ast_MatchArm_t*) l5)->f_pattern;
                vader_resolver_bind_pattern(l0, l2);
                l9 = ((vader_struct_toolchain_ast_MatchArm_t*) l5)->f_guard;
                vader_resolver_walk_opt_expr(l0, l9);
                l10 = ((vader_struct_toolchain_ast_MatchArm_t*) l5)->f_body;
                vader_resolver_walk_expr(l0, l10);
                vader_resolver_pop(((vader_struct_vader_resolver_ResolveState_t*) l0)->f_scope);
                t1 = (l8 + INT64_C(1));
                l8 = (size_t) (int64_t) t1;
                goto loop_49;
            }
        }
    }
    vader_resolver_pop(((vader_struct_vader_resolver_ResolveState_t*) l0)->f_scope);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_resolver_walk_opt_expr(void* l0, vader_box_t l1) {
    vader_box_t l2 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l1, &l2 };
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (!(l1.tag == 0u)) {
        l2 = l1;
        vader_resolver_walk_expr(l0, l2);
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_resolver_walk_stmt(void* l0, vader_box_t l1) {
    vader_box_t l2 = vader_box_null();
    void* l3 = NULL;
    void* t0 = NULL;
    bool t1;
    vader_box_t* gc_roots[2] = { &l1, &l2 };
    void** gc_raw_roots[3] = { &l0, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l1.tag == 440u) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_toolchain_ast_LetStmt_t*) t0)->f_ty;
        vader_resolver_walk_opt_expr(l0, l2);
        t0 = l1.payload.obj;
        l2 = ((vader_struct_toolchain_ast_LetStmt_t*) t0)->f_value;
        vader_resolver_walk_expr(l0, l2);
        t0 = l1.payload.obj;
        l2 = ((vader_struct_toolchain_ast_LetStmt_t*) t0)->f_binding;
        vader_resolver_bind_let_binding(l0, l2);
        t0 = l1.payload.obj;
        t1 = ((vader_struct_toolchain_ast_LetStmt_t*) t0)->f_mutable;
        if (!(t1)) {
            t0 = l1.payload.obj;
            l2 = ((vader_struct_toolchain_ast_LetStmt_t*) t0)->f_binding;
            vader_resolver_mark_binding_immutable(l0, l2);
        }
    } else {
        if (l1.tag == 394u) {
            t0 = l1.payload.obj;
            l2 = ((vader_struct_toolchain_ast_AssignStmt_t*) t0)->f_target;
            vader_resolver_walk_expr(l0, l2);
            t0 = l1.payload.obj;
            l2 = ((vader_struct_toolchain_ast_AssignStmt_t*) t0)->f_value;
            vader_resolver_walk_expr(l0, l2);
        } else {
            if (l1.tag == 418u) {
                t0 = l1.payload.obj;
                l2 = ((vader_struct_toolchain_ast_ExprStmt_t*) t0)->f_expr;
                vader_resolver_walk_expr(l0, l2);
            } else {
                if (l1.tag == 457u) {
                    t0 = l1.payload.obj;
                    l2 = ((vader_struct_toolchain_ast_ReturnStmt_t*) t0)->f_value;
                    vader_resolver_walk_opt_expr(l0, l2);
                } else {
                    if (l1.tag == 480u) {
                        t0 = l1.payload.obj;
                        l2 = ((vader_struct_toolchain_ast_YieldStmt_t*) t0)->f_value;
                        vader_resolver_walk_expr(l0, l2);
                    } else {
                        if (l1.tag == 424u) {
                            l3 = l1.payload.obj;
                            vader_resolver_walk_for(l0, l3);
                        } else {
                            if (l1.tag == 400u) {
                            } else {
                                if (l1.tag == 406u) {
                                } else {
                                    if (l1.tag == 409u) {
                                        l3 = l1.payload.obj;
                                        vader_resolver_walk_defer(l0, l3);
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
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_resolver_walk_struct_decl(void* l0, void* l1) {
    void* l2 = NULL;
    void* l5 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l12 = NULL;
    size_t l3, l4;
    vader_string_t l6 = 0;
    vader_string_t l10 = 0;
    vader_box_t l11 = vader_box_null(), l14 = vader_box_null();
    int32_t l13;
    int64_t t0;
    vader_box_t* gc_roots[2] = { &l11, &l14 };
    void** gc_raw_roots[8] = { &l0, &l1, &l2, &l5, &l7, &l8, &l9, &l12 };
    vader_string_t* gc_atom_roots[2] = { &l6, &l10 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_toolchain_ast_StructDecl_t*) l1)->f_decorators;
    vader_resolver_walk_decorators(l0, l2);
    vader_resolver_push(((vader_struct_vader_resolver_ResolveState_t*) l0)->f_scope);
    l2 = ((vader_struct_toolchain_ast_StructDecl_t*) l1)->f_type_params;
    l3 = ((vader_array_t*) l2)->length;
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_14: {
            if ((l4 < l3)) {
                vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
                if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                if ((size_t) l4 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                l5 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
                l6 = ((vader_struct_toolchain_ast_TypeParam_t*) l5)->f_name;
                l7 = ((vader_struct_toolchain_ast_TypeParam_t*) l5)->f_span;
                l8 = vader_resolver_mint_local(l0, INT32_C(9), l6, l7);
                l9 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_scope;
                l10 = ((vader_struct_toolchain_ast_TypeParam_t*) l5)->f_name;
                vader_resolver_bind(l9, l10, l8);
                l11 = ((vader_struct_toolchain_ast_TypeParam_t*) l5)->f_bound;
                vader_resolver_walk_opt_expr(l0, l11);
                if (!(((vader_struct_toolchain_ast_TypeParam_t*) l5)->f_bound.tag == 0u)) {
                    l12 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_type_param_bounds;
                    l13 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l8)->f_id;
                    l14 = ((vader_struct_toolchain_ast_TypeParam_t*) l5)->f_bound;
                    std_collections_put__i32__Any(l12, l13, l14);
                }
                t0 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                goto loop_14;
            }
        }
    }
    l2 = ((vader_struct_toolchain_ast_StructDecl_t*) l1)->f_fields;
    l3 = ((vader_array_t*) l2)->length;
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_79: {
            if ((l4 < l3)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l4 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                l5 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
                l11 = ((vader_struct_toolchain_ast_StructField_t*) l5)->f_ty;
                vader_resolver_walk_expr(l0, l11);
                l14 = ((vader_struct_toolchain_ast_StructField_t*) l5)->f_default_v;
                vader_resolver_walk_opt_expr(l0, l14);
                t0 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                goto loop_79;
            }
        }
    }
    vader_resolver_pop(((vader_struct_vader_resolver_ResolveState_t*) l0)->f_scope);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_resolver_walk_struct_lit(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l6 = vader_box_null(), l7 = vader_box_null();
    void* l3 = NULL;
    size_t l4, l5;
    void* t0 = NULL;
    int64_t t1;
    vader_box_t* gc_roots[3] = { &l2, &l6, &l7 };
    void** gc_raw_roots[4] = { &l0, &l1, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_toolchain_ast_StructLitExpr_t*) l1)->f_type_name;
    vader_resolver_walk_expr(l0, l2);
    l3 = ((vader_struct_toolchain_ast_StructLitExpr_t*) l1)->f_items;
    l4 = ((vader_array_t*) l3)->length;
    l5 = (size_t) (int64_t) INT64_C(0);
    {
        loop_12: {
            if ((l5 < l4)) {
                vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
                if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                if ((size_t) l5 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                l2 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
                if (l2.tag == 466u) {
                    t0 = l2.payload.obj;
                    l6 = ((vader_struct_toolchain_ast_StructLitField_t*) t0)->f_value;
                    vader_resolver_walk_expr(l0, l6);
                } else {
                    if (l2.tag == 467u) {
                        t0 = l2.payload.obj;
                        l7 = ((vader_struct_toolchain_ast_StructLitSpread_t*) t0)->f_expr;
                        vader_resolver_walk_expr(l0, l7);
                    } else {
                        { vader_gc_top = gc_frame.prev; return; }
                    }
                }
                t1 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t1;
                goto loop_12;
            }
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_resolver_walk_trait_decl(void* l0, void* l1) {
    void* l2 = NULL;
    void* l5 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l12 = NULL;
    size_t l3, l4;
    vader_string_t l6 = 0;
    vader_string_t l10 = 0;
    vader_box_t l11 = vader_box_null(), l14 = vader_box_null();
    int32_t l13;
    int64_t t0;
    vader_box_t* gc_roots[2] = { &l11, &l14 };
    void** gc_raw_roots[8] = { &l0, &l1, &l2, &l5, &l7, &l8, &l9, &l12 };
    vader_string_t* gc_atom_roots[2] = { &l6, &l10 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_toolchain_ast_TraitDecl_t*) l1)->f_decorators;
    vader_resolver_walk_decorators(l0, l2);
    vader_resolver_push(((vader_struct_vader_resolver_ResolveState_t*) l0)->f_scope);
    l2 = ((vader_struct_toolchain_ast_TraitDecl_t*) l1)->f_type_params;
    l3 = ((vader_array_t*) l2)->length;
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_14: {
            if ((l4 < l3)) {
                vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
                if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                if ((size_t) l4 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                l5 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
                l6 = ((vader_struct_toolchain_ast_TypeParam_t*) l5)->f_name;
                l7 = ((vader_struct_toolchain_ast_TypeParam_t*) l5)->f_span;
                l8 = vader_resolver_mint_local(l0, INT32_C(9), l6, l7);
                l9 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_scope;
                l10 = ((vader_struct_toolchain_ast_TypeParam_t*) l5)->f_name;
                vader_resolver_bind(l9, l10, l8);
                l11 = ((vader_struct_toolchain_ast_TypeParam_t*) l5)->f_bound;
                vader_resolver_walk_opt_expr(l0, l11);
                if (!(((vader_struct_toolchain_ast_TypeParam_t*) l5)->f_bound.tag == 0u)) {
                    l12 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_type_param_bounds;
                    l13 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l8)->f_id;
                    l14 = ((vader_struct_toolchain_ast_TypeParam_t*) l5)->f_bound;
                    std_collections_put__i32__Any(l12, l13, l14);
                }
                t0 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                goto loop_14;
            }
        }
    }
    l11 = ((vader_struct_toolchain_ast_TraitDecl_t*) l1)->f_requires;
    vader_resolver_walk_opt_expr(l0, l11);
    l2 = ((vader_struct_toolchain_ast_TraitDecl_t*) l1)->f_members;
    l3 = ((vader_array_t*) l2)->length;
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_84: {
            if ((l4 < l3)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l4 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                l5 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
                vader_resolver_walk_fn_decl(l0, l5);
                t0 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                goto loop_84;
            }
        }
    }
    vader_resolver_pop(((vader_struct_vader_resolver_ResolveState_t*) l0)->f_scope);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

void* vader_resolver_wildcard_ambiguities(void* l0, void* l1, void* l2, void* l3) {
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    void* l18 = NULL;
    void* l19 = NULL;
    void* l21 = NULL;
    void* l27 = NULL;
    void* l29 = NULL;
    void* l33 = NULL;
    size_t l7, l8, l15, l16, l30, l31;
    vader_string_t l9 = 0;
    vader_string_t l17 = 0;
    vader_string_t l22 = 0;
    vader_string_t l23 = 0;
    vader_string_t l24 = 0;
    vader_string_t l26 = 0;
    vader_string_t l32 = 0;
    vader_box_t l10 = vader_box_null(), l11 = vader_box_null(), l25 = vader_box_null();
    bool l20, l28;
    vader_box_t t0 = vader_box_null();
    int64_t t1;
    void* t2 = NULL;
    bool t3;
    vader_string_t t4 = 0;
    size_t t5;
    vader_box_t* gc_roots[4] = { &l10, &l11, &l25, &t0 };
    void** gc_raw_roots[17] = { &l0, &l1, &l2, &l3, &l4, &l5, &l6, &l12, &l13, &l14, &l18, &l19, &l21, &l27, &l29, &l33, &t2 };
    vader_struct___Tuple_2_cb60e7c5b39cd1d9_t _a7_storage = {0};
    void* gc_stack_objs[1] = { (void*) &_a7_storage };
    vader_string_t* gc_atom_roots[8] = { &l9, &l17, &l22, &l23, &l24, &l26, &l32, &t4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 17u, gc_roots, gc_raw_roots, 1u, gc_stack_objs, 8u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 169u);
    l4 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(16u, 0u, 0u, 180u);
    l5 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 172u);
    l6 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__string__Any___t* _a3_obj = (vader_struct_std_collections_MutableMap__string__Any___t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__Any___t));
    vader_obj_header_init(_a3_obj, 323u);
    _a3_obj->f_ekeys = l4;
    _a3_obj->f_evals = l5;
    _a3_obj->f_index = l6;
    _a3_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l4 = (void*) _a3_obj;
    l5 = l1;
    l7 = ((vader_array_t*) l5)->length;
    l8 = (size_t) (int64_t) INT64_C(0);
    {
        loop_21: {
            if ((l8 < l7)) {
                vader_array_t* _a4_slotarr = ((vader_array_t*) l5);
                if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                if ((size_t) l8 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_box_slots(_a4_slotarr->buf)[_a4_slotarr->offset + (size_t) l8];
                l9 = t0.payload.s;
                l10 = std_collections_get__string__Any(l0, l9);
                if (l10.tag == 0u) {
                    t1 = (l8 + INT64_C(1));
                    l8 = (size_t) (int64_t) t1;
                    goto loop_21;
                }
                l6 = l10.payload.obj;
                l11 = std_collections_get__string__Any(l2, l9);
                l12 = ((vader_struct_vader_resolver_CollectedModule_t*) ((vader_struct_vader_resolver_LoadedModule_t*) l6)->f_collected)->f_symbols;
                l13 = ((vader_struct_std_collections_MutableMap__string__Symbol_t*) l12)->f_ekeys;
                l14 = ((vader_struct_std_collections_MutableMap__string__Symbol_t*) l12)->f_evals;
                l15 = ((vader_struct_std_collections_MutableMap__string__Symbol_t*) l12)->f_size;
                l16 = (size_t) (int64_t) INT64_C(0);
                {
                    loop_63: {
                        if ((l16 >= l15)) {
                        } else {
                            vader_array_t* _a5_slotarr = ((vader_array_t*) l13);
                            if (_a5_slotarr->buf != NULL && _a5_slotarr->buf->header.forward != NULL) { _a5_slotarr->buf = vader_array_buf_forward(_a5_slotarr->buf); }
                            if ((size_t) l16 >= _a5_slotarr->length) { vader_trap("array index out of bounds"); }
                            t0 = vader_array_box_slots(_a5_slotarr->buf)[_a5_slotarr->offset + (size_t) l16];
                            l17 = t0.payload.s;
                            vader_array_t* _a6_slotarr = ((vader_array_t*) l14);
                            if (_a6_slotarr->buf != NULL && _a6_slotarr->buf->header.forward != NULL) { _a6_slotarr->buf = vader_array_buf_forward(_a6_slotarr->buf); }
                            if ((size_t) l16 >= _a6_slotarr->length) { vader_trap("array index out of bounds"); }
                            l18 = vader_array_ref_load_obj(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l16);
                            vader_struct___Tuple_2_cb60e7c5b39cd1d9_t* _a8_obj = &_a7_storage;
                            vader_obj_header_init(_a8_obj, 223u);
                            _a8_obj->f__0 = l17;
                            _a8_obj->f__1 = l18;
                            t2 = (void*) _a8_obj;
                            l19 = ((vader_struct___Tuple_2_cb60e7c5b39cd1d9_t*) t2)->f__1;
                            t1 = (l16 + INT64_C(1));
                            l16 = (size_t) (int64_t) t1;
                            t3 = vader_resolver_wildcard_exposable(((vader_struct_vader_resolver_symbol_Symbol_t*) l19)->f_kind);
                            if (!(t3)) {
                                goto loop_63;
                            }
                            if (((vader_struct_vader_resolver_symbol_Symbol_t*) l19)->f_visibility != INT32_C(0)) {
                                goto loop_63;
                            }
                            if (!(l11.tag == 0u)) {
                                l21 = l11.payload.obj;
                                l22 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l19)->f_name;
                                l20 = std_core____Contains_contains__string(l21, l22);
                            } else {
                                l20 = false;
                            }
                            if (l20) {
                                goto loop_63;
                            }
                            l23 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l19)->f_name;
                            t0 = std_collections_get__string__Any(l3, l23);
                            if (!(t0.tag == 0u)) {
                                goto loop_63;
                            }
                            l24 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l19)->f_name;
                            l25 = std_collections_get__string__Any(l4, l24);
                            if (l25.tag == 0u) {
                                l26 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l19)->f_name;
                                vader_array_t* _a9_arr = vader_array_new(8u, 1u, 0u, 169u);
                                vader_array_box_slots(_a9_arr->buf)[_a9_arr->offset + 0u] = vader_box_string(169u, l9);
                                l27 = (void*) _a9_arr;
                                std_collections_put__string__Any(l4, l26, vader_ref_box(l27));
                            } else {
                                l28 = false;
                                l29 = l25.payload.obj;
                                vader_array_t* _a10_slotarr = ((vader_array_t*) l29);
                                if (_a10_slotarr->buf != NULL && _a10_slotarr->buf->header.forward != NULL) { _a10_slotarr->buf = vader_array_buf_forward(_a10_slotarr->buf); }
                                l30 = ((vader_array_t*) l29)->length;
                                l31 = (size_t) (int64_t) INT64_C(0);
                                {
                                    loop_162: {
                                        if ((l31 < l30)) {
                                            if ((size_t) l31 >= _a10_slotarr->length) { vader_trap("array index out of bounds"); }
                                            t0 = vader_array_box_slots(_a10_slotarr->buf)[_a10_slotarr->offset + (size_t) l31];
                                            t4 = t0.payload.s;
                                            if (t4 == l9) {
                                                l28 = true;
                                            }
                                            t1 = (l31 + INT64_C(1));
                                            l31 = (size_t) (int64_t) t1;
                                            goto loop_162;
                                        }
                                    }
                                }
                                if (!(l28)) {
                                    t2 = l25.payload.obj;
                                    vader_array_push((vader_array_t*) t2, vader_box_string(169u, l9));
                                    l32 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l19)->f_name;
                                    l33 = l25.payload.obj;
                                    std_collections_put__string__Any(l4, l32, vader_ref_box(l33));
                                }
                            }
                            goto loop_63;
                        }
                    }
                }
                t1 = (l8 + INT64_C(1));
                l8 = (size_t) (int64_t) t1;
                goto loop_21;
            }
        }
    }
    vader_array_t* _a11_arr = vader_array_new(8u, 0u, 0u, 169u);
    l5 = (void*) _a11_arr;
    vader_array_t* _a12_arr = vader_array_new(16u, 0u, 0u, 180u);
    l6 = (void*) _a12_arr;
    vader_array_t* _a13_arr = vader_array_new(9u, 0u, 7u, 172u);
    l12 = (void*) _a13_arr;
    vader_struct_std_collections_MutableMap__string__Any___t* _a14_obj = (vader_struct_std_collections_MutableMap__string__Any___t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__Any___t));
    vader_obj_header_init(_a14_obj, 323u);
    _a14_obj->f_ekeys = l5;
    _a14_obj->f_evals = l6;
    _a14_obj->f_index = l12;
    _a14_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a14_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a14_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l5 = (void*) _a14_obj;
    l6 = ((vader_struct_std_collections_MutableMap__string__string___t*) l4)->f_ekeys;
    l12 = ((vader_struct_std_collections_MutableMap__string__string___t*) l4)->f_evals;
    l7 = ((vader_struct_std_collections_MutableMap__string__string___t*) l4)->f_size;
    l8 = (size_t) (int64_t) INT64_C(0);
    {
        loop_240: {
            if ((l8 >= l7)) {
            } else {
                vader_array_t* _a15_slotarr = ((vader_array_t*) l6);
                if (_a15_slotarr->buf != NULL && _a15_slotarr->buf->header.forward != NULL) { _a15_slotarr->buf = vader_array_buf_forward(_a15_slotarr->buf); }
                if ((size_t) l8 >= _a15_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_box_slots(_a15_slotarr->buf)[_a15_slotarr->offset + (size_t) l8];
                l9 = t0.payload.s;
                vader_array_t* _a16_slotarr = ((vader_array_t*) l12);
                if (_a16_slotarr->buf != NULL && _a16_slotarr->buf->header.forward != NULL) { _a16_slotarr->buf = vader_array_buf_forward(_a16_slotarr->buf); }
                if ((size_t) l8 >= _a16_slotarr->length) { vader_trap("array index out of bounds"); }
                l4 = vader_array_ref_load_obj(_a16_slotarr->buf, _a16_slotarr->offset + (size_t) l8);
                vader_struct___Tuple_string_Array_string__55ab4b78_t* _a17_obj = (vader_struct___Tuple_string_Array_string__55ab4b78_t*) vader_gc_alloc(sizeof(vader_struct___Tuple_string_Array_string__55ab4b78_t));
                vader_obj_header_init(_a17_obj, 235u);
                _a17_obj->f__0 = l9;
                _a17_obj->f__1 = l4;
                l13 = (void*) _a17_obj;
                l17 = ((vader_struct___Tuple_string_Array_string__55ab4b78_t*) l13)->f__0;
                l14 = ((vader_struct___Tuple_string_Array_string__55ab4b78_t*) l13)->f__1;
                t1 = (l8 + INT64_C(1));
                l8 = (size_t) (int64_t) t1;
                t5 = ((vader_array_t*) l14)->length;
                if ((t5 >= INT64_C(2))) {
                    std_collections_put__string__Any(l5, l17, vader_ref_box(l14));
                }
                goto loop_240;
            }
        }
    }
    { void* __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static bool vader_resolver_wildcard_exposable(int32_t l0) {
    bool l1;
    if (l0 == INT32_C(0)) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(1);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(2);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(3);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(5);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(6);
    }
    return l1;
}

void* vader_resolver_wire_imports(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l9 = NULL;
    size_t l6, l7;
    vader_string_t l8 = 0;
    vader_string_t l10 = 0;
    vader_string_t l11 = 0;
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    int64_t t2;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[8] = { &l0, &l1, &l2, &l3, &l4, &l5, &l9, &t1 };
    vader_struct___Tuple_2_122be429df783e3b_t _a6_storage = {0};
    void* gc_stack_objs[1] = { (void*) &_a6_storage };
    vader_string_t* gc_atom_roots[3] = { &l8, &l10, &l11 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 8u, gc_roots, gc_raw_roots, 1u, gc_stack_objs, 3u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l1 = vader_resolver_new_import_target_table();
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 169u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(8u, 0u, 0u, 169u);
    l3 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 172u);
    l4 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__string__string_t* _a3_obj = (vader_struct_std_collections_MutableMap__string__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__string_t));
    vader_obj_header_init(_a3_obj, 363u);
    _a3_obj->f_ekeys = l2;
    _a3_obj->f_evals = l3;
    _a3_obj->f_index = l4;
    _a3_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l2 = (void*) _a3_obj;
    l3 = ((vader_struct_vader_resolver_LoadedProject_t*) l0)->f_modules;
    l4 = ((vader_struct_std_collections_MutableMap__string__LoadedModule_t*) l3)->f_ekeys;
    l5 = ((vader_struct_std_collections_MutableMap__string__LoadedModule_t*) l3)->f_evals;
    l6 = ((vader_struct_std_collections_MutableMap__string__LoadedModule_t*) l3)->f_size;
    l7 = (size_t) (int64_t) INT64_C(0);
    {
        loop_28: {
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
                vader_struct___Tuple_2_122be429df783e3b_t* _a7_obj = &_a6_storage;
                vader_obj_header_init(_a7_obj, 202u);
                _a7_obj->f__0 = l8;
                _a7_obj->f__1 = l3;
                t1 = (void*) _a7_obj;
                l9 = ((vader_struct___Tuple_2_122be429df783e3b_t*) t1)->f__1;
                t2 = (l7 + INT64_C(1));
                l7 = (size_t) (int64_t) t2;
                l10 = ((vader_struct_vader_resolver_Module_t*) ((vader_struct_vader_resolver_LoadedModule_t*) l9)->f_module)->f_module_name;
                l11 = ((vader_struct_vader_resolver_Module_t*) ((vader_struct_vader_resolver_LoadedModule_t*) l9)->f_module)->f_id;
                std_collections_put__string__string(l2, l10, l11);
                goto loop_28;
            }
        }
    }
    l3 = ((vader_struct_vader_resolver_LoadedProject_t*) l0)->f_modules;
    l4 = ((vader_struct_std_collections_MutableMap__string__LoadedModule_t*) l3)->f_ekeys;
    l5 = ((vader_struct_std_collections_MutableMap__string__LoadedModule_t*) l3)->f_evals;
    l6 = ((vader_struct_std_collections_MutableMap__string__LoadedModule_t*) l3)->f_size;
    l7 = (size_t) (int64_t) INT64_C(0);
    {
        loop_80: {
            if ((l7 >= l6)) {
            } else {
                vader_array_t* _a8_slotarr = ((vader_array_t*) l4);
                if (_a8_slotarr->buf != NULL && _a8_slotarr->buf->header.forward != NULL) { _a8_slotarr->buf = vader_array_buf_forward(_a8_slotarr->buf); }
                if ((size_t) l7 >= _a8_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_box_slots(_a8_slotarr->buf)[_a8_slotarr->offset + (size_t) l7];
                l8 = t0.payload.s;
                vader_array_t* _a9_slotarr = ((vader_array_t*) l5);
                if (_a9_slotarr->buf != NULL && _a9_slotarr->buf->header.forward != NULL) { _a9_slotarr->buf = vader_array_buf_forward(_a9_slotarr->buf); }
                if ((size_t) l7 >= _a9_slotarr->length) { vader_trap("array index out of bounds"); }
                l3 = vader_array_ref_load_obj(_a9_slotarr->buf, _a9_slotarr->offset + (size_t) l7);
                vader_struct___Tuple_2_122be429df783e3b_t* _a10_obj = (vader_struct___Tuple_2_122be429df783e3b_t*) vader_gc_alloc(sizeof(vader_struct___Tuple_2_122be429df783e3b_t));
                vader_obj_header_init(_a10_obj, 202u);
                _a10_obj->f__0 = l8;
                _a10_obj->f__1 = l3;
                t1 = (void*) _a10_obj;
                l9 = ((vader_struct___Tuple_2_122be429df783e3b_t*) t1)->f__1;
                t2 = (l7 + INT64_C(1));
                l7 = (size_t) (int64_t) t2;
                vader_resolver_wire_module(l9, l2, l0, l1);
                goto loop_80;
            }
        }
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void vader_resolver_wire_module(void* l0, void* l1, void* l2, void* l3) {
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l10 = NULL;
    void* l12 = NULL;
    void* l15 = NULL;
    void* l19 = NULL;
    void* l23 = NULL;
    void* l24 = NULL;
    void* l27 = NULL;
    void* l28 = NULL;
    void* l29 = NULL;
    void* l31 = NULL;
    void* l32 = NULL;
    void* l33 = NULL;
    void* l35 = NULL;
    size_t l7, l8;
    int32_t l9, l11;
    vader_string_t l13 = 0;
    vader_string_t l16 = 0;
    vader_string_t l20 = 0;
    vader_string_t l21 = 0;
    vader_string_t l25 = 0;
    vader_string_t l26 = 0;
    vader_string_t l30 = 0;
    vader_string_t l34 = 0;
    vader_box_t l14 = vader_box_null(), l17 = vader_box_null(), l18 = vader_box_null(), l22 = vader_box_null();
    int64_t t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[4] = { &l14, &l17, &l18, &l22 };
    void** gc_raw_roots[21] = { &l0, &l1, &l2, &l3, &l4, &l5, &l6, &l10, &l12, &l15, &l19, &l23, &l24, &l27, &l28, &l29, &l31, &l32, &l33, &l35, &t1 };
    vader_string_t* gc_atom_roots[8] = { &l13, &l16, &l20, &l21, &l25, &l26, &l30, &l34 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 21u, gc_roots, gc_raw_roots, 0u, NULL, 8u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l4 = ((vader_struct_vader_resolver_CollectedModule_t*) ((vader_struct_vader_resolver_LoadedModule_t*) l0)->f_collected)->f_imports;
    l5 = ((vader_struct_std_collections_MutableMap__i32__ImportInfo_t*) l4)->f_ekeys;
    l6 = ((vader_struct_std_collections_MutableMap__i32__ImportInfo_t*) l4)->f_evals;
    l7 = ((vader_struct_std_collections_MutableMap__i32__ImportInfo_t*) l4)->f_size;
    l8 = (size_t) (int64_t) INT64_C(0);
    {
        loop_13: {
            if ((l8 >= l7)) {
                { vader_gc_top = gc_frame.prev; return; }
            }
            vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
            if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
            if ((size_t) l8 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
            l9 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l8];
            vader_array_t* _a1_slotarr = ((vader_array_t*) l6);
            if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
            if ((size_t) l8 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
            l4 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l8);
            vader_struct___Tuple_2_5e4ffda3bebebd74_t* _a2_obj = (vader_struct___Tuple_2_5e4ffda3bebebd74_t*) vader_gc_alloc(sizeof(vader_struct___Tuple_2_5e4ffda3bebebd74_t));
            vader_obj_header_init(_a2_obj, 206u);
            _a2_obj->f__0 = l9;
            _a2_obj->f__1 = l4;
            l10 = (void*) _a2_obj;
            l11 = ((vader_struct___Tuple_2_5e4ffda3bebebd74_t*) l10)->f__0;
            l12 = ((vader_struct___Tuple_2_5e4ffda3bebebd74_t*) l10)->f__1;
            t0 = (l8 + INT64_C(1));
            l8 = (size_t) (int64_t) t0;
            l13 = ((vader_struct_vader_resolver_ImportInfo_t*) l12)->f_path;
            l14 = std_collections_get__string__string(l1, l13);
            if (l14.tag == 0u) {
                std_collections_put__i32__bool(((vader_struct_vader_resolver_ImportTargetTable_t*) l3)->f_missing, l11, true);
                goto loop_13;
            }
            l15 = ((vader_struct_vader_resolver_LoadedProject_t*) l2)->f_modules;
            l16 = l14.payload.s;
            l17 = std_collections_get__string__Any(l15, l16);
            if (l17.tag == 0u) {
                std_collections_put__i32__bool(((vader_struct_vader_resolver_ImportTargetTable_t*) l3)->f_missing, l11, true);
                goto loop_13;
            }
            l18 = ((vader_struct_vader_resolver_ImportInfo_t*) l12)->f_imported_name;
            if (l18.tag == 0u) {
                l19 = ((vader_struct_vader_resolver_ImportTargetTable_t*) l3)->f_namespace_targets;
                l20 = l14.payload.s;
                std_collections_put__i32__string(l19, l11, l20);
            } else {
                if (l18.tag == 169u) {
                    l21 = l18.payload.s;
                    t1 = l17.payload.obj;
                    l22 = std_collections_get__string__Any(((vader_struct_vader_resolver_CollectedModule_t*) ((vader_struct_vader_resolver_LoadedModule_t*) t1)->f_collected)->f_symbols, l21);
                    if (l22.tag == 0u) {
                        std_collections_put__i32__bool(((vader_struct_vader_resolver_ImportTargetTable_t*) l3)->f_missing, l11, true);
                        l23 = ((vader_struct_vader_resolver_LoadedProject_t*) l2)->f_diags;
                        l24 = ((vader_struct_vader_resolver_ImportInfo_t*) l12)->f_binding_span;
                        l25 = ((vader_struct_vader_resolver_ImportInfo_t*) l12)->f_path;
                        l26 = concat_5(930u, l21, 959u, l25, 930u);
                        l27 = vader_diagnostics_resolver_error((uint8_t) (int32_t) INT32_C(2), l24, l26);
                        vader_array_push((vader_array_t*) l23, vader_ref_box(l27));
                    } else {
                        if (l22.tag == 889u) {
                            t1 = l22.payload.obj;
                            if (((vader_struct_vader_resolver_symbol_Symbol_t*) t1)->f_visibility == INT32_C(1)) {
                                std_collections_put__i32__bool(((vader_struct_vader_resolver_ImportTargetTable_t*) l3)->f_missing, l11, true);
                                l28 = ((vader_struct_vader_resolver_LoadedProject_t*) l2)->f_diags;
                                l29 = ((vader_struct_vader_resolver_ImportInfo_t*) l12)->f_binding_span;
                                l30 = concat_3(930u, l21, 930u);
                                l31 = vader_diagnostics_resolver_error((uint8_t) (int32_t) INT32_C(7), l29, l30);
                                vader_array_push((vader_array_t*) l28, vader_ref_box(l31));
                            } else {
                                l32 = ((vader_struct_vader_resolver_ImportTargetTable_t*) l3)->f_symbol_targets;
                                l33 = l22.payload.obj;
                                l34 = l14.payload.s;
                                vader_struct_vader_resolver_SymbolTarget_t* _a3_obj = (vader_struct_vader_resolver_SymbolTarget_t*) vader_gc_alloc(sizeof(vader_struct_vader_resolver_SymbolTarget_t));
                                vader_obj_header_init(_a3_obj, 887u);
                                _a3_obj->f_symbol = l33;
                                _a3_obj->f_module_id = l34;
                                l35 = (void*) _a3_obj;
                                std_collections_put__i32__Any(l32, l11, vader_ref_box(l35));
                            }
                        } else {
                            { vader_gc_top = gc_frame.prev; return; }
                        }
                    }
                } else {
                    { vader_gc_top = gc_frame.prev; return; }
                }
            }
            goto loop_13;
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_resolver_zero_span(vader_string_t l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[3] = { &l1, &l2, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_struct_toolchain_span_Position_t* _a0_obj = (vader_struct_toolchain_span_Position_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Position_t));
    vader_obj_header_init(_a0_obj, 481u);
    _a0_obj->f_file = l0;
    _a0_obj->f_offset = (size_t) (int64_t) INT64_C(0);
    _a0_obj->f_line = INT32_C(1);
    _a0_obj->f_column = INT32_C(1);
    l1 = (void*) _a0_obj;
    vader_struct_toolchain_span_Position_t* _a1_obj = (vader_struct_toolchain_span_Position_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Position_t));
    vader_obj_header_init(_a1_obj, 481u);
    _a1_obj->f_file = l0;
    _a1_obj->f_offset = (size_t) (int64_t) INT64_C(0);
    _a1_obj->f_line = INT32_C(1);
    _a1_obj->f_column = INT32_C(1);
    l2 = (void*) _a1_obj;
    vader_struct_toolchain_span_Span_t* _a2_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
    vader_obj_header_init(_a2_obj, 482u);
    _a2_obj->f_start = l1;
    _a2_obj->f_end = l2;
    t0 = (void*) _a2_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

