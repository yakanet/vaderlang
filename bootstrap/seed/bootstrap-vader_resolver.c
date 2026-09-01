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
    void* l12 = NULL;
    void* l13 = NULL;
    void* l16 = NULL;
    void* l18 = NULL;
    void* l19 = NULL;
    void* l21 = NULL;
    void* l22 = NULL;
    void* l26 = NULL;
    vader_string_t l8 = 0;
    vader_string_t l14 = 0;
    vader_string_t l17 = 0;
    vader_string_t l20 = 0;
    vader_string_t l23 = 0;
    vader_string_t l27 = 0;
    vader_box_t l9 = vader_box_null(), l15 = vader_box_null();
    bool l10;
    int32_t l11, l24, l25;
    vader_string_t t0 = 0;
    void* t1 = NULL;
    vader_box_t* gc_roots[2] = { &l9, &l15 };
    void** gc_raw_roots[14] = { &l0, &l1, &l4, &l5, &l7, &l12, &l13, &l16, &l18, &l19, &l21, &l22, &l26, &t1 };
    vader_string_t* gc_atom_roots[9] = { &l2, &l3, &l8, &l14, &l17, &l20, &l23, &l27, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 14u, gc_roots, gc_raw_roots, 0u, NULL, 9u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l6 = ((vader_struct_toolchain_ast_FnDecl_t*) l1)->f_visibility;
    t0 = ((vader_struct_toolchain_ast_FnDecl_t*) l1)->f_name;
    if (t0 == 1795u) {
        l6 = (uint8_t) (int32_t) INT32_C(0);
    } else {
    }
    l7 = ((vader_struct_vader_resolver_CollectedModule_t*) l0)->f_symbols;
    l8 = ((vader_struct_toolchain_ast_FnDecl_t*) l1)->f_name;
    l9 = std_collections_get__string__Any(l7, l8);
    if (l9.tag == 872u) {
        l7 = l9.payload.obj;
        if (((vader_struct_vader_resolver_symbol_Symbol_t*) l7)->f_kind != INT32_C(0)) {
            l10 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l7)->f_kind != INT32_C(7);
        } else {
            l10 = false;
        }
        if (l10) {
            l7 = ((vader_struct_toolchain_ast_FnDecl_t*) l1)->f_name_span;
            l8 = ((vader_struct_toolchain_ast_FnDecl_t*) l1)->f_name;
            l8 = concat_3(919u, l8, 927u);
            l7 = vader_diagnostics_resolver_error((uint8_t) (int32_t) INT32_C(3), l7, l8);
            vader_array_push((vader_array_t*) l5, vader_ref_box(l7));
            { vader_gc_top = gc_frame.prev; return; }
        }
        l11 = INT32_C(0);
        l8 = ((vader_struct_toolchain_ast_FnDecl_t*) l1)->f_name;
        l7 = ((vader_struct_toolchain_ast_FnDecl_t*) l1)->f_name_span;
        l12 = vader_resolver_symbol_make(l4, l11, l8, l2, l3, l6, vader_ref_box(l7));
        l13 = ((vader_struct_vader_resolver_CollectedModule_t*) l0)->f_fn_overloads;
        l14 = ((vader_struct_toolchain_ast_FnDecl_t*) l1)->f_name;
        l15 = std_collections_get__string__Any(l13, l14);
        if (l15.tag == 0u) {
            l16 = ((vader_struct_vader_resolver_CollectedModule_t*) l0)->f_fn_overloads;
            l17 = ((vader_struct_toolchain_ast_FnDecl_t*) l1)->f_name;
            vader_array_t* _a0_arr = vader_array_new(88u, 1u, 13u, 872u);
            ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = l12;
            l18 = (void*) _a0_arr;
            std_collections_put__string__Any(l16, l17, vader_ref_box(l18));
        } else {
            t1 = l15.payload.obj;
            vader_array_push((vader_array_t*) t1, vader_ref_box(l12));
            l19 = ((vader_struct_vader_resolver_CollectedModule_t*) l0)->f_fn_overloads;
            l20 = ((vader_struct_toolchain_ast_FnDecl_t*) l1)->f_name;
            l21 = l15.payload.obj;
            std_collections_put__string__Any(l19, l20, vader_ref_box(l21));
        }
        if (l9.tag == 0u) {
            l22 = ((vader_struct_vader_resolver_CollectedModule_t*) l0)->f_symbols;
            l23 = ((vader_struct_toolchain_ast_FnDecl_t*) l1)->f_name;
            std_collections_put__string__Any(l22, l23, vader_ref_box(l12));
            { vader_gc_top = gc_frame.prev; return; }
        }
        if (l9.tag == 872u) {
            t1 = l9.payload.obj;
            l24 = ((vader_struct_vader_resolver_symbol_Symbol_t*) t1)->f_kind;
            l25 = INT32_C(7);
            if (l24 == l25) {
                l26 = ((vader_struct_vader_resolver_CollectedModule_t*) l0)->f_symbols;
                l27 = ((vader_struct_toolchain_ast_FnDecl_t*) l1)->f_name;
                std_collections_put__string__Any(l26, l27, vader_ref_box(l12));
            } else {
            }
            { vader_gc_top = gc_frame.prev; return; }
        }
        { vader_gc_top = gc_frame.prev; return; }
    }
    l11 = INT32_C(0);
    l8 = ((vader_struct_toolchain_ast_FnDecl_t*) l1)->f_name;
    l7 = ((vader_struct_toolchain_ast_FnDecl_t*) l1)->f_name_span;
    l12 = vader_resolver_symbol_make(l4, l11, l8, l2, l3, l6, vader_ref_box(l7));
    l13 = ((vader_struct_vader_resolver_CollectedModule_t*) l0)->f_fn_overloads;
    l14 = ((vader_struct_toolchain_ast_FnDecl_t*) l1)->f_name;
    l15 = std_collections_get__string__Any(l13, l14);
    if (l15.tag == 0u) {
        l16 = ((vader_struct_vader_resolver_CollectedModule_t*) l0)->f_fn_overloads;
        l17 = ((vader_struct_toolchain_ast_FnDecl_t*) l1)->f_name;
        vader_array_t* _a1_arr = vader_array_new(88u, 1u, 13u, 872u);
        ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = l12;
        l18 = (void*) _a1_arr;
        std_collections_put__string__Any(l16, l17, vader_ref_box(l18));
    } else {
        t1 = l15.payload.obj;
        vader_array_push((vader_array_t*) t1, vader_ref_box(l12));
        l19 = ((vader_struct_vader_resolver_CollectedModule_t*) l0)->f_fn_overloads;
        l20 = ((vader_struct_toolchain_ast_FnDecl_t*) l1)->f_name;
        l21 = l15.payload.obj;
        std_collections_put__string__Any(l19, l20, vader_ref_box(l21));
    }
    if (l9.tag == 0u) {
        l22 = ((vader_struct_vader_resolver_CollectedModule_t*) l0)->f_symbols;
        l23 = ((vader_struct_toolchain_ast_FnDecl_t*) l1)->f_name;
        std_collections_put__string__Any(l22, l23, vader_ref_box(l12));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l9.tag == 872u) {
        t1 = l9.payload.obj;
        l24 = ((vader_struct_vader_resolver_symbol_Symbol_t*) t1)->f_kind;
        l25 = INT32_C(7);
        if (l24 == l25) {
            l26 = ((vader_struct_vader_resolver_CollectedModule_t*) l0)->f_symbols;
            l27 = ((vader_struct_toolchain_ast_FnDecl_t*) l1)->f_name;
            std_collections_put__string__Any(l26, l27, vader_ref_box(l12));
        } else {
        }
        { vader_gc_top = gc_frame.prev; return; }
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
    if (l9.tag == 872u) {
        l10 = concat_3(919u, l2, 927u);
        l11 = vader_diagnostics_resolver_error((uint8_t) (int32_t) INT32_C(3), l3, l10);
        vader_array_push((vader_array_t*) l8, vader_ref_box(l11));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l9.tag == 0u) {
        l11 = vader_resolver_symbol_make(l7, l1, l2, l5, l6, l4, vader_ref_box(l3));
        std_collections_put__string__Any(((vader_struct_vader_resolver_CollectedModule_t*) l0)->f_symbols, l2, vader_ref_box(l11));
        { vader_gc_top = gc_frame.prev; return; }
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
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 161u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(15u, 0u, 0u, 171u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 164u);
    l3 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__string__Any___t* _a3_obj = (vader_struct_std_collections_MutableMap__string__Any___t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__Any___t));
    vader_obj_header_init(_a3_obj, 311u);
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
            } else {
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
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 161u);
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
            } else {
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
                if (l4.tag == 384u) {
                    return true;
                }
                if (l4.tag == 0u) {
                    t1 = (l3 + INT64_C(1));
                    l3 = (size_t) (int64_t) t1;
                    goto loop_7;
                }
                vader_unreachable("unreachable return in vader_resolver$any_has_body");
            } else {
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
    if (!(l1.tag == 411u)) {
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
                if (l5.tag == 412u) {
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
                    } else {
                    }
                } else {
                }
                t2 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t2;
                goto loop_15;
            } else {
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
    void* l3 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    vader_box_t l4 = vader_box_null();
    vader_string_t l7 = 0;
    vader_string_t t0 = 0;
    void* t1 = NULL;
    vader_box_t* gc_roots[2] = { &l1, &l4 };
    void** gc_raw_roots[5] = { &l0, &l3, &l5, &l6, &t1 };
    vader_string_t* gc_atom_roots[2] = { &l7, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    if (l1.tag == 382u) {
        l3 = l1.payload.obj;
        if (((vader_struct_toolchain_ast_BinaryExpr_t*) l3)->f_op == INT32_C(10)) {
            l4 = ((vader_struct_toolchain_ast_BinaryExpr_t*) l3)->f_left;
            vader_resolver_bind_cond_is_as(l0, l4, true);
            l4 = ((vader_struct_toolchain_ast_BinaryExpr_t*) l3)->f_right;
            vader_resolver_bind_cond_is_as(l0, l4, true);
            { vader_gc_top = gc_frame.prev; return; }
        }
        if (((vader_struct_toolchain_ast_BinaryExpr_t*) l3)->f_op == INT32_C(18)) {
            l4 = ((vader_struct_toolchain_ast_BinaryExpr_t*) l3)->f_left;
            vader_resolver_walk_expr(l0, l4);
            l4 = ((vader_struct_toolchain_ast_BinaryExpr_t*) l3)->f_right;
            vader_resolver_walk_expr(l0, l4);
            t0 = ((vader_struct_toolchain_ast_BinaryExpr_t*) l3)->f_bind_as;
            if (t0 != 0u) {
                if (l2) {
                    l5 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_diags;
                    t1 = ((vader_struct_toolchain_ast_BinaryExpr_t*) l3)->f_right.payload.obj;
                    l6 = ((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t1)->f_span;
                    l6 = vader_diagnostics_resolver_error((uint8_t) (int32_t) INT32_C(28), l6, 1154u);
                    vader_array_push((vader_array_t*) l5, vader_ref_box(l6));
                } else {
                }
                l7 = ((vader_struct_toolchain_ast_BinaryExpr_t*) l3)->f_bind_as;
                t1 = ((vader_struct_toolchain_ast_BinaryExpr_t*) l3)->f_right.payload.obj;
                l5 = ((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t1)->f_span;
                l5 = vader_resolver_mint_local(l0, INT32_C(11), l7, l5);
                l6 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_scope;
                l7 = ((vader_struct_toolchain_ast_BinaryExpr_t*) l3)->f_bind_as;
                vader_resolver_bind(l6, l7, l5);
            } else {
            }
            { vader_gc_top = gc_frame.prev; return; }
        }
        vader_resolver_walk_expr(l0, l1);
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_resolver_walk_expr(l0, l1);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_resolver_bind_import(void* l0, vader_string_t l1, void* l2, vader_string_t l3, vader_box_t l4, vader_string_t l5, void* l6, void* l7) {
    vader_box_t l8 = vader_box_null(), l12 = vader_box_null();
    void* l9 = NULL;
    void* l10 = NULL;
    int32_t l11;
    bool l13;
    vader_string_t l14 = 0;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    vader_box_t* gc_roots[3] = { &l4, &l8, &l12 };
    void** gc_raw_roots[7] = { &l0, &l2, &l6, &l7, &l9, &l10, &t0 };
    vader_string_t* gc_atom_roots[5] = { &l1, &l3, &l5, &l14, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 5u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l8 = std_collections_get__string__Any(((vader_struct_vader_resolver_CollectedModule_t*) l0)->f_symbols, l1);
    if (l8.tag == 872u) {
        l9 = l8.payload.obj;
        if (((vader_struct_vader_resolver_symbol_Symbol_t*) l9)->f_kind == INT32_C(7)) {
            l10 = ((vader_struct_vader_resolver_CollectedModule_t*) l0)->f_imports;
            l11 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l9)->f_id;
            l12 = std_collections_get__i32__Any(l10, l11);
            if (!(l12.tag == 0u)) {
                t0 = l12.payload.obj;
                t1 = ((vader_struct_vader_resolver_ImportInfo_t*) t0)->f_path;
                if (t1 == l3) {
                    t0 = l12.payload.obj;
                    l13 = vader_resolver_names_equal(((vader_struct_vader_resolver_ImportInfo_t*) t0)->f_imported_name, l4);
                } else {
                    l13 = false;
                }
                l13 = !(l13);
            } else {
                l13 = false;
            }
            if (l13) {
                l14 = concat_3(919u, l1, 919u);
                l10 = vader_diagnostics_resolver_error((uint8_t) (int32_t) INT32_C(10), l2, l14);
                vader_array_push((vader_array_t*) l7, vader_ref_box(l10));
            } else {
            }
        } else {
            if (((vader_struct_vader_resolver_symbol_Symbol_t*) l9)->f_kind == INT32_C(0)) {
                l9 = vader_resolver_symbol_make(l6, INT32_C(7), l1, l5, l5, (uint8_t) (int32_t) INT32_C(1), vader_ref_box(l2));
                l10 = ((vader_struct_vader_resolver_CollectedModule_t*) l0)->f_imports;
                l11 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l9)->f_id;
                vader_struct_vader_resolver_ImportInfo_t* _a0_obj = (vader_struct_vader_resolver_ImportInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_resolver_ImportInfo_t));
                vader_obj_header_init(_a0_obj, 856u);
                _a0_obj->f_path = l3;
                _a0_obj->f_imported_name = l4;
                _a0_obj->f_local = l1;
                _a0_obj->f_binding_span = l2;
                l9 = (void*) _a0_obj;
                std_collections_put__i32__Any(l10, l11, vader_ref_box(l9));
            } else {
                l14 = concat_3(919u, l1, 919u);
                l9 = vader_diagnostics_resolver_error((uint8_t) (int32_t) INT32_C(10), l2, l14);
                vader_array_push((vader_array_t*) l7, vader_ref_box(l9));
            }
        }
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l8.tag == 0u) {
        l9 = vader_resolver_symbol_make(l6, INT32_C(7), l1, l5, l5, (uint8_t) (int32_t) INT32_C(1), vader_ref_box(l2));
        std_collections_put__string__Any(((vader_struct_vader_resolver_CollectedModule_t*) l0)->f_symbols, l1, vader_ref_box(l9));
        l10 = ((vader_struct_vader_resolver_CollectedModule_t*) l0)->f_imports;
        l11 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l9)->f_id;
        vader_struct_vader_resolver_ImportInfo_t* _a1_obj = (vader_struct_vader_resolver_ImportInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_resolver_ImportInfo_t));
        vader_obj_header_init(_a1_obj, 856u);
        _a1_obj->f_path = l3;
        _a1_obj->f_imported_name = l4;
        _a1_obj->f_local = l1;
        _a1_obj->f_binding_span = l2;
        l9 = (void*) _a1_obj;
        std_collections_put__i32__Any(l10, l11, vader_ref_box(l9));
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_resolver_bind_let_binding(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    vader_string_t l3 = 0;
    uint64_t l6;
    size_t l7, l8;
    vader_box_t l9 = vader_box_null();
    void* t0 = NULL;
    int64_t t1;
    vader_box_t* gc_roots[2] = { &l1, &l9 };
    void** gc_raw_roots[5] = { &l0, &l2, &l4, &l5, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    if (l1.tag == 445u) {
        l2 = l1.payload.obj;
        l3 = ((vader_struct_toolchain_ast_SimpleBinding_t*) l2)->f_name;
        l4 = ((vader_struct_toolchain_ast_SimpleBinding_t*) l2)->f_name_span;
        l4 = vader_resolver_bind_local_checked(l0, INT32_C(10), l3, l4);
        l5 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_idents;
        l6 = toolchain_span_Span_Hash_hash(((vader_struct_toolchain_ast_SimpleBinding_t*) l2)->f_name_span);
        std_collections_put__u64__Any(l5, l6, vader_ref_box(l4));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 457u) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_toolchain_ast_TupleBinding_t*) t0)->f_elements;
        l7 = ((vader_array_t*) l2)->length;
        l8 = (size_t) (int64_t) INT64_C(0);
        {
            loop_40: {
                if ((l8 < l7)) {
                    vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
                    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                    if ((size_t) l8 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                    l9 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l8);
                    vader_resolver_bind_let_binding(l0, l9);
                    t1 = (l8 + INT64_C(1));
                    l8 = (size_t) (int64_t) t1;
                    goto loop_40;
                } else {
                }
            }
        }
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 463u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 442u) {
        l2 = l1.payload.obj;
        l3 = ((vader_struct_toolchain_ast_RestBinding_t*) l2)->f_name;
        l4 = ((vader_struct_toolchain_ast_RestBinding_t*) l2)->f_span;
        l4 = vader_resolver_bind_local_checked(l0, INT32_C(10), l3, l4);
        l5 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_idents;
        l6 = toolchain_span_Span_Hash_hash(((vader_struct_toolchain_ast_RestBinding_t*) l2)->f_span);
        std_collections_put__u64__Any(l5, l6, vader_ref_box(l4));
        { vader_gc_top = gc_frame.prev; return; }
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
    if (l2 == 859u) {
        l4 = -(INT32_C(1));
    } else {
        l4 = vader_resolver_lookup_frame_index(((vader_struct_vader_resolver_ResolveState_t*) l0)->f_scope, l2);
    }
    if ((l4 > INT32_C(0))) {
        t0 = vader_resolver_frame_count(((vader_struct_vader_resolver_ResolveState_t*) l0)->f_scope);
        l5 = (t0 - INT32_C(1));
        if (l4 == l5) {
            l6 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_diags;
            l7 = concat_3(919u, l2, 919u);
            l8 = vader_diagnostics_warning((uint8_t) (int32_t) INT32_C(5), l3, l7);
            vader_array_push((vader_array_t*) l6, vader_ref_box(l8));
        } else {
            l6 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_diags;
            l7 = concat_3(919u, l2, 919u);
            l8 = vader_diagnostics_warning((uint8_t) (int32_t) INT32_C(4), l3, l7);
            vader_array_push((vader_array_t*) l6, vader_ref_box(l8));
        }
    } else {
    }
    l6 = vader_resolver_mint_local(l0, l1, l2, l3);
    vader_resolver_bind(((vader_struct_vader_resolver_ResolveState_t*) l0)->f_scope, l2, l6);
    { void* __vret = l6; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void vader_resolver_bind_pattern(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    void* l5 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    vader_box_t l3 = vader_box_null(), l6 = vader_box_null();
    vader_string_t l4 = 0;
    vader_string_t l12 = 0;
    size_t l7, l8, l13;
    void* t0 = NULL;
    int64_t t1;
    vader_box_t* gc_roots[3] = { &l1, &l3, &l6 };
    void** gc_raw_roots[7] = { &l0, &l2, &l5, &l9, &l10, &l11, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l4, &l12 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    if (l1.tag == 424u) {
        l2 = l1.payload.obj;
        l3 = ((vader_struct_toolchain_ast_IsPattern_t*) l2)->f_ty;
        vader_resolver_walk_expr(l0, l3);
        l3 = ((vader_struct_toolchain_ast_IsPattern_t*) l2)->f_bind_as;
        if (l3.tag == 0u) {
            if (!(((vader_struct_toolchain_ast_IsPattern_t*) l2)->f_inner.tag == 0u)) {
                l6 = ((vader_struct_toolchain_ast_IsPattern_t*) l2)->f_inner;
                vader_resolver_bind_pattern(l0, l6);
            } else {
            }
            { vader_gc_top = gc_frame.prev; return; }
        }
        if (l3.tag == 161u) {
            l4 = l3.payload.s;
            l5 = ((vader_struct_toolchain_ast_IsPattern_t*) l2)->f_span;
            l5 = vader_resolver_mint_local(l0, INT32_C(11), l4, l5);
            vader_resolver_bind(((vader_struct_vader_resolver_ResolveState_t*) l0)->f_scope, l4, l5);
            if (!(((vader_struct_toolchain_ast_IsPattern_t*) l2)->f_inner.tag == 0u)) {
                l6 = ((vader_struct_toolchain_ast_IsPattern_t*) l2)->f_inner;
                vader_resolver_bind_pattern(l0, l6);
            } else {
            }
            { vader_gc_top = gc_frame.prev; return; }
        }
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 454u) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_toolchain_ast_StructPattern_t*) t0)->f_fields;
        l7 = ((vader_array_t*) l2)->length;
        l8 = (size_t) (int64_t) INT64_C(0);
        {
            loop_73: {
                if ((l8 < l7)) {
                    vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
                    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                    if ((size_t) l8 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                    l5 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l8);
                    l3 = ((vader_struct_toolchain_ast_StructPatternField_t*) l5)->f_value;
                    if (l3.tag == 437u) {
                        l4 = ((vader_struct_toolchain_ast_StructPatternField_t*) l5)->f_name;
                        l9 = ((vader_struct_toolchain_ast_StructPatternField_t*) l5)->f_name_span;
                        l10 = vader_resolver_mint_local(l0, INT32_C(11), l4, l9);
                        l11 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_scope;
                        l12 = ((vader_struct_toolchain_ast_StructPatternField_t*) l5)->f_name;
                        vader_resolver_bind(l11, l12, l10);
                        l13 = (size_t) (int64_t) INT64_C(1);
                        t1 = (l8 + l13);
                        l8 = (size_t) (int64_t) t1;
                        goto loop_73;
                    }
                    if (l3.tag == 438u) {
                        t0 = l3.payload.obj;
                        l6 = ((vader_struct_toolchain_ast_PatternLiteral_t*) t0)->f_value;
                        vader_resolver_walk_expr(l0, l6);
                        l13 = (size_t) (int64_t) INT64_C(1);
                        t1 = (l8 + l13);
                        l8 = (size_t) (int64_t) t1;
                        goto loop_73;
                    }
                    { vader_gc_top = gc_frame.prev; return; }
                } else {
                }
            }
        }
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 458u) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_toolchain_ast_TuplePattern_t*) t0)->f_elements;
        l7 = ((vader_array_t*) l2)->length;
        l8 = (size_t) (int64_t) INT64_C(0);
        {
            loop_151: {
                if ((l8 < l7)) {
                    vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
                    if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                    if ((size_t) l8 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                    l3 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l8);
                    vader_resolver_bind_pattern(l0, l3);
                    t1 = (l8 + INT64_C(1));
                    l8 = (size_t) (int64_t) t1;
                    goto loop_151;
                } else {
                }
            }
        }
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 465u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 383u) {
        l2 = l1.payload.obj;
        l4 = ((vader_struct_toolchain_ast_BindingPattern_t*) l2)->f_name;
        l5 = ((vader_struct_toolchain_ast_BindingPattern_t*) l2)->f_span;
        l5 = vader_resolver_mint_local(l0, INT32_C(11), l4, l5);
        l9 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_scope;
        l4 = ((vader_struct_toolchain_ast_BindingPattern_t*) l2)->f_name;
        vader_resolver_bind(l9, l4, l5);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 403u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 427u) {
        t0 = l1.payload.obj;
        l3 = ((vader_struct_toolchain_ast_LiteralPattern_t*) t0)->f_value;
        vader_resolver_walk_expr(l0, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 441u) {
        l2 = l1.payload.obj;
        l3 = ((vader_struct_toolchain_ast_RangePattern_t*) l2)->f_lower;
        vader_resolver_walk_expr(l0, l3);
        l3 = ((vader_struct_toolchain_ast_RangePattern_t*) l2)->f_upper;
        vader_resolver_walk_expr(l0, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 436u) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_toolchain_ast_OrPattern_t*) t0)->f_patterns;
        l7 = ((vader_array_t*) l2)->length;
        l8 = (size_t) (int64_t) INT64_C(0);
        {
            loop_254: {
                if ((l8 < l7)) {
                    vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
                    if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                    if ((size_t) l8 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                    l3 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l8);
                    vader_resolver_bind_pattern(l0, l3);
                    t1 = (l8 + INT64_C(1));
                    l8 = (size_t) (int64_t) t1;
                    goto loop_254;
                } else {
                }
            }
        }
        { vader_gc_top = gc_frame.prev; return; }
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
    size_t l4, l5, l7, l8, l13;
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
                            if (l9.tag == 407u) {
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
                                    l13 = (size_t) (int64_t) INT64_C(1);
                                    t2 = (l8 + l13);
                                    l8 = (size_t) (int64_t) t2;
                                    goto loop_29;
                                }
                                l13 = (size_t) (int64_t) INT64_C(1);
                                t2 = (l8 + l13);
                                l8 = (size_t) (int64_t) t2;
                                goto loop_29;
                            }
                            l13 = (size_t) (int64_t) INT64_C(1);
                            t2 = (l8 + l13);
                            l8 = (size_t) (int64_t) t2;
                            goto loop_29;
                        } else {
                        }
                    }
                }
                t2 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t2;
                goto loop_13;
            } else {
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
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 161u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(15u, 0u, 0u, 171u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 164u);
    l3 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__string__Any_t* _a3_obj = (vader_struct_std_collections_MutableMap__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__Any_t));
    vader_obj_header_init(_a3_obj, 309u);
    _a3_obj->f_ekeys = l1;
    _a3_obj->f_evals = l2;
    _a3_obj->f_index = l3;
    _a3_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l1 = (void*) _a3_obj;
    l4 = std_collections_get__string__Any(((vader_struct_vader_resolver_LoadedProject_t*) l0)->f_modules, 504u);
    if (l4.tag == 859u) {
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
                    vader_struct___Tuple_1124_t* _a6_obj = (vader_struct___Tuple_1124_t*) vader_gc_alloc(sizeof(vader_struct___Tuple_1124_t));
                    vader_obj_header_init(_a6_obj, 192u);
                    _a6_obj->f__0 = l8;
                    _a6_obj->f__1 = l2;
                    l9 = (void*) _a6_obj;
                    l10 = ((vader_struct___Tuple_1124_t*) l9)->f__0;
                    l11 = ((vader_struct___Tuple_1124_t*) l9)->f__1;
                    t2 = (l7 + INT64_C(1));
                    l7 = (size_t) (int64_t) t2;
                    std_collections_put__string__Any(l1, l10, vader_ref_box(l11));
                    goto loop_35;
                }
            }
        }
    } else {
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
        loop_109: {
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
                vader_struct___Tuple_1124_t* _a9_obj = (vader_struct___Tuple_1124_t*) vader_gc_alloc(sizeof(vader_struct___Tuple_1124_t));
                vader_obj_header_init(_a9_obj, 192u);
                _a9_obj->f__0 = l8;
                _a9_obj->f__1 = l2;
                l9 = (void*) _a9_obj;
                l10 = ((vader_struct___Tuple_1124_t*) l9)->f__0;
                l11 = ((vader_struct___Tuple_1124_t*) l9)->f__1;
                t2 = (l7 + INT64_C(1));
                l7 = (size_t) (int64_t) t2;
                std_collections_put__string__Any(l1, l10, vader_ref_box(l11));
                goto loop_109;
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
    vader_resolver_bind_1(l2, 733u, l3);
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
            } else {
            }
        }
    }
    l5 = ((vader_array_t*) ((vader_struct_toolchain_ast_TraitDecl_t*) l1)->f_type_params)->length;
    {
        loop_53: {
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
                    goto loop_53;
                }
            } else {
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
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 161u);
    l4 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(15u, 0u, 0u, 171u);
    l5 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 164u);
    l6 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__string__Any_t* _a3_obj = (vader_struct_std_collections_MutableMap__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__Any_t));
    vader_obj_header_init(_a3_obj, 309u);
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
                vader_struct___Tuple_1124_t* _a6_obj = (vader_struct___Tuple_1124_t*) vader_gc_alloc(sizeof(vader_struct___Tuple_1124_t));
                vader_obj_header_init(_a6_obj, 192u);
                _a6_obj->f__0 = l10;
                _a6_obj->f__1 = l5;
                l11 = (void*) _a6_obj;
                l12 = ((vader_struct___Tuple_1124_t*) l11)->f__0;
                l13 = ((vader_struct___Tuple_1124_t*) l11)->f__1;
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
                            vader_struct___Tuple_1124_t* _a10_obj = (vader_struct___Tuple_1124_t*) vader_gc_alloc(sizeof(vader_struct___Tuple_1124_t));
                            vader_obj_header_init(_a10_obj, 192u);
                            _a10_obj->f__0 = l12;
                            _a10_obj->f__1 = l18;
                            t3 = (void*) _a10_obj;
                            l19 = ((vader_struct___Tuple_1124_t*) t3)->f__1;
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
                            } else {
                            }
                            goto loop_119;
                        }
                    }
                }
                t2 = (l9 + INT64_C(1));
                l9 = (size_t) (int64_t) t2;
                goto loop_77;
            } else {
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
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 161u);
    l0 = (void*) _a0_arr;
    l1 = (void*) &vader_data_9;
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
                vader_array_push((vader_array_t*) l0, vader_box_string(161u, l4));
                t1 = (l3 + INT64_C(1));
                l3 = (size_t) (int64_t) t1;
                goto loop_9;
            } else {
            }
        }
    }
    l1 = (void*) &vader_data_10;
    l2 = ((vader_array_t*) l1)->length;
    l3 = (size_t) (int64_t) INT64_C(0);
    {
        loop_39: {
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
                vader_array_push((vader_array_t*) l0, vader_box_string(161u, l4));
                t1 = (l3 + INT64_C(1));
                l3 = (size_t) (int64_t) t1;
                goto loop_39;
            } else {
            }
        }
    }
    l1 = (void*) &vader_data_6;
    l2 = ((vader_array_t*) l1)->length;
    l3 = (size_t) (int64_t) INT64_C(0);
    {
        loop_70: {
            if ((l3 < l2)) {
                vader_array_t* _a4_slotarr = ((vader_array_t*) l1);
                if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                if ((size_t) l3 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                t2 = vader_array_box_slots(_a4_slotarr->buf)[_a4_slotarr->offset + (size_t) l3];
                l4 = t2.payload.s;
                vader_array_push((vader_array_t*) l0, vader_box_string(161u, l4));
                t1 = (l3 + INT64_C(1));
                l3 = (size_t) (int64_t) t1;
                goto loop_70;
            } else {
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
    void* l11 = NULL;
    void* l18 = NULL;
    void* l22 = NULL;
    void* l25 = NULL;
    void* l26 = NULL;
    void* l27 = NULL;
    void* l34 = NULL;
    void* l35 = NULL;
    void* l58 = NULL;
    void* l59 = NULL;
    void* l60 = NULL;
    size_t l6, l7, l8, l9, l15, l16, l24, l61;
    vader_box_t l10 = vader_box_null(), l12 = vader_box_null(), l14 = vader_box_null(), l32 = vader_box_null();
    vader_string_t l13 = 0;
    vader_string_t l17 = 0;
    vader_string_t l19 = 0;
    vader_string_t l20 = 0;
    vader_string_t l21 = 0;
    vader_string_t l23 = 0;
    vader_string_t l29 = 0;
    vader_string_t l30 = 0;
    vader_string_t l31 = 0;
    vader_string_t l33 = 0;
    vader_string_t l36 = 0;
    vader_string_t l37 = 0;
    vader_string_t l38 = 0;
    vader_string_t l40 = 0;
    vader_string_t l45 = 0;
    vader_string_t l46 = 0;
    vader_string_t l47 = 0;
    vader_string_t l48 = 0;
    vader_string_t l50 = 0;
    vader_string_t l55 = 0;
    vader_string_t l56 = 0;
    uint8_t l28, l39, l41, l42, l43, l44, l49, l51, l52, l53, l54, l57;
    void* t0 = NULL;
    int64_t t1;
    bool t2;
    vader_box_t t3 = vader_box_null();
    vader_box_t* gc_roots[5] = { &l10, &l12, &l14, &l32, &t3 };
    void** gc_raw_roots[18] = { &l0, &l1, &l2, &l3, &l4, &l5, &l11, &l18, &l22, &l25, &l26, &l27, &l34, &l35, &l58, &l59, &l60, &t0 };
    vader_string_t* gc_atom_roots[21] = { &l13, &l17, &l19, &l20, &l21, &l23, &l29, &l30, &l31, &l33, &l36, &l37, &l38, &l40, &l45, &l46, &l47, &l48, &l50, &l55, &l56 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 5u, 18u, gc_roots, gc_raw_roots, 0u, NULL, 21u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 161u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(15u, 0u, 0u, 171u);
    l3 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 164u);
    l4 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__string__Any_t* _a3_obj = (vader_struct_std_collections_MutableMap__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__Any_t));
    vader_obj_header_init(_a3_obj, 309u);
    _a3_obj->f_ekeys = l2;
    _a3_obj->f_evals = l3;
    _a3_obj->f_index = l4;
    _a3_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l2 = (void*) _a3_obj;
    vader_array_t* _a4_arr = vader_array_new(8u, 0u, 0u, 161u);
    l3 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_new(15u, 0u, 0u, 171u);
    l4 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(9u, 0u, 7u, 164u);
    l5 = (void*) _a6_arr;
    vader_struct_std_collections_MutableMap__string__Any_t* _a7_obj = (vader_struct_std_collections_MutableMap__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__Any_t));
    vader_obj_header_init(_a7_obj, 309u);
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
                            if (l10.tag == 407u) {
                                l11 = l10.payload.obj;
                                l12 = vader_resolver_target_selectors(((vader_struct_toolchain_ast_FnDecl_t*) l11)->f_decorators);
                                if (l12.tag == 0u) {
                                    t1 = (l9 + INT64_C(1));
                                    l9 = (size_t) (int64_t) t1;
                                    goto loop_51;
                                }
                                t0 = l12.payload.obj;
                                t2 = ((vader_struct_vader_resolver_TargetSelectors_t*) t0)->f_is_bare;
                                if (!(t2)) {
                                    t1 = (l9 + INT64_C(1));
                                    l9 = (size_t) (int64_t) t1;
                                    goto loop_51;
                                }
                                l13 = ((vader_struct_toolchain_ast_FnDecl_t*) l11)->f_name;
                                l14 = std_collections_get__string__Any(l2, l13);
                                if (!(l14.tag == 0u)) {
                                    t0 = l14.payload.obj;
                                    l15 = ((vader_array_t*) ((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_params)->length;
                                    l16 = ((vader_array_t*) ((vader_struct_toolchain_ast_FnDecl_t*) l11)->f_params)->length;
                                    if (l15 != l16) {
                                        l17 = 228u;
                                    } else {
                                        l17 = 0u;
                                    }
                                    l18 = ((vader_struct_toolchain_ast_FnDecl_t*) l11)->f_name_span;
                                    l19 = ((vader_struct_toolchain_ast_FnDecl_t*) l11)->f_name;
                                    t0 = l14.payload.obj;
                                    l20 = vader_resolver_span_origin(((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_name_span);
                                    l21 = concat_5(919u, l19, 963u, l20, l17);
                                    l22 = vader_diagnostics_resolver_error((uint8_t) (int32_t) INT32_C(38), l18, l21);
                                    vader_array_push((vader_array_t*) l1, vader_ref_box(l22));
                                    t1 = (l9 + INT64_C(1));
                                    l9 = (size_t) (int64_t) t1;
                                    goto loop_51;
                                }
                                l23 = ((vader_struct_toolchain_ast_FnDecl_t*) l11)->f_name;
                                std_collections_put__string__Any(l2, l23, vader_ref_box(l11));
                                l24 = (size_t) (int64_t) INT64_C(1);
                                t1 = (l9 + l24);
                                l9 = (size_t) (int64_t) t1;
                                goto loop_51;
                            }
                            l24 = (size_t) (int64_t) INT64_C(1);
                            t1 = (l9 + l24);
                            l9 = (size_t) (int64_t) t1;
                            goto loop_51;
                        } else {
                        }
                    }
                }
                t1 = (l7 + INT64_C(1));
                l7 = (size_t) (int64_t) t1;
                goto loop_35;
            } else {
            }
        }
    }
    l4 = l0;
    l6 = ((vader_array_t*) l4)->length;
    l7 = (size_t) (int64_t) INT64_C(0);
    {
        loop_189: {
            if ((l7 < l6)) {
                vader_array_t* _a10_slotarr = ((vader_array_t*) l4);
                if (_a10_slotarr->buf != NULL && _a10_slotarr->buf->header.forward != NULL) { _a10_slotarr->buf = vader_array_buf_forward(_a10_slotarr->buf); }
                if ((size_t) l7 >= _a10_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_ref_load_obj(_a10_slotarr->buf, _a10_slotarr->offset + (size_t) l7);
                l5 = ((vader_struct_toolchain_ast_Program_t*) ((vader_struct_vader_resolver_SourceFile_t*) t0)->f_program)->f_decls;
                l8 = ((vader_array_t*) l5)->length;
                l9 = (size_t) (int64_t) INT64_C(0);
                {
                    loop_205: {
                        if ((l9 < l8)) {
                            vader_array_t* _a11_slotarr = ((vader_array_t*) l5);
                            if (_a11_slotarr->buf != NULL && _a11_slotarr->buf->header.forward != NULL) { _a11_slotarr->buf = vader_array_buf_forward(_a11_slotarr->buf); }
                            if ((size_t) l9 >= _a11_slotarr->length) { vader_trap("array index out of bounds"); }
                            l10 = vader_array_ref_load_box(_a11_slotarr->buf, _a11_slotarr->offset + (size_t) l9);
                            if (l10.tag == 407u) {
                                l11 = l10.payload.obj;
                                l12 = vader_resolver_target_selectors(((vader_struct_toolchain_ast_FnDecl_t*) l11)->f_decorators);
                                if (l12.tag == 0u) {
                                    t1 = (l9 + INT64_C(1));
                                    l9 = (size_t) (int64_t) t1;
                                    goto loop_205;
                                }
                                t0 = l12.payload.obj;
                                t2 = ((vader_struct_vader_resolver_TargetSelectors_t*) t0)->f_is_bare;
                                if (t2) {
                                    t1 = (l9 + INT64_C(1));
                                    l9 = (size_t) (int64_t) t1;
                                    goto loop_205;
                                }
                                l13 = ((vader_struct_toolchain_ast_FnDecl_t*) l11)->f_name;
                                l14 = std_collections_get__string__Any(l2, l13);
                                if (l14.tag == 0u) {
                                    l18 = ((vader_struct_toolchain_ast_FnDecl_t*) l11)->f_name_span;
                                    l17 = ((vader_struct_toolchain_ast_FnDecl_t*) l11)->f_name;
                                    l19 = concat_3(919u, l17, 948u);
                                    l22 = vader_diagnostics_resolver_error((uint8_t) (int32_t) INT32_C(35), l18, l19);
                                    vader_array_push((vader_array_t*) l1, vader_ref_box(l22));
                                } else {
                                    t0 = l14.payload.obj;
                                    vader_resolver_check_signature(t0, l11, l1);
                                }
                                if (((vader_struct_toolchain_ast_FnDecl_t*) l11)->f_visibility == INT32_C(0)) {
                                    l25 = ((vader_struct_toolchain_ast_FnDecl_t*) l11)->f_name_span;
                                    l20 = ((vader_struct_toolchain_ast_FnDecl_t*) l11)->f_name;
                                    l21 = concat_3(919u, l20, 961u);
                                    l26 = vader_diagnostics_resolver_error((uint8_t) (int32_t) INT32_C(36), l25, l21);
                                    vader_array_push((vader_array_t*) l1, vader_ref_box(l26));
                                } else {
                                }
                                t0 = l12.payload.obj;
                                l27 = ((vader_struct_vader_resolver_TargetSelectors_t*) t0)->f_os;
                                l15 = ((vader_array_t*) l27)->length;
                                l16 = (size_t) (int64_t) INT64_C(0);
                                {
                                    loop_308: {
                                        if ((l16 < l15)) {
                                            vader_array_t* _a12_slotarr = ((vader_array_t*) l27);
                                            if (_a12_slotarr->buf != NULL && _a12_slotarr->buf->header.forward != NULL) { _a12_slotarr->buf = vader_array_buf_forward(_a12_slotarr->buf); }
                                            if ((size_t) l16 >= _a12_slotarr->length) { vader_trap("array index out of bounds"); }
                                            t3 = vader_array_read_u8(_a12_slotarr, _a12_slotarr->offset + (size_t) l16, 167u);
                                            l28 = ((uint8_t) t3.payload.i);
                                            l23 = ((vader_struct_toolchain_ast_FnDecl_t*) l11)->f_name;
                                            l29 = 2417u;
                                            if (l28 == INT32_C(0)) {
                                                l30 = 2392u;
                                                l31 = concat_3(l23, l29, l30);
                                                l32 = std_collections_get__string__Any(l3, l31);
                                                if (!(l32.tag == 0u)) {
                                                    l34 = l32.payload.obj;
                                                    l35 = ((vader_struct_toolchain_ast_FnDecl_t*) l11)->f_name_span;
                                                    t2 = toolchain_span_Span_Equals_equals(l34, l35);
                                                    if (t2) {
                                                        l36 = 919u;
                                                        l37 = ((vader_struct_toolchain_ast_FnDecl_t*) l11)->f_name;
                                                        l38 = 984u;
                                                        l39 = (uint8_t) (int32_t) INT32_C(0);
                                                        if (l28 == l39) {
                                                            l40 = 2392u;
                                                            l45 = 1003u;
                                                            l33 = concat_5(l36, l37, l38, l40, l45);
                                                            l57 = (uint8_t) (int32_t) INT32_C(37);
                                                            l58 = ((vader_struct_toolchain_ast_FnDecl_t*) l11)->f_name_span;
                                                            l59 = vader_diagnostics_resolver_error(l57, l58, l33);
                                                            vader_array_push((vader_array_t*) l1, vader_ref_box(l59));
                                                            l24 = (size_t) (int64_t) INT64_C(1);
                                                            t1 = (l16 + l24);
                                                            l16 = (size_t) (int64_t) t1;
                                                            goto loop_308;
                                                        }
                                                        l41 = (uint8_t) (int32_t) INT32_C(1);
                                                        if (l28 == l41) {
                                                            l40 = 1768u;
                                                            l45 = 1003u;
                                                            l33 = concat_5(l36, l37, l38, l40, l45);
                                                            l57 = (uint8_t) (int32_t) INT32_C(37);
                                                            l58 = ((vader_struct_toolchain_ast_FnDecl_t*) l11)->f_name_span;
                                                            l59 = vader_diagnostics_resolver_error(l57, l58, l33);
                                                            vader_array_push((vader_array_t*) l1, vader_ref_box(l59));
                                                            l24 = (size_t) (int64_t) INT64_C(1);
                                                            t1 = (l16 + l24);
                                                            l16 = (size_t) (int64_t) t1;
                                                            goto loop_308;
                                                        }
                                                        l42 = (uint8_t) (int32_t) INT32_C(2);
                                                        if (l28 == l42) {
                                                            l40 = 1394u;
                                                            l45 = 1003u;
                                                            l33 = concat_5(l36, l37, l38, l40, l45);
                                                            l57 = (uint8_t) (int32_t) INT32_C(37);
                                                            l58 = ((vader_struct_toolchain_ast_FnDecl_t*) l11)->f_name_span;
                                                            l59 = vader_diagnostics_resolver_error(l57, l58, l33);
                                                            vader_array_push((vader_array_t*) l1, vader_ref_box(l59));
                                                            l24 = (size_t) (int64_t) INT64_C(1);
                                                            t1 = (l16 + l24);
                                                            l16 = (size_t) (int64_t) t1;
                                                            goto loop_308;
                                                        }
                                                        l43 = (uint8_t) (int32_t) INT32_C(3);
                                                        if (l28 == l43) {
                                                            l40 = 2386u;
                                                            l45 = 1003u;
                                                            l33 = concat_5(l36, l37, l38, l40, l45);
                                                            l57 = (uint8_t) (int32_t) INT32_C(37);
                                                            l58 = ((vader_struct_toolchain_ast_FnDecl_t*) l11)->f_name_span;
                                                            l59 = vader_diagnostics_resolver_error(l57, l58, l33);
                                                            vader_array_push((vader_array_t*) l1, vader_ref_box(l59));
                                                            l24 = (size_t) (int64_t) INT64_C(1);
                                                            t1 = (l16 + l24);
                                                            l16 = (size_t) (int64_t) t1;
                                                            goto loop_308;
                                                        }
                                                        l44 = (uint8_t) (int32_t) INT32_C(4);
                                                        if (l28 == l44) {
                                                            l40 = 1254u;
                                                            l45 = 1003u;
                                                            l33 = concat_5(l36, l37, l38, l40, l45);
                                                            l57 = (uint8_t) (int32_t) INT32_C(37);
                                                            l58 = ((vader_struct_toolchain_ast_FnDecl_t*) l11)->f_name_span;
                                                            l59 = vader_diagnostics_resolver_error(l57, l58, l33);
                                                            vader_array_push((vader_array_t*) l1, vader_ref_box(l59));
                                                            l24 = (size_t) (int64_t) INT64_C(1);
                                                            t1 = (l16 + l24);
                                                            l16 = (size_t) (int64_t) t1;
                                                            goto loop_308;
                                                        }
                                                        { vader_gc_top = gc_frame.prev; return; }
                                                    }
                                                    l46 = 919u;
                                                    l47 = ((vader_struct_toolchain_ast_FnDecl_t*) l11)->f_name;
                                                    l48 = 928u;
                                                    l49 = (uint8_t) (int32_t) INT32_C(0);
                                                    if (l28 == l49) {
                                                        l50 = 2392u;
                                                        l55 = 933u;
                                                        t0 = l32.payload.obj;
                                                        l56 = vader_resolver_span_origin(t0);
                                                        l33 = concat_6(l46, l47, l48, l50, l55, l56);
                                                        l57 = (uint8_t) (int32_t) INT32_C(37);
                                                        l58 = ((vader_struct_toolchain_ast_FnDecl_t*) l11)->f_name_span;
                                                        l59 = vader_diagnostics_resolver_error(l57, l58, l33);
                                                        vader_array_push((vader_array_t*) l1, vader_ref_box(l59));
                                                        l24 = (size_t) (int64_t) INT64_C(1);
                                                        t1 = (l16 + l24);
                                                        l16 = (size_t) (int64_t) t1;
                                                        goto loop_308;
                                                    }
                                                    l51 = (uint8_t) (int32_t) INT32_C(1);
                                                    if (l28 == l51) {
                                                        l50 = 1768u;
                                                        l55 = 933u;
                                                        t0 = l32.payload.obj;
                                                        l56 = vader_resolver_span_origin(t0);
                                                        l33 = concat_6(l46, l47, l48, l50, l55, l56);
                                                        l57 = (uint8_t) (int32_t) INT32_C(37);
                                                        l58 = ((vader_struct_toolchain_ast_FnDecl_t*) l11)->f_name_span;
                                                        l59 = vader_diagnostics_resolver_error(l57, l58, l33);
                                                        vader_array_push((vader_array_t*) l1, vader_ref_box(l59));
                                                        l24 = (size_t) (int64_t) INT64_C(1);
                                                        t1 = (l16 + l24);
                                                        l16 = (size_t) (int64_t) t1;
                                                        goto loop_308;
                                                    }
                                                    l52 = (uint8_t) (int32_t) INT32_C(2);
                                                    if (l28 == l52) {
                                                        l50 = 1394u;
                                                        l55 = 933u;
                                                        t0 = l32.payload.obj;
                                                        l56 = vader_resolver_span_origin(t0);
                                                        l33 = concat_6(l46, l47, l48, l50, l55, l56);
                                                        l57 = (uint8_t) (int32_t) INT32_C(37);
                                                        l58 = ((vader_struct_toolchain_ast_FnDecl_t*) l11)->f_name_span;
                                                        l59 = vader_diagnostics_resolver_error(l57, l58, l33);
                                                        vader_array_push((vader_array_t*) l1, vader_ref_box(l59));
                                                        l24 = (size_t) (int64_t) INT64_C(1);
                                                        t1 = (l16 + l24);
                                                        l16 = (size_t) (int64_t) t1;
                                                        goto loop_308;
                                                    }
                                                    l53 = (uint8_t) (int32_t) INT32_C(3);
                                                    if (l28 == l53) {
                                                        l50 = 2386u;
                                                        l55 = 933u;
                                                        t0 = l32.payload.obj;
                                                        l56 = vader_resolver_span_origin(t0);
                                                        l33 = concat_6(l46, l47, l48, l50, l55, l56);
                                                        l57 = (uint8_t) (int32_t) INT32_C(37);
                                                        l58 = ((vader_struct_toolchain_ast_FnDecl_t*) l11)->f_name_span;
                                                        l59 = vader_diagnostics_resolver_error(l57, l58, l33);
                                                        vader_array_push((vader_array_t*) l1, vader_ref_box(l59));
                                                        l24 = (size_t) (int64_t) INT64_C(1);
                                                        t1 = (l16 + l24);
                                                        l16 = (size_t) (int64_t) t1;
                                                        goto loop_308;
                                                    }
                                                    l54 = (uint8_t) (int32_t) INT32_C(4);
                                                    if (l28 == l54) {
                                                        l50 = 1254u;
                                                        l55 = 933u;
                                                        t0 = l32.payload.obj;
                                                        l56 = vader_resolver_span_origin(t0);
                                                        l33 = concat_6(l46, l47, l48, l50, l55, l56);
                                                        l57 = (uint8_t) (int32_t) INT32_C(37);
                                                        l58 = ((vader_struct_toolchain_ast_FnDecl_t*) l11)->f_name_span;
                                                        l59 = vader_diagnostics_resolver_error(l57, l58, l33);
                                                        vader_array_push((vader_array_t*) l1, vader_ref_box(l59));
                                                        l24 = (size_t) (int64_t) INT64_C(1);
                                                        t1 = (l16 + l24);
                                                        l16 = (size_t) (int64_t) t1;
                                                        goto loop_308;
                                                    }
                                                    { vader_gc_top = gc_frame.prev; return; }
                                                }
                                                l60 = ((vader_struct_toolchain_ast_FnDecl_t*) l11)->f_name_span;
                                                std_collections_put__string__Any(l3, l31, vader_ref_box(l60));
                                                l24 = (size_t) (int64_t) INT64_C(1);
                                                t1 = (l16 + l24);
                                                l16 = (size_t) (int64_t) t1;
                                                goto loop_308;
                                            }
                                            if (l28 == INT32_C(1)) {
                                                l30 = 1768u;
                                                l31 = concat_3(l23, l29, l30);
                                                l32 = std_collections_get__string__Any(l3, l31);
                                                if (!(l32.tag == 0u)) {
                                                    l34 = l32.payload.obj;
                                                    l35 = ((vader_struct_toolchain_ast_FnDecl_t*) l11)->f_name_span;
                                                    t2 = toolchain_span_Span_Equals_equals(l34, l35);
                                                    if (t2) {
                                                        l36 = 919u;
                                                        l37 = ((vader_struct_toolchain_ast_FnDecl_t*) l11)->f_name;
                                                        l38 = 984u;
                                                        l39 = (uint8_t) (int32_t) INT32_C(0);
                                                        if (l28 == l39) {
                                                            l40 = 2392u;
                                                            l45 = 1003u;
                                                            l33 = concat_5(l36, l37, l38, l40, l45);
                                                            l57 = (uint8_t) (int32_t) INT32_C(37);
                                                            l58 = ((vader_struct_toolchain_ast_FnDecl_t*) l11)->f_name_span;
                                                            l59 = vader_diagnostics_resolver_error(l57, l58, l33);
                                                            vader_array_push((vader_array_t*) l1, vader_ref_box(l59));
                                                            l24 = (size_t) (int64_t) INT64_C(1);
                                                            t1 = (l16 + l24);
                                                            l16 = (size_t) (int64_t) t1;
                                                            goto loop_308;
                                                        }
                                                        l41 = (uint8_t) (int32_t) INT32_C(1);
                                                        if (l28 == l41) {
                                                            l40 = 1768u;
                                                            l45 = 1003u;
                                                            l33 = concat_5(l36, l37, l38, l40, l45);
                                                            l57 = (uint8_t) (int32_t) INT32_C(37);
                                                            l58 = ((vader_struct_toolchain_ast_FnDecl_t*) l11)->f_name_span;
                                                            l59 = vader_diagnostics_resolver_error(l57, l58, l33);
                                                            vader_array_push((vader_array_t*) l1, vader_ref_box(l59));
                                                            l24 = (size_t) (int64_t) INT64_C(1);
                                                            t1 = (l16 + l24);
                                                            l16 = (size_t) (int64_t) t1;
                                                            goto loop_308;
                                                        }
                                                        l42 = (uint8_t) (int32_t) INT32_C(2);
                                                        if (l28 == l42) {
                                                            l40 = 1394u;
                                                            l45 = 1003u;
                                                            l33 = concat_5(l36, l37, l38, l40, l45);
                                                            l57 = (uint8_t) (int32_t) INT32_C(37);
                                                            l58 = ((vader_struct_toolchain_ast_FnDecl_t*) l11)->f_name_span;
                                                            l59 = vader_diagnostics_resolver_error(l57, l58, l33);
                                                            vader_array_push((vader_array_t*) l1, vader_ref_box(l59));
                                                            l24 = (size_t) (int64_t) INT64_C(1);
                                                            t1 = (l16 + l24);
                                                            l16 = (size_t) (int64_t) t1;
                                                            goto loop_308;
                                                        }
                                                        l43 = (uint8_t) (int32_t) INT32_C(3);
                                                        if (l28 == l43) {
                                                            l40 = 2386u;
                                                            l45 = 1003u;
                                                            l33 = concat_5(l36, l37, l38, l40, l45);
                                                            l57 = (uint8_t) (int32_t) INT32_C(37);
                                                            l58 = ((vader_struct_toolchain_ast_FnDecl_t*) l11)->f_name_span;
                                                            l59 = vader_diagnostics_resolver_error(l57, l58, l33);
                                                            vader_array_push((vader_array_t*) l1, vader_ref_box(l59));
                                                            l24 = (size_t) (int64_t) INT64_C(1);
                                                            t1 = (l16 + l24);
                                                            l16 = (size_t) (int64_t) t1;
                                                            goto loop_308;
                                                        }
                                                        l44 = (uint8_t) (int32_t) INT32_C(4);
                                                        if (l28 == l44) {
                                                            l40 = 1254u;
                                                            l45 = 1003u;
                                                            l33 = concat_5(l36, l37, l38, l40, l45);
                                                            l57 = (uint8_t) (int32_t) INT32_C(37);
                                                            l58 = ((vader_struct_toolchain_ast_FnDecl_t*) l11)->f_name_span;
                                                            l59 = vader_diagnostics_resolver_error(l57, l58, l33);
                                                            vader_array_push((vader_array_t*) l1, vader_ref_box(l59));
                                                            l24 = (size_t) (int64_t) INT64_C(1);
                                                            t1 = (l16 + l24);
                                                            l16 = (size_t) (int64_t) t1;
                                                            goto loop_308;
                                                        }
                                                        { vader_gc_top = gc_frame.prev; return; }
                                                    }
                                                    l46 = 919u;
                                                    l47 = ((vader_struct_toolchain_ast_FnDecl_t*) l11)->f_name;
                                                    l48 = 928u;
                                                    l49 = (uint8_t) (int32_t) INT32_C(0);
                                                    if (l28 == l49) {
                                                        l50 = 2392u;
                                                        l55 = 933u;
                                                        t0 = l32.payload.obj;
                                                        l56 = vader_resolver_span_origin(t0);
                                                        l33 = concat_6(l46, l47, l48, l50, l55, l56);
                                                        l57 = (uint8_t) (int32_t) INT32_C(37);
                                                        l58 = ((vader_struct_toolchain_ast_FnDecl_t*) l11)->f_name_span;
                                                        l59 = vader_diagnostics_resolver_error(l57, l58, l33);
                                                        vader_array_push((vader_array_t*) l1, vader_ref_box(l59));
                                                        l24 = (size_t) (int64_t) INT64_C(1);
                                                        t1 = (l16 + l24);
                                                        l16 = (size_t) (int64_t) t1;
                                                        goto loop_308;
                                                    }
                                                    l51 = (uint8_t) (int32_t) INT32_C(1);
                                                    if (l28 == l51) {
                                                        l50 = 1768u;
                                                        l55 = 933u;
                                                        t0 = l32.payload.obj;
                                                        l56 = vader_resolver_span_origin(t0);
                                                        l33 = concat_6(l46, l47, l48, l50, l55, l56);
                                                        l57 = (uint8_t) (int32_t) INT32_C(37);
                                                        l58 = ((vader_struct_toolchain_ast_FnDecl_t*) l11)->f_name_span;
                                                        l59 = vader_diagnostics_resolver_error(l57, l58, l33);
                                                        vader_array_push((vader_array_t*) l1, vader_ref_box(l59));
                                                        l24 = (size_t) (int64_t) INT64_C(1);
                                                        t1 = (l16 + l24);
                                                        l16 = (size_t) (int64_t) t1;
                                                        goto loop_308;
                                                    }
                                                    l52 = (uint8_t) (int32_t) INT32_C(2);
                                                    if (l28 == l52) {
                                                        l50 = 1394u;
                                                        l55 = 933u;
                                                        t0 = l32.payload.obj;
                                                        l56 = vader_resolver_span_origin(t0);
                                                        l33 = concat_6(l46, l47, l48, l50, l55, l56);
                                                        l57 = (uint8_t) (int32_t) INT32_C(37);
                                                        l58 = ((vader_struct_toolchain_ast_FnDecl_t*) l11)->f_name_span;
                                                        l59 = vader_diagnostics_resolver_error(l57, l58, l33);
                                                        vader_array_push((vader_array_t*) l1, vader_ref_box(l59));
                                                        l24 = (size_t) (int64_t) INT64_C(1);
                                                        t1 = (l16 + l24);
                                                        l16 = (size_t) (int64_t) t1;
                                                        goto loop_308;
                                                    }
                                                    l53 = (uint8_t) (int32_t) INT32_C(3);
                                                    if (l28 == l53) {
                                                        l50 = 2386u;
                                                        l55 = 933u;
                                                        t0 = l32.payload.obj;
                                                        l56 = vader_resolver_span_origin(t0);
                                                        l33 = concat_6(l46, l47, l48, l50, l55, l56);
                                                        l57 = (uint8_t) (int32_t) INT32_C(37);
                                                        l58 = ((vader_struct_toolchain_ast_FnDecl_t*) l11)->f_name_span;
                                                        l59 = vader_diagnostics_resolver_error(l57, l58, l33);
                                                        vader_array_push((vader_array_t*) l1, vader_ref_box(l59));
                                                        l24 = (size_t) (int64_t) INT64_C(1);
                                                        t1 = (l16 + l24);
                                                        l16 = (size_t) (int64_t) t1;
                                                        goto loop_308;
                                                    }
                                                    l54 = (uint8_t) (int32_t) INT32_C(4);
                                                    if (l28 == l54) {
                                                        l50 = 1254u;
                                                        l55 = 933u;
                                                        t0 = l32.payload.obj;
                                                        l56 = vader_resolver_span_origin(t0);
                                                        l33 = concat_6(l46, l47, l48, l50, l55, l56);
                                                        l57 = (uint8_t) (int32_t) INT32_C(37);
                                                        l58 = ((vader_struct_toolchain_ast_FnDecl_t*) l11)->f_name_span;
                                                        l59 = vader_diagnostics_resolver_error(l57, l58, l33);
                                                        vader_array_push((vader_array_t*) l1, vader_ref_box(l59));
                                                        l24 = (size_t) (int64_t) INT64_C(1);
                                                        t1 = (l16 + l24);
                                                        l16 = (size_t) (int64_t) t1;
                                                        goto loop_308;
                                                    }
                                                    { vader_gc_top = gc_frame.prev; return; }
                                                }
                                                l60 = ((vader_struct_toolchain_ast_FnDecl_t*) l11)->f_name_span;
                                                std_collections_put__string__Any(l3, l31, vader_ref_box(l60));
                                                l24 = (size_t) (int64_t) INT64_C(1);
                                                t1 = (l16 + l24);
                                                l16 = (size_t) (int64_t) t1;
                                                goto loop_308;
                                            }
                                            if (l28 == INT32_C(2)) {
                                                l30 = 1394u;
                                                l31 = concat_3(l23, l29, l30);
                                                l32 = std_collections_get__string__Any(l3, l31);
                                                if (!(l32.tag == 0u)) {
                                                    l34 = l32.payload.obj;
                                                    l35 = ((vader_struct_toolchain_ast_FnDecl_t*) l11)->f_name_span;
                                                    t2 = toolchain_span_Span_Equals_equals(l34, l35);
                                                    if (t2) {
                                                        l36 = 919u;
                                                        l37 = ((vader_struct_toolchain_ast_FnDecl_t*) l11)->f_name;
                                                        l38 = 984u;
                                                        l39 = (uint8_t) (int32_t) INT32_C(0);
                                                        if (l28 == l39) {
                                                            l40 = 2392u;
                                                            l45 = 1003u;
                                                            l33 = concat_5(l36, l37, l38, l40, l45);
                                                            l57 = (uint8_t) (int32_t) INT32_C(37);
                                                            l58 = ((vader_struct_toolchain_ast_FnDecl_t*) l11)->f_name_span;
                                                            l59 = vader_diagnostics_resolver_error(l57, l58, l33);
                                                            vader_array_push((vader_array_t*) l1, vader_ref_box(l59));
                                                            l24 = (size_t) (int64_t) INT64_C(1);
                                                            t1 = (l16 + l24);
                                                            l16 = (size_t) (int64_t) t1;
                                                            goto loop_308;
                                                        }
                                                        l41 = (uint8_t) (int32_t) INT32_C(1);
                                                        if (l28 == l41) {
                                                            l40 = 1768u;
                                                            l45 = 1003u;
                                                            l33 = concat_5(l36, l37, l38, l40, l45);
                                                            l57 = (uint8_t) (int32_t) INT32_C(37);
                                                            l58 = ((vader_struct_toolchain_ast_FnDecl_t*) l11)->f_name_span;
                                                            l59 = vader_diagnostics_resolver_error(l57, l58, l33);
                                                            vader_array_push((vader_array_t*) l1, vader_ref_box(l59));
                                                            l24 = (size_t) (int64_t) INT64_C(1);
                                                            t1 = (l16 + l24);
                                                            l16 = (size_t) (int64_t) t1;
                                                            goto loop_308;
                                                        }
                                                        l42 = (uint8_t) (int32_t) INT32_C(2);
                                                        if (l28 == l42) {
                                                            l40 = 1394u;
                                                            l45 = 1003u;
                                                            l33 = concat_5(l36, l37, l38, l40, l45);
                                                            l57 = (uint8_t) (int32_t) INT32_C(37);
                                                            l58 = ((vader_struct_toolchain_ast_FnDecl_t*) l11)->f_name_span;
                                                            l59 = vader_diagnostics_resolver_error(l57, l58, l33);
                                                            vader_array_push((vader_array_t*) l1, vader_ref_box(l59));
                                                            l24 = (size_t) (int64_t) INT64_C(1);
                                                            t1 = (l16 + l24);
                                                            l16 = (size_t) (int64_t) t1;
                                                            goto loop_308;
                                                        }
                                                        l43 = (uint8_t) (int32_t) INT32_C(3);
                                                        if (l28 == l43) {
                                                            l40 = 2386u;
                                                            l45 = 1003u;
                                                            l33 = concat_5(l36, l37, l38, l40, l45);
                                                            l57 = (uint8_t) (int32_t) INT32_C(37);
                                                            l58 = ((vader_struct_toolchain_ast_FnDecl_t*) l11)->f_name_span;
                                                            l59 = vader_diagnostics_resolver_error(l57, l58, l33);
                                                            vader_array_push((vader_array_t*) l1, vader_ref_box(l59));
                                                            l24 = (size_t) (int64_t) INT64_C(1);
                                                            t1 = (l16 + l24);
                                                            l16 = (size_t) (int64_t) t1;
                                                            goto loop_308;
                                                        }
                                                        l44 = (uint8_t) (int32_t) INT32_C(4);
                                                        if (l28 == l44) {
                                                            l40 = 1254u;
                                                            l45 = 1003u;
                                                            l33 = concat_5(l36, l37, l38, l40, l45);
                                                            l57 = (uint8_t) (int32_t) INT32_C(37);
                                                            l58 = ((vader_struct_toolchain_ast_FnDecl_t*) l11)->f_name_span;
                                                            l59 = vader_diagnostics_resolver_error(l57, l58, l33);
                                                            vader_array_push((vader_array_t*) l1, vader_ref_box(l59));
                                                            l24 = (size_t) (int64_t) INT64_C(1);
                                                            t1 = (l16 + l24);
                                                            l16 = (size_t) (int64_t) t1;
                                                            goto loop_308;
                                                        }
                                                        { vader_gc_top = gc_frame.prev; return; }
                                                    }
                                                    l46 = 919u;
                                                    l47 = ((vader_struct_toolchain_ast_FnDecl_t*) l11)->f_name;
                                                    l48 = 928u;
                                                    l49 = (uint8_t) (int32_t) INT32_C(0);
                                                    if (l28 == l49) {
                                                        l50 = 2392u;
                                                        l55 = 933u;
                                                        t0 = l32.payload.obj;
                                                        l56 = vader_resolver_span_origin(t0);
                                                        l33 = concat_6(l46, l47, l48, l50, l55, l56);
                                                        l57 = (uint8_t) (int32_t) INT32_C(37);
                                                        l58 = ((vader_struct_toolchain_ast_FnDecl_t*) l11)->f_name_span;
                                                        l59 = vader_diagnostics_resolver_error(l57, l58, l33);
                                                        vader_array_push((vader_array_t*) l1, vader_ref_box(l59));
                                                        l24 = (size_t) (int64_t) INT64_C(1);
                                                        t1 = (l16 + l24);
                                                        l16 = (size_t) (int64_t) t1;
                                                        goto loop_308;
                                                    }
                                                    l51 = (uint8_t) (int32_t) INT32_C(1);
                                                    if (l28 == l51) {
                                                        l50 = 1768u;
                                                        l55 = 933u;
                                                        t0 = l32.payload.obj;
                                                        l56 = vader_resolver_span_origin(t0);
                                                        l33 = concat_6(l46, l47, l48, l50, l55, l56);
                                                        l57 = (uint8_t) (int32_t) INT32_C(37);
                                                        l58 = ((vader_struct_toolchain_ast_FnDecl_t*) l11)->f_name_span;
                                                        l59 = vader_diagnostics_resolver_error(l57, l58, l33);
                                                        vader_array_push((vader_array_t*) l1, vader_ref_box(l59));
                                                        l24 = (size_t) (int64_t) INT64_C(1);
                                                        t1 = (l16 + l24);
                                                        l16 = (size_t) (int64_t) t1;
                                                        goto loop_308;
                                                    }
                                                    l52 = (uint8_t) (int32_t) INT32_C(2);
                                                    if (l28 == l52) {
                                                        l50 = 1394u;
                                                        l55 = 933u;
                                                        t0 = l32.payload.obj;
                                                        l56 = vader_resolver_span_origin(t0);
                                                        l33 = concat_6(l46, l47, l48, l50, l55, l56);
                                                        l57 = (uint8_t) (int32_t) INT32_C(37);
                                                        l58 = ((vader_struct_toolchain_ast_FnDecl_t*) l11)->f_name_span;
                                                        l59 = vader_diagnostics_resolver_error(l57, l58, l33);
                                                        vader_array_push((vader_array_t*) l1, vader_ref_box(l59));
                                                        l24 = (size_t) (int64_t) INT64_C(1);
                                                        t1 = (l16 + l24);
                                                        l16 = (size_t) (int64_t) t1;
                                                        goto loop_308;
                                                    }
                                                    l53 = (uint8_t) (int32_t) INT32_C(3);
                                                    if (l28 == l53) {
                                                        l50 = 2386u;
                                                        l55 = 933u;
                                                        t0 = l32.payload.obj;
                                                        l56 = vader_resolver_span_origin(t0);
                                                        l33 = concat_6(l46, l47, l48, l50, l55, l56);
                                                        l57 = (uint8_t) (int32_t) INT32_C(37);
                                                        l58 = ((vader_struct_toolchain_ast_FnDecl_t*) l11)->f_name_span;
                                                        l59 = vader_diagnostics_resolver_error(l57, l58, l33);
                                                        vader_array_push((vader_array_t*) l1, vader_ref_box(l59));
                                                        l24 = (size_t) (int64_t) INT64_C(1);
                                                        t1 = (l16 + l24);
                                                        l16 = (size_t) (int64_t) t1;
                                                        goto loop_308;
                                                    }
                                                    l54 = (uint8_t) (int32_t) INT32_C(4);
                                                    if (l28 == l54) {
                                                        l50 = 1254u;
                                                        l55 = 933u;
                                                        t0 = l32.payload.obj;
                                                        l56 = vader_resolver_span_origin(t0);
                                                        l33 = concat_6(l46, l47, l48, l50, l55, l56);
                                                        l57 = (uint8_t) (int32_t) INT32_C(37);
                                                        l58 = ((vader_struct_toolchain_ast_FnDecl_t*) l11)->f_name_span;
                                                        l59 = vader_diagnostics_resolver_error(l57, l58, l33);
                                                        vader_array_push((vader_array_t*) l1, vader_ref_box(l59));
                                                        l24 = (size_t) (int64_t) INT64_C(1);
                                                        t1 = (l16 + l24);
                                                        l16 = (size_t) (int64_t) t1;
                                                        goto loop_308;
                                                    }
                                                    { vader_gc_top = gc_frame.prev; return; }
                                                }
                                                l60 = ((vader_struct_toolchain_ast_FnDecl_t*) l11)->f_name_span;
                                                std_collections_put__string__Any(l3, l31, vader_ref_box(l60));
                                                l24 = (size_t) (int64_t) INT64_C(1);
                                                t1 = (l16 + l24);
                                                l16 = (size_t) (int64_t) t1;
                                                goto loop_308;
                                            }
                                            if (l28 == INT32_C(3)) {
                                                l30 = 2386u;
                                                l31 = concat_3(l23, l29, l30);
                                                l32 = std_collections_get__string__Any(l3, l31);
                                                if (!(l32.tag == 0u)) {
                                                    l34 = l32.payload.obj;
                                                    l35 = ((vader_struct_toolchain_ast_FnDecl_t*) l11)->f_name_span;
                                                    t2 = toolchain_span_Span_Equals_equals(l34, l35);
                                                    if (t2) {
                                                        l36 = 919u;
                                                        l37 = ((vader_struct_toolchain_ast_FnDecl_t*) l11)->f_name;
                                                        l38 = 984u;
                                                        l39 = (uint8_t) (int32_t) INT32_C(0);
                                                        if (l28 == l39) {
                                                            l40 = 2392u;
                                                            l45 = 1003u;
                                                            l33 = concat_5(l36, l37, l38, l40, l45);
                                                            l57 = (uint8_t) (int32_t) INT32_C(37);
                                                            l58 = ((vader_struct_toolchain_ast_FnDecl_t*) l11)->f_name_span;
                                                            l59 = vader_diagnostics_resolver_error(l57, l58, l33);
                                                            vader_array_push((vader_array_t*) l1, vader_ref_box(l59));
                                                            l24 = (size_t) (int64_t) INT64_C(1);
                                                            t1 = (l16 + l24);
                                                            l16 = (size_t) (int64_t) t1;
                                                            goto loop_308;
                                                        }
                                                        l41 = (uint8_t) (int32_t) INT32_C(1);
                                                        if (l28 == l41) {
                                                            l40 = 1768u;
                                                            l45 = 1003u;
                                                            l33 = concat_5(l36, l37, l38, l40, l45);
                                                            l57 = (uint8_t) (int32_t) INT32_C(37);
                                                            l58 = ((vader_struct_toolchain_ast_FnDecl_t*) l11)->f_name_span;
                                                            l59 = vader_diagnostics_resolver_error(l57, l58, l33);
                                                            vader_array_push((vader_array_t*) l1, vader_ref_box(l59));
                                                            l24 = (size_t) (int64_t) INT64_C(1);
                                                            t1 = (l16 + l24);
                                                            l16 = (size_t) (int64_t) t1;
                                                            goto loop_308;
                                                        }
                                                        l42 = (uint8_t) (int32_t) INT32_C(2);
                                                        if (l28 == l42) {
                                                            l40 = 1394u;
                                                            l45 = 1003u;
                                                            l33 = concat_5(l36, l37, l38, l40, l45);
                                                            l57 = (uint8_t) (int32_t) INT32_C(37);
                                                            l58 = ((vader_struct_toolchain_ast_FnDecl_t*) l11)->f_name_span;
                                                            l59 = vader_diagnostics_resolver_error(l57, l58, l33);
                                                            vader_array_push((vader_array_t*) l1, vader_ref_box(l59));
                                                            l24 = (size_t) (int64_t) INT64_C(1);
                                                            t1 = (l16 + l24);
                                                            l16 = (size_t) (int64_t) t1;
                                                            goto loop_308;
                                                        }
                                                        l43 = (uint8_t) (int32_t) INT32_C(3);
                                                        if (l28 == l43) {
                                                            l40 = 2386u;
                                                            l45 = 1003u;
                                                            l33 = concat_5(l36, l37, l38, l40, l45);
                                                            l57 = (uint8_t) (int32_t) INT32_C(37);
                                                            l58 = ((vader_struct_toolchain_ast_FnDecl_t*) l11)->f_name_span;
                                                            l59 = vader_diagnostics_resolver_error(l57, l58, l33);
                                                            vader_array_push((vader_array_t*) l1, vader_ref_box(l59));
                                                            l24 = (size_t) (int64_t) INT64_C(1);
                                                            t1 = (l16 + l24);
                                                            l16 = (size_t) (int64_t) t1;
                                                            goto loop_308;
                                                        }
                                                        l44 = (uint8_t) (int32_t) INT32_C(4);
                                                        if (l28 == l44) {
                                                            l40 = 1254u;
                                                            l45 = 1003u;
                                                            l33 = concat_5(l36, l37, l38, l40, l45);
                                                            l57 = (uint8_t) (int32_t) INT32_C(37);
                                                            l58 = ((vader_struct_toolchain_ast_FnDecl_t*) l11)->f_name_span;
                                                            l59 = vader_diagnostics_resolver_error(l57, l58, l33);
                                                            vader_array_push((vader_array_t*) l1, vader_ref_box(l59));
                                                            l24 = (size_t) (int64_t) INT64_C(1);
                                                            t1 = (l16 + l24);
                                                            l16 = (size_t) (int64_t) t1;
                                                            goto loop_308;
                                                        }
                                                        { vader_gc_top = gc_frame.prev; return; }
                                                    }
                                                    l46 = 919u;
                                                    l47 = ((vader_struct_toolchain_ast_FnDecl_t*) l11)->f_name;
                                                    l48 = 928u;
                                                    l49 = (uint8_t) (int32_t) INT32_C(0);
                                                    if (l28 == l49) {
                                                        l50 = 2392u;
                                                        l55 = 933u;
                                                        t0 = l32.payload.obj;
                                                        l56 = vader_resolver_span_origin(t0);
                                                        l33 = concat_6(l46, l47, l48, l50, l55, l56);
                                                        l57 = (uint8_t) (int32_t) INT32_C(37);
                                                        l58 = ((vader_struct_toolchain_ast_FnDecl_t*) l11)->f_name_span;
                                                        l59 = vader_diagnostics_resolver_error(l57, l58, l33);
                                                        vader_array_push((vader_array_t*) l1, vader_ref_box(l59));
                                                        l24 = (size_t) (int64_t) INT64_C(1);
                                                        t1 = (l16 + l24);
                                                        l16 = (size_t) (int64_t) t1;
                                                        goto loop_308;
                                                    }
                                                    l51 = (uint8_t) (int32_t) INT32_C(1);
                                                    if (l28 == l51) {
                                                        l50 = 1768u;
                                                        l55 = 933u;
                                                        t0 = l32.payload.obj;
                                                        l56 = vader_resolver_span_origin(t0);
                                                        l33 = concat_6(l46, l47, l48, l50, l55, l56);
                                                        l57 = (uint8_t) (int32_t) INT32_C(37);
                                                        l58 = ((vader_struct_toolchain_ast_FnDecl_t*) l11)->f_name_span;
                                                        l59 = vader_diagnostics_resolver_error(l57, l58, l33);
                                                        vader_array_push((vader_array_t*) l1, vader_ref_box(l59));
                                                        l24 = (size_t) (int64_t) INT64_C(1);
                                                        t1 = (l16 + l24);
                                                        l16 = (size_t) (int64_t) t1;
                                                        goto loop_308;
                                                    }
                                                    l52 = (uint8_t) (int32_t) INT32_C(2);
                                                    if (l28 == l52) {
                                                        l50 = 1394u;
                                                        l55 = 933u;
                                                        t0 = l32.payload.obj;
                                                        l56 = vader_resolver_span_origin(t0);
                                                        l33 = concat_6(l46, l47, l48, l50, l55, l56);
                                                        l57 = (uint8_t) (int32_t) INT32_C(37);
                                                        l58 = ((vader_struct_toolchain_ast_FnDecl_t*) l11)->f_name_span;
                                                        l59 = vader_diagnostics_resolver_error(l57, l58, l33);
                                                        vader_array_push((vader_array_t*) l1, vader_ref_box(l59));
                                                        l24 = (size_t) (int64_t) INT64_C(1);
                                                        t1 = (l16 + l24);
                                                        l16 = (size_t) (int64_t) t1;
                                                        goto loop_308;
                                                    }
                                                    l53 = (uint8_t) (int32_t) INT32_C(3);
                                                    if (l28 == l53) {
                                                        l50 = 2386u;
                                                        l55 = 933u;
                                                        t0 = l32.payload.obj;
                                                        l56 = vader_resolver_span_origin(t0);
                                                        l33 = concat_6(l46, l47, l48, l50, l55, l56);
                                                        l57 = (uint8_t) (int32_t) INT32_C(37);
                                                        l58 = ((vader_struct_toolchain_ast_FnDecl_t*) l11)->f_name_span;
                                                        l59 = vader_diagnostics_resolver_error(l57, l58, l33);
                                                        vader_array_push((vader_array_t*) l1, vader_ref_box(l59));
                                                        l24 = (size_t) (int64_t) INT64_C(1);
                                                        t1 = (l16 + l24);
                                                        l16 = (size_t) (int64_t) t1;
                                                        goto loop_308;
                                                    }
                                                    l54 = (uint8_t) (int32_t) INT32_C(4);
                                                    if (l28 == l54) {
                                                        l50 = 1254u;
                                                        l55 = 933u;
                                                        t0 = l32.payload.obj;
                                                        l56 = vader_resolver_span_origin(t0);
                                                        l33 = concat_6(l46, l47, l48, l50, l55, l56);
                                                        l57 = (uint8_t) (int32_t) INT32_C(37);
                                                        l58 = ((vader_struct_toolchain_ast_FnDecl_t*) l11)->f_name_span;
                                                        l59 = vader_diagnostics_resolver_error(l57, l58, l33);
                                                        vader_array_push((vader_array_t*) l1, vader_ref_box(l59));
                                                        l24 = (size_t) (int64_t) INT64_C(1);
                                                        t1 = (l16 + l24);
                                                        l16 = (size_t) (int64_t) t1;
                                                        goto loop_308;
                                                    }
                                                    { vader_gc_top = gc_frame.prev; return; }
                                                }
                                                l60 = ((vader_struct_toolchain_ast_FnDecl_t*) l11)->f_name_span;
                                                std_collections_put__string__Any(l3, l31, vader_ref_box(l60));
                                                l24 = (size_t) (int64_t) INT64_C(1);
                                                t1 = (l16 + l24);
                                                l16 = (size_t) (int64_t) t1;
                                                goto loop_308;
                                            }
                                            if (l28 == INT32_C(4)) {
                                                l30 = 1254u;
                                                l31 = concat_3(l23, l29, l30);
                                                l32 = std_collections_get__string__Any(l3, l31);
                                                if (!(l32.tag == 0u)) {
                                                    l34 = l32.payload.obj;
                                                    l35 = ((vader_struct_toolchain_ast_FnDecl_t*) l11)->f_name_span;
                                                    t2 = toolchain_span_Span_Equals_equals(l34, l35);
                                                    if (t2) {
                                                        l36 = 919u;
                                                        l37 = ((vader_struct_toolchain_ast_FnDecl_t*) l11)->f_name;
                                                        l38 = 984u;
                                                        l39 = (uint8_t) (int32_t) INT32_C(0);
                                                        if (l28 == l39) {
                                                            l40 = 2392u;
                                                            l45 = 1003u;
                                                            l33 = concat_5(l36, l37, l38, l40, l45);
                                                            l57 = (uint8_t) (int32_t) INT32_C(37);
                                                            l58 = ((vader_struct_toolchain_ast_FnDecl_t*) l11)->f_name_span;
                                                            l59 = vader_diagnostics_resolver_error(l57, l58, l33);
                                                            vader_array_push((vader_array_t*) l1, vader_ref_box(l59));
                                                            l24 = (size_t) (int64_t) INT64_C(1);
                                                            t1 = (l16 + l24);
                                                            l16 = (size_t) (int64_t) t1;
                                                            goto loop_308;
                                                        }
                                                        l41 = (uint8_t) (int32_t) INT32_C(1);
                                                        if (l28 == l41) {
                                                            l40 = 1768u;
                                                            l45 = 1003u;
                                                            l33 = concat_5(l36, l37, l38, l40, l45);
                                                            l57 = (uint8_t) (int32_t) INT32_C(37);
                                                            l58 = ((vader_struct_toolchain_ast_FnDecl_t*) l11)->f_name_span;
                                                            l59 = vader_diagnostics_resolver_error(l57, l58, l33);
                                                            vader_array_push((vader_array_t*) l1, vader_ref_box(l59));
                                                            l24 = (size_t) (int64_t) INT64_C(1);
                                                            t1 = (l16 + l24);
                                                            l16 = (size_t) (int64_t) t1;
                                                            goto loop_308;
                                                        }
                                                        l42 = (uint8_t) (int32_t) INT32_C(2);
                                                        if (l28 == l42) {
                                                            l40 = 1394u;
                                                            l45 = 1003u;
                                                            l33 = concat_5(l36, l37, l38, l40, l45);
                                                            l57 = (uint8_t) (int32_t) INT32_C(37);
                                                            l58 = ((vader_struct_toolchain_ast_FnDecl_t*) l11)->f_name_span;
                                                            l59 = vader_diagnostics_resolver_error(l57, l58, l33);
                                                            vader_array_push((vader_array_t*) l1, vader_ref_box(l59));
                                                            l24 = (size_t) (int64_t) INT64_C(1);
                                                            t1 = (l16 + l24);
                                                            l16 = (size_t) (int64_t) t1;
                                                            goto loop_308;
                                                        }
                                                        l43 = (uint8_t) (int32_t) INT32_C(3);
                                                        if (l28 == l43) {
                                                            l40 = 2386u;
                                                            l45 = 1003u;
                                                            l33 = concat_5(l36, l37, l38, l40, l45);
                                                            l57 = (uint8_t) (int32_t) INT32_C(37);
                                                            l58 = ((vader_struct_toolchain_ast_FnDecl_t*) l11)->f_name_span;
                                                            l59 = vader_diagnostics_resolver_error(l57, l58, l33);
                                                            vader_array_push((vader_array_t*) l1, vader_ref_box(l59));
                                                            l24 = (size_t) (int64_t) INT64_C(1);
                                                            t1 = (l16 + l24);
                                                            l16 = (size_t) (int64_t) t1;
                                                            goto loop_308;
                                                        }
                                                        l44 = (uint8_t) (int32_t) INT32_C(4);
                                                        if (l28 == l44) {
                                                            l40 = 1254u;
                                                            l45 = 1003u;
                                                            l33 = concat_5(l36, l37, l38, l40, l45);
                                                            l57 = (uint8_t) (int32_t) INT32_C(37);
                                                            l58 = ((vader_struct_toolchain_ast_FnDecl_t*) l11)->f_name_span;
                                                            l59 = vader_diagnostics_resolver_error(l57, l58, l33);
                                                            vader_array_push((vader_array_t*) l1, vader_ref_box(l59));
                                                            l24 = (size_t) (int64_t) INT64_C(1);
                                                            t1 = (l16 + l24);
                                                            l16 = (size_t) (int64_t) t1;
                                                            goto loop_308;
                                                        }
                                                        { vader_gc_top = gc_frame.prev; return; }
                                                    }
                                                    l46 = 919u;
                                                    l47 = ((vader_struct_toolchain_ast_FnDecl_t*) l11)->f_name;
                                                    l48 = 928u;
                                                    l49 = (uint8_t) (int32_t) INT32_C(0);
                                                    if (l28 == l49) {
                                                        l50 = 2392u;
                                                        l55 = 933u;
                                                        t0 = l32.payload.obj;
                                                        l56 = vader_resolver_span_origin(t0);
                                                        l33 = concat_6(l46, l47, l48, l50, l55, l56);
                                                        l57 = (uint8_t) (int32_t) INT32_C(37);
                                                        l58 = ((vader_struct_toolchain_ast_FnDecl_t*) l11)->f_name_span;
                                                        l59 = vader_diagnostics_resolver_error(l57, l58, l33);
                                                        vader_array_push((vader_array_t*) l1, vader_ref_box(l59));
                                                        l24 = (size_t) (int64_t) INT64_C(1);
                                                        t1 = (l16 + l24);
                                                        l16 = (size_t) (int64_t) t1;
                                                        goto loop_308;
                                                    }
                                                    l51 = (uint8_t) (int32_t) INT32_C(1);
                                                    if (l28 == l51) {
                                                        l50 = 1768u;
                                                        l55 = 933u;
                                                        t0 = l32.payload.obj;
                                                        l56 = vader_resolver_span_origin(t0);
                                                        l33 = concat_6(l46, l47, l48, l50, l55, l56);
                                                        l57 = (uint8_t) (int32_t) INT32_C(37);
                                                        l58 = ((vader_struct_toolchain_ast_FnDecl_t*) l11)->f_name_span;
                                                        l59 = vader_diagnostics_resolver_error(l57, l58, l33);
                                                        vader_array_push((vader_array_t*) l1, vader_ref_box(l59));
                                                        l24 = (size_t) (int64_t) INT64_C(1);
                                                        t1 = (l16 + l24);
                                                        l16 = (size_t) (int64_t) t1;
                                                        goto loop_308;
                                                    }
                                                    l52 = (uint8_t) (int32_t) INT32_C(2);
                                                    if (l28 == l52) {
                                                        l50 = 1394u;
                                                        l55 = 933u;
                                                        t0 = l32.payload.obj;
                                                        l56 = vader_resolver_span_origin(t0);
                                                        l33 = concat_6(l46, l47, l48, l50, l55, l56);
                                                        l57 = (uint8_t) (int32_t) INT32_C(37);
                                                        l58 = ((vader_struct_toolchain_ast_FnDecl_t*) l11)->f_name_span;
                                                        l59 = vader_diagnostics_resolver_error(l57, l58, l33);
                                                        vader_array_push((vader_array_t*) l1, vader_ref_box(l59));
                                                        l24 = (size_t) (int64_t) INT64_C(1);
                                                        t1 = (l16 + l24);
                                                        l16 = (size_t) (int64_t) t1;
                                                        goto loop_308;
                                                    }
                                                    l53 = (uint8_t) (int32_t) INT32_C(3);
                                                    if (l28 == l53) {
                                                        l50 = 2386u;
                                                        l55 = 933u;
                                                        t0 = l32.payload.obj;
                                                        l56 = vader_resolver_span_origin(t0);
                                                        l33 = concat_6(l46, l47, l48, l50, l55, l56);
                                                        l57 = (uint8_t) (int32_t) INT32_C(37);
                                                        l58 = ((vader_struct_toolchain_ast_FnDecl_t*) l11)->f_name_span;
                                                        l59 = vader_diagnostics_resolver_error(l57, l58, l33);
                                                        vader_array_push((vader_array_t*) l1, vader_ref_box(l59));
                                                        l24 = (size_t) (int64_t) INT64_C(1);
                                                        t1 = (l16 + l24);
                                                        l16 = (size_t) (int64_t) t1;
                                                        goto loop_308;
                                                    }
                                                    l54 = (uint8_t) (int32_t) INT32_C(4);
                                                    if (l28 == l54) {
                                                        l50 = 1254u;
                                                        l55 = 933u;
                                                        t0 = l32.payload.obj;
                                                        l56 = vader_resolver_span_origin(t0);
                                                        l33 = concat_6(l46, l47, l48, l50, l55, l56);
                                                        l57 = (uint8_t) (int32_t) INT32_C(37);
                                                        l58 = ((vader_struct_toolchain_ast_FnDecl_t*) l11)->f_name_span;
                                                        l59 = vader_diagnostics_resolver_error(l57, l58, l33);
                                                        vader_array_push((vader_array_t*) l1, vader_ref_box(l59));
                                                        l24 = (size_t) (int64_t) INT64_C(1);
                                                        t1 = (l16 + l24);
                                                        l16 = (size_t) (int64_t) t1;
                                                        goto loop_308;
                                                    }
                                                    { vader_gc_top = gc_frame.prev; return; }
                                                }
                                                l60 = ((vader_struct_toolchain_ast_FnDecl_t*) l11)->f_name_span;
                                                std_collections_put__string__Any(l3, l31, vader_ref_box(l60));
                                                l24 = (size_t) (int64_t) INT64_C(1);
                                                t1 = (l16 + l24);
                                                l16 = (size_t) (int64_t) t1;
                                                goto loop_308;
                                            }
                                            { vader_gc_top = gc_frame.prev; return; }
                                        } else {
                                        }
                                    }
                                }
                                l61 = (size_t) (int64_t) INT64_C(1);
                                t1 = (l9 + l61);
                                l9 = (size_t) (int64_t) t1;
                                goto loop_205;
                            }
                            l61 = (size_t) (int64_t) INT64_C(1);
                            t1 = (l9 + l61);
                            l9 = (size_t) (int64_t) t1;
                            goto loop_205;
                        } else {
                        }
                    }
                }
                t1 = (l7 + INT64_C(1));
                l7 = (size_t) (int64_t) t1;
                goto loop_189;
            } else {
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
    void* l11 = NULL;
    void* l14 = NULL;
    void* l16 = NULL;
    void* l18 = NULL;
    void* l21 = NULL;
    void* l23 = NULL;
    size_t l6, l7;
    vader_box_t l8 = vader_box_null(), l9 = vader_box_null();
    vader_string_t l10 = 0;
    vader_string_t l12 = 0;
    vader_string_t l13 = 0;
    vader_string_t l15 = 0;
    vader_string_t l17 = 0;
    vader_string_t l19 = 0;
    vader_string_t l20 = 0;
    vader_string_t l22 = 0;
    vader_box_t t0 = vader_box_null();
    int64_t t1;
    vader_box_t* gc_roots[3] = { &l8, &l9, &t0 };
    void** gc_raw_roots[12] = { &l0, &l1, &l2, &l3, &l4, &l5, &l11, &l14, &l16, &l18, &l21, &l23 };
    vader_string_t* gc_atom_roots[8] = { &l10, &l12, &l13, &l15, &l17, &l19, &l20, &l22 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 12u, gc_roots, gc_raw_roots, 0u, NULL, 8u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 161u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(15u, 0u, 0u, 171u);
    l3 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 164u);
    l4 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__string__Any_t* _a3_obj = (vader_struct_std_collections_MutableMap__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__Any_t));
    vader_obj_header_init(_a3_obj, 309u);
    _a3_obj->f_ekeys = l2;
    _a3_obj->f_evals = l3;
    _a3_obj->f_index = l4;
    _a3_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l2 = (void*) _a3_obj;
    vader_array_t* _a4_arr = vader_array_new(8u, 0u, 0u, 161u);
    l3 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_new(15u, 0u, 0u, 171u);
    l4 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(9u, 0u, 7u, 164u);
    l5 = (void*) _a6_arr;
    vader_struct_std_collections_MutableMap__string__Any_t* _a7_obj = (vader_struct_std_collections_MutableMap__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__Any_t));
    vader_obj_header_init(_a7_obj, 309u);
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
                if (l8.tag == 417u) {
                    l5 = l8.payload.obj;
                    l9 = ((vader_struct_toolchain_ast_ImportDecl_t*) l5)->f_binding;
                    if (l9.tag == 464u) {
                        l10 = ((vader_struct_toolchain_ast_ImportDecl_t*) l5)->f_path;
                        t0 = std_collections_get__string__Any(l3, l10);
                        if (!(t0.tag == 0u)) {
                            l11 = ((vader_struct_toolchain_ast_ImportDecl_t*) l5)->f_span;
                            l12 = ((vader_struct_toolchain_ast_ImportDecl_t*) l5)->f_path;
                            l13 = concat_3(919u, l12, 919u);
                            l14 = vader_diagnostics_resolver_error((uint8_t) (int32_t) INT32_C(31), l11, l13);
                            vader_array_push((vader_array_t*) l1, vader_ref_box(l14));
                        } else {
                        }
                        l15 = ((vader_struct_toolchain_ast_ImportDecl_t*) l5)->f_path;
                        l16 = ((vader_struct_toolchain_ast_ImportDecl_t*) l5)->f_span;
                        std_collections_put__string__Any(l2, l15, vader_ref_box(l16));
                    } else {
                        if (l9.tag == 397u) {
                            l17 = ((vader_struct_toolchain_ast_ImportDecl_t*) l5)->f_path;
                            t0 = std_collections_get__string__Any(l2, l17);
                            if (!(t0.tag == 0u)) {
                                l18 = ((vader_struct_toolchain_ast_ImportDecl_t*) l5)->f_span;
                                l19 = ((vader_struct_toolchain_ast_ImportDecl_t*) l5)->f_path;
                                l20 = concat_3(919u, l19, 919u);
                                l21 = vader_diagnostics_resolver_error((uint8_t) (int32_t) INT32_C(31), l18, l20);
                                vader_array_push((vader_array_t*) l1, vader_ref_box(l21));
                            } else {
                            }
                            l22 = ((vader_struct_toolchain_ast_ImportDecl_t*) l5)->f_path;
                            l23 = ((vader_struct_toolchain_ast_ImportDecl_t*) l5)->f_span;
                            std_collections_put__string__Any(l3, l22, vader_ref_box(l23));
                        } else {
                        }
                    }
                } else {
                }
                t1 = (l7 + INT64_C(1));
                l7 = (size_t) (int64_t) t1;
                goto loop_35;
            } else {
            }
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_resolver_check_orphan_rule(void* l0, vader_string_t l1, void* l2, void* l3, void* l4, void* l5) {
    void* l6 = NULL;
    void* l10 = NULL;
    vader_box_t l7 = vader_box_null();
    bool l8, l9, l11;
    vader_string_t l12 = 0;
    vader_string_t l13 = 0;
    vader_string_t t0 = 0;
    vader_box_t* gc_roots[1] = { &l7 };
    void** gc_raw_roots[7] = { &l0, &l2, &l3, &l4, &l5, &l6, &l10 };
    vader_string_t* gc_atom_roots[4] = { &l1, &l12, &l13, &t0 };
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
    if (l7.tag == 872u) {
        l10 = l7.payload.obj;
        l8 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l10)->f_kind == INT32_C(12);
        t0 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l10)->f_module;
        l9 = t0 == l1;
    } else {
    }
    t0 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l6)->f_module;
    l11 = t0 == l1;
    if (!(l8)) {
        l8 = !(l9);
    } else {
        l8 = false;
    }
    if (l8) {
        l8 = !(l11);
    } else {
        l8 = false;
    }
    if (l8) {
        l6 = ((vader_struct_toolchain_ast_ImplDecl_t*) l0)->f_span;
        l12 = ((vader_struct_toolchain_ast_ImplDecl_t*) l0)->f_trait_name;
        l13 = vader_resolver_for_type_display_name(((vader_struct_toolchain_ast_ImplDecl_t*) l0)->f_for_type);
        l12 = concat_4(l12, 114u, l13, 232u);
        l6 = vader_diagnostics_resolver_error((uint8_t) (int32_t) INT32_C(17), l6, l12);
        vader_array_push((vader_array_t*) l5, vader_ref_box(l6));
    } else {
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
    void* l18 = NULL;
    void* l21 = NULL;
    void* l22 = NULL;
    void* l24 = NULL;
    size_t l3, l4, l6, l7, l10, l11, l14, l15;
    vader_box_t l8 = vader_box_null(), l16 = vader_box_null();
    vader_string_t l19 = 0;
    vader_string_t l20 = 0;
    vader_string_t l23 = 0;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    vader_string_t t3 = 0;
    int64_t t2;
    vader_box_t t4 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l8, &l16, &t4 };
    void** gc_raw_roots[13] = { &l0, &l1, &l2, &l5, &l9, &l12, &l13, &l17, &l18, &l21, &l22, &l24, &t0 };
    vader_string_t* gc_atom_roots[5] = { &l19, &l20, &l23, &t1, &t3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 13u, gc_roots, gc_raw_roots, 0u, NULL, 5u, gc_atom_roots };
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
                            if (l8.tag == 407u) {
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
                                            if (t1 != 2125u) {
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
                                                        if (l16.tag == 400u) {
                                                            l17 = l16.payload.obj;
                                                            t1 = ((vader_struct_toolchain_ast_DotVariantExpr_t*) l17)->f_variant;
                                                            t3 = std_string_to_lower(t1);
                                                            t4 = vader_target_parse_os(t3);
                                                            if (t4.tag == 0u) {
                                                                t0 = l16.payload.obj;
                                                                l18 = ((vader_struct_toolchain_ast_DotVariantExpr_t*) t0)->f_span;
                                                                l19 = ((vader_struct_toolchain_ast_DotVariantExpr_t*) l17)->f_variant;
                                                                l20 = concat_3(1047u, l19, 991u);
                                                                l21 = vader_diagnostics_resolver_error((uint8_t) (int32_t) INT32_C(34), l18, l20);
                                                                vader_array_push((vader_array_t*) l1, vader_ref_box(l21));
                                                            } else {
                                                            }
                                                        } else {
                                                            t0 = l16.payload.obj;
                                                            l22 = ((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t0)->f_span;
                                                            l23 = concat_2(1126u, 2403u);
                                                            l24 = vader_diagnostics_resolver_error((uint8_t) (int32_t) INT32_C(34), l22, l23);
                                                            vader_array_push((vader_array_t*) l1, vader_ref_box(l24));
                                                        }
                                                        t2 = (l15 + INT64_C(1));
                                                        l15 = (size_t) (int64_t) t2;
                                                        goto loop_70;
                                                    } else {
                                                    }
                                                }
                                            }
                                            t2 = (l11 + INT64_C(1));
                                            l11 = (size_t) (int64_t) t2;
                                            goto loop_43;
                                        } else {
                                        }
                                    }
                                }
                            } else {
                            }
                            t2 = (l7 + INT64_C(1));
                            l7 = (size_t) (int64_t) t2;
                            goto loop_23;
                        } else {
                        }
                    }
                }
                t2 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t2;
                goto loop_7;
            } else {
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
        l3 = std_core_write_string_at(l8, l3, 919u);
        l3 = std_core_write_string_at(l8, l3, l6);
        l3 = std_core_write_string_at(l8, l3, 1002u);
        t1 = ((vader_array_t*) ((vader_struct_toolchain_ast_FnDecl_t*) l0)->f_params)->length;
        t0 = ((int64_t) (size_t) t1);
        l9 = (uint64_t) (int64_t) t0;
        l3 = std_core_write_unsigned(l8, l3, l9);
        l3 = std_core_write_string_at(l8, l3, 154u);
        l3 = std_core_write_string_at(l8, l3, l7);
        l3 = std_core_write_string_at(l8, l3, 375u);
        l6 = std_core_finish_buffer(l8, l3);
        l8 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(36));
        l3 = (size_t) (int64_t) INT64_C(0);
        l3 = std_core_write_string_at(l8, l3, 2137u);
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
                    l18 = std_core_write_string_at(l8, l18, 1889u);
                    t0 = (l4 + INT64_C(1));
                    l9 = (uint64_t) (int64_t) t0;
                    l18 = std_core_write_unsigned(l8, l18, l9);
                    l18 = std_core_write_string_at(l8, l18, 143u);
                    l18 = std_core_write_string_at(l8, l18, l10);
                    l18 = std_core_write_string_at(l8, l18, 958u);
                    l18 = std_core_write_string_at(l8, l18, l11);
                    l18 = std_core_write_string_at(l8, l18, 933u);
                    l18 = std_core_write_string_at(l8, l18, l12);
                    l18 = std_core_write_string_at(l8, l18, 375u);
                    l19 = std_core_finish_buffer(l8, l18);
                    l20 = concat_3(919u, l7, 953u);
                    l21 = concat_3(l19, l20, 1360u);
                    l22 = vader_diagnostics_resolver_error((uint8_t) (int32_t) INT32_C(39), l5, l21);
                    vader_array_push((vader_array_t*) l2, vader_ref_box(l22));
                } else {
                }
                t0 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                goto loop_121;
            } else {
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
    void* l8 = NULL;
    void* l11 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    size_t l3, l4;
    vader_box_t l5 = vader_box_null();
    vader_string_t l9 = 0;
    vader_string_t l10 = 0;
    vader_string_t t0 = 0;
    vader_string_t t1 = 0;
    vader_box_t t2 = vader_box_null();
    void* t3 = NULL;
    int64_t t4;
    vader_box_t* gc_roots[2] = { &l5, &t2 };
    void** gc_raw_roots[11] = { &l0, &l1, &l2, &l6, &l7, &l8, &l11, &l12, &l13, &l14, &t3 };
    vader_string_t* gc_atom_roots[4] = { &l9, &l10, &t0, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 11u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots };
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
                if (l5.tag == 400u) {
                    l6 = l5.payload.obj;
                    t0 = ((vader_struct_toolchain_ast_DotVariantExpr_t*) l6)->f_variant;
                    t1 = std_string_to_lower(t0);
                    t2 = vader_target_parse_os(t1);
                    if (t2.tag == 0u) {
                        l7 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_diags;
                        l8 = ((vader_struct_toolchain_ast_DotVariantExpr_t*) l6)->f_span;
                        l9 = ((vader_struct_toolchain_ast_DotVariantExpr_t*) l6)->f_variant;
                        l10 = concat_3(1047u, l9, 991u);
                        l11 = vader_diagnostics_resolver_error((uint8_t) (int32_t) INT32_C(34), l8, l10);
                        vader_array_push((vader_array_t*) l7, vader_ref_box(l11));
                    } else {
                    }
                } else {
                    l12 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_diags;
                    t3 = l5.payload.obj;
                    l13 = ((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t3)->f_span;
                    l14 = vader_diagnostics_resolver_error((uint8_t) (int32_t) INT32_C(34), l13, 1470u);
                    vader_array_push((vader_array_t*) l12, vader_ref_box(l14));
                }
                t4 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t4;
                goto loop_7;
            } else {
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
                    l3 = concat_2(l3, 375u);
                } else {
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
            } else {
            }
        }
    }
    l5 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_diags;
    l9 = ((vader_struct_toolchain_ast_IdentExpr_t*) l1)->f_span;
    l4 = ((vader_struct_toolchain_ast_IdentExpr_t*) l1)->f_name;
    l10 = ((vader_struct_toolchain_ast_IdentExpr_t*) l1)->f_name;
    l3 = concat_7(919u, l4, 968u, l3, 233u, l10, 1031u);
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
    vader_obj_header_init(_a0_obj, 412u);
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
    void* l2 = NULL;
    void* l4 = NULL;
    vader_string_t l3 = 0;
    size_t l5, l6;
    vader_box_t l7 = vader_box_null();
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    int64_t t2;
    vader_box_t* gc_roots[3] = { &l0, &l7, &t1 };
    void** gc_raw_roots[4] = { &l1, &l2, &l4, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    if (l0.tag == 445u) {
        l1 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast_SimpleBinding_t*) l1)->f_span;
        l3 = ((vader_struct_toolchain_ast_SimpleBinding_t*) l1)->f_name;
        l1 = ((vader_struct_toolchain_ast_SimpleBinding_t*) l1)->f_name_span;
        vader_struct_toolchain_ast_SimpleBinding_t* _a0_obj = (vader_struct_toolchain_ast_SimpleBinding_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_SimpleBinding_t));
        vader_obj_header_init(_a0_obj, 445u);
        _a0_obj->f_span = l2;
        _a0_obj->f_id = (size_t) (int64_t) INT64_C(0);
        _a0_obj->f_name = l3;
        _a0_obj->f_name_span = l1;
        t0 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 457u) {
        l1 = l0.payload.obj;
        vader_array_t* _a1_arr = vader_array_new(114u, 0u, 13u, 1054u);
        l2 = (void*) _a1_arr;
        l4 = ((vader_struct_toolchain_ast_TupleBinding_t*) l1)->f_elements;
        l5 = ((vader_array_t*) l4)->length;
        l6 = (size_t) (int64_t) INT64_C(0);
        {
            loop_35: {
                if ((l6 < l5)) {
                    vader_array_t* _a2_slotarr = ((vader_array_t*) l4);
                    if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                    if ((size_t) l6 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                    t1 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l6);
                    l7 = vader_resolver_clone_let_binding(t1);
                    vader_array_push((vader_array_t*) l2, l7);
                    t2 = (l6 + INT64_C(1));
                    l6 = (size_t) (int64_t) t2;
                    goto loop_35;
                } else {
                }
            }
        }
        vader_struct_toolchain_ast_TupleBinding_t* _a3_obj = (vader_struct_toolchain_ast_TupleBinding_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_TupleBinding_t));
        vader_obj_header_init(_a3_obj, 457u);
        _a3_obj->f_span = ((vader_struct_toolchain_ast_TupleBinding_t*) l1)->f_span;
        _a3_obj->f_id = (size_t) (int64_t) INT64_C(0);
        _a3_obj->f_elements = l2;
        t0 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 463u) {
        t0 = l0.payload.obj;
        vader_struct_toolchain_ast_WildcardBinding_t* _a4_obj = (vader_struct_toolchain_ast_WildcardBinding_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_WildcardBinding_t));
        vader_obj_header_init(_a4_obj, 463u);
        _a4_obj->f_span = ((vader_struct_toolchain_ast_WildcardBinding_t*) t0)->f_span;
        _a4_obj->f_id = (size_t) (int64_t) INT64_C(0);
        t0 = (void*) _a4_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 442u) {
        l1 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast_RestBinding_t*) l1)->f_span;
        l3 = ((vader_struct_toolchain_ast_RestBinding_t*) l1)->f_name;
        l1 = ((vader_struct_toolchain_ast_RestBinding_t*) l1)->f_name_span;
        vader_struct_toolchain_ast_RestBinding_t* _a5_obj = (vader_struct_toolchain_ast_RestBinding_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_RestBinding_t));
        vader_obj_header_init(_a5_obj, 442u);
        _a5_obj->f_span = l2;
        _a5_obj->f_id = (size_t) (int64_t) INT64_C(0);
        _a5_obj->f_name = l3;
        _a5_obj->f_name_span = l1;
        t0 = (void*) _a5_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_unreachable("unreachable return in vader_resolver$clone_let_binding");
    vader_gc_top = gc_frame.prev;
}

static void vader_resolver_collect_decl(void* l0, vader_box_t l1, vader_string_t l2, vader_string_t l3, void* l4, void* l5, void* l6, void* l7) {
    void* l8 = NULL;
    void* l10 = NULL;
    vader_string_t l9 = 0;
    uint8_t l11;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[7] = { &l0, &l4, &l5, &l6, &l7, &l8, &l10 };
    vader_string_t* gc_atom_roots[3] = { &l2, &l3, &l9 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    if (l1.tag == 417u) {
        l8 = l1.payload.obj;
        vader_resolver_collect_import(l0, l8, l2, l3, l4, l5, l6, l7);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 407u) {
        l8 = l1.payload.obj;
        vader_resolver_add_fn(l0, l8, l2, l3, l4, l7);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 449u) {
        l8 = l1.payload.obj;
        l9 = ((vader_struct_toolchain_ast_StructDecl_t*) l8)->f_name;
        l10 = ((vader_struct_toolchain_ast_StructDecl_t*) l8)->f_name_span;
        l11 = ((vader_struct_toolchain_ast_StructDecl_t*) l8)->f_visibility;
        vader_resolver_add_named(l0, INT32_C(1), l9, l10, l11, l2, l3, l4, l7);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 401u) {
        l8 = l1.payload.obj;
        l9 = ((vader_struct_toolchain_ast_EnumDecl_t*) l8)->f_name;
        l10 = ((vader_struct_toolchain_ast_EnumDecl_t*) l8)->f_name_span;
        l11 = ((vader_struct_toolchain_ast_EnumDecl_t*) l8)->f_visibility;
        vader_resolver_add_named(l0, INT32_C(2), l9, l10, l11, l2, l3, l4, l7);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 456u) {
        l8 = l1.payload.obj;
        l9 = ((vader_struct_toolchain_ast_TraitDecl_t*) l8)->f_name;
        l10 = ((vader_struct_toolchain_ast_TraitDecl_t*) l8)->f_name_span;
        l11 = ((vader_struct_toolchain_ast_TraitDecl_t*) l8)->f_visibility;
        vader_resolver_add_named(l0, INT32_C(3), l9, l10, l11, l2, l3, l4, l7);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 459u) {
        l8 = l1.payload.obj;
        l9 = ((vader_struct_toolchain_ast_TypeAliasDecl_t*) l8)->f_name;
        l10 = ((vader_struct_toolchain_ast_TypeAliasDecl_t*) l8)->f_name_span;
        l11 = ((vader_struct_toolchain_ast_TypeAliasDecl_t*) l8)->f_visibility;
        vader_resolver_add_named(l0, INT32_C(5), l9, l10, l11, l2, l3, l4, l7);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 391u) {
        l8 = l1.payload.obj;
        l9 = ((vader_struct_toolchain_ast_ConstDecl_t*) l8)->f_name;
        l10 = ((vader_struct_toolchain_ast_ConstDecl_t*) l8)->f_name_span;
        l11 = ((vader_struct_toolchain_ast_ConstDecl_t*) l8)->f_visibility;
        vader_resolver_add_named(l0, INT32_C(6), l9, l10, l11, l2, l3, l4, l7);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 416u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 379u) {
        { vader_gc_top = gc_frame.prev; return; }
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
            } else {
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
    size_t l13, l14, l23;
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
        vader_array_push((vader_array_t*) l8, vader_box_string(161u, l9));
        l9 = ((vader_struct_toolchain_ast_ImportDecl_t*) l1)->f_path;
        l8 = ((vader_struct_toolchain_ast_ImportDecl_t*) l1)->f_span;
        vader_resolver_diagnose_import_path(l9, l8, l3, l5, l6, l7);
    }
    l10 = ((vader_struct_toolchain_ast_ImportDecl_t*) l1)->f_binding;
    if (l10.tag == 432u) {
        t1 = l10.payload.obj;
        l9 = ((vader_struct_toolchain_ast_NamedNamespaceImport_t*) t1)->f_name;
        l8 = ((vader_struct_toolchain_ast_ImportDecl_t*) l1)->f_span;
        l11 = ((vader_struct_toolchain_ast_ImportDecl_t*) l1)->f_path;
        vader_resolver_bind_import(l0, l9, l8, l11, vader_box_obj(0u, NULL), l2, l4, l7);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l10.tag == 464u) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_resolver_CollectedModule_t*) l0)->f_wildcards);
        if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
        if ((size_t) INT32_C(0) >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
        t1 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT32_C(0));
        l8 = ((vader_struct_vader_resolver_FileWildcards_t*) t1)->f_paths;
        l9 = ((vader_struct_toolchain_ast_ImportDecl_t*) l1)->f_path;
        vader_array_push((vader_array_t*) l8, vader_box_string(161u, l9));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l10.tag == 397u) {
        l8 = l10.payload.obj;
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_resolver_CollectedModule_t*) l0)->f_wildcards);
        if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
        if ((size_t) INT32_C(0) >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
        t1 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) INT32_C(0));
        l12 = ((vader_struct_vader_resolver_FileWildcards_t*) t1)->f_paths;
        l9 = ((vader_struct_toolchain_ast_ImportDecl_t*) l1)->f_path;
        vader_array_push((vader_array_t*) l12, vader_box_string(161u, l9));
        t2 = ((vader_array_t*) ((vader_struct_toolchain_ast_DestructureImport_t*) l8)->f_names)->length;
        if (t2 == INT64_C(0)) {
            l12 = ((vader_struct_toolchain_ast_ImportDecl_t*) l1)->f_span;
            l9 = ((vader_struct_toolchain_ast_ImportDecl_t*) l1)->f_path;
            l9 = concat_3(919u, l9, 919u);
            l12 = vader_diagnostics_warning((uint8_t) (int32_t) INT32_C(7), l12, l9);
            vader_array_push((vader_array_t*) l7, vader_ref_box(l12));
        } else {
        }
        vader_array_t* _a2_arr = vader_array_new(8u, 0u, 0u, 161u);
        l12 = (void*) _a2_arr;
        l8 = ((vader_struct_toolchain_ast_DestructureImport_t*) l8)->f_names;
        l13 = ((vader_array_t*) l8)->length;
        l14 = (size_t) (int64_t) INT64_C(0);
        {
            loop_130: {
                if ((l14 < l13)) {
                    vader_array_t* _a3_slotarr = ((vader_array_t*) l8);
                    if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                    if ((size_t) l14 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                    l15 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l14);
                    l10 = ((vader_struct_toolchain_ast_ImportName_t*) l15)->f_alias;
                    if (l10.tag == 0u) {
                        l16 = ((vader_struct_toolchain_ast_ImportName_t*) l15)->f_span;
                        l9 = ((vader_struct_toolchain_ast_ImportName_t*) l15)->f_name;
                        l11 = concat_3(919u, l9, 919u);
                        l17 = vader_diagnostics_resolver_error((uint8_t) (int32_t) INT32_C(32), l16, l11);
                        vader_array_push((vader_array_t*) l7, vader_ref_box(l17));
                        l23 = (size_t) (int64_t) INT64_C(1);
                        t3 = (l14 + l23);
                        l14 = (size_t) (int64_t) t3;
                        goto loop_130;
                    }
                    if (l10.tag == 161u) {
                        l18 = l10.payload.s;
                        l19 = ((vader_struct_toolchain_ast_ImportName_t*) l15)->f_name;
                        vader_array_push((vader_array_t*) l12, vader_box_string(161u, l19));
                        if (l18 != 859u) {
                            l20 = ((vader_struct_toolchain_ast_ImportName_t*) l15)->f_span;
                            l21 = ((vader_struct_toolchain_ast_ImportDecl_t*) l1)->f_path;
                            l22 = ((vader_struct_toolchain_ast_ImportName_t*) l15)->f_name;
                            vader_resolver_bind_import(l0, l18, l20, l21, vader_box_string(161u, l22), l2, l4, l7);
                        } else {
                        }
                        l23 = (size_t) (int64_t) INT64_C(1);
                        t3 = (l14 + l23);
                        l14 = (size_t) (int64_t) t3;
                        goto loop_130;
                    }
                    { vader_gc_top = gc_frame.prev; return; }
                } else {
                }
            }
        }
        vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_vader_resolver_CollectedModule_t*) l0)->f_wildcards);
        if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
        if ((size_t) INT32_C(0) >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
        t1 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) INT32_C(0));
        l8 = ((vader_struct_vader_resolver_FileWildcards_t*) t1)->f_excludes;
        l9 = ((vader_struct_toolchain_ast_ImportDecl_t*) l1)->f_path;
        std_collections_put__string__Any(l8, l9, vader_ref_box(l12));
        { vader_gc_top = gc_frame.prev; return; }
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
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 161u);
    l7 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(15u, 0u, 0u, 171u);
    l8 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 164u);
    l9 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__string__Any_t* _a3_obj = (vader_struct_std_collections_MutableMap__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__Any_t));
    vader_obj_header_init(_a3_obj, 309u);
    _a3_obj->f_ekeys = l7;
    _a3_obj->f_evals = l8;
    _a3_obj->f_index = l9;
    _a3_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l7 = (void*) _a3_obj;
    vader_array_t* _a4_arr = vader_array_new(8u, 0u, 0u, 161u);
    l8 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_new(15u, 0u, 0u, 171u);
    l9 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(9u, 0u, 7u, 164u);
    l10 = (void*) _a6_arr;
    vader_struct_std_collections_MutableMap__string__Any___t* _a7_obj = (vader_struct_std_collections_MutableMap__string__Any___t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__Any___t));
    vader_obj_header_init(_a7_obj, 311u);
    _a7_obj->f_ekeys = l8;
    _a7_obj->f_evals = l9;
    _a7_obj->f_index = l10;
    _a7_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a7_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a7_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l8 = (void*) _a7_obj;
    l9 = vader_resolver_new_import_table();
    vader_array_t* _a8_arr = vader_array_new(8u, 0u, 0u, 161u);
    l10 = (void*) _a8_arr;
    l11 = ((vader_struct_toolchain_ast_Program_t*) l0)->f_file;
    vader_array_t* _a9_arr = vader_array_new(8u, 0u, 0u, 161u);
    l12 = (void*) _a9_arr;
    vader_array_t* _a10_arr = vader_array_new(8u, 0u, 0u, 161u);
    l13 = (void*) _a10_arr;
    vader_array_t* _a11_arr = vader_array_new(15u, 0u, 0u, 171u);
    l14 = (void*) _a11_arr;
    vader_array_t* _a12_arr = vader_array_new(9u, 0u, 7u, 164u);
    l15 = (void*) _a12_arr;
    vader_struct_std_collections_MutableMap__string__Any___t* _a13_obj = (vader_struct_std_collections_MutableMap__string__Any___t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__Any___t));
    vader_obj_header_init(_a13_obj, 311u);
    _a13_obj->f_ekeys = l13;
    _a13_obj->f_evals = l14;
    _a13_obj->f_index = l15;
    _a13_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a13_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a13_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l13 = (void*) _a13_obj;
    vader_struct_vader_resolver_FileWildcards_t* _a14_obj = (vader_struct_vader_resolver_FileWildcards_t*) vader_gc_alloc(sizeof(vader_struct_vader_resolver_FileWildcards_t));
    vader_obj_header_init(_a14_obj, 854u);
    _a14_obj->f_file = l11;
    _a14_obj->f_paths = l12;
    _a14_obj->f_excludes = l13;
    t0 = (void*) _a14_obj;
    vader_array_t* _a15_arr = vader_array_new(81u, 1u, 13u, 854u);
    ((void**) _a15_arr->buf->slots)[_a15_arr->offset + 0u] = t0;
    l12 = (void*) _a15_arr;
    vader_struct_vader_resolver_CollectedModule_t* _a16_obj = (vader_struct_vader_resolver_CollectedModule_t*) vader_gc_alloc(sizeof(vader_struct_vader_resolver_CollectedModule_t));
    vader_obj_header_init(_a16_obj, 852u);
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
            } else {
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
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 161u);
    l3 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(15u, 0u, 0u, 171u);
    l4 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 164u);
    l5 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__string__Any_t* _a3_obj = (vader_struct_std_collections_MutableMap__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__Any_t));
    vader_obj_header_init(_a3_obj, 309u);
    _a3_obj->f_ekeys = l3;
    _a3_obj->f_evals = l4;
    _a3_obj->f_index = l5;
    _a3_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l3 = (void*) _a3_obj;
    vader_array_t* _a4_arr = vader_array_new(50u, 0u, 13u, 684u);
    l4 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_new(83u, 0u, 13u, 858u);
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
    vader_array_t* _a1_arr = vader_array_new(110u, 0u, 13u, 1023u);
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
                        } else {
                        }
                    }
                }
                t2 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t2;
                goto loop_21;
            } else {
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
                } else {
                }
                t2 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t2;
                goto loop_9;
            } else {
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
    vader_struct___Tuple_1126_t _a6_storage = {0};
    void* gc_stack_objs[1] = { (void*) &_a6_storage };
    vader_string_t* gc_atom_roots[2] = { &l9, &l10 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 8u, gc_roots, gc_raw_roots, 1u, gc_stack_objs, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 161u);
    l3 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(9u, 0u, 7u, 164u);
    l4 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 164u);
    l5 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__string__i32_t* _a3_obj = (vader_struct_std_collections_MutableMap__string__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__i32_t));
    vader_obj_header_init(_a3_obj, 349u);
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
                vader_struct___Tuple_1126_t* _a7_obj = &_a6_storage;
                vader_obj_header_init(_a7_obj, 193u);
                _a7_obj->f__0 = l9;
                _a7_obj->f__1 = l4;
                t1 = (void*) _a7_obj;
                l10 = ((vader_struct___Tuple_1126_t*) t1)->f__0;
                t2 = (l8 + INT64_C(1));
                l8 = (size_t) (int64_t) t2;
                t0 = std_collections_get__string__i32(l3, l10);
                if (t0.tag == 0u) {
                    vader_resolver_walk_import_cycle(l10, l0, l1, l3, l2);
                } else {
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
    t0 = std_string_starts_with(l0, 421u);
    if (t0) {
        l6 = true;
    } else {
        l6 = std_string_starts_with(l0, 418u);
    }
    if (l6) {
        l7 = concat_3(919u, l0, 919u);
        l8 = vader_diagnostics_resolver_error((uint8_t) (int32_t) INT32_C(24), l1, l7);
        vader_array_push((vader_array_t*) l5, vader_ref_box(l8));
        t1 = vader_box_obj(0u, NULL);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == l2) {
        l7 = concat_3(919u, l0, 919u);
        l8 = vader_diagnostics_resolver_error((uint8_t) (int32_t) INT32_C(23), l1, l7);
        vader_array_push((vader_array_t*) l5, vader_ref_box(l8));
        t1 = vader_box_obj(0u, NULL);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == 2000u) {
        l6 = l2 != 2000u;
    } else {
        l6 = false;
    }
    if (l6) {
        l8 = vader_diagnostics_resolver_error((uint8_t) (int32_t) INT32_C(27), l1, 0u);
        vader_array_push((vader_array_t*) l5, vader_ref_box(l8));
        t1 = vader_box_obj(0u, NULL);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = std_string_starts_with(l0, 2287u);
    if (t0) {
        t0 = std_string_starts_with(l2, 2287u);
        l6 = !(t0);
    } else {
        l6 = false;
    }
    if (l6) {
        l6 = l2 != 2145u;
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
        l7 = concat_7(919u, l2, 982u, l0, 1016u, 2145u, 985u);
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
    if (l9.tag == 853u) {
        t4 = l9.payload.obj;
        t5 = ((vader_struct_vader_resolver_DiscoveredModule_t*) t4)->f_folder;
        t1 = vader_box_string(161u, t5);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l9.tag == 0u) {
        l9 = vader_resolver_misplaced_module_at(l0, l4);
        if (l9.tag == 0u) {
            l7 = concat_3(919u, l0, 919u);
            l8 = vader_diagnostics_resolver_error((uint8_t) (int32_t) INT32_C(0), l1, l7);
            vader_array_push((vader_array_t*) l5, vader_ref_box(l8));
        } else {
            l7 = l9.payload.s;
            l7 = concat_5(919u, l0, 1013u, l7, 245u);
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
    vader_array_t* _a0_arr = vader_array_new(23u, 0u, 13u, 407u);
    l2 = (void*) _a0_arr;
    if (l1.tag == 0u) {
        { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = l1.payload.obj;
    vader_array_t* _a1_arr = vader_array_new(50u, 0u, 13u, 684u);
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
                            if (l10.tag == 407u) {
                                l11 = l10.payload.obj;
                                t1 = vader_resolver_target_selectors(((vader_struct_toolchain_ast_FnDecl_t*) l11)->f_decorators);
                                if (t1.tag == 0u) {
                                    t2 = (l9 + INT64_C(1));
                                    l9 = (size_t) (int64_t) t2;
                                    goto loop_41;
                                }
                                t3 = vader_resolver_body_survives(l11, l3);
                                if (t3) {
                                    t2 = (l9 + INT64_C(1));
                                    l9 = (size_t) (int64_t) t2;
                                    goto loop_41;
                                }
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
                        } else {
                        }
                    }
                }
                t2 = (l6 + INT64_C(1));
                l6 = (size_t) (int64_t) t2;
                goto loop_25;
            } else {
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
    void* l19 = NULL;
    vader_string_t l12 = 0;
    vader_string_t l17 = 0;
    vader_string_t l20 = 0;
    vader_box_t l13 = vader_box_null(), l18 = vader_box_null();
    int64_t t0;
    bool t1;
    void* t2 = NULL;
    vader_box_t t3 = vader_box_null();
    vader_box_t* gc_roots[4] = { &l8, &l13, &l18, &t3 };
    void** gc_raw_roots[12] = { &l0, &l1, &l2, &l3, &l4, &l5, &l6, &l7, &l11, &l14, &l19, &t2 };
    vader_string_t* gc_atom_roots[3] = { &l12, &l17, &l20 };
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
                    goto loop_3;
                }
                if (l13.tag == 859u) {
                    t2 = l13.payload.obj;
                    l14 = ((vader_struct_vader_resolver_CollectedModule_t*) ((vader_struct_vader_resolver_LoadedModule_t*) t2)->f_collected)->f_import_paths;
                    l15 = ((vader_array_t*) l14)->length;
                    l16 = (size_t) (int64_t) INT64_C(0);
                    {
                        loop_59: {
                            if ((l16 < l15)) {
                                vader_array_t* _a1_slotarr = ((vader_array_t*) l14);
                                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                                if ((size_t) l16 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                                t3 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l16];
                                l17 = t3.payload.s;
                                l18 = std_collections_get__string__Any(l4, l17);
                                if (l18.tag == 853u) {
                                    l19 = l18.payload.obj;
                                    l20 = ((vader_struct_vader_resolver_DiscoveredModule_t*) l19)->f_folder;
                                    t1 = vader_resolver_has_module(l2, l20);
                                    if (!(t1)) {
                                        vader_array_push((vader_array_t*) l0, vader_ref_box(l19));
                                    } else {
                                    }
                                } else {
                                }
                                t0 = (l16 + INT64_C(1));
                                l16 = (size_t) (int64_t) t0;
                                goto loop_59;
                            } else {
                            }
                        }
                    }
                    goto loop_3;
                }
                { vader_gc_top = gc_frame.prev; return; }
            } else {
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
    t0 = vader_host_std_io_exists(l0);
    if (t0) {
        l1 = vader_host_std_io_is_dir(l0);
    } else {
        l1 = false;
    }
    if (l1) {
        { vader_string_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = vader_resolver_dir_of(l0);
    if (l2 == 0u) {
        { vader_gc_top = gc_frame.prev; return 416u; }
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
    vader_struct___Tuple_1126_t _a2_storage = {0};
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
            } else {
                vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
                if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                if ((size_t) l5 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l5];
                l6 = t0.payload.s;
                vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l5 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                l1 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5);
                vader_struct___Tuple_1126_t* _a3_obj = &_a2_storage;
                vader_obj_header_init(_a3_obj, 193u);
                _a3_obj->f__0 = l6;
                _a3_obj->f__1 = l1;
                t1 = (void*) _a3_obj;
                l7 = ((vader_struct___Tuple_1126_t*) t1)->f__0;
                t2 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t2;
                t3 = std_string_ends_with(l7, 1998u);
                if (t3) {
                    l8 = true;
                } else {
                    l8 = std_string_ends_with(l7, 1997u);
                }
                if (l8) {
                    t0 = vader_box_string(161u, l7);
                    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
                }
                goto loop_12;
            }
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
    vader_struct___Tuple_1126_t _a2_storage = {0};
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
            } else {
                vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
                if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                if ((size_t) l5 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l5];
                l6 = t0.payload.s;
                vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l5 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                l1 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5);
                vader_struct___Tuple_1126_t* _a3_obj = &_a2_storage;
                vader_obj_header_init(_a3_obj, 193u);
                _a3_obj->f__0 = l6;
                _a3_obj->f__1 = l1;
                t1 = (void*) _a3_obj;
                l7 = ((vader_struct___Tuple_1126_t*) t1)->f__0;
                t2 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t2;
                t3 = std_string_ends_with(l7, 2001u);
                if (t3) {
                    l8 = true;
                } else {
                    l8 = std_string_ends_with(l7, 2000u);
                }
                if (l8) {
                    t0 = vader_box_string(161u, l7);
                    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
                }
                goto loop_12;
            }
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
    t0 = vader_host_std_io_exists(l1);
    if (t0) {
        t0 = vader_host_std_io_is_dir(l1);
        if (!(t0)) {
            l1 = vader_resolver_dir_of(l1);
        } else {
        }
    } else {
        l1 = vader_resolver_dir_of(l1);
    }
    {
        loop_19: {
            t1 = vader_resolver_join_path(l1, 2285u);
            t0 = vader_host_std_io_exists(t1);
            if (t0) {
            } else {
                l2 = vader_resolver_dir_of(l1);
                if (l2 == l1) {
                    t2 = vader_box_obj(0u, NULL);
                    { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
                }
                l1 = l2;
                goto loop_19;
            }
        }
    }
    t2 = vader_box_string(161u, l1);
    { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_string_t vader_resolver_for_type_display_name(vader_box_t l0) {
    void* l1;
    void* t0;
    vader_string_t t1;
    if (l0.tag == 412u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_toolchain_ast_IdentExpr_t*) t0)->f_name;
        return t1;
    }
    if (l0.tag == 411u) {
        l1 = l0.payload.obj;
        if (((vader_struct_toolchain_ast_GenericInstExpr_t*) l1)->f_callee.tag == 412u) {
            t0 = ((vader_struct_toolchain_ast_GenericInstExpr_t*) l1)->f_callee.payload.obj;
            t1 = ((vader_struct_toolchain_ast_IdentExpr_t*) t0)->f_name;
            return t1;
        }
        return 524u;
    }
    return 524u;
}

static vader_box_t vader_resolver_for_type_owner_sym(vader_box_t l0, void* l1, void* l2) {
    uint64_t l3;
    vader_box_t l4 = vader_box_null();
    void* l5 = NULL;
    void* t0 = NULL;
    void* t2 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l0, &l4, &t1 };
    void** gc_raw_roots[5] = { &l1, &l2, &l5, &t0, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 412u) {
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
    if (l0.tag == 411u) {
        l5 = l0.payload.obj;
        if (((vader_struct_toolchain_ast_GenericInstExpr_t*) l5)->f_callee.tag == 412u) {
            t0 = ((vader_struct_toolchain_ast_GenericInstExpr_t*) l5)->f_callee.payload.obj;
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
        t1 = vader_box_obj(0u, NULL);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
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
    vader_string_t l2 = 0;
    vader_string_t l3 = 0;
    bool t0;
    vader_box_t* gc_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[3] = { &l1, &l2, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 0u, gc_roots, NULL, 0u, NULL, 3u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    if (l0.tag == 161u) {
        l1 = l0.payload.s;
        l2 = 1271u;
        l3 = vader_resolver_join_path(l1, l2);
        t0 = vader_host_std_io_is_dir(l3);
        if (!(t0)) {
            { vader_gc_top = gc_frame.prev; return 0u; }
        }
        { vader_string_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 0u) {
        l1 = vader_host_std_io_current_working_directory();
        l2 = 1271u;
        l3 = vader_resolver_join_path(l1, l2);
        t0 = vader_host_std_io_is_dir(l3);
        if (!(t0)) {
            { vader_gc_top = gc_frame.prev; return 0u; }
        }
        { vader_string_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_unreachable("unreachable return in vader_resolver$generated_root_for");
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
    vader_array_t* _a0_arr = vader_array_new(21u, 0u, 13u, 393u);
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
            } else {
            }
        }
    }
    l3 = ((vader_struct_toolchain_ast_FnDecl_t*) l1)->f_decorators;
    l4 = ((vader_array_t*) l3)->length;
    l5 = (size_t) (int64_t) INT64_C(0);
    {
        loop_37: {
            if ((l5 < l4)) {
                vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
                if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                if ((size_t) l5 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                l6 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l5);
                t1 = ((vader_struct_toolchain_ast_Decorator_t*) l6)->f_name;
                if (t1 == 1498u) {
                    l7 = true;
                } else {
                    t1 = ((vader_struct_toolchain_ast_Decorator_t*) l6)->f_name;
                    l7 = t1 == 1704u;
                }
                if (l7) {
                    vader_array_push((vader_array_t*) l2, vader_ref_box(l6));
                } else {
                }
                t0 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t0;
                goto loop_37;
            } else {
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
    vader_obj_header_init(_a3_obj, 407u);
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
    l2 = vader_host_std_env_get_env(820u);
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
    t2 = vader_host_std_io_exists(t1);
    if (t2) {
        t0 = vader_box_string(161u, l3);
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
    vader_obj_header_init(_a0_obj, 858u);
    _a0_obj->f_dir = l1;
    _a0_obj->f_prefix = l0;
    _a0_obj->f_merge = false;
    _a0_obj->f_origin = (uint8_t) (int32_t) INT32_C(0);
    t0 = (void*) _a0_obj;
    vader_array_t* _a1_arr = vader_array_new(83u, 1u, 13u, 858u);
    ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = t0;
    l4 = (void*) _a1_arr;
    vader_array_push_all((vader_array_t*) l4, (vader_array_t*) l2);
    if (l3 != 0u) {
        vader_struct_vader_resolver_IncludePath_t* _a2_obj = (vader_struct_vader_resolver_IncludePath_t*) vader_gc_alloc(sizeof(vader_struct_vader_resolver_IncludePath_t));
        vader_obj_header_init(_a2_obj, 858u);
        _a2_obj->f_dir = l3;
        _a2_obj->f_prefix = 0u;
        _a2_obj->f_merge = true;
        _a2_obj->f_origin = (uint8_t) (int32_t) INT32_C(0);
        l5 = (void*) _a2_obj;
        vader_array_push((vader_array_t*) l4, vader_ref_box(l5));
    } else {
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
    vader_obj_header_init(_a0_obj, 862u);
    _a0_obj->f_id = l12;
    _a0_obj->f_display_path = l14;
    _a0_obj->f_module_name = l15;
    _a0_obj->f_origin = l16;
    _a0_obj->f_files = l9;
    t1 = (void*) _a0_obj;
    vader_struct_vader_resolver_LoadedModule_t* _a1_obj = (vader_struct_vader_resolver_LoadedModule_t*) vader_gc_alloc(sizeof(vader_struct_vader_resolver_LoadedModule_t));
    vader_obj_header_init(_a1_obj, 859u);
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
    vader_array_t* _a0_arr = vader_array_new(109u, 0u, 13u, 1015u);
    l1 = (void*) _a0_arr;
    vader_struct_toolchain_ast_Decorator_t* _a1_obj = (vader_struct_toolchain_ast_Decorator_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_Decorator_t));
    vader_obj_header_init(_a1_obj, 393u);
    _a1_obj->f_span = l0;
    _a1_obj->f_id = (size_t) (int64_t) INT64_C(0);
    _a1_obj->f_name = 1704u;
    _a1_obj->f_args = l1;
    t0 = (void*) _a1_obj;
    vader_array_t* _a2_arr = vader_array_new(21u, 1u, 13u, 393u);
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
                if (t0 == 1704u) {
                    return true;
                }
                t0 = ((vader_struct_toolchain_ast_Decorator_t*) l4)->f_name;
                if (t0 == 1498u) {
                    return true;
                }
                t1 = (l3 + INT64_C(1));
                l3 = (size_t) (int64_t) t1;
                goto loop_7;
            } else {
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
                if (t1 == 1704u) {
                    return true;
                }
                t2 = (l3 + INT64_C(1));
                l3 = (size_t) (int64_t) t2;
                goto loop_7;
            } else {
            }
        }
    }
    return false;
}

static bool vader_resolver_is_known_decorator(vader_string_t l0) {
    bool l1;
    if (l0 == 1348u) {
        l1 = true;
    } else {
        l1 = l0 == 1498u;
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == 1484u;
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == 2127u;
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == 1704u;
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == 1411u;
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == 1213u;
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == 1860u;
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == 1150u;
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == 2125u;
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == 1292u;
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == 1293u;
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == 1294u;
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
    l2 = std_string_trim_prefix(l1, 421u);
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
    t3 = concat_3(l0, 438u, l2);
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
    vader_struct___Tuple_1129_t _a7_storage = {0};
    void* gc_stack_objs[1] = { (void*) &_a7_storage };
    vader_string_t* gc_atom_roots[4] = { &l9, &l16, &l17, &l18 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 13u, gc_roots, gc_raw_roots, 1u, gc_stack_objs, 4u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l8 = vader_resolver_resolve_lazy(2004u, l1, l2, l3);
    if (l8.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    t0 = l8.payload.obj;
    l9 = ((vader_struct_vader_resolver_DiscoveredModule_t*) t0)->f_folder;
    t1 = vader_resolver_has_module(l0, l9);
    if (!(t1)) {
        t0 = l8.payload.obj;
        vader_array_t* _a0_arr = vader_array_new(80u, 1u, 13u, 853u);
        ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = t0;
        t0 = (void*) _a0_arr;
        vader_resolver_drain_load_queue(t0, l1, l0, l5, l2, l3, l4, l6, vader_ref_box(l7));
    } else {
    }
    vader_array_t* _a1_arr = vader_array_new(8u, 0u, 0u, 161u);
    l10 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(8u, 0u, 0u, 161u);
    l11 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(9u, 0u, 7u, 164u);
    l12 = (void*) _a3_arr;
    vader_struct_std_collections_MutableMap__string__string_t* _a4_obj = (vader_struct_std_collections_MutableMap__string__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__string_t));
    vader_obj_header_init(_a4_obj, 352u);
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
        loop_60: {
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
                vader_struct___Tuple_1129_t* _a8_obj = &_a7_storage;
                vader_obj_header_init(_a8_obj, 195u);
                _a8_obj->f__0 = l9;
                _a8_obj->f__1 = l16;
                l11 = (void*) _a8_obj;
                l17 = ((vader_struct___Tuple_1129_t*) l11)->f__0;
                l18 = ((vader_struct___Tuple_1129_t*) l11)->f__1;
                t3 = (l15 + INT64_C(1));
                l15 = (size_t) (int64_t) t3;
                std_collections_put__string__string(l10, l17, l18);
                goto loop_60;
            }
        }
    }
    l9 = vader_target_baked_module_source(l7);
    std_collections_put__string__string(l10, 505u, l9);
    vader_array_t* _a9_arr = vader_array_new(8u, 1u, 0u, 161u);
    vader_array_box_slots(_a9_arr->buf)[_a9_arr->offset + 0u] = vader_box_string(161u, 505u);
    l11 = (void*) _a9_arr;
    vader_struct_vader_resolver_DiscoveredModule_t* _a10_obj = (vader_struct_vader_resolver_DiscoveredModule_t*) vader_gc_alloc(sizeof(vader_struct_vader_resolver_DiscoveredModule_t));
    vader_obj_header_init(_a10_obj, 853u);
    _a10_obj->f_name = 2005u;
    _a10_obj->f_folder = 504u;
    _a10_obj->f_files = l11;
    _a10_obj->f_origin = (uint8_t) (int32_t) INT32_C(1);
    t0 = (void*) _a10_obj;
    vader_array_t* _a11_arr = vader_array_new(80u, 1u, 13u, 853u);
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
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 161u);
    l3 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(8u, 0u, 0u, 161u);
    l4 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 164u);
    l5 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__string__string_t* _a3_obj = (vader_struct_std_collections_MutableMap__string__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__string_t));
    vader_obj_header_init(_a3_obj, 352u);
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
    void* l14 = NULL;
    void* l16 = NULL;
    void* l17 = NULL;
    void* l18 = NULL;
    void* l22 = NULL;
    void* l25 = NULL;
    void* l27 = NULL;
    void* l28 = NULL;
    void* l31 = NULL;
    void* l32 = NULL;
    void* l34 = NULL;
    void* l36 = NULL;
    void* l40 = NULL;
    vader_string_t l6 = 0;
    vader_string_t l13 = 0;
    vader_string_t l15 = 0;
    vader_string_t l26 = 0;
    vader_string_t l29 = 0;
    vader_string_t l30 = 0;
    vader_string_t l37 = 0;
    vader_string_t l38 = 0;
    vader_string_t l41 = 0;
    vader_box_t l7 = vader_box_null(), l8 = vader_box_null(), l23 = vader_box_null(), l33 = vader_box_null(), l35 = vader_box_null(), l39 = vader_box_null();
    size_t l19, l20, l21;
    uint8_t l24;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    bool t2;
    vader_box_t* gc_roots[7] = { &l3, &l7, &l8, &l23, &l33, &l35, &l39 };
    void** gc_raw_roots[22] = { &l1, &l2, &l4, &l5, &l9, &l10, &l11, &l12, &l14, &l16, &l17, &l18, &l22, &l25, &l27, &l28, &l31, &l32, &l34, &l36, &l40, &t0 };
    vader_string_t* gc_atom_roots[11] = { &l0, &l6, &l13, &l15, &l26, &l29, &l30, &l37, &l38, &l41, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 7u, 22u, gc_roots, gc_raw_roots, 0u, NULL, 11u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_struct_vader_resolver_symbol_SymbolFactory_t* _a0_obj = (vader_struct_vader_resolver_symbol_SymbolFactory_t*) vader_gc_alloc(sizeof(vader_struct_vader_resolver_symbol_SymbolFactory_t));
    vader_obj_header_init(_a0_obj, 873u);
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
    if (l7.tag == 874u) {
        l9 = vader_target_host_target();
    } else {
        l9 = l7.payload.obj;
    }
    if (l7.tag == 874u) {
        l8 = vader_box_obj(0u, NULL);
    } else {
        t0 = l7.payload.obj;
        l8 = vader_ref_box(t0);
    }
    vader_array_t* _a1_arr = vader_array_new(8u, 0u, 0u, 161u);
    l10 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(15u, 0u, 0u, 171u);
    l11 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(9u, 0u, 7u, 164u);
    l12 = (void*) _a3_arr;
    vader_struct_std_collections_MutableMap__string__Any_t* _a4_obj = (vader_struct_std_collections_MutableMap__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__Any_t));
    vader_obj_header_init(_a4_obj, 309u);
    _a4_obj->f_ekeys = l10;
    _a4_obj->f_evals = l11;
    _a4_obj->f_index = l12;
    _a4_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a4_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a4_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l10 = (void*) _a4_obj;
    vader_array_t* _a5_arr = vader_array_new(50u, 0u, 13u, 684u);
    l11 = (void*) _a5_arr;
    l7 = vader_resolver_find_manifest_root(l6);
    if (l7.tag == 161u) {
        t1 = l7.payload.s;
        l12 = vader_resolver_read_manifest(t1);
        l13 = vader_resolver_entry_folder_of(l6);
        l14 = vader_resolver_project_include_paths(l7, l12, l2);
        l15 = vader_resolver_generated_root_for(l7);
        vader_array_t* _a6_arr = vader_array_new(8u, 0u, 0u, 161u);
        l16 = (void*) _a6_arr;
        vader_array_t* _a7_arr = vader_array_new(15u, 0u, 0u, 171u);
        l17 = (void*) _a7_arr;
        vader_array_t* _a8_arr = vader_array_new(9u, 0u, 7u, 164u);
        l18 = (void*) _a8_arr;
        l19 = (size_t) (int64_t) INT64_C(0);
        l20 = (size_t) (int64_t) INT64_C(0);
        l21 = (size_t) (int64_t) INT64_C(0);
        vader_struct_std_collections_MutableMap__string__Any_t* _a9_obj = (vader_struct_std_collections_MutableMap__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__Any_t));
        vader_obj_header_init(_a9_obj, 309u);
        _a9_obj->f_ekeys = l16;
        _a9_obj->f_evals = l17;
        _a9_obj->f_index = l18;
        _a9_obj->f_mask = l19;
        _a9_obj->f_size = l20;
        _a9_obj->f_tombs = l21;
        l22 = (void*) _a9_obj;
        l23 = vader_resolver_seed_entry(l13, l11);
        if (l23.tag == 0u) {
            l24 = (uint8_t) (int32_t) INT32_C(0);
            l25 = vader_resolver_zero_span(l6);
            l26 = 1443u;
            l27 = vader_diagnostics_resolver_error(l24, l25, l26);
            vader_array_push((vader_array_t*) l11, vader_ref_box(l27));
            vader_struct_vader_resolver_LoadedProject_t* _a10_obj = (vader_struct_vader_resolver_LoadedProject_t*) vader_gc_alloc(sizeof(vader_struct_vader_resolver_LoadedProject_t));
            vader_obj_header_init(_a10_obj, 860u);
            _a10_obj->f_entry = l13;
            _a10_obj->f_modules = l10;
            _a10_obj->f_factory = l4;
            _a10_obj->f_project_root = l7;
            _a10_obj->f_diags = l11;
            t0 = (void*) _a10_obj;
            { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l23.tag == 853u) {
            l28 = l23.payload.obj;
            l29 = ((vader_struct_vader_resolver_DiscoveredModule_t*) l28)->f_name;
            l30 = ((vader_struct_vader_resolver_DiscoveredModule_t*) l28)->f_folder;
            l31 = vader_resolver_include_paths(l29, l30, l14, l15);
            t1 = ((vader_struct_vader_resolver_DiscoveredModule_t*) l28)->f_name;
            l33 = vader_resolver_resolve_lazy(t1, l31, l22, l11);
            if (l33.tag == 0u) {
                l32 = l28;
            } else {
                l32 = l33.payload.obj;
            }
            vader_array_t* _a11_arr = vader_array_new(80u, 1u, 13u, 853u);
            ((void**) _a11_arr->buf->slots)[_a11_arr->offset + 0u] = l32;
            l34 = (void*) _a11_arr;
            l35 = vader_resolver_resolve_lazy(2000u, l31, l22, l11);
            if (l35.tag == 853u) {
                l36 = l35.payload.obj;
                l37 = ((vader_struct_vader_resolver_DiscoveredModule_t*) l36)->f_folder;
                l38 = ((vader_struct_vader_resolver_DiscoveredModule_t*) l28)->f_folder;
                if (l37 != l38) {
                    vader_array_push((vader_array_t*) l34, vader_ref_box(l36));
                } else {
                }
            } else {
            }
            vader_resolver_drain_load_queue(l34, l31, l10, l4, l22, l11, l1, l5, l8);
            l39 = vader_resolver_resolve_lazy(2003u, l31, l22, l11);
            if (l39.tag == 853u) {
                l40 = l39.payload.obj;
                l41 = ((vader_struct_vader_resolver_DiscoveredModule_t*) l40)->f_folder;
                t2 = vader_resolver_has_module(l10, l41);
                if (!(t2)) {
                    vader_array_t* _a12_arr = vader_array_new(80u, 1u, 13u, 853u);
                    ((void**) _a12_arr->buf->slots)[_a12_arr->offset + 0u] = l40;
                    t0 = (void*) _a12_arr;
                    vader_resolver_drain_load_queue(t0, l31, l10, l4, l22, l11, l1, l5, l8);
                } else {
                }
            } else {
            }
            vader_resolver_load_baked_target(l10, l31, l22, l11, l1, l4, l5, l9);
            vader_resolver_detect_import_cycles(l10, l22, l11);
            t1 = ((vader_struct_vader_resolver_DiscoveredModule_t*) l28)->f_folder;
            vader_struct_vader_resolver_LoadedProject_t* _a13_obj = (vader_struct_vader_resolver_LoadedProject_t*) vader_gc_alloc(sizeof(vader_struct_vader_resolver_LoadedProject_t));
            vader_obj_header_init(_a13_obj, 860u);
            _a13_obj->f_entry = t1;
            _a13_obj->f_modules = l10;
            _a13_obj->f_factory = l4;
            _a13_obj->f_project_root = l7;
            _a13_obj->f_diags = l11;
            t0 = (void*) _a13_obj;
            { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        vader_unreachable("unreachable return in vader_resolver$load_project_with_overlay");
    }
    if (l7.tag == 0u) {
        vader_array_t* _a14_arr = vader_array_new(8u, 0u, 0u, 161u);
        t0 = (void*) _a14_arr;
        vader_struct_vader_resolver_Manifest_t* _a15_obj = (vader_struct_vader_resolver_Manifest_t*) vader_gc_alloc(sizeof(vader_struct_vader_resolver_Manifest_t));
        vader_obj_header_init(_a15_obj, 861u);
        _a15_obj->f_include_paths = t0;
        l12 = (void*) _a15_obj;
        l13 = vader_resolver_entry_folder_of(l6);
        l14 = vader_resolver_project_include_paths(l7, l12, l2);
        l15 = vader_resolver_generated_root_for(l7);
        vader_array_t* _a16_arr = vader_array_new(8u, 0u, 0u, 161u);
        l16 = (void*) _a16_arr;
        vader_array_t* _a17_arr = vader_array_new(15u, 0u, 0u, 171u);
        l17 = (void*) _a17_arr;
        vader_array_t* _a18_arr = vader_array_new(9u, 0u, 7u, 164u);
        l18 = (void*) _a18_arr;
        l19 = (size_t) (int64_t) INT64_C(0);
        l20 = (size_t) (int64_t) INT64_C(0);
        l21 = (size_t) (int64_t) INT64_C(0);
        vader_struct_std_collections_MutableMap__string__Any_t* _a19_obj = (vader_struct_std_collections_MutableMap__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__Any_t));
        vader_obj_header_init(_a19_obj, 309u);
        _a19_obj->f_ekeys = l16;
        _a19_obj->f_evals = l17;
        _a19_obj->f_index = l18;
        _a19_obj->f_mask = l19;
        _a19_obj->f_size = l20;
        _a19_obj->f_tombs = l21;
        l22 = (void*) _a19_obj;
        l23 = vader_resolver_seed_entry(l13, l11);
        if (l23.tag == 0u) {
            l24 = (uint8_t) (int32_t) INT32_C(0);
            l25 = vader_resolver_zero_span(l6);
            l26 = 1443u;
            l27 = vader_diagnostics_resolver_error(l24, l25, l26);
            vader_array_push((vader_array_t*) l11, vader_ref_box(l27));
            vader_struct_vader_resolver_LoadedProject_t* _a20_obj = (vader_struct_vader_resolver_LoadedProject_t*) vader_gc_alloc(sizeof(vader_struct_vader_resolver_LoadedProject_t));
            vader_obj_header_init(_a20_obj, 860u);
            _a20_obj->f_entry = l13;
            _a20_obj->f_modules = l10;
            _a20_obj->f_factory = l4;
            _a20_obj->f_project_root = l7;
            _a20_obj->f_diags = l11;
            t0 = (void*) _a20_obj;
            { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l23.tag == 853u) {
            l28 = l23.payload.obj;
            l29 = ((vader_struct_vader_resolver_DiscoveredModule_t*) l28)->f_name;
            l30 = ((vader_struct_vader_resolver_DiscoveredModule_t*) l28)->f_folder;
            l31 = vader_resolver_include_paths(l29, l30, l14, l15);
            t1 = ((vader_struct_vader_resolver_DiscoveredModule_t*) l28)->f_name;
            l33 = vader_resolver_resolve_lazy(t1, l31, l22, l11);
            if (l33.tag == 0u) {
                l32 = l28;
            } else {
                l32 = l33.payload.obj;
            }
            vader_array_t* _a21_arr = vader_array_new(80u, 1u, 13u, 853u);
            ((void**) _a21_arr->buf->slots)[_a21_arr->offset + 0u] = l32;
            l34 = (void*) _a21_arr;
            l35 = vader_resolver_resolve_lazy(2000u, l31, l22, l11);
            if (l35.tag == 853u) {
                l36 = l35.payload.obj;
                l37 = ((vader_struct_vader_resolver_DiscoveredModule_t*) l36)->f_folder;
                l38 = ((vader_struct_vader_resolver_DiscoveredModule_t*) l28)->f_folder;
                if (l37 != l38) {
                    vader_array_push((vader_array_t*) l34, vader_ref_box(l36));
                } else {
                }
            } else {
            }
            vader_resolver_drain_load_queue(l34, l31, l10, l4, l22, l11, l1, l5, l8);
            l39 = vader_resolver_resolve_lazy(2003u, l31, l22, l11);
            if (l39.tag == 853u) {
                l40 = l39.payload.obj;
                l41 = ((vader_struct_vader_resolver_DiscoveredModule_t*) l40)->f_folder;
                t2 = vader_resolver_has_module(l10, l41);
                if (!(t2)) {
                    vader_array_t* _a22_arr = vader_array_new(80u, 1u, 13u, 853u);
                    ((void**) _a22_arr->buf->slots)[_a22_arr->offset + 0u] = l40;
                    t0 = (void*) _a22_arr;
                    vader_resolver_drain_load_queue(t0, l31, l10, l4, l22, l11, l1, l5, l8);
                } else {
                }
            } else {
            }
            vader_resolver_load_baked_target(l10, l31, l22, l11, l1, l4, l5, l9);
            vader_resolver_detect_import_cycles(l10, l22, l11);
            t1 = ((vader_struct_vader_resolver_DiscoveredModule_t*) l28)->f_folder;
            vader_struct_vader_resolver_LoadedProject_t* _a23_obj = (vader_struct_vader_resolver_LoadedProject_t*) vader_gc_alloc(sizeof(vader_struct_vader_resolver_LoadedProject_t));
            vader_obj_header_init(_a23_obj, 860u);
            _a23_obj->f_entry = t1;
            _a23_obj->f_modules = l10;
            _a23_obj->f_factory = l4;
            _a23_obj->f_project_root = l7;
            _a23_obj->f_diags = l11;
            t0 = (void*) _a23_obj;
            { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        vader_unreachable("unreachable return in vader_resolver$load_project_with_overlay");
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
                if (l3.tag == 872u) {
                    t1 = l3.payload.obj;
                    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                }
                if (l3.tag == 0u) {
                    goto loop_4;
                }
                vader_unreachable("unreachable return in vader_resolver$lookup");
            } else {
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
            } else {
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
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 161u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(15u, 0u, 0u, 171u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 164u);
    l3 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__string__Any_t* _a3_obj = (vader_struct_std_collections_MutableMap__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__Any_t));
    vader_obj_header_init(_a3_obj, 309u);
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
                l3 = vader_resolver_symbol_make(l0, INT32_C(12), l6, 506u, 506u, (uint8_t) (int32_t) INT32_C(0), vader_box_obj(0u, NULL));
                std_collections_put__string__Any(l1, l6, vader_ref_box(l3));
                t1 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t1;
                goto loop_21;
            } else {
            }
        }
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void vader_resolver_mark_binding_immutable(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    vader_string_t l4 = 0;
    vader_box_t l5 = vader_box_null();
    int32_t l6;
    size_t l7, l8;
    void* t0 = NULL;
    int64_t t1;
    vader_box_t* gc_roots[2] = { &l1, &l5 };
    void** gc_raw_roots[4] = { &l0, &l2, &l3, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    if (l1.tag == 445u) {
        l2 = l1.payload.obj;
        l3 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_scope;
        l4 = ((vader_struct_toolchain_ast_SimpleBinding_t*) l2)->f_name;
        l5 = vader_resolver_lookup(l3, l4);
        if (l5.tag == 872u) {
            l2 = l5.payload.obj;
            l3 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_immutable_locals;
            l6 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l2)->f_id;
            std_collections_put__i32__bool(l3, l6, true);
            { vader_gc_top = gc_frame.prev; return; }
        }
        if (l5.tag == 0u) {
            { vader_gc_top = gc_frame.prev; return; }
        }
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 457u) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_toolchain_ast_TupleBinding_t*) t0)->f_elements;
        l7 = ((vader_array_t*) l2)->length;
        l8 = (size_t) (int64_t) INT64_C(0);
        {
            loop_50: {
                if ((l8 < l7)) {
                    vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
                    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                    if ((size_t) l8 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                    l5 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l8);
                    vader_resolver_mark_binding_immutable(l0, l5);
                    t1 = (l8 + INT64_C(1));
                    l8 = (size_t) (int64_t) t1;
                    goto loop_50;
                } else {
                }
            }
        }
    } else {
        if (l1.tag == 442u) {
            l2 = l1.payload.obj;
            l3 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_scope;
            l4 = ((vader_struct_toolchain_ast_RestBinding_t*) l2)->f_name;
            l5 = vader_resolver_lookup(l3, l4);
            if (l5.tag == 872u) {
                l2 = l5.payload.obj;
                l3 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_immutable_locals;
                l6 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l2)->f_id;
                std_collections_put__i32__bool(l3, l6, true);
            } else {
            }
        } else {
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
                t0 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l4, 167u);
                l5 = ((uint8_t) t0.payload.i);
                l6 = ((vader_struct_vader_target_Target_t*) l1)->f_os;
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
    void* l19 = NULL;
    int32_t l6, l7;
    vader_string_t l8 = 0;
    size_t l10, l11, l20;
    vader_box_t l13 = vader_box_null();
    bool t0;
    int32_t t1;
    int64_t t2;
    vader_box_t* gc_roots[1] = { &l13 };
    void** gc_raw_roots[14] = { &l0, &l1, &l2, &l3, &l4, &l5, &l9, &l12, &l14, &l15, &l16, &l17, &l18, &l19 };
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
    l8 = concat_2(508u, l8);
    vader_struct_vader_resolver_StampCtx_t* _a0_obj = (vader_struct_vader_resolver_StampCtx_t*) vader_gc_alloc(sizeof(vader_struct_vader_resolver_StampCtx_t));
    vader_obj_header_init(_a0_obj, 868u);
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
                    l20 = (size_t) (int64_t) INT64_C(1);
                    t2 = (l11 + l20);
                    l11 = (size_t) (int64_t) t2;
                    goto loop_47;
                }
                if (l13.tag == 384u) {
                    l14 = l13.payload.obj;
                    l15 = ((vader_struct_std_collections_MutableSet__string_t*) l3)->f_inner;
                    l8 = ((vader_struct_toolchain_ast_FnDecl_t*) l12)->f_name;
                    t0 = std_collections_contains_key__string__bool(l15, l8);
                    if (t0) {
                        t2 = (l11 + INT64_C(1));
                        l11 = (size_t) (int64_t) t2;
                        goto loop_47;
                    }
                    vader_array_t* _a2_arr = vader_array_new(21u, 0u, 13u, 393u);
                    l16 = (void*) _a2_arr;
                    l17 = vader_resolver_substitute_block_materialized(l14, l4, l2, l5);
                    l18 = ((vader_struct_toolchain_ast_ImplDecl_t*) l0)->f_members;
                    l19 = vader_resolver_synth_with_body(l12, l4, l16, l17, l5);
                    vader_array_push((vader_array_t*) l18, vader_ref_box(l19));
                    l20 = (size_t) (int64_t) INT64_C(1);
                    t2 = (l11 + l20);
                    l11 = (size_t) (int64_t) t2;
                    goto loop_47;
                }
                { vader_gc_top = gc_frame.prev; return; }
            } else {
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
    l6 = concat_2(508u, l6);
    vader_struct_vader_resolver_StampCtx_t* _a0_obj = (vader_struct_vader_resolver_StampCtx_t*) vader_gc_alloc(sizeof(vader_struct_vader_resolver_StampCtx_t));
    vader_obj_header_init(_a0_obj, 868u);
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
            } else {
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
            } else {
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
                vader_struct___Tuple_1128_t* _a2_obj = (vader_struct___Tuple_1128_t*) vader_gc_alloc(sizeof(vader_struct___Tuple_1128_t));
                vader_obj_header_init(_a2_obj, 194u);
                _a2_obj->f__0 = l7;
                _a2_obj->f__1 = l2;
                l8 = (void*) _a2_obj;
                l9 = ((vader_struct___Tuple_1128_t*) l8)->f__0;
                l10 = ((vader_struct___Tuple_1128_t*) l8)->f__1;
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
    void* l13 = NULL;
    void* l17 = NULL;
    void* l23 = NULL;
    void* l26 = NULL;
    size_t l6, l7, l24, l25;
    vader_string_t l8 = 0;
    vader_string_t l10 = 0;
    vader_string_t l20 = 0;
    vader_string_t l21 = 0;
    vader_string_t l22 = 0;
    vader_box_t l12 = vader_box_null(), l18 = vader_box_null();
    bool l14, l15, l16;
    uint8_t l19;
    int32_t l27, l28;
    vader_box_t t0 = vader_box_null();
    int64_t t1;
    void* t2 = NULL;
    vader_box_t* gc_roots[3] = { &l12, &l18, &t0 };
    void** gc_raw_roots[13] = { &l0, &l1, &l2, &l3, &l4, &l5, &l9, &l11, &l13, &l17, &l23, &l26, &t2 };
    vader_string_t* gc_atom_roots[5] = { &l8, &l10, &l20, &l21, &l22 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 13u, gc_roots, gc_raw_roots, 0u, NULL, 5u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_resolver_CollectedModule_t*) l1)->f_symbols;
    l4 = ((vader_struct_std_collections_MutableMap__string__Symbol_t*) l3)->f_ekeys;
    l5 = ((vader_struct_std_collections_MutableMap__string__Symbol_t*) l3)->f_evals;
    l6 = ((vader_struct_std_collections_MutableMap__string__Symbol_t*) l3)->f_size;
    l7 = (size_t) (int64_t) INT64_C(0);
    {
        loop_12: {
            if ((l7 >= l6)) {
            } else {
                vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
                if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                if ((size_t) l7 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l7];
                l8 = t0.payload.s;
                vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l7 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                l3 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l7);
                vader_struct___Tuple_1124_t* _a2_obj = (vader_struct___Tuple_1124_t*) vader_gc_alloc(sizeof(vader_struct___Tuple_1124_t));
                vader_obj_header_init(_a2_obj, 192u);
                _a2_obj->f__0 = l8;
                _a2_obj->f__1 = l3;
                l9 = (void*) _a2_obj;
                l10 = ((vader_struct___Tuple_1124_t*) l9)->f__0;
                l11 = ((vader_struct___Tuple_1124_t*) l9)->f__1;
                t1 = (l7 + INT64_C(1));
                l7 = (size_t) (int64_t) t1;
                l12 = std_collections_get__string__Any(((vader_struct_vader_resolver_CollectedModule_t*) l0)->f_symbols, l10);
                if (l12.tag == 0u) {
                    std_collections_put__string__Any(((vader_struct_vader_resolver_CollectedModule_t*) l0)->f_symbols, l10, vader_ref_box(l11));
                    goto loop_12;
                }
                if (l12.tag == 872u) {
                    l13 = l12.payload.obj;
                    if (((vader_struct_vader_resolver_symbol_Symbol_t*) l13)->f_kind == INT32_C(0)) {
                        l14 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l11)->f_kind == INT32_C(0);
                    } else {
                        l14 = false;
                    }
                    if (((vader_struct_vader_resolver_symbol_Symbol_t*) l13)->f_kind == INT32_C(7)) {
                        l15 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l11)->f_kind == INT32_C(7);
                    } else {
                        l15 = false;
                    }
                    if (!(l14)) {
                        l16 = !(l15);
                    } else {
                        l16 = false;
                    }
                    if (l16) {
                        l18 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l11)->f_defined_at;
                        if (l18.tag == 468u) {
                            l17 = l18.payload.obj;
                            l19 = (uint8_t) (int32_t) INT32_C(25);
                            l20 = 919u;
                            l21 = 926u;
                            l22 = concat_3(l20, l10, l21);
                            l23 = vader_diagnostics_resolver_error(l19, l17, l22);
                            vader_array_push((vader_array_t*) l2, vader_ref_box(l23));
                            goto loop_12;
                        }
                        if (l18.tag == 0u) {
                            l17 = vader_resolver_zero_span(0u);
                            l19 = (uint8_t) (int32_t) INT32_C(25);
                            l20 = 919u;
                            l21 = 926u;
                            l22 = concat_3(l20, l10, l21);
                            l23 = vader_diagnostics_resolver_error(l19, l17, l22);
                            vader_array_push((vader_array_t*) l2, vader_ref_box(l23));
                            goto loop_12;
                        }
                        { vader_gc_top = gc_frame.prev; return; }
                    }
                    goto loop_12;
                }
                { vader_gc_top = gc_frame.prev; return; }
            }
        }
    }
    l3 = ((vader_struct_vader_resolver_CollectedModule_t*) l1)->f_fn_overloads;
    l4 = ((vader_struct_std_collections_MutableMap__string__Symbol___t*) l3)->f_ekeys;
    l5 = ((vader_struct_std_collections_MutableMap__string__Symbol___t*) l3)->f_evals;
    l6 = ((vader_struct_std_collections_MutableMap__string__Symbol___t*) l3)->f_size;
    l7 = (size_t) (int64_t) INT64_C(0);
    {
        loop_169: {
            if ((l7 >= l6)) {
            } else {
                vader_array_t* _a3_slotarr = ((vader_array_t*) l4);
                if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                if ((size_t) l7 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_box_slots(_a3_slotarr->buf)[_a3_slotarr->offset + (size_t) l7];
                l8 = t0.payload.s;
                vader_array_t* _a4_slotarr = ((vader_array_t*) l5);
                if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                if ((size_t) l7 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                l3 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l7);
                vader_struct___Tuple_1135_t* _a5_obj = (vader_struct___Tuple_1135_t*) vader_gc_alloc(sizeof(vader_struct___Tuple_1135_t));
                vader_obj_header_init(_a5_obj, 197u);
                _a5_obj->f__0 = l8;
                _a5_obj->f__1 = l3;
                l9 = (void*) _a5_obj;
                l10 = ((vader_struct___Tuple_1135_t*) l9)->f__0;
                l11 = ((vader_struct___Tuple_1135_t*) l9)->f__1;
                t1 = (l7 + INT64_C(1));
                l7 = (size_t) (int64_t) t1;
                l12 = std_collections_get__string__Any(((vader_struct_vader_resolver_CollectedModule_t*) l0)->f_fn_overloads, l10);
                if (l12.tag == 0u) {
                    std_collections_put__string__Any(((vader_struct_vader_resolver_CollectedModule_t*) l0)->f_fn_overloads, l10, vader_ref_box(l11));
                } else {
                    l13 = l11;
                    l24 = ((vader_array_t*) l13)->length;
                    l25 = (size_t) (int64_t) INT64_C(0);
                    {
                        loop_215: {
                            if ((l25 < l24)) {
                                vader_array_t* _a6_slotarr = ((vader_array_t*) l13);
                                if (_a6_slotarr->buf != NULL && _a6_slotarr->buf->header.forward != NULL) { _a6_slotarr->buf = vader_array_buf_forward(_a6_slotarr->buf); }
                                if ((size_t) l25 >= _a6_slotarr->length) { vader_trap("array index out of bounds"); }
                                l17 = vader_array_ref_load_obj(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l25);
                                t2 = l12.payload.obj;
                                vader_array_push((vader_array_t*) t2, vader_ref_box(l17));
                                t1 = (l25 + INT64_C(1));
                                l25 = (size_t) (int64_t) t1;
                                goto loop_215;
                            } else {
                            }
                        }
                    }
                    l23 = ((vader_struct_vader_resolver_CollectedModule_t*) l0)->f_fn_overloads;
                    l26 = l12.payload.obj;
                    std_collections_put__string__Any(l23, l10, vader_ref_box(l26));
                }
                goto loop_169;
            }
        }
    }
    l3 = ((vader_struct_vader_resolver_CollectedModule_t*) l1)->f_imports;
    l4 = ((vader_struct_std_collections_MutableMap__i32__ImportInfo_t*) l3)->f_ekeys;
    l5 = ((vader_struct_std_collections_MutableMap__i32__ImportInfo_t*) l3)->f_evals;
    l6 = ((vader_struct_std_collections_MutableMap__i32__ImportInfo_t*) l3)->f_size;
    l7 = (size_t) (int64_t) INT64_C(0);
    {
        loop_263: {
            if ((l7 >= l6)) {
            } else {
                vader_array_t* _a7_slotarr = ((vader_array_t*) l4);
                if (_a7_slotarr->buf != NULL && _a7_slotarr->buf->header.forward != NULL) { _a7_slotarr->buf = vader_array_buf_forward(_a7_slotarr->buf); }
                if ((size_t) l7 >= _a7_slotarr->length) { vader_trap("array index out of bounds"); }
                l27 = ((int32_t*) _a7_slotarr->buf->slots)[_a7_slotarr->offset + (size_t) l7];
                vader_array_t* _a8_slotarr = ((vader_array_t*) l5);
                if (_a8_slotarr->buf != NULL && _a8_slotarr->buf->header.forward != NULL) { _a8_slotarr->buf = vader_array_buf_forward(_a8_slotarr->buf); }
                if ((size_t) l7 >= _a8_slotarr->length) { vader_trap("array index out of bounds"); }
                l3 = vader_array_ref_load_obj(_a8_slotarr->buf, _a8_slotarr->offset + (size_t) l7);
                vader_struct___Tuple_1131_t* _a9_obj = (vader_struct___Tuple_1131_t*) vader_gc_alloc(sizeof(vader_struct___Tuple_1131_t));
                vader_obj_header_init(_a9_obj, 196u);
                _a9_obj->f__0 = l27;
                _a9_obj->f__1 = l3;
                l9 = (void*) _a9_obj;
                l28 = ((vader_struct___Tuple_1131_t*) l9)->f__0;
                l11 = ((vader_struct___Tuple_1131_t*) l9)->f__1;
                t1 = (l7 + INT64_C(1));
                l7 = (size_t) (int64_t) t1;
                std_collections_put__i32__Any(((vader_struct_vader_resolver_CollectedModule_t*) l0)->f_imports, l28, vader_ref_box(l11));
                goto loop_263;
            }
        }
    }
    l3 = ((vader_struct_vader_resolver_CollectedModule_t*) l1)->f_import_paths;
    l6 = ((vader_array_t*) l3)->length;
    l7 = (size_t) (int64_t) INT64_C(0);
    {
        loop_305: {
            if ((l7 < l6)) {
                vader_array_t* _a10_slotarr = ((vader_array_t*) l3);
                if (_a10_slotarr->buf != NULL && _a10_slotarr->buf->header.forward != NULL) { _a10_slotarr->buf = vader_array_buf_forward(_a10_slotarr->buf); }
                if ((size_t) l7 >= _a10_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_box_slots(_a10_slotarr->buf)[_a10_slotarr->offset + (size_t) l7];
                l8 = t0.payload.s;
                vader_array_push((vader_array_t*) ((vader_struct_vader_resolver_CollectedModule_t*) l0)->f_import_paths, vader_box_string(161u, l8));
                t1 = (l7 + INT64_C(1));
                l7 = (size_t) (int64_t) t1;
                goto loop_305;
            } else {
            }
        }
    }
    l3 = ((vader_struct_vader_resolver_CollectedModule_t*) l0)->f_wildcards;
    l4 = ((vader_struct_vader_resolver_CollectedModule_t*) l1)->f_wildcards;
    vader_array_push_all((vader_array_t*) l3, (vader_array_t*) l4);
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
    if (l2 == 2378u) {
        l4 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_diags;
        l5 = concat_3(919u, l2, 919u);
        l6 = vader_diagnostics_resolver_error((uint8_t) (int32_t) INT32_C(18), l3, l5);
        vader_array_push((vader_array_t*) l4, vader_ref_box(l6));
    } else {
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
    vader_array_t* _a0_arr = vader_array_new(50u, 0u, 13u, 684u);
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
                t2 = vader_host_std_io_is_dir(l6);
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
                    t4 = vader_box_string(161u, t3);
                    { vader_box_t __vret = t4; vader_gc_top = gc_frame.prev; return __vret; }
                }
                t1 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t1;
                goto loop_8;
            } else {
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
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 161u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(15u, 0u, 0u, 171u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 164u);
    l3 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__string__Any_t* _a3_obj = (vader_struct_std_collections_MutableMap__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__Any_t));
    vader_obj_header_init(_a3_obj, 309u);
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
                vader_struct___Tuple_1126_t* _a6_obj = (vader_struct___Tuple_1126_t*) vader_gc_alloc(sizeof(vader_struct___Tuple_1126_t));
                vader_obj_header_init(_a6_obj, 193u);
                _a6_obj->f__0 = l7;
                _a6_obj->f__1 = l2;
                t1 = (void*) _a6_obj;
                l8 = ((vader_struct___Tuple_1126_t*) t1)->f__1;
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
    vader_array_t* _a0_arr = vader_array_new(9u, 0u, 7u, 164u);
    l0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(15u, 0u, 0u, 171u);
    l1 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 164u);
    l2 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__i32__Any_t* _a3_obj = (vader_struct_std_collections_MutableMap__i32__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__Any_t));
    vader_obj_header_init(_a3_obj, 272u);
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
    vader_array_t* _a0_arr = vader_array_new(9u, 0u, 7u, 164u);
    l0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(15u, 0u, 0u, 171u);
    l1 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 164u);
    l2 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__i32__Any_t* _a3_obj = (vader_struct_std_collections_MutableMap__i32__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__Any_t));
    vader_obj_header_init(_a3_obj, 272u);
    _a3_obj->f_ekeys = l0;
    _a3_obj->f_evals = l1;
    _a3_obj->f_index = l2;
    _a3_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l0 = (void*) _a3_obj;
    vader_array_t* _a4_arr = vader_array_new(9u, 0u, 7u, 164u);
    l1 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_new(8u, 0u, 0u, 161u);
    l2 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(9u, 0u, 7u, 164u);
    l3 = (void*) _a6_arr;
    vader_struct_std_collections_MutableMap__i32__string_t* _a7_obj = (vader_struct_std_collections_MutableMap__i32__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__string_t));
    vader_obj_header_init(_a7_obj, 303u);
    _a7_obj->f_ekeys = l1;
    _a7_obj->f_evals = l2;
    _a7_obj->f_index = l3;
    _a7_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a7_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a7_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l1 = (void*) _a7_obj;
    vader_array_t* _a8_arr = vader_array_new(9u, 0u, 7u, 164u);
    l2 = (void*) _a8_arr;
    vader_array_t* _a9_arr = vader_array_new(6u, 0u, 12u, 159u);
    l3 = (void*) _a9_arr;
    vader_array_t* _a10_arr = vader_array_new(9u, 0u, 7u, 164u);
    l4 = (void*) _a10_arr;
    vader_struct_std_collections_MutableMap__i32__bool_t* _a11_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
    vader_obj_header_init(_a11_obj, 299u);
    _a11_obj->f_ekeys = l2;
    _a11_obj->f_evals = l3;
    _a11_obj->f_index = l4;
    _a11_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a11_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a11_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l2 = (void*) _a11_obj;
    vader_struct_vader_resolver_ImportTargetTable_t* _a12_obj = (vader_struct_vader_resolver_ImportTargetTable_t*) vader_gc_alloc(sizeof(vader_struct_vader_resolver_ImportTargetTable_t));
    vader_obj_header_init(_a12_obj, 857u);
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
    vader_array_t* _a0_arr = vader_array_new(17u, 1u, 13u, 344u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = l0;
    t0 = (void*) _a0_arr;
    vader_struct_vader_resolver_Scope_t* _a1_obj = (vader_struct_vader_resolver_Scope_t*) vader_gc_alloc(sizeof(vader_struct_vader_resolver_Scope_t));
    vader_obj_header_init(_a1_obj, 866u);
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
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 161u);
    l0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(15u, 0u, 0u, 171u);
    l1 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 164u);
    l2 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__string__Any_t* _a3_obj = (vader_struct_std_collections_MutableMap__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__Any_t));
    vader_obj_header_init(_a3_obj, 309u);
    _a3_obj->f_ekeys = l0;
    _a3_obj->f_evals = l1;
    _a3_obj->f_index = l2;
    _a3_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    t0 = (void*) _a3_obj;
    vader_struct_vader_resolver_Subst_t* _a4_obj = (vader_struct_vader_resolver_Subst_t*) vader_gc_alloc(sizeof(vader_struct_vader_resolver_Subst_t));
    vader_obj_header_init(_a4_obj, 869u);
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
    vader_obj_header_init(_a0_obj, 467u);
    _a0_obj->f_file = l3;
    _a0_obj->f_offset = (size_t) (int64_t) INT64_C(0);
    _a0_obj->f_line = l2;
    _a0_obj->f_column = l1;
    l4 = (void*) _a0_obj;
    vader_struct_toolchain_span_Span_t* _a1_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
    vader_obj_header_init(_a1_obj, 468u);
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
    t0 = vader_resolver_join_path(l0, 2002u);
    t1 = vader_host_std_io_exists(t0);
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
    vader_array_t* _a0_arr = vader_array_new(86u, 0u, 13u, 867u);
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
                        } else {
                        }
                    }
                }
                vader_parser_assign_program_ids(((vader_struct_vader_parser_ParsedSource_t*) l10)->f_program, l3);
                l15 = ((vader_struct_vader_parser_ParsedSource_t*) l10)->f_program;
                vader_struct_vader_resolver_SourceFile_t* _a3_obj = (vader_struct_vader_resolver_SourceFile_t*) vader_gc_alloc(sizeof(vader_struct_vader_resolver_SourceFile_t));
                vader_obj_header_init(_a3_obj, 867u);
                _a3_obj->f_path = l8;
                _a3_obj->f_content = l9;
                _a3_obj->f_program = l15;
                _a3_obj->f_id_factory = l3;
                l16 = (void*) _a3_obj;
                vader_array_push((vader_array_t*) l4, vader_ref_box(l16));
                t1 = (l7 + INT64_C(1));
                l7 = (size_t) (int64_t) t1;
                goto loop_9;
            } else {
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
    vader_obj_header_init(_a0_obj, 858u);
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
    vader_array_t* _a0_arr = vader_array_new(17u, 0u, 13u, 344u);
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
            } else {
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
                            if (l10.tag == 417u) {
                                t0 = l10.payload.obj;
                                t1 = ((vader_struct_toolchain_ast_ImportDecl_t*) t0)->f_path;
                                vader_resolver_resolve_lazy(t1, l1, l2, l3);
                            } else {
                            }
                            t2 = (l9 + INT64_C(1));
                            l9 = (size_t) (int64_t) t2;
                            goto loop_23;
                        } else {
                        }
                    }
                }
                t2 = (l6 + INT64_C(1));
                l6 = (size_t) (int64_t) t2;
                goto loop_7;
            } else {
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
    vader_string_t l12 = 0;
    uint8_t l8;
    vader_box_t l10 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    int64_t t1;
    vader_string_t t2 = 0;
    vader_box_t* gc_roots[3] = { &l0, &l10, &t0 };
    void** gc_raw_roots[5] = { &l1, &l2, &l3, &l4, &l9 };
    vader_string_t* gc_atom_roots[4] = { &l7, &l11, &l12, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(83u, 0u, 13u, 858u);
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
            } else {
            }
        }
    }
    l10 = vader_resolver_sidecar_root(1767u, 2002u);
    if (!(l10.tag == 0u)) {
        t2 = l10.payload.s;
        l4 = vader_resolver_plain_root(t2, (uint8_t) (int32_t) INT32_C(1));
        vader_array_push((vader_array_t*) l3, vader_ref_box(l4));
    } else {
    }
    if (l0.tag == 161u) {
        l7 = l0.payload.s;
        l4 = vader_resolver_plain_root(l7, (uint8_t) (int32_t) INT32_C(0));
        vader_array_push((vader_array_t*) l3, vader_ref_box(l4));
        l4 = ((vader_struct_vader_resolver_Manifest_t*) l1)->f_include_paths;
        l5 = ((vader_array_t*) l4)->length;
        l6 = (size_t) (int64_t) INT64_C(0);
        {
            loop_73: {
                if ((l6 < l5)) {
                    vader_array_t* _a2_slotarr = ((vader_array_t*) l4);
                    if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                    if ((size_t) l6 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                    t0 = vader_array_box_slots(_a2_slotarr->buf)[_a2_slotarr->offset + (size_t) l6];
                    l11 = t0.payload.s;
                    l12 = vader_resolver_join_path(l7, l11);
                    l8 = vader_resolver_origin_of_root(l12);
                    l9 = vader_resolver_plain_root(l12, l8);
                    vader_array_push((vader_array_t*) l3, vader_ref_box(l9));
                    t1 = (l6 + INT64_C(1));
                    l6 = (size_t) (int64_t) t1;
                    goto loop_73;
                } else {
                }
            }
        }
        if (l10.tag == 0u) {
            l7 = 1767u;
            l8 = vader_resolver_origin_of_root(1767u);
            l4 = vader_resolver_plain_root(l7, l8);
            vader_array_push((vader_array_t*) l3, vader_ref_box(l4));
        } else {
        }
        { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 0u) {
        if (l10.tag == 0u) {
            l7 = 1767u;
            l8 = vader_resolver_origin_of_root(1767u);
            l4 = vader_resolver_plain_root(l7, l8);
            vader_array_push((vader_array_t*) l3, vader_ref_box(l4));
        } else {
        }
        { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_unreachable("unreachable return in vader_resolver$project_include_paths");
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
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 161u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(6u, 0u, 12u, 159u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 164u);
    l3 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__string__bool_t* _a3_obj = (vader_struct_std_collections_MutableMap__string__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__bool_t));
    vader_obj_header_init(_a3_obj, 348u);
    _a3_obj->f_ekeys = l1;
    _a3_obj->f_evals = l2;
    _a3_obj->f_index = l3;
    _a3_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    t0 = (void*) _a3_obj;
    vader_struct_std_collections_MutableSet__string_t* _a4_obj = (vader_struct_std_collections_MutableSet__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__string_t));
    vader_obj_header_init(_a4_obj, 368u);
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
            } else {
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
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 161u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(15u, 0u, 0u, 171u);
    l3 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 164u);
    l4 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__string__Any_t* _a3_obj = (vader_struct_std_collections_MutableMap__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__Any_t));
    vader_obj_header_init(_a3_obj, 309u);
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
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 161u);
    l1 = (void*) _a0_arr;
    l2 = vader_resolver_join_path(l0, 2285u);
    t0 = vader_host_std_io_exists(l2);
    if (!(t0)) {
        vader_struct_vader_resolver_Manifest_t* _a1_obj = (vader_struct_vader_resolver_Manifest_t*) vader_gc_alloc(sizeof(vader_struct_vader_resolver_Manifest_t));
        vader_obj_header_init(_a1_obj, 861u);
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
        vader_obj_header_init(_a2_obj, 861u);
        _a2_obj->f_include_paths = l1;
        t1 = (void*) _a2_obj;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = json_parse(l2);
    if (l3.tag == 269u) {
        t1 = l3.payload.obj;
        l3 = std_collections_get__string__Any(((vader_struct_json_JsonObject_t*) t1)->f_entries, 1677u);
        if (l3.tag == 264u) {
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
                        if (l3.tag == 270u) {
                            t1 = l3.payload.obj;
                            l2 = ((vader_struct_json_JsonString_t*) t1)->f_value;
                            vader_array_push((vader_array_t*) l1, vader_box_string(161u, l2));
                        } else {
                        }
                        t2 = (l6 + INT64_C(1));
                        l6 = (size_t) (int64_t) t2;
                        goto loop_55;
                    } else {
                    }
                }
            }
        } else {
        }
    } else {
    }
    vader_struct_vader_resolver_Manifest_t* _a4_obj = (vader_struct_vader_resolver_Manifest_t*) vader_gc_alloc(sizeof(vader_struct_vader_resolver_Manifest_t));
    vader_obj_header_init(_a4_obj, 861u);
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
    l2 = std_io_read_file_string(l1);
    if (l2.tag == 161u) {
        t0 = l2.payload.s;
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return 0u; }
    vader_gc_top = gc_frame.prev;
}

static void vader_resolver_report_uncovered(void* l0, void* l1, void* l2, void* l3, void* l4) {
    void* l5 = NULL;
    void* l8 = NULL;
    void* l12 = NULL;
    void* l18 = NULL;
    void* l24 = NULL;
    size_t l6, l7, l9, l10, l25;
    vader_box_t l11 = vader_box_null(), l13 = vader_box_null(), l17 = vader_box_null();
    vader_string_t l14 = 0;
    vader_string_t l15 = 0;
    vader_string_t l16 = 0;
    vader_string_t l19 = 0;
    vader_string_t l20 = 0;
    vader_string_t l21 = 0;
    vader_string_t l22 = 0;
    vader_string_t l23 = 0;
    void* t0 = NULL;
    int64_t t1;
    bool t2;
    vader_box_t t3 = vader_box_null();
    vader_box_t* gc_roots[4] = { &l11, &l13, &l17, &t3 };
    void** gc_raw_roots[11] = { &l0, &l1, &l2, &l3, &l4, &l5, &l8, &l12, &l18, &l24, &t0 };
    vader_string_t* gc_atom_roots[8] = { &l14, &l15, &l16, &l19, &l20, &l21, &l22, &l23 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 11u, gc_roots, gc_raw_roots, 0u, NULL, 8u, gc_atom_roots };
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
                            if (l11.tag == 407u) {
                                l12 = l11.payload.obj;
                                l13 = vader_resolver_target_selectors(((vader_struct_toolchain_ast_FnDecl_t*) l12)->f_decorators);
                                if (l13.tag == 0u) {
                                    t1 = (l10 + INT64_C(1));
                                    l10 = (size_t) (int64_t) t1;
                                    goto loop_23;
                                }
                                t0 = l13.payload.obj;
                                t2 = ((vader_struct_vader_resolver_TargetSelectors_t*) t0)->f_is_bare;
                                if (!(t2)) {
                                    t1 = (l10 + INT64_C(1));
                                    l10 = (size_t) (int64_t) t1;
                                    goto loop_23;
                                }
                                if (!(((vader_struct_toolchain_ast_FnDecl_t*) l12)->f_body.tag == 0u)) {
                                    t1 = (l10 + INT64_C(1));
                                    l10 = (size_t) (int64_t) t1;
                                    goto loop_23;
                                }
                                l14 = ((vader_struct_toolchain_ast_FnDecl_t*) l12)->f_name;
                                t3 = std_collections_get__string__Any(l2, l14);
                                if (!(t3.tag == 0u)) {
                                    t1 = (l10 + INT64_C(1));
                                    l10 = (size_t) (int64_t) t1;
                                    goto loop_23;
                                }
                                t2 = vader_resolver_is_host_bound(l12);
                                if (t2) {
                                    t1 = (l10 + INT64_C(1));
                                    l10 = (size_t) (int64_t) t1;
                                    goto loop_23;
                                }
                                l16 = ((vader_struct_toolchain_ast_FnDecl_t*) l12)->f_name;
                                l17 = std_collections_get__string__string(l3, l16);
                                if (l17.tag == 0u) {
                                    l15 = 323u;
                                } else {
                                    l15 = l17.payload.s;
                                }
                                l18 = ((vader_struct_toolchain_ast_FnDecl_t*) l12)->f_name_span;
                                l19 = ((vader_struct_toolchain_ast_FnDecl_t*) l12)->f_name;
                                l20 = vader_target_display_target(l1);
                                l21 = concat_5(919u, l19, 949u, l20, 931u);
                                l22 = concat_2(1731u, l15);
                                l23 = concat_2(l21, l22);
                                l24 = vader_diagnostics_resolver_error((uint8_t) (int32_t) INT32_C(40), l18, l23);
                                vader_array_push((vader_array_t*) l4, vader_ref_box(l24));
                                l25 = (size_t) (int64_t) INT64_C(1);
                                t1 = (l10 + l25);
                                l10 = (size_t) (int64_t) t1;
                                goto loop_23;
                            }
                            l25 = (size_t) (int64_t) INT64_C(1);
                            t1 = (l10 + l25);
                            l10 = (size_t) (int64_t) t1;
                            goto loop_23;
                        } else {
                        }
                    }
                }
                t1 = (l7 + INT64_C(1));
                l7 = (size_t) (int64_t) t1;
                goto loop_7;
            } else {
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
    size_t l3, l4, l7;
    vader_box_t l6 = vader_box_null();
    int64_t t0;
    vader_box_t* gc_roots[1] = { &l6 };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(23u, 0u, 13u, 407u);
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
                    l7 = (size_t) (int64_t) INT64_C(1);
                    t0 = (l4 + l7);
                    l4 = (size_t) (int64_t) t0;
                    goto loop_9;
                }
                if (l6.tag == 384u) {
                    l7 = (size_t) (int64_t) INT64_C(1);
                    t0 = (l4 + l7);
                    l4 = (size_t) (int64_t) t0;
                    goto loop_9;
                }
                vader_unreachable("unreachable return in vader_resolver$required_methods");
            } else {
            }
        }
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_box_t vader_resolver_resolve_decl(vader_box_t l0, void* l1, void* l2, void* l3) {
    void* l4 = NULL;
    void* l7 = NULL;
    vader_box_t l5 = vader_box_null();
    vader_string_t l6 = 0;
    void* t0 = NULL;
    bool t1;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l0, &l5, &t2 };
    void** gc_raw_roots[6] = { &l1, &l2, &l3, &l4, &l7, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l6 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    if (l0.tag == 407u) {
        l4 = l0.payload.obj;
        l5 = vader_resolver_target_selectors(((vader_struct_toolchain_ast_FnDecl_t*) l4)->f_decorators);
        if (l5.tag == 0u) {
            t0 = l0.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t0 = l5.payload.obj;
        t1 = ((vader_struct_vader_resolver_TargetSelectors_t*) t0)->f_is_bare;
        if (t1) {
            l6 = ((vader_struct_toolchain_ast_FnDecl_t*) l4)->f_name;
            l5 = std_collections_get__string__Any(l2, l6);
            if (l5.tag == 0u) {
                t0 = l0.payload.obj;
                { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l7 = l5.payload.obj;
            t0 = vader_resolver_graft_body(l4, l7);
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
    if (l4.tag == 853u) {
        t0 = l4.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = vader_box_obj(0u, NULL);
    l5 = (uint8_t) (int32_t) INT32_C(0);
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 161u);
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
                t1 = vader_host_std_io_is_dir(l11);
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
                    l4 = vader_box_string(161u, l11);
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
            } else {
            }
        }
    }
    if (l4.tag == 0u) {
        t4 = vader_box_obj(0u, NULL);
        { vader_box_t __vret = t4; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l11 = l4.payload.s;
    vader_struct_vader_resolver_DiscoveredModule_t* _a4_obj = (vader_struct_vader_resolver_DiscoveredModule_t*) vader_gc_alloc(sizeof(vader_struct_vader_resolver_DiscoveredModule_t));
    vader_obj_header_init(_a4_obj, 853u);
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
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 161u);
    l5 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(15u, 0u, 0u, 171u);
    l6 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 164u);
    l7 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__string__Any_t* _a3_obj = (vader_struct_std_collections_MutableMap__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__Any_t));
    vader_obj_header_init(_a3_obj, 309u);
    _a3_obj->f_ekeys = l5;
    _a3_obj->f_evals = l6;
    _a3_obj->f_index = l7;
    _a3_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l5 = (void*) _a3_obj;
    vader_array_t* _a4_arr = vader_array_new(8u, 0u, 0u, 161u);
    l6 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_new(15u, 0u, 0u, 171u);
    l7 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(9u, 0u, 7u, 164u);
    l8 = (void*) _a6_arr;
    vader_struct_std_collections_MutableMap__string__Any___t* _a7_obj = (vader_struct_std_collections_MutableMap__string__Any___t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__Any___t));
    vader_obj_header_init(_a7_obj, 311u);
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
            } else {
            }
        }
    }
    l9 = l5;
    l12 = ((vader_struct_std_collections_MutableMap__string__Symbol_t*) l9)->f_ekeys;
    l14 = ((vader_struct_std_collections_MutableMap__string__Symbol_t*) l9)->f_evals;
    l10 = ((vader_struct_std_collections_MutableMap__string__Symbol_t*) l9)->f_size;
    l11 = (size_t) (int64_t) INT64_C(0);
    {
        loop_49: {
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
                vader_struct___Tuple_1124_t* _a3_obj = (vader_struct___Tuple_1124_t*) vader_gc_alloc(sizeof(vader_struct___Tuple_1124_t));
                vader_obj_header_init(_a3_obj, 192u);
                _a3_obj->f__0 = l13;
                _a3_obj->f__1 = l9;
                l15 = (void*) _a3_obj;
                l16 = ((vader_struct___Tuple_1124_t*) l15)->f__0;
                l17 = ((vader_struct___Tuple_1124_t*) l15)->f__1;
                t0 = (l11 + INT64_C(1));
                l11 = (size_t) (int64_t) t0;
                t1 = std_collections_get__string__Any(l7, l16);
                if (t1.tag == 0u) {
                    std_collections_put__string__Any(l7, l16, vader_ref_box(l17));
                } else {
                }
                goto loop_49;
            }
        }
    }
    l7 = vader_resolver_resolve_program(l0, l7, l1, l3, l6);
    l8 = vader_resolver_sort_by_name(l8);
    l9 = ((vader_struct_vader_resolver_ResolvedFile_t*) l7)->f_idents;
    l12 = ((vader_struct_vader_resolver_ResolvedFile_t*) l7)->f_immutable_locals;
    l14 = ((vader_struct_vader_resolver_ResolvedFile_t*) l7)->f_immutable_borrows;
    l15 = ((vader_struct_vader_resolver_CollectedModule_t*) l4)->f_fn_overloads;
    vader_array_t* _a4_arr = vader_array_new(9u, 0u, 7u, 164u);
    l17 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_new(15u, 0u, 0u, 171u);
    l18 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(9u, 0u, 7u, 164u);
    l19 = (void*) _a6_arr;
    vader_struct_std_collections_MutableMap__i32__Any_t* _a7_obj = (vader_struct_std_collections_MutableMap__i32__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__Any_t));
    vader_obj_header_init(_a7_obj, 272u);
    _a7_obj->f_ekeys = l17;
    _a7_obj->f_evals = l18;
    _a7_obj->f_index = l19;
    _a7_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a7_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a7_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l17 = (void*) _a7_obj;
    vader_array_t* _a8_arr = vader_array_new(9u, 0u, 7u, 164u);
    l18 = (void*) _a8_arr;
    vader_array_t* _a9_arr = vader_array_new(15u, 0u, 0u, 171u);
    l19 = (void*) _a9_arr;
    vader_array_t* _a10_arr = vader_array_new(9u, 0u, 7u, 164u);
    l20 = (void*) _a10_arr;
    vader_struct_std_collections_MutableMap__i32__Any_t* _a11_obj = (vader_struct_std_collections_MutableMap__i32__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__Any_t));
    vader_obj_header_init(_a11_obj, 272u);
    _a11_obj->f_ekeys = l18;
    _a11_obj->f_evals = l19;
    _a11_obj->f_index = l20;
    _a11_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a11_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a11_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l18 = (void*) _a11_obj;
    vader_array_t* _a12_arr = vader_array_new(9u, 0u, 7u, 164u);
    l19 = (void*) _a12_arr;
    vader_array_t* _a13_arr = vader_array_new(15u, 0u, 0u, 171u);
    l20 = (void*) _a13_arr;
    vader_array_t* _a14_arr = vader_array_new(9u, 0u, 7u, 164u);
    l21 = (void*) _a14_arr;
    vader_struct_std_collections_MutableMap__i32__Any_t* _a15_obj = (vader_struct_std_collections_MutableMap__i32__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__Any_t));
    vader_obj_header_init(_a15_obj, 272u);
    _a15_obj->f_ekeys = l19;
    _a15_obj->f_evals = l20;
    _a15_obj->f_index = l21;
    _a15_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a15_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a15_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l19 = (void*) _a15_obj;
    l20 = ((vader_struct_vader_resolver_ResolvedFile_t*) l7)->f_type_param_bounds;
    l7 = ((vader_struct_vader_resolver_ResolvedFile_t*) l7)->f_diags;
    vader_array_t* _a16_arr = vader_array_new(9u, 0u, 7u, 164u);
    l21 = (void*) _a16_arr;
    vader_array_t* _a17_arr = vader_array_new(8u, 0u, 0u, 161u);
    l22 = (void*) _a17_arr;
    vader_array_t* _a18_arr = vader_array_new(9u, 0u, 7u, 164u);
    l23 = (void*) _a18_arr;
    vader_struct_std_collections_MutableMap__i32__string_t* _a19_obj = (vader_struct_std_collections_MutableMap__i32__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__string_t));
    vader_obj_header_init(_a19_obj, 303u);
    _a19_obj->f_ekeys = l21;
    _a19_obj->f_evals = l22;
    _a19_obj->f_index = l23;
    _a19_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a19_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a19_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l21 = (void*) _a19_obj;
    vader_array_t* _a20_arr = vader_array_new(9u, 0u, 7u, 164u);
    l22 = (void*) _a20_arr;
    vader_array_t* _a21_arr = vader_array_new(15u, 0u, 0u, 171u);
    l23 = (void*) _a21_arr;
    vader_array_t* _a22_arr = vader_array_new(9u, 0u, 7u, 164u);
    l24 = (void*) _a22_arr;
    vader_struct_std_collections_MutableMap__i32__MutableMap_Any__Any__t* _a23_obj = (vader_struct_std_collections_MutableMap__i32__MutableMap_Any__Any__t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__MutableMap_Any__Any__t));
    vader_obj_header_init(_a23_obj, 287u);
    _a23_obj->f_ekeys = l22;
    _a23_obj->f_evals = l23;
    _a23_obj->f_index = l24;
    _a23_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a23_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a23_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l22 = (void*) _a23_obj;
    vader_array_t* _a24_arr = vader_array_new(9u, 0u, 7u, 164u);
    l23 = (void*) _a24_arr;
    vader_array_t* _a25_arr = vader_array_new(15u, 0u, 0u, 171u);
    l24 = (void*) _a25_arr;
    vader_array_t* _a26_arr = vader_array_new(9u, 0u, 7u, 164u);
    l25 = (void*) _a26_arr;
    vader_struct_std_collections_MutableMap__i32__MutableMap_Any__Any__t* _a27_obj = (vader_struct_std_collections_MutableMap__i32__MutableMap_Any__Any__t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__MutableMap_Any__Any__t));
    vader_obj_header_init(_a27_obj, 287u);
    _a27_obj->f_ekeys = l23;
    _a27_obj->f_evals = l24;
    _a27_obj->f_index = l25;
    _a27_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a27_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a27_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l23 = (void*) _a27_obj;
    vader_struct_vader_resolver_ResolvedModule_t* _a28_obj = (vader_struct_vader_resolver_ResolvedModule_t*) vader_gc_alloc(sizeof(vader_struct_vader_resolver_ResolvedModule_t));
    vader_obj_header_init(_a28_obj, 865u);
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
    vader_array_t* _a0_arr = vader_array_new(13u, 0u, 4u, 169u);
    l5 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(15u, 0u, 0u, 171u);
    l6 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 164u);
    l7 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__u64__Any_t* _a3_obj = (vader_struct_std_collections_MutableMap__u64__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__u64__Any_t));
    vader_obj_header_init(_a3_obj, 355u);
    _a3_obj->f_ekeys = l5;
    _a3_obj->f_evals = l6;
    _a3_obj->f_index = l7;
    _a3_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l5 = (void*) _a3_obj;
    vader_array_t* _a4_arr = vader_array_new(9u, 0u, 7u, 164u);
    l6 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_new(6u, 0u, 12u, 159u);
    l7 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(9u, 0u, 7u, 164u);
    l8 = (void*) _a6_arr;
    vader_struct_std_collections_MutableMap__i32__bool_t* _a7_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
    vader_obj_header_init(_a7_obj, 299u);
    _a7_obj->f_ekeys = l6;
    _a7_obj->f_evals = l7;
    _a7_obj->f_index = l8;
    _a7_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a7_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a7_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l6 = (void*) _a7_obj;
    vader_array_t* _a8_arr = vader_array_new(9u, 0u, 7u, 164u);
    l7 = (void*) _a8_arr;
    vader_array_t* _a9_arr = vader_array_new(6u, 0u, 12u, 159u);
    l8 = (void*) _a9_arr;
    vader_array_t* _a10_arr = vader_array_new(9u, 0u, 7u, 164u);
    l9 = (void*) _a10_arr;
    vader_struct_std_collections_MutableMap__i32__bool_t* _a11_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
    vader_obj_header_init(_a11_obj, 299u);
    _a11_obj->f_ekeys = l7;
    _a11_obj->f_evals = l8;
    _a11_obj->f_index = l9;
    _a11_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a11_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a11_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l7 = (void*) _a11_obj;
    vader_array_t* _a12_arr = vader_array_new(9u, 0u, 7u, 164u);
    l8 = (void*) _a12_arr;
    vader_array_t* _a13_arr = vader_array_new(15u, 0u, 0u, 171u);
    l9 = (void*) _a13_arr;
    vader_array_t* _a14_arr = vader_array_new(9u, 0u, 7u, 164u);
    l10 = (void*) _a14_arr;
    vader_struct_std_collections_MutableMap__i32__Any_t* _a15_obj = (vader_struct_std_collections_MutableMap__i32__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__Any_t));
    vader_obj_header_init(_a15_obj, 272u);
    _a15_obj->f_ekeys = l8;
    _a15_obj->f_evals = l9;
    _a15_obj->f_index = l10;
    _a15_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a15_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a15_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l8 = (void*) _a15_obj;
    vader_array_t* _a16_arr = vader_array_new(50u, 0u, 13u, 684u);
    l9 = (void*) _a16_arr;
    l10 = vader_resolver_new_scope(l1);
    vader_struct_vader_resolver_ResolveState_t* _a17_obj = (vader_struct_vader_resolver_ResolveState_t*) vader_gc_alloc(sizeof(vader_struct_vader_resolver_ResolveState_t));
    vader_obj_header_init(_a17_obj, 863u);
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
            } else {
            }
        }
    }
    l6 = ((vader_struct_vader_resolver_ResolveState_t*) l5)->f_idents;
    l7 = ((vader_struct_vader_resolver_ResolveState_t*) l5)->f_immutable_locals;
    l8 = ((vader_struct_vader_resolver_ResolveState_t*) l5)->f_immutable_borrows;
    l9 = ((vader_struct_vader_resolver_ResolveState_t*) l5)->f_type_param_bounds;
    l5 = ((vader_struct_vader_resolver_ResolveState_t*) l5)->f_diags;
    vader_struct_vader_resolver_ResolvedFile_t* _a19_obj = (vader_struct_vader_resolver_ResolvedFile_t*) vader_gc_alloc(sizeof(vader_struct_vader_resolver_ResolvedFile_t));
    vader_obj_header_init(_a19_obj, 864u);
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
        t2 = vader_box_string(161u, t1);
        { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = ((vader_struct_vader_resolver_IncludePath_t*) l0)->f_prefix;
    if (l1 == l2) {
        t0 = ((vader_struct_vader_resolver_IncludePath_t*) l0)->f_dir;
        t2 = vader_box_string(161u, t0);
        { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_vader_resolver_IncludePath_t*) l0)->f_prefix;
    l2 = concat_2(t0, 438u);
    t3 = std_string_starts_with(l1, l2);
    if (t3) {
        l2 = ((vader_struct_vader_resolver_IncludePath_t*) l0)->f_dir;
        t0 = ((vader_struct_vader_resolver_IncludePath_t*) l0)->f_prefix;
        l3 = concat_2(t0, 438u);
        l3 = std_string_trim_prefix(l1, l3);
        t0 = vader_resolver_join_path(l2, l3);
        t2 = vader_box_string(161u, t0);
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
                            if (l11.tag == 416u) {
                                l12 = l11.payload.obj;
                                l13 = ((vader_struct_vader_resolver_CollectedModule_t*) ((vader_struct_vader_resolver_LoadedModule_t*) l0)->f_collected)->f_symbols;
                                vader_resolver_check_orphan_rule(l12, l1, l13, l2, l3, l4);
                            } else {
                            }
                            t1 = (l10 + INT64_C(1));
                            l10 = (size_t) (int64_t) t1;
                            goto loop_24;
                        } else {
                        }
                    }
                }
                t1 = (l7 + INT64_C(1));
                l7 = (size_t) (int64_t) t1;
                goto loop_8;
            } else {
            }
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static vader_box_t vader_resolver_scan_folder(vader_string_t l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l26 = vader_box_null(), l30 = vader_box_null();
    void* l3 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l19 = NULL;
    void* l20 = NULL;
    void* l21 = NULL;
    void* l22 = NULL;
    void* l32 = NULL;
    void* l36 = NULL;
    void* l37 = NULL;
    void* l41 = NULL;
    void* l45 = NULL;
    void* l52 = NULL;
    size_t l4, l5, l9, l10, l15, l16, l17, l23, l24, l29, l53;
    vader_string_t l11 = 0;
    vader_string_t l12 = 0;
    vader_string_t l13 = 0;
    vader_string_t l18 = 0;
    vader_string_t l25 = 0;
    vader_string_t l27 = 0;
    vader_string_t l28 = 0;
    vader_string_t l33 = 0;
    vader_string_t l34 = 0;
    vader_string_t l35 = 0;
    vader_string_t l38 = 0;
    vader_string_t l39 = 0;
    vader_string_t l40 = 0;
    vader_string_t l42 = 0;
    vader_string_t l43 = 0;
    vader_string_t l46 = 0;
    vader_string_t l47 = 0;
    vader_string_t l48 = 0;
    vader_string_t l49 = 0;
    vader_string_t l50 = 0;
    vader_string_t l51 = 0;
    bool l14;
    uint8_t l31, l44;
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    bool t2;
    int64_t t3;
    vader_box_t* gc_roots[4] = { &l2, &l26, &l30, &t0 };
    void** gc_raw_roots[16] = { &l1, &l3, &l6, &l7, &l8, &l19, &l20, &l21, &l22, &l32, &l36, &l37, &l41, &l45, &l52, &t1 };
    vader_string_t* gc_atom_roots[22] = { &l0, &l11, &l12, &l13, &l18, &l25, &l27, &l28, &l33, &l34, &l35, &l38, &l39, &l40, &l42, &l43, &l46, &l47, &l48, &l49, &l50, &l51 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 16u, gc_roots, gc_raw_roots, 0u, NULL, 22u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = vader_host_std_io_read_dir(l0);
    if (l2.tag == 8u) {
        l3 = l2.payload.obj;
        l4 = ((vader_array_t*) l3)->length;
        l5 = (size_t) (int64_t) INT64_C(0);
        if (l4 == l5) {
            t0 = vader_box_obj(0u, NULL);
            { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        vader_struct___lambda_env_3065_t* _a0_obj = (vader_struct___lambda_env_3065_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_3065_t));
        vader_obj_header_init(_a0_obj, 254u);
        t1 = (void*) _a0_obj;
        vader_fn_t* _a1_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
        vader_obj_header_init(_a1_closure, 135u);
        _a1_closure->code = (void*) &vader_fn_lift_303;
        _a1_closure->env = t1;
        l6 = (void*) _a1_closure;
        l8 = std_sort_sort__string(l3, l6);
        vader_array_t* _a2_arr = vader_array_new(8u, 0u, 0u, 161u);
        l7 = (void*) _a2_arr;
        l9 = ((vader_array_t*) l8)->length;
        l10 = (size_t) (int64_t) INT64_C(0);
        {
            loop_35: {
                if ((l10 < l9)) {
                    vader_array_t* _a3_slotarr = ((vader_array_t*) l8);
                    if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                    if ((size_t) l10 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                    t0 = vader_array_box_slots(_a3_slotarr->buf)[_a3_slotarr->offset + (size_t) l10];
                    l11 = t0.payload.s;
                    l12 = vader_resolver_join_path(l0, l11);
                    l13 = 437u;
                    t2 = std_string_ends_with(l11, l13);
                    if (t2) {
                        t2 = vader_host_std_io_is_dir(l12);
                        l14 = !(t2);
                    } else {
                        l14 = false;
                    }
                    if (l14) {
                        vader_array_push((vader_array_t*) l7, vader_box_string(161u, l12));
                    } else {
                    }
                    l15 = (size_t) (int64_t) INT64_C(1);
                    t3 = (l10 + l15);
                    l10 = (size_t) (int64_t) t3;
                    goto loop_35;
                } else {
                }
            }
        }
        l16 = ((vader_array_t*) l7)->length;
        l17 = (size_t) (int64_t) INT64_C(0);
        if (l16 == l17) {
            t0 = vader_box_obj(0u, NULL);
            { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l18 = 0u;
        l19 = toolchain_span_empty_span();
        vader_array_t* _a4_arr = vader_array_new(8u, 0u, 0u, 161u);
        l20 = (void*) _a4_arr;
        vader_struct_vader_resolver_FolderBucket_t* _a5_obj = (vader_struct_vader_resolver_FolderBucket_t*) vader_gc_alloc(sizeof(vader_struct_vader_resolver_FolderBucket_t));
        vader_obj_header_init(_a5_obj, 855u);
        _a5_obj->f_name = l18;
        _a5_obj->f_first_decl_span = l19;
        _a5_obj->f_files = l20;
        l21 = (void*) _a5_obj;
        l22 = l7;
        l23 = ((vader_array_t*) l22)->length;
        l24 = (size_t) (int64_t) INT64_C(0);
        {
            loop_112: {
                if ((l24 < l23)) {
                    vader_array_t* _a6_slotarr = ((vader_array_t*) l22);
                    if (_a6_slotarr->buf != NULL && _a6_slotarr->buf->header.forward != NULL) { _a6_slotarr->buf = vader_array_buf_forward(_a6_slotarr->buf); }
                    if ((size_t) l24 >= _a6_slotarr->length) { vader_trap("array index out of bounds"); }
                    t0 = vader_array_box_slots(_a6_slotarr->buf)[_a6_slotarr->offset + (size_t) l24];
                    l25 = t0.payload.s;
                    l26 = std_io_read_file_string(l25);
                    if (l26.tag == 161u) {
                        l27 = l26.payload.s;
                        l28 = 0u;
                        if (l27 == l28) {
                            l29 = (size_t) (int64_t) INT64_C(1);
                            t3 = (l24 + l29);
                            l24 = (size_t) (int64_t) t3;
                            goto loop_112;
                        }
                        vader_array_push((vader_array_t*) ((vader_struct_vader_resolver_FolderBucket_t*) l21)->f_files, vader_box_string(161u, l25));
                        l30 = vader_parser_parse_module_header(l27, l25);
                        if (l30.tag == 0u) {
                            l31 = (uint8_t) (int32_t) INT32_C(19);
                            l32 = toolchain_span_empty_span();
                            l33 = 919u;
                            l34 = 919u;
                            l35 = concat_3(l33, l25, l34);
                            l36 = vader_diagnostics_resolver_error(l31, l32, l35);
                            vader_array_push((vader_array_t*) l1, vader_ref_box(l36));
                            l53 = (size_t) (int64_t) INT64_C(1);
                            t3 = (l24 + l53);
                            l24 = (size_t) (int64_t) t3;
                            goto loop_112;
                        }
                        if (l30.tag == 847u) {
                            l37 = l30.payload.obj;
                            l38 = ((vader_struct_vader_resolver_FolderBucket_t*) l21)->f_name;
                            l39 = 0u;
                            if (l38 == l39) {
                                l40 = ((vader_struct_vader_parser_ModuleHeader_t*) l37)->f_name;
                                ((vader_struct_vader_resolver_FolderBucket_t*) l21)->f_name = l40;
                                VADER_WRITE_BARRIER((vader_struct_vader_resolver_FolderBucket_t*) l21);
                                l41 = ((vader_struct_vader_parser_ModuleHeader_t*) l37)->f_name_span;
                                ((vader_struct_vader_resolver_FolderBucket_t*) l21)->f_first_decl_span = l41;
                                VADER_WRITE_BARRIER((vader_struct_vader_resolver_FolderBucket_t*) l21);
                            } else {
                                l42 = ((vader_struct_vader_parser_ModuleHeader_t*) l37)->f_name;
                                l43 = ((vader_struct_vader_resolver_FolderBucket_t*) l21)->f_name;
                                if (l42 != l43) {
                                    l44 = (uint8_t) (int32_t) INT32_C(21);
                                    l45 = ((vader_struct_vader_parser_ModuleHeader_t*) l37)->f_name_span;
                                    l46 = 919u;
                                    l47 = ((vader_struct_vader_parser_ModuleHeader_t*) l37)->f_name;
                                    l48 = 939u;
                                    l49 = ((vader_struct_vader_resolver_FolderBucket_t*) l21)->f_name;
                                    l50 = 1006u;
                                    l51 = concat_5(l46, l47, l48, l49, l50);
                                    l52 = vader_diagnostics_resolver_error(l44, l45, l51);
                                    vader_array_push((vader_array_t*) l1, vader_ref_box(l52));
                                } else {
                                }
                            }
                            l53 = (size_t) (int64_t) INT64_C(1);
                            t3 = (l24 + l53);
                            l24 = (size_t) (int64_t) t3;
                            goto loop_112;
                        }
                        vader_unreachable("unreachable return in vader_resolver$scan_folder");
                    }
                    if (l26.tag == 374u) {
                        l27 = 0u;
                        l28 = 0u;
                        if (l27 == l28) {
                            l29 = (size_t) (int64_t) INT64_C(1);
                            t3 = (l24 + l29);
                            l24 = (size_t) (int64_t) t3;
                            goto loop_112;
                        }
                        vader_array_push((vader_array_t*) ((vader_struct_vader_resolver_FolderBucket_t*) l21)->f_files, vader_box_string(161u, l25));
                        l30 = vader_parser_parse_module_header(l27, l25);
                        if (l30.tag == 0u) {
                            l31 = (uint8_t) (int32_t) INT32_C(19);
                            l32 = toolchain_span_empty_span();
                            l33 = 919u;
                            l34 = 919u;
                            l35 = concat_3(l33, l25, l34);
                            l36 = vader_diagnostics_resolver_error(l31, l32, l35);
                            vader_array_push((vader_array_t*) l1, vader_ref_box(l36));
                            l53 = (size_t) (int64_t) INT64_C(1);
                            t3 = (l24 + l53);
                            l24 = (size_t) (int64_t) t3;
                            goto loop_112;
                        }
                        if (l30.tag == 847u) {
                            l37 = l30.payload.obj;
                            l38 = ((vader_struct_vader_resolver_FolderBucket_t*) l21)->f_name;
                            l39 = 0u;
                            if (l38 == l39) {
                                l40 = ((vader_struct_vader_parser_ModuleHeader_t*) l37)->f_name;
                                ((vader_struct_vader_resolver_FolderBucket_t*) l21)->f_name = l40;
                                VADER_WRITE_BARRIER((vader_struct_vader_resolver_FolderBucket_t*) l21);
                                l41 = ((vader_struct_vader_parser_ModuleHeader_t*) l37)->f_name_span;
                                ((vader_struct_vader_resolver_FolderBucket_t*) l21)->f_first_decl_span = l41;
                                VADER_WRITE_BARRIER((vader_struct_vader_resolver_FolderBucket_t*) l21);
                            } else {
                                l42 = ((vader_struct_vader_parser_ModuleHeader_t*) l37)->f_name;
                                l43 = ((vader_struct_vader_resolver_FolderBucket_t*) l21)->f_name;
                                if (l42 != l43) {
                                    l44 = (uint8_t) (int32_t) INT32_C(21);
                                    l45 = ((vader_struct_vader_parser_ModuleHeader_t*) l37)->f_name_span;
                                    l46 = 919u;
                                    l47 = ((vader_struct_vader_parser_ModuleHeader_t*) l37)->f_name;
                                    l48 = 939u;
                                    l49 = ((vader_struct_vader_resolver_FolderBucket_t*) l21)->f_name;
                                    l50 = 1006u;
                                    l51 = concat_5(l46, l47, l48, l49, l50);
                                    l52 = vader_diagnostics_resolver_error(l44, l45, l51);
                                    vader_array_push((vader_array_t*) l1, vader_ref_box(l52));
                                } else {
                                }
                            }
                            l53 = (size_t) (int64_t) INT64_C(1);
                            t3 = (l24 + l53);
                            l24 = (size_t) (int64_t) t3;
                            goto loop_112;
                        }
                        vader_unreachable("unreachable return in vader_resolver$scan_folder");
                    }
                    vader_unreachable("unreachable return in vader_resolver$scan_folder");
                } else {
                }
            }
        }
        { vader_box_t __vret = vader_ref_box(l21); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l2.tag == 374u) {
        vader_array_t* _a7_arr = vader_array_new(8u, 0u, 0u, 161u);
        l3 = (void*) _a7_arr;
        l4 = ((vader_array_t*) l3)->length;
        l5 = (size_t) (int64_t) INT64_C(0);
        if (l4 == l5) {
            t0 = vader_box_obj(0u, NULL);
            { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        vader_struct___lambda_env_3065_t* _a8_obj = (vader_struct___lambda_env_3065_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_3065_t));
        vader_obj_header_init(_a8_obj, 254u);
        t1 = (void*) _a8_obj;
        vader_fn_t* _a9_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
        vader_obj_header_init(_a9_closure, 135u);
        _a9_closure->code = (void*) &vader_fn_lift_303;
        _a9_closure->env = t1;
        l6 = (void*) _a9_closure;
        l8 = std_sort_sort__string(l3, l6);
        vader_array_t* _a10_arr = vader_array_new(8u, 0u, 0u, 161u);
        l7 = (void*) _a10_arr;
        l9 = ((vader_array_t*) l8)->length;
        l10 = (size_t) (int64_t) INT64_C(0);
        {
            loop_440: {
                if ((l10 < l9)) {
                    vader_array_t* _a11_slotarr = ((vader_array_t*) l8);
                    if (_a11_slotarr->buf != NULL && _a11_slotarr->buf->header.forward != NULL) { _a11_slotarr->buf = vader_array_buf_forward(_a11_slotarr->buf); }
                    if ((size_t) l10 >= _a11_slotarr->length) { vader_trap("array index out of bounds"); }
                    t0 = vader_array_box_slots(_a11_slotarr->buf)[_a11_slotarr->offset + (size_t) l10];
                    l11 = t0.payload.s;
                    l12 = vader_resolver_join_path(l0, l11);
                    l13 = 437u;
                    t2 = std_string_ends_with(l11, l13);
                    if (t2) {
                        t2 = vader_host_std_io_is_dir(l12);
                        l14 = !(t2);
                    } else {
                        l14 = false;
                    }
                    if (l14) {
                        vader_array_push((vader_array_t*) l7, vader_box_string(161u, l12));
                    } else {
                    }
                    l15 = (size_t) (int64_t) INT64_C(1);
                    t3 = (l10 + l15);
                    l10 = (size_t) (int64_t) t3;
                    goto loop_440;
                } else {
                }
            }
        }
        l16 = ((vader_array_t*) l7)->length;
        l17 = (size_t) (int64_t) INT64_C(0);
        if (l16 == l17) {
            t0 = vader_box_obj(0u, NULL);
            { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l18 = 0u;
        l19 = toolchain_span_empty_span();
        vader_array_t* _a12_arr = vader_array_new(8u, 0u, 0u, 161u);
        l20 = (void*) _a12_arr;
        vader_struct_vader_resolver_FolderBucket_t* _a13_obj = (vader_struct_vader_resolver_FolderBucket_t*) vader_gc_alloc(sizeof(vader_struct_vader_resolver_FolderBucket_t));
        vader_obj_header_init(_a13_obj, 855u);
        _a13_obj->f_name = l18;
        _a13_obj->f_first_decl_span = l19;
        _a13_obj->f_files = l20;
        l21 = (void*) _a13_obj;
        l22 = l7;
        l23 = ((vader_array_t*) l22)->length;
        l24 = (size_t) (int64_t) INT64_C(0);
        {
            loop_517: {
                if ((l24 < l23)) {
                    vader_array_t* _a14_slotarr = ((vader_array_t*) l22);
                    if (_a14_slotarr->buf != NULL && _a14_slotarr->buf->header.forward != NULL) { _a14_slotarr->buf = vader_array_buf_forward(_a14_slotarr->buf); }
                    if ((size_t) l24 >= _a14_slotarr->length) { vader_trap("array index out of bounds"); }
                    t0 = vader_array_box_slots(_a14_slotarr->buf)[_a14_slotarr->offset + (size_t) l24];
                    l25 = t0.payload.s;
                    l26 = std_io_read_file_string(l25);
                    if (l26.tag == 161u) {
                        l27 = l26.payload.s;
                        l28 = 0u;
                        if (l27 == l28) {
                            l29 = (size_t) (int64_t) INT64_C(1);
                            t3 = (l24 + l29);
                            l24 = (size_t) (int64_t) t3;
                            goto loop_517;
                        }
                        vader_array_push((vader_array_t*) ((vader_struct_vader_resolver_FolderBucket_t*) l21)->f_files, vader_box_string(161u, l25));
                        l30 = vader_parser_parse_module_header(l27, l25);
                        if (l30.tag == 0u) {
                            l31 = (uint8_t) (int32_t) INT32_C(19);
                            l32 = toolchain_span_empty_span();
                            l33 = 919u;
                            l34 = 919u;
                            l35 = concat_3(l33, l25, l34);
                            l36 = vader_diagnostics_resolver_error(l31, l32, l35);
                            vader_array_push((vader_array_t*) l1, vader_ref_box(l36));
                            l53 = (size_t) (int64_t) INT64_C(1);
                            t3 = (l24 + l53);
                            l24 = (size_t) (int64_t) t3;
                            goto loop_517;
                        }
                        if (l30.tag == 847u) {
                            l37 = l30.payload.obj;
                            l38 = ((vader_struct_vader_resolver_FolderBucket_t*) l21)->f_name;
                            l39 = 0u;
                            if (l38 == l39) {
                                l40 = ((vader_struct_vader_parser_ModuleHeader_t*) l37)->f_name;
                                ((vader_struct_vader_resolver_FolderBucket_t*) l21)->f_name = l40;
                                VADER_WRITE_BARRIER((vader_struct_vader_resolver_FolderBucket_t*) l21);
                                l41 = ((vader_struct_vader_parser_ModuleHeader_t*) l37)->f_name_span;
                                ((vader_struct_vader_resolver_FolderBucket_t*) l21)->f_first_decl_span = l41;
                                VADER_WRITE_BARRIER((vader_struct_vader_resolver_FolderBucket_t*) l21);
                            } else {
                                l42 = ((vader_struct_vader_parser_ModuleHeader_t*) l37)->f_name;
                                l43 = ((vader_struct_vader_resolver_FolderBucket_t*) l21)->f_name;
                                if (l42 != l43) {
                                    l44 = (uint8_t) (int32_t) INT32_C(21);
                                    l45 = ((vader_struct_vader_parser_ModuleHeader_t*) l37)->f_name_span;
                                    l46 = 919u;
                                    l47 = ((vader_struct_vader_parser_ModuleHeader_t*) l37)->f_name;
                                    l48 = 939u;
                                    l49 = ((vader_struct_vader_resolver_FolderBucket_t*) l21)->f_name;
                                    l50 = 1006u;
                                    l51 = concat_5(l46, l47, l48, l49, l50);
                                    l52 = vader_diagnostics_resolver_error(l44, l45, l51);
                                    vader_array_push((vader_array_t*) l1, vader_ref_box(l52));
                                } else {
                                }
                            }
                            l53 = (size_t) (int64_t) INT64_C(1);
                            t3 = (l24 + l53);
                            l24 = (size_t) (int64_t) t3;
                            goto loop_517;
                        }
                        vader_unreachable("unreachable return in vader_resolver$scan_folder");
                    }
                    if (l26.tag == 374u) {
                        l27 = 0u;
                        l28 = 0u;
                        if (l27 == l28) {
                            l29 = (size_t) (int64_t) INT64_C(1);
                            t3 = (l24 + l29);
                            l24 = (size_t) (int64_t) t3;
                            goto loop_517;
                        }
                        vader_array_push((vader_array_t*) ((vader_struct_vader_resolver_FolderBucket_t*) l21)->f_files, vader_box_string(161u, l25));
                        l30 = vader_parser_parse_module_header(l27, l25);
                        if (l30.tag == 0u) {
                            l31 = (uint8_t) (int32_t) INT32_C(19);
                            l32 = toolchain_span_empty_span();
                            l33 = 919u;
                            l34 = 919u;
                            l35 = concat_3(l33, l25, l34);
                            l36 = vader_diagnostics_resolver_error(l31, l32, l35);
                            vader_array_push((vader_array_t*) l1, vader_ref_box(l36));
                            l53 = (size_t) (int64_t) INT64_C(1);
                            t3 = (l24 + l53);
                            l24 = (size_t) (int64_t) t3;
                            goto loop_517;
                        }
                        if (l30.tag == 847u) {
                            l37 = l30.payload.obj;
                            l38 = ((vader_struct_vader_resolver_FolderBucket_t*) l21)->f_name;
                            l39 = 0u;
                            if (l38 == l39) {
                                l40 = ((vader_struct_vader_parser_ModuleHeader_t*) l37)->f_name;
                                ((vader_struct_vader_resolver_FolderBucket_t*) l21)->f_name = l40;
                                VADER_WRITE_BARRIER((vader_struct_vader_resolver_FolderBucket_t*) l21);
                                l41 = ((vader_struct_vader_parser_ModuleHeader_t*) l37)->f_name_span;
                                ((vader_struct_vader_resolver_FolderBucket_t*) l21)->f_first_decl_span = l41;
                                VADER_WRITE_BARRIER((vader_struct_vader_resolver_FolderBucket_t*) l21);
                            } else {
                                l42 = ((vader_struct_vader_parser_ModuleHeader_t*) l37)->f_name;
                                l43 = ((vader_struct_vader_resolver_FolderBucket_t*) l21)->f_name;
                                if (l42 != l43) {
                                    l44 = (uint8_t) (int32_t) INT32_C(21);
                                    l45 = ((vader_struct_vader_parser_ModuleHeader_t*) l37)->f_name_span;
                                    l46 = 919u;
                                    l47 = ((vader_struct_vader_parser_ModuleHeader_t*) l37)->f_name;
                                    l48 = 939u;
                                    l49 = ((vader_struct_vader_resolver_FolderBucket_t*) l21)->f_name;
                                    l50 = 1006u;
                                    l51 = concat_5(l46, l47, l48, l49, l50);
                                    l52 = vader_diagnostics_resolver_error(l44, l45, l51);
                                    vader_array_push((vader_array_t*) l1, vader_ref_box(l52));
                                } else {
                                }
                            }
                            l53 = (size_t) (int64_t) INT64_C(1);
                            t3 = (l24 + l53);
                            l24 = (size_t) (int64_t) t3;
                            goto loop_517;
                        }
                        vader_unreachable("unreachable return in vader_resolver$scan_folder");
                    }
                    vader_unreachable("unreachable return in vader_resolver$scan_folder");
                } else {
                }
            }
        }
        { vader_box_t __vret = vader_ref_box(l21); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_unreachable("unreachable return in vader_resolver$scan_folder");
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
    vader_obj_header_init(_a0_obj, 853u);
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
    void* l13 = NULL;
    void* l16 = NULL;
    void* l30 = NULL;
    void* l31 = NULL;
    void* l35 = NULL;
    void* l36 = NULL;
    void* l37 = NULL;
    size_t l8, l9, l10, l11, l17, l18, l29, l33;
    vader_box_t l12 = vader_box_null(), l14 = vader_box_null(), l21 = vader_box_null(), l34 = vader_box_null();
    vader_string_t l15 = 0;
    vader_string_t l20 = 0;
    vader_string_t l22 = 0;
    vader_string_t l23 = 0;
    vader_string_t l24 = 0;
    vader_string_t l25 = 0;
    vader_string_t l26 = 0;
    vader_string_t l27 = 0;
    vader_string_t l28 = 0;
    vader_string_t l32 = 0;
    uint8_t l19;
    void* t0 = NULL;
    int64_t t1;
    bool t2;
    vader_box_t t3 = vader_box_null();
    vader_box_t* gc_roots[6] = { &l1, &l12, &l14, &l21, &l34, &t3 };
    void** gc_raw_roots[15] = { &l0, &l2, &l3, &l4, &l5, &l6, &l7, &l13, &l16, &l30, &l31, &l35, &l36, &l37, &t0 };
    vader_string_t* gc_atom_roots[10] = { &l15, &l20, &l22, &l23, &l24, &l25, &l26, &l27, &l28, &l32 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 6u, 15u, gc_roots, gc_raw_roots, 0u, NULL, 10u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_resolver_check_selectors(l0, l2);
    vader_resolver_check_groups(l0, l2);
    if (l1.tag == 0u) {
        { void* __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 161u);
    l3 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(15u, 0u, 0u, 171u);
    l4 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 164u);
    l5 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__string__Any_t* _a3_obj = (vader_struct_std_collections_MutableMap__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__Any_t));
    vader_obj_header_init(_a3_obj, 309u);
    _a3_obj->f_ekeys = l3;
    _a3_obj->f_evals = l4;
    _a3_obj->f_index = l5;
    _a3_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l3 = (void*) _a3_obj;
    vader_array_t* _a4_arr = vader_array_new(8u, 0u, 0u, 161u);
    l4 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_new(6u, 0u, 12u, 159u);
    l5 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(9u, 0u, 7u, 164u);
    l6 = (void*) _a6_arr;
    vader_struct_std_collections_MutableMap__string__bool_t* _a7_obj = (vader_struct_std_collections_MutableMap__string__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__bool_t));
    vader_obj_header_init(_a7_obj, 348u);
    _a7_obj->f_ekeys = l4;
    _a7_obj->f_evals = l5;
    _a7_obj->f_index = l6;
    _a7_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a7_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a7_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l4 = (void*) _a7_obj;
    vader_array_t* _a8_arr = vader_array_new(8u, 0u, 0u, 161u);
    l5 = (void*) _a8_arr;
    vader_array_t* _a9_arr = vader_array_new(8u, 0u, 0u, 161u);
    l6 = (void*) _a9_arr;
    vader_array_t* _a10_arr = vader_array_new(9u, 0u, 7u, 164u);
    l7 = (void*) _a10_arr;
    vader_struct_std_collections_MutableMap__string__string_t* _a11_obj = (vader_struct_std_collections_MutableMap__string__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__string_t));
    vader_obj_header_init(_a11_obj, 352u);
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
                            if (l12.tag == 407u) {
                                l13 = l12.payload.obj;
                                l14 = vader_resolver_target_selectors(((vader_struct_toolchain_ast_FnDecl_t*) l13)->f_decorators);
                                if (l14.tag == 0u) {
                                    t1 = (l11 + INT64_C(1));
                                    l11 = (size_t) (int64_t) t1;
                                    goto loop_77;
                                }
                                t0 = l14.payload.obj;
                                t2 = ((vader_struct_vader_resolver_TargetSelectors_t*) t0)->f_is_bare;
                                if (t2) {
                                    l15 = ((vader_struct_toolchain_ast_FnDecl_t*) l13)->f_name;
                                    std_collections_put__string__bool(l4, l15, true);
                                    l33 = (size_t) (int64_t) INT64_C(1);
                                    t1 = (l11 + l33);
                                    l11 = (size_t) (int64_t) t1;
                                    goto loop_77;
                                }
                                t0 = l14.payload.obj;
                                l16 = ((vader_struct_vader_resolver_TargetSelectors_t*) t0)->f_os;
                                l17 = ((vader_array_t*) l16)->length;
                                l18 = (size_t) (int64_t) INT64_C(0);
                                {
                                    loop_131: {
                                        if ((l18 < l17)) {
                                            vader_array_t* _a14_slotarr = ((vader_array_t*) l16);
                                            if (_a14_slotarr->buf != NULL && _a14_slotarr->buf->header.forward != NULL) { _a14_slotarr->buf = vader_array_buf_forward(_a14_slotarr->buf); }
                                            if ((size_t) l18 >= _a14_slotarr->length) { vader_trap("array index out of bounds"); }
                                            t3 = vader_array_read_u8(_a14_slotarr, _a14_slotarr->offset + (size_t) l18, 167u);
                                            l19 = ((uint8_t) t3.payload.i);
                                            l20 = ((vader_struct_toolchain_ast_FnDecl_t*) l13)->f_name;
                                            l21 = std_collections_get__string__string(l5, l20);
                                            l22 = ((vader_struct_toolchain_ast_FnDecl_t*) l13)->f_name;
                                            if (l21.tag == 0u) {
                                                l24 = 416u;
                                                if (l19 == INT32_C(0)) {
                                                    l25 = 2392u;
                                                    l23 = concat_2(l24, l25);
                                                    std_collections_put__string__string(l5, l22, l23);
                                                    l29 = (size_t) (int64_t) INT64_C(1);
                                                    t1 = (l18 + l29);
                                                    l18 = (size_t) (int64_t) t1;
                                                    goto loop_131;
                                                }
                                                if (l19 == INT32_C(1)) {
                                                    l25 = 1768u;
                                                    l23 = concat_2(l24, l25);
                                                    std_collections_put__string__string(l5, l22, l23);
                                                    l29 = (size_t) (int64_t) INT64_C(1);
                                                    t1 = (l18 + l29);
                                                    l18 = (size_t) (int64_t) t1;
                                                    goto loop_131;
                                                }
                                                if (l19 == INT32_C(2)) {
                                                    l25 = 1394u;
                                                    l23 = concat_2(l24, l25);
                                                    std_collections_put__string__string(l5, l22, l23);
                                                    l29 = (size_t) (int64_t) INT64_C(1);
                                                    t1 = (l18 + l29);
                                                    l18 = (size_t) (int64_t) t1;
                                                    goto loop_131;
                                                }
                                                if (l19 == INT32_C(3)) {
                                                    l25 = 2386u;
                                                    l23 = concat_2(l24, l25);
                                                    std_collections_put__string__string(l5, l22, l23);
                                                    l29 = (size_t) (int64_t) INT64_C(1);
                                                    t1 = (l18 + l29);
                                                    l18 = (size_t) (int64_t) t1;
                                                    goto loop_131;
                                                }
                                                if (l19 == INT32_C(4)) {
                                                    l25 = 1254u;
                                                    l23 = concat_2(l24, l25);
                                                    std_collections_put__string__string(l5, l22, l23);
                                                    l29 = (size_t) (int64_t) INT64_C(1);
                                                    t1 = (l18 + l29);
                                                    l18 = (size_t) (int64_t) t1;
                                                    goto loop_131;
                                                }
                                                vader_unreachable("unreachable return in vader_resolver$select_target_bodies");
                                            }
                                            l26 = l21.payload.s;
                                            l27 = 381u;
                                            if (l19 == INT32_C(0)) {
                                                l28 = 2392u;
                                                l23 = concat_3(l26, l27, l28);
                                                std_collections_put__string__string(l5, l22, l23);
                                                l29 = (size_t) (int64_t) INT64_C(1);
                                                t1 = (l18 + l29);
                                                l18 = (size_t) (int64_t) t1;
                                                goto loop_131;
                                            }
                                            if (l19 == INT32_C(1)) {
                                                l28 = 1768u;
                                                l23 = concat_3(l26, l27, l28);
                                                std_collections_put__string__string(l5, l22, l23);
                                                l29 = (size_t) (int64_t) INT64_C(1);
                                                t1 = (l18 + l29);
                                                l18 = (size_t) (int64_t) t1;
                                                goto loop_131;
                                            }
                                            if (l19 == INT32_C(2)) {
                                                l28 = 1394u;
                                                l23 = concat_3(l26, l27, l28);
                                                std_collections_put__string__string(l5, l22, l23);
                                                l29 = (size_t) (int64_t) INT64_C(1);
                                                t1 = (l18 + l29);
                                                l18 = (size_t) (int64_t) t1;
                                                goto loop_131;
                                            }
                                            if (l19 == INT32_C(3)) {
                                                l28 = 2386u;
                                                l23 = concat_3(l26, l27, l28);
                                                std_collections_put__string__string(l5, l22, l23);
                                                l29 = (size_t) (int64_t) INT64_C(1);
                                                t1 = (l18 + l29);
                                                l18 = (size_t) (int64_t) t1;
                                                goto loop_131;
                                            }
                                            if (l19 == INT32_C(4)) {
                                                l28 = 1254u;
                                                l23 = concat_3(l26, l27, l28);
                                                std_collections_put__string__string(l5, l22, l23);
                                                l29 = (size_t) (int64_t) INT64_C(1);
                                                t1 = (l18 + l29);
                                                l18 = (size_t) (int64_t) t1;
                                                goto loop_131;
                                            }
                                            vader_unreachable("unreachable return in vader_resolver$select_target_bodies");
                                        } else {
                                        }
                                    }
                                }
                                t0 = l14.payload.obj;
                                l30 = ((vader_struct_vader_resolver_TargetSelectors_t*) t0)->f_os;
                                l31 = l1.payload.obj;
                                t2 = vader_resolver_matches_target(l30, l31);
                                if (t2) {
                                    l32 = ((vader_struct_toolchain_ast_FnDecl_t*) l13)->f_name;
                                    std_collections_put__string__Any(l3, l32, vader_ref_box(l13));
                                } else {
                                }
                                l33 = (size_t) (int64_t) INT64_C(1);
                                t1 = (l11 + l33);
                                l11 = (size_t) (int64_t) t1;
                                goto loop_77;
                            }
                            l33 = (size_t) (int64_t) INT64_C(1);
                            t1 = (l11 + l33);
                            l11 = (size_t) (int64_t) t1;
                            goto loop_77;
                        } else {
                        }
                    }
                }
                t1 = (l9 + INT64_C(1));
                l9 = (size_t) (int64_t) t1;
                goto loop_61;
            } else {
            }
        }
    }
    l6 = l1.payload.obj;
    vader_resolver_report_uncovered(l0, l6, l3, l5, l2);
    vader_array_t* _a15_arr = vader_array_new(86u, 0u, 13u, 867u);
    l5 = (void*) _a15_arr;
    l6 = l0;
    l8 = ((vader_array_t*) l6)->length;
    l9 = (size_t) (int64_t) INT64_C(0);
    {
        loop_458: {
            if ((l9 < l8)) {
                vader_array_t* _a16_slotarr = ((vader_array_t*) l6);
                if (_a16_slotarr->buf != NULL && _a16_slotarr->buf->header.forward != NULL) { _a16_slotarr->buf = vader_array_buf_forward(_a16_slotarr->buf); }
                if ((size_t) l9 >= _a16_slotarr->length) { vader_trap("array index out of bounds"); }
                l7 = vader_array_ref_load_obj(_a16_slotarr->buf, _a16_slotarr->offset + (size_t) l9);
                vader_array_t* _a17_arr = vader_array_new(110u, 0u, 13u, 1023u);
                l13 = (void*) _a17_arr;
                l16 = ((vader_struct_toolchain_ast_Program_t*) ((vader_struct_vader_resolver_SourceFile_t*) l7)->f_program)->f_decls;
                l10 = ((vader_array_t*) l16)->length;
                l11 = (size_t) (int64_t) INT64_C(0);
                {
                    loop_477: {
                        if ((l11 < l10)) {
                            vader_array_t* _a18_slotarr = ((vader_array_t*) l16);
                            if (_a18_slotarr->buf != NULL && _a18_slotarr->buf->header.forward != NULL) { _a18_slotarr->buf = vader_array_buf_forward(_a18_slotarr->buf); }
                            if ((size_t) l11 >= _a18_slotarr->length) { vader_trap("array index out of bounds"); }
                            l12 = vader_array_ref_load_box(_a18_slotarr->buf, _a18_slotarr->offset + (size_t) l11);
                            l30 = l1.payload.obj;
                            l14 = vader_resolver_resolve_decl(l12, l30, l3, l4);
                            if (!(l14.tag == 0u)) {
                                l21 = l14;
                                vader_array_push((vader_array_t*) l13, l21);
                            } else {
                            }
                            t1 = (l11 + INT64_C(1));
                            l11 = (size_t) (int64_t) t1;
                            goto loop_477;
                        } else {
                        }
                    }
                }
                l15 = ((vader_struct_vader_resolver_SourceFile_t*) l7)->f_path;
                l20 = ((vader_struct_vader_resolver_SourceFile_t*) l7)->f_content;
                l22 = ((vader_struct_toolchain_ast_Program_t*) ((vader_struct_vader_resolver_SourceFile_t*) l7)->f_program)->f_file;
                l31 = ((vader_struct_toolchain_ast_Program_t*) ((vader_struct_vader_resolver_SourceFile_t*) l7)->f_program)->f_span;
                l17 = ((vader_struct_toolchain_ast_Program_t*) ((vader_struct_vader_resolver_SourceFile_t*) l7)->f_program)->f_id;
                l34 = ((vader_struct_toolchain_ast_Program_t*) ((vader_struct_vader_resolver_SourceFile_t*) l7)->f_program)->f_module;
                vader_struct_toolchain_ast_Program_t* _a19_obj = (vader_struct_toolchain_ast_Program_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_Program_t));
                vader_obj_header_init(_a19_obj, 439u);
                _a19_obj->f_file = l22;
                _a19_obj->f_span = l31;
                _a19_obj->f_id = l17;
                _a19_obj->f_module = l34;
                _a19_obj->f_decls = l13;
                l35 = (void*) _a19_obj;
                l36 = ((vader_struct_vader_resolver_SourceFile_t*) l7)->f_id_factory;
                vader_struct_vader_resolver_SourceFile_t* _a20_obj = (vader_struct_vader_resolver_SourceFile_t*) vader_gc_alloc(sizeof(vader_struct_vader_resolver_SourceFile_t));
                vader_obj_header_init(_a20_obj, 867u);
                _a20_obj->f_path = l15;
                _a20_obj->f_content = l20;
                _a20_obj->f_program = l35;
                _a20_obj->f_id_factory = l36;
                l37 = (void*) _a20_obj;
                vader_array_push((vader_array_t*) l5, vader_ref_box(l37));
                t1 = (l9 + INT64_C(1));
                l9 = (size_t) (int64_t) t1;
                goto loop_458;
            } else {
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
        t1 = vader_box_string(161u, t0);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_host_std_io_current_executable_location();
    t2 = vader_resolver_dir_of(t0);
    l3 = vader_resolver_join_path(t2, l0);
    t0 = vader_resolver_join_path(l3, l1);
    t3 = vader_host_std_io_exists(t0);
    if (t3) {
        t1 = vader_box_string(161u, l3);
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
    vader_struct___lambda_env_2051_t* _a0_obj = (vader_struct___lambda_env_2051_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_2051_t));
    vader_obj_header_init(_a0_obj, 239u);
    t0 = (void*) _a0_obj;
    vader_fn_t* _a1_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
    vader_obj_header_init(_a1_closure, 151u);
    _a1_closure->code = (void*) &vader_fn_lift_289;
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
    vader_box_t t0 = vader_box_null();
    int64_t t1;
    vader_box_t* gc_roots[2] = { &l0, &t0 };
    void** gc_raw_roots[3] = { &l1, &l2, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 445u) {
        l2 = l0.payload.obj;
        l3 = vader_resolver_next_clone_span(l1);
        ((vader_struct_toolchain_ast_SimpleBinding_t*) l2)->f_span = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_SimpleBinding_t*) l2);
        l3 = vader_resolver_next_clone_span(l1);
        ((vader_struct_toolchain_ast_SimpleBinding_t*) l2)->f_name_span = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_SimpleBinding_t*) l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 457u) {
        l2 = l0.payload.obj;
        l3 = vader_resolver_next_clone_span(l1);
        ((vader_struct_toolchain_ast_TupleBinding_t*) l2)->f_span = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_TupleBinding_t*) l2);
        l2 = ((vader_struct_toolchain_ast_TupleBinding_t*) l2)->f_elements;
        l4 = ((vader_array_t*) l2)->length;
        l5 = (size_t) (int64_t) INT64_C(0);
        {
            loop_39: {
                if ((l5 < l4)) {
                    vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
                    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                    if ((size_t) l5 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                    t0 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
                    vader_resolver_stamp_binding_spans(t0, l1);
                    t1 = (l5 + INT64_C(1));
                    l5 = (size_t) (int64_t) t1;
                    goto loop_39;
                } else {
                }
            }
        }
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 463u) {
        l2 = l0.payload.obj;
        l3 = vader_resolver_next_clone_span(l1);
        ((vader_struct_toolchain_ast_WildcardBinding_t*) l2)->f_span = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_WildcardBinding_t*) l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 442u) {
        l2 = l0.payload.obj;
        l3 = vader_resolver_next_clone_span(l1);
        ((vader_struct_toolchain_ast_RestBinding_t*) l2)->f_span = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_RestBinding_t*) l2);
        l3 = vader_resolver_next_clone_span(l1);
        ((vader_struct_toolchain_ast_RestBinding_t*) l2)->f_name_span = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_RestBinding_t*) l2);
        { vader_gc_top = gc_frame.prev; return; }
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
            } else {
            }
        }
    }
    if (!(((vader_struct_toolchain_ast_BlockExpr_t*) l0)->f_trailing.tag == 0u)) {
        vader_resolver_stamp_expr_spans(((vader_struct_toolchain_ast_BlockExpr_t*) l0)->f_trailing, l1);
    } else {
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
    size_t l4, l5, l11;
    vader_box_t l7 = vader_box_null();
    int64_t t0;
    void* t1 = NULL;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l0, &l7, &t2 };
    void** gc_raw_roots[8] = { &l1, &l2, &l3, &l6, &l8, &l9, &l10, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 8u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 422u) {
        l2 = l0.payload.obj;
        l3 = vader_resolver_next_clone_span(l1);
        ((vader_struct_toolchain_ast_IntLitExpr_t*) l2)->f_span = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_IntLitExpr_t*) l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 406u) {
        l2 = l0.payload.obj;
        l3 = vader_resolver_next_clone_span(l1);
        ((vader_struct_toolchain_ast_FloatLitExpr_t*) l2)->f_span = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_FloatLitExpr_t*) l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 385u) {
        l2 = l0.payload.obj;
        l3 = vader_resolver_next_clone_span(l1);
        ((vader_struct_toolchain_ast_BoolLitExpr_t*) l2)->f_span = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_BoolLitExpr_t*) l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 435u) {
        l2 = l0.payload.obj;
        l3 = vader_resolver_next_clone_span(l1);
        ((vader_struct_toolchain_ast_NullLitExpr_t*) l2)->f_span = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_NullLitExpr_t*) l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 390u) {
        l2 = l0.payload.obj;
        l3 = vader_resolver_next_clone_span(l1);
        ((vader_struct_toolchain_ast_CharLitExpr_t*) l2)->f_span = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_CharLitExpr_t*) l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 412u) {
        l2 = l0.payload.obj;
        l3 = vader_resolver_next_clone_span(l1);
        ((vader_struct_toolchain_ast_IdentExpr_t*) l2)->f_span = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_IdentExpr_t*) l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 388u) {
        l2 = l0.payload.obj;
        l3 = vader_resolver_next_clone_span(l1);
        ((vader_struct_toolchain_ast_CallExpr_t*) l2)->f_span = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_CallExpr_t*) l2);
        vader_resolver_stamp_expr_spans(((vader_struct_toolchain_ast_CallExpr_t*) l2)->f_callee, l1);
        l2 = ((vader_struct_toolchain_ast_CallExpr_t*) l2)->f_args;
        l4 = ((vader_array_t*) l2)->length;
        l5 = (size_t) (int64_t) INT64_C(0);
        {
            loop_106: {
                if ((l5 < l4)) {
                    vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
                    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                    if ((size_t) l5 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                    l3 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
                    l6 = vader_resolver_next_clone_span(l1);
                    ((vader_struct_toolchain_ast_CallArg_t*) l3)->f_span = l6;
                    VADER_WRITE_BARRIER((vader_struct_toolchain_ast_CallArg_t*) l3);
                    vader_resolver_stamp_expr_spans(((vader_struct_toolchain_ast_CallArg_t*) l3)->f_value, l1);
                    t0 = (l5 + INT64_C(1));
                    l5 = (size_t) (int64_t) t0;
                    goto loop_106;
                } else {
                }
            }
        }
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 405u) {
        l2 = l0.payload.obj;
        l3 = vader_resolver_next_clone_span(l1);
        ((vader_struct_toolchain_ast_FieldExpr_t*) l2)->f_span = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_FieldExpr_t*) l2);
        vader_resolver_stamp_expr_spans(((vader_struct_toolchain_ast_FieldExpr_t*) l2)->f_target, l1);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 420u) {
        l2 = l0.payload.obj;
        l3 = vader_resolver_next_clone_span(l1);
        ((vader_struct_toolchain_ast_IndexExpr_t*) l2)->f_span = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_IndexExpr_t*) l2);
        vader_resolver_stamp_expr_spans(((vader_struct_toolchain_ast_IndexExpr_t*) l2)->f_target, l1);
        vader_resolver_stamp_expr_spans(((vader_struct_toolchain_ast_IndexExpr_t*) l2)->f_index, l1);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 461u) {
        l2 = l0.payload.obj;
        l3 = vader_resolver_next_clone_span(l1);
        ((vader_struct_toolchain_ast_UnaryExpr_t*) l2)->f_span = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_UnaryExpr_t*) l2);
        vader_resolver_stamp_expr_spans(((vader_struct_toolchain_ast_UnaryExpr_t*) l2)->f_operand, l1);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 382u) {
        l2 = l0.payload.obj;
        l3 = vader_resolver_next_clone_span(l1);
        ((vader_struct_toolchain_ast_BinaryExpr_t*) l2)->f_span = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_BinaryExpr_t*) l2);
        vader_resolver_stamp_expr_spans(((vader_struct_toolchain_ast_BinaryExpr_t*) l2)->f_left, l1);
        vader_resolver_stamp_expr_spans(((vader_struct_toolchain_ast_BinaryExpr_t*) l2)->f_right, l1);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 415u) {
        l2 = l0.payload.obj;
        l3 = vader_resolver_next_clone_span(l1);
        ((vader_struct_toolchain_ast_IfExpr_t*) l2)->f_span = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_IfExpr_t*) l2);
        vader_resolver_stamp_expr_spans(((vader_struct_toolchain_ast_IfExpr_t*) l2)->f_cond, l1);
        vader_resolver_stamp_block_spans(((vader_struct_toolchain_ast_IfExpr_t*) l2)->f_then_block, l1);
        l7 = ((vader_struct_toolchain_ast_IfExpr_t*) l2)->f_else_branch;
        if (l7.tag == 0u) {
            { vader_gc_top = gc_frame.prev; return; }
        }
        if (l7.tag == 413u) {
            t1 = l7.payload.obj;
            vader_resolver_stamp_block_spans(((vader_struct_toolchain_ast_IfElseBlock_t*) t1)->f_block, l1);
            { vader_gc_top = gc_frame.prev; return; }
        }
        if (l7.tag == 414u) {
            t1 = l7.payload.obj;
            vader_resolver_stamp_expr_spans(vader_ref_box(((vader_struct_toolchain_ast_IfElseIf_t*) t1)->f_branch), l1);
            { vader_gc_top = gc_frame.prev; return; }
        }
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 429u) {
        l2 = l0.payload.obj;
        l3 = vader_resolver_next_clone_span(l1);
        ((vader_struct_toolchain_ast_MatchExpr_t*) l2)->f_span = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_MatchExpr_t*) l2);
        vader_resolver_stamp_expr_spans(((vader_struct_toolchain_ast_MatchExpr_t*) l2)->f_scrutinee, l1);
        l2 = ((vader_struct_toolchain_ast_MatchExpr_t*) l2)->f_arms;
        l4 = ((vader_array_t*) l2)->length;
        l5 = (size_t) (int64_t) INT64_C(0);
        {
            loop_277: {
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
                    } else {
                    }
                    vader_resolver_stamp_expr_spans(((vader_struct_toolchain_ast_MatchArm_t*) l3)->f_body, l1);
                    t0 = (l5 + INT64_C(1));
                    l5 = (size_t) (int64_t) t0;
                    goto loop_277;
                } else {
                }
            }
        }
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 384u) {
        t1 = l0.payload.obj;
        vader_resolver_stamp_block_spans(t1, l1);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 451u) {
        l2 = l0.payload.obj;
        l3 = vader_resolver_next_clone_span(l1);
        ((vader_struct_toolchain_ast_StructLitExpr_t*) l2)->f_span = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_StructLitExpr_t*) l2);
        vader_resolver_stamp_expr_spans(((vader_struct_toolchain_ast_StructLitExpr_t*) l2)->f_type_name, l1);
        l2 = ((vader_struct_toolchain_ast_StructLitExpr_t*) l2)->f_items;
        l4 = ((vader_array_t*) l2)->length;
        l5 = (size_t) (int64_t) INT64_C(0);
        {
            loop_349: {
                if ((l5 < l4)) {
                    vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
                    if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                    if ((size_t) l5 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                    l7 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l5);
                    if (l7.tag == 452u) {
                        l3 = l7.payload.obj;
                        l6 = vader_resolver_next_clone_span(l1);
                        ((vader_struct_toolchain_ast_StructLitField_t*) l3)->f_span = l6;
                        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_StructLitField_t*) l3);
                        l8 = vader_resolver_next_clone_span(l1);
                        ((vader_struct_toolchain_ast_StructLitField_t*) l3)->f_name_span = l8;
                        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_StructLitField_t*) l3);
                        vader_resolver_stamp_expr_spans(((vader_struct_toolchain_ast_StructLitField_t*) l3)->f_value, l1);
                        l11 = (size_t) (int64_t) INT64_C(1);
                        t0 = (l5 + l11);
                        l5 = (size_t) (int64_t) t0;
                        goto loop_349;
                    }
                    if (l7.tag == 453u) {
                        l9 = l7.payload.obj;
                        l10 = vader_resolver_next_clone_span(l1);
                        ((vader_struct_toolchain_ast_StructLitSpread_t*) l9)->f_span = l10;
                        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_StructLitSpread_t*) l9);
                        vader_resolver_stamp_expr_spans(((vader_struct_toolchain_ast_StructLitSpread_t*) l9)->f_expr, l1);
                        l11 = (size_t) (int64_t) INT64_C(1);
                        t0 = (l5 + l11);
                        l5 = (size_t) (int64_t) t0;
                        goto loop_349;
                    }
                    { vader_gc_top = gc_frame.prev; return; }
                } else {
                }
            }
        }
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 444u) {
        l2 = l0.payload.obj;
        l3 = vader_resolver_next_clone_span(l1);
        ((vader_struct_toolchain_ast_SeqLitExpr_t*) l2)->f_span = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_SeqLitExpr_t*) l2);
        l2 = ((vader_struct_toolchain_ast_SeqLitExpr_t*) l2)->f_elements;
        l4 = ((vader_array_t*) l2)->length;
        l5 = (size_t) (int64_t) INT64_C(0);
        {
            loop_435: {
                if ((l5 < l4)) {
                    vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
                    if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                    if ((size_t) l5 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                    t2 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l5);
                    vader_resolver_stamp_expr_spans(t2, l1);
                    t0 = (l5 + INT64_C(1));
                    l5 = (size_t) (int64_t) t0;
                    goto loop_435;
                } else {
                }
            }
        }
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 440u) {
        l2 = l0.payload.obj;
        l3 = vader_resolver_next_clone_span(l1);
        ((vader_struct_toolchain_ast_RangeExpr_t*) l2)->f_span = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_RangeExpr_t*) l2);
        vader_resolver_stamp_expr_spans(((vader_struct_toolchain_ast_RangeExpr_t*) l2)->f_lower, l1);
        vader_resolver_stamp_expr_spans(((vader_struct_toolchain_ast_RangeExpr_t*) l2)->f_upper, l1);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 381u) {
        l2 = l0.payload.obj;
        l3 = vader_resolver_next_clone_span(l1);
        ((vader_struct_toolchain_ast_AwaitExpr_t*) l2)->f_span = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_AwaitExpr_t*) l2);
        vader_resolver_stamp_expr_spans(((vader_struct_toolchain_ast_AwaitExpr_t*) l2)->f_inner, l1);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 389u) {
        l2 = l0.payload.obj;
        l3 = vader_resolver_next_clone_span(l1);
        ((vader_struct_toolchain_ast_CastExpr_t*) l2)->f_span = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_CastExpr_t*) l2);
        vader_resolver_stamp_expr_spans(((vader_struct_toolchain_ast_CastExpr_t*) l2)->f_target, l1);
        vader_resolver_stamp_expr_spans(((vader_struct_toolchain_ast_CastExpr_t*) l2)->f_value, l1);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 423u) {
        l2 = l0.payload.obj;
        l3 = vader_resolver_next_clone_span(l1);
        ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l2)->f_span = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l2);
        l3 = vader_resolver_next_clone_span(l1);
        ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l2)->f_name_span = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l2);
        l2 = ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l2)->f_args;
        l4 = ((vader_array_t*) l2)->length;
        l5 = (size_t) (int64_t) INT64_C(0);
        {
            loop_538: {
                if ((l5 < l4)) {
                    vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
                    if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                    if ((size_t) l5 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                    t2 = vader_array_ref_load_box(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l5);
                    vader_resolver_stamp_expr_spans(t2, l1);
                    t0 = (l5 + INT64_C(1));
                    l5 = (size_t) (int64_t) t0;
                    goto loop_538;
                } else {
                }
            }
        }
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 400u) {
        l2 = l0.payload.obj;
        l3 = vader_resolver_next_clone_span(l1);
        ((vader_struct_toolchain_ast_DotVariantExpr_t*) l2)->f_span = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_DotVariantExpr_t*) l2);
        l3 = vader_resolver_next_clone_span(l1);
        ((vader_struct_toolchain_ast_DotVariantExpr_t*) l2)->f_variant_span = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_DotVariantExpr_t*) l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 446u) {
        l2 = l0.payload.obj;
        l3 = vader_resolver_next_clone_span(l1);
        ((vader_struct_toolchain_ast_StringLitExpr_t*) l2)->f_span = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_StringLitExpr_t*) l2);
        l2 = ((vader_struct_toolchain_ast_StringLitExpr_t*) l2)->f_parts;
        l4 = ((vader_array_t*) l2)->length;
        l5 = (size_t) (int64_t) INT64_C(0);
        {
            loop_598: {
                if ((l5 < l4)) {
                    vader_array_t* _a5_slotarr = ((vader_array_t*) l2);
                    if (_a5_slotarr->buf != NULL && _a5_slotarr->buf->header.forward != NULL) { _a5_slotarr->buf = vader_array_buf_forward(_a5_slotarr->buf); }
                    if ((size_t) l5 >= _a5_slotarr->length) { vader_trap("array index out of bounds"); }
                    l7 = vader_array_ref_load_box(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l5);
                    if (l7.tag == 448u) {
                        l3 = l7.payload.obj;
                        l6 = vader_resolver_next_clone_span(l1);
                        ((vader_struct_toolchain_ast_StringLitText_t*) l3)->f_span = l6;
                        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_StringLitText_t*) l3);
                        l11 = (size_t) (int64_t) INT64_C(1);
                        t0 = (l5 + l11);
                        l5 = (size_t) (int64_t) t0;
                        goto loop_598;
                    }
                    if (l7.tag == 447u) {
                        l8 = l7.payload.obj;
                        l9 = vader_resolver_next_clone_span(l1);
                        ((vader_struct_toolchain_ast_StringLitInterp_t*) l8)->f_span = l9;
                        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_StringLitInterp_t*) l8);
                        vader_resolver_stamp_expr_spans(((vader_struct_toolchain_ast_StringLitInterp_t*) l8)->f_expr, l1);
                        l11 = (size_t) (int64_t) INT64_C(1);
                        t0 = (l5 + l11);
                        l5 = (size_t) (int64_t) t0;
                        goto loop_598;
                    }
                    { vader_gc_top = gc_frame.prev; return; }
                } else {
                }
            }
        }
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 425u) {
        l2 = l0.payload.obj;
        l3 = vader_resolver_next_clone_span(l1);
        ((vader_struct_toolchain_ast_LambdaExpr_t*) l2)->f_span = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_LambdaExpr_t*) l2);
        l3 = ((vader_struct_toolchain_ast_LambdaExpr_t*) l2)->f_params;
        l4 = ((vader_array_t*) l3)->length;
        l5 = (size_t) (int64_t) INT64_C(0);
        {
            loop_675: {
                if ((l5 < l4)) {
                    vader_array_t* _a6_slotarr = ((vader_array_t*) l3);
                    if (_a6_slotarr->buf != NULL && _a6_slotarr->buf->header.forward != NULL) { _a6_slotarr->buf = vader_array_buf_forward(_a6_slotarr->buf); }
                    if ((size_t) l5 >= _a6_slotarr->length) { vader_trap("array index out of bounds"); }
                    l6 = vader_array_ref_load_obj(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l5);
                    l8 = vader_resolver_next_clone_span(l1);
                    ((vader_struct_toolchain_ast_FnParam_t*) l6)->f_span = l8;
                    VADER_WRITE_BARRIER((vader_struct_toolchain_ast_FnParam_t*) l6);
                    if (!(((vader_struct_toolchain_ast_FnParam_t*) l6)->f_ty.tag == 0u)) {
                        vader_resolver_stamp_expr_spans(((vader_struct_toolchain_ast_FnParam_t*) l6)->f_ty, l1);
                    } else {
                    }
                    if (!(((vader_struct_toolchain_ast_FnParam_t*) l6)->f_default_value.tag == 0u)) {
                        vader_resolver_stamp_expr_spans(((vader_struct_toolchain_ast_FnParam_t*) l6)->f_default_value, l1);
                    } else {
                    }
                    t0 = (l5 + INT64_C(1));
                    l5 = (size_t) (int64_t) t0;
                    goto loop_675;
                } else {
                }
            }
        }
        if (!(((vader_struct_toolchain_ast_LambdaExpr_t*) l2)->f_return_type.tag == 0u)) {
            vader_resolver_stamp_expr_spans(((vader_struct_toolchain_ast_LambdaExpr_t*) l2)->f_return_type, l1);
        } else {
        }
        vader_resolver_stamp_block_spans(((vader_struct_toolchain_ast_LambdaExpr_t*) l2)->f_body, l1);
    } else {
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_resolver_stamp_pattern_spans(vader_box_t l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[3] = { &l1, &l2, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 424u) {
        l2 = l0.payload.obj;
        l3 = vader_resolver_next_clone_span(l1);
        ((vader_struct_toolchain_ast_IsPattern_t*) l2)->f_span = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_IsPattern_t*) l2);
        if (!(((vader_struct_toolchain_ast_IsPattern_t*) l2)->f_inner.tag == 0u)) {
            vader_resolver_stamp_pattern_spans(((vader_struct_toolchain_ast_IsPattern_t*) l2)->f_inner, l1);
        } else {
        }
    } else {
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_resolver_stamp_stmt_spans(vader_box_t l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l7 = NULL;
    vader_box_t l4 = vader_box_null(), l5 = vader_box_null();
    vader_string_t l6 = 0;
    void* t0 = NULL;
    vader_box_t* gc_roots[3] = { &l0, &l4, &l5 };
    void** gc_raw_roots[5] = { &l1, &l2, &l3, &l7, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l6 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    if (l0.tag == 426u) {
        l2 = l0.payload.obj;
        l3 = vader_resolver_next_clone_span(l1);
        ((vader_struct_toolchain_ast_LetStmt_t*) l2)->f_span = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_LetStmt_t*) l2);
        vader_resolver_stamp_binding_spans(((vader_struct_toolchain_ast_LetStmt_t*) l2)->f_binding, l1);
        if (!(((vader_struct_toolchain_ast_LetStmt_t*) l2)->f_ty.tag == 0u)) {
            vader_resolver_stamp_expr_spans(((vader_struct_toolchain_ast_LetStmt_t*) l2)->f_ty, l1);
        } else {
        }
        vader_resolver_stamp_expr_spans(((vader_struct_toolchain_ast_LetStmt_t*) l2)->f_value, l1);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 404u) {
        l2 = l0.payload.obj;
        l3 = vader_resolver_next_clone_span(l1);
        ((vader_struct_toolchain_ast_ExprStmt_t*) l2)->f_span = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_ExprStmt_t*) l2);
        vader_resolver_stamp_expr_spans(((vader_struct_toolchain_ast_ExprStmt_t*) l2)->f_expr, l1);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 443u) {
        l2 = l0.payload.obj;
        l3 = vader_resolver_next_clone_span(l1);
        ((vader_struct_toolchain_ast_ReturnStmt_t*) l2)->f_span = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_ReturnStmt_t*) l2);
        if (!(((vader_struct_toolchain_ast_ReturnStmt_t*) l2)->f_value.tag == 0u)) {
            vader_resolver_stamp_expr_spans(((vader_struct_toolchain_ast_ReturnStmt_t*) l2)->f_value, l1);
        } else {
        }
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 380u) {
        l2 = l0.payload.obj;
        l3 = vader_resolver_next_clone_span(l1);
        ((vader_struct_toolchain_ast_AssignStmt_t*) l2)->f_span = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_AssignStmt_t*) l2);
        vader_resolver_stamp_expr_spans(((vader_struct_toolchain_ast_AssignStmt_t*) l2)->f_target, l1);
        vader_resolver_stamp_expr_spans(((vader_struct_toolchain_ast_AssignStmt_t*) l2)->f_value, l1);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 410u) {
        l2 = l0.payload.obj;
        l3 = vader_resolver_next_clone_span(l1);
        ((vader_struct_toolchain_ast_ForStmt_t*) l2)->f_span = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_ForStmt_t*) l2);
        l4 = ((vader_struct_toolchain_ast_ForStmt_t*) l2)->f_form;
        if (l4.tag == 462u) {
            t0 = l4.payload.obj;
            vader_resolver_stamp_expr_spans(((vader_struct_toolchain_ast_WhileFor_t*) t0)->f_cond, l1);
            vader_resolver_stamp_block_spans(((vader_struct_toolchain_ast_ForStmt_t*) l2)->f_body, l1);
            { vader_gc_top = gc_frame.prev; return; }
        }
        if (l4.tag == 419u) {
            l3 = l4.payload.obj;
            l5 = ((vader_struct_toolchain_ast_InFor_t*) l3)->f_loop_var;
            if (l5.tag == 433u) {
                t0 = l5.payload.obj;
                l6 = ((vader_struct_toolchain_ast_NamedVar_t*) t0)->f_name;
                l7 = vader_resolver_next_clone_span(l1);
                vader_struct_toolchain_ast_NamedVar_t* _a0_obj = (vader_struct_toolchain_ast_NamedVar_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_NamedVar_t));
                vader_obj_header_init(_a0_obj, 433u);
                _a0_obj->f_name = l6;
                _a0_obj->f_span = l7;
                l7 = (void*) _a0_obj;
                ((vader_struct_toolchain_ast_InFor_t*) l3)->f_loop_var = vader_ref_box(l7);
                VADER_WRITE_BARRIER((vader_struct_toolchain_ast_InFor_t*) l3);
                vader_resolver_stamp_expr_spans(((vader_struct_toolchain_ast_InFor_t*) l3)->f_iter, l1);
                vader_resolver_stamp_block_spans(((vader_struct_toolchain_ast_ForStmt_t*) l2)->f_body, l1);
                { vader_gc_top = gc_frame.prev; return; }
            }
            if (l5.tag == 398u) {
                t0 = l5.payload.obj;
                vader_resolver_stamp_binding_spans(((vader_struct_toolchain_ast_DestructureVar_t*) t0)->f_pattern, l1);
                vader_resolver_stamp_expr_spans(((vader_struct_toolchain_ast_InFor_t*) l3)->f_iter, l1);
                vader_resolver_stamp_block_spans(((vader_struct_toolchain_ast_ForStmt_t*) l2)->f_body, l1);
                { vader_gc_top = gc_frame.prev; return; }
            }
            if (l5.tag == 399u) {
                vader_resolver_stamp_expr_spans(((vader_struct_toolchain_ast_InFor_t*) l3)->f_iter, l1);
                vader_resolver_stamp_block_spans(((vader_struct_toolchain_ast_ForStmt_t*) l2)->f_body, l1);
                { vader_gc_top = gc_frame.prev; return; }
            }
            { vader_gc_top = gc_frame.prev; return; }
        }
        if (l4.tag == 421u) {
            vader_resolver_stamp_block_spans(((vader_struct_toolchain_ast_ForStmt_t*) l2)->f_body, l1);
            { vader_gc_top = gc_frame.prev; return; }
        }
        { vader_gc_top = gc_frame.prev; return; }
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
    vader_array_t* _a0_arr = vader_array_new(111u, 0u, 13u, 1028u);
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
            } else {
            }
        }
    }
    l6 = vader_box_obj(0u, NULL);
    if (!(((vader_struct_toolchain_ast_BlockExpr_t*) l0)->f_trailing.tag == 0u)) {
        l6 = vader_resolver_substitute_expr_full(((vader_struct_toolchain_ast_BlockExpr_t*) l0)->f_trailing, l1);
    } else {
    }
    vader_struct_toolchain_ast_BlockExpr_t* _a2_obj = (vader_struct_toolchain_ast_BlockExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_BlockExpr_t));
    vader_obj_header_init(_a2_obj, 384u);
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
    void* l2 = NULL;
    void* l3 = NULL;
    vader_box_t l4 = vader_box_null();
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l0, &l4, &t1 };
    void** gc_raw_roots[4] = { &l1, &l2, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 443u) {
        l2 = l0.payload.obj;
        l3 = ((vader_struct_toolchain_ast_ReturnStmt_t*) l2)->f_span;
        l4 = vader_resolver_subst_opt_expr(((vader_struct_toolchain_ast_ReturnStmt_t*) l2)->f_value, l1);
        vader_struct_toolchain_ast_ReturnStmt_t* _a0_obj = (vader_struct_toolchain_ast_ReturnStmt_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_ReturnStmt_t));
        vader_obj_header_init(_a0_obj, 443u);
        _a0_obj->f_span = l3;
        _a0_obj->f_id = (size_t) (int64_t) INT64_C(0);
        _a0_obj->f_value = l4;
        t0 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if ((l0.tag == 386u || l0.tag == 392u)) {
        { vader_box_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if ((l0.tag == 378u || l0.tag == 381u || l0.tag == 382u || l0.tag == 384u || l0.tag == 385u || l0.tag == 388u || l0.tag == 389u || l0.tag == 390u || l0.tag == 400u || l0.tag == 405u || l0.tag == 406u || l0.tag == 409u || l0.tag == 411u || l0.tag == 412u || l0.tag == 415u || l0.tag == 420u || l0.tag == 422u || l0.tag == 423u || l0.tag == 425u || l0.tag == 429u || l0.tag == 431u || l0.tag == 434u || l0.tag == 435u || l0.tag == 440u || l0.tag == 444u || l0.tag == 446u || l0.tag == 451u || l0.tag == 461u)) {
        t1 = vader_resolver_substitute_expr_full(l0, l1);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_unreachable("unreachable return in vader_resolver$substitute_coalesce_fallback");
    vader_gc_top = gc_frame.prev;
}

static vader_box_t vader_resolver_substitute_expr_full(vader_box_t l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l6 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    void* l12 = NULL;
    void* l17 = NULL;
    void* l18 = NULL;
    void* l19 = NULL;
    void* l20 = NULL;
    vader_box_t l4 = vader_box_null(), l5 = vader_box_null(), l15 = vader_box_null();
    size_t l7, l8, l21;
    bool l11, l16;
    vader_string_t l13 = 0;
    uint8_t l14;
    void* t0 = NULL;
    void* t3 = NULL;
    vader_box_t t1 = vader_box_null();
    int64_t t2;
    vader_box_t* gc_roots[5] = { &l0, &l4, &l5, &l15, &t1 };
    void** gc_raw_roots[13] = { &l1, &l2, &l3, &l6, &l9, &l10, &l12, &l17, &l18, &l19, &l20, &t0, &t3 };
    vader_string_t* gc_atom_roots[1] = { &l13 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 5u, 13u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    if ((l0.tag == 385u || l0.tag == 390u || l0.tag == 406u || l0.tag == 422u || l0.tag == 435u)) {
        { vader_box_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 434u) {
        l2 = l0.payload.obj;
        l3 = ((vader_struct_toolchain_ast_NullCoalesceExpr_t*) l2)->f_span;
        l4 = vader_resolver_substitute_expr_full(((vader_struct_toolchain_ast_NullCoalesceExpr_t*) l2)->f_left, l1);
        l5 = vader_resolver_substitute_coalesce_fallback(((vader_struct_toolchain_ast_NullCoalesceExpr_t*) l2)->f_fallback, l1);
        vader_struct_toolchain_ast_NullCoalesceExpr_t* _a0_obj = (vader_struct_toolchain_ast_NullCoalesceExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_NullCoalesceExpr_t));
        vader_obj_header_init(_a0_obj, 434u);
        _a0_obj->f_span = l3;
        _a0_obj->f_id = (size_t) (int64_t) INT64_C(0);
        _a0_obj->f_left = l4;
        _a0_obj->f_fallback = l5;
        t0 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 412u) {
        t0 = l0.payload.obj;
        t1 = vader_resolver_substitute_type_expr(vader_ref_box(t0), l1);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 411u) {
        t0 = l0.payload.obj;
        t1 = vader_resolver_substitute_type_expr(vader_ref_box(t0), l1);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 409u) {
        t0 = l0.payload.obj;
        t1 = vader_resolver_substitute_type_expr(vader_ref_box(t0), l1);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 378u) {
        t0 = l0.payload.obj;
        t1 = vader_resolver_substitute_type_expr(vader_ref_box(t0), l1);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 431u) {
        t0 = l0.payload.obj;
        t1 = vader_resolver_substitute_type_expr(vader_ref_box(t0), l1);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 388u) {
        l2 = l0.payload.obj;
        vader_array_t* _a1_arr = vader_array_new(19u, 0u, 13u, 387u);
        l3 = (void*) _a1_arr;
        l6 = ((vader_struct_toolchain_ast_CallExpr_t*) l2)->f_args;
        l7 = ((vader_array_t*) l6)->length;
        l8 = (size_t) (int64_t) INT64_C(0);
        {
            loop_89: {
                if ((l8 < l7)) {
                    vader_array_t* _a2_slotarr = ((vader_array_t*) l6);
                    if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                    if ((size_t) l8 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                    l9 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l8);
                    l10 = ((vader_struct_toolchain_ast_CallArg_t*) l9)->f_span;
                    l4 = ((vader_struct_toolchain_ast_CallArg_t*) l9)->f_name;
                    l5 = vader_resolver_substitute_expr_full(((vader_struct_toolchain_ast_CallArg_t*) l9)->f_value, l1);
                    l11 = ((vader_struct_toolchain_ast_CallArg_t*) l9)->f_spread;
                    vader_struct_toolchain_ast_CallArg_t* _a3_obj = (vader_struct_toolchain_ast_CallArg_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_CallArg_t));
                    vader_obj_header_init(_a3_obj, 387u);
                    _a3_obj->f_span = l10;
                    _a3_obj->f_id = (size_t) (int64_t) INT64_C(0);
                    _a3_obj->f_name = l4;
                    _a3_obj->f_value = l5;
                    _a3_obj->f_spread = l11;
                    l12 = (void*) _a3_obj;
                    vader_array_push((vader_array_t*) l3, vader_ref_box(l12));
                    t2 = (l8 + INT64_C(1));
                    l8 = (size_t) (int64_t) t2;
                    goto loop_89;
                } else {
                }
            }
        }
        l6 = ((vader_struct_toolchain_ast_CallExpr_t*) l2)->f_span;
        l4 = vader_resolver_substitute_expr_full(((vader_struct_toolchain_ast_CallExpr_t*) l2)->f_callee, l1);
        vader_struct_toolchain_ast_CallExpr_t* _a4_obj = (vader_struct_toolchain_ast_CallExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_CallExpr_t));
        vader_obj_header_init(_a4_obj, 388u);
        _a4_obj->f_span = l6;
        _a4_obj->f_id = (size_t) (int64_t) INT64_C(0);
        _a4_obj->f_callee = l4;
        _a4_obj->f_args = l3;
        _a4_obj->f_trailing_comma = false;
        t0 = (void*) _a4_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 405u) {
        l2 = l0.payload.obj;
        l3 = ((vader_struct_toolchain_ast_FieldExpr_t*) l2)->f_span;
        l4 = vader_resolver_substitute_expr_full(((vader_struct_toolchain_ast_FieldExpr_t*) l2)->f_target, l1);
        l13 = ((vader_struct_toolchain_ast_FieldExpr_t*) l2)->f_field;
        l6 = ((vader_struct_toolchain_ast_FieldExpr_t*) l2)->f_field_span;
        l11 = ((vader_struct_toolchain_ast_FieldExpr_t*) l2)->f_is_numeric;
        vader_struct_toolchain_ast_FieldExpr_t* _a5_obj = (vader_struct_toolchain_ast_FieldExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_FieldExpr_t));
        vader_obj_header_init(_a5_obj, 405u);
        _a5_obj->f_span = l3;
        _a5_obj->f_id = (size_t) (int64_t) INT64_C(0);
        _a5_obj->f_target = l4;
        _a5_obj->f_field = l13;
        _a5_obj->f_field_span = l6;
        _a5_obj->f_is_numeric = l11;
        t0 = (void*) _a5_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 420u) {
        l2 = l0.payload.obj;
        l3 = ((vader_struct_toolchain_ast_IndexExpr_t*) l2)->f_span;
        l4 = vader_resolver_substitute_expr_full(((vader_struct_toolchain_ast_IndexExpr_t*) l2)->f_target, l1);
        l5 = vader_resolver_substitute_expr_full(((vader_struct_toolchain_ast_IndexExpr_t*) l2)->f_index, l1);
        vader_struct_toolchain_ast_IndexExpr_t* _a6_obj = (vader_struct_toolchain_ast_IndexExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_IndexExpr_t));
        vader_obj_header_init(_a6_obj, 420u);
        _a6_obj->f_span = l3;
        _a6_obj->f_id = (size_t) (int64_t) INT64_C(0);
        _a6_obj->f_target = l4;
        _a6_obj->f_index = l5;
        t0 = (void*) _a6_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 461u) {
        l2 = l0.payload.obj;
        l3 = ((vader_struct_toolchain_ast_UnaryExpr_t*) l2)->f_span;
        l14 = ((vader_struct_toolchain_ast_UnaryExpr_t*) l2)->f_op;
        l4 = vader_resolver_substitute_expr_full(((vader_struct_toolchain_ast_UnaryExpr_t*) l2)->f_operand, l1);
        vader_struct_toolchain_ast_UnaryExpr_t* _a7_obj = (vader_struct_toolchain_ast_UnaryExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_UnaryExpr_t));
        vader_obj_header_init(_a7_obj, 461u);
        _a7_obj->f_span = l3;
        _a7_obj->f_id = (size_t) (int64_t) INT64_C(0);
        _a7_obj->f_op = l14;
        _a7_obj->f_operand = l4;
        t0 = (void*) _a7_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 382u) {
        l2 = l0.payload.obj;
        l3 = ((vader_struct_toolchain_ast_BinaryExpr_t*) l2)->f_span;
        l14 = ((vader_struct_toolchain_ast_BinaryExpr_t*) l2)->f_op;
        l4 = vader_resolver_substitute_expr_full(((vader_struct_toolchain_ast_BinaryExpr_t*) l2)->f_left, l1);
        l5 = vader_resolver_substitute_expr_full(((vader_struct_toolchain_ast_BinaryExpr_t*) l2)->f_right, l1);
        l13 = ((vader_struct_toolchain_ast_BinaryExpr_t*) l2)->f_bind_as;
        vader_struct_toolchain_ast_BinaryExpr_t* _a8_obj = (vader_struct_toolchain_ast_BinaryExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_BinaryExpr_t));
        vader_obj_header_init(_a8_obj, 382u);
        _a8_obj->f_span = l3;
        _a8_obj->f_id = (size_t) (int64_t) INT64_C(0);
        _a8_obj->f_op = l14;
        _a8_obj->f_left = l4;
        _a8_obj->f_right = l5;
        _a8_obj->f_bind_as = l13;
        t0 = (void*) _a8_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 415u) {
        l2 = l0.payload.obj;
        l4 = vader_box_obj(0u, NULL);
        l5 = ((vader_struct_toolchain_ast_IfExpr_t*) l2)->f_else_branch;
        if (l5.tag == 0u) {
            l3 = ((vader_struct_toolchain_ast_IfExpr_t*) l2)->f_span;
            l7 = (size_t) (int64_t) INT64_C(0);
            l15 = vader_resolver_substitute_expr_full(((vader_struct_toolchain_ast_IfExpr_t*) l2)->f_cond, l1);
            l6 = vader_resolver_substitute_block(((vader_struct_toolchain_ast_IfExpr_t*) l2)->f_then_block, l1);
            vader_struct_toolchain_ast_IfExpr_t* _a9_obj = (vader_struct_toolchain_ast_IfExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_IfExpr_t));
            vader_obj_header_init(_a9_obj, 415u);
            _a9_obj->f_span = l3;
            _a9_obj->f_id = l7;
            _a9_obj->f_cond = l15;
            _a9_obj->f_then_block = l6;
            _a9_obj->f_else_branch = l4;
            t0 = (void*) _a9_obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l5.tag == 413u) {
            t0 = l5.payload.obj;
            t3 = vader_resolver_substitute_block(((vader_struct_toolchain_ast_IfElseBlock_t*) t0)->f_block, l1);
            vader_struct_toolchain_ast_IfElseBlock_t* _a10_obj = (vader_struct_toolchain_ast_IfElseBlock_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_IfElseBlock_t));
            vader_obj_header_init(_a10_obj, 413u);
            _a10_obj->f_block = t3;
            t0 = (void*) _a10_obj;
            l4 = vader_ref_box(t0);
            l3 = ((vader_struct_toolchain_ast_IfExpr_t*) l2)->f_span;
            l7 = (size_t) (int64_t) INT64_C(0);
            l15 = vader_resolver_substitute_expr_full(((vader_struct_toolchain_ast_IfExpr_t*) l2)->f_cond, l1);
            l6 = vader_resolver_substitute_block(((vader_struct_toolchain_ast_IfExpr_t*) l2)->f_then_block, l1);
            vader_struct_toolchain_ast_IfExpr_t* _a11_obj = (vader_struct_toolchain_ast_IfExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_IfExpr_t));
            vader_obj_header_init(_a11_obj, 415u);
            _a11_obj->f_span = l3;
            _a11_obj->f_id = l7;
            _a11_obj->f_cond = l15;
            _a11_obj->f_then_block = l6;
            _a11_obj->f_else_branch = l4;
            t0 = (void*) _a11_obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l5.tag == 414u) {
            t0 = l5.payload.obj;
            l5 = vader_resolver_substitute_expr_full(vader_ref_box(((vader_struct_toolchain_ast_IfElseIf_t*) t0)->f_branch), l1);
            if (l5.tag == 415u) {
                t0 = l5.payload.obj;
                vader_struct_toolchain_ast_IfElseIf_t* _a12_obj = (vader_struct_toolchain_ast_IfElseIf_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_IfElseIf_t));
                vader_obj_header_init(_a12_obj, 414u);
                _a12_obj->f_branch = t0;
                t0 = (void*) _a12_obj;
                l4 = vader_ref_box(t0);
            } else {
            }
            l3 = ((vader_struct_toolchain_ast_IfExpr_t*) l2)->f_span;
            l7 = (size_t) (int64_t) INT64_C(0);
            l15 = vader_resolver_substitute_expr_full(((vader_struct_toolchain_ast_IfExpr_t*) l2)->f_cond, l1);
            l6 = vader_resolver_substitute_block(((vader_struct_toolchain_ast_IfExpr_t*) l2)->f_then_block, l1);
            vader_struct_toolchain_ast_IfExpr_t* _a13_obj = (vader_struct_toolchain_ast_IfExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_IfExpr_t));
            vader_obj_header_init(_a13_obj, 415u);
            _a13_obj->f_span = l3;
            _a13_obj->f_id = l7;
            _a13_obj->f_cond = l15;
            _a13_obj->f_then_block = l6;
            _a13_obj->f_else_branch = l4;
            t0 = (void*) _a13_obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        vader_unreachable("unreachable return in vader_resolver$substitute_expr_full");
    }
    if (l0.tag == 429u) {
        l2 = l0.payload.obj;
        vader_array_t* _a14_arr = vader_array_new(27u, 0u, 13u, 428u);
        l3 = (void*) _a14_arr;
        l6 = ((vader_struct_toolchain_ast_MatchExpr_t*) l2)->f_arms;
        l7 = ((vader_array_t*) l6)->length;
        l8 = (size_t) (int64_t) INT64_C(0);
        {
            loop_361: {
                if ((l8 < l7)) {
                    vader_array_t* _a15_slotarr = ((vader_array_t*) l6);
                    if (_a15_slotarr->buf != NULL && _a15_slotarr->buf->header.forward != NULL) { _a15_slotarr->buf = vader_array_buf_forward(_a15_slotarr->buf); }
                    if ((size_t) l8 >= _a15_slotarr->length) { vader_trap("array index out of bounds"); }
                    l9 = vader_array_ref_load_obj(_a15_slotarr->buf, _a15_slotarr->offset + (size_t) l8);
                    l4 = vader_box_obj(0u, NULL);
                    if (!(((vader_struct_toolchain_ast_MatchArm_t*) l9)->f_guard.tag == 0u)) {
                        l4 = vader_resolver_substitute_expr_full(((vader_struct_toolchain_ast_MatchArm_t*) l9)->f_guard, l1);
                    } else {
                    }
                    l10 = ((vader_struct_toolchain_ast_MatchArm_t*) l9)->f_span;
                    l5 = vader_resolver_substitute_pattern(((vader_struct_toolchain_ast_MatchArm_t*) l9)->f_pattern, l1);
                    l15 = vader_resolver_substitute_expr_full(((vader_struct_toolchain_ast_MatchArm_t*) l9)->f_body, l1);
                    vader_struct_toolchain_ast_MatchArm_t* _a16_obj = (vader_struct_toolchain_ast_MatchArm_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_MatchArm_t));
                    vader_obj_header_init(_a16_obj, 428u);
                    _a16_obj->f_span = l10;
                    _a16_obj->f_id = (size_t) (int64_t) INT64_C(0);
                    _a16_obj->f_pattern = l5;
                    _a16_obj->f_guard = l4;
                    _a16_obj->f_body = l15;
                    l12 = (void*) _a16_obj;
                    vader_array_push((vader_array_t*) l3, vader_ref_box(l12));
                    t2 = (l8 + INT64_C(1));
                    l8 = (size_t) (int64_t) t2;
                    goto loop_361;
                } else {
                }
            }
        }
        l6 = ((vader_struct_toolchain_ast_MatchExpr_t*) l2)->f_span;
        l4 = vader_resolver_substitute_expr_full(((vader_struct_toolchain_ast_MatchExpr_t*) l2)->f_scrutinee, l1);
        l11 = ((vader_struct_toolchain_ast_MatchExpr_t*) l2)->f_partial;
        l16 = ((vader_struct_toolchain_ast_MatchExpr_t*) l2)->f_unreachable;
        vader_struct_toolchain_ast_MatchExpr_t* _a17_obj = (vader_struct_toolchain_ast_MatchExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_MatchExpr_t));
        vader_obj_header_init(_a17_obj, 429u);
        _a17_obj->f_span = l6;
        _a17_obj->f_id = (size_t) (int64_t) INT64_C(0);
        _a17_obj->f_scrutinee = l4;
        _a17_obj->f_arms = l3;
        _a17_obj->f_partial = l11;
        _a17_obj->f_unreachable = l16;
        t0 = (void*) _a17_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 384u) {
        t0 = l0.payload.obj;
        t3 = vader_resolver_substitute_block(t0, l1);
        { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 451u) {
        l2 = l0.payload.obj;
        vader_array_t* _a18_arr = vader_array_new(116u, 0u, 13u, 1057u);
        l3 = (void*) _a18_arr;
        l6 = ((vader_struct_toolchain_ast_StructLitExpr_t*) l2)->f_items;
        l7 = ((vader_array_t*) l6)->length;
        l8 = (size_t) (int64_t) INT64_C(0);
        {
            loop_456: {
                if ((l8 < l7)) {
                    vader_array_t* _a19_slotarr = ((vader_array_t*) l6);
                    if (_a19_slotarr->buf != NULL && _a19_slotarr->buf->header.forward != NULL) { _a19_slotarr->buf = vader_array_buf_forward(_a19_slotarr->buf); }
                    if ((size_t) l8 >= _a19_slotarr->length) { vader_trap("array index out of bounds"); }
                    l4 = vader_array_ref_load_box(_a19_slotarr->buf, _a19_slotarr->offset + (size_t) l8);
                    if (l4.tag == 452u) {
                        l9 = l4.payload.obj;
                        l10 = ((vader_struct_toolchain_ast_StructLitField_t*) l9)->f_span;
                        l13 = ((vader_struct_toolchain_ast_StructLitField_t*) l9)->f_name;
                        l12 = ((vader_struct_toolchain_ast_StructLitField_t*) l9)->f_name_span;
                        l5 = vader_resolver_substitute_expr_full(((vader_struct_toolchain_ast_StructLitField_t*) l9)->f_value, l1);
                        vader_struct_toolchain_ast_StructLitField_t* _a20_obj = (vader_struct_toolchain_ast_StructLitField_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_StructLitField_t));
                        vader_obj_header_init(_a20_obj, 452u);
                        _a20_obj->f_span = l10;
                        _a20_obj->f_id = (size_t) (int64_t) INT64_C(0);
                        _a20_obj->f_name = l13;
                        _a20_obj->f_name_span = l12;
                        _a20_obj->f_value = l5;
                        l17 = (void*) _a20_obj;
                        vader_array_push((vader_array_t*) l3, vader_ref_box(l17));
                        l21 = (size_t) (int64_t) INT64_C(1);
                        t2 = (l8 + l21);
                        l8 = (size_t) (int64_t) t2;
                        goto loop_456;
                    }
                    if (l4.tag == 453u) {
                        l18 = l4.payload.obj;
                        l19 = ((vader_struct_toolchain_ast_StructLitSpread_t*) l18)->f_span;
                        l15 = vader_resolver_substitute_expr_full(((vader_struct_toolchain_ast_StructLitSpread_t*) l18)->f_expr, l1);
                        vader_struct_toolchain_ast_StructLitSpread_t* _a21_obj = (vader_struct_toolchain_ast_StructLitSpread_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_StructLitSpread_t));
                        vader_obj_header_init(_a21_obj, 453u);
                        _a21_obj->f_span = l19;
                        _a21_obj->f_id = (size_t) (int64_t) INT64_C(0);
                        _a21_obj->f_expr = l15;
                        l20 = (void*) _a21_obj;
                        vader_array_push((vader_array_t*) l3, vader_ref_box(l20));
                        l21 = (size_t) (int64_t) INT64_C(1);
                        t2 = (l8 + l21);
                        l8 = (size_t) (int64_t) t2;
                        goto loop_456;
                    }
                    vader_unreachable("unreachable return in vader_resolver$substitute_expr_full");
                } else {
                }
            }
        }
        l6 = ((vader_struct_toolchain_ast_StructLitExpr_t*) l2)->f_span;
        l4 = vader_resolver_substitute_type_expr(((vader_struct_toolchain_ast_StructLitExpr_t*) l2)->f_type_name, l1);
        vader_struct_toolchain_ast_StructLitExpr_t* _a22_obj = (vader_struct_toolchain_ast_StructLitExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_StructLitExpr_t));
        vader_obj_header_init(_a22_obj, 451u);
        _a22_obj->f_span = l6;
        _a22_obj->f_id = (size_t) (int64_t) INT64_C(0);
        _a22_obj->f_type_name = l4;
        _a22_obj->f_items = l3;
        _a22_obj->f_trailing_comma = false;
        t0 = (void*) _a22_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 444u) {
        l2 = l0.payload.obj;
        vader_array_t* _a23_arr = vader_array_new(109u, 0u, 13u, 1015u);
        l3 = (void*) _a23_arr;
        l6 = ((vader_struct_toolchain_ast_SeqLitExpr_t*) l2)->f_elements;
        l7 = ((vader_array_t*) l6)->length;
        l8 = (size_t) (int64_t) INT64_C(0);
        {
            loop_561: {
                if ((l8 < l7)) {
                    vader_array_t* _a24_slotarr = ((vader_array_t*) l6);
                    if (_a24_slotarr->buf != NULL && _a24_slotarr->buf->header.forward != NULL) { _a24_slotarr->buf = vader_array_buf_forward(_a24_slotarr->buf); }
                    if ((size_t) l8 >= _a24_slotarr->length) { vader_trap("array index out of bounds"); }
                    t1 = vader_array_ref_load_box(_a24_slotarr->buf, _a24_slotarr->offset + (size_t) l8);
                    l4 = vader_resolver_substitute_expr_full(t1, l1);
                    vader_array_push((vader_array_t*) l3, l4);
                    t2 = (l8 + INT64_C(1));
                    l8 = (size_t) (int64_t) t2;
                    goto loop_561;
                } else {
                }
            }
        }
        vader_struct_toolchain_ast_SeqLitExpr_t* _a25_obj = (vader_struct_toolchain_ast_SeqLitExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_SeqLitExpr_t));
        vader_obj_header_init(_a25_obj, 444u);
        _a25_obj->f_span = ((vader_struct_toolchain_ast_SeqLitExpr_t*) l2)->f_span;
        _a25_obj->f_id = (size_t) (int64_t) INT64_C(0);
        _a25_obj->f_elements = l3;
        _a25_obj->f_trailing_comma = false;
        t0 = (void*) _a25_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 440u) {
        l2 = l0.payload.obj;
        l3 = ((vader_struct_toolchain_ast_RangeExpr_t*) l2)->f_span;
        l11 = ((vader_struct_toolchain_ast_RangeExpr_t*) l2)->f_inclusive;
        l4 = vader_resolver_substitute_expr_full(((vader_struct_toolchain_ast_RangeExpr_t*) l2)->f_lower, l1);
        l5 = vader_resolver_substitute_expr_full(((vader_struct_toolchain_ast_RangeExpr_t*) l2)->f_upper, l1);
        vader_struct_toolchain_ast_RangeExpr_t* _a26_obj = (vader_struct_toolchain_ast_RangeExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_RangeExpr_t));
        vader_obj_header_init(_a26_obj, 440u);
        _a26_obj->f_span = l3;
        _a26_obj->f_id = (size_t) (int64_t) INT64_C(0);
        _a26_obj->f_inclusive = l11;
        _a26_obj->f_lower = l4;
        _a26_obj->f_upper = l5;
        t0 = (void*) _a26_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 381u) {
        l2 = l0.payload.obj;
        l3 = ((vader_struct_toolchain_ast_AwaitExpr_t*) l2)->f_span;
        l4 = vader_resolver_substitute_expr_full(((vader_struct_toolchain_ast_AwaitExpr_t*) l2)->f_inner, l1);
        vader_struct_toolchain_ast_AwaitExpr_t* _a27_obj = (vader_struct_toolchain_ast_AwaitExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_AwaitExpr_t));
        vader_obj_header_init(_a27_obj, 381u);
        _a27_obj->f_span = l3;
        _a27_obj->f_id = (size_t) (int64_t) INT64_C(0);
        _a27_obj->f_inner = l4;
        t0 = (void*) _a27_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 389u) {
        l2 = l0.payload.obj;
        l3 = ((vader_struct_toolchain_ast_CastExpr_t*) l2)->f_span;
        l4 = vader_resolver_substitute_type_expr(((vader_struct_toolchain_ast_CastExpr_t*) l2)->f_target, l1);
        l5 = vader_resolver_substitute_expr_full(((vader_struct_toolchain_ast_CastExpr_t*) l2)->f_value, l1);
        vader_struct_toolchain_ast_CastExpr_t* _a28_obj = (vader_struct_toolchain_ast_CastExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_CastExpr_t));
        vader_obj_header_init(_a28_obj, 389u);
        _a28_obj->f_span = l3;
        _a28_obj->f_id = (size_t) (int64_t) INT64_C(0);
        _a28_obj->f_target = l4;
        _a28_obj->f_value = l5;
        t0 = (void*) _a28_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 423u) {
        l2 = l0.payload.obj;
        vader_array_t* _a29_arr = vader_array_new(109u, 0u, 13u, 1015u);
        l3 = (void*) _a29_arr;
        l6 = ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l2)->f_args;
        l7 = ((vader_array_t*) l6)->length;
        l8 = (size_t) (int64_t) INT64_C(0);
        {
            loop_674: {
                if ((l8 < l7)) {
                    vader_array_t* _a30_slotarr = ((vader_array_t*) l6);
                    if (_a30_slotarr->buf != NULL && _a30_slotarr->buf->header.forward != NULL) { _a30_slotarr->buf = vader_array_buf_forward(_a30_slotarr->buf); }
                    if ((size_t) l8 >= _a30_slotarr->length) { vader_trap("array index out of bounds"); }
                    t1 = vader_array_ref_load_box(_a30_slotarr->buf, _a30_slotarr->offset + (size_t) l8);
                    l4 = vader_resolver_substitute_expr_full(t1, l1);
                    vader_array_push((vader_array_t*) l3, l4);
                    t2 = (l8 + INT64_C(1));
                    l8 = (size_t) (int64_t) t2;
                    goto loop_674;
                } else {
                }
            }
        }
        l6 = ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l2)->f_span;
        l13 = ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l2)->f_name;
        l2 = ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l2)->f_name_span;
        vader_struct_toolchain_ast_IntrinsicCallExpr_t* _a31_obj = (vader_struct_toolchain_ast_IntrinsicCallExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_IntrinsicCallExpr_t));
        vader_obj_header_init(_a31_obj, 423u);
        _a31_obj->f_span = l6;
        _a31_obj->f_id = (size_t) (int64_t) INT64_C(0);
        _a31_obj->f_name = l13;
        _a31_obj->f_name_span = l2;
        _a31_obj->f_args = l3;
        _a31_obj->f_trailing_comma = false;
        t0 = (void*) _a31_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 400u) {
        l2 = l0.payload.obj;
        l3 = ((vader_struct_toolchain_ast_DotVariantExpr_t*) l2)->f_span;
        l13 = ((vader_struct_toolchain_ast_DotVariantExpr_t*) l2)->f_variant;
        l2 = ((vader_struct_toolchain_ast_DotVariantExpr_t*) l2)->f_variant_span;
        vader_struct_toolchain_ast_DotVariantExpr_t* _a32_obj = (vader_struct_toolchain_ast_DotVariantExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_DotVariantExpr_t));
        vader_obj_header_init(_a32_obj, 400u);
        _a32_obj->f_span = l3;
        _a32_obj->f_id = (size_t) (int64_t) INT64_C(0);
        _a32_obj->f_variant = l13;
        _a32_obj->f_variant_span = l2;
        t0 = (void*) _a32_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 446u) {
        l2 = l0.payload.obj;
        vader_array_t* _a33_arr = vader_array_new(115u, 0u, 13u, 1056u);
        l3 = (void*) _a33_arr;
        l6 = ((vader_struct_toolchain_ast_StringLitExpr_t*) l2)->f_parts;
        l7 = ((vader_array_t*) l6)->length;
        l8 = (size_t) (int64_t) INT64_C(0);
        {
            loop_748: {
                if ((l8 < l7)) {
                    vader_array_t* _a34_slotarr = ((vader_array_t*) l6);
                    if (_a34_slotarr->buf != NULL && _a34_slotarr->buf->header.forward != NULL) { _a34_slotarr->buf = vader_array_buf_forward(_a34_slotarr->buf); }
                    if ((size_t) l8 >= _a34_slotarr->length) { vader_trap("array index out of bounds"); }
                    l4 = vader_array_ref_load_box(_a34_slotarr->buf, _a34_slotarr->offset + (size_t) l8);
                    if (l4.tag == 448u) {
                        l9 = l4.payload.obj;
                        l13 = ((vader_struct_toolchain_ast_StringLitText_t*) l9)->f_value;
                        l10 = ((vader_struct_toolchain_ast_StringLitText_t*) l9)->f_span;
                        vader_struct_toolchain_ast_StringLitText_t* _a35_obj = (vader_struct_toolchain_ast_StringLitText_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_StringLitText_t));
                        vader_obj_header_init(_a35_obj, 448u);
                        _a35_obj->f_value = l13;
                        _a35_obj->f_span = l10;
                        _a35_obj->f_id = (size_t) (int64_t) INT64_C(0);
                        l12 = (void*) _a35_obj;
                        vader_array_push((vader_array_t*) l3, vader_ref_box(l12));
                        l21 = (size_t) (int64_t) INT64_C(1);
                        t2 = (l8 + l21);
                        l8 = (size_t) (int64_t) t2;
                        goto loop_748;
                    }
                    if (l4.tag == 447u) {
                        l17 = l4.payload.obj;
                        l5 = vader_resolver_substitute_expr_full(((vader_struct_toolchain_ast_StringLitInterp_t*) l17)->f_expr, l1);
                        l18 = ((vader_struct_toolchain_ast_StringLitInterp_t*) l17)->f_span;
                        vader_struct_toolchain_ast_StringLitInterp_t* _a36_obj = (vader_struct_toolchain_ast_StringLitInterp_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_StringLitInterp_t));
                        vader_obj_header_init(_a36_obj, 447u);
                        _a36_obj->f_expr = l5;
                        _a36_obj->f_span = l18;
                        _a36_obj->f_id = (size_t) (int64_t) INT64_C(0);
                        l19 = (void*) _a36_obj;
                        vader_array_push((vader_array_t*) l3, vader_ref_box(l19));
                        l21 = (size_t) (int64_t) INT64_C(1);
                        t2 = (l8 + l21);
                        l8 = (size_t) (int64_t) t2;
                        goto loop_748;
                    }
                    vader_unreachable("unreachable return in vader_resolver$substitute_expr_full");
                } else {
                }
            }
        }
        vader_struct_toolchain_ast_StringLitExpr_t* _a37_obj = (vader_struct_toolchain_ast_StringLitExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_StringLitExpr_t));
        vader_obj_header_init(_a37_obj, 446u);
        _a37_obj->f_span = ((vader_struct_toolchain_ast_StringLitExpr_t*) l2)->f_span;
        _a37_obj->f_id = (size_t) (int64_t) INT64_C(0);
        _a37_obj->f_parts = l3;
        t0 = (void*) _a37_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 425u) {
        l2 = l0.payload.obj;
        vader_array_t* _a38_arr = vader_array_new(24u, 0u, 13u, 408u);
        l3 = (void*) _a38_arr;
        l6 = ((vader_struct_toolchain_ast_LambdaExpr_t*) l2)->f_params;
        l7 = ((vader_array_t*) l6)->length;
        l8 = (size_t) (int64_t) INT64_C(0);
        {
            loop_837: {
                if ((l8 < l7)) {
                    vader_array_t* _a39_slotarr = ((vader_array_t*) l6);
                    if (_a39_slotarr->buf != NULL && _a39_slotarr->buf->header.forward != NULL) { _a39_slotarr->buf = vader_array_buf_forward(_a39_slotarr->buf); }
                    if ((size_t) l8 >= _a39_slotarr->length) { vader_trap("array index out of bounds"); }
                    l9 = vader_array_ref_load_obj(_a39_slotarr->buf, _a39_slotarr->offset + (size_t) l8);
                    l4 = vader_box_obj(0u, NULL);
                    if (!(((vader_struct_toolchain_ast_FnParam_t*) l9)->f_ty.tag == 0u)) {
                        l4 = vader_resolver_substitute_type_expr(((vader_struct_toolchain_ast_FnParam_t*) l9)->f_ty, l1);
                    } else {
                    }
                    l5 = vader_box_obj(0u, NULL);
                    if (!(((vader_struct_toolchain_ast_FnParam_t*) l9)->f_default_value.tag == 0u)) {
                        l5 = vader_resolver_substitute_expr_full(((vader_struct_toolchain_ast_FnParam_t*) l9)->f_default_value, l1);
                    } else {
                    }
                    l10 = ((vader_struct_toolchain_ast_FnParam_t*) l9)->f_span;
                    l13 = ((vader_struct_toolchain_ast_FnParam_t*) l9)->f_name;
                    l11 = ((vader_struct_toolchain_ast_FnParam_t*) l9)->f_variadic;
                    l16 = ((vader_struct_toolchain_ast_FnParam_t*) l9)->f_mutable;
                    l12 = ((vader_struct_toolchain_ast_FnParam_t*) l9)->f_decorators;
                    vader_struct_toolchain_ast_FnParam_t* _a40_obj = (vader_struct_toolchain_ast_FnParam_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_FnParam_t));
                    vader_obj_header_init(_a40_obj, 408u);
                    _a40_obj->f_span = l10;
                    _a40_obj->f_id = (size_t) (int64_t) INT64_C(0);
                    _a40_obj->f_name = l13;
                    _a40_obj->f_ty = l4;
                    _a40_obj->f_default_value = l5;
                    _a40_obj->f_variadic = l11;
                    _a40_obj->f_mutable = l16;
                    _a40_obj->f_decorators = l12;
                    l17 = (void*) _a40_obj;
                    vader_array_push((vader_array_t*) l3, vader_ref_box(l17));
                    t2 = (l8 + INT64_C(1));
                    l8 = (size_t) (int64_t) t2;
                    goto loop_837;
                } else {
                }
            }
        }
        l4 = vader_box_obj(0u, NULL);
        if (!(((vader_struct_toolchain_ast_LambdaExpr_t*) l2)->f_return_type.tag == 0u)) {
            l4 = vader_resolver_substitute_type_expr(((vader_struct_toolchain_ast_LambdaExpr_t*) l2)->f_return_type, l1);
        } else {
        }
        l6 = ((vader_struct_toolchain_ast_LambdaExpr_t*) l2)->f_span;
        l2 = vader_resolver_substitute_block(((vader_struct_toolchain_ast_LambdaExpr_t*) l2)->f_body, l1);
        vader_struct_toolchain_ast_LambdaExpr_t* _a41_obj = (vader_struct_toolchain_ast_LambdaExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_LambdaExpr_t));
        vader_obj_header_init(_a41_obj, 425u);
        _a41_obj->f_span = l6;
        _a41_obj->f_id = (size_t) (int64_t) INT64_C(0);
        _a41_obj->f_params = l3;
        _a41_obj->f_return_type = l4;
        _a41_obj->f_body = l2;
        _a41_obj->f_trailing_comma = false;
        t0 = (void*) _a41_obj;
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
    vader_array_t* _a0_arr = vader_array_new(24u, 0u, 13u, 408u);
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
                vader_obj_header_init(_a2_obj, 408u);
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
            } else {
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
    vader_array_t* _a0_arr = vader_array_new(24u, 0u, 13u, 408u);
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
                if (t0 == 1955u) {
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
                vader_obj_header_init(_a2_obj, 408u);
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
            } else {
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
    vader_array_t* _a0_arr = vader_array_new(24u, 0u, 13u, 408u);
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
                vader_obj_header_init(_a2_obj, 408u);
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
            } else {
            }
        }
    }
    { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_box_t vader_resolver_substitute_pattern(vader_box_t l0, void* l1) {
    void* l2 = NULL;
    void* l4 = NULL;
    vader_box_t l3 = vader_box_null(), l5 = vader_box_null(), l6 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[4] = { &l0, &l3, &l5, &l6 };
    void** gc_raw_roots[4] = { &l1, &l2, &l4, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 424u) {
        l2 = l0.payload.obj;
        l3 = vader_box_obj(0u, NULL);
        if (!(((vader_struct_toolchain_ast_IsPattern_t*) l2)->f_inner.tag == 0u)) {
            l3 = vader_resolver_substitute_pattern(((vader_struct_toolchain_ast_IsPattern_t*) l2)->f_inner, l1);
        } else {
        }
        l4 = ((vader_struct_toolchain_ast_IsPattern_t*) l2)->f_span;
        l5 = vader_resolver_substitute_type_expr(((vader_struct_toolchain_ast_IsPattern_t*) l2)->f_ty, l1);
        l6 = ((vader_struct_toolchain_ast_IsPattern_t*) l2)->f_bind_as;
        vader_struct_toolchain_ast_IsPattern_t* _a0_obj = (vader_struct_toolchain_ast_IsPattern_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_IsPattern_t));
        vader_obj_header_init(_a0_obj, 424u);
        _a0_obj->f_span = l4;
        _a0_obj->f_id = (size_t) (int64_t) INT64_C(0);
        _a0_obj->f_ty = l5;
        _a0_obj->f_inner = l3;
        _a0_obj->f_bind_as = l6;
        t0 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_box_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_box_t vader_resolver_substitute_stmt(vader_box_t l0, void* l1) {
    void* l2 = NULL;
    void* l4 = NULL;
    void* l9 = NULL;
    void* l12 = NULL;
    vader_box_t l3 = vader_box_null(), l6 = vader_box_null(), l7 = vader_box_null(), l8 = vader_box_null(), l11 = vader_box_null();
    bool l5;
    size_t l10;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[7] = { &l0, &l3, &l6, &l7, &l8, &l11, &t1 };
    void** gc_raw_roots[6] = { &l1, &l2, &l4, &l9, &l12, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 7u, 6u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 426u) {
        l2 = l0.payload.obj;
        l3 = vader_box_obj(0u, NULL);
        if (!(((vader_struct_toolchain_ast_LetStmt_t*) l2)->f_ty.tag == 0u)) {
            l3 = vader_resolver_substitute_type_expr(((vader_struct_toolchain_ast_LetStmt_t*) l2)->f_ty, l1);
        } else {
        }
        l4 = ((vader_struct_toolchain_ast_LetStmt_t*) l2)->f_span;
        l5 = ((vader_struct_toolchain_ast_LetStmt_t*) l2)->f_mutable;
        l6 = vader_resolver_clone_let_binding(((vader_struct_toolchain_ast_LetStmt_t*) l2)->f_binding);
        l7 = vader_resolver_substitute_expr_full(((vader_struct_toolchain_ast_LetStmt_t*) l2)->f_value, l1);
        vader_struct_toolchain_ast_LetStmt_t* _a0_obj = (vader_struct_toolchain_ast_LetStmt_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_LetStmt_t));
        vader_obj_header_init(_a0_obj, 426u);
        _a0_obj->f_span = l4;
        _a0_obj->f_id = (size_t) (int64_t) INT64_C(0);
        _a0_obj->f_mutable = l5;
        _a0_obj->f_binding = l6;
        _a0_obj->f_ty = l3;
        _a0_obj->f_value = l7;
        t0 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 404u) {
        l2 = l0.payload.obj;
        l4 = ((vader_struct_toolchain_ast_ExprStmt_t*) l2)->f_span;
        l3 = vader_resolver_substitute_expr_full(((vader_struct_toolchain_ast_ExprStmt_t*) l2)->f_expr, l1);
        vader_struct_toolchain_ast_ExprStmt_t* _a1_obj = (vader_struct_toolchain_ast_ExprStmt_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_ExprStmt_t));
        vader_obj_header_init(_a1_obj, 404u);
        _a1_obj->f_span = l4;
        _a1_obj->f_id = (size_t) (int64_t) INT64_C(0);
        _a1_obj->f_expr = l3;
        t0 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 443u) {
        l2 = l0.payload.obj;
        l3 = vader_box_obj(0u, NULL);
        if (!(((vader_struct_toolchain_ast_ReturnStmt_t*) l2)->f_value.tag == 0u)) {
            l3 = vader_resolver_substitute_expr_full(((vader_struct_toolchain_ast_ReturnStmt_t*) l2)->f_value, l1);
        } else {
        }
        vader_struct_toolchain_ast_ReturnStmt_t* _a2_obj = (vader_struct_toolchain_ast_ReturnStmt_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_ReturnStmt_t));
        vader_obj_header_init(_a2_obj, 443u);
        _a2_obj->f_span = ((vader_struct_toolchain_ast_ReturnStmt_t*) l2)->f_span;
        _a2_obj->f_id = (size_t) (int64_t) INT64_C(0);
        _a2_obj->f_value = l3;
        t0 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 380u) {
        l2 = l0.payload.obj;
        l4 = ((vader_struct_toolchain_ast_AssignStmt_t*) l2)->f_span;
        l3 = vader_resolver_substitute_expr_full(((vader_struct_toolchain_ast_AssignStmt_t*) l2)->f_target, l1);
        l6 = vader_resolver_substitute_expr_full(((vader_struct_toolchain_ast_AssignStmt_t*) l2)->f_value, l1);
        vader_struct_toolchain_ast_AssignStmt_t* _a3_obj = (vader_struct_toolchain_ast_AssignStmt_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_AssignStmt_t));
        vader_obj_header_init(_a3_obj, 380u);
        _a3_obj->f_span = l4;
        _a3_obj->f_id = (size_t) (int64_t) INT64_C(0);
        _a3_obj->f_target = l3;
        _a3_obj->f_value = l6;
        t0 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 410u) {
        l2 = l0.payload.obj;
        l3 = ((vader_struct_toolchain_ast_ForStmt_t*) l2)->f_form;
        l6 = ((vader_struct_toolchain_ast_ForStmt_t*) l2)->f_form;
        if (l6.tag == 462u) {
            t0 = l6.payload.obj;
            t1 = vader_resolver_substitute_expr_full(((vader_struct_toolchain_ast_WhileFor_t*) t0)->f_cond, l1);
            vader_struct_toolchain_ast_WhileFor_t* _a4_obj = (vader_struct_toolchain_ast_WhileFor_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_WhileFor_t));
            vader_obj_header_init(_a4_obj, 462u);
            _a4_obj->f_cond = t1;
            t0 = (void*) _a4_obj;
            l3 = vader_ref_box(t0);
            l9 = ((vader_struct_toolchain_ast_ForStmt_t*) l2)->f_span;
            l10 = (size_t) (int64_t) INT64_C(0);
            l11 = ((vader_struct_toolchain_ast_ForStmt_t*) l2)->f_label;
            l12 = vader_resolver_substitute_block(((vader_struct_toolchain_ast_ForStmt_t*) l2)->f_body, l1);
            l5 = ((vader_struct_toolchain_ast_ForStmt_t*) l2)->f_is_comptime;
            vader_struct_toolchain_ast_ForStmt_t* _a5_obj = (vader_struct_toolchain_ast_ForStmt_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_ForStmt_t));
            vader_obj_header_init(_a5_obj, 410u);
            _a5_obj->f_span = l9;
            _a5_obj->f_id = l10;
            _a5_obj->f_label = l11;
            _a5_obj->f_form = l3;
            _a5_obj->f_body = l12;
            _a5_obj->f_is_comptime = l5;
            t0 = (void*) _a5_obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l6.tag == 419u) {
            l4 = l6.payload.obj;
            l7 = ((vader_struct_toolchain_ast_InFor_t*) l4)->f_loop_var;
            l8 = vader_resolver_substitute_expr_full(((vader_struct_toolchain_ast_InFor_t*) l4)->f_iter, l1);
            vader_struct_toolchain_ast_InFor_t* _a6_obj = (vader_struct_toolchain_ast_InFor_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_InFor_t));
            vader_obj_header_init(_a6_obj, 419u);
            _a6_obj->f_loop_var = l7;
            _a6_obj->f_iter = l8;
            t0 = (void*) _a6_obj;
            l3 = vader_ref_box(t0);
            l9 = ((vader_struct_toolchain_ast_ForStmt_t*) l2)->f_span;
            l10 = (size_t) (int64_t) INT64_C(0);
            l11 = ((vader_struct_toolchain_ast_ForStmt_t*) l2)->f_label;
            l12 = vader_resolver_substitute_block(((vader_struct_toolchain_ast_ForStmt_t*) l2)->f_body, l1);
            l5 = ((vader_struct_toolchain_ast_ForStmt_t*) l2)->f_is_comptime;
            vader_struct_toolchain_ast_ForStmt_t* _a7_obj = (vader_struct_toolchain_ast_ForStmt_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_ForStmt_t));
            vader_obj_header_init(_a7_obj, 410u);
            _a7_obj->f_span = l9;
            _a7_obj->f_id = l10;
            _a7_obj->f_label = l11;
            _a7_obj->f_form = l3;
            _a7_obj->f_body = l12;
            _a7_obj->f_is_comptime = l5;
            t0 = (void*) _a7_obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l6.tag == 421u) {
            l9 = ((vader_struct_toolchain_ast_ForStmt_t*) l2)->f_span;
            l10 = (size_t) (int64_t) INT64_C(0);
            l11 = ((vader_struct_toolchain_ast_ForStmt_t*) l2)->f_label;
            l12 = vader_resolver_substitute_block(((vader_struct_toolchain_ast_ForStmt_t*) l2)->f_body, l1);
            l5 = ((vader_struct_toolchain_ast_ForStmt_t*) l2)->f_is_comptime;
            vader_struct_toolchain_ast_ForStmt_t* _a8_obj = (vader_struct_toolchain_ast_ForStmt_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_ForStmt_t));
            vader_obj_header_init(_a8_obj, 410u);
            _a8_obj->f_span = l9;
            _a8_obj->f_id = l10;
            _a8_obj->f_label = l11;
            _a8_obj->f_form = l3;
            _a8_obj->f_body = l12;
            _a8_obj->f_is_comptime = l5;
            t0 = (void*) _a8_obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        vader_unreachable("unreachable return in vader_resolver$substitute_stmt");
    }
    if (l0.tag == 386u) {
        t0 = l0.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 392u) {
        t0 = l0.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_box_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_box_t vader_resolver_substitute_type_expr(vader_box_t l0, void* l1) {
    void* l2 = NULL;
    void* l5 = NULL;
    void* l8 = NULL;
    vader_box_t l3 = vader_box_null(), l7 = vader_box_null();
    vader_string_t l4 = 0;
    uint8_t l6;
    size_t l9, l10;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    int64_t t2;
    vader_box_t* gc_roots[4] = { &l0, &l3, &l7, &t1 };
    void** gc_raw_roots[5] = { &l1, &l2, &l5, &l8, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    if (l0.tag == 412u) {
        l2 = l0.payload.obj;
        l4 = ((vader_struct_toolchain_ast_IdentExpr_t*) l2)->f_name;
        l3 = vader_resolver_lookup_subst(l1, l4);
        if (l3.tag == 0u) {
            t0 = vader_resolver_clone_ident(l2);
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l2 = vader_resolver_new_subst();
        t1 = vader_resolver_substitute_type_expr(l3, l2);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 382u) {
        l2 = l0.payload.obj;
        l5 = ((vader_struct_toolchain_ast_BinaryExpr_t*) l2)->f_span;
        l6 = ((vader_struct_toolchain_ast_BinaryExpr_t*) l2)->f_op;
        l3 = vader_resolver_substitute_type_expr(((vader_struct_toolchain_ast_BinaryExpr_t*) l2)->f_left, l1);
        l7 = vader_resolver_substitute_type_expr(((vader_struct_toolchain_ast_BinaryExpr_t*) l2)->f_right, l1);
        l4 = ((vader_struct_toolchain_ast_BinaryExpr_t*) l2)->f_bind_as;
        vader_struct_toolchain_ast_BinaryExpr_t* _a0_obj = (vader_struct_toolchain_ast_BinaryExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_BinaryExpr_t));
        vader_obj_header_init(_a0_obj, 382u);
        _a0_obj->f_span = l5;
        _a0_obj->f_id = (size_t) (int64_t) INT64_C(0);
        _a0_obj->f_op = l6;
        _a0_obj->f_left = l3;
        _a0_obj->f_right = l7;
        _a0_obj->f_bind_as = l4;
        t0 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 409u) {
        l2 = l0.payload.obj;
        vader_array_t* _a1_arr = vader_array_new(109u, 0u, 13u, 1015u);
        l5 = (void*) _a1_arr;
        l8 = ((vader_struct_toolchain_ast_FnTypeExpr_t*) l2)->f_params;
        l9 = ((vader_array_t*) l8)->length;
        l10 = (size_t) (int64_t) INT64_C(0);
        {
            loop_71: {
                if ((l10 < l9)) {
                    vader_array_t* _a2_slotarr = ((vader_array_t*) l8);
                    if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                    if ((size_t) l10 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                    t1 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l10);
                    l3 = vader_resolver_substitute_type_expr(t1, l1);
                    vader_array_push((vader_array_t*) l5, l3);
                    t2 = (l10 + INT64_C(1));
                    l10 = (size_t) (int64_t) t2;
                    goto loop_71;
                } else {
                }
            }
        }
        l3 = ((vader_struct_toolchain_ast_FnTypeExpr_t*) l2)->f_return_type;
        l7 = vader_box_obj(0u, NULL);
        if (!(l3.tag == 0u)) {
            l7 = vader_resolver_substitute_type_expr(l3, l1);
        } else {
        }
        l2 = ((vader_struct_toolchain_ast_FnTypeExpr_t*) l2)->f_span;
        vader_array_t* _a3_arr = vader_array_new(6u, 0u, 12u, 159u);
        l8 = (void*) _a3_arr;
        vader_struct_toolchain_ast_FnTypeExpr_t* _a4_obj = (vader_struct_toolchain_ast_FnTypeExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_FnTypeExpr_t));
        vader_obj_header_init(_a4_obj, 409u);
        _a4_obj->f_span = l2;
        _a4_obj->f_id = (size_t) (int64_t) INT64_C(0);
        _a4_obj->f_params = l5;
        _a4_obj->f_params_mutable = l8;
        _a4_obj->f_return_type = l7;
        t0 = (void*) _a4_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 378u) {
        l2 = l0.payload.obj;
        l5 = ((vader_struct_toolchain_ast_ArrayTypeExpr_t*) l2)->f_span;
        l3 = vader_resolver_substitute_type_expr(((vader_struct_toolchain_ast_ArrayTypeExpr_t*) l2)->f_element, l1);
        vader_struct_toolchain_ast_ArrayTypeExpr_t* _a5_obj = (vader_struct_toolchain_ast_ArrayTypeExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_ArrayTypeExpr_t));
        vader_obj_header_init(_a5_obj, 378u);
        _a5_obj->f_span = l5;
        _a5_obj->f_id = (size_t) (int64_t) INT64_C(0);
        _a5_obj->f_element = l3;
        t0 = (void*) _a5_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 431u) {
        l2 = l0.payload.obj;
        l5 = ((vader_struct_toolchain_ast_MutableTypeExpr_t*) l2)->f_span;
        l3 = vader_resolver_substitute_type_expr(((vader_struct_toolchain_ast_MutableTypeExpr_t*) l2)->f_inner, l1);
        vader_struct_toolchain_ast_MutableTypeExpr_t* _a6_obj = (vader_struct_toolchain_ast_MutableTypeExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_MutableTypeExpr_t));
        vader_obj_header_init(_a6_obj, 431u);
        _a6_obj->f_span = l5;
        _a6_obj->f_id = (size_t) (int64_t) INT64_C(0);
        _a6_obj->f_inner = l3;
        t0 = (void*) _a6_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 444u) {
        l2 = l0.payload.obj;
        vader_array_t* _a7_arr = vader_array_new(109u, 0u, 13u, 1015u);
        l5 = (void*) _a7_arr;
        l8 = ((vader_struct_toolchain_ast_SeqLitExpr_t*) l2)->f_elements;
        l9 = ((vader_array_t*) l8)->length;
        l10 = (size_t) (int64_t) INT64_C(0);
        {
            loop_171: {
                if ((l10 < l9)) {
                    vader_array_t* _a8_slotarr = ((vader_array_t*) l8);
                    if (_a8_slotarr->buf != NULL && _a8_slotarr->buf->header.forward != NULL) { _a8_slotarr->buf = vader_array_buf_forward(_a8_slotarr->buf); }
                    if ((size_t) l10 >= _a8_slotarr->length) { vader_trap("array index out of bounds"); }
                    t1 = vader_array_ref_load_box(_a8_slotarr->buf, _a8_slotarr->offset + (size_t) l10);
                    l3 = vader_resolver_substitute_type_expr(t1, l1);
                    vader_array_push((vader_array_t*) l5, l3);
                    t2 = (l10 + INT64_C(1));
                    l10 = (size_t) (int64_t) t2;
                    goto loop_171;
                } else {
                }
            }
        }
        vader_struct_toolchain_ast_SeqLitExpr_t* _a9_obj = (vader_struct_toolchain_ast_SeqLitExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_SeqLitExpr_t));
        vader_obj_header_init(_a9_obj, 444u);
        _a9_obj->f_span = ((vader_struct_toolchain_ast_SeqLitExpr_t*) l2)->f_span;
        _a9_obj->f_id = (size_t) (int64_t) INT64_C(0);
        _a9_obj->f_elements = l5;
        _a9_obj->f_trailing_comma = false;
        t0 = (void*) _a9_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 411u) {
        l2 = l0.payload.obj;
        vader_array_t* _a10_arr = vader_array_new(109u, 0u, 13u, 1015u);
        l5 = (void*) _a10_arr;
        l8 = ((vader_struct_toolchain_ast_GenericInstExpr_t*) l2)->f_type_args;
        l9 = ((vader_array_t*) l8)->length;
        l10 = (size_t) (int64_t) INT64_C(0);
        {
            loop_216: {
                if ((l10 < l9)) {
                    vader_array_t* _a11_slotarr = ((vader_array_t*) l8);
                    if (_a11_slotarr->buf != NULL && _a11_slotarr->buf->header.forward != NULL) { _a11_slotarr->buf = vader_array_buf_forward(_a11_slotarr->buf); }
                    if ((size_t) l10 >= _a11_slotarr->length) { vader_trap("array index out of bounds"); }
                    t1 = vader_array_ref_load_box(_a11_slotarr->buf, _a11_slotarr->offset + (size_t) l10);
                    l3 = vader_resolver_substitute_type_expr(t1, l1);
                    vader_array_push((vader_array_t*) l5, l3);
                    t2 = (l10 + INT64_C(1));
                    l10 = (size_t) (int64_t) t2;
                    goto loop_216;
                } else {
                }
            }
        }
        l8 = ((vader_struct_toolchain_ast_GenericInstExpr_t*) l2)->f_span;
        l3 = ((vader_struct_toolchain_ast_GenericInstExpr_t*) l2)->f_callee;
        vader_struct_toolchain_ast_GenericInstExpr_t* _a12_obj = (vader_struct_toolchain_ast_GenericInstExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_GenericInstExpr_t));
        vader_obj_header_init(_a12_obj, 411u);
        _a12_obj->f_span = l8;
        _a12_obj->f_id = (size_t) (int64_t) INT64_C(0);
        _a12_obj->f_callee = l3;
        _a12_obj->f_type_args = l5;
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
    vader_obj_header_init(_a0_obj, 467u);
    _a0_obj->f_file = 0u;
    _a0_obj->f_offset = (size_t) (int64_t) INT64_C(0);
    _a0_obj->f_line = INT32_C(0);
    _a0_obj->f_column = l1;
    l2 = (void*) _a0_obj;
    vader_struct_toolchain_span_Span_t* _a1_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
    vader_obj_header_init(_a1_obj, 468u);
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
    vader_array_t* _a0_arr = vader_array_new(33u, 0u, 13u, 460u);
    l6 = (void*) _a0_arr;
    l7 = vader_resolver_substitute_params(((vader_struct_toolchain_ast_FnDecl_t*) l0)->f_params, l2);
    l8 = vader_resolver_substitute_opt_type(((vader_struct_toolchain_ast_FnDecl_t*) l0)->f_return_type, l2);
    l9 = ((vader_struct_toolchain_ast_FnDecl_t*) l0)->f_is_expression_bodied;
    vader_struct_toolchain_ast_FnDecl_t* _a1_obj = (vader_struct_toolchain_ast_FnDecl_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_FnDecl_t));
    vader_obj_header_init(_a1_obj, 407u);
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
    vader_array_t* _a0_arr = vader_array_new(33u, 0u, 13u, 460u);
    l8 = (void*) _a0_arr;
    l9 = vader_resolver_substitute_params_stamped(((vader_struct_toolchain_ast_FnDecl_t*) l0)->f_params, l1, l4);
    l10 = vader_resolver_substitute_opt_type(((vader_struct_toolchain_ast_FnDecl_t*) l0)->f_return_type, l1);
    l11 = ((vader_struct_toolchain_ast_FnDecl_t*) l0)->f_is_expression_bodied;
    vader_struct_toolchain_ast_FnDecl_t* _a1_obj = (vader_struct_toolchain_ast_FnDecl_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_FnDecl_t));
    vader_obj_header_init(_a1_obj, 407u);
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
                if (t0 != 2125u) {
                    t1 = (l3 + INT64_C(1));
                    l3 = (size_t) (int64_t) t1;
                    goto loop_7;
                }
                vader_array_t* _a1_arr = vader_array_new(11u, 0u, 1u, 167u);
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
                            if (l9.tag == 400u) {
                                t2 = l9.payload.obj;
                                t0 = ((vader_struct_toolchain_ast_DotVariantExpr_t*) t2)->f_variant;
                                t3 = std_string_to_lower(t0);
                                l10 = vader_target_parse_os(t3);
                                if (!(l10.tag == 0u)) {
                                    l11 = ((uint8_t) l10.payload.i);
                                    vader_array_push_u8((vader_array_t*) l5, (int32_t) (uint8_t) l11);
                                } else {
                                }
                            } else {
                            }
                            t1 = (l8 + INT64_C(1));
                            l8 = (size_t) (int64_t) t1;
                            goto loop_36;
                        } else {
                        }
                    }
                }
                t4 = ((vader_array_t*) ((vader_struct_toolchain_ast_Decorator_t*) l4)->f_args)->length;
                l12 = t4 == INT64_C(0);
                vader_struct_vader_resolver_TargetSelectors_t* _a3_obj = (vader_struct_vader_resolver_TargetSelectors_t*) vader_gc_alloc(sizeof(vader_struct_vader_resolver_TargetSelectors_t));
                vader_obj_header_init(_a3_obj, 871u);
                _a3_obj->f_os = l5;
                _a3_obj->f_is_bare = l12;
                t2 = (void*) _a3_obj;
                { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
            } else {
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
    l1 = std_io_read_file_string(l0);
    if (l1.tag == 161u) {
        t0 = l1.payload.s;
        t1 = vader_box_string(161u, t0);
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
            } else {
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
    void* l3 = NULL;
    void* l6 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    size_t l4, l5;
    vader_string_t l7 = 0;
    vader_string_t l11 = 0;
    vader_box_t l12 = vader_box_null();
    int64_t t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[2] = { &l1, &l12 };
    void** gc_raw_roots[8] = { &l0, &l2, &l3, &l6, &l8, &l9, &l10, &t1 };
    vader_string_t* gc_atom_roots[2] = { &l7, &l11 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    if (l1.tag == 417u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 407u) {
        l2 = l1.payload.obj;
        vader_resolver_walk_fn_decl(l0, l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 449u) {
        l2 = l1.payload.obj;
        vader_resolver_walk_struct_decl(l0, l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 401u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 456u) {
        l2 = l1.payload.obj;
        vader_resolver_walk_trait_decl(l0, l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 416u) {
        l2 = l1.payload.obj;
        vader_resolver_walk_impl_decl(l0, l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 459u) {
        l2 = l1.payload.obj;
        vader_resolver_push(((vader_struct_vader_resolver_ResolveState_t*) l0)->f_scope);
        l3 = ((vader_struct_toolchain_ast_TypeAliasDecl_t*) l2)->f_type_params;
        l4 = ((vader_array_t*) l3)->length;
        l5 = (size_t) (int64_t) INT64_C(0);
        {
            loop_69: {
                if ((l5 < l4)) {
                    vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
                    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                    if ((size_t) l5 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                    l6 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
                    l7 = ((vader_struct_toolchain_ast_TypeParam_t*) l6)->f_name;
                    l8 = ((vader_struct_toolchain_ast_TypeParam_t*) l6)->f_span;
                    l9 = vader_resolver_mint_local(l0, INT32_C(9), l7, l8);
                    l10 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_scope;
                    l11 = ((vader_struct_toolchain_ast_TypeParam_t*) l6)->f_name;
                    vader_resolver_bind(l10, l11, l9);
                    l12 = ((vader_struct_toolchain_ast_TypeParam_t*) l6)->f_bound;
                    vader_resolver_walk_opt_expr(l0, l12);
                    t0 = (l5 + INT64_C(1));
                    l5 = (size_t) (int64_t) t0;
                    goto loop_69;
                } else {
                }
            }
        }
        l12 = ((vader_struct_toolchain_ast_TypeAliasDecl_t*) l2)->f_aliased;
        vader_resolver_walk_opt_expr(l0, l12);
        vader_resolver_pop(((vader_struct_vader_resolver_ResolveState_t*) l0)->f_scope);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 391u) {
        l2 = l1.payload.obj;
        l12 = ((vader_struct_toolchain_ast_ConstDecl_t*) l2)->f_ty;
        vader_resolver_walk_opt_expr(l0, l12);
        l12 = ((vader_struct_toolchain_ast_ConstDecl_t*) l2)->f_value;
        vader_resolver_walk_expr(l0, l12);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 379u) {
        t1 = l1.payload.obj;
        l12 = ((vader_struct_toolchain_ast_AssertDecl_t*) t1)->f_condition;
        vader_resolver_walk_expr(l0, l12);
        { vader_gc_top = gc_frame.prev; return; }
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
                    l9 = concat_3(1061u, l8, 919u);
                    l10 = vader_diagnostics_resolver_error((uint8_t) (int32_t) INT32_C(9), l7, l9);
                    vader_array_push((vader_array_t*) l6, vader_ref_box(l10));
                } else {
                }
                t0 = ((vader_struct_toolchain_ast_Decorator_t*) l5)->f_name;
                if (t0 == 2125u) {
                    vader_resolver_check_target_selectors(l0, l5);
                    t2 = (l4 + INT64_C(1));
                    l4 = (size_t) (int64_t) t2;
                    goto loop_7;
                }
                l11 = ((vader_struct_toolchain_ast_Decorator_t*) l5)->f_args;
                l12 = ((vader_array_t*) l11)->length;
                l13 = (size_t) (int64_t) INT64_C(0);
                {
                    loop_64: {
                        if ((l13 < l12)) {
                            vader_array_t* _a1_slotarr = ((vader_array_t*) l11);
                            if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                            if ((size_t) l13 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                            l14 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l13);
                            vader_resolver_walk_expr(l0, l14);
                            t2 = (l13 + INT64_C(1));
                            l13 = (size_t) (int64_t) t2;
                            goto loop_64;
                        } else {
                        }
                    }
                }
                t2 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t2;
                goto loop_7;
            } else {
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
    if (l2.tag == 396u) {
        t0 = l2.payload.obj;
        l3 = ((vader_struct_toolchain_ast_DeferStmtBody_t*) t0)->f_stmt;
        vader_resolver_walk_stmt(l0, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 394u) {
        t0 = l2.payload.obj;
        l4 = ((vader_struct_toolchain_ast_DeferBlockBody_t*) t0)->f_block;
        vader_resolver_walk_block(l0, l4);
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_resolver_walk_expr(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l6 = NULL;
    vader_string_t l4 = 0;
    vader_box_t l5 = vader_box_null(), l10 = vader_box_null();
    uint64_t l7;
    size_t l8, l9;
    void* t0 = NULL;
    int64_t t1;
    vader_box_t* gc_roots[3] = { &l1, &l5, &l10 };
    void** gc_raw_roots[5] = { &l0, &l2, &l3, &l6, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    if (l1.tag == 412u) {
        l2 = l1.payload.obj;
        l3 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_scope;
        l4 = ((vader_struct_toolchain_ast_IdentExpr_t*) l2)->f_name;
        l5 = vader_resolver_lookup(l3, l4);
        if (l5.tag == 872u) {
            l3 = l5.payload.obj;
            l6 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_idents;
            l7 = toolchain_span_Span_Hash_hash(((vader_struct_toolchain_ast_IdentExpr_t*) l2)->f_span);
            std_collections_put__u64__Any(l6, l7, vader_ref_box(l3));
            vader_resolver_check_wildcard_ambiguity(l0, l2, l3);
            { vader_gc_top = gc_frame.prev; return; }
        }
        if (l5.tag == 0u) {
            l3 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_diags;
            l6 = ((vader_struct_toolchain_ast_IdentExpr_t*) l2)->f_span;
            l4 = ((vader_struct_toolchain_ast_IdentExpr_t*) l2)->f_name;
            l4 = concat_3(919u, l4, 919u);
            l2 = vader_diagnostics_resolver_error((uint8_t) (int32_t) INT32_C(5), l6, l4);
            vader_array_push((vader_array_t*) l3, vader_ref_box(l2));
            { vader_gc_top = gc_frame.prev; return; }
        }
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 388u) {
        l2 = l1.payload.obj;
        l5 = ((vader_struct_toolchain_ast_CallExpr_t*) l2)->f_callee;
        vader_resolver_walk_expr(l0, l5);
        l2 = ((vader_struct_toolchain_ast_CallExpr_t*) l2)->f_args;
        l8 = ((vader_array_t*) l2)->length;
        l9 = (size_t) (int64_t) INT64_C(0);
        {
            loop_80: {
                if ((l9 < l8)) {
                    vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
                    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                    if ((size_t) l9 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                    t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l9);
                    l5 = ((vader_struct_toolchain_ast_CallArg_t*) t0)->f_value;
                    vader_resolver_walk_expr(l0, l5);
                    t1 = (l9 + INT64_C(1));
                    l9 = (size_t) (int64_t) t1;
                    goto loop_80;
                } else {
                }
            }
        }
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 405u) {
        t0 = l1.payload.obj;
        l5 = ((vader_struct_toolchain_ast_FieldExpr_t*) t0)->f_target;
        vader_resolver_walk_expr(l0, l5);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 420u) {
        l2 = l1.payload.obj;
        l5 = ((vader_struct_toolchain_ast_IndexExpr_t*) l2)->f_target;
        vader_resolver_walk_expr(l0, l5);
        l5 = ((vader_struct_toolchain_ast_IndexExpr_t*) l2)->f_index;
        vader_resolver_walk_expr(l0, l5);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 461u) {
        t0 = l1.payload.obj;
        l5 = ((vader_struct_toolchain_ast_UnaryExpr_t*) t0)->f_operand;
        vader_resolver_walk_expr(l0, l5);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 382u) {
        l2 = l1.payload.obj;
        l5 = ((vader_struct_toolchain_ast_BinaryExpr_t*) l2)->f_left;
        vader_resolver_walk_expr(l0, l5);
        l5 = ((vader_struct_toolchain_ast_BinaryExpr_t*) l2)->f_right;
        vader_resolver_walk_expr(l0, l5);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 434u) {
        l2 = l1.payload.obj;
        l5 = ((vader_struct_toolchain_ast_NullCoalesceExpr_t*) l2)->f_left;
        vader_resolver_walk_expr(l0, l5);
        l5 = ((vader_struct_toolchain_ast_NullCoalesceExpr_t*) l2)->f_fallback;
        if ((l5.tag == 386u || l5.tag == 392u || l5.tag == 443u)) {
            l10 = l5;
            vader_resolver_walk_stmt(l0, l10);
            { vader_gc_top = gc_frame.prev; return; }
        }
        if ((l5.tag == 378u || l5.tag == 381u || l5.tag == 382u || l5.tag == 384u || l5.tag == 385u || l5.tag == 388u || l5.tag == 389u || l5.tag == 390u || l5.tag == 400u || l5.tag == 405u || l5.tag == 406u || l5.tag == 409u || l5.tag == 411u || l5.tag == 412u || l5.tag == 415u || l5.tag == 420u || l5.tag == 422u || l5.tag == 423u || l5.tag == 425u || l5.tag == 429u || l5.tag == 431u || l5.tag == 434u || l5.tag == 435u || l5.tag == 440u || l5.tag == 444u || l5.tag == 446u || l5.tag == 451u || l5.tag == 461u)) {
            vader_resolver_walk_expr(l0, l5);
            { vader_gc_top = gc_frame.prev; return; }
        }
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 415u) {
        l2 = l1.payload.obj;
        vader_resolver_walk_if(l0, l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 429u) {
        l2 = l1.payload.obj;
        vader_resolver_walk_match(l0, l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 384u) {
        l2 = l1.payload.obj;
        vader_resolver_walk_block(l0, l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 425u) {
        l2 = l1.payload.obj;
        vader_resolver_walk_lambda(l0, l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 451u) {
        l2 = l1.payload.obj;
        vader_resolver_walk_struct_lit(l0, l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 444u) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_toolchain_ast_SeqLitExpr_t*) t0)->f_elements;
        l8 = ((vader_array_t*) l2)->length;
        l9 = (size_t) (int64_t) INT64_C(0);
        {
            loop_263: {
                if ((l9 < l8)) {
                    vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
                    if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                    if ((size_t) l9 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                    l5 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l9);
                    vader_resolver_walk_expr(l0, l5);
                    t1 = (l9 + INT64_C(1));
                    l9 = (size_t) (int64_t) t1;
                    goto loop_263;
                } else {
                }
            }
        }
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 440u) {
        l2 = l1.payload.obj;
        l5 = ((vader_struct_toolchain_ast_RangeExpr_t*) l2)->f_lower;
        vader_resolver_walk_expr(l0, l5);
        l5 = ((vader_struct_toolchain_ast_RangeExpr_t*) l2)->f_upper;
        vader_resolver_walk_expr(l0, l5);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 381u) {
        t0 = l1.payload.obj;
        l5 = ((vader_struct_toolchain_ast_AwaitExpr_t*) t0)->f_inner;
        vader_resolver_walk_expr(l0, l5);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 389u) {
        l2 = l1.payload.obj;
        l5 = ((vader_struct_toolchain_ast_CastExpr_t*) l2)->f_value;
        vader_resolver_walk_expr(l0, l5);
        l5 = ((vader_struct_toolchain_ast_CastExpr_t*) l2)->f_target;
        vader_resolver_walk_expr(l0, l5);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 411u) {
        l2 = l1.payload.obj;
        l5 = ((vader_struct_toolchain_ast_GenericInstExpr_t*) l2)->f_callee;
        vader_resolver_walk_expr(l0, l5);
        l2 = ((vader_struct_toolchain_ast_GenericInstExpr_t*) l2)->f_type_args;
        l8 = ((vader_array_t*) l2)->length;
        l9 = (size_t) (int64_t) INT64_C(0);
        {
            loop_352: {
                if ((l9 < l8)) {
                    vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
                    if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                    if ((size_t) l9 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                    l5 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l9);
                    vader_resolver_walk_expr(l0, l5);
                    t1 = (l9 + INT64_C(1));
                    l9 = (size_t) (int64_t) t1;
                    goto loop_352;
                } else {
                }
            }
        }
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 423u) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) t0)->f_args;
        l8 = ((vader_array_t*) l2)->length;
        l9 = (size_t) (int64_t) INT64_C(0);
        {
            loop_387: {
                if ((l9 < l8)) {
                    vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
                    if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                    if ((size_t) l9 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                    l5 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l9);
                    vader_resolver_walk_expr(l0, l5);
                    t1 = (l9 + INT64_C(1));
                    l9 = (size_t) (int64_t) t1;
                    goto loop_387;
                } else {
                }
            }
        }
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 400u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 409u) {
        l2 = l1.payload.obj;
        l3 = ((vader_struct_toolchain_ast_FnTypeExpr_t*) l2)->f_params;
        l8 = ((vader_array_t*) l3)->length;
        l9 = (size_t) (int64_t) INT64_C(0);
        {
            loop_428: {
                if ((l9 < l8)) {
                    vader_array_t* _a4_slotarr = ((vader_array_t*) l3);
                    if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                    if ((size_t) l9 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                    l5 = vader_array_ref_load_box(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l9);
                    vader_resolver_walk_expr(l0, l5);
                    t1 = (l9 + INT64_C(1));
                    l9 = (size_t) (int64_t) t1;
                    goto loop_428;
                } else {
                }
            }
        }
        l5 = ((vader_struct_toolchain_ast_FnTypeExpr_t*) l2)->f_return_type;
        vader_resolver_walk_opt_expr(l0, l5);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 378u) {
        t0 = l1.payload.obj;
        l5 = ((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t0)->f_element;
        vader_resolver_walk_expr(l0, l5);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 431u) {
        t0 = l1.payload.obj;
        l5 = ((vader_struct_toolchain_ast_MutableTypeExpr_t*) t0)->f_inner;
        vader_resolver_walk_expr(l0, l5);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 422u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 406u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 385u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 435u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 390u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 446u) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_toolchain_ast_StringLitExpr_t*) t0)->f_parts;
        l8 = ((vader_array_t*) l2)->length;
        l9 = (size_t) (int64_t) INT64_C(0);
        {
            loop_517: {
                if ((l9 < l8)) {
                    vader_array_t* _a5_slotarr = ((vader_array_t*) l2);
                    if (_a5_slotarr->buf != NULL && _a5_slotarr->buf->header.forward != NULL) { _a5_slotarr->buf = vader_array_buf_forward(_a5_slotarr->buf); }
                    if ((size_t) l9 >= _a5_slotarr->length) { vader_trap("array index out of bounds"); }
                    l5 = vader_array_ref_load_box(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l9);
                    if (l5.tag == 447u) {
                        t0 = l5.payload.obj;
                        l10 = ((vader_struct_toolchain_ast_StringLitInterp_t*) t0)->f_expr;
                        vader_resolver_walk_expr(l0, l10);
                    } else {
                    }
                    t1 = (l9 + INT64_C(1));
                    l9 = (size_t) (int64_t) t1;
                    goto loop_517;
                } else {
                }
            }
        }
        { vader_gc_top = gc_frame.prev; return; }
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
                } else {
                }
                t0 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                goto loop_14;
            } else {
            }
        }
    }
    l2 = ((vader_struct_toolchain_ast_FnDecl_t*) l1)->f_params;
    l3 = ((vader_array_t*) l2)->length;
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_90: {
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
                goto loop_90;
            } else {
            }
        }
    }
    l13 = ((vader_struct_toolchain_ast_FnDecl_t*) l1)->f_return_type;
    vader_resolver_walk_opt_expr(l0, l13);
    l13 = ((vader_struct_toolchain_ast_FnDecl_t*) l1)->f_body;
    if (l13.tag == 0u) {
        vader_resolver_pop(((vader_struct_vader_resolver_ResolveState_t*) l0)->f_scope);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l13.tag == 384u) {
        l2 = l13.payload.obj;
        vader_resolver_walk_block(l0, l2);
        vader_resolver_pop(((vader_struct_vader_resolver_ResolveState_t*) l0)->f_scope);
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_resolver_walk_for(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l3 = vader_box_null(), l4 = vader_box_null(), l5 = vader_box_null(), l13 = vader_box_null();
    void* l6 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    void* l14 = NULL;
    int32_t l7;
    vader_string_t l8 = 0;
    uint64_t l12;
    void* t0 = NULL;
    vader_box_t* gc_roots[5] = { &l2, &l3, &l4, &l5, &l13 };
    void** gc_raw_roots[8] = { &l0, &l1, &l6, &l9, &l10, &l11, &l14, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l8 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 5u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_toolchain_ast_ForStmt_t*) l1)->f_form;
    if (l2.tag == 421u) {
        vader_resolver_push(((vader_struct_vader_resolver_ResolveState_t*) l0)->f_scope);
        l4 = ((vader_struct_toolchain_ast_ForStmt_t*) l1)->f_form;
        if (l4.tag == 419u) {
            t0 = l4.payload.obj;
            l5 = ((vader_struct_toolchain_ast_InFor_t*) t0)->f_loop_var;
            if (l5.tag == 433u) {
                l6 = l5.payload.obj;
                l7 = INT32_C(10);
                l8 = ((vader_struct_toolchain_ast_NamedVar_t*) l6)->f_name;
                l9 = ((vader_struct_toolchain_ast_NamedVar_t*) l6)->f_span;
                l10 = vader_resolver_bind_local_checked(l0, l7, l8, l9);
                l11 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_idents;
                l12 = toolchain_span_Span_Hash_hash(((vader_struct_toolchain_ast_NamedVar_t*) l6)->f_span);
                std_collections_put__u64__Any(l11, l12, vader_ref_box(l10));
                l14 = ((vader_struct_toolchain_ast_ForStmt_t*) l1)->f_body;
                vader_resolver_walk_block(l0, l14);
                vader_resolver_pop(((vader_struct_vader_resolver_ResolveState_t*) l0)->f_scope);
                { vader_gc_top = gc_frame.prev; return; }
            }
            if (l5.tag == 398u) {
                t0 = l5.payload.obj;
                l13 = ((vader_struct_toolchain_ast_DestructureVar_t*) t0)->f_pattern;
                vader_resolver_bind_let_binding(l0, l13);
                l14 = ((vader_struct_toolchain_ast_ForStmt_t*) l1)->f_body;
                vader_resolver_walk_block(l0, l14);
                vader_resolver_pop(((vader_struct_vader_resolver_ResolveState_t*) l0)->f_scope);
                { vader_gc_top = gc_frame.prev; return; }
            }
            if (l5.tag == 399u) {
                l14 = ((vader_struct_toolchain_ast_ForStmt_t*) l1)->f_body;
                vader_resolver_walk_block(l0, l14);
                vader_resolver_pop(((vader_struct_vader_resolver_ResolveState_t*) l0)->f_scope);
                { vader_gc_top = gc_frame.prev; return; }
            }
            { vader_gc_top = gc_frame.prev; return; }
        }
        l14 = ((vader_struct_toolchain_ast_ForStmt_t*) l1)->f_body;
        vader_resolver_walk_block(l0, l14);
        vader_resolver_pop(((vader_struct_vader_resolver_ResolveState_t*) l0)->f_scope);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 462u) {
        t0 = l2.payload.obj;
        l3 = ((vader_struct_toolchain_ast_WhileFor_t*) t0)->f_cond;
        vader_resolver_walk_expr(l0, l3);
        vader_resolver_push(((vader_struct_vader_resolver_ResolveState_t*) l0)->f_scope);
        l4 = ((vader_struct_toolchain_ast_ForStmt_t*) l1)->f_form;
        if (l4.tag == 419u) {
            t0 = l4.payload.obj;
            l5 = ((vader_struct_toolchain_ast_InFor_t*) t0)->f_loop_var;
            if (l5.tag == 433u) {
                l6 = l5.payload.obj;
                l7 = INT32_C(10);
                l8 = ((vader_struct_toolchain_ast_NamedVar_t*) l6)->f_name;
                l9 = ((vader_struct_toolchain_ast_NamedVar_t*) l6)->f_span;
                l10 = vader_resolver_bind_local_checked(l0, l7, l8, l9);
                l11 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_idents;
                l12 = toolchain_span_Span_Hash_hash(((vader_struct_toolchain_ast_NamedVar_t*) l6)->f_span);
                std_collections_put__u64__Any(l11, l12, vader_ref_box(l10));
                l14 = ((vader_struct_toolchain_ast_ForStmt_t*) l1)->f_body;
                vader_resolver_walk_block(l0, l14);
                vader_resolver_pop(((vader_struct_vader_resolver_ResolveState_t*) l0)->f_scope);
                { vader_gc_top = gc_frame.prev; return; }
            }
            if (l5.tag == 398u) {
                t0 = l5.payload.obj;
                l13 = ((vader_struct_toolchain_ast_DestructureVar_t*) t0)->f_pattern;
                vader_resolver_bind_let_binding(l0, l13);
                l14 = ((vader_struct_toolchain_ast_ForStmt_t*) l1)->f_body;
                vader_resolver_walk_block(l0, l14);
                vader_resolver_pop(((vader_struct_vader_resolver_ResolveState_t*) l0)->f_scope);
                { vader_gc_top = gc_frame.prev; return; }
            }
            if (l5.tag == 399u) {
                l14 = ((vader_struct_toolchain_ast_ForStmt_t*) l1)->f_body;
                vader_resolver_walk_block(l0, l14);
                vader_resolver_pop(((vader_struct_vader_resolver_ResolveState_t*) l0)->f_scope);
                { vader_gc_top = gc_frame.prev; return; }
            }
            { vader_gc_top = gc_frame.prev; return; }
        }
        l14 = ((vader_struct_toolchain_ast_ForStmt_t*) l1)->f_body;
        vader_resolver_walk_block(l0, l14);
        vader_resolver_pop(((vader_struct_vader_resolver_ResolveState_t*) l0)->f_scope);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 419u) {
        t0 = l2.payload.obj;
        l2 = ((vader_struct_toolchain_ast_InFor_t*) t0)->f_iter;
        vader_resolver_walk_expr(l0, l2);
        vader_resolver_push(((vader_struct_vader_resolver_ResolveState_t*) l0)->f_scope);
        l4 = ((vader_struct_toolchain_ast_ForStmt_t*) l1)->f_form;
        if (l4.tag == 419u) {
            t0 = l4.payload.obj;
            l5 = ((vader_struct_toolchain_ast_InFor_t*) t0)->f_loop_var;
            if (l5.tag == 433u) {
                l6 = l5.payload.obj;
                l7 = INT32_C(10);
                l8 = ((vader_struct_toolchain_ast_NamedVar_t*) l6)->f_name;
                l9 = ((vader_struct_toolchain_ast_NamedVar_t*) l6)->f_span;
                l10 = vader_resolver_bind_local_checked(l0, l7, l8, l9);
                l11 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_idents;
                l12 = toolchain_span_Span_Hash_hash(((vader_struct_toolchain_ast_NamedVar_t*) l6)->f_span);
                std_collections_put__u64__Any(l11, l12, vader_ref_box(l10));
                l14 = ((vader_struct_toolchain_ast_ForStmt_t*) l1)->f_body;
                vader_resolver_walk_block(l0, l14);
                vader_resolver_pop(((vader_struct_vader_resolver_ResolveState_t*) l0)->f_scope);
                { vader_gc_top = gc_frame.prev; return; }
            }
            if (l5.tag == 398u) {
                t0 = l5.payload.obj;
                l13 = ((vader_struct_toolchain_ast_DestructureVar_t*) t0)->f_pattern;
                vader_resolver_bind_let_binding(l0, l13);
                l14 = ((vader_struct_toolchain_ast_ForStmt_t*) l1)->f_body;
                vader_resolver_walk_block(l0, l14);
                vader_resolver_pop(((vader_struct_vader_resolver_ResolveState_t*) l0)->f_scope);
                { vader_gc_top = gc_frame.prev; return; }
            }
            if (l5.tag == 399u) {
                l14 = ((vader_struct_toolchain_ast_ForStmt_t*) l1)->f_body;
                vader_resolver_walk_block(l0, l14);
                vader_resolver_pop(((vader_struct_vader_resolver_ResolveState_t*) l0)->f_scope);
                { vader_gc_top = gc_frame.prev; return; }
            }
            { vader_gc_top = gc_frame.prev; return; }
        }
        l14 = ((vader_struct_toolchain_ast_ForStmt_t*) l1)->f_body;
        vader_resolver_walk_block(l0, l14);
        vader_resolver_pop(((vader_struct_vader_resolver_ResolveState_t*) l0)->f_scope);
        { vader_gc_top = gc_frame.prev; return; }
    }
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
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 414u) {
        t0 = l2.payload.obj;
        l3 = ((vader_struct_toolchain_ast_IfElseIf_t*) t0)->f_branch;
        vader_resolver_walk_if(l0, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 413u) {
        t0 = l2.payload.obj;
        l3 = ((vader_struct_toolchain_ast_IfElseBlock_t*) t0)->f_block;
        vader_resolver_walk_block(l0, l3);
        { vader_gc_top = gc_frame.prev; return; }
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
                } else {
                }
                t0 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                goto loop_14;
            } else {
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
        loop_91: {
            if ((l4 < l3)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l4 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                l11 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
                vader_resolver_walk_expr(l0, l11);
                t0 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                goto loop_91;
            } else {
            }
        }
    }
    l2 = ((vader_struct_toolchain_ast_ImplDecl_t*) l1)->f_members;
    l3 = ((vader_array_t*) l2)->length;
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_119: {
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
                    goto loop_119;
                }
                vader_resolver_walk_fn_decl(l0, l5);
                t0 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                goto loop_119;
            } else {
            }
        }
    }
    vader_resolver_pop(((vader_struct_vader_resolver_ResolveState_t*) l0)->f_scope);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_resolver_walk_import_cycle(vader_string_t l0, void* l1, void* l2, void* l3, void* l4) {
    vader_box_t l5 = vader_box_null(), l13 = vader_box_null();
    void* l6 = NULL;
    void* l7 = NULL;
    void* l11 = NULL;
    void* l14 = NULL;
    void* l17 = NULL;
    size_t l8, l9;
    vader_string_t l10 = 0;
    vader_string_t l12 = 0;
    vader_string_t l15 = 0;
    vader_string_t l16 = 0;
    vader_box_t t0 = vader_box_null();
    vader_string_t t1 = 0;
    int32_t t2;
    int64_t t3;
    vader_box_t* gc_roots[3] = { &l5, &l13, &t0 };
    void** gc_raw_roots[9] = { &l1, &l2, &l3, &l4, &l6, &l7, &l11, &l14, &l17 };
    vader_string_t* gc_atom_roots[6] = { &l0, &l10, &l12, &l15, &l16, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 9u, gc_roots, gc_raw_roots, 0u, NULL, 6u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    std_collections_put__string__i32(l3, l0, INT32_C(1));
    l5 = std_collections_get__string__Any(l1, l0);
    if (l5.tag == 859u) {
        l6 = l5.payload.obj;
        l7 = ((vader_struct_vader_resolver_CollectedModule_t*) ((vader_struct_vader_resolver_LoadedModule_t*) l6)->f_collected)->f_import_paths;
        l8 = ((vader_array_t*) l7)->length;
        l9 = (size_t) (int64_t) INT64_C(0);
        {
            loop_21: {
                if ((l9 < l8)) {
                    vader_array_t* _a0_slotarr = ((vader_array_t*) l7);
                    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                    if ((size_t) l9 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                    t0 = vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l9];
                    l10 = t0.payload.s;
                    l5 = std_collections_get__string__Any(l2, l10);
                    if (l5.tag == 853u) {
                        l11 = l5.payload.obj;
                        l12 = ((vader_struct_vader_resolver_DiscoveredModule_t*) l11)->f_folder;
                        l13 = std_collections_get__string__i32(l3, l12);
                        if (l13.tag == 0u) {
                            t1 = ((vader_struct_vader_resolver_DiscoveredModule_t*) l11)->f_folder;
                            vader_resolver_walk_import_cycle(t1, l1, l2, l3, l4);
                        } else {
                            t2 = ((int32_t) l13.payload.i);
                            if (t2 == INT32_C(1)) {
                                t1 = ((vader_struct_vader_resolver_Module_t*) ((vader_struct_vader_resolver_LoadedModule_t*) l6)->f_module)->f_display_path;
                                l14 = vader_resolver_zero_span(t1);
                                l15 = ((vader_struct_vader_resolver_Module_t*) ((vader_struct_vader_resolver_LoadedModule_t*) l6)->f_module)->f_display_path;
                                l16 = concat_5(919u, l15, 954u, l10, 1041u);
                                l17 = vader_diagnostics_resolver_error((uint8_t) (int32_t) INT32_C(4), l14, l16);
                                vader_array_push((vader_array_t*) l4, vader_ref_box(l17));
                            } else {
                            }
                        }
                    } else {
                    }
                    t3 = (l9 + INT64_C(1));
                    l9 = (size_t) (int64_t) t3;
                    goto loop_21;
                } else {
                }
            }
        }
    } else {
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
            } else {
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
    vader_box_t l2 = vader_box_null(), l7 = vader_box_null(), l8 = vader_box_null();
    void* l3 = NULL;
    void* l6 = NULL;
    size_t l4, l5;
    int64_t t0;
    vader_box_t* gc_roots[3] = { &l2, &l7, &l8 };
    void** gc_raw_roots[4] = { &l0, &l1, &l3, &l6 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_toolchain_ast_MatchExpr_t*) l1)->f_scrutinee;
    vader_resolver_walk_expr(l0, l2);
    l3 = ((vader_struct_toolchain_ast_MatchExpr_t*) l1)->f_arms;
    l4 = ((vader_array_t*) l3)->length;
    l5 = (size_t) (int64_t) INT64_C(0);
    {
        loop_12: {
            if ((l5 < l4)) {
                vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
                if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                if ((size_t) l5 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                l6 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
                vader_resolver_push(((vader_struct_vader_resolver_ResolveState_t*) l0)->f_scope);
                l2 = ((vader_struct_toolchain_ast_MatchArm_t*) l6)->f_pattern;
                vader_resolver_bind_pattern(l0, l2);
                l7 = ((vader_struct_toolchain_ast_MatchArm_t*) l6)->f_guard;
                vader_resolver_walk_opt_expr(l0, l7);
                l8 = ((vader_struct_toolchain_ast_MatchArm_t*) l6)->f_body;
                vader_resolver_walk_expr(l0, l8);
                vader_resolver_pop(((vader_struct_vader_resolver_ResolveState_t*) l0)->f_scope);
                t0 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t0;
                goto loop_12;
            } else {
            }
        }
    }
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
    } else {
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_resolver_walk_stmt(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    vader_box_t l3 = vader_box_null();
    bool t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[2] = { &l1, &l3 };
    void** gc_raw_roots[3] = { &l0, &l2, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l1.tag == 426u) {
        l2 = l1.payload.obj;
        l3 = ((vader_struct_toolchain_ast_LetStmt_t*) l2)->f_ty;
        vader_resolver_walk_opt_expr(l0, l3);
        l3 = ((vader_struct_toolchain_ast_LetStmt_t*) l2)->f_value;
        vader_resolver_walk_expr(l0, l3);
        l3 = ((vader_struct_toolchain_ast_LetStmt_t*) l2)->f_binding;
        vader_resolver_bind_let_binding(l0, l3);
        t0 = ((vader_struct_toolchain_ast_LetStmt_t*) l2)->f_mutable;
        if (!(t0)) {
            l3 = ((vader_struct_toolchain_ast_LetStmt_t*) l2)->f_binding;
            vader_resolver_mark_binding_immutable(l0, l3);
        } else {
        }
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 380u) {
        l2 = l1.payload.obj;
        l3 = ((vader_struct_toolchain_ast_AssignStmt_t*) l2)->f_target;
        vader_resolver_walk_expr(l0, l3);
        l3 = ((vader_struct_toolchain_ast_AssignStmt_t*) l2)->f_value;
        vader_resolver_walk_expr(l0, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 404u) {
        t1 = l1.payload.obj;
        l3 = ((vader_struct_toolchain_ast_ExprStmt_t*) t1)->f_expr;
        vader_resolver_walk_expr(l0, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 443u) {
        t1 = l1.payload.obj;
        l3 = ((vader_struct_toolchain_ast_ReturnStmt_t*) t1)->f_value;
        vader_resolver_walk_opt_expr(l0, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 466u) {
        t1 = l1.payload.obj;
        l3 = ((vader_struct_toolchain_ast_YieldStmt_t*) t1)->f_value;
        vader_resolver_walk_expr(l0, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 410u) {
        l2 = l1.payload.obj;
        vader_resolver_walk_for(l0, l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 386u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 392u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 395u) {
        l2 = l1.payload.obj;
        vader_resolver_walk_defer(l0, l2);
        { vader_gc_top = gc_frame.prev; return; }
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
                } else {
                }
                t0 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                goto loop_14;
            } else {
            }
        }
    }
    l2 = ((vader_struct_toolchain_ast_StructDecl_t*) l1)->f_fields;
    l3 = ((vader_array_t*) l2)->length;
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_81: {
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
                goto loop_81;
            } else {
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
    size_t l4, l5, l8;
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
                if (l2.tag == 452u) {
                    t0 = l2.payload.obj;
                    l6 = ((vader_struct_toolchain_ast_StructLitField_t*) t0)->f_value;
                    vader_resolver_walk_expr(l0, l6);
                    l8 = (size_t) (int64_t) INT64_C(1);
                    t1 = (l5 + l8);
                    l5 = (size_t) (int64_t) t1;
                    goto loop_12;
                }
                if (l2.tag == 453u) {
                    t0 = l2.payload.obj;
                    l7 = ((vader_struct_toolchain_ast_StructLitSpread_t*) t0)->f_expr;
                    vader_resolver_walk_expr(l0, l7);
                    l8 = (size_t) (int64_t) INT64_C(1);
                    t1 = (l5 + l8);
                    l5 = (size_t) (int64_t) t1;
                    goto loop_12;
                }
                { vader_gc_top = gc_frame.prev; return; }
            } else {
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
                } else {
                }
                t0 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                goto loop_14;
            } else {
            }
        }
    }
    l11 = ((vader_struct_toolchain_ast_TraitDecl_t*) l1)->f_requires;
    vader_resolver_walk_opt_expr(l0, l11);
    l2 = ((vader_struct_toolchain_ast_TraitDecl_t*) l1)->f_members;
    l3 = ((vader_array_t*) l2)->length;
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_86: {
            if ((l4 < l3)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l4 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                l5 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
                vader_resolver_walk_fn_decl(l0, l5);
                t0 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                goto loop_86;
            } else {
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
    vader_struct___Tuple_1124_t _a7_storage = {0};
    void* gc_stack_objs[1] = { (void*) &_a7_storage };
    vader_string_t* gc_atom_roots[8] = { &l9, &l17, &l22, &l23, &l24, &l26, &l32, &t4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 17u, gc_roots, gc_raw_roots, 1u, gc_stack_objs, 8u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 161u);
    l4 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(15u, 0u, 0u, 171u);
    l5 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 164u);
    l6 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__string__Any___t* _a3_obj = (vader_struct_std_collections_MutableMap__string__Any___t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__Any___t));
    vader_obj_header_init(_a3_obj, 311u);
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
                            vader_struct___Tuple_1124_t* _a8_obj = &_a7_storage;
                            vader_obj_header_init(_a8_obj, 192u);
                            _a8_obj->f__0 = l17;
                            _a8_obj->f__1 = l18;
                            t2 = (void*) _a8_obj;
                            l19 = ((vader_struct___Tuple_1124_t*) t2)->f__1;
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
                                vader_array_t* _a9_arr = vader_array_new(8u, 1u, 0u, 161u);
                                vader_array_box_slots(_a9_arr->buf)[_a9_arr->offset + 0u] = vader_box_string(161u, l9);
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
                                            } else {
                                            }
                                            t1 = (l31 + INT64_C(1));
                                            l31 = (size_t) (int64_t) t1;
                                            goto loop_162;
                                        } else {
                                        }
                                    }
                                }
                                if (!(l28)) {
                                    t2 = l25.payload.obj;
                                    vader_array_push((vader_array_t*) t2, vader_box_string(161u, l9));
                                    l32 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l19)->f_name;
                                    l33 = l25.payload.obj;
                                    std_collections_put__string__Any(l4, l32, vader_ref_box(l33));
                                } else {
                                }
                            }
                            goto loop_63;
                        }
                    }
                }
                t1 = (l8 + INT64_C(1));
                l8 = (size_t) (int64_t) t1;
                goto loop_21;
            } else {
            }
        }
    }
    vader_array_t* _a11_arr = vader_array_new(8u, 0u, 0u, 161u);
    l5 = (void*) _a11_arr;
    vader_array_t* _a12_arr = vader_array_new(15u, 0u, 0u, 171u);
    l6 = (void*) _a12_arr;
    vader_array_t* _a13_arr = vader_array_new(9u, 0u, 7u, 164u);
    l12 = (void*) _a13_arr;
    vader_struct_std_collections_MutableMap__string__Any___t* _a14_obj = (vader_struct_std_collections_MutableMap__string__Any___t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__Any___t));
    vader_obj_header_init(_a14_obj, 311u);
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
        loop_244: {
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
                vader_struct___Tuple_1128_t* _a17_obj = (vader_struct___Tuple_1128_t*) vader_gc_alloc(sizeof(vader_struct___Tuple_1128_t));
                vader_obj_header_init(_a17_obj, 194u);
                _a17_obj->f__0 = l9;
                _a17_obj->f__1 = l4;
                l13 = (void*) _a17_obj;
                l17 = ((vader_struct___Tuple_1128_t*) l13)->f__0;
                l14 = ((vader_struct___Tuple_1128_t*) l13)->f__1;
                t1 = (l8 + INT64_C(1));
                l8 = (size_t) (int64_t) t1;
                t5 = ((vader_array_t*) l14)->length;
                if ((t5 >= INT64_C(2))) {
                    std_collections_put__string__Any(l5, l17, vader_ref_box(l14));
                } else {
                }
                goto loop_244;
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
    vader_struct___Tuple_1126_t _a6_storage = {0};
    void* gc_stack_objs[1] = { (void*) &_a6_storage };
    vader_string_t* gc_atom_roots[3] = { &l8, &l10, &l11 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 8u, gc_roots, gc_raw_roots, 1u, gc_stack_objs, 3u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l1 = vader_resolver_new_import_target_table();
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 161u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(8u, 0u, 0u, 161u);
    l3 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 164u);
    l4 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__string__string_t* _a3_obj = (vader_struct_std_collections_MutableMap__string__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__string_t));
    vader_obj_header_init(_a3_obj, 352u);
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
                vader_struct___Tuple_1126_t* _a7_obj = &_a6_storage;
                vader_obj_header_init(_a7_obj, 193u);
                _a7_obj->f__0 = l8;
                _a7_obj->f__1 = l3;
                t1 = (void*) _a7_obj;
                l9 = ((vader_struct___Tuple_1126_t*) t1)->f__1;
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
                vader_struct___Tuple_1126_t* _a10_obj = (vader_struct___Tuple_1126_t*) vader_gc_alloc(sizeof(vader_struct___Tuple_1126_t));
                vader_obj_header_init(_a10_obj, 193u);
                _a10_obj->f__0 = l8;
                _a10_obj->f__1 = l3;
                t1 = (void*) _a10_obj;
                l9 = ((vader_struct___Tuple_1126_t*) t1)->f__1;
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
    void* l30 = NULL;
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
    vader_string_t l31 = 0;
    vader_string_t l34 = 0;
    vader_box_t l14 = vader_box_null(), l17 = vader_box_null(), l18 = vader_box_null(), l22 = vader_box_null();
    int64_t t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[4] = { &l14, &l17, &l18, &l22 };
    void** gc_raw_roots[21] = { &l0, &l1, &l2, &l3, &l4, &l5, &l6, &l10, &l12, &l15, &l19, &l23, &l24, &l27, &l28, &l29, &l30, &l32, &l33, &l35, &t1 };
    vader_string_t* gc_atom_roots[8] = { &l13, &l16, &l20, &l21, &l25, &l26, &l31, &l34 };
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
            } else {
                vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
                if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                if ((size_t) l8 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                l9 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l8];
                vader_array_t* _a1_slotarr = ((vader_array_t*) l6);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l8 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                l4 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l8);
                vader_struct___Tuple_1131_t* _a2_obj = (vader_struct___Tuple_1131_t*) vader_gc_alloc(sizeof(vader_struct___Tuple_1131_t));
                vader_obj_header_init(_a2_obj, 196u);
                _a2_obj->f__0 = l9;
                _a2_obj->f__1 = l4;
                l10 = (void*) _a2_obj;
                l11 = ((vader_struct___Tuple_1131_t*) l10)->f__0;
                l12 = ((vader_struct___Tuple_1131_t*) l10)->f__1;
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
                    goto loop_13;
                }
                if (l18.tag == 161u) {
                    l21 = l18.payload.s;
                    t1 = l17.payload.obj;
                    l22 = std_collections_get__string__Any(((vader_struct_vader_resolver_CollectedModule_t*) ((vader_struct_vader_resolver_LoadedModule_t*) t1)->f_collected)->f_symbols, l21);
                    if (l22.tag == 0u) {
                        std_collections_put__i32__bool(((vader_struct_vader_resolver_ImportTargetTable_t*) l3)->f_missing, l11, true);
                        l23 = ((vader_struct_vader_resolver_LoadedProject_t*) l2)->f_diags;
                        l24 = ((vader_struct_vader_resolver_ImportInfo_t*) l12)->f_binding_span;
                        l25 = ((vader_struct_vader_resolver_ImportInfo_t*) l12)->f_path;
                        l26 = concat_5(919u, l21, 946u, l25, 919u);
                        l27 = vader_diagnostics_resolver_error((uint8_t) (int32_t) INT32_C(2), l24, l26);
                        vader_array_push((vader_array_t*) l23, vader_ref_box(l27));
                        goto loop_13;
                    }
                    if (l22.tag == 872u) {
                        l28 = l22.payload.obj;
                        if (((vader_struct_vader_resolver_symbol_Symbol_t*) l28)->f_visibility == INT32_C(1)) {
                            std_collections_put__i32__bool(((vader_struct_vader_resolver_ImportTargetTable_t*) l3)->f_missing, l11, true);
                            l29 = ((vader_struct_vader_resolver_LoadedProject_t*) l2)->f_diags;
                            l30 = ((vader_struct_vader_resolver_ImportInfo_t*) l12)->f_binding_span;
                            l31 = concat_3(919u, l21, 919u);
                            l32 = vader_diagnostics_resolver_error((uint8_t) (int32_t) INT32_C(7), l30, l31);
                            vader_array_push((vader_array_t*) l29, vader_ref_box(l32));
                        } else {
                            l33 = ((vader_struct_vader_resolver_ImportTargetTable_t*) l3)->f_symbol_targets;
                            l34 = l14.payload.s;
                            vader_struct_vader_resolver_SymbolTarget_t* _a3_obj = (vader_struct_vader_resolver_SymbolTarget_t*) vader_gc_alloc(sizeof(vader_struct_vader_resolver_SymbolTarget_t));
                            vader_obj_header_init(_a3_obj, 870u);
                            _a3_obj->f_symbol = l28;
                            _a3_obj->f_module_id = l34;
                            l35 = (void*) _a3_obj;
                            std_collections_put__i32__Any(l33, l11, vader_ref_box(l35));
                        }
                        goto loop_13;
                    }
                    { vader_gc_top = gc_frame.prev; return; }
                }
                { vader_gc_top = gc_frame.prev; return; }
            }
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
    vader_obj_header_init(_a0_obj, 467u);
    _a0_obj->f_file = l0;
    _a0_obj->f_offset = (size_t) (int64_t) INT64_C(0);
    _a0_obj->f_line = INT32_C(1);
    _a0_obj->f_column = INT32_C(1);
    l1 = (void*) _a0_obj;
    vader_struct_toolchain_span_Position_t* _a1_obj = (vader_struct_toolchain_span_Position_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Position_t));
    vader_obj_header_init(_a1_obj, 467u);
    _a1_obj->f_file = l0;
    _a1_obj->f_offset = (size_t) (int64_t) INT64_C(0);
    _a1_obj->f_line = INT32_C(1);
    _a1_obj->f_column = INT32_C(1);
    l2 = (void*) _a1_obj;
    vader_struct_toolchain_span_Span_t* _a2_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
    vader_obj_header_init(_a2_obj, 468u);
    _a2_obj->f_start = l1;
    _a2_obj->f_end = l2;
    t0 = (void*) _a2_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

