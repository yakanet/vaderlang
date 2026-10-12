#include "bootstrap.split.h"

static void vader_resolver_add_fn(void* l0, void* l1, vader_string_t l2, vader_string_t l3, void* l4, void* l5);
static void vader_resolver_add_named(void* l0, uint8_t l1, vader_string_t l2, void* l3, uint8_t l4, vader_string_t l5, vader_string_t l6, void* l7, void* l8);
static bool vader_resolver_any_has_body(void* l0);
static void vader_resolver_auto_bind_for_type_params(void* l0, vader_box_t l1);
static void vader_resolver_bind(void* l0, vader_string_t l1, void* l2);
static void vader_resolver_bind_1(void* l0, vader_string_t l1, vader_box_t l2);
static void vader_resolver_bind_cond_is_as(void* l0, vader_box_t l1, bool l2);
static void vader_resolver_bind_import(void* l0, vader_string_t l1, void* l2, vader_string_t l3, vader_box_t l4, vader_string_t l5, void* l6, void* l7);
static void vader_resolver_bind_let_binding(void* l0, vader_box_t l1, void* l2);
static void* vader_resolver_bind_local_checked(void* l0, uint8_t l1, vader_string_t l2, void* l3);
static void vader_resolver_bind_pattern(void* l0, vader_box_t l1);
static void* vader_resolver_bind_type_param(void* l0, void* l1);
static void* vader_resolver_binding_clashes(void* l0, void* l1);
static void* vader_resolver_binding_span(vader_box_t l0);
static bool vader_resolver_body_survives(void* l0, void* l1);
static void* vader_resolver_build_subst(void* l0, void* l1);
static void* vader_resolver_builtin_type_names(void);
static void vader_resolver_check_groups(void* l0, void* l1);
static void vader_resolver_check_import_form_conflict(void* l0, void* l1);
static void vader_resolver_check_orphan_rule(void* l0, vader_string_t l1, void* l2, void* l3, void* l4, void* l5, void* l6);
static void vader_resolver_check_selectors(void* l0, void* l1);
static void vader_resolver_check_signature(void* l0, void* l1, void* l2);
static void vader_resolver_check_target_selectors(void* l0, void* l1);
static void vader_resolver_check_wildcard_ambiguity(void* l0, vader_string_t l1, void* l2, void* l3);
static vader_box_t vader_resolver_checked_bound(void* l0, void* l1, vader_box_t l2);
static vader_box_t vader_resolver_clone_assign_value(void* l0, vader_box_t l1, void* l2);
static void* vader_resolver_clone_ident(void* l0);
static vader_box_t vader_resolver_clone_let_binding(vader_box_t l0);
static void vader_resolver_collect_decl(void* l0, vader_box_t l1, vader_string_t l2, vader_string_t l3, void* l4, void* l5, void* l6, void* l7);
static void* vader_resolver_collect_files(void* l0, vader_string_t l1, vader_string_t l2, void* l3, void* l4, void* l5, void* l6);
static void vader_resolver_collect_import(void* l0, void* l1, vader_string_t l2, vader_string_t l3, void* l4, void* l5, void* l6, void* l7);
static void* vader_resolver_collect_module(void* l0, vader_string_t l1, vader_string_t l2, void* l3, void* l4, void* l5, void* l6);
static void* vader_resolver_collect_module_no_index(void* l0, vader_string_t l1, void* l2);
static size_t vader_resolver_count_sam_synthetics(void* l0);
static void* vader_resolver_declare_type_param(void* l0, void* l1);
static bool vader_resolver_declared_outside_lambda(void* l0, vader_string_t l1);
static void vader_resolver_detect_import_cycles(void* l0, void* l1, void* l2);
static vader_box_t vader_resolver_diagnose_import_path(vader_string_t l0, void* l1, vader_string_t l2, void* l3, void* l4, void* l5);
static vader_string_t vader_resolver_dir_of(vader_string_t l0);
static void* vader_resolver_discarded_bodies(void* l0, vader_box_t l1);
static vader_box_t vader_resolver_displayable_impl(void* l0, void* l1, vader_string_t l2);
static void vader_resolver_drain_load_queue(void* l0, void* l1, void* l2, void* l3, void* l4, void* l5, void* l6, void* l7, vader_box_t l8);
static void* vader_resolver_enter_file(void* l0, void* l1);
static vader_string_t vader_resolver_entry_folder_of(vader_string_t l0);
static vader_box_t vader_resolver_find_manifest_root(vader_string_t l0);
static vader_string_t vader_resolver_for_type_display_name(vader_box_t l0);
static vader_box_t vader_resolver_for_type_owner_sym(vader_box_t l0, void* l1, void* l2);
static int32_t vader_resolver_frame_count(void* l0);
static vader_string_t vader_resolver_generated_root_for(vader_box_t l0);
static void* vader_resolver_graft_body(void* l0, void* l1);
static bool vader_resolver_has_module(void* l0, vader_string_t l1);
static bool vader_resolver_has_reassignment(void* l0, void* l1);
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
static vader_box_t vader_resolver_lookup_trait_sym(void* l0, void* l1, void* l2, void* l3);
static void* vader_resolver_make_builtin_scope(void* l0);
static void vader_resolver_mark_param_borrow(void* l0, void* l1, void* l2);
static bool vader_resolver_matches_target(void* l0, void* l1);
static void vader_resolver_merge_collected(void* l0, void* l1, void* l2);
static void* vader_resolver_mint_local(void* l0, uint8_t l1, vader_string_t l2, void* l3);
static vader_box_t vader_resolver_misplaced_module_at(vader_string_t l0, void* l1);
static bool vader_resolver_names_equal(vader_box_t l0, vader_box_t l1);
static void* vader_resolver_new_import_target_table(void);
static void* vader_resolver_new_scope(void* l0);
static void* vader_resolver_new_subst(void);
static void* vader_resolver_next_clone_span(void* l0);
static void vader_resolver_note_rebind(void* l0, vader_box_t l1);
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
static void* vader_resolver_rebind_free_locals(void* l0);
static void vader_resolver_report_uncovered(void* l0, void* l1, void* l2, void* l3, void* l4);
static void vader_resolver_report_unreassigned_mutables(void* l0);
static vader_box_t vader_resolver_resolve_decl(vader_box_t l0, void* l1, void* l2, void* l3);
static vader_box_t vader_resolver_resolve_lazy(vader_string_t l0, void* l1, void* l2, void* l3);
static void* vader_resolver_resolve_module_programs(void* l0, void* l1, vader_string_t l2, void* l3);
static vader_box_t vader_resolver_rooted_candidate(void* l0, vader_string_t l1);
static vader_box_t vader_resolver_scan_folder(vader_string_t l0, void* l1);
static void* vader_resolver_search_roots(vader_string_t l0, void* l1, void* l2);
static vader_box_t vader_resolver_seed_entry(vader_string_t l0, void* l1);
static void vader_resolver_seed_wildcard_exports(void* l0, void* l1, void* l2, void* l3);
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
static void* vader_resolver_swap_root(void* l0, void* l1);
static void* vader_resolver_synth_clone_span(void* l0);
static void* vader_resolver_synth_signature(void* l0, void* l1, void* l2, void* l3);
static void* vader_resolver_synth_with_body(void* l0, void* l1, void* l2, void* l3, void* l4);
static vader_box_t vader_resolver_target_selectors(void* l0);
static vader_box_t vader_resolver_try_read(vader_string_t l0);
static vader_box_t vader_resolver_union_in_bound(vader_box_t l0);
static void vader_resolver_walk_block(void* l0, void* l1);
static void vader_resolver_walk_body(void* l0, void* l1);
static void vader_resolver_walk_decl(void* l0, vader_box_t l1);
static void vader_resolver_walk_decorators(void* l0, void* l1);
static void vader_resolver_walk_defer(void* l0, void* l1);
static void vader_resolver_walk_enum_decl(void* l0, void* l1);
static void vader_resolver_walk_expr(void* l0, vader_box_t l1);
static void vader_resolver_walk_fn_decl(void* l0, void* l1);
static void vader_resolver_walk_for(void* l0, void* l1);
static void vader_resolver_walk_if(void* l0, void* l1);
static void vader_resolver_walk_impl_decl(void* l0, void* l1);
static void vader_resolver_walk_import_cycle(vader_string_t l0, void* l1, void* l2, void* l3, void* l4);
static void vader_resolver_walk_lambda(void* l0, void* l1);
static void vader_resolver_walk_let(void* l0, void* l1);
static void vader_resolver_walk_match(void* l0, void* l1);
static void vader_resolver_walk_opt_expr(void* l0, vader_box_t l1);
static void vader_resolver_walk_stmt(void* l0, vader_box_t l1);
static void vader_resolver_walk_struct_decl(void* l0, void* l1);
static void vader_resolver_walk_struct_lit(void* l0, void* l1);
static void vader_resolver_walk_struct_lit_items(void* l0, void* l1);
static void vader_resolver_walk_trait_decl(void* l0, void* l1);
static void* vader_resolver_wildcard_ambiguities(void* l0, void* l1, void* l2, void* l3);
static bool vader_resolver_wildcard_exposable(uint8_t l0);
static bool vader_resolver_wildcard_exposes(void* l0, vader_box_t l1);
static void vader_resolver_wire_module(void* l0, void* l1, void* l2, void* l3);
static void* vader_resolver_with_displayable_impls(void* l0);
static void* vader_resolver_zero_span(vader_string_t l0);

static void vader_resolver_add_fn(void* l0, void* l1, vader_string_t l2, vader_string_t l3, void* l4, void* l5) {
    uint8_t l6;
    void* l7 = NULL;
    void* l10 = NULL;
    void* l12 = NULL;
    vader_string_t l8 = 0;
    vader_box_t l9 = vader_box_null(), l11 = vader_box_null();
    vader_string_t t0 = 0;
    void* t1 = NULL;
    vader_box_t* gc_roots[2] = { &l9, &l11 };
    void** gc_raw_roots[8] = { &l0, &l1, &l4, &l5, &l7, &l10, &l12, &t1 };
    vader_string_t* gc_atom_roots[4] = { &l2, &l3, &l8, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l6 = ((vader_struct_toolchain_ast_FnDecl_t*) l1)->f_visibility;
    t0 = ((vader_struct_toolchain_ast_FnDecl_t*) l1)->f_name;
    if (t0 == 1976u) {
        l6 = (uint8_t) 0;
    }
    l7 = ((vader_struct_vader_resolver_CollectedModule_t*) l0)->f_symbols;
    l8 = ((vader_struct_toolchain_ast_FnDecl_t*) l1)->f_name;
    l9 = std_collections_MutableMap_Index_at__string__Any(l7, l8);
    if (l9.tag == 1024u) {
        t1 = l9.payload.obj;
        if (((vader_struct_vader_resolver_symbol_Symbol_t*) t1)->f_kind != INT32_C(0)) {
            l7 = ((vader_struct_toolchain_ast_FnDecl_t*) l1)->f_name_span;
            l8 = ((vader_struct_toolchain_ast_FnDecl_t*) l1)->f_name;
            l8 = concat_3(866u, l8, 879u);
            l7 = vader_diagnostics_resolver_error((uint8_t) 3, l7, l8);
            vader_array_push((vader_array_t*) l5, vader_ref_box(l7));
            { vader_gc_top = gc_frame.prev; return; }
        }
    }
    l8 = ((vader_struct_toolchain_ast_FnDecl_t*) l1)->f_name;
    l7 = ((vader_struct_toolchain_ast_FnDecl_t*) l1)->f_name_span;
    l7 = vader_resolver_symbol_make(l4, (uint8_t) 0, l8, l2, l3, l6, vader_ref_box(l7));
    l10 = ((vader_struct_vader_resolver_CollectedModule_t*) l0)->f_fn_overloads;
    l8 = ((vader_struct_toolchain_ast_FnDecl_t*) l1)->f_name;
    l11 = std_collections_MutableMap_Index_at__string__Any(l10, l8);
    if (l11.tag == 0u) {
        l10 = ((vader_struct_vader_resolver_CollectedModule_t*) l0)->f_fn_overloads;
        l8 = ((vader_struct_toolchain_ast_FnDecl_t*) l1)->f_name;
        vader_array_t* _a0_arr = vader_array_new(126u, 1u, 13u, 1024u);
        ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = l7;
        l12 = (void*) _a0_arr;
        std_collections_MutableMap_IndexSet_set_at__string__Any(l10, l8, vader_ref_box(l12));
    } else {
        t1 = l11.payload.obj;
        vader_array_push((vader_array_t*) t1, vader_ref_box(l7));
        l10 = ((vader_struct_vader_resolver_CollectedModule_t*) l0)->f_fn_overloads;
        l8 = ((vader_struct_toolchain_ast_FnDecl_t*) l1)->f_name;
        l12 = l11.payload.obj;
        std_collections_MutableMap_IndexSet_set_at__string__Any(l10, l8, vader_ref_box(l12));
    }
    if (l9.tag == 0u) {
        l10 = ((vader_struct_vader_resolver_CollectedModule_t*) l0)->f_symbols;
        l8 = ((vader_struct_toolchain_ast_FnDecl_t*) l1)->f_name;
        std_collections_MutableMap_IndexSet_set_at__string__Any(l10, l8, vader_ref_box(l7));
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_resolver_add_named(void* l0, uint8_t l1, vader_string_t l2, void* l3, uint8_t l4, vader_string_t l5, vader_string_t l6, void* l7, void* l8) {
    vader_box_t l9 = vader_box_null();
    vader_string_t l10 = 0;
    void* l11 = NULL;
    vader_box_t* gc_roots[1] = { &l9 };
    void** gc_raw_roots[5] = { &l0, &l3, &l7, &l8, &l11 };
    vader_string_t* gc_atom_roots[4] = { &l2, &l5, &l6, &l10 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l9 = std_collections_MutableMap_Index_at__string__Any(((vader_struct_vader_resolver_CollectedModule_t*) l0)->f_symbols, l2);
    if (l9.tag == 1024u) {
        l10 = concat_3(866u, l2, 879u);
        l11 = vader_diagnostics_resolver_error((uint8_t) 3, l3, l10);
        vader_array_push((vader_array_t*) l8, vader_ref_box(l11));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (!(l9.tag == 0u)) {
        vader_unreachable("non-exhaustive match (T3013 should have caught this)");
    }
    l11 = vader_resolver_symbol_make(l7, l1, l2, l5, l6, l4, vader_ref_box(l3));
    std_collections_MutableMap_IndexSet_set_at__string__Any(((vader_struct_vader_resolver_CollectedModule_t*) l0)->f_symbols, l2, vader_ref_box(l11));
    { vader_gc_top = gc_frame.prev; return; }
}

static bool vader_resolver_any_has_body(void* l0) {
    void* l1;
    size_t l2, l3;
    vader_box_t l4;
    void* t0;
    int64_t t1;
    l1 = l0;
    l2 = ((vader_array_t*) l1)->length;
    l3 = (size_t) 0;
    while ((l3 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
        l4 = ((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_body;
        if (l4.tag == 447u) {
            return true;
        }
        if (!(l4.tag == 0u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        t1 = (l3 + INT64_C(1));
        l3 = (size_t) (int64_t) t1;
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
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (!(l1.tag == 475u)) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    t0 = l1.payload.obj;
    l2 = ((vader_struct_toolchain_ast_GenericInstExpr_t*) t0)->f_type_args;
    l3 = ((vader_array_t*) l2)->length;
    l4 = (size_t) 0;
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        l5 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        if (l5.tag == 476u) {
            l6 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_scope;
            t0 = l5.payload.obj;
            l7 = ((vader_struct_toolchain_ast_IdentExpr_t*) t0)->f_name;
            t1 = vader_resolver_lookup(l6, l7);
            if (t1.tag == 0u) {
                t0 = l5.payload.obj;
                l8 = ((vader_struct_toolchain_ast_IdentExpr_t*) t0)->f_name;
                t0 = l5.payload.obj;
                l9 = ((vader_struct_toolchain_ast_IdentExpr_t*) t0)->f_span;
                l10 = vader_resolver_mint_local(l0, (uint8_t) 9, l8, l9);
                l11 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_scope;
                t0 = l5.payload.obj;
                l12 = ((vader_struct_toolchain_ast_IdentExpr_t*) t0)->f_name;
                vader_resolver_bind(l11, l12, l10);
            }
        }
        t2 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t2;
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_resolver_bind(void* l0, vader_string_t l1, void* l2) {
    size_t l3;
    void* l4 = NULL;
    int64_t t0;
    void* t1 = NULL;
    void** gc_raw_roots[4] = { &l0, &l2, &l4, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = ((vader_array_t*) ((vader_struct_vader_resolver_Scope_t*) l0)->f_frames)->length;
    if (!(l3 == INT64_C(0))) {
        l4 = ((vader_struct_vader_resolver_Scope_t*) l0)->f_frames;
        t0 = vader_chk_sub(usize, l3, INT64_C(1));
        l3 = (size_t) (int64_t) t0;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t1 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
        std_collections_MutableMap_IndexSet_set_at__string__Any(t1, l1, vader_ref_box(l2));
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_resolver_bind_1(void* l0, vader_string_t l1, vader_box_t l2) {
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    std_collections_MutableMap_IndexSet_set_at__string__Any(((vader_struct_vader_resolver_Subst_t*) l0)->f_entries, l1, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_resolver_bind_cond_is_as(void* l0, vader_box_t l1, bool l2) {
    vader_box_t l3 = vader_box_null();
    void* l4 = NULL;
    void* l5 = NULL;
    vader_string_t l6 = 0;
    uint64_t l7;
    void* t0 = NULL;
    vader_box_t* gc_roots[2] = { &l1, &l3 };
    void** gc_raw_roots[4] = { &l0, &l4, &l5, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l6 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l1.tag == 446u) {
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
            l3 = ((vader_struct_toolchain_ast_BinaryExpr_t*) t0)->f_bind_as;
            if (l3.tag == 0u) {
                { vader_gc_top = gc_frame.prev; return; }
            }
            if (l2) {
                l4 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_diags;
                t0 = l3.payload.obj;
                l5 = ((vader_struct_toolchain_ast_AsBinding_t*) t0)->f_span;
                l5 = vader_diagnostics_resolver_error((uint8_t) 28, l5, 1256u);
                vader_array_push((vader_array_t*) l4, vader_ref_box(l5));
            }
            t0 = l3.payload.obj;
            l6 = ((vader_struct_toolchain_ast_AsBinding_t*) t0)->f_name;
            t0 = l3.payload.obj;
            l4 = ((vader_struct_toolchain_ast_AsBinding_t*) t0)->f_span;
            l4 = vader_resolver_mint_local(l0, (uint8_t) 11, l6, l4);
            l5 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_scope;
            t0 = l3.payload.obj;
            l6 = ((vader_struct_toolchain_ast_AsBinding_t*) t0)->f_name;
            vader_resolver_bind(l5, l6, l4);
            l5 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_idents;
            t0 = l3.payload.obj;
            l7 = toolchain_span_Span_Hash_hash(((vader_struct_toolchain_ast_AsBinding_t*) t0)->f_span);
            std_collections_MutableMap_IndexSet_set_at__u64__Any(l5, l7, vader_ref_box(l4));
            { vader_gc_top = gc_frame.prev; return; }
        }
        vader_resolver_walk_expr(l0, l1);
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_resolver_walk_expr(l0, l1);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_resolver_bind_import(void* l0, vader_string_t l1, void* l2, vader_string_t l3, vader_box_t l4, vader_string_t l5, void* l6, void* l7) {
    vader_box_t l8 = vader_box_null();
    void* l9 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    int32_t l10;
    bool l11;
    vader_string_t l12 = 0;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    vader_box_t* gc_roots[2] = { &l4, &l8 };
    void** gc_raw_roots[8] = { &l0, &l2, &l6, &l7, &l9, &l13, &l14, &t0 };
    vader_string_t* gc_atom_roots[5] = { &l1, &l3, &l5, &l12, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 5u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_resolver_CollectedModule_t*) l0)->f_files);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
    t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT32_C(0));
    l8 = std_collections_MutableMap_Index_at__string__Any(((vader_struct_vader_resolver_FileImports_t*) t0)->f_bindings, l1);
    if (l8.tag == 0u) {
        l9 = vader_resolver_symbol_make(l6, (uint8_t) 7, l1, l5, l5, (uint8_t) 1, vader_ref_box(l2));
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_resolver_CollectedModule_t*) l0)->f_files);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, INT32_C(0))
        t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) INT32_C(0));
        std_collections_MutableMap_IndexSet_set_at__string__Any(((vader_struct_vader_resolver_FileImports_t*) t0)->f_bindings, l1, vader_ref_box(l9));
        l13 = ((vader_struct_vader_resolver_CollectedModule_t*) l0)->f_imports;
        l10 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l9)->f_id;
        vader_struct_vader_resolver_ImportInfo_t* _a2_obj = (vader_struct_vader_resolver_ImportInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_resolver_ImportInfo_t));
        vader_obj_header_init(_a2_obj, 1006u);
        _a2_obj->f_path = l3;
        _a2_obj->f_imported_name = l4;
        _a2_obj->f_local = l1;
        _a2_obj->f_binding_span = l2;
        l14 = (void*) _a2_obj;
        std_collections_MutableMap_IndexSet_set_at__i32__Any(l13, l10, vader_ref_box(l14));
        { vader_gc_top = gc_frame.prev; return; }
    }
    l9 = ((vader_struct_vader_resolver_CollectedModule_t*) l0)->f_imports;
    t0 = l8.payload.obj;
    l10 = ((vader_struct_vader_resolver_symbol_Symbol_t*) t0)->f_id;
    l8 = std_collections_MutableMap_Index_at__i32__Any(l9, l10);
    if (!(l8.tag == 0u)) {
        t0 = l8.payload.obj;
        t1 = ((vader_struct_vader_resolver_ImportInfo_t*) t0)->f_path;
        if (t1 == l3) {
            t0 = l8.payload.obj;
            l11 = vader_resolver_names_equal(((vader_struct_vader_resolver_ImportInfo_t*) t0)->f_imported_name, l4);
        } else {
            l11 = false;
        }
        l11 = !(l11);
    } else {
        l11 = false;
    }
    if (l11) {
        l12 = concat_3(866u, l1, 866u);
        l9 = vader_diagnostics_resolver_error((uint8_t) 10, l2, l12);
        vader_array_push((vader_array_t*) l7, vader_ref_box(l9));
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_resolver_bind_let_binding(void* l0, vader_box_t l1, void* l2) {
    vader_string_t l3 = 0;
    void* l4 = NULL;
    void* l5 = NULL;
    uint64_t l6;
    size_t l7, l8;
    vader_box_t l9 = vader_box_null();
    void* t0 = NULL;
    int64_t t1;
    vader_box_t* gc_roots[2] = { &l1, &l9 };
    void** gc_raw_roots[5] = { &l0, &l2, &l4, &l5, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l1.tag == 511u) {
        t0 = l1.payload.obj;
        l3 = ((vader_struct_toolchain_ast_SimpleBinding_t*) t0)->f_name;
        t0 = l1.payload.obj;
        l4 = ((vader_struct_toolchain_ast_SimpleBinding_t*) t0)->f_name_span;
        l4 = vader_resolver_bind_local_checked(l0, (uint8_t) 10, l3, l4);
        l5 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_idents;
        t0 = l1.payload.obj;
        l6 = toolchain_span_Span_Hash_hash(((vader_struct_toolchain_ast_SimpleBinding_t*) t0)->f_name_span);
        std_collections_MutableMap_IndexSet_set_at__u64__Any(l5, l6, vader_ref_box(l4));
        vader_array_push((vader_array_t*) l2, vader_ref_box(l4));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 523u) {
        t0 = l1.payload.obj;
        l4 = ((vader_struct_toolchain_ast_TupleBinding_t*) t0)->f_elements;
        l7 = ((vader_array_t*) l4)->length;
        l8 = (size_t) 0;
        while ((l8 < l7)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l8)
            l9 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l8);
            vader_resolver_bind_let_binding(l0, l9, l2);
            t1 = (l8 + INT64_C(1));
            l8 = (size_t) (int64_t) t1;
        }
    } else if (!(l1.tag == 528u)) {
        if (!(l1.tag == 507u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        t0 = l1.payload.obj;
        l3 = ((vader_struct_toolchain_ast_RestBinding_t*) t0)->f_name;
        t0 = l1.payload.obj;
        l4 = ((vader_struct_toolchain_ast_RestBinding_t*) t0)->f_span;
        l4 = vader_resolver_bind_local_checked(l0, (uint8_t) 10, l3, l4);
        l5 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_idents;
        t0 = l1.payload.obj;
        l6 = toolchain_span_Span_Hash_hash(((vader_struct_toolchain_ast_RestBinding_t*) t0)->f_span);
        std_collections_MutableMap_IndexSet_set_at__u64__Any(l5, l6, vader_ref_box(l4));
        vader_array_push((vader_array_t*) l2, vader_ref_box(l4));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void* vader_resolver_bind_local_checked(void* l0, uint8_t l1, vader_string_t l2, void* l3) {
    int32_t l4, l5;
    void* l6 = NULL;
    void* l8 = NULL;
    vader_string_t l7 = 0;
    bool l9;
    int32_t t0;
    void** gc_raw_roots[4] = { &l0, &l3, &l6, &l8 };
    vader_string_t* gc_atom_roots[2] = { &l2, &l7 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l2 == 809u) {
        l4 = INT32_C(-1);
    } else {
        l4 = vader_resolver_lookup_frame_index(((vader_struct_vader_resolver_ResolveState_t*) l0)->f_scope, l2);
    }
    if ((l4 > INT32_C(0))) {
        t0 = vader_resolver_frame_count(((vader_struct_vader_resolver_ResolveState_t*) l0)->f_scope);
        l5 = vader_chk_sub(i32, t0, INT32_C(1));
        if (l4 == l5) {
            l6 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_diags;
            l7 = concat_3(866u, l2, 866u);
            l8 = vader_diagnostics_warning((uint8_t) 5, l3, l7);
            vader_array_push((vader_array_t*) l6, vader_ref_box(l8));
        } else {
            l6 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_diags;
            l7 = concat_3(866u, l2, 866u);
            l8 = vader_diagnostics_warning((uint8_t) 4, l3, l7);
            vader_array_push((vader_array_t*) l6, vader_ref_box(l8));
        }
    }
    l6 = vader_resolver_mint_local(l0, l1, l2, l3);
    vader_resolver_bind(((vader_struct_vader_resolver_ResolveState_t*) l0)->f_scope, l2, l6);
    if (l1 == INT32_C(10)) {
        l9 = true;
    } else {
        l9 = l1 == INT32_C(8);
    }
    if (l9) {
        l8 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_declared_locals;
        l4 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l6)->f_id;
        vader_array_push_i32((vader_array_t*) l8, l4);
        { void* __vret = l6; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { void* __vret = l6; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_resolver_bind_pattern(void* l0, vader_box_t l1) {
    vader_box_t l2 = vader_box_null(), l7 = vader_box_null(), l13 = vader_box_null();
    void* l3 = NULL;
    void* l6 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    size_t l4, l5;
    vader_string_t l8 = 0;
    vader_string_t l12 = 0;
    void* t0 = NULL;
    int64_t t1;
    vader_box_t* gc_roots[4] = { &l1, &l2, &l7, &l13 };
    void** gc_raw_roots[7] = { &l0, &l3, &l6, &l9, &l10, &l11, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l8, &l12 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l1.tag == 488u) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_toolchain_ast_IsPattern_t*) t0)->f_ty;
        vader_resolver_walk_expr(l0, l2);
        t0 = l1.payload.obj;
        if (!(((vader_struct_toolchain_ast_IsPattern_t*) t0)->f_inner.tag == 0u)) {
            t0 = l1.payload.obj;
            l2 = ((vader_struct_toolchain_ast_IsPattern_t*) t0)->f_inner;
            vader_resolver_bind_pattern(l0, l2);
        }
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 520u) {
        t0 = l1.payload.obj;
        l3 = ((vader_struct_toolchain_ast_StructPattern_t*) t0)->f_fields;
        l4 = ((vader_array_t*) l3)->length;
        l5 = (size_t) 0;
        while ((l5 < l4)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
            l6 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
            l2 = ((vader_struct_toolchain_ast_StructPatternField_t*) l6)->f_value;
            l7 = l2;
            if (l2.tag == 501u) {
                l8 = ((vader_struct_toolchain_ast_StructPatternField_t*) l6)->f_name;
                l9 = ((vader_struct_toolchain_ast_StructPatternField_t*) l6)->f_name_span;
                l10 = vader_resolver_mint_local(l0, (uint8_t) 11, l8, l9);
                l11 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_scope;
                l12 = ((vader_struct_toolchain_ast_StructPatternField_t*) l6)->f_name;
                vader_resolver_bind(l11, l12, l10);
            } else {
                if (!(l2.tag == 502u)) {
                    vader_unreachable("non-exhaustive match (T3013 should have caught this)");
                }
                t0 = l7.payload.obj;
                l13 = ((vader_struct_toolchain_ast_PatternLiteral_t*) t0)->f_value;
                vader_resolver_walk_expr(l0, l13);
            }
            t1 = (l5 + INT64_C(1));
            l5 = (size_t) (int64_t) t1;
        }
    } else if (!(l1.tag == 530u)) {
        if (!(l1.tag == 467u)) {
            if (l1.tag == 491u) {
                t0 = l1.payload.obj;
                l2 = ((vader_struct_toolchain_ast_LiteralPattern_t*) t0)->f_value;
                vader_resolver_walk_expr(l0, l2);
            } else if (l1.tag == 506u) {
                t0 = l1.payload.obj;
                l2 = ((vader_struct_toolchain_ast_RangePattern_t*) t0)->f_lower;
                vader_resolver_walk_expr(l0, l2);
                t0 = l1.payload.obj;
                l2 = ((vader_struct_toolchain_ast_RangePattern_t*) t0)->f_upper;
                vader_resolver_walk_expr(l0, l2);
            } else {
                if (!(l1.tag == 500u)) {
                    vader_unreachable("non-exhaustive match (T3013 should have caught this)");
                }
                t0 = l1.payload.obj;
                l3 = ((vader_struct_toolchain_ast_OrPattern_t*) t0)->f_patterns;
                l4 = ((vader_array_t*) l3)->length;
                l5 = (size_t) 0;
                while ((l5 < l4)) {
                    vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
                    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
                    l2 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5);
                    vader_resolver_bind_pattern(l0, l2);
                    t1 = (l5 + INT64_C(1));
                    l5 = (size_t) (int64_t) t1;
                }
            }
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void* vader_resolver_bind_type_param(void* l0, void* l1) {
    vader_string_t l2 = 0;
    void* l3 = NULL;
    void* l4 = NULL;
    vader_box_t l5 = vader_box_null();
    vader_box_t* gc_roots[1] = { &l5 };
    void** gc_raw_roots[4] = { &l0, &l1, &l3, &l4 };
    vader_string_t* gc_atom_roots[1] = { &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_toolchain_ast_TypeParam_t*) l1)->f_name;
    l3 = ((vader_struct_toolchain_ast_TypeParam_t*) l1)->f_span;
    l3 = vader_resolver_mint_local(l0, (uint8_t) 9, l2, l3);
    l4 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_scope;
    l2 = ((vader_struct_toolchain_ast_TypeParam_t*) l1)->f_name;
    vader_resolver_bind(l4, l2, l3);
    l5 = ((vader_struct_toolchain_ast_TypeParam_t*) l1)->f_bound;
    vader_resolver_walk_opt_expr(l0, l5);
    { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_resolver_binding_clashes(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    void* l13 = NULL;
    void* l16 = NULL;
    size_t l6, l7;
    vader_string_t l8 = 0;
    vader_string_t l9 = 0;
    vader_string_t l15 = 0;
    vader_box_t l12 = vader_box_null(), l14 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    int64_t t1;
    vader_box_t* gc_roots[3] = { &l12, &l14, &t0 };
    void** gc_raw_roots[10] = { &l0, &l1, &l2, &l3, &l4, &l5, &l10, &l11, &l13, &l16 };
    vader_string_t* gc_atom_roots[3] = { &l8, &l9, &l15 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 10u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(75u, 0u, 13u, 811u);
    l2 = (void*) _a0_arr;
    l3 = ((vader_struct_vader_resolver_FileImports_t*) l1)->f_bindings;
    l4 = ((vader_struct_std_collections_MutableMap__string__Symbol_t*) l3)->f_ekeys;
    l5 = ((vader_struct_std_collections_MutableMap__string__Symbol_t*) l3)->f_evals;
    l6 = ((vader_struct_std_collections_MutableMap__string__Symbol_t*) l3)->f_size;
    l7 = (size_t) 0;
    while (!((l7 >= l6))) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l7)
        t0 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l7];
        l8 = t0.payload.s;
        vader_array_t* _a2_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l7)
        l3 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l7);
        l9 = l8;
        l10 = l3;
        t1 = (l7 + INT64_C(1));
        l7 = (size_t) (int64_t) t1;
        l12 = std_collections_MutableMap_Index_at__string__Any(((vader_struct_vader_resolver_CollectedModule_t*) l0)->f_symbols, l9);
        if (l12.tag == 0u) {
            continue;
        }
        l11 = l12.payload.obj;
        l14 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l10)->f_defined_at;
        if (l14.tag == 0u) {
            continue;
        }
        l13 = l14.payload.obj;
        if (!(((vader_struct_vader_resolver_symbol_Symbol_t*) l11)->f_kind != INT32_C(0))) {
            continue;
        }
        l15 = concat_3(866u, l9, 866u);
        l16 = vader_diagnostics_resolver_error((uint8_t) 10, l13, l15);
        vader_array_push((vader_array_t*) l2, vader_ref_box(l16));
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_resolver_binding_span(vader_box_t l0) {
    void* l1;
    void* t0;
    if (l0.tag == 511u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_toolchain_ast_SimpleBinding_t*) t0)->f_name_span;
        return l1;
    }
    if (l0.tag == 523u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_toolchain_ast_TupleBinding_t*) t0)->f_span;
    } else if (l0.tag == 507u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_toolchain_ast_RestBinding_t*) t0)->f_span;
    } else {
        if (!(l0.tag == 528u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        t0 = l0.payload.obj;
        l1 = ((vader_struct_toolchain_ast_WildcardBinding_t*) t0)->f_span;
    }
    return l1;
}

static bool vader_resolver_body_survives(void* l0, void* l1) {
    void* l2;
    void* l4;
    void* l7;
    void* l11;
    void* l12;
    vader_box_t l3, l10;
    size_t l5, l6, l8, l9;
    void* t0;
    bool t1;
    int64_t t2;
    l3 = ((vader_struct_toolchain_ast_FnDecl_t*) l0)->f_body;
    if (l3.tag == 0u) {
        return false;
    }
    l2 = l3.payload.obj;
    l4 = l1;
    l5 = ((vader_array_t*) l4)->length;
    l6 = (size_t) 0;
    while ((l6 < l5)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l6);
        l7 = ((vader_struct_toolchain_ast_Program_t*) ((vader_struct_vader_resolver_SourceFile_t*) t0)->f_program)->f_decls;
        l8 = ((vader_array_t*) l7)->length;
        l9 = (size_t) 0;
        while ((l9 < l8)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l7);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            l3 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l9);
            if (l3.tag == 471u) {
                t0 = l3.payload.obj;
                l10 = ((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_body;
                if (!(l10.tag == 0u)) {
                    t0 = l10.payload.obj;
                    l11 = ((vader_struct_toolchain_ast_BlockExpr_t*) t0)->f_span;
                    l12 = ((vader_struct_toolchain_ast_BlockExpr_t*) l2)->f_span;
                    t1 = toolchain_span_Span_Equals_equals(l11, l12);
                    if (t1) {
                        return true;
                    }
                }
            }
            t2 = (l9 + INT64_C(1));
            l9 = (size_t) (int64_t) t2;
        }
        t2 = (l6 + INT64_C(1));
        l6 = (size_t) (int64_t) t2;
    }
    return false;
}

void* vader_resolver_build_core_seed(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l5 = NULL;
    void* l10 = NULL;
    vader_box_t l4 = vader_box_null();
    size_t l6, l7;
    vader_string_t l8 = 0;
    vader_string_t l9 = 0;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    int64_t t2;
    vader_box_t* gc_roots[2] = { &l4, &t1 };
    void** gc_raw_roots[7] = { &l0, &l1, &l2, &l3, &l5, &l10, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l8, &l9 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(13u, 0u, 0u, 244u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(21u, 0u, 0u, 255u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(14u, 0u, 7u, 247u);
    l3 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__string__Any_t* _a3_obj = (vader_struct_std_collections_MutableMap__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__Any_t));
    vader_obj_header_init(_a3_obj, 336u);
    _a3_obj->f_ekeys = l1;
    _a3_obj->f_evals = l2;
    _a3_obj->f_index = l3;
    _a3_obj->f_mask = (size_t) 0;
    _a3_obj->f_size = (size_t) 0;
    _a3_obj->f_tombs = (size_t) 0;
    l1 = (void*) _a3_obj;
    l4 = std_collections_MutableMap_Index_at__string__Any(((vader_struct_vader_resolver_LoadedProject_t*) l0)->f_modules, 389u);
    if (l4.tag == 1009u) {
        t0 = l4.payload.obj;
        l2 = ((vader_struct_vader_resolver_CollectedModule_t*) ((vader_struct_vader_resolver_LoadedModule_t*) t0)->f_collected)->f_symbols;
        l3 = ((vader_struct_std_collections_MutableMap__string__Symbol_t*) l2)->f_ekeys;
        l5 = ((vader_struct_std_collections_MutableMap__string__Symbol_t*) l2)->f_evals;
        l6 = ((vader_struct_std_collections_MutableMap__string__Symbol_t*) l2)->f_size;
        l7 = (size_t) 0;
        while (!((l7 >= l6))) {
            vader_array_t* _a4_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l7)
            t1 = vader_array_box_slots(_a4_slotarr->buf)[_a4_slotarr->offset + (size_t) l7];
            l8 = t1.payload.s;
            vader_array_t* _a5_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l7)
            l2 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l7);
            l9 = l8;
            l10 = l2;
            t2 = (l7 + INT64_C(1));
            l7 = (size_t) (int64_t) t2;
            std_collections_MutableMap_IndexSet_set_at__string__Any(l1, l9, vader_ref_box(l10));
        }
    }
    l4 = vader_resolver_find_core_module_id(l0);
    if (l4.tag == 0u) {
        { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l8 = l4.payload.s;
    l4 = std_collections_MutableMap_Index_at__string__Any(((vader_struct_vader_resolver_LoadedProject_t*) l0)->f_modules, l8);
    if (l4.tag == 0u) {
        { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = l4.payload.obj;
    l2 = ((vader_struct_vader_resolver_CollectedModule_t*) ((vader_struct_vader_resolver_LoadedModule_t*) l2)->f_collected)->f_symbols;
    l3 = ((vader_struct_std_collections_MutableMap__string__Symbol_t*) l2)->f_ekeys;
    l5 = ((vader_struct_std_collections_MutableMap__string__Symbol_t*) l2)->f_evals;
    l6 = ((vader_struct_std_collections_MutableMap__string__Symbol_t*) l2)->f_size;
    l7 = (size_t) 0;
    while (!((l7 >= l6))) {
        vader_array_t* _a6_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l7)
        t1 = vader_array_box_slots(_a6_slotarr->buf)[_a6_slotarr->offset + (size_t) l7];
        l8 = t1.payload.s;
        vader_array_t* _a7_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l7)
        l2 = vader_array_ref_load_obj(_a7_slotarr->buf, _a7_slotarr->offset + (size_t) l7);
        l9 = l8;
        l10 = l2;
        t2 = (l7 + INT64_C(1));
        l7 = (size_t) (int64_t) t2;
        std_collections_MutableMap_IndexSet_set_at__string__Any(l1, l9, vader_ref_box(l10));
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
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
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_resolver_new_subst();
    l3 = ((vader_struct_toolchain_ast_ImplDecl_t*) l0)->f_for_type;
    vader_resolver_bind_1(l2, 652u, l3);
    l4 = ((vader_array_t*) ((vader_struct_toolchain_ast_TraitDecl_t*) l1)->f_type_params)->length;
    l5 = ((vader_array_t*) ((vader_struct_toolchain_ast_ImplDecl_t*) l0)->f_trait_args)->length;
    l4 = std_math_min_2(l4, l5);
    l5 = (size_t) 0;
    while ((l5 < l4)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_TraitDecl_t*) l1)->f_type_params);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
        l6 = ((vader_struct_toolchain_ast_TypeParam_t*) t0)->f_name;
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_ImplDecl_t*) l0)->f_trait_args);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
        l3 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5);
        vader_resolver_bind_1(l2, l6, l3);
        t1 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t1;
    }
    l5 = ((vader_array_t*) ((vader_struct_toolchain_ast_TraitDecl_t*) l1)->f_type_params)->length;
    while ((l4 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_TraitDecl_t*) l1)->f_type_params);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        t0 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
        l7 = ((vader_struct_toolchain_ast_TypeParam_t*) t0)->f_default_v;
        if (l7.tag == 0u) break;
        l3 = l7;
        vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_TraitDecl_t*) l1)->f_type_params);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l4)
        t0 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l4);
        l6 = ((vader_struct_toolchain_ast_TypeParam_t*) t0)->f_name;
        l8 = vader_resolver_substitute_type_expr(l3, l2);
        vader_resolver_bind_1(l2, l6, l8);
        t1 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t1;
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_resolver_builtin_type_names(void) {
    void* l0 = NULL;
    void* l2 = NULL;
    size_t l1, l3;
    vader_string_t l4 = 0;
    void* t0 = NULL;
    int64_t t1;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t2 };
    void** gc_raw_roots[3] = { &l0, &l2, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(13u, 0u, 0u, 244u);
    l0 = (void*) _a0_arr;
    t0 = (void*) &vader_data_23;
    l1 = ((vader_array_t*) t0)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l0, (size_t) l1);
    l0 = (void*) _a1_arr;
    l2 = (void*) &vader_data_23;
    l1 = ((vader_array_t*) l2)->length;
    l3 = (size_t) 0;
    while ((l3 < l1)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
        t0 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l3);
        l4 = ((vader_struct_vader_types_PrimitiveMeta_t*) t0)->f_name;
        vader_array_push((vader_array_t*) l0, vader_box_string(244u, l4));
        t1 = (l3 + INT64_C(1));
        l3 = (size_t) (int64_t) t1;
    }
    l2 = (void*) &vader_data_24;
    l1 = ((vader_array_t*) l2)->length;
    l3 = (size_t) 0;
    while ((l3 < l1)) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l3)
        t0 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l3);
        vader_array_t* _a4_slotarr = ((vader_array_t*) t0);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, INT32_C(0))
        t2 = vader_array_box_slots(_a4_slotarr->buf)[_a4_slotarr->offset + (size_t) INT32_C(0)];
        l4 = t2.payload.s;
        vader_array_push((vader_array_t*) l0, vader_box_string(244u, l4));
        t1 = (l3 + INT64_C(1));
        l3 = (size_t) (int64_t) t1;
    }
    l2 = (void*) &vader_data_13;
    l1 = ((vader_array_t*) l2)->length;
    l3 = (size_t) 0;
    while ((l3 < l1)) {
        vader_array_t* _a5_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l3)
        t2 = vader_array_box_slots(_a5_slotarr->buf)[_a5_slotarr->offset + (size_t) l3];
        l4 = t2.payload.s;
        vader_array_push((vader_array_t*) l0, vader_box_string(244u, l4));
        t1 = (l3 + INT64_C(1));
        l3 = (size_t) (int64_t) t1;
    }
    { void* __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_resolver_check_groups(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l11 = NULL;
    void* l18 = NULL;
    void* l22 = NULL;
    void* l24 = NULL;
    void* l25 = NULL;
    void* l26 = NULL;
    void* l27 = NULL;
    void* l33 = NULL;
    void* l34 = NULL;
    void* l40 = NULL;
    void* l41 = NULL;
    void* l42 = NULL;
    size_t l6, l7, l8, l9, l15, l16;
    vader_box_t l10 = vader_box_null(), l12 = vader_box_null(), l14 = vader_box_null(), l31 = vader_box_null();
    vader_string_t l13 = 0;
    vader_string_t l17 = 0;
    vader_string_t l19 = 0;
    vader_string_t l20 = 0;
    vader_string_t l21 = 0;
    vader_string_t l23 = 0;
    vader_string_t l29 = 0;
    vader_string_t l30 = 0;
    vader_string_t l32 = 0;
    vader_string_t l35 = 0;
    vader_string_t l36 = 0;
    vader_string_t l37 = 0;
    vader_string_t l38 = 0;
    vader_string_t l39 = 0;
    uint8_t l28;
    void* t0 = NULL;
    int64_t t1;
    bool t2;
    vader_box_t t3 = vader_box_null();
    vader_box_t* gc_roots[5] = { &l10, &l12, &l14, &l31, &t3 };
    void** gc_raw_roots[19] = {
        &l0, &l1, &l2, &l3, &l4, &l5, &l11, &l18, &l22, &l24, &l25, &l26, &l27, &l33, &l34, &l40,
        &l41, &l42, &t0,
    };
    vader_string_t* gc_atom_roots[14] = {
        &l13, &l17, &l19, &l20, &l21, &l23, &l29, &l30, &l32, &l35, &l36, &l37, &l38, &l39,
    };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 5u, 19u, gc_roots, gc_raw_roots, 0u, NULL, 14u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(13u, 0u, 0u, 244u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(21u, 0u, 0u, 255u);
    l3 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(14u, 0u, 7u, 247u);
    l4 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__string__Any_t* _a3_obj = (vader_struct_std_collections_MutableMap__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__Any_t));
    vader_obj_header_init(_a3_obj, 336u);
    _a3_obj->f_ekeys = l2;
    _a3_obj->f_evals = l3;
    _a3_obj->f_index = l4;
    _a3_obj->f_mask = (size_t) 0;
    _a3_obj->f_size = (size_t) 0;
    _a3_obj->f_tombs = (size_t) 0;
    l2 = (void*) _a3_obj;
    vader_array_t* _a4_arr = vader_array_new(13u, 0u, 0u, 244u);
    l3 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_new(21u, 0u, 0u, 255u);
    l4 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(14u, 0u, 7u, 247u);
    l5 = (void*) _a6_arr;
    vader_struct_std_collections_MutableMap__string__Any_t* _a7_obj = (vader_struct_std_collections_MutableMap__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__Any_t));
    vader_obj_header_init(_a7_obj, 336u);
    _a7_obj->f_ekeys = l3;
    _a7_obj->f_evals = l4;
    _a7_obj->f_index = l5;
    _a7_obj->f_mask = (size_t) 0;
    _a7_obj->f_size = (size_t) 0;
    _a7_obj->f_tombs = (size_t) 0;
    l3 = (void*) _a7_obj;
    l4 = l0;
    l6 = ((vader_array_t*) l4)->length;
    l7 = (size_t) 0;
    while ((l7 < l6)) {
        vader_array_t* _a8_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l7)
        t0 = vader_array_ref_load_obj(_a8_slotarr->buf, _a8_slotarr->offset + (size_t) l7);
        l5 = ((vader_struct_toolchain_ast_Program_t*) ((vader_struct_vader_resolver_SourceFile_t*) t0)->f_program)->f_decls;
        l8 = ((vader_array_t*) l5)->length;
        l9 = (size_t) 0;
        while ((l9 < l8)) {
            vader_array_t* _a9_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l9)
            l10 = vader_array_ref_load_box(_a9_slotarr->buf, _a9_slotarr->offset + (size_t) l9);
            if (l10.tag == 471u) {
                t0 = l10.payload.obj;
                l12 = vader_resolver_target_selectors(((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_decorators);
                if (l12.tag == 0u) {
                    t1 = (l9 + INT64_C(1));
                    l9 = (size_t) (int64_t) t1;
                    continue;
                }
                l11 = l12.payload.obj;
                t2 = ((vader_struct_vader_resolver_TargetSelectors_t*) l11)->f_is_bare;
                if (t2) {
                    t0 = l10.payload.obj;
                    l13 = ((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_name;
                    l14 = std_collections_MutableMap_Index_at__string__Any(l2, l13);
                    if (l14.tag == 0u) {
                        t0 = l10.payload.obj;
                        l23 = ((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_name;
                        l24 = l10.payload.obj;
                        std_collections_MutableMap_IndexSet_set_at__string__Any(l2, l23, vader_ref_box(l24));
                    } else {
                        t0 = l14.payload.obj;
                        l15 = ((vader_array_t*) ((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_params)->length;
                        t0 = l10.payload.obj;
                        l16 = ((vader_array_t*) ((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_params)->length;
                        if (l15 != l16) {
                            l17 = 157u;
                        } else {
                            l17 = 0u;
                        }
                        t0 = l10.payload.obj;
                        l18 = ((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_name_span;
                        t0 = l10.payload.obj;
                        l19 = ((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_name;
                        t0 = l14.payload.obj;
                        l20 = vader_resolver_span_origin(((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_name_span);
                        l21 = concat_5(866u, l19, 949u, l20, l17);
                        l22 = vader_diagnostics_resolver_error((uint8_t) 38, l18, l21);
                        vader_array_push((vader_array_t*) l1, vader_ref_box(l22));
                        t1 = (l9 + INT64_C(1));
                        l9 = (size_t) (int64_t) t1;
                        continue;
                    }
                } else {
                    t1 = (l9 + INT64_C(1));
                    l9 = (size_t) (int64_t) t1;
                    continue;
                }
            }
            t1 = (l9 + INT64_C(1));
            l9 = (size_t) (int64_t) t1;
        }
        t1 = (l7 + INT64_C(1));
        l7 = (size_t) (int64_t) t1;
    }
    l4 = l0;
    l6 = ((vader_array_t*) l4)->length;
    l7 = (size_t) 0;
    while ((l7 < l6)) {
        vader_array_t* _a10_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a10_slotarr, l7)
        t0 = vader_array_ref_load_obj(_a10_slotarr->buf, _a10_slotarr->offset + (size_t) l7);
        l5 = ((vader_struct_toolchain_ast_Program_t*) ((vader_struct_vader_resolver_SourceFile_t*) t0)->f_program)->f_decls;
        l8 = ((vader_array_t*) l5)->length;
        l9 = (size_t) 0;
        while ((l9 < l8)) {
            vader_array_t* _a11_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l9)
            l10 = vader_array_ref_load_box(_a11_slotarr->buf, _a11_slotarr->offset + (size_t) l9);
            if (l10.tag == 471u) {
                t0 = l10.payload.obj;
                l12 = vader_resolver_target_selectors(((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_decorators);
                if (l12.tag == 0u) {
                    t1 = (l9 + INT64_C(1));
                    l9 = (size_t) (int64_t) t1;
                    continue;
                }
                t0 = l12.payload.obj;
                t2 = ((vader_struct_vader_resolver_TargetSelectors_t*) t0)->f_is_bare;
                if (t2) {
                    t1 = (l9 + INT64_C(1));
                    l9 = (size_t) (int64_t) t1;
                    continue;
                }
                t0 = l10.payload.obj;
                l13 = ((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_name;
                l14 = std_collections_MutableMap_Index_at__string__Any(l2, l13);
                if (l14.tag == 0u) {
                    t0 = l10.payload.obj;
                    l11 = ((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_name_span;
                    t0 = l10.payload.obj;
                    l17 = ((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_name;
                    l19 = concat_3(866u, l17, 920u);
                    l18 = vader_diagnostics_resolver_error((uint8_t) 35, l11, l19);
                    vader_array_push((vader_array_t*) l1, vader_ref_box(l18));
                } else {
                    l22 = l14.payload.obj;
                    l24 = l10.payload.obj;
                    vader_resolver_check_signature(l22, l24, l1);
                }
                t0 = l10.payload.obj;
                if (((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_visibility == INT32_C(0)) {
                    t0 = l10.payload.obj;
                    l25 = ((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_name_span;
                    t0 = l10.payload.obj;
                    l20 = ((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_name;
                    l21 = concat_3(866u, l20, 943u);
                    l26 = vader_diagnostics_resolver_error((uint8_t) 36, l25, l21);
                    vader_array_push((vader_array_t*) l1, vader_ref_box(l26));
                }
                t0 = l12.payload.obj;
                l27 = ((vader_struct_vader_resolver_TargetSelectors_t*) t0)->f_os;
                l15 = ((vader_array_t*) l27)->length;
                l16 = (size_t) 0;
                while ((l16 < l15)) {
                    vader_array_t* _a12_slotarr = ((vader_array_t*) l27);
                    VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a12_slotarr, l16)
                    t3 = vader_array_read_u8(_a12_slotarr, _a12_slotarr->offset + (size_t) l16, 250u);
                    l28 = ((uint8_t) t3.payload.i);
                    t0 = l10.payload.obj;
                    l23 = ((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_name;
                    l29 = std_target_Os_Display_to_string(l28);
                    l30 = concat_3(l23, 2673u, l29);
                    l31 = std_collections_MutableMap_Index_at__string__Any(l3, l30);
                    if (l31.tag == 0u) {
                        t0 = l10.payload.obj;
                        l42 = ((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_name_span;
                        std_collections_MutableMap_IndexSet_set_at__string__Any(l3, l30, vader_ref_box(l42));
                    } else {
                        l33 = l31.payload.obj;
                        t0 = l10.payload.obj;
                        l34 = ((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_name_span;
                        t2 = toolchain_span_Span_Equals_equals(l33, l34);
                        if (t2) {
                            t0 = l10.payload.obj;
                            l35 = ((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_name;
                            l36 = std_target_Os_Display_to_string(l28);
                            l32 = concat_5(866u, l35, 981u, l36, 1031u);
                        } else {
                            t0 = l10.payload.obj;
                            l37 = ((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_name;
                            l38 = std_target_Os_Display_to_string(l28);
                            t0 = l31.payload.obj;
                            l39 = vader_resolver_span_origin(t0);
                            l32 = concat_6(866u, l37, 880u, l38, 888u, l39);
                        }
                        t0 = l10.payload.obj;
                        l40 = ((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_name_span;
                        l41 = vader_diagnostics_resolver_error((uint8_t) 37, l40, l32);
                        vader_array_push((vader_array_t*) l1, vader_ref_box(l41));
                    }
                    t1 = (l16 + INT64_C(1));
                    l16 = (size_t) (int64_t) t1;
                }
            }
            t1 = (l9 + INT64_C(1));
            l9 = (size_t) (int64_t) t1;
        }
        t1 = (l7 + INT64_C(1));
        l7 = (size_t) (int64_t) t1;
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_resolver_check_import_form_conflict(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l13 = NULL;
    void* l15 = NULL;
    void* l19 = NULL;
    void* l22 = NULL;
    void* l24 = NULL;
    size_t l6, l7;
    vader_box_t l8 = vader_box_null(), l9 = vader_box_null();
    vader_string_t l10 = 0;
    vader_string_t l11 = 0;
    vader_string_t l12 = 0;
    vader_string_t l14 = 0;
    vader_string_t l16 = 0;
    vader_string_t l18 = 0;
    vader_string_t l20 = 0;
    vader_string_t l21 = 0;
    vader_string_t l23 = 0;
    bool l17;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    int64_t t2;
    vader_box_t* gc_roots[3] = { &l8, &l9, &t1 };
    void** gc_raw_roots[12] = { &l0, &l1, &l2, &l3, &l4, &l5, &l13, &l15, &l19, &l22, &l24, &t0 };
    vader_string_t* gc_atom_roots[9] = { &l10, &l11, &l12, &l14, &l16, &l18, &l20, &l21, &l23 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 12u, gc_roots, gc_raw_roots, 0u, NULL, 9u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(13u, 0u, 0u, 244u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(21u, 0u, 0u, 255u);
    l3 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(14u, 0u, 7u, 247u);
    l4 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__string__Any_t* _a3_obj = (vader_struct_std_collections_MutableMap__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__Any_t));
    vader_obj_header_init(_a3_obj, 336u);
    _a3_obj->f_ekeys = l2;
    _a3_obj->f_evals = l3;
    _a3_obj->f_index = l4;
    _a3_obj->f_mask = (size_t) 0;
    _a3_obj->f_size = (size_t) 0;
    _a3_obj->f_tombs = (size_t) 0;
    l2 = (void*) _a3_obj;
    vader_array_t* _a4_arr = vader_array_new(13u, 0u, 0u, 244u);
    l3 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_new(21u, 0u, 0u, 255u);
    l4 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(14u, 0u, 7u, 247u);
    l5 = (void*) _a6_arr;
    vader_struct_std_collections_MutableMap__string__Any_t* _a7_obj = (vader_struct_std_collections_MutableMap__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__Any_t));
    vader_obj_header_init(_a7_obj, 336u);
    _a7_obj->f_ekeys = l3;
    _a7_obj->f_evals = l4;
    _a7_obj->f_index = l5;
    _a7_obj->f_mask = (size_t) 0;
    _a7_obj->f_size = (size_t) 0;
    _a7_obj->f_tombs = (size_t) 0;
    l3 = (void*) _a7_obj;
    l4 = l0;
    l6 = ((vader_array_t*) l4)->length;
    l7 = (size_t) 0;
    while ((l7 < l6)) {
        vader_array_t* _a8_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l7)
        l8 = vader_array_ref_load_box(_a8_slotarr->buf, _a8_slotarr->offset + (size_t) l7);
        if (l8.tag == 481u) {
            t0 = l8.payload.obj;
            l9 = ((vader_struct_toolchain_ast_ImportDecl_t*) t0)->f_binding;
            if (l9.tag == 529u) {
                t0 = l8.payload.obj;
                l10 = ((vader_struct_toolchain_ast_ImportDecl_t*) t0)->f_path;
                t1 = std_collections_MutableMap_Index_at__string__Any(l3, l10);
                if (!(t1.tag == 0u)) {
                    t0 = l8.payload.obj;
                    l5 = ((vader_struct_toolchain_ast_ImportDecl_t*) t0)->f_span;
                    t0 = l8.payload.obj;
                    l11 = ((vader_struct_toolchain_ast_ImportDecl_t*) t0)->f_path;
                    l12 = concat_3(866u, l11, 866u);
                    l13 = vader_diagnostics_resolver_error((uint8_t) 31, l5, l12);
                    vader_array_push((vader_array_t*) l1, vader_ref_box(l13));
                }
                t0 = l8.payload.obj;
                l14 = ((vader_struct_toolchain_ast_ImportDecl_t*) t0)->f_path;
                t0 = l8.payload.obj;
                l15 = ((vader_struct_toolchain_ast_ImportDecl_t*) t0)->f_span;
                std_collections_MutableMap_IndexSet_set_at__string__Any(l2, l14, vader_ref_box(l15));
            } else if (l9.tag == 461u) {
                t0 = l8.payload.obj;
                l16 = ((vader_struct_toolchain_ast_ImportDecl_t*) t0)->f_path;
                t1 = std_collections_MutableMap_Index_at__string__Any(l2, l16);
                if (!(t1.tag == 0u)) {
                    l17 = true;
                } else {
                    t0 = l8.payload.obj;
                    l18 = ((vader_struct_toolchain_ast_ImportDecl_t*) t0)->f_path;
                    t1 = std_collections_MutableMap_Index_at__string__Any(l3, l18);
                    l17 = !(t1.tag == 0u);
                }
                if (l17) {
                    t0 = l8.payload.obj;
                    l19 = ((vader_struct_toolchain_ast_ImportDecl_t*) t0)->f_span;
                    t0 = l8.payload.obj;
                    l20 = ((vader_struct_toolchain_ast_ImportDecl_t*) t0)->f_path;
                    l21 = concat_3(866u, l20, 866u);
                    l22 = vader_diagnostics_resolver_error((uint8_t) 31, l19, l21);
                    vader_array_push((vader_array_t*) l1, vader_ref_box(l22));
                }
                t0 = l8.payload.obj;
                l23 = ((vader_struct_toolchain_ast_ImportDecl_t*) t0)->f_path;
                t0 = l8.payload.obj;
                l24 = ((vader_struct_toolchain_ast_ImportDecl_t*) t0)->f_span;
                std_collections_MutableMap_IndexSet_set_at__string__Any(l3, l23, vader_ref_box(l24));
            }
        }
        t2 = (l7 + INT64_C(1));
        l7 = (size_t) (int64_t) t2;
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_resolver_check_orphan_rule(void* l0, vader_string_t l1, void* l2, void* l3, void* l4, void* l5, void* l6) {
    void* l7 = NULL;
    vader_box_t l8 = vader_box_null();
    bool l9, l10, l11;
    vader_string_t l12 = 0;
    vader_string_t l13 = 0;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    vader_box_t* gc_roots[1] = { &l8 };
    void** gc_raw_roots[8] = { &l0, &l2, &l3, &l4, &l5, &l6, &l7, &t0 };
    vader_string_t* gc_atom_roots[4] = { &l1, &l12, &l13, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l8 = vader_resolver_lookup_trait_sym(l0, l2, l3, l5);
    if (l8.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l7 = l8.payload.obj;
    if (((vader_struct_vader_resolver_symbol_Symbol_t*) l7)->f_kind != INT32_C(3)) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l8 = vader_resolver_for_type_owner_sym(((vader_struct_toolchain_ast_ImplDecl_t*) l0)->f_for_type, l4, l5);
    l9 = false;
    l10 = false;
    if (l8.tag == 1024u) {
        t0 = l8.payload.obj;
        l9 = ((vader_struct_vader_resolver_symbol_Symbol_t*) t0)->f_kind == INT32_C(12);
        t0 = l8.payload.obj;
        t1 = ((vader_struct_vader_resolver_symbol_Symbol_t*) t0)->f_module;
        l10 = t1 == l1;
    }
    t1 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l7)->f_module;
    l11 = t1 == l1;
    if (l9) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l10) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l11) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l7 = ((vader_struct_toolchain_ast_ImplDecl_t*) l0)->f_span;
    l12 = ((vader_struct_toolchain_ast_ImplDecl_t*) l0)->f_trait_name;
    l13 = vader_resolver_for_type_display_name(((vader_struct_toolchain_ast_ImplDecl_t*) l0)->f_for_type);
    l12 = concat_4(l12, 73u, l13, 166u);
    l7 = vader_diagnostics_resolver_error((uint8_t) 17, l7, l12);
    vader_array_push((vader_array_t*) l6, vader_ref_box(l7));
    { vader_gc_top = gc_frame.prev; return; }
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
    void* l22 = NULL;
    size_t l3, l4, l6, l7, l10, l11, l14, l15;
    vader_box_t l8 = vader_box_null(), l16 = vader_box_null();
    vader_string_t l18 = 0;
    vader_string_t l19 = 0;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    vader_string_t t3 = 0;
    int64_t t2;
    vader_box_t t4 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l8, &l16, &t4 };
    void** gc_raw_roots[12] = { &l0, &l1, &l2, &l5, &l9, &l12, &l13, &l17, &l20, &l21, &l22, &t0 };
    vader_string_t* gc_atom_roots[4] = { &l18, &l19, &t1, &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 12u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = l0;
    l3 = ((vader_array_t*) l2)->length;
    l4 = (size_t) 0;
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        l5 = ((vader_struct_toolchain_ast_Program_t*) ((vader_struct_vader_resolver_SourceFile_t*) t0)->f_program)->f_decls;
        l6 = ((vader_array_t*) l5)->length;
        l7 = (size_t) 0;
        while ((l7 < l6)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l7)
            l8 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l7);
            if (l8.tag == 471u) {
                t0 = l8.payload.obj;
                l9 = ((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_decorators;
                l10 = ((vader_array_t*) l9)->length;
                l11 = (size_t) 0;
                while ((l11 < l10)) {
                    vader_array_t* _a2_slotarr = ((vader_array_t*) l9);
                    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l11)
                    l12 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l11);
                    t1 = ((vader_struct_toolchain_ast_Decorator_t*) l12)->f_name;
                    if (t1 != 2331u) {
                        t2 = (l11 + INT64_C(1));
                        l11 = (size_t) (int64_t) t2;
                        continue;
                    }
                    l13 = ((vader_struct_toolchain_ast_Decorator_t*) l12)->f_args;
                    l14 = ((vader_array_t*) l13)->length;
                    l15 = (size_t) 0;
                    while ((l15 < l14)) {
                        vader_array_t* _a3_slotarr = ((vader_array_t*) l13);
                        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l15)
                        l16 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l15);
                        if (l16.tag == 464u) {
                            t0 = l16.payload.obj;
                            t1 = ((vader_struct_toolchain_ast_DotVariantExpr_t*) t0)->f_variant;
                            t3 = std_string_to_lower(t1);
                            t4 = vader_target_parse_os(t3);
                            if (t4.tag == 0u) {
                                t0 = l16.payload.obj;
                                l17 = ((vader_struct_toolchain_ast_DotVariantExpr_t*) t0)->f_span;
                                t0 = l16.payload.obj;
                                l18 = ((vader_struct_toolchain_ast_DotVariantExpr_t*) t0)->f_variant;
                                l19 = concat_3(1096u, l18, 994u);
                                l20 = vader_diagnostics_resolver_error((uint8_t) 34, l17, l19);
                                vader_array_push((vader_array_t*) l1, vader_ref_box(l20));
                            }
                        } else {
                            t0 = l16.payload.obj;
                            l21 = ((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t0)->f_span;
                            l22 = vader_diagnostics_resolver_error((uint8_t) 34, l21, 1192u);
                            vader_array_push((vader_array_t*) l1, vader_ref_box(l22));
                        }
                        t2 = (l15 + INT64_C(1));
                        l15 = (size_t) (int64_t) t2;
                    }
                    t2 = (l11 + INT64_C(1));
                    l11 = (size_t) (int64_t) t2;
                }
            }
            t2 = (l7 + INT64_C(1));
            l7 = (size_t) (int64_t) t2;
        }
        t2 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t2;
    }
    { vader_gc_top = gc_frame.prev; return; }
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
    int64_t t0, t3;
    size_t t1;
    void* t2 = NULL;
    void** gc_raw_roots[7] = { &l0, &l1, &l2, &l5, &l8, &l22, &t2 };
    vader_string_t* gc_atom_roots[8] = { &l6, &l7, &l10, &l11, &l12, &l19, &l20, &l21 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 7u, NULL, gc_raw_roots, 0u, NULL, 8u, gc_atom_roots,
    };
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
        l3 = (size_t) 0;
        l3 = std_core_write_string_at(l8, l3, 866u);
        l3 = std_core_write_string_at(l8, l3, l6);
        l3 = std_core_write_string_at(l8, l3, 1020u);
        t1 = ((vader_array_t*) ((vader_struct_toolchain_ast_FnDecl_t*) l0)->f_params)->length;
        t0 = ((int64_t) (size_t) t1);
        l9 = (uint64_t) (int64_t) t0;
        l3 = std_core_write_unsigned(l8, l3, l9);
        l3 = std_core_write_string_at(l8, l3, 119u);
        l3 = std_core_write_string_at(l8, l3, l7);
        l3 = std_core_write_string_at(l8, l3, 279u);
        l6 = std_core_finish_buffer(l8, l3);
        l8 = std_core_new_byte_buffer((size_t) 36);
        l3 = (size_t) 0;
        l3 = std_core_write_string_at(l8, l3, 2361u);
        t1 = ((vader_array_t*) ((vader_struct_toolchain_ast_FnDecl_t*) l1)->f_params)->length;
        t0 = ((int64_t) (size_t) t1);
        l9 = (uint64_t) (int64_t) t0;
        l3 = std_core_write_unsigned(l8, l3, l9);
        l7 = std_core_finish_buffer(l8, l3);
        l6 = concat_2(l6, l7);
        l5 = vader_diagnostics_resolver_error((uint8_t) 39, l5, l6);
        vader_array_push((vader_array_t*) l2, vader_ref_box(l5));
        { vader_gc_top = gc_frame.prev; return; }
    }
    l3 = (size_t) 0;
    l4 = ((vader_array_t*) ((vader_struct_toolchain_ast_FnDecl_t*) l0)->f_params)->length;
    while ((l3 < l4)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_FnDecl_t*) l0)->f_params);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t2 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
        l6 = ((vader_struct_toolchain_ast_FnParam_t*) t2)->f_name;
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_FnDecl_t*) l1)->f_params);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
        t2 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l3);
        l7 = ((vader_struct_toolchain_ast_FnParam_t*) t2)->f_name;
        if (l6 != l7) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_FnDecl_t*) l1)->f_params);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
            t2 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l3);
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
            l18 = (size_t) 0;
            l18 = std_core_write_string_at(l8, l18, 2104u);
            t0 = vader_chk_add(usize, l3, INT64_C(1));
            t3 = t0;
            l9 = (uint64_t) (int64_t) t3;
            l18 = std_core_write_unsigned(l8, l18, l9);
            l18 = std_core_write_string_at(l8, l18, 108u);
            l18 = std_core_write_string_at(l8, l18, l10);
            l18 = std_core_write_string_at(l8, l18, 940u);
            l18 = std_core_write_string_at(l8, l18, l11);
            l18 = std_core_write_string_at(l8, l18, 888u);
            l18 = std_core_write_string_at(l8, l18, l12);
            l18 = std_core_write_string_at(l8, l18, 279u);
            l19 = std_core_finish_buffer(l8, l18);
            l20 = concat_3(866u, l7, 929u);
            l21 = concat_3(l19, l20, 1496u);
            l22 = vader_diagnostics_resolver_error((uint8_t) 39, l5, l21);
            vader_array_push((vader_array_t*) l2, vader_ref_box(l22));
        }
        t0 = (l3 + INT64_C(1));
        l3 = (size_t) (int64_t) t0;
    }
    { vader_gc_top = gc_frame.prev; return; }
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
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 10u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_toolchain_ast_Decorator_t*) l1)->f_args;
    l3 = ((vader_array_t*) l2)->length;
    l4 = (size_t) 0;
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        l5 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        if (l5.tag == 464u) {
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
                l9 = concat_3(1096u, l8, 994u);
                l10 = vader_diagnostics_resolver_error((uint8_t) 34, l7, l9);
                vader_array_push((vader_array_t*) l6, vader_ref_box(l10));
            }
        } else {
            l11 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_diags;
            t0 = l5.payload.obj;
            l12 = ((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t0)->f_span;
            l13 = vader_diagnostics_resolver_error((uint8_t) 34, l12, 1613u);
            vader_array_push((vader_array_t*) l11, vader_ref_box(l13));
        }
        t4 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t4;
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_resolver_check_wildcard_ambiguity(void* l0, vader_string_t l1, void* l2, void* l3) {
    vader_string_t l4 = 0;
    vader_string_t l5 = 0;
    void* l6 = NULL;
    void* l10 = NULL;
    vader_box_t l7 = vader_box_null();
    size_t l8, l9;
    vader_box_t t0 = vader_box_null();
    int64_t t1;
    vader_box_t* gc_roots[2] = { &l7, &t0 };
    void** gc_raw_roots[5] = { &l0, &l2, &l3, &l6, &l10 };
    vader_string_t* gc_atom_roots[3] = { &l1, &l4, &l5 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l3)->f_module;
    l5 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_module_path;
    if (l4 == l5) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l7 = std_collections_MutableMap_Index_at__string__Any(((vader_struct_vader_resolver_ResolveState_t*) l0)->f_ambiguous, l1);
    if (l7.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l6 = l7.payload.obj;
    l4 = 0u;
    l8 = (size_t) 0;
    l9 = ((vader_array_t*) l6)->length;
    while ((l8 < l9)) {
        if ((l8 > INT64_C(0))) {
            l4 = concat_2(l4, 279u);
        }
        vader_array_t* _a0_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l8)
        t0 = vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l8];
        l5 = t0.payload.s;
        l4 = concat_2(l4, l5);
        t1 = (l8 + INT64_C(1));
        l8 = (size_t) (int64_t) t1;
    }
    l6 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_diags;
    l4 = concat_7(866u, l1, 956u, l4, 168u, l1, 1068u);
    l10 = vader_diagnostics_resolver_error((uint8_t) 30, l2, l4);
    vader_array_push((vader_array_t*) l6, vader_ref_box(l10));
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_resolver_checked_bound(void* l0, void* l1, vader_box_t l2) {
    void* l3 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    vader_box_t l4 = vader_box_null();
    size_t l8, l9;
    bool l10;
    vader_string_t l11 = 0;
    vader_string_t l12 = 0;
    bool t0;
    void* t1 = NULL;
    vader_string_t t2 = 0;
    int64_t t3;
    size_t t4;
    vader_box_t t5 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l2, &l4, &t5 };
    void** gc_raw_roots[7] = { &l0, &l1, &l3, &l5, &l6, &l7, &t1 };
    vader_string_t* gc_atom_roots[3] = { &l11, &l12, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_toolchain_ast_TypeParam_t*) l1)->f_is_comptime_value;
    if (t0) {
        { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = vader_resolver_union_in_bound(l2);
    if (l4.tag == 0u) {
        { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = l4.payload.obj;
    l5 = toolchain_ast_collect_bitor_variants(vader_ref_box(l3));
    vader_array_t* _a0_arr = vader_array_new(179u, 0u, 13u, 1259u);
    l6 = (void*) _a0_arr;
    l7 = l5;
    l8 = ((vader_array_t*) l7)->length;
    l9 = (size_t) 0;
    while ((l9 < l8)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l9)
        l4 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l9);
        if (!(l4.tag == 476u)) {
            l10 = true;
        } else {
            t1 = l4.payload.obj;
            t2 = ((vader_struct_toolchain_ast_IdentExpr_t*) t1)->f_name;
            l10 = t2 != 2070u;
        }
        if (l10) {
            vader_array_push((vader_array_t*) l6, l4);
        }
        t3 = (l9 + INT64_C(1));
        l9 = (size_t) (int64_t) t3;
    }
    l8 = ((vader_array_t*) l6)->length;
    l9 = ((vader_array_t*) l5)->length;
    if ((l8 < l9)) {
        l11 = ((vader_struct_toolchain_ast_TypeParam_t*) l1)->f_name;
        l12 = ((vader_struct_toolchain_ast_TypeParam_t*) l1)->f_name;
        l11 = concat_5(2129u, l11, 978u, l12, 151u);
    } else {
        l11 = 1197u;
    }
    l5 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_diags;
    l3 = ((vader_struct_toolchain_ast_BinaryExpr_t*) l3)->f_span;
    l12 = ((vader_struct_toolchain_ast_TypeParam_t*) l1)->f_name;
    l11 = concat_4(866u, l12, 1039u, l11);
    l3 = vader_diagnostics_resolver_error((uint8_t) 41, l3, l11);
    vader_array_push((vader_array_t*) l5, vader_ref_box(l3));
    t4 = ((vader_array_t*) l6)->length;
    if (t4 == INT64_C(1)) {
        if (l2.tag == 446u) {
            t1 = l2.payload.obj;
            if (((vader_struct_toolchain_ast_BinaryExpr_t*) t1)->f_op == INT32_C(8)) {
                vader_array_t* _a2_slotarr = ((vader_array_t*) l6);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, INT32_C(0))
                t5 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) INT32_C(0));
                { vader_box_t __vret = t5; vader_gc_top = gc_frame.prev; return __vret; }
            }
            { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
        }
        { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_resolver_clone_assign_value(void* l0, vader_box_t l1, void* l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    uint8_t l5;
    vader_box_t l6 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    vader_box_t* gc_roots[3] = { &l1, &l6, &t0 };
    void** gc_raw_roots[5] = { &l0, &l2, &l3, &l4, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = toolchain_ast_compound_assign_op(l0);
    if (t0.tag == 0u) {
        t0 = vader_resolver_substitute_expr_full(((vader_struct_toolchain_ast_AssignStmt_t*) l0)->f_value, l2);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (((vader_struct_toolchain_ast_AssignStmt_t*) l0)->f_value.tag == 446u) {
        l3 = ((vader_struct_toolchain_ast_AssignStmt_t*) l0)->f_value.payload.obj;
        l4 = ((vader_struct_toolchain_ast_BinaryExpr_t*) l3)->f_span;
        l5 = ((vader_struct_toolchain_ast_BinaryExpr_t*) l3)->f_op;
        l6 = vader_resolver_substitute_expr_full(((vader_struct_toolchain_ast_BinaryExpr_t*) l3)->f_right, l2);
        vader_struct_toolchain_ast_BinaryExpr_t* _a0_obj = (vader_struct_toolchain_ast_BinaryExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_BinaryExpr_t));
        vader_obj_header_init(_a0_obj, 446u);
        _a0_obj->f_span = l4;
        _a0_obj->f_id = (size_t) 0;
        _a0_obj->f_op = l5;
        _a0_obj->f_left = l1;
        _a0_obj->f_right = l6;
        _a0_obj->f_bind_as = vader_box_obj(0u, NULL);
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_resolver_substitute_expr_full(((vader_struct_toolchain_ast_AssignStmt_t*) l0)->f_value, l2);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_resolver_clone_ident(void* l0) {
    void* l1 = NULL;
    vader_box_t l2 = vader_box_null();
    vader_string_t l3 = 0;
    bool l4, l5;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[3] = { &l0, &l1, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = l0;
    t0 = ((vader_struct_toolchain_ast_IdentExpr_t*) l1)->f_span;
    l2 = vader_ref_box(t0);
    l3 = ((vader_struct_toolchain_ast_IdentExpr_t*) l1)->f_name;
    l4 = ((vader_struct_toolchain_ast_IdentExpr_t*) l1)->f_implicit_dot;
    l5 = ((vader_struct_toolchain_ast_IdentExpr_t*) l1)->f_is_type_param_intro;
    vader_struct_toolchain_ast_IdentExpr_t* _a0_obj = (vader_struct_toolchain_ast_IdentExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_IdentExpr_t));
    vader_obj_header_init(_a0_obj, 476u);
    _a0_obj->f_span = l2.payload.obj;
    _a0_obj->f_id = (size_t) 0;
    _a0_obj->f_name = l3;
    _a0_obj->f_implicit_dot = l4;
    _a0_obj->f_is_type_param_intro = l5;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_resolver_clone_let_binding(vader_box_t l0) {
    void* l1 = NULL;
    void* l5 = NULL;
    vader_box_t l2 = vader_box_null(), l4 = vader_box_null();
    vader_string_t l3 = 0;
    size_t l6, l7;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    int64_t t2;
    vader_box_t* gc_roots[4] = { &l0, &l2, &l4, &t1 };
    void** gc_raw_roots[3] = { &l1, &l5, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l0.tag == 511u) {
        l1 = l0.payload.obj;
        t0 = ((vader_struct_toolchain_ast_SimpleBinding_t*) l1)->f_span;
        l2 = vader_ref_box(t0);
        l3 = ((vader_struct_toolchain_ast_SimpleBinding_t*) l1)->f_name;
        t0 = ((vader_struct_toolchain_ast_SimpleBinding_t*) l1)->f_name_span;
        l4 = vader_ref_box(t0);
        vader_struct_toolchain_ast_SimpleBinding_t* _a0_obj = (vader_struct_toolchain_ast_SimpleBinding_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_SimpleBinding_t));
        vader_obj_header_init(_a0_obj, 511u);
        _a0_obj->f_span = l2.payload.obj;
        _a0_obj->f_id = (size_t) 0;
        _a0_obj->f_name = l3;
        _a0_obj->f_name_span = l4.payload.obj;
        t0 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 523u) {
        vader_array_t* _a1_arr = vader_array_new(185u, 0u, 13u, 1316u);
        l1 = (void*) _a1_arr;
        t0 = l0.payload.obj;
        l5 = ((vader_struct_toolchain_ast_TupleBinding_t*) t0)->f_elements;
        l6 = ((vader_array_t*) l5)->length;
        l7 = (size_t) 0;
        while ((l7 < l6)) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l7)
            t1 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l7);
            l2 = vader_resolver_clone_let_binding(t1);
            vader_array_push((vader_array_t*) l1, l2);
            t2 = (l7 + INT64_C(1));
            l7 = (size_t) (int64_t) t2;
        }
        t0 = l0.payload.obj;
        vader_struct_toolchain_ast_TupleBinding_t* _a3_obj = (vader_struct_toolchain_ast_TupleBinding_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_TupleBinding_t));
        vader_obj_header_init(_a3_obj, 523u);
        _a3_obj->f_span = ((vader_struct_toolchain_ast_TupleBinding_t*) t0)->f_span;
        _a3_obj->f_id = (size_t) 0;
        _a3_obj->f_elements = l1;
        t0 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 528u) {
        t0 = l0.payload.obj;
        vader_struct_toolchain_ast_WildcardBinding_t* _a4_obj = (vader_struct_toolchain_ast_WildcardBinding_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_WildcardBinding_t));
        vader_obj_header_init(_a4_obj, 528u);
        _a4_obj->f_span = ((vader_struct_toolchain_ast_WildcardBinding_t*) t0)->f_span;
        _a4_obj->f_id = (size_t) 0;
        t0 = (void*) _a4_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l0.tag == 507u)) {
        vader_unreachable("non-exhaustive match (T3013 should have caught this)");
    }
    l1 = l0.payload.obj;
    t0 = ((vader_struct_toolchain_ast_RestBinding_t*) l1)->f_span;
    l2 = vader_ref_box(t0);
    l3 = ((vader_struct_toolchain_ast_RestBinding_t*) l1)->f_name;
    t0 = ((vader_struct_toolchain_ast_RestBinding_t*) l1)->f_name_span;
    l4 = vader_ref_box(t0);
    vader_struct_toolchain_ast_RestBinding_t* _a5_obj = (vader_struct_toolchain_ast_RestBinding_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_RestBinding_t));
    vader_obj_header_init(_a5_obj, 507u);
    _a5_obj->f_span = l2.payload.obj;
    _a5_obj->f_id = (size_t) 0;
    _a5_obj->f_name = l3;
    _a5_obj->f_name_span = l4.payload.obj;
    t0 = (void*) _a5_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_resolver_collect_decl(void* l0, vader_box_t l1, vader_string_t l2, vader_string_t l3, void* l4, void* l5, void* l6, void* l7) {
    void* l8 = NULL;
    vader_string_t l9 = 0;
    uint8_t l10;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[7] = { &l0, &l4, &l5, &l6, &l7, &l8, &t0 };
    vader_string_t* gc_atom_roots[3] = { &l2, &l3, &l9 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l1.tag == 481u) {
        l8 = l1.payload.obj;
        vader_resolver_collect_import(l0, l8, l2, l3, l4, l5, l6, l7);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 471u) {
        l8 = l1.payload.obj;
        vader_resolver_add_fn(l0, l8, l2, l3, l4, l7);
    } else if (l1.tag == 515u) {
        t0 = l1.payload.obj;
        l9 = ((vader_struct_toolchain_ast_StructDecl_t*) t0)->f_name;
        t0 = l1.payload.obj;
        l8 = ((vader_struct_toolchain_ast_StructDecl_t*) t0)->f_name_span;
        t0 = l1.payload.obj;
        l10 = ((vader_struct_toolchain_ast_StructDecl_t*) t0)->f_visibility;
        vader_resolver_add_named(l0, (uint8_t) 1, l9, l8, l10, l2, l3, l4, l7);
    } else if (l1.tag == 465u) {
        t0 = l1.payload.obj;
        l9 = ((vader_struct_toolchain_ast_EnumDecl_t*) t0)->f_name;
        t0 = l1.payload.obj;
        l8 = ((vader_struct_toolchain_ast_EnumDecl_t*) t0)->f_name_span;
        t0 = l1.payload.obj;
        l10 = ((vader_struct_toolchain_ast_EnumDecl_t*) t0)->f_visibility;
        vader_resolver_add_named(l0, (uint8_t) 2, l9, l8, l10, l2, l3, l4, l7);
    } else if (l1.tag == 522u) {
        t0 = l1.payload.obj;
        l9 = ((vader_struct_toolchain_ast_TraitDecl_t*) t0)->f_name;
        t0 = l1.payload.obj;
        l8 = ((vader_struct_toolchain_ast_TraitDecl_t*) t0)->f_name_span;
        t0 = l1.payload.obj;
        l10 = ((vader_struct_toolchain_ast_TraitDecl_t*) t0)->f_visibility;
        vader_resolver_add_named(l0, (uint8_t) 3, l9, l8, l10, l2, l3, l4, l7);
    } else if (l1.tag == 524u) {
        t0 = l1.payload.obj;
        l9 = ((vader_struct_toolchain_ast_TypeAliasDecl_t*) t0)->f_name;
        t0 = l1.payload.obj;
        l8 = ((vader_struct_toolchain_ast_TypeAliasDecl_t*) t0)->f_name_span;
        t0 = l1.payload.obj;
        l10 = ((vader_struct_toolchain_ast_TypeAliasDecl_t*) t0)->f_visibility;
        vader_resolver_add_named(l0, (uint8_t) 5, l9, l8, l10, l2, l3, l4, l7);
    } else if (l1.tag == 454u) {
        t0 = l1.payload.obj;
        l9 = ((vader_struct_toolchain_ast_ConstDecl_t*) t0)->f_name;
        t0 = l1.payload.obj;
        l8 = ((vader_struct_toolchain_ast_ConstDecl_t*) t0)->f_name_span;
        t0 = l1.payload.obj;
        l10 = ((vader_struct_toolchain_ast_ConstDecl_t*) t0)->f_visibility;
        vader_resolver_add_named(l0, (uint8_t) 6, l9, l8, l10, l2, l3, l4, l7);
    } else if (!(l1.tag == 480u)) {
        if (!(l1.tag == 443u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void* vader_resolver_collect_files(void* l0, vader_string_t l1, vader_string_t l2, void* l3, void* l4, void* l5, void* l6) {
    void* l7 = NULL;
    void* l10 = NULL;
    size_t l8, l9;
    void* t0 = NULL;
    int64_t t1;
    void** gc_raw_roots[8] = { &l0, &l3, &l4, &l5, &l6, &l7, &l10, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l1, &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 8u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
    t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT32_C(0));
    l7 = vader_resolver_collect_module(((vader_struct_vader_resolver_SourceFile_t*) t0)->f_program, l1, l2, l3, l4, l5, l6);
    l8 = (size_t) 1;
    l9 = ((vader_array_t*) l0)->length;
    while ((l8 < l9)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l8)
        t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l8);
        l10 = vader_resolver_collect_module(((vader_struct_vader_resolver_SourceFile_t*) t0)->f_program, l1, l2, l3, l4, l5, l6);
        vader_resolver_merge_collected(l7, l10, l6);
        t1 = (l8 + INT64_C(1));
        l8 = (size_t) (int64_t) t1;
    }
    { void* __vret = l7; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_resolver_collect_import(void* l0, void* l1, vader_string_t l2, vader_string_t l3, void* l4, void* l5, void* l6, void* l7) {
    void* l8 = NULL;
    void* l12 = NULL;
    void* l15 = NULL;
    void* l17 = NULL;
    void* l18 = NULL;
    void* l21 = NULL;
    vader_string_t l9 = 0;
    vader_string_t l11 = 0;
    vader_string_t l19 = 0;
    vader_string_t l20 = 0;
    vader_string_t l22 = 0;
    vader_string_t l23 = 0;
    vader_box_t l10 = vader_box_null(), l16 = vader_box_null();
    size_t l13, l14;
    vader_string_t t0 = 0;
    void* t1 = NULL;
    size_t t2;
    vader_box_t t3 = vader_box_null();
    int64_t t4;
    vader_box_t* gc_roots[3] = { &l10, &l16, &t3 };
    void** gc_raw_roots[13] = {
        &l0, &l1, &l4, &l5, &l6, &l7, &l8, &l12, &l15, &l17, &l18, &l21, &t1,
    };
    vader_string_t* gc_atom_roots[9] = { &l2, &l3, &l9, &l11, &l19, &l20, &l22, &l23, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 13u, gc_roots, gc_raw_roots, 0u, NULL, 9u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_toolchain_ast_ImportDecl_t*) l1)->f_path;
    if (t0 == 0u) {
        l8 = ((vader_struct_toolchain_ast_ImportDecl_t*) l1)->f_span;
        l8 = vader_diagnostics_resolver_error((uint8_t) 1, l8, 0u);
        vader_array_push((vader_array_t*) l7, vader_ref_box(l8));
    } else {
        l8 = ((vader_struct_vader_resolver_CollectedModule_t*) l0)->f_import_paths;
        l9 = ((vader_struct_toolchain_ast_ImportDecl_t*) l1)->f_path;
        vader_array_push((vader_array_t*) l8, vader_box_string(244u, l9));
        l9 = ((vader_struct_toolchain_ast_ImportDecl_t*) l1)->f_path;
        l8 = ((vader_struct_toolchain_ast_ImportDecl_t*) l1)->f_span;
        vader_resolver_diagnose_import_path(l9, l8, l3, l5, l6, l7);
    }
    l10 = ((vader_struct_toolchain_ast_ImportDecl_t*) l1)->f_binding;
    if (l10.tag == 496u) {
        t1 = l10.payload.obj;
        l9 = ((vader_struct_toolchain_ast_NamedNamespaceImport_t*) t1)->f_name;
        l8 = ((vader_struct_toolchain_ast_ImportDecl_t*) l1)->f_span;
        l11 = ((vader_struct_toolchain_ast_ImportDecl_t*) l1)->f_path;
        vader_resolver_bind_import(l0, l9, l8, l11, vader_box_obj(0u, NULL), l2, l4, l7);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l10.tag == 529u) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_resolver_CollectedModule_t*) l0)->f_files);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
        t1 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT32_C(0));
        l8 = ((vader_struct_vader_resolver_FileImports_t*) t1)->f_paths;
        l9 = ((vader_struct_toolchain_ast_ImportDecl_t*) l1)->f_path;
        vader_array_push((vader_array_t*) l8, vader_box_string(244u, l9));
    } else {
        if (!(l10.tag == 461u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_resolver_CollectedModule_t*) l0)->f_files);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, INT32_C(0))
        t1 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) INT32_C(0));
        l8 = ((vader_struct_vader_resolver_FileImports_t*) t1)->f_paths;
        l9 = ((vader_struct_toolchain_ast_ImportDecl_t*) l1)->f_path;
        vader_array_push((vader_array_t*) l8, vader_box_string(244u, l9));
        t1 = l10.payload.obj;
        t2 = ((vader_array_t*) ((vader_struct_toolchain_ast_DestructureImport_t*) t1)->f_names)->length;
        if (t2 == INT64_C(0)) {
            l8 = ((vader_struct_toolchain_ast_ImportDecl_t*) l1)->f_span;
            l9 = ((vader_struct_toolchain_ast_ImportDecl_t*) l1)->f_path;
            l9 = concat_3(866u, l9, 866u);
            l8 = vader_diagnostics_warning((uint8_t) 7, l8, l9);
            vader_array_push((vader_array_t*) l7, vader_ref_box(l8));
        }
        vader_array_t* _a2_arr = vader_array_new(13u, 0u, 0u, 244u);
        l8 = (void*) _a2_arr;
        t1 = l10.payload.obj;
        l12 = ((vader_struct_toolchain_ast_DestructureImport_t*) t1)->f_names;
        l13 = ((vader_array_t*) l12)->length;
        l14 = (size_t) 0;
        while ((l14 < l13)) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l12);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l14)
            l15 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l14);
            l10 = ((vader_struct_toolchain_ast_ImportName_t*) l15)->f_alias;
            l16 = l10;
            if (l10.tag == 0u) {
                l17 = ((vader_struct_toolchain_ast_ImportName_t*) l15)->f_span;
                l9 = ((vader_struct_toolchain_ast_ImportName_t*) l15)->f_name;
                l11 = concat_3(866u, l9, 866u);
                l18 = vader_diagnostics_resolver_error((uint8_t) 32, l17, l11);
                vader_array_push((vader_array_t*) l7, vader_ref_box(l18));
            } else {
                if (!(l10.tag == 244u)) {
                    vader_unreachable("non-exhaustive match (T3013 should have caught this)");
                }
                l19 = ((vader_struct_toolchain_ast_ImportName_t*) l15)->f_name;
                vader_array_push((vader_array_t*) l8, vader_box_string(244u, l19));
                t0 = l16.payload.s;
                if (t0 != 809u) {
                    l20 = l16.payload.s;
                    l21 = ((vader_struct_toolchain_ast_ImportName_t*) l15)->f_span;
                    l22 = ((vader_struct_toolchain_ast_ImportDecl_t*) l1)->f_path;
                    l23 = ((vader_struct_toolchain_ast_ImportName_t*) l15)->f_name;
                    t3 = vader_box_string(244u, l23);
                    vader_resolver_bind_import(l0, l20, l21, l22, t3, l2, l4, l7);
                }
            }
            t4 = (l14 + INT64_C(1));
            l14 = (size_t) (int64_t) t4;
        }
        vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_vader_resolver_CollectedModule_t*) l0)->f_files);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, INT32_C(0))
        t1 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) INT32_C(0));
        l12 = ((vader_struct_vader_resolver_FileImports_t*) t1)->f_excludes;
        l9 = ((vader_struct_toolchain_ast_ImportDecl_t*) l1)->f_path;
        std_collections_MutableMap_IndexSet_set_at__string__Any(l12, l9, vader_ref_box(l8));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void* vader_resolver_collect_module(void* l0, vader_string_t l1, vader_string_t l2, void* l3, void* l4, void* l5, void* l6) {
    void* l7 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    void* l15 = NULL;
    void* l16 = NULL;
    vader_string_t l12 = 0;
    size_t l17, l18;
    vader_box_t l19 = vader_box_null();
    void* t0 = NULL;
    int64_t t1;
    vader_box_t* gc_roots[1] = { &l19 };
    void** gc_raw_roots[15] = {
        &l0, &l3, &l4, &l5, &l6, &l7, &l8, &l9, &l10, &l11, &l13, &l14, &l15, &l16, &t0,
    };
    vader_string_t* gc_atom_roots[3] = { &l1, &l2, &l12 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 15u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(13u, 0u, 0u, 244u);
    l7 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(21u, 0u, 0u, 255u);
    l8 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(14u, 0u, 7u, 247u);
    l9 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__string__Any_t* _a3_obj = (vader_struct_std_collections_MutableMap__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__Any_t));
    vader_obj_header_init(_a3_obj, 336u);
    _a3_obj->f_ekeys = l7;
    _a3_obj->f_evals = l8;
    _a3_obj->f_index = l9;
    _a3_obj->f_mask = (size_t) 0;
    _a3_obj->f_size = (size_t) 0;
    _a3_obj->f_tombs = (size_t) 0;
    l7 = (void*) _a3_obj;
    vader_array_t* _a4_arr = vader_array_new(13u, 0u, 0u, 244u);
    l8 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_new(21u, 0u, 0u, 255u);
    l9 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(14u, 0u, 7u, 247u);
    l10 = (void*) _a6_arr;
    vader_struct_std_collections_MutableMap__string__Any___t* _a7_obj = (vader_struct_std_collections_MutableMap__string__Any___t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__Any___t));
    vader_obj_header_init(_a7_obj, 338u);
    _a7_obj->f_ekeys = l8;
    _a7_obj->f_evals = l9;
    _a7_obj->f_index = l10;
    _a7_obj->f_mask = (size_t) 0;
    _a7_obj->f_size = (size_t) 0;
    _a7_obj->f_tombs = (size_t) 0;
    l8 = (void*) _a7_obj;
    vader_array_t* _a8_arr = vader_array_new(14u, 0u, 7u, 247u);
    l9 = (void*) _a8_arr;
    vader_array_t* _a9_arr = vader_array_new(21u, 0u, 0u, 255u);
    l10 = (void*) _a9_arr;
    vader_array_t* _a10_arr = vader_array_new(14u, 0u, 7u, 247u);
    l11 = (void*) _a10_arr;
    vader_struct_std_collections_MutableMap__i32__Any_t* _a11_obj = (vader_struct_std_collections_MutableMap__i32__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__Any_t));
    vader_obj_header_init(_a11_obj, 296u);
    _a11_obj->f_ekeys = l9;
    _a11_obj->f_evals = l10;
    _a11_obj->f_index = l11;
    _a11_obj->f_mask = (size_t) 0;
    _a11_obj->f_size = (size_t) 0;
    _a11_obj->f_tombs = (size_t) 0;
    l9 = (void*) _a11_obj;
    vader_array_t* _a12_arr = vader_array_new(13u, 0u, 0u, 244u);
    l10 = (void*) _a12_arr;
    l12 = ((vader_struct_toolchain_ast_Program_t*) l0)->f_file;
    vader_array_t* _a13_arr = vader_array_new(13u, 0u, 0u, 244u);
    l11 = (void*) _a13_arr;
    vader_array_t* _a14_arr = vader_array_new(13u, 0u, 0u, 244u);
    l13 = (void*) _a14_arr;
    vader_array_t* _a15_arr = vader_array_new(21u, 0u, 0u, 255u);
    l14 = (void*) _a15_arr;
    vader_array_t* _a16_arr = vader_array_new(14u, 0u, 7u, 247u);
    l15 = (void*) _a16_arr;
    vader_struct_std_collections_MutableMap__string__Any___t* _a17_obj = (vader_struct_std_collections_MutableMap__string__Any___t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__Any___t));
    vader_obj_header_init(_a17_obj, 338u);
    _a17_obj->f_ekeys = l13;
    _a17_obj->f_evals = l14;
    _a17_obj->f_index = l15;
    _a17_obj->f_mask = (size_t) 0;
    _a17_obj->f_size = (size_t) 0;
    _a17_obj->f_tombs = (size_t) 0;
    l13 = (void*) _a17_obj;
    vader_array_t* _a18_arr = vader_array_new(13u, 0u, 0u, 244u);
    l14 = (void*) _a18_arr;
    vader_array_t* _a19_arr = vader_array_new(21u, 0u, 0u, 255u);
    l15 = (void*) _a19_arr;
    vader_array_t* _a20_arr = vader_array_new(14u, 0u, 7u, 247u);
    l16 = (void*) _a20_arr;
    vader_struct_std_collections_MutableMap__string__Any_t* _a21_obj = (vader_struct_std_collections_MutableMap__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__Any_t));
    vader_obj_header_init(_a21_obj, 336u);
    _a21_obj->f_ekeys = l14;
    _a21_obj->f_evals = l15;
    _a21_obj->f_index = l16;
    _a21_obj->f_mask = (size_t) 0;
    _a21_obj->f_size = (size_t) 0;
    _a21_obj->f_tombs = (size_t) 0;
    l14 = (void*) _a21_obj;
    vader_struct_vader_resolver_FileImports_t* _a22_obj = (vader_struct_vader_resolver_FileImports_t*) vader_gc_alloc(sizeof(vader_struct_vader_resolver_FileImports_t));
    vader_obj_header_init(_a22_obj, 1003u);
    _a22_obj->f_file = l12;
    _a22_obj->f_paths = l11;
    _a22_obj->f_excludes = l13;
    _a22_obj->f_bindings = l14;
    t0 = (void*) _a22_obj;
    vader_array_t* _a23_arr = vader_array_new(118u, 1u, 13u, 1003u);
    ((void**) _a23_arr->buf->slots)[_a23_arr->offset + 0u] = t0;
    l11 = (void*) _a23_arr;
    vader_struct_vader_resolver_CollectedModule_t* _a24_obj = (vader_struct_vader_resolver_CollectedModule_t*) vader_gc_alloc(sizeof(vader_struct_vader_resolver_CollectedModule_t));
    vader_obj_header_init(_a24_obj, 1001u);
    _a24_obj->f_symbols = l7;
    _a24_obj->f_fn_overloads = l8;
    _a24_obj->f_imports = l9;
    _a24_obj->f_import_paths = l10;
    _a24_obj->f_files = l11;
    l7 = (void*) _a24_obj;
    vader_resolver_check_import_form_conflict(((vader_struct_toolchain_ast_Program_t*) l0)->f_decls, l6);
    l8 = ((vader_struct_toolchain_ast_Program_t*) l0)->f_decls;
    l17 = ((vader_array_t*) l8)->length;
    l18 = (size_t) 0;
    while ((l18 < l17)) {
        vader_array_t* _a25_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a25_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a25_slotarr, l18)
        l19 = vader_array_ref_load_box(_a25_slotarr->buf, _a25_slotarr->offset + (size_t) l18);
        vader_resolver_collect_decl(l7, l19, l1, l2, l3, l4, l5, l6);
        t1 = (l18 + INT64_C(1));
        l18 = (size_t) (int64_t) t1;
    }
    { void* __vret = l7; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_resolver_collect_module_no_index(void* l0, vader_string_t l1, void* l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[6] = { &l0, &l2, &l3, &l4, &l5, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 6u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(13u, 0u, 0u, 244u);
    l3 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(21u, 0u, 0u, 255u);
    l4 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(14u, 0u, 7u, 247u);
    l5 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__string__Any_t* _a3_obj = (vader_struct_std_collections_MutableMap__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__Any_t));
    vader_obj_header_init(_a3_obj, 336u);
    _a3_obj->f_ekeys = l3;
    _a3_obj->f_evals = l4;
    _a3_obj->f_index = l5;
    _a3_obj->f_mask = (size_t) 0;
    _a3_obj->f_size = (size_t) 0;
    _a3_obj->f_tombs = (size_t) 0;
    l3 = (void*) _a3_obj;
    vader_array_t* _a4_arr = vader_array_new(75u, 0u, 13u, 811u);
    l4 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_new(120u, 0u, 13u, 1008u);
    l5 = (void*) _a5_arr;
    t0 = vader_resolver_collect_module(l0, l1, l1, l2, l3, l5, l4);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
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
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
        t1 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT32_C(0));
        { void* __vret = ((vader_struct_toolchain_ast_Program_t*) ((vader_struct_vader_resolver_SourceFile_t*) t1)->f_program)->f_decls; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a1_arr = vader_array_new(180u, 0u, 13u, 1273u);
    l1 = (void*) _a1_arr;
    l2 = l0;
    l3 = ((vader_array_t*) l2)->length;
    l4 = (size_t) 0;
    while ((l4 < l3)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        t1 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
        l5 = ((vader_struct_toolchain_ast_Program_t*) ((vader_struct_vader_resolver_SourceFile_t*) t1)->f_program)->f_decls;
        l6 = ((vader_array_t*) l5)->length;
        l7 = (size_t) 0;
        while ((l7 < l6)) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l7)
            l8 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l7);
            vader_array_push((vader_array_t*) l1, l8);
            t2 = (l7 + INT64_C(1));
            l7 = (size_t) (int64_t) t2;
        }
        t2 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t2;
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static size_t vader_resolver_count_sam_synthetics(void* l0) {
    size_t l1, l3, l4;
    void* l2;
    void* t0;
    bool t1;
    int64_t t2;
    l1 = (size_t) 0;
    l2 = l0;
    l3 = ((vader_array_t*) l2)->length;
    l4 = (size_t) 0;
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        t1 = ((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_sam_synthetic;
        if (t1) {
            t2 = vader_chk_add(usize, l1, INT64_C(1));
            l1 = (size_t) (int64_t) t2;
        }
        t2 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t2;
    }
    return l1;
}

static void* vader_resolver_declare_type_param(void* l0, void* l1) {
    void* l2 = NULL;
    void* l4 = NULL;
    vader_box_t l3 = vader_box_null();
    int32_t l5;
    vader_box_t* gc_roots[1] = { &l3 };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = vader_resolver_bind_type_param(l0, l1);
    l3 = ((vader_struct_toolchain_ast_TypeParam_t*) l1)->f_bound;
    if (l3.tag == 0u) {
        { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_type_param_bounds;
    l5 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l2)->f_id;
    l3 = vader_resolver_checked_bound(l0, l1, l3);
    std_collections_MutableMap_IndexSet_set_at__i32__Any(l4, l5, l3);
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_resolver_declared_outside_lambda(void* l0, vader_string_t l1) {
    int32_t l2;
    vader_box_t l3;
    int32_t t0;
    l3 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_lambda_frame;
    if (l3.tag == 0u) {
        return false;
    }
    l2 = ((int32_t) l3.payload.i);
    t0 = vader_resolver_lookup_frame_index(((vader_struct_vader_resolver_ResolveState_t*) l0)->f_scope, l1);
    return (t0 < l2);
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
    vader_string_t* gc_atom_roots[2] = { &l9, &l10 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(13u, 0u, 0u, 244u);
    l3 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(14u, 0u, 7u, 247u);
    l4 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(14u, 0u, 7u, 247u);
    l5 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__string__i32_t* _a3_obj = (vader_struct_std_collections_MutableMap__string__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__i32_t));
    vader_obj_header_init(_a3_obj, 385u);
    _a3_obj->f_ekeys = l3;
    _a3_obj->f_evals = l4;
    _a3_obj->f_index = l5;
    _a3_obj->f_mask = (size_t) 0;
    _a3_obj->f_size = (size_t) 0;
    _a3_obj->f_tombs = (size_t) 0;
    l3 = (void*) _a3_obj;
    l4 = l0;
    l5 = ((vader_struct_std_collections_MutableMap__string__LoadedModule_t*) l4)->f_ekeys;
    l6 = ((vader_struct_std_collections_MutableMap__string__LoadedModule_t*) l4)->f_evals;
    l7 = ((vader_struct_std_collections_MutableMap__string__LoadedModule_t*) l4)->f_size;
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
        t1 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l8);
        l10 = l9;
        t2 = (l8 + INT64_C(1));
        l8 = (size_t) (int64_t) t2;
        t0 = std_collections_MutableMap_Index_at__string__i32(l3, l10);
        if (!(t0.tag == 0u)) {
            continue;
        }
        vader_resolver_walk_import_cycle(l10, l0, l1, l3, l2);
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_resolver_diagnose_import_path(vader_string_t l0, void* l1, vader_string_t l2, void* l3, void* l4, void* l5) {
    bool l6;
    vader_string_t l7 = 0;
    void* l8 = NULL;
    vader_box_t l9 = vader_box_null();
    bool t0;
    uint8_t t1;
    void* t2 = NULL;
    vader_string_t t3 = 0;
    vader_box_t t4 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l9, &t4 };
    void** gc_raw_roots[6] = { &l1, &l3, &l4, &l5, &l8, &t2 };
    vader_string_t* gc_atom_roots[4] = { &l0, &l2, &l7, &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = std_string_starts_with(l0, 315u);
    if (t0) {
        l6 = true;
    } else {
        l6 = std_string_starts_with(l0, 312u);
    }
    if (l6) {
        l7 = concat_3(866u, l0, 866u);
        l8 = vader_diagnostics_resolver_error((uint8_t) 24, l1, l7);
        vader_array_push((vader_array_t*) l5, vader_ref_box(l8));
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    if (l0 == l2) {
        l7 = concat_3(866u, l0, 866u);
        l8 = vader_diagnostics_resolver_error((uint8_t) 23, l1, l7);
        vader_array_push((vader_array_t*) l5, vader_ref_box(l8));
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    if (l0 == 2231u) {
        if (l2 != 2231u) {
            l8 = vader_diagnostics_resolver_error((uint8_t) 27, l1, 0u);
            vader_array_push((vader_array_t*) l5, vader_ref_box(l8));
            { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
        }
    }
    t0 = std_string_starts_with(l0, 2489u);
    if (t0) {
        t0 = std_string_starts_with(l2, 2489u);
        if (!(t0)) {
            if (l2 != 2373u) {
                t1 = vader_resolver_importer_origin(l3, l2);
                if (t1 == INT32_C(1)) {
                    l7 = concat_5(866u, l2, 977u, l0, 1049u);
                    l8 = vader_diagnostics_resolver_error((uint8_t) 33, l1, l7);
                    vader_array_push((vader_array_t*) l5, vader_ref_box(l8));
                    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
                }
            }
        }
    }
    t0 = std_collections_is_empty__string__Any(l3);
    if (t0) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l9 = std_collections_MutableMap_Index_at__string__Any(l3, l0);
    if (l9.tag == 1002u) {
        t2 = l9.payload.obj;
        t3 = ((vader_struct_vader_resolver_DiscoveredModule_t*) t2)->f_folder;
        t4 = vader_box_string(244u, t3);
        { vader_box_t __vret = t4; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l9.tag == 0u)) {
        vader_unreachable("non-exhaustive match (T3013 should have caught this)");
    }
    l9 = vader_resolver_misplaced_module_at(l0, l4);
    if (l9.tag == 0u) {
        l7 = concat_3(866u, l0, 866u);
        l8 = vader_diagnostics_resolver_error((uint8_t) 0, l1, l7);
        vader_array_push((vader_array_t*) l5, vader_ref_box(l8));
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l7 = l9.payload.s;
    l7 = concat_5(866u, l0, 1046u, l7, 183u);
    l8 = vader_diagnostics_resolver_error((uint8_t) 0, l1, l7);
    vader_array_push((vader_array_t*) l5, vader_ref_box(l8));
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
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
}

static void* vader_resolver_discarded_bodies(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l7 = NULL;
    void* l11 = NULL;
    size_t l5, l6, l8, l9;
    vader_box_t l10 = vader_box_null();
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    int64_t t2;
    bool t3;
    vader_box_t* gc_roots[3] = { &l1, &l10, &t1 };
    void** gc_raw_roots[7] = { &l0, &l2, &l3, &l4, &l7, &l11, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 7u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(29u, 0u, 13u, 471u);
    l2 = (void*) _a0_arr;
    if (l1.tag == 0u) {
        { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = l1.payload.obj;
    vader_array_t* _a1_arr = vader_array_new(75u, 0u, 13u, 811u);
    l4 = (void*) _a1_arr;
    l3 = vader_resolver_select_target_bodies(l0, vader_ref_box(l3), l4);
    l4 = l0;
    l5 = ((vader_array_t*) l4)->length;
    l6 = (size_t) 0;
    while ((l6 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l6)
        t0 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l6);
        l7 = ((vader_struct_toolchain_ast_Program_t*) ((vader_struct_vader_resolver_SourceFile_t*) t0)->f_program)->f_decls;
        l8 = ((vader_array_t*) l7)->length;
        l9 = (size_t) 0;
        while ((l9 < l8)) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l7);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l9)
            l10 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l9);
            if (l10.tag == 471u) {
                t0 = l10.payload.obj;
                t1 = vader_resolver_target_selectors(((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_decorators);
                if (t1.tag == 0u) {
                    t2 = (l9 + INT64_C(1));
                    l9 = (size_t) (int64_t) t2;
                    continue;
                }
                t0 = l10.payload.obj;
                t3 = vader_resolver_body_survives(t0, l3);
                if (t3) {
                    t2 = (l9 + INT64_C(1));
                    l9 = (size_t) (int64_t) t2;
                    continue;
                }
                l11 = l10.payload.obj;
                vader_array_push((vader_array_t*) l2, vader_ref_box(l11));
            }
            t2 = (l9 + INT64_C(1));
            l9 = (size_t) (int64_t) t2;
        }
        t2 = (l6 + INT64_C(1));
        l6 = (size_t) (int64_t) t2;
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_resolver_displayable_impl(void* l0, void* l1, vader_string_t l2) {
    void* l3 = NULL;
    void* l5 = NULL;
    void* l8 = NULL;
    vader_string_t l4 = 0;
    vader_string_t l9 = 0;
    vader_string_t l10 = 0;
    size_t l6, l7;
    vader_box_t l11 = vader_box_null();
    void* t0 = NULL;
    vader_string_t t1 = 0;
    int64_t t2;
    vader_box_t* gc_roots[1] = { &l11 };
    void** gc_raw_roots[6] = { &l0, &l1, &l3, &l5, &l8, &t0 };
    vader_string_t* gc_atom_roots[5] = { &l2, &l4, &l9, &l10, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 5u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(13u, 0u, 0u, 244u);
    t0 = (void*) _a0_arr;
    vader_struct_std_string_builder_StringBuilder_t* _a1_obj = (vader_struct_std_string_builder_StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string_builder_StringBuilder_t));
    vader_obj_header_init(_a1_obj, 440u);
    _a1_obj->f_parts = t0;
    l3 = (void*) _a1_obj;
    t1 = ((vader_struct_toolchain_ast_EnumDecl_t*) l0)->f_name;
    l4 = concat_2(t1, 81u);
    std_string_builder_append(l3, l4);
    std_string_builder_append(l3, 14u);
    l5 = ((vader_struct_toolchain_ast_EnumDecl_t*) l0)->f_variants;
    l6 = ((vader_array_t*) l5)->length;
    l7 = (size_t) 0;
    while ((l7 < l6)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l7)
        l8 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l7);
        l4 = ((vader_struct_toolchain_ast_EnumVariant_t*) l8)->f_name;
        l9 = ((vader_struct_toolchain_ast_EnumVariant_t*) l8)->f_name;
        l10 = concat_5(11u, l4, 32u, l9, 180u);
        std_string_builder_append(l3, l10);
        t2 = (l7 + INT64_C(1));
        l7 = (size_t) (int64_t) t2;
    }
    std_string_builder_append(l3, 15u);
    l4 = ((vader_struct_toolchain_ast_EnumDecl_t*) l0)->f_name;
    l4 = concat_4(394u, l2, 184u, l4);
    t1 = std_string_builder_StringBuilder_Display_to_string(l3);
    t0 = vader_parser_parse_source(t1, l4);
    vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_Program_t*) ((vader_struct_vader_parser_ParsedSource_t*) t0)->f_program)->f_decls);
    VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a3_slotarr, INT32_C(0))
    l11 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) INT32_C(0));
    if (l11.tag == 480u) {
        l3 = l11.payload.obj;
        l5 = ((vader_struct_toolchain_ast_Decorator_t*) l1)->f_span;
        ((vader_struct_toolchain_ast_ImplDecl_t*) l3)->f_span = l5;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_ImplDecl_t*) l3);
        l3 = l11.payload.obj;
        vader_array_t* _a4_arr = vader_array_new(27u, 1u, 13u, 456u);
        ((void**) _a4_arr->buf->slots)[_a4_arr->offset + 0u] = l1;
        l5 = (void*) _a4_arr;
        ((vader_struct_toolchain_ast_ImplDecl_t*) l3)->f_decorators = l5;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_ImplDecl_t*) l3);
        { vader_box_t __vret = l11; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_box_t __vret = l11; vader_gc_top = gc_frame.prev; return __vret; }
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
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 12u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l9 = (size_t) 0;
    for (;;) {
        l10 = ((vader_array_t*) l0)->length;
        if ((l9 < l10)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l9)
            l11 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l9);
            t0 = vader_chk_add(usize, l9, INT64_C(1));
            l9 = (size_t) (int64_t) t0;
            l12 = ((vader_struct_vader_resolver_DiscoveredModule_t*) l11)->f_folder;
            t1 = vader_resolver_has_module(l2, l12);
            if (t1) {
                continue;
            }
            vader_resolver_ingest_module(l11, l1, l2, l3, l4, l5, l6, l7, l8);
            l13 = std_collections_MutableMap_Index_at__string__Any(l2, l12);
            if (l13.tag == 0u) {
                continue;
            }
            if (!(l13.tag == 1009u)) {
                vader_unreachable("non-exhaustive match (T3013 should have caught this)");
            }
            t2 = l13.payload.obj;
            l14 = ((vader_struct_vader_resolver_CollectedModule_t*) ((vader_struct_vader_resolver_LoadedModule_t*) t2)->f_collected)->f_import_paths;
            l15 = ((vader_array_t*) l14)->length;
            l16 = (size_t) 0;
            while ((l16 < l15)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) l14);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l16)
                t3 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l16];
                l17 = t3.payload.s;
                l18 = std_collections_MutableMap_Index_at__string__Any(l4, l17);
                if (l18.tag == 1002u) {
                    t2 = l18.payload.obj;
                    l19 = ((vader_struct_vader_resolver_DiscoveredModule_t*) t2)->f_folder;
                    t1 = vader_resolver_has_module(l2, l19);
                    if (!(t1)) {
                        l20 = l18.payload.obj;
                        vader_array_push((vader_array_t*) l0, vader_ref_box(l20));
                    }
                }
                t0 = (l16 + INT64_C(1));
                l16 = (size_t) (int64_t) t0;
            }
            continue;
        }
        break;
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void* vader_resolver_enter_file(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_scope;
    l3 = ((vader_struct_vader_resolver_FileScope_t*) l1)->f_root;
    l2 = vader_resolver_swap_root(l2, l3);
    l3 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_ambiguous;
    vader_struct_vader_resolver_FileScope_t* _a0_obj = (vader_struct_vader_resolver_FileScope_t*) vader_gc_alloc(sizeof(vader_struct_vader_resolver_FileScope_t));
    vader_obj_header_init(_a0_obj, 1004u);
    _a0_obj->f_root = l2;
    _a0_obj->f_ambiguous = l3;
    l2 = (void*) _a0_obj;
    l3 = ((vader_struct_vader_resolver_FileScope_t*) l1)->f_ambiguous;
    ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_ambiguous = l3;
    VADER_WRITE_BARRIER((vader_struct_vader_resolver_ResolveState_t*) l0);
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_resolver_entry_folder_of(vader_string_t l0) {
    vader_string_t l1 = 0;
    bool t0;
    vader_string_t* gc_atom_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = std_io_exists(l0);
    if (t0) {
        t0 = std_io_is_dir(l0);
        if (t0) {
            { vader_string_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    l1 = vader_resolver_dir_of(l0);
    if (!(l1 == 0u)) {
        { vader_string_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return 309u; }
}

void* vader_resolver_file_imports(void* l0, vader_string_t l1) {
    void* l2 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    size_t l3, l4;
    vader_string_t t0 = 0;
    int64_t t1;
    void* t2 = NULL;
    void** gc_raw_roots[7] = { &l0, &l2, &l5, &l6, &l7, &l8, &t2 };
    vader_string_t* gc_atom_roots[2] = { &l1, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 7u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_resolver_CollectedModule_t*) l0)->f_files;
    l3 = ((vader_array_t*) l2)->length;
    l4 = (size_t) 0;
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l5 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        t0 = ((vader_struct_vader_resolver_FileImports_t*) l5)->f_file;
        if (t0 == l1) {
            { void* __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
        }
        t1 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t1;
    }
    vader_array_t* _a1_arr = vader_array_new(13u, 0u, 0u, 244u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(13u, 0u, 0u, 244u);
    l5 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(21u, 0u, 0u, 255u);
    l6 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_new(14u, 0u, 7u, 247u);
    l7 = (void*) _a4_arr;
    vader_struct_std_collections_MutableMap__string__Any___t* _a5_obj = (vader_struct_std_collections_MutableMap__string__Any___t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__Any___t));
    vader_obj_header_init(_a5_obj, 338u);
    _a5_obj->f_ekeys = l5;
    _a5_obj->f_evals = l6;
    _a5_obj->f_index = l7;
    _a5_obj->f_mask = (size_t) 0;
    _a5_obj->f_size = (size_t) 0;
    _a5_obj->f_tombs = (size_t) 0;
    l5 = (void*) _a5_obj;
    vader_array_t* _a6_arr = vader_array_new(13u, 0u, 0u, 244u);
    l6 = (void*) _a6_arr;
    vader_array_t* _a7_arr = vader_array_new(21u, 0u, 0u, 255u);
    l7 = (void*) _a7_arr;
    vader_array_t* _a8_arr = vader_array_new(14u, 0u, 7u, 247u);
    l8 = (void*) _a8_arr;
    vader_struct_std_collections_MutableMap__string__Any_t* _a9_obj = (vader_struct_std_collections_MutableMap__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__Any_t));
    vader_obj_header_init(_a9_obj, 336u);
    _a9_obj->f_ekeys = l6;
    _a9_obj->f_evals = l7;
    _a9_obj->f_index = l8;
    _a9_obj->f_mask = (size_t) 0;
    _a9_obj->f_size = (size_t) 0;
    _a9_obj->f_tombs = (size_t) 0;
    l6 = (void*) _a9_obj;
    vader_struct_vader_resolver_FileImports_t* _a10_obj = (vader_struct_vader_resolver_FileImports_t*) vader_gc_alloc(sizeof(vader_struct_vader_resolver_FileImports_t));
    vader_obj_header_init(_a10_obj, 1003u);
    _a10_obj->f_file = l1;
    _a10_obj->f_paths = l2;
    _a10_obj->f_excludes = l5;
    _a10_obj->f_bindings = l6;
    t2 = (void*) _a10_obj;
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_resolver_file_root_scope(void* l0, void* l1, void* l2, void* l3, void* l4) {
    void* l5 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l13 = NULL;
    size_t l9, l10;
    vader_string_t l11 = 0;
    vader_string_t l12 = 0;
    vader_box_t t0 = vader_box_null();
    int64_t t1;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[10] = { &l0, &l1, &l2, &l3, &l4, &l5, &l6, &l7, &l8, &l13 };
    vader_string_t* gc_atom_roots[2] = { &l11, &l12 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 10u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(13u, 0u, 0u, 244u);
    l5 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(21u, 0u, 0u, 255u);
    l6 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(14u, 0u, 7u, 247u);
    l7 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__string__Any_t* _a3_obj = (vader_struct_std_collections_MutableMap__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__Any_t));
    vader_obj_header_init(_a3_obj, 336u);
    _a3_obj->f_ekeys = l5;
    _a3_obj->f_evals = l6;
    _a3_obj->f_index = l7;
    _a3_obj->f_mask = (size_t) 0;
    _a3_obj->f_size = (size_t) 0;
    _a3_obj->f_tombs = (size_t) 0;
    l5 = (void*) _a3_obj;
    l6 = l0;
    l7 = ((vader_struct_std_collections_MutableMap__string__Symbol_t*) l6)->f_ekeys;
    l8 = ((vader_struct_std_collections_MutableMap__string__Symbol_t*) l6)->f_evals;
    l9 = ((vader_struct_std_collections_MutableMap__string__Symbol_t*) l6)->f_size;
    l10 = (size_t) 0;
    while (!((l10 >= l9))) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l10)
        t0 = vader_array_box_slots(_a4_slotarr->buf)[_a4_slotarr->offset + (size_t) l10];
        l11 = t0.payload.s;
        vader_array_t* _a5_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l10)
        l6 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l10);
        l12 = l11;
        l13 = l6;
        t1 = (l10 + INT64_C(1));
        l10 = (size_t) (int64_t) t1;
        std_collections_MutableMap_IndexSet_set_at__string__Any(l5, l12, vader_ref_box(l13));
    }
    l6 = ((vader_struct_vader_resolver_FileImports_t*) l2)->f_bindings;
    l7 = ((vader_struct_std_collections_MutableMap__string__Symbol_t*) l6)->f_ekeys;
    l8 = ((vader_struct_std_collections_MutableMap__string__Symbol_t*) l6)->f_evals;
    l9 = ((vader_struct_std_collections_MutableMap__string__Symbol_t*) l6)->f_size;
    l10 = (size_t) 0;
    while (!((l10 >= l9))) {
        vader_array_t* _a6_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l10)
        t0 = vader_array_box_slots(_a6_slotarr->buf)[_a6_slotarr->offset + (size_t) l10];
        l11 = t0.payload.s;
        vader_array_t* _a7_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l10)
        l6 = vader_array_ref_load_obj(_a7_slotarr->buf, _a7_slotarr->offset + (size_t) l10);
        l12 = l11;
        l13 = l6;
        t1 = (l10 + INT64_C(1));
        l10 = (size_t) (int64_t) t1;
        std_collections_MutableMap_IndexSet_set_at__string__Any(l5, l12, vader_ref_box(l13));
    }
    l6 = ((vader_struct_vader_resolver_CollectedModule_t*) l1)->f_symbols;
    l7 = ((vader_struct_std_collections_MutableMap__string__Symbol_t*) l6)->f_ekeys;
    l8 = ((vader_struct_std_collections_MutableMap__string__Symbol_t*) l6)->f_evals;
    l9 = ((vader_struct_std_collections_MutableMap__string__Symbol_t*) l6)->f_size;
    l10 = (size_t) 0;
    while (!((l10 >= l9))) {
        vader_array_t* _a8_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l10)
        t0 = vader_array_box_slots(_a8_slotarr->buf)[_a8_slotarr->offset + (size_t) l10];
        l11 = t0.payload.s;
        vader_array_t* _a9_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l10)
        l6 = vader_array_ref_load_obj(_a9_slotarr->buf, _a9_slotarr->offset + (size_t) l10);
        l12 = l11;
        l13 = l6;
        t1 = (l10 + INT64_C(1));
        l10 = (size_t) (int64_t) t1;
        std_collections_MutableMap_IndexSet_set_at__string__Any(l5, l12, vader_ref_box(l13));
    }
    l6 = l4;
    l7 = ((vader_struct_std_collections_MutableMap__string__Symbol_t*) l6)->f_ekeys;
    l8 = ((vader_struct_std_collections_MutableMap__string__Symbol_t*) l6)->f_evals;
    l9 = ((vader_struct_std_collections_MutableMap__string__Symbol_t*) l6)->f_size;
    l10 = (size_t) 0;
    while (!((l10 >= l9))) {
        vader_array_t* _a10_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a10_slotarr, l10)
        t0 = vader_array_box_slots(_a10_slotarr->buf)[_a10_slotarr->offset + (size_t) l10];
        l11 = t0.payload.s;
        vader_array_t* _a11_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l10)
        l6 = vader_array_ref_load_obj(_a11_slotarr->buf, _a11_slotarr->offset + (size_t) l10);
        l12 = l11;
        l13 = l6;
        t1 = (l10 + INT64_C(1));
        l10 = (size_t) (int64_t) t1;
        t0 = std_collections_MutableMap_Index_at__string__Any(l5, l12);
        if (!(t0.tag == 0u)) {
            continue;
        }
        std_collections_MutableMap_IndexSet_set_at__string__Any(l5, l12, vader_ref_box(l13));
    }
    l6 = ((vader_struct_vader_resolver_FileImports_t*) l2)->f_paths;
    l7 = ((vader_struct_vader_resolver_FileImports_t*) l2)->f_excludes;
    vader_resolver_seed_wildcard_exports(l5, l3, l6, l7);
    { void* __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_resolver_find_async_module_id(void* l0) {
    void* l1;
    void* l2;
    void* l3;
    size_t l4, l5;
    vader_string_t l6, l7;
    vader_box_t t0;
    void* t1;
    int64_t t2;
    bool t3;
    l1 = ((vader_struct_vader_resolver_LoadedProject_t*) l0)->f_modules;
    l2 = ((vader_struct_std_collections_MutableMap__string__LoadedModule_t*) l1)->f_ekeys;
    l3 = ((vader_struct_std_collections_MutableMap__string__LoadedModule_t*) l1)->f_evals;
    l4 = ((vader_struct_std_collections_MutableMap__string__LoadedModule_t*) l1)->f_size;
    l5 = (size_t) 0;
    for (;;) {
        if (!((l5 >= l4))) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
            t0 = vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l5];
            l6 = t0.payload.s;
            vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
            t1 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5);
            l7 = l6;
            t2 = (l5 + INT64_C(1));
            l5 = (size_t) (int64_t) t2;
            t3 = std_string_ends_with(l7, 2229u);
            if (t3) {
                t0 = vader_box_string(244u, l7);
                return t0;
            }
            t3 = std_string_ends_with(l7, 2228u);
            if (!(t3)) {
                continue;
            }
            t0 = vader_box_string(244u, l7);
            return t0;
        }
        break;
    }
    return vader_box_obj(0u, NULL);
}

vader_box_t vader_resolver_find_core_module_id(void* l0) {
    void* l1;
    void* l2;
    void* l3;
    size_t l4, l5;
    vader_string_t l6, l7;
    vader_box_t t0;
    void* t1;
    int64_t t2;
    bool t3;
    l1 = ((vader_struct_vader_resolver_LoadedProject_t*) l0)->f_modules;
    l2 = ((vader_struct_std_collections_MutableMap__string__LoadedModule_t*) l1)->f_ekeys;
    l3 = ((vader_struct_std_collections_MutableMap__string__LoadedModule_t*) l1)->f_evals;
    l4 = ((vader_struct_std_collections_MutableMap__string__LoadedModule_t*) l1)->f_size;
    l5 = (size_t) 0;
    for (;;) {
        if (!((l5 >= l4))) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
            t0 = vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l5];
            l6 = t0.payload.s;
            vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
            t1 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5);
            l7 = l6;
            t2 = (l5 + INT64_C(1));
            l5 = (size_t) (int64_t) t2;
            t3 = std_string_ends_with(l7, 2232u);
            if (t3) {
                t0 = vader_box_string(244u, l7);
                return t0;
            }
            t3 = std_string_ends_with(l7, 2231u);
            if (!(t3)) {
                continue;
            }
            t0 = vader_box_string(244u, l7);
            return t0;
        }
        break;
    }
    return vader_box_obj(0u, NULL);
}

static vader_box_t vader_resolver_find_manifest_root(vader_string_t l0) {
    vader_string_t l1 = 0;
    vader_string_t l2 = 0;
    bool t0;
    vader_string_t t1 = 0;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t2 };
    vader_string_t* gc_atom_roots[4] = { &l0, &l1, &l2, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 0u, gc_roots, NULL, 0u, NULL, 4u, gc_atom_roots,
    };
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
    for (;;) {
        t1 = vader_resolver_join_path(l1, 2487u);
        t0 = std_io_exists(t1);
        if (!(t0)) {
            l2 = vader_resolver_dir_of(l1);
            if (l2 == l1) {
                { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
            }
            l1 = l2;
            continue;
        }
        break;
    }
    t2 = vader_box_string(244u, l1);
    { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_resolver_for_type_display_name(vader_box_t l0) {
    vader_box_t l1 = vader_box_null();
    void* t0 = NULL;
    void* t3 = NULL;
    vader_string_t t1 = 0;
    vader_string_t t2 = 0;
    vader_box_t* gc_roots[2] = { &l0, &l1 };
    void** gc_raw_roots[2] = { &t0, &t3 };
    vader_string_t* gc_atom_roots[2] = { &t1, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l0.tag == 441u) {
        t0 = l0.payload.obj;
        l1 = toolchain_ast_strip_mut_marker(((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t0)->f_element);
        if (l1.tag == 0u) {
            { vader_gc_top = gc_frame.prev; return 414u; }
        }
        t1 = vader_resolver_for_type_display_name(l1);
        t2 = concat_2(t1, 801u);
        { vader_string_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 476u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_toolchain_ast_IdentExpr_t*) t0)->f_name;
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 475u) {
        t0 = l0.payload.obj;
        if (((vader_struct_toolchain_ast_GenericInstExpr_t*) t0)->f_callee.tag == 476u) {
            t0 = l0.payload.obj;
            t3 = ((vader_struct_toolchain_ast_GenericInstExpr_t*) t0)->f_callee.payload.obj;
            t1 = ((vader_struct_toolchain_ast_IdentExpr_t*) t3)->f_name;
            { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
        }
        { vader_gc_top = gc_frame.prev; return 412u; }
    }
    { vader_gc_top = gc_frame.prev; return 412u; }
}

static vader_box_t vader_resolver_for_type_owner_sym(vader_box_t l0, void* l1, void* l2) {
    vader_box_t l3;
    void* l4;
    uint64_t l5;
    void* t0;
    void* t1;
    if (l0.tag == 441u) {
        t0 = l0.payload.obj;
        l3 = toolchain_ast_strip_mut_marker(((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t0)->f_element);
        if (l3.tag == 0u) {
            return vader_box_obj(0u, NULL);
        }
        l3 = vader_resolver_for_type_owner_sym(l3, l1, l2);
        if (l3.tag == 0u) {
            return vader_box_obj(0u, NULL);
        }
        l4 = l3.payload.obj;
        if (((vader_struct_vader_resolver_symbol_Symbol_t*) l4)->f_kind == INT32_C(9)) {
            return vader_box_obj(0u, NULL);
        }
        return vader_ref_box(l4);
    }
    if (l0.tag == 476u) {
        t0 = l0.payload.obj;
        l5 = toolchain_span_Span_Hash_hash(((vader_struct_toolchain_ast_IdentExpr_t*) t0)->f_span);
        l3 = std_collections_MutableMap_Index_at__u64__Any(l1, l5);
        if (l3.tag == 0u) {
            return vader_box_obj(0u, NULL);
        }
        t0 = l3.payload.obj;
        t1 = vader_resolver_resolve_import_redirect(t0, l2);
        return vader_ref_box(t1);
    }
    if (l0.tag == 475u) {
        t0 = l0.payload.obj;
        if (((vader_struct_toolchain_ast_GenericInstExpr_t*) t0)->f_callee.tag == 476u) {
            t0 = l0.payload.obj;
            t1 = ((vader_struct_toolchain_ast_GenericInstExpr_t*) t0)->f_callee.payload.obj;
            l5 = toolchain_span_Span_Hash_hash(((vader_struct_toolchain_ast_IdentExpr_t*) t1)->f_span);
            l3 = std_collections_MutableMap_Index_at__u64__Any(l1, l5);
            if (l3.tag == 0u) {
                return vader_box_obj(0u, NULL);
            }
            t0 = l3.payload.obj;
            t1 = vader_resolver_resolve_import_redirect(t0, l2);
            return vader_ref_box(t1);
        }
        return vader_box_obj(0u, NULL);
    }
    return vader_box_obj(0u, NULL);
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
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 0u, gc_roots, NULL, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l0.tag == 244u) {
        l1 = l0.payload.s;
    } else {
        if (!(l0.tag == 0u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = std_io_current_working_directory();
    }
    l1 = vader_resolver_join_path(l1, 1385u);
    t0 = std_io_is_dir(l1);
    if (!(t0)) {
        { vader_gc_top = gc_frame.prev; return 0u; }
    }
    { vader_string_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_resolver_graft_body(void* l0, void* l1) {
    void* l2 = NULL;
    void* l4 = NULL;
    void* l6 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    size_t l3, l5;
    bool l7, l14, l15;
    vader_string_t l8 = 0;
    uint8_t l9;
    vader_box_t l12 = vader_box_null(), l13 = vader_box_null();
    int64_t t0;
    vader_string_t t1 = 0;
    void* t2 = NULL;
    vader_box_t* gc_roots[2] = { &l12, &l13 };
    void** gc_raw_roots[8] = { &l0, &l1, &l2, &l4, &l6, &l10, &l11, &t2 };
    vader_string_t* gc_atom_roots[2] = { &l8, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(27u, 0u, 13u, 456u);
    l2 = (void*) _a0_arr;
    l3 = ((vader_array_t*) ((vader_struct_toolchain_ast_FnDecl_t*) l0)->f_decorators)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l2, (size_t) l3);
    l2 = (void*) _a1_arr;
    l4 = ((vader_struct_toolchain_ast_FnDecl_t*) l0)->f_decorators;
    l3 = ((vader_array_t*) l4)->length;
    l5 = (size_t) 0;
    while ((l5 < l3)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l5)
        l6 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l5);
        vader_array_push((vader_array_t*) l2, vader_ref_box(l6));
        t0 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t0;
    }
    l4 = ((vader_struct_toolchain_ast_FnDecl_t*) l1)->f_decorators;
    l3 = ((vader_array_t*) l4)->length;
    l5 = (size_t) 0;
    while ((l5 < l3)) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l5)
        l6 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l5);
        t1 = ((vader_struct_toolchain_ast_Decorator_t*) l6)->f_name;
        if (t1 == 1642u) {
            l7 = true;
        } else {
            t1 = ((vader_struct_toolchain_ast_Decorator_t*) l6)->f_name;
            l7 = t1 == 1874u;
        }
        if (l7) {
            vader_array_push((vader_array_t*) l2, vader_ref_box(l6));
        }
        t0 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t0;
    }
    l4 = ((vader_struct_toolchain_ast_FnDecl_t*) l0)->f_span;
    l3 = ((vader_struct_toolchain_ast_FnDecl_t*) l0)->f_id;
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
    vader_struct_toolchain_ast_FnDecl_t* _a4_obj = (vader_struct_toolchain_ast_FnDecl_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_FnDecl_t));
    vader_obj_header_init(_a4_obj, 471u);
    _a4_obj->f_span = l4;
    _a4_obj->f_id = l3;
    _a4_obj->f_name = l8;
    _a4_obj->f_name_span = l6;
    _a4_obj->f_visibility = l9;
    _a4_obj->f_type_params = l10;
    _a4_obj->f_params = l11;
    _a4_obj->f_return_type = l12;
    _a4_obj->f_body = l13;
    _a4_obj->f_decorators = l2;
    _a4_obj->f_sam_synthetic = l7;
    _a4_obj->f_is_expression_bodied = l14;
    _a4_obj->f_materialized = l15;
    _a4_obj->f_comptime_synthetic = false;
    _a4_obj->f_trailing_comma = false;
    t2 = (void*) _a4_obj;
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_resolver_has_module(void* l0, vader_string_t l1) {
    vader_box_t t0;
    t0 = std_collections_MutableMap_Index_at__string__Any(l0, l1);
    return !(t0.tag == 0u);
}

static bool vader_resolver_has_reassignment(void* l0, void* l1) {
    void* l2;
    void* l5;
    void* l6;
    size_t l3, l4;
    int32_t l7;
    bool t0;
    int64_t t1;
    l2 = l1;
    l3 = ((vader_array_t*) l2)->length;
    l4 = (size_t) 0;
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l5 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        l6 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_reassigned;
        l7 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l5)->f_id;
        t0 = std_collections_MutableSet_Contains_contains__i32(l6, l7);
        if (t0) {
            return true;
        }
        t1 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t1;
    }
    return false;
}

static vader_box_t vader_resolver_home_root(vader_string_t l0, vader_string_t l1) {
    vader_string_t l2 = 0;
    vader_box_t l3 = vader_box_null();
    vader_string_t t0 = 0;
    bool t1;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l3, &t2 };
    vader_string_t* gc_atom_roots[4] = { &l0, &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 0u, gc_roots, NULL, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = vader_host_std_env_get_env(771u);
    if (l3.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l2 = l3.payload.s;
    if (l2 == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l2 = vader_resolver_join_path(l2, l0);
    t0 = vader_resolver_join_path(l2, l1);
    t1 = std_io_exists(t0);
    if (!(t1)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    t2 = vader_box_string(244u, l2);
    { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static uint8_t vader_resolver_importer_origin(void* l0, vader_string_t l1) {
    void* l2;
    vader_box_t l3;
    l3 = std_collections_MutableMap_Index_at__string__Any(l0, l1);
    if (l3.tag == 0u) {
        return (uint8_t) 0;
    }
    l2 = l3.payload.obj;
    return ((vader_struct_vader_resolver_DiscoveredModule_t*) l2)->f_origin;
}

static void* vader_resolver_include_paths(vader_string_t l0, vader_string_t l1, void* l2, vader_string_t l3) {
    void* l4 = NULL;
    void* l5 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[4] = { &l2, &l4, &l5, &t0 };
    vader_string_t* gc_atom_roots[3] = { &l0, &l1, &l3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_struct_vader_resolver_IncludePath_t* _a0_obj = (vader_struct_vader_resolver_IncludePath_t*) vader_gc_alloc(sizeof(vader_struct_vader_resolver_IncludePath_t));
    vader_obj_header_init(_a0_obj, 1008u);
    _a0_obj->f_dir = l1;
    _a0_obj->f_prefix = l0;
    _a0_obj->f_merge = false;
    _a0_obj->f_origin = (uint8_t) 0;
    t0 = (void*) _a0_obj;
    vader_array_t* _a1_arr = vader_array_new(120u, 1u, 13u, 1008u);
    ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = t0;
    l4 = (void*) _a1_arr;
    vader_array_push_all((vader_array_t*) l4, (vader_array_t*) l2);
    if (l3 != 0u) {
        vader_struct_vader_resolver_IncludePath_t* _a2_obj = (vader_struct_vader_resolver_IncludePath_t*) vader_gc_alloc(sizeof(vader_struct_vader_resolver_IncludePath_t));
        vader_obj_header_init(_a2_obj, 1008u);
        _a2_obj->f_dir = l3;
        _a2_obj->f_prefix = 0u;
        _a2_obj->f_merge = true;
        _a2_obj->f_origin = (uint8_t) 0;
        l5 = (void*) _a2_obj;
        vader_array_push((vader_array_t*) l4, vader_ref_box(l5));
        { void* __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { void* __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
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
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 12u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_vader_resolver_DiscoveredModule_t*) l0)->f_files)->length;
    if (t0 == INT64_C(0)) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l9 = vader_resolver_parse_module_files(((vader_struct_vader_resolver_DiscoveredModule_t*) l0)->f_files, l5, l6, l7);
    t0 = ((vader_array_t*) l9)->length;
    if (!(t0 == INT64_C(0))) {
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
        vader_obj_header_init(_a0_obj, 1012u);
        _a0_obj->f_id = l12;
        _a0_obj->f_display_path = l14;
        _a0_obj->f_module_name = l15;
        _a0_obj->f_origin = l16;
        _a0_obj->f_files = l9;
        t1 = (void*) _a0_obj;
        vader_struct_vader_resolver_LoadedModule_t* _a1_obj = (vader_struct_vader_resolver_LoadedModule_t*) vader_gc_alloc(sizeof(vader_struct_vader_resolver_LoadedModule_t));
        vader_obj_header_init(_a1_obj, 1009u);
        _a1_obj->f_module = t1;
        _a1_obj->f_collected = l13;
        _a1_obj->f_node_id_factory = l7;
        _a1_obj->f_discarded_bodies = l10;
        l9 = (void*) _a1_obj;
        std_collections_MutableMap_IndexSet_set_at__string__Any(l2, l11, vader_ref_box(l9));
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void* vader_resolver_intrinsic_decorator(void* l0) {
    void* l1 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[3] = { &l0, &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(179u, 0u, 13u, 1259u);
    l1 = (void*) _a0_arr;
    vader_struct_toolchain_ast_Decorator_t* _a1_obj = (vader_struct_toolchain_ast_Decorator_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_Decorator_t));
    vader_obj_header_init(_a1_obj, 456u);
    _a1_obj->f_span = l0;
    _a1_obj->f_id = (size_t) 0;
    _a1_obj->f_name = 1874u;
    _a1_obj->f_args = l1;
    t0 = (void*) _a1_obj;
    vader_array_t* _a2_arr = vader_array_new(27u, 1u, 13u, 456u);
    ((void**) _a2_arr->buf->slots)[_a2_arr->offset + 0u] = t0;
    t0 = (void*) _a2_arr;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_resolver_is_host_bound(void* l0) {
    void* l1;
    void* l4;
    size_t l2, l3;
    vader_string_t t0;
    int64_t t1;
    l1 = ((vader_struct_toolchain_ast_FnDecl_t*) l0)->f_decorators;
    l2 = ((vader_array_t*) l1)->length;
    l3 = (size_t) 0;
    while ((l3 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l4 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
        t0 = ((vader_struct_toolchain_ast_Decorator_t*) l4)->f_name;
        if (t0 == 1874u) {
            return true;
        }
        t0 = ((vader_struct_toolchain_ast_Decorator_t*) l4)->f_name;
        if (t0 == 1642u) {
            return true;
        }
        t1 = (l3 + INT64_C(1));
        l3 = (size_t) (int64_t) t1;
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
    l2 = ((vader_array_t*) l1)->length;
    l3 = (size_t) 0;
    while ((l3 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
        t1 = ((vader_struct_toolchain_ast_Decorator_t*) t0)->f_name;
        if (t1 == 1874u) {
            return true;
        }
        t2 = (l3 + INT64_C(1));
        l3 = (size_t) (int64_t) t2;
    }
    return false;
}

static bool vader_resolver_is_known_decorator(vader_string_t l0) {
    bool l1;
    if (l0 == 1484u) {
        l1 = true;
    } else {
        l1 = l0 == 1642u;
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == 1628u;
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == 2334u;
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == 1874u;
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == 1539u;
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == 1323u;
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == 2059u;
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == 1251u;
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == 2331u;
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == 1420u;
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == 1422u;
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == 1421u;
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == 1423u;
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == 1424u;
    }
    if (l1) {
        return true;
    }
    return l0 == 1546u;
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
    l2 = std_string_trim_prefix(l1, 315u);
    if (l0 == 0u) {
        { vader_string_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_host_std_core_byte_len(l0);
    t1 = vader_chk_sub(usize, t0, INT64_C(1));
    l3 = (size_t) (int64_t) t1;
    t2 = vader_host_std_core_byte_at(l0, l3);
    if (!(t2 == INT32_C(47))) {
        t3 = concat_3(l0, 336u, l2);
        { vader_string_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t3 = concat_2(l0, l2);
    { vader_string_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_resolver_load_baked_target(void* l0, void* l1, void* l2, void* l3, void* l4, void* l5, void* l6, void* l7) {
    void* l8 = NULL;
    void* l11 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    vader_box_t l9 = vader_box_null();
    vader_string_t l10 = 0;
    vader_string_t l16 = 0;
    vader_string_t l17 = 0;
    vader_string_t l18 = 0;
    size_t l14, l15;
    bool t0;
    void* t1 = NULL;
    vader_box_t t2 = vader_box_null();
    int64_t t3;
    vader_box_t* gc_roots[2] = { &l9, &t2 };
    void** gc_raw_roots[13] = {
        &l0, &l1, &l2, &l3, &l4, &l5, &l6, &l7, &l8, &l11, &l12, &l13, &t1,
    };
    vader_string_t* gc_atom_roots[4] = { &l10, &l16, &l17, &l18 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 13u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l9 = vader_resolver_resolve_lazy(2235u, l1, l2, l3);
    if (l9.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l8 = l9.payload.obj;
    l10 = ((vader_struct_vader_resolver_DiscoveredModule_t*) l8)->f_folder;
    t0 = vader_resolver_has_module(l0, l10);
    if (!(t0)) {
        vader_array_t* _a0_arr = vader_array_new(117u, 1u, 13u, 1002u);
        ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = l8;
        t1 = (void*) _a0_arr;
        vader_resolver_drain_load_queue(t1, l1, l0, l5, l2, l3, l4, l6, vader_ref_box(l7));
    }
    vader_array_t* _a1_arr = vader_array_new(13u, 0u, 0u, 244u);
    l8 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(13u, 0u, 0u, 244u);
    l11 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(14u, 0u, 7u, 247u);
    l12 = (void*) _a3_arr;
    vader_struct_std_collections_MutableMap__string__string_t* _a4_obj = (vader_struct_std_collections_MutableMap__string__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__string_t));
    vader_obj_header_init(_a4_obj, 388u);
    _a4_obj->f_ekeys = l8;
    _a4_obj->f_evals = l11;
    _a4_obj->f_index = l12;
    _a4_obj->f_mask = (size_t) 0;
    _a4_obj->f_size = (size_t) 0;
    _a4_obj->f_tombs = (size_t) 0;
    l8 = (void*) _a4_obj;
    l11 = l4;
    l12 = ((vader_struct_std_collections_MutableMap__string__string_t*) l11)->f_ekeys;
    l13 = ((vader_struct_std_collections_MutableMap__string__string_t*) l11)->f_evals;
    l14 = ((vader_struct_std_collections_MutableMap__string__string_t*) l11)->f_size;
    l15 = (size_t) 0;
    while (!((l15 >= l14))) {
        vader_array_t* _a5_slotarr = ((vader_array_t*) l12);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l15)
        t2 = vader_array_box_slots(_a5_slotarr->buf)[_a5_slotarr->offset + (size_t) l15];
        l10 = t2.payload.s;
        vader_array_t* _a6_slotarr = ((vader_array_t*) l13);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l15)
        t2 = vader_array_box_slots(_a6_slotarr->buf)[_a6_slotarr->offset + (size_t) l15];
        l16 = t2.payload.s;
        l17 = l10;
        l18 = l16;
        t3 = (l15 + INT64_C(1));
        l15 = (size_t) (int64_t) t3;
        std_collections_MutableMap_IndexSet_set_at__string__string(l8, l17, l18);
    }
    l10 = vader_target_baked_module_source(l7);
    std_collections_MutableMap_IndexSet_set_at__string__string(l8, 390u, l10);
    vader_array_t* _a7_arr = vader_array_new(13u, 1u, 0u, 244u);
    vader_array_box_slots(_a7_arr->buf)[_a7_arr->offset + 0u] = vader_box_string(244u, 390u);
    l11 = (void*) _a7_arr;
    vader_struct_vader_resolver_DiscoveredModule_t* _a8_obj = (vader_struct_vader_resolver_DiscoveredModule_t*) vader_gc_alloc(sizeof(vader_struct_vader_resolver_DiscoveredModule_t));
    vader_obj_header_init(_a8_obj, 1002u);
    _a8_obj->f_name = 2236u;
    _a8_obj->f_folder = 389u;
    _a8_obj->f_files = l11;
    _a8_obj->f_origin = (uint8_t) 1;
    t1 = (void*) _a8_obj;
    vader_array_t* _a9_arr = vader_array_new(117u, 1u, 13u, 1002u);
    ((void**) _a9_arr->buf->slots)[_a9_arr->offset + 0u] = t1;
    t1 = (void*) _a9_arr;
    vader_resolver_drain_load_queue(t1, l1, l0, l5, l2, l3, l8, l6, vader_ref_box(l7));
    { vader_gc_top = gc_frame.prev; return; }
}

void* vader_resolver_load_project(vader_string_t l0, void* l1, vader_box_t l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[5] = { &l1, &l3, &l4, &l5, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(13u, 0u, 0u, 244u);
    l3 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(13u, 0u, 0u, 244u);
    l4 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(14u, 0u, 7u, 247u);
    l5 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__string__string_t* _a3_obj = (vader_struct_std_collections_MutableMap__string__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__string_t));
    vader_obj_header_init(_a3_obj, 388u);
    _a3_obj->f_ekeys = l3;
    _a3_obj->f_evals = l4;
    _a3_obj->f_index = l5;
    _a3_obj->f_mask = (size_t) 0;
    _a3_obj->f_size = (size_t) 0;
    _a3_obj->f_tombs = (size_t) 0;
    l3 = (void*) _a3_obj;
    t0 = vader_resolver_load_project_with_overlay(l0, l3, l1, l2);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_resolver_load_project_with_overlay(vader_string_t l0, void* l1, void* l2, vader_box_t l3) {
    void* l4 = NULL;
    void* l5 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    void* l15 = NULL;
    vader_string_t l6 = 0;
    vader_string_t l17 = 0;
    vader_box_t l7 = vader_box_null(), l8 = vader_box_null(), l16 = vader_box_null(), l18 = vader_box_null();
    void* t0 = NULL;
    vader_string_t t1 = 0;
    bool t2;
    vader_box_t* gc_roots[5] = { &l3, &l7, &l8, &l16, &l18 };
    void** gc_raw_roots[12] = { &l1, &l2, &l4, &l5, &l9, &l10, &l11, &l12, &l13, &l14, &l15, &t0 };
    vader_string_t* gc_atom_roots[4] = { &l0, &l6, &l17, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 5u, 12u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_struct_vader_resolver_symbol_SymbolFactory_t* _a0_obj = (vader_struct_vader_resolver_symbol_SymbolFactory_t*) vader_gc_alloc(sizeof(vader_struct_vader_resolver_symbol_SymbolFactory_t));
    vader_obj_header_init(_a0_obj, 1025u);
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
    if (l7.tag == 1027u) {
        l9 = vader_target_host_target();
    } else {
        l9 = l7.payload.obj;
    }
    if (l7.tag == 1027u) {
        l8 = vader_box_obj(0u, NULL);
    } else {
        t0 = l7.payload.obj;
        l8 = vader_ref_box(t0);
    }
    vader_array_t* _a1_arr = vader_array_new(13u, 0u, 0u, 244u);
    l10 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(21u, 0u, 0u, 255u);
    l11 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(14u, 0u, 7u, 247u);
    l12 = (void*) _a3_arr;
    vader_struct_std_collections_MutableMap__string__Any_t* _a4_obj = (vader_struct_std_collections_MutableMap__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__Any_t));
    vader_obj_header_init(_a4_obj, 336u);
    _a4_obj->f_ekeys = l10;
    _a4_obj->f_evals = l11;
    _a4_obj->f_index = l12;
    _a4_obj->f_mask = (size_t) 0;
    _a4_obj->f_size = (size_t) 0;
    _a4_obj->f_tombs = (size_t) 0;
    l10 = (void*) _a4_obj;
    vader_array_t* _a5_arr = vader_array_new(75u, 0u, 13u, 811u);
    l11 = (void*) _a5_arr;
    l12 = vader_resolver_search_roots(l6, l2, l11);
    l7 = ((vader_struct_vader_resolver_SearchRoots_t*) l12)->f_project_root;
    vader_array_t* _a6_arr = vader_array_new(13u, 0u, 0u, 244u);
    l13 = (void*) _a6_arr;
    vader_array_t* _a7_arr = vader_array_new(21u, 0u, 0u, 255u);
    l14 = (void*) _a7_arr;
    vader_array_t* _a8_arr = vader_array_new(14u, 0u, 7u, 247u);
    l15 = (void*) _a8_arr;
    vader_struct_std_collections_MutableMap__string__Any_t* _a9_obj = (vader_struct_std_collections_MutableMap__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__Any_t));
    vader_obj_header_init(_a9_obj, 336u);
    _a9_obj->f_ekeys = l13;
    _a9_obj->f_evals = l14;
    _a9_obj->f_index = l15;
    _a9_obj->f_mask = (size_t) 0;
    _a9_obj->f_size = (size_t) 0;
    _a9_obj->f_tombs = (size_t) 0;
    l13 = (void*) _a9_obj;
    l16 = ((vader_struct_vader_resolver_SearchRoots_t*) l12)->f_entry;
    if (l16.tag == 0u) {
        l17 = vader_resolver_entry_folder_of(l6);
        l14 = vader_resolver_zero_span(l6);
        t1 = concat_3(2049u, l17, 915u);
        l6 = concat_2(t1, 1245u);
        l14 = vader_diagnostics_resolver_error((uint8_t) 0, l14, l6);
        vader_array_push((vader_array_t*) l11, vader_ref_box(l14));
        vader_struct_vader_resolver_LoadedProject_t* _a10_obj = (vader_struct_vader_resolver_LoadedProject_t*) vader_gc_alloc(sizeof(vader_struct_vader_resolver_LoadedProject_t));
        vader_obj_header_init(_a10_obj, 1010u);
        _a10_obj->f_entry = l17;
        _a10_obj->f_modules = l10;
        _a10_obj->f_factory = l4;
        _a10_obj->f_project_root = l7;
        _a10_obj->f_diags = l11;
        t0 = (void*) _a10_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l16.tag == 1002u)) {
        vader_unreachable("non-exhaustive match (T3013 should have caught this)");
    }
    l12 = ((vader_struct_vader_resolver_SearchRoots_t*) l12)->f_paths;
    t0 = l16.payload.obj;
    t1 = ((vader_struct_vader_resolver_DiscoveredModule_t*) t0)->f_name;
    l18 = vader_resolver_resolve_lazy(t1, l12, l13, l11);
    if (l18.tag == 0u) {
        l14 = l16.payload.obj;
    } else {
        l14 = l18.payload.obj;
    }
    vader_array_t* _a11_arr = vader_array_new(117u, 1u, 13u, 1002u);
    ((void**) _a11_arr->buf->slots)[_a11_arr->offset + 0u] = l14;
    l14 = (void*) _a11_arr;
    l18 = vader_resolver_resolve_lazy(2231u, l12, l13, l11);
    if (l18.tag == 1002u) {
        t0 = l18.payload.obj;
        l6 = ((vader_struct_vader_resolver_DiscoveredModule_t*) t0)->f_folder;
        t0 = l16.payload.obj;
        l17 = ((vader_struct_vader_resolver_DiscoveredModule_t*) t0)->f_folder;
        if (l6 != l17) {
            l15 = l18.payload.obj;
            vader_array_push((vader_array_t*) l14, vader_ref_box(l15));
        }
    }
    vader_resolver_drain_load_queue(l14, l12, l10, l4, l13, l11, l1, l5, l8);
    l18 = vader_resolver_resolve_lazy(2234u, l12, l13, l11);
    if (l18.tag == 1002u) {
        t0 = l18.payload.obj;
        l6 = ((vader_struct_vader_resolver_DiscoveredModule_t*) t0)->f_folder;
        t2 = vader_resolver_has_module(l10, l6);
        if (!(t2)) {
            t0 = l18.payload.obj;
            vader_array_t* _a12_arr = vader_array_new(117u, 1u, 13u, 1002u);
            ((void**) _a12_arr->buf->slots)[_a12_arr->offset + 0u] = t0;
            t0 = (void*) _a12_arr;
            vader_resolver_drain_load_queue(t0, l12, l10, l4, l13, l11, l1, l5, l8);
        }
    }
    vader_resolver_load_baked_target(l10, l12, l13, l11, l1, l4, l5, l9);
    vader_resolver_detect_import_cycles(l10, l13, l11);
    t0 = l16.payload.obj;
    t1 = ((vader_struct_vader_resolver_DiscoveredModule_t*) t0)->f_folder;
    vader_struct_vader_resolver_LoadedProject_t* _a13_obj = (vader_struct_vader_resolver_LoadedProject_t*) vader_gc_alloc(sizeof(vader_struct_vader_resolver_LoadedProject_t));
    vader_obj_header_init(_a13_obj, 1010u);
    _a13_obj->f_entry = t1;
    _a13_obj->f_modules = l10;
    _a13_obj->f_factory = l4;
    _a13_obj->f_project_root = l7;
    _a13_obj->f_diags = l11;
    t0 = (void*) _a13_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_resolver_lookup(void* l0, vader_string_t l1) {
    size_t l2;
    vader_box_t l3;
    int64_t t0;
    void* t1;
    l2 = ((vader_array_t*) ((vader_struct_vader_resolver_Scope_t*) l0)->f_frames)->length;
    while ((l2 > INT64_C(0))) {
        t0 = vader_chk_sub(usize, l2, INT64_C(1));
        l2 = (size_t) (int64_t) t0;
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_resolver_Scope_t*) l0)->f_frames);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
        t1 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
        l3 = std_collections_MutableMap_Index_at__string__Any(t1, l1);
        if (l3.tag == 1024u) {
            t1 = l3.payload.obj;
            return vader_ref_box(t1);
        }
        if (!(l3.tag == 0u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
    }
    return vader_box_obj(0u, NULL);
}

static int32_t vader_resolver_lookup_frame_index(void* l0, vader_string_t l1) {
    size_t l2;
    int64_t t0;
    void* t1;
    vader_box_t t2;
    l2 = ((vader_array_t*) ((vader_struct_vader_resolver_Scope_t*) l0)->f_frames)->length;
    while ((l2 > INT64_C(0))) {
        t0 = vader_chk_sub(usize, l2, INT64_C(1));
        l2 = (size_t) (int64_t) t0;
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_resolver_Scope_t*) l0)->f_frames);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
        t1 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
        t2 = std_collections_MutableMap_Index_at__string__Any(t1, l1);
        if (!(t2.tag == 0u)) {
            return ((int32_t) (size_t) l2);
        }
    }
    return INT32_C(-1);
}

static vader_box_t vader_resolver_lookup_subst(void* l0, vader_string_t l1) {
    vader_box_t t0;
    t0 = std_collections_MutableMap_Index_at__string__Any(((vader_struct_vader_resolver_Subst_t*) l0)->f_entries, l1);
    return t0;
}

static vader_box_t vader_resolver_lookup_trait_sym(void* l0, void* l1, void* l2, void* l3) {
    vader_string_t l4;
    vader_box_t l5;
    vader_box_t t0;
    void* t1;
    void* t2;
    l4 = ((vader_struct_toolchain_ast_ImplDecl_t*) l0)->f_trait_name;
    t0 = std_collections_MutableMap_Index_at__string__Any(l1, l4);
    if (t0.tag == 1024u) {
        l4 = ((vader_struct_toolchain_ast_ImplDecl_t*) l0)->f_trait_name;
        t0 = std_collections_MutableMap_Index_at__string__Any(l1, l4);
        t1 = t0.payload.obj;
        t2 = vader_resolver_resolve_import_redirect(t1, l3);
        return vader_ref_box(t2);
    }
    l4 = ((vader_struct_toolchain_ast_ImplDecl_t*) l0)->f_trait_name;
    l5 = std_collections_MutableMap_Index_at__string__Any(l2, l4);
    if (l5.tag == 0u) {
        return vader_box_obj(0u, NULL);
    }
    t1 = l5.payload.obj;
    t2 = vader_resolver_resolve_import_redirect(t1, l3);
    return vader_ref_box(t2);
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
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(13u, 0u, 0u, 244u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(21u, 0u, 0u, 255u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(14u, 0u, 7u, 247u);
    l3 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__string__Any_t* _a3_obj = (vader_struct_std_collections_MutableMap__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__Any_t));
    vader_obj_header_init(_a3_obj, 336u);
    _a3_obj->f_ekeys = l1;
    _a3_obj->f_evals = l2;
    _a3_obj->f_index = l3;
    _a3_obj->f_mask = (size_t) 0;
    _a3_obj->f_size = (size_t) 0;
    _a3_obj->f_tombs = (size_t) 0;
    l1 = (void*) _a3_obj;
    l2 = vader_resolver_builtin_type_names();
    l4 = ((vader_array_t*) l2)->length;
    l5 = (size_t) 0;
    while ((l5 < l4)) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l5)
        t0 = vader_array_box_slots(_a4_slotarr->buf)[_a4_slotarr->offset + (size_t) l5];
        l6 = t0.payload.s;
        l3 = vader_resolver_symbol_make(l0, (uint8_t) 12, l6, 391u, 391u, (uint8_t) 0, vader_box_obj(0u, NULL));
        std_collections_MutableMap_IndexSet_set_at__string__Any(l1, l6, vader_ref_box(l3));
        t1 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t1;
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
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
    std_collections_MutableMap_IndexSet_set_at__i32__bool(l3, l4, true);
    { vader_gc_top = gc_frame.prev; return; }
}

static bool vader_resolver_matches_target(void* l0, void* l1) {
    void* l2;
    size_t l3, l4;
    uint8_t l5, l6;
    vader_box_t t0;
    int64_t t1;
    l2 = l0;
    l3 = ((vader_array_t*) l2)->length;
    l4 = (size_t) 0;
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l4, 250u);
        l5 = ((uint8_t) t0.payload.i);
        l6 = ((vader_struct_vader_target_Target_t*) l1)->f_os;
        if (l5 == l6) {
            return true;
        }
        t1 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t1;
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
    int32_t l6, l7;
    vader_string_t l8 = 0;
    size_t l10, l11;
    vader_box_t l13 = vader_box_null();
    bool t0;
    int32_t t1;
    int64_t t2;
    void* t3 = NULL;
    vader_box_t* gc_roots[1] = { &l13 };
    void** gc_raw_roots[13] = {
        &l0, &l1, &l2, &l3, &l4, &l5, &l9, &l12, &l14, &l15, &l16, &l17, &t3,
    };
    vader_string_t* gc_atom_roots[1] = { &l8 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 13u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_resolver_any_has_body(((vader_struct_toolchain_ast_TraitDecl_t*) l1)->f_members);
    if (!(t0)) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l3 = vader_resolver_provided_names(((vader_struct_toolchain_ast_ImplDecl_t*) l0)->f_members);
    l4 = vader_resolver_build_subst(l0, l1);
    l5 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_toolchain_ast_ImplDecl_t*) l0)->f_trait_name_span)->f_start;
    t1 = ((vader_struct_toolchain_span_Position_t*) l5)->f_line;
    l6 = vader_chk_mul(i32, t1, INT32_C(1024));
    l7 = ((vader_struct_toolchain_span_Position_t*) l5)->f_column;
    l6 = vader_chk_add(i32, l6, l7);
    l8 = ((vader_struct_toolchain_span_Position_t*) l5)->f_file;
    l8 = concat_2(393u, l8);
    vader_struct_vader_resolver_StampCtx_t* _a0_obj = (vader_struct_vader_resolver_StampCtx_t*) vader_gc_alloc(sizeof(vader_struct_vader_resolver_StampCtx_t));
    vader_obj_header_init(_a0_obj, 1020u);
    _a0_obj->f_base_line = l6;
    _a0_obj->f_counter = INT32_C(0);
    _a0_obj->f_file = l8;
    l5 = (void*) _a0_obj;
    l9 = ((vader_struct_toolchain_ast_TraitDecl_t*) l1)->f_members;
    l10 = ((vader_array_t*) l9)->length;
    l11 = (size_t) 0;
    while ((l11 < l10)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l9);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l11)
        l12 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l11);
        l13 = ((vader_struct_toolchain_ast_FnDecl_t*) l12)->f_body;
        if (!(l13.tag == 0u)) {
            if (!(l13.tag == 447u)) {
                vader_unreachable("non-exhaustive match (T3013 should have caught this)");
            }
            l8 = ((vader_struct_toolchain_ast_FnDecl_t*) l12)->f_name;
            t0 = std_collections_MutableSet_Contains_contains__string(l3, l8);
            if (t0) {
                t2 = (l11 + INT64_C(1));
                l11 = (size_t) (int64_t) t2;
                continue;
            }
            vader_array_t* _a2_arr = vader_array_new(27u, 0u, 13u, 456u);
            l14 = (void*) _a2_arr;
            t3 = l13.payload.obj;
            l15 = vader_resolver_substitute_block_materialized(t3, l4, l2, l5);
            l16 = ((vader_struct_toolchain_ast_ImplDecl_t*) l0)->f_members;
            l17 = vader_resolver_synth_with_body(l12, l4, l14, l15, l5);
            vader_array_push((vader_array_t*) l16, vader_ref_box(l17));
        }
        t2 = (l11 + INT64_C(1));
        l11 = (size_t) (int64_t) t2;
    }
    { vader_gc_top = gc_frame.prev; return; }
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
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 10u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
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
    l4 = vader_chk_mul(i32, t2, INT32_C(1024));
    l5 = ((vader_struct_toolchain_span_Position_t*) l3)->f_column;
    l4 = vader_chk_add(i32, l4, l5);
    l6 = ((vader_struct_toolchain_span_Position_t*) l3)->f_file;
    l6 = concat_2(393u, l6);
    vader_struct_vader_resolver_StampCtx_t* _a0_obj = (vader_struct_vader_resolver_StampCtx_t*) vader_gc_alloc(sizeof(vader_struct_vader_resolver_StampCtx_t));
    vader_obj_header_init(_a0_obj, 1020u);
    _a0_obj->f_base_line = l4;
    _a0_obj->f_counter = INT32_C(0);
    _a0_obj->f_file = l6;
    l3 = (void*) _a0_obj;
    l7 = ((vader_struct_toolchain_ast_TraitDecl_t*) l1)->f_members;
    l8 = ((vader_array_t*) l7)->length;
    l9 = (size_t) 0;
    while ((l9 < l8)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l9)
        l10 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l9);
        l11 = ((vader_struct_toolchain_ast_ImplDecl_t*) l0)->f_members;
        l12 = vader_resolver_next_clone_span(l3);
        l13 = vader_resolver_intrinsic_decorator(((vader_struct_toolchain_ast_ImplDecl_t*) l0)->f_span);
        l14 = vader_resolver_synth_signature(l10, l12, l2, l13);
        vader_array_push((vader_array_t*) l11, vader_ref_box(l14));
        t3 = (l9 + INT64_C(1));
        l9 = (size_t) (int64_t) t3;
    }
    { vader_gc_top = gc_frame.prev; return; }
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
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 9u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
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
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
    l3 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT32_C(0));
    l4 = vader_resolver_build_subst(l0, l1);
    l5 = (size_t) 0;
    l6 = ((vader_array_t*) ((vader_struct_toolchain_ast_ImplDecl_t*) l0)->f_members)->length;
    while ((l5 < l6)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_ImplDecl_t*) l0)->f_members);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
        l7 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5);
        t1 = ((vader_struct_toolchain_ast_FnDecl_t*) l7)->f_sam_synthetic;
        if (t1) {
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
            t2 = (l5 + INT64_C(1));
            l5 = (size_t) (int64_t) t2;
            continue;
        }
        t2 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t2;
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_resolver_merge_collected(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l10 = NULL;
    void* l13 = NULL;
    void* l17 = NULL;
    void* l20 = NULL;
    void* l21 = NULL;
    size_t l6, l7, l18, l19;
    vader_string_t l8 = 0;
    vader_string_t l9 = 0;
    vader_string_t l16 = 0;
    vader_box_t l11 = vader_box_null(), l14 = vader_box_null(), l15 = vader_box_null();
    bool l12;
    int32_t l22, l23;
    vader_box_t t0 = vader_box_null();
    int64_t t1;
    void* t2 = NULL;
    vader_box_t* gc_roots[4] = { &l11, &l14, &l15, &t0 };
    void** gc_raw_roots[12] = { &l0, &l1, &l2, &l3, &l4, &l5, &l10, &l13, &l17, &l20, &l21, &t2 };
    vader_string_t* gc_atom_roots[3] = { &l8, &l9, &l16 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 12u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_resolver_CollectedModule_t*) l1)->f_symbols;
    l4 = ((vader_struct_std_collections_MutableMap__string__Symbol_t*) l3)->f_ekeys;
    l5 = ((vader_struct_std_collections_MutableMap__string__Symbol_t*) l3)->f_evals;
    l6 = ((vader_struct_std_collections_MutableMap__string__Symbol_t*) l3)->f_size;
    l7 = (size_t) 0;
    while (!((l7 >= l6))) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l7)
        t0 = vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l7];
        l8 = t0.payload.s;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l7)
        l3 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l7);
        l9 = l8;
        l10 = l3;
        t1 = (l7 + INT64_C(1));
        l7 = (size_t) (int64_t) t1;
        l11 = std_collections_MutableMap_Index_at__string__Any(((vader_struct_vader_resolver_CollectedModule_t*) l0)->f_symbols, l9);
        if (l11.tag == 0u) {
            std_collections_MutableMap_IndexSet_set_at__string__Any(((vader_struct_vader_resolver_CollectedModule_t*) l0)->f_symbols, l9, vader_ref_box(l10));
            continue;
        }
        if (!(l11.tag == 1024u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        t2 = l11.payload.obj;
        if (((vader_struct_vader_resolver_symbol_Symbol_t*) t2)->f_kind != INT32_C(0)) {
            l12 = true;
        } else {
            l12 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l10)->f_kind != INT32_C(0);
        }
        if (l12) {
            l14 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l10)->f_defined_at;
            l15 = l14;
            if (l14.tag == 534u) {
                l13 = l15.payload.obj;
            } else {
                if (!(l14.tag == 0u)) {
                    vader_unreachable("non-exhaustive match (T3013 should have caught this)");
                }
                l13 = vader_resolver_zero_span(0u);
            }
            l16 = concat_3(866u, l9, 878u);
            l17 = vader_diagnostics_resolver_error((uint8_t) 25, l13, l16);
            vader_array_push((vader_array_t*) l2, vader_ref_box(l17));
        }
    }
    l3 = ((vader_struct_vader_resolver_CollectedModule_t*) l1)->f_fn_overloads;
    l4 = ((vader_struct_std_collections_MutableMap__string__Symbol___t*) l3)->f_ekeys;
    l5 = ((vader_struct_std_collections_MutableMap__string__Symbol___t*) l3)->f_evals;
    l6 = ((vader_struct_std_collections_MutableMap__string__Symbol___t*) l3)->f_size;
    l7 = (size_t) 0;
    while (!((l7 >= l6))) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l7)
        t0 = vader_array_box_slots(_a2_slotarr->buf)[_a2_slotarr->offset + (size_t) l7];
        l8 = t0.payload.s;
        vader_array_t* _a3_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l7)
        l3 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l7);
        l9 = l8;
        l10 = l3;
        t1 = (l7 + INT64_C(1));
        l7 = (size_t) (int64_t) t1;
        l11 = std_collections_MutableMap_Index_at__string__Any(((vader_struct_vader_resolver_CollectedModule_t*) l0)->f_fn_overloads, l9);
        if (l11.tag == 0u) {
            std_collections_MutableMap_IndexSet_set_at__string__Any(((vader_struct_vader_resolver_CollectedModule_t*) l0)->f_fn_overloads, l9, vader_ref_box(l10));
            continue;
        }
        l13 = l10;
        l18 = ((vader_array_t*) l13)->length;
        l19 = (size_t) 0;
        while ((l19 < l18)) {
            vader_array_t* _a4_slotarr = ((vader_array_t*) l13);
            VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l19)
            l17 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l19);
            t2 = l11.payload.obj;
            vader_array_push((vader_array_t*) t2, vader_ref_box(l17));
            t1 = (l19 + INT64_C(1));
            l19 = (size_t) (int64_t) t1;
        }
        l20 = ((vader_struct_vader_resolver_CollectedModule_t*) l0)->f_fn_overloads;
        l21 = l11.payload.obj;
        std_collections_MutableMap_IndexSet_set_at__string__Any(l20, l9, vader_ref_box(l21));
    }
    l3 = ((vader_struct_vader_resolver_CollectedModule_t*) l1)->f_imports;
    l4 = ((vader_struct_std_collections_MutableMap__i32__ImportInfo_t*) l3)->f_ekeys;
    l5 = ((vader_struct_std_collections_MutableMap__i32__ImportInfo_t*) l3)->f_evals;
    l6 = ((vader_struct_std_collections_MutableMap__i32__ImportInfo_t*) l3)->f_size;
    l7 = (size_t) 0;
    while (!((l7 >= l6))) {
        vader_array_t* _a5_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l7)
        l22 = ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l7];
        vader_array_t* _a6_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l7)
        l3 = vader_array_ref_load_obj(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l7);
        l23 = l22;
        l10 = l3;
        t1 = (l7 + INT64_C(1));
        l7 = (size_t) (int64_t) t1;
        std_collections_MutableMap_IndexSet_set_at__i32__Any(((vader_struct_vader_resolver_CollectedModule_t*) l0)->f_imports, l23, vader_ref_box(l10));
    }
    l3 = ((vader_struct_vader_resolver_CollectedModule_t*) l1)->f_import_paths;
    l6 = ((vader_array_t*) l3)->length;
    l7 = (size_t) 0;
    while ((l7 < l6)) {
        vader_array_t* _a7_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l7)
        t0 = vader_array_box_slots(_a7_slotarr->buf)[_a7_slotarr->offset + (size_t) l7];
        l8 = t0.payload.s;
        vader_array_push((vader_array_t*) ((vader_struct_vader_resolver_CollectedModule_t*) l0)->f_import_paths, vader_box_string(244u, l8));
        t1 = (l7 + INT64_C(1));
        l7 = (size_t) (int64_t) t1;
    }
    l3 = ((vader_struct_vader_resolver_CollectedModule_t*) l0)->f_files;
    l4 = ((vader_struct_vader_resolver_CollectedModule_t*) l1)->f_files;
    vader_array_push_all((vader_array_t*) l3, (vader_array_t*) l4);
    { vader_gc_top = gc_frame.prev; return; }
}

static void* vader_resolver_mint_local(void* l0, uint8_t l1, vader_string_t l2, void* l3) {
    void* l4 = NULL;
    void* l6 = NULL;
    vader_string_t l5 = 0;
    vader_string_t l7 = 0;
    void* t0 = NULL;
    void** gc_raw_roots[5] = { &l0, &l3, &l4, &l6, &t0 };
    vader_string_t* gc_atom_roots[3] = { &l2, &l5, &l7 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l2 == 2628u) {
        l4 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_diags;
        l5 = concat_3(866u, l2, 866u);
        l6 = vader_diagnostics_resolver_error((uint8_t) 18, l3, l5);
        vader_array_push((vader_array_t*) l4, vader_ref_box(l6));
    }
    l4 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_factory;
    l5 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_module_path;
    l7 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_module_path;
    t0 = vader_resolver_symbol_make(l4, l1, l2, l5, l7, (uint8_t) 1, vader_ref_box(l3));
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_resolver_misplaced_module_at(vader_string_t l0, void* l1) {
    void* l2 = NULL;
    void* l7 = NULL;
    size_t l3, l4;
    vader_box_t l5 = vader_box_null(), l8 = vader_box_null();
    vader_string_t l6 = 0;
    void* t0 = NULL;
    int64_t t1;
    bool t2;
    vader_string_t t3 = 0;
    vader_box_t t4 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l5, &l8, &t4 };
    void** gc_raw_roots[4] = { &l1, &l2, &l7, &t0 };
    vader_string_t* gc_atom_roots[3] = { &l0, &l6, &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(75u, 0u, 13u, 811u);
    l2 = (void*) _a0_arr;
    l3 = (size_t) 0;
    l4 = ((vader_array_t*) l1)->length;
    while ((l3 < l4)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
        t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l3);
        l5 = vader_resolver_rooted_candidate(t0, l0);
        if (l5.tag == 0u) {
            t1 = (l3 + INT64_C(1));
            l3 = (size_t) (int64_t) t1;
            continue;
        }
        l6 = l5.payload.s;
        t2 = std_io_is_dir(l6);
        if (t2) {
            l8 = vader_resolver_scan_folder(l6, l2);
            if (l8.tag == 0u) {
                t1 = (l3 + INT64_C(1));
                l3 = (size_t) (int64_t) t1;
                continue;
            }
            l7 = l8.payload.obj;
            t3 = ((vader_struct_vader_resolver_FolderBucket_t*) l7)->f_name;
            if (t3 != 0u) {
                t3 = ((vader_struct_vader_resolver_FolderBucket_t*) l7)->f_name;
                if (t3 != l0) {
                    t3 = ((vader_struct_vader_resolver_FolderBucket_t*) l7)->f_name;
                    t4 = vader_box_string(244u, t3);
                    { vader_box_t __vret = t4; vader_gc_top = gc_frame.prev; return __vret; }
                }
            }
            t1 = (l3 + INT64_C(1));
            l3 = (size_t) (int64_t) t1;
            continue;
        }
        t1 = (l3 + INT64_C(1));
        l3 = (size_t) (int64_t) t1;
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

void* vader_resolver_module_index_by_name(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    size_t l5, l6;
    vader_string_t l7 = 0;
    vader_box_t t0 = vader_box_null();
    vader_string_t t1 = 0;
    int64_t t2;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &l4 };
    vader_string_t* gc_atom_roots[2] = { &l7, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(13u, 0u, 0u, 244u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(21u, 0u, 0u, 255u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(14u, 0u, 7u, 247u);
    l3 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__string__Any_t* _a3_obj = (vader_struct_std_collections_MutableMap__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__Any_t));
    vader_obj_header_init(_a3_obj, 336u);
    _a3_obj->f_ekeys = l1;
    _a3_obj->f_evals = l2;
    _a3_obj->f_index = l3;
    _a3_obj->f_mask = (size_t) 0;
    _a3_obj->f_size = (size_t) 0;
    _a3_obj->f_tombs = (size_t) 0;
    l1 = (void*) _a3_obj;
    l2 = ((vader_struct_vader_resolver_LoadedProject_t*) l0)->f_modules;
    l3 = ((vader_struct_std_collections_MutableMap__string__LoadedModule_t*) l2)->f_ekeys;
    l4 = ((vader_struct_std_collections_MutableMap__string__LoadedModule_t*) l2)->f_evals;
    l5 = ((vader_struct_std_collections_MutableMap__string__LoadedModule_t*) l2)->f_size;
    l6 = (size_t) 0;
    while (!((l6 >= l5))) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l6)
        t0 = vader_array_box_slots(_a4_slotarr->buf)[_a4_slotarr->offset + (size_t) l6];
        t1 = t0.payload.s;
        vader_array_t* _a5_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l6)
        l2 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l6);
        t2 = (l6 + INT64_C(1));
        l6 = (size_t) (int64_t) t2;
        l7 = ((vader_struct_vader_resolver_Module_t*) ((vader_struct_vader_resolver_LoadedModule_t*) l2)->f_module)->f_module_name;
        std_collections_MutableMap_IndexSet_set_at__string__Any(l1, l7, vader_ref_box(l2));
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_resolver_names_equal(vader_box_t l0, vader_box_t l1) {
    vader_string_t l2, l3;
    if (l0.tag == 0u) {
        return l1.tag == 0u;
    }
    if (!(l1.tag == 0u)) {
        l2 = l0.payload.s;
        l3 = l1.payload.s;
        return l2 == l3;
    }
    return false;
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
    vader_array_t* _a0_arr = vader_array_new(14u, 0u, 7u, 247u);
    l0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(21u, 0u, 0u, 255u);
    l1 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(14u, 0u, 7u, 247u);
    l2 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__i32__Any_t* _a3_obj = (vader_struct_std_collections_MutableMap__i32__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__Any_t));
    vader_obj_header_init(_a3_obj, 296u);
    _a3_obj->f_ekeys = l0;
    _a3_obj->f_evals = l1;
    _a3_obj->f_index = l2;
    _a3_obj->f_mask = (size_t) 0;
    _a3_obj->f_size = (size_t) 0;
    _a3_obj->f_tombs = (size_t) 0;
    l0 = (void*) _a3_obj;
    vader_array_t* _a4_arr = vader_array_new(14u, 0u, 7u, 247u);
    l1 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_new(13u, 0u, 0u, 244u);
    l2 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(14u, 0u, 7u, 247u);
    l3 = (void*) _a6_arr;
    vader_struct_std_collections_MutableMap__i32__string_t* _a7_obj = (vader_struct_std_collections_MutableMap__i32__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__string_t));
    vader_obj_header_init(_a7_obj, 332u);
    _a7_obj->f_ekeys = l1;
    _a7_obj->f_evals = l2;
    _a7_obj->f_index = l3;
    _a7_obj->f_mask = (size_t) 0;
    _a7_obj->f_size = (size_t) 0;
    _a7_obj->f_tombs = (size_t) 0;
    l1 = (void*) _a7_obj;
    vader_array_t* _a8_arr = vader_array_new(14u, 0u, 7u, 247u);
    l2 = (void*) _a8_arr;
    vader_array_t* _a9_arr = vader_array_new(11u, 0u, 12u, 242u);
    l3 = (void*) _a9_arr;
    vader_array_t* _a10_arr = vader_array_new(14u, 0u, 7u, 247u);
    l4 = (void*) _a10_arr;
    vader_struct_std_collections_MutableMap__i32__bool_t* _a11_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
    vader_obj_header_init(_a11_obj, 329u);
    _a11_obj->f_ekeys = l2;
    _a11_obj->f_evals = l3;
    _a11_obj->f_index = l4;
    _a11_obj->f_mask = (size_t) 0;
    _a11_obj->f_size = (size_t) 0;
    _a11_obj->f_tombs = (size_t) 0;
    l2 = (void*) _a11_obj;
    vader_struct_vader_resolver_ImportTargetTable_t* _a12_obj = (vader_struct_vader_resolver_ImportTargetTable_t*) vader_gc_alloc(sizeof(vader_struct_vader_resolver_ImportTargetTable_t));
    vader_obj_header_init(_a12_obj, 1007u);
    _a12_obj->f_symbol_targets = l0;
    _a12_obj->f_namespace_targets = l1;
    _a12_obj->f_missing = l2;
    t0 = (void*) _a12_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_resolver_new_scope(void* l0) {
    void* t0 = NULL;
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(23u, 1u, 13u, 378u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = l0;
    t0 = (void*) _a0_arr;
    vader_struct_vader_resolver_Scope_t* _a1_obj = (vader_struct_vader_resolver_Scope_t*) vader_gc_alloc(sizeof(vader_struct_vader_resolver_Scope_t));
    vader_obj_header_init(_a1_obj, 1017u);
    _a1_obj->f_frames = t0;
    t0 = (void*) _a1_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_resolver_new_subst(void) {
    void* l0 = NULL;
    void* l1 = NULL;
    void* l2 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(13u, 0u, 0u, 244u);
    l0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(21u, 0u, 0u, 255u);
    l1 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(14u, 0u, 7u, 247u);
    l2 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__string__Any_t* _a3_obj = (vader_struct_std_collections_MutableMap__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__Any_t));
    vader_obj_header_init(_a3_obj, 336u);
    _a3_obj->f_ekeys = l0;
    _a3_obj->f_evals = l1;
    _a3_obj->f_index = l2;
    _a3_obj->f_mask = (size_t) 0;
    _a3_obj->f_size = (size_t) 0;
    _a3_obj->f_tombs = (size_t) 0;
    t0 = (void*) _a3_obj;
    vader_struct_vader_resolver_Subst_t* _a4_obj = (vader_struct_vader_resolver_Subst_t*) vader_gc_alloc(sizeof(vader_struct_vader_resolver_Subst_t));
    vader_obj_header_init(_a4_obj, 1021u);
    _a4_obj->f_entries = t0;
    t0 = (void*) _a4_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_resolver_next_clone_span(void* l0) {
    int32_t l1, l2;
    vader_string_t l3 = 0;
    void* l4 = NULL;
    int32_t t0;
    void* t1 = NULL;
    void** gc_raw_roots[3] = { &l0, &l4, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct_vader_resolver_StampCtx_t*) l0)->f_counter;
    t0 = ((vader_struct_vader_resolver_StampCtx_t*) l0)->f_counter;
    l2 = vader_chk_add(i32, t0, INT32_C(1));
    ((vader_struct_vader_resolver_StampCtx_t*) l0)->f_counter = l2;
    l3 = ((vader_struct_vader_resolver_StampCtx_t*) l0)->f_file;
    l2 = ((vader_struct_vader_resolver_StampCtx_t*) l0)->f_base_line;
    vader_struct_toolchain_span_Position_t* _a0_obj = (vader_struct_toolchain_span_Position_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Position_t));
    vader_obj_header_init(_a0_obj, 533u);
    _a0_obj->f_file = l3;
    _a0_obj->f_offset = (size_t) 0;
    _a0_obj->f_line = l2;
    _a0_obj->f_column = l1;
    l4 = (void*) _a0_obj;
    vader_struct_toolchain_span_Span_t* _a1_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
    vader_obj_header_init(_a1_obj, 534u);
    _a1_obj->f_start = l4;
    _a1_obj->f_end = l4;
    t1 = (void*) _a1_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_resolver_note_rebind(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    void* l5 = NULL;
    uint64_t l3;
    vader_box_t l4 = vader_box_null();
    int32_t l6;
    vader_string_t l7 = 0;
    void* t0 = NULL;
    int32_t t1;
    bool t2;
    vader_box_t* gc_roots[2] = { &l1, &l4 };
    void** gc_raw_roots[4] = { &l0, &l2, &l5, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l7 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l1.tag == 476u) {
        l2 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_idents;
        t0 = l1.payload.obj;
        l3 = toolchain_span_Span_Hash_hash(((vader_struct_toolchain_ast_IdentExpr_t*) t0)->f_span);
        l4 = std_collections_MutableMap_Index_at__u64__Any(l2, l3);
        if (l4.tag == 0u) {
            { vader_gc_top = gc_frame.prev; return; }
        }
        l2 = l4.payload.obj;
        l5 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_reassigned;
        l6 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l2)->f_id;
        std_collections_add__i32(l5, l6);
        t1 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_loop_depth;
        if ((t1 > INT32_C(0))) {
            l5 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_rebind_log;
            l6 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l2)->f_id;
            vader_array_push_i32((vader_array_t*) l5, l6);
        }
        t0 = l1.payload.obj;
        l7 = ((vader_struct_toolchain_ast_IdentExpr_t*) t0)->f_name;
        t2 = vader_resolver_declared_outside_lambda(l0, l7);
        if (t2) {
            l5 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_closure_rebound;
            l6 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l2)->f_id;
            std_collections_add__i32(l5, l6);
        }
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static uint8_t vader_resolver_origin_of_root(vader_string_t l0) {
    vader_string_t t0 = 0;
    bool t1;
    vader_string_t* gc_atom_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = vader_resolver_join_path(l0, 2233u);
    t1 = std_io_exists(t0);
    if (!(t1)) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 0; }
    }
    { vader_gc_top = gc_frame.prev; return (uint8_t) 1; }
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
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 11u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(124u, 0u, 13u, 1019u);
    l4 = (void*) _a0_arr;
    l5 = l0;
    l6 = ((vader_array_t*) l5)->length;
    l7 = (size_t) 0;
    while ((l7 < l6)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l7)
        t0 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l7];
        l8 = t0.payload.s;
        l9 = vader_resolver_read_with_overlay(l2, l8);
        if (l9 == 0u) {
            t1 = (l7 + INT64_C(1));
            l7 = (size_t) (int64_t) t1;
            continue;
        }
        l10 = vader_parser_parse_source(l9, l8);
        l11 = ((vader_struct_vader_parser_ParsedSource_t*) l10)->f_errors;
        l12 = ((vader_array_t*) l11)->length;
        l13 = (size_t) 0;
        while ((l13 < l12)) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) l11);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l13)
            l14 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l13);
            vader_array_push((vader_array_t*) l1, vader_ref_box(l14));
            t1 = (l13 + INT64_C(1));
            l13 = (size_t) (int64_t) t1;
        }
        l15 = vader_resolver_with_displayable_impls(((vader_struct_vader_parser_ParsedSource_t*) l10)->f_program);
        vader_parser_assign_program_ids(l15, l3);
        vader_struct_vader_resolver_SourceFile_t* _a3_obj = (vader_struct_vader_resolver_SourceFile_t*) vader_gc_alloc(sizeof(vader_struct_vader_resolver_SourceFile_t));
        vader_obj_header_init(_a3_obj, 1019u);
        _a3_obj->f_path = l8;
        _a3_obj->f_content = l9;
        _a3_obj->f_program = l15;
        _a3_obj->f_id_factory = l3;
        l16 = (void*) _a3_obj;
        vader_array_push((vader_array_t*) l4, vader_ref_box(l16));
        t1 = (l7 + INT64_C(1));
        l7 = (size_t) (int64_t) t1;
    }
    { void* __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_resolver_plain_root(vader_string_t l0, uint8_t l1) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_struct_vader_resolver_IncludePath_t* _a0_obj = (vader_struct_vader_resolver_IncludePath_t*) vader_gc_alloc(sizeof(vader_struct_vader_resolver_IncludePath_t));
    vader_obj_header_init(_a0_obj, 1008u);
    _a0_obj->f_dir = l0;
    _a0_obj->f_prefix = 0u;
    _a0_obj->f_merge = false;
    _a0_obj->f_origin = l1;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_resolver_pop(void* l0) {
    vader_box_t t0;
    t0 = vader_array_remove_last((vader_array_t*) ((vader_struct_vader_resolver_Scope_t*) l0)->f_frames);
    return;
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
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = l0;
    l5 = ((vader_array_t*) l4)->length;
    l6 = (size_t) 0;
    while ((l6 < l5)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l6)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l6);
        l7 = ((vader_struct_toolchain_ast_Program_t*) ((vader_struct_vader_resolver_SourceFile_t*) t0)->f_program)->f_decls;
        l8 = ((vader_array_t*) l7)->length;
        l9 = (size_t) 0;
        while ((l9 < l8)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l7);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l9)
            l10 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l9);
            if (l10.tag == 481u) {
                t0 = l10.payload.obj;
                t1 = ((vader_struct_toolchain_ast_ImportDecl_t*) t0)->f_path;
                vader_resolver_resolve_lazy(t1, l1, l2, l3);
            }
            t2 = (l9 + INT64_C(1));
            l9 = (size_t) (int64_t) t2;
        }
        t2 = (l6 + INT64_C(1));
        l6 = (size_t) (int64_t) t2;
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void* vader_resolver_project_include_paths(vader_box_t l0, void* l1, void* l2) {
    void* l3 = NULL;
    void* l5 = NULL;
    void* l9 = NULL;
    size_t l4, l6;
    vader_string_t l7 = 0;
    vader_string_t l11 = 0;
    uint8_t l8;
    vader_box_t l10 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    int64_t t1;
    vader_string_t t2 = 0;
    vader_box_t* gc_roots[3] = { &l0, &l10, &t0 };
    void** gc_raw_roots[5] = { &l1, &l2, &l3, &l5, &l9 };
    vader_string_t* gc_atom_roots[3] = { &l7, &l11, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(120u, 0u, 13u, 1008u);
    l3 = (void*) _a0_arr;
    l4 = ((vader_array_t*) l2)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l3, (size_t) l4);
    l3 = (void*) _a1_arr;
    l5 = l2;
    l4 = ((vader_array_t*) l5)->length;
    l6 = (size_t) 0;
    while ((l6 < l4)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l6)
        t0 = vader_array_box_slots(_a2_slotarr->buf)[_a2_slotarr->offset + (size_t) l6];
        l7 = t0.payload.s;
        l8 = vader_resolver_origin_of_root(l7);
        l9 = vader_resolver_plain_root(l7, l8);
        vader_array_push((vader_array_t*) l3, vader_ref_box(l9));
        t1 = (l6 + INT64_C(1));
        l6 = (size_t) (int64_t) t1;
    }
    l10 = vader_resolver_sidecar_root(1947u, 2233u);
    if (!(l10.tag == 0u)) {
        t2 = l10.payload.s;
        l5 = vader_resolver_plain_root(t2, (uint8_t) 1);
        vader_array_push((vader_array_t*) l3, vader_ref_box(l5));
    }
    if (l0.tag == 244u) {
        t2 = l0.payload.s;
        l5 = vader_resolver_plain_root(t2, (uint8_t) 0);
        vader_array_push((vader_array_t*) l3, vader_ref_box(l5));
        l5 = ((vader_struct_vader_resolver_Manifest_t*) l1)->f_include_paths;
        l4 = ((vader_array_t*) l5)->length;
        l6 = (size_t) 0;
        while ((l6 < l4)) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l6)
            t0 = vader_array_box_slots(_a3_slotarr->buf)[_a3_slotarr->offset + (size_t) l6];
            l7 = t0.payload.s;
            t2 = l0.payload.s;
            l11 = vader_resolver_join_path(t2, l7);
            l8 = vader_resolver_origin_of_root(l11);
            l9 = vader_resolver_plain_root(l11, l8);
            vader_array_push((vader_array_t*) l3, vader_ref_box(l9));
            t1 = (l6 + INT64_C(1));
            l6 = (size_t) (int64_t) t1;
        }
    } else if (!(l0.tag == 0u)) {
        vader_unreachable("non-exhaustive match (T3013 should have caught this)");
    }
    if (l10.tag == 0u) {
        l8 = vader_resolver_origin_of_root(1947u);
        l5 = vader_resolver_plain_root(1947u, l8);
        vader_array_push((vader_array_t*) l3, vader_ref_box(l5));
        { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
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
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(13u, 0u, 0u, 244u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(11u, 0u, 12u, 242u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(14u, 0u, 7u, 247u);
    l3 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__string__bool_t* _a3_obj = (vader_struct_std_collections_MutableMap__string__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__bool_t));
    vader_obj_header_init(_a3_obj, 384u);
    _a3_obj->f_ekeys = l1;
    _a3_obj->f_evals = l2;
    _a3_obj->f_index = l3;
    _a3_obj->f_mask = (size_t) 0;
    _a3_obj->f_size = (size_t) 0;
    _a3_obj->f_tombs = (size_t) 0;
    t0 = (void*) _a3_obj;
    vader_struct_std_collections_MutableSet__string_t* _a4_obj = (vader_struct_std_collections_MutableSet__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__string_t));
    vader_obj_header_init(_a4_obj, 429u);
    _a4_obj->f_inner = t0;
    l1 = (void*) _a4_obj;
    l2 = l0;
    l4 = ((vader_array_t*) l2)->length;
    l5 = (size_t) 0;
    while ((l5 < l4)) {
        vader_array_t* _a5_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l5)
        t0 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l5);
        l6 = ((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_name;
        std_collections_add__string(l1, l6);
        t1 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t1;
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
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
    vader_array_t* _a0_arr = vader_array_new(13u, 0u, 0u, 244u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(21u, 0u, 0u, 255u);
    l3 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(14u, 0u, 7u, 247u);
    l4 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__string__Any_t* _a3_obj = (vader_struct_std_collections_MutableMap__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__Any_t));
    vader_obj_header_init(_a3_obj, 336u);
    _a3_obj->f_ekeys = l2;
    _a3_obj->f_evals = l3;
    _a3_obj->f_index = l4;
    _a3_obj->f_mask = (size_t) 0;
    _a3_obj->f_size = (size_t) 0;
    _a3_obj->f_tombs = (size_t) 0;
    l2 = (void*) _a3_obj;
    vader_array_push((vader_array_t*) l1, vader_ref_box(l2));
    { vader_gc_top = gc_frame.prev; return; }
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
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(13u, 0u, 0u, 244u);
    l1 = (void*) _a0_arr;
    l2 = vader_resolver_join_path(l0, 2487u);
    t0 = std_io_exists(l2);
    if (!(t0)) {
        vader_struct_vader_resolver_Manifest_t* _a1_obj = (vader_struct_vader_resolver_Manifest_t*) vader_gc_alloc(sizeof(vader_struct_vader_resolver_Manifest_t));
        vader_obj_header_init(_a1_obj, 1011u);
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
        vader_obj_header_init(_a2_obj, 1011u);
        _a2_obj->f_include_paths = l1;
        t1 = (void*) _a2_obj;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = json_parse(l2);
    if (l3.tag == 293u) {
        t1 = l3.payload.obj;
        l3 = std_collections_MutableMap_Index_at__string__Any(((vader_struct_json_JsonObject_t*) t1)->f_entries, 1841u);
        if (l3.tag == 288u) {
            t1 = l3.payload.obj;
            l4 = ((vader_struct_json_JsonArray_t*) t1)->f_items;
            l5 = ((vader_array_t*) l4)->length;
            l6 = (size_t) 0;
            while ((l6 < l5)) {
                vader_array_t* _a3_slotarr = ((vader_array_t*) l4);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l6)
                l3 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l6);
                if (l3.tag == 294u) {
                    t1 = l3.payload.obj;
                    l2 = ((vader_struct_json_JsonString_t*) t1)->f_value;
                    vader_array_push((vader_array_t*) l1, vader_box_string(244u, l2));
                }
                t2 = (l6 + INT64_C(1));
                l6 = (size_t) (int64_t) t2;
            }
        }
        vader_struct_vader_resolver_Manifest_t* _a4_obj = (vader_struct_vader_resolver_Manifest_t*) vader_gc_alloc(sizeof(vader_struct_vader_resolver_Manifest_t));
        vader_obj_header_init(_a4_obj, 1011u);
        _a4_obj->f_include_paths = l1;
        t1 = (void*) _a4_obj;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_resolver_Manifest_t* _a5_obj = (vader_struct_vader_resolver_Manifest_t*) vader_gc_alloc(sizeof(vader_struct_vader_resolver_Manifest_t));
    vader_obj_header_init(_a5_obj, 1011u);
    _a5_obj->f_include_paths = l1;
    t1 = (void*) _a5_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_resolver_read_with_overlay(void* l0, vader_string_t l1) {
    vader_box_t l2 = vader_box_null();
    vader_string_t t0 = 0;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[2] = { &l1, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = std_collections_MutableMap_Index_at__string__string(l0, l1);
    if (!(l2.tag == 0u)) {
        t0 = l2.payload.s;
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = std_io_read_file_string(l1, (size_t) 16777216);
    if (!(l2.tag == 244u)) {
        { vader_gc_top = gc_frame.prev; return 0u; }
    }
    t0 = l2.payload.s;
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_resolver_rebind_free_locals(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    size_t l4, l5;
    int32_t l6;
    void* t0 = NULL;
    bool t1;
    int64_t t2;
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(14u, 0u, 7u, 247u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(11u, 0u, 12u, 242u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(14u, 0u, 7u, 247u);
    l3 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__i32__bool_t* _a3_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
    vader_obj_header_init(_a3_obj, 329u);
    _a3_obj->f_ekeys = l1;
    _a3_obj->f_evals = l2;
    _a3_obj->f_index = l3;
    _a3_obj->f_mask = (size_t) 0;
    _a3_obj->f_size = (size_t) 0;
    _a3_obj->f_tombs = (size_t) 0;
    t0 = (void*) _a3_obj;
    vader_struct_std_collections_MutableSet__i32_t* _a4_obj = (vader_struct_std_collections_MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i32_t));
    vader_obj_header_init(_a4_obj, 427u);
    _a4_obj->f_inner = t0;
    l1 = (void*) _a4_obj;
    l2 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_declared_locals;
    l4 = ((vader_array_t*) l2)->length;
    l5 = (size_t) 0;
    while ((l5 < l4)) {
        vader_array_t* _a5_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l5)
        l6 = ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l5];
        t1 = std_collections_MutableSet_Contains_contains__i32(((vader_struct_vader_resolver_ResolveState_t*) l0)->f_reassigned, l6);
        if (!(t1)) {
            std_collections_add__i32(l1, l6);
        }
        t2 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t2;
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_resolver_report_uncovered(void* l0, void* l1, void* l2, void* l3, void* l4) {
    void* l5 = NULL;
    void* l8 = NULL;
    void* l12 = NULL;
    void* l18 = NULL;
    void* l24 = NULL;
    size_t l6, l7, l9, l10;
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
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 11u, gc_roots, gc_raw_roots, 0u, NULL, 8u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l5 = l0;
    l6 = ((vader_array_t*) l5)->length;
    l7 = (size_t) 0;
    while ((l7 < l6)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l7)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l7);
        l8 = ((vader_struct_toolchain_ast_Program_t*) ((vader_struct_vader_resolver_SourceFile_t*) t0)->f_program)->f_decls;
        l9 = ((vader_array_t*) l8)->length;
        l10 = (size_t) 0;
        while ((l10 < l9)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l8);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l10)
            l11 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l10);
            if (l11.tag == 471u) {
                t0 = l11.payload.obj;
                l13 = vader_resolver_target_selectors(((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_decorators);
                if (l13.tag == 0u) {
                    t1 = (l10 + INT64_C(1));
                    l10 = (size_t) (int64_t) t1;
                    continue;
                }
                l12 = l13.payload.obj;
                t2 = ((vader_struct_vader_resolver_TargetSelectors_t*) l12)->f_is_bare;
                if (t2) {
                    t0 = l11.payload.obj;
                    if (((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_body.tag == 0u) {
                        t0 = l11.payload.obj;
                        l14 = ((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_name;
                        t3 = std_collections_MutableMap_Index_at__string__Any(l2, l14);
                        if (t3.tag == 0u) {
                            t0 = l11.payload.obj;
                            t2 = vader_resolver_is_host_bound(t0);
                            if (t2) {
                                t1 = (l10 + INT64_C(1));
                                l10 = (size_t) (int64_t) t1;
                                continue;
                            }
                            t0 = l11.payload.obj;
                            l16 = ((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_name;
                            l17 = std_collections_MutableMap_Index_at__string__string(l3, l16);
                            if (l17.tag == 0u) {
                                l15 = 242u;
                            } else {
                                l15 = l17.payload.s;
                            }
                            t0 = l11.payload.obj;
                            l18 = ((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_name_span;
                            t0 = l11.payload.obj;
                            l19 = ((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_name;
                            l20 = vader_target_display_target(l1);
                            l21 = concat_5(866u, l19, 921u, l20, 884u);
                            l22 = concat_2(1910u, l15);
                            l23 = concat_2(l21, l22);
                            l24 = vader_diagnostics_resolver_error((uint8_t) 40, l18, l23);
                            vader_array_push((vader_array_t*) l4, vader_ref_box(l24));
                        } else {
                            t1 = (l10 + INT64_C(1));
                            l10 = (size_t) (int64_t) t1;
                            continue;
                        }
                    } else {
                        t1 = (l10 + INT64_C(1));
                        l10 = (size_t) (int64_t) t1;
                        continue;
                    }
                } else {
                    t1 = (l10 + INT64_C(1));
                    l10 = (size_t) (int64_t) t1;
                    continue;
                }
            }
            t1 = (l10 + INT64_C(1));
            l10 = (size_t) (int64_t) t1;
        }
        t1 = (l7 + INT64_C(1));
        l7 = (size_t) (int64_t) t1;
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_resolver_report_unreassigned_mutables(void* l0) {
    void* l1 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l14 = NULL;
    void* l15 = NULL;
    void* l17 = NULL;
    size_t l2, l3, l7, l10, l11;
    vader_string_t l12 = 0;
    vader_string_t l13 = 0;
    vader_string_t l16 = 0;
    bool t0;
    int64_t t1;
    void* t2 = NULL;
    void** gc_raw_roots[11] = { &l0, &l1, &l4, &l5, &l6, &l8, &l9, &l14, &l15, &l17, &t2 };
    vader_string_t* gc_atom_roots[3] = { &l12, &l13, &l16 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 11u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_mutable_decls;
    l2 = ((vader_array_t*) l1)->length;
    l3 = (size_t) 0;
    while ((l3 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        l4 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
        l5 = ((vader_struct_vader_resolver_MutableDecl_t*) l4)->f_syms;
        t0 = vader_resolver_has_reassignment(l0, l5);
        if (t0) {
            t1 = (l3 + INT64_C(1));
            l3 = (size_t) (int64_t) t1;
            continue;
        }
        vader_array_t* _a1_arr = vader_array_new(13u, 0u, 0u, 244u);
        l6 = (void*) _a1_arr;
        l7 = ((vader_array_t*) ((vader_struct_vader_resolver_MutableDecl_t*) l4)->f_syms)->length;
        vader_array_t* _a2_arr = vader_array_repeat((vader_array_t*) l6, (size_t) l7);
        l8 = (void*) _a2_arr;
        l9 = ((vader_struct_vader_resolver_MutableDecl_t*) l4)->f_syms;
        l10 = ((vader_array_t*) l9)->length;
        l11 = (size_t) 0;
        while ((l11 < l10)) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l9);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l11)
            t2 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l11);
            l12 = ((vader_struct_vader_resolver_symbol_Symbol_t*) t2)->f_name;
            vader_array_push((vader_array_t*) l8, vader_box_string(244u, l12));
            t1 = (l11 + INT64_C(1));
            l11 = (size_t) (int64_t) t1;
        }
        l13 = std_string_join(l8, 1079u);
        l14 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_diags;
        l15 = ((vader_struct_vader_resolver_MutableDecl_t*) l4)->f_span;
        l16 = concat_3(866u, l13, 866u);
        l17 = vader_diagnostics_warning((uint8_t) 11, l15, l16);
        vader_array_push((vader_array_t*) l14, vader_ref_box(l17));
        t1 = (l3 + INT64_C(1));
        l3 = (size_t) (int64_t) t1;
    }
    { vader_gc_top = gc_frame.prev; return; }
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
    vader_array_t* _a0_arr = vader_array_new(29u, 0u, 13u, 471u);
    l1 = (void*) _a0_arr;
    l2 = l0;
    l3 = ((vader_array_t*) l2)->length;
    l4 = (size_t) 0;
    while ((l4 < l3)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
        l5 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
        l6 = ((vader_struct_toolchain_ast_FnDecl_t*) l5)->f_body;
        if (l6.tag == 0u) {
            vader_array_push((vader_array_t*) l1, vader_ref_box(l5));
        } else if (!(l6.tag == 447u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        t0 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t0;
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_resolver_resolve_decl(vader_box_t l0, void* l1, void* l2, void* l3) {
    void* l4 = NULL;
    vader_box_t l5 = vader_box_null();
    vader_string_t l6 = 0;
    void* t0 = NULL;
    void* t2 = NULL;
    bool t1;
    vader_box_t* gc_roots[2] = { &l0, &l5 };
    void** gc_raw_roots[6] = { &l1, &l2, &l3, &l4, &t0, &t2 };
    vader_string_t* gc_atom_roots[1] = { &l6 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l0.tag == 515u) {
        t0 = l0.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l0.tag == 471u)) {
        { vader_box_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l0.payload.obj;
    l5 = vader_resolver_target_selectors(((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_decorators);
    if (l5.tag == 0u) {
        t0 = l0.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = l5.payload.obj;
    t1 = ((vader_struct_vader_resolver_TargetSelectors_t*) l4)->f_is_bare;
    if (!(t1)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    t0 = l0.payload.obj;
    l6 = ((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_name;
    l5 = std_collections_MutableMap_Index_at__string__Any(l2, l6);
    if (l5.tag == 0u) {
        t0 = l0.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = l5.payload.obj;
    t0 = l0.payload.obj;
    t2 = vader_resolver_graft_body(t0, l4);
    { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
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
    l4 = std_collections_MutableMap_Index_at__i32__Any(l2, l3);
    if (l4.tag == 0u) {
        return l0;
    }
    l2 = l4.payload.obj;
    return ((vader_struct_vader_resolver_SymbolTarget_t*) l2)->f_symbol;
}

static vader_box_t vader_resolver_resolve_lazy(vader_string_t l0, void* l1, void* l2, void* l3) {
    vader_box_t l4 = vader_box_null(), l9 = vader_box_null(), l12 = vader_box_null();
    uint8_t l5;
    void* l6 = NULL;
    void* l11 = NULL;
    void* l13 = NULL;
    void* l15 = NULL;
    size_t l7, l8;
    vader_string_t l10 = 0;
    vader_string_t l14 = 0;
    void* t0 = NULL;
    bool t1;
    int64_t t2;
    vader_string_t t3 = 0;
    vader_box_t* gc_roots[3] = { &l4, &l9, &l12 };
    void** gc_raw_roots[8] = { &l1, &l2, &l3, &l6, &l11, &l13, &l15, &t0 };
    vader_string_t* gc_atom_roots[4] = { &l0, &l10, &l14, &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = std_collections_MutableMap_Index_at__string__Any(l2, l0);
    if (l4.tag == 1002u) {
        t0 = l4.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = vader_box_obj(0u, NULL);
    l5 = (uint8_t) 0;
    vader_array_t* _a0_arr = vader_array_new(13u, 0u, 0u, 244u);
    l6 = (void*) _a0_arr;
    l7 = (size_t) 0;
    l8 = ((vader_array_t*) l1)->length;
    while ((l7 < l8)) {
        if (!(l4.tag == 0u)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l7)
            t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l7);
            t1 = ((vader_struct_vader_resolver_IncludePath_t*) t0)->f_merge;
            if (!(t1)) {
                t2 = (l7 + INT64_C(1));
                l7 = (size_t) (int64_t) t2;
                continue;
            }
        }
        vader_array_t* _a2_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l7)
        t0 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l7);
        l9 = vader_resolver_rooted_candidate(t0, l0);
        if (l9.tag == 0u) {
            t2 = (l7 + INT64_C(1));
            l7 = (size_t) (int64_t) t2;
            continue;
        }
        l10 = l9.payload.s;
        t1 = std_io_is_dir(l10);
        if (t1) {
            l12 = vader_resolver_scan_folder(l10, l3);
            if (l12.tag == 0u) {
                t2 = (l7 + INT64_C(1));
                l7 = (size_t) (int64_t) t2;
                continue;
            }
            l11 = l12.payload.obj;
            t3 = ((vader_struct_vader_resolver_FolderBucket_t*) l11)->f_name;
            if (t3 != l0) {
                t2 = (l7 + INT64_C(1));
                l7 = (size_t) (int64_t) t2;
                continue;
            }
            if (l4.tag == 0u) {
                l4 = vader_box_string(244u, l10);
                vader_array_t* _a3_slotarr = ((vader_array_t*) l1);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l7)
                t0 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l7);
                l5 = ((vader_struct_vader_resolver_IncludePath_t*) t0)->f_origin;
                l13 = ((vader_struct_vader_resolver_FolderBucket_t*) l11)->f_files;
                vader_array_push_all((vader_array_t*) l6, (vader_array_t*) l13);
                t2 = (l7 + INT64_C(1));
                l7 = (size_t) (int64_t) t2;
                continue;
            }
            l14 = l4.payload.s;
            if (l10 == l14) {
                t2 = (l7 + INT64_C(1));
                l7 = (size_t) (int64_t) t2;
                continue;
            }
            l15 = ((vader_struct_vader_resolver_FolderBucket_t*) l11)->f_files;
            vader_array_push_all((vader_array_t*) l6, (vader_array_t*) l15);
            t2 = (l7 + INT64_C(1));
            l7 = (size_t) (int64_t) t2;
            continue;
        }
        t2 = (l7 + INT64_C(1));
        l7 = (size_t) (int64_t) t2;
    }
    if (l4.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l10 = l4.payload.s;
    vader_struct_vader_resolver_DiscoveredModule_t* _a4_obj = (vader_struct_vader_resolver_DiscoveredModule_t*) vader_gc_alloc(sizeof(vader_struct_vader_resolver_DiscoveredModule_t));
    vader_obj_header_init(_a4_obj, 1002u);
    _a4_obj->f_name = l0;
    _a4_obj->f_folder = l10;
    _a4_obj->f_files = l6;
    _a4_obj->f_origin = l5;
    l6 = (void*) _a4_obj;
    std_collections_MutableMap_IndexSet_set_at__string__Any(l2, l0, vader_ref_box(l6));
    { vader_box_t __vret = vader_ref_box(l6); vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_resolver_resolve_module(void* l0, vader_string_t l1, void* l2) {
    void* l3 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    vader_string_t l4 = 0;
    void* t0 = NULL;
    void** gc_raw_roots[9] = { &l0, &l2, &l3, &l5, &l6, &l7, &l8, &l9, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l1, &l4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 9u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = vader_resolver_collect_module_no_index(l0, l1, l2);
    l4 = ((vader_struct_toolchain_ast_Program_t*) l0)->f_file;
    l5 = vader_parser_new_node_id_factory();
    vader_struct_vader_resolver_SourceFile_t* _a0_obj = (vader_struct_vader_resolver_SourceFile_t*) vader_gc_alloc(sizeof(vader_struct_vader_resolver_SourceFile_t));
    vader_obj_header_init(_a0_obj, 1019u);
    _a0_obj->f_path = l4;
    _a0_obj->f_content = 0u;
    _a0_obj->f_program = l0;
    _a0_obj->f_id_factory = l5;
    t0 = (void*) _a0_obj;
    vader_array_t* _a1_arr = vader_array_new(124u, 1u, 13u, 1019u);
    ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = t0;
    l5 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(13u, 0u, 0u, 244u);
    l6 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(21u, 0u, 0u, 255u);
    l7 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_new(14u, 0u, 7u, 247u);
    l8 = (void*) _a4_arr;
    vader_struct_std_collections_MutableMap__string__Any_t* _a5_obj = (vader_struct_std_collections_MutableMap__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__Any_t));
    vader_obj_header_init(_a5_obj, 336u);
    _a5_obj->f_ekeys = l6;
    _a5_obj->f_evals = l7;
    _a5_obj->f_index = l8;
    _a5_obj->f_mask = (size_t) 0;
    _a5_obj->f_size = (size_t) 0;
    _a5_obj->f_tombs = (size_t) 0;
    l6 = (void*) _a5_obj;
    vader_array_t* _a6_arr = vader_array_new(13u, 0u, 0u, 244u);
    l7 = (void*) _a6_arr;
    vader_array_t* _a7_arr = vader_array_new(21u, 0u, 0u, 255u);
    l8 = (void*) _a7_arr;
    vader_array_t* _a8_arr = vader_array_new(14u, 0u, 7u, 247u);
    l9 = (void*) _a8_arr;
    vader_struct_std_collections_MutableMap__string__Any_t* _a9_obj = (vader_struct_std_collections_MutableMap__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__Any_t));
    vader_obj_header_init(_a9_obj, 336u);
    _a9_obj->f_ekeys = l7;
    _a9_obj->f_evals = l8;
    _a9_obj->f_index = l9;
    _a9_obj->f_mask = (size_t) 0;
    _a9_obj->f_size = (size_t) 0;
    _a9_obj->f_tombs = (size_t) 0;
    l7 = (void*) _a9_obj;
    t0 = vader_resolver_resolve_module_files(l5, l1, l1, l2, l3, l6, l7);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_resolver_resolve_module_files(void* l0, vader_string_t l1, vader_string_t l2, void* l3, void* l4, void* l5, void* l6) {
    void* l7 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    void* l12 = NULL;
    void* l15 = NULL;
    void* l17 = NULL;
    void* l19 = NULL;
    void* l20 = NULL;
    void* l21 = NULL;
    void* l22 = NULL;
    void* l23 = NULL;
    void* l24 = NULL;
    void* l25 = NULL;
    void* l26 = NULL;
    void* l27 = NULL;
    void* l30 = NULL;
    void* l31 = NULL;
    size_t l13, l14, l28, l29;
    vader_string_t l16 = 0;
    vader_string_t l18 = 0;
    vader_box_t t0 = vader_box_null();
    vader_string_t t1 = 0;
    int64_t t2;
    void* t3 = NULL;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[25] = {
        &l0, &l3, &l4, &l5, &l6, &l7, &l8, &l9, &l10, &l11, &l12, &l15, &l17, &l19, &l20, &l21,
        &l22, &l23, &l24, &l25, &l26, &l27, &l30, &l31, &t3,
    };
    vader_string_t* gc_atom_roots[5] = { &l1, &l2, &l16, &l18, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 25u, gc_roots, gc_raw_roots, 0u, NULL, 5u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l7 = vader_resolver_make_builtin_scope(l3);
    vader_array_t* _a0_arr = vader_array_new(13u, 0u, 0u, 244u);
    l8 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(21u, 0u, 0u, 255u);
    l9 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(14u, 0u, 7u, 247u);
    l10 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__string__Any_t* _a3_obj = (vader_struct_std_collections_MutableMap__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__Any_t));
    vader_obj_header_init(_a3_obj, 336u);
    _a3_obj->f_ekeys = l8;
    _a3_obj->f_evals = l9;
    _a3_obj->f_index = l10;
    _a3_obj->f_mask = (size_t) 0;
    _a3_obj->f_size = (size_t) 0;
    _a3_obj->f_tombs = (size_t) 0;
    l8 = (void*) _a3_obj;
    vader_array_t* _a4_arr = vader_array_new(35u, 0u, 13u, 504u);
    l9 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_new(126u, 0u, 13u, 1024u);
    l10 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(75u, 0u, 13u, 811u);
    l11 = (void*) _a6_arr;
    l12 = l0;
    l13 = ((vader_array_t*) l12)->length;
    l14 = (size_t) 0;
    while ((l14 < l13)) {
        vader_array_t* _a7_slotarr = ((vader_array_t*) l12);
        VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l14)
        l15 = vader_array_ref_load_obj(_a7_slotarr->buf, _a7_slotarr->offset + (size_t) l14);
        l16 = ((vader_struct_toolchain_ast_Program_t*) ((vader_struct_vader_resolver_SourceFile_t*) l15)->f_program)->f_file;
        l17 = vader_resolver_file_imports(l4, l16);
        l18 = ((vader_struct_toolchain_ast_Program_t*) ((vader_struct_vader_resolver_SourceFile_t*) l15)->f_program)->f_file;
        l19 = vader_resolver_file_root_scope(l7, l4, l17, l5, l6);
        l20 = ((vader_struct_vader_resolver_FileImports_t*) l17)->f_paths;
        l21 = ((vader_struct_vader_resolver_FileImports_t*) l17)->f_excludes;
        l22 = vader_resolver_wildcard_ambiguities(l5, l20, l21, l6);
        vader_struct_vader_resolver_FileScope_t* _a8_obj = (vader_struct_vader_resolver_FileScope_t*) vader_gc_alloc(sizeof(vader_struct_vader_resolver_FileScope_t));
        vader_obj_header_init(_a8_obj, 1004u);
        _a8_obj->f_root = l19;
        _a8_obj->f_ambiguous = l22;
        l23 = (void*) _a8_obj;
        std_collections_MutableMap_IndexSet_set_at__string__Any(l8, l18, vader_ref_box(l23));
        l24 = ((vader_struct_vader_resolver_SourceFile_t*) l15)->f_program;
        vader_array_push((vader_array_t*) l9, vader_ref_box(l24));
        l25 = ((vader_struct_vader_resolver_FileImports_t*) l17)->f_bindings;
        l26 = ((vader_struct_std_collections_MutableMap__string__Symbol_t*) l25)->f_ekeys;
        l27 = ((vader_struct_std_collections_MutableMap__string__Symbol_t*) l25)->f_evals;
        l28 = ((vader_struct_std_collections_MutableMap__string__Symbol_t*) l25)->f_size;
        l29 = (size_t) 0;
        while (!((l29 >= l28))) {
            vader_array_t* _a9_slotarr = ((vader_array_t*) l26);
            VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l29)
            t0 = vader_array_box_slots(_a9_slotarr->buf)[_a9_slotarr->offset + (size_t) l29];
            t1 = t0.payload.s;
            vader_array_t* _a10_slotarr = ((vader_array_t*) l27);
            VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a10_slotarr, l29)
            l30 = vader_array_ref_load_obj(_a10_slotarr->buf, _a10_slotarr->offset + (size_t) l29);
            t2 = (l29 + INT64_C(1));
            l29 = (size_t) (int64_t) t2;
            vader_array_push((vader_array_t*) l10, vader_ref_box(l30));
        }
        l31 = vader_resolver_binding_clashes(l4, l17);
        vader_array_push_all((vader_array_t*) l11, (vader_array_t*) l31);
        t2 = (l14 + INT64_C(1));
        l14 = (size_t) (int64_t) t2;
    }
    l7 = vader_resolver_resolve_module_programs(l9, l8, l1, l3);
    vader_array_push_all((vader_array_t*) ((vader_struct_vader_resolver_ResolvedFile_t*) l7)->f_diags, (vader_array_t*) l11);
    t3 = std_collections_values__string__Symbol(((vader_struct_vader_resolver_CollectedModule_t*) l4)->f_symbols);
    l8 = vader_resolver_sort_by_name(t3);
    l9 = ((vader_struct_vader_resolver_ResolvedFile_t*) l7)->f_idents;
    l11 = ((vader_struct_vader_resolver_ResolvedFile_t*) l7)->f_immutable_locals;
    l12 = ((vader_struct_vader_resolver_ResolvedFile_t*) l7)->f_immutable_borrows;
    l15 = ((vader_struct_vader_resolver_ResolvedFile_t*) l7)->f_rebind_free;
    l17 = ((vader_struct_vader_resolver_ResolvedFile_t*) l7)->f_loop_rebinds;
    l19 = ((vader_struct_vader_resolver_ResolvedFile_t*) l7)->f_closure_rebound;
    l20 = ((vader_struct_vader_resolver_CollectedModule_t*) l4)->f_fn_overloads;
    vader_array_t* _a11_arr = vader_array_new(14u, 0u, 7u, 247u);
    l21 = (void*) _a11_arr;
    vader_array_t* _a12_arr = vader_array_new(21u, 0u, 0u, 255u);
    l22 = (void*) _a12_arr;
    vader_array_t* _a13_arr = vader_array_new(14u, 0u, 7u, 247u);
    l23 = (void*) _a13_arr;
    vader_struct_std_collections_MutableMap__i32__Any_t* _a14_obj = (vader_struct_std_collections_MutableMap__i32__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__Any_t));
    vader_obj_header_init(_a14_obj, 296u);
    _a14_obj->f_ekeys = l21;
    _a14_obj->f_evals = l22;
    _a14_obj->f_index = l23;
    _a14_obj->f_mask = (size_t) 0;
    _a14_obj->f_size = (size_t) 0;
    _a14_obj->f_tombs = (size_t) 0;
    l21 = (void*) _a14_obj;
    vader_array_t* _a15_arr = vader_array_new(14u, 0u, 7u, 247u);
    l22 = (void*) _a15_arr;
    vader_array_t* _a16_arr = vader_array_new(21u, 0u, 0u, 255u);
    l23 = (void*) _a16_arr;
    vader_array_t* _a17_arr = vader_array_new(14u, 0u, 7u, 247u);
    l24 = (void*) _a17_arr;
    vader_struct_std_collections_MutableMap__i32__Any_t* _a18_obj = (vader_struct_std_collections_MutableMap__i32__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__Any_t));
    vader_obj_header_init(_a18_obj, 296u);
    _a18_obj->f_ekeys = l22;
    _a18_obj->f_evals = l23;
    _a18_obj->f_index = l24;
    _a18_obj->f_mask = (size_t) 0;
    _a18_obj->f_size = (size_t) 0;
    _a18_obj->f_tombs = (size_t) 0;
    l22 = (void*) _a18_obj;
    vader_array_t* _a19_arr = vader_array_new(14u, 0u, 7u, 247u);
    l23 = (void*) _a19_arr;
    vader_array_t* _a20_arr = vader_array_new(21u, 0u, 0u, 255u);
    l24 = (void*) _a20_arr;
    vader_array_t* _a21_arr = vader_array_new(14u, 0u, 7u, 247u);
    l25 = (void*) _a21_arr;
    vader_struct_std_collections_MutableMap__i32__Any_t* _a22_obj = (vader_struct_std_collections_MutableMap__i32__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__Any_t));
    vader_obj_header_init(_a22_obj, 296u);
    _a22_obj->f_ekeys = l23;
    _a22_obj->f_evals = l24;
    _a22_obj->f_index = l25;
    _a22_obj->f_mask = (size_t) 0;
    _a22_obj->f_size = (size_t) 0;
    _a22_obj->f_tombs = (size_t) 0;
    l23 = (void*) _a22_obj;
    l24 = ((vader_struct_vader_resolver_ResolvedFile_t*) l7)->f_type_param_bounds;
    l7 = ((vader_struct_vader_resolver_ResolvedFile_t*) l7)->f_diags;
    vader_array_t* _a23_arr = vader_array_new(14u, 0u, 7u, 247u);
    l25 = (void*) _a23_arr;
    vader_array_t* _a24_arr = vader_array_new(13u, 0u, 0u, 244u);
    l26 = (void*) _a24_arr;
    vader_array_t* _a25_arr = vader_array_new(14u, 0u, 7u, 247u);
    l27 = (void*) _a25_arr;
    vader_struct_std_collections_MutableMap__i32__string_t* _a26_obj = (vader_struct_std_collections_MutableMap__i32__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__string_t));
    vader_obj_header_init(_a26_obj, 332u);
    _a26_obj->f_ekeys = l25;
    _a26_obj->f_evals = l26;
    _a26_obj->f_index = l27;
    _a26_obj->f_mask = (size_t) 0;
    _a26_obj->f_size = (size_t) 0;
    _a26_obj->f_tombs = (size_t) 0;
    l25 = (void*) _a26_obj;
    vader_array_t* _a27_arr = vader_array_new(14u, 0u, 7u, 247u);
    l26 = (void*) _a27_arr;
    vader_array_t* _a28_arr = vader_array_new(21u, 0u, 0u, 255u);
    l27 = (void*) _a28_arr;
    vader_array_t* _a29_arr = vader_array_new(14u, 0u, 7u, 247u);
    l30 = (void*) _a29_arr;
    vader_struct_std_collections_MutableMap__i32__MutableMap_Any__Any__t* _a30_obj = (vader_struct_std_collections_MutableMap__i32__MutableMap_Any__Any__t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__MutableMap_Any__Any__t));
    vader_obj_header_init(_a30_obj, 313u);
    _a30_obj->f_ekeys = l26;
    _a30_obj->f_evals = l27;
    _a30_obj->f_index = l30;
    _a30_obj->f_mask = (size_t) 0;
    _a30_obj->f_size = (size_t) 0;
    _a30_obj->f_tombs = (size_t) 0;
    l26 = (void*) _a30_obj;
    vader_array_t* _a31_arr = vader_array_new(14u, 0u, 7u, 247u);
    l27 = (void*) _a31_arr;
    vader_array_t* _a32_arr = vader_array_new(21u, 0u, 0u, 255u);
    l30 = (void*) _a32_arr;
    vader_array_t* _a33_arr = vader_array_new(14u, 0u, 7u, 247u);
    l31 = (void*) _a33_arr;
    vader_struct_std_collections_MutableMap__i32__MutableMap_Any__Any__t* _a34_obj = (vader_struct_std_collections_MutableMap__i32__MutableMap_Any__Any__t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__MutableMap_Any__Any__t));
    vader_obj_header_init(_a34_obj, 313u);
    _a34_obj->f_ekeys = l27;
    _a34_obj->f_evals = l30;
    _a34_obj->f_index = l31;
    _a34_obj->f_mask = (size_t) 0;
    _a34_obj->f_size = (size_t) 0;
    _a34_obj->f_tombs = (size_t) 0;
    l27 = (void*) _a34_obj;
    vader_struct_vader_resolver_ResolvedModule_t* _a35_obj = (vader_struct_vader_resolver_ResolvedModule_t*) vader_gc_alloc(sizeof(vader_struct_vader_resolver_ResolvedModule_t));
    vader_obj_header_init(_a35_obj, 1016u);
    _a35_obj->f_path = l1;
    _a35_obj->f_display_path = l2;
    _a35_obj->f_symbols = l8;
    _a35_obj->f_import_bindings = l10;
    _a35_obj->f_idents = l9;
    _a35_obj->f_immutable_locals = l11;
    _a35_obj->f_immutable_borrows = l12;
    _a35_obj->f_rebind_free = l15;
    _a35_obj->f_loop_rebinds = l17;
    _a35_obj->f_closure_rebound = l19;
    _a35_obj->f_fn_overloads = l20;
    _a35_obj->f_imports_to = l21;
    _a35_obj->f_alias_types = l22;
    _a35_obj->f_alias_decls = l23;
    _a35_obj->f_type_param_bounds = l24;
    _a35_obj->f_diags = l7;
    _a35_obj->f_deprecated_messages = l25;
    _a35_obj->f_namespace_member_types = l26;
    _a35_obj->f_namespace_private_members = l27;
    t3 = (void*) _a35_obj;
    { void* __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_resolver_resolve_module_programs(void* l0, void* l1, vader_string_t l2, void* l3) {
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
    size_t l19, l20, l24, l25;
    vader_string_t l21 = 0;
    vader_string_t l23 = 0;
    vader_box_t l22 = vader_box_null(), l26 = vader_box_null();
    void* t0 = NULL;
    vader_string_t t1 = 0;
    int64_t t2;
    vader_box_t* gc_roots[2] = { &l22, &l26 };
    void** gc_raw_roots[19] = {
        &l0, &l1, &l3, &l4, &l5, &l6, &l7, &l8, &l9, &l10, &l11, &l12, &l13, &l14, &l15, &l16, &l17,
        &l18, &t0,
    };
    vader_string_t* gc_atom_roots[4] = { &l2, &l21, &l23, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 19u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(19u, 0u, 4u, 253u);
    l4 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(21u, 0u, 0u, 255u);
    l5 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(14u, 0u, 7u, 247u);
    l6 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__u64__Any_t* _a3_obj = (vader_struct_std_collections_MutableMap__u64__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__u64__Any_t));
    vader_obj_header_init(_a3_obj, 391u);
    _a3_obj->f_ekeys = l4;
    _a3_obj->f_evals = l5;
    _a3_obj->f_index = l6;
    _a3_obj->f_mask = (size_t) 0;
    _a3_obj->f_size = (size_t) 0;
    _a3_obj->f_tombs = (size_t) 0;
    l4 = (void*) _a3_obj;
    vader_array_t* _a4_arr = vader_array_new(14u, 0u, 7u, 247u);
    l5 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_new(11u, 0u, 12u, 242u);
    l6 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(14u, 0u, 7u, 247u);
    l7 = (void*) _a6_arr;
    vader_struct_std_collections_MutableMap__i32__bool_t* _a7_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
    vader_obj_header_init(_a7_obj, 329u);
    _a7_obj->f_ekeys = l5;
    _a7_obj->f_evals = l6;
    _a7_obj->f_index = l7;
    _a7_obj->f_mask = (size_t) 0;
    _a7_obj->f_size = (size_t) 0;
    _a7_obj->f_tombs = (size_t) 0;
    l5 = (void*) _a7_obj;
    vader_array_t* _a8_arr = vader_array_new(14u, 0u, 7u, 247u);
    l6 = (void*) _a8_arr;
    vader_array_t* _a9_arr = vader_array_new(11u, 0u, 12u, 242u);
    l7 = (void*) _a9_arr;
    vader_array_t* _a10_arr = vader_array_new(14u, 0u, 7u, 247u);
    l8 = (void*) _a10_arr;
    vader_struct_std_collections_MutableMap__i32__bool_t* _a11_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
    vader_obj_header_init(_a11_obj, 329u);
    _a11_obj->f_ekeys = l6;
    _a11_obj->f_evals = l7;
    _a11_obj->f_index = l8;
    _a11_obj->f_mask = (size_t) 0;
    _a11_obj->f_size = (size_t) 0;
    _a11_obj->f_tombs = (size_t) 0;
    l6 = (void*) _a11_obj;
    vader_array_t* _a12_arr = vader_array_new(14u, 0u, 7u, 247u);
    l7 = (void*) _a12_arr;
    vader_array_t* _a13_arr = vader_array_new(21u, 0u, 0u, 255u);
    l8 = (void*) _a13_arr;
    vader_array_t* _a14_arr = vader_array_new(14u, 0u, 7u, 247u);
    l9 = (void*) _a14_arr;
    vader_struct_std_collections_MutableMap__i32__Any_t* _a15_obj = (vader_struct_std_collections_MutableMap__i32__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__Any_t));
    vader_obj_header_init(_a15_obj, 296u);
    _a15_obj->f_ekeys = l7;
    _a15_obj->f_evals = l8;
    _a15_obj->f_index = l9;
    _a15_obj->f_mask = (size_t) 0;
    _a15_obj->f_size = (size_t) 0;
    _a15_obj->f_tombs = (size_t) 0;
    l7 = (void*) _a15_obj;
    vader_array_t* _a16_arr = vader_array_new(122u, 0u, 13u, 1013u);
    l8 = (void*) _a16_arr;
    vader_array_t* _a17_arr = vader_array_new(14u, 0u, 7u, 247u);
    l9 = (void*) _a17_arr;
    vader_array_t* _a18_arr = vader_array_new(11u, 0u, 12u, 242u);
    l10 = (void*) _a18_arr;
    vader_array_t* _a19_arr = vader_array_new(14u, 0u, 7u, 247u);
    l11 = (void*) _a19_arr;
    vader_struct_std_collections_MutableMap__i32__bool_t* _a20_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
    vader_obj_header_init(_a20_obj, 329u);
    _a20_obj->f_ekeys = l9;
    _a20_obj->f_evals = l10;
    _a20_obj->f_index = l11;
    _a20_obj->f_mask = (size_t) 0;
    _a20_obj->f_size = (size_t) 0;
    _a20_obj->f_tombs = (size_t) 0;
    t0 = (void*) _a20_obj;
    vader_struct_std_collections_MutableSet__i32_t* _a21_obj = (vader_struct_std_collections_MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i32_t));
    vader_obj_header_init(_a21_obj, 427u);
    _a21_obj->f_inner = t0;
    l9 = (void*) _a21_obj;
    vader_array_t* _a22_arr = vader_array_new(14u, 0u, 7u, 247u);
    l10 = (void*) _a22_arr;
    vader_array_t* _a23_arr = vader_array_new(14u, 0u, 7u, 247u);
    l11 = (void*) _a23_arr;
    vader_array_t* _a24_arr = vader_array_new(19u, 0u, 4u, 253u);
    l12 = (void*) _a24_arr;
    vader_array_t* _a25_arr = vader_array_new(21u, 0u, 0u, 255u);
    l13 = (void*) _a25_arr;
    vader_array_t* _a26_arr = vader_array_new(14u, 0u, 7u, 247u);
    l14 = (void*) _a26_arr;
    vader_struct_std_collections_MutableMap__u64__MutableSet_Any__t* _a27_obj = (vader_struct_std_collections_MutableMap__u64__MutableSet_Any__t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__u64__MutableSet_Any__t));
    vader_obj_header_init(_a27_obj, 403u);
    _a27_obj->f_ekeys = l12;
    _a27_obj->f_evals = l13;
    _a27_obj->f_index = l14;
    _a27_obj->f_mask = (size_t) 0;
    _a27_obj->f_size = (size_t) 0;
    _a27_obj->f_tombs = (size_t) 0;
    l12 = (void*) _a27_obj;
    vader_array_t* _a28_arr = vader_array_new(14u, 0u, 7u, 247u);
    l13 = (void*) _a28_arr;
    vader_array_t* _a29_arr = vader_array_new(11u, 0u, 12u, 242u);
    l14 = (void*) _a29_arr;
    vader_array_t* _a30_arr = vader_array_new(14u, 0u, 7u, 247u);
    l15 = (void*) _a30_arr;
    vader_struct_std_collections_MutableMap__i32__bool_t* _a31_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
    vader_obj_header_init(_a31_obj, 329u);
    _a31_obj->f_ekeys = l13;
    _a31_obj->f_evals = l14;
    _a31_obj->f_index = l15;
    _a31_obj->f_mask = (size_t) 0;
    _a31_obj->f_size = (size_t) 0;
    _a31_obj->f_tombs = (size_t) 0;
    t0 = (void*) _a31_obj;
    vader_struct_std_collections_MutableSet__i32_t* _a32_obj = (vader_struct_std_collections_MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i32_t));
    vader_obj_header_init(_a32_obj, 427u);
    _a32_obj->f_inner = t0;
    l13 = (void*) _a32_obj;
    vader_array_t* _a33_arr = vader_array_new(75u, 0u, 13u, 811u);
    l14 = (void*) _a33_arr;
    vader_array_t* _a34_arr = vader_array_new(13u, 0u, 0u, 244u);
    l15 = (void*) _a34_arr;
    vader_array_t* _a35_arr = vader_array_new(21u, 0u, 0u, 255u);
    l16 = (void*) _a35_arr;
    vader_array_t* _a36_arr = vader_array_new(14u, 0u, 7u, 247u);
    l17 = (void*) _a36_arr;
    vader_struct_std_collections_MutableMap__string__Any_t* _a37_obj = (vader_struct_std_collections_MutableMap__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__Any_t));
    vader_obj_header_init(_a37_obj, 336u);
    _a37_obj->f_ekeys = l15;
    _a37_obj->f_evals = l16;
    _a37_obj->f_index = l17;
    _a37_obj->f_mask = (size_t) 0;
    _a37_obj->f_size = (size_t) 0;
    _a37_obj->f_tombs = (size_t) 0;
    t0 = (void*) _a37_obj;
    l15 = vader_resolver_new_scope(t0);
    vader_array_t* _a38_arr = vader_array_new(13u, 0u, 0u, 244u);
    l16 = (void*) _a38_arr;
    vader_array_t* _a39_arr = vader_array_new(21u, 0u, 0u, 255u);
    l17 = (void*) _a39_arr;
    vader_array_t* _a40_arr = vader_array_new(14u, 0u, 7u, 247u);
    l18 = (void*) _a40_arr;
    vader_struct_std_collections_MutableMap__string__Any___t* _a41_obj = (vader_struct_std_collections_MutableMap__string__Any___t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__Any___t));
    vader_obj_header_init(_a41_obj, 338u);
    _a41_obj->f_ekeys = l16;
    _a41_obj->f_evals = l17;
    _a41_obj->f_index = l18;
    _a41_obj->f_mask = (size_t) 0;
    _a41_obj->f_size = (size_t) 0;
    _a41_obj->f_tombs = (size_t) 0;
    l16 = (void*) _a41_obj;
    vader_struct_vader_resolver_ResolveState_t* _a42_obj = (vader_struct_vader_resolver_ResolveState_t*) vader_gc_alloc(sizeof(vader_struct_vader_resolver_ResolveState_t));
    vader_obj_header_init(_a42_obj, 1014u);
    _a42_obj->f_idents = l4;
    _a42_obj->f_immutable_locals = l5;
    _a42_obj->f_immutable_borrows = l6;
    _a42_obj->f_params_immutable_default = true;
    _a42_obj->f_type_param_bounds = l7;
    _a42_obj->f_mutable_decls = l8;
    _a42_obj->f_reassigned = l9;
    _a42_obj->f_declared_locals = l10;
    _a42_obj->f_rebind_log = l11;
    _a42_obj->f_loop_depth = INT32_C(0);
    _a42_obj->f_loop_rebinds = l12;
    _a42_obj->f_lambda_frame = vader_box_obj(0u, NULL);
    _a42_obj->f_closure_rebound = l13;
    _a42_obj->f_diags = l14;
    _a42_obj->f_scope = l15;
    _a42_obj->f_module_path = l2;
    _a42_obj->f_factory = l3;
    _a42_obj->f_ambiguous = l16;
    _a42_obj->f_file_scopes = l1;
    l4 = (void*) _a42_obj;
    l5 = l0;
    l19 = ((vader_array_t*) l5)->length;
    l20 = (size_t) 0;
    for (;;) {
        if ((l20 < l19)) {
            vader_array_t* _a43_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a43_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a43_slotarr, l20)
            l6 = vader_array_ref_load_obj(_a43_slotarr->buf, _a43_slotarr->offset + (size_t) l20);
            l21 = ((vader_struct_toolchain_ast_Program_t*) l6)->f_file;
            l22 = std_collections_MutableMap_Index_at__string__Any(l1, l21);
            if (l22.tag == 0u) {
                l23 = ((vader_struct_toolchain_ast_Program_t*) l6)->f_file;
                t1 = concat_3(2160u, l23, 866u);
                vader_host_std_abort_panic(t1);
                vader_unreachable("a no-return call returned");
            } else {
                l7 = l22.payload.obj;
                vader_resolver_enter_file(l4, l7);
                l8 = ((vader_struct_toolchain_ast_Program_t*) l6)->f_decls;
                l24 = ((vader_array_t*) l8)->length;
                l25 = (size_t) 0;
                while ((l25 < l24)) {
                    vader_array_t* _a44_slotarr = ((vader_array_t*) l8);
                    VADER_ARRAY_RESOLVE_BUF(_a44_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a44_slotarr, l25)
                    l26 = vader_array_ref_load_box(_a44_slotarr->buf, _a44_slotarr->offset + (size_t) l25);
                    vader_resolver_walk_decl(l4, l26);
                    t2 = (l25 + INT64_C(1));
                    l25 = (size_t) (int64_t) t2;
                }
                t2 = (l20 + INT64_C(1));
                l20 = (size_t) (int64_t) t2;
                continue;
            }
        }
        break;
    }
    vader_resolver_report_unreassigned_mutables(l4);
    l5 = ((vader_struct_vader_resolver_ResolveState_t*) l4)->f_idents;
    l6 = ((vader_struct_vader_resolver_ResolveState_t*) l4)->f_immutable_locals;
    l7 = ((vader_struct_vader_resolver_ResolveState_t*) l4)->f_immutable_borrows;
    l8 = vader_resolver_rebind_free_locals(l4);
    l9 = ((vader_struct_vader_resolver_ResolveState_t*) l4)->f_loop_rebinds;
    l10 = ((vader_struct_vader_resolver_ResolveState_t*) l4)->f_closure_rebound;
    l11 = ((vader_struct_vader_resolver_ResolveState_t*) l4)->f_type_param_bounds;
    l4 = ((vader_struct_vader_resolver_ResolveState_t*) l4)->f_diags;
    vader_struct_vader_resolver_ResolvedFile_t* _a45_obj = (vader_struct_vader_resolver_ResolvedFile_t*) vader_gc_alloc(sizeof(vader_struct_vader_resolver_ResolvedFile_t));
    vader_obj_header_init(_a45_obj, 1015u);
    _a45_obj->f_idents = l5;
    _a45_obj->f_immutable_locals = l6;
    _a45_obj->f_immutable_borrows = l7;
    _a45_obj->f_rebind_free = l8;
    _a45_obj->f_loop_rebinds = l9;
    _a45_obj->f_closure_rebound = l10;
    _a45_obj->f_type_param_bounds = l11;
    _a45_obj->f_diags = l4;
    t0 = (void*) _a45_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
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
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 5u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_resolver_IncludePath_t*) l0)->f_prefix;
    if (t0 == 0u) {
        t0 = ((vader_struct_vader_resolver_IncludePath_t*) l0)->f_dir;
        t1 = vader_resolver_join_path(t0, l1);
        t2 = vader_box_string(244u, t1);
        { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = ((vader_struct_vader_resolver_IncludePath_t*) l0)->f_prefix;
    if (l1 == l2) {
        t0 = ((vader_struct_vader_resolver_IncludePath_t*) l0)->f_dir;
        t2 = vader_box_string(244u, t0);
        { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_vader_resolver_IncludePath_t*) l0)->f_prefix;
    l2 = concat_2(t0, 336u);
    t3 = std_string_starts_with(l1, l2);
    if (!(t3)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l2 = ((vader_struct_vader_resolver_IncludePath_t*) l0)->f_dir;
    t0 = ((vader_struct_vader_resolver_IncludePath_t*) l0)->f_prefix;
    l3 = concat_2(t0, 336u);
    l3 = std_string_trim_prefix(l1, l3);
    t0 = vader_resolver_join_path(l2, l3);
    t2 = vader_box_string(244u, t0);
    { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

void vader_resolver_run_orphan_rule_check_for_module(void* l0, vader_string_t l1, void* l2, void* l3, void* l4) {
    void* l5 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l11 = NULL;
    void* l12 = NULL;
    void* l16 = NULL;
    void* l17 = NULL;
    size_t l6, l7, l13, l14;
    vader_string_t l10 = 0;
    vader_box_t l15 = vader_box_null();
    void* t0 = NULL;
    int64_t t1;
    vader_box_t* gc_roots[1] = { &l15 };
    void** gc_raw_roots[12] = { &l0, &l2, &l3, &l4, &l5, &l8, &l9, &l11, &l12, &l16, &l17, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l1, &l10 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 12u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l5 = ((vader_struct_vader_resolver_Module_t*) ((vader_struct_vader_resolver_LoadedModule_t*) l0)->f_module)->f_files;
    l6 = ((vader_array_t*) l5)->length;
    l7 = (size_t) 0;
    while ((l7 < l6)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l7)
        l8 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l7);
        l9 = ((vader_struct_vader_resolver_LoadedModule_t*) l0)->f_collected;
        l10 = ((vader_struct_toolchain_ast_Program_t*) ((vader_struct_vader_resolver_SourceFile_t*) l8)->f_program)->f_file;
        t0 = vader_resolver_file_imports(l9, l10);
        l11 = ((vader_struct_vader_resolver_FileImports_t*) t0)->f_bindings;
        l12 = ((vader_struct_toolchain_ast_Program_t*) ((vader_struct_vader_resolver_SourceFile_t*) l8)->f_program)->f_decls;
        l13 = ((vader_array_t*) l12)->length;
        l14 = (size_t) 0;
        while ((l14 < l13)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l12);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l14)
            l15 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l14);
            if (l15.tag == 480u) {
                l16 = l15.payload.obj;
                l17 = ((vader_struct_vader_resolver_CollectedModule_t*) ((vader_struct_vader_resolver_LoadedModule_t*) l0)->f_collected)->f_symbols;
                vader_resolver_check_orphan_rule(l16, l1, l17, l11, l2, l3, l4);
            }
            t1 = (l14 + INT64_C(1));
            l14 = (size_t) (int64_t) t1;
        }
        t1 = (l7 + INT64_C(1));
        l7 = (size_t) (int64_t) t1;
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_resolver_scan_folder(vader_string_t l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l10 = vader_box_null();
    void* l3 = NULL;
    void* l4 = NULL;
    void* l9 = NULL;
    void* l12 = NULL;
    void* l14 = NULL;
    void* l17 = NULL;
    void* l21 = NULL;
    size_t l5, l6;
    vader_string_t l7 = 0;
    vader_string_t l8 = 0;
    vader_string_t l11 = 0;
    vader_string_t l13 = 0;
    vader_string_t l15 = 0;
    vader_string_t l16 = 0;
    vader_string_t l18 = 0;
    vader_string_t l19 = 0;
    vader_string_t l20 = 0;
    size_t t0;
    vader_box_t t1 = vader_box_null();
    bool t2;
    int64_t t3;
    vader_string_t t4 = 0;
    void* t5 = NULL;
    vader_box_t* gc_roots[3] = { &l2, &l10, &t1 };
    void** gc_raw_roots[9] = { &l1, &l3, &l4, &l9, &l12, &l14, &l17, &l21, &t5 };
    vader_string_t* gc_atom_roots[11] = {
        &l0, &l7, &l8, &l11, &l13, &l15, &l16, &l18, &l19, &l20, &t4,
    };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 9u, gc_roots, gc_raw_roots, 0u, NULL, 11u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = std_io_read_dir(l0);
    if (l2.tag == 13u) {
        l3 = l2.payload.obj;
    } else {
        if (!(l2.tag == 437u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        vader_array_t* _a0_arr = vader_array_new(13u, 0u, 0u, 244u);
        l3 = (void*) _a0_arr;
    }
    t0 = ((vader_array_t*) l3)->length;
    if (t0 == INT64_C(0)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l4 = (void*) &vader_fn_static___lambda_vader_resolver_0;
    l4 = std_sort_sort__string(l3, l4);
    vader_array_t* _a1_arr = vader_array_new(13u, 0u, 0u, 244u);
    l3 = (void*) _a1_arr;
    l5 = ((vader_array_t*) l4)->length;
    l6 = (size_t) 0;
    while ((l6 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l6)
        t1 = vader_array_box_slots(_a2_slotarr->buf)[_a2_slotarr->offset + (size_t) l6];
        l7 = t1.payload.s;
        l8 = vader_resolver_join_path(l0, l7);
        t2 = std_string_ends_with(l7, 335u);
        if (t2) {
            t2 = std_io_is_dir(l8);
            if (!(t2)) {
                vader_array_push((vader_array_t*) l3, vader_box_string(244u, l8));
            }
        }
        t3 = (l6 + INT64_C(1));
        l6 = (size_t) (int64_t) t3;
    }
    t0 = ((vader_array_t*) l3)->length;
    if (t0 == INT64_C(0)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l4 = toolchain_span_empty_span();
    vader_array_t* _a3_arr = vader_array_new(13u, 0u, 0u, 244u);
    l9 = (void*) _a3_arr;
    vader_struct_vader_resolver_FolderBucket_t* _a4_obj = (vader_struct_vader_resolver_FolderBucket_t*) vader_gc_alloc(sizeof(vader_struct_vader_resolver_FolderBucket_t));
    vader_obj_header_init(_a4_obj, 1005u);
    _a4_obj->f_name = 0u;
    _a4_obj->f_first_decl_span = l4;
    _a4_obj->f_files = l9;
    l4 = (void*) _a4_obj;
    l5 = ((vader_array_t*) l3)->length;
    l6 = (size_t) 0;
    while ((l6 < l5)) {
        vader_array_t* _a5_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l6)
        t1 = vader_array_box_slots(_a5_slotarr->buf)[_a5_slotarr->offset + (size_t) l6];
        l7 = t1.payload.s;
        l2 = std_io_read_file_string(l7, (size_t) 16777216);
        if (l2.tag == 244u) {
            l8 = l2.payload.s;
        } else {
            if (!(l2.tag == 437u)) {
                vader_unreachable("non-exhaustive match (T3013 should have caught this)");
            }
            l8 = 0u;
        }
        if (l8 == 0u) {
            t3 = (l6 + INT64_C(1));
            l6 = (size_t) (int64_t) t3;
            continue;
        }
        vader_array_push((vader_array_t*) ((vader_struct_vader_resolver_FolderBucket_t*) l4)->f_files, vader_box_string(244u, l7));
        l10 = vader_parser_parse_module_header(l8, l7);
        if (l10.tag == 0u) {
            l9 = toolchain_span_empty_span();
            l11 = concat_3(866u, l7, 866u);
            l12 = vader_diagnostics_resolver_error((uint8_t) 19, l9, l11);
            vader_array_push((vader_array_t*) l1, vader_ref_box(l12));
        } else {
            if (!(l10.tag == 996u)) {
                vader_unreachable("non-exhaustive match (T3013 should have caught this)");
            }
            t4 = ((vader_struct_vader_resolver_FolderBucket_t*) l4)->f_name;
            if (t4 == 0u) {
                t5 = l10.payload.obj;
                l13 = ((vader_struct_vader_parser_ModuleHeader_t*) t5)->f_name;
                ((vader_struct_vader_resolver_FolderBucket_t*) l4)->f_name = l13;
                VADER_WRITE_BARRIER((vader_struct_vader_resolver_FolderBucket_t*) l4);
                t5 = l10.payload.obj;
                l14 = ((vader_struct_vader_parser_ModuleHeader_t*) t5)->f_name_span;
                ((vader_struct_vader_resolver_FolderBucket_t*) l4)->f_first_decl_span = l14;
                VADER_WRITE_BARRIER((vader_struct_vader_resolver_FolderBucket_t*) l4);
            } else {
                t5 = l10.payload.obj;
                l15 = ((vader_struct_vader_parser_ModuleHeader_t*) t5)->f_name;
                l16 = ((vader_struct_vader_resolver_FolderBucket_t*) l4)->f_name;
                if (l15 != l16) {
                    t5 = l10.payload.obj;
                    l17 = ((vader_struct_vader_parser_ModuleHeader_t*) t5)->f_name_span;
                    t5 = l10.payload.obj;
                    l18 = ((vader_struct_vader_parser_ModuleHeader_t*) t5)->f_name;
                    l19 = ((vader_struct_vader_resolver_FolderBucket_t*) l4)->f_name;
                    l20 = concat_5(866u, l18, 896u, l19, 1034u);
                    l21 = vader_diagnostics_resolver_error((uint8_t) 21, l17, l20);
                    vader_array_push((vader_array_t*) l1, vader_ref_box(l21));
                }
            }
        }
        t3 = (l6 + INT64_C(1));
        l6 = (size_t) (int64_t) t3;
    }
    { vader_box_t __vret = vader_ref_box(l4); vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_resolver_search_roots(vader_string_t l0, void* l1, void* l2) {
    vader_box_t l3 = vader_box_null(), l7 = vader_box_null();
    void* l4 = NULL;
    void* l8 = NULL;
    vader_string_t l5 = 0;
    vader_string_t l6 = 0;
    vader_string_t l9 = 0;
    vader_string_t t0 = 0;
    void* t1 = NULL;
    vader_box_t* gc_roots[2] = { &l3, &l7 };
    void** gc_raw_roots[5] = { &l1, &l2, &l4, &l8, &t1 };
    vader_string_t* gc_atom_roots[5] = { &l0, &l5, &l6, &l9, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 5u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = vader_resolver_find_manifest_root(l0);
    if (l3.tag == 244u) {
        t0 = l3.payload.s;
        l4 = vader_resolver_read_manifest(t0);
    } else {
        if (!(l3.tag == 0u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        vader_array_t* _a0_arr = vader_array_new(13u, 0u, 0u, 244u);
        t1 = (void*) _a0_arr;
        vader_struct_vader_resolver_Manifest_t* _a1_obj = (vader_struct_vader_resolver_Manifest_t*) vader_gc_alloc(sizeof(vader_struct_vader_resolver_Manifest_t));
        vader_obj_header_init(_a1_obj, 1011u);
        _a1_obj->f_include_paths = t1;
        l4 = (void*) _a1_obj;
    }
    l5 = vader_resolver_entry_folder_of(l0);
    l4 = vader_resolver_project_include_paths(l3, l4, l1);
    l6 = vader_resolver_generated_root_for(l3);
    l7 = vader_resolver_seed_entry(l5, l2);
    if (l7.tag == 0u) {
        l8 = l4;
        vader_struct_vader_resolver_SearchRoots_t* _a2_obj = (vader_struct_vader_resolver_SearchRoots_t*) vader_gc_alloc(sizeof(vader_struct_vader_resolver_SearchRoots_t));
        vader_obj_header_init(_a2_obj, 1018u);
        _a2_obj->f_project_root = l3;
        _a2_obj->f_entry = l7;
        _a2_obj->f_paths = l8;
        t1 = (void*) _a2_obj;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = l7.payload.obj;
    l5 = ((vader_struct_vader_resolver_DiscoveredModule_t*) t1)->f_name;
    t1 = l7.payload.obj;
    l9 = ((vader_struct_vader_resolver_DiscoveredModule_t*) t1)->f_folder;
    l8 = vader_resolver_include_paths(l5, l9, l4, l6);
    vader_struct_vader_resolver_SearchRoots_t* _a3_obj = (vader_struct_vader_resolver_SearchRoots_t*) vader_gc_alloc(sizeof(vader_struct_vader_resolver_SearchRoots_t));
    vader_obj_header_init(_a3_obj, 1018u);
    _a3_obj->f_project_root = l3;
    _a3_obj->f_entry = l7;
    _a3_obj->f_paths = l8;
    t1 = (void*) _a3_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_resolver_seed_entry(vader_string_t l0, void* l1) {
    void* l2 = NULL;
    vader_box_t l3 = vader_box_null();
    vader_string_t l4 = 0;
    vader_string_t t0 = 0;
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &l3 };
    void** gc_raw_roots[3] = { &l1, &l2, &t1 };
    vader_string_t* gc_atom_roots[3] = { &l0, &l4, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = vader_resolver_scan_folder(l0, l1);
    if (l3.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l2 = l3.payload.obj;
    t0 = ((vader_struct_vader_resolver_FolderBucket_t*) l2)->f_name;
    if (!(t0 == 0u)) {
        l4 = ((vader_struct_vader_resolver_FolderBucket_t*) l2)->f_name;
        l2 = ((vader_struct_vader_resolver_FolderBucket_t*) l2)->f_files;
        vader_struct_vader_resolver_DiscoveredModule_t* _a0_obj = (vader_struct_vader_resolver_DiscoveredModule_t*) vader_gc_alloc(sizeof(vader_struct_vader_resolver_DiscoveredModule_t));
        vader_obj_header_init(_a0_obj, 1002u);
        _a0_obj->f_name = l4;
        _a0_obj->f_folder = l0;
        _a0_obj->f_files = l2;
        _a0_obj->f_origin = (uint8_t) 0;
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static void vader_resolver_seed_wildcard_exports(void* l0, void* l1, void* l2, void* l3) {
    void* l4 = NULL;
    void* l8 = NULL;
    void* l11 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    void* l16 = NULL;
    size_t l5, l6, l14, l15;
    vader_string_t l7 = 0;
    vader_string_t l17 = 0;
    vader_string_t l18 = 0;
    vader_box_t l9 = vader_box_null(), l10 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    int64_t t1;
    vader_string_t t2 = 0;
    bool t3;
    vader_box_t* gc_roots[3] = { &l9, &l10, &t0 };
    void** gc_raw_roots[10] = { &l0, &l1, &l2, &l3, &l4, &l8, &l11, &l12, &l13, &l16 };
    vader_string_t* gc_atom_roots[4] = { &l7, &l17, &l18, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 10u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = l2;
    l5 = ((vader_array_t*) l4)->length;
    l6 = (size_t) 0;
    while ((l6 < l5)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l6)
        t0 = vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l6];
        l7 = t0.payload.s;
        l9 = std_collections_MutableMap_Index_at__string__Any(l1, l7);
        if (l9.tag == 0u) {
            t1 = (l6 + INT64_C(1));
            l6 = (size_t) (int64_t) t1;
            continue;
        }
        l8 = l9.payload.obj;
        l10 = std_collections_MutableMap_Index_at__string__Any(l3, l7);
        l11 = ((vader_struct_vader_resolver_CollectedModule_t*) ((vader_struct_vader_resolver_LoadedModule_t*) l8)->f_collected)->f_symbols;
        l12 = ((vader_struct_std_collections_MutableMap__string__Symbol_t*) l11)->f_ekeys;
        l13 = ((vader_struct_std_collections_MutableMap__string__Symbol_t*) l11)->f_evals;
        l14 = ((vader_struct_std_collections_MutableMap__string__Symbol_t*) l11)->f_size;
        l15 = (size_t) 0;
        while (!((l15 >= l14))) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l12);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l15)
            t0 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l15];
            t2 = t0.payload.s;
            vader_array_t* _a2_slotarr = ((vader_array_t*) l13);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l15)
            l16 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l15);
            t1 = (l15 + INT64_C(1));
            l15 = (size_t) (int64_t) t1;
            t3 = vader_resolver_wildcard_exposes(l16, l10);
            if (!(t3)) {
                continue;
            }
            l17 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l16)->f_name;
            t0 = std_collections_MutableMap_Index_at__string__Any(l0, l17);
            if (!(t0.tag == 0u)) {
                continue;
            }
            l18 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l16)->f_name;
            std_collections_MutableMap_IndexSet_set_at__string__Any(l0, l18, vader_ref_box(l16));
        }
        t1 = (l6 + INT64_C(1));
        l6 = (size_t) (int64_t) t1;
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void* vader_resolver_select_target_bodies(void* l0, vader_box_t l1, void* l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l13 = NULL;
    void* l16 = NULL;
    void* l27 = NULL;
    void* l28 = NULL;
    void* l30 = NULL;
    void* l33 = NULL;
    void* l34 = NULL;
    void* l35 = NULL;
    size_t l8, l9, l10, l11, l17, l18;
    vader_box_t l12 = vader_box_null(), l14 = vader_box_null(), l21 = vader_box_null(), l31 = vader_box_null(), l32 = vader_box_null();
    vader_string_t l15 = 0;
    vader_string_t l20 = 0;
    vader_string_t l22 = 0;
    vader_string_t l23 = 0;
    vader_string_t l24 = 0;
    vader_string_t l25 = 0;
    vader_string_t l26 = 0;
    vader_string_t l29 = 0;
    uint8_t l19;
    void* t0 = NULL;
    int64_t t1;
    bool t2;
    vader_box_t t3 = vader_box_null();
    vader_box_t* gc_roots[7] = { &l1, &l12, &l14, &l21, &l31, &l32, &t3 };
    void** gc_raw_roots[16] = {
        &l0, &l2, &l3, &l4, &l5, &l6, &l7, &l13, &l16, &l27, &l28, &l30, &l33, &l34, &l35, &t0,
    };
    vader_string_t* gc_atom_roots[8] = { &l15, &l20, &l22, &l23, &l24, &l25, &l26, &l29 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 7u, 16u, gc_roots, gc_raw_roots, 0u, NULL, 8u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_resolver_check_selectors(l0, l2);
    vader_resolver_check_groups(l0, l2);
    if (l1.tag == 0u) {
        { void* __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a0_arr = vader_array_new(13u, 0u, 0u, 244u);
    l3 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(21u, 0u, 0u, 255u);
    l4 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(14u, 0u, 7u, 247u);
    l5 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__string__Any_t* _a3_obj = (vader_struct_std_collections_MutableMap__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__Any_t));
    vader_obj_header_init(_a3_obj, 336u);
    _a3_obj->f_ekeys = l3;
    _a3_obj->f_evals = l4;
    _a3_obj->f_index = l5;
    _a3_obj->f_mask = (size_t) 0;
    _a3_obj->f_size = (size_t) 0;
    _a3_obj->f_tombs = (size_t) 0;
    l3 = (void*) _a3_obj;
    vader_array_t* _a4_arr = vader_array_new(13u, 0u, 0u, 244u);
    l4 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_new(11u, 0u, 12u, 242u);
    l5 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(14u, 0u, 7u, 247u);
    l6 = (void*) _a6_arr;
    vader_struct_std_collections_MutableMap__string__bool_t* _a7_obj = (vader_struct_std_collections_MutableMap__string__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__bool_t));
    vader_obj_header_init(_a7_obj, 384u);
    _a7_obj->f_ekeys = l4;
    _a7_obj->f_evals = l5;
    _a7_obj->f_index = l6;
    _a7_obj->f_mask = (size_t) 0;
    _a7_obj->f_size = (size_t) 0;
    _a7_obj->f_tombs = (size_t) 0;
    l4 = (void*) _a7_obj;
    vader_array_t* _a8_arr = vader_array_new(13u, 0u, 0u, 244u);
    l5 = (void*) _a8_arr;
    vader_array_t* _a9_arr = vader_array_new(13u, 0u, 0u, 244u);
    l6 = (void*) _a9_arr;
    vader_array_t* _a10_arr = vader_array_new(14u, 0u, 7u, 247u);
    l7 = (void*) _a10_arr;
    vader_struct_std_collections_MutableMap__string__string_t* _a11_obj = (vader_struct_std_collections_MutableMap__string__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__string_t));
    vader_obj_header_init(_a11_obj, 388u);
    _a11_obj->f_ekeys = l5;
    _a11_obj->f_evals = l6;
    _a11_obj->f_index = l7;
    _a11_obj->f_mask = (size_t) 0;
    _a11_obj->f_size = (size_t) 0;
    _a11_obj->f_tombs = (size_t) 0;
    l5 = (void*) _a11_obj;
    l6 = l0;
    l8 = ((vader_array_t*) l6)->length;
    l9 = (size_t) 0;
    while ((l9 < l8)) {
        vader_array_t* _a12_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a12_slotarr, l9)
        t0 = vader_array_ref_load_obj(_a12_slotarr->buf, _a12_slotarr->offset + (size_t) l9);
        l7 = ((vader_struct_toolchain_ast_Program_t*) ((vader_struct_vader_resolver_SourceFile_t*) t0)->f_program)->f_decls;
        l10 = ((vader_array_t*) l7)->length;
        l11 = (size_t) 0;
        while ((l11 < l10)) {
            vader_array_t* _a13_slotarr = ((vader_array_t*) l7);
            VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a13_slotarr, l11)
            l12 = vader_array_ref_load_box(_a13_slotarr->buf, _a13_slotarr->offset + (size_t) l11);
            if (l12.tag == 471u) {
                t0 = l12.payload.obj;
                l14 = vader_resolver_target_selectors(((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_decorators);
                if (l14.tag == 0u) {
                    t1 = (l11 + INT64_C(1));
                    l11 = (size_t) (int64_t) t1;
                    continue;
                }
                l13 = l14.payload.obj;
                t2 = ((vader_struct_vader_resolver_TargetSelectors_t*) l13)->f_is_bare;
                if (t2) {
                    t0 = l12.payload.obj;
                    l15 = ((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_name;
                    std_collections_MutableMap_IndexSet_set_at__string__bool(l4, l15, true);
                } else {
                    l16 = ((vader_struct_vader_resolver_TargetSelectors_t*) l13)->f_os;
                    l17 = ((vader_array_t*) l16)->length;
                    l18 = (size_t) 0;
                    while ((l18 < l17)) {
                        vader_array_t* _a14_slotarr = ((vader_array_t*) l16);
                        VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a14_slotarr, l18)
                        t3 = vader_array_read_u8(_a14_slotarr, _a14_slotarr->offset + (size_t) l18, 250u);
                        l19 = ((uint8_t) t3.payload.i);
                        t0 = l12.payload.obj;
                        l20 = ((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_name;
                        l21 = std_collections_MutableMap_Index_at__string__string(l5, l20);
                        t0 = l12.payload.obj;
                        l22 = ((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_name;
                        if (l21.tag == 0u) {
                            l24 = std_target_Os_Display_to_string(l19);
                            l23 = concat_2(309u, l24);
                        } else {
                            l25 = l21.payload.s;
                            l26 = std_target_Os_Display_to_string(l19);
                            l23 = concat_3(l25, 280u, l26);
                        }
                        std_collections_MutableMap_IndexSet_set_at__string__string(l5, l22, l23);
                        t1 = (l18 + INT64_C(1));
                        l18 = (size_t) (int64_t) t1;
                    }
                    l27 = ((vader_struct_vader_resolver_TargetSelectors_t*) l13)->f_os;
                    l28 = l1.payload.obj;
                    t2 = vader_resolver_matches_target(l27, l28);
                    if (t2) {
                        t0 = l12.payload.obj;
                        l29 = ((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_name;
                        l30 = l12.payload.obj;
                        std_collections_MutableMap_IndexSet_set_at__string__Any(l3, l29, vader_ref_box(l30));
                    }
                }
            }
            t1 = (l11 + INT64_C(1));
            l11 = (size_t) (int64_t) t1;
        }
        t1 = (l9 + INT64_C(1));
        l9 = (size_t) (int64_t) t1;
    }
    l6 = l1.payload.obj;
    vader_resolver_report_uncovered(l0, l6, l3, l5, l2);
    vader_array_t* _a15_arr = vader_array_new(124u, 0u, 13u, 1019u);
    l5 = (void*) _a15_arr;
    l8 = ((vader_array_t*) l0)->length;
    vader_array_t* _a16_arr = vader_array_repeat((vader_array_t*) l5, (size_t) l8);
    l5 = (void*) _a16_arr;
    l6 = l0;
    l8 = ((vader_array_t*) l6)->length;
    l9 = (size_t) 0;
    while ((l9 < l8)) {
        vader_array_t* _a17_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a17_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a17_slotarr, l9)
        l7 = vader_array_ref_load_obj(_a17_slotarr->buf, _a17_slotarr->offset + (size_t) l9);
        vader_array_t* _a18_arr = vader_array_new(180u, 0u, 13u, 1273u);
        l13 = (void*) _a18_arr;
        l16 = ((vader_struct_toolchain_ast_Program_t*) ((vader_struct_vader_resolver_SourceFile_t*) l7)->f_program)->f_decls;
        l10 = ((vader_array_t*) l16)->length;
        l11 = (size_t) 0;
        while ((l11 < l10)) {
            vader_array_t* _a19_slotarr = ((vader_array_t*) l16);
            VADER_ARRAY_RESOLVE_BUF(_a19_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a19_slotarr, l11)
            l12 = vader_array_ref_load_box(_a19_slotarr->buf, _a19_slotarr->offset + (size_t) l11);
            l27 = l1.payload.obj;
            l14 = vader_resolver_resolve_decl(l12, l27, l3, l4);
            if (!(l14.tag == 0u)) {
                l21 = l14;
                vader_array_push((vader_array_t*) l13, l21);
            }
            t1 = (l11 + INT64_C(1));
            l11 = (size_t) (int64_t) t1;
        }
        l28 = l7;
        l15 = ((vader_struct_vader_resolver_SourceFile_t*) l28)->f_path;
        l20 = ((vader_struct_vader_resolver_SourceFile_t*) l28)->f_content;
        l30 = ((vader_struct_vader_resolver_SourceFile_t*) l7)->f_program;
        l22 = ((vader_struct_toolchain_ast_Program_t*) l30)->f_file;
        t0 = ((vader_struct_toolchain_ast_Program_t*) l30)->f_span;
        l31 = vader_ref_box(t0);
        l17 = ((vader_struct_toolchain_ast_Program_t*) l30)->f_id;
        l32 = ((vader_struct_toolchain_ast_Program_t*) l30)->f_module;
        vader_struct_toolchain_ast_Program_t* _a20_obj = (vader_struct_toolchain_ast_Program_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_Program_t));
        vader_obj_header_init(_a20_obj, 504u);
        _a20_obj->f_file = l22;
        _a20_obj->f_span = l31.payload.obj;
        _a20_obj->f_id = l17;
        _a20_obj->f_module = l32;
        _a20_obj->f_decls = l13;
        l33 = (void*) _a20_obj;
        l34 = ((vader_struct_vader_resolver_SourceFile_t*) l28)->f_id_factory;
        vader_struct_vader_resolver_SourceFile_t* _a21_obj = (vader_struct_vader_resolver_SourceFile_t*) vader_gc_alloc(sizeof(vader_struct_vader_resolver_SourceFile_t));
        vader_obj_header_init(_a21_obj, 1019u);
        _a21_obj->f_path = l15;
        _a21_obj->f_content = l20;
        _a21_obj->f_program = l33;
        _a21_obj->f_id_factory = l34;
        l35 = (void*) _a21_obj;
        vader_array_push((vader_array_t*) l5, vader_ref_box(l35));
        t1 = (l9 + INT64_C(1));
        l9 = (size_t) (int64_t) t1;
    }
    { void* __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
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
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 0u, gc_roots, NULL, 0u, NULL, 5u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_resolver_home_root(l0, l1);
    if (!(l2.tag == 0u)) {
        t0 = l2.payload.s;
        t1 = vader_box_string(244u, t0);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = std_io_current_executable_location();
    t2 = vader_resolver_dir_of(t0);
    l3 = vader_resolver_join_path(t2, l0);
    t0 = vader_resolver_join_path(l3, l1);
    t3 = std_io_exists(t0);
    if (!(t3)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    t1 = vader_box_string(244u, l3);
    { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_resolver_sort_by_name(void* l0) {
    void* l1 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[3] = { &l0, &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = (void*) &vader_fn_static___lambda_vader_resolver_1;
    t0 = std_sort_sort__Symbol(l0, l1);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
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
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct_toolchain_span_Position_t*) ((vader_struct_toolchain_span_Span_t*) l0)->f_start)->f_file;
    l2 = vader_host_std_core_byte_len(l1);
    l3 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(21) + l2));
    l2 = (size_t) 0;
    l2 = std_core_write_string_at(l3, l2, l1);
    l2 = std_core_write_string_at(l3, l2, 353u);
    t0 = ((vader_struct_toolchain_span_Position_t*) ((vader_struct_toolchain_span_Span_t*) l0)->f_start)->f_line;
    l4 = ((int64_t) (int32_t) t0);
    l2 = std_core_write_int(l3, l2, l4);
    t1 = std_core_finish_buffer(l3, l2);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
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
    if (l0.tag == 511u) {
        l2 = l0.payload.obj;
        l3 = vader_resolver_next_clone_span(l1);
        ((vader_struct_toolchain_ast_SimpleBinding_t*) l2)->f_span = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_SimpleBinding_t*) l2);
        l2 = l0.payload.obj;
        l3 = vader_resolver_next_clone_span(l1);
        ((vader_struct_toolchain_ast_SimpleBinding_t*) l2)->f_name_span = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_SimpleBinding_t*) l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 523u) {
        l2 = l0.payload.obj;
        l3 = vader_resolver_next_clone_span(l1);
        ((vader_struct_toolchain_ast_TupleBinding_t*) l2)->f_span = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_TupleBinding_t*) l2);
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast_TupleBinding_t*) t0)->f_elements;
        l4 = ((vader_array_t*) l2)->length;
        l5 = (size_t) 0;
        while ((l5 < l4)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
            t1 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
            vader_resolver_stamp_binding_spans(t1, l1);
            t2 = (l5 + INT64_C(1));
            l5 = (size_t) (int64_t) t2;
        }
    } else if (l0.tag == 528u) {
        l2 = l0.payload.obj;
        l3 = vader_resolver_next_clone_span(l1);
        ((vader_struct_toolchain_ast_WildcardBinding_t*) l2)->f_span = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_WildcardBinding_t*) l2);
    } else {
        if (!(l0.tag == 507u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l2 = l0.payload.obj;
        l3 = vader_resolver_next_clone_span(l1);
        ((vader_struct_toolchain_ast_RestBinding_t*) l2)->f_span = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_RestBinding_t*) l2);
        l2 = l0.payload.obj;
        l3 = vader_resolver_next_clone_span(l1);
        ((vader_struct_toolchain_ast_RestBinding_t*) l2)->f_name_span = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_RestBinding_t*) l2);
    }
    { vader_gc_top = gc_frame.prev; return; }
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
    l4 = (size_t) 0;
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        t0 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        vader_resolver_stamp_stmt_spans(t0, l1);
        t1 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t1;
    }
    if (((vader_struct_toolchain_ast_BlockExpr_t*) l0)->f_trailing.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_resolver_stamp_expr_spans(((vader_struct_toolchain_ast_BlockExpr_t*) l0)->f_trailing, l1);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_resolver_stamp_expr_spans(vader_box_t l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l6 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    size_t l4, l5;
    vader_box_t l7 = vader_box_null(), l9 = vader_box_null();
    vader_string_t l8 = 0;
    void* t0 = NULL;
    int64_t t1;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[4] = { &l0, &l7, &l9, &t2 };
    void** gc_raw_roots[9] = { &l1, &l2, &l3, &l6, &l10, &l11, &l12, &l13, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l8 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 9u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l0.tag == 486u) {
        l2 = l0.payload.obj;
        l3 = vader_resolver_next_clone_span(l1);
        ((vader_struct_toolchain_ast_IntLitExpr_t*) l2)->f_span = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_IntLitExpr_t*) l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 470u) {
        l2 = l0.payload.obj;
        l3 = vader_resolver_next_clone_span(l1);
        ((vader_struct_toolchain_ast_FloatLitExpr_t*) l2)->f_span = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_FloatLitExpr_t*) l2);
    } else if (l0.tag == 448u) {
        l2 = l0.payload.obj;
        l3 = vader_resolver_next_clone_span(l1);
        ((vader_struct_toolchain_ast_BoolLitExpr_t*) l2)->f_span = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_BoolLitExpr_t*) l2);
    } else if (l0.tag == 499u) {
        l2 = l0.payload.obj;
        l3 = vader_resolver_next_clone_span(l1);
        ((vader_struct_toolchain_ast_NullLitExpr_t*) l2)->f_span = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_NullLitExpr_t*) l2);
    } else if (l0.tag == 453u) {
        l2 = l0.payload.obj;
        l3 = vader_resolver_next_clone_span(l1);
        ((vader_struct_toolchain_ast_CharLitExpr_t*) l2)->f_span = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_CharLitExpr_t*) l2);
    } else if (l0.tag == 476u) {
        l2 = l0.payload.obj;
        l3 = vader_resolver_next_clone_span(l1);
        ((vader_struct_toolchain_ast_IdentExpr_t*) l2)->f_span = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_IdentExpr_t*) l2);
    } else if (l0.tag == 451u) {
        l2 = l0.payload.obj;
        l3 = vader_resolver_next_clone_span(l1);
        ((vader_struct_toolchain_ast_CallExpr_t*) l2)->f_span = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_CallExpr_t*) l2);
        t0 = l0.payload.obj;
        vader_resolver_stamp_expr_spans(((vader_struct_toolchain_ast_CallExpr_t*) t0)->f_callee, l1);
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast_CallExpr_t*) t0)->f_args;
        l4 = ((vader_array_t*) l2)->length;
        l5 = (size_t) 0;
        while ((l5 < l4)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
            l3 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
            l6 = vader_resolver_next_clone_span(l1);
            ((vader_struct_toolchain_ast_CallArg_t*) l3)->f_span = l6;
            VADER_WRITE_BARRIER((vader_struct_toolchain_ast_CallArg_t*) l3);
            vader_resolver_stamp_expr_spans(((vader_struct_toolchain_ast_CallArg_t*) l3)->f_value, l1);
            t1 = (l5 + INT64_C(1));
            l5 = (size_t) (int64_t) t1;
        }
    } else if (l0.tag == 469u) {
        l2 = l0.payload.obj;
        l3 = vader_resolver_next_clone_span(l1);
        ((vader_struct_toolchain_ast_FieldExpr_t*) l2)->f_span = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_FieldExpr_t*) l2);
        t0 = l0.payload.obj;
        vader_resolver_stamp_expr_spans(((vader_struct_toolchain_ast_FieldExpr_t*) t0)->f_target, l1);
    } else if (l0.tag == 484u) {
        l2 = l0.payload.obj;
        l3 = vader_resolver_next_clone_span(l1);
        ((vader_struct_toolchain_ast_IndexExpr_t*) l2)->f_span = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_IndexExpr_t*) l2);
        t0 = l0.payload.obj;
        vader_resolver_stamp_expr_spans(((vader_struct_toolchain_ast_IndexExpr_t*) t0)->f_target, l1);
        t0 = l0.payload.obj;
        vader_resolver_stamp_expr_spans(((vader_struct_toolchain_ast_IndexExpr_t*) t0)->f_index, l1);
    } else if (l0.tag == 526u) {
        l2 = l0.payload.obj;
        l3 = vader_resolver_next_clone_span(l1);
        ((vader_struct_toolchain_ast_UnaryExpr_t*) l2)->f_span = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_UnaryExpr_t*) l2);
        t0 = l0.payload.obj;
        vader_resolver_stamp_expr_spans(((vader_struct_toolchain_ast_UnaryExpr_t*) t0)->f_operand, l1);
    } else if (l0.tag == 446u) {
        l2 = l0.payload.obj;
        l3 = vader_resolver_next_clone_span(l1);
        ((vader_struct_toolchain_ast_BinaryExpr_t*) l2)->f_span = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_BinaryExpr_t*) l2);
        t0 = l0.payload.obj;
        vader_resolver_stamp_expr_spans(((vader_struct_toolchain_ast_BinaryExpr_t*) t0)->f_left, l1);
        t0 = l0.payload.obj;
        vader_resolver_stamp_expr_spans(((vader_struct_toolchain_ast_BinaryExpr_t*) t0)->f_right, l1);
        t0 = l0.payload.obj;
        l7 = ((vader_struct_toolchain_ast_BinaryExpr_t*) t0)->f_bind_as;
        if (!(l7.tag == 0u)) {
            l2 = l0.payload.obj;
            t0 = l7.payload.obj;
            l8 = ((vader_struct_toolchain_ast_AsBinding_t*) t0)->f_name;
            l3 = vader_resolver_next_clone_span(l1);
            vader_struct_toolchain_ast_AsBinding_t* _a1_obj = (vader_struct_toolchain_ast_AsBinding_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_AsBinding_t));
            vader_obj_header_init(_a1_obj, 442u);
            _a1_obj->f_name = l8;
            _a1_obj->f_span = l3;
            l3 = (void*) _a1_obj;
            ((vader_struct_toolchain_ast_BinaryExpr_t*) l2)->f_bind_as = vader_ref_box(l3);
            VADER_WRITE_BARRIER((vader_struct_toolchain_ast_BinaryExpr_t*) l2);
        }
    } else if (l0.tag == 479u) {
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
        l9 = l7;
        if (!(l7.tag == 0u)) {
            if (l7.tag == 477u) {
                t0 = l9.payload.obj;
                vader_resolver_stamp_block_spans(((vader_struct_toolchain_ast_IfElseBlock_t*) t0)->f_block, l1);
            } else {
                if (!(l7.tag == 478u)) {
                    vader_unreachable("non-exhaustive match (T3013 should have caught this)");
                }
                t0 = l9.payload.obj;
                vader_resolver_stamp_expr_spans(vader_ref_box(((vader_struct_toolchain_ast_IfElseIf_t*) t0)->f_branch), l1);
            }
        }
    } else if (l0.tag == 493u) {
        l2 = l0.payload.obj;
        l3 = vader_resolver_next_clone_span(l1);
        ((vader_struct_toolchain_ast_MatchExpr_t*) l2)->f_span = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_MatchExpr_t*) l2);
        t0 = l0.payload.obj;
        vader_resolver_stamp_expr_spans(((vader_struct_toolchain_ast_MatchExpr_t*) t0)->f_scrutinee, l1);
        t0 = l0.payload.obj;
        l7 = ((vader_struct_toolchain_ast_MatchExpr_t*) t0)->f_bind_as;
        if (!(l7.tag == 0u)) {
            l2 = l0.payload.obj;
            t0 = l7.payload.obj;
            l8 = ((vader_struct_toolchain_ast_AsBinding_t*) t0)->f_name;
            l3 = vader_resolver_next_clone_span(l1);
            vader_struct_toolchain_ast_AsBinding_t* _a2_obj = (vader_struct_toolchain_ast_AsBinding_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_AsBinding_t));
            vader_obj_header_init(_a2_obj, 442u);
            _a2_obj->f_name = l8;
            _a2_obj->f_span = l3;
            l3 = (void*) _a2_obj;
            ((vader_struct_toolchain_ast_MatchExpr_t*) l2)->f_bind_as = vader_ref_box(l3);
            VADER_WRITE_BARRIER((vader_struct_toolchain_ast_MatchExpr_t*) l2);
        }
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast_MatchExpr_t*) t0)->f_arms;
        l4 = ((vader_array_t*) l2)->length;
        l5 = (size_t) 0;
        while ((l5 < l4)) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l5)
            l3 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l5);
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
        }
    } else if (l0.tag == 447u) {
        t0 = l0.payload.obj;
        vader_resolver_stamp_block_spans(t0, l1);
    } else if (l0.tag == 517u) {
        l2 = l0.payload.obj;
        l3 = vader_resolver_next_clone_span(l1);
        ((vader_struct_toolchain_ast_StructLitExpr_t*) l2)->f_span = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_StructLitExpr_t*) l2);
        t0 = l0.payload.obj;
        vader_resolver_stamp_expr_spans(((vader_struct_toolchain_ast_StructLitExpr_t*) t0)->f_type_name, l1);
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast_StructLitExpr_t*) t0)->f_items;
        l4 = ((vader_array_t*) l2)->length;
        l5 = (size_t) 0;
        while ((l5 < l4)) {
            vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l5)
            l7 = vader_array_ref_load_box(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l5);
            if (l7.tag == 518u) {
                l3 = l7.payload.obj;
                l6 = vader_resolver_next_clone_span(l1);
                ((vader_struct_toolchain_ast_StructLitField_t*) l3)->f_span = l6;
                VADER_WRITE_BARRIER((vader_struct_toolchain_ast_StructLitField_t*) l3);
                l10 = l7.payload.obj;
                l11 = vader_resolver_next_clone_span(l1);
                ((vader_struct_toolchain_ast_StructLitField_t*) l10)->f_name_span = l11;
                VADER_WRITE_BARRIER((vader_struct_toolchain_ast_StructLitField_t*) l10);
                t0 = l7.payload.obj;
                vader_resolver_stamp_expr_spans(((vader_struct_toolchain_ast_StructLitField_t*) t0)->f_value, l1);
            } else {
                if (!(l7.tag == 519u)) {
                    vader_unreachable("non-exhaustive match (T3013 should have caught this)");
                }
                l12 = l7.payload.obj;
                l13 = vader_resolver_next_clone_span(l1);
                ((vader_struct_toolchain_ast_StructLitSpread_t*) l12)->f_span = l13;
                VADER_WRITE_BARRIER((vader_struct_toolchain_ast_StructLitSpread_t*) l12);
                t0 = l7.payload.obj;
                vader_resolver_stamp_expr_spans(((vader_struct_toolchain_ast_StructLitSpread_t*) t0)->f_expr, l1);
            }
            t1 = (l5 + INT64_C(1));
            l5 = (size_t) (int64_t) t1;
        }
    } else if (l0.tag == 510u) {
        l2 = l0.payload.obj;
        l3 = vader_resolver_next_clone_span(l1);
        ((vader_struct_toolchain_ast_SeqLitExpr_t*) l2)->f_span = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_SeqLitExpr_t*) l2);
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast_SeqLitExpr_t*) t0)->f_elements;
        l4 = ((vader_array_t*) l2)->length;
        l5 = (size_t) 0;
        while ((l5 < l4)) {
            vader_array_t* _a5_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l5)
            t2 = vader_array_ref_load_box(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l5);
            vader_resolver_stamp_expr_spans(t2, l1);
            t1 = (l5 + INT64_C(1));
            l5 = (size_t) (int64_t) t1;
        }
    } else if (l0.tag == 505u) {
        l2 = l0.payload.obj;
        l3 = vader_resolver_next_clone_span(l1);
        ((vader_struct_toolchain_ast_RangeExpr_t*) l2)->f_span = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_RangeExpr_t*) l2);
        t0 = l0.payload.obj;
        vader_resolver_stamp_expr_spans(((vader_struct_toolchain_ast_RangeExpr_t*) t0)->f_lower, l1);
        t0 = l0.payload.obj;
        vader_resolver_stamp_expr_spans(((vader_struct_toolchain_ast_RangeExpr_t*) t0)->f_upper, l1);
    } else if (l0.tag == 445u) {
        l2 = l0.payload.obj;
        l3 = vader_resolver_next_clone_span(l1);
        ((vader_struct_toolchain_ast_AwaitExpr_t*) l2)->f_span = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_AwaitExpr_t*) l2);
        t0 = l0.payload.obj;
        vader_resolver_stamp_expr_spans(((vader_struct_toolchain_ast_AwaitExpr_t*) t0)->f_inner, l1);
    } else if (l0.tag == 452u) {
        l2 = l0.payload.obj;
        l3 = vader_resolver_next_clone_span(l1);
        ((vader_struct_toolchain_ast_CastExpr_t*) l2)->f_span = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_CastExpr_t*) l2);
        t0 = l0.payload.obj;
        vader_resolver_stamp_expr_spans(((vader_struct_toolchain_ast_CastExpr_t*) t0)->f_target, l1);
        t0 = l0.payload.obj;
        vader_resolver_stamp_expr_spans(((vader_struct_toolchain_ast_CastExpr_t*) t0)->f_value, l1);
    } else if (l0.tag == 487u) {
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
        l5 = (size_t) 0;
        while ((l5 < l4)) {
            vader_array_t* _a6_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l5)
            t2 = vader_array_ref_load_box(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l5);
            vader_resolver_stamp_expr_spans(t2, l1);
            t1 = (l5 + INT64_C(1));
            l5 = (size_t) (int64_t) t1;
        }
    } else if (l0.tag == 464u) {
        l2 = l0.payload.obj;
        l3 = vader_resolver_next_clone_span(l1);
        ((vader_struct_toolchain_ast_DotVariantExpr_t*) l2)->f_span = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_DotVariantExpr_t*) l2);
        l2 = l0.payload.obj;
        l3 = vader_resolver_next_clone_span(l1);
        ((vader_struct_toolchain_ast_DotVariantExpr_t*) l2)->f_variant_span = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_DotVariantExpr_t*) l2);
    } else if (l0.tag == 512u) {
        l2 = l0.payload.obj;
        l3 = vader_resolver_next_clone_span(l1);
        ((vader_struct_toolchain_ast_StringLitExpr_t*) l2)->f_span = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_StringLitExpr_t*) l2);
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast_StringLitExpr_t*) t0)->f_parts;
        l4 = ((vader_array_t*) l2)->length;
        l5 = (size_t) 0;
        while ((l5 < l4)) {
            vader_array_t* _a7_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l5)
            l7 = vader_array_ref_load_box(_a7_slotarr->buf, _a7_slotarr->offset + (size_t) l5);
            if (l7.tag == 514u) {
                l3 = l7.payload.obj;
                l6 = vader_resolver_next_clone_span(l1);
                ((vader_struct_toolchain_ast_StringLitText_t*) l3)->f_span = l6;
                VADER_WRITE_BARRIER((vader_struct_toolchain_ast_StringLitText_t*) l3);
            } else {
                if (!(l7.tag == 513u)) {
                    vader_unreachable("non-exhaustive match (T3013 should have caught this)");
                }
                l10 = l7.payload.obj;
                l11 = vader_resolver_next_clone_span(l1);
                ((vader_struct_toolchain_ast_StringLitInterp_t*) l10)->f_span = l11;
                VADER_WRITE_BARRIER((vader_struct_toolchain_ast_StringLitInterp_t*) l10);
                t0 = l7.payload.obj;
                vader_resolver_stamp_expr_spans(((vader_struct_toolchain_ast_StringLitInterp_t*) t0)->f_expr, l1);
            }
            t1 = (l5 + INT64_C(1));
            l5 = (size_t) (int64_t) t1;
        }
    } else if (l0.tag == 489u) {
        l2 = l0.payload.obj;
        l3 = vader_resolver_next_clone_span(l1);
        ((vader_struct_toolchain_ast_LambdaExpr_t*) l2)->f_span = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_LambdaExpr_t*) l2);
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast_LambdaExpr_t*) t0)->f_params;
        l4 = ((vader_array_t*) l2)->length;
        l5 = (size_t) 0;
        while ((l5 < l4)) {
            vader_array_t* _a8_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l5)
            l3 = vader_array_ref_load_obj(_a8_slotarr->buf, _a8_slotarr->offset + (size_t) l5);
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
        }
        t0 = l0.payload.obj;
        if (!(((vader_struct_toolchain_ast_LambdaExpr_t*) t0)->f_return_type.tag == 0u)) {
            t0 = l0.payload.obj;
            vader_resolver_stamp_expr_spans(((vader_struct_toolchain_ast_LambdaExpr_t*) t0)->f_return_type, l1);
        }
        t0 = l0.payload.obj;
        vader_resolver_stamp_block_spans(((vader_struct_toolchain_ast_LambdaExpr_t*) t0)->f_body, l1);
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_resolver_stamp_pattern_spans(vader_box_t l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[4] = { &l1, &l2, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 488u) {
        l2 = l0.payload.obj;
        l3 = vader_resolver_next_clone_span(l1);
        ((vader_struct_toolchain_ast_IsPattern_t*) l2)->f_span = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_IsPattern_t*) l2);
        t0 = l0.payload.obj;
        if (!(((vader_struct_toolchain_ast_IsPattern_t*) t0)->f_inner.tag == 0u)) {
            t0 = l0.payload.obj;
            vader_resolver_stamp_pattern_spans(((vader_struct_toolchain_ast_IsPattern_t*) t0)->f_inner, l1);
        }
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_resolver_stamp_stmt_spans(vader_box_t l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    size_t l4, l5;
    vader_box_t l6 = vader_box_null(), l7 = vader_box_null(), l8 = vader_box_null(), l9 = vader_box_null();
    vader_string_t l10 = 0;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    int64_t t2;
    vader_box_t* gc_roots[6] = { &l0, &l6, &l7, &l8, &l9, &t1 };
    void** gc_raw_roots[4] = { &l1, &l2, &l3, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l10 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 6u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l0.tag == 490u) {
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
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 468u) {
        l2 = l0.payload.obj;
        l3 = vader_resolver_next_clone_span(l1);
        ((vader_struct_toolchain_ast_ExprStmt_t*) l2)->f_span = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_ExprStmt_t*) l2);
        t0 = l0.payload.obj;
        vader_resolver_stamp_expr_spans(((vader_struct_toolchain_ast_ExprStmt_t*) t0)->f_expr, l1);
    } else if (l0.tag == 509u) {
        l2 = l0.payload.obj;
        l3 = vader_resolver_next_clone_span(l1);
        ((vader_struct_toolchain_ast_ReturnStmt_t*) l2)->f_span = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_ReturnStmt_t*) l2);
        t0 = l0.payload.obj;
        if (!(((vader_struct_toolchain_ast_ReturnStmt_t*) t0)->f_value.tag == 0u)) {
            t0 = l0.payload.obj;
            vader_resolver_stamp_expr_spans(((vader_struct_toolchain_ast_ReturnStmt_t*) t0)->f_value, l1);
        }
    } else if (l0.tag == 444u) {
        l2 = l0.payload.obj;
        l3 = vader_resolver_next_clone_span(l1);
        ((vader_struct_toolchain_ast_AssignStmt_t*) l2)->f_span = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_AssignStmt_t*) l2);
        t0 = l0.payload.obj;
        vader_resolver_stamp_expr_spans(((vader_struct_toolchain_ast_AssignStmt_t*) t0)->f_target, l1);
        t0 = l0.payload.obj;
        vader_resolver_stamp_expr_spans(((vader_struct_toolchain_ast_AssignStmt_t*) t0)->f_value, l1);
    } else if (l0.tag == 460u) {
        l2 = l0.payload.obj;
        l3 = vader_resolver_next_clone_span(l1);
        ((vader_struct_toolchain_ast_DestructureAssignStmt_t*) l2)->f_span = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_DestructureAssignStmt_t*) l2);
        t0 = l0.payload.obj;
        l2 = toolchain_ast_assign_places(t0);
        l4 = ((vader_array_t*) l2)->length;
        l5 = (size_t) 0;
        while ((l5 < l4)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
            t1 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
            vader_resolver_stamp_expr_spans(t1, l1);
            t2 = (l5 + INT64_C(1));
            l5 = (size_t) (int64_t) t2;
        }
        t0 = l0.payload.obj;
        vader_resolver_stamp_expr_spans(((vader_struct_toolchain_ast_DestructureAssignStmt_t*) t0)->f_value, l1);
    } else if (l0.tag == 474u) {
        l2 = l0.payload.obj;
        l3 = vader_resolver_next_clone_span(l1);
        ((vader_struct_toolchain_ast_ForStmt_t*) l2)->f_span = l3;
        VADER_WRITE_BARRIER((vader_struct_toolchain_ast_ForStmt_t*) l2);
        t0 = l0.payload.obj;
        l6 = ((vader_struct_toolchain_ast_ForStmt_t*) t0)->f_form;
        l7 = l6;
        if (l6.tag == 527u) {
            t0 = l7.payload.obj;
            vader_resolver_stamp_expr_spans(((vader_struct_toolchain_ast_WhileFor_t*) t0)->f_cond, l1);
        } else if (l6.tag == 483u) {
            t0 = l7.payload.obj;
            l8 = ((vader_struct_toolchain_ast_InFor_t*) t0)->f_loop_var;
            l9 = l8;
            if (l8.tag == 497u) {
                l2 = l7.payload.obj;
                t0 = l9.payload.obj;
                l10 = ((vader_struct_toolchain_ast_NamedVar_t*) t0)->f_name;
                l3 = vader_resolver_next_clone_span(l1);
                vader_struct_toolchain_ast_NamedVar_t* _a1_obj = (vader_struct_toolchain_ast_NamedVar_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_NamedVar_t));
                vader_obj_header_init(_a1_obj, 497u);
                _a1_obj->f_name = l10;
                _a1_obj->f_span = l3;
                l3 = (void*) _a1_obj;
                ((vader_struct_toolchain_ast_InFor_t*) l2)->f_loop_var = vader_ref_box(l3);
                VADER_WRITE_BARRIER((vader_struct_toolchain_ast_InFor_t*) l2);
            } else if (l8.tag == 462u) {
                t0 = l9.payload.obj;
                vader_resolver_stamp_binding_spans(((vader_struct_toolchain_ast_DestructureVar_t*) t0)->f_pattern, l1);
            } else if (!(l8.tag == 463u)) {
                vader_unreachable("non-exhaustive match (T3013 should have caught this)");
            }
            t0 = l7.payload.obj;
            vader_resolver_stamp_expr_spans(((vader_struct_toolchain_ast_InFor_t*) t0)->f_iter, l1);
        } else if (!(l6.tag == 485u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        t0 = l0.payload.obj;
        vader_resolver_stamp_block_spans(((vader_struct_toolchain_ast_ForStmt_t*) t0)->f_body, l1);
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_resolver_subst_opt_expr(vader_box_t l0, void* l1) {
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l0, &t0 };
    void** gc_raw_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (!(l0.tag == 0u)) {
        t0 = vader_resolver_substitute_expr_full(l0, l1);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static void* vader_resolver_substitute_block(void* l0, void* l1) {
    void* l2 = NULL;
    void* l4 = NULL;
    size_t l3, l5;
    vader_box_t l6 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    int64_t t1;
    void* t2 = NULL;
    vader_box_t* gc_roots[2] = { &l6, &t0 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l4, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(181u, 0u, 13u, 1279u);
    l2 = (void*) _a0_arr;
    l3 = ((vader_array_t*) ((vader_struct_toolchain_ast_BlockExpr_t*) l0)->f_stmts)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l2, (size_t) l3);
    l2 = (void*) _a1_arr;
    l4 = ((vader_struct_toolchain_ast_BlockExpr_t*) l0)->f_stmts;
    l3 = ((vader_array_t*) l4)->length;
    l5 = (size_t) 0;
    while ((l5 < l3)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l5)
        t0 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l5);
        l6 = vader_resolver_substitute_stmt(t0, l1);
        vader_array_push((vader_array_t*) l2, l6);
        t1 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t1;
    }
    l6 = vader_box_obj(0u, NULL);
    if (!(((vader_struct_toolchain_ast_BlockExpr_t*) l0)->f_trailing.tag == 0u)) {
        l6 = vader_resolver_substitute_expr_full(((vader_struct_toolchain_ast_BlockExpr_t*) l0)->f_trailing, l1);
    }
    vader_struct_toolchain_ast_BlockExpr_t* _a3_obj = (vader_struct_toolchain_ast_BlockExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_BlockExpr_t));
    vader_obj_header_init(_a3_obj, 447u);
    _a3_obj->f_span = ((vader_struct_toolchain_ast_BlockExpr_t*) l0)->f_span;
    _a3_obj->f_id = (size_t) 0;
    _a3_obj->f_stmts = l2;
    _a3_obj->f_trailing = l6;
    t2 = (void*) _a3_obj;
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
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
}

static vader_box_t vader_resolver_substitute_coalesce_fallback(vader_box_t l0, void* l1) {
    vader_box_t l2 = vader_box_null();
    void* l3 = NULL;
    void* t0 = NULL;
    vader_box_t* gc_roots[2] = { &l0, &l2 };
    void** gc_raw_roots[3] = { &l1, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 509u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_toolchain_ast_ReturnStmt_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l2 = vader_resolver_subst_opt_expr(((vader_struct_toolchain_ast_ReturnStmt_t*) t0)->f_value, l1);
        vader_struct_toolchain_ast_ReturnStmt_t* _a0_obj = (vader_struct_toolchain_ast_ReturnStmt_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_ReturnStmt_t));
        vader_obj_header_init(_a0_obj, 509u);
        _a0_obj->f_span = l3;
        _a0_obj->f_id = (size_t) 0;
        _a0_obj->f_value = l2;
        t0 = (void*) _a0_obj;
        l2 = vader_ref_box(t0);
        { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if ((l0.tag == 449u || l0.tag == 455u)) {
        l2 = l0;
    } else {
        if (!((l0.tag == 441u || l0.tag == 445u || l0.tag == 446u || l0.tag == 447u || l0.tag == 448u || l0.tag == 451u || l0.tag == 452u || l0.tag == 453u || l0.tag == 464u || l0.tag == 469u || l0.tag == 470u || l0.tag == 473u || l0.tag == 475u || l0.tag == 476u || l0.tag == 479u || l0.tag == 484u || l0.tag == 486u || l0.tag == 487u || l0.tag == 489u || l0.tag == 493u || l0.tag == 495u || l0.tag == 498u || l0.tag == 499u || l0.tag == 505u || l0.tag == 510u || l0.tag == 512u || l0.tag == 517u || l0.tag == 526u))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l2 = vader_resolver_substitute_expr_full(l0, l1);
    }
    { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
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
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 5u, 10u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if ((l0.tag == 448u || l0.tag == 453u || l0.tag == 470u || l0.tag == 486u || l0.tag == 499u)) {
        { vader_box_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 498u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast_NullCoalesceExpr_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l3 = vader_resolver_substitute_expr_full(((vader_struct_toolchain_ast_NullCoalesceExpr_t*) t0)->f_left, l1);
        t0 = l0.payload.obj;
        l4 = vader_resolver_substitute_coalesce_fallback(((vader_struct_toolchain_ast_NullCoalesceExpr_t*) t0)->f_fallback, l1);
        vader_struct_toolchain_ast_NullCoalesceExpr_t* _a0_obj = (vader_struct_toolchain_ast_NullCoalesceExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_NullCoalesceExpr_t));
        vader_obj_header_init(_a0_obj, 498u);
        _a0_obj->f_span = l2;
        _a0_obj->f_id = (size_t) 0;
        _a0_obj->f_left = l3;
        _a0_obj->f_fallback = l4;
        t0 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 476u) {
        t0 = l0.payload.obj;
        t1 = vader_resolver_substitute_type_expr(vader_ref_box(t0), l1);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 475u) {
        t0 = l0.payload.obj;
        t1 = vader_resolver_substitute_type_expr(vader_ref_box(t0), l1);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 473u) {
        t0 = l0.payload.obj;
        t1 = vader_resolver_substitute_type_expr(vader_ref_box(t0), l1);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 441u) {
        t0 = l0.payload.obj;
        t1 = vader_resolver_substitute_type_expr(vader_ref_box(t0), l1);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 495u) {
        t0 = l0.payload.obj;
        t1 = vader_resolver_substitute_type_expr(vader_ref_box(t0), l1);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 451u) {
        vader_array_t* _a1_arr = vader_array_new(25u, 0u, 13u, 450u);
        l2 = (void*) _a1_arr;
        t0 = l0.payload.obj;
        l5 = ((vader_struct_toolchain_ast_CallExpr_t*) t0)->f_args;
        l6 = ((vader_array_t*) l5)->length;
        l7 = (size_t) 0;
        while ((l7 < l6)) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l7)
            l8 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l7);
            l9 = ((vader_struct_toolchain_ast_CallArg_t*) l8)->f_span;
            l3 = ((vader_struct_toolchain_ast_CallArg_t*) l8)->f_name;
            l4 = vader_resolver_substitute_expr_full(((vader_struct_toolchain_ast_CallArg_t*) l8)->f_value, l1);
            l10 = ((vader_struct_toolchain_ast_CallArg_t*) l8)->f_spread;
            vader_struct_toolchain_ast_CallArg_t* _a3_obj = (vader_struct_toolchain_ast_CallArg_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_CallArg_t));
            vader_obj_header_init(_a3_obj, 450u);
            _a3_obj->f_span = l9;
            _a3_obj->f_id = (size_t) 0;
            _a3_obj->f_name = l3;
            _a3_obj->f_value = l4;
            _a3_obj->f_spread = l10;
            l11 = (void*) _a3_obj;
            vader_array_push((vader_array_t*) l2, vader_ref_box(l11));
            t2 = (l7 + INT64_C(1));
            l7 = (size_t) (int64_t) t2;
        }
        t0 = l0.payload.obj;
        l5 = ((vader_struct_toolchain_ast_CallExpr_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l3 = vader_resolver_substitute_expr_full(((vader_struct_toolchain_ast_CallExpr_t*) t0)->f_callee, l1);
        vader_struct_toolchain_ast_CallExpr_t* _a4_obj = (vader_struct_toolchain_ast_CallExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_CallExpr_t));
        vader_obj_header_init(_a4_obj, 451u);
        _a4_obj->f_span = l5;
        _a4_obj->f_id = (size_t) 0;
        _a4_obj->f_callee = l3;
        _a4_obj->f_args = l2;
        _a4_obj->f_trailing_comma = false;
        t0 = (void*) _a4_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 469u) {
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
        vader_obj_header_init(_a5_obj, 469u);
        _a5_obj->f_span = l2;
        _a5_obj->f_id = (size_t) 0;
        _a5_obj->f_target = l3;
        _a5_obj->f_field = l12;
        _a5_obj->f_field_span = l5;
        _a5_obj->f_is_numeric = l10;
        t0 = (void*) _a5_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 484u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast_IndexExpr_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l3 = vader_resolver_substitute_expr_full(((vader_struct_toolchain_ast_IndexExpr_t*) t0)->f_target, l1);
        t0 = l0.payload.obj;
        l4 = vader_resolver_substitute_expr_full(((vader_struct_toolchain_ast_IndexExpr_t*) t0)->f_index, l1);
        vader_struct_toolchain_ast_IndexExpr_t* _a6_obj = (vader_struct_toolchain_ast_IndexExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_IndexExpr_t));
        vader_obj_header_init(_a6_obj, 484u);
        _a6_obj->f_span = l2;
        _a6_obj->f_id = (size_t) 0;
        _a6_obj->f_target = l3;
        _a6_obj->f_index = l4;
        t0 = (void*) _a6_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 526u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast_UnaryExpr_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l13 = ((vader_struct_toolchain_ast_UnaryExpr_t*) t0)->f_op;
        t0 = l0.payload.obj;
        l3 = vader_resolver_substitute_expr_full(((vader_struct_toolchain_ast_UnaryExpr_t*) t0)->f_operand, l1);
        vader_struct_toolchain_ast_UnaryExpr_t* _a7_obj = (vader_struct_toolchain_ast_UnaryExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_UnaryExpr_t));
        vader_obj_header_init(_a7_obj, 526u);
        _a7_obj->f_span = l2;
        _a7_obj->f_id = (size_t) 0;
        _a7_obj->f_op = l13;
        _a7_obj->f_operand = l3;
        t0 = (void*) _a7_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 446u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast_BinaryExpr_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l13 = ((vader_struct_toolchain_ast_BinaryExpr_t*) t0)->f_op;
        t0 = l0.payload.obj;
        l3 = vader_resolver_substitute_expr_full(((vader_struct_toolchain_ast_BinaryExpr_t*) t0)->f_left, l1);
        t0 = l0.payload.obj;
        l4 = vader_resolver_substitute_expr_full(((vader_struct_toolchain_ast_BinaryExpr_t*) t0)->f_right, l1);
        t0 = l0.payload.obj;
        l14 = ((vader_struct_toolchain_ast_BinaryExpr_t*) t0)->f_bind_as;
        vader_struct_toolchain_ast_BinaryExpr_t* _a8_obj = (vader_struct_toolchain_ast_BinaryExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_BinaryExpr_t));
        vader_obj_header_init(_a8_obj, 446u);
        _a8_obj->f_span = l2;
        _a8_obj->f_id = (size_t) 0;
        _a8_obj->f_op = l13;
        _a8_obj->f_left = l3;
        _a8_obj->f_right = l4;
        _a8_obj->f_bind_as = l14;
        t0 = (void*) _a8_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 479u) {
        l3 = vader_box_obj(0u, NULL);
        t0 = l0.payload.obj;
        l4 = ((vader_struct_toolchain_ast_IfExpr_t*) t0)->f_else_branch;
        l14 = l4;
        if (!(l4.tag == 0u)) {
            if (l4.tag == 477u) {
                t0 = l14.payload.obj;
                t3 = vader_resolver_substitute_block(((vader_struct_toolchain_ast_IfElseBlock_t*) t0)->f_block, l1);
                vader_struct_toolchain_ast_IfElseBlock_t* _a9_obj = (vader_struct_toolchain_ast_IfElseBlock_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_IfElseBlock_t));
                vader_obj_header_init(_a9_obj, 477u);
                _a9_obj->f_block = t3;
                t0 = (void*) _a9_obj;
                l3 = vader_ref_box(t0);
            } else {
                if (!(l4.tag == 478u)) {
                    vader_unreachable("non-exhaustive match (T3013 should have caught this)");
                }
                t0 = l14.payload.obj;
                l4 = vader_resolver_substitute_expr_full(vader_ref_box(((vader_struct_toolchain_ast_IfElseIf_t*) t0)->f_branch), l1);
                if (l4.tag == 479u) {
                    t0 = l4.payload.obj;
                    vader_struct_toolchain_ast_IfElseIf_t* _a10_obj = (vader_struct_toolchain_ast_IfElseIf_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_IfElseIf_t));
                    vader_obj_header_init(_a10_obj, 478u);
                    _a10_obj->f_branch = t0;
                    t0 = (void*) _a10_obj;
                    l3 = vader_ref_box(t0);
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
        vader_obj_header_init(_a11_obj, 479u);
        _a11_obj->f_span = l2;
        _a11_obj->f_id = (size_t) 0;
        _a11_obj->f_cond = l4;
        _a11_obj->f_then_block = l5;
        _a11_obj->f_else_branch = l3;
        t0 = (void*) _a11_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 493u) {
        vader_array_t* _a12_arr = vader_array_new(34u, 0u, 13u, 492u);
        l2 = (void*) _a12_arr;
        t0 = l0.payload.obj;
        l5 = ((vader_struct_toolchain_ast_MatchExpr_t*) t0)->f_arms;
        l6 = ((vader_array_t*) l5)->length;
        l7 = (size_t) 0;
        while ((l7 < l6)) {
            vader_array_t* _a13_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a13_slotarr, l7)
            l8 = vader_array_ref_load_obj(_a13_slotarr->buf, _a13_slotarr->offset + (size_t) l7);
            l3 = vader_box_obj(0u, NULL);
            if (!(((vader_struct_toolchain_ast_MatchArm_t*) l8)->f_guard.tag == 0u)) {
                l3 = vader_resolver_substitute_expr_full(((vader_struct_toolchain_ast_MatchArm_t*) l8)->f_guard, l1);
            }
            l9 = ((vader_struct_toolchain_ast_MatchArm_t*) l8)->f_span;
            l4 = vader_resolver_substitute_pattern(((vader_struct_toolchain_ast_MatchArm_t*) l8)->f_pattern, l1);
            l14 = vader_resolver_substitute_expr_full(((vader_struct_toolchain_ast_MatchArm_t*) l8)->f_body, l1);
            vader_struct_toolchain_ast_MatchArm_t* _a14_obj = (vader_struct_toolchain_ast_MatchArm_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_MatchArm_t));
            vader_obj_header_init(_a14_obj, 492u);
            _a14_obj->f_span = l9;
            _a14_obj->f_id = (size_t) 0;
            _a14_obj->f_pattern = l4;
            _a14_obj->f_guard = l3;
            _a14_obj->f_body = l14;
            l11 = (void*) _a14_obj;
            vader_array_push((vader_array_t*) l2, vader_ref_box(l11));
            t2 = (l7 + INT64_C(1));
            l7 = (size_t) (int64_t) t2;
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
        l4 = ((vader_struct_toolchain_ast_MatchExpr_t*) t0)->f_bind_as;
        vader_struct_toolchain_ast_MatchExpr_t* _a15_obj = (vader_struct_toolchain_ast_MatchExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_MatchExpr_t));
        vader_obj_header_init(_a15_obj, 493u);
        _a15_obj->f_span = l5;
        _a15_obj->f_id = (size_t) 0;
        _a15_obj->f_scrutinee = l3;
        _a15_obj->f_arms = l2;
        _a15_obj->f_partial = l10;
        _a15_obj->f_unreachable = l15;
        _a15_obj->f_bind_as = l4;
        t0 = (void*) _a15_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 447u) {
        t0 = l0.payload.obj;
        t3 = vader_resolver_substitute_block(t0, l1);
        { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 517u) {
        vader_array_t* _a16_arr = vader_array_new(187u, 0u, 13u, 1319u);
        l2 = (void*) _a16_arr;
        t0 = l0.payload.obj;
        l5 = ((vader_struct_toolchain_ast_StructLitExpr_t*) t0)->f_items;
        l6 = ((vader_array_t*) l5)->length;
        l7 = (size_t) 0;
        while ((l7 < l6)) {
            vader_array_t* _a17_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a17_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a17_slotarr, l7)
            l3 = vader_array_ref_load_box(_a17_slotarr->buf, _a17_slotarr->offset + (size_t) l7);
            if (l3.tag == 518u) {
                t0 = l3.payload.obj;
                l8 = ((vader_struct_toolchain_ast_StructLitField_t*) t0)->f_span;
                t0 = l3.payload.obj;
                l12 = ((vader_struct_toolchain_ast_StructLitField_t*) t0)->f_name;
                t0 = l3.payload.obj;
                l9 = ((vader_struct_toolchain_ast_StructLitField_t*) t0)->f_name_span;
                t0 = l3.payload.obj;
                l4 = vader_resolver_substitute_expr_full(((vader_struct_toolchain_ast_StructLitField_t*) t0)->f_value, l1);
                vader_struct_toolchain_ast_StructLitField_t* _a18_obj = (vader_struct_toolchain_ast_StructLitField_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_StructLitField_t));
                vader_obj_header_init(_a18_obj, 518u);
                _a18_obj->f_span = l8;
                _a18_obj->f_id = (size_t) 0;
                _a18_obj->f_name = l12;
                _a18_obj->f_name_span = l9;
                _a18_obj->f_value = l4;
                l11 = (void*) _a18_obj;
                vader_array_push((vader_array_t*) l2, vader_ref_box(l11));
            } else {
                if (!(l3.tag == 519u)) {
                    vader_unreachable("non-exhaustive match (T3013 should have caught this)");
                }
                t0 = l3.payload.obj;
                l16 = ((vader_struct_toolchain_ast_StructLitSpread_t*) t0)->f_span;
                t0 = l3.payload.obj;
                l14 = vader_resolver_substitute_expr_full(((vader_struct_toolchain_ast_StructLitSpread_t*) t0)->f_expr, l1);
                vader_struct_toolchain_ast_StructLitSpread_t* _a19_obj = (vader_struct_toolchain_ast_StructLitSpread_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_StructLitSpread_t));
                vader_obj_header_init(_a19_obj, 519u);
                _a19_obj->f_span = l16;
                _a19_obj->f_id = (size_t) 0;
                _a19_obj->f_expr = l14;
                l17 = (void*) _a19_obj;
                vader_array_push((vader_array_t*) l2, vader_ref_box(l17));
            }
            t2 = (l7 + INT64_C(1));
            l7 = (size_t) (int64_t) t2;
        }
        t0 = l0.payload.obj;
        l5 = ((vader_struct_toolchain_ast_StructLitExpr_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l3 = vader_resolver_substitute_type_expr(((vader_struct_toolchain_ast_StructLitExpr_t*) t0)->f_type_name, l1);
        vader_struct_toolchain_ast_StructLitExpr_t* _a20_obj = (vader_struct_toolchain_ast_StructLitExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_StructLitExpr_t));
        vader_obj_header_init(_a20_obj, 517u);
        _a20_obj->f_span = l5;
        _a20_obj->f_id = (size_t) 0;
        _a20_obj->f_type_name = l3;
        _a20_obj->f_items = l2;
        _a20_obj->f_trailing_comma = false;
        t0 = (void*) _a20_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 510u) {
        vader_array_t* _a21_arr = vader_array_new(179u, 0u, 13u, 1259u);
        l2 = (void*) _a21_arr;
        t0 = l0.payload.obj;
        l5 = ((vader_struct_toolchain_ast_SeqLitExpr_t*) t0)->f_elements;
        l6 = ((vader_array_t*) l5)->length;
        l7 = (size_t) 0;
        while ((l7 < l6)) {
            vader_array_t* _a22_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a22_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a22_slotarr, l7)
            t1 = vader_array_ref_load_box(_a22_slotarr->buf, _a22_slotarr->offset + (size_t) l7);
            l3 = vader_resolver_substitute_expr_full(t1, l1);
            vader_array_push((vader_array_t*) l2, l3);
            t2 = (l7 + INT64_C(1));
            l7 = (size_t) (int64_t) t2;
        }
        t0 = l0.payload.obj;
        vader_struct_toolchain_ast_SeqLitExpr_t* _a23_obj = (vader_struct_toolchain_ast_SeqLitExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_SeqLitExpr_t));
        vader_obj_header_init(_a23_obj, 510u);
        _a23_obj->f_span = ((vader_struct_toolchain_ast_SeqLitExpr_t*) t0)->f_span;
        _a23_obj->f_id = (size_t) 0;
        _a23_obj->f_elements = l2;
        _a23_obj->f_trailing_comma = false;
        t0 = (void*) _a23_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 505u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast_RangeExpr_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l10 = ((vader_struct_toolchain_ast_RangeExpr_t*) t0)->f_inclusive;
        t0 = l0.payload.obj;
        l3 = vader_resolver_substitute_expr_full(((vader_struct_toolchain_ast_RangeExpr_t*) t0)->f_lower, l1);
        t0 = l0.payload.obj;
        l4 = vader_resolver_substitute_expr_full(((vader_struct_toolchain_ast_RangeExpr_t*) t0)->f_upper, l1);
        vader_struct_toolchain_ast_RangeExpr_t* _a24_obj = (vader_struct_toolchain_ast_RangeExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_RangeExpr_t));
        vader_obj_header_init(_a24_obj, 505u);
        _a24_obj->f_span = l2;
        _a24_obj->f_id = (size_t) 0;
        _a24_obj->f_inclusive = l10;
        _a24_obj->f_lower = l3;
        _a24_obj->f_upper = l4;
        t0 = (void*) _a24_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 445u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast_AwaitExpr_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l3 = vader_resolver_substitute_expr_full(((vader_struct_toolchain_ast_AwaitExpr_t*) t0)->f_inner, l1);
        vader_struct_toolchain_ast_AwaitExpr_t* _a25_obj = (vader_struct_toolchain_ast_AwaitExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_AwaitExpr_t));
        vader_obj_header_init(_a25_obj, 445u);
        _a25_obj->f_span = l2;
        _a25_obj->f_id = (size_t) 0;
        _a25_obj->f_inner = l3;
        t0 = (void*) _a25_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 452u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast_CastExpr_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l3 = vader_resolver_substitute_type_expr(((vader_struct_toolchain_ast_CastExpr_t*) t0)->f_target, l1);
        t0 = l0.payload.obj;
        l4 = vader_resolver_substitute_expr_full(((vader_struct_toolchain_ast_CastExpr_t*) t0)->f_value, l1);
        vader_struct_toolchain_ast_CastExpr_t* _a26_obj = (vader_struct_toolchain_ast_CastExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_CastExpr_t));
        vader_obj_header_init(_a26_obj, 452u);
        _a26_obj->f_span = l2;
        _a26_obj->f_id = (size_t) 0;
        _a26_obj->f_target = l3;
        _a26_obj->f_value = l4;
        t0 = (void*) _a26_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 487u) {
        vader_array_t* _a27_arr = vader_array_new(179u, 0u, 13u, 1259u);
        l2 = (void*) _a27_arr;
        t0 = l0.payload.obj;
        l5 = ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) t0)->f_args;
        l6 = ((vader_array_t*) l5)->length;
        l7 = (size_t) 0;
        while ((l7 < l6)) {
            vader_array_t* _a28_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a28_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a28_slotarr, l7)
            t1 = vader_array_ref_load_box(_a28_slotarr->buf, _a28_slotarr->offset + (size_t) l7);
            l3 = vader_resolver_substitute_expr_full(t1, l1);
            vader_array_push((vader_array_t*) l2, l3);
            t2 = (l7 + INT64_C(1));
            l7 = (size_t) (int64_t) t2;
        }
        t0 = l0.payload.obj;
        l5 = ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l12 = ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) t0)->f_name;
        t0 = l0.payload.obj;
        l8 = ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) t0)->f_name_span;
        vader_struct_toolchain_ast_IntrinsicCallExpr_t* _a29_obj = (vader_struct_toolchain_ast_IntrinsicCallExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_IntrinsicCallExpr_t));
        vader_obj_header_init(_a29_obj, 487u);
        _a29_obj->f_span = l5;
        _a29_obj->f_id = (size_t) 0;
        _a29_obj->f_name = l12;
        _a29_obj->f_name_span = l8;
        _a29_obj->f_args = l2;
        _a29_obj->f_trailing_comma = false;
        t0 = (void*) _a29_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 464u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast_DotVariantExpr_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l12 = ((vader_struct_toolchain_ast_DotVariantExpr_t*) t0)->f_variant;
        t0 = l0.payload.obj;
        l5 = ((vader_struct_toolchain_ast_DotVariantExpr_t*) t0)->f_variant_span;
        vader_struct_toolchain_ast_DotVariantExpr_t* _a30_obj = (vader_struct_toolchain_ast_DotVariantExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_DotVariantExpr_t));
        vader_obj_header_init(_a30_obj, 464u);
        _a30_obj->f_span = l2;
        _a30_obj->f_id = (size_t) 0;
        _a30_obj->f_variant = l12;
        _a30_obj->f_variant_span = l5;
        t0 = (void*) _a30_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 512u) {
        vader_array_t* _a31_arr = vader_array_new(186u, 0u, 13u, 1318u);
        l2 = (void*) _a31_arr;
        t0 = l0.payload.obj;
        l5 = ((vader_struct_toolchain_ast_StringLitExpr_t*) t0)->f_parts;
        l6 = ((vader_array_t*) l5)->length;
        l7 = (size_t) 0;
        while ((l7 < l6)) {
            vader_array_t* _a32_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a32_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a32_slotarr, l7)
            l3 = vader_array_ref_load_box(_a32_slotarr->buf, _a32_slotarr->offset + (size_t) l7);
            if (l3.tag == 514u) {
                t0 = l3.payload.obj;
                l12 = ((vader_struct_toolchain_ast_StringLitText_t*) t0)->f_value;
                t0 = l3.payload.obj;
                l8 = ((vader_struct_toolchain_ast_StringLitText_t*) t0)->f_span;
                vader_struct_toolchain_ast_StringLitText_t* _a33_obj = (vader_struct_toolchain_ast_StringLitText_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_StringLitText_t));
                vader_obj_header_init(_a33_obj, 514u);
                _a33_obj->f_value = l12;
                _a33_obj->f_span = l8;
                _a33_obj->f_id = (size_t) 0;
                l9 = (void*) _a33_obj;
                vader_array_push((vader_array_t*) l2, vader_ref_box(l9));
            } else {
                if (!(l3.tag == 513u)) {
                    vader_unreachable("non-exhaustive match (T3013 should have caught this)");
                }
                t0 = l3.payload.obj;
                l4 = vader_resolver_substitute_expr_full(((vader_struct_toolchain_ast_StringLitInterp_t*) t0)->f_expr, l1);
                t0 = l3.payload.obj;
                l11 = ((vader_struct_toolchain_ast_StringLitInterp_t*) t0)->f_span;
                vader_struct_toolchain_ast_StringLitInterp_t* _a34_obj = (vader_struct_toolchain_ast_StringLitInterp_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_StringLitInterp_t));
                vader_obj_header_init(_a34_obj, 513u);
                _a34_obj->f_expr = l4;
                _a34_obj->f_span = l11;
                _a34_obj->f_id = (size_t) 0;
                l16 = (void*) _a34_obj;
                vader_array_push((vader_array_t*) l2, vader_ref_box(l16));
            }
            t2 = (l7 + INT64_C(1));
            l7 = (size_t) (int64_t) t2;
        }
        t0 = l0.payload.obj;
        vader_struct_toolchain_ast_StringLitExpr_t* _a35_obj = (vader_struct_toolchain_ast_StringLitExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_StringLitExpr_t));
        vader_obj_header_init(_a35_obj, 512u);
        _a35_obj->f_span = ((vader_struct_toolchain_ast_StringLitExpr_t*) t0)->f_span;
        _a35_obj->f_id = (size_t) 0;
        _a35_obj->f_parts = l2;
        t0 = (void*) _a35_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l0.tag == 489u)) {
        vader_unreachable("non-exhaustive match (T3013 should have caught this)");
    }
    vader_array_t* _a36_arr = vader_array_new(30u, 0u, 13u, 472u);
    l2 = (void*) _a36_arr;
    t0 = l0.payload.obj;
    l5 = ((vader_struct_toolchain_ast_LambdaExpr_t*) t0)->f_params;
    l6 = ((vader_array_t*) l5)->length;
    l7 = (size_t) 0;
    while ((l7 < l6)) {
        vader_array_t* _a37_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a37_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a37_slotarr, l7)
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
        vader_obj_header_init(_a38_obj, 472u);
        _a38_obj->f_span = l9;
        _a38_obj->f_id = (size_t) 0;
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
    vader_obj_header_init(_a39_obj, 489u);
    _a39_obj->f_span = l5;
    _a39_obj->f_id = (size_t) 0;
    _a39_obj->f_params = l2;
    _a39_obj->f_return_type = l3;
    _a39_obj->f_body = l8;
    _a39_obj->f_trailing_comma = false;
    t0 = (void*) _a39_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_resolver_substitute_opt_type(vader_box_t l0, void* l1) {
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l0, &t0 };
    void** gc_raw_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (!(l0.tag == 0u)) {
        t0 = vader_resolver_substitute_type_expr(l0, l1);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static void* vader_resolver_substitute_params(void* l0, void* l1) {
    void* l2 = NULL;
    void* l4 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l14 = NULL;
    void* l15 = NULL;
    size_t l3, l5;
    vader_box_t l8 = vader_box_null(), l10 = vader_box_null(), l11 = vader_box_null();
    vader_string_t l9 = 0;
    bool l12, l13;
    void* t0 = NULL;
    int64_t t1;
    vader_box_t* gc_roots[3] = { &l8, &l10, &l11 };
    void** gc_raw_roots[9] = { &l0, &l1, &l2, &l4, &l6, &l7, &l14, &l15, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l9 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 9u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(30u, 0u, 13u, 472u);
    l2 = (void*) _a0_arr;
    l3 = ((vader_array_t*) l0)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l2, (size_t) l3);
    l2 = (void*) _a1_arr;
    l4 = l0;
    l3 = ((vader_array_t*) l4)->length;
    l5 = (size_t) 0;
    while ((l5 < l3)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l5)
        l6 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l5);
        l7 = l6;
        t0 = ((vader_struct_toolchain_ast_FnParam_t*) l7)->f_span;
        l8 = vader_ref_box(t0);
        l9 = ((vader_struct_toolchain_ast_FnParam_t*) l7)->f_name;
        l10 = vader_resolver_substitute_opt_type(((vader_struct_toolchain_ast_FnParam_t*) l6)->f_ty, l1);
        l11 = ((vader_struct_toolchain_ast_FnParam_t*) l7)->f_default_value;
        l12 = ((vader_struct_toolchain_ast_FnParam_t*) l7)->f_variadic;
        l13 = ((vader_struct_toolchain_ast_FnParam_t*) l7)->f_mutable;
        l14 = ((vader_struct_toolchain_ast_FnParam_t*) l7)->f_decorators;
        vader_struct_toolchain_ast_FnParam_t* _a3_obj = (vader_struct_toolchain_ast_FnParam_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_FnParam_t));
        vader_obj_header_init(_a3_obj, 472u);
        _a3_obj->f_span = l8.payload.obj;
        _a3_obj->f_id = (size_t) 0;
        _a3_obj->f_name = l9;
        _a3_obj->f_ty = l10;
        _a3_obj->f_default_value = l11;
        _a3_obj->f_variadic = l12;
        _a3_obj->f_mutable = l13;
        _a3_obj->f_decorators = l14;
        l15 = (void*) _a3_obj;
        vader_array_push((vader_array_t*) l2, vader_ref_box(l15));
        t1 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t1;
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_resolver_substitute_params_disambiguated(void* l0, void* l1, void* l2, void* l3) {
    void* l4 = NULL;
    void* l6 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    void* l16 = NULL;
    void* l17 = NULL;
    size_t l5, l7;
    vader_string_t l11 = 0;
    vader_box_t l12 = vader_box_null(), l13 = vader_box_null();
    bool l14, l15;
    vader_string_t t0 = 0;
    int64_t t1;
    vader_box_t* gc_roots[2] = { &l12, &l13 };
    void** gc_raw_roots[11] = { &l0, &l1, &l2, &l3, &l4, &l6, &l8, &l9, &l10, &l16, &l17 };
    vader_string_t* gc_atom_roots[2] = { &l11, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 11u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(30u, 0u, 13u, 472u);
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
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l7)
        l8 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l7);
        t0 = ((vader_struct_toolchain_ast_FnParam_t*) l8)->f_name;
        if (t0 == 2188u) {
            l9 = l2;
        } else {
            l9 = vader_resolver_synth_clone_span(l3);
        }
        l10 = l8;
        l11 = ((vader_struct_toolchain_ast_FnParam_t*) l10)->f_name;
        l12 = vader_resolver_substitute_opt_type(((vader_struct_toolchain_ast_FnParam_t*) l8)->f_ty, l1);
        l13 = ((vader_struct_toolchain_ast_FnParam_t*) l10)->f_default_value;
        l14 = ((vader_struct_toolchain_ast_FnParam_t*) l10)->f_variadic;
        l15 = ((vader_struct_toolchain_ast_FnParam_t*) l10)->f_mutable;
        l16 = ((vader_struct_toolchain_ast_FnParam_t*) l10)->f_decorators;
        vader_struct_toolchain_ast_FnParam_t* _a3_obj = (vader_struct_toolchain_ast_FnParam_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_FnParam_t));
        vader_obj_header_init(_a3_obj, 472u);
        _a3_obj->f_span = l9;
        _a3_obj->f_id = (size_t) 0;
        _a3_obj->f_name = l11;
        _a3_obj->f_ty = l12;
        _a3_obj->f_default_value = l13;
        _a3_obj->f_variadic = l14;
        _a3_obj->f_mutable = l15;
        _a3_obj->f_decorators = l16;
        l17 = (void*) _a3_obj;
        vader_array_push((vader_array_t*) l4, vader_ref_box(l17));
        t1 = (l7 + INT64_C(1));
        l7 = (size_t) (int64_t) t1;
    }
    { void* __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_resolver_substitute_params_stamped(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    void* l5 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l15 = NULL;
    void* l16 = NULL;
    size_t l4, l6;
    vader_string_t l10 = 0;
    vader_box_t l11 = vader_box_null(), l12 = vader_box_null();
    bool l13, l14;
    int64_t t0;
    vader_box_t* gc_roots[2] = { &l11, &l12 };
    void** gc_raw_roots[10] = { &l0, &l1, &l2, &l3, &l5, &l7, &l8, &l9, &l15, &l16 };
    vader_string_t* gc_atom_roots[1] = { &l10 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 10u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(30u, 0u, 13u, 472u);
    l3 = (void*) _a0_arr;
    l4 = ((vader_array_t*) l0)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l3, (size_t) l4);
    l3 = (void*) _a1_arr;
    l5 = l0;
    l4 = ((vader_array_t*) l5)->length;
    l6 = (size_t) 0;
    while ((l6 < l4)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l6)
        l7 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l6);
        l8 = l7;
        l9 = vader_resolver_next_clone_span(l2);
        l10 = ((vader_struct_toolchain_ast_FnParam_t*) l8)->f_name;
        l11 = vader_resolver_substitute_opt_type(((vader_struct_toolchain_ast_FnParam_t*) l7)->f_ty, l1);
        l12 = ((vader_struct_toolchain_ast_FnParam_t*) l8)->f_default_value;
        l13 = ((vader_struct_toolchain_ast_FnParam_t*) l8)->f_variadic;
        l14 = ((vader_struct_toolchain_ast_FnParam_t*) l8)->f_mutable;
        l15 = ((vader_struct_toolchain_ast_FnParam_t*) l8)->f_decorators;
        vader_struct_toolchain_ast_FnParam_t* _a3_obj = (vader_struct_toolchain_ast_FnParam_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_FnParam_t));
        vader_obj_header_init(_a3_obj, 472u);
        _a3_obj->f_span = l9;
        _a3_obj->f_id = (size_t) 0;
        _a3_obj->f_name = l10;
        _a3_obj->f_ty = l11;
        _a3_obj->f_default_value = l12;
        _a3_obj->f_variadic = l13;
        _a3_obj->f_mutable = l14;
        _a3_obj->f_decorators = l15;
        l16 = (void*) _a3_obj;
        vader_array_push((vader_array_t*) l3, vader_ref_box(l16));
        t0 = (l6 + INT64_C(1));
        l6 = (size_t) (int64_t) t0;
    }
    { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_resolver_substitute_pattern(vader_box_t l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l4 = vader_box_null();
    void* l3 = NULL;
    void* t0 = NULL;
    vader_box_t* gc_roots[3] = { &l0, &l2, &l4 };
    void** gc_raw_roots[3] = { &l1, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (!(l0.tag == 488u)) {
        { vader_box_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
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
    vader_struct_toolchain_ast_IsPattern_t* _a0_obj = (vader_struct_toolchain_ast_IsPattern_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_IsPattern_t));
    vader_obj_header_init(_a0_obj, 488u);
    _a0_obj->f_span = l3;
    _a0_obj->f_id = (size_t) 0;
    _a0_obj->f_ty = l4;
    _a0_obj->f_inner = l2;
    t0 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_resolver_substitute_stmt(vader_box_t l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l5 = vader_box_null(), l6 = vader_box_null(), l13 = vader_box_null();
    void* l3 = NULL;
    void* l7 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    void* l12 = NULL;
    bool l4;
    size_t l8, l9;
    void* t0 = NULL;
    int64_t t1;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[6] = { &l0, &l2, &l5, &l6, &l13, &t2 };
    void** gc_raw_roots[7] = { &l1, &l3, &l7, &l10, &l11, &l12, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 6u, 7u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 490u) {
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
        vader_obj_header_init(_a0_obj, 490u);
        _a0_obj->f_span = l3;
        _a0_obj->f_id = (size_t) 0;
        _a0_obj->f_mutable = l4;
        _a0_obj->f_binding = l5;
        _a0_obj->f_ty = l2;
        _a0_obj->f_value = l6;
        t0 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 468u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_toolchain_ast_ExprStmt_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l2 = vader_resolver_substitute_expr_full(((vader_struct_toolchain_ast_ExprStmt_t*) t0)->f_expr, l1);
        vader_struct_toolchain_ast_ExprStmt_t* _a1_obj = (vader_struct_toolchain_ast_ExprStmt_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_ExprStmt_t));
        vader_obj_header_init(_a1_obj, 468u);
        _a1_obj->f_span = l3;
        _a1_obj->f_id = (size_t) 0;
        _a1_obj->f_expr = l2;
        t0 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 509u) {
        l2 = vader_box_obj(0u, NULL);
        t0 = l0.payload.obj;
        if (!(((vader_struct_toolchain_ast_ReturnStmt_t*) t0)->f_value.tag == 0u)) {
            t0 = l0.payload.obj;
            l2 = vader_resolver_substitute_expr_full(((vader_struct_toolchain_ast_ReturnStmt_t*) t0)->f_value, l1);
        }
        t0 = l0.payload.obj;
        vader_struct_toolchain_ast_ReturnStmt_t* _a2_obj = (vader_struct_toolchain_ast_ReturnStmt_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_ReturnStmt_t));
        vader_obj_header_init(_a2_obj, 509u);
        _a2_obj->f_span = ((vader_struct_toolchain_ast_ReturnStmt_t*) t0)->f_span;
        _a2_obj->f_id = (size_t) 0;
        _a2_obj->f_value = l2;
        t0 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 444u) {
        t0 = l0.payload.obj;
        l2 = vader_resolver_substitute_expr_full(((vader_struct_toolchain_ast_AssignStmt_t*) t0)->f_target, l1);
        t0 = l0.payload.obj;
        l3 = ((vader_struct_toolchain_ast_AssignStmt_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l5 = vader_resolver_clone_assign_value(t0, l2, l1);
        vader_struct_toolchain_ast_AssignStmt_t* _a3_obj = (vader_struct_toolchain_ast_AssignStmt_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_AssignStmt_t));
        vader_obj_header_init(_a3_obj, 444u);
        _a3_obj->f_span = l3;
        _a3_obj->f_id = (size_t) 0;
        _a3_obj->f_target = l2;
        _a3_obj->f_value = l5;
        t0 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 460u) {
        vader_array_t* _a4_arr = vader_array_new(184u, 0u, 13u, 1313u);
        l3 = (void*) _a4_arr;
        t0 = l0.payload.obj;
        l7 = ((vader_struct_toolchain_ast_DestructureAssignStmt_t*) t0)->f_targets;
        l8 = ((vader_array_t*) l7)->length;
        l9 = (size_t) 0;
        while ((l9 < l8)) {
            vader_array_t* _a5_slotarr = ((vader_array_t*) l7);
            VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l9)
            l2 = vader_array_ref_load_box(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l9);
            if (l2.tag == 503u) {
                t0 = l2.payload.obj;
                l5 = vader_resolver_substitute_expr_full(((vader_struct_toolchain_ast_PlaceTarget_t*) t0)->f_place, l1);
                t0 = l2.payload.obj;
                vader_struct_toolchain_ast_PlaceTarget_t* _a6_obj = (vader_struct_toolchain_ast_PlaceTarget_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_PlaceTarget_t));
                vader_obj_header_init(_a6_obj, 503u);
                _a6_obj->f_span = ((vader_struct_toolchain_ast_PlaceTarget_t*) t0)->f_span;
                _a6_obj->f_id = (size_t) 0;
                _a6_obj->f_place = l5;
                l10 = (void*) _a6_obj;
                vader_array_push((vader_array_t*) l3, vader_ref_box(l10));
            } else if (l2.tag == 508u) {
                t0 = l2.payload.obj;
                l6 = vader_resolver_substitute_expr_full(((vader_struct_toolchain_ast_RestTarget_t*) t0)->f_place, l1);
                t0 = l2.payload.obj;
                vader_struct_toolchain_ast_RestTarget_t* _a7_obj = (vader_struct_toolchain_ast_RestTarget_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_RestTarget_t));
                vader_obj_header_init(_a7_obj, 508u);
                _a7_obj->f_span = ((vader_struct_toolchain_ast_RestTarget_t*) t0)->f_span;
                _a7_obj->f_id = (size_t) 0;
                _a7_obj->f_place = l6;
                l11 = (void*) _a7_obj;
                vader_array_push((vader_array_t*) l3, vader_ref_box(l11));
            } else {
                if (!(l2.tag == 531u)) {
                    vader_unreachable("non-exhaustive match (T3013 should have caught this)");
                }
                t0 = l2.payload.obj;
                vader_struct_toolchain_ast_WildcardTarget_t* _a8_obj = (vader_struct_toolchain_ast_WildcardTarget_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_WildcardTarget_t));
                vader_obj_header_init(_a8_obj, 531u);
                _a8_obj->f_span = ((vader_struct_toolchain_ast_WildcardTarget_t*) t0)->f_span;
                _a8_obj->f_id = (size_t) 0;
                l12 = (void*) _a8_obj;
                vader_array_push((vader_array_t*) l3, vader_ref_box(l12));
            }
            t1 = (l9 + INT64_C(1));
            l9 = (size_t) (int64_t) t1;
        }
        t0 = l0.payload.obj;
        l7 = ((vader_struct_toolchain_ast_DestructureAssignStmt_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l2 = vader_resolver_substitute_expr_full(((vader_struct_toolchain_ast_DestructureAssignStmt_t*) t0)->f_value, l1);
        vader_struct_toolchain_ast_DestructureAssignStmt_t* _a9_obj = (vader_struct_toolchain_ast_DestructureAssignStmt_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_DestructureAssignStmt_t));
        vader_obj_header_init(_a9_obj, 460u);
        _a9_obj->f_span = l7;
        _a9_obj->f_id = (size_t) 0;
        _a9_obj->f_targets = l3;
        _a9_obj->f_value = l2;
        t0 = (void*) _a9_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 474u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast_ForStmt_t*) t0)->f_form;
        t0 = l0.payload.obj;
        l5 = ((vader_struct_toolchain_ast_ForStmt_t*) t0)->f_form;
        l6 = l5;
        if (l5.tag == 527u) {
            t0 = l6.payload.obj;
            t2 = vader_resolver_substitute_expr_full(((vader_struct_toolchain_ast_WhileFor_t*) t0)->f_cond, l1);
            vader_struct_toolchain_ast_WhileFor_t* _a10_obj = (vader_struct_toolchain_ast_WhileFor_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_WhileFor_t));
            vader_obj_header_init(_a10_obj, 527u);
            _a10_obj->f_cond = t2;
            t0 = (void*) _a10_obj;
            l2 = vader_ref_box(t0);
        } else if (l5.tag == 483u) {
            t0 = l6.payload.obj;
            l13 = ((vader_struct_toolchain_ast_InFor_t*) t0)->f_loop_var;
            t0 = l6.payload.obj;
            l6 = vader_resolver_substitute_expr_full(((vader_struct_toolchain_ast_InFor_t*) t0)->f_iter, l1);
            vader_struct_toolchain_ast_InFor_t* _a11_obj = (vader_struct_toolchain_ast_InFor_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_InFor_t));
            vader_obj_header_init(_a11_obj, 483u);
            _a11_obj->f_loop_var = l13;
            _a11_obj->f_iter = l6;
            t0 = (void*) _a11_obj;
            l2 = vader_ref_box(t0);
        } else if (!(l5.tag == 485u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        t0 = l0.payload.obj;
        l3 = ((vader_struct_toolchain_ast_ForStmt_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l5 = ((vader_struct_toolchain_ast_ForStmt_t*) t0)->f_label;
        t0 = l0.payload.obj;
        l7 = vader_resolver_substitute_block(((vader_struct_toolchain_ast_ForStmt_t*) t0)->f_body, l1);
        t0 = l0.payload.obj;
        l4 = ((vader_struct_toolchain_ast_ForStmt_t*) t0)->f_is_comptime;
        vader_struct_toolchain_ast_ForStmt_t* _a12_obj = (vader_struct_toolchain_ast_ForStmt_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_ForStmt_t));
        vader_obj_header_init(_a12_obj, 474u);
        _a12_obj->f_span = l3;
        _a12_obj->f_id = (size_t) 0;
        _a12_obj->f_label = l5;
        _a12_obj->f_form = l2;
        _a12_obj->f_body = l7;
        _a12_obj->f_is_comptime = l4;
        t0 = (void*) _a12_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 449u) {
        t0 = l0.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l0.tag == 455u)) {
        { vader_box_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l0.payload.obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_resolver_substitute_type_expr(vader_box_t l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l6 = vader_box_null(), l7 = vader_box_null();
    vader_string_t l3 = 0;
    void* l4 = NULL;
    void* l8 = NULL;
    void* l11 = NULL;
    uint8_t l5;
    size_t l9, l10;
    bool l12;
    void* t0 = NULL;
    void* t1 = NULL;
    vader_box_t t2 = vader_box_null();
    int64_t t3;
    vader_box_t* gc_roots[5] = { &l0, &l2, &l6, &l7, &t2 };
    void** gc_raw_roots[6] = { &l1, &l4, &l8, &l11, &t0, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 5u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l0.tag == 476u) {
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
    if (l0.tag == 446u) {
        t0 = l0.payload.obj;
        l4 = ((vader_struct_toolchain_ast_BinaryExpr_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l5 = ((vader_struct_toolchain_ast_BinaryExpr_t*) t0)->f_op;
        t0 = l0.payload.obj;
        l2 = vader_resolver_substitute_type_expr(((vader_struct_toolchain_ast_BinaryExpr_t*) t0)->f_left, l1);
        t0 = l0.payload.obj;
        l6 = vader_resolver_substitute_type_expr(((vader_struct_toolchain_ast_BinaryExpr_t*) t0)->f_right, l1);
        t0 = l0.payload.obj;
        l7 = ((vader_struct_toolchain_ast_BinaryExpr_t*) t0)->f_bind_as;
        vader_struct_toolchain_ast_BinaryExpr_t* _a0_obj = (vader_struct_toolchain_ast_BinaryExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_BinaryExpr_t));
        vader_obj_header_init(_a0_obj, 446u);
        _a0_obj->f_span = l4;
        _a0_obj->f_id = (size_t) 0;
        _a0_obj->f_op = l5;
        _a0_obj->f_left = l2;
        _a0_obj->f_right = l6;
        _a0_obj->f_bind_as = l7;
        t0 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 473u) {
        vader_array_t* _a1_arr = vader_array_new(179u, 0u, 13u, 1259u);
        l4 = (void*) _a1_arr;
        t0 = l0.payload.obj;
        l8 = ((vader_struct_toolchain_ast_FnTypeExpr_t*) t0)->f_params;
        l9 = ((vader_array_t*) l8)->length;
        l10 = (size_t) 0;
        while ((l10 < l9)) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) l8);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l10)
            t2 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l10);
            l2 = vader_resolver_substitute_type_expr(t2, l1);
            vader_array_push((vader_array_t*) l4, l2);
            t3 = (l10 + INT64_C(1));
            l10 = (size_t) (int64_t) t3;
        }
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast_FnTypeExpr_t*) t0)->f_return_type;
        l6 = vader_box_obj(0u, NULL);
        if (!(l2.tag == 0u)) {
            l6 = vader_resolver_substitute_type_expr(l2, l1);
        }
        t0 = l0.payload.obj;
        l8 = ((vader_struct_toolchain_ast_FnTypeExpr_t*) t0)->f_span;
        vader_array_t* _a3_arr = vader_array_new(11u, 0u, 12u, 242u);
        l11 = (void*) _a3_arr;
        vader_struct_toolchain_ast_FnTypeExpr_t* _a4_obj = (vader_struct_toolchain_ast_FnTypeExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_FnTypeExpr_t));
        vader_obj_header_init(_a4_obj, 473u);
        _a4_obj->f_span = l8;
        _a4_obj->f_id = (size_t) 0;
        _a4_obj->f_params = l4;
        _a4_obj->f_params_mutable = l11;
        _a4_obj->f_return_type = l6;
        t0 = (void*) _a4_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 441u) {
        t0 = l0.payload.obj;
        l4 = ((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t0)->f_span;
        t0 = l0.payload.obj;
        l2 = vader_resolver_substitute_type_expr(((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t0)->f_element, l1);
        vader_struct_toolchain_ast_ArrayTypeExpr_t* _a5_obj = (vader_struct_toolchain_ast_ArrayTypeExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_ArrayTypeExpr_t));
        vader_obj_header_init(_a5_obj, 441u);
        _a5_obj->f_span = l4;
        _a5_obj->f_id = (size_t) 0;
        _a5_obj->f_element = l2;
        t0 = (void*) _a5_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 495u) {
        l4 = l0.payload.obj;
        t0 = ((vader_struct_toolchain_ast_MutableTypeExpr_t*) l4)->f_span;
        l2 = vader_ref_box(t0);
        t0 = l0.payload.obj;
        l6 = vader_resolver_substitute_type_expr(((vader_struct_toolchain_ast_MutableTypeExpr_t*) t0)->f_inner, l1);
        l12 = ((vader_struct_toolchain_ast_MutableTypeExpr_t*) l4)->f_deduced;
        vader_struct_toolchain_ast_MutableTypeExpr_t* _a6_obj = (vader_struct_toolchain_ast_MutableTypeExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_MutableTypeExpr_t));
        vader_obj_header_init(_a6_obj, 495u);
        _a6_obj->f_span = l2.payload.obj;
        _a6_obj->f_id = (size_t) 0;
        _a6_obj->f_inner = l6;
        _a6_obj->f_deduced = l12;
        t0 = (void*) _a6_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 510u) {
        vader_array_t* _a7_arr = vader_array_new(179u, 0u, 13u, 1259u);
        l4 = (void*) _a7_arr;
        t0 = l0.payload.obj;
        l8 = ((vader_struct_toolchain_ast_SeqLitExpr_t*) t0)->f_elements;
        l9 = ((vader_array_t*) l8)->length;
        l10 = (size_t) 0;
        while ((l10 < l9)) {
            vader_array_t* _a8_slotarr = ((vader_array_t*) l8);
            VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l10)
            t2 = vader_array_ref_load_box(_a8_slotarr->buf, _a8_slotarr->offset + (size_t) l10);
            l2 = vader_resolver_substitute_type_expr(t2, l1);
            vader_array_push((vader_array_t*) l4, l2);
            t3 = (l10 + INT64_C(1));
            l10 = (size_t) (int64_t) t3;
        }
        t0 = l0.payload.obj;
        vader_struct_toolchain_ast_SeqLitExpr_t* _a9_obj = (vader_struct_toolchain_ast_SeqLitExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_SeqLitExpr_t));
        vader_obj_header_init(_a9_obj, 510u);
        _a9_obj->f_span = ((vader_struct_toolchain_ast_SeqLitExpr_t*) t0)->f_span;
        _a9_obj->f_id = (size_t) 0;
        _a9_obj->f_elements = l4;
        _a9_obj->f_trailing_comma = false;
        t0 = (void*) _a9_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l0.tag == 475u)) {
        { vader_box_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a10_arr = vader_array_new(179u, 0u, 13u, 1259u);
    l4 = (void*) _a10_arr;
    t0 = l0.payload.obj;
    l8 = ((vader_struct_toolchain_ast_GenericInstExpr_t*) t0)->f_type_args;
    l9 = ((vader_array_t*) l8)->length;
    l10 = (size_t) 0;
    while ((l10 < l9)) {
        vader_array_t* _a11_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l10)
        t2 = vader_array_ref_load_box(_a11_slotarr->buf, _a11_slotarr->offset + (size_t) l10);
        l2 = vader_resolver_substitute_type_expr(t2, l1);
        vader_array_push((vader_array_t*) l4, l2);
        t3 = (l10 + INT64_C(1));
        l10 = (size_t) (int64_t) t3;
    }
    t0 = l0.payload.obj;
    l8 = ((vader_struct_toolchain_ast_GenericInstExpr_t*) t0)->f_span;
    t0 = l0.payload.obj;
    l2 = ((vader_struct_toolchain_ast_GenericInstExpr_t*) t0)->f_callee;
    vader_struct_toolchain_ast_GenericInstExpr_t* _a12_obj = (vader_struct_toolchain_ast_GenericInstExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_GenericInstExpr_t));
    vader_obj_header_init(_a12_obj, 475u);
    _a12_obj->f_span = l8;
    _a12_obj->f_id = (size_t) 0;
    _a12_obj->f_callee = l2;
    _a12_obj->f_type_args = l4;
    t0 = (void*) _a12_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_resolver_swap_root(void* l0, void* l1) {
    void* l2;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_resolver_Scope_t*) l0)->f_frames);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
    l2 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT32_C(0));
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
    vader_array_ref_store(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT32_C(0), l1);
    VADER_WRITE_BARRIER(_a0_slotarr->buf);
    return l2;
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
    vader_obj_header_init(_a0_obj, 533u);
    _a0_obj->f_file = 0u;
    _a0_obj->f_offset = (size_t) 0;
    _a0_obj->f_line = INT32_C(0);
    _a0_obj->f_column = l1;
    l2 = (void*) _a0_obj;
    vader_struct_toolchain_span_Span_t* _a1_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
    vader_obj_header_init(_a1_obj, 534u);
    _a1_obj->f_start = l2;
    _a1_obj->f_end = l2;
    t1 = (void*) _a1_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
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
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = ((vader_struct_toolchain_ast_FnDecl_t*) l0)->f_span;
    l5 = ((vader_struct_toolchain_ast_FnDecl_t*) l0)->f_name;
    vader_array_t* _a0_arr = vader_array_new(42u, 0u, 13u, 525u);
    l6 = (void*) _a0_arr;
    l7 = vader_resolver_substitute_params(((vader_struct_toolchain_ast_FnDecl_t*) l0)->f_params, l2);
    l8 = vader_resolver_substitute_opt_type(((vader_struct_toolchain_ast_FnDecl_t*) l0)->f_return_type, l2);
    l9 = ((vader_struct_toolchain_ast_FnDecl_t*) l0)->f_is_expression_bodied;
    vader_struct_toolchain_ast_FnDecl_t* _a1_obj = (vader_struct_toolchain_ast_FnDecl_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_FnDecl_t));
    vader_obj_header_init(_a1_obj, 471u);
    _a1_obj->f_span = l4;
    _a1_obj->f_id = (size_t) 0;
    _a1_obj->f_name = l5;
    _a1_obj->f_name_span = l1;
    _a1_obj->f_visibility = (uint8_t) 0;
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
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 10u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l5 = ((vader_struct_toolchain_ast_FnDecl_t*) l0)->f_span;
    l6 = ((vader_struct_toolchain_ast_FnDecl_t*) l0)->f_name;
    l7 = ((vader_struct_toolchain_ast_FnDecl_t*) l0)->f_name_span;
    vader_array_t* _a0_arr = vader_array_new(42u, 0u, 13u, 525u);
    l8 = (void*) _a0_arr;
    l9 = vader_resolver_substitute_params_stamped(((vader_struct_toolchain_ast_FnDecl_t*) l0)->f_params, l1, l4);
    l10 = vader_resolver_substitute_opt_type(((vader_struct_toolchain_ast_FnDecl_t*) l0)->f_return_type, l1);
    l11 = ((vader_struct_toolchain_ast_FnDecl_t*) l0)->f_is_expression_bodied;
    vader_struct_toolchain_ast_FnDecl_t* _a1_obj = (vader_struct_toolchain_ast_FnDecl_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_FnDecl_t));
    vader_obj_header_init(_a1_obj, 471u);
    _a1_obj->f_span = l5;
    _a1_obj->f_id = (size_t) 0;
    _a1_obj->f_name = l6;
    _a1_obj->f_name_span = l7;
    _a1_obj->f_visibility = (uint8_t) 0;
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
    vader_box_t* gc_roots[2] = { &l9, &l10 };
    void** gc_raw_roots[6] = { &l0, &l1, &l4, &l5, &l6, &t2 };
    vader_string_t* gc_atom_roots[2] = { &t0, &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = l0;
    l2 = ((vader_array_t*) l1)->length;
    l3 = (size_t) 0;
    for (;;) {
        if ((l3 < l2)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
            l4 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
            t0 = ((vader_struct_toolchain_ast_Decorator_t*) l4)->f_name;
            if (t0 != 2331u) {
                t1 = (l3 + INT64_C(1));
                l3 = (size_t) (int64_t) t1;
                continue;
            }
            vader_array_t* _a1_arr = vader_array_new(16u, 0u, 1u, 250u);
            l5 = (void*) _a1_arr;
            l6 = ((vader_struct_toolchain_ast_Decorator_t*) l4)->f_args;
            l7 = ((vader_array_t*) l6)->length;
            l8 = (size_t) 0;
            while ((l8 < l7)) {
                vader_array_t* _a2_slotarr = ((vader_array_t*) l6);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l8)
                l9 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l8);
                if (l9.tag == 464u) {
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
            }
            t4 = ((vader_array_t*) ((vader_struct_toolchain_ast_Decorator_t*) l4)->f_args)->length;
            l12 = t4 == INT64_C(0);
            vader_struct_vader_resolver_TargetSelectors_t* _a3_obj = (vader_struct_vader_resolver_TargetSelectors_t*) vader_gc_alloc(sizeof(vader_struct_vader_resolver_TargetSelectors_t));
            vader_obj_header_init(_a3_obj, 1023u);
            _a3_obj->f_os = l5;
            _a3_obj->f_is_bare = l12;
            t2 = (void*) _a3_obj;
            { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
        }
        break;
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static vader_box_t vader_resolver_try_read(vader_string_t l0) {
    vader_box_t l1 = vader_box_null();
    vader_string_t t0 = 0;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l1, &t1 };
    vader_string_t* gc_atom_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 0u, gc_roots, NULL, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = std_io_read_file_string(l0, (size_t) 16777216);
    if (!(l1.tag == 244u)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    t0 = l1.payload.s;
    t1 = vader_box_string(244u, t0);
    { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_resolver_union_in_bound(vader_box_t l0) {
    vader_box_t l1;
    void* t0;
    vader_box_t t1;
    if (!(l0.tag == 446u)) {
        return vader_box_obj(0u, NULL);
    }
    t0 = l0.payload.obj;
    if (((vader_struct_toolchain_ast_BinaryExpr_t*) t0)->f_op == INT32_C(8)) {
        t0 = l0.payload.obj;
        return vader_ref_box(t0);
    }
    t0 = l0.payload.obj;
    if (((vader_struct_toolchain_ast_BinaryExpr_t*) t0)->f_op != INT32_C(7)) {
        return vader_box_obj(0u, NULL);
    }
    t0 = l0.payload.obj;
    l1 = vader_resolver_union_in_bound(((vader_struct_toolchain_ast_BinaryExpr_t*) t0)->f_left);
    if (l1.tag == 0u) {
        t0 = l0.payload.obj;
        t1 = vader_resolver_union_in_bound(((vader_struct_toolchain_ast_BinaryExpr_t*) t0)->f_right);
        return t1;
    }
    t0 = l1.payload.obj;
    return vader_ref_box(t0);
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
    l4 = (size_t) 0;
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        l5 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        vader_resolver_walk_stmt(l0, l5);
        t0 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t0;
    }
    l5 = ((vader_struct_toolchain_ast_BlockExpr_t*) l1)->f_trailing;
    vader_resolver_walk_opt_expr(l0, l5);
    vader_resolver_pop(((vader_struct_vader_resolver_ResolveState_t*) l0)->f_scope);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_resolver_walk_body(void* l0, void* l1) {
    void* l2 = NULL;
    vader_string_t l3 = 0;
    vader_box_t l4 = vader_box_null();
    vader_box_t* gc_roots[1] = { &l4 };
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_string_t* gc_atom_roots[1] = { &l3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_file_scopes;
    l3 = ((vader_struct_toolchain_span_Position_t*) ((vader_struct_toolchain_span_Span_t*) ((vader_struct_toolchain_ast_BlockExpr_t*) l1)->f_span)->f_start)->f_file;
    l4 = std_collections_MutableMap_Index_at__string__Any(l2, l3);
    if (!(l4.tag == 0u)) {
        l2 = l4.payload.obj;
        l2 = vader_resolver_enter_file(l0, l2);
        vader_resolver_walk_block(l0, l1);
        vader_resolver_enter_file(l0, l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_resolver_walk_block(l0, l1);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_resolver_walk_decl(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    void* l5 = NULL;
    size_t l3, l4;
    vader_box_t l6 = vader_box_null();
    void* t0 = NULL;
    int64_t t1;
    vader_box_t* gc_roots[2] = { &l1, &l6 };
    void** gc_raw_roots[4] = { &l0, &l2, &l5, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l1.tag == 481u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 471u) {
        l2 = l1.payload.obj;
        vader_resolver_walk_fn_decl(l0, l2);
    } else if (l1.tag == 515u) {
        l2 = l1.payload.obj;
        vader_resolver_walk_struct_decl(l0, l2);
    } else if (l1.tag == 465u) {
        l2 = l1.payload.obj;
        vader_resolver_walk_enum_decl(l0, l2);
    } else if (l1.tag == 522u) {
        l2 = l1.payload.obj;
        vader_resolver_walk_trait_decl(l0, l2);
    } else if (l1.tag == 480u) {
        l2 = l1.payload.obj;
        vader_resolver_walk_impl_decl(l0, l2);
    } else if (l1.tag == 524u) {
        vader_resolver_push(((vader_struct_vader_resolver_ResolveState_t*) l0)->f_scope);
        t0 = l1.payload.obj;
        l2 = ((vader_struct_toolchain_ast_TypeAliasDecl_t*) t0)->f_type_params;
        l3 = ((vader_array_t*) l2)->length;
        l4 = (size_t) 0;
        while ((l4 < l3)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
            l5 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
            vader_resolver_bind_type_param(l0, l5);
            if (!(((vader_struct_toolchain_ast_TypeParam_t*) l5)->f_bound.tag == 0u)) {
                l6 = ((vader_struct_toolchain_ast_TypeParam_t*) l5)->f_bound;
                vader_resolver_checked_bound(l0, l5, l6);
            }
            t1 = (l4 + INT64_C(1));
            l4 = (size_t) (int64_t) t1;
        }
        t0 = l1.payload.obj;
        l6 = ((vader_struct_toolchain_ast_TypeAliasDecl_t*) t0)->f_aliased;
        vader_resolver_walk_opt_expr(l0, l6);
        vader_resolver_pop(((vader_struct_vader_resolver_ResolveState_t*) l0)->f_scope);
    } else if (l1.tag == 454u) {
        t0 = l1.payload.obj;
        l6 = ((vader_struct_toolchain_ast_ConstDecl_t*) t0)->f_ty;
        vader_resolver_walk_opt_expr(l0, l6);
        t0 = l1.payload.obj;
        l6 = ((vader_struct_toolchain_ast_ConstDecl_t*) t0)->f_value;
        vader_resolver_walk_expr(l0, l6);
    } else {
        if (!(l1.tag == 443u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        t0 = l1.payload.obj;
        l6 = ((vader_struct_toolchain_ast_AssertDecl_t*) t0)->f_condition;
        vader_resolver_walk_expr(l0, l6);
    }
    { vader_gc_top = gc_frame.prev; return; }
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
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = l1;
    l3 = ((vader_array_t*) l2)->length;
    l4 = (size_t) 0;
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        l5 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        t0 = ((vader_struct_toolchain_ast_Decorator_t*) l5)->f_name;
        t1 = vader_resolver_is_known_decorator(t0);
        if (!(t1)) {
            l6 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_diags;
            l7 = ((vader_struct_toolchain_ast_Decorator_t*) l5)->f_span;
            l8 = ((vader_struct_toolchain_ast_Decorator_t*) l5)->f_name;
            l9 = concat_3(1114u, l8, 866u);
            l10 = vader_diagnostics_resolver_error((uint8_t) 9, l7, l9);
            vader_array_push((vader_array_t*) l6, vader_ref_box(l10));
        }
        t0 = ((vader_struct_toolchain_ast_Decorator_t*) l5)->f_name;
        if (t0 == 2331u) {
            vader_resolver_check_target_selectors(l0, l5);
            t2 = (l4 + INT64_C(1));
            l4 = (size_t) (int64_t) t2;
            continue;
        }
        l11 = ((vader_struct_toolchain_ast_Decorator_t*) l5)->f_args;
        l12 = ((vader_array_t*) l11)->length;
        l13 = (size_t) 0;
        while ((l13 < l12)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l11);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l13)
            l14 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l13);
            vader_resolver_walk_expr(l0, l14);
            t2 = (l13 + INT64_C(1));
            l13 = (size_t) (int64_t) t2;
        }
        t2 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t2;
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_resolver_walk_defer(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l3 = vader_box_null(), l4 = vader_box_null();
    void* l5 = NULL;
    void* t0 = NULL;
    vader_box_t* gc_roots[3] = { &l2, &l3, &l4 };
    void** gc_raw_roots[4] = { &l0, &l1, &l5, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_toolchain_ast_DeferStmt_t*) l1)->f_body;
    l3 = l2;
    if (l2.tag == 459u) {
        t0 = l3.payload.obj;
        l4 = ((vader_struct_toolchain_ast_DeferStmtBody_t*) t0)->f_stmt;
        vader_resolver_walk_stmt(l0, l4);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (!(l2.tag == 457u)) {
        vader_unreachable("non-exhaustive match (T3013 should have caught this)");
    }
    t0 = l3.payload.obj;
    l5 = ((vader_struct_toolchain_ast_DeferBlockBody_t*) t0)->f_block;
    vader_resolver_walk_block(l0, l5);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_resolver_walk_enum_decl(void* l0, void* l1) {
    void* l2 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    size_t l3, l4;
    vader_box_t l5 = vader_box_null();
    int64_t t0;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l5, &t1 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l6, &l7 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_toolchain_ast_EnumDecl_t*) l1)->f_decorators;
    vader_resolver_walk_decorators(l0, l2);
    l2 = ((vader_struct_toolchain_ast_EnumDecl_t*) l1)->f_header;
    l3 = ((vader_array_t*) l2)->length;
    l4 = (size_t) 0;
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        l5 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        vader_resolver_walk_expr(l0, l5);
        t0 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t0;
    }
    l2 = ((vader_struct_toolchain_ast_EnumDecl_t*) l1)->f_variants;
    l3 = ((vader_array_t*) l2)->length;
    l4 = (size_t) 0;
    while ((l4 < l3)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
        l6 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
        if (!(((vader_struct_toolchain_ast_EnumVariant_t*) l6)->f_data.tag == 0u)) {
            t1 = ((vader_struct_toolchain_ast_EnumVariant_t*) l6)->f_data;
            l7 = t1.payload.obj;
            vader_resolver_walk_struct_lit_items(l0, l7);
        }
        t0 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t0;
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_resolver_walk_expr(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    void* l6 = NULL;
    vader_string_t l3 = 0;
    vader_box_t l4 = vader_box_null(), l9 = vader_box_null(), l10 = vader_box_null();
    uint64_t l5;
    size_t l7, l8;
    void* t0 = NULL;
    int64_t t1;
    vader_box_t* gc_roots[4] = { &l1, &l4, &l9, &l10 };
    void** gc_raw_roots[4] = { &l0, &l2, &l6, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l1.tag == 476u) {
        l2 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_scope;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_toolchain_ast_IdentExpr_t*) t0)->f_name;
        l4 = vader_resolver_lookup(l2, l3);
        if (l4.tag == 1024u) {
            l2 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_idents;
            t0 = l1.payload.obj;
            l5 = toolchain_span_Span_Hash_hash(((vader_struct_toolchain_ast_IdentExpr_t*) t0)->f_span);
            l6 = l4.payload.obj;
            std_collections_MutableMap_IndexSet_set_at__u64__Any(l2, l5, vader_ref_box(l6));
            t0 = l1.payload.obj;
            l3 = ((vader_struct_toolchain_ast_IdentExpr_t*) t0)->f_name;
            t0 = l1.payload.obj;
            l2 = ((vader_struct_toolchain_ast_IdentExpr_t*) t0)->f_span;
            l6 = l4.payload.obj;
            vader_resolver_check_wildcard_ambiguity(l0, l3, l2, l6);
        } else {
            if (!(l4.tag == 0u)) {
                vader_unreachable("non-exhaustive match (T3013 should have caught this)");
            }
            l2 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_diags;
            t0 = l1.payload.obj;
            l6 = ((vader_struct_toolchain_ast_IdentExpr_t*) t0)->f_span;
            t0 = l1.payload.obj;
            l3 = ((vader_struct_toolchain_ast_IdentExpr_t*) t0)->f_name;
            l3 = concat_3(866u, l3, 866u);
            l6 = vader_diagnostics_resolver_error((uint8_t) 5, l6, l3);
            vader_array_push((vader_array_t*) l2, vader_ref_box(l6));
        }
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 451u) {
        t0 = l1.payload.obj;
        l4 = ((vader_struct_toolchain_ast_CallExpr_t*) t0)->f_callee;
        vader_resolver_walk_expr(l0, l4);
        t0 = l1.payload.obj;
        l2 = ((vader_struct_toolchain_ast_CallExpr_t*) t0)->f_args;
        l7 = ((vader_array_t*) l2)->length;
        l8 = (size_t) 0;
        while ((l8 < l7)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l8)
            t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l8);
            l4 = ((vader_struct_toolchain_ast_CallArg_t*) t0)->f_value;
            vader_resolver_walk_expr(l0, l4);
            t1 = (l8 + INT64_C(1));
            l8 = (size_t) (int64_t) t1;
        }
    } else if (l1.tag == 469u) {
        t0 = l1.payload.obj;
        l4 = ((vader_struct_toolchain_ast_FieldExpr_t*) t0)->f_target;
        vader_resolver_walk_expr(l0, l4);
    } else if (l1.tag == 484u) {
        t0 = l1.payload.obj;
        l4 = ((vader_struct_toolchain_ast_IndexExpr_t*) t0)->f_target;
        vader_resolver_walk_expr(l0, l4);
        t0 = l1.payload.obj;
        l4 = ((vader_struct_toolchain_ast_IndexExpr_t*) t0)->f_index;
        vader_resolver_walk_expr(l0, l4);
    } else if (l1.tag == 526u) {
        t0 = l1.payload.obj;
        l4 = ((vader_struct_toolchain_ast_UnaryExpr_t*) t0)->f_operand;
        vader_resolver_walk_expr(l0, l4);
    } else if (l1.tag == 446u) {
        t0 = l1.payload.obj;
        l4 = ((vader_struct_toolchain_ast_BinaryExpr_t*) t0)->f_left;
        vader_resolver_walk_expr(l0, l4);
        t0 = l1.payload.obj;
        l4 = ((vader_struct_toolchain_ast_BinaryExpr_t*) t0)->f_right;
        vader_resolver_walk_expr(l0, l4);
    } else if (l1.tag == 498u) {
        t0 = l1.payload.obj;
        l4 = ((vader_struct_toolchain_ast_NullCoalesceExpr_t*) t0)->f_left;
        vader_resolver_walk_expr(l0, l4);
        t0 = l1.payload.obj;
        l4 = ((vader_struct_toolchain_ast_NullCoalesceExpr_t*) t0)->f_fallback;
        l9 = l4;
        if ((l4.tag == 449u || l4.tag == 455u || l4.tag == 509u)) {
            l10 = l9;
            vader_resolver_walk_stmt(l0, l10);
        } else {
            if (!((l4.tag == 441u || l4.tag == 445u || l4.tag == 446u || l4.tag == 447u || l4.tag == 448u || l4.tag == 451u || l4.tag == 452u || l4.tag == 453u || l4.tag == 464u || l4.tag == 469u || l4.tag == 470u || l4.tag == 473u || l4.tag == 475u || l4.tag == 476u || l4.tag == 479u || l4.tag == 484u || l4.tag == 486u || l4.tag == 487u || l4.tag == 489u || l4.tag == 493u || l4.tag == 495u || l4.tag == 498u || l4.tag == 499u || l4.tag == 505u || l4.tag == 510u || l4.tag == 512u || l4.tag == 517u || l4.tag == 526u))) {
                vader_unreachable("non-exhaustive match (T3013 should have caught this)");
            }
            l4 = l9;
            vader_resolver_walk_expr(l0, l4);
        }
    } else if (l1.tag == 479u) {
        l2 = l1.payload.obj;
        vader_resolver_walk_if(l0, l2);
    } else if (l1.tag == 493u) {
        l2 = l1.payload.obj;
        vader_resolver_walk_match(l0, l2);
    } else if (l1.tag == 447u) {
        l2 = l1.payload.obj;
        vader_resolver_walk_block(l0, l2);
    } else if (l1.tag == 489u) {
        l2 = l1.payload.obj;
        vader_resolver_walk_lambda(l0, l2);
    } else if (l1.tag == 517u) {
        l2 = l1.payload.obj;
        vader_resolver_walk_struct_lit(l0, l2);
    } else if (l1.tag == 510u) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_toolchain_ast_SeqLitExpr_t*) t0)->f_elements;
        l7 = ((vader_array_t*) l2)->length;
        l8 = (size_t) 0;
        while ((l8 < l7)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l8)
            l4 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l8);
            vader_resolver_walk_expr(l0, l4);
            t1 = (l8 + INT64_C(1));
            l8 = (size_t) (int64_t) t1;
        }
    } else if (l1.tag == 505u) {
        t0 = l1.payload.obj;
        l4 = ((vader_struct_toolchain_ast_RangeExpr_t*) t0)->f_lower;
        vader_resolver_walk_expr(l0, l4);
        t0 = l1.payload.obj;
        l4 = ((vader_struct_toolchain_ast_RangeExpr_t*) t0)->f_upper;
        vader_resolver_walk_expr(l0, l4);
    } else if (l1.tag == 445u) {
        t0 = l1.payload.obj;
        l4 = ((vader_struct_toolchain_ast_AwaitExpr_t*) t0)->f_inner;
        vader_resolver_walk_expr(l0, l4);
    } else if (l1.tag == 452u) {
        t0 = l1.payload.obj;
        l4 = ((vader_struct_toolchain_ast_CastExpr_t*) t0)->f_value;
        vader_resolver_walk_expr(l0, l4);
        t0 = l1.payload.obj;
        l4 = ((vader_struct_toolchain_ast_CastExpr_t*) t0)->f_target;
        vader_resolver_walk_expr(l0, l4);
    } else if (l1.tag == 475u) {
        t0 = l1.payload.obj;
        l4 = ((vader_struct_toolchain_ast_GenericInstExpr_t*) t0)->f_callee;
        vader_resolver_walk_expr(l0, l4);
        t0 = l1.payload.obj;
        l2 = ((vader_struct_toolchain_ast_GenericInstExpr_t*) t0)->f_type_args;
        l7 = ((vader_array_t*) l2)->length;
        l8 = (size_t) 0;
        while ((l8 < l7)) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l8)
            l4 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l8);
            vader_resolver_walk_expr(l0, l4);
            t1 = (l8 + INT64_C(1));
            l8 = (size_t) (int64_t) t1;
        }
    } else if (l1.tag == 487u) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) t0)->f_args;
        l7 = ((vader_array_t*) l2)->length;
        l8 = (size_t) 0;
        while ((l8 < l7)) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l8)
            l4 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l8);
            vader_resolver_walk_expr(l0, l4);
            t1 = (l8 + INT64_C(1));
            l8 = (size_t) (int64_t) t1;
        }
    } else if (!(l1.tag == 464u)) {
        if (l1.tag == 473u) {
            t0 = l1.payload.obj;
            l2 = ((vader_struct_toolchain_ast_FnTypeExpr_t*) t0)->f_params;
            l7 = ((vader_array_t*) l2)->length;
            l8 = (size_t) 0;
            while ((l8 < l7)) {
                vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
                VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l8)
                l4 = vader_array_ref_load_box(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l8);
                vader_resolver_walk_expr(l0, l4);
                t1 = (l8 + INT64_C(1));
                l8 = (size_t) (int64_t) t1;
            }
            t0 = l1.payload.obj;
            l4 = ((vader_struct_toolchain_ast_FnTypeExpr_t*) t0)->f_return_type;
            vader_resolver_walk_opt_expr(l0, l4);
        } else if (l1.tag == 441u) {
            t0 = l1.payload.obj;
            l4 = ((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t0)->f_element;
            vader_resolver_walk_expr(l0, l4);
        } else if (l1.tag == 495u) {
            t0 = l1.payload.obj;
            l4 = ((vader_struct_toolchain_ast_MutableTypeExpr_t*) t0)->f_inner;
            vader_resolver_walk_expr(l0, l4);
        } else if (!(l1.tag == 486u)) {
            if (!(l1.tag == 470u)) {
                if (!(l1.tag == 448u)) {
                    if (!(l1.tag == 499u)) {
                        if (!(l1.tag == 453u)) {
                            if (!(l1.tag == 512u)) {
                                vader_unreachable("non-exhaustive match (T3013 should have caught this)");
                            }
                            t0 = l1.payload.obj;
                            l2 = ((vader_struct_toolchain_ast_StringLitExpr_t*) t0)->f_parts;
                            l7 = ((vader_array_t*) l2)->length;
                            l8 = (size_t) 0;
                            while ((l8 < l7)) {
                                vader_array_t* _a5_slotarr = ((vader_array_t*) l2);
                                VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
                                VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l8)
                                l4 = vader_array_ref_load_box(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l8);
                                if (l4.tag == 513u) {
                                    t0 = l4.payload.obj;
                                    l9 = ((vader_struct_toolchain_ast_StringLitInterp_t*) t0)->f_expr;
                                    vader_resolver_walk_expr(l0, l9);
                                }
                                t1 = (l8 + INT64_C(1));
                                l8 = (size_t) (int64_t) t1;
                            }
                        }
                    }
                }
            }
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_resolver_walk_fn_decl(void* l0, void* l1) {
    void* l2 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l12 = NULL;
    size_t l3, l4;
    uint64_t l8;
    vader_box_t l9 = vader_box_null(), l10 = vader_box_null();
    vader_string_t l11 = 0;
    int64_t t0;
    vader_box_t* gc_roots[2] = { &l9, &l10 };
    void** gc_raw_roots[7] = { &l0, &l1, &l2, &l5, &l6, &l7, &l12 };
    vader_string_t* gc_atom_roots[1] = { &l11 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_toolchain_ast_FnDecl_t*) l1)->f_decorators;
    vader_resolver_walk_decorators(l0, l2);
    vader_resolver_push(((vader_struct_vader_resolver_ResolveState_t*) l0)->f_scope);
    l2 = ((vader_struct_toolchain_ast_FnDecl_t*) l1)->f_type_params;
    l3 = ((vader_array_t*) l2)->length;
    l4 = (size_t) 0;
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        l5 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        l6 = vader_resolver_declare_type_param(l0, l5);
        l7 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_idents;
        l8 = toolchain_span_Span_Hash_hash(((vader_struct_toolchain_ast_TypeParam_t*) l5)->f_span);
        std_collections_MutableMap_IndexSet_set_at__u64__Any(l7, l8, vader_ref_box(l6));
        t0 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t0;
    }
    l2 = ((vader_struct_toolchain_ast_FnDecl_t*) l1)->f_params;
    l3 = ((vader_array_t*) l2)->length;
    l4 = (size_t) 0;
    while ((l4 < l3)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
        l5 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
        l9 = ((vader_struct_toolchain_ast_FnParam_t*) l5)->f_ty;
        vader_resolver_walk_opt_expr(l0, l9);
        l10 = ((vader_struct_toolchain_ast_FnParam_t*) l5)->f_default_value;
        vader_resolver_walk_opt_expr(l0, l10);
        l11 = ((vader_struct_toolchain_ast_FnParam_t*) l5)->f_name;
        l6 = ((vader_struct_toolchain_ast_FnParam_t*) l5)->f_span;
        l7 = vader_resolver_bind_local_checked(l0, (uint8_t) 8, l11, l6);
        l12 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_idents;
        l8 = toolchain_span_Span_Hash_hash(((vader_struct_toolchain_ast_FnParam_t*) l5)->f_span);
        std_collections_MutableMap_IndexSet_set_at__u64__Any(l12, l8, vader_ref_box(l7));
        vader_resolver_mark_param_borrow(l0, l5, l7);
        t0 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t0;
    }
    l9 = ((vader_struct_toolchain_ast_FnDecl_t*) l1)->f_return_type;
    vader_resolver_walk_opt_expr(l0, l9);
    l9 = ((vader_struct_toolchain_ast_FnDecl_t*) l1)->f_body;
    l10 = l9;
    if (l9.tag == 0u) {
        vader_resolver_pop(((vader_struct_vader_resolver_ResolveState_t*) l0)->f_scope);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (!(l9.tag == 447u)) {
        vader_unreachable("non-exhaustive match (T3013 should have caught this)");
    }
    l2 = l10.payload.obj;
    vader_resolver_walk_body(l0, l2);
    vader_resolver_pop(((vader_struct_vader_resolver_ResolveState_t*) l0)->f_scope);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_resolver_walk_for(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l3 = vader_box_null(), l4 = vader_box_null();
    vader_string_t l5 = 0;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l11 = NULL;
    uint64_t l8;
    size_t l9, l12;
    int32_t l10;
    void* t0 = NULL;
    int32_t t1;
    size_t t2;
    int64_t t3;
    vader_box_t* gc_roots[3] = { &l2, &l3, &l4 };
    void** gc_raw_roots[6] = { &l0, &l1, &l6, &l7, &l11, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l5 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_toolchain_ast_ForStmt_t*) l1)->f_form;
    l3 = l2;
    if (!(l2.tag == 485u)) {
        if (l2.tag == 527u) {
            t0 = l3.payload.obj;
            l4 = ((vader_struct_toolchain_ast_WhileFor_t*) t0)->f_cond;
            vader_resolver_walk_expr(l0, l4);
        } else {
            if (!(l2.tag == 483u)) {
                vader_unreachable("non-exhaustive match (T3013 should have caught this)");
            }
            t0 = l3.payload.obj;
            l2 = ((vader_struct_toolchain_ast_InFor_t*) t0)->f_iter;
            vader_resolver_walk_expr(l0, l2);
        }
    }
    vader_resolver_push(((vader_struct_vader_resolver_ResolveState_t*) l0)->f_scope);
    l2 = ((vader_struct_toolchain_ast_ForStmt_t*) l1)->f_form;
    l3 = l2;
    if (l2.tag == 483u) {
        t0 = l3.payload.obj;
        l3 = ((vader_struct_toolchain_ast_InFor_t*) t0)->f_loop_var;
        l4 = l3;
        if (l3.tag == 497u) {
            t0 = l4.payload.obj;
            l5 = ((vader_struct_toolchain_ast_NamedVar_t*) t0)->f_name;
            t0 = l4.payload.obj;
            l6 = ((vader_struct_toolchain_ast_NamedVar_t*) t0)->f_span;
            l6 = vader_resolver_bind_local_checked(l0, (uint8_t) 10, l5, l6);
            l7 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_idents;
            t0 = l4.payload.obj;
            l8 = toolchain_span_Span_Hash_hash(((vader_struct_toolchain_ast_NamedVar_t*) t0)->f_span);
            std_collections_MutableMap_IndexSet_set_at__u64__Any(l7, l8, vader_ref_box(l6));
        } else if (l3.tag == 462u) {
            vader_array_t* _a0_arr = vader_array_new(126u, 0u, 13u, 1024u);
            l6 = (void*) _a0_arr;
            t0 = l4.payload.obj;
            l4 = ((vader_struct_toolchain_ast_DestructureVar_t*) t0)->f_pattern;
            vader_resolver_bind_let_binding(l0, l4, l6);
        } else if (!(l3.tag == 463u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
    } else if (!((l2.tag == 485u || l2.tag == 527u))) {
        vader_unreachable("non-exhaustive match (T3013 should have caught this)");
    }
    l9 = ((vader_array_t*) ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_rebind_log)->length;
    t1 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_loop_depth;
    l10 = vader_chk_add(i32, t1, INT32_C(1));
    ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_loop_depth = l10;
    l6 = ((vader_struct_toolchain_ast_ForStmt_t*) l1)->f_body;
    vader_resolver_walk_block(l0, l6);
    t1 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_loop_depth;
    l10 = vader_chk_sub(i32, t1, INT32_C(1));
    ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_loop_depth = l10;
    vader_resolver_pop(((vader_struct_vader_resolver_ResolveState_t*) l0)->f_scope);
    t2 = ((vader_array_t*) ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_rebind_log)->length;
    if ((t2 > l9)) {
        vader_array_t* _a1_arr = vader_array_new(14u, 0u, 7u, 247u);
        l6 = (void*) _a1_arr;
        vader_array_t* _a2_arr = vader_array_new(11u, 0u, 12u, 242u);
        l7 = (void*) _a2_arr;
        vader_array_t* _a3_arr = vader_array_new(14u, 0u, 7u, 247u);
        l11 = (void*) _a3_arr;
        vader_struct_std_collections_MutableMap__i32__bool_t* _a4_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
        vader_obj_header_init(_a4_obj, 329u);
        _a4_obj->f_ekeys = l6;
        _a4_obj->f_evals = l7;
        _a4_obj->f_index = l11;
        _a4_obj->f_mask = (size_t) 0;
        _a4_obj->f_size = (size_t) 0;
        _a4_obj->f_tombs = (size_t) 0;
        t0 = (void*) _a4_obj;
        vader_struct_std_collections_MutableSet__i32_t* _a5_obj = (vader_struct_std_collections_MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i32_t));
        vader_obj_header_init(_a5_obj, 427u);
        _a5_obj->f_inner = t0;
        l6 = (void*) _a5_obj;
        l12 = ((vader_array_t*) ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_rebind_log)->length;
        while ((l9 < l12)) {
            vader_array_t* _a6_slotarr = ((vader_array_t*) ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_rebind_log);
            VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l9)
            l10 = ((int32_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l9];
            std_collections_add__i32(l6, l10);
            t3 = (l9 + INT64_C(1));
            l9 = (size_t) (int64_t) t3;
        }
        l7 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_loop_rebinds;
        l8 = toolchain_span_Span_Hash_hash(((vader_struct_toolchain_ast_ForStmt_t*) l1)->f_span);
        std_collections_MutableMap_IndexSet_set_at__u64__Any(l7, l8, vader_ref_box(l6));
    }
    t1 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_loop_depth;
    if (t1 == INT32_C(0)) {
        vader_array_clear((vader_array_t*) ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_rebind_log);
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_resolver_walk_if(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l4 = vader_box_null();
    void* l3 = NULL;
    void* t0 = NULL;
    vader_box_t* gc_roots[2] = { &l2, &l4 };
    void** gc_raw_roots[4] = { &l0, &l1, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_resolver_push(((vader_struct_vader_resolver_ResolveState_t*) l0)->f_scope);
    l2 = ((vader_struct_toolchain_ast_IfExpr_t*) l1)->f_cond;
    vader_resolver_bind_cond_is_as(l0, l2, false);
    l3 = ((vader_struct_toolchain_ast_IfExpr_t*) l1)->f_then_block;
    vader_resolver_walk_block(l0, l3);
    vader_resolver_pop(((vader_struct_vader_resolver_ResolveState_t*) l0)->f_scope);
    l2 = ((vader_struct_toolchain_ast_IfExpr_t*) l1)->f_else_branch;
    l4 = l2;
    if (l2.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 478u) {
        t0 = l4.payload.obj;
        l3 = ((vader_struct_toolchain_ast_IfElseIf_t*) t0)->f_branch;
        vader_resolver_walk_if(l0, l3);
    } else {
        if (!(l2.tag == 477u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        t0 = l4.payload.obj;
        l3 = ((vader_struct_toolchain_ast_IfElseBlock_t*) t0)->f_block;
        vader_resolver_walk_block(l0, l3);
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_resolver_walk_impl_decl(void* l0, void* l1) {
    void* l2 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l8 = NULL;
    size_t l3, l4;
    uint64_t l7;
    vader_box_t l9 = vader_box_null();
    vader_string_t l10 = 0;
    int64_t t0;
    bool t1;
    vader_box_t* gc_roots[1] = { &l9 };
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l5, &l6, &l8 };
    vader_string_t* gc_atom_roots[1] = { &l10 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_toolchain_ast_ImplDecl_t*) l1)->f_decorators;
    vader_resolver_walk_decorators(l0, l2);
    vader_resolver_push(((vader_struct_vader_resolver_ResolveState_t*) l0)->f_scope);
    l2 = ((vader_struct_toolchain_ast_ImplDecl_t*) l1)->f_type_params;
    l3 = ((vader_array_t*) l2)->length;
    l4 = (size_t) 0;
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        l5 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        l6 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_idents;
        l7 = toolchain_span_Span_Hash_hash(((vader_struct_toolchain_ast_TypeParam_t*) l5)->f_span);
        l8 = vader_resolver_declare_type_param(l0, l5);
        std_collections_MutableMap_IndexSet_set_at__u64__Any(l6, l7, vader_ref_box(l8));
        t0 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t0;
    }
    l9 = ((vader_struct_toolchain_ast_ImplDecl_t*) l1)->f_for_type;
    vader_resolver_auto_bind_for_type_params(l0, l9);
    l9 = ((vader_struct_toolchain_ast_ImplDecl_t*) l1)->f_for_type;
    vader_resolver_walk_expr(l0, l9);
    l2 = ((vader_struct_toolchain_ast_ImplDecl_t*) l1)->f_trait_args;
    l3 = ((vader_array_t*) l2)->length;
    l4 = (size_t) 0;
    while ((l4 < l3)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
        l9 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
        vader_resolver_walk_expr(l0, l9);
        t0 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t0;
    }
    l2 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_scope;
    l10 = ((vader_struct_toolchain_ast_ImplDecl_t*) l1)->f_trait_name;
    l9 = vader_resolver_lookup(l2, l10);
    if (!(l9.tag == 0u)) {
        l2 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_idents;
        l7 = toolchain_span_Span_Hash_hash(((vader_struct_toolchain_ast_ImplDecl_t*) l1)->f_trait_name_span);
        l5 = l9.payload.obj;
        std_collections_MutableMap_IndexSet_set_at__u64__Any(l2, l7, vader_ref_box(l5));
        l10 = ((vader_struct_toolchain_ast_ImplDecl_t*) l1)->f_trait_name;
        l2 = ((vader_struct_toolchain_ast_ImplDecl_t*) l1)->f_trait_name_span;
        l5 = l9.payload.obj;
        vader_resolver_check_wildcard_ambiguity(l0, l10, l2, l5);
    }
    l2 = ((vader_struct_toolchain_ast_ImplDecl_t*) l1)->f_members;
    l3 = ((vader_array_t*) l2)->length;
    l4 = (size_t) 0;
    while ((l4 < l3)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        l5 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
        t1 = ((vader_struct_toolchain_ast_FnDecl_t*) l5)->f_materialized;
        if (t1) {
            t1 = ((vader_struct_toolchain_ast_FnDecl_t*) l5)->f_sam_synthetic;
            if (t1) {
                t0 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                continue;
            }
        }
        vader_resolver_walk_fn_decl(l0, l5);
        t0 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t0;
    }
    vader_resolver_pop(((vader_struct_vader_resolver_ResolveState_t*) l0)->f_scope);
    { vader_gc_top = gc_frame.prev; return; }
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
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 6u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    std_collections_MutableMap_IndexSet_set_at__string__i32(l3, l0, INT32_C(1));
    l5 = std_collections_MutableMap_Index_at__string__Any(l1, l0);
    if (l5.tag == 1009u) {
        t0 = l5.payload.obj;
        l6 = ((vader_struct_vader_resolver_CollectedModule_t*) ((vader_struct_vader_resolver_LoadedModule_t*) t0)->f_collected)->f_import_paths;
        l7 = ((vader_array_t*) l6)->length;
        l8 = (size_t) 0;
        while ((l8 < l7)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l6);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l8)
            t1 = vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l8];
            l9 = t1.payload.s;
            l10 = std_collections_MutableMap_Index_at__string__Any(l2, l9);
            if (l10.tag == 1002u) {
                t0 = l10.payload.obj;
                l11 = ((vader_struct_vader_resolver_DiscoveredModule_t*) t0)->f_folder;
                l12 = std_collections_MutableMap_Index_at__string__i32(l3, l11);
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
                        l15 = concat_5(866u, l14, 932u, l9, 1083u);
                        l16 = vader_diagnostics_resolver_error((uint8_t) 4, l13, l15);
                        vader_array_push((vader_array_t*) l4, vader_ref_box(l16));
                    }
                }
            }
            t4 = (l8 + INT64_C(1));
            l8 = (size_t) (int64_t) t4;
        }
    }
    std_collections_MutableMap_IndexSet_set_at__string__i32(l3, l0, INT32_C(2));
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_resolver_walk_lambda(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l8 = vader_box_null();
    int32_t l3;
    void* l4 = NULL;
    void* l7 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    void* l12 = NULL;
    size_t l5, l6;
    vader_string_t l9 = 0;
    uint64_t l13;
    vader_box_t t0 = vader_box_null();
    int64_t t1;
    vader_box_t* gc_roots[3] = { &l2, &l8, &t0 };
    void** gc_raw_roots[7] = { &l0, &l1, &l4, &l7, &l10, &l11, &l12 };
    vader_string_t* gc_atom_roots[1] = { &l9 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_lambda_frame;
    l3 = vader_resolver_frame_count(((vader_struct_vader_resolver_ResolveState_t*) l0)->f_scope);
    t0 = vader_box_i32(247u, l3);
    ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_lambda_frame = t0;
    VADER_WRITE_BARRIER((vader_struct_vader_resolver_ResolveState_t*) l0);
    vader_resolver_push(((vader_struct_vader_resolver_ResolveState_t*) l0)->f_scope);
    l4 = ((vader_struct_toolchain_ast_LambdaExpr_t*) l1)->f_params;
    l5 = ((vader_array_t*) l4)->length;
    l6 = (size_t) 0;
    while ((l6 < l5)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l6)
        l7 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l6);
        l8 = ((vader_struct_toolchain_ast_FnParam_t*) l7)->f_ty;
        vader_resolver_walk_opt_expr(l0, l8);
        l9 = ((vader_struct_toolchain_ast_FnParam_t*) l7)->f_name;
        l10 = ((vader_struct_toolchain_ast_FnParam_t*) l7)->f_span;
        l11 = vader_resolver_bind_local_checked(l0, (uint8_t) 8, l9, l10);
        vader_resolver_mark_param_borrow(l0, l7, l11);
        l12 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_idents;
        l13 = toolchain_span_Span_Hash_hash(((vader_struct_toolchain_ast_FnParam_t*) l7)->f_span);
        std_collections_MutableMap_IndexSet_set_at__u64__Any(l12, l13, vader_ref_box(l11));
        t1 = (l6 + INT64_C(1));
        l6 = (size_t) (int64_t) t1;
    }
    l8 = ((vader_struct_toolchain_ast_LambdaExpr_t*) l1)->f_return_type;
    vader_resolver_walk_opt_expr(l0, l8);
    l4 = ((vader_struct_toolchain_ast_LambdaExpr_t*) l1)->f_body;
    vader_resolver_walk_block(l0, l4);
    vader_resolver_pop(((vader_struct_vader_resolver_ResolveState_t*) l0)->f_scope);
    ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_lambda_frame = l2;
    VADER_WRITE_BARRIER((vader_struct_vader_resolver_ResolveState_t*) l0);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_resolver_walk_let(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null();
    void* l3 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l9 = NULL;
    size_t l4, l5;
    int32_t l8;
    bool t0;
    size_t t1;
    int64_t t2;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[6] = { &l0, &l1, &l3, &l6, &l7, &l9 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 6u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_toolchain_ast_LetStmt_t*) l1)->f_ty;
    vader_resolver_walk_opt_expr(l0, l2);
    l2 = ((vader_struct_toolchain_ast_LetStmt_t*) l1)->f_value;
    vader_resolver_walk_expr(l0, l2);
    vader_array_t* _a0_arr = vader_array_new(126u, 0u, 13u, 1024u);
    l3 = (void*) _a0_arr;
    l2 = ((vader_struct_toolchain_ast_LetStmt_t*) l1)->f_binding;
    vader_resolver_bind_let_binding(l0, l2, l3);
    t0 = ((vader_struct_toolchain_ast_LetStmt_t*) l1)->f_mutable;
    if (t0) {
        t1 = ((vader_array_t*) l3)->length;
        if ((t1 > INT64_C(0))) {
            l6 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_mutable_decls;
            l7 = vader_resolver_binding_span(((vader_struct_toolchain_ast_LetStmt_t*) l1)->f_binding);
            vader_struct_vader_resolver_MutableDecl_t* _a1_obj = (vader_struct_vader_resolver_MutableDecl_t*) vader_gc_alloc(sizeof(vader_struct_vader_resolver_MutableDecl_t));
            vader_obj_header_init(_a1_obj, 1013u);
            _a1_obj->f_syms = l3;
            _a1_obj->f_span = l7;
            l9 = (void*) _a1_obj;
            vader_array_push((vader_array_t*) l6, vader_ref_box(l9));
        }
    } else {
        l4 = ((vader_array_t*) l3)->length;
        l5 = (size_t) 0;
        while ((l5 < l4)) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l5)
            l6 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l5);
            l7 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_immutable_locals;
            l8 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l6)->f_id;
            std_collections_MutableMap_IndexSet_set_at__i32__bool(l7, l8, true);
            t2 = (l5 + INT64_C(1));
            l5 = (size_t) (int64_t) t2;
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_resolver_walk_match(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l9 = vader_box_null(), l10 = vader_box_null();
    vader_string_t l3 = 0;
    void* l4 = NULL;
    void* l5 = NULL;
    uint64_t l6;
    size_t l7, l8;
    void* t0 = NULL;
    int64_t t1;
    vader_box_t* gc_roots[3] = { &l2, &l9, &l10 };
    void** gc_raw_roots[5] = { &l0, &l1, &l4, &l5, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_toolchain_ast_MatchExpr_t*) l1)->f_scrutinee;
    vader_resolver_walk_expr(l0, l2);
    vader_resolver_push(((vader_struct_vader_resolver_ResolveState_t*) l0)->f_scope);
    l2 = ((vader_struct_toolchain_ast_MatchExpr_t*) l1)->f_bind_as;
    if (!(l2.tag == 0u)) {
        t0 = l2.payload.obj;
        l3 = ((vader_struct_toolchain_ast_AsBinding_t*) t0)->f_name;
        t0 = l2.payload.obj;
        l4 = ((vader_struct_toolchain_ast_AsBinding_t*) t0)->f_span;
        l4 = vader_resolver_mint_local(l0, (uint8_t) 11, l3, l4);
        l5 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_scope;
        t0 = l2.payload.obj;
        l3 = ((vader_struct_toolchain_ast_AsBinding_t*) t0)->f_name;
        vader_resolver_bind(l5, l3, l4);
        l5 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_idents;
        t0 = l2.payload.obj;
        l6 = toolchain_span_Span_Hash_hash(((vader_struct_toolchain_ast_AsBinding_t*) t0)->f_span);
        std_collections_MutableMap_IndexSet_set_at__u64__Any(l5, l6, vader_ref_box(l4));
    }
    l4 = ((vader_struct_toolchain_ast_MatchExpr_t*) l1)->f_arms;
    l7 = ((vader_array_t*) l4)->length;
    l8 = (size_t) 0;
    while ((l8 < l7)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l8)
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
    }
    vader_resolver_pop(((vader_struct_vader_resolver_ResolveState_t*) l0)->f_scope);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_resolver_walk_opt_expr(void* l0, vader_box_t l1) {
    vader_box_t l2 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l1, &l2 };
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l1.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l2 = l1;
    vader_resolver_walk_expr(l0, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_resolver_walk_stmt(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    vader_box_t l3 = vader_box_null();
    size_t l4, l5;
    void* t0 = NULL;
    int64_t t1;
    vader_box_t* gc_roots[2] = { &l1, &l3 };
    void** gc_raw_roots[3] = { &l0, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l1.tag == 490u) {
        l2 = l1.payload.obj;
        vader_resolver_walk_let(l0, l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 444u) {
        t0 = l1.payload.obj;
        l3 = ((vader_struct_toolchain_ast_AssignStmt_t*) t0)->f_target;
        vader_resolver_walk_expr(l0, l3);
        t0 = l1.payload.obj;
        l3 = ((vader_struct_toolchain_ast_AssignStmt_t*) t0)->f_value;
        vader_resolver_walk_expr(l0, l3);
        t0 = l1.payload.obj;
        l3 = ((vader_struct_toolchain_ast_AssignStmt_t*) t0)->f_target;
        vader_resolver_note_rebind(l0, l3);
    } else if (l1.tag == 460u) {
        t0 = l1.payload.obj;
        l2 = toolchain_ast_assign_places(t0);
        l4 = ((vader_array_t*) l2)->length;
        l5 = (size_t) 0;
        while ((l5 < l4)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
            l3 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
            vader_resolver_walk_expr(l0, l3);
            vader_resolver_note_rebind(l0, l3);
            t1 = (l5 + INT64_C(1));
            l5 = (size_t) (int64_t) t1;
        }
        t0 = l1.payload.obj;
        l3 = ((vader_struct_toolchain_ast_DestructureAssignStmt_t*) t0)->f_value;
        vader_resolver_walk_expr(l0, l3);
    } else if (l1.tag == 468u) {
        t0 = l1.payload.obj;
        l3 = ((vader_struct_toolchain_ast_ExprStmt_t*) t0)->f_expr;
        vader_resolver_walk_expr(l0, l3);
    } else if (l1.tag == 509u) {
        t0 = l1.payload.obj;
        l3 = ((vader_struct_toolchain_ast_ReturnStmt_t*) t0)->f_value;
        vader_resolver_walk_opt_expr(l0, l3);
    } else if (l1.tag == 532u) {
        t0 = l1.payload.obj;
        l3 = ((vader_struct_toolchain_ast_YieldStmt_t*) t0)->f_value;
        vader_resolver_walk_expr(l0, l3);
    } else if (l1.tag == 474u) {
        l2 = l1.payload.obj;
        vader_resolver_walk_for(l0, l2);
    } else if (!(l1.tag == 449u)) {
        if (!(l1.tag == 455u)) {
            if (!(l1.tag == 458u)) {
                vader_unreachable("non-exhaustive match (T3013 should have caught this)");
            }
            l2 = l1.payload.obj;
            vader_resolver_walk_defer(l0, l2);
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_resolver_walk_struct_decl(void* l0, void* l1) {
    void* l2 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    size_t l3, l4;
    uint64_t l8;
    vader_box_t l9 = vader_box_null(), l10 = vader_box_null();
    int64_t t0;
    vader_box_t* gc_roots[2] = { &l9, &l10 };
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l5, &l6, &l7 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 6u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_toolchain_ast_StructDecl_t*) l1)->f_decorators;
    vader_resolver_walk_decorators(l0, l2);
    vader_resolver_push(((vader_struct_vader_resolver_ResolveState_t*) l0)->f_scope);
    l2 = ((vader_struct_toolchain_ast_StructDecl_t*) l1)->f_type_params;
    l3 = ((vader_array_t*) l2)->length;
    l4 = (size_t) 0;
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        l5 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        l6 = vader_resolver_declare_type_param(l0, l5);
        l7 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_idents;
        l8 = toolchain_span_Span_Hash_hash(((vader_struct_toolchain_ast_TypeParam_t*) l5)->f_span);
        std_collections_MutableMap_IndexSet_set_at__u64__Any(l7, l8, vader_ref_box(l6));
        t0 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t0;
    }
    l2 = ((vader_struct_toolchain_ast_StructDecl_t*) l1)->f_fields;
    l3 = ((vader_array_t*) l2)->length;
    l4 = (size_t) 0;
    while ((l4 < l3)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
        l5 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
        l9 = ((vader_struct_toolchain_ast_StructField_t*) l5)->f_ty;
        vader_resolver_walk_expr(l0, l9);
        l10 = ((vader_struct_toolchain_ast_StructField_t*) l5)->f_default_v;
        vader_resolver_walk_opt_expr(l0, l10);
        t0 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t0;
    }
    vader_resolver_pop(((vader_struct_vader_resolver_ResolveState_t*) l0)->f_scope);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_resolver_walk_struct_lit(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null();
    void* l3 = NULL;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[3] = { &l0, &l1, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_toolchain_ast_StructLitExpr_t*) l1)->f_type_name;
    vader_resolver_walk_expr(l0, l2);
    l3 = ((vader_struct_toolchain_ast_StructLitExpr_t*) l1)->f_items;
    vader_resolver_walk_struct_lit_items(l0, l3);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_resolver_walk_struct_lit_items(void* l0, void* l1) {
    void* l2 = NULL;
    size_t l3, l4;
    vader_box_t l5 = vader_box_null(), l6 = vader_box_null(), l7 = vader_box_null();
    void* t0 = NULL;
    int64_t t1;
    vader_box_t* gc_roots[3] = { &l5, &l6, &l7 };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = l1;
    l3 = ((vader_array_t*) l2)->length;
    l4 = (size_t) 0;
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        l5 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        if (l5.tag == 518u) {
            t0 = l5.payload.obj;
            l6 = ((vader_struct_toolchain_ast_StructLitField_t*) t0)->f_value;
            vader_resolver_walk_expr(l0, l6);
        } else {
            t0 = l5.payload.obj;
            l7 = ((vader_struct_toolchain_ast_StructLitSpread_t*) t0)->f_expr;
            vader_resolver_walk_expr(l0, l7);
        }
        t1 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t1;
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_resolver_walk_trait_decl(void* l0, void* l1) {
    void* l2 = NULL;
    void* l5 = NULL;
    size_t l3, l4;
    vader_box_t l6 = vader_box_null();
    vader_string_t l7 = 0;
    int64_t t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &l6 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l5, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l7 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_toolchain_ast_TraitDecl_t*) l1)->f_decorators;
    vader_resolver_walk_decorators(l0, l2);
    vader_resolver_push(((vader_struct_vader_resolver_ResolveState_t*) l0)->f_scope);
    l2 = ((vader_struct_toolchain_ast_TraitDecl_t*) l1)->f_type_params;
    l3 = ((vader_array_t*) l2)->length;
    l4 = (size_t) 0;
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        l5 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        vader_resolver_declare_type_param(l0, l5);
        t0 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t0;
    }
    l6 = ((vader_struct_toolchain_ast_TraitDecl_t*) l1)->f_requires;
    vader_resolver_walk_opt_expr(l0, l6);
    l6 = vader_resolver_union_in_bound(((vader_struct_toolchain_ast_TraitDecl_t*) l1)->f_requires);
    if (!(l6.tag == 0u)) {
        l7 = ((vader_struct_toolchain_ast_TraitDecl_t*) l1)->f_name;
        l7 = concat_3(866u, l7, 1042u);
        l2 = ((vader_struct_vader_resolver_ResolveState_t*) l0)->f_diags;
        t1 = l6.payload.obj;
        l5 = ((vader_struct_toolchain_ast_BinaryExpr_t*) t1)->f_span;
        l5 = vader_diagnostics_resolver_error((uint8_t) 41, l5, l7);
        vader_array_push((vader_array_t*) l2, vader_ref_box(l5));
    }
    l2 = ((vader_struct_toolchain_ast_TraitDecl_t*) l1)->f_members;
    l3 = ((vader_array_t*) l2)->length;
    l4 = (size_t) 0;
    while ((l4 < l3)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
        l5 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
        vader_resolver_walk_fn_decl(l0, l5);
        t0 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t0;
    }
    vader_resolver_pop(((vader_struct_vader_resolver_ResolveState_t*) l0)->f_scope);
    { vader_gc_top = gc_frame.prev; return; }
}

static void* vader_resolver_wildcard_ambiguities(void* l0, void* l1, void* l2, void* l3) {
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    void* l17 = NULL;
    void* l22 = NULL;
    void* l24 = NULL;
    void* l28 = NULL;
    size_t l7, l8, l15, l16, l25, l26;
    vader_string_t l9 = 0;
    vader_string_t l18 = 0;
    vader_string_t l19 = 0;
    vader_string_t l21 = 0;
    vader_string_t l27 = 0;
    vader_box_t l10 = vader_box_null(), l11 = vader_box_null(), l20 = vader_box_null();
    bool l23;
    size_t t0;
    vader_box_t t1 = vader_box_null();
    int64_t t2;
    vader_string_t t3 = 0;
    bool t4;
    void* t5 = NULL;
    vader_box_t* gc_roots[4] = { &l10, &l11, &l20, &t1 };
    void** gc_raw_roots[15] = {
        &l0, &l1, &l2, &l3, &l4, &l5, &l6, &l12, &l13, &l14, &l17, &l22, &l24, &l28, &t5,
    };
    vader_string_t* gc_atom_roots[6] = { &l9, &l18, &l19, &l21, &l27, &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 15u, gc_roots, gc_raw_roots, 0u, NULL, 6u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(13u, 0u, 0u, 244u);
    l4 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(21u, 0u, 0u, 255u);
    l5 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(14u, 0u, 7u, 247u);
    l6 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__string__Any___t* _a3_obj = (vader_struct_std_collections_MutableMap__string__Any___t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__Any___t));
    vader_obj_header_init(_a3_obj, 338u);
    _a3_obj->f_ekeys = l4;
    _a3_obj->f_evals = l5;
    _a3_obj->f_index = l6;
    _a3_obj->f_mask = (size_t) 0;
    _a3_obj->f_size = (size_t) 0;
    _a3_obj->f_tombs = (size_t) 0;
    l4 = (void*) _a3_obj;
    t0 = ((vader_array_t*) l1)->length;
    if ((t0 < INT64_C(2))) {
        { void* __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l5 = l1;
    l7 = ((vader_array_t*) l5)->length;
    l8 = (size_t) 0;
    while ((l8 < l7)) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l8)
        t1 = vader_array_box_slots(_a4_slotarr->buf)[_a4_slotarr->offset + (size_t) l8];
        l9 = t1.payload.s;
        l10 = std_collections_MutableMap_Index_at__string__Any(l0, l9);
        if (l10.tag == 0u) {
            t2 = (l8 + INT64_C(1));
            l8 = (size_t) (int64_t) t2;
            continue;
        }
        l6 = l10.payload.obj;
        l11 = std_collections_MutableMap_Index_at__string__Any(l2, l9);
        l12 = ((vader_struct_vader_resolver_CollectedModule_t*) ((vader_struct_vader_resolver_LoadedModule_t*) l6)->f_collected)->f_symbols;
        l13 = ((vader_struct_std_collections_MutableMap__string__Symbol_t*) l12)->f_ekeys;
        l14 = ((vader_struct_std_collections_MutableMap__string__Symbol_t*) l12)->f_evals;
        l15 = ((vader_struct_std_collections_MutableMap__string__Symbol_t*) l12)->f_size;
        l16 = (size_t) 0;
        while (!((l16 >= l15))) {
            vader_array_t* _a5_slotarr = ((vader_array_t*) l13);
            VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l16)
            t1 = vader_array_box_slots(_a5_slotarr->buf)[_a5_slotarr->offset + (size_t) l16];
            t3 = t1.payload.s;
            vader_array_t* _a6_slotarr = ((vader_array_t*) l14);
            VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l16)
            l17 = vader_array_ref_load_obj(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l16);
            t2 = (l16 + INT64_C(1));
            l16 = (size_t) (int64_t) t2;
            t4 = vader_resolver_wildcard_exposes(l17, l11);
            if (!(t4)) {
                continue;
            }
            l18 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l17)->f_name;
            t1 = std_collections_MutableMap_Index_at__string__Any(l3, l18);
            if (!(t1.tag == 0u)) {
                continue;
            }
            l19 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l17)->f_name;
            l20 = std_collections_MutableMap_Index_at__string__Any(l4, l19);
            if (l20.tag == 0u) {
                l21 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l17)->f_name;
                vader_array_t* _a7_arr = vader_array_new(13u, 1u, 0u, 244u);
                vader_array_box_slots(_a7_arr->buf)[_a7_arr->offset + 0u] = vader_box_string(244u, l9);
                l22 = (void*) _a7_arr;
                std_collections_MutableMap_IndexSet_set_at__string__Any(l4, l21, vader_ref_box(l22));
                continue;
            }
            l23 = false;
            l24 = l20.payload.obj;
            l25 = ((vader_array_t*) l24)->length;
            l26 = (size_t) 0;
            while ((l26 < l25)) {
                vader_array_t* _a8_slotarr = ((vader_array_t*) l24);
                VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
                t1 = vader_array_box_slots(_a8_slotarr->buf)[_a8_slotarr->offset + (size_t) l26];
                t3 = t1.payload.s;
                if (t3 == l9) {
                    l23 = true;
                }
                t2 = (l26 + INT64_C(1));
                l26 = (size_t) (int64_t) t2;
            }
            if (!(l23)) {
                t5 = l20.payload.obj;
                vader_array_push((vader_array_t*) t5, vader_box_string(244u, l9));
                l27 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l17)->f_name;
                l28 = l20.payload.obj;
                std_collections_MutableMap_IndexSet_set_at__string__Any(l4, l27, vader_ref_box(l28));
            }
        }
        t2 = (l8 + INT64_C(1));
        l8 = (size_t) (int64_t) t2;
    }
    vader_array_t* _a9_arr = vader_array_new(13u, 0u, 0u, 244u);
    l5 = (void*) _a9_arr;
    vader_array_t* _a10_arr = vader_array_new(21u, 0u, 0u, 255u);
    l6 = (void*) _a10_arr;
    vader_array_t* _a11_arr = vader_array_new(14u, 0u, 7u, 247u);
    l12 = (void*) _a11_arr;
    vader_struct_std_collections_MutableMap__string__Any___t* _a12_obj = (vader_struct_std_collections_MutableMap__string__Any___t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__Any___t));
    vader_obj_header_init(_a12_obj, 338u);
    _a12_obj->f_ekeys = l5;
    _a12_obj->f_evals = l6;
    _a12_obj->f_index = l12;
    _a12_obj->f_mask = (size_t) 0;
    _a12_obj->f_size = (size_t) 0;
    _a12_obj->f_tombs = (size_t) 0;
    l5 = (void*) _a12_obj;
    l6 = ((vader_struct_std_collections_MutableMap__string__string___t*) l4)->f_ekeys;
    l12 = ((vader_struct_std_collections_MutableMap__string__string___t*) l4)->f_evals;
    l7 = ((vader_struct_std_collections_MutableMap__string__string___t*) l4)->f_size;
    l8 = (size_t) 0;
    while (!((l8 >= l7))) {
        vader_array_t* _a13_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a13_slotarr, l8)
        t1 = vader_array_box_slots(_a13_slotarr->buf)[_a13_slotarr->offset + (size_t) l8];
        l9 = t1.payload.s;
        vader_array_t* _a14_slotarr = ((vader_array_t*) l12);
        VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a14_slotarr, l8)
        l4 = vader_array_ref_load_obj(_a14_slotarr->buf, _a14_slotarr->offset + (size_t) l8);
        l18 = l9;
        l13 = l4;
        t2 = (l8 + INT64_C(1));
        l8 = (size_t) (int64_t) t2;
        t0 = ((vader_array_t*) l13)->length;
        if (!((t0 >= INT64_C(2)))) {
            continue;
        }
        std_collections_MutableMap_IndexSet_set_at__string__Any(l5, l18, vader_ref_box(l13));
    }
    { void* __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_resolver_wildcard_exposable(uint8_t l0) {
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
        return true;
    }
    return l0 == INT32_C(6);
}

static bool vader_resolver_wildcard_exposes(void* l0, vader_box_t l1) {
    vader_string_t l2;
    bool t0;
    void* t1;
    t0 = vader_resolver_wildcard_exposable(((vader_struct_vader_resolver_symbol_Symbol_t*) l0)->f_kind);
    if (t0) {
        if (((vader_struct_vader_resolver_symbol_Symbol_t*) l0)->f_visibility != INT32_C(0)) {
            return false;
        }
        if (!(l1.tag == 0u)) {
            l2 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l0)->f_name;
            t1 = l1.payload.obj;
            t0 = std_core____Contains_contains__string(t1, l2);
            return !(t0);
        }
        return true;
    }
    return false;
}

void* vader_resolver_wire_imports(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    size_t l6, l7;
    vader_string_t l8 = 0;
    vader_string_t l9 = 0;
    vader_box_t t0 = vader_box_null();
    vader_string_t t1 = 0;
    int64_t t2;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l3, &l4, &l5 };
    vader_string_t* gc_atom_roots[3] = { &l8, &l9, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = vader_resolver_new_import_target_table();
    vader_array_t* _a0_arr = vader_array_new(13u, 0u, 0u, 244u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(13u, 0u, 0u, 244u);
    l3 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(14u, 0u, 7u, 247u);
    l4 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__string__string_t* _a3_obj = (vader_struct_std_collections_MutableMap__string__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__string_t));
    vader_obj_header_init(_a3_obj, 388u);
    _a3_obj->f_ekeys = l2;
    _a3_obj->f_evals = l3;
    _a3_obj->f_index = l4;
    _a3_obj->f_mask = (size_t) 0;
    _a3_obj->f_size = (size_t) 0;
    _a3_obj->f_tombs = (size_t) 0;
    l2 = (void*) _a3_obj;
    l3 = ((vader_struct_vader_resolver_LoadedProject_t*) l0)->f_modules;
    l4 = ((vader_struct_std_collections_MutableMap__string__LoadedModule_t*) l3)->f_ekeys;
    l5 = ((vader_struct_std_collections_MutableMap__string__LoadedModule_t*) l3)->f_evals;
    l6 = ((vader_struct_std_collections_MutableMap__string__LoadedModule_t*) l3)->f_size;
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
        l8 = ((vader_struct_vader_resolver_Module_t*) ((vader_struct_vader_resolver_LoadedModule_t*) l3)->f_module)->f_module_name;
        l9 = ((vader_struct_vader_resolver_Module_t*) ((vader_struct_vader_resolver_LoadedModule_t*) l3)->f_module)->f_id;
        std_collections_MutableMap_IndexSet_set_at__string__string(l2, l8, l9);
    }
    l3 = ((vader_struct_vader_resolver_LoadedProject_t*) l0)->f_modules;
    l4 = ((vader_struct_std_collections_MutableMap__string__LoadedModule_t*) l3)->f_ekeys;
    l5 = ((vader_struct_std_collections_MutableMap__string__LoadedModule_t*) l3)->f_evals;
    l6 = ((vader_struct_std_collections_MutableMap__string__LoadedModule_t*) l3)->f_size;
    l7 = (size_t) 0;
    while (!((l7 >= l6))) {
        vader_array_t* _a6_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l7)
        t0 = vader_array_box_slots(_a6_slotarr->buf)[_a6_slotarr->offset + (size_t) l7];
        t1 = t0.payload.s;
        vader_array_t* _a7_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l7)
        l3 = vader_array_ref_load_obj(_a7_slotarr->buf, _a7_slotarr->offset + (size_t) l7);
        t2 = (l7 + INT64_C(1));
        l7 = (size_t) (int64_t) t2;
        vader_resolver_wire_module(l3, l2, l0, l1);
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_resolver_wire_module(void* l0, void* l1, void* l2, void* l3) {
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l11 = NULL;
    void* l14 = NULL;
    void* l19 = NULL;
    void* l21 = NULL;
    void* l24 = NULL;
    void* l25 = NULL;
    void* l29 = NULL;
    void* l30 = NULL;
    void* l31 = NULL;
    void* l34 = NULL;
    void* l35 = NULL;
    void* l36 = NULL;
    void* l38 = NULL;
    size_t l7, l8;
    int32_t l9, l10;
    vader_string_t l12 = 0;
    vader_string_t l15 = 0;
    vader_string_t l20 = 0;
    vader_string_t l22 = 0;
    vader_string_t l26 = 0;
    vader_string_t l27 = 0;
    vader_string_t l28 = 0;
    vader_string_t l32 = 0;
    vader_string_t l33 = 0;
    vader_string_t l37 = 0;
    vader_box_t l13 = vader_box_null(), l16 = vader_box_null(), l17 = vader_box_null(), l18 = vader_box_null(), l23 = vader_box_null();
    int64_t t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[5] = { &l13, &l16, &l17, &l18, &l23 };
    void** gc_raw_roots[21] = {
        &l0, &l1, &l2, &l3, &l4, &l5, &l6, &l11, &l14, &l19, &l21, &l24, &l25, &l29, &l30, &l31,
        &l34, &l35, &l36, &l38, &t1,
    };
    vader_string_t* gc_atom_roots[10] = {
        &l12, &l15, &l20, &l22, &l26, &l27, &l28, &l32, &l33, &l37,
    };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 5u, 21u, gc_roots, gc_raw_roots, 0u, NULL, 10u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = ((vader_struct_vader_resolver_CollectedModule_t*) ((vader_struct_vader_resolver_LoadedModule_t*) l0)->f_collected)->f_imports;
    l5 = ((vader_struct_std_collections_MutableMap__i32__ImportInfo_t*) l4)->f_ekeys;
    l6 = ((vader_struct_std_collections_MutableMap__i32__ImportInfo_t*) l4)->f_evals;
    l7 = ((vader_struct_std_collections_MutableMap__i32__ImportInfo_t*) l4)->f_size;
    l8 = (size_t) 0;
    while (!((l8 >= l7))) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l8)
        l9 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l8];
        vader_array_t* _a1_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l8)
        l4 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l8);
        l10 = l9;
        l11 = l4;
        t0 = (l8 + INT64_C(1));
        l8 = (size_t) (int64_t) t0;
        l12 = ((vader_struct_vader_resolver_ImportInfo_t*) l11)->f_path;
        l13 = std_collections_MutableMap_Index_at__string__string(l1, l12);
        if (l13.tag == 0u) {
            std_collections_MutableMap_IndexSet_set_at__i32__bool(((vader_struct_vader_resolver_ImportTargetTable_t*) l3)->f_missing, l10, true);
            continue;
        }
        l14 = ((vader_struct_vader_resolver_LoadedProject_t*) l2)->f_modules;
        l15 = l13.payload.s;
        l16 = std_collections_MutableMap_Index_at__string__Any(l14, l15);
        if (l16.tag == 0u) {
            std_collections_MutableMap_IndexSet_set_at__i32__bool(((vader_struct_vader_resolver_ImportTargetTable_t*) l3)->f_missing, l10, true);
            continue;
        }
        l17 = ((vader_struct_vader_resolver_ImportInfo_t*) l11)->f_imported_name;
        l18 = l17;
        if (l17.tag == 0u) {
            l19 = ((vader_struct_vader_resolver_ImportTargetTable_t*) l3)->f_namespace_targets;
            l20 = l13.payload.s;
            std_collections_MutableMap_IndexSet_set_at__i32__string(l19, l10, l20);
            continue;
        }
        if (!(l17.tag == 244u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        t1 = l16.payload.obj;
        l21 = ((vader_struct_vader_resolver_CollectedModule_t*) ((vader_struct_vader_resolver_LoadedModule_t*) t1)->f_collected)->f_symbols;
        l22 = l18.payload.s;
        l23 = std_collections_MutableMap_Index_at__string__Any(l21, l22);
        if (l23.tag == 0u) {
            std_collections_MutableMap_IndexSet_set_at__i32__bool(((vader_struct_vader_resolver_ImportTargetTable_t*) l3)->f_missing, l10, true);
            l24 = ((vader_struct_vader_resolver_LoadedProject_t*) l2)->f_diags;
            l25 = ((vader_struct_vader_resolver_ImportInfo_t*) l11)->f_binding_span;
            l26 = l18.payload.s;
            l27 = ((vader_struct_vader_resolver_ImportInfo_t*) l11)->f_path;
            l28 = concat_5(866u, l26, 911u, l27, 866u);
            l29 = vader_diagnostics_resolver_error((uint8_t) 2, l25, l28);
            vader_array_push((vader_array_t*) l24, vader_ref_box(l29));
        } else {
            if (!(l23.tag == 1024u)) {
                vader_unreachable("non-exhaustive match (T3013 should have caught this)");
            }
            t1 = l23.payload.obj;
            if (((vader_struct_vader_resolver_symbol_Symbol_t*) t1)->f_visibility == INT32_C(1)) {
                std_collections_MutableMap_IndexSet_set_at__i32__bool(((vader_struct_vader_resolver_ImportTargetTable_t*) l3)->f_missing, l10, true);
                l30 = ((vader_struct_vader_resolver_LoadedProject_t*) l2)->f_diags;
                l31 = ((vader_struct_vader_resolver_ImportInfo_t*) l11)->f_binding_span;
                l32 = l18.payload.s;
                l33 = concat_3(866u, l32, 866u);
                l34 = vader_diagnostics_resolver_error((uint8_t) 7, l31, l33);
                vader_array_push((vader_array_t*) l30, vader_ref_box(l34));
            } else {
                l35 = ((vader_struct_vader_resolver_ImportTargetTable_t*) l3)->f_symbol_targets;
                l36 = l23.payload.obj;
                l37 = l13.payload.s;
                vader_struct_vader_resolver_SymbolTarget_t* _a2_obj = (vader_struct_vader_resolver_SymbolTarget_t*) vader_gc_alloc(sizeof(vader_struct_vader_resolver_SymbolTarget_t));
                vader_obj_header_init(_a2_obj, 1022u);
                _a2_obj->f_symbol = l36;
                _a2_obj->f_module_id = l37;
                l38 = (void*) _a2_obj;
                std_collections_MutableMap_IndexSet_set_at__i32__Any(l35, l10, vader_ref_box(l38));
            }
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void* vader_resolver_with_displayable_impls(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l6 = NULL;
    void* l8 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    size_t l3, l4, l10, l11;
    vader_box_t l5 = vader_box_null(), l7 = vader_box_null(), l9 = vader_box_null(), l15 = vader_box_null();
    vader_string_t l14 = 0;
    void* t0 = NULL;
    bool t1;
    int64_t t2;
    vader_box_t* gc_roots[4] = { &l5, &l7, &l9, &l15 };
    void** gc_raw_roots[8] = { &l0, &l1, &l2, &l6, &l8, &l12, &l13, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l14 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(180u, 0u, 13u, 1273u);
    l1 = (void*) _a0_arr;
    l2 = ((vader_struct_toolchain_ast_Program_t*) l0)->f_decls;
    l3 = ((vader_array_t*) l2)->length;
    l4 = (size_t) 0;
    while ((l4 < l3)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
        l5 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
        if (l5.tag == 465u) {
            t0 = l5.payload.obj;
            l8 = ((vader_struct_toolchain_ast_EnumDecl_t*) t0)->f_decorators;
            l9 = vader_box_obj(0u, NULL);
            l10 = ((vader_array_t*) l8)->length;
            l11 = (size_t) 0;
            {
                while ((l11 < l10)) {
                    vader_array_t* _a2_slotarr = ((vader_array_t*) l8);
                    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                    l12 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l11);
                    t1 = __lambda_vader_resolver_2(l12);
                    if (t1) {
                        l9 = vader_ref_box(l12);
                        goto end_30;
                    }
                    t2 = (l11 + INT64_C(1));
                    l11 = (size_t) (int64_t) t2;
                }
                l9 = vader_box_obj(0u, NULL);
            } end_30: ;
            l7 = l9;
            if (l7.tag == 0u) {
                t2 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t2;
                continue;
            }
            l6 = l7.payload.obj;
            l13 = l5.payload.obj;
            l14 = ((vader_struct_toolchain_ast_Program_t*) l0)->f_file;
            l15 = vader_resolver_displayable_impl(l13, l6, l14);
            vader_array_push((vader_array_t*) l1, l15);
        }
        t2 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t2;
    }
    t1 = std_iter_is_empty__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType(l1);
    if (!(t1)) {
        l2 = l0;
        l14 = ((vader_struct_toolchain_ast_Program_t*) l2)->f_file;
        t0 = ((vader_struct_toolchain_ast_Program_t*) l2)->f_span;
        l5 = vader_ref_box(t0);
        l3 = ((vader_struct_toolchain_ast_Program_t*) l2)->f_id;
        l7 = ((vader_struct_toolchain_ast_Program_t*) l2)->f_module;
        l1 = std_core____Add_add__AssertDecl___ConstDecl___EnumDecl___FnDecl___ImplDecl___ImportDecl___StructDecl___TraitDecl___TypeAliasDecl(((vader_struct_toolchain_ast_Program_t*) l0)->f_decls, l1);
        vader_struct_toolchain_ast_Program_t* _a3_obj = (vader_struct_toolchain_ast_Program_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast_Program_t));
        vader_obj_header_init(_a3_obj, 504u);
        _a3_obj->f_file = l14;
        _a3_obj->f_span = l5.payload.obj;
        _a3_obj->f_id = l3;
        _a3_obj->f_module = l7;
        _a3_obj->f_decls = l1;
        t0 = (void*) _a3_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { void* __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_resolver_zero_span(vader_string_t l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[3] = { &l1, &l2, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_struct_toolchain_span_Position_t* _a0_obj = (vader_struct_toolchain_span_Position_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Position_t));
    vader_obj_header_init(_a0_obj, 533u);
    _a0_obj->f_file = l0;
    _a0_obj->f_offset = (size_t) 0;
    _a0_obj->f_line = INT32_C(1);
    _a0_obj->f_column = INT32_C(1);
    l1 = (void*) _a0_obj;
    vader_struct_toolchain_span_Position_t* _a1_obj = (vader_struct_toolchain_span_Position_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Position_t));
    vader_obj_header_init(_a1_obj, 533u);
    _a1_obj->f_file = l0;
    _a1_obj->f_offset = (size_t) 0;
    _a1_obj->f_line = INT32_C(1);
    _a1_obj->f_column = INT32_C(1);
    l2 = (void*) _a1_obj;
    vader_struct_toolchain_span_Span_t* _a2_obj = (vader_struct_toolchain_span_Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span_Span_t));
    vader_obj_header_init(_a2_obj, 534u);
    _a2_obj->f_start = l1;
    _a2_obj->f_end = l2;
    t0 = (void*) _a2_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}
